/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#ifndef MARS_CFG_H
#define MARS_CFG_H

/* *******************************
 * MARS MISSION MODE CONTROL
 * ********************************/
#if defined(MARS_DEBUG_SUPPORT_DISABLED)
#if defined MARS_ALLOW_ACTIVATION_NO_CRC
/* MAF activation without CRC shall not be enabled in mission mode. */
#undef MARS_ALLOW_ACTIVATION_NO_CRC
#endif
#endif

/* *******************************
 * MARS MEMORY LAYOUT
 * ********************************/
#define MARS_DRAM_START_ADDR          0x20000u /* Start Address of DRAM */

#define MARS_FIRMWARE_END_ADDR        0x1FFFFu  /* I-RAM end address */
#define MARS_FIRMWARE_START_ADDR      0x8000u  /* Start address of MAF */

#define MARS_REGISTER_BANK_START 0x33000u
#define MARS_REGISTER_BANK_END 0x3B3FFu

#define MARS_MEMORY_END_ADDR              0x3B3FFu  /* End address of Mars memory map */
#define MARS_MAX_MEMORY_SECTION_SIZE      0x17FFFu  /* Maximum size of a memory section IRAM Memory section */

#define MARS_FIRMWARE_MAX_SIZE        (MARS_FIRMWARE_END_ADDR - MARS_FIRMWARE_START_ADDR)  /* Maximum size of MAF */

#define MARS_PROFILE_TABLE_START_ADDR 0x28000u  /* Start address of Profiler memory */
#define MARS_PROFILE_TABLE_LEN        0x8400u   /* Length of Profiler memory */
#define MARS_PHASE_TX_LUT_START_ADDR  0x32000u  /* Start address of PHASE TX LUT */

#define MARS_ZHV_START_ADDR           0x20F00u  /* Start address of ZHV data*/
#define MARS_ZHV_LEN                  2048      /* Length of ZHV data in bytes */

#define MARS_FW_METADATA_START_ADDR (MARS_DRAM_START_ADDR + 0x200u) /* Start address of Mars FW metadata */

#define MARS_FW_VERSION_START_ADDR  (MARS_FW_METADATA_START_ADDR + 0x08u) /* FW Metadata offset to Mars FW version */

#define MARS_DIAG_VALUES_START_ADDR (MARS_DRAM_START_ADDR + 0x700u)
#define MARS_DIAG_VALUES_SIZE       (0x800u)
#define MARS_DIAG_VALUES_MAX_NUMBER (MARS_DIAG_VALUES_SIZE/sizeof(uint32))

#define MARS_DIAG_VALUES_MAX_NUMBER_MAF_ERROR_STATUS 42
#define MARS_DIAG_VALUES_MAF_ERROR_STATUS_START_ADDR (MARS_DIAG_VALUES_START_ADDR + 0x340u) /* end size 0x3E4, 0x3E4 - 0x340 = 42 word elements */

#define MARS_SCP_CAL_SIZE_WORDS 3u                    /* Size of the SCP CAL memory block */
#define MARS_SCP_CAL_ERROR_SIZE_WORDS 3u              /* Size of the SCP CAL ERROR memory block */
#define MARS_SCP_CONFIGURE_BIST_WORDS 0x3Eu              /* Size for configure BIST memory block */
#define MARS_SCP_ERROR_BITS_OFFSET 0x80u              /* Memory offset where the parameter error bits are stored */

#define MARS_MIPI_DIAG_ARRAY_SIZE 16u                 /* Number of MIPI metadata diag array items in mars_configure / mars_scp_cfg */

#define SSI_BUFFER_SIZE (8u+2u) /* Size of SSI internal buffer in words */

/* Layer 1 SSI burst-size indices  */
#define MAX_WR_SIZE_IDX_QSPI 5u   /* 64-word bursts with alignment checks */
#define MAX_RD_SIZE_IDX_QSPI 3u   /* max QSPI read burst: 16 words */
#define MAX_WR_SIZE_IDX_SPI  2u   /* max SPI write burst: 8 words */
#define MAX_RD_SIZE_IDX_SPI  2u   /* max SPI read burst: 8 words */

#define MARS_MEM_WR_READBACK_LIMIT 4u  /* read-back integrity word limit */

/* *********************************
 *  MARS MAILBOX
 * *********************************/
