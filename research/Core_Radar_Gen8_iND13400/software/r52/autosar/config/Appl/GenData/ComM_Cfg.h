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
 *            Module: ComM
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ComM_Cfg.h
 *   Generation Time: 2026-06-07 16:44:40
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

#if !defined(COMM_CFG_H)
#define COMM_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ INCLUDES
 ----------------------------------------------------------------------------- */

#include "ComM_Types.h"
#include "Com_Types.h"
#include "Os.h"
/* -----------------------------------------------------------------------------
    &&&~ CONFIGURATION DEFINES
 ----------------------------------------------------------------------------- */

#ifndef COMM_USE_DUMMY_STATEMENT
#define COMM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COMM_DUMMY_STATEMENT
#define COMM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COMM_DUMMY_STATEMENT_CONST
#define COMM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COMM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define COMM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef COMM_ATOMIC_VARIABLE_ACCESS
#define COMM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef COMM_PROCESSOR_IND13400
#define COMM_PROCESSOR_IND13400
#endif
#ifndef COMM_COMP_LLVMDIAB
#define COMM_COMP_LLVMDIAB
#endif
#ifndef COMM_GEN_GENERATOR_MSR
#define COMM_GEN_GENERATOR_MSR
#endif
#ifndef COMM_CPUTYPE_BITORDER_LSB2MSB
#define COMM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef COMM_CONFIGURATION_VARIANT_PRECOMPILE
#define COMM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef COMM_CONFIGURATION_VARIANT_LINKTIME
#define COMM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef COMM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define COMM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef COMM_CONFIGURATION_VARIANT
#define COMM_CONFIGURATION_VARIANT COMM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef COMM_POSTBUILD_VARIANT_SUPPORT
#define COMM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#ifndef COMM_DEV_ERROR_DETECT
#define COMM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef COMM_DEV_ERROR_REPORT
#define COMM_DEV_ERROR_REPORT STD_ON
#endif

#define COMM_VERSION_INFO_API                                             STD_OFF

#define COMM_MODE_LIMITATION                                              STD_OFF
#define COMM_WAKEUP_INHIBITION                                            STD_OFF

#define COMM_PNC_SUPPORT                                                  STD_OFF
#define COMM_PNC_ACTIVE_COORD                                             STD_OFF
#define COMM_PNC_PS_TIMER                                                 0u
#define COMM_ACTIVE_PNC                                                   0u
#define COMM_PNC_EXTENDED_FUNCTIONALITY_ENABLED                           STD_OFF

#define COMM_SYNCHRONIZED_PNC_SHUTDOWN_ENABLED                            STD_OFF

#define COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED                    STD_OFF
#define COMM_PNC_PASSIVE_GW_SUPPORT                                       STD_OFF
#define COMM_PNC_EXISTS_COORD_PNC_WITH_GW_PASSIVE_AND_MANAGED_CHANNELS    STD_OFF
#define COMM_PNC_EXISTS_GATEWAY_TYPE_ACTIVE                               STD_OFF
#define COMM_PNC_EXISTS_GATEWAY_TYPE_NONE                                 STD_OFF
#define COMM_PNC_SIGNAL_LENGTH                                            0u
#define COMM_PNC_MAX_NUMBER_OF_EIRA_RX                                    0u
#define COMM_PNC_CHECK_ENABLED_AT_RUNTIME                                 STD_OFF
#define COMM_PNC_0_VECTOR_AVOIDANCE                                       STD_OFF

#define COMM_NM_GW_EXT_ENABLED                                            STD_OFF
#define COMM_KEEP_AWAKE_CHANNELS_SUPPORT                                  STD_ON
#define COMM_BUS_TYPE_INTERNAL_PRESENT                                    STD_OFF
#define COMM_BUS_TYPE_FR_PRESENT                                          STD_OFF
#define COMM_BUS_TYPE_LIN_PRESENT                                         STD_OFF
#define COMM_EXISTS_ONLY_NONE_NMTYPEOFCHANNEL                             STD_ON

#define COMM_FULL_COMM_REQUEST_NOTIF                                      STD_OFF
#define COMM_MAX_NUMBER_OF_USERS                                          3u
#define COMM_DCM_INDICATION                                               STD_ON
#define COMM_USERMODENOTIFUNC_PNC_USER_ONLY                               STD_ON
#define COMM_EXISTS_USER_WITH_SINGLE_PNC                                  STD_OFF

#define COMM_SYNCHRONOUS_WAKE_UP                                          STD_OFF
#define COMM_EXTENDED_RAM_CHECK                                           STD_OFF

#define COMM_NM_VARIANT_FULL_PRESENT                                     STD_OFF

#define COMM_NVM_SUPPORT                                                  STD_OFF

#define COMM_MULTIPARTITION                                               STD_OFF
#define COMM_EXISTS_CHANNEL_ON_MASTER_PARTITION                           STD_ON
#define COMM_EXISTS_USER_ON_SATELLITE_PARTITION                           STD_OFF
#define COMM_EXISTS_USER_ON_MASTER_PARTITION                              STD_ON


#define COMM_ALL_CHANNEL_USER_REQUESTERS_SIZE                             0u


#define COMM_MASTER_PARTITION_IDX                       0u
#define COMM_SINGLEPARTITION                            0u

#define COMM_NO_SYMBOLICNAMEVALUE                       65535u
/* -----------------------------------------------------------------------------
    &&&~ USER HANDLES
 ----------------------------------------------------------------------------- */

#define ComMConf_ComMUser_CN_PCAN_RADAR_d6cf874b    1u 
#define ComMConf_ComMUser_CN_VCAN_RADAR_4b138c58    2u 
#define ComMConf_ComMUser_cnctr_RDR_RdrNet_9faa6a47 0u 


/* -----------------------------------------------------------------------------
    &&&~ CHANNEL HANDLES
 ----------------------------------------------------------------------------- */

#define ComMConf_ComMChannel_cnctr_RDR_RdrNet_5172a59b 0u 
#define ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1    1u 
#define ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6    2u 


/* -----------------------------------------------------------------------------
    &&&~ PNC HANDLES
 ----------------------------------------------------------------------------- */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComMPCDataSwitches  ComM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COMM_ACTIVECOMMODE                                                                          STD_ON
