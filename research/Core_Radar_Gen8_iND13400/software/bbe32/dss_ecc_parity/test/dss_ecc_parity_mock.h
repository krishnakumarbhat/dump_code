/*===========================================================================*/
/**
 * @file dss_ecc_parity_mock.h
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 *
 * @section DESC DESCRIPTION:
 * Mock header for dss_ecc_parity hardware-specific functions for unit testing
 *
 */
/*===========================================================================*/

#ifndef DSS_ECC_PARITY_MOCK_H
#define DSS_ECC_PARITY_MOCK_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdint.h>

   /* Mock global variables */
   extern uint32_t mock_axi_ecc_register;
   extern uint32_t mock_write_count;
   extern uint32_t mock_read_count;
   extern bool mock_write_fails;
   extern uint32_t mock_csrpctl_register;
   extern uint32_t mock_csrpctl_write_count;
   extern uint32_t mock_csrpctl_read_count;
   extern bool mock_csrpctl_write_fails;
   extern int32_t mock_dss_ecc_dram_memory;
   extern int32_t mock_dss_ecc_iram_memory;
   extern uint32_t mock_dss_ecc_mesr;
   extern uint32_t mock_dss_ecc_ccount;
   extern uint32_t mock_dss_ecc_memctl;
   extern uint32_t mock_dss_ecc_irq_enabled;

   /* Mock function prototypes */
   void mock_dss_ecc_reset(void);
   uint32_t mock_XT_RER(uint32_t address);
   void mock_XT_WER(uint32_t value, uint32_t address);
   void mock_XT_ISYNC(void);
   uint32_t mock_XT_RSR_CSRPCTL(void);
   void mock_XT_WSR_CSRPCTL(uint32_t value);
   uint32_t mock_XT_RSR_MESR(void);
   void mock_XT_WSR_MESR(uint32_t value);
   uint32_t mock_XT_RSR_CCOUNT(void);
   void mock_XT_MEMW(void);
   void mock_XT_EXTW(void);
   void mock_XT_ESYNC(void);
   uint32_t mock_XT_RSR_MEMCTL(void);
   void mock_XT_WSR_MEMCTL(uint32_t value);
   void mock_dss_ecc_irq_enable(void);

/* Macro overrides for unit testing */
#ifdef UNIT_TEST
   #define XT_RER(addr)          mock_XT_RER(addr)
   #define XT_WER(val, addr)     mock_XT_WER(val, addr)
   #define XT_ISYNC()            mock_XT_ISYNC()
   #define XT_RSR_CSRPCTL()      mock_XT_RSR_CSRPCTL()
   #define XT_WSR_CSRPCTL(value) mock_XT_WSR_CSRPCTL(value)
   #define XT_RSR_MESR()         mock_XT_RSR_MESR()
   #define XT_WSR_MESR(value)    mock_XT_WSR_MESR(value)
   #define XT_RSR_CCOUNT()       mock_XT_RSR_CCOUNT()
   #define XT_MEMW()             mock_XT_MEMW()
   #define XT_EXTW()             mock_XT_EXTW()
   #define XT_ESYNC()            mock_XT_ESYNC()
   #define XT_RSR_MEMCTL()       mock_XT_RSR_MEMCTL()
   #define XT_WSR_MEMCTL(value)  mock_XT_WSR_MEMCTL(value)
   #define DSS_ECC_DRAM_PTR      (&mock_dss_ecc_dram_memory)
   #define DSS_ECC_IRAM_PTR      (&mock_dss_ecc_iram_memory)
   #define DSS_ECC_IRQ_ENABLE()  mock_dss_ecc_irq_enable()
#endif

#ifdef __cplusplus
}
#endif

#endif // DSS_ECC_PARITY_MOCK_H
