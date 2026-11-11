#ifndef PLATFORM_DIAG_CALLOUT_H
   #define PLATFORM_DIAG_CALLOUT_H

/**************************************************************************
 * Copyright 2019 Aptiv Technologies, Inc., All Rights Reserved.
 * Aptiv Confidential
 *
 * \b Application:        Diagnostics \n
 * \b File-Revision:      %version: 1 %\n
 * \b Last-Changed-by:fjvnnx  %derived_by: fjvnnx % \n
 * \b Classification:     CONFIDENTIAL \n
 * %date_modified: 09/09/2019 %
 *
 *
 *
 ***************************************************************************
 *
 *  Module Name:  Platform_Diag_Callout.h
 *
 *  Description:
 *    This file contains the declarations of precondition functions for platform faults, by which setting or clearing of fault can
 *be disabled.
 *
 *
 **************************************************************************/
/*====================================================================================================================*\
 *
 * Copyright 2019 Aptiv Electronic Controls, All Rights Reserved
 * It is not allowed to reproduce or utilize parts of this document in any form
 * or by any means, including photocopying and microfilm, without permission in
 * written by Aptiv Electronics & Safety Division.
 *
\*====================================================================================================================*/
/*=====================================================================================================================*
 * PREPROCESSOR DIRECTIVES
 *=====================================================================================================================*/

/* INCLUDE DIRECTIVES FOR OTHER HEADERS ------------------------------------------------------------------------------*/

   #include "Platform_Diag_Cfg.h"
//#include "hw_init_c2.h" // to be moved to SWC_Appl_Diag.h

/*====================================================================================================================*\
 * EXPORTED FUNCTIONS PROTOTYPES
\*====================================================================================================================*/

/* Function Prototypes------------------------------------------------------------------------------------------------*/
   /*Mirror Ram Integrity Check Fault check*/
   #if (TRUE == ENABLE_MIRROR_RAM_INTEGRITY_CHECK_FAULT_PLT)
   // extern uint8 Mirror_Ram_Integrity_Check_Fault_Check(void);
   #endif

   /* Preconditions for FEATURE_FUNCTION_CALIBRATION_CHECKSUM_FAULT*/
   #if (ENABLE_FEATURE_FUNCTION_CALIBRATION_CHECKSUM_FAULT_PLT)
      #if (PRECONDITION_ENABLE_FEATURE_FUNCTION_CALIBRATION_CHECKSUM_FAULT_PLT)
extern Std_ReturnType Feature_Function_Calibration_Checksum_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for MIRROR_RAM_INTEGRITY_CHECK_FAULT*/
   #if (ENABLE_MIRROR_RAM_INTEGRITY_CHECK_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MIRROR_RAM_INTEGRITY_CHECK_FAULT_PLT)
extern Std_ReturnType Mirror_Ram_Integrity_Check_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for HOST_APPLICATION_FLASH_CHECKSUM_FAULT*/
   #if (ENABLE_APPLICATION_FLASH_CHECKSUM_FAULT_PLT)
      #if (PRECONDITION_ENABLE_HOST_APPLICATION_FLASH_CHECKSUM_FAULT_PLT)
extern Std_ReturnType Application_Flash_Checksum_Fault_Precondition_Check(void);
      #endif
   #endif
/* Preconditions for MMIC_USC_UNPROGRAMMED_FAULT */
   #if (ENABLE_USC_MMIC_A_UNPROGRAMMED_FAULT_PLT)
      #if (PRECONDITION_USC_MMIC_A_UNPROGRAMMED_FAULT_PLT)
extern Std_ReturnType USC_MMIC_A_Unprogrammed_Fault_Precondition_Check(void);
      #endif
   #endif
/* Preconditions for MMIC_Error_Recovery_Fault */
   #if (ENABLE_MMIC_ERROR_RECOVERY_FAILURE_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_ERROR_RECOVERY_FAILURE_FAULT_PLT)
extern Std_ReturnType MMIC_Error_Recovery_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for SMC_VALIDTN_FLT*/
   #if (ENABLE_SMC_VALIDATION_FAULT_PLT)
      #if (PRECONDITION_ENABLE_SMC_VALIDATION_FAULT_PLT)
extern Std_ReturnType Smc_Validation_Fault_Test_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for USC_VALIDATION_FAULT*/
   #if (ENABLE_USC_VALIDATION_FAULT_PLT)
      #if (PRECONDITION_ENABLE_USC_VALIDATION_FAULT_PLT)
