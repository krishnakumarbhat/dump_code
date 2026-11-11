/* @copyright 2024 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#include "r52_l0_ssi.h"
#include "TCM_LIB.h"
#include "r52_l0_util.h"
#include "mars_l0_tunables.h"

/**********************************************************************************************************************
 *  LOCAL MACRO DECLARATIONS
 *********************************************************************************************************************/
#define ARM_SPI_DRV_VERSION_EXPECTED    0x20e /**< expected driver version */
#define ARM_SPI_API_VERSION_EXPECTED    0x204 /**< expected API version */

/* we will just return the last 8 bits of the error. However the standard BUSY report
 * is a negative number, and conversion is deprecated by the MISRA checker.
 * Regardless, the result is the same number: MARS_ERROR_DRIVER_SSI | 0xFE
 */
#if (ARM_DRIVER_ERROR_BUSY < 0)
#define ARM_SPI_DRIVER_ERROR_BUSY (0xFFFFFFFFuL - (uint32)(-(ARM_DRIVER_ERROR_BUSY+1)))
#else
#define ARM_SPI_DRIVER_ERROR_BUSY ((uint32)(ARM_DRIVER_ERROR_BUSY))
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/
static Mars_ReturnType mars_l0_ssi_init(mars_driver_data_t driver_data);
static Mars_ReturnType mars_l0_ssi_set_mode(mars_driver_data_t driver_data,const mars_l0_ssi_mode_en mode);
static Mars_ReturnType mars_l0_ssi_get_mode(mars_driver_data_t driver_data, mars_l0_ssi_mode_en *const mode);
static Mars_ReturnType mars_l0_ssi_set_speed_chandra_evb(mars_driver_data_t driver_data, const mars_l0_ssi_speed_en speed);
static Mars_ReturnType mars_l0_ssi_set_speed_edu(mars_driver_data_t driver_data, const mars_l0_ssi_speed_en speed);
static Mars_ReturnType mars_l0_ssi_spi_transfer(mars_driver_data_t driver_data, const uint32 *const txdata, uint32 *const rxdata, const uint32 size);
static Mars_ReturnType mars_l0_ssi_qspi_send(mars_driver_data_t driver_data, const uint32 *const txdata, const uint32 size, const uint16 inst, const uint32 addr);
static Mars_ReturnType mars_l0_ssi_qspi_receive(mars_driver_data_t driver_data, uint32 *const rxdata, const uint32 size, const uint16 inst, const uint32 addr);
static inline Mars_ReturnType mars_l0_ssi_set_ssi_speed(mars_driver_data_t driver_data, const mars_l0_ssi_speed_en speed, uint32 delay_high, uint32 delay_low);
/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/
mars_l0_ssi_t r52_l0_ssi_chandra_evb = {.init = &mars_l0_ssi_init, /* polyspace VARIABLE:ALL [No action planned:Low] "Required for Mars instance definition" */
                                        .set_mode = &mars_l0_ssi_set_mode,
                                        .get_mode = &mars_l0_ssi_get_mode,
                                        .set_speed = &mars_l0_ssi_set_speed_chandra_evb,
                                        .spi_transfer = &mars_l0_ssi_spi_transfer,
                                        .qspi_send = &mars_l0_ssi_qspi_send,
                                        .qspi_receive = &mars_l0_ssi_qspi_receive}; /*!< Layer 0 SSI definitions, Chandra EVB variant */

mars_l0_ssi_t r52_l0_ssi_edu = {.init = &mars_l0_ssi_init, /* polyspace VARIABLE:ALL [No action planned:Low] "Required for Mars instance definition" */
                                .set_mode = &mars_l0_ssi_set_mode,
                                .get_mode = &mars_l0_ssi_get_mode,
                                .set_speed = &mars_l0_ssi_set_speed_edu,
                                .spi_transfer = &mars_l0_ssi_spi_transfer,
                                .qspi_send = &mars_l0_ssi_qspi_send,
                                .qspi_receive = &mars_l0_ssi_qspi_receive}; /*!< Layer 0 SSI definitions, EDU variant */

