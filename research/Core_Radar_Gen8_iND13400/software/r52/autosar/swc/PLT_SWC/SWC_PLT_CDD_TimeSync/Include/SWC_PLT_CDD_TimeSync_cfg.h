#ifndef SWC_CDD_TIMESYNC_CFG_H
#define SWC_CDD_TIMESYNC_CFG_H
/**\file
 * \brief Header file for SWC_PLT_CDD_TimeSync_cfg SW-C
 *
 *
 *
 * \b Application:        SRR8p \n
 * \b File-Revision:      %version: 1 %\n
 * \b Last-Changed-by:    %derived_by: iu9n5c % \n
 * \b Classification:     CONFIDENTIAL \n
 */
/*============================================================================*\
*
* Copyright 2025 Aptiv, All Rights Reserved
* It is not allowed to reproduce or utilize parts of this document in any form
* or by any means, including photocopying and microfilm, without permission in
* written by Aptiv.
*
\*============================================================================*/
/*============================================================================*
 * PREPROCESSOR DIRECTIVES
 *============================================================================*/
/* INCLUDE DIRECTIVES FOR OTHER HEADERS --------------------------------------*/
#include "Gpt.h"

/* local standard types */

/* EXPORTED DEFINE MACROS (#, ##) --------------------------------------------*/
/* LOCAL DEFINE MACROS (#, ##) -----------------------------------------------*/

/* EXPORTED DEFINES FOR CONSTANTS --------------------------------------------*/
/*============================================================================*\
* EXPORTED TYPEDEF DECLARATIONS
\*============================================================================*/
/* ENUMS ---------------------------------------------------------------------*/
/* STRUCTS -------------------------------------------------------------------*/
/* UNIONS --------------------------------------------------------------------*/
/* OTHER TYPEDEFS ------------------------------------------------------------*/
/*============================================================================*\
* EXPORTED OBJECT DECLARATIONS
\*============================================================================*/
/* CONFIGURATION DEFINE MACROS (#, ##) ---------------------------------------*/
/* This Macro defines weather Master feature of the sensor is used or not */
#define TIMESYNC_MASTER_FEATURE STD_OFF
/* This Macro defines weather Slave feature of the sensor is used or not */
#define TIMESYNC_SLAVE_FEATURE STD_ON
/* This Macro defines weather Gateway feature of the sensor is used or not */
/* Currently this feature is not supported */
#define TIMESYNC_GATEWAY_FEATURE STD_OFF
/* This Macro defines weather timesync message time-out diagnostics should be enabled or not*/
#define TIMESYNC_MSG_TIMEOUT STD_ON
/* Avoid warnings of unused API parameters */
#define STBMD_IGNORE_UNREF_PARAM(param) ((void)(param))
#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

#define TIMESYNC_TIMER_CHANNEL     ((Gpt_ChannelType)2U)
#define TIMESYNC_TIMER_CLK_HZ_F32  ((float32)TIMER_CH0_2_CLK_HZ)
#define TIMESYNC_US_PER_SECOND_F32 (1000000.0f)

   extern float32 SWC_PLT_CDD_TimeSync_GetTimerCntValueUs(void);
   extern void SWC_PLT_CDD_TimeSync_SetTimerCntValueUs(float32 timer_value_us);
   extern Std_ReturnType EcuSync_SeedCanTSynTimeBaseIfNeeded(void);

#define GET_TIMESYNC_TIMER_CNT_VALUE_US()               SWC_PLT_CDD_TimeSync_GetTimerCntValueUs()
#define SET_TIMESYNC_TIMER_CNT_VALUE_US(timer_value_us) SWC_PLT_CDD_TimeSync_SetTimerCntValueUs((timer_value_us))

#ifdef __cplusplus
}
#endif /* __cplusplus */
/*====================================================================================================================*\
* File Revision History (top to bottom: first revision to last revision)
*======================================================================================================================
*
* Date(dd-mm-yyyy)        userid                            (Description on following lines: SCR #, etc.)
*
* 10-26-2023              dz5wdd(Fahim Bandali)                   Initial version
\*===================================================================================================================*/
#endif /* SWC_CDD_TIMESYNC_CFG_H */
