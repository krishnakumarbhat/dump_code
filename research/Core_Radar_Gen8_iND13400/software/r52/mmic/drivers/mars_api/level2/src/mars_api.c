/* polyspace GUIDELINE:SC03 [No action planned:Low] "This file implements the APIs Layer 2 and calls actions functions and the needed Layer 1 interfaces." */
/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


#include "mars_l1.h"
#include "mars_l1_raw.h"
#include "mars_l1_validated_params.h"
#include "mars_l2_validated_params.h"
#include "mars_l2_actions.h"
#include "mars_l2_private.h"
#include "mars_api.h"



/**********************************************************************************************************************
 * LOCAL MACRO
 *********************************************************************************************************************/
#define MARS_TESTPATTERN_CHANNEL_SIZE 4u
#define MARS_START_CW_START_BIT_INDEX 12u
#define MARS_START_CW_CHANNEL_BIT_INDEX 10u

#define MARS_CAL_CTRL_WRITE_CMD_BIT_INDEX 10u
#define MARS_CAL_CTRL_WRITE_SIZE_BIT_INDEX 4u
#define MARS_CAL_CTRL_WRITE_CRC_BIT_INDEX 28u

#define MARS_CONFIGURE_BIST_CMD_BIT_INDEX 10u
#define MARS_CONFIGURE_BIST_SIZE_BIT_INDEX 4u
#define MARS_CONFIGURE_BIST_CRC_BIT_INDEX 28u

#define MARS_L2_ERR_MASK    0x3FFFFFuL

#define MARS_TP_CONFIG_NUMBER_OF_COLUMNS 2u

#define MARS_UID_CPU_SYS_SYSNAME_REG_INDEX 0u
#define MARS_UID_CPU_SYS_SYSREV_REG_INDEX 1u
#define MARS_UID_OTPM_UI_OTP_LOT_ID_REG_INDEX 2u
#define MARS_UID_OTPM_UI_OTP_WAFER_NUMBER_REG_INDEX 3u
#define MARS_UID_OTPM_UI_X_REG_INDEX 4u
#define MARS_UID_OTPM_UI_Y_REG_INDEX 5u

/**********************************************************************************************************************
 * LOCAL VARIABLE DECLARATION
 *********************************************************************************************************************/
static const struct
{
    uint32 tp_enable;
    uint32 tp_waveform_sel;
    uint32 tp_offset;
    uint32 tp_step;
    uint32 tp_ctl_poly_sel;
    uint32 tp_ctl_par_sel;
    uint32 tp_thr;
    uint32 tp_shift1_value;
    uint32 tp_shift2_value;
} MARS_TP_REGS[] = {
    {MARS_F_ASYNC_BANK_ASYNC_TP0_ENABLE, MARS_F_ASYNC_BANK_ASYNC_TP0_WAVEFORM_SEL, MARS_F_ASYNC_BANK_ASYNC_TP0_OFFSET, MARS_F_ASYNC_BANK_ASYNC_TP0_STEP, MARS_F_ASYNC_BANK_ASYNC_TP0_CTL_POLY_SEL,
     MARS_F_ASYNC_BANK_ASYNC_TP0_CTL_PAR_SEL, MARS_F_ASYNC_BANK_ASYNC_TP0_THR, MARS_F_ASYNC_BANK_ASYNC_TP0_SHIFT1_VALUE, MARS_F_ASYNC_BANK_ASYNC_TP0_SHIFT2_VALUE},
    {MARS_F_ASYNC_BANK_ASYNC_TP1_ENABLE, MARS_F_ASYNC_BANK_ASYNC_TP1_WAVEFORM_SEL, MARS_F_ASYNC_BANK_ASYNC_TP1_OFFSET, MARS_F_ASYNC_BANK_ASYNC_TP1_STEP, MARS_F_ASYNC_BANK_ASYNC_TP1_CTL_POLY_SEL,
     MARS_F_ASYNC_BANK_ASYNC_TP1_CTL_PAR_SEL, MARS_F_ASYNC_BANK_ASYNC_TP1_THR, MARS_F_ASYNC_BANK_ASYNC_TP1_SHIFT1_VALUE, MARS_F_ASYNC_BANK_ASYNC_TP1_SHIFT2_VALUE},
    {MARS_F_ASYNC_BANK_ASYNC_TP2_ENABLE, MARS_F_ASYNC_BANK_ASYNC_TP2_WAVEFORM_SEL, MARS_F_ASYNC_BANK_ASYNC_TP2_OFFSET, MARS_F_ASYNC_BANK_ASYNC_TP2_STEP, MARS_F_ASYNC_BANK_ASYNC_TP2_CTL_POLY_SEL,
     MARS_F_ASYNC_BANK_ASYNC_TP2_CTL_PAR_SEL, MARS_F_ASYNC_BANK_ASYNC_TP2_THR, MARS_F_ASYNC_BANK_ASYNC_TP2_SHIFT1_VALUE, MARS_F_ASYNC_BANK_ASYNC_TP2_SHIFT2_VALUE},
    {MARS_F_ASYNC_BANK_ASYNC_TP3_ENABLE, MARS_F_ASYNC_BANK_ASYNC_TP3_WAVEFORM_SEL, MARS_F_ASYNC_BANK_ASYNC_TP3_OFFSET, MARS_F_ASYNC_BANK_ASYNC_TP3_STEP, MARS_F_ASYNC_BANK_ASYNC_TP3_CTL_POLY_SEL,
     MARS_F_ASYNC_BANK_ASYNC_TP3_CTL_PAR_SEL, MARS_F_ASYNC_BANK_ASYNC_TP3_THR, MARS_F_ASYNC_BANK_ASYNC_TP3_SHIFT1_VALUE, MARS_F_ASYNC_BANK_ASYNC_TP3_SHIFT2_VALUE}};

/**********************************************************************************************************************
 * LOCAL FUNCTION DECLARATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL VARIABLE DECLARATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/
/**
 * @brief         Initialize MARS API driver
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful MARS_API_ID_INIT errors if failed
 * @design        GID-269270 GID-350950 GID-350953
 */
Mars_ReturnType mars_init(mars_instance_t *const mars_self)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    ret_val = mars_action_allow_api_call(mars_self, MARS_UNINTIALIZED, MARS_OPERATION_MODE_UNDEFINED, MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        /* Initialize the Action data */
        mars_action_init(mars_self);

        /* Initialize the Layer 1 */
        ret_val = mars_layer1_init(mars_self);

        if (MARS_E_OK == ret_val)
        {
            ret_val = mars_action_init_gpio_reset_write(mars_self);
        }

        if (MARS_E_OK == ret_val)
        {
            /* Set mode and configure SSI */
            ret_val = mars_action_ssi_set_mode(mars_self, MARS_SSI_SPI);
        }

        if (MARS_E_OK == ret_val)
        {
            /* Check MBL timeout and status */
            ret_val = mars_action_check_init_status(mars_self);
        }

        if (MARS_E_OK == ret_val)
        {
            MARS_DATA_OP_MODE_STATUS = MARS_OPERATION_MODE_NORMAL;
        }

    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_INIT;
    }

    return ret_val;
}

/**
 * @brief         Initialize MARS API driver and force the chip to debug mode.
 *                Debug mode is a special operation where the chip is omitting power-up HW tests.
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful MARS_API_ID_INIT_DEBUG errors if failed
 * @design        GID-351044 GID-269271 GID-351052
 */
#ifndef MARS_DEBUG_SUPPORT_DISABLED
Mars_ReturnType mars_init_debug(mars_instance_t *const mars_self)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    ret_val = mars_action_allow_api_call(mars_self, MARS_UNINTIALIZED, MARS_OPERATION_MODE_UNDEFINED, MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        /* Initialize the Action data */
        mars_action_init(mars_self);

        /* Initialize the Layer 1 */
        ret_val = mars_layer1_init(mars_self);

        if (MARS_E_OK == ret_val)
        {
            ret_val = mars_action_init_debug_gpio_reset_write(mars_self);
        }

        if (MARS_E_OK == ret_val)
        {
            /* Set mode and configure SSI */
            ret_val = mars_action_ssi_set_mode(mars_self, MARS_SSI_SPI);
        }

        if (MARS_E_OK == ret_val)
        {
                /* Check MBL timeout and status */
            ret_val = mars_action_check_init_status(mars_self);
        }

        if (MARS_E_OK == ret_val)
        {
            MARS_DATA_OP_MODE_STATUS = MARS_OPERATION_MODE_DEBUG;
        }

    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_INIT_DEBUG;
    }

    return ret_val;
}
#endif

/**
 * @brief         Read the results of the BIST
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   results results from BIST
 * @return        MARS_E_OK if successful MARS_E_OK if failed
 * @design        GID-347876 GID-347883 GID-347911
 */
Mars_ReturnType mars_read_bist_result( mars_instance_t *const mars_self, mars_bist_result_t *const results)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    /* Keep SFT pin reporting minimally gated: only require valid pointers and initialized API */
    if ((NULL_PTR != mars_self) &&
        (NULL_PTR != results) &&
        (0u == (MARS_DATA_DRIVER_STATUS & MARS_UNINTIALIZED)))
    {
        results->safety_error_detected = mars_action_sft_is_active(mars_self);
    }

    ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INITIALIZED_FW_NOT_RUNNING | MARS_INIT_IDLE_OPERATIONAL | MARS_BUSY), (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if (NULL_PTR == results)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        else
        {
            /* If device is busy, verify MAF state first before continuing with BIST reads */
            if ((mars_driver_status_t)MARS_BUSY == MARS_DATA_DRIVER_STATUS)
            {
                ret_val= mars_action_check_maf_state(mars_self, MARS_RDY_TIMEOUT_US);
            }

            if (ret_val == MARS_E_OK)
            {
                ret_val = mars_action_check_sft_registers(mars_self, results);

                if (MARS_E_OK == ret_val)
                {
                    ret_val = mars_action_read_hw_registers(mars_self, results);
                }

                if (MARS_E_OK == ret_val)
                {
                    ret_val = mars_action_read_diagnostic_memory(mars_self, results);
                }
            }
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_READ_BIST_RESULT;
    }

    return ret_val;
}

