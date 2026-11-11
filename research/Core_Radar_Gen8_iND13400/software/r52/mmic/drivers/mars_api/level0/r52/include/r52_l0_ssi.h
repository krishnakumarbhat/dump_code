/*===========================================================================*/
/**
 * @file r52_l0_ssi.h
 *
 *
 * @date    date created:   17-09-2024
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

#ifndef R52_L0_SSI_H
#define R52_L0_SSI_H

/* polyspace-begin CERT-C:PRE08-C [No action planned:Low] "Modules named based on the architecture design" */
#include "mars_l0_types.h"
#include "mars_l0_error.h"
/* polyspace-end CERT-C:PRE08-C [No action planned:Low] "Modules named based on the architecture design" */

#include "Driver_SPI.h"

extern mars_l0_ssi_t r52_l0_ssi_chandra_evb;  /*!< Layer 0 abstraction for the Synch Serial Interface driver Chandra EVB variant */
extern mars_l0_ssi_t r52_l0_ssi_edu;          /*!< Layer 0 abstraction for the Synch Serial Interface driver EDU board variant */
#endif /*R52_L0_SSI_H*/
