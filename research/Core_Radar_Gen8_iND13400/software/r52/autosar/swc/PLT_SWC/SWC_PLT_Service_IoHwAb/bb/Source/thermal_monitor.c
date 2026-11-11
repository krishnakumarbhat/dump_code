/*===========================================================================*\
 * FILE: thermal_monitor.c
 *===========================================================================
 * Copyright (C) 2021 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * %full_filespec:  thermal_monitor.c~3:csrc:kok_css2#129 %
 * %version:  1 %
 * %derived_by:  pzbdxm %
 * %date_modified:  Mon Aug  1 15:55:28 2016 %
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains code which realizes the Thermal Monitoring of the micro
 *
 * ABBREVIATIONS:
 *   TMU - Thermal Monitoring Unit
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *   Requirements Document(s):
 *   (Design & Requirements)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN - "Aptiv C Coding Standards"
 *
 * DEVIATIONS FROM STANDARDS:
 *   None
 *
\*===========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "thermal_monitor.h"
#include "SWC_PLT_CDD_FailSafe.h"
#include "reuse.h"
#include "vstdlib.h"
/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Local Preprocessor #define MACROS
\*===========================================================================*/
#define DEG_C_2_DEG_F(temp)             (((temp)*9.0f / 5.0f) + 32.0f)
#define PVT_DEVIATION_THRESHOLD_DEG_C   (10.0f) /* 10 degree C deviation threshold */
#define PVT_CONSECUTIVE_CYCLE_LIMIT     (3U)    /* Number of consecutive cycles before reset */
#define PVT_TEMPERATURE_DEVIATION_RESET (84U)   /* Reset reason code for PVT temperature deviation */
/*===========================================================================*\
 * Local Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Local Object Definitions
\*===========================================================================*/

/*===========================================================================*\
* External Object Declarations
\*===========================================================================*/
#if (ENABLE_SQT_TEST_STUBS == TRUE)
extern void Thermal_Monitor_TestManager(void);
volatile uint8 Test_Stub_PVT_Temp_Deviation;
#endif
/*===========================================================================*\
 * File Scope Variables
\*===========================================================================*/
const float32 PVT_Coeff_a4                   = -9.2627e-12f;
const float32 PVT_Coeff_a3                   = 6.0373e-08f;
const float32 PVT_Coeff_a2                   = -1.7058e-04f;
const float32 PVT_Coeff_a1                   = 3.2512e-01f;
const float32 PVT_Coeff_a0                   = -4.9002e+01f;
static uint8 PVT_Deviation_Consecutive_Count = 0U;
/*===========================================================================*\
* Local Function Prototypes
\*===========================================================================*/
static void Read_PVT_Temperature_Values(PVT_Temp_Celsius_T *PVT_Temperature_C);
static void PVT_Convert_To_Celsius(PVT_Temperatures_T *Raw_Temp_Value, PVT_Temp_Celsius_T *PVT_Temp_Celsius);
static void Check_PVT_Temperature_Deviation(const PVT_Temp_Celsius_T *PVT_Temp_C);
static void Configure_PVT_Trim_Values(PVT_Measurement_Sites_T pvt_site);
/*===========================================================================*\
* Exported Function Prototypes
\*===========================================================================*/

