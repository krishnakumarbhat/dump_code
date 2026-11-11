#ifndef RA_FAULT_INJECTION_MOCK_H
#define RA_FAULT_INJECTION_MOCK_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

   typedef struct
   {
      uint32_t ENA;
      uint32_t FORCE_CQMEM_AHB;
      uint32_t FORCE_WCMEM_AHB;
      uint32_t FORCE_IDXMEM_AHB;
      uint32_t FORCE_PHMEM_AHB;
      uint32_t FORCE_ESTMEM_1_AHB;
      uint32_t FORCE_ESTMEM_3_AHB;
      uint32_t QUEUE_RESET;
   } CONTROL_F_t;

   typedef struct
   {
      uint32_t r;
      CONTROL_F_t f;
   } CONTROL_t;

   typedef struct
   {
      uint32_t CMD_IDX;
      uint32_t CMD_PUSH;
   } CMD_PUSH_F_t;

   typedef struct
   {
      uint32_t r;
      CMD_PUSH_F_t f;
   } CMD_PUSH_t;

   typedef struct
   {
      uint32_t TM_FORCE_AXI_IN_PARITY_ERR;
      uint32_t TM_FORCE_AXI_OUT_PARITY_ERR;
   } FUSA_TESTMODES_F_t;

   typedef struct
   {
      uint32_t r;
      FUSA_TESTMODES_F_t f;
   } FUSA_TESTMODES_t;

   typedef struct
   {
      uint32_t AXI_IN_PARITY_CHK_IRQ_R52_FUSA_FLAG;
      uint32_t AXI_OUT_PARITY_CHK_IRQ_R52_FUSA_FLAG;
   } R52_FUSA_IRQ_FLAG_F_t;

   typedef struct
   {
      uint32_t r;
      R52_FUSA_IRQ_FLAG_F_t f;
   } R52_FUSA_IRQ_FLAG_t;

   typedef struct
   {
      uint32_t IN_STAGE_WDT_IRQ_R52_ERR_ENA;
      uint32_t PROC_STAGE_WDT_IRQ_R52_ERR_ENA;
      uint32_t OUT_STAGE_WDT_IRQ_R52_ERR_ENA;
      uint32_t INVALID_CONFIG_IRQ_R52_ERR_ENA;
      uint32_t DPMEM_MUX_ERR_IRQ_R52_ERR_ENA;
      uint32_t AXI_IN_RESP_ERR_IRQ_R52_ERR_ENA;
   } R52_ERR_IRQ_ENA_1_F_t;

   typedef struct
   {
      uint32_t r;
      R52_ERR_IRQ_ENA_1_F_t f;
   } R52_ERR_IRQ_ENA_1_t;

   typedef struct
   {
      uint32_t IN_STAGE_WDT_IRQ_R52_ERR_FLAG;
      uint32_t PROC_STAGE_WDT_IRQ_R52_ERR_FLAG;
      uint32_t OUT_STAGE_WDT_IRQ_R52_ERR_FLAG;
      uint32_t INVALID_CONFIG_IRQ_R52_ERR_FLAG;
      uint32_t PREPROC_OVF_IRQ_R52_ERR_FLAG;
      uint32_t DPMEM_MUX_ERR_IRQ_R52_ERR_FLAG;
   } R52_ERR_IRQ_FLAG_1_F_t;

   typedef struct
   {
      uint32_t r;
   } R52_ERR_IRQ_ENA_2_t;

   typedef struct
   {
      uint32_t r;
      R52_ERR_IRQ_FLAG_1_F_t f;
   } R52_ERR_IRQ_FLAG_1_t;

   typedef struct
   {
      uint32_t MON_TMR_IN_TIMEOUT_SEL;
      uint32_t MON_TMR_IN_ENA;
   } MON_TIMER_IN_CTRL_F_t;

   typedef struct
   {
      uint32_t r;
      MON_TIMER_IN_CTRL_F_t f;
   } MON_TIMER_IN_CTRL_t;

   typedef struct
   {
      uint32_t MON_TMR_OUT_TIMEOUT_SEL;
      uint32_t MON_TMR_OUT_ENA;
   } MON_TIMER_OUT_CTRL_F_t;

   typedef struct
   {
      uint32_t r;
      MON_TIMER_OUT_CTRL_F_t f;
   } MON_TIMER_OUT_CTRL_t;

   typedef struct
   {
      uint32_t r;
   } R52_FUSA_IRQ_ENA_t;

   typedef struct
   {
      uint32_t MON_TMR_PROC_TIMEOUT_SEL;
      uint32_t MON_TMR_PROC_ENA;
   } MON_TIMER_PROC_CTRL_F_t;

   typedef struct
   {
      uint32_t r;
      MON_TIMER_PROC_CTRL_F_t f;
   } MON_TIMER_PROC_CTRL_t;

   typedef struct
   {
      uint32_t CQMEM_ECC_ENC_BYPASS;
      uint32_t CQMEM_ECC_SEC_CNT_THR;
   } CQMEM_ECC_CONTROL_F_t;

   typedef struct
   {
      uint32_t r;
      CQMEM_ECC_CONTROL_F_t f;
   } CQMEM_ECC_CONTROL_t;

   typedef struct
   {
      uint32_t WCMEM_ECC_ENC_BYPASS;
      uint32_t WCMEM_ECC_SEC_CNT_THR;
   } WCMEM_ECC_CONTROL_F_t;

   typedef struct
   {
      uint32_t r;
      WCMEM_ECC_CONTROL_F_t f;
   } WCMEM_ECC_CONTROL_t;

   typedef struct
   {
      uint32_t IDXMEM_ECC_ENC_BYPASS;
      uint32_t IDXMEM_ECC_SEC_CNT_THR;
   } IDXMEM_ECC_CONTROL_F_t;

   typedef struct
   {
      uint32_t r;
      IDXMEM_ECC_CONTROL_F_t f;
   } IDXMEM_ECC_CONTROL_t;

   typedef struct
   {
      uint32_t PHMEM_ECC_ENC_BYPASS;
      uint32_t PHMEM_ECC_SEC_CNT_THR;
   } PHMEM_ECC_CONTROL_F_t;

   typedef struct
   {
      uint32_t r;
      PHMEM_ECC_CONTROL_F_t f;
   } PHMEM_ECC_CONTROL_t;

   typedef struct
   {
      uint32_t ESTMEM_1_ECC_ENC_BYPASS;
   } ESTMEM_1_ECC_CONTROL_F_t;

   typedef struct
   {
      uint32_t r;
      ESTMEM_1_ECC_CONTROL_F_t f;
   } ESTMEM_1_ECC_CONTROL_t;

   typedef struct
   {
      uint32_t ESTMEM_3_ECC_ENC_BYPASS;
   } ESTMEM_3_ECC_CONTROL_F_t;

   typedef struct
   {
      uint32_t r;
      ESTMEM_3_ECC_CONTROL_F_t f;
   } ESTMEM_3_ECC_CONTROL_t;

   typedef struct
   {
      CONTROL_t CONTROL;
      CMD_PUSH_t CMD_PUSH;
      FUSA_TESTMODES_t FUSA_TESTMODES;

      R52_FUSA_IRQ_ENA_t R52_FUSA_IRQ_ENA;
      R52_FUSA_IRQ_FLAG_t R52_FUSA_IRQ_FLAG;

      R52_ERR_IRQ_ENA_1_t R52_ERR_IRQ_ENA_1;
      R52_ERR_IRQ_ENA_2_t R52_ERR_IRQ_ENA_2;
      R52_ERR_IRQ_FLAG_1_t R52_ERR_IRQ_FLAG_1;

      MON_TIMER_IN_CTRL_t MON_TIMER_IN_CTRL;
      MON_TIMER_PROC_CTRL_t MON_TIMER_PROC_CTRL;
      MON_TIMER_OUT_CTRL_t MON_TIMER_OUT_CTRL;

      CQMEM_ECC_CONTROL_t CQMEM_ECC_CONTROL;
      WCMEM_ECC_CONTROL_t WCMEM_ECC_CONTROL;
      IDXMEM_ECC_CONTROL_t IDXMEM_ECC_CONTROL;
      PHMEM_ECC_CONTROL_t PHMEM_ECC_CONTROL;

      uint16_t CQMEM_ECC_STATUS;
      uint16_t IDXMEM_ECC_STATUS;
      uint16_t PHMEM_ECC_STATUS;
      uint16_t WCMEM_ECC_STATUS;

      ESTMEM_1_ECC_CONTROL_t ESTMEM_1_ECC_CONTROL;
      ESTMEM_3_ECC_CONTROL_t ESTMEM_3_ECC_CONTROL;

      uint16_t ESTMEM_1_ECC_STATUS;
      uint32_t OUT_ADDR_RANGE_CONTROL;

   } RA_SFRS_t;

   typedef struct
   {
      uint32_t CQMEM[128];
      uint32_t WCMEM[128];
      uint32_t IDXMEM[128];
      uint32_t PHMEM[128];
      uint32_t ESTMEM_1[128];
      uint32_t ESTMEM_3[128];

   } RA_MEM_t;

   typedef RA_MEM_t RA_MEM_SFRS_t;

   extern RA_SFRS_t mock_ra_regs;
   extern RA_MEM_t mock_ra_mem_regs;

   extern uintptr_t RA_base;
   extern uintptr_t RA_MEM_base;

#define RA                                                      ((volatile RA_SFRS_t *)RA_base)
#define RA_MEM                                                  ((volatile RA_MEM_t *)RA_MEM_base)
#define RA_R52_ERR_IRQ_ENA_1_PREPROC_OVF_IRQ_R52_ERR_ENA_msk    (1U)
#define RA_R52_ERR_IRQ_ENA_2_OUT_ADDR_RANGE_IRQ_R52_ERR_ENA_msk (1U)

   void RA_MockReset(void);

#ifdef __cplusplus
}
#endif

#endif
