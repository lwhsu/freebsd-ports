--- ProcessList.h.orig	2020-12-22 06:39:42 UTC
+++ ProcessList.h
@@ -18,6 +18,7 @@ in the source distribution for its full text.
 #include "Process.h"
 #include "RichString.h"
 #include "Settings.h"
+#include "IncSet.h"
 #include "UsersTable.h"
 #include "Vector.h"
 
@@ -48,7 +49,7 @@ typedef struct ProcessList_ {
    Panel* panel;
    int following;
    uid_t userId;
-   const char* incFilter;
+   IncSet* incSet;
    Hashtable* pidMatchList;
 
    #ifdef HAVE_LIBHWLOC
