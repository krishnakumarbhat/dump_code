#include "Mipi_wrapper_fake.h"

DEFINE_FAKE_VALUE_FUNC(Board_Revision_T, Get_Board_Revision);
DEFINE_FAKE_VALUE_FUNC(bool, Get_RDI_Log_Board_Connected);

/* AUTOSAR I2c driver fakes */
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, I2c_MasterTransmit, uint32_t, uint8_t *, uint8_t, boolean);
DEFINE_FAKE_VOID_FUNC(I2c_MainFunction);
DEFINE_FAKE_VALUE_FUNC(I2c_StatusType, I2c_GetStatus);

/* Old I2C fakes (may not be used) */
DEFINE_FAKE_VALUE_FUNC(I2c_StatusType, I2c_Write_Data, uint32_t, uint8_t, uint8_t *, uint32_t);
DEFINE_FAKE_VALUE_FUNC(I2c_StatusType, I2c_Receive_Data, uint32_t, uint8_t *, uint32_t);

DEFINE_FAKE_VALUE_FUNC(int32_t, Stub_SetMode, uint32_t, uint32_t, uint32_t);

/* Provide the stubbed Driver_Port0 with function pointer */
ARM_DRIVER_PORT Driver_Port0 = {
   .SetMode = Stub_SetMode,
};
