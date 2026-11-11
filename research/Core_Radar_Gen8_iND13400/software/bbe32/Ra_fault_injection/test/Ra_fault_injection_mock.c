#include "Ra_fault_injection_mock.h"
#include <string.h>

RA_SFRS_t mock_ra_regs;
RA_MEM_t mock_ra_mem_regs;

uintptr_t RA_base     = (uintptr_t)&mock_ra_regs;
uintptr_t RA_MEM_base = (uintptr_t)&mock_ra_mem_regs;

void RA_MockReset(void)
{
   memset(&mock_ra_regs, 0, sizeof(mock_ra_regs));
   memset(&mock_ra_mem_regs, 0, sizeof(mock_ra_mem_regs));
}
