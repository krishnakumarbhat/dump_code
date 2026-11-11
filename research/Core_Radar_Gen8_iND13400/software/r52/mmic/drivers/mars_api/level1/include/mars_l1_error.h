/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#ifndef MARS_L1_ERROR_H
#define MARS_L1_ERROR_H

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_public_types.h"
#include "mars_error.h"
/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern void mars_set_l1_error_information(Mars_ReturnType *const ret_val_ptr, const uint32 instance_id, const uint32 error_l1, const uint32 error_id);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/**********************************************************************************************************************
 * MARS ERROR L1
 *********************************************************************************************************************/
#define MARS_ERROR_L1_CRC           (1UL  << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars CRC Level 1 Error Type*/
#define MARS_ERROR_L1_GPIO_RESET    (2UL  << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars GPIO_RESET Level 1 Error Type*/
#define MARS_ERROR_L1_GPIO_MLBX     (3UL  << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars GPIO_MLBX Level 1 Error Type*/
#define MARS_ERROR_L1_GPIO_GP0      (4UL  << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars GPIO_GP0 Level 1 Error Type*/
#define MARS_ERROR_L1_GPIO_SFT      (5UL  << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars GPIO_SFT Level 1 Error Type*/
#define MARS_ERROR_L1_OC            (6UL  << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars Output Compare Level 1 Error Type*/
#define MARS_ERROR_L1_SSI           (7UL  << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars SSI Level 1 Error Type*/
#define MARS_ERROR_L1_TMR           (8UL  << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars Timer Level 1 Error Type*/
#define MARS_ERROR_L1_INIT          (9UL  << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars Init Level 1 Error Type*/
#define MARS_ERROR_L1_REG           (10UL << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars Register Level 1 Error Type*/
#define MARS_ERROR_L1_REG_UNUSED    (11UL << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars Register Unused Level 1 Error Type*/ /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "Unused Error ID kept for design" */
#define MARS_ERROR_L1_GPIO_TE       (12UL << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars GPIO_TE Level 1 Error Type*/
#define MARS_ERROR_L1_MEM           (13UL << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars Memory Level 1 Error Type*/
#define MARS_ERROR_L1_MLBX          (14UL << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars Mailbox Level 1 Error Type*/
#define MARS_ERROR_L1_MEM_RAW       (15UL << MARS_ERROR_L1_BIT_OFFSET)     /*!< Mars Memory RAW middle layer Level 1 Error Type*/

/**********************************************************************************************************************
 * MARS ERROR IDs LEVEL 1
 *********************************************************************************************************************/
#define MARS_L1_E_NOT_OK                    (1U  << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 1] Generic error */
#define MARS_L1_E_NOT_OK_MISMATCH           (2U  << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 2] Register Read back verification failed */
#define MARS_L1_E_NOT_OK_PARAM              (3U  << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 3] Parameter verification failed */
#define MARS_L1_E_MLBX_TIMEOUT_ERROR        (4U  << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 4] Mailbox Timeout Error */
#define MARS_L1_E_MLBX_UNEXPECTED_RESP      (5U  << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 5] Mailbox response is active but not valid reception */
#define MARS_L1_E_MLBX_INVALID_SLOT         (6U  << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 6] Mailbox response slot invalid state */
#define MARS_L1_E_MLBX_RESPONSE_PARITY_ERROR   (7U  << MARS_ERROR_ID_BIT_OFFSET) /*!< [value 7] Mailbox response parity error */
#define MARS_L1_E_MLBX_BUSY_ERROR           (8U  << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 8] Mailbox stuck in busy state, timeout expired */
#define MARS_L1_E_MEM_WRITE_MISMATCH        (9U  << MARS_ERROR_ID_BIT_OFFSET)    /*!< [value 9] Memory Block Read back verification failed */
#define MARS_L1_E_REG_BLACKLISTED           (10U  << MARS_ERROR_ID_BIT_OFFSET)   /*!< [value 10] Attempt to access a register that may cause system error */
#define MARS_L1_E_REG_INVALID_SIZE          (11U  << MARS_ERROR_ID_BIT_OFFSET)   /*!< [value 11] Attempt to write a value bigger than the width of the register field */
#define MARS_L1_E_MLBX_REQUEST_PARITY_ERROR (12U  << MARS_ERROR_ID_BIT_OFFSET)   /*!< [value 12] Mailbox request parity error */
#define MARS_L1_E_MEM_WRITE_MISMATCH_MLBX   (13U  << MARS_ERROR_ID_BIT_OFFSET)   /*!< [value 13] Memory write mailbox CRC verification failed */
#endif /* MARS_L1_ERROR_H */
