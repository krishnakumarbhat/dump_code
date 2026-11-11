/* polyspace GUIDELINE:SC03 [No action planned:Low] "This file implements the API logic actions in Layer 2 and calls the needed Layer 1 interfaces." */
/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_l1.h"
#include "mars_l1_raw.h"
#include "mars_l2_private.h"
#include "mars_l2_actions.h"
#include "mars_l2_validated_params.h"
#include "mars_l1_validated_params.h"


/**********************************************************************************************************************
 * LOCAL MACRO
 *********************************************************************************************************************/
#define MARS_SCP_RESP_OK (1u << 0u)
#define MARS_SCP_RESP_CRC_INCORRECT (1u << 1u)
#define MARS_SCP_RESP_PARAM_ERROR (1u << 2u)
#define MARS_MLBX_STATUS_BIT 0u       /* MLBX Response bit 0 - Status */

#define MARS_MLBX_RESP_CRC_BIT_INDEX 28u

#define MARS_DIAG_MEM_SAMPLE_OFFSET (0u)
#define MARS_DIAG_MEM_COUNTER_OFFSET (12u)
#define MARS_DIAG_MEM_SAMPLE_REVERSED_OFFSET (16u)
#define MARS_DIAG_MEM_COUNTER_REVERSED_OFFSET (28u)
#define MARS_SFT_PIN_TEST_START (0xA5A5u)
#define MARS_SFT_PIN_TEST_STOP (0x5A5Au)

#define MARS_MAX_BIT_POS_IN_UINT32 (31u)

#define MARS_FRM_GPX_SET_MASK (0x3u)
#define MARS_FRM_GPX_SET_SELECT_MODE (0x0u)
#define MARS_FRM_GPX_SET_SET_TO_ONE (0x1u)
#define MARS_FRM_GPX_SET_SET_TO_ZERO (0x2u)

#define MARS_ZHV_GENERATE_NEW_TABLE  0u  /* Generate new ZeroHour Value table */
#define MARS_ZHV_USE_EXISTING_TABLE  1u   /* Use the existing ZeroHour Value table */

#define MARS_MLBX_SUBCMD_RD_CRC_VARH_SHIFT (28u)
#define MARS_MLBX_SUBCMD_RD_LEN_SHIFT (4u)

#define MARS_MLBX_SCP_SEND_UPDATE_SIZE_INDEX (4u)
#define MARS_MLBX_SCP_SEND_UPDATE_CRC_INDEX (28u)

#define MARS_SIGNED_9_BIT_CONVERSION_MASK (0x01FFu)
#define MARS_SIGNED_9_BIT_SIGN_MASK (0x0100u)
#define MARS_SIGNED_9_BIT_EXTEND_MASK (0xFE00u)
#define MARS_L1_ERR_MASK    0xFFFFu

#define MARS_MBL_RESP_PASS           0x1uL
#define MARS_MBL_VAR_H_PASS          0x0uL
#define MARS_MBL_VAR_H_ERR_OTPM      0x1uL
#define MARS_MBL_VAR_H_ERR_SEC       0x2uL
#define MARS_MBL_VAR_H_ERR_BOR       0x3uL
#define MARS_MBL_VAR_H_ERR_ADD_CMD   0x4uL
#define MARS_MBL_VAR_H_ERR_CLK_CORE   0x5uL
#define MARS_MBL_VAR_H_ERR_CLK_SYS   0x6uL
#define MARS_MBL_VAR_H_PASS_NO_CLOCK 0x8000uL

typedef enum {
     MARS_R_CORE_BANK_SFT_ERR_STATUS_READ_BIST_INDEX = 0u,
     MARS_F_CORE_BANK_MCU_MSSG_READ_BIST_INDEX = 1u,
     MARS_R_CORE_BANK_SFT_STATUS_READ_BIST_INDEX = 2u,
     MARS_R_CORE_BANK_FRM_ERR_READ_BIST_INDEX = 3u,
     MARS_R_CORE_BANK_ENA_ERR_READ_BIST_INDEX = 4u,
     MARS_R_LOGEN_BANK_CHRP_GEN_ERROR_READ_BIST_INDEX = 5u,
     MARS_R_LOGEN_BANK_LOGEN_ERROR_READ_BIST_INDEX = 6u,
     MARS_R_RXADC_FUSAIRQV_READ_BIST_INDEX = 7u,
     MARS_F_RXADC_FUSAIRQV0_READ_BIST_INDEX = 8u,
     MARS_F_RXADC_FUSAIRQV1_READ_BIST_INDEX = 9u,
     MARS_R_RXADC_FUSAMON_READ_BIST_INDEX = 10u,
     MARS_R_RXADC_MOD0_FUSAIRQV_READ_BIST_INDEX = 11u,
     MARS_R_RXADC_MOD1_FUSAIRQV_READ_BIST_INDEX = 12u,
     MARS_R_RXADC_MOD2_FUSAIRQV_READ_BIST_INDEX = 13u,
     MARS_R_RXADC_MOD3_FUSAIRQV_READ_BIST_INDEX = 14u,
     MARS_R_ASYNC_BANK_ASYNC_ERR1_READ_BIST_INDEX = 15u,
     MARS_R_PROFILER_BANK_PRF_ERR1_READ_BIST_INDEX = 16u,
     MARS_R_PROFILER_BANK_PRF_ERR2_READ_BIST_INDEX = 17u,
     MARS_R_CPU_SYS_MCU_ERR_0_READ_BIST_INDEX = 18u,
     MARS_R_CPU_SYS_MCU_ERR_1_READ_BIST_INDEX = 19u,
     MARS_R_CPU_SYS_MCU_ERR_2_READ_BIST_INDEX = 20u,
     MARS_R_CPU_SYS_MCU_ERR_3_READ_BIST_INDEX = 21u,
     MARS_F_CPU_SYS_DMA_ERR_STATUS_READ_BIST_INDEX = 22u,
     MARS_R_MIPI_BANK_IRQ_STATUS_READ_BIST_INDEX = 23u,
     MARS_R_CPLL_BANK_REFPLL_ERROR_READ_BIST_INDEX = 24u,
     MARS_NUMBER_OF_SFT_ERROR_REGS = 25u
}mars_read_bist_hw_registers_read_index_t; /* polyspace MISRA-C-2023:2.3 [Justified:Low] "The unsed enum over macros to avoid MISRA C:2023 1.1Too many macro definitions" */
/**********************************************************************************************************************
 * VARIABLE DECLARATION
 *********************************************************************************************************************/
static const struct 
{
    uint32 start_address;
    uint32 end_address;
} MARS_MEMORY_MAP[] =
{
    {0x08000u, 0x1FFFFu}, /*Instruction memory*/
    {0x20000u, 0x27FFFu}, /*Data memory*/
    {0x28000u, 0x303FFu}, /*Profiler memory*/
    {0x31000u, 0x313FFu}, /*Async register bank*/
    {0x32000u, 0x32FFFu}, /*Phase Tx look up table*/
    {0x33000u, 0x33FFFu}, /*Register bank*/
    {0x34000u, 0x347FFu}, /*Profiler buffer registers*/
    {0x35000u, 0x357FFu}, /*Mailbox, OTPM, timer, WD, MCU register bank*/
    {0x37000u, 0x37FFFu}, /*Sampling block ADC, Register bank*/
    {0x38000u, 0x387FFu}, /*LOGEN register bank*/
    {0x39000u, 0x397FFu}, /*Ref-PLL register bank*/
    {0x3A000u, 0x3A3FFu}, /*MIPI (CSI-2) register bank*/
    {0x3B000u, 0x3B3FFu}  /*SSI configuration register bank*/
};

typedef struct 
{
    Mars_ReturnType (*gpio_write) (mars_instance_t *const mars_self, const mars_gpio_level_en level);
    mars_gpio_level_en gpio_level;
}mars_init_debug_gpio_t;
/**********************************************************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/
static mars_mbl_error_en mars_action_mbl_set_mlbx_response(const mars_mailbox_resp_t * const mlbx_response);
static Mars_ReturnType mars_action_scp_error_read(mars_instance_t *const mars_self, const uint32 mlbx_scp_crc);
static void mars_action_scp_set_mlbx_response(mars_instance_t *const mars_self, const uint8 mars_scp_resp, const uint16 mars_scp_resp_var_h, const uint32 mars_scp_resp_var_l);
static void mars_action_maf_set_mlbx_response(mars_instance_t *const mars_self, const uint8 mars_maf_resp, const uint16 mars_maf_resp_var_h, const uint32 mars_maf_resp_var_l, const mars_activation_t activation_type);
static Mars_ReturnType mars_action_ssi_set_speed( mars_instance_t *const mars_self);
static Mars_ReturnType mars_action_mbl_check_status(mars_instance_t *const mars_self);
static Mars_ReturnType mars_action_ssi_configure( mars_instance_t *const mars_self);
static void mars_action_mars_configure_param_check_modes( const mars_rfdist_mode_t *const rfdist_mode, const mars_bias_noise_filter_t *const bias_noise_filter, mars_api_check_error_en *const param_index);
static void mars_action_mars_configure_param_tx_rx_check(const mars_tx_config_t *const tx_config, const mars_rx_config_t *const rx_config, mars_api_check_error_en *const param_index);
static void mars_action_mars_configure_tx_rx(const mars_tx_config_t *const tx_config, const mars_rx_config_t *const rx_config, mars_scratchpad_cfg_t *const mars_scp_cfg);
static void mars_action_mars_configure_modes( const mars_rfdist_mode_t *const rfdist_mode, const mars_bias_noise_filter_t *const bias_noise_filter_ctrl, mars_scratchpad_cfg_t *const mars_scp_cfg);
static void mars_action_mars_configure_param_check_mipi_chrp( const mars_mipi_config_t *const mipi_config, const mars_mipi_diag_t *const mipi_diag, const mars_chirp_config_t *const chrp_config, const mars_chirp_mode_t *const chrp_mode, mars_api_check_error_en *const param_index);
static void mars_action_mars_configure_mipi_chrp(const mars_mipi_config_t *const mipi_config, const mars_mipi_diag_t *const mipi_diag, const mars_chirp_config_t *const chrp_config, const mars_chirp_mode_t *const chrp_mode, mars_scratchpad_cfg_t *const mars_scp_cfg);

/**********************************************************************************************************************
 *  GLOBAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/**
 * @brief         Internal initialization of Radar API variables
 * @param [in]    mars_self pointer to driver instance structure
 * @return        void
 * @design        GID-350955
 */
void mars_action_init(mars_instance_t *const mars_self)
{
    uint32 clear_index;

    MARS_DATA_DRIVER_STATUS = MARS_UNINTIALIZED;
    MARS_DATA_OP_MODE_STATUS = MARS_OPERATION_MODE_UNDEFINED;

    /* Initializing status and error variables */
    MARS_DATA_MBL_ERROR = MARS_L2_MBL_NO_ERROR;
    MARS_DATA_MAF_ERROR = MARS_L2_MAF_NO_ERROR;
    MARS_DATA_SFT_ERROR = MARS_L2_SFT_NO_ERROR;
    MARS_DATA_SSI_ERROR = MARS_L2_SSI_NO_ERROR;
    MARS_DATA_SCP_ERROR = MARS_L2_SCP_NO_ERROR;
    MARS_DATA_PCW_ERROR = MARS_L2_PCW_NO_ERROR;
    MARS_DATA_STS_ERROR = MARS_L2_STS_NO_ERROR;
    MARS_DATA_MCU_STATUS = MCU_NO_STATUS;
    MARS_DATA_CTRL_STATUS = CTRL_MUX_CLK_IN_NO_STATUS;
    MARS_DATA_FW_VERSION = 0u;

    /* Initializing buffer variables */
    MARS_DATA_BUFFER_MAF_SRC_ADDR = NULL_PTR;
    MARS_DATA_BUFFER_MAF_SIZE = 0u;
    MARS_DATA_BUFFER_MAF_CRC = 0u;

    /*Mars driver data initialization*/
    for (clear_index = 0; clear_index < MARS_DRIVER_DATA_ARRAY_SIZE; clear_index++)
    {
        MARS_DATA_BUFFER_DRIVER_DATA[clear_index] = 0u;
    }
    for (clear_index = 0; clear_index < MARS_BYTES_TO_WORDS(sizeof(mars_data_buffer_scp_error_t)); clear_index++)
    {
        MARS_DATA_BUFFER_SCP_ERROR.word[clear_index] = 0u;
    }

    for (clear_index = 0; clear_index < MARS_DIAG_VALUES_MAX_NUMBER; clear_index++)
    {
        MARS_DATA_BUFFER_FRESHNESS_COUNTER_DIAG[clear_index] = 0xFFu;
    }
}

/***************************************
 * MEMORY READ/WRITE INTERFACES
 **************************************/

/**
 * @brief         Reads SCP error data
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    mlbx_scp_crc CRC value from mailbox
 * @return        MARS_E_OK if read successful and CRC matches, MARS_E_NOT_OK otherwise
 * @design        GID-350963
 */
static Mars_ReturnType mars_action_scp_error_read(mars_instance_t *const mars_self, const uint32 mlbx_scp_crc)
{
    Mars_ReturnType ret_val;
    uint32 scp_crc = 0u;

    const Mars_ReturnType ret_val_memblk = mars_read_mem_safe(mars_self, (MARS_SCRATCHPAD_CFG_START_ADDRESS + MARS_SCP_ERROR_BITS_OFFSET), (uint32 * const)&MARS_DATA_BUFFER_SCP_ERROR.word[0],
                                                        MARS_BYTES_TO_WORDS(sizeof(mars_data_buffer_scp_error_t)));

    /* Calculate the CRC over the Mars SCP data */
    const Mars_ReturnType ret_val_crc = mars_calculate_crc(mars_self, &MARS_DATA_BUFFER_SCP_ERROR.word[0], sizeof(mars_data_buffer_scp_error_t), &scp_crc);

    if ((MARS_E_OK == ret_val_memblk) && (MARS_E_OK == ret_val_crc) && (mlbx_scp_crc == scp_crc))
    {
        ret_val = MARS_E_OK;
    }
    else
    {
        ret_val = MARS_E_NOT_OK;
    }

    return ret_val;
}

/***************************************
 * MBL INTERFACES
 **************************************/
/**
 * @brief         Sets mailbox response status

 * @param[in]     mlbx_response
 * @return        mars_mbl_error_en identified error
 * @design        GID-350965 GID-487459
 */
static mars_mbl_error_en mars_action_mbl_set_mlbx_response(const mars_mailbox_resp_t * const mlbx_response)
{
    mars_mbl_error_en ret = MARS_L2_MBL_NO_ERROR;

    /*  MLBX RESPONSE:
     *  [bit 0] : 0 Failed / 1 Passed */

    /*  MLBX VAR H:
     *  [value 0u] : Pass
     *  [value 1u] : OTPM error
     *  [value 2u] : WRITE SEC REG error
     *  [value 3u] : BOR error
     *  [value 4u] : Additional CMD error
     *  [value 5u] : REF-PLL error
     *  [value 6u] : ADC-PLL error

     *  MLBX VAR L:
     *  not used */

    /* PASS_NO_CLOCK is a successful MBL result, but host SSI must stay low speed. */
    if (MARS_MBL_VAR_H_PASS_NO_CLOCK == mlbx_response->var_h)
    {
        ret = MARS_L2_MBL_NO_CLOCK_SET_ERROR;
    }
    /* check if response is OK/NOT OK */
    else if ((mlbx_response->response & (1u << MARS_MLBX_STATUS_BIT)) != MARS_MBL_RESP_PASS)  /* parse errors only if response indicates fail */
    {
        switch (mlbx_response->var_h)
        {
            case MARS_MBL_VAR_H_PASS:
                /* All MBL, HW and BIST tests are ok. This is not really expected here along with response 'fail' */
                ret = MARS_L2_MBL_NO_ERROR;
                break;

            case MARS_MBL_VAR_H_ERR_OTPM:
                /* Error reading OTPM */
                ret = MARS_L2_MBL_OTPM_ERROR;
                break;
            case MARS_MBL_VAR_H_ERR_BOR:
                /* Error configuring BOR */
                ret = MARS_L2_MBL_BOR_ERROR;
                break;
            case MARS_MBL_VAR_H_ERR_SEC:
                /* Error to configure security mode */
                ret = MARS_L2_MBL_WRITE_SEC_REG_ERROR;
                break;
            case MARS_MBL_VAR_H_ERR_CLK_CORE:
                /* Error to configure clock core */
                ret = MARS_L2_MBL_CLOCK_CORE_ERROR;
                break;
            case MARS_MBL_VAR_H_ERR_CLK_SYS:
                /* Error to configure clock system */
                ret = MARS_L2_MBL_CLOCK_SYS_ERROR;
                break;
            case MARS_MBL_VAR_H_ERR_ADD_CMD:
                /* Error while MBL executing additional commands */
                ret = MARS_L2_MBL_ADDITIONAL_CMD_ERROR;
                break;
            default:
                /* Reported error is not in the list of known error IDs */
                ret = MARS_L2_MBL_UNKNOWN_ERROR;
                break;
        }
    }
    else
    {
        /* Response indicates pass and var_h is not PASS_NO_CLOCK: no mailbox-level error. */
        ret = MARS_L2_MBL_NO_ERROR;
    }
    return ret;
}

/**
 * @brief         Checks Mars Boot Loader status
 * @param [inout] mars_self pointer to driver instance structure
 * @return        MARS_E_OK if MBL successful, error code if failed
 * @design        GID-350959 GID-487458
 */
