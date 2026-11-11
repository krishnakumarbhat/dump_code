/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Can_Irq.h"
#include "Csm.h"
#include "Csm_Cfg.h"
#include "Driver_Port.h"
#include "EcuM.h"
#include "Fault_Lib_Prj.h"
#include "I2c_Irq.h"
#include "Mcu.h"
#include "Mss_Ecc_Parity.h"
#include "Os.h"
#include "Os_Lcfg.h"
#include "Rte_SWC_PLT_CDD_FailSafe_Type.h"
#include "SWC_PLT_CDD_FailSafe.h"
#include "SchM_Fls.h"
#include "Wdg_182_iND13400_Irq.h"
#include "boot_interface.h"
#include "calibration.h"
#include "calibration_if.h"
#include "chandra_sfrs_base.h"
#include "crg_sfrs.h"
#include "dd_gpt.h"
#include "dd_mipi.h"
#include "dd_mmic.h"
#include "dd_pmic.h"
#include "dsp_setup.h"
#include "dsp_sfrs.h"
#include "ipc_data.h"
#include "ipc_mss.h"
#include "mcal_init.h"
#include "mipi_interrupt.h"
#include "mpu_r52.h"
#include "platformtime.h"
#include "radar_data.h"
#include "retention_ram_data.h"
#include "reuse.h"
#include <cstring>

/*===========================================================================*
 * SWE5 Integration Testing Support
 *===========================================================================*/
#include "master_it_macros_test.h"

#if defined(Integration_Testing)
/* Global flag defined for SIT_WAIT_FOR_DEBUGGER() macro */
volatile bool __attribute__((used)) SIT_Run = false;
#endif /* Integration_Testing */

#define UBSAN_ATTR __attribute__((used, noinline))

/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/
#define CRG ((volatile CRG_SFRS_t *)CRG_base)
#define DSP ((volatile DSP_SFRS_t *)DSP_base)

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
#define UART_RX_TEST_ENABLE          0
#define FIFTY_MS_IN_HEX              0x42480000
#define DELAY_IN_MICROSEC            50000
#define INIT_TIME_FOR_START          5
#define R52_MAIN_TIME_MEASURE_ENABLE (0u)

extern const uintptr_t __CUSTOMER_CALS_FLASH_START_ADDRESS;
/* Dataset (Customer Cals/SMC expansion) flash start address, used for the unprogrammed/CRC DTC check */
#define DATASET_FLASH_START_ADDR ((uint32_t)(&__CUSTOMER_CALS_FLASH_START_ADDRESS))
/* Value read back from erased (unprogrammed) flash */
#define DATASET_FLASH_ERASED_VALUE (0xFFFFFFFFU)
/*===========================================================================*
 * Local Variables
 *===========================================================================*/
/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

extern void mm_intf0_handler_worker(void);
extern void ETHERNET0_Handler(void);
extern void ETHERNET1_Handler(void);
extern void ETHERNET2_Handler(void);
extern void ETHERNET3_Handler(void);
extern void ETHERNET4_Handler(void);
extern void ETHERNET5_Handler(void);
extern void ETHERNET6_Handler(void);
extern void ETHERNET7_Handler(void);
extern void GPADC_Handler(void);
extern void TCM_LIB_Init(void);
extern void WATCHDOG_FUSA_Handler(void);

static void Retention_Ram_Data_Init(void);
extern void I2CM_Handler(void);
extern uint32_t __R52_TCMA_NULL_GUARD_BASE__[];
extern uint32_t __R52_PBL_SIZE__[];
volatile uint64_t Acq_End_Time_FE[NUM_LOOKS]   = {0};
volatile uint64_t Acq_Start_Time_FS[NUM_LOOKS] = {0};
volatile uint16_t calib_load_fail              = 0;

volatile uint32_t Ubsan_Divzero_Count     = 0u;
volatile uint32_t Ubsan_Divzero_Caller_LR = 0u;

void *Calib_Flash_Read_Wrapper(void *dst, const void *src, uintptr_t length)
{
   MemIf_JobResultType status;
   uint8_t ReadData_result = 0U;
   uint8_t read_buffer[64] __attribute__((aligned(16)));
   static int16_t calib_timeout_counter;
   while (length)
   {
      const uint32_t read_size = length > sizeof(read_buffer) ? sizeof(read_buffer) : length;
      calib_timeout_counter    = 1000;
      ReadData_result          = Fls_Read((uint32_t)src, read_buffer, read_size);
      if (E_OK == ReadData_result)
      {
         do
         {
            Fls_MainFunction();
            status = Fls_GetJobResult();
            calib_timeout_counter--;
         } while ((status != MEMIF_JOB_OK) && calib_timeout_counter);
         if (0 == calib_timeout_counter)
         {
            calib_load_fail = 1;
         }
         memcpy(dst, read_buffer, read_size);
         dst = ((uint8_t *)dst) + read_size;
         src = ((uint8_t *)src) + read_size;
         length -= read_size;
      }
      else
      {
         // do nothing;
      }
   }
   return NULL;
}

