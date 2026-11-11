
/*===========================================================================*/
/**
 * @file toi_algo_interface.c
 *
 *      This file contains  Module.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 *   This file implements the algorithm interface layer for the TOI Character
 *   Quality Determination module. It provides initialization and accessor
 *   functions for TOI input/output parameter structures, and maps inter-processor
 *   communication (IPC) buffer data (D2M, M2D messages) to the algorithm-specific
 *   parameters including detection data (SNR, azimuth/elevation confidence,
 *   bistatic flag, single target flag, power), radar data status, and blockage
 *   information. Both downselection and non-downselection data paths are supported.
 *
 * @section ABBR ABBREVIATIONS:
 *   - Open below WI in document
 *   - "https://polarionprod1.aptiv.com/polarion/redirect/project/CORE_RADAR_GEN5/workitem?id=WI-316084"
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     -
 *"https://polarionprod1.aptiv.com/polarion/#/project/CORE_RADAR_GEN5/wiki/531-SDD_Radar/AAU_SDD_CoreRadar_TOI_Character_Quality_Determination"
 *
 *   - Requirements Document(s):
 *     -
 *"https://polarionprod1.aptiv.com/polarion/#/project/CORE_RADAR_GEN5/wiki/511-SRS_Radar/CMP_SRS_CoreRadar_Front_End_Management"
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *   - <a href="https://spo.aptiv.com/sites/0307-eoses/GlobalRegional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "toi_algo_interface.h"
#include "ipc_data.h"
#include "ipc_dsp.h"

/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Local Preprocessor #define MACROS
\*===========================================================================*/

/*===========================================================================*\
 * Local Type Declarations
\*===========================================================================*/
#if (DOWNSELECTION_ENABLE == 1U)
   #define Get_SNR_IP_PTR(x)             ((x)->payload.downselection_data.af_ds_data.snr)
   #define Get_AZ_CONF_IP_PTR(x)         ((x)->payload.downselection_data.af_ds_data.az_conf)
   #define Get_EL_CONF_IP_PTR(x)         ((x)->payload.downselection_data.af_ds_data.el_conf)
   #define Get_F_BISTATIC_IP_PTR(x)      ((x)->payload.downselection_data.af_ds_data.f_bistatic)
   #define Get_F_SINGLE_TARGET_IP_PTR(x) ((x)->payload.downselection_data.af_ds_data.f_single_target)

/*-> Commented until further strategy of EMH-25940 Detection stream update in af signals is finalised.
   //#define Get_AF_IP_DET_DATA(x)         ((x)->payload.downselection_data.af_ds_data)
   //#define Get_POW_IP_PTR(x)             ((x)->payload.downselection_data.af_ds_data.pow)
   //#define Get_AF_NUM_DET(x)             ((x)->payload.downselection_data.af_ds_data.num_af_ds_det)
*/

   #define Get_TOI_OP_DATA_PTR(x)   ((x)->payload.toi_ds_stream_data.toi_op_data)
   #define Get_TOI_OP_STREAM_PTR(x) ((x)->payload.toi_ds_stream_data)
#else
   #define Get_AF_IP_DET_DATA(x)         ((x)->payload.det_data.af_data)
   #define Get_SNR_IP_PTR(x)             ((x)->payload.det_data.af_data.snr)
   #define Get_AZ_CONF_IP_PTR(x)         ((x)->payload.det_data.af_data.az_conf)
   #define Get_EL_CONF_IP_PTR(x)         ((x)->payload.det_data.af_data.el_conf)
   #define Get_F_BISTATIC_IP_PTR(x)      ((x)->payload.det_data.af_data.f_bistatic)
   #define Get_F_SINGLE_TARGET_IP_PTR(x) ((x)->payload.det_data.af_data.f_single_target)
   #define Get_POW_IP_PTR(x)             ((x)->payload.det_data.af_data.pow)
   #define Get_AF_NUM_DET(x)             ((x)->payload.det_data.num_af_det)
   #define Get_TOI_OP_DATA_PTR(x)        ((x)->payload.toi_stream_data.toi_op_data)
   #define Get_TOI_OP_STREAM_PTR(x)      ((x)->payload.toi_stream_data)
