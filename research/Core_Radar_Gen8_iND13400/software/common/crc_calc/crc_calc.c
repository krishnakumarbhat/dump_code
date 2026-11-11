/*===========================================================================*/
/**
 * @file crc_calc.c
 *
 * Description: This file contains the functions to calculate checksum
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
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "chandra_sfrs_base.h"
#include "crc_calc.h"
#include "crc_sfrs.h"
#include "ipc_data.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
#define SW_IPC_CRC_FINAL_XOR_CRC32 (uint32_t)(0xFFFFFFFFUL)
#define SW_IPC_CRC_INITIAL_VALUE32 (uint32_t)(0xFFFFFFFFUL)
#define ARM_CRC_DRV_VERSION        ARM_DRIVER_VERSION_MAJOR_MINOR(2, 6) /**< CRC driver version */
#define REV32(X)                   Reflect32(X)
/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/**
 * @struct Crc_ChannelRegs
 * @requirements
 * @brief           A struct with information used for CRC channel
 */
typedef struct
{
   volatile uint32_t *INIT;
   volatile uint32_t *CTL;    /* Pointer to the full 32-bit control register*/
   volatile uint32_t *XIN[4]; /* Pointers to input registers */
   volatile uint32_t *OUT;    /* Pointer to output register */
} Crc_ChannelRegs;

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
static uint32_t IPC_M2D_Crc_Cal_Tab[MAX_IPC_M2D_CRITICAL_SIG]          = {0};
static IPC_Crc_Calc_Table_T M2D_Crc_Calc_Sig[MAX_IPC_M2D_CRITICAL_SIG] = {0};
/* Uncommented D2M CRC tables for Calc_D2M_Buf_Crc_Chn_X */
static uint32_t IPC_D2M_Crc_Cal_Tab[MAX_IPC_D2M_CRITICAL_SIG]          = {0};
static IPC_Crc_Calc_Table_T D2M_Crc_Calc_Sig[MAX_IPC_D2M_CRITICAL_SIG] = {0};

/*!< CRC Engine Instance */
#ifndef UNIT_TEST
static volatile CRC_SFRS_t *const ptr_crc = (volatile CRC_SFRS_t *)CRC_base; /*!< CRC instance pointer */
   #ifdef ENABLE_CRC_TESTS
/* Global CRC test result variables for Lauterbach inspection */
volatile uint32_t __attribute__((used)) g_crc_hw_result_0 = 0U;
volatile uint32_t __attribute__((used)) g_crc_hw_result_1 = 0U;
volatile uint32_t __attribute__((used)) g_crc_sw_result   = 0U;
   #endif
#endif

static const Crc_StandardParametersType Crc_32bit_Ethernet = {.Crc_Polynomial                = 0x04C11DB7U,
                                                              .Crc_InitValue                 = 0xFFFFFFFFU,
                                                              .Crc_XorValue                  = 0xFFFFFFFFU,
                                                              .Crc_Check                     = 0xCBF43926U,
                                                              .Crc_MagicCheck                = 0xDEBB20E3U,
                                                              .Crc_OutputFlipPolarity        = 0U,
                                                              .Crc_OutputReverseBitEndiannes = 1U,
                                                              .Crc_InputBitReverse           = 1U,
                                                              .Crc_InputByteReverse          = 1U,
                                                              .Crc_InputByteShift            = 0U,
                                                              .Crc_Reserved                  = 0U};
