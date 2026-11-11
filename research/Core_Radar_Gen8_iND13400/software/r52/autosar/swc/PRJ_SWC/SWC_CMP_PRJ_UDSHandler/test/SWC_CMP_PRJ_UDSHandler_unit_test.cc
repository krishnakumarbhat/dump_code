/*===========================================================================*/
/**
 * @file SWC_CMP_PRJ_UDSHandler_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for the checking the SWC_CMP_PRJ_UDSHandler.c file
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include <chrono>
#include <gtest/gtest.h>
#include <setjmp.h>
#include <thread>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "Rte_Type.h"
#include "SWC_CMP_PRJ_UDSHandler_fake.h"
#include "fff.h"

extern "C"
{
#include "SWC_CMP_PRJ_UDSHandler.c"

/* ALIGNMENT_SUCCESSFUL is generated per-SWC into Rte_SWC_PLT_Radar_Alignment_Handler_Type.h, which
 * cannot be included in this TU (RTE allows only one application header per TU). */
#ifndef ALIGNMENT_SUCCESSFUL
   #define ALIGNMENT_SUCCESSFUL (4U)
#endif

   /* Global state normally owned by SWC_PLT_Radar_Alignment_Handler; provided here as test state
    * since that SWC is not linked into this unit test binary. */
   Dt_Alignment_Handler AlignmentHandler         = {};
   Dt_AlignmentAuto AlignmentAuto                = {};
   Dt_AlignmentService AlignmentService          = {};
   Dt_AlignmentStatic AlignmentStatic            = {};
   Dt_Alignment_M2D_Data alignment_m2d_data      = {};
   AlignmentInitialCals_T alignment_initial_cals = {};
}

uint16 Pass_Count_Debounce[MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT] = {0};
uint16 Fail_Count_Debounce[MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT] = {0};

/*===========================================================================*
 * Helper: longjmp-based escape for Mcu_Reset fake (avoids while(TRUE) hang)
 *===========================================================================*/
static jmp_buf g_mcu_reset_jmp_buf;

static Std_ReturnType ManualAlignRead_zero(Dt_Manual_Alignment_Execution_Data_CRC *data)
{
   if (data != NULL)
   {
      memset(data, 0, sizeof(*data));
   }
   return RTE_E_OK;
}

static void Mcu_Reset_longjmp_custom(Mcu_reset_T reset_type)
{
   longjmp(g_mcu_reset_jmp_buf, 1);
}

/*===========================================================================*
 * Helper: NvM_GetErrorStatus custom fakes for output-parameter injection
 *===========================================================================*/
static Std_ReturnType NvM_GetErrorStatus_set_pending(NvM_BlockIdType blockId, NvM_RequestResultType *pStatus)
{
   if (NULL != pStatus)
   {
      *pStatus = NVM_REQ_PENDING;
   }
   return RTE_E_OK;
}

static Std_ReturnType NvM_GetErrorStatus_set_ok(NvM_BlockIdType blockId, NvM_RequestResultType *pStatus)
{
   if (NULL != pStatus)
   {
      *pStatus = NVM_REQ_OK;
   }
   return RTE_E_OK;
}

static Std_ReturnType Rte_Read_PhysicalAdcData_set_battery_12_5v(Dt_AdcData_T *data)
{
   if (NULL != data)
   {
      data->Adc_Batt_Volt = 12.5F;
   }
   return RTE_E_OK;
}

static void CS_ReadNvM_Value_set_sensorpos_unlocked(Dt_SensorPosition_Status_T *data)
{
   if (NULL != data)
   {
      memset(data, 0, sizeof(*data));
      data->SensorPos_Value       = SRR_FC;
      data->SensorPos_Lock_Status = SENSOR_POS_UNLOCKED;
   }
}
static void CS_ReadNvM_Value_set_sensorpos_locked(Dt_SensorPosition_Status_T *data)
{
   if (NULL != data)
   {
      memset(data, 0, sizeof(*data));
      data->SensorPos_Value       = SRR_FC;
      data->SensorPos_Lock_Status = SENSOR_POS_LOCKED;
   }
}
static void CS_GetError_Status_set_nvm_ok(NvM_RequestResultType *error_status)
{
   if (NULL != error_status)
   {
      *error_status = NVM_REQ_OK;
   }
}
static void CS_GetError_Status_set_nvm_pending(NvM_RequestResultType *error_status)
{
   if (NULL != error_status)
   {
      *error_status = NVM_REQ_PENDING;
   }
}
static void CS_GetError_Status_set_nvm_not_ok(NvM_RequestResultType *error_status)
{
   if (NULL != error_status)
   {
      *error_status = NVM_REQ_NOT_OK;
   }
}

static Std_ReturnType
   Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable_set_validation_fault(
      uint8_t *data)
{
   if (NULL != data)
   {
      memset(data, 0, sizeof(Platform_fault_T));
      reinterpret_cast<Platform_fault_T *>(data)->Platform_Bits.usc_validation_fault = TRUE;
   }
   return RTE_E_OK;
}
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class SWC_CMP_PRJ_UDSHandler_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      RESET_FAKE(Mcu_Reset);
      RESET_FAKE(NvM_GetErrorStatus);
      RESET_FAKE(NvM_WriteBlock);
      RESET_FAKE(Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_PhysicalAdcData_De_PhysicalAdcData);
      RESET_FAKE(Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable);
      RESET_FAKE(CS_ReadNvM_Value_Operation);
      RESET_FAKE(CS_GetError_Status_Operation);
      RESET_FAKE(Trigger_Write_to_NVM);
      RESET_FAKE(Dcm_GetSesCtrlType);
      RESET_FAKE(Clear_Platform_Fault_Arrays);
      RESET_FAKE(Clear_Cust_Fault_Arrays);
      RESET_FAKE(CS_Control_DTC_Service_Operation);

      RESET_FAKE(
         Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC);
      RESET_FAKE(
         Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC);
      RESET_FAKE(
         Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC);
      Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC_fake
         .custom_fake = ManualAlignRead_zero;

      RESET_FAKE(Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status);
      rid_lock_start_routine_Status                                                = ROUTINE_INIT;
      rid_unlock_start_routine_Status                                              = ROUTINE_INIT;
      UDSReset                                                                     = NONE;
      Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System = 0U;
      Set_Customer_Radar_Position(SRR_FC);
   }

   /**
    * @b Description
    * @n
    *    Method run after each individual test case.
    */
   void TearDown()
   {
   }
};

/*===========================================================================*
 * Test Cases: Perform_SoftReset
 *===========================================================================*/

/* Verify that Perform_SoftReset sets UDSReset to SOFT_RESET */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, Perform_SoftReset_SetsUDSResetToSoftReset)
{
   UDSReset = NONE;

   Perform_SoftReset();

   EXPECT_EQ(UDSReset, SOFT_RESET);
}

/*===========================================================================*
 * Test Cases: Diag_services_fnc_caller
 *===========================================================================*/

/* Branch: default — UDSReset is NONE, Mcu_Reset must NOT be called */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, Diag_services_fnc_caller_DefaultBranch_McuResetNotCalled)
{
   UDSReset = NONE;

   Diag_services_fnc_caller();

   EXPECT_EQ(Mcu_Reset_fake.call_count, 0u);
}

/* Branch: SOFT_RESET, while(TRUE) reached — Mcu_Reset returns normally so execution
 * advances past the call into the safety loop; thread is detached to avoid hanging */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, Diag_services_fnc_caller_SoftReset_WhileLoopReached)
{
   RESET_FAKE(Mcu_Reset);
   Mcu_Reset_fake.custom_fake = Mcu_Reset_longjmp_custom;
   UDSReset                   = SOFT_RESET;

   if (setjmp(g_mcu_reset_jmp_buf) == 0)
   {
      Diag_services_fnc_caller();
      FAIL() << "Diag_services_fnc_caller should not return after triggering the soft reset branch.";
   }

   EXPECT_EQ(Mcu_Reset_fake.call_count, 1u);
   EXPECT_EQ(Mcu_Reset_fake.arg0_val, RESET_SW_INTENTIONAL);
}

/* Branch: SOFT_RESET — Mcu_Reset must be called with RESET_SW_INTENTIONAL */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, Diag_services_fnc_caller_SoftResetBranch_CallsMcuResetWithIntentional)
{
   Mcu_Reset_fake.custom_fake = Mcu_Reset_longjmp_custom;
   UDSReset                   = SOFT_RESET;

   if (setjmp(g_mcu_reset_jmp_buf) == 0)
   {
      Diag_services_fnc_caller();
   }

   EXPECT_EQ(Mcu_Reset_fake.call_count, 1u);
   EXPECT_EQ(Mcu_Reset_fake.arg0_val, RESET_SW_INTENTIONAL);
}

/*===========================================================================*
 * Test Cases
 *===========================================================================*/
/*===========================================================================*
 * Test Cases: DataServices_Data_0xF190_VIN_ConditionCheckRead
 *===========================================================================*/

/* NULL ErrorCode → returns RTE_E_INVALID */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, ConditionCheckRead_NullErrorCode_ReturnsInvalid)
{
   Std_ReturnType ret = DataServices_Data_0xF190_VIN_ConditionCheckRead(DCM_INITIAL, nullptr);

   EXPECT_EQ(ret, RTE_E_INVALID);
}

/* Valid ErrorCode → sets *ErrorCode to positive response, returns RTE_E_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, ConditionCheckRead_ValidErrorCode_SetsPositiveResponseAndReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   Std_ReturnType ret = DataServices_Data_0xF190_VIN_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(err_code, DCM_E_POSITIVERESPONSE);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xF190_VIN_ReadData
 *===========================================================================*/

/* NULL Data pointer → returns RTE_E_INVALID */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, ReadData_NullData_ReturnsInvalid)
{
   Std_ReturnType ret = DataServices_Data_0xF190_VIN_ReadData(DCM_INITIAL, nullptr);

   EXPECT_EQ(ret, RTE_E_INVALID);
}

/* Valid Data pointer → copies VIN and returns RTE_E_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, ReadData_ValidData_CopiesVinAndReturnsOk)
{
   Dcm_DataElement_Data_VIN_Read_ArrayType data[17] = {0};

   Std_ReturnType ret = DataServices_Data_0xF190_VIN_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xF190_VIN_WriteData
 *===========================================================================*/

/* NULL Data → returns E_NOT_OK immediately */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, WriteData_NullData_ReturnsNotOk)
{
   Dcm_NegativeResponseCodeType err_code = 0u;

   Std_ReturnType ret = DataServices_Data_0xF190_VIN_WriteData(nullptr, DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, E_NOT_OK);
}

