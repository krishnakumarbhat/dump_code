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
 *            Module: Rtm
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Rtm_Cbk.h
 *   Generation Time: 2026-07-28 13:38:13
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
#if !defined(RTM_CBK_H)
#define RTM_CBK_H

#include "Platform_Types.h"
#include "Rtm_Types.h"

typedef uint32 Rtm_TimestampType;

typedef struct
{
  uint32        prevActive;        /* Previously active measurement */
  uint32        nextActive;        /* Next active measurement*/
  uint32        intermediateTime;  /* Time of interruption */
  uint32        threadContext;     /* The context in which the MP is running. */
} Rtm_MeasurementPointInfoType;

typedef struct
{
  const boolean interruptsDisabled; /* Defines if interrupts are disabled during MP execution. */
  const uint8   measurementType;
  const uint8   mpType;
  const uint16  coreId;             /* Assigned Core ID */
} Rtm_MeasurementPointConfigType;


typedef struct
{
  uint32        prevActiveNetMP;   /* Previously active measurement- Net*/
  uint32        preemptionTime;    /* Time of interruption */
} Rtm_ThreadContextInfoType;


#define RTM_START_SEC_CODE
#include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

Rtm_TimestampType Rtm_GetTimeMeasurement(void); 





#define RTM_STOP_SEC_CODE
#include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* RTM_CBK_H */