/*! Lookup table for CRC32 table based calculation */
static const uint32_t SW_IPC_Crc_Table32[256] = /* PRQA S 3218 */ /* MD_CRC_8.7_FileScopeStatic */
   {/* PRQA S 1257 32 */                                          /* MD_CRC_10.3_Portability */
    0x00000000UL,
    0x77073096UL,
    0xEE0E612CUL,
    0x990951BAUL,
    0x076DC419UL,
    0x706AF48FUL,
    0xE963A535UL,
    0x9E6495A3UL,
    0x0EDB8832UL,
    0x79DCB8A4UL,
    0xE0D5E91EUL,
    0x97D2D988UL,
    0x09B64C2BUL,
    0x7EB17CBDUL,
    0xE7B82D07UL,
    0x90BF1D91UL,
    0x1DB71064UL,
    0x6AB020F2UL,
    0xF3B97148UL,
    0x84BE41DEUL,
    0x1ADAD47DUL,
    0x6DDDE4EBUL,
    0xF4D4B551UL,
    0x83D385C7UL,
    0x136C9856UL,
    0x646BA8C0UL,
    0xFD62F97AUL,
    0x8A65C9ECUL,
    0x14015C4FUL,
    0x63066CD9UL,
    0xFA0F3D63UL,
    0x8D080DF5UL,
    0x3B6E20C8UL,
    0x4C69105EUL,
    0xD56041E4UL,
    0xA2677172UL,
    0x3C03E4D1UL,
    0x4B04D447UL,
    0xD20D85FDUL,
    0xA50AB56BUL,
    0x35B5A8FAUL,
    0x42B2986CUL,
    0xDBBBC9D6UL,
    0xACBCF940UL,
    0x32D86CE3UL,
    0x45DF5C75UL,
    0xDCD60DCFUL,
    0xABD13D59UL,
    0x26D930ACUL,
    0x51DE003AUL,
    0xC8D75180UL,
    0xBFD06116UL,
    0x21B4F4B5UL,
    0x56B3C423UL,
    0xCFBA9599UL,
    0xB8BDA50FUL,
    0x2802B89EUL,
    0x5F058808UL,
    0xC60CD9B2UL,
    0xB10BE924UL,
    0x2F6F7C87UL,
    0x58684C11UL,
    0xC1611DABUL,
    0xB6662D3DUL,
    0x76DC4190UL,
    0x01DB7106UL,
    0x98D220BCUL,
    0xEFD5102AUL,
    0x71B18589UL,
    0x06B6B51FUL,
    0x9FBFE4A5UL,
    0xE8B8D433UL,
    0x7807C9A2UL,
    0x0F00F934UL,
    0x9609A88EUL,
    0xE10E9818UL,
    0x7F6A0DBBUL,
    0x086D3D2DUL,
    0x91646C97UL,
    0xE6635C01UL,
    0x6B6B51F4UL,
    0x1C6C6162UL,
    0x856530D8UL,
    0xF262004EUL,
    0x6C0695EDUL,
    0x1B01A57BUL,
    0x8208F4C1UL,
    0xF50FC457UL,
    0x65B0D9C6UL,
    0x12B7E950UL,
    0x8BBEB8EAUL,
    0xFCB9887CUL,
    0x62DD1DDFUL,
    0x15DA2D49UL,
    0x8CD37CF3UL,
    0xFBD44C65UL,
    0x4DB26158UL,
    0x3AB551CEUL,
    0xA3BC0074UL,
    0xD4BB30E2UL,
    0x4ADFA541UL,
    0x3DD895D7UL,
    0xA4D1C46DUL,
    0xD3D6F4FBUL,
    0x4369E96AUL,
    0x346ED9FCUL,
    0xAD678846UL,
    0xDA60B8D0UL,
    0x44042D73UL,
    0x33031DE5UL,
    0xAA0A4C5FUL,
    0xDD0D7CC9UL,
    0x5005713CUL,
    0x270241AAUL,
    0xBE0B1010UL,
    0xC90C2086UL,
    0x5768B525UL,
    0x206F85B3UL,
    0xB966D409UL,
    0xCE61E49FUL,
    0x5EDEF90EUL,
    0x29D9C998UL,
    0xB0D09822UL,
    0xC7D7A8B4UL,
    0x59B33D17UL,
    0x2EB40D81UL,
    0xB7BD5C3BUL,
    0xC0BA6CADUL,
    0xEDB88320UL,
    0x9ABFB3B6UL,
    0x03B6E20CUL,
    0x74B1D29AUL,
    0xEAD54739UL,
    0x9DD277AFUL,
    0x04DB2615UL,
    0x73DC1683UL,
    0xE3630B12UL,
    0x94643B84UL,
    0x0D6D6A3EUL,
    0x7A6A5AA8UL,
    0xE40ECF0BUL,
    0x9309FF9DUL,
    0x0A00AE27UL,
    0x7D079EB1UL,
    0xF00F9344UL,
    0x8708A3D2UL,
    0x1E01F268UL,
    0x6906C2FEUL,
    0xF762575DUL,
    0x806567CBUL,
    0x196C3671UL,
    0x6E6B06E7UL,
    0xFED41B76UL,
    0x89D32BE0UL,
    0x10DA7A5AUL,
    0x67DD4ACCUL,
    0xF9B9DF6FUL,
    0x8EBEEFF9UL,
    0x17B7BE43UL,
    0x60B08ED5UL,
    0xD6D6A3E8UL,
    0xA1D1937EUL,
    0x38D8C2C4UL,
    0x4FDFF252UL,
    0xD1BB67F1UL,
    0xA6BC5767UL,
    0x3FB506DDUL,
    0x48B2364BUL,
    0xD80D2BDAUL,
    0xAF0A1B4CUL,
    0x36034AF6UL,
    0x41047A60UL,
    0xDF60EFC3UL,
    0xA867DF55UL,
    0x316E8EEFUL,
    0x4669BE79UL,
    0xCB61B38CUL,
    0xBC66831AUL,
    0x256FD2A0UL,
    0x5268E236UL,
    0xCC0C7795UL,
    0xBB0B4703UL,
    0x220216B9UL,
    0x5505262FUL,
    0xC5BA3BBEUL,
    0xB2BD0B28UL,
    0x2BB45A92UL,
    0x5CB36A04UL,
    0xC2D7FFA7UL,
    0xB5D0CF31UL,
    0x2CD99E8BUL,
    0x5BDEAE1DUL,
    0x9B64C2B0UL,
    0xEC63F226UL,
    0x756AA39CUL,
    0x026D930AUL,
    0x9C0906A9UL,
    0xEB0E363FUL,
    0x72076785UL,
    0x05005713UL,
    0x95BF4A82UL,
    0xE2B87A14UL,
    0x7BB12BAEUL,
    0x0CB61B38UL,
    0x92D28E9BUL,
    0xE5D5BE0DUL,
    0x7CDCEFB7UL,
    0x0BDBDF21UL,
    0x86D3D2D4UL,
    0xF1D4E242UL,
    0x68DDB3F8UL,
    0x1FDA836EUL,
    0x81BE16CDUL,
    0xF6B9265BUL,
    0x6FB077E1UL,
    0x18B74777UL,
    0x88085AE6UL,
    0xFF0F6A70UL,
    0x66063BCAUL,
    0x11010B5CUL,
    0x8F659EFFUL,
    0xF862AE69UL,
    0x616BFFD3UL,
    0x166CCF45UL,
    0xA00AE278UL,
    0xD70DD2EEUL,
    0x4E048354UL,
    0x3903B3C2UL,
    0xA7672661UL,
    0xD06016F7UL,
    0x4969474DUL,
    0x3E6E77DBUL,
    0xAED16A4AUL,
    0xD9D65ADCUL,
    0x40DF0B66UL,
    0x37D83BF0UL,
    0xA9BCAE53UL,
    0xDEBB9EC5UL,
    0x47B2CF7FUL,
    0x30B5FFE9UL,
    0xBDBDF21CUL,
    0xCABAC28AUL,
    0x53B39330UL,
    0x24B4A3A6UL,
    0xBAD03605UL,
    0xCDD70693UL,
    0x54DE5729UL,
    0x23D967BFUL,
    0xB3667A2EUL,
    0xC4614AB8UL,
    0x5D681B02UL,
    0x2A6F2B94UL,
    0xB40BBE37UL,
    0xC30C8EA1UL,
    0x5A05DF1BUL,
    0x2D02EF8DUL};

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
static int32_t ARM_CRC_Control(uint8_t crc_channel, uint8_t polynomial);
static Crc_ChannelRegs Crc_GetChannelRegs(uint8_t channel);
static int32_t CRC_CalculateCRCX(const uint8_t *const data, uint32_t length, uint8_t polynomial, uint32_t initial_seed,
                                 uint8_t channel, uint32_t *const crc);
