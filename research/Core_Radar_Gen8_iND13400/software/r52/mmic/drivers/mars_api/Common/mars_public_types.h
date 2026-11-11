/*===========================================================================*/
/**
 * @file mars_public_types.h
 * @brief Header file defining public types for the MARS API.
 *
 * This file contains type definitions, enumerations, and macros used in the MARS API.
 * It provides the necessary data structures and constants for interacting with the MARS system.
 *
 * @date    Date created:   06-09-2023
 *
 *------------------------------------------------------------------------------
 *
 * @copyright 2023 indie Semiconductor.
 *
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor.
 *
 *------------------------------------------------------------------------------
 */

#ifndef MARS_PUBLIC_TYPES_H
#define MARS_PUBLIC_TYPES_H

#include "Platform_Types.h"
#include "mars_cfg.h"

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

/** @def ADC0
 *  @brief ADC channel 0
 */
#ifndef ADC0
#define ADC0 (0U)
#endif

/** @def ADC1
 *  @brief ADC channel 1
 */
#ifndef ADC1
#define ADC1 (1U)
#endif

/** @def ADC2
 *  @brief ADC channel 2
 */
#ifndef ADC2
#define ADC2 (2U)
#endif

/** @def ADC3
 *  @brief ADC channel 3
 */
#ifndef ADC3
#define ADC3 (3U)
#endif

/** @def CW_MODE_CONT
 *  @brief Continuous wave mode
 */
#ifndef CW_MODE_CONT
#define CW_MODE_CONT (0U)
#endif

/** @def CW_MODE_TRIG
 *  @brief Triggered CW mode
 */
#ifndef CW_MODE_TRIG
#define CW_MODE_TRIG (1U)
#endif

/**
 * @defgroup MARS_DRIVER_STATUS_VALUES Radar API Status Values
 * @brief Bitmask values for mars_driver_status_t
 * @details These macros define the valid status values for the Radar API driver state.
 *          Currently only one bit is set at a time, but the bitmask design
 *          allows for future extensions where multiple states may be valid
 *          simultaneously.
 * @{
 */

/** @def MARS_UNINTIALIZED
 *  @brief Uninitialized state
 *  @details Value: 1 (bit 0). The Radar API driver is not operational, mars_init or
 *           mars_init_debug shall be called first.
 *  @relates mars_driver_status_t
 */
#define MARS_UNINTIALIZED (1u << 0u)

/** @def MARS_INITIALIZED_FW_NOT_RUNNING
 *  @brief Initialized but firmware not running
 *  @details Value: 2 (bit 1). The host side Radar API driver has been initialized,
 *           but the MAF has not been uploaded and/or activated yet.
 *  @relates mars_driver_status_t
 */
#define MARS_INITIALIZED_FW_NOT_RUNNING (1u << 1u)

/** @def MARS_INIT_IDLE_OPERATIONAL
 *  @brief Idle operational state
 *  @details Value: 4 (bit 2). The Radar API driver is operational and ready to accept
 *           new commands.
 *  @relates mars_driver_status_t
 */
#define MARS_INIT_IDLE_OPERATIONAL (1u << 2u)

/** @def MARS_DRIVER_ERROR
 *  @brief Driver error state
 *  @details Value: 8 (bit 3). Radar API driver has detected an unrecoverable error.
 *  @relates mars_driver_status_t
 */
#define MARS_DRIVER_ERROR (1u << 3u)

/** @def MARS_BUSY
 *  @brief Busy state
 *  @details Value: 16 (bit 4). Radar API driver is busy processing a request frame.
 *           The status will return to MARS_INIT_IDLE_OPERATIONAL after
 *           receiving the frame completion response from Mars.
 *  @relates mars_driver_status_t
 */
#define MARS_BUSY (1u << 4u)

/** @} */ /* End of MARS_DRIVER_STATUS_VALUES group */

/**
 * @def MCU_NO_STATUS
 * @brief No status available
 */
#define MCU_NO_STATUS (0u << 0u) 

/**
 * @def MCU_RDR_READY
 * @brief Radar ready
 */
#define MCU_RDR_READY (1u << 0u) /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "MCU STATUS bit fields, used in the host application" */

/**
 * @def MCU_SFT_ERROR
 * @brief Safety error
 */
#define MCU_SFT_ERROR (1u << 1u) /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "MCU STATUS bit fields, used in the host application" */

/**
 * @def MCU_DET_SFT_ERROR
 * @brief Error detected by safety task
 */
#define MCU_DET_SFT_ERROR (1u << 2u) /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "MCU STATUS bit fields, used in the host application" */

/**
 * @def MCU_IDLE
 * @brief Radar status IDLE
 */
#define MCU_IDLE (1u << 3u) /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "MCU STATUS bit fields, used in the host application" */

/**
 * @def MCU_POWER_UP
 * @brief Radar status POWER UP
 */
#define MCU_POWER_UP (1u << 4u) /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "MCU STATUS bit fields, used in the host application" */

/**
 * @def MCU_FRAME_RUN
 * @brief Radar status FRAME RUN
 */
#define MCU_FRAME_RUN (1u << 5u) /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "MCU STATUS bit fields, used in the host application" */

/**
 * @def MCU_SAFETY
 * @brief Radar status SAFETY
 */
#define MCU_SAFETY (1u << 6u) /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "MCU STATUS bit fields, used in the host application" */

/**
 * @def MCU_POWER_DOWN
 * @brief Radar status POWER DOWN
 */
#define MCU_POWER_DOWN (1u << 7u) /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "MCU STATUS bit fields, used in the host application" */

/**
 * @def MCU_FRAME_DELAY
 * @brief Radar status FRAME DELAY
 */
#define MCU_FRAME_DELAY (1u << 8u) /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "MCU STATUS bit fields, used in the host application" */

/**
 * @def MCU_UNUSED
 * @brief UNUSED
 */
