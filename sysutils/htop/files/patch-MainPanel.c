--- MainPanel.c.orig	2020-12-22 06:39:42 UTC
+++ MainPanel.c
@@ -74,7 +74,7 @@ static HandlerResult MainPanel_eventHandler(Panel* sup
    } else if (ch != ERR && this->inc->active) {
       bool filterChanged = IncSet_handleKey(this->inc, ch, super, (IncMode_GetPanelValue) MainPanel_getValue, NULL);
       if (filterChanged) {
-         this->state->pl->incFilter = IncSet_filter(this->inc);
+         this->state->pl->incSet = this->inc;
          reaction = HTOP_REFRESH | HTOP_REDRAW_BAR;
       }
       if (this->inc->found) {
