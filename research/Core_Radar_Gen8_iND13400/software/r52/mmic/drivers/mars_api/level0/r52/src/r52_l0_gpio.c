/* @copyright 2024 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#include "r52_l0_gpio.h"
#include "r52_l0_util.h"
#include "Driver_Common.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/
static Mars_ReturnType mars_l0_gpio_init_reset_chandra_evb(mars_driver_data_t driver_data);
static Mars_ReturnType mars_l0_gpio_read_reset_chandra_evb(mars_driver_data_t driver_data, mars_gpio_level_en *const level);
static Mars_ReturnType mars_l0_gpio_write_reset_chandra_evb(mars_driver_data_t driver_data, const mars_gpio_level_en level);
static Mars_ReturnType mars_l0_gpio_init_reset_edu(mars_driver_data_t driver_data);
static Mars_ReturnType mars_l0_gpio_read_reset_edu(mars_driver_data_t driver_data, mars_gpio_level_en *const level);
static Mars_ReturnType mars_l0_gpio_write_reset_edu(mars_driver_data_t driver_data, const mars_gpio_level_en level);
static Mars_ReturnType mars_l0_gpio_init_reset_chandra_evb_t(mars_driver_data_t driver_data);
static Mars_ReturnType mars_l0_gpio_read_reset_chandra_evb_t(mars_driver_data_t driver_data, mars_gpio_level_en *const level);
static Mars_ReturnType mars_l0_gpio_write_reset_chandra_evb_t(mars_driver_data_t driver_data, const mars_gpio_level_en level);


static Mars_ReturnType mars_l0_gpio_init_mlbx(mars_driver_data_t driver_data);
static Mars_ReturnType mars_l0_gpio_read_mlbx(mars_driver_data_t driver_data, mars_gpio_level_en *const level);
static Mars_ReturnType mars_l0_gpio_write_mlbx(mars_driver_data_t driver_data, const mars_gpio_level_en level);
static Mars_ReturnType mars_l0_gpio_init_sft(mars_driver_data_t driver_data);
static Mars_ReturnType mars_l0_gpio_read_sft(mars_driver_data_t driver_data, mars_gpio_level_en *const level);
static Mars_ReturnType mars_l0_gpio_write_sft(mars_driver_data_t driver_data, const mars_gpio_level_en level);
static Mars_ReturnType mars_l0_gpio_init_gp0(mars_driver_data_t driver_data);
static Mars_ReturnType mars_l0_gpio_read_gp0(mars_driver_data_t driver_data, mars_gpio_level_en *const level);
static Mars_ReturnType mars_l0_gpio_write_gp0(mars_driver_data_t driver_data, const mars_gpio_level_en level);

static Mars_ReturnType mars_l0_gpio_write_reset_pin(const ARM_GPIO_CHN chn, const mars_gpio_level_en level);
static Mars_ReturnType mars_l0_gpio_read_pin(const ARM_GPIO_CHN chn, mars_gpio_level_en *const level);
static Mars_ReturnType mars_l0_gpio_init_reset_pin(mars_driver_data_t driver_data, const ARM_PORT_PIN port_chn, const ARM_GPIO_CHN pin_chn);
static Mars_ReturnType mars_l0_gpio_init(mars_driver_data_t driver_data, ARM_PORT_PIN pin, ARM_PORT_PIN_MODE mode, ARM_PORT_PIN_CFG cfg);
/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

    /*!< Layer0 descriptor of the Reset pin EVB variant */
mars_l0_gpio_t r52_l0_gpio_reset_chandra_evb = {/* polyspace VARIABLE:ALL [No action planned:Low] "Required for Mars instance definition" */
    .init = &mars_l0_gpio_init_reset_chandra_evb, .read = &mars_l0_gpio_read_reset_chandra_evb, .write = &mars_l0_gpio_write_reset_chandra_evb};             

    /*!< Layer0 descriptor of the Reset pin EVB variant with Mars T*/
mars_l0_gpio_t r52_l0_gpio_reset_chandra_evb_t = {/* polyspace VARIABLE:ALL [No action planned:Low] "Required for Mars instance definition" */
    .init = &mars_l0_gpio_init_reset_chandra_evb_t, .read = &mars_l0_gpio_read_reset_chandra_evb_t, .write = &mars_l0_gpio_write_reset_chandra_evb_t};       

   /*!< Layer0 descriptor of the Reset pin EDU variant */ 
