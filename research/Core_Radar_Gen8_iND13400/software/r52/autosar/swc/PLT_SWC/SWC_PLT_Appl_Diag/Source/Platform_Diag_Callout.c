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
 *  Module Name:  Platform_Diag_Callout.c
 *
 *  Description:
 *    This file contains the preconditions for platform faults, by which setting or clearing of fault can be disabled..
 *
 *
 **************************************************************************/

/**************************************************************************
 * #Include files
 *************************************************************************/
#include "Platform_Diag_Callout.h"
#include "Rte_SWC_PLT_Appl_Diag.h"
#include "SWC_PLT_Appl_Diag.h"

/**********************************************************************************************************************\
 *  File Scope Variables
\**********************************************************************************************************************/
/*Vehicle supply voltage status flag*/

static uint8 Supply_Voltage_Sts = CODED_FALSE;

/*Radar Radiating Stable�flag*/
#if 0
static uint8 Radar_Radiating_Stable_Sts = CODED_FALSE;
#endif
/*====================================================================================================================*\
* FUNCTION: Mirror_Ram_Integrity_Check_Fault_Check
*=======================================================================================================================
* RETURN VALUE: uint8
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Mirror Ram Integrity Check Fault check
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if (TRUE == ENABLE_MIRROR_RAM_INTEGRITY_CHECK_FAULT_PLT)
uint8 Mirror_Ram_Integrity_Check_Fault_Check(void)
{
   uint8 integrity_check_alignment_status;
   uint8 integrity_check_dataset_status;
   uint8 ret_val = DIAG_TEST_NOT_COMPLETED;
   /* Read integrity alignment status */
   (void)Rte_Read_Rp_Intigrity_Status_Dt_Intigrity_Status_T(&integrity_check_alignment_status);
   /*Read integrity fault status from dataset*/
   (void)Rte_Read_Rp_Intigrity_Status_DataSet_Intigrity_Status_DataSet(&integrity_check_dataset_status);
   /* Checking for the dolphin Transmitter_ID_Fault in IPC structure */
   if ((CODED_TRUE == integrity_check_alignment_status) || (CODED_TRUE == integrity_check_dataset_status))
   {
      ret_val = DIAG_TEST_FAIL;
   }
   else if ((CODED_FALSE == integrity_check_alignment_status) && (CODED_FALSE == integrity_check_dataset_status))
   {
      ret_val = DIAG_TEST_PASS;
   }
   else
   {
      /* No action to perform */
   }
   return ret_val;
}
#endif

