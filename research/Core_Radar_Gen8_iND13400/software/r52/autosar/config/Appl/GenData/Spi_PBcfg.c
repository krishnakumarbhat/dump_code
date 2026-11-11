/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/** 
 * @Spi Post-build Cfg source
 *
 * @file 	 Spi_PBcfg.c
 * @Date     Generation Time:   2026-08-26 22:51:47
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
 * @SPI SPI MCAL Post-build configuration source file
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Specification of SPI Driver AUTOSAR CP Release 4.4.0
 *
 *   - Requirements Document(s):
 *     - @Specification of SPI Driver AUTOSAR CP Release 4.4.0
 *
 *   - Applicable Standards:
 *     - @Autosar Classic Platform 4.4.0
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 * @section Maybe Changed By the User: NO
 */
/*===========================================================================*/
/*===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/

#include "Spi_GeneralTypes.h"
#include "Spi_Cfg.h"            /* polyspace DEFECT:USELESS_INCLUDE "It is used by the module" */
#include "Spi_PBcfg.h"
#include "Spi_Externals.h"      /* polyspace DEFECT:USELESS_INCLUDE "It is used by the module" */

/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/
 
/*===========================================================================*
 * Local Preprocessor defined MACROS
 *===========================================================================*/

/**
 * @name Current configuration
 */
/** @{ */
#define NumberOfChannels    2U
#define NumberOfJobs        1U
#define NumberOfSequences   1U
#define NumberOfHWUnits     1U


#define NumChanJob0 		1U

#define NumJobsSeq0 		1U
/** @} */

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
* Exported Function Prototypes
*===========================================================================*/

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
 
/**
 * @def             SPI_START_SEC_CONFIG_DATA_POSTBUILD
 * @brief           Start of MemMap section
 */
#define SPI_START_SEC_CONFIG_DATA_POSTBUILD
#include "Spi_MemMap.h" /* polyspace MISRA-C-2023:20.1 "AUTOSAR Memory Mapping." */

/**
 * @name Internal buffers info
 */
/** @{ */
STATIC VAR(uint16, SPI_VAR_CLEARED) __attribute__ ((aligned(4)))  BufferTxChannel1[LengthEB1];			/* Transmit (EB) buffer for storing default transmit values */ /* polyspace MISRA-C-2023:8.15 " Single internal definition with explicit alignment " */
STATIC VAR(uint16, SPI_VAR_CLEARED) __attribute__ ((aligned(4)))  BufferTxChannel0[BufferSizeIB0];		/* Transmit (IB) buffer for channel 0*/ /* polyspace MISRA-C-2023:8.15 " Single internal definition with explicit alignment " */
STATIC VAR(uint16, SPI_VAR_CLEARED) __attribute__ ((aligned(4)))  BufferRxChannel0[BufferSizeIB0];		/* Receive (IB) buffer for channel 0*/ /* polyspace MISRA-C-2023:8.15 " Single internal definition with explicit alignment " */
/** @} */

STATIC CONST(Spi_ChannelConfig, SPI_CONST) SpiAvailableChannels[NumberOfChannels] =    /* Array of channels for SPI operation */
{
    {
        .SpiChannelId = 1U,					/* Channel ID */
        .SpiDataWidth = 16U,				/* Data width (1 up to 32 bits) */
        .SpiDefaultData =   0x0,			/* Default transmit value */
        .SpiBufType = SPI_EB,			/* Buffer usage with EB/IB Channel */
        .SpiTransferStart = SPI_MSB,		/* Defines the first starting bit for transmission */
        .SpiLengthEB = LengthEB1,			/* Number of data elements for EB Channels */
        .SpiSizeIB =  BufferSizeIB1,		/* Number of data buffers for IB Channels  */
        .SpiTXBufferIB = BufferTxChannel1, 	/* Transmit (IB) buffer for storing default transmit values */
        .SpiRXBufferIB = NULL_PTR 			/* Receive buffer for channel (IB) */
    },
    {
        .SpiChannelId = 0U,					/* Channel ID */
        .SpiDataWidth = 16U,				/* Data width (1 up to 32 bits) */
        .SpiDefaultData =   0x0,			/* Default transmit value */
        .SpiBufType = SPI_IB,			/* Buffer usage with EB/IB Channel */
        .SpiTransferStart = SPI_MSB,		/* Defines the first starting bit for transmission */
        .SpiLengthEB = LengthEB0,			/* Number of data elements for EB Channels */
        .SpiSizeIB =  BufferSizeIB0,		/* Number of data buffers for IB Channels  */
        .SpiTXBufferIB = BufferTxChannel0, 	/* Transmit buffer for channel (IB) */
        .SpiRXBufferIB = BufferRxChannel0 	/* Receive buffer for channel (IB) */
    },
};


