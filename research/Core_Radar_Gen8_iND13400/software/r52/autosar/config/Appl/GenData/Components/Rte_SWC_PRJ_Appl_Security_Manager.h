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
 *             File:  Rte_SWC_PRJ_Appl_Security_Manager.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PRJ_Appl_Security_Manager>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PRJ_APPL_SECURITY_MANAGER_H
# define RTE_SWC_PRJ_APPL_SECURITY_MANAGER_H

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

# include "Rte_SWC_PRJ_Appl_Security_Manager_Type.h"
# include "Rte_DataHandleType.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_Security_Manager_Pp_Crypto_customfuntions_version_De_Crypto_CustomFunctions_Version(P2CONST(Crypto_CustomFunctions_VersionStruct, AUTOMATIC, RTE_SWC_PRJ_APPL_SECURITY_MANAGER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_Crypto_customfuntions_version_De_Crypto_CustomFunctions_Version Rte_Write_SWC_PRJ_Appl_Security_Manager_Pp_Crypto_customfuntions_version_De_Crypto_CustomFunctions_Version


# endif /* !defined(RTE_CORE) */


# define SWC_PRJ_Appl_Security_Manager_START_SEC_CODE
# include "SWC_PRJ_Appl_Security_Manager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_HSE_Security_Compare_key_Operation CS_HSE_Security_Compare_key_Operation
#  define RTE_RUNNABLE_CS_HSE_Security_generate_seed_Operation CS_HSE_Security_generate_seed_Operation
#  define RTE_RUNNABLE_RE_Security_Manager_50ms RE_Security_Manager_50ms
#  define RTE_RUNNABLE_RE_Security_Manager_Init RE_Security_Manager_Init
# endif

# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(void, SWC_PRJ_Appl_Security_Manager_CODE) CS_HSE_Security_Compare_key_Operation(uint8 Security_Level, P2CONST(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_SECURITY_MANAGER_APPL_DATA) Encrypted_key, P2VAR(Crypto_ResultType, AUTOMATIC, RTE_SWC_PRJ_APPL_SECURITY_MANAGER_APPL_VAR) verify_Result); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(void, SWC_PRJ_Appl_Security_Manager_CODE) CS_HSE_Security_Compare_key_Operation(uint8 Security_Level, P2CONST(Dcm_Data16ByteType, AUTOMATIC, RTE_SWC_PRJ_APPL_SECURITY_MANAGER_APPL_DATA) Encrypted_key, P2VAR(Crypto_ResultType, AUTOMATIC, RTE_SWC_PRJ_APPL_SECURITY_MANAGER_APPL_VAR) verify_Result); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(void, SWC_PRJ_Appl_Security_Manager_CODE) CS_HSE_Security_generate_seed_Operation(uint8 Security_level, P2VAR(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_SECURITY_MANAGER_APPL_VAR) Seed_Value); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PRJ_Appl_Security_Manager_CODE) RE_Security_Manager_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PRJ_Appl_Security_Manager_CODE) RE_Security_Manager_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PRJ_Appl_Security_Manager_STOP_SEC_CODE
# include "SWC_PRJ_Appl_Security_Manager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PRJ_APPL_SECURITY_MANAGER_H */

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
