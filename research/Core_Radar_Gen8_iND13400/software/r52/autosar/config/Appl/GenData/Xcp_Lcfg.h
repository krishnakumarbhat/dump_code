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
 *            Module: Xcp
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Xcp_Lcfg.h
 *   Generation Time: 2026-05-11 17:41:30
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
    
#if !defined(XCP_LCFG_H)
#define XCP_LCFG_H

#include "Xcp_Types.h"

#define XCP_START_SEC_CONST_UNSPECIFIED
#include "Xcp_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#if( XCP_DAQ == STD_ON )
extern CONSTP2VAR(uint8, XCP_VAR_NO_INIT, AUTOMATIC) Xcp_SendQueueRef[XCP_NUMBER_OF_CORES];
extern CONST(uint32, XCP_CONST) Xcp_SendQueueSize[XCP_NUMBER_OF_CORES];
extern CONST(Xcp_ECcIDType, XCP_CONST) Xcp_ECcIdMapping[XCP_MAX_EVENT];
#endif

extern CONST(Xcp_TlApiType, XCP_CONST) Xcp_TlApi[2];

/* Events */
extern CONST(uint8, XCP_CONST) kXcpEventName_0[8];
extern CONST(uint8, XCP_CONST) kXcpEventName_1[25];
extern CONST(uint8, XCP_CONST) kXcpEventName_2[20];
extern CONST(uint8, XCP_CONST) kXcpEventName_3[21];

extern CONSTP2CONST(uint8, XCP_CONST, XCP_CONST) kXcpEventName[4];
extern CONST(uint8, XCP_CONST) kXcpEventNameLength[4];
extern CONST(uint8, XCP_CONST) kXcpEventCycle[4];
extern CONST(uint8, XCP_CONST) kXcpEventUnit[4];
extern CONST(uint8, XCP_CONST) kXcpEventDirection[4];
extern CONST(uint8, XCP_CONST) kXcpEventNumDaq[4];


/* Event Channel SNV IDs */



/**
 * \defgroup XcpHandleIdsEventChannelHandleIDs Handle IDs of handle space EventChannel Handle IDs.
 * \brief Symbolic Name Values (SNVs) for EventChannel Handles
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define XcpConf_XcpEventChannel_Rtm_Evt                               0       /**< [PostBuildInvariantValuesModelView] */
#define XcpConf_XcpEventChannel_Xcp_Daq_Event_0_Post_RDD              1       /**< [PostBuildInvariantValuesModelView] */
#define XcpConf_XcpEventChannel_Xcp_Daq_Event_1_ADC                   2       /**< [PostBuildInvariantValuesModelView] */
#define XcpConf_XcpEventChannel_Xcp_Daq_Event_2_MMIC                  3       /**< [PostBuildInvariantValuesModelView] */
/**\} */


/* Flash programming */
extern CONST(uint8, XCP_CONST) kXcpSectorName_0[20];
extern CONST(uint8, XCP_CONST) kXcpSectorName_1[20];
extern CONSTP2CONST(uint8, XCP_CONST, XCP_CONST) kXcpSectorName[2];
extern CONST(uint8, XCP_CONST) kXcpSectorNameLength[2];
extern CONST(uint32, XCP_CONST) kXcpProgramSectorStart[2];
extern CONST(uint32, XCP_CONST) kXcpProgramSectorEnd[2];

#define XCP_STOP_SEC_CONST_UNSPECIFIED
#include "Xcp_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */


#endif /* XCP_LCFG_H */   