extern Std_ReturnType Usc_Validation_Fault_Test_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for CORE2_CALIBRATION_FLASH_CHECKSUM_FAULT*/
   #if (ENABLE_CORE2_CALIBRATION_FLASH_CHECKSUM_FAULT_PLT)
      #if (PRECONDITION_ENABLE_CORE2_CALIBRATION_FLASH_CHECKSUM_FAULT_PLT)
extern Std_ReturnType Core2_Calibration_Checksum_Fault_Test_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for STACK_OVERFLOW_FAULT*/
   #if (ENABLE_STACK_OVERFLOW_FAULT_PLT)
      #if (PRECONDITION_ENABLE_STACK_OVERFLOW_FAULT_PLT)
extern Std_ReturnType Stack_Overflow_Test_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for MMIC_TEMPERATURE_HIGH_FAULT */
   #if (ENABLE_MMIC_TEMPERATURE_HIGH_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_TEMPERATURE_HIGH_FAULT_PLT)
extern Std_ReturnType Dolphin_Temp_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for MMIC_ACQUISITION_OVERFLOW_FAULT_PLT */
   #if (ENABLE_MMIC_ACQUISITION_OVERFLOW_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_ACQUISITION_OVERFLOW_FAULT_PLT)
extern Std_ReturnType Aquisition_Overflow_Precondition_Check(void);
      #endif
   #endif
/* Preconditions for MMIC_A_SPI_FAULT */
   #if (ENABLE_PMIC_MCU_COMMUNICATION_FAULT_PLT)
      #if (PRECONDITION_ENABLE_PMIC_MCU_COMMUNICATION_FAULT_PLT)
extern Std_ReturnType pmic_mcu_communication_fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for MMIC_A_SPI_FAULT */
   #if (ENABLE_MMIC_A_SPI_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_A_SPI_FAULT_PLT)
extern Std_ReturnType Dolphin_Spi_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for MMIC_CHIRP_PLL_UNLOCKL_FAULT */
   #if (ENABLE_MMIC_CHIRP_PLL_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_CHIRP_PLL_FAULT_PLT)
extern Std_ReturnType Chirp_Pll_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for RF_BALL_BREAK_FAULT*/
   #if (ENABLE_MMIC_RF_BALL_BREAK_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_RF_BALL_BREAK_FAULT_PLT)
extern Std_ReturnType Rf_Ball_Break_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for RF_BALL_BREAK_FAULT*/
   #if (ENABLE_MMIC_LOOP_BACK_TEST_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_LOOP_BACK_TEST_FAULT_PLT)
extern Std_ReturnType MMIC_Loop_Back_test_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for MMIC_FUNCTIONAL_CONFIGURATION_FAULT */
   #if (ENABLE_MMIC_FUNCTIONAL_CONFIGURATION_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_FUNCTIONAL_CONFIGURATION_FAULT_PLT)
extern Std_ReturnType MMIC_Functional_Configuration_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for MMIC_A_TRANSMITTER_ID_FAULT */
   #if (ENABLE_MMIC_A_TRANSMITTER_ID_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_A_TRANSMITTER_ID_FAULT_PLT)
extern Std_ReturnType Transmitter_Id_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for MMIC_A_SAFE_START_FAULT */
   #if (ENABLE_MMIC_A_SAFE_START_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_A_SAFE_START_FAULT_PLT)
extern Std_ReturnType Dolphin_Safe_Start_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for EXTERNAL_WATCHDOG_FAULT */
   #if (ENABLE_EXTERNAL_WDG_FAULT_PLT)
      #if (PRECONDITION_ENABLE_EXTERNAL_WDG_FAULT_PLT)
extern Std_ReturnType External_Wdg_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for MICROPROCESSOR_TEMP_HIGH_FAULT*/
   #if (ENABLE_MICROPROCESSOR_TEMP_HIGH_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MICROPROCESSOR_TEMP_HIGH_FAULT_PLT)
extern Std_ReturnType Microprocessor_Temp_High_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for MICROPROCESSOR_TEMP_LOW_FAULT*/
   #if (ENABLE_MICROPROCESSOR_TEMP_LOW_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MICROPROCESSOR_TEMP_LOW_FAULT_PLT)
extern Std_ReturnType Microprocessor_Temp_Low_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for SIGNAL_INTEGRITY_FAULT */
   #if (ENABLE_SIGNAL_INTEGRITY_FAULT_PLT)
      #if (PRECONDITION_ENABLE_SIGNAL_INTEGRITY_FAULT_PLT)
