--- IncSet.h.orig	2021-01-11 17:18:21 UTC
+++ IncSet.h
@@ -9,6 +9,7 @@ in the source distribution for its full text.
 
 #include <stdbool.h>
 #include <stddef.h>
+#include <gnu/regex.h>
 
 #include "FunctionBar.h"
 #include "Panel.h"
@@ -34,6 +35,11 @@ typedef struct IncSet_ {
    FunctionBar* defaultBar;
    bool filtering;
    bool found;
+   bool regex;
+   bool exclude;
+   bool regexAlloc;
+   char* rawFilter;
+   regex_t regexFilter;
 } IncSet;
 
 static inline const char* IncSet_filter(const IncSet* this) {
@@ -47,6 +53,8 @@ void IncSet_reset(IncSet* this, IncType type);
 IncSet* IncSet_new(FunctionBar* bar);
 
 void IncSet_delete(IncSet* this);
+
+bool IncSet_filterTest(IncSet* this, const char* str);
 
 bool IncSet_handleKey(IncSet* this, int ch, Panel* panel, IncMode_GetPanelValue getPanelValue, Vector* lines);
 
