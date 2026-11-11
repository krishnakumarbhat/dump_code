/**
 * @file Mipi_wrapper_fake.h
 *
 * Stubs and fakes for external functions used by Mipi_wrapper.c
 */
#ifndef MIPI_WRAPPER_FAKE_H_
#define MIPI_WRAPPER_FAKE_H_

#include "fff.h"
#include <stdbool.h>
#include <stdint.h>

/* Include AUTOSAR I2C types early so fakes can use them */
#include "I2c_Types.h"

#ifdef __cplusplus
extern "C"
{
#endif

   /*===========================================================================*
    * Type stubs for hardware-specific types
    *===========================================================================*/

   /* Board revision stubs */
   typedef enum Board_Revision_Tag
   {
      BOARD_REV_EDU  = 0U,
      BOARD_REV_A0   = 1U,
      BOARD_REV_A2P0 = 2U,
      BOARD_REV_A2P1 = 3U,
      BOARD_REV_MAX
   } Board_Revision_T;

   /* I2C types (I2c_StatusType, I2c_StatusType) provided by AUTOSAR I2c_Types.h */
   /* which is included above */

   /* AUTOSAR standard return type */
   typedef uint8_t Std_ReturnType;

   /* ARM CMSIS Port driver stub */
   typedef int32_t (*ARM_Port_SetMode_func)(uint32_t port, uint32_t mode, uint32_t cfg);

   typedef struct ARM_DRIVER_PORT_tag
   {
      ARM_Port_SetMode_func SetMode;
   } ARM_DRIVER_PORT;

/* ARM_PORT constants */
#define ARM_PORT_A1A6       (20U)
#define ARM_PORT_A1A7       (21U)
#define ARM_PORT_A1B6       (22U)
#define ARM_PORT_A1B7       (23U)
#define ARM_PIN_MODE_DIO    (0U)
#define ARM_PORT_CFG_INPUT  (0U)
#define ARM_PORT_CFG_OUTPUT (1U)

/* reuse.h stubs */
#ifndef CODED_FALSE
   #define CODED_FALSE (0U)
#endif
#ifndef CODED_TRUE
   #define CODED_TRUE (1U)
#endif

   /* Fake board revision functions */
   DECLARE_FAKE_VALUE_FUNC(Board_Revision_T, Get_Board_Revision);
   DECLARE_FAKE_VALUE_FUNC(bool, Get_RDI_Log_Board_Connected);

   /* Fake I2C functions - AUTOSAR I2c driver */
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, I2c_MasterTransmit, uint32_t, uint8_t *, uint8_t, boolean);
   DECLARE_FAKE_VOID_FUNC(I2c_MainFunction);
   DECLARE_FAKE_VALUE_FUNC(I2c_StatusType, I2c_GetStatus);

   /* Old I2C functions (may not be used) */
   DECLARE_FAKE_VALUE_FUNC(I2c_StatusType, I2c_Write_Data, uint32_t, uint8_t, uint8_t *, uint32_t);
   DECLARE_FAKE_VALUE_FUNC(I2c_StatusType, I2c_Receive_Data, uint32_t, uint8_t *, uint32_t);

   /* Fake ARM Port SetMode */
   DECLARE_FAKE_VALUE_FUNC(int32_t, Stub_SetMode, uint32_t, uint32_t, uint32_t);

   /* External Port driver (stubbed) */
   extern ARM_DRIVER_PORT Driver_Port0;

#ifdef __cplusplus
}
#endif

#endif /* MIPI_WRAPPER_FAKE_H_ */
