#include <gtest/gtest.h>

extern "C"
{
#include "Mss_Ecc_Parity.h"

   extern uint32_t sysmem_ecc_inject_sec_call_count;
   extern uint32_t sysmem_ecc_inject_ded_call_count;
}

TEST(Mss_Ecc_Parity_UnitTestSuite, Execute_CallsSECAndDED)
{
   sysmem_ecc_inject_sec_call_count = 0u;
   sysmem_ecc_inject_ded_call_count = 0u;

   Ecc_Fault_Injection_Test();

   EXPECT_EQ(sysmem_ecc_inject_sec_call_count, 1u);
   EXPECT_EQ(sysmem_ecc_inject_ded_call_count, 1u);
}
