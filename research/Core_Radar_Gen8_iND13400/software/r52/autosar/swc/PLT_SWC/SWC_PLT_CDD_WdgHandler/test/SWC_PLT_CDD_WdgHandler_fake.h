#ifndef SWC_PLT_CDD_WDGHANDLER_H
#define SWC_PLT_CDD_WDGHANDLER_H

#include "fff.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "Rte_Type.h"
#include "WdgIf_Types.h"

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Appl_Internal_Wdg_Instance_SetMode, WdgIf_ModeType);
   DECLARE_FAKE_VOID_FUNC(Appl_Internal_Wdg_Instance_SetTriggerCondition, uint16);
   DECLARE_FAKE_VOID_FUNC(Appl_Wdg_Disable, Dt_Wdg_Type);

#ifdef __cplusplus
}
#endif

#endif
