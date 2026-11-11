/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_l1_error.h"


/**
* @brief         registers L1 error information
* @param [in]    instance_id denotes the Mars instance
* @param [in]    error_l1 defines the error type
* @param [in]    error_id denotes the error ID withing a given error type
* @param [inout] ret_val_ptr points to the error return value of the caller function to be updated
* @return        None
* @design        GID-344805 GID-344807 GID-344810
*/
void mars_set_l1_error_information(Mars_ReturnType *const ret_val_ptr, const uint32 instance_id, const uint32 error_l1, const uint32 error_id) /* polyspace GUIDELINE:SC04 [No action planned:Medium] "The function provides the error return structure for all errors originating from Layer 1." */
{

    if(NULL_PTR != ret_val_ptr) /* polyspace RTE:UNR [Not a defect:Low] "Null pointer check for unit level testability" */
    {

        if (0 != error_id)
        {
            /* ensure that return value is cleared to 0 any time we write a new ERROR ID. since based on this ERROR ID, the code will add extra information when propagating to upper layers*/
            *ret_val_ptr = ((*ret_val_ptr) & 0u) | (error_id);
        }
        if (0 != error_l1) /* polyspace RTE:UNR [Not a defect:Low] "Case no data for for L1 error type" */
        {
            *ret_val_ptr = ((*ret_val_ptr) & ~((uint32)MARS_ERROR_L1_BIT_MASK << (uint8)MARS_ERROR_L1_BIT_OFFSET)) | (error_l1);
        }

        /*Sandeep: Not needed since we have our own decoding mechanism*/
        // mars_error_hook((*ret_val_ptr), instance_id);
    }
}
