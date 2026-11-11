#ifndef SIL_WRAPPER_H
#define SIL_WRAPPER_H

#include "Radar_SIL_Version.h"
#include "Resim_Config.h"
#include <cstdio>

#ifdef __cplusplus
extern "C"
{
#endif
   enum class SIL_Status_T : int
   {
      E_SIL_RUN_OK = 0,
      E_SIL_RUN_ERR,
      E_SIL_INIT_ERR,
      E_SIL_PENDING_STATE
   };
#if defined(_WIN32) || defined(__WIN32__)
   #ifdef EMB_LIB_SIL_WRAPPER_SHARED_EXPORT // compiling dll
      #define SHAREDLIB_API __declspec(dllexport)
   #elif defined(EMB_LIB_SIL_WRAPPER_STATIC) // compiling staticlib, needed because no #define implies using the dll
      #define SHAREDLIB_API
   #else
      #define SHAREDLIB_API __declspec(dllimport) // using dll
   #endif
#else
   // For non-windows this macro is noop.
   #define SHAREDLIB_API
#endif // WIN32
   SHAREDLIB_API SIL_Status_T SRR7_SiL_Init(const SIL_RADAR_Config_T *config);
   SHAREDLIB_API SIL_Status_T SRR7_SiL_Reset();
   SHAREDLIB_API SIL_Status_T SRR7_SiL_Execute(const SIL_RADAR_Input_Data_T *input, SIL_RADAR_Output_Data_T *output);
   SHAREDLIB_API SIL_Status_T SRR7_SiL_SetFolderPath(const char *input_log_path);
   SHAREDLIB_API SIL_Status_T SRR7_SiL_Exit(FILE *fptr, int sensor_id);
   SHAREDLIB_API SIL_Status_T SRR7_SiL_GetVersion(RADAR_Version_Info_T **pp_version);
#undef SHAREDLIB_API
#ifdef __cplusplus
}
#endif // __cplusplus
#endif // SIL_WRAPPER_H