extern Std_ReturnType Signal_Integrity_FAULT_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for MNR_BLOCKAGE*/
   #if (ENABLE_MNR_BLOCKAGE_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MNR_BLOCKAGE_FAULT_PLT)
extern Std_ReturnType MNR_Radar_Blockage_Detected_Fault_Test_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for BATTERY_LOW_FAULT*/
   #if (ENABLE_BATTERY_LOW_FAULT_PLT)
      #if (PRECONDITION_ENABLE_BATTERY_LOW_FAULT_PLT)
extern Std_ReturnType Battery_Low_Fault_Test_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for BATTERY_HIGH_FAULT*/
   #if (ENABLE_BATTERY_HIGH_FAULT_PLT)
      #if (PRECONDITION_ENABLE_BATTERY_HIGH_FAULT_PLT)
extern Std_ReturnType Battery_High_Fault_Test_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for DOLPHIN_SAFETY_INTEGTRITY_CHECK_FAULT*/
   #if (ENABLE_MMIC_A_SAFETY_INTEGTRITY_CHECK_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_A_SAFETY_INTEGTRITY_CHECK_FAULT_PLT)
extern Std_ReturnType Dolphin_Dafety_Integtrity_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for DOLPHIN_SENSOR_DEAD_FAULT*/
   #if (ENABLE_MMIC_A_SENSOR_DEAD_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_A_SENSOR_DEAD_FAULT_PLT)
extern Std_ReturnType Dolphin_Densor_Dead_Fault_Precondition_Check(void);
      #endif
   #endif

   /* Preconditions for THERMISTOR_OUT_OF_RANGE_FAULT*/
   #if (ENABLE_THERMISTOR_OUT_OF_RANGE_FAULT_PLT)
      #if (PRECONDITION_ENABLE_THERMISTOR_OUT_OF_RANGE_FAULT_PLT)
extern Std_ReturnType Thermistor_Out_Of_Range_Fault_Precondition_Check(void);
      #endif
   #endif

   /* Preconditions for MMIC_TX0_BALL_BREAK_FAULT */
   #if (ENABLE_MMIC_TX0_BALL_BREAK_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_TX0_BALL_BREAK_FAULT_PLT)
extern Std_ReturnType MMIC_TX0_Ball_Break_Precondition_Check(void);
      #endif
   #endif

   /* Preconditions for MMIC_TX1_BALL_BREAK_FAULT */
   #if (ENABLE_MMIC_TX1_BALL_BREAK_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_TX1_BALL_BREAK_FAULT_PLT)
extern Std_ReturnType MMIC_Tx1_Ball_Break_Fault_Precondition_Check(void);
      #endif
   #endif

   /* Preconditions for MMIC_TX2_BALL_BREAK_FAULT */
   #if (ENABLE_MMIC_TX2_BALL_BREAK_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_TX2_BALL_BREAK_FAULT_PLT)
extern Std_ReturnType MMIC_Tx2_Ball_Break_Fault_Precondition_Check(void);
      #endif
   #endif

   /* Preconditions for MMIC_TX3_BALL_BREAK_FAULT */
   #if (ENABLE_MMIC_TX3_BALL_BREAK_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_TX3_BALL_BREAK_FAULT_PLT)
extern Std_ReturnType MMIC_Tx3_Ball_Break_Fault_Precondition_Check(void);
      #endif
   #endif

   /* Preconditions for MCU_STARTUP_FAULT */
   #if (ENABLE_MCU_STARTUP_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MCU_STARTUP_FAULT_PLT)
extern Std_ReturnType MCU_Startup_Fault_Precondition_Check(void);
      #endif
   #endif

   /* Preconditions for MCU_REPETITIVE_RESET_FAULT */
   #if (ENABLE_MCU_REPETITIVE_RESET_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MCU_REPETITIVE_RESET_FAULT_PLT)
extern Std_ReturnType MCU_Repetitive_Reset_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for RFE_REPETITIVE_RESET_FAULT */
   #if (ENABLE_RFE_REPETITIVE_RESET_FAULT_PLT)
      #if (PRECONDITION_ENABLE_RFE_REPETITIVE_RESET_FAULT_PLT)