#define COMM_ACTIVEPNCCOMMODE                                                                       STD_OFF  /**< PNC Support is disabled */
#define COMM_BUSCOMMODEREQ                                                                          STD_ON
#define COMM_BUSCOMMODEREQFRSHUTDOWN                                                                STD_OFF  /**< Fr support is not present */
#define COMM_BUSPNCCOMMODEREQ                                                                       STD_OFF  /**< PNC Support is disabled */
#define COMM_BUSSLEEPMODEINDICATED                                                                  STD_OFF  /**< NM variant LINSLAVE is not present */
#define COMM_BUSSMSTATE                                                                             STD_ON
#define COMM_BUSTYPEFR                                                                              STD_OFF  /**< Fr support is not present */
#define COMM_CHANNEL                                                                                STD_ON
#define COMM_BUSTYPEOFCHANNEL                                                                       STD_ON
#define COMM_GETCURRENTBUSSMMODEAPIOFCHANNEL                                                        STD_ON
#define COMM_GWTYPEOFCHANNEL                                                                        STD_ON
#define COMM_INHIBITIONINITVALUEOFCHANNEL                                                           STD_ON
#define COMM_INVALIDHNDOFCHANNEL                                                                    STD_OFF  /**< the value of ComM_InvalidHndOfChannel is always 'false' due to this, the array is deactivated. */
#define COMM_J1939SUPPORTOFCHANNEL                                                                  STD_OFF  /**< the value of ComM_J1939SupportOfChannel is always 'false' due to this, the array is deactivated. */
#define COMM_MAINFUNCTIONNEEDSSYNCOFCHANNEL                                                         STD_OFF  /**< Configuration is single partition. */
#define COMM_MANAGINGCHANNELIDOFCHANNEL                                                             STD_ON
#define COMM_MANAGINGCHANNELOFCHANNEL                                                               STD_OFF  /**< the value of ComM_ManagingChannelOfChannel is always 'false' due to this, the array is deactivated. */
#define COMM_MANAGINGUSEROFCHANNEL                                                                  STD_OFF  /**< the value of ComM_ManagingUserOfChannel is always 'COMM_NO_MANAGINGUSEROFCHANNEL' due to this, the array is deactivated. */
#define COMM_MINFULLCOMTIMEOFCHANNEL                                                                STD_OFF  /**< the value of ComM_MinFullComTimeOfChannel is always '0' due to this, the array is deactivated. */
#define COMM_NMLIGHTDURATIONOFCHANNEL                                                               STD_OFF  /**< the value of ComM_NmLightDurationOfChannel is always '0' due to this, the array is deactivated. */
#define COMM_NMLIGHTSILENTDURATIONOFCHANNEL                                                         STD_OFF  /**< the value of ComM_NmLightSilentDurationOfChannel is always '0' due to this, the array is deactivated. */
#define COMM_NMSUPPORTOFCHANNEL                                                                     STD_OFF  /**< the value of ComM_NmSupportOfChannel is always 'false' due to this, the array is deactivated. */
#define COMM_NMTYPEOFCHANNEL                                                                        STD_ON
#define COMM_PARTITIONCONFIGIDXOFCHANNEL                                                            STD_ON
#define COMM_PASSIVEORLINSLAVEOFCHANNEL                                                             STD_OFF  /**< the value of ComM_PassiveOrLinSlaveOfChannel is always 'false' due to this, the array is deactivated. */
#define COMM_PNCNMREQUESTOFCHANNEL                                                                  STD_OFF  /**< the value of ComM_PncNmRequestOfChannel is always 'false' due to this, the array is deactivated. */
#define COMM_REQUESTBUSSMMODEAPIOFCHANNEL                                                           STD_ON
#define COMM_RESETAFTERFORCINGNOCOMMOFCHANNEL                                                       STD_OFF  /**< the value of ComM_ResetAfterForcingNoCommOfChannel is always 'false' due to this, the array is deactivated. */
#define COMM_SILENTSUPPORTOFCHANNEL                                                                 STD_OFF  /**< the value of ComM_SilentSupportOfChannel is always 'false' due to this, the array is deactivated. */
#define COMM_WAKEUPSTATEOFCHANNEL                                                                   STD_ON
#define COMM_CHANNELPB                                                                              STD_ON
#define COMM_INVALIDHNDOFCHANNELPB                                                                  STD_OFF  /**< the value of ComM_InvalidHndOfChannelPb is always 'false' due to this, the array is deactivated. */
#define COMM_PNCLIMITATIONENDIDXOFCHANNELPB                                                         STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_PNCLIMITATIONSTARTIDXOFCHANNELPB                                                       STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_PNCLIMITATIONUSEDOFCHANNELPB                                                           STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_PNCPBINDENDIDXOFCHANNELPB                                                              STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_PNCPBINDSTARTIDXOFCHANNELPB                                                            STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_PNCPBINDUSEDOFCHANNELPB                                                                STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_USERREQFULLCOMENDIDXOFCHANNELPB                                                        STD_ON
#define COMM_USERREQFULLCOMSTARTIDXOFCHANNELPB                                                      STD_ON
#define COMM_USERREQFULLCOMUSEDOFCHANNELPB                                                          STD_ON
#define COMM_COMALLOWED                                                                             STD_ON
#define COMM_COORDPNCWITHGWPASSIVEANDMANAGEDCHANNELS                                                STD_OFF  /**< Coordinated Pnc with GW Passive and Managed channels not supported */
#define COMM_DCMINDICATION                                                                          STD_ON
#define COMM_DCMREQUESTACTIVE                                                                       STD_ON
#define COMM_ECUMWAKEUPINDICATED                                                                    STD_ON
#define COMM_EIRATXSIGNALINDIRECTION                                                                STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define COMM_EXTENDEDRAMCHECK                                                                       STD_OFF  /**< Extended Ram Check is not supported */
#define COMM_FINALMAGICNUMBER                                                                       STD_OFF  /**< the module configuration does not support flashing of data. */
#define COMM_FORWARDNMGATEWAY                                                                       STD_OFF  /**< This shall only be considered if NmGateway and MultiPartition are enabled, and if there exists at least one Channel EcuMWakeUp source */
#define COMM_FORWARDSYNCHRONIZEDPNCSHUTDOWNINDICATED                                                STD_OFF  /**< Synchronized PNC Shutdown is disabled or no Intermediate PNC Coordinator exists. */
#define COMM_FRSHUTDOWN                                                                             STD_OFF  /**< Fr support is not present */
#define COMM_FULLCOMREQUESTERS                                                                      STD_OFF  /**< Deactivated because no channel had ComMFullCommRequestNoficiation enabled */
#define COMM_FULLCOMMREQUESTNOTIF                                                                   STD_OFF  /**< Full Comm Request Notif is not supported */
#define COMM_FULLNMTYPEOFCHANNEL                                                                    STD_OFF  /**< No Channel with NmVariant FULL configured. */
#define COMM_INHIBITION                                                                             STD_ON
#define COMM_INITDATAHASHCODE                                                                       STD_OFF  /**< the module configuration does not support flashing of data. */
#define COMM_INITSTATUS                                                                             STD_ON
#define COMM_KEEPAWAKECHANNELS                                                                      STD_ON
#define COMM_LASTSTATECHANGE                                                                        STD_OFF  /**< No user mode Notification configured. */
#define COMM_LIGHTNMTYPEOFCHANNEL                                                                   STD_OFF  /**< Only Nm type Light is not supported */
#define COMM_LINSLAVENMTYPEOFCHANNEL                                                                STD_OFF  /**< NM variant LINSLAVE is not present */
#define COMM_MINFULLCOMMODETIMER                                                                    STD_OFF  /**< Min Full Com Timer is disabled */
#define COMM_MODELIMITATION                                                                         STD_OFF  /**< Mode Limitation is not supported */
#define COMM_NMGWEXT                                                                                STD_OFF  /**< NmGwExt is not supported */
#define COMM_NMLIGHTTIMER                                                                           STD_OFF  /**< Nm Light and Nm Light Silent Timers are disabled */
#define COMM_NMSTARTUPINDICATED                                                                     STD_ON
#define COMM_NONENMTYPEOFCHANNEL                                                                    STD_ON
#define COMM_NOTIFYPNCSTATECHANGE                                                                   STD_OFF  /**< No user mode Notification configured. */
#define COMM_NVMSTOREREQ                                                                            STD_OFF  /**< NvM support is disabled */
#define COMM_ONLYNONENMTYPEOFCHANNEL                                                                STD_ON
#define COMM_PARTITIONIDENTIFIERS                                                                   STD_ON
#define COMM_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                             STD_ON
#define COMM_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                     STD_ON
#define COMM_PNC                                                                                    STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define COMM_CLEARMASKOFPNC                                                                         STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_COORDINATEDOFPNC                                                                       STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_INTERMEDIATEPNCCOORDINATOROFPNC                                                        STD_OFF  /**< Synchronized PNC Shutdown is disabled. */
#define COMM_PNCIDOFPNC                                                                             STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_SETMASKOFPNC                                                                           STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_SYSTEMUSEROFPNC                                                                        STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_TOPLEVELPNCCOORDINATOROFPNC                                                            STD_OFF  /**< Synchronized PNC Shutdown is disabled. */
#define COMM_WAKEUPENABLEDOFPNC                                                                     STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_PNC0VECTORAVOIDANCE                                                                    STD_OFF  /**< Pnc 0 Vector Avoidance is not supported */
#define COMM_PNCCHANNELMAPPING                                                                      STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_PNCCHECKENABLEDATRUNTIME                                                               STD_OFF  /**< Pnc Check Enabled At Runtime is not supported */
#define COMM_PNCEIRARX                                                                              STD_OFF  /**< Pnc Eira Rx is not supported */
#define COMM_PNCEIRARXCOUNT                                                                         STD_OFF  /**< Pnc Eira Rx is not supported */
#define COMM_PNCEXTENDEDFUNCTIONALITY                                                               STD_OFF  /**< Pnc Extended Functionality is not supported */
#define COMM_PNCGWTYPEACTIVE                                                                        STD_OFF  /**< Pnc Gw type Active is not supported */
#define COMM_PNCGWTYPENONE                                                                          STD_OFF  /**< Pnc Gateway Type None is not supported */
#define COMM_PNCGWTYPEPASSIVE                                                                       STD_OFF  /**< Configuration does not have Pnc Passive Gw Support. */
#define COMM_PNCLIMITATION                                                                          STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_PNCPSLEEPTIMER                                                                         STD_OFF  /**< PNC Support is disabled */
#define COMM_PNCPB                                                                                  STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define COMM_PNCCHANNELMAPPINGENDIDXOFPNCPB                                                         STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_PNCCHANNELMAPPINGSTARTIDXOFPNCPB                                                       STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_PNCCHANNELMAPPINGUSEDOFPNCPB                                                           STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_PNCSIGNALINDENDIDXOFPNCPB                                                              STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_PNCSIGNALINDSTARTIDXOFPNCPB                                                            STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_PNCSIGNALINDUSEDOFPNCPB                                                                STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_SIGNALBYTEINDEXOFPNCPB                                                                 STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_USERREQPNCFULLCOMENDIDXOFPNCPB                                                         STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_USERREQPNCFULLCOMSTARTIDXOFPNCPB                                                       STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_PNCPBIND                                                                               STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_PNCSIGNAL                                                                              STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define COMM_BUSTYPEIDOFPNCSIGNAL                                                                   STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_CHANNELIDXOFPNCSIGNAL                                                                  STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_CHANNELUSEDOFPNCSIGNAL                                                                 STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_TYPEOFPNCSIGNAL                                                                        STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_PNCSIGNALIND                                                                           STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_PNCSIGNALVALUES                                                                        STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_PNCTOCHANNELROUTINGSTATE                                                               STD_OFF  /**< Pnc To Channel Routing Limitation is disabled. */
#define COMM_PNCWITHOUTCHANNELS                                                                     STD_OFF  /**< PNC without channels not supported */
#define COMM_POSTINITIALIZED                                                                        STD_ON
#define COMM_RESETREQUIRED                                                                          STD_OFF  /**< NoResetAfterForcingNoCom is not present */
#define COMM_SIMULATEDSMMODE                                                                        STD_OFF  /**< No channel of type 'internal' is present */
#define COMM_SIZEOFACTIVECOMMODE                                                                    STD_ON
#define COMM_SIZEOFACTIVEPNCCOMMODE                                                                 STD_ON
#define COMM_SIZEOFBUSCOMMODEREQ                                                                    STD_ON
#define COMM_SIZEOFBUSCOMMODEREQFRSHUTDOWN                                                          STD_ON
#define COMM_SIZEOFBUSPNCCOMMODEREQ                                                                 STD_ON
#define COMM_SIZEOFBUSSLEEPMODEINDICATED                                                            STD_ON
#define COMM_SIZEOFBUSSMSTATE                                                                       STD_ON
#define COMM_SIZEOFBUSTYPEFR                                                                        STD_ON
#define COMM_SIZEOFCHANNEL                                                                          STD_ON
#define COMM_SIZEOFCHANNELPB                                                                        STD_ON
#define COMM_SIZEOFCOMALLOWED                                                                       STD_ON
#define COMM_SIZEOFCOORDPNCWITHGWPASSIVEANDMANAGEDCHANNELS                                          STD_ON
#define COMM_SIZEOFDCMINDICATION                                                                    STD_ON
#define COMM_SIZEOFDCMREQUESTACTIVE                                                                 STD_ON
#define COMM_SIZEOFECUMWAKEUPINDICATED                                                              STD_ON
#define COMM_SIZEOFEIRATXSIGNALINDIRECTION                                                          STD_ON
#define COMM_SIZEOFEXTENDEDRAMCHECK                                                                 STD_ON
#define COMM_SIZEOFFORWARDNMGATEWAY                                                                 STD_ON
#define COMM_SIZEOFFORWARDSYNCHRONIZEDPNCSHUTDOWNINDICATED                                          STD_ON
#define COMM_SIZEOFFRSHUTDOWN                                                                       STD_ON
#define COMM_SIZEOFFULLCOMREQUESTERS                                                                STD_ON
#define COMM_SIZEOFFULLCOMMREQUESTNOTIF                                                             STD_ON
#define COMM_SIZEOFFULLNMTYPEOFCHANNEL                                                              STD_ON
#define COMM_SIZEOFKEEPAWAKECHANNELS                                                                STD_ON
#define COMM_SIZEOFLASTSTATECHANGE                                                                  STD_ON
#define COMM_SIZEOFLIGHTNMTYPEOFCHANNEL                                                             STD_ON
#define COMM_SIZEOFLINSLAVENMTYPEOFCHANNEL                                                          STD_ON
#define COMM_SIZEOFMINFULLCOMMODETIMER                                                              STD_ON
#define COMM_SIZEOFMODELIMITATION                                                                   STD_ON
#define COMM_SIZEOFNMGWEXT                                                                          STD_ON
#define COMM_SIZEOFNMLIGHTTIMER                                                                     STD_ON
#define COMM_SIZEOFNMSTARTUPINDICATED                                                               STD_ON
#define COMM_SIZEOFNONENMTYPEOFCHANNEL                                                              STD_ON
#define COMM_SIZEOFONLYNONENMTYPEOFCHANNEL                                                          STD_ON
#define COMM_SIZEOFPARTITIONIDENTIFIERS                                                             STD_ON
#define COMM_SIZEOFPNC                                                                              STD_ON
#define COMM_SIZEOFPNC0VECTORAVOIDANCE                                                              STD_ON
#define COMM_SIZEOFPNCCHANNELMAPPING                                                                STD_ON
#define COMM_SIZEOFPNCCHECKENABLEDATRUNTIME                                                         STD_ON
#define COMM_SIZEOFPNCEIRARX                                                                        STD_ON
#define COMM_SIZEOFPNCEXTENDEDFUNCTIONALITY                                                         STD_ON
#define COMM_SIZEOFPNCGWTYPEACTIVE                                                                  STD_ON
#define COMM_SIZEOFPNCGWTYPENONE                                                                    STD_ON
#define COMM_SIZEOFPNCGWTYPEPASSIVE                                                                 STD_ON
#define COMM_SIZEOFPNCLIMITATION                                                                    STD_ON
#define COMM_SIZEOFPNCPSLEEPTIMER                                                                   STD_ON
#define COMM_SIZEOFPNCPB                                                                            STD_ON
#define COMM_SIZEOFPNCPBIND                                                                         STD_ON
#define COMM_SIZEOFPNCSIGNAL                                                                        STD_ON
#define COMM_SIZEOFPNCSIGNALIND                                                                     STD_ON
#define COMM_SIZEOFPNCSIGNALVALUES                                                                  STD_ON
#define COMM_SIZEOFPNCTOCHANNELROUTINGSTATE                                                         STD_ON
#define COMM_SIZEOFPNCWITHOUTCHANNELS                                                               STD_ON
#define COMM_SIZEOFPOSTINITIALIZED                                                                  STD_ON
#define COMM_SIZEOFRESETREQUIRED                                                                    STD_ON
#define COMM_SIZEOFSIMULATEDSMMODE                                                                  STD_ON
#define COMM_SIZEOFSTATECHANGE                                                                      STD_ON
#define COMM_SIZEOFSYNCHRONOUSWAKEUP                                                                STD_ON
#define COMM_SIZEOFUSER                                                                             STD_ON
#define COMM_SIZEOFUSERBYTEMASK                                                                     STD_ON
#define COMM_SIZEOFUSERMODENOTIFUNC                                                                 STD_ON
#define COMM_SIZEOFUSERMODENOTIFICATIONONLYFORPNCUSERS                                              STD_ON
#define COMM_SIZEOFUSERPNCBYTEMASK                                                                  STD_ON
#define COMM_SIZEOFUSERREQFULLCOM                                                                   STD_ON
#define COMM_SIZEOFUSERREQPNCFULLCOM                                                                STD_ON
#define COMM_SIZEOFUSERWITHSINGLEPNC                                                                STD_ON
#define COMM_SIZEOFWAKEUPINHIBITION                                                                 STD_ON
#define COMM_STATECHANGE                                                                            STD_OFF  /**< No user mode Notification configured. */
#define COMM_SYNCHRONOUSWAKEUP                                                                      STD_OFF  /**< Synchronous WakeUp is disabled. */
#define COMM_USER                                                                                   STD_ON
#define COMM_PARTITIONCONFIGIDXOFUSER                                                               STD_ON
#define COMM_PNCUSEROFUSER                                                                          STD_ON
#define COMM_USERBYTEMASKENDIDXOFUSER                                                               STD_ON
#define COMM_USERBYTEMASKSTARTIDXOFUSER                                                             STD_ON
#define COMM_USERBYTEMASKUSEDOFUSER                                                                 STD_ON
#define COMM_USERPNCBYTEMASKENDIDXOFUSER                                                            STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_USERPNCBYTEMASKLENGTHOFUSER                                                            STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_USERPNCBYTEMASKSTARTIDXOFUSER                                                          STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_USERPNCBYTEMASKUSEDOFUSER                                                              STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_USERBYTEMASK                                                                           STD_ON
#define COMM_CHANNELOFUSERBYTEMASK                                                                  STD_ON
#define COMM_CLEARMASKOFUSERBYTEMASK                                                                STD_ON
#define COMM_SETMASKOFUSERBYTEMASK                                                                  STD_ON
#define COMM_USERREQFULLCOMIDXOFUSERBYTEMASK                                                        STD_ON
#define COMM_USERMODENOTIFUNC                                                                       STD_OFF  /**< No user mode Notification configured. */
#define COMM_USERMODENOTIFICATIONONLYFORPNCUSERS                                                    STD_ON
#define COMM_USERPNCBYTEMASK                                                                        STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define COMM_CLEARMASKOFUSERPNCBYTEMASK                                                             STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_PNCIDOFUSERPNCBYTEMASK                                                                 STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_PNCIDXOFUSERPNCBYTEMASK                                                                STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_SETMASKOFUSERPNCBYTEMASK                                                               STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_USERREQPNCFULLCOMIDXOFUSERPNCBYTEMASK                                                  STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_USERREQFULLCOM                                                                         STD_ON
#define COMM_USERREQPNCFULLCOM                                                                      STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define COMM_USERWITHSINGLEPNC                                                                      STD_OFF  /**< User With Single Pnc not supported */
#define COMM_WAKEUPINHIBITION                                                                       STD_OFF  /**< Wakeup Inhibition is not supported */
#define COMM_PCCONFIG                                                                               STD_ON
#define COMM_FINALMAGICNUMBEROFPCCONFIG                                                             STD_OFF  /**< the module configuration does not support flashing of data. */
#define COMM_INITDATAHASHCODEOFPCCONFIG                                                             STD_OFF  /**< the module configuration does not support flashing of data. */
#define COMM_PCPARTITIONCONFIGOFPCCONFIG                                                            STD_ON
#define COMM_PARTITIONIDENTIFIERSOFPCCONFIG                                                         STD_ON
#define COMM_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define COMM_PCPARTITIONCONFIG                                                                      STD_ON
#define COMM_ACTIVECOMMODEOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_ACTIVEPNCCOMMODEOFPCPARTITIONCONFIG                                                    STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_BUSCOMMODEREQFRSHUTDOWNOFPCPARTITIONCONFIG                                             STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_BUSCOMMODEREQOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_BUSPNCCOMMODEREQOFPCPARTITIONCONFIG                                                    STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_BUSSLEEPMODEINDICATEDOFPCPARTITIONCONFIG                                               STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_BUSSMSTATEOFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_BUSTYPEFROFPCPARTITIONCONFIG                                                           STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_CHANNELOFPCPARTITIONCONFIG                                                             STD_ON
#define COMM_CHANNELPBOFPCPARTITIONCONFIG                                                           STD_ON
#define COMM_COMALLOWEDOFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_COORDPNCWITHGWPASSIVEANDMANAGEDCHANNELSOFPCPARTITIONCONFIG                             STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_DCMINDICATIONOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_DCMREQUESTACTIVEOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ECUMWAKEUPINDICATEDOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_EIRATXSIGNALINDIRECTIONOFPCPARTITIONCONFIG                                             STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_EXTENDEDRAMCHECKOFPCPARTITIONCONFIG                                                    STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_FORWARDNMGATEWAYOFPCPARTITIONCONFIG                                                    STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_FORWARDSYNCHRONIZEDPNCSHUTDOWNINDICATEDOFPCPARTITIONCONFIG                             STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_FRSHUTDOWNOFPCPARTITIONCONFIG                                                          STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_FULLCOMREQUESTERSOFPCPARTITIONCONFIG                                                   STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_FULLCOMMREQUESTNOTIFOFPCPARTITIONCONFIG                                                STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_FULLNMTYPEOFCHANNELOFPCPARTITIONCONFIG                                                 STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_INHIBITIONOFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_INITSTATUSOFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_KEEPAWAKECHANNELSOFPCPARTITIONCONFIG                                                   STD_ON
#define COMM_LASTSTATECHANGEOFPCPARTITIONCONFIG                                                     STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_LIGHTNMTYPEOFCHANNELOFPCPARTITIONCONFIG                                                STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_LINSLAVENMTYPEOFCHANNELOFPCPARTITIONCONFIG                                             STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_MINFULLCOMMODETIMEROFPCPARTITIONCONFIG                                                 STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_MODELIMITATIONOFPCPARTITIONCONFIG                                                      STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_NMGWEXTOFPCPARTITIONCONFIG                                                             STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_NMLIGHTTIMEROFPCPARTITIONCONFIG                                                        STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_NMSTARTUPINDICATEDOFPCPARTITIONCONFIG                                                  STD_ON
#define COMM_NONENMTYPEOFCHANNELOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_NOTIFYPNCSTATECHANGEOFPCPARTITIONCONFIG                                                STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_NVMSTOREREQOFPCPARTITIONCONFIG                                                         STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_ONLYNONENMTYPEOFCHANNELOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_PNC0VECTORAVOIDANCEOFPCPARTITIONCONFIG                                                 STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCCHANNELMAPPINGOFPCPARTITIONCONFIG                                                   STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCCHECKENABLEDATRUNTIMEOFPCPARTITIONCONFIG                                            STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCEIRARXCOUNTOFPCPARTITIONCONFIG                                                      STD_OFF  /**< Pnc Eira Rx is not supported */
#define COMM_PNCEIRARXOFPCPARTITIONCONFIG                                                           STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCEXTENDEDFUNCTIONALITYOFPCPARTITIONCONFIG                                            STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCGWTYPEACTIVEOFPCPARTITIONCONFIG                                                     STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCGWTYPENONEOFPCPARTITIONCONFIG                                                       STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCGWTYPEPASSIVEOFPCPARTITIONCONFIG                                                    STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCLIMITATIONOFPCPARTITIONCONFIG                                                       STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCOFPCPARTITIONCONFIG                                                                 STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCPSLEEPTIMEROFPCPARTITIONCONFIG                                                      STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCPBINDOFPCPARTITIONCONFIG                                                            STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCPBOFPCPARTITIONCONFIG                                                               STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCSIGNALINDOFPCPARTITIONCONFIG                                                        STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCSIGNALOFPCPARTITIONCONFIG                                                           STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCSIGNALVALUESOFPCPARTITIONCONFIG                                                     STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCTOCHANNELROUTINGSTATEOFPCPARTITIONCONFIG                                            STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_PNCWITHOUTCHANNELSOFPCPARTITIONCONFIG                                                  STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_POSTINITIALIZEDOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_RESETREQUIREDOFPCPARTITIONCONFIG                                                       STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_SIMULATEDSMMODEOFPCPARTITIONCONFIG                                                     STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_SIZEOFACTIVECOMMODEOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_SIZEOFACTIVEPNCCOMMODEOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_SIZEOFBUSCOMMODEREQFRSHUTDOWNOFPCPARTITIONCONFIG                                       STD_ON
#define COMM_SIZEOFBUSCOMMODEREQOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_SIZEOFBUSPNCCOMMODEREQOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_SIZEOFBUSSLEEPMODEINDICATEDOFPCPARTITIONCONFIG                                         STD_ON
#define COMM_SIZEOFBUSSMSTATEOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_SIZEOFBUSTYPEFROFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_SIZEOFCHANNELOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_SIZEOFCHANNELPBOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_SIZEOFCOMALLOWEDOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_SIZEOFCOORDPNCWITHGWPASSIVEANDMANAGEDCHANNELSOFPCPARTITIONCONFIG                       STD_ON
#define COMM_SIZEOFDCMINDICATIONOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_SIZEOFDCMREQUESTACTIVEOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_SIZEOFECUMWAKEUPINDICATEDOFPCPARTITIONCONFIG                                           STD_ON
#define COMM_SIZEOFEIRATXSIGNALINDIRECTIONOFPCPARTITIONCONFIG                                       STD_ON
#define COMM_SIZEOFEXTENDEDRAMCHECKOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_SIZEOFFORWARDNMGATEWAYOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_SIZEOFFORWARDSYNCHRONIZEDPNCSHUTDOWNINDICATEDOFPCPARTITIONCONFIG                       STD_ON
#define COMM_SIZEOFFRSHUTDOWNOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_SIZEOFFULLCOMREQUESTERSOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_SIZEOFFULLCOMMREQUESTNOTIFOFPCPARTITIONCONFIG                                          STD_ON
#define COMM_SIZEOFFULLNMTYPEOFCHANNELOFPCPARTITIONCONFIG                                           STD_ON
#define COMM_SIZEOFKEEPAWAKECHANNELSOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_SIZEOFLASTSTATECHANGEOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_SIZEOFLIGHTNMTYPEOFCHANNELOFPCPARTITIONCONFIG                                          STD_ON
#define COMM_SIZEOFLINSLAVENMTYPEOFCHANNELOFPCPARTITIONCONFIG                                       STD_ON
#define COMM_SIZEOFMINFULLCOMMODETIMEROFPCPARTITIONCONFIG                                           STD_ON
#define COMM_SIZEOFMODELIMITATIONOFPCPARTITIONCONFIG                                                STD_ON
#define COMM_SIZEOFNMGWEXTOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_SIZEOFNMLIGHTTIMEROFPCPARTITIONCONFIG                                                  STD_ON
#define COMM_SIZEOFNMSTARTUPINDICATEDOFPCPARTITIONCONFIG                                            STD_ON
#define COMM_SIZEOFNONENMTYPEOFCHANNELOFPCPARTITIONCONFIG                                           STD_ON
#define COMM_SIZEOFONLYNONENMTYPEOFCHANNELOFPCPARTITIONCONFIG                                       STD_ON
#define COMM_SIZEOFPNC0VECTORAVOIDANCEOFPCPARTITIONCONFIG                                           STD_ON
#define COMM_SIZEOFPNCCHANNELMAPPINGOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_SIZEOFPNCCHECKENABLEDATRUNTIMEOFPCPARTITIONCONFIG                                      STD_ON
#define COMM_SIZEOFPNCEIRARXOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_SIZEOFPNCEXTENDEDFUNCTIONALITYOFPCPARTITIONCONFIG                                      STD_ON
#define COMM_SIZEOFPNCGWTYPEACTIVEOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_SIZEOFPNCGWTYPENONEOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_SIZEOFPNCGWTYPEPASSIVEOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_SIZEOFPNCLIMITATIONOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_SIZEOFPNCOFPCPARTITIONCONFIG                                                           STD_ON
#define COMM_SIZEOFPNCPSLEEPTIMEROFPCPARTITIONCONFIG                                                STD_ON
#define COMM_SIZEOFPNCPBINDOFPCPARTITIONCONFIG                                                      STD_ON
#define COMM_SIZEOFPNCPBOFPCPARTITIONCONFIG                                                         STD_ON
#define COMM_SIZEOFPNCSIGNALINDOFPCPARTITIONCONFIG                                                  STD_ON
#define COMM_SIZEOFPNCSIGNALOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_SIZEOFPNCSIGNALVALUESOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_SIZEOFPNCTOCHANNELROUTINGSTATEOFPCPARTITIONCONFIG                                      STD_ON
#define COMM_SIZEOFPNCWITHOUTCHANNELSOFPCPARTITIONCONFIG                                            STD_ON
#define COMM_SIZEOFPOSTINITIALIZEDOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_SIZEOFRESETREQUIREDOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_SIZEOFSIMULATEDSMMODEOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_SIZEOFSTATECHANGEOFPCPARTITIONCONFIG                                                   STD_ON
#define COMM_SIZEOFSYNCHRONOUSWAKEUPOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_SIZEOFUSERBYTEMASKOFPCPARTITIONCONFIG                                                  STD_ON
#define COMM_SIZEOFUSERMODENOTIFUNCOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_SIZEOFUSERMODENOTIFICATIONONLYFORPNCUSERSOFPCPARTITIONCONFIG                           STD_ON
#define COMM_SIZEOFUSEROFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_SIZEOFUSERPNCBYTEMASKOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_SIZEOFUSERREQFULLCOMOFPCPARTITIONCONFIG                                                STD_ON
#define COMM_SIZEOFUSERREQPNCFULLCOMOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_SIZEOFUSERWITHSINGLEPNCOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_SIZEOFWAKEUPINHIBITIONOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_STATECHANGEOFPCPARTITIONCONFIG                                                         STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_SYNCHRONOUSWAKEUPOFPCPARTITIONCONFIG                                                   STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_USERBYTEMASKOFPCPARTITIONCONFIG                                                        STD_ON
#define COMM_USERMODENOTIFUNCOFPCPARTITIONCONFIG                                                    STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_USERMODENOTIFICATIONONLYFORPNCUSERSOFPCPARTITIONCONFIG                                 STD_ON
#define COMM_USEROFPCPARTITIONCONFIG                                                                STD_ON
#define COMM_USERPNCBYTEMASKOFPCPARTITIONCONFIG                                                     STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_USERREQFULLCOMOFPCPARTITIONCONFIG                                                      STD_ON
#define COMM_USERREQPNCFULLCOMOFPCPARTITIONCONFIG                                                   STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_USERWITHSINGLEPNCOFPCPARTITIONCONFIG                                                   STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define COMM_WAKEUPINHIBITIONOFPCPARTITIONCONFIG                                                    STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCMinNumericValueDefines  ComM Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define COMM_MIN_FULLCOMREQUESTERS                                                                  0u
#define COMM_MIN_MINFULLCOMMODETIMER                                                                0u
#define COMM_MIN_NMLIGHTTIMER                                                                       0u
#define COMM_MIN_PNCLIMITATION                                                                      0u
#define COMM_MIN_PNCPSLEEPTIMER                                                                     0u
#define COMM_MIN_PNCSIGNALVALUES                                                                    0u
#define COMM_MIN_PNCTOCHANNELROUTINGSTATE                                                           0u
#define COMM_MIN_SIMULATEDSMMODE                                                                    0u
#define COMM_MIN_STATECHANGE                                                                        0u
#define COMM_MIN_USERREQFULLCOM                                                                     0u
#define COMM_MIN_USERREQPNCFULLCOM                                                                  0u
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCMaxNumericValueDefines  ComM Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define COMM_MAX_FULLCOMREQUESTERS                                                                  65535u
#define COMM_MAX_MINFULLCOMMODETIMER                                                                65535u
#define COMM_MAX_NMLIGHTTIMER                                                                       65535u
#define COMM_MAX_PNCLIMITATION                                                                      255u
#define COMM_MAX_PNCPSLEEPTIMER                                                                     65535u
#define COMM_MAX_PNCSIGNALVALUES                                                                    255u
#define COMM_MAX_PNCTOCHANNELROUTINGSTATE                                                           255u
#define COMM_MAX_SIMULATEDSMMODE                                                                    255u
#define COMM_MAX_STATECHANGE                                                                        255u
#define COMM_MAX_USERREQFULLCOM                                                                     255u
#define COMM_MAX_USERREQPNCFULLCOM                                                                  255u
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCNoReferenceDefines  ComM No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define COMM_NO_MANAGINGCHANNELIDOFCHANNEL                                                          255u
#define COMM_NO_MANAGINGUSEROFCHANNEL                                                               255u
#define COMM_NO_PNCLIMITATIONENDIDXOFCHANNELPB                                                      255u
#define COMM_NO_PNCLIMITATIONSTARTIDXOFCHANNELPB                                                    255u
#define COMM_NO_PNCPBINDENDIDXOFCHANNELPB                                                           255u
#define COMM_NO_PNCPBINDSTARTIDXOFCHANNELPB                                                         255u
#define COMM_NO_USERREQFULLCOMENDIDXOFCHANNELPB                                                     255u
#define COMM_NO_USERREQFULLCOMSTARTIDXOFCHANNELPB                                                   255u
#define COMM_NO_PNCCHANNELMAPPINGENDIDXOFPNCPB                                                      255u
#define COMM_NO_PNCCHANNELMAPPINGSTARTIDXOFPNCPB                                                    255u
#define COMM_NO_PNCSIGNALINDENDIDXOFPNCPB                                                           255u
#define COMM_NO_PNCSIGNALINDSTARTIDXOFPNCPB                                                         255u
#define COMM_NO_CHANNELIDXOFPNCSIGNAL                                                               255u
#define COMM_NO_USERBYTEMASKENDIDXOFUSER                                                            255u
#define COMM_NO_USERBYTEMASKSTARTIDXOFUSER                                                          255u
#define COMM_NO_USERPNCBYTEMASKENDIDXOFUSER                                                         255u
#define COMM_NO_USERPNCBYTEMASKSTARTIDXOFUSER                                                       255u
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCEnumExistsDefines  ComM Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define COMM_EXISTS_NOT_USED_IN_THIS_VARIANT_NMTYPEOFCHANNEL                                        STD_OFF
#define COMM_EXISTS_FULL_NMTYPEOFCHANNEL                                                            STD_OFF
#define COMM_EXISTS_PASSIVE_NMTYPEOFCHANNEL                                                         STD_OFF
#define COMM_EXISTS_LIGHT_NMTYPEOFCHANNEL                                                           STD_OFF
#define COMM_EXISTS_NONE_NMTYPEOFCHANNEL                                                            STD_ON
#define COMM_EXISTS_LINSLAVE_NMTYPEOFCHANNEL                                                        STD_OFF
#define COMM_EXISTS_EIRA_RX_TYPEOFPNCSIGNAL                                                         STD_OFF
#define COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL                                                         STD_OFF
#define COMM_EXISTS_ERA_RX_TYPEOFPNCSIGNAL                                                          STD_OFF
#define COMM_EXISTS_NOT_USED_IN_THIS_VARIANT_TYPEOFPNCSIGNAL                                        STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCEnumDefines  ComM Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define COMM_NOT_USED_IN_THIS_VARIANT_NMTYPEOFCHANNEL                                               0x00u
#define COMM_FULL_NMTYPEOFCHANNEL                                                                   0x01u
#define COMM_PASSIVE_NMTYPEOFCHANNEL                                                                0x02u
#define COMM_LIGHT_NMTYPEOFCHANNEL                                                                  0x03u
#define COMM_NONE_NMTYPEOFCHANNEL                                                                   0x04u
#define COMM_LINSLAVE_NMTYPEOFCHANNEL                                                               0x05u
#define COMM_EIRA_RX_TYPEOFPNCSIGNAL                                                                0x00u
#define COMM_EIRA_TX_TYPEOFPNCSIGNAL                                                                0x01u
#define COMM_ERA_RX_TYPEOFPNCSIGNAL                                                                 0x02u
#define COMM_NOT_USED_IN_THIS_VARIANT_TYPEOFPNCSIGNAL                                               0x03u
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCIsReducedToDefineDefines  ComM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define COMM_ISDEF_BUSTYPEFR                                                                        STD_OFF
#define COMM_ISDEF_BUSTYPEOFCHANNEL                                                                 STD_OFF
#define COMM_ISDEF_GETCURRENTBUSSMMODEAPIOFCHANNEL                                                  STD_OFF
#define COMM_ISDEF_GWTYPEOFCHANNEL                                                                  STD_ON
#define COMM_ISDEF_INHIBITIONINITVALUEOFCHANNEL                                                     STD_ON
#define COMM_ISDEF_INVALIDHNDOFCHANNEL                                                              STD_OFF
#define COMM_ISDEF_J1939SUPPORTOFCHANNEL                                                            STD_OFF
#define COMM_ISDEF_MAINFUNCTIONNEEDSSYNCOFCHANNEL                                                   STD_OFF
#define COMM_ISDEF_MANAGINGCHANNELIDOFCHANNEL                                                       STD_ON
#define COMM_ISDEF_MANAGINGCHANNELOFCHANNEL                                                         STD_OFF
#define COMM_ISDEF_MANAGINGUSEROFCHANNEL                                                            STD_OFF
#define COMM_ISDEF_MINFULLCOMTIMEOFCHANNEL                                                          STD_OFF
#define COMM_ISDEF_NMLIGHTDURATIONOFCHANNEL                                                         STD_OFF
#define COMM_ISDEF_NMLIGHTSILENTDURATIONOFCHANNEL                                                   STD_OFF
#define COMM_ISDEF_NMSUPPORTOFCHANNEL                                                               STD_OFF
#define COMM_ISDEF_NMTYPEOFCHANNEL                                                                  STD_ON
#define COMM_ISDEF_PARTITIONCONFIGIDXOFCHANNEL                                                      STD_ON
#define COMM_ISDEF_PASSIVEORLINSLAVEOFCHANNEL                                                       STD_OFF
#define COMM_ISDEF_PNCNMREQUESTOFCHANNEL                                                            STD_OFF
#define COMM_ISDEF_REQUESTBUSSMMODEAPIOFCHANNEL                                                     STD_OFF
#define COMM_ISDEF_RESETAFTERFORCINGNOCOMMOFCHANNEL                                                 STD_OFF
#define COMM_ISDEF_SILENTSUPPORTOFCHANNEL                                                           STD_OFF
#define COMM_ISDEF_WAKEUPSTATEOFCHANNEL                                                             STD_ON
#define COMM_ISDEF_INVALIDHNDOFCHANNELPB                                                            STD_OFF
#define COMM_ISDEF_PNCLIMITATIONENDIDXOFCHANNELPB                                                   STD_OFF
#define COMM_ISDEF_PNCLIMITATIONSTARTIDXOFCHANNELPB                                                 STD_OFF
#define COMM_ISDEF_PNCLIMITATIONUSEDOFCHANNELPB                                                     STD_OFF
#define COMM_ISDEF_PNCPBINDENDIDXOFCHANNELPB                                                        STD_OFF
#define COMM_ISDEF_PNCPBINDSTARTIDXOFCHANNELPB                                                      STD_OFF
#define COMM_ISDEF_PNCPBINDUSEDOFCHANNELPB                                                          STD_OFF
#define COMM_ISDEF_USERREQFULLCOMENDIDXOFCHANNELPB                                                  STD_OFF
#define COMM_ISDEF_USERREQFULLCOMSTARTIDXOFCHANNELPB                                                STD_OFF
#define COMM_ISDEF_USERREQFULLCOMUSEDOFCHANNELPB                                                    STD_ON
#define COMM_ISDEF_COORDPNCWITHGWPASSIVEANDMANAGEDCHANNELS                                          STD_OFF
#define COMM_ISDEF_DCMINDICATION                                                                    STD_ON
#define COMM_ISDEF_EXTENDEDRAMCHECK                                                                 STD_OFF
#define COMM_ISDEF_FULLCOMMREQUESTNOTIF                                                             STD_OFF
#define COMM_ISDEF_FULLNMTYPEOFCHANNEL                                                              STD_OFF
#define COMM_ISDEF_KEEPAWAKECHANNELS                                                                STD_ON
#define COMM_ISDEF_LIGHTNMTYPEOFCHANNEL                                                             STD_OFF
#define COMM_ISDEF_LINSLAVENMTYPEOFCHANNEL                                                          STD_OFF
#define COMM_ISDEF_MODELIMITATION                                                                   STD_OFF
#define COMM_ISDEF_NMGWEXT                                                                          STD_OFF
#define COMM_ISDEF_NONENMTYPEOFCHANNEL                                                              STD_ON
#define COMM_ISDEF_ONLYNONENMTYPEOFCHANNEL                                                          STD_ON
#define COMM_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                       STD_OFF
#define COMM_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                               STD_OFF
#define COMM_ISDEF_CLEARMASKOFPNC                                                                   STD_OFF
#define COMM_ISDEF_COORDINATEDOFPNC                                                                 STD_OFF
#define COMM_ISDEF_INTERMEDIATEPNCCOORDINATOROFPNC                                                  STD_OFF
#define COMM_ISDEF_PNCIDOFPNC                                                                       STD_OFF
#define COMM_ISDEF_SETMASKOFPNC                                                                     STD_OFF
#define COMM_ISDEF_SYSTEMUSEROFPNC                                                                  STD_OFF
#define COMM_ISDEF_TOPLEVELPNCCOORDINATOROFPNC                                                      STD_OFF
#define COMM_ISDEF_WAKEUPENABLEDOFPNC                                                               STD_OFF
#define COMM_ISDEF_PNC0VECTORAVOIDANCE                                                              STD_OFF
#define COMM_ISDEF_PNCCHANNELMAPPING                                                                STD_OFF
#define COMM_ISDEF_PNCCHECKENABLEDATRUNTIME                                                         STD_OFF
#define COMM_ISDEF_PNCEIRARX                                                                        STD_OFF
#define COMM_ISDEF_PNCEXTENDEDFUNCTIONALITY                                                         STD_OFF
#define COMM_ISDEF_PNCGWTYPEACTIVE                                                                  STD_OFF
#define COMM_ISDEF_PNCGWTYPENONE                                                                    STD_OFF
#define COMM_ISDEF_PNCGWTYPEPASSIVE                                                                 STD_OFF
#define COMM_ISDEF_PNCCHANNELMAPPINGENDIDXOFPNCPB                                                   STD_OFF
#define COMM_ISDEF_PNCCHANNELMAPPINGSTARTIDXOFPNCPB                                                 STD_OFF
#define COMM_ISDEF_PNCCHANNELMAPPINGUSEDOFPNCPB                                                     STD_OFF
#define COMM_ISDEF_PNCSIGNALINDENDIDXOFPNCPB                                                        STD_OFF
#define COMM_ISDEF_PNCSIGNALINDSTARTIDXOFPNCPB                                                      STD_OFF
#define COMM_ISDEF_PNCSIGNALINDUSEDOFPNCPB                                                          STD_OFF
#define COMM_ISDEF_SIGNALBYTEINDEXOFPNCPB                                                           STD_OFF
#define COMM_ISDEF_USERREQPNCFULLCOMENDIDXOFPNCPB                                                   STD_OFF
#define COMM_ISDEF_USERREQPNCFULLCOMSTARTIDXOFPNCPB                                                 STD_OFF
#define COMM_ISDEF_PNCPBIND                                                                         STD_OFF
#define COMM_ISDEF_BUSTYPEIDOFPNCSIGNAL                                                             STD_OFF
#define COMM_ISDEF_CHANNELIDXOFPNCSIGNAL                                                            STD_OFF
#define COMM_ISDEF_CHANNELUSEDOFPNCSIGNAL                                                           STD_OFF
#define COMM_ISDEF_TYPEOFPNCSIGNAL                                                                  STD_OFF
#define COMM_ISDEF_PNCSIGNALIND                                                                     STD_OFF
#define COMM_ISDEF_PNCWITHOUTCHANNELS                                                               STD_OFF
#define COMM_ISDEF_SYNCHRONOUSWAKEUP                                                                STD_OFF
#define COMM_ISDEF_PARTITIONCONFIGIDXOFUSER                                                         STD_ON
#define COMM_ISDEF_PNCUSEROFUSER                                                                    STD_OFF
#define COMM_ISDEF_USERBYTEMASKENDIDXOFUSER                                                         STD_OFF
#define COMM_ISDEF_USERBYTEMASKSTARTIDXOFUSER                                                       STD_OFF
#define COMM_ISDEF_USERBYTEMASKUSEDOFUSER                                                           STD_ON
#define COMM_ISDEF_USERPNCBYTEMASKENDIDXOFUSER                                                      STD_OFF
#define COMM_ISDEF_USERPNCBYTEMASKLENGTHOFUSER                                                      STD_OFF
#define COMM_ISDEF_USERPNCBYTEMASKSTARTIDXOFUSER                                                    STD_OFF
#define COMM_ISDEF_USERPNCBYTEMASKUSEDOFUSER                                                        STD_OFF
#define COMM_ISDEF_CHANNELOFUSERBYTEMASK                                                            STD_OFF
#define COMM_ISDEF_CLEARMASKOFUSERBYTEMASK                                                          STD_ON
#define COMM_ISDEF_SETMASKOFUSERBYTEMASK                                                            STD_ON
#define COMM_ISDEF_USERREQFULLCOMIDXOFUSERBYTEMASK                                                  STD_OFF
#define COMM_ISDEF_USERMODENOTIFUNC                                                                 STD_OFF
#define COMM_ISDEF_USERMODENOTIFICATIONONLYFORPNCUSERS                                              STD_ON
#define COMM_ISDEF_CLEARMASKOFUSERPNCBYTEMASK                                                       STD_OFF
#define COMM_ISDEF_PNCIDOFUSERPNCBYTEMASK                                                           STD_OFF
#define COMM_ISDEF_PNCIDXOFUSERPNCBYTEMASK                                                          STD_OFF
#define COMM_ISDEF_SETMASKOFUSERPNCBYTEMASK                                                         STD_OFF
#define COMM_ISDEF_USERREQPNCFULLCOMIDXOFUSERPNCBYTEMASK                                            STD_OFF
#define COMM_ISDEF_USERWITHSINGLEPNC                                                                STD_OFF
#define COMM_ISDEF_WAKEUPINHIBITION                                                                 STD_OFF
#define COMM_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                      STD_ON
#define COMM_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define COMM_ISDEF_ACTIVECOMMODEOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_ISDEF_ACTIVEPNCCOMMODEOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_ISDEF_BUSCOMMODEREQFRSHUTDOWNOFPCPARTITIONCONFIG                                       STD_ON
#define COMM_ISDEF_BUSCOMMODEREQOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_ISDEF_BUSPNCCOMMODEREQOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_ISDEF_BUSSLEEPMODEINDICATEDOFPCPARTITIONCONFIG                                         STD_ON
#define COMM_ISDEF_BUSSMSTATEOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ISDEF_BUSTYPEFROFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_ISDEF_CHANNELOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_ISDEF_CHANNELPBOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_ISDEF_COMALLOWEDOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ISDEF_COORDPNCWITHGWPASSIVEANDMANAGEDCHANNELSOFPCPARTITIONCONFIG                       STD_ON
#define COMM_ISDEF_DCMINDICATIONOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_ISDEF_DCMREQUESTACTIVEOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_ISDEF_ECUMWAKEUPINDICATEDOFPCPARTITIONCONFIG                                           STD_ON
#define COMM_ISDEF_EIRATXSIGNALINDIRECTIONOFPCPARTITIONCONFIG                                       STD_ON
#define COMM_ISDEF_EXTENDEDRAMCHECKOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_ISDEF_FORWARDNMGATEWAYOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_ISDEF_FORWARDSYNCHRONIZEDPNCSHUTDOWNINDICATEDOFPCPARTITIONCONFIG                       STD_ON
#define COMM_ISDEF_FRSHUTDOWNOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ISDEF_FULLCOMREQUESTERSOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_ISDEF_FULLCOMMREQUESTNOTIFOFPCPARTITIONCONFIG                                          STD_ON
#define COMM_ISDEF_FULLNMTYPEOFCHANNELOFPCPARTITIONCONFIG                                           STD_ON
#define COMM_ISDEF_INHIBITIONOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ISDEF_INITSTATUSOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ISDEF_KEEPAWAKECHANNELSOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_ISDEF_LASTSTATECHANGEOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_ISDEF_LIGHTNMTYPEOFCHANNELOFPCPARTITIONCONFIG                                          STD_ON
#define COMM_ISDEF_LINSLAVENMTYPEOFCHANNELOFPCPARTITIONCONFIG                                       STD_ON
#define COMM_ISDEF_MINFULLCOMMODETIMEROFPCPARTITIONCONFIG                                           STD_ON
#define COMM_ISDEF_MODELIMITATIONOFPCPARTITIONCONFIG                                                STD_ON
#define COMM_ISDEF_NMGWEXTOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_ISDEF_NMLIGHTTIMEROFPCPARTITIONCONFIG                                                  STD_ON
#define COMM_ISDEF_NMSTARTUPINDICATEDOFPCPARTITIONCONFIG                                            STD_ON
#define COMM_ISDEF_NONENMTYPEOFCHANNELOFPCPARTITIONCONFIG                                           STD_ON
#define COMM_ISDEF_NOTIFYPNCSTATECHANGEOFPCPARTITIONCONFIG                                          STD_ON
#define COMM_ISDEF_NVMSTOREREQOFPCPARTITIONCONFIG                                                   STD_ON
#define COMM_ISDEF_ONLYNONENMTYPEOFCHANNELOFPCPARTITIONCONFIG                                       STD_ON
#define COMM_ISDEF_PNC0VECTORAVOIDANCEOFPCPARTITIONCONFIG                                           STD_ON
#define COMM_ISDEF_PNCCHANNELMAPPINGOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_ISDEF_PNCCHECKENABLEDATRUNTIMEOFPCPARTITIONCONFIG                                      STD_ON
#define COMM_ISDEF_PNCEIRARXOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_ISDEF_PNCEXTENDEDFUNCTIONALITYOFPCPARTITIONCONFIG                                      STD_ON
#define COMM_ISDEF_PNCGWTYPEACTIVEOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_ISDEF_PNCGWTYPENONEOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_ISDEF_PNCGWTYPEPASSIVEOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_ISDEF_PNCLIMITATIONOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_ISDEF_PNCOFPCPARTITIONCONFIG                                                           STD_ON
#define COMM_ISDEF_PNCPSLEEPTIMEROFPCPARTITIONCONFIG                                                STD_ON
#define COMM_ISDEF_PNCPBINDOFPCPARTITIONCONFIG                                                      STD_ON
#define COMM_ISDEF_PNCPBOFPCPARTITIONCONFIG                                                         STD_ON
#define COMM_ISDEF_PNCSIGNALINDOFPCPARTITIONCONFIG                                                  STD_ON
#define COMM_ISDEF_PNCSIGNALOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_ISDEF_PNCSIGNALVALUESOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_ISDEF_PNCTOCHANNELROUTINGSTATEOFPCPARTITIONCONFIG                                      STD_ON
#define COMM_ISDEF_PNCWITHOUTCHANNELSOFPCPARTITIONCONFIG                                            STD_ON
#define COMM_ISDEF_POSTINITIALIZEDOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_ISDEF_RESETREQUIREDOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_ISDEF_SIMULATEDSMMODEOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_ISDEF_STATECHANGEOFPCPARTITIONCONFIG                                                   STD_ON
#define COMM_ISDEF_SYNCHRONOUSWAKEUPOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_ISDEF_USERBYTEMASKOFPCPARTITIONCONFIG                                                  STD_ON
#define COMM_ISDEF_USERMODENOTIFUNCOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_ISDEF_USERMODENOTIFICATIONONLYFORPNCUSERSOFPCPARTITIONCONFIG                           STD_ON
#define COMM_ISDEF_USEROFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_ISDEF_USERPNCBYTEMASKOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_ISDEF_USERREQFULLCOMOFPCPARTITIONCONFIG                                                STD_ON
#define COMM_ISDEF_USERREQPNCFULLCOMOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_ISDEF_USERWITHSINGLEPNCOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_ISDEF_WAKEUPINHIBITIONOFPCPARTITIONCONFIG                                              STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCEqualsAlwaysToDefines  ComM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define COMM_EQ2_BUSTYPEFR                                                                          
#define COMM_EQ2_BUSTYPEOFCHANNEL                                                                   
#define COMM_EQ2_GETCURRENTBUSSMMODEAPIOFCHANNEL                                                    
#define COMM_EQ2_GWTYPEOFCHANNEL                                                                    COMM_GATEWAY_TYPE_NONE
#define COMM_EQ2_INHIBITIONINITVALUEOFCHANNEL                                                       0x00u
#define COMM_EQ2_INVALIDHNDOFCHANNEL                                                                
#define COMM_EQ2_J1939SUPPORTOFCHANNEL                                                              
#define COMM_EQ2_MAINFUNCTIONNEEDSSYNCOFCHANNEL                                                     
#define COMM_EQ2_MANAGINGCHANNELIDOFCHANNEL                                                         255u
#define COMM_EQ2_MANAGINGCHANNELOFCHANNEL                                                           
#define COMM_EQ2_MANAGINGUSEROFCHANNEL                                                              
#define COMM_EQ2_MINFULLCOMTIMEOFCHANNEL                                                            
#define COMM_EQ2_NMLIGHTDURATIONOFCHANNEL                                                           
#define COMM_EQ2_NMLIGHTSILENTDURATIONOFCHANNEL                                                     
#define COMM_EQ2_NMSUPPORTOFCHANNEL                                                                 
#define COMM_EQ2_NMTYPEOFCHANNEL                                                                    COMM_NONE_NMTYPEOFCHANNEL
#define COMM_EQ2_PARTITIONCONFIGIDXOFCHANNEL                                                        0u
#define COMM_EQ2_PASSIVEORLINSLAVEOFCHANNEL                                                         
#define COMM_EQ2_PNCNMREQUESTOFCHANNEL                                                              
#define COMM_EQ2_REQUESTBUSSMMODEAPIOFCHANNEL                                                       
#define COMM_EQ2_RESETAFTERFORCINGNOCOMMOFCHANNEL                                                   
#define COMM_EQ2_SILENTSUPPORTOFCHANNEL                                                             
#define COMM_EQ2_WAKEUPSTATEOFCHANNEL                                                               COMM_FULL_COM_NETWORK_REQUESTED
#define COMM_EQ2_INVALIDHNDOFCHANNELPB                                                              
#define COMM_EQ2_PNCLIMITATIONENDIDXOFCHANNELPB                                                     
#define COMM_EQ2_PNCLIMITATIONSTARTIDXOFCHANNELPB                                                   
#define COMM_EQ2_PNCLIMITATIONUSEDOFCHANNELPB                                                       
#define COMM_EQ2_PNCPBINDENDIDXOFCHANNELPB                                                          
#define COMM_EQ2_PNCPBINDSTARTIDXOFCHANNELPB                                                        
#define COMM_EQ2_PNCPBINDUSEDOFCHANNELPB                                                            
#define COMM_EQ2_USERREQFULLCOMENDIDXOFCHANNELPB                                                    
#define COMM_EQ2_USERREQFULLCOMSTARTIDXOFCHANNELPB                                                  
#define COMM_EQ2_USERREQFULLCOMUSEDOFCHANNELPB                                                      TRUE
#define COMM_EQ2_COORDPNCWITHGWPASSIVEANDMANAGEDCHANNELS                                            
#define COMM_EQ2_DCMINDICATION                                                                      TRUE
#define COMM_EQ2_EXTENDEDRAMCHECK                                                                   
#define COMM_EQ2_FULLCOMMREQUESTNOTIF                                                               
#define COMM_EQ2_FULLNMTYPEOFCHANNEL                                                                
#define COMM_EQ2_KEEPAWAKECHANNELS                                                                  TRUE
#define COMM_EQ2_LIGHTNMTYPEOFCHANNEL                                                               
#define COMM_EQ2_LINSLAVENMTYPEOFCHANNEL                                                            
#define COMM_EQ2_MODELIMITATION                                                                     
#define COMM_EQ2_NMGWEXT                                                                            
#define COMM_EQ2_NONENMTYPEOFCHANNEL                                                                TRUE
#define COMM_EQ2_ONLYNONENMTYPEOFCHANNEL                                                            TRUE
#define COMM_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                         
#define COMM_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                 
#define COMM_EQ2_CLEARMASKOFPNC                                                                     
#define COMM_EQ2_COORDINATEDOFPNC                                                                   
#define COMM_EQ2_INTERMEDIATEPNCCOORDINATOROFPNC                                                    
#define COMM_EQ2_PNCIDOFPNC                                                                         
#define COMM_EQ2_SETMASKOFPNC                                                                       
#define COMM_EQ2_SYSTEMUSEROFPNC                                                                    
#define COMM_EQ2_TOPLEVELPNCCOORDINATOROFPNC                                                        
#define COMM_EQ2_WAKEUPENABLEDOFPNC                                                                 
#define COMM_EQ2_PNC0VECTORAVOIDANCE                                                                
#define COMM_EQ2_PNCCHANNELMAPPING                                                                  
#define COMM_EQ2_PNCCHECKENABLEDATRUNTIME                                                           
#define COMM_EQ2_PNCEIRARX                                                                          
#define COMM_EQ2_PNCEXTENDEDFUNCTIONALITY                                                           
#define COMM_EQ2_PNCGWTYPEACTIVE                                                                    
#define COMM_EQ2_PNCGWTYPENONE                                                                      
#define COMM_EQ2_PNCGWTYPEPASSIVE                                                                   
#define COMM_EQ2_PNCCHANNELMAPPINGENDIDXOFPNCPB                                                     
#define COMM_EQ2_PNCCHANNELMAPPINGSTARTIDXOFPNCPB                                                   
#define COMM_EQ2_PNCCHANNELMAPPINGUSEDOFPNCPB                                                       
#define COMM_EQ2_PNCSIGNALINDENDIDXOFPNCPB                                                          
#define COMM_EQ2_PNCSIGNALINDSTARTIDXOFPNCPB                                                        
#define COMM_EQ2_PNCSIGNALINDUSEDOFPNCPB                                                            
#define COMM_EQ2_SIGNALBYTEINDEXOFPNCPB                                                             
#define COMM_EQ2_USERREQPNCFULLCOMENDIDXOFPNCPB                                                     
#define COMM_EQ2_USERREQPNCFULLCOMSTARTIDXOFPNCPB                                                   
#define COMM_EQ2_PNCPBIND                                                                           
#define COMM_EQ2_BUSTYPEIDOFPNCSIGNAL                                                               
#define COMM_EQ2_CHANNELIDXOFPNCSIGNAL                                                              
#define COMM_EQ2_CHANNELUSEDOFPNCSIGNAL                                                             
#define COMM_EQ2_TYPEOFPNCSIGNAL                                                                    
#define COMM_EQ2_PNCSIGNALIND                                                                       
#define COMM_EQ2_PNCWITHOUTCHANNELS                                                                 
#define COMM_EQ2_SYNCHRONOUSWAKEUP                                                                  
#define COMM_EQ2_PARTITIONCONFIGIDXOFUSER                                                           0u
#define COMM_EQ2_PNCUSEROFUSER                                                                      
#define COMM_EQ2_USERBYTEMASKENDIDXOFUSER                                                           
#define COMM_EQ2_USERBYTEMASKSTARTIDXOFUSER                                                         
#define COMM_EQ2_USERBYTEMASKUSEDOFUSER                                                             TRUE
#define COMM_EQ2_USERPNCBYTEMASKENDIDXOFUSER                                                        
#define COMM_EQ2_USERPNCBYTEMASKLENGTHOFUSER                                                        
#define COMM_EQ2_USERPNCBYTEMASKSTARTIDXOFUSER                                                      
#define COMM_EQ2_USERPNCBYTEMASKUSEDOFUSER                                                          
#define COMM_EQ2_CHANNELOFUSERBYTEMASK                                                              
#define COMM_EQ2_CLEARMASKOFUSERBYTEMASK                                                            0xFEu
#define COMM_EQ2_SETMASKOFUSERBYTEMASK                                                              0x01u
#define COMM_EQ2_USERREQFULLCOMIDXOFUSERBYTEMASK                                                    
#define COMM_EQ2_USERMODENOTIFUNC                                                                   
#define COMM_EQ2_USERMODENOTIFICATIONONLYFORPNCUSERS                                                TRUE
#define COMM_EQ2_CLEARMASKOFUSERPNCBYTEMASK                                                         
#define COMM_EQ2_PNCIDOFUSERPNCBYTEMASK                                                             
#define COMM_EQ2_PNCIDXOFUSERPNCBYTEMASK                                                            
#define COMM_EQ2_SETMASKOFUSERPNCBYTEMASK                                                           
#define COMM_EQ2_USERREQPNCFULLCOMIDXOFUSERPNCBYTEMASK                                              
#define COMM_EQ2_USERWITHSINGLEPNC                                                                  
#define COMM_EQ2_WAKEUPINHIBITION                                                                   
#define COMM_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                        ComM_PCPartitionConfig
#define COMM_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                     ComM_PartitionIdentifiers
#define COMM_EQ2_ACTIVECOMMODEOFPCPARTITIONCONFIG                                                   ComM_ActiveComMode.raw
#define COMM_EQ2_ACTIVEPNCCOMMODEOFPCPARTITIONCONFIG                                                ComM_ActivePncComMode
#define COMM_EQ2_BUSCOMMODEREQFRSHUTDOWNOFPCPARTITIONCONFIG                                         ComM_BusComModeReqFrShutdown.raw
#define COMM_EQ2_BUSCOMMODEREQOFPCPARTITIONCONFIG                                                   ComM_BusComModeReq.raw
#define COMM_EQ2_BUSPNCCOMMODEREQOFPCPARTITIONCONFIG                                                ComM_BusPncComModeReq
#define COMM_EQ2_BUSSLEEPMODEINDICATEDOFPCPARTITIONCONFIG                                           ComM_BusSleepModeIndicated.raw
#define COMM_EQ2_BUSSMSTATEOFPCPARTITIONCONFIG                                                      ComM_BusSmState.raw
#define COMM_EQ2_BUSTYPEFROFPCPARTITIONCONFIG                                                       ComM_BusTypeFr
#define COMM_EQ2_CHANNELOFPCPARTITIONCONFIG                                                         ComM_Channel
#define COMM_EQ2_CHANNELPBOFPCPARTITIONCONFIG                                                       ComM_ChannelPb
#define COMM_EQ2_COMALLOWEDOFPCPARTITIONCONFIG                                                      ComM_ComAllowed.raw
#define COMM_EQ2_COORDPNCWITHGWPASSIVEANDMANAGEDCHANNELSOFPCPARTITIONCONFIG                         ComM_CoordPncWithGwPassiveAndManagedChannels
#define COMM_EQ2_DCMINDICATIONOFPCPARTITIONCONFIG                                                   ComM_DcmIndication
#define COMM_EQ2_DCMREQUESTACTIVEOFPCPARTITIONCONFIG                                                ComM_DcmRequestActive.raw
#define COMM_EQ2_ECUMWAKEUPINDICATEDOFPCPARTITIONCONFIG                                             ComM_EcuMWakeUpIndicated
#define COMM_EQ2_EIRATXSIGNALINDIRECTIONOFPCPARTITIONCONFIG                                         ComM_EiraTxSignalIndirection
#define COMM_EQ2_EXTENDEDRAMCHECKOFPCPARTITIONCONFIG                                                ComM_ExtendedRamCheck
#define COMM_EQ2_FORWARDNMGATEWAYOFPCPARTITIONCONFIG                                                ComM_ForwardNmGateway.raw
#define COMM_EQ2_FORWARDSYNCHRONIZEDPNCSHUTDOWNINDICATEDOFPCPARTITIONCONFIG                         ComM_ForwardSynchronizedPncShutdownIndicated
#define COMM_EQ2_FRSHUTDOWNOFPCPARTITIONCONFIG                                                      ComM_FrShutdown.raw
#define COMM_EQ2_FULLCOMREQUESTERSOFPCPARTITIONCONFIG                                               ComM_FullComRequesters
#define COMM_EQ2_FULLCOMMREQUESTNOTIFOFPCPARTITIONCONFIG                                            ComM_FullCommRequestNotif
#define COMM_EQ2_FULLNMTYPEOFCHANNELOFPCPARTITIONCONFIG                                             ComM_FullNmTypeOfChannel
#define COMM_EQ2_INHIBITIONOFPCPARTITIONCONFIG                                                      (&(ComM_Inhibition))
#define COMM_EQ2_INITSTATUSOFPCPARTITIONCONFIG                                                      (&(ComM_InitStatus))
#define COMM_EQ2_KEEPAWAKECHANNELSOFPCPARTITIONCONFIG                                               ComM_KeepAwakeChannels
#define COMM_EQ2_LASTSTATECHANGEOFPCPARTITIONCONFIG                                                 ComM_LastStateChange
#define COMM_EQ2_LIGHTNMTYPEOFCHANNELOFPCPARTITIONCONFIG                                            ComM_LightNmTypeOfChannel
#define COMM_EQ2_LINSLAVENMTYPEOFCHANNELOFPCPARTITIONCONFIG                                         ComM_LinslaveNmTypeOfChannel
#define COMM_EQ2_MINFULLCOMMODETIMEROFPCPARTITIONCONFIG                                             ComM_MinFullComModeTimer.raw
#define COMM_EQ2_MODELIMITATIONOFPCPARTITIONCONFIG                                                  ComM_ModeLimitation
#define COMM_EQ2_NMGWEXTOFPCPARTITIONCONFIG                                                         ComM_NmGwExt
#define COMM_EQ2_NMLIGHTTIMEROFPCPARTITIONCONFIG                                                    ComM_NmLightTimer.raw
#define COMM_EQ2_NMSTARTUPINDICATEDOFPCPARTITIONCONFIG                                              ComM_NmStartUpIndicated
#define COMM_EQ2_NONENMTYPEOFCHANNELOFPCPARTITIONCONFIG                                             ComM_NoneNmTypeOfChannel
#define COMM_EQ2_NOTIFYPNCSTATECHANGEOFPCPARTITIONCONFIG                                            (&(ComM_NotifyPncStateChange))
#define COMM_EQ2_NVMSTOREREQOFPCPARTITIONCONFIG                                                     (&(ComM_NvMStoreReq))
#define COMM_EQ2_ONLYNONENMTYPEOFCHANNELOFPCPARTITIONCONFIG                                         ComM_OnlyNoneNmTypeOfChannel
#define COMM_EQ2_PNC0VECTORAVOIDANCEOFPCPARTITIONCONFIG                                             ComM_Pnc0VectorAvoidance
#define COMM_EQ2_PNCCHANNELMAPPINGOFPCPARTITIONCONFIG                                               ComM_PncChannelMapping
#define COMM_EQ2_PNCCHECKENABLEDATRUNTIMEOFPCPARTITIONCONFIG                                        ComM_PncCheckEnabledAtRuntime
#define COMM_EQ2_PNCEIRARXOFPCPARTITIONCONFIG                                                       ComM_PncEiraRx
#define COMM_EQ2_PNCEXTENDEDFUNCTIONALITYOFPCPARTITIONCONFIG                                        ComM_PncExtendedFunctionality
#define COMM_EQ2_PNCGWTYPEACTIVEOFPCPARTITIONCONFIG                                                 ComM_PncGwTypeActive
#define COMM_EQ2_PNCGWTYPENONEOFPCPARTITIONCONFIG                                                   ComM_PncGwTypeNone
#define COMM_EQ2_PNCGWTYPEPASSIVEOFPCPARTITIONCONFIG                                                ComM_PncGwTypePassive
#define COMM_EQ2_PNCLIMITATIONOFPCPARTITIONCONFIG                                                   ComM_PncLimitation
#define COMM_EQ2_PNCOFPCPARTITIONCONFIG                                                             ComM_Pnc
#define COMM_EQ2_PNCPSLEEPTIMEROFPCPARTITIONCONFIG                                                  ComM_PncPSleepTimer
#define COMM_EQ2_PNCPBINDOFPCPARTITIONCONFIG                                                        ComM_PncPbInd
#define COMM_EQ2_PNCPBOFPCPARTITIONCONFIG                                                           ComM_PncPb
#define COMM_EQ2_PNCSIGNALINDOFPCPARTITIONCONFIG                                                    ComM_PncSignalInd
#define COMM_EQ2_PNCSIGNALOFPCPARTITIONCONFIG                                                       ComM_PncSignal
#define COMM_EQ2_PNCSIGNALVALUESOFPCPARTITIONCONFIG                                                 ComM_PncSignalValues
#define COMM_EQ2_PNCTOCHANNELROUTINGSTATEOFPCPARTITIONCONFIG                                        ComM_PncToChannelRoutingState.raw
#define COMM_EQ2_PNCWITHOUTCHANNELSOFPCPARTITIONCONFIG                                              ComM_PncWithoutChannels
#define COMM_EQ2_POSTINITIALIZEDOFPCPARTITIONCONFIG                                                 ComM_PostInitialized
#define COMM_EQ2_RESETREQUIREDOFPCPARTITIONCONFIG                                                   ComM_ResetRequired.raw
#define COMM_EQ2_SIMULATEDSMMODEOFPCPARTITIONCONFIG                                                 ComM_SimulatedSmMode.raw
#define COMM_EQ2_STATECHANGEOFPCPARTITIONCONFIG                                                     ComM_StateChange.raw
#define COMM_EQ2_SYNCHRONOUSWAKEUPOFPCPARTITIONCONFIG                                               ComM_SynchronousWakeUp
#define COMM_EQ2_USERBYTEMASKOFPCPARTITIONCONFIG                                                    ComM_UserByteMask
#define COMM_EQ2_USERMODENOTIFUNCOFPCPARTITIONCONFIG                                                ComM_UserModeNotiFunc
#define COMM_EQ2_USERMODENOTIFICATIONONLYFORPNCUSERSOFPCPARTITIONCONFIG                             ComM_UserModeNotificationOnlyForPncUsers
#define COMM_EQ2_USEROFPCPARTITIONCONFIG                                                            ComM_User
#define COMM_EQ2_USERPNCBYTEMASKOFPCPARTITIONCONFIG                                                 ComM_UserPncByteMask
#define COMM_EQ2_USERREQFULLCOMOFPCPARTITIONCONFIG                                                  ComM_UserReqFullCom
#define COMM_EQ2_USERREQPNCFULLCOMOFPCPARTITIONCONFIG                                               ComM_UserReqPncFullCom
#define COMM_EQ2_USERWITHSINGLEPNCOFPCPARTITIONCONFIG                                               ComM_UserWithSinglePnc
#define COMM_EQ2_WAKEUPINHIBITIONOFPCPARTITIONCONFIG                                                ComM_WakeupInhibition
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCSymbolicNonDereferenciateablePointers  ComM Symbolic Non Dereferenciateable Pointers (PRE_COMPILE)
  \brief  Symbolic non dereferenciateable pointers to be used if all values are optimized to a defined and to return a correct value for has macros in variants.
  \{
*/ 
#define ComM_ActivePncComMode                                                                       ((ComM_ActivePncComModePtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_BusComModeReqFrShutdown                                                                ((ComM_BusComModeReqFrShutdownPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_BusPncComModeReq                                                                       ((ComM_BusPncComModeReqPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_BusSleepModeIndicated                                                                  ((ComM_BusSleepModeIndicatedPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_BusTypeFr                                                                              ((ComM_BusTypeFrPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_CoordPncWithGwPassiveAndManagedChannels                                                ((ComM_CoordPncWithGwPassiveAndManagedChannelsPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_EiraTxSignalIndirection                                                                ((ComM_EiraTxSignalIndirectionPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_ExtendedRamCheck                                                                       ((ComM_ExtendedRamCheckPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_ForwardNmGateway                                                                       ((ComM_ForwardNmGatewayPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_ForwardSynchronizedPncShutdownIndicated                                                ((ComM_ForwardSynchronizedPncShutdownIndicatedPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_FrShutdown                                                                             ((ComM_FrShutdownPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_FullComRequesters                                                                      ((ComM_FullComRequestersPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_FullCommRequestNotif                                                                   ((ComM_FullCommRequestNotifPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_FullNmTypeOfChannel                                                                    ((ComM_FullNmTypeOfChannelPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_LastStateChange                                                                        ((ComM_LastStateChangePtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_LightNmTypeOfChannel                                                                   ((ComM_LightNmTypeOfChannelPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_LinslaveNmTypeOfChannel                                                                ((ComM_LinslaveNmTypeOfChannelPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_MinFullComModeTimer                                                                    ((ComM_MinFullComModeTimerPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_ModeLimitation                                                                         ((ComM_ModeLimitationPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_NmGwExt                                                                                ((ComM_NmGwExtPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_NmLightTimer                                                                           ((ComM_NmLightTimerPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_NotifyPncStateChange                                                                   ((ComM_NotifyPncStateChangePtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_NvMStoreReq                                                                            ((ComM_NvMStoreReqPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_Pnc                                                                                    ((ComM_PncPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_Pnc0VectorAvoidance                                                                    ((ComM_Pnc0VectorAvoidancePtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncChannelMapping                                                                      ((ComM_PncChannelMappingPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncCheckEnabledAtRuntime                                                               ((ComM_PncCheckEnabledAtRuntimePtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncEiraRx                                                                              ((ComM_PncEiraRxPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncExtendedFunctionality                                                               ((ComM_PncExtendedFunctionalityPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncGwTypeActive                                                                        ((ComM_PncGwTypeActivePtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncGwTypeNone                                                                          ((ComM_PncGwTypeNonePtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncGwTypePassive                                                                       ((ComM_PncGwTypePassivePtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncLimitation                                                                          ((ComM_PncLimitationPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncPSleepTimer                                                                         ((ComM_PncPSleepTimerPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncPb                                                                                  ((ComM_PncPbPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncPbInd                                                                               ((ComM_PncPbIndPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncSignal                                                                              ((ComM_PncSignalPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncSignalInd                                                                           ((ComM_PncSignalIndPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncSignalValues                                                                        ((ComM_PncSignalValuesPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncToChannelRoutingState                                                               ((ComM_PncToChannelRoutingStatePtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_PncWithoutChannels                                                                     ((ComM_PncWithoutChannelsPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_ResetRequired                                                                          ((ComM_ResetRequiredPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_SimulatedSmMode                                                                        ((ComM_SimulatedSmModePtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_StateChange                                                                            ((ComM_StateChangePtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_SynchronousWakeUp                                                                      ((ComM_SynchronousWakeUpPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_UserModeNotiFunc                                                                       ((ComM_UserModeNotiFuncPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_UserPncByteMask                                                                        ((ComM_UserPncByteMaskPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_UserReqPncFullCom                                                                      ((ComM_UserReqPncFullComPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_UserWithSinglePnc                                                                      ((ComM_UserWithSinglePncPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define ComM_WakeupInhibition                                                                       ((ComM_WakeupInhibitionPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCSymbolicInitializationPointers  ComM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define ComM_Config_Ptr                                                                             NULL_PTR  /**< symbolic identifier which shall be used to initialize 'ComM' */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCInitializationSymbols  ComM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define ComM_Config                                                                                 NULL_PTR  /**< symbolic identifier which could be used to initialize 'ComM */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCGeneral  ComM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define COMM_CHECK_INIT_POINTER                                                                     STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define COMM_FINAL_MAGIC_NUMBER                                                                     0x0C1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of ComM */
#define COMM_INDIVIDUAL_POSTBUILD                                                                   STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'ComM' is not configured to be postbuild capable. */
#define COMM_INIT_DATA                                                                              COMM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define COMM_INIT_DATA_HASH_CODE                                                                    -215872543  /**< the precompile constant to validate the initialization structure at initialization time of ComM with a hashcode. The seed value is '0x0C1Eu' */
#define COMM_USE_ECUM_BSW_ERROR_HOOK                                                                STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define COMM_USE_INIT_POINTER                                                                       STD_OFF  /**< STD_ON if the init pointer ComM shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComMPBDataSwitches  ComM Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COMM_PBCONFIG                                                                               STD_OFF  /**< the module configuration is VARIANT_PRE_COMPILE. */
#define COMM_LTCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define COMM_PBPARTITIONCONFIGOFPBCONFIG                                                            STD_OFF  /**< the module configuration is VARIANT_PRE_COMPILE. */
#define COMM_PCCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< the module configuration is VARIANT_PRE_COMPILE. */
#define COMM_PBPARTITIONCONFIG                                                                      STD_OFF  /**< the module configuration is VARIANT_PRE_COMPILE. */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPBIsReducedToDefineDefines  ComM Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define COMM_ISDEF_LTCONFIGIDXOFPBCONFIG                                                            STD_OFF
#define COMM_ISDEF_PBPARTITIONCONFIGOFPBCONFIG                                                      STD_OFF
#define COMM_ISDEF_PCCONFIGIDXOFPBCONFIG                                                            STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  ComMPBEqualsAlwaysToDefines  ComM Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define COMM_EQ2_LTCONFIGIDXOFPBCONFIG                                                              
#define COMM_EQ2_PBPARTITIONCONFIGOFPBCONFIG                                                        
#define COMM_EQ2_PCCONFIGIDXOFPBCONFIG                                                              
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
typedef P2FUNC(Std_ReturnType, COMM_CODE, ComM_StateNotiFuncPtrType) (Rte_ModeType_ComMMode  nextMode);
typedef P2FUNC(Std_ReturnType, COMM_CODE, RequestBusSMModeApiType) (NetworkHandleType Channel, ComM_ModeType ComMode);
typedef P2FUNC(Std_ReturnType, COMM_CODE, GetCurrentBusSMModeApiType) (NetworkHandleType Channel, P2VAR(ComM_ModeType, AUTOMATIC, AUTOMATIC) ComMode);

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  ComMPCSizeOfTypes  ComM SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for ComM_SizeOfActiveComMode */
typedef uint8 ComM_SizeOfActiveComModeType;

/**   \brief  value based type definition for ComM_SizeOfActivePncComMode */
typedef uint8 ComM_SizeOfActivePncComModeType;

/**   \brief  value based type definition for ComM_SizeOfBusComModeReq */
typedef uint8 ComM_SizeOfBusComModeReqType;

/**   \brief  value based type definition for ComM_SizeOfBusComModeReqFrShutdown */
typedef uint8 ComM_SizeOfBusComModeReqFrShutdownType;

/**   \brief  value based type definition for ComM_SizeOfBusPncComModeReq */
typedef uint8 ComM_SizeOfBusPncComModeReqType;

/**   \brief  value based type definition for ComM_SizeOfBusSleepModeIndicated */
typedef uint8 ComM_SizeOfBusSleepModeIndicatedType;

/**   \brief  value based type definition for ComM_SizeOfBusSmState */
typedef uint8 ComM_SizeOfBusSmStateType;

/**   \brief  value based type definition for ComM_SizeOfBusTypeFr */
typedef uint8 ComM_SizeOfBusTypeFrType;

/**   \brief  value based type definition for ComM_SizeOfChannel */
typedef uint8 ComM_SizeOfChannelType;

/**   \brief  value based type definition for ComM_SizeOfChannelPb */
typedef uint8 ComM_SizeOfChannelPbType;

/**   \brief  value based type definition for ComM_SizeOfComAllowed */
typedef uint8 ComM_SizeOfComAllowedType;

/**   \brief  value based type definition for ComM_SizeOfCoordPncWithGwPassiveAndManagedChannels */
typedef uint8 ComM_SizeOfCoordPncWithGwPassiveAndManagedChannelsType;

/**   \brief  value based type definition for ComM_SizeOfDcmIndication */
typedef uint8 ComM_SizeOfDcmIndicationType;

/**   \brief  value based type definition for ComM_SizeOfDcmRequestActive */
typedef uint8 ComM_SizeOfDcmRequestActiveType;

/**   \brief  value based type definition for ComM_SizeOfEcuMWakeUpIndicated */
typedef uint8 ComM_SizeOfEcuMWakeUpIndicatedType;

/**   \brief  value based type definition for ComM_SizeOfEiraTxSignalIndirection */
typedef uint8 ComM_SizeOfEiraTxSignalIndirectionType;

/**   \brief  value based type definition for ComM_SizeOfExtendedRamCheck */
typedef uint8 ComM_SizeOfExtendedRamCheckType;

/**   \brief  value based type definition for ComM_SizeOfForwardNmGateway */
typedef uint8 ComM_SizeOfForwardNmGatewayType;

/**   \brief  value based type definition for ComM_SizeOfForwardSynchronizedPncShutdownIndicated */
typedef uint8 ComM_SizeOfForwardSynchronizedPncShutdownIndicatedType;

/**   \brief  value based type definition for ComM_SizeOfFrShutdown */
typedef uint8 ComM_SizeOfFrShutdownType;

/**   \brief  value based type definition for ComM_SizeOfFullComRequesters */
typedef uint8 ComM_SizeOfFullComRequestersType;

/**   \brief  value based type definition for ComM_SizeOfFullCommRequestNotif */
typedef uint8 ComM_SizeOfFullCommRequestNotifType;

/**   \brief  value based type definition for ComM_SizeOfFullNmTypeOfChannel */
typedef uint8 ComM_SizeOfFullNmTypeOfChannelType;

/**   \brief  value based type definition for ComM_SizeOfKeepAwakeChannels */
typedef uint8 ComM_SizeOfKeepAwakeChannelsType;

/**   \brief  value based type definition for ComM_SizeOfLastStateChange */
typedef uint8 ComM_SizeOfLastStateChangeType;

/**   \brief  value based type definition for ComM_SizeOfLightNmTypeOfChannel */
typedef uint8 ComM_SizeOfLightNmTypeOfChannelType;

/**   \brief  value based type definition for ComM_SizeOfLinslaveNmTypeOfChannel */
typedef uint8 ComM_SizeOfLinslaveNmTypeOfChannelType;

/**   \brief  value based type definition for ComM_SizeOfMinFullComModeTimer */
typedef uint8 ComM_SizeOfMinFullComModeTimerType;

/**   \brief  value based type definition for ComM_SizeOfModeLimitation */
typedef uint8 ComM_SizeOfModeLimitationType;

/**   \brief  value based type definition for ComM_SizeOfNmGwExt */
typedef uint8 ComM_SizeOfNmGwExtType;

/**   \brief  value based type definition for ComM_SizeOfNmLightTimer */
typedef uint8 ComM_SizeOfNmLightTimerType;

/**   \brief  value based type definition for ComM_SizeOfNmStartUpIndicated */
typedef uint8 ComM_SizeOfNmStartUpIndicatedType;

/**   \brief  value based type definition for ComM_SizeOfNoneNmTypeOfChannel */
typedef uint8 ComM_SizeOfNoneNmTypeOfChannelType;

/**   \brief  value based type definition for ComM_SizeOfOnlyNoneNmTypeOfChannel */
typedef uint8 ComM_SizeOfOnlyNoneNmTypeOfChannelType;

/**   \brief  value based type definition for ComM_SizeOfPartitionIdentifiers */
typedef uint8 ComM_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for ComM_SizeOfPnc */
typedef uint8 ComM_SizeOfPncType;

/**   \brief  value based type definition for ComM_SizeOfPnc0VectorAvoidance */
typedef uint8 ComM_SizeOfPnc0VectorAvoidanceType;

/**   \brief  value based type definition for ComM_SizeOfPncChannelMapping */
typedef uint8 ComM_SizeOfPncChannelMappingType;

/**   \brief  value based type definition for ComM_SizeOfPncCheckEnabledAtRuntime */
typedef uint8 ComM_SizeOfPncCheckEnabledAtRuntimeType;

/**   \brief  value based type definition for ComM_SizeOfPncEiraRx */
typedef uint8 ComM_SizeOfPncEiraRxType;

/**   \brief  value based type definition for ComM_SizeOfPncExtendedFunctionality */
typedef uint8 ComM_SizeOfPncExtendedFunctionalityType;

/**   \brief  value based type definition for ComM_SizeOfPncGwTypeActive */
typedef uint8 ComM_SizeOfPncGwTypeActiveType;

/**   \brief  value based type definition for ComM_SizeOfPncGwTypeNone */
typedef uint8 ComM_SizeOfPncGwTypeNoneType;

/**   \brief  value based type definition for ComM_SizeOfPncGwTypePassive */
typedef uint8 ComM_SizeOfPncGwTypePassiveType;

/**   \brief  value based type definition for ComM_SizeOfPncLimitation */
typedef uint8 ComM_SizeOfPncLimitationType;

/**   \brief  value based type definition for ComM_SizeOfPncPSleepTimer */
typedef uint8 ComM_SizeOfPncPSleepTimerType;

/**   \brief  value based type definition for ComM_SizeOfPncPb */
typedef uint8 ComM_SizeOfPncPbType;

/**   \brief  value based type definition for ComM_SizeOfPncPbInd */
typedef uint8 ComM_SizeOfPncPbIndType;

/**   \brief  value based type definition for ComM_SizeOfPncSignal */
typedef uint8 ComM_SizeOfPncSignalType;

/**   \brief  value based type definition for ComM_SizeOfPncSignalInd */
typedef uint8 ComM_SizeOfPncSignalIndType;

/**   \brief  value based type definition for ComM_SizeOfPncSignalValues */
typedef uint8 ComM_SizeOfPncSignalValuesType;

/**   \brief  value based type definition for ComM_SizeOfPncToChannelRoutingState */
typedef uint8 ComM_SizeOfPncToChannelRoutingStateType;

/**   \brief  value based type definition for ComM_SizeOfPncWithoutChannels */
typedef uint8 ComM_SizeOfPncWithoutChannelsType;

/**   \brief  value based type definition for ComM_SizeOfPostInitialized */
typedef uint8 ComM_SizeOfPostInitializedType;

/**   \brief  value based type definition for ComM_SizeOfResetRequired */
typedef uint8 ComM_SizeOfResetRequiredType;

/**   \brief  value based type definition for ComM_SizeOfSimulatedSmMode */
typedef uint8 ComM_SizeOfSimulatedSmModeType;

/**   \brief  value based type definition for ComM_SizeOfStateChange */
typedef uint8 ComM_SizeOfStateChangeType;

/**   \brief  value based type definition for ComM_SizeOfSynchronousWakeUp */
typedef uint8 ComM_SizeOfSynchronousWakeUpType;

/**   \brief  value based type definition for ComM_SizeOfUser */
typedef uint8 ComM_SizeOfUserType;

/**   \brief  value based type definition for ComM_SizeOfUserByteMask */
typedef uint8 ComM_SizeOfUserByteMaskType;

/**   \brief  value based type definition for ComM_SizeOfUserModeNotiFunc */
typedef uint8 ComM_SizeOfUserModeNotiFuncType;

/**   \brief  value based type definition for ComM_SizeOfUserModeNotificationOnlyForPncUsers */
typedef uint8 ComM_SizeOfUserModeNotificationOnlyForPncUsersType;

/**   \brief  value based type definition for ComM_SizeOfUserPncByteMask */
typedef uint8 ComM_SizeOfUserPncByteMaskType;

/**   \brief  value based type definition for ComM_SizeOfUserReqFullCom */
typedef uint8 ComM_SizeOfUserReqFullComType;

/**   \brief  value based type definition for ComM_SizeOfUserReqPncFullCom */
typedef uint8 ComM_SizeOfUserReqPncFullComType;

/**   \brief  value based type definition for ComM_SizeOfUserWithSinglePnc */
typedef uint8 ComM_SizeOfUserWithSinglePncType;

/**   \brief  value based type definition for ComM_SizeOfWakeupInhibition */
typedef uint8 ComM_SizeOfWakeupInhibitionType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComMPCIterableTypes  ComM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate ComM_BusTypeFr */
typedef uint8_least ComM_BusTypeFrIterType;

/**   \brief  type used to iterate ComM_Channel */
typedef uint8_least ComM_ChannelIterType;

/**   \brief  type used to iterate ComM_ChannelPb */
typedef uint8_least ComM_ChannelPbIterType;

/**   \brief  type used to iterate ComM_CoordPncWithGwPassiveAndManagedChannels */
typedef uint8_least ComM_CoordPncWithGwPassiveAndManagedChannelsIterType;

/**   \brief  type used to iterate ComM_DcmIndication */
typedef uint8_least ComM_DcmIndicationIterType;

/**   \brief  type used to iterate ComM_EcuMWakeUpIndicated */
typedef uint8_least ComM_EcuMWakeUpIndicatedIterType;

/**   \brief  type used to iterate ComM_EiraTxSignalIndirection */
typedef uint8_least ComM_EiraTxSignalIndirectionIterType;

/**   \brief  type used to iterate ComM_ExtendedRamCheck */
typedef uint8_least ComM_ExtendedRamCheckIterType;

/**   \brief  type used to iterate ComM_FullComRequesters */
typedef uint8_least ComM_FullComRequestersIterType;

/**   \brief  type used to iterate ComM_FullCommRequestNotif */
typedef uint8_least ComM_FullCommRequestNotifIterType;

/**   \brief  type used to iterate ComM_FullNmTypeOfChannel */
typedef uint8_least ComM_FullNmTypeOfChannelIterType;

/**   \brief  type used to iterate ComM_KeepAwakeChannels */
typedef uint8_least ComM_KeepAwakeChannelsIterType;

/**   \brief  type used to iterate ComM_LightNmTypeOfChannel */
typedef uint8_least ComM_LightNmTypeOfChannelIterType;

/**   \brief  type used to iterate ComM_LinslaveNmTypeOfChannel */
typedef uint8_least ComM_LinslaveNmTypeOfChannelIterType;

/**   \brief  type used to iterate ComM_ModeLimitation */
typedef uint8_least ComM_ModeLimitationIterType;

/**   \brief  type used to iterate ComM_NmGwExt */
typedef uint8_least ComM_NmGwExtIterType;

/**   \brief  type used to iterate ComM_NmStartUpIndicated */
typedef uint8_least ComM_NmStartUpIndicatedIterType;

/**   \brief  type used to iterate ComM_NoneNmTypeOfChannel */
typedef uint8_least ComM_NoneNmTypeOfChannelIterType;

/**   \brief  type used to iterate ComM_OnlyNoneNmTypeOfChannel */
typedef uint8_least ComM_OnlyNoneNmTypeOfChannelIterType;

/**   \brief  type used to iterate ComM_PartitionIdentifiers */
typedef uint8_least ComM_PartitionIdentifiersIterType;

/**   \brief  type used to iterate ComM_Pnc */
typedef uint8_least ComM_PncIterType;

/**   \brief  type used to iterate ComM_Pnc0VectorAvoidance */
typedef uint8_least ComM_Pnc0VectorAvoidanceIterType;

/**   \brief  type used to iterate ComM_PncChannelMapping */
typedef uint8_least ComM_PncChannelMappingIterType;

/**   \brief  type used to iterate ComM_PncCheckEnabledAtRuntime */
typedef uint8_least ComM_PncCheckEnabledAtRuntimeIterType;

/**   \brief  type used to iterate ComM_PncEiraRx */
typedef uint8_least ComM_PncEiraRxIterType;

/**   \brief  type used to iterate ComM_PncExtendedFunctionality */
typedef uint8_least ComM_PncExtendedFunctionalityIterType;

/**   \brief  type used to iterate ComM_PncGwTypeActive */
typedef uint8_least ComM_PncGwTypeActiveIterType;

/**   \brief  type used to iterate ComM_PncGwTypeNone */
typedef uint8_least ComM_PncGwTypeNoneIterType;

/**   \brief  type used to iterate ComM_PncGwTypePassive */
typedef uint8_least ComM_PncGwTypePassiveIterType;

/**   \brief  type used to iterate ComM_PncLimitation */
typedef uint8_least ComM_PncLimitationIterType;

/**   \brief  type used to iterate ComM_PncPb */
typedef uint8_least ComM_PncPbIterType;

/**   \brief  type used to iterate ComM_PncPbInd */
typedef uint8_least ComM_PncPbIndIterType;

/**   \brief  type used to iterate ComM_PncSignal */
typedef uint8_least ComM_PncSignalIterType;

/**   \brief  type used to iterate ComM_PncSignalInd */
typedef uint8_least ComM_PncSignalIndIterType;

/**   \brief  type used to iterate ComM_PncSignalValues */
typedef uint8_least ComM_PncSignalValuesIterType;

/**   \brief  type used to iterate ComM_PncWithoutChannels */
typedef uint8_least ComM_PncWithoutChannelsIterType;

/**   \brief  type used to iterate ComM_PostInitialized */
typedef uint8_least ComM_PostInitializedIterType;

/**   \brief  type used to iterate ComM_SynchronousWakeUp */
typedef uint8_least ComM_SynchronousWakeUpIterType;

/**   \brief  type used to iterate ComM_User */
typedef uint8_least ComM_UserIterType;

/**   \brief  type used to iterate ComM_UserByteMask */
typedef uint8_least ComM_UserByteMaskIterType;

/**   \brief  type used to iterate ComM_UserModeNotiFunc */
typedef uint8_least ComM_UserModeNotiFuncIterType;

/**   \brief  type used to iterate ComM_UserModeNotificationOnlyForPncUsers */
typedef uint8_least ComM_UserModeNotificationOnlyForPncUsersIterType;

/**   \brief  type used to iterate ComM_UserPncByteMask */
typedef uint8_least ComM_UserPncByteMaskIterType;

/**   \brief  type used to iterate ComM_UserReqFullCom */
typedef uint8_least ComM_UserReqFullComIterType;

/**   \brief  type used to iterate ComM_UserReqPncFullCom */
typedef uint8_least ComM_UserReqPncFullComIterType;

/**   \brief  type used to iterate ComM_UserWithSinglePnc */
typedef uint8_least ComM_UserWithSinglePncIterType;

/**   \brief  type used to iterate ComM_WakeupInhibition */
typedef uint8_least ComM_WakeupInhibitionIterType;

/**   \brief  type used to iterate ComM_PCPartitionConfig */
typedef uint8_least ComM_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCIterableTypesWithSizeRelations  ComM Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate ComM_ActiveComMode */
typedef ComM_ChannelIterType ComM_ActiveComModeIterType;

/**   \brief  type used to iterate ComM_ActivePncComMode */
typedef ComM_PncIterType ComM_ActivePncComModeIterType;

/**   \brief  type used to iterate ComM_BusComModeReq */
typedef ComM_ChannelIterType ComM_BusComModeReqIterType;

/**   \brief  type used to iterate ComM_BusComModeReqFrShutdown */
typedef ComM_ChannelIterType ComM_BusComModeReqFrShutdownIterType;

/**   \brief  type used to iterate ComM_BusPncComModeReq */
typedef ComM_PncIterType ComM_BusPncComModeReqIterType;

/**   \brief  type used to iterate ComM_BusSleepModeIndicated */
typedef ComM_ChannelIterType ComM_BusSleepModeIndicatedIterType;

/**   \brief  type used to iterate ComM_BusSmState */
typedef ComM_ChannelIterType ComM_BusSmStateIterType;

/**   \brief  type used to iterate ComM_ComAllowed */
typedef ComM_ChannelIterType ComM_ComAllowedIterType;

/**   \brief  type used to iterate ComM_DcmRequestActive */
typedef ComM_ChannelIterType ComM_DcmRequestActiveIterType;

/**   \brief  type used to iterate ComM_ForwardNmGateway */
typedef ComM_ChannelIterType ComM_ForwardNmGatewayIterType;

/**   \brief  type used to iterate ComM_ForwardSynchronizedPncShutdownIndicated */
typedef ComM_PncIterType ComM_ForwardSynchronizedPncShutdownIndicatedIterType;

/**   \brief  type used to iterate ComM_FrShutdown */
typedef ComM_ChannelIterType ComM_FrShutdownIterType;

/**   \brief  type used to iterate ComM_LastStateChange */
typedef ComM_UserIterType ComM_LastStateChangeIterType;

/**   \brief  type used to iterate ComM_MinFullComModeTimer */
typedef ComM_ChannelIterType ComM_MinFullComModeTimerIterType;

/**   \brief  type used to iterate ComM_NmLightTimer */
typedef ComM_ChannelIterType ComM_NmLightTimerIterType;

/**   \brief  type used to iterate ComM_PncPSleepTimer */
typedef ComM_PncIterType ComM_PncPSleepTimerIterType;

/**   \brief  type used to iterate ComM_PncToChannelRoutingState */
typedef ComM_ChannelIterType ComM_PncToChannelRoutingStateIterType;

/**   \brief  type used to iterate ComM_ResetRequired */
typedef ComM_ChannelIterType ComM_ResetRequiredIterType;

/**   \brief  type used to iterate ComM_SimulatedSmMode */
typedef ComM_ChannelIterType ComM_SimulatedSmModeIterType;

/**   \brief  type used to iterate ComM_StateChange */
typedef ComM_ChannelIterType ComM_StateChangeIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCValueTypes  ComM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for ComM_BusSleepModeIndicated */
typedef boolean ComM_BusSleepModeIndicatedType;

/**   \brief  value based type definition for ComM_BusTypeFr */
typedef boolean ComM_BusTypeFrType;

/**   \brief  value based type definition for ComM_GwTypeOfChannel */
typedef uint8 ComM_GwTypeOfChannelType;

/**   \brief  value based type definition for ComM_InhibitionInitValueOfChannel */
typedef uint8 ComM_InhibitionInitValueOfChannelType;

/**   \brief  value based type definition for ComM_InvalidHndOfChannel */
typedef boolean ComM_InvalidHndOfChannelType;

/**   \brief  value based type definition for ComM_J1939SupportOfChannel */
typedef boolean ComM_J1939SupportOfChannelType;

/**   \brief  value based type definition for ComM_MainFunctionNeedsSyncOfChannel */
typedef boolean ComM_MainFunctionNeedsSyncOfChannelType;

/**   \brief  value based type definition for ComM_ManagingChannelIdOfChannel */
typedef uint8 ComM_ManagingChannelIdOfChannelType;

/**   \brief  value based type definition for ComM_ManagingChannelOfChannel */
typedef boolean ComM_ManagingChannelOfChannelType;

/**   \brief  value based type definition for ComM_ManagingUserOfChannel */
typedef uint8 ComM_ManagingUserOfChannelType;

/**   \brief  value based type definition for ComM_MinFullComTimeOfChannel */
typedef uint8 ComM_MinFullComTimeOfChannelType;

/**   \brief  value based type definition for ComM_NmLightDurationOfChannel */
typedef uint8 ComM_NmLightDurationOfChannelType;

/**   \brief  value based type definition for ComM_NmLightSilentDurationOfChannel */
typedef uint8 ComM_NmLightSilentDurationOfChannelType;

/**   \brief  value based type definition for ComM_NmSupportOfChannel */
typedef boolean ComM_NmSupportOfChannelType;

/**   \brief  value based type definition for ComM_NmTypeOfChannel */
typedef uint8 ComM_NmTypeOfChannelType;

/**   \brief  value based type definition for ComM_PartitionConfigIdxOfChannel */
typedef uint8 ComM_PartitionConfigIdxOfChannelType;

/**   \brief  value based type definition for ComM_PassiveOrLinSlaveOfChannel */
typedef boolean ComM_PassiveOrLinSlaveOfChannelType;

/**   \brief  value based type definition for ComM_PncNmRequestOfChannel */
typedef boolean ComM_PncNmRequestOfChannelType;

/**   \brief  value based type definition for ComM_ResetAfterForcingNoCommOfChannel */
typedef boolean ComM_ResetAfterForcingNoCommOfChannelType;

/**   \brief  value based type definition for ComM_SilentSupportOfChannel */
typedef boolean ComM_SilentSupportOfChannelType;

/**   \brief  value based type definition for ComM_WakeupStateOfChannel */
typedef uint8 ComM_WakeupStateOfChannelType;

/**   \brief  value based type definition for ComM_InvalidHndOfChannelPb */
typedef boolean ComM_InvalidHndOfChannelPbType;

/**   \brief  value based type definition for ComM_PncLimitationEndIdxOfChannelPb */
typedef uint8 ComM_PncLimitationEndIdxOfChannelPbType;

/**   \brief  value based type definition for ComM_PncLimitationStartIdxOfChannelPb */
typedef uint8 ComM_PncLimitationStartIdxOfChannelPbType;

/**   \brief  value based type definition for ComM_PncLimitationUsedOfChannelPb */
typedef boolean ComM_PncLimitationUsedOfChannelPbType;

/**   \brief  value based type definition for ComM_PncPbIndEndIdxOfChannelPb */
typedef uint8 ComM_PncPbIndEndIdxOfChannelPbType;

/**   \brief  value based type definition for ComM_PncPbIndStartIdxOfChannelPb */
typedef uint8 ComM_PncPbIndStartIdxOfChannelPbType;

/**   \brief  value based type definition for ComM_PncPbIndUsedOfChannelPb */
typedef boolean ComM_PncPbIndUsedOfChannelPbType;

/**   \brief  value based type definition for ComM_UserReqFullComEndIdxOfChannelPb */
typedef uint8 ComM_UserReqFullComEndIdxOfChannelPbType;

/**   \brief  value based type definition for ComM_UserReqFullComStartIdxOfChannelPb */
typedef uint8 ComM_UserReqFullComStartIdxOfChannelPbType;

/**   \brief  value based type definition for ComM_UserReqFullComUsedOfChannelPb */
typedef boolean ComM_UserReqFullComUsedOfChannelPbType;

/**   \brief  value based type definition for ComM_ComAllowed */
typedef boolean ComM_ComAllowedType;

/**   \brief  value based type definition for ComM_CoordPncWithGwPassiveAndManagedChannels */
typedef boolean ComM_CoordPncWithGwPassiveAndManagedChannelsType;

/**   \brief  value based type definition for ComM_DcmIndication */
typedef boolean ComM_DcmIndicationType;

/**   \brief  value based type definition for ComM_DcmRequestActive */
typedef boolean ComM_DcmRequestActiveType;

/**   \brief  value based type definition for ComM_EcuMWakeUpIndicated */
typedef boolean ComM_EcuMWakeUpIndicatedType;

/**   \brief  value based type definition for ComM_ExtendedRamCheck */
typedef boolean ComM_ExtendedRamCheckType;

/**   \brief  value based type definition for ComM_FinalMagicNumber */
typedef uint16 ComM_FinalMagicNumberType;

/**   \brief  value based type definition for ComM_ForwardNmGateway */
typedef boolean ComM_ForwardNmGatewayType;

/**   \brief  value based type definition for ComM_ForwardSynchronizedPncShutdownIndicated */
typedef boolean ComM_ForwardSynchronizedPncShutdownIndicatedType;

/**   \brief  value based type definition for ComM_FrShutdown */
typedef boolean ComM_FrShutdownType;

/**   \brief  value based type definition for ComM_FullComRequesters */
typedef uint16 ComM_FullComRequestersType;

/**   \brief  value based type definition for ComM_FullCommRequestNotif */
typedef boolean ComM_FullCommRequestNotifType;

/**   \brief  value based type definition for ComM_FullNmTypeOfChannel */
typedef boolean ComM_FullNmTypeOfChannelType;

/**   \brief  value based type definition for ComM_InitDataHashCode */
typedef sint32 ComM_InitDataHashCodeType;

/**   \brief  value based type definition for ComM_KeepAwakeChannels */
typedef boolean ComM_KeepAwakeChannelsType;

/**   \brief  value based type definition for ComM_LightNmTypeOfChannel */
typedef boolean ComM_LightNmTypeOfChannelType;

/**   \brief  value based type definition for ComM_LinslaveNmTypeOfChannel */
typedef boolean ComM_LinslaveNmTypeOfChannelType;

/**   \brief  value based type definition for ComM_MinFullComModeTimer */
typedef uint16 ComM_MinFullComModeTimerType;

/**   \brief  value based type definition for ComM_ModeLimitation */
typedef boolean ComM_ModeLimitationType;

/**   \brief  value based type definition for ComM_NmGwExt */
typedef boolean ComM_NmGwExtType;

/**   \brief  value based type definition for ComM_NmLightTimer */
typedef uint16 ComM_NmLightTimerType;

/**   \brief  value based type definition for ComM_NmStartUpIndicated */
typedef boolean ComM_NmStartUpIndicatedType;

/**   \brief  value based type definition for ComM_NoneNmTypeOfChannel */
typedef boolean ComM_NoneNmTypeOfChannelType;

/**   \brief  value based type definition for ComM_NotifyPncStateChange */
typedef boolean ComM_NotifyPncStateChangeType;

/**   \brief  value based type definition for ComM_NvMStoreReq */
typedef boolean ComM_NvMStoreReqType;

/**   \brief  value based type definition for ComM_OnlyNoneNmTypeOfChannel */
typedef boolean ComM_OnlyNoneNmTypeOfChannelType;

/**   \brief  value based type definition for ComM_PartitionSNVOfPartitionIdentifiers */
typedef uint32 ComM_PartitionSNVOfPartitionIdentifiersType;

/**   \brief  value based type definition for ComM_ClearMaskOfPnc */
typedef uint8 ComM_ClearMaskOfPncType;

/**   \brief  value based type definition for ComM_CoordinatedOfPnc */
typedef boolean ComM_CoordinatedOfPncType;

/**   \brief  value based type definition for ComM_IntermediatePncCoordinatorOfPnc */
typedef boolean ComM_IntermediatePncCoordinatorOfPncType;

/**   \brief  value based type definition for ComM_PncIdOfPnc */
typedef uint8 ComM_PncIdOfPncType;

/**   \brief  value based type definition for ComM_SetMaskOfPnc */
typedef uint8 ComM_SetMaskOfPncType;

/**   \brief  value based type definition for ComM_SystemUserOfPnc */
typedef uint8 ComM_SystemUserOfPncType;

/**   \brief  value based type definition for ComM_TopLevelPncCoordinatorOfPnc */
typedef boolean ComM_TopLevelPncCoordinatorOfPncType;

/**   \brief  value based type definition for ComM_WakeupEnabledOfPnc */
typedef boolean ComM_WakeupEnabledOfPncType;

/**   \brief  value based type definition for ComM_Pnc0VectorAvoidance */
typedef boolean ComM_Pnc0VectorAvoidanceType;

/**   \brief  value based type definition for ComM_PncChannelMapping */
typedef uint8 ComM_PncChannelMappingType;

/**   \brief  value based type definition for ComM_PncCheckEnabledAtRuntime */
typedef boolean ComM_PncCheckEnabledAtRuntimeType;

/**   \brief  value based type definition for ComM_PncEiraRx */
typedef boolean ComM_PncEiraRxType;

/**   \brief  value based type definition for ComM_PncEiraRxCount */
typedef uint8 ComM_PncEiraRxCountType;

/**   \brief  value based type definition for ComM_PncExtendedFunctionality */
typedef boolean ComM_PncExtendedFunctionalityType;

/**   \brief  value based type definition for ComM_PncGwTypeActive */
typedef boolean ComM_PncGwTypeActiveType;

/**   \brief  value based type definition for ComM_PncGwTypeNone */
typedef boolean ComM_PncGwTypeNoneType;

/**   \brief  value based type definition for ComM_PncGwTypePassive */
typedef boolean ComM_PncGwTypePassiveType;

/**   \brief  value based type definition for ComM_PncLimitation */
typedef uint8 ComM_PncLimitationType;

/**   \brief  value based type definition for ComM_PncPSleepTimer */
typedef uint16 ComM_PncPSleepTimerType;

/**   \brief  value based type definition for ComM_PncChannelMappingEndIdxOfPncPb */
typedef uint8 ComM_PncChannelMappingEndIdxOfPncPbType;

/**   \brief  value based type definition for ComM_PncChannelMappingStartIdxOfPncPb */
typedef uint8 ComM_PncChannelMappingStartIdxOfPncPbType;

/**   \brief  value based type definition for ComM_PncChannelMappingUsedOfPncPb */
typedef boolean ComM_PncChannelMappingUsedOfPncPbType;

/**   \brief  value based type definition for ComM_PncSignalIndEndIdxOfPncPb */
typedef uint8 ComM_PncSignalIndEndIdxOfPncPbType;

/**   \brief  value based type definition for ComM_PncSignalIndStartIdxOfPncPb */
typedef uint8 ComM_PncSignalIndStartIdxOfPncPbType;

/**   \brief  value based type definition for ComM_PncSignalIndUsedOfPncPb */
typedef boolean ComM_PncSignalIndUsedOfPncPbType;

/**   \brief  value based type definition for ComM_SignalByteIndexOfPncPb */
typedef uint8 ComM_SignalByteIndexOfPncPbType;

/**   \brief  value based type definition for ComM_UserReqPncFullComEndIdxOfPncPb */
typedef uint8 ComM_UserReqPncFullComEndIdxOfPncPbType;

/**   \brief  value based type definition for ComM_UserReqPncFullComStartIdxOfPncPb */
typedef uint8 ComM_UserReqPncFullComStartIdxOfPncPbType;

/**   \brief  value based type definition for ComM_PncPbInd */
typedef uint8 ComM_PncPbIndType;

/**   \brief  value based type definition for ComM_BusTypeIdOfPncSignal */
typedef uint8 ComM_BusTypeIdOfPncSignalType;

/**   \brief  value based type definition for ComM_ChannelIdxOfPncSignal */
typedef uint8 ComM_ChannelIdxOfPncSignalType;

/**   \brief  value based type definition for ComM_ChannelUsedOfPncSignal */
typedef boolean ComM_ChannelUsedOfPncSignalType;

/**   \brief  value based type definition for ComM_TypeOfPncSignal */
typedef uint8 ComM_TypeOfPncSignalType;

/**   \brief  value based type definition for ComM_PncSignalInd */
typedef uint8 ComM_PncSignalIndType;

/**   \brief  value based type definition for ComM_PncSignalValues */
typedef uint8 ComM_PncSignalValuesType;

/**   \brief  value based type definition for ComM_PncToChannelRoutingState */
typedef uint8 ComM_PncToChannelRoutingStateType;

/**   \brief  value based type definition for ComM_PncWithoutChannels */
typedef boolean ComM_PncWithoutChannelsType;

/**   \brief  value based type definition for ComM_PostInitialized */
typedef boolean ComM_PostInitializedType;

/**   \brief  value based type definition for ComM_ResetRequired */
typedef boolean ComM_ResetRequiredType;

/**   \brief  value based type definition for ComM_SimulatedSmMode */
typedef uint8 ComM_SimulatedSmModeType;

/**   \brief  value based type definition for ComM_StateChange */
typedef uint8 ComM_StateChangeType;

/**   \brief  value based type definition for ComM_SynchronousWakeUp */
typedef boolean ComM_SynchronousWakeUpType;

/**   \brief  value based type definition for ComM_PartitionConfigIdxOfUser */
typedef uint8 ComM_PartitionConfigIdxOfUserType;

/**   \brief  value based type definition for ComM_PncUserOfUser */
typedef boolean ComM_PncUserOfUserType;

/**   \brief  value based type definition for ComM_UserByteMaskEndIdxOfUser */
typedef uint8 ComM_UserByteMaskEndIdxOfUserType;

/**   \brief  value based type definition for ComM_UserByteMaskStartIdxOfUser */
typedef uint8 ComM_UserByteMaskStartIdxOfUserType;

/**   \brief  value based type definition for ComM_UserByteMaskUsedOfUser */
typedef boolean ComM_UserByteMaskUsedOfUserType;

/**   \brief  value based type definition for ComM_UserPncByteMaskEndIdxOfUser */
typedef uint8 ComM_UserPncByteMaskEndIdxOfUserType;

/**   \brief  value based type definition for ComM_UserPncByteMaskLengthOfUser */
typedef uint8 ComM_UserPncByteMaskLengthOfUserType;

/**   \brief  value based type definition for ComM_UserPncByteMaskStartIdxOfUser */
typedef uint8 ComM_UserPncByteMaskStartIdxOfUserType;

/**   \brief  value based type definition for ComM_UserPncByteMaskUsedOfUser */
typedef boolean ComM_UserPncByteMaskUsedOfUserType;

/**   \brief  value based type definition for ComM_ChannelOfUserByteMask */
typedef uint8 ComM_ChannelOfUserByteMaskType;

/**   \brief  value based type definition for ComM_ClearMaskOfUserByteMask */
typedef uint8 ComM_ClearMaskOfUserByteMaskType;

/**   \brief  value based type definition for ComM_SetMaskOfUserByteMask */
typedef uint8 ComM_SetMaskOfUserByteMaskType;

/**   \brief  value based type definition for ComM_UserReqFullComIdxOfUserByteMask */
typedef uint8 ComM_UserReqFullComIdxOfUserByteMaskType;

/**   \brief  value based type definition for ComM_UserModeNotificationOnlyForPncUsers */
typedef boolean ComM_UserModeNotificationOnlyForPncUsersType;

/**   \brief  value based type definition for ComM_ClearMaskOfUserPncByteMask */
typedef uint8 ComM_ClearMaskOfUserPncByteMaskType;

/**   \brief  value based type definition for ComM_PncIDOfUserPncByteMask */
typedef uint8 ComM_PncIDOfUserPncByteMaskType;

/**   \brief  value based type definition for ComM_PncIdxOfUserPncByteMask */
typedef uint8 ComM_PncIdxOfUserPncByteMaskType;

/**   \brief  value based type definition for ComM_SetMaskOfUserPncByteMask */
typedef uint8 ComM_SetMaskOfUserPncByteMaskType;

/**   \brief  value based type definition for ComM_UserReqPncFullComIdxOfUserPncByteMask */
typedef uint8 ComM_UserReqPncFullComIdxOfUserPncByteMaskType;

/**   \brief  value based type definition for ComM_UserReqFullCom */
typedef uint8 ComM_UserReqFullComType;

/**   \brief  value based type definition for ComM_UserReqPncFullCom */
typedef uint8 ComM_UserReqPncFullComType;

/**   \brief  value based type definition for ComM_UserWithSinglePnc */
typedef boolean ComM_UserWithSinglePncType;

/**   \brief  value based type definition for ComM_WakeupInhibition */
typedef boolean ComM_WakeupInhibitionType;

/** 
  \}
*/ 


/* PRQA S 0639, 0779 POSTBUILDGLOBALDATATYPES */ /* MD_MSR_1.1_639, MD_MSR_Rule5.2_0779 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComMPBIterableTypes  ComM Iterable Types (POST_BUILD)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate ComM_PBPartitionConfig */
typedef uint16_least ComM_PBPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPBValueTypes  ComM Value Types (POST_BUILD)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for ComM_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 ComM_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for ComM_LTConfigIdxOfPBConfig */
typedef uint8 ComM_LTConfigIdxOfPBConfigType;

/**   \brief  value based type definition for ComM_PCConfigIdxOfPBConfig */
typedef uint8 ComM_PCConfigIdxOfPBConfigType;

/** 
  \}
*/ 


/* PRQA L:POSTBUILDGLOBALDATATYPES */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComMPCStructTypes  ComM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in ComM_Channel */
typedef struct sComM_ChannelType
{
  ComM_BusType BusTypeOfChannel;  /**< The channel bus type */
  GetCurrentBusSMModeApiType GetCurrentBusSMModeApiOfChannel;  /**< Query the current communication mode from the corresponding BusSM */
  RequestBusSMModeApiType RequestBusSMModeApiOfChannel;  /**< Request the communication mode from the corresponding BusSM */
} ComM_ChannelType;

/**   \brief  type used in ComM_ChannelPb */
typedef struct sComM_ChannelPbType
{
  ComM_UserReqFullComEndIdxOfChannelPbType UserReqFullComEndIdxOfChannelPb;  /**< the end index of the 0:n relation pointing to ComM_UserReqFullCom */
  ComM_UserReqFullComStartIdxOfChannelPbType UserReqFullComStartIdxOfChannelPb;  /**< the start index of the 0:n relation pointing to ComM_UserReqFullCom */
} ComM_ChannelPbType;

/**   \brief  type used in ComM_EiraTxSignalIndirection */
typedef struct sComM_EiraTxSignalIndirectionType
{
  uint8 ComM_EiraTxSignalIndirectionNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} ComM_EiraTxSignalIndirectionType;

/**   \brief  type used in ComM_PartitionIdentifiers */
typedef struct sComM_PartitionIdentifiersType
{
  ComM_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
  ComM_PCPartitionConfigIdxOfPartitionIdentifiersType PCPartitionConfigIdxOfPartitionIdentifiers;  /**< the index of the 1:1 relation pointing to ComM_PCPartitionConfig */
} ComM_PartitionIdentifiersType;

/**   \brief  type used in ComM_Pnc */
typedef struct sComM_PncType
{
  uint8 ComM_PncNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} ComM_PncType;

/**   \brief  type used in ComM_PncPb */
typedef struct sComM_PncPbType
{
  uint8 ComM_PncPbNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} ComM_PncPbType;

/**   \brief  type used in ComM_PncSignal */
typedef struct sComM_PncSignalType
{
  uint8 ComM_PncSignalNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} ComM_PncSignalType;

/**   \brief  type used in ComM_User */
typedef struct sComM_UserType
{
  ComM_PncUserOfUserType PncUserOfUser;  /**< decides if a user is a partial network user or a direct channel user */
  ComM_UserByteMaskEndIdxOfUserType UserByteMaskEndIdxOfUser;  /**< the end index of the 0:n relation pointing to ComM_UserByteMask */
  ComM_UserByteMaskStartIdxOfUserType UserByteMaskStartIdxOfUser;  /**< the start index of the 0:n relation pointing to ComM_UserByteMask */
} ComM_UserType;

/**   \brief  type used in ComM_UserByteMask */
typedef struct sComM_UserByteMaskType
{
  ComM_ChannelOfUserByteMaskType ChannelOfUserByteMask;  /**< ID of the channel which is requested by this entry. */
  ComM_UserReqFullComIdxOfUserByteMaskType UserReqFullComIdxOfUserByteMask;  /**< the index of the 1:1 relation pointing to ComM_UserReqFullCom */
} ComM_UserByteMaskType;

/**   \brief  type used in ComM_UserPncByteMask */
typedef struct sComM_UserPncByteMaskType
{
  uint8 ComM_UserPncByteMaskNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} ComM_UserPncByteMaskType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCSymbolicStructTypes  ComM Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style for debugging purposes. These types are not used in the implementation!.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to ComM_ActiveComMode for debugging purposes in the partition context  */
typedef struct ComM_ActiveComModeStructSTag
{
  ComM_StateType ComMChannel_0;
  ComM_StateType ComMChannel_1;
  ComM_StateType ComMChannel_2;
} ComM_ActiveComModeStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_BusComModeReq for debugging purposes in the partition context  */
typedef struct ComM_BusComModeReqStructSTag
{
  ComM_StateType ComMChannel_0;
  ComM_StateType ComMChannel_1;
  ComM_StateType ComMChannel_2;
} ComM_BusComModeReqStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_BusComModeReqFrShutdown for debugging purposes in the partition context  */
typedef struct ComM_BusComModeReqFrShutdownStructSTag
{
  ComM_StateType ComMChannel_0;
  ComM_StateType ComMChannel_1;
  ComM_StateType ComMChannel_2;
} ComM_BusComModeReqFrShutdownStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_BusSleepModeIndicated for debugging purposes in the partition context  */
typedef struct ComM_BusSleepModeIndicatedStructSTag
{
  ComM_BusSleepModeIndicatedType ComMChannel_0;
  ComM_BusSleepModeIndicatedType ComMChannel_1;
  ComM_BusSleepModeIndicatedType ComMChannel_2;
} ComM_BusSleepModeIndicatedStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_BusSmState for debugging purposes in the partition context  */
typedef struct ComM_BusSmStateStructSTag
{
  ComM_ModeType ComMChannel_0;
  ComM_ModeType ComMChannel_1;
  ComM_ModeType ComMChannel_2;
} ComM_BusSmStateStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_ComAllowed for debugging purposes in the partition context  */
typedef struct ComM_ComAllowedStructSTag
{
  ComM_ComAllowedType ComMChannel_0;
  ComM_ComAllowedType ComMChannel_1;
  ComM_ComAllowedType ComMChannel_2;
} ComM_ComAllowedStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_DcmRequestActive for debugging purposes in the partition context  */
typedef struct ComM_DcmRequestActiveStructSTag
{
  ComM_DcmRequestActiveType ComMChannel_0;
  ComM_DcmRequestActiveType ComMChannel_1;
  ComM_DcmRequestActiveType ComMChannel_2;
} ComM_DcmRequestActiveStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_ForwardNmGateway for debugging purposes in the partition context  */
typedef struct ComM_ForwardNmGatewayStructSTag
{
  ComM_ForwardNmGatewayType ComMChannel_0;
  ComM_ForwardNmGatewayType ComMChannel_1;
  ComM_ForwardNmGatewayType ComMChannel_2;
} ComM_ForwardNmGatewayStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_FrShutdown for debugging purposes in the partition context  */
typedef struct ComM_FrShutdownStructSTag
{
  ComM_FrShutdownType ComMChannel_0;
  ComM_FrShutdownType ComMChannel_1;
  ComM_FrShutdownType ComMChannel_2;
} ComM_FrShutdownStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_MinFullComModeTimer for debugging purposes in the partition context  */
typedef struct ComM_MinFullComModeTimerStructSTag
{
  ComM_MinFullComModeTimerType ComMChannel_0;
  ComM_MinFullComModeTimerType ComMChannel_1;
  ComM_MinFullComModeTimerType ComMChannel_2;
} ComM_MinFullComModeTimerStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_NmLightTimer for debugging purposes in the partition context  */
typedef struct ComM_NmLightTimerStructSTag
{
  ComM_NmLightTimerType ComMChannel_0;
  ComM_NmLightTimerType ComMChannel_1;
  ComM_NmLightTimerType ComMChannel_2;
} ComM_NmLightTimerStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_PncToChannelRoutingState for debugging purposes in the partition context  */
typedef struct ComM_PncToChannelRoutingStateStructSTag
{
  ComM_PncToChannelRoutingStateType ComMChannel_0;
  ComM_PncToChannelRoutingStateType ComMChannel_1;
  ComM_PncToChannelRoutingStateType ComMChannel_2;
} ComM_PncToChannelRoutingStateStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_ResetRequired for debugging purposes in the partition context  */
typedef struct ComM_ResetRequiredStructSTag
{
  ComM_ResetRequiredType ComMChannel_0;
  ComM_ResetRequiredType ComMChannel_1;
  ComM_ResetRequiredType ComMChannel_2;
} ComM_ResetRequiredStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_SimulatedSmMode for debugging purposes in the partition context  */
typedef struct ComM_SimulatedSmModeStructSTag
{
  ComM_SimulatedSmModeType ComMChannel_0;
  ComM_SimulatedSmModeType ComMChannel_1;
  ComM_SimulatedSmModeType ComMChannel_2;
} ComM_SimulatedSmModeStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_StateChange for debugging purposes in the partition context  */
typedef struct ComM_StateChangeStructSTag
{
  ComM_StateChangeType ComMChannel_0;
  ComM_StateChangeType ComMChannel_1;
  ComM_StateChangeType ComMChannel_2;
} ComM_StateChangeStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCUnionIndexAndSymbolTypes  ComM Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style. This type is for debugging purposes, in the implementation the access over the real array type with raw is always used.
  \{
*/ 
/**   \brief  type to access ComM_ActiveComMode in an index and symbol based style for debugging purposes */
typedef union ComM_ActiveComModeUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_StateType raw[3];
  ComM_ActiveComModeStructSType str;
} ComM_ActiveComModeUType;

/**   \brief  type to access ComM_BusComModeReq in an index and symbol based style for debugging purposes */
typedef union ComM_BusComModeReqUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_StateType raw[3];
  ComM_BusComModeReqStructSType str;
} ComM_BusComModeReqUType;

