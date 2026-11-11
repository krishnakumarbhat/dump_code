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
 *            Module: NvM
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: NvM_PrivateCbk.h
 *   Generation Time: 2026-08-07 20:10:36
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
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/* PRQA S 5087 MemMap */ /* MD_MSR_MemMap */

/* Do not modify the following parts. */
/* Modification is only allowed in the described parts */

/* ---- private section of configuration ---------------------------------- */
/* ---- used as interface to all submodules of the NvM -------------------- */

/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
#if (!defined NVM_PRIVATE_CKB_H)
# define NVM_PRIVATE_CKB_H

/**********************************************************************************************************************
 *  CONFIGURATION TYPES, VARIABLES, DEFINES...
 *********************************************************************************************************************/
#include "BswM_NvM.h"

/* production error configuration */


#define NvM_DemReportErrorReqFailed()         
#define NvM_DemReportErrorIntegrityFailed()   
#define NvM_DemReportErrorLossOfRedundancy()  
#define NvM_DemReportErrorQueueOverflow()     
#define NvM_DemReportErrorWriteProtected()    


/* include list of the callback definitions */
#include "SWC_Appl_FaultMgr_Cfg.h" 
#include "Dem_Cbk.h" 
#include "SWC_PLT_Appl_NvMHandler.h" 


#if (!defined NVM_CFG_SOURCE)
/* in NvM_Cfg.c we don't need the following definitions and includes */

/* Include-File, which contains Errorhook-Function */
#  include "Det.h"

/* Configurations for Development mode */
/* DET Errorhook
 * macro will only be needed, if reporting is enabled */
#  define NvM_Errorhook(ServiceId, ErrorCode) ((void)Det_ReportError((NVM_MODULE_ID), (0u), (ServiceId), (ErrorCode))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#endif /* NVM_CFG_SOURCE */

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define NvM_invokeCurrentBlockMode(id, res) NVM_DUMMY_STATEMENT(id); NVM_DUMMY_STATEMENT(res) /*  if any block has NotifyBswM == TRUE  */

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define NvM_invokeCurrentJobMode(req, res) BswM_NvM_CurrentJobMode((req),(res)) /*  if NvMBswMMultiBlockJobStatusInformation is TRUE  */

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define NvM_invokeMultiCbk(req, res) NVM_DUMMY_STATEMENT(req); NVM_DUMMY_STATEMENT(res) /*  if Multi Block Callback is configured  */

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define NvM_invokeDetectedLossOfRedundancyCallback(blockId) NVM_DUMMY_STATEMENT((blockId))

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define NvM_invokeProvideDynamicConfigIdCallback(dataPtr, payloadLength) NVM_DUMMY_STATEMENT(dataPtr); NVM_DUMMY_STATEMENT(payloadLength)

/* ---- end private configuration section --------------------------------- */
#endif /* NVM_PRIVATE_CKB_H */

/* PRQA L:MemMap */

/**********************************************************************************************************************
 *  END OF FILE: NvM_PrivateCbk.h
 *********************************************************************************************************************/
    