extern Std_ReturnType RFE_Repetitive_Reset_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for PLATFORM_TIME_FAULT */
   #if (ENABLE_PLATFORM_TIME_FAULT_PLT)
      #if (PRECONDITION_ENABLE_PLATFORM_TIME_FAULT_PLT)
extern Std_ReturnType Platform_time_Fault_Test_Precondition_Check(void);
      #endif
   #endif

   /*Preconditions for ALIGNMENT_NO_INITIAL_CALIBRATION_FAULT*/
   #if (ENABLE_ALIGNMENT_NO_INITIAL_CALIBRATION_FAULT_PLT)
      #if (PRECONDITION_ENABLE_ALIGNMENT_NO_INITIAL_CALIBRATION_FAULT_PLT)
extern Std_ReturnType Alignment_No_Initial_Calibration_Fault_Test_Precondition_Check(void);
      #endif
   #endif

/*Preconditions for ALIGNMENT_STATIC_CALIBRATION_FAULT */
   #if (ENABLE_ALIGNMENT_STATIC_CALIBRATION_FAULT_PLT)
      #if (PRECONDITION_ENABLE_ALIGNMENT_STATIC_CALIBRATION_FAULT_PLT)
extern Std_ReturnType Alignment_Static_Calibration_Fault_Test_Precondition_Check(void);
      #endif
   #endif

   /*Preconditions for ALIGNMENT_SERVICE_CALIBRATION_FAULT*/
   #if (ENABLE_ALIGNMENT_SERVICE_CALIBRATION_FAULT_PLT)
      #if (PRECONDITION_ENABLE_ALIGNMENT_SERVICE_CALIBRATION_FAULT_PLT)
extern Std_ReturnType Alignment_Service_Calibration_Fault_Test_Precondition_Check(void);
      #endif
   #endif

/*Preconditions for ALIGNMENT_SHORTTRACK_CALIBRATION_FAULT*/
   #if (ENABLE_ALIGNMENT_SHORTTRACK_CALIBRATION_FAULT_PLT)
      #if (PRECONDITION_ENABLE_ALIGNMENT_SHORTTRACK_CALIBRATION_FAULT_PLT)
extern Std_ReturnType Alignment_ShortTrack_Calibration_Fault_Test_Precondition_Check(void);
      #endif
   #endif

/*Preconditions for ALIGNMENT_AUTOALIGN_OUTOF_RANGE_FAULT*/
   #if (ENABLE_ALIGNMENT_AUTOALIGN_OUTOF_RANGE_FAULT_PLT)
      #if (PRECONDITION_ENABLE_ALIGNMENT_AUTOALIGN_OUTOF_RANGE_FAULT_PLT)
extern Std_ReturnType Alignment_Autoalign_outof_range_Fault_Test_Precondition_Check(void);
      #endif
   #endif

/*Preconditions for ALIGNMENT_AUTOALIGN_ALGO_FAULT*/
   #if (ENABLE_ALIGNMENT_AUTOALIGN_ALGO_FAULT_PLT)
      #if (PRECONDITION_ALIGNMENT_ENABLE_AUTOALIGN_ALGO_FAULT_PLT)
extern Std_ReturnType Alignment_Autoalign_Algo_Fault_Test_Precondition_Check(void);
      #endif
   #endif

/* Preconditions for ALIGNMENT_AUTOALIGNMENT_SUDDEN_JUMP_DETECTION_FAULT*/
   #if (ENBALE_ALIGNMENT_AUTOALIGNMENT_SUDDEN_JUMP_DETECTION_FAULT_PLT)
      #if (PRECONDITION_ALIGNMENT_AUTOALIGNMENT_SUDDEN_JUMP_DETECTION_FAULT_PLT)
extern Std_ReturnType Alignment_AutoAlignment_Sudden_Jump_Detection_Fault_Test_Precondition_Check(void);
      #endif
   #endif

/* Preconditions for BLOCKAGE_ALGO_ERROR_FAULT*/
   #if (ENABLE_BLOCKAGE_ALGO_ERROR_FAULT_PLT)
      #if (PRECONDITION_ENABLE_BLOCKAGE_ALGO_ERROR_FAULT_PLT)
extern Std_ReturnType Blockage_Algo_Fault_Precondition_Check(void);
      #endif
   #endif
/* Preconditions for DAMPING_ALGO_ERROR_FAULT*/
   #if (ENABLE_DAMPING_ALGO_ERROR_FAULT_PLT)
      #if (PRECONDITION_ENABLE_DAMPING_ALGO_ERROR_FAULT_PLT)