/**
 * @brief         Configures BIST performed during the next Frame Tx
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    test_id multi-select bitfield identifier(s) of the the test
 * @return        MARS_E_OK if successful MARS_E_OK if failed
 * @design        GID-347888 GID-320492 GID-269251
 */
Mars_ReturnType mars_configure_bist(mars_instance_t *const mars_self, const mars_bist_config_t test_id)
{
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INIT_IDLE_OPERATIONAL), (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_FW_VERSION_MIN_COMPATIBLE, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if (NULL_PTR == test_id)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        
        if (MARS_E_OK == ret_val)
        {
            ret_val = mars_write_mem_safe(mars_self, (const uint32 * const)test_id, MARS_SCRATCHPAD_CFG_START_ADDRESS, MARS_SCP_CONFIGURE_BIST_WORDS);
        }

        if (MARS_E_OK == ret_val)
        {
            uint32 scp_crc = 0u;
            ret_val = mars_calculate_crc(mars_self, (const uint32 *const )test_id, MARS_SCP_CONFIGURE_BIST_WORDS * sizeof(uint32), &scp_crc);
            if (MARS_E_OK == ret_val)
            {
                mars_mailbox_req_t mlbx_request = {0};
                mars_mailbox_resp_t mlbx_response = {0};
                mlbx_request.slot = MARS_MLBX_SLOT_GEN_CMD;
                mlbx_request.command = MARS_MLBX_CMD_ML_RDR_SCP;
                mlbx_request.var_h = (uint32)((MARS_MLBX_SUBCMD_SCP_CONFIGBIST << MARS_CONFIGURE_BIST_CMD_BIT_INDEX) | (MARS_SCP_CONFIGURE_BIST_WORDS << MARS_CONFIGURE_BIST_SIZE_BIT_INDEX) | (scp_crc >> MARS_CONFIGURE_BIST_CRC_BIT_INDEX));
                mlbx_request.var_l = (scp_crc & 0x0FFFFFFFuL);
                /* Send mailbox request and wait for the response */
                ret_val = mars_exchange_mlbx(mars_self, &mlbx_request, &mlbx_response, MARS_MLBX_TIMEOUT_US);
                if (MARS_E_OK == ret_val)
                {
                    ret_val = mars_action_scp_configbist_set_mlbx_response(mars_self, (uint8)mlbx_response.response, (uint16)mlbx_response.var_h, (uint32)mlbx_response.var_l);
                }
            }
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_CONFIGURE_BIST;
    }

    return ret_val;
}

/**
 * @brief         Reads back the actual BIST configuration from MAF
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   test_id actual MAF configuration of the built in self tests
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 * @design        GID-448270 GID-448272 GID-448274
 */
Mars_ReturnType mars_configure_bist_read( mars_instance_t *const mars_self, mars_bist_config_t test_id)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INIT_IDLE_OPERATIONAL), (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_FW_VERSION_MIN_COMPATIBLE, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if (NULL_PTR == test_id)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }

        if (MARS_E_OK == ret_val)
        {
            ret_val = mars_action_scp_read_back(mars_self, MARS_MLBX_SUBCMD_RD_BACK_CONFIGBIST, (uint32 *const)test_id, MARS_SCP_CONFIGURE_BIST_WORDS);
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_CONFIGURE_BIST_READ;
    }

    return ret_val;
}

/**
 * @brief         Starts CW transmission. See also mars_convert_frequency_phys_to_raw and mars_convert_phase_phys_to_raw
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    channel TX channel ID is the channel index in the range of 0..3
 * @param [in]    raw_phase CW phase value valid range [0..511], that is the index to the phase LUT
 *                see mars_convert_phase_phys_to_raw to use physical values in degrees.
 * @param [in]    raw_frequency CW frequency raw value valid range [8039082..10223616]
 *                see mars_convert_frequency_phys_to_raw to use physical values in Hz.
 * @return        MARS_E_OK if successful MARS_API_ID_START_CW errors if failed
 * @design        GID-269252 GID-350829 GID-350832
 */
Mars_ReturnType mars_start_cw(mars_instance_t *const mars_self, const mars_tx_channel_t channel, const mars_raw_phase_t raw_phase, const mars_fs_frequency_t raw_frequency)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    ret_val = mars_action_allow_api_call(mars_self, MARS_INIT_IDLE_OPERATIONAL, (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if(channel >= MARS_TX_CHANNEL_MAX)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        else if((raw_frequency < MARS_FS_FREQUENCY_MIN) || (raw_frequency > MARS_FS_FREQUENCY_MAX))
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_3);
        }
        else if(raw_phase > MARS_RAW_PHASE_MAX)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_2);
        }
        else
        {
            /* Calculate the VarH and VarL for PURE CW CFG MLBX command (data will be shifted in Mailbox Request where
             * parity is added) VAR_H : [12:12] 1-Start/0-Stop, [11:10] Chn index, [9:0] Phase LUT index VAR_L : [27:0] FS */
            const uint32 var_h = (uint16)(((uint32)1u << MARS_START_CW_START_BIT_INDEX) + (((uint32)channel & 0x03u) << MARS_START_CW_CHANNEL_BIT_INDEX) + ((uint32)raw_phase & 0x3FFu));
            const uint32 var_l = (raw_frequency & 0x00FFFFFFu);
            ret_val = mars_action_control_cw(mars_self, var_h, var_l);
        }
    }
    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_START_CW;
    }

    return ret_val;
}

/**
 * @brief         Writes Phase Look Up Table to Mars. The function writes the complete table (512 entries).
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    lut_values array of 14 bit LUT values (7 bit I x 7 bit Q)
 * @return        MARS_E_OK if successful MARS_API_ID_PHASE_LUT_WRITE_RAW errors if failed
 * @design        GID-269267 GID-347847 GID-347843
 */
Mars_ReturnType mars_phase_lut_write_raw( mars_instance_t *const mars_self, const uint16 lut_values[4][PHASE_LUT_NO_OF_ENTRIES])
{
    Mars_ReturnType ret_val = MARS_E_OK;

    ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INITIALIZED_FW_NOT_RUNNING | MARS_INIT_IDLE_OPERATIONAL),
                                  (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if (NULL_PTR == lut_values)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        else
        {
            uint8 index = 0;


            for(index = 0; index < MARS_PHASE_LUT_NO_OF_TX ; index++) 
            {

                ret_val = mars_write_reg_safe(mars_self, MARS_F_CORE_BANK_ENA_LUT_SEL, index);

                if(MARS_E_OK == ret_val)
                {
                    ret_val = mars_action_phase_lut_write_raw(mars_self, lut_values[index]);
                }

                if (MARS_E_OK != ret_val)
                {
                    break;
                } 
            }
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_PHASE_LUT_WRITE_RAW;
    }

    return ret_val;
}

/**
 * @brief         Read Phase Look Up Table from Mars. . The function reads the complete table (512 entries).
 *                The caller function shall ensure that sufficient memory is available for reading in 32bitsx512 = 2KBytes memory.
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   lut_values array of 14 bit LUT values (7 bit I x 7 bit Q)
 * @return        MARS_E_OK if successful MARS_API_ID_PHASE_LUT_READ_RAW errors if failed
 * @design        GID-269266 GID-347852 GID-347845
 */
Mars_ReturnType mars_phase_lut_read_raw( mars_instance_t *const mars_self, uint16 lut_values[4][PHASE_LUT_NO_OF_ENTRIES])
{
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INITIALIZED_FW_NOT_RUNNING | MARS_INIT_IDLE_OPERATIONAL),
                                                  (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if (NULL_PTR == lut_values)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        else
        {
            uint8 index = 0;


            for(index = 0; index < MARS_PHASE_LUT_NO_OF_TX ; index++)
            {

                ret_val = mars_write_reg_safe(mars_self, MARS_F_CORE_BANK_ENA_LUT_SEL, index);

                if(MARS_E_OK == ret_val)
                {
                    ret_val = mars_action_phase_lut_read_raw(mars_self, lut_values[index]);
                }
                if(MARS_E_OK != ret_val)
                {
                    break;
                }
            }
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_PHASE_LUT_READ_RAW;
    }

    return ret_val;
}

/**
 * @brief         Stops CW transmission
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    channel TX channel ID is the channel index in the range of 0..3
 *                where the command shall be applied to.
 * @return        MARS_E_OK if successful MARS_E_OK if failed
 * @design        GID-350836 GID-269253 GID-350839
 */
Mars_ReturnType mars_stop_cw(mars_instance_t *const mars_self, const mars_tx_channel_t channel)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_action_allow_api_call(mars_self, MARS_INIT_IDLE_OPERATIONAL, (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);
    if (MARS_E_OK == ret_val)
    {
        if(channel >= MARS_TX_CHANNEL_MAX)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        else
        {
            /* Calculate the VarH and VarL for PURE CW CFG MLBX command (data will be shifted in Mailbox Request where
             * parity is added) VAR_H : [12:12] 1-Start/0-Stop, [11:10] Chn index, [9:0] Phase LUT index VAR_L : [27:0] FS */
            const uint32 var_h = ((uint32)channel & 0x03u) << MARS_START_CW_CHANNEL_BIT_INDEX;
            const uint32 var_l = 0; /* a valid arbitrary value 79GHz */
            ret_val = mars_action_control_cw(mars_self, var_h, var_l);
        }

    }
    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_STOP_CW;
    }

    return ret_val;
}

