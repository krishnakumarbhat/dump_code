/*===========================================================================*/
/**
 * @file mars_l0_types.h
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

#ifndef MARS_L0_TYPES_H
#define MARS_L0_TYPES_H

#include "mars_public_types.h"

/**********************************************************************************************************************
 * GLOBAL MACROS
 *********************************************************************************************************************/

#define MARS_DRIVER_DATA_ARRAY_SIZE 6u /* Size of the array of Mars driver data, used to store data for each driver in a single array instead of separate variables*/
/* Index 0 and 1 are reserved */
#define MARS_GPIO_INIT_STATUS_INDEX 2u /* Index in the driver data array where the GPIO init status is stored */
#define MARS_TMR_VALUE_NS_FOR_10_UTICKS_INDEX 3u /* Index in the driver data array where the timer value in ns for 10 microsecond ticks is stored */
#define MARS_SSI_MODE_INDEX 4u /* Index in the driver data array where the current SSI mode is stored */
#define MARS_SSI_SPEED_INDEX 5u /* Index in the driver data array where the current SSI speed is stored */


#define TMR_TMR_VALUE_NS_FOR_10_UTICKS_INITIAL_VALUE 100uL

/* polyspace-begin Custom:6.3 [No action planned:Mid] "Starts with internal module name L0" */
typedef enum {
    L0_IO_LO = 0,    /*!< [value 0] Layer 0 GPIO LOW level */
    L0_IO_HI = 1     /*!< [value 1] Layer 0 GPIO HI level */
} mars_gpio_level_en; /*!< Layer GPIO Level GID-273192 */
/* polyspace-end Custom:6.3 [No action planned:Mid] "Starts with internal module name L0" */

/* polyspace-begin Custom:6.3 [No action planned:Mid] "Starts with internal module name L0" */
typedef enum {
    L0_SSI_MODE_SPI = 0,    /*!< [value 0] Layer 0 SSI SPI mode */
    L0_SSI_MODE_QSPI = 1    /*!< [value 1] Layer 0 SSI QSPI mode */
}mars_l0_ssi_mode_en;        /*!< Layer 0 SSI mode GID-273533 */
/* polyspace-end Custom:6.3 [No action planned:Mid] "Starts with internal module name L0" */

/* polyspace-begin Custom:6.3 [No action planned:Mid] "Starts with internal module name L0" */
typedef enum {
    L0_SSI_SPEED_LO = 0,    /*!< [value 0] Layer 0 SSI mode low speed, used at startup */
    L0_SSI_SPEED_HI = 1     /*!< [value 1] Layer 0 SSI mode high speed, used after MAF activation */
}mars_l0_ssi_speed_en;       /*!< Layer 0 SSI speed GID-273534 */
/* polyspace-end Custom:6.3 [No action planned:Mid] "Starts with internal module name L0" */

/* polyspace-begin Custom:6.3 [No action planned:Mid] "Starts with internal module name R52_L0" */
typedef enum
{
    R52_L0_GPIO_UNINIT = 0,  /*!< Driver is not yet initialized */
    R52_L0_GPIO_INIT_OK = 1, /*!< Driver is initialized correctly */
    R52_L0_GPIO_INIT_NOK = 2 /*!< Driver is initialized and failed */
} mars_r52_gpio_status_en; /* polyspace MISRA-C-2023:2.3 [Justified:Low] "The enum used to indicate the current GPIO init state" */
/* polyspace-end Custom:6.3 [No action planned:Mid] "Starts with internal module name R52_L0" */

typedef uint32 mars_driver_data_t[MARS_DRIVER_DATA_ARRAY_SIZE]; /* Array of Mars driver data, used to store data for each driver in a single array instead of separate variables*/

/* polyspace-begin MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-begin CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */
typedef struct {
    Mars_ReturnType (*init) (mars_driver_data_t driver_data); /*!< Layer 0 CRC init function prototype */
    Mars_ReturnType (*calculate) (mars_driver_data_t driver_data, const uint32* const data, const uint32 size, uint32* const crc); /*!< Layer 0 CRC calculate prototype */
} mars_l0_crc_t;    /*!< Layer 0 wrapper function descriptors for GID-273122 */
/* polyspace-end MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-end CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */

