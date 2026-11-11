/* @copyright 2024 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_l1.h"
#include "mars_l1_raw.h"
#include "mars_l1_validated_params.h"

/**********************************************************************************************************************
 * LOCAL MACRO
 *********************************************************************************************************************/
#define CRC_OUTPUT_XOR_VAL 0xFFFFFFFFu /*!< CRC Output XOR value  */

#define MARS_MAX_ADDR 0x3FFFFuL
#define MARS_ADDR_1K_BYTES_SIZE 0x400u
#define MARS_ADDR_1K_BYTES_MASK 0x3FFu

#define MARS_MAX_MEMORY_BLOCK_SIZE_WORDS 2862u /* maximum number of words that can be transferred in one transfer, based on the maximum burst size for Hamming distance 4 */
#define MARS_MLBX_CRC_VAR_SHFT  16u
#define MARS_MLBX_CRC_VAR_MASK  0xFFFFu

/**********************************************************************************************************************
 * Command packet Macros
 *********************************************************************************************************************/
#define MARS_SSI_CMDPACKET_PARITY_ADDR_SHIFT      16u
#define MARS_SSI_CMDPACKET_ADDRESS_SHIFT           0u
#define MARS_SSI_CMDPACKET_RD_WR_RED_SHIFT        18u
#define MARS_SSI_CMDPACKET_DLEN_RED_SHIFT         19u
#define MARS_SSI_CMDPACKET_CRC_CTRL_SHIFT         22u
#define MARS_SSI_CMDPACKET_DLEN_SHIFT             24u
#define MARS_SSI_CMDPACKET_WAIT_CYCLES_SHIFT      27u
#define MARS_SSI_CMDPACKET_TR_TYPE_SHIFT          29u
#define MARS_SSI_CMDPACKET_RD_WR_SHIFT            31u

#define MARS_SSI_CMDPACKET_ADDRESS_MASK           0xFFFFu
#define MARS_SSI_CMDPACKET_PARITY_ADDR_MASK       0x3u
#define MARS_SSI_CMDPACKET_RD_WR_RED_MASK         0x1u
#define MARS_SSI_CMDPACKET_DLEN_RED_MASK          0x7u
#define MARS_SSI_CMDPACKET_CRC_CTRL_MASK          0x3u
#define MARS_SSI_CMDPACKET_DLEN_MASK              0x7u
#define MARS_SSI_CMDPACKET_WAIT_CYCLES_MASK       0x3u
#define MARS_SSI_CMDPACKET_TR_TYPE_MASK           0x3u
#define MARS_SSI_CMDPACKET_RD_WR_MASK             0x1u

/**********************************************************************************************************************
 * LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32 mars_ssi_cmdpacket_t;

/**********************************************************************************************************************
 * LOCAL CONSTANT DECLARATIONS
 *********************************************************************************************************************/
/* supported SSI length values */
static const uint32 SSI_DATA_LEN_MAP[] = {1u, 4u, 8u, 16u, 32u, 64u};

/**********************************************************************************************************************
 * LOCAL FUNCTIONS
 *********************************************************************************************************************/
static uint32 mars_l1_ssi_addr_parity(uint16 const address);
static uint32 mars_l1_get_max_size(const mars_l0_ssi_mode_en mode, const uint32 address, const mars_operation_en operation);
static uint32 mars_l1_burst_plan(const uint32 hw_max_idx, const uint32 remaining_words, const uint32 current_addr);
static Mars_ReturnType mars_l1_write_mem_unsafe(mars_instance_t *const mars_self, const uint32 *const src, uint32 dst, const uint32 size);
static Mars_ReturnType mars_l1_read_mem_unsafe(mars_instance_t *const mars_self, uint32 const src, uint32 *const dst, const uint32 size);
static Mars_ReturnType mars_l1_write_mem_unsafe_block(mars_instance_t *const mars_self, const uint32 *const src, uint32 dst, const uint32 size_idx, const mars_ssi_crc_reset_en crc_ctrl);
static Mars_ReturnType mars_l1_write_mem_raw_mt4(mars_instance_t *const mars_self, const uint32 *const src, const uint32 dst, const uint32 w_size, const mars_safe_chk_en chk);
/**********************************************************************************************************************
 * GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**
 * @brief         Write Mars memory without checking the integrity of the written values, up to one block of data
 * @param[in]     mars_self the Mars instance
 * @param[in]     src array of 32bits data  to be written to Mars memory
 * @param[in]     dst Mars memory starting address for the write operation
 * @param[in]     size_idx encoded size value enumeration
 * @param[in]     crc_ctrl control if the Mars hardware CRC should be reset (first block) or kept running (rest of blocks)
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-344796 GID-344179
 */