static Mars_ReturnType mars_action_mbl_check_status(mars_instance_t *const mars_self)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    Mars_ReturnType ret_val_gp0 = MARS_E_OK;
    Mars_ReturnType ret_val_sft = MARS_E_OK;
    Mars_ReturnType ret_val_mlbx = MARS_E_OK;

    MARS_DATA_MBL_ERROR = MARS_L2_MBL_UNKNOWN_ERROR;

    mars_mailbox_resp_t mlbx_response = {0};

    mars_gpio_level_en sft_err_chn_val = L0_IO_LO;
    mars_gpio_level_en gp0_chn_val = L0_IO_LO;
    mlbx_response.slot = MARS_MLBX_SLOT_STATUS_RESPONSE;

    ret_val_mlbx = mars_read_mlbx(mars_self, &mlbx_response, MARS_MLBX_INIT_TIMEOUT_US);
    ret_val_gp0 = mars_gpio_gp0_read(mars_self, &gp0_chn_val);
    ret_val_sft = mars_gpio_sft_read(mars_self, &sft_err_chn_val);

    /* we shall check if any of the boot report building blocks have resulted in error */
    if ((ret_val_gp0 == MARS_E_OK) && (ret_val_sft == MARS_E_OK))
    {
        /* MBL mailbox response has not arrived within timeout */
        if (((ret_val_mlbx & (MARS_ERROR_L1_BIT_MASK << MARS_ERROR_L1_BIT_OFFSET)) == MARS_ERROR_L1_MLBX) &&
            ((ret_val_mlbx & (MARS_ERROR_ID_BIT_MASK << MARS_ERROR_ID_BIT_OFFSET)) == MARS_L1_E_MLBX_TIMEOUT_ERROR))
        {

            if (sft_err_chn_val == L0_IO_LO)
            {
                if (gp0_chn_val == L0_IO_LO) /* SFT/MLBx/GP0  = 0/0/0 indicates Power-up fail */
                {
                    MARS_DATA_MBL_ERROR = MARS_L2_MBL_PMU_TASK_ERROR;   /* 0/0/0 */
                }
                else  /* SFT/MLBx/GP0  = 0/0/1 indicates DFT (BIST) stuck */
                {
                    MARS_DATA_MBL_ERROR = MARS_L2_MBL_PMU_BIST_ERROR;   /* 0/0/1 */
                }
            }
        }
        else /* Mailbox response has arrived or MLBX indication has been received without mailbox data */
        {
            if (sft_err_chn_val == L0_IO_LO) /* SFT :0 */
            {
                if (gp0_chn_val == L0_IO_LO) /* SFT/MLBx/GP0  = 0/1/0 indicates DFT error */
                {
                    MARS_DATA_MBL_ERROR = MARS_L2_MBL_DFT_ERROR;    /* 0/1/0 */
                }
                else /* SFT/MLBx/GP0  = 0/1/1  Host reads mailbox response message */
                {
                    if (ret_val_mlbx == MARS_E_OK)
                    {
                        MARS_DATA_MBL_ERROR = mars_action_mbl_set_mlbx_response(&mlbx_response);
                    }
                }
            }
            else /* SFT :1 */
            {
                if ((gp0_chn_val == L0_IO_LO) && (ret_val_mlbx == MARS_E_OK))/* SFT/MLBx/GP0  = 1/1/0  Host reads mailbox response message and continues with MAF*/
                {
                    MARS_DATA_MBL_ERROR = mars_action_mbl_set_mlbx_response(&mlbx_response);
                }
            }
        }
    }

    if ((MARS_L2_MBL_NO_ERROR != MARS_DATA_MBL_ERROR) && (MARS_L2_MBL_NO_CLOCK_SET_ERROR != MARS_DATA_MBL_ERROR))
    {
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_MBL, (uint32)MARS_DATA_MBL_ERROR);
    }

    if (MARS_E_OK != ret_val_gp0)
    {
        ret_val = ret_val_gp0;
    }
    else if (MARS_E_OK != ret_val_sft)
    {
        ret_val = ret_val_sft;
    }
    else
    {
        if ((MARS_E_OK != ret_val_mlbx) &&
             (MARS_L2_MBL_UNKNOWN_ERROR == MARS_DATA_MBL_ERROR) &&
             ((ret_val_mlbx & (MARS_ERROR_L1_BIT_MASK << MARS_ERROR_L1_BIT_OFFSET)) == MARS_ERROR_L1_MLBX) &&
             ((ret_val_mlbx & (MARS_ERROR_ID_BIT_MASK << MARS_ERROR_ID_BIT_OFFSET)) != MARS_L1_E_MLBX_TIMEOUT_ERROR))
        {
            /* mlbx returned a non-timeout L1 error; the inner logic could not diagnose MBL status */
            ret_val = ret_val_mlbx;
        }
    }

    return ret_val;
}


/***************************************
 * MAF INTERFACES
 **************************************/

/**
 * @brief         Sets MAF mailbox response status
 * @param [inout] mars_self Pointer to driver instance structure
 * @param [in]    mars_maf_resp MAF mailbox response status
 * @param [in]    mars_maf_resp_var_h MAF mailbox response variable high
 * @param [in]    mars_maf_resp_var_l MAF mailbox response variable low (not used)
 * @return        none
 * @design        GID-350967
 */
static void mars_action_maf_set_mlbx_response(mars_instance_t *const mars_self, const uint8 mars_maf_resp, const uint16 mars_maf_resp_var_h, const uint32 mars_maf_resp_var_l, const mars_activation_t activation_type)
{
    /*  MLBX RESPONSE:
     *  [bit 0] : 0 Failed / 1 Passed
     *  [bit 4] : 0 No Parity check error / 1 Parity check error (from mailbox command) */

    /*  MLBX VAR H:
     *  [bit 0 - bit 15] CRC bits [31:16] */

    /*  MLBX VAR L:
     *  [bit 0 - bit 15] CRC bits [15:0]  */ 

    if (1u == MARS_GET_BIT_VALUE(mars_maf_resp, MARS_MLBX_STATUS_BIT))
    {   
#if defined(MARS_ALLOW_ACTIVATION_NO_CRC)
        /* MLBX Response Bit 0 - Passed */
        if(activation_type == ACTIVATE_NO_CHECK)
        {
             /* MAF deactivation successful, reset MAF error status */
            MARS_DATA_MAF_ERROR = MARS_L2_MAF_NO_ERROR;
        }

        if(activation_type == ACTIVATE_CHECK_CRC)
        {

#else
            (void)activation_type;
#endif /* MARS_ALLOW_ACTIVATION_NO_CRC */

#if defined (DISABLE_CHECK_CRC)
            (void)mars_maf_resp_var_l;
            MARS_DATA_MAF_ERROR = MARS_L2_MAF_NO_ERROR;
#else
            const uint32 maf_crc_cal = (((uint32)mars_maf_resp_var_h & 0xFFFFuL) << MARS_MAF_ACTIVATE_CRC_VAR_H_SHIFT) | (mars_maf_resp_var_l & 0xFFFFuL);
            
            if(maf_crc_cal == MARS_DATA_BUFFER_MAF_CRC)
            {
                MARS_DATA_MAF_ERROR = MARS_L2_MAF_NO_ERROR;
            }
            else 
            {
                /* CRC check failed */
                MARS_DATA_MAF_ERROR = MARS_L2_MAF_CRC_INCORRECT_ERROR;
            }
#endif /* DISABLE_CHECK_CRC */
#if defined(MARS_ALLOW_ACTIVATION_NO_CRC)
        }
#endif /* MARS_ALLOW_ACTIVATION_NO_CRC */
    }
    else if(1u == MARS_GET_BIT_VALUE(mars_maf_resp_var_h, 1u))
    {
        /* MLBX VAR H Bit 1 - Secure MAF error */
        MARS_DATA_MAF_ERROR = MARS_L2_MAF_SECURE_MAF_ERROR;
    }
    else if(1u == MARS_GET_BIT_VALUE(mars_maf_resp_var_h, 2u))
    {
        /* MLBX VAR H Bit 2 - CRC error */
        MARS_DATA_MAF_ERROR = MARS_L2_MAF_CRC_ERROR;
    }
    else if (1u == MARS_GET_BIT_VALUE(mars_maf_resp, MARS_MLBX_PARITY_CHECK_BIT))
    {
        /* MLBX Response Bit 4 - Parity error */
        /* handled by the Level 1 */
        ;
    }
    else
    {
        MARS_DATA_MAF_ERROR = MARS_L2_MAF_UNKNOWN_ERROR;
    }
    


}

/***************************************
 * SFT_ERR_N INTERFACES
 **************************************/

/**
 * @brief         Checks if SFT is active
 * @param [in]    mars_self Pointer to driver instance structure
 * @return        MARS_SFT_ERR_ACTIVE if SFT error is active, MARS_SFT_ERR_NOT_ACTIVE otherwise
 * @design        GID-348149 GID-351808 GID-351806
 */
mars_sft_err_n_t mars_action_sft_is_active(mars_instance_t *const mars_self)
{
    mars_sft_err_n_t ret_val = MARS_SFT_ERR_NOT_ACTIVE;

    mars_gpio_level_en sft_err_chn_val = L0_IO_HI;
    if (mars_gpio_sft_read(mars_self, &sft_err_chn_val) == MARS_E_OK)
    {
        if (L0_IO_LO == sft_err_chn_val)
        {
            ret_val = MARS_SFT_ERR_ACTIVE;
        }
        else /* L0_IO_HI */
        {
            ret_val = MARS_SFT_ERR_NOT_ACTIVE;
        }
    }

    return ret_val;
}


/***************************************
 * SSI INTERFACES
 **************************************/
/**
 * @brief         Set SSI mailbox response
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    mars_ssi_resp SSI response byte
 * @param [in]    mars_ssi_resp_var_h SSI response variable high (unused)
 * @param [in]    mars_ssi_resp_var_l SSI response variable low (unused)
 * @return        none
 * @design        GID-350969
 */
void mars_action_ssi_set_mlbx_response(mars_instance_t *const mars_self, const uint8 mars_ssi_resp, const uint16 mars_ssi_resp_var_h, const uint32 mars_ssi_resp_var_l)
{
    (void)mars_ssi_resp_var_h;
    (void)mars_ssi_resp_var_l;

    /*  MLBX RESPONSE:
     *  [bit 0] : 0 Failed / 1 Passed
     *  [bit 4] : 0 No Parity check error / 1 Parity check error (from mailbox command) */

    /*  MLBX VAR H:
     *  not used */

    /*  MLBX VAR L:
     *  not used */

    if (1u == MARS_GET_BIT_VALUE(mars_ssi_resp, MARS_MLBX_STATUS_BIT))
    {
        /* MLBX Response Bit 0 - Passed */
        MARS_DATA_SSI_ERROR = MARS_L2_SSI_NO_ERROR;
    }
    else if (1u == MARS_GET_BIT_VALUE(mars_ssi_resp, MARS_MLBX_PARITY_CHECK_BIT))
    {
        /* MLBX Response Bit 4 - Parity error */
        /* handled by the Level 1 */
        ;
    }
    else
    {
        /* MLBX Response No bits set */
        MARS_DATA_SSI_ERROR = MARS_L2_SSI_OPERATION_MODE_ERROR;
    }
}

/**
 * @brief         Sets SSI mode
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    ssi_mode SSI configuration mode (MARS_SSI_QSPI or MARS_SSI_SPI)
 * @return        MARS_E_OK if successful, error code otherwise
 * @design        GID-352167
 */
Mars_ReturnType mars_action_ssi_set_mode( mars_instance_t *const mars_self, const mars_ssi_config_t ssi_mode)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    const mars_l0_ssi_mode_en mode = ((ssi_mode == MARS_SSI_QSPI) ? L0_SSI_MODE_QSPI : L0_SSI_MODE_SPI);

    ret_val = mars_ssi_set_mode(mars_self, mode);
    if(MARS_E_OK == ret_val)
    {
        ret_val = mars_action_ssi_set_speed(mars_self);
    }

    return ret_val;
}

/**
 * @brief         Sets SSI speed
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful, error code otherwise
 * @design        GID-352170
 */
static Mars_ReturnType mars_action_ssi_set_speed(mars_instance_t *const mars_self)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    mars_l0_ssi_speed_en speed = L0_SSI_SPEED_LO;

    if (0 != (MARS_UNINTIALIZED & MARS_DATA_DRIVER_STATUS))
    {
        /* Host SSI slow until MBL outcome is known */
        speed = L0_SSI_SPEED_LO;
    }
    else if (0 != (MARS_INITIALIZED_FW_NOT_RUNNING & MARS_DATA_DRIVER_STATUS))
    {
#if defined(MARS_POST_MBL_SSI_HIGH_IF_CLOCK_OK)
        if (MARS_L2_MBL_NO_ERROR == MARS_DATA_MBL_ERROR)
        {
            speed = L0_SSI_SPEED_HI;
        }
        else
        {
            speed = L0_SSI_SPEED_LO;
        }
#else
        /* MAF not yet running; default slow SSI until MAF idle */
        speed = L0_SSI_SPEED_LO;
#endif
    }
    else if (0 != ((MARS_INIT_IDLE_OPERATIONAL) & MARS_DATA_DRIVER_STATUS))
    {
        /* Mars is running MAF */
        speed = L0_SSI_SPEED_HI;
    }
    else
    {
        /* invalid driver state */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_DRIVER_STATUS_ERROR);
    }

    if (MARS_E_OK == ret_val)
    {
        ret_val = mars_ssi_set_speed(mars_self, speed);
    }

    return ret_val;
}

/**
 * @brief         Configures SSI for Mars
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful, error code otherwise
 * @design        GID-352613
 */
static Mars_ReturnType mars_action_ssi_configure( mars_instance_t *const mars_self)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    /* Initialize SSI CRC driver */
    ret_val = mars_configure_crc(mars_self);

    return ret_val;
}

/***************************************
 * SCP INTERFACES
 **************************************/
/**
 * @brief         Validates and stores SCP mailbox response
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    mars_scp_resp scratchpad response data
 * @param [in]    mars_scp_resp_var_h Mailbox VarH
 * @param [in]    mars_scp_resp_var_l Mailbox VarL
 * @return        MARS_E_OK if successful MARS_L2_SCP_PARAMETER_ERROR is fails
 * @design        GID-350518
 */
static void mars_action_scp_set_mlbx_response(mars_instance_t *const mars_self, const uint8 mars_scp_resp, const uint16 mars_scp_resp_var_h, const uint32 mars_scp_resp_var_l)
{

    /*  MLBX RESPONSE:
     *  [bit 0] : 0 Failed / 1 Passed
     *  [bit 1] : 0 CRC check passed / 1 CRC check failed
     *  [bit 2] : 0 No Param Error / 1 Param Error
     *  [bit 4] : 0 No Parity check error / 1 Parity check error (from mailbox command)

     *  MLBX VAR H:
     *  [bit 0:3] CRC32_H
     *  [bit 4:9] LEN-1
     *  [bit 10:15] CMD

     *  MLBX VAR L:
     *  [bit 0-27] CRC32_L */

    if (1u == MARS_GET_BIT_VALUE(mars_scp_resp, MARS_MLBX_STATUS_BIT))
    {
        /* MLBX Response Bit 0 - Passed */
        MARS_DATA_SCP_ERROR = MARS_L2_SCP_NO_ERROR;
    }
    else if (1u == MARS_GET_BIT_VALUE(mars_scp_resp, 1u))
    {
        /* MLBX Response Bit 1 - CRC failed */
        MARS_DATA_SCP_ERROR = MARS_L2_SCP_CRC_INCORRECT_ERROR;
    }
    else if (1u == MARS_GET_BIT_VALUE(mars_scp_resp, 2u))
    {
        /* MLBX Response Bit 2 - Param error */

        /* Read the validity bits that marks the param error - 96 valid bit fields */

        uint32 mlbx_scp_resp_crc = (uint32)mars_scp_resp_var_h & 0xFu;
        mlbx_scp_resp_crc = (mlbx_scp_resp_crc << MARS_MLBX_RESP_CRC_BIT_INDEX) + (mars_scp_resp_var_l & 0x0FFFFFFFu);

        if (mars_action_scp_error_read(mars_self, mlbx_scp_resp_crc) == MARS_E_OK)
        {
            uint32 err_bits = 0;
            /* calculate error ID enum from returned VALID bts*/
            err_bits = mars_scp_get_first_error(&MARS_DATA_BUFFER_SCP_ERROR);
            /* check if there was a param error bit set in a valid position */
            if (err_bits != MARS_GETFIRSTERROR_INVALID)
            {
                const uint32 error_id = (uint32)MARS_L2_SCP_RFDIST_MODE_ERROR + err_bits;
                if (error_id < (uint32)MARS_L2_SCP_LAST_ERROR_POS)
                {
                    MARS_DATA_SCP_ERROR = (mars_scp_error_en)error_id; /* polyspace MISRA-C-2023:10.5 [No action planned:Low] "Transformation of a value received via mailbox" */
                }
                else
                {
                    /* if no known valid bit is set but param error is true then return "generic" parameter error */
                    MARS_DATA_SCP_ERROR = MARS_L2_SCP_PARAMETER_ERROR;
                }
            }
            else
            {
                /* if no valid bit is set but param error is true then return "generic" parameter error */
                MARS_DATA_SCP_ERROR = MARS_L2_SCP_PARAMETER_ERROR;
            }
        }
        else
        {
            /* Parameter error was indicated but the precise value could not be identified due to CRC mismatch */
            MARS_DATA_SCP_ERROR = MARS_L2_SCP_PARAMETER_ERROR;
        }
    }
    else if (1u == MARS_GET_BIT_VALUE(mars_scp_resp, MARS_MLBX_PARITY_CHECK_BIT))
    {
        /* MLBX Response Bit 4 - Parity error */
        /* handled by the Level 1 */
        ;
    }
    else
    {
        /* MLBX Response No bits set */
        MARS_DATA_SCP_ERROR = MARS_L2_SCP_UNKNOWN_ERROR;
    }
}
/**
 * @brief         Set SCP configbist mailbox response
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    mars_configbist_resp configbist response byte
 * @param [in]    mars_configbist_resp_var_h configbist response variable high
 * @param [in]    mars_configbist_resp_var_l configbist response variable low
 * @return        MARS_E_OK if successful, specific error code if failed
 * @design        GID-350976
 */
