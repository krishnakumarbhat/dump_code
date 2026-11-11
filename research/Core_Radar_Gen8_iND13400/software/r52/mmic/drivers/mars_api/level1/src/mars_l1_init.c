/* @copyright 2024 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_l1.h"

/**********************************************************************************************************************
 * STATIC FUNCTIONS DECLARATION
 *********************************************************************************************************************/
static Mars_ReturnType mars_layer1_init_gpio( mars_instance_t *const mars_self);
static Mars_ReturnType mars_layer1_init_drivers_ex_gpio( mars_instance_t *const mars_self);

 /**********************************************************************************************************************
 * STATIC FUNCTIONS DEFINITION
 *********************************************************************************************************************/


/**
 * @brief         Initialize `GPIO` Layer1 by calling the underlying Layer0 driver inits
 * @param         mars_self mars driver instance reference
 * @return        MARS_E_OK if successful 
 * @design        GID-536519
 */
static Mars_ReturnType mars_layer1_init_gpio( mars_instance_t *const mars_self) /* polyspace GUIDELINE:SC18 [No action planned:Low] "Fixing the language scope will affect the readability of the function" */ /* polyspace GUIDELINE:SC15 [No action planned:Low] "Reducing the number of static paths will affect the readability of the function" */
{
    Mars_ReturnType ret_val = MARS_E_OK;
    /* polyspace-begin RTE:IDP,NIP,COR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
    const mars_instance_drivers_t * const drivers = &mars_self->Mars_Drivers;

    /* Initialize GPIO driver of Mars GP0 pin */
    mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_GPIO_GP0, MARS_L1_E_NOT_OK_PARAM);
    if (drivers->Mars_Gpio_Driver_GP0 != NULL_PTR)
    {
        if (drivers->Mars_Gpio_Driver_GP0->init != NULL_PTR)
        {
            ret_val = drivers->Mars_Gpio_Driver_GP0->init(MARS_L0_DRIVER_DATA(mars_self));
        }
    }

    if (ret_val == MARS_E_OK)
    {
        /* Initialize GPIO driver of Mars RESET pin */
        mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_GPIO_RESET, MARS_L1_E_NOT_OK_PARAM);
        if (drivers->Mars_Gpio_Driver_Reset != NULL_PTR)
        {
            if (drivers->Mars_Gpio_Driver_Reset->init != NULL_PTR)
            {
                ret_val = drivers->Mars_Gpio_Driver_Reset->init(MARS_L0_DRIVER_DATA(mars_self));
            }
        }
    }
    if (ret_val == MARS_E_OK)
    {
        /* Initialize GPIO driver of Mars MLBX pin */
        mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_GPIO_MLBX, MARS_L1_E_NOT_OK_PARAM);
        if (drivers->Mars_Gpio_Driver_MLBX != NULL_PTR)
        {
            if (drivers->Mars_Gpio_Driver_MLBX->init != NULL_PTR)
            {
                ret_val = drivers->Mars_Gpio_Driver_MLBX->init(MARS_L0_DRIVER_DATA(mars_self));
            }
        }
    }
    if (ret_val == MARS_E_OK)
    {
        /* Initialize GPIO driver of Mars SFT pin */
        mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_GPIO_SFT, MARS_L1_E_NOT_OK_PARAM);
        if (drivers->Mars_Gpio_Driver_SFT != NULL_PTR)
        {
            if (drivers->Mars_Gpio_Driver_SFT->init != NULL_PTR)
            {
                ret_val = drivers->Mars_Gpio_Driver_SFT->init( MARS_L0_DRIVER_DATA(mars_self));
            }
        }
    }
