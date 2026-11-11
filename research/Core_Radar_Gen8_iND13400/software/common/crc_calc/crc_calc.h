#ifndef CRC_CALC_H
#define CRC_CALC_H
/*===========================================================================*/
/**
 * @file crc_calc.h
 *
 * @todo Add a one line description of the header file here.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * @todo Add full description here
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 *
 * @defgroup template Provide API description and define/delete next line
 * @ingroup <parent_API> (OPTIONAL USE if part of another API, else delete)
 * @{
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include "Driver_Common.h"
#include "ipc_data.h" /* Needed for M2D_Msg_T used in Calc_M2D_Buf_Crc prototype */
#include "reuse.h"

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

   /*===========================================================================*
    * Exported Preprocessor #define Constants
    *===========================================================================*/
#define ARM_CRC_CRC32_POLY_04C11DB7H (3U) /**< 32-bit 0x04C11DB7 polynomial CRC calculation */

/**
 * @def             CRC_CH_0
 * @brief           Hardware channel 0
 */
#define CRC_CH_0 (0x00U)

/**
 * @def             CRC_CH_1
 * @brief           Hardware channel 1
 */
#define CRC_CH_1 (0x01U)
/**
 * @def             CRC_CH_2
 * @brief           Hardware channel 2
 */
#define CRC_CH_2 (0x02U)

/**
 * @def             CRC_CH_3
 * @brief           Hardware channel 3
 */
#define CRC_CH_3 (0x03U)

/****** CRC channel codes: *****/
#define ARM_CRC_CHANNEL0     0U /**< Channel0 */
#define ARM_CRC_CHANNEL1     1U /**< Channel1 */
#define ARM_CRC_CHANNEL2     2U /**< Channel2 */
#define ARM_CRC_CHANNEL3     3U /**< Channel3 */
#define ARM_CRC_OUT_OF_RANGE 4U /* out of range value  */

/****** CRC Generator Polynomial codes *****/
#define ARM_CRC_CRC8_POLY_1DH        (0U) /**< 8-bit 0x1D polynomial CRC calculation */
#define ARM_CRC_CRC8_POLY_2FH        (1U) /**< 8-bit 0x2F polynomial CRC calculation */
#define ARM_CRC_CRC16_POLY_1021H     (2U) /**< 16-bit 0x1021 polynomial CRC calculation */
#define ARM_CRC_CRC32_POLY_04C11DB7H (3U) /**< 32-bit 0x04C11DB7 polynomial CRC calculation */
#define ARM_CRC_CRC32_POLY_F4ACFB13H (4U) /**< 32-bit 0xF4ACFB13 polynomial CRC calculation */
#define ARM_CRC_POLYNOMIAL_END       (5U)

/****** CRC Module Status codes *****/
#define ARM_CRC_MODULE_STATE_UNINIT  (0U) /**< Uninit : Module is not initializated */
#define ARM_CRC_MODULE_STATE_STARTED (1U) /**< Started: Module is started */
#define ARM_CRC_MODULE_STATE_STOPPED (2U) /**< Stopped: Module is not started (initialization) */

/****** CRC Engine Status codes *****/
#define ARM_CRC_ENGINE_STATE_FREE (0U) /**< Engine released */
#define ARM_CRC_ENGINE_STATE_BUSY (1U) /**< Engine busy */

#define ARM_CRC_TIMEOUT 0xFFFFU /**< Time Out (TBD).*/

#define ARM_CRC_INIT_CTL_PAR_SEL    3U /**< Parallelism selection */
#define ARM_CRC_INIT_CTL_OUT_POL    0U /**< Flip polarity of CRC output when set to 1*/
#define ARM_CRC_INIT_CTL_OUT_REV    0U /**< Reverse bit endianness of CRC output when set to 1*/
#define ARM_CRC_INIT_CTL_BYTE_SHIFT 0U /**< Number of bytes to right shift input Data after byte and bit reversing*/
#define ARM_CRC_INIT_CTL_BIT_REV    0U /**< Reverse Bit Order of Data written into CRC engine; within byte boundary*/
#define ARM_CRC_INIT_CTL_BYTE_REV   0U /**< Reverse Byte Order of Data written into CRC engine*/
#define CRC_CTL_PAR_MASK            (0x3UL << 0)
#define CRC_CTL_BYTE_REV_BIT_MASK   (1U << 2)
#define POLY_OUT_OF_RANGE           5 /* Number of supported polynomials */

