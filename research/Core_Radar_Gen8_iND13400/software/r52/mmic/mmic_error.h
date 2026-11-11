#ifndef MMIC_ERROR_H
   #define MMIC_ERROR_H
   /*===========================================================================*\
    * FILE: mmic_error.h
    *===========================================================================
    * Copyright 2024 APTIV, All Rights Reserved.
    * APTIV Confidential
    *---------------------------------------------------------------------------
    *
    * DESCRIPTION:
    * This module tracks and reports errors related to the MMIC device drivers.
    *
    * ABBREVIATIONS:
    *
    * TRACEABILITY INFO:
    *   Design Document(s):
    *
    *   Requirements Document(s):
    *
    *   Applicable Standards (in order of precedence: highest first):
    *   1. C Coding Standards SW REF 264.15D
    *
    * DEVIATIONS FROM STANDARDS:
    *
   \*===========================================================================*/
   /*===========================================================================*\
    * Preprocessor #include directive(s) for standard header files
   \*===========================================================================*/
   #include "reuse.h"

   /*===========================================================================*\
    * Preprocessor #include directive(s) for other header files
   \*===========================================================================*/
   #include "mmic_stream.h"

   /*===========================================================================*\
    * Exported preprocessor #define constants (object-like macros)
   \*===========================================================================*/

   /*===========================================================================*\
    * Exported preprocessor #define macros (i.e. those using # or ## operator)
   \*===========================================================================*/
   #define MMIC_ERROR_ID_TABLE(DCS_X)                                                                                             \
                                                                                                                                  \
      DCS_X(REINIT_ERROR_SPI)                                                                                                     \
      DCS_X(REINIT_ERROR_ACQ_ACTIVE)                                                                                              \
      DCS_X(REINIT_ERROR_ISM_RESET)                                                                                               \
      DCS_X(REINIT_ERROR_ISM_STARTUP)                                                                                             \
      DCS_X(REINIT_ERROR_ISM_WARNING)                                                                                             \
      DCS_X(REINIT_ERROR_CTE_INIT)                                                                                                \
      DCS_X(REINIT_ERROR_MIPI_CONFIG_INIT)                                                                                        \
      DCS_X(REINIT_ERROR_MIPI_CONFIG_RUN_TIME)                                                                                    \
      DCS_X(REINIT_ERROR_MIPI_CSI2_FuSa_FAULT)                                                                                    \
      DCS_X(REINIT_ERROR_MMIC_INIT)                                                                                               \
      DCS_X(REINIT_ERROR_TRIGGER_TIMEOUT)                                                                                         \
      DCS_X(REINIT_ERROR_LOOK_COMPLETE)                                                                                           \
      DCS_X(REINIT_ERROR_DISCARD)                                                                                                 \
      DCS_X(REINIT_ERROR_API_RETURN_VAL_FAULT)                                                                                    \
      DCS_X(REINIT_MARS_SAFETY_CRITICAL_FAULT)                                                                                    \
      DCS_X(REINIT_MARS_NON_RECOVERABLE_FAULT)                                                                                    \
      DCS_X(REINIT_ERROR_MARS_MCU_STS_MCU_MSSG)                                                                                   \
      DCS_X(DISCARD_ERROR_TEST)                                                                                                   \
      DCS_X(DISCARD_ERROR_RDD_RUNNING)                                                                                            \
      DCS_X(DISCARD_ERROR_SPT_WDG_MEMINIT)                                                                                        \
      DCS_X(DISCARD_ERROR_SPT_WDG_RFFT_TWIDCPY)                                                                                   \
      DCS_X(DISCARD_ERROR_SPT_WDG_RFFT)                                                                                           \
      DCS_X(DISCARD_ERROR_SPT_WDG_DFFT_TWIDCPY)                                                                                   \
      DCS_X(DISCARD_ERROR_SPT_WDG_DFFT)                                                                                           \
      DCS_X(DISCARD_ERROR_SPT_BUSY)                                                                                               \
      DCS_X(DISCARD_ERROR_ISM_CRC)                                                                                                \
      DCS_X(DISCARD_ERROR_ISM)                                                                                                    \
      DCS_X(DISCARD_ERROR_ISM_MASTER)                                                                                             \
      DCS_X(DISCARD_ERROR_ISM_DEFAULT)                                                                                            \
      DCS_X(DISCARD_ERROR_CONFIG_LOOK)                                                                                            \
      DCS_X(DISCARD_ERROR_LOOK_TRIGGER)                                                                                           \
      DCS_X(DISCARD_ERROR_LOOK_COMPLETE)                                                                                          \
      DCS_X(DISCARD_ERROR_MIPI_DEVICE_READY_TIMEOUT)                                                                              \
      DCS_X(DISCARD_ERROR_MIPI_RECOVERABLE_FAULT)                                                                                 \
      DCS_X(DISCARD_ERROR_TX_TEMP_READ_TIMEOUT)                                                                                   \
      DCS_X(DISCARD_ERROR_TE_FREQ_COUNT_TIMEOUT)                                                                                  \
      DCS_X(DISCARD_ERROR_MCLK_MSPC_TIMEOUT)                                                                                      \
      DCS_X(DISCARD_ERROR_MCLK_MSPC_CALIBRATION)                                                                                  \
      DCS_X(DISCARD_ERROR_CAFC_TEMP_READ_TIMEOUT)                                                                                 \
      DCS_X(DISCARD_ERROR_MIPI_FREQ_COUNT_TIMEOUT)                                                                                \
      DCS_X(DISCARD_ERROR_CAFC_FREQ_COUNT_TIMEOUT)                                                                                \
      DCS_X(DISCARD_ERROR_BC_ISM_OSM_FIT)                                                                                         \
      DCS_X(DISCARD_ERROR_BC_CHIRP_INTEGRITY)                                                                                     \
      DCS_X(DISCARD_ERROR_BC_TX_PATH_INTEGRITY)                                                                                   \
      DCS_X(DISCARD_ERROR_BC_GPIO_TOGGLE_TEST)                                                                                    \
      DCS_X(DISCARD_ERROR_ADC_CALIBRATION_TIMEOUT)                                                                                \
      DCS_X(DISCARD_ERROR_ADC_CALIBRATIONFAILED)                                                                                  \
      DCS_X(DISCARD_ERROR_RX_CALIBRATE_LOx3_GAIN)                                                                                 \
      DCS_X(DISCARD_ERROR_LOI_CALIBRATE_LOx3_GAIN)                                                                                \
      DCS_X(DISCARD_ERROR_LOI_START_LO_GAIN_CALIB)                                                                                \
      DCS_X(DISCARD_ERROR_TX1_PPD_CALIB)                                                                                          \
      DCS_X(DISCARD_ERROR_TX2_PPD_CALIB)                                                                                          \
      DCS_X(DISCARD_ERROR_TX3_PPD_CALIB)                                                                                          \
      DCS_X(DISCARD_ERROR_TX1_RF_CALIB)                                                                                           \
      DCS_X(DISCARD_ERROR_TX2_RF_CALIB)                                                                                           \
      DCS_X(DISCARD_ERROR_TX3_RF_CALIB)                                                                                           \
      DCS_X(DISCARD_ERROR_CAFC_CALIBRATION)                                                                                       \
      DCS_X(DISCARD_ERROR_RECOVERABLE_FAULT)                                                                                      \
      DCS_X(DISCARD_ERROR_RESET)                                                                                                  \
      DCS_X(DISCARD_ERROR_SENSOR_DEAD)

   #define MMIC_CONFIG_ERROR_ID_TABLE(DCS_X)                                                                                      \
      DCS_X(CONFIG_ERROR_MMIC_CONFIG)                                                                                             \
      DCS_X(CONFIG_ERROR_MIPI_CONFIG)                                                                                             \
      DCS_X(REINIT_CONFIG_ERROR_MIPI_CONFIG)                                                                                      \
      DCS_X(REINIT_CONFIG_ERROR_MMIC_CONFIG)                                                                                      \
      DCS_X(MMIC_LOOK_CONFIG_ERROR)

