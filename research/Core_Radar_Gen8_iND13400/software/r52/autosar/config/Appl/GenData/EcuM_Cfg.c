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
 *            Module: EcuM
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EcuM_Cfg.c
 *   Generation Time: 2026-08-27 14:12:14
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



/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* PRQA S 0310 EOF */ /* MD_CSL_0310 */
#include "EcuM.h"

#define ECUM_PRIVATE_CFG_PARTLY_INCLUDE
#include "EcuM_PrivateCfg.h"
#undef ECUM_PRIVATE_CFG_PARTLY_INCLUDE /* PRQA S 0841 */ /* MD_EcuM_0841 */

#if((ECUM_CHANNELOFCOMMCHANNELREFS == STD_ON) || (ECUM_PNCOFCOMMPNCREFS == STD_ON) || (ECUM_SUPPORT_COMM == STD_ON))
#include "ComM.h"
#endif

#if !defined (ECUM_LOCAL) /* COV_ECUM_LOCAL */
# define ECUM_LOCAL static
#endif

#if !defined (ECUM_LOCAL_INLINE) /* COV_ECUM_LOCAL_INLINE */
# define ECUM_LOCAL_INLINE LOCAL_INLINE
#endif 

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  EcuM_ComMChannelRefs
**********************************************************************************************************************/
/** 
  \var    EcuM_ComMChannelRefs
  \brief  Referenced ComM Channel(s).
  \details
  Element    Description
  Channel    Referenced ComM Channel(s) per WakeupSource
*/ 
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_ComMChannelRefsType, ECUM_CONST) EcuM_ComMChannelRefs[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Channel                                               Comment                                 Referable Keys */
  { /*     0 */    ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1 },  /* [CN_PCAN_RADAR_458ff0f1]    */  /* [WS_CN_PCAN_RADAR_458ff0f1, /ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_PCAN_RADAR_458ff0f1] */
  { /*     1 */    ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6 },  /* [CN_VCAN_RADAR_489180b6]    */  /* [WS_CN_VCAN_RADAR_489180b6, /ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_VCAN_RADAR_489180b6] */
  { /*     2 */ ComMConf_ComMChannel_cnctr_RDR_RdrNet_5172a59b }   /* [cnctr_RDR_RdrNet_5172a59b] */  /* [WS_cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/cnctr_RDR_RdrNet_5172a59b] */
};
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_DriverInitOneFctPtrRDR_01
**********************************************************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverFuncType, ECUM_CONST) EcuM_DriverInitOneFctPtrRDR_01 = EcuM_AL_DriverInitOne_RDR_01;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_DriverInitOneFctPtrRDR_02
**********************************************************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverFuncType, ECUM_CONST) EcuM_DriverInitOneFctPtrRDR_02 = EcuM_AL_DriverInitOne_RDR_02;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_DriverInitOneFctPtrRDR_03
**********************************************************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverFuncType, ECUM_CONST) EcuM_DriverInitOneFctPtrRDR_03 = EcuM_AL_DriverInitOne_RDR_03;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_DriverInitOneFctPtrRDR_04
**********************************************************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverFuncType, ECUM_CONST) EcuM_DriverInitOneFctPtrRDR_04 = EcuM_AL_DriverInitOne_RDR_04;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_DriverInitOneFctPtrRDR_05
**********************************************************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverFuncType, ECUM_CONST) EcuM_DriverInitOneFctPtrRDR_05 = EcuM_AL_DriverInitOne_RDR_05;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_DriverInitOneFctPtrRDR_06
**********************************************************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverFuncType, ECUM_CONST) EcuM_DriverInitOneFctPtrRDR_06 = EcuM_AL_DriverInitOne_RDR_06;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_DriverInitOneFctPtrRDR_07
**********************************************************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverFuncType, ECUM_CONST) EcuM_DriverInitOneFctPtrRDR_07 = EcuM_AL_DriverInitOne_RDR_07;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_DriverInitOneFctPtrRDR_08
**********************************************************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverFuncType, ECUM_CONST) EcuM_DriverInitOneFctPtrRDR_08 = EcuM_AL_DriverInitOne_RDR_08;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    EcuM_PartitionIdentifiers
  \brief  the partition context in Config_RDR_01
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to EcuM_PCPartitionConfig
*/ 
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_PartitionIdentifiersType, ECUM_CONST) EcuM_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV          PCPartitionConfigIdx */
  { /*     0 */ ECUM_SINGLEPARTITION,                   0u }
};
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_WakeupSourceList
**********************************************************************************************************************/
/** 
  \var    EcuM_WakeupSourceList
  \brief  Contains all parameters configured for Wakeup Sources
  \details
  Element                    Description
  ComMChannelRefsEndIdx      the end index of the 0:n relation pointing to EcuM_ComMChannelRefs
  ComMChannelRefsStartIdx    the start index of the 0:n relation pointing to EcuM_ComMChannelRefs
*/ 
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_WakeupSourceListType, ECUM_CONST) EcuM_WakeupSourceList[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ComMChannelRefsEndIdx                            ComMChannelRefsStartIdx                                  Comment                                    Referable Keys */
  { /*     0 */ ECUM_NO_COMMCHANNELREFSENDIDXOFWAKEUPSOURCELIST, ECUM_NO_COMMCHANNELREFSSTARTIDXOFWAKEUPSOURCELIST },  /* [ECUM_WKSOURCE_POWER]          */  /* [WS_ECUM_WKSOURCE_POWER, /ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_POWER] */
  { /*     1 */ ECUM_NO_COMMCHANNELREFSENDIDXOFWAKEUPSOURCELIST, ECUM_NO_COMMCHANNELREFSSTARTIDXOFWAKEUPSOURCELIST },  /* [ECUM_WKSOURCE_RESET]          */  /* [WS_ECUM_WKSOURCE_RESET, /ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_RESET] */
  { /*     2 */ ECUM_NO_COMMCHANNELREFSENDIDXOFWAKEUPSOURCELIST, ECUM_NO_COMMCHANNELREFSSTARTIDXOFWAKEUPSOURCELIST },  /* [ECUM_WKSOURCE_INTERNAL_RESET] */  /* [WS_ECUM_WKSOURCE_INTERNAL_RESET, /ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_INTERNAL_RESET] */
  { /*     3 */ ECUM_NO_COMMCHANNELREFSENDIDXOFWAKEUPSOURCELIST, ECUM_NO_COMMCHANNELREFSSTARTIDXOFWAKEUPSOURCELIST },  /* [ECUM_WKSOURCE_INTERNAL_WDG]   */  /* [WS_ECUM_WKSOURCE_INTERNAL_WDG, /ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_INTERNAL_WDG] */
  { /*     4 */ ECUM_NO_COMMCHANNELREFSENDIDXOFWAKEUPSOURCELIST, ECUM_NO_COMMCHANNELREFSSTARTIDXOFWAKEUPSOURCELIST },  /* [ECUM_WKSOURCE_EXTERNAL_WDG]   */  /* [WS_ECUM_WKSOURCE_EXTERNAL_WDG, /ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_EXTERNAL_WDG] */
  { /*     5 */                                              1u,                                                0u },  /* [CN_PCAN_RADAR_458ff0f1]       */  /* [WS_CN_PCAN_RADAR_458ff0f1, /ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_PCAN_RADAR_458ff0f1] */
  { /*     6 */                                              2u,                                                1u },  /* [CN_VCAN_RADAR_489180b6]       */  /* [WS_CN_VCAN_RADAR_489180b6, /ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_VCAN_RADAR_489180b6] */
  { /*     7 */                                              3u,                                                2u }   /* [cnctr_RDR_RdrNet_5172a59b]    */  /* [WS_cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/cnctr_RDR_RdrNet_5172a59b] */
};
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_BswMCurrentModuleState
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_StateType, ECUM_VAR_CLEARED) EcuM_BswMCurrentModuleState;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_BswMRequestedModuleState
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_StateType, ECUM_VAR_CLEARED) EcuM_BswMRequestedModuleState;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_ModuleState
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_StateType, ECUM_VAR_CLEARED) EcuM_ModuleState;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PCConfig
**********************************************************************************************************************/
/** 
  \var    EcuM_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to EcuM_PCPartitionConfig
*/ 
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_PCConfigsType, ECUM_CONST) EcuM_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_RDR_01] */
      EcuM_PCPartitionConfigRDR_01  /**< the pointer to EcuM_PCPartitionConfig in Config_RDR_01 */
  },
  { /* Index: 1 Keys: [Config_RDR_02] */
      EcuM_PCPartitionConfigRDR_02  /**< the pointer to EcuM_PCPartitionConfig in Config_RDR_02 */
  },
  { /* Index: 2 Keys: [Config_RDR_03] */
      EcuM_PCPartitionConfigRDR_03  /**< the pointer to EcuM_PCPartitionConfig in Config_RDR_03 */
  },
  { /* Index: 3 Keys: [Config_RDR_04] */
      EcuM_PCPartitionConfigRDR_04  /**< the pointer to EcuM_PCPartitionConfig in Config_RDR_04 */
  },
  { /* Index: 4 Keys: [Config_RDR_05] */
      EcuM_PCPartitionConfigRDR_05  /**< the pointer to EcuM_PCPartitionConfig in Config_RDR_05 */
  },
  { /* Index: 5 Keys: [Config_RDR_06] */
      EcuM_PCPartitionConfigRDR_06  /**< the pointer to EcuM_PCPartitionConfig in Config_RDR_06 */
  },
  { /* Index: 6 Keys: [Config_RDR_07] */
      EcuM_PCPartitionConfigRDR_07  /**< the pointer to EcuM_PCPartitionConfig in Config_RDR_07 */
  },
  { /* Index: 7 Keys: [Config_RDR_08] */
      EcuM_PCPartitionConfigRDR_08  /**< the pointer to EcuM_PCPartitionConfig in Config_RDR_08 */
  }
};
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PCPartitionConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    EcuM_PCPartitionConfigRDR_01
  \details
  Element                Description
  DriverInitOneFctPtr    the pointer to EcuM_DriverInitOneFctPtr
