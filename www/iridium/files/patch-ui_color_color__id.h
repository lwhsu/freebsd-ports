--- ui/color/color_id.h.orig	2025-06-19 07:37:57 UTC
+++ ui/color/color_id.h
@@ -627,7 +627,7 @@
   E_CPONLY(kColorCrosSysPositive) \
   E_CPONLY(kColorCrosSysComplementVariant) \
   E_CPONLY(kColorCrosSysInputFieldOnBase)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define PLATFORM_SPECIFIC_COLOR_IDS \
   E_CPONLY(kColorNativeBoxFrameBorder)\
   E_CPONLY(kColorNativeHeaderButtonBorderActive) \
