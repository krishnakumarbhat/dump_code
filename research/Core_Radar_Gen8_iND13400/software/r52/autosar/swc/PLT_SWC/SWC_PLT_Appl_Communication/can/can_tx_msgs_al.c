
/*===========================================================================*/
/**
 * @file can_tx_msgs_al.c
 *
 * CAN transmission message composition and handling for MOIS/BSIS signals.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This module handles the composition and transmission of CAN messages for
 * MOIS (Moving Object Indication System) and BSIS (Blind Spot Information System)
 * functionality. It reads data from the DSP-to-MCU IPC buffer and maps it to the
 * corresponding CAN signals. Additional CAN message handling may be added here
 * as the feature set expands.
 *
 * @section ABBR ABBREVIATIONS:
 *   - BSIS: Blind Spot Information System
 *   - BSD:  Blind Spot Detection
 *   - CAN:  Controller Area Network
 *   - ECU:  Electronic Control Unit
 *   - IPC:  Inter-Processor Communication
 *   - MOIS: Moving Object Indication System
 *   - RTE:  Runtime Environment (AUTOSAR)
 *   - VDP:  Vehicle Data Port
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Core_Radar_Gen8_CAN_Messaging_Architecture
 *     - SWC_PLT_Appl_Communication_Design
 *
 *   - Requirements Document(s):
 *     - Core_Radar_Gen8_System_Requirements
 *     - CAN_Messaging_Protocol_Specification
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/GlobalRegional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
 *     - AUTOSAR C Coding Standards
 *     - CAN Protocol Standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "can_tx_msgs_al.h"
#include "Rte_SWC_PLT_Appl_Communication.h"
#include "can_rx_msgs.h"
#include "can_signals.h"
#include "can_tx_msgs.h"
#include "ipc_data.h"
#include "ipc_mss.h"
#include "sensor_position.h"

/*===========================================================================*
 * Local Preprocessor #define Configurations
 *===========================================================================*/
/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
#define Write_MOIS_Message Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_MOIS_ALVCAN_Vdp_SG_MOIS_ALVCAN
#define Write_BSIS_Message Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RDR_BSD1_Tx_ALPCAN_Vdp_SG_RDR_BSD1_Tx_ALPCAN
#define Write_prop_ADAS_MOIS_info_Message                                                                                         \
   Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_prop_ADAS_MOIS_info_ALVCAN_Vdp_SG_prop_ADAS_MOIS_info_ALVCAN
#define Write_prop_ADAS_BSIS_info_Message                                                                                         \
   Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_GW_prop_ADAS_BSIS_info_ALPCAN_Vdp_SG_GW_prop_ADAS_BSIS_info_ALPCAN
