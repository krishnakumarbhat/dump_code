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
 *             File:  Rte_SWC_PLT_Service_IoHwAb.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_Service_IoHwAb>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_SERVICE_IOHWAB_H
# define RTE_SWC_PLT_SERVICE_IOHWAB_H

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

# include "Rte_SWC_PLT_Service_IoHwAb_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_ADC_XCP_Req_De_ADC_XCP_Req;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Rp_ADC_XCP_Req_De_ADC_XCP_Req (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_ADC_XCP_Req_De_ADC_XCP_Req Rte_Read_SWC_PLT_Service_IoHwAb_Rp_ADC_XCP_Req_De_ADC_XCP_Req
#  define Rte_Read_SWC_PLT_Service_IoHwAb_Rp_ADC_XCP_Req_De_ADC_XCP_Req(data) (*(data) = Rte_SWC_PLT_CDD_XCP_Pp_ADC_XCP_Req_De_ADC_XCP_Req, ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define SWC_PLT_Service_IoHwAb_START_SEC_CODE
# include "SWC_PLT_Service_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_RawAdcCount_Read CS_RawAdcCount_Read
#  define RTE_RUNNABLE_CS_Update_Thermal_Mon_Temps_Read CS_Update_Thermal_Mon_Temps_Read
#  define RTE_RUNNABLE_Get_FloatingPinPosition_FaultStatus Get_FloatingPinPosition_FaultStatus
#  define RTE_RUNNABLE_Get_STM_TimeStamp Get_STM_TimeStamp
#  define RTE_RUNNABLE_Pp_PWMDutyCycle Pp_PWMDutyCycle
#  define RTE_RUNNABLE_RE_PLT_Service_IoHwAb_ADCFilter_5ms RE_PLT_Service_IoHwAb_ADCFilter_5ms
#  define RTE_RUNNABLE_RE_PLT_Service_IoHwAb_Init RE_PLT_Service_IoHwAb_Init
#  define RTE_RUNNABLE_RE_PLT_Service_IoHwAb_Main_5ms RE_PLT_Service_IoHwAb_Main_5ms
#  define RTE_RUNNABLE_Set_DIO_LED_SRC_PULL Set_DIO_LED_SRC_PULL
# endif

FUNC(Std_ReturnType, SWC_PLT_Service_IoHwAb_CODE) CS_RawAdcCount_Read(P2VAR(Dt_RawAdcData_T, AUTOMATIC, RTE_SWC_PLT_SERVICE_IOHWAB_APPL_VAR) RawAdcData); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_PLT_Service_IoHwAb_CODE) CS_Update_Thermal_Mon_Temps_Read(P2VAR(DT_Thermal_mon_mes_results_T, AUTOMATIC, RTE_SWC_PLT_SERVICE_IOHWAB_APPL_VAR) therm_temp_results); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Service_IoHwAb_CODE) Get_FloatingPinPosition_FaultStatus(P2VAR(uint8, AUTOMATIC, RTE_SWC_PLT_SERVICE_IOHWAB_APPL_VAR) Status); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Service_IoHwAb_CODE) Get_STM_TimeStamp(P2VAR(uint32, AUTOMATIC, RTE_SWC_PLT_SERVICE_IOHWAB_APPL_VAR) arg); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Service_IoHwAb_CODE) Pp_PWMDutyCycle(uint8 DutyCycle); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Service_IoHwAb_CODE) RE_PLT_Service_IoHwAb_ADCFilter_5ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Service_IoHwAb_CODE) RE_PLT_Service_IoHwAb_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Service_IoHwAb_CODE) RE_PLT_Service_IoHwAb_Main_5ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, SWC_PLT_Service_IoHwAb_CODE) Set_DIO_LED_SRC_PULL(uint8 Data); /* PRQA S 1330, 3451, 0786, 3449, 3451, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define SWC_PLT_Service_IoHwAb_STOP_SEC_CODE
# include "SWC_PLT_Service_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Pi_RawAdcCount_E_NOT_OK (1U)

#  define RTE_E_Pi_Set_DIO_LED_SRC_PULL_E_NOT_OK (1U)

#  define RTE_E_Pi_Update_Thermal_Mon_Temps_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_SERVICE_IOHWAB_H */

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

   MD_Rte_1330:  MISRA rule: Rule8.3
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
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
