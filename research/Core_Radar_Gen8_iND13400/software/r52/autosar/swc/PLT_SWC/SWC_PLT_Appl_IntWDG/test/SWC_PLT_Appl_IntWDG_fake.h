#ifndef SWC_PLT_Appl_IntWDG_H
#define SWC_PLT_Appl_IntWDG_H

#include "fff.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "Rte_SWC_PLT_Appl_IntWDG.h"
#include "Rte_Type.h"
#include "WdgM.h"

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, WdgM_SetMode, WdgM_ModeType, uint16);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, WdgM_CheckpointReached, WdgM_SupervisedEntityIdType, WdgM_CheckpointIdType);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, WdgM_DeactivateSupervisionEntity, WdgM_SupervisedEntityIdType);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, WdgM_ActivateSupervisionEntity, WdgM_SupervisedEntityIdType);
   DECLARE_FAKE_VOID_FUNC(WdgM_Init, const WdgM_ConfigType *);

#ifdef __cplusplus
}
#endif

#endif
