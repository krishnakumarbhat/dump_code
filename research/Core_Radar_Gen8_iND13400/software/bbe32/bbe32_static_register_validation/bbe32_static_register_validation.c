/*===========================================================================*\
 * FILE: bbe32_static_register_validation.c
 *===========================================================================
 * Copyright 2025 APTIV Technologies, Inc., All Rights Reserved.
 * APTIV Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the static register safety mechanisum functions for Functional Safety Configuration.
 *
 * ABBREVIATIONS:
 *   TODO: List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *     TODO: Update list of design document(s)
 *
 *   Requirements Document(s):
 *     TODO: Update list of requirements document(s)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     SW REF 264.15D "APTIV C Coding Standards" [12-Mar-2006]
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
#include "bbe32_static_register_validation_cfg.h"
#include "crc_calc.h"
#include "ipc_data.h"
#include "ipc_dsp.h"
/* ========================================================================== */
/* Macros                                     */
/* ========================================================================== */
#define FS_STARTUP_DELAY (20)
#define FS_WAIT_150MS    (3)
/* WAIT AND DATALENGTH MACRO  */
#define MAX_NO_REGISTER_BBE32 ((uint32)16)
#define DATA_LENGTH           ((uint8)4)

/*===========================================================================*\
 * Local Function Prototypes
\*===========================================================================*/
static uint32 Bbe32_FuSa_Calculate_CRC_FS(void);
static uint8 Bbe32_FuSa_Validate_CRC(void);
/*===========================================================================*\
 * Local Object Definitions
\*===========================================================================*/
/*Register Description that has been configured for CRC calculation*/
/*If there is any addition or removal of registers from this list please update the macro MAX_NO_REGISTER value
 * accordingly*/
const uint32 *Register_Description_Bbe32[MAX_NO_REGISTER_BBE32] = {
   /* TODO (const uint32 *)(AUX_ACC_MISC_CTRL0), */ (const uint32 *)(AUX_ACC_ECC_CTRL0),
   (const uint32 *)(AUX_ACC_ECC_CTRL1),
   (const uint32 *)(AUX_ACC_ECC_CTRL2),
   (const uint32 *)(AUX_ACC_RAM_CTRL0),
   (const uint32 *)(IRQ_ERR_ENA_CTRL0),
   /* TODO (const uint32 *)(IRQ_INFO_ENA_CTRL0), */ (const uint32 *)R52_ERR_IRQ_ENA_2,
   (const uint32 *)R52_FUNC_IRQ_ENA,
   (const uint32 *)COMP_PRBS_1,
   (const uint32 *)COMP_PRBS_2,
   (const uint32 *)DECOMP_PRBS_1,
   (const uint32 *)DECOMP_PRBS_2,
   (const uint32 *)MON_TIMER_IN_CTRL,
   (const uint32 *)MON_TIMER_PROC_CTRL,
   (const uint32 *)MON_TIMER_OUT_CTRL,
   (const uint32 *)IDMA_TRIGGER_ENA,
   (const uint32 *)(DSP_FUSA_IRQ_ENA),
};

static uint32 FS_CRC                = 0xFFFFFFFFu;
volatile uint32 Runtime_CRC         = 0xFFFFFFFFu;
static uint8 One_Sec_Delay          = 0u;
static uint8 One_Time_Intialization = CODED_TRUE;
/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/
/********************************************************************************************
 * FUNCTION: Bbe32_FuSa_Calculate_CRC_FS()
 *
 * This function will compare the Offline CRC with Online CRC and verify if the integrity of safety critical registers are
 *maintained
 *
 * \param[in]      none
 *
 * \return         none
 *
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 *******************************************************************************************/
static uint32_t Bbe32_FuSa_Calculate_CRC_FS(void)
{
   uint32 online_index;
   uint8 call_value           = true;
   uint32_t online_crc_result = 0xFFFFFFFFu;

   /*Software based CRC calculation for the configured Regsiters */
   for (online_index = 0u; online_index < MAX_NO_REGISTER_BBE32; online_index++)
   {
      if (true == call_value)
      {
         online_crc_result =
            Compute_CRC32_SW((uint8 *)(uintptr_t)Register_Description_Bbe32[online_index], DATA_LENGTH, online_crc_result, true);
         call_value = false;
      }
      else
      {
         online_crc_result =
            Compute_CRC32_SW((uint8 *)(uintptr_t)Register_Description_Bbe32[online_index], DATA_LENGTH, online_crc_result, false);
      }
   }

   return (online_crc_result);
}
/*==========================================================================*/
/**
 * FUNCTION: bbe32_static_register_validation_Check
 *===========================================================================
 * RETURN VALUE: None.
 *
 * PARAMETERS: None.
 *
 * EXTERNAL REFERENCES: None.
 *
 * DEVIATIONS FROM STANDARDS:None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * bbe32_static_register_validation_Check function will run at every 50ms.
 * This function will verify the static registers data at every 150ms.
 * If there is any update in the static registers data, it will trigger the functional reset. *
 *
 * PRECONDITIONS: ALL MSS and DSS registers should be initialized.
 *
 *
 * POSTCONDITIONS: If there is change in static register data, will lead to functional reset.
 *
 */
/*===========================================================================*/
void Bbe32_Static_Register_Safety_Check(void)
{
   volatile D2M_Msg_T *d2m_msg_ptr              = Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();
   uint8 Bbe32_Static_Register_Validation_Fault = CODED_FALSE;

   One_Sec_Delay++;
   if ((CODED_TRUE == One_Time_Intialization) && (0 == (One_Sec_Delay % FS_STARTUP_DELAY)))
   {
      /* Offline / reference CRC calculation after one sec of delay */
      FS_CRC                 = Bbe32_FuSa_Calculate_CRC_FS();
      One_Time_Intialization = CODED_FALSE;
   }

   if ((CODED_FALSE == One_Time_Intialization) && (0 == (One_Sec_Delay % FS_WAIT_150MS)))
   {
      /*Runtime CRC calculation every one hundred and fifty milli sec */
      Runtime_CRC = Bbe32_FuSa_Calculate_CRC_FS();
      if (Bbe32_FuSa_Validate_CRC())
      {
         Bbe32_Static_Register_Validation_Fault = CODED_TRUE;
      }
      else
      {
         Bbe32_Static_Register_Validation_Fault = CODED_FALSE;
      }
   }

   d2m_msg_ptr->payload.diag_data.fusa_bbe32_reg_readback_test_fault_flag = Bbe32_Static_Register_Validation_Fault;
}
/********************************************************************************************
 * FUNCTION: Bbe32_FuSa_Validate_CRC()
 *
 * This function will compare the reference CRC (expected) with periodic Online CRC (actual)
 * and verify if the integrity of safety critical registers are maintained.
 * Reference CRC is currently from init values. TODO : offline golden CRC approach.
 *
 * \param[in]      none
 *
 * \return         none
 *
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 *******************************************************************************************/
static uint8 Bbe32_FuSa_Validate_CRC(void)
{
   uint8 return_val = 0u;
   /*CRC result validation of online and reference CRC calculated */
   if (Runtime_CRC != FS_CRC)
   {
      return_val = true;
   }
   else
   {
      /* Nothing needed */
   }
   return return_val;
}
