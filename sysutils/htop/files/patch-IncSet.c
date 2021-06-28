--- IncSet.c.orig	2021-01-11 17:18:21 UTC
+++ IncSet.c
@@ -12,6 +12,7 @@ in the source distribution for its full text.
 #include <ctype.h>
 #include <string.h>
 #include <stdlib.h>
+#include <gnu/regex.h>
 
 #include "CRT.h"
 #include "ListItem.h"
@@ -39,9 +40,11 @@ static inline void IncMode_initSearch(IncMode* search)
    search->isFilter = false;
 }
 
-static const char* const filterFunctions[] = {"Done  ", "Clear ", " Filter: ", NULL};
-static const char* const filterKeys[] = {"Enter", "Esc", "  "};
-static const int filterEvents[] = {13, 27, ERR};
+static const char* const filterFunctions[] = {"Done  ", "Clear ", "!Regexp ", "Filter Out ", " Filter: ", NULL};
+static const char* const filterKeys[] = {"Enter", "Esc",  "F5", "F6", "  "};
+static const char* regexLabels[] = {"Regexp  ", "!Regexp "};
+static const char* excludeLabels[] = {"Filter Out ", "Filter In  "};
+static const int filterEvents[] = {13, 27,  KEY_F(5), KEY_F(6), ERR};
 
 static inline void IncMode_initFilter(IncMode* filter) {
    memset(filter, 0, sizeof(IncMode));
@@ -61,24 +64,79 @@ IncSet* IncSet_new(FunctionBar* bar) {
    this->defaultBar = bar;
    this->filtering = false;
    this->found = false;
+   this->rawFilter = NULL;
+   this->regex = true;
+   this->exclude = false;
+   this->regexAlloc = false;
    return this;
 }
 
+static void freeFilter(IncSet* this);
+
 void IncSet_delete(IncSet* this) {
    IncMode_done(&(this->modes[0]));
    IncMode_done(&(this->modes[1]));
+   freeFilter(this);
    free(this);
 }
 
+
+static void updateBarLabels(IncSet* this) {
+   if (this->active == &(this->modes[INC_FILTER])) {
+      IncMode* filterMode = &(this->modes[INC_FILTER]);
+      FunctionBar_setLabel(filterMode->bar, KEY_F(5), regexLabels[this->regex ? 1 : 0]);
+      FunctionBar_setLabel(filterMode->bar, KEY_F(6), excludeLabels[this->exclude ? 1 : 0]);
+   }
+}
+
+static bool testWithFilter(IncSet* this, const char* testSubject) {
+   if (!this || !this->filtering) {
+      return true;
+   }
+   if (this->regexAlloc) {
+      return regexec(&this->regexFilter, testSubject, 0, NULL, 0) ? this->exclude : !this->exclude;
+   }
+   return  String_contains_i(testSubject, this->rawFilter ? this->rawFilter : "" ) ? !this->exclude : this->exclude;
+}
+
+bool IncSet_filterTest(IncSet* this, const char* str) {
+      return !this || !this->filtering || testWithFilter(this, str);
+}
+
+static void freeFilter(IncSet* this) {
+   if (this->regexAlloc) {
+      regfree(&this->regexFilter);
+      this->regexAlloc = false;
+   }
+   if (this->rawFilter) {
+      free(this->rawFilter);
+      this->rawFilter = NULL;
+   }
+}
+
+static void compileFilter(IncSet* this, const char* filterStr) {
+   if (this->rawFilter) {
+      freeFilter(this);
+   }
+   if (filterStr) {
+      this->rawFilter = xStrdup(filterStr);
+      if (this->regex) {
+         int result = regcomp(&this->regexFilter, this->rawFilter, REG_EXTENDED|REG_NOSUB|REG_ICASE);
+         if (!result) {
+            this->regexAlloc = true;
+         }
+      }
+   }
+}
+
 static void updateWeakPanel(IncSet* this, Panel* panel, Vector* lines) {
    Object* selected = Panel_getSelected(panel);
    Panel_prune(panel);
    if (this->filtering) {
       int n = 0;
-      const char* incFilter = this->modes[INC_FILTER].buffer;
       for (int i = 0; i < Vector_size(lines); i++) {
          ListItem* line = (ListItem*)Vector_get(lines, i);
-         if (String_contains_i(line->value, incFilter)) {
+         if (testWithFilter(this, line->value)) {
             Panel_add(panel, (Object*)line);
             if (selected == (Object*)line) {
                Panel_setSelected(panel, n);
@@ -98,10 +156,10 @@ static void updateWeakPanel(IncSet* this, Panel* panel
    }
 }
 
-static bool search(IncMode* mode, Panel* panel, IncMode_GetPanelValue getPanelValue) {
+static bool search(IncSet* this, Panel* panel, IncMode_GetPanelValue getPanelValue) {
    int size = Panel_size(panel);
    for (int i = 0; i < size; i++) {
-      if (String_contains_i(getPanelValue(panel, i), mode->buffer)) {
+      if (testWithFilter(this, getPanelValue(panel, i))) {
          Panel_setSelected(panel, i);
          return true;
       }
@@ -147,6 +205,18 @@ bool IncSet_handleKey(IncSet* this, int ch, Panel* pan
 
       IncMode_find(mode, panel, getPanelValue, ch == KEY_F(3) ? 1 : -1);
       doSearch = false;
+   } else if (ch == KEY_F(5)) {
+      if (mode->isFilter) {
+         filterChanged = true;
+         this->regex = !this->regex;
+         updateBarLabels(this);
+      }
+   } else if (ch == KEY_F(6)) {
+      if (mode->isFilter) {
+         filterChanged = true;
+         this->exclude = !this->exclude;
+         updateBarLabels(this);
+      }
    } else if (0 < ch && ch < 255 && isprint((unsigned char)ch)) {
       if (mode->index < INCMODE_MAX) {
          mode->buffer[mode->index] = ch;
@@ -167,6 +237,7 @@ bool IncSet_handleKey(IncSet* this, int ch, Panel* pan
             filterChanged = true;
             if (mode->index == 0) {
                this->filtering = false;
+               freeFilter(this);
                IncMode_reset(mode);
             }
          }
@@ -180,6 +251,7 @@ bool IncSet_handleKey(IncSet* this, int ch, Panel* pan
          filterChanged = true;
          if (ch == 27) {
             this->filtering = false;
+            freeFilter(this);
             IncMode_reset(mode);
          }
       } else {
@@ -191,8 +263,11 @@ bool IncSet_handleKey(IncSet* this, int ch, Panel* pan
       Panel_setDefaultBar(panel);
       doSearch = false;
    }
+   if (filterChanged) {
+      compileFilter(this, mode->buffer);
+   }
    if (doSearch) {
-      this->found = search(mode, panel, getPanelValue);
+      this->found = search(this, panel, getPanelValue);
    }
    if (filterChanged && lines) {
       updateWeakPanel(this, panel, lines);
@@ -207,6 +282,7 @@ const char* IncSet_getListItemValue(Panel* panel, int 
 
 void IncSet_activate(IncSet* this, IncType type, Panel* panel) {
    this->active = &(this->modes[type]);
+   updateBarLabels(this);
    panel->currentBar = this->active->bar;
 }
 
