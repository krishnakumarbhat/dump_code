/*===========================================================================*\
 * FILE: Generic_Drv_sfr.h (Mock for Unit Test)
 *===========================================================================
 * Copyright (C) 2026 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * Test stub for ipc_dsp unit tests.
 * Provides an include guard so that re-inclusion inside ipc_dsp.c is
 * blocked, allowing the test file to override DSP_base with a pointer
 * to a local test variable via #undef / #define before including the
 * source under test.
\*===========================================================================*/

#ifndef GENERIC_DRV_SFR_H
#define GENERIC_DRV_SFR_H

#ifndef __IO
   #define __IO volatile
#endif

#include "dsp_sfrs.h"

/* Base address macro — overridden by ipc_dsp_unit_test.cc via #undef/#define */
#define DSP_base 0x84401000

#define DSP ((__IO DSP_SFRS_t *)DSP_base)

#endif /* GENERIC_DRV_SFR_H */