/**   \brief  type to access ComM_BusComModeReqFrShutdown in an index and symbol based style for debugging purposes */
typedef union ComM_BusComModeReqFrShutdownUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_StateType raw[3];
  ComM_BusComModeReqFrShutdownStructSType str;
} ComM_BusComModeReqFrShutdownUType;

/**   \brief  type to access ComM_BusSleepModeIndicated in an index and symbol based style for debugging purposes */
typedef union ComM_BusSleepModeIndicatedUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_BusSleepModeIndicatedType raw[3];
  ComM_BusSleepModeIndicatedStructSType str;
} ComM_BusSleepModeIndicatedUType;

/**   \brief  type to access ComM_BusSmState in an index and symbol based style for debugging purposes */
typedef union ComM_BusSmStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_ModeType raw[3];
  ComM_BusSmStateStructSType str;
} ComM_BusSmStateUType;

/**   \brief  type to access ComM_ComAllowed in an index and symbol based style for debugging purposes */
typedef union ComM_ComAllowedUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_ComAllowedType raw[3];
  ComM_ComAllowedStructSType str;
} ComM_ComAllowedUType;

/**   \brief  type to access ComM_DcmRequestActive in an index and symbol based style for debugging purposes */
typedef union ComM_DcmRequestActiveUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_DcmRequestActiveType raw[3];
  ComM_DcmRequestActiveStructSType str;
} ComM_DcmRequestActiveUType;