/*===========================================================================*\
 * Local Inline Function Definitions and Function-Like Macros
\*===========================================================================*/

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/
/*****************************************************************************
 *. Name: PVT_Monitoring_Init
 *. This function initializes the PVT (Process, Voltage, Temperature) monitoring
 *. peripherals (PVT0 and PVT1) for thermal monitoring of the microcontroller.
 *.
 *. Parameters: void
 *.
 *. Return Value: None.
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
void PVT_Monitoring_Init(void)
{
   /************ PVT0 peripheral configuration ************/

   /* Clear the SFR fields CTL_PVT0_PSAMPLE and CTL_PVT0_VSAMPLE of register PVT0_CTRL1 by setting them to 0x0 */
   PVT0_CTRL1_ADDR &= ~(PVT0_PSAMPLE_Msk | PVT0_VSAMPLE_Msk);

   /* Configure PVT trim Gain and Offset values */
   Configure_PVT_Trim_Values(PVT0);

   /* Set length */
   PVT0_CTRL3_ADDR |= (CTRL_PVT0_ACC_LEN << CTL_PVT0_ACC_LEN_OFFSET);

   /* Set Threshold */
   PVT0_CTRL4_ADDR = CTRL_PVT0_ALARM0_THR * CTRL_PVT0_ACC_LEN;
   PVT0_CTRL4_ADDR |= ((CTRL_PVT0_ALARM1_THR * CTRL_PVT0_ACC_LEN) << CTL_PVT0_ALARM1_THR_OFFSET);

   /* Enable Alarm0 and Alarm1 */
   PVT0_CTRL3_ADDR |= CTRL_PVT0_ALARM0_ACC;
   PVT0_CTRL3_ADDR |= CTRL_PVT0_ALARM1_ACC;

   /* Enable interrupts for signal trigger */
   PVT0_IRQ_CTRL_ADDR |= CTRL_PVT0_ALARM_ENA;
   PVT0_IRQ_CTRL_ADDR |= CTRL_PVT0_SIG_ENA;

   /* Enable Clock and Run */
   PVT0_CTRL0_ADDR |= CTRL_PVT0_CK_EN;
   PVT0_CTRL0_ADDR |= CTRL_PVT0_RUN;

   /************ PVT1 peripheral configuration ************/

   /* Clear the SFR fields CTL_PVT0_PSAMPLE and CTL_PVT0_VSAMPLE of register PVT0_CTRL1 by setting them to 0x0 */
   PVT1_CTRL1_ADDR &= ~(PVT1_PSAMPLE_Msk | PVT1_VSAMPLE_Msk);

   /* Configure PVT trim Gain and Offset values */
   Configure_PVT_Trim_Values(PVT1);

   /* Set length */
   PVT1_CTRL3_ADDR |= (CTRL_PVT1_ACC_LEN << CTL_PVT1_ACC_LEN_OFFSET);

   /* Set Threshold */
   PVT1_CTRL4_ADDR = CTRL_PVT1_ALARM0_THR * CTRL_PVT1_ACC_LEN;
   PVT1_CTRL4_ADDR |= ((CTRL_PVT1_ALARM1_THR * CTRL_PVT1_ACC_LEN) << CTL_PVT1_ALARM1_THR_OFFSET);

   /* Enable Alarm0 and Alarm1 */
   PVT1_CTRL3_ADDR |= CTRL_PVT1_ALARM0_ACC;
   PVT1_CTRL3_ADDR |= CTRL_PVT1_ALARM1_ACC;

   /* Enable interrupts for signal trigger */
   PVT1_IRQ_CTRL_ADDR |= CTRL_PVT1_ALARM_ENA;
   PVT1_IRQ_CTRL_ADDR |= CTRL_PVT1_SIG_ENA;

   /* Enable Clock and Run */
   PVT1_CTRL0_ADDR |= CTRL_PVT1_CK_EN;
   PVT1_CTRL0_ADDR |= CTRL_PVT1_RUN;
}