/**
 * @brief         Activates Mars firmware
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    activation_type type of activation
 * @return        MARS_E_OK if successful MARS_API_ID_ACTIVATE_FIRMWARE errors if failed
 * @design        GID-350330 GID-269246 GID-350328
 */
Mars_ReturnType mars_activate_firmware(mars_instance_t *const mars_self, const mars_activation_t activation_type)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    ret_val = mars_action_allow_api_call(mars_self, MARS_INITIALIZED_FW_NOT_RUNNING, (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        /* Send the activation command to MAF */
        ret_val = mars_action_maf_activate(mars_self, activation_type);

        /* wait until MAF indicates successful start */
        /* Done by polling the MARS_F_CORE_BANK_MCU_RDR_READY flag */

        if (MARS_E_OK == ret_val)
        {
            ret_val = mars_action_maf_activation_check(mars_self);
        }

        if (MARS_E_OK == ret_val)
        {
           ret_val = mars_action_check_maf_version(mars_self);
        }    
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_ACTIVATE_FIRMWARE;
    }

    return ret_val;
}

/**
 * @brief         Loads firmware in Mars
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    firmware_data binary data of the mars application firmware
 * @param [in]    offset offset of the next data chunk (32-bit, byte offset from start of MAF)
 * @param [in]    length length of the binary data in bytes
 * @return        MARS_E_OK if successful MARS_API_ID_UPLOAD_FIRMWARE errors if failed
 * @design        GID-269245 GID-350333 GID-350335
 */
Mars_ReturnType mars_upload_firmware(mars_instance_t *const mars_self, const mars_firmware_data_t *const firmware_data, const uint32 offset, const mars_firmware_size_t length)
{
    mars_api_check_error_en param_index = MARS_L2_API_CHECK_NO_ERROR;
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, MARS_INITIALIZED_FW_NOT_RUNNING, (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        /* If offset is 0, reinitialize the buffers for a complete MAF upload */
        if (0u == offset)
        {
            MARS_DATA_BUFFER_MAF_START_ADDR = MARS_FIRMWARE_START_ADDR;
            MARS_DATA_BUFFER_MAF_SIZE = 0u;
        }

        /* Check parameters */
        ret_val = mars_action_check_upload_firmware_params_check(mars_self, offset, length, firmware_data, &param_index);
       
        if (MARS_E_OK == ret_val)
        {
            /* Fill the input buffers */
            MARS_DATA_BUFFER_MAF_SRC_ADDR = firmware_data;
            MARS_DATA_BUFFER_MAF_START_ADDR = (uint32)((uint32)MARS_FIRMWARE_START_ADDR + offset);
            MARS_DATA_BUFFER_MAF_SIZE = length;
            MARS_DATA_BUFFER_MAF_CRC = firmware_data[ MARS_BYTES_TO_WORDS(length) - 1UL];

            ret_val = mars_write_mem_safe(mars_self, MARS_DATA_BUFFER_MAF_SRC_ADDR, MARS_DATA_BUFFER_MAF_START_ADDR, MARS_BYTES_TO_WORDS(MARS_DATA_BUFFER_MAF_SIZE));

            /* Clear MAF Uploaded Flag - using Write Register API to ensure that Read-Back check is used */
            if (MARS_E_OK == ret_val)
            {
                ret_val = mars_write_reg_safe(mars_self, MARS_F_CORE_BANK_MCU_RDR_READY, 0u);
            }
        }
        else
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)param_index);
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_UPLOAD_FIRMWARE;
    }

    return ret_val;
}

/**
 * @brief         Initiates Frame transmission
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    timestamp millisecond time when Fram Tx is expected to be due
 * @param [in]    metadata_reg Value passed to Mars for transmit in MIPI metadata
 * @return        MARS_E_OK if successful MARS_API_ID_TRIGGER_FRAME errors if failed
 * @design        GID-269247  GID-350480 GID-350482
 */
Mars_ReturnType mars_trigger_frame(mars_instance_t *const mars_self, const mars_frame_timestamp_t timestamp, const mars_mipi_metadata_reg_t metadata_reg)
{
    const mars_trigger_frame_error_en frame_mars_busy = MARS_L2_FRAME_MARS_BUSY;
    const mars_trigger_frame_error_en frame_mars_block_by_sft = MARS_L2_FRAME_BLOCKED_BY_SFT;
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t) (MARS_INIT_IDLE_OPERATIONAL|MARS_BUSY), (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        /* MAF is not accepting frame trigger requests if it is in Safe State */
        /* We must prevent going ahead with frame trigger, because that would place the API in MARS_BUSY */
        /* and the READY would never come from MAF.  */
        if (MARS_SFT_ERR_ACTIVE == mars_action_sft_is_active(mars_self))
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_FRAME, (uint32)frame_mars_block_by_sft);
        }
    }

    /* Take measures if the API was in BUSY state for any reasons */
    if ((MARS_E_OK == ret_val) && (MARS_DATA_DRIVER_STATUS == MARS_BUSY))
    {
        ret_val= mars_action_check_maf_state(mars_self, MARS_RDY_TIMEOUT_US);
    }

    /* No SAFETY pin asserted, no BUSY state. */
    if (MARS_E_OK == ret_val)
    {
        mars_reg_value_t radar_ready = 0u;

        ret_val = mars_read_reg_safe(mars_self, MARS_F_CORE_BANK_MCU_RDR_READY, &radar_ready);

        if ((MARS_E_OK == ret_val) && (MARS_RADAR_READY_OK == radar_ready))
        {
            /* Trigger Frame - MM_FRAME_START */
            ret_val = mars_action_frame_start(mars_self, timestamp, metadata_reg);
            if(ret_val == MARS_E_OK)
            {
                /* Set driver status to busy */
                MARS_DATA_DRIVER_STATUS = MARS_BUSY;
            }
        }
        else
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_FRAME, (uint32)frame_mars_busy);
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_TRIGGER_FRAME;
    }

    return ret_val;
}

/**
 * @brief         Reads device unique ID information from the chip
 *                This information is available only after MAF has been successfully loaded and executed.
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   id Unique device ID information for detailed information check mars_uid_t
 * @return        MARS_E_OK if successful MARS_API_ID_READ_UID errors if failed
 * @design        GID-366196 GID-366200 GID-366198
 */
Mars_ReturnType mars_read_uid( mars_instance_t *const mars_self, mars_uid_t *const id)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    ret_val = mars_action_allow_api_call(mars_self, MARS_INIT_IDLE_OPERATIONAL, (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if (id == NULL_PTR)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        else
        {
            /* temporary storage of UID info building blocks */
            uint32 firmware_version = 0;

            const uint32 uid_register_addresses[]=
            {
                MARS_R_CPU_SYS_SYSNAME,
                MARS_R_CPU_SYS_SYSREV,
                MARS_F_OTPM_UI_OTP_LOT_ID,
                MARS_F_OTPM_UI_WAFER_NUMBER,
                MARS_F_OTPM_UI_X,
                MARS_F_OTPM_UI_Y
            };

            uint32 uid_temp_storage[sizeof(uid_register_addresses)/sizeof(uid_register_addresses[0])] = {0};

            /* SYSNAME register of Mars, 0x4D415253 = MARS in ASCII 
             * SYSREV register of Mars, Bits [15:8] - Major revision in ASCII (A, B, etc)  Bits [7:0] - Minor revision in ASCII (0, 1, etc)
             * LOT ID read from OTPM Mirror populated by MAF
             * Wafer number read from OTPM Mirror populated by MAF
             * Wafer X position read from OTPM Mirror populated by MAF
             * Wafer Y position read from OTPM Mirror populated by MAF
            */

            for(uint32 i = 0; i < (sizeof(uid_register_addresses)/sizeof(uid_register_addresses[0])); i++)
            {
                ret_val = mars_read_reg_safe(mars_self, uid_register_addresses[i], &uid_temp_storage[i]);
                if (MARS_E_OK != ret_val)
                {
                    break;
                }
            }        

            if (ret_val == MARS_E_OK)
            {
                id->si_name_version = (((mars_si_name_version_t)uid_temp_storage[MARS_UID_CPU_SYS_SYSNAME_REG_INDEX]) << MARS_32_BITS) | ((mars_si_name_version_t)uid_temp_storage[MARS_UID_CPU_SYS_SYSREV_REG_INDEX]);

                mars_unique_id_t uid = ((mars_unique_id_t)uid_temp_storage[MARS_UID_OTPM_UI_OTP_LOT_ID_REG_INDEX]) << MARS_32_BITS;

                uid |= (((mars_unique_id_t)uid_temp_storage[MARS_UID_OTPM_UI_OTP_WAFER_NUMBER_REG_INDEX]) & 0xffuL) << MARS_24_BITS;
                uid |= (((mars_unique_id_t)uid_temp_storage[MARS_UID_OTPM_UI_X_REG_INDEX]) & 0xffuL) << MARS_16_BITS;
                uid |= (((mars_unique_id_t)uid_temp_storage[MARS_UID_OTPM_UI_Y_REG_INDEX]) & 0xffuL) << MARS_8_BITS;
                id->uid = uid;

                /* Mars Firmware version information in Mars RAM, populated by MAF */
                ret_val = mars_action_read_maf_version(mars_self, &firmware_version);

                if (ret_val == MARS_E_OK)
                {
                    id->fw_version.maf_version = firmware_version;
                }
            }
        }
    }
    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_READ_UID;
    }

    return ret_val;
}

/**
 * @brief         Reads device status information from the chip
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   status device status information
 * @return        MARS_E_OK if successful MARS_E_OK if failed
 * @design        GID-350291 GID-269257 GID-350285
 */
