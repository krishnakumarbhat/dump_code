#ifndef MCU_SAFETY_FAKE_H_
#define MCU_SAFETY_FAKE_H_

#include "Rte_Type.h"
#include "fff.h"

#define UNIT_TEST
#ifdef __cplusplus
extern "C"
{
#endif

   /*===========================================================================*
    * Fake value functions - MCU_Safety functions
    *===========================================================================*/

   uint8 Rte_SWC_PLT_CDD_MCU_Safety_Pp_TR_initMCU_Fail_De_TR_InitMCU_fail;
   VAR(Dt_InitializationStatus, RTE_VAR_NOINIT)
   Rte_SWC_PLT_CDD_MCU_Safety_Pp_PlatformInitializationStatus_De_MCU_InitializationStatus;
   uint8 Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime;

   /*===========================================================================*
    * Fake functions - NOC_Handler functions called from MCU_Safety
    *===========================================================================*/
   DECLARE_FAKE_VOID_FUNC(Clear_StickyDiag_MissionFault_registers);
   DECLARE_FAKE_VOID_FUNC(NOC_Run_Bist_Chandra);
   DECLARE_FAKE_VOID_FUNC(NOC_Run_Bist_Small);
   DECLARE_FAKE_VOID_FUNC(NOC_Run_Bist_Artie);
   DECLARE_FAKE_VOID_FUNC(NOC_Verify_Chandra_LatentIsr_Execution);
   DECLARE_FAKE_VOID_FUNC(NOC_Verify_Artie_LatentIsr_Execution);
   DECLARE_FAKE_VOID_FUNC(NOC_Verify_Small_LatentIsr_Execution);

#ifdef __cplusplus
}
#endif

#define FFF_FAKES_MCU_SAFETY_NOC_LIST(FAKE)                                                                                       \
   FAKE(Clear_StickyDiag_MissionFault_registers)                                                                                  \
   FAKE(NOC_Run_Bist_Chandra)                                                                                                     \
   FAKE(NOC_Run_Bist_Small)                                                                                                       \
   FAKE(NOC_Run_Bist_Artie)                                                                                                       \
   FAKE(NOC_Verify_Chandra_LatentIsr_Execution)                                                                                   \
   FAKE(NOC_Verify_Artie_LatentIsr_Execution)                                                                                     \
   FAKE(NOC_Verify_Small_LatentIsr_Execution)

#endif /* MCU_SAFETY_H_ */
