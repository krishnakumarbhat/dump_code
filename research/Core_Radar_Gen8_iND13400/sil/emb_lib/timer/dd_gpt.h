#ifndef DD_GPT_H
#define DD_GPT_H
#include "reuse.h"
float32_t Get_Timestamp_ms();
float32_t Get_Elapsed_Time_ms(float32_t starting_timestamp_ms);
uint64_t Get_Timestamp_us();
void Get_Elapsed_ustime(uint32_t *inst_us_time, uint64_t start_time);

#endif // DD_GPT_H