#endif

/*===========================================================================*\
 * Exported Object Definitions
\*===========================================================================*/

/*===========================================================================*\
 * Local Object Definitions
\*===========================================================================*/
static TOI_Input_Params_T __attribute__((section(".sram0.bss"))) TOI_Input_Params;
static TOI_Output_Params_T __attribute__((section(".sram0.bss"))) TOI_Output_Params;

/*===========================================================================*\
* Local Function Prototypes
\*===========================================================================*/
/**
 * FUNCTION:Get_TOI_Init_Parameters()
 *    Returns the pointer to TOI_Input_Params
 *
 * \param[in]     none
 *
 * \return         TOI_Input_Params_T *
 *
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 *
 * TRACEABILITY INFO:
 *
 * SDD
 * WorkItem 1 : WI-24125
 *
 * SRD
 * WorkItem 1 : WI-23864
 */
TOI_Input_Params_T *Get_TOI_Init_Parameters(void)
{
   return (&TOI_Input_Params);
}

/**
 * FUNCTION:Get_TOI_Output_Parameters()
 *    Returns the pointer to TOI_Output_Params
 *
 * \param[in]     none
 *
 * \return         TOI_Output_Params_T *
 *
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 *
 * TRACEABILITY INFO:
 *
 * SDD
 * WorkItem 1 : WI-24125
 *
 * SRD
 * WorkItem 1 : WI-23864
 */
TOI_Output_Params_T *Get_TOI_Output_Parameters(void)
{
   return (&TOI_Output_Params);
}

/**
 * FUNCTION:Get_Payload_CRC_Mismatch_Err()
 *    Returns the rdr_data_sts_payload_crc_mismatch status.
 *
 * \param[in]     none
 *
 * \return         rdr_data_sts_payload_crc_mismatch
 *
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 *
 * TRACEABILITY INFO:
 */
uint8_t Get_Payload_CRC_Mismatch_Err(void)
{
   TOI_Input_Params_T *const toi_input_params_ptr = Get_TOI_Init_Parameters();
   return toi_input_params_ptr->crc_mismatch;
}

/**
 * FUNCTION:TOI_Parameters_Init()
 *    Initializes toi input and output parameters
 *
 * \param[in]     none
 *
 * \return         none
 *
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 *
 * TRACEABILITY INFO:
 *
 * SDD
 * WorkItem 1 :
 *
 * SRD
 * WorkItem 1 :
 */