/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/
static inline bool Crc_AreAllEnginesBusy(const IPC_Crc_ModuleStateType_T *const state)
{
   return (
      (state->Crc_EngineBusyCh0 == (uint32_t)CRC_CH_STATUS_BUSY) && (state->Crc_EngineBusyCh1 == (uint32_t)CRC_CH_STATUS_BUSY) &&
      (state->Crc_EngineBusyCh2 == (uint32_t)CRC_CH_STATUS_BUSY) && (state->Crc_EngineBusyCh3 == (uint32_t)CRC_CH_STATUS_BUSY));
}

#ifndef UNIT_TEST
/*===========================================================================*
 * Function Definitions
 *===========================================================================*/
/**
 * @fn            Reflect32
 * @brief         Reflects the input data bit by bit
 * @param [in]    Data - Data to be reflected.
 *
 * @param [out]   None
 * @return        uint32_t - 32 bit result of reflected data.
 */
static uint32_t Reflect32(uint32_t Data)
{
   /* Add additional variable according to MISRA C:2023:17.8:Advisory */
   uint32_t u32_temp = Data;
   /* Swap individual bits */
   u32_temp = ((u32_temp >> ONE_BIT_SHIFT) & SWAP_32BIT_MASK_INDIV) | ((u32_temp & SWAP_32BIT_MASK_INDIV) << ONE_BIT_SHIFT);
   /* Swap pairs of bits */
   u32_temp = ((u32_temp >> TWO_BIT_SHIFT) & SWAP_32BIT_MASK_PAIRS) | ((u32_temp & SWAP_32BIT_MASK_PAIRS) << TWO_BIT_SHIFT);
   /* Swap high and low 4 bits */
   u32_temp = ((u32_temp >> FOUR_BIT_SHIFT) & SWAP_32BIT_MASK_NIBBLE) | ((u32_temp & SWAP_32BIT_MASK_NIBBLE) << FOUR_BIT_SHIFT);
   /* Swap bytes */
   u32_temp = ((u32_temp >> ONE_BYTE_SHIFT) & SWAP_32BIT_MASK_BYTE) | ((u32_temp & SWAP_32BIT_MASK_BYTE) << ONE_BYTE_SHIFT);
   /* Swap 2 bytes pairs */
   return (u32_temp >> TWO_BYTE_SHIFT) | (u32_temp << TWO_BYTE_SHIFT);
}
static int32_t ARM_CRC_Control(uint8_t crc_channel, uint8_t polynomial)
{
   int32_t crc_status = ARM_DRIVER_ERROR;
   ARM_CRC_CONTROL control;
   control.output_polarity    = Crc_32bit_Ethernet.Crc_OutputFlipPolarity;
   control.output_reverse     = Crc_32bit_Ethernet.Crc_OutputReverseBitEndiannes;
   control.input_bit_reverse  = Crc_32bit_Ethernet.Crc_InputBitReverse;
   control.input_byte_reverse = Crc_32bit_Ethernet.Crc_InputByteReverse;
   control.input_byte_shift   = Crc_32bit_Ethernet.Crc_InputByteShift;

   /* Check that the arguments crc_channel and polynomial are within the range */
   if ((crc_channel < ARM_CRC_OUT_OF_RANGE) && (polynomial < POLY_OUT_OF_RANGE))
   {
      crc_status = (int32_t)ARM_DRIVER_OK;

      if (crc_channel == ARM_CRC_CHANNEL0) /* Check if the state of channel 0 is free */
      {
         ptr_crc->CH0_CTL.f.OUT_POL  = control.output_polarity;
         ptr_crc->CH0_CTL.f.OUT_REV  = control.output_reverse;
         ptr_crc->CH0_CTL.f.BIT_REV  = control.input_bit_reverse;
         ptr_crc->CH0_CTL.f.BYTE_REV = control.input_byte_reverse;
         ptr_crc->CH0_CTL.f.BYTE_SHIFT =
            control.input_byte_shift; /**< Number of bytes to right shift input Data after byte and bit reversing */
      }
      else if (crc_channel == ARM_CRC_CHANNEL1)
      {
         ptr_crc->CH1_CTL.f.OUT_POL    = control.output_polarity;
         ptr_crc->CH1_CTL.f.OUT_REV    = control.output_reverse;
         ptr_crc->CH1_CTL.f.BIT_REV    = control.input_bit_reverse;
         ptr_crc->CH1_CTL.f.BYTE_REV   = control.input_byte_reverse;
         ptr_crc->CH1_CTL.f.BYTE_SHIFT = control.input_byte_shift;
      }
      else if (crc_channel == ARM_CRC_CHANNEL2)
      {
         ptr_crc->CH2_CTL.f.OUT_POL = control.output_polarity;
         ptr_crc->CH2_CTL.f.OUT_REV = control.output_reverse;
         ptr_crc->CH2_CTL.f.BIT_REV =
            control.input_bit_reverse; /**< Reverse Bit Order of Data written into CRC engine; within byte boundary */
         ptr_crc->CH2_CTL.f.BYTE_REV   = control.input_byte_reverse; /**< Reverse Byte Order of Data written into CRC engine */
         ptr_crc->CH2_CTL.f.BYTE_SHIFT = control.input_byte_shift;
      }
      else
      {
         /*  crc_channel == ARM_CRC_CHANNEL3  */
         ptr_crc->CH3_CTL.f.OUT_POL = control.output_polarity;
         ptr_crc->CH3_CTL.f.OUT_REV = control.output_reverse;
         ptr_crc->CH3_CTL.f.BIT_REV =
            control.input_bit_reverse; /**< Reverse Bit Order of Data written into CRC engine; within byte boundary */
         ptr_crc->CH3_CTL.f.BYTE_REV   = control.input_byte_reverse; /**< Reverse Byte Order of Data written into CRC engine */
         ptr_crc->CH3_CTL.f.BYTE_SHIFT = control.input_byte_shift;
      }
   }
   else
   {
      crc_status = ARM_DRIVER_ERROR_PARAMETER;
   }
   return crc_status;
}