static Mars_ReturnType mars_l1_write_mem_unsafe_block( mars_instance_t *const mars_self, const uint32 *const src, uint32 dst, const uint32 size_idx, const mars_ssi_crc_reset_en crc_ctrl)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    const mars_l0_ssi_t *const ssi_driver = mars_self->Mars_Drivers.Mars_SSI_Driver; 
    mars_data_buffer_spi_t * const buffer_spi = &mars_self->Mars_Data.Mars_Buffer.Mars_Buffer_SPI;

    /* check if parameters are valid and within range */
    if ((ssi_driver != NULL_PTR) &&
            (ssi_driver->get_mode != NULL_PTR) && /* polyspace RTE:NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
            (ssi_driver->spi_transfer != NULL_PTR) && /* polyspace RTE:NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
            (ssi_driver->qspi_send != NULL_PTR) && /* polyspace RTE:NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
            (src != NULL_PTR))
    {
        mars_l0_ssi_mode_en l0_mode = L0_SSI_MODE_SPI;

        (void)ssi_driver->get_mode(MARS_L0_DRIVER_DATA(mars_self),&l0_mode); /* polyspace RTE:COR [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */

        if (size_idx <= mars_l1_get_max_size(l0_mode, dst, MARS_OPERATION_WRITE))
        {
            mars_ssi_cmdpacket_t mars_ssi_cmdpacket= 0;

            /* compile the SSI packet instruction that shall be transferred to Mars */
            const uint32 ssi_len = SSI_DATA_LEN_MAP[size_idx];

            mars_ssi_cmdpacket  = ((size_idx & MARS_SSI_CMDPACKET_DLEN_MASK) << MARS_SSI_CMDPACKET_DLEN_SHIFT);
            mars_ssi_cmdpacket |= ((size_idx & MARS_SSI_CMDPACKET_DLEN_RED_MASK) << MARS_SSI_CMDPACKET_DLEN_RED_SHIFT);
            mars_ssi_cmdpacket |= ((1uL & MARS_SSI_CMDPACKET_RD_WR_MASK) << MARS_SSI_CMDPACKET_RD_WR_SHIFT);           /* Write Operation  */
            mars_ssi_cmdpacket |= ((1uL & MARS_SSI_CMDPACKET_RD_WR_RED_MASK) << MARS_SSI_CMDPACKET_RD_WR_RED_SHIFT); /* Write Operation  */
            mars_ssi_cmdpacket |= ((0uL & MARS_SSI_CMDPACKET_WAIT_CYCLES_MASK) << MARS_SSI_CMDPACKET_WAIT_CYCLES_SHIFT);
            mars_ssi_cmdpacket |= ((0uL & MARS_SSI_CMDPACKET_TR_TYPE_MASK) << MARS_SSI_CMDPACKET_TR_TYPE_SHIFT); /* b00: Write */
            mars_ssi_cmdpacket |= ((((crc_ctrl == MARS_L1_SSI_RESET_CRC) ? 2uL : 1uL) & MARS_SSI_CMDPACKET_CRC_CTRL_MASK) << MARS_SSI_CMDPACKET_CRC_CTRL_SHIFT);
            mars_ssi_cmdpacket |= (((dst >> 2u) & MARS_SSI_CMDPACKET_ADDRESS_MASK) << MARS_SSI_CMDPACKET_ADDRESS_SHIFT);
            mars_ssi_cmdpacket |= (((mars_l1_ssi_addr_parity((uint16)((dst >> 2u) & 0xFFFFu)) & MARS_SSI_CMDPACKET_PARITY_ADDR_MASK) << MARS_SSI_CMDPACKET_PARITY_ADDR_SHIFT));

            switch (l0_mode)
            {
                case L0_SSI_MODE_SPI:
                    if ((ssi_len + 1u) <= SSI_BUFFER_SIZE)
                    {
                        uint32 index_copy = 0;
                        buffer_spi->buffer_SPI_out[0] = mars_ssi_cmdpacket;
                        for (index_copy = 0; index_copy < ssi_len; index_copy++)
                        {
                            buffer_spi->buffer_SPI_out[index_copy + 1] = src[index_copy]; /* polyspace RTE:IDP,NIV [No action planned:Low] "Pointer to the src buffer. It is obtained from the API instance parameter and checked against NULL_PTR */
                        }
                        ret_val = ssi_driver->spi_transfer(MARS_L0_DRIVER_DATA(mars_self), buffer_spi->buffer_SPI_out, buffer_spi->buffer_SPI_in, (ssi_len + 1)); /* polyspace RTE:COR [No action planned:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
                    }
                    else
                    {
                        ret_val = MARS_L1_E_NOT_OK_PARAM;
                    }
                    break;
                case L0_SSI_MODE_QSPI:
                    ret_val = ssi_driver->qspi_send(MARS_L0_DRIVER_DATA(mars_self),src, ssi_len, (uint16)(mars_ssi_cmdpacket >> MARS_16_BITS), dst >> 2); /* polyspace RTE:COR [No action planned:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
                    break;
                default: /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the current mode is not with valid value" */
                    ret_val = MARS_L1_E_NOT_OK;
                    break;
            }

            if (ret_val != MARS_E_OK)
            {
                mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MEM, MARS_NO_DATA);
            }
        }
        else
        {
            mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MEM, MARS_L1_E_NOT_OK_PARAM);
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MEM, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         Read Mars memory without checking the integrity of the read values, up to one block of data
 * @param[in]     mars_self pointer to the API instance structure
 * @param[in]     src Mars memory starting address for the read operation
 * @param[out]    dst array of 32bits data  to be read from Mars memory
 * @param[in]     size_idx encoded size value enumeration
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-344330 GID-344677
 */
Mars_ReturnType mars_l1_read_mem_unsafe_block(mars_instance_t *const mars_self, const uint32 src, uint32 *const dst, const uint32 size_idx, const mars_ssi_crc_reset_en crc_ctrl)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    const mars_l0_ssi_t *const ssi_driver = mars_self->Mars_Drivers.Mars_SSI_Driver; 
    mars_data_buffer_spi_t * const buffer_spi = &mars_self->Mars_Data.Mars_Buffer.Mars_Buffer_SPI;

    /* check if parameters are valid and within range */
    if ((ssi_driver != NULL_PTR) &&
            (ssi_driver->get_mode != NULL_PTR) && /* polyspace RTE:IDP,NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
            (ssi_driver->spi_transfer != NULL_PTR) && /* polyspace RTE:NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
            (ssi_driver->qspi_receive != NULL_PTR) && /* polyspace RTE:NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
            (dst != NULL_PTR))
    {
        mars_l0_ssi_mode_en l0_mode = L0_SSI_MODE_SPI;
        (void)ssi_driver->get_mode(MARS_L0_DRIVER_DATA(mars_self),&l0_mode); /* polyspace RTE:COR [No action planned:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */

        if (size_idx <= mars_l1_get_max_size(l0_mode, src, MARS_OPERATION_READ))
        {
            const uint32 ssi_len = SSI_DATA_LEN_MAP[size_idx];
            mars_ssi_cmdpacket_t mars_ssi_cmdpacket = 0;

            uint32 index_copy = 0;

            /* compile the SSI packet instruction that shall be transferred to Mars */
            mars_ssi_cmdpacket  = ((size_idx & MARS_SSI_CMDPACKET_DLEN_MASK) << MARS_SSI_CMDPACKET_DLEN_SHIFT);
            mars_ssi_cmdpacket |= ((size_idx & MARS_SSI_CMDPACKET_DLEN_RED_MASK) << MARS_SSI_CMDPACKET_DLEN_RED_SHIFT);
            mars_ssi_cmdpacket |= ((0uL & MARS_SSI_CMDPACKET_RD_WR_MASK) << MARS_SSI_CMDPACKET_RD_WR_SHIFT);           /* Write Operation  */
            mars_ssi_cmdpacket |= ((0uL & MARS_SSI_CMDPACKET_RD_WR_RED_MASK) << MARS_SSI_CMDPACKET_RD_WR_RED_SHIFT); /* Write Operation  */
            mars_ssi_cmdpacket |= ((0uL & MARS_SSI_CMDPACKET_WAIT_CYCLES_MASK) << MARS_SSI_CMDPACKET_WAIT_CYCLES_SHIFT);
            mars_ssi_cmdpacket |= ((3uL & MARS_SSI_CMDPACKET_TR_TYPE_MASK) << MARS_SSI_CMDPACKET_TR_TYPE_SHIFT); /* b00: Write */
            mars_ssi_cmdpacket |= ((((crc_ctrl == MARS_L1_SSI_RESET_CRC) ? 2uL : 1uL) & MARS_SSI_CMDPACKET_CRC_CTRL_MASK) << MARS_SSI_CMDPACKET_CRC_CTRL_SHIFT);
            mars_ssi_cmdpacket |= (((src >> 2u) & MARS_SSI_CMDPACKET_ADDRESS_MASK) << MARS_SSI_CMDPACKET_ADDRESS_SHIFT);
            mars_ssi_cmdpacket |= (((mars_l1_ssi_addr_parity((uint16)((src >> 2u) & 0xFFFFu)) & MARS_SSI_CMDPACKET_PARITY_ADDR_MASK) << MARS_SSI_CMDPACKET_PARITY_ADDR_SHIFT));

            (void)ssi_driver->get_mode(MARS_L0_DRIVER_DATA(mars_self),&l0_mode);

            switch (l0_mode)
            {
                case L0_SSI_MODE_SPI:
                    if ((ssi_len + 2u) <= SSI_BUFFER_SIZE)
                    {
                        mars_ssi_cmdpacket |= ((3uL & MARS_SSI_CMDPACKET_WAIT_CYCLES_MASK) << MARS_SSI_CMDPACKET_WAIT_CYCLES_SHIFT); /* b11: 32 Wait Cycles (SPI) */
                        buffer_spi->buffer_SPI_out[0] = mars_ssi_cmdpacket;
                        buffer_spi->buffer_SPI_out[1] = 0;
                        buffer_spi->buffer_SPI_out[2] = 0;
                        ret_val = ssi_driver->spi_transfer(MARS_L0_DRIVER_DATA(mars_self), buffer_spi->buffer_SPI_out, buffer_spi->buffer_SPI_in, (ssi_len + 2)); /* polyspace RTE:COR [No action planned:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
                        for (index_copy = 0; index_copy < ssi_len; index_copy++)
                        {
                            dst[index_copy] = buffer_spi->buffer_SPI_in[index_copy + 2u]; /* polyspace RTE:IDP [No action planned:Low] "Pointer to the dst buffer. It is obtained from the API instance parameter and checked against NULL_PTR */
                        }
                    }
                    else
                    {
                        ret_val = MARS_L1_E_NOT_OK_PARAM;
                    }
                    break;
                case L0_SSI_MODE_QSPI:
                    mars_ssi_cmdpacket |= ((0u & MARS_SSI_CMDPACKET_WAIT_CYCLES_MASK) << MARS_SSI_CMDPACKET_WAIT_CYCLES_SHIFT); /* b01: 8 Wait Cycle (QSPI) */
                    ret_val = ssi_driver->qspi_receive(MARS_L0_DRIVER_DATA(mars_self), dst, ssi_len, (uint16)(mars_ssi_cmdpacket >> MARS_16_BITS), (src >> 2)); /* polyspace RTE:COR [No action planned:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
                    break;
                default: /* polyspace RTE:UNR [Not a defect:Low] "Not unreachable code if the current mode is not with valid value" */
                    ret_val = MARS_L1_E_NOT_OK;
                    break;
            }

            if (ret_val != MARS_E_OK)
            {
                mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MEM, MARS_NO_DATA);
            }
        }
        else
        {
            mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MEM, MARS_L1_E_NOT_OK_PARAM);
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MEM, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         Read Mars memory without checking the integrity of the read values
 * @param[in]     mars_self the Mars instance
 * @param[in]     src Mars memory starting address for the read operation
 * @param[out]    dst array of 32bits data  to be read from Mars memory
 * @param[in]     size number of 32bits words to be read from Mars
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-344343 GID-344330
 */
