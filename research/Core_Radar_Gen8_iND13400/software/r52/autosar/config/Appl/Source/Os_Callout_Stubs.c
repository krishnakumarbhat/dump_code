/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program:
 *          Customer:
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Callout_Stubs.c
 *   Generation Time: 2026-09-29 14:27:49
 *           Project: Gen8_iND13400 - Version 1.0
 *          Delivery: PAI19494
 *      Tool Version: DaVinci Configurator Classic (beta) 5.31.55 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include
 *errors.
 *
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed!
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
#define OS_CALLOUT_STUBS_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Os.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_Include>
 *********************************************************************************************************************/
#include "EcuM.h"
#include "Exception_handler.h"
#include "SWC_PLT_CDD_FailSafe.h"
extern Dt_Memory_Exception_Info_T Exception_Context;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StartupHook()
 *********************************************************************************************************************/
#if OS_CFG_STARTUPHOOK_SYSTEM == STD_ON
   #define OS_START_SEC_CODE_STARTUPHOOK_ASIL_D
   #include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_STARTUPHOOK_CODE) StartupHook(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_StartupHook>
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
    *********************************************************************************************************************/
}

   #define OS_STOP_SEC_CODE_STARTUPHOOK_ASIL_D
   #include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif                                      /* OS_CFG_STARTUPHOOK_SYSTEM */

/**********************************************************************************************************************
 *  ShutdownHook()
 *********************************************************************************************************************/
#if OS_CFG_SHUTDOWNHOOK_SYSTEM == STD_ON
   #define OS_START_SEC_CODE_SHUTDOWNHOOK_ASIL_D
   #include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_SHUTDOWNHOOK_CODE) ShutdownHook(StatusType Fatalerror)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ShutdownHook>
    *********************************************************************************************************************/
   FailSafe_Log_ResetReason((uint16)Fatalerror);
   EcuM_Shutdown();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
    *********************************************************************************************************************/
}

   #define OS_STOP_SEC_CODE_SHUTDOWNHOOK_ASIL_D
   #include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif                                      /* OS_CFG_SHUTDOWNHOOK_SYSTEM */

/**********************************************************************************************************************
 *  ErrorHook()
 *********************************************************************************************************************/
#if OS_CFG_ERRORHOOK_SYSTEM == STD_ON
   #define OS_START_SEC_CODE_ERRORHOOK_ASIL_D
   #include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_ERRORHOOK_CODE) ErrorHook(StatusType Error)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ErrorHook>
    *********************************************************************************************************************/
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
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
    *********************************************************************************************************************/
}

   #define OS_STOP_SEC_CODE_ERRORHOOK_ASIL_D
   #include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif                                      /* OS_CFG_ERRORHOOK_SYSTEM */

/**********************************************************************************************************************
 *  ProtectionHook()
 *********************************************************************************************************************/
#if OS_CFG_PROTECTIONHOOK_SYSTEM == STD_ON
   #define OS_START_SEC_CODE_PROTECTIONHOOK_ASIL_D
   #include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(ProtectionReturnType, OS_PROTECTIONHOOK_CODE) ProtectionHook(StatusType Fatalerror)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ProtectionHook>
    *********************************************************************************************************************/
   if ((Fatalerror == E_OS_PROTECTION_MEMORY) || (Fatalerror == E_OS_PROTECTION_EXCEPTION))
   {
      GetExceptionInfo((uint8)Fatalerror);
      Log_ExceptionReason_Info(&Exception_Context, Fatalerror);
      (void)FailSafe_Log_ResetReason(Fatalerror);
   }
   return PRO_SHUTDOWN;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
    *********************************************************************************************************************/
}

   #define OS_STOP_SEC_CODE_PROTECTIONHOOK_ASIL_D
   #include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif                                      /* OS_CFG_PROTECTIONHOOK_SYSTEM */

/**********************************************************************************************************************
 *  PreTaskHook()
 *********************************************************************************************************************/
#if OS_CFG_PRETASKHOOK == STD_ON
   #define OS_START_SEC_CODE_PRETASKHOOK_ASIL_D
   #include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_PRETASKHOOK_CODE) PreTaskHook(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PreTaskHook>
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
    *********************************************************************************************************************/
}

   #define OS_STOP_SEC_CODE_PRETASKHOOK_ASIL_D
   #include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif                                      /* OS_CFG_PRETASKHOOK */

/**********************************************************************************************************************
 *  PostTaskHook()
 *********************************************************************************************************************/
#if OS_CFG_POSTTASKHOOK == STD_ON
   #define OS_START_SEC_CODE_POSTTASKHOOK_ASIL_D
   #include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_POSTTASKHOOK_CODE) PostTaskHook(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PostTaskHook>
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
    *********************************************************************************************************************/
}

   #define OS_STOP_SEC_CODE_POSTTASKHOOK_ASIL_D
   #include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif                                      /* OS_CFG_POSTTASKHOOK */

/**********************************************************************************************************************
 *  Os_PanicHook()
 *********************************************************************************************************************/
#if OS_CFG_PANICHOOK == STD_ON
   #define OS_START_SEC_CODE_PANICHOOK_ASIL_D
   #include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_PANICHOOK_CODE) Os_PanicHook(Os_PanicStatusType Status)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PanicHook>
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
    *********************************************************************************************************************/
}

   #define OS_STOP_SEC_CODE_PANICHOOK_ASIL_D
   #include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif                                      /* OS_CFG_PANICHOOK */

/* Unrecognized User Blocks */

/**********************************************************************************************************************
 *  END OF FILE: Os_Callout_Stubs.c
 *********************************************************************************************************************/