/* MMIC_ERROR_ID_TABLE() */

   #define ERROR_ID_ENUM(id)            id,
   #define MMIC_ERROR_ID_STRUCT_U16(id) uint16_t U16_##id;

/*===========================================================================*\
 * Exported type declarations (enum, struct, union, typedef)
\*===========================================================================*/
typedef enum MMIC_Error_ID_Tag
{
   MMIC_ERROR_ID_TABLE(ERROR_ID_ENUM) MAX_NUM_MMIC_ERROR

} MMIC_Error_ID_T;

typedef enum MMIC_Config_Error_ID_Tag
{
   MMIC_CONFIG_ERROR_ID_TABLE(ERROR_ID_ENUM) MAX_NUM_MMIC_CONFIG_ERROR
} MMIC_Config_Error_ID_T;

typedef union MMIC_Error_Union_Tag
{
   uint16_t u16[MAX_NUM_MMIC_ERROR];
   struct
   {
      MMIC_ERROR_ID_TABLE(MMIC_ERROR_ID_STRUCT_U16)
   } f;

} MMIC_Error_Union_T;

typedef union MMIC_Config_Error_Union_Tag
{
   uint16_t u16[MAX_NUM_MMIC_CONFIG_ERROR];
   struct
   {
      MMIC_CONFIG_ERROR_ID_TABLE(MMIC_ERROR_ID_STRUCT_U16)
   } f;

} MMIC_Config_Error_Union_T;