Mars_ReturnType mars_read_status(mars_instance_t *const mars_self, mars_rdrstatus_t *const status)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    mars_mailbox_req_t mlbx_request = {0};
    mars_mailbox_resp_t mlbx_response = {0};

    ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INITIALIZED_FW_NOT_RUNNING | MARS_INIT_IDLE_OPERATIONAL),
                                  (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if (status == NULL_PTR)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        else
        {
            /* Calculate the VarH and VarL for RDR STS MLBX command
            * VAR_H : [15:0] 0u
            * VAR_L : [27:0] 0u */
            mlbx_request.slot = MARS_MLBX_SLOT_GEN_CMD;
            mlbx_request.command = MARS_MLBX_CMD_ML_RDR_STS;
            mlbx_request.var_h = 0u;
            mlbx_request.var_l = 0u;

            /* Send mailbox request and wait for the response */
            ret_val = mars_exchange_mlbx(mars_self, &mlbx_request, &mlbx_response, MARS_MLBX_TIMEOUT_US);

            mars_action_sts_set_mlbx_response(mars_self, (uint8)mlbx_response.response, (uint16)mlbx_response.var_h, (uint32)mlbx_response.var_l);

            if (MARS_E_OK == ret_val)
            {
                if (MARS_DATA_STS_ERROR <= MARS_L2_STS_RDR_DET_SFT_ERROR)
                {
                    ret_val = MARS_E_OK;
                }
                else
                {
                    mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_STS, (uint32)MARS_DATA_STS_ERROR);
                }
            }

            /* Get the MCU status */
            status->mcu_status = (uint32)((uint32)MARS_DATA_MCU_STATUS & 0x1FFFFFFuL);
            status->ctrl_status = MARS_DATA_CTRL_STATUS;

            /* Get the SFT error */
            status->sft_error = (uint16)MARS_DATA_SFT_ERROR;
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_READ_STATUS;
    }

    return ret_val;
}

/**
 * @brief         Reads status information from the driver
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   status driver status information
 * @return        MARS_E_OK if successful MARS_API_ID_READ_DRIVER_STATUS errors if failed
 * @design        GID-269258 GID-350300 GID-350296
 */
Mars_ReturnType mars_read_driver_status( mars_instance_t *const mars_self, mars_driver_status_t *const status)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    ret_val = mars_action_allow_api_call(mars_self, MARS_UNINTIALIZED, MARS_OPERATION_MODE_UNDEFINED, MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if (status == NULL_PTR)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        else
        {
            if( (uint32)MARS_DATA_DRIVER_STATUS == (uint32)MARS_BUSY)
            {
                Mars_ReturnType maf_state_ret_val = MARS_E_OK;
                /* we check the MAF state, where getting response from MAF or not equally carries
                 * positive information that are not considered error. All other Layer1 errors are reported upwards */
                maf_state_ret_val = mars_action_check_maf_state(mars_self, MARS_RDY_TIMEOUT_US);
                if ((maf_state_ret_val != MARS_E_OK) &&
                    ((maf_state_ret_val & MARS_L2_ERR_MASK) != (MARS_ERROR_L2_API_CHECK | (uint32)MARS_L2_API_CHECK_MAF_STATE_BUSY_ERROR)))
                {
                    ret_val = maf_state_ret_val;
                }
            }

            *status = (mars_driver_status_t)MARS_DATA_DRIVER_STATUS;
        }

    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_READ_DRIVER_STATUS;
    }

    return ret_val;
}

/**
 * @brief         Configures Mars chip stationary configuration
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    tx_config Configuration of TX parameters
 * @param [in]    rx_config configuration of RX parameters
 * @param [in]    rfdist_mode configuration of RF distribution mode (Single, Master, Slave)
 * @param [in]    bias_noise_filter configuration of Bias Noise Filter control
 * @param [in]    mipi_config configuration of MIPI
 * @param [in]    chrp_config configuration of chirp and frame parameters
 * @param [in]    chrp_mode chirp mode configuration
 * @param [in]    gp_config configuration of GP0 & GP1 pin
 * @param [in]    frame_counter initial frame counter value, incremented by Mars automatically
 * @param [in]    mipi_diag array of up to 16 Mars register addresses, their content will be returned in MIPI metadata
 * @param [in]    maf_fusa_fs Fstart used in MAF FUSA functions
 * @return        MARS_E_OK if successful MARS_API_ID_CONFIGURE errors if fails
 * @design        GID-350493 GID-350495 GID-269254
 */
Mars_ReturnType mars_configure(mars_instance_t *const mars_self, const mars_tx_config_t *const tx_config, const mars_rx_config_t *const rx_config, const mars_rfdist_mode_t *const rfdist_mode, /* polyspace GUIDELINE:SC07 [No action planned:Medium] "The API takes all the parameters needed for configuration for MARS to validate them" */
                               const mars_bias_noise_filter_t *const bias_noise_filter, const mars_mipi_config_t *const mipi_config, const mars_chirp_config_t *const chrp_config,
                               const mars_chirp_mode_t *const chrp_mode, const mars_gp_config_t *const gp_config, const mars_frame_counter_t *const frame_counter,
                               const mars_mipi_diag_t *const mipi_diag, const mars_fusa_fs_t *const maf_fusa_fs)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    mars_scratchpad_cfg_t mars_scp_cfg = {0};

    ret_val = mars_action_allow_api_call(mars_self, MARS_INIT_IDLE_OPERATIONAL, (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_FW_VERSION_MIN_COMPATIBLE, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        ret_val = mars_action_mars_configure_param_check(mars_self, tx_config, rx_config, rfdist_mode, bias_noise_filter, mipi_config, chrp_config, chrp_mode, gp_config, mipi_diag);

        if (MARS_E_OK == ret_val)
        {
            mars_action_configure_scp(&mars_scp_cfg, tx_config, rx_config, rfdist_mode, bias_noise_filter, mipi_config, chrp_config, chrp_mode, mipi_diag, maf_fusa_fs);

            if (NULL_PTR != gp_config)
            { 
                ret_val = mars_action_configure_gp_registers(mars_self, gp_config);     
            }

            if ((MARS_E_OK == ret_val) && (NULL_PTR != frame_counter))
            {
                uint32 frame_counter_mars = mars_calculate_frm_cnt_parity(*frame_counter);
                frame_counter_mars |= (uint32)(*frame_counter);

                ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_R_CPU_SYS_FRM_CNTR, frame_counter_mars);
            }
        }

        if (MARS_E_OK == ret_val)
        {
            ret_val = mars_action_scp_send_update_command(mars_self, &mars_scp_cfg);
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_CONFIGURE;
    }

    return ret_val;
}

/**
 * @brief         Reads back Mars chip stationary configuration
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   tx_config Configuration of TX parameters
 * @param [out]   rx_config configuration of RX parameters
 * @param [out]   rfdist_mode configuration of RF distribution mode (Single, Master, Slave)
 * @param [out]    bias_noise_filter configuration of Bias Noise Filter control
 * @param [out]   mipi_config configuration of MIPI
 * @param [out]   chrp_config configuration of chirp and frame parameters
 * @param [out]   chrp_mode chirp mode configuration
 * @param [out]   gp_config configuration of GP0 & GP1 pins
 * @param [out]   frame_counter initial frame counter value, incremented by Mars automatically
 * @param [out]   mipi_diag array of up to 16 Mars register addresses, their content will be returned in MIPI metadata
 * @param [out]   maf_fusa_fs Fstart used in MAF FUSA functions
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 * @design        GID-449720 GID-449718 GID-449719
 */

Mars_ReturnType mars_configure_read( mars_instance_t *const mars_self, mars_tx_config_t *const tx_config, mars_rx_config_t *const rx_config, mars_rfdist_mode_t *const rfdist_mode, /* polyspace GUIDELINE:SC07 [No action planned:Medium] "The API takes all the parameters needed for MARS configuration" */
                               mars_bias_noise_filter_t *const bias_noise_filter, mars_mipi_config_t *const mipi_config, mars_chirp_config_t *const chrp_config,
                               mars_chirp_mode_t *const chrp_mode, mars_gp_config_t *const gp_config, mars_frame_counter_t *const frame_counter,
                               mars_mipi_diag_t *const mipi_diag, mars_fusa_fs_t *const maf_fusa_fs)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    mars_scratchpad_cfg_t mars_scp_cfg = {0};
    ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INIT_IDLE_OPERATIONAL), (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_FW_VERSION_MIN_COMPATIBLE, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        ret_val = mars_action_config_read_param_check(mars_self, tx_config, rx_config, rfdist_mode, bias_noise_filter, mipi_config, chrp_config, chrp_mode, gp_config, frame_counter, mipi_diag, maf_fusa_fs);

        if (MARS_E_OK == ret_val)
        { 
            ret_val = mars_action_scp_read_back(mars_self, MARS_MLBX_SUBCMD_RD_BACK_CONFIG, &(mars_scp_cfg.valid_1), MARS_BYTES_TO_WORDS(MARS_SCRATCHPAD_SIZE));
        }
        if (ret_val == MARS_E_OK)
        {
            /* Parse the scratchpad data and fill in the output parameters */
            ret_val = mars_action_config_read_parse_scp_data(mars_self, &mars_scp_cfg, tx_config, rx_config, rfdist_mode, bias_noise_filter, mipi_config, chrp_config, chrp_mode, mipi_diag, maf_fusa_fs);
        }

        if(MARS_E_OK == ret_val)
        {
            /* Read configuration registers */
            ret_val = mars_action_config_read_gp_registers(mars_self, gp_config);
        }

        if (MARS_E_OK == ret_val)
        {
            uint32 register_val = 0;
            /* Read frame counter value */
            ret_val = mars_read_reg_safe(mars_self, MARS_R_CPU_SYS_FRM_CNTR,  &register_val);
            if (MARS_E_OK == ret_val)
            {
                *frame_counter = (uint16) (register_val & 0xFFFFu); /* polyspace RTE:IDP [Not a defect:Medium] "The pointer is checked for NULL before dereferencing in mars_action_config_read_param_check" */
            }
        }
        
    }
    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_CONFIGURE_READ;
    }
    return ret_val;
}

