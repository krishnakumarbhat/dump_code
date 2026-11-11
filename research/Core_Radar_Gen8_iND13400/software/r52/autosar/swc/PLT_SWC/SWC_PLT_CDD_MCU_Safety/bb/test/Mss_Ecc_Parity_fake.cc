#include "Mss_Ecc_Parity_fake.h"

/*===========================================================================*
 * Fake function definitions for ECC Fault Injection
 *===========================================================================*/
extern "C"
{
   DEFINE_FAKE_VOID_FUNC(ECC_Irq_Enable);
   DEFINE_FAKE_VOID_FUNC(ECC_Sec_Threshold_Config);
   DEFINE_FAKE_VOID_FUNC(Ecc_Fault_Injection_Test);
}
