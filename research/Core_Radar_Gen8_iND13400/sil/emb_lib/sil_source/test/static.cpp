#include "sil_wrapper.h"

int main()
{
   const auto init_status = SRR7_SiL_Init(nullptr);
   if (init_status == SIL_Status_T::E_SIL_RUN_OK)
   {
      SRR7_SiL_Execute(nullptr, nullptr);
      return 0;
   }
   return 1;
}