/**
* @brief         Resets the Mars chip or recovers the API driver state.
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    reset     type of reset; one of MARS_RESET_HARD, MARS_RESET_SOFT,
 *                          MARS_RESET_FORCE_LOW, or MARS_RESET_STATUS (see mars_reset_t)
 * @return        MARS_E_OK if successful, E_NOT_OK if failed.
 *                Returns error 0x0908000c (MARS_API_ID_RESET | MARS_ERROR_L2_API_CHECK |
 *                MARS_L2_API_CHECK_DRIVER_STATUS_ERROR) if the driver has not been initialized.
 * @design        GID-348464 GID-348512 GID-269255
 */
Mars_ReturnType mars_reset(mars_instance_t *const mars_self, const mars_reset_t reset)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INITIALIZED_FW_NOT_RUNNING | MARS_INIT_IDLE_OPERATIONAL | MARS_DRIVER_ERROR | MARS_BUSY), MARS_OPERATION_MODE_UNDEFINED, MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (((ret_val & (MARS_ERROR_L2_BIT_MASK << MARS_ERROR_L2_BIT_OFFSET)) == MARS_ERROR_L2_API_CHECK) &&
        ((ret_val & MARS_ERROR_ID_BIT_MASK) == (Mars_ReturnType)MARS_L2_API_CHECK_DRIVER_STATUS_ERROR))
    {
        /* we perform a low level init if the API was not initialized yet, so the reset can be executed */
        mars_action_init(mars_self);
        ret_val = mars_layer1_init(mars_self);
    }
    if (MARS_E_OK == ret_val)
    {
        switch (reset)
        {
            case MARS_RESET_SOFT:
                /* 6.8.3 PMU Power Management unit
                 * Send the PMU to SWRST state
                 * Software Reset is active HIGH (1) */
                ret_val = mars_write_reg_raw(mars_self, (uint32)MARS_F_CORE_BANK_RST_SYS_PMU, (uint32)0x01U, MARS_L1_SAFE_NO_CHK);
                break;
            case MARS_RESET_HARD:
                /* Set the PMU to Idle State - GPIO Reset is active LOW */
                ret_val = mars_gpio_reset_write(mars_self, L0_IO_LO);
                /* Wait for Reset */
                if(MARS_E_OK == ret_val)
                {
                ret_val = mars_wait_ms(mars_self, 1);
                }
                /* Release the PMU from Idle State, next state is FUNC (debug mode) or BIST (normal mode) - GPIO Reset is
                 * not-active/idle HIGH */
                if(MARS_E_OK == ret_val)
                {
                    ret_val = mars_gpio_reset_write(mars_self, L0_IO_HI);
                }
                break;
            case MARS_RESET_FORCE_LOW:
                /* Set the PMU to Idle State - GPIO Reset is active LOW */
                ret_val = mars_gpio_reset_write(mars_self, L0_IO_LO);
                break;
            case MARS_RESET_STATUS:
                /* Set the Status to idle */
                MARS_DATA_DRIVER_STATUS = MARS_INIT_IDLE_OPERATIONAL;
                break;
            default: /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the input parameter not with valid value" */
                mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
                break;
        }
        if (MARS_E_OK == ret_val)
        {
            /* Reset the driver status if it is not the status reset */
            if (reset != MARS_RESET_STATUS)
            {
               MARS_DATA_DRIVER_STATUS = MARS_UNINTIALIZED;
            }
        }
        else
        {
            /* Reset failed */  
            MARS_DATA_DRIVER_STATUS = MARS_DRIVER_ERROR;
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_RESET;
    }

    return ret_val;
}

/**
 * @brief         Reads Profiler Table 0 from the chip
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    offset start index of the table read in bytes [0..33776]
 * @param [in]    size number of the table entries to be read. One increment is 16 bytes
 * @param [out]   table table data that is read back from the device
 * @return        MARS_E_OK if successful MARS_API_ID_PROFILER_TABLE_0_READ_RAW errors if failed
 * @design        GID-269261 GID-347824 GID-347833
 */
Mars_ReturnType mars_profiler_table_0_read_raw( mars_instance_t *const mars_self, const uint16 offset, const uint16 size, mars_pt0_t *const table)
{
    mars_api_check_error_en param_index = MARS_L2_API_CHECK_NO_ERROR;
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INITIALIZED_FW_NOT_RUNNING | MARS_INIT_IDLE_OPERATIONAL),
                                  (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        ret_val = mars_api_parameter_check(offset, &param_index, MARS_PROFILER_T0_ELEMENT_SIZE_BYTES, size, table);
        if (MARS_E_OK == ret_val)
        {
            ret_val = mars_read_mem_safe(mars_self, (MARS_PROFILE_TABLE_START_ADDR + offset), table->raw, MARS_BYTES_TO_WORDS((size * (uint32)MARS_PROFILER_T0_ELEMENT_SIZE_BYTES)));
        }
        else
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)param_index);
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_PROFILER_TABLE_0_READ_RAW;
    }

    return ret_val;
}

/**
 * @brief         Writes Profiler Table 0 in the chip
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    offset start index of the table write in bytes [0..33776]
 * @param [in]    size number of the table entries to be written. One increment is 16 bytes
 * @param [in]    table table data that is written to the device
 * @return        MARS_E_OK if successful MARS_API_ID_PROFILER_TABLE_0_WRITE_RAW errors if failed
 * @design        GID-269262 GID-347827 GID-347835
 */
Mars_ReturnType mars_profiler_table_0_write_raw( mars_instance_t *const mars_self, const uint16 offset, const uint16 size, const mars_pt0_t *const table)
{
    mars_api_check_error_en param_index = MARS_L2_API_CHECK_NO_ERROR;
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INITIALIZED_FW_NOT_RUNNING | MARS_INIT_IDLE_OPERATIONAL),
                                  (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        ret_val = mars_api_parameter_check(offset, &param_index, MARS_PROFILER_T0_ELEMENT_SIZE_BYTES, size, table);
        if (MARS_E_OK == ret_val)
        {
            ret_val = mars_l1_write_mem_raw(mars_self, table->raw, (uint32)(MARS_PROFILE_TABLE_START_ADDR + offset), MARS_BYTES_TO_WORDS(((uint32)(size * MARS_PROFILER_T0_ELEMENT_SIZE_BYTES))),MARS_L1_SAFE_CHK_MLBX);
        }
        else
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)param_index);
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_PROFILER_TABLE_0_WRITE_RAW;
    }

    return ret_val;
}

/**
 * @brief         Reads Profiler Table 1 from the chip
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    offset start index of the table read in bytes [0..33784]
 * @param [in]    size number of the table entries to be read. One increment is 8 bytes
 * @param [out]   table table data that is read back from the device
 * @return        MARS_E_OK if successful MARS_API_ID_PROFILER_TABLE_1_READ_RAW errors if failed
 * @design        GID-347837 GID-269263 GID-347829
 */
Mars_ReturnType mars_profiler_table_1_read_raw( mars_instance_t *const mars_self, const uint16 offset, const uint16 size, mars_pt1_t *const table)
{
    mars_api_check_error_en param_index = MARS_L2_API_CHECK_NO_ERROR;
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INITIALIZED_FW_NOT_RUNNING | MARS_INIT_IDLE_OPERATIONAL),
                                  (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        ret_val = mars_api_parameter_check(offset, &param_index, MARS_PROFILER_T1_ELEMENT_SIZE_BYTES, size,  table);
        if (MARS_E_OK == ret_val)
        {
            ret_val = mars_read_mem_safe(mars_self, (uint32)(MARS_PROFILE_TABLE_START_ADDR + offset), table->raw, MARS_BYTES_TO_WORDS(((uint32)(size * MARS_PROFILER_T1_ELEMENT_SIZE_BYTES))));
        }
        else
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)param_index);
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_PROFILER_TABLE_1_READ_RAW;
    }

    return ret_val;
}

/**
 * @brief         Writes Profiler Table 1 in the chip
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    offset start index of the table write in bytes [0..33784]
 * @param [in]    size number of the table entries to be written. One increment is 8 bytes
 * @param [in]    table table data that is written to the device
 * @return        MARS_E_OK if successful MARS_API_ID_PROFILER_TABLE_1_WRITE_RAW errors if failed
 * @design        GID-269264 GID-347831 GID-347839
 */
Mars_ReturnType mars_profiler_table_1_write_raw( mars_instance_t *const mars_self, const uint16 offset, const uint16 size, const mars_pt1_t *const table)
{
    mars_api_check_error_en param_index = MARS_L2_API_CHECK_NO_ERROR;
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INITIALIZED_FW_NOT_RUNNING | MARS_INIT_IDLE_OPERATIONAL),
                                  (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        ret_val = mars_api_parameter_check(offset, &param_index, MARS_PROFILER_T1_ELEMENT_SIZE_BYTES, size, table);
        if (MARS_E_OK == ret_val)
        {
            ret_val = mars_l1_write_mem_raw(mars_self, table->raw, (uint32)(MARS_PROFILE_TABLE_START_ADDR + offset), MARS_BYTES_TO_WORDS(((uint32)(size * MARS_PROFILER_T1_ELEMENT_SIZE_BYTES))),MARS_L1_SAFE_CHK_MLBX);
        }
        else
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)param_index);
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_PROFILER_TABLE_1_WRITE_RAW;
    }

    return ret_val;
}

