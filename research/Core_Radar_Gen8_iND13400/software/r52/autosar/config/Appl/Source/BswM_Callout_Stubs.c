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
 *              File: BswM_Callout_Stubs.c
 *   Generation Time: 2026-09-21 13:31:55
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
 * WARNING: This code has been generated with reduced-severity errors.
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of
 *the embedded code. Usage of the created files happens at own risk!
 *
 * [Warning] BSWM01016 - Feature must be enabled!
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 *
 * [Warning] BSWM01016 - Feature must be enabled!
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 *
 * [Warning] BSWM01016 - Feature must be enabled!
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 *
 * [Warning] BSWM01016 - Feature must be enabled!
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 *
 * [Warning] BSWM01016 - Feature must be enabled!
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 *
 * [Warning] BSWM01016 - Feature must be enabled!
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 *
 * [Warning] BSWM01016 - Feature must be enabled!
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 *
 * [Warning] BSWM01016 - Feature must be enabled!
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include
 *errors.
 *
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed!
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           <USERBLOCK User Version>                           DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#define BSWM_CALLOUT_STUBS_SOURCE
#include "BswM.h"
#include "BswM_Private_Cfg.h"

/**********************************************************************************************************************
 *  Additional configured User includes
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           <USERBLOCK User Includes>                          DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

#include "Eth.h"
#include "EthTrcv_30_Rtl9010.h"
#include "EthTrcv_30_Tja1103.h"
#include "PHY_User_Cbk.h" /* PHY detection types/functions used in BswM_Action_INIT_Action_EthIf_Init_RDR_01 */
#include "SWC_CMP_PRJ_UDSHandler.h"
#include "SchM_Fls.h"
#include "board_revision.h"
#include "sensor_position.h"
#define APTIV_OFFICIAL_RELEASE TRUE
volatile uint8 CustShutdownTaskCompleted = CODED_FALSE;
extern uint8 NVM_Config_Ram_Block;
volatile bool Configured_PHY_1Gb = true;
/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
#define BSWM_START_SEC_CALLOUT_CODE_ASIL_D
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GENERIC CALLOUTS
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_AL_SetProgrammableInterrupts(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_AL_SetProgrammableInterrupts>      DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of BswM_AL_SetProgrammableInterrupts */

FUNC(void, BSWM_CODE) BswM_ESH_OnEnterPostRun(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterPostRun>                DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterPostRun */

FUNC(void, BSWM_CODE) BswM_ESH_OnEnterPrepShutdown(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterPrepShutdown>           DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterPrepShutdown */

FUNC(void, BSWM_CODE) BswM_ESH_OnEnterRun(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterRun>                    DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterRun */

FUNC(void, BSWM_CODE) BswM_ESH_OnEnterShutdown(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterShutdown>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterShutdown */

FUNC(void, BSWM_CODE) BswM_ESH_OnEnterWaitForNvm(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterWaitForNvm>             DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   NvM_RequestResultType ErrorStatus;
   do
   {
      NvM_MainFunction();
      Fee_30_FlexNor_MainFunction();
      Fls_MainFunction();
      NvM_GetErrorStatus(NvMConf___MultiBlockRequest, &ErrorStatus);
   } while (ErrorStatus == NVM_REQ_PENDING);

   if (ErrorStatus == NVM_REQ_OK)
   {
      CustShutdownTaskCompleted = (uint8)CODED_TRUE;
   }
   else
   {
      CustShutdownTaskCompleted = (uint8)CODED_FALSE;
   }
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterWaitForNvm */

FUNC(void, BSWM_CODE) BswM_ESH_OnEnterWakeup(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterWakeup>                 DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterWakeup */

FUNC(void, BSWM_CODE) BswM_INIT_NvMReadAll(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_INIT_NvMReadAll>                   DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   NvM_RequestResultType ErrorStatus;
   NvM_ReadAll();
   do
   {
      NvM_MainFunction();
      Fee_30_FlexNor_MainFunction();
      Fls_MainFunction();
      NvM_GetErrorStatus(NvMConf___MultiBlockRequest, &ErrorStatus);
   } while (ErrorStatus == NVM_REQ_PENDING);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of BswM_INIT_NvMReadAll */

FUNC(void, BSWM_CODE) Ecu_PerformSoftReset(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Ecu_PerformSoftReset>                   DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   Perform_SoftReset();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of Ecu_PerformSoftReset */

FUNC(void, BSWM_CODE) Eth_ComM_Init(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Eth_ComM_Init>                          DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* B0CVAL is not having Phy available in ecu, so Request Full COMM only if board revision is not B0CVAL */
   if (BOARD_REV_B0CVAL != Get_Board_Revision())
   {
      ComM_RequestComMode(ComMConf_ComMChannel_cnctr_RDR_RdrNet_5172a59b, COMM_FULL_COMMUNICATION);
   }
   else
   {
      ComM_RequestComMode(ComMConf_ComMChannel_cnctr_RDR_RdrNet_5172a59b, COMM_NO_COMMUNICATION);
   }

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of Eth_ComM_Init */

FUNC(void, BSWM_CODE) Ipdu_Mode(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Ipdu_Mode>                              DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   uint8 ecu_position;

   ecu_position = Get_Radar_Position(); // Get_Current_ECU_Position();

   if (ecu_position != 0x1)
   {
      Com_SwitchIpduTxMode(ComConf_ComIPdu_RDR_BSD1_Tx_oPCAN_RADAR_170995fb_Tx, FALSE);
      Com_SwitchIpduTxMode(ComConf_ComIPdu_GW_prop_ADAS_BSIS_info_oPCAN_RADAR_f2d61fec_Tx, FALSE);
   }

   if (ecu_position != 0x5)
   {
      Com_SwitchIpduTxMode(ComConf_ComIPdu_MOIS_oVCAN_RADAR_39784631_Tx, FALSE);
      Com_SwitchIpduTxMode(ComConf_ComIPdu_prop_ADAS_MOIS_info_oVCAN_RADAR_f03aed28_Tx, FALSE);
   }

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of Ipdu_Mode */

FUNC(void, BSWM_CODE) UserCalloutFunc_AckModeTransition_Execute(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK UserCalloutFunc_AckModeTransition_Execute> DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   Diag_services_fnc_caller();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of UserCalloutFunc_AckModeTransition_Execute */

FUNC(void, BSWM_CODE) UserCallout_Det_Init(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK UserCallout_Det_Init>                   DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   Det_Init(Det_Config_Ptr);

   /* Det Filter Configuration */

/*Offical release enable*/
#if (APTIV_OFFICIAL_RELEASE == TRUE)
   detBreakFilter[0u].mModuleId   = 0xFFFFU;
   detBreakFilter[0u].mInstanceId = 0xFFU;
   detBreakFilter[0u].mApiId      = 0xFFU;
   detBreakFilter[0u].mErrorId    = 0xFFU;
#else
   /* HYX-418 is created to resolve the issue */
   detBreakFilter[1u].mModuleId   = CANTP_MODULE_ID;
   detBreakFilter[1u].mInstanceId = CANTP_INSTANCE_ID_DET;
   detBreakFilter[1u].mApiId      = CANTP_SID_RXINIT;
   detBreakFilter[1u].mErrorId    = CANTP_E_INVALID_RX_BUFFER;

   /* HYX-418 is created to resolve the issue */
   detBreakFilter[2u].mModuleId   = CANTP_MODULE_ID;
   detBreakFilter[2u].mInstanceId = CANTP_INSTANCE_ID_DET;
   detBreakFilter[2u].mApiId      = CANTP_SID_RXINDICATION;
   detBreakFilter[2u].mErrorId    = CANTP_E_INVALID_RX_LENGTH;

#endif
   /* Enable break filter in general*/
   detStatus.breakFilterActive = TRUE; /* replaced 1 with TRUE to resolve coverity warning */
   /* Enable logging in general*/
   detStatus.logActive = TRUE; /* replaced 1 with TRUE to resolve coverity warning */

   Det_Start();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of UserCallout_Det_Init */

FUNC(void, BSWM_CODE) User_CAN_ComPduGroupHandling(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User_CAN_ComPduGroupHandling>           DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   uint8 ecu_position;

   ecu_position = Get_Radar_Position(); // Get_Current_ECU_Position();

   switch (ecu_position)
   {
      case 1: /* ECU_POS_VARIANT_RDR01 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Tx_b6bdb067, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR01_oVCAN_RADAR_Rx_BC_7567adec, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR01_oVCAN_RADAR_Tx_0xD0_2361e9dc, 1);
         break;
      }
      case 2: /* ECU_POS_VARIANT_RDR02 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR02_oPCAN_RADAR_Rx_c92fa313, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR02_oPCAN_RADAR_Tx_9f750495, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR02_oVCAN_RADAR_Rx_BC_d6312b45, 1);

         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR02_oVCAN_RADAR_Tx_0xD0_587f6b3f, 1);
         break;
      }
      case 3: /* ECU_POS_VARIANT_RDR03 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR03_oPCAN_RADAR_Rx_67473282, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR03_oPCAN_RADAR_Tx_311d9504, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR03_oVCAN_RADAR_Rx_BC_01d3ab1d, 1);

         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR03_oVCAN_RADAR_Tx_0xD0_c7a5e8a1, 1);
         break;
      }
      case 4: /* ECU_POS_VARIANT_RDR04 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR04_oPCAN_RADAR_Rx_9abecaf7, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR04_oPCAN_RADAR_Tx_cce46d71, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR04_oVCAN_RADAR_Rx_BC_4bed2056, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR04_oVCAN_RADAR_Tx_0xD0_ae426ef9, 1);
         break;
      }
      case 5: /* ECU_POS_VARIANT_RDR05 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR05_oPCAN_RADAR_Rx_34d65b66, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR05_oPCAN_RADAR_Tx_628cfce0, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR05_oVCAN_RADAR_Tx_0xD0_3198ed67, 1);
         break;
      }
      case 6: /* ECU_POS_VARIANT_RDR06 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR06_oPCAN_RADAR_Rx_1d1eef94, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR06_oPCAN_RADAR_Tx_4b444812, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR06_oVCAN_RADAR_Rx_BC_3f5926a7, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR06_oVCAN_RADAR_Tx_0xD0_4a866f84, 1);
         break;
      }
      case 7: /* ECU_POS_VARIANT_RDR07 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR07_oPCAN_RADAR_Rx_b3767e05, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR07_oPCAN_RADAR_Tx_e52cd983, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR07_oVCAN_RADAR_Rx_BC_e8bba6ff, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR07_oVCAN_RADAR_Tx_0xD0_d55cec1a, 1);
         break;
      }
      case 8: /* ECU_POS_VARIANT_RDR08 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR08_oPCAN_RADAR_Rx_3d9c193f, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR08_oPCAN_RADAR_Tx_6bc6beb9, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR08_oVCAN_RADAR_Rx_BC_ab243031, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR08_oVCAN_RADAR_Tx_0xD0_99496334, 1);
         break;
      }
      default:
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Tx_b6bdb067, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR01_oVCAN_RADAR_Rx_BC_7567adec, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR01_oVCAN_RADAR_Tx_0xD0_2361e9dc, 1);
         break;
      }
   }
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of User_CAN_ComPduGroupHandling */

FUNC(void, BSWM_CODE) User_Com_Init(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User_Com_Init>                          DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   Com_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_Com_Init);
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of User_Com_Init */

FUNC(void, BSWM_CODE) User_EthIf_Init(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User_EthIf_Init>                        DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   NXP_RTL_PHY_MODEL_T lConnected_PHY;

   /* Initialize Ethernet MAC and SERDES */
   if (BOARD_REV_B0CVAL != Get_Board_Revision())
   {
      Eth_Init(&Eth_Config);
   }
   else
   {
      disable_ethernet_clocks();
   }
#ifdef Enable_PHY_100Mb
   Configured_PHY_1Gb = false;
#else
   Configured_PHY_1Gb             = true;
#endif

   /*lint -save -e534 */ /* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */

   /* Identify the connected PHY manufacturer/sub-model (RTL9010/RTL9000/TJA1103/TJA1120). */
   lConnected_PHY = Get_PHY_Model();

   if (RTL_9010x == lConnected_PHY)
   {
      /* Initialize RTL Transceiver */
      EthTrcv_30_Rtl9010_Init(EthTrcv_30_Rtl9010_Config_Ptr);
      /* RTL9010BSA: combo PHY (100Mb or 1Gbps) ??? capability matches both build variants */
      /* PHY-type-specific DSP configuration is applied in RTL_PHY_Post_Init() */
#ifdef Enable_PHY_100Mb
      EthIf_Init(EthIf_Config_RDR_02_Ptr);
#else
      EthIf_Init(EthIf_Config_RDR_01_Ptr);
#endif
   }
   else if (RTL_9000Cx == lConnected_PHY)
   {
      /* TODO : Add code when it's ready */
   }
   else if ((NXP_TJA1103 == lConnected_PHY) || (NXP_TJA1120 == lConnected_PHY))
   {
      /* Initialize NXP Transceiver */
      EthTrcv_30_Tja1103_Init(EthTrcv_30_Tja1103_Config_Ptr);
      EthIf_Init(EthIf_Config_RDR_03_Ptr);
   }
   else
   {
      /* PHY not identified ??? fall back to compile-time default so EthIf_Init always runs */
      EthIf_Init(EthIf_Config_RDR_01_Ptr);
   }
   /*lint -restore */

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

} /* End of User_EthIf_Init */

#define BSWM_STOP_SEC_CALLOUT_CODE_ASIL_D
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if 0
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK ESH_ComM_CheckPendingRequests>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Ecu_PerformHardReset>                   DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

#endif

/**********************************************************************************************************************
 *  END OF FILE: BSWM_CALLOUT_STUBS.C
 *********************************************************************************************************************/
