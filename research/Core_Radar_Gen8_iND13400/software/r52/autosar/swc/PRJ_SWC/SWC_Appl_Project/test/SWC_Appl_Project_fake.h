#ifndef SWC_APPL_PROJECT_FAKE_H_
#define SWC_APPL_PROJECT_FAKE_H_

#include "fff.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "Dio.h"
#include "Rte_SWC_Appl_Project.h"

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_Appl_Project_Rp_XCP_Set_Output_State_De_XCP_Set_Output,
                           Dt_XCP_Set_Output *);
   DECLARE_FAKE_VOID_FUNC(Dio_WriteChannel, Dio_ChannelType, Dio_LevelType);

#ifdef __cplusplus
}
#endif

#endif