/**
 * @brief         Reads complete register or bitfield from the Mars chip memory map
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    reg_id register and bit field ID
 * @param [out]   value register or bitfield value
 * @return        MARS_E_OK if successful MARS_E_OK MARS_API_ID_READ_REGISTER errors if failed
 * @design        GID-269243 GID-324485 GID-347790
 */
Mars_ReturnType mars_read_register( mars_instance_t *const mars_self, const mars_reg_id_t reg_id, mars_reg_value_t *const value)
{
    uint32 register_val_buffer = 0;

    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INITIALIZED_FW_NOT_RUNNING | MARS_INIT_IDLE_OPERATIONAL),
                                                  (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if (value == NULL_PTR)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_2);
        }
        else
        {
            ret_val = mars_read_reg_safe(mars_self, (uint32)reg_id, &register_val_buffer);

            if (MARS_E_OK == ret_val)
            {
                *value = register_val_buffer;
            }
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_READ_REGISTER;
    }

    return ret_val;
}

/**
 * @brief         Writes complete register or bitfield in the Mars chip memory map
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    reg_id register and bit field ID
 * @param [in]    value register or bitfield value
 * @return        MARS_E_OK if successful MARS_API_ID_WRITE_REGISTER errors if failed
 * @design        GID-347788 GID-269244 GID-324488
 */
Mars_ReturnType mars_write_register( mars_instance_t *const mars_self, const mars_reg_id_t reg_id, const mars_reg_value_t value)
{

    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INITIALIZED_FW_NOT_RUNNING | MARS_INIT_IDLE_OPERATIONAL),
                                                  (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        ret_val = mars_write_reg_safe(mars_self, (uint32)reg_id, (uint32)value);
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_WRITE_REGISTER;
    }

    return ret_val;
}


/**
 * @brief         Reads the content of a Mars memory location
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    address Memory address in Mars
 * @param [out]   value resulting data read from Mars memory
 * @param [in]    size number of 32-bit words to be read
 * @return        MARS_E_OK if successful MARS_E_OK MARS_API_ID_READ_MEMORY errors if failed
 * @design        GID-420818 GID-421454 GID-421518
 */
Mars_ReturnType mars_read_memory( mars_instance_t *const mars_self, mars_address_t const address, mars_value_t *const value, const mars_size_t size)
{
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INITIALIZED_FW_NOT_RUNNING | MARS_INIT_IDLE_OPERATIONAL),
                                                  (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if (value == NULL_PTR)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_2);
        }
        else if((size == 0u) || (size > MARS_BYTES_TO_WORDS(MARS_MAX_MEMORY_SECTION_SIZE)))
        { 
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_3);
        }
        else if( address > MARS_MEMORY_END_ADDR)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        else
        {
            if(mars_action_check_memory_range(address, size) != MARS_E_OK)
            {
                mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
            }
            else
            {
                ret_val = mars_read_mem_safe(mars_self, address, value, size);
            }   
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_READ_MEMORY;
    }

    return ret_val;
}

/**
 * @brief         Writes data directly into Mars memory
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    address Memory address in Mars
 * @param [in]    value data to be written to Mars memory
 * @param [in]    size number of 32-bit words to be written
 * @return        MARS_E_OK if successful MARS_API_ID_WRITE_MEMORY errors if failed
 * @design        GID-420820 GID-421455 GID-421519
 */
Mars_ReturnType mars_write_memory( mars_instance_t *const mars_self, mars_address_t const address, const mars_value_t * const  value, const mars_size_t size)
{

    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INITIALIZED_FW_NOT_RUNNING | MARS_INIT_IDLE_OPERATIONAL),
                                                  (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if( value == NULL_PTR)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_2);
        }
        else if((size == 0u) || (size > MARS_BYTES_TO_WORDS(MARS_MAX_MEMORY_SECTION_SIZE)))
        { 
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_3);
        }
        else if( address > MARS_MEMORY_END_ADDR)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        else
        {
            if((mars_l1_check_blacklisted_in_range_address(address, size) != MARS_E_OK) || (mars_action_check_memory_range(address, size) != MARS_E_OK) )
            {
                mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
            }
            else
            {
                ret_val = mars_write_mem_safe(mars_self, value, address, size);
                
            }
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_WRITE_MEMORY;
    }

    return ret_val;
}

/**
 * @brief         Enables Test Pattern generation in the device
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    channel ADC channel
 * @param [in]    tp_config Test Pattern config
 * @param [in]    clr_mode Test Pattern Clear Mode
 * @return        MARS_E_OK if successful MARS_API_ID_ENABLE_TESTPATTERN errors if failed
 * @design        GID-350939 GID-350941 GID-269268
 */
Mars_ReturnType mars_enable_testpattern( mars_instance_t *const mars_self, const mars_tp_adc_channel_t channel, const mars_tp_config_t *const tp_config, const mars_tp_clr_mode_t clr_mode)
{
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, MARS_INIT_IDLE_OPERATIONAL, (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if ((uint32)channel > (uint32)MARS_ADC_CH4)
        { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the input parameter not with valid value" */
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }

        if(tp_config == NULL_PTR)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_2);
        }

        if ((uint32)clr_mode > (uint32) MARS_TESTPATTERN_CLR_SAMPLE_START)
        { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the input parameter not with valid value" */
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_3);
        }

        if (MARS_E_OK == ret_val)
        {
            /* Enable Test Pattern */
            ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_ASYNC_BANK_ASYNC_DATA_SELECT, (uint32)0x02U);

            /* Async test pattern channel 0 */
            if (MARS_E_OK == ret_val)
            {
                const uint32 mars_tp_config[][MARS_TP_CONFIG_NUMBER_OF_COLUMNS] = {
                    {MARS_TP_REGS[channel].tp_enable, (uint32)0x01U},
                    {MARS_TP_REGS[channel].tp_waveform_sel, (uint32)(tp_config->waveform)},
                    {MARS_TP_REGS[channel].tp_offset, ((uint32)tp_config->offset & 0xFFFFU)},
                    {MARS_TP_REGS[channel].tp_step, ((uint32)tp_config->step & 0x3FFU)},
                    {MARS_TP_REGS[channel].tp_ctl_poly_sel, (uint32)(tp_config->polynomial)},
                    {MARS_TP_REGS[channel].tp_ctl_par_sel, (uint32)(tp_config->parallelism)},
                    {MARS_TP_REGS[channel].tp_thr, ((uint32)tp_config->threshold & 0x7FFU)},
                    {MARS_TP_REGS[channel].tp_shift1_value, ((uint32)tp_config->shift1 & 0x1FU)},
                    {MARS_TP_REGS[channel].tp_shift2_value, ((uint32)tp_config->shift2 & 0x1FU)}
                    };
                for(uint32 idx = 0; idx < (sizeof(mars_tp_config) / sizeof(mars_tp_config[0])); idx++ )
                {
                    ret_val = mars_write_reg_safe(mars_self, mars_tp_config[idx][0], mars_tp_config[idx][1]);
                    if (MARS_E_OK != ret_val)
                    {
                        break;
                    }
                }
                if(MARS_E_OK == ret_val)
                {
                    /* Write Test Pattern Clear Mode */
                    ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_ASYNC_BANK_ASYNC_TP_CLR_MODE, (uint32)clr_mode);
                }
            }

        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_ENABLE_TESTPATTERN;
    }

    return ret_val;
}

/**
 * @brief         Disables Test Pattern generation in the device
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    channel ADC channel
 * @return        MARS_E_OK if successful MARS_API_ID_DISABLE_TESTPATTERN errors if failed
 * @design        GID-350943 GID-269269 GID-350948
 */
Mars_ReturnType mars_disable_testpattern( mars_instance_t *const mars_self, const mars_tp_adc_channel_t channel)
{

    uint32 register_val_buffer = 0;

    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, MARS_INIT_IDLE_OPERATIONAL, (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if ((uint32)channel > (uint32)MARS_ADC_CH4)
        { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the input parameter not with valid value" */
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }

        if (MARS_E_OK == ret_val) /* polyspace RTE:UNR [Not a defect:Low] "Not always true check if the input parameter is not valid" */
        {
            /* Disable Async test pattern channel */
            ret_val = mars_write_reg_safe(mars_self, MARS_TP_REGS[channel].tp_enable, (uint32)0x00U);

            if (MARS_E_OK == ret_val)
            {
                uint8 async_tp_chn_status = 0;

                for (uint32 channel_idx = 0; channel_idx < MARS_TESTPATTERN_CHANNEL_SIZE; channel_idx++)
                {
                    ret_val = mars_read_reg_safe(mars_self, MARS_TP_REGS[channel_idx].tp_enable, &register_val_buffer);
                    if (ret_val != MARS_E_OK)
                    {
                        break;
                    }
                    
                    async_tp_chn_status |= (uint8)((register_val_buffer & 0x01u) << channel_idx);
                }

                if ((0 == async_tp_chn_status) && (MARS_E_OK == ret_val))
                {
                    /* Disable Test Pattern MUX selection */
                    ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_ASYNC_BANK_ASYNC_DATA_SELECT, (uint32)0x01U);
                }
            }
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_DISABLE_TESTPATTERN;
    }

    return ret_val;
}

/**
 * @brief         Switches between SPI and QSPI mode
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    config QSPI configuration
 * @return        MARS_E_OK if successful MARS_API_ID_QSPI_CONFIG errors if failed
  * @design       GID-269259 GID-350303 GID-350312
 */