Mars_ReturnType mars_action_scp_configbist_set_mlbx_response(mars_instance_t *const mars_self, const uint8 mars_configbist_resp, const uint16 mars_configbist_resp_var_h, const uint32 mars_configbist_resp_var_l)
{
    Mars_ReturnType ret_val = MARS_E_OK;


    /*  MLBX RESPONSE:
     *  [bit 0] : 0 Failed / 1 Passed
     *  [bit 1] : 0 CRC check passed / 1 CRC check failed
     *  [bit 2] : 0 no Parameter Error / 1 Parameter Error
     *  [bit 4] : 0 no parity Error / 1 parity Error

     *  MLBX VAR H:
     *  not used

     *  MLBX VAR L:
     *  not used */

    if (MARS_SCP_RESP_OK == (mars_configbist_resp & MARS_SCP_RESP_OK))
    {
        /* MLBX Response Bit 0 - Passed */
        ret_val = MARS_E_OK;
    }
    else if (MARS_SCP_RESP_CRC_INCORRECT == (mars_configbist_resp & MARS_SCP_RESP_CRC_INCORRECT))
    {
        /* MLBX Response Bit 1 - CRC failed */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP, (uint32)MARS_L2_SCP_CRC_INCORRECT_ERROR);
    }
    else if (MARS_SCP_RESP_PARAM_ERROR == (mars_configbist_resp & MARS_SCP_RESP_PARAM_ERROR))
    {
        mars_scp_error_en config_bist_param_error = MARS_L2_SCP_LAST_ERROR_POS;
        /* MLBX Response Bit 2 - Parameter error */
        uint32 mlbx_configbist_resp_crc = (uint32)mars_configbist_resp_var_h & 0xFu;
        mlbx_configbist_resp_crc = (mlbx_configbist_resp_crc << MARS_MLBX_RESP_CRC_BIT_INDEX) + (mars_configbist_resp_var_l & 0x0FFFFFFFu);

        if (mars_action_scp_error_read(mars_self, mlbx_configbist_resp_crc) == MARS_E_OK)
        {
            /* calculate error ID enum from returned VALID bts*/
            const uint32 err_bits = mars_scp_get_first_error(&MARS_DATA_BUFFER_SCP_ERROR);
            /* check if there was a param error bit set in a valid position */
            if (err_bits != MARS_GETFIRSTERROR_INVALID)
            {
                const uint32 error_id = (uint32)MARS_L2_SCP_RFDIST_MODE_ERROR + err_bits;
                if (error_id < (uint32)MARS_L2_SCP_LAST_ERROR_POS)
                {
                    config_bist_param_error = (mars_scp_error_en)error_id; /* polyspace MISRA-C-2023:10.5 [No action planned:Low] "Transformation of a value received via mailbox" */
                }
                else
                {
                    /* if no known valid bit is set but param error is true then return "generic" parameter error */
                    config_bist_param_error = MARS_L2_SCP_PARAMETER_ERROR;
                }
            }
            else
            {
                /* if no valid bit is set but param error is true then return "generic" parameter error */
                config_bist_param_error = MARS_L2_SCP_PARAMETER_ERROR;
            }
        }
        else
        {
            /* Parameter error was indicated but the precise value could not be identified due to CRC mismatch */
            config_bist_param_error = MARS_L2_SCP_PARAMETER_ERROR;
        }

        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP, (uint32)config_bist_param_error);
    }
    else
    {
        /* Error was indicated but the value could not be identified */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP,   (uint32)MARS_L2_SCP_UNKNOWN_ERROR);
    }

    return ret_val;
}

/**
 * @brief         Reads back data from MAF via the mailbox read-back command
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    subcmd read-back subcommand identifying the data to retrieve
 * @param [out]   dst destination buffer for the read-back data
 * @param [in]    words number of 32-bit words to read back
 * @return        MARS_E_OK if successful, specific error code if failed
 * @design        GID-448276 GID-509244
 */
Mars_ReturnType mars_action_scp_read_back( mars_instance_t *const mars_self, const uint32 subcmd, uint32 *const dst, const uint32 words)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    const mars_rd_back_error_en rd_back_parameter_error = MARS_L2_RD_BACK_PARAMETER_ERROR;
    const mars_rd_back_error_en rd_back_crc_error = MARS_L2_RD_BACK_CRC_ERROR;
    const mars_rd_back_error_en rd_back_lenght_error = MARS_L2_RD_BACK_LENGTH_ERROR;
    const mars_rd_back_error_en rd_back_unkonwn_error = MARS_L2_RD_BACK_UNKNOWN_ERROR;

    mars_mailbox_req_t mlbx_request = {0};
    mars_mailbox_resp_t mlbx_response = {0};

    /* Build the mailbox read-back request */
    mlbx_request.slot = MARS_MLBX_SLOT_GEN_CMD;
    mlbx_request.command = MARS_MLBX_CMD_ML_RD_BACK;
    mlbx_request.var_h = (uint32)subcmd;
    mlbx_request.var_l = 0u;

    /* Send mailbox request and wait for the response */
    ret_val = mars_exchange_mlbx(mars_self, &mlbx_request, &mlbx_response, MARS_MLBX_TIMEOUT_US);

    if (MARS_E_OK == ret_val)
    {
        if (MARS_SCP_RESP_OK == (mlbx_response.response & MARS_SCP_RESP_OK))
        {
            /* Extract CRC from the response: CRC32_H 31:28 from MLBX_H 7:4, CRC32_L 27:0 from MLBX_L 31:4 */
            const uint32 resp_crc = (((uint32)mlbx_response.var_h & 0x0FuL) << MARS_MLBX_SUBCMD_RD_CRC_VARH_SHIFT) | (mlbx_response.var_l & 0x0FFFFFFFuL);
            /* Extract LEN-1 from the response: MLBX_H 9:4 */
            const uint32 resp_len = (((uint32)mlbx_response.var_h >> MARS_MLBX_SUBCMD_RD_LEN_SHIFT) & 0x3FuL) + 1uL;
            if (resp_len > words)
            {
                mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_RD_BACK, (uint32)rd_back_lenght_error);
            }
            else
            {
                /* Read the data from the read-back memory block */
                ret_val = mars_read_mem_safe(mars_self, MARS_SCRATCHPAD_CFG_START_ADDRESS, dst, resp_len);
            }

            if (MARS_E_OK == ret_val)
            {
                /* Validate CRC of the read-back data */
                uint32 calc_crc = 0u;
                ret_val = mars_calculate_crc(mars_self, (const uint32 *const)dst, resp_len * sizeof(uint32), &calc_crc);

                if (MARS_E_OK == ret_val)
                {
                    if (calc_crc != resp_crc)
                    {
                        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_RD_BACK, (uint32)rd_back_crc_error);
                    }
                }
            }
        }
        else if (MARS_SCP_RESP_PARAM_ERROR == (mlbx_response.response & MARS_SCP_RESP_PARAM_ERROR))
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_RD_BACK, (uint32)rd_back_parameter_error);
        }
        else
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_RD_BACK, (uint32)rd_back_unkonwn_error);
        }
    }

    return ret_val;
}

/**
 * @brief         Send Scratchpad to Mars
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    mars_scp_cfg_ref Scratchpad data structure
 * @return        MARS_E_OK if successful MARS_ERROR_L2_SCP errors is fails
 * @design        GID-350516
 */
Mars_ReturnType mars_action_scp_send_update_command(mars_instance_t *const mars_self, mars_scratchpad_cfg_t *const mars_scp_cfg_ref)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    mars_mailbox_req_t mlbx_request = {0};
    mars_mailbox_resp_t mlbx_response = {0};

    /* Update the SCP layout version */
    mars_scp_cfg_ref->frame_1.version = (MARS_MLBX_CMD_CFG_VERSION & 0x0Fu);
    mars_scp_cfg_ref->valid_1 |= (1uL << MARS_VALID_1_VERSION_VALID);

    /* Write the SCP mem blk to Mars */
    ret_val = mars_write_mem_safe(mars_self, &(mars_scp_cfg_ref->valid_1), MARS_SCRATCHPAD_CFG_START_ADDRESS, MARS_BYTES_TO_WORDS(MARS_SCRATCHPAD_SIZE));

    if (MARS_E_OK == ret_val)
    {
        uint32 scp_crc = 0;

        ret_val = mars_calculate_crc(mars_self, &mars_scp_cfg_ref->valid_1, MARS_SCRATCHPAD_SIZE, &scp_crc);

        if (MARS_E_OK == ret_val)
        {
            mlbx_request.slot = MARS_MLBX_SLOT_GEN_CMD;
            mlbx_request.command = MARS_MLBX_CMD_ML_RDR_SCP;
            mlbx_request.var_h = (MARS_BYTES_TO_WORDS(MARS_SCRATCHPAD_SIZE) << MARS_MLBX_SCP_SEND_UPDATE_SIZE_INDEX) | (scp_crc >> MARS_MLBX_SCP_SEND_UPDATE_CRC_INDEX);
            mlbx_request.var_l = (scp_crc & 0x0FFFFFFFu);

            /* Send mailbox request and wait for the response */
            ret_val = mars_exchange_mlbx(mars_self, &mlbx_request, &mlbx_response, MARS_MLBX_TIMEOUT_US);

            mars_action_scp_set_mlbx_response(mars_self, (uint8)mlbx_response.response, (uint16)mlbx_response.var_h, (uint32)mlbx_response.var_l);

            if (MARS_E_OK == ret_val)
            {
                if (MARS_L2_SCP_NO_ERROR == MARS_DATA_SCP_ERROR)
                {
                    ret_val = MARS_E_OK;
                }
                else
                {
                    mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP, (uint32)MARS_DATA_SCP_ERROR);
                }
            }
        }
    }

    return ret_val;
}

/***************************************
 * RDR STS INTERFACES
 **************************************/

/**
 * @brief         Set STS mailbox response
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    mars_sts_resp STS response byte
 * @param [in]    mars_sts_resp_var_h STS response variable high
 * @param [in]    mars_sts_resp_var_l STS response variable low
 * @return        none
 * @design        GID-350978
 */
void mars_action_sts_set_mlbx_response(mars_instance_t *const mars_self, const uint8 mars_sts_resp, const uint16 mars_sts_resp_var_h, const uint32 mars_sts_resp_var_l)
{
    /*  MLBX RESPONSE:
     *  [bit 0] : 0 Failed / 1 Passed
     *  [bit 1] : 0 Slave / 1 Master
     *  [bit 2] : 0 No Radar Safety Error / 1 Radar Safety Error
     *  [bit 3] : 0 No Radar Detected Safety Error / 1 Radar Detected Safety Error
     *  [bit 4] : 0 No Parity check error / 1 Parity check error (from mailbox command) */

    /*  MLBX VAR H:
     *  [bit 0] BOR Power error
     *  [bit 1] Ref- PLL error
     *  [bit 2] MCU error detected
     *  [bit 3] LOGEN error
     *  [bit 4] Rx-ADC error
     *  [bit 5] Frame control error
     *  [bit 6] Async unit error
     *  [bit 7] Profiler unit error
     *  [bit 8] Enable unit error
     *  [bit 9] Sys ADC PLL Unlock
     *  [bit 10] MCU subsystem error
     *  [bit 11] CSI2 error
     *  [bit 12] SSI error
     *  [bit 13] Chirp linearity or synthesizer lock indication error
     *  [bit 14] RFE Safety
     *  [bit 15] Bist/DFT/TE safety error */

    /*  MLBX VAR L:
     *  [0] Radar ready
     *  [1] Safety error
     *  [2] Error detected by safety task
     *  [8:3] Radar status: 1 - IDLE, 2 - POWER UP, 4 - FRAME RUN, 8 - SAFETY, 16- POWER DOWN, 32-FRAME DELAY
     *  [24:9] RDR_MSSG */
    MARS_DATA_STS_ERROR = MARS_L2_STS_NO_ERROR;
    if (1u == MARS_GET_BIT_VALUE(mars_sts_resp, 2u))
    {
        /* MLBX Response Bit 2 - Radar Safety error */
        MARS_DATA_STS_ERROR = MARS_L2_STS_RDR_SFT_ERROR;
    }
    if ((MARS_DATA_STS_ERROR == MARS_L2_STS_NO_ERROR) && (1u == MARS_GET_BIT_VALUE(mars_sts_resp, 3u)))
    {
        /* MLBX Response Bit 3 - Radar DET SFT error */
        MARS_DATA_STS_ERROR = MARS_L2_STS_RDR_DET_SFT_ERROR;
    }
    if ((MARS_DATA_STS_ERROR == MARS_L2_STS_NO_ERROR) && (0u == MARS_GET_BIT_VALUE(mars_sts_resp, 0u)))
    {
        /* MLBX Response No bits set */
        MARS_DATA_STS_ERROR = MARS_L2_STS_UNKNOWN_ERROR;
    }

    if (1u == MARS_GET_BIT_VALUE(mars_sts_resp, 1u))
    {
        /* MLBX Response Bit 1 - Radar control type */
        MARS_DATA_CTRL_STATUS = CTRL_MUX_CLK_IN_INTERNAL;
    }
    else
    {
        MARS_DATA_CTRL_STATUS = CTRL_MUX_CLK_IN_EXTERNAL;
    }

    /* Save the MCU Status based on the VAR L */
    MARS_DATA_MCU_STATUS = (mars_mcustatus_t) mars_sts_resp_var_l; 
    /* Set the SFT Data based on the VAR H - mars_sft_error_en data type matching the error order */
    MARS_DATA_SFT_ERROR = (mars_sft_error_en) mars_sts_resp_var_h;  /* polyspace MISRA-C-2023:10.5 [No action planned:Low] "Transformation of a value received via mailbox" */
}

/***************************************
 * MCU STATUS INTERFACES
 **************************************/
/**
 * @brief         Internal function to handle frame start
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    timestamp millisecond time when Fram Tx is expected to be due
 * @param [in]    metadata_reg Value passed to Mars for transmit in MIPI metadata
 * @return        MARS_E_OK if successful, returns from L1 mars_write_reg_safe and oc_frm_en_set if fails
 * @design        GID-350489
 */
Mars_ReturnType mars_action_frame_start( mars_instance_t *const mars_self, const mars_frame_timestamp_t timestamp, const mars_mipi_metadata_reg_t metadata_reg)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_CPU_SYS_TSTMP0, (uint32)(timestamp & 0xFFFFFFFFu));
    if(ret_val == MARS_E_OK)
    {
        ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_CPU_SYS_TSTMP1, (uint32)(timestamp >> MARS_32_BITS));
    }

    if(MARS_E_OK == ret_val)
    {
        ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_R_CPU_SYS_MTDT, (uint32)metadata_reg);
    }

    if (MARS_E_OK == ret_val)
    {
        ret_val = mars_oc_frm_en_set(mars_self, (uint64)timestamp);
    }

    return ret_val;
}

/**
 * @brief         Check the parameters of mars_configure
* @param [in]    mars_self pointer to driver instance structure
 * @param [in]    tx_config Configuration of TX parameters
 * @param [in]    rx_config configuration of RX parameters
 * @param [in]    rfdist_mode configuration of RF distribution mode (Single, Master, Slave)
 * @param [in]    bias_noise_filter configuration of Bias Noise Filter control
 * @param [in]    mipi_config configuration of MIPI
 * @param [in]    chrp_config configuration of chirp and frame parameters
 * @param [in]    chrp_mode chirp mode configuration
 * @param [in]    gp_config configuration of GP0 & GP1 pin
 * @param [in]    mipi_diag array of up to 16 Mars register addresses, their content will be returned in MIPI metadata
 * @return        MARS_E_OK if no error, MARS_ERROR_L2_API_CHECK errors if fails
 * @design        GID-350498
 */
Mars_ReturnType mars_action_mars_configure_param_check(const mars_instance_t *const mars_self, const mars_tx_config_t *const tx_config, const mars_rx_config_t *const rx_config, /* polyspace GUIDELINE:SC07 [No action planned:Medium] "The function takes all the parameters needed for configuration for MARS to validate them" */
                                                       const mars_rfdist_mode_t *const rfdist_mode, const mars_bias_noise_filter_t *const bias_noise_filter, const mars_mipi_config_t *const mipi_config,
                                                       const mars_chirp_config_t *const chrp_config, const mars_chirp_mode_t *const chrp_mode, const mars_gp_config_t *const gp_config,
                                                       const mars_mipi_diag_t *const mipi_diag)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    mars_api_check_error_en param_index = MARS_L2_API_CHECK_NO_ERROR;
    (void)mipi_diag;

    /* Check TX and RX parameters */
    mars_action_mars_configure_param_tx_rx_check(tx_config, rx_config, &param_index);

    /* Check RF distribution mode, synthesizer mode and chirp mode parameters */
    mars_action_mars_configure_param_check_modes(rfdist_mode, bias_noise_filter, &param_index);

    /* Check MIPI and chirp configuration parameters */
    mars_action_mars_configure_param_check_mipi_chrp(mipi_config, mipi_diag, chrp_config, chrp_mode, &param_index);

    /* Check GP0 & GP1 pin configuration parameters */
    if ((NULL_PTR != gp_config) && (param_index == MARS_L2_API_CHECK_NO_ERROR))
    {
        if (!(((uint32)(gp_config->gp0) <= (uint32)GP_NO_CHANGE) && ((uint32)(gp_config->gp1) <= (uint32)GP_NO_CHANGE)))
        { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the API input parameter is NULL or not in valid range" */
            param_index = MARS_L2_API_CHECK_PARAM_INDEX_8;
        }
    }

    if (MARS_L2_API_CHECK_NO_ERROR != param_index)
    {
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)param_index);
    }

    return ret_val;
}

/**
 * @brief         Check the parameters of mars_configure
 * @param [in]     mars_self pointer to driver instance structure
 * @param [in]    tx_config Configuration of TX parameters
 * @param [in]    rx_config configuration of RX parameters
 * @param [in]    rfdist_mode configuration of RF distribution mode (Single, Master, Slave)
 * @param [in]    bias_noise_filter configuration of Bias Noise Filter control
 * @param [in]    mipi_config configuration of MIPI
 * @param [in]    chrp_config configuration of chirp and frame parameters
 * @param [in]    chrp_mode chirp mode configuration
 * @param [in]    gp_config configuration of GP0 & GP1 pin
 * @param [out]   frame_counter initial frame counter value, incremented by Mars automatically
 * @param [in]    mipi_diag array of up to 16 Mars register addresses, their content will be returned in MIPI metadata
 * @param [out]   maf_fusa_fs Fstart used in MAF FUSA functions
 * @return        MARS_E_OK if no error, MARS_ERROR_L2_API_CHECK errors if fails
 * @design        GID-455969
 */
