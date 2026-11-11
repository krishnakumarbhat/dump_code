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
 *              File: Xcp_Lcfg.c
 *   Generation Time: 2026-05-11 17:41:29
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
    
#define XCP_LCFG_SOURCE
    
#include "Xcp.h"

/*lint -e451 */ /* Suppress ID451 because Xcp_MemMap.h cannot use a include guard */

#if ( XCP_DAQ == STD_ON )
# define XCP_START_SEC_VAR_NOCACHE_NO_INIT_32
# include "Xcp_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

XCP_LOCAL VAR(uint8, XCP_VAR_NO_INIT_NOCACHE) Xcp_SendQueue_Core0[XCP_NUMBER_OF_CHANNELS][20480u];

# define XCP_STOP_SEC_VAR_NOCACHE_NO_INIT_32
# include "Xcp_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */
#endif

#define XCP_START_SEC_CONST_UNSPECIFIED
#include "Xcp_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#if( XCP_DAQ == STD_ON )
CONSTP2VAR(uint8, XCP_CONST, XCP_VAR_NO_INIT) Xcp_SendQueueRef[XCP_NUMBER_OF_CORES] =
{
  &Xcp_SendQueue_Core0[0][0]
};

CONST(uint32, XCP_CONST) Xcp_SendQueueSize[XCP_NUMBER_OF_CORES] =
{
  sizeof(Xcp_SendQueue_Core0[0])
};

CONST(Xcp_ECcIDType, XCP_CONST) Xcp_ECcIdMapping[XCP_MAX_EVENT] = /* PRQA S 1533 */ /* MD_XCP_1533 */
{
  {
    0u, 
    0u
  }, 
  {
    0u, 
    0u
  }, 
  {
    0u, 
    0u
  }, 
  {
    0u, 
    0u
  }
};
#endif

CONST(Xcp_TlApiType, XCP_CONST) Xcp_TlApi[2] = 
{
  {
    CanXcp_Send /*  ApplXcpSend  */ , 
    CanXcp_SendFlush /*  ApplXcpSendFlush  */ , 
    CanXcp_TLService /*  ApplXcpTLService  */ 
  }, 
  {
    TcpIpXcp_Send /*  ApplXcpSend  */ , 
    TcpIpXcp_SendFlush /*  ApplXcpSendFlush  */ , 
    TcpIpXcp_TLService /*  ApplXcpTLService  */ 
  }
};

/* Events */
CONST(uint8, XCP_CONST) kXcpEventName_0[8] = "Rtm_Evt";
CONST(uint8, XCP_CONST) kXcpEventName_1[25] = "Xcp_Daq_Event_0_Post_RDD";
CONST(uint8, XCP_CONST) kXcpEventName_2[20] = "Xcp_Daq_Event_1_ADC";
CONST(uint8, XCP_CONST) kXcpEventName_3[21] = "Xcp_Daq_Event_2_MMIC";

CONSTP2CONST(uint8, XCP_CONST, XCP_CONST) kXcpEventName[4] = /* PRQA S 1533 */ /* MD_XCP_1533 */
{
  &kXcpEventName_0[0], 
  &kXcpEventName_1[0], 
  &kXcpEventName_2[0], 
  &kXcpEventName_3[0]
};
CONST(uint8, XCP_CONST) kXcpEventNameLength[4] = /* PRQA S 1533 */ /* MD_XCP_1533 */ 
{
  7u, 
  24u, 
  19u, 
  20u
};
CONST(uint8, XCP_CONST) kXcpEventCycle[4] = /* PRQA S 1533 */ /* MD_XCP_1533 */ 
{
  0u, 
  0u, 
  0u, 
  0u
};
CONST(uint8, XCP_CONST) kXcpEventUnit[4] = /* PRQA S 1533 */ /* MD_XCP_1533 */
{
  XCP_DAQ_TIMESTAMP_UNIT_1MS, 
  XCP_DAQ_TIMESTAMP_UNIT_1US, 
  XCP_DAQ_TIMESTAMP_UNIT_1US, 
  XCP_DAQ_TIMESTAMP_UNIT_1US
}; 
CONST(uint8, XCP_CONST) kXcpEventDirection[4] = /* PRQA S 1533 */ /* MD_XCP_1533 */
{
  XCP_DAQ_EVENT_DIRECTION_DAQ, 
  XCP_DAQ_EVENT_DIRECTION_DAQ, 
  XCP_DAQ_EVENT_DIRECTION_DAQ, 
  XCP_DAQ_EVENT_DIRECTION_DAQ
}; 
CONST(uint8, XCP_CONST) kXcpEventNumDaq[4] = /* PRQA S 1533 */ /* MD_XCP_1533 */
{
  0x01u, 
  0x01u, 
  0x01u, 
  0x01u
}; 
 
/* Flash programming */
CONST(uint8, XCP_CONST) kXcpSectorName_0[20] = "XcpSector_SMC_FLASH";
CONST(uint8, XCP_CONST) kXcpSectorName_1[20] = "XcpSector_USC_FLASH";
CONSTP2CONST(uint8, XCP_CONST, XCP_CONST) kXcpSectorName[2] = /* PRQA S 1533 */ /* MD_XCP_1533 */
{
  &kXcpSectorName_0[0], 
  &kXcpSectorName_1[0]
};
CONST(uint8, XCP_CONST) kXcpSectorNameLength[2] = /* PRQA S 1533 */ /* MD_XCP_1533 */ 
{
  19u, 
  19u
};
CONST(uint32, XCP_CONST) kXcpProgramSectorStart[2] = /* PRQA S 1533 */ /* MD_XCP_1533 */ 
{
  0x00080000u, 
  0x00070000u
};
CONST(uint32, XCP_CONST) kXcpProgramSectorEnd[2] = /* PRQA S 1533 */ /* MD_XCP_1533 */ 
{
  0x000BFFFFu, 
  0x0007FFFFu
};

#define XCP_STOP_SEC_CONST_UNSPECIFIED
#include "Xcp_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

