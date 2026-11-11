/**
 * @file Os_Callout_fakes.h
 * @brief Fake function declarations for Os_Callout_Stubs testing
 */

#ifndef OS_CALLOUT_FAKES_H
#define OS_CALLOUT_FAKES_H

#include "fff.h"
#include <stdint.h>

// AUTOSAR types
typedef uint32_t StatusType;
typedef uint32_t ProtectionReturnType;

#define PRO_SHUTDOWN              2U
#define E_OS_PROTECTION_MEMORY    1U
#define E_OS_PROTECTION_EXCEPTION 2U
#define E_OS_SYS_OVERLOAD         3U

typedef enum
{
   OS_PANIC_UNKNOWN = 0
} Os_PanicStatusType;

typedef struct
{
   uint32_t DetailedError;
} Os_ErrorInformationType;

// External function declarations
DECLARE_FAKE_VOID_FUNC(Printf_Information, const char *);
DECLARE_FAKE_VOID_FUNC(FailSafe_Log_ResetReason, uint16_t);
DECLARE_FAKE_VOID_FUNC(EcuM_Shutdown);
DECLARE_FAKE_VALUE_FUNC(StatusType, Os_GetDetailedError, Os_ErrorInformationType *);

#endif // OS_CALLOUT_FAKES_H