Mars_ReturnType mars_action_config_read_param_check(const mars_instance_t *const mars_self,const mars_tx_config_t *const tx_config,const mars_rx_config_t *const rx_config,const mars_rfdist_mode_t *const rfdist_mode, /* polyspace GUIDELINE:SC07 [No action planned:Medium] "The function takes all the parameters needed for MARS configuration readback to validate them" */ /* polyspace GUIDELINE:SC15 [No action planned:Low] "The Threshold has been exceeded but to keep the function readability" */
                               const mars_bias_noise_filter_t *const bias_noise_filter, const mars_mipi_config_t *const mipi_config,const mars_chirp_config_t *const chrp_config,
                               const mars_chirp_mode_t *const chrp_mode,const mars_gp_config_t *const gp_config,const mars_frame_counter_t *const frame_counter,
                               const mars_mipi_diag_t *const mipi_diag,const mars_fusa_fs_t *const maf_fusa_fs)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    mars_api_check_error_en param_index = MARS_L2_API_CHECK_NO_ERROR;
    if (tx_config == NULL_PTR)
    {
        param_index = MARS_L2_API_CHECK_PARAM_INDEX_1;
    }
    if ((param_index == MARS_L2_API_CHECK_NO_ERROR) && (rx_config == NULL_PTR))
    {
        param_index = MARS_L2_API_CHECK_PARAM_INDEX_2;
    }
    if ((param_index == MARS_L2_API_CHECK_NO_ERROR) && (rfdist_mode == NULL_PTR))
    {
        param_index = MARS_L2_API_CHECK_PARAM_INDEX_3;
    }
    if ((param_index == MARS_L2_API_CHECK_NO_ERROR) && (bias_noise_filter == NULL_PTR))
    {
        param_index = MARS_L2_API_CHECK_PARAM_INDEX_4;
    }
    if ((param_index == MARS_L2_API_CHECK_NO_ERROR) && (mipi_config == NULL_PTR))
    {
        param_index = MARS_L2_API_CHECK_PARAM_INDEX_5;
    }
    if ((param_index == MARS_L2_API_CHECK_NO_ERROR) && (chrp_config == NULL_PTR))
    {
        param_index = MARS_L2_API_CHECK_PARAM_INDEX_6;
    }
    if ((param_index == MARS_L2_API_CHECK_NO_ERROR) && (chrp_mode == NULL_PTR))
    {
        param_index = MARS_L2_API_CHECK_PARAM_INDEX_7;
    }
    if ((param_index == MARS_L2_API_CHECK_NO_ERROR) && (gp_config == NULL_PTR))
    {
        param_index = MARS_L2_API_CHECK_PARAM_INDEX_8;
    }
    if ((param_index == MARS_L2_API_CHECK_NO_ERROR) && (frame_counter == NULL_PTR))
    {
        param_index = MARS_L2_API_CHECK_PARAM_INDEX_9;
    }
    if ((param_index == MARS_L2_API_CHECK_NO_ERROR) && (mipi_diag == NULL_PTR))
    {
        param_index = MARS_L2_API_CHECK_PARAM_INDEX_10;
    }
    if ((param_index == MARS_L2_API_CHECK_NO_ERROR) && (maf_fusa_fs == NULL_PTR))
    {
        param_index = MARS_L2_API_CHECK_PARAM_INDEX_11;
    }
    if (MARS_L2_API_CHECK_NO_ERROR != param_index)
    {
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)param_index);
    }
    return ret_val;
}

/**
 * @brief         Check the parameters of mars_configure
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    mars_scp_cfg Scratchpad data structure to be filled
 * @param [in]    tx_config Configuration of TX parameters
 * @param [in]    rx_config configuration of RX parameters
 * @param [in]    rfdist_mode configuration of RF distribution mode (Single, Master, Slave)
 * @param [in]    bias_noise_filter configuration of Bias Noise Filter control
 * @param [in]    mipi_config configuration of MIPI
 * @param [in]    chrp_config configuration of chirp and frame parameters
 * @param [in]    chrp_mode chirp mode configuration
 * @param [in]    mipi_diag array of up to 16 Mars register addresses, their content will be returned in MIPI metadata
 * @param [out]   maf_fusa_fs Fstart used in MAF FUSA functions
 * @return        MARS_E_OK if no error, MARS_ERROR_L2_API_CHECK errors if fails
 * @design        GID-455970
 */
Mars_ReturnType mars_action_config_read_parse_scp_data(const mars_instance_t *const mars_self,const mars_scratchpad_cfg_t *const mars_scp_cfg, mars_tx_config_t *const tx_config, mars_rx_config_t *const rx_config, mars_rfdist_mode_t *const rfdist_mode, /* polyspace GUIDELINE:SC07 [No action planned:Medium] "The API takes all the parameters needed for MARS configuration" */ /* polyspace GUIDELINE:SC12 [No action planned:Low] "The Threshold has been exceeded but to keep the function readability" */ /* polyspace GUIDELINE:SC15 [No action planned:Low] "The Threshold has been exceeded but to keep the function readability" */
                               mars_bias_noise_filter_t *const bias_noise_filter, mars_mipi_config_t *const mipi_config, mars_chirp_config_t *const chrp_config,
                               mars_chirp_mode_t *const chrp_mode, mars_mipi_diag_t *const mipi_diag, mars_fusa_fs_t *const maf_fusa_fs)
{
    /* polyspace-begin RTE:IDP [Not a defect:Medium] "The pointer is checked for NULL before dereferencing in mars_action_config_read_param_check" */
    Mars_ReturnType ret_val = MARS_E_OK;
    const mars_tx_en_mode_t tx_en_mode_array[] = {MARS_TX_EN_NORMAL,MARS_TX_EN_OFFSET_DISABLE};
    const mars_tx_ph_mode_t tx_ph_mode_array[] = {MARS_TX_PH_LUT,MARS_TX_PH_MOD_CHIRP,MARS_TX_PH_MOD_CONT};
    const mars_rx_en_mode_t rx_en_mode_array[] = {MARS_RX_EN_NORMAL,MARS_RX_EN_OFFSET_DISABLE};
    const mars_rx_adc_mode_t rx_adc_mode_array[] = {MARS_RX_ADC_NORMAL,MARS_RX_ADC_TESTPATTERN,MARS_RX_ADC_INJECTION};
    const mars_rx_adc_samp_frq_t rx_adc_samp_frq_array[] = {MARS_RXADC_SAMPLE_960M,MARS_RXADC_SAMPLE_1200M};
    const mars_rx_ifvga_stage_1_t rx_ifvga_stage_1_array[] = {MARS_RX_IFVGA_ST_1_18DB,MARS_RX_IFVGA_ST_1_12DB};
    const mars_rx_hpf_prechg_t rx_hpf_prechg_array[] = {MARS_RXIFVGA_HPF_PRECHARGE_DISABLED, MARS_RXIFVGA_HPF_PRECHARGE_ENABLED, MARS_RXIFVGA_HPF_PRECHARGE_AUTO};
    const mars_rfdist_mode_t rfdist_mode_array[] = {MARS_RFDIST_INTERNAL_LO, MARS_RFDIST_CASCADE_MASTER, MARS_RFDIST_EXTERNAL_LO};
    const mars_mipi_tx_lanes_t mipi_tx_lanes_array[] = {MARS_LANE_1, MARS_LANE_2, MARS_LANE_4};
    const mars_mipi_bitrate_t mipi_data_rate_array[] = {MARS_MIPI_210MBPS, MARS_MIPI_400MBPS, MARS_MIPI_600MBPS, MARS_MIPI_840MBPS, MARS_MIPI_1250MBPS};
    const mars_mipi_metadata_enable_t mipi_metadata_enable_array[] = {MARS_MIPI_METADATA_DISABLED, MARS_MIPI_METADATA_ENABLED};
    const mars_mipi_power_mode_t mipi_power_mode_array[] = {MARS_MIPI_ALWAYS_ON_NON_CONTINUOUS, MARS_MIPI_POWER_SAVING_NON_CONTINUOUS,MARS_MIPI_ALWAYS_ON_CONTINUOUS,MARS_MIPI_POWER_SAVING_CONTINUOUS};
    const mars_bias_noise_filter_t bias_noise_filter_array[] = {BIAS_NOISE_FILTER_OFF, BIAS_NOISE_FILTER_ON};
    const mars_mimo_mode_t mimo_mode_array[] = {MIMO_PLUS_MODE, MIMO_PLUS_PRO_MODE};



    if(mars_scp_cfg->tx_ops.tx_ph_mode > (uint32)MARS_TX_PH_MOD_CONT)
    { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP, (uint32)MARS_L2_SCP_TX_PH_MODE_ERROR);
    }
    
    if((mars_scp_cfg->rx_ops.rx_adc_mode > (uint32)MARS_RX_ADC_INJECTION) && (ret_val == MARS_E_OK)) /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
    { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP, (uint32)MARS_L2_SCP_RX_ADC_MODE_ERROR);
    }

    if((mars_scp_cfg->gains.rx_adc_samp_frq > (uint32)MARS_RXADC_SAMPLE_1200M) && (ret_val == MARS_E_OK)) /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
    { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP, (uint32)MARS_L2_SCP_RX_ADC_SAMP_FRQ_ERROR);
    }

    if((mars_scp_cfg->tx_ops.ifvga_hpf_mode > (uint32)MARS_RXIFVGA_HPF_PRECHARGE_AUTO) && (ret_val == MARS_E_OK)) /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
    { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP, (uint32)MARS_L2_SCP_IFVGA_HPF_MODE_ERROR);
    }
    if((mars_scp_cfg->tx_ops.rfdist_mode > (uint32)MARS_RFDIST_EXTERNAL_LO) && (ret_val == MARS_E_OK)) /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
    { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP, (uint32)MARS_L2_SCP_RFDIST_MODE_ERROR);
    }

    if((mars_scp_cfg->frame_1.mipi_data_lanes > (uint32)MARS_LANE_4) && (ret_val == MARS_E_OK)) /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
    { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP, (uint32)MARS_L2_SCP_MIPI_DATA_LANES_ERROR);
    }
    
    if((mars_scp_cfg->frame_1.mipi_data_rate > (uint32)MARS_MIPI_1250MBPS) && (ret_val == MARS_E_OK)) /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
    { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP, (uint32)MARS_L2_SCP_MIPI_DATA_RATE_ERROR);
    }
    
    if((mars_scp_cfg->gains.meta_mode > (uint32)MARS_MIPI_METADATA_ENABLED) && (ret_val == MARS_E_OK)) /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
    { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the read back value not in valid range" */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP, (uint32)MARS_L2_SCP_METADATA_ENABLE_ERROR);
    }

    if(ret_val == MARS_E_OK) /* polyspace RTE:UNR [Not a defect:Low] "Not always true in case any of the previous check failed" */
    {   
        uint16 tmp;

        /* Transmitter Configuration part of Scratchpad data*/
        tx_config->tx_en_mode =tx_en_mode_array[mars_scp_cfg->rx_ops.tx_en_mode];
        tx_config->tx_power = mars_scp_cfg->gains.tx_power;
        
        tmp = (mars_scp_cfg->tx_ops.tx_off_offset) & MARS_SIGNED_9_BIT_CONVERSION_MASK;
        if ((tmp & MARS_SIGNED_9_BIT_SIGN_MASK) != 0u)
        { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the value is negative" */
            tmp |= MARS_SIGNED_9_BIT_EXTEND_MASK;   /* sign extend */
        }
        tx_config->tx_off_offset = (mars_tx_off_offset_t)tmp;
        
        tx_config->tx_on_offset = mars_scp_cfg->tx_ops.tx_on_offset;
        tx_config->tx_seq_offset = mars_scp_cfg->tx_ops.tx_seq_offset;
        tx_config->tx_ph_mode = tx_ph_mode_array[mars_scp_cfg->tx_ops.tx_ph_mode];


        /* Receiver Configuration part of Scratchpad data*/
        rx_config->rx_en_mode = rx_en_mode_array[mars_scp_cfg->rx_ops.rx_en_mode];
        rx_config->rx_ifvga_gain = mars_scp_cfg->gains.rx_gain_ifvga;
        rx_config->rx_mixer_gain = mars_scp_cfg->gains.rx_gain_mixer;
        rx_config->rx_on_offset = mars_scp_cfg->rx_ops.rx_on_offset;
       
        tmp = (mars_scp_cfg->rx_ops.rx_off_offset) & MARS_SIGNED_9_BIT_CONVERSION_MASK;
        if ((tmp & MARS_SIGNED_9_BIT_SIGN_MASK) != 0u)
        { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the value is negative" */
            tmp |= MARS_SIGNED_9_BIT_EXTEND_MASK;   /* sign extend */
        }
        rx_config->rx_off_offset = (mars_rx_off_offset_t)tmp;

        rx_config->rx_seq_offset = mars_scp_cfg->rx_ops.rx_seq_offset;
        rx_config->rx_ifvga_stage_1 = rx_ifvga_stage_1_array[mars_scp_cfg->rx_ops.rx_ifvga_stage];
        rx_config->rx_hpf_prechg_mode = rx_hpf_prechg_array[mars_scp_cfg->tx_ops.ifvga_hpf_mode]; 
        rx_config->rx_adc_samp_frq = rx_adc_samp_frq_array[mars_scp_cfg->gains.rx_adc_samp_frq]; 
        rx_config->rx_adc_mode = rx_adc_mode_array[mars_scp_cfg->rx_ops.rx_adc_mode];


        /* RF Distribution mode and Synthesizer mode */
        *rfdist_mode = rfdist_mode_array[mars_scp_cfg->tx_ops.rfdist_mode];

        /* Bias Noise Filter configuration */
        *bias_noise_filter = bias_noise_filter_array[mars_scp_cfg->frame_3.bias_noise_filter];

        /* MIPI Configuration part of Scratchpad data*/
        mipi_config->mipi_data_lanes = mipi_tx_lanes_array[mars_scp_cfg->frame_1.mipi_data_lanes];
        mipi_config->mipi_data_rate = mipi_data_rate_array[mars_scp_cfg->frame_1.mipi_data_rate];
        mipi_config->metadata_enable = mipi_metadata_enable_array[mars_scp_cfg->gains.meta_mode];
        mipi_config->power_mode = mipi_power_mode_array[mars_scp_cfg->frame_3.mipi_power_mode];

        /* Chirp Mode part of Scratchpad data*/
        chrp_mode->mimo_mode = mimo_mode_array[mars_scp_cfg->frame_1.prf_mimo];
    
        /* Chirp and Frame Configuration part of Scratchpad data*/
        chrp_config->chirps_per_frame = mars_scp_cfg->frame_1.frm_num_chirp;
        chrp_config->repeatable_chirps_num = mars_scp_cfg->frame_1.frm_repit_chirp;
        chrp_config->t0_start_pointer = ((mars_scp_cfg->frame_2.prf_start_ptr_t0) << 2);
        chrp_config->t0_end_pointer = ((mars_scp_cfg->frame_2.prf_end_ptr_t0) << 2);
        chrp_config->t1_start_pointer = ((mars_scp_cfg->frame_3.prf_start_ptr_t1) << 2);

        /* MIPI diag part of Scratchpad data*/
        for (uint16 diag_idx = 0; diag_idx < MARS_MIPI_DIAG_ARRAY_SIZE; diag_idx++)
        {
            mipi_diag[diag_idx] = mars_scp_cfg->mipi_metadata[diag_idx];
        }

        /* ZHV FUSA start frequency part of Scratchpad data*/    
        *maf_fusa_fs = (mars_fusa_fs_t) mars_scp_cfg->frame_4.safety_chirps_fs;
    }
        

    return ret_val;
    /* polyspace-end RTE:IDP [Not a defect:Medium] "The pointer is checked for NULL before dereferencing in mars_action_config_read_param_check" */
}

/**
 * @brief         Check the parameters of mars_configure
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    mars_scp_cfg Scratchpad data structure to be filled
 * @param [in]    gp_config configuration of GP0 & GP1 pin
 * @return        MARS_E_OK if no error, MARS_ERROR_L2_API_CHECK errors if fails
 * @design        GID-455971  GID-509242
 */
Mars_ReturnType mars_action_config_read_gp_registers( mars_instance_t *const mars_self, mars_gp_config_t *const gp_config)
{
    /* polyspace-begin RTE:IDP [Not a defect:Medium] "The pointer is checked for NULL before dereferencing in mars_action_config_read_param_check" */
    Mars_ReturnType ret_val = MARS_E_OK;
    uint32 frm_gp_set=0, frm_gp_select=0;

    const mars_gp_t mars_gp_array[] = {
    GP_PMU_Ready, GP_Frame_PowerUp, GP_Frame_Start, GP_Frame_Safety, GP_Frame_PowerDown, GP_EN_Frame_Start, GP_EN_Chirp_Start,
    GP_EN_Sample_Start, GP_Chirp_Valid, GP_Frame_Sync, GP_Synth_Lock_Signal, GP_MCU_Radar_Ready, GP_Critical_Error, GP_GPT, GP_BOR_N,
    GP_REF_PLL_Lock, GP_ADC_PLL_Lock, GP_MIPI_PLL_Lock, GP_MIPI_IRQ, GP_POR_08_N, GP_POR_18_N, GP_CLK_CORE, GP_SET_HI, GP_SET_LO, GP_NO_CHANGE
    };

    /* Read GP0 configuration from Mars registers */    
    ret_val = mars_read_reg_safe(mars_self, (uint32)MARS_F_CORE_BANK_FRM_GP0_SET, &frm_gp_set);
    if(MARS_E_OK == ret_val)
    {
        ret_val = mars_read_reg_safe(mars_self, (uint32)MARS_F_CORE_BANK_FRM_GP0_SELECT, &frm_gp_select);
    }

    if(MARS_E_OK == ret_val)
    {
        /* Parse GP0 configuration */
        if((frm_gp_set & MARS_FRM_GPX_SET_MASK) == MARS_FRM_GPX_SET_SET_TO_ONE) 
        {
            gp_config->gp0 = GP_SET_HI;
        }
        else if((frm_gp_set & MARS_FRM_GPX_SET_MASK) == MARS_FRM_GPX_SET_SET_TO_ZERO)
        {
            gp_config->gp0 = GP_SET_LO;
        }
        else if(((frm_gp_set & MARS_FRM_GPX_SET_MASK) == MARS_FRM_GPX_SET_SELECT_MODE) && (frm_gp_select <= (( sizeof(mars_gp_array) /sizeof(mars_gp_array[0]) ) - 1)))
        {
            gp_config->gp0 = mars_gp_array[frm_gp_select];
        }
        else
        {
            gp_config->gp0 = GP_NO_CHANGE;
        }

        /* Read GP1 configuration from Mars registers */    
        ret_val = mars_read_reg_safe(mars_self, (uint32)MARS_F_CORE_BANK_FRM_GP1_SET, &frm_gp_set);
        if(MARS_E_OK == ret_val)
        {
            ret_val = mars_read_reg_safe(mars_self, (uint32)MARS_F_CORE_BANK_FRM_GP1_SELECT, &frm_gp_select);
        }

        if(MARS_E_OK == ret_val)
        {
            /* Parse GP1 configuration */
            if((frm_gp_set & MARS_FRM_GPX_SET_MASK) == MARS_FRM_GPX_SET_SET_TO_ONE) 
            {
                gp_config->gp1 = GP_SET_HI;
            }
            else if((frm_gp_set & MARS_FRM_GPX_SET_MASK) == MARS_FRM_GPX_SET_SET_TO_ZERO)
            {
                gp_config->gp1 = GP_SET_LO;
            }
            else if(((frm_gp_set & MARS_FRM_GPX_SET_MASK) == MARS_FRM_GPX_SET_SELECT_MODE) && (frm_gp_select <= (( sizeof(mars_gp_array) /sizeof(mars_gp_array[0]) ) - 1)))
            {
                gp_config->gp1 = mars_gp_array[frm_gp_select];
            }
            else
            {
                gp_config->gp1 = GP_NO_CHANGE;
            }
        }
    }
    return ret_val;
    /* polyspace-begin RTE:IDP [Not a defect:Medium] "The pointer is checked for NULL before dereferencing in mars_action_config_read_param_check" */
}

