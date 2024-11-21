commit f4726b93e3cee3e81d241a5163541849d4f6851f
Author: Christoph Moench-Tegeder <cmt@burggraben.net>
Date:   Thu Jan 25 22:29:37 2024 +0100

    include sys/wait.h for pclose() return values

--- main/config.c.orig	2024-10-17 16:00:41 UTC
+++ main/config.c
@@ -44,6 +44,7 @@
 #include <libgen.h>
 #include <time.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 
 #include <math.h>	/* HUGE_VAL */
 #include <regex.h>
