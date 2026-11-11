#include "dd_gpt.h"
#include "emblib_ipc_data.h"

#define OVER_FLOW_TIME_VALUE ((uint64_t)17179869)
#define FLOAT_INFINITY       0x7f800000

float32_t Get_Timestamp_ms()
{
   return Get_IPC_D2M_Buffer()->payload.det_data.stream_hdr.module_time_ms;
}

uint64_t Get_Timestamp_us()
{
   return static_cast<uint64_t>(Get_IPC_D2M_Buffer()->payload.det_data.stream_hdr.module_time_ms) * 1000000ULL;
}

float32_t Get_Elapsed_Time_ms(float32_t starting_timestamp_ms)
{
   float32_t end_time_ms = Get_Timestamp_ms();
   float32_t elapsed_time_ms;

   if (end_time_ms >= starting_timestamp_ms)
   {
      elapsed_time_ms = end_time_ms - starting_timestamp_ms;
   }
   else
   {
      /* Since the ms timer uses float32_t, overflow happens when the timestamp_seconds counter overflows at a value of
         4,294,967,295 4,294,967,295 / (1000 ms/s) / (60 sec/min) / (60 min/hr) / (24 hrs/day) = 4,971 days before overflow,
         or 13.6 years. Therefore, overflow does not need to be handled as it is impratcial that a radar will remain on for 13.6
         years and we return the float value for infinity if for some reason this does happen.
       */
      elapsed_time_ms = FLOAT_INFINITY;
   }

   return elapsed_time_ms;
}

void Get_Elapsed_ustime(uint32_t *inst_us_time, uint64_t start_time)
{
   uint64_t end_time = Get_Timestamp_us();

   if (start_time > end_time)
   {
      /* Wrap-around: timer rolled over at OVER_FLOW_TIME_VALUE microseconds */
      *inst_us_time = (uint32_t)((OVER_FLOW_TIME_VALUE - start_time) + end_time);
   }
   else
   {
      *inst_us_time = (uint32_t)(end_time - start_time);
   }
}