/**********************************************************************************************************************
 *  LOCAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**
 * @brief         Initialize SSI driver for default communication in SPI mode low speed
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data 
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273535 GID-329096 GID-329093
 */
static Mars_ReturnType mars_l0_ssi_init(mars_driver_data_t driver_data)
{
    int32_t ret_v_drv = ARM_DRIVER_OK;
    Mars_ReturnType ret_val = MARS_E_OK;
    const ARM_DRIVER_VERSION ssi_driver_version_cmsis = Driver_SPI0.GetVersion(); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
    const mars_driver_version_t ssi_driver_version = {ssi_driver_version_cmsis.api, ssi_driver_version_cmsis.drv};
    const mars_driver_version_t ssi_driver_version_expected = {ARM_SPI_API_VERSION_EXPECTED,ARM_SPI_DRV_VERSION_EXPECTED};
    ret_val = mars_check_driver_version(ssi_driver_version,ssi_driver_version_expected);
    if (ret_val == MARS_E_OK)
    {
        (void)TCM_LIB_Init();
        ret_v_drv = Driver_SPI0.Uninitialize(); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */

        if (ret_v_drv == ARM_DRIVER_OK)
        {
            ret_v_drv = Driver_SPI0.Initialize(NULL_PTR); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
        }

        if (ret_v_drv == ARM_DRIVER_OK)
        {
#if defined(EDU_BOARD)
            ret_val = mars_l0_ssi_set_speed_edu(driver_data, L0_SSI_SPEED_LO);
#elif defined(CHANDRA_EVB_BOARD)
            ret_val = mars_l0_ssi_set_speed_chandra_evb(driver_data, L0_SSI_SPEED_LO);
#else
#error "No Host board variant selected."
#endif /* EDU_BOARD or CHANDRA_EVB_BOARD */

            if (ret_val == MARS_E_OK)
            {
                ret_val = mars_l0_ssi_set_mode(driver_data, L0_SSI_MODE_SPI);
            }
        }
        else
        {
            ret_val = MARS_ERROR_DRIVER_SSI | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
        }
    }else
    {
        ret_val |= MARS_ERROR_DRIVER_SSI;
    }


    return ret_val;
}

/**
 * @brief         Set the communication speed of the SSI driver, Chandra EVB variant
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    speed the requested communication speed HI or LO
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-329083  GID-329105 GID-273616
 */
static Mars_ReturnType mars_l0_ssi_set_speed_chandra_evb(mars_driver_data_t driver_data, const mars_l0_ssi_speed_en speed)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_l0_ssi_set_ssi_speed(driver_data, speed, RX_DELAY_TIME_EVB_HI, RX_DELAY_TIME_EVB_LO);
    return ret_val;
}

/**
 * @brief         Set the communication speed of the SSI driver, EDU variant
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    speed the requested communication speed HI or LO
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-329083  GID-329105 GID-273616
 */
static Mars_ReturnType mars_l0_ssi_set_speed_edu(mars_driver_data_t driver_data, const mars_l0_ssi_speed_en speed)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_l0_ssi_set_ssi_speed(driver_data, speed, RX_DELAY_TIME_EDU_HI, RX_DELAY_TIME_EDU_LO);
    return ret_val;
}

/**
 * @brief         Set the communication mode of the SSI driver (SPI or QSPI)
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    mode the requested communication mode
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-329089 GID-329099 GID-273536
 */