#define MCU_UNUSED (1u << 9u) /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "MCU STATUS bit fields, used in the host application" */

/**
 * @def MCU_RDR_MSSG
 * @brief Radar message
 */
#define MCU_RDR_MSSG (1u << 10u) /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "MCU STATUS bit fields, used in the host application" */

/**
 * @def PROFILE_TABLE_0_NO_OF_WORDS
 * @brief Profile Table 0
 */
#define PROFILE_TABLE_0_NO_OF_WORDS (4u)

/**
 * @def PROFILE_TABLE_1_NO_OF_WORDS
 * @brief Profile Table 1
 */
#define PROFILE_TABLE_1_NO_OF_WORDS (2u)

/**
 * @def PHASE_LUT_NO_OF_ENTRIES
 * @brief Phase LUT
 */
#define PHASE_LUT_NO_OF_ENTRIES (512u)

/**
 * @def CALIBRATION_CONTROL_NO_OF_WORDS
 * @brief Calibration Control see Mars-IO-297
 */
#define CALIBRATION_CONTROL_NO_OF_WORDS (3u)

/**
 * @def MARS_NO_DATA
 * @brief Mars no data available  
 */
#define MARS_NO_DATA (0U)

/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/
/**
 * @enum mars_diag_health_state_t
 * @brief Enumeration for Diagnostic value health state.
 * @design GID-350418
 */
typedef enum
{
    MARS_VAL_FRESH, /*!< Value has been updated since the last read request */
    MARS_VAL_STALE, /*!< Value has not been updated since the last read request */
    MARS_VAL_BAD    /*!< Integrity of the retrieved value is compromised */
} mars_diag_health_state_t;

/**
 * @struct mars_api_sw_version_t
 * @brief Structure for API software version.
 * @design GID-350175
 */
typedef struct
{
    uint8 major; /*!< Major version */
    uint8 minor; /*!< Minor version */
    uint8 patch; /*!< Patch version */
} mars_api_sw_version_t;

/**
 * @struct mars_pt_word_5_t
 * @brief Structure for profiler table 5th entry. Part of to Profiler Table 1.
 * @design GID-349527
 */
typedef struct
{
    uint32 NumSamp : 12; /*!< Number of samples */
    uint32 HPF1 : 2;     /*!< High-pass filter 1 */
    uint32 HPF2 : 4;     /*!< High-pass filter 2 */
    uint32 DEC : 4;      /*!< Decimation factor */
    uint32 Te : 10;      /*!< Time extension */
} mars_pt_word_5_t;

/**
 * @struct mars_pt_word_4_t
 * @brief Structure for profiler table 4th entry. Part of to Profiler Table 1.
 * @design GID-349527
 */
typedef struct
{
    uint32 Slope : 10;          /*!< Slope */
    uint32 VC : 2;              /*!< Voltage control */
    uint32 AsyncFIFOThresh : 5; /*!< Asynchronous FIFO threshold */
    uint32 Tr : 15;             /*!< Time resolution */
} mars_pt_word_4_t;

/**
 * @struct mars_pt_word_3_t
 * @brief Structure for profiler table 3rd entry. Part of to Profiler Table 0.
 * @design GID-349527
 */
typedef struct
{
    uint32 TxPhase3 : 9; /*!< Transmit phase 3 */
    uint32 : 23;         /*!< Reserved */
} mars_pt_word_3_t;

/**
 * @struct mars_pt_word_2_t
 * @brief Structure for profiler table 2nd entry. Part of to Profiler Table 0.
 * @design GID-349527
 */
typedef struct
{
    uint32 ChirpMode : 2; /*!< Chirp mode */
    uint32 T1Ptr : 3;     /*!< T1 pointer */
    uint32 TxPhase0 : 9;  /*!< Transmit phase 0 */
    uint32 TxPhase1 : 9;  /*!< Transmit phase 1 */
    uint32 TxPhase2 : 9;  /*!< Transmit phase 2 */
} mars_pt_word_2_t;

/**
 * @struct mars_pt_word_1_t
 * @brief Structure for profiler table 1st entry. Part of to Profiler Table 0.
 * @design GID-349527
 */
typedef struct
{
    uint32 Td : 16;  /*!< Time delay */
    uint32 Ts : 11;  /*!< Time start */
    uint32 : 1;      /*!< Reserved */
    uint32 TxEn : 4; /*!< Transmit enable */
} mars_pt_word_1_t;

/**
 * @struct mars_pt_word_0_t
 * @brief Structure for profiler table 0th entry. Part of to Profiler Table 0.
 * @design GID-349527
 */
typedef struct
{
    uint32 Fs : 24;       /*!< Frequency start */
    uint32 RxEnAntAB : 8; /*!< Receive enable antenna A and B */
} mars_pt_word_0_t;

/**
 * @union mars_pt0_t
 * @brief Union for profiler table 0.
 * @design GID-349527
 */
typedef union { /* polyspace MISRA-C-2023:19.2 [No action planned:Low] "Union keyword required by the design of the profile table access" */
    uint32 raw[PROFILE_TABLE_0_NO_OF_WORDS]; /*!< Raw data */
    struct
    {
        mars_pt_word_0_t t0_0; /*!< Table 0 entry 0 */
        mars_pt_word_1_t t0_1; /*!< Table 0 entry 1 */
        mars_pt_word_2_t t0_2; /*!< Table 0 entry 2 */
        mars_pt_word_3_t t0_3; /*!< Table 0 entry 3 */
    } s;                  /*!< Structured data */
} mars_pt0_t;

/**
 * @union mars_pt1_t
 * @brief Union for profiler table 1.
 * @design GID-349527
 */
