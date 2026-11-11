/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/** 
 * @Dma PBCfg source
 *
 * @file 	 Dma_PBCfg.c
 * @Date     Generation Time:   2026-08-26 20:55:48
 * @Project  Project:   Gen8_iND13400 - Version 1.0
 * 
 *------------------------------------------------------------------------------
 *
 * Copyright (c) indie Semiconductor 2025. All rights reserved.
 *
 * Information within this file is indie Semiconductor confidential and proprietary. 
 * 
 *------------------------------------------------------------------------------
 *
 * @section FULL DESCRIPTION:
 *
 * @DMA Dma Post Build configuration source file
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - 
 *
 *   - Requirements Document(s):
 *     -
 *
 *   - Applicable Standards:
 *     -
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Dma_PBcfg.h"

/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/

/*===========================================================================*
* Exported Function Prototypes
*===========================================================================*/

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
#define DMA_START_SEC_CONFIG_DATA_POSTBUILD
#include "Dma_MemMap.h"

static const Dma_strChConfigType DmaChannelCfg[CHANNEL_CONFIGURED_NUM_MAX] = {

    {               
    .en_DmaChannelId        =  CHANNEL_ID_1,
	.en_DmaChannelPirority  =  CH_PRIORITY_3,
    .str_DmaChannelCfg      =
        {
        	.en_SrcBurstsize     = DMA_ITEM_NUM_16,
        	.en_DstBurstsize     = DMA_ITEM_NUM_16,
        	.en_SrcDataWidth     = DMA_TR_WIDTH_32,               
    		.en_DstDataWidth     = DMA_TR_WIDTH_32,
    		.ArlenEn          	 = STD_ON,
    		.Arlen            	 = 7,
    		.AwlenEn          	 = STD_ON,
    		.Awlen            	 = 7,
    		.en_SrcMultiBlockTranferType = DMA_MULTBLK_CONTIGUOUS,
    		.en_DstMultiBlockTranferType = DMA_MULTBLK_CONTIGUOUS,
 			.ChannelEndNotification      = Channel1_EndNotification,
    	}
    },
    
};

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
 
const Dma_ConfigType Dma_Config = {
    .pstr_DmaChannel           =    &DmaChannelCfg[0],
    .DmaNumberOfChannels       =    CHANNEL_CONFIGURED_NUM_MAX,
};

#define DMA_STOP_SEC_CONFIG_DATA_POSTBUILD
#include "Dma_MemMap.h"		/* polyspace DEFECT:USELESS_INCLUDE [Justified:Low] "AUTOSAR Memory Mapping" */
/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/*===========================================================================*
 *  Local Function Definitions
 *===========================================================================*/

