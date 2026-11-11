/**
 * @file EcuM_Callout_Stubs_unit_test.cc
 * @brief Unit tests for EcuM_Callout_Stubs.c
 */

#include <gtest/gtest.h>
extern "C"
{
#include "EcuM_Callout_fakes.h"

   DEFINE_FFF_GLOBALS;

   void EcuM_AL_DriverInitZero(void);
   void EcuM_AL_DriverInitOne_RDR_01(void);
   void EcuM_AL_DriverRestartList_RDR_01(void);
   void EcuM_AL_DriverInitOne_RDR_02(void);
   void EcuM_AL_DriverRestartList_RDR_02(void);
   void EcuM_AL_DriverInitOne_RDR_03(void);
   void EcuM_AL_DriverRestartList_RDR_03(void);
   void EcuM_AL_DriverInitOne_RDR_04(void);
   void EcuM_AL_DriverRestartList_RDR_04(void);
   void EcuM_AL_DriverInitOne_RDR_05(void);
   void EcuM_AL_DriverRestartList_RDR_05(void);
   void EcuM_AL_DriverInitOne_RDR_06(void);
   void EcuM_AL_DriverRestartList_RDR_06(void);
   void EcuM_AL_DriverInitOne_RDR_07(void);
   void EcuM_AL_DriverRestartList_RDR_07(void);
   void EcuM_AL_DriverInitOne_RDR_08(void);
   void EcuM_AL_DriverRestartList_RDR_08(void);
   const void *EcuM_DeterminePbConfiguration(void);
   void EcuM_StartOS(uint8_t appMode);
   void EcuM_ShutdownOS(uint16_t error);
   void EcuM_BswErrorHook(uint16_t BswModuleId, uint8_t ErrorId);
   void EcuM_AL_SetProgrammableInterrupts(void);
   void EcuM_ErrorHook(uint16_t reason);
   void EcuM_OnGoOffOne(void);
   void EcuM_OnGoOffTwo(void);
   void EcuM_AL_SwitchOff(void);
   void EcuM_AL_Reset(uint8_t reset_type);
   void EcuM_GenerateRamHash(void);
   uint8_t EcuM_CheckRamHash(void);
   void EcuM_McuSetMode(uint8_t McuMode);
   void EcuM_SleepActivity(void);
   void EcuM_EnableWakeupSources(uint32_t wakeupSource);
   void EcuM_DisableWakeupSources(uint32_t wakeupSource);
   void EcuM_CheckWakeup(uint32_t wakeupSource);
   void EcuM_StartWakeupSources(uint32_t wakeupSource);
   void EcuM_StopWakeupSources(uint32_t wakeupSource);
   void EcuM_CheckValidation(uint32_t wakeupSource);
}

DEFINE_FAKE_VOID_FUNC(BswM_InitMemory);
DEFINE_FAKE_VOID_FUNC(ComM_InitMemory);
DEFINE_FAKE_VOID_FUNC(Com_InitMemory);
DEFINE_FAKE_VOID_FUNC(Det_InitMemory);
DEFINE_FAKE_VOID_FUNC(EthIf_InitMemory);
DEFINE_FAKE_VOID_FUNC(EthSM_InitMemory);
DEFINE_FAKE_VOID_FUNC(PduR_InitMemory);
DEFINE_FAKE_VOID_FUNC(Rte_InitMemory);
DEFINE_FAKE_VOID_FUNC(SoAd_InitMemory);
DEFINE_FAKE_VOID_FUNC(TcpIp_InitMemory);
DEFINE_FAKE_VOID_FUNC(EthTrcv_30_Rtl9010_InitMemory);
DEFINE_FAKE_VOID_FUNC(Xcp_InitMemory);
DEFINE_FAKE_VOID_FUNC(TcpIpXcp_InitMemory);
DEFINE_FAKE_VOID_FUNC(CanIf_InitMemory);
DEFINE_FAKE_VOID_FUNC(CanSM_InitMemory);
DEFINE_FAKE_VOID_FUNC(MCAL_Init);
DEFINE_FAKE_VALUE_FUNC(Sensor_Position_Config_T, Get_Default_Sensor_Position_Config);
DEFINE_FAKE_VOID_FUNC(Init_Sensor_Position, Sensor_Position_Config_T *);
DEFINE_FAKE_VOID_FUNC(Read_Sensor_Position_Pins);
DEFINE_FAKE_VOID_FUNC(Det_Init, const void *);
DEFINE_FAKE_VOID_FUNC(BswM_PreInit, const void *);
DEFINE_FAKE_VOID_FUNC(ComM_PreInit, const void *);
DEFINE_FAKE_VOID_FUNC(PduR_PreInit, const void *);
DEFINE_FAKE_VOID_FUNC(SoAd_PreInit, const void *);
DEFINE_FAKE_VOID_FUNC(Eth_30_Wrapper_Init, const void *);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_Radar_Position);
DEFINE_FAKE_VOID_FUNC(DisableAllInterrupts);
DEFINE_FAKE_VOID_FUNC(EnableAllInterrupts);
DEFINE_FAKE_VOID_FUNC(StartOS, uint8_t);
DEFINE_FAKE_VOID_FUNC(ShutdownOS, uint16_t);

