/*===========================================================================*/
/**
 * @file versions.c
 *
 * @todo Add a one line description of the header file here.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This file provides versioning information
 *
 * @section ABBR ABBREVIATIONS:
 *
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - https://confluence.asux.aptiv.com/display/AASSA/GPO+Radar+Software+Versioning
 *
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/globalregional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - List of deviations from standards in this file: "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 *
 * @defgroup template Provide API description and define/delete next line
 * @ingroup <parent_API> (OPTIONAL USE if part of another API, else delete)
 * @{
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "versions.h"
#include "boot_interface.h"
#include "gitinfo.h"
#include "radar_sw_config.h"
#include "retention_ram_data.h"

/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/
/* generation of the product */
#define GENERATION_REVISION ((uint8_t)8)

/* sofware version for the product */
#define MAJOR_RELEASE_REVISION ((uint8_t)7)
#define MINOR_RELEASE_REVISION ((uint8_t)0)
#define PATCH_RELEASE_REVISION ((uint8_t)10)
#define PRE_RELEASE_REVISION   ((uint8_t)0)

/*** < Radar Configuration > ***/
/* radar board revision configuration */
#if defined(B0_BOARD)
   #define BOARD_TYPE_CFG ((uint8_t)(0xB0))
#elif defined(A0_BOARD)
   #define BOARD_TYPE_CFG ((uint8_t)(0xA0))
#else
   /* default - EDU_BOARD */
   #define BOARD_TYPE_CFG ((uint8_t)(0x01))
#endif

/* radar vehicle communication configuration */
/*| b7| b6| b5| b4| b3| b2|  b1 |  b0 |*/
/*|TBD|TBD|TBD|TBD|TBD|TBD| ETH | CAN |*/
#define CFG_VEHCOM_CAN ((uint8_t)(1U << (uint8_t)BIT_VEHCOM_CAN))
#define CFG_VEHCOM_ETH ((uint8_t)(1U << (uint8_t)BIT_VEHCOM_ETH))

#ifdef VEH_SOMEIP /* Someip- high Det Variant: --veh_com= someip*/
   #define VEH_COM_TYPE_CFG (CFG_VEHCOM_ETH)
#else
   /*For Satellite-CAN, Platform Standalone and AL-Standalone  */
   #define VEH_COM_TYPE_CFG (CFG_VEHCOM_CAN)
#endif

/* radar sub output configuration */
/*| b7| b6| b5| b4| b3|  b2 |  b1 |  b0 |*/
/*|TBD|TBD|TBD|TBD|TBD| CDC | OBJ | DET |*/
#define CFG_RADAR_DET      ((uint8_t)(1U << (uint8_t)BIT_RADAR_DET))
#define CFG_RADAR_OBJ      ((uint8_t)(1U << (uint8_t)BIT_RADAR_OBJ))
#define CFG_RADAR_CDC      ((uint8_t)(1U << (uint8_t)BIT_RADAR_CDC))
#define CFG_RADAR_HIGH_DET ((uint8_t)(1U << (uint8_t)BIT_RADAR_HIGH_DET))

/* for streaming radar */
/*| b7| b6| b5| b4| b3|  b2 |b1|b0|*/
/*|TBD|TBD|TBD|TBD|TBD| CDC |  |  |*/
#define CFG_RADAR_ADC  ((uint8_t)0)
#define CFG_RADAR_RFFT ((uint8_t)1)
#define CFG_RADAR_DFFT ((uint8_t)2)
#define CFG_RADAR_AFFT ((uint8_t)3)

/* radar output configuration */
#if defined(TRACKER_STANDALONE)
   #define OUTPUT_TYPE_CFG ((uint8_t)RADAR_STANDALONE)
   /* sub output type */
   #define OP_SUB_TYPE_CFG (CFG_RADAR_OBJ | CFG_RADAR_DET)
#elif defined(TRACKER_PARTNER_FUSION_SENSOR)
   #define OUTPUT_TYPE_CFG ((uint8_t)RADAR_SLAVE)
   /* sub output type */
   #define OP_SUB_TYPE_CFG (CFG_RADAR_DET)
#elif defined(TRACKER_MAIN_FUSION_SENSOR)
   #define OUTPUT_TYPE_CFG ((uint8_t)RADAR_MASTER)
   /* sub output type */
   #define OP_SUB_TYPE_CFG (CFG_RADAR_DET)
#else
   /* default - TRACKER_DISABLED */
   #define OUTPUT_TYPE_CFG ((uint8_t)RADAR_SATELLITE)

   #if defined(VEH_SOMEIP)
      /* sub output type */
      #define OP_SUB_TYPE_CFG (CFG_RADAR_HIGH_DET)
   #else
      /* sub output type */
      #define OP_SUB_TYPE_CFG (CFG_RADAR_DET)

   #endif

