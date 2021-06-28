--- ProcessList.c.orig	2020-12-22 06:39:42 UTC
+++ ProcessList.c
@@ -6,6 +6,7 @@ in the source distribution for its full text.
 */
 
 #include "ProcessList.h"
+#include "IncSet.h"
 
 #include <assert.h>
 #include <stdlib.h>
@@ -483,8 +484,6 @@ void ProcessList_expandTree(ProcessList* this) {
 }
 
 void ProcessList_rebuildPanel(ProcessList* this) {
-   const char* incFilter = this->incFilter;
-
    int currPos = Panel_getSelectedIndex(this->panel);
    pid_t currPid = this->following != -1 ? this->following : 0;
    int currScrollV = this->panel->scrollV;
@@ -497,7 +496,7 @@ void ProcessList_rebuildPanel(ProcessList* this) {
 
       if ( (!p->show)
          || (this->userId != (uid_t) -1 && (p->st_uid != this->userId))
-         || (incFilter && !(String_contains_i(Process_getCommand(p), incFilter)))
+         || !IncSet_filterTest(this->incSet, p->comm)
          || (this->pidMatchList && !Hashtable_get(this->pidMatchList, p->tgid)) )
          continue;
 
