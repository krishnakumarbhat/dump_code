/* @copyright 2024 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_l1.h"

/**********************************************************************************************************************
 * GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**
 * @brief         read the value of the Mars mailbox response indication IO pin
 * @param         mars_self mars driver instance reference
 * @param         level pointer to host memory where the level value will be written
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-346251 GID-278634 GID-286463
 */
Mars_ReturnType mars_gpio_mlbx_read(mars_instance_t *const mars_self, mars_gpio_level_en *const level)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if ((mars_self != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_Gpio_Driver_MLBX != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_Gpio_Driver_MLBX->read != NULL_PTR) && /* polyspace RTE:IDP,NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
            (level != NULL_PTR))
    {
        ret_val = mars_self->Mars_Drivers.Mars_Gpio_Driver_MLBX->read(MARS_L0_DRIVER_DATA(mars_self), level); /* polyspace RTE:COR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */

        if (ret_val != MARS_E_OK)
        {
            mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_GPIO_MLBX, MARS_NO_DATA);
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_GPIO_MLBX, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         read the value of the Mars GP0 IO pin
 * @param         mars_self mars driver instance reference
 * @param         level pointer to host memory where the level value will be written
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-278635 GID-286465 GID-346253
 */
Mars_ReturnType mars_gpio_gp0_read(mars_instance_t *const mars_self, mars_gpio_level_en *const level)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if ((mars_self != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_Gpio_Driver_GP0 != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_Gpio_Driver_GP0->read != NULL_PTR) && /* polyspace RTE:IDP,NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
            (level != NULL_PTR))
    {
        ret_val = mars_self->Mars_Drivers.Mars_Gpio_Driver_GP0->read(MARS_L0_DRIVER_DATA(mars_self), level); /* polyspace RTE:COR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */

        if (ret_val != MARS_E_OK)
        {
            mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_GPIO_GP0, MARS_NO_DATA);
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_GPIO_GP0, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         read the value of the Mars SFT ERR IO pin
 * @param         mars_self mars driver instance reference
 * @param         level pointer to host memory where the level value will be written
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-346255 GID-278636 GID-286467
 */
Mars_ReturnType mars_gpio_sft_read(mars_instance_t *const mars_self, mars_gpio_level_en *const level)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if ((mars_self != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_Gpio_Driver_SFT != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_Gpio_Driver_SFT->read != NULL_PTR) && /* polyspace RTE:IDP,NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
            (level != NULL_PTR))
    {
        ret_val = mars_self->Mars_Drivers.Mars_Gpio_Driver_SFT->read(MARS_L0_DRIVER_DATA(mars_self), level); /* polyspace RTE:COR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */

        if (ret_val != MARS_E_OK)
        {
            mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_GPIO_SFT, MARS_NO_DATA);
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_GPIO_SFT, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         write the value of the Mars RESET_N pin
 * @param         mars_self mars driver instance reference
 * @param         level value to be written to the IO
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-278637 GID-286469 GID-346257
 */
Mars_ReturnType mars_gpio_reset_write(mars_instance_t *const mars_self, const mars_gpio_level_en level)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if ((mars_self != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_Gpio_Driver_Reset != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_Gpio_Driver_Reset->write != NULL_PTR)) /* polyspace RTE:IDP,NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
    {
        ret_val = mars_self->Mars_Drivers.Mars_Gpio_Driver_Reset->write(MARS_L0_DRIVER_DATA(mars_self), level); /* polyspace RTE:COR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */

        if (ret_val != MARS_E_OK)
        {
            mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_GPIO_RESET, MARS_NO_DATA);
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_GPIO_RESET, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         write the value of the FRM_EN pin directly (immediate change )
 * @param         mars_self mars driver instance reference
 * @param         level value to be written to the IO
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-346258 GID-278638 GID-286471
 */
Mars_ReturnType mars_gpio_frm_en_write(mars_instance_t *const mars_self, const mars_gpio_level_en level)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if ((mars_self != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_OC_Driver != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_OC_Driver->write != NULL_PTR)) /* polyspace RTE:IDP,NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
    {
        ret_val = mars_self->Mars_Drivers.Mars_OC_Driver->write(MARS_L0_DRIVER_DATA(mars_self), level); /* polyspace RTE:COR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */

        if (ret_val != MARS_E_OK)
        {
            mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_OC, MARS_NO_DATA);
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_OC, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         write the value of the FRM_EN pin at a later time (delayed timed trigger)
 * @param         mars_self mars driver instance reference
 * @param         timestamp future timepoint when the FRM_EN pin will be toggled
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-278639 GID-286473 GID-346263
 */
Mars_ReturnType mars_oc_frm_en_set(mars_instance_t *const mars_self, const uint64 timestamp)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    if ((mars_self != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_OC_Driver != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_OC_Driver->set_oc != NULL_PTR)) /* polyspace RTE:IDP,NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
    {
        ret_val = mars_self->Mars_Drivers.Mars_OC_Driver->set_oc(MARS_L0_DRIVER_DATA(mars_self), timestamp); /* polyspace RTE:COR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */

        if (ret_val != MARS_E_OK)
        {
            mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_OC, MARS_NO_DATA);
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_OC, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

#ifndef MARS_DEBUG_SUPPORT_DISABLED
/**
 * @brief         write the value of the TE pin
 * @param         mars_self mars driver instance reference
 * @param         level value to be written to the IO
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-402012 GID-402014 GID-402016
 */
Mars_ReturnType mars_gpio_te_write(mars_instance_t *const mars_self, const mars_gpio_level_en level)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if (mars_self != NULL_PTR)
    {
        /* TE pin is optional and not used in all setups. We shall handle where TE driver is null, that is a valid case */
        if (mars_self->Mars_Drivers.Mars_Gpio_Driver_TE != NULL_PTR)
        {
            if (mars_self->Mars_Drivers.Mars_Gpio_Driver_TE->write != NULL_PTR) /* polyspace RTE:IDP,NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
            {
                ret_val = mars_self->Mars_Drivers.Mars_Gpio_Driver_TE->write(MARS_L0_DRIVER_DATA(mars_self), level); /* polyspace RTE:COR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
                if (ret_val != MARS_E_OK)
                {
                    mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_GPIO_TE, MARS_NO_DATA);
                }
            }
            else
            {
                mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_GPIO_TE, MARS_L1_E_NOT_OK_PARAM);
            }
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_GPIO_TE, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}
#endif
