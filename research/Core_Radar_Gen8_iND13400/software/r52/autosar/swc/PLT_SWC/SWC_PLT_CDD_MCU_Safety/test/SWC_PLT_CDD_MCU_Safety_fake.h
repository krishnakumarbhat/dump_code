#ifndef SWC_PLT_CDD_MCU_Safety_FAKE_H
#define SWC_PLT_CDD_MCU_Safety_FAKE_H

#include "Rte_Type.h"
#include "fff.h"
#include "mcu_reset_wrapper.h"
DECLARE_FAKE_VOID_FUNC(Mcu_Reset, Mcu_reset_T);
#ifdef __cplusplus
extern "C"
{
#endif
   DECLARE_FAKE_VOID_FUNC(MCU_Safety_Init);
   DECLARE_FAKE_VOID_FUNC(MCU_Safety_50ms);
#ifdef __cplusplus
}
#endif
#define FFF_FAKES_MCU_Safety_LIST(FAKE)                                                                                           \
   FAKE(Mcu_Reset)                                                                                                                \
   FAKE(MCU_Safety_Init)                                                                                                          \
   FAKE(MCU_Safety_50ms)
#endif