/*====================================================================================================================*\
* FUNCTION: Feature_Function_Calibration_Checksum_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for FEATURE_FUNCTION_CALIBRATION_CHECKSUM_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_FEATURE_FUNCTION_CALIBRATION_CHECKSUM_FAULT_PLT) &&                                                          \
     (TRUE == PRECONDITION_ENABLE_FEATURE_FUNCTION_CALIBRATION_CHECKSUM_FAULT_PLT))
Std_ReturnType Feature_Function_Calibration_Checksum_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: Mirror_Ram_Integrity_Check_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MIRROR_RAM_INTEGRITY_CHECK_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MIRROR_RAM_INTEGRITY_CHECK_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MIRROR_RAM_INTEGRITY_CHECK_FAULT_PLT))
Std_ReturnType Mirror_Ram_Integrity_Check_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: Application_Flash_Checksum_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for HOST_APPLICATION_FLASH_CHECKSUM_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_APPLICATION_FLASH_CHECKSUM_FAULT_PLT) &&                                                                     \
     (TRUE == PRECONDITION_ENABLE_HOST_APPLICATION_FLASH_CHECKSUM_FAULT_PLT))
Std_ReturnType Application_Flash_Checksum_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: Smc_Validation_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for SMC_VALIDTN_FLT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_SMC_VALIDATION_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_SMC_VALIDATION_FAULT_PLT))
Std_ReturnType Smc_Validation_Fault_Test_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: Usc_Validation_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for USC_VALIDATION_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_USC_VALIDATION_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_USC_VALIDATION_FAULT_PLT))
Std_ReturnType Usc_Validation_Fault_Test_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: USC_MMIC_A_Unprogrammed_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for USC_MMIC_A_Unprogrammed_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_USC_MMIC_A_UNPROGRAMMED_FAULT_PLT) && (TRUE == PRECONDITION_USC_MMIC_A_UNPROGRAMMED_FAULT_PLT))
Std_ReturnType USC_MMIC_A_Unprogrammed_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: MMIC_Error_Recovery_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MMIC_Error_Recovery_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_ERROR_RECOVERY_FAILURE_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_ERROR_RECOVERY_FAILURE_FAULT_PLT))
Std_ReturnType MMIC_Error_Recovery_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: MMIC_Secondary_Clock_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MMIC_Secondary_Clock_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_SECONDARY_CLOCK_FAULT_PLT) && (TRUE == PRECONDITION_MMIC_SECONDARY_CLOCK_FAULT_PLT))
Std_ReturnType MMIC_Secondary_Clock_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: MMIC_Secondary_MIPI_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MMIC_Secondary_MIPI_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_SECONDARY_MIPI_FAULT_PLT) && (TRUE == PRECONDITION_MMIC_SECONDARY_MIPI_FAULT_PLT))
Std_ReturnType MMIC_Secondary_MIPI_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: MMIC_Secondary_Register_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MMIC_Secondary_Register_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_SECONDARY_REGISTER_FAULT_PLT) && (TRUE == PRECONDITION_MMIC_SECONDARY_REGISTER_FAULT_PLT))
Std_ReturnType MMIC_Secondary_Register_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: MMIC_Secondary_MCU_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MMIC_Secondary_MCU_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_SECONDARY_MCU_FAULT_PLT) && (TRUE == PRECONDITION_MMIC_SECONDARY_MCU_FAULT_PLT))
Std_ReturnType MMIC_Secondary_MCU_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: MMIC_Secondary_BallBreak_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MMIC_Secondary_BallBreak_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_SECONDARY_BALLBREAK_FAULT_PLT) && (TRUE == PRECONDITION_MMIC_SECONDARY_BALLBREAK_FAULT_PLT))
Std_ReturnType MMIC_Secondary_BallBreak_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: Core2_Calibration_Checksum_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for CORE2_CALIBRATION_FLASH_CHECKSUM_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_CORE2_CALIBRATION_FLASH_CHECKSUM_FAULT_PLT) &&                                                               \
     (TRUE == PRECONDITION_ENABLE_CORE2_CALIBRATION_FLASH_CHECKSUM_FAULT_PLT))
Std_ReturnType Core2_Calibration_Checksum_Fault_Test_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: Stack_Overflow_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for STACK_OVERFLOW_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_STACK_OVERFLOW_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_STACK_OVERFLOW_FAULT_PLT))
Std_ReturnType Stack_Overflow_Test_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: Blockage_Algo_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for Blockage_Algo_Fault_Precondition_Check.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_BLOCKAGE_ALGO_ERROR_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_BLOCKAGE_ALGO_ERROR_FAULT_PLT))
Std_ReturnType Blockage_Algo_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: Damping_Algo_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for Damping_Algo_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_DAMPING_ALGO_ERROR_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_DAMPING_ALGO_ERROR_FAULT_PLT))
Std_ReturnType Damping_Algo_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: Sll_Monitoring_Algo_Error_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for SIDELOBE_BLOCKAGE_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_SLL_MONITORING_ALGO_ERROR_PLT) && (TRUE == PRECONDITION_ENABLE_SLL_MONITORING_ALGO_ERROR_FAULT_PLT))
Std_ReturnType Sll_Monitoring_Algo_Error_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: safe_startup_hwa_fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for safe_startup_hwa_fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_SAFE_STARTUP_HWA_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_SAFE_STARTUP_HWA_FAULT_PLT))
Std_ReturnType safe_startup_hwa_fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: range_check_fault_precondition_check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for range_check_fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_RANGE_ESTIMATION_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_RANGE_ESTIMATION_FAULT_PLT))
Std_ReturnType range_check_fault_precondition_check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: MMIC_Temp_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for DOLPHIN_TEMP_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_TEMPERATURE_LOW_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_TEMPERATURE_LOW_FAULT_PLT))
Std_ReturnType MMIC_Temperature_Low_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: MMIC_Temp_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MMIC_TEMP_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_TEMPERATURE_HIGH_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_TEMPERATURE_HIGH_FAULT_PLT))
Std_ReturnType MMIC_Temp_high_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif
/*====================================================================================================================*\
* FUNCTION: Dolphin_Spi_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for DOLPHIN_SPI_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_A_SPI_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_A_SPI_FAULT_PLT))
Std_ReturnType Dolphin_Spi_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif
/*====================================================================================================================*\
* FUNCTION: Chirp_Pll_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for CHIRP_PLL_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_CHIRP_PLL_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_CHIRP_PLL_FAULT_PLT))
Std_ReturnType Chirp_Pll_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif
/*====================================================================================================================*\
* FUNCTION: Rf_Ball_Break_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for RF_BALL_BREAK_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_RF_BALL_BREAK_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_RF_BALL_BREAK_FAULT_PLT))
Std_ReturnType Rf_Ball_Break_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: Aquisition_Overflow_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for ACQUISITION_OVERFLOW_FAULT_PLT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_ACQUISITION_OVERFLOW_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_ACQUISITION_OVERFLOW_FAULT_PLT))
Std_ReturnType Aquisition_Overflow_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: pmic_mcu_communication_fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for PMIC_MCU_COMMUNICATION_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_PMIC_MCU_COMMUNICATION_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_PMIC_MCU_COMMUNICATION_FAULT_PLT))
Std_ReturnType pmic_mcu_communication_fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: MMIC_Loop_Back_Test_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MMIC_LOOP_BACK_TEST_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_LOOP_BACK_TEST_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_LOOP_BACK_TEST_FAULT_PLT))
Std_ReturnType MMIC_Loop_Back_test_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: MMIC_Functional_Configuration_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MMIC_Functional_Configuration_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_FUNCTIONAL_CONFIGURATION_FAULT_PLT) &&                                                                  \
     (TRUE == PRECONDITION_ENABLE_MMIC_FUNCTIONAL_CONFIGURATION_FAULT_PLT))
Std_ReturnType MMIC_Functional_Configuration_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: RFE_Frequency_Monitor_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for RFE_FREQUENCY_MONITOR_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_RFE_FREQUENCY_MONITOR_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_RFE_FREQUENCY_MONITOR_FAULT_PLT))
Std_ReturnType RFE_Frequency_Monitor_Fault_Precondition_Check(void)
{
   return E_NOT_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: RFE_Under_Over_Voltage_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for RFE_UNDER_OVER_VOLTAGE_FAULT_PLT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_RFE_UNDER_OVER_VOLTAGE_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_RFE_UNDER_OVER_VOLTAGE_FAULT_PLT))
Std_ReturnType RFE_Under_Over_Fault_Voltage_Precondition_Check(void)
{
   return E_NOT_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: RFE_Power_Level_Detector_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for RFE_POWER_LEVEL_DETECTOR_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_RFE_POWER_LEVEL_DETECTOR_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_RFE_POWER_LEVEL_DETECTOR_FAULT_PLT))
Std_ReturnType RFE_Power_Level_Detector_Fault_Precondition_Check(void)
{
   return E_NOT_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: RFE_Lock_Step_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for RFE_LOCK_STEP_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_RFE_LOCK_STEP_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_RFE_LOCK_STEP_FAULT_PLT))
Std_ReturnType RFE_Lock_Step_Fault_Precondition_Check(void)
{
   return E_NOT_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: RFE_Cpu_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for RFE_LOCK_STEP_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_RFE_CPU_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_RFE_CPU_FAULT_PLT))
Std_ReturnType RFE_Cpu_Fault_Precondition_Check(void)
{
   return E_NOT_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: RFE_Rx_Rfbist_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for RFE_RX_RFBIST_FAULT_PLT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_RFE_RX_RFBIST_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_RFE_RX_RFBIST_FAULT_PLT))
Std_ReturnType RFE_Rx_Rfbist_Fault_Precondition_Check(void)
{
   return E_NOT_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: RFE_Tx_Rfbist_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for RFE_TX_RFBIST_FAULT_PLT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_RFE_TX_RFBIST_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_RFE_TX_RFBIST_FAULT_PLT))
Std_ReturnType RFE_Tx_Rfbist_Fault_Precondition_Check(void)
{
   return E_NOT_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: Transmitter_Id_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for TRANSMITTER_ID_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_A_TRANSMITTER_ID_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_A_TRANSMITTER_ID_FAULT_PLT))
Std_ReturnType Transmitter_Id_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif
/*====================================================================================================================*\
* FUNCTION: MMIC_Safe_Start_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MMIC_SAFE_START_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_A_SAFE_START_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_A_SAFE_START_FAULT_PLT))
Std_ReturnType MMIC_Safe_Start_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif
/*====================================================================================================================*\
* FUNCTION: M7_To_BBE_CRC_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for M7_TO_BBE_CRC_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_M7_TO_BBE_CRC_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_M7_TO_BBE_CRC_FAULT_PLT))
Std_ReturnType M7_To_BBE_CRC_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: BBE_To_M7_CRC_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for BBE_TO_M7_CRC_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_BBE_TO_M7_CRC_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_BBE_TO_M7_CRC_FAULT_PLT))
Std_ReturnType BBE_To_M7_CRC_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: BBE_To_A53_CRC_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for BBE_TO_A53_CRC_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_BBE_TO_A53_CRC_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_BBE_TO_A53_CRC_FAULT_PLT))
Std_ReturnType BBE_To_A53_CRC_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: A53_To_M7_CRC_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for A53_TO_M7_CRC_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_A53_TO_M7_CRC_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_A53_TO_M7_CRC_FAULT_PLT))
Std_ReturnType A53_To_M7_CRC_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif
/*====================================================================================================================*\
* FUNCTION: BBE_To_R52_CRC_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for BBE_TO_R52_CRC_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_BBE_TO_R52_CRC_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_BBE_TO_R52_CRC_FAULT_PLT))
Std_ReturnType BBE_To_R52_CRC_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: R52_To_BBE_CRC_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for BBE_TO_R52_CRC_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_R52_TO_BBE_CRC_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_R52_TO_BBE_CRC_FAULT_PLT))
Std_ReturnType R52_To_BBE_CRC_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif
/*====================================================================================================================*\
* FUNCTION: External_Wdg_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for EXTERNAL_WDG_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_EXTERNAL_WDG_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_EXTERNAL_WDG_FAULT_PLT))
Std_ReturnType External_Wdg_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif
/*====================================================================================================================*\
* FUNCTION: Can_Controller_Ram_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for CAN_CONTROLLER_RAM_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_CAN_CONTROLLER_RAM_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_CAN_CONTROLLER_RAM_FAULT_PLT))
Std_ReturnType Can_Controller_Ram_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: Microprocessor_Temp_High_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MICROPROCESSOR_TEMP_HIGH_FAULT_PLT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MICROPROCESSOR_TEMP_HIGH_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MICROPROCESSOR_TEMP_HIGH_FAULT_PLT))
Std_ReturnType Microprocessor_Temp_High_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if ((CODED_TRUE == Supply_Voltage_Sts) && (Platform_Check_Fault_If_Enabled(MICROPROCESSOR_TEMP_HIGH_FAULT) != FALSE))
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: Microprocessor_Temp_Low_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MICROPROCESSOR_TEMP_LOW_FAULT_PLT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MICROPROCESSOR_TEMP_LOW_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MICROPROCESSOR_TEMP_LOW_FAULT_PLT))
Std_ReturnType Microprocessor_Temp_Low_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif
/*====================================================================================================================*\
* FUNCTION: Signal_Integrity_FAULT_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for SIGNAL_INTEGRITY_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_SIGNAL_INTEGRITY_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_SIGNAL_INTEGRITY_FAULT_PLT))
Std_ReturnType Signal_Integrity_FAULT_Precondition_Check(void)
{
   return E_OK;
}
#endif
/*====================================================================================================================*\
* FUNCTION: MNR_Radar_Blockage_Detected_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MNR_BLOCKAGE FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MNR_BLOCKAGE_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MNR_BLOCKAGE_FAULT_PLT))
Std_ReturnType MNR_Radar_Blockage_Detected_Fault_Test_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: Battery_High_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for BATTERY_HIGH_FAULT .
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_BATTERY_HIGH_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_BATTERY_HIGH_FAULT_PLT))
Std_ReturnType Battery_High_Fault_Test_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: Battery_Low_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for BATTERY_LOW_FAULT .
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_BATTERY_LOW_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_BATTERY_LOW_FAULT_PLT))
Std_ReturnType Battery_Low_Fault_Test_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: Dolphin_Dafety_Integtrity_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for DOLPHIN_SAFETY_INTEGTRITY_CHECK_FAULT .
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_SAFETY_INTEGTRITY_CHECK_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_SAFETY_INTEGTRITY_CHECK_FAULT_PLT))
Std_ReturnType safety_Integtrity_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: Dolphin_Densor_Dead_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for DOLPHIN_SENSOR_DEAD_FAULT .
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_A_SENSOR_DEAD_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_A_SENSOR_DEAD_FAULT_PLT))
Std_ReturnType Dolphin_Densor_Dead_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif
/*====================================================================================================================*\
* FUNCTION: Thermistor_Out_Of_Range_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for THERMISTOR_OUT_OF_RANGE_FAULT_PLT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_THERMISTOR_OUT_OF_RANGE_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_THERMISTOR_OUT_OF_RANGE_FAULT_PLT))
Std_ReturnType Thermistor_Out_Of_Range_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts && (Platform_Check_Fault_If_Enabled(THERMISTOR_OUT_OF_RANGE_FAULT) != FALSE))
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: MMIC_TX0_Ball_Break_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MMIC_TX0_BALL_BREAK_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_TX0_BALL_BREAK_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_TX0_BALL_BREAK_FAULT_PLT))
Std_ReturnType MMIC_TX0_Ball_Break_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif
/*====================================================================================================================*\
* FUNCTION: MMIC_Tx1_Ball_Break_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MMIC_TX1_BALL_BREAK_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_TX1_BALL_BREAK_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_TX1_BALL_BREAK_FAULT_PLT))
Std_ReturnType MMIC_Tx1_Ball_Break_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif
/*====================================================================================================================*\
* FUNCTION: MMIC_Tx2_Ball_Break_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MMIC_TX2_BALL_BREAK_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_TX2_BALL_BREAK_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_TX2_BALL_BREAK_FAULT_PLT))
Std_ReturnType MMIC_Tx2_Ball_Break_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif
/*====================================================================================================================*\
* FUNCTION: MMIC_Tx3_Ball_Break_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MMIC_TX3_BALL_BREAK_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MMIC_TX3_BALL_BREAK_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MMIC_TX3_BALL_BREAK_FAULT_PLT))
Std_ReturnType MMIC_Tx3_Ball_Break_Fault_Precondition_Check(void)
{
   /*Supply voltage precondition check*/
   if (CODED_TRUE == Supply_Voltage_Sts)
   {
      return E_OK;
   }
   else
   {
      return E_NOT_OK;
   }
}
#endif

