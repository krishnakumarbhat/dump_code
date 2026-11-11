#ifndef CDC_STREAM_COMBINED_H
#define CDC_STREAM_COMBINED_H

#include "cdc_stream.h"
#include "spbb_cfg.h"

#define MAX_NO_CDC_CHUNKS (uint32_t)(SPBB_MAX_CDC_DBIN_COUNT_PER_FRAME / TOTAL_CDC_RECORDS_PER_FRAME)

typedef struct CDC_Stream_Combined_Tag /*Offset Start byte of the Structure CDC_Stream is 64 bytes*/
{
   CDC_Stream_T cdc_stream[MAX_NO_CDC_CHUNKS];
} CDC_Stream_Combined_T;

#endif // CDC_STREAM_COMBINED_H
