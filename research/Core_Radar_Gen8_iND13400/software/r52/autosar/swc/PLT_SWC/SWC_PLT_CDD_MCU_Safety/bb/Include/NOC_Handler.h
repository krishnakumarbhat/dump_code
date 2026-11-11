#ifndef NOC_HANDLER_H
#define NOC_HANDLER_H

/*===========================================================================*\
 * FILE: NOC_Handler.h
 *===========================================================================
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2026 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the header files for NOC Handler.
 *
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/GlobalRegional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards </a>
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include "Rte_SWC_PLT_CDD_MCU_Safety.h"
#include "Std_Types.h"

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/

/*===========================================================================*\
 * Helper Macros for Register List Generation
\*===========================================================================*/
/* Base addresses for each NOC variant */
#define CHANDRA_NOC_BASE_ADDR (0x84FD0000U)
#define SMALL_NOC_BASE_ADDR   (0x8BF00000U)
#define ARTIE_NOC_BASE_ADDR   (0x91910000U)

/* FUSA_CTRL base address for sticky diagnostic registers */
#define FUSA_CTRL_BASE_ADDR (0x89004000U)

/* Relative register offsets (common to all NOC variants) */
#define NOC_CLEAR_OFFSET               (0x0CU)
#define NOC_BIST_CONTROL_OFFSET        (0x10U)
#define NOC_BIST_STATUS_OFFSET         (0x14U)
#define NOC_BIST_START_OFFSET          (0x18U)
#define NOC_MISSION_FAULT_00_OFFSET    (0x40U)
#define NOC_MISSION_FAULT_01_OFFSET    (0x44U)
#define NOC_MISSION_FAULT_02_OFFSET    (0x48U)
#define NOC_MISSION_FAULT_03_OFFSET    (0x4CU)
#define NOC_LATENT_COM_FAULT_00_OFFSET (0x54U)
#define NOC_LATENT_COM_FAULT_01_OFFSET (0x58U)
#define NOC_LATENT_COM_FAULT_02_OFFSET (0x5CU)
#define NOC_LATENT_COM_FAULT_03_OFFSET (0x60U)
/* FUSA_CTRL sticky diagnostic register offsets (relative to FUSA_CTRL_BASE_ADDR) */
#define STICKY_DIAG_CTRL0_OFFSET (0xBCU) /* Confirmed: 0x890040BC */
#define STICKY_DIAG_CTRL1_OFFSET (0xC0U) /* Confirmed: 0x890040C0 */
#define STICKY_DIAG_CTRL2_OFFSET (0xC4U) /* Confirmed: 0x890040C4 */

/* Parameterized register access macros for CHANDRA NOC */
#define CHANDRA_NOC_CLEAR_ADDR               (*(volatile uint32_t *)(CHANDRA_NOC_BASE_ADDR + NOC_CLEAR_OFFSET))
#define CHANDRA_NOC_BIST_CONTROL_ADDR        (*(volatile uint32_t *)(CHANDRA_NOC_BASE_ADDR + NOC_BIST_CONTROL_OFFSET))
#define CHANDRA_NOC_BIST_START_ADDR          (*(volatile uint32_t *)(CHANDRA_NOC_BASE_ADDR + NOC_BIST_START_OFFSET))
#define CHANDRA_NOC_BIST_STATUS_ADDR         (*(volatile uint32_t *)(CHANDRA_NOC_BASE_ADDR + NOC_BIST_STATUS_OFFSET))
#define CHANDRA_NOC_MISSION_FAULT_00_ADDR    (*(volatile uint32_t *)(CHANDRA_NOC_BASE_ADDR + NOC_MISSION_FAULT_00_OFFSET))
#define CHANDRA_NOC_MISSION_FAULT_01_ADDR    (*(volatile uint32_t *)(CHANDRA_NOC_BASE_ADDR + NOC_MISSION_FAULT_01_OFFSET))
#define CHANDRA_NOC_MISSION_FAULT_02_ADDR    (*(volatile uint32_t *)(CHANDRA_NOC_BASE_ADDR + NOC_MISSION_FAULT_02_OFFSET))
#define CHANDRA_NOC_MISSION_FAULT_03_ADDR    (*(volatile uint32_t *)(CHANDRA_NOC_BASE_ADDR + NOC_MISSION_FAULT_03_OFFSET))
#define CHANDRA_NOC_LATENT_COM_FAULT_00_ADDR (*(volatile uint32_t *)(CHANDRA_NOC_BASE_ADDR + NOC_LATENT_COM_FAULT_00_OFFSET))
#define CHANDRA_NOC_LATENT_COM_FAULT_01_ADDR (*(volatile uint32_t *)(CHANDRA_NOC_BASE_ADDR + NOC_LATENT_COM_FAULT_01_OFFSET))
#define CHANDRA_NOC_LATENT_COM_FAULT_02_ADDR (*(volatile uint32_t *)(CHANDRA_NOC_BASE_ADDR + NOC_LATENT_COM_FAULT_02_OFFSET))
#define CHANDRA_NOC_LATENT_COM_FAULT_03_ADDR (*(volatile uint32_t *)(CHANDRA_NOC_BASE_ADDR + NOC_LATENT_COM_FAULT_03_OFFSET))
/* Sticky diagnostic control registers in FUSA_CTRL block */
#define STICKY_DIAG_CTRL0_ADDR (*(volatile uint32_t *)(FUSA_CTRL_BASE_ADDR + STICKY_DIAG_CTRL0_OFFSET))
#define STICKY_DIAG_CTRL1_ADDR (*(volatile uint32_t *)(FUSA_CTRL_BASE_ADDR + STICKY_DIAG_CTRL1_OFFSET))
#define STICKY_DIAG_CTRL2_ADDR (*(volatile uint32_t *)(FUSA_CTRL_BASE_ADDR + STICKY_DIAG_CTRL2_OFFSET))