/* NULL ErrorCode (valid Data) → returns E_NOT_OK immediately */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, WriteData_NullErrorCode_ReturnsNotOk)
{
   Dcm_DataElement_Data_VIN_Read_ArrayType data[17] = {0};

   Std_ReturnType ret = DataServices_Data_0xF190_VIN_WriteData(data, DCM_INITIAL, nullptr);

   EXPECT_EQ(ret, E_NOT_OK);
}

/* DCM_INITIAL, NVM_REQ_PENDING → returns DCM_E_PENDING with RCRRP error code */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, WriteData_Initial_NvmPending_ReturnsPending)
{
   Dcm_DataElement_Data_VIN_Read_ArrayType data[17] = {0};
   Dcm_NegativeResponseCodeType err_code            = 0u;
   NvM_GetErrorStatus_fake.custom_fake              = NvM_GetErrorStatus_set_pending;

   Std_ReturnType ret = DataServices_Data_0xF190_VIN_WriteData(data, DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, DCM_E_PENDING);
   EXPECT_EQ(err_code, DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING);
}

/* DCM_INITIAL, not pending, WriteBlock succeeds → returns DCM_E_PENDING */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, WriteData_Initial_NotPending_WriteBlockOk_ReturnsPending)
{
   Dcm_DataElement_Data_VIN_Read_ArrayType data[17] = {0};
   Dcm_NegativeResponseCodeType err_code            = 0u;
   NvM_WriteBlock_fake.return_val                   = RTE_E_OK;

   Std_ReturnType ret = DataServices_Data_0xF190_VIN_WriteData(data, DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, DCM_E_PENDING);
   EXPECT_EQ(err_code, DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING);
}

/* DCM_INITIAL, not pending, WriteBlock fails → returns E_NOT_OK with programming failure */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, WriteData_Initial_NotPending_WriteBlockFails_ReturnsNotOk)
{
   Dcm_DataElement_Data_VIN_Read_ArrayType data[17] = {0};
   Dcm_NegativeResponseCodeType err_code            = 0u;
   NvM_WriteBlock_fake.return_val                   = E_NOT_OK;

   Std_ReturnType ret = DataServices_Data_0xF190_VIN_WriteData(data, DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, E_NOT_OK);
   EXPECT_EQ(err_code, DCM_E_GENERALPROGRAMMINGFAILURE);
}

/* DCM_PENDING, NVM_REQ_PENDING → returns DCM_E_PENDING */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, WriteData_Pending_NvmPending_ReturnsPending)
{
   Dcm_DataElement_Data_VIN_Read_ArrayType data[17] = {0};
   Dcm_NegativeResponseCodeType err_code            = 0u;
   NvM_GetErrorStatus_fake.custom_fake              = NvM_GetErrorStatus_set_pending;

   Std_ReturnType ret = DataServices_Data_0xF190_VIN_WriteData(data, DCM_PENDING, &err_code);

   EXPECT_EQ(ret, DCM_E_PENDING);
   EXPECT_EQ(err_code, DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING);
}

/* DCM_PENDING, NVM_REQ_OK → returns E_OK with positive response */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, WriteData_Pending_NvmOk_ReturnsOk)
{
   Dcm_DataElement_Data_VIN_Read_ArrayType data[17] = {0};
   Dcm_NegativeResponseCodeType err_code            = 0u;
   NvM_GetErrorStatus_fake.custom_fake              = NvM_GetErrorStatus_set_ok;

   Std_ReturnType ret = DataServices_Data_0xF190_VIN_WriteData(data, DCM_PENDING, &err_code);

   EXPECT_EQ(ret, E_OK);
   EXPECT_EQ(err_code, DCM_E_POSITIVERESPONSE);
}

/* DCM_PENDING, NVM_REQ_NOT_OK (neither pending nor OK) → returns E_NOT_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, WriteData_Pending_NvmNotOk_ReturnsNotOk)
{
   Dcm_DataElement_Data_VIN_Read_ArrayType data[17] = {0};
   Dcm_NegativeResponseCodeType err_code            = 0u;

   Std_ReturnType ret = DataServices_Data_0xF190_VIN_WriteData(data, DCM_PENDING, &err_code);

   EXPECT_EQ(ret, E_NOT_OK);
   EXPECT_EQ(err_code, DCM_E_GENERALPROGRAMMINGFAILURE);
}

/* DCM_CANCEL → returns E_NOT_OK with programming failure */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, WriteData_Cancel_ReturnsNotOk)
{
   Dcm_DataElement_Data_VIN_Read_ArrayType data[17] = {0};
   Dcm_NegativeResponseCodeType err_code            = 0u;

   Std_ReturnType ret = DataServices_Data_0xF190_VIN_WriteData(data, DCM_CANCEL, &err_code);

   EXPECT_EQ(ret, E_NOT_OK);
   EXPECT_EQ(err_code, DCM_E_GENERALPROGRAMMINGFAILURE);
}

/*===========================================================================*
 * Test Cases: RE_SWC_CMP_PRJ_UDSHandler_Main_50ms
 *===========================================================================*/

/* Verify that the 50ms runnable can be called without fault (empty body) */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, Main50ms_CanBeCalledWithoutFault)
{
   RE_SWC_CMP_PRJ_UDSHandler_Main_50ms();
}

/*===========================================================================*
 * Test Cases: BCD_To_Decimal
 *===========================================================================*/

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, BcdToDecimal_ConvertsPackedDigits)
{
   EXPECT_EQ(BCD_To_Decimal(0x1234U), 1234U);
   EXPECT_EQ(BCD_To_Decimal(0x24U), 24U);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0x1111_ECUVoltage_ReadData
 *===========================================================================*/

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, EcuVoltageReadData_ScalesBatteryVoltageIntoRawByte)
{
   /* ECU voltage is encoded as a 2-byte big-endian value: Data[0]=high byte, Data[1]=low byte.
    * 12.5V * resolution(10) = 125 = 0x007D -> Data[0]=0x00, Data[1]=0x7D */
   Dcm_DataElement_Data_ECUVoltage_Read_ArrayType data[2] = {0U};
   Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_PhysicalAdcData_De_PhysicalAdcData_fake.custom_fake =
      Rte_Read_PhysicalAdcData_set_battery_12_5v;

   const Std_ReturnType ret = DataServices_Data_0x1111_ECUVoltage_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_PhysicalAdcData_De_PhysicalAdcData_fake.call_count, 1u);
   EXPECT_EQ(data[0], 0U);
   EXPECT_EQ(data[1], 125U);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, EcuVoltageReadData_NullData_ReturnsNotOk)
{
   const Std_ReturnType ret = DataServices_Data_0x1111_ECUVoltage_ReadData(DCM_INITIAL, nullptr);

   EXPECT_EQ(ret, RTE_E_DataServices_Data_ECUVoltage_Read_E_NOT_OK);
   EXPECT_EQ(Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_PhysicalAdcData_De_PhysicalAdcData_fake.call_count, 0u);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xA000_SerialNumber_ReadData
 *===========================================================================*/

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SerialNumberReadData_FormatsBcdCalibrationAsAscii)
{
   Dcm_DataElement_Data_SerialNumber_Read_ArrayType data[16] = {0U};
   uint8 expected[16]                                        = {0U};
   const uint32 julian_year_decimal                          = BCD_To_Decimal((uint32_t)k_Julian_Year_USC);
   const uint32 julian_date_decimal                          = BCD_To_Decimal((uint32_t)k_Julian_Production_Date_USC);
   const uint32 sequence_number_decimal                      = BCD_To_Decimal((uint32_t)k_Mfg_Sequence_Number_USC);

   expected[0]  = '0';
   expected[1]  = '0';
   expected[2]  = '0';
   expected[3]  = '0';
   expected[4]  = '0';
   expected[5]  = '2';
   expected[6]  = '0';
   expected[7]  = (uint8)('0' + ((julian_year_decimal / 10U) % 10U));
   expected[8]  = (uint8)('0' + (julian_year_decimal % 10U));
   expected[9]  = (uint8)('0' + (julian_date_decimal / 100U));
   expected[10] = (uint8)('0' + ((julian_date_decimal / 10U) % 10U));
   expected[11] = (uint8)('0' + (julian_date_decimal % 10U));
   expected[12] = (uint8)('0' + (sequence_number_decimal / 1000U));
   expected[13] = (uint8)('0' + ((sequence_number_decimal / 100U) % 10U));
   expected[14] = (uint8)('0' + ((sequence_number_decimal / 10U) % 10U));
   expected[15] = (uint8)('0' + (sequence_number_decimal % 10U));

   const Std_ReturnType ret = DataServices_Data_0xA000_SerialNumber_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   for (uint32 index = 0U; index < 16U; ++index)
   {
      EXPECT_EQ(data[index], expected[index]);
   }
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SerialNumberReadData_NullData_ReturnsNotOk)
{
   const Std_ReturnType ret = DataServices_Data_0xA000_SerialNumber_ReadData(DCM_INITIAL, nullptr);

   EXPECT_EQ(ret, RTE_E_DataServices_Data_SerialNumber_Read_E_NOT_OK);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SerialNumberReadData_FaultBranch_FillsZeroAscii)
{
   Dcm_DataElement_Data_SerialNumber_Read_ArrayType data[16] = {0U};
   Platform_fault_T fault_table                              = {0};

   fault_table.Platform_Bits.usc_validation_fault                                                                = TRUE;
   Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable_fake.return_val = 0U;
   Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable_fake.custom_fake =
      Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable_set_validation_fault;

   const Std_ReturnType ret = DataServices_Data_0xA000_SerialNumber_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   for (uint32 index = 0U; index < 16U; ++index)
   {
      EXPECT_EQ(data[index], 0x30U);
   }
}

/*===========================================================================*
 * Test Cases: CSDataServices_Data_Snapshot_DID_0x1111_ECUVoltage_ReadData
 *===========================================================================*/

/* Valid Data pointer → returns RTE_E_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SnapshotDID1111EcuVoltage_ReadData_ReturnsOk)
{
   uint8 data[2] = {0U};

   const Std_ReturnType ret = CSDataServices_Data_Snapshot_DID_0x1111_ECUVoltage_ReadData(data);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: CSDataServices_Data_Snapshot_DID_0x1112_VehicleSpeed_ReadData
 *===========================================================================*/

