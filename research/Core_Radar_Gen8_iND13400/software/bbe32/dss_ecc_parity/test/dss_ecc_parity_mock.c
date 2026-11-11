/*===========================================================================*/
/**
 * @file dss_ecc_parity_mock.c
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 *
 * @section DESC DESCRIPTION:
 * Mock implementation for dss_ecc_parity hardware functions
 *
 */
/*===========================================================================*/

#include "dss_ecc_parity_mock.h"

/* Mock global variables */
uint32_t mock_axi_ecc_register    = 0U;
uint32_t mock_write_count         = 0U;
uint32_t mock_read_count          = 0U;
bool mock_write_fails             = false;
uint32_t mock_csrpctl_register    = 0U;
uint32_t mock_csrpctl_write_count = 0U;
uint32_t mock_csrpctl_read_count  = 0U;
bool mock_csrpctl_write_fails     = false;
int32_t mock_dss_ecc_dram_memory  = 0;
int32_t mock_dss_ecc_iram_memory  = 0;
uint32_t mock_dss_ecc_mesr        = 0U;
uint32_t mock_dss_ecc_ccount      = 0U;
uint32_t mock_dss_ecc_memctl      = 0U;
uint32_t mock_dss_ecc_irq_enabled = 0U;
/**
 * Reset all mock variables to initial state
 */
void mock_dss_ecc_reset(void)
{
   mock_axi_ecc_register    = 0U;
   mock_write_count         = 0U;
   mock_read_count          = 0U;
   mock_write_fails         = false;
   mock_csrpctl_register    = 0U;
   mock_csrpctl_write_count = 0U;
   mock_csrpctl_read_count  = 0U;
   mock_csrpctl_write_fails = false;
   mock_dss_ecc_dram_memory = 0;
   mock_dss_ecc_iram_memory = 0;
   mock_dss_ecc_mesr        = 0U;
   mock_dss_ecc_ccount      = 0U;
   mock_dss_ecc_memctl      = 0U;
   mock_dss_ecc_irq_enabled = 0U;
}

/**
 * Mock implementation of XT_RER (Read External Register)
 */
uint32_t mock_XT_RER(uint32_t address)
{
   mock_read_count++;
   return mock_axi_ecc_register;
}

/**
 * Mock implementation of XT_WER (Write External Register)
 */
void mock_XT_WER(uint32_t value, uint32_t address)
{
   mock_write_count++;
   if (!mock_write_fails)
   {
      mock_axi_ecc_register = value;
   }
}

/**
 * Mock implementation of XT_ISYNC (Instruction Sync)
 */
void mock_XT_ISYNC(void)
{
   /* No operation for mock */
}

uint32_t mock_XT_RSR_CSRPCTL(void)
{
   mock_csrpctl_read_count++;
   return mock_csrpctl_register;
}

void mock_XT_WSR_CSRPCTL(uint32_t value)
{
   mock_csrpctl_write_count++;
   if (!mock_csrpctl_write_fails)
   {
      mock_csrpctl_register = value;
   }
}

uint32_t mock_XT_RSR_MESR(void)
{
   return mock_dss_ecc_mesr;
}

void mock_XT_WSR_MESR(uint32_t value)
{
   mock_dss_ecc_mesr = value;
}

uint32_t mock_XT_RSR_CCOUNT(void)
{
   return mock_dss_ecc_ccount;
}

void mock_XT_MEMW(void)
{
}

void mock_XT_EXTW(void)
{
}

void mock_XT_ESYNC(void)
{
}

uint32_t mock_XT_RSR_MEMCTL(void)
{
   return mock_dss_ecc_memctl;
}

void mock_XT_WSR_MEMCTL(uint32_t value)
{
   mock_dss_ecc_memctl = value;
}

void mock_dss_ecc_irq_enable(void)
{
   mock_dss_ecc_irq_enabled = 1U;
}