/* Parameterized register access macros for SMALL NOC */
#define SMALL_NOC_CLEAR_ADDR               (*(volatile uint32_t *)(SMALL_NOC_BASE_ADDR + NOC_CLEAR_OFFSET))
#define SMALL_NOC_BIST_CONTROL_ADDR        (*(volatile uint32_t *)(SMALL_NOC_BASE_ADDR + NOC_BIST_CONTROL_OFFSET))
#define SMALL_NOC_BIST_START_ADDR          (*(volatile uint32_t *)(SMALL_NOC_BASE_ADDR + NOC_BIST_START_OFFSET))
#define SMALL_NOC_BIST_STATUS_ADDR         (*(volatile uint32_t *)(SMALL_NOC_BASE_ADDR + NOC_BIST_STATUS_OFFSET))
#define SMALL_NOC_MISSION_FAULT_00_ADDR    (*(volatile uint32_t *)(SMALL_NOC_BASE_ADDR + NOC_MISSION_FAULT_00_OFFSET))
#define SMALL_NOC_MISSION_FAULT_01_ADDR    (*(volatile uint32_t *)(SMALL_NOC_BASE_ADDR + NOC_MISSION_FAULT_01_OFFSET))
#define SMALL_NOC_MISSION_FAULT_02_ADDR    (*(volatile uint32_t *)(SMALL_NOC_BASE_ADDR + NOC_MISSION_FAULT_02_OFFSET))
#define SMALL_NOC_MISSION_FAULT_03_ADDR    (*(volatile uint32_t *)(SMALL_NOC_BASE_ADDR + NOC_MISSION_FAULT_03_OFFSET))
#define SMALL_NOC_LATENT_COM_FAULT_00_ADDR (*(volatile uint32_t *)(SMALL_NOC_BASE_ADDR + NOC_LATENT_COM_FAULT_00_OFFSET))
#define SMALL_NOC_LATENT_COM_FAULT_01_ADDR (*(volatile uint32_t *)(SMALL_NOC_BASE_ADDR + NOC_LATENT_COM_FAULT_01_OFFSET))
#define SMALL_NOC_LATENT_COM_FAULT_02_ADDR (*(volatile uint32_t *)(SMALL_NOC_BASE_ADDR + NOC_LATENT_COM_FAULT_02_OFFSET))
#define SMALL_NOC_LATENT_COM_FAULT_03_ADDR (*(volatile uint32_t *)(SMALL_NOC_BASE_ADDR + NOC_LATENT_COM_FAULT_03_OFFSET))