/* Valid Data pointer → returns RTE_E_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SnapshotDID1112VehicleSpeed_ReadData_ReturnsOk)
{
   uint8 data[2] = {0U};

   const Std_ReturnType ret = CSDataServices_Data_Snapshot_DID_0x1112_VehicleSpeed_ReadData(data);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: CSDataServices_Data_Snapshot_DID_0x1116_CombinedSignal_ReadData
 *===========================================================================*/

/* Valid Data pointer → returns RTE_E_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SnapshotDID1116CombinedSignal_ReadData_ReturnsOk)
{
   uint8 data[7] = {0U};

   const Std_ReturnType ret = CSDataServices_Data_Snapshot_DID_0x1116_CombinedSignal_ReadData(data);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: CSDataServices_Data_Snapshot_DID_0x1117_Sensor_Availability_Flag_Information_ReadData
 *===========================================================================*/

/* Valid Data pointer → returns RTE_E_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SnapshotDID1117SensorAvailabilityFlag_ReadData_ReturnsOk)
{
   uint8 data[1] = {0U};

   const Std_ReturnType ret = CSDataServices_Data_Snapshot_DID_0x1117_Sensor_Availability_Flag_Information_ReadData(data);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: CSDataServices_Data_Snapshot_DID_0xa004_Ego_Acceleration_ReadData
 *===========================================================================*/

/* Valid Data pointer → returns RTE_E_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SnapshotDIDa004EgoAcceleration_ReadData_ReturnsOk)
{
   uint8 data[1] = {0U};

   const Std_ReturnType ret = CSDataServices_Data_Snapshot_DID_0xa004_Ego_Acceleration_ReadData(data);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SensorPositionPimReadOperation_ValidPtr_CanBeCalledWithoutFault)
{
   Dt_SensorPosition_Status_T sensor_pos = {0};
   CS_SensorPosition_Pim_Read_Operation(&sensor_pos);
}
 * Test Cases: DataServices_Data_0x1111_ECUVoltage_ConditionCheckRead
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, EcuVoltageConditionCheckRead_ReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0x1111_ECUVoltage_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0x1112_VehicleSpeed_ConditionCheckRead
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, VehicleSpeedConditionCheckRead_ReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0x1112_VehicleSpeed_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0x1112_VehicleSpeed_ReadData
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, VehicleSpeedReadData_ReturnsOk)
{
   Dcm_DataElement_Data_VehicleSpeed_Read_ArrayType data[2] = {0U};

   const Std_ReturnType ret = DataServices_Data_0x1112_VehicleSpeed_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0x1116_DateandTime_ConditionCheckRead
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DateAndTimeConditionCheckRead_ReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0x1116_DateandTime_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0x1116_DateandTime_ReadData
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DateAndTimeReadData_ReturnsOk)
{
   Dcm_DataElement_Data_DateandTime_Read_ArrayType data[7] = {0U};

   const Std_ReturnType ret = DataServices_Data_0x1116_DateandTime_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0x1117_Sensor_Availability_Flag_ConditionCheckRead
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SensorAvailabilityFlagConditionCheckRead_ReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0x1117_Sensor_Availability_Flag_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0x1117_Sensor_Availability_Flag_ReadData
 *===========================================================================*/

/* Operation mode is stored with configured offset applied */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SensorAvailabilityFlagReadData_OperationModeIsStoredInData)
{
   Dcm_DataElement_Data_Sensor_Availability_Flag_Read_ArrayType data[1]         = {0U};
   Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System = 3U;

   const Std_ReturnType ret = DataServices_Data_0x1117_Sensor_Availability_Flag_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(data[0], static_cast<Dcm_DataElement_Data_Sensor_Availability_Flag_Read_ArrayType>(3U - OP_MODE_OFFSET));
}

