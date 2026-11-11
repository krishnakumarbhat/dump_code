#ifndef CORE0_DSD_UPDATE_H_
#define CORE0_DSD_UPDATE_H_

#include "fixmac.h"
#include "typedefs.h"

#ifndef DSD_OFFSET
   #define DSD_OFFSET (0)
#endif

#define Update_DSD_Cal_Error(dsd_cal_value, core_cal_min, core_cal_max, error_type)                                               \
   do                                                                                                                             \
   {                                                                                                                              \
      ((dsd_cal_value >= core_cal_min) & (dsd_cal_value <= core_cal_max)) ? (0) : (dsd_error_count.##error_type++);               \
   } while (0)

#define CORE0_CONVERT_RAW_TO_PHYS_1_BYTE_UNSIGNED(data, res, off, delphi_res, delphi_offset)                                      \
   CORE0_RAW_TO_PHYS_UNSINGED_ONE_BYTE(data, res, off, delphi_res, delphi_offset)
#define CORE0_CONVERT_RAW_TO_PHYS_2_BYTE_UNSIGNED(data, res, off, delphi_res, delphi_offset)                                      \
   CORE0_RAW_TO_PHYS_UNSINGED_TWO_BYTE(data, res, off, delphi_res, delphi_offset)
#define CORE0_CONVERT_RAW_TO_PHYS_4_BYTE_UNSIGNED(data, res, off, delphi_res, delphi_offset)                                      \
   CORE0_RAW_TO_PHYS_UNSINGED_FOUR_BYTE(data, res, off, delphi_res, delphi_offset)
#define CORE0_CONVERT_RAW_TO_PHYS_1_BYTE_SIGNED(data, res, off, delphi_res, delphi_offset)                                        \
   CORE0_RAW_TO_PHYS_ONE_BYTE(data, res, off, delphi_res, delphi_offset)
#define CORE0_CONVERT_RAW_TO_PHYS_2_BYTE_SIGNED(data, res, off, delphi_res, delphi_offset)                                        \
   CORE0_RAW_TO_PHYS_TWO_BYTE(data, res, off, delphi_res, delphi_offset)
#define CORE0_CONVERT_RAW_TO_PHYS_4_BYTE_SIGNED(data, res, off, delphi_res, delphi_offset)                                        \
   CORE0_RAW_TO_PHYS_FOUR_BYTE(data, res, off, delphi_res, delphi_offset)

float CORE0_RAW_TO_PHYS_ONE_BYTE(signed8_T data, float res, uint8_t offset, float delphi_res, float delphi_offset);
float CORE0_RAW_TO_PHYS_TWO_BYTE(signed16_T data, float res, uint8_t offset, float delphi_res, float delphi_offset);
float CORE0_RAW_TO_PHYS_FOUR_BYTE(signed32_T data, float res, uint8_t offset, float delphi_res, float delphi_offset);
float CORE0_RAW_TO_PHYS_UNSINGED_ONE_BYTE(unsigned8_T data, float res, uint8_t offset, float delphi_res, float delphi_offset);
float CORE0_RAW_TO_PHYS_UNSINGED_TWO_BYTE(unsigned16_T data, float res, uint8_t offset, float delphi_res, float delphi_offset);
float CORE0_RAW_TO_PHYS_UNSINGED_FOUR_BYTE(unsigned32_T data, float res, uint8_t offset, float delphi_res, float delphi_offset);

extern void Update_General_Info_Cal_With_DSD(void);
extern void Update_Core0_Radar_Mounting_Cal_With_DSD(void);
extern void Update_Core0_State_Machine_Cal_With_DSD(void);
extern void Update_Core0_Brightness_Module_Cal_With_DSD(void);

extern void Range_Chk_DSD_General_Info_Cal(void);
extern void Range_Chk_DSD_Radar_Mounting_Cal(void);
extern void Range_Chk_DSD_State_Machine_Cal(void);
extern void Range_Chk_DSD_Brightness_Module_Cal(void);

#endif