Mars_ReturnType mars_qspi_config(mars_instance_t *const mars_self, const mars_ssi_config_t *const config)
{
    mars_mailbox_req_t mlbx_request = {0};
    mars_mailbox_resp_t mlbx_response = {0};

    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INITIALIZED_FW_NOT_RUNNING | MARS_INIT_IDLE_OPERATIONAL),
                                                  (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if ((config == NULL_PTR) || ((*config != MARS_SSI_SPI) && (*config != MARS_SSI_QSPI)))
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        else
        {
            /* Save the previous SSI Mode */
            const mars_ssi_config_t ssi_mode_prev = (MARS_SSI_SPI == *config) ? MARS_SSI_QSPI : MARS_SSI_SPI;

            mlbx_request.slot = MARS_MLBX_SLOT_GEN_CMD;
            mlbx_request.command = MARS_MLBX_CMD_ML_CFG_SSI;
            mlbx_request.var_h = (uint16)*config;
            mlbx_request.var_l = 0u;

            /* Send mailbox request */
            ret_val = mars_write_mlbx(mars_self, &mlbx_request, MARS_MLBX_TIMEOUT_US);

            if (MARS_E_OK == ret_val)
            {
                /* Switch the SSI mode, mlbx_varH contains the SSI mode */
                ret_val = mars_action_ssi_set_mode(mars_self, *config);

                /* Read mailbox response */
                mlbx_response.slot = MARS_MLBX_SLOT_GEN_CMD;
                ret_val = mars_read_mlbx(mars_self, &mlbx_response, MARS_MLBX_TIMEOUT_US);

                mars_action_ssi_set_mlbx_response(mars_self, (uint8)mlbx_response.response, (uint16)mlbx_response.var_h, (uint32)mlbx_response.var_l);
            }

            if (MARS_E_OK == ret_val)
            {
                if (MARS_L2_SSI_NO_ERROR == MARS_DATA_SSI_ERROR)
                {
                    ret_val = MARS_E_OK;
                }
                else
                {
                    /* SSI Mode Switch failed, revert the SSI mode */
                    (void)mars_action_ssi_set_mode(mars_self, ssi_mode_prev);

                    mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SSI, (uint32)MARS_DATA_SSI_ERROR);
                }
            }
            else
            {
                /* SSI Mode Switch failed, revert the SSI mode */
                ret_val |= mars_action_ssi_set_mode(mars_self, ssi_mode_prev);
            }
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_QSPI_CONFIG;
    }

    return ret_val;
}

/**
 * @brief         Provides the version of the host API driver
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   version version information
 * @return       MARS_E_OK if successful MARS_E_OK if failed
 * @design       GID-409958 GID-409969 GID-409959
 */
Mars_ReturnType mars_get_api_version(const mars_instance_t *const mars_self, mars_api_sw_version_t *const version)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    if (NULL_PTR == mars_self)
    {
        mars_set_l2_error_information(&ret_val, MARS_NO_DATA, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_INVALID_INSTANCE_ERROR);
    }
    else if (NULL_PTR == version)
    {
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
    }
    else
    {
        (void)mars_self;

        version->major = (uint8)MARS_API_VERSION_MAJOR;
        version->minor = (uint8)MARS_API_VERSION_MINOR;
        version->patch = (uint8)MARS_API_VERSION_PATCH;
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_GET_API_VERSION;
    }

    return ret_val;
}

/**
 * @brief         Write the calibration control settings to Mars
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    control bit field that contains the the enable/disable information of Mars calibration features
 * @return        MARS_E_OK if successful MARS_API_ID_CAL_CTRL_WRITE errors if failed
 * @design        GID-289748 GID-290285 GID-350983
 */
Mars_ReturnType mars_cal_ctrl_write( mars_instance_t *const mars_self, const mars_cal_control_t *const control)
{
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INIT_IDLE_OPERATIONAL), (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_FW_VERSION_MIN_COMPATIBLE, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if (NULL_PTR == control)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }

        if( MARS_E_OK == ret_val)
        { 
            ret_val = mars_write_mem_safe(mars_self, (const uint32 *)*control, MARS_SCRATCHPAD_CFG_START_ADDRESS, MARS_SCP_CAL_SIZE_WORDS);
        }
        
        if (MARS_E_OK == ret_val)
        {
            uint32 scp_crc = 0;
            ret_val = mars_calculate_crc(mars_self, (const uint32*) *control, MARS_SCP_CAL_SIZE_WORDS * sizeof(uint32), &scp_crc);
            if (MARS_E_OK == ret_val)
            {
                mars_mailbox_req_t mlbx_request = {0};
                mars_mailbox_resp_t mlbx_response = {0};
                mlbx_request.slot = MARS_MLBX_SLOT_GEN_CMD;
                mlbx_request.command = MARS_MLBX_CMD_ML_RDR_SCP;
                mlbx_request.var_h = (uint32)((uint16)MARS_MLBX_SUBCMD_SCP_CAL << MARS_CAL_CTRL_WRITE_CMD_BIT_INDEX) | ((uint16)MARS_SCP_CAL_SIZE_WORDS << MARS_CAL_CTRL_WRITE_SIZE_BIT_INDEX) | (uint16)(scp_crc >> MARS_CAL_CTRL_WRITE_CRC_BIT_INDEX);
                mlbx_request.var_l = (scp_crc & 0x0FFFFFFFuL);
                /* Send mailbox request and wait for the response */
                ret_val = mars_exchange_mlbx(mars_self, &mlbx_request, &mlbx_response, MARS_MLBX_TIMEOUT_US);
                if (MARS_E_OK == ret_val)
                {
                    ret_val = mars_action_scp_cal_set_mlbx_response((const mars_instance_t *)mars_self, (uint8)mlbx_response.response, (uint16)mlbx_response.var_h, (uint32)mlbx_response.var_l);
                }
            }
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_CAL_CTRL_WRITE;
    }

    return ret_val;
}

/**
 * @brief         Reads back the calibration control information from Mars
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   control array of 32 bit values used as bit fields to enable/disable individual calibration features
 * @return        MARS_E_OK if successful MARS_API_ID_CAL_CTRL_READ errors if failed
 * @design        GID-449360 GID-449362 GID-449364
 */
Mars_ReturnType mars_cal_ctrl_read( mars_instance_t *const mars_self, mars_cal_control_t *const control)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INIT_IDLE_OPERATIONAL), (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_FW_VERSION_MIN_COMPATIBLE, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if (NULL_PTR == control)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }

        if (MARS_E_OK == ret_val)
        {
            ret_val = mars_action_scp_read_back(mars_self, MARS_MLBX_SUBCMD_RD_BACK_CAL,( uint32 *const) *control, MARS_SCP_CAL_SIZE_WORDS);
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_CAL_CTRL_READ;
    }

    return ret_val;
}

/**
 * @brief         Requests Mars to update all diagnostic values. This includes both the temperature-type signed values and the voltage-type unsigned diagnostic ADC values.
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful MARS_API_ID_UPDATE_DIAG_VALUES errors if failed
 * @design        GID-319512 GID-319505 GID-329312
 */
Mars_ReturnType mars_update_diagnostic_values( mars_instance_t *const mars_self)
{
    mars_mailbox_req_t mlbx_request = {0};
    mars_mailbox_resp_t mlbx_response = {0};

    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, MARS_INIT_IDLE_OPERATIONAL, (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        /* Calculate the VarH and VarL for RDR STS MLBX command
         * VAR_H : [15:0] 0u
         * VAR_L : [27:0] 0u */
        mlbx_request.slot = MARS_MLBX_SLOT_GEN_CMD;
        mlbx_request.command = MARS_MLBX_CMD_ML_UPD_DIAG;
        mlbx_request.var_h = 0u;
        mlbx_request.var_l = 0u;

        /* Send mailbox request and wait for the response */
        ret_val = mars_exchange_mlbx(mars_self, &mlbx_request, &mlbx_response, MARS_MLBX_TIMEOUT_US);

        if (MARS_E_OK == ret_val)
        {
            ret_val = mars_action_update_diag_set_mlbx_response((const mars_instance_t *)mars_self, (uint8)mlbx_response.response, (uint16)mlbx_response.var_h, (uint32)mlbx_response.var_l);
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_UPDATE_DIAG_VALUES;
    }

    return ret_val;
}

/**
 * @brief         Reads one or more diag entries of the Mars chip, and returns the value after integrity check.
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    start_idx index number of the first diag entry to be read
 * @param [in]    num_values number of diag entries to be read
 * @param [out]   diag_values array of mars_diag_t values, size of the array is greater or equal to num_values
 * @return        MARS_E_OK if successful, MARS_API_ID_READ_DIAG_RAW errors if failure
 * @design        GID-366239 GID-367503 GID-367505
 */
Mars_ReturnType mars_read_diag_raw(mars_instance_t *const mars_self, const uint32 start_idx, const uint32 num_values, mars_diag_t *const diag_values)
{
    const mars_read_diag_raw_error_en read_diag_raw_size_error = MARS_L2_READ_DIAG_RAW_SIZE_ERROR;
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, MARS_INIT_IDLE_OPERATIONAL, (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_FW_VERSION_MIN_COMPATIBLE, MARS_ALLOW_ALL_FW_VERSIONS);

    if (MARS_E_OK == ret_val)
    {
        if( (num_values == 0u ) || (num_values > MARS_DIAG_VALUES_MAX_NUMBER) )
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_2);
        }
        else if (start_idx >= MARS_DIAG_VALUES_MAX_NUMBER)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        else if ((start_idx + num_values) > MARS_DIAG_VALUES_MAX_NUMBER)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_READ_DIAG_RAW, (uint32)read_diag_raw_size_error);
        }
        else if (NULL_PTR == diag_values)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_3);
        }
        else
        {
            uint32 diag_idx = 0;

            while ((diag_idx < num_values) && (MARS_E_OK == ret_val))
            {
                const uint32 remaining = num_values - diag_idx;
                const uint32 chunk_count = (remaining < MARS_DIAG_READ_CHUNK_SIZE) ? remaining : MARS_DIAG_READ_CHUNK_SIZE;
                const uint32 mem_addr = MARS_DIAG_VALUES_START_ADDR + ((start_idx + diag_idx) * sizeof(uint32));
                mars_diag_health_state_t sample_states[MARS_DIAG_READ_CHUNK_SIZE] = {0};
                uint32 sample_raws[MARS_DIAG_READ_CHUNK_SIZE] = {0};
                uint8 sample_counters[MARS_DIAG_READ_CHUNK_SIZE] = {0};
                uint32 chunk_iterator;

                for (chunk_iterator = 0u; chunk_iterator < chunk_count; chunk_iterator++)
                {
                    sample_counters[chunk_iterator] = MARS_DATA_BUFFER_FRESHNESS_COUNTER_DIAG[start_idx + diag_idx + chunk_iterator];
                }

                ret_val = mars_action_read_diag_raw_chunk(mars_self, mem_addr, chunk_count, sample_states, sample_raws, sample_counters);

                if (MARS_E_OK == ret_val)
                {
                    for (chunk_iterator = 0u; chunk_iterator < chunk_count; chunk_iterator++)
                    {
                        MARS_DATA_BUFFER_FRESHNESS_COUNTER_DIAG[start_idx + diag_idx + chunk_iterator] = sample_counters[chunk_iterator];
                        diag_values[diag_idx + chunk_iterator].state = sample_states[chunk_iterator];
                        diag_values[diag_idx + chunk_iterator].raw_value = (uint16)(sample_raws[chunk_iterator] & 0xFFFFu);
                    }
                    diag_idx += chunk_count;
                }
                else
                {
                    for (chunk_iterator = diag_idx; chunk_iterator < num_values; chunk_iterator++)
                    {
                        diag_values[chunk_iterator].state = MARS_VAL_BAD;
                    }
                }
            }
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_READ_DIAG_RAW;
    }

    return ret_val;
}