#endif

/* CDC enabled / disabled */
#if defined(CDC_ENABLE)
   #define OUTPUT_SUB_TYPE_CFG (OP_SUB_TYPE_CFG | CFG_RADAR_CDC)
#else
   #define OUTPUT_SUB_TYPE_CFG (OP_SUB_TYPE_CFG)
#endif

/* reserved field for future use */
#define RSVD ((uint8_t)0)

/* radar application configuration */
/*| b7| b6| b5| b4| b3|  b2 |  b1 |  b0 |*/
/*|TBD|TBD|TBD|TBD|TBD| TBD | FLR | SRR |*/
#define CFG_RADAR_APPL_SRR ((uint8_t)(1U << (uint8_t)BIT_RADAR_APPL_SRR))
#define CFG_RADAR_APPL_FLR ((uint8_t)(1U << (uint8_t)BIT_RADAR_APPL_FLR))

#if defined(FLR8)
   #define APPL_TYPE_CFG CFG_RADAR_APPL_FLR
#else
   /*SRR8P or SRR8HD*/
   #define APPL_TYPE_CFG CFG_RADAR_APPL_SRR
#endif
/*===========================================================================*\
 * Local Preprocessor #define MACROS
\*===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
/* radar application bitfields */
typedef enum Radar_Appl_Bit_Tag
{
   BIT_RADAR_APPL_SRR,
   BIT_RADAR_APPL_FLR
} Radar_Appl_Bit_T;

/* radar output configuration */
typedef enum Radar_Output_Type_Tag
{
   RADAR_SATELLITE,
   RADAR_STANDALONE,
   RADAR_STREAMING,
   RADAR_MASTER,
   RADAR_SLAVE,
   RADAR_CFG_MAX
} Radar_Output_Type_T;

/* radar sub output bitfields */
typedef enum Sub_Output_Bit_Tag
{
   BIT_RADAR_DET,
   BIT_RADAR_OBJ,
   BIT_RADAR_CDC,
   BIT_RADAR_HIGH_DET
} Sub_Output_Bit_T;

/* radar vehicle communication bitfields */
typedef enum Veh_Comm_Bit_Tag
{
   BIT_VEHCOM_CAN = 0,
   BIT_VEHCOM_ETH = 1
} Veh_Comm_Bit_T;

/*===========================================================================*\
 * Local Object Definitions
\*===========================================================================*/
#pragma clang section rodata = ".versionInfo"
/* embedded copyright notice */
/* Full copyright notice (64 bytes) */
volatile const char copyright[] = "Copyright \xA9 2022 Aptiv. All Rights Reserved.";

volatile const Application_Version_T Application_Version = {.output_type     = OUTPUT_TYPE_CFG,
                                                            .output_sub_type = OUTPUT_SUB_TYPE_CFG,
                                                            .veh_com_type    = VEH_COM_TYPE_CFG,
                                                            .board_type      = BOARD_TYPE_CFG,
                                                            .rsvd            = RSVD,
                                                            .appl_type       = APPL_TYPE_CFG,
                                                            .generation      = GENERATION_REVISION,
                                                            .variant         = K_PLATFORM_VARIANT,
                                                            .major           = MAJOR_RELEASE_REVISION,
                                                            .minor           = MINOR_RELEASE_REVISION,
                                                            .patch           = PATCH_RELEASE_REVISION,
                                                            .pre_rel         = PRE_RELEASE_REVISION};

volatile const char Git_Commit_Hash[] = STABLE_BUILD_SCM_REVISION;
volatile const char Git_Status[]      = STABLE_BUILD_SCM_STATUS;

#pragma clang section rodata = ""

Boot_Shared_Data_T Boot_Shared_Data __attribute__((section(".boot_interface"), used));
Retention_Ram_Data_T Retention_Ram_Data __attribute__((section(".retention_ram_data")));
volatile Bootloader_Version_T Bootloader_Version;

/*===========================================================================*\
 * Local Function Prototypes
\*===========================================================================*/

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/

/*===========================================================================*\
 * FUNCTION: Get_Application_Version
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:This function returns a pointer to the Application version
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
const Application_Version_T *Get_Application_Version(void)
{
   return ((const Application_Version_T *)&Application_Version);
}

/*===========================================================================*\
 * FUNCTION: Get_Bootloader_Version
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:This function returns a pointer to the Bootloader version
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
const Bootloader_Version_T *Get_Bootloader_Version(void)
{
   Bootloader_Version.major = Boot_Shared_Data.pbl_version_major;
   Bootloader_Version.minor = Boot_Shared_Data.pbl_version_minor;
   Bootloader_Version.patch = Boot_Shared_Data.pbl_version_patch;

   return ((const Bootloader_Version_T *)&Bootloader_Version);
}

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- --------
 *
 \*===========================================================================*/