typedef union { /* polyspace MISRA-C-2023:19.2 [No action planned:Low] "Union keyword required by the design of the profile table access" */
    uint32 raw[PROFILE_TABLE_1_NO_OF_WORDS]; /*!< Raw data */
    struct
    {
        mars_pt_word_4_t t1_4; /*!< Table 1 entry 4 */
        mars_pt_word_5_t t1_5; /*!< Table 1 entry 5 */
    } s;                  /*!< Structured data */
} mars_pt1_t;

/** @typedef mars_firmware_data_t
 *  @brief Type for firmware data.
 *  @design GID-350331
 */
typedef uint32 mars_firmware_data_t;

/** @typedef mars_firmware_size_t
 *  @brief Type for firmware size.
 *  @design GID-350331
 */
typedef uint32 mars_firmware_size_t;

/** @typedef mars_frame_timestamp_t
 *  @brief Type for frame timestamp.
 *  @design GID-350487
 */
typedef uint64 mars_frame_timestamp_t;

/** @typedef mars_mipi_metadata_reg_t
 *  @brief Type for MIPI metadata register.
 *  @design GID-350487
 */
typedef uint16 mars_mipi_metadata_reg_t;

/** @typedef mars_fs_frequency_t
 *  @brief Type for FStart frequency
 *  @design GID-350989
 */
typedef uint32 mars_fs_frequency_t;

/**
 * @enum mars_mipi_bitrate_t
 * @brief Enumeration for MIPI bitrates supported by the MARS system.
 * @design GID-350487
 */
typedef enum
{
    MARS_MIPI_210MBPS = 0, /*!< 210 Mbps */
    MARS_MIPI_400MBPS = 1, /*!< 400 Mbps */
    MARS_MIPI_600MBPS = 2, /*!< 600 Mbps */
    MARS_MIPI_840MBPS = 3, /*!< 840 Mbps */
    MARS_MIPI_1250MBPS = 4 /*!< 1.25 Gbps */
} mars_mipi_bitrate_t;

/**
 * @enum mars_mipi_metadata_enable_t
 * @brief Enumeration for enabling MIPI metadata.
 * @design GID-350487
 */
typedef enum
{
    MARS_MIPI_METADATA_DISABLED = 0, /*!< Metadata disabled */
    MARS_MIPI_METADATA_ENABLED = 1   /*!< Metadata enabled */
} mars_mipi_metadata_enable_t;

/**
 * @enum mars_mipi_power_mode_t
 * @brief Enumeration for MIPI Power mode setting.
 * @design GID-350487
 */
typedef enum
{
    MARS_MIPI_ALWAYS_ON_NON_CONTINUOUS = 0, /*!< Always on non-continuous */
    MARS_MIPI_POWER_SAVING_NON_CONTINUOUS = 1, /*!< Power saving mode non-continuous */
    MARS_MIPI_ALWAYS_ON_CONTINUOUS = 2, /*!< Always on continuous */
    MARS_MIPI_POWER_SAVING_CONTINUOUS = 3 /*!< Power saving mode continuous */
} mars_mipi_power_mode_t;

/** @typedef mars_reg_id_t
 *  @brief Type for register ID.
 *  @design GID-347862
 */
typedef uint32 mars_reg_id_t;

/** @typedef mars_reg_value_t
 *  @brief Type for register value.
 *  @design GID-347862
 */
typedef uint32 mars_reg_value_t;

/** @typedef mars_address_t
 *  @brief Type for Mars memory address
 *  @design GID-420863
 */
typedef uint32 mars_address_t;

/** @typedef mars_value_t
 *  @brief Type for Mars memory location value.
 *  @design GID-420863
 */
typedef uint32 mars_value_t;

/** @typedef  mars_size_t
 *  @brief Type for Mars memory size.
 *  @design GID-420863
 */
typedef uint32 mars_size_t;

/** @typedef mars_rx_ifvga_gain_t
 *  @brief Type for RX IFVGA gain.
 *  @design GID-350487
 */
typedef uint8 mars_rx_ifvga_gain_t;

/** @typedef mars_rx_mixer_gain_t
 *  @brief Type for RX mixer gain.
 *  @design GID-350487
 */
typedef uint8 mars_rx_mixer_gain_t;

/** @typedef mars_tp_offset_t
 *  @brief Type for Test Pattern offset.
 *  @design GID-350990
 */
typedef uint16 mars_tp_offset_t;

/** @typedef mars_tp_pulse_threshold_t
 *  @brief Type for Test Pattern pulse threshold.
 *  @design GID-350990
 */
typedef uint16 mars_tp_pulse_threshold_t;

/** @typedef mars_tp_shift1_t
 *  @brief Type for Test Pattern shift 1.
 *  @design GID-350990
 */
typedef uint16 mars_tp_shift1_t;

/** @typedef mars_tp_shift2_t
 *  @brief Type for Test Pattern shift 2.
 *  @design GID-350990
 */
typedef uint16 mars_tp_shift2_t;

/** @typedef mars_tp_step_t
 *  @brief Type for Test Pattern step.
 *  @design GID-350990
 */
typedef uint16 mars_tp_step_t;

/* polyspace-begin Custom:6.3 [No action planned:Mid] "Starts with prefixed enum name" */
/**
 * @enum mars_activation_t
 * @brief Enumeration for activation modes.
 * @design GID-350331
 *
 */
typedef enum
{
#if defined(MARS_ALLOW_ACTIVATION_NO_CRC)
    ACTIVATE_NO_CHECK = (0U),         /*!< @deprecated Activate MAF without CRC check. Risk of starting incomplete firmware. Use ACTIVATE_CHECK_CRC instead. Requires MARS_ALLOW_ACTIVATION_NO_CRC. */
#endif /* MARS_ALLOW_ACTIVATION_NO_CRC */
    ACTIVATE_CHECK_CRC = (1U),        /*!< Activate MAF with CRC check */
} mars_activation_t;
/* polyspace-end Custom:6.3 [No action planned:Mid] "Starts with prefixed enum name" */

