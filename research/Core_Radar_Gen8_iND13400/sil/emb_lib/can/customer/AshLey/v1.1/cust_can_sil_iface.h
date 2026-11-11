#ifndef CUST_CAN_SIL_IFACE_H
#define CUST_CAN_SIL_IFACE_H

#include "fixmac.h"
#include "output_control.h"
#define MAX_FLR_DETECTIONS      400
#define CAN_SIG_NOT_IMPLEMENTED 0 // not updated by sw

#define TS_GLOBAL_TIME_OUT  (0x01u)
#define TS_GLOBAL_TIME_BASE (0x08u)

// feature function specific
#define COLLISION_WARNING_ACTIVE           5U
#define SYSTEM_READY_ACTIVATED             3U
#define NO_RELEVANT_OBJECT_MONITORED       0U
#define SINGLE_RELEVANT_OBJECT_MONITORED   1U
#define MULTIPLE_RELEVANT_OBJECT_MONITORED 2U
#define WRNG_RLVNT_OBJ_DETD_RESERVED       4U
#define BSD_PRBLTY_MSTIMP_OBJ_NOT_AVAIL    7U

void can_data_write(unsigned long long timestamp);

float32_t FXP2FLP_Fnc(int32_t value, int32_t bpp_num, bool signed_flag);

#endif // CUST_CAN_SIL_IFACE_H
