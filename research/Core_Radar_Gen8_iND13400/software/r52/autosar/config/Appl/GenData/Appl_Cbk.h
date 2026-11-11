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
 *            Module: Com
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Appl_Cbk.h
 *   Generation Time: 2026-08-11 17:20:12
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

#if !defined (APPL_CBK_H)
# define APPL_CBK_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Com_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COM_START_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "Com_MemMap.h"


/* Configurable notification interface prototypes */
FUNC(void, COM_APPL_CODE) ComNotification_SG_ETC2_00_oETC2_00_oVCAN_RADAR_efbda90a_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_VD_oGW_VD_oPCAN_RADAR_ad0f59e4_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_OEL_oGW_OEL_oPCAN_RADAR_dcaa9b38_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_ETC2_03_oETC2_03_oVCAN_RADAR_6b0f6884_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_SAS_oGW_SAS_oPCAN_RADAR_0d213b5c_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_CLS_Tx_4_oCLS_Tx_4_oVCAN_RADAR_72dadf8e_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_VD_oVD_oVCAN_RADAR_27d322c3_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_CCVS1_oCCVS1_oVCAN_RADAR_1b2d3da2_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_SAS_oSAS_oVCAN_RADAR_c902864e_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_CCVS1_oCCVS1_oVCAN_RADAR_1b2d3da2_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_TD_oGW_TD_oPCAN_RADAR_a8a59c34_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_CCVS1_oGW_CCVS1_oPCAN_RADAR_70857376_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_CLS_Tx_16_oGW_CLS_Tx_16_oPCAN_RADAR_ecf85999_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_TD_oTD_oVCAN_RADAR_c3698ded_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_CLS_Tx_16_oCLS_Tx_16_oVCAN_RADAR_ce7ac5cf_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_ETC2_03_oGW_ETC2_03_oPCAN_RADAR_04d9a8d8_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_ADAS_FN_Enable_disable_sts_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_46faeb96_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_OEL_oGW_OEL_oPCAN_RADAR_dcaa9b38_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_CLS_Tx_16_oGW_CLS_Tx_16_oPCAN_RADAR_ecf85999_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_VDC2_oVDC2_oVCAN_RADAR_06eddadd_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_ETC2_oGW_ETC2_oPCAN_RADAR_d84ef27a_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_OEL_oOEL_oVCAN_RADAR_400a2f4d_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_CLS_Tx_16_oCLS_Tx_16_oVCAN_RADAR_ce7ac5cf_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_VDC2_oGW_VDC2_oPCAN_RADAR_41520959_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_SAS_oGW_SAS_oPCAN_RADAR_0d213b5c_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_VD_oVD_oVCAN_RADAR_27d322c3_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_ETC2_03_oGW_ETC2_03_oPCAN_RADAR_04d9a8d8_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_ETC2_00_oETC2_00_oVCAN_RADAR_efbda90a_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_TD_oTD_oVCAN_RADAR_c3698ded_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_VDC2_oVDC2_oVCAN_RADAR_06eddadd_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_TD_oGW_TD_oPCAN_RADAR_a8a59c34_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_VDC2_oGW_VDC2_oPCAN_RADAR_41520959_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_ETC2_oGW_ETC2_oPCAN_RADAR_d84ef27a_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_CLS_Tx_4_oGW_CLS_Tx_4_oPCAN_RADAR_474ec459_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_ETC2_03_oETC2_03_oVCAN_RADAR_6b0f6884_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_OEL_oOEL_oVCAN_RADAR_400a2f4d_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_CLS_Tx_4_oCLS_Tx_4_oVCAN_RADAR_72dadf8e_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_ADAS_FN_Enable_disable_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_9a8054b4_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_SAS_oSAS_oVCAN_RADAR_c902864e_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_ADAS_FN_Enable_disable_sts_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_46faeb96_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_CCVS1_oGW_CCVS1_oPCAN_RADAR_70857376_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_ADAS_FN_Enable_disable_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_9a8054b4_Rx(void);
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_CLS_Tx_4_oGW_CLS_Tx_4_oPCAN_RADAR_474ec459_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_VD_oGW_VD_oPCAN_RADAR_ad0f59e4_Rx(void);



#define COM_STOP_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "Com_MemMap.h"

#endif  /* APPL_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Appl_Cbk.h
**********************************************************************************************************************/

