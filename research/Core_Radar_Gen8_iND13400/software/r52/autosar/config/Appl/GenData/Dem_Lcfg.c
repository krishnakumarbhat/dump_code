/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Dem
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dem_Lcfg.c
 *   Generation Time: 2026-08-12 18:54:44
 *           Project: Gen8_iND13400 - Version 1.0
 *          Delivery: PAI19494
 *      Tool Version: DaVinci Configurator Classic (beta) 5.31.55 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/


/* configuration, interrupt handling implementations differ from the
 * source identification define used here. The naming
 * schemes for those files can be taken from this list:
 *
 * Dem.c:         DEM_SOURCE
 * Dem_Lcfg.c:    DEM_LCFG_SOURCE
 * Dem_PBcfg.c:   DEM_PBCFG_SOURCE */
#define DEM_LCFG_SOURCE


/**********************************************************************************************************************
  MISRA JUSTIFICATIONS
**********************************************************************************************************************/

/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */                                      /* Maximum '#if...' nesting exceeds 8 levels - program is non-conforming -- caused by #include'd files. */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */                                      /* Number of macro definitions exceeds 1024 - program is non-conforming -- caused by #include'd files. */
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */                                          /* Identifier does not differ in 32 significant characters -- caused by Autosar algorithm for unique symbolic names. */
/* PRQA S 0612 EOF */ /* MD_DEM_1.1_612 */                                      /* The size of an object exceeds 32767 bytes - program is non-conforming -- caused by large user configuration. */
/* PRQA S 0613 EOF */ /* MD_DEM_613 */                                          /* The size of an object exceeds 65535 bytes - program is non-conforming -- caused by large user configuration. */


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

#include "Dem.h"
#include "Os.h"
#if (DEM_CFG_USE_NVM == STD_ON)
# include "NvM.h"                                                               /* get: symbolic names for NvM block IDs */
#endif
#if (DEM_CFG_SUPPORT_J1939 == STD_ON)
# include "J1939Nm.h"                                                           /* get: symbolic names for J1939Nm node IDs */
#endif
#if (DEM_CFG_USE_RTE == STD_ON)
/* DEM used with RTE */
# include "Rte_DemMaster_Invalid_OsApplication.h"
#endif
#include "Dem_AdditionalIncludeCfg.h"                                           /* additional, configuration defined files */

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/