/*****************************************************************************
 *. Name: Configure_PVT_Trim_Values
 *. This function check the pvt site and based on the PLT Trim flag,
 *. it configures the trim gain and offset values for the PVT.
 *.
 *. Parameters: PVT_Measurement_Sites_T pvt_site
 *.
 *. Return Value: None.
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
static void Configure_PVT_Trim_Values(PVT_Measurement_Sites_T pvt_site)
{
   uint32 sys_ctrl_pvt_trim;
   uint32 pvt_trimg;
   uint32 pvt_trimo;

   pvt_trimg = DEFAULT_TRIMG_VALUE;
   pvt_trimo = DEFAULT_TRIMO_VALUE;

   sys_ctrl_pvt_trim = OTP_PVT_TRIM_ADDR;

   if (pvt_site == PVT0)
   {
      /* Check the PVT0 trim flag */
      if ((sys_ctrl_pvt_trim & SYS_CTRL_PVT0_TRIM_FLAG_Msk) != 0UL)
      {
         /* if trim flag is set then read the trim - and gain value from OTP address */
         pvt_trimg = (sys_ctrl_pvt_trim & SYS_CTRL_PVT0_TRIMG_Msk) >> SYS_CTRL_PVT0_TRIMG_Pos;
         pvt_trimo = (sys_ctrl_pvt_trim & SYS_CTRL_PVT0_TRIMO_Msk) >> SYS_CTRL_PVT0_TRIMO_Pos;
      }

      /* configure the trim values */
      PVT0_CTRL1_ADDR |= CTRL_PVT0_TRIMG(pvt_trimg);
      PVT0_CTRL1_ADDR |= CTRL_PVT0_TRIMO(pvt_trimo);
   }
   else if (pvt_site == PVT1)
   {
      /* Check the PVT0 trim flag */
      if ((sys_ctrl_pvt_trim & SYS_CTRL_PVT1_TRIM_FLAG_Msk) != 0UL)
      {
         /* if trim flag is set then read the trim offset and gain value from OTP address */
         pvt_trimg = (sys_ctrl_pvt_trim & SYS_CTRL_PVT1_TRIMG_Msk) >> SYS_CTRL_PVT1_TRIMG_Pos;
         pvt_trimo = (sys_ctrl_pvt_trim & SYS_CTRL_PVT1_TRIMO_Msk) >> SYS_CTRL_PVT1_TRIMO_Pos;
      }

      /* configure the trim values */
      PVT1_CTRL1_ADDR |= CTRL_PVT1_TRIMG(pvt_trimg);
      PVT1_CTRL1_ADDR |= CTRL_PVT1_TRIMO(pvt_trimo);
   }
}
/*****************************************************************************
 *. Name: Read_PVT_Temperature_Values
 *. This function reads the instantaneous and average temperature values from
 *. the TMU PVT peripherals and stores them in the structure Pvt_Temp.
 *.
 *. Parameters: void
 *.
 *. Return Value: None.
 *.
 *. Shared Variables: Pvt_Temp
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 ******************************************************************************/
static void Read_PVT_Temperature_Values(PVT_Temp_Celsius_T *PVT_Temperature_C)
{
   uint32_t pvt0_accumlated_temp;
   uint32_t pvt1_accumlated_temp;
   PVT_Temperatures_T Pvt_Temp;

   Pvt_Temp.PVT0_Inst_Temp_Raw_Value = PVT0_STAT0_ADDR & STS_PVT0_DOUT_INS_MASK;
   Pvt_Temp.PVT1_Inst_Temp_Raw_Value = PVT1_STAT0_ADDR & STS_PVT1_DOUT_INS_MASK;

   pvt0_accumlated_temp             = PVT0_STAT1_ADDR & STS_PVT0_DOUT_ACC_MASK;
   pvt1_accumlated_temp             = PVT1_STAT1_ADDR & STS_PVT1_DOUT_ACC_MASK;
   Pvt_Temp.PVT0_Avg_Temp_raw_Value = pvt0_accumlated_temp / CTRL_PVT0_ACC_LEN;
   Pvt_Temp.PVT1_Avg_Temp_raw_Value = pvt1_accumlated_temp / CTRL_PVT1_ACC_LEN;

   PVT_Convert_To_Celsius(&Pvt_Temp, PVT_Temperature_C);
}
/*****************************************************************************
 *. Name: PVT_Convert_To_Celsius
 *. This function converts the raw PVT temperature values to Celsius using
 *. a polynomial conversion formula.
 *.
 *. Parameters: PVT_Temperatures_T *Raw_Temp_Value
 *.             PVT_Temp_Celsius_T *PVT_Temp_Celsius
 *.
 *. Return Value: None.
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 ******************************************************************************/
static void PVT_Convert_To_Celsius(PVT_Temperatures_T *Raw_Temp_Value, PVT_Temp_Celsius_T *PVT_Temp_Celsius)
{
   float32 raw_value[4];
   uint8_t index;
   float32 temp_c[4];

   raw_value[0] = (float32)Raw_Temp_Value->PVT0_Inst_Temp_Raw_Value;
   raw_value[1] = (float32)Raw_Temp_Value->PVT1_Inst_Temp_Raw_Value;
   raw_value[2] = (float32)Raw_Temp_Value->PVT0_Avg_Temp_raw_Value;
   raw_value[3] = (float32)Raw_Temp_Value->PVT1_Avg_Temp_raw_Value;

   for (index = (uint8)PVT0_INST; index < (uint8)PVT_MAX; index++)
   {
      /* Formula(Horner's method) to convert into celsius */
      temp_c[index] =
         (((PVT_Coeff_a4 * raw_value[index] + PVT_Coeff_a3) * raw_value[index] + PVT_Coeff_a2) * raw_value[index] + PVT_Coeff_a1) *
            raw_value[index] +
         PVT_Coeff_a0;
   }
   PVT_Temp_Celsius->PVT0_Inst_Temp_Value_C = temp_c[0];
   PVT_Temp_Celsius->PVT1_Inst_Temp_Value_C = temp_c[1];
   PVT_Temp_Celsius->PVT0_Avg_Temp_Value_C  = temp_c[2];
   PVT_Temp_Celsius->PVT1_Avg_Temp_Value_C  = temp_c[3];
}
/*****************************************************************************
 *. Name: Check_PVT_Temperature_Deviation
 *. This function checks if PVT0 and PVT1 temperature readings deviate from
 *. each other by more than 10 degrees Celsius. If the deviation persists for
 *. 3 consecutive radar cycles, it triggers an MCU reset by calling
 *. FailSafe_Log_ResetReason.
 *.
 *. Parameters: const PVT_Temp_Celsius_T *PVT_Temp_C - Pointer to temperature values
 *.
 *. Return Value: None.
 *.
 *. Shared Variables: PVT_Deviation_Consecutive_Count
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 ******************************************************************************/
static void Check_PVT_Temperature_Deviation(const PVT_Temp_Celsius_T *PVT_Temp_C)
{
   float32 pvt0_temp;
   float32 pvt1_temp;
   float32 temp_difference;
   boolean is_deviation_exceeded;

   pvt0_temp = PVT_Temp_C->PVT0_Avg_Temp_Value_C;
   pvt1_temp = PVT_Temp_C->PVT1_Avg_Temp_Value_C;

#if (ENABLE_SQT_TEST_STUBS == TRUE)
   /* SQT Test: Override temperatures to simulate >10 degree C deviation */
   /* PVT STAT registers are read-only hardware registers, so we override here */
   if (Test_Stub_PVT_Temp_Deviation == 1U)
   {
      pvt0_temp = 50.0f; /* Force PVT0 to 50 degree C */
      pvt1_temp = 30.0f; /* Force PVT1 to 30 degree C, deviation = 20 degree C */
   }
#endif

   /* Calculate absolute difference between PVT0 and PVT1 temperatures */
   if (pvt0_temp >= pvt1_temp)
   {
      temp_difference = pvt0_temp - pvt1_temp;
   }
   else
   {
      temp_difference = pvt1_temp - pvt0_temp;
   }

   /* Check if deviation exceeds 10 degree C threshold */
   is_deviation_exceeded = (temp_difference > PVT_DEVIATION_THRESHOLD_DEG_C) ? TRUE : FALSE;

   if (is_deviation_exceeded)
   {
      /* Deviation exceeds 10 degree C threshold, increment consecutive counter */
      if (PVT_Deviation_Consecutive_Count < 255U)
      {
         PVT_Deviation_Consecutive_Count++;
      }
      /* Check if deviation persisted for 3 consecutive radar cycles */
      if (PVT_Deviation_Consecutive_Count >= PVT_CONSECUTIVE_CYCLE_LIMIT)
      {
         FailSafe_Log_ResetReason(PVT_TEMPERATURE_DEVIATION_RESET);
      }
   }
   else
   {
      /* Deviation within acceptable range, reset consecutive counter */
      PVT_Deviation_Consecutive_Count = 0U;
   }
}
/*****************************************************************************
 *. Name: Update_Thermal_Monitor_Values
 *. This function updates the thermal monitor measurement results structure
 *. with the latest temperature readings from the PVT peripherals.
 *.
 *. Parameters: DT_Thermal_mon_mes_results_T *therm_mon_results
 *.
 *. Return Value: None.
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 ******************************************************************************/
void Update_Thermal_Monitor_Values(DT_Thermal_mon_mes_results_T *therm_mon_results)
{
   PVT_Temp_Celsius_T PVT_Temp_C;
   uint8 site_idx;
   static DT_Thermal_mon_mes_results_T Thermal_Monitor_Measurements = {{{0.0f}}, {{0.0f}}, {{0.0f}}, {{0.0f}}, {{0.0f}}, {{0.0f}}};

#if (ENABLE_SQT_TEST_STUBS == TRUE)
   /* Call SQT Test Manager to execute any active tests */
   Thermal_Monitor_TestManager();
#endif

   Read_PVT_Temperature_Values(&PVT_Temp_C);
   Check_PVT_Temperature_Deviation(&PVT_Temp_C);

   for (site_idx = (uint8)PVT0; (site_idx < (uint8)MAX_PVT) && (site_idx < 2U); site_idx++)
   {
      if (site_idx == (uint8)PVT0)
      {
         Thermal_Monitor_Measurements.immediate_temp_c.temperature[site_idx] = PVT_Temp_C.PVT0_Inst_Temp_Value_C;
         Thermal_Monitor_Measurements.immediate_temp_f.temperature[site_idx] =
            DEG_C_2_DEG_F(Thermal_Monitor_Measurements.immediate_temp_c.temperature[site_idx]);

         Thermal_Monitor_Measurements.average_temp_c.temperature[site_idx] = PVT_Temp_C.PVT0_Avg_Temp_Value_C;
         Thermal_Monitor_Measurements.average_temp_f.temperature[site_idx] =
            DEG_C_2_DEG_F(Thermal_Monitor_Measurements.average_temp_c.temperature[site_idx]);
      }
      else
      {
         Thermal_Monitor_Measurements.immediate_temp_c.temperature[site_idx] = PVT_Temp_C.PVT1_Inst_Temp_Value_C;
         Thermal_Monitor_Measurements.immediate_temp_f.temperature[site_idx] =
            DEG_C_2_DEG_F(Thermal_Monitor_Measurements.immediate_temp_c.temperature[site_idx]);

         Thermal_Monitor_Measurements.average_temp_c.temperature[site_idx] = PVT_Temp_C.PVT1_Avg_Temp_Value_C;
         Thermal_Monitor_Measurements.average_temp_f.temperature[site_idx] =
            DEG_C_2_DEG_F(Thermal_Monitor_Measurements.average_temp_c.temperature[site_idx]);
      }
   }
   (void)VStdMemCpy((void *)therm_mon_results, (void *)&Thermal_Monitor_Measurements, sizeof(Thermal_Monitor_Measurements));
}
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 *  Date      Name               (Description on following lines: SCR #, etc.)
 * --------   -----              ---------------------------------------------
 * 20/01/2026 Sathvika           Implemented PVT monitoring
\*===========================================================================*/
