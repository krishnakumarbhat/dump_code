/*===========================================================================*\
 * FILE: Generic_Drv_sfr.h (Mock for Unit Test)
 *===========================================================================
 * Copyright (C) 2026 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * Test stub for dsp_setup unit tests.
 * Provides an include guard so that re-inclusion inside dsp_setup.c is
 * blocked, allowing the test file to override DSP_base and CRG_base with
 * pointers to local test variables via #undef / #define before including
 * the source under test.
\*===========================================================================*/

#ifndef GENERIC_DRV_SFR_H
#define GENERIC_DRV_SFR_H

#ifndef __IO
   #define __IO volatile
#endif

#include "crg_sfrs.h"
#include "dsp_sfrs.h"
#include "timers_sfrs.h"

/* Base address macros — overridden by dsp_setup_unit_test.cc via #undef/#define */
#define DSP_base    0x84401000
#define CRG_base    0x89002000
#define TIMERS_base 0x91923000

#define DSP    ((__IO DSP_SFRS_t *)DSP_base)
#define CRG    ((__IO CRG_SFRS_t *)CRG_base)
#define TIMERS ((__IO TIMERS_SFRS_t *)TIMERS_base)

#endif /* GENERIC_DRV_SFR_H */
