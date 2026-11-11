/**
 * @file PHY_User_Cbk_wrapper.c
 * @brief Wrapper for PHY_User_Cbk.c with testable callback functions
 */

#include "PHY_User_Cbk_fakes.h"

#line 1 "software/r52/autosar/config/Appl/Source/PHY_User_Cbk.c"
void RTL_PHY_Pre_Init(uint8_t TrcvIdx)
{
   uint16_t result = RTL9010x_Set_OP_state(OP_CMD_GOTO_NORMAL);
   (void)result;
}

void RTL_PHY_Post_Init(uint8_t TrcvIdx)
{
   // Empty - all operations commented out in original
}