mars_l0_gpio_t r52_l0_gpio_reset_edu = {.init = &mars_l0_gpio_init_reset_edu, .read = &mars_l0_gpio_read_reset_edu, .write = &mars_l0_gpio_write_reset_edu}; /* polyspace VARIABLE:ALL [No action planned:Low] "Required for Mars instance definition" */
   /*!< Layer0 descriptor of the Mailbox response pin */
mars_l0_gpio_t r52_l0_gpio_mlbx = {.init = &mars_l0_gpio_init_mlbx, .read = &mars_l0_gpio_read_mlbx, .write = &mars_l0_gpio_write_mlbx}; /* polyspace VARIABLE:ALL [No action planned:Low] "Required for Mars instance definition" */        
   /*!< Layer0 descriptor of the SFT Error pin */
mars_l0_gpio_t r52_l0_gpio_sft = {.init = &mars_l0_gpio_init_sft, .read = &mars_l0_gpio_read_sft, .write = &mars_l0_gpio_write_sft}; /* polyspace VARIABLE:ALL [No action planned:Low] "Required for Mars instance definition" */
   /*!< Layer0 descriptor of the GP0 pin */                
mars_l0_gpio_t r52_l0_gpio_gp0 = {.init = &mars_l0_gpio_init_gp0, .read = &mars_l0_gpio_read_gp0, .write = &mars_l0_gpio_write_gp0}; /* polyspace VARIABLE:ALL [No action planned:Low] "Required for Mars instance definition" */                        

/**********************************************************************************************************************
 *  LOCAL VARIABLES
 *********************************************************************************************************************/

#define ARM_GPIO_DRV_VERSION_EXPECTED    0x500 /**< expected driver version */
#define ARM_GPIO_API_VERSION_EXPECTED    0x101 /**< expected API version */

#define ARM_PORT_DRV_VERSION_EXPECTED    0x500 /**< expected driver version */
#define ARM_PORT_API_VERSION_EXPECTED    0x301 /**< expected API version */

typedef uint32_t arm_gpio_value_t; 

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**
 * @brief         Initialize GPIO pin "reset" for Chandra EVB
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273194 GID-537076
 */
static Mars_ReturnType mars_l0_gpio_init_reset_chandra_evb(mars_driver_data_t driver_data)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_l0_gpio_init_reset_pin(driver_data,ARM_PORT_A1B6,ARM_GPIO_CHN_A1B6);
    return ret_val;
}

/**
 * @brief         Initialize GPIO pin "reset" for Chandra EVB with T shaped Mars EV
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273194 GID-537076
 */
static Mars_ReturnType mars_l0_gpio_init_reset_chandra_evb_t(mars_driver_data_t driver_data)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_l0_gpio_init_reset_pin(driver_data, ARM_PORT_A1A1,ARM_GPIO_CHN_A1A1);
    return ret_val;
}



/**
 * @brief         Initialize GPIO pin "reset" for EDU EVB
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273194 GID-537076
 */
static Mars_ReturnType mars_l0_gpio_init_reset_edu(mars_driver_data_t driver_data)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_l0_gpio_init_reset_pin(driver_data, ARM_PORT_A1A0,ARM_GPIO_CHN_A1A0);
    return ret_val;
}

/**
 * @brief         Initialize GPIO pin "Mailbox Response"
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273194 GID-438661 GID-438662
 */
static Mars_ReturnType mars_l0_gpio_init_mlbx(mars_driver_data_t driver_data)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_l0_gpio_init(driver_data, ARM_PORT_MM_IRQ, ARM_PIN_MODE_MMINTF_IRQ, ARM_PORT_CFG_INPUT);
    return ret_val;
}

/**
 * @brief         Initialize GPIO pin "Safety Error"
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 * @design        GID-273194 GID-438661 GID-438662
 */
static Mars_ReturnType mars_l0_gpio_init_sft(mars_driver_data_t driver_data)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_l0_gpio_init(driver_data, ARM_PORT_MM_ERROR, ARM_PIN_MODE_MMINTF_ERROR, ARM_PORT_CFG_INPUT);
    return ret_val;
}

/**
 * @brief         Initialize GPIO pin GP0
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param         level : expected IO pin level
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273194 GID-438661 GID-438662
 */
