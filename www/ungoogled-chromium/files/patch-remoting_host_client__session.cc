--- remoting/host/client_session.cc.orig	2025-04-15 08:30:07 UTC
+++ remoting/host/client_session.cc
@@ -187,7 +187,7 @@ void ClientSession::NotifyClientResolution(
   if (effective_policies_.curtain_required.value_or(false)) {
     dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
 #endif
 