static int32_t ARM_CRC_CalculateCRC32(const uint8_t *const data, uint32_t length, uint8_t polynomial, uint32_t initial_seed,
                                      uint8_t channel, uint32_t *const crc)
{
   int32_t crc_status = ARM_DRIVER_ERROR;
   if ((NULL != data) && (NULL != crc) && (length > 0) && (ARM_CRC_POLYNOMIAL_END > polynomial))
   {
      crc_status = CRC_CalculateCRCX(data, length, polynomial, initial_seed, channel, crc);
      *crc ^= Crc_32bit_Ethernet.Crc_XorValue;
   }
   return crc_status;
}
/**
 * @fn            Crc_CalculateCRC32
 * @id            0x03
 * @sync          Synchronous
 * @reentrancy    Reentrant
 * @requirements  SWS_Crc_00020
 * @brief         This service makes a CRC32 calculation on Crc_Length data bytes.
 * @param [in]    Crc_DataPtr - Pointer to start address of data block to be calculated.
 * @param [in]    Crc_Length - Length of data block to be calculated in bytes.
 * @param [in]    Crc_StartValue32 - Start value when the algorithm starts.
 * @param [in]    Crc_IsFirstCall - TRUE: First call in a sequence or individual CRC calculation; start from initial value, ignore
 * Crc_StartValue32.
 *                                - FALSE: Subsequent call in a call sequence; Crc_StartValue32 is interpreted to be the return
 * value of the previous function call.
 * @param [out]   None
 * @return        uint32_t - 32 bit result of CRC calculation.
 */
static uint32_t Crc_CalculateCRC32_HW(
   const uint8_t *Crc_DataPtr, uint32_t Crc_Length, uint32_t Crc_StartValue32, bool Crc_IsFirstCall,
   uint8_t channel) /* polyspace DEFECT:UNMODIFIED_VAR_NOT_CONST "It is defined by the AUTOSAR specifications SWS_Crc_00020" */
{
   uint32_t Crc32                    = 0;
   IPC_Shared_Buffers_T *Ipc_buf_add = (IPC_Shared_Buffers_T *)Get_Ipc_Shared_Buffer_Base_Address();
   /* Start value*/
   if (Crc_IsFirstCall)
   {
      Crc32 = Crc_32bit_Ethernet.Crc_InitValue;
   }
   else
   {
      Crc32 = Crc_StartValue32 ^ Crc_32bit_Ethernet.Crc_XorValue;
      Crc32 = REV32(Crc32);
   }

   /* Hardware based CRC32 calculation */
   while (Crc_AreAllEnginesBusy(&Ipc_buf_add->Crc_ModuleState)) /* TODO: Enhancement can be applied on BAR-5701 */
   {
      /* stuck till the any crc channel is free */
   }
   if ((ARM_CRC_CHANNEL0 == channel) && ((uint8_t)CRC_CH_STATUS_BUSY != Ipc_buf_add->Crc_ModuleState.Crc_EngineBusyCh0))
   {
      Ipc_buf_add->Crc_ModuleState.Crc_EngineBusyCh0 = (uint8_t)CRC_CH_STATUS_BUSY;
      ARM_CRC_Control(CRC_CH_0, ARM_CRC_CRC32_POLY_04C11DB7H);
      ARM_CRC_CalculateCRC32(Crc_DataPtr, Crc_Length, ARM_CRC_CRC32_POLY_04C11DB7H, Crc32, CRC_CH_0, &(Crc32));
      Ipc_buf_add->Crc_ModuleState.Crc_EngineBusyCh0 = (uint8_t)CRC_CH_STATUS_FREE;
   }
   else if ((ARM_CRC_CHANNEL1 == channel) && ((uint8_t)CRC_CH_STATUS_BUSY != Ipc_buf_add->Crc_ModuleState.Crc_EngineBusyCh1))
   {
      Ipc_buf_add->Crc_ModuleState.Crc_EngineBusyCh1 = (uint8_t)CRC_CH_STATUS_BUSY;
      ARM_CRC_Control(CRC_CH_1, ARM_CRC_CRC32_POLY_04C11DB7H);
      ARM_CRC_CalculateCRC32(Crc_DataPtr, Crc_Length, ARM_CRC_CRC32_POLY_04C11DB7H, Crc32, CRC_CH_1, &(Crc32));
      Ipc_buf_add->Crc_ModuleState.Crc_EngineBusyCh1 = (uint8_t)CRC_CH_STATUS_FREE;
   }
   else if ((ARM_CRC_CHANNEL2 == channel) && ((uint8_t)CRC_CH_STATUS_BUSY != Ipc_buf_add->Crc_ModuleState.Crc_EngineBusyCh2))
   {
      Ipc_buf_add->Crc_ModuleState.Crc_EngineBusyCh2 = (uint8_t)CRC_CH_STATUS_BUSY;
      ARM_CRC_Control(CRC_CH_2, ARM_CRC_CRC32_POLY_04C11DB7H);
      ARM_CRC_CalculateCRC32(Crc_DataPtr, Crc_Length, ARM_CRC_CRC32_POLY_04C11DB7H, Crc32, CRC_CH_2, &(Crc32));
      Ipc_buf_add->Crc_ModuleState.Crc_EngineBusyCh2 = (uint8_t)CRC_CH_STATUS_FREE;
   }
   else if ((ARM_CRC_CHANNEL3 == channel) && ((uint8_t)CRC_CH_STATUS_BUSY != Ipc_buf_add->Crc_ModuleState.Crc_EngineBusyCh3))
   {
      Ipc_buf_add->Crc_ModuleState.Crc_EngineBusyCh3 = (uint8_t)CRC_CH_STATUS_BUSY;
      ARM_CRC_Control(CRC_CH_3, ARM_CRC_CRC32_POLY_04C11DB7H);
      ARM_CRC_CalculateCRC32(Crc_DataPtr, Crc_Length, ARM_CRC_CRC32_POLY_04C11DB7H, Crc32, CRC_CH_3, &(Crc32));
      Ipc_buf_add->Crc_ModuleState.Crc_EngineBusyCh3 = (uint8_t)CRC_CH_STATUS_FREE;
   }
   else
   {
      /* Do Nothing */
   }
   return Crc32;
}