/* Zero operation mode underflows by design when offset is applied */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SensorAvailabilityFlagReadData_ZeroOperationMode_DataIsZero)
{
   Dcm_DataElement_Data_Sensor_Availability_Flag_Read_ArrayType data[1] = {0xFFu};
   /* SetUp already reset the backing variable to 0 */

   const Std_ReturnType ret = DataServices_Data_0x1117_Sensor_Availability_Flag_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(data[0], static_cast<Dcm_DataElement_Data_Sensor_Availability_Flag_Read_ArrayType>(0xFFu));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SensorAvailabilityFlagReadData_NullData_ReturnsNotOk)
{
   const Std_ReturnType ret = DataServices_Data_0x1117_Sensor_Availability_Flag_ReadData(DCM_INITIAL, nullptr);

   EXPECT_EQ(ret, RTE_E_DataServices_Data_Sensor_Availability_Flag_Read_E_NOT_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xA000_SerialNumber_ConditionCheckRead
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SerialNumberConditionCheckRead_ReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0xA000_SerialNumber_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xA001_SoftwareNumber_ConditionCheckRead
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SoftwareNumberConditionCheckRead_ReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0xA001_SoftwareNumber_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xA001_SoftwareNumber_ReadData
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SoftwareNumberReadData_ReturnsOk)
{
   Dcm_DataElement_Data_SoftwareNumber_Read_ArrayType data[1] = {0U};

   const Std_ReturnType ret = DataServices_Data_0xA001_SoftwareNumber_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SoftwareNumberReadData_DefaultBranch_UsesFallbackPartCode)
{
   Dcm_DataElement_Data_SoftwareNumber_Read_ArrayType data[14] = {0U};
   const uint8 expected[14] = {'F', 'F', 'F', 'A', 'A', 'F', '.', 'F', '.', 'F', 'F', '.', 'F', 'F'};

   Base_Software_Part_Number_and_Revision_SRR[3] = 'B';
   Base_Software_Part_Number_and_Revision_SRR[4] = 'A';

   const Std_ReturnType ret = DataServices_Data_0xA001_SoftwareNumber_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(memcmp(data, expected, sizeof(expected)), 0);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SoftwareNumberReadData_ValidBranch_UsesCustomerPosition)
{
   Dcm_DataElement_Data_SoftwareNumber_Read_ArrayType data[14] = {0U};
   const uint8 expected[14] = {'A', 'L', '5', 'A', 'A', '1', '.', '0', '0', '.', '0', '0', '.', '0'};

   memcpy(Base_Software_Part_Number_and_Revision_SRR, expected, sizeof(expected));
   Set_Customer_Radar_Position(SRR_FC);

   const Std_ReturnType ret = DataServices_Data_0xA001_SoftwareNumber_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(data[2], '5');
   EXPECT_EQ(data[0], 'A');
   EXPECT_EQ(data[1], 'L');
   EXPECT_EQ(data[3], 'A');
   EXPECT_EQ(data[4], 'A');
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SoftwareNumberReadData_RlBranch_UsesRrLCode)
{
   Dcm_DataElement_Data_SoftwareNumber_Read_ArrayType data[14] = {0U};
   const uint8 expected[14] = {'A', 'L', '5', 'A', 'A', '1', '.', '0', '0', '.', '0', '0', '.', '0'};

   memcpy(Base_Software_Part_Number_and_Revision_SRR, expected, sizeof(expected));
   Set_Customer_Radar_Position(SRR_L1);

   const Std_ReturnType ret = DataServices_Data_0xA001_SoftwareNumber_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(data[2], '6');
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SoftwareNumberReadData_DefaultBranch_UsesRrLCode)
{
   Dcm_DataElement_Data_SoftwareNumber_Read_ArrayType data[14] = {0U};
   const uint8 expected[14] = {'A', 'L', '5', 'A', 'A', '1', '.', '0', '0', '.', '0', '0', '.', '0'};

   memcpy(Base_Software_Part_Number_and_Revision_SRR, expected, sizeof(expected));
   Set_Customer_Radar_Position(0xFFU);

   const Std_ReturnType ret = DataServices_Data_0xA001_SoftwareNumber_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(data[2], '6');
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ConditionCheckRead
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DatasetPartNoAndRevisionConditionCheckRead_ReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ReadData
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DatasetPartNoAndRevisionReadData_ReturnsOk)
{
   Dcm_DataElement_Data_Dataset_Part_No_and_Revision_Read_ArrayType data[1] = {0U};

   const Std_ReturnType ret = DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DatasetPartNoAndRevisionReadData_DefaultBranch_UsesFallbackPartCode)
{
   Dcm_DataElement_Data_Dataset_Part_No_and_Revision_Read_ArrayType data[12] = {0U};
   const uint8 expected[12] = {'F', 'F', 'F', 'A', 'D', 'F', '.', 'F', 'F', '.', 'F', 'F'};

   Dataset_Part_Number_and_Revision_SRR[3] = 'B';
   Dataset_Part_Number_and_Revision_SRR[4] = 'D';

   const Std_ReturnType ret = DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(memcmp(data, expected, sizeof(expected)), 0);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DatasetPartNoAndRevisionReadData_ValidBranch_UsesCustomerPosition)
{
   Dcm_DataElement_Data_Dataset_Part_No_and_Revision_Read_ArrayType data[12] = {0U};
   const uint8 expected[12] = {'A', 'L', '5', 'A', 'D', '4', '.', '0', '0', '.', '0', '0'};

   memcpy(Dataset_Part_Number_and_Revision_SRR, expected, sizeof(expected));
   Set_Customer_Radar_Position(SRR_FC);

   const Std_ReturnType ret = DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(data[0], 'A');
   EXPECT_EQ(data[2], '5');
   EXPECT_EQ(data[3], 'A');
   EXPECT_EQ(data[4], 'D');
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DatasetPartNoAndRevisionReadData_RlBranch_UsesRrLCode)
{
   Dcm_DataElement_Data_Dataset_Part_No_and_Revision_Read_ArrayType data[12] = {0U};
   const uint8 expected[12] = {'A', 'L', '5', 'A', 'D', '4', '.', '0', '0', '.', '0', '0'};

   memcpy(Dataset_Part_Number_and_Revision_SRR, expected, sizeof(expected));
   Set_Customer_Radar_Position(SRR_L1);

   const Std_ReturnType ret = DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(data[2], '6');
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DatasetPartNoAndRevisionReadData_DefaultBranch_UsesRrLCode)
{
   Dcm_DataElement_Data_Dataset_Part_No_and_Revision_Read_ArrayType data[12] = {0U};
   const uint8 expected[12] = {'A', 'L', '5', 'A', 'D', '4', '.', '0', '0', '.', '0', '0'};

   memcpy(Dataset_Part_Number_and_Revision_SRR, expected, sizeof(expected));
   Set_Customer_Radar_Position(0xFFU);

   const Std_ReturnType ret = DataServices_Data_0xA002_Dataset_Part_No_and_Revision_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(data[2], '6');
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xA003_SMC_Part_No_and_Revision_ConditionCheckRead
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SmcPartNoAndRevisionConditionCheckRead_ReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0xA003_SMC_Part_No_and_Revision_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xA003_SMC_Part_No_and_Revision_ReadData
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SmcPartNoAndRevisionReadData_ReturnsOk)
{
   Dcm_DataElement_Data_SMC_Part_No_and_Revision_Read_ArrayType data[1] = {0U};

   const Std_ReturnType ret = DataServices_Data_0xA003_SMC_Part_No_and_Revision_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SmcPartNoAndRevisionReadData_DefaultBranch_UsesFallbackPartCode)
{
   Dcm_DataElement_Data_SMC_Part_No_and_Revision_Read_ArrayType data[12] = {0U};
   const uint8 expected[12] = {'F', 'F', 'F', 'A', 'C', 'F', '.', 'F', 'F', '.', 'F', 'F'};

   SMC_Part_Number_and_Revision[3] = 'B';
   SMC_Part_Number_and_Revision[4] = 'C';

   const Std_ReturnType ret = DataServices_Data_0xA003_SMC_Part_No_and_Revision_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(memcmp(data, expected, sizeof(expected)), 0);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SmcPartNoAndRevisionReadData_ValidBranch_UsesCustomerPosition)
{
   Dcm_DataElement_Data_SMC_Part_No_and_Revision_Read_ArrayType data[12] = {0U};
   const uint8 expected[12] = {'A', 'L', '5', 'A', 'C', '4', '.', '0', '0', '.', '0', '0'};

   memcpy(SMC_Part_Number_and_Revision, expected, sizeof(expected));
   Set_Customer_Radar_Position(SRR_FC);

   const Std_ReturnType ret = DataServices_Data_0xA003_SMC_Part_No_and_Revision_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(data[0], 'A');
   EXPECT_EQ(data[2], '5');
   EXPECT_EQ(data[3], 'A');
   EXPECT_EQ(data[4], 'C');
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SmcPartNoAndRevisionReadData_RlBranch_UsesRrLCode)
{
   Dcm_DataElement_Data_SMC_Part_No_and_Revision_Read_ArrayType data[12] = {0U};
   const uint8 expected[12] = {'A', 'L', '5', 'A', 'C', '4', '.', '0', '0', '.', '0', '0'};

   memcpy(SMC_Part_Number_and_Revision, expected, sizeof(expected));
   Set_Customer_Radar_Position(SRR_L1);

   const Std_ReturnType ret = DataServices_Data_0xA003_SMC_Part_No_and_Revision_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(data[2], '6');
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SmcPartNoAndRevisionReadData_DefaultBranch_UsesRrLCode)
{
   Dcm_DataElement_Data_SMC_Part_No_and_Revision_Read_ArrayType data[12] = {0U};
   const uint8 expected[12] = {'A', 'L', '5', 'A', 'C', '4', '.', '0', '0', '.', '0', '0'};

   memcpy(SMC_Part_Number_and_Revision, expected, sizeof(expected));
   Set_Customer_Radar_Position(0xFFU);

   const Std_ReturnType ret = DataServices_Data_0xA003_SMC_Part_No_and_Revision_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(data[2], '6');
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xA004_Ego_Acceleration_ConditionCheckRead
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, EgoAccelerationConditionCheckRead_ReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0xA004_Ego_Acceleration_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xA004_Ego_Acceleration_ReadData
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, EgoAccelerationReadData_ReturnsOk)
{
   Dcm_DataElement_Data_Ego_Acceleration_Read_ArrayType data[1] = {0U};

   const Std_ReturnType ret = DataServices_Data_0xA004_Ego_Acceleration_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xF010_Vehicle_Variant_ConditionCheckRead
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, VehicleVariantConditionCheckRead_ReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0xF010_Vehicle_Variant_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xF010_Vehicle_Variant_ReadData
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, VehicleVariantReadData_ReturnsOk)
{
   Dcm_DataElement_Data_Vehicle_Variant_Read_ArrayType data[1] = {0U};

   const Std_ReturnType ret = DataServices_Data_0xF010_Vehicle_Variant_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, VehicleVariantReadData_NullData_ReturnsInvalid)
{
   const Std_ReturnType ret = DataServices_Data_0xF010_Vehicle_Variant_ReadData(DCM_INITIAL, nullptr);

   EXPECT_EQ(ret, RTE_E_INVALID);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, VehicleVariantReadData_UsesNotAvailableDefaultValue)
{
   Dcm_DataElement_Data_Vehicle_Variant_Read_ArrayType data[1] = {0U};

   const Std_ReturnType ret = DataServices_Data_0xF010_Vehicle_Variant_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(data[0], 0x0FU);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xF017_Pin_Position_Status_ConditionCheckRead
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, PinPositionStatusConditionCheckRead_ReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0xF017_Pin_Position_Status_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xF017_Pin_Position_Status_ReadData
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, PinPositionStatusReadData_ReturnsOk)
{
   Dcm_DataElement_Data_Pin_Position_Status_Read_ArrayType data[1] = {0U};

   const Std_ReturnType ret = DataServices_Data_0xF017_Pin_Position_Status_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xF150_Hardware_Version_number_ConditionCheckRead
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, HardwareVersionNumberConditionCheckRead_ReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0xF150_Hardware_Version_number_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xF150_Hardware_Version_number_ReadData
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, HardwareVersionNumberReadData_ReturnsOk)
{
   Dcm_DataElement_Data_Hardware_Version_number_Read_ArrayType data[1] = {0U};

   const Std_ReturnType ret = DataServices_Data_0xF150_Hardware_Version_number_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, HardwareVersionNumberReadData_NullData_ReturnsInvalid)
{
   const Std_ReturnType ret = DataServices_Data_0xF150_Hardware_Version_number_ReadData(DCM_INITIAL, nullptr);

   EXPECT_EQ(ret, RTE_E_INVALID);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, HardwareVersionNumberReadData_CopiesKnownVersionString)
{
   Dcm_DataElement_Data_Hardware_Version_number_Read_ArrayType data[5] = {0U};
   const uint8 expected[5]                                             = {'0', '1', '.', '0', '0'};

   const Std_ReturnType ret = DataServices_Data_0xF150_Hardware_Version_number_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(memcmp(data, expected, sizeof(expected)), 0);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xF15A_Software_Fingerprint_ConditionCheckRead
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SoftwareFingerprintConditionCheckRead_ReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0xF15A_Software_Fingerprint_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xF15A_Software_Fingerprint_ReadData
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SoftwareFingerprintReadData_ReturnsOk)
{
   Dcm_DataElement_Data_Software_Fingerprint_Read_ArrayType data[1] = {0U};

   const Std_ReturnType ret = DataServices_Data_0xF15A_Software_Fingerprint_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SoftwareFingerprintReadData_NullData_ReturnsInvalid)
{
   const Std_ReturnType ret = DataServices_Data_0xF15A_Software_Fingerprint_ReadData(DCM_INITIAL, nullptr);

   EXPECT_EQ(ret, RTE_E_INVALID);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SoftwareFingerprintReadData_DefaultBranch_WritesZeroFilledFingerprint)
{
   /* Set invalid tool code (> 0x03) to exercise the default zero-filled branch. */
   const uint8 saved_fingerprint_byte0 = software_fingerprint_info[0];
   software_fingerprint_info[0]        = 0x04U;

   ASSERT_EQ(software_fingerprint_info[0], 0x04U);

   Dcm_DataElement_Data_Software_Fingerprint_Read_ArrayType data[4] = {0U};
   const uint8 expected[4]                                          = {0U, 0U, 0U, 0U};

   const Std_ReturnType ret = DataServices_Data_0xF15A_Software_Fingerprint_ReadData(DCM_INITIAL, data);

   software_fingerprint_info[0] = saved_fingerprint_byte0; /* restore so next tests are not affected */

   EXPECT_EQ(ret, RTE_E_OK);
   EXPECT_EQ(data[0], 0U);
   EXPECT_EQ(data[1], 0U);
   EXPECT_EQ(data[2], 0U);
   EXPECT_EQ(data[3], 0U);
   EXPECT_EQ(memcmp(data, expected, sizeof(expected)), 0);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SoftwareFingerprintReadData_ValidToolCodeBranch_ReturnsStoredFingerprint)
{
   Dcm_DataElement_Data_Software_Fingerprint_Read_ArrayType written_data[4] = {0x03U, 0x11U, 0x22U, 0x33U};
   Dcm_DataElement_Data_Software_Fingerprint_Read_ArrayType read_data[4]    = {0U};
   Dcm_NegativeResponseCodeType err_code                                    = 0xFFu;

   const Std_ReturnType write_ret = DataServices_Data_0xF15A_Software_Fingerprint_WriteData(written_data, DCM_INITIAL, &err_code);
   const Std_ReturnType read_ret  = DataServices_Data_0xF15A_Software_Fingerprint_ReadData(DCM_INITIAL, read_data);

   EXPECT_EQ(write_ret, RTE_E_OK);
   EXPECT_EQ(read_ret, RTE_E_OK);
   EXPECT_EQ(memcmp(read_data, written_data, sizeof(written_data)), 0);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xF15A_Software_Fingerprint_WriteData
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SoftwareFingerprintWriteData_ReturnsOk)
{
   Dcm_DataElement_Data_Software_Fingerprint_Read_ArrayType data[4] = {0U};
   Dcm_NegativeResponseCodeType err_code                            = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0xF15A_Software_Fingerprint_WriteData(data, DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: check_subfunction_0x85
 *===========================================================================*/

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, CheckSubfunction0x85_ValidSubFunctions_ReturnsOk)
{
   uint8 request_on[1]  = {CONTROL_DTC_ON};
   uint8 request_off[1] = {CONTROL_DTC_OFF};

   EXPECT_EQ(check_subfunction_0x85(request_on), E_OK);
   EXPECT_EQ(check_subfunction_0x85(request_off), E_OK);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, CheckSubfunction0x85_InvalidSubFunction_ReturnsNotOk)
{
   uint8 request_invalid[1] = {0x00U};

   EXPECT_EQ(check_subfunction_0x85(request_invalid), E_NOT_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xF16A_Boot_App_Identification_ConditionCheckRead
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, BootAppIdentificationConditionCheckRead_ReturnsOk)
{
   Dcm_NegativeResponseCodeType err_code = 0xFFu;

   const Std_ReturnType ret = DataServices_Data_0xF16A_Boot_App_Identification_ConditionCheckRead(DCM_INITIAL, &err_code);

   EXPECT_EQ(ret, RTE_E_OK);
}

/*===========================================================================*
 * Test Cases: DataServices_Data_0xF16A_Boot_App_Identification_ReadData
 *===========================================================================*/

/* Returns RTE_E_OK unconditionally */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, BootAppIdentificationReadData_ReturnsOk)
{
   Dcm_DataElement_Data_Boot_App_Identification_DID_Read_ArrayType data[1] = {0U};

   const Std_ReturnType ret = DataServices_Data_0xF16A_Boot_App_Identification_ReadData(DCM_INITIAL, data);

   EXPECT_EQ(ret, RTE_E_OK);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, BootAppIdentificationReadData_NullData_ReturnsInvalid)
{
   const Std_ReturnType ret = DataServices_Data_0xF16A_Boot_App_Identification_ReadData(DCM_INITIAL, nullptr);

   EXPECT_EQ(ret, RTE_E_INVALID);
}

/*===========================================================================*
 * Test Cases: ServiceRequestNotification_Indication
 *===========================================================================*/

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, ServiceRequestNotification_Indication_ReturnsRteEOk)
{
   uint8 requestData[4]                   = {0x10, 0x01, 0x02, 0x03};
   Dcm_NegativeResponseCodeType errorCode = 0;

   Std_ReturnType result = ServiceRequestNotification_Indication(0x10,                // SID
                                                                 requestData,         // RequestData
                                                                 sizeof(requestData), // DataSize
                                                                 0x00,                // ReqType
                                                                 0xF1A0,              // SourceAddress
                                                                 &errorCode);         // ErrorCode

   EXPECT_EQ(RTE_E_OK, result);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, Diagnostics_Clear_ReturnsOkAndClearsFaultTables)
{
   const Std_ReturnType result = Diagnostics_Clear();

   EXPECT_EQ(E_OK, result);
   EXPECT_EQ(Clear_Platform_Fault_Arrays_fake.call_count, 1u);
   EXPECT_EQ(Clear_Cust_Fault_Arrays_fake.call_count, 1u);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, ServiceRequestNotification_Indication_ClearDtc_ValidLength_CallsDiagnosticsClear)
{
   uint8 requestData[3]                   = {0x01, 0x02, 0x03};
   Dcm_NegativeResponseCodeType errorCode = 0U;

   const Std_ReturnType result =
      ServiceRequestNotification_Indication(CLEAR_DTC_SERVICE, requestData, sizeof(requestData), DCM_INITIAL, 0xF1A0U, &errorCode);

   EXPECT_EQ(E_OK, result);
   EXPECT_EQ(Clear_Platform_Fault_Arrays_fake.call_count, 1u);
   EXPECT_EQ(Clear_Cust_Fault_Arrays_fake.call_count, 1u);
   EXPECT_EQ(errorCode, 0U);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, ServiceRequestNotification_Indication_ClearDtc_InvalidLength_ReturnsNotOk)
{
   uint8 requestData[2]                   = {0x01, 0x02};
   Dcm_NegativeResponseCodeType errorCode = 0U;

   const Std_ReturnType result =
      ServiceRequestNotification_Indication(CLEAR_DTC_SERVICE, requestData, sizeof(requestData), DCM_INITIAL, 0xF1A0U, &errorCode);

   EXPECT_EQ(RTE_E_ServiceRequestNotification_E_NOT_OK, result);
   EXPECT_EQ(errorCode, DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, ServiceRequestNotification_Indication_ControlDtc_ValidSubFunction_CallsOperation)
{
   uint8 requestData[1]                   = {CONTROL_DTC_ON};
   Dcm_NegativeResponseCodeType errorCode = 0U;

   const Std_ReturnType result =
      ServiceRequestNotification_Indication(CONTROL_DTC, requestData, sizeof(requestData), DCM_INITIAL, 0xF1A0U, &errorCode);

   EXPECT_EQ(E_OK, result);
   EXPECT_EQ(CS_Control_DTC_Service_Operation_fake.call_count, 1u);
   EXPECT_EQ(CS_Control_DTC_Service_Operation_fake.arg0_val, CONTROL_DTC_ON);
   EXPECT_EQ(errorCode, 0U);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, ServiceRequestNotification_Indication_ControlDtc_UnsupportedSubFunction_ReturnsNotOk)
{
   uint8 requestData[1]                   = {0x00U};
   Dcm_NegativeResponseCodeType errorCode = 0U;

   const Std_ReturnType result =
      ServiceRequestNotification_Indication(CONTROL_DTC, requestData, sizeof(requestData), DCM_INITIAL, 0xF1A0U, &errorCode);

   EXPECT_EQ(RTE_E_ServiceRequestNotification_E_NOT_OK, result);
   EXPECT_EQ(errorCode, DCM_E_SUBFUNCTIONNOTSUPPORTED);
}

/*===========================================================================*
 * Test Cases: ServiceRequestNotification_Confirmation
 *===========================================================================*/

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, ReturnsRteEOk)
{
   Std_ReturnType result = ServiceRequestNotification_Confirmation(0x10U,           // SID
                                                                   0x00U,           // ReqType
                                                                   0xF1A0U,         // SourceAddress
                                                                   DCM_RES_POS_OK); // ConfirmationStatus

   EXPECT_EQ(RTE_E_OK, result);
}

/*===========================================================================*
 * Test Cases:         SecurityAccess_Unlocked_L1_GetSeed
 *===========================================================================*/

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SecurityAccess_Unlocked_L1_GetSeed_ReturnsRteEOk)
{
   uint8 seed[16]                         = {0};
   Dcm_NegativeResponseCodeType errorCode = 0;

   Std_ReturnType result = SecurityAccess_Unlocked_L1_GetSeed(DCM_INITIAL, seed, &errorCode);

   EXPECT_EQ(RTE_E_OK, result);
}

