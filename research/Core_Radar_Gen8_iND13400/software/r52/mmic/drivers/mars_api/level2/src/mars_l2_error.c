/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_l2_error.h"


/**
* @brief         registers L2 error information
* @param [in]    instance_id denotes the Mars instance
* @param [in]    error_l2 defines the error type
* @param [in]    error_id denotes the error ID withing a given error type
* @param [in]    flags error status flags
* @param [inout] ret_val_ptr points to the error return value of the caller function to be updated
* @return        None
* @design        GID-347220 GID-347223 GID-347218
*/

void mars_set_l2_error_information(Mars_ReturnType *const ret_val_ptr, const uint32 instance_id, const uint32 flags, const uint32 error_l2, const uint32 error_id) /* polyspace GUIDELINE:SC04 [No action planned:Medium] "The function provides the error return structure for all errors originating from Layer 2." */ /* polyspace GUIDELINE:SC21 [No action planned:Medium] "The function provides the error return structure for all errors originating from Layer 2." */
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if(NULL_PTR != ret_val_ptr) /* polyspace RTE:UNR [No action Planned:Low] "Null pointer check for unit level testability" */
    {
        ret_val = *ret_val_ptr;

        if (MARS_NO_DATA != error_id)
        {
            /* ensure that return value is cleared to 0 any time we write a new ERROR ID. since based on this ERROR ID, the code will add extra information when propagating to upper layers */
            ret_val = (ret_val & 0u) | (error_id);
        }
        if (MARS_NO_DATA != flags) 
        {/* polyspace RTE:UNR [No action Planned:Low] "No flag set currently not used" */
            ret_val = (ret_val & ~((uint32)MARS_FLAGS_BIT_MASK << MARS_FLAGS_BIT_OFFSET)) | (flags);
        }
        if (MARS_NO_DATA != error_l2) /* polyspace RTE:UNR [No action Planned:Low] "Case no data for for L2 error type" */
        {
            ret_val = (ret_val & ~((uint32)MARS_ERROR_L2_BIT_MASK << MARS_ERROR_L2_BIT_OFFSET)) | (error_l2);
        }

        *ret_val_ptr = ret_val;

        // mars_error_hook(ret_val, instance_id);
    }
}
