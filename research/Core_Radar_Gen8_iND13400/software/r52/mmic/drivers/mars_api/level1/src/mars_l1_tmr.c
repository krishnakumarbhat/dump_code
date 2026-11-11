/* @copyright 2024 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_l1.h"

/**********************************************************************************************************************
 * LOCAL ENUMERATIONS
 *********************************************************************************************************************/
typedef enum
{
    MARS_WAIT_MICROSECONDS = 0, /* Enum for identifying wait time in us */
    MARS_WAIT_MILLISECONDS,      /* Enum for identifying wait time in ms */
} mars_waittime_type_en;

/**********************************************************************************************************************
 * LOCAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/
static Mars_ReturnType mars_wait(mars_instance_t *const mars_self, const uint32 wait_time, const mars_waittime_type_en wait_type);
/**********************************************************************************************************************
 * GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**
 * @brief         Initialize performs a blocking wait for the given number of microseconds
 * @param         mars_self mars driver instance reference
 * @param         wait_time the wait wait_time in microseconds
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-345256 GID-278652 GID-286187 
 */
Mars_ReturnType mars_wait_us(mars_instance_t *const mars_self, const uint32 wait_time)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_wait(mars_self, wait_time, MARS_WAIT_MICROSECONDS);
    return ret_val;
}

/**
 * @brief         Initialize performs a blocking wait for the given number of milliseconds
 * @param         mars_self mars driver instance reference
 * @param         wait_time the wait wait_time in milliseconds
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-278654 GID-286197 GID-345250
 */
Mars_ReturnType mars_wait_ms(mars_instance_t *const mars_self, const uint32 wait_time)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_wait(mars_self, wait_time, MARS_WAIT_MILLISECONDS);
    return ret_val;
}

/**
 * @brief         Initialize performs a blocking wait either usec or millisec
 * @param         mars_self mars driver instance reference
 * @param         wait_time the wait wait_time in milliseconds
 * @param         wait_type either microseconds or milliseconds
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-345258
 */
static Mars_ReturnType mars_wait(mars_instance_t *const mars_self, const uint32 wait_time, const mars_waittime_type_en wait_type)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if ((mars_self != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_TMR_Driver != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_TMR_Driver->wait_us != NULL_PTR) && /* polyspace RTE:IDP,NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
            (mars_self->Mars_Drivers.Mars_TMR_Driver->wait_ms != NULL_PTR)) /* polyspace RTE:NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
    {
        switch (wait_type)
        {
            case MARS_WAIT_MICROSECONDS:
                ret_val = mars_self->Mars_Drivers.Mars_TMR_Driver->wait_us(MARS_L0_DRIVER_DATA(mars_self), wait_time); /* polyspace RTE:COR [No action planned:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
                break;
            case MARS_WAIT_MILLISECONDS:
                ret_val = mars_self->Mars_Drivers.Mars_TMR_Driver->wait_ms(MARS_L0_DRIVER_DATA(mars_self), wait_time); /* polyspace RTE:COR [No action planned:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
                break;
            default: /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the input parameter not with valid value" */
                ret_val = MARS_L1_E_NOT_OK_PARAM;
                break;
        }

        if (ret_val != MARS_E_OK)
        {
            mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_TMR, MARS_NO_DATA);
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_TMR, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}