/*===========================================================================*
 * Test Cases:         SecurityAccess_Unlocked_L1_CompareKey
 *===========================================================================*/

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SecurityAccess_Unlocked_L1_CompareKey_ReturnsRteEOk)
{
   uint8 key[16]                          = {0};
   Dcm_NegativeResponseCodeType errorCode = 0;

   Std_ReturnType result = SecurityAccess_Unlocked_L1_CompareKey(key, DCM_INITIAL, &errorCode);

   EXPECT_EQ(RTE_E_OK, result);
}

/*===========================================================================*
 * Test Cases:         RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start
 *===========================================================================*/

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_ReturnsRteEOk)
{
   Dcm_StartDataIn_Routine_Pin_Position_Unlock_Start_In_ReqDataArrayType inReqData    = {};
   Dcm_StartDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                             = 0U;

   // Read_Sensor_Position_From_Pins_fake.return_val = SRR_FC;
   CS_ReadNvM_Value_Operation_fake.custom_fake   = CS_ReadNvM_Value_set_sensorpos_locked;
   CS_GetError_Status_Operation_fake.custom_fake = CS_GetError_Status_set_nvm_ok;
   Std_ReturnType result =
      RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start(&inReqData, DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_OK, result);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_RequestResults_ReturnsRteEOk)
{
   Dcm_RequestDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                               = 0U;
   Dcm_StartDataIn_Routine_Pin_Position_Unlock_Start_In_ReqDataArrayType inReqData      = {};
   Dcm_StartDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataArrayType startOutData = {};
   /* Get_Customer_Radar_Position() is provided by test fake and returns SRR_FC. */
   CS_ReadNvM_Value_Operation_fake.custom_fake   = CS_ReadNvM_Value_set_sensorpos_locked;
   CS_GetError_Status_Operation_fake.custom_fake = CS_GetError_Status_set_nvm_ok;
   EXPECT_EQ(RTE_E_OK,
             RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start(&inReqData, DCM_INITIAL, &startOutData, &errorCode));

   Std_ReturnType retVal =
      RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_RequestResults(DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_OK, retVal);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_RequestResults_WithoutStart_ReturnsRequestSequenceError)
{
   Dcm_RequestDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                               = DCM_E_POSITIVERESPONSE;

   Std_ReturnType retVal =
      RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_RequestResults(DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_INVALID, retVal);
   EXPECT_EQ(DCM_E_REQUESTSEQUENCEERROR, errorCode);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start_OutOfRangeRequest_SetsAbortAndFailed)
{
   Dcm_StartDataIn_Routine_Pin_Position_Unlock_Start_In_ReqDataArrayType inReqData    = {};
   Dcm_StartDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                             = DCM_E_POSITIVERESPONSE;

   inReqData                                     = 3U;
   CS_ReadNvM_Value_Operation_fake.custom_fake   = CS_ReadNvM_Value_set_sensorpos_locked;
   CS_GetError_Status_Operation_fake.custom_fake = CS_GetError_Status_set_nvm_ok;

   Std_ReturnType retVal =
      RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start(&inReqData, DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_ServiceRequestNotification_E_NOT_OK, retVal);
   EXPECT_EQ(DCM_E_REQUESTOUTOFRANGE, errorCode);
   EXPECT_EQ(ROUTINE_ABORT, rid_unlock_start_routine_Status);
   EXPECT_EQ(ROUTINE_FAILED, outResData);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start_ReturnsRteEOk)
{
   Dcm_StartDataIn_Routine_Pin_Position_Lock_Start_In_ReqDataArrayType inReqData    = {};
   Dcm_StartDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                           = 0U;

   // Read_Sensor_Position_From_Pins_fake.return_val = SRR_FC;
   CS_ReadNvM_Value_Operation_fake.custom_fake   = CS_ReadNvM_Value_set_sensorpos_unlocked;
   CS_GetError_Status_Operation_fake.custom_fake = CS_GetError_Status_set_nvm_ok;
   Std_ReturnType retVal =
      RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start(&inReqData, DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_OK, retVal);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start_OutOfRangeRequest_SetsAbortAndFailed)
{
   Dcm_StartDataIn_Routine_Pin_Position_Lock_Start_In_ReqDataArrayType inReqData    = {};
   Dcm_StartDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                           = DCM_E_POSITIVERESPONSE;
   inReqData                                                                        = 3U;
   // Read_Sensor_Position_From_Pins_fake.return_val = SRR_FC;
   CS_ReadNvM_Value_Operation_fake.custom_fake   = CS_ReadNvM_Value_set_sensorpos_unlocked;
   CS_GetError_Status_Operation_fake.custom_fake = CS_GetError_Status_set_nvm_ok;
   Std_ReturnType retVal =
      RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start(&inReqData, DCM_INITIAL, &outResData, &errorCode);
   EXPECT_EQ(RTE_E_ServiceRequestNotification_E_NOT_OK, retVal);
   EXPECT_EQ(DCM_E_REQUESTOUTOFRANGE, errorCode);
   EXPECT_EQ(ROUTINE_ABORT, rid_lock_start_routine_Status);
   EXPECT_EQ(ROUTINE_FAILED, outResData);
}
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults_ReturnsRteEOk)
{
   Dcm_RequestDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                             = 0U;

   Dcm_StartDataIn_Routine_Pin_Position_Lock_Start_In_ReqDataArrayType inReqData      = {};
   Dcm_StartDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType startOutData = {};
   // Read_Sensor_Position_From_Pins_fake.return_val                                     = SRR_FC;
   CS_ReadNvM_Value_Operation_fake.custom_fake   = CS_ReadNvM_Value_set_sensorpos_unlocked;
   CS_GetError_Status_Operation_fake.custom_fake = CS_GetError_Status_set_nvm_ok;
   EXPECT_EQ(RTE_E_OK,
             RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start(&inReqData, DCM_INITIAL, &startOutData, &errorCode));
   Std_ReturnType retVal =
      RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults(DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_OK, retVal);
}
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults_WithoutStart_ReturnsRequestSequenceError)
{
   Dcm_RequestDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                             = DCM_E_POSITIVERESPONSE;
   Std_ReturnType retVal =
      RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults(DCM_INITIAL, &outResData, &errorCode);
   EXPECT_EQ(RTE_E_INVALID, retVal);
   EXPECT_EQ(DCM_E_REQUESTSEQUENCEERROR, errorCode);
}