/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
Self_BSIS_Feature_Degradation_Flags_T bsis_feature_degradation_flags;
Self_MOIS_Feature_Degradation_Flags_T mois_feature_degradation_flags;

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/*===========================================================================*\
 * FUNCTION: Send_MOIS_Messages
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * - Get_IPC_D2M_Sp_Post_Proc_Buffer() — reads DSP-to-MCU post-processing IPC buffer
 * - Rte_Write_Pp_ObjectDetectionState_AL_*         — writes ObjectDetectionState signal
 * - Rte_Write_Pp_CollisionWarningLevel_AL_*        — writes CollisionWarningLevel signal
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Reads mois_alert_level and mois_number_of_relevant_objects from the
 * MOIS IPC output and maps them to the three CAN signals:
 *   - ObjectDetectionState:          0x05 (collision warning) if alert_level > 0,
 *                                    0x03 (ready/activated) if alert_level == 0.
 *   - CollisionWarningLevel:         Direct mapping from mois_alert_level.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Send_MOIS_Messages(void)
{
   I_SG_MOIS_ALVCAN mois_msg                     = {0};
   I_SG_prop_ADAS_MOIS_info_ALVCAN mois_info_msg = {0};
   uint8_t system_state, state;
   D2M_Msg_T *d2m_buf_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();

   system_state = d2m_buf_ptr->payload.Mois_IPC_Output.mois_cust_mm_output.MOIS_Systemsts;

   /* CollisionWarningLevel */
   mois_msg.MOISCollisionWarningLevel          = d2m_buf_ptr->payload.Mois_IPC_Output.mois_cust_mm_output.MOIS_Alert;
   mois_info_msg.rdn_MOISCollisionWarningLevel = d2m_buf_ptr->payload.Mois_IPC_Output.mois_cust_mm_output.MOIS_Alert;
   switch (system_state)
   {
      case 0U:
         state = DETECTION_STATE_DRIVER_DEACTIVATED; /* DBC = 2 */
         break;
      case 1U:
      case 2U:
         state = DETECTION_STATE_READY_ACTIVATED; /* DBC = 3 */
         break;

      case 3U:
         state = DETECTION_STATE_COLLISION_WARNING; /* DBC = 5 */
         break;

      case 4U:
         state = DETECTION_STATE_ERROR; /* DBC = 14 */
         break;
      case 5U:
         state = DETECTION_STATE_NOT_READY; /* DBC = 0 */
         break;
      default:
         state = DETECTION_STATE_READY_ACTIVATED; /* DBC = 3 */
         break;
   }
   /* ObjectDetectionState */
   mois_msg.MovingObjectDetectionState          = state;
   mois_info_msg.rdn_MovingObjectDetectionState = state;

   (void)Write_MOIS_Message(&mois_msg);
   Write_prop_ADAS_MOIS_info_Message(&mois_info_msg);
}
/*===========================================================================*\
 * FUNCTION: Send_BSIS_Messages
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * - Get_IPC_D2M_Sp_Post_Proc_Buffer() — reads DSP-to-MCU post-processing IPC buffer
 * - Rte_Write_Pp_BlindSpotDetectionState_AL_*              — writes BlindSpotDetectionState signal
 * - Rte_Write_Pp_BlindSpotCollisionWarningLevel_AL_*       — writes BlindSpotCollisionWarningLevel signal
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Reads bsis_alert_level from the BSIS IPC output and maps it to
 * the four BSD1 CAN signals:
 *   - BlindSpotDetectionState:             0x05 (collision warning) if alert_level > 0,
 *                                          0x03 (ready/activated) if alert_level == 0.
 *   - BlindSpotCollisionWarningLevel:      Direct mapping from bsis_alert_level.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Send_BSIS_Messages(void)
{
   I_SG_RDR_BSD1_Tx_ALPCAN bsis_msg                 = {0};
   I_SG_GW_prop_ADAS_BSIS_info_ALPCAN bsis_info_msg = {0};
   uint8_t system_state, state;
   D2M_Msg_T *d2m_buf_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   system_state           = d2m_buf_ptr->payload.Bsis_IPC_Output.bsis_cust_mm_output.BSIS_Systemsts;
   /* CollisionWarningLevel */
   bsis_msg.BlindSpotCollisionWarningLevel_Tx   = d2m_buf_ptr->payload.Bsis_IPC_Output.bsis_cust_mm_output.BSIS_Alert;
   bsis_info_msg.BlindSpotCollisionWarningLevel = d2m_buf_ptr->payload.Bsis_IPC_Output.bsis_cust_mm_output.BSIS_Alert;

   /* ObjectDetectionState */
   switch (system_state)
   {
      case 0U:
         state = DETECTION_STATE_DRIVER_DEACTIVATED; /* DBC = 2 */
         break;

      case 1U:
      case 2U:
         state = DETECTION_STATE_READY_ACTIVATED; /* DBC = 3 */
         break;

      case 3U:
         state = DETECTION_STATE_COLLISION_WARNING; /* DBC = 5 */
         break;

      case 4U:
         state = DETECTION_STATE_ERROR; /* DBC = 14 */
         break;

      default:
         state = DETECTION_STATE_READY_ACTIVATED; /* DBC = 3 */
         break;
   }
   bsis_msg.BlindSpotDetectionState_Tx   = state;
   bsis_info_msg.BlindSpotDetectionState = state;

   (void)Write_BSIS_Message(&bsis_msg);
   Write_prop_ADAS_BSIS_info_Message(&bsis_info_msg);
}

/*===========================================================================*\
 * FUNCTION: Get_Coded_Bool_Value
 *===========================================================================
 * RETURN VALUE:
 * uint8_t
 *
 * PARAMETERS:
 * uint8_t flag
 * uint8_t true_val
 * uint8_t false_val
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Get the coded boolean value for CAN signal population based on the input flag and DBC values
 * --------------------------------------------------------------------------
 * This function gives the coded boolean value based on the input flag and DBC values.
\*===========================================================================*/
static uint8_t Get_Coded_Bool_Value(uint8_t flag, uint8_t true_val, uint8_t false_val)
{
   uint8_t ret_val = CODED_FALSE;

   if (true_val == flag)
   {
      ret_val = CODED_FALSE;
   }
   else if (false_val == flag)
   {
      ret_val = CODED_TRUE;
   }
   else
   {
      /* coded value not recognized, retain default */
   }
   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: L2_BSIS_Feature_Degradation_Check
 *===========================================================================
* RETURN VALUE:
* uint8_t
*
* PARAMETERS:
* void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * CAVEATS:
 * This function sets the L1 feature degradation flag by taking into consideration the below mentioned conditions.
 * i) Time sync failed fault is active
 * ii) HED_TIME_SYNC_SRC_MASTER indicates the master time sync source is active
 * iii) Operation mode faulty(0x3) in FC Radar should trigger the degradation flag and operation mode = OPERATIONAL should not