*/ 
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_PCPartitionConfigType, ECUM_CONST) EcuM_PCPartitionConfigRDR_01[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [ECUM_SINGLEPARTITION] */
      (&(EcuM_DriverInitOneFctPtrRDR_01))  /**< the pointer to EcuM_DriverInitOneFctPtr in Config_RDR_01 */
  }
};
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PCPartitionConfigRDR_02
**********************************************************************************************************************/
/** 
  \var    EcuM_PCPartitionConfigRDR_02
  \details
  Element                Description
  DriverInitOneFctPtr    the pointer to EcuM_DriverInitOneFctPtr
*/ 
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_PCPartitionConfigType, ECUM_CONST) EcuM_PCPartitionConfigRDR_02[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [ECUM_SINGLEPARTITION] */
      (&(EcuM_DriverInitOneFctPtrRDR_02))  /**< the pointer to EcuM_DriverInitOneFctPtr in Config_RDR_02 */
  }
};
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PCPartitionConfigRDR_03
**********************************************************************************************************************/
/** 
  \var    EcuM_PCPartitionConfigRDR_03
  \details
  Element                Description
  DriverInitOneFctPtr    the pointer to EcuM_DriverInitOneFctPtr
*/ 
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_PCPartitionConfigType, ECUM_CONST) EcuM_PCPartitionConfigRDR_03[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [ECUM_SINGLEPARTITION] */
      (&(EcuM_DriverInitOneFctPtrRDR_03))  /**< the pointer to EcuM_DriverInitOneFctPtr in Config_RDR_03 */
  }
};
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PCPartitionConfigRDR_04
**********************************************************************************************************************/
/** 
  \var    EcuM_PCPartitionConfigRDR_04
  \details
  Element                Description
  DriverInitOneFctPtr    the pointer to EcuM_DriverInitOneFctPtr
*/ 
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_PCPartitionConfigType, ECUM_CONST) EcuM_PCPartitionConfigRDR_04[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [ECUM_SINGLEPARTITION] */
      (&(EcuM_DriverInitOneFctPtrRDR_04))  /**< the pointer to EcuM_DriverInitOneFctPtr in Config_RDR_04 */
  }
};
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PCPartitionConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    EcuM_PCPartitionConfigRDR_05
  \details
  Element                Description
  DriverInitOneFctPtr    the pointer to EcuM_DriverInitOneFctPtr