/* NULL In_ReqData → hits (NULL_PTR == In_ReqData) true branch, returns E_NOT_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start_NullInReqData_ReturnsNotOk)
{
   Dcm_StartDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                           = 0U;

   Std_ReturnType retVal =
      RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start(nullptr, DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(E_NOT_OK, retVal);
}

/* NULL ErrorCode → hits (NULL_PTR == ErrorCode) true branch, returns E_NOT_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start_NullErrorCode_ReturnsNotOk)
{
   Dcm_StartDataIn_Routine_Pin_Position_Lock_Start_In_ReqDataArrayType inReqData    = {};
   Dcm_StartDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType outResData = {};

   Std_ReturnType retVal =
      RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start(&inReqData, DCM_INITIAL, &outResData, nullptr);

   EXPECT_EQ(E_NOT_OK, retVal);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, RoutineServices_Routine_0x0200_CheckProgPreCond_Start_Start_ReturnsRteEOk)
{
   Dcm_StartDataOut_Routine_CheckProgPreCond_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                          = 0U;

   Std_ReturnType retVal = RoutineServices_Routine_0x0200_CheckProgPreCond_Start_Start(DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_OK, retVal);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xFDA3_Read_Active_Fault_Table_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_Read_Active_Fault_Table_Read_ArrayType data = {};

   Std_ReturnType retVal = DataServices_Data_0xFDA3_Read_Active_Fault_Table_ReadData(DCM_INITIAL, &data);

   EXPECT_EQ(RTE_E_OK, retVal);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xFDA3_Read_Active_Fault_Table_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   Std_ReturnType retVal = DataServices_Data_0xFDA3_Read_Active_Fault_Table_ConditionCheckRead(DCM_INITIAL, &errorCode);

   EXPECT_EQ(RTE_E_OK, retVal);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF19E_PCAN_DBC_Version_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_PCAN_DBC_Version_Read_ArrayType data = {};

   Std_ReturnType retVal = DataServices_Data_0xF19E_PCAN_DBC_Version_ReadData(DCM_INITIAL, &data);

   EXPECT_EQ(RTE_E_OK, retVal);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF19E_PCAN_DBC_Version_ReadData_NullData_ReturnsInvalid)
{
   Std_ReturnType retVal = DataServices_Data_0xF19E_PCAN_DBC_Version_ReadData(DCM_INITIAL, nullptr);

   EXPECT_EQ(retVal, RTE_E_INVALID);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF19E_PCAN_DBC_Version_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   Std_ReturnType retVal = DataServices_Data_0xF19E_PCAN_DBC_Version_ConditionCheckRead(DCM_INITIAL, &errorCode);

   EXPECT_EQ(RTE_E_OK, retVal);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF19D_CANDBMatrixVer_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_CANDBMatrixVer_Read_ArrayType data = {};

   Std_ReturnType retVal = DataServices_Data_0xF19D_CANDBMatrixVer_ReadData(DCM_INITIAL, &data);

   EXPECT_EQ(RTE_E_OK, retVal);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF19D_CANDBMatrixVer_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   Std_ReturnType retVal = DataServices_Data_0xF19D_CANDBMatrixVer_ConditionCheckRead(DCM_INITIAL, &errorCode);

   EXPECT_EQ(RTE_E_OK, retVal);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF191_HardwareNumber_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_HardwareNumber_Read_ArrayType data = {};

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF191_HardwareNumber_ReadData(DCM_INITIAL, &data));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF191_HardwareNumber_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF191_HardwareNumber_ConditionCheckRead(DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF18B_ECUBuildDate_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_ECUBuildDate_Read_ArrayType data = {};

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF18B_ECUBuildDate_ReadData(DCM_INITIAL, &data));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF18B_ECUBuildDate_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF18B_ECUBuildDate_ConditionCheckRead(DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF189_BaseSoftwareVersionNumber_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_Base_Software_Version_number_Read_ArrayType data = {};

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF189_Base_Software_Version_number_ReadData(DCM_INITIAL, &data));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF189_BaseSoftwareVersionNumber_ReadData_NullData_ReturnsInvalid)
{
   EXPECT_EQ(RTE_E_INVALID, DataServices_Data_0xF189_Base_Software_Version_number_ReadData(DCM_INITIAL, nullptr));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       DataServices_Data_0xF189_Base_Software_Version_number_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF189_Base_Software_Version_number_ConditionCheckRead(DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_ActiveDiagnosticSessionDataIdentifier_Read_ArrayType data = {};

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ReadData(DCM_INITIAL, &data));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ReadData_NullData_ReturnsNotOk)
{
   EXPECT_EQ(E_NOT_OK, DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ReadData(DCM_INITIAL, nullptr));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ReadData_SessionReadFails_ReturnsNotOk)
{
   Dcm_DataElement_Data_ActiveDiagnosticSessionDataIdentifier_Read_ArrayType data = {0xAAU};

   Dcm_GetSesCtrlType_fake.return_val = E_NOT_OK;

   EXPECT_EQ(RTE_E_DataServices_Data_ActiveDiagnosticSessionDataIdentifier_Read_E_NOT_OK,
             DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ReadData(DCM_INITIAL, &data));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF186_ActiveDiagnosticSessionDataIdentifier_ConditionCheckRead(DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF180_BootloaderNumber_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_BootloaderNumber_Read_ArrayType data = {};

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF180_BootloaderNumber_ReadData(DCM_INITIAL, &data));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF180_BootloaderNumber_ReadData_NullData_ReturnsInvalid)
{
   EXPECT_EQ(RTE_E_INVALID, DataServices_Data_0xF180_BootloaderNumber_ReadData(DCM_INITIAL, nullptr));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF180_BootloaderNumber_ReadData_RlBranch_UsesRrLCode)
{
   Dcm_DataElement_Data_BootloaderNumber_Read_ArrayType data[12] = {0U};

   Set_Customer_Radar_Position(SRR_L1);

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF180_BootloaderNumber_ReadData(DCM_INITIAL, data));
   EXPECT_EQ(data[2], '6');
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF180_BootloaderNumber_ReadData_DefaultBranch_UsesRrLCode)
{
   Dcm_DataElement_Data_BootloaderNumber_Read_ArrayType data[12] = {0U};

   Set_Customer_Radar_Position(0xFFU);

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF180_BootloaderNumber_ReadData(DCM_INITIAL, data));
   EXPECT_EQ(data[2], '6');
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF180_BootloaderNumber_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF180_BootloaderNumber_ConditionCheckRead(DCM_INITIAL, &errorCode));
}

/*===========================================================================*
 * Test Cases: Alignment DIDs and Routines (moved from Alignment module)
 *===========================================================================*/

/* 0xF011 Static Alignment Engineering Non Configuration Parameters */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead(
                          DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_Static_Alignment_Engineering_Non_Configuration_Parameters_Read_ArrayType data[42] = {0U};

   EXPECT_EQ(RTE_E_OK,
             DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ReadData(DCM_INITIAL, data));
}

/* 0xF012 Static Alignment Engineering Read Parameters */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK,
             DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ConditionCheckRead(DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_Static_Alignment_Engineering_Read_Parameters_Read_ArrayType data[22] = {0U};

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ReadData(DCM_INITIAL, data));
}

/* 0xF013 Static Alignment Engineering Write Configuration Parameter */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       DataServices_Data_0xF013_Static_Alignment_Engineering_Write_Configuration_Parameter_WriteData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_Static_Alignment_Engineering_Write_Configuration_Parameter_Write_ArrayType data[6] = {0U};
   Dcm_NegativeResponseCodeType errorCode                                                                  = 0U;

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF013_Static_Alignment_Engineering_Write_Configuration_Parameter_WriteData(
                          data, DCM_INITIAL, &errorCode));
}

/* 0xF014 Service Alignment Engineering Non Configuration Parameters */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead(
                          DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_Service_Alignment_Engineering_Non_Configuration_Parameters_Read_ArrayType data[14] = {0U};

   EXPECT_EQ(RTE_E_OK,
             DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ReadData(DCM_INITIAL, data));
}

/* 0xF015 Service Alignment Result Parameters */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ConditionCheckRead(DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_Service_Alignment_Result_Parameters_Read_ArrayType data[87] = {0U};

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ReadData(DCM_INITIAL, data));
}

/* 0xF016 Auto Alignment Status Information */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       DataServices_Data_0xF016_Auto_Alignment_Status_Information_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF016_Auto_Alignment_Status_Information_ConditionCheckRead(DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF016_Auto_Alignment_Status_Information_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_Auto_Alignment_Status_Information_Read_ArrayType data[93] = {0U};

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF016_Auto_Alignment_Status_Information_ReadData(DCM_INITIAL, data));
}

