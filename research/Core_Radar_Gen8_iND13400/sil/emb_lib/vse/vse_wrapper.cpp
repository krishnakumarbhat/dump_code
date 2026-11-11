#include "vse_wrapper.h"
#include "VSE_Core.h"
#include "VSE_Teststub.h"
#include "debug_stream.h"
#include "emblib_ipc_data.h"
#include "string.h"

#define ENABLE_VSE_TEST_STUBS FALSE

#if ENABLE_VSE_TEST_STUBS

static double g_vse_time = 0.0;
#endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_IPC_VSE_Handler_10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_IPC_VSE_Handler_10ms_doc
 *********************************************************************************************************************/
#if ENABLE_VSE_TEST_STUBS
void VSE_Input_Stub_Update(M2D_Msg_T *m2d_msg_ptr)
{
   build_vse_cycle(g_vse_time, &m2d_msg_ptr->payload.veh_data.veh_raw_data[0], &m2d_msg_ptr->payload.veh_data.veh_raw_misc,
                   &m2d_msg_ptr->payload.veh_data.veh_params, &m2d_msg_ptr->payload.veh_data.latest_raw_index);

   g_vse_time += 0.010;
   if (g_vse_time >= 9.0)
   {
      g_vse_time = 0.0;
   }
}
#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_CDD_IPC_CODE) RE_IPC_VSE_Handler_10ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_IPC_VSE_Handler_10ms
    *********************************************************************************************************************/
   M2D_Msg_T *m2d_msg_ptr = Get_IPC_M2D_Buffer();
#if ENABLE_VSE_TEST_STUBS
   VSE_Input_Stub_Update((M2D_Msg_T *)m2d_msg_ptr);
#endif
   Run_VSE(m2d_msg_ptr);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}
