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
 *             File:  Rte_SWC_PRJ_Appl_Security_Manager_Type.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application types header file for SW-C <SWC_PRJ_Appl_Security_Manager>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PRJ_APPL_SECURITY_MANAGER_TYPE_H
# define RTE_SWC_PRJ_APPL_SECURITY_MANAGER_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef E_NOT_OK
#   define E_NOT_OK (1U)
#  endif

#  ifndef CRYPTO_E_BUSY
#   define CRYPTO_E_BUSY (2U)
#  endif

#  ifndef CRYPTO_E_ENTROPY_EXHAUSTED
#   define CRYPTO_E_ENTROPY_EXHAUSTED (4U)
#  endif

#  ifndef CRYPTO_E_KEY_READ_FAIL
#   define CRYPTO_E_KEY_READ_FAIL (6U)
#  endif

#  ifndef CRYPTO_E_KEY_WRITE_FAIL
#   define CRYPTO_E_KEY_WRITE_FAIL (7U)
#  endif

#  ifndef CRYPTO_E_KEY_NOT_AVAILABLE
#   define CRYPTO_E_KEY_NOT_AVAILABLE (8U)
#  endif

#  ifndef CRYPTO_E_KEY_NOT_VALID
#   define CRYPTO_E_KEY_NOT_VALID (9U)
#  endif

#  ifndef CRYPTO_E_KEY_SIZE_MISMATCH
#   define CRYPTO_E_KEY_SIZE_MISMATCH (10U)
#  endif

#  ifndef CRYPTO_E_JOB_CANCELED
#   define CRYPTO_E_JOB_CANCELED (12U)
#  endif

#  ifndef CRYPTO_E_KEY_EMPTY
#   define CRYPTO_E_KEY_EMPTY (13U)
#  endif
# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PRJ_APPL_SECURITY_MANAGER_TYPE_H */
