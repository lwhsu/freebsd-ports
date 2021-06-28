--- InfoScreen.c.orig	2020-12-22 06:39:42 UTC
+++ InfoScreen.c
@@ -63,8 +63,7 @@ void InfoScreen_drawTitled(InfoScreen* this, const cha
 
 void InfoScreen_addLine(InfoScreen* this, const char* line) {
    Vector_add(this->lines, (Object*) ListItem_new(line, 0));
-   const char* incFilter = IncSet_filter(this->inc);
-   if (!incFilter || String_contains_i(line, incFilter)) {
+   if (IncSet_filterTest(this->inc, line)) {
       Panel_add(this->display, Vector_get(this->lines, Vector_size(this->lines) - 1));
    }
 }
@@ -73,7 +72,7 @@ void InfoScreen_appendLine(InfoScreen* this, const cha
    ListItem* last = (ListItem*)Vector_get(this->lines, Vector_size(this->lines) - 1);
    ListItem_append(last, line);
    const char* incFilter = IncSet_filter(this->inc);
-   if (incFilter && Panel_get(this->display, Panel_size(this->display) - 1) != (Object*)last && String_contains_i(line, incFilter)) {
+   if (incFilter && Panel_get(this->display, Panel_size(this->display) - 1) != (Object*)last && IncSet_filterTest(this->inc, line)) {
       Panel_add(this->display, (Object*)last);
    }
 }
