/*===========================================================================*/
/**
 * @file SWC_PRJ_Appl_Power_Manager_fake.cc
 *
 * Fake/Mock implementation file for SWC_PRJ_Appl_Power_Manager unit testing
 */
/*===========================================================================*/

#include "SWC_PRJ_Appl_Power_Manager_fake.h"

DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * RTE Fake Function Definitions
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PRJ_Appl_Power_Manager_Rp_PhysicalAdcData_De_PhysicalAdcData, Dt_AdcData_T *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown,
                       const Dt_OpModeShutdown *);
DEFINE_FAKE_VALUE_FUNC(Board_Revision_T, Get_Board_Revision);
DEFINE_FAKE_VALUE_FUNC(Dio_Wrapper_Status_T, Dio_Wrapper_WriteChannel, Dio_ChannelType, Dio_LevelType);
DEFINE_FAKE_VOID_FUNC(Mcu_Reset, Mcu_reset_T);