STATIC VAR(Spi_ChannelType, SPI_VAR_CLEARED) 	Job0_Channels[NumChanJob0] = {0U, };	/* Set of channels for transmission in job 0*/


STATIC CONST(Spi_JobConfig, SPI_CONST) SpiAvailableJobs[NumberOfJobs] =
{
    {
        .SpiJobId = 0U,			/* Job ID */
        .SpiHWDeviceID = 0U,			/* SPI HW device ID */
        .SpiJobPriority = 1U,			/* Priority (0 <lower> - 3 <higher>) */
        .SpiChannelsIncluded = NumChanJob0,			/* Number of channels related to this job */
        .SpiOperationMode = SPI_Mode,			/* Standard SPI Mode or Enhanced SPI Mode (QSPI) */
        .SpiAddressLength = SPI_ADDR_LEN_NOT_USED,
        .SpiChannelList = Job0_Channels,			/* List of channels related to this job */
        .SpiJobEndNotification = NULL			/* Job end notification function */
    },
};

STATIC VAR(Spi_JobType, SPI_VAR_CLEARED)	Seq0_Jobs[NumJobsSeq0] = {0U, };		/* Set of jobs for transmission in sequence 0*/

STATIC CONST(Spi_SequenceConfig, SPI_CONST)  SpiAvailableSequences[NumberOfSequences] = /* Array of sequences for SPI operation */
{
    {
        .SpiSequenceId = 0U,			/* Sequence ID */
        .SpiJobList = Seq0_Jobs,			/* List of jobs related to this channel */
        .SpiJobsIncluded = NumJobsSeq0,			/* Number of jobs related to this sequence */
        .SpiSeqEndNotification = NULL,			/* Sequence end notification function */
        .SpiInterruptibleSequence = TRUE,			/* Sequence interruptible or not interruptible */
    },
};

STATIC CONST(Spi_HWDeviceStruct, SPI_CONST) SpiHWDevices[NumberOfHWUnits] =        /* Array of device settings for SPI operation */
{
    {
        .SpiHWDeviceID = 0U,
        .SpiHwUnit = CSIB0,                         /* Symbolic name to identify the HW SPI Hardware */
        .SpiDrvModel = SPI_MASTER,               /* Operating model of the SPI device (Master or Slave) */
        .SpiBaudRate = 50000000U,                      /* Transfer Speed */
        .SpiRxDelay = 0U,                           /* Receive Sample Delay */
        .SpiCsIdentifier = NULL_PTR,                /* Symbolic Name to identify the Chip Select (CS) */
        .SpiCsSelection = CS_VIA_PERIPHERAL_ENGINE, /* CS is handled automatically by HW or via GPIO */
        .SpiCsPolarity = LOW,                      /* Cs polarity (low or high) */
        .SpiClkPolarity = LOW,                      /* Clk polarity (low or high) */
        .SpiDataShiftEdge = LEADING,                /* Data shift with leading or trailing edge */
        .SpiEnableCs = FALSE,                       /* This parameter enables or not the Chip Select handling functions */
        .SpiTimeClk2Cs = 0                         /* Timing between clock and chip select (in seconds) */
    },
};
 
CONST(Spi_ConfigType, SPI_CONST) Spi_Config =
{
    .SpiNumChannels = NumberOfChannels,         /* Number of channels */
    .SpiNumJobs = NumberOfJobs,                 /* Number of jobs */
    .SpiNumSequences = NumberOfSequences,       /* Number of sequences */
    .SpiHWUnits = NumberOfHWUnits,              /* Number of hardware units */
    .SpiChannels = SpiAvailableChannels,        /* Channels */
    .SpiJobs = SpiAvailableJobs,                /* Jobs */
    .SpiSequences = SpiAvailableSequences,      /* SPI Sequences */
    .SpiHWDeviceList = SpiHWDevices         	/* SPI External Devices */
};

/**
 * @def             SPI_STOP_SEC_CONFIG_DATA_POSTBUILD
 * @brief           Stop of MemMap section
 */
#define SPI_STOP_SEC_CONFIG_DATA_POSTBUILD
#include "Spi_MemMap.h" /* polyspace DEFECT:USELESS_INCLUDE "AUTOSAR Memory Mapping." *//* polyspace MISRA-C-2023:20.1 "AUTOSAR Memory Mapping." */

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

 