/**
 * @brief         Clear all recoverable safety errors.
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful, MARS_API_ID_CLR_RECOV_SFT_ERRORS errors if failure
 * @design        GID-393904 GID-413855 GID-413857
 */
Mars_ReturnType mars_clear_recoverable_sft_errors( mars_instance_t *const mars_self)
{
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INIT_IDLE_OPERATIONAL), (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_FW_VERSION_MIN_COMPATIBLE, MARS_ALLOW_ALL_FW_VERSIONS);


    if (MARS_E_OK == ret_val)
    {
        mars_mailbox_req_t mlbx_request = {0};
        mars_mailbox_resp_t mlbx_response = {0};

        mlbx_request.slot = MARS_MLBX_SLOT_GEN_CMD;
        mlbx_request.command = MARS_MLBX_CMD_ML_ERR_RECOV;
        mlbx_request.var_h = MARS_MLBX_SUBCMD_CLEAR_RECOV_ERR;
        mlbx_request.var_l = 0u;

        /* Send mailbox request and wait for the response */
        ret_val = mars_exchange_mlbx(mars_self, &mlbx_request, &mlbx_response, MARS_MLBX_TIMEOUT_US);

        if (MARS_E_OK == ret_val)
        {
            ret_val = mars_action_clear_sft_err_set_mlbx_response((const mars_instance_t *)mars_self, (uint8)mlbx_response.response, (uint16)mlbx_response.var_h, (uint32)mlbx_response.var_l);
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_CLR_RECOV_SFT_ERRORS;
    }

    return ret_val;
}

/**
 * @brief         Reads Zero Hour Values from the chip
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   zhv Zero Hour Value data that is read back from the device
 * @return        MARS_E_OK if successful MARS_API_ID_ZHV_READ errors if failed
 * @design        GID-417204 GID-420857 GID-420862
 */
Mars_ReturnType mars_zhv_read( mars_instance_t *const mars_self, mars_zhv_t zhv)
{
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INIT_IDLE_OPERATIONAL),
                                                  (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);


    if (MARS_E_OK == ret_val)
    {
        if (NULL_PTR == zhv)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        else
        {
            ret_val = mars_read_mem_safe(mars_self, MARS_ZHV_START_ADDR, zhv, MARS_BYTES_TO_WORDS(MARS_ZHV_LEN));
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_ZHV_READ;
    }

    return ret_val;
}

/**
 * @brief         Writes Zero Hour Values to the chip
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   zhv Zero Hour Value data that is to be written to the device
 * @return        MARS_E_OK if successful MARS_API_ID_ZHV_WRITE errors if failed
 * @design        GID-417203 GID-420855 GID-420860
 */
Mars_ReturnType mars_zhv_write( mars_instance_t *const mars_self, const mars_zhv_t zhv)
{
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, (mars_driver_status_t)(MARS_INIT_IDLE_OPERATIONAL),
                                                  (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_ALLOW_ALL_FW_VERSIONS, MARS_ALLOW_ALL_FW_VERSIONS);


    if (MARS_E_OK == ret_val)
    {
        if (NULL_PTR == zhv)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        }
        else
        {
            ret_val = mars_l1_write_mem_raw(mars_self, zhv, MARS_ZHV_START_ADDR, MARS_BYTES_TO_WORDS(MARS_ZHV_LEN),MARS_L1_SAFE_CHK_MLBX);
        }
    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_ZHV_WRITE;
    }

    return ret_val;
}

/**
 * @brief         Performs check if the physical IO pin SFT_ERR_N is operational and its logical level can be detected by the API
 * @param [in]    mars_self pointer to driver instance structure
 * @return        Mars_ReturnType MARS_E_OK if success, MARS_API_ID_CHK_SFT_PIN set of errors if failing
 * @design        GID-422096 GID-420566 GID-422097
 */
Mars_ReturnType mars_check_sft_pin( mars_instance_t *const mars_self)
{
    const mars_test_sft_pin_error_en test_sft_pin_is_active = MARS_L2_TEST_SFT_PIN_IS_ACTIVE;
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, MARS_INIT_IDLE_OPERATIONAL, (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_FW_VERSION_MIN_COMPATIBLE, MARS_ALLOW_ALL_FW_VERSIONS);
    
    if (MARS_E_OK == ret_val)
    {
        if (MARS_SFT_ERR_ACTIVE == mars_action_sft_is_active(mars_self))
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_TEST_SFT_PIN,(uint32) test_sft_pin_is_active);
        }

        if (MARS_E_OK == ret_val)
        {
            /* Assert the SFT pin */
            ret_val = mars_action_send_sft_pin_test_command(mars_self,MARS_SFT_ASSERT);
        }
        
        if(ret_val == MARS_E_OK)
        {   
            /* Read the SFT pin value */    
            ret_val = mars_action_check_sft_pin_status(mars_self, MARS_SFT_ASSERT);
        }

        if(ret_val == MARS_E_OK)
        {
            /* De-assert the SFT pin */
            ret_val = mars_action_send_sft_pin_test_command(mars_self,MARS_SFT_DEASSERT);
        }
        
        if(ret_val == MARS_E_OK)
        {
            /* Read the SFT pin value */ 
            ret_val = mars_action_check_sft_pin_status(mars_self, MARS_SFT_DEASSERT);
        }

    }

    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_CHECK_SFT_PIN;
    }

    return ret_val;
}

/**
 * @brief         Generates ZHV data (triggers a ZHV generation frame and reads the result)
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   zhv Zero Hour Value data that is read back from the device
 * @param [in]    frame_time maximum time to wait for that frame to complete, in milliseconds.
 *                If the frame does not finish within this budget, the call fails with a frame-wait timeout
 * @return        Mars_ReturnType MARS_E_OK if success, MARS_API_ID_ZHV_GENERATE set of errors if failing
 * @design        GID-429447 GID-429428 GID-429439
 */
Mars_ReturnType mars_zhv_generate(mars_instance_t *const mars_self, mars_zhv_t zhv, const uint32 frame_time)
{
    Mars_ReturnType ret_val = mars_action_allow_api_call(mars_self, MARS_INIT_IDLE_OPERATIONAL, (uint32)(MARS_OPERATION_MODE_NORMAL | MARS_OPERATION_MODE_DEBUG), MARS_FW_VERSION_MIN_COMPATIBLE, MARS_ALLOW_ALL_FW_VERSIONS);


    if((zhv == NULL_PTR) && (MARS_E_OK == ret_val))
    {
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
    }
    /* Step 1: Inform MAF that the next Frame trigger shall initiate ZHV generation
     and step 2: Check if MARS is READY before triggering a frame */
    if (MARS_E_OK == ret_val)
    {
       ret_val = mars_action_zhv_generate_setup(mars_self);
    }

    /* Step 3: Trigger a frame */
    if (ret_val == MARS_E_OK)
    {
        /* Trigger Frame - MM_FRAME_START */
        ret_val = mars_action_frame_start(mars_self, 0, 0);
    }

    /* Step 4: Wait for Frame complete */
    if (ret_val == MARS_E_OK)
    {
        ret_val = mars_action_wait_frame_ready(mars_self, frame_time);
    }

    /* Step 5: Read back generated ZHV data */
    if (ret_val == MARS_E_OK)
    {
        ret_val = mars_read_mem_safe(mars_self, MARS_ZHV_START_ADDR, zhv, MARS_BYTES_TO_WORDS(MARS_ZHV_LEN));
    }

    /* Step 6: Inform MAF that next frame may not initiate ZHV generation */
    if (MARS_E_OK == ret_val)
    {
       ret_val = mars_action_zhv_generate_cleanup(mars_self);
    }
    if (MARS_E_OK != ret_val)
    {
        ret_val |= MARS_API_ID_ZHV_GENERATE;
    }

    return ret_val;
}

