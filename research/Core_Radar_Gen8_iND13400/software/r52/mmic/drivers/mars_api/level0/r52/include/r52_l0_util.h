/*===========================================================================*/
/**
 * @file r52_l0_util.h
 *
 *
 * @date    date created:   06-19-2025
 *
 *
 *------------------------------------------------------------------------------
 *
 * @copyright 2024 indie Semiconductor.
 *
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Seminconductor
 *
 *------------------------------------------------------------------------------
 */

#ifndef R52_L0_UTIL_H
#define R52_L0_UTIL_H

/* polyspace-begin CERT-C:PRE08-C [No action planned:Low] "Modules named based on the architecture design" */
#include "mars_l0_types.h"
#include "mars_l0_error.h"
/* polyspace-end CERT-C:PRE08-C [No action planned:Low] "Modules named based on the architecture design" */

typedef struct
{
    uint16 api;
    uint16 drv;
}mars_driver_version_t;

extern Mars_ReturnType mars_check_driver_version(const mars_driver_version_t actual, const mars_driver_version_t expected);
Mars_ReturnType mars_convert_negative_errors(const sint32 ret_v_drv,const uint32 driver_error_mask);
#endif /*R52_L0_UTIL_H*/
