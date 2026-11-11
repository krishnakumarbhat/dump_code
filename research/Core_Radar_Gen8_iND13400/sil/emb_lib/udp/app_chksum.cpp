/*===========================================================================*/
/**
 * @file app_chksum.c
 *
 * Description: This file contains the functions to calculate checksum
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2023 Aptiv. All rights reserved.
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
#include "reuse.h"

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "app_chksum.h"
#include "stream_header.h"
//#include <drivers/hw_include/awr294x/cslr_soc_baseaddress.h>
//#include <drivers/hw_include/csl_types.h>
//#include <drivers/hw_include/hw_types.h>
/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define ONE_SECTOR_CNT (1U)
#ifdef ENABLE_CHECKSUM
   #define GET_LEN(xsum_len) (xsum_len)
#else
   #define GET_LEN(xsum_len) (0U)
#endif
/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 * Name:  CalcSum16
 *   This function calculates a 16-bit checksum -
 *      based on addition of all bytes of payload
 *
 * Shared Variables: none
 *
 * Parameters:
 *    const uint8_t *ptr - address of payload from which crc is to be calculated,
 *    uint32_t len - defines the length of payload upto which crc is to be calculated
 *
 * Return Value:
 *    uint16_t - calculated crc
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 ******************************************************************************/
uint16_t CalcSum16(const uint8_t *ptr, uint32_t len)
{
   uint16_t sum = 0U;

   /* enable it when necessary */
   uint8_t byte;
   while (len--)
   {
      byte = *ptr++;
      sum += byte;
   }

   return sum;
}

/******************************************************************************
 * Name:  Compute_CRC32_Ch2
 *   This function calculates 32-bit CRC using HW CRC module
 *
 * Shared Variables: none
 *
 * Parameters:
 *    uint32_t *data - address of payload from which crc is to be calculated,
 *    uint32_t data_len - defines the length of payload upto which crc is to be calculated
 *    uint32_t *crc - computed 32 bit crc
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
#if 0
int32_t Compute_CRC32_Ch2(uint32_t *data, uint32_t data_len, uint32_t *crc)
{
   crcSignature_t signature;
   crcSignatureRegAddr_t psa_sign_reg_addr;
   uint32_t pattern_cnt;
   uint32_t loop_cnt;
   crcConfig_t config;
   int32_t ret_val = CSL_PASS;

   #if defined(_TMS320C6X)
   CRC_Cfg_T CRC_Cfg = {(uint32_t)CSL_DSS_MCRC_U_BASE, CRC_CHANNEL_2};
   #else
   CRC_Cfg_T CRC_Cfg = {(uint32_t)CSL_MSS_MCRC_U_BASE, CRC_CHANNEL_2};
   #endif
   pattern_cnt = (uint32_t)(data_len / sizeof(uint32_t));

   config.mode         = CRC_OPERATION_MODE_FULLCPU;
   config.type         = CRC_TYPE_32BIT;
   config.dataLen      = CRC_DATALENGTH_32BIT;
   config.bitSwap      = CRC_BITSWAP_MSB;
   config.byteSwap     = CRC_BYTESWAP_ENABLE;
   config.patternCount = pattern_cnt;
   config.sectorCount  = ONE_SECTOR_CNT;

   ret_val = CRCConfigure(CRC_Cfg.crc_base_addr, CRC_Cfg.crc_channel, &config);

   if (CSL_PASS == ret_val)
   {
      /* Get CRC PSA signature register address */
      CRCGetPSASigRegAddr(CRC_Cfg.crc_base_addr, CRC_Cfg.crc_channel, &psa_sign_reg_addr);

      /* Reset the CRC channel*/
      CRCChannelReset(CRC_Cfg.crc_base_addr, CRC_Cfg.crc_channel);
      /* compute the CRC by writing the data buffer on which CRC computation is needed */
      for (loop_cnt = 0; loop_cnt < pattern_cnt; loop_cnt++)
      {
         HW_WR_REG32(psa_sign_reg_addr.regL, (uint32_t)data[loop_cnt]);
      }

      /* Fetch CRC signature value */
      ret_val = CRCGetPSASig(CRC_Cfg.crc_base_addr, CRC_Cfg.crc_channel, &signature);

      *(crc) = signature.regL;

      /* CRC signature has been computed correctly */
   }
   else
   {
      /* Error: Unable to configure CRC module. */
   }
   return ((int32_t)ret_val);
}
#endif
/*===========================================================================*
 * Function Definitions
 *===========================================================================*/
/*===========================================================================*\
 * FUNCTION: Calculate_Checksum
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void * ptr
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Calculates checksum for a stream
\*===========================================================================*/
void Calculate_Checksum(uint8_t *ptr, uint32_t len)
{
   Stream_Hdr_T *hdr_ptr;
   uint8_t *xsum_ptr;
   uint32_t xsum_len;

   /* stream header is at the beginning */
   hdr_ptr = (Stream_Hdr_T *)(void *)ptr;

   /* offset by stream header */
   xsum_len = len - LOG_DATA_HDR_LEN;
   xsum_ptr = ptr + LOG_DATA_HDR_LEN;

   /* Disable checksum calculation if it takes more time */
   hdr_ptr->checksum = CalcSum16(xsum_ptr, GET_LEN(xsum_len));
}

/*============================================================================*\
 * AUTHOR(S) IDENTITY (AID)
 *-----------------------------------------------------------------------------
 *
 *  AID         NAME
 *  ---------------------------------------------------------------------------
 *  XXX         Firstname Lastname
 *  qjrdfk      Venkatesh G
\*============================================================================*/

/*============================================================================*\
 * FILE REVISION HISTORY - To be filled by the project team
 *-----------------------------------------------------------------------------
 *
 *  DATE          REVISION         AID          JIRA Ticket ID
 *      SUMMARY OF CHANGES
 *  ---------------------------------------------------------------------------
 *  yy-mm-dd      x.xx        XXX          12345
 *      First revision
 *  22-12-02      1.00        qjrdfk       DDR-1907
 *      Create application specific common crc function
 *  ---------------------------------------------------------------------------
\*============================================================================*/

/* END OF FILE -------------------------------------------------------------- */
