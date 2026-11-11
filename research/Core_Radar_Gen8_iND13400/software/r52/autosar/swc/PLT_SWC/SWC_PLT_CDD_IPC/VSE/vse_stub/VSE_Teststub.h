#ifndef VSE_TESTSTUB_H
#define VSE_TESTSTUB_H

#include "ipc_data.h"

#define VSE_RAW_INSTANCES 5U /* 50 ms cycle / 10 ms tick */
#define VSE_INPUT_NOISE   1  /* set 0 to emit clean reference inputs */
typedef float float32_t;
/* --- enums (adjust to your project's real definitions) --- */
enum
{
   GEAR_PARK    = 0,
   GEAR_REVERSE = 1,
   GEAR_NEUTRAL = 2,
   GEAR_DRIVE   = 3
};
enum
{
   TURN_NONE   = 0,
   TURN_LEFT   = 1,
   TURN_RIGHT  = 2,
   TURN_HAZARD = 3
};
enum
{
   QF_INVALID = 0,
   QF_VALID   = 3
};

/* --- structs (remove and include vse_stream.h in the real build) --- */

/* per-instant scenario point */
typedef struct
{
   float speed;       /* m/s, negative when reversing */
   float long_accel;  /* m/s^2 */
   float yaw;         /* rad/s */
   float steer_deg;   /* steering wheel angle */
   float steer_speed; /* deg/s */
   float lat_accel;   /* m/s^2 */
   uint8_t gear;
   uint8_t turn;
   uint8_t standstill;
} Scenario_T;

void build_vse_cycle(double t0, volatile Veh_Raw_Data_T *raw, volatile Veh_Raw_Misc_T *misc, volatile Veh_Params_T *veh_params,
                     volatile uint8_t *latest_raw_index);

#endif