#define INPUT_REG_SIZE         (4)         /* Size in bytes of the input register of the CRC HW engine */
#define SHIFT_8_BITS           (8)         /* Right shift the data by 8 bits */
#define SHIFT_16_BITS          (16)        /* Right shift the data by 16 bits */
#define SHIFT_24_BITS          (24)        /* Right shift the data by 24 bits */
#define ONE_BIT_SHIFT          (1U)        /* Shift by 1 bit for swapping individual bits */
#define TWO_BIT_SHIFT          (2U)        /* Shift by 2 bits for swapping pairs of bits */
#define FOUR_BIT_SHIFT         (4U)        /* Shift by 4 bits for swapping nibbles */
#define ONE_BYTE_SHIFT         (8U)        /* Shift by 8 bits for swapping bytes */
#define TWO_BYTE_SHIFT         (16U)       /* Shift by 16 bits for swapping 2-byte pairs */
#define REMAINING_1_BYTE       (1)         /* 1 byte of the crc data is remaining */
#define REMAINING_2_BYTES      (2)         /* 2 bytes of the crc data are remaining */
#define REMAINING_3_BYTES      (3)         /* 3 bytes of the crc data are remaining */
#define SWAP_32BIT_MASK_INDIV  0x55555555U /* 01010101010101010101010101010101 in binary */
#define SWAP_32BIT_MASK_PAIRS  0x33333333U /* 00110011001100110011001100110011 in binary */
#define SWAP_32BIT_MASK_NIBBLE 0x0F0F0F0FU /* 00001111000011110000111100001111 in binary */
#define SWAP_32BIT_MASK_BYTE   0x00FF00FFU /* 00000000111111110000000011111111 in binary */
#define ASSUME_ALIGNED(PTR, ALIGNMENT)                                                                                            \
   (PTR) /* Macro to assume pointer is aligned to the specified alignment, used for static code analysis tools */
#define ALIGNOF(type) sizeof(type)
/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/
/* Below macro will enable IPC metadata CRC checks*/
#define ENABLE_IPC_CRC_METADATA
#define MAX_IPC_M2D_CRITICAL_SIG (7U)
#define MAX_IPC_D2M_CRITICAL_SIG (7U)
#define ARM_CRC_API_VERSION      ARM_DRIVER_VERSION_MAJOR_MINOR(1, 3) /* API version */
   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/

   /* Table entry describing a contiguous region used for CRC computation */
   typedef struct IPC_Crc_Calc_Table_Tag
   {
      uint32_t *startAddr; /* start address of region to checksum */
      uint32_t size;       /* size of region in bytes */
   } IPC_Crc_Calc_Table_T;

   typedef struct Crc_StandardParameters_Tag
   {
      uint32_t Crc_Polynomial;
      uint32_t Crc_InitValue;
      uint32_t Crc_XorValue;
      uint32_t Crc_Check;
      uint32_t Crc_MagicCheck;
      uint32_t Crc_OutputFlipPolarity:1U;
      uint32_t Crc_OutputReverseBitEndiannes:1U;
      uint32_t Crc_InputBitReverse:1U;
      uint32_t Crc_InputByteReverse:1U;
      uint32_t Crc_InputByteShift:2U;
      uint32_t Crc_ParSel:2U;
      uint32_t Crc_Reserved:26U;
   } Crc_StandardParametersType;
   typedef struct _ARM_CRC_CONTROL
   {
      uint32_t output_polarity:1U;    /**< Flip polarity of CRC output when set to 1 */
      uint32_t output_reverse:1U;     /**< Reverse bit endianness of CRC output when set to 1 */
      uint32_t input_bit_reverse:1U;  /**< Reverse Bit Order of Data written into CRC engine; within byte boundary */
      uint32_t input_byte_reverse:1U; /**< Reverse Byte Order of Data written into CRC engine */
      uint32_t input_byte_shift:2U;   /**< Reverse Byte Order of Data written into CRC engine */
      uint32_t reserved:2U;           /**< Reserved (must be zero) */
   } ARM_CRC_CONTROL;
   /*===========================================================================*
    * Exported Const Object Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/
   extern uint32_t Compute_CRC32_SW(uint8_t *data, uint32_t data_len, uint32_t start_value, bool firstCall);
   /* Accept volatile source buffer and promise not to modify it */
   extern uint32_t Calc_M2D_Buf_Crc(volatile const M2D_Msg_T *buffer_ptr);
   extern uint32_t Calc_D2M_Buf_Crc_Chn_X(volatile D2M_Msg_T *buffer_ptr, uint8_t channel);
#ifdef ENABLE_CRC_TESTS
   extern uint32_t Test_CRC_Channels(void);
#endif
   /*===========================================================================*
    * Exported Inline Function Definitions and #define Function-Like Macros
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/** @} doxygen end group */

/*============================================================================*\
 * AUTHOR(S) IDENTITY (AID)
 *-----------------------------------------------------------------------------
 *
 *  AID         NAME
 *  ---------------------------------------------------------------------------
 *  XXX         Firstname Lastname
 *  tjy9rb      Deepak Kumar Pandey
\*============================================================================*/

/* END OF FILE -------------------------------------------------------------- */
#endif /* CRC_CALC_H*/