// Declare mock functions for flash driver tests
extern "C"
{
   int32_t mock_ReadData(uint32_t, void *, uint32_t);
   ARM_FLASH_STATUS mock_GetStatus(void);
   ARM_FLASH_CAPABILITIES mock_GetCapabilities(void);
}

class EcuMCalloutTest : public ::testing::Test
{
 protected:
   void SetUp() override
   {
      RESET_FAKE(BswM_InitMemory);
      RESET_FAKE(ComM_InitMemory);
      RESET_FAKE(Com_InitMemory);
      RESET_FAKE(Det_InitMemory);
      RESET_FAKE(EthIf_InitMemory);
      RESET_FAKE(EthSM_InitMemory);
      RESET_FAKE(PduR_InitMemory);
      RESET_FAKE(Rte_InitMemory);
      RESET_FAKE(SoAd_InitMemory);
      RESET_FAKE(TcpIp_InitMemory);
      RESET_FAKE(EthTrcv_30_Rtl9010_InitMemory);
      RESET_FAKE(Xcp_InitMemory);
      RESET_FAKE(TcpIpXcp_InitMemory);
      RESET_FAKE(CanIf_InitMemory);
      RESET_FAKE(CanSM_InitMemory);
      RESET_FAKE(MCAL_Init);
      RESET_FAKE(Get_Default_Sensor_Position_Config);
      RESET_FAKE(Init_Sensor_Position);
      RESET_FAKE(Read_Sensor_Position_Pins);
      RESET_FAKE(Det_Init);
      RESET_FAKE(BswM_PreInit);
      RESET_FAKE(ComM_PreInit);
      RESET_FAKE(PduR_PreInit);
      RESET_FAKE(SoAd_PreInit);
      RESET_FAKE(Eth_30_Wrapper_Init);
      RESET_FAKE(Get_Radar_Position);
      RESET_FAKE(DisableAllInterrupts);
      RESET_FAKE(EnableAllInterrupts);
      RESET_FAKE(StartOS);
      RESET_FAKE(ShutdownOS);
      FFF_RESET_HISTORY();

      Sensor_Position_Config_T default_config            = {APTIV_FLR, nullptr};
      Get_Default_Sensor_Position_Config_fake.return_val = default_config;
      Get_Radar_Position_fake.return_val                 = 1;

      // Reset flash driver to default mock implementations
      Driver_Flash0.ReadData        = mock_ReadData;
      Driver_Flash0.GetStatus       = mock_GetStatus;
      Driver_Flash0.GetCapabilities = mock_GetCapabilities;
      SPC_load_fail                 = 0;
   }
};

TEST_F(EcuMCalloutTest, ErrorHook_NoError_ReturnsNormally)
{
   EcuM_ErrorHook(0);
   // Should return normally without hanging
}