void TOI_Parameters_Init(void)
{
   TOI_Input_Params_T *const toi_input_params_ptr   = Get_TOI_Init_Parameters();
   TOI_Output_Params_T *const toi_output_params_ptr = Get_TOI_Output_Parameters();
   D2M_Msg_T *d2m_ptr                               = (D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();
   /*M2D_Msg_T *m2d_ptr                               = (M2D_Msg_T *)Get_IPC_M2D_Buffer();*/

   /*Map input data from IPC buffer to TOI internal pointers*/
   toi_input_params_ptr->look_id       = d2m_ptr->payload.rdd_stream_data.look_data.look_id;
   toi_input_params_ptr->scan_index_ip = d2m_ptr->payload.rdd_stream_data.look_data.scan_index;

   /* Below are the dummy populated values to prevent data qualifier setting because of garbage data - those signals to be mapped
    * correctly once the actual signals are available */
   toi_input_params_ptr->rdd1_saturation_occured_flag_ip  = 0U;
   toi_input_params_ptr->interference_detected_ip         = CODED_FALSE;
   toi_input_params_ptr->range_check_interference_ip      = CODED_FALSE;
   toi_input_params_ptr->hw_accel_self_test_fault_flag_ip = Get_DSP_RA_Error_Status();
   toi_input_params_ptr->dsp_self_test_failure_flag_ip    = d2m_ptr->payload.diag_data.dsp_self_test_failure_flag;

   /* Keeping below mappings for reference */

   /*toi_input_params_ptr->rdd1_saturation_occured_flag_ip =
   d2m_ptr->payload.rdd_stream_data.rdd_data.rdd1_saturation_occured_flag; toi_input_params_ptr->interference_detected_ip        =
   a2m_ptr->payload.interference_detection_data.interference_detected; toi_input_params_ptr->range_check_interference_ip     =
   a2m_ptr->payload.interference_detection_data.range_check_interference;

   toi_input_params_ptr->det_proc_loop_overrun_flag_ip = d2m_ptr->payload.diag_data.detection_processing_loop_overrun_fault;
   toi_input_params_ptr->detection_data_integrity_fault_flag_ip = d2m_ptr->payload.diag_data.detection_data_integrity_fault;
   toi_input_params_ptr->range_check_blockage_ip = d2m_ptr->payload.radar_capability_data.blockage.range_check_blockage;
   toi_input_params_ptr->blockage_val_ip         = d2m_ptr->payload.radar_capability_data.blockage.blockage.value;
   toi_input_params_ptr->blockage_status_ip      = d2m_ptr->payload.radar_capability_data.blockage.blockage_status;

    -> Commented until further strategy of EMH-25940 Detection stream update in af signals is finalised.
   toi_input_params_ptr->af_ip_det_data         = &Get_AF_IP_DET_DATA(d2m_ptr);
   toi_input_params_ptr->det_ip_count           = Get_AF_NUM_DET(d2m_ptr);
   toi_input_params_ptr->snr_ip_ptr             = Get_SNR_IP_PTR(d2m_ptr);
    toi_input_params_ptr->az_conf_ip_ptr         = Get_AZ_CONF_IP_PTR(d2m_ptr);
    toi_input_params_ptr->el_conf_ip_ptr         = Get_EL_CONF_IP_PTR(d2m_ptr);
    toi_input_params_ptr->f_bistatic_ip_ptr      = Get_F_BISTATIC_IP_PTR(d2m_ptr);
   toi_input_params_ptr->f_single_target_ip_ptr = Get_F_SINGLE_TARGET_IP_PTR(d2m_ptr);
    toi_input_params_ptr->f_ci_det_ip_ptr         = Get_AF_IP_DET_DATA(d2m_ptr).f_ci_det;
   toi_input_params_ptr->pow_ip_ptr = Get_POW_IP_PTR(d2m_ptr);
   */

   /*Map output data pointers from IPC buffer to internal pointers */
   toi_output_params_ptr->toi_op_data_ptr   = &Get_TOI_OP_DATA_PTR(d2m_ptr);
   toi_output_params_ptr->toi_op_stream_ptr = &Get_TOI_OP_STREAM_PTR(d2m_ptr);

   Get_TOI_OP_STREAM_PTR(d2m_ptr).toi_ip_data.hw_accel_self_test_fault_flag_ip =
      toi_input_params_ptr->hw_accel_self_test_fault_flag_ip;
   Get_TOI_OP_STREAM_PTR(d2m_ptr).toi_ip_data.toi_interference_detected_ip = toi_input_params_ptr->interference_detected_ip;
   Get_TOI_OP_STREAM_PTR(d2m_ptr).toi_ip_data.toi_det_proc_loop_overrun_flag_ip =
      toi_input_params_ptr->det_proc_loop_overrun_flag_ip;
   Get_TOI_OP_STREAM_PTR(d2m_ptr).toi_ip_data.toi_rdd1_saturation_occured_flag_ip =
      toi_input_params_ptr->rdd1_saturation_occured_flag_ip;
}