/**
 * @typedef mars_driver_status_t
 * @brief Type for Radar API driver status (bitmask).
 * @design GID-350175
 *
 * @details This type represents the current state of the Radar API driver.
 *          The value is a bitmask using the following status flags:
 *
 *          | Value | Macro                          | Description                                    |
 *          |-------|--------------------------------|------------------------------------------------|
 *          | 1     | MARS_UNINTIALIZED              | Radar API driver not initialized               |
 *          | 2     | MARS_INITIALIZED_FW_NOT_RUNNING| Initialized but firmware not running           |
 *          | 4     | MARS_INIT_IDLE_OPERATIONAL     | Radar API driver operational and ready         |
 *          | 8     | MARS_DRIVER_ERROR              | Unrecoverable error detected                   |
 *          | 16    | MARS_BUSY                      | Processing a frame request                     |
 *
 * @note    The type is designed as a bitmask to allow future extensions where
 *          multiple status bits may be valid simultaneously. Currently, only
 *          one status bit is set at any given time.
 *
 * @see     MARS_UNINTIALIZED
 * @see     MARS_INITIALIZED_FW_NOT_RUNNING
 * @see     MARS_INIT_IDLE_OPERATIONAL
 * @see     MARS_DRIVER_ERROR
 * @see     MARS_BUSY
 * @ingroup MARS_DRIVER_STATUS_VALUES
 */
typedef uint32 mars_driver_status_t;

/** @typedef mars_mcustatus_t
 *  @brief Type for MCU status.
 */
typedef uint32 mars_mcustatus_t;

/* polyspace-begin Custom:6.3 [No action planned:Mid] "Starts with prefixed enum name" */
/**
 * @enum mars_gp_t
 * @brief Enumeration for GP configurations.
 * @design GID-350487
 */
typedef enum
{
    GP_PMU_Ready = (0U),          /*!< PMU Ready, active high */
    GP_Frame_PowerUp = (1U),      /*!< Frame Function Phase "Power Up", active high */
    GP_Frame_Start = (2U),        /*!< Frame Function Phase "Start", active high */
    GP_Frame_Safety = (3U),       /*!< Frame Function Phase "Safety", active high */
    GP_Frame_PowerDown = (4U),    /*!< Frame Function Phase "Power Down", active high */
    GP_EN_Frame_Start = (5U),     /*!< Internal trigger indicating start of Frame preparation */
    GP_EN_Chirp_Start = (6U),     /*!< Internal trigger indicating start of chirp preparation */
    GP_EN_Sample_Start = (7U),    /*!< Sampling in progress during a chirp */
    GP_Chirp_Valid = (8U),        /*!< Internal trigger indicating the start of chirp generation */
    GP_Frame_Sync = (9U),         /*!< Frame synchronization signal pulse at Frame Start */
    GP_Synth_Lock_Signal = (10U), /*!< Synthesizer lock signal */
    GP_MCU_Radar_Ready = (11U),   /*!< MCU Radar ready */
    GP_Critical_Error = (12U),    /*!< Critical Error indication */
    GP_GPT = (13U),               /*!< Host set timer trigger */
    GP_BOR_N = (14U),             /*!< BOR_N Error indication, active low */
    GP_REF_PLL_Lock = (15U),      /*!< Ref PLL lock */
    GP_ADC_PLL_Lock = (16U),      /*!< ADC PLL lock */
    GP_MIPI_PLL_Lock = (17U),     /*!< MIPI PLL lock */
    GP_MIPI_IRQ = (18U),          /*!< MIPI IRQ assertion */
    GP_POR_08_N = (19U),          /*!< POR_N 0.8V Error indication, active low */
    GP_POR_18_N = (20U),          /*!< POR_N 1.8V Error indication, active low */
    GP_CLK_CORE = (21U),          /*!< Core Clock */
    GP_SET_HI = (22U),            /*!< Set High */
    GP_SET_LO = (23U),            /*!< Set Low */
    GP_NO_CHANGE = (24U)          /*!< No Change */
} mars_gp_t;
/* polyspace-end Custom:6.3 [No action planned:Mid] "Starts with prefixed enum name" */

/* polyspace-begin MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-begin CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */
/**
 * @struct mars_gp_config_t
 * @brief Structure defining values for both GP0 and GP1 control.
 * @design GID-350175
 */
typedef struct
{
    mars_gp_t gp0;   /*!< configuration of GP0 */
    mars_gp_t gp1;   /*!< configuration of GP1 */
} mars_gp_config_t;
/* polyspace-end MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-end CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */

/* polyspace-begin Custom:6.3 [No action planned:Mid] "Starts with prefixed enum name" */
/**
 * @enum mars_ctrlstatus_t
 * @brief Enumeration for control status.
 * @design GID-350175
 */
typedef enum
{
    CTRL_MUX_CLK_IN_NO_STATUS = 0x00u, /*!< No status available */
    CTRL_MUX_CLK_IN_EXTERNAL = 0x01u,  /*!< Mars configured to use external clock input */
    CTRL_MUX_CLK_IN_INTERNAL = 0x02u   /*!< Mars configured to use internal clock input */
} mars_ctrlstatus_t;
/* polyspace-end Custom:6.3 [No action planned:Mid] "Starts with prefixed enum name" */

/**
 * @struct mars_rdrstatus_t
 * @brief Structure for radar status.
 * @design GID-350175
 */
typedef struct
{
    uint16 sft_error;      /*!< Radar Safety Status */
    uint32 mcu_status;     /*!< Radar MCU Status */
    mars_ctrlstatus_t ctrl_status; /*!< Radar control Slave/Master */
} mars_rdrstatus_t;

/**
 * @enum mars_mipi_tx_lanes_t
 * @brief Enumeration for MIPI TX lanes.
 * @design GID-350487
 */
