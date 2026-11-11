/* @copyright 2024 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_l1.h"
#include "mars_l1_raw.h"


#define MARS_L1_CRC_CONFIG_NUMBER 2u
/**********************************************************************************************************************
 * GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**
 * @brief         Configure CRC engine
 * @param         mars_self mars driver instance reference
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-352390 GID-352392 GID-352394
 */
Mars_ReturnType mars_configure_crc( mars_instance_t *const mars_self)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    const uint32 crc_config[][MARS_L1_CRC_CONFIG_NUMBER]=
    {
        {MARS_F_CPU_SYS_INIT_SEED, 0xFFFFFFFFu}, /* Init seed */
        {MARS_F_CPU_SYS_CTL_PAR_SEL, 3u},        /* CRC_PAR_32 */
        {MARS_F_CPU_SYS_CTL_OUT_REV, 0u},        /* Reverse bit endianness of CRC output */
        {MARS_F_CPU_SYS_CHN_SEL, 0u},            /* Channel 0 */
        {MARS_F_CPU_SYS_POLY_SEL_CH0, 3u},       /* Polynomial 04C11DB7 */
        {MARS_F_CPU_SYS_POLY_SEL_CH1, 3u},       /* Polynomial 04C11DB7 */
        {MARS_F_CPU_SYS_CTL_BIT_REV, 0u},        /* Reverse Bit Order */
        {MARS_F_CPU_SYS_CTL_BYTE_REV, 0u},       /* Reverse Byte Order */
        {MARS_F_CPU_SYS_CTL_BYTE_SHIFT, 0u}      /* No bytes shift */
    };

    /* Initialize SSI CRC driver */
    for(uint32 count = 0 ; count < (sizeof(crc_config)/sizeof(crc_config[0])) ; count++)
    {
        ret_val = mars_write_reg_raw(mars_self, crc_config[count][0], crc_config[count][1], MARS_L1_SAFE_CHK);
        if (ret_val != MARS_E_OK)
        {
            break;
        }
    }
    return ret_val;
}

/**
 * @brief         Calculates CRC32 of an array of 32bit values
 * @param         mars_self mars driver instance reference
 * @param [in]    data pointer to input data array
 * @param [in]    size length of data array in bytes
 * @param [out]   crc calculated CRC
 * @return        MARS_E_OK if successful MARS_L1/Driver ErrorID if failed
 * @design        GID-291671 GID-291679 GID-344816
 */
Mars_ReturnType mars_calculate_crc( mars_instance_t *const mars_self, const uint32 *const data, const uint32 size, uint32 *const crc)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if ((mars_self != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_CRC_Driver != NULL_PTR) &&
            (mars_self->Mars_Drivers.Mars_CRC_Driver->calculate != NULL_PTR) && /* polyspace RTE:IDP,NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
            (data != NULL_PTR) && (crc != NULL_PTR))
    {
        /* the function is just a wrapper around the underlying driver CRC without any transformation. */
        /* The CRC driver is handling the polynomial, XOR, bit swapping */
        ret_val = mars_self->Mars_Drivers.Mars_CRC_Driver->calculate(MARS_L0_DRIVER_DATA(mars_self),data, size, crc); /* polyspace RTE:COR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */

        if (ret_val != MARS_E_OK)
        {
            mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_CRC, MARS_NO_DATA);
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_CRC, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}