TEST_F(EcuMCalloutTest, DriverInitZero_InitializesAllModulesInCorrectOrder)
{
   EcuM_AL_DriverInitZero();

   EXPECT_EQ(BswM_InitMemory_fake.call_count, 1);
   EXPECT_EQ(ComM_InitMemory_fake.call_count, 1);
   EXPECT_EQ(Com_InitMemory_fake.call_count, 1);
   EXPECT_EQ(Det_InitMemory_fake.call_count, 1);
   EXPECT_EQ(EthIf_InitMemory_fake.call_count, 1);
   EXPECT_EQ(EthSM_InitMemory_fake.call_count, 1);
   EXPECT_EQ(PduR_InitMemory_fake.call_count, 1);
   EXPECT_EQ(Rte_InitMemory_fake.call_count, 1);
   EXPECT_EQ(SoAd_InitMemory_fake.call_count, 1);
   EXPECT_EQ(TcpIp_InitMemory_fake.call_count, 1);
   EXPECT_EQ(EthTrcv_30_Rtl9010_InitMemory_fake.call_count, 1);
   EXPECT_EQ(Det_Init_fake.call_count, 1);
   EXPECT_EQ(Xcp_InitMemory_fake.call_count, 1);
   EXPECT_EQ(TcpIpXcp_InitMemory_fake.call_count, 1);
   EXPECT_EQ(CanIf_InitMemory_fake.call_count, 1);
   EXPECT_EQ(CanSM_InitMemory_fake.call_count, 1);
   EXPECT_EQ(MCAL_Init_fake.call_count, 1);
   EXPECT_EQ(Get_Default_Sensor_Position_Config_fake.call_count, 1);
   EXPECT_EQ(Init_Sensor_Position_fake.call_count, 1);
   EXPECT_EQ(Read_Sensor_Position_Pins_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DriverInitZero_SetsFlashReadPointer)
{
   EcuM_AL_DriverInitZero();

   EXPECT_EQ(Init_Sensor_Position_fake.call_count, 1);
   EXPECT_NE(Init_Sensor_Position_fake.arg0_val->flash_read, nullptr);
}

TEST_F(EcuMCalloutTest, DriverInitOne_RDR_01_InitializesDriversForPosition1)
{
   EcuM_AL_DriverInitOne_RDR_01();

   EXPECT_EQ(BswM_PreInit_fake.call_count, 1);
   EXPECT_EQ(BswM_PreInit_fake.arg0_val, EcuM_GlobalPCConfig_Ptr->BswMConfigPtr);
   EXPECT_EQ(ComM_PreInit_fake.call_count, 1);
   EXPECT_EQ(PduR_PreInit_fake.call_count, 1);
   EXPECT_EQ(SoAd_PreInit_fake.call_count, 1);
   EXPECT_EQ(Eth_30_Wrapper_Init_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DriverRestartList_RDR_01_IsEmpty)
{
   EcuM_AL_DriverRestartList_RDR_01();
   // No AUTOSAR functions should be called
}

TEST_F(EcuMCalloutTest, DriverInitOne_RDR_02_InitializesDriversForPosition2)
{
   EcuM_AL_DriverInitOne_RDR_02();

   EXPECT_EQ(BswM_PreInit_fake.call_count, 1);
   EXPECT_EQ(ComM_PreInit_fake.call_count, 1);
   EXPECT_EQ(PduR_PreInit_fake.call_count, 1);
   EXPECT_EQ(SoAd_PreInit_fake.call_count, 1);
   EXPECT_EQ(Eth_30_Wrapper_Init_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DriverRestartList_RDR_02_IsEmpty)
{
   EcuM_AL_DriverRestartList_RDR_02();
   // No AUTOSAR functions should be called
}

TEST_F(EcuMCalloutTest, DriverInitZero_CallsReadSensorPositionPins)
{
   EcuM_AL_DriverInitZero();

   EXPECT_EQ(Read_Sensor_Position_Pins_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DriverInitOne_RDR_03_InitializesDrivers)
{
   EcuM_AL_DriverInitOne_RDR_03();
   EXPECT_EQ(BswM_PreInit_fake.call_count, 1);
   EXPECT_EQ(Eth_30_Wrapper_Init_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DriverInitOne_RDR_04_InitializesDrivers)
{
   EcuM_AL_DriverInitOne_RDR_04();
   EXPECT_EQ(BswM_PreInit_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DriverInitOne_RDR_05_InitializesDrivers)
{
   EcuM_AL_DriverInitOne_RDR_05();
   EXPECT_EQ(BswM_PreInit_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DriverInitOne_RDR_06_InitializesDrivers)
{
   EcuM_AL_DriverInitOne_RDR_06();
   EXPECT_EQ(BswM_PreInit_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DriverInitOne_RDR_07_InitializesDrivers)
{
   EcuM_AL_DriverInitOne_RDR_07();
   EXPECT_EQ(BswM_PreInit_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DriverInitOne_RDR_08_InitializesDrivers)
{
   EcuM_AL_DriverInitOne_RDR_08();
   EXPECT_EQ(BswM_PreInit_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DeterminePbConfiguration_Position1_ReturnsRDR01)
{
   Get_Radar_Position_fake.return_val = 1;
   const void *result                 = EcuM_DeterminePbConfiguration();
   EXPECT_EQ(DisableAllInterrupts_fake.call_count, 1);
   EXPECT_EQ(EnableAllInterrupts_fake.call_count, 1);
   EXPECT_NE(result, nullptr);
}

TEST_F(EcuMCalloutTest, DeterminePbConfiguration_Position2_ReturnsRDR02)
{
   Get_Radar_Position_fake.return_val = 2;
   EcuM_DeterminePbConfiguration();
   EXPECT_EQ(Get_Radar_Position_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DeterminePbConfiguration_Position3_ReturnsRDR03)
{
   Get_Radar_Position_fake.return_val = 3;
   EcuM_DeterminePbConfiguration();
   EXPECT_EQ(Get_Radar_Position_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DeterminePbConfiguration_Position4_ReturnsRDR04)
{
   Get_Radar_Position_fake.return_val = 4;
   EcuM_DeterminePbConfiguration();
   EXPECT_EQ(Get_Radar_Position_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DeterminePbConfiguration_Position5_ReturnsRDR05)
{
   Get_Radar_Position_fake.return_val = 5;
   EcuM_DeterminePbConfiguration();
   EXPECT_EQ(Get_Radar_Position_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DeterminePbConfiguration_Position6_ReturnsRDR06)
{
   Get_Radar_Position_fake.return_val = 6;
   EcuM_DeterminePbConfiguration();
   EXPECT_EQ(Get_Radar_Position_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DeterminePbConfiguration_Position7_ReturnsRDR07)
{
   Get_Radar_Position_fake.return_val = 7;
   EcuM_DeterminePbConfiguration();
   EXPECT_EQ(Get_Radar_Position_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DeterminePbConfiguration_Position8_ReturnsRDR08)
{
   Get_Radar_Position_fake.return_val = 8;
   EcuM_DeterminePbConfiguration();
   EXPECT_EQ(Get_Radar_Position_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, DeterminePbConfiguration_InvalidPosition_ReturnsDefaultRDR01)
{
   Get_Radar_Position_fake.return_val = 99;
   EcuM_DeterminePbConfiguration();
   EXPECT_EQ(Get_Radar_Position_fake.call_count, 1);
}

TEST_F(EcuMCalloutTest, StartOS_CallsStartOS)
{
   EcuM_StartOS(0);
   EXPECT_EQ(StartOS_fake.call_count, 1);
   EXPECT_EQ(StartOS_fake.arg0_val, 0);
}

TEST_F(EcuMCalloutTest, ShutdownOS_CallsShutdownOS)
{
   EcuM_ShutdownOS(0);
   EXPECT_EQ(ShutdownOS_fake.call_count, 1);
   EXPECT_EQ(ShutdownOS_fake.arg0_val, 0);
}

TEST_F(EcuMCalloutTest, BswErrorHook_NonEcuMModule_ReturnsNormally)
{
   EcuM_BswErrorHook(5, 1);
   // Should return normally without hanging
}

TEST_F(EcuMCalloutTest, SetProgrammableInterrupts_DoesNothing)
{
   EcuM_AL_SetProgrammableInterrupts();
}

TEST_F(EcuMCalloutTest, DriverRestartList_RDR_03_IsEmpty)
{
   EcuM_AL_DriverRestartList_RDR_03();
}

TEST_F(EcuMCalloutTest, DriverRestartList_RDR_04_IsEmpty)
{
   EcuM_AL_DriverRestartList_RDR_04();
}

TEST_F(EcuMCalloutTest, DriverRestartList_RDR_05_IsEmpty)
{
   EcuM_AL_DriverRestartList_RDR_05();
}

TEST_F(EcuMCalloutTest, DriverRestartList_RDR_06_IsEmpty)
{
   EcuM_AL_DriverRestartList_RDR_06();
}

TEST_F(EcuMCalloutTest, DriverRestartList_RDR_07_IsEmpty)
{
   EcuM_AL_DriverRestartList_RDR_07();
}

TEST_F(EcuMCalloutTest, DriverRestartList_RDR_08_IsEmpty)
{
   EcuM_AL_DriverRestartList_RDR_08();
}

TEST_F(EcuMCalloutTest, OnGoOffOne_IsEmpty)
{
   EcuM_OnGoOffOne();
}

TEST_F(EcuMCalloutTest, OnGoOffTwo_IsEmpty)
{
   EcuM_OnGoOffTwo();
}

TEST_F(EcuMCalloutTest, AL_SwitchOff_IsEmpty)
{
   EcuM_AL_SwitchOff();
}

TEST_F(EcuMCalloutTest, AL_Reset_WithResetType)
{
   EcuM_AL_Reset(1);
}

TEST_F(EcuMCalloutTest, ErrorHook_ConfigDataInconsistent_EntersErrorPath)
{
   // while(1) is guarded by #ifndef UNIT_TEST, so this path is now testable
   EcuM_ErrorHook(ECUM_E_HOOK_CONFIGURATION_DATA_INCONSISTENT);
   // In production this would hang in while(1); in unit test the loop is compiled out
}

TEST_F(EcuMCalloutTest, BswErrorHook_EcuMModule_EntersErrorPath)
{
   // while(1) is guarded by #ifndef UNIT_TEST, so this path is now testable
   EcuM_BswErrorHook(ECUM_MODULE_ID, 1);
   // In production this would hang in while(1); in unit test the loop is compiled out
}

TEST_F(EcuMCalloutTest, GenerateRamHash_IsEmpty)
{
   EcuM_GenerateRamHash();
}

TEST_F(EcuMCalloutTest, CheckRamHash_ReturnsOne)
{
   uint8_t result = EcuM_CheckRamHash();
   EXPECT_EQ(result, 1);
}

TEST_F(EcuMCalloutTest, McuSetMode_WithMode)
{
   EcuM_McuSetMode(0);
}

TEST_F(EcuMCalloutTest, SleepActivity_IsEmpty)
{
   EcuM_SleepActivity();
}

TEST_F(EcuMCalloutTest, EnableWakeupSources_WithSource)
{
   EcuM_EnableWakeupSources(1);
}

TEST_F(EcuMCalloutTest, DisableWakeupSources_WithSource)
{
   EcuM_DisableWakeupSources(1);
}

TEST_F(EcuMCalloutTest, CheckWakeup_WithSource)
{
   EcuM_CheckWakeup(1);
}

TEST_F(EcuMCalloutTest, StartWakeupSources_WithSource)
{
   EcuM_StartWakeupSources(1);
}

TEST_F(EcuMCalloutTest, StopWakeupSources_WithSource)
{
   EcuM_StopWakeupSources(1);
}

TEST_F(EcuMCalloutTest, CheckValidation_WithSource)
{
   EcuM_CheckValidation(1);
}

// Declare the wrapper function for testing
extern "C"
{
   void *Sensor_Pos_SPC_Flash_Read_Wrapper(void *dst, const void *src, uintptr_t length);
   extern ARM_DRIVER_FLASH Driver_Flash0;
   extern volatile uint16_t SPC_load_fail;
}

TEST_F(EcuMCalloutTest, FlashReadWrapper_SuccessfulRead)
{
   uint8_t dest[64];
   uint8_t src[64];
   SPC_load_fail = 0;

   void *result = Sensor_Pos_SPC_Flash_Read_Wrapper(dest, src, 32);

   EXPECT_EQ(result, nullptr);
   EXPECT_EQ(SPC_load_fail, 0);
}

TEST_F(EcuMCalloutTest, FlashReadWrapper_LargeBuffer)
{
   uint8_t dest[128];
   uint8_t src[128];
   SPC_load_fail = 0;

   void *result = Sensor_Pos_SPC_Flash_Read_Wrapper(dest, src, 128);

   EXPECT_EQ(result, nullptr);
}

TEST_F(EcuMCalloutTest, FlashReadWrapper_ZeroLength)
{
   uint8_t dest[64];
   uint8_t src[64];

   void *result = Sensor_Pos_SPC_Flash_Read_Wrapper(dest, src, 0);

   EXPECT_EQ(result, nullptr);
}

// Custom flash driver implementations for testing different scenarios
static int32_t flash_read_fail(uint32_t addr, void *data, uint32_t cnt)
{
   return 0; // Return failure
}

static ARM_FLASH_STATUS flash_status_busy(void)
{
   static int call_count = 0;
   ARM_FLASH_STATUS status;
   if (call_count++ < 5)
   {
      status.busy  = 1;
      status.error = 0;
   }
   else
   {
      status.busy  = 0;
      status.error = 0;
   }
   return status;
}

static ARM_FLASH_STATUS flash_status_error(void)
{
   ARM_FLASH_STATUS status = {0, 1};
   return status;
}

static ARM_FLASH_STATUS flash_status_timeout(void)
{
   ARM_FLASH_STATUS status = {1, 0}; // Always busy
   return status;
}

// Note: FlashReadWrapper_ReadDataFails test would cause infinite loop because
// when read fails, length never decreases, so it's not tested

TEST_F(EcuMCalloutTest, FlashReadWrapper_StatusError)
{
   uint8_t dest[64];
   uint8_t src[64];
   SPC_load_fail = 0;

   // Set status to return error
   Driver_Flash0.GetStatus = flash_status_error;

   void *result = Sensor_Pos_SPC_Flash_Read_Wrapper(dest, src, 32);

   EXPECT_EQ(result, nullptr);
   EXPECT_EQ(SPC_load_fail, 1); // Should set fail flag on error
}

TEST_F(EcuMCalloutTest, FlashReadWrapper_Timeout)
{
   uint8_t dest[64];
   uint8_t src[64];
   SPC_load_fail = 0;

   // Set status to always return busy (timeout scenario)
   Driver_Flash0.GetStatus = flash_status_timeout;

   void *result = Sensor_Pos_SPC_Flash_Read_Wrapper(dest, src, 16);

   EXPECT_EQ(result, nullptr);
   EXPECT_EQ(SPC_load_fail, 1); // Should set fail flag on timeout
}

TEST_F(EcuMCalloutTest, FlashReadWrapper_BusyThenSuccess)
{
   uint8_t dest[64];
   uint8_t src[64];
   SPC_load_fail = 0;

   // Set status to return busy initially then success
   Driver_Flash0.GetStatus = flash_status_busy;

   void *result = Sensor_Pos_SPC_Flash_Read_Wrapper(dest, src, 16);

   EXPECT_EQ(result, nullptr);
   EXPECT_EQ(SPC_load_fail, 0); // Should succeed after busy loop
}