static Mars_ReturnType mars_l1_read_mem_unsafe(mars_instance_t *const mars_self, const uint32 src, uint32 *const dst, const uint32 size)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    const mars_l0_ssi_t *const ssi_driver = mars_self->Mars_Drivers.Mars_SSI_Driver; 

    /* check if parameters are valid and within range */
    if ((ssi_driver != NULL_PTR) &&
            (ssi_driver->get_mode != NULL_PTR) && /* polyspace RTE:IDP,NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
            (dst != NULL_PTR) &&
            ((src + (size << 2)) <= MARS_MAX_ADDR) && (size > 0))
    {
        uint32 current_src = src;
        uint32 current_dst_idx = 0;
        uint32 remaining_size = size;
        mars_ssi_crc_reset_en crc_ctrl = MARS_L1_SSI_RESET_CRC;
        mars_l0_ssi_mode_en l0_mode = L0_SSI_MODE_SPI;

        (void)ssi_driver->get_mode(MARS_L0_DRIVER_DATA(mars_self), &l0_mode); /* polyspace RTE:COR [No action planned:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */

        const uint32 hw_max_idx = mars_l1_get_max_size(l0_mode, src, MARS_OPERATION_READ);

        /* Each iteration issues exactly one burst sized to fit in the remaining transfer and the
         * current 1K (1024-byte) region. mars_l1_burst_plan guarantees a valid size index by
         * construction (worst case idx=0 -> 1-word burst), so the chip-level constraint that a
         * burst must not cross a 1K address boundary is satisfied without any error path. */
        while ((remaining_size > 0) && (ret_val == MARS_E_OK))
        {
            const uint32 size_array_idx = mars_l1_burst_plan(hw_max_idx, remaining_size, current_src);

            ret_val = mars_l1_read_mem_unsafe_block(mars_self, current_src, &dst[current_dst_idx], size_array_idx, crc_ctrl); /* polyspace RTE:OVFL [Not a defect:Medium] "The operation based on validated input parameters to be within bounds at the caller functions" */

            if (ret_val == MARS_E_OK)
            {
                current_dst_idx += SSI_DATA_LEN_MAP[size_array_idx]; /* polyspace RTE:OVFL [Not a defect:Medium] "The operation based on validated input parameters to be within bounds at the caller functions" */
                remaining_size -= SSI_DATA_LEN_MAP[size_array_idx]; /* polyspace RTE:OVFL [Not a defect:Medium] "The operation based on validated input parameters to be within bounds at the loop condition entrance" */
                current_src += (SSI_DATA_LEN_MAP[size_array_idx] << 2); /* polyspace RTE:OVFL [Not a defect:Medium] "The operation based on validated input parameters to be within bounds at the caller functions" */
                crc_ctrl = MARS_L1_SSI_KEEP_CRC;
            }
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MEM, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         Write Mars memory without checking the integrity of the written values
 * @param[in]     mars_self the Mars instance
 * @param[in]     src array of 32bits data  to be written to Mars memory
 * @param[in]     dst Mars memory starting address for the write operation
 * @param[in]     size number of 32 bits values tobe written
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-344794 GID-344179
 */
static Mars_ReturnType mars_l1_write_mem_unsafe(mars_instance_t *const mars_self, const uint32 *const src, uint32 dst, const uint32 size)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    const mars_l0_ssi_t *const ssi_driver = mars_self->Mars_Drivers.Mars_SSI_Driver; 

    if ((ssi_driver != NULL_PTR) &&
            (ssi_driver->get_mode != NULL_PTR) && /* polyspace RTE:NIP [Not a defect:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */
            (src != NULL_PTR) &&
            ((dst + (size << 2)) <= MARS_MAX_ADDR) && (size > 0)) /* polyspace RTE:OVFL [Not a defect:Medium] "The operation based on validated input parameters to be within bounds at the caller functions" */
    {
        uint32 current_dst = dst;
        uint32 current_src_idx = 0;
        uint32 remaining_size = size;
        mars_ssi_crc_reset_en crc_ctrl = MARS_L1_SSI_RESET_CRC;
        mars_l0_ssi_mode_en l0_mode = L0_SSI_MODE_SPI;

        (void)ssi_driver->get_mode(MARS_L0_DRIVER_DATA(mars_self), &l0_mode); /* polyspace RTE:COR [No action planned:Low] "Pointer to the driver function. It is obtained from the API instance parameter and checked against NULL_PTR */

        const uint32 hw_max_idx = mars_l1_get_max_size(l0_mode, dst, MARS_OPERATION_WRITE);

        /* Each iteration issues exactly one burst sized to fit in the remaining transfer and the
         * current 1K (1024-byte) region. mars_l1_burst_plan guarantees a valid size index by
         * construction (worst case idx=0 -> 1-word burst), so the chip-level constraint that a
         * burst must not cross a 1K address boundary is satisfied without any error path. */
        while ((remaining_size > 0) && (ret_val == MARS_E_OK))
        {
            const uint32 size_array_idx = mars_l1_burst_plan(hw_max_idx, remaining_size, current_dst);

            ret_val = mars_l1_write_mem_unsafe_block(mars_self, &src[current_src_idx], current_dst, size_array_idx, crc_ctrl); /* polyspace RTE:OVFL [Not a defect:Medium] "The operation based on validated input parameters to be within bounds at the caller functions" */

            if (ret_val == MARS_E_OK)
            {
                current_src_idx += SSI_DATA_LEN_MAP[size_array_idx]; /* polyspace RTE:OVFL [Not a defect:Medium] "The operation based on validated input parameters to be within bounds at the caller functions" */
                remaining_size -= SSI_DATA_LEN_MAP[size_array_idx];  /* polyspace RTE:OVFL [Not a defect:Medium] "The operation based on validated input parameters to be within bounds at the loop condition entry" */
                current_dst += (SSI_DATA_LEN_MAP[size_array_idx] << 2);/* polyspace RTE:OVFL [Not a defect:Medium] "The operation based on validated input parameters to be within bounds at the caller functions" */
                crc_ctrl = MARS_L1_SSI_KEEP_CRC;
            }
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MEM, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         calculate 2 bits parity of the 16bits address value
 * @param[in]     address 16bits value for calculating parity
 * @return        calculated parity, for lower and higher byte on the two last bits
 * @design        GID-347135 GID-346911 GID-346913
 */
static uint32 mars_l1_ssi_addr_parity(const uint16 address)
{
    uint32 p0 = (uint32)address & 0x00FFuL;                  /* Parity for lower 8 bits */
    uint32 p1 = ((uint32)address & 0xFF00uL) >> MARS_8_BITS; /* Parity for upper 8 bits */
    p0 ^= p0 >> MARS_4_BITS;
    p0 &= 0x0FuL;
    p0 = (MARS_PARITY_LUT_4BIT >> p0) & 1uL;

    p1 ^= p1 >> MARS_4_BITS;
    p1 &= 0x0FuL;
    p1 = (MARS_PARITY_LUT_4BIT >> p1) & 1uL;
    p1 <<= 1;
    return ~(p0 | p1) & 0x03uL;
}

/**
 * @brief         calculates the maximum number of data words that can be read/ written from Mars in a given SSI mode
 * @param[in]     mode SSI mode (SPI or QSPI)
 * @param[in]     address target address for the read/write operation
 * @param[in]     operation operation type (read or write)
 * @return        maximum size of SSI data transfer in read direction
 * @design        GID-474890 GID-474892 GID-474891
 */
static uint32 mars_l1_get_max_size(const mars_l0_ssi_mode_en mode, const uint32 address, const mars_operation_en operation)
{
    uint32 max_size = 0u;
    if((address <= MARS_REGISTER_BANK_END) && (address >= MARS_REGISTER_BANK_START))
    {
        /* For register access, the maximum transfer size is 1 words for both SPI and QSPI modes, due to the silicon limitation of the current Mars design. */
        max_size = 0;
    }
    else
    {
        /* For memory access, the maximum transfer size depends on the SSI mode. */
        if(operation == MARS_OPERATION_WRITE)
        {
             max_size = ((mode == L0_SSI_MODE_QSPI) ? MAX_WR_SIZE_IDX_QSPI : MAX_WR_SIZE_IDX_SPI);
        }
        else
        {
            max_size = ((mode == L0_SSI_MODE_QSPI) ? MAX_RD_SIZE_IDX_QSPI : MAX_RD_SIZE_IDX_SPI);
        }
    }
    return max_size;
}

/**
 * @brief         Choose the largest SSI burst size index that fits in the remaining transfer
 *                and does not cross a 1K (1024-byte) address boundary.
 * @param[in]     hw_max_idx maximum SSI burst size index allowed by the current SSI mode and target address
 * @param[in]     remaining_words number of 32-bit words still to be transferred (must be > 0 when called)
 * @param[in]     current_addr current target byte address (word-aligned)
 * @return        a size index in [0..hw_max_idx]. Index 0 corresponds to a 1-word burst and is
 *                always a valid fallback because words_until_1k >= 1 and remaining_words >= 1.
 * @design        GID-506625
 */
static uint32 mars_l1_burst_plan(const uint32 hw_max_idx, const uint32 remaining_words, const uint32 current_addr)
{
    /* Bytes left in the current 1K region, converted to 32-bit words. Range: [1 .. 256]. */
    const uint32 words_until_1k = (MARS_ADDR_1K_BYTES_SIZE - (current_addr & MARS_ADDR_1K_BYTES_MASK)) >> 2u;
    uint32 idx = hw_max_idx;

    /* Walk down from the largest legal index until both constraints are satisfied. The loop
     * always terminates: at idx==0 SSI_DATA_LEN_MAP[0]==1, words_until_1k>=1, remaining_words>=1. */
    while ((idx > 0u) &&
           ((SSI_DATA_LEN_MAP[idx] > remaining_words) ||
            (SSI_DATA_LEN_MAP[idx] > words_until_1k)))
    {
        idx--;
    }

    return idx;
}

/**
 * @brief         Read Mars memory without check of the integrity of the read values
 * @param[in]     mars_self pointer to mars instance structure
 * @param[in]     src Mars memory starting address for the read operation
 * @param[out]    dst array of 32bits data  to be read from Mars memory
 * @param[in]     r_size number of 32bits words to be read from Mars
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-344341 GID-344726
 */
Mars_ReturnType mars_l1_read_mem_raw( mars_instance_t *const mars_self, const uint32 src, uint32 *const dst, const uint32 r_size)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    
    if (mars_self != NULL_PTR)
    {   
            /* Read-back shall not be integrity checked. We pass the request to the unsafe interface. */
            ret_val = mars_l1_read_mem_unsafe(mars_self, src, dst, r_size);
            
    }
    else
    { /* polyspace RTE:UNR [Not a defect:Low] "Null pointer check for unit level testability" */
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MEM_RAW, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         Read Mars memory with check of the integrity of the read values
 * @param[in]     mars_self pointer to mars instance structure
 * @param[in]     src Mars memory starting address for the read operation
 * @param[out]    dst array of 32bits data  to be read from Mars memory
 * @param[in]     r_size number of 32bits words to be read from Mars
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-477494 GID-477559
 */
Mars_ReturnType mars_l1_read_mem_raw_check( mars_instance_t *const mars_self, const uint32 src, uint32 *const dst, const uint32 r_size)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    
    if (mars_self != NULL_PTR)
    {   
        uint32 remaining = r_size ;
        uint32 current_dst_idx = 0;
        uint32 current_src = src;
        uint32 chunk_size = 0u ;

        do{
            if (remaining > MARS_MAX_MEMORY_BLOCK_SIZE_WORDS)
            {
                chunk_size = MARS_MAX_MEMORY_BLOCK_SIZE_WORDS;
            }
            else
            {
                chunk_size = remaining;
            }
            /* Read-back shall not be integrity checked. We pass the request to the unsafe interface. */
            ret_val = mars_l1_read_mem_unsafe(mars_self, current_src, &dst[current_dst_idx], chunk_size);
            if (ret_val == MARS_E_OK)
            {
                uint32 crc_in_host = 0u;

                ret_val = mars_calculate_crc(mars_self, &dst[current_dst_idx], chunk_size * sizeof(uint32), &crc_in_host);

                if (ret_val == MARS_E_OK)
                {
                    /* The hardware supports the SSI CRC */
                    uint32 crc_in_mars = 0xAA55u;
                    ret_val = mars_read_reg_raw(mars_self, MARS_F_CPU_SYS_OUT_CRC_CH0, &crc_in_mars);
                    /* XOR the CRC output*/
                    crc_in_mars ^= CRC_OUTPUT_XOR_VAL;
                    /* Compare CRC values from host and from Mars, then report mismatch if they differ */
                    if ((ret_val == MARS_E_OK) && (crc_in_mars != crc_in_host))
                    {
                        mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_MEM_RAW, MARS_L1_E_NOT_OK_MISMATCH);
                    }
                }
            }
             /* Move pointer forward */
            current_src += (chunk_size * sizeof(uint32));
            current_dst_idx += chunk_size;

            /* Reduce remaining */
            remaining -= chunk_size;
        
        }while((ret_val == MARS_E_OK) && (remaining > 0)); /* For read operations, if the size is larger than the read-back limit, we perform CRC check instead of read-back. In this case, we loop back to the unsafe read after calculating CRC to maintain the timing consistency between safe and unsafe check for different sizes. */
    }
    else
    { /* polyspace RTE:UNR [Not a defect:Low] "Null pointer check for unit level testability" */
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MEM_RAW, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         Verify written memory block CRC via mailbox command
 * @param[in]     mars_self pointer to mars instance structure
 * @param[in]     current_dst Mars memory starting address for the written block
 * @param[in]     chunk_size number of 32-bit words in the block
 * @param[in]     crc_in_host CRC value calculated on the host for the written data
 * @return        MARS_E_OK if successful, error code otherwise
 * @design        GID-517743 GID-517748
 */
static Mars_ReturnType mars_l1_write_mem_mlbx_crc_check( mars_instance_t *const mars_self, const uint32 current_dst, const uint32 chunk_size, const uint32 crc_in_host)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    mars_mailbox_req_t mlbx_crc_request = {0};
    mars_mailbox_resp_t mlbx_crc_response = {0};
    uint32 crc_in_mars = 0u;

    mlbx_crc_request.slot = MARS_MLBX_SLOT_GEN_CMD;
    mlbx_crc_request.var_h = current_dst >> 2;
    mlbx_crc_request.var_l = chunk_size;
    mlbx_crc_request.command = MARS_MLBX_CMD_ML_CHECK_CRC;

    ret_val = mars_exchange_mlbx(mars_self, &mlbx_crc_request, &mlbx_crc_response, MARS_MLBX_TIMEOUT_US);

    crc_in_mars = ((uint32)((uint32)mlbx_crc_response.var_l & MARS_MLBX_CRC_VAR_MASK) << MARS_MLBX_CRC_VAR_SHFT) | (uint32)(mlbx_crc_response.var_h & MARS_MLBX_CRC_VAR_MASK);

    if ((ret_val == MARS_E_OK) && (crc_in_mars != crc_in_host))
    {
        mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_MEM_RAW, MARS_L1_E_MEM_WRITE_MISMATCH_MLBX);
    }

    return ret_val;
}

/**
 * @brief         Write Mars memory with optional check of the integrity of the written values for <=4 words
 * @param[in]     mars_self pointer to mars instance structure
 * @param[in]     src array of 32bits data  to be written to Mars memory
 * @param[in]     dst Mars memory starting address for the write operation
 * @param[in]     w_size number of 32 bits values tobe written, <=4
 * @param[in]     chk control if integrity check shall be performed
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-517744 GID-517747
 */
Mars_ReturnType mars_l1_write_mem_raw_lt4( mars_instance_t *const mars_self, const uint32 *const src, const uint32 dst, const uint32 w_size, const mars_safe_chk_en chk)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    ret_val = mars_l1_write_mem_unsafe(mars_self, src, dst, w_size);
    if ((ret_val == MARS_E_OK) && ((chk == MARS_L1_SAFE_CHK) || (chk == MARS_L1_SAFE_CHK_MLBX)))
    {
        /* read back a limited amount of data to the host memory and compare it to the intended values */
        uint32 readback_buffer[MARS_MEM_WR_READBACK_LIMIT] = {0};
        ret_val = mars_l1_read_mem_unsafe(mars_self, dst, readback_buffer, w_size);
        if (ret_val == MARS_E_OK)
        {
            for (uint32 readback_cmp_idx = 0; readback_cmp_idx < w_size; readback_cmp_idx++)
            {
                /* report mismatch if any of the read back values differ from the expected one */
                if (readback_buffer[readback_cmp_idx] != src[readback_cmp_idx]) /* polyspace RTE:IDP [Justified:Low] "All callers guarantee src buffer size >= w_size; validated at API boundary" */
                {
                    mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_MEM_RAW, MARS_L1_E_MEM_WRITE_MISMATCH);
                    break;
                }
            }
        }
    }
    return ret_val;
}

/**
 * @brief         Write Mars memory with optional check of the integrity of the written values for > 4 words
 * @param[in]     mars_self pointer to mars instance structure
 * @param[in]     src array of 32bits data  to be written to Mars memory
 * @param[in]     dst Mars memory starting address for the write operation
 * @param[in]     w_size number of 32 bits values tobe written, > 4 and <= MARS_MAX_MEMORY_BLOCK_SIZE_WORDS
 * @param[in]     chk control if integrity check shall be performed
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-517745 GID-517746
 */
static Mars_ReturnType mars_l1_write_mem_raw_mt4( mars_instance_t *const mars_self, const uint32 *const src, const uint32 dst, const uint32 w_size, const mars_safe_chk_en chk)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    ret_val = mars_l1_write_mem_unsafe(mars_self, src, dst, w_size);
    if ((ret_val == MARS_E_OK) && ((chk == MARS_L1_SAFE_CHK) || (chk == MARS_L1_SAFE_CHK_MLBX)))
    {
        /* CRC check for writes larger than MARS_MEM_WR_READBACK_LIMIT words.
         * Calculate host CRC once, then reuse it for SSI and optional mailbox checks.
         */
        uint32 crc_in_host = 0u;

        ret_val = mars_calculate_crc(mars_self, src, w_size * sizeof(uint32), &crc_in_host);

        if (ret_val == MARS_E_OK)
        {
            uint32 crc_in_mars = 0xAA55u;

            /* Read SSI CRC before any mailbox CRC command:
             * mailbox commands can overwrite MARS_F_CPU_SYS_OUT_CRC_CH0.
             */
            ret_val = mars_read_reg_raw(mars_self, MARS_F_CPU_SYS_OUT_CRC_CH0, &crc_in_mars);
            /* XOR the CRC output*/
            crc_in_mars ^= CRC_OUTPUT_XOR_VAL;

            /* Compare CRC values from host and from Mars, then report mismatch if they differ */
            if ((ret_val == MARS_E_OK) && (crc_in_mars != crc_in_host))
            {
                mars_set_l1_error_information(&ret_val, (uint32)mars_self->Mars_Instance_Id, MARS_ERROR_L1_MEM_RAW, MARS_L1_E_MEM_WRITE_MISMATCH);
            }
            if ((ret_val == MARS_E_OK) && (chk == MARS_L1_SAFE_CHK_MLBX))
            {
                ret_val = mars_l1_write_mem_mlbx_crc_check(mars_self, dst, w_size, crc_in_host);
            }
        }
    }

    return ret_val;
}

