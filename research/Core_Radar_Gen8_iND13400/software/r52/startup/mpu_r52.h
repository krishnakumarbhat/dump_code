/**
 * @file mpu_r52.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Main application definitions.
 * @note This file should only contain constant definitions and NO INCLUDE files.
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
#ifndef MPU_R52_H
#define MPU_R52_H

#include <stdint.h>
#include <stdbool.h>

/* ====== Field enums ====== */
typedef enum {
    MPU_SH_NON_SHAREABLE=0,
    MPU_SH_OUTER_SHAREABLE=2,
    MPU_SH_INNER_SHAREABLE=3
} mpu_sh_t;

typedef enum {
    MPU_AP_PRIV_RW_USER_NO = 0,
    MPU_AP_PRIV_RW_USER_RW = 1,
    MPU_AP_PRIV_RO_USER_NO = 2,
    MPU_AP_PRIV_RO_USER_RO = 3
} mpu_ap_t;

/* Structure to hold MPU region configuration */
typedef struct {
    const uint32_t *base_sym;   /* Pointer to linker symbol for base address */
    const uint32_t *limit_sym;  /* Pointer to linker symbol for limit address */
    uint8_t region;             /* Region number (0-15/23) */
    uint8_t sh;                 /* Shareability attribute (0, 2, 3) */
    uint8_t ap;                 /* Access permissions (0-3) */
    uint8_t xn;                 /* Execute Never flag (0-1) */
    uint8_t attridx;            /* Memory attribute index (0-15) */
    bool enable;                /* Enable flag */
    uint8_t padding[2];         /* Explicit padding for 4-byte alignment */
} Mpu_Region_Config_t;

void __attribute((section(".StartupCommon"))) Mpu_Init(void);
#endif
