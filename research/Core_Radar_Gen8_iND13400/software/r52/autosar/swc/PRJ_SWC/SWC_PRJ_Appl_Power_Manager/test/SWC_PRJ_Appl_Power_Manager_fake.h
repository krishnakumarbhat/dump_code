#ifndef SWC_PRJ_APPL_POWER_MANAGER_FAKE_H
#define SWC_PRJ_APPL_POWER_MANAGER_FAKE_H

#include "fff.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#include "Dio.h"
#include "Rte_Type.h"
#include "board_revision.h"
#include "dio_wrapper.h"
#include "mcu_reset_wrapper.h"

   /*===========================================================================*
    * RTE Fake Function Declarations
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PRJ_Appl_Power_Manager_Rp_PhysicalAdcData_De_PhysicalAdcData,
                           Dt_AdcData_T *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown,
                           const Dt_OpModeShutdown *);
   DECLARE_FAKE_VALUE_FUNC(Board_Revision_T, Get_Board_Revision);
   DECLARE_FAKE_VALUE_FUNC(Dio_Wrapper_Status_T, Dio_Wrapper_WriteChannel, Dio_ChannelType, Dio_LevelType);
   DECLARE_FAKE_VOID_FUNC(Mcu_Reset, Mcu_reset_T);

#ifdef __cplusplus
}
#endif

#endif /* SWC_PRJ_APPL_POWER_MANAGER_FAKE_H */
