--- htop.c.orig	2020-12-22 06:39:42 UTC
+++ htop.c
@@ -254,7 +254,7 @@ static void setCommFilter(State* state, char** commFil
    buffer[maxlen] = 0;
    inc->modes[INC_FILTER].index = strlen(buffer);
    inc->filtering = true;
-   pl->incFilter = IncSet_filter(inc);
+   pl->incSet = ((MainPanel*)state->panel)->inc;
 
    free(*commFilter);
    *commFilter = NULL;
