--- src/3rdparty/chromium/components/password_manager/core/browser/password_store/login_database.cc.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/components/password_manager/core/browser/password_store/login_database.cc
@@ -1030,7 +1030,7 @@ bool ShouldDeleteUndecryptablePasswords(
     bool is_user_data_dir_policy_set,
     bool is_enabled_by_policy,
     IsAccountStore is_account_store) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string user_data_dir_string;
   std::unique_ptr<base::Environment> environment(base::Environment::Create());
   // On Linux user data directory ca be specified using an env variable. If it
@@ -1049,7 +1049,7 @@ bool ShouldDeleteUndecryptablePasswords(
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_line->HasSwitch(password_manager::kPasswordStore)) {
     RecordShouldDeleteUndecryptablePasswordsMetric(
         ShouldDeleteUndecryptablePasswordsResult::
