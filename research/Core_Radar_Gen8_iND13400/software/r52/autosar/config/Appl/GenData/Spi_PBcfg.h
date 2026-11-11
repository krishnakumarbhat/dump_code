/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/** 
 * @Spi Post-build Cfg header
 *
 * @file     Spi_PBcfg.h
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
 * @SPI Spi Post-build configuration header file
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

#ifndef SPI_PBCFG_H_
#define SPI_PBCFG_H_

/*===========================================================================*
 * Header Files
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{ /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */ 

/*===========================================================================*
* Exported Preprocessor #define Constants
*===========================================================================*/

/**
 * @name Data buffer sizes
 */
/** @{ */

#define     BufferSizeIB1      0U      /**< Number of data buffers for IB Channel */
#define     BufferSizeIB0      2U      /**< Number of data buffers for IB Channel */

#define     LengthEB1          400U      /**< Number of data elements for EB Channel */
#define     LengthEB0          0U      /**< Number of data elements for EB Channel */
/** @} */

/*===========================================================================*
* Exported Preprocessor functions MACROS
*===========================================================================*/
 
/*===========================================================================*
* Exported Type Declarations
*===========================================================================*/

/** 
 * @struct Spi_ChannelConfig
 * @requirements SWS_Spi_00063
 * @brief Contain the the definition for each Channel.
 */
typedef struct
{
    VAR(uint8, TYPEDEF)                                                 SpiDataWidth;       /**< Data width (1 up to 32 bits) */
    VAR(uint16, TYPEDEF)                                                SpiSizeIB;          /**< Number of data buffers for IB Channels */
    VAR(uint16, TYPEDEF)                                                SpiLengthEB;        /**< Number of data elements for EB Channels */
    VAR(Spi_ChannelType, TYPEDEF)                                       SpiChannelId;       /**< Channel ID */
    VAR(Spi_BufferType, TYPEDEF)                                        SpiBufType;     /**< Buffer usage with EB/IB Channel */
    VAR(uint32, TYPEDEF)                                                SpiDefaultData;     /**< Default transmit value */
    VAR(Spi_TransferStart_en, TYPEDEF)                                     SpiTransferStart;   /**< Defines the first starting bit for transmission */
    P2VAR(void, TYPEDEF, SPI_APPL_DATA) __attribute__((aligned(4)))		SpiTXBufferIB;      /**< Transmit buffer for channel (IB) */
    P2VAR(void, TYPEDEF, SPI_APPL_DATA)					                SpiRXBufferIB;      /**< Receive buffer for channel (IB) */
}  Spi_ChannelConfig;

/** 
 * @struct Spi_JobConfig
 * @requirements SWS_Spi_00009
 * @brief Contain the the definition for each Job.
 */
typedef struct
{
    VAR(uint8, TYPEDEF) 				                        SpiHWDeviceID;          /**< SPI Hardware Device ID */
    VAR(uint8, TYPEDEF)   			                            SpiJobPriority;         /**< Priority (0 <lower> - 3 <higher>) */
    VAR(uint8, TYPEDEF)				                            SpiChannelsIncluded;    /**< Number of channels related to this job */
    VAR(Spi_JobType, TYPEDEF)			                        SpiJobId;               /**< Job ID */
    VAR(Spi_OperationMode_en, TYPEDEF)	                        SpiOperationMode;       /**< Standard SPI Mode or Enhanced SPI Mode (QSPI) */
    VAR(Spi_AddressLength_en, TYPEDEF)	                        SpiAddressLength;       /**< Address length in QSPI mode */
    P2VAR(Spi_ChannelType, TYPEDEF, SPI_APPL_DATA)              SpiChannelList;         /**< List of channels related to this job */
    P2FUNC(void, SPI_APPL_CODE, SpiJobEndNotification)(void);                           /**< Job end notification function */
} Spi_JobConfig;

/** 
 * @struct Spi_SequenceConfig
 * @requirements SWS_Spi_00064
 * @brief Contain the the definition for each Sequence.
 */