/**
 * @brief         Check the parameters RX & TX of mars_configure
 * @param [in]    tx_config Configuration of TX parameters
 * @param [in]    rx_config configuration of RX parameters
 * @param [in]    param_index parameter index to be updated in case of error
 * @return        MARS_E_OK if no error, MARS_ERROR_L2_API_CHECK errors if fails
 * @design        GID-450214
 */
static void mars_action_mars_configure_param_tx_rx_check(const mars_tx_config_t *const tx_config, const mars_rx_config_t *const rx_config, mars_api_check_error_en *const param_index)
{
    if ((NULL_PTR != tx_config))
    {
        if (!(((uint32)tx_config->tx_en_mode <= 1u) && (tx_config->tx_power >= 20u) && (tx_config->tx_power <= 127u)  && (tx_config->tx_off_offset >= (sint16)(-256)) &&
            (tx_config->tx_off_offset <= (sint16)255u)  && ((uint32)tx_config->tx_ph_mode <= 2u)))
        {
            *param_index = MARS_L2_API_CHECK_PARAM_INDEX_1;
        }
    }

    if ((NULL_PTR != rx_config) && (*param_index == MARS_L2_API_CHECK_NO_ERROR))
    {
        if (!(((uint32)rx_config->rx_en_mode <= 1UL) && (rx_config->rx_ifvga_gain <= 20u) && (rx_config->rx_mixer_gain >= 4u) && (rx_config->rx_mixer_gain <= 30u) &&
            (rx_config->rx_off_offset <= (sint16)511u) && ((uint32)rx_config->rx_adc_mode <= 2UL) && ((uint32)rx_config->rx_adc_samp_frq <= 1UL)
            && ((uint32)rx_config->rx_ifvga_stage_1 <= 1UL)
            && ((uint32)rx_config->rx_hpf_prechg_mode <= 2UL)))
        {
            *param_index = MARS_L2_API_CHECK_PARAM_INDEX_2;
        }
    }
}


/**
 * @brief         Check the mode parameters of mars_configure
 * @param [in]    rfdist_mode configuration of RF distribution mode (Single, Master, Slave)
 * @param [in]    bias_noise_filter configuration of Bias Noise Filter control
 * @param [in]    chrp_mode chirp mode configuration
 * @param [in]    param_index parameter index to be updated in case of error
 * @return        None
 * @design        GID-450144
 */
static void mars_action_mars_configure_param_check_modes( const mars_rfdist_mode_t *const rfdist_mode, const mars_bias_noise_filter_t *const bias_noise_filter, mars_api_check_error_en *const param_index)
{
    
    if ((NULL_PTR != rfdist_mode) && (*param_index == MARS_L2_API_CHECK_NO_ERROR))
    {
        if ((uint32)(*rfdist_mode) > 2u)
        { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the input parameter not with valid value" */
            *param_index = MARS_L2_API_CHECK_PARAM_INDEX_3;
        }
    }

    if ((NULL_PTR != bias_noise_filter) && (*param_index == MARS_L2_API_CHECK_NO_ERROR))
    {
        if ((uint32)(*bias_noise_filter) > 1u)
        { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the input parameter not with valid value" */
            *param_index = MARS_L2_API_CHECK_PARAM_INDEX_4;
        }
    }

}

/**
 * @brief         Check the mode parameters of mars_configure
 * @param [in]    mipi_config configuration of MIPI
 * @param [in]    mipi_diag array of up to 16 Mars register addresses, their content will be returned in MIPI metadata
 * @param [in]    chrp_config configuration of chirp and frame parameters
 * @param [in]    chrp_mode chirp mode configuration
 * @param [in]    param_index parameter index to be updated in case of error
 * @return        None
 * @design        GID-438508 
 */
static void mars_action_mars_configure_param_check_mipi_chrp( const mars_mipi_config_t *const mipi_config, const mars_mipi_diag_t *const mipi_diag, const mars_chirp_config_t *const chrp_config, const mars_chirp_mode_t *const chrp_mode, mars_api_check_error_en *const param_index)
{
    /* Check MIPI configuration parameters */
    if ((NULL_PTR != mipi_config) && (*param_index == MARS_L2_API_CHECK_NO_ERROR))
    {
        if (!(((uint32)mipi_config->mipi_data_lanes <= 2uL) && ((uint32)mipi_config->mipi_data_rate <= 4uL) && ((uint32)mipi_config->power_mode <= 3uL)))
        { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the input parameter not with valid value" */
            *param_index = MARS_L2_API_CHECK_PARAM_INDEX_5;
        }
    }

    /* Check Chirp and Frame configuration parameters */
    if ((NULL_PTR != chrp_config) && (*param_index == MARS_L2_API_CHECK_NO_ERROR))
    {
        if (!((chrp_config->chirps_per_frame >= 1u) && (chrp_config->chirps_per_frame <= 4095u) && (chrp_config->repeatable_chirps_num <= 15u) && (chrp_config->t0_start_pointer <= 0x83FFu) &&
            (chrp_config->t0_end_pointer <= 0x83FFu) && (chrp_config->t1_start_pointer <= 0x83FFu)))
        {
            *param_index = MARS_L2_API_CHECK_PARAM_INDEX_6;
        }
    }
    /* Check MIPI diag register addresses */
    if ((NULL_PTR != mipi_diag) && (*param_index == MARS_L2_API_CHECK_NO_ERROR))
    {
        uint32 diag_iter = 0;
        while ((mipi_diag[diag_iter] != 0uL) && (diag_iter < 16uL))
        {
            if (mars_l1_check_blacklisted_address(mipi_diag[diag_iter]) != MARS_E_OK)
            {
                *param_index = MARS_L2_API_CHECK_PARAM_INDEX_10;
                break;
            }
            diag_iter++;
        }
    }
    
    if ((NULL_PTR != chrp_mode) && (*param_index == MARS_L2_API_CHECK_NO_ERROR))
    {
        if (!(((uint32)chrp_mode->mimo_mode >= 1UL) && ((uint32)chrp_mode->mimo_mode <= 2UL)))
        { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the input parameter not with valid value" */
            *param_index = MARS_L2_API_CHECK_PARAM_INDEX_7;
        }
    }
}
    
/**
 * @brief         Configure the Scratchpad data based on mars_configure parameters
 * @param [in]    mars_scp_cfg Scratchpad data structure to be filled
 * @param [in]    tx_config Configuration of TX parameters
 * @param [in]    rx_config configuration of RX parameters
 * @param [in]    rfdist_mode configuration of RF distribution mode (Single, Master, Slave)
 * @param [in]    bias_noise_filter configuration of Bias Noise Filter control
 * @param [in]    mipi_config configuration of MIPI
 * @param [in]    chrp_config configuration of chirp and frame parameters
 * @param [in]    chrp_mode chirp mode configuration
 * @param [in]    mipi_diag array of up to 16 Mars register addresses, their content will be returned in MIPI metadata
 * @param [in]    maf_fusa_fs fusa fs configuration
 * @return        None
 * @design        GID-438540
 */
void mars_action_configure_scp(mars_scratchpad_cfg_t *const mars_scp_cfg, const mars_tx_config_t *const tx_config, const mars_rx_config_t *const rx_config, const mars_rfdist_mode_t *const rfdist_mode, /* polyspace GUIDELINE:SC07 [No action planned:Medium] "The function takes all the parameters needed for configuration for MARS to prepare the data structure" */
                               const mars_bias_noise_filter_t *const bias_noise_filter, const mars_mipi_config_t *const mipi_config, const mars_chirp_config_t *const chrp_config,
                               const mars_chirp_mode_t *const chrp_mode, const mars_mipi_diag_t *const mipi_diag, const mars_fusa_fs_t *const maf_fusa_fs)
{
    if(NULL_PTR != mars_scp_cfg) /* polyspace RTE:UNR [No action Planned:Low] "Null pointer check for unit level testability" */
    {
        mars_action_mars_configure_tx_rx(tx_config, rx_config, mars_scp_cfg);

        mars_action_mars_configure_modes(rfdist_mode, bias_noise_filter, mars_scp_cfg);

        mars_action_mars_configure_mipi_chrp(mipi_config, mipi_diag, chrp_config, chrp_mode, mars_scp_cfg);


        /*Update ZHV FUSA start frequency part of Scratchpad data*/
        if (NULL_PTR != maf_fusa_fs)
        {
            mars_scp_cfg->frame_4.safety_chirps_fs = ((*maf_fusa_fs) & 0xFFFFFFu); /* fusa fs is 24 bit value in SCP */
            mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_SAFETY_CHIRPS_FS_VALID);
        }
    }

}

/**
 * @brief         mars_configure modes parameters update in Scratchpad data
 * @param [in]    rfdist_mode configuration of RF distribution mode (Single, Master, Slave)
 * @param [in]    synth_mode configuration of synthesizer mode CW or FMCW
 * @param [in]    chrp_mode chirp mode configuration
 * @param [in]    mars_scp_cfg Scratchpad data structure to be filled
 * @return        None
 * @design        GID-438543
 */
static void mars_action_mars_configure_modes( const mars_rfdist_mode_t *const rfdist_mode, const mars_bias_noise_filter_t *const bias_noise_filter_ctrl, mars_scratchpad_cfg_t *const mars_scp_cfg)
{

    /*Update RF Distribution Mode part of Scratchpad data*/
    if (NULL_PTR != rfdist_mode)
    {
        mars_scp_cfg->tx_ops.rfdist_mode = (uint8)(*rfdist_mode);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_RFDIST_MODE_VALID);
    }

    if (NULL_PTR != bias_noise_filter_ctrl)
    {
        mars_scp_cfg->frame_3.bias_noise_filter = (uint8)(*bias_noise_filter_ctrl);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_BIAS_NOISE_FILTER_VALID);
    }

}

/**
 * @brief         Configure the TX & RX parameters in Scratchpad data
 * @param [in]    tx_config Configuration of TX parameters
 * @param [in]    rx_config configuration of RX parameters
 * @param [in]    mars_scp_cfg Scratchpad data structure to be filled
 * @return        None
 * @design        GID-450216
 */
static void mars_action_mars_configure_tx_rx(const mars_tx_config_t *const tx_config, const mars_rx_config_t *const rx_config, mars_scratchpad_cfg_t *const mars_scp_cfg)
{
    /*Update Transmitter Configuration part of Scratchpad data*/
    if (NULL_PTR != tx_config)
    {
        mars_scp_cfg->rx_ops.tx_en_mode = (uint8)(tx_config->tx_en_mode);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_TX_EN_MODE_VALID);

        mars_scp_cfg->gains.tx_power = (tx_config->tx_power);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_TX_POWER_VALID);

        mars_scp_cfg->tx_ops.tx_on_offset = (tx_config->tx_on_offset);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_TX_ON_OFFSET_VALID);

        mars_scp_cfg->tx_ops.tx_off_offset = ((uint16)(tx_config->tx_off_offset)) & MARS_SIGNED_9_BIT_CONVERSION_MASK; /* polyspace RTE:OVFL [Justified:Medium] "The casting required by the design to set the return error value" */
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_TX_OFF_OFFSET_VALID);

        mars_scp_cfg->tx_ops.tx_seq_offset = (tx_config->tx_seq_offset);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_TX_SEQ_OFFSET_VALID);

        mars_scp_cfg->tx_ops.tx_ph_mode = (uint8)(tx_config->tx_ph_mode);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_TX_PH_MODE_VALID);
    }

    /*Update Receiver Configuration part of Scratchpad data*/
    if (NULL_PTR != rx_config)
    {
        mars_scp_cfg->rx_ops.rx_en_mode = (uint8)(rx_config->rx_en_mode);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_RX_EN_MODE_VALID);

        mars_scp_cfg->gains.rx_gain_ifvga = (rx_config->rx_ifvga_gain);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_RX_GAIN_IFVGA_VALID);

        mars_scp_cfg->gains.rx_gain_mixer = (rx_config->rx_mixer_gain);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_RX_GAIN_MIXER_VALID);

        mars_scp_cfg->rx_ops.rx_on_offset = (rx_config->rx_on_offset);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_RX_ON_OFFSET_VALID);

        mars_scp_cfg->rx_ops.rx_off_offset = ((uint16)(rx_config->rx_off_offset)) & MARS_SIGNED_9_BIT_CONVERSION_MASK; /* polyspace RTE:OVFL [Justified:Medium] "The casting required by the design to set the return error value" */
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_RX_OFF_OFFSET_VALID);

        mars_scp_cfg->rx_ops.rx_seq_offset = (rx_config->rx_seq_offset);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_RX_SEQ_OFFSET_VALID);

        mars_scp_cfg->rx_ops.rx_adc_mode = (uint8)(rx_config->rx_adc_mode);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_RX_ADC_MODE_VALID);

        mars_scp_cfg->gains.rx_adc_samp_frq = (uint8)(rx_config->rx_adc_samp_frq);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_RX_ADC_SAMP_FRQ_VALID);

        mars_scp_cfg->rx_ops.rx_ifvga_stage = (uint8)(rx_config->rx_ifvga_stage_1);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_RX_IFVGA_STAGE_1_VALID);

        mars_scp_cfg->tx_ops.ifvga_hpf_mode = (uint8)(rx_config->rx_hpf_prechg_mode);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_IFVGA_HPF_VALID);
    }
}

/**
 * @brief         mars_configure MIPI and Chirp parameters update in Scratchpad data
 * @param [in]    mipi_config configuration of MIPI
 * @param [in]    mipi_diag array of up to 16 Mars register addresses, their content will be returned in MIPI metadata
 * @param [in]    chrp_config configuration of chirp and frame parameters
 * @param [in]    chrp_mode chirp mode configuration
 * @param [in]    mars_scp_cfg Scratchpad data structure to be filled
 * @return        None
 * @design        GID-438542
 */
static void mars_action_mars_configure_mipi_chrp(const mars_mipi_config_t *const mipi_config, const mars_mipi_diag_t *const mipi_diag, const mars_chirp_config_t *const chrp_config, const mars_chirp_mode_t *const chrp_mode, mars_scratchpad_cfg_t *const mars_scp_cfg)
{
    /*Update Chirp Mode part of Scratchpad data*/
    if (NULL_PTR != chrp_mode)
    {
        mars_scp_cfg->frame_1.prf_mimo = (uint8)((chrp_mode->mimo_mode == MIMO_PLUS_PRO_MODE) ? 1u : 0);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_PRF_MIMO_VALID);
    }
   
        /*Update MIPI Config part of Scratchpad data*/
    if (NULL_PTR != mipi_config)
    {
        mars_scp_cfg->frame_1.mipi_data_lanes = (uint8)(mipi_config->mipi_data_lanes);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_MIPI_DATA_LANES_VALID);

        mars_scp_cfg->frame_1.mipi_data_rate = (uint8)(mipi_config->mipi_data_rate);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_MIPI_DATA_RATE_VALID);

        mars_scp_cfg->gains.meta_mode = (mipi_config->metadata_enable == MARS_MIPI_METADATA_ENABLED) ? 1u : 0u;
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_META_MODE_VALID);

        mars_scp_cfg->frame_3.mipi_power_mode = (uint8)(mipi_config->power_mode);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_MIPI_POWER_MODE_VALID);
    }
    /*Update Chirp Config part of Scratchpad data*/
    if (NULL_PTR != chrp_config)
    {
        mars_scp_cfg->frame_1.frm_num_chirp = ((chrp_config->chirps_per_frame) & 0x0FFFu);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_FRM_NUM_CHIRP_VALID);

        mars_scp_cfg->frame_1.frm_repit_chirp = (chrp_config->repeatable_chirps_num);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_FRM_REPIT_CHIRP_VALID);

        mars_scp_cfg->frame_2.prf_start_ptr_t0 = ((chrp_config->t0_start_pointer) >> 2);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_PRF_START_PTR_T0_VALID);

        mars_scp_cfg->frame_2.prf_end_ptr_t0 = ((chrp_config->t0_end_pointer) >> 2);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_PRF_END_PTR_T0_VALID);

        mars_scp_cfg->frame_3.prf_start_ptr_t1 = ((chrp_config->t1_start_pointer) >> 2);
        mars_scp_cfg->valid_1 |= (1uL << MARS_VALID_1_PRF_START_PTR_T1_VALID);
    }
    /*Update MIPI diag part of Scratchpad data*/
    if (NULL_PTR != mipi_diag)
    {
        mars_scp_cfg->valid_2.mipi_metadata_valid = 0;
        for (uint16 diag_idx = 0; diag_idx < MARS_MIPI_DIAG_ARRAY_SIZE; diag_idx++)
        {
            if (mipi_diag[diag_idx] == 0UL)
            {
                break;
            }
            mars_scp_cfg->mipi_metadata[diag_idx] = mipi_diag[diag_idx];

            mars_scp_cfg->valid_2.mipi_metadata_valid |= (uint16)1u << (diag_idx & 0x0Fu);

        }
    }

}


/**
 * @brief         Check data integrity of a diag raw value (counter/sample consistency).
 * @param [in]    register_val_buffer raw register value from diag memory ([31:28] counter reversed, [27:16] sample reversed, [15:12] counter, [11:0] sample)
 * @param [inout] sample_counter the sample freshness counter
 * @param [out]   sample_raw the resulting raw sample value (0 if integrity check fails)
 * @return        MARS_VAL_FRESH if data is valid and updated, MARS_VAL_STALE if valid but not updated, MARS_VAL_BAD if corrupted
 * @design        GID-454800
 */