/**   \brief  type to access ComM_ForwardNmGateway in an index and symbol based style for debugging purposes */
typedef union ComM_ForwardNmGatewayUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_ForwardNmGatewayType raw[3];
  ComM_ForwardNmGatewayStructSType str;
} ComM_ForwardNmGatewayUType;

/**   \brief  type to access ComM_FrShutdown in an index and symbol based style for debugging purposes */
typedef union ComM_FrShutdownUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_FrShutdownType raw[3];
  ComM_FrShutdownStructSType str;
} ComM_FrShutdownUType;

/**   \brief  type to access ComM_MinFullComModeTimer in an index and symbol based style for debugging purposes */
typedef union ComM_MinFullComModeTimerUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_MinFullComModeTimerType raw[3];
  ComM_MinFullComModeTimerStructSType str;
} ComM_MinFullComModeTimerUType;

/**   \brief  type to access ComM_NmLightTimer in an index and symbol based style for debugging purposes */
typedef union ComM_NmLightTimerUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_NmLightTimerType raw[3];
  ComM_NmLightTimerStructSType str;
} ComM_NmLightTimerUType;

/**   \brief  type to access ComM_PncToChannelRoutingState in an index and symbol based style for debugging purposes */
typedef union ComM_PncToChannelRoutingStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_PncToChannelRoutingStateType raw[3];
  ComM_PncToChannelRoutingStateStructSType str;
} ComM_PncToChannelRoutingStateUType;