static Mars_ReturnType mars_l0_gpio_init_gp0(mars_driver_data_t driver_data)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_l0_gpio_init(driver_data, ARM_PORT_MM_FRAME_SOT, ARM_PIN_MODE_MMINTF_FRAME_SOT, ARM_PORT_CFG_INPUT);
    return ret_val;
}

/**
 * @brief         Write to GPIO pin Mailbox Response
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    level : expected IO pin level
 * @return        MARS_L0 ErrorID, write to this pin is not allowed. Interface exists for harmonized API
 * @design        GID-273220 GID-537079
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

static Mars_ReturnType mars_l0_gpio_write_mlbx(mars_driver_data_t driver_data, const mars_gpio_level_en level)
{
    /* MLBX is an input pin hence no write is allowed */
    (void)driver_data;
    (void)level;
    return MARS_ERROR_L0_GPIO | MARS_L0_E_NOT_OK_WRITE;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         Read GPIO pin Mailbox Response
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [out]   level : IO pin level
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273203 GID-438642 GID-438644
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

static Mars_ReturnType mars_l0_gpio_read_mlbx(mars_driver_data_t driver_data, mars_gpio_level_en *const level)
{
    (void)driver_data;
    return (mars_l0_gpio_read_pin(ARM_GPIO_CHN_MMINT_SG2, level));
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */


/**
 * @brief         Write to GPIO pin Safety Error
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    level : expected IO pin level
 * @return        MARS_L0 ErrorID, write to this pin is not allowed. Interface exists for harmonized API
 * @design        GID-273220 GID-537079
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

static Mars_ReturnType mars_l0_gpio_write_sft(mars_driver_data_t driver_data, const mars_gpio_level_en level)
{
    /* SFT is an input pin hence no write is allowed */
    (void)driver_data;
    (void)level;
    return MARS_ERROR_L0_GPIO | MARS_L0_E_NOT_OK_WRITE;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         Read GPIO pin Safety Error
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [out]   level : IO pin level
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273203 GID-438642 GID-438644
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

static Mars_ReturnType mars_l0_gpio_read_sft(mars_driver_data_t driver_data, mars_gpio_level_en *const level)
{
    (void)driver_data;
    return (mars_l0_gpio_read_pin(ARM_GPIO_CHN_MMINT_SG0, level));
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         Write to GPIO pin GP0
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    level : expected IO pin level
 * @return        MARS_L0 ErrorID, write to this pin is not allowed. Interface exists for harmonized API
 * @design        GID-273220 GID-537079
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

static Mars_ReturnType mars_l0_gpio_write_gp0(mars_driver_data_t driver_data, const mars_gpio_level_en level)
{
    /* GP0 is an input pin hence no write is allowed */
    (void)driver_data;
    (void)level;
    return MARS_ERROR_L0_GPIO | MARS_L0_E_NOT_OK_WRITE;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         Read GPIO pin GP0
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [out]   level : IO pin level
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273203 GID-438642 GID-438644
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

static Mars_ReturnType mars_l0_gpio_read_gp0(mars_driver_data_t driver_data, mars_gpio_level_en *const level)
{
    (void)driver_data;
    return (mars_l0_gpio_read_pin(ARM_GPIO_CHN_MMINT_SG1, level));
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         Write to GPIO pin RESET on the Chandra EVB
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    level : expected IO pin level
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273220 GID-537078
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

static Mars_ReturnType mars_l0_gpio_write_reset_chandra_evb(mars_driver_data_t driver_data, const mars_gpio_level_en level)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    (void)driver_data;
    ret_val = mars_l0_gpio_write_reset_pin(ARM_GPIO_CHN_A1B6, level);
    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         Write to GPIO pin RESET on the Chandra EVB with T shaped Mars EVB
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    level : expected IO pin level
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273220 GID-537078
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

static Mars_ReturnType mars_l0_gpio_write_reset_chandra_evb_t(mars_driver_data_t driver_data, const mars_gpio_level_en level)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    (void)driver_data;

    ret_val = mars_l0_gpio_write_reset_pin(ARM_GPIO_CHN_A1A1, level);
    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */


/**
 * @brief         Write to GPIO pin RESET on the EDU board
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    level : expected IO pin level
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273220 GID-537078
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

static Mars_ReturnType mars_l0_gpio_write_reset_edu(mars_driver_data_t driver_data, const mars_gpio_level_en level)
{
    (void)driver_data;
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_l0_gpio_write_reset_pin(ARM_GPIO_CHN_A1A0, level);
    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         Read GPIO pin RESET on Chandra EVB
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [out]   level : IO pin level
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273203 GID-537077
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

static Mars_ReturnType mars_l0_gpio_read_reset_chandra_evb(mars_driver_data_t driver_data, mars_gpio_level_en *const level)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    (void)driver_data;

    ret_val = mars_l0_gpio_read_pin(ARM_GPIO_CHN_A1B6, level);
    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         Read GPIO pin RESET on Chandra EVB with T shaped Mars EVB
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [out]   level : IO pin level
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273203 GID-537077
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

static Mars_ReturnType mars_l0_gpio_read_reset_chandra_evb_t(mars_driver_data_t driver_data, mars_gpio_level_en *const level)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    (void)driver_data;

    ret_val = mars_l0_gpio_read_pin(ARM_GPIO_CHN_A1A1, level);
    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         Read GPIO pin RESET on EDU board
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [out]   level : IO pin level
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273203 GID-537077
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

static Mars_ReturnType mars_l0_gpio_read_reset_edu(mars_driver_data_t driver_data, mars_gpio_level_en *const level)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    (void)driver_data;
    ret_val = mars_l0_gpio_read_pin(ARM_GPIO_CHN_A1A0, level);
    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         Generic common IO pin init
 * @param[inout]  driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    pin  Port pin identifier
 * @param [in]    mode Port pin mode
 * @param [in]    cfg  Port pin configuration
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-329329 GID-273194 GID-329333
 */
static Mars_ReturnType mars_l0_gpio_init(mars_driver_data_t driver_data,ARM_PORT_PIN pin, ARM_PORT_PIN_MODE mode, ARM_PORT_PIN_CFG cfg)
{
    int32_t ret_v_drv = ARM_DRIVER_OK;
    Mars_ReturnType ret_val = MARS_E_OK;

    if (driver_data == NULL_PTR)
    {
        ret_val = MARS_ERROR_L0_GPIO | MARS_L0_E_NOT_OK_PARAM;
    }
    else
    {
        switch (driver_data[MARS_GPIO_INIT_STATUS_INDEX]) 
        {
        case (uint32)R52_L0_GPIO_UNINIT:
            do
            {
                const ARM_DRIVER_VERSION port_driver_version_cmsis = Driver_Port0.GetVersion(); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
                const mars_driver_version_t port_driver_version = {port_driver_version_cmsis.api, port_driver_version_cmsis.drv};
                const mars_driver_version_t port_driver_version_expected = {ARM_PORT_API_VERSION_EXPECTED,ARM_PORT_DRV_VERSION_EXPECTED};

                const ARM_DRIVER_VERSION gpio_driver_version_cmsis = Driver_Gpio0.GetVersion(); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
                const mars_driver_version_t gpio_driver_version = {gpio_driver_version_cmsis.api, gpio_driver_version_cmsis.drv};
                const mars_driver_version_t gpio_driver_version_expected = {ARM_GPIO_API_VERSION_EXPECTED,ARM_GPIO_DRV_VERSION_EXPECTED};

                /* before initialization, we check if the underlying CMSIS drivers are compatible to the Radar API */
                /* check PORT driver compatibility */
                ret_val = mars_check_driver_version(port_driver_version,port_driver_version_expected);
                if (ret_val != MARS_E_OK)
                {
                    ret_val |=  MARS_ERROR_DRIVER_PORT;
                }
                else
                {
                    /* check GPIO driver compatibility */
                    ret_val = mars_check_driver_version(gpio_driver_version,gpio_driver_version_expected);
                    if (ret_val != MARS_E_OK)
                    {
                        ret_val |=  MARS_ERROR_DRIVER_GPIO;
                    }
                }
                if (ret_val == MARS_E_OK)
                {
                    /* PORT and GPIO drivers are always needed for reset pins */
                    ret_v_drv = Driver_Port0.Initialize(ARM_PORT_NUM_OF_GROUP, ARM_PORT_ON); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
                    if (ret_v_drv != ARM_DRIVER_OK)
                    {
                    ret_val = (uint32)MARS_ERROR_DRIVER_PORT | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
                    }
                    else
                    {
                        ret_v_drv = Driver_Gpio0.Initialize(NULL_PTR); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
                        if (ret_v_drv != ARM_DRIVER_OK)
                        {
                        ret_val = MARS_ERROR_DRIVER_GPIO | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
                        }
                    }

                    if (ret_v_drv == ARM_DRIVER_OK)
                    {
                        ret_val = MARS_E_OK;
                        driver_data[MARS_GPIO_INIT_STATUS_INDEX] = (uint32)R52_L0_GPIO_INIT_OK;
                    }
                    else
                    {
                        driver_data[MARS_GPIO_INIT_STATUS_INDEX] = (uint32)R52_L0_GPIO_INIT_NOK;
                    }
                }
            }while (0);
            break;
        case (uint32)R52_L0_GPIO_INIT_OK:
            /* Driver has been already initialized */
            ret_val = MARS_E_OK;
            break;
        default:
            /* Driver init failed previously  */
            ret_val = MARS_ERROR_L0_GPIO | MARS_L0_E_INIT_FAILED;
            break;
        }
        if (ret_val == MARS_E_OK)
        {
            /* Configure PORT pin mode */
            ret_v_drv = Driver_Port0.SetMode(pin, mode, cfg); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
            if (ret_v_drv == ARM_DRIVER_OK)
            {
                ret_val = MARS_E_OK;
            }
            else
            {
            ret_val = MARS_ERROR_DRIVER_PORT | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
            }
        }
    }
    return ret_val;
}

/**
 * @brief         Write to GPIO pin RESET
 * @param [in]    level : expected IO pin level
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273220 GID-329344 GID-329347
 */
static Mars_ReturnType mars_l0_gpio_write_reset_pin(const ARM_GPIO_CHN chn, const mars_gpio_level_en level)
{
    int32_t ret_v_drv = ARM_DRIVER_OK;
    Mars_ReturnType ret_val = MARS_E_OK;
    const arm_gpio_value_t reset_state = (level == L0_IO_HI) ? ARM_GPIO_HIGH : ARM_GPIO_LOW;
    ret_v_drv = Driver_Gpio0.WriteChn(chn, reset_state); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
    if (ret_v_drv == ARM_DRIVER_OK)
    {
        ret_val = MARS_E_OK;
    }
    else
    {
        ret_val = MARS_ERROR_DRIVER_GPIO | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
    }
    return ret_val;
}

/**
 * @brief         Read GPIO pin
 * @param [out]   level : IO pin level
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-438647 GID-438648
 */
static Mars_ReturnType mars_l0_gpio_read_pin(const ARM_GPIO_CHN chn, mars_gpio_level_en *const level)
{
    int32_t ret_v_drv = ARM_DRIVER_OK;
    Mars_ReturnType ret_val = MARS_E_OK;
    if (NULL_PTR != level)
    {
        arm_gpio_value_t reset_state = 0;
        ret_v_drv = Driver_Gpio0.ReadChn(chn, &reset_state); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */

        if (ret_v_drv == ARM_DRIVER_OK)
        {
            *level = (reset_state == ARM_GPIO_LOW) ? L0_IO_LO : L0_IO_HI;
            ret_val = MARS_E_OK;
        }
        else
        {
            ret_val = MARS_ERROR_DRIVER_GPIO | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
        }
    }
    else
    {
        ret_val = MARS_ERROR_L0_GPIO | MARS_L0_E_NOT_OK_PARAM;
    }
    return ret_val;
}
/**
 * @brief         Initialize GPIO pin "reset"
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param[in]     port_chn denotes the PORT channel
 * @param[in]     pin_chn denotes the GPIO  channel
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273194 GID-537075
 */
static Mars_ReturnType mars_l0_gpio_init_reset_pin(mars_driver_data_t driver_data,const ARM_PORT_PIN port_chn, const ARM_GPIO_CHN pin_chn)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_l0_gpio_init(driver_data, port_chn, ARM_PIN_MODE_DIO, ARM_PORT_CFG_OUTPUT);
    if (ret_val == MARS_E_OK)
    {
        /* Reset pin must be default high, we can set it only after drivers are initialized. */
        ret_val = mars_l0_gpio_write_reset_pin(pin_chn, L0_IO_HI);
    }
    return ret_val;
}