trigger the degradation flag.
 * iv) Point iii for SRR-L1 OR SRR-L2 should also trigger the degradation flag accordingly.
 * v) Blockage status for FC sets the degradation flag according to the below scenarios
 *    - Sensor Blocked : Blockage Status = BlockSts_ok(0x1) AND Blockage value = any value other than 0x0 & 0x1
 *    - Sensor Blocked : Blockage Status = BlockSts_faulty(0x0) OR BlockSts_invalid(0x4)
 *    - Sensor Not Blocked : Blockage Status = BlockSts_ok(0x1) AND Blockage value = 0x0 OR 0x1
 * --------------------------------------------------------------------------
* ABSTRACT: Set the L1 feature degradation flag based on specific conditions.
* --------------------------------------------------------------------------
* This function returns the L1 BSIS feature degradation flag as a CODED_TRUE in fault case and CODED_FALSE otherwise.
* PRS requirements to be considered for testing :
* 1) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106823
* 2) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106825
* 3) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106844
* 4) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106846
* 5) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106849
\*===========================================================================*/
uint8_t L2_BSIS_Feature_Degradation_Check(Self_Feature_Degradation_Params_T feature_degradation_params)
{
   uint8_t l2_bsis_feature_degradation_flag = CODED_FALSE;
   uint8_t sensor_pos                       = Get_Radar_Position();

   if (SENSOR_POS_L2 == sensor_pos)
   {
      if (Cx1_SYNCED_AT_LEAST_ONCE == feature_degradation_params.self_time_sync_validity_flag)
      {
         bsis_feature_degradation_flags.bsis_self_time_sync_validity_degrade_flag = CODED_FALSE;
      }
      else if ((Cx2_SYNC_MSG_TIMEOUT_OR_CRC_ERR == feature_degradation_params.self_time_sync_validity_flag) ||
               (Cx0_OUT_OF_SYNC == feature_degradation_params.self_time_sync_validity_flag))
      {
         bsis_feature_degradation_flags.bsis_self_time_sync_validity_degrade_flag = CODED_TRUE;
      }

      bsis_feature_degradation_flags.bsis_self_op_mode_degrade_flag =
         Get_Coded_Bool_Value(feature_degradation_params.self_op_mode, Cx2_Operational, Cx3_OpMode_Faulty);
   }
   l2_bsis_feature_degradation_flag = ((CODED_TRUE == bsis_feature_degradation_flags.bsis_self_time_sync_validity_degrade_flag) ||
                                       (CODED_TRUE == bsis_feature_degradation_flags.bsis_self_op_mode_degrade_flag) ||
                                       (CODED_TRUE == bsis_feature_degradation_flags.bsis_self_align_init_calib_degrade_flag)) ?
                                         CODED_TRUE :
                                         CODED_FALSE;

   return l2_bsis_feature_degradation_flag;
}

/*===========================================================================*\
 * FUNCTION: FC_MOIS_Feature_Degradation_Check
 *===========================================================================
 * RETURN VALUE:
 * uint8_t
 *
 * PARAMETERS:
 * L1_Feature_Degradation_Params_T feature_degradation_params
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * CAVEATS:
 * This function sets the L1 MOIS feature degradation flag by taking into consideration the below mentioned conditions.
 * i) FC operation mode faulty(0x3) should trigger the degradation flag and operation mode = OPERATIONAL(0x2) should not trigger
it.
 * ii) Only applies for sensor position 5 (MOIS sensor position).
 * --------------------------------------------------------------------------
 * ABSTRACT: Set the L1 MOIS feature degradation flag based on FC operation mode and blockage status.
 * --------------------------------------------------------------------------
 * This function returns the L1 MOIS feature degradation flag as a CODED_TRUE in fault case and CODED_FALSE otherwise.
 * PRS requirements to be considered for testing :
 * 1) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106843
 * 2) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106845
 * 3) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106848
\*===========================================================================*/
uint8_t FC_MOIS_Feature_Degradation_Check(Self_Feature_Degradation_Params_T feature_degradation_params)
{
   uint8_t l1_mois_feature_degradation_flag = CODED_FALSE;

   uint8_t sensor_pos = Get_Radar_Position();
   if (SENSOR_POS_FC == sensor_pos)
   {
      mois_feature_degradation_flags.mois_self_op_mode_degrade_flag =
         Get_Coded_Bool_Value(feature_degradation_params.self_op_mode, Cx2_Operational, Cx3_OpMode_Faulty);
   }
   l1_mois_feature_degradation_flag = ((CODED_TRUE == mois_feature_degradation_flags.mois_self_op_mode_degrade_flag ||
                                        CODED_TRUE == mois_feature_degradation_flags.mois_self_align_init_calib_degrade_flag) ?
                                          CODED_TRUE :
                                          CODED_FALSE);

   return l1_mois_feature_degradation_flag;
}