typedef enum
{
    MARS_LANE_1 = (0U), /*!< Single lane */
    MARS_LANE_2 = (1U), /*!< Dual lane */
    MARS_LANE_4 = (2U)  /*!< Quad lane */
} mars_mipi_tx_lanes_t;

/**
 * @enum mars_tp_ctlparsel_t
 * @brief Enumeration for TP control parallelism selection.
 * @design GID-350990
 */
typedef enum
{
    MARS_TP_PAR12 = (0U), /*!< 12-bit parallelism */
    MARS_TP_PAR14 = (1U)  /*!< 14-bit parallelism */
} mars_tp_ctlparsel_t;

/**
 * @enum mars_tp_ctlpolysel_t
 * @brief Enumeration for TP control polynomial selection.
 * @design GID-350990
 */
typedef enum
{
    MARS_TP_PRBS7 = (0U),  /*!< PRBS7 polynomial */
    MARS_TP_PRBS15 = (1U), /*!< PRBS15 polynomial */
    MARS_TP_PRBS23 = (2U), /*!< PRBS23 polynomial */
    MARS_TP_PRBS31 = (3U)  /*!< PRBS31 polynomial */
} mars_tp_ctlpolysel_t;

/**
 * @enum mars_tp_waveformsel_t
 * @brief Enumeration for TP waveform selection.
 * @design GID-350990
 */
typedef enum
{
    MARS_TP_PULSE = (0U), /*!< Pulse waveform */
    MARS_TP_SINE = (1U),  /*!< Sine waveform */
    MARS_TP_RAMP = (2U),  /*!< Ramp waveform */
    MARS_TP_PRBS = (3U)   /*!< PRBS waveform */
} mars_tp_waveformsel_t;

/** @typedef mars_tx_channel_t
 *  @brief Type for TX channel index.
 *  @design GID-350989
 */
typedef uint8 mars_tx_channel_t;


/** @typedef mars_raw_phase_t
 *  @brief Type for raw phase.
 *  @design GID-350989
 */
typedef uint16 mars_raw_phase_t;

/**
 * @struct mars_diag_t
 * @brief Structure for Diagnostic Raw status.
 * @design GID-350418
 */
typedef struct
{
    uint8 state; /*!< Diagnostic state */
    uint16 raw_value;               /*!< Diagnostic value in raw */
} mars_diag_t;

/**
 * @enum mars_rx_en_mode_t
 * @brief Enumeration for RX enable mode.
 * @design GID-350487
 */
typedef enum
{
    MARS_RX_EN_NORMAL = 0,        /*!< Normal mode */
    MARS_RX_EN_OFFSET_DISABLE = 1 /*!< Offset disable mode */
} mars_rx_en_mode_t;

/** @typedef mars_rx_on_offset_t
 *  @brief Type for RX on offset.
 *  @design GID-350487
 */
typedef uint8 mars_rx_on_offset_t;

/** @typedef mars_rx_off_offset_t
 *  @brief Type for RX off offset.
 *  @design GID-350487
 */
typedef sint16 mars_rx_off_offset_t;

/** @typedef mars_rx_seq_offset_t
 *  @brief Type for RX sequence offset.
 *  @design GID-350487
 */
typedef uint8 mars_rx_seq_offset_t;

/**
 * @enum mars_rx_adc_mode_t
 * @brief Enumeration for RX ADC mode.
 * @design GID-350487
 */
typedef enum
{
    MARS_RX_ADC_NORMAL = 0,      /*!< Normal mode */
    MARS_RX_ADC_TESTPATTERN = 1, /*!< Test pattern mode */
    MARS_RX_ADC_INJECTION = 2    /*!< Injection mode */
} mars_rx_adc_mode_t;

/**
 * @enum mars_rx_adc_samp_frq_t
 * @brief Enumeration for RX ADC sample frequency.
 * @design GID-350487
 */
typedef enum
{
    MARS_RXADC_SAMPLE_960M = 0, /*!< 960 MHz sample frequency */
    MARS_RXADC_SAMPLE_1200M = 1 /*!< 1200 MHz sample frequency */
} mars_rx_adc_samp_frq_t;

/* polyspace-begin MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-begin CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */
/**
 * @enum mars_rx_ifvga_stage_1_t
 * @brief Enumeration for RX IFVGA Gain Stage 1 (12dB or 18dB)
 * @design GID-350487
 */
typedef enum
{
    MARS_RX_IFVGA_ST_1_18DB = 0, /*!< Rx IFVGA Stage 1 is 18dB */
    MARS_RX_IFVGA_ST_1_12DB = 1  /*!< Rx IFVGA Stage 1 is 12dB */
} mars_rx_ifvga_stage_1_t;


/**
 * @enum mars_rx_hpf_prechg_t
 * @brief Enumeration for RX IFVGA High-Pass Filter Precharge control
 * @design GID-350487
 */
typedef enum
{
    MARS_RXIFVGA_HPF_PRECHARGE_DISABLED = 0, /*!< RX IFVGA High-Pass Filter Precharge Disabled */
    MARS_RXIFVGA_HPF_PRECHARGE_ENABLED = 1,  /*!< RX IFVGA High-Pass Filter Precharge Enabled */
    MARS_RXIFVGA_HPF_PRECHARGE_AUTO = 2,     /*!< RX IFVGA High-Pass Filter Precharge handled by MAF */
} mars_rx_hpf_prechg_t;


/**
 * @struct mars_rx_config_t
 * @brief Structure for RX configuration.
 * @design GID-350487
 */
