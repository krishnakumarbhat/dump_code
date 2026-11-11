/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_SWC_PRJ_Appl_SensorPosition.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PRJ_Appl_SensorPosition>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PRJ_APPL_SENSORPOSITION_H
# define RTE_SWC_PRJ_APPL_SENSORPOSITION_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_SWC_PRJ_Appl_SensorPosition_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status Rte_Write_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status
#  define Rte_Write_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status(data) (Rte_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define SWC_PLT_Appl_NvMHandler_START_SEC_CODE
#  include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) CS_ReadNvM_Value_Operation(P2VAR(Dt_SensorPosition_Status_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) Sensorpos_Read_Record); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_NvMHandler_STOP_SEC_CODE
#  include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CS_Sensorpos_ReadNvM_Value_Operation(arg1) (CS_ReadNvM_Value_Operation(arg1), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define SWC_PRJ_Appl_SensorPosition_START_SEC_CODE
# include "SWC_PRJ_Appl_SensorPosition_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_Get_Pinposition_Status_Operation CS_Get_Pinposition_Status_Operation
#  define RTE_RUNNABLE_RE_SensorPosition_50ms RE_SensorPosition_50ms
# endif

FUNC(void, SWC_PRJ_Appl_SensorPosition_CODE) CS_Get_Pinposition_Status_Operation(P2VAR(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_SENSORPOSITION_APPL_VAR) Sensor_Position); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PRJ_Appl_SensorPosition_CODE) RE_SensorPosition_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PRJ_Appl_SensorPosition_STOP_SEC_CODE
# include "SWC_PRJ_Appl_SensorPosition_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PRJ_APPL_SENSORPOSITION_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
