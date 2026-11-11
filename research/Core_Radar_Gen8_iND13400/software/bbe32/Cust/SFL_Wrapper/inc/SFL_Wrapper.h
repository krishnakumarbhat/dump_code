#ifndef SFL_ADAPTER_H
#define SFL_ADAPTER_H

/**************************************************************************************************\
* File: SFL_Adapter.cpp
***************************************************************************************************
* Copyright 2024 Aptiv, Inc., All Rights Reserved.
* Aptiv Confidential
*-------------------------------------------------------------------------------------------------
* Created on: feb 11, 2026
* Author: Hari Kailash M M (3dm38i)
*-------------------------------------------------------------------------------------------------
*
* Description:
* Embedded Adapter for SFL features for RNA SRR7p customer.
*
\**************************************************************************************************/

/**************************************************************************************************\
* Standard Header Includes
\**************************************************************************************************/

/**************************************************************************************************\
* Project Header Includes
\**************************************************************************************************/
#if defined(SFL_ADAPTER_USED_MEM_POOL)
   #include "helpers/mem_pool.h"
#endif

/**************************************************************************************************\
* Global Preprocessor Constants
\**************************************************************************************************/

#define SFL_EXECUTION_TIME (0.05f)

/**************************************************************************************************\
* Extern Type Declaration
\**************************************************************************************************/
#define SFL_Faulty_Sts (4U)

typedef enum
{
   SFL_MOIS_disable = (0U),
   SFL_MOIS_enable  = (1U),
} SFL_MOIS_enable_disable_sts_T;

typedef enum
{
   SFL_Ignition_Off = (0U),
   SFL_Ignition_On  = (1U),
} SFL_Ignition_Status_T;

typedef enum
{
   SFL_System_Fail_Not_Present = (0U),
   SFL_System_Fail_Present     = (1U),
} SFL_Fail_Status_T;

typedef enum
{
   SFL_System_Not_Blind = (0U),
   SFL_System_Blind     = (1U),
} SFL_Blind_Status_T;

typedef enum SFL_Blockage_Value_Tag
{
   SFL_BLOCKAGE_VALUE_NOT_BLOCKED        = 0,
   SFL_BLOCKAGE_VALUE_SLIGHTLY_BLOCKED   = 1,
   SFL_BLOCKAGE_VALUE_MODERATELY_BLOCKED = 2,
   SFL_BLOCKAGE_VALUE_HIGHLY_BLOCKED     = 3,
   SFL_BLOCKAGE_VALUE_FULLY_BLOCKED      = 4,
   SFL_BLOCKAGE_VALUE_LIMITED_SIGHT      = 254,
   SFL_BLOCKAGE_VALUE_INVALID            = 255,
} SFL_Blockage_Value_T;

typedef enum SFL_Blockage_Status_Tag
{
   SFL_BLOCKAGE_STATUS_FAULTY         = 0,
   SFL_BLOCKAGE_STATUS_OK             = 1,
   SFL_BLOCKAGE_STATUS_RESERVED       = 2,
   SFL_BLOCKAGE_STATUS_INITIALIZATION = 3,
   SFL_BLOCKAGE_STATUS_INVALID        = 255,
} SFL_Blockage_Status_T;
/**************************************************************************************************\
* Global Function Prototypes
\**************************************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

#if defined(SFL_ADAPTER_USED_MEM_POOL)
   bool Feature_Handler_SFL_Adapter_Memory_Init(Mem_Pool_T *mem_pool);
#endif
   void Feature_Function_Init(void);
   void Feature_Function_Run_50ms(void);

#ifdef __cplusplus
}
#endif

/*================================================================================================*\
* Revision History
*================================================================================================
*    Date          By                     Description
* MM/DD/YYYY  Name/Initials            JIRA AAA-#### Explanation of changes
* ----------  -------------            ----------------------------------------------------------
* 11/02/2026  Hari Kailash M M
\*================================================================================================*/
#endif /* SFL_ADAPTER_H */
