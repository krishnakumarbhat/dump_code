#ifndef INTERFERENCE_DETECTION_ALGO_INTERFACE_H /* { */
   #define INTERFERENCE_DETECTION_ALGO_INTERFACE_H
   /*===========================================================================*\
    * FILE: interference_detection_algo_interface.h
    *===========================================================================
    * Copyright 2013 Delphi Technologies, Inc., All Rights Reserved.
    * Delphi Confidential
    *---------------------------------------------------------------------------
    *
    * DESCRIPTION:
    *   This file contains the header files for Common Functions.
    *
    * ABBREVIATIONS:
    *   TODO: List of abbreviations used, or reference(s) to external document(s)
    *
    * TRACEABILITY INFO:
    *   - Design Document(s):
    *       SDD Link : polarionprod1.delphiauto.net/polarion/#/project/RadarCoreGeneration4Radars/
    *                     wiki/SW_Detailed_Design/SDD_ASBBRCOR_Interference_Detection
    *
    *   - Requirements Document(s):
    *       SRD Link : polarionprod1.delphiauto.net/polarion/#/project/RadarCoreGeneration4Radars/
    *					   wiki/SW_Requirements/SRD_ASBBRCOR_Interference_Detection
    *
    *   Applicable Standards (in order of precedence: highest first):
    *     SW REF 264.15D "Delphi C Coding Standards" [12-Mar-2006]
    *
    * DEVIATIONS FROM STANDARDS:
    *   None.
    *
   \*===========================================================================*/
   /*===========================================================================*\
    * Standard Header Files
   \*===========================================================================*/

   /*===========================================================================*\
    * Other Header Files
   \*===========================================================================*/
   #include "idbb_include.h"
   #include "interference_detection.h"
   #include "ipc_data.h"
   #include "mem_pool.h"

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/

/*===========================================================================*\
 * Exported Object Declarations
\*===========================================================================*/

/* ========================================================================== *
 *                            Structures
 * ========================================================================== */

/**
 * @brief Structure to hold memory allocation info for ID module
 */
typedef struct ID_Internal_Mem_Info_Tag
{
   uint32_t size;   /**< Size of memory block required */
   void **addr_ptr; /**< Pointer to address pointer */
} ID_Internal_Mem_Info_T;

   #define ID_MP_MAX_NUM_MEMORY_LOC (1U) /**< Maximum number of memory locations for ID */

typedef struct ID_INPUT_Tag
{
   Rdd_Stream_T *p_rdd_stream;
   Vse_Stream_T *p_vse_stream;
   ID_Stream_T *p_id_stream;
} ID_INPUT_T;

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/

   #ifdef __cplusplus
extern "C"
{
   #endif

   extern void ID_Init_BB_Params(ID_INPUT_T *id_input_data);
   extern void interference_detection_wrapper(M2D_Msg_T *p_m2d, D2M_Msg_T *p_d2m);
   extern void ID_Populate_Logging_Structure(ID_INPUT_T *id_input_data);
   extern void ID_Clear_Logging_Data(void);

   #ifdef __cplusplus
}
   #endif

#endif /* } INTERFERENCE_DETECTION_ALGO_INTERFACE_H */

/*===========================================================================*/
/*!
 * @file
 *
 * @section RH REVISION HISTORY (top to bottom: first revision to last revision)
 *
 * - 03-Dec-2022 Indresh Singh : CUX-2942, Added Interference_Detection Component.
 */
/*===========================================================================*/
/** @} doxygen end group */
