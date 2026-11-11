#ifndef VSE_CORE_H
#define VSE_CORE_H

#include "ipc_data.h"
#include "ipc_mss.h"
#include "vse_stream.h"

#ifdef __cplusplus
extern "C"
{
#endif

   void Run_VSE(volatile M2D_Msg_T *p_ipc_m2d);

#ifdef __cplusplus
}
#endif

enum Radar_Positions
{
   UNKNOWN_POSITION       = 0U,
   RADAR_POS_REAR_LEFT    = 1U,
   RADAR_POS_REAR_RIGHT   = 2U,
   RADAR_POS_FRONT_RIGHT  = 3U,
   RADAR_POS_FRONT_LEFT   = 4U,
   RADAR_POS_FRONT_CENTER = 5U,
   RADAR_POS_REAR_CENTER  = 6U,
   RADAR_POS_RIGHT_CENTER = 7U,
   RADAR_POS_LEFT_CENTER  = 8U,
   INVALID_POSITION       = 9U,
};
#endif
