/* @copyright 2024 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_l1.h"
#include "mars_l1_raw.h"
#include "mars_regs_gen.h"
#include "mars_l1_validated_params.h"

/**********************************************************************************************************************
 * LOCAL MACROS
 *********************************************************************************************************************/
#define MARS_MLBX_MAX_NO_OF_INDEX 16u
#define MARS_MLBX_REQ 1uL

#define MARS_MLBX_PARITY_MASK 0xFFuL
#define MARS_MLBX_PARITY_SHIFT 0x08u

#define MARS_MLBX_VAR_SIZE 2u

#define MARS_MLBX_TIME_OUT_SCALEING_FACTOR 10u

#define MARS_MLBX_T_FIRST_INDEX 0u
#define MARS_MLBX_T_SECOND_INDEX 1u

#define MARS_MLBX_PARITYL_SHIFT      0u
#define MARS_MLBX_PARITYL_MASK       0xFu
#define MARS_MLBX_VARL_SHIFT         4u
#define MARS_MLBX_VARL_MASK          0x0FFFFFFFu
#define MARS_MLBX_PARITYH_SHIFT      0u
#define MARS_MLBX_PARITYH_MASK       0xFu
#define MARS_MLBX_VARH_SHIFT         4u
#define MARS_MLBX_VARH_MASK          0xFFFFu
#define MARS_MLBX_CMD_SHIFT          20u
#define MARS_MLBX_CMD_MASK           0x1FFu
#define MARS_MLBX_RESERVED_SHIFT     29u
#define MARS_MLBX_RESERVED_MASK      0x1u
#define MARS_MLBX_STATE_SHIFT        30u
#define MARS_MLBX_STATE_MASK         0x3u
/**********************************************************************************************************************
 * LOCAL TYPE DECLARATIONS
 *********************************************************************************************************************/
typedef enum
{
    MARS_MLBX_STATUS_IDLE = 0,
    MARS_MLBX_STATUS_BUSY = 1,
} mars_mailbox_idle_en;

typedef enum
{
    MARS_MLBX_CHECK_NORMAL = 0,
    MARS_MLBX_CHECK_RECOVERY = 1
} mars_mailbox_recovery_en;

typedef struct
{
    uint32 mars_mlbx_h_reg;
    uint32 mars_mlbx_l_reg;
} mars_mlbx_index_t;

typedef uint32 mars_mlbx_t[MARS_MLBX_VAR_SIZE];

/**********************************************************************************************************************
 * LOCAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/
static Mars_ReturnType mars_l1_mailbox_write_prv( mars_instance_t *const mars_self, const mars_mailbox_req_t *const mlbx);
static Mars_ReturnType mars_l1_mailbox_read_prv( mars_instance_t *const mars_self, mars_mlbx_t mlbx_data, uint32 *const slot, const mars_mailbox_recovery_en check_recovery);
static Mars_ReturnType mars_l1_mailbox_is_idle_prv( mars_instance_t *const mars_self, uint32 const slot, mars_mailbox_idle_en *const status);
static uint32 mars_l1_parity8_prv(const uint8 parity_data);
static uint32 mars_l1_mailbox_parity_prv(const uint32 parity_data);

/**********************************************************************************************************************
 * LOCAL CONSTANTS
 *********************************************************************************************************************/
