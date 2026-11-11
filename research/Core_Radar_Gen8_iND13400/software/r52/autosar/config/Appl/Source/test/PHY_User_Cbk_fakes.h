/**
 * @file PHY_User_Cbk_fakes.h
 * @brief Fake function declarations for PHY_User_Cbk testing
 */

#ifndef PHY_USER_CBK_FAKES_H
#define PHY_USER_CBK_FAKES_H

#include "fff.h"
#include <stdint.h>

#define SUCCESS            0
#define ERROR              1
#define RTL_TRCV_INDEX     0U
#define OP_CMD_GOTO_NORMAL 1U

// External function declarations
DECLARE_FAKE_VALUE_FUNC(uint16_t, EthTrcv_30_Rtl9010_Internal_WriteTrcvReg, uint8_t, uint8_t, uint16_t);
DECLARE_FAKE_VALUE_FUNC(uint16_t, EthTrcv_30_Rtl9010_Internal_ReadTrcvReg, uint8_t, uint8_t, uint16_t *);
DECLARE_FAKE_VALUE_FUNC(uint16_t, RTL9010x_Set_OP_state, uint16_t);

#endif // PHY_USER_CBK_FAKES_H
