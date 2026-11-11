#include "SWC_PLT_Appl_IntWDG_fake.h"

DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, WdgM_SetMode, WdgM_ModeType, uint16);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, WdgM_CheckpointReached, WdgM_SupervisedEntityIdType, WdgM_CheckpointIdType);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, WdgM_DeactivateSupervisionEntity, WdgM_SupervisedEntityIdType);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, WdgM_ActivateSupervisionEntity, WdgM_SupervisedEntityIdType);
DEFINE_FAKE_VOID_FUNC(WdgM_Init, const WdgM_ConfigType *);
