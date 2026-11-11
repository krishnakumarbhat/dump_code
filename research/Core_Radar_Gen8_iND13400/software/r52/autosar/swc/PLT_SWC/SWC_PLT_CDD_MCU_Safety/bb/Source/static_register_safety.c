/*===========================================================================*\
 * FILE: static_register_safety.c
 *===========================================================================
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2026 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the static register safety mechanisum functions for Functional Safety Configuration.
 *
 * ABBREVIATIONS:
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/GlobalRegional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards </a>
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "static_register_safety.h"

#include "Crc.h"
#include "Rte_SWC_PLT_CDD_MCU_Safety.h"
#include "board_revision.h"
#include "radar_ctl.h"
#include "static_register_safety_cfg.h"
/*===========================================================================*\
 * Local Function Prototypes
\*===========================================================================*/
static uint8_t Eth_Static_Register_Excluded(Board_Revision_T board_revision, Static_Registers_T reg_index);
static uint32_t FuSa_Calculate_CRC_FS(const uint32_t **Reg_Desc_Ptr, uint16_t max_num_register, Board_Revision_T board_revision);
static uint8_t Static_Register_Safety_Check_Init(uint32_t *fusa_crc_ptr, uint32_t *Reg_Data_Init, const uint32_t **Reg_Desc_Ptr,
                                                 const uint16_t max_num_register, Board_Revision_T board_revision);
static void Static_Register_Data_Comparison(const uint32_t *Reg_Data_Init, uint8_t *fault_reg_index, const uint32_t **Reg_Desc_Ptr,
                                            uint16_t max_num_register, Board_Revision_T board_revision);

/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/
#define FS_STARTUP_DELAY_CYCLES       ((uint8_t)20) /* 1s delay */
#define STATIC_REG_CHECK_DELAY_CYCLES ((uint8_t)3)  /* 150ms delay */
#define DEFAULT_CRC                   ((uint32_t)0xFFFFFFFF)

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/
static uint8_t Eth_Static_Register_Excluded(const Board_Revision_T board_revision, const Static_Registers_T reg_index)
{
   uint8_t exclude_register = CODED_FALSE;

   if (BOARD_REV_B0CVAL == board_revision)
   {
      switch (reg_index)
      {
         case REG_LATENCY_CTRL:
         case REG_MACSEC_IP_CONTROL:
         case REG_MACSEC_CFG_MIN_IPG:
         case REG_MACSEC_IP_VLAN:
         case REG_RLS_CNT_SETUP_VALUE:
         case REG_IRQ_GLBL_EN:
         case REG_DMA_CH1_INTERRUPT_ENABLE:
         case REG_DMA_CH1_RX_CONTROL:
         case REG_DMA_CH1_RX_CONTROL2:
         case REG_DMA_CH1_TXDESC_RING_LENGTH:
         case REG_DMA_CH1_TX_CONTROL:
         case REG_DMA_CH1_CONTROL:
         case REG_DMA_CH0_INTERRUPT_ENABLE:
         case REG_DMA_CH0_RX_CONTROL2:
         case REG_DMA_CH0_TXDESC_RING_LENGTH:
         case REG_DMA_CH0_RX_CONTROL:
         case REG_DMA_CH0_TX_CONTROL:
         case REG_DMA_CH0_CONTROL:
         case REG_DMA_ECC_INTERRUPT_ENABLE:
         case REG_SERDES_MISC_CTRL:
         case REG_ETHERNET_MCGR_CTRL:
         case REG_ETHER_CTRL:
            exclude_register = CODED_TRUE;
            break;

         default:
            break;
      }
   }

   return exclude_register;
}

#define MAX_NUM_REGISTER                         ((uint16_t)REG_STATIC_MAX)
#define RTE_READ_BBE32_STATIC_REG_FAILURE_STATUS Rte_Read_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo
#define RTE_FAILSAFE_LOG_RESET_REASON            Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason
#define RTE_STATIC_REG_CHECK_FAILURE_INFO                                                                                         \
   Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo

/*===========================================================================*\
 * Local Object Definitions
\*===========================================================================*/
static const uint32_t *Reg_Desc_Ptr[]           = {REGISTERS_DESCRIPTION_LIST(REG_DESC_PTR)};
static uint32_t Reg_Data_Init[MAX_NUM_REGISTER] = {0U};

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/
/*==========================================================================*/
/**
 * FUNCTION: FuSa_Calculate_CRC_FS
 *===========================================================================
 * RETURN VALUE: uint32_t - Calculated CRC32 value for configured registers.
 *
 * PARAMETERS: Reg_Desc_Ptr, max_num_register.
 *
 * EXTERNAL REFERENCES: None.
 *
 * DEVIATIONS FROM STANDARDS:None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * This function calculates CRC32 over all configured safety critical registers
 * to verify their integrity.
 *
 * PRECONDITIONS: Register_Description array must be initialized.
 *
 *
 * POSTCONDITIONS: Returns CRC32 value for register comparison.
 *
 */
/*===========================================================================*/
static uint32_t FuSa_Calculate_CRC_FS(const uint32_t **Reg_Desc_Ptr, const uint16_t max_num_register,
                                      const Board_Revision_T board_revision)
{
   uint32_t index;
   uint32_t crc_result = DEFAULT_CRC;
   /*Software based CRC calculation for the configured Regsiters */

   for (index = 0U; index < max_num_register; index++)
   {
      if (CODED_TRUE == Eth_Static_Register_Excluded(board_revision, (Static_Registers_T)index))
      {
         continue;
      }

      crc_result = Crc_CalculateCRC32((uint8_t *)Reg_Desc_Ptr[index], sizeof(*Reg_Desc_Ptr[index]), crc_result, (uint8_t)!index);
   }

   return (crc_result);
}

/*==========================================================================*/
/**
 * FUNCTION: Static_Register_Safety_Check_Init
 *===========================================================================
 * RETURN VALUE: uint8_t
 *
 * PARAMETERS: fusa_crc_ptr, Reg_Data_Init, Reg_Desc_Ptr, max_num_register
 *
 * EXTERNAL REFERENCES: None.
 *
 * DEVIATIONS FROM STANDARDS:None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Static_Register_Safety_Check_Init function will run once at 1st time.
 * This function will calculate CRC once and takes backup of original values of the registers.
 *
 * PRECONDITIONS: All MSS and DSS registers should be initialized.
 *
 *
 * POSTCONDITIONS: None
 *
 */
/*===========================================================================*/
static uint8_t Static_Register_Safety_Check_Init(uint32_t *fusa_crc_ptr, uint32_t *Reg_Data_Init, const uint32_t **Reg_Desc_Ptr,
                                                 const uint16_t max_num_register, const Board_Revision_T board_revision)
{
   static uint8_t start_up_delay = 0U;
   uint16_t loop_count;
   uint8_t ret_val = CODED_TRUE;

   start_up_delay++;

   if (start_up_delay < FS_STARTUP_DELAY_CYCLES)
   {
      return ret_val;
   }

   if (Radar_Core_Status.RadarInitializatonStatus == RADAR_SUCCESS)
   {
      *fusa_crc_ptr = FuSa_Calculate_CRC_FS(Reg_Desc_Ptr, max_num_register, board_revision);
      ret_val       = CODED_FALSE;

      for (loop_count = 0U; loop_count < max_num_register; loop_count++)
      {
         if (CODED_TRUE == Eth_Static_Register_Excluded(board_revision, (Static_Registers_T)loop_count))
         {
            continue;
         }

         /*copying the register initialization data*/
         Reg_Data_Init[loop_count] = *Reg_Desc_Ptr[loop_count];
      }
   }
   return ret_val;
}

/*==========================================================================*/
/**
 * FUNCTION: Static_Register_Data_Comparison
 *===========================================================================
 * RETURN VALUE: void.
 *
 * PARAMETERS: Reg_Data_Init, fault_reg_index, Reg_Desc_Ptr, max_num_register.
 *
 * EXTERNAL REFERENCES: None.
 *
 * DEVIATIONS FROM STANDARDS:None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * This function compares the current values of static registers with their backed up
 * values and stores the index of modified register in case of mismatch.

 *
 * POSTCONDITIONS: If there is change in static register data, will lead to functional reset.
 *
 */