/* Parameterized register access macros for ARTIE NOC */
#define ARTIE_NOC_CLEAR_ADDR               (*(volatile uint32_t *)(ARTIE_NOC_BASE_ADDR + NOC_CLEAR_OFFSET))
#define ARTIE_NOC_BIST_CONTROL_ADDR        (*(volatile uint32_t *)(ARTIE_NOC_BASE_ADDR + NOC_BIST_CONTROL_OFFSET))
#define ARTIE_NOC_BIST_START_ADDR          (*(volatile uint32_t *)(ARTIE_NOC_BASE_ADDR + NOC_BIST_START_OFFSET))
#define ARTIE_NOC_BIST_STATUS_ADDR         (*(volatile uint32_t *)(ARTIE_NOC_BASE_ADDR + NOC_BIST_STATUS_OFFSET))
#define ARTIE_NOC_MISSION_FAULT_00_ADDR    (*(volatile uint32_t *)(ARTIE_NOC_BASE_ADDR + NOC_MISSION_FAULT_00_OFFSET))
#define ARTIE_NOC_MISSION_FAULT_01_ADDR    (*(volatile uint32_t *)(ARTIE_NOC_BASE_ADDR + NOC_MISSION_FAULT_01_OFFSET))
#define ARTIE_NOC_MISSION_FAULT_02_ADDR    (*(volatile uint32_t *)(ARTIE_NOC_BASE_ADDR + NOC_MISSION_FAULT_02_OFFSET))
#define ARTIE_NOC_MISSION_FAULT_03_ADDR    (*(volatile uint32_t *)(ARTIE_NOC_BASE_ADDR + NOC_MISSION_FAULT_03_OFFSET))
#define ARTIE_NOC_LATENT_COM_FAULT_00_ADDR (*(volatile uint32_t *)(ARTIE_NOC_BASE_ADDR + NOC_LATENT_COM_FAULT_00_OFFSET))
#define ARTIE_NOC_LATENT_COM_FAULT_01_ADDR (*(volatile uint32_t *)(ARTIE_NOC_BASE_ADDR + NOC_LATENT_COM_FAULT_01_OFFSET))
#define ARTIE_NOC_LATENT_COM_FAULT_02_ADDR (*(volatile uint32_t *)(ARTIE_NOC_BASE_ADDR + NOC_LATENT_COM_FAULT_02_OFFSET))
#define ARTIE_NOC_LATENT_COM_FAULT_03_ADDR (*(volatile uint32_t *)(ARTIE_NOC_BASE_ADDR + NOC_LATENT_COM_FAULT_03_OFFSET))

/* BISTCONTROL register field encoding (offset 0x10):
 * - bit 24:    AUTOMISSION  - when set, hardware auto-returns to mission mode after BIST
 * - bits 23:16: TIMEOUT1     - BIST timeout value (reset: 0xFF); provides hardware-bounded BIST execution
 * - bits 15:0:  TIMEOUT0     - BIST timeout value (reset: 0xFFFF); provides hardware-bounded BIST execution
 * TIMEOUT0/TIMEOUT1 defaults are non-zero; do not write BISTCONTROL with value 0 or both fields will be 0. */
#define NOC_BIST_AUTOMISSION_BIT (1U << 24) /* BISTCONTROL.AUTOMISSION: hardware auto-returns to mission mode */

/* BISTSTART register: write this value to trigger BIST sequence */
#define BIST_START_VALUE (0x000000B5U)

/* CLEAR register field encoding (offset 0x0C):
 * - bit 1: BISTCLEAR    - clears all BIST-related registers; only required when AutoMission == 0
 * - bit 0: MISSIONCLEAR - clears Mission Faults */
#define NOC_BIST_CLEAR_BIT    (2U) /* CLEAR.BISTCLEAR: only use when AutoMission == 0 */
#define NOC_MISSION_CLEAR_BIT (1U) /* CLEAR.MISSIONCLEAR */

/* Maximum iterations to wait for BistStatus.Done to return to 0 after BIST completion.
 * This bounds the post-BIST mission-mode restoration poll (spec sequence step 7).
 * No hardware timeout exists for this transition; software must guard it. */
#define NOC_BIST_POST_DONE_TIMEOUT_COUNT (1000U)

#define STICKY_DIAG_CLEAR_ALL_BITS (0xFFFFFFFFU) /* clear all sticky diagnostic bits */

#define NOC_BIST_DONE_BIT   (1U << 0)
#define NOC_BIST_FAILED_BIT (1U << 1)
#define NOC_STATUS_SET      (1U)
#define NOC_STATUS_NOT_SET  (0U)

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Function Declarations
 *===========================================================================*/
void Clear_StickyDiag_MissionFault_registers(void);
void NOC_Run_Bist_Chandra(void);
void NOC_Run_Bist_Small(void);
void NOC_Run_Bist_Artie(void);
void NOC_Verify_Chandra_LatentIsr_Execution(void);
void NOC_Verify_Artie_LatentIsr_Execution(void);
void NOC_Verify_Small_LatentIsr_Execution(void);
extern void Log_NOCLatentIntFault_Info(Dt_NOC_Fault_Info_T *NOCFault_Context, uint16 Resnum);

#endif /* NOC_HANDLER_H */