static mars_diag_health_state_t mars_action_diag_check_data_integrity(const uint32 register_val_buffer,
                                                               uint8 *const sample_counter,
                                                               uint32 *const sample_raw)
{
    mars_diag_health_state_t state = MARS_VAL_BAD;
    const uint8 counter = (uint8)((register_val_buffer >> MARS_DIAG_MEM_COUNTER_OFFSET) & 0x0Fu);
    const uint8 counter_reversed = (uint8)((register_val_buffer >> MARS_DIAG_MEM_COUNTER_REVERSED_OFFSET) & 0x0Fu);
    const uint16 sample = (uint16)((register_val_buffer >> MARS_DIAG_MEM_SAMPLE_OFFSET) & 0xFFFu);
    const uint16 sample_reversed = (uint16)((register_val_buffer >> MARS_DIAG_MEM_SAMPLE_REVERSED_OFFSET) & 0xFFFu);

    /* Check the consistency of the data read */
    if ((counter_reversed == ((counter ^ 0xFFu) & 0x0Fu)) && (sample_reversed == ((sample ^ 0xFFFFu) & 0xFFFu)))
    {
        /* Check the update status */
        if (*sample_counter == counter)
        {
            /* data is not updated by the Mars */
            state = MARS_VAL_STALE;
        }
        else
        {
            /* data is updated by the Mars */
            state = MARS_VAL_FRESH;
            *sample_counter = counter;
        }

        *sample_raw = sample;
    }
    else
    {
        /* data is corrupted */
        state = MARS_VAL_BAD;
        *sample_raw = 0u;
        *sample_counter = 0x0Fu;
    }

    return state;
}




/**
 * @brief         Read a contiguous chunk of diagnostic memory words and apply data integrity check to each.
 * @brief         Performs a single multi-word mars_read_mem_safe call to minimize SPI + CRC overhead.
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    mem_start_addr start address of the first word in the chunk
 * @param [in]    chunk_count number of words to read, must be <= MARS_DIAG_READ_CHUNK_SIZE
 * @param [out]   sample_states array of health states, one per word
 * @param [out]   sample_raws array of raw sample values, one per word
 * @param [inout] sample_counters array of freshness counters, one per word
 * @return        MARS_E_OK if the memory read succeeded, SPI/CRC error otherwise
 * @design        GID-454801
 */
Mars_ReturnType mars_action_read_diag_raw_chunk( mars_instance_t *const mars_self,
                                                       const uint32 mem_start_addr,
                                                       const uint32 chunk_count,
                                                       mars_diag_health_state_t *const sample_states,
                                                       uint32 *const sample_raws,
                                                       uint8 *const sample_counters)
{
    uint32 chunk_buffer[MARS_DIAG_READ_CHUNK_SIZE] = {0};

    /* Single SPI transfer + CRC check for the entire chunk */
    const Mars_ReturnType ret_val = mars_read_mem_safe(mars_self, mem_start_addr, chunk_buffer, chunk_count);

    if (MARS_E_OK == ret_val)
    {
        for (uint32 chunk_iterator = 0u; chunk_iterator < chunk_count; chunk_iterator++)
        {
            sample_states[chunk_iterator] = mars_action_diag_check_data_integrity(chunk_buffer[chunk_iterator], &sample_counters[chunk_iterator], &sample_raws[chunk_iterator]);
        }
    }

    return ret_val;
}


/**
 * @brief         Process SCP Cal mailbox response
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    mars_scp_resp SCP response byte
 * @param [in]    mars_scp_resp_var_h SCP response variable high
 * @param [in]    mars_scp_resp_var_l SCP response variable low (unused)
 * @return        MARS_E_OK if successful, specific error code if failed
 * @design        GID-350985
 */
Mars_ReturnType mars_action_scp_cal_set_mlbx_response(const mars_instance_t *const mars_self, const uint8 mars_scp_resp, const uint16 mars_scp_resp_var_h, const uint32 mars_scp_resp_var_l)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    (void)mars_scp_resp_var_l;

    /*  MLBX RESPONSE:
     *  [bit 0] : 0 Failed / 1 Passed
     *  [bit 1] : 0 CRC check passed / 1 CRC check failed
     *  [bit 3] : 0 no State Alignment Error / 1 State alignment error in respH

     *  MLBX VAR H:
     *  [bit 0] : BIAS parameters misalignment
     *  [bit 1] : Rx parameters misalignment
     *  [bit 2] : Rx channels misalignment
     *  [bit 3] : Tx parameters misalignment
     *  [bit 4] : Tx channels misalignment
     *

     *  MLBX VAR L:
     *  not used
     */

    if (1u == MARS_GET_BIT_VALUE(mars_scp_resp, MARS_MLBX_STATUS_BIT))
    {
        /* MLBX Response Bit 0 - Passed */
        ret_val = MARS_E_OK;
    }
    else if (1u == MARS_GET_BIT_VALUE(mars_scp_resp, 1u))
    {
        /* MLBX Response Bit 1 - CRC failed */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP, (uint32)MARS_L2_SCP_CRC_INCORRECT_ERROR);
    }
    else if (1u == MARS_GET_BIT_VALUE(mars_scp_resp, 3u))
    {
        /* MLBX Response Bit 2 - State error */

        /* Read the validity bits that marks the param error - 96 valid bit fields */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP_CAL_STATE, ((uint32)mars_scp_resp_var_h & 0x1Fu));
    }
    else
    {
        /* Error was indicated but the value could not be identified */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_SCP, (uint32)MARS_L2_SCP_UNKNOWN_ERROR);
    }

    return ret_val;
}

/**
 * @brief         Process UpdateDiag mailbox response
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    mars_scp_resp SCP response byte
 * @param [in]    mars_scp_resp_var_h SCP response variable high (unused)
 * @param [in]    mars_scp_resp_var_l SCP response variable low (unused)
 * @return        MARS_E_OK if successful, specific MARS_ERROR_L2_UPDATE_DIAG error code if failed
 * @design        GID-350987
 */
Mars_ReturnType mars_action_update_diag_set_mlbx_response(const mars_instance_t *const mars_self, const uint8 mars_scp_resp, const uint16 mars_scp_resp_var_h, const uint32 mars_scp_resp_var_l)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    const mars_update_diag_error_en update_diag_failed = MARS_L2_UPDATE_DIAG_FAILED;
    const mars_update_diag_error_en update_diag_prohibited = MARS_L2_UPDATE_DIAG_PROHIBITED;

    (void)mars_scp_resp_var_l;
    (void)mars_scp_resp_var_h;

    /*  MLBX RESPONSE:
     *  [bit 0] : 0 Failed / 1 Passed
     *  [bit 1] : 0 No Error / 1 Command Prohibited

     *  MLBX VAR H:
     *  not used

     *  MLBX VAR L:
     *  not used
     */

    if (1u == MARS_GET_BIT_VALUE(mars_scp_resp, MARS_MLBX_STATUS_BIT))
    {
        /* MLBX Response Bit 0 - Passed */
        ret_val = MARS_E_OK;
    }
    else if (1u == MARS_GET_BIT_VALUE(mars_scp_resp, 1u))
    {
        /* Update command reported as prohibited, frame already running */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_UPDATE_DIAG, (uint32)update_diag_prohibited);
    }
    else
    {
        /* Update command reported as failed */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_UPDATE_DIAG, (uint32)update_diag_failed);
    }

    return ret_val;
}

/**
 * @brief         Controls continuous wave transmission
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    var_h mailbox variable H
 * @param [in]    var_l mailbox variable L
 * @return        MARS_E_OK if successful, or error code if failed
 * @design        GID-361158
 */
Mars_ReturnType mars_action_control_cw(mars_instance_t *const mars_self, const uint32 var_h, const uint32 var_l)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    mars_mailbox_req_t mlbx_request = {0};
    mars_mailbox_resp_t mlbx_response = {0};

    mlbx_request.slot = MARS_MLBX_SLOT_GEN_CMD;
    mlbx_request.command = MARS_MLBX_CMD_ML_PURE_CW_CTRL;
    mlbx_request.var_h = var_h;
    mlbx_request.var_l = var_l;

    /* Send mailbox request and wait for the response */
    ret_val = mars_exchange_mlbx(mars_self, &mlbx_request, &mlbx_response, MARS_MLBX_TIMEOUT_US);
    if (ret_val == MARS_E_OK)
    {
        /*  MLBX RESPONSE:
         *  [bit 0] : 0 Failed / 1 Passed
         *  [bit 1] : 0 Error Condition Met / 1 Error Condition not Met (other TX is ongoing)
         *  [bit 2] : 0 No Param Error / 1 Param Error (FS out of range)
         *  [bit 4] : 0 No Parity check error / 1 Parity check error (from mailbox command) */

        /*  MLBX VAR H:
         *  not used */

        /*  MLBX VAR L:
         *  not used */

        if (1u == MARS_GET_BIT_VALUE(mlbx_response.response, MARS_MLBX_STATUS_BIT))
        {
            /* MLBX Response Bit 0 - Passed */
            MARS_DATA_PCW_ERROR = MARS_L2_PCW_NO_ERROR;
        }
        else if (1u == MARS_GET_BIT_VALUE(mlbx_response.response, 1u))
        {
            /* MLBX Response Bit 1 - Error Condition not Met (other TX is ongoing */
            MARS_DATA_PCW_ERROR = MARS_L2_PCW_CONDITION_NOT_MET_ERROR;
        }
        else if (1u == MARS_GET_BIT_VALUE(mlbx_response.response, 2u))
        {
            /* MLBX Response Bit 2 - Param error */
            MARS_DATA_PCW_ERROR = MARS_L2_PCW_PARAMETER_ERROR;
        }
        else
        {
            /* MLBX Response No bits set */
            MARS_DATA_PCW_ERROR = MARS_L2_PCW_UNKNOWN_ERROR;
        }
        if (MARS_L2_PCW_NO_ERROR != MARS_DATA_PCW_ERROR)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_PCW, (uint32)MARS_DATA_PCW_ERROR);
        }
    }

    return ret_val;
}

/** 
 * @brief         Reads MAF version from Mars FW metadata
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   maf_version pointer to MAF version information
 * @return        MARS_E_OK if successful, error code if failed
 * @design        GID-366711
 */
Mars_ReturnType mars_action_read_maf_version( mars_instance_t *const mars_self, uint32* const maf_version)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    uint32 firmware_version = 0;
    ret_val = mars_read_mem_safe(mars_self, MARS_FW_VERSION_START_ADDR, &firmware_version, 1u);
    if (ret_val == MARS_E_OK)
    {
        *maf_version = firmware_version;
    }
    return ret_val;
}


/**
 * @brief         Checks Mars Busy status
 * @param [inout] mars_self pointer to driver instance structure
 * @param [in]    timeout timeout in microseconds until the function waits for the response to arrive
 * @return        MARS_E_OK if Not Busy, error code if it is busy 
 * @design        GID-410048 GID-470824 GID-467314
 */
Mars_ReturnType mars_action_check_maf_state(mars_instance_t *const mars_self, const uint32 timeout)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    mars_mailbox_resp_t mlbx_response = {0};

    mlbx_response.slot = MARS_MLBX_SLOT_STATUS_RESPONSE;
    ret_val = mars_read_mlbx(mars_self, &mlbx_response, timeout);

   /*  MLBX RESPONSE:
    *  [bit 0] : 0 Failed / 1 Passed

     *  MLBX VAR H:
     *  0xFFFF - MAF is IDLE

     *  MLBX VAR L:
     *  [bit 0] : FMCW Frame not done / 1 FMCW Frame done
     */


      /* Verify that FMCW Frame is successfully finished */
    if(MARS_E_OK == ret_val)
    {
        if ((mlbx_response.var_h == 0xFFFFu) && (1u == MARS_GET_BIT_VALUE(mlbx_response.response, MARS_MLBX_STATUS_BIT)) &&
           (MARS_GET_BIT_VALUE(mlbx_response.var_l,MARS_MLBX_VAR_L_BIT_FMCW_FRAME_DONE) == 0u ))
        {
            MARS_DATA_DRIVER_STATUS = MARS_INIT_IDLE_OPERATIONAL;
        }
        else
        {
            /* Mailbox read a valid message but it is not was what we expected. We keep reporting BUSY. */
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_MAF_STATE_BUSY_ERROR);
        }
    }
    if ((ret_val & MARS_L1_ERR_MASK) == (MARS_ERROR_L1_MLBX | MARS_L1_E_MLBX_TIMEOUT_ERROR))
    {
        /* Mailbox read did not catch anything meaning that MAF is still busy.
         * This is not an error but one of the expected states, hence indicated accordingly */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_MAF_STATE_BUSY_ERROR);
    }
    /* other low level errors are valid errors and shall be reported upwards */
    return ret_val;
}

/* @brief         Writes Phase Look Up Table to Mars. The function writes only a specific table index (512 entries).
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    lut_values array of 14 bit LUT values (7 bit I x 7 bit Q)
 * @return        MARS_E_OK if successful, error code if failed
 * @design        GID-413023
 */
Mars_ReturnType mars_action_phase_lut_write_raw( mars_instance_t *const mars_self, const uint16 lut_values[MARS_PHASE_LUT_NO_OF_ELEMENTS])
{
    Mars_ReturnType ret_val = MARS_E_OK;

    uint32 mars_phase_lut_buffer[MARS_PHASE_LUT_TRANSFER_CHUNK_SIZE] = {0};


        uint32 parity1 = 0;
        uint32 parity0 = 0;
        uint32 lut_entry_value = 0;
        uint16 copy_index = 0;
        uint32 chunk_number = 0;

    while (copy_index < MARS_PHASE_LUT_NO_OF_ELEMENTS)
    {
        /* calculate an individual LUT entry value */
        lut_entry_value = (uint32)lut_values[copy_index] & 0x3FFFu;

        parity0 = mars_calculate_lut_parity(lut_entry_value & 0xFFu) << MARS_14_BITS;
        parity1 = mars_calculate_lut_parity(lut_entry_value & 0x3F00u) << MARS_15_BITS;

        lut_entry_value |= (((uint32)copy_index) << MARS_16_BITS);
        lut_entry_value |= parity0;
        lut_entry_value |= parity1;

        /* place the calculated LUT entry value in the temporary buffer */
        mars_phase_lut_buffer[copy_index % MARS_PHASE_LUT_TRANSFER_CHUNK_SIZE] = lut_entry_value;
        copy_index++;

        /* when the temp buffer is full write it to Mars Phase LUT */
        if (0 == (copy_index % MARS_PHASE_LUT_TRANSFER_CHUNK_SIZE))
        {
            uint32 dst_addr = MARS_PHASE_TX_LUT_START_ADDR;
            dst_addr +=  ((chunk_number * MARS_PHASE_LUT_TRANSFER_CHUNK_SIZE) * (uint32) sizeof(uint32)); /* polyspace RTE:OVFL [Not a defect:Medium] "The operation limited to range[0, MARS_PHASE_LUT_NO_OF_ELEMENTS] inside loop" */
            
            ret_val = mars_l1_write_mem_raw(mars_self, mars_phase_lut_buffer, dst_addr, MARS_PHASE_LUT_TRANSFER_CHUNK_SIZE,MARS_L1_SAFE_CHK_MLBX);
            
            chunk_number++; /* polyspace RTE:OVFL [Not a defect:Medium] "The operation limited to range[0, MARS_PHASE_LUT_NO_OF_ELEMENTS] inside loop" */

            if (MARS_E_OK != ret_val)
            {
                break;
            }
        }
    }
    

    return ret_val;
}

/**
 * @brief         Writes Phase Look Up Table to Mars. The function writes only a specific table index (512 entries).
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   lut_values array of 14 bit LUT values (7 bit I x 7 bit Q)
 * @return        MARS_E_OK if successful, error code if failed
 * @design        GID-413042
 */
Mars_ReturnType mars_action_phase_lut_read_raw( mars_instance_t *const mars_self, uint16 lut_values[MARS_PHASE_LUT_NO_OF_ELEMENTS])
{
    Mars_ReturnType ret_val = MARS_E_OK;

    /* allocate a smaller temporary buffer for on-the-fly data transformation */
    uint32 mars_phase_lut_buffer[MARS_PHASE_LUT_TRANSFER_CHUNK_SIZE] = {0};


    uint32 copy_index = 0;
    for (copy_index = 0; copy_index < MARS_PHASE_LUT_NO_OF_ELEMENTS; copy_index++)
    {
        /* copy MARS LUT in the temp buffer in chunks */
        if (0 == (copy_index % MARS_PHASE_LUT_TRANSFER_CHUNK_SIZE))
        {
            uint32 src_addr = MARS_PHASE_TX_LUT_START_ADDR;
            src_addr += (uint32)(copy_index * sizeof(uint32));

            ret_val = mars_read_mem_safe(mars_self, src_addr, mars_phase_lut_buffer, MARS_PHASE_LUT_TRANSFER_CHUNK_SIZE);

            if (MARS_E_OK != ret_val)
            {
                break;
            }
        }

        /* copy the transformed value from temp buffer to destination buffer */
        lut_values[copy_index] = (uint16)(mars_phase_lut_buffer[copy_index % MARS_PHASE_LUT_TRANSFER_CHUNK_SIZE] & 0x3FFFuL);
    }
    

    return ret_val;
}

/**
 * @brief         Process Clear Safety Errors mailbox response
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    mars_resp mailbox response byte
 * @param [in]    mars_resp_var_h mailbox response variable high (unused)
 * @param [in]    mars_resp_var_l mailbox response variable low (unused)
 * @return        MARS_E_OK if successful, specific MARS_ERROR_L2_CLEAR_SFT_ERR error code if failed
 * @design        GID-413911
 */
Mars_ReturnType mars_action_clear_sft_err_set_mlbx_response(const mars_instance_t *const mars_self, const uint8 mars_resp, const uint16 mars_resp_var_h, const uint32 mars_resp_var_l)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    const mars_clear_sft_error_en clear_sft_err_failed = MARS_L2_CLEAR_SFT_ERR_FAILED;

    (void)mars_resp_var_h;
    (void)mars_resp_var_l;

    /*  MLBX RESPONSE:
     *  [bit 0] : 0 Failed / 1 Passed

     *  MLBX VAR H:
     *  not used

     *  MLBX VAR L:
     *  not used
     */

    if (1u == MARS_GET_BIT_VALUE(mars_resp, MARS_MLBX_STATUS_BIT))
    {
        /* MLBX Response Bit 0 - Passed */
        ret_val = MARS_E_OK;
    }
    else
    {
        /* Mailbox command reported as failed */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_CLEAR_SFT_ERR, (uint32)clear_sft_err_failed);
    }

    return ret_val;
}


