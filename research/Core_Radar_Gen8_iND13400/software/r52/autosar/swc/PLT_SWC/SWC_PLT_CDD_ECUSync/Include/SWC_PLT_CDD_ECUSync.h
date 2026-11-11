#ifndef SWC_CDD_ECUSYNC_H
#define SWC_CDD_ECUSYNC_H

/**\file
 * \brief Header file for SWC_PLT_CDD_ECUSync SW-C
 *
 * This file contains some implementations needed to adapt the NvM manager blocks
 *
 * \b Application:        SRR7p \n
 * \b File-Revision:      %version: 1 %\n
 * \b Last-Changed-by:    %derived_by: cj8f7c % \n
 * \b Classification:     CONFIDENTIAL \n
 */

/*============================================================================*\
*
* Copyright 2022 Aptiv, All Rights Reserved
* It is not allowed to reproduce or utilize parts of this document in any form
* or by any means, including photocopying and microfilm, without permission in
* written by Aptiv.
*
\*============================================================================*/

/*============================================================================*
 * PREPROCESSOR DIRECTIVES
 *============================================================================*/

/* INCLUDE DIRECTIVES FOR STANDARD HEADERS -----------------------------------*/
/*#include "Common_SRAM_Core0.h"*/

/* INCLUDE DIRECTIVES FOR OTHER HEADERS --------------------------------------*/
#include "Std_Types.h"
/* local standard types */
#include "fixmac.h"
#include "sensor_position.h"
#include "smc_cal.h"

/* EXPORTED DEFINE MACROS (#, ##) --------------------------------------------*/
/* Will be set if ECU synchronization has not been initialized */
#define ECUSYNC_STATUS_NOTINIT (0x0000U)

/* Will be set if ECU synchronization has been initialized */
#define ECUSYNC_STATUS_INITIALIZED (0xA55AU)

/* Will be set if ECU synchronization has been started */
#define ECUSYNC_STATUS_STARTED (0x5AA5U)
#ifndef UNIT_TEST
   #define TIMESYNCOFFSET k_sensor_radar_firing_offset_list_smc[Get_Radar_Position() - 1U]
#else
   #define TIMESYNCOFFSET (0U)
#endif

/* LOCAL DEFINE MACROS (#, ##) -----------------------------------------------*/
#define STBM_DOMAIN_INDEX 0U

/* CONFIGURATION DEFINE MACROS (#, ##) ---------------------------------------*/
/* This Macro defines weather Master feature of the sensor is used or not */
#define TIMESYNC_MASTER_FEATURE STD_OFF
/* This Macro defines weather Slave feature of the sensor is used or not */
#define TIMESYNC_SLAVE_FEATURE STD_ON
/* This Macro defines weather Gateway feature of the sensor is used or not */
/* Currently this feature is not supported */
#define TIMESYNC_GATEWAY_FEATURE STD_OFF
/* This Macro defines weather timesync message time-out diagnostics should be enabled or not*/
#define TIMESYNC_MSG_TIMEOUT STD_OFF
/* This macro defines the offset to be maintained between the Global clock and the internal clock */
#define TIMESYNCOFFSET k_sensor_radar_firing_offset_list_smc[Get_Radar_Position() - 1U]

/* This macro defines the maximum correction that can be done either in upward or downward direction for every radar cycle */

//#define RADAR_TRIG_ISR_100MS /* COmment this if Radar cycle needs to be 50ms */
#ifdef RADAR_TRIG_ISR_100MS
   #define TIMESYNC_CYCLE_TIMERPERIOD_MS (100UL)
   /* This macro defines the threshold beyond which correction will be applied on the clock */
   #define TIMESYNC_CORRECTIONTHRESHOLD (98UL)

#else
   #define TIMESYNC_CYCLE_TIMERPERIOD_MS (50UL)
   /* This macro defines the threshold beyond which correction will be applied on the clock */
   #define TIMESYNC_CORRECTIONTHRESHOLD  (48L)

#endif

/* This macro defines the maximum correction that can be done either in upward or downward direction for every radar cycle */
#define TIMESYNC_CORRECTIONOFFSET (10UL)

/* Avoid warnings of unused API parameters */
#define STBMD_IGNORE_UNREF_PARAM(param) ((void)(param))
/* EXPORTED DEFINES FOR CONSTANTS --------------------------------------------*/

/*============================================================================*\
* EXPORTED TYPEDEF DECLARATIONS
\*============================================================================*/

/* ENUMS ---------------------------------------------------------------------*/
typedef enum ECU_SYNC_Correction_Tag
{
   ECU_SYNC_INVALID = 0, /* Invalid */
   ECU_SYNC_UP_STEP,     /* Adjust next radar cycle Up,   less than Max up   */
   ECU_SYNC_MAX_UP_STEP, /* Adjust next radar cycle Up,   Max up value       */
   ECU_SYNC_DOWN_STEP    /* Adjust next radar cycle down, less than Max down */
} ECU_SYNC_Correction_T;
/* STRUCTS -------------------------------------------------------------------*/

/* UNIONS --------------------------------------------------------------------*/

/* OTHER TYPEDEFS ------------------------------------------------------------*/

/*============================================================================*\
* EXPORTED OBJECT DECLARATIONS
\*============================================================================*/
/* Current time in seconds.
This value is incremented once per second in the HW timer interrupt.
Additionally this value is updated by the SYNC/FLLUP CAN messages from the time master*/
#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

   FUNC(void, SWC_CDD_StbMD_CODE) Time_Sync_Service(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
/************************
 * function prototypes
 ***********************/
#if (TRUE == ENABLE_SIT_TEST_STUBS)
void PlatformTime_ustime_Interface_Test(void);
#endif
/*====================================================================================================================*\
* File Revision History (top to bottom: first revision to last revision)
*======================================================================================================================
*
* Date(dd-mm-yyyy)        userid                            (Description on following lines: SCR #, etc.)
*
* 08-23-2022              cj8f7c(Venkata)                   Initial version
\*===================================================================================================================*/

#endif /* SWC_APPL_ALIGNMENT_NVM_H */