/**   \brief  type to access ComM_ResetRequired in an index and symbol based style for debugging purposes */
typedef union ComM_ResetRequiredUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_ResetRequiredType raw[3];
  ComM_ResetRequiredStructSType str;
} ComM_ResetRequiredUType;

/**   \brief  type to access ComM_SimulatedSmMode in an index and symbol based style for debugging purposes */
typedef union ComM_SimulatedSmModeUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_SimulatedSmModeType raw[3];
  ComM_SimulatedSmModeStructSType str;
} ComM_SimulatedSmModeUType;

/**   \brief  type to access ComM_StateChange in an index and symbol based style for debugging purposes */
typedef union ComM_StateChangeUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_StateChangeType raw[3];
  ComM_StateChangeStructSType str;
} ComM_StateChangeUType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCRootPointerTypes  ComM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to ComM_ActiveComMode */
typedef P2VAR(ComM_StateType, TYPEDEF, COMM_VAR_NO_INIT) ComM_ActiveComModePtrType;

/**   \brief  type used to point to ComM_ActivePncComMode */
typedef P2VAR(ComM_PncModeType, TYPEDEF, COMM_VAR_NO_INIT) ComM_ActivePncComModePtrType;

/**   \brief  type used to point to ComM_BusComModeReq */
typedef P2VAR(ComM_StateType, TYPEDEF, COMM_VAR_NO_INIT) ComM_BusComModeReqPtrType;