typedef struct
{
    mars_rx_en_mode_t rx_en_mode;               /*!< RX enable mode */
    mars_rx_ifvga_gain_t rx_ifvga_gain;         /*!< RX IFVGA gain */
    mars_rx_mixer_gain_t rx_mixer_gain;         /*!< RX mixer gain */
    mars_rx_on_offset_t rx_on_offset;           /*!< RX on offset */
    mars_rx_off_offset_t rx_off_offset;         /*!< RX off offset */
    mars_rx_seq_offset_t rx_seq_offset;         /*!< RX sequence offset */
    mars_rx_adc_mode_t rx_adc_mode;             /*!< RX ADC mode */
    mars_rx_adc_samp_frq_t rx_adc_samp_frq;     /*!< RX ADC sample frequency */
    mars_rx_ifvga_stage_1_t rx_ifvga_stage_1;   /*!< RX IFVGA Gain Stage 1 */
    mars_rx_hpf_prechg_t rx_hpf_prechg_mode;    /*!< RX IFVGA HPF Precharge control */
} mars_rx_config_t;
/* polyspace-end MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-end CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */

/**
 * @enum mars_rfdist_mode_t
 * @brief Enumeration for RF distribution mode.
 * @design GID-350487
 */
typedef enum
{
    MARS_RFDIST_INTERNAL_LO = 0,    /*!< Internal LO mode */
    MARS_RFDIST_CASCADE_MASTER = 1, /*!< Cascade master mode */
    MARS_RFDIST_EXTERNAL_LO = 2     /*!< External LO mode */
} mars_rfdist_mode_t;

/** @typedef mars_tx_power_t
 *  @brief Type for TX power.
 *  @design GID-350487
 */
typedef uint8 mars_tx_power_t;

/**
 * @enum mars_tx_en_mode_t
 * @brief Enumeration for TX enable mode.
 * @design GID-350487
 */
typedef enum
{
    MARS_TX_EN_NORMAL = 0,        /*!< Normal mode */
    MARS_TX_EN_OFFSET_DISABLE = 1 /*!< Offset disable mode */
} mars_tx_en_mode_t;

/** @typedef mars_tx_on_offset_t
 *  @brief Type for TX on offset.
 *  @design GID-350487
 */
typedef uint8 mars_tx_on_offset_t;

/** @typedef mars_tx_off_offset_t
 *  @brief Type for TX off offset.
 *  @design GID-350487
 */
typedef sint16 mars_tx_off_offset_t;

/** @typedef mars_tx_seq_offset_t
 *  @brief Type for TX sequence offset.
 *  @design GID-350487
 */
typedef uint8 mars_tx_seq_offset_t;

/**
 * @enum mars_tx_ph_mode_t
 * @brief Enumeration for TX phase mode.
 * @design GID-350487
 */
typedef enum
{
    MARS_TX_PH_LUT = 0,       /*!< Profile TX-phase LUT */
    MARS_TX_PH_MOD_CHIRP = 1, /*!< Chirp-to-chirp TX-phase modulation */
    MARS_TX_PH_MOD_CONT = 2   /*!< Continuous TX-phase modulation */
} mars_tx_ph_mode_t;

/* polyspace-begin MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-begin CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */
/**
 * @struct mars_tx_config_t
 * @brief Structure for TX configuration.
 * @design GID-350487
 */
typedef struct
{
    mars_tx_en_mode_t tx_en_mode;       /*!< TX enable mode */
    mars_tx_power_t tx_power;           /*!< TX power */
    mars_tx_on_offset_t tx_on_offset;   /*!< TX on offset */
    mars_tx_off_offset_t tx_off_offset; /*!< TX off offset */
    mars_tx_seq_offset_t tx_seq_offset; /*!< TX sequence offset */
    mars_tx_ph_mode_t tx_ph_mode;       /*!< TX phase mode */
} mars_tx_config_t;
/* polyspace-end MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-end CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */

/**
 * @enum mars_bias_noise_filter_t
 * @brief Enumeration for boas noise filter control.
 * @design GID-350487
 */
/* polyspace-begin Custom:6.3 [No action planned:Mid] "Starts with prefixed enum name" */
typedef enum
{
    BIAS_NOISE_FILTER_OFF = 0, /*!< Bias Noise Filter Off */
    BIAS_NOISE_FILTER_ON = 1,   /*!< Bias Noise Filter On */
} mars_bias_noise_filter_t;
/* polyspace-end Custom:6.3 [No action planned:Mid] "Starts with prefixed enum name" */

/**
 * @enum mars_mimo_mode_t
 * @brief Enumeration for MIMO mode.
 * @design GID-350487
 */

/* polyspace-begin Custom:6.3 [No action planned:Mid] "Starts with prefixed enum name" */
typedef enum
{
    MIMO_PLUS_MODE = (1U),    /*!< MIMO Plus mode */
    MIMO_PLUS_PRO_MODE = (2U) /*!< MIMO Plus Pro mode */
} mars_mimo_mode_t;
/* polyspace-end Custom:6.3 [No action planned:Mid] "Starts with prefixed enum name" */

/**
 * @enum mars_profiler_mode_t
 * @brief Enumeration for profiler mode.
 * @design GID-350487
 */
typedef enum
{
    MARS_PROF_FIFO = 0,  /*!< FIFO operation */
    MARS_PROF_SHADOW = 1 /*!< Shadow register operation */
} mars_profiler_mode_t;

/* polyspace-begin MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-begin CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */
/**
 * @struct mars_chirp_config_t
 * @brief Structure for chirp configuration.
 * @design GID-350487
 */
typedef struct
{
    uint16 chirps_per_frame;     /*!< Number of chirps per frame */
    uint8 repeatable_chirps_num; /*!< Number of repeatable chirps in the frame */
    uint16 t0_start_pointer;     /*!< Offset to first T0 table entry in bytes. Shall be calculated based on the formula: [ProfileTable0 entry size (mars_pt0_t, 16 bytes)] * [Number of Elements]. E.g. Start after the 3th element, t0_start_pointer = 16 * 3. */
    uint16 t0_end_pointer;       /*!< Offset to last T0 table entry in bytes. Shall be calculated based on the formula: [ProfileTable0 entry size (mars_pt0_t, 16 bytes)] * [Number of Elements]. E.g. End with the 5th element, t0_start_pointer = 16 * 5.  */
    uint16 t1_start_pointer;     /*!< Offset to first T1 table entry in bytes. Total PT0 size should be considered to avoid overlapping!!! Shall be calculated based on the formula: [ProfileTable0 total size] + [ProfileTable1 entry size (mars_pt1_t, 8 bytes)] * [Number of Elements]. E.g. Start after the 3th element, t1_start_pointer = pt0_total_size + (8 * 3). */
} mars_chirp_config_t;
/* polyspace-end MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-end CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */

/* polyspace-begin MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-begin CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */
/**
 * @struct mars_chirp_mode_t
 * @brief Structure for chirp mode.
 * @design GID-350487
 */
typedef struct
{
    mars_profiler_mode_t profiler_mode; /*!< Profiler mode , deprecated. Has no effect */
    mars_mimo_mode_t mimo_mode;         /*!< MIMO mode */
} mars_chirp_mode_t;
/* polyspace-end MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-end CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */

/** @union mars_fw_version_t
 *  @brief Type for firmware version.
 *  @design GID-350175
 */
typedef union { /* polyspace MISRA-C-2023:19.2 [No action planned:Low] "Union keyword required by the design of the profile table access" */
    uint32 maf_version; /*!< Raw data */
    struct
    {
        uint32 maf_version_patch          :8; /*!< MAF version PATCH */
        uint32 maf_version_minor          :8; /*!< MAF version MINOR */
        uint32 maf_version_major          :8; /*!< MAF version MAJOR */
        uint32 maf_version_variant        :4; /*!< MAF version VARIANT */
        uint32 maf_version_hw             :4; /*!< MAF version HW */
    } s;                  /*!< Structured data */
} mars_fw_version_t;

/** @typedef mars_unique_id_t
 *  @brief Type for Mars Unique ID
 *  @design GID-350175
 */
typedef uint64 mars_unique_id_t;

/** @typedef mars_si_name_version_t
 *  @brief ASCII encoded information denoting "MARS" on [63:32] and "B0" or any other past or future silicon version on [31:0] bits
 *  @design GID-350175
 */
typedef uint64 mars_si_name_version_t;

/**
 * @struct mars_uid_t
 * @brief Structure for device Unique ID.
 * @design GID-350175
 */
typedef struct
{
    mars_si_name_version_t si_name_version; /*!<  Mars Silicon name and version on 64 bits */
    mars_unique_id_t uid;                   /*!< 64 bits integer that uniquely identifies MARS chips */
    mars_fw_version_t fw_version;          /*!< 32 bits integer for the firmware version */
} mars_uid_t;

/* polyspace-begin MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-begin CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */
/**
 * @struct mars_mipi_config_t
 * @brief Structure for MIPI configuration.
 * @design GID-350487
 */
typedef struct
{
    mars_mipi_tx_lanes_t mipi_data_lanes;        /*!< MIPI data lanes */
    mars_mipi_bitrate_t mipi_data_rate;          /*!< MIPI data rate */
    mars_mipi_metadata_enable_t metadata_enable; /*!< Metadata enable */
    mars_mipi_power_mode_t power_mode;           /*!< MIPI power mode */
} mars_mipi_config_t;
/* polyspace-end MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-end CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */

/**
 * @struct mars_tp_config_t
 * @brief Structure for Test Pattern configuration.
 * @design GID-350990
 */
typedef struct
{
    mars_tp_waveformsel_t waveform;      /*!< Test Pattern waveform */
    mars_tp_ctlpolysel_t polynomial;     /*!< Test Pattern polynomial */
    mars_tp_ctlparsel_t parallelism;     /*!< Test Pattern parallelism */
    mars_tp_step_t step;                 /*!< Test Pattern step */
    mars_tp_offset_t offset;             /*!< Test Pattern offset */
    mars_tp_pulse_threshold_t threshold; /*!< Test Pattern pulse threshold */
    mars_tp_shift2_t shift2;             /*!< Test Pattern shift 2 */
    mars_tp_shift1_t shift1;             /*!< Test Pattern shift 1 */
} mars_tp_config_t;

/** @typedef mars_cal_control_t
 *  @brief Type for calibration control.
 *  @design GID-350988
 */
typedef uint32 mars_cal_control_t[CALIBRATION_CONTROL_NO_OF_WORDS];

/**
 * @enum mars_reset_t
 * @brief Enumeration for reset types used with mars_reset().
 * @design GID-350175
 */
typedef enum
{
    MARS_RESET_HARD = (0U),      /*!< Normal operation: full hardware reset */
    MARS_RESET_SOFT = (1U),      /*!< Software-controlled reset via an internal register command */
    MARS_RESET_FORCE_LOW = (2U), /*!< Asserts the reset line and holds it low, without releasing. */
    MARS_RESET_STATUS = (3U)     /*!< API state recovery only: forces the API driver state to MARS_INIT_IDLE_OPERATIONAL*/
} mars_reset_t;

/** @typedef mars_frame_counter_t
 *  @brief Type for frame counter.
 *  @design GID-350487
 */
typedef uint16 mars_frame_counter_t;

/** @typedef mars_mipi_diag_t
 *  @brief Type for MIPI diagnostic.
 *  @design GID-350487
 */
typedef uint32 mars_mipi_diag_t;

/** @typedef mars_fusa_fs_t
 *  @brief Type for MAF FUSA Start Frequency
 *  @design GID-350487
 */
typedef uint32 mars_fusa_fs_t;


/**
 * @enum mars_tp_adc_channel_t
 * @brief Enumeration for Test Pattern ADC channel.
 * @design GID-350990
 */
