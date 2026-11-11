/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/**
 * @I2c Post-build Cfg source
 *
 * @file 	 I2c_PBcfg.c
 * @Date     Generation Time:   2026-09-02 19:34:10
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
 * @Microcontroller I2c Post-build configuration source file
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

#include "I2c_PBcfg.h"

#define I2C_START_SEC_CONFIG_DATA_POSTBUILD
#include "I2c_MemMap.h"

const I2c_ConfigType I2c_Config =
{
    .DataBaudrate = I2C_BUS_SPEED_FAST,
    .SlaveConfig = 
    {
        .AcceptGeneralCall = FALSE,  
        .AddressSlave = 0x00000069u,
        .TenBitsAddress = FALSE
    },
    .I2C_JobEndNotification = Pmic_I2c_JobEndNotification
};

#define I2C_STOP_SEC_CONFIG_DATA_POSTBUILD     
#include"I2c_MemMap.h"   /* polyspace DEFECT:USELESS_INCLUDE "Needed for AUTOSAR Memory Mapping  " */  /* polyspace MISRA-C-2023:20.1"Needed for AUTOSAR Memory Mapping" */