static Mars_ReturnType mars_l0_ssi_set_mode(mars_driver_data_t driver_data, const mars_l0_ssi_mode_en mode)
{
    int32_t ret_v_drv = ARM_DRIVER_OK;
    Mars_ReturnType ret_val = MARS_E_OK;

    /* This CMSIS driver can operate correctly only if the speed parameter is passed along with the mode */
    const uint32 speed = (driver_data[MARS_SSI_SPEED_INDEX] == (uint32)L0_SSI_SPEED_LO) ? SSI_CLOCK_SPEED_LO : SSI_CLOCK_SPEED_HI;

    if( mode == L0_SSI_MODE_SPI) 
    {
        ret_v_drv = Driver_SPI0.Control(ARM_SPI_MODE_MASTER | ARM_SPI_CPOL0_CPHA0 | ARM_SPI_MSB_LSB | ARM_SPI_DATA_BITS(32u) | ARM_SPI_POLLING_MODE, speed);
    }
    else if( mode == L0_SSI_MODE_QSPI)  /* polyspace RTE:UNR [No action Planned:Low] "Not unreachable code based on input parameter" */
    {
        ret_v_drv = Driver_SPI0.Control(ARM_SPI_MODE_QSPI | ARM_INST_QSPI_ADDR_QSPI | ARM_SPI_CPOL0_CPHA0 | ARM_SPI_MSB_LSB | ARM_QSPI_INST_L16 | ARM_QSPI_ADDR_L16 | ARM_SPI_DATA_BITS(32u) | ARM_SPI_POLLING_MODE, speed);
    }
    else
    {
        ret_val =  MARS_ERROR_L0_SSI | MARS_L0_E_NOT_OK_SET_MODE ;
    }

    if (ret_v_drv != ARM_DRIVER_OK)
    {
        ret_val = MARS_ERROR_DRIVER_SSI | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
    }
    else
    {
        if (ret_val == MARS_E_OK) /* polyspace RTE:UNR [Not a defect:Low] "Condition guards against storing an invalid mode/speed value; false branch is reachable with out-of-range enum inputs" */
        {
            driver_data[MARS_SSI_MODE_INDEX] = (uint32)mode;
        }
    }

    return ret_val;
}