typedef enum
{
    MARS_ADC_CH1 = 0u, /*!< Select test pattern for ADC channel 1 */
    MARS_ADC_CH2 = 1u, /*!< Select test pattern for ADC channel 2 */
    MARS_ADC_CH3 = 2u, /*!< Select test pattern for ADC channel 3 */
    MARS_ADC_CH4 = 3u  /*!< Select test pattern for ADC channel 4 */
} mars_tp_adc_channel_t;

/**
 * @enum mars_ssi_config_t
 * @brief Enumeration for SSI configuration.
 * @design GID-350175
 */
typedef enum
{
    MARS_SSI_SPI = 1u,  /*!< Mars shall communicate with host in SPI mode */
    MARS_SSI_QSPI = 2u, /*!< Mars shall communicate with host in QSPI mode */
} mars_ssi_config_t;

/** @typedef mars_bist_config_t
 *  @brief Type for BIST configuration.
 *  @design GID-347866
 */
typedef uint32 mars_bist_config_t[MARS_SCP_CONFIGURE_BIST_WORDS];

/**
 * @enum mars_sft_err_n_t
 * @brief Enumeration for safety error status.
 * @design GID-383856
 */
typedef enum
{
    MARS_SFT_ERR_NOT_ACTIVE = 0, /*!< No active safety error */
    MARS_SFT_ERR_ACTIVE = 1      /*!< Active safety error */
} mars_sft_err_n_t;

/**
 * @enum mars_maf_status_t
 * @brief Mars Application Firmware software state (MAF operational mode).
 * @design GID-383856
 */
typedef enum
{
    MARS_MAF_INIT = 0,                 /*!< MAF starting up. */
    MARS_MAF_STANDBY = 1,              /*!< MAF ready and operational. */
    MARS_MAF_FMCW = 2,                 /*!< MAF operational, running FMCW. */
    MARS_MAF_CW = 3,                   /*!< MAF operational, running CW. */
    MARS_MAF_SFT_RECOVERABLE = 4,      /*!< MAF operational, identified a recoverable SFT error. */
    MARS_MAF_SFT_NON_RECOVERABLE = 5   /*!< MAF not operational identified a non-recoverable SFT error. */
} mars_maf_status_t;

/**
 * @enum mars_tp_clr_mode_t
 * @brief Enumeration for Mars Test Pattern Clear Mode.
 * @design GID-350990
 */
typedef enum
{
 MARS_TESTPATTERN_CLR_FRM_START = 0,     /* Test pattern resets at frame start   */
 MARS_TESTPATTERN_CLR_CHRP_START  = 1,   /* Test pattern resets at chirp start   */
 MARS_TESTPATTERN_CLR_RAMP_START  = 2,   /* Test pattern resets at ramp start    */
 MARS_TESTPATTERN_CLR_SAMPLE_START = 3   /* Test pattern resets at sample start  */
} mars_tp_clr_mode_t;



/**
 * @typedef mcu_diag_error_t
 * @brief Diagnostic error code element type (raw uint16 value from MAF diagnostics).
 * @design GID-383856
 */
typedef uint16 mcu_diag_error_t;

/**
 * @struct mars_bist_result_t
 * @brief Data type for Software detected errors diagnostic data.
 * @design GID-383856
 */
typedef struct
{
    mars_sft_err_n_t safety_error_detected;       /*!< Status of IRQE_SFT_ERR_N pin. */
    mars_maf_status_t maf_status;                 /*!< Status reported by the Mars Application Firmware (MAF). */
    mars_reg_value_t CORE_BANK_SFT_ERR_MON;       /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t CORE_BANK_SFT_ERR_STATUS;    /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t CORE_BANK_MCU_STS_MCU_MSSG;  /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t CORE_BANK_SFT_STATUS;        /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t CORE_BANK_FRM_ERR;           /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t CORE_BANK_ENA_ERR;           /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t LOGEN_BANK_CHRP_GEN_ERROR;   /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t LOGEN_BANK_LOGEN_ERROR;      /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t RXADC_FUSAIRQV;              /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t RXADC_FUSAIRQV0;             /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t RXADC_FUSAIRQV1;             /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t RXADC_FUSAMON;               /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t RX_ADC_MOD0_FUSAIRQV;       /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t RX_ADC_MOD1_FUSAIRQV;       /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t RX_ADC_MOD2_FUSAIRQV;       /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t RX_ADC_MOD3_FUSAIRQV;       /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t ASYNC_BANK_ASYNC_ERR1;       /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t PROF_BANK_PRF_ERR1;          /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t PROF_BANK_PRF_ERR2;          /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t CPU_SYS_MCU_ERR_0;           /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t CPU_SYS_MCU_ERR_1;           /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t CPU_SYS_MCU_ERR_2;           /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t CPU_SYS_MCU_ERR_3;           /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t CPU_SYS_DMA_ERR;             /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t MIPI_BANK_IRQ_STATUS;        /*!< Status reported by the Hardware detected errors */
    mars_reg_value_t CPLL_BANK_REFPLL_ERR;        /*!< Status reported by the Hardware detected errors */
    mcu_diag_error_t mcu_diag_error_values[MARS_DIAG_VALUES_MAX_NUMBER_MAF_ERROR_STATUS];   /*!< Additional Software detected errors diagnostic data. */
} mars_bist_result_t;

/** @typedef mars_zhv_t
 *  @brief Type Zero Hour Values data array
 *  @design GID-350988
 */
typedef uint32 mars_zhv_t[512];

/** @typedef Mars_ReturnType
 *  @brief Type for return type.
 */
typedef uint32 Mars_ReturnType; /* polyspace Custom:3.1[No action planned:Mid] "Legacy AutoSAR-compatible type name; does not use _t suffix as required by custom rule" */

/** @def MARS_E_OK
 *  @brief Macro for successful operation.
 */
#ifndef MARS_E_OK
#define MARS_E_OK 0
#endif

/** @def NULL_PTR
 *  @brief Macro for null pointer.
 */
#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif

#endif /* MARS_PUBLIC_TYPES_H */