*/ 
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_PCPartitionConfigType, ECUM_CONST) EcuM_PCPartitionConfigRDR_05[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [ECUM_SINGLEPARTITION] */
      (&(EcuM_DriverInitOneFctPtrRDR_05))  /**< the pointer to EcuM_DriverInitOneFctPtr in Config_RDR_05 */
  }
};
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PCPartitionConfigRDR_06
**********************************************************************************************************************/
/** 
  \var    EcuM_PCPartitionConfigRDR_06
  \details
  Element                Description
  DriverInitOneFctPtr    the pointer to EcuM_DriverInitOneFctPtr
*/ 
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_PCPartitionConfigType, ECUM_CONST) EcuM_PCPartitionConfigRDR_06[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [ECUM_SINGLEPARTITION] */
      (&(EcuM_DriverInitOneFctPtrRDR_06))  /**< the pointer to EcuM_DriverInitOneFctPtr in Config_RDR_06 */
  }
};
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PCPartitionConfigRDR_07
**********************************************************************************************************************/
/** 
  \var    EcuM_PCPartitionConfigRDR_07
  \details
  Element                Description
  DriverInitOneFctPtr    the pointer to EcuM_DriverInitOneFctPtr
*/ 
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_PCPartitionConfigType, ECUM_CONST) EcuM_PCPartitionConfigRDR_07[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [ECUM_SINGLEPARTITION] */
      (&(EcuM_DriverInitOneFctPtrRDR_07))  /**< the pointer to EcuM_DriverInitOneFctPtr in Config_RDR_07 */
  }
};
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PCPartitionConfigRDR_08
**********************************************************************************************************************/
/** 
  \var    EcuM_PCPartitionConfigRDR_08
  \details
  Element                Description
  DriverInitOneFctPtr    the pointer to EcuM_DriverInitOneFctPtr
*/ 
#define ECUM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_PCPartitionConfigType, ECUM_CONST) EcuM_PCPartitionConfigRDR_08[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [ECUM_SINGLEPARTITION] */
      (&(EcuM_DriverInitOneFctPtrRDR_08))  /**< the pointer to EcuM_DriverInitOneFctPtr in Config_RDR_08 */
  }
};
#define ECUM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/