/*====================================================================================================================*\
* FUNCTION: MCU_Startup_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MCU_STARTUP_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MCU_STARTUP_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MCU_STARTUP_FAULT_PLT))
Std_ReturnType MCU_Startup_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: MCU_Repetitive_Reset_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for MCU_REPETITIVE_RESET_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_MCU_REPETITIVE_RESET_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_MCU_REPETITIVE_RESET_FAULT_PLT))
Std_ReturnType MCU_Repetitive_Reset_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif
/*====================================================================================================================*\
* FUNCTION: RFE_Repetitive_Reset_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for RFE_REPETITIVE_RESET_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_RFE_REPETITIVE_RESET_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_RFE_REPETITIVE_RESET_FAULT_PLT))
Std_ReturnType RFE_Repetitive_Reset_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif
/*====================================================================================================================*\
* FUNCTION: Platform_time_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for PLATFORM_TIME_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

#if ((TRUE == ENABLE_PLATFORM_TIME_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_PLATFORM_TIME_FAULT_PLT))
Std_ReturnType Platform_time_Fault_Test_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: Alignment_No_Initial_Calibration_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for Alignment_No_Initial_Calibration_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

#if ((TRUE == ENABLE_ALIGNMENT_NO_INITIAL_CALIBRATION_FAULT_PLT) &&                                                               \
     (TRUE == PRECONDITION_ENABLE_ALIGNMENT_NO_INITIAL_CALIBRATION_FAULT_PLT))
Std_ReturnType Alignment_No_Initial_Calibration_Fault_Test_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: Alignment_Static_Calibration_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for Alignment_Static_Calibration_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

#if ((TRUE == ENABLE_ALIGNMENT_STATIC_CALIBRATION_FAULT_PLT) &&                                                                   \
     (TRUE == PRECONDITION_ENABLE_ALIGNMENT_STATIC_CALIBRATION_FAULT_PLT))
Std_ReturnType Alignment_Static_Calibration_Fault_Test_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: Alignment_Service_Calibration_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for Alignment_Service_Calibration_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

#if ((TRUE == ENABLE_ALIGNMENT_SERVICE_CALIBRATION_FAULT_PLT) &&                                                                  \
     (TRUE == PRECONDITION_ENABLE_ALIGNMENT_SERVICE_CALIBRATION_FAULT_PLT))
Std_ReturnType Alignment_Service_Calibration_Fault_Test_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: Alignment_ShortTrack_Calibration_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for Alignment_ShortTrack_Calibration_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

#if ((TRUE == ENABLE_ALIGNMENT_SHORTTRACK_CALIBRATION_FAULT_PLT) &&                                                               \
     (TRUE == PRECONDITION_ENABLE_ALIGNMENT_SHORTTRACK_CALIBRATION_FAULT_PLT))
Std_ReturnType Alignment_ShortTrack_Calibration_Fault_Test_Precondition_Check(void)
{
   return E_OK;
}
#endif
/*====================================================================================================================*\
* FUNCTION: Alignment_Autoalign_outof_range_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for Alignment_Autoalign_outof_range_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

#if ((TRUE == ENABLE_ALIGNMENT_AUTOALIGN_OUTOF_RANGE_FAULT_PLT) &&                                                                \
     (TRUE == PRECONDITION_ENABLE_ALIGNMENT_AUTOALIGN_OUTOF_RANGE_FAULT_PLT))
Std_ReturnType Alignment_Autoalign_outof_range_Fault_Test_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: Safe_Startup_HWA_Fault_precondition_check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for Alignment_Autoalign_outof_range_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_SAFE_STARTUP_HWA_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_SAFE_STARTUP_HWA_FAULT_PLT))
Std_ReturnType Safe_Startup_HWA_Fault_precondition_check(void)
{
   return E_OK;
}
#endif
/*====================================================================================================================*\
* FUNCTION: Alignment_Autoalign_Algo_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for AUTOALIGNMENT_ALGO_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

#if ((TRUE == ENABLE_ALIGNMENT_AUTOALIGN_ALGO_FAULT_PLT) && (TRUE == PRECONDITION_ALIGNMENT_ENABLE_AUTOALIGN_ALGO_FAULT_PLT))
Std_ReturnType Alignment_Autoalign_Algo_Fault_Test_Precondition_Check(void)
{
   return E_OK;
}
#endif
/*====================================================================================================================*\
* FUNCTION: Core_Self_Test_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for CORE_SELF_TEST_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

#if ((TRUE == ENABLE_CORE_SELF_TEST_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_CORE_SELF_TEST_FAULT_PLT))
Std_ReturnType Core_Self_Test_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: API_Look_Config_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for API_LOOK_CONFIG_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

#if ((TRUE == ENABLE_API_LOOK_CONFIG_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_API_LOOK_CONFIG_FAULT_PLT))
Std_ReturnType API_Look_Config_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: API_Look_Trigger_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for API_LOOK_TRIGGER_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

#if ((TRUE == ENABLE_API_LOOK_TRIGGER_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_API_LOOK_TRIGGER_FAULT_PLT))
Std_ReturnType API_Look_Trigger_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: API_Look_Complete_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for API_LOOK_COMPLETE_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

#if ((TRUE == ENABLE_API_LOOK_COMPLETE_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_API_LOOK_COMPLETE_FAULT_PLT))
Std_ReturnType API_Look_Complete_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif
/*====================================================================================================================*\
* FUNCTION: Alignment_AutoAlignment_Sudden_Jump_Detection_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for AUTOALIGNMENT_ALGO_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

#if ((TRUE == ENBALE_ALIGNMENT_AUTOALIGNMENT_SUDDEN_JUMP_DETECTION_FAULT_PLT) &&                                                  \
     (TRUE == PRECONDITION_ALIGNMENT_AUTOALIGNMENT_SUDDEN_JUMP_DETECTION_FAULT_PLT))
Std_ReturnType Alignment_AutoAlignment_Sudden_Jump_Detection_Fault_Test_Precondition_Check(void)
{
   return E_OK;
}
#endif
/*====================================================================================================================*\
* FUNCTION: Autoalignment_Critical_Misalignment_Error_Fault_Test_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for Autoalignment_Critical_Misalignment_Error_Fault.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

#if ((TRUE == ENBALE_AUTOALIGNMENT_CRITICAL_MISALIGNMENT_ERROR_FAULT_PLT) &&                                                      \
     (TRUE == PRECONDITION_AUTOALIGNMENT_CRITICAL_MISALIGNMENT_ERROR_FAULT_PLT))
Std_ReturnType Autoalignment_Critical_Misalignment_Error_Fault_Test_Precondition_Check(void)
{
   return E_OK;
}
#endif
/*====================================================================================================================*\
* FUNCTION: DETECTION_PROCESSION_LOOP_OVERRUN_FAULT_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for DETECTION_PROCESSION_LOOP_OVERRUN_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_DETECTION_PROCESSION_LOOP_OVERRUN_FAULT_PLT) &&                                                              \
     (TRUE == PRECONDITION_ENABLE_DETECTION_PROCESSION_LOOP_OVERRUN_FAULT_PLT))
Std_ReturnType Detection_Procession_Loop_Overrun_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: DETECTION_DATA_INTEGRITY_FAULT_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for DETECTION_DATA_INTEGRITY_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_DETECTION_DATA_INTEGRITY_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_DETECTION_DATA_INTEGRITY_FAULT_PLT))
Std_ReturnType Detection_Data_Integrity_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: DSP_Internal_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for DSP_INTERNAL_FAULT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
#if ((TRUE == ENABLE_DSP_INTERNAL_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_DSP_INTERNAL_FAULT_PLT))
Std_ReturnType DSP_Internal_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif

/*====================================================================================================================*\
* FUNCTION: Fisrt_Pass_Saturation_Fault_Precondition_Check
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Preconditions for FIRST_PASS_SATURATION_FAULT_PLT.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

#if ((TRUE == ENABLE_FIRST_PASS_SATURATION_FAULT_PLT) && (TRUE == PRECONDITION_ENABLE_FIRST_PASS_SATURATION_FAULT_PLT))
Std_ReturnType Fisrt_Pass_Saturation_Fault_Precondition_Check(void)
{
   return E_OK;
}
#endif
/************************************************************************************************************************************
 *  Revision History
 *
 *   Date        SCR			Name             Description
 *   ----        ----		  ----------- ---------------------------------------------------------------------------------------
 * 09-SEP-2019   CPT-93		Prince     	   Updated the module SWC_PLT_Appl_Validation_Diag according to APTIV C CODING GUIDELINES .
 * 22-NOV-2019   CPT-107    Priyatham      Removed Std_Types.h, NvM.h, timing_function.h header files  that are included.
 * 13-DEC-2019   CPT-132	   Prince	      Dolphin Fault Implementation.
 * 17-JAN-2020   CPT-199	   Prince	      Implement remaining Validation diagnostics - Part 2.
 * 27-JAN-2020   CPT-210	   Prince	      Implement remaining Validation diagnostics - Part 3.
 * 28-APR-2020   CPT-286	   Prince	      Fault Manager as per Platform PDD Part-1.
 * 05-MAY-2020   CPT-289	   Prince	      Fault Manager as per Platform PDD Part-2.
 * 29-JUN-2020   CPT-309	   Prince	      TemperatureSupervision as per mode manager PDD
 * 28-JAN-2021 	CPT-413	   Priyatham	  Implementation of Temperature Supervision in Mode Manager
 * 22-FEB-2021   CPT-415    Ankita Pandey  Implentation of Voltage state machine
 * 08-Nov-2021   EEG-693    Vijayendra        [SW][EMH-236]Implementation of the MNR blockage implementation[SRR6/FLR4/SRR6+]
 * 22-Feb-2022   DNP-2610   Suba           IPC c0_c2_core_T refactoring
 * 29-Mar-2022   EEG-891    Sristi          Bring FLR4p IPC fault implementation to Platform building block
 * *************************************************************************************************************************************************/