/* polyspace-begin MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-begin CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */
typedef struct  {
    Mars_ReturnType (*init) (mars_driver_data_t driver_data); /*!< Layer 0 GPIO init function prototype */
    Mars_ReturnType (*read) (mars_driver_data_t driver_data, mars_gpio_level_en * const level);    /*!< Layer 0 GPIO read function prototype */
    Mars_ReturnType (*write) (mars_driver_data_t driver_data, mars_gpio_level_en const level);     /*!< Layer 0 GPIO write function prototype */
} mars_l0_gpio_t; /*!< Layer 0 wrapper function descriptors for GPIO GID-273193 */
/* polyspace-end MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-end CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */


/* polyspace-begin MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-begin CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */
typedef struct  {
    Mars_ReturnType (*init) (mars_driver_data_t driver_data); /*!< Layer 0 Output Compare init function prototype */
    Mars_ReturnType (*set_oc) (mars_driver_data_t driver_data, const uint64 timestamp);   /*!< Layer 0 Output Compare set_oc function prototype */
    Mars_ReturnType (*write) (mars_driver_data_t driver_data, mars_gpio_level_en const level); /*!< Layer 0 Output Compare write function prototype */
} mars_l0_oc_t; /*!< Layer 0 wrapper function descriptors for Output Compare GID-273293 */
/* polyspace-end MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-end CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */

/* polyspace-begin MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-begin CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */
typedef struct  {
    Mars_ReturnType (*init) (mars_driver_data_t driver_data); /*!< Layer 0 SSI init function prototype */
    Mars_ReturnType (*set_mode) (mars_driver_data_t driver_data, const mars_l0_ssi_mode_en mode);  /*!< Layer 0 SSI set_mode function prototype */ /* polyspace CERT-C:DCL02-C [Justified:Low] "This is not considered an issue, as the findings are not identical and there are slight differences between them." */
    Mars_ReturnType (*get_mode) (mars_driver_data_t driver_data, mars_l0_ssi_mode_en *const mode); /*!< Layer 0 SSI get_mode function prototype */
    Mars_ReturnType (*set_speed) (mars_driver_data_t driver_data, const mars_l0_ssi_speed_en speed);   /*!< Layer 0 SSI set_speed   function prototype */
    Mars_ReturnType (*spi_transfer) (mars_driver_data_t driver_data, const uint32* const txdata, uint32* const rxdata, const uint32 size);  /*!< Layer 0 SSI spi_transfer function prototype */
    Mars_ReturnType (*qspi_send) (mars_driver_data_t driver_data, const uint32* const txdata, const uint32 size, const uint16 inst, const uint32 addr);   /*!< Layer 0 SSI qspi_send function prototype */
    Mars_ReturnType (*qspi_receive) (mars_driver_data_t driver_data, uint32* const rxdata, const uint32 size, const uint16 inst, const uint32 addr);    /*!< Layer 0 SSI qspi_receive function prototype */
} mars_l0_ssi_t;    /*!< Layer 0 wrapper function descriptors for Sync Serial Interface GID-273532  */
/* polyspace-end MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-end CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */


/* polyspace-begin MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-begin CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */
typedef struct  {
    Mars_ReturnType (*init) (mars_driver_data_t driver_data); /*!< Layer 0 Timer init function prototype */
    Mars_ReturnType (*wait_us) (mars_driver_data_t driver_data, const uint32 wait_time);   /*!< Layer 0 Timer wait_us function prototype */
    Mars_ReturnType (*wait_ms) (mars_driver_data_t driver_data, const uint32 wait_time);   /*!< Layer 0 Timer wait_ms function prototype */
} mars_l0_tmr_t;    /*!< Layer 0 wrapper function descriptors for timer GID-273294 */
/* polyspace-end MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-end CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */

#endif /*MARS_L0_TYPES_H*/