/**
 * @brief         checks if the provided memory range is valid
 * @param [in]    address start address of the memory range
 * @param [in]    size size of the memory range in word bytes
 * @return        MARS_E_OK if successful, MARS_E_NOT_OK if failed
 * @design        GID-421886
 */
Mars_ReturnType mars_action_check_memory_range(const uint32 address, const uint32 size)
{
    Mars_ReturnType ret_val = MARS_E_NOT_OK;
    
    const uint32 end_address = address + size - 1u;

    for (uint32 i = 0; i < (sizeof(MARS_MEMORY_MAP) / sizeof(MARS_MEMORY_MAP[0])); i++)
    {
        if ((address >= MARS_MEMORY_MAP[i].start_address) && (end_address <= MARS_MEMORY_MAP[i].end_address))
        {
            /* Address is within the valid memory range */
            ret_val = MARS_E_OK;
            break;
        }
    }
   
    return ret_val;
}
/**
 * @brief         Send SFT pin test to Mars
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    mars_sft_set_en assert/deassert state enum
 * @return        MARS_E_OK if successful asserted/deasserted
 * @design        GID-422966
 */
Mars_ReturnType mars_action_send_sft_pin_test_command( mars_instance_t *const mars_self, const mars_sft_set_en state)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    const mars_test_sft_pin_error_en test_sft_pin_test_cmd_failed = MARS_L2_TEST_SFT_PIN_TEST_CMD_FAILED;

    mars_mailbox_req_t mlbx_request = {0};
    mars_mailbox_resp_t mlbx_response = {0};

 
        mlbx_request.slot = MARS_MLBX_SLOT_GEN_CMD;
        mlbx_request.command = MARS_MLBX_CMD_SFT_PIN_TEST;

        if(state == MARS_SFT_ASSERT)
        {
            mlbx_request.var_h = MARS_SFT_PIN_TEST_START;
        }
        else 
        {
            mlbx_request.var_h = MARS_SFT_PIN_TEST_STOP;
        }

        ret_val = mars_exchange_mlbx(mars_self, &mlbx_request, &mlbx_response, MARS_MLBX_TIMEOUT_US);
        /*  MLBX RESPONSE:
         *  [bit 0] : 0 Failed / 1 Passed
         *  [bit 4] : 0 No Parity check error / 1 Parity check error (from mailbox command)
         *  MLBX VAR H:
         *  not used
         *
         *  MLBX VAR L:
         *  not used
         */
        if(MARS_E_OK == ret_val)
        {
            
            if (1u != MARS_GET_BIT_VALUE(mlbx_response.response, MARS_MLBX_STATUS_BIT))
            {
                /* Mailbox command reported as failed */
                mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_TEST_SFT_PIN,(uint32) test_sft_pin_test_cmd_failed);

            }
        }
    return ret_val;
}

/**
 * @brief         Check SFT pin test status
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    mars_sft_set_en assert/deassert state enum
 * @return        MARS_E_OK if successful asserted/deasserted
 * @design        GID-423843
 */
Mars_ReturnType mars_action_check_sft_pin_status(mars_instance_t *const mars_self, const mars_sft_set_en state)
{
    const mars_test_sft_pin_error_en test_sft_pin_cannot_assert = MARS_L2_TEST_SFT_PIN_CANNOT_ASSERT;
    const mars_test_sft_pin_error_en test_sft_pin_cannot_deassert = MARS_L2_TEST_SFT_PIN_CANNOT_DEASSERT;

    Mars_ReturnType ret_val = MARS_E_OK;
    mars_gpio_level_en sft_err_chn_val = L0_IO_HI;
    ret_val = mars_gpio_sft_read(mars_self, &sft_err_chn_val);
    if((state == MARS_SFT_ASSERT) && (MARS_E_OK == ret_val))
    {
        if (L0_IO_LO != sft_err_chn_val)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_TEST_SFT_PIN,(uint32) test_sft_pin_cannot_assert);
        }            
    }
    if((state == MARS_SFT_DEASSERT) && (MARS_E_OK == ret_val))
    {
        if (L0_IO_HI != sft_err_chn_val)
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_TEST_SFT_PIN,(uint32) test_sft_pin_cannot_deassert);
        }            
    }

    return ret_val;
}

/**
 * @brief         Wait until frame done
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    timeout maximum time to wait for MAF to report frame done, in milliseconds.
  * @return        MARS_E_OK if successful asserted/deasserted
 * @design        GID-429437
 */
Mars_ReturnType mars_action_wait_frame_ready(mars_instance_t *const mars_self, const uint32 timeout)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    const mars_wait_frame_error_en frm_wait_timeout = MARS_L2_FRM_WAIT_TIMEOUT;
    MARS_DATA_DRIVER_STATUS = MARS_BUSY;
    uint32 tmp_to  = 0;
    do
    {
        /* wait for MAF reporting ready. mars_action_check_maf_state uses 1000 us timeout per poll. */
        (void) mars_action_check_maf_state(mars_self, MARS_ZHV_RDY_TIMEOUT_1000_US);
        if (MARS_DATA_DRIVER_STATUS == MARS_INIT_IDLE_OPERATIONAL)
        {
            break;
        }
        tmp_to++;
    }while (tmp_to < timeout);
        /* check if the loop has exited with timeout */
    if (MARS_DATA_DRIVER_STATUS != MARS_INIT_IDLE_OPERATIONAL)
    {
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_FRM_WAIT, (uint32)frm_wait_timeout);
    }
    return ret_val;

}


/**
 * @brief         Reads hardware registers for BIST results
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   results results from BIST
 * @return        MARS_E_OK if successful MARS_E_OK if failed
 * @design        GID-438483 GID-457863
 */
Mars_ReturnType mars_action_read_hw_registers( mars_instance_t *const mars_self, mars_bist_result_t *const results)
{
    const uint32 reg_id[MARS_NUMBER_OF_SFT_ERROR_REGS]=
    {
        MARS_R_CORE_BANK_SFT_ERR_STATUS,
        MARS_F_CORE_BANK_MCU_MSSG,
        MARS_R_CORE_BANK_SFT_STATUS,
        MARS_R_CORE_BANK_FRM_ERR,
        MARS_R_CORE_BANK_ENA_ERR,
        MARS_R_LOGEN_BANK_CHRP_GEN_ERROR,
        MARS_R_LOGEN_BANK_LOGEN_ERROR,
        MARS_R_RXADC_FUSAIRQV,
        MARS_F_RXADC_FUSAIRQV0,
        MARS_F_RXADC_FUSAIRQV1,
        MARS_R_RXADC_FUSAMON,
        MARS_R_RXADC_MOD0_FUSAIRQV,
        MARS_R_RXADC_MOD1_FUSAIRQV,
        MARS_R_RXADC_MOD2_FUSAIRQV,
        MARS_R_RXADC_MOD3_FUSAIRQV,
        MARS_R_ASYNC_BANK_ASYNC_ERR1,
        MARS_R_PROFILER_BANK_PRF_ERR1,
        MARS_R_PROFILER_BANK_PRF_ERR2,  
        MARS_R_CPU_SYS_MCU_ERR_0,
        MARS_R_CPU_SYS_MCU_ERR_1,
        MARS_R_CPU_SYS_MCU_ERR_2,
        MARS_R_CPU_SYS_MCU_ERR_3,
        MARS_F_CPU_SYS_DMA_ERR_STATUS,
        MARS_R_MIPI_BANK_IRQ_STATUS,
        MARS_R_CPLL_BANK_REFPLL_ERROR
    };

    mars_reg_value_t reg_value_tmp[MARS_NUMBER_OF_SFT_ERROR_REGS] = {0};
    
    Mars_ReturnType ret_val = MARS_E_OK;
    /* Get the HW register status */
    
    for(uint32 count = 0 ; count < (uint32)MARS_NUMBER_OF_SFT_ERROR_REGS ; count++)
    {
        ret_val = mars_read_reg_safe(mars_self, reg_id[count], &reg_value_tmp[count]);
        if (ret_val != MARS_E_OK)
        {
           break;
        }
        
    }
    
    if(ret_val == MARS_E_OK)
    {
        results->CORE_BANK_SFT_ERR_STATUS = reg_value_tmp[MARS_R_CORE_BANK_SFT_ERR_STATUS_READ_BIST_INDEX];
        results->CORE_BANK_MCU_STS_MCU_MSSG = reg_value_tmp[MARS_F_CORE_BANK_MCU_MSSG_READ_BIST_INDEX];
        results->CORE_BANK_SFT_STATUS = reg_value_tmp[MARS_R_CORE_BANK_SFT_STATUS_READ_BIST_INDEX];
        results->CORE_BANK_FRM_ERR = reg_value_tmp[MARS_R_CORE_BANK_FRM_ERR_READ_BIST_INDEX];
        results->CORE_BANK_ENA_ERR = reg_value_tmp[MARS_R_CORE_BANK_ENA_ERR_READ_BIST_INDEX];
        results->LOGEN_BANK_CHRP_GEN_ERROR = reg_value_tmp[MARS_R_LOGEN_BANK_CHRP_GEN_ERROR_READ_BIST_INDEX];
        results->LOGEN_BANK_LOGEN_ERROR = reg_value_tmp[MARS_R_LOGEN_BANK_LOGEN_ERROR_READ_BIST_INDEX];
        results->RXADC_FUSAIRQV = reg_value_tmp[MARS_R_RXADC_FUSAIRQV_READ_BIST_INDEX];
        results->RXADC_FUSAIRQV0 = reg_value_tmp[MARS_F_RXADC_FUSAIRQV0_READ_BIST_INDEX];
        results->RXADC_FUSAIRQV1 = reg_value_tmp[MARS_F_RXADC_FUSAIRQV1_READ_BIST_INDEX];
        results->RXADC_FUSAMON = reg_value_tmp[MARS_R_RXADC_FUSAMON_READ_BIST_INDEX];
        results->RX_ADC_MOD0_FUSAIRQV = reg_value_tmp[MARS_R_RXADC_MOD0_FUSAIRQV_READ_BIST_INDEX];
        results->RX_ADC_MOD1_FUSAIRQV = reg_value_tmp[MARS_R_RXADC_MOD1_FUSAIRQV_READ_BIST_INDEX];
        results->RX_ADC_MOD2_FUSAIRQV = reg_value_tmp[MARS_R_RXADC_MOD2_FUSAIRQV_READ_BIST_INDEX];
        results->RX_ADC_MOD3_FUSAIRQV = reg_value_tmp[MARS_R_RXADC_MOD3_FUSAIRQV_READ_BIST_INDEX];
        results->ASYNC_BANK_ASYNC_ERR1 = reg_value_tmp[MARS_R_ASYNC_BANK_ASYNC_ERR1_READ_BIST_INDEX];
        results->PROF_BANK_PRF_ERR1 = reg_value_tmp[MARS_R_PROFILER_BANK_PRF_ERR1_READ_BIST_INDEX];
        results->PROF_BANK_PRF_ERR2 = reg_value_tmp[MARS_R_PROFILER_BANK_PRF_ERR2_READ_BIST_INDEX];
        results->CPU_SYS_MCU_ERR_0 = reg_value_tmp[MARS_R_CPU_SYS_MCU_ERR_0_READ_BIST_INDEX];
        results->CPU_SYS_MCU_ERR_1 = reg_value_tmp[MARS_R_CPU_SYS_MCU_ERR_1_READ_BIST_INDEX];
        results->CPU_SYS_MCU_ERR_2 = reg_value_tmp[MARS_R_CPU_SYS_MCU_ERR_2_READ_BIST_INDEX];
        results->CPU_SYS_MCU_ERR_3 = reg_value_tmp[MARS_R_CPU_SYS_MCU_ERR_3_READ_BIST_INDEX];
        results->CPU_SYS_DMA_ERR = reg_value_tmp[MARS_F_CPU_SYS_DMA_ERR_STATUS_READ_BIST_INDEX];
        results->MIPI_BANK_IRQ_STATUS = reg_value_tmp[MARS_R_MIPI_BANK_IRQ_STATUS_READ_BIST_INDEX];
        results->CPLL_BANK_REFPLL_ERR = reg_value_tmp[MARS_R_CPLL_BANK_REFPLL_ERROR_READ_BIST_INDEX];
    }
    return ret_val;

}

/**
 * @brief         Reads diagnostic memory for BIST results
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   results results from BIST
 * @return        MARS_E_OK if successful MARS_E_OK if failed
 * @design        GID-438486 GID-457864
 */
Mars_ReturnType mars_action_read_diagnostic_memory( mars_instance_t *const mars_self, mars_bist_result_t *const results)
{
    /* Read diagnostic memory for MCU errors in chunks to reduce SPI + CRC overhead */
    uint32 diag_idx = 0;
    Mars_ReturnType ret_val = MARS_E_OK;
    const mars_read_bist_error_en read_bist_integrity_check_failed = MARS_L2_READ_BIST_INTEGRITY_CHECK_FAILED;

    while ((diag_idx < MARS_DIAG_VALUES_MAX_NUMBER_MAF_ERROR_STATUS) && (MARS_E_OK == ret_val))
    {
        const uint32 remaining = MARS_DIAG_VALUES_MAX_NUMBER_MAF_ERROR_STATUS - diag_idx;
        const uint32 chunk_count = (remaining < MARS_DIAG_READ_CHUNK_SIZE) ? remaining : MARS_DIAG_READ_CHUNK_SIZE;
        const uint32 mem_addr = MARS_DIAG_VALUES_MAF_ERROR_STATUS_START_ADDR + (diag_idx * sizeof(uint32));
        mars_diag_health_state_t sample_states[MARS_DIAG_READ_CHUNK_SIZE] = {0};
        uint32 sample_raws[MARS_DIAG_READ_CHUNK_SIZE] = {0};
        uint8 sample_counters[MARS_DIAG_READ_CHUNK_SIZE] = {0};
        uint32 chunk_iterator;

        for (chunk_iterator = 0u; chunk_iterator < chunk_count; chunk_iterator++)
        {
            sample_states[chunk_iterator] = MARS_VAL_BAD;
            sample_raws[chunk_iterator] = 0u;
            sample_counters[chunk_iterator] = 0u;
        }

        ret_val = mars_action_read_diag_raw_chunk(mars_self, mem_addr, chunk_count, sample_states, sample_raws, sample_counters);

        if (MARS_E_OK == ret_val)
        {
            for (chunk_iterator = 0u; chunk_iterator < chunk_count; chunk_iterator++)
            {
                /* sample_states and sample_counters not used, kept for interface compatibility with mars_action_read_diag_raw_chunk */
                (void)sample_states[chunk_iterator];
                (void)sample_counters[chunk_iterator];
                results->mcu_diag_error_values[diag_idx + chunk_iterator] = (uint16)(sample_raws[chunk_iterator] & 0xFFFFu); /* polyspace RTE:OBAI [No action planned:Low] "chunk_count bounds are enforced by the while condition" */
            }
            diag_idx += chunk_count;
        }
        else
        {
            mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_READ_BIST, (uint32)read_bist_integrity_check_failed);
        }
    }
    return ret_val;
}


/**
 * @brief         Check SFT registers for BIST results
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   results results from BIST
 * @return        MARS_E_OK if successful MARS_E_OK if failed
 * @design        GID-438482 GID-457862
 */
Mars_ReturnType mars_action_check_sft_registers( mars_instance_t *const mars_self, mars_bist_result_t *const results)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    mars_reg_value_t register_value = 0;
    const mars_read_bist_error_en read_bist_invalid_sft = MARS_L2_READ_BIST_INVALID_SFT;
    const mars_maf_status_t mars_maf_status_array[] = {
        MARS_MAF_INIT, MARS_MAF_STANDBY, MARS_MAF_FMCW, MARS_MAF_CW, MARS_MAF_SFT_RECOVERABLE, MARS_MAF_SFT_NON_RECOVERABLE
    }; 

    /* Get MAF status */
    ret_val = mars_read_reg_safe(mars_self, MARS_F_CORE_BANK_MCU_MSSG, &register_value);

    if(register_value <= (( sizeof(mars_maf_status_array) /sizeof(mars_maf_status_array[0]) ) - 1))
    {
        results->maf_status = mars_maf_status_array[register_value];
    }

    if(ret_val == MARS_E_OK)
    {
        /* Get the SFT register status */
        ret_val = mars_read_reg_safe(mars_self, MARS_R_CORE_BANK_SFT_ERR, &register_value);
        results->CORE_BANK_SFT_ERR_MON = register_value;
    }


    if (MARS_E_OK == ret_val)
    {
        /* Check if the data is valid */
        for(uint32 index = 0u; index < MARS_MAX_BIT_POS_IN_UINT32; index += 2u)
        {
            const uint8 sft_error = (uint8)((register_value >> index) & 0x03u);

            /* Values 0b00 and 0b11 are invalid as per Mars HW design and specified in GID-365948 */
            if ((0x00u == sft_error) || (0x03u == sft_error))
            {
                mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_READ_BIST, (uint32) read_bist_invalid_sft);
                break;
            }
        }
    }
    return ret_val;
}


/**
 * @brief         Configures GP registers
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   gp_config configuration of GP0 & GP1 pin
 * @return        MARS_E_OK if successful MARS_E_OK if failed
 * @design        GID-438537
 */
Mars_ReturnType mars_action_configure_gp_registers( mars_instance_t *const mars_self, const mars_gp_config_t *const gp_config) /* polyspace GUIDELINE:SC18 [No action planned:Low] "Fixing the language scope will affect the readability of the function" */
{
    Mars_ReturnType ret_val = MARS_E_OK;
    
    
    ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_CORE_BANK_FRM_GP0_LOCK, 0x0u);
    
    if(ret_val == MARS_E_OK)
    {
        if( gp_config->gp0 == GP_SET_HI )
        {
            ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_CORE_BANK_FRM_GP0_SET, 0x1u);                    
        }
        else if( gp_config->gp0 == GP_SET_LO )
        {
            ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_CORE_BANK_FRM_GP0_SET, 0x2u);
        }
        else if(gp_config->gp0 != GP_NO_CHANGE)
        {            
            ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_CORE_BANK_FRM_GP0_SET, 0x0u);
            
            if(ret_val == MARS_E_OK)
            {
                ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_CORE_BANK_FRM_GP0_SELECT, (uint32) gp_config->gp0);
            }
        }
        else
        {
            ;
        }
    }

    if(ret_val == MARS_E_OK)
    {
        ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_CORE_BANK_FRM_GP1_LOCK, 0x0u);
        
        if(ret_val == MARS_E_OK)
        {
            if (gp_config->gp1 == GP_SET_HI)
            {
                ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_CORE_BANK_FRM_GP1_SET, 0x01u);
            }
            else if( gp_config->gp1 == GP_SET_LO)
            {
                ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_CORE_BANK_FRM_GP1_SET, 0x02u);
            }
            else if(gp_config->gp1 != GP_NO_CHANGE)
            {
                ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_CORE_BANK_FRM_GP1_SET, 0x0u);

                if(ret_val == MARS_E_OK)
                {
                    ret_val = mars_write_reg_safe(mars_self, (uint32)MARS_F_CORE_BANK_FRM_GP1_SELECT, (uint32) gp_config->gp1);
                }
            }
            else
            {
                ;
            }
        }
    }
    return ret_val;
}