/*****************************************************************************
 *. Name: CRC_CalculateCRCX
 *. This function will calculate 32 bit CRC for the input data
 *. using hardware CRC
 *.
 *. Parameters:
 *. data - pointer to input data
 *. length - length of input data
 *  polynomial - Polynomial used for hardware crc
 *. initial_seed - seed value for CRC calculation
 *. crc - calculated crc
 *.
 *. Return Value: 32 bit unsigned int
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
static int32_t CRC_CalculateCRCX(const uint8_t *const data, uint32_t length, uint8_t polynomial, uint32_t initial_seed,
                                 uint8_t channel, uint32_t *const crc)
{
   int32_t crc_status = ARM_DRIVER_ERROR;
   uint32_t cnt       = 0;
   uint32_t temp      = 0;

   if (channel == ARM_CRC_CHANNEL0)
   {
      ptr_crc->CH0_CTL.f.POLY = polynomial;
   }
   else if (channel == ARM_CRC_CHANNEL1)
   {
      ptr_crc->CH1_CTL.f.POLY = polynomial;
   }
   else if (channel == ARM_CRC_CHANNEL2)
   {
      ptr_crc->CH2_CTL.f.POLY = polynomial;
   }
   else if (channel == ARM_CRC_CHANNEL3)
   {
      ptr_crc->CH3_CTL.f.POLY = polynomial;
   }
   else
   {
      crc_status = ARM_DRIVER_ERROR_BUSY;
   }
   if (((uintptr_t)data % ALIGNOF(uint64_t)) == 0)
   {
      const uint64_t *const u64LargeDataPtr = (const uint64_t *)ASSUME_ALIGNED(data, ALIGNOF(uint64_t));
      const uint32_t *const u32LargeDataPtr = (const uint32_t *)ASSUME_ALIGNED(data, ALIGNOF(uint32_t));

      const uint32_t words_length      = length / sizeof(uint32_t);
      const uint32_t b128_words_length = words_length / sizeof(uint32_t);
      const uint8_t remaining_bytes = (uint8_t)(length - (sizeof(uint32_t) * words_length)); /* find the remaining no. of bytes */
      const uint8_t remaining_words =
         (uint8_t)(words_length - (sizeof(uint32_t) * b128_words_length)); /* find the remaining no. of full words */
      /* Retrieve register pointers corresponding to the selected CRC channel */
      Crc_ChannelRegs regs = Crc_GetChannelRegs(channel);
      /*Initialize seed and set PAR to ARM_CRC_INIT_CTL_PAR_SEL*/
      *regs.INIT = initial_seed;
      *regs.CTL &= ~CRC_CTL_PAR_MASK;
      *regs.CTL |= (ARM_CRC_INIT_CTL_PAR_SEL & CRC_CTL_PAR_MASK); /* Set the Parallelism to send 4 bytes to the input reg. */
      for (cnt = 0; cnt < b128_words_length; cnt += 2)
      {
         *(regs.XIN[0]) = (uint32_t)(u64LargeDataPtr[cnt]);
         *(regs.XIN[1]) = (uint32_t)(u64LargeDataPtr[cnt] >> 32);
         *(regs.XIN[2]) = (uint32_t)(u64LargeDataPtr[cnt + 1]);
         *(regs.XIN[3]) = (uint32_t)(u64LargeDataPtr[cnt + 1] >> 32);
      }
      if (remaining_words != 0)
      {
         switch (remaining_words)
         {
            case 1:
               *(regs.XIN[0]) = u32LargeDataPtr[words_length - 1];
               break;
            case 2:
               *(regs.XIN[0]) = u32LargeDataPtr[words_length - 2];
               *(regs.XIN[1]) = u32LargeDataPtr[words_length - 1];
               break;
            default:
               /* remaining_words = 3 */
               *(regs.XIN[0]) = u32LargeDataPtr[words_length - 3];
               *(regs.XIN[1]) = u32LargeDataPtr[words_length - 2];
               *(regs.XIN[2]) = u32LargeDataPtr[words_length - 1];
               break;
         }
      }
      if (remaining_bytes != 0)
      {
         /*clear rev_bit and set PAR to (remaining_bytes - 1) */
         *regs.CTL &= ~CRC_CTL_BYTE_REV_BIT_MASK;
         *regs.CTL &= ~CRC_CTL_PAR_MASK;
         *regs.CTL |= (remaining_bytes - 1) & CRC_CTL_PAR_MASK;

         switch (remaining_bytes)
         {
            case REMAINING_3_BYTES:
               temp = ((uint32_t)data[length - 3] << SHIFT_16_BITS) | ((uint32_t)data[length - 2] << SHIFT_8_BITS) |
                      ((uint32_t)data[length - 1]);
               break;
            case REMAINING_2_BYTES:
               temp = ((uint32_t)data[length - 2] << SHIFT_8_BITS) | ((uint32_t)data[length - 1]);
               break;
            default:
               /* One byte remain */
               temp = (uint32_t)data[length - 1];
               break;
         }
         *(regs.XIN[0]) = temp;
      }

      /* Get the CRC result */
      *crc = *regs.OUT;
   }
   else
   {
      /* Number of unaligned bytes */
      const uint8_t bytes_until_aligned = (uint8_t)(ALIGNOF(uint64_t) - ((uint32_t)data % ALIGNOF(uint64_t)));
      if (bytes_until_aligned >= length)
      {
         /* Retrieve register pointers corresponding to the selected CRC channel */
         Crc_ChannelRegs regs = Crc_GetChannelRegs(channel);
         /* Initialize seed and clear PAR and BYTE_REV bits */
         *regs.INIT = initial_seed;
         *regs.CTL &= ~(CRC_CTL_PAR_MASK | CRC_CTL_BYTE_REV_BIT_MASK);
         for (cnt = 0; cnt < length; cnt++)
         {
            *(regs.XIN[0]) = data[cnt];
         }

         *crc = *(regs.OUT);
      }
      else
      {
         /* Handle the unaligned bytes by processing byte by byte computation */
         uint32_t words_length   = bytes_until_aligned / sizeof(uint32_t);
         uint8_t remaining_bytes = 0; /* find the remaining no. of bytes */

         Crc_ChannelRegs regs = Crc_GetChannelRegs(channel);
         /* Initialize seed and clear PAR and BYTE_REV bits */
         *regs.INIT = initial_seed;
         *regs.CTL &= ~(CRC_CTL_PAR_MASK | CRC_CTL_BYTE_REV_BIT_MASK);
         for (cnt = 0; cnt < bytes_until_aligned; cnt++)
         {
            *(regs.XIN[0]) = data[cnt]; /*Input data to the CRC engine*/
         }

         /* use the aligned ptr to compute with it*/
         const uint64_t *const u64LargeDataPtr =
            (const uint64_t *)ASSUME_ALIGNED(&((const uint8_t *)data)[bytes_until_aligned], ALIGNOF(uint64_t));
         const uint32_t *const u32LargeDataPtr =
            (const uint32_t *)ASSUME_ALIGNED(&((const uint8_t *)data)[bytes_until_aligned], ALIGNOF(uint32_t));

         words_length                     = (length - bytes_until_aligned) / sizeof(uint32_t);
         const uint32_t b128_words_length = words_length / sizeof(uint32_t);
         const uint8_t remaining_words =
            (uint8_t)(words_length - (sizeof(uint32_t) * b128_words_length)); /* find the remaining no. of full words */
         remaining_bytes =
            (uint8_t)((length - bytes_until_aligned) - (sizeof(uint32_t) * words_length)); /* find the remaining no. of bytes */
         crc_status = ARM_DRIVER_OK;
         /* Set PAR to ARM_CRC_INIT_CTL_PAR_SEL, and set BYTE_REV */
         *regs.CTL = (*(regs.CTL) & ~CRC_CTL_PAR_MASK) | (ARM_CRC_INIT_CTL_PAR_SEL & CRC_CTL_PAR_MASK);
         *regs.CTL |= CRC_CTL_BYTE_REV_BIT_MASK;
         for (cnt = 0; cnt < (b128_words_length); cnt += 2)
         {
            *(regs.XIN[0]) = (uint32_t)u64LargeDataPtr[cnt];             /*Input data to the CRC engine */
            *(regs.XIN[1]) = (uint32_t)(u64LargeDataPtr[cnt] >> 32);     /*Input data to the CRC engine */
            *(regs.XIN[2]) = (uint32_t)u64LargeDataPtr[cnt + 1];         /*Input data to the CRC engine */
            *(regs.XIN[3]) = (uint32_t)(u64LargeDataPtr[cnt + 1] >> 32); /*Input data to the CRC engine */
         }
         if (remaining_words != 0)
         {
            switch (remaining_words)
            {
               case 1:
                  *(regs.XIN[0]) = u32LargeDataPtr[words_length - 1]; /*Input data to the CRC engine */
                  break;
               case 2:
                  *(regs.XIN[0]) = u32LargeDataPtr[words_length - 2];
                  *(regs.XIN[1]) = u32LargeDataPtr[words_length - 1]; /*Input data to the CRC engine */
                  break;
               default:
                  /* remaining_words = 3 */
                  *(regs.XIN[0]) = u32LargeDataPtr[words_length - 3];
                  *(regs.XIN[1]) = u32LargeDataPtr[words_length - 2];
                  *(regs.XIN[2]) = u32LargeDataPtr[words_length - 1]; /*Input data to the CRC engine */
                  break;
            }
         }
         else
         {
            /* Do Nothing */
         }
         if (remaining_bytes != 0)
         {
            /* Clear BYTE_REV bit and update PAR with (remaining_bytes - 1) */
            *regs.CTL &= ~CRC_CTL_BYTE_REV_BIT_MASK;
            *regs.CTL = (*regs.CTL & ~CRC_CTL_PAR_MASK) | ((remaining_bytes - 1) & CRC_CTL_PAR_MASK);
            switch (remaining_bytes)
            {
               /* In case of 3 bytes remaining */
               case REMAINING_3_BYTES:
                  temp = (uint32_t)data[length - 3] << SHIFT_16_BITS | (((uint32_t)data[length - 2]) << SHIFT_8_BITS) |
                         ((uint32_t)data[length - 1]);
                  break;
               /* In case of 2 bytes remaining */
               case REMAINING_2_BYTES:
                  temp = ((uint32_t)data[length - 1]) | (uint32_t)data[length - 2] << SHIFT_8_BITS;
                  break;
               default:
                  /* In case of 1 byte remaining */
                  temp = ((uint32_t)data[length - 1]);
                  break;
            }
            *(regs.XIN[0]) = temp; /*Input data to the CRC engine */
         }
         else
         {
            /* do nothing */
         }

         /* Get the calculated crc from output register */
         *crc = *(regs.OUT);
      }
   }
   return crc_status;
}