/**   \brief  type used to point to ComM_BusComModeReqFrShutdown */
typedef P2VAR(ComM_StateType, TYPEDEF, COMM_VAR_NO_INIT) ComM_BusComModeReqFrShutdownPtrType;

/**   \brief  type used to point to ComM_BusPncComModeReq */
typedef P2VAR(ComM_PncModeType, TYPEDEF, COMM_VAR_NO_INIT) ComM_BusPncComModeReqPtrType;

/**   \brief  type used to point to ComM_BusSleepModeIndicated */
typedef P2VAR(ComM_BusSleepModeIndicatedType, TYPEDEF, COMM_VAR_NO_INIT) ComM_BusSleepModeIndicatedPtrType;

/**   \brief  type used to point to ComM_BusSmState */
typedef P2VAR(ComM_ModeType, TYPEDEF, COMM_VAR_NO_INIT) ComM_BusSmStatePtrType;

/**   \brief  type used to point to ComM_BusTypeFr */
typedef P2CONST(ComM_BusTypeFrType, TYPEDEF, COMM_CONST) ComM_BusTypeFrPtrType;

/**   \brief  type used to point to ComM_Channel */
typedef P2CONST(ComM_ChannelType, TYPEDEF, COMM_CONST) ComM_ChannelPtrType;

