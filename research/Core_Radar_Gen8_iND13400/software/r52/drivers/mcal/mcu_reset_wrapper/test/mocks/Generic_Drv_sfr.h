/*===========================================================================*\
 * FILE: Generic_Drv_sfr.h (Mock for Unit Test)
 *===========================================================================
 * Copyright (C) 2023 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * Mock SFR register header providing SYSCTRL stub for unit testing.
\*===========================================================================*/

#ifndef GENERIC_DRV_SFR_H
#define GENERIC_DRV_SFR_H

#include "Std_Types.h"
#include <stdint.h>

/*===========================================================================*\
 * Minimal SYSCTRL register stub - only fields used by mcu_reset_wrapper
\*===========================================================================*/
typedef struct
{
   uint32_t DEBUG_CODE;
   uint32_t RETAIN_1;
} SYSCTRL_SFRS_t;

extern SYSCTRL_SFRS_t sysctrl_stub;

#define SYSCTRL (&sysctrl_stub)

#endif /* GENERIC_DRV_SFR_H */
