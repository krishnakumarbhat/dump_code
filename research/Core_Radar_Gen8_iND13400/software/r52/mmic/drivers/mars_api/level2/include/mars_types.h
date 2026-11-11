/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#ifndef MARS_TYPES_H
#define MARS_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/* polyspace-begin CERT-C:PRE08-C [No action planned:Low] "Modules named based on the architecture design" */
#include "mars_l2_error.h"
/* polyspace-end CERT-C:PRE08-C [No action planned:Low] "Modules named based on the architecture design" */

#include "mars_cfg.h"
#include "mars_l0_types.h"
#include "mars_public_types.h"


/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* ****************************
 * MARS DATA
 * ****************************/
/** @struct mars_data_status_t
 *  @brief Mars API internal Status Data for one instance
 *  @design GID-349561
 */
typedef struct
{
    mars_driver_status_t Mars_Data_drvStatus;
    mars_mbl_error_en Mars_Data_mblError;
    mars_maf_error_en Mars_Data_mafError;
    mars_sft_error_en Mars_Data_sftError;
    mars_ssi_error_en Mars_Data_ssiError;
    mars_scp_error_en Mars_Data_scpError;
    mars_pcw_error_en Mars_Data_pcwError;
    mars_sts_error_en Mars_Data_stsError;
    mars_mcustatus_t Mars_Data_mcuStatus;
    mars_ctrlstatus_t Mars_Data_ctrlStatus;
    uint32 Mars_Data_opModeStatus;
    mars_fw_version_t Mars_Data_fwVersion;
} mars_data_status_t;

/** @struct mars_data_buffer_scp_error_t
 *  @brief Scratchpad errors
 *  @design GID-349561
 */
typedef struct
{
    uint32 word[MARS_SCP_CAL_ERROR_SIZE_WORDS];
} mars_data_buffer_scp_error_t;

/** @struct mars_data_buffer_spi_t
 *  @brief SPI buffer
 *  @design GID-349561
 */
typedef struct
{
    uint32 buffer_SPI_out[SSI_BUFFER_SIZE]; /* Internal buffer for SSI operations */
    uint32 buffer_SPI_in[SSI_BUFFER_SIZE];  /* Internal buffer for SSI operations */
} mars_data_buffer_spi_t;


/** @struct mars_data_buffer_t
 *  @brief Mars API internal cache/work variables for one instance
 *  @design GID-349561
 */
typedef struct
{
    const uint32 *firmware_srcAddr;
    uint32 firmware_startAddr;
    uint32 firmware_size;
    uint32 firmware_crc;
    mars_data_buffer_scp_error_t scp_error;
    uint8 freshnessCounterDiag[MARS_DIAG_VALUES_MAX_NUMBER];
    mars_data_buffer_spi_t Mars_Buffer_SPI;
    mars_driver_data_t driver_data; /* Internal variables used by the driver implementations */
    
} mars_data_buffer_t;

/** @struct mars_instance_data_t
 *  @brief Mars API internal variables for one instance
 *  @design GID-349561
 */
typedef struct
{
    mars_data_status_t Mars_Status;
    mars_data_buffer_t Mars_Buffer;
} mars_instance_data_t;

/* ****************************
 * MARS SELF INSTANCE
 * ****************************/

/** @enum mars_instance_id_en
 *  @brief Mars API Instance identifier Enum
 *  @design GID-349561
 */
typedef enum
{
    MARS_INSTANCE_ID_0 = 0u,
    MARS_INSTANCE_ID_1 = 1u,
    MARS_MAX_NO_OF_INSTANCES
} mars_instance_id_en;

/** @struct mars_instance_drivers_t
 *  @brief Mars API instance L0 driver wrapper pointers
 *  @design GID-349561
 */
typedef struct
{
    mars_l0_ssi_t * Mars_SSI_Driver;
    mars_l0_gpio_t * Mars_Gpio_Driver_Reset;
    mars_l0_gpio_t * Mars_Gpio_Driver_MLBX;
    mars_l0_gpio_t * Mars_Gpio_Driver_GP0;
    mars_l0_gpio_t * Mars_Gpio_Driver_SFT;
    mars_l0_oc_t * Mars_OC_Driver;
    mars_l0_tmr_t * Mars_TMR_Driver;
    mars_l0_crc_t * Mars_CRC_Driver;
#ifndef MARS_DEBUG_SUPPORT_DISABLED
    mars_l0_gpio_t * Mars_Gpio_Driver_TE;
#endif
} mars_instance_drivers_t;

/* polyspace-begin MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-begin CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */
/** @struct mars_instance_t
 *  @brief Mars API instance type
 *  @design GID-349561
 */
typedef struct
{
    mars_instance_id_en Mars_Instance_Id;
    mars_instance_data_t Mars_Data;
    mars_instance_drivers_t Mars_Drivers;
} mars_instance_t;
/* polyspace-end MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-end CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */

/** @enum mars_sft_set_en
 *  @brief Mars SFT Set Enum
 *  @design GID-422624
 */
typedef enum
{
    MARS_SFT_ASSERT = 0u,
    MARS_SFT_DEASSERT = 1u
} mars_sft_set_en;

/* ****************************
 * MARS API
 * ****************************/
#define MARS_OPERATION_MODE_NORMAL (1u << 0u) /*!< [bit 0] Normal Mode */
#define MARS_OPERATION_MODE_DEBUG (1u << 1u) /*!< [bit 1] Debug Mode */
#define MARS_OPERATION_MODE_UNDEFINED (1u << 2u) /*!< [bit 2] Undefined Mode */
#define MARS_ALLOW_ALL_FW_VERSIONS 0u

#define MARS_1_BIT  (1u)
#define MARS_2_BITS (2u)
#define MARS_3_BITS (3u)
#define MARS_4_BITS (4u)
#define MARS_8_BITS (8u)
#define MARS_14_BITS (14u)
#define MARS_15_BITS (15u)
#define MARS_16_BITS (16u)
#define MARS_24_BITS (24u)
#define MARS_32_BITS (32u)
#define MARS_MAX_32_BITS_VALUE (0xFFFFFFFFuL)
#define MARS_PARITY_LUT_4BIT (0x6996uL)
#define MARS_GETFIRSTERROR_INVALID 0xFFFFFFFFuL

#endif /* MARS_TYPES_H */