typedef struct MMIC_Error_Data_Tag
{
   /* [C191] Structure members should be grouped by data size and allocated from largest to smallest.
      [N8] All struct and union members shall be all lower case delimited with underscores.*/
   bool faulted;
   bool reinit_error;
   bool discard_error;
   bool MMIC_config_error;
   uint8_t MMIC_config_error_count;
   uint8_t function_config_fault;
   int8_t reinit_error_count;
   int8_t reinit_clear_count;
   int8_t discard_error_count;
   uint16_t reinit_error_total;
   uint16_t discard_error_total;
   MMIC_Config_Error_Union_T MMIC_config_error_counters;
   MMIC_Error_Union_T error_counters;

} MMIC_Error_Data_T;

/*===========================================================================*\
 * Exported inline function definitions and #define function-like macros
\*===========================================================================*/

/*===========================================================================*\
 * Exported object declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported function prototypes
\*===========================================================================*/
void Update_MMIC_Success(void);

void Set_MMIC_Faulted(void);
void Clr_MMIC_Faulted(void);
bool Get_MMIC_Faulted(void);

void Set_MMIC_Error_Reinit(MMIC_Error_ID_T error_id);
void Clr_MMIC_Error_Reinit(void);
bool Get_MMIC_Error_Reinit(void);
uint16_t Get_MMIC_Error_Reinit_Count(void);

void Set_MMIC_Error_Discard(MMIC_Error_ID_T error_id);
void Clr_MMIC_Error_Discard(void);
bool Get_MMIC_Error_Discard(void);
uint16_t Get_MMIC_Error_Discard_Count(void);

uint16_t Get_MMIC_Error_By_ID(MMIC_Error_ID_T error_id);
uint16_t *Get_MMIC_Error_Counters_ptr(void);

/* function config error prototype */
void Set_MMIC_Config_Error(MMIC_Config_Error_ID_T error_id);
void Clr_MMIC_Config_Error(void);
void Clr_MMIC_Config_Error_Cnt(void);
bool Get_MMIC_Config_Error(void);
uint8_t Get_Function_Config_Error(void);
void Clr_MMIC_API_Look_Fault_Status(void);
void Clr_MMIC_Reinit_Error_Count(void);
void Clr_MMIC_Reinit_Count_Post_Init(void);
uint8_t Get_MIPI_Fault(void);
/*===========================================================================*\
 * Exported variables
\*===========================================================================*/
extern volatile uint8_t API_Look_Config_Error;
extern volatile uint8_t API_Look_Trigger_Error;
extern volatile uint8_t API_Look_Complete_Error;
extern MMIC_Stream_T MMIC_Stream;

#endif
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- --------
 * 21-Jul-2025   qjgws1   EPB-3944:: Bring in the mars reset mechanism from tiger team branch temporarily
 * 20-Aug-2025   ftoobg   EPB-4023: [GEN8]Implement Function Config Fault & Validate
 * 20-Jan-2026   ftoobg   EPB-3952: [Gen8][SWE3] Implement Mars Safety: MMIC Safety Critical Errors Handling
 * 29-Dec-2025   ftoobg   EPB-4264: [Gen8][SWE3]MARS safety: API return value handling
 * 12-Feb-2026   djdgwr   EPB-4387: Added MMIC_LOOK_CONFIG_ERROR inside the MMIC_ERROR_ID_TABLE
 * 18-Feb-2026   djdgwr   EPB-4459: [GEN8][SWE3] Implement & Integration of MIPI Diagnostic function
 * 23-Feb-2026   ftoobg   EPB-4461: [GNE8]Bring Radar Control SM changes similar to GEN7_V2/GEN7_V1 into GEN8 variant
 * 10-Mar-2026   djdgwr   EPB-4477: [GEN8][SWE3][R5.0]Check the MIPI Return Value-added the Reinit Reson for MIPI CSI2 in run time.
 *
 \*===========================================================================*/