static Crc_ChannelRegs Crc_GetChannelRegs(uint8_t channel)
{
   Crc_ChannelRegs regs = {0};
   switch (channel)
   {
      case ARM_CRC_CHANNEL0:
         regs.INIT   = &ptr_crc->CH0_INIT;
         regs.CTL    = &ptr_crc->CH0_CTL.r;
         regs.XIN[0] = &ptr_crc->CH0_XIN0;
         regs.XIN[1] = &ptr_crc->CH0_XIN1;
         regs.XIN[2] = &ptr_crc->CH0_XIN2;
         regs.XIN[3] = &ptr_crc->CH0_XIN3;
         regs.OUT    = &ptr_crc->CH0_OUT;
         break;
      case ARM_CRC_CHANNEL1:
         regs.INIT   = &ptr_crc->CH1_INIT;
         regs.CTL    = &ptr_crc->CH1_CTL.r;
         regs.XIN[0] = &ptr_crc->CH1_XIN0;
         regs.XIN[1] = &ptr_crc->CH1_XIN1;
         regs.XIN[2] = &ptr_crc->CH1_XIN2;
         regs.XIN[3] = &ptr_crc->CH1_XIN3;
         regs.OUT    = &ptr_crc->CH1_OUT;
         break;
      case ARM_CRC_CHANNEL2:
         regs.INIT   = &ptr_crc->CH2_INIT;
         regs.CTL    = &ptr_crc->CH2_CTL.r;
         regs.XIN[0] = &ptr_crc->CH2_XIN0;
         regs.XIN[1] = &ptr_crc->CH2_XIN1;
         regs.XIN[2] = &ptr_crc->CH2_XIN2;
         regs.XIN[3] = &ptr_crc->CH2_XIN3;
         regs.OUT    = &ptr_crc->CH2_OUT;
         break;
      case ARM_CRC_CHANNEL3:
         regs.INIT   = &ptr_crc->CH3_INIT;
         regs.CTL    = &ptr_crc->CH3_CTL.r;
         regs.XIN[0] = &ptr_crc->CH3_XIN0;
         regs.XIN[1] = &ptr_crc->CH3_XIN1;
         regs.XIN[2] = &ptr_crc->CH3_XIN2;
         regs.XIN[3] = &ptr_crc->CH3_XIN3;
         regs.OUT    = &ptr_crc->CH3_OUT;
         break;
      default:
         // Return zeroed struct on invalid channel
         break;
   }

   return regs;
}
#endif
/******************************************************************************
 * Name:  Compute_CRC32_SW
 *   This function calculates 32-bit CRC using SW CRC
 *
 * Shared Variables: none
 *
 * Parameters:
 *    uint8_t  *data - address of payload from which crc is to be calculated,
 *    uint32_t data_len - defines the length of payload upto which crc is to be calculated
 *    uint32_t start_value - start value of crc in case it is not FirstCall
 *    bool firstCall - TRUE- SW_IPC_CRC_INITIAL_VALUE32 is used. FALSE- start_value is used
 *
 * Return Value:
 *    uint16_t - error in crc calculation
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 ******************************************************************************/
uint32_t Compute_CRC32_SW(uint8_t *data, uint32_t data_len, uint32_t start_value, bool firstCall)
{
   uint32_t sw_ipc_crc_value;
   uint32_t sw_ipc_crc_loopcounter;

   if (firstCall)
   {
      sw_ipc_crc_value = SW_IPC_CRC_INITIAL_VALUE32;
   }
   else
   {
      sw_ipc_crc_value = (SW_IPC_CRC_FINAL_XOR_CRC32 ^ start_value);
   }

   /* Calculate CRC using table */
   for (sw_ipc_crc_loopcounter = 0; sw_ipc_crc_loopcounter < data_len; sw_ipc_crc_loopcounter++)
   {
      sw_ipc_crc_value ^= (uint32_t)data[sw_ipc_crc_loopcounter];
      sw_ipc_crc_value = (sw_ipc_crc_value >> 8u) ^ (SW_IPC_Crc_Table32[(uint8_t)(sw_ipc_crc_value)]);
   }

   return (uint32_t)(sw_ipc_crc_value ^ SW_IPC_CRC_FINAL_XOR_CRC32);
}
/******************************************************************************
 *. Name: Calc_M2D_Buf_Crc
 *. This function calculate crc for critical signals of IPC M2D buffer
 *.
 *. Parameters:  M2D_Msg_T *buffer_ptr
 *. Return Value: int32_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues: EUR-2051
 ******************************************************************************/
