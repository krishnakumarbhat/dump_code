/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  E2EXf_LCfg.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR E2EXf Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  MICROSAR E2EXf header file for link-time variant
 *********************************************************************************************************************/

/* double include prevention */
#ifndef E2EXF_LCFG_H
# define E2EXF_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "SchM_E2EXf_Type.h"
# define E2EXF_LEGACY_STATEMACHINE (STD_OFF)

# include "E2E_P05.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Version identification */
# define E2EXF_CFG_MAJOR_VERSION   (0x01U)
# define E2EXF_CFG_MINOR_VERSION   (0x11U)

# define E2EXF_VERSION_INFO_API    (STD_OFF)

# define E2EXF_DEV_ERROR_DETECT    (STD_ON)
# define E2EXF_DEV_ERROR_REPORT    (STD_ON)

# define E2EXF_P01_ENABLED         (STD_OFF)
# define E2EXF_P02_ENABLED         (STD_OFF)
# define E2EXF_P04_ENABLED         (STD_OFF)
# define E2EXF_P04m_ENABLED        (STD_OFF)
# define E2EXF_P05_ENABLED         (STD_ON)
# define E2EXF_P06_ENABLED         (STD_OFF)
# define E2EXF_P07_ENABLED         (STD_OFF)
# define E2EXF_P08_ENABLED         (STD_OFF)
# define E2EXF_P11_ENABLED         (STD_OFF)
# define E2EXF_P22_ENABLED         (STD_OFF)
# define E2EXF_P44_ENABLED         (STD_OFF)
# define E2EXF_PJ193976_ENABLED    (STD_OFF)
# define E2EXF_PRN_ENABLED         (STD_OFF)

# define E2EXF_OUTOFPLACE_ENABLED  (STD_OFF)
# define E2E_HANDLE_COMFEEDBACK    (STD_OFF)

/* ----- Modes ----- */
# define E2EXF_UNINIT              (0x00U)
# define E2EXF_INIT                (0x01U)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

# ifndef E2EXF_DUMMY_STATEMENT
#  define E2EXF_DUMMY_STATEMENT(v) (v)=(v)
# endif
# ifndef E2EXF_DUMMY_STATEMENT_CONST
#  define E2EXF_DUMMY_STATEMENT_CONST(v) (void)(v)
# endif

/**********************************************************************************************************************
 * E2EXf transformers
 *********************************************************************************************************************/

# define E2EXF_START_SEC_CODE_ASIL_D
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08, \
         &E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08, \
         &E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE_ASIL_D
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * E2EXf retransformers
 *********************************************************************************************************************/

# define E2EXF_START_SEC_CODE_ASIL_D
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07)
/* PRQA L:L2 */

/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv( \
         buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08, \
         &E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08, \
         &E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08, \
         &E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08, \
         &E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE_ASIL_D
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct {
  boolean inPlace;
  boolean executeDespiteDataUnavailability;
  boolean profileBehavior;
  boolean disableEndToEndCheck;
  uint32 headerLength;
  uint32 upperHeaderBitsToShift;
} E2EXf_OptionsType;

typedef struct
{
  /* postbuild not yet supported */
  uint8 E2EXf_dummy;
} E2EXf_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Initialization state of the module */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_ModuleInitialized;

# define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_CLEARED) E2EXf_P05CheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
extern VAR(uint8, E2EXF_VAR_CLEARED) E2EXf_SMProfileStatusWindow_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08[2]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_CLEARED) E2EXf_SMCheckState_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define E2EXF_START_SEC_CODE_ASIL_D
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  E2EXf_Init_Calls
 *********************************************************************************************************************/
/*! \brief       State structures initialization function
 *  \details     This function initializes all state structures managed by E2EXf.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, E2EXF_CODE) E2EXf_Init_Calls(void);

/**********************************************************************************************************************
 *  E2EXf_InitMemory()
 *********************************************************************************************************************/
/*! \brief       Function for *_INIT_*-variable initialization and for clearing *_CLEARED_*-variables to zero
 *  \details     Service to initialize module global variables at power up. This function initializes the
 *                variables in *_INIT_* sections and clears *_CLEARED_*-variables to zero.
 *                Used in case they are not initialized by the startup code.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, E2EXF_CODE) E2EXf_InitMemory(void);

# define E2EXF_STOP_SEC_CODE_ASIL_D
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* E2EXF_LCFG_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_E2EXf_0791:  MISRA rule: -
     Reason:       Transformer names are derived from the configuration.
     Risk:         No functional risk.
     Prevention:   Not required.

*/