/**   \brief  type used to point to ComM_ChannelPb */
typedef P2CONST(ComM_ChannelPbType, TYPEDEF, COMM_CONST) ComM_ChannelPbPtrType;

/**   \brief  type used to point to ComM_ComAllowed */
typedef P2VAR(ComM_ComAllowedType, TYPEDEF, COMM_VAR_NO_INIT) ComM_ComAllowedPtrType;

/**   \brief  type used to point to ComM_CoordPncWithGwPassiveAndManagedChannels */
typedef P2CONST(ComM_CoordPncWithGwPassiveAndManagedChannelsType, TYPEDEF, COMM_CONST) ComM_CoordPncWithGwPassiveAndManagedChannelsPtrType;

/**   \brief  type used to point to ComM_DcmIndication */
typedef P2CONST(ComM_DcmIndicationType, TYPEDEF, COMM_CONST) ComM_DcmIndicationPtrType;

/**   \brief  type used to point to ComM_DcmRequestActive */
typedef P2VAR(ComM_DcmRequestActiveType, TYPEDEF, COMM_VAR_NO_INIT) ComM_DcmRequestActivePtrType;

/**   \brief  type used to point to ComM_EcuMWakeUpIndicated */
typedef P2VAR(volatile ComM_EcuMWakeUpIndicatedType, TYPEDEF, COMM_VAR_NO_INIT) ComM_EcuMWakeUpIndicatedPtrType;