static void Check_Dataset_Flash_Programmed(void)
{
   uint32_t psc_first_word = 0U;
   (void)Calib_Flash_Read_Wrapper(&psc_first_word, (const void *)DATASET_FLASH_START_ADDR, sizeof(psc_first_word));
   if (DATASET_FLASH_ERASED_VALUE == psc_first_word)
   {
      Set_Fault_If_Enabled(PRJ_DATASET_UNPROGRAMMED_FAULT);
   }
   else
   {
      Clear_Fault_If_Enabled_and_Not_Latched(PRJ_DATASET_UNPROGRAMMED_FAULT);
   }
   Set_Test_Completed_If_Enabled(PRJ_DATASET_UNPROGRAMMED_FAULT);

   /* TODO: PRJ_DATASET_CRC_FAILURE_FAULT is not set here - PSC is not yet a valid calibration source
    * (Get_Cal_Load_Status only supports USC/SMC), so no CRC check is available for this dataset yet. */
}

void Calib_Init_Function(void)
{
   /* IMPORTANT: This driver/mcal SHALL not be excluded due to it initializes clocks and interrupts
    *            so all other drivers requries it to function correctly */
#if 1
   /* Initialize calibrations */
   Calibration_Handler_Config_T calib_config = Get_Default_Calibration_Handler_Config();
   /* override flash_read with custom wrapper for reading from flash */
   calib_config.flash_read = Calib_Flash_Read_Wrapper;
   Calibration_Handler_Init(&calib_config);
   Populate_Calibration_Headers();
   Validate_Load_All_Calib_Data(MAX_CALIBRATIONS);

   /* Check if the dataset is programmed in flash */
   Check_Dataset_Flash_Programmed();

   /* Providing calibrations info for Integration Testing */
   SIT_Calibration_Data();

   // Initialize_Frame_Start_Output_Gpio();
   // Trigger_Frame_Start_To_Resi();
#endif
}

/*===========================================================================*
 * Function: __ubsan_handle_divrem_overflow
 * Description: UBSan runtime handler for integer divide-by-zero and remainder
 *              overflow. Called by the compiler-instrumented code when an
 *              integer division or modulo operation triggers undefined behaviour
 *              (divisor == 0 or signed overflow). Records the caller LR and
 *              increments a diagnostic counter. Does NOT assert or reset so
 *              that the system remains observable under a debugger.
 * Parameters:
 *   data - pointer to UBSan source location / type descriptor (unused)
 *   lhs  - left-hand-side operand at the point of the violation (unused)
 *   rhs  - right-hand-side operand at the point of the violation (unused)
 * Globals written: Ubsan_Divzero_Caller_LR, Ubsan_Divzero_Count
 *===========================================================================*/
#pragma clang optimize off
void UBSAN_ATTR __ubsan_handle_divrem_overflow(void *data, uintptr_t lhs, uintptr_t rhs)
{
   uintptr_t lr;
   (void)data;
   (void)lhs;
   (void)rhs;

   __asm__ volatile("mov %0, lr" : "=r"(lr));

   Ubsan_Divzero_Caller_LR = lr - 4; // Subtract to get the actual address of the exception

   Ubsan_Divzero_Count++;
}
#pragma clang optimize on

/*===========================================================================*
 * Function: __ubsan_handle_float_divide_by_zero
 * Description: UBSan runtime handler for floating-point divide-by-zero.
 *              Called by the compiler-instrumented code when a floating-point
 *              division by zero is detected. Records the caller LR and
 *              increments a diagnostic counter. Does NOT assert or reset so
 *              that the system remains observable under a debugger.
 * Parameters:
 *   data - pointer to UBSan source location / type descriptor (unused)
 *   lhs  - left-hand-side (dividend) operand at the point of the violation
 *          (unused, passed as uintptr_t bit-pattern)
 * Globals written: Ubsan_Divzero_Caller_LR, Ubsan_Divzero_Count
 *===========================================================================*/