static const mars_mlbx_index_t MARS_MLBX_SLOT_REGS[MARS_MLBX_MAX_NO_OF_INDEX] = {
    /* INDEX 0  */ {MARS_F_CPU_SYS_MLBX_H0, MARS_F_CPU_SYS_MLBX_L0}, /* STATUS_RESPONSE (MLBX 0) */
    /* INDEX 1  */ {MARS_F_CPU_SYS_MLBX_H1, MARS_F_CPU_SYS_MLBX_L1}, /* GEN_CMD (MLBX 1) */
    /* INDEX 2  */ {MARS_F_CPU_SYS_MLBX_H2, MARS_F_CPU_SYS_MLBX_L2},
    /* INDEX 3  */ {MARS_F_CPU_SYS_MLBX_H3, MARS_F_CPU_SYS_MLBX_L3},
    /* INDEX 4  */ {MARS_F_CPU_SYS_MLBX_H4, MARS_F_CPU_SYS_MLBX_L4},
    /* INDEX 5  */ {MARS_F_CPU_SYS_MLBX_H5, MARS_F_CPU_SYS_MLBX_L5},
    /* INDEX 6  */ {MARS_F_CPU_SYS_MLBX_H6, MARS_F_CPU_SYS_MLBX_L6},
    /* INDEX 7  */ {MARS_F_CPU_SYS_MLBX_H7, MARS_F_CPU_SYS_MLBX_L7},
    /* INDEX 8  */ {MARS_F_CPU_SYS_MLBX_H8, MARS_F_CPU_SYS_MLBX_L8},
    /* INDEX 9  */ {MARS_F_CPU_SYS_MLBX_H9, MARS_F_CPU_SYS_MLBX_L9},
    /* INDEX 10 */ {MARS_F_CPU_SYS_MLBX_H10, MARS_F_CPU_SYS_MLBX_L10},
    /* INDEX 11 */ {MARS_F_CPU_SYS_MLBX_H11, MARS_F_CPU_SYS_MLBX_L11},
    /* INDEX 12 */ {MARS_F_CPU_SYS_MLBX_H12, MARS_F_CPU_SYS_MLBX_L12},
    /* INDEX 13 */ {MARS_F_CPU_SYS_MLBX_H13, MARS_F_CPU_SYS_MLBX_L13},
    /* INDEX 14 */ {MARS_F_CPU_SYS_MLBX_H14, MARS_F_CPU_SYS_MLBX_L14},
    /* INDEX 15 */ {MARS_F_CPU_SYS_MLBX_H15, MARS_F_CPU_SYS_MLBX_L15}};

/**********************************************************************************************************************
 * GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**
 * @brief         send a mailbox message to Mars
 * @param         mars_self mars driver instance reference
 * @param         mlbx reference to the mailbox request data structure
 * @param         timeout wait time for mailbox getting available
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-278673 GID-286195 GID-346699
 */
