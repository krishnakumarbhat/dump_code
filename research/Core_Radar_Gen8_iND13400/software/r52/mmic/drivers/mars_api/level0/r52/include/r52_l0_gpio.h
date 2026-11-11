/*===========================================================================*/
/**
 * @file r52_l0_gpio.h
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

#ifndef R52_L0_GPIO_H
#define R52_L0_GPIO_H

/* polyspace-begin CERT-C:PRE08-C [No action planned:Low] "Modules named based on the architecture design" */
#include "mars_l0_types.h"
#include "mars_l0_error.h"
/* polyspace-end CERT-C:PRE08-C [No action planned:Low] "Modules named based on the architecture design" */

#include "Driver_Gpio.h"
#include "Driver_Port.h"

extern mars_l0_gpio_t r52_l0_gpio_reset_chandra_evb;  /*!< Layer 0 abstraction for the GPIO RESET pin of the Chandra EVB  - OUTPUT */
extern mars_l0_gpio_t r52_l0_gpio_reset_chandra_evb_t;  /*!< Layer 0 abstraction for the GPIO RESET pin of the Chandra EVB with Mars T - OUTPUT */
extern mars_l0_gpio_t r52_l0_gpio_reset_edu;          /*!< Layer 0 abstraction for the GPIO RESET pin of the EDU board  - OUTPUT */
extern mars_l0_gpio_t r52_l0_gpio_mlbx;               /*!< Layer 0 abstraction for the GPIO Mailbox Response notification pin - INPUT */
extern mars_l0_gpio_t r52_l0_gpio_sft;                /*!< Layer 0 abstraction for the GPIO Safety Error notification pin - INPUT */
extern mars_l0_gpio_t r52_l0_gpio_gp0;                /*!< Layer 0 abstraction for the GPIO GP0 pin - INPUT */
#endif /*R52_L0_GPIO_H*/