extern Std_ReturnType Damping_Algo_Fault_Precondition_Check(void);
      #endif
   #endif
/* Preconditions for SLL_MONITORING_ALGO_ERROR_FAULT*/
   #if (ENABLE_SLL_MONITORING_ALGO_ERROR_PLT)
      #if (PRECONDITION_ENABLE_SLL_MONITORING_ALGO_ERROR_FAULT_PLT)
extern Std_ReturnType Sll_Monitoring_Algo_Error_Precondition_Check(void);
      #endif
   #endif
/* Preconditions for MMIC_HWA_STARTUP_FAULT*/
   #if (ENABLE_MMIC_HWA_STARTUP_FAULT_PLT)
      #if (PRECONDITION_ENABLE_MMIC_HWA_STARTUP_FAULT_PLT)
extern Std_ReturnType mmic_hwa_startup_fault_Precondition_Check(void);
      #endif
   #endif
/* Preconditions for M7_TO_BBE_CRC_FAULT*/
   #if (ENABLE_M7_TO_BBE_CRC_FAULT_PLT)
      #if (PRECONDITION_ENABLE_M7_TO_BBE_CRC_FAULT_PLT)
extern Std_ReturnType M7_To_BBE_CRC_Fault_Precondition_Check(void);
      #endif
   #endif

/* Preconditions for BBE_TO_M7_CRC_FAULT*/
   #if (ENABLE_BBE_TO_M7_CRC_FAULT_PLT)
      #if (PRECONDITION_ENABLE_BBE_TO_M7_CRC_FAULT_PLT)
extern Std_ReturnType BBE_To_M7_CRC_Fault_Precondition_Check(void);
      #endif
   #endif

/* Preconditions for BBE_TO_A53_CRC_FAULT*/
   #if (ENABLE_BBE_TO_A53_CRC_FAULT_PLT)
      #if (PRECONDITION_ENABLE_BBE_TO_A53_CRC_FAULT_PLT)
extern Std_ReturnType BBE_To_A53_CRC_Fault_Precondition_Check(void);
      #endif
   #endif
/* Preconditions for A53_TO_M7_CRC_FAULT*/
   #if (ENABLE_A53_TO_M7_CRC_FAULT_PLT)
      #if (PRECONDITION_ENABLE_A53_TO_M7_CRC_FAULT_PLT)
extern Std_ReturnType A53_To_M7_CRC_Fault_Precondition_Check(void);
      #endif
   #endif

/* Preconditions for BBE_TO_R52_CRC_FAULT*/
   #if (ENABLE_BBE_TO_R52_CRC_FAULT_PLT)
      #if (PRECONDITION_ENABLE_BBE_TO_R52_CRC_FAULT_PLT)
extern Std_ReturnType BBE_To_R52_CRC_Fault_Precondition_Check(void);
      #endif
   #endif

   /* Preconditions for R52_TO_BBE_CRC_FAULT*/
   #if (ENABLE_R52_TO_BBE_CRC_FAULT_PLT)
      #if (PRECONDITION_ENABLE_R52_TO_BBE_CRC_FAULT_PLT)
extern Std_ReturnType R52_To_BBE_CRC_Fault_Precondition_Check(void);
      #endif
   #endif

/* Preconditions for MMIC_HWA_STARTUP_FAULT*/
   #if (ENABLE_SAFE_STARTUP_HWA_FAULT_PLT)
      #if (PRECONDITION_ENABLE_SAFE_STARTUP_HWA_FAULT_PLT)
extern Std_ReturnType Safe_Startup_HWA_Fault_precondition_check(void);
      #endif
   #endif
   /* Preconditions for RFE_FREQUENCY_MONITOR_FAULT*/
   #if (ENABLE_RFE_FREQUENCY_MONITOR_FAULT_PLT)
      #if (PRECONDITION_ENABLE_RFE_FREQUENCY_MONITOR_FAULT_PLT)
extern Std_ReturnType RFE_Frequency_Monitor_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for RFE_UNDER_OVER_VOLTAGE_FAULT*/
   #if (ENABLE_RFE_UNDER_OVER_VOLTAGE_FAULT_PLT)
      #if (PRECONDITION_ENABLE_RFE_UNDER_OVER_VOLTAGE_FAULT_PLT)