/**
 * @brief         Activates the uploaded MAF firmware mailbox command
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   activation_type type of activation
 * @return        MARS_E_OK if successful MARS_E_OK if failed
 * @design        GID-438490
 */
Mars_ReturnType mars_action_maf_activate( mars_instance_t *const mars_self, const mars_activation_t activation_type)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    mars_mailbox_req_t mlbx_request = {0};
    mars_mailbox_resp_t mlbx_response = {0};
    uint8 mailbox_cmd = 0u;
    switch (activation_type)
    {
#if defined(MARS_ALLOW_ACTIVATION_NO_CRC)
    case ACTIVATE_NO_CHECK:
        mailbox_cmd = MARS_MLBX_CMD_ML_EXEC_MAF;
        break;
#endif /* MARS_ALLOW_ACTIVATION_NO_CRC */
    case ACTIVATE_CHECK_CRC:
        mailbox_cmd = MARS_MLBX_CMD_ML_EXEC_MAF_CRC;
        break;
    default: /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the input parameter not with valid value" */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_PARAM_INDEX_1);
        break;
    }


    if(((MARS_DATA_BUFFER_MAF_START_ADDR < MARS_FIRMWARE_START_ADDR) || (MARS_DATA_BUFFER_MAF_START_ADDR >= MARS_FIRMWARE_END_ADDR) || 
        (MARS_DATA_BUFFER_MAF_SIZE == 0u) || (MARS_DATA_BUFFER_MAF_SIZE >MARS_FIRMWARE_MAX_SIZE)) && (ret_val == MARS_E_OK))
    {
        /* MAF start address is not set, cannot proceed with activation */
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_MAF, (uint32) MARS_L2_MAF_NOT_UPLOAD_ERROR);
    }
    else
    {
        /* calculate the total size of the MAF that was uploaded */
        const uint32 maf_size = (MARS_DATA_BUFFER_MAF_START_ADDR - MARS_FIRMWARE_START_ADDR) + MARS_DATA_BUFFER_MAF_SIZE;
        mlbx_request.slot = MARS_MLBX_SLOT_GEN_CMD;
        mlbx_request.command = mailbox_cmd;

        /* The MBL of Mars B0 expects the size that is excluding the CRC */
        mlbx_request.var_h = (uint32)(maf_size / sizeof(uint32)) - 1uL; /* polyspace RTE:OVFL [Not a defect:Medium] "The operation applied to DRS" */
        mlbx_request.var_l = 0u;
    }
    if (MARS_E_OK == ret_val)
    {
        /* Send mailbox request and wait for the response */
        ret_val = mars_exchange_mlbx(mars_self, &mlbx_request, &mlbx_response, MARS_MAF_ACTIVATE_TIMEOUT_US);
        mars_action_maf_set_mlbx_response(mars_self, (uint8)mlbx_response.response, (uint16)mlbx_response.var_h, (uint32)mlbx_response.var_l, activation_type);
        if (MARS_E_OK == ret_val)
        {
            if (MARS_L2_MAF_NO_ERROR == MARS_DATA_MAF_ERROR)
            {
                ret_val = MARS_E_OK;
            }
            else
            {
                mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_MAF, (uint32)MARS_DATA_MAF_ERROR);
            }
        }
    }
    return ret_val;
}

/**
 * @brief         Checks the MAF version after activation
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   activation_type type of activation
 * @return        MARS_E_OK if successful MARS_E_OK if failed
 * @design        GID-438491
 */
Mars_ReturnType mars_action_check_maf_version(mars_instance_t *const mars_self)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    
     /* Read the MAF version */
    ret_val = mars_action_read_maf_version(mars_self, &MARS_DATA_FW_VERSION);
    
    if (((MARS_DATA_FW_VERSION & 0xF0000000u) >> MARS_FW_HW_VERSION_OFFSET) != MARS_FW_HW_VERSION)
    {
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_MAF, (uint32)MARS_L2_MAF_VERSION_MISMATCH_ERROR);
    }
    if (MARS_E_OK == ret_val)
    {
        /* MAF Activation successfully, change the Driver State */
        MARS_DATA_DRIVER_STATUS = MARS_INIT_IDLE_OPERATIONAL;
        /* Increase the clock speed, without changing the current mode */
        ret_val = mars_action_ssi_set_speed(mars_self);
    }
    else
    {
        /* MAF Activation failed */
        MARS_DATA_DRIVER_STATUS = MARS_INITIALIZED_FW_NOT_RUNNING;
    }

    return ret_val;
}

/**
 * @brief         Checks parameters for firmware upload
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    firmware_data binary data of the mars application firmware
 * @param [in]    offset offset of the next data chunk
 * @param [in]    length length of the binary data in bytes
 * @param [in]    firmware_data pointer to the firmware data buffer
 * @param [out]   param_index parameter index in case of error
 * @return        MARS_E_OK if successful MARS_E_NOT_OK if failed
 * @design        GID-438492
 */
Mars_ReturnType mars_action_check_upload_firmware_params_check(const mars_instance_t *const mars_self, const uint32 offset, const mars_firmware_size_t length, const mars_firmware_data_t *const firmware_data, mars_api_check_error_en *const param_index)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if( firmware_data == NULL_PTR)
    {
        /* Param Error - data pointer must not be NULL */
        *param_index = MARS_L2_API_CHECK_PARAM_INDEX_1;
        ret_val = MARS_E_NOT_OK;
    }
    else if (((offset % sizeof(mars_firmware_data_t)) != 0) || (offset >= MARS_FIRMWARE_MAX_SIZE))
    {
        /* Param Error - data must be multiple of 4 bytes (mars_firmware_data_t) */
        *param_index = MARS_L2_API_CHECK_PARAM_INDEX_2;
        ret_val = MARS_E_NOT_OK;
    }
    else if (((length % sizeof(mars_firmware_data_t)) != 0) || (length == 0))
    {
        /* Param Error - data must fit into the MAF memory partition and be a multiple of the firmware data type */
        *param_index = MARS_L2_API_CHECK_PARAM_INDEX_3;
        ret_val = MARS_E_NOT_OK;
    }
    else if (((uint32)MARS_FIRMWARE_START_ADDR + offset) < (MARS_DATA_BUFFER_MAF_START_ADDR + MARS_DATA_BUFFER_MAF_SIZE)) /* polyspace RTE:OVFL [Not a defect:Medium] "The operands are initialized with predefined values and validated against predefined ranges" */
    {
        /* Param Error - data must be continuous in the memory */
        *param_index = MARS_L2_API_CHECK_PARAM_INDEX_2;
        ret_val = MARS_E_NOT_OK;
    }
    else if (length > (MARS_FIRMWARE_MAX_SIZE - offset))
    {
        /* Param Error - data must fit into the MAF memory partition (overflow-safe check) */
        *param_index = MARS_L2_API_CHECK_PARAM_INDEX_3;
        ret_val = MARS_E_NOT_OK;
    }
    else
    {
        ret_val = MARS_E_OK;
    }

    return ret_val;
}

/**
 * @brief         Generates ZHV data setup before frame trigger
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful MARS_E_NOT_OK if failed
 * @design        GID-438546
 */
Mars_ReturnType mars_action_zhv_generate_setup(mars_instance_t *const mars_self)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    const mars_trigger_frame_error_en frame_mars_busy = MARS_L2_FRAME_MARS_BUSY;
    mars_scratchpad_cfg_t mars_scp_cfg = {0};

    /* Step 1: Inform MAF that the next Frame trigger shall initiate ZHV generation */
    mars_scp_cfg.frame_3.zhv_generation_mode = MARS_ZHV_GENERATE_NEW_TABLE;
    mars_scp_cfg.valid_1 |= (1uL << MARS_VALID_1_ZHV_GENERATION_MODE_VALID);

    ret_val = mars_action_scp_send_update_command(mars_self, &mars_scp_cfg);
    

    /* Step 2: Check if MARS is READY before triggering a frame */
    if (ret_val == MARS_E_OK)
    {
        mars_reg_value_t radar_ready = 0u;

        ret_val = mars_read_reg_safe(mars_self, MARS_F_CORE_BANK_MCU_RDR_READY, &radar_ready);

        if (MARS_E_OK == ret_val)
        {
            if (MARS_RADAR_READY_OK != radar_ready)
            {
                mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_FRAME, (uint32)frame_mars_busy);
            }
        }
    }
    return ret_val;
}

/**
 * @brief         Generates ZHV data not initaste ZHV generation
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful MARS_E_NOT_OK if failed
 * @design        GID-438545
 */
Mars_ReturnType mars_action_zhv_generate_cleanup(mars_instance_t *const mars_self)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    
    /* Step 6: Inform MAF that next frame may not initiate ZHV generation */
    mars_scratchpad_cfg_t mars_scp_cfg = {0};


    mars_scp_cfg.frame_3.zhv_generation_mode = MARS_ZHV_USE_EXISTING_TABLE;
    mars_scp_cfg.valid_1 |= (1uL << MARS_VALID_1_ZHV_GENERATION_MODE_VALID);

    ret_val = mars_action_scp_send_update_command(mars_self, &mars_scp_cfg);

    return ret_val;
}


/**
 * @brief         Initializes GPIO reset sequence
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful MARS_API_ID_INIT errors if failed
 * @design        GID-438453
 */
Mars_ReturnType mars_action_init_gpio_reset_write(mars_instance_t *const mars_self)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    /* Set the PMU to Idle State - GPIO Reset is active LOW */
    ret_val = mars_gpio_reset_write(mars_self, L0_IO_LO);

    if(ret_val == MARS_E_OK)
    {
        ret_val = mars_wait_ms(mars_self, MARS_INIT_RESET_LOW_TIME);
    }
    /* Release the PMU from Idle State, next state is FUNC (debug mode set) - GPIO Reset is not-active/idle HIGH */
    if(ret_val == MARS_E_OK)
    {
        ret_val = mars_gpio_reset_write(mars_self, L0_IO_HI);
    }
    /* Wait for Mars transition to BIST then FUNC mode */
    if(ret_val == MARS_E_OK)
    {
        ret_val = mars_wait_ms(mars_self, MARS_INIT_WAIT_AFTER_RESET);
    }

    return ret_val;
}


/**
 * @brief         Initializes GPIO reset sequence for debug mode
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful MARS_API_ID_INIT errors if failed
 * @design        GID-438452
 */
#ifndef MARS_DEBUG_SUPPORT_DISABLED
Mars_ReturnType mars_action_init_debug_gpio_reset_write(mars_instance_t *const mars_self)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    const mars_init_debug_gpio_t gpio_call[] =
    {
        {&mars_gpio_reset_write,   L0_IO_LO}, /* Debug boot step 1: RESET_N LOW */
        {&mars_gpio_frm_en_write,  L0_IO_HI}, /* Debug boot step 2: FRAME_ENABLE_IN HIGH */
        {&mars_gpio_te_write,      L0_IO_HI}, /* Debug boot step 3: TE HIGH */
        {&mars_gpio_reset_write,   L0_IO_HI}, /* Debug boot step 4: RESET_N HIGH */
        {&mars_gpio_frm_en_write,  L0_IO_LO}, /* Debug boot step 5: FRAME_ENABLE_IN LO */
        {&mars_gpio_te_write,      L0_IO_LO}  /* Debug boot step 6: TE LO */
    };
        
    for(uint32 indx=0; indx < (sizeof(gpio_call)/sizeof(gpio_call[0])); indx++)
    {
        ret_val = gpio_call[indx].gpio_write(mars_self, gpio_call[indx].gpio_level);
        if (ret_val == MARS_E_OK)
        {
           ret_val = mars_wait_us(mars_self, MARS_INIT_DEBUG_SEQ_DELAY);
        }
        
        if(ret_val != MARS_E_OK)
        {
            break;
        }
    }

    /* wait for MBL */
    if(ret_val == MARS_E_OK)
    {
        ret_val = mars_wait_ms(mars_self, MARS_INIT_WAIT_AFTER_RESET);
    }    

    return ret_val;
}
#endif

/**
 * @brief         Check Initialization MBL timeout and status 
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful MARS_API_ID_INIT errors if failed
 * @design        GID-438454
 */
Mars_ReturnType mars_action_check_init_status(mars_instance_t *const mars_self)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    /* Check MBL timeout and status */
    ret_val = mars_action_mbl_check_status(mars_self);
        
    if (MARS_E_OK == ret_val)
    {
        ret_val = mars_action_ssi_configure(mars_self);
    }

    if (MARS_E_OK == ret_val)
    {
        /* Initialization successfully, change the Driver State and Operation Mode */
        MARS_DATA_DRIVER_STATUS = MARS_INITIALIZED_FW_NOT_RUNNING;
#if defined(MARS_POST_MBL_SSI_HIGH_IF_CLOCK_OK)
        {
            const Mars_ReturnType ret_speed = mars_action_ssi_set_speed(mars_self);
            if (MARS_E_OK != ret_speed)
            {
                ret_val = ret_speed;
                MARS_DATA_DRIVER_STATUS = MARS_DRIVER_ERROR;
            }
        }
#endif
    }else
    {
        /* Initialization failed */
        MARS_DATA_DRIVER_STATUS = MARS_DRIVER_ERROR;

    }

    return ret_val;
}

/**
* @brief         Utility function to check if conditions are met to perform a given API call
* @param [in]    mars_self pointer to instance structure
* @param [in]    drv_state Drviver state where the call is accepted
* @param [in]    op_mode Openartion mode where the call is accepted
* @param [in]    min_fw_ver Minimum MAF version required for the API call, use MARS_ALLOW_ALL_FW_VERSIONS if no check needed
* @param [in]    max_fw_ver Maximum MAF version required for the API call
* @return        MARS_E_OK is call is permitted, MARS_ERROR_L2_API_CHECK error if call is prohibited
* @design        GID-347783 GID-347778 GID-347781
*/
Mars_ReturnType mars_action_allow_api_call( mars_instance_t *const mars_self, const mars_driver_status_t drv_state, const uint32 op_mode, const uint32 min_fw_ver, const uint32 max_fw_ver) /* polyspace GUIDELINE:SC04 [No action planned:Medium] "The function used by all the APIs to validate the correct driver state, operation state and firmware version" */ /* polyspace GUIDELINE:SC21 [No action planned:Medium] "The function used by all the APIs to validate the correct driver state, operation state and firmware version" */
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if (NULL_PTR == mars_self)
    {
        mars_set_l2_error_information(&ret_val, MARS_NO_DATA, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_INVALID_INSTANCE_ERROR);
    }
    else
    {
        if ((MARS_UNINTIALIZED != drv_state) && (0u == (MARS_DATA_DRIVER_STATUS & drv_state)))
        {
            if(MARS_DATA_DRIVER_STATUS == MARS_BUSY)
            {
                ret_val= mars_action_check_maf_state(mars_self, MARS_RDY_TIMEOUT_US);
            }
            else
            {
                mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_DRIVER_STATUS_ERROR);
            }
            
        }

        if ((ret_val == MARS_E_OK) && (MARS_OPERATION_MODE_UNDEFINED != op_mode))
        {
            if (0u == (MARS_DATA_OP_MODE_STATUS & op_mode))
            {
                mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_OPERATION_MODE_ERROR);
            }
        }

        if ((ret_val == MARS_E_OK) && (MARS_ALLOW_ALL_FW_VERSIONS != min_fw_ver))
        {
            /* Compare MAF version without patch field */
            if ((MARS_DATA_FW_VERSION & 0xFFFF00u) < (min_fw_ver & 0xFFFF00u))
            {
                mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_MAF_MIN_VER_NOT_COMPATIBLE_ERROR);
            }
        }

        if ((ret_val == MARS_E_OK) && (MARS_ALLOW_ALL_FW_VERSIONS != max_fw_ver))
        { /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the MAF version is more than the supported versions" */
            /* Compare MAF version without patch field */
            if ((MARS_DATA_FW_VERSION & 0xFFFF00u) >= (max_fw_ver & 0xFFFF00u))
            {
                mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_API_CHECK, (uint32)MARS_L2_API_CHECK_MAF_MAX_VER_NOT_COMPATIBLE_ERROR);
            }
        }

        /* TODO: more conditions if needed */
    }

    return ret_val;
}

/**
 * @brief         Check if MAF has been activated yet
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful, MARS_L2_MAF_RADAR_READY_TIMEOUT_ERROR or l1 error if failed
 * @design        GID-409955
 */
Mars_ReturnType mars_action_maf_activation_check( mars_instance_t *const mars_self)
{
    uint32 ready_wait_ctr = MARS_ACTIVATE_RDY_POLL_CNT;
    Mars_ReturnType ret_val = MARS_E_OK;
    mars_reg_value_t radar_ready = 0u;
    do
    {
        ret_val = mars_read_reg_safe(mars_self, MARS_F_CORE_BANK_MCU_RDR_READY, &radar_ready);

        if ((MARS_E_OK != ret_val) || (MARS_RADAR_READY_OK == radar_ready))
        {
            break;
        }

        ready_wait_ctr--;

        ret_val = mars_wait_ms(mars_self, MARS_ACTIVATE_RDY_POLL_MSEC); /* wait 10msec between checks */

    } while ((MARS_E_OK == ret_val) && (0u != ready_wait_ctr));

    if ((MARS_E_OK == ret_val) && (0 == ready_wait_ctr))
    {
        mars_set_l2_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_NO_DATA, MARS_ERROR_L2_MAF, (uint32)MARS_L2_MAF_RADAR_READY_TIMEOUT_ERROR);
    }
    return ret_val;
}