uint32_t Calc_M2D_Buf_Crc(volatile const M2D_Msg_T *buffer_ptr)
{
   uint8_t idx;
   uint8_t idx_max  = 0U;
   uint32_t crc_val = 0U;
   if (NULL != buffer_ptr)
   {
      memset((void *)&M2D_Crc_Calc_Sig, 0U, sizeof(M2D_Crc_Calc_Sig));
      memset((void *)&IPC_M2D_Crc_Cal_Tab, 0U, sizeof(IPC_M2D_Crc_Cal_Tab));

      M2D_Crc_Calc_Sig[idx_max].startAddr = (uint32_t *)&(buffer_ptr->payload.look_Info);
      M2D_Crc_Calc_Sig[idx_max].size      = sizeof(buffer_ptr->payload.look_Info);
      idx_max++;

      M2D_Crc_Calc_Sig[idx_max].startAddr = (uint32_t *)&(buffer_ptr->payload.veh_data);
      M2D_Crc_Calc_Sig[idx_max].size      = sizeof(buffer_ptr->payload.veh_data);
      idx_max++;

      M2D_Crc_Calc_Sig[idx_max].startAddr = (uint32_t *)&(buffer_ptr->payload.Radar_Sts_Ptr);
      M2D_Crc_Calc_Sig[idx_max].size      = sizeof(buffer_ptr->payload.Radar_Sts_Ptr);
      idx_max++;

      M2D_Crc_Calc_Sig[idx_max].startAddr = (uint32_t *)&(buffer_ptr->payload.alignment_Info);
      M2D_Crc_Calc_Sig[idx_max].size      = sizeof(buffer_ptr->payload.alignment_Info);
      idx_max++;
   }
   M2D_Crc_Calc_Sig[idx_max].startAddr = (uint32_t *)&(IPC_M2D_Crc_Cal_Tab[0]);
   /*Last index is final crc so excluded from crc calculation*/
   M2D_Crc_Calc_Sig[idx_max].size = (sizeof(IPC_M2D_Crc_Cal_Tab) - sizeof(uint32_t));
   idx_max++;

   /* Calculate crc or checksum */
   for (idx = 0U; idx < idx_max; idx++)
   {
      if (NULL != M2D_Crc_Calc_Sig[idx].startAddr)
      {
         crc_val = Compute_CRC32_SW((uint8_t *)((M2D_Crc_Calc_Sig[idx].startAddr)), (uint32_t)(M2D_Crc_Calc_Sig[idx].size),
                                    0xFFFFFFFFU, false);
      }
      IPC_M2D_Crc_Cal_Tab[idx] = crc_val;
   }
   return (crc_val);
}

/******************************************************************************
 *. Name: Calc_D2M_Buf_Crc_Chn_X
 *. This function calculate crc for critical signals of IPC D2M buffer
 *.
 *. Parameters:  D2M_Msg_T *buffer_ptr
 *.              uint8_t Channel
 *. Return Value: uint32_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues: DDR-4370
 ******************************************************************************/
