#include "SWC_PLT_CDD_WdgHandler_fake.h"

DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Appl_Internal_Wdg_Instance_SetMode, WdgIf_ModeType);
DEFINE_FAKE_VOID_FUNC(Appl_Internal_Wdg_Instance_SetTriggerCondition, uint16);
DEFINE_FAKE_VOID_FUNC(Appl_Wdg_Disable, Dt_Wdg_Type);
