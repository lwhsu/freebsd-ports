--- Action.c.orig	2021-01-11 17:18:21 UTC
+++ Action.c
@@ -236,9 +236,8 @@ static Htop_Reaction actionToggleTreeView(State* st) {
 }
 
 static Htop_Reaction actionIncFilter(State* st) {
-   IncSet* inc = ((MainPanel*)st->panel)->inc;
-   IncSet_activate(inc, INC_FILTER, st->panel);
-   st->pl->incFilter = IncSet_filter(inc);
+   st->pl->incSet = ((MainPanel*)st->panel)->inc;
+   IncSet_activate(st->pl->incSet, INC_FILTER, st->panel);
    return HTOP_REFRESH | HTOP_KEEP_FOLLOWING;
 }
 