uint32_t __attribute__((noinline)) Calc_D2M_Buf_Crc_Chn_X(volatile D2M_Msg_T *buffer_ptr, uint8_t Channel)
{
   uint8_t idx;
   uint8_t idx_max  = 0U;
   uint32_t crc_val = 0U;
   if (buffer_ptr != NULL)
   {
      memset((void *)&D2M_Crc_Calc_Sig, 0U, sizeof(D2M_Crc_Calc_Sig));
      memset((void *)&IPC_D2M_Crc_Cal_Tab, 0U, sizeof(IPC_D2M_Crc_Cal_Tab));

      D2M_Crc_Calc_Sig[idx_max].startAddr = (uint32_t *)&(buffer_ptr->payload.diag_data);
      D2M_Crc_Calc_Sig[idx_max].size      = sizeof(buffer_ptr->payload.diag_data);
      idx_max++;

      D2M_Crc_Calc_Sig[idx_max].startAddr = (uint32_t *)&(buffer_ptr->payload.radar_capability_data.fault_table);
      D2M_Crc_Calc_Sig[idx_max].size      = sizeof(buffer_ptr->payload.radar_capability_data.fault_table);
      idx_max++;

#if (DOWNSELECTION_ENABLE)
      D2M_Crc_Calc_Sig[idx_max].startAddr = (uint32_t *)&(buffer_ptr->payload.downselection_data.af_ds_dets);
      D2M_Crc_Calc_Sig[idx_max].size      = sizeof(buffer_ptr->payload.downselection_data.af_ds_dets);
      idx_max++;
      D2M_Crc_Calc_Sig[idx_max].startAddr = (uint32_t *)&(buffer_ptr->payload.toi_ds_stream_data.toi_ip_data);
      D2M_Crc_Calc_Sig[idx_max].size =
         sizeof(buffer_ptr->payload.toi_ds_stream_data.toi_ip_data) + sizeof(buffer_ptr->payload.toi_ds_stream_data.toi_op_data);
      idx_max++;
#else
      D2M_Crc_Calc_Sig[idx_max].startAddr = (uint32_t *)&(buffer_ptr->payload.det_data.af_dets);
      D2M_Crc_Calc_Sig[idx_max].size      = sizeof(buffer_ptr->payload.det_data.af_dets);
      idx_max++;
      D2M_Crc_Calc_Sig[idx_max].startAddr = (uint32_t *)&(buffer_ptr->payload.toi_stream_data.toi_ip_data);
      D2M_Crc_Calc_Sig[idx_max].size =
         sizeof(buffer_ptr->payload.toi_stream_data.toi_ip_data) + sizeof(buffer_ptr->payload.toi_stream_data.toi_op_data);
      idx_max++;
#endif
      D2M_Crc_Calc_Sig[idx_max].startAddr = (uint32_t *)&(buffer_ptr->payload.alignment_stream_data);
      D2M_Crc_Calc_Sig[idx_max].size      = sizeof(buffer_ptr->payload.alignment_stream_data);
      idx_max++;

      D2M_Crc_Calc_Sig[idx_max].startAddr = (uint32_t *)&(buffer_ptr->payload.dynamic_alignment_log_stream);
      D2M_Crc_Calc_Sig[idx_max].size      = sizeof(buffer_ptr->payload.dynamic_alignment_log_stream);
      idx_max++;
   }
   D2M_Crc_Calc_Sig[idx_max].startAddr = (uint32_t *)&(IPC_D2M_Crc_Cal_Tab[0]);
   /*Last index is final crc so excluded from crc calculation*/
   D2M_Crc_Calc_Sig[idx_max].size = (sizeof(IPC_D2M_Crc_Cal_Tab) - sizeof(uint32_t));
   idx_max++;
   /* Calculate crc or checksum */
   for (idx = 0U; idx < idx_max; idx++)
   {
      if (NULL != D2M_Crc_Calc_Sig[idx].startAddr)
      {
         if (ARM_CRC_CHANNEL0 == Channel)
         {
            crc_val = Crc_CalculateCRC32_HW((uint8_t *)(D2M_Crc_Calc_Sig[idx].startAddr), (uint32_t)(D2M_Crc_Calc_Sig[idx].size),
                                            0xFFFFFFFFU, false, ARM_CRC_CHANNEL0);
         }
         else if (ARM_CRC_CHANNEL1 == Channel)
         {
            crc_val = Crc_CalculateCRC32_HW((uint8_t *)(D2M_Crc_Calc_Sig[idx].startAddr), (uint32_t)(D2M_Crc_Calc_Sig[idx].size),
                                            0xFFFFFFFFU, false, ARM_CRC_CHANNEL1);
         }
      }
      IPC_D2M_Crc_Cal_Tab[idx] = crc_val;
   }
   return (crc_val);
}

/******************************************************************************
 *. Name: Test_CRC_Channels
 *. This function tests CRC calculation on both Channel 0 and Channel 1
 *. to verify they are working as expected
 *.
 *. Parameters: None
 *. Return Value: uint32_t - Test result status
 *.               0 = All tests passed
 *.               Non-zero = Test failures (bit mask of failed tests)
 *.
 *. Test Vectors:
 *.   Known CRC32/Ethernet test vectors for validation
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 ******************************************************************************/
#ifdef ENABLE_CRC_TESTS
uint32_t Test_CRC_Channels(void)
{
   uint32_t test_result = 0U;

   /* Test Vector: "123456789" - Standard CRC32/Ethernet test string */
   /* Expected CRC32/Ethernet check value: 0xCBF43926 */
   const uint8_t test_data[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
   const uint32_t test_len   = sizeof(test_data);

   /* HW Channel 0 CRC - result stored in global g_crc_hw_result */
   g_crc_hw_result_0 = Crc_CalculateCRC32_HW(test_data, test_len, 0xFFFFFFFFU, true, ARM_CRC_CHANNEL0);
   /* HW Channel 1 CRC - result stored in global g_crc_hw_result */
   g_crc_hw_result_1 = Crc_CalculateCRC32_HW(test_data, test_len, 0xFFFFFFFFU, true, ARM_CRC_CHANNEL1);

   /* SW CRC - result stored in global g_crc_sw_result */
   g_crc_sw_result = Compute_CRC32_SW((uint8_t *)test_data, test_len, 0xFFFFFFFFU, true);

   /* Bit 0: HW vs SW mismatch */
   if (g_crc_hw_result_0 != g_crc_sw_result)
   {
      test_result |= (1U << 0);
   }
   /* Bit 1: HW vs SW mismatch */
   if (g_crc_hw_result_1 != g_crc_sw_result)
   {
      test_result |= (1U << 1);
   }
   /* Bit 2: SW CRC does not match standard check value 0xCBF43926 */
   if (g_crc_sw_result != 0xCBF43926U)
   {
      test_result |= (1U << 2);
   }

   return test_result;
}
#endif

/*============================================================================*\
 * AUTHOR(S) IDENTITY (AID)
 *-----------------------------------------------------------------------------
 *
 *  AID         NAME
 *  ---------------------------------------------------------------------------
 *  XXX         Firstname Lastname
 *  tjy9rb     Deepak Kumar Pandey
\*============================================================================*/

/* END OF FILE -------------------------------------------------------------- */