/* 0xF01B Manual Alignment Execution */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF01B_Manual_Alignment_Execution_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF01B_Manual_Alignment_Execution_ConditionCheckRead(DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF01B_Manual_Alignment_Execution_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_Manual_Alignment_Execution_Read_ArrayType data[10] = {0U};

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF01B_Manual_Alignment_Execution_ReadData(DCM_INITIAL, data));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF01B_Manual_Alignment_Execution_WriteData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_Manual_Alignment_Execution_Read_ArrayType data[10] = {0U};
   Dcm_NegativeResponseCodeType errorCode                                  = 0U;

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF01B_Manual_Alignment_Execution_WriteData(data, DCM_INITIAL, &errorCode));
}

/* 0xF01C Static Alignment Result Parameters */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ConditionCheckRead_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ConditionCheckRead(DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ReadData_ReturnsRteEOk)
{
   Dcm_DataElement_Data_Static_Alignment_Result_Parameters_Read_ArrayType data[55] = {0U};

   EXPECT_EQ(RTE_E_OK, DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ReadData(DCM_INITIAL, data));
}

/* 0x7000 Static Alignment Execution Start (Start / Stop / RequestResults) */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Start_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Start(DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop(DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults_ReturnsRteEOk)
{
   Dcm_RequestDataOut_Routine_Static_Alignment_Execution_Start_Out_ResDataArrayType outResData[3] = {0U};
   Dcm_NegativeResponseCodeType errorCode                                                         = 0U;

   EXPECT_EQ(RTE_E_OK,
             RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults(DCM_INITIAL, outResData, &errorCode));
}

/* 0x7003 Service Alignment Execution Start (Start / Stop / RequestResults) */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Start_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Start(DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop_ReturnsRteEOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   EXPECT_EQ(RTE_E_OK, RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop(DCM_INITIAL, &errorCode));
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults_ReturnsRteEOk)
{
   Dcm_RequestDataOut_Routine_Service_Alignment_Execution_Start_Out_ResDataArrayType outResData[28] = {0U};
   Dcm_NegativeResponseCodeType errorCode                                                           = 0U;

   EXPECT_EQ(RTE_E_OK,
             RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults(DCM_INITIAL, outResData, &errorCode));
}
/* Start: NULL ErrorCode -> ErrorCode assignment skipped, still returns RTE_E_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Start_NullErrorCode_ReturnsOk)
{
   EXPECT_EQ(RTE_E_OK, RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Start(DCM_INITIAL, nullptr));
}

/* Stop: NULL ErrorCode -> outer guard false, returns E_NOT_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop_NullErrorCode_ReturnsNotOk)
{
   Std_ReturnType ret = RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop(DCM_INITIAL, nullptr);

   EXPECT_EQ(RTE_E_RoutineServices_Routine_Static_Alignment_Execution_Start_E_NOT_OK, ret);
}

/* Stop: not started -> sequence error branch */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop_NotStarted_ReturnsSequenceError)
{
   Dcm_NegativeResponseCodeType errorCode = DCM_E_POSITIVERESPONSE;
   StaticAlignmentStarted                 = CODED_FALSE;

   Std_ReturnType ret = RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop(DCM_INITIAL, &errorCode);

   EXPECT_EQ(RTE_E_RoutineServices_Routine_Static_Alignment_Execution_Start_E_NOT_OK, ret);
   EXPECT_EQ(DCM_E_REQUESTSEQUENCEERROR, errorCode);
}

/* Stop: started -> success branch */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop_Started_ReturnsOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;
   StaticAlignmentStarted                 = CODED_TRUE;

   Std_ReturnType ret = RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop(DCM_INITIAL, &errorCode);

   EXPECT_EQ(RTE_E_OK, ret);
   EXPECT_EQ(DCM_E_POSITIVERESPONSE, errorCode);
}

/* RequestResults: NULL Out_ResData -> outer guard false, returns E_NOT_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults_NullOutResData_ReturnsNotOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults(DCM_INITIAL, nullptr, &errorCode);

   EXPECT_EQ(RTE_E_RoutineServices_Routine_Static_Alignment_Execution_Start_E_NOT_OK, ret);
}

/* RequestResults: neither started nor stopped -> sequence error branch */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults_NotStartedNorStopped_ReturnsSequenceError)
{
   Dcm_RequestDataOut_Routine_Static_Alignment_Execution_Start_Out_ResDataArrayType outResData[3] = {0U};
   Dcm_NegativeResponseCodeType errorCode                                                         = DCM_E_POSITIVERESPONSE;
   StaticAlignmentStarted                                                                         = CODED_FALSE;
   StaticAlignmentStoppedByTester                                                                 = CODED_FALSE;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults(DCM_INITIAL, outResData, &errorCode);

   EXPECT_EQ(RTE_E_RoutineServices_Routine_Static_Alignment_Execution_Start_E_NOT_OK, ret);
   EXPECT_EQ(DCM_E_REQUESTSEQUENCEERROR, errorCode);
}

/* RequestResults: alignment successful -> ProgressPercent forced to 100 */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults_Successful_ReportsProgressComplete)
{
   Dcm_RequestDataOut_Routine_Static_Alignment_Execution_Start_Out_ResDataArrayType outResData[3] = {0U};
   Dcm_NegativeResponseCodeType errorCode                                                         = 0U;
   StaticAlignmentStarted                                                                         = CODED_TRUE;
   StaticAlignmentStoppedByTester                                                                 = CODED_FALSE;
   AlignmentStatic.AlignmentStaticStatus                                                          = ALIGNMENT_SUCCESSFUL;
   AlignmentHandler.ProgressPercent                                                               = 42U;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults(DCM_INITIAL, outResData, &errorCode);

   EXPECT_EQ(RTE_E_OK, ret);
   EXPECT_EQ(ALIGNMENT_PROGRESS_PERCENT_COMPLETE, outResData[2]);
}

/* RequestResults: alignment not successful -> ProgressPercent taken from AlignmentHandler */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults_NotSuccessful_ReportsHandlerProgress)
{
   Dcm_RequestDataOut_Routine_Static_Alignment_Execution_Start_Out_ResDataArrayType outResData[3] = {0U};
   Dcm_NegativeResponseCodeType errorCode                                                         = 0U;
   StaticAlignmentStarted                                                                         = CODED_TRUE;
   StaticAlignmentStoppedByTester                                                                 = CODED_FALSE;
   AlignmentStatic.AlignmentStaticStatus                                                          = 0U;
   AlignmentHandler.ProgressPercent                                                               = 42U;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults(DCM_INITIAL, outResData, &errorCode);

   EXPECT_EQ(RTE_E_OK, ret);
   EXPECT_EQ(42U, outResData[2]);
}

/* Start: NULL ErrorCode -> ErrorCode assignment skipped, still returns RTE_E_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Start_NullErrorCode_ReturnsOk)
{
   EXPECT_EQ(RTE_E_OK, RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Start(DCM_INITIAL, nullptr));
}

/* Stop: NULL ErrorCode -> outer guard false, returns E_NOT_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop_NullErrorCode_ReturnsNotOk)
{
   Std_ReturnType ret = RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop(DCM_INITIAL, nullptr);

   EXPECT_EQ(RTE_E_RoutineServices_Routine_Service_Alignment_Execution_Start_E_NOT_OK, ret);
}

/* Stop: not started -> sequence error branch */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop_NotStarted_ReturnsSequenceError)
{
   Dcm_NegativeResponseCodeType errorCode = DCM_E_POSITIVERESPONSE;
   ServiceAlignmentStarted                = CODED_FALSE;

   Std_ReturnType ret = RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop(DCM_INITIAL, &errorCode);

   EXPECT_EQ(RTE_E_RoutineServices_Routine_Service_Alignment_Execution_Start_E_NOT_OK, ret);
   EXPECT_EQ(DCM_E_REQUESTSEQUENCEERROR, errorCode);
}

/* Stop: started -> success branch */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop_Started_ReturnsOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;
   ServiceAlignmentStarted                = CODED_TRUE;

   Std_ReturnType ret = RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop(DCM_INITIAL, &errorCode);

   EXPECT_EQ(RTE_E_OK, ret);
   EXPECT_EQ(DCM_E_POSITIVERESPONSE, errorCode);
}

/* RequestResults: NULL Out_ResData -> outer guard false, returns E_NOT_OK */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults_NullOutResData_ReturnsNotOk)
{
   Dcm_NegativeResponseCodeType errorCode = 0U;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults(DCM_INITIAL, nullptr, &errorCode);

   EXPECT_EQ(RTE_E_RoutineServices_Routine_Service_Alignment_Execution_Start_E_NOT_OK, ret);
}

/* RequestResults: neither started nor stopped -> sequence error branch */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults_NotStartedNorStopped_ReturnsSequenceError)
{
   Dcm_RequestDataOut_Routine_Service_Alignment_Execution_Start_Out_ResDataArrayType outResData[28] = {0U};
   Dcm_NegativeResponseCodeType errorCode                                                           = DCM_E_POSITIVERESPONSE;
   ServiceAlignmentStarted                                                                          = CODED_FALSE;
   ServiceAlignmentStoppedByTester                                                                  = CODED_FALSE;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults(DCM_INITIAL, outResData, &errorCode);

   EXPECT_EQ(RTE_E_RoutineServices_Routine_Service_Alignment_Execution_Start_E_NOT_OK, ret);
   EXPECT_EQ(DCM_E_REQUESTSEQUENCEERROR, errorCode);
}

/* RequestResults: alignment successful -> ProgressPercent forced to 100 */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults_Successful_ReportsProgressComplete)
{
   Dcm_RequestDataOut_Routine_Service_Alignment_Execution_Start_Out_ResDataArrayType outResData[28] = {0U};
   Dcm_NegativeResponseCodeType errorCode                                                           = 0U;
   ServiceAlignmentStarted                                                                          = CODED_TRUE;
   ServiceAlignmentStoppedByTester                                                                  = CODED_FALSE;
   AlignmentService.AlignmentServiceSt                                                              = ALIGNMENT_SUCCESSFUL;
   AlignmentHandler.ProgressPercent                                                                 = 17U;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults(DCM_INITIAL, outResData, &errorCode);

   EXPECT_EQ(RTE_E_OK, ret);
   EXPECT_EQ(ALIGNMENT_PROGRESS_PERCENT_COMPLETE, outResData[2]);
}

