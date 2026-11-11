/**
 * @file mars_scratchpad_config.h
 *
 *
 * @date    date created:   09-01-2024
 *
 *  THIS IS A GENERATED FILE! DO NOT EDIT!
 *------------------------------------------------------------------------------
 *
 * @copyright 2024 indie Semiconductor.
 *
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Seminconductor
 *
 *------------------------------------------------------------------------------
 */

#ifndef MARS_SCP_CONFIG_H
#define MARS_SCP_CONFIG_H

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include "mars_public_types.h"

#define MARS_SCRATCHPAD_CFG_START_ADDRESS    (0x20000u)
#define MARS_SCRATCHPAD_SIZE                 (sizeof(mars_scratchpad_cfg_t))
#define MARS_MLBX_CMD_CFG_VERSION        (3u)
#define MARS_MIPI_MEDATA_NO_OF_WORDS         (16u)

#define MARS_VALID_1_RFDIST_MODE_VALID          0u
#define MARS_VALID_1_IFVGA_HPF_VALID            1u
#define MARS_VALID_1_TX_PH_MODE_VALID           2u
#define MARS_VALID_1_TX_OFF_OFFSET_VALID        3u
#define MARS_VALID_1_TX_ON_OFFSET_VALID         4u
#define MARS_VALID_1_TX_SEQ_OFFSET_VALID        5u
#define MARS_VALID_1_RX_EN_MODE_VALID           6u
#define MARS_VALID_1_TX_EN_MODE_VALID           7u
#define MARS_VALID_1_RX_ADC_MODE_VALID          8u
#define MARS_VALID_1_RX_OFF_OFFSET_VALID        9u
#define MARS_VALID_1_RX_ON_OFFSET_VALID         10u
#define MARS_VALID_1_RX_SEQ_OFFSET_VALID        11u
#define MARS_VALID_1_META_MODE_VALID            12u
#define MARS_VALID_1_RX_ADC_SAMP_FRQ_VALID      13u
#define MARS_VALID_1_TX_POWER_VALID             14u
#define MARS_VALID_1_RX_GAIN_MIXER_VALID        15u
#define MARS_VALID_1_RX_GAIN_IFVGA_VALID        16u
#define MARS_VALID_1_RX_IFVGA_STAGE_1_VALID     17u
#define MARS_VALID_1_PRF_MIMO_VALID             18u
#define MARS_VALID_1_MIPI_DATA_LANES_VALID      19u
#define MARS_VALID_1_MIPI_DATA_RATE_VALID       20u
#define MARS_VALID_1_FRM_REPIT_CHIRP_VALID      21u
#define MARS_VALID_1_FRM_NUM_CHIRP_VALID        22u
#define MARS_VALID_1_VERSION_VALID              23u
#define MARS_VALID_1_PRF_END_PTR_T0_VALID       24u
#define MARS_VALID_1_PRF_START_PTR_T0_VALID     25u
#define MARS_VALID_1_PRF_START_PTR_T1_VALID     26u
#define MARS_VALID_1_MIPI_POWER_MODE_VALID      27u
#define MARS_VALID_1_ZHV_GENERATION_MODE_VALID  28u
#define MARS_VALID_1_SAFETY_CHIRPS_FS_VALID     29u
#define MARS_VALID_1_BIAS_NOISE_FILTER_VALID    30u
#define MARS_VALID_1_UNUSED                     31u /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "SCP valid field is reserved for future use" */


typedef uint32 mars_valid_1_t;

typedef struct
{
    uint32 mipi_metadata_valid : 16;
    uint32 valid_2_unused : 16;
} mars_valid_2_t;

typedef struct
{
    uint32 valid_3_unused : 32;
} mars_valid_3_t;

typedef struct
{
    uint32 rfdist_mode : 2;
    uint32 ifvga_hpf_mode : 2;
    uint32 tx_ph_mode : 3;
    uint32 tx_off_offset : 9;
    uint32 tx_on_offset : 8;
    uint32 tx_seq_offset : 8;
} mars_tx_ops_t;

typedef struct
{
    uint32 rx_en_mode : 1;
    uint32 tx_en_mode : 1;
    uint32 rx_ifvga_stage : 1;
    uint32 rx_ops_unused : 1;
    uint32 rx_adc_mode : 3;
    uint32 rx_off_offset : 9;
    uint32 rx_on_offset : 8;
    uint32 rx_seq_offset : 8;
} mars_rx_ops_t;

typedef struct
{
    uint32 meta_mode : 4;
    uint32 rx_adc_samp_frq : 4;
    uint32 tx_power : 8;
    uint32 rx_gain_ifvga : 8;
    uint32 rx_gain_mixer : 8;
} mars_gains_t;

typedef struct
{
    uint32 frame_1_unused_1 : 1;
    uint32 prf_mimo : 1;
    uint32 mipi_data_lanes : 2;
    uint32 mipi_data_rate : 3;
    uint32 frm_repit_chirp : 8;
    uint32 version : 4;
    uint32 frm_num_chirp : 12;
    uint32 frame_1_unused_2 : 1;
} mars_frame_1_t;

typedef struct
{
    uint32 prf_end_ptr_t0 : 16;
    uint32 prf_start_ptr_t0 : 16;
} mars_frame_2_t;

typedef struct
{
    uint32 prf_start_ptr_t1 : 16;
    uint32 mipi_power_mode : 2;
    uint32 zhv_generation_mode : 2;
    uint32 bias_noise_filter : 1;
    uint32 frame_3_unused : 11;
} mars_frame_3_t;

typedef struct
{
    uint32 safety_chirps_fs : 24;
    uint32 frame_4_unused : 8;
} mars_frame_4_t;

typedef uint32 mars_mipi_metadata_diag_t;

typedef uint32 unused_t;

typedef struct
{
    mars_valid_1_t valid_1;
    mars_valid_2_t valid_2;
    mars_valid_3_t valid_3;
    mars_tx_ops_t tx_ops;
    mars_rx_ops_t rx_ops;
    mars_gains_t gains;
    mars_frame_1_t frame_1;
    mars_frame_2_t frame_2;
    mars_frame_3_t frame_3;
    mars_frame_4_t frame_4;
    unused_t unused_0;
    unused_t unused_1;
    unused_t unused_2;
    unused_t unused_3;
    unused_t unused_4;
    unused_t unused_5;
    mars_mipi_metadata_diag_t mipi_metadata[MARS_MIPI_MEDATA_NO_OF_WORDS];
} mars_scratchpad_cfg_t;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#endif