extern Std_ReturnType RFE_Under_Over_Fault_Voltage_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for RFE_POWER_LEVEL_DETECTOR_FAULT*/
   #if (ENABLE_RFE_POWER_LEVEL_DETECTOR_FAULT_PLT)
      #if (PRECONDITION_ENABLE_RFE_POWER_LEVEL_DETECTOR_FAULT_PLT)
Std_ReturnType RFE_Power_Level_Detector_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for RFE_LOCK_STEP_FAULT*/
   #if (ENABLE_RFE_LOCK_STEP_FAULT_PLT)
      #if (PRECONDITION_ENABLE_RFE_LOCK_STEP_FAULT_PLT)
Std_ReturnType RFE_Lock_Step_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for RFE_CPU_FAULT*/
   #if (ENABLE_RFE_CPU_FAULT_PLT)
      #if (PRECONDITION_ENABLE_RFE_CPU_FAULT_PLT)
Std_ReturnType RFE_Cpu_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for RFE_RX_RFBIST_FAULT*/
   #if (ENABLE_RFE_RX_RFBIST_FAULT_PLT)
      #if (PRECONDITION_ENABLE_RFE_RX_RFBIST_FAULT_PLT)
Std_ReturnType RFE_Rx_Rfbist_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for RFE_TX_RFBIST_FAULT*/
   #if (ENABLE_RFE_TX_RFBIST_FAULT_PLT)
      #if (TRUE == PRECONDITION_ENABLE_RFE_TX_RFBIST_FAULT_PLT)
Std_ReturnType RFE_Tx_Rfbist_Fault_Precondition_Check(void);
      #endif
   #endif
   /* Preconditions for CORE_SELF_TEST_FAULT*/
   #if (ENABLE_CORE_SELF_TEST_FAULT_PLT)
      #if (TRUE == PRECONDITION_ENABLE_CORE_SELF_TEST_FAULT_PLT)
Std_ReturnType Core_Self_Test_Fault_Precondition_Check(void);
      #endif
   #endif
/* Preconditions for API_LOOK_CONFIG_FAULT*/
   #if (ENABLE_API_LOOK_CONFIG_FAULT_PLT)
      #if (TRUE == PRECONDITION_ENABLE_API_LOOK_CONFIG_FAULT_PLT)
Std_ReturnType API_Look_Config_Fault_Precondition_Check(void);
      #endif
   #endif

/* Preconditions for API_LOOK_TRIGGER_FAULT*/
   #if (ENABLE_API_LOOK_TRIGGER_FAULT_PLT)
      #if (TRUE == PRECONDITION_ENABLE_API_LOOK_TRIGGER_FAULT_PLT)
Std_ReturnType API_Look_Trigger_Fault_Precondition_Check(void);
      #endif
   #endif

/* Preconditions for API_LOOK_COMPLETE_FAULT*/
   #if (ENABLE_API_LOOK_COMPLETE_FAULT_PLT)
      #if (TRUE == PRECONDITION_ENABLE_API_LOOK_COMPLETE_FAULT_PLT)
Std_ReturnType API_Look_Complete_Fault_Precondition_Check(void);
      #endif
   #endif

/* Preconditions for AUTOALIGNMENT_CRITICAL_MISALIGNMENT_ERROR_FAULT*/
   #if (ENBALE_AUTOALIGNMENT_CRITICAL_MISALIGNMENT_ERROR_FAULT_PLT)
      #if (PRECONDITION_AUTOALIGNMENT_CRITICAL_MISALIGNMENT_ERROR_FAULT_PLT)
extern Std_ReturnType Autoalignment_Critical_Misalignment_Error_Fault_Test_Precondition_Check(void);
      #endif
   #endif
#endif /* End of VALIDATION_DIAG_CUSTOMER_H */
/************************************************************************************************************************************
 *  Revision History
 *
 *   Date        SCR			Name             Description
 *   ----        ----		  ----------- ---------------------------------------------------------------------------------------
 * 09-SEP-2019   CPT-93		Prince     	    Updated the module SWC_PLT_Appl_Validation_Diag according to APTIV C CODING GUIDELINES .
 * 13-DEC-2019   CPT-132	   Prince	       Dolphin Fault Implementation.
 * 28-APR-2020   CPT-286	   Prince	       Fault Manager as per Platform PDD Part-1.
 * 29-JUN-2020   CPT-309	   Prince	       TemperatureSupervision as per mode manager PDD
 * 29-MAR-2022   EEG-891	   Sristi 	       Bring FLR4p IPC fault implementation to Platform building block
 * *************************************************************************************************************************************************/