/* RequestResults: alignment not successful -> ProgressPercent taken from AlignmentHandler */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults_NotSuccessful_ReportsHandlerProgress)
{
   Dcm_RequestDataOut_Routine_Service_Alignment_Execution_Start_Out_ResDataArrayType outResData[28] = {0U};
   Dcm_NegativeResponseCodeType errorCode                                                           = 0U;
   ServiceAlignmentStarted                                                                          = CODED_TRUE;
   ServiceAlignmentStoppedByTester                                                                  = CODED_FALSE;
   AlignmentService.AlignmentServiceSt                                                              = 0U;
   AlignmentHandler.ProgressPercent                                                                 = 17U;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults(DCM_INITIAL, outResData, &errorCode);

   EXPECT_EQ(RTE_E_OK, ret);
   EXPECT_EQ(17U, outResData[2]);
}

/*===========================================================================*
 * Test Cases: CSCallbackDTCStatusChange_DTCStatusChanged
 *===========================================================================*/

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, CSCallbackDTCStatusChange_DTCStatusChanged_TriggersNvSyncAndReturnsOk)
{
   Std_ReturnType ret = CSCallbackDTCStatusChange_DTCStatusChanged(0x123456U, 0x10U, 0x20U);

   EXPECT_EQ(RTE_E_OK, ret);
   EXPECT_EQ(1u, Dem_RequestNvSynchronization_fake.call_count);
}

/*===========================================================================*
 * Test Cases: SecurityAccess_Unlocked_L1_GetSecurityAttemptCounter / SetSecurityAttemptCounter
 *===========================================================================*/

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SecurityAccess_Unlocked_L1_GetSecurityAttemptCounter_WritesZeroAndReturnsOk)
{
   uint8 attempt_counter = 0xAAu;

   Std_ReturnType ret = SecurityAccess_Unlocked_L1_GetSecurityAttemptCounter(DCM_INITIAL, &attempt_counter);

   EXPECT_EQ(RTE_E_OK, ret);
   EXPECT_EQ(0u, attempt_counter);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, SecurityAccess_Unlocked_L1_SetSecurityAttemptCounter_ReturnsOk)
{
   Std_ReturnType ret = SecurityAccess_Unlocked_L1_SetSecurityAttemptCounter(DCM_INITIAL, 5U);

   EXPECT_EQ(RTE_E_OK, ret);
}

/*===========================================================================*
 * Test Cases: Additional Lock branches (Lock_SensorPosition_Request paths)
 *===========================================================================*/

/* Already-locked branch -> DCM_E_CONDITIONSNOTCORRECT */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_AlreadyLocked_SetsConditionsNotCorrect)
{
   Dcm_StartDataIn_Routine_Pin_Position_Lock_Start_In_ReqDataArrayType inReqData    = {};
   Dcm_StartDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                           = DCM_E_POSITIVERESPONSE;
   CS_ReadNvM_Value_Operation_fake.custom_fake                                      = CS_ReadNvM_Value_set_sensorpos_locked;
   CS_GetError_Status_Operation_fake.custom_fake                                    = CS_GetError_Status_set_nvm_ok;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start(&inReqData, DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_ServiceRequestNotification_E_NOT_OK, ret);
   EXPECT_EQ(DCM_E_CONDITIONSNOTCORRECT, errorCode);
}

/* NVM_REQ_PENDING branch -> DCM_E_GENERALPROGRAMMINGFAILURE */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_NvmPending_SetsGeneralProgrammingFailure)
{
   Dcm_StartDataIn_Routine_Pin_Position_Lock_Start_In_ReqDataArrayType inReqData    = {};
   Dcm_StartDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                           = DCM_E_POSITIVERESPONSE;
   CS_ReadNvM_Value_Operation_fake.custom_fake                                      = CS_ReadNvM_Value_set_sensorpos_unlocked;
   CS_GetError_Status_Operation_fake.custom_fake                                    = CS_GetError_Status_set_nvm_pending;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start(&inReqData, DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_ServiceRequestNotification_E_NOT_OK, ret);
   EXPECT_EQ(DCM_E_GENERALPROGRAMMINGFAILURE, errorCode);
}

/* Requested position != current sensor position -> DCM_E_REQUESTOUTOFRANGE (non-defensive path) */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_MismatchedPosition_SetsRequestOutOfRange)
{
   Dcm_StartDataIn_Routine_Pin_Position_Lock_Start_In_ReqDataArrayType inReqData    = 1U;
   Dcm_StartDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                           = DCM_E_POSITIVERESPONSE;
   CS_ReadNvM_Value_Operation_fake.custom_fake                                      = CS_ReadNvM_Value_set_sensorpos_unlocked;
   CS_GetError_Status_Operation_fake.custom_fake                                    = CS_GetError_Status_set_nvm_ok;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start(&inReqData, DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_ServiceRequestNotification_E_NOT_OK, ret);
   EXPECT_EQ(DCM_E_REQUESTOUTOFRANGE, errorCode);
}

/*===========================================================================*
 * Test Cases: Additional Unlock branches (unlock_SensorPosition_Request paths)
 *===========================================================================*/

/* Already-unlocked branch -> DCM_E_CONDITIONSNOTCORRECT */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_AlreadyUnlocked_SetsConditionsNotCorrect)
{
   Dcm_StartDataIn_Routine_Pin_Position_Unlock_Start_In_ReqDataArrayType inReqData    = {};
   Dcm_StartDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                             = DCM_E_POSITIVERESPONSE;
   CS_ReadNvM_Value_Operation_fake.custom_fake                                        = CS_ReadNvM_Value_set_sensorpos_unlocked;
   CS_GetError_Status_Operation_fake.custom_fake                                      = CS_GetError_Status_set_nvm_ok;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start(&inReqData, DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_ServiceRequestNotification_E_NOT_OK, ret);
   EXPECT_EQ(DCM_E_CONDITIONSNOTCORRECT, errorCode);
}

/* NVM_REQ_PENDING branch -> DCM_E_GENERALPROGRAMMINGFAILURE */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_NvmPending_SetsGeneralProgrammingFailure)
{
   Dcm_StartDataIn_Routine_Pin_Position_Unlock_Start_In_ReqDataArrayType inReqData    = {};
   Dcm_StartDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                             = DCM_E_POSITIVERESPONSE;
   CS_ReadNvM_Value_Operation_fake.custom_fake                                        = CS_ReadNvM_Value_set_sensorpos_locked;
   CS_GetError_Status_Operation_fake.custom_fake                                      = CS_GetError_Status_set_nvm_pending;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start(&inReqData, DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_ServiceRequestNotification_E_NOT_OK, ret);
   EXPECT_EQ(DCM_E_GENERALPROGRAMMINGFAILURE, errorCode);
}

/* Requested position != current sensor position -> DCM_E_REQUESTOUTOFRANGE (non-defensive path) */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_MismatchedPosition_SetsRequestOutOfRange)
{
   Dcm_StartDataIn_Routine_Pin_Position_Unlock_Start_In_ReqDataArrayType inReqData    = 1U;
   Dcm_StartDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                             = DCM_E_POSITIVERESPONSE;
   CS_ReadNvM_Value_Operation_fake.custom_fake                                        = CS_ReadNvM_Value_set_sensorpos_locked;
   CS_GetError_Status_Operation_fake.custom_fake                                      = CS_GetError_Status_set_nvm_ok;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start(&inReqData, DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_ServiceRequestNotification_E_NOT_OK, ret);
   EXPECT_EQ(DCM_E_REQUESTOUTOFRANGE, errorCode);
}

/* NULL In_ReqData / ErrorCode for 0x7005 (Unlock) */
TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_NullInReqData_ReturnsNotOk)
{
   Dcm_StartDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                             = 0U;

   Std_ReturnType ret =
      RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start(nullptr, DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(E_NOT_OK, ret);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite, RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_NullErrorCode_ReturnsNotOk)
{
   Dcm_StartDataIn_Routine_Pin_Position_Unlock_Start_In_ReqDataArrayType inReqData    = {};
   Dcm_StartDataOut_Routine_Pin_Position_Unlock_Start_Out_ResDataArrayType outResData = {};

   Std_ReturnType ret =
      RoutineServices_Routine_0x7005_Pin_Position_Unlock_Start_Start(&inReqData, DCM_INITIAL, &outResData, nullptr);

   EXPECT_EQ(E_NOT_OK, ret);
}

/*===========================================================================*
 * Test Cases: Update_RequestRoutineResults_For_PinPosition_Lock_Unlock branches
 * (exercised indirectly via 0x7004 RequestResults after a successful Start)
 *===========================================================================*/

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults_NvmPending_ReportsInProgress)
{
   Dcm_StartDataIn_Routine_Pin_Position_Lock_Start_In_ReqDataArrayType inReqData      = {};
   Dcm_StartDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType startOutData = {};
   Dcm_RequestDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                             = 0U;
   CS_ReadNvM_Value_Operation_fake.custom_fake                                        = CS_ReadNvM_Value_set_sensorpos_unlocked;
   CS_GetError_Status_Operation_fake.custom_fake                                      = CS_GetError_Status_set_nvm_ok;

   ASSERT_EQ(RTE_E_OK,
             RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start(&inReqData, DCM_INITIAL, &startOutData, &errorCode));

   CS_GetError_Status_Operation_fake.custom_fake = CS_GetError_Status_set_nvm_pending;
   Std_ReturnType ret =
      RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults(DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_OK, ret);
   EXPECT_EQ(RID_STATUS_INPROGRESS, outResData);
}

TEST_F(SWC_CMP_PRJ_UDSHandler_UnitTestSuite,
       RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults_NvmNotOk_ReportsUnsuccessful)
{
   Dcm_StartDataIn_Routine_Pin_Position_Lock_Start_In_ReqDataArrayType inReqData      = {};
   Dcm_StartDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType startOutData = {};
   Dcm_RequestDataOut_Routine_Pin_Position_Lock_Start_Out_ResDataArrayType outResData = {};
   Dcm_NegativeResponseCodeType errorCode                                             = 0U;
   CS_ReadNvM_Value_Operation_fake.custom_fake                                        = CS_ReadNvM_Value_set_sensorpos_unlocked;
   CS_GetError_Status_Operation_fake.custom_fake                                      = CS_GetError_Status_set_nvm_ok;

   ASSERT_EQ(RTE_E_OK,
             RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_Start(&inReqData, DCM_INITIAL, &startOutData, &errorCode));

   CS_GetError_Status_Operation_fake.custom_fake = CS_GetError_Status_set_nvm_not_ok;
   Std_ReturnType ret =
      RoutineServices_Routine_0x7004_Pin_Position_Lock_Start_RequestResults(DCM_INITIAL, &outResData, &errorCode);

   EXPECT_EQ(RTE_E_OK, ret);
   EXPECT_EQ(RID_STATUS_UNSUCCESSFUL, outResData);
}