/**   \brief  type used to point to ComM_EiraTxSignalIndirection */
typedef P2CONST(ComM_EiraTxSignalIndirectionType, TYPEDEF, COMM_CONST) ComM_EiraTxSignalIndirectionPtrType;

/**   \brief  type used to point to ComM_ExtendedRamCheck */
typedef P2CONST(ComM_ExtendedRamCheckType, TYPEDEF, COMM_CONST) ComM_ExtendedRamCheckPtrType;

/**   \brief  type used to point to ComM_ForwardNmGateway */
typedef P2VAR(ComM_ForwardNmGatewayType, TYPEDEF, COMM_VAR_NO_INIT) ComM_ForwardNmGatewayPtrType;

/**   \brief  type used to point to ComM_ForwardSynchronizedPncShutdownIndicated */
typedef P2VAR(ComM_ForwardSynchronizedPncShutdownIndicatedType, TYPEDEF, COMM_VAR_NO_INIT) ComM_ForwardSynchronizedPncShutdownIndicatedPtrType;

/**   \brief  type used to point to ComM_FrShutdown */
typedef P2VAR(ComM_FrShutdownType, TYPEDEF, COMM_VAR_NO_INIT) ComM_FrShutdownPtrType;

/**   \brief  type used to point to ComM_FullComRequesters */
typedef P2VAR(ComM_FullComRequestersType, TYPEDEF, COMM_VAR_NO_INIT) ComM_FullComRequestersPtrType;

/**   \brief  type used to point to ComM_FullCommRequestNotif */
typedef P2CONST(ComM_FullCommRequestNotifType, TYPEDEF, COMM_CONST) ComM_FullCommRequestNotifPtrType;

/**   \brief  type used to point to ComM_FullNmTypeOfChannel */
typedef P2CONST(ComM_FullNmTypeOfChannelType, TYPEDEF, COMM_CONST) ComM_FullNmTypeOfChannelPtrType;

/**   \brief  type used to point to ComM_Inhibition */
typedef P2VAR(ComM_InhibitionType, TYPEDEF, COMM_NVM_DATA_NO_INIT) ComM_InhibitionPtrType;

/**   \brief  type used to point to ComM_InitStatus */
typedef P2VAR(ComM_InitStatusType, TYPEDEF, COMM_VAR_NO_INIT) ComM_InitStatusPtrType;

/**   \brief  type used to point to ComM_KeepAwakeChannels */
typedef P2CONST(ComM_KeepAwakeChannelsType, TYPEDEF, COMM_CONST) ComM_KeepAwakeChannelsPtrType;

/**   \brief  type used to point to ComM_LastStateChange */
typedef P2VAR(ComM_ModeType, TYPEDEF, COMM_VAR_NO_INIT) ComM_LastStateChangePtrType;

/**   \brief  type used to point to ComM_LightNmTypeOfChannel */
typedef P2CONST(ComM_LightNmTypeOfChannelType, TYPEDEF, COMM_CONST) ComM_LightNmTypeOfChannelPtrType;

/**   \brief  type used to point to ComM_LinslaveNmTypeOfChannel */
typedef P2CONST(ComM_LinslaveNmTypeOfChannelType, TYPEDEF, COMM_CONST) ComM_LinslaveNmTypeOfChannelPtrType;

/**   \brief  type used to point to ComM_MinFullComModeTimer */
typedef P2VAR(ComM_MinFullComModeTimerType, TYPEDEF, COMM_VAR_NO_INIT) ComM_MinFullComModeTimerPtrType;

/**   \brief  type used to point to ComM_ModeLimitation */
typedef P2CONST(ComM_ModeLimitationType, TYPEDEF, COMM_CONST) ComM_ModeLimitationPtrType;

/**   \brief  type used to point to ComM_NmGwExt */
typedef P2CONST(ComM_NmGwExtType, TYPEDEF, COMM_CONST) ComM_NmGwExtPtrType;

/**   \brief  type used to point to ComM_NmLightTimer */
typedef P2VAR(ComM_NmLightTimerType, TYPEDEF, COMM_VAR_NO_INIT) ComM_NmLightTimerPtrType;

/**   \brief  type used to point to ComM_NmStartUpIndicated */
typedef P2VAR(volatile ComM_NmStartUpIndicatedType, TYPEDEF, COMM_VAR_NO_INIT) ComM_NmStartUpIndicatedPtrType;

/**   \brief  type used to point to ComM_NoneNmTypeOfChannel */
typedef P2CONST(ComM_NoneNmTypeOfChannelType, TYPEDEF, COMM_CONST) ComM_NoneNmTypeOfChannelPtrType;

/**   \brief  type used to point to ComM_NotifyPncStateChange */
typedef P2VAR(ComM_NotifyPncStateChangeType, TYPEDEF, COMM_VAR_NO_INIT) ComM_NotifyPncStateChangePtrType;

/**   \brief  type used to point to ComM_NvMStoreReq */
typedef P2VAR(ComM_NvMStoreReqType, TYPEDEF, COMM_VAR_NO_INIT) ComM_NvMStoreReqPtrType;

/**   \brief  type used to point to ComM_OnlyNoneNmTypeOfChannel */
typedef P2CONST(ComM_OnlyNoneNmTypeOfChannelType, TYPEDEF, COMM_CONST) ComM_OnlyNoneNmTypeOfChannelPtrType;

/**   \brief  type used to point to ComM_PartitionIdentifiers */
typedef P2CONST(ComM_PartitionIdentifiersType, TYPEDEF, COMM_CONST) ComM_PartitionIdentifiersPtrType;

/**   \brief  type used to point to ComM_Pnc */
typedef P2CONST(ComM_PncType, TYPEDEF, COMM_CONST) ComM_PncPtrType;

/**   \brief  type used to point to ComM_Pnc0VectorAvoidance */
typedef P2CONST(ComM_Pnc0VectorAvoidanceType, TYPEDEF, COMM_CONST) ComM_Pnc0VectorAvoidancePtrType;

/**   \brief  type used to point to ComM_PncChannelMapping */
typedef P2CONST(ComM_PncChannelMappingType, TYPEDEF, COMM_CONST) ComM_PncChannelMappingPtrType;

/**   \brief  type used to point to ComM_PncCheckEnabledAtRuntime */
typedef P2CONST(ComM_PncCheckEnabledAtRuntimeType, TYPEDEF, COMM_CONST) ComM_PncCheckEnabledAtRuntimePtrType;

/**   \brief  type used to point to ComM_PncEiraRx */
typedef P2CONST(ComM_PncEiraRxType, TYPEDEF, COMM_CONST) ComM_PncEiraRxPtrType;

/**   \brief  type used to point to ComM_PncExtendedFunctionality */
typedef P2CONST(ComM_PncExtendedFunctionalityType, TYPEDEF, COMM_CONST) ComM_PncExtendedFunctionalityPtrType;

/**   \brief  type used to point to ComM_PncGwTypeActive */
typedef P2CONST(ComM_PncGwTypeActiveType, TYPEDEF, COMM_CONST) ComM_PncGwTypeActivePtrType;

/**   \brief  type used to point to ComM_PncGwTypeNone */
typedef P2CONST(ComM_PncGwTypeNoneType, TYPEDEF, COMM_CONST) ComM_PncGwTypeNonePtrType;

/**   \brief  type used to point to ComM_PncGwTypePassive */
typedef P2CONST(ComM_PncGwTypePassiveType, TYPEDEF, COMM_CONST) ComM_PncGwTypePassivePtrType;

/**   \brief  type used to point to ComM_PncLimitation */
typedef P2VAR(ComM_PncLimitationType, TYPEDEF, COMM_VAR_NO_INIT) ComM_PncLimitationPtrType;

/**   \brief  type used to point to ComM_PncPSleepTimer */
typedef P2VAR(ComM_PncPSleepTimerType, TYPEDEF, COMM_VAR_NO_INIT) ComM_PncPSleepTimerPtrType;

/**   \brief  type used to point to ComM_PncPb */
typedef P2CONST(ComM_PncPbType, TYPEDEF, COMM_CONST) ComM_PncPbPtrType;

/**   \brief  type used to point to ComM_PncPbInd */
typedef P2CONST(ComM_PncPbIndType, TYPEDEF, COMM_CONST) ComM_PncPbIndPtrType;

/**   \brief  type used to point to ComM_PncSignal */
typedef P2CONST(ComM_PncSignalType, TYPEDEF, COMM_CONST) ComM_PncSignalPtrType;

/**   \brief  type used to point to ComM_PncSignalInd */
typedef P2CONST(ComM_PncSignalIndType, TYPEDEF, COMM_CONST) ComM_PncSignalIndPtrType;

/**   \brief  type used to point to ComM_PncSignalValues */
typedef P2VAR(ComM_PncSignalValuesType, TYPEDEF, COMM_VAR_NO_INIT) ComM_PncSignalValuesPtrType;

/**   \brief  type used to point to ComM_PncToChannelRoutingState */
typedef P2VAR(ComM_PncToChannelRoutingStateType, TYPEDEF, COMM_VAR_NO_INIT) ComM_PncToChannelRoutingStatePtrType;

/**   \brief  type used to point to ComM_PncWithoutChannels */
typedef P2CONST(ComM_PncWithoutChannelsType, TYPEDEF, COMM_CONST) ComM_PncWithoutChannelsPtrType;

/**   \brief  type used to point to ComM_PostInitialized */
typedef P2VAR(ComM_PostInitializedType, TYPEDEF, COMM_VAR_NO_INIT) ComM_PostInitializedPtrType;

/**   \brief  type used to point to ComM_ResetRequired */
typedef P2VAR(ComM_ResetRequiredType, TYPEDEF, COMM_VAR_NO_INIT) ComM_ResetRequiredPtrType;

/**   \brief  type used to point to ComM_SimulatedSmMode */
typedef P2VAR(ComM_SimulatedSmModeType, TYPEDEF, COMM_VAR_NO_INIT) ComM_SimulatedSmModePtrType;

/**   \brief  type used to point to ComM_StateChange */
typedef P2VAR(ComM_StateChangeType, TYPEDEF, COMM_VAR_NO_INIT) ComM_StateChangePtrType;

/**   \brief  type used to point to ComM_SynchronousWakeUp */
typedef P2CONST(ComM_SynchronousWakeUpType, TYPEDEF, COMM_CONST) ComM_SynchronousWakeUpPtrType;

/**   \brief  type used to point to ComM_User */
typedef P2CONST(ComM_UserType, TYPEDEF, COMM_CONST) ComM_UserPtrType;

/**   \brief  type used to point to ComM_UserByteMask */
typedef P2CONST(ComM_UserByteMaskType, TYPEDEF, COMM_CONST) ComM_UserByteMaskPtrType;

/**   \brief  type used to point to ComM_UserModeNotiFunc */
typedef P2CONST(ComM_StateNotiFuncPtrType, TYPEDEF, COMM_CONST) ComM_UserModeNotiFuncPtrType;

/**   \brief  type used to point to ComM_UserModeNotificationOnlyForPncUsers */
typedef P2CONST(ComM_UserModeNotificationOnlyForPncUsersType, TYPEDEF, COMM_CONST) ComM_UserModeNotificationOnlyForPncUsersPtrType;

/**   \brief  type used to point to ComM_UserPncByteMask */
typedef P2CONST(ComM_UserPncByteMaskType, TYPEDEF, COMM_CONST) ComM_UserPncByteMaskPtrType;

/**   \brief  type used to point to ComM_UserReqFullCom */
typedef P2VAR(ComM_UserReqFullComType, TYPEDEF, COMM_VAR_NO_INIT) ComM_UserReqFullComPtrType;

/**   \brief  type used to point to ComM_UserReqPncFullCom */
typedef P2VAR(ComM_UserReqPncFullComType, TYPEDEF, COMM_VAR_NO_INIT) ComM_UserReqPncFullComPtrType;

/**   \brief  type used to point to ComM_UserWithSinglePnc */
typedef P2CONST(ComM_UserWithSinglePncType, TYPEDEF, COMM_CONST) ComM_UserWithSinglePncPtrType;

/**   \brief  type used to point to ComM_WakeupInhibition */
typedef P2CONST(ComM_WakeupInhibitionType, TYPEDEF, COMM_CONST) ComM_WakeupInhibitionPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCPartitionRootPointer  ComM Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in ComM_PCPartitionConfig */
typedef struct sComM_PCPartitionConfigType
{
  uint8 ComM_PCPartitionConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} ComM_PCPartitionConfigType;

/**   \brief  type used to point to ComM_PCPartitionConfig */
typedef P2CONST(ComM_PCPartitionConfigType, TYPEDEF, COMM_CONST) ComM_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCRootValueTypes  ComM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in ComM_PCConfig */
typedef struct sComM_PCConfigType
{
  uint8 ComM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} ComM_PCConfigType;

typedef ComM_PCConfigType ComM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/* PRQA S 0639, 0779 POSTBUILDGLOBALDATATYPES */ /* MD_MSR_1.1_639, MD_MSR_Rule5.2_0779 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComMPBPartitionRootPointer  ComM Partition Root Pointer (POST_BUILD)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in ComM_PBPartitionConfig */
typedef struct sComM_PBPartitionConfigType
{
  uint8 ComM_PBPartitionConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} ComM_PBPartitionConfigType;

/**   \brief  type used to point to ComM_PBPartitionConfig */
typedef P2CONST(ComM_PBPartitionConfigType, TYPEDEF, COMM_PBCFG) ComM_PBPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPBRootValueTypes  ComM Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in ComM_PBConfig */
typedef struct sComM_PBConfigType
{
  uint8 ComM_PBConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} ComM_PBConfigType;

/** 
  \}
*/ 


/* PRQA L:POSTBUILDGLOBALDATATYPES */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/* PRQA S 3451 EXTERNDECLARATIONS */ /* MD_ComM_3451_3449 */
/* PRQA S 3449 EXTERNALDECLARATIONS_3449 */ /* MD_ComM_3451_3449 */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  ComM_Channel
**********************************************************************************************************************/
/** 
  \var    ComM_Channel
  \brief  Contains PreCompile configuration parameters of channels
  \details
  Element                   Description
  BusType                   The channel bus type
  GetCurrentBusSMModeApi    Query the current communication mode from the corresponding BusSM
  RequestBusSMModeApi       Request the communication mode from the corresponding BusSM
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelType, COMM_CONST) ComM_Channel[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelPb
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelPb
  \brief  Contains PostBuild configuration parameters of channels
  \details
  Element                   Description
  UserReqFullComEndIdx      the end index of the 0:n relation pointing to ComM_UserReqFullCom
  UserReqFullComStartIdx    the start index of the 0:n relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelPbType, COMM_CONST) ComM_ChannelPb[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    ComM_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to ComM_PCPartitionConfig
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PartitionIdentifiersType, COMM_CONST) ComM_PartitionIdentifiers[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_User
**********************************************************************************************************************/
/** 
  \var    ComM_User
  \brief  Information about ComM users
  \details
  Element                 Description
  PncUser                 decides if a user is a partial network user or a direct channel user
  UserByteMaskEndIdx      the end index of the 0:n relation pointing to ComM_UserByteMask
  UserByteMaskStartIdx    the start index of the 0:n relation pointing to ComM_UserByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserType, COMM_CONST) ComM_User[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserByteMask
**********************************************************************************************************************/
/** 
  \var    ComM_UserByteMask
  \brief  Each user has N entries in this array (N = # channels attached to this user, directly or through PNC). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqFullCom
  \details
  Element              Description
  Channel              ID of the channel which is requested by this entry.
  UserReqFullComIdx    the index of the 1:1 relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserByteMaskType, COMM_CONST) ComM_UserByteMask[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ActiveComMode
**********************************************************************************************************************/
/** 
  \var    ComM_ActiveComMode
  \brief  Current state of a channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ActiveComModeUType, COMM_VAR_NO_INIT) ComM_ActiveComMode;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusComModeReq
**********************************************************************************************************************/
/** 
  \var    ComM_BusComModeReq
  \brief  State requested externally (bus)
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_BusComModeReqUType, COMM_VAR_NO_INIT) ComM_BusComModeReq;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusSmState
**********************************************************************************************************************/
/** 
  \var    ComM_BusSmState
  \brief  Communication state of a channel provided by BusSM
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_BusSmStateUType, COMM_VAR_NO_INIT) ComM_BusSmState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ComAllowed
**********************************************************************************************************************/
/** 
  \var    ComM_ComAllowed
  \brief  Communication allowed status of a channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ComAllowedUType, COMM_VAR_NO_INIT) ComM_ComAllowed;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_DcmRequestActive
**********************************************************************************************************************/
/** 
  \var    ComM_DcmRequestActive
  \brief  Status of Dcm active diagnostic request, TRUE if requested, FALSE otherwise
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_DcmRequestActiveUType, COMM_VAR_NO_INIT) ComM_DcmRequestActive;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_EcuMWakeUpIndicated
**********************************************************************************************************************/
/** 
  \var    ComM_EcuMWakeUpIndicated
  \brief  Passive Wakeup indicated by EcuM (ComM_EcuM_WakeUpIndication()). TRUE if indicated, FALSE otherwise.
*/ 
#define COMM_START_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(ComM_EcuMWakeUpIndicatedType, COMM_VAR_NO_INIT) ComM_EcuMWakeUpIndicated[1];
#define COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_Inhibition
**********************************************************************************************************************/
/** 
  \var    ComM_Inhibition
  \brief  Status of mode limitation (inhibition)
*/ 
#define COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_InhibitionType, COMM_NVM_DATA_NO_INIT) ComM_Inhibition;
#define COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_InitStatus
**********************************************************************************************************************/
/** 
  \var    ComM_InitStatus
  \brief  Initialization state of ComM
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_InitStatusType, COMM_VAR_NO_INIT) ComM_InitStatus;
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_NmStartUpIndicated
**********************************************************************************************************************/
/** 
  \var    ComM_NmStartUpIndicated
  \brief  Passive Wakeup indicated by Nm (ComM_Nm_NetworkStartIndication() or ComM_Nm_RestartIndication()). TRUE if indicated, FALSE otherwise.
*/ 
#define COMM_START_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(ComM_NmStartUpIndicatedType, COMM_VAR_NO_INIT) ComM_NmStartUpIndicated[1];
#define COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PostInitialized
**********************************************************************************************************************/
/** 
  \var    ComM_PostInitialized
  \brief  Post-Initialized state
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_PostInitializedType, COMM_VAR_NO_INIT) ComM_PostInitialized[1];
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserReqFullCom
**********************************************************************************************************************/
/** 
  \var    ComM_UserReqFullCom
  \brief  RAM array used to store user requests for channels as bitmasks. Each channel 'owns' 1..n bytes in this array, depending on the number of users assigned to it.
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_UserReqFullComType, COMM_VAR_NO_INIT) ComM_UserReqFullCom[3];
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/* PRQA L:EXTERNALDECLARATIONS_3449 */
/* PRQA L:EXTERNDECLARATIONS */

 /**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/





#endif /* COMM_CFG_H */

