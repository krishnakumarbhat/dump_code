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
 * @brief         Set the SSI controller to the selected operation mode
 * @param         mars_self mars driver instance reference
 * @param         mode the requested operation mode
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-278678 GID-286578 GID-344846
 */
Mars_ReturnType mars_ssi_set_mode( mars_instance_t *const mars_self, const mars_ssi_mode_en mode)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if ((mars_self != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_SSI_Driver != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_SSI_Driver->set_mode != NULL_PTR)) /* polyspace RTE:IDP,NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
    {
        ret_val = mars_self->Mars_Drivers.Mars_SSI_Driver->set_mode(MARS_L0_DRIVER_DATA(mars_self),(mars_l0_ssi_mode_en)mode); /* polyspace RTE:COR [No action planned:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_SSI, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         Set the SSI controller to the selected communication speed
 * @param         mars_self mars driver instance reference
 * @param         speed the requested operation speed
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-278679 GID-344854 GID-286581
 */
Mars_ReturnType mars_ssi_set_speed( mars_instance_t *const mars_self, const mars_ssi_speed_en speed)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if ((mars_self != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_SSI_Driver != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_SSI_Driver->set_speed != NULL_PTR)) /* polyspace RTE:IDP,NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
    {
        ret_val = mars_self->Mars_Drivers.Mars_SSI_Driver->set_speed(MARS_L0_DRIVER_DATA(mars_self), (mars_l0_ssi_speed_en)speed); /* polyspace RTE:COR [No action planned:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_SSI, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}
