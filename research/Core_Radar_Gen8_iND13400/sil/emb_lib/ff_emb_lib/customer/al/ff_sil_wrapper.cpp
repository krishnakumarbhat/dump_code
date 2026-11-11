#if defined(FEATURE_ENABLE)
   #include "ff_sil_wrapper.h"
   #include "OLP_wrapper.h"
   #include "SFL_Wrapper.h"
   #include "profile_timing.h"
#endif

void feature_run()
{
#if defined(FEATURE_ENABLE)

   TIMER_START(FEATURE_FUNCTION);
   static bool Is_FF_initialised = false;

   if (Is_FF_initialised == false)
   {
      /* Start of Customer specific modules initialization*/
      Olp_Init();
      Feature_Function_Init();
      /* End of Customer specific modules initialization*/

      Is_FF_initialised = true;
   }

   /* Start of Customer specific modules periodic execution*/
   Olp_Main();
   Feature_Function_Run_50ms();

   /* End of Customer specific modules periodic execution*/
   TIMER_STOP(FEATURE_FUNCTION);

#endif
}