Mars_ReturnType mars_write_mlbx( mars_instance_t *const mars_self, const mars_mailbox_req_t *const mlbx, const uint32 timeout)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if ((mars_self != NULL_PTR) && (mlbx != NULL_PTR))
    {
        /* set/clear the return value */
        uint32 timeout_tmp = timeout / MARS_MLBX_TIME_OUT_SCALEING_FACTOR;
        uint32 exit_loop = 0;
        /* Wait for a valid MLBX event */
        do
        {
            /* Write the mailbox request */
            ret_val = mars_l1_mailbox_write_prv(mars_self, mlbx);

            if (((ret_val & ((MARS_ERROR_L1_BIT_MASK << MARS_ERROR_L1_BIT_OFFSET) | (MARS_ERROR_ID_BIT_MASK << MARS_ERROR_ID_BIT_OFFSET))) == (MARS_L1_E_MLBX_BUSY_ERROR | MARS_ERROR_L1_MLBX)))
            {
                ret_val = mars_wait_us(mars_self, 10u);
                timeout_tmp--;
                if (ret_val != MARS_E_OK)
                {
                    exit_loop = 1uL;
                }
            }
            else
            {
                exit_loop = 1uL;
            }

        } while ((0u < timeout_tmp) && (exit_loop == 0u));

        if (ret_val == MARS_E_OK)
        {
            if (timeout_tmp == 0)
            {
                mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_MLBX, MARS_L1_E_MLBX_BUSY_ERROR);
            }
        }
    }
    else
    {/* polyspace RTE:UNR [Not a defect:Low] "Null pointer check for unit level testability" */
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MLBX, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         get a mailbox message from Mars
 * @param         mars_self mars driver instance reference
 * @param         mlbx reference to the mailbox response data structure
 * @param         timeout timeout in microseconds until the function waits for a message to arrive
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-278674 GID-286194 GID-346694
 */
Mars_ReturnType mars_read_mlbx( mars_instance_t *const mars_self, mars_mailbox_resp_t *const mlbx, const uint32 timeout)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if ((mars_self != NULL_PTR) && (mlbx != NULL_PTR))
    {
        /* check if MLBX response is active, or, if not it would be active within timeout */
        mars_gpio_level_en mlbx_chn_val = L0_IO_LO;
        uint32 timeout_tmp = timeout / MARS_MLBX_TIME_OUT_SCALEING_FACTOR;
        uint32 exit_gpio_loop = 0;
        /* Wait for a valid MLBX event */
        while ((0u < timeout_tmp) && (exit_gpio_loop == 0u))
        {
            ret_val = mars_gpio_mlbx_read(mars_self, &mlbx_chn_val);
            if ((ret_val != MARS_E_OK) || (L0_IO_HI == mlbx_chn_val))
            {
                exit_gpio_loop = 1uL;
            }
            else
            {
                ret_val = mars_wait_us(mars_self, 10u);
                
               exit_gpio_loop = (ret_val != MARS_E_OK) ? 1uL : 0uL; 
            }
            timeout_tmp--;
        }

        /* check if mailbox response indication was inactive at the end of timeout*/
        if (mlbx_chn_val == L0_IO_LO)
        {
            /* set timeout error if no other L0 error is pending */
            if (ret_val == MARS_E_OK)
            {
                mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_MLBX, MARS_L1_E_MLBX_TIMEOUT_ERROR);
            }
        }
        else
        {
            /* active mailbox request */
            uint32 mlbx_iteration = MARS_MLBX_MAX_NO_OF_INDEX;
            uint32 exit_read_loop = 0;
            do
            {
                mars_mlbx_t mlbx_data = {0};
                uint32 slot;

                ret_val = mars_l1_mailbox_read_prv(mars_self, mlbx_data, &slot, MARS_MLBX_CHECK_NORMAL);

                if (MARS_E_OK != ret_val)
                {
                    ret_val = mars_l1_mailbox_read_prv(mars_self, mlbx_data, &slot, MARS_MLBX_CHECK_RECOVERY);
                }

                if (ret_val == MARS_E_OK)
                {
                    /* we only process the mailbox response from the expected slot */
                    if (slot == mlbx->slot)
                    {
                        mlbx->var_h = ((mlbx_data[MARS_MLBX_T_SECOND_INDEX] >> MARS_MLBX_VARH_SHIFT) & MARS_MLBX_VARH_MASK);
                        mlbx->var_l = ((mlbx_data[MARS_MLBX_T_FIRST_INDEX] >> MARS_MLBX_VARL_SHIFT) & MARS_MLBX_VARL_MASK);
                        mlbx->response = (((mlbx_data[MARS_MLBX_T_SECOND_INDEX] >> MARS_MLBX_CMD_SHIFT) & MARS_MLBX_CMD_MASK) & 0x1FuL); /* response is 5 bits */

                        /* check if the response has indicated parity error / resend request / in the mailbox command */
                        if (0 != (mlbx->response & (1uL << MARS_MLBX_PARITY_CHECK_BIT)))
                        {
                            /* we store the parity error */
                            mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_MLBX, MARS_L1_E_MLBX_REQUEST_PARITY_ERROR);
                        }
                    }
                    if (ret_val != MARS_E_OK)
                    {
                        exit_read_loop = 1uL;
                    }
                    else
                    {
                        mlbx_chn_val = L0_IO_LO;
                        ret_val = mars_gpio_mlbx_read(mars_self, &mlbx_chn_val);
                        if (ret_val != MARS_E_OK)
                        {
                            exit_read_loop = 1uL;
                        }
                    }
                }
                else
                {
                    exit_read_loop = 1uL;
                }
                mlbx_iteration--;
            } while ((mlbx_iteration > 0) && (mlbx_chn_val == L0_IO_HI) && (exit_read_loop == 0));

            /* if we exhausted all mailbox read then we indicate unexpected response */
            if ((mlbx_iteration == 0) && (ret_val == MARS_E_OK))
            {
                mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_MLBX, MARS_L1_E_MLBX_UNEXPECTED_RESP);
            }
        }

    }
    else
    { /* polyspace RTE:UNR [Not a defect:Low] "Null pointer check for unit level testability" */
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MLBX, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         exchange mailbox request and response message pair with  Mars
 * @param         mars_self mars driver instance reference
 * @param         mlbx_w reference to the mailbox request data structure
 * @param         mlbx_r reference to the mailbox response data structure
 * @param         timeout timeout in microseconds until the function waits for the response to arrive
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-286131 GID-286193 GID-346701
 */
Mars_ReturnType mars_exchange_mlbx( mars_instance_t *const mars_self, const mars_mailbox_req_t *const mlbx_w, mars_mailbox_resp_t *const mlbx_r, const uint32 timeout) /* polyspace GUIDELINE:SC04 [No action planned:Medium] "The function provides the generic mailbox interaction." */
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if ((mars_self != NULL_PTR) && (mlbx_w != NULL_PTR) && (mlbx_r != NULL_PTR))
    {
        /* send request */
        ret_val = mars_write_mlbx(mars_self, mlbx_w, MARS_MLBX_WRITE_TIMEOUT);
        if (ret_val == MARS_E_OK)
        {
            /* wait for response */
            mlbx_r->slot = mlbx_w->slot; /* We expect the response in the slot where we sent the request from */
            ret_val = mars_read_mlbx(mars_self, mlbx_r, timeout);
        }
    }
    else
    { /* polyspace RTE:UNR [Not a defect:Low] "Null pointer check for unit level testability" */
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MLBX, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**********************************************************************************************************************
 * LOCAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/**
* @brief         internal function handling mailbox write
* @param         mars_self mars driver instance reference
* @param         mlbx reference to the mailbox request data structure
* @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
* @design        GID-346696 GID-286195
*/
static Mars_ReturnType mars_l1_mailbox_write_prv( mars_instance_t *const mars_self, const mars_mailbox_req_t *const mlbx)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    mars_mailbox_idle_en idle = MARS_MLBX_STATUS_IDLE;

    ret_val = mars_l1_mailbox_is_idle_prv(mars_self, mlbx->slot, &idle);

    if (MARS_E_OK == ret_val)
    {
        if (idle == MARS_MLBX_STATUS_IDLE)
        {
            mars_mlbx_t raw_mailbox = {0};
            raw_mailbox[MARS_MLBX_T_SECOND_INDEX] |= ((mlbx->command & MARS_MLBX_CMD_MASK) << MARS_MLBX_CMD_SHIFT);
            raw_mailbox[MARS_MLBX_T_SECOND_INDEX] |= ((mlbx->var_h & MARS_MLBX_VARH_MASK) << MARS_MLBX_VARH_SHIFT);
            raw_mailbox[MARS_MLBX_T_FIRST_INDEX]  |= ((mlbx->var_l & MARS_MLBX_VARL_MASK) << MARS_MLBX_VARL_SHIFT);

            /* Write MLBX Variable L */
            /* Writing the two locations in a single memory write call is not providing performance benefit, because
            Mars is not capable to receive 2x32 bit data words in a single transfer. (Only 1, 4, 8 etc is possible).
            So the L1 memory write call would break down the operation to two separate  transfer sequences.
             */
            raw_mailbox[MARS_MLBX_T_FIRST_INDEX] |= ((mars_l1_mailbox_parity_prv(raw_mailbox[MARS_MLBX_T_FIRST_INDEX]) & MARS_MLBX_PARITYL_MASK) << MARS_MLBX_PARITYL_SHIFT);
            ret_val = mars_write_reg_raw(mars_self, MARS_MLBX_SLOT_REGS[mlbx->slot].mars_mlbx_l_reg, raw_mailbox[MARS_MLBX_T_FIRST_INDEX], MARS_L1_SAFE_NO_CHK);

            if (MARS_E_OK == ret_val)
            {
                /* Write the command MLBX Variable H */
                raw_mailbox[MARS_MLBX_T_SECOND_INDEX] |= ((0uL & MARS_MLBX_RESERVED_MASK) << MARS_MLBX_RESERVED_SHIFT);
                raw_mailbox[MARS_MLBX_T_SECOND_INDEX] |= ((MARS_MLBX_REQ & MARS_MLBX_STATE_MASK) << MARS_MLBX_STATE_SHIFT);
                raw_mailbox[MARS_MLBX_T_SECOND_INDEX] |= ((mars_l1_mailbox_parity_prv(raw_mailbox[MARS_MLBX_T_SECOND_INDEX]) & MARS_MLBX_PARITYH_MASK) << MARS_MLBX_PARITYH_SHIFT);

                ret_val = mars_write_reg_raw(mars_self, MARS_MLBX_SLOT_REGS[mlbx->slot].mars_mlbx_h_reg, raw_mailbox[MARS_MLBX_T_SECOND_INDEX], MARS_L1_SAFE_NO_CHK);
            }
        }
        else
        {
            mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MLBX, MARS_L1_E_MLBX_BUSY_ERROR);
        }
    }


    return ret_val;
}

