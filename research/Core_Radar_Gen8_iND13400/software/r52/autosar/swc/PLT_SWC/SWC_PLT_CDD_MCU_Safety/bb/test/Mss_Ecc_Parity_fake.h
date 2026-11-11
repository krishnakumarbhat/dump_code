#ifndef MSS_ECC_PARITY_FAKE_H
#define MSS_ECC_PARITY_FAKE_H

#ifdef __cplusplus
extern "C"
{
   #include "fff.h"
}
#endif

#ifdef __cplusplus
extern "C"
{
#endif

   DECLARE_FAKE_VOID_FUNC(ECC_Irq_Enable);
   DECLARE_FAKE_VOID_FUNC(ECC_Sec_Threshold_Config);
   DECLARE_FAKE_VOID_FUNC(Ecc_Fault_Injection_Test);
   DECLARE_FAKE_VOID_FUNC(ARTIEMEM_SEC_Fault_Injection);
   DECLARE_FAKE_VOID_FUNC(ARTIEMEM_DED_Fault_Injection);
   DECLARE_FAKE_VOID_FUNC(SET_SEC_Threshold);

#ifdef __cplusplus
}
#endif

#define FFF_FAKES_MSS_ECC_PARITY_LIST(FAKE)                                                                                       \
   FAKE(ECC_Irq_Enable)                                                                                                           \
   FAKE(ECC_Sec_Threshold_Config)                                                                                                 \
   FAKE(Ecc_Fault_Injection_Test)                                                                                                 \
   FAKE(ARTIEMEM_SEC_Fault_Injection)                                                                                             \
   FAKE(ARTIEMEM_DED_Fault_Injection)                                                                                             \
   FAKE(SET_SEC_Threshold)

#endif /* MSS_ECC_PARITY_FAKE_H */
