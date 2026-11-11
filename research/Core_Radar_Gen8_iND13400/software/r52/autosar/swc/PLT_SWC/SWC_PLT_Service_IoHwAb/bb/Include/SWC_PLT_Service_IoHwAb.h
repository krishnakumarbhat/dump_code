#ifndef SWC_PLT_SERVICE_IOHWAB_H
#define SWC_PLT_SERVICE_IOHWAB_H

/**\file: SWC_PLT_Service_IoHwAb.h
 *
 * Brief description of the file ends at this dot. Detailed decription
 * follows here
 *
 * \b Project:            RNA \n
 * \b Application:        SWC_Service_IoHwAb \n
 * \b Target:             \n
 * \b Compiler:           \n
 * \b Module:             %name:SWC_Service_IoHwAb.h % \n
 * \b File-Revision:      %version:  5 % \n
 * \b Changeable-by-user: Yes \n
 * \b Module-Owner:       %owner:   % \n
 * \b Last-Changed-Date:  %date_modified: Fri Jul 14 05:33:50 2017 % \n
 * \b Classification:     CONFIDENTIAL \n
 * \Requirements
 * \reqtrace
 */

/*============================================================================*\
 *
* Copyright (C) 2021 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *
\*============================================================================*/

/*============================================================================*\
 * PREPROCESSOR DIRECTIVES
\*============================================================================*/

/* INCLUDE DIRECTIVES FOR STANDARD HEADERS -----------------------------------*/

/* INCLUDE DIRECTIVES FOR OTHER HEADERS --------------------------------------*/
#include "Adc.h"
#include "Adc_PBcfg.h"
#include "Rte_Type.h"
#include "reuse.h"
#include "thermal_monitor.h"

#define ADC_MAX_GROUP      (1U)
#define ADC_NUM_CHANNEL    (10U)
#define ADC_CHANNEL_BUFFER ((uint8)ADC_NUM_CHANNEL)
#define ADC_0_GROUP        AdcConf_AdcGroup_AdcGroup
#define BUFFER_ADC0_G0     (&RawAdc_Count_Io[CHANNEL_BOARD_REV])
#define NULL_VALUE         (0U)

#define ADC_BOARD_REV    (0U)
#define ADC_BATT         (1U)
#define ADC_POS_GND_A    (2U)
#define ADC_POS_GND_B    (3U)
#define ADC_IGN          (4U)
#define ADC_POS_GND_D    (5U)
#define ADC_BATT_I_SENSE (6U)
#define ADC_RDI_DETECT   (7U)
#define ADC_POS_GND_C    (8U)
#define ADC_MCU_TEMP     (9U)

#define CHANNEL_BOARD_REV    (0U)
#define CHANNEL_BATT_ADC     (1U)
#define CHANNEL_POS_GND_A    (2U)
#define CHANNEL_POS_GND_B    (3U)
#define CHANNEL_IGN          (4U)
#define CHANNEL_POS_GND_D    (5U)
#define CHANNEL_BATT_I_SENSE (6U)
#define CHANNEL_RDI_DETECT   (7U)
#define CHANNEL_POS_GND_C    (8U)
#define CHANNEL_MCU_TEMP     (9U)

extern Adc_ValueGroupType Adc_Results_Buff[ADC_NUM_CHANNEL];
#define Get_Adc_ValueGroupType(x) (Adc_ValueGroupType *)(&Adc_Results_Buff[x])
#define ADC_Read_Group(x)         Adc_ReadGroup((x), Get_Adc_ValueGroupType((x)))
#define Get_ADC_Counts(x)         Adc_Results_Buff[x]

#define ADC_CH_STS                                                                                                                \
   (*(volatile uint32_t                                                                                                           \
         *)0x88001150U) /* Address of the register which indicates the completion of ADC conversion for all channels */
#define CH_CAPTURE_DONE 0x00000001U
/*============================================================================*\
 * EXPORTED TYPEDEF DECLARATIONS
\*============================================================================*/

/* ENUMS ---------------------------------------------------------------------*/
typedef enum IoHwAb_Adc_PosPin_Hw_Ckt_Tag
{
   Init_EnablePosGndCkt  = 0x01,
   Init_DisablePosGndCkt = 0x02,
   EnablePosGndCkt       = 0x03,
   DisablePosGndCkt      = 0x04
} IoHwAb_Adc_PosPin_Hw_Ckt_T;

typedef enum Channel_Pos_Tag
{
   CHANNEL_POSITION_GND_A = 0,
   CHANNEL_POSITION_GND_B,
   CHANNEL_POSITION_GND_C,
   CHANNEL_POSITION_GND_D,
   CHANNEL_POSITION_GND_MAX
} Channel_Pos_T;

typedef struct Position_Pins_Tag
{
   uint16 pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_MAX];
   boolean pos_gnd_valid[CHANNEL_POSITION_GND_MAX];
} Position_Pins_T;
/*============================================================================*\
 * EXPORTED OBJECT DECLARATIONS
\*============================================================================*/

/*============================================================================*\
 * EXPORTED FUNCTIONS PROTOTYPES
\*============================================================================*/
extern Std_ReturnType IoHwAb_RawAdcCount_Read(Dt_RawAdcData_T *RawAdcData);
extern void IoHwAb_Get_FloatingPinPosition_FaultStatus(uint8 *Status);
extern void IoHwAb_Get_STM_TimeStamp(uint32 *arg);
extern void Init_ADC_Channels(void);
extern void IoHwAb_Adc_Main_5ms(void);
extern void Read_RawADCdata(uint8 Adc_Group, uint16 *BufferPtr);
extern void Hw_Read_Position_Pins(Position_Pins_T *pos_pins);
extern void IoHwAb_ADC_PosPin_Prj_cbk(IoHwAb_Adc_PosPin_Hw_Ckt_T PosPinHwCkt_Control);
extern void Platform_Time_Register_set(uint8 fault_type);
extern uint8_t Adc_Selftest(void);
extern void Read_Sensor_Position_Pins(void);
extern Position_Pins_T *Get_Last_Sensor_Position_Pins(void);
extern void IoHwAb_AdcNotification(void);
extern uint16_t Get_Board_Rev_Cnt(void);
extern bool Check_RDI_Log_Connection(void);
extern bool Get_RDI_Log_Board_Connected(void);
/*============================================================================*\
 * FILE REVISION HISTORY
 *-----------------------------------------------------------------------------
 *
 *  DATE        REV      AID          SCR         TASK
 * SUMMARY OF CHANGES
 *  ---------------------------------------------------------------------------
 * 14-April-25  1.0    Keerthi     EEG-5727    Service_IoHwAb Bringup
 *  ---------------------------------------------------------------------------
\*============================================================================*/

#endif /* #ifndef SWC_PLT_SERVICE_IOHWAB_H */