/**
* @brief         internal function checking if mailbox is idle
* @param[in]     mars_self mars driver instance reference
* @param[in]     slot mailbox slot to be checked
* @param[out]    status reference to status variable of the caller to report idle status
* @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
* @design        GID-346319 GID-346322 GID-346704
*/
static Mars_ReturnType mars_l1_mailbox_is_idle_prv( mars_instance_t *const mars_self, const uint32 slot, mars_mailbox_idle_en *const status)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    uint32 register_val_buffer = 0;

    /* Check the index value */
    if (slot < MARS_MLBX_MAX_NO_OF_INDEX)
    {
        ret_val = mars_read_reg_raw_safe(mars_self, MARS_F_CPU_SYS_MLBX_STATUS, &register_val_buffer);
        if (MARS_E_OK == ret_val)
        {
            const uint32 mlbx_idle_bit = 1uL << ((slot & 0x0Fu) + MARS_MLBX_MAX_NO_OF_INDEX);
            if ((register_val_buffer & mlbx_idle_bit) != 0)
            {
                *status = MARS_MLBX_STATUS_IDLE;
            }
            else
            {
                *status = MARS_MLBX_STATUS_BUSY;
            }
        }

    }
    else
    { /* polyspace RTE:UNR [Not a defect:Low] "Guard against wrong parameter slot" */
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MLBX, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
* @brief         internal function calculating mailbox 4 bit parity value
* @param[in]     parity_data input data for parity calculation, total 4 bytes
* @return        Calculated parity on the lowest 4 bits, one bit for each byte in the input 32-bit word
* @design        GID-346313 GID-346710 GID-346316
*/
static uint32 mars_l1_mailbox_parity_prv(const uint32 parity_data)
{
    uint32 parity_data_tmp = parity_data;
    uint32 words[sizeof(uint32)] = {0};

    parity_data_tmp >>= MARS_4_BITS; /* in mailbox message words always the last 4 bits are the parity */
    for (uint32 bit_idx = 0; bit_idx < sizeof(uint32); bit_idx++)
    {
        /* Parity bits for each consecutive 7/8/4 data bit */
        words[bit_idx] = ~(mars_l1_parity8_prv((uint8)(parity_data_tmp & MARS_MLBX_PARITY_MASK))) & 0x01uL;
        parity_data_tmp >>= MARS_MLBX_PARITY_SHIFT;
    }

    return (words[3] << MARS_3_BITS) | (words[2] << MARS_2_BITS) | (words[1] << MARS_1_BIT) | words[0];
}

/**
* @brief         internal function calculating mailbox 1 bit parity value on individual byte
* @param[in]     parity_data input data for parity calculation, total 1 byte
* @return        Calculated parity on the lowest bit
* @design        GID-346708 GID-346316
*/
static uint32 mars_l1_parity8_prv(const uint8 parity_data)
{
    uint32 ret = 0;
    uint8 parity_tmp = parity_data;
    parity_tmp ^= (parity_tmp >> MARS_4_BITS);
    parity_tmp &= 0x0Fu;
    ret = (MARS_PARITY_LUT_4BIT >> parity_tmp) & 1uL;

    return ret;
}
/**
* @brief         internal function handling mailbox read
* @param[in]     mars_self mars driver instance reference
* @param[out]    mlbx_data reference to the mailbox response data structure
* @param[in]     slot mailbox slot to be read
* @param[in]     check_recovery if the recovery mailbox set should be used
* @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
* @design        GID-346692
*/
static Mars_ReturnType mars_l1_mailbox_read_prv( mars_instance_t *const mars_self, mars_mlbx_t mlbx_data, uint32 *const slot, const mars_mailbox_recovery_en check_recovery)
{
    Mars_ReturnType ret_val = MARS_L1_E_NOT_OK;
    mars_mlbx_t mlbx_tmp = {0};
    uint32 mlbx_tmp_slot = 0;

    /* Polyspace required initialization */
    mlbx_tmp[MARS_MLBX_T_FIRST_INDEX] = 0;
    mlbx_tmp[MARS_MLBX_T_SECOND_INDEX] = 0;

    /* get the pending slot index */
    ret_val = mars_read_reg_raw(mars_self, MARS_F_CPU_SYS_MLBX_RELEASE_INDEX, &mlbx_tmp_slot);

    if (MARS_E_OK == ret_val)
    {
        uint32 mlbx_slot_parity = 0;
        mlbx_slot_parity = mars_l1_parity8_prv((uint8)(mlbx_tmp_slot & 0x0Fu));
        mlbx_slot_parity <<= 4;

        if (mlbx_slot_parity != (mlbx_tmp_slot & 0x10uL)) /* check if the slot index is valid */
        {
            mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MLBX, MARS_L1_E_MLBX_INVALID_SLOT);
        }
        else
        {
            *slot = (mlbx_tmp_slot & 0x0FuL);
        }
    }

    if (MARS_E_OK == ret_val)
    {
        if (MARS_MLBX_CHECK_NORMAL == check_recovery)
        {
            ret_val = mars_read_reg_raw(mars_self, MARS_F_CPU_SYS_MLBX_RELEASE_L, &mlbx_tmp[MARS_MLBX_T_FIRST_INDEX]);
            if (MARS_E_OK == ret_val)
            {
                ret_val = mars_read_reg_raw(mars_self, MARS_F_CPU_SYS_MLBX_RELEASE_H, &mlbx_tmp[MARS_MLBX_T_SECOND_INDEX]);
            }
        }
        else
        {
            ret_val = mars_read_reg_raw(mars_self, MARS_F_CPU_SYS_MLBX_RELEASE_RECOV_L, &mlbx_tmp[MARS_MLBX_T_FIRST_INDEX]);
            if (MARS_E_OK == ret_val)
            {
                ret_val = mars_read_reg_raw(mars_self, MARS_F_CPU_SYS_MLBX_RELEASE_RECOV_H, &mlbx_tmp[MARS_MLBX_T_SECOND_INDEX]);
            }
        }

    }

    /* Read the Mailbox L and H */
    if (MARS_E_OK == ret_val)
    {
        /* Check the Mailbox response parity - last 4 bits are the parity*/
        const uint32 tmp_pl = mars_l1_mailbox_parity_prv(mlbx_tmp[MARS_MLBX_T_FIRST_INDEX]) & 0x0FuL;
        const uint32 tmp_ph = mars_l1_mailbox_parity_prv(mlbx_tmp[MARS_MLBX_T_SECOND_INDEX]) & 0x0FuL;

        if (((mlbx_tmp[MARS_MLBX_T_FIRST_INDEX] & MARS_MLBX_PARITYL_MASK) == tmp_pl) && ((mlbx_tmp[MARS_MLBX_T_SECOND_INDEX] & MARS_MLBX_PARITYH_MASK) == tmp_ph))
        {
            mlbx_data[MARS_MLBX_T_FIRST_INDEX] = mlbx_tmp[MARS_MLBX_T_FIRST_INDEX];
            mlbx_data[MARS_MLBX_T_SECOND_INDEX] = mlbx_tmp[MARS_MLBX_T_SECOND_INDEX];

            /* Mailbox data saved */
            ret_val = MARS_E_OK;
        }
        else
        {
            /* Mailbox response parity check failed */
            mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MLBX, MARS_L1_E_MLBX_RESPONSE_PARITY_ERROR);
        }
    }

    return ret_val;
}