/* Physical mailbox register slots (MLBX_Hn/Ln). Only 0 and 1 are used by this driver.
 * Slot = hardware index; command (MARS_MLBX_CMD_*) = protocol opcode. Do not add per-operation slot aliases. */
#define MARS_MLBX_SLOT_STATUS_RESPONSE 0U /* Mars-initiated status / response (read) */
#define MARS_MLBX_SLOT_GEN_CMD 1U /* Host-initiated general command (read/write) */

/* var_l payload bit in STATUS_RESPONSE slot (e.g. MAF FMCW frame-done indication) */
#define MARS_MLBX_VAR_L_BIT_FMCW_FRAME_DONE 0U

#define MARS_MLBX_CMD_ML_RDR_STS 0x01U
#if defined(MARS_ALLOW_ACTIVATION_NO_CRC)
#define MARS_MLBX_CMD_ML_EXEC_MAF 0x02U
#endif
#define MARS_MLBX_CMD_ML_EXEC_MAF_CRC 0x03U
#define MARS_MLBX_CMD_ML_EXEC_MAF_CRC_SEC 0x04U /* Level 1 defined : MLBX_CMD_ML_EXEC_MAF_CRC_SEC */ /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "Compatibility layout with Level 1 macro MLBX_CMD_ML_EXEC_MAF_CRC_SEC" */
#define MARS_MLBX_CMD_ML_CFG_SSI 0x05U
#define MARS_MLBX_CMD_ML_CHECK_CRC 0x06U
#define MARS_MLBX_CMD_ML_RDR_SCP 0x0AU
#define MARS_MLBX_SUBCMD_SCP_CAL 0x02U
#define MARS_MLBX_SUBCMD_SCP_CONFIGBIST 0x03UL
#define MARS_MLBX_CMD_ML_PURE_CW_CTRL 0x0BU
#define MARS_MLBX_CMD_ML_UPD_DIAG 0x0EU
#define MARS_MLBX_CMD_ML_ERR_RECOV 0x0FU
#define MARS_MLBX_CMD_SFT_PIN_TEST 0x10U
#define MARS_MLBX_CMD_ML_RD_BACK 0x0DU
#define MARS_MLBX_SUBCMD_RD_BACK_CAL 0x02UL
#define MARS_MLBX_SUBCMD_RD_BACK_CONFIGBIST 0x03UL
#define MARS_MLBX_SUBCMD_RD_BACK_CONFIG 0x00UL
#define MARS_MLBX_SUBCMD_CLEAR_RECOV_ERR 0xA5A5U

#define MARS_MLBX_PARITY_CHECK_BIT 4U /* MLBX response bit 4 - parity error */

/* *********************************
 *  MARS PROFILE STRUCTURE
 * *********************************/
#define MARS_PROFILER_T0_ELEMENT_SIZE_BYTES (sizeof(mars_pt0_t))
#define MARS_PROFILER_T1_ELEMENT_SIZE_BYTES (sizeof(mars_pt1_t))
#define MARS_PROFILER_T0_MAX_NO_OF_ELEMENTS 2048u
#define MARS_PROFILER_T1_MAX_NO_OF_ELEMENTS 8u
#define MARS_PHASE_LUT_NO_OF_ELEMENTS 512u
#define MARS_PHASE_LUT_NO_OF_TX 4

/* *********************************
 *  MARS MAF
 * *********************************/
#define MARS_FW_HW_VERSION_OFFSET (28u)
#define MARS_FW_VERSION_MIN_COMPATIBLE MARS_FW_VERSION(1UL, 0UL, 3UL, 0x6UL, 0UL)
#define MARS_FW_HW_VERSION 1u

#define MARS_RADAR_READY_OK 0x03U /* Radar-ready register value (both ready bits set) */
#define MARS_MAF_ACTIVATE_CRC_VAR_H_SHIFT 16U /* VAR_H upper half in MAF activate CRC response */

/* *********************************
 *  MARS CW
 * *********************************/
#define MARS_TX_CHANNEL_MAX 4U
#define MARS_FS_FREQUENCY_MIN 8039082U /* Minimum frequency in Hz */
#define MARS_FS_FREQUENCY_MAX 10223616U /* Maximum frequency in Hz */
#define MARS_RAW_PHASE_MAX  511u       /*Maximum Phase Look-Up Table (LUT) index*/

#endif /* MARS_CFG_H */
