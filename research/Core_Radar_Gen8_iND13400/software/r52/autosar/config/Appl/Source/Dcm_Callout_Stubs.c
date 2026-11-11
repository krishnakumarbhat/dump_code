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
 *            Module: BswM
 *           Program:
 *          Customer:
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dcm_Callout_Stubs.c
 *   Generation Time: 2026-06-02 14:19:11
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
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Version>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#define DCM_CALLOUT_STUBS_SOURCE
#include "Dcm.h"
#include "Dem.h"

/**********************************************************************************************************************
 *  Additional configured User includes
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Includes>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
//#include "boot_interface.h"
#define BOOT_FLAG_SET   0xAA
#define PROG_REQ_FLAG   0xB5
#define RESET_RESP_FLAG 0x1

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GENERIC CALLOUTS
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SetProgConditions(Dcm_ProgConditionsPtrType progConditions)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Dcm_SetProgConditions>                  DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
#if 0
   Boot_Shared_Data.jump_to_boot_flag                          = BOOT_FLAG_SET;
   Boot_Shared_Data.VectorBoot_Shared_Data.prog_req_flag       = PROG_REQ_FLAG;
   Boot_Shared_Data.VectorBoot_Shared_Data.reset_response_flag = RESET_RESP_FLAG;
#endif
   return 0u;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of Dcm_SetProgConditions */

FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_GetProgConditions(Dcm_ProgConditionsPtrType progConditions)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Dcm_GetProgConditions>      DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   return 0u;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of Dcm_GetProgConditions */

FUNC(Std_ReturnType, DCM_CALLOUT_CODE)
Dcm_ProcessRequestTransferExit(Dcm_OpStatusType OpStatus, P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) transferRequestParameterRecord,
                               uint32 transferRequestParameterRecordSize,
                               P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) transferResponseParameterRecord,
                               P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) transferResponseParameterRecordSize,
                               Dcm_NegativeResponseCodePtrType ErrorCode)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Dcm_ProcessRequestTransferExit>      DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   return 0u;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of Dcm_ProcessRequestTransferExit */

FUNC(Std_ReturnType, DCM_CALLOUT_CODE)
Dcm_ProcessRequestDownload(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint8 MemoryIdentifier, uint32 MemoryAddress,
                           uint32 MemorySize, P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) BlockLength,
                           Dcm_NegativeResponseCodePtrType ErrorCode)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Dcm_ProcessRequestDownload>      DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   return 0u;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of Dcm_ProcessRequestDownload */

FUNC(void, DCM_CALLOUT_CODE) Dcm_Confirmation(Dcm_IdContextType idContext, PduIdType dcmRxPduId, Dcm_ConfirmationStatusType status)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Dcm_Confirmation>      DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of Dcm_Confirmation */

FUNC(Dcm_ReturnWriteMemoryType, DCM_CALLOUT_CODE)
Dcm_ProcessTransferDataWrite(Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier, uint32 MemoryAddress, uint32 MemorySize,
                             P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) MemoryData, Dcm_NegativeResponseCodePtrType ErrorCode)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Dcm_ProcessTransferDataWrite>      DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   return 0u;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of Dcm_ProcessTransferDataWrite */

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: DCM_CALLOUT_STUBS.C
 *********************************************************************************************************************/