/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Dem_Cfg_CallbackDtcStatusChanged
**********************************************************************************************************************/
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_DtcStatusChangedFPtrType, DEM_CONST) Dem_Cfg_CallbackDtcStatusChanged[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CallbackDtcStatusChanged                                           */
  /*     0 */ Rte_Call_CBStatusDTC_DemCallbackDTCStatusChanged_DTCStatusChanged 
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataCollectionTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataCollectionTable
  \details
  Element                                                           Description
  IdNumber                                                      
  CollectionSize                                                
  DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd
  DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd
  StorageKind                                                   
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataCollectionTableType, DEM_CONST) Dem_Cfg_DataCollectionTable[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IdNumber  CollectionSize  DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndEndIdx                                  DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndStartIdx                                  StorageKind                       Referable Keys */
  { /*     0 */  0x0000u,             0u, DEM_CFG_NO_DATAELEMENTTABLECOL2ELMTINDDATAELEMENTTABLECOL2ELMTINDENDIDXOFDATACOLLECTIONTABLE, DEM_CFG_NO_DATAELEMENTTABLECOL2ELMTINDDATAELEMENTTABLECOL2ELMTINDSTARTIDXOFDATACOLLECTIONTABLE, DEM_CFG_EREC_TYPE_GLOBAL   },  /* [#NoDataCollectionConfigured] */
  { /*     1 */  0x0002u,             1u,                                                                                           1u,                                                                                             0u, DEM_CFG_EREC_TYPE_INTERNAL },  /* [#EdrExtendedDataRecord_AgingCounter, Ext:ExtendedDataClass_6d15841fTO#EdrExtendedDataRecord_AgingCounter, #ExtendedDataRecord] */
  { /*     2 */  0x0001u,             1u,                                                                                           2u,                                                                                             1u, DEM_CFG_EREC_TYPE_INTERNAL },  /* [#EdrExtendedDataRecord_OccurrenceCounter, Ext:ExtendedDataClass_6d15841fTO#EdrExtendedDataRecord_OccurrenceCounter, #ExtendedDataRecord] */
  { /*     3 */  0x1116u,             7u,                                                                                           3u,                                                                                             2u, DEM_CFG_EREC_TYPE_USER     },  /* [#DidDID_DateandTime_Read_0x1116, Ffm:FreezeFrame_d41460f8TO#DidDID_DateandTime_Read_0x1116] */
  { /*     4 */  0x1111u,             2u,                                                                                           4u,                                                                                             3u, DEM_CFG_EREC_TYPE_USER     },  /* [#DidDID_ECUVoltage_Read_0x1111, Ffm:FreezeFrame_d41460f8TO#DidDID_ECUVoltage_Read_0x1111] */
  { /*     5 */  0xA004u,             1u,                                                                                           5u,                                                                                             4u, DEM_CFG_EREC_TYPE_USER     },  /* [#DidDID_Ego_Acceleration_Read_0xa004, Ffm:FreezeFrame_d41460f8TO#DidDID_Ego_Acceleration_Read_0xa004] */
  { /*     6 */  0x1117u,             1u,                                                                                           6u,                                                                                             5u, DEM_CFG_EREC_TYPE_USER     },  /* [#DidDID_Sensor_Availability_Flag_Read_0x1117, Ffm:FreezeFrame_d41460f8TO#DidDID_Sensor_Availability_Flag_Read_0x1117] */
  { /*     7 */  0x1112u,             2u,                                                                                           7u,                                                                                             6u, DEM_CFG_EREC_TYPE_USER     }   /* [#DidDID_VehicleSpeed_Read_0x1112, Ffm:FreezeFrame_d41460f8TO#DidDID_VehicleSpeed_Read_0x1112] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd
  \brief  the index of the 1:1 relation pointing to Dem_Cfg_DataCollectionTable
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollIndType, DEM_CONST) Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     DataCollectionTableIdxOfDataCollectionTableEdr2CollInd  */
  /*     0 */                                                      2u,
  /*     1 */                                                      1u
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd
  \brief  the index of the 1:1 relation pointing to Dem_Cfg_DataCollectionTable
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollIndType, DEM_CONST) Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     DataCollectionTableIdxOfDataCollectionTableFfm2CollInd  */
  /*     0 */                                                      4u,
  /*     1 */                                                      7u,
  /*     2 */                                                      3u,
  /*     3 */                                                      6u,
  /*     4 */                                                      5u
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataElementTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataElementTable
  \details
  Element            Description
  ElementDataType    DataElement data type, returned by Dem_Cfg_DataElementDataType()
  ElementKind        DataElement kind, returned by Dem_Cfg_DataCallbackType()
  ElementSize        Size of data element in Byte.
  ReadDataFunc       C-function for getting the data. Its signature depends on ElementKind and ElementDataType
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataElementTableType, DEM_CONST) Dem_Cfg_DataElementTable[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ElementDataType            ElementKind                  ElementSize  ReadDataFunc                                                                                                                                         Referable Keys */
  { /*     0 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATAELEMENT_INVALID,          0u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                                          },  /* [#NoDataElementConfigured] */
  { /*     1 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT  ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x1117_Sensor_Availability_Flag_Information_ReadData },  /* [#Data_DID_0x1117_Sensor_Availability_Flag_Information, DidDID_Sensor_Availability_Flag_Read_0x1117TO#Data_DID_0x1117_Sensor_Availability_Flag_Information] */
  { /*     2 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT  ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x1112_VehicleSpeed_ReadData                         },  /* [#Data_DID_0x1112_VehicleSpeed, DidDID_VehicleSpeed_Read_0x1112TO#Data_DID_0x1112_VehicleSpeed] */
  { /*     3 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_AGINGCTR ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                                          },  /* [#Data_AgingCounter_Aging_Counter, EdrExtendedDataRecord_AgingCounterTO#Data_AgingCounter_Aging_Counter] */
  { /*     4 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_OCCCTR   ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                                          },  /* [#Data_OccurrenceCounter_Occurrence_Counter, EdrExtendedDataRecord_OccurrenceCounterTO#Data_OccurrenceCounter_Occurrence_Counter] */
  { /*     5 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT  ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0xa004_Ego_Acceleration_ReadData                     },  /* [#Data_DID_0xa004_Ego_Acceleration, DidDID_Ego_Acceleration_Read_0xa004TO#Data_DID_0xa004_Ego_Acceleration] */
  { /*     6 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT  ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x1111_ECUVoltage_ReadData                           },  /* [#Data_DID_0x1111_ECUVoltage, DidDID_ECUVoltage_Read_0x1111TO#Data_DID_0x1111_ECUVoltage] */
  { /*     7 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT  ,          7u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x1116_CombinedSignal_ReadData                       }   /* [#Data_DID_0x1116_CombinedSignal, DidDID_DateandTime_Read_0x1116TO#Data_DID_0x1116_CombinedSignal] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd
  \brief  the index of the 1:1 relation pointing to Dem_Cfg_DataElementTable
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtIndType, DEM_CONST) Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     DataElementTableIdxOfDataElementTableCol2ElmtInd  */
  /*     0 */                                                3u,
  /*     1 */                                                4u,
  /*     2 */                                                7u,
  /*     3 */                                                6u,
  /*     4 */                                                5u,
  /*     5 */                                                1u,
  /*     6 */                                                2u
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DebounceIndirectionTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DebounceIndirectionTable
  \brief  Table with optional indirections to tables with algorithm specific debouncing parameters. The algorithm used by an event is indicated by the presence or absence of the indirection ids. An event having neither a counter based or time based indirection id indicates monitor internal debouncing, having both is invalid.
  \details
  Element                         Description
  CounterBasedDebounceTableIdx    the index of the 0:1 relation pointing to Dem_Cfg_CounterBasedDebounceTable
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DebounceIndirectionTableType, DEM_CONST) Dem_Cfg_DebounceIndirectionTable[63] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CounterBasedDebounceTableIdx                                             Comment */
  { /*     0 */                                                                0u },  /* [#EVENT_INVALID] */
  { /*     1 */                                                                0u },  /* [ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received] */
  { /*     2 */                                                                0u },  /* [ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received] */
  { /*     3 */                                                                0u },  /* [AT_AMT_ECU_ETC2_03_message_Missing_Message] */
  { /*     4 */                                                                0u },  /* [AT_AMT_ETC2_erratic_communication_Erratic] */
  { /*     5 */                                                                0u },  /* [AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received] */
  { /*     6 */                                                                0u },  /* [Application_Interface_Lookup_Performance_or_Incorrect_Operation] */
  { /*     7 */                                                                0u },  /* [CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received] */
  { /*     8 */                                                                0u },  /* [CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received] */
  { /*     9 */                                                                0u },  /* [Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic] */
  { /*    10 */                                                                0u },  /* [Cluster_ECU_ADAS_FN_STS_message_Missing_Message] */
  { /*    11 */                                                                0u },  /* [Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic] */
  { /*    12 */                                                                0u },  /* [Cluster_ECU_CLS_Tx_4_message_Missing_Message] */
  { /*    13 */                                                                0u },  /* [Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic] */
  { /*    14 */                                                                0u },  /* [Cluster_ECU_CLS_Tx_16_message_Missing_Message] */
  { /*    15 */                                                                0u },  /* [Cluster_ECU_OEL_erratic_communication_Erratic] */
  { /*    16 */                                                                0u },  /* [Cluster_ECU_OEL_message_Missing_Message] */
  { /*    17 */                                                                0u },  /* [Cluster_ECU_TD_erratic_communication_Erratic] */
  { /*    18 */                                                                0u },  /* [Cluster_ECU_TD_message_Missing_Message] */
  { /*    19 */                                                                0u },  /* [ECU_NVM_Corruption_Program_memory_Failure] */
  { /*    20 */                                                                0u },  /* [EMS_ECU_CCVS1_erratic_communication_Erractic] */
  { /*    21 */                                                                0u },  /* [EMS_ECU_CCVS1_message_Missing_Message] */
  { /*    22 */                                                                0u },  /* [EMS_ECU_ETC2_00_message_Missing_Message] */
  { /*    23 */                                                                0u },  /* [EMS_ECU_ETC2_erratic_communication_Erractic] */
  { /*    24 */                                                                0u },  /* [EMS_ECU_VD_erratic_communication_Erratic] */
  { /*    25 */                                                                0u },  /* [EMS_ECU_VD_message_Missing_Message] */
  { /*    26 */                                                                0u },  /* [ESC_ECU_VDC2_erratic_communication_Erratic] */
  { /*    27 */                                                                0u },  /* [ESC_ECU_VDC2_message_Missing_Message] */
  { /*    28 */                                                                0u },  /* [Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure] */
  { /*    29 */                                                                0u },  /* [Front_Left_Side_Radar_Missing_Message] */
  { /*    30 */                                                                0u },  /* [Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect] */
  { /*    31 */                                                                0u },  /* [Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received] */
  { /*    32 */                                                                0u },  /* [OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received] */
  { /*    33 */                                                                0u },  /* [PCAN_Communication_Bus_Off] */
  { /*    34 */                                                                0u },  /* [PCAN_TimeSync_Missing_Message] */
  { /*    35 */                                                                0u },  /* [Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure] */
  { /*    36 */                                                                0u },  /* [Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation] */
  { /*    37 */                                                                0u },  /* [Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect] */
  { /*    38 */                                                                0u },  /* [Radar_Initial_Alignment_Missing_Calibration] */
  { /*    39 */                                                                0u },  /* [Radar_MMIC_Component_Failure] */
  { /*    40 */                                                                0u },  /* [Radar_MMIC_RFBIST_Component_Internal_Failure] */
  { /*    41 */                                                                0u },  /* [Radar_Module_General_Memory_Failure] */
  { /*    42 */                                                                0u },  /* [Radar_Module_Over_Temperature] */
  { /*    43 */                                                                0u },  /* [Radar_Module_System_Internal_Failure] */
  { /*    44 */                                                                0u },  /* [Radar_Module_Watchdog_Failure] */
  { /*    45 */                                                                0u },  /* [Radar_Mounting_Orientation_Incorrect_Assembly] */
  { /*    46 */                                                                0u },  /* [Radar_Performance_Capability_Algorithm_Based_Failure] */
  { /*    47 */                                                                0u },  /* [Radar_Pin_Position_Wrong_Mounting_Position] */
  { /*    48 */                                                                0u },  /* [Radar_Platform_Time_System_Programming_Failure] */
  { /*    49 */                                                                0u },  /* [Radar_SMC_General_Checksum_Failure] */
    /* Index    CounterBasedDebounceTableIdx                                             Comment */
  { /*    50 */                                                                0u },  /* [Radar_System_Battery_High_Voltage_System_Voltage_High] */
  { /*    51 */                                                                0u },  /* [Radar_System_Battery_Low_Voltage_System_Voltage_Low] */
  { /*    52 */                                                                0u },  /* [Radar_calibration_Calibration_or_Paramater_Memory_Failure] */
  { /*    53 */                                                                0u },  /* [SAS_ECU_SAS_message_Missing_Message] */
  { /*    54 */                                                                0u },  /* [SAS_ECU_erratic_communication_Erratic] */
  { /*    55 */                                                                0u },  /* [SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received] */
  { /*    56 */                                                                0u },  /* [VCAN_Communication_Bus_Off] */
  { /*    57 */                                                                0u },  /* [VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received] */
  { /*    58 */                                                                0u },  /* [VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received] */
  { /*    59 */                                                                0u },  /* [VDC2_message_Yaw_rate_Invalid_Serial_Data_Received] */
  { /*    60 */                                                                0u },  /* [Vehicle_DataSet_Not_Configured] */
  { /*    61 */                                                                0u },  /* [Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect] */
  { /*    62 */ DEM_CFG_NO_COUNTERBASEDDEBOUNCETABLEIDXOFDEBOUNCEINDIRECTIONTABLE }   /* [DemEventParameter] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DtcCalibTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DtcCalibTable
  \details
  Element                       Description
  UdsDtc                    
  AgingCycleCounterThreshold    DemAgingCycleCounterThreshold of the DemEventParameter/DemEventClass. If AgingAllowedOfEventTable==FALSE and DemAgingCycleCounterThreshold does not exist '255' is set. If AgingAllowedOfEventTable==TRUE and DemAgingCycleCounterThreshold does not exist '0' is set.
  AgingCycleId                  DemOperationCycle (ID) referenced by DemEventParameter/DemEventClass/DemAgingCycleRef
  DtcPriority                   DemEventParameter/DemEventClass/DemEventPriority, values [1..255] for the configuration range [1..255].
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DtcCalibTableType, DEM_CONST) Dem_Cfg_DtcCalibTable[63] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    UdsDtc     AgingCycleCounterThreshold  AgingCycleId                            DtcPriority        Referable Keys */
  { /*     0 */ 16777215u,                         0u, /*no AgingCycle*/ 1U                  ,          0u },  /* [#NoUdsDtcConfigured, #NoJ1939DtcConfigured] */
  { /*     1 */ 13907585u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD43681] */
  { /*     2 */ 13907841u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD43781] */
  { /*     3 */ 13895559u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD40787] */
  { /*     4 */ 13900175u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD4198F] */
  { /*     5 */ 13906049u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD43081] */
  { /*     6 */  5637266u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x561792_001] */
  { /*     7 */ 13903489u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD42681] */
  { /*     8 */ 13903745u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD42781] */
  { /*     9 */ 13902735u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD4238F] */
  { /*    10 */ 13895815u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD40887] */
  { /*    11 */ 13901967u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD4208F] */
  { /*    12 */ 13897863u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD41087] */
  { /*    13 */ 13902223u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD4218F] */
  { /*    14 */ 13896071u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD40987] */
  { /*    15 */ 13902479u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD4228F] */
  { /*    16 */ 13898119u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD41187] */
  { /*    17 */ 13902991u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD4248F] */
  { /*    18 */ 13898375u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD41287] */
  { /*    19 */  5642565u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x561745] */
  { /*    20 */ 13899151u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD4158F] */
  { /*    21 */ 13894535u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD40387] */
  { /*    22 */ 13894791u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD40487] */
  { /*    23 */ 13899407u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD4168F] */
  { /*    24 */ 13899663u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD4178F] */
  { /*    25 */ 13895047u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD40587] */
  { /*    26 */ 13899919u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD4188F] */
  { /*    27 */ 13895303u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD40687] */
  { /*    28 */ 13910922u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD4438A] */
  { /*    29 */ 13908359u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD43987] */
  { /*    30 */ 13910147u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD44083] */
  { /*    31 */ 13904257u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD42981] */
  { /*    32 */ 13906305u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD43181] */
  { /*    33 */ 13894280u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD40288] */
  { /*    34 */ 13910407u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD44187] */
  { /*    35 */  5639265u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x560C61] */
  { /*    36 */  5640338u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x561092] */
  { /*    37 */  5639032u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x560B78] */
  { /*    38 */  5638740u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x560A54] */
  { /*    39 */  5636617u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x560209] */
  { /*    40 */  5637014u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x561792] */
  { /*    41 */  5637698u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x560642] */
  { /*    42 */ 13893707u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD4004B] */
  { /*    43 */  5636100u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x560004] */
  { /*    44 */  5637959u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x560747] */
  { /*    45 */  5640597u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x561195] */
  { /*    46 */  5636358u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x560106] */
  { /*    47 */  5640054u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x560F76] */
  { /*    48 */  5640965u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x561305] */
  { /*    49 */  5639745u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x560E41] */
    /* Index    UdsDtc     AgingCycleCounterThreshold  AgingCycleId                            DtcPriority        Referable Keys */
  { /*    50 */  5638563u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x5609A3] */
  { /*    51 */  5638306u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x5608A2] */
  { /*    52 */  5639494u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x560D46] */
  { /*    53 */ 13898631u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD41387] */
  { /*    54 */ 13903247u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD4258F] */
  { /*    55 */ 13906561u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD43281] */
  { /*    56 */ 13894024u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD40188] */
  { /*    57 */ 13907073u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD43481] */
  { /*    58 */ 13907329u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD43581] */
  { /*    59 */ 13906817u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0xD43381] */
  { /*    60 */  5641813u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x561655] */
  { /*    61 */  5641603u,                        40u, DemConf_DemOperationCycle_Power_On_Off,          2u },  /* [DTCClass_DtcClass_DTC_0x561583] */
  { /*    62 */  1193046u,                       255u, DemConf_DemOperationCycle_Power_On_Off,          2u }   /* [DemDTCClass] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DtcInvariantDataTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DtcInvariantDataTable
  \details
  Element                     Description
  FreezeFrameTableStdFFIdx    the index of the 1:1 relation pointing to Dem_Cfg_FreezeFrameTable
  FunctionalUnit          
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DtcInvariantDataTableType, DEM_CONST) Dem_Cfg_DtcInvariantDataTable[63] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FreezeFrameTableStdFFIdx  FunctionalUnit        Referable Keys */
  { /*     0 */                       0u,           255u },  /* [#NoUdsDtcConfigured, #NoJ1939DtcConfigured] */
  { /*     1 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD43681] */
  { /*     2 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD43781] */
  { /*     3 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD40787] */
  { /*     4 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD4198F] */
  { /*     5 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD43081] */
  { /*     6 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x561792_001] */
  { /*     7 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD42681] */
  { /*     8 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD42781] */
  { /*     9 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD4238F] */
  { /*    10 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD40887] */
  { /*    11 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD4208F] */
  { /*    12 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD41087] */
  { /*    13 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD4218F] */
  { /*    14 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD40987] */
  { /*    15 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD4228F] */
  { /*    16 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD41187] */
  { /*    17 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD4248F] */
  { /*    18 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD41287] */
  { /*    19 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x561745] */
  { /*    20 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD4158F] */
  { /*    21 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD40387] */
  { /*    22 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD40487] */
  { /*    23 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD4168F] */
  { /*    24 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD4178F] */
  { /*    25 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD40587] */
  { /*    26 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD4188F] */
  { /*    27 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD40687] */
  { /*    28 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD4438A] */
  { /*    29 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD43987] */
  { /*    30 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD44083] */
  { /*    31 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD42981] */
  { /*    32 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD43181] */
  { /*    33 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD40288] */
  { /*    34 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD44187] */
  { /*    35 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x560C61] */
  { /*    36 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x561092] */
  { /*    37 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x560B78] */
  { /*    38 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x560A54] */
  { /*    39 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x560209] */
  { /*    40 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x561792] */
  { /*    41 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x560642] */
  { /*    42 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD4004B] */
  { /*    43 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x560004] */
  { /*    44 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x560747] */
  { /*    45 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x561195] */
  { /*    46 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x560106] */
  { /*    47 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x560F76] */
  { /*    48 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x561305] */
  { /*    49 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x560E41] */
    /* Index    FreezeFrameTableStdFFIdx  FunctionalUnit        Referable Keys */
  { /*    50 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x5609A3] */
  { /*    51 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x5608A2] */
  { /*    52 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x560D46] */
  { /*    53 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD41387] */
  { /*    54 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD4258F] */
  { /*    55 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD43281] */
  { /*    56 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD40188] */
  { /*    57 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD43481] */
  { /*    58 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD43581] */
  { /*    59 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0xD43381] */
  { /*    60 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x561655] */
  { /*    61 */                       1u,             0u },  /* [DTCClass_DtcClass_DTC_0x561583] */
  { /*    62 */                       0u,             0u }   /* [DemDTCClass] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DtcTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DtcTable
  \details
  Element                              Description
  ExtendedDataTableIdx                 the index of the 1:1 relation pointing to Dem_Cfg_ExtendedDataTable
  FreezeFrameNumIndirectionTableIdx    the index of the 0:1 relation pointing to Dem_Cfg_FreezeFrameNumIndirectionTable
  J1939NodeIdIndEndIdx                 the end index of the 0:n relation pointing to Dem_Cfg_J1939NodeIdInd
  J1939NodeIdIndStartIdx               the start index of the 0:n relation pointing to Dem_Cfg_J1939NodeIdInd
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DtcTableType, DEM_CONST) Dem_Cfg_DtcTable[63] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExtendedDataTableIdx  FreezeFrameNumIndirectionTableIdx                       J1939NodeIdIndEndIdx                       J1939NodeIdIndStartIdx                             Referable Keys */
  { /*     0 */                   0u, DEM_CFG_NO_FREEZEFRAMENUMINDIRECTIONTABLEIDXOFDTCTABLE, DEM_CFG_NO_J1939NODEIDINDENDIDXOFDTCTABLE, DEM_CFG_NO_J1939NODEIDINDSTARTIDXOFDTCTABLE },  /* [#NoUdsDtcConfigured, #NoJ1939DtcConfigured] */
  { /*     1 */                   1u,                                                     0u,                                        1u,                                          0u },  /* [DTCClass_DtcClass_DTC_0xD43681] */
  { /*     2 */                   1u,                                                     0u,                                        2u,                                          1u },  /* [DTCClass_DtcClass_DTC_0xD43781] */
  { /*     3 */                   1u,                                                     0u,                                        3u,                                          2u },  /* [DTCClass_DtcClass_DTC_0xD40787] */
  { /*     4 */                   1u,                                                     0u,                                        4u,                                          3u },  /* [DTCClass_DtcClass_DTC_0xD4198F] */
  { /*     5 */                   1u,                                                     0u,                                        5u,                                          4u },  /* [DTCClass_DtcClass_DTC_0xD43081] */
  { /*     6 */                   1u,                                                     0u,                                        6u,                                          5u },  /* [DTCClass_DtcClass_DTC_0x561792_001] */
  { /*     7 */                   1u,                                                     0u,                                        7u,                                          6u },  /* [DTCClass_DtcClass_DTC_0xD42681] */
  { /*     8 */                   1u,                                                     0u,                                        8u,                                          7u },  /* [DTCClass_DtcClass_DTC_0xD42781] */
  { /*     9 */                   1u,                                                     0u,                                        9u,                                          8u },  /* [DTCClass_DtcClass_DTC_0xD4238F] */
  { /*    10 */                   1u,                                                     0u,                                       10u,                                          9u },  /* [DTCClass_DtcClass_DTC_0xD40887] */
  { /*    11 */                   1u,                                                     0u,                                       11u,                                         10u },  /* [DTCClass_DtcClass_DTC_0xD4208F] */
  { /*    12 */                   1u,                                                     0u,                                       12u,                                         11u },  /* [DTCClass_DtcClass_DTC_0xD41087] */
  { /*    13 */                   1u,                                                     0u,                                       13u,                                         12u },  /* [DTCClass_DtcClass_DTC_0xD4218F] */
  { /*    14 */                   1u,                                                     0u,                                       14u,                                         13u },  /* [DTCClass_DtcClass_DTC_0xD40987] */
  { /*    15 */                   1u,                                                     0u,                                       15u,                                         14u },  /* [DTCClass_DtcClass_DTC_0xD4228F] */
  { /*    16 */                   1u,                                                     0u,                                       16u,                                         15u },  /* [DTCClass_DtcClass_DTC_0xD41187] */
  { /*    17 */                   1u,                                                     0u,                                       17u,                                         16u },  /* [DTCClass_DtcClass_DTC_0xD4248F] */
  { /*    18 */                   1u,                                                     0u,                                       18u,                                         17u },  /* [DTCClass_DtcClass_DTC_0xD41287] */
  { /*    19 */                   1u,                                                     0u,                                       19u,                                         18u },  /* [DTCClass_DtcClass_DTC_0x561745] */
  { /*    20 */                   1u,                                                     0u,                                       20u,                                         19u },  /* [DTCClass_DtcClass_DTC_0xD4158F] */
  { /*    21 */                   1u,                                                     0u,                                       21u,                                         20u },  /* [DTCClass_DtcClass_DTC_0xD40387] */
  { /*    22 */                   1u,                                                     0u,                                       22u,                                         21u },  /* [DTCClass_DtcClass_DTC_0xD40487] */
  { /*    23 */                   1u,                                                     0u,                                       23u,                                         22u },  /* [DTCClass_DtcClass_DTC_0xD4168F] */
  { /*    24 */                   1u,                                                     0u,                                       24u,                                         23u },  /* [DTCClass_DtcClass_DTC_0xD4178F] */
  { /*    25 */                   1u,                                                     0u,                                       25u,                                         24u },  /* [DTCClass_DtcClass_DTC_0xD40587] */
  { /*    26 */                   1u,                                                     0u,                                       26u,                                         25u },  /* [DTCClass_DtcClass_DTC_0xD4188F] */
  { /*    27 */                   1u,                                                     0u,                                       27u,                                         26u },  /* [DTCClass_DtcClass_DTC_0xD40687] */
  { /*    28 */                   1u,                                                     0u,                                       28u,                                         27u },  /* [DTCClass_DtcClass_DTC_0xD4438A] */
  { /*    29 */                   1u,                                                     0u,                                       29u,                                         28u },  /* [DTCClass_DtcClass_DTC_0xD43987] */
  { /*    30 */                   1u,                                                     0u,                                       30u,                                         29u },  /* [DTCClass_DtcClass_DTC_0xD44083] */
  { /*    31 */                   1u,                                                     0u,                                       31u,                                         30u },  /* [DTCClass_DtcClass_DTC_0xD42981] */
  { /*    32 */                   1u,                                                     0u,                                       32u,                                         31u },  /* [DTCClass_DtcClass_DTC_0xD43181] */
  { /*    33 */                   1u,                                                     0u,                                       33u,                                         32u },  /* [DTCClass_DtcClass_DTC_0xD40288] */
  { /*    34 */                   1u,                                                     0u,                                       34u,                                         33u },  /* [DTCClass_DtcClass_DTC_0xD44187] */
  { /*    35 */                   1u,                                                     0u,                                       35u,                                         34u },  /* [DTCClass_DtcClass_DTC_0x560C61] */
  { /*    36 */                   1u,                                                     0u,                                       36u,                                         35u },  /* [DTCClass_DtcClass_DTC_0x561092] */
  { /*    37 */                   1u,                                                     0u,                                       37u,                                         36u },  /* [DTCClass_DtcClass_DTC_0x560B78] */
  { /*    38 */                   1u,                                                     0u,                                       38u,                                         37u },  /* [DTCClass_DtcClass_DTC_0x560A54] */
  { /*    39 */                   1u,                                                     0u,                                       39u,                                         38u },  /* [DTCClass_DtcClass_DTC_0x560209] */
  { /*    40 */                   1u,                                                     0u,                                       40u,                                         39u },  /* [DTCClass_DtcClass_DTC_0x561792] */
  { /*    41 */                   1u,                                                     0u,                                       41u,                                         40u },  /* [DTCClass_DtcClass_DTC_0x560642] */
  { /*    42 */                   1u,                                                     0u,                                       42u,                                         41u },  /* [DTCClass_DtcClass_DTC_0xD4004B] */
  { /*    43 */                   1u,                                                     0u,                                       43u,                                         42u },  /* [DTCClass_DtcClass_DTC_0x560004] */
  { /*    44 */                   1u,                                                     0u,                                       44u,                                         43u },  /* [DTCClass_DtcClass_DTC_0x560747] */
  { /*    45 */                   1u,                                                     0u,                                       45u,                                         44u },  /* [DTCClass_DtcClass_DTC_0x561195] */
  { /*    46 */                   1u,                                                     0u,                                       46u,                                         45u },  /* [DTCClass_DtcClass_DTC_0x560106] */
  { /*    47 */                   1u,                                                     0u,                                       47u,                                         46u },  /* [DTCClass_DtcClass_DTC_0x560F76] */
  { /*    48 */                   1u,                                                     0u,                                       48u,                                         47u },  /* [DTCClass_DtcClass_DTC_0x561305] */
  { /*    49 */                   1u,                                                     0u,                                       49u,                                         48u },  /* [DTCClass_DtcClass_DTC_0x560E41] */
    /* Index    ExtendedDataTableIdx  FreezeFrameNumIndirectionTableIdx                       J1939NodeIdIndEndIdx                       J1939NodeIdIndStartIdx                             Referable Keys */
  { /*    50 */                   1u,                                                     0u,                                       50u,                                         49u },  /* [DTCClass_DtcClass_DTC_0x5609A3] */
  { /*    51 */                   1u,                                                     0u,                                       51u,                                         50u },  /* [DTCClass_DtcClass_DTC_0x5608A2] */
  { /*    52 */                   1u,                                                     0u,                                       52u,                                         51u },  /* [DTCClass_DtcClass_DTC_0x560D46] */
  { /*    53 */                   1u,                                                     0u,                                       53u,                                         52u },  /* [DTCClass_DtcClass_DTC_0xD41387] */
  { /*    54 */                   1u,                                                     0u,                                       54u,                                         53u },  /* [DTCClass_DtcClass_DTC_0xD4258F] */
  { /*    55 */                   1u,                                                     0u,                                       55u,                                         54u },  /* [DTCClass_DtcClass_DTC_0xD43281] */
  { /*    56 */                   1u,                                                     0u,                                       56u,                                         55u },  /* [DTCClass_DtcClass_DTC_0xD40188] */
  { /*    57 */                   1u,                                                     0u,                                       57u,                                         56u },  /* [DTCClass_DtcClass_DTC_0xD43481] */
  { /*    58 */                   1u,                                                     0u,                                       58u,                                         57u },  /* [DTCClass_DtcClass_DTC_0xD43581] */
  { /*    59 */                   1u,                                                     0u,                                       59u,                                         58u },  /* [DTCClass_DtcClass_DTC_0xD43381] */
  { /*    60 */                   1u,                                                     0u,                                       60u,                                         59u },  /* [DTCClass_DtcClass_DTC_0x561655] */
  { /*    61 */                   1u,                                                     0u,                                       61u,                                         60u },  /* [DTCClass_DtcClass_DTC_0x561583] */
  { /*    62 */                   0u,                                                     1u,                                       62u,                                         61u }   /* [DemDTCClass] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventAvailableInVariantRDR_01
**********************************************************************************************************************/
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EventAvailableInVariantType, DEM_CONST) Dem_Cfg_EventAvailableInVariantRDR_01[63] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     EventAvailableInVariant      Comment */
  /*     0 */                     TRUE,  /* [#EVENT_INVALID] */
  /*     1 */                     TRUE,  /* [ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received] */
  /*     2 */                     TRUE,  /* [ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received] */
  /*     3 */                     TRUE,  /* [AT_AMT_ECU_ETC2_03_message_Missing_Message] */
  /*     4 */                     TRUE,  /* [AT_AMT_ETC2_erratic_communication_Erratic] */
  /*     5 */                     TRUE,  /* [AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received] */
  /*     6 */                     TRUE,  /* [Application_Interface_Lookup_Performance_or_Incorrect_Operation] */
  /*     7 */                     TRUE,  /* [CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received] */
  /*     8 */                     TRUE,  /* [CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received] */
  /*     9 */                     TRUE,  /* [Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic] */
  /*    10 */                     TRUE,  /* [Cluster_ECU_ADAS_FN_STS_message_Missing_Message] */
  /*    11 */                     TRUE,  /* [Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic] */
  /*    12 */                     TRUE,  /* [Cluster_ECU_CLS_Tx_4_message_Missing_Message] */
  /*    13 */                     TRUE,  /* [Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic] */
  /*    14 */                     TRUE,  /* [Cluster_ECU_CLS_Tx_16_message_Missing_Message] */
  /*    15 */                     TRUE,  /* [Cluster_ECU_OEL_erratic_communication_Erratic] */
  /*    16 */                     TRUE,  /* [Cluster_ECU_OEL_message_Missing_Message] */
  /*    17 */                     TRUE,  /* [Cluster_ECU_TD_erratic_communication_Erratic] */
  /*    18 */                     TRUE,  /* [Cluster_ECU_TD_message_Missing_Message] */
  /*    19 */                     TRUE,  /* [ECU_NVM_Corruption_Program_memory_Failure] */
  /*    20 */                     TRUE,  /* [EMS_ECU_CCVS1_erratic_communication_Erractic] */
  /*    21 */                     TRUE,  /* [EMS_ECU_CCVS1_message_Missing_Message] */
  /*    22 */                     TRUE,  /* [EMS_ECU_ETC2_00_message_Missing_Message] */
  /*    23 */                     TRUE,  /* [EMS_ECU_ETC2_erratic_communication_Erractic] */
  /*    24 */                     TRUE,  /* [EMS_ECU_VD_erratic_communication_Erratic] */
  /*    25 */                     TRUE,  /* [EMS_ECU_VD_message_Missing_Message] */
  /*    26 */                     TRUE,  /* [ESC_ECU_VDC2_erratic_communication_Erratic] */
  /*    27 */                     TRUE,  /* [ESC_ECU_VDC2_message_Missing_Message] */
  /*    28 */                     TRUE,  /* [Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure] */
  /*    29 */                     TRUE,  /* [Front_Left_Side_Radar_Missing_Message] */
  /*    30 */                     TRUE,  /* [Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect] */
  /*    31 */                     TRUE,  /* [Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received] */
  /*    32 */                     TRUE,  /* [OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received] */
  /*    33 */                     TRUE,  /* [PCAN_Communication_Bus_Off] */
  /*    34 */                     TRUE,  /* [PCAN_TimeSync_Missing_Message] */
  /*    35 */                     TRUE,  /* [Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure] */
  /*    36 */                     TRUE,  /* [Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation] */
  /*    37 */                     TRUE,  /* [Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect] */
  /*    38 */                     TRUE,  /* [Radar_Initial_Alignment_Missing_Calibration] */
  /*    39 */                     TRUE,  /* [Radar_MMIC_Component_Failure] */
  /*    40 */                     TRUE,  /* [Radar_MMIC_RFBIST_Component_Internal_Failure] */
  /*    41 */                     TRUE,  /* [Radar_Module_General_Memory_Failure] */
  /*    42 */                     TRUE,  /* [Radar_Module_Over_Temperature] */
  /*    43 */                     TRUE,  /* [Radar_Module_System_Internal_Failure] */
  /*    44 */                     TRUE,  /* [Radar_Module_Watchdog_Failure] */
  /*    45 */                     TRUE,  /* [Radar_Mounting_Orientation_Incorrect_Assembly] */
  /*    46 */                     TRUE,  /* [Radar_Performance_Capability_Algorithm_Based_Failure] */
  /*    47 */                     TRUE,  /* [Radar_Pin_Position_Wrong_Mounting_Position] */
  /*    48 */                     TRUE,  /* [Radar_Platform_Time_System_Programming_Failure] */
  /*    49 */                     TRUE,  /* [Radar_SMC_General_Checksum_Failure] */
  /* Index     EventAvailableInVariant      Comment */
  /*    50 */                     TRUE,  /* [Radar_System_Battery_High_Voltage_System_Voltage_High] */
  /*    51 */                     TRUE,  /* [Radar_System_Battery_Low_Voltage_System_Voltage_Low] */
  /*    52 */                     TRUE,  /* [Radar_calibration_Calibration_or_Paramater_Memory_Failure] */
  /*    53 */                     TRUE,  /* [SAS_ECU_SAS_message_Missing_Message] */
  /*    54 */                     TRUE,  /* [SAS_ECU_erratic_communication_Erratic] */
  /*    55 */                     TRUE,  /* [SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received] */
  /*    56 */                     TRUE,  /* [VCAN_Communication_Bus_Off] */
  /*    57 */                     TRUE,  /* [VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received] */
  /*    58 */                     TRUE,  /* [VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received] */
  /*    59 */                     TRUE,  /* [VDC2_message_Yaw_rate_Invalid_Serial_Data_Received] */
  /*    60 */                     TRUE,  /* [Vehicle_DataSet_Not_Configured] */
  /*    61 */                     TRUE,  /* [Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect] */
  /*    62 */                     TRUE   /* [DemEventParameter] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventAvailableInVariantRDR_02
**********************************************************************************************************************/
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EventAvailableInVariantType, DEM_CONST) Dem_Cfg_EventAvailableInVariantRDR_02[63] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     EventAvailableInVariant      Comment */
  /*     0 */                     TRUE,  /* [#EVENT_INVALID] */
  /*     1 */                     TRUE,  /* [ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received] */
  /*     2 */                     TRUE,  /* [ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received] */
  /*     3 */                     TRUE,  /* [AT_AMT_ECU_ETC2_03_message_Missing_Message] */
  /*     4 */                     TRUE,  /* [AT_AMT_ETC2_erratic_communication_Erratic] */
  /*     5 */                     TRUE,  /* [AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received] */
  /*     6 */                     TRUE,  /* [Application_Interface_Lookup_Performance_or_Incorrect_Operation] */
  /*     7 */                     TRUE,  /* [CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received] */
  /*     8 */                     TRUE,  /* [CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received] */
  /*     9 */                     TRUE,  /* [Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic] */
  /*    10 */                     TRUE,  /* [Cluster_ECU_ADAS_FN_STS_message_Missing_Message] */
  /*    11 */                     TRUE,  /* [Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic] */
  /*    12 */                     TRUE,  /* [Cluster_ECU_CLS_Tx_4_message_Missing_Message] */
  /*    13 */                     TRUE,  /* [Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic] */
  /*    14 */                     TRUE,  /* [Cluster_ECU_CLS_Tx_16_message_Missing_Message] */
  /*    15 */                     TRUE,  /* [Cluster_ECU_OEL_erratic_communication_Erratic] */
  /*    16 */                     TRUE,  /* [Cluster_ECU_OEL_message_Missing_Message] */
  /*    17 */                     TRUE,  /* [Cluster_ECU_TD_erratic_communication_Erratic] */
  /*    18 */                     TRUE,  /* [Cluster_ECU_TD_message_Missing_Message] */
  /*    19 */                     TRUE,  /* [ECU_NVM_Corruption_Program_memory_Failure] */
  /*    20 */                     TRUE,  /* [EMS_ECU_CCVS1_erratic_communication_Erractic] */
  /*    21 */                     TRUE,  /* [EMS_ECU_CCVS1_message_Missing_Message] */
  /*    22 */                     TRUE,  /* [EMS_ECU_ETC2_00_message_Missing_Message] */
  /*    23 */                     TRUE,  /* [EMS_ECU_ETC2_erratic_communication_Erractic] */
  /*    24 */                     TRUE,  /* [EMS_ECU_VD_erratic_communication_Erratic] */
  /*    25 */                     TRUE,  /* [EMS_ECU_VD_message_Missing_Message] */
  /*    26 */                     TRUE,  /* [ESC_ECU_VDC2_erratic_communication_Erratic] */
  /*    27 */                     TRUE,  /* [ESC_ECU_VDC2_message_Missing_Message] */
  /*    28 */                     TRUE,  /* [Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure] */
  /*    29 */                    FALSE,  /* [Front_Left_Side_Radar_Missing_Message] */
  /*    30 */                    FALSE,  /* [Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect] */
  /*    31 */                     TRUE,  /* [Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received] */
  /*    32 */                     TRUE,  /* [OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received] */
  /*    33 */                     TRUE,  /* [PCAN_Communication_Bus_Off] */
  /*    34 */                    FALSE,  /* [PCAN_TimeSync_Missing_Message] */
  /*    35 */                     TRUE,  /* [Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure] */
  /*    36 */                     TRUE,  /* [Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation] */
  /*    37 */                     TRUE,  /* [Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect] */
  /*    38 */                     TRUE,  /* [Radar_Initial_Alignment_Missing_Calibration] */
  /*    39 */                     TRUE,  /* [Radar_MMIC_Component_Failure] */
  /*    40 */                     TRUE,  /* [Radar_MMIC_RFBIST_Component_Internal_Failure] */
  /*    41 */                     TRUE,  /* [Radar_Module_General_Memory_Failure] */
  /*    42 */                     TRUE,  /* [Radar_Module_Over_Temperature] */
  /*    43 */                     TRUE,  /* [Radar_Module_System_Internal_Failure] */
  /*    44 */                     TRUE,  /* [Radar_Module_Watchdog_Failure] */
  /*    45 */                     TRUE,  /* [Radar_Mounting_Orientation_Incorrect_Assembly] */
  /*    46 */                     TRUE,  /* [Radar_Performance_Capability_Algorithm_Based_Failure] */
  /*    47 */                     TRUE,  /* [Radar_Pin_Position_Wrong_Mounting_Position] */
  /*    48 */                     TRUE,  /* [Radar_Platform_Time_System_Programming_Failure] */
  /*    49 */                     TRUE,  /* [Radar_SMC_General_Checksum_Failure] */
  /* Index     EventAvailableInVariant      Comment */
  /*    50 */                     TRUE,  /* [Radar_System_Battery_High_Voltage_System_Voltage_High] */
  /*    51 */                     TRUE,  /* [Radar_System_Battery_Low_Voltage_System_Voltage_Low] */
  /*    52 */                     TRUE,  /* [Radar_calibration_Calibration_or_Paramater_Memory_Failure] */
  /*    53 */                     TRUE,  /* [SAS_ECU_SAS_message_Missing_Message] */
  /*    54 */                     TRUE,  /* [SAS_ECU_erratic_communication_Erratic] */
  /*    55 */                     TRUE,  /* [SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received] */
  /*    56 */                     TRUE,  /* [VCAN_Communication_Bus_Off] */
  /*    57 */                     TRUE,  /* [VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received] */
  /*    58 */                     TRUE,  /* [VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received] */
  /*    59 */                     TRUE,  /* [VDC2_message_Yaw_rate_Invalid_Serial_Data_Received] */
  /*    60 */                     TRUE,  /* [Vehicle_DataSet_Not_Configured] */
  /*    61 */                     TRUE,  /* [Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect] */
  /*    62 */                     TRUE   /* [DemEventParameter] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventAvailableInVariantRDR_04
**********************************************************************************************************************/
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EventAvailableInVariantType, DEM_CONST) Dem_Cfg_EventAvailableInVariantRDR_04[63] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     EventAvailableInVariant      Comment */
  /*     0 */                     TRUE,  /* [#EVENT_INVALID] */
  /*     1 */                     TRUE,  /* [ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received] */
  /*     2 */                     TRUE,  /* [ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received] */
  /*     3 */                     TRUE,  /* [AT_AMT_ECU_ETC2_03_message_Missing_Message] */
  /*     4 */                     TRUE,  /* [AT_AMT_ETC2_erratic_communication_Erratic] */
  /*     5 */                     TRUE,  /* [AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received] */
  /*     6 */                     TRUE,  /* [Application_Interface_Lookup_Performance_or_Incorrect_Operation] */
  /*     7 */                     TRUE,  /* [CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received] */
  /*     8 */                     TRUE,  /* [CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received] */
  /*     9 */                     TRUE,  /* [Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic] */
  /*    10 */                     TRUE,  /* [Cluster_ECU_ADAS_FN_STS_message_Missing_Message] */
  /*    11 */                     TRUE,  /* [Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic] */
  /*    12 */                     TRUE,  /* [Cluster_ECU_CLS_Tx_4_message_Missing_Message] */
  /*    13 */                     TRUE,  /* [Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic] */
  /*    14 */                     TRUE,  /* [Cluster_ECU_CLS_Tx_16_message_Missing_Message] */
  /*    15 */                     TRUE,  /* [Cluster_ECU_OEL_erratic_communication_Erratic] */
  /*    16 */                     TRUE,  /* [Cluster_ECU_OEL_message_Missing_Message] */
  /*    17 */                     TRUE,  /* [Cluster_ECU_TD_erratic_communication_Erratic] */
  /*    18 */                     TRUE,  /* [Cluster_ECU_TD_message_Missing_Message] */
  /*    19 */                     TRUE,  /* [ECU_NVM_Corruption_Program_memory_Failure] */
  /*    20 */                     TRUE,  /* [EMS_ECU_CCVS1_erratic_communication_Erractic] */
  /*    21 */                     TRUE,  /* [EMS_ECU_CCVS1_message_Missing_Message] */
  /*    22 */                     TRUE,  /* [EMS_ECU_ETC2_00_message_Missing_Message] */
  /*    23 */                     TRUE,  /* [EMS_ECU_ETC2_erratic_communication_Erractic] */
  /*    24 */                     TRUE,  /* [EMS_ECU_VD_erratic_communication_Erratic] */
  /*    25 */                     TRUE,  /* [EMS_ECU_VD_message_Missing_Message] */
  /*    26 */                     TRUE,  /* [ESC_ECU_VDC2_erratic_communication_Erratic] */
  /*    27 */                     TRUE,  /* [ESC_ECU_VDC2_message_Missing_Message] */
  /*    28 */                     TRUE,  /* [Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure] */
  /*    29 */                    FALSE,  /* [Front_Left_Side_Radar_Missing_Message] */
  /*    30 */                    FALSE,  /* [Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect] */
  /*    31 */                     TRUE,  /* [Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received] */
  /*    32 */                     TRUE,  /* [OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received] */
  /*    33 */                     TRUE,  /* [PCAN_Communication_Bus_Off] */
  /*    34 */                     TRUE,  /* [PCAN_TimeSync_Missing_Message] */
  /*    35 */                     TRUE,  /* [Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure] */
  /*    36 */                     TRUE,  /* [Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation] */
  /*    37 */                     TRUE,  /* [Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect] */
  /*    38 */                     TRUE,  /* [Radar_Initial_Alignment_Missing_Calibration] */
  /*    39 */                     TRUE,  /* [Radar_MMIC_Component_Failure] */
  /*    40 */                     TRUE,  /* [Radar_MMIC_RFBIST_Component_Internal_Failure] */
  /*    41 */                     TRUE,  /* [Radar_Module_General_Memory_Failure] */
  /*    42 */                     TRUE,  /* [Radar_Module_Over_Temperature] */
  /*    43 */                     TRUE,  /* [Radar_Module_System_Internal_Failure] */
  /*    44 */                     TRUE,  /* [Radar_Module_Watchdog_Failure] */
  /*    45 */                     TRUE,  /* [Radar_Mounting_Orientation_Incorrect_Assembly] */
  /*    46 */                     TRUE,  /* [Radar_Performance_Capability_Algorithm_Based_Failure] */
  /*    47 */                     TRUE,  /* [Radar_Pin_Position_Wrong_Mounting_Position] */
  /*    48 */                     TRUE,  /* [Radar_Platform_Time_System_Programming_Failure] */
  /*    49 */                     TRUE,  /* [Radar_SMC_General_Checksum_Failure] */
  /* Index     EventAvailableInVariant      Comment */
  /*    50 */                     TRUE,  /* [Radar_System_Battery_High_Voltage_System_Voltage_High] */
  /*    51 */                     TRUE,  /* [Radar_System_Battery_Low_Voltage_System_Voltage_Low] */
  /*    52 */                     TRUE,  /* [Radar_calibration_Calibration_or_Paramater_Memory_Failure] */
  /*    53 */                     TRUE,  /* [SAS_ECU_SAS_message_Missing_Message] */
  /*    54 */                     TRUE,  /* [SAS_ECU_erratic_communication_Erratic] */
  /*    55 */                     TRUE,  /* [SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received] */
  /*    56 */                     TRUE,  /* [VCAN_Communication_Bus_Off] */
  /*    57 */                     TRUE,  /* [VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received] */
  /*    58 */                     TRUE,  /* [VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received] */
  /*    59 */                     TRUE,  /* [VDC2_message_Yaw_rate_Invalid_Serial_Data_Received] */
  /*    60 */                     TRUE,  /* [Vehicle_DataSet_Not_Configured] */
  /*    61 */                     TRUE,  /* [Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect] */
  /*    62 */                     TRUE   /* [DemEventParameter] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventEntryIndexToNvBlockIndex
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventEntryIndexToNvBlockIndex
  \brief  Translates entry indices used in Dem_Cfg_EventEntryInfoTable[] to the corresponding Nv Block indices used in Dem_Cfg_NvBlockDataPtr[]
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_NvBlockIndexType, DEM_CONST) Dem_Cfg_EventEntryIndexToNvBlockIndex[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     EventEntryIndexToNvBlockIndex      Comment */
  /*     0 */ 2u                            ,  /* [Dem_PrimaryEntry0] */
  /*     1 */ 3u                            ,  /* [Dem_PrimaryEntry1] */
  /*     2 */ 4u                            ,  /* [Dem_PrimaryEntry2] */
  /*     3 */ 5u                            ,  /* [Dem_PrimaryEntry3] */
  /*     4 */ 6u                            ,  /* [Dem_PrimaryEntry4] */
  /*     5 */ 7u                            ,  /* [Dem_PrimaryEntry5] */
  /*     6 */ 8u                            ,  /* [Dem_PrimaryEntry6] */
  /*     7 */ 9u                            ,  /* [Dem_PrimaryEntry7] */
  /*     8 */ 10u                           ,  /* [Dem_PrimaryEntry8] */
  /*     9 */ 11u                           ,  /* [Dem_PrimaryEntry9] */
  /*    10 */ DEM_CFG_INVALID_NVBLOCK_INDEX    /* [[Dem_Cfg_ReadoutBuffer[0].ReadOutBufferData[0].Data], never persisted in NvM] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventEntryInfoTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventEntryInfoTable
  \details
  Element                      Description
  SizeOfExtendedData           Size in bytes of the extended record data buffer.
  SizeOfJ1939ExpFreezeFrame    Size in bytes of the J1939 expanded freeze frame in the J1939 data buffer.
  SizeOfJ1939FreezeFrame       Size in bytes of the J1939 freeze frame in the J1939 data buffer.
  SizeOfObdFreezeFrame         Size in bytes of the WWH-OBD freeze frame data buffer.
  SizeOfSnapshotData           Size in bytes of the snapshot data buffer.
  BaseEntryPtr                 Pointer to the event entry base data.
  InitPtr                      Pointer to the event entry specific initialization block.
  ExtendedDataPtr              Pointer to the extended record data buffer.
  J1939FreezeFrameDataPtr      Pointer to the J1939 freeze frame data buffer.
  ObdFreezeFrameDataPtr        Pointer to the WWH-OBD freeze frame data buffer.
  SnapshotDataPtr              Pointer to the snapshot data buffer.
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EventEntryInfoTableType, DEM_CONST) Dem_Cfg_EventEntryInfoTable[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SizeOfExtendedData  SizeOfJ1939ExpFreezeFrame  SizeOfJ1939FreezeFrame  SizeOfObdFreezeFrame  SizeOfSnapshotData  BaseEntryPtr                                                      InitPtr                                                     ExtendedDataPtr  J1939FreezeFrameDataPtr  ObdFreezeFrameDataPtr  SnapshotDataPtr                                                           */
  { /*     0 */                 0u,                        0u,                     0u,                   0u,                13u, &Dem_Cfg_GetPrimaryEntry_0().BaseEntry                          , (Dem_ConstDataPtrType) &Dem_Cfg_GetPrimaryEventEntryInit(), NULL_PTR       , NULL_PTR               , NULL_PTR             , &Dem_Cfg_GetPrimaryEntry_0().SnapshotData[0][0]                           },
  { /*     1 */                 0u,                        0u,                     0u,                   0u,                13u, &Dem_Cfg_GetPrimaryEntry_1().BaseEntry                          , (Dem_ConstDataPtrType) &Dem_Cfg_GetPrimaryEventEntryInit(), NULL_PTR       , NULL_PTR               , NULL_PTR             , &Dem_Cfg_GetPrimaryEntry_1().SnapshotData[0][0]                           },
  { /*     2 */                 0u,                        0u,                     0u,                   0u,                13u, &Dem_Cfg_GetPrimaryEntry_2().BaseEntry                          , (Dem_ConstDataPtrType) &Dem_Cfg_GetPrimaryEventEntryInit(), NULL_PTR       , NULL_PTR               , NULL_PTR             , &Dem_Cfg_GetPrimaryEntry_2().SnapshotData[0][0]                           },
  { /*     3 */                 0u,                        0u,                     0u,                   0u,                13u, &Dem_Cfg_GetPrimaryEntry_3().BaseEntry                          , (Dem_ConstDataPtrType) &Dem_Cfg_GetPrimaryEventEntryInit(), NULL_PTR       , NULL_PTR               , NULL_PTR             , &Dem_Cfg_GetPrimaryEntry_3().SnapshotData[0][0]                           },
  { /*     4 */                 0u,                        0u,                     0u,                   0u,                13u, &Dem_Cfg_GetPrimaryEntry_4().BaseEntry                          , (Dem_ConstDataPtrType) &Dem_Cfg_GetPrimaryEventEntryInit(), NULL_PTR       , NULL_PTR               , NULL_PTR             , &Dem_Cfg_GetPrimaryEntry_4().SnapshotData[0][0]                           },
  { /*     5 */                 0u,                        0u,                     0u,                   0u,                13u, &Dem_Cfg_GetPrimaryEntry_5().BaseEntry                          , (Dem_ConstDataPtrType) &Dem_Cfg_GetPrimaryEventEntryInit(), NULL_PTR       , NULL_PTR               , NULL_PTR             , &Dem_Cfg_GetPrimaryEntry_5().SnapshotData[0][0]                           },
  { /*     6 */                 0u,                        0u,                     0u,                   0u,                13u, &Dem_Cfg_GetPrimaryEntry_6().BaseEntry                          , (Dem_ConstDataPtrType) &Dem_Cfg_GetPrimaryEventEntryInit(), NULL_PTR       , NULL_PTR               , NULL_PTR             , &Dem_Cfg_GetPrimaryEntry_6().SnapshotData[0][0]                           },
  { /*     7 */                 0u,                        0u,                     0u,                   0u,                13u, &Dem_Cfg_GetPrimaryEntry_7().BaseEntry                          , (Dem_ConstDataPtrType) &Dem_Cfg_GetPrimaryEventEntryInit(), NULL_PTR       , NULL_PTR               , NULL_PTR             , &Dem_Cfg_GetPrimaryEntry_7().SnapshotData[0][0]                           },
  { /*     8 */                 0u,                        0u,                     0u,                   0u,                13u, &Dem_Cfg_GetPrimaryEntry_8().BaseEntry                          , (Dem_ConstDataPtrType) &Dem_Cfg_GetPrimaryEventEntryInit(), NULL_PTR       , NULL_PTR               , NULL_PTR             , &Dem_Cfg_GetPrimaryEntry_8().SnapshotData[0][0]                           },
  { /*     9 */                 0u,                        0u,                     0u,                   0u,                13u, &Dem_Cfg_GetPrimaryEntry_9().BaseEntry                          , (Dem_ConstDataPtrType) &Dem_Cfg_GetPrimaryEventEntryInit(), NULL_PTR       , NULL_PTR               , NULL_PTR             , &Dem_Cfg_GetPrimaryEntry_9().SnapshotData[0][0]                           },
  { /*    10 */                 0u,                        0u,                     0u,                   0u,                13u, &Dem_Cfg_GetReadoutBuffer(0).ReadOutBufferData[0].Data.BaseEntry, NULL_PTR                                                  , NULL_PTR       , NULL_PTR               , NULL_PTR             , &Dem_Cfg_GetReadoutBuffer(0).ReadOutBufferData[0].Data.SnapshotData[0][0] }
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventInvariantDataTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventInvariantDataTable
  \details
  Element        Description
  DtcTableIdx    the index of the 1:1 relation pointing to Dem_Cfg_DtcTable
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EventInvariantDataTableType, DEM_CONST) Dem_Cfg_EventInvariantDataTable[63] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DtcTableIdx        Referable Keys */
  { /*     0 */          1u },  /* [#EVENT_INVALID] */
  { /*     1 */          1u },  /* [ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received] */
  { /*     2 */          2u },  /* [ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received] */
  { /*     3 */          3u },  /* [AT_AMT_ECU_ETC2_03_message_Missing_Message] */
  { /*     4 */          4u },  /* [AT_AMT_ETC2_erratic_communication_Erratic] */
  { /*     5 */          5u },  /* [AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received] */
  { /*     6 */          6u },  /* [Application_Interface_Lookup_Performance_or_Incorrect_Operation] */
  { /*     7 */          7u },  /* [CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received] */
  { /*     8 */          8u },  /* [CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received] */
  { /*     9 */          9u },  /* [Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic] */
  { /*    10 */         10u },  /* [Cluster_ECU_ADAS_FN_STS_message_Missing_Message] */
  { /*    11 */         11u },  /* [Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic] */
  { /*    12 */         12u },  /* [Cluster_ECU_CLS_Tx_4_message_Missing_Message] */
  { /*    13 */         13u },  /* [Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic] */
  { /*    14 */         14u },  /* [Cluster_ECU_CLS_Tx_16_message_Missing_Message] */
  { /*    15 */         15u },  /* [Cluster_ECU_OEL_erratic_communication_Erratic] */
  { /*    16 */         16u },  /* [Cluster_ECU_OEL_message_Missing_Message] */
  { /*    17 */         17u },  /* [Cluster_ECU_TD_erratic_communication_Erratic] */
  { /*    18 */         18u },  /* [Cluster_ECU_TD_message_Missing_Message] */
  { /*    19 */         19u },  /* [ECU_NVM_Corruption_Program_memory_Failure] */
  { /*    20 */         20u },  /* [EMS_ECU_CCVS1_erratic_communication_Erractic] */
  { /*    21 */         21u },  /* [EMS_ECU_CCVS1_message_Missing_Message] */
  { /*    22 */         22u },  /* [EMS_ECU_ETC2_00_message_Missing_Message] */
  { /*    23 */         23u },  /* [EMS_ECU_ETC2_erratic_communication_Erractic] */
  { /*    24 */         24u },  /* [EMS_ECU_VD_erratic_communication_Erratic] */
  { /*    25 */         25u },  /* [EMS_ECU_VD_message_Missing_Message] */
  { /*    26 */         26u },  /* [ESC_ECU_VDC2_erratic_communication_Erratic] */
  { /*    27 */         27u },  /* [ESC_ECU_VDC2_message_Missing_Message] */
  { /*    28 */         28u },  /* [Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure] */
  { /*    29 */         29u },  /* [Front_Left_Side_Radar_Missing_Message] */
  { /*    30 */         30u },  /* [Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect] */
  { /*    31 */         31u },  /* [Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received] */
  { /*    32 */         32u },  /* [OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received] */
  { /*    33 */         33u },  /* [PCAN_Communication_Bus_Off] */
  { /*    34 */         34u },  /* [PCAN_TimeSync_Missing_Message] */
  { /*    35 */         35u },  /* [Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure] */
  { /*    36 */         36u },  /* [Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation] */
  { /*    37 */         37u },  /* [Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect] */
  { /*    38 */         38u },  /* [Radar_Initial_Alignment_Missing_Calibration] */
  { /*    39 */         39u },  /* [Radar_MMIC_Component_Failure] */
  { /*    40 */         40u },  /* [Radar_MMIC_RFBIST_Component_Internal_Failure] */
  { /*    41 */         41u },  /* [Radar_Module_General_Memory_Failure] */
  { /*    42 */         42u },  /* [Radar_Module_Over_Temperature] */
  { /*    43 */         43u },  /* [Radar_Module_System_Internal_Failure] */
  { /*    44 */         44u },  /* [Radar_Module_Watchdog_Failure] */
  { /*    45 */         45u },  /* [Radar_Mounting_Orientation_Incorrect_Assembly] */
  { /*    46 */         46u },  /* [Radar_Performance_Capability_Algorithm_Based_Failure] */
  { /*    47 */         47u },  /* [Radar_Pin_Position_Wrong_Mounting_Position] */
  { /*    48 */         48u },  /* [Radar_Platform_Time_System_Programming_Failure] */
  { /*    49 */         49u },  /* [Radar_SMC_General_Checksum_Failure] */
    /* Index    DtcTableIdx        Referable Keys */
  { /*    50 */         50u },  /* [Radar_System_Battery_High_Voltage_System_Voltage_High] */
  { /*    51 */         51u },  /* [Radar_System_Battery_Low_Voltage_System_Voltage_Low] */
  { /*    52 */         52u },  /* [Radar_calibration_Calibration_or_Paramater_Memory_Failure] */
  { /*    53 */         53u },  /* [SAS_ECU_SAS_message_Missing_Message] */
  { /*    54 */         54u },  /* [SAS_ECU_erratic_communication_Erratic] */
  { /*    55 */         55u },  /* [SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received] */
  { /*    56 */         56u },  /* [VCAN_Communication_Bus_Off] */
  { /*    57 */         57u },  /* [VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received] */
  { /*    58 */         58u },  /* [VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received] */
  { /*    59 */         59u },  /* [VDC2_message_Yaw_rate_Invalid_Serial_Data_Received] */
  { /*    60 */         60u },  /* [Vehicle_DataSet_Not_Configured] */
  { /*    61 */         61u },  /* [Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect] */
  { /*    62 */         62u }   /* [DemEventParameter] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventPrecompileDataTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventPrecompileDataTable
  \details
  Element                       Description
  EventStatusChangedEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_EventStatusChanged
  EventStatusChangedStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_EventStatusChanged
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EventPrecompileDataTableType, DEM_CONST) Dem_Cfg_EventPrecompileDataTable[63] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EventStatusChangedEndIdx                                       EventStatusChangedStartIdx                                             Referable Keys */
  { /*     0 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [#EVENT_INVALID, Satellite#Invalid_OsApplication] */
  { /*     1 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received, Satellite#Invalid_OsApplication] */
  { /*     2 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received, Satellite#Invalid_OsApplication] */
  { /*     3 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [AT_AMT_ECU_ETC2_03_message_Missing_Message, Satellite#Invalid_OsApplication] */
  { /*     4 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [AT_AMT_ETC2_erratic_communication_Erratic, Satellite#Invalid_OsApplication] */
  { /*     5 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, Satellite#Invalid_OsApplication] */
  { /*     6 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Application_Interface_Lookup_Performance_or_Incorrect_Operation, Satellite#Invalid_OsApplication] */
  { /*     7 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received, Satellite#Invalid_OsApplication] */
  { /*     8 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received, Satellite#Invalid_OsApplication] */
  { /*     9 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic, Satellite#Invalid_OsApplication] */
  { /*    10 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Cluster_ECU_ADAS_FN_STS_message_Missing_Message, Satellite#Invalid_OsApplication] */
  { /*    11 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic, Satellite#Invalid_OsApplication] */
  { /*    12 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Cluster_ECU_CLS_Tx_4_message_Missing_Message, Satellite#Invalid_OsApplication] */
  { /*    13 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic, Satellite#Invalid_OsApplication] */
  { /*    14 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Cluster_ECU_CLS_Tx_16_message_Missing_Message, Satellite#Invalid_OsApplication] */
  { /*    15 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Cluster_ECU_OEL_erratic_communication_Erratic, Satellite#Invalid_OsApplication] */
  { /*    16 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Cluster_ECU_OEL_message_Missing_Message, Satellite#Invalid_OsApplication] */
  { /*    17 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Cluster_ECU_TD_erratic_communication_Erratic, Satellite#Invalid_OsApplication] */
  { /*    18 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Cluster_ECU_TD_message_Missing_Message, Satellite#Invalid_OsApplication] */
  { /*    19 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [ECU_NVM_Corruption_Program_memory_Failure, Satellite#Invalid_OsApplication] */
  { /*    20 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [EMS_ECU_CCVS1_erratic_communication_Erractic, Satellite#Invalid_OsApplication] */
  { /*    21 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [EMS_ECU_CCVS1_message_Missing_Message, Satellite#Invalid_OsApplication] */
  { /*    22 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [EMS_ECU_ETC2_00_message_Missing_Message, Satellite#Invalid_OsApplication] */
  { /*    23 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [EMS_ECU_ETC2_erratic_communication_Erractic, Satellite#Invalid_OsApplication] */
  { /*    24 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [EMS_ECU_VD_erratic_communication_Erratic, Satellite#Invalid_OsApplication] */
  { /*    25 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [EMS_ECU_VD_message_Missing_Message, Satellite#Invalid_OsApplication] */
  { /*    26 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [ESC_ECU_VDC2_erratic_communication_Erratic, Satellite#Invalid_OsApplication] */
  { /*    27 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [ESC_ECU_VDC2_message_Missing_Message, Satellite#Invalid_OsApplication] */
  { /*    28 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure, Satellite#Invalid_OsApplication] */
  { /*    29 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Front_Left_Side_Radar_Missing_Message, Satellite#Invalid_OsApplication] */
  { /*    30 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect, Satellite#Invalid_OsApplication] */
  { /*    31 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, Satellite#Invalid_OsApplication] */
  { /*    32 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received, Satellite#Invalid_OsApplication] */
  { /*    33 */                                                            1u,                                                              0u },  /* [PCAN_Communication_Bus_Off, Satellite#Invalid_OsApplication] */
  { /*    34 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [PCAN_TimeSync_Missing_Message, Satellite#Invalid_OsApplication] */
  { /*    35 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure, Satellite#Invalid_OsApplication] */
  { /*    36 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation, Satellite#Invalid_OsApplication] */
  { /*    37 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect, Satellite#Invalid_OsApplication] */
  { /*    38 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_Initial_Alignment_Missing_Calibration, Satellite#Invalid_OsApplication] */
  { /*    39 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_MMIC_Component_Failure, Satellite#Invalid_OsApplication] */
  { /*    40 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_MMIC_RFBIST_Component_Internal_Failure, Satellite#Invalid_OsApplication] */
  { /*    41 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_Module_General_Memory_Failure, Satellite#Invalid_OsApplication] */
  { /*    42 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_Module_Over_Temperature, Satellite#Invalid_OsApplication] */
  { /*    43 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_Module_System_Internal_Failure, Satellite#Invalid_OsApplication] */
  { /*    44 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_Module_Watchdog_Failure, Satellite#Invalid_OsApplication] */
  { /*    45 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_Mounting_Orientation_Incorrect_Assembly, Satellite#Invalid_OsApplication] */
  { /*    46 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_Performance_Capability_Algorithm_Based_Failure, Satellite#Invalid_OsApplication] */
  { /*    47 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_Pin_Position_Wrong_Mounting_Position, Satellite#Invalid_OsApplication] */
  { /*    48 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_Platform_Time_System_Programming_Failure, Satellite#Invalid_OsApplication] */
  { /*    49 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_SMC_General_Checksum_Failure, Satellite#Invalid_OsApplication] */
    /* Index    EventStatusChangedEndIdx                                       EventStatusChangedStartIdx                                             Referable Keys */
  { /*    50 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_System_Battery_High_Voltage_System_Voltage_High, Satellite#Invalid_OsApplication] */
  { /*    51 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_System_Battery_Low_Voltage_System_Voltage_Low, Satellite#Invalid_OsApplication] */
  { /*    52 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Radar_calibration_Calibration_or_Paramater_Memory_Failure, Satellite#Invalid_OsApplication] */
  { /*    53 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [SAS_ECU_SAS_message_Missing_Message, Satellite#Invalid_OsApplication] */
  { /*    54 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [SAS_ECU_erratic_communication_Erratic, Satellite#Invalid_OsApplication] */
  { /*    55 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received, Satellite#Invalid_OsApplication] */
  { /*    56 */                                                            2u,                                                              1u },  /* [VCAN_Communication_Bus_Off, Satellite#Invalid_OsApplication] */
  { /*    57 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received, Satellite#Invalid_OsApplication] */
  { /*    58 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received, Satellite#Invalid_OsApplication] */
  { /*    59 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [VDC2_message_Yaw_rate_Invalid_Serial_Data_Received, Satellite#Invalid_OsApplication] */
  { /*    60 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Vehicle_DataSet_Not_Configured, Satellite#Invalid_OsApplication] */
  { /*    61 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE },  /* [Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect, Satellite#Invalid_OsApplication] */
  { /*    62 */ DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE }   /* [DemEventParameter, Satellite#Invalid_OsApplication] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventStatusChanged
**********************************************************************************************************************/
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_EventStatusChangedFPtrType, DEM_CONST) Dem_Cfg_EventStatusChanged[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     EventStatusChanged                          Referable Keys */
  /*     0 */ App_DemCbkEventStatus_PCAN_BusOffFault ,  /* [PCAN_Communication_Bus_Off] */
  /*     1 */ App_DemCbkEventStatus_VCAN_BusOffFault    /* [VCAN_Communication_Bus_Off] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ExtendedDataTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ExtendedDataTable
  \details
  Element                                                                 Description
  DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd
  DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_ExtendedDataTableType, DEM_CONST) Dem_Cfg_ExtendedDataTable[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndEndIdx                                DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndStartIdx                                      Referable Keys */
  { /*     0 */ DEM_CFG_NO_DATACOLLECTIONTABLEEDR2COLLINDDATACOLLECTIONTABLEEDR2COLLINDENDIDXOFEXTENDEDDATATABLE, DEM_CFG_NO_DATACOLLECTIONTABLEEDR2COLLINDDATACOLLECTIONTABLEEDR2COLLINDSTARTIDXOFEXTENDEDDATATABLE },  /* [#NoExtendedDataRecordConfigured, #NoUdsDtcConfigured, DemDTCClass] */
  { /*     1 */                                                                                               2u,                                                                                                 0u }   /* [#ExtendedDataClass_6d15841f, DTCClass_DtcClass_DTC_0xD43681, DTCClass_DtcClass_DTC_0xD43781, DTCClass_DtcClass_DTC_0xD40787, DTCClass_DtcClass_DTC_0xD4198F, DTCClass_DtcClass_DTC_0xD43081, DTCClass_DtcClass_DTC_0x561792_001, DTCClass_DtcClass_DTC_0xD42681, DTCClass_DtcClass_DTC_0xD42781, DTCClass_DtcClass_DTC_0xD4238F, DTCClass_DtcClass_DTC_0xD40887, DTCClass_DtcClass_DTC_0xD4208F, DTCClass_DtcClass_DTC_0xD41087, DTCClass_DtcClass_DTC_0xD4218F, DTCClass_DtcClass_DTC_0xD40987, DTCClass_DtcClass_DTC_0xD4228F, DTCClass_DtcClass_DTC_0xD41187, DTCClass_DtcClass_DTC_0xD4248F, DTCClass_DtcClass_DTC_0xD41287, DTCClass_DtcClass_DTC_0x561745, DTCClass_DtcClass_DTC_0xD4158F, DTCClass_DtcClass_DTC_0xD40387, DTCClass_DtcClass_DTC_0xD40487, DTCClass_DtcClass_DTC_0xD4168F, DTCClass_DtcClass_DTC_0xD4178F, DTCClass_DtcClass_DTC_0xD40587, DTCClass_DtcClass_DTC_0xD4188F, DTCClass_DtcClass_DTC_0xD40687, DTCClass_DtcClass_DTC_0xD4438A, DTCClass_DtcClass_DTC_0xD43987, DTCClass_DtcClass_DTC_0xD44083, DTCClass_DtcClass_DTC_0xD42981, DTCClass_DtcClass_DTC_0xD43181, DTCClass_DtcClass_DTC_0xD40288, DTCClass_DtcClass_DTC_0xD44187, DTCClass_DtcClass_DTC_0x560C61, DTCClass_DtcClass_DTC_0x561092, DTCClass_DtcClass_DTC_0x560B78, DTCClass_DtcClass_DTC_0x560A54, DTCClass_DtcClass_DTC_0x560209, DTCClass_DtcClass_DTC_0x561792, DTCClass_DtcClass_DTC_0x560642, DTCClass_DtcClass_DTC_0xD4004B, DTCClass_DtcClass_DTC_0x560004, DTCClass_DtcClass_DTC_0x560747, DTCClass_DtcClass_DTC_0x561195, DTCClass_DtcClass_DTC_0x560106, DTCClass_DtcClass_DTC_0x560F76, DTCClass_DtcClass_DTC_0x561305, DTCClass_DtcClass_DTC_0x560E41, DTCClass_DtcClass_DTC_0x5609A3, DTCClass_DtcClass_DTC_0x5608A2, DTCClass_DtcClass_DTC_0x560D46, DTCClass_DtcClass_DTC_0xD41387, DTCClass_DtcClass_DTC_0xD4258F, DTCClass_DtcClass_DTC_0xD43281, DTCClass_DtcClass_DTC_0xD40188, DTCClass_DtcClass_DTC_0xD43481, DTCClass_DtcClass_DTC_0xD43581, DTCClass_DtcClass_DTC_0xD43381, DTCClass_DtcClass_DTC_0x561655, DTCClass_DtcClass_DTC_0x561583] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FreezeFrameNumIndirectionTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FreezeFrameNumIndirectionTable
  \details
  Element                        Description
  FreezeFrameNumTableEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_FreezeFrameNumTable
  FreezeFrameNumTableStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_FreezeFrameNumTable
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_FreezeFrameNumIndirectionTableType, DEM_CONST) Dem_Cfg_FreezeFrameNumIndirectionTable[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FreezeFrameNumTableEndIdx                                             FreezeFrameNumTableStartIdx                                                   Referable Keys */
  { /*     0 */                                                                   1u,                                                                     0u },  /* [FreezeFrameRecNum_8514b953:UNUSED, DTCClass_DtcClass_DTC_0xD43681, DTCClass_DtcClass_DTC_0xD43781, DTCClass_DtcClass_DTC_0xD40787, DTCClass_DtcClass_DTC_0xD4198F, DTCClass_DtcClass_DTC_0xD43081, DTCClass_DtcClass_DTC_0x561792_001, DTCClass_DtcClass_DTC_0xD42681, DTCClass_DtcClass_DTC_0xD42781, DTCClass_DtcClass_DTC_0xD4238F, DTCClass_DtcClass_DTC_0xD40887, DTCClass_DtcClass_DTC_0xD4208F, DTCClass_DtcClass_DTC_0xD41087, DTCClass_DtcClass_DTC_0xD4218F, DTCClass_DtcClass_DTC_0xD40987, DTCClass_DtcClass_DTC_0xD4228F, DTCClass_DtcClass_DTC_0xD41187, DTCClass_DtcClass_DTC_0xD4248F, DTCClass_DtcClass_DTC_0xD41287, DTCClass_DtcClass_DTC_0x561745, DTCClass_DtcClass_DTC_0xD4158F, DTCClass_DtcClass_DTC_0xD40387, DTCClass_DtcClass_DTC_0xD40487, DTCClass_DtcClass_DTC_0xD4168F, DTCClass_DtcClass_DTC_0xD4178F, DTCClass_DtcClass_DTC_0xD40587, DTCClass_DtcClass_DTC_0xD4188F, DTCClass_DtcClass_DTC_0xD40687, DTCClass_DtcClass_DTC_0xD4438A, DTCClass_DtcClass_DTC_0xD43987, DTCClass_DtcClass_DTC_0xD44083, DTCClass_DtcClass_DTC_0xD42981, DTCClass_DtcClass_DTC_0xD43181, DTCClass_DtcClass_DTC_0xD40288, DTCClass_DtcClass_DTC_0xD44187, DTCClass_DtcClass_DTC_0x560C61, DTCClass_DtcClass_DTC_0x561092, DTCClass_DtcClass_DTC_0x560B78, DTCClass_DtcClass_DTC_0x560A54, DTCClass_DtcClass_DTC_0x560209, DTCClass_DtcClass_DTC_0x561792, DTCClass_DtcClass_DTC_0x560642, DTCClass_DtcClass_DTC_0xD4004B, DTCClass_DtcClass_DTC_0x560004, DTCClass_DtcClass_DTC_0x560747, DTCClass_DtcClass_DTC_0x561195, DTCClass_DtcClass_DTC_0x560106, DTCClass_DtcClass_DTC_0x560F76, DTCClass_DtcClass_DTC_0x561305, DTCClass_DtcClass_DTC_0x560E41, DTCClass_DtcClass_DTC_0x5609A3, DTCClass_DtcClass_DTC_0x5608A2, DTCClass_DtcClass_DTC_0x560D46, DTCClass_DtcClass_DTC_0xD41387, DTCClass_DtcClass_DTC_0xD4258F, DTCClass_DtcClass_DTC_0xD43281, DTCClass_DtcClass_DTC_0xD40188, DTCClass_DtcClass_DTC_0xD43481, DTCClass_DtcClass_DTC_0xD43581, DTCClass_DtcClass_DTC_0xD43381, DTCClass_DtcClass_DTC_0x561655, DTCClass_DtcClass_DTC_0x561583] */
  { /*     1 */ DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFFREEZEFRAMENUMINDIRECTIONTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFFREEZEFRAMENUMINDIRECTIONTABLE }   /* [UNUSED:UNUSED, DemDTCClass] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FreezeFrameTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FreezeFrameTable
  \details
  Element                                                                 Description
  DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd
  DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd
  RecordSize                                                              Summarized size of did data that is stored in the SnapshotData[][] of the corresponding Memory Entry Type (i.e. typically without size of dids containing internal data elements).
  RecordSizeUds                                                           Summarized size of did data, did numbers and snapshot header (i.e. dynamical payload size of the uds response message).
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_FreezeFrameTableType, DEM_CONST) Dem_Cfg_FreezeFrameTable[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndEndIdx                               DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndStartIdx                               RecordSize  RecordSizeUds        Referable Keys */
  { /*     0 */ DEM_CFG_NO_DATACOLLECTIONTABLEFFM2COLLINDDATACOLLECTIONTABLEFFM2COLLINDENDIDXOFFREEZEFRAMETABLE, DEM_CFG_NO_DATACOLLECTIONTABLEFFM2COLLINDDATACOLLECTIONTABLEFFM2COLLINDSTARTIDXOFFREEZEFRAMETABLE,         0u,            0u },  /* [#NoFreezeFrameConfigured, #NoUdsDtcConfigured, SecondFF:#NoUdsDtcConfigured, SecondFF:DTCClass_DtcClass_DTC_0xD43681, SecondFF:DTCClass_DtcClass_DTC_0xD43781, SecondFF:DTCClass_DtcClass_DTC_0xD40787, SecondFF:DTCClass_DtcClass_DTC_0xD4198F, SecondFF:DTCClass_DtcClass_DTC_0xD43081, SecondFF:DTCClass_DtcClass_DTC_0x561792_001, SecondFF:DTCClass_DtcClass_DTC_0xD42681, SecondFF:DTCClass_DtcClass_DTC_0xD42781, SecondFF:DTCClass_DtcClass_DTC_0xD4238F, SecondFF:DTCClass_DtcClass_DTC_0xD40887, SecondFF:DTCClass_DtcClass_DTC_0xD4208F, SecondFF:DTCClass_DtcClass_DTC_0xD41087, SecondFF:DTCClass_DtcClass_DTC_0xD4218F, SecondFF:DTCClass_DtcClass_DTC_0xD40987, SecondFF:DTCClass_DtcClass_DTC_0xD4228F, SecondFF:DTCClass_DtcClass_DTC_0xD41187, SecondFF:DTCClass_DtcClass_DTC_0xD4248F, SecondFF:DTCClass_DtcClass_DTC_0xD41287, SecondFF:DTCClass_DtcClass_DTC_0x561745, SecondFF:DTCClass_DtcClass_DTC_0xD4158F, SecondFF:DTCClass_DtcClass_DTC_0xD40387, SecondFF:DTCClass_DtcClass_DTC_0xD40487, SecondFF:DTCClass_DtcClass_DTC_0xD4168F, SecondFF:DTCClass_DtcClass_DTC_0xD4178F, SecondFF:DTCClass_DtcClass_DTC_0xD40587, SecondFF:DTCClass_DtcClass_DTC_0xD4188F, SecondFF:DTCClass_DtcClass_DTC_0xD40687, SecondFF:DTCClass_DtcClass_DTC_0xD4438A, SecondFF:DTCClass_DtcClass_DTC_0xD43987, SecondFF:DTCClass_DtcClass_DTC_0xD44083, SecondFF:DTCClass_DtcClass_DTC_0xD42981, SecondFF:DTCClass_DtcClass_DTC_0xD43181, SecondFF:DTCClass_DtcClass_DTC_0xD40288, SecondFF:DTCClass_DtcClass_DTC_0xD44187, SecondFF:DTCClass_DtcClass_DTC_0x560C61, SecondFF:DTCClass_DtcClass_DTC_0x561092, SecondFF:DTCClass_DtcClass_DTC_0x560B78, SecondFF:DTCClass_DtcClass_DTC_0x560A54, SecondFF:DTCClass_DtcClass_DTC_0x560209, SecondFF:DTCClass_DtcClass_DTC_0x561792, SecondFF:DTCClass_DtcClass_DTC_0x560642, SecondFF:DTCClass_DtcClass_DTC_0xD4004B, SecondFF:DTCClass_DtcClass_DTC_0x560004, SecondFF:DTCClass_DtcClass_DTC_0x560747, SecondFF:DTCClass_DtcClass_DTC_0x561195, SecondFF:DTCClass_DtcClass_DTC_0x560106, SecondFF:DTCClass_DtcClass_DTC_0x560F76, SecondFF:DTCClass_DtcClass_DTC_0x561305, SecondFF:DTCClass_DtcClass_DTC_0x560E41, SecondFF:DTCClass_DtcClass_DTC_0x5609A3, SecondFF:DTCClass_DtcClass_DTC_0x5608A2, SecondFF:DTCClass_DtcClass_DTC_0x560D46, SecondFF:DTCClass_DtcClass_DTC_0xD41387, SecondFF:DTCClass_DtcClass_DTC_0xD4258F, SecondFF:DTCClass_DtcClass_DTC_0xD43281, SecondFF:DTCClass_DtcClass_DTC_0xD40188, SecondFF:DTCClass_DtcClass_DTC_0xD43481, SecondFF:DTCClass_DtcClass_DTC_0xD43581, SecondFF:DTCClass_DtcClass_DTC_0xD43381, SecondFF:DTCClass_DtcClass_DTC_0x561655, SecondFF:DTCClass_DtcClass_DTC_0x561583, DemDTCClass, SecondFF:DemDTCClass] */
  { /*     1 */                                                                                              5u,                                                                                                0u,        13u,           25u }   /* [#FreezeFrame_d41460f8, DTCClass_DtcClass_DTC_0xD43681, DTCClass_DtcClass_DTC_0xD43781, DTCClass_DtcClass_DTC_0xD40787, DTCClass_DtcClass_DTC_0xD4198F, DTCClass_DtcClass_DTC_0xD43081, DTCClass_DtcClass_DTC_0x561792_001, DTCClass_DtcClass_DTC_0xD42681, DTCClass_DtcClass_DTC_0xD42781, DTCClass_DtcClass_DTC_0xD4238F, DTCClass_DtcClass_DTC_0xD40887, DTCClass_DtcClass_DTC_0xD4208F, DTCClass_DtcClass_DTC_0xD41087, DTCClass_DtcClass_DTC_0xD4218F, DTCClass_DtcClass_DTC_0xD40987, DTCClass_DtcClass_DTC_0xD4228F, DTCClass_DtcClass_DTC_0xD41187, DTCClass_DtcClass_DTC_0xD4248F, DTCClass_DtcClass_DTC_0xD41287, DTCClass_DtcClass_DTC_0x561745, DTCClass_DtcClass_DTC_0xD4158F, DTCClass_DtcClass_DTC_0xD40387, DTCClass_DtcClass_DTC_0xD40487, DTCClass_DtcClass_DTC_0xD4168F, DTCClass_DtcClass_DTC_0xD4178F, DTCClass_DtcClass_DTC_0xD40587, DTCClass_DtcClass_DTC_0xD4188F, DTCClass_DtcClass_DTC_0xD40687, DTCClass_DtcClass_DTC_0xD4438A, DTCClass_DtcClass_DTC_0xD43987, DTCClass_DtcClass_DTC_0xD44083, DTCClass_DtcClass_DTC_0xD42981, DTCClass_DtcClass_DTC_0xD43181, DTCClass_DtcClass_DTC_0xD40288, DTCClass_DtcClass_DTC_0xD44187, DTCClass_DtcClass_DTC_0x560C61, DTCClass_DtcClass_DTC_0x561092, DTCClass_DtcClass_DTC_0x560B78, DTCClass_DtcClass_DTC_0x560A54, DTCClass_DtcClass_DTC_0x560209, DTCClass_DtcClass_DTC_0x561792, DTCClass_DtcClass_DTC_0x560642, DTCClass_DtcClass_DTC_0xD4004B, DTCClass_DtcClass_DTC_0x560004, DTCClass_DtcClass_DTC_0x560747, DTCClass_DtcClass_DTC_0x561195, DTCClass_DtcClass_DTC_0x560106, DTCClass_DtcClass_DTC_0x560F76, DTCClass_DtcClass_DTC_0x561305, DTCClass_DtcClass_DTC_0x560E41, DTCClass_DtcClass_DTC_0x5609A3, DTCClass_DtcClass_DTC_0x5608A2, DTCClass_DtcClass_DTC_0x560D46, DTCClass_DtcClass_DTC_0xD41387, DTCClass_DtcClass_DTC_0xD4258F, DTCClass_DtcClass_DTC_0xD43281, DTCClass_DtcClass_DTC_0xD40188, DTCClass_DtcClass_DTC_0xD43481, DTCClass_DtcClass_DTC_0xD43581, DTCClass_DtcClass_DTC_0xD43381, DTCClass_DtcClass_DTC_0x561655, DTCClass_DtcClass_DTC_0x561583] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_J1939NodeId
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_J1939NodeId
  \brief  All J1939Nm/J1939NmConfigSet/J1939NmNode containers (as symbolic names) referenced by the DEM. Each DTC in the Dem_Cfg_DtcTable refers to a discontiguous range in this table. If there are DTCs without NmNode, there is an additional dummy entry at the end, which is then referred by the Dem_Cfg_DtcTable.
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_J1939NodeIdType, DEM_CONST) Dem_Cfg_J1939NodeId[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     J1939NodeId                              Comment                                                                                                      Referable Keys */
  /*     0 */ J1939NmConf_J1939NmNode_J1939NmNode ,  /* [DemJ1939NodeAddress]                                                                                 */  /* [DemDTCClass] */
  /*     1 */ 0                                      /* [Index DEM_CFG_J1939_NODE_INVALID: Invalid dummy entry for all DTCs without a valid NmNode reference] */  /* [DTCClass_DtcClass_DTC_0x560004, DTCClass_DtcClass_DTC_0x560106, DTCClass_DtcClass_DTC_0x560209, DTCClass_DtcClass_DTC_0x560642, DTCClass_DtcClass_DTC_0x560747, DTCClass_DtcClass_DTC_0x5608A2, DTCClass_DtcClass_DTC_0x5609A3, DTCClass_DtcClass_DTC_0x560A54, DTCClass_DtcClass_DTC_0x560B78, DTCClass_DtcClass_DTC_0x560C61, DTCClass_DtcClass_DTC_0x560D46, DTCClass_DtcClass_DTC_0x560E41, DTCClass_DtcClass_DTC_0x560F76, DTCClass_DtcClass_DTC_0x561092, DTCClass_DtcClass_DTC_0x561195, DTCClass_DtcClass_DTC_0x561305, DTCClass_DtcClass_DTC_0x561583, DTCClass_DtcClass_DTC_0x561655, DTCClass_DtcClass_DTC_0x561745, DTCClass_DtcClass_DTC_0x561792, DTCClass_DtcClass_DTC_0x561792_001, DTCClass_DtcClass_DTC_0xD4004B, DTCClass_DtcClass_DTC_0xD40188, DTCClass_DtcClass_DTC_0xD40288, DTCClass_DtcClass_DTC_0xD40387, DTCClass_DtcClass_DTC_0xD40487, DTCClass_DtcClass_DTC_0xD40587, DTCClass_DtcClass_DTC_0xD40687, DTCClass_DtcClass_DTC_0xD40787, DTCClass_DtcClass_DTC_0xD40887, DTCClass_DtcClass_DTC_0xD40987, DTCClass_DtcClass_DTC_0xD41087, DTCClass_DtcClass_DTC_0xD41187, DTCClass_DtcClass_DTC_0xD41287, DTCClass_DtcClass_DTC_0xD41387, DTCClass_DtcClass_DTC_0xD4158F, DTCClass_DtcClass_DTC_0xD4168F, DTCClass_DtcClass_DTC_0xD4178F, DTCClass_DtcClass_DTC_0xD4188F, DTCClass_DtcClass_DTC_0xD4198F, DTCClass_DtcClass_DTC_0xD4208F, DTCClass_DtcClass_DTC_0xD4218F, DTCClass_DtcClass_DTC_0xD4228F, DTCClass_DtcClass_DTC_0xD4238F, DTCClass_DtcClass_DTC_0xD4248F, DTCClass_DtcClass_DTC_0xD4258F, DTCClass_DtcClass_DTC_0xD42681, DTCClass_DtcClass_DTC_0xD42781, DTCClass_DtcClass_DTC_0xD42981, DTCClass_DtcClass_DTC_0xD43081, DTCClass_DtcClass_DTC_0xD43181, DTCClass_DtcClass_DTC_0xD43281, DTCClass_DtcClass_DTC_0xD43381, DTCClass_DtcClass_DTC_0xD43481, DTCClass_DtcClass_DTC_0xD43581, DTCClass_DtcClass_DTC_0xD43681, DTCClass_DtcClass_DTC_0xD43781, DTCClass_DtcClass_DTC_0xD43987, DTCClass_DtcClass_DTC_0xD44083, DTCClass_DtcClass_DTC_0xD44187, DTCClass_DtcClass_DTC_0xD4438A] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_J1939NodeIdInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_J1939NodeIdInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_J1939NodeId
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_J1939NodeIdIndType, DEM_CONST) Dem_Cfg_J1939NodeIdInd[62] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     J1939NodeIdInd      Referable Keys */
  /*     0 */              1u,  /* [DTCClass_DtcClass_DTC_0xD43681] */
  /*     1 */              1u,  /* [DTCClass_DtcClass_DTC_0xD43781] */
  /*     2 */              1u,  /* [DTCClass_DtcClass_DTC_0xD40787] */
  /*     3 */              1u,  /* [DTCClass_DtcClass_DTC_0xD4198F] */
  /*     4 */              1u,  /* [DTCClass_DtcClass_DTC_0xD43081] */
  /*     5 */              1u,  /* [DTCClass_DtcClass_DTC_0x561792_001] */
  /*     6 */              1u,  /* [DTCClass_DtcClass_DTC_0xD42681] */
  /*     7 */              1u,  /* [DTCClass_DtcClass_DTC_0xD42781] */
  /*     8 */              1u,  /* [DTCClass_DtcClass_DTC_0xD4238F] */
  /*     9 */              1u,  /* [DTCClass_DtcClass_DTC_0xD40887] */
  /*    10 */              1u,  /* [DTCClass_DtcClass_DTC_0xD4208F] */
  /*    11 */              1u,  /* [DTCClass_DtcClass_DTC_0xD41087] */
  /*    12 */              1u,  /* [DTCClass_DtcClass_DTC_0xD4218F] */
  /*    13 */              1u,  /* [DTCClass_DtcClass_DTC_0xD40987] */
  /*    14 */              1u,  /* [DTCClass_DtcClass_DTC_0xD4228F] */
  /*    15 */              1u,  /* [DTCClass_DtcClass_DTC_0xD41187] */
  /*    16 */              1u,  /* [DTCClass_DtcClass_DTC_0xD4248F] */
  /*    17 */              1u,  /* [DTCClass_DtcClass_DTC_0xD41287] */
  /*    18 */              1u,  /* [DTCClass_DtcClass_DTC_0x561745] */
  /*    19 */              1u,  /* [DTCClass_DtcClass_DTC_0xD4158F] */
  /*    20 */              1u,  /* [DTCClass_DtcClass_DTC_0xD40387] */
  /*    21 */              1u,  /* [DTCClass_DtcClass_DTC_0xD40487] */
  /*    22 */              1u,  /* [DTCClass_DtcClass_DTC_0xD4168F] */
  /*    23 */              1u,  /* [DTCClass_DtcClass_DTC_0xD4178F] */
  /*    24 */              1u,  /* [DTCClass_DtcClass_DTC_0xD40587] */
  /*    25 */              1u,  /* [DTCClass_DtcClass_DTC_0xD4188F] */
  /*    26 */              1u,  /* [DTCClass_DtcClass_DTC_0xD40687] */
  /*    27 */              1u,  /* [DTCClass_DtcClass_DTC_0xD4438A] */
  /*    28 */              1u,  /* [DTCClass_DtcClass_DTC_0xD43987] */
  /*    29 */              1u,  /* [DTCClass_DtcClass_DTC_0xD44083] */
  /*    30 */              1u,  /* [DTCClass_DtcClass_DTC_0xD42981] */
  /*    31 */              1u,  /* [DTCClass_DtcClass_DTC_0xD43181] */
  /*    32 */              1u,  /* [DTCClass_DtcClass_DTC_0xD40288] */
  /*    33 */              1u,  /* [DTCClass_DtcClass_DTC_0xD44187] */
  /*    34 */              1u,  /* [DTCClass_DtcClass_DTC_0x560C61] */
  /*    35 */              1u,  /* [DTCClass_DtcClass_DTC_0x561092] */
  /*    36 */              1u,  /* [DTCClass_DtcClass_DTC_0x560B78] */
  /*    37 */              1u,  /* [DTCClass_DtcClass_DTC_0x560A54] */
  /*    38 */              1u,  /* [DTCClass_DtcClass_DTC_0x560209] */
  /*    39 */              1u,  /* [DTCClass_DtcClass_DTC_0x561792] */
  /*    40 */              1u,  /* [DTCClass_DtcClass_DTC_0x560642] */
  /*    41 */              1u,  /* [DTCClass_DtcClass_DTC_0xD4004B] */
  /*    42 */              1u,  /* [DTCClass_DtcClass_DTC_0x560004] */
  /*    43 */              1u,  /* [DTCClass_DtcClass_DTC_0x560747] */
  /*    44 */              1u,  /* [DTCClass_DtcClass_DTC_0x561195] */
  /*    45 */              1u,  /* [DTCClass_DtcClass_DTC_0x560106] */
  /*    46 */              1u,  /* [DTCClass_DtcClass_DTC_0x560F76] */
  /*    47 */              1u,  /* [DTCClass_DtcClass_DTC_0x561305] */
  /*    48 */              1u,  /* [DTCClass_DtcClass_DTC_0x560E41] */
  /*    49 */              1u,  /* [DTCClass_DtcClass_DTC_0x5609A3] */
  /* Index     J1939NodeIdInd      Referable Keys */
  /*    50 */              1u,  /* [DTCClass_DtcClass_DTC_0x5608A2] */
  /*    51 */              1u,  /* [DTCClass_DtcClass_DTC_0x560D46] */
  /*    52 */              1u,  /* [DTCClass_DtcClass_DTC_0xD41387] */
  /*    53 */              1u,  /* [DTCClass_DtcClass_DTC_0xD4258F] */
  /*    54 */              1u,  /* [DTCClass_DtcClass_DTC_0xD43281] */
  /*    55 */              1u,  /* [DTCClass_DtcClass_DTC_0xD40188] */
  /*    56 */              1u,  /* [DTCClass_DtcClass_DTC_0xD43481] */
  /*    57 */              1u,  /* [DTCClass_DtcClass_DTC_0xD43581] */
  /*    58 */              1u,  /* [DTCClass_DtcClass_DTC_0xD43381] */
  /*    59 */              1u,  /* [DTCClass_DtcClass_DTC_0x561655] */
  /*    60 */              1u,  /* [DTCClass_DtcClass_DTC_0x561583] */
  /*    61 */              0u   /* [DemDTCClass] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_NvBlockDataPtr
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_NvBlockDataPtr
  \brief  The array contains these items: Admin, Status, 10 * Primary
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_NvDataPtrType, DEM_CONST) Dem_Cfg_NvBlockDataPtr[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     NvBlockDataPtr                                                                                 Comment */
  /*     0 */ (Dem_NvDataPtrType) &Dem_Cfg_GetAdminData()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_AdminData] */
  /*     1 */ (Dem_NvDataPtrType) &Dem_Cfg_GetStatusData()       /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_StatusData] */
  /*     2 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_0()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry0] */
  /*     3 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_1()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry1] */
  /*     4 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_2()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry2] */
  /*     5 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_3()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry3] */
  /*     6 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_4()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry4] */
  /*     7 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_5()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry5] */
  /*     8 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_6()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry6] */
  /*     9 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_7()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry7] */
  /*    10 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_8()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry8] */
  /*    11 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_9()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */   /* [Dem_PrimaryEntry9] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_NvBlockDataSize
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_NvBlockDataSize
  \brief  The array contains these items: Admin, Status, 10 * Primary
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_NvBlockDataSizeType, DEM_CONST) Dem_Cfg_NvBlockDataSize[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     NvBlockDataSize                                                        Comment */
  /*     0 */ (Dem_Cfg_NvBlockDataSizeType) sizeof(Dem_Cfg_GetAdminData())      ,  /* [Dem_AdminData] */
  /*     1 */ (Dem_Cfg_NvBlockDataSizeType) sizeof(Dem_Cfg_GetStatusData())     ,  /* [Dem_StatusData] */
  /*     2 */ (Dem_Cfg_NvBlockDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_0()) ,  /* [Dem_PrimaryEntry0] */
  /*     3 */ (Dem_Cfg_NvBlockDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_1()) ,  /* [Dem_PrimaryEntry1] */
  /*     4 */ (Dem_Cfg_NvBlockDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_2()) ,  /* [Dem_PrimaryEntry2] */
  /*     5 */ (Dem_Cfg_NvBlockDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_3()) ,  /* [Dem_PrimaryEntry3] */
  /*     6 */ (Dem_Cfg_NvBlockDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_4()) ,  /* [Dem_PrimaryEntry4] */
  /*     7 */ (Dem_Cfg_NvBlockDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_5()) ,  /* [Dem_PrimaryEntry5] */
  /*     8 */ (Dem_Cfg_NvBlockDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_6()) ,  /* [Dem_PrimaryEntry6] */
  /*     9 */ (Dem_Cfg_NvBlockDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_7()) ,  /* [Dem_PrimaryEntry7] */
  /*    10 */ (Dem_Cfg_NvBlockDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_8()) ,  /* [Dem_PrimaryEntry8] */
  /*    11 */ (Dem_Cfg_NvBlockDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_9())    /* [Dem_PrimaryEntry9] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_NvBlockId
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_NvBlockId
  \brief  The array contains these items: Admin, Status, 10 * Primary
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_NvBlockIdType, DEM_CONST) Dem_Cfg_NvBlockId[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     NvBlockId                                                              Comment */
  /*     0 */ NvMConf_NvMBlockDescriptor_DemAdminDataBlock /*NvMBlockId=8*/     ,  /* [Dem_AdminData] */
  /*     1 */ NvMConf_NvMBlockDescriptor_DemStatusDataBlock /*NvMBlockId=9*/    ,  /* [Dem_StatusData] */
  /*     2 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock0 /*NvMBlockId=10*/ ,  /* [Dem_PrimaryEntry0] */
  /*     3 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock1 /*NvMBlockId=11*/ ,  /* [Dem_PrimaryEntry1] */
  /*     4 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock2 /*NvMBlockId=12*/ ,  /* [Dem_PrimaryEntry2] */
  /*     5 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock3 /*NvMBlockId=13*/ ,  /* [Dem_PrimaryEntry3] */
  /*     6 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock4 /*NvMBlockId=14*/ ,  /* [Dem_PrimaryEntry4] */
  /*     7 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock5 /*NvMBlockId=15*/ ,  /* [Dem_PrimaryEntry5] */
  /*     8 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock6 /*NvMBlockId=16*/ ,  /* [Dem_PrimaryEntry6] */
  /*     9 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock7 /*NvMBlockId=17*/ ,  /* [Dem_PrimaryEntry7] */
  /*    10 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock8 /*NvMBlockId=18*/ ,  /* [Dem_PrimaryEntry8] */
  /*    11 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock9 /*NvMBlockId=19*/    /* [Dem_PrimaryEntry9] */
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEventEntryInit
**********************************************************************************************************************/
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_PrimaryEntryType, DEM_CONST) Dem_Cfg_PrimaryEventEntryInit = { 0 };  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_AdminData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_AdminDataType, DEM_NVM_DATA_CLEARED) Dem_Cfg_AdminData;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_CalibrationErrorRegister
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_CalibrationErrorRegister
  \brief  Variable is set when an inconsistency is detected due to calibrated values (during runtime) and can be read via measurement by customer.
*/ 
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_CalibrationErrorRegisterType, DEM_VAR_CLEARED) Dem_Cfg_CalibrationErrorRegister;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ClearDTCTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ClearDTCTable
  \brief  size = DEM_CFG_NUMBER_OF_CLEARDTCS
*/ 
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_ClearDTC_DataType, DEM_VAR_CLEARED) Dem_Cfg_ClearDTCTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_CommitBuffer
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_CommitBufferType, DEM_VAR_CLEARED) Dem_Cfg_CommitBuffer;  /* PRQA S 1514, 1533, 0759, 0759, 0759, 0759, 0759, 0759, 0759, 0759 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_MSR_Union, MD_MSR_Union, MD_MSR_Union, MD_MSR_Union, MD_MSR_Union, MD_MSR_Union, MD_MSR_Union, MD_MSR_Union */
#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DTCSelectorTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DTCSelectorTable
  \brief  size = DEM_CFG_NUMBER_OF_DTCSELECTORS
*/ 
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_DTCSelector_DataType, DEM_VAR_CLEARED) Dem_Cfg_DTCSelectorTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionFulfilled
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionFulfilled
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition ID. Table value: current condition state 'FALSE' not fulfilled, 'TRUE' fulfilled.
*/ 
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_EnableConditionFulfilledType, DEM_VAR_CLEARED) Dem_Cfg_EnableConditionFulfilled[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionGroupCounter
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionGroupCounter
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition group number. Table value: count of conditions in state 'enable'.
*/ 
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_EnableConditionGroupCounterType, DEM_VAR_CLEARED) Dem_Cfg_EnableConditionGroupCounter[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */

#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionGroupState
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionGroupState
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition group number. Table value: count of conditions in state 'enable'.
*/ 
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Cfg_EnableConditionGroupStateType, DEM_VAR_CLEARED) Dem_Cfg_EnableConditionGroupState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [#__Internal_ControlDtcSettingGroup, __Internal_ControlDtcSetting] */

#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventDataCommitNumber
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventDataCommitNumber
  \brief  Index = Index in Dem_Cfg_Eventtable
*/ 
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Cfg_EventDataCommitNumberType, DEM_VAR_CLEARED) Dem_Cfg_EventDataCommitNumber[63];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventInternalStatus
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventInternalStatus
  \brief  size = DEM_G_NUMBER_OF_EVENTS
*/ 
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Event_InternalStatusType, DEM_VAR_CLEARED) Dem_Cfg_EventInternalStatus[63];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [#EVENT_INVALID, #NoExtendedDataRecordConfigured] */
  /*     1 */  /* [ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     2 */  /* [ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     3 */  /* [AT_AMT_ECU_ETC2_03_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     4 */  /* [AT_AMT_ETC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     5 */  /* [AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     6 */  /* [Application_Interface_Lookup_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     7 */  /* [CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     8 */  /* [CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     9 */  /* [Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    10 */  /* [Cluster_ECU_ADAS_FN_STS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    11 */  /* [Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    12 */  /* [Cluster_ECU_CLS_Tx_4_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    13 */  /* [Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    14 */  /* [Cluster_ECU_CLS_Tx_16_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    15 */  /* [Cluster_ECU_OEL_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    16 */  /* [Cluster_ECU_OEL_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    17 */  /* [Cluster_ECU_TD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    18 */  /* [Cluster_ECU_TD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    19 */  /* [ECU_NVM_Corruption_Program_memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    20 */  /* [EMS_ECU_CCVS1_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    21 */  /* [EMS_ECU_CCVS1_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    22 */  /* [EMS_ECU_ETC2_00_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    23 */  /* [EMS_ECU_ETC2_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    24 */  /* [EMS_ECU_VD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    25 */  /* [EMS_ECU_VD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    26 */  /* [ESC_ECU_VDC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    27 */  /* [ESC_ECU_VDC2_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    28 */  /* [Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    29 */  /* [Front_Left_Side_Radar_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    30 */  /* [Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    31 */  /* [Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    32 */  /* [OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    33 */  /* [PCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    34 */  /* [PCAN_TimeSync_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    35 */  /* [Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    36 */  /* [Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    37 */  /* [Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    38 */  /* [Radar_Initial_Alignment_Missing_Calibration, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    39 */  /* [Radar_MMIC_Component_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    40 */  /* [Radar_MMIC_RFBIST_Component_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    41 */  /* [Radar_Module_General_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    42 */  /* [Radar_Module_Over_Temperature, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    43 */  /* [Radar_Module_System_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    44 */  /* [Radar_Module_Watchdog_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    45 */  /* [Radar_Mounting_Orientation_Incorrect_Assembly, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    46 */  /* [Radar_Performance_Capability_Algorithm_Based_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    47 */  /* [Radar_Pin_Position_Wrong_Mounting_Position, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    48 */  /* [Radar_Platform_Time_System_Programming_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    49 */  /* [Radar_SMC_General_Checksum_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /* Index        Referable Keys   RDR_01 */
  /*    50 */  /* [Radar_System_Battery_High_Voltage_System_Voltage_High, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    51 */  /* [Radar_System_Battery_Low_Voltage_System_Voltage_Low, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    52 */  /* [Radar_calibration_Calibration_or_Paramater_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    53 */  /* [SAS_ECU_SAS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    54 */  /* [SAS_ECU_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    55 */  /* [SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    56 */  /* [VCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    57 */  /* [VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    58 */  /* [VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    59 */  /* [VDC2_message_Yaw_rate_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    60 */  /* [Vehicle_DataSet_Not_Configured, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    61 */  /* [Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    62 */  /* [DemEventParameter, #NoExtendedDataRecordConfigured] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [#EVENT_INVALID, #NoExtendedDataRecordConfigured] */
  /*     1 */  /* [ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     2 */  /* [ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     3 */  /* [AT_AMT_ECU_ETC2_03_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     4 */  /* [AT_AMT_ETC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     5 */  /* [AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     6 */  /* [Application_Interface_Lookup_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     7 */  /* [CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     8 */  /* [CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     9 */  /* [Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    10 */  /* [Cluster_ECU_ADAS_FN_STS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    11 */  /* [Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    12 */  /* [Cluster_ECU_CLS_Tx_4_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    13 */  /* [Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    14 */  /* [Cluster_ECU_CLS_Tx_16_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    15 */  /* [Cluster_ECU_OEL_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    16 */  /* [Cluster_ECU_OEL_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    17 */  /* [Cluster_ECU_TD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    18 */  /* [Cluster_ECU_TD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    19 */  /* [ECU_NVM_Corruption_Program_memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    20 */  /* [EMS_ECU_CCVS1_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    21 */  /* [EMS_ECU_CCVS1_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    22 */  /* [EMS_ECU_ETC2_00_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    23 */  /* [EMS_ECU_ETC2_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    24 */  /* [EMS_ECU_VD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    25 */  /* [EMS_ECU_VD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    26 */  /* [ESC_ECU_VDC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    27 */  /* [ESC_ECU_VDC2_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    28 */  /* [Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    29 */  /* [Front_Left_Side_Radar_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    30 */  /* [Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    31 */  /* [Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    32 */  /* [OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    33 */  /* [PCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    34 */  /* [PCAN_TimeSync_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    35 */  /* [Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    36 */  /* [Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    37 */  /* [Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    38 */  /* [Radar_Initial_Alignment_Missing_Calibration, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    39 */  /* [Radar_MMIC_Component_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    40 */  /* [Radar_MMIC_RFBIST_Component_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    41 */  /* [Radar_Module_General_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    42 */  /* [Radar_Module_Over_Temperature, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    43 */  /* [Radar_Module_System_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    44 */  /* [Radar_Module_Watchdog_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    45 */  /* [Radar_Mounting_Orientation_Incorrect_Assembly, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    46 */  /* [Radar_Performance_Capability_Algorithm_Based_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    47 */  /* [Radar_Pin_Position_Wrong_Mounting_Position, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    48 */  /* [Radar_Platform_Time_System_Programming_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    49 */  /* [Radar_SMC_General_Checksum_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /* Index        Referable Keys   RDR_02 */
  /*    50 */  /* [Radar_System_Battery_High_Voltage_System_Voltage_High, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    51 */  /* [Radar_System_Battery_Low_Voltage_System_Voltage_Low, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    52 */  /* [Radar_calibration_Calibration_or_Paramater_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    53 */  /* [SAS_ECU_SAS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    54 */  /* [SAS_ECU_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    55 */  /* [SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    56 */  /* [VCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    57 */  /* [VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    58 */  /* [VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    59 */  /* [VDC2_message_Yaw_rate_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    60 */  /* [Vehicle_DataSet_Not_Configured, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    61 */  /* [Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    62 */  /* [DemEventParameter, #NoExtendedDataRecordConfigured] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [#EVENT_INVALID, #NoExtendedDataRecordConfigured] */
  /*     1 */  /* [ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     2 */  /* [ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     3 */  /* [AT_AMT_ECU_ETC2_03_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     4 */  /* [AT_AMT_ETC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     5 */  /* [AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     6 */  /* [Application_Interface_Lookup_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     7 */  /* [CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     8 */  /* [CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     9 */  /* [Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    10 */  /* [Cluster_ECU_ADAS_FN_STS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    11 */  /* [Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    12 */  /* [Cluster_ECU_CLS_Tx_4_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    13 */  /* [Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    14 */  /* [Cluster_ECU_CLS_Tx_16_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    15 */  /* [Cluster_ECU_OEL_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    16 */  /* [Cluster_ECU_OEL_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    17 */  /* [Cluster_ECU_TD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    18 */  /* [Cluster_ECU_TD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    19 */  /* [ECU_NVM_Corruption_Program_memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    20 */  /* [EMS_ECU_CCVS1_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    21 */  /* [EMS_ECU_CCVS1_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    22 */  /* [EMS_ECU_ETC2_00_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    23 */  /* [EMS_ECU_ETC2_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    24 */  /* [EMS_ECU_VD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    25 */  /* [EMS_ECU_VD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    26 */  /* [ESC_ECU_VDC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    27 */  /* [ESC_ECU_VDC2_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    28 */  /* [Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    29 */  /* [Front_Left_Side_Radar_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    30 */  /* [Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    31 */  /* [Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    32 */  /* [OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    33 */  /* [PCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    34 */  /* [PCAN_TimeSync_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    35 */  /* [Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    36 */  /* [Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    37 */  /* [Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    38 */  /* [Radar_Initial_Alignment_Missing_Calibration, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    39 */  /* [Radar_MMIC_Component_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    40 */  /* [Radar_MMIC_RFBIST_Component_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    41 */  /* [Radar_Module_General_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    42 */  /* [Radar_Module_Over_Temperature, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    43 */  /* [Radar_Module_System_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    44 */  /* [Radar_Module_Watchdog_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    45 */  /* [Radar_Mounting_Orientation_Incorrect_Assembly, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    46 */  /* [Radar_Performance_Capability_Algorithm_Based_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    47 */  /* [Radar_Pin_Position_Wrong_Mounting_Position, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    48 */  /* [Radar_Platform_Time_System_Programming_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    49 */  /* [Radar_SMC_General_Checksum_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /* Index        Referable Keys   RDR_03 */
  /*    50 */  /* [Radar_System_Battery_High_Voltage_System_Voltage_High, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    51 */  /* [Radar_System_Battery_Low_Voltage_System_Voltage_Low, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    52 */  /* [Radar_calibration_Calibration_or_Paramater_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    53 */  /* [SAS_ECU_SAS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    54 */  /* [SAS_ECU_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    55 */  /* [SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    56 */  /* [VCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    57 */  /* [VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    58 */  /* [VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    59 */  /* [VDC2_message_Yaw_rate_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    60 */  /* [Vehicle_DataSet_Not_Configured, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    61 */  /* [Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    62 */  /* [DemEventParameter, #NoExtendedDataRecordConfigured] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [#EVENT_INVALID, #NoExtendedDataRecordConfigured] */
  /*     1 */  /* [ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     2 */  /* [ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     3 */  /* [AT_AMT_ECU_ETC2_03_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     4 */  /* [AT_AMT_ETC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     5 */  /* [AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     6 */  /* [Application_Interface_Lookup_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     7 */  /* [CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     8 */  /* [CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     9 */  /* [Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    10 */  /* [Cluster_ECU_ADAS_FN_STS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    11 */  /* [Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    12 */  /* [Cluster_ECU_CLS_Tx_4_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    13 */  /* [Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    14 */  /* [Cluster_ECU_CLS_Tx_16_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    15 */  /* [Cluster_ECU_OEL_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    16 */  /* [Cluster_ECU_OEL_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    17 */  /* [Cluster_ECU_TD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    18 */  /* [Cluster_ECU_TD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    19 */  /* [ECU_NVM_Corruption_Program_memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    20 */  /* [EMS_ECU_CCVS1_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    21 */  /* [EMS_ECU_CCVS1_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    22 */  /* [EMS_ECU_ETC2_00_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    23 */  /* [EMS_ECU_ETC2_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    24 */  /* [EMS_ECU_VD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    25 */  /* [EMS_ECU_VD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    26 */  /* [ESC_ECU_VDC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    27 */  /* [ESC_ECU_VDC2_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    28 */  /* [Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    29 */  /* [Front_Left_Side_Radar_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    30 */  /* [Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    31 */  /* [Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    32 */  /* [OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    33 */  /* [PCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    34 */  /* [PCAN_TimeSync_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    35 */  /* [Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    36 */  /* [Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    37 */  /* [Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    38 */  /* [Radar_Initial_Alignment_Missing_Calibration, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    39 */  /* [Radar_MMIC_Component_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    40 */  /* [Radar_MMIC_RFBIST_Component_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    41 */  /* [Radar_Module_General_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    42 */  /* [Radar_Module_Over_Temperature, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    43 */  /* [Radar_Module_System_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    44 */  /* [Radar_Module_Watchdog_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    45 */  /* [Radar_Mounting_Orientation_Incorrect_Assembly, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    46 */  /* [Radar_Performance_Capability_Algorithm_Based_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    47 */  /* [Radar_Pin_Position_Wrong_Mounting_Position, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    48 */  /* [Radar_Platform_Time_System_Programming_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    49 */  /* [Radar_SMC_General_Checksum_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /* Index        Referable Keys   RDR_04 */
  /*    50 */  /* [Radar_System_Battery_High_Voltage_System_Voltage_High, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    51 */  /* [Radar_System_Battery_Low_Voltage_System_Voltage_Low, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    52 */  /* [Radar_calibration_Calibration_or_Paramater_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    53 */  /* [SAS_ECU_SAS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    54 */  /* [SAS_ECU_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    55 */  /* [SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    56 */  /* [VCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    57 */  /* [VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    58 */  /* [VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    59 */  /* [VDC2_message_Yaw_rate_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    60 */  /* [Vehicle_DataSet_Not_Configured, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    61 */  /* [Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    62 */  /* [DemEventParameter, #NoExtendedDataRecordConfigured] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [#EVENT_INVALID, #NoExtendedDataRecordConfigured] */
  /*     1 */  /* [ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     2 */  /* [ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     3 */  /* [AT_AMT_ECU_ETC2_03_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     4 */  /* [AT_AMT_ETC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     5 */  /* [AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     6 */  /* [Application_Interface_Lookup_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     7 */  /* [CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     8 */  /* [CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     9 */  /* [Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    10 */  /* [Cluster_ECU_ADAS_FN_STS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    11 */  /* [Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    12 */  /* [Cluster_ECU_CLS_Tx_4_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    13 */  /* [Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    14 */  /* [Cluster_ECU_CLS_Tx_16_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    15 */  /* [Cluster_ECU_OEL_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    16 */  /* [Cluster_ECU_OEL_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    17 */  /* [Cluster_ECU_TD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    18 */  /* [Cluster_ECU_TD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    19 */  /* [ECU_NVM_Corruption_Program_memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    20 */  /* [EMS_ECU_CCVS1_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    21 */  /* [EMS_ECU_CCVS1_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    22 */  /* [EMS_ECU_ETC2_00_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    23 */  /* [EMS_ECU_ETC2_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    24 */  /* [EMS_ECU_VD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    25 */  /* [EMS_ECU_VD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    26 */  /* [ESC_ECU_VDC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    27 */  /* [ESC_ECU_VDC2_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    28 */  /* [Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    29 */  /* [Front_Left_Side_Radar_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    30 */  /* [Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    31 */  /* [Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    32 */  /* [OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    33 */  /* [PCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    34 */  /* [PCAN_TimeSync_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    35 */  /* [Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    36 */  /* [Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    37 */  /* [Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    38 */  /* [Radar_Initial_Alignment_Missing_Calibration, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    39 */  /* [Radar_MMIC_Component_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    40 */  /* [Radar_MMIC_RFBIST_Component_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    41 */  /* [Radar_Module_General_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    42 */  /* [Radar_Module_Over_Temperature, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    43 */  /* [Radar_Module_System_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    44 */  /* [Radar_Module_Watchdog_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    45 */  /* [Radar_Mounting_Orientation_Incorrect_Assembly, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    46 */  /* [Radar_Performance_Capability_Algorithm_Based_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    47 */  /* [Radar_Pin_Position_Wrong_Mounting_Position, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    48 */  /* [Radar_Platform_Time_System_Programming_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    49 */  /* [Radar_SMC_General_Checksum_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /* Index        Referable Keys   RDR_05 */
  /*    50 */  /* [Radar_System_Battery_High_Voltage_System_Voltage_High, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    51 */  /* [Radar_System_Battery_Low_Voltage_System_Voltage_Low, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    52 */  /* [Radar_calibration_Calibration_or_Paramater_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    53 */  /* [SAS_ECU_SAS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    54 */  /* [SAS_ECU_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    55 */  /* [SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    56 */  /* [VCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    57 */  /* [VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    58 */  /* [VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    59 */  /* [VDC2_message_Yaw_rate_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    60 */  /* [Vehicle_DataSet_Not_Configured, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    61 */  /* [Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    62 */  /* [DemEventParameter, #NoExtendedDataRecordConfigured] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [#EVENT_INVALID, #NoExtendedDataRecordConfigured] */
  /*     1 */  /* [ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     2 */  /* [ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     3 */  /* [AT_AMT_ECU_ETC2_03_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     4 */  /* [AT_AMT_ETC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     5 */  /* [AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     6 */  /* [Application_Interface_Lookup_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     7 */  /* [CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     8 */  /* [CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     9 */  /* [Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    10 */  /* [Cluster_ECU_ADAS_FN_STS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    11 */  /* [Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    12 */  /* [Cluster_ECU_CLS_Tx_4_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    13 */  /* [Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    14 */  /* [Cluster_ECU_CLS_Tx_16_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    15 */  /* [Cluster_ECU_OEL_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    16 */  /* [Cluster_ECU_OEL_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    17 */  /* [Cluster_ECU_TD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    18 */  /* [Cluster_ECU_TD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    19 */  /* [ECU_NVM_Corruption_Program_memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    20 */  /* [EMS_ECU_CCVS1_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    21 */  /* [EMS_ECU_CCVS1_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    22 */  /* [EMS_ECU_ETC2_00_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    23 */  /* [EMS_ECU_ETC2_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    24 */  /* [EMS_ECU_VD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    25 */  /* [EMS_ECU_VD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    26 */  /* [ESC_ECU_VDC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    27 */  /* [ESC_ECU_VDC2_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    28 */  /* [Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    29 */  /* [Front_Left_Side_Radar_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    30 */  /* [Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    31 */  /* [Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    32 */  /* [OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    33 */  /* [PCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    34 */  /* [PCAN_TimeSync_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    35 */  /* [Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    36 */  /* [Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    37 */  /* [Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    38 */  /* [Radar_Initial_Alignment_Missing_Calibration, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    39 */  /* [Radar_MMIC_Component_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    40 */  /* [Radar_MMIC_RFBIST_Component_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    41 */  /* [Radar_Module_General_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    42 */  /* [Radar_Module_Over_Temperature, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    43 */  /* [Radar_Module_System_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    44 */  /* [Radar_Module_Watchdog_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    45 */  /* [Radar_Mounting_Orientation_Incorrect_Assembly, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    46 */  /* [Radar_Performance_Capability_Algorithm_Based_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    47 */  /* [Radar_Pin_Position_Wrong_Mounting_Position, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    48 */  /* [Radar_Platform_Time_System_Programming_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    49 */  /* [Radar_SMC_General_Checksum_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /* Index        Referable Keys   RDR_06 */
  /*    50 */  /* [Radar_System_Battery_High_Voltage_System_Voltage_High, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    51 */  /* [Radar_System_Battery_Low_Voltage_System_Voltage_Low, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    52 */  /* [Radar_calibration_Calibration_or_Paramater_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    53 */  /* [SAS_ECU_SAS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    54 */  /* [SAS_ECU_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    55 */  /* [SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    56 */  /* [VCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    57 */  /* [VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    58 */  /* [VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    59 */  /* [VDC2_message_Yaw_rate_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    60 */  /* [Vehicle_DataSet_Not_Configured, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    61 */  /* [Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    62 */  /* [DemEventParameter, #NoExtendedDataRecordConfigured] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [#EVENT_INVALID, #NoExtendedDataRecordConfigured] */
  /*     1 */  /* [ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     2 */  /* [ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     3 */  /* [AT_AMT_ECU_ETC2_03_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     4 */  /* [AT_AMT_ETC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     5 */  /* [AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     6 */  /* [Application_Interface_Lookup_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     7 */  /* [CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     8 */  /* [CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     9 */  /* [Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    10 */  /* [Cluster_ECU_ADAS_FN_STS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    11 */  /* [Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    12 */  /* [Cluster_ECU_CLS_Tx_4_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    13 */  /* [Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    14 */  /* [Cluster_ECU_CLS_Tx_16_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    15 */  /* [Cluster_ECU_OEL_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    16 */  /* [Cluster_ECU_OEL_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    17 */  /* [Cluster_ECU_TD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    18 */  /* [Cluster_ECU_TD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    19 */  /* [ECU_NVM_Corruption_Program_memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    20 */  /* [EMS_ECU_CCVS1_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    21 */  /* [EMS_ECU_CCVS1_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    22 */  /* [EMS_ECU_ETC2_00_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    23 */  /* [EMS_ECU_ETC2_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    24 */  /* [EMS_ECU_VD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    25 */  /* [EMS_ECU_VD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    26 */  /* [ESC_ECU_VDC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    27 */  /* [ESC_ECU_VDC2_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    28 */  /* [Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    29 */  /* [Front_Left_Side_Radar_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    30 */  /* [Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    31 */  /* [Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    32 */  /* [OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    33 */  /* [PCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    34 */  /* [PCAN_TimeSync_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    35 */  /* [Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    36 */  /* [Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    37 */  /* [Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    38 */  /* [Radar_Initial_Alignment_Missing_Calibration, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    39 */  /* [Radar_MMIC_Component_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    40 */  /* [Radar_MMIC_RFBIST_Component_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    41 */  /* [Radar_Module_General_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    42 */  /* [Radar_Module_Over_Temperature, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    43 */  /* [Radar_Module_System_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    44 */  /* [Radar_Module_Watchdog_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    45 */  /* [Radar_Mounting_Orientation_Incorrect_Assembly, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    46 */  /* [Radar_Performance_Capability_Algorithm_Based_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    47 */  /* [Radar_Pin_Position_Wrong_Mounting_Position, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    48 */  /* [Radar_Platform_Time_System_Programming_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    49 */  /* [Radar_SMC_General_Checksum_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /* Index        Referable Keys   RDR_07 */
  /*    50 */  /* [Radar_System_Battery_High_Voltage_System_Voltage_High, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    51 */  /* [Radar_System_Battery_Low_Voltage_System_Voltage_Low, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    52 */  /* [Radar_calibration_Calibration_or_Paramater_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    53 */  /* [SAS_ECU_SAS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    54 */  /* [SAS_ECU_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    55 */  /* [SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    56 */  /* [VCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    57 */  /* [VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    58 */  /* [VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    59 */  /* [VDC2_message_Yaw_rate_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    60 */  /* [Vehicle_DataSet_Not_Configured, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    61 */  /* [Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    62 */  /* [DemEventParameter, #NoExtendedDataRecordConfigured] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [#EVENT_INVALID, #NoExtendedDataRecordConfigured] */
  /*     1 */  /* [ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     2 */  /* [ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     3 */  /* [AT_AMT_ECU_ETC2_03_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     4 */  /* [AT_AMT_ETC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     5 */  /* [AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     6 */  /* [Application_Interface_Lookup_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     7 */  /* [CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     8 */  /* [CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*     9 */  /* [Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    10 */  /* [Cluster_ECU_ADAS_FN_STS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    11 */  /* [Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    12 */  /* [Cluster_ECU_CLS_Tx_4_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    13 */  /* [Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    14 */  /* [Cluster_ECU_CLS_Tx_16_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    15 */  /* [Cluster_ECU_OEL_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    16 */  /* [Cluster_ECU_OEL_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    17 */  /* [Cluster_ECU_TD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    18 */  /* [Cluster_ECU_TD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    19 */  /* [ECU_NVM_Corruption_Program_memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    20 */  /* [EMS_ECU_CCVS1_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    21 */  /* [EMS_ECU_CCVS1_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    22 */  /* [EMS_ECU_ETC2_00_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    23 */  /* [EMS_ECU_ETC2_erratic_communication_Erractic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    24 */  /* [EMS_ECU_VD_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    25 */  /* [EMS_ECU_VD_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    26 */  /* [ESC_ECU_VDC2_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    27 */  /* [ESC_ECU_VDC2_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    28 */  /* [Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    29 */  /* [Front_Left_Side_Radar_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    30 */  /* [Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    31 */  /* [Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    32 */  /* [OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    33 */  /* [PCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    34 */  /* [PCAN_TimeSync_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    35 */  /* [Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    36 */  /* [Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    37 */  /* [Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    38 */  /* [Radar_Initial_Alignment_Missing_Calibration, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    39 */  /* [Radar_MMIC_Component_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    40 */  /* [Radar_MMIC_RFBIST_Component_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    41 */  /* [Radar_Module_General_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    42 */  /* [Radar_Module_Over_Temperature, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    43 */  /* [Radar_Module_System_Internal_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    44 */  /* [Radar_Module_Watchdog_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    45 */  /* [Radar_Mounting_Orientation_Incorrect_Assembly, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    46 */  /* [Radar_Performance_Capability_Algorithm_Based_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    47 */  /* [Radar_Pin_Position_Wrong_Mounting_Position, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    48 */  /* [Radar_Platform_Time_System_Programming_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    49 */  /* [Radar_SMC_General_Checksum_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /* Index        Referable Keys   RDR_08 */
  /*    50 */  /* [Radar_System_Battery_High_Voltage_System_Voltage_High, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    51 */  /* [Radar_System_Battery_Low_Voltage_System_Voltage_Low, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    52 */  /* [Radar_calibration_Calibration_or_Paramater_Memory_Failure, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    53 */  /* [SAS_ECU_SAS_message_Missing_Message, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    54 */  /* [SAS_ECU_erratic_communication_Erratic, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    55 */  /* [SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    56 */  /* [VCAN_Communication_Bus_Off, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    57 */  /* [VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    58 */  /* [VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    59 */  /* [VDC2_message_Yaw_rate_Invalid_Serial_Data_Received, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    60 */  /* [Vehicle_DataSet_Not_Configured, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    61 */  /* [Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect, #EdrExtendedDataRecord_OccurrenceCounter, #EdrExtendedDataRecord_AgingCounter] */
  /*    62 */  /* [DemEventParameter, #NoExtendedDataRecordConfigured] */

#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ExtendedDataRecordIteratorTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ExtendedDataRecordIteratorTable
  \brief  size = 1
*/ 
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_ExtendedDataRecordIterator_FilterType, DEM_VAR_CLEARED) Dem_Cfg_ExtendedDataRecordIteratorTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FilterInfoTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FilterInfoTable
  \brief  size = DEM_CFG_NUMBER_OF_FILTER
*/ 
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_FilterData_InfoType, DEM_VAR_CLEARED) Dem_Cfg_FilterInfoTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FreezeFrameIteratorTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FreezeFrameIteratorTable
  \brief  size = DEM_CFG_NUMBER_OF_FREEZEFRAMEITERATORS
*/ 
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_FreezeFrameIterator_FilterType, DEM_VAR_CLEARED) Dem_Cfg_FreezeFrameIteratorTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryCurrentCount
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_MemoryCurrentCountType, DEM_VAR_CLEARED) Dem_Cfg_MemoryCurrentCount[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryStatus
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryStatus
  \brief  The array contains these items: Admin, Status, 10 * Primary
*/ 
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_MemoryStatusType, DEM_VAR_CLEARED) Dem_Cfg_MemoryStatus[12];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryChronology
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_PrimaryChronology
  \brief  size = DEM_CFG_GLOBAL_PRIMARY_SIZE
*/ 
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_EntryIndexType, DEM_VAR_CLEARED) Dem_Cfg_PrimaryChronology[10];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_0
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_0;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_1
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_1;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_2
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_2;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_3
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_3;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_4
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_4;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_5
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_5;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_6
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_6;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_7
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_7;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_8
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_8;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_9
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_9;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ReadoutBuffer
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_ReadoutBufferEntryType, DEM_VAR_CLEARED) Dem_Cfg_ReadoutBuffer[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ReportedEventsOfFilter
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ReportedEventsOfFilter
  \brief  size = DEM_CFG_NUMBER_OF_FILTER
*/ 
#define DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_ReportedEventsType, DEM_VAR_CLEARED) Dem_Cfg_ReportedEventsOfFilter[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SatelliteInfoInvalid_OsApplication
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_SatelliteInfoInvalid_OsApplication
  \brief  Buffer for satellite data on OsApplication "Invalid_OsApplication"
*/ 
#define DEM_START_SEC_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_SatelliteInfoTypeInvalid_OsApplication, DEM_VAR_CLEARED) Dem_Cfg_SatelliteInfoInvalid_OsApplication;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_StatusData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_StatusDataType, DEM_NVM_DATA_CLEARED) Dem_Cfg_StatusData;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_PCConfig
**********************************************************************************************************************/
/** 
  \var    Dem_PCConfig
  \details
  Element                    Description
  EventAvailableInVariant    the pointer to Dem_Cfg_EventAvailableInVariant
  ConfigurationId            Magic constant derived from the configuration parameters /Dem/DemGeneral/DemCompiledConfigId and /Dem/DemGeneral/DemCompiledPostbuildCrc. Each value change is evidence to incompatible NV stored data and triggers a re-initialization of the NV data.
*/ 
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_PCConfigsType, DEM_CONST) Dem_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_RDR_01] */
      Dem_Cfg_EventAvailableInVariantRDR_01  /**< the pointer to Dem_Cfg_EventAvailableInVariant in Config_RDR_01 */
    , 0x7E73u
  },
  { /* Index: 1 Keys: [Config_RDR_02] */
      Dem_Cfg_EventAvailableInVariantRDR_02  /**< the pointer to Dem_Cfg_EventAvailableInVariant in Config_RDR_02 */
    , 0x0E82u
  },
  { /* Index: 2 Keys: [Config_RDR_03] */
      Dem_Cfg_EventAvailableInVariantRDR_02  /**< the pointer to Dem_Cfg_EventAvailableInVariant in Config_RDR_03 */
    , 0x0E83u
  },
  { /* Index: 3 Keys: [Config_RDR_04] */
      Dem_Cfg_EventAvailableInVariantRDR_04  /**< the pointer to Dem_Cfg_EventAvailableInVariant in Config_RDR_04 */
    , 0x8FACu
  },
  { /* Index: 4 Keys: [Config_RDR_05] */
      Dem_Cfg_EventAvailableInVariantRDR_02  /**< the pointer to Dem_Cfg_EventAvailableInVariant in Config_RDR_05 */
    , 0x0E85u
  },
  { /* Index: 5 Keys: [Config_RDR_06] */
      Dem_Cfg_EventAvailableInVariantRDR_02  /**< the pointer to Dem_Cfg_EventAvailableInVariant in Config_RDR_06 */
    , 0x0E86u
  },
  { /* Index: 6 Keys: [Config_RDR_07] */
      Dem_Cfg_EventAvailableInVariantRDR_02  /**< the pointer to Dem_Cfg_EventAvailableInVariant in Config_RDR_07 */
    , 0x0E87u
  },
  { /* Index: 7 Keys: [Config_RDR_08] */
      Dem_Cfg_EventAvailableInVariantRDR_02  /**< the pointer to Dem_Cfg_EventAvailableInVariant in Config_RDR_08 */
    , 0x0E88u
  }
};
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/



/**********************************************************************************************************************
  END OF FILE: Dem_Lcfg.c     [Vector, VARIANT-POSTBUILD-SELECTABLE, 29.03.00.234032]
**********************************************************************************************************************/

