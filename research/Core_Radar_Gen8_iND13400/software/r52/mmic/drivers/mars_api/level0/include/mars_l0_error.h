/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#ifndef MARS_L0_ERROR_H
#define MARS_L0_ERROR_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_public_types.h"
#include "mars_error.h"
/**********************************************************************************************************************
 * MARS ERROR L0
 *********************************************************************************************************************/
#define MARS_ERROR_DRIVER_CRC           (1UL  << MARS_ERROR_L0_BIT_OFFSET)    /*!< Mars CRC Driver Error Type*/
#define MARS_ERROR_DRIVER_GPIO          (2UL  << MARS_ERROR_L0_BIT_OFFSET)    /*!< Mars GPIO Driver Error Type*/
#define MARS_ERROR_DRIVER_PORT          (3UL  << MARS_ERROR_L0_BIT_OFFSET)    /*!< Mars Port Driver Error Type*/
#define MARS_ERROR_DRIVER_SSI           (6UL  << MARS_ERROR_L0_BIT_OFFSET)    /*!< Mars SSI Driver Error Type*/
#define MARS_ERROR_L0_CRC               (7UL  << MARS_ERROR_L0_BIT_OFFSET)    /*!< Mars CRC Level 0 Error Type*/
#define MARS_ERROR_L0_GPIO              (8UL  << MARS_ERROR_L0_BIT_OFFSET)    /*!< Mars GPIO Level 0 Error Type*/
#define MARS_ERROR_L0_OC                (9UL  << MARS_ERROR_L0_BIT_OFFSET)    /*!< Mars Output Compare Level 0 Error Type*/ /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "Unused Error ID kept for driver design" */
#define MARS_ERROR_L0_SSI               (10UL << MARS_ERROR_L0_BIT_OFFSET)    /*!< Mars SSI Level 0 Error Type*/
#define MARS_ERROR_L0_TMR               (11UL << MARS_ERROR_L0_BIT_OFFSET)    /*!< Mars Timer Level 0 Error Type*/

/**********************************************************************************************************************
 * MARS ERROR IDs LEVEL 0
 *********************************************************************************************************************/
#define MARS_L0_E_NOT_OK_PARAM          (1u << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 1] Parameter verification failed */
#define MARS_L0_E_NOT_OK_INIT           (2u << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 2] GPIO invalid state */
#define MARS_L0_E_NOT_OK_WRITE          (3u << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 3] GPIO invalid write operation */
#define MARS_L0_E_NOT_OK_SET_SPEED      (4u << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 4] SSI invalid set_speed value */
#define MARS_L0_E_NOT_OK_SET_MODE       (5u << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 5] SSI invalid set_mode value */
#define MARS_L0_E_INIT_FAILED           (6u << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 6] Initialization failed */
#define MARS_L0_E_DRV_MISMATCH          (7u << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 7] Incompatible CMSIS driver */



#endif /* MARS_L0_ERROR_H */
