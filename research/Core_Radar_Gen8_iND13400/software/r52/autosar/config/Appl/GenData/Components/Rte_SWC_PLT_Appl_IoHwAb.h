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
 *             File:  Rte_SWC_PLT_Appl_IoHwAb.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_Appl_IoHwAb>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_APPL_IOHWAB_H
# define RTE_SWC_PLT_APPL_IOHWAB_H

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

# include "Rte_SWC_PLT_Appl_IoHwAb_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_Analog_Channel_Count_De_Analog_Channel_Count;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_BoardRevision_Xcp_De_BoardRevision_Xcp;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_MCU_Sensor_Count_De_MCU_Sensor_Count;
extern VAR(Dt_VBattState_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_Analog_Channel_Count_De_Analog_Channel_Count (0U)
#  define Rte_InitValue_Pp_BoardRevision_Xcp_De_BoardRevision_Xcp (0U)
#  define Rte_InitValue_Pp_Board_Revision_De_Board_Revision (85U)
#  define Rte_InitValue_Pp_MCU_Sensor_Count_De_MCU_Sensor_Count (0U)
#  define Rte_InitValue_Pp_SubState_De_SubState (0U)
#  define Rte_InitValue_Pp_TimeLeft_To_NextState_De_TimeLeft_To_NextState (0U)
#  define Rte_InitValue_Pp_Vbatt_State_De_Vbatt_State (0U)
#  define Rte_InitValue_Rp_ECUPos_Value_De_ECUPos_Value (0U)
#  define Rte_InitValue_Rp_IoHwAb_VRM_State_De_VBattState_T (0U)
#  define Rte_InitValue_Rp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override (1U)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_PhysicalAdcData_De_PhysicalAdcData(P2CONST(Dt_AdcData_T, AUTOMATIC, RTE_SWC_PLT_APPL_IOHWAB_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_RawAdc_Data_Filtered_De_RawAdcData(P2CONST(Dt_RawAdcDataFilt_T, AUTOMATIC, RTE_SWC_PLT_APPL_IOHWAB_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered(P2CONST(Dt_RawAdcData_T, AUTOMATIC, RTE_SWC_PLT_APPL_IOHWAB_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_ECUPos_Value_De_ECUPos_Value Rte_Read_SWC_PLT_Appl_IoHwAb_Rp_ECUPos_Value_De_ECUPos_Value
#  define Rte_Read_SWC_PLT_Appl_IoHwAb_Rp_ECUPos_Value_De_ECUPos_Value(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override Rte_Read_SWC_PLT_Appl_IoHwAb_Rp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override
#  define Rte_Read_SWC_PLT_Appl_IoHwAb_Rp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override(data) (*(data) = Rte_SWC_PLT_CDD_XCP_Pp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_ADC_Measurement_interface_Element Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_ADC_Measurement_interface_Element
#  define Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_ADC_Measurement_interface_Element(data) (RTE_E_OK)
#  define Rte_Write_Pp_Analog_Channel_Count_De_Analog_Channel_Count Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_Analog_Channel_Count_De_Analog_Channel_Count
#  define Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_Analog_Channel_Count_De_Analog_Channel_Count(data) (Rte_SWC_PLT_Appl_IoHwAb_Pp_Analog_Channel_Count_De_Analog_Channel_Count = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_BoardRevision_Xcp_De_BoardRevision_Xcp Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_BoardRevision_Xcp_De_BoardRevision_Xcp
#  define Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_BoardRevision_Xcp_De_BoardRevision_Xcp(data) (Rte_SWC_PLT_Appl_IoHwAb_Pp_BoardRevision_Xcp_De_BoardRevision_Xcp = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Board_Revision_De_Board_Revision Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_Board_Revision_De_Board_Revision
#  define Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_Board_Revision_De_Board_Revision(data) (RTE_E_OK)
#  define Rte_Write_Pp_MCU_Sensor_Count_De_MCU_Sensor_Count Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_MCU_Sensor_Count_De_MCU_Sensor_Count
#  define Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_MCU_Sensor_Count_De_MCU_Sensor_Count(data) (Rte_SWC_PLT_Appl_IoHwAb_Pp_MCU_Sensor_Count_De_MCU_Sensor_Count = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_PhysicalAdcData_De_PhysicalAdcData Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_PhysicalAdcData_De_PhysicalAdcData
#  define Rte_Write_Pp_RawAdc_Data_Filtered_De_RawAdcData Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_RawAdc_Data_Filtered_De_RawAdcData
#  define Rte_Write_Pp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered
#  define Rte_Write_Pp_SubState_De_SubState Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_SubState_De_SubState
#  define Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_SubState_De_SubState(data) (RTE_E_OK)
#  define Rte_Write_Pp_TimeLeft_To_NextState_De_TimeLeft_To_NextState Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_TimeLeft_To_NextState_De_TimeLeft_To_NextState
#  define Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_TimeLeft_To_NextState_De_TimeLeft_To_NextState(data) (RTE_E_OK)
#  define Rte_Write_Pp_Vbatt_State_De_Vbatt_State Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State
#  define Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State(data) (Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_Pp_DcmSessionPrecondition_Mode_De_DcmSessionPrecondition_Mode Rte_Switch_SWC_PLT_Appl_IoHwAb_Pp_DcmSessionPrecondition_Mode_De_DcmSessionPrecondition_Mode
#  define Rte_Switch_SWC_PLT_Appl_IoHwAb_Pp_DcmSessionPrecondition_Mode_De_DcmSessionPrecondition_Mode(mode) (RTE_E_OK)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define SWC_PLT_Service_IoHwAb_START_SEC_CODE
#  include "SWC_PLT_Service_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_PLT_Service_IoHwAb_CODE) CS_RawAdcCount_Read(P2VAR(Dt_RawAdcData_T, AUTOMATIC, RTE_SWC_PLT_SERVICE_IOHWAB_APPL_VAR) RawAdcData); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Service_IoHwAb_STOP_SEC_CODE
#  include "SWC_PLT_Service_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Service_IoHwAb_START_SEC_CODE
#  include "SWC_PLT_Service_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_PLT_Service_IoHwAb_CODE) CS_Update_Thermal_Mon_Temps_Read(P2VAR(DT_Thermal_mon_mes_results_T, AUTOMATIC, RTE_SWC_PLT_SERVICE_IOHWAB_APPL_VAR) therm_temp_results); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Service_IoHwAb_STOP_SEC_CODE
#  include "SWC_PLT_Service_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CS_RawAdcCount_Read CS_RawAdcCount_Read
#  define Rte_Call_CS_Update_Thermal_Mon_Temps_Read CS_Update_Thermal_Mon_Temps_Read

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Dt_EcuPosition_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_IoHwAb_ECU_Position_ROMDefault;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_ECU_Position_ROMDefault() (&Rte_SWC_PLT_Appl_IoHwAb_ECU_Position_ROMDefault)

# endif /* !defined(RTE_CORE) */


# define SWC_PLT_Appl_IoHwAb_START_SEC_CODE
# include "SWC_PLT_Appl_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_Platform_register_set CS_Platform_register_set
#  define RTE_RUNNABLE_CS_ThermMonTemp_Read CS_ThermMonTemp_Read
#  define RTE_RUNNABLE_RE_PLT_IoHwAb_Init RE_PLT_IoHwAb_Init
#  define RTE_RUNNABLE_RE_PLT_IoHwAb_Main_10ms RE_PLT_IoHwAb_Main_10ms
#  define RTE_RUNNABLE_RE_PLT_IoHwAb_Main_50ms RE_PLT_IoHwAb_Main_50ms
#  define RTE_RUNNABLE_RE_PLT_IoHwAb_Main_5ms RE_PLT_IoHwAb_Main_5ms
# endif

FUNC(void, SWC_PLT_Appl_IoHwAb_CODE) CS_Platform_register_set(uint8 fault_type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_PLT_Appl_IoHwAb_CODE) CS_ThermMonTemp_Read(Dt_Therm_Mon_Temp_Opt_T temp_option, P2VAR(DT_Thermal_Monitor_Temperatures_T, AUTOMATIC, RTE_SWC_PLT_APPL_IOHWAB_APPL_VAR) reqValue); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_IoHwAb_CODE) RE_PLT_IoHwAb_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_IoHwAb_CODE) RE_PLT_IoHwAb_Main_10ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_IoHwAb_CODE) RE_PLT_IoHwAb_Main_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_IoHwAb_CODE) RE_PLT_IoHwAb_Main_5ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PLT_Appl_IoHwAb_STOP_SEC_CODE
# include "SWC_PLT_Appl_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Pi_RawAdcCount_E_NOT_OK (1U)

#  define RTE_E_Pi_ThermMonTemp_E_NOT_OK (1U)

#  define RTE_E_Pi_Update_Thermal_Mon_Temps_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_APPL_IOHWAB_H */

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
