/**
 * @file Os_Callout_Stubs_wrapper.c
 * @brief Wrapper to compile Os_Callout_Stubs.c with fakes for unit testing
 */

#include "Os_Callout_fakes.h"

#line 1 "software/r52/autosar/config/Appl/Source/Os_Callout_Stubs.c"
void StartupHook(void)
{
   // Empty implementation
}

void ShutdownHook(StatusType Fatalerror)
{
   FailSafe_Log_ResetReason((uint16_t)Fatalerror);
   EcuM_Shutdown();
}

void ErrorHook(StatusType Error)
{
   Os_ErrorInformationType CurrentError;
   (void)Os_GetDetailedError(&CurrentError);
   if ((CurrentError.DetailedError == E_OS_PROTECTION_MEMORY) || (CurrentError.DetailedError == E_OS_PROTECTION_EXCEPTION))
   {
      FailSafe_Log_ResetReason(CurrentError.DetailedError);
   }
   else if (CurrentError.DetailedError == E_OS_SYS_OVERLOAD)
   {
      /* do nothing */
   }
   else
   {
      FailSafe_Log_ResetReason(CurrentError.DetailedError);
   }
}

ProtectionReturnType ProtectionHook(StatusType Fatalerror)
{
   return PRO_SHUTDOWN;
}

void PreTaskHook(void)
{
   // Empty implementation
}

void PostTaskHook(void)
{
   // Empty implementation
}

void Os_PanicHook(Os_PanicStatusType Status)
{
   // Empty implementation
}