/**
 * @brief         Write Mars memory with optional check of the integrity of the written values
 * @param[in]     mars_self pointer to mars instance structure
 * @param[in]     src array of 32bits data  to be written to Mars memory
 * @param[in]     dst Mars memory starting address for the write operation
 * @param[in]     w_size number of 32 bits values tobe written
 * @param[in]     chk control if integrity check shall be performed
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-344735 GID-344740
 */
Mars_ReturnType mars_l1_write_mem_raw( mars_instance_t *const mars_self, const uint32 *const src, const uint32 dst, const uint32 w_size, const mars_safe_chk_en chk)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if ((mars_self != NULL_PTR) && (src != NULL_PTR) && (w_size > 0u) && (w_size <= (uint32)(MARS_FIRMWARE_MAX_SIZE / sizeof(uint32))))
    {   
        if (w_size <= MARS_MEM_WR_READBACK_LIMIT)
        {
            ret_val = mars_l1_write_mem_raw_lt4(mars_self, src, dst, w_size, chk);

            /* MLBX check requires CRC even if the data size is smaller */
            if ((ret_val == MARS_E_OK) && (chk == MARS_L1_SAFE_CHK_MLBX))
            {
                uint32 crc_in_host = 0u;
                ret_val = mars_calculate_crc(mars_self, src, w_size * sizeof(uint32), &crc_in_host);
                if (ret_val == MARS_E_OK)
                {
                    ret_val = mars_l1_write_mem_mlbx_crc_check(mars_self, dst, w_size, crc_in_host);
                }
            }
        }
        else
        {
            uint32 remaining = w_size ;
            uint32 current_dst = dst;
            uint32 current_src_idx = 0;
            uint32 chunk_size = 0u ;

            do{
                if (remaining > MARS_MAX_MEMORY_BLOCK_SIZE_WORDS)
                {
                    chunk_size = MARS_MAX_MEMORY_BLOCK_SIZE_WORDS;
                }
                else
                {
                    chunk_size = remaining;
                }

                ret_val = mars_l1_write_mem_raw_mt4(mars_self, &src[current_src_idx], current_dst, chunk_size, chk);

                /* Move pointer forward */
                current_src_idx += chunk_size ;
                current_dst += (chunk_size * sizeof(uint32)); /* polyspace RTE:OVFL [Not a defect:Medium] "The operation based on validated input parameters to be within bounds at the caller functions" */
                /* Reduce remaining */
                remaining -= chunk_size;

            }while((ret_val == MARS_E_OK) && (remaining > 0)); /* For write operations, if the size is larger than the read-back limit, we perform CRC check instead of read-back. In this case, we loop back to the unsafe write after calculating CRC to maintain the timing consistency between safe and unsafe check for different sizes. */
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_MEM_RAW, MARS_L1_E_NOT_OK_PARAM);
    }
    return ret_val;
}
