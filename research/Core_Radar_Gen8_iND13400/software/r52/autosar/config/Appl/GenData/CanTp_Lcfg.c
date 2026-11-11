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
 *            Module: CanTp
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTp_Lcfg.c
 *   Generation Time: 2026-08-07 17:10:37
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
#define CANTP_LCFG_SOURCE

/* -----------------------------------------------------------------------------
    &&&~ Include files
 ----------------------------------------------------------------------------- */
# include "CanTp_Lcfg.h"

#if (CANTP_LOLAYER_CANIF == STD_ON)
# include "CanIf.h"
#endif
# include "PduR_CanTp.h"

/* -----------------------------------------------------------------------------
    &&&~ Data definitions
 ----------------------------------------------------------------------------- */



/**********************************************************************************************************************
 *  LOCAL DATA
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
 *  GLOBAL DATA
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTp_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#if(CANTP_USE_INIT_POINTER == STD_ON)
P2CONST(CanTp_PBConfigType, CANTP_VAR_CLEARED, CANTP_PBCFG) CanTp_ConfigDataPtr = (P2CONST(CanTp_PBConfigType, CANTP_VAR_CLEARED, CANTP_PBCFG))NULL_PTR;
#endif

#define CANTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTp_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#define CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTp_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

VAR(boolean, CANTP_VAR_NO_INIT) CanTp_PreInitialized;

#define CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTp_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanTp_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    CanTp_PartitionIdentifiers
  \brief  the partition context in Config_RDR_01
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to CanTp_PCPartitionConfig
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_PartitionIdentifiersType, CANTP_CONST) CanTp_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV                PCPartitionConfigIdx */
  { /*     0 */ CanTpSinglePartitionMemory,                   0u }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_01
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_01[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxPdu2RxSduInd      Referable Keys */
  /*     0 */              6u,  /* [RxPdu_0] */
  /*     1 */              1u,  /* [RxPdu_1] */
  /*     2 */              5u,  /* [RxPdu_2] */
  /*     3 */             20u,  /* [RxPdu_3] */
  /*     4 */             10u,  /* [RxPdu_4] */
  /*     5 */              4u,  /* [RxPdu_5] */
  /*     6 */             16u,  /* [RxPdu_6] */
  /*     7 */              9u,  /* [RxPdu_7] */
  /*     8 */              2u,  /* [RxPdu_8] */
  /*     9 */             14u,  /* [RxPdu_9] */
  /*    10 */             21u,  /* [RxPdu_10] */
  /*    11 */             23u,  /* [RxPdu_11] */
  /*    12 */             18u,  /* [RxPdu_12] */
  /*    13 */             22u,  /* [RxPdu_13] */
  /*    14 */             11u,  /* [RxPdu_14] */
  /*    15 */              7u,  /* [RxPdu_15] */
  /*    16 */              8u,  /* [RxPdu_16] */
  /*    17 */             17u,  /* [RxPdu_17] */
  /*    18 */             12u,  /* [RxPdu_18] */
  /*    19 */              0u,  /* [RxPdu_19] */
  /*    20 */             19u,  /* [RxPdu_20] */
  /*    21 */             13u,  /* [RxPdu_21] */
  /*    22 */             15u,  /* [RxPdu_22] */
  /*    23 */              3u   /* [RxPdu_23] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_02
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_02
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_02[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxPdu2RxSduInd      Referable Keys */
  /*     0 */              4u,  /* [RxPdu_0] */
  /*     1 */             13u,  /* [RxPdu_1] */
  /*     2 */             17u,  /* [RxPdu_2] */
  /*     3 */              9u,  /* [RxPdu_3] */
  /*     4 */             16u,  /* [RxPdu_4] */
  /*     5 */              5u,  /* [RxPdu_5] */
  /*     6 */             11u,  /* [RxPdu_6] */
  /*     7 */             14u,  /* [RxPdu_7] */
  /*     8 */             15u,  /* [RxPdu_8] */
  /*     9 */              1u,  /* [RxPdu_9] */
  /*    10 */             12u,  /* [RxPdu_10] */
  /*    11 */              3u,  /* [RxPdu_11] */
  /*    12 */             18u,  /* [RxPdu_12] */
  /*    13 */              7u,  /* [RxPdu_13] */
  /*    14 */             20u,  /* [RxPdu_14] */
  /*    15 */             10u,  /* [RxPdu_15] */
  /*    16 */              2u,  /* [RxPdu_16] */
  /*    17 */             22u,  /* [RxPdu_17] */
  /*    18 */              8u,  /* [RxPdu_18] */
  /*    19 */              6u,  /* [RxPdu_19] */
  /*    20 */             21u,  /* [RxPdu_20] */
  /*    21 */             19u,  /* [RxPdu_21] */
  /*    22 */              0u,  /* [RxPdu_22] */
  /*    23 */             23u   /* [RxPdu_23] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_03
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_03
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_03[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxPdu2RxSduInd      Referable Keys */
  /*     0 */              5u,  /* [RxPdu_0] */
  /*     1 */             11u,  /* [RxPdu_1] */
  /*     2 */             14u,  /* [RxPdu_2] */
  /*     3 */             19u,  /* [RxPdu_3] */
  /*     4 */             18u,  /* [RxPdu_4] */
  /*     5 */              4u,  /* [RxPdu_5] */
  /*     6 */              9u,  /* [RxPdu_6] */
  /*     7 */              2u,  /* [RxPdu_7] */
  /*     8 */              3u,  /* [RxPdu_8] */
  /*     9 */              7u,  /* [RxPdu_9] */
  /*    10 */             20u,  /* [RxPdu_10] */
  /*    11 */             10u,  /* [RxPdu_11] */
  /*    12 */             13u,  /* [RxPdu_12] */
  /*    13 */              0u,  /* [RxPdu_13] */
  /*    14 */              8u,  /* [RxPdu_14] */
  /*    15 */             17u,  /* [RxPdu_15] */
  /*    16 */              6u,  /* [RxPdu_16] */
  /*    17 */             21u,  /* [RxPdu_17] */
  /*    18 */             22u,  /* [RxPdu_18] */
  /*    19 */             15u,  /* [RxPdu_19] */
  /*    20 */             23u,  /* [RxPdu_20] */
  /*    21 */              1u,  /* [RxPdu_21] */
  /*    22 */             16u,  /* [RxPdu_22] */
  /*    23 */             12u   /* [RxPdu_23] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_04
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_04
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_04[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxPdu2RxSduInd      Referable Keys */
  /*     0 */              4u,  /* [RxPdu_0] */
  /*     1 */             16u,  /* [RxPdu_1] */
  /*     2 */             19u,  /* [RxPdu_2] */
  /*     3 */             11u,  /* [RxPdu_3] */
  /*     4 */              2u,  /* [RxPdu_4] */
  /*     5 */              7u,  /* [RxPdu_5] */
  /*     6 */             21u,  /* [RxPdu_6] */
  /*     7 */             17u,  /* [RxPdu_7] */
  /*     8 */             18u,  /* [RxPdu_8] */
  /*     9 */              8u,  /* [RxPdu_9] */
  /*    10 */             12u,  /* [RxPdu_10] */
  /*    11 */             20u,  /* [RxPdu_11] */
  /*    12 */              6u,  /* [RxPdu_12] */
  /*    13 */              3u,  /* [RxPdu_13] */
  /*    14 */              0u,  /* [RxPdu_14] */
  /*    15 */             15u,  /* [RxPdu_15] */
  /*    16 */             22u,  /* [RxPdu_16] */
  /*    17 */             13u,  /* [RxPdu_17] */
  /*    18 */              5u,  /* [RxPdu_18] */
  /*    19 */             10u,  /* [RxPdu_19] */
  /*    20 */              9u,  /* [RxPdu_20] */
  /*    21 */              1u,  /* [RxPdu_21] */
  /*    22 */             23u,  /* [RxPdu_22] */
  /*    23 */             14u   /* [RxPdu_23] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_05
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_05[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxPdu2RxSduInd      Referable Keys */
  /*     0 */              7u,  /* [RxPdu_0] */
  /*     1 */              9u,  /* [RxPdu_1] */
  /*     2 */              1u,  /* [RxPdu_2] */
  /*     3 */             22u,  /* [RxPdu_3] */
  /*     4 */              0u,  /* [RxPdu_4] */
  /*     5 */             15u,  /* [RxPdu_5] */
  /*     6 */              8u,  /* [RxPdu_6] */
  /*     7 */              4u,  /* [RxPdu_7] */
  /*     8 */             11u,  /* [RxPdu_8] */
  /*     9 */             20u,  /* [RxPdu_9] */
  /*    10 */             19u,  /* [RxPdu_10] */
  /*    11 */             17u,  /* [RxPdu_11] */
  /*    12 */             18u,  /* [RxPdu_12] */
  /*    13 */             23u,  /* [RxPdu_13] */
  /*    14 */             10u,  /* [RxPdu_14] */
  /*    15 */             14u,  /* [RxPdu_15] */
  /*    16 */              6u,  /* [RxPdu_16] */
  /*    17 */              3u,  /* [RxPdu_17] */
  /*    18 */              5u,  /* [RxPdu_18] */
  /*    19 */             13u,  /* [RxPdu_19] */
  /*    20 */              2u,  /* [RxPdu_20] */
  /*    21 */             16u,  /* [RxPdu_21] */
  /*    22 */             21u,  /* [RxPdu_22] */
  /*    23 */             12u   /* [RxPdu_23] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_06
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_06
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_06[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxPdu2RxSduInd      Referable Keys */
  /*     0 */              3u,  /* [RxPdu_0] */
  /*     1 */             14u,  /* [RxPdu_1] */
  /*     2 */             15u,  /* [RxPdu_2] */
  /*     3 */              5u,  /* [RxPdu_3] */
  /*     4 */             22u,  /* [RxPdu_4] */
  /*     5 */              4u,  /* [RxPdu_5] */
  /*     6 */              7u,  /* [RxPdu_6] */
  /*     7 */             13u,  /* [RxPdu_7] */
  /*     8 */             17u,  /* [RxPdu_8] */
  /*     9 */             10u,  /* [RxPdu_9] */
  /*    10 */              0u,  /* [RxPdu_10] */
  /*    11 */              1u,  /* [RxPdu_11] */
  /*    12 */             18u,  /* [RxPdu_12] */
  /*    13 */              8u,  /* [RxPdu_13] */
  /*    14 */             21u,  /* [RxPdu_14] */
  /*    15 */              9u,  /* [RxPdu_15] */
  /*    16 */              6u,  /* [RxPdu_16] */
  /*    17 */             12u,  /* [RxPdu_17] */
  /*    18 */             11u,  /* [RxPdu_18] */
  /*    19 */              2u,  /* [RxPdu_19] */
  /*    20 */             16u,  /* [RxPdu_20] */
  /*    21 */             19u,  /* [RxPdu_21] */
  /*    22 */             20u,  /* [RxPdu_22] */
  /*    23 */             23u   /* [RxPdu_23] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_07
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_07
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_07[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxPdu2RxSduInd      Referable Keys */
  /*     0 */              9u,  /* [RxPdu_0] */
  /*     1 */              6u,  /* [RxPdu_1] */
  /*     2 */              7u,  /* [RxPdu_2] */
  /*     3 */             23u,  /* [RxPdu_3] */
  /*     4 */             15u,  /* [RxPdu_4] */
  /*     5 */              8u,  /* [RxPdu_5] */
  /*     6 */              2u,  /* [RxPdu_6] */
  /*     7 */             10u,  /* [RxPdu_7] */
  /*     8 */             14u,  /* [RxPdu_8] */
  /*     9 */              1u,  /* [RxPdu_9] */
  /*    10 */             21u,  /* [RxPdu_10] */
  /*    11 */              4u,  /* [RxPdu_11] */
  /*    12 */             12u,  /* [RxPdu_12] */
  /*    13 */              0u,  /* [RxPdu_13] */
  /*    14 */              3u,  /* [RxPdu_14] */
  /*    15 */             20u,  /* [RxPdu_15] */
  /*    16 */              5u,  /* [RxPdu_16] */
  /*    17 */             18u,  /* [RxPdu_17] */
  /*    18 */             22u,  /* [RxPdu_18] */
  /*    19 */             16u,  /* [RxPdu_19] */
  /*    20 */             17u,  /* [RxPdu_20] */
  /*    21 */             11u,  /* [RxPdu_21] */
  /*    22 */             19u,  /* [RxPdu_22] */
  /*    23 */             13u   /* [RxPdu_23] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_08
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_08
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_08[24] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     RxPdu2RxSduInd      Referable Keys */
  /*     0 */             10u,  /* [RxPdu_0] */
  /*     1 */             19u,  /* [RxPdu_1] */
  /*     2 */             16u,  /* [RxPdu_2] */
  /*     3 */              0u,  /* [RxPdu_3] */
  /*     4 */             22u,  /* [RxPdu_4] */
  /*     5 */              9u,  /* [RxPdu_5] */
  /*     6 */             14u,  /* [RxPdu_6] */
  /*     7 */             20u,  /* [RxPdu_7] */
  /*     8 */             17u,  /* [RxPdu_8] */
  /*     9 */              7u,  /* [RxPdu_9] */
  /*    10 */             15u,  /* [RxPdu_10] */
  /*    11 */              6u,  /* [RxPdu_11] */
  /*    12 */              8u,  /* [RxPdu_12] */
  /*    13 */              3u,  /* [RxPdu_13] */
  /*    14 */             11u,  /* [RxPdu_14] */
  /*    15 */             18u,  /* [RxPdu_15] */
  /*    16 */             23u,  /* [RxPdu_16] */
  /*    17 */              2u,  /* [RxPdu_17] */
  /*    18 */              5u,  /* [RxPdu_18] */
  /*    19 */             21u,  /* [RxPdu_19] */
  /*    20 */              4u,  /* [RxPdu_20] */
  /*    21 */              1u,  /* [RxPdu_21] */
  /*    22 */             13u,  /* [RxPdu_22] */
  /*    23 */             12u   /* [RxPdu_23] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_01
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_01[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxPdu2TxSduInd      Referable Keys */
  /*     0 */              4u,  /* [RxPdu_0] */
  /*     1 */              0u,  /* [RxPdu_1] */
  /*     2 */              3u,  /* [RxPdu_2] */
  /*     3 */              9u,  /* [RxPdu_3] */
  /*     4 */              6u,  /* [RxPdu_4] */
  /*     5 */              2u,  /* [RxPdu_5] */
  /*     6 */              8u,  /* [RxPdu_6] */
  /*     7 */              5u,  /* [RxPdu_7] */
  /*     8 */              1u,  /* [RxPdu_8] */
  /*     9 */              7u,  /* [RxPdu_9] */
  /*    10 */             10u,  /* [RxPdu_10] */
  /*    11 */             11u   /* [RxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_02
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_02
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_02[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxPdu2TxSduInd      Referable Keys */
  /*     0 */              2u,  /* [RxPdu_0] */
  /*     1 */              7u,  /* [RxPdu_1] */
  /*     2 */             11u,  /* [RxPdu_2] */
  /*     3 */              4u,  /* [RxPdu_3] */
  /*     4 */             10u,  /* [RxPdu_4] */
  /*     5 */              3u,  /* [RxPdu_5] */
  /*     6 */              5u,  /* [RxPdu_6] */
  /*     7 */              8u,  /* [RxPdu_7] */
  /*     8 */              9u,  /* [RxPdu_8] */
  /*     9 */              0u,  /* [RxPdu_9] */
  /*    10 */              6u,  /* [RxPdu_10] */
  /*    11 */              1u   /* [RxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_03
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_03
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_03[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxPdu2TxSduInd      Referable Keys */
  /*     0 */              3u,  /* [RxPdu_0] */
  /*     1 */              7u,  /* [RxPdu_1] */
  /*     2 */              8u,  /* [RxPdu_2] */
  /*     3 */             10u,  /* [RxPdu_3] */
  /*     4 */              9u,  /* [RxPdu_4] */
  /*     5 */              2u,  /* [RxPdu_5] */
  /*     6 */              5u,  /* [RxPdu_6] */
  /*     7 */              0u,  /* [RxPdu_7] */
  /*     8 */              1u,  /* [RxPdu_8] */
  /*     9 */              4u,  /* [RxPdu_9] */
  /*    10 */             11u,  /* [RxPdu_10] */
  /*    11 */              6u   /* [RxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_04
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_04
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_04[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxPdu2TxSduInd      Referable Keys */
  /*     0 */              1u,  /* [RxPdu_0] */
  /*     1 */              6u,  /* [RxPdu_1] */
  /*     2 */              9u,  /* [RxPdu_2] */
  /*     3 */              4u,  /* [RxPdu_3] */
  /*     4 */              0u,  /* [RxPdu_4] */
  /*     5 */              2u,  /* [RxPdu_5] */
  /*     6 */             11u,  /* [RxPdu_6] */
  /*     7 */              7u,  /* [RxPdu_7] */
  /*     8 */              8u,  /* [RxPdu_8] */
  /*     9 */              3u,  /* [RxPdu_9] */
  /*    10 */              5u,  /* [RxPdu_10] */
  /*    11 */             10u   /* [RxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_05
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_05[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxPdu2TxSduInd      Referable Keys */
  /*     0 */              3u,  /* [RxPdu_0] */
  /*     1 */              5u,  /* [RxPdu_1] */
  /*     2 */              1u,  /* [RxPdu_2] */
  /*     3 */             11u,  /* [RxPdu_3] */
  /*     4 */              0u,  /* [RxPdu_4] */
  /*     5 */              7u,  /* [RxPdu_5] */
  /*     6 */              4u,  /* [RxPdu_6] */
  /*     7 */              2u,  /* [RxPdu_7] */
  /*     8 */              6u,  /* [RxPdu_8] */
  /*     9 */             10u,  /* [RxPdu_9] */
  /*    10 */              9u,  /* [RxPdu_10] */
  /*    11 */              8u   /* [RxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_06
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_06
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_06[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxPdu2TxSduInd      Referable Keys */
  /*     0 */              2u,  /* [RxPdu_0] */
  /*     1 */              8u,  /* [RxPdu_1] */
  /*     2 */              9u,  /* [RxPdu_2] */
  /*     3 */              4u,  /* [RxPdu_3] */
  /*     4 */             11u,  /* [RxPdu_4] */
  /*     5 */              3u,  /* [RxPdu_5] */
  /*     6 */              5u,  /* [RxPdu_6] */
  /*     7 */              7u,  /* [RxPdu_7] */
  /*     8 */             10u,  /* [RxPdu_8] */
  /*     9 */              6u,  /* [RxPdu_9] */
  /*    10 */              0u,  /* [RxPdu_10] */
  /*    11 */              1u   /* [RxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_07
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_07
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_07[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxPdu2TxSduInd      Referable Keys */
  /*     0 */              6u,  /* [RxPdu_0] */
  /*     1 */              3u,  /* [RxPdu_1] */
  /*     2 */              4u,  /* [RxPdu_2] */
  /*     3 */             11u,  /* [RxPdu_3] */
  /*     4 */              9u,  /* [RxPdu_4] */
  /*     5 */              5u,  /* [RxPdu_5] */
  /*     6 */              1u,  /* [RxPdu_6] */
  /*     7 */              7u,  /* [RxPdu_7] */
  /*     8 */              8u,  /* [RxPdu_8] */
  /*     9 */              0u,  /* [RxPdu_9] */
  /*    10 */             10u,  /* [RxPdu_10] */
  /*    11 */              2u   /* [RxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_08
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_08
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_08[12] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     RxPdu2TxSduInd      Referable Keys */
  /*     0 */              4u,  /* [RxPdu_0] */
  /*     1 */              9u,  /* [RxPdu_1] */
  /*     2 */              7u,  /* [RxPdu_2] */
  /*     3 */              0u,  /* [RxPdu_3] */
  /*     4 */             11u,  /* [RxPdu_4] */
  /*     5 */              3u,  /* [RxPdu_5] */
  /*     6 */              5u,  /* [RxPdu_6] */
  /*     7 */             10u,  /* [RxPdu_7] */
  /*     8 */              8u,  /* [RxPdu_8] */
  /*     9 */              2u,  /* [RxPdu_9] */
  /*    10 */              6u,  /* [RxPdu_10] */
  /*    11 */              1u   /* [RxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPduMap
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPduMap
  \brief  Table of Addressing Infos of RxNPdus
  \details
  Element                    Description
  RxPdu2RxSduEndIdx          the end index of the 0:n relation pointing to one of CanTp_RxPdu2RxSduInd
  RxPdu2RxSduStartIdx        the start index of the 0:n relation pointing to one of CanTp_RxPdu2RxSduInd
  RxPdu2TxSduEndIdx          the end index of the 0:n relation pointing to one of CanTp_RxPdu2TxSduInd
  RxPdu2TxSduPartitionIdx    the partition index of the 0:n relation pointing to one of CanTp_RxPdu2TxSduInd
  RxPdu2TxSduStartIdx        the start index of the 0:n relation pointing to one of CanTp_RxPdu2TxSduInd
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPduMapType, CANTP_CONST) CanTp_RxPduMap[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxPdu2RxSduEndIdx  RxPdu2RxSduStartIdx  RxPdu2TxSduEndIdx                     RxPdu2TxSduPartitionIdx                                                       RxPdu2TxSduStartIdx                           Referable Keys */
  { /*     0 */                1u,                  0u,                                   1u,                                         0u  /* CanTpSinglePartitionMemory */,                                     0u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/FR_DIAG_REQ_PHY_OBD1_Tp_oVCAN_RADAR_ddfa31cf_Rx] */
  { /*     1 */                2u,                  1u,                                   2u,                                         0u  /* CanTpSinglePartitionMemory */,                                     1u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/FR_DIAG_REQ_PHY_OBD2_Tp_oVCAN_RADAR_b91a4a31_Rx] */
  { /*     2 */                3u,                  2u,                                   3u,                                         0u  /* CanTpSinglePartitionMemory */,                                     2u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/FR_DIAG_REQ_PHY_OTA_Tp_oVCAN_RADAR_4de495d5_Rx] */
  { /*     3 */                4u,                  3u,                                   4u,                                         0u  /* CanTpSinglePartitionMemory */,                                     3u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/FR_DIAG_REQ_PHY_PLANT_Tp_oVCAN_RADAR_bda0e30b_Rx] */
  { /*     4 */                5u,                  4u,                                   5u,                                         0u  /* CanTpSinglePartitionMemory */,                                     4u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_6e232c89_Rx] */
  { /*     5 */                6u,                  5u,                                   6u,                                         0u  /* CanTpSinglePartitionMemory */,                                     5u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_20_b6648efa_Rx] */
  { /*     6 */                7u,                  6u,                                   7u,                                         0u  /* CanTpSinglePartitionMemory */,                                     6u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_0ac35777_Rx] */
  { /*     7 */                8u,                  7u,                                   8u,                                         0u  /* CanTpSinglePartitionMemory */,                                     7u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_20_65ff9201_Rx] */
  { /*     8 */                9u,                  8u,                                   9u,                                         0u  /* CanTpSinglePartitionMemory */,                                     8u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_20_96582344_Rx] */
  { /*     9 */               10u,                  9u,                                  10u,                                         0u  /* CanTpSinglePartitionMemory */,                                     9u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_94a46e49_Rx] */
  { /*    10 */               11u,                 10u,                                  11u,                                         0u  /* CanTpSinglePartitionMemory */,                                    10u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_20_f110e38b_Rx] */
  { /*    11 */               12u,                 11u,                                  12u,                                         0u  /* CanTpSinglePartitionMemory */,                                    11u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_68155c61_Rx] */
  { /*    12 */               13u,                 12u, CANTP_NO_RXPDU2TXSDUENDIDXOFRXPDUMAP, CANTP_NO_RXPDU2TXSDUPARTITIONIDXOFRXPDUMAP                                  , CANTP_NO_RXPDU2TXSDUSTARTIDXOFRXPDUMAP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/DIAG_REQ_FNC_OBD1_Tp_oVCAN_RADAR_260cec9f_Rx] */
  { /*    13 */               14u,                 13u, CANTP_NO_RXPDU2TXSDUENDIDXOFRXPDUMAP, CANTP_NO_RXPDU2TXSDUPARTITIONIDXOFRXPDUMAP                                  , CANTP_NO_RXPDU2TXSDUSTARTIDXOFRXPDUMAP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/DIAG_REQ_FNC_OBD2_Tp_oVCAN_RADAR_42ec9761_Rx] */
  { /*    14 */               15u,                 14u, CANTP_NO_RXPDU2TXSDUENDIDXOFRXPDUMAP, CANTP_NO_RXPDU2TXSDUPARTITIONIDXOFRXPDUMAP                                  , CANTP_NO_RXPDU2TXSDUSTARTIDXOFRXPDUMAP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/DIAG_REQ_FNC_OTA_Tp_oVCAN_RADAR_6f75a08a_Rx] */
  { /*    15 */               16u,                 15u, CANTP_NO_RXPDU2TXSDUENDIDXOFRXPDUMAP, CANTP_NO_RXPDU2TXSDUPARTITIONIDXOFRXPDUMAP                                  , CANTP_NO_RXPDU2TXSDUSTARTIDXOFRXPDUMAP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/DIAG_REQ_FNC_PLANT_Tp_oVCAN_RADAR_d6304422_Rx] */
  { /*    16 */               17u,                 16u, CANTP_NO_RXPDU2TXSDUENDIDXOFRXPDUMAP, CANTP_NO_RXPDU2TXSDUPARTITIONIDXOFRXPDUMAP                                  , CANTP_NO_RXPDU2TXSDUSTARTIDXOFRXPDUMAP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_20_9397638b_Rx] */
  { /*    17 */               18u,                 17u, CANTP_NO_RXPDU2TXSDUENDIDXOFRXPDUMAP, CANTP_NO_RXPDU2TXSDUPARTITIONIDXOFRXPDUMAP                                  , CANTP_NO_RXPDU2TXSDUSTARTIDXOFRXPDUMAP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_ba721e23_Rx] */
  { /*    18 */               19u,                 18u, CANTP_NO_RXPDU2TXSDUENDIDXOFRXPDUMAP, CANTP_NO_RXPDU2TXSDUPARTITIONIDXOFRXPDUMAP                                  , CANTP_NO_RXPDU2TXSDUSTARTIDXOFRXPDUMAP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_20_400c7f70_Rx] */
  { /*    19 */               20u,                 19u, CANTP_NO_RXPDU2TXSDUENDIDXOFRXPDUMAP, CANTP_NO_RXPDU2TXSDUPARTITIONIDXOFRXPDUMAP                                  , CANTP_NO_RXPDU2TXSDUSTARTIDXOFRXPDUMAP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_de9265dd_Rx] */
  { /*    20 */               21u,                 20u, CANTP_NO_RXPDU2TXSDUENDIDXOFRXPDUMAP, CANTP_NO_RXPDU2TXSDUPARTITIONIDXOFRXPDUMAP                                  , CANTP_NO_RXPDU2TXSDUSTARTIDXOFRXPDUMAP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_7ea6262a_Rx] */
  { /*    21 */               22u,                 21u, CANTP_NO_RXPDU2TXSDUENDIDXOFRXPDUMAP, CANTP_NO_RXPDU2TXSDUPARTITIONIDXOFRXPDUMAP                                  , CANTP_NO_RXPDU2TXSDUSTARTIDXOFRXPDUMAP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_20_0a67f2f6_Rx] */
  { /*    22 */               23u,                 22u, CANTP_NO_RXPDU2TXSDUENDIDXOFRXPDUMAP, CANTP_NO_RXPDU2TXSDUPARTITIONIDXOFRXPDUMAP                                  , CANTP_NO_RXPDU2TXSDUSTARTIDXOFRXPDUMAP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_5ec247a5_Rx] */
  { /*    23 */               24u,                 23u, CANTP_NO_RXPDU2TXSDUENDIDXOFRXPDUMAP, CANTP_NO_RXPDU2TXSDUPARTITIONIDXOFRXPDUMAP                                  , CANTP_NO_RXPDU2TXSDUSTARTIDXOFRXPDUMAP }   /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_20_d63751cc_Rx] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_01
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_01[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxFcPduId                                                                 PduRRxSduId                              RxPduId                                     TxFcPduConfirmationPduId                        CanType                        NAr   NBr  NCr   RxMaxPayloadLength  RxPduMapIdx  RxTaType                             STmin  TxPduMapIdx                     TxSduCfgIdx                           Comment                            Referable Keys */
  { /*     0 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dab59121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_7c29b324, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         19u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_d62c6608] */  /* [CanTpRxNSdu_d62c6608, RxPdu_19] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_1d3adefb, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_25c8f584, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_25c8f584, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          1u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             1u,                             0u },  /* [CanTpRxNSdu_c5537cf0] */  /* [CanTpRxNSdu_c5537cf0, RxPdu_1, TxPdu_1] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRSrcPdu_PduRSrcPdu_58857336, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_1d12fd25, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_1d12fd25, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          8u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             8u,                             1u },  /* [CanTpRxNSdu_bd9a0635] */  /* [CanTpRxNSdu_bd9a0635, RxPdu_8, TxPdu_8] */
  { /*     3 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_d6a59fd3, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_dea5e5f6, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         23u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_e307f5e7] */  /* [CanTpRxNSdu_e307f5e7, RxPdu_23] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_88550f3d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_53da4212, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_53da4212, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          5u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             5u,                             2u },  /* [CanTpRxNSdu_24fdb8bb] */  /* [CanTpRxNSdu_24fdb8bb, RxPdu_5, TxPdu_5] */
  { /*     5 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRSrcPdu_PduRSrcPdu_4399556e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_1c8dcaf8, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_1c8dcaf8, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          2u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             2u,                             3u },  /* [CanTpRxNSdu_2fa399b3] */  /* [CanTpRxNSdu_2fa399b3, RxPdu_2, TxPdu_2] */
  { /*     6 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_7bb4cf60, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_7e1619c8, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_7e1619c8, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          0u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             0u,                             4u },  /* [CanTpRxNSdu_7f5185ac] */  /* [CanTpRxNSdu_7f5185ac, RxPdu_0, TxPdu_0] */
  { /*     7 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_55bb6522, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_ec7f19dd, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         15u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_b76651b3] */  /* [CanTpRxNSdu_b76651b3, RxPdu_15] */
  { /*     8 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_12ce5aa9, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_007a5691, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         16u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_6a4050a8] */  /* [CanTpRxNSdu_6a4050a8, RxPdu_16] */
  { /*     9 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_5808d905, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a9d0cc61, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_a9d0cc61, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          7u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             7u,                             5u },  /* [CanTpRxNSdu_db835be6] */  /* [CanTpRxNSdu_db835be6, RxPdu_7, TxPdu_7] */
  { /*    10 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_d26a3583, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_bea21a30, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_bea21a30, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          4u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             4u,                             6u },  /* [CanTpRxNSdu_e66ca3b9] */  /* [CanTpRxNSdu_e66ca3b9, RxPdu_4, TxPdu_4] */
  { /*    11 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dbaad71c, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_25d1c137, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         14u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_c5ebb271] */  /* [CanTpRxNSdu_c5ebb271, RxPdu_14] */
  { /*    12 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_acafabed, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2f78abfb, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         18u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_0d8cb540] */  /* [CanTpRxNSdu_0d8cb540, RxPdu_18] */
  { /*    13 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_09f61e64, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_7236ae3d, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         21u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_d603b303] */  /* [CanTpRxNSdu_d603b303, RxPdu_21] */
  { /*    14 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRSrcPdu_PduRSrcPdu_c794190e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_5da9cb2a, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_5da9cb2a, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          9u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             9u,                             7u },  /* [CanTpRxNSdu_0057d142] */  /* [CanTpRxNSdu_0057d142, RxPdu_9, TxPdu_9] */
  { /*    15 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_61d1e2e6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_c1cf6678, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         22u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_c5aa076c] */  /* [CanTpRxNSdu_c5aa076c, RxPdu_22] */
  { /*    16 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_f2e56351, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_1fe0333b, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_1fe0333b, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          6u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             6u,                             8u },  /* [CanTpRxNSdu_64228dd8] */  /* [CanTpRxNSdu_64228dd8, RxPdu_6, TxPdu_6] */
  { /*    17 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_ec57064f, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_027c2a01, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         17u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_8ea01f46] */  /* [CanTpRxNSdu_8ea01f46, RxPdu_17] */
  { /*    18 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_e4e4d778, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_81677e4e, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         12u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_80a26c19] */  /* [CanTpRxNSdu_80a26c19, RxPdu_12] */
  { /*    19 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_6f3aa62d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_6f50186e, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         20u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_b509cdf9] */  /* [CanTpRxNSdu_b509cdf9, RxPdu_20] */
  { /*    20 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRSrcPdu_PduRSrcPdu_199df235, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_11900290, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_11900290, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          3u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             3u,                             9u },  /* [CanTpRxNSdu_6b1dcdd5] */  /* [CanTpRxNSdu_6b1dcdd5, RxPdu_3, TxPdu_3] */
  { /*    21 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_917a13f6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_e961c2e4, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_e961c2e4, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,         10u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            10u,                            10u },  /* [CanTpRxNSdu_3a469f02] */  /* [CanTpRxNSdu_3a469f02, RxPdu_10, TxPdu_10] */
  { /*    22 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_017e0121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a704ede5, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         13u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_275a18b1] */  /* [CanTpRxNSdu_275a18b1, RxPdu_13] */
  { /*    23 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRSrcPdu_PduRSrcPdu_ce8fc2bd, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_69d47c63, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_69d47c63, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,         11u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            11u,                            11u }   /* [CanTpRxNSdu_f486fe77] */  /* [CanTpRxNSdu_f486fe77, RxPdu_11, TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_02
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_02
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_02[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxFcPduId                                                                 PduRRxSduId                              RxPduId                                     TxFcPduConfirmationPduId                        CanType                        NAr   NBr  NCr   RxMaxPayloadLength  RxPduMapIdx  RxTaType                             STmin  TxPduMapIdx                     TxSduCfgIdx                           Comment                            Referable Keys */
  { /*     0 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_61d1e2e6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_955effbd, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         22u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_3d176ff8] */  /* [CanTpRxNSdu_3d176ff8, RxPdu_22] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRSrcPdu_PduRSrcPdu_c794190e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_de393efa, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_de393efa, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          9u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             9u,                             0u },  /* [CanTpRxNSdu_4b8ac5bd] */  /* [CanTpRxNSdu_4b8ac5bd, RxPdu_9, TxPdu_9] */
  { /*     2 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_12ce5aa9, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_b306521c, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         16u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_290c259d] */  /* [CanTpRxNSdu_290c259d, RxPdu_16] */
  { /*     3 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRSrcPdu_PduRSrcPdu_ce8fc2bd, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_ee3456aa, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_ee3456aa, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,         11u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            11u,                             1u },  /* [CanTpRxNSdu_8063d38e] */  /* [CanTpRxNSdu_8063d38e, RxPdu_11, TxPdu_11] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_7bb4cf60, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_050d9363, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_050d9363, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          0u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             0u,                             2u },  /* [CanTpRxNSdu_6b1f15de] */  /* [CanTpRxNSdu_6b1f15de, RxPdu_0, TxPdu_0] */
  { /*     5 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_88550f3d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_6a09e291, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_6a09e291, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          5u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             5u,                             3u },  /* [CanTpRxNSdu_6b7431ef] */  /* [CanTpRxNSdu_6b7431ef, RxPdu_5, TxPdu_5] */
  { /*     6 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dab59121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_ee04a3b7, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         19u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_e69a2e9c] */  /* [CanTpRxNSdu_e69a2e9c, RxPdu_19] */
  { /*     7 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_017e0121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_dcddaf97, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         13u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_c22ecba5] */  /* [CanTpRxNSdu_c22ecba5, RxPdu_13] */
  { /*     8 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_acafabed, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_31ffae20, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         18u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_5bd213bc] */  /* [CanTpRxNSdu_5bd213bc, RxPdu_18] */
  { /*     9 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRSrcPdu_PduRSrcPdu_199df235, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_31443625, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_31443625, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          3u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             3u,                             4u },  /* [CanTpRxNSdu_90dedbb7] */  /* [CanTpRxNSdu_90dedbb7, RxPdu_3, TxPdu_3] */
  { /*    10 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_55bb6522, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_6b2d7968, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         15u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_87c84b68] */  /* [CanTpRxNSdu_87c84b68, RxPdu_15] */
  { /*    11 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_f2e56351, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_5917721d, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_5917721d, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          6u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             6u,                             5u },  /* [CanTpRxNSdu_482f027a] */  /* [CanTpRxNSdu_482f027a, RxPdu_6, TxPdu_6] */
  { /*    12 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_917a13f6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_91d8a7cd, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_91d8a7cd, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,         10u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            10u,                             6u },  /* [CanTpRxNSdu_9bdfb9c6] */  /* [CanTpRxNSdu_9bdfb9c6, RxPdu_10, TxPdu_10] */
  { /*    13 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_1d3adefb, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_69216f34, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_69216f34, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          1u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             1u,                             7u },  /* [CanTpRxNSdu_5249da4a] */  /* [CanTpRxNSdu_5249da4a, RxPdu_1, TxPdu_1] */
  { /*    14 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_5808d905, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_f07d8f2b, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_f07d8f2b, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          7u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             7u,                             8u },  /* [CanTpRxNSdu_4e12ed26] */  /* [CanTpRxNSdu_4e12ed26, RxPdu_7, TxPdu_7] */
  { /*    15 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRSrcPdu_PduRSrcPdu_58857336, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_05b41376, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_05b41376, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          8u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             8u,                             9u },  /* [CanTpRxNSdu_175c4d75] */  /* [CanTpRxNSdu_175c4d75, RxPdu_8, TxPdu_8] */
  { /*    16 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_d26a3583, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_d29ebc6b, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_d29ebc6b, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          4u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             4u,                            10u },  /* [CanTpRxNSdu_a39083e7] */  /* [CanTpRxNSdu_a39083e7, RxPdu_4, TxPdu_4] */
  { /*    17 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRSrcPdu_PduRSrcPdu_4399556e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_44358187, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_44358187, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          2u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             2u,                            11u },  /* [CanTpRxNSdu_4f8ed450] */  /* [CanTpRxNSdu_4f8ed450, RxPdu_2, TxPdu_2] */
  { /*    18 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_e4e4d778, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2cc9a2e3, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         12u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_8c618172] */  /* [CanTpRxNSdu_8c618172, RxPdu_12] */
  { /*    19 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_09f61e64, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_6fa47c37, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         21u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_6541c420] */  /* [CanTpRxNSdu_6541c420, RxPdu_21] */
  { /*    20 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dbaad71c, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_49526666, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         14u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_6bec8c22] */  /* [CanTpRxNSdu_6bec8c22, RxPdu_14] */
  { /*    21 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_6f3aa62d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_02808996, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         20u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_784cf1a8] */  /* [CanTpRxNSdu_784cf1a8, RxPdu_20] */
  { /*    22 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_ec57064f, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_df9c51e3, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         17u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_85b3e172] */  /* [CanTpRxNSdu_85b3e172, RxPdu_17] */
  { /*    23 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_d6a59fd3, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_219160d4, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         23u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG }   /* [CanTpRxNSdu_4700b6a3] */  /* [CanTpRxNSdu_4700b6a3, RxPdu_23] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_03
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_03
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_03[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxFcPduId                                                                 PduRRxSduId                              RxPduId                                     TxFcPduConfirmationPduId                        CanType                        NAr   NBr  NCr   RxMaxPayloadLength  RxPduMapIdx  RxTaType                             STmin  TxPduMapIdx                     TxSduCfgIdx                           Comment                            Referable Keys */
  { /*     0 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_017e0121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_e9a53f5f, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         13u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_4164c19b] */  /* [CanTpRxNSdu_4164c19b, RxPdu_13] */
  { /*     1 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_09f61e64, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_b29ee0c8, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         21u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_468ce7a5] */  /* [CanTpRxNSdu_468ce7a5, RxPdu_21] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_5808d905, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_17fce6a3, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_17fce6a3, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          7u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             7u,                             0u },  /* [CanTpRxNSdu_471bd8a5] */  /* [CanTpRxNSdu_471bd8a5, RxPdu_7, TxPdu_7] */
  { /*     3 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRSrcPdu_PduRSrcPdu_58857336, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_0324451f, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_0324451f, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          8u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             8u,                             1u },  /* [CanTpRxNSdu_1b50fb68] */  /* [CanTpRxNSdu_1b50fb68, RxPdu_8, TxPdu_8] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_88550f3d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_f1486551, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_f1486551, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          5u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             5u,                             2u },  /* [CanTpRxNSdu_620766ce] */  /* [CanTpRxNSdu_620766ce, RxPdu_5, TxPdu_5] */
  { /*     5 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_7bb4cf60, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2322364d, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_2322364d, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          0u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             0u,                             3u },  /* [CanTpRxNSdu_93c8010e] */  /* [CanTpRxNSdu_93c8010e, RxPdu_0, TxPdu_0] */
  { /*     6 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_12ce5aa9, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_7db6e3a7, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         16u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_45712a97] */  /* [CanTpRxNSdu_45712a97, RxPdu_16] */
  { /*     7 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRSrcPdu_PduRSrcPdu_c794190e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_60e658cd, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_60e658cd, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          9u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             9u,                             4u },  /* [CanTpRxNSdu_fac189c4] */  /* [CanTpRxNSdu_fac189c4, RxPdu_9, TxPdu_9] */
  { /*     8 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dbaad71c, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_21c36ca5, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         14u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_73387856] */  /* [CanTpRxNSdu_73387856, RxPdu_14] */
  { /*     9 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_f2e56351, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_98033048, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_98033048, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          6u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             6u,                             5u },  /* [CanTpRxNSdu_e2541eaf] */  /* [CanTpRxNSdu_e2541eaf, RxPdu_6, TxPdu_6] */
  { /*    10 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRSrcPdu_PduRSrcPdu_ce8fc2bd, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_25f6a934, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_25f6a934, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,         11u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            11u,                             6u },  /* [CanTpRxNSdu_ca28ec73] */  /* [CanTpRxNSdu_ca28ec73, RxPdu_11, TxPdu_11] */
  { /*    11 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_1d3adefb, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_012fc1e4, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_012fc1e4, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          1u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             1u,                             7u },  /* [CanTpRxNSdu_7e56306d] */  /* [CanTpRxNSdu_7e56306d, RxPdu_1, TxPdu_1] */
  { /*    12 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_d6a59fd3, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2828ffd9, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         23u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_006d7169] */  /* [CanTpRxNSdu_006d7169, RxPdu_23] */
  { /*    13 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_e4e4d778, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_5e5e67e3, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         12u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_b3e928e8] */  /* [CanTpRxNSdu_b3e928e8, RxPdu_12] */
  { /*    14 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRSrcPdu_PduRSrcPdu_4399556e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_c557c89e, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_c557c89e, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          2u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             2u,                             8u },  /* [CanTpRxNSdu_d8286eb1] */  /* [CanTpRxNSdu_d8286eb1, RxPdu_2, TxPdu_2] */
  { /*    15 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dab59121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_eed79f7d, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         19u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_13c303b2] */  /* [CanTpRxNSdu_13c303b2, RxPdu_19] */
  { /*    16 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_61d1e2e6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_31268e73, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         22u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_e9868279] */  /* [CanTpRxNSdu_e9868279, RxPdu_22] */
  { /*    17 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_55bb6522, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_7b3b0f4d, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         15u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_b593107a] */  /* [CanTpRxNSdu_b593107a, RxPdu_15] */
  { /*    18 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_d26a3583, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_20042bf7, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_20042bf7, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          4u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             4u,                             9u },  /* [CanTpRxNSdu_9a31514e] */  /* [CanTpRxNSdu_9a31514e, RxPdu_4, TxPdu_4] */
  { /*    19 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRSrcPdu_PduRSrcPdu_199df235, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_d2d2ac8c, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_d2d2ac8c, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          3u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             3u,                            10u },  /* [CanTpRxNSdu_d1b47cad] */  /* [CanTpRxNSdu_d1b47cad, RxPdu_3, TxPdu_3] */
  { /*    20 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_917a13f6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_5d81c8c9, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_5d81c8c9, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,         10u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            10u,                            11u },  /* [CanTpRxNSdu_42fe9847] */  /* [CanTpRxNSdu_42fe9847, RxPdu_10, TxPdu_10] */
  { /*    21 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_ec57064f, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_77e5ffa1, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         17u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_296d7662] */  /* [CanTpRxNSdu_296d7662, RxPdu_17] */
  { /*    22 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_acafabed, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_e05b87d2, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         18u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_321c67e6] */  /* [CanTpRxNSdu_321c67e6, RxPdu_18] */
  { /*    23 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_6f3aa62d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a219ac95, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         20u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG }   /* [CanTpRxNSdu_27371a31] */  /* [CanTpRxNSdu_27371a31, RxPdu_20] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_04
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_04
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_04[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxFcPduId                                                                 PduRRxSduId                              RxPduId                                     TxFcPduConfirmationPduId                        CanType                        NAr   NBr  NCr   RxMaxPayloadLength  RxPduMapIdx  RxTaType                             STmin  TxPduMapIdx                     TxSduCfgIdx                           Comment                            Referable Keys */
  { /*     0 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dbaad71c, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_60bfe9ef, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         14u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_8ebb4dba] */  /* [CanTpRxNSdu_8ebb4dba, RxPdu_14] */
  { /*     1 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_09f61e64, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_24fb9ff2, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         21u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_78c5c2e6] */  /* [CanTpRxNSdu_78c5c2e6, RxPdu_21] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_d26a3583, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_492bb4b1, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_492bb4b1, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          4u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             4u,                             0u },  /* [CanTpRxNSdu_b5963bcd] */  /* [CanTpRxNSdu_b5963bcd, RxPdu_4, TxPdu_4] */
  { /*     3 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_017e0121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_604a7f84, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         13u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_bcfcbb59] */  /* [CanTpRxNSdu_bcfcbb59, RxPdu_13] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_7bb4cf60, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_26482297, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_26482297, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          0u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             0u,                             1u },  /* [CanTpRxNSdu_8b07fec8] */  /* [CanTpRxNSdu_8b07fec8, RxPdu_0, TxPdu_0] */
  { /*     5 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_acafabed, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_4664bd26, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         18u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_5245b630] */  /* [CanTpRxNSdu_5245b630, RxPdu_18] */
  { /*     6 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_e4e4d778, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_09f211c0, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         12u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_17721f14] */  /* [CanTpRxNSdu_17721f14, RxPdu_12] */
  { /*     7 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_88550f3d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_08415e34, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_08415e34, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          5u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             5u,                             2u },  /* [CanTpRxNSdu_808a4832] */  /* [CanTpRxNSdu_808a4832, RxPdu_5, TxPdu_5] */
  { /*     8 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRSrcPdu_PduRSrcPdu_c794190e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_50d05297, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_50d05297, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          9u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             9u,                             3u },  /* [CanTpRxNSdu_be955aab] */  /* [CanTpRxNSdu_be955aab, RxPdu_9, TxPdu_9] */
  { /*     9 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_6f3aa62d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_0e79eefd, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         20u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_bd76dbce] */  /* [CanTpRxNSdu_bd76dbce, RxPdu_20] */
  { /*    10 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dab59121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_ef2320d0, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         19u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_b5beb7bd] */  /* [CanTpRxNSdu_b5beb7bd, RxPdu_19] */
  { /*    11 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRSrcPdu_PduRSrcPdu_199df235, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_fa7e2a6b, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_fa7e2a6b, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          3u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             3u,                             4u },  /* [CanTpRxNSdu_39b7733b] */  /* [CanTpRxNSdu_39b7733b, RxPdu_3, TxPdu_3] */
  { /*    12 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_917a13f6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a83ee65f, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_a83ee65f, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,         10u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            10u,                             5u },  /* [CanTpRxNSdu_35dbd553] */  /* [CanTpRxNSdu_35dbd553, RxPdu_10, TxPdu_10] */
  { /*    13 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_ec57064f, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_af4492d7, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         17u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_fe5046bf] */  /* [CanTpRxNSdu_fe5046bf, RxPdu_17] */
  { /*    14 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_d6a59fd3, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_0a9d3920, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         23u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_b87fedc1] */  /* [CanTpRxNSdu_b87fedc1, RxPdu_23] */
  { /*    15 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_55bb6522, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_cb01d19c, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         15u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_8a7f8276] */  /* [CanTpRxNSdu_8a7f8276, RxPdu_15] */
  { /*    16 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_1d3adefb, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_c8e61be1, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_c8e61be1, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          1u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             1u,                             6u },  /* [CanTpRxNSdu_71a17bb4] */  /* [CanTpRxNSdu_71a17bb4, RxPdu_1, TxPdu_1] */
  { /*    17 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_5808d905, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_3750ca88, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_3750ca88, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          7u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             7u,                             7u },  /* [CanTpRxNSdu_0a6cebaf] */  /* [CanTpRxNSdu_0a6cebaf, RxPdu_7, TxPdu_7] */
  { /*    18 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRSrcPdu_PduRSrcPdu_58857336, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_240c21b4, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_240c21b4, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          8u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             8u,                             8u },  /* [CanTpRxNSdu_c1932d51] */  /* [CanTpRxNSdu_c1932d51, RxPdu_8, TxPdu_8] */
  { /*    19 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRSrcPdu_PduRSrcPdu_4399556e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_8274ce50, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_8274ce50, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          2u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             2u,                             9u },  /* [CanTpRxNSdu_6e6d2a7f] */  /* [CanTpRxNSdu_6e6d2a7f, RxPdu_2, TxPdu_2] */
  { /*    20 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRSrcPdu_PduRSrcPdu_ce8fc2bd, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2dbb61ae, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_2dbb61ae, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,         11u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            11u,                            10u },  /* [CanTpRxNSdu_dac1b156] */  /* [CanTpRxNSdu_dac1b156, RxPdu_11, TxPdu_11] */
  { /*    21 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_f2e56351, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_cec4b5a4, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_cec4b5a4, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          6u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             6u,                            11u },  /* [CanTpRxNSdu_8a9f4292] */  /* [CanTpRxNSdu_8a9f4292, RxPdu_6, TxPdu_6] */
  { /*    22 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_12ce5aa9, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_8e0f0117, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         16u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_dcc3cd8a] */  /* [CanTpRxNSdu_dcc3cd8a, RxPdu_16] */
  { /*    23 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_61d1e2e6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_e3fed264, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         22u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG }   /* [CanTpRxNSdu_fe9ab262] */  /* [CanTpRxNSdu_fe9ab262, RxPdu_22] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_05
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_05[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxFcPduId                                                                 PduRRxSduId                              RxPduId                                     TxFcPduConfirmationPduId                        CanType                        NAr   NBr  NCr   RxMaxPayloadLength  RxPduMapIdx  RxTaType                             STmin  TxPduMapIdx                     TxSduCfgIdx                           Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_d26a3583, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_e3414a64, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_e3414a64, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          4u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             4u,                             0u },  /* [CanTpRxNSdu_0adc25ca] */  /* [CanTpRxNSdu_0adc25ca, RxPdu_4, TxPdu_4] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRSrcPdu_PduRSrcPdu_4399556e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a9a436aa, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_a9a436aa, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          2u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             2u,                             1u },  /* [CanTpRxNSdu_7f902975] */  /* [CanTpRxNSdu_7f902975, RxPdu_2, TxPdu_2] */
  { /*     2 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_6f3aa62d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_aa895199, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         20u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_1686abd3] */  /* [CanTpRxNSdu_1686abd3, RxPdu_20] */
  { /*     3 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_ec57064f, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_95b4ca6b, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         17u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_647cf724] */  /* [CanTpRxNSdu_647cf724, RxPdu_17] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_5808d905, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_7c9c8a40, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_7c9c8a40, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          7u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             7u,                             2u },  /* [CanTpRxNSdu_da5fea54] */  /* [CanTpRxNSdu_da5fea54, RxPdu_7, TxPdu_7] */
  { /*     5 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_acafabed, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_41a3f494, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         18u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_48aeef23] */  /* [CanTpRxNSdu_48aeef23, RxPdu_18] */
  { /*     6 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_12ce5aa9, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_748cf4a0, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         16u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_f5437413] */  /* [CanTpRxNSdu_f5437413, RxPdu_16] */
  { /*     7 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_7bb4cf60, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_d446074a, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_d446074a, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          0u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             0u,                             3u },  /* [CanTpRxNSdu_c0427f66] */  /* [CanTpRxNSdu_c0427f66, RxPdu_0, TxPdu_0] */
  { /*     8 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_f2e56351, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a3c73065, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_a3c73065, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          6u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             6u,                             4u },  /* [CanTpRxNSdu_28542b52] */  /* [CanTpRxNSdu_28542b52, RxPdu_6, TxPdu_6] */
  { /*     9 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_1d3adefb, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_ca69fbd1, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_ca69fbd1, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          1u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             1u,                             5u },  /* [CanTpRxNSdu_ddc06ff6] */  /* [CanTpRxNSdu_ddc06ff6, RxPdu_1, TxPdu_1] */
  { /*    10 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dbaad71c, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_4a313afd, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         14u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_938c4b7e] */  /* [CanTpRxNSdu_938c4b7e, RxPdu_14] */
  { /*    11 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRSrcPdu_PduRSrcPdu_58857336, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_ae92d8c2, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_ae92d8c2, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          8u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             8u,                             6u },  /* [CanTpRxNSdu_7de58f85] */  /* [CanTpRxNSdu_7de58f85, RxPdu_8, TxPdu_8] */
  { /*    12 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_d6a59fd3, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_634576d0, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         23u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_8bd00a19] */  /* [CanTpRxNSdu_8bd00a19, RxPdu_23] */
  { /*    13 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dab59121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_00542158, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         19u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_66d3fe72] */  /* [CanTpRxNSdu_66d3fe72, RxPdu_19] */
  { /*    14 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_55bb6522, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_acecf7b1, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         15u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_e0f3e280] */  /* [CanTpRxNSdu_e0f3e280, RxPdu_15] */
  { /*    15 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_88550f3d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_102ffa27, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_102ffa27, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          5u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             5u,                             7u },  /* [CanTpRxNSdu_5a9726cc] */  /* [CanTpRxNSdu_5a9726cc, RxPdu_5, TxPdu_5] */
  { /*    16 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_09f61e64, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_ad161582, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         21u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_ff05d790] */  /* [CanTpRxNSdu_ff05d790, RxPdu_21] */
  { /*    17 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRSrcPdu_PduRSrcPdu_ce8fc2bd, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_1cdbe534, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_1cdbe534, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,         11u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            11u,                             8u },  /* [CanTpRxNSdu_8d39cc24] */  /* [CanTpRxNSdu_8d39cc24, RxPdu_11, TxPdu_11] */
  { /*    18 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_e4e4d778, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_67f2735b, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         12u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_6673db92] */  /* [CanTpRxNSdu_6673db92, RxPdu_12] */
  { /*    19 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_917a13f6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_af200a9a, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_af200a9a, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,         10u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            10u,                             9u },  /* [CanTpRxNSdu_244becaa] */  /* [CanTpRxNSdu_244becaa, RxPdu_10, TxPdu_10] */
  { /*    20 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRSrcPdu_PduRSrcPdu_c794190e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_6e1a863d, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_6e1a863d, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          9u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             9u,                            10u },  /* [CanTpRxNSdu_7d9f3885] */  /* [CanTpRxNSdu_7d9f3885, RxPdu_9, TxPdu_9] */
  { /*    21 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_61d1e2e6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_8cec51f3, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         22u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_a810d4a0] */  /* [CanTpRxNSdu_a810d4a0, RxPdu_22] */
  { /*    22 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRSrcPdu_PduRSrcPdu_199df235, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_684eb36e, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_684eb36e, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          3u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             3u,                            11u },  /* [CanTpRxNSdu_5075f9f9] */  /* [CanTpRxNSdu_5075f9f9, RxPdu_3, TxPdu_3] */
  { /*    23 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_017e0121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_964d0a86, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         13u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG }   /* [CanTpRxNSdu_6ada5e57] */  /* [CanTpRxNSdu_6ada5e57, RxPdu_13] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_06
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_06
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_06[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxFcPduId                                                                 PduRRxSduId                              RxPduId                                     TxFcPduConfirmationPduId                        CanType                        NAr   NBr  NCr   RxMaxPayloadLength  RxPduMapIdx  RxTaType                             STmin  TxPduMapIdx                     TxSduCfgIdx                           Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_917a13f6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_b8b6db31, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_b8b6db31, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,         10u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            10u,                             0u },  /* [CanTpRxNSdu_cbb41ec6] */  /* [CanTpRxNSdu_cbb41ec6, RxPdu_10, TxPdu_10] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRSrcPdu_PduRSrcPdu_ce8fc2bd, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_8e11574f, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_8e11574f, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,         11u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            11u,                             1u },  /* [CanTpRxNSdu_e3788fc6] */  /* [CanTpRxNSdu_e3788fc6, RxPdu_11, TxPdu_11] */
  { /*     2 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dab59121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_23eeaf8e, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         19u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_d8e283f4] */  /* [CanTpRxNSdu_d8e283f4, RxPdu_19] */
  { /*     3 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_7bb4cf60, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2b023a7d, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_2b023a7d, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          0u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             0u,                             2u },  /* [CanTpRxNSdu_c912f74f] */  /* [CanTpRxNSdu_c912f74f, RxPdu_0, TxPdu_0] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_88550f3d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_4069e760, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_4069e760, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          5u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             5u,                             3u },  /* [CanTpRxNSdu_b4077489] */  /* [CanTpRxNSdu_b4077489, RxPdu_5, TxPdu_5] */
  { /*     5 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRSrcPdu_PduRSrcPdu_199df235, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_267926b4, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_267926b4, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          3u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             3u,                             4u },  /* [CanTpRxNSdu_f5655a25] */  /* [CanTpRxNSdu_f5655a25, RxPdu_3, TxPdu_3] */
  { /*     6 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_12ce5aa9, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_235fdddd, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         16u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_a193aec9] */  /* [CanTpRxNSdu_a193aec9, RxPdu_16] */
  { /*     7 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_f2e56351, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_cc681870, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_cc681870, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          6u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             6u,                             5u },  /* [CanTpRxNSdu_1e2714e5] */  /* [CanTpRxNSdu_1e2714e5, RxPdu_6, TxPdu_6] */
  { /*     8 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_017e0121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_58be1a07, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         13u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_fb9ea522] */  /* [CanTpRxNSdu_fb9ea522, RxPdu_13] */
  { /*     9 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_55bb6522, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_d837d615, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         15u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_b6ad447c] */  /* [CanTpRxNSdu_b6ad447c, RxPdu_15] */
  { /*    10 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRSrcPdu_PduRSrcPdu_c794190e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_1ed3ddf2, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_1ed3ddf2, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          9u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             9u,                             6u },  /* [CanTpRxNSdu_bcb07df3] */  /* [CanTpRxNSdu_bcb07df3, RxPdu_9, TxPdu_9] */
  { /*    11 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_acafabed, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_f2c3088b, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         18u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_7800f5f8] */  /* [CanTpRxNSdu_7800f5f8, RxPdu_18] */
  { /*    12 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_ec57064f, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2c024d1e, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         17u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_bbac6d3d] */  /* [CanTpRxNSdu_bbac6d3d, RxPdu_17] */
  { /*    13 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_5808d905, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_b70ae635, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_b70ae635, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          7u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             7u,                             7u },  /* [CanTpRxNSdu_71ff2702] */  /* [CanTpRxNSdu_71ff2702, RxPdu_7, TxPdu_7] */
  { /*    14 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_1d3adefb, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_caab25b0, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_caab25b0, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          1u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             1u,                             8u },  /* [CanTpRxNSdu_1825ea7b] */  /* [CanTpRxNSdu_1825ea7b, RxPdu_1, TxPdu_1] */
  { /*    15 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRSrcPdu_PduRSrcPdu_4399556e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_9802bf78, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_9802bf78, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          2u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             2u,                             9u },  /* [CanTpRxNSdu_7019f6f9] */  /* [CanTpRxNSdu_7019f6f9, RxPdu_2, TxPdu_2] */
  { /*    16 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_6f3aa62d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_ab223cd1, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         20u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_35b990b3] */  /* [CanTpRxNSdu_35b990b3, RxPdu_20] */
  { /*    17 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRSrcPdu_PduRSrcPdu_58857336, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_74a06159, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_74a06159, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          8u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             8u,                            10u },  /* [CanTpRxNSdu_ff9066e8] */  /* [CanTpRxNSdu_ff9066e8, RxPdu_8, TxPdu_8] */
  { /*    18 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_e4e4d778, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_1d379936, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         12u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_70587782] */  /* [CanTpRxNSdu_70587782, RxPdu_12] */
  { /*    19 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_09f61e64, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_277f419b, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         21u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_d8dde2ce] */  /* [CanTpRxNSdu_d8dde2ce, RxPdu_21] */
  { /*    20 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_61d1e2e6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_af00b3fb, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         22u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_96757754] */  /* [CanTpRxNSdu_96757754, RxPdu_22] */
  { /*    21 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dbaad71c, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_55314ea3, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         14u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_28543443] */  /* [CanTpRxNSdu_28543443, RxPdu_14] */
  { /*    22 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_d26a3583, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_9440c6c7, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_9440c6c7, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          4u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             4u,                            11u },  /* [CanTpRxNSdu_a01029ae] */  /* [CanTpRxNSdu_a01029ae, RxPdu_4, TxPdu_4] */
  { /*    23 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_d6a59fd3, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_b6120ed7, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         23u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG }   /* [CanTpRxNSdu_192cc3c6] */  /* [CanTpRxNSdu_192cc3c6, RxPdu_23] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_07
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_07
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_07[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxFcPduId                                                                 PduRRxSduId                              RxPduId                                     TxFcPduConfirmationPduId                        CanType                        NAr   NBr  NCr   RxMaxPayloadLength  RxPduMapIdx  RxTaType                             STmin  TxPduMapIdx                     TxSduCfgIdx                           Comment                            Referable Keys */
  { /*     0 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_017e0121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_01b31906, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         13u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_8ce7f960] */  /* [CanTpRxNSdu_8ce7f960, RxPdu_13] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRSrcPdu_PduRSrcPdu_c794190e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_fd47e566, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_fd47e566, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          9u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             9u,                             0u },  /* [CanTpRxNSdu_40aa540d] */  /* [CanTpRxNSdu_40aa540d, RxPdu_9, TxPdu_9] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_f2e56351, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_7c60d701, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_7c60d701, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          6u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             6u,                             1u },  /* [CanTpRxNSdu_1be7398e] */  /* [CanTpRxNSdu_1be7398e, RxPdu_6, TxPdu_6] */
  { /*     3 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dbaad71c, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_6e1fb67f, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         14u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_b639676a] */  /* [CanTpRxNSdu_b639676a, RxPdu_14] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRSrcPdu_PduRSrcPdu_ce8fc2bd, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_ee206532, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_ee206532, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,         11u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            11u,                             2u },  /* [CanTpRxNSdu_35203c39] */  /* [CanTpRxNSdu_35203c39, RxPdu_11, TxPdu_11] */
  { /*     5 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_12ce5aa9, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_b9befcac, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         16u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_9f8c2215] */  /* [CanTpRxNSdu_9f8c2215, RxPdu_16] */
  { /*     6 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_1d3adefb, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_1f3d3e0c, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_1f3d3e0c, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          1u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             1u,                             3u },  /* [CanTpRxNSdu_98e0a949] */  /* [CanTpRxNSdu_98e0a949, RxPdu_1, TxPdu_1] */
  { /*     7 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRSrcPdu_PduRSrcPdu_4399556e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_ea8aa2c0, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_ea8aa2c0, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          2u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             2u,                             4u },  /* [CanTpRxNSdu_100f5ca2] */  /* [CanTpRxNSdu_100f5ca2, RxPdu_2, TxPdu_2] */
  { /*     8 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_88550f3d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_8b786657, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_8b786657, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          5u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             5u,                             5u },  /* [CanTpRxNSdu_3216b4ff] */  /* [CanTpRxNSdu_3216b4ff, RxPdu_5, TxPdu_5] */
  { /*     9 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_7bb4cf60, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_bfccbcc5, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_bfccbcc5, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          0u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             0u,                             6u },  /* [CanTpRxNSdu_6816740d] */  /* [CanTpRxNSdu_6816740d, RxPdu_0, TxPdu_0] */
  { /*    10 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_5808d905, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_32a3ebca, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_32a3ebca, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          7u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             7u,                             7u },  /* [CanTpRxNSdu_605d1a3a] */  /* [CanTpRxNSdu_605d1a3a, RxPdu_7, TxPdu_7] */
  { /*    11 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_09f61e64, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_6ef3cf96, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         21u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_2bf3c190] */  /* [CanTpRxNSdu_2bf3c190, RxPdu_21] */
  { /*    12 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_e4e4d778, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a3c8ef02, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         12u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_b86f24ed] */  /* [CanTpRxNSdu_b86f24ed, RxPdu_12] */
  { /*    13 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_d6a59fd3, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_83f5a036, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         23u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_761ee134] */  /* [CanTpRxNSdu_761ee134, RxPdu_23] */
  { /*    14 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRSrcPdu_PduRSrcPdu_58857336, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_87c67036, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_87c67036, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          8u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             8u,                             8u },  /* [CanTpRxNSdu_055d88c0] */  /* [CanTpRxNSdu_055d88c0, RxPdu_8, TxPdu_8] */
  { /*    15 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_d26a3583, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_8650b453, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_8650b453, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          4u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             4u,                             9u },  /* [CanTpRxNSdu_0a60edb0] */  /* [CanTpRxNSdu_0a60edb0, RxPdu_4, TxPdu_4] */
  { /*    16 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dab59121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_9d5b4730, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         19u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_a9da1dde] */  /* [CanTpRxNSdu_a9da1dde, RxPdu_19] */
  { /*    17 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_6f3aa62d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_6f33a27f, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         20u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_87fb2a09] */  /* [CanTpRxNSdu_87fb2a09, RxPdu_20] */
  { /*    18 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_ec57064f, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_889c2a4d, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         17u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_d7b9ba5a] */  /* [CanTpRxNSdu_d7b9ba5a, RxPdu_17] */
  { /*    19 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_61d1e2e6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_9fbea91a, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         22u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_21707157] */  /* [CanTpRxNSdu_21707157, RxPdu_22] */
  { /*    20 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_55bb6522, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_b34f2acd, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         15u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_55a66e29] */  /* [CanTpRxNSdu_55a66e29, RxPdu_15] */
  { /*    21 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_917a13f6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_74140790, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_74140790, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,         10u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            10u,                            10u },  /* [CanTpRxNSdu_2888d97c] */  /* [CanTpRxNSdu_2888d97c, RxPdu_10, TxPdu_10] */
  { /*    22 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_acafabed, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_4ebc6152, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         18u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_34d1d4f6] */  /* [CanTpRxNSdu_34d1d4f6, RxPdu_18] */
  { /*    23 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRSrcPdu_PduRSrcPdu_199df235, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_ccc91718, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_ccc91718, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          3u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             3u,                            11u }   /* [CanTpRxNSdu_f984455c] */  /* [CanTpRxNSdu_f984455c, RxPdu_3, TxPdu_3] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_08
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_08
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_08[24] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    LoLayerTxFcPduId                                                                 PduRRxSduId                              RxPduId                                     TxFcPduConfirmationPduId                        CanType                        NAr   NBr  NCr   RxMaxPayloadLength  RxPduMapIdx  RxTaType                             STmin  TxPduMapIdx                     TxSduCfgIdx                           Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRSrcPdu_PduRSrcPdu_199df235, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a9a1742e, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_a9a1742e, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          3u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             3u,                             0u },  /* [CanTpRxNSdu_5ea61dee] */  /* [CanTpRxNSdu_5ea61dee, RxPdu_3, TxPdu_3] */
  { /*     1 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_09f61e64, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_1fa00345, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         21u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_d93a2016] */  /* [CanTpRxNSdu_d93a2016, RxPdu_21] */
  { /*     2 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_ec57064f, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_944dd35d, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         17u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_cee402a3] */  /* [CanTpRxNSdu_cee402a3, RxPdu_17] */
  { /*     3 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_017e0121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_c1a26365, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         13u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_796f9cad] */  /* [CanTpRxNSdu_796f9cad, RxPdu_13] */
  { /*     4 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_6f3aa62d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2a62e703, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         20u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_89d4d963] */  /* [CanTpRxNSdu_89d4d963, RxPdu_20] */
  { /*     5 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_acafabed, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_25164214, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         18u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_d821701d] */  /* [CanTpRxNSdu_d821701d, RxPdu_18] */
  { /*     6 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRSrcPdu_PduRSrcPdu_ce8fc2bd, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_ecfc16e9, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_ecfc16e9, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,         11u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            11u,                             1u },  /* [CanTpRxNSdu_fe897178] */  /* [CanTpRxNSdu_fe897178, RxPdu_11, TxPdu_11] */
  { /*     7 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRSrcPdu_PduRSrcPdu_c794190e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_9315ebfa, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_9315ebfa, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          9u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             9u,                             2u },  /* [CanTpRxNSdu_382889a1] */  /* [CanTpRxNSdu_382889a1, RxPdu_9, TxPdu_9] */
  { /*     8 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_e4e4d778, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_f673eb66, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         12u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_38bfaa92] */  /* [CanTpRxNSdu_38bfaa92, RxPdu_12] */
  { /*     9 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_88550f3d, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_8beca7d7, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_8beca7d7, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          5u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             5u,                             3u },  /* [CanTpRxNSdu_125a8101] */  /* [CanTpRxNSdu_125a8101, RxPdu_5, TxPdu_5] */
  { /*    10 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_7bb4cf60, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_5235cea4, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_5235cea4, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          0u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             0u,                             4u },  /* [CanTpRxNSdu_9b170e76] */  /* [CanTpRxNSdu_9b170e76, RxPdu_0, TxPdu_0] */
  { /*    11 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dbaad71c, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_9b2ade95, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         14u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_fab1e11a] */  /* [CanTpRxNSdu_fab1e11a, RxPdu_14] */
  { /*    12 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_d6a59fd3, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_e1347c6e, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         23u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_18f2ade7] */  /* [CanTpRxNSdu_18f2ade7, RxPdu_23] */
  { /*    13 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_61d1e2e6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_654adf9b, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         22u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_bf84955c] */  /* [CanTpRxNSdu_bf84955c, RxPdu_22] */
  { /*    14 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_f2e56351, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_999c2b0a, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_999c2b0a, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          6u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             6u,                             5u },  /* [CanTpRxNSdu_0d1ea855] */  /* [CanTpRxNSdu_0d1ea855, RxPdu_6, TxPdu_6] */
  { /*    15 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_917a13f6, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_eeb961d3, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_eeb961d3, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,         10u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                            10u,                             6u },  /* [CanTpRxNSdu_406ac1d2] */  /* [CanTpRxNSdu_406ac1d2, RxPdu_10, TxPdu_10] */
  { /*    16 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRSrcPdu_PduRSrcPdu_4399556e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a9cb123b, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_a9cb123b, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          2u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             2u,                             7u },  /* [CanTpRxNSdu_01773b70] */  /* [CanTpRxNSdu_01773b70, RxPdu_2, TxPdu_2] */
  { /*    17 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRSrcPdu_PduRSrcPdu_58857336, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_4a8b6b3b, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_4a8b6b3b, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          8u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             8u,                             8u },  /* [CanTpRxNSdu_2062e733] */  /* [CanTpRxNSdu_2062e733, RxPdu_8, TxPdu_8] */
  { /*    18 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_55bb6522, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_3b063fb4, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         15u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_77935e90] */  /* [CanTpRxNSdu_77935e90, RxPdu_15] */
  { /*    19 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRSrcPdu_PduRSrcPdu_1d3adefb, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_7def204a, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_7def204a, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          1u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             1u,                             9u },  /* [CanTpRxNSdu_92ce2a9d] */  /* [CanTpRxNSdu_92ce2a9d, RxPdu_1, TxPdu_1] */
  { /*    20 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRSrcPdu_PduRSrcPdu_5808d905, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_28b1b5df, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_28b1b5df, CANTP_CAN20_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                 7u,          7u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             7u,                            10u },  /* [CanTpRxNSdu_3fa592e1] */  /* [CanTpRxNSdu_3fa592e1, RxPdu_7, TxPdu_7] */
  { /*    21 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_dab59121, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_9f3977a1, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                63u,         19u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_110562d5] */  /* [CanTpRxNSdu_110562d5, RxPdu_19] */
  { /*    22 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRSrcPdu_PduRSrcPdu_d26a3583, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_056f526e, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_056f526e, CANTP_CANFD_CANTYPEOFRXSDUCFG, 201u,  3u, 201u,                63u,          4u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             4u,                            11u },  /* [CanTpRxNSdu_1f237be1] */  /* [CanTpRxNSdu_1f237be1, RxPdu_4, TxPdu_4] */
  { /*    23 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_PduRSrcPdu_12ce5aa9, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_599d72c1, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u, 21u,  11u,                 7u,         16u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXPDUMAPIDXOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG }   /* [CanTpRxNSdu_0999e59b] */  /* [CanTpRxNSdu_0999e59b, RxPdu_16] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduSnv2Hdl
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduSnv2Hdl
  \brief  CanTpRxNSdu SNV to Handle (i.e. internal index) mapping
  \details
  Element         Description
  RxNSduHdlIdx    the index of the 0:1 relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduSnv2HdlType, CANTP_CONST) CanTp_RxSduSnv2Hdl[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxNSduHdlIdx        Comment */
  { /*     0 */           0u },  /* [CanTpRxNSdu_d62c6608] */
  { /*     1 */           1u },  /* [CanTpRxNSdu_c5537cf0] */
  { /*     2 */           2u },  /* [CanTpRxNSdu_bd9a0635] */
  { /*     3 */           3u },  /* [CanTpRxNSdu_e307f5e7] */
  { /*     4 */           4u },  /* [CanTpRxNSdu_24fdb8bb] */
  { /*     5 */           5u },  /* [CanTpRxNSdu_2fa399b3] */
  { /*     6 */           6u },  /* [CanTpRxNSdu_7f5185ac] */
  { /*     7 */           7u },  /* [CanTpRxNSdu_b76651b3] */
  { /*     8 */           8u },  /* [CanTpRxNSdu_6a4050a8] */
  { /*     9 */           9u },  /* [CanTpRxNSdu_db835be6] */
  { /*    10 */          10u },  /* [CanTpRxNSdu_e66ca3b9] */
  { /*    11 */          11u },  /* [CanTpRxNSdu_c5ebb271] */
  { /*    12 */          12u },  /* [CanTpRxNSdu_0d8cb540] */
  { /*    13 */          13u },  /* [CanTpRxNSdu_d603b303] */
  { /*    14 */          14u },  /* [CanTpRxNSdu_0057d142] */
  { /*    15 */          15u },  /* [CanTpRxNSdu_c5aa076c] */
  { /*    16 */          16u },  /* [CanTpRxNSdu_64228dd8] */
  { /*    17 */          17u },  /* [CanTpRxNSdu_8ea01f46] */
  { /*    18 */          18u },  /* [CanTpRxNSdu_80a26c19] */
  { /*    19 */          19u },  /* [CanTpRxNSdu_b509cdf9] */
  { /*    20 */          20u },  /* [CanTpRxNSdu_6b1dcdd5] */
  { /*    21 */          21u },  /* [CanTpRxNSdu_3a469f02] */
  { /*    22 */          22u },  /* [CanTpRxNSdu_275a18b1] */
  { /*    23 */          23u }   /* [CanTpRxNSdu_f486fe77] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_01
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_01[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPdu2RxSduInd      Referable Keys */
  /*     0 */              6u,  /* [TxPdu_0] */
  /*     1 */              1u,  /* [TxPdu_1] */
  /*     2 */              5u,  /* [TxPdu_2] */
  /*     3 */             20u,  /* [TxPdu_3] */
  /*     4 */             10u,  /* [TxPdu_4] */
  /*     5 */              4u,  /* [TxPdu_5] */
  /*     6 */             16u,  /* [TxPdu_6] */
  /*     7 */              9u,  /* [TxPdu_7] */
  /*     8 */              2u,  /* [TxPdu_8] */
  /*     9 */             14u,  /* [TxPdu_9] */
  /*    10 */             21u,  /* [TxPdu_10] */
  /*    11 */             23u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_02
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_02
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_02[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPdu2RxSduInd      Referable Keys */
  /*     0 */              4u,  /* [TxPdu_0] */
  /*     1 */             13u,  /* [TxPdu_1] */
  /*     2 */             17u,  /* [TxPdu_2] */
  /*     3 */              9u,  /* [TxPdu_3] */
  /*     4 */             16u,  /* [TxPdu_4] */
  /*     5 */              5u,  /* [TxPdu_5] */
  /*     6 */             11u,  /* [TxPdu_6] */
  /*     7 */             14u,  /* [TxPdu_7] */
  /*     8 */             15u,  /* [TxPdu_8] */
  /*     9 */              1u,  /* [TxPdu_9] */
  /*    10 */             12u,  /* [TxPdu_10] */
  /*    11 */              3u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_03
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_03
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_03[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPdu2RxSduInd      Referable Keys */
  /*     0 */              5u,  /* [TxPdu_0] */
  /*     1 */             11u,  /* [TxPdu_1] */
  /*     2 */             14u,  /* [TxPdu_2] */
  /*     3 */             19u,  /* [TxPdu_3] */
  /*     4 */             18u,  /* [TxPdu_4] */
  /*     5 */              4u,  /* [TxPdu_5] */
  /*     6 */              9u,  /* [TxPdu_6] */
  /*     7 */              2u,  /* [TxPdu_7] */
  /*     8 */              3u,  /* [TxPdu_8] */
  /*     9 */              7u,  /* [TxPdu_9] */
  /*    10 */             20u,  /* [TxPdu_10] */
  /*    11 */             10u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_04
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_04
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_04[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPdu2RxSduInd      Referable Keys */
  /*     0 */              4u,  /* [TxPdu_0] */
  /*     1 */             16u,  /* [TxPdu_1] */
  /*     2 */             19u,  /* [TxPdu_2] */
  /*     3 */             11u,  /* [TxPdu_3] */
  /*     4 */              2u,  /* [TxPdu_4] */
  /*     5 */              7u,  /* [TxPdu_5] */
  /*     6 */             21u,  /* [TxPdu_6] */
  /*     7 */             17u,  /* [TxPdu_7] */
  /*     8 */             18u,  /* [TxPdu_8] */
  /*     9 */              8u,  /* [TxPdu_9] */
  /*    10 */             12u,  /* [TxPdu_10] */
  /*    11 */             20u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_05
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_05[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPdu2RxSduInd      Referable Keys */
  /*     0 */              7u,  /* [TxPdu_0] */
  /*     1 */              9u,  /* [TxPdu_1] */
  /*     2 */              1u,  /* [TxPdu_2] */
  /*     3 */             22u,  /* [TxPdu_3] */
  /*     4 */              0u,  /* [TxPdu_4] */
  /*     5 */             15u,  /* [TxPdu_5] */
  /*     6 */              8u,  /* [TxPdu_6] */
  /*     7 */              4u,  /* [TxPdu_7] */
  /*     8 */             11u,  /* [TxPdu_8] */
  /*     9 */             20u,  /* [TxPdu_9] */
  /*    10 */             19u,  /* [TxPdu_10] */
  /*    11 */             17u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_06
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_06
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_06[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPdu2RxSduInd      Referable Keys */
  /*     0 */              3u,  /* [TxPdu_0] */
  /*     1 */             14u,  /* [TxPdu_1] */
  /*     2 */             15u,  /* [TxPdu_2] */
  /*     3 */              5u,  /* [TxPdu_3] */
  /*     4 */             22u,  /* [TxPdu_4] */
  /*     5 */              4u,  /* [TxPdu_5] */
  /*     6 */              7u,  /* [TxPdu_6] */
  /*     7 */             13u,  /* [TxPdu_7] */
  /*     8 */             17u,  /* [TxPdu_8] */
  /*     9 */             10u,  /* [TxPdu_9] */
  /*    10 */              0u,  /* [TxPdu_10] */
  /*    11 */              1u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_07
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_07
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_07[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPdu2RxSduInd      Referable Keys */
  /*     0 */              9u,  /* [TxPdu_0] */
  /*     1 */              6u,  /* [TxPdu_1] */
  /*     2 */              7u,  /* [TxPdu_2] */
  /*     3 */             23u,  /* [TxPdu_3] */
  /*     4 */             15u,  /* [TxPdu_4] */
  /*     5 */              8u,  /* [TxPdu_5] */
  /*     6 */              2u,  /* [TxPdu_6] */
  /*     7 */             10u,  /* [TxPdu_7] */
  /*     8 */             14u,  /* [TxPdu_8] */
  /*     9 */              1u,  /* [TxPdu_9] */
  /*    10 */             21u,  /* [TxPdu_10] */
  /*    11 */              4u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_08
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_08
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_08[12] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     TxPdu2RxSduInd      Referable Keys */
  /*     0 */             10u,  /* [TxPdu_0] */
  /*     1 */             19u,  /* [TxPdu_1] */
  /*     2 */             16u,  /* [TxPdu_2] */
  /*     3 */              0u,  /* [TxPdu_3] */
  /*     4 */             22u,  /* [TxPdu_4] */
  /*     5 */              9u,  /* [TxPdu_5] */
  /*     6 */             14u,  /* [TxPdu_6] */
  /*     7 */             20u,  /* [TxPdu_7] */
  /*     8 */             17u,  /* [TxPdu_8] */
  /*     9 */              7u,  /* [TxPdu_9] */
  /*    10 */             15u,  /* [TxPdu_10] */
  /*    11 */              6u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_01
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_01[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPdu2TxSduInd      Referable Keys */
  /*     0 */              4u,  /* [TxPdu_0] */
  /*     1 */              0u,  /* [TxPdu_1] */
  /*     2 */              3u,  /* [TxPdu_2] */
  /*     3 */              9u,  /* [TxPdu_3] */
  /*     4 */              6u,  /* [TxPdu_4] */
  /*     5 */              2u,  /* [TxPdu_5] */
  /*     6 */              8u,  /* [TxPdu_6] */
  /*     7 */              5u,  /* [TxPdu_7] */
  /*     8 */              1u,  /* [TxPdu_8] */
  /*     9 */              7u,  /* [TxPdu_9] */
  /*    10 */             10u,  /* [TxPdu_10] */
  /*    11 */             11u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_02
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_02
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_02[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPdu2TxSduInd      Referable Keys */
  /*     0 */              2u,  /* [TxPdu_0] */
  /*     1 */              7u,  /* [TxPdu_1] */
  /*     2 */             11u,  /* [TxPdu_2] */
  /*     3 */              4u,  /* [TxPdu_3] */
  /*     4 */             10u,  /* [TxPdu_4] */
  /*     5 */              3u,  /* [TxPdu_5] */
  /*     6 */              5u,  /* [TxPdu_6] */
  /*     7 */              8u,  /* [TxPdu_7] */
  /*     8 */              9u,  /* [TxPdu_8] */
  /*     9 */              0u,  /* [TxPdu_9] */
  /*    10 */              6u,  /* [TxPdu_10] */
  /*    11 */              1u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_03
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_03
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_03[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPdu2TxSduInd      Referable Keys */
  /*     0 */              3u,  /* [TxPdu_0] */
  /*     1 */              7u,  /* [TxPdu_1] */
  /*     2 */              8u,  /* [TxPdu_2] */
  /*     3 */             10u,  /* [TxPdu_3] */
  /*     4 */              9u,  /* [TxPdu_4] */
  /*     5 */              2u,  /* [TxPdu_5] */
  /*     6 */              5u,  /* [TxPdu_6] */
  /*     7 */              0u,  /* [TxPdu_7] */
  /*     8 */              1u,  /* [TxPdu_8] */
  /*     9 */              4u,  /* [TxPdu_9] */
  /*    10 */             11u,  /* [TxPdu_10] */
  /*    11 */              6u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_04
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_04
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_04[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPdu2TxSduInd      Referable Keys */
  /*     0 */              1u,  /* [TxPdu_0] */
  /*     1 */              6u,  /* [TxPdu_1] */
  /*     2 */              9u,  /* [TxPdu_2] */
  /*     3 */              4u,  /* [TxPdu_3] */
  /*     4 */              0u,  /* [TxPdu_4] */
  /*     5 */              2u,  /* [TxPdu_5] */
  /*     6 */             11u,  /* [TxPdu_6] */
  /*     7 */              7u,  /* [TxPdu_7] */
  /*     8 */              8u,  /* [TxPdu_8] */
  /*     9 */              3u,  /* [TxPdu_9] */
  /*    10 */              5u,  /* [TxPdu_10] */
  /*    11 */             10u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_05
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_05[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPdu2TxSduInd      Referable Keys */
  /*     0 */              3u,  /* [TxPdu_0] */
  /*     1 */              5u,  /* [TxPdu_1] */
  /*     2 */              1u,  /* [TxPdu_2] */
  /*     3 */             11u,  /* [TxPdu_3] */
  /*     4 */              0u,  /* [TxPdu_4] */
  /*     5 */              7u,  /* [TxPdu_5] */
  /*     6 */              4u,  /* [TxPdu_6] */
  /*     7 */              2u,  /* [TxPdu_7] */
  /*     8 */              6u,  /* [TxPdu_8] */
  /*     9 */             10u,  /* [TxPdu_9] */
  /*    10 */              9u,  /* [TxPdu_10] */
  /*    11 */              8u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_06
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_06
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_06[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPdu2TxSduInd      Referable Keys */
  /*     0 */              2u,  /* [TxPdu_0] */
  /*     1 */              8u,  /* [TxPdu_1] */
  /*     2 */              9u,  /* [TxPdu_2] */
  /*     3 */              4u,  /* [TxPdu_3] */
  /*     4 */             11u,  /* [TxPdu_4] */
  /*     5 */              3u,  /* [TxPdu_5] */
  /*     6 */              5u,  /* [TxPdu_6] */
  /*     7 */              7u,  /* [TxPdu_7] */
  /*     8 */             10u,  /* [TxPdu_8] */
  /*     9 */              6u,  /* [TxPdu_9] */
  /*    10 */              0u,  /* [TxPdu_10] */
  /*    11 */              1u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_07
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_07
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_07[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPdu2TxSduInd      Referable Keys */
  /*     0 */              6u,  /* [TxPdu_0] */
  /*     1 */              3u,  /* [TxPdu_1] */
  /*     2 */              4u,  /* [TxPdu_2] */
  /*     3 */             11u,  /* [TxPdu_3] */
  /*     4 */              9u,  /* [TxPdu_4] */
  /*     5 */              5u,  /* [TxPdu_5] */
  /*     6 */              1u,  /* [TxPdu_6] */
  /*     7 */              7u,  /* [TxPdu_7] */
  /*     8 */              8u,  /* [TxPdu_8] */
  /*     9 */              0u,  /* [TxPdu_9] */
  /*    10 */             10u,  /* [TxPdu_10] */
  /*    11 */              2u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_08
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_08
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_08[12] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     TxPdu2TxSduInd      Referable Keys */
  /*     0 */              4u,  /* [TxPdu_0] */
  /*     1 */              9u,  /* [TxPdu_1] */
  /*     2 */              7u,  /* [TxPdu_2] */
  /*     3 */              0u,  /* [TxPdu_3] */
  /*     4 */             11u,  /* [TxPdu_4] */
  /*     5 */              3u,  /* [TxPdu_5] */
  /*     6 */              5u,  /* [TxPdu_6] */
  /*     7 */             10u,  /* [TxPdu_7] */
  /*     8 */              8u,  /* [TxPdu_8] */
  /*     9 */              2u,  /* [TxPdu_9] */
  /*    10 */              6u,  /* [TxPdu_10] */
  /*    11 */              1u   /* [TxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPduMap
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPduMap
  \brief  Table of Usage Infos of TxNPdus
  \details
  Element                Description
  CanId              
  TxPdu2RxSduEndIdx      the end index of the 0:n relation pointing to one of CanTp_TxPdu2RxSduInd
  TxPdu2RxSduStartIdx    the start index of the 0:n relation pointing to one of CanTp_TxPdu2RxSduInd
  TxPdu2TxSduEndIdx      the end index of the 0:n relation pointing to one of CanTp_TxPdu2TxSduInd
  TxPdu2TxSduStartIdx    the start index of the 0:n relation pointing to one of CanTp_TxPdu2TxSduInd
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxPduMapType, CANTP_CONST) CanTp_TxPduMap[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CanId        TxPdu2RxSduEndIdx  TxPdu2RxSduStartIdx  TxPdu2TxSduEndIdx  TxPdu2TxSduStartIdx        Referable Keys */
  { /*     0 */ 0x98DAF0D0u,                1u,                  0u,                1u,                  0u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_41a76716_Tx] */
  { /*     1 */ 0x98DAF1D0u,                2u,                  1u,                2u,                  1u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_25471ce8_Tx] */
  { /*     2 */ 0x98DAF4D0u,                3u,                  2u,                3u,                  2u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_19b4e511_Tx] */
  { /*     3 */ 0x98DAF5D0u,                4u,                  3u,                4u,                  3u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_4233d42d_Tx] */
  { /*     4 */ 0xD8DAF0B0u,                5u,                  4u,                5u,                  4u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_0aebd6ab_Tx] */
  { /*     5 */ 0x98DAF0B0u,                6u,                  5u,                6u,                  5u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_f6415fa5_Tx] */
  { /*     6 */ 0xD8DAF1B0u,                7u,                  6u,                7u,                  6u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_6e0bad55_Tx] */
  { /*     7 */ 0x98DAF1B0u,                8u,                  7u,                8u,                  7u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_25da435e_Tx] */
  { /*     8 */ 0x98DAF4B0u,                9u,                  8u,                9u,                  8u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_6c821aae_Tx] */
  { /*     9 */ 0xD8DAF4B0u,               10u,                  9u,               10u,                  9u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_37f68c50_Tx] */
  { /*    10 */ 0x98DAF5B0u,               11u,                 10u,               11u,                 10u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_0a848a3f_Tx] */
  { /*    11 */ 0xD8DAF5B0u,               12u,                 11u,               12u,                 11u }   /* [/ActiveEcuC/EcuC/EcucPduCollection/PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_bd11d57f_Tx] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_01
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_01[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxPduId                                                                   PduRTxSduId                                                                RxFcPduId                                       TxPduConfirmationPduId                      CanType                        RxPduMapIdx  RxSduCfgIdx  TxMaxPayloadLength  TxPduMapIdx        Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD2_oVCAN_RADAR_96501380_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_07322176, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_07322176, CANTP_CAN20_CANTYPEOFTXSDUCFG,          1u,          1u,                 7u,          1u },  /* [CanTpTxNSdu_c5537cf0] */  /* [CanTpTxNSdu_c5537cf0, TxPdu_1, RxPdu_1] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_20_a840a80f_Tx  , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_3fe829d7, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_3fe829d7, CANTP_CAN20_CANTYPEOFTXSDUCFG,          8u,          2u,                 7u,          8u },  /* [CanTpTxNSdu_bd9a0635] */  /* [CanTpTxNSdu_bd9a0635, TxPdu_8, RxPdu_8] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_20_955df2f4_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_712096e0, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_712096e0, CANTP_CAN20_CANTYPEOFTXSDUCFG,          5u,          4u,                 7u,          5u },  /* [CanTpTxNSdu_24fdb8bb] */  /* [CanTpTxNSdu_24fdb8bb, TxPdu_5, RxPdu_5] */
  { /*     3 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OTA_oVCAN_RADAR_9ad9d3d9_Tx         , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_3e771e0a, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_3e771e0a, CANTP_CAN20_CANTYPEOFTXSDUCFG,          2u,          5u,                 7u,          2u },  /* [CanTpTxNSdu_2fa399b3] */  /* [CanTpTxNSdu_2fa399b3, TxPdu_2, RxPdu_2] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD1_oVCAN_RADAR_cd47a295_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_5ceccd3a, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_5ceccd3a, CANTP_CAN20_CANTYPEOFTXSDUCFG,          0u,          6u,                 7u,          0u },  /* [CanTpTxNSdu_7f5185ac] */  /* [CanTpTxNSdu_7f5185ac, TxPdu_0, RxPdu_0] */
  { /*     5 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_20_f1bd890a_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_8b2a1893, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_8b2a1893, CANTP_CAN20_CANTYPEOFTXSDUCFG,          7u,          9u,                 7u,          7u },  /* [CanTpTxNSdu_db835be6] */  /* [CanTpTxNSdu_db835be6, TxPdu_7, RxPdu_7] */
  { /*     6 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_572eb9fe_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_9c58cec2, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_9c58cec2, CANTP_CANFD_CANTYPEOFTXSDUCFG,          4u,         10u,                63u,          4u },  /* [CanTpTxNSdu_e66ca3b9] */  /* [CanTpTxNSdu_e66ca3b9, TxPdu_4, RxPdu_4] */
  { /*     7 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_2a569d3c_Tx     , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_7f531fd8, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_7f531fd8, CANTP_CANFD_CANTYPEOFTXSDUCFG,          9u,         14u,                63u,          9u },  /* [CanTpTxNSdu_0057d142] */  /* [CanTpTxNSdu_0057d142, TxPdu_9, RxPdu_9] */
  { /*     8 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_0c3908eb_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_3d1ae7c9, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_3d1ae7c9, CANTP_CANFD_CANTYPEOFTXSDUCFG,          6u,         16u,                63u,          6u },  /* [CanTpTxNSdu_64228dd8] */  /* [CanTpTxNSdu_64228dd8, TxPdu_6, RxPdu_6] */
  { /*     9 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_PLANT_oVCAN_RADAR_5fef2467_Tx       , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_336ad662, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_336ad662, CANTP_CAN20_CANTYPEOFTXSDUCFG,          3u,         20u,                 7u,          3u },  /* [CanTpTxNSdu_6b1dcdd5] */  /* [CanTpTxNSdu_6b1dcdd5, TxPdu_3, RxPdu_3] */
  { /*    10 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_20_22a7f120_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_cb9b1616, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_cb9b1616, CANTP_CAN20_CANTYPEOFTXSDUCFG,         10u,         21u,                 7u,         10u },  /* [CanTpTxNSdu_3a469f02] */  /* [CanTpTxNSdu_3a469f02, TxPdu_10, RxPdu_10] */
  { /*    11 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_cfac777e_Tx   , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_4b2ea891, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_4b2ea891, CANTP_CANFD_CANTYPEOFTXSDUCFG,         11u,         23u,                63u,         11u }   /* [CanTpTxNSdu_f486fe77] */  /* [CanTpTxNSdu_f486fe77, TxPdu_11, RxPdu_11] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_02
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_02
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_02[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxPduId                                                                   PduRTxSduId                                                                RxFcPduId                                       TxPduConfirmationPduId                      CanType                        RxPduMapIdx  RxSduCfgIdx  TxMaxPayloadLength  TxPduMapIdx        Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_2a569d3c_Tx     , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_fcc3ea08, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_fcc3ea08, CANTP_CANFD_CANTYPEOFTXSDUCFG,          9u,          1u,                63u,          9u },  /* [CanTpTxNSdu_4b8ac5bd] */  /* [CanTpTxNSdu_4b8ac5bd, TxPdu_9, RxPdu_9] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_cfac777e_Tx   , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_ccce8258, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_ccce8258, CANTP_CANFD_CANTYPEOFTXSDUCFG,         11u,          3u,                63u,         11u },  /* [CanTpTxNSdu_8063d38e] */  /* [CanTpTxNSdu_8063d38e, TxPdu_11, RxPdu_11] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD1_oVCAN_RADAR_cd47a295_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_27f74791, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_27f74791, CANTP_CAN20_CANTYPEOFTXSDUCFG,          0u,          4u,                 7u,          0u },  /* [CanTpTxNSdu_6b1f15de] */  /* [CanTpTxNSdu_6b1f15de, TxPdu_0, RxPdu_0] */
  { /*     3 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_20_955df2f4_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_48f33663, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_48f33663, CANTP_CAN20_CANTYPEOFTXSDUCFG,          5u,          5u,                 7u,          5u },  /* [CanTpTxNSdu_6b7431ef] */  /* [CanTpTxNSdu_6b7431ef, TxPdu_5, RxPdu_5] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_PLANT_oVCAN_RADAR_5fef2467_Tx       , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_13bee2d7, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_13bee2d7, CANTP_CAN20_CANTYPEOFTXSDUCFG,          3u,          9u,                 7u,          3u },  /* [CanTpTxNSdu_90dedbb7] */  /* [CanTpTxNSdu_90dedbb7, TxPdu_3, RxPdu_3] */
  { /*     5 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_0c3908eb_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_7beda6ef, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_7beda6ef, CANTP_CANFD_CANTYPEOFTXSDUCFG,          6u,         11u,                63u,          6u },  /* [CanTpTxNSdu_482f027a] */  /* [CanTpTxNSdu_482f027a, TxPdu_6, RxPdu_6] */
  { /*     6 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_20_22a7f120_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_b322733f, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_b322733f, CANTP_CAN20_CANTYPEOFTXSDUCFG,         10u,         12u,                 7u,         10u },  /* [CanTpTxNSdu_9bdfb9c6] */  /* [CanTpTxNSdu_9bdfb9c6, TxPdu_10, RxPdu_10] */
  { /*     7 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD2_oVCAN_RADAR_96501380_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_4bdbbbc6, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_4bdbbbc6, CANTP_CAN20_CANTYPEOFTXSDUCFG,          1u,         13u,                 7u,          1u },  /* [CanTpTxNSdu_5249da4a] */  /* [CanTpTxNSdu_5249da4a, TxPdu_1, RxPdu_1] */
  { /*     8 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_20_f1bd890a_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_d2875bd9, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_d2875bd9, CANTP_CAN20_CANTYPEOFTXSDUCFG,          7u,         14u,                 7u,          7u },  /* [CanTpTxNSdu_4e12ed26] */  /* [CanTpTxNSdu_4e12ed26, TxPdu_7, RxPdu_7] */
  { /*     9 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_20_a840a80f_Tx  , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_274ec784, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_274ec784, CANTP_CAN20_CANTYPEOFTXSDUCFG,          8u,         15u,                 7u,          8u },  /* [CanTpTxNSdu_175c4d75] */  /* [CanTpTxNSdu_175c4d75, TxPdu_8, RxPdu_8] */
  { /*    10 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_572eb9fe_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_f0646899, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_f0646899, CANTP_CANFD_CANTYPEOFTXSDUCFG,          4u,         16u,                63u,          4u },  /* [CanTpTxNSdu_a39083e7] */  /* [CanTpTxNSdu_a39083e7, TxPdu_4, RxPdu_4] */
  { /*    11 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OTA_oVCAN_RADAR_9ad9d3d9_Tx         , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_66cf5575, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_66cf5575, CANTP_CAN20_CANTYPEOFTXSDUCFG,          2u,         17u,                 7u,          2u }   /* [CanTpTxNSdu_4f8ed450] */  /* [CanTpTxNSdu_4f8ed450, TxPdu_2, RxPdu_2] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_03
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_03
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_03[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxPduId                                                                   PduRTxSduId                                                                RxFcPduId                                       TxPduConfirmationPduId                      CanType                        RxPduMapIdx  RxSduCfgIdx  TxMaxPayloadLength  TxPduMapIdx        Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_20_f1bd890a_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_35063251, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_35063251, CANTP_CAN20_CANTYPEOFTXSDUCFG,          7u,          2u,                 7u,          7u },  /* [CanTpTxNSdu_471bd8a5] */  /* [CanTpTxNSdu_471bd8a5, TxPdu_7, RxPdu_7] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_20_a840a80f_Tx  , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_21de91ed, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_21de91ed, CANTP_CAN20_CANTYPEOFTXSDUCFG,          8u,          3u,                 7u,          8u },  /* [CanTpTxNSdu_1b50fb68] */  /* [CanTpTxNSdu_1b50fb68, TxPdu_8, RxPdu_8] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_20_955df2f4_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_d3b2b1a3, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_d3b2b1a3, CANTP_CAN20_CANTYPEOFTXSDUCFG,          5u,          4u,                 7u,          5u },  /* [CanTpTxNSdu_620766ce] */  /* [CanTpTxNSdu_620766ce, TxPdu_5, RxPdu_5] */
  { /*     3 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD1_oVCAN_RADAR_cd47a295_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_01d8e2bf, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_01d8e2bf, CANTP_CAN20_CANTYPEOFTXSDUCFG,          0u,          5u,                 7u,          0u },  /* [CanTpTxNSdu_93c8010e] */  /* [CanTpTxNSdu_93c8010e, TxPdu_0, RxPdu_0] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_2a569d3c_Tx     , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_421c8c3f, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_421c8c3f, CANTP_CANFD_CANTYPEOFTXSDUCFG,          9u,          7u,                63u,          9u },  /* [CanTpTxNSdu_fac189c4] */  /* [CanTpTxNSdu_fac189c4, TxPdu_9, RxPdu_9] */
  { /*     5 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_0c3908eb_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_baf9e4ba, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_baf9e4ba, CANTP_CANFD_CANTYPEOFTXSDUCFG,          6u,          9u,                63u,          6u },  /* [CanTpTxNSdu_e2541eaf] */  /* [CanTpTxNSdu_e2541eaf, TxPdu_6, RxPdu_6] */
  { /*     6 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_cfac777e_Tx   , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_070c7dc6, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_070c7dc6, CANTP_CANFD_CANTYPEOFTXSDUCFG,         11u,         10u,                63u,         11u },  /* [CanTpTxNSdu_ca28ec73] */  /* [CanTpTxNSdu_ca28ec73, TxPdu_11, RxPdu_11] */
  { /*     7 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD2_oVCAN_RADAR_96501380_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_23d51516, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_23d51516, CANTP_CAN20_CANTYPEOFTXSDUCFG,          1u,         11u,                 7u,          1u },  /* [CanTpTxNSdu_7e56306d] */  /* [CanTpTxNSdu_7e56306d, TxPdu_1, RxPdu_1] */
  { /*     8 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OTA_oVCAN_RADAR_9ad9d3d9_Tx         , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_e7ad1c6c, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_e7ad1c6c, CANTP_CAN20_CANTYPEOFTXSDUCFG,          2u,         14u,                 7u,          2u },  /* [CanTpTxNSdu_d8286eb1] */  /* [CanTpTxNSdu_d8286eb1, TxPdu_2, RxPdu_2] */
  { /*     9 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_572eb9fe_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_02feff05, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_02feff05, CANTP_CANFD_CANTYPEOFTXSDUCFG,          4u,         18u,                63u,          4u },  /* [CanTpTxNSdu_9a31514e] */  /* [CanTpTxNSdu_9a31514e, TxPdu_4, RxPdu_4] */
  { /*    10 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_PLANT_oVCAN_RADAR_5fef2467_Tx       , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_f028787e, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_f028787e, CANTP_CAN20_CANTYPEOFTXSDUCFG,          3u,         19u,                 7u,          3u },  /* [CanTpTxNSdu_d1b47cad] */  /* [CanTpTxNSdu_d1b47cad, TxPdu_3, RxPdu_3] */
  { /*    11 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_20_22a7f120_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_7f7b1c3b, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_7f7b1c3b, CANTP_CAN20_CANTYPEOFTXSDUCFG,         10u,         20u,                 7u,         10u }   /* [CanTpTxNSdu_42fe9847] */  /* [CanTpTxNSdu_42fe9847, TxPdu_10, RxPdu_10] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_04
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_04
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_04[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxPduId                                                                   PduRTxSduId                                                                RxFcPduId                                       TxPduConfirmationPduId                      CanType                        RxPduMapIdx  RxSduCfgIdx  TxMaxPayloadLength  TxPduMapIdx        Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_572eb9fe_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_6bd16043, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_6bd16043, CANTP_CANFD_CANTYPEOFTXSDUCFG,          4u,          2u,                63u,          4u },  /* [CanTpTxNSdu_b5963bcd] */  /* [CanTpTxNSdu_b5963bcd, TxPdu_4, RxPdu_4] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD1_oVCAN_RADAR_cd47a295_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_04b2f665, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_04b2f665, CANTP_CAN20_CANTYPEOFTXSDUCFG,          0u,          4u,                 7u,          0u },  /* [CanTpTxNSdu_8b07fec8] */  /* [CanTpTxNSdu_8b07fec8, TxPdu_0, RxPdu_0] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_20_955df2f4_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_2abb8ac6, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_2abb8ac6, CANTP_CAN20_CANTYPEOFTXSDUCFG,          5u,          7u,                 7u,          5u },  /* [CanTpTxNSdu_808a4832] */  /* [CanTpTxNSdu_808a4832, TxPdu_5, RxPdu_5] */
  { /*     3 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_2a569d3c_Tx     , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_722a8665, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_722a8665, CANTP_CANFD_CANTYPEOFTXSDUCFG,          9u,          8u,                63u,          9u },  /* [CanTpTxNSdu_be955aab] */  /* [CanTpTxNSdu_be955aab, TxPdu_9, RxPdu_9] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_PLANT_oVCAN_RADAR_5fef2467_Tx       , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_d884fe99, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_d884fe99, CANTP_CAN20_CANTYPEOFTXSDUCFG,          3u,         11u,                 7u,          3u },  /* [CanTpTxNSdu_39b7733b] */  /* [CanTpTxNSdu_39b7733b, TxPdu_3, RxPdu_3] */
  { /*     5 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_20_22a7f120_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_8ac432ad, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_8ac432ad, CANTP_CAN20_CANTYPEOFTXSDUCFG,         10u,         12u,                 7u,         10u },  /* [CanTpTxNSdu_35dbd553] */  /* [CanTpTxNSdu_35dbd553, TxPdu_10, RxPdu_10] */
  { /*     6 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD2_oVCAN_RADAR_96501380_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_ea1ccf13, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_ea1ccf13, CANTP_CAN20_CANTYPEOFTXSDUCFG,          1u,         16u,                 7u,          1u },  /* [CanTpTxNSdu_71a17bb4] */  /* [CanTpTxNSdu_71a17bb4, TxPdu_1, RxPdu_1] */
  { /*     7 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_20_f1bd890a_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_15aa1e7a, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_15aa1e7a, CANTP_CAN20_CANTYPEOFTXSDUCFG,          7u,         17u,                 7u,          7u },  /* [CanTpTxNSdu_0a6cebaf] */  /* [CanTpTxNSdu_0a6cebaf, TxPdu_7, RxPdu_7] */
  { /*     8 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_20_a840a80f_Tx  , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_06f6f546, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_06f6f546, CANTP_CAN20_CANTYPEOFTXSDUCFG,          8u,         18u,                 7u,          8u },  /* [CanTpTxNSdu_c1932d51] */  /* [CanTpTxNSdu_c1932d51, TxPdu_8, RxPdu_8] */
  { /*     9 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OTA_oVCAN_RADAR_9ad9d3d9_Tx         , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_a08e1aa2, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_a08e1aa2, CANTP_CAN20_CANTYPEOFTXSDUCFG,          2u,         19u,                 7u,          2u },  /* [CanTpTxNSdu_6e6d2a7f] */  /* [CanTpTxNSdu_6e6d2a7f, TxPdu_2, RxPdu_2] */
  { /*    10 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_cfac777e_Tx   , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_0f41b55c, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_0f41b55c, CANTP_CANFD_CANTYPEOFTXSDUCFG,         11u,         20u,                63u,         11u },  /* [CanTpTxNSdu_dac1b156] */  /* [CanTpTxNSdu_dac1b156, TxPdu_11, RxPdu_11] */
  { /*    11 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_0c3908eb_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_ec3e6156, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_ec3e6156, CANTP_CANFD_CANTYPEOFTXSDUCFG,          6u,         21u,                63u,          6u }   /* [CanTpTxNSdu_8a9f4292] */  /* [CanTpTxNSdu_8a9f4292, TxPdu_6, RxPdu_6] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_05
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_05[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxPduId                                                                   PduRTxSduId                                                                RxFcPduId                                       TxPduConfirmationPduId                      CanType                        RxPduMapIdx  RxSduCfgIdx  TxMaxPayloadLength  TxPduMapIdx        Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_572eb9fe_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_c1bb9e96, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_c1bb9e96, CANTP_CANFD_CANTYPEOFTXSDUCFG,          4u,          0u,                63u,          4u },  /* [CanTpTxNSdu_0adc25ca] */  /* [CanTpTxNSdu_0adc25ca, TxPdu_4, RxPdu_4] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OTA_oVCAN_RADAR_9ad9d3d9_Tx         , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_8b5ee258, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_8b5ee258, CANTP_CAN20_CANTYPEOFTXSDUCFG,          2u,          1u,                 7u,          2u },  /* [CanTpTxNSdu_7f902975] */  /* [CanTpTxNSdu_7f902975, TxPdu_2, RxPdu_2] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_20_f1bd890a_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_5e665eb2, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_5e665eb2, CANTP_CAN20_CANTYPEOFTXSDUCFG,          7u,          4u,                 7u,          7u },  /* [CanTpTxNSdu_da5fea54] */  /* [CanTpTxNSdu_da5fea54, TxPdu_7, RxPdu_7] */
  { /*     3 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD1_oVCAN_RADAR_cd47a295_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_f6bcd3b8, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_f6bcd3b8, CANTP_CAN20_CANTYPEOFTXSDUCFG,          0u,          7u,                 7u,          0u },  /* [CanTpTxNSdu_c0427f66] */  /* [CanTpTxNSdu_c0427f66, TxPdu_0, RxPdu_0] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_0c3908eb_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_813de497, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_813de497, CANTP_CANFD_CANTYPEOFTXSDUCFG,          6u,          8u,                63u,          6u },  /* [CanTpTxNSdu_28542b52] */  /* [CanTpTxNSdu_28542b52, TxPdu_6, RxPdu_6] */
  { /*     5 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD2_oVCAN_RADAR_96501380_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_e8932f23, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_e8932f23, CANTP_CAN20_CANTYPEOFTXSDUCFG,          1u,          9u,                 7u,          1u },  /* [CanTpTxNSdu_ddc06ff6] */  /* [CanTpTxNSdu_ddc06ff6, TxPdu_1, RxPdu_1] */
  { /*     6 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_20_a840a80f_Tx  , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_8c680c30, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_8c680c30, CANTP_CAN20_CANTYPEOFTXSDUCFG,          8u,         11u,                 7u,          8u },  /* [CanTpTxNSdu_7de58f85] */  /* [CanTpTxNSdu_7de58f85, TxPdu_8, RxPdu_8] */
  { /*     7 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_20_955df2f4_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_32d52ed5, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_32d52ed5, CANTP_CAN20_CANTYPEOFTXSDUCFG,          5u,         15u,                 7u,          5u },  /* [CanTpTxNSdu_5a9726cc] */  /* [CanTpTxNSdu_5a9726cc, TxPdu_5, RxPdu_5] */
  { /*     8 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_cfac777e_Tx   , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_3e2131c6, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_3e2131c6, CANTP_CANFD_CANTYPEOFTXSDUCFG,         11u,         17u,                63u,         11u },  /* [CanTpTxNSdu_8d39cc24] */  /* [CanTpTxNSdu_8d39cc24, TxPdu_11, RxPdu_11] */
  { /*     9 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_20_22a7f120_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_8ddade68, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_8ddade68, CANTP_CAN20_CANTYPEOFTXSDUCFG,         10u,         19u,                 7u,         10u },  /* [CanTpTxNSdu_244becaa] */  /* [CanTpTxNSdu_244becaa, TxPdu_10, RxPdu_10] */
  { /*    10 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_2a569d3c_Tx     , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_4ce052cf, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_4ce052cf, CANTP_CANFD_CANTYPEOFTXSDUCFG,          9u,         20u,                63u,          9u },  /* [CanTpTxNSdu_7d9f3885] */  /* [CanTpTxNSdu_7d9f3885, TxPdu_9, RxPdu_9] */
  { /*    11 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_PLANT_oVCAN_RADAR_5fef2467_Tx       , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_4ab4679c, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_4ab4679c, CANTP_CAN20_CANTYPEOFTXSDUCFG,          3u,         22u,                 7u,          3u }   /* [CanTpTxNSdu_5075f9f9] */  /* [CanTpTxNSdu_5075f9f9, TxPdu_3, RxPdu_3] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_06
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_06
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_06[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxPduId                                                                   PduRTxSduId                                                                RxFcPduId                                       TxPduConfirmationPduId                      CanType                        RxPduMapIdx  RxSduCfgIdx  TxMaxPayloadLength  TxPduMapIdx        Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_20_22a7f120_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_9a4c0fc3, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_9a4c0fc3, CANTP_CAN20_CANTYPEOFTXSDUCFG,         10u,          0u,                 7u,         10u },  /* [CanTpTxNSdu_cbb41ec6] */  /* [CanTpTxNSdu_cbb41ec6, TxPdu_10, RxPdu_10] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_cfac777e_Tx   , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_aceb83bd, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_aceb83bd, CANTP_CANFD_CANTYPEOFTXSDUCFG,         11u,          1u,                63u,         11u },  /* [CanTpTxNSdu_e3788fc6] */  /* [CanTpTxNSdu_e3788fc6, TxPdu_11, RxPdu_11] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD1_oVCAN_RADAR_cd47a295_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_09f8ee8f, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_09f8ee8f, CANTP_CAN20_CANTYPEOFTXSDUCFG,          0u,          3u,                 7u,          0u },  /* [CanTpTxNSdu_c912f74f] */  /* [CanTpTxNSdu_c912f74f, TxPdu_0, RxPdu_0] */
  { /*     3 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_20_955df2f4_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_62933392, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_62933392, CANTP_CAN20_CANTYPEOFTXSDUCFG,          5u,          4u,                 7u,          5u },  /* [CanTpTxNSdu_b4077489] */  /* [CanTpTxNSdu_b4077489, TxPdu_5, RxPdu_5] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_PLANT_oVCAN_RADAR_5fef2467_Tx       , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_0483f246, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_0483f246, CANTP_CAN20_CANTYPEOFTXSDUCFG,          3u,          5u,                 7u,          3u },  /* [CanTpTxNSdu_f5655a25] */  /* [CanTpTxNSdu_f5655a25, TxPdu_3, RxPdu_3] */
  { /*     5 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_0c3908eb_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_ee92cc82, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_ee92cc82, CANTP_CANFD_CANTYPEOFTXSDUCFG,          6u,          7u,                63u,          6u },  /* [CanTpTxNSdu_1e2714e5] */  /* [CanTpTxNSdu_1e2714e5, TxPdu_6, RxPdu_6] */
  { /*     6 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_2a569d3c_Tx     , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_3c290900, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_3c290900, CANTP_CANFD_CANTYPEOFTXSDUCFG,          9u,         10u,                63u,          9u },  /* [CanTpTxNSdu_bcb07df3] */  /* [CanTpTxNSdu_bcb07df3, TxPdu_9, RxPdu_9] */
  { /*     7 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_20_f1bd890a_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_95f032c7, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_95f032c7, CANTP_CAN20_CANTYPEOFTXSDUCFG,          7u,         13u,                 7u,          7u },  /* [CanTpTxNSdu_71ff2702] */  /* [CanTpTxNSdu_71ff2702, TxPdu_7, RxPdu_7] */
  { /*     8 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD2_oVCAN_RADAR_96501380_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_e851f142, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_e851f142, CANTP_CAN20_CANTYPEOFTXSDUCFG,          1u,         14u,                 7u,          1u },  /* [CanTpTxNSdu_1825ea7b] */  /* [CanTpTxNSdu_1825ea7b, TxPdu_1, RxPdu_1] */
  { /*     9 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OTA_oVCAN_RADAR_9ad9d3d9_Tx         , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_baf86b8a, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_baf86b8a, CANTP_CAN20_CANTYPEOFTXSDUCFG,          2u,         15u,                 7u,          2u },  /* [CanTpTxNSdu_7019f6f9] */  /* [CanTpTxNSdu_7019f6f9, TxPdu_2, RxPdu_2] */
  { /*    10 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_20_a840a80f_Tx  , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_565ab5ab, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_565ab5ab, CANTP_CAN20_CANTYPEOFTXSDUCFG,          8u,         17u,                 7u,          8u },  /* [CanTpTxNSdu_ff9066e8] */  /* [CanTpTxNSdu_ff9066e8, TxPdu_8, RxPdu_8] */
  { /*    11 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_572eb9fe_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_b6ba1235, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_b6ba1235, CANTP_CANFD_CANTYPEOFTXSDUCFG,          4u,         22u,                63u,          4u }   /* [CanTpTxNSdu_a01029ae] */  /* [CanTpTxNSdu_a01029ae, TxPdu_4, RxPdu_4] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_07
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_07
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_07[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxPduId                                                                   PduRTxSduId                                                                RxFcPduId                                       TxPduConfirmationPduId                      CanType                        RxPduMapIdx  RxSduCfgIdx  TxMaxPayloadLength  TxPduMapIdx        Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_2a569d3c_Tx     , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_dfbd3194, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_dfbd3194, CANTP_CANFD_CANTYPEOFTXSDUCFG,          9u,          1u,                63u,          9u },  /* [CanTpTxNSdu_40aa540d] */  /* [CanTpTxNSdu_40aa540d, TxPdu_9, RxPdu_9] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_0c3908eb_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_5e9a03f3, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_5e9a03f3, CANTP_CANFD_CANTYPEOFTXSDUCFG,          6u,          2u,                63u,          6u },  /* [CanTpTxNSdu_1be7398e] */  /* [CanTpTxNSdu_1be7398e, TxPdu_6, RxPdu_6] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_cfac777e_Tx   , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_ccdab1c0, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_ccdab1c0, CANTP_CANFD_CANTYPEOFTXSDUCFG,         11u,          4u,                63u,         11u },  /* [CanTpTxNSdu_35203c39] */  /* [CanTpTxNSdu_35203c39, TxPdu_11, RxPdu_11] */
  { /*     3 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD2_oVCAN_RADAR_96501380_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_3dc7eafe, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_3dc7eafe, CANTP_CAN20_CANTYPEOFTXSDUCFG,          1u,          6u,                 7u,          1u },  /* [CanTpTxNSdu_98e0a949] */  /* [CanTpTxNSdu_98e0a949, TxPdu_1, RxPdu_1] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OTA_oVCAN_RADAR_9ad9d3d9_Tx         , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_c8707632, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_c8707632, CANTP_CAN20_CANTYPEOFTXSDUCFG,          2u,          7u,                 7u,          2u },  /* [CanTpTxNSdu_100f5ca2] */  /* [CanTpTxNSdu_100f5ca2, TxPdu_2, RxPdu_2] */
  { /*     5 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_20_955df2f4_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_a982b2a5, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_a982b2a5, CANTP_CAN20_CANTYPEOFTXSDUCFG,          5u,          8u,                 7u,          5u },  /* [CanTpTxNSdu_3216b4ff] */  /* [CanTpTxNSdu_3216b4ff, TxPdu_5, RxPdu_5] */
  { /*     6 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD1_oVCAN_RADAR_cd47a295_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_9d366837, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_9d366837, CANTP_CAN20_CANTYPEOFTXSDUCFG,          0u,          9u,                 7u,          0u },  /* [CanTpTxNSdu_6816740d] */  /* [CanTpTxNSdu_6816740d, TxPdu_0, RxPdu_0] */
  { /*     7 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_20_f1bd890a_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_10593f38, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_10593f38, CANTP_CAN20_CANTYPEOFTXSDUCFG,          7u,         10u,                 7u,          7u },  /* [CanTpTxNSdu_605d1a3a] */  /* [CanTpTxNSdu_605d1a3a, TxPdu_7, RxPdu_7] */
  { /*     8 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_20_a840a80f_Tx  , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_a53ca4c4, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_a53ca4c4, CANTP_CAN20_CANTYPEOFTXSDUCFG,          8u,         14u,                 7u,          8u },  /* [CanTpTxNSdu_055d88c0] */  /* [CanTpTxNSdu_055d88c0, TxPdu_8, RxPdu_8] */
  { /*     9 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_572eb9fe_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_a4aa60a1, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_a4aa60a1, CANTP_CANFD_CANTYPEOFTXSDUCFG,          4u,         15u,                63u,          4u },  /* [CanTpTxNSdu_0a60edb0] */  /* [CanTpTxNSdu_0a60edb0, TxPdu_4, RxPdu_4] */
  { /*    10 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_20_22a7f120_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_56eed362, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_56eed362, CANTP_CAN20_CANTYPEOFTXSDUCFG,         10u,         21u,                 7u,         10u },  /* [CanTpTxNSdu_2888d97c] */  /* [CanTpTxNSdu_2888d97c, TxPdu_10, RxPdu_10] */
  { /*    11 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_PLANT_oVCAN_RADAR_5fef2467_Tx       , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_ee33c3ea, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_ee33c3ea, CANTP_CAN20_CANTYPEOFTXSDUCFG,          3u,         23u,                 7u,          3u }   /* [CanTpTxNSdu_f984455c] */  /* [CanTpTxNSdu_f984455c, TxPdu_3, RxPdu_3] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_08
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_08
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_08[12] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    LoLayerTxPduId                                                                   PduRTxSduId                                                                RxFcPduId                                       TxPduConfirmationPduId                      CanType                        RxPduMapIdx  RxSduCfgIdx  TxMaxPayloadLength  TxPduMapIdx        Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx       , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_PLANT_oVCAN_RADAR_5fef2467_Tx       , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_8b5ba0dc, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_8b5ba0dc, CANTP_CAN20_CANTYPEOFTXSDUCFG,          3u,          0u,                 7u,          3u },  /* [CanTpTxNSdu_5ea61dee] */  /* [CanTpTxNSdu_5ea61dee, TxPdu_3, RxPdu_3] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx   , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_cfac777e_Tx   , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_ce06c21b, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_ce06c21b, CANTP_CANFD_CANTYPEOFTXSDUCFG,         11u,          6u,                63u,         11u },  /* [CanTpTxNSdu_fe897178] */  /* [CanTpTxNSdu_fe897178, TxPdu_11, RxPdu_11] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx     , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_2a569d3c_Tx     , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_b1ef3f08, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_b1ef3f08, CANTP_CANFD_CANTYPEOFTXSDUCFG,          9u,          7u,                63u,          9u },  /* [CanTpTxNSdu_382889a1] */  /* [CanTpTxNSdu_382889a1, TxPdu_9, RxPdu_9] */
  { /*     3 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_20_955df2f4_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_a9167325, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_a9167325, CANTP_CAN20_CANTYPEOFTXSDUCFG,          5u,          9u,                 7u,          5u },  /* [CanTpTxNSdu_125a8101] */  /* [CanTpTxNSdu_125a8101, TxPdu_5, RxPdu_5] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD1_oVCAN_RADAR_cd47a295_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_70cf1a56, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_70cf1a56, CANTP_CAN20_CANTYPEOFTXSDUCFG,          0u,         10u,                 7u,          0u },  /* [CanTpTxNSdu_9b170e76] */  /* [CanTpTxNSdu_9b170e76, TxPdu_0, RxPdu_0] */
  { /*     5 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_0c3908eb_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_bb66fff8, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_bb66fff8, CANTP_CANFD_CANTYPEOFTXSDUCFG,          6u,         14u,                63u,          6u },  /* [CanTpTxNSdu_0d1ea855] */  /* [CanTpTxNSdu_0d1ea855, TxPdu_6, RxPdu_6] */
  { /*     6 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx, PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_20_22a7f120_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_cc43b521, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_cc43b521, CANTP_CAN20_CANTYPEOFTXSDUCFG,         10u,         15u,                 7u,         10u },  /* [CanTpTxNSdu_406ac1d2] */  /* [CanTpTxNSdu_406ac1d2, TxPdu_10, RxPdu_10] */
  { /*     7 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx         , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OTA_oVCAN_RADAR_9ad9d3d9_Tx         , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_8b31c6c9, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_8b31c6c9, CANTP_CAN20_CANTYPEOFTXSDUCFG,          2u,         16u,                 7u,          2u },  /* [CanTpTxNSdu_01773b70] */  /* [CanTpTxNSdu_01773b70, TxPdu_2, RxPdu_2] */
  { /*     8 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx  , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_20_a840a80f_Tx  , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_6871bfc9, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_6871bfc9, CANTP_CAN20_CANTYPEOFTXSDUCFG,          8u,         17u,                 7u,          8u },  /* [CanTpTxNSdu_2062e733] */  /* [CanTpTxNSdu_2062e733, TxPdu_8, RxPdu_8] */
  { /*     9 */ CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx        , PduRConf_PduRDestPdu_FR_DIAG_RES_PHY_OBD2_oVCAN_RADAR_96501380_Tx        , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_5f15f4b8, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_5f15f4b8, CANTP_CAN20_CANTYPEOFTXSDUCFG,          1u,         19u,                 7u,          1u },  /* [CanTpTxNSdu_92ce2a9d] */  /* [CanTpTxNSdu_92ce2a9d, TxPdu_1, RxPdu_1] */
  { /*    10 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_20_f1bd890a_Tx , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_0a4b612d, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_0a4b612d, CANTP_CAN20_CANTYPEOFTXSDUCFG,          7u,         20u,                 7u,          7u },  /* [CanTpTxNSdu_3fa592e1] */  /* [CanTpTxNSdu_3fa592e1, TxPdu_7, RxPdu_7] */
  { /*    11 */ CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx    , PduRConf_PduRDestPdu_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_572eb9fe_Tx    , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_2795869c, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_2795869c, CANTP_CANFD_CANTYPEOFTXSDUCFG,          4u,         22u,                63u,          4u }   /* [CanTpTxNSdu_1f237be1] */  /* [CanTpTxNSdu_1f237be1, TxPdu_4, RxPdu_4] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduSnv2Hdl
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduSnv2Hdl
  \brief  CanTpTxNSdu SNV to Handle (i.e. internal index) mapping
  \details
  Element         Description
  TxNSduHdlIdx    the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduSnv2HdlType, CANTP_CONST) CanTp_TxSduSnv2Hdl[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxNSduHdlIdx        Comment */
  { /*     0 */           0u },  /* [CanTpTxNSdu_c5537cf0] */
  { /*     1 */           1u },  /* [CanTpTxNSdu_bd9a0635] */
  { /*     2 */           2u },  /* [CanTpTxNSdu_24fdb8bb] */
  { /*     3 */           3u },  /* [CanTpTxNSdu_2fa399b3] */
  { /*     4 */           4u },  /* [CanTpTxNSdu_7f5185ac] */
  { /*     5 */           5u },  /* [CanTpTxNSdu_db835be6] */
  { /*     6 */           6u },  /* [CanTpTxNSdu_e66ca3b9] */
  { /*     7 */           7u },  /* [CanTpTxNSdu_0057d142] */
  { /*     8 */           8u },  /* [CanTpTxNSdu_64228dd8] */
  { /*     9 */           9u },  /* [CanTpTxNSdu_6b1dcdd5] */
  { /*    10 */          10u },  /* [CanTpTxNSdu_3a469f02] */
  { /*    11 */          11u }   /* [CanTpTxNSdu_f486fe77] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_CalcBS
**********************************************************************************************************************/
/** 
  \var    CanTp_CalcBS
  \brief  CalcBS array
*/ 
#define CANTP_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTp_CalcBSType, CANTP_VAR_NO_INIT) CanTp_CalcBS[24];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTP_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxState
**********************************************************************************************************************/
/** 
  \var    CanTp_RxState
  \brief  RxState array
*/ 
#define CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTp_RxStateType, CANTP_VAR_NO_INIT) CanTp_RxState[24];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSemaphores
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSemaphores
  \brief  TxSemaphores array
*/ 
#define CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTp_TxSemaphoreType, CANTP_VAR_NO_INIT) CanTp_TxSemaphores[12];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxState
**********************************************************************************************************************/
/** 
  \var    CanTp_TxState
  \brief  TxState array
*/ 
#define CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTp_TxStateType, CANTP_VAR_NO_INIT) CanTp_TxState[12];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCConfig
**********************************************************************************************************************/
/** 
  \var    CanTp_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to CanTp_PCPartitionConfig
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_PCConfigsType, CANTP_CONST) CanTp_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_RDR_01] */
      CanTp_PCPartitionConfigRDR_01  /**< the pointer to CanTp_PCPartitionConfig in Config_RDR_01 */
  },
  { /* Index: 1 Keys: [Config_RDR_02] */
      CanTp_PCPartitionConfigRDR_02  /**< the pointer to CanTp_PCPartitionConfig in Config_RDR_02 */
  },
  { /* Index: 2 Keys: [Config_RDR_03] */
      CanTp_PCPartitionConfigRDR_03  /**< the pointer to CanTp_PCPartitionConfig in Config_RDR_03 */
  },
  { /* Index: 3 Keys: [Config_RDR_04] */
      CanTp_PCPartitionConfigRDR_04  /**< the pointer to CanTp_PCPartitionConfig in Config_RDR_04 */
  },
  { /* Index: 4 Keys: [Config_RDR_05] */
      CanTp_PCPartitionConfigRDR_05  /**< the pointer to CanTp_PCPartitionConfig in Config_RDR_05 */
  },
  { /* Index: 5 Keys: [Config_RDR_06] */
      CanTp_PCPartitionConfigRDR_06  /**< the pointer to CanTp_PCPartitionConfig in Config_RDR_06 */
  },
  { /* Index: 6 Keys: [Config_RDR_07] */
      CanTp_PCPartitionConfigRDR_07  /**< the pointer to CanTp_PCPartitionConfig in Config_RDR_07 */
  },
  { /* Index: 7 Keys: [Config_RDR_08] */
      CanTp_PCPartitionConfigRDR_08  /**< the pointer to CanTp_PCPartitionConfig in Config_RDR_08 */
  }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_01
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_01[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CanTpSinglePartitionMemory] */
      CanTp_RxPdu2RxSduIndRDR_01  /**< the pointer to CanTp_RxPdu2RxSduInd in Config_RDR_01 */
    , CanTp_RxPdu2TxSduIndRDR_01  /**< the pointer to CanTp_RxPdu2TxSduInd in Config_RDR_01 */
    , CanTp_RxSduCfgRDR_01        /**< the pointer to CanTp_RxSduCfg in Config_RDR_01 */
    , CanTp_TxPdu2RxSduIndRDR_01  /**< the pointer to CanTp_TxPdu2RxSduInd in Config_RDR_01 */
    , CanTp_TxPdu2TxSduIndRDR_01  /**< the pointer to CanTp_TxPdu2TxSduInd in Config_RDR_01 */
    , CanTp_TxSduCfgRDR_01        /**< the pointer to CanTp_TxSduCfg in Config_RDR_01 */
  }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_02
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_02
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_02[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CanTpSinglePartitionMemory] */
      CanTp_RxPdu2RxSduIndRDR_02  /**< the pointer to CanTp_RxPdu2RxSduInd in Config_RDR_02 */
    , CanTp_RxPdu2TxSduIndRDR_02  /**< the pointer to CanTp_RxPdu2TxSduInd in Config_RDR_02 */
    , CanTp_RxSduCfgRDR_02        /**< the pointer to CanTp_RxSduCfg in Config_RDR_02 */
    , CanTp_TxPdu2RxSduIndRDR_02  /**< the pointer to CanTp_TxPdu2RxSduInd in Config_RDR_02 */
    , CanTp_TxPdu2TxSduIndRDR_02  /**< the pointer to CanTp_TxPdu2TxSduInd in Config_RDR_02 */
    , CanTp_TxSduCfgRDR_02        /**< the pointer to CanTp_TxSduCfg in Config_RDR_02 */
  }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_03
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_03
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_03[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CanTpSinglePartitionMemory] */
      CanTp_RxPdu2RxSduIndRDR_03  /**< the pointer to CanTp_RxPdu2RxSduInd in Config_RDR_03 */
    , CanTp_RxPdu2TxSduIndRDR_03  /**< the pointer to CanTp_RxPdu2TxSduInd in Config_RDR_03 */
    , CanTp_RxSduCfgRDR_03        /**< the pointer to CanTp_RxSduCfg in Config_RDR_03 */
    , CanTp_TxPdu2RxSduIndRDR_03  /**< the pointer to CanTp_TxPdu2RxSduInd in Config_RDR_03 */
    , CanTp_TxPdu2TxSduIndRDR_03  /**< the pointer to CanTp_TxPdu2TxSduInd in Config_RDR_03 */
    , CanTp_TxSduCfgRDR_03        /**< the pointer to CanTp_TxSduCfg in Config_RDR_03 */
  }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_04
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_04
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_04[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CanTpSinglePartitionMemory] */
      CanTp_RxPdu2RxSduIndRDR_04  /**< the pointer to CanTp_RxPdu2RxSduInd in Config_RDR_04 */
    , CanTp_RxPdu2TxSduIndRDR_04  /**< the pointer to CanTp_RxPdu2TxSduInd in Config_RDR_04 */
    , CanTp_RxSduCfgRDR_04        /**< the pointer to CanTp_RxSduCfg in Config_RDR_04 */
    , CanTp_TxPdu2RxSduIndRDR_04  /**< the pointer to CanTp_TxPdu2RxSduInd in Config_RDR_04 */
    , CanTp_TxPdu2TxSduIndRDR_04  /**< the pointer to CanTp_TxPdu2TxSduInd in Config_RDR_04 */
    , CanTp_TxSduCfgRDR_04        /**< the pointer to CanTp_TxSduCfg in Config_RDR_04 */
  }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_05
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_05[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CanTpSinglePartitionMemory] */
      CanTp_RxPdu2RxSduIndRDR_05  /**< the pointer to CanTp_RxPdu2RxSduInd in Config_RDR_05 */
    , CanTp_RxPdu2TxSduIndRDR_05  /**< the pointer to CanTp_RxPdu2TxSduInd in Config_RDR_05 */
    , CanTp_RxSduCfgRDR_05        /**< the pointer to CanTp_RxSduCfg in Config_RDR_05 */
    , CanTp_TxPdu2RxSduIndRDR_05  /**< the pointer to CanTp_TxPdu2RxSduInd in Config_RDR_05 */
    , CanTp_TxPdu2TxSduIndRDR_05  /**< the pointer to CanTp_TxPdu2TxSduInd in Config_RDR_05 */
    , CanTp_TxSduCfgRDR_05        /**< the pointer to CanTp_TxSduCfg in Config_RDR_05 */
  }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_06
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_06
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_06[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CanTpSinglePartitionMemory] */
      CanTp_RxPdu2RxSduIndRDR_06  /**< the pointer to CanTp_RxPdu2RxSduInd in Config_RDR_06 */
    , CanTp_RxPdu2TxSduIndRDR_06  /**< the pointer to CanTp_RxPdu2TxSduInd in Config_RDR_06 */
    , CanTp_RxSduCfgRDR_06        /**< the pointer to CanTp_RxSduCfg in Config_RDR_06 */
    , CanTp_TxPdu2RxSduIndRDR_06  /**< the pointer to CanTp_TxPdu2RxSduInd in Config_RDR_06 */
    , CanTp_TxPdu2TxSduIndRDR_06  /**< the pointer to CanTp_TxPdu2TxSduInd in Config_RDR_06 */
    , CanTp_TxSduCfgRDR_06        /**< the pointer to CanTp_TxSduCfg in Config_RDR_06 */
  }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_07
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_07
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_07[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CanTpSinglePartitionMemory] */
      CanTp_RxPdu2RxSduIndRDR_07  /**< the pointer to CanTp_RxPdu2RxSduInd in Config_RDR_07 */
    , CanTp_RxPdu2TxSduIndRDR_07  /**< the pointer to CanTp_RxPdu2TxSduInd in Config_RDR_07 */
    , CanTp_RxSduCfgRDR_07        /**< the pointer to CanTp_RxSduCfg in Config_RDR_07 */
    , CanTp_TxPdu2RxSduIndRDR_07  /**< the pointer to CanTp_TxPdu2RxSduInd in Config_RDR_07 */
    , CanTp_TxPdu2TxSduIndRDR_07  /**< the pointer to CanTp_TxPdu2TxSduInd in Config_RDR_07 */
    , CanTp_TxSduCfgRDR_07        /**< the pointer to CanTp_TxSduCfg in Config_RDR_07 */
  }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_08
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_08
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_08[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CanTpSinglePartitionMemory] */
      CanTp_RxPdu2RxSduIndRDR_08  /**< the pointer to CanTp_RxPdu2RxSduInd in Config_RDR_08 */
    , CanTp_RxPdu2TxSduIndRDR_08  /**< the pointer to CanTp_RxPdu2TxSduInd in Config_RDR_08 */
    , CanTp_RxSduCfgRDR_08        /**< the pointer to CanTp_RxSduCfg in Config_RDR_08 */
    , CanTp_TxPdu2RxSduIndRDR_08  /**< the pointer to CanTp_TxPdu2RxSduInd in Config_RDR_08 */
    , CanTp_TxPdu2TxSduIndRDR_08  /**< the pointer to CanTp_TxPdu2TxSduInd in Config_RDR_08 */
    , CanTp_TxSduCfgRDR_08        /**< the pointer to CanTp_TxSduCfg in Config_RDR_08 */
  }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 * FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/