/**
 * @brief         Get the communication mode of the SSI driver
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [out]    speed the actual operation mode SPI or QSPI
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-329102 GID-329086 GID-273615
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
static Mars_ReturnType mars_l0_ssi_get_mode(mars_driver_data_t driver_data, mars_l0_ssi_mode_en *const mode)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    if ((NULL_PTR != mode) && (driver_data != NULL_PTR))
    {
        /* l0_ssi_mode is stored locally in this wrapper and valid for this particular instance.
         * In case of two SSI instances the second one shall be in a separate compilation unit with its own local l0_ssi_mode variable */
        *mode = (driver_data[MARS_SSI_MODE_INDEX] == (uint32)L0_SSI_MODE_SPI) ? L0_SSI_MODE_SPI : L0_SSI_MODE_QSPI;
        ret_val = MARS_E_OK;
    }
    else
    {
        ret_val = MARS_ERROR_L0_SSI | MARS_L0_E_NOT_OK_PARAM;
    }

    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         Bi-directional SPI transfer
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    txdata data buffer to be transmitted
 * @param [out]   rxdata data buffer to be received
 * @param [in]    size the number of 32bit words to be transmitted
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273619 GID-329149 GID-329068
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
static Mars_ReturnType mars_l0_ssi_spi_transfer(mars_driver_data_t driver_data, const uint32 *const txdata, uint32 *const rxdata, const uint32 size)
{
    int32_t ret_v_drv = ARM_DRIVER_OK;
    Mars_ReturnType ret_val = MARS_E_OK;

    /* check if input parameters are valid */
    if ((driver_data != NULL_PTR) && (driver_data[MARS_SSI_MODE_INDEX] == (uint32)L0_SSI_MODE_SPI) && (NULL_PTR != txdata) && (NULL_PTR != rxdata) && (size > 0))
    {
        /* check the busy driver status before transfer */
        if (0U == Driver_SPI0.GetStatus().busy_status) /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
        {
            /* perform a pass-thru to the low level driver */
            ret_v_drv = Driver_SPI0.Transfer(txdata, rxdata, size); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */

            if (ret_v_drv == ARM_DRIVER_OK)
            {
                if (MARS_E_OK != Driver_SPI0.GetStatus().data_lost)
                {
                    ret_val = MARS_ERROR_DRIVER_SSI | (ARM_SPI_EVENT_DATA_LOST & MARS_ERROR_ID_BIT_MASK);
                }

                if ((MARS_E_OK != Driver_SPI0.GetStatus().mode_fault) && (ret_val == MARS_E_OK))
                {
                    ret_val = MARS_ERROR_DRIVER_SSI | (ARM_SPI_EVENT_MODE_FAULT & MARS_ERROR_ID_BIT_MASK);
                }
            }
            else
            {
                ret_val = MARS_ERROR_DRIVER_SSI | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
            }
        }
        else
        {
            ret_val = MARS_ERROR_DRIVER_SSI | (ARM_SPI_DRIVER_ERROR_BUSY & MARS_ERROR_ID_BIT_MASK);
        }
    }
    else
    {
        ret_val = MARS_ERROR_L0_SSI | MARS_L0_E_NOT_OK_PARAM;
    }
    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         QSPI transfer in transmit direction
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    txdata data buffer to be transmitted
 * @param [in]    size the number of 32bit words to be transmitted
 * @param [in]    inst QSPI transfer instruction word
 * @param [in]    addr QSPI transfer address
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-329152 GID-273644 GID-329073
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
static Mars_ReturnType mars_l0_ssi_qspi_send(mars_driver_data_t driver_data, const uint32 *const txdata, const uint32 size, const uint16 inst, const uint32 addr)
{
    int32_t ret_v_drv = ARM_DRIVER_OK;
    Mars_ReturnType ret_val = MARS_E_OK;

    /* check if input parameters are valid */
    if ((driver_data != NULL_PTR) && (driver_data[MARS_SSI_MODE_INDEX] == (uint32)L0_SSI_MODE_QSPI) && (NULL_PTR != txdata) && (size > 0))
    {
        /* check the busy driver status before transfer */
        if (0U == Driver_SPI0.GetStatus().busy_status) /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
        {
            /* perform a pass-thru to the low level driver */
            ret_v_drv = Driver_SPI0.Send(txdata, size, inst, addr); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */

            if (ret_v_drv == ARM_DRIVER_OK)
            {
                if (MARS_E_OK != Driver_SPI0.GetStatus().data_lost)
                {
                    ret_val = MARS_ERROR_DRIVER_SSI | (ARM_SPI_EVENT_DATA_LOST & MARS_ERROR_ID_BIT_MASK);
                }
                if ((ret_val == MARS_E_OK) && (0 != Driver_SPI0.GetStatus().mode_fault))
                {
                    ret_val = MARS_ERROR_DRIVER_SSI | (ARM_SPI_EVENT_MODE_FAULT & MARS_ERROR_ID_BIT_MASK);
                }
            }
            else
            {
                ret_val = MARS_ERROR_DRIVER_SSI | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
            }
        }
        else
        {
            ret_val = MARS_ERROR_DRIVER_SSI | (ARM_SPI_DRIVER_ERROR_BUSY & MARS_ERROR_ID_BIT_MASK);
        }
    }
    else
    {
        ret_val = MARS_ERROR_L0_SSI | MARS_L0_E_NOT_OK_PARAM;
    }

    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         QSPI transfer in transmit direction
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [out]   rxdata data buffer for reception
 * @param [in]    size the number of 32bit words to be received
 * @param [in]    inst QSPI transfer instruction word
 * @param [in]    addr QSPI transfer address
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-364551 GID-329077 GID-329155
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
static Mars_ReturnType mars_l0_ssi_qspi_receive(mars_driver_data_t driver_data, uint32 *const rxdata, const uint32 size, const uint16 inst, const uint32 addr)
{
    int32_t ret_v_drv = ARM_DRIVER_OK;
    Mars_ReturnType ret_val = MARS_E_OK;

    /* check if input parameters are valid */
    if ((driver_data != NULL_PTR) && (driver_data[MARS_SSI_MODE_INDEX] == (uint32)L0_SSI_MODE_QSPI) && (NULL_PTR != rxdata) && (size > 0))
    {
        /* check the busy driver status before transfer */
        if (0U != Driver_SPI0.GetStatus().busy_status) /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
        {
            ret_val = MARS_ERROR_DRIVER_SSI | (ARM_SPI_DRIVER_ERROR_BUSY & MARS_ERROR_ID_BIT_MASK);
        }
        else
        {
            /* perform a pass-thru to the low level driver */
            ret_v_drv = Driver_SPI0.Receive(rxdata, size, inst, addr, RX_WAIT_CYCLES_QSPI); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */

            if (ret_v_drv != ARM_DRIVER_OK)
            {
                ret_val = MARS_ERROR_DRIVER_SSI | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
            }
            else
            {
                if (0 != Driver_SPI0.GetStatus().data_lost)
                {
                    ret_val = MARS_ERROR_DRIVER_SSI | (ARM_SPI_EVENT_DATA_LOST & MARS_ERROR_ID_BIT_MASK);
                }
                if ((0 != Driver_SPI0.GetStatus().mode_fault) && (ret_val == MARS_E_OK))
                {
                    ret_val = MARS_ERROR_DRIVER_SSI | (ARM_SPI_EVENT_MODE_FAULT & MARS_ERROR_ID_BIT_MASK);
                }
            }
        }
    }
    else
    {
        ret_val = MARS_ERROR_L0_SSI | MARS_L0_E_NOT_OK_PARAM;
    }

    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */


/**
 * @brief         Set the communication speed of the SSI driver
 * @param[in]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    speed the requested communication speed HI or LO
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273652 GID-364562 GID-353192
 */
static inline Mars_ReturnType mars_l0_ssi_set_ssi_speed(mars_driver_data_t driver_data, const mars_l0_ssi_speed_en speed, uint32 delay_high, uint32 delay_low)
{
    int32_t ret_v_drv = ARM_DRIVER_OK;
    Mars_ReturnType ret_val = MARS_E_OK;
    if(driver_data == NULL_PTR)
    {
        ret_val = MARS_ERROR_L0_SSI | MARS_L0_E_NOT_OK_PARAM;
    }
    else
    {
        /* call the low level control functions to change the SSI speed */
        switch (speed)
        {
            case L0_SSI_SPEED_HI:
                ret_v_drv = Driver_SPI0.Control(ARM_SPI_SET_BUS_SPEED, SSI_CLOCK_SPEED_HI); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
                if (ret_v_drv == ARM_DRIVER_OK)
                {
                    ret_v_drv = Driver_SPI0.Control(ARM_SPI_SET_RX_DELAY, delay_high);
                }
                break;
            case L0_SSI_SPEED_LO:
                ret_v_drv = Driver_SPI0.Control(ARM_SPI_SET_BUS_SPEED, SSI_CLOCK_SPEED_LO); /* polyspace RTE:COR [Not a defect:Medium] "The pointer points to constant which will not change in the run time so no need to be checked against NULL to be solved after including the driver files" */
                if (ret_v_drv == ARM_DRIVER_OK)
                {
                    ret_v_drv = Driver_SPI0.Control(ARM_SPI_SET_RX_DELAY, delay_low);
                }
                break;
            default:/* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the input parameter not with valid value" */
                ret_val = MARS_ERROR_L0_SSI | MARS_L0_E_NOT_OK_SET_SPEED;
                break;
        }
    
        if (ret_v_drv == ARM_DRIVER_OK)
        {
            if (ret_val == MARS_E_OK) /* polyspace RTE:UNR [Not a defect:Low] "Condition guards against storing an invalid mode/speed value; false branch is reachable with out-of-range enum inputs" */
            {
                driver_data[MARS_SSI_SPEED_INDEX] = (uint32)speed;
            }
        }
        else
        {
            ret_val = MARS_ERROR_DRIVER_SSI | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
        }
    }
    return ret_val;
}