#pragma clang optimize off
void UBSAN_ATTR __ubsan_handle_float_divide_by_zero(void *data, uintptr_t lhs)
{
   uintptr_t lr;
   (void)data;
   (void)lhs;

   __asm__ volatile("mov %0, lr" : "=r"(lr));

   Ubsan_Divzero_Caller_LR = lr - 4; // Subtract to get the actual address of the exception

   Ubsan_Divzero_Count++;
}
#pragma clang optimize on

int __attribute__((section(".tcm_code_main"))) main(void)
{
   CRG->CLK_TOP_CTRL.f.CTL_CG_SEL_CLK_TEST = 0x2;

   /* Zero PBL (TCMA) region so this can be reused by application */
   memset((void *)__R52_TCMA_NULL_GUARD_BASE__, 0, (size_t)(uintptr_t)__R52_PBL_SIZE__);
   /* IMPORTANT: This driver/mcal SHALL not be excluded due to it initializes clocks and interrupts
    *            so all other drivers requries it to function correctly */

   /* SWE5 Integration Testing: Wait for debugger to attach (macro expands to no-op when testing disabled) */
   SIT_WAIT_FOR_DEBUGGER();

   /* Clear the DSP RUNSTALL bit to start DSP execution - needs to be done in a better way*/
   // *((uint32_t *)0x84401000) &= 0xFFFFFFFE;
   /* DND-4114 Mpu_Init contains MPU configurations: moved from from Startup.c
      for modularity and easy auto update using symbols from linker file */
#if R52_MAIN_TIME_MEASURE_ENABLE
   IOCTRL->GPIO_11.f.FUNC_SEL = 0x0; /* DIO Mode */
   IOCTRL->GPIO_11.f.IE       = 1;   /* Output so IE buffer not needed */
   IOCTRL->GPIO_11.f.DS       = 0;
   IOCTRL->GPIO_11.f.ST       = 0;
   IOCTRL->GPIO_11.f.PE       = 0;
   IOCTRL->GPIO_11.f.PS       = 0;
   GPIO->GPIO_SWPORTB_DDR.f.GPIO_SWPORTB_DDR |= 0x08; /* As Output */
   GPIO->GPIO_SWPORTB_DR.f.GPIO_SWPORTB_DR |= 0x08u;
#endif
   Retention_Ram_Data_Init();
   Mpu_Init();
   /* AUTOSAR initialization */
   Os_InitMemory();
   Os_Init();
   TCM_LIB_Init();
   Enable_Mss_Tcm_Cache_Ecc();
   EcuM_Init(); /* Does not return */

   return (0U);
}

TASK(Init_Task)
{
   Os_InitialEnableInterruptSources(FALSE);
   // Os_DisableInterruptSource(RA_ERROR_IRQ_Handler);
   // Os_DisableInterruptSource(RA_FUSA_IRQ_Handler);
   EcuM_StartupTwo();
/* Run MCAL tests AFTER EcuM_StartupTwo() completes
 * This ensures:
 * 1. All AUTOSAR modules fully initialized
 * 2. Interrupts properly configured and enabled
 */
#if defined(MCAL_TEST_ENABLE)
   {
      Mcal_Test();
   }
#endif

   (void)TerminateTask();
}

/* OS Wrapper for CAT2 Timer 1 */
volatile uint32 Gpt_Timer1_Counter;
volatile uint32 Gpt_Timer2_Counter;
volatile uint32 Gpt_Timer3_Counter;
volatile uint32 Gpt_Timer4_Counter;
volatile uint32 BBE_SP_GPIO0_Counter     = 0;
volatile uint32 MIPI_Frm_Start_Counter   = 0;
volatile uint32 MIPI_Frm_End_Counter     = 0;
volatile uint32 MIPI_Chrp_Start_Counter  = 0;
volatile uint32 MIPI_Chrp_End_Counter    = 0;
volatile uint32 MIPI_Chp_Fusa_Counter    = 0;
volatile bool MIPI_Chp_FuSa_Flag         = false;
volatile uint32 Wdg_Timeout_ISR          = 0;
volatile uint32 AA0_Fusa_Handler_ISR_Cnt = 0;
volatile uint32 AA1_Fusa_Handler_ISR_Cnt = 0;
// volatile uint8_t Test_CAND_Interrupt_Cnt;
// FUNC(void, CAN_CODE) Os_Isr_CANFD0_Handler(void)
// {
//    Test_CAND_Interrupt_Cnt++;
//    CANFD0_Handler();
// }

/* OS Wrapper for CAT2 MM_INTF0 */
void Os_Isr_mm_intf0_handler(void)
{
   (void)mm_intf0_handler_worker();
}

