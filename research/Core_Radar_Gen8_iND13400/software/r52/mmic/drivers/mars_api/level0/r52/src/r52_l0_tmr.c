/* @copyright 2024 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */


#include "system_clk.h"
#include "r52_l0_tmr.h"
#include "mars_l0_tunables.h"

/**********************************************************************************************************************
 *  LOCAL MACROS
 *********************************************************************************************************************/

/* 1 / cpu_freq = 1 tick time in seconds, thus 1 000 000 000 / cpu_freq = 1 tick time value in ns */
#define MARS_TMR_CLK_NS_TO_US 1000uL
#define MARS_TMR_CLK_US_TO_MS 1000uL
#define MARS_TMR_CLK_1000NS 10000000uL
#define MARS_VALUE_NS_10_CPU_TICKS 10u
#define MARS_VALUE_NS_1000_INSTRUCTIONS 1000u

/**********************************************************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/
static Mars_ReturnType mars_l0_tmr_init(mars_driver_data_t driver_data);
static Mars_ReturnType mars_l0_tmr_wait_us(mars_driver_data_t driver_data, const uint32 wait_time);
static Mars_ReturnType mars_l0_tmr_wait_ms(mars_driver_data_t driver_data, const uint32 wait_time);
static Mars_ReturnType mars_l0_tmr_wait_time(const uint32 ticks, const uint32 wait_time);

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/
mars_l0_tmr_t r52_l0_tmr = {.init = &mars_l0_tmr_init, .wait_us = &mars_l0_tmr_wait_us, .wait_ms = &mars_l0_tmr_wait_ms}; /* polyspace VARIABLE:ALL [No action planned:Low] "Required for Mars instance definition" */

/**********************************************************************************************************************
 *  LOCAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**
 * @brief         Initialize Layer 0 Timers
 * @param[out]    driver_data pointer to the driver data array, used to store the layer 0 data
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273289 GID-329360 GID-329356
 */
static __attribute__((optnone)) Mars_ReturnType mars_l0_tmr_init(mars_driver_data_t driver_data)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    
    if (driver_data == NULL_PTR)
    {
        ret_val = MARS_ERROR_L0_TMR | MARS_L0_E_NOT_OK_PARAM;
    }
    else
    {
        driver_data[MARS_TMR_VALUE_NS_FOR_10_UTICKS_INDEX] = TMR_TMR_VALUE_NS_FOR_10_UTICKS_INITIAL_VALUE;
        /* The value is calculated once at init so it can be reused later when software wait loops are calculated */
        uint32 sys_clk = System_Clk_GetSysCurrentClock();

        if (sys_clk >= MARS_TMR_CLK_NS_TO_US)
        {
            sys_clk /= MARS_TMR_CLK_NS_TO_US;
            driver_data[MARS_TMR_VALUE_NS_FOR_10_UTICKS_INDEX] = (MARS_TMR_CLK_1000NS / sys_clk);
            ret_val = MARS_E_OK;
        }
        else
        {
            ret_val = MARS_ERROR_L0_TMR | MARS_L0_E_NOT_OK_PARAM;
        }
    }
    return ret_val;
}

/**
 * @brief         Blocking wait for the given number of microseconds - software loop timer
 * @param [in]    ticks software timer tuning
 * @param [in]    wait_time in microseconds
 * @return        MARS_E_OK or error
 * @design        GID-528650 GID-528651
 */
static  __attribute__((optnone)) Mars_ReturnType mars_l0_tmr_wait_time(const uint32 ticks,const uint32 wait_time)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    if (ticks > 0uL)    /* check value to avoid division by 0 */
    {
        /* Three way formula (re-order to avoid overflow of uint32) :
         * valueNS_for_10CPUticks (ns) ...... 10 ticks
         * (value_us * 1000)(ns) ............ x ticks (numberOfInstructions) */
        volatile uint32 number_of_instructions = ((wait_time * MARS_VALUE_NS_10_CPU_TICKS) / ticks) * MARS_VALUE_NS_1000_INSTRUCTIONS;

        /* In average, a while cycle consumes 10 instructions (calculated via T32 timer)*/
        while (MARS_TMR_SW_CYCLE_INSTR < number_of_instructions)
        {
            number_of_instructions -= MARS_TMR_SW_CYCLE_INSTR; /* polyspace RTE:OVFL [Not a defect:Medium] "The operation is check at the loop entry" */
        }
    }
    else
    {
        ret_val = MARS_ERROR_L0_TMR | MARS_L0_E_NOT_OK_INIT;
    }

    return ret_val;
}

/**
 * @brief         Blocking wait for the given number of microseconds
 * @param [in]    wait_time in microseconds
 * @param [in]    driver_data pointer to the driver data array, used to store the layer 0 data
 * @return        MARS_E_OK
 * @design        GID-273291 GID-329366 GID-329363
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
static Mars_ReturnType mars_l0_tmr_wait_us(mars_driver_data_t driver_data,const uint32 wait_time)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    if ((driver_data != NULL_PTR) && (wait_time > 0) && (wait_time <= MARS_TMR_CLK_NS_TO_US)) /* check wait_time to avoid overflow of calculation and to ensure the wait time is within the expected range for this API */
    {
        ret_val = mars_l0_tmr_wait_time(driver_data[MARS_TMR_VALUE_NS_FOR_10_UTICKS_INDEX], wait_time);
    }
    else
    {
        ret_val = MARS_ERROR_L0_TMR | MARS_L0_E_NOT_OK_PARAM;
    }

    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         Blocking wait for the given number of milliseconds
 * @param [in]  driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    wait_time in milliseconds
 * @return        MARS_E_OK
 * @design        GID-273317 GID-329372 GID-329369
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
static __attribute__((optnone)) Mars_ReturnType mars_l0_tmr_wait_ms(mars_driver_data_t driver_data, const uint32 wait_time)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    uint32 wait_time_tmp = wait_time;

    if(driver_data == NULL_PTR)
    {
        ret_val = MARS_ERROR_L0_TMR | MARS_L0_E_NOT_OK_PARAM;
    }
    else
    {
        while ((wait_time_tmp != 0) && (ret_val == MARS_E_OK) )
        {
            ret_val = mars_l0_tmr_wait_time(driver_data[MARS_TMR_VALUE_NS_FOR_10_UTICKS_INDEX], MARS_TMR_CLK_US_TO_MS); /* wait for 1 ms */
            wait_time_tmp--;
        }
    }

    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
