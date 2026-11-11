#include "SWC_Appl_Project_fake.h"

DEFINE_FFF_GLOBALS;

DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_Appl_Project_Rp_XCP_Set_Output_State_De_XCP_Set_Output, Dt_XCP_Set_Output *);
DEFINE_FAKE_VOID_FUNC(Dio_WriteChannel, Dio_ChannelType, Dio_LevelType);