/* Placeholder for the BBE to R52 IPC interrupt */
void Os_Isr_BBE_SP_GPIO0_Handler(void)
{
   BBE_SP_GPIO0_Counter++;
   DSP->IRQ_ENA &= ~(0x01); // disable IRQ_ENA GPIO0 interrupt
   Update_R52_IPC_Notify();
}

/* OS Wrapper for CAT2 ADC Handler */
void Os_Isr_GPADC_Handler(void)
{
   (void)GPADC_Handler();
}

void Os_Isr_mipi_chp_end_handler(void)
{
   MIPI_Chrp_End_Counter++;
   (void)MIPI_Chirp_End_Handler();
}

void Os_Isr_mipi_chp_start_handler(void)
{
   MIPI_Chrp_Start_Counter++;
   (void)MIPI_Chirp_Start_Handler();
}

void Os_Isr_mipi_frm_end_handler(void)
{
   uint16_t look_type;
   look_type = Get_Radar_Look();
   Get_Platform_ustime((uint64_t *)&Acq_End_Time_FE[look_type]);
   MIPI_Frm_End_Counter++;
   (void)MIPI_Frame_End_Handler();
}

void Os_Isr_mipi_frm_start_handler(void)
{
   uint16_t look_type;
   look_type = Get_Radar_Look();
   Get_Platform_ustime((uint64_t *)&Acq_Start_Time_FS[look_type]);
   MIPI_Frm_Start_Counter++;
   (void)MIPI_Frame_Start_Handler();
}

void Os_Isr_mipi_chp_fusa_handler(void)
{
   MIPI_Chp_Fusa_Counter++;
   MIPI_Chp_FuSa_Flag = true;
   /* copy the IRQ0, IRQ1 and IRQ2 status flag information into local register */
   MIPI_FuSa_IRQ0_Mon_Status.register_value |= ptrMIPI->FUSA_IRQ0_FLAG.r;
   MIPI_FuSa_IRQ1_Mon_Status.register_value |= ptrMIPI->FUSA_IRQ1_FLAG.r;
   MIPI_FuSa_IRQ2_Mon_Status.register_value |= ptrMIPI->FUSA_IRQ2_FLAG.r;
   (void)MIPI_FuSa_Irq_Handler();
}

void Os_Isr_mipi_err_fusa_handler(void)
{
   /* MIPI_ERR_FUSA_Handler */
}

uint64_t *Get_Acq_End_Time_FE_Ptr(void)
{
   return (uint64_t *)&Acq_End_Time_FE[0];
}
uint64_t *Get_Acq_Start_Time_FS_Ptr(void)
{
   return (uint64_t *)&Acq_Start_Time_FS[0];
}

void Os_Isr_dsp_ctrl_err_fusa_irq_handler(void)
{
   /* dsp_ctrl_err_fusa_irq_handler */
}

static void Retention_Ram_Data_Init(void)
{
   /* If reset is Power-On , Initialize Retention Ram Data to Zero */
   if (Boot_Shared_Data.reset_type == 0)
   {
      /* Explicitly initialize each Retention_Ram_Data member to zero */
      Retention_Ram_Data.Exception_data.exception_causing_address   = 0u;
      Retention_Ram_Data.Exception_data.exception_status_register   = 0u;
      Retention_Ram_Data.Exception_data.memory_exception_address    = 0u;
      Retention_Ram_Data.Exception_data.stack_pointer               = 0u;
      Retention_Ram_Data.Exception_data.reset_number                = 0u;
      Retention_Ram_Data.Exception_data.exception_type              = 0u;
      Retention_Ram_Data.Exception_data.memory_exception_occurred   = false;
      Retention_Ram_Data.fhti_test_data.failure_name                = 0u;
      Retention_Ram_Data.fhti_test_data.reset_count                 = 0u;
      Retention_Ram_Data.fhti_test_data.repetative_reset_fault_type = 0u;
      Retention_Ram_Data.fhti_test_data.plt_usTime_freeze_pending   = 0u;
   }
}
void Csm_callback(uint32 jobid, Std_ReturnType cryptoResult)
{
   (void)cryptoResult;
   (void)jobid;
}

void Os_Isr_AA0_Fusa_Handler(void)
{
   /*AA0_FUSA_IRQ_Handler*/
   AA0_Fusa_Handler_ISR_Cnt++;
}

void Os_Isr_AA1_Fusa_Handler(void)
{
   /*AA1_FUSA_IRQ_Handler*/
   AA1_Fusa_Handler_ISR_Cnt++;
}