typedef struct
{
    VAR(uint8, TYPEDEF)				                            SpiJobsIncluded;            /**< Number of jobs related to this sequence */
    VAR(boolean, TYPEDEF)				                        SpiInterruptibleSequence;   /**< Sequence interruptible or not interruptible */
    VAR(Spi_SequenceType, TYPEDEF)  	                        SpiSequenceId;              /**< Sequence ID */
    P2VAR(Spi_JobType, TYPEDEF, SPI_APPL_DATA)                  SpiJobList;                 /**< List of jobs related to this sequence */
    P2FUNC(void, SPI_APPL_CODE, SpiSeqEndNotification)(void);	                            /**< Sequence end notification function */
} Spi_SequenceConfig;

/** 
 * @struct Spi_HWDeviceStruct
 * @requirements SWS_Spi_00010
 * @brief Contain the the definition for each SPI hardware unit.
 */
typedef struct
{
    VAR(uint32, TYPEDEF)				    SpiBaudRate;                    /**< Transfer Speed */
    VAR(uint32, TYPEDEF)				    SpiTimeClk2Cs;                  /**< Timing between clock and chip select (in seconds) */
    VAR(uint8, TYPEDEF)				        SpiHWDeviceID;                 	/**< SPI Hardware Device ID */
    VAR(uint8, TYPEDEF) 		            SpiRxDelay;                	    /**< Receive Sample Delay */
    VAR(boolean, TYPEDEF)				    SpiEnableCs;                    /**< This parameter enables or not the Chip Select handling functions */
    VAR(Spi_HwUnit_en, TYPEDEF)			    SpiHwUnit;                      /**< Symbolic name to identify the HW SPI Hardware */
    VAR(Spi_DrvModel_en, TYPEDEF)			SpiDrvModel;                    /**< Operating model of the SPI device (Master or Slave) */
    VAR(Spi_Polarity, TYPEDEF) 		        SpiCsPolarity;                  /**< Cs polarity (low or high) */
    VAR(Spi_Polarity, TYPEDEF) 		        SpiClkPolarity;                	/**< Clk polarity (low or high) */
    VAR(Spi_CsSelection_en, TYPEDEF)		SpiCsSelection;                 /**< CS is handled automatically by HW or via GPIO */
    VAR(Spi_DataShiftEdge_en, TYPEDEF)	    SpiDataShiftEdge;               /**< Data shift with leading or trailing edge */
    P2VAR(char, TYPEDEF, SPI_APPL_DATA)     SpiCsIdentifier;                /**< Symbolic Name to identify the Chip Select (CS) */
}  Spi_HWDeviceStruct;

/** 
 * @struct Spi_ConfigType
 * @requirements SWS_Spi_00372
 * @brief        Contain the initialization data for the SPI Handler/Driver.
 */
typedef struct
{
    VAR(Spi_ChannelType, TYPEDEF)     SpiNumChannels;         /**< Number of channels */
    VAR(Spi_JobType, TYPEDEF)         SpiNumJobs;             /**< Number of jobs */
    VAR(Spi_SequenceType, TYPEDEF)    SpiNumSequences;        /**< Number of sequences */
    VAR(Spi_HWUnitType, TYPEDEF)      SpiHWUnits;             /**< Number of hardware units */

    P2CONST(Spi_ChannelConfig,  TYPEDEF, SPI_APPL_CONST) SpiChannels;       /**< SPI Channels */
    P2CONST(Spi_JobConfig,      TYPEDEF, SPI_APPL_CONST) SpiJobs;           /**< SPI Jobs */
    P2CONST(Spi_SequenceConfig, TYPEDEF, SPI_APPL_CONST) SpiSequences;      /**< SPI Sequences */
    P2CONST(Spi_HWDeviceStruct, TYPEDEF, SPI_APPL_CONST) SpiHWDeviceList;   /**< SPI Hardware Device List */
} Spi_ConfigType;

/*===========================================================================*
* Exported Const Object Declarations
*===========================================================================*/
extern CONST(Spi_ConfigType, SPI_CONST) Spi_Config;

/*===========================================================================*
* Exported Function Prototypes
*===========================================================================*/

/*===========================================================================*
* Exported Inline Function Definitions and #define Function-Like Macros
*===========================================================================*/


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* SPI_PBCFG_H_*/
 