#ifndef MARS_DEBUG_SUPPORT_DISABLED
    if (ret_val == MARS_E_OK)
    {
        /* TE pin is optional, therefore we perform the init only if TE driver is configured */
        if (drivers->Mars_Gpio_Driver_TE != NULL_PTR)
        {
            /* Initialize GPIO driver of Mars TE pin */
            mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_GPIO_TE, MARS_L1_E_NOT_OK_PARAM);
            if (drivers->Mars_Gpio_Driver_TE->init != NULL_PTR)
            {
                ret_val = drivers->Mars_Gpio_Driver_TE->init(MARS_L0_DRIVER_DATA(mars_self));
            }
        }
    }
#endif

    /* polyspace-end RTE:IDP,NIP,COR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
    return ret_val; 
}

/**
 * @brief         Initialize drivers Layer1 by calling the underlying Layer0 driver inits
 * @param         mars_self mars driver instance reference
 * @return        MARS_E_OK if successful 
 * @design        GID-536520
 */
static Mars_ReturnType mars_layer1_init_drivers_ex_gpio( mars_instance_t *const mars_self) /* polyspace GUIDELINE:SC18 [No action planned:Low] "Fixing the language scope will affect the readability of the function" */
{
    Mars_ReturnType ret_val = MARS_E_OK;
    /* polyspace-begin RTE:IDP,NIP,COR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
    const mars_instance_drivers_t * const drivers = &mars_self->Mars_Drivers;

    /* Initialize SSI driver */
    mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_SSI, MARS_L1_E_NOT_OK_PARAM);
    if (drivers->Mars_SSI_Driver != NULL_PTR)
    {
        if (drivers->Mars_SSI_Driver->init != NULL_PTR)
        {
            ret_val = drivers->Mars_SSI_Driver->init(MARS_L0_DRIVER_DATA(mars_self));
        }
    }

    if (ret_val == MARS_E_OK)
    {
        mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_TMR, MARS_L1_E_NOT_OK_PARAM);
        /* Initialize TMR driver */
        if (drivers->Mars_TMR_Driver != NULL_PTR)
        {
            if (drivers->Mars_TMR_Driver->init != NULL_PTR)
            {
                ret_val = drivers->Mars_TMR_Driver->init(MARS_L0_DRIVER_DATA(mars_self));
            }
        }
    }

    if (ret_val == MARS_E_OK)
    {
        /* Initialize CRC driver */
        mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_CRC, MARS_L1_E_NOT_OK_PARAM);
        if (drivers->Mars_CRC_Driver != NULL_PTR)
        {
            if (drivers->Mars_CRC_Driver->init != NULL_PTR)
            {
                ret_val = drivers->Mars_CRC_Driver->init(MARS_L0_DRIVER_DATA(mars_self));
            }
        }
    }
    if (ret_val == MARS_E_OK)
    {
        /* Initialize Output Compare driver */
        mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_OC, MARS_L1_E_NOT_OK_PARAM);
        if (drivers->Mars_OC_Driver != NULL_PTR)
        {
            if (drivers->Mars_OC_Driver->init != NULL_PTR)
            {
                ret_val = drivers->Mars_OC_Driver->init(MARS_L0_DRIVER_DATA(mars_self));
            }
        }
    }
    /* polyspace-end RTE:IDP,NIP,COR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
    return ret_val;
}

/**********************************************************************************************************************
 * GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**
 * @brief         Initialize Layer1 by calling the underlying Layer0 driver inits
 * @param         mars_self mars driver instance reference
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-345262 GID-278646 GID-286192
 */
Mars_ReturnType mars_layer1_init( mars_instance_t *const mars_self)
{
    /* polyspace-begin RTE:UNR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
    /* TODO: add extra checks for verifying the completeness of mars_self drivers */
    Mars_ReturnType ret_val = MARS_E_NOT_OK;

    if (mars_self != NULL_PTR)
    {
        ret_val = mars_layer1_init_gpio(mars_self);
        
        
        if (ret_val == MARS_E_OK)
        {
            ret_val = mars_layer1_init_drivers_ex_gpio(mars_self);
        }


    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_INIT, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
    /* polyspace-end RTE:UNR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
}