/*===========================================================================*/
static void Static_Register_Data_Comparison(const uint32_t *Reg_Data_Init, uint8_t *fault_reg_index, const uint32_t **Reg_Desc_Ptr,
                                            const uint16_t max_num_register, const Board_Revision_T board_revision)
{
   uint16_t loop_count;
   uint8_t byte_pos = 0U;
   uint8_t bit_pos  = 0U;

   for (loop_count = 0U; loop_count < max_num_register; loop_count++)
   {
      if (CODED_TRUE == Eth_Static_Register_Excluded(board_revision, (Static_Registers_T)loop_count))
      {
         continue;
      }

      /*at every 3rd RADAR_CYCLES comparing register data with register initialization data*/
      if (*Reg_Desc_Ptr[loop_count] != Reg_Data_Init[loop_count])
      {
         byte_pos = (uint8_t)(loop_count / ((uint8_t)8)); /* 8bits per byte*/
         bit_pos  = (uint8_t)(loop_count % ((uint8_t)8)); /* 8bits per byte*/
         SET_BIT(fault_reg_index[byte_pos], bit_pos);     /*Stores the index of the modified register*/
      }
   }
}

/*==========================================================================*/
/**
 * FUNCTION: Static_Register_Safety_Check
 *===========================================================================
 * RETURN VALUE: void.
 *
 * PARAMETERS: void.
 *
 * EXTERNAL REFERENCES: None.
 *
 * DEVIATIONS FROM STANDARDS:None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Static_Register_Safety_Check function will run at every 50ms.
 * This function will verify the static registers data at every 3 RADAR_CYCLEs.
 * If there is any update in the static registers data, it will trigger the functional reset. *
 *
 * PRECONDITIONS: ALL MSS and DSS registers should be initialized.
 *
 *
 * POSTCONDITIONS: If there is change in static register data, will lead to functional reset.
 *
 */
/*===========================================================================*/
void Static_Register_Safety_Check(void)
{
   static Dt_StaticRegCheckFailureInfo bbe32_regChkFailed = {0U};
   static uint32_t fusa_crc                               = DEFAULT_CRC;
   static uint8_t static_reg_init_status                  = CODED_TRUE;
   static uint8_t iteration_count                         = 0U;
   uint32_t runtime_crc                                   = DEFAULT_CRC;
   const uint16_t max_num_register                        = MAX_NUM_REGISTER;
   const Board_Revision_T board_revision                  = Get_Board_Revision();
   uint8_t fault_reg_index[MAX_REG_INDEX_BYTES]           = {0U};

   iteration_count++;

   if (CODED_TRUE == static_reg_init_status)
   {
      static_reg_init_status =
         Static_Register_Safety_Check_Init(&fusa_crc, Reg_Data_Init, Reg_Desc_Ptr, max_num_register, board_revision);
      iteration_count = 0U;
   }

   if ((STATIC_REG_CHECK_DELAY_CYCLES == iteration_count) && (CODED_FALSE == static_reg_init_status))
   {
      /*Runtime CRC calculation every 3 RADAR_CYCLEs */
      runtime_crc = FuSa_Calculate_CRC_FS(Reg_Desc_Ptr, max_num_register, board_revision);
      (void)RTE_READ_BBE32_STATIC_REG_FAILURE_STATUS(&bbe32_regChkFailed[0U]); /* bbe32 static register failure status */

      if ((runtime_crc != fusa_crc) || (TRUE == bbe32_regChkFailed[0U]))
      {
         Static_Register_Data_Comparison(Reg_Data_Init, fault_reg_index, Reg_Desc_Ptr, max_num_register, board_revision);
         /*Soft Reset if CRC is mismatched */
         (void)RTE_STATIC_REG_CHECK_FAILURE_INFO(&fault_reg_index[0U]);
         (void)RTE_FAILSAFE_LOG_RESET_REASON(MCU_FAILSAFE_SOFT_FUNC_RESET);
      }
      else
      {
         /* Do Nothing*/
      }
      iteration_count = 0U;
   }
   else
   {
      /* Nothing needed */
   }
}
