#include "static_align_main_fake.h"
#include "fff.h"
DEFINE_FFF_GLOBALS;

DEFINE_FAKE_VALUE_FUNC(M2D_Msg_T *, Get_IPC_M2D_Onetime_Msg_Buffer);
DEFINE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_IPC_D2M_Sp_Post_Proc_Buffer);
DEFINE_FAKE_VALUE_FUNC(M2D_One_Time_Msg_T *, Get_IPC_M2D_One_Time_Buffer);
