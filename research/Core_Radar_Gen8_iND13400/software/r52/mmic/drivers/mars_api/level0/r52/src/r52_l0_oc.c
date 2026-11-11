/* @copyright 2024 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#include "r52_l0_tmr.h"
#include "r52_l0_oc.h"
#include "r52_l0_util.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/
static Mars_ReturnType mars_l0_oc_init(mars_driver_data_t driver_data);
static Mars_ReturnType mars_l0_oc_set_oc(mars_driver_data_t driver_data, const uint64 timestamp);
static Mars_ReturnType mars_l0_oc_force_write(mars_driver_data_t driver_data, const mars_gpio_level_en level);

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/
mars_l0_oc_t r52_l0_oc = {.init = &mars_l0_oc_init, .set_oc = &mars_l0_oc_set_oc, .write = &mars_l0_oc_force_write}; /* polyspace VARIABLE:ALL [No action planned:Low] "Required for Mars instance definition" */

/**********************************************************************************************************************
 *  LOCAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**
 * @brief         Initialize Layer 0 Output Compare driver
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273264 GID-329171 GID-329175
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

static Mars_ReturnType mars_l0_oc_init(mars_driver_data_t driver_data)
{
    int32_t ret_v_drv = ARM_DRIVER_OK;
    Mars_ReturnType ret_val = MARS_E_OK;
    (void)driver_data;

    /* FRM_EN pin shall be kept default low */
    ret_v_drv = Driver_Port0.SetMode(ARM_PORT_A1A3, ARM_PIN_MODE_DIO, ARM_PORT_CFG_OUTPUT); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
    if (ret_v_drv != ARM_DRIVER_OK)
    {
        ret_val = MARS_ERROR_DRIVER_PORT | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
    }else
    {
        /* make sure FRM_EN pin is default low */
        ret_v_drv = Driver_Gpio0.WriteChn(ARM_GPIO_CHN_A1A3, ARM_GPIO_LOW); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
    }
    if ((ret_val == MARS_E_OK) && (ret_v_drv != ARM_DRIVER_OK))
    {
        ret_val = MARS_ERROR_DRIVER_GPIO | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
    }

    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/**
 * @brief         Configures the comparator value of the OC peripheral
 *                or triggers frame immediately
 * @param [in]    timestamp Comparator value of the trigger point
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @return        MARS_E_OK
 * @design        GID-329181 GID-273267 GID-329178
 */
static Mars_ReturnType mars_l0_oc_set_oc(mars_driver_data_t driver_data, const uint64 timestamp)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    (void)timestamp;
    ret_val = mars_l0_oc_force_write(driver_data, L0_IO_HI);
    (void)r52_l0_tmr.wait_us(driver_data, 5);  /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
    if(ret_val == MARS_E_OK)
    {
        ret_val = mars_l0_oc_force_write(driver_data, L0_IO_LO);
    }
    return ret_val;
}
/**
 * @brief         Forces the comparator output to a desired level
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    level expected IO level on the pin of the OC
 * @return        MARS_E_OK or MARS_ERROR_
 * @design        GID-329187 GID-273268 GID-329184
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

static Mars_ReturnType mars_l0_oc_force_write(mars_driver_data_t driver_data, const mars_gpio_level_en level)
{
    int32_t ret_v_drv = ARM_DRIVER_OK;
    Mars_ReturnType ret_val = MARS_E_OK;
    (void)driver_data;

    if (level == L0_IO_HI)
    {
        /* force-write MM_FRAME_START pin HI */
        ret_v_drv = Driver_Gpio0.WriteChn(ARM_GPIO_CHN_A1A3, ARM_GPIO_HIGH); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */

        if (ret_v_drv == ARM_DRIVER_OK)
        {
            ret_val = MARS_E_OK;
        }
        else
        {
            ret_val = MARS_ERROR_DRIVER_GPIO | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
        }
    }
    else /* pin to be forced low */
    {
        /* force-write MM_FRAME_START pin LO */
        ret_v_drv = Driver_Gpio0.WriteChn(ARM_GPIO_CHN_A1A3, ARM_GPIO_LOW);

        if (ret_v_drv == ARM_DRIVER_OK)
        {
            ret_val = MARS_E_OK;
        }
        else
        {
            ret_val = MARS_ERROR_DRIVER_GPIO | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
        }
    }

    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
