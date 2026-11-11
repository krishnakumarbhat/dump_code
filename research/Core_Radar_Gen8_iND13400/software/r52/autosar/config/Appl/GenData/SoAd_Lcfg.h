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
 *            Module: SoAd
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SoAd_Lcfg.h
 *   Generation Time: 2026-08-27 14:12:22
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
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] SOAD01500 - BSW Module configuration error. 
 * - [Reduced Severity due to User-Defined Parameter] /ActiveEcuC/Xcp only supports /ActiveEcuC/SoAd/Xcp[0:SoAdIfTxConfirmation](value=false) set to true. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/SoAd/Xcp[0:SoAdIfTxConfirmation](value=false) (DefRef: /MICROSAR/SoAd/SoAdBswModules/SoAdIfTxConfirmation)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
#if !defined (SOAD_LCFG_H)
# define SOAD_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "SoAd_Types.h"

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  SoAdPCDataSwitches  SoAd Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define SOAD_BESTMATCHSOCONIDXLIST                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONIDXOFBESTMATCHSOCONIDXLIST                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_DHCPEVENTCBK                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_DROPPEDTCPCONCTR                                                                       STD_OFF  /**< Deactivateable: 'SoAd_DroppedTcpConCtr' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SOAD_MEASUREMENTCOUNTERENDIDXOFDROPPEDTCPCONCTR                                             STD_OFF  /**< Deactivateable: 'SoAd_DroppedTcpConCtr.MeasurementCounterEndIdx' Reason: 'TCP is not configured.' */
#define SOAD_MEASUREMENTCOUNTERSTARTIDXOFDROPPEDTCPCONCTR                                           STD_OFF  /**< Deactivateable: 'SoAd_DroppedTcpConCtr.MeasurementCounterStartIdx' Reason: 'TCP is not configured.' */
#define SOAD_MEASUREMENTCOUNTERUSEDOFDROPPEDTCPCONCTR                                               STD_OFF  /**< Deactivateable: 'SoAd_DroppedTcpConCtr.MeasurementCounterUsed' Reason: 'TCP is not configured.' */
#define SOAD_DROPPEDTCPPDUCTR                                                                       STD_OFF  /**< Deactivateable: 'SoAd_DroppedTcpPduCtr' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SOAD_MEASUREMENTCOUNTERENDIDXOFDROPPEDTCPPDUCTR                                             STD_OFF  /**< Deactivateable: 'SoAd_DroppedTcpPduCtr.MeasurementCounterEndIdx' Reason: 'TCP is not configured.' */
#define SOAD_MEASUREMENTCOUNTERSTARTIDXOFDROPPEDTCPPDUCTR                                           STD_OFF  /**< Deactivateable: 'SoAd_DroppedTcpPduCtr.MeasurementCounterStartIdx' Reason: 'TCP is not configured.' */
#define SOAD_MEASUREMENTCOUNTERUSEDOFDROPPEDTCPPDUCTR                                               STD_OFF  /**< Deactivateable: 'SoAd_DroppedTcpPduCtr.MeasurementCounterUsed' Reason: 'TCP is not configured.' */
#define SOAD_DROPPEDUDPLENGTHCTR                                                                    STD_OFF  /**< Deactivateable: 'SoAd_DroppedUdpLengthCtr' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SOAD_MEASUREMENTCOUNTERENDIDXOFDROPPEDUDPLENGTHCTR                                          STD_OFF  /**< Deactivateable: 'SoAd_DroppedUdpLengthCtr.MeasurementCounterEndIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERSTARTIDXOFDROPPEDUDPLENGTHCTR                                        STD_OFF  /**< Deactivateable: 'SoAd_DroppedUdpLengthCtr.MeasurementCounterStartIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERUSEDOFDROPPEDUDPLENGTHCTR                                            STD_OFF  /**< Deactivateable: 'SoAd_DroppedUdpLengthCtr.MeasurementCounterUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_DROPPEDUDPPDUCTR                                                                       STD_OFF  /**< Deactivateable: 'SoAd_DroppedUdpPduCtr' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SOAD_MEASUREMENTCOUNTERENDIDXOFDROPPEDUDPPDUCTR                                             STD_OFF  /**< Deactivateable: 'SoAd_DroppedUdpPduCtr.MeasurementCounterEndIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERSTARTIDXOFDROPPEDUDPPDUCTR                                           STD_OFF  /**< Deactivateable: 'SoAd_DroppedUdpPduCtr.MeasurementCounterStartIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERUSEDOFDROPPEDUDPPDUCTR                                               STD_OFF  /**< Deactivateable: 'SoAd_DroppedUdpPduCtr.MeasurementCounterUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_DROPPEDUDPSOCKETCTR                                                                    STD_OFF  /**< Deactivateable: 'SoAd_DroppedUdpSocketCtr' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SOAD_MEASUREMENTCOUNTERENDIDXOFDROPPEDUDPSOCKETCTR                                          STD_OFF  /**< Deactivateable: 'SoAd_DroppedUdpSocketCtr.MeasurementCounterEndIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERSTARTIDXOFDROPPEDUDPSOCKETCTR                                        STD_OFF  /**< Deactivateable: 'SoAd_DroppedUdpSocketCtr.MeasurementCounterStartIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERUSEDOFDROPPEDUDPSOCKETCTR                                            STD_OFF  /**< Deactivateable: 'SoAd_DroppedUdpSocketCtr.MeasurementCounterUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_EVENTQUEUEFLAG                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIDENT                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEFLAGENDIDXOFEVENTQUEUEIDENT                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEFLAGSTARTIDXOFEVENTQUEUEIDENT                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFTXROUTEGRPCONFIGIDXOFEVENTQUEUEIDENT                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFTXROUTEGRPCONFIGUSEDOFEVENTQUEUEIDENT                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFUDPPDUROUTECONFIGIDXOFEVENTQUEUEIDENT                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFUDPPDUROUTECONFIGUSEDOFEVENTQUEUEIDENT                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUESOCONMODECHGCONFIGIDXOFEVENTQUEUEIDENT                                       STD_OFF  /**< Deactivateable: 'SoAd_EventQueueIdent.EventQueueSoConModeChgConfigIdx' Reason: 'SoConModeChg Queue is disabled.' */
#define SOAD_EVENTQUEUESTATESOCONCONFIGIDXOFEVENTQUEUEIDENT                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPRXSOCONCONFIGIDXOFEVENTQUEUEIDENT                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPRXSOCONCONFIGUSEDOFEVENTQUEUEIDENT                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPTXSOCONCONFIGIDXOFEVENTQUEUEIDENT                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPTXSOCONCONFIGUSEDOFEVENTQUEUEIDENT                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFTXROUTEGRP                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPIDXOFEVENTQUEUEIFTXROUTEGRP                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFTXROUTEGRPCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFTXROUTEGRPENDIDXOFEVENTQUEUEIFTXROUTEGRPCONFIG                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFTXROUTEGRPSTARTIDXOFEVENTQUEUEIFTXROUTEGRPCONFIG                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEMGMTIDXOFEVENTQUEUEIFTXROUTEGRPCONFIG                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_FLAGOFFSETOFEVENTQUEUEIFTXROUTEGRPCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LIMITOFEVENTQUEUEIFTXROUTEGRPCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFUDPPDUROUTE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEIDXOFEVENTQUEUEIFUDPPDUROUTE                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFUDPPDUROUTECONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFUDPPDUROUTEENDIDXOFEVENTQUEUEIFUDPPDUROUTECONFIG                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFUDPPDUROUTESTARTIDXOFEVENTQUEUEIFUDPPDUROUTECONFIG                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEMGMTIDXOFEVENTQUEUEIFUDPPDUROUTECONFIG                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_FLAGOFFSETOFEVENTQUEUEIFUDPPDUROUTECONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LIMITOFEVENTQUEUEIFUDPPDUROUTECONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEMGMT                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IDXOFEVENTQUEUEMGMT                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LVLOFEVENTQUEUEMGMT                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUESOCONMODECHG                                                                 STD_OFF  /**< Deactivateable: 'SoAd_EventQueueSoConModeChg' Reason: 'SoConModeChg Queue is disabled.' */
#define SOAD_SOCONIDXOFEVENTQUEUESOCONMODECHG                                                       STD_OFF  /**< Deactivateable: 'SoAd_EventQueueSoConModeChg.SoConIdx' Reason: 'SoConModeChg Queue is disabled.' */
#define SOAD_EVENTQUEUESOCONMODECHGCONFIG                                                           STD_OFF  /**< Deactivateable: 'SoAd_EventQueueSoConModeChgConfig' Reason: 'SoConModeChg Queue is disabled.' */
#define SOAD_EVENTQUEUEMGMTIDXOFEVENTQUEUESOCONMODECHGCONFIG                                        STD_OFF  /**< Deactivateable: 'SoAd_EventQueueSoConModeChgConfig.EventQueueMgmtIdx' Reason: 'SoConModeChg Queue is disabled.' */
#define SOAD_EVENTQUEUESOCONMODECHGENDIDXOFEVENTQUEUESOCONMODECHGCONFIG                             STD_OFF  /**< Deactivateable: 'SoAd_EventQueueSoConModeChgConfig.EventQueueSoConModeChgEndIdx' Reason: 'SoConModeChg Queue is disabled.' */
#define SOAD_EVENTQUEUESOCONMODECHGSTARTIDXOFEVENTQUEUESOCONMODECHGCONFIG                           STD_OFF  /**< Deactivateable: 'SoAd_EventQueueSoConModeChgConfig.EventQueueSoConModeChgStartIdx' Reason: 'SoConModeChg Queue is disabled.' */
#define SOAD_FLAGOFFSETOFEVENTQUEUESOCONMODECHGCONFIG                                               STD_OFF  /**< Deactivateable: 'SoAd_EventQueueSoConModeChgConfig.FlagOffset' Reason: 'SoConModeChg Queue is disabled.' */
#define SOAD_LIMITOFEVENTQUEUESOCONMODECHGCONFIG                                                    STD_OFF  /**< Deactivateable: 'SoAd_EventQueueSoConModeChgConfig.Limit' Reason: 'SoConModeChg Queue is disabled.' */
#define SOAD_EVENTQUEUESTATESOCON                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONIDXOFEVENTQUEUESTATESOCON                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUESTATESOCONCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEMGMTIDXOFEVENTQUEUESTATESOCONCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUESTATESOCONENDIDXOFEVENTQUEUESTATESOCONCONFIG                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUESTATESOCONSTARTIDXOFEVENTQUEUESTATESOCONCONFIG                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_FLAGOFFSETOFEVENTQUEUESTATESOCONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LIMITOFEVENTQUEUESTATESOCONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPRXSOCON                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONIDXOFEVENTQUEUETPRXSOCON                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPRXSOCONCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEMGMTIDXOFEVENTQUEUETPRXSOCONCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPRXSOCONENDIDXOFEVENTQUEUETPRXSOCONCONFIG                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPRXSOCONSTARTIDXOFEVENTQUEUETPRXSOCONCONFIG                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_FLAGOFFSETOFEVENTQUEUETPRXSOCONCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LIMITOFEVENTQUEUETPRXSOCONCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPTXSOCON                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONIDXOFEVENTQUEUETPTXSOCON                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPTXSOCONCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEMGMTIDXOFEVENTQUEUETPTXSOCONCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPTXSOCONENDIDXOFEVENTQUEUETPTXSOCONCONFIG                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPTXSOCONSTARTIDXOFEVENTQUEUETPTXSOCONCONFIG                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_FLAGOFFSETOFEVENTQUEUETPTXSOCONCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LIMITOFEVENTQUEUETPTXSOCONCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_FINALMAGICNUMBER                                                                       STD_OFF  /**< Deactivateable: 'SoAd_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define SOAD_IFRXBUFFER                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_INITDATAHASHCODE                                                                       STD_OFF  /**< Deactivateable: 'SoAd_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define SOAD_INSTANCE                                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_BESTMATCHSOCONIDXLISTENDIDXOFINSTANCE                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_BESTMATCHSOCONIDXLISTSTARTIDXOFINSTANCE                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIDENTIDXOFINSTANCE                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGBUFCONFIGENDIDXOFINSTANCE                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGBUFCONFIGSTARTIDXOFINSTANCE                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGBUFCONFIGUSEDOFINSTANCE                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTIDENTIDXOFINSTANCE                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TRIGGERBUFCONFIGENDIDXOFINSTANCE                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TRIGGERBUFCONFIGSTARTIDXOFINSTANCE                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TRIGGERBUFCONFIGUSEDOFINSTANCE                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_INSTANCEDYN                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_BESTMATCHLISTSIZEOFINSTANCEDYN                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_COUNTEROFINSTANCEDYN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_OPENSOCKSOFINSTANCEDYN                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_INSTANCEMAP                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSPECIFICINSTANCEIDXOFINSTANCEMAP                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSPECIFICINSTANCEPARTITIONIDXOFINSTANCEMAP                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_INVALIDSOMEIPMETHODIDCTR                                                               STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpMethodIdCtr' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SOAD_MEASUREMENTCOUNTERENDIDXOFINVALIDSOMEIPMETHODIDCTR                                     STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpMethodIdCtr.MeasurementCounterEndIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERSTARTIDXOFINVALIDSOMEIPMETHODIDCTR                                   STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpMethodIdCtr.MeasurementCounterStartIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERUSEDOFINVALIDSOMEIPMETHODIDCTR                                       STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpMethodIdCtr.MeasurementCounterUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_INVALIDSOMEIPSDMETHODIDCTR                                                             STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpSdMethodIdCtr' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SOAD_MEASUREMENTCOUNTERENDIDXOFINVALIDSOMEIPSDMETHODIDCTR                                   STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpSdMethodIdCtr.MeasurementCounterEndIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERSTARTIDXOFINVALIDSOMEIPSDMETHODIDCTR                                 STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpSdMethodIdCtr.MeasurementCounterStartIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERUSEDOFINVALIDSOMEIPSDMETHODIDCTR                                     STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpSdMethodIdCtr.MeasurementCounterUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_INVALIDSOMEIPSDSERVICEIDCTR                                                            STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpSdServiceIdCtr' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SOAD_MEASUREMENTCOUNTERENDIDXOFINVALIDSOMEIPSDSERVICEIDCTR                                  STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpSdServiceIdCtr.MeasurementCounterEndIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERSTARTIDXOFINVALIDSOMEIPSDSERVICEIDCTR                                STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpSdServiceIdCtr.MeasurementCounterStartIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERUSEDOFINVALIDSOMEIPSDSERVICEIDCTR                                    STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpSdServiceIdCtr.MeasurementCounterUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_INVALIDSOMEIPSERVICEIDCTR                                                              STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpServiceIdCtr' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SOAD_MEASUREMENTCOUNTERENDIDXOFINVALIDSOMEIPSERVICEIDCTR                                    STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpServiceIdCtr.MeasurementCounterEndIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERSTARTIDXOFINVALIDSOMEIPSERVICEIDCTR                                  STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpServiceIdCtr.MeasurementCounterStartIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERUSEDOFINVALIDSOMEIPSERVICEIDCTR                                      STD_OFF  /**< Deactivateable: 'SoAd_InvalidSomeIpServiceIdCtr.MeasurementCounterUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_IPFRAGBUF                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGBUFCONFIG                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGBUFENDIDXOFIPFRAGBUFCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGBUFSTARTIDXOFIPFRAGBUFCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGBUFCONFIGDYN                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LENGTHOFIPFRAGBUFCONFIGDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGMGT                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGBUFCONFIGIDXOFIPFRAGMGT                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALADDR                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ADDRIDOFLOCALADDR                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_DOMAINOFLOCALADDR                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONGRPENDIDXOFLOCALADDR                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONGRPSTARTIDXOFLOCALADDR                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONGRPUSEDOFLOCALADDR                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPIPCTRLIDXOFLOCALADDR                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALADDRBYTCPIPCTRLIND                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALADDRDYN                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPADDRSTATEOFLOCALADDRDYN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALADDRIDMAP                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_INVALIDHNDOFLOCALADDRIDMAP                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSPECIFICLOCALADDRIDXOFLOCALADDRIDMAP                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSPECIFICLOCALADDRPARTITIONIDXOFLOCALADDRIDMAP                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSPECIFICLOCALADDRUSEDOFLOCALADDRIDMAP                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALIPADDRASSIGNMENTCHGCBK                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALIPADDRASSIGNMENTCHGCBKIND                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_MAXIFROUTEGRPTRANSMITPDUSIZE                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_MEASUREMENTCOUNTER                                                                     STD_OFF  /**< Deactivateable: 'SoAd_MeasurementCounter' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASCOUNTERFLAGOFMEASUREMENTCOUNTER                                                    STD_OFF  /**< Deactivateable: 'SoAd_MeasurementCounter.MeasCounterFlag' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASCOUNTERVALUEOFMEASUREMENTCOUNTER                                                   STD_OFF  /**< Deactivateable: 'SoAd_MeasurementCounter.MeasCounterValue' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTDATAMGMT                                                                    STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERDROPPEDTCPCONIDXOFMEASUREMENTDATAMGMT                                STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterDroppedTcpConIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERDROPPEDTCPCONUSEDOFMEASUREMENTDATAMGMT                               STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterDroppedTcpConUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERDROPPEDTCPPDUIDXOFMEASUREMENTDATAMGMT                                STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterDroppedTcpPduIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERDROPPEDTCPPDUUSEDOFMEASUREMENTDATAMGMT                               STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterDroppedTcpPduUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERDROPPEDUDPLENGTHIDXOFMEASUREMENTDATAMGMT                             STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterDroppedUdpLengthIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERDROPPEDUDPLENGTHUSEDOFMEASUREMENTDATAMGMT                            STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterDroppedUdpLengthUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERDROPPEDUDPPDUIDXOFMEASUREMENTDATAMGMT                                STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterDroppedUdpPduIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERDROPPEDUDPPDUUSEDOFMEASUREMENTDATAMGMT                               STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterDroppedUdpPduUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERDROPPEDUDPSOCKETIDXOFMEASUREMENTDATAMGMT                             STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterDroppedUdpSocketIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERDROPPEDUDPSOCKETUSEDOFMEASUREMENTDATAMGMT                            STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterDroppedUdpSocketUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERINVALIDSOMEIPMETHODIDIDXOFMEASUREMENTDATAMGMT                        STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterInvalidSomeIpMethodIdIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERINVALIDSOMEIPMETHODIDUSEDOFMEASUREMENTDATAMGMT                       STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterInvalidSomeIpMethodIdUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERINVALIDSOMEIPSDMETHODIDIDXOFMEASUREMENTDATAMGMT                      STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterInvalidSomeIpSdMethodIdIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERINVALIDSOMEIPSDMETHODIDUSEDOFMEASUREMENTDATAMGMT                     STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterInvalidSomeIpSdMethodIdUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERINVALIDSOMEIPSDSERVICEIDIDXOFMEASUREMENTDATAMGMT                     STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterInvalidSomeIpSdServiceIdIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERINVALIDSOMEIPSDSERVICEIDUSEDOFMEASUREMENTDATAMGMT                    STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterInvalidSomeIpSdServiceIdUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERINVALIDSOMEIPSERVICEIDIDXOFMEASUREMENTDATAMGMT                       STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterInvalidSomeIpServiceIdIdx' Reason: 'Measurement data is disabled.' */
#define SOAD_MEASUREMENTCOUNTERINVALIDSOMEIPSERVICEIDUSEDOFMEASUREMENTDATAMGMT                      STD_OFF  /**< Deactivateable: 'SoAd_MeasurementDataMgmt.MeasurementCounterInvalidSomeIpServiceIdUsed' Reason: 'Measurement data is disabled.' */
#define SOAD_METADATARXBUFFER                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_MODECHGQUEUE                                                                           STD_OFF  /**< Deactivateable: 'SoAd_ModeChgQueue' Reason: 'SoConModeChg Queue is disabled.' */
#define SOAD_NPDUUDPTX                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXBUFFERENDIDXOFNPDUUDPTX                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXBUFFERSTARTIDXOFNPDUUDPTX                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXBUFFERUSEDOFNPDUUDPTX                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXQUEUEENDIDXOFNPDUUDPTX                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXQUEUESTARTIDXOFNPDUUDPTX                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXQUEUEUSEDOFNPDUUDPTX                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONIDXOFNPDUUDPTX                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXBUFFER                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXDYN                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_BUFLENOFNPDUUDPTXDYN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LVLOFNPDUUDPTXDYN                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RETRYCNTOFNPDUUDPTXDYN                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TOTALLENOFNPDUUDPTXDYN                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TRANSMISSIONSTATEOFNPDUUDPTXDYN                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXQUEUE                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_COPIEDOFNPDUUDPTXQUEUE                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LENOFNPDUUDPTXQUEUE                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXBUFFERIDXOFNPDUUDPTXQUEUE                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTIDXOFNPDUUDPTXQUEUE                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITION                                                                              STD_OFF  /**< Deactivateable: 'SoAd_Partition' Reason: 'No Multicore environment.' */
#define SOAD_OSAPPLICATIONIDOFPARTITION                                                             STD_OFF  /**< Deactivateable: 'SoAd_Partition.OsApplicationId' Reason: 'No Multicore environment.' */
#define SOAD_PARTITIONDYN                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_INITIALIZEDOFPARTITIONDYN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONIDENTIFIERS                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTE                                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ALLPDUROUTEDESTWITHPDUHDROFPDUROUTE                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IFOPTIMISTICTRANSMITOFPDUROUTE                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IFTRIGGERTRANSMITMODEOFPDUROUTE                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_METADATATXENABLEDOFPDUROUTE                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTENDIDXOFPDUROUTE                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTSTARTIDXOFPDUROUTE                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXCONFENABLEDOFPDUROUTE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXCONFPDUIDOFPDUROUTE                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXOPTIMIZEDOFPDUROUTE                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_UPPERLAYERAPIOFPDUROUTE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_UPPERLAYERIDXOFPDUROUTE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDEST                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEIDXOFPDUROUTEDEST                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCONBYPDUROUTEDESTINDENDIDXOFPDUROUTEDEST                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCONBYPDUROUTEDESTINDSTARTIDXOFPDUROUTEDEST                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCONBYPDUROUTEDESTINDUSEDOFPDUROUTEDEST                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONIDXOFPDUROUTEDEST                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXPDUHDRIDOFPDUROUTEDEST                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXUDPTRIGGERMODEOFPDUROUTEDEST                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_UDPTRIGGERTIMEOUTOFPDUROUTEDEST                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTBYSOCONIND                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTIND                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDYN                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PENDINGTXCONFMAINOFPDUROUTEDYN                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PENDINGTXCONFNUMOFPDUROUTEDYN                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRIPV4                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ADDROFREMADDRIPV4                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PORTOFREMADDRIPV4                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRIPV6                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ADDROFREMADDRIPV6                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PORTOFREMADDRIPV6                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRRCV                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRP                                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ENABLEDATINITOFROUTEGRP                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_MULTIINSTANCEONGRPOFROUTEGRP                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTINDENDIDXOFROUTEGRP                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTINDSTARTIDXOFROUTEGRP                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTINDUSEDOFROUTEGRP                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPIDOFROUTEGRP                                                                   STD_ON
#define SOAD_ROUTEGRPSOCONENDIDXOFROUTEGRP                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCONSTARTIDXOFROUTEGRP                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXREQUESTENABLEOFROUTEGRP                                                              STD_ON
#define SOAD_SOCKETROUTEINDENDIDXOFROUTEGRP                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTEINDSTARTIDXOFROUTEGRP                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTEINDUSEDOFROUTEGRP                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXTRIGGERABLEOFROUTEGRP                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPIDMAP                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_INVALIDHNDOFROUTEGRPIDMAP                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSPECIFICROUTEGRPIDXOFROUTEGRPIDMAP                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSPECIFICROUTEGRPPARTITIONIDXOFROUTEGRPIDMAP                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSPECIFICROUTEGRPUSEDOFROUTEGRPIDMAP                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCON                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPIDXOFROUTEGRPSOCON                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONIDXOFROUTEGRPSOCON                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCONBYPDUROUTEDESTIND                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCONBYSOCKETROUTEDESTIND                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCONDYN                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ENABLEDOFROUTEGRPSOCONDYN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_FLAGSOFROUTEGRPSOCONDYN                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFSTRUCTMGT                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFSTRUCTSEGIDXOFRXBUFSTRUCTMGT                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFSTRUCTSEGLVLOFRXBUFSTRUCTMGT                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFSTRUCTSEG                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_DATAPTROFRXBUFSTRUCTSEG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LENOFRXBUFSTRUCTSEG                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFFERCONFIG                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IFRXBUFFERENDIDXOFRXBUFFERCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IFRXBUFFERSTARTIDXOFRXBUFFERCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IFRXBUFFERUSEDOFRXBUFFERCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_METADATARXBUFFERENDIDXOFRXBUFFERCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_METADATARXBUFFERSTARTIDXOFRXBUFFERCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_METADATARXBUFFERUSEDOFRXBUFFERCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPRXBUFFERENDIDXOFRXBUFFERCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPRXBUFFERSTARTIDXOFRXBUFFERCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPRXBUFFERUSEDOFRXBUFFERCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFFERCONFIGDYN                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IFRXBUFFERIDXOFRXBUFFERCONFIGDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPRXBUFFERIDXOFRXBUFFERCONFIGDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXMGT                                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_CANCELREQUESTEDOFRXMGT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBYTESPENDINGOFRXMGT                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTEDESTIDXOFRXMGT                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXPDUIDIDMAP                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_INVALIDHNDOFRXPDUIDIDMAP                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSPECIFICSOCKETROUTEDESTIDXOFRXPDUIDIDMAP                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSPECIFICSOCKETROUTEDESTPARTITIONIDXOFRXPDUIDIDMAP                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SECURITYEVENT                                                                          STD_OFF  /**< Deactivateable: 'SoAd_SecurityEvent' Reason: 'Security events are disabled.' */
#define SOAD_SEVDROPMSGRXUDPLENGTHOFSECURITYEVENT                                                   STD_OFF  /**< Deactivateable: 'SoAd_SecurityEvent.SevDropMsgRxUdpLength' Reason: 'Security events are disabled.' */
#define SOAD_SEVDROPMSGRXUDPSOCKETOFSECURITYEVENT                                                   STD_OFF  /**< Deactivateable: 'SoAd_SecurityEvent.SevDropMsgRxUdpSocket' Reason: 'Security events are disabled.' */
#define SOAD_SEVDROPPDURXTCPOFSECURITYEVENT                                                         STD_OFF  /**< Deactivateable: 'SoAd_SecurityEvent.SevDropPduRxTcp' Reason: 'Security events are disabled.' */
#define SOAD_SEVDROPPDURXUDPOFSECURITYEVENT                                                         STD_OFF  /**< Deactivateable: 'SoAd_SecurityEvent.SevDropPduRxUdp' Reason: 'Security events are disabled.' */
#define SOAD_SEVREJECTEDTCPCONNECTIONOFSECURITYEVENT                                                STD_OFF  /**< Deactivateable: 'SoAd_SecurityEvent.SevRejectedTcpConnection' Reason: 'Security events are disabled.' */
#define SOAD_SHUTDOWNFINISHEDCBK                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFBESTMATCHSOCONIDXLIST                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFDHCPEVENTCBK                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFDROPPEDTCPCONCTR                                                                 STD_OFF  /**< Deactivateable: 'SoAd_SizeOfDroppedTcpConCtr' Reason: 'Deactivateable: 'DroppedTcpConCtr' Reason: 'Deactivateable: 'SoAd_DroppedTcpConCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFDROPPEDTCPPDUCTR                                                                 STD_OFF  /**< Deactivateable: 'SoAd_SizeOfDroppedTcpPduCtr' Reason: 'Deactivateable: 'DroppedTcpPduCtr' Reason: 'Deactivateable: 'SoAd_DroppedTcpPduCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFDROPPEDUDPLENGTHCTR                                                              STD_OFF  /**< Deactivateable: 'SoAd_SizeOfDroppedUdpLengthCtr' Reason: 'Deactivateable: 'DroppedUdpLengthCtr' Reason: 'Deactivateable: 'SoAd_DroppedUdpLengthCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFDROPPEDUDPPDUCTR                                                                 STD_OFF  /**< Deactivateable: 'SoAd_SizeOfDroppedUdpPduCtr' Reason: 'Deactivateable: 'DroppedUdpPduCtr' Reason: 'Deactivateable: 'SoAd_DroppedUdpPduCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFDROPPEDUDPSOCKETCTR                                                              STD_OFF  /**< Deactivateable: 'SoAd_SizeOfDroppedUdpSocketCtr' Reason: 'Deactivateable: 'DroppedUdpSocketCtr' Reason: 'Deactivateable: 'SoAd_DroppedUdpSocketCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFEVENTQUEUEFLAG                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUEIDENT                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUEIFTXROUTEGRP                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUEIFTXROUTEGRPCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUEIFUDPPDUROUTE                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUEIFUDPPDUROUTECONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUEMGMT                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUESOCONMODECHG                                                           STD_OFF  /**< Deactivateable: 'SoAd_SizeOfEventQueueSoConModeChg' Reason: 'Deactivateable: 'EventQueueSoConModeChg' Reason: 'Deactivateable: 'SoAd_EventQueueSoConModeChg' Reason: 'SoConModeChg Queue is disabled.''' */
#define SOAD_SIZEOFEVENTQUEUESOCONMODECHGCONFIG                                                     STD_OFF  /**< Deactivateable: 'SoAd_SizeOfEventQueueSoConModeChgConfig' Reason: 'Deactivateable: 'EventQueueSoConModeChgConfig' Reason: 'Deactivateable: 'SoAd_EventQueueSoConModeChgConfig' Reason: 'SoConModeChg Queue is disabled.''' */
#define SOAD_SIZEOFEVENTQUEUESTATESOCON                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUESTATESOCONCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUETPRXSOCON                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUETPRXSOCONCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUETPTXSOCON                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUETPTXSOCONCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFIFRXBUFFER                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFINSTANCE                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFINSTANCEDYN                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFINSTANCEMAP                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFINVALIDSOMEIPMETHODIDCTR                                                         STD_OFF  /**< Deactivateable: 'SoAd_SizeOfInvalidSomeIpMethodIdCtr' Reason: 'Deactivateable: 'InvalidSomeIpMethodIdCtr' Reason: 'Deactivateable: 'SoAd_InvalidSomeIpMethodIdCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFINVALIDSOMEIPSDMETHODIDCTR                                                       STD_OFF  /**< Deactivateable: 'SoAd_SizeOfInvalidSomeIpSdMethodIdCtr' Reason: 'Deactivateable: 'InvalidSomeIpSdMethodIdCtr' Reason: 'Deactivateable: 'SoAd_InvalidSomeIpSdMethodIdCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFINVALIDSOMEIPSDSERVICEIDCTR                                                      STD_OFF  /**< Deactivateable: 'SoAd_SizeOfInvalidSomeIpSdServiceIdCtr' Reason: 'Deactivateable: 'InvalidSomeIpSdServiceIdCtr' Reason: 'Deactivateable: 'SoAd_InvalidSomeIpSdServiceIdCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFINVALIDSOMEIPSERVICEIDCTR                                                        STD_OFF  /**< Deactivateable: 'SoAd_SizeOfInvalidSomeIpServiceIdCtr' Reason: 'Deactivateable: 'InvalidSomeIpServiceIdCtr' Reason: 'Deactivateable: 'SoAd_InvalidSomeIpServiceIdCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFIPFRAGBUF                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFIPFRAGBUFCONFIG                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFIPFRAGBUFCONFIGDYN                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFIPFRAGMGT                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFLOCALADDR                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFLOCALADDRBYTCPIPCTRLIND                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFLOCALADDRDYN                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFLOCALADDRIDMAP                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFLOCALIPADDRASSIGNMENTCHGCBK                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFLOCALIPADDRASSIGNMENTCHGCBKIND                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFMEASUREMENTCOUNTER                                                               STD_OFF  /**< Deactivateable: 'SoAd_SizeOfMeasurementCounter' Reason: 'Deactivateable: 'MeasurementCounter' Reason: 'Deactivateable: 'SoAd_MeasurementCounter' Reason: 'Measurement data is disabled.''' */
#define SOAD_SIZEOFMEASUREMENTDATAMGMT                                                              STD_OFF  /**< Deactivateable: 'SoAd_SizeOfMeasurementDataMgmt' Reason: 'Deactivateable: 'MeasurementDataMgmt' Reason: 'Deactivateable: 'SoAd_MeasurementDataMgmt' Reason: 'Measurement data is disabled.''' */
#define SOAD_SIZEOFMETADATARXBUFFER                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFMODECHGQUEUE                                                                     STD_OFF  /**< Deactivateable: 'SoAd_SizeOfModeChgQueue' Reason: 'Deactivateable: 'ModeChgQueue' Reason: 'Deactivateable: 'SoAd_ModeChgQueue' Reason: 'SoConModeChg Queue is disabled.''' */
#define SOAD_SIZEOFNPDUUDPTX                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFNPDUUDPTXBUFFER                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFNPDUUDPTXDYN                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFNPDUUDPTXQUEUE                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFPARTITION                                                                        STD_OFF  /**< Deactivateable: 'SoAd_SizeOfPartition' Reason: 'Deactivateable: 'Partition' Reason: 'Deactivateable: 'SoAd_Partition' Reason: 'No Multicore environment.''' */
#define SOAD_SIZEOFPARTITIONDYN                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFPARTITIONIDENTIFIERS                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFPDUROUTE                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFPDUROUTEDEST                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFPDUROUTEDESTBYSOCONIND                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFPDUROUTEDESTIND                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFPDUROUTEDYN                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFREMADDRIPV4                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFREMADDRIPV6                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFREMADDRRCV                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFROUTEGRP                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFROUTEGRPIDMAP                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFROUTEGRPSOCON                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFROUTEGRPSOCONBYPDUROUTEDESTIND                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFROUTEGRPSOCONBYSOCKETROUTEDESTIND                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFROUTEGRPSOCONDYN                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFRXBUFSTRUCTMGT                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFRXBUFSTRUCTSEG                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFRXBUFFERCONFIG                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFRXBUFFERCONFIGDYN                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFRXMGT                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFRXPDUIDIDMAP                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSECURITYEVENT                                                                    STD_OFF  /**< Deactivateable: 'SoAd_SizeOfSecurityEvent' Reason: 'Deactivateable: 'SecurityEvent' Reason: 'Deactivateable: 'SoAd_SecurityEvent' Reason: 'Security events are disabled.''' */
#define SOAD_SIZEOFSHUTDOWNFINISHEDCBK                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCON                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCONDYN                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCONGRP                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCONMAP                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCONMODECHGCBK                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCONMODECHGCBKIND                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCKET                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCKETDYN                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCKETROUTE                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCKETROUTEDEST                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCKETROUTEIND                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCKETTCP                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCKETUDP                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTCPIPCTRL                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTCPKEEPALIVEGLOBALLYENABLED                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTCPTXQUEUE                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTCPTXQUEUEDATA                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTCPTXQUEUEMGT                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTIDENT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTMGMT                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTNPDUUDPTX                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTNPDUUDPTXCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTNPDUUDPTXMAP                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTTCPAUTOCONNECT                                                        STD_OFF  /**< Deactivateable: 'SoAd_SizeOfTimeoutListTcpAutoConnect' Reason: 'Deactivateable: 'TimeoutListTcpAutoConnect' Reason: 'Deactivateable: 'SoAd_TimeoutListTcpAutoConnect' Reason: 'TCP is not configured.''' */
#define SOAD_SIZEOFTIMEOUTLISTTCPAUTOCONNECTCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTTCPAUTOCONNECTMAP                                                     STD_OFF  /**< Deactivateable: 'SoAd_SizeOfTimeoutListTcpAutoConnectMap' Reason: 'Deactivateable: 'TimeoutListTcpAutoConnectMap' Reason: 'Deactivateable: 'SoAd_TimeoutListTcpAutoConnectMap' Reason: 'TCP is not configured.''' */
#define SOAD_SIZEOFTIMEOUTLISTUDPALIVE                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTUDPALIVECONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTUDPALIVEMAP                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTPRXBUFFER                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTPTXBUFFER                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTPTXBUFFERCONFIG                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTPTXBUFFERCONFIGDYN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTRIGGERBUF                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTRIGGERBUFCONFIG                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTRIGGERBUFCONFIGDYN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTXMGT                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTXPDUIDMAP                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFUPPERLAYER                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFVERIFYRXPDUBUF                                                                   STD_OFF  /**< Deactivateable: 'SoAd_SizeOfVerifyRxPduBuf' Reason: 'Deactivateable: 'VerifyRxPduBuf' Reason: 'Deactivateable: 'SoAd_VerifyRxPduBuf' Reason: 'SoAdVerifyRxPduMaxDataLength is 0.''' */
#define SOAD_SIZEOFVERIFYRXPDUCBK                                                                   STD_OFF  /**< Deactivateable: 'SoAd_SizeOfVerifyRxPduCbk' Reason: 'Deactivateable: 'VerifyRxPduCbk' Reason: 'Deactivateable: 'SoAd_VerifyRxPduCbk' Reason: 'SoAdVerifyRxPduCallback is not configured.''' */
#define SOAD_SOCON                                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGMGTIDXOFSOCON                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGMGTUSEDOFSOCON                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALIPADDRASSIGNMENTCHGCBKINDENDIDXOFSOCON                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALIPADDRASSIGNMENTCHGCBKINDSTARTIDXOFSOCON                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALIPADDRASSIGNMENTCHGCBKINDUSEDOFSOCON                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_MODECHGQUEUEENDIDXOFSOCON                                                              STD_OFF  /**< Deactivateable: 'SoAd_SoCon.ModeChgQueueEndIdx' Reason: 'SoConModeChg Queue is disabled.' */
#define SOAD_MODECHGQUEUESTARTIDXOFSOCON                                                            STD_OFF  /**< Deactivateable: 'SoAd_SoCon.ModeChgQueueStartIdx' Reason: 'SoConModeChg Queue is disabled.' */
#define SOAD_MODECHGQUEUEUSEDOFSOCON                                                                STD_OFF  /**< Deactivateable: 'SoAd_SoCon.ModeChgQueueUsed' Reason: 'SoConModeChg Queue is disabled.' */
#define SOAD_NPDUUDPTXIDXOFSOCON                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXUSEDOFSOCON                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTBYSOCONINDENDIDXOFSOCON                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTBYSOCONINDSTARTIDXOFSOCON                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTBYSOCONINDUSEDOFSOCON                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRCFGSTATEOFSOCON                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRIPV4IDXOFSOCON                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRIPV4USEDOFSOCON                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRIPV6IDXOFSOCON                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRIPV6USEDOFSOCON                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRRCVIDXOFSOCON                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRRCVUSEDOFSOCON                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFSTRUCTMGTIDXOFSOCON                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFSTRUCTMGTUSEDOFSOCON                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFSTRUCTSEGENDIDXOFSOCON                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFSTRUCTSEGSTARTIDXOFSOCON                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFSTRUCTSEGUSEDOFSOCON                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFFERCONFIGIDXOFSOCON                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFFERCONFIGUSEDOFSOCON                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXMGTIDXOFSOCON                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXMGTUSEDOFSOCON                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONGRPIDXOFSOCON                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONIDOFSOCON                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONMODECHGCBKINDENDIDXOFSOCON                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONMODECHGCBKINDSTARTIDXOFSOCON                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONMODECHGCBKINDUSEDOFSOCON                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETIDXOFSOCON                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTEENDIDXOFSOCON                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTESTARTIDXOFSOCON                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTEUSEDOFSOCON                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPTXQUEUEIDXOFSOCON                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPTXQUEUEUSEDOFSOCON                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPTXBUFFERCONFIGIDXOFSOCON                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPTXBUFFERCONFIGUSEDOFSOCON                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXMGTIDXOFSOCON                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXMGTUSEDOFSOCON                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_VERIFYRXPDUENABLEDOFSOCON                                                              STD_OFF  /**< Deactivateable: 'SoAd_SoCon.VerifyRxPduEnabled' Reason: 'SoAdVerifyRxPduCallback is not configured.' */
#define SOAD_SOCONDYN                                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ABORTOFSOCONDYN                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_CLOSEMODEOFSOCONDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_MODEOFSOCONDYN                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_OPENCLOSECOUNTEROFSOCONDYN                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRDYNOFSOCONDYN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRRELEASEOFSOCONDYN                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRSTATEDYNOFSOCONDYN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXACTIVEOFSOCONDYN                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTOCCURREDOFSOCONDYN                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXACTIVEOFSOCONDYN                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONGRP                                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_BESTMATCHWITHPDUHEADERENABLEDOFSOCONGRP                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_BESTMATCHWITHSOCKROUTEENABLEDOFSOCONGRP                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_FRAMEPRIORITYOFSOCONGRP                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_INSTANCEIDXOFSOCONGRP                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALADDRIDXOFSOCONGRP                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALADDRUSEDOFSOCONGRP                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALPORTOFSOCONGRP                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_MEASUREMENTDATASOMEIPSDTYPEOFSOCONGRP                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_MSGACCEPTFILTERENABLEDOFSOCONGRP                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUHDRENABLEDOFSOCONGRP                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONENDIDXOFSOCONGRP                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONSTARTIDXOFSOCONGRP                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKAUTOSOCONSETUPKEEPONLINEOFSOCONGRP                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKAUTOSOCONSETUPOFSOCONGRP                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETIDXOFSOCONGRP                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETTCPIDXOFSOCONGRP                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETTCPUSEDOFSOCONGRP                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETUDPIDXOFSOCONGRP                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETUDPUSEDOFSOCONGRP                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETUSEDOFSOCONGRP                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONMAP                                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_INVALIDHNDOFSOCONMAP                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSPECIFICSOCONIDXOFSOCONMAP                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSPECIFICSOCONPARTITIONIDXOFSOCONMAP                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONMODECHGCBK                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONMODECHGCBKIND                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKET                                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONENDIDXOFSOCKET                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONSTARTIDXOFSOCKET                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETDYN                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALPORTOFSOCKETDYN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SKIPBYTESOFSOCKETDYN                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONTXACTIVEIDXOFSOCKETDYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETIDOFSOCKETDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_STATEOFSOCKETDYN                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTE                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_METADATARXENABLEDOFSOCKETROUTE                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXPDUHDRMETHODIDOFSOCKETROUTE                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXPDUHDRSERVICEIDOFSOCKETROUTE                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONIDXOFSOCKETROUTE                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTEDESTENDIDXOFSOCKETROUTE                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTEDESTSTARTIDXOFSOCKETROUTE                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_UPPERLAYERAPIOFSOCKETROUTE                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTEDEST                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCONBYSOCKETROUTEDESTINDENDIDXOFSOCKETROUTEDEST                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCONBYSOCKETROUTEDESTINDSTARTIDXOFSOCKETROUTEDEST                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCONBYSOCKETROUTEDESTINDUSEDOFSOCKETROUTEDEST                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXPDUIDOFSOCKETROUTEDEST                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTEIDXOFSOCKETROUTEDEST                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_UPPERLAYERIDXOFSOCKETROUTEDEST                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTEIND                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETTCP                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IMMEDTPTXCONFOFSOCKETTCP                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPAUTOCONNECTTIMEOUTOFSOCKETTCP                                                       STD_OFF  /**< Deactivateable: 'SoAd_SocketTcp.TcpAutoConnectTimeout' Reason: 'TCP is not configured.' */
#define SOAD_TCPINITIATEOFSOCKETTCP                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPKEEPALIVEINTERVALOFSOCKETTCP                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPKEEPALIVEOFSOCKETTCP                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPKEEPALIVEPROBESMAXOFSOCKETTCP                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPKEEPALIVETIMEOFSOCKETTCP                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPMSLOFSOCKETTCP                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPNODELAYOFSOCKETTCP                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPRXBUFMINOFSOCKETTCP                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPTLSCONIDOFSOCKETTCP                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPTXBUFMINOFSOCKETTCP                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETUDP                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ALIVETIMEOUTMAXCNTOFSOCKETUDP                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_CHECKSUMCHANGEENABLEDOFSOCKETUDP                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_CHECKSUMENABLEDOFSOCKETUDP                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IMMEDIFTXCONFLISTSIZEOFSOCKETUDP                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IMMEDIFTXCONFOFSOCKETUDP                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXBUFFERMINOFSOCKETUDP                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXQUEUESIZEOFSOCKETUDP                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RETRYQUEUELIMITOFSOCKETUDP                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_UDPLISTENONLYOFSOCKETUDP                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_UDPSTRICTHDRLENCHECKENABLEDOFSOCKETUDP                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_UDPTRIGGERTIMEOUTOFSOCKETUDP                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPIPCTRL                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALADDRBYTCPIPCTRLINDENDIDXOFTCPIPCTRL                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALADDRBYTCPIPCTRLINDSTARTIDXOFTCPIPCTRL                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALADDRBYTCPIPCTRLINDUSEDOFTCPIPCTRL                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RETRYENABLEDOFTCPIPCTRL                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPKEEPALIVEGLOBALLYENABLED                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPTXQUEUE                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPTXQUEUEDATAENDIDXOFTCPTXQUEUE                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPTXQUEUEDATASTARTIDXOFTCPTXQUEUE                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPTXQUEUEDATA                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LENOFTCPTXQUEUEDATA                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEIDXOFTCPTXQUEUEDATA                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPTXQUEUEMGT                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LVLOFTCPTXQUEUEMGT                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPTXQUEUEDATAIDXOFTCPTXQUEUEMGT                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TOTLENOFTCPTXQUEUEMGT                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTIDENT                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTNPDUUDPTXCONFIGIDXOFTIMEOUTLISTIDENT                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTNPDUUDPTXCONFIGUSEDOFTIMEOUTLISTIDENT                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTTCPAUTOCONNECTCONFIGIDXOFTIMEOUTLISTIDENT                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTTCPAUTOCONNECTCONFIGUSEDOFTIMEOUTLISTIDENT                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTUDPALIVECONFIGIDXOFTIMEOUTLISTIDENT                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTUDPALIVECONFIGUSEDOFTIMEOUTLISTIDENT                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTMGMT                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LVLOFTIMEOUTLISTMGMT                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTNPDUUDPTX                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXIDXOFTIMEOUTLISTNPDUUDPTX                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTOFTIMEOUTLISTNPDUUDPTX                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTNPDUUDPTXCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTMGMTIDXOFTIMEOUTLISTNPDUUDPTXCONFIG                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTNPDUUDPTXENDIDXOFTIMEOUTLISTNPDUUDPTXCONFIG                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTNPDUUDPTXSTARTIDXOFTIMEOUTLISTNPDUUDPTXCONFIG                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTNPDUUDPTXMAP                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTNPDUUDPTXIDXOFTIMEOUTLISTNPDUUDPTXMAP                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTTCPAUTOCONNECT                                                              STD_OFF  /**< Deactivateable: 'SoAd_TimeoutListTcpAutoConnect' Reason: 'TCP is not configured.' */
#define SOAD_SOCONIDXOFTIMEOUTLISTTCPAUTOCONNECT                                                    STD_OFF  /**< Deactivateable: 'SoAd_TimeoutListTcpAutoConnect.SoConIdx' Reason: 'TCP is not configured.' */
#define SOAD_TIMEOUTOFTIMEOUTLISTTCPAUTOCONNECT                                                     STD_OFF  /**< Deactivateable: 'SoAd_TimeoutListTcpAutoConnect.Timeout' Reason: 'TCP is not configured.' */
#define SOAD_TIMEOUTLISTTCPAUTOCONNECTCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTMGMTIDXOFTIMEOUTLISTTCPAUTOCONNECTCONFIG                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTTCPAUTOCONNECTENDIDXOFTIMEOUTLISTTCPAUTOCONNECTCONFIG                       STD_OFF  /**< Deactivateable: 'SoAd_TimeoutListTcpAutoConnectConfig.TimeoutListTcpAutoConnectEndIdx' Reason: 'TCP is not configured.' */
#define SOAD_TIMEOUTLISTTCPAUTOCONNECTSTARTIDXOFTIMEOUTLISTTCPAUTOCONNECTCONFIG                     STD_OFF  /**< Deactivateable: 'SoAd_TimeoutListTcpAutoConnectConfig.TimeoutListTcpAutoConnectStartIdx' Reason: 'TCP is not configured.' */
#define SOAD_TIMEOUTLISTTCPAUTOCONNECTMAP                                                           STD_OFF  /**< Deactivateable: 'SoAd_TimeoutListTcpAutoConnectMap' Reason: 'TCP is not configured.' */
#define SOAD_TIMEOUTLISTTCPAUTOCONNECTIDXOFTIMEOUTLISTTCPAUTOCONNECTMAP                             STD_OFF  /**< Deactivateable: 'SoAd_TimeoutListTcpAutoConnectMap.TimeoutListTcpAutoConnectIdx' Reason: 'TCP is not configured.' */
#define SOAD_TIMEOUTLISTUDPALIVE                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONIDXOFTIMEOUTLISTUDPALIVE                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTOFTIMEOUTLISTUDPALIVE                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTUDPALIVECONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTMGMTIDXOFTIMEOUTLISTUDPALIVECONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTUDPALIVEENDIDXOFTIMEOUTLISTUDPALIVECONFIG                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTUDPALIVESTARTIDXOFTIMEOUTLISTUDPALIVECONFIG                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTUDPALIVEMAP                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTUDPALIVEIDXOFTIMEOUTLISTUDPALIVEMAP                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPRXBUFFER                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPTXBUFFER                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPTXBUFFERCONFIG                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPTXBUFFERENDIDXOFTPTXBUFFERCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPTXBUFFERSTARTIDXOFTPTXBUFFERCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPTXBUFFERUSEDOFTPTXBUFFERCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPTXBUFFERCONFIGDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPTXBUFFERIDXOFTPTXBUFFERCONFIGDYN                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TRIGGERBUF                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TRIGGERBUFCONFIG                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TRIGGERBUFENDIDXOFTRIGGERBUFCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TRIGGERBUFSTARTIDXOFTRIGGERBUFCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TRIGGERBUFCONFIGDYN                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LENGTHOFTRIGGERBUFCONFIGDYN                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEIDXOFTRIGGERBUFCONFIGDYN                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXMGT                                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_CANCELREQUESTEDOFTXMGT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTIDXOFTXMGT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXBUFPTROFTXMGT                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXBYTESLENOFTXMGT                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXBYTESPENDINGOFTXMGT                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXPDUIDMAP                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_INVALIDHNDOFTXPDUIDMAP                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSPECIFICPDUROUTEIDXOFTXPDUIDMAP                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONSPECIFICPDUROUTEPARTITIONIDXOFTXPDUIDMAP                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_UPPERLAYER                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IFRXINDICATIONCBKOFUPPERLAYER                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IFTRIGGERTRANSMITCBKOFUPPERLAYER                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IFTXCONFIRMATIONCBKOFUPPERLAYER                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPCOPYRXDATACBKOFUPPERLAYER                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPCOPYRXDATACONSTCBKOFUPPERLAYER                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPCOPYTXDATACBKOFUPPERLAYER                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPCOPYTXDATACONSTCBKOFUPPERLAYER                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPRXINDICATIONCBKOFUPPERLAYER                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPSTARTOFRECEPTIONCBKOFUPPERLAYER                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPSTARTOFRECEPTIONCONSTCBKOFUPPERLAYER                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPTXCONFIRMATIONCBKOFUPPERLAYER                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_VERIFYRXPDUBUF                                                                         STD_OFF  /**< Deactivateable: 'SoAd_VerifyRxPduBuf' Reason: 'SoAdVerifyRxPduMaxDataLength is 0.' */
#define SOAD_VERIFYRXPDUCBK                                                                         STD_OFF  /**< Deactivateable: 'SoAd_VerifyRxPduCbk' Reason: 'SoAdVerifyRxPduCallback is not configured.' */
#define SOAD_PCCONFIG                                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_FINALMAGICNUMBEROFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'SoAd_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define SOAD_INITDATAHASHCODEOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'SoAd_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define SOAD_PCPARTITIONCONFIGOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONIDENTIFIERSOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PCPARTITIONCONFIG                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_BESTMATCHSOCONIDXLISTOFPCPARTITIONCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_DHCPEVENTCBKOFPCPARTITIONCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEFLAGOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIDENTOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFTXROUTEGRPCONFIGOFPCPARTITIONCONFIG                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFTXROUTEGRPOFPCPARTITIONCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFUDPPDUROUTECONFIGOFPCPARTITIONCONFIG                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEIFUDPPDUROUTEOFPCPARTITIONCONFIG                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUEMGMTOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUESTATESOCONCONFIGOFPCPARTITIONCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUESTATESOCONOFPCPARTITIONCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPRXSOCONCONFIGOFPCPARTITIONCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPRXSOCONOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPTXSOCONCONFIGOFPCPARTITIONCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_EVENTQUEUETPTXSOCONOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IFRXBUFFEROFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_INSTANCEDYNOFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_INSTANCEMAPOFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_INSTANCEOFPCPARTITIONCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGBUFCONFIGDYNOFPCPARTITIONCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGBUFCONFIGOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGBUFOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_IPFRAGMGTOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALADDRBYTCPIPCTRLINDOFPCPARTITIONCONFIG                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALADDRDYNOFPCPARTITIONCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALADDRIDMAPOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALADDROFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALIPADDRASSIGNMENTCHGCBKINDOFPCPARTITIONCONFIG                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_LOCALIPADDRASSIGNMENTCHGCBKOFPCPARTITIONCONFIG                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_MAXIFROUTEGRPTRANSMITPDUSIZEOFPCPARTITIONCONFIG                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_METADATARXBUFFEROFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXBUFFEROFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXDYNOFPCPARTITIONCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_NPDUUDPTXQUEUEOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PARTITIONDYNOFPCPARTITIONCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTBYSOCONINDOFPCPARTITIONCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTINDOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDESTOFPCPARTITIONCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEDYNOFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_PDUROUTEOFPCPARTITIONCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRIPV4OFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRIPV6OFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_REMADDRRCVOFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPIDMAPOFPCPARTITIONCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPOFPCPARTITIONCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCONBYPDUROUTEDESTINDOFPCPARTITIONCONFIG                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCONBYSOCKETROUTEDESTINDOFPCPARTITIONCONFIG                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCONDYNOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_ROUTEGRPSOCONOFPCPARTITIONCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFSTRUCTMGTOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFSTRUCTSEGOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFFERCONFIGDYNOFPCPARTITIONCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXBUFFERCONFIGOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXMGTOFPCPARTITIONCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_RXPDUIDIDMAPOFPCPARTITIONCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SHUTDOWNFINISHEDCBKOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFBESTMATCHSOCONIDXLISTOFPCPARTITIONCONFIG                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFDHCPEVENTCBKOFPCPARTITIONCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFDROPPEDTCPCONCTROFPCPARTITIONCONFIG                                              STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfDroppedTcpConCtr' Reason: 'Deactivateable: 'DroppedTcpConCtr' Reason: 'Deactivateable: 'SoAd_DroppedTcpConCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFDROPPEDTCPPDUCTROFPCPARTITIONCONFIG                                              STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfDroppedTcpPduCtr' Reason: 'Deactivateable: 'DroppedTcpPduCtr' Reason: 'Deactivateable: 'SoAd_DroppedTcpPduCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFDROPPEDUDPLENGTHCTROFPCPARTITIONCONFIG                                           STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfDroppedUdpLengthCtr' Reason: 'Deactivateable: 'DroppedUdpLengthCtr' Reason: 'Deactivateable: 'SoAd_DroppedUdpLengthCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFDROPPEDUDPPDUCTROFPCPARTITIONCONFIG                                              STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfDroppedUdpPduCtr' Reason: 'Deactivateable: 'DroppedUdpPduCtr' Reason: 'Deactivateable: 'SoAd_DroppedUdpPduCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFDROPPEDUDPSOCKETCTROFPCPARTITIONCONFIG                                           STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfDroppedUdpSocketCtr' Reason: 'Deactivateable: 'DroppedUdpSocketCtr' Reason: 'Deactivateable: 'SoAd_DroppedUdpSocketCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFEVENTQUEUEFLAGOFPCPARTITIONCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUEIDENTOFPCPARTITIONCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUEIFTXROUTEGRPCONFIGOFPCPARTITIONCONFIG                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUEIFTXROUTEGRPOFPCPARTITIONCONFIG                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUEIFUDPPDUROUTECONFIGOFPCPARTITIONCONFIG                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUEIFUDPPDUROUTEOFPCPARTITIONCONFIG                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUEMGMTOFPCPARTITIONCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUESOCONMODECHGCONFIGOFPCPARTITIONCONFIG                                  STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfEventQueueSoConModeChgConfig' Reason: 'Deactivateable: 'EventQueueSoConModeChgConfig' Reason: 'Deactivateable: 'SoAd_EventQueueSoConModeChgConfig' Reason: 'SoConModeChg Queue is disabled.''' */
#define SOAD_SIZEOFEVENTQUEUESOCONMODECHGOFPCPARTITIONCONFIG                                        STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfEventQueueSoConModeChg' Reason: 'Deactivateable: 'EventQueueSoConModeChg' Reason: 'Deactivateable: 'SoAd_EventQueueSoConModeChg' Reason: 'SoConModeChg Queue is disabled.''' */
#define SOAD_SIZEOFEVENTQUEUESTATESOCONCONFIGOFPCPARTITIONCONFIG                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUESTATESOCONOFPCPARTITIONCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUETPRXSOCONCONFIGOFPCPARTITIONCONFIG                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUETPRXSOCONOFPCPARTITIONCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUETPTXSOCONCONFIGOFPCPARTITIONCONFIG                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFEVENTQUEUETPTXSOCONOFPCPARTITIONCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFIFRXBUFFEROFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFINSTANCEDYNOFPCPARTITIONCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFINSTANCEMAPOFPCPARTITIONCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFINSTANCEOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFINVALIDSOMEIPMETHODIDCTROFPCPARTITIONCONFIG                                      STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfInvalidSomeIpMethodIdCtr' Reason: 'Deactivateable: 'InvalidSomeIpMethodIdCtr' Reason: 'Deactivateable: 'SoAd_InvalidSomeIpMethodIdCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFINVALIDSOMEIPSDMETHODIDCTROFPCPARTITIONCONFIG                                    STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfInvalidSomeIpSdMethodIdCtr' Reason: 'Deactivateable: 'InvalidSomeIpSdMethodIdCtr' Reason: 'Deactivateable: 'SoAd_InvalidSomeIpSdMethodIdCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFINVALIDSOMEIPSDSERVICEIDCTROFPCPARTITIONCONFIG                                   STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfInvalidSomeIpSdServiceIdCtr' Reason: 'Deactivateable: 'InvalidSomeIpSdServiceIdCtr' Reason: 'Deactivateable: 'SoAd_InvalidSomeIpSdServiceIdCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFINVALIDSOMEIPSERVICEIDCTROFPCPARTITIONCONFIG                                     STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfInvalidSomeIpServiceIdCtr' Reason: 'Deactivateable: 'InvalidSomeIpServiceIdCtr' Reason: 'Deactivateable: 'SoAd_InvalidSomeIpServiceIdCtr' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define SOAD_SIZEOFIPFRAGBUFCONFIGDYNOFPCPARTITIONCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFIPFRAGBUFCONFIGOFPCPARTITIONCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFIPFRAGBUFOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFIPFRAGMGTOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFLOCALADDRBYTCPIPCTRLINDOFPCPARTITIONCONFIG                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFLOCALADDRDYNOFPCPARTITIONCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFLOCALADDRIDMAPOFPCPARTITIONCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFLOCALADDROFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFLOCALIPADDRASSIGNMENTCHGCBKINDOFPCPARTITIONCONFIG                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFLOCALIPADDRASSIGNMENTCHGCBKOFPCPARTITIONCONFIG                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFMEASUREMENTCOUNTEROFPCPARTITIONCONFIG                                            STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfMeasurementCounter' Reason: 'Deactivateable: 'MeasurementCounter' Reason: 'Deactivateable: 'SoAd_MeasurementCounter' Reason: 'Measurement data is disabled.''' */
#define SOAD_SIZEOFMEASUREMENTDATAMGMTOFPCPARTITIONCONFIG                                           STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfMeasurementDataMgmt' Reason: 'Deactivateable: 'MeasurementDataMgmt' Reason: 'Deactivateable: 'SoAd_MeasurementDataMgmt' Reason: 'Measurement data is disabled.''' */
#define SOAD_SIZEOFMETADATARXBUFFEROFPCPARTITIONCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFMODECHGQUEUEOFPCPARTITIONCONFIG                                                  STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfModeChgQueue' Reason: 'Deactivateable: 'ModeChgQueue' Reason: 'Deactivateable: 'SoAd_ModeChgQueue' Reason: 'SoConModeChg Queue is disabled.''' */
#define SOAD_SIZEOFNPDUUDPTXBUFFEROFPCPARTITIONCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFNPDUUDPTXDYNOFPCPARTITIONCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFNPDUUDPTXOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFNPDUUDPTXQUEUEOFPCPARTITIONCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFPARTITIONDYNOFPCPARTITIONCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFPARTITIONOFPCPARTITIONCONFIG                                                     STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfPartition' Reason: 'Deactivateable: 'Partition' Reason: 'Deactivateable: 'SoAd_Partition' Reason: 'No Multicore environment.''' */
#define SOAD_SIZEOFPDUROUTEDESTBYSOCONINDOFPCPARTITIONCONFIG                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFPDUROUTEDESTINDOFPCPARTITIONCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFPDUROUTEDESTOFPCPARTITIONCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFPDUROUTEDYNOFPCPARTITIONCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFPDUROUTEOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFREMADDRIPV4OFPCPARTITIONCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFREMADDRIPV6OFPCPARTITIONCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFREMADDRRCVOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFROUTEGRPIDMAPOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFROUTEGRPOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFROUTEGRPSOCONBYPDUROUTEDESTINDOFPCPARTITIONCONFIG                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFROUTEGRPSOCONBYSOCKETROUTEDESTINDOFPCPARTITIONCONFIG                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFROUTEGRPSOCONDYNOFPCPARTITIONCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFROUTEGRPSOCONOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFRXBUFSTRUCTMGTOFPCPARTITIONCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFRXBUFSTRUCTSEGOFPCPARTITIONCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFRXBUFFERCONFIGDYNOFPCPARTITIONCONFIG                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFRXBUFFERCONFIGOFPCPARTITIONCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFRXMGTOFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFRXPDUIDIDMAPOFPCPARTITIONCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSECURITYEVENTOFPCPARTITIONCONFIG                                                 STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfSecurityEvent' Reason: 'Deactivateable: 'SecurityEvent' Reason: 'Deactivateable: 'SoAd_SecurityEvent' Reason: 'Security events are disabled.''' */
#define SOAD_SIZEOFSHUTDOWNFINISHEDCBKOFPCPARTITIONCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCONDYNOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCONGRPOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCONMAPOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCONMODECHGCBKINDOFPCPARTITIONCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCONMODECHGCBKOFPCPARTITIONCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCONOFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCKETDYNOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCKETOFPCPARTITIONCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCKETROUTEDESTOFPCPARTITIONCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCKETROUTEINDOFPCPARTITIONCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCKETROUTEOFPCPARTITIONCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCKETTCPOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFSOCKETUDPOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTCPIPCTRLOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTCPKEEPALIVEGLOBALLYENABLEDOFPCPARTITIONCONFIG                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTCPTXQUEUEDATAOFPCPARTITIONCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTCPTXQUEUEMGTOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTCPTXQUEUEOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTIDENTOFPCPARTITIONCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTMGMTOFPCPARTITIONCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTNPDUUDPTXCONFIGOFPCPARTITIONCONFIG                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTNPDUUDPTXMAPOFPCPARTITIONCONFIG                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTNPDUUDPTXOFPCPARTITIONCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTTCPAUTOCONNECTCONFIGOFPCPARTITIONCONFIG                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTTCPAUTOCONNECTMAPOFPCPARTITIONCONFIG                                  STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfTimeoutListTcpAutoConnectMap' Reason: 'Deactivateable: 'TimeoutListTcpAutoConnectMap' Reason: 'Deactivateable: 'SoAd_TimeoutListTcpAutoConnectMap' Reason: 'TCP is not configured.''' */
#define SOAD_SIZEOFTIMEOUTLISTTCPAUTOCONNECTOFPCPARTITIONCONFIG                                     STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfTimeoutListTcpAutoConnect' Reason: 'Deactivateable: 'TimeoutListTcpAutoConnect' Reason: 'Deactivateable: 'SoAd_TimeoutListTcpAutoConnect' Reason: 'TCP is not configured.''' */
#define SOAD_SIZEOFTIMEOUTLISTUDPALIVECONFIGOFPCPARTITIONCONFIG                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTUDPALIVEMAPOFPCPARTITIONCONFIG                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTIMEOUTLISTUDPALIVEOFPCPARTITIONCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTPRXBUFFEROFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTPTXBUFFERCONFIGDYNOFPCPARTITIONCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTPTXBUFFERCONFIGOFPCPARTITIONCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTPTXBUFFEROFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTRIGGERBUFCONFIGDYNOFPCPARTITIONCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTRIGGERBUFCONFIGOFPCPARTITIONCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTRIGGERBUFOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTXMGTOFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFTXPDUIDMAPOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFUPPERLAYEROFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SIZEOFVERIFYRXPDUBUFOFPCPARTITIONCONFIG                                                STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfVerifyRxPduBuf' Reason: 'Deactivateable: 'VerifyRxPduBuf' Reason: 'Deactivateable: 'SoAd_VerifyRxPduBuf' Reason: 'SoAdVerifyRxPduMaxDataLength is 0.''' */
#define SOAD_SIZEOFVERIFYRXPDUCBKOFPCPARTITIONCONFIG                                                STD_OFF  /**< Deactivateable: 'SoAd_PCPartitionConfig.SizeOfVerifyRxPduCbk' Reason: 'Deactivateable: 'VerifyRxPduCbk' Reason: 'Deactivateable: 'SoAd_VerifyRxPduCbk' Reason: 'SoAdVerifyRxPduCallback is not configured.''' */
#define SOAD_SOCONDYNOFPCPARTITIONCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONGRPOFPCPARTITIONCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONMAPOFPCPARTITIONCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONMODECHGCBKINDOFPCPARTITIONCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONMODECHGCBKOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCONOFPCPARTITIONCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETDYNOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETOFPCPARTITIONCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTEDESTOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTEINDOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETROUTEOFPCPARTITIONCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETTCPOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_SOCKETUDPOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPIPCTRLOFPCPARTITIONCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPKEEPALIVEGLOBALLYENABLEDOFPCPARTITIONCONFIG                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPTXQUEUEDATAOFPCPARTITIONCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPTXQUEUEMGTOFPCPARTITIONCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TCPTXQUEUEOFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTIDENTOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTMGMTOFPCPARTITIONCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTNPDUUDPTXCONFIGOFPCPARTITIONCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTNPDUUDPTXMAPOFPCPARTITIONCONFIG                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTNPDUUDPTXOFPCPARTITIONCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTTCPAUTOCONNECTCONFIGOFPCPARTITIONCONFIG                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTUDPALIVECONFIGOFPCPARTITIONCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTUDPALIVEMAPOFPCPARTITIONCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TIMEOUTLISTUDPALIVEOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPRXBUFFEROFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPTXBUFFERCONFIGDYNOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPTXBUFFERCONFIGOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TPTXBUFFEROFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TRIGGERBUFCONFIGDYNOFPCPARTITIONCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TRIGGERBUFCONFIGOFPCPARTITIONCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TRIGGERBUFOFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXMGTOFPCPARTITIONCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_TXPDUIDMAPOFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define SOAD_UPPERLAYEROFPCPARTITIONCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCMinNumericValueDefines  SoAd Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define SOAD_MIN_SOCONIDXOFBESTMATCHSOCONIDXLIST                                                    0u
#define SOAD_MIN_ROUTEGRPIDXOFEVENTQUEUEIFTXROUTEGRP                                                0u
#define SOAD_MIN_PDUROUTEIDXOFEVENTQUEUEIFUDPPDUROUTE                                               0u
#define SOAD_MIN_IDXOFEVENTQUEUEMGMT                                                                0u
#define SOAD_MIN_LVLOFEVENTQUEUEMGMT                                                                0u
#define SOAD_MIN_SOCONIDXOFEVENTQUEUESTATESOCON                                                     0u
#define SOAD_MIN_SOCONIDXOFEVENTQUEUETPRXSOCON                                                      0u
#define SOAD_MIN_SOCONIDXOFEVENTQUEUETPTXSOCON                                                      0u
#define SOAD_MIN_IFRXBUFFER                                                                         0u
#define SOAD_MIN_COUNTEROFINSTANCEDYN                                                               0u
#define SOAD_MIN_IPFRAGBUF                                                                          0u
#define SOAD_MIN_LENGTHOFIPFRAGBUFCONFIGDYN                                                         0u
#define SOAD_MIN_IPFRAGBUFCONFIGIDXOFIPFRAGMGT                                                      0u
#define SOAD_MIN_METADATARXBUFFER                                                                   0u
#define SOAD_MIN_NPDUUDPTXBUFFER                                                                    0u
#define SOAD_MIN_BUFLENOFNPDUUDPTXDYN                                                               0u
#define SOAD_MIN_LVLOFNPDUUDPTXDYN                                                                  0u
#define SOAD_MIN_RETRYCNTOFNPDUUDPTXDYN                                                             0u
#define SOAD_MIN_TOTALLENOFNPDUUDPTXDYN                                                             0u
#define SOAD_MIN_LENOFNPDUUDPTXQUEUE                                                                0u
#define SOAD_MIN_NPDUUDPTXBUFFERIDXOFNPDUUDPTXQUEUE                                                 0u
#define SOAD_MIN_PDUROUTEDESTIDXOFNPDUUDPTXQUEUE                                                    0u
#define SOAD_MIN_FLAGSOFROUTEGRPSOCONDYN                                                            0u
#define SOAD_MIN_RXBUFSTRUCTSEGIDXOFRXBUFSTRUCTMGT                                                  0u
#define SOAD_MIN_RXBUFSTRUCTSEGLVLOFRXBUFSTRUCTMGT                                                  0u
#define SOAD_MIN_LENOFRXBUFSTRUCTSEG                                                                0u
#define SOAD_MIN_IFRXBUFFERIDXOFRXBUFFERCONFIGDYN                                                   0u
#define SOAD_MIN_TPRXBUFFERIDXOFRXBUFFERCONFIGDYN                                                   0u
#define SOAD_MIN_RXBYTESPENDINGOFRXMGT                                                              0u
#define SOAD_MIN_SOCKETROUTEDESTIDXOFRXMGT                                                          0u
#define SOAD_MIN_OPENCLOSECOUNTEROFSOCONDYN                                                         0u
#define SOAD_MIN_SKIPBYTESOFSOCKETDYN                                                               0u
#define SOAD_MIN_SOCONTXACTIVEIDXOFSOCKETDYN                                                        0u
#define SOAD_MIN_LENOFTCPTXQUEUEDATA                                                                0u
#define SOAD_MIN_PDUROUTEIDXOFTCPTXQUEUEDATA                                                        0u
#define SOAD_MIN_LVLOFTCPTXQUEUEMGT                                                                 0u
#define SOAD_MIN_TCPTXQUEUEDATAIDXOFTCPTXQUEUEMGT                                                   0u
#define SOAD_MIN_TOTLENOFTCPTXQUEUEMGT                                                              0u
#define SOAD_MIN_LVLOFTIMEOUTLISTMGMT                                                               0u
#define SOAD_MIN_NPDUUDPTXIDXOFTIMEOUTLISTNPDUUDPTX                                                 0u
#define SOAD_MIN_TIMEOUTOFTIMEOUTLISTNPDUUDPTX                                                      0u
#define SOAD_MIN_TIMEOUTLISTNPDUUDPTXIDXOFTIMEOUTLISTNPDUUDPTXMAP                                   0u
#define SOAD_MIN_SOCONIDXOFTIMEOUTLISTUDPALIVE                                                      0u
#define SOAD_MIN_TIMEOUTOFTIMEOUTLISTUDPALIVE                                                       0u
#define SOAD_MIN_TIMEOUTLISTUDPALIVEIDXOFTIMEOUTLISTUDPALIVEMAP                                     0u
#define SOAD_MIN_TPRXBUFFER                                                                         0u
#define SOAD_MIN_TPTXBUFFER                                                                         0u
#define SOAD_MIN_TPTXBUFFERIDXOFTPTXBUFFERCONFIGDYN                                                 0u
#define SOAD_MIN_TRIGGERBUF                                                                         0u
#define SOAD_MIN_LENGTHOFTRIGGERBUFCONFIGDYN                                                        0u
#define SOAD_MIN_PDUROUTEIDXOFTRIGGERBUFCONFIGDYN                                                   0u
#define SOAD_MIN_PDUROUTEDESTIDXOFTXMGT                                                             0u
#define SOAD_MIN_TXBYTESLENOFTXMGT                                                                  0u
#define SOAD_MIN_TXBYTESPENDINGOFTXMGT                                                              0u
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCMaxNumericValueDefines  SoAd Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define SOAD_MAX_SOCONIDXOFBESTMATCHSOCONIDXLIST                                                    255u
#define SOAD_MAX_ROUTEGRPIDXOFEVENTQUEUEIFTXROUTEGRP                                                255u
#define SOAD_MAX_PDUROUTEIDXOFEVENTQUEUEIFUDPPDUROUTE                                               255u
#define SOAD_MAX_IDXOFEVENTQUEUEMGMT                                                                65535u
#define SOAD_MAX_LVLOFEVENTQUEUEMGMT                                                                65535u
#define SOAD_MAX_SOCONIDXOFEVENTQUEUESTATESOCON                                                     255u
#define SOAD_MAX_SOCONIDXOFEVENTQUEUETPRXSOCON                                                      255u
#define SOAD_MAX_SOCONIDXOFEVENTQUEUETPTXSOCON                                                      255u
#define SOAD_MAX_IFRXBUFFER                                                                         255u
#define SOAD_MAX_COUNTEROFINSTANCEDYN                                                               4294967295u
#define SOAD_MAX_IPFRAGBUF                                                                          255u
#define SOAD_MAX_LENGTHOFIPFRAGBUFCONFIGDYN                                                         65535u
#define SOAD_MAX_IPFRAGBUFCONFIGIDXOFIPFRAGMGT                                                      255u
#define SOAD_MAX_METADATARXBUFFER                                                                   255u
#define SOAD_MAX_NPDUUDPTXBUFFER                                                                    255u
#define SOAD_MAX_BUFLENOFNPDUUDPTXDYN                                                               65535u
#define SOAD_MAX_LVLOFNPDUUDPTXDYN                                                                  255u
#define SOAD_MAX_RETRYCNTOFNPDUUDPTXDYN                                                             65535u
#define SOAD_MAX_TOTALLENOFNPDUUDPTXDYN                                                             4294967295u
#define SOAD_MAX_LENOFNPDUUDPTXQUEUE                                                                65535u
#define SOAD_MAX_NPDUUDPTXBUFFERIDXOFNPDUUDPTXQUEUE                                                 255u
#define SOAD_MAX_PDUROUTEDESTIDXOFNPDUUDPTXQUEUE                                                    255u
#define SOAD_MAX_FLAGSOFROUTEGRPSOCONDYN                                                            255u
#define SOAD_MAX_RXBUFSTRUCTSEGIDXOFRXBUFSTRUCTMGT                                                  255u
#define SOAD_MAX_RXBUFSTRUCTSEGLVLOFRXBUFSTRUCTMGT                                                  255u
#define SOAD_MAX_LENOFRXBUFSTRUCTSEG                                                                65535u
#define SOAD_MAX_IFRXBUFFERIDXOFRXBUFFERCONFIGDYN                                                   255u
#define SOAD_MAX_TPRXBUFFERIDXOFRXBUFFERCONFIGDYN                                                   255u
#define SOAD_MAX_RXBYTESPENDINGOFRXMGT                                                              65535u
#define SOAD_MAX_SOCKETROUTEDESTIDXOFRXMGT                                                          255u
#define SOAD_MAX_OPENCLOSECOUNTEROFSOCONDYN                                                         4294967295u
#define SOAD_MAX_SKIPBYTESOFSOCKETDYN                                                               4294967295u
#define SOAD_MAX_SOCONTXACTIVEIDXOFSOCKETDYN                                                        255u
#define SOAD_MAX_LENOFTCPTXQUEUEDATA                                                                65535u
#define SOAD_MAX_PDUROUTEIDXOFTCPTXQUEUEDATA                                                        255u
#define SOAD_MAX_LVLOFTCPTXQUEUEMGT                                                                 65535u
#define SOAD_MAX_TCPTXQUEUEDATAIDXOFTCPTXQUEUEMGT                                                   255u
#define SOAD_MAX_TOTLENOFTCPTXQUEUEMGT                                                              4294967295u
#define SOAD_MAX_LVLOFTIMEOUTLISTMGMT                                                               65535u
#define SOAD_MAX_NPDUUDPTXIDXOFTIMEOUTLISTNPDUUDPTX                                                 255u
#define SOAD_MAX_TIMEOUTOFTIMEOUTLISTNPDUUDPTX                                                      4294967295u
#define SOAD_MAX_TIMEOUTLISTNPDUUDPTXIDXOFTIMEOUTLISTNPDUUDPTXMAP                                   255u
#define SOAD_MAX_SOCONIDXOFTIMEOUTLISTUDPALIVE                                                      255u
#define SOAD_MAX_TIMEOUTOFTIMEOUTLISTUDPALIVE                                                       4294967295u
#define SOAD_MAX_TIMEOUTLISTUDPALIVEIDXOFTIMEOUTLISTUDPALIVEMAP                                     255u
#define SOAD_MAX_TPRXBUFFER                                                                         255u
#define SOAD_MAX_TPTXBUFFER                                                                         255u
#define SOAD_MAX_TPTXBUFFERIDXOFTPTXBUFFERCONFIGDYN                                                 255u
#define SOAD_MAX_TRIGGERBUF                                                                         255u
#define SOAD_MAX_LENGTHOFTRIGGERBUFCONFIGDYN                                                        65535u
#define SOAD_MAX_PDUROUTEIDXOFTRIGGERBUFCONFIGDYN                                                   255u
#define SOAD_MAX_PDUROUTEDESTIDXOFTXMGT                                                             255u
#define SOAD_MAX_TXBYTESLENOFTXMGT                                                                  65535u
#define SOAD_MAX_TXBYTESPENDINGOFTXMGT                                                              65535u
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCNoReferenceDefines  SoAd No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define SOAD_NO_EVENTQUEUEIFTXROUTEGRPCONFIGIDXOFEVENTQUEUEIDENT                                    255u
#define SOAD_NO_EVENTQUEUEIFUDPPDUROUTECONFIGIDXOFEVENTQUEUEIDENT                                   255u
#define SOAD_NO_EVENTQUEUETPRXSOCONCONFIGIDXOFEVENTQUEUEIDENT                                       255u
#define SOAD_NO_EVENTQUEUETPTXSOCONCONFIGIDXOFEVENTQUEUEIDENT                                       255u
#define SOAD_NO_ROUTEGRPIDXOFEVENTQUEUEIFTXROUTEGRP                                                 255u
#define SOAD_NO_PDUROUTEIDXOFEVENTQUEUEIFUDPPDUROUTE                                                255u
#define SOAD_NO_SOCONIDXOFEVENTQUEUESTATESOCON                                                      255u
#define SOAD_NO_SOCONIDXOFEVENTQUEUETPRXSOCON                                                       255u
#define SOAD_NO_SOCONIDXOFEVENTQUEUETPTXSOCON                                                       255u
#define SOAD_NO_IPFRAGBUFCONFIGENDIDXOFINSTANCE                                                     255u
#define SOAD_NO_IPFRAGBUFCONFIGSTARTIDXOFINSTANCE                                                   255u
#define SOAD_NO_TRIGGERBUFCONFIGENDIDXOFINSTANCE                                                    255u
#define SOAD_NO_TRIGGERBUFCONFIGSTARTIDXOFINSTANCE                                                  255u
#define SOAD_NO_PARTITIONSPECIFICINSTANCEPARTITIONIDXOFINSTANCEMAP                                  255u
#define SOAD_NO_SOCONGRPENDIDXOFLOCALADDR                                                           255u
#define SOAD_NO_SOCONGRPSTARTIDXOFLOCALADDR                                                         255u
#define SOAD_NO_PARTITIONSPECIFICLOCALADDRIDXOFLOCALADDRIDMAP                                       255u
#define SOAD_NO_PARTITIONSPECIFICLOCALADDRPARTITIONIDXOFLOCALADDRIDMAP                              255u
#define SOAD_NO_NPDUUDPTXBUFFERENDIDXOFNPDUUDPTX                                                    255u
#define SOAD_NO_NPDUUDPTXBUFFERSTARTIDXOFNPDUUDPTX                                                  255u
#define SOAD_NO_NPDUUDPTXQUEUEENDIDXOFNPDUUDPTX                                                     255u
#define SOAD_NO_NPDUUDPTXQUEUESTARTIDXOFNPDUUDPTX                                                   255u
#define SOAD_NO_PDUROUTEDESTIDXOFNPDUUDPTXQUEUE                                                     255u
#define SOAD_NO_ROUTEGRPSOCONBYPDUROUTEDESTINDENDIDXOFPDUROUTEDEST                                  255u
#define SOAD_NO_ROUTEGRPSOCONBYPDUROUTEDESTINDSTARTIDXOFPDUROUTEDEST                                255u
#define SOAD_NO_PDUROUTEDESTINDENDIDXOFROUTEGRP                                                     255u
#define SOAD_NO_PDUROUTEDESTINDSTARTIDXOFROUTEGRP                                                   255u
#define SOAD_NO_SOCKETROUTEINDENDIDXOFROUTEGRP                                                      255u
#define SOAD_NO_SOCKETROUTEINDSTARTIDXOFROUTEGRP                                                    255u
#define SOAD_NO_PARTITIONSPECIFICROUTEGRPIDXOFROUTEGRPIDMAP                                         255u
#define SOAD_NO_PARTITIONSPECIFICROUTEGRPPARTITIONIDXOFROUTEGRPIDMAP                                255u
#define SOAD_NO_IFRXBUFFERENDIDXOFRXBUFFERCONFIG                                                    255u
#define SOAD_NO_IFRXBUFFERSTARTIDXOFRXBUFFERCONFIG                                                  255u
#define SOAD_NO_METADATARXBUFFERENDIDXOFRXBUFFERCONFIG                                              255u
#define SOAD_NO_METADATARXBUFFERSTARTIDXOFRXBUFFERCONFIG                                            255u
#define SOAD_NO_TPRXBUFFERENDIDXOFRXBUFFERCONFIG                                                    255u
#define SOAD_NO_TPRXBUFFERSTARTIDXOFRXBUFFERCONFIG                                                  255u
#define SOAD_NO_IFRXBUFFERIDXOFRXBUFFERCONFIGDYN                                                    255u
#define SOAD_NO_TPRXBUFFERIDXOFRXBUFFERCONFIGDYN                                                    255u
#define SOAD_NO_PARTITIONSPECIFICSOCKETROUTEDESTPARTITIONIDXOFRXPDUIDIDMAP                          255u
#define SOAD_NO_IPFRAGMGTIDXOFSOCON                                                                 255u
#define SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDENDIDXOFSOCON                                         255u
#define SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDSTARTIDXOFSOCON                                       255u
#define SOAD_NO_NPDUUDPTXIDXOFSOCON                                                                 255u
#define SOAD_NO_PDUROUTEDESTBYSOCONINDENDIDXOFSOCON                                                 255u
#define SOAD_NO_PDUROUTEDESTBYSOCONINDSTARTIDXOFSOCON                                               255u
#define SOAD_NO_REMADDRIPV4IDXOFSOCON                                                               255u
#define SOAD_NO_REMADDRIPV6IDXOFSOCON                                                               255u
#define SOAD_NO_REMADDRRCVIDXOFSOCON                                                                255u
#define SOAD_NO_RXBUFSTRUCTMGTIDXOFSOCON                                                            255u
#define SOAD_NO_RXBUFSTRUCTSEGENDIDXOFSOCON                                                         255u
#define SOAD_NO_RXBUFSTRUCTSEGSTARTIDXOFSOCON                                                       255u
#define SOAD_NO_RXBUFFERCONFIGIDXOFSOCON                                                            255u
#define SOAD_NO_RXMGTIDXOFSOCON                                                                     255u
#define SOAD_NO_SOCONMODECHGCBKINDENDIDXOFSOCON                                                     255u
#define SOAD_NO_SOCONMODECHGCBKINDSTARTIDXOFSOCON                                                   255u
#define SOAD_NO_SOCKETROUTEENDIDXOFSOCON                                                            255u
#define SOAD_NO_SOCKETROUTESTARTIDXOFSOCON                                                          255u
#define SOAD_NO_TCPTXQUEUEIDXOFSOCON                                                                255u
#define SOAD_NO_TPTXBUFFERCONFIGIDXOFSOCON                                                          255u
#define SOAD_NO_TXMGTIDXOFSOCON                                                                     255u
#define SOAD_NO_FRAMEPRIORITYOFSOCONGRP                                                             255u
#define SOAD_NO_LOCALADDRIDXOFSOCONGRP                                                              255u
#define SOAD_NO_SOCKETIDXOFSOCONGRP                                                                 255u
#define SOAD_NO_SOCKETTCPIDXOFSOCONGRP                                                              255u
#define SOAD_NO_SOCKETUDPIDXOFSOCONGRP                                                              255u
#define SOAD_NO_PARTITIONSPECIFICSOCONPARTITIONIDXOFSOCONMAP                                        255u
#define SOAD_NO_SOCONTXACTIVEIDXOFSOCKETDYN                                                         255u
#define SOAD_NO_ROUTEGRPSOCONBYSOCKETROUTEDESTINDENDIDXOFSOCKETROUTEDEST                            255u
#define SOAD_NO_ROUTEGRPSOCONBYSOCKETROUTEDESTINDSTARTIDXOFSOCKETROUTEDEST                          255u
#define SOAD_NO_TCPKEEPALIVEINTERVALOFSOCKETTCP                                                     255u
#define SOAD_NO_TCPKEEPALIVEPROBESMAXOFSOCKETTCP                                                    255u
#define SOAD_NO_TCPKEEPALIVETIMEOFSOCKETTCP                                                         255u
#define SOAD_NO_TCPMSLOFSOCKETTCP                                                                   255u
#define SOAD_NO_TCPTLSCONIDOFSOCKETTCP                                                              255u
#define SOAD_NO_LOCALADDRBYTCPIPCTRLINDENDIDXOFTCPIPCTRL                                            255u
#define SOAD_NO_LOCALADDRBYTCPIPCTRLINDSTARTIDXOFTCPIPCTRL                                          255u
#define SOAD_NO_TIMEOUTLISTNPDUUDPTXCONFIGIDXOFTIMEOUTLISTIDENT                                     255u
#define SOAD_NO_TIMEOUTLISTTCPAUTOCONNECTCONFIGIDXOFTIMEOUTLISTIDENT                                255u
#define SOAD_NO_TIMEOUTLISTUDPALIVECONFIGIDXOFTIMEOUTLISTIDENT                                      255u
#define SOAD_NO_NPDUUDPTXIDXOFTIMEOUTLISTNPDUUDPTX                                                  255u
#define SOAD_NO_TIMEOUTLISTNPDUUDPTXIDXOFTIMEOUTLISTNPDUUDPTXMAP                                    255u
#define SOAD_NO_SOCONIDXOFTIMEOUTLISTUDPALIVE                                                       255u
#define SOAD_NO_TIMEOUTLISTUDPALIVEIDXOFTIMEOUTLISTUDPALIVEMAP                                      255u
#define SOAD_NO_TPTXBUFFERENDIDXOFTPTXBUFFERCONFIG                                                  255u
#define SOAD_NO_TPTXBUFFERSTARTIDXOFTPTXBUFFERCONFIG                                                255u
#define SOAD_NO_PARTITIONSPECIFICPDUROUTEPARTITIONIDXOFTXPDUIDMAP                                   255u
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCIsReducedToDefineDefines  SoAd Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define SOAD_ISDEF_DHCPEVENTCBK                                                                     STD_OFF
#define SOAD_ISDEF_EVENTQUEUEFLAGENDIDXOFEVENTQUEUEIDENT                                            STD_OFF
#define SOAD_ISDEF_EVENTQUEUEFLAGSTARTIDXOFEVENTQUEUEIDENT                                          STD_OFF
#define SOAD_ISDEF_EVENTQUEUEIFTXROUTEGRPCONFIGIDXOFEVENTQUEUEIDENT                                 STD_OFF
#define SOAD_ISDEF_EVENTQUEUEIFTXROUTEGRPCONFIGUSEDOFEVENTQUEUEIDENT                                STD_OFF
#define SOAD_ISDEF_EVENTQUEUEIFUDPPDUROUTECONFIGIDXOFEVENTQUEUEIDENT                                STD_OFF
#define SOAD_ISDEF_EVENTQUEUEIFUDPPDUROUTECONFIGUSEDOFEVENTQUEUEIDENT                               STD_OFF
#define SOAD_ISDEF_EVENTQUEUESTATESOCONCONFIGIDXOFEVENTQUEUEIDENT                                   STD_OFF
#define SOAD_ISDEF_EVENTQUEUETPRXSOCONCONFIGIDXOFEVENTQUEUEIDENT                                    STD_OFF
#define SOAD_ISDEF_EVENTQUEUETPRXSOCONCONFIGUSEDOFEVENTQUEUEIDENT                                   STD_OFF
#define SOAD_ISDEF_EVENTQUEUETPTXSOCONCONFIGIDXOFEVENTQUEUEIDENT                                    STD_OFF
#define SOAD_ISDEF_EVENTQUEUETPTXSOCONCONFIGUSEDOFEVENTQUEUEIDENT                                   STD_OFF
#define SOAD_ISDEF_EVENTQUEUEIFTXROUTEGRPENDIDXOFEVENTQUEUEIFTXROUTEGRPCONFIG                       STD_OFF
#define SOAD_ISDEF_EVENTQUEUEIFTXROUTEGRPSTARTIDXOFEVENTQUEUEIFTXROUTEGRPCONFIG                     STD_OFF
#define SOAD_ISDEF_EVENTQUEUEMGMTIDXOFEVENTQUEUEIFTXROUTEGRPCONFIG                                  STD_OFF
#define SOAD_ISDEF_FLAGOFFSETOFEVENTQUEUEIFTXROUTEGRPCONFIG                                         STD_OFF
#define SOAD_ISDEF_LIMITOFEVENTQUEUEIFTXROUTEGRPCONFIG                                              STD_OFF
#define SOAD_ISDEF_EVENTQUEUEIFUDPPDUROUTEENDIDXOFEVENTQUEUEIFUDPPDUROUTECONFIG                     STD_OFF
#define SOAD_ISDEF_EVENTQUEUEIFUDPPDUROUTESTARTIDXOFEVENTQUEUEIFUDPPDUROUTECONFIG                   STD_OFF
#define SOAD_ISDEF_EVENTQUEUEMGMTIDXOFEVENTQUEUEIFUDPPDUROUTECONFIG                                 STD_OFF
#define SOAD_ISDEF_FLAGOFFSETOFEVENTQUEUEIFUDPPDUROUTECONFIG                                        STD_OFF
#define SOAD_ISDEF_LIMITOFEVENTQUEUEIFUDPPDUROUTECONFIG                                             STD_OFF
#define SOAD_ISDEF_EVENTQUEUEMGMTIDXOFEVENTQUEUESTATESOCONCONFIG                                    STD_OFF
#define SOAD_ISDEF_EVENTQUEUESTATESOCONENDIDXOFEVENTQUEUESTATESOCONCONFIG                           STD_OFF
#define SOAD_ISDEF_EVENTQUEUESTATESOCONSTARTIDXOFEVENTQUEUESTATESOCONCONFIG                         STD_OFF
#define SOAD_ISDEF_FLAGOFFSETOFEVENTQUEUESTATESOCONCONFIG                                           STD_OFF
#define SOAD_ISDEF_LIMITOFEVENTQUEUESTATESOCONCONFIG                                                STD_OFF
#define SOAD_ISDEF_EVENTQUEUEMGMTIDXOFEVENTQUEUETPRXSOCONCONFIG                                     STD_OFF
#define SOAD_ISDEF_EVENTQUEUETPRXSOCONENDIDXOFEVENTQUEUETPRXSOCONCONFIG                             STD_OFF
#define SOAD_ISDEF_EVENTQUEUETPRXSOCONSTARTIDXOFEVENTQUEUETPRXSOCONCONFIG                           STD_OFF
#define SOAD_ISDEF_FLAGOFFSETOFEVENTQUEUETPRXSOCONCONFIG                                            STD_OFF
#define SOAD_ISDEF_LIMITOFEVENTQUEUETPRXSOCONCONFIG                                                 STD_OFF
#define SOAD_ISDEF_EVENTQUEUEMGMTIDXOFEVENTQUEUETPTXSOCONCONFIG                                     STD_OFF
#define SOAD_ISDEF_EVENTQUEUETPTXSOCONENDIDXOFEVENTQUEUETPTXSOCONCONFIG                             STD_OFF
#define SOAD_ISDEF_EVENTQUEUETPTXSOCONSTARTIDXOFEVENTQUEUETPTXSOCONCONFIG                           STD_OFF
#define SOAD_ISDEF_FLAGOFFSETOFEVENTQUEUETPTXSOCONCONFIG                                            STD_OFF
#define SOAD_ISDEF_LIMITOFEVENTQUEUETPTXSOCONCONFIG                                                 STD_OFF
#define SOAD_ISDEF_BESTMATCHSOCONIDXLISTENDIDXOFINSTANCE                                            STD_OFF
#define SOAD_ISDEF_BESTMATCHSOCONIDXLISTSTARTIDXOFINSTANCE                                          STD_OFF
#define SOAD_ISDEF_EVENTQUEUEIDENTIDXOFINSTANCE                                                     STD_OFF
#define SOAD_ISDEF_IPFRAGBUFCONFIGENDIDXOFINSTANCE                                                  STD_OFF
#define SOAD_ISDEF_IPFRAGBUFCONFIGSTARTIDXOFINSTANCE                                                STD_OFF
#define SOAD_ISDEF_IPFRAGBUFCONFIGUSEDOFINSTANCE                                                    STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTIDENTIDXOFINSTANCE                                                    STD_OFF
#define SOAD_ISDEF_TRIGGERBUFCONFIGENDIDXOFINSTANCE                                                 STD_OFF
#define SOAD_ISDEF_TRIGGERBUFCONFIGSTARTIDXOFINSTANCE                                               STD_OFF
#define SOAD_ISDEF_TRIGGERBUFCONFIGUSEDOFINSTANCE                                                   STD_OFF
#define SOAD_ISDEF_PARTITIONSPECIFICINSTANCEIDXOFINSTANCEMAP                                        STD_OFF
#define SOAD_ISDEF_PARTITIONSPECIFICINSTANCEPARTITIONIDXOFINSTANCEMAP                               STD_OFF
#define SOAD_ISDEF_IPFRAGBUFENDIDXOFIPFRAGBUFCONFIG                                                 STD_OFF
#define SOAD_ISDEF_IPFRAGBUFSTARTIDXOFIPFRAGBUFCONFIG                                               STD_OFF
#define SOAD_ISDEF_ADDRIDOFLOCALADDR                                                                STD_OFF
#define SOAD_ISDEF_DOMAINOFLOCALADDR                                                                STD_OFF
#define SOAD_ISDEF_SOCONGRPENDIDXOFLOCALADDR                                                        STD_OFF
#define SOAD_ISDEF_SOCONGRPSTARTIDXOFLOCALADDR                                                      STD_OFF
#define SOAD_ISDEF_SOCONGRPUSEDOFLOCALADDR                                                          STD_OFF
#define SOAD_ISDEF_TCPIPCTRLIDXOFLOCALADDR                                                          STD_OFF
#define SOAD_ISDEF_LOCALADDRBYTCPIPCTRLIND                                                          STD_OFF
#define SOAD_ISDEF_INVALIDHNDOFLOCALADDRIDMAP                                                       STD_OFF
#define SOAD_ISDEF_PARTITIONSPECIFICLOCALADDRIDXOFLOCALADDRIDMAP                                    STD_OFF
#define SOAD_ISDEF_PARTITIONSPECIFICLOCALADDRPARTITIONIDXOFLOCALADDRIDMAP                           STD_OFF
#define SOAD_ISDEF_PARTITIONSPECIFICLOCALADDRUSEDOFLOCALADDRIDMAP                                   STD_OFF
#define SOAD_ISDEF_LOCALIPADDRASSIGNMENTCHGCBK                                                      STD_OFF
#define SOAD_ISDEF_LOCALIPADDRASSIGNMENTCHGCBKIND                                                   STD_OFF
#define SOAD_ISDEF_NPDUUDPTXBUFFERENDIDXOFNPDUUDPTX                                                 STD_OFF
#define SOAD_ISDEF_NPDUUDPTXBUFFERSTARTIDXOFNPDUUDPTX                                               STD_OFF
#define SOAD_ISDEF_NPDUUDPTXBUFFERUSEDOFNPDUUDPTX                                                   STD_OFF
#define SOAD_ISDEF_NPDUUDPTXQUEUEENDIDXOFNPDUUDPTX                                                  STD_OFF
#define SOAD_ISDEF_NPDUUDPTXQUEUESTARTIDXOFNPDUUDPTX                                                STD_OFF
#define SOAD_ISDEF_NPDUUDPTXQUEUEUSEDOFNPDUUDPTX                                                    STD_OFF
#define SOAD_ISDEF_SOCONIDXOFNPDUUDPTX                                                              STD_OFF
#define SOAD_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                       STD_OFF
#define SOAD_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                               STD_OFF
#define SOAD_ISDEF_ALLPDUROUTEDESTWITHPDUHDROFPDUROUTE                                              STD_OFF
#define SOAD_ISDEF_IFOPTIMISTICTRANSMITOFPDUROUTE                                                   STD_OFF
#define SOAD_ISDEF_IFTRIGGERTRANSMITMODEOFPDUROUTE                                                  STD_OFF
#define SOAD_ISDEF_METADATATXENABLEDOFPDUROUTE                                                      STD_OFF
#define SOAD_ISDEF_PDUROUTEDESTENDIDXOFPDUROUTE                                                     STD_OFF
#define SOAD_ISDEF_PDUROUTEDESTSTARTIDXOFPDUROUTE                                                   STD_OFF
#define SOAD_ISDEF_TXCONFENABLEDOFPDUROUTE                                                          STD_OFF
#define SOAD_ISDEF_TXCONFPDUIDOFPDUROUTE                                                            STD_OFF
#define SOAD_ISDEF_TXOPTIMIZEDOFPDUROUTE                                                            STD_OFF
#define SOAD_ISDEF_UPPERLAYERAPIOFPDUROUTE                                                          STD_OFF
#define SOAD_ISDEF_UPPERLAYERIDXOFPDUROUTE                                                          STD_OFF
#define SOAD_ISDEF_PDUROUTEIDXOFPDUROUTEDEST                                                        STD_OFF
#define SOAD_ISDEF_ROUTEGRPSOCONBYPDUROUTEDESTINDENDIDXOFPDUROUTEDEST                               STD_OFF
#define SOAD_ISDEF_ROUTEGRPSOCONBYPDUROUTEDESTINDSTARTIDXOFPDUROUTEDEST                             STD_OFF
#define SOAD_ISDEF_ROUTEGRPSOCONBYPDUROUTEDESTINDUSEDOFPDUROUTEDEST                                 STD_OFF
#define SOAD_ISDEF_SOCONIDXOFPDUROUTEDEST                                                           STD_OFF
#define SOAD_ISDEF_TXPDUHDRIDOFPDUROUTEDEST                                                         STD_OFF
#define SOAD_ISDEF_TXUDPTRIGGERMODEOFPDUROUTEDEST                                                   STD_OFF
#define SOAD_ISDEF_UDPTRIGGERTIMEOUTOFPDUROUTEDEST                                                  STD_OFF
#define SOAD_ISDEF_PDUROUTEDESTBYSOCONIND                                                           STD_OFF
#define SOAD_ISDEF_PDUROUTEDESTIND                                                                  STD_OFF
#define SOAD_ISDEF_ADDROFREMADDRIPV4                                                                STD_OFF
#define SOAD_ISDEF_PORTOFREMADDRIPV4                                                                STD_OFF
#define SOAD_ISDEF_ADDROFREMADDRIPV6                                                                STD_OFF
#define SOAD_ISDEF_PORTOFREMADDRIPV6                                                                STD_OFF
#define SOAD_ISDEF_ENABLEDATINITOFROUTEGRP                                                          STD_OFF
#define SOAD_ISDEF_MULTIINSTANCEONGRPOFROUTEGRP                                                     STD_OFF
#define SOAD_ISDEF_PDUROUTEDESTINDENDIDXOFROUTEGRP                                                  STD_OFF
#define SOAD_ISDEF_PDUROUTEDESTINDSTARTIDXOFROUTEGRP                                                STD_OFF
#define SOAD_ISDEF_PDUROUTEDESTINDUSEDOFROUTEGRP                                                    STD_OFF
#define SOAD_ISDEF_ROUTEGRPIDOFROUTEGRP                                                             STD_OFF
#define SOAD_ISDEF_ROUTEGRPSOCONENDIDXOFROUTEGRP                                                    STD_OFF
#define SOAD_ISDEF_ROUTEGRPSOCONSTARTIDXOFROUTEGRP                                                  STD_OFF
#define SOAD_ISDEF_RXREQUESTENABLEOFROUTEGRP                                                        STD_OFF
#define SOAD_ISDEF_SOCKETROUTEINDENDIDXOFROUTEGRP                                                   STD_OFF
#define SOAD_ISDEF_SOCKETROUTEINDSTARTIDXOFROUTEGRP                                                 STD_OFF
#define SOAD_ISDEF_SOCKETROUTEINDUSEDOFROUTEGRP                                                     STD_OFF
#define SOAD_ISDEF_TXTRIGGERABLEOFROUTEGRP                                                          STD_OFF
#define SOAD_ISDEF_INVALIDHNDOFROUTEGRPIDMAP                                                        STD_OFF
#define SOAD_ISDEF_PARTITIONSPECIFICROUTEGRPIDXOFROUTEGRPIDMAP                                      STD_OFF
#define SOAD_ISDEF_PARTITIONSPECIFICROUTEGRPPARTITIONIDXOFROUTEGRPIDMAP                             STD_OFF
#define SOAD_ISDEF_PARTITIONSPECIFICROUTEGRPUSEDOFROUTEGRPIDMAP                                     STD_OFF
#define SOAD_ISDEF_ROUTEGRPIDXOFROUTEGRPSOCON                                                       STD_OFF
#define SOAD_ISDEF_SOCONIDXOFROUTEGRPSOCON                                                          STD_OFF
#define SOAD_ISDEF_ROUTEGRPSOCONBYPDUROUTEDESTIND                                                   STD_OFF
#define SOAD_ISDEF_ROUTEGRPSOCONBYSOCKETROUTEDESTIND                                                STD_OFF
#define SOAD_ISDEF_IFRXBUFFERENDIDXOFRXBUFFERCONFIG                                                 STD_OFF
#define SOAD_ISDEF_IFRXBUFFERSTARTIDXOFRXBUFFERCONFIG                                               STD_OFF
#define SOAD_ISDEF_IFRXBUFFERUSEDOFRXBUFFERCONFIG                                                   STD_OFF
#define SOAD_ISDEF_METADATARXBUFFERENDIDXOFRXBUFFERCONFIG                                           STD_OFF
#define SOAD_ISDEF_METADATARXBUFFERSTARTIDXOFRXBUFFERCONFIG                                         STD_OFF
#define SOAD_ISDEF_METADATARXBUFFERUSEDOFRXBUFFERCONFIG                                             STD_OFF
#define SOAD_ISDEF_TPRXBUFFERENDIDXOFRXBUFFERCONFIG                                                 STD_OFF
#define SOAD_ISDEF_TPRXBUFFERSTARTIDXOFRXBUFFERCONFIG                                               STD_OFF
#define SOAD_ISDEF_TPRXBUFFERUSEDOFRXBUFFERCONFIG                                                   STD_OFF
#define SOAD_ISDEF_INVALIDHNDOFRXPDUIDIDMAP                                                         STD_OFF
#define SOAD_ISDEF_PARTITIONSPECIFICSOCKETROUTEDESTIDXOFRXPDUIDIDMAP                                STD_OFF
#define SOAD_ISDEF_PARTITIONSPECIFICSOCKETROUTEDESTPARTITIONIDXOFRXPDUIDIDMAP                       STD_OFF
#define SOAD_ISDEF_SHUTDOWNFINISHEDCBK                                                              STD_OFF
#define SOAD_ISDEF_IPFRAGMGTIDXOFSOCON                                                              STD_OFF
#define SOAD_ISDEF_IPFRAGMGTUSEDOFSOCON                                                             STD_OFF
#define SOAD_ISDEF_LOCALIPADDRASSIGNMENTCHGCBKINDENDIDXOFSOCON                                      STD_OFF
#define SOAD_ISDEF_LOCALIPADDRASSIGNMENTCHGCBKINDSTARTIDXOFSOCON                                    STD_OFF
#define SOAD_ISDEF_LOCALIPADDRASSIGNMENTCHGCBKINDUSEDOFSOCON                                        STD_OFF
#define SOAD_ISDEF_NPDUUDPTXIDXOFSOCON                                                              STD_OFF
#define SOAD_ISDEF_NPDUUDPTXUSEDOFSOCON                                                             STD_OFF
#define SOAD_ISDEF_PDUROUTEDESTBYSOCONINDENDIDXOFSOCON                                              STD_OFF
#define SOAD_ISDEF_PDUROUTEDESTBYSOCONINDSTARTIDXOFSOCON                                            STD_OFF
#define SOAD_ISDEF_PDUROUTEDESTBYSOCONINDUSEDOFSOCON                                                STD_OFF
#define SOAD_ISDEF_REMADDRCFGSTATEOFSOCON                                                           STD_OFF
#define SOAD_ISDEF_REMADDRIPV4IDXOFSOCON                                                            STD_OFF
#define SOAD_ISDEF_REMADDRIPV4USEDOFSOCON                                                           STD_OFF
#define SOAD_ISDEF_REMADDRIPV6IDXOFSOCON                                                            STD_OFF
#define SOAD_ISDEF_REMADDRIPV6USEDOFSOCON                                                           STD_OFF
#define SOAD_ISDEF_REMADDRRCVIDXOFSOCON                                                             STD_OFF
#define SOAD_ISDEF_REMADDRRCVUSEDOFSOCON                                                            STD_OFF
#define SOAD_ISDEF_RXBUFSTRUCTMGTIDXOFSOCON                                                         STD_OFF
#define SOAD_ISDEF_RXBUFSTRUCTMGTUSEDOFSOCON                                                        STD_OFF
#define SOAD_ISDEF_RXBUFSTRUCTSEGENDIDXOFSOCON                                                      STD_OFF
#define SOAD_ISDEF_RXBUFSTRUCTSEGSTARTIDXOFSOCON                                                    STD_OFF
#define SOAD_ISDEF_RXBUFSTRUCTSEGUSEDOFSOCON                                                        STD_OFF
#define SOAD_ISDEF_RXBUFFERCONFIGIDXOFSOCON                                                         STD_OFF
#define SOAD_ISDEF_RXBUFFERCONFIGUSEDOFSOCON                                                        STD_OFF
#define SOAD_ISDEF_RXMGTIDXOFSOCON                                                                  STD_OFF
#define SOAD_ISDEF_RXMGTUSEDOFSOCON                                                                 STD_OFF
#define SOAD_ISDEF_SOCONGRPIDXOFSOCON                                                               STD_OFF
#define SOAD_ISDEF_SOCONIDOFSOCON                                                                   STD_OFF
#define SOAD_ISDEF_SOCONMODECHGCBKINDENDIDXOFSOCON                                                  STD_OFF
#define SOAD_ISDEF_SOCONMODECHGCBKINDSTARTIDXOFSOCON                                                STD_OFF
#define SOAD_ISDEF_SOCONMODECHGCBKINDUSEDOFSOCON                                                    STD_OFF
#define SOAD_ISDEF_SOCKETIDXOFSOCON                                                                 STD_OFF
#define SOAD_ISDEF_SOCKETROUTEENDIDXOFSOCON                                                         STD_OFF
#define SOAD_ISDEF_SOCKETROUTESTARTIDXOFSOCON                                                       STD_OFF
#define SOAD_ISDEF_SOCKETROUTEUSEDOFSOCON                                                           STD_OFF
#define SOAD_ISDEF_TCPTXQUEUEIDXOFSOCON                                                             STD_OFF
#define SOAD_ISDEF_TCPTXQUEUEUSEDOFSOCON                                                            STD_OFF
#define SOAD_ISDEF_TPTXBUFFERCONFIGIDXOFSOCON                                                       STD_OFF
#define SOAD_ISDEF_TPTXBUFFERCONFIGUSEDOFSOCON                                                      STD_OFF
#define SOAD_ISDEF_TXMGTIDXOFSOCON                                                                  STD_OFF
#define SOAD_ISDEF_TXMGTUSEDOFSOCON                                                                 STD_OFF
#define SOAD_ISDEF_BESTMATCHWITHPDUHEADERENABLEDOFSOCONGRP                                          STD_OFF
#define SOAD_ISDEF_BESTMATCHWITHSOCKROUTEENABLEDOFSOCONGRP                                          STD_OFF
#define SOAD_ISDEF_FRAMEPRIORITYOFSOCONGRP                                                          STD_OFF
#define SOAD_ISDEF_INSTANCEIDXOFSOCONGRP                                                            STD_OFF
#define SOAD_ISDEF_LOCALADDRIDXOFSOCONGRP                                                           STD_OFF
#define SOAD_ISDEF_LOCALADDRUSEDOFSOCONGRP                                                          STD_OFF
#define SOAD_ISDEF_LOCALPORTOFSOCONGRP                                                              STD_OFF
#define SOAD_ISDEF_MEASUREMENTDATASOMEIPSDTYPEOFSOCONGRP                                            STD_OFF
#define SOAD_ISDEF_MSGACCEPTFILTERENABLEDOFSOCONGRP                                                 STD_OFF
#define SOAD_ISDEF_PDUHDRENABLEDOFSOCONGRP                                                          STD_OFF
#define SOAD_ISDEF_SOCONENDIDXOFSOCONGRP                                                            STD_OFF
#define SOAD_ISDEF_SOCONSTARTIDXOFSOCONGRP                                                          STD_OFF
#define SOAD_ISDEF_SOCKAUTOSOCONSETUPKEEPONLINEOFSOCONGRP                                           STD_OFF
#define SOAD_ISDEF_SOCKAUTOSOCONSETUPOFSOCONGRP                                                     STD_OFF
#define SOAD_ISDEF_SOCKETIDXOFSOCONGRP                                                              STD_OFF
#define SOAD_ISDEF_SOCKETTCPIDXOFSOCONGRP                                                           STD_OFF
#define SOAD_ISDEF_SOCKETTCPUSEDOFSOCONGRP                                                          STD_OFF
#define SOAD_ISDEF_SOCKETUDPIDXOFSOCONGRP                                                           STD_OFF
#define SOAD_ISDEF_SOCKETUDPUSEDOFSOCONGRP                                                          STD_OFF
#define SOAD_ISDEF_SOCKETUSEDOFSOCONGRP                                                             STD_OFF
#define SOAD_ISDEF_INVALIDHNDOFSOCONMAP                                                             STD_OFF
#define SOAD_ISDEF_PARTITIONSPECIFICSOCONIDXOFSOCONMAP                                              STD_OFF
#define SOAD_ISDEF_PARTITIONSPECIFICSOCONPARTITIONIDXOFSOCONMAP                                     STD_OFF
#define SOAD_ISDEF_SOCONMODECHGCBK                                                                  STD_OFF
#define SOAD_ISDEF_SOCONMODECHGCBKIND                                                               STD_OFF
#define SOAD_ISDEF_SOCONENDIDXOFSOCKET                                                              STD_OFF
#define SOAD_ISDEF_SOCONSTARTIDXOFSOCKET                                                            STD_OFF
#define SOAD_ISDEF_METADATARXENABLEDOFSOCKETROUTE                                                   STD_OFF
#define SOAD_ISDEF_RXPDUHDRMETHODIDOFSOCKETROUTE                                                    STD_OFF
#define SOAD_ISDEF_RXPDUHDRSERVICEIDOFSOCKETROUTE                                                   STD_OFF
#define SOAD_ISDEF_SOCONIDXOFSOCKETROUTE                                                            STD_OFF
#define SOAD_ISDEF_SOCKETROUTEDESTENDIDXOFSOCKETROUTE                                               STD_OFF
#define SOAD_ISDEF_SOCKETROUTEDESTSTARTIDXOFSOCKETROUTE                                             STD_OFF
#define SOAD_ISDEF_UPPERLAYERAPIOFSOCKETROUTE                                                       STD_OFF
#define SOAD_ISDEF_ROUTEGRPSOCONBYSOCKETROUTEDESTINDENDIDXOFSOCKETROUTEDEST                         STD_OFF
#define SOAD_ISDEF_ROUTEGRPSOCONBYSOCKETROUTEDESTINDSTARTIDXOFSOCKETROUTEDEST                       STD_OFF
#define SOAD_ISDEF_ROUTEGRPSOCONBYSOCKETROUTEDESTINDUSEDOFSOCKETROUTEDEST                           STD_OFF
#define SOAD_ISDEF_RXPDUIDOFSOCKETROUTEDEST                                                         STD_OFF
#define SOAD_ISDEF_SOCKETROUTEIDXOFSOCKETROUTEDEST                                                  STD_OFF
#define SOAD_ISDEF_UPPERLAYERIDXOFSOCKETROUTEDEST                                                   STD_OFF
#define SOAD_ISDEF_SOCKETROUTEIND                                                                   STD_OFF
#define SOAD_ISDEF_IMMEDTPTXCONFOFSOCKETTCP                                                         STD_OFF
#define SOAD_ISDEF_TCPINITIATEOFSOCKETTCP                                                           STD_OFF
#define SOAD_ISDEF_TCPKEEPALIVEINTERVALOFSOCKETTCP                                                  STD_OFF
#define SOAD_ISDEF_TCPKEEPALIVEOFSOCKETTCP                                                          STD_OFF
#define SOAD_ISDEF_TCPKEEPALIVEPROBESMAXOFSOCKETTCP                                                 STD_OFF
#define SOAD_ISDEF_TCPKEEPALIVETIMEOFSOCKETTCP                                                      STD_OFF
#define SOAD_ISDEF_TCPMSLOFSOCKETTCP                                                                STD_OFF
#define SOAD_ISDEF_TCPNODELAYOFSOCKETTCP                                                            STD_OFF
#define SOAD_ISDEF_TCPRXBUFMINOFSOCKETTCP                                                           STD_OFF
#define SOAD_ISDEF_TCPTLSCONIDOFSOCKETTCP                                                           STD_OFF
#define SOAD_ISDEF_TCPTXBUFMINOFSOCKETTCP                                                           STD_OFF
#define SOAD_ISDEF_ALIVETIMEOUTMAXCNTOFSOCKETUDP                                                    STD_OFF
#define SOAD_ISDEF_CHECKSUMCHANGEENABLEDOFSOCKETUDP                                                 STD_OFF
#define SOAD_ISDEF_CHECKSUMENABLEDOFSOCKETUDP                                                       STD_OFF
#define SOAD_ISDEF_IMMEDIFTXCONFLISTSIZEOFSOCKETUDP                                                 STD_OFF
#define SOAD_ISDEF_IMMEDIFTXCONFOFSOCKETUDP                                                         STD_OFF
#define SOAD_ISDEF_NPDUUDPTXBUFFERMINOFSOCKETUDP                                                    STD_OFF
#define SOAD_ISDEF_NPDUUDPTXQUEUESIZEOFSOCKETUDP                                                    STD_OFF
#define SOAD_ISDEF_RETRYQUEUELIMITOFSOCKETUDP                                                       STD_OFF
#define SOAD_ISDEF_UDPLISTENONLYOFSOCKETUDP                                                         STD_OFF
#define SOAD_ISDEF_UDPSTRICTHDRLENCHECKENABLEDOFSOCKETUDP                                           STD_OFF
#define SOAD_ISDEF_UDPTRIGGERTIMEOUTOFSOCKETUDP                                                     STD_OFF
#define SOAD_ISDEF_LOCALADDRBYTCPIPCTRLINDENDIDXOFTCPIPCTRL                                         STD_OFF
#define SOAD_ISDEF_LOCALADDRBYTCPIPCTRLINDSTARTIDXOFTCPIPCTRL                                       STD_OFF
#define SOAD_ISDEF_LOCALADDRBYTCPIPCTRLINDUSEDOFTCPIPCTRL                                           STD_OFF
#define SOAD_ISDEF_RETRYENABLEDOFTCPIPCTRL                                                          STD_OFF
#define SOAD_ISDEF_TCPKEEPALIVEGLOBALLYENABLED                                                      STD_OFF
#define SOAD_ISDEF_TCPTXQUEUEDATAENDIDXOFTCPTXQUEUE                                                 STD_OFF
#define SOAD_ISDEF_TCPTXQUEUEDATASTARTIDXOFTCPTXQUEUE                                               STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTNPDUUDPTXCONFIGIDXOFTIMEOUTLISTIDENT                                  STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTNPDUUDPTXCONFIGUSEDOFTIMEOUTLISTIDENT                                 STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTTCPAUTOCONNECTCONFIGIDXOFTIMEOUTLISTIDENT                             STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTTCPAUTOCONNECTCONFIGUSEDOFTIMEOUTLISTIDENT                            STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTUDPALIVECONFIGIDXOFTIMEOUTLISTIDENT                                   STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTUDPALIVECONFIGUSEDOFTIMEOUTLISTIDENT                                  STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTMGMTIDXOFTIMEOUTLISTNPDUUDPTXCONFIG                                   STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTNPDUUDPTXENDIDXOFTIMEOUTLISTNPDUUDPTXCONFIG                           STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTNPDUUDPTXSTARTIDXOFTIMEOUTLISTNPDUUDPTXCONFIG                         STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTMGMTIDXOFTIMEOUTLISTTCPAUTOCONNECTCONFIG                              STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTMGMTIDXOFTIMEOUTLISTUDPALIVECONFIG                                    STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTUDPALIVEENDIDXOFTIMEOUTLISTUDPALIVECONFIG                             STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTUDPALIVESTARTIDXOFTIMEOUTLISTUDPALIVECONFIG                           STD_OFF
#define SOAD_ISDEF_TPTXBUFFERENDIDXOFTPTXBUFFERCONFIG                                               STD_OFF
#define SOAD_ISDEF_TPTXBUFFERSTARTIDXOFTPTXBUFFERCONFIG                                             STD_OFF
#define SOAD_ISDEF_TPTXBUFFERUSEDOFTPTXBUFFERCONFIG                                                 STD_OFF
#define SOAD_ISDEF_TRIGGERBUFENDIDXOFTRIGGERBUFCONFIG                                               STD_OFF
#define SOAD_ISDEF_TRIGGERBUFSTARTIDXOFTRIGGERBUFCONFIG                                             STD_OFF
#define SOAD_ISDEF_INVALIDHNDOFTXPDUIDMAP                                                           STD_OFF
#define SOAD_ISDEF_PARTITIONSPECIFICPDUROUTEIDXOFTXPDUIDMAP                                         STD_OFF
#define SOAD_ISDEF_PARTITIONSPECIFICPDUROUTEPARTITIONIDXOFTXPDUIDMAP                                STD_OFF
#define SOAD_ISDEF_IFRXINDICATIONCBKOFUPPERLAYER                                                    STD_OFF
#define SOAD_ISDEF_IFTRIGGERTRANSMITCBKOFUPPERLAYER                                                 STD_OFF
#define SOAD_ISDEF_IFTXCONFIRMATIONCBKOFUPPERLAYER                                                  STD_OFF
#define SOAD_ISDEF_TPCOPYRXDATACBKOFUPPERLAYER                                                      STD_OFF
#define SOAD_ISDEF_TPCOPYRXDATACONSTCBKOFUPPERLAYER                                                 STD_OFF
#define SOAD_ISDEF_TPCOPYTXDATACBKOFUPPERLAYER                                                      STD_OFF
#define SOAD_ISDEF_TPCOPYTXDATACONSTCBKOFUPPERLAYER                                                 STD_OFF
#define SOAD_ISDEF_TPRXINDICATIONCBKOFUPPERLAYER                                                    STD_OFF
#define SOAD_ISDEF_TPSTARTOFRECEPTIONCBKOFUPPERLAYER                                                STD_OFF
#define SOAD_ISDEF_TPSTARTOFRECEPTIONCONSTCBKOFUPPERLAYER                                           STD_OFF
#define SOAD_ISDEF_TPTXCONFIRMATIONCBKOFUPPERLAYER                                                  STD_OFF
#define SOAD_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                      STD_OFF
#define SOAD_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_OFF
#define SOAD_ISDEF_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                             STD_OFF
#define SOAD_ISDEF_BESTMATCHSOCONIDXLISTOFPCPARTITIONCONFIG                                         STD_OFF
#define SOAD_ISDEF_DHCPEVENTCBKOFPCPARTITIONCONFIG                                                  STD_OFF
#define SOAD_ISDEF_EVENTQUEUEFLAGOFPCPARTITIONCONFIG                                                STD_OFF
#define SOAD_ISDEF_EVENTQUEUEIDENTOFPCPARTITIONCONFIG                                               STD_OFF
#define SOAD_ISDEF_EVENTQUEUEIFTXROUTEGRPCONFIGOFPCPARTITIONCONFIG                                  STD_OFF
#define SOAD_ISDEF_EVENTQUEUEIFTXROUTEGRPOFPCPARTITIONCONFIG                                        STD_OFF
#define SOAD_ISDEF_EVENTQUEUEIFUDPPDUROUTECONFIGOFPCPARTITIONCONFIG                                 STD_OFF
#define SOAD_ISDEF_EVENTQUEUEIFUDPPDUROUTEOFPCPARTITIONCONFIG                                       STD_OFF
#define SOAD_ISDEF_EVENTQUEUEMGMTOFPCPARTITIONCONFIG                                                STD_OFF
#define SOAD_ISDEF_EVENTQUEUESTATESOCONCONFIGOFPCPARTITIONCONFIG                                    STD_OFF
#define SOAD_ISDEF_EVENTQUEUESTATESOCONOFPCPARTITIONCONFIG                                          STD_OFF
#define SOAD_ISDEF_EVENTQUEUETPRXSOCONCONFIGOFPCPARTITIONCONFIG                                     STD_OFF
#define SOAD_ISDEF_EVENTQUEUETPRXSOCONOFPCPARTITIONCONFIG                                           STD_OFF
#define SOAD_ISDEF_EVENTQUEUETPTXSOCONCONFIGOFPCPARTITIONCONFIG                                     STD_OFF
#define SOAD_ISDEF_EVENTQUEUETPTXSOCONOFPCPARTITIONCONFIG                                           STD_OFF
#define SOAD_ISDEF_IFRXBUFFEROFPCPARTITIONCONFIG                                                    STD_OFF
#define SOAD_ISDEF_INSTANCEDYNOFPCPARTITIONCONFIG                                                   STD_OFF
#define SOAD_ISDEF_INSTANCEMAPOFPCPARTITIONCONFIG                                                   STD_OFF
#define SOAD_ISDEF_INSTANCEOFPCPARTITIONCONFIG                                                      STD_OFF
#define SOAD_ISDEF_IPFRAGBUFCONFIGDYNOFPCPARTITIONCONFIG                                            STD_OFF
#define SOAD_ISDEF_IPFRAGBUFCONFIGOFPCPARTITIONCONFIG                                               STD_OFF
#define SOAD_ISDEF_IPFRAGBUFOFPCPARTITIONCONFIG                                                     STD_OFF
#define SOAD_ISDEF_IPFRAGMGTOFPCPARTITIONCONFIG                                                     STD_OFF
#define SOAD_ISDEF_LOCALADDRBYTCPIPCTRLINDOFPCPARTITIONCONFIG                                       STD_OFF
#define SOAD_ISDEF_LOCALADDRDYNOFPCPARTITIONCONFIG                                                  STD_OFF
#define SOAD_ISDEF_LOCALADDRIDMAPOFPCPARTITIONCONFIG                                                STD_OFF
#define SOAD_ISDEF_LOCALADDROFPCPARTITIONCONFIG                                                     STD_OFF
#define SOAD_ISDEF_LOCALIPADDRASSIGNMENTCHGCBKINDOFPCPARTITIONCONFIG                                STD_OFF
#define SOAD_ISDEF_LOCALIPADDRASSIGNMENTCHGCBKOFPCPARTITIONCONFIG                                   STD_OFF
#define SOAD_ISDEF_MAXIFROUTEGRPTRANSMITPDUSIZEOFPCPARTITIONCONFIG                                  STD_OFF
#define SOAD_ISDEF_METADATARXBUFFEROFPCPARTITIONCONFIG                                              STD_OFF
#define SOAD_ISDEF_NPDUUDPTXBUFFEROFPCPARTITIONCONFIG                                               STD_OFF
#define SOAD_ISDEF_NPDUUDPTXDYNOFPCPARTITIONCONFIG                                                  STD_OFF
#define SOAD_ISDEF_NPDUUDPTXOFPCPARTITIONCONFIG                                                     STD_OFF
#define SOAD_ISDEF_NPDUUDPTXQUEUEOFPCPARTITIONCONFIG                                                STD_OFF
#define SOAD_ISDEF_PARTITIONDYNOFPCPARTITIONCONFIG                                                  STD_OFF
#define SOAD_ISDEF_PDUROUTEDESTBYSOCONINDOFPCPARTITIONCONFIG                                        STD_OFF
#define SOAD_ISDEF_PDUROUTEDESTINDOFPCPARTITIONCONFIG                                               STD_OFF
#define SOAD_ISDEF_PDUROUTEDESTOFPCPARTITIONCONFIG                                                  STD_OFF
#define SOAD_ISDEF_PDUROUTEDYNOFPCPARTITIONCONFIG                                                   STD_OFF
#define SOAD_ISDEF_PDUROUTEOFPCPARTITIONCONFIG                                                      STD_OFF
#define SOAD_ISDEF_REMADDRIPV4OFPCPARTITIONCONFIG                                                   STD_OFF
#define SOAD_ISDEF_REMADDRIPV6OFPCPARTITIONCONFIG                                                   STD_OFF
#define SOAD_ISDEF_REMADDRRCVOFPCPARTITIONCONFIG                                                    STD_OFF
#define SOAD_ISDEF_ROUTEGRPIDMAPOFPCPARTITIONCONFIG                                                 STD_OFF
#define SOAD_ISDEF_ROUTEGRPOFPCPARTITIONCONFIG                                                      STD_OFF
#define SOAD_ISDEF_ROUTEGRPSOCONBYPDUROUTEDESTINDOFPCPARTITIONCONFIG                                STD_OFF
#define SOAD_ISDEF_ROUTEGRPSOCONBYSOCKETROUTEDESTINDOFPCPARTITIONCONFIG                             STD_OFF
#define SOAD_ISDEF_ROUTEGRPSOCONDYNOFPCPARTITIONCONFIG                                              STD_OFF
#define SOAD_ISDEF_ROUTEGRPSOCONOFPCPARTITIONCONFIG                                                 STD_OFF
#define SOAD_ISDEF_RXBUFSTRUCTMGTOFPCPARTITIONCONFIG                                                STD_OFF
#define SOAD_ISDEF_RXBUFSTRUCTSEGOFPCPARTITIONCONFIG                                                STD_OFF
#define SOAD_ISDEF_RXBUFFERCONFIGDYNOFPCPARTITIONCONFIG                                             STD_OFF
#define SOAD_ISDEF_RXBUFFERCONFIGOFPCPARTITIONCONFIG                                                STD_OFF
#define SOAD_ISDEF_RXMGTOFPCPARTITIONCONFIG                                                         STD_OFF
#define SOAD_ISDEF_RXPDUIDIDMAPOFPCPARTITIONCONFIG                                                  STD_OFF
#define SOAD_ISDEF_SHUTDOWNFINISHEDCBKOFPCPARTITIONCONFIG                                           STD_OFF
#define SOAD_ISDEF_SIZEOFBESTMATCHSOCONIDXLISTOFPCPARTITIONCONFIG                                   STD_OFF
#define SOAD_ISDEF_SIZEOFDHCPEVENTCBKOFPCPARTITIONCONFIG                                            STD_OFF
#define SOAD_ISDEF_SIZEOFEVENTQUEUEFLAGOFPCPARTITIONCONFIG                                          STD_OFF
#define SOAD_ISDEF_SIZEOFEVENTQUEUEIDENTOFPCPARTITIONCONFIG                                         STD_OFF
#define SOAD_ISDEF_SIZEOFEVENTQUEUEIFTXROUTEGRPCONFIGOFPCPARTITIONCONFIG                            STD_OFF
#define SOAD_ISDEF_SIZEOFEVENTQUEUEIFTXROUTEGRPOFPCPARTITIONCONFIG                                  STD_OFF
#define SOAD_ISDEF_SIZEOFEVENTQUEUEIFUDPPDUROUTECONFIGOFPCPARTITIONCONFIG                           STD_OFF
#define SOAD_ISDEF_SIZEOFEVENTQUEUEIFUDPPDUROUTEOFPCPARTITIONCONFIG                                 STD_OFF
#define SOAD_ISDEF_SIZEOFEVENTQUEUEMGMTOFPCPARTITIONCONFIG                                          STD_OFF
#define SOAD_ISDEF_SIZEOFEVENTQUEUESTATESOCONCONFIGOFPCPARTITIONCONFIG                              STD_OFF
#define SOAD_ISDEF_SIZEOFEVENTQUEUESTATESOCONOFPCPARTITIONCONFIG                                    STD_OFF
#define SOAD_ISDEF_SIZEOFEVENTQUEUETPRXSOCONCONFIGOFPCPARTITIONCONFIG                               STD_OFF
#define SOAD_ISDEF_SIZEOFEVENTQUEUETPRXSOCONOFPCPARTITIONCONFIG                                     STD_OFF
#define SOAD_ISDEF_SIZEOFEVENTQUEUETPTXSOCONCONFIGOFPCPARTITIONCONFIG                               STD_OFF
#define SOAD_ISDEF_SIZEOFEVENTQUEUETPTXSOCONOFPCPARTITIONCONFIG                                     STD_OFF
#define SOAD_ISDEF_SIZEOFIFRXBUFFEROFPCPARTITIONCONFIG                                              STD_OFF
#define SOAD_ISDEF_SIZEOFINSTANCEMAPOFPCPARTITIONCONFIG                                             STD_OFF
#define SOAD_ISDEF_SIZEOFINSTANCEOFPCPARTITIONCONFIG                                                STD_OFF
#define SOAD_ISDEF_SIZEOFIPFRAGBUFCONFIGOFPCPARTITIONCONFIG                                         STD_OFF
#define SOAD_ISDEF_SIZEOFIPFRAGBUFOFPCPARTITIONCONFIG                                               STD_OFF
#define SOAD_ISDEF_SIZEOFIPFRAGMGTOFPCPARTITIONCONFIG                                               STD_OFF
#define SOAD_ISDEF_SIZEOFLOCALADDRBYTCPIPCTRLINDOFPCPARTITIONCONFIG                                 STD_OFF
#define SOAD_ISDEF_SIZEOFLOCALADDRIDMAPOFPCPARTITIONCONFIG                                          STD_OFF
#define SOAD_ISDEF_SIZEOFLOCALADDROFPCPARTITIONCONFIG                                               STD_OFF
#define SOAD_ISDEF_SIZEOFLOCALIPADDRASSIGNMENTCHGCBKINDOFPCPARTITIONCONFIG                          STD_OFF
#define SOAD_ISDEF_SIZEOFLOCALIPADDRASSIGNMENTCHGCBKOFPCPARTITIONCONFIG                             STD_OFF
#define SOAD_ISDEF_SIZEOFMETADATARXBUFFEROFPCPARTITIONCONFIG                                        STD_OFF
#define SOAD_ISDEF_SIZEOFNPDUUDPTXBUFFEROFPCPARTITIONCONFIG                                         STD_OFF
#define SOAD_ISDEF_SIZEOFNPDUUDPTXOFPCPARTITIONCONFIG                                               STD_OFF
#define SOAD_ISDEF_SIZEOFNPDUUDPTXQUEUEOFPCPARTITIONCONFIG                                          STD_OFF
#define SOAD_ISDEF_SIZEOFPARTITIONDYNOFPCPARTITIONCONFIG                                            STD_OFF
#define SOAD_ISDEF_SIZEOFPDUROUTEDESTBYSOCONINDOFPCPARTITIONCONFIG                                  STD_OFF
#define SOAD_ISDEF_SIZEOFPDUROUTEDESTINDOFPCPARTITIONCONFIG                                         STD_OFF
#define SOAD_ISDEF_SIZEOFPDUROUTEDESTOFPCPARTITIONCONFIG                                            STD_OFF
#define SOAD_ISDEF_SIZEOFPDUROUTEOFPCPARTITIONCONFIG                                                STD_OFF
#define SOAD_ISDEF_SIZEOFREMADDRIPV4OFPCPARTITIONCONFIG                                             STD_OFF
#define SOAD_ISDEF_SIZEOFREMADDRIPV6OFPCPARTITIONCONFIG                                             STD_OFF
#define SOAD_ISDEF_SIZEOFREMADDRRCVOFPCPARTITIONCONFIG                                              STD_OFF
#define SOAD_ISDEF_SIZEOFROUTEGRPIDMAPOFPCPARTITIONCONFIG                                           STD_OFF
#define SOAD_ISDEF_SIZEOFROUTEGRPOFPCPARTITIONCONFIG                                                STD_OFF
#define SOAD_ISDEF_SIZEOFROUTEGRPSOCONBYPDUROUTEDESTINDOFPCPARTITIONCONFIG                          STD_OFF
#define SOAD_ISDEF_SIZEOFROUTEGRPSOCONBYSOCKETROUTEDESTINDOFPCPARTITIONCONFIG                       STD_OFF
#define SOAD_ISDEF_SIZEOFROUTEGRPSOCONOFPCPARTITIONCONFIG                                           STD_OFF
#define SOAD_ISDEF_SIZEOFRXBUFSTRUCTMGTOFPCPARTITIONCONFIG                                          STD_OFF
#define SOAD_ISDEF_SIZEOFRXBUFSTRUCTSEGOFPCPARTITIONCONFIG                                          STD_OFF
#define SOAD_ISDEF_SIZEOFRXBUFFERCONFIGOFPCPARTITIONCONFIG                                          STD_OFF
#define SOAD_ISDEF_SIZEOFRXMGTOFPCPARTITIONCONFIG                                                   STD_OFF
#define SOAD_ISDEF_SIZEOFRXPDUIDIDMAPOFPCPARTITIONCONFIG                                            STD_OFF
#define SOAD_ISDEF_SIZEOFSHUTDOWNFINISHEDCBKOFPCPARTITIONCONFIG                                     STD_OFF
#define SOAD_ISDEF_SIZEOFSOCONGRPOFPCPARTITIONCONFIG                                                STD_OFF
#define SOAD_ISDEF_SIZEOFSOCONMAPOFPCPARTITIONCONFIG                                                STD_OFF
#define SOAD_ISDEF_SIZEOFSOCONMODECHGCBKINDOFPCPARTITIONCONFIG                                      STD_OFF
#define SOAD_ISDEF_SIZEOFSOCONMODECHGCBKOFPCPARTITIONCONFIG                                         STD_OFF
#define SOAD_ISDEF_SIZEOFSOCONOFPCPARTITIONCONFIG                                                   STD_OFF
#define SOAD_ISDEF_SIZEOFSOCKETOFPCPARTITIONCONFIG                                                  STD_OFF
#define SOAD_ISDEF_SIZEOFSOCKETROUTEDESTOFPCPARTITIONCONFIG                                         STD_OFF
#define SOAD_ISDEF_SIZEOFSOCKETROUTEINDOFPCPARTITIONCONFIG                                          STD_OFF
#define SOAD_ISDEF_SIZEOFSOCKETROUTEOFPCPARTITIONCONFIG                                             STD_OFF
#define SOAD_ISDEF_SIZEOFSOCKETTCPOFPCPARTITIONCONFIG                                               STD_OFF
#define SOAD_ISDEF_SIZEOFSOCKETUDPOFPCPARTITIONCONFIG                                               STD_OFF
#define SOAD_ISDEF_SIZEOFTCPIPCTRLOFPCPARTITIONCONFIG                                               STD_OFF
#define SOAD_ISDEF_SIZEOFTCPKEEPALIVEGLOBALLYENABLEDOFPCPARTITIONCONFIG                             STD_OFF
#define SOAD_ISDEF_SIZEOFTCPTXQUEUEDATAOFPCPARTITIONCONFIG                                          STD_OFF
#define SOAD_ISDEF_SIZEOFTCPTXQUEUEOFPCPARTITIONCONFIG                                              STD_OFF
#define SOAD_ISDEF_SIZEOFTIMEOUTLISTIDENTOFPCPARTITIONCONFIG                                        STD_OFF
#define SOAD_ISDEF_SIZEOFTIMEOUTLISTMGMTOFPCPARTITIONCONFIG                                         STD_OFF
#define SOAD_ISDEF_SIZEOFTIMEOUTLISTNPDUUDPTXCONFIGOFPCPARTITIONCONFIG                              STD_OFF
#define SOAD_ISDEF_SIZEOFTIMEOUTLISTNPDUUDPTXMAPOFPCPARTITIONCONFIG                                 STD_OFF
#define SOAD_ISDEF_SIZEOFTIMEOUTLISTNPDUUDPTXOFPCPARTITIONCONFIG                                    STD_OFF
#define SOAD_ISDEF_SIZEOFTIMEOUTLISTTCPAUTOCONNECTCONFIGOFPCPARTITIONCONFIG                         STD_OFF
#define SOAD_ISDEF_SIZEOFTIMEOUTLISTUDPALIVECONFIGOFPCPARTITIONCONFIG                               STD_OFF
#define SOAD_ISDEF_SIZEOFTIMEOUTLISTUDPALIVEMAPOFPCPARTITIONCONFIG                                  STD_OFF
#define SOAD_ISDEF_SIZEOFTIMEOUTLISTUDPALIVEOFPCPARTITIONCONFIG                                     STD_OFF
#define SOAD_ISDEF_SIZEOFTPRXBUFFEROFPCPARTITIONCONFIG                                              STD_OFF
#define SOAD_ISDEF_SIZEOFTPTXBUFFERCONFIGOFPCPARTITIONCONFIG                                        STD_OFF
#define SOAD_ISDEF_SIZEOFTPTXBUFFEROFPCPARTITIONCONFIG                                              STD_OFF
#define SOAD_ISDEF_SIZEOFTRIGGERBUFCONFIGOFPCPARTITIONCONFIG                                        STD_OFF
#define SOAD_ISDEF_SIZEOFTRIGGERBUFOFPCPARTITIONCONFIG                                              STD_OFF
#define SOAD_ISDEF_SIZEOFTXMGTOFPCPARTITIONCONFIG                                                   STD_OFF
#define SOAD_ISDEF_SIZEOFTXPDUIDMAPOFPCPARTITIONCONFIG                                              STD_OFF
#define SOAD_ISDEF_SIZEOFUPPERLAYEROFPCPARTITIONCONFIG                                              STD_OFF
#define SOAD_ISDEF_SOCONDYNOFPCPARTITIONCONFIG                                                      STD_OFF
#define SOAD_ISDEF_SOCONGRPOFPCPARTITIONCONFIG                                                      STD_OFF
#define SOAD_ISDEF_SOCONMAPOFPCPARTITIONCONFIG                                                      STD_OFF
#define SOAD_ISDEF_SOCONMODECHGCBKINDOFPCPARTITIONCONFIG                                            STD_OFF
#define SOAD_ISDEF_SOCONMODECHGCBKOFPCPARTITIONCONFIG                                               STD_OFF
#define SOAD_ISDEF_SOCONOFPCPARTITIONCONFIG                                                         STD_OFF
#define SOAD_ISDEF_SOCKETDYNOFPCPARTITIONCONFIG                                                     STD_OFF
#define SOAD_ISDEF_SOCKETOFPCPARTITIONCONFIG                                                        STD_OFF
#define SOAD_ISDEF_SOCKETROUTEDESTOFPCPARTITIONCONFIG                                               STD_OFF
#define SOAD_ISDEF_SOCKETROUTEINDOFPCPARTITIONCONFIG                                                STD_OFF
#define SOAD_ISDEF_SOCKETROUTEOFPCPARTITIONCONFIG                                                   STD_OFF
#define SOAD_ISDEF_SOCKETTCPOFPCPARTITIONCONFIG                                                     STD_OFF
#define SOAD_ISDEF_SOCKETUDPOFPCPARTITIONCONFIG                                                     STD_OFF
#define SOAD_ISDEF_TCPIPCTRLOFPCPARTITIONCONFIG                                                     STD_OFF
#define SOAD_ISDEF_TCPKEEPALIVEGLOBALLYENABLEDOFPCPARTITIONCONFIG                                   STD_OFF
#define SOAD_ISDEF_TCPTXQUEUEDATAOFPCPARTITIONCONFIG                                                STD_OFF
#define SOAD_ISDEF_TCPTXQUEUEMGTOFPCPARTITIONCONFIG                                                 STD_OFF
#define SOAD_ISDEF_TCPTXQUEUEOFPCPARTITIONCONFIG                                                    STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTIDENTOFPCPARTITIONCONFIG                                              STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTMGMTOFPCPARTITIONCONFIG                                               STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTNPDUUDPTXCONFIGOFPCPARTITIONCONFIG                                    STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTNPDUUDPTXMAPOFPCPARTITIONCONFIG                                       STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTNPDUUDPTXOFPCPARTITIONCONFIG                                          STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTTCPAUTOCONNECTCONFIGOFPCPARTITIONCONFIG                               STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTUDPALIVECONFIGOFPCPARTITIONCONFIG                                     STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTUDPALIVEMAPOFPCPARTITIONCONFIG                                        STD_OFF
#define SOAD_ISDEF_TIMEOUTLISTUDPALIVEOFPCPARTITIONCONFIG                                           STD_OFF
#define SOAD_ISDEF_TPRXBUFFEROFPCPARTITIONCONFIG                                                    STD_OFF
#define SOAD_ISDEF_TPTXBUFFERCONFIGDYNOFPCPARTITIONCONFIG                                           STD_OFF
#define SOAD_ISDEF_TPTXBUFFERCONFIGOFPCPARTITIONCONFIG                                              STD_OFF
#define SOAD_ISDEF_TPTXBUFFEROFPCPARTITIONCONFIG                                                    STD_OFF
#define SOAD_ISDEF_TRIGGERBUFCONFIGDYNOFPCPARTITIONCONFIG                                           STD_OFF
#define SOAD_ISDEF_TRIGGERBUFCONFIGOFPCPARTITIONCONFIG                                              STD_OFF
#define SOAD_ISDEF_TRIGGERBUFOFPCPARTITIONCONFIG                                                    STD_OFF
#define SOAD_ISDEF_TXMGTOFPCPARTITIONCONFIG                                                         STD_OFF
#define SOAD_ISDEF_TXPDUIDMAPOFPCPARTITIONCONFIG                                                    STD_OFF
#define SOAD_ISDEF_UPPERLAYEROFPCPARTITIONCONFIG                                                    STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCEqualsAlwaysToDefines  SoAd Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define SOAD_EQ2_DHCPEVENTCBK                                                                       
#define SOAD_EQ2_EVENTQUEUEFLAGENDIDXOFEVENTQUEUEIDENT                                              
#define SOAD_EQ2_EVENTQUEUEFLAGSTARTIDXOFEVENTQUEUEIDENT                                            
#define SOAD_EQ2_EVENTQUEUEIFTXROUTEGRPCONFIGIDXOFEVENTQUEUEIDENT                                   
#define SOAD_EQ2_EVENTQUEUEIFTXROUTEGRPCONFIGUSEDOFEVENTQUEUEIDENT                                  
#define SOAD_EQ2_EVENTQUEUEIFUDPPDUROUTECONFIGIDXOFEVENTQUEUEIDENT                                  
#define SOAD_EQ2_EVENTQUEUEIFUDPPDUROUTECONFIGUSEDOFEVENTQUEUEIDENT                                 
#define SOAD_EQ2_EVENTQUEUESTATESOCONCONFIGIDXOFEVENTQUEUEIDENT                                     
#define SOAD_EQ2_EVENTQUEUETPRXSOCONCONFIGIDXOFEVENTQUEUEIDENT                                      
#define SOAD_EQ2_EVENTQUEUETPRXSOCONCONFIGUSEDOFEVENTQUEUEIDENT                                     
#define SOAD_EQ2_EVENTQUEUETPTXSOCONCONFIGIDXOFEVENTQUEUEIDENT                                      
#define SOAD_EQ2_EVENTQUEUETPTXSOCONCONFIGUSEDOFEVENTQUEUEIDENT                                     
#define SOAD_EQ2_EVENTQUEUEIFTXROUTEGRPENDIDXOFEVENTQUEUEIFTXROUTEGRPCONFIG                         
#define SOAD_EQ2_EVENTQUEUEIFTXROUTEGRPSTARTIDXOFEVENTQUEUEIFTXROUTEGRPCONFIG                       
#define SOAD_EQ2_EVENTQUEUEMGMTIDXOFEVENTQUEUEIFTXROUTEGRPCONFIG                                    
#define SOAD_EQ2_FLAGOFFSETOFEVENTQUEUEIFTXROUTEGRPCONFIG                                           
#define SOAD_EQ2_LIMITOFEVENTQUEUEIFTXROUTEGRPCONFIG                                                
#define SOAD_EQ2_EVENTQUEUEIFUDPPDUROUTEENDIDXOFEVENTQUEUEIFUDPPDUROUTECONFIG                       
#define SOAD_EQ2_EVENTQUEUEIFUDPPDUROUTESTARTIDXOFEVENTQUEUEIFUDPPDUROUTECONFIG                     
#define SOAD_EQ2_EVENTQUEUEMGMTIDXOFEVENTQUEUEIFUDPPDUROUTECONFIG                                   
#define SOAD_EQ2_FLAGOFFSETOFEVENTQUEUEIFUDPPDUROUTECONFIG                                          
#define SOAD_EQ2_LIMITOFEVENTQUEUEIFUDPPDUROUTECONFIG                                               
#define SOAD_EQ2_EVENTQUEUEMGMTIDXOFEVENTQUEUESTATESOCONCONFIG                                      
#define SOAD_EQ2_EVENTQUEUESTATESOCONENDIDXOFEVENTQUEUESTATESOCONCONFIG                             
#define SOAD_EQ2_EVENTQUEUESTATESOCONSTARTIDXOFEVENTQUEUESTATESOCONCONFIG                           
#define SOAD_EQ2_FLAGOFFSETOFEVENTQUEUESTATESOCONCONFIG                                             
#define SOAD_EQ2_LIMITOFEVENTQUEUESTATESOCONCONFIG                                                  
#define SOAD_EQ2_EVENTQUEUEMGMTIDXOFEVENTQUEUETPRXSOCONCONFIG                                       
#define SOAD_EQ2_EVENTQUEUETPRXSOCONENDIDXOFEVENTQUEUETPRXSOCONCONFIG                               
#define SOAD_EQ2_EVENTQUEUETPRXSOCONSTARTIDXOFEVENTQUEUETPRXSOCONCONFIG                             
#define SOAD_EQ2_FLAGOFFSETOFEVENTQUEUETPRXSOCONCONFIG                                              
#define SOAD_EQ2_LIMITOFEVENTQUEUETPRXSOCONCONFIG                                                   
#define SOAD_EQ2_EVENTQUEUEMGMTIDXOFEVENTQUEUETPTXSOCONCONFIG                                       
#define SOAD_EQ2_EVENTQUEUETPTXSOCONENDIDXOFEVENTQUEUETPTXSOCONCONFIG                               
#define SOAD_EQ2_EVENTQUEUETPTXSOCONSTARTIDXOFEVENTQUEUETPTXSOCONCONFIG                             
#define SOAD_EQ2_FLAGOFFSETOFEVENTQUEUETPTXSOCONCONFIG                                              
#define SOAD_EQ2_LIMITOFEVENTQUEUETPTXSOCONCONFIG                                                   
#define SOAD_EQ2_BESTMATCHSOCONIDXLISTENDIDXOFINSTANCE                                              
#define SOAD_EQ2_BESTMATCHSOCONIDXLISTSTARTIDXOFINSTANCE                                            
#define SOAD_EQ2_EVENTQUEUEIDENTIDXOFINSTANCE                                                       
#define SOAD_EQ2_IPFRAGBUFCONFIGENDIDXOFINSTANCE                                                    
#define SOAD_EQ2_IPFRAGBUFCONFIGSTARTIDXOFINSTANCE                                                  
#define SOAD_EQ2_IPFRAGBUFCONFIGUSEDOFINSTANCE                                                      
#define SOAD_EQ2_TIMEOUTLISTIDENTIDXOFINSTANCE                                                      
#define SOAD_EQ2_TRIGGERBUFCONFIGENDIDXOFINSTANCE                                                   
#define SOAD_EQ2_TRIGGERBUFCONFIGSTARTIDXOFINSTANCE                                                 
#define SOAD_EQ2_TRIGGERBUFCONFIGUSEDOFINSTANCE                                                     
#define SOAD_EQ2_PARTITIONSPECIFICINSTANCEIDXOFINSTANCEMAP                                          
#define SOAD_EQ2_PARTITIONSPECIFICINSTANCEPARTITIONIDXOFINSTANCEMAP                                 
#define SOAD_EQ2_IPFRAGBUFENDIDXOFIPFRAGBUFCONFIG                                                   
#define SOAD_EQ2_IPFRAGBUFSTARTIDXOFIPFRAGBUFCONFIG                                                 
#define SOAD_EQ2_ADDRIDOFLOCALADDR                                                                  
#define SOAD_EQ2_DOMAINOFLOCALADDR                                                                  
#define SOAD_EQ2_SOCONGRPENDIDXOFLOCALADDR                                                          
#define SOAD_EQ2_SOCONGRPSTARTIDXOFLOCALADDR                                                        
#define SOAD_EQ2_SOCONGRPUSEDOFLOCALADDR                                                            
#define SOAD_EQ2_TCPIPCTRLIDXOFLOCALADDR                                                            
#define SOAD_EQ2_LOCALADDRBYTCPIPCTRLIND                                                            
#define SOAD_EQ2_INVALIDHNDOFLOCALADDRIDMAP                                                         
#define SOAD_EQ2_PARTITIONSPECIFICLOCALADDRIDXOFLOCALADDRIDMAP                                      
#define SOAD_EQ2_PARTITIONSPECIFICLOCALADDRPARTITIONIDXOFLOCALADDRIDMAP                             
#define SOAD_EQ2_PARTITIONSPECIFICLOCALADDRUSEDOFLOCALADDRIDMAP                                     
#define SOAD_EQ2_LOCALIPADDRASSIGNMENTCHGCBK                                                        
#define SOAD_EQ2_LOCALIPADDRASSIGNMENTCHGCBKIND                                                     
#define SOAD_EQ2_NPDUUDPTXBUFFERENDIDXOFNPDUUDPTX                                                   
#define SOAD_EQ2_NPDUUDPTXBUFFERSTARTIDXOFNPDUUDPTX                                                 
#define SOAD_EQ2_NPDUUDPTXBUFFERUSEDOFNPDUUDPTX                                                     
#define SOAD_EQ2_NPDUUDPTXQUEUEENDIDXOFNPDUUDPTX                                                    
#define SOAD_EQ2_NPDUUDPTXQUEUESTARTIDXOFNPDUUDPTX                                                  
#define SOAD_EQ2_NPDUUDPTXQUEUEUSEDOFNPDUUDPTX                                                      
#define SOAD_EQ2_SOCONIDXOFNPDUUDPTX                                                                
#define SOAD_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                         
#define SOAD_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                 
#define SOAD_EQ2_ALLPDUROUTEDESTWITHPDUHDROFPDUROUTE                                                
#define SOAD_EQ2_IFOPTIMISTICTRANSMITOFPDUROUTE                                                     
#define SOAD_EQ2_IFTRIGGERTRANSMITMODEOFPDUROUTE                                                    
#define SOAD_EQ2_METADATATXENABLEDOFPDUROUTE                                                        
#define SOAD_EQ2_PDUROUTEDESTENDIDXOFPDUROUTE                                                       
#define SOAD_EQ2_PDUROUTEDESTSTARTIDXOFPDUROUTE                                                     
#define SOAD_EQ2_TXCONFENABLEDOFPDUROUTE                                                            
#define SOAD_EQ2_TXCONFPDUIDOFPDUROUTE                                                              
#define SOAD_EQ2_TXOPTIMIZEDOFPDUROUTE                                                              
#define SOAD_EQ2_UPPERLAYERAPIOFPDUROUTE                                                            
#define SOAD_EQ2_UPPERLAYERIDXOFPDUROUTE                                                            
#define SOAD_EQ2_PDUROUTEIDXOFPDUROUTEDEST                                                          
#define SOAD_EQ2_ROUTEGRPSOCONBYPDUROUTEDESTINDENDIDXOFPDUROUTEDEST                                 
#define SOAD_EQ2_ROUTEGRPSOCONBYPDUROUTEDESTINDSTARTIDXOFPDUROUTEDEST                               
#define SOAD_EQ2_ROUTEGRPSOCONBYPDUROUTEDESTINDUSEDOFPDUROUTEDEST                                   
#define SOAD_EQ2_SOCONIDXOFPDUROUTEDEST                                                             
#define SOAD_EQ2_TXPDUHDRIDOFPDUROUTEDEST                                                           
#define SOAD_EQ2_TXUDPTRIGGERMODEOFPDUROUTEDEST                                                     
#define SOAD_EQ2_UDPTRIGGERTIMEOUTOFPDUROUTEDEST                                                    
#define SOAD_EQ2_PDUROUTEDESTBYSOCONIND                                                             
#define SOAD_EQ2_PDUROUTEDESTIND                                                                    
#define SOAD_EQ2_ADDROFREMADDRIPV4                                                                  
#define SOAD_EQ2_PORTOFREMADDRIPV4                                                                  
#define SOAD_EQ2_ADDROFREMADDRIPV6                                                                  
#define SOAD_EQ2_PORTOFREMADDRIPV6                                                                  
#define SOAD_EQ2_ENABLEDATINITOFROUTEGRP                                                            
#define SOAD_EQ2_MULTIINSTANCEONGRPOFROUTEGRP                                                       
#define SOAD_EQ2_PDUROUTEDESTINDENDIDXOFROUTEGRP                                                    
#define SOAD_EQ2_PDUROUTEDESTINDSTARTIDXOFROUTEGRP                                                  
#define SOAD_EQ2_PDUROUTEDESTINDUSEDOFROUTEGRP                                                      
#define SOAD_EQ2_ROUTEGRPIDOFROUTEGRP                                                               
#define SOAD_EQ2_ROUTEGRPSOCONENDIDXOFROUTEGRP                                                      
#define SOAD_EQ2_ROUTEGRPSOCONSTARTIDXOFROUTEGRP                                                    
#define SOAD_EQ2_RXREQUESTENABLEOFROUTEGRP                                                          
#define SOAD_EQ2_SOCKETROUTEINDENDIDXOFROUTEGRP                                                     
#define SOAD_EQ2_SOCKETROUTEINDSTARTIDXOFROUTEGRP                                                   
#define SOAD_EQ2_SOCKETROUTEINDUSEDOFROUTEGRP                                                       
#define SOAD_EQ2_TXTRIGGERABLEOFROUTEGRP                                                            
#define SOAD_EQ2_INVALIDHNDOFROUTEGRPIDMAP                                                          
#define SOAD_EQ2_PARTITIONSPECIFICROUTEGRPIDXOFROUTEGRPIDMAP                                        
#define SOAD_EQ2_PARTITIONSPECIFICROUTEGRPPARTITIONIDXOFROUTEGRPIDMAP                               
#define SOAD_EQ2_PARTITIONSPECIFICROUTEGRPUSEDOFROUTEGRPIDMAP                                       
#define SOAD_EQ2_ROUTEGRPIDXOFROUTEGRPSOCON                                                         
#define SOAD_EQ2_SOCONIDXOFROUTEGRPSOCON                                                            
#define SOAD_EQ2_ROUTEGRPSOCONBYPDUROUTEDESTIND                                                     
#define SOAD_EQ2_ROUTEGRPSOCONBYSOCKETROUTEDESTIND                                                  
#define SOAD_EQ2_IFRXBUFFERENDIDXOFRXBUFFERCONFIG                                                   
#define SOAD_EQ2_IFRXBUFFERSTARTIDXOFRXBUFFERCONFIG                                                 
#define SOAD_EQ2_IFRXBUFFERUSEDOFRXBUFFERCONFIG                                                     
#define SOAD_EQ2_METADATARXBUFFERENDIDXOFRXBUFFERCONFIG                                             
#define SOAD_EQ2_METADATARXBUFFERSTARTIDXOFRXBUFFERCONFIG                                           
#define SOAD_EQ2_METADATARXBUFFERUSEDOFRXBUFFERCONFIG                                               
#define SOAD_EQ2_TPRXBUFFERENDIDXOFRXBUFFERCONFIG                                                   
#define SOAD_EQ2_TPRXBUFFERSTARTIDXOFRXBUFFERCONFIG                                                 
#define SOAD_EQ2_TPRXBUFFERUSEDOFRXBUFFERCONFIG                                                     
#define SOAD_EQ2_INVALIDHNDOFRXPDUIDIDMAP                                                           
#define SOAD_EQ2_PARTITIONSPECIFICSOCKETROUTEDESTIDXOFRXPDUIDIDMAP                                  
#define SOAD_EQ2_PARTITIONSPECIFICSOCKETROUTEDESTPARTITIONIDXOFRXPDUIDIDMAP                         
#define SOAD_EQ2_SHUTDOWNFINISHEDCBK                                                                
#define SOAD_EQ2_IPFRAGMGTIDXOFSOCON                                                                
#define SOAD_EQ2_IPFRAGMGTUSEDOFSOCON                                                               
#define SOAD_EQ2_LOCALIPADDRASSIGNMENTCHGCBKINDENDIDXOFSOCON                                        
#define SOAD_EQ2_LOCALIPADDRASSIGNMENTCHGCBKINDSTARTIDXOFSOCON                                      
#define SOAD_EQ2_LOCALIPADDRASSIGNMENTCHGCBKINDUSEDOFSOCON                                          
#define SOAD_EQ2_NPDUUDPTXIDXOFSOCON                                                                
#define SOAD_EQ2_NPDUUDPTXUSEDOFSOCON                                                               
#define SOAD_EQ2_PDUROUTEDESTBYSOCONINDENDIDXOFSOCON                                                
#define SOAD_EQ2_PDUROUTEDESTBYSOCONINDSTARTIDXOFSOCON                                              
#define SOAD_EQ2_PDUROUTEDESTBYSOCONINDUSEDOFSOCON                                                  
#define SOAD_EQ2_REMADDRCFGSTATEOFSOCON                                                             
#define SOAD_EQ2_REMADDRIPV4IDXOFSOCON                                                              
#define SOAD_EQ2_REMADDRIPV4USEDOFSOCON                                                             
#define SOAD_EQ2_REMADDRIPV6IDXOFSOCON                                                              
#define SOAD_EQ2_REMADDRIPV6USEDOFSOCON                                                             
#define SOAD_EQ2_REMADDRRCVIDXOFSOCON                                                               
#define SOAD_EQ2_REMADDRRCVUSEDOFSOCON                                                              
#define SOAD_EQ2_RXBUFSTRUCTMGTIDXOFSOCON                                                           
#define SOAD_EQ2_RXBUFSTRUCTMGTUSEDOFSOCON                                                          
#define SOAD_EQ2_RXBUFSTRUCTSEGENDIDXOFSOCON                                                        
#define SOAD_EQ2_RXBUFSTRUCTSEGSTARTIDXOFSOCON                                                      
#define SOAD_EQ2_RXBUFSTRUCTSEGUSEDOFSOCON                                                          
#define SOAD_EQ2_RXBUFFERCONFIGIDXOFSOCON                                                           
#define SOAD_EQ2_RXBUFFERCONFIGUSEDOFSOCON                                                          
#define SOAD_EQ2_RXMGTIDXOFSOCON                                                                    
#define SOAD_EQ2_RXMGTUSEDOFSOCON                                                                   
#define SOAD_EQ2_SOCONGRPIDXOFSOCON                                                                 
#define SOAD_EQ2_SOCONIDOFSOCON                                                                     
#define SOAD_EQ2_SOCONMODECHGCBKINDENDIDXOFSOCON                                                    
#define SOAD_EQ2_SOCONMODECHGCBKINDSTARTIDXOFSOCON                                                  
#define SOAD_EQ2_SOCONMODECHGCBKINDUSEDOFSOCON                                                      
#define SOAD_EQ2_SOCKETIDXOFSOCON                                                                   
#define SOAD_EQ2_SOCKETROUTEENDIDXOFSOCON                                                           
#define SOAD_EQ2_SOCKETROUTESTARTIDXOFSOCON                                                         
#define SOAD_EQ2_SOCKETROUTEUSEDOFSOCON                                                             
#define SOAD_EQ2_TCPTXQUEUEIDXOFSOCON                                                               
#define SOAD_EQ2_TCPTXQUEUEUSEDOFSOCON                                                              
#define SOAD_EQ2_TPTXBUFFERCONFIGIDXOFSOCON                                                         
#define SOAD_EQ2_TPTXBUFFERCONFIGUSEDOFSOCON                                                        
#define SOAD_EQ2_TXMGTIDXOFSOCON                                                                    
#define SOAD_EQ2_TXMGTUSEDOFSOCON                                                                   
#define SOAD_EQ2_BESTMATCHWITHPDUHEADERENABLEDOFSOCONGRP                                            
#define SOAD_EQ2_BESTMATCHWITHSOCKROUTEENABLEDOFSOCONGRP                                            
#define SOAD_EQ2_FRAMEPRIORITYOFSOCONGRP                                                            
#define SOAD_EQ2_INSTANCEIDXOFSOCONGRP                                                              
#define SOAD_EQ2_LOCALADDRIDXOFSOCONGRP                                                             
#define SOAD_EQ2_LOCALADDRUSEDOFSOCONGRP                                                            
#define SOAD_EQ2_LOCALPORTOFSOCONGRP                                                                
#define SOAD_EQ2_MEASUREMENTDATASOMEIPSDTYPEOFSOCONGRP                                              
#define SOAD_EQ2_MSGACCEPTFILTERENABLEDOFSOCONGRP                                                   
#define SOAD_EQ2_PDUHDRENABLEDOFSOCONGRP                                                            
#define SOAD_EQ2_SOCONENDIDXOFSOCONGRP                                                              
#define SOAD_EQ2_SOCONSTARTIDXOFSOCONGRP                                                            
#define SOAD_EQ2_SOCKAUTOSOCONSETUPKEEPONLINEOFSOCONGRP                                             
#define SOAD_EQ2_SOCKAUTOSOCONSETUPOFSOCONGRP                                                       
#define SOAD_EQ2_SOCKETIDXOFSOCONGRP                                                                
#define SOAD_EQ2_SOCKETTCPIDXOFSOCONGRP                                                             
#define SOAD_EQ2_SOCKETTCPUSEDOFSOCONGRP                                                            
#define SOAD_EQ2_SOCKETUDPIDXOFSOCONGRP                                                             
#define SOAD_EQ2_SOCKETUDPUSEDOFSOCONGRP                                                            
#define SOAD_EQ2_SOCKETUSEDOFSOCONGRP                                                               
#define SOAD_EQ2_INVALIDHNDOFSOCONMAP                                                               
#define SOAD_EQ2_PARTITIONSPECIFICSOCONIDXOFSOCONMAP                                                
#define SOAD_EQ2_PARTITIONSPECIFICSOCONPARTITIONIDXOFSOCONMAP                                       
#define SOAD_EQ2_SOCONMODECHGCBK                                                                    
#define SOAD_EQ2_SOCONMODECHGCBKIND                                                                 
#define SOAD_EQ2_SOCONENDIDXOFSOCKET                                                                
#define SOAD_EQ2_SOCONSTARTIDXOFSOCKET                                                              
#define SOAD_EQ2_METADATARXENABLEDOFSOCKETROUTE                                                     
#define SOAD_EQ2_RXPDUHDRMETHODIDOFSOCKETROUTE                                                      
#define SOAD_EQ2_RXPDUHDRSERVICEIDOFSOCKETROUTE                                                     
#define SOAD_EQ2_SOCONIDXOFSOCKETROUTE                                                              
#define SOAD_EQ2_SOCKETROUTEDESTENDIDXOFSOCKETROUTE                                                 
#define SOAD_EQ2_SOCKETROUTEDESTSTARTIDXOFSOCKETROUTE                                               
#define SOAD_EQ2_UPPERLAYERAPIOFSOCKETROUTE                                                         
#define SOAD_EQ2_ROUTEGRPSOCONBYSOCKETROUTEDESTINDENDIDXOFSOCKETROUTEDEST                           
#define SOAD_EQ2_ROUTEGRPSOCONBYSOCKETROUTEDESTINDSTARTIDXOFSOCKETROUTEDEST                         
#define SOAD_EQ2_ROUTEGRPSOCONBYSOCKETROUTEDESTINDUSEDOFSOCKETROUTEDEST                             
#define SOAD_EQ2_RXPDUIDOFSOCKETROUTEDEST                                                           
#define SOAD_EQ2_SOCKETROUTEIDXOFSOCKETROUTEDEST                                                    
#define SOAD_EQ2_UPPERLAYERIDXOFSOCKETROUTEDEST                                                     
#define SOAD_EQ2_SOCKETROUTEIND                                                                     
#define SOAD_EQ2_IMMEDTPTXCONFOFSOCKETTCP                                                           
#define SOAD_EQ2_TCPINITIATEOFSOCKETTCP                                                             
#define SOAD_EQ2_TCPKEEPALIVEINTERVALOFSOCKETTCP                                                    
#define SOAD_EQ2_TCPKEEPALIVEOFSOCKETTCP                                                            
#define SOAD_EQ2_TCPKEEPALIVEPROBESMAXOFSOCKETTCP                                                   
#define SOAD_EQ2_TCPKEEPALIVETIMEOFSOCKETTCP                                                        
#define SOAD_EQ2_TCPMSLOFSOCKETTCP                                                                  
#define SOAD_EQ2_TCPNODELAYOFSOCKETTCP                                                              
#define SOAD_EQ2_TCPRXBUFMINOFSOCKETTCP                                                             
#define SOAD_EQ2_TCPTLSCONIDOFSOCKETTCP                                                             
#define SOAD_EQ2_TCPTXBUFMINOFSOCKETTCP                                                             
#define SOAD_EQ2_ALIVETIMEOUTMAXCNTOFSOCKETUDP                                                      
#define SOAD_EQ2_CHECKSUMCHANGEENABLEDOFSOCKETUDP                                                   
#define SOAD_EQ2_CHECKSUMENABLEDOFSOCKETUDP                                                         
#define SOAD_EQ2_IMMEDIFTXCONFLISTSIZEOFSOCKETUDP                                                   
#define SOAD_EQ2_IMMEDIFTXCONFOFSOCKETUDP                                                           
#define SOAD_EQ2_NPDUUDPTXBUFFERMINOFSOCKETUDP                                                      
#define SOAD_EQ2_NPDUUDPTXQUEUESIZEOFSOCKETUDP                                                      
#define SOAD_EQ2_RETRYQUEUELIMITOFSOCKETUDP                                                         
#define SOAD_EQ2_UDPLISTENONLYOFSOCKETUDP                                                           
#define SOAD_EQ2_UDPSTRICTHDRLENCHECKENABLEDOFSOCKETUDP                                             
#define SOAD_EQ2_UDPTRIGGERTIMEOUTOFSOCKETUDP                                                       
#define SOAD_EQ2_LOCALADDRBYTCPIPCTRLINDENDIDXOFTCPIPCTRL                                           
#define SOAD_EQ2_LOCALADDRBYTCPIPCTRLINDSTARTIDXOFTCPIPCTRL                                         
#define SOAD_EQ2_LOCALADDRBYTCPIPCTRLINDUSEDOFTCPIPCTRL                                             
#define SOAD_EQ2_RETRYENABLEDOFTCPIPCTRL                                                            
#define SOAD_EQ2_TCPKEEPALIVEGLOBALLYENABLED                                                        
#define SOAD_EQ2_TCPTXQUEUEDATAENDIDXOFTCPTXQUEUE                                                   
#define SOAD_EQ2_TCPTXQUEUEDATASTARTIDXOFTCPTXQUEUE                                                 
#define SOAD_EQ2_TIMEOUTLISTNPDUUDPTXCONFIGIDXOFTIMEOUTLISTIDENT                                    
#define SOAD_EQ2_TIMEOUTLISTNPDUUDPTXCONFIGUSEDOFTIMEOUTLISTIDENT                                   
#define SOAD_EQ2_TIMEOUTLISTTCPAUTOCONNECTCONFIGIDXOFTIMEOUTLISTIDENT                               
#define SOAD_EQ2_TIMEOUTLISTTCPAUTOCONNECTCONFIGUSEDOFTIMEOUTLISTIDENT                              
#define SOAD_EQ2_TIMEOUTLISTUDPALIVECONFIGIDXOFTIMEOUTLISTIDENT                                     
#define SOAD_EQ2_TIMEOUTLISTUDPALIVECONFIGUSEDOFTIMEOUTLISTIDENT                                    
#define SOAD_EQ2_TIMEOUTLISTMGMTIDXOFTIMEOUTLISTNPDUUDPTXCONFIG                                     
#define SOAD_EQ2_TIMEOUTLISTNPDUUDPTXENDIDXOFTIMEOUTLISTNPDUUDPTXCONFIG                             
#define SOAD_EQ2_TIMEOUTLISTNPDUUDPTXSTARTIDXOFTIMEOUTLISTNPDUUDPTXCONFIG                           
#define SOAD_EQ2_TIMEOUTLISTMGMTIDXOFTIMEOUTLISTTCPAUTOCONNECTCONFIG                                
#define SOAD_EQ2_TIMEOUTLISTMGMTIDXOFTIMEOUTLISTUDPALIVECONFIG                                      
#define SOAD_EQ2_TIMEOUTLISTUDPALIVEENDIDXOFTIMEOUTLISTUDPALIVECONFIG                               
#define SOAD_EQ2_TIMEOUTLISTUDPALIVESTARTIDXOFTIMEOUTLISTUDPALIVECONFIG                             
#define SOAD_EQ2_TPTXBUFFERENDIDXOFTPTXBUFFERCONFIG                                                 
#define SOAD_EQ2_TPTXBUFFERSTARTIDXOFTPTXBUFFERCONFIG                                               
#define SOAD_EQ2_TPTXBUFFERUSEDOFTPTXBUFFERCONFIG                                                   
#define SOAD_EQ2_TRIGGERBUFENDIDXOFTRIGGERBUFCONFIG                                                 
#define SOAD_EQ2_TRIGGERBUFSTARTIDXOFTRIGGERBUFCONFIG                                               
#define SOAD_EQ2_INVALIDHNDOFTXPDUIDMAP                                                             
#define SOAD_EQ2_PARTITIONSPECIFICPDUROUTEIDXOFTXPDUIDMAP                                           
#define SOAD_EQ2_PARTITIONSPECIFICPDUROUTEPARTITIONIDXOFTXPDUIDMAP                                  
#define SOAD_EQ2_IFRXINDICATIONCBKOFUPPERLAYER                                                      
#define SOAD_EQ2_IFTRIGGERTRANSMITCBKOFUPPERLAYER                                                   
#define SOAD_EQ2_IFTXCONFIRMATIONCBKOFUPPERLAYER                                                    
#define SOAD_EQ2_TPCOPYRXDATACBKOFUPPERLAYER                                                        
#define SOAD_EQ2_TPCOPYRXDATACONSTCBKOFUPPERLAYER                                                   
#define SOAD_EQ2_TPCOPYTXDATACBKOFUPPERLAYER                                                        
#define SOAD_EQ2_TPCOPYTXDATACONSTCBKOFUPPERLAYER                                                   
#define SOAD_EQ2_TPRXINDICATIONCBKOFUPPERLAYER                                                      
#define SOAD_EQ2_TPSTARTOFRECEPTIONCBKOFUPPERLAYER                                                  
#define SOAD_EQ2_TPSTARTOFRECEPTIONCONSTCBKOFUPPERLAYER                                             
#define SOAD_EQ2_TPTXCONFIRMATIONCBKOFUPPERLAYER                                                    
#define SOAD_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                        
#define SOAD_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                     
#define SOAD_EQ2_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                               
#define SOAD_EQ2_BESTMATCHSOCONIDXLISTOFPCPARTITIONCONFIG                                           
#define SOAD_EQ2_DHCPEVENTCBKOFPCPARTITIONCONFIG                                                    
#define SOAD_EQ2_EVENTQUEUEFLAGOFPCPARTITIONCONFIG                                                  
#define SOAD_EQ2_EVENTQUEUEIDENTOFPCPARTITIONCONFIG                                                 
#define SOAD_EQ2_EVENTQUEUEIFTXROUTEGRPCONFIGOFPCPARTITIONCONFIG                                    
#define SOAD_EQ2_EVENTQUEUEIFTXROUTEGRPOFPCPARTITIONCONFIG                                          
#define SOAD_EQ2_EVENTQUEUEIFUDPPDUROUTECONFIGOFPCPARTITIONCONFIG                                   
#define SOAD_EQ2_EVENTQUEUEIFUDPPDUROUTEOFPCPARTITIONCONFIG                                         
#define SOAD_EQ2_EVENTQUEUEMGMTOFPCPARTITIONCONFIG                                                  
#define SOAD_EQ2_EVENTQUEUESTATESOCONCONFIGOFPCPARTITIONCONFIG                                      
#define SOAD_EQ2_EVENTQUEUESTATESOCONOFPCPARTITIONCONFIG                                            
#define SOAD_EQ2_EVENTQUEUETPRXSOCONCONFIGOFPCPARTITIONCONFIG                                       
#define SOAD_EQ2_EVENTQUEUETPRXSOCONOFPCPARTITIONCONFIG                                             
#define SOAD_EQ2_EVENTQUEUETPTXSOCONCONFIGOFPCPARTITIONCONFIG                                       
#define SOAD_EQ2_EVENTQUEUETPTXSOCONOFPCPARTITIONCONFIG                                             
#define SOAD_EQ2_IFRXBUFFEROFPCPARTITIONCONFIG                                                      
#define SOAD_EQ2_INSTANCEDYNOFPCPARTITIONCONFIG                                                     
#define SOAD_EQ2_INSTANCEMAPOFPCPARTITIONCONFIG                                                     
#define SOAD_EQ2_INSTANCEOFPCPARTITIONCONFIG                                                        
#define SOAD_EQ2_IPFRAGBUFCONFIGDYNOFPCPARTITIONCONFIG                                              
#define SOAD_EQ2_IPFRAGBUFCONFIGOFPCPARTITIONCONFIG                                                 
#define SOAD_EQ2_IPFRAGBUFOFPCPARTITIONCONFIG                                                       
#define SOAD_EQ2_IPFRAGMGTOFPCPARTITIONCONFIG                                                       
#define SOAD_EQ2_LOCALADDRBYTCPIPCTRLINDOFPCPARTITIONCONFIG                                         
#define SOAD_EQ2_LOCALADDRDYNOFPCPARTITIONCONFIG                                                    
#define SOAD_EQ2_LOCALADDRIDMAPOFPCPARTITIONCONFIG                                                  
#define SOAD_EQ2_LOCALADDROFPCPARTITIONCONFIG                                                       
#define SOAD_EQ2_LOCALIPADDRASSIGNMENTCHGCBKINDOFPCPARTITIONCONFIG                                  
#define SOAD_EQ2_LOCALIPADDRASSIGNMENTCHGCBKOFPCPARTITIONCONFIG                                     
#define SOAD_EQ2_MAXIFROUTEGRPTRANSMITPDUSIZEOFPCPARTITIONCONFIG                                    
#define SOAD_EQ2_METADATARXBUFFEROFPCPARTITIONCONFIG                                                
#define SOAD_EQ2_NPDUUDPTXBUFFEROFPCPARTITIONCONFIG                                                 
#define SOAD_EQ2_NPDUUDPTXDYNOFPCPARTITIONCONFIG                                                    
#define SOAD_EQ2_NPDUUDPTXOFPCPARTITIONCONFIG                                                       
#define SOAD_EQ2_NPDUUDPTXQUEUEOFPCPARTITIONCONFIG                                                  
#define SOAD_EQ2_PARTITIONDYNOFPCPARTITIONCONFIG                                                    
#define SOAD_EQ2_PDUROUTEDESTBYSOCONINDOFPCPARTITIONCONFIG                                          
#define SOAD_EQ2_PDUROUTEDESTINDOFPCPARTITIONCONFIG                                                 
#define SOAD_EQ2_PDUROUTEDESTOFPCPARTITIONCONFIG                                                    
#define SOAD_EQ2_PDUROUTEDYNOFPCPARTITIONCONFIG                                                     
#define SOAD_EQ2_PDUROUTEOFPCPARTITIONCONFIG                                                        
#define SOAD_EQ2_REMADDRIPV4OFPCPARTITIONCONFIG                                                     
#define SOAD_EQ2_REMADDRIPV6OFPCPARTITIONCONFIG                                                     
#define SOAD_EQ2_REMADDRRCVOFPCPARTITIONCONFIG                                                      
#define SOAD_EQ2_ROUTEGRPIDMAPOFPCPARTITIONCONFIG                                                   
#define SOAD_EQ2_ROUTEGRPOFPCPARTITIONCONFIG                                                        
#define SOAD_EQ2_ROUTEGRPSOCONBYPDUROUTEDESTINDOFPCPARTITIONCONFIG                                  
#define SOAD_EQ2_ROUTEGRPSOCONBYSOCKETROUTEDESTINDOFPCPARTITIONCONFIG                               
#define SOAD_EQ2_ROUTEGRPSOCONDYNOFPCPARTITIONCONFIG                                                
#define SOAD_EQ2_ROUTEGRPSOCONOFPCPARTITIONCONFIG                                                   
#define SOAD_EQ2_RXBUFSTRUCTMGTOFPCPARTITIONCONFIG                                                  
#define SOAD_EQ2_RXBUFSTRUCTSEGOFPCPARTITIONCONFIG                                                  
#define SOAD_EQ2_RXBUFFERCONFIGDYNOFPCPARTITIONCONFIG                                               
#define SOAD_EQ2_RXBUFFERCONFIGOFPCPARTITIONCONFIG                                                  
#define SOAD_EQ2_RXMGTOFPCPARTITIONCONFIG                                                           
#define SOAD_EQ2_RXPDUIDIDMAPOFPCPARTITIONCONFIG                                                    
#define SOAD_EQ2_SHUTDOWNFINISHEDCBKOFPCPARTITIONCONFIG                                             
#define SOAD_EQ2_SIZEOFBESTMATCHSOCONIDXLISTOFPCPARTITIONCONFIG                                     
#define SOAD_EQ2_SIZEOFDHCPEVENTCBKOFPCPARTITIONCONFIG                                              
#define SOAD_EQ2_SIZEOFEVENTQUEUEFLAGOFPCPARTITIONCONFIG                                            
#define SOAD_EQ2_SIZEOFEVENTQUEUEIDENTOFPCPARTITIONCONFIG                                           
#define SOAD_EQ2_SIZEOFEVENTQUEUEIFTXROUTEGRPCONFIGOFPCPARTITIONCONFIG                              
#define SOAD_EQ2_SIZEOFEVENTQUEUEIFTXROUTEGRPOFPCPARTITIONCONFIG                                    
#define SOAD_EQ2_SIZEOFEVENTQUEUEIFUDPPDUROUTECONFIGOFPCPARTITIONCONFIG                             
#define SOAD_EQ2_SIZEOFEVENTQUEUEIFUDPPDUROUTEOFPCPARTITIONCONFIG                                   
#define SOAD_EQ2_SIZEOFEVENTQUEUEMGMTOFPCPARTITIONCONFIG                                            
#define SOAD_EQ2_SIZEOFEVENTQUEUESTATESOCONCONFIGOFPCPARTITIONCONFIG                                
#define SOAD_EQ2_SIZEOFEVENTQUEUESTATESOCONOFPCPARTITIONCONFIG                                      
#define SOAD_EQ2_SIZEOFEVENTQUEUETPRXSOCONCONFIGOFPCPARTITIONCONFIG                                 
#define SOAD_EQ2_SIZEOFEVENTQUEUETPRXSOCONOFPCPARTITIONCONFIG                                       
#define SOAD_EQ2_SIZEOFEVENTQUEUETPTXSOCONCONFIGOFPCPARTITIONCONFIG                                 
#define SOAD_EQ2_SIZEOFEVENTQUEUETPTXSOCONOFPCPARTITIONCONFIG                                       
#define SOAD_EQ2_SIZEOFIFRXBUFFEROFPCPARTITIONCONFIG                                                
#define SOAD_EQ2_SIZEOFINSTANCEMAPOFPCPARTITIONCONFIG                                               
#define SOAD_EQ2_SIZEOFINSTANCEOFPCPARTITIONCONFIG                                                  
#define SOAD_EQ2_SIZEOFIPFRAGBUFCONFIGOFPCPARTITIONCONFIG                                           
#define SOAD_EQ2_SIZEOFIPFRAGBUFOFPCPARTITIONCONFIG                                                 
#define SOAD_EQ2_SIZEOFIPFRAGMGTOFPCPARTITIONCONFIG                                                 
#define SOAD_EQ2_SIZEOFLOCALADDRBYTCPIPCTRLINDOFPCPARTITIONCONFIG                                   
#define SOAD_EQ2_SIZEOFLOCALADDRIDMAPOFPCPARTITIONCONFIG                                            
#define SOAD_EQ2_SIZEOFLOCALADDROFPCPARTITIONCONFIG                                                 
#define SOAD_EQ2_SIZEOFLOCALIPADDRASSIGNMENTCHGCBKINDOFPCPARTITIONCONFIG                            
#define SOAD_EQ2_SIZEOFLOCALIPADDRASSIGNMENTCHGCBKOFPCPARTITIONCONFIG                               
#define SOAD_EQ2_SIZEOFMETADATARXBUFFEROFPCPARTITIONCONFIG                                          
#define SOAD_EQ2_SIZEOFNPDUUDPTXBUFFEROFPCPARTITIONCONFIG                                           
#define SOAD_EQ2_SIZEOFNPDUUDPTXOFPCPARTITIONCONFIG                                                 
#define SOAD_EQ2_SIZEOFNPDUUDPTXQUEUEOFPCPARTITIONCONFIG                                            
#define SOAD_EQ2_SIZEOFPARTITIONDYNOFPCPARTITIONCONFIG                                              
#define SOAD_EQ2_SIZEOFPDUROUTEDESTBYSOCONINDOFPCPARTITIONCONFIG                                    
#define SOAD_EQ2_SIZEOFPDUROUTEDESTINDOFPCPARTITIONCONFIG                                           
#define SOAD_EQ2_SIZEOFPDUROUTEDESTOFPCPARTITIONCONFIG                                              
#define SOAD_EQ2_SIZEOFPDUROUTEOFPCPARTITIONCONFIG                                                  
#define SOAD_EQ2_SIZEOFREMADDRIPV4OFPCPARTITIONCONFIG                                               
#define SOAD_EQ2_SIZEOFREMADDRIPV6OFPCPARTITIONCONFIG                                               
#define SOAD_EQ2_SIZEOFREMADDRRCVOFPCPARTITIONCONFIG                                                
#define SOAD_EQ2_SIZEOFROUTEGRPIDMAPOFPCPARTITIONCONFIG                                             
#define SOAD_EQ2_SIZEOFROUTEGRPOFPCPARTITIONCONFIG                                                  
#define SOAD_EQ2_SIZEOFROUTEGRPSOCONBYPDUROUTEDESTINDOFPCPARTITIONCONFIG                            
#define SOAD_EQ2_SIZEOFROUTEGRPSOCONBYSOCKETROUTEDESTINDOFPCPARTITIONCONFIG                         
#define SOAD_EQ2_SIZEOFROUTEGRPSOCONOFPCPARTITIONCONFIG                                             
#define SOAD_EQ2_SIZEOFRXBUFSTRUCTMGTOFPCPARTITIONCONFIG                                            
#define SOAD_EQ2_SIZEOFRXBUFSTRUCTSEGOFPCPARTITIONCONFIG                                            
#define SOAD_EQ2_SIZEOFRXBUFFERCONFIGOFPCPARTITIONCONFIG                                            
#define SOAD_EQ2_SIZEOFRXMGTOFPCPARTITIONCONFIG                                                     
#define SOAD_EQ2_SIZEOFRXPDUIDIDMAPOFPCPARTITIONCONFIG                                              
#define SOAD_EQ2_SIZEOFSHUTDOWNFINISHEDCBKOFPCPARTITIONCONFIG                                       
#define SOAD_EQ2_SIZEOFSOCONGRPOFPCPARTITIONCONFIG                                                  
#define SOAD_EQ2_SIZEOFSOCONMAPOFPCPARTITIONCONFIG                                                  
#define SOAD_EQ2_SIZEOFSOCONMODECHGCBKINDOFPCPARTITIONCONFIG                                        
#define SOAD_EQ2_SIZEOFSOCONMODECHGCBKOFPCPARTITIONCONFIG                                           
#define SOAD_EQ2_SIZEOFSOCONOFPCPARTITIONCONFIG                                                     
#define SOAD_EQ2_SIZEOFSOCKETOFPCPARTITIONCONFIG                                                    
#define SOAD_EQ2_SIZEOFSOCKETROUTEDESTOFPCPARTITIONCONFIG                                           
#define SOAD_EQ2_SIZEOFSOCKETROUTEINDOFPCPARTITIONCONFIG                                            
#define SOAD_EQ2_SIZEOFSOCKETROUTEOFPCPARTITIONCONFIG                                               
#define SOAD_EQ2_SIZEOFSOCKETTCPOFPCPARTITIONCONFIG                                                 
#define SOAD_EQ2_SIZEOFSOCKETUDPOFPCPARTITIONCONFIG                                                 
#define SOAD_EQ2_SIZEOFTCPIPCTRLOFPCPARTITIONCONFIG                                                 
#define SOAD_EQ2_SIZEOFTCPKEEPALIVEGLOBALLYENABLEDOFPCPARTITIONCONFIG                               
#define SOAD_EQ2_SIZEOFTCPTXQUEUEDATAOFPCPARTITIONCONFIG                                            
#define SOAD_EQ2_SIZEOFTCPTXQUEUEOFPCPARTITIONCONFIG                                                
#define SOAD_EQ2_SIZEOFTIMEOUTLISTIDENTOFPCPARTITIONCONFIG                                          
#define SOAD_EQ2_SIZEOFTIMEOUTLISTMGMTOFPCPARTITIONCONFIG                                           
#define SOAD_EQ2_SIZEOFTIMEOUTLISTNPDUUDPTXCONFIGOFPCPARTITIONCONFIG                                
#define SOAD_EQ2_SIZEOFTIMEOUTLISTNPDUUDPTXMAPOFPCPARTITIONCONFIG                                   
#define SOAD_EQ2_SIZEOFTIMEOUTLISTNPDUUDPTXOFPCPARTITIONCONFIG                                      
#define SOAD_EQ2_SIZEOFTIMEOUTLISTTCPAUTOCONNECTCONFIGOFPCPARTITIONCONFIG                           
#define SOAD_EQ2_SIZEOFTIMEOUTLISTUDPALIVECONFIGOFPCPARTITIONCONFIG                                 
#define SOAD_EQ2_SIZEOFTIMEOUTLISTUDPALIVEMAPOFPCPARTITIONCONFIG                                    
#define SOAD_EQ2_SIZEOFTIMEOUTLISTUDPALIVEOFPCPARTITIONCONFIG                                       
#define SOAD_EQ2_SIZEOFTPRXBUFFEROFPCPARTITIONCONFIG                                                
#define SOAD_EQ2_SIZEOFTPTXBUFFERCONFIGOFPCPARTITIONCONFIG                                          
#define SOAD_EQ2_SIZEOFTPTXBUFFEROFPCPARTITIONCONFIG                                                
#define SOAD_EQ2_SIZEOFTRIGGERBUFCONFIGOFPCPARTITIONCONFIG                                          
#define SOAD_EQ2_SIZEOFTRIGGERBUFOFPCPARTITIONCONFIG                                                
#define SOAD_EQ2_SIZEOFTXMGTOFPCPARTITIONCONFIG                                                     
#define SOAD_EQ2_SIZEOFTXPDUIDMAPOFPCPARTITIONCONFIG                                                
#define SOAD_EQ2_SIZEOFUPPERLAYEROFPCPARTITIONCONFIG                                                
#define SOAD_EQ2_SOCONDYNOFPCPARTITIONCONFIG                                                        
#define SOAD_EQ2_SOCONGRPOFPCPARTITIONCONFIG                                                        
#define SOAD_EQ2_SOCONMAPOFPCPARTITIONCONFIG                                                        
#define SOAD_EQ2_SOCONMODECHGCBKINDOFPCPARTITIONCONFIG                                              
#define SOAD_EQ2_SOCONMODECHGCBKOFPCPARTITIONCONFIG                                                 
#define SOAD_EQ2_SOCONOFPCPARTITIONCONFIG                                                           
#define SOAD_EQ2_SOCKETDYNOFPCPARTITIONCONFIG                                                       
#define SOAD_EQ2_SOCKETOFPCPARTITIONCONFIG                                                          
#define SOAD_EQ2_SOCKETROUTEDESTOFPCPARTITIONCONFIG                                                 
#define SOAD_EQ2_SOCKETROUTEINDOFPCPARTITIONCONFIG                                                  
#define SOAD_EQ2_SOCKETROUTEOFPCPARTITIONCONFIG                                                     
#define SOAD_EQ2_SOCKETTCPOFPCPARTITIONCONFIG                                                       
#define SOAD_EQ2_SOCKETUDPOFPCPARTITIONCONFIG                                                       
#define SOAD_EQ2_TCPIPCTRLOFPCPARTITIONCONFIG                                                       
#define SOAD_EQ2_TCPKEEPALIVEGLOBALLYENABLEDOFPCPARTITIONCONFIG                                     
#define SOAD_EQ2_TCPTXQUEUEDATAOFPCPARTITIONCONFIG                                                  
#define SOAD_EQ2_TCPTXQUEUEMGTOFPCPARTITIONCONFIG                                                   
#define SOAD_EQ2_TCPTXQUEUEOFPCPARTITIONCONFIG                                                      
#define SOAD_EQ2_TIMEOUTLISTIDENTOFPCPARTITIONCONFIG                                                
#define SOAD_EQ2_TIMEOUTLISTMGMTOFPCPARTITIONCONFIG                                                 
#define SOAD_EQ2_TIMEOUTLISTNPDUUDPTXCONFIGOFPCPARTITIONCONFIG                                      
#define SOAD_EQ2_TIMEOUTLISTNPDUUDPTXMAPOFPCPARTITIONCONFIG                                         
#define SOAD_EQ2_TIMEOUTLISTNPDUUDPTXOFPCPARTITIONCONFIG                                            
#define SOAD_EQ2_TIMEOUTLISTTCPAUTOCONNECTCONFIGOFPCPARTITIONCONFIG                                 
#define SOAD_EQ2_TIMEOUTLISTUDPALIVECONFIGOFPCPARTITIONCONFIG                                       
#define SOAD_EQ2_TIMEOUTLISTUDPALIVEMAPOFPCPARTITIONCONFIG                                          
#define SOAD_EQ2_TIMEOUTLISTUDPALIVEOFPCPARTITIONCONFIG                                             
#define SOAD_EQ2_TPRXBUFFEROFPCPARTITIONCONFIG                                                      
#define SOAD_EQ2_TPTXBUFFERCONFIGDYNOFPCPARTITIONCONFIG                                             
#define SOAD_EQ2_TPTXBUFFERCONFIGOFPCPARTITIONCONFIG                                                
#define SOAD_EQ2_TPTXBUFFEROFPCPARTITIONCONFIG                                                      
#define SOAD_EQ2_TRIGGERBUFCONFIGDYNOFPCPARTITIONCONFIG                                             
#define SOAD_EQ2_TRIGGERBUFCONFIGOFPCPARTITIONCONFIG                                                
#define SOAD_EQ2_TRIGGERBUFOFPCPARTITIONCONFIG                                                      
#define SOAD_EQ2_TXMGTOFPCPARTITIONCONFIG                                                           
#define SOAD_EQ2_TXPDUIDMAPOFPCPARTITIONCONFIG                                                      
#define SOAD_EQ2_UPPERLAYEROFPCPARTITIONCONFIG                                                      
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCSymbolicInitializationPointers  SoAd Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define SoAd_Config_Ptr                                                                             &(SoAd_PCConfig.Config)  /**< symbolic identifier which shall be used to initialize 'SoAd' */
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCInitializationSymbols  SoAd Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define SoAd_Config                                                                                 SoAd_PCConfig.Config  /**< symbolic identifier which could be used to initialize 'SoAd */
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCGeneral  SoAd General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define SOAD_CHECK_INIT_POINTER                                                                     STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define SOAD_FINAL_MAGIC_NUMBER                                                                     0x381Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of SoAd */
#define SOAD_INDIVIDUAL_POSTBUILD                                                                   STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'SoAd' is not configured to be postbuild capable. */
#define SOAD_INIT_DATA                                                                              SOAD_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define SOAD_INIT_DATA_HASH_CODE                                                                    1191833289  /**< the precompile constant to validate the initialization structure at initialization time of SoAd with a hashcode. The seed value is '0x381Eu' */
#define SOAD_USE_ECUM_BSW_ERROR_HOOK                                                                STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define SOAD_USE_INIT_POINTER                                                                       STD_ON  /**< STD_ON if the init pointer SoAd shall be used. */
#define SoAd_PartitionIndexOfCSLForSOAD_NO_OS_APPL_MAPPED                                           0u  /**< internal partition index of the ComStackLib for the partition SOAD_NO_OS_APPL_MAPPED */
/** 
  \}
*/ 



/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  SoAdPCGetRootDataMacros  SoAd Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define SoAd_GetPCPartitionConfigOfPCConfig()                                                       SoAd_ConfigDataPtr->PCPartitionConfigOfPCConfig
#define SoAd_GetPartitionIdentifiersOfPCConfig()                                                    SoAd_ConfigDataPtr->PartitionIdentifiersOfPCConfig
#define SoAd_GetSizeOfPartitionIdentifiersOfPCConfig()                                              SoAd_ConfigDataPtr->SizeOfPartitionIdentifiersOfPCConfig
#define SoAd_GetBestMatchSoConIdxListOfPCPartitionConfig(partitionIndex)                            SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].BestMatchSoConIdxListOfPCPartitionConfig
#define SoAd_GetDhcpEventCbkOfPCPartitionConfig()                                                   SoAd_GetPCPartitionConfigOfPCConfig()[(0)].DhcpEventCbkOfPCPartitionConfig
#define SoAd_GetEventQueueFlagOfPCPartitionConfig(partitionIndex)                                   SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventQueueFlagOfPCPartitionConfig
#define SoAd_GetEventQueueIdentOfPCPartitionConfig(partitionIndex)                                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventQueueIdentOfPCPartitionConfig
#define SoAd_GetEventQueueIfTxRouteGrpConfigOfPCPartitionConfig(partitionIndex)                     SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventQueueIfTxRouteGrpConfigOfPCPartitionConfig
#define SoAd_GetEventQueueIfTxRouteGrpOfPCPartitionConfig(partitionIndex)                           SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventQueueIfTxRouteGrpOfPCPartitionConfig
#define SoAd_GetEventQueueIfUdpPduRouteConfigOfPCPartitionConfig(partitionIndex)                    SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventQueueIfUdpPduRouteConfigOfPCPartitionConfig
#define SoAd_GetEventQueueIfUdpPduRouteOfPCPartitionConfig(partitionIndex)                          SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventQueueIfUdpPduRouteOfPCPartitionConfig
#define SoAd_GetEventQueueMgmtOfPCPartitionConfig(partitionIndex)                                   SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventQueueMgmtOfPCPartitionConfig
#define SoAd_GetEventQueueStateSoConConfigOfPCPartitionConfig(partitionIndex)                       SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventQueueStateSoConConfigOfPCPartitionConfig
#define SoAd_GetEventQueueStateSoConOfPCPartitionConfig(partitionIndex)                             SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventQueueStateSoConOfPCPartitionConfig
#define SoAd_GetEventQueueTpRxSoConConfigOfPCPartitionConfig(partitionIndex)                        SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventQueueTpRxSoConConfigOfPCPartitionConfig
#define SoAd_GetEventQueueTpRxSoConOfPCPartitionConfig(partitionIndex)                              SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventQueueTpRxSoConOfPCPartitionConfig
#define SoAd_GetEventQueueTpTxSoConConfigOfPCPartitionConfig(partitionIndex)                        SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventQueueTpTxSoConConfigOfPCPartitionConfig
#define SoAd_GetEventQueueTpTxSoConOfPCPartitionConfig(partitionIndex)                              SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].EventQueueTpTxSoConOfPCPartitionConfig
#define SoAd_GetIfRxBufferOfPCPartitionConfig(partitionIndex)                                       SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].IfRxBufferOfPCPartitionConfig
#define SoAd_GetInstanceDynOfPCPartitionConfig(partitionIndex)                                      SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].InstanceDynOfPCPartitionConfig
#define SoAd_GetInstanceMapOfPCPartitionConfig()                                                    SoAd_GetPCPartitionConfigOfPCConfig()[(0)].InstanceMapOfPCPartitionConfig
#define SoAd_GetInstanceOfPCPartitionConfig(partitionIndex)                                         SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].InstanceOfPCPartitionConfig
#define SoAd_GetIpFragBufConfigDynOfPCPartitionConfig(partitionIndex)                               SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].IpFragBufConfigDynOfPCPartitionConfig
#define SoAd_GetIpFragBufConfigOfPCPartitionConfig(partitionIndex)                                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].IpFragBufConfigOfPCPartitionConfig
#define SoAd_GetIpFragBufOfPCPartitionConfig(partitionIndex)                                        SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].IpFragBufOfPCPartitionConfig
#define SoAd_GetIpFragMgtOfPCPartitionConfig(partitionIndex)                                        SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].IpFragMgtOfPCPartitionConfig
#define SoAd_GetLocalAddrByTcpIpCtrlIndOfPCPartitionConfig(partitionIndex)                          SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].LocalAddrByTcpIpCtrlIndOfPCPartitionConfig
#define SoAd_GetLocalAddrDynOfPCPartitionConfig(partitionIndex)                                     SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].LocalAddrDynOfPCPartitionConfig
#define SoAd_GetLocalAddrIdMapOfPCPartitionConfig()                                                 SoAd_GetPCPartitionConfigOfPCConfig()[(0)].LocalAddrIdMapOfPCPartitionConfig
#define SoAd_GetLocalAddrOfPCPartitionConfig(partitionIndex)                                        SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].LocalAddrOfPCPartitionConfig
#define SoAd_GetLocalIpAddrAssignmentChgCbkIndOfPCPartitionConfig(partitionIndex)                   SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].LocalIpAddrAssignmentChgCbkIndOfPCPartitionConfig
#define SoAd_GetLocalIpAddrAssignmentChgCbkOfPCPartitionConfig()                                    SoAd_GetPCPartitionConfigOfPCConfig()[(0)].LocalIpAddrAssignmentChgCbkOfPCPartitionConfig
#define SoAd_GetMaxIfRouteGrpTransmitPduSizeOfPCPartitionConfig(partitionIndex)                     SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].MaxIfRouteGrpTransmitPduSizeOfPCPartitionConfig
#define SoAd_GetMetaDataRxBufferOfPCPartitionConfig(partitionIndex)                                 SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].MetaDataRxBufferOfPCPartitionConfig
#define SoAd_GetNPduUdpTxBufferOfPCPartitionConfig(partitionIndex)                                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].NPduUdpTxBufferOfPCPartitionConfig
#define SoAd_GetNPduUdpTxDynOfPCPartitionConfig(partitionIndex)                                     SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].NPduUdpTxDynOfPCPartitionConfig
#define SoAd_GetNPduUdpTxOfPCPartitionConfig(partitionIndex)                                        SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].NPduUdpTxOfPCPartitionConfig
#define SoAd_GetNPduUdpTxQueueOfPCPartitionConfig(partitionIndex)                                   SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].NPduUdpTxQueueOfPCPartitionConfig
#define SoAd_GetPartitionDynOfPCPartitionConfig(partitionIndex)                                     SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].PartitionDynOfPCPartitionConfig
#define SoAd_GetPduRouteDestBySoConIndOfPCPartitionConfig(partitionIndex)                           SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].PduRouteDestBySoConIndOfPCPartitionConfig
#define SoAd_GetPduRouteDestIndOfPCPartitionConfig(partitionIndex)                                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].PduRouteDestIndOfPCPartitionConfig
#define SoAd_GetPduRouteDestOfPCPartitionConfig(partitionIndex)                                     SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].PduRouteDestOfPCPartitionConfig
#define SoAd_GetPduRouteDynOfPCPartitionConfig(partitionIndex)                                      SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].PduRouteDynOfPCPartitionConfig
#define SoAd_GetPduRouteOfPCPartitionConfig(partitionIndex)                                         SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].PduRouteOfPCPartitionConfig
#define SoAd_GetRemAddrIpV4OfPCPartitionConfig(partitionIndex)                                      SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RemAddrIpV4OfPCPartitionConfig
#define SoAd_GetRemAddrIpV6OfPCPartitionConfig(partitionIndex)                                      SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RemAddrIpV6OfPCPartitionConfig
#define SoAd_GetRemAddrRcvOfPCPartitionConfig(partitionIndex)                                       SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RemAddrRcvOfPCPartitionConfig
#define SoAd_GetRouteGrpIdMapOfPCPartitionConfig()                                                  SoAd_GetPCPartitionConfigOfPCConfig()[(0)].RouteGrpIdMapOfPCPartitionConfig
#define SoAd_GetRouteGrpOfPCPartitionConfig(partitionIndex)                                         SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RouteGrpOfPCPartitionConfig
#define SoAd_GetRouteGrpSoConByPduRouteDestIndOfPCPartitionConfig(partitionIndex)                   SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RouteGrpSoConByPduRouteDestIndOfPCPartitionConfig
#define SoAd_GetRouteGrpSoConBySocketRouteDestIndOfPCPartitionConfig(partitionIndex)                SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RouteGrpSoConBySocketRouteDestIndOfPCPartitionConfig
#define SoAd_GetRouteGrpSoConDynOfPCPartitionConfig(partitionIndex)                                 SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RouteGrpSoConDynOfPCPartitionConfig
#define SoAd_GetRouteGrpSoConOfPCPartitionConfig(partitionIndex)                                    SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RouteGrpSoConOfPCPartitionConfig
#define SoAd_GetRxBufStructMgtOfPCPartitionConfig(partitionIndex)                                   SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RxBufStructMgtOfPCPartitionConfig
#define SoAd_GetRxBufStructSegOfPCPartitionConfig(partitionIndex)                                   SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RxBufStructSegOfPCPartitionConfig
#define SoAd_GetRxBufferConfigDynOfPCPartitionConfig(partitionIndex)                                SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RxBufferConfigDynOfPCPartitionConfig
#define SoAd_GetRxBufferConfigOfPCPartitionConfig(partitionIndex)                                   SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RxBufferConfigOfPCPartitionConfig
#define SoAd_GetRxMgtOfPCPartitionConfig(partitionIndex)                                            SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RxMgtOfPCPartitionConfig
#define SoAd_GetRxPduIdIdMapOfPCPartitionConfig()                                                   SoAd_GetPCPartitionConfigOfPCConfig()[(0)].RxPduIdIdMapOfPCPartitionConfig
#define SoAd_GetShutdownFinishedCbkOfPCPartitionConfig()                                            SoAd_GetPCPartitionConfigOfPCConfig()[(0)].ShutdownFinishedCbkOfPCPartitionConfig
#define SoAd_GetSizeOfBestMatchSoConIdxListOfPCPartitionConfig(partitionIndex)                      SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfBestMatchSoConIdxListOfPCPartitionConfig
#define SoAd_GetSizeOfDhcpEventCbkOfPCPartitionConfig()                                             SoAd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfDhcpEventCbkOfPCPartitionConfig
#define SoAd_GetSizeOfEventQueueFlagOfPCPartitionConfig(partitionIndex)                             SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventQueueFlagOfPCPartitionConfig
#define SoAd_GetSizeOfEventQueueIdentOfPCPartitionConfig(partitionIndex)                            SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventQueueIdentOfPCPartitionConfig
#define SoAd_GetSizeOfEventQueueIfTxRouteGrpConfigOfPCPartitionConfig(partitionIndex)               SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventQueueIfTxRouteGrpConfigOfPCPartitionConfig
#define SoAd_GetSizeOfEventQueueIfTxRouteGrpOfPCPartitionConfig(partitionIndex)                     SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventQueueIfTxRouteGrpOfPCPartitionConfig
#define SoAd_GetSizeOfEventQueueIfUdpPduRouteConfigOfPCPartitionConfig(partitionIndex)              SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventQueueIfUdpPduRouteConfigOfPCPartitionConfig
#define SoAd_GetSizeOfEventQueueIfUdpPduRouteOfPCPartitionConfig(partitionIndex)                    SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventQueueIfUdpPduRouteOfPCPartitionConfig
#define SoAd_GetSizeOfEventQueueMgmtOfPCPartitionConfig(partitionIndex)                             SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventQueueMgmtOfPCPartitionConfig
#define SoAd_GetSizeOfEventQueueStateSoConConfigOfPCPartitionConfig(partitionIndex)                 SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventQueueStateSoConConfigOfPCPartitionConfig
#define SoAd_GetSizeOfEventQueueStateSoConOfPCPartitionConfig(partitionIndex)                       SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventQueueStateSoConOfPCPartitionConfig
#define SoAd_GetSizeOfEventQueueTpRxSoConConfigOfPCPartitionConfig(partitionIndex)                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventQueueTpRxSoConConfigOfPCPartitionConfig
#define SoAd_GetSizeOfEventQueueTpRxSoConOfPCPartitionConfig(partitionIndex)                        SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventQueueTpRxSoConOfPCPartitionConfig
#define SoAd_GetSizeOfEventQueueTpTxSoConConfigOfPCPartitionConfig(partitionIndex)                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventQueueTpTxSoConConfigOfPCPartitionConfig
#define SoAd_GetSizeOfEventQueueTpTxSoConOfPCPartitionConfig(partitionIndex)                        SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfEventQueueTpTxSoConOfPCPartitionConfig
#define SoAd_GetSizeOfIfRxBufferOfPCPartitionConfig(partitionIndex)                                 SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfIfRxBufferOfPCPartitionConfig
#define SoAd_GetSizeOfInstanceMapOfPCPartitionConfig()                                              SoAd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfInstanceMapOfPCPartitionConfig
#define SoAd_GetSizeOfInstanceOfPCPartitionConfig(partitionIndex)                                   SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfInstanceOfPCPartitionConfig
#define SoAd_GetSizeOfIpFragBufConfigOfPCPartitionConfig(partitionIndex)                            SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfIpFragBufConfigOfPCPartitionConfig
#define SoAd_GetSizeOfIpFragBufOfPCPartitionConfig(partitionIndex)                                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfIpFragBufOfPCPartitionConfig
#define SoAd_GetSizeOfIpFragMgtOfPCPartitionConfig(partitionIndex)                                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfIpFragMgtOfPCPartitionConfig
#define SoAd_GetSizeOfLocalAddrByTcpIpCtrlIndOfPCPartitionConfig(partitionIndex)                    SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfLocalAddrByTcpIpCtrlIndOfPCPartitionConfig
#define SoAd_GetSizeOfLocalAddrIdMapOfPCPartitionConfig()                                           SoAd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfLocalAddrIdMapOfPCPartitionConfig
#define SoAd_GetSizeOfLocalAddrOfPCPartitionConfig(partitionIndex)                                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfLocalAddrOfPCPartitionConfig
#define SoAd_GetSizeOfLocalIpAddrAssignmentChgCbkIndOfPCPartitionConfig(partitionIndex)             SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfLocalIpAddrAssignmentChgCbkIndOfPCPartitionConfig
#define SoAd_GetSizeOfLocalIpAddrAssignmentChgCbkOfPCPartitionConfig()                              SoAd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfLocalIpAddrAssignmentChgCbkOfPCPartitionConfig
#define SoAd_GetSizeOfMetaDataRxBufferOfPCPartitionConfig(partitionIndex)                           SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfMetaDataRxBufferOfPCPartitionConfig
#define SoAd_GetSizeOfNPduUdpTxBufferOfPCPartitionConfig(partitionIndex)                            SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfNPduUdpTxBufferOfPCPartitionConfig
#define SoAd_GetSizeOfNPduUdpTxOfPCPartitionConfig(partitionIndex)                                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfNPduUdpTxOfPCPartitionConfig
#define SoAd_GetSizeOfNPduUdpTxQueueOfPCPartitionConfig(partitionIndex)                             SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfNPduUdpTxQueueOfPCPartitionConfig
#define SoAd_GetSizeOfPartitionDynOfPCPartitionConfig(partitionIndex)                               SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfPartitionDynOfPCPartitionConfig
#define SoAd_GetSizeOfPduRouteDestBySoConIndOfPCPartitionConfig(partitionIndex)                     SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfPduRouteDestBySoConIndOfPCPartitionConfig
#define SoAd_GetSizeOfPduRouteDestIndOfPCPartitionConfig(partitionIndex)                            SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfPduRouteDestIndOfPCPartitionConfig
#define SoAd_GetSizeOfPduRouteDestOfPCPartitionConfig(partitionIndex)                               SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfPduRouteDestOfPCPartitionConfig
#define SoAd_GetSizeOfPduRouteOfPCPartitionConfig(partitionIndex)                                   SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfPduRouteOfPCPartitionConfig
#define SoAd_GetSizeOfRemAddrIpV4OfPCPartitionConfig(partitionIndex)                                SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfRemAddrIpV4OfPCPartitionConfig
#define SoAd_GetSizeOfRemAddrIpV6OfPCPartitionConfig(partitionIndex)                                SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfRemAddrIpV6OfPCPartitionConfig
#define SoAd_GetSizeOfRemAddrRcvOfPCPartitionConfig(partitionIndex)                                 SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfRemAddrRcvOfPCPartitionConfig
#define SoAd_GetSizeOfRouteGrpIdMapOfPCPartitionConfig()                                            SoAd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfRouteGrpIdMapOfPCPartitionConfig
#define SoAd_GetSizeOfRouteGrpOfPCPartitionConfig(partitionIndex)                                   SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfRouteGrpOfPCPartitionConfig
#define SoAd_GetSizeOfRouteGrpSoConByPduRouteDestIndOfPCPartitionConfig(partitionIndex)             SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfRouteGrpSoConByPduRouteDestIndOfPCPartitionConfig
#define SoAd_GetSizeOfRouteGrpSoConBySocketRouteDestIndOfPCPartitionConfig(partitionIndex)          SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfRouteGrpSoConBySocketRouteDestIndOfPCPartitionConfig
#define SoAd_GetSizeOfRouteGrpSoConOfPCPartitionConfig(partitionIndex)                              SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfRouteGrpSoConOfPCPartitionConfig
#define SoAd_GetSizeOfRxBufStructMgtOfPCPartitionConfig(partitionIndex)                             SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfRxBufStructMgtOfPCPartitionConfig
#define SoAd_GetSizeOfRxBufStructSegOfPCPartitionConfig(partitionIndex)                             SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfRxBufStructSegOfPCPartitionConfig
#define SoAd_GetSizeOfRxBufferConfigOfPCPartitionConfig(partitionIndex)                             SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfRxBufferConfigOfPCPartitionConfig
#define SoAd_GetSizeOfRxMgtOfPCPartitionConfig(partitionIndex)                                      SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfRxMgtOfPCPartitionConfig
#define SoAd_GetSizeOfRxPduIdIdMapOfPCPartitionConfig()                                             SoAd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfRxPduIdIdMapOfPCPartitionConfig
#define SoAd_GetSizeOfShutdownFinishedCbkOfPCPartitionConfig()                                      SoAd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfShutdownFinishedCbkOfPCPartitionConfig
#define SoAd_GetSizeOfSoConGrpOfPCPartitionConfig(partitionIndex)                                   SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSoConGrpOfPCPartitionConfig
#define SoAd_GetSizeOfSoConMapOfPCPartitionConfig()                                                 SoAd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfSoConMapOfPCPartitionConfig
#define SoAd_GetSizeOfSoConModeChgCbkIndOfPCPartitionConfig(partitionIndex)                         SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSoConModeChgCbkIndOfPCPartitionConfig
#define SoAd_GetSizeOfSoConModeChgCbkOfPCPartitionConfig()                                          SoAd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfSoConModeChgCbkOfPCPartitionConfig
#define SoAd_GetSizeOfSoConOfPCPartitionConfig(partitionIndex)                                      SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSoConOfPCPartitionConfig
#define SoAd_GetSizeOfSocketOfPCPartitionConfig(partitionIndex)                                     SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSocketOfPCPartitionConfig
#define SoAd_GetSizeOfSocketRouteDestOfPCPartitionConfig(partitionIndex)                            SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSocketRouteDestOfPCPartitionConfig
#define SoAd_GetSizeOfSocketRouteIndOfPCPartitionConfig(partitionIndex)                             SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSocketRouteIndOfPCPartitionConfig
#define SoAd_GetSizeOfSocketRouteOfPCPartitionConfig(partitionIndex)                                SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSocketRouteOfPCPartitionConfig
#define SoAd_GetSizeOfSocketTcpOfPCPartitionConfig(partitionIndex)                                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSocketTcpOfPCPartitionConfig
#define SoAd_GetSizeOfSocketUdpOfPCPartitionConfig(partitionIndex)                                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSocketUdpOfPCPartitionConfig
#define SoAd_GetSizeOfTcpIpCtrlOfPCPartitionConfig(partitionIndex)                                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTcpIpCtrlOfPCPartitionConfig
#define SoAd_GetSizeOfTcpKeepAliveGloballyEnabledOfPCPartitionConfig()                              SoAd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfTcpKeepAliveGloballyEnabledOfPCPartitionConfig
#define SoAd_GetSizeOfTcpTxQueueDataOfPCPartitionConfig(partitionIndex)                             SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTcpTxQueueDataOfPCPartitionConfig
#define SoAd_GetSizeOfTcpTxQueueOfPCPartitionConfig(partitionIndex)                                 SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTcpTxQueueOfPCPartitionConfig
#define SoAd_GetSizeOfTimeoutListIdentOfPCPartitionConfig(partitionIndex)                           SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTimeoutListIdentOfPCPartitionConfig
#define SoAd_GetSizeOfTimeoutListMgmtOfPCPartitionConfig(partitionIndex)                            SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTimeoutListMgmtOfPCPartitionConfig
#define SoAd_GetSizeOfTimeoutListNPduUdpTxConfigOfPCPartitionConfig(partitionIndex)                 SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTimeoutListNPduUdpTxConfigOfPCPartitionConfig
#define SoAd_GetSizeOfTimeoutListNPduUdpTxMapOfPCPartitionConfig(partitionIndex)                    SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTimeoutListNPduUdpTxMapOfPCPartitionConfig
#define SoAd_GetSizeOfTimeoutListNPduUdpTxOfPCPartitionConfig(partitionIndex)                       SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTimeoutListNPduUdpTxOfPCPartitionConfig
#define SoAd_GetSizeOfTimeoutListTcpAutoConnectConfigOfPCPartitionConfig(partitionIndex)            SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTimeoutListTcpAutoConnectConfigOfPCPartitionConfig
#define SoAd_GetSizeOfTimeoutListUdpAliveConfigOfPCPartitionConfig(partitionIndex)                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTimeoutListUdpAliveConfigOfPCPartitionConfig
#define SoAd_GetSizeOfTimeoutListUdpAliveMapOfPCPartitionConfig(partitionIndex)                     SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTimeoutListUdpAliveMapOfPCPartitionConfig
#define SoAd_GetSizeOfTimeoutListUdpAliveOfPCPartitionConfig(partitionIndex)                        SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTimeoutListUdpAliveOfPCPartitionConfig
#define SoAd_GetSizeOfTpRxBufferOfPCPartitionConfig(partitionIndex)                                 SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTpRxBufferOfPCPartitionConfig
#define SoAd_GetSizeOfTpTxBufferConfigOfPCPartitionConfig(partitionIndex)                           SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTpTxBufferConfigOfPCPartitionConfig
#define SoAd_GetSizeOfTpTxBufferOfPCPartitionConfig(partitionIndex)                                 SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTpTxBufferOfPCPartitionConfig
#define SoAd_GetSizeOfTriggerBufConfigOfPCPartitionConfig(partitionIndex)                           SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTriggerBufConfigOfPCPartitionConfig
#define SoAd_GetSizeOfTriggerBufOfPCPartitionConfig(partitionIndex)                                 SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTriggerBufOfPCPartitionConfig
#define SoAd_GetSizeOfTxMgtOfPCPartitionConfig(partitionIndex)                                      SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTxMgtOfPCPartitionConfig
#define SoAd_GetSizeOfTxPduIdMapOfPCPartitionConfig()                                               SoAd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfTxPduIdMapOfPCPartitionConfig
#define SoAd_GetSizeOfUpperLayerOfPCPartitionConfig()                                               SoAd_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfUpperLayerOfPCPartitionConfig
#define SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)                                         SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SoConDynOfPCPartitionConfig
#define SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)                                         SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SoConGrpOfPCPartitionConfig
#define SoAd_GetSoConMapOfPCPartitionConfig()                                                       SoAd_GetPCPartitionConfigOfPCConfig()[(0)].SoConMapOfPCPartitionConfig
#define SoAd_GetSoConModeChgCbkIndOfPCPartitionConfig(partitionIndex)                               SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SoConModeChgCbkIndOfPCPartitionConfig
#define SoAd_GetSoConModeChgCbkOfPCPartitionConfig()                                                SoAd_GetPCPartitionConfigOfPCConfig()[(0)].SoConModeChgCbkOfPCPartitionConfig
#define SoAd_GetSoConOfPCPartitionConfig(partitionIndex)                                            SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SoConOfPCPartitionConfig
#define SoAd_GetSocketDynOfPCPartitionConfig(partitionIndex)                                        SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SocketDynOfPCPartitionConfig
#define SoAd_GetSocketOfPCPartitionConfig(partitionIndex)                                           SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SocketOfPCPartitionConfig
#define SoAd_GetSocketRouteDestOfPCPartitionConfig(partitionIndex)                                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SocketRouteDestOfPCPartitionConfig
#define SoAd_GetSocketRouteIndOfPCPartitionConfig(partitionIndex)                                   SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SocketRouteIndOfPCPartitionConfig
#define SoAd_GetSocketRouteOfPCPartitionConfig(partitionIndex)                                      SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SocketRouteOfPCPartitionConfig
#define SoAd_GetSocketTcpOfPCPartitionConfig(partitionIndex)                                        SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SocketTcpOfPCPartitionConfig
#define SoAd_GetSocketUdpOfPCPartitionConfig(partitionIndex)                                        SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SocketUdpOfPCPartitionConfig
#define SoAd_GetTcpIpCtrlOfPCPartitionConfig(partitionIndex)                                        SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TcpIpCtrlOfPCPartitionConfig
#define SoAd_GetTcpKeepAliveGloballyEnabledOfPCPartitionConfig()                                    SoAd_GetPCPartitionConfigOfPCConfig()[(0)].TcpKeepAliveGloballyEnabledOfPCPartitionConfig
#define SoAd_GetTcpTxQueueDataOfPCPartitionConfig(partitionIndex)                                   SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TcpTxQueueDataOfPCPartitionConfig
#define SoAd_GetTcpTxQueueMgtOfPCPartitionConfig(partitionIndex)                                    SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TcpTxQueueMgtOfPCPartitionConfig
#define SoAd_GetTcpTxQueueOfPCPartitionConfig(partitionIndex)                                       SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TcpTxQueueOfPCPartitionConfig
#define SoAd_GetTimeoutListIdentOfPCPartitionConfig(partitionIndex)                                 SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeoutListIdentOfPCPartitionConfig
#define SoAd_GetTimeoutListMgmtOfPCPartitionConfig(partitionIndex)                                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeoutListMgmtOfPCPartitionConfig
#define SoAd_GetTimeoutListNPduUdpTxConfigOfPCPartitionConfig(partitionIndex)                       SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeoutListNPduUdpTxConfigOfPCPartitionConfig
#define SoAd_GetTimeoutListNPduUdpTxMapOfPCPartitionConfig(partitionIndex)                          SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeoutListNPduUdpTxMapOfPCPartitionConfig
#define SoAd_GetTimeoutListNPduUdpTxOfPCPartitionConfig(partitionIndex)                             SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeoutListNPduUdpTxOfPCPartitionConfig
#define SoAd_GetTimeoutListTcpAutoConnectConfigOfPCPartitionConfig(partitionIndex)                  SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeoutListTcpAutoConnectConfigOfPCPartitionConfig
#define SoAd_GetTimeoutListUdpAliveConfigOfPCPartitionConfig(partitionIndex)                        SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeoutListUdpAliveConfigOfPCPartitionConfig
#define SoAd_GetTimeoutListUdpAliveMapOfPCPartitionConfig(partitionIndex)                           SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeoutListUdpAliveMapOfPCPartitionConfig
#define SoAd_GetTimeoutListUdpAliveOfPCPartitionConfig(partitionIndex)                              SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeoutListUdpAliveOfPCPartitionConfig
#define SoAd_GetTpRxBufferOfPCPartitionConfig(partitionIndex)                                       SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TpRxBufferOfPCPartitionConfig
#define SoAd_GetTpTxBufferConfigDynOfPCPartitionConfig(partitionIndex)                              SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TpTxBufferConfigDynOfPCPartitionConfig
#define SoAd_GetTpTxBufferConfigOfPCPartitionConfig(partitionIndex)                                 SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TpTxBufferConfigOfPCPartitionConfig
#define SoAd_GetTpTxBufferOfPCPartitionConfig(partitionIndex)                                       SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TpTxBufferOfPCPartitionConfig
#define SoAd_GetTriggerBufConfigDynOfPCPartitionConfig(partitionIndex)                              SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TriggerBufConfigDynOfPCPartitionConfig
#define SoAd_GetTriggerBufConfigOfPCPartitionConfig(partitionIndex)                                 SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TriggerBufConfigOfPCPartitionConfig
#define SoAd_GetTriggerBufOfPCPartitionConfig(partitionIndex)                                       SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TriggerBufOfPCPartitionConfig
#define SoAd_GetTxMgtOfPCPartitionConfig(partitionIndex)                                            SoAd_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TxMgtOfPCPartitionConfig
#define SoAd_GetTxPduIdMapOfPCPartitionConfig()                                                     SoAd_GetPCPartitionConfigOfPCConfig()[(0)].TxPduIdMapOfPCPartitionConfig
#define SoAd_GetUpperLayerOfPCPartitionConfig()                                                     SoAd_GetPCPartitionConfigOfPCConfig()[(0)].UpperLayerOfPCPartitionConfig
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCGetDuplicatedRootDataMacros  SoAd Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define SoAd_GetSizeOfInstanceDynOfPCPartitionConfig(partitionIndex)                                SoAd_GetSizeOfInstanceOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in SoAd_InstanceDyn */
#define SoAd_GetSizeOfIpFragBufConfigDynOfPCPartitionConfig(partitionIndex)                         SoAd_GetSizeOfIpFragBufConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in SoAd_IpFragBufConfigDyn */
#define SoAd_GetSizeOfLocalAddrDynOfPCPartitionConfig(partitionIndex)                               SoAd_GetSizeOfLocalAddrOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in SoAd_LocalAddrDyn */
#define SoAd_GetSizeOfNPduUdpTxDynOfPCPartitionConfig(partitionIndex)                               SoAd_GetSizeOfNPduUdpTxOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in SoAd_NPduUdpTxDyn */
#define SoAd_GetSizeOfPduRouteDynOfPCPartitionConfig(partitionIndex)                                SoAd_GetSizeOfPduRouteOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in SoAd_PduRouteDyn */
#define SoAd_GetSizeOfRouteGrpSoConDynOfPCPartitionConfig(partitionIndex)                           SoAd_GetSizeOfRouteGrpSoConOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in SoAd_RouteGrpSoConDyn */
#define SoAd_GetSizeOfRxBufferConfigDynOfPCPartitionConfig(partitionIndex)                          SoAd_GetSizeOfRxBufferConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in SoAd_RxBufferConfigDyn */
#define SoAd_GetSizeOfSoConDynOfPCPartitionConfig(partitionIndex)                                   SoAd_GetSizeOfSoConOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in SoAd_SoConDyn */
#define SoAd_GetSizeOfSocketDynOfPCPartitionConfig(partitionIndex)                                  SoAd_GetSizeOfSocketOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in SoAd_SocketDyn */
#define SoAd_GetSizeOfTcpTxQueueMgtOfPCPartitionConfig(partitionIndex)                              SoAd_GetSizeOfTcpTxQueueOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in SoAd_TcpTxQueueMgt */
#define SoAd_GetSizeOfTpTxBufferConfigDynOfPCPartitionConfig(partitionIndex)                        SoAd_GetSizeOfTpTxBufferConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in SoAd_TpTxBufferConfigDyn */
#define SoAd_GetSizeOfTriggerBufConfigDynOfPCPartitionConfig(partitionIndex)                        SoAd_GetSizeOfTriggerBufConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in SoAd_TriggerBufConfigDyn */
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCGetDataMacros  SoAd Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define SoAd_GetSoConIdxOfBestMatchSoConIdxList(Index, partitionIndex)                              (SoAd_GetBestMatchSoConIdxListOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdxOfBestMatchSoConIdxList)
#define SoAd_GetDhcpEventCbk(Index)                                                                 (SoAd_GetDhcpEventCbkOfPCPartitionConfig()[(Index)])
#define SoAd_GetEventQueueFlag(Index, partitionIndex)                                               (SoAd_GetEventQueueFlagOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_GetEventQueueFlagEndIdxOfEventQueueIdent(Index, partitionIndex)                        (SoAd_GetEventQueueIdentOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueFlagEndIdxOfEventQueueIdent)
#define SoAd_GetEventQueueFlagStartIdxOfEventQueueIdent(Index, partitionIndex)                      (SoAd_GetEventQueueIdentOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueFlagStartIdxOfEventQueueIdent)
#define SoAd_GetEventQueueIfTxRouteGrpConfigIdxOfEventQueueIdent(Index, partitionIndex)             (SoAd_GetEventQueueIdentOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueIfTxRouteGrpConfigIdxOfEventQueueIdent)
#define SoAd_GetEventQueueIfUdpPduRouteConfigIdxOfEventQueueIdent(Index, partitionIndex)            (SoAd_GetEventQueueIdentOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueIfUdpPduRouteConfigIdxOfEventQueueIdent)
#define SoAd_GetEventQueueStateSoConConfigIdxOfEventQueueIdent(Index, partitionIndex)               (SoAd_GetEventQueueIdentOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueStateSoConConfigIdxOfEventQueueIdent)
#define SoAd_GetEventQueueTpRxSoConConfigIdxOfEventQueueIdent(Index, partitionIndex)                (SoAd_GetEventQueueIdentOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueTpRxSoConConfigIdxOfEventQueueIdent)
#define SoAd_GetEventQueueTpTxSoConConfigIdxOfEventQueueIdent(Index, partitionIndex)                (SoAd_GetEventQueueIdentOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueTpTxSoConConfigIdxOfEventQueueIdent)
#define SoAd_GetRouteGrpIdxOfEventQueueIfTxRouteGrp(Index, partitionIndex)                          (SoAd_GetEventQueueIfTxRouteGrpOfPCPartitionConfig(partitionIndex)[(Index)].RouteGrpIdxOfEventQueueIfTxRouteGrp)
#define SoAd_GetEventQueueIfTxRouteGrpEndIdxOfEventQueueIfTxRouteGrpConfig(Index, partitionIndex)   (SoAd_GetEventQueueIfTxRouteGrpConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueIfTxRouteGrpEndIdxOfEventQueueIfTxRouteGrpConfig)
#define SoAd_GetEventQueueIfTxRouteGrpStartIdxOfEventQueueIfTxRouteGrpConfig(Index, partitionIndex) (SoAd_GetEventQueueIfTxRouteGrpConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueIfTxRouteGrpStartIdxOfEventQueueIfTxRouteGrpConfig)
#define SoAd_GetEventQueueMgmtIdxOfEventQueueIfTxRouteGrpConfig(Index, partitionIndex)              (SoAd_GetEventQueueIfTxRouteGrpConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueMgmtIdxOfEventQueueIfTxRouteGrpConfig)
#define SoAd_GetFlagOffsetOfEventQueueIfTxRouteGrpConfig(Index, partitionIndex)                     (SoAd_GetEventQueueIfTxRouteGrpConfigOfPCPartitionConfig(partitionIndex)[(Index)].FlagOffsetOfEventQueueIfTxRouteGrpConfig)
#define SoAd_GetLimitOfEventQueueIfTxRouteGrpConfig(Index, partitionIndex)                          (SoAd_GetEventQueueIfTxRouteGrpConfigOfPCPartitionConfig(partitionIndex)[(Index)].LimitOfEventQueueIfTxRouteGrpConfig)
#define SoAd_GetPduRouteIdxOfEventQueueIfUdpPduRoute(Index, partitionIndex)                         (SoAd_GetEventQueueIfUdpPduRouteOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteIdxOfEventQueueIfUdpPduRoute)
#define SoAd_GetEventQueueIfUdpPduRouteEndIdxOfEventQueueIfUdpPduRouteConfig(Index, partitionIndex) (SoAd_GetEventQueueIfUdpPduRouteConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueIfUdpPduRouteEndIdxOfEventQueueIfUdpPduRouteConfig)
#define SoAd_GetEventQueueIfUdpPduRouteStartIdxOfEventQueueIfUdpPduRouteConfig(Index, partitionIndex) (SoAd_GetEventQueueIfUdpPduRouteConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueIfUdpPduRouteStartIdxOfEventQueueIfUdpPduRouteConfig)
#define SoAd_GetEventQueueMgmtIdxOfEventQueueIfUdpPduRouteConfig(Index, partitionIndex)             (SoAd_GetEventQueueIfUdpPduRouteConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueMgmtIdxOfEventQueueIfUdpPduRouteConfig)
#define SoAd_GetFlagOffsetOfEventQueueIfUdpPduRouteConfig(Index, partitionIndex)                    (SoAd_GetEventQueueIfUdpPduRouteConfigOfPCPartitionConfig(partitionIndex)[(Index)].FlagOffsetOfEventQueueIfUdpPduRouteConfig)
#define SoAd_GetLimitOfEventQueueIfUdpPduRouteConfig(Index, partitionIndex)                         (SoAd_GetEventQueueIfUdpPduRouteConfigOfPCPartitionConfig(partitionIndex)[(Index)].LimitOfEventQueueIfUdpPduRouteConfig)
#define SoAd_GetIdxOfEventQueueMgmt(Index, partitionIndex)                                          (SoAd_GetEventQueueMgmtOfPCPartitionConfig(partitionIndex)[(Index)].IdxOfEventQueueMgmt)
#define SoAd_GetLvlOfEventQueueMgmt(Index, partitionIndex)                                          (SoAd_GetEventQueueMgmtOfPCPartitionConfig(partitionIndex)[(Index)].LvlOfEventQueueMgmt)
#define SoAd_GetSoConIdxOfEventQueueStateSoCon(Index, partitionIndex)                               (SoAd_GetEventQueueStateSoConOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdxOfEventQueueStateSoCon)
#define SoAd_GetEventQueueMgmtIdxOfEventQueueStateSoConConfig(Index, partitionIndex)                (SoAd_GetEventQueueStateSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueMgmtIdxOfEventQueueStateSoConConfig)
#define SoAd_GetEventQueueStateSoConEndIdxOfEventQueueStateSoConConfig(Index, partitionIndex)       (SoAd_GetEventQueueStateSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueStateSoConEndIdxOfEventQueueStateSoConConfig)
#define SoAd_GetEventQueueStateSoConStartIdxOfEventQueueStateSoConConfig(Index, partitionIndex)     (SoAd_GetEventQueueStateSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueStateSoConStartIdxOfEventQueueStateSoConConfig)
#define SoAd_GetFlagOffsetOfEventQueueStateSoConConfig(Index, partitionIndex)                       (SoAd_GetEventQueueStateSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].FlagOffsetOfEventQueueStateSoConConfig)
#define SoAd_GetLimitOfEventQueueStateSoConConfig(Index, partitionIndex)                            (SoAd_GetEventQueueStateSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].LimitOfEventQueueStateSoConConfig)
#define SoAd_GetSoConIdxOfEventQueueTpRxSoCon(Index, partitionIndex)                                (SoAd_GetEventQueueTpRxSoConOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdxOfEventQueueTpRxSoCon)
#define SoAd_GetEventQueueMgmtIdxOfEventQueueTpRxSoConConfig(Index, partitionIndex)                 (SoAd_GetEventQueueTpRxSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueMgmtIdxOfEventQueueTpRxSoConConfig)
#define SoAd_GetEventQueueTpRxSoConEndIdxOfEventQueueTpRxSoConConfig(Index, partitionIndex)         (SoAd_GetEventQueueTpRxSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueTpRxSoConEndIdxOfEventQueueTpRxSoConConfig)
#define SoAd_GetEventQueueTpRxSoConStartIdxOfEventQueueTpRxSoConConfig(Index, partitionIndex)       (SoAd_GetEventQueueTpRxSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueTpRxSoConStartIdxOfEventQueueTpRxSoConConfig)
#define SoAd_GetFlagOffsetOfEventQueueTpRxSoConConfig(Index, partitionIndex)                        (SoAd_GetEventQueueTpRxSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].FlagOffsetOfEventQueueTpRxSoConConfig)
#define SoAd_GetLimitOfEventQueueTpRxSoConConfig(Index, partitionIndex)                             (SoAd_GetEventQueueTpRxSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].LimitOfEventQueueTpRxSoConConfig)
#define SoAd_GetSoConIdxOfEventQueueTpTxSoCon(Index, partitionIndex)                                (SoAd_GetEventQueueTpTxSoConOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdxOfEventQueueTpTxSoCon)
#define SoAd_GetEventQueueMgmtIdxOfEventQueueTpTxSoConConfig(Index, partitionIndex)                 (SoAd_GetEventQueueTpTxSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueMgmtIdxOfEventQueueTpTxSoConConfig)
#define SoAd_GetEventQueueTpTxSoConEndIdxOfEventQueueTpTxSoConConfig(Index, partitionIndex)         (SoAd_GetEventQueueTpTxSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueTpTxSoConEndIdxOfEventQueueTpTxSoConConfig)
#define SoAd_GetEventQueueTpTxSoConStartIdxOfEventQueueTpTxSoConConfig(Index, partitionIndex)       (SoAd_GetEventQueueTpTxSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueTpTxSoConStartIdxOfEventQueueTpTxSoConConfig)
#define SoAd_GetFlagOffsetOfEventQueueTpTxSoConConfig(Index, partitionIndex)                        (SoAd_GetEventQueueTpTxSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].FlagOffsetOfEventQueueTpTxSoConConfig)
#define SoAd_GetLimitOfEventQueueTpTxSoConConfig(Index, partitionIndex)                             (SoAd_GetEventQueueTpTxSoConConfigOfPCPartitionConfig(partitionIndex)[(Index)].LimitOfEventQueueTpTxSoConConfig)
#define SoAd_GetIfRxBuffer(Index, partitionIndex)                                                   (SoAd_GetIfRxBufferOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_GetBestMatchSoConIdxListEndIdxOfInstance(Index, partitionIndex)                        (SoAd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].BestMatchSoConIdxListEndIdxOfInstance)
#define SoAd_GetBestMatchSoConIdxListStartIdxOfInstance(Index, partitionIndex)                      (SoAd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].BestMatchSoConIdxListStartIdxOfInstance)
#define SoAd_GetEventQueueIdentIdxOfInstance(Index, partitionIndex)                                 (SoAd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].EventQueueIdentIdxOfInstance)
#define SoAd_GetIpFragBufConfigEndIdxOfInstance(Index, partitionIndex)                              (SoAd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].IpFragBufConfigEndIdxOfInstance)
#define SoAd_GetIpFragBufConfigStartIdxOfInstance(Index, partitionIndex)                            (SoAd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].IpFragBufConfigStartIdxOfInstance)
#define SoAd_GetTimeoutListIdentIdxOfInstance(Index, partitionIndex)                                (SoAd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListIdentIdxOfInstance)
#define SoAd_GetTriggerBufConfigEndIdxOfInstance(Index, partitionIndex)                             (SoAd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].TriggerBufConfigEndIdxOfInstance)
#define SoAd_GetTriggerBufConfigStartIdxOfInstance(Index, partitionIndex)                           (SoAd_GetInstanceOfPCPartitionConfig(partitionIndex)[(Index)].TriggerBufConfigStartIdxOfInstance)
#define SoAd_GetBestMatchListSizeOfInstanceDyn(Index, partitionIndex)                               (SoAd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].BestMatchListSizeOfInstanceDyn)
#define SoAd_GetCounterOfInstanceDyn(Index, partitionIndex)                                         (SoAd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].CounterOfInstanceDyn)
#define SoAd_GetOpenSocksOfInstanceDyn(Index, partitionIndex)                                       (SoAd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].OpenSocksOfInstanceDyn)
#define SoAd_GetPartitionSpecificInstanceIdxOfInstanceMap(Index)                                    (SoAd_GetInstanceMapOfPCPartitionConfig()[(Index)].PartitionSpecificInstanceIdxOfInstanceMap)
#define SoAd_GetPartitionSpecificInstancePartitionIdxOfInstanceMap(Index)                           (SoAd_GetInstanceMapOfPCPartitionConfig()[(Index)].PartitionSpecificInstancePartitionIdxOfInstanceMap)
#define SoAd_GetIpFragBuf(Index, partitionIndex)                                                    (SoAd_GetIpFragBufOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_GetIpFragBufEndIdxOfIpFragBufConfig(Index, partitionIndex)                             (SoAd_GetIpFragBufConfigOfPCPartitionConfig(partitionIndex)[(Index)].IpFragBufEndIdxOfIpFragBufConfig)
#define SoAd_GetIpFragBufStartIdxOfIpFragBufConfig(Index, partitionIndex)                           (SoAd_GetIpFragBufConfigOfPCPartitionConfig(partitionIndex)[(Index)].IpFragBufStartIdxOfIpFragBufConfig)
#define SoAd_GetLengthOfIpFragBufConfigDyn(Index, partitionIndex)                                   (SoAd_GetIpFragBufConfigDynOfPCPartitionConfig(partitionIndex)[(Index)].LengthOfIpFragBufConfigDyn)
#define SoAd_GetIpFragBufConfigIdxOfIpFragMgt(Index, partitionIndex)                                (SoAd_GetIpFragMgtOfPCPartitionConfig(partitionIndex)[(Index)].IpFragBufConfigIdxOfIpFragMgt)
#define SoAd_GetAddrIdOfLocalAddr(Index, partitionIndex)                                            (SoAd_GetLocalAddrOfPCPartitionConfig(partitionIndex)[(Index)].AddrIdOfLocalAddr)
#define SoAd_GetDomainOfLocalAddr(Index, partitionIndex)                                            (SoAd_GetLocalAddrOfPCPartitionConfig(partitionIndex)[(Index)].DomainOfLocalAddr)
#define SoAd_GetSoConGrpEndIdxOfLocalAddr(Index, partitionIndex)                                    (SoAd_GetLocalAddrOfPCPartitionConfig(partitionIndex)[(Index)].SoConGrpEndIdxOfLocalAddr)
#define SoAd_GetSoConGrpStartIdxOfLocalAddr(Index, partitionIndex)                                  (SoAd_GetLocalAddrOfPCPartitionConfig(partitionIndex)[(Index)].SoConGrpStartIdxOfLocalAddr)
#define SoAd_GetTcpIpCtrlIdxOfLocalAddr(Index, partitionIndex)                                      (SoAd_GetLocalAddrOfPCPartitionConfig(partitionIndex)[(Index)].TcpIpCtrlIdxOfLocalAddr)
#define SoAd_GetLocalAddrByTcpIpCtrlInd(Index, partitionIndex)                                      (SoAd_GetLocalAddrByTcpIpCtrlIndOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_GetIpAddrStateOfLocalAddrDyn(Index, partitionIndex)                                    (SoAd_GetLocalAddrDynOfPCPartitionConfig(partitionIndex)[(Index)].IpAddrStateOfLocalAddrDyn)
#define SoAd_IsInvalidHndOfLocalAddrIdMap(Index)                                                    ((SoAd_GetLocalAddrIdMapOfPCPartitionConfig()[(Index)].InvalidHndOfLocalAddrIdMap) != FALSE)
#define SoAd_GetPartitionSpecificLocalAddrIdxOfLocalAddrIdMap(Index)                                (SoAd_GetLocalAddrIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificLocalAddrIdxOfLocalAddrIdMap)
#define SoAd_GetPartitionSpecificLocalAddrPartitionIdxOfLocalAddrIdMap(Index)                       (SoAd_GetLocalAddrIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificLocalAddrPartitionIdxOfLocalAddrIdMap)
#define SoAd_GetLocalIpAddrAssignmentChgCbk(Index)                                                  (SoAd_GetLocalIpAddrAssignmentChgCbkOfPCPartitionConfig()[(Index)])
#define SoAd_GetLocalIpAddrAssignmentChgCbkInd(Index, partitionIndex)                               (SoAd_GetLocalIpAddrAssignmentChgCbkIndOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_GetMetaDataRxBuffer(Index, partitionIndex)                                             (SoAd_GetMetaDataRxBufferOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_GetNPduUdpTxBufferEndIdxOfNPduUdpTx(Index, partitionIndex)                             (SoAd_GetNPduUdpTxOfPCPartitionConfig(partitionIndex)[(Index)].NPduUdpTxBufferEndIdxOfNPduUdpTx)
#define SoAd_GetNPduUdpTxBufferStartIdxOfNPduUdpTx(Index, partitionIndex)                           (SoAd_GetNPduUdpTxOfPCPartitionConfig(partitionIndex)[(Index)].NPduUdpTxBufferStartIdxOfNPduUdpTx)
#define SoAd_GetNPduUdpTxQueueEndIdxOfNPduUdpTx(Index, partitionIndex)                              (SoAd_GetNPduUdpTxOfPCPartitionConfig(partitionIndex)[(Index)].NPduUdpTxQueueEndIdxOfNPduUdpTx)
#define SoAd_GetNPduUdpTxQueueStartIdxOfNPduUdpTx(Index, partitionIndex)                            (SoAd_GetNPduUdpTxOfPCPartitionConfig(partitionIndex)[(Index)].NPduUdpTxQueueStartIdxOfNPduUdpTx)
#define SoAd_GetSoConIdxOfNPduUdpTx(Index, partitionIndex)                                          (SoAd_GetNPduUdpTxOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdxOfNPduUdpTx)
#define SoAd_GetNPduUdpTxBuffer(Index, partitionIndex)                                              (SoAd_GetNPduUdpTxBufferOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_GetBufLenOfNPduUdpTxDyn(Index, partitionIndex)                                         (SoAd_GetNPduUdpTxDynOfPCPartitionConfig(partitionIndex)[(Index)].BufLenOfNPduUdpTxDyn)
#define SoAd_GetLvlOfNPduUdpTxDyn(Index, partitionIndex)                                            (SoAd_GetNPduUdpTxDynOfPCPartitionConfig(partitionIndex)[(Index)].LvlOfNPduUdpTxDyn)
#define SoAd_GetRetryCntOfNPduUdpTxDyn(Index, partitionIndex)                                       (SoAd_GetNPduUdpTxDynOfPCPartitionConfig(partitionIndex)[(Index)].RetryCntOfNPduUdpTxDyn)
#define SoAd_GetTotalLenOfNPduUdpTxDyn(Index, partitionIndex)                                       (SoAd_GetNPduUdpTxDynOfPCPartitionConfig(partitionIndex)[(Index)].TotalLenOfNPduUdpTxDyn)
#define SoAd_GetTransmissionStateOfNPduUdpTxDyn(Index, partitionIndex)                              (SoAd_GetNPduUdpTxDynOfPCPartitionConfig(partitionIndex)[(Index)].TransmissionStateOfNPduUdpTxDyn)
#define SoAd_IsCopiedOfNPduUdpTxQueue(Index, partitionIndex)                                        ((SoAd_GetNPduUdpTxQueueOfPCPartitionConfig(partitionIndex)[(Index)].CopiedOfNPduUdpTxQueue) != FALSE)
#define SoAd_GetLenOfNPduUdpTxQueue(Index, partitionIndex)                                          (SoAd_GetNPduUdpTxQueueOfPCPartitionConfig(partitionIndex)[(Index)].LenOfNPduUdpTxQueue)
#define SoAd_GetNPduUdpTxBufferIdxOfNPduUdpTxQueue(Index, partitionIndex)                           (SoAd_GetNPduUdpTxQueueOfPCPartitionConfig(partitionIndex)[(Index)].NPduUdpTxBufferIdxOfNPduUdpTxQueue)
#define SoAd_GetPduRouteDestIdxOfNPduUdpTxQueue(Index, partitionIndex)                              (SoAd_GetNPduUdpTxQueueOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteDestIdxOfNPduUdpTxQueue)
#define SoAd_GetInitializedOfPartitionDyn(Index, partitionIndex)                                    (SoAd_GetPartitionDynOfPCPartitionConfig(partitionIndex)[(Index)].InitializedOfPartitionDyn)
#define SoAd_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                   (SoAd_GetPartitionIdentifiersOfPCConfig()[(Index)].PCPartitionConfigIdxOfPartitionIdentifiers)
#define SoAd_GetPartitionSNVOfPartitionIdentifiers(Index)                                           (SoAd_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define SoAd_IsAllPduRouteDestWithPduHdrOfPduRoute(Index, partitionIndex)                           ((SoAd_GetPduRouteOfPCPartitionConfig(partitionIndex)[(Index)].AllPduRouteDestWithPduHdrOfPduRoute) != FALSE)
#define SoAd_IsIfOptimisticTransmitOfPduRoute(Index, partitionIndex)                                ((SoAd_GetPduRouteOfPCPartitionConfig(partitionIndex)[(Index)].IfOptimisticTransmitOfPduRoute) != FALSE)
#define SoAd_GetIfTriggerTransmitModeOfPduRoute(Index, partitionIndex)                              (SoAd_GetPduRouteOfPCPartitionConfig(partitionIndex)[(Index)].IfTriggerTransmitModeOfPduRoute)
#define SoAd_IsMetaDataTxEnabledOfPduRoute(Index, partitionIndex)                                   ((SoAd_GetPduRouteOfPCPartitionConfig(partitionIndex)[(Index)].MetaDataTxEnabledOfPduRoute) != FALSE)
#define SoAd_GetPduRouteDestEndIdxOfPduRoute(Index, partitionIndex)                                 (SoAd_GetPduRouteOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteDestEndIdxOfPduRoute)
#define SoAd_GetPduRouteDestStartIdxOfPduRoute(Index, partitionIndex)                               (SoAd_GetPduRouteOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteDestStartIdxOfPduRoute)
#define SoAd_IsTxConfEnabledOfPduRoute(Index, partitionIndex)                                       ((SoAd_GetPduRouteOfPCPartitionConfig(partitionIndex)[(Index)].TxConfEnabledOfPduRoute) != FALSE)
#define SoAd_GetTxConfPduIdOfPduRoute(Index, partitionIndex)                                        (SoAd_GetPduRouteOfPCPartitionConfig(partitionIndex)[(Index)].TxConfPduIdOfPduRoute)
#define SoAd_IsTxOptimizedOfPduRoute(Index, partitionIndex)                                         ((SoAd_GetPduRouteOfPCPartitionConfig(partitionIndex)[(Index)].TxOptimizedOfPduRoute) != FALSE)
#define SoAd_GetUpperLayerApiOfPduRoute(Index, partitionIndex)                                      (SoAd_GetPduRouteOfPCPartitionConfig(partitionIndex)[(Index)].UpperLayerApiOfPduRoute)
#define SoAd_GetUpperLayerIdxOfPduRoute(Index, partitionIndex)                                      (SoAd_GetPduRouteOfPCPartitionConfig(partitionIndex)[(Index)].UpperLayerIdxOfPduRoute)
#define SoAd_GetPduRouteIdxOfPduRouteDest(Index, partitionIndex)                                    (SoAd_GetPduRouteDestOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteIdxOfPduRouteDest)
#define SoAd_GetRouteGrpSoConByPduRouteDestIndEndIdxOfPduRouteDest(Index, partitionIndex)           (SoAd_GetPduRouteDestOfPCPartitionConfig(partitionIndex)[(Index)].RouteGrpSoConByPduRouteDestIndEndIdxOfPduRouteDest)
#define SoAd_GetRouteGrpSoConByPduRouteDestIndStartIdxOfPduRouteDest(Index, partitionIndex)         (SoAd_GetPduRouteDestOfPCPartitionConfig(partitionIndex)[(Index)].RouteGrpSoConByPduRouteDestIndStartIdxOfPduRouteDest)
#define SoAd_GetSoConIdxOfPduRouteDest(Index, partitionIndex)                                       (SoAd_GetPduRouteDestOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdxOfPduRouteDest)
#define SoAd_GetTxPduHdrIdOfPduRouteDest(Index, partitionIndex)                                     (SoAd_GetPduRouteDestOfPCPartitionConfig(partitionIndex)[(Index)].TxPduHdrIdOfPduRouteDest)
#define SoAd_GetTxUdpTriggerModeOfPduRouteDest(Index, partitionIndex)                               (SoAd_GetPduRouteDestOfPCPartitionConfig(partitionIndex)[(Index)].TxUdpTriggerModeOfPduRouteDest)
#define SoAd_GetUdpTriggerTimeoutOfPduRouteDest(Index, partitionIndex)                              (SoAd_GetPduRouteDestOfPCPartitionConfig(partitionIndex)[(Index)].UdpTriggerTimeoutOfPduRouteDest)
#define SoAd_GetPduRouteDestBySoConInd(Index, partitionIndex)                                       (SoAd_GetPduRouteDestBySoConIndOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_GetPduRouteDestInd(Index, partitionIndex)                                              (SoAd_GetPduRouteDestIndOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_IsPendingTxConfMainOfPduRouteDyn(Index, partitionIndex)                                ((SoAd_GetPduRouteDynOfPCPartitionConfig(partitionIndex)[(Index)].PendingTxConfMainOfPduRouteDyn) != FALSE)
#define SoAd_GetPendingTxConfNumOfPduRouteDyn(Index, partitionIndex)                                (SoAd_GetPduRouteDynOfPCPartitionConfig(partitionIndex)[(Index)].PendingTxConfNumOfPduRouteDyn)
#define SoAd_GetAddrOfRemAddrIpV4(Index, partitionIndex)                                            (SoAd_GetRemAddrIpV4OfPCPartitionConfig(partitionIndex)[(Index)].AddrOfRemAddrIpV4)
#define SoAd_GetPortOfRemAddrIpV4(Index, partitionIndex)                                            (SoAd_GetRemAddrIpV4OfPCPartitionConfig(partitionIndex)[(Index)].PortOfRemAddrIpV4)
#define SoAd_GetAddrOfRemAddrIpV6(Index, partitionIndex)                                            (SoAd_GetRemAddrIpV6OfPCPartitionConfig(partitionIndex)[(Index)].AddrOfRemAddrIpV6)
#define SoAd_GetPortOfRemAddrIpV6(Index, partitionIndex)                                            (SoAd_GetRemAddrIpV6OfPCPartitionConfig(partitionIndex)[(Index)].PortOfRemAddrIpV6)
#define SoAd_GetRemAddrRcv(Index, partitionIndex)                                                   (SoAd_GetRemAddrRcvOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_IsEnabledAtInitOfRouteGrp(Index, partitionIndex)                                       ((SoAd_GetRouteGrpOfPCPartitionConfig(partitionIndex)[(Index)].EnabledAtInitOfRouteGrp) != FALSE)
#define SoAd_IsMultiInstanceOnGrpOfRouteGrp(Index, partitionIndex)                                  ((SoAd_GetRouteGrpOfPCPartitionConfig(partitionIndex)[(Index)].MultiInstanceOnGrpOfRouteGrp) != FALSE)
#define SoAd_GetPduRouteDestIndEndIdxOfRouteGrp(Index, partitionIndex)                              (SoAd_GetRouteGrpOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteDestIndEndIdxOfRouteGrp)
#define SoAd_GetPduRouteDestIndStartIdxOfRouteGrp(Index, partitionIndex)                            (SoAd_GetRouteGrpOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteDestIndStartIdxOfRouteGrp)
#define SoAd_GetRouteGrpIdOfRouteGrp(Index, partitionIndex)                                         ((SoAd_RoutingGroupIdType)SoAd_GetRouteGrpOfPCPartitionConfig(partitionIndex)[(Index)].RouteGrpIdOfRouteGrp)
#define SoAd_GetRouteGrpSoConEndIdxOfRouteGrp(Index, partitionIndex)                                (SoAd_GetRouteGrpOfPCPartitionConfig(partitionIndex)[(Index)].RouteGrpSoConEndIdxOfRouteGrp)
#define SoAd_GetRouteGrpSoConStartIdxOfRouteGrp(Index, partitionIndex)                              (SoAd_GetRouteGrpOfPCPartitionConfig(partitionIndex)[(Index)].RouteGrpSoConStartIdxOfRouteGrp)
#define SoAd_IsRxRequestEnableOfRouteGrp(Index, partitionIndex)                                     ((SoAd_GetRouteGrpOfPCPartitionConfig(partitionIndex)[(Index)].RxRequestEnableOfRouteGrp) != FALSE)
#define SoAd_GetSocketRouteIndEndIdxOfRouteGrp(Index, partitionIndex)                               (SoAd_GetRouteGrpOfPCPartitionConfig(partitionIndex)[(Index)].SocketRouteIndEndIdxOfRouteGrp)
#define SoAd_GetSocketRouteIndStartIdxOfRouteGrp(Index, partitionIndex)                             (SoAd_GetRouteGrpOfPCPartitionConfig(partitionIndex)[(Index)].SocketRouteIndStartIdxOfRouteGrp)
#define SoAd_IsTxTriggerableOfRouteGrp(Index, partitionIndex)                                       ((SoAd_GetRouteGrpOfPCPartitionConfig(partitionIndex)[(Index)].TxTriggerableOfRouteGrp) != FALSE)
#define SoAd_IsInvalidHndOfRouteGrpIdMap(Index)                                                     ((SoAd_GetRouteGrpIdMapOfPCPartitionConfig()[(Index)].InvalidHndOfRouteGrpIdMap) != FALSE)
#define SoAd_GetPartitionSpecificRouteGrpIdxOfRouteGrpIdMap(Index)                                  (SoAd_GetRouteGrpIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificRouteGrpIdxOfRouteGrpIdMap)
#define SoAd_GetPartitionSpecificRouteGrpPartitionIdxOfRouteGrpIdMap(Index)                         (SoAd_GetRouteGrpIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificRouteGrpPartitionIdxOfRouteGrpIdMap)
#define SoAd_GetRouteGrpIdxOfRouteGrpSoCon(Index, partitionIndex)                                   (SoAd_GetRouteGrpSoConOfPCPartitionConfig(partitionIndex)[(Index)].RouteGrpIdxOfRouteGrpSoCon)
#define SoAd_GetSoConIdxOfRouteGrpSoCon(Index, partitionIndex)                                      (SoAd_GetRouteGrpSoConOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdxOfRouteGrpSoCon)
#define SoAd_GetRouteGrpSoConByPduRouteDestInd(Index, partitionIndex)                               (SoAd_GetRouteGrpSoConByPduRouteDestIndOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_GetRouteGrpSoConBySocketRouteDestInd(Index, partitionIndex)                            (SoAd_GetRouteGrpSoConBySocketRouteDestIndOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_IsEnabledOfRouteGrpSoConDyn(Index, partitionIndex)                                     ((SoAd_GetRouteGrpSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].EnabledOfRouteGrpSoConDyn) != FALSE)
#define SoAd_GetFlagsOfRouteGrpSoConDyn(Index, partitionIndex)                                      (SoAd_GetRouteGrpSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].FlagsOfRouteGrpSoConDyn)
#define SoAd_GetRxBufStructSegIdxOfRxBufStructMgt(Index, partitionIndex)                            (SoAd_GetRxBufStructMgtOfPCPartitionConfig(partitionIndex)[(Index)].RxBufStructSegIdxOfRxBufStructMgt)
#define SoAd_GetRxBufStructSegLvlOfRxBufStructMgt(Index, partitionIndex)                            (SoAd_GetRxBufStructMgtOfPCPartitionConfig(partitionIndex)[(Index)].RxBufStructSegLvlOfRxBufStructMgt)
#define SoAd_GetDataPtrOfRxBufStructSeg(Index, partitionIndex)                                      (SoAd_GetRxBufStructSegOfPCPartitionConfig(partitionIndex)[(Index)].DataPtrOfRxBufStructSeg)
#define SoAd_GetLenOfRxBufStructSeg(Index, partitionIndex)                                          (SoAd_GetRxBufStructSegOfPCPartitionConfig(partitionIndex)[(Index)].LenOfRxBufStructSeg)
#define SoAd_GetIfRxBufferEndIdxOfRxBufferConfig(Index, partitionIndex)                             (SoAd_GetRxBufferConfigOfPCPartitionConfig(partitionIndex)[(Index)].IfRxBufferEndIdxOfRxBufferConfig)
#define SoAd_GetIfRxBufferStartIdxOfRxBufferConfig(Index, partitionIndex)                           (SoAd_GetRxBufferConfigOfPCPartitionConfig(partitionIndex)[(Index)].IfRxBufferStartIdxOfRxBufferConfig)
#define SoAd_GetMetaDataRxBufferEndIdxOfRxBufferConfig(Index, partitionIndex)                       (SoAd_GetRxBufferConfigOfPCPartitionConfig(partitionIndex)[(Index)].MetaDataRxBufferEndIdxOfRxBufferConfig)
#define SoAd_GetMetaDataRxBufferStartIdxOfRxBufferConfig(Index, partitionIndex)                     (SoAd_GetRxBufferConfigOfPCPartitionConfig(partitionIndex)[(Index)].MetaDataRxBufferStartIdxOfRxBufferConfig)
#define SoAd_GetTpRxBufferEndIdxOfRxBufferConfig(Index, partitionIndex)                             (SoAd_GetRxBufferConfigOfPCPartitionConfig(partitionIndex)[(Index)].TpRxBufferEndIdxOfRxBufferConfig)
#define SoAd_GetTpRxBufferStartIdxOfRxBufferConfig(Index, partitionIndex)                           (SoAd_GetRxBufferConfigOfPCPartitionConfig(partitionIndex)[(Index)].TpRxBufferStartIdxOfRxBufferConfig)
#define SoAd_GetIfRxBufferIdxOfRxBufferConfigDyn(Index, partitionIndex)                             (SoAd_GetRxBufferConfigDynOfPCPartitionConfig(partitionIndex)[(Index)].IfRxBufferIdxOfRxBufferConfigDyn)
#define SoAd_GetTpRxBufferIdxOfRxBufferConfigDyn(Index, partitionIndex)                             (SoAd_GetRxBufferConfigDynOfPCPartitionConfig(partitionIndex)[(Index)].TpRxBufferIdxOfRxBufferConfigDyn)
#define SoAd_IsCancelRequestedOfRxMgt(Index, partitionIndex)                                        ((SoAd_GetRxMgtOfPCPartitionConfig(partitionIndex)[(Index)].CancelRequestedOfRxMgt) != FALSE)
#define SoAd_GetRxBytesPendingOfRxMgt(Index, partitionIndex)                                        (SoAd_GetRxMgtOfPCPartitionConfig(partitionIndex)[(Index)].RxBytesPendingOfRxMgt)
#define SoAd_GetSocketRouteDestIdxOfRxMgt(Index, partitionIndex)                                    (SoAd_GetRxMgtOfPCPartitionConfig(partitionIndex)[(Index)].SocketRouteDestIdxOfRxMgt)
#define SoAd_IsInvalidHndOfRxPduIdIdMap(Index)                                                      ((SoAd_GetRxPduIdIdMapOfPCPartitionConfig()[(Index)].InvalidHndOfRxPduIdIdMap) != FALSE)
#define SoAd_GetPartitionSpecificSocketRouteDestIdxOfRxPduIdIdMap(Index)                            (SoAd_GetRxPduIdIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificSocketRouteDestIdxOfRxPduIdIdMap)
#define SoAd_GetPartitionSpecificSocketRouteDestPartitionIdxOfRxPduIdIdMap(Index)                   (SoAd_GetRxPduIdIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificSocketRouteDestPartitionIdxOfRxPduIdIdMap)
#define SoAd_GetShutdownFinishedCbk(Index)                                                          (SoAd_GetShutdownFinishedCbkOfPCPartitionConfig()[(Index)])
#define SoAd_GetIpFragMgtIdxOfSoCon(Index, partitionIndex)                                          (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].IpFragMgtIdxOfSoCon)
#define SoAd_GetLocalIpAddrAssignmentChgCbkIndEndIdxOfSoCon(Index, partitionIndex)                  (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].LocalIpAddrAssignmentChgCbkIndEndIdxOfSoCon)
#define SoAd_GetLocalIpAddrAssignmentChgCbkIndStartIdxOfSoCon(Index, partitionIndex)                (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].LocalIpAddrAssignmentChgCbkIndStartIdxOfSoCon)
#define SoAd_GetNPduUdpTxIdxOfSoCon(Index, partitionIndex)                                          (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].NPduUdpTxIdxOfSoCon)
#define SoAd_GetPduRouteDestBySoConIndEndIdxOfSoCon(Index, partitionIndex)                          (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteDestBySoConIndEndIdxOfSoCon)
#define SoAd_GetPduRouteDestBySoConIndStartIdxOfSoCon(Index, partitionIndex)                        (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteDestBySoConIndStartIdxOfSoCon)
#define SoAd_GetRemAddrCfgStateOfSoCon(Index, partitionIndex)                                       (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].RemAddrCfgStateOfSoCon)
#define SoAd_GetRemAddrIpV4IdxOfSoCon(Index, partitionIndex)                                        (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].RemAddrIpV4IdxOfSoCon)
#define SoAd_GetRemAddrIpV6IdxOfSoCon(Index, partitionIndex)                                        (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].RemAddrIpV6IdxOfSoCon)
#define SoAd_GetRemAddrRcvIdxOfSoCon(Index, partitionIndex)                                         (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].RemAddrRcvIdxOfSoCon)
#define SoAd_GetRxBufStructMgtIdxOfSoCon(Index, partitionIndex)                                     (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].RxBufStructMgtIdxOfSoCon)
#define SoAd_GetRxBufStructSegEndIdxOfSoCon(Index, partitionIndex)                                  (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].RxBufStructSegEndIdxOfSoCon)
#define SoAd_GetRxBufStructSegStartIdxOfSoCon(Index, partitionIndex)                                (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].RxBufStructSegStartIdxOfSoCon)
#define SoAd_GetRxBufferConfigIdxOfSoCon(Index, partitionIndex)                                     (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].RxBufferConfigIdxOfSoCon)
#define SoAd_GetRxMgtIdxOfSoCon(Index, partitionIndex)                                              (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].RxMgtIdxOfSoCon)
#define SoAd_GetSoConGrpIdxOfSoCon(Index, partitionIndex)                                           (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].SoConGrpIdxOfSoCon)
#define SoAd_GetSoConIdOfSoCon(Index, partitionIndex)                                               (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdOfSoCon)
#define SoAd_GetSoConModeChgCbkIndEndIdxOfSoCon(Index, partitionIndex)                              (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].SoConModeChgCbkIndEndIdxOfSoCon)
#define SoAd_GetSoConModeChgCbkIndStartIdxOfSoCon(Index, partitionIndex)                            (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].SoConModeChgCbkIndStartIdxOfSoCon)
#define SoAd_GetSocketIdxOfSoCon(Index, partitionIndex)                                             (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].SocketIdxOfSoCon)
#define SoAd_GetSocketRouteEndIdxOfSoCon(Index, partitionIndex)                                     (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].SocketRouteEndIdxOfSoCon)
#define SoAd_GetSocketRouteStartIdxOfSoCon(Index, partitionIndex)                                   (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].SocketRouteStartIdxOfSoCon)
#define SoAd_GetTcpTxQueueIdxOfSoCon(Index, partitionIndex)                                         (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].TcpTxQueueIdxOfSoCon)
#define SoAd_GetTpTxBufferConfigIdxOfSoCon(Index, partitionIndex)                                   (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].TpTxBufferConfigIdxOfSoCon)
#define SoAd_GetTxMgtIdxOfSoCon(Index, partitionIndex)                                              (SoAd_GetSoConOfPCPartitionConfig(partitionIndex)[(Index)].TxMgtIdxOfSoCon)
#define SoAd_IsAbortOfSoConDyn(Index, partitionIndex)                                               ((SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].AbortOfSoConDyn) != FALSE)
#define SoAd_GetCloseModeOfSoConDyn(Index, partitionIndex)                                          (SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].CloseModeOfSoConDyn)
#define SoAd_GetModeOfSoConDyn(Index, partitionIndex)                                               (SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].ModeOfSoConDyn)
#define SoAd_GetOpenCloseCounterOfSoConDyn(Index, partitionIndex)                                   (SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].OpenCloseCounterOfSoConDyn)
#define SoAd_GetRemAddrDynOfSoConDyn(Index, partitionIndex)                                         (SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].RemAddrDynOfSoConDyn)
#define SoAd_GetRemAddrReleaseOfSoConDyn(Index, partitionIndex)                                     (SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].RemAddrReleaseOfSoConDyn)
#define SoAd_GetRemAddrStateDynOfSoConDyn(Index, partitionIndex)                                    (SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].RemAddrStateDynOfSoConDyn)
#define SoAd_IsRxActiveOfSoConDyn(Index, partitionIndex)                                            ((SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].RxActiveOfSoConDyn) != FALSE)
#define SoAd_IsTimeoutOccurredOfSoConDyn(Index, partitionIndex)                                     ((SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutOccurredOfSoConDyn) != FALSE)
#define SoAd_IsTxActiveOfSoConDyn(Index, partitionIndex)                                            ((SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].TxActiveOfSoConDyn) != FALSE)
#define SoAd_IsBestMatchWithPduHeaderEnabledOfSoConGrp(Index, partitionIndex)                       ((SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].BestMatchWithPduHeaderEnabledOfSoConGrp) != FALSE)
#define SoAd_IsBestMatchWithSockRouteEnabledOfSoConGrp(Index, partitionIndex)                       ((SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].BestMatchWithSockRouteEnabledOfSoConGrp) != FALSE)
#define SoAd_GetFramePriorityOfSoConGrp(Index, partitionIndex)                                      (SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].FramePriorityOfSoConGrp)
#define SoAd_GetInstanceIdxOfSoConGrp(Index, partitionIndex)                                        (SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].InstanceIdxOfSoConGrp)
#define SoAd_GetLocalAddrIdxOfSoConGrp(Index, partitionIndex)                                       (SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].LocalAddrIdxOfSoConGrp)
#define SoAd_GetLocalPortOfSoConGrp(Index, partitionIndex)                                          (SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].LocalPortOfSoConGrp)
#define SoAd_GetMeasurementDataSomeIpSdTypeOfSoConGrp(Index, partitionIndex)                        (SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].MeasurementDataSomeIpSdTypeOfSoConGrp)
#define SoAd_IsMsgAcceptFilterEnabledOfSoConGrp(Index, partitionIndex)                              ((SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].MsgAcceptFilterEnabledOfSoConGrp) != FALSE)
#define SoAd_IsPduHdrEnabledOfSoConGrp(Index, partitionIndex)                                       ((SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].PduHdrEnabledOfSoConGrp) != FALSE)
#define SoAd_GetSoConEndIdxOfSoConGrp(Index, partitionIndex)                                        (SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].SoConEndIdxOfSoConGrp)
#define SoAd_GetSoConStartIdxOfSoConGrp(Index, partitionIndex)                                      (SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].SoConStartIdxOfSoConGrp)
#define SoAd_IsSockAutoSoConSetupKeepOnlineOfSoConGrp(Index, partitionIndex)                        ((SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].SockAutoSoConSetupKeepOnlineOfSoConGrp) != FALSE)
#define SoAd_IsSockAutoSoConSetupOfSoConGrp(Index, partitionIndex)                                  ((SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].SockAutoSoConSetupOfSoConGrp) != FALSE)
#define SoAd_GetSocketIdxOfSoConGrp(Index, partitionIndex)                                          (SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].SocketIdxOfSoConGrp)
#define SoAd_GetSocketTcpIdxOfSoConGrp(Index, partitionIndex)                                       (SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].SocketTcpIdxOfSoConGrp)
#define SoAd_GetSocketUdpIdxOfSoConGrp(Index, partitionIndex)                                       (SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex)[(Index)].SocketUdpIdxOfSoConGrp)
#define SoAd_IsInvalidHndOfSoConMap(Index)                                                          ((SoAd_GetSoConMapOfPCPartitionConfig()[(Index)].InvalidHndOfSoConMap) != FALSE)
#define SoAd_GetPartitionSpecificSoConIdxOfSoConMap(Index)                                          (SoAd_GetSoConMapOfPCPartitionConfig()[(Index)].PartitionSpecificSoConIdxOfSoConMap)
#define SoAd_GetPartitionSpecificSoConPartitionIdxOfSoConMap(Index)                                 (SoAd_GetSoConMapOfPCPartitionConfig()[(Index)].PartitionSpecificSoConPartitionIdxOfSoConMap)
#define SoAd_GetSoConModeChgCbk(Index)                                                              (SoAd_GetSoConModeChgCbkOfPCPartitionConfig()[(Index)])
#define SoAd_GetSoConModeChgCbkInd(Index, partitionIndex)                                           (SoAd_GetSoConModeChgCbkIndOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_GetSoConEndIdxOfSocket(Index, partitionIndex)                                          (SoAd_GetSocketOfPCPartitionConfig(partitionIndex)[(Index)].SoConEndIdxOfSocket)
#define SoAd_GetSoConStartIdxOfSocket(Index, partitionIndex)                                        (SoAd_GetSocketOfPCPartitionConfig(partitionIndex)[(Index)].SoConStartIdxOfSocket)
#define SoAd_GetLocalPortOfSocketDyn(Index, partitionIndex)                                         (SoAd_GetSocketDynOfPCPartitionConfig(partitionIndex)[(Index)].LocalPortOfSocketDyn)
#define SoAd_GetSkipBytesOfSocketDyn(Index, partitionIndex)                                         (SoAd_GetSocketDynOfPCPartitionConfig(partitionIndex)[(Index)].SkipBytesOfSocketDyn)
#define SoAd_GetSoConTxActiveIdxOfSocketDyn(Index, partitionIndex)                                  (SoAd_GetSocketDynOfPCPartitionConfig(partitionIndex)[(Index)].SoConTxActiveIdxOfSocketDyn)
#define SoAd_GetSocketIdOfSocketDyn(Index, partitionIndex)                                          (SoAd_GetSocketDynOfPCPartitionConfig(partitionIndex)[(Index)].SocketIdOfSocketDyn)
#define SoAd_GetStateOfSocketDyn(Index, partitionIndex)                                             (SoAd_GetSocketDynOfPCPartitionConfig(partitionIndex)[(Index)].StateOfSocketDyn)
#define SoAd_IsMetaDataRxEnabledOfSocketRoute(Index, partitionIndex)                                ((SoAd_GetSocketRouteOfPCPartitionConfig(partitionIndex)[(Index)].MetaDataRxEnabledOfSocketRoute) != FALSE)
#define SoAd_GetRxPduHdrMethodIdOfSocketRoute(Index, partitionIndex)                                (SoAd_GetSocketRouteOfPCPartitionConfig(partitionIndex)[(Index)].RxPduHdrMethodIdOfSocketRoute)
#define SoAd_GetRxPduHdrServiceIdOfSocketRoute(Index, partitionIndex)                               (SoAd_GetSocketRouteOfPCPartitionConfig(partitionIndex)[(Index)].RxPduHdrServiceIdOfSocketRoute)
#define SoAd_GetSoConIdxOfSocketRoute(Index, partitionIndex)                                        (SoAd_GetSocketRouteOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdxOfSocketRoute)
#define SoAd_GetSocketRouteDestEndIdxOfSocketRoute(Index, partitionIndex)                           (SoAd_GetSocketRouteOfPCPartitionConfig(partitionIndex)[(Index)].SocketRouteDestEndIdxOfSocketRoute)
#define SoAd_GetSocketRouteDestStartIdxOfSocketRoute(Index, partitionIndex)                         (SoAd_GetSocketRouteOfPCPartitionConfig(partitionIndex)[(Index)].SocketRouteDestStartIdxOfSocketRoute)
#define SoAd_GetUpperLayerApiOfSocketRoute(Index, partitionIndex)                                   (SoAd_GetSocketRouteOfPCPartitionConfig(partitionIndex)[(Index)].UpperLayerApiOfSocketRoute)
#define SoAd_GetRouteGrpSoConBySocketRouteDestIndEndIdxOfSocketRouteDest(Index, partitionIndex)     (SoAd_GetSocketRouteDestOfPCPartitionConfig(partitionIndex)[(Index)].RouteGrpSoConBySocketRouteDestIndEndIdxOfSocketRouteDest)
#define SoAd_GetRouteGrpSoConBySocketRouteDestIndStartIdxOfSocketRouteDest(Index, partitionIndex)   (SoAd_GetSocketRouteDestOfPCPartitionConfig(partitionIndex)[(Index)].RouteGrpSoConBySocketRouteDestIndStartIdxOfSocketRouteDest)
#define SoAd_GetRxPduIdOfSocketRouteDest(Index, partitionIndex)                                     (SoAd_GetSocketRouteDestOfPCPartitionConfig(partitionIndex)[(Index)].RxPduIdOfSocketRouteDest)
#define SoAd_GetSocketRouteIdxOfSocketRouteDest(Index, partitionIndex)                              (SoAd_GetSocketRouteDestOfPCPartitionConfig(partitionIndex)[(Index)].SocketRouteIdxOfSocketRouteDest)
#define SoAd_GetUpperLayerIdxOfSocketRouteDest(Index, partitionIndex)                               (SoAd_GetSocketRouteDestOfPCPartitionConfig(partitionIndex)[(Index)].UpperLayerIdxOfSocketRouteDest)
#define SoAd_GetSocketRouteInd(Index, partitionIndex)                                               (SoAd_GetSocketRouteIndOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_IsImmedTpTxConfOfSocketTcp(Index, partitionIndex)                                      ((SoAd_GetSocketTcpOfPCPartitionConfig(partitionIndex)[(Index)].ImmedTpTxConfOfSocketTcp) != FALSE)
#define SoAd_IsTcpInitiateOfSocketTcp(Index, partitionIndex)                                        ((SoAd_GetSocketTcpOfPCPartitionConfig(partitionIndex)[(Index)].TcpInitiateOfSocketTcp) != FALSE)
#define SoAd_GetTcpKeepAliveIntervalOfSocketTcp(Index, partitionIndex)                              (SoAd_GetSocketTcpOfPCPartitionConfig(partitionIndex)[(Index)].TcpKeepAliveIntervalOfSocketTcp)
#define SoAd_IsTcpKeepAliveOfSocketTcp(Index, partitionIndex)                                       ((SoAd_GetSocketTcpOfPCPartitionConfig(partitionIndex)[(Index)].TcpKeepAliveOfSocketTcp) != FALSE)
#define SoAd_GetTcpKeepAliveProbesMaxOfSocketTcp(Index, partitionIndex)                             (SoAd_GetSocketTcpOfPCPartitionConfig(partitionIndex)[(Index)].TcpKeepAliveProbesMaxOfSocketTcp)
#define SoAd_GetTcpKeepAliveTimeOfSocketTcp(Index, partitionIndex)                                  (SoAd_GetSocketTcpOfPCPartitionConfig(partitionIndex)[(Index)].TcpKeepAliveTimeOfSocketTcp)
#define SoAd_GetTcpMslOfSocketTcp(Index, partitionIndex)                                            (SoAd_GetSocketTcpOfPCPartitionConfig(partitionIndex)[(Index)].TcpMslOfSocketTcp)
#define SoAd_GetTcpNoDelayOfSocketTcp(Index, partitionIndex)                                        (SoAd_GetSocketTcpOfPCPartitionConfig(partitionIndex)[(Index)].TcpNoDelayOfSocketTcp)
#define SoAd_GetTcpRxBufMinOfSocketTcp(Index, partitionIndex)                                       (SoAd_GetSocketTcpOfPCPartitionConfig(partitionIndex)[(Index)].TcpRxBufMinOfSocketTcp)
#define SoAd_GetTcpTlsConIdOfSocketTcp(Index, partitionIndex)                                       (SoAd_GetSocketTcpOfPCPartitionConfig(partitionIndex)[(Index)].TcpTlsConIdOfSocketTcp)
#define SoAd_GetTcpTxBufMinOfSocketTcp(Index, partitionIndex)                                       (SoAd_GetSocketTcpOfPCPartitionConfig(partitionIndex)[(Index)].TcpTxBufMinOfSocketTcp)
#define SoAd_GetAliveTimeoutMaxCntOfSocketUdp(Index, partitionIndex)                                (SoAd_GetSocketUdpOfPCPartitionConfig(partitionIndex)[(Index)].AliveTimeoutMaxCntOfSocketUdp)
#define SoAd_IsChecksumChangeEnabledOfSocketUdp(Index, partitionIndex)                              ((SoAd_GetSocketUdpOfPCPartitionConfig(partitionIndex)[(Index)].ChecksumChangeEnabledOfSocketUdp) != FALSE)
#define SoAd_IsChecksumEnabledOfSocketUdp(Index, partitionIndex)                                    ((SoAd_GetSocketUdpOfPCPartitionConfig(partitionIndex)[(Index)].ChecksumEnabledOfSocketUdp) != FALSE)
#define SoAd_GetImmedIfTxConfListSizeOfSocketUdp(Index, partitionIndex)                             (SoAd_GetSocketUdpOfPCPartitionConfig(partitionIndex)[(Index)].ImmedIfTxConfListSizeOfSocketUdp)
#define SoAd_IsImmedIfTxConfOfSocketUdp(Index, partitionIndex)                                      ((SoAd_GetSocketUdpOfPCPartitionConfig(partitionIndex)[(Index)].ImmedIfTxConfOfSocketUdp) != FALSE)
#define SoAd_GetNPduUdpTxBufferMinOfSocketUdp(Index, partitionIndex)                                (SoAd_GetSocketUdpOfPCPartitionConfig(partitionIndex)[(Index)].NPduUdpTxBufferMinOfSocketUdp)
#define SoAd_GetNPduUdpTxQueueSizeOfSocketUdp(Index, partitionIndex)                                (SoAd_GetSocketUdpOfPCPartitionConfig(partitionIndex)[(Index)].NPduUdpTxQueueSizeOfSocketUdp)
#define SoAd_GetRetryQueueLimitOfSocketUdp(Index, partitionIndex)                                   (SoAd_GetSocketUdpOfPCPartitionConfig(partitionIndex)[(Index)].RetryQueueLimitOfSocketUdp)
#define SoAd_IsUdpListenOnlyOfSocketUdp(Index, partitionIndex)                                      ((SoAd_GetSocketUdpOfPCPartitionConfig(partitionIndex)[(Index)].UdpListenOnlyOfSocketUdp) != FALSE)
#define SoAd_IsUdpStrictHdrLenCheckEnabledOfSocketUdp(Index, partitionIndex)                        ((SoAd_GetSocketUdpOfPCPartitionConfig(partitionIndex)[(Index)].UdpStrictHdrLenCheckEnabledOfSocketUdp) != FALSE)
#define SoAd_GetUdpTriggerTimeoutOfSocketUdp(Index, partitionIndex)                                 (SoAd_GetSocketUdpOfPCPartitionConfig(partitionIndex)[(Index)].UdpTriggerTimeoutOfSocketUdp)
#define SoAd_GetLocalAddrByTcpIpCtrlIndEndIdxOfTcpIpCtrl(Index, partitionIndex)                     (SoAd_GetTcpIpCtrlOfPCPartitionConfig(partitionIndex)[(Index)].LocalAddrByTcpIpCtrlIndEndIdxOfTcpIpCtrl)
#define SoAd_GetLocalAddrByTcpIpCtrlIndStartIdxOfTcpIpCtrl(Index, partitionIndex)                   (SoAd_GetTcpIpCtrlOfPCPartitionConfig(partitionIndex)[(Index)].LocalAddrByTcpIpCtrlIndStartIdxOfTcpIpCtrl)
#define SoAd_IsRetryEnabledOfTcpIpCtrl(Index, partitionIndex)                                       ((SoAd_GetTcpIpCtrlOfPCPartitionConfig(partitionIndex)[(Index)].RetryEnabledOfTcpIpCtrl) != FALSE)
#define SoAd_IsTcpKeepAliveGloballyEnabled(Index)                                                   ((SoAd_GetTcpKeepAliveGloballyEnabledOfPCPartitionConfig()[(Index)]) != FALSE)
#define SoAd_GetTcpTxQueueDataEndIdxOfTcpTxQueue(Index, partitionIndex)                             (SoAd_GetTcpTxQueueOfPCPartitionConfig(partitionIndex)[(Index)].TcpTxQueueDataEndIdxOfTcpTxQueue)
#define SoAd_GetTcpTxQueueDataStartIdxOfTcpTxQueue(Index, partitionIndex)                           (SoAd_GetTcpTxQueueOfPCPartitionConfig(partitionIndex)[(Index)].TcpTxQueueDataStartIdxOfTcpTxQueue)
#define SoAd_GetLenOfTcpTxQueueData(Index, partitionIndex)                                          (SoAd_GetTcpTxQueueDataOfPCPartitionConfig(partitionIndex)[(Index)].LenOfTcpTxQueueData)
#define SoAd_GetPduRouteIdxOfTcpTxQueueData(Index, partitionIndex)                                  (SoAd_GetTcpTxQueueDataOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteIdxOfTcpTxQueueData)
#define SoAd_GetLvlOfTcpTxQueueMgt(Index, partitionIndex)                                           (SoAd_GetTcpTxQueueMgtOfPCPartitionConfig(partitionIndex)[(Index)].LvlOfTcpTxQueueMgt)
#define SoAd_GetTcpTxQueueDataIdxOfTcpTxQueueMgt(Index, partitionIndex)                             (SoAd_GetTcpTxQueueMgtOfPCPartitionConfig(partitionIndex)[(Index)].TcpTxQueueDataIdxOfTcpTxQueueMgt)
#define SoAd_GetTotLenOfTcpTxQueueMgt(Index, partitionIndex)                                        (SoAd_GetTcpTxQueueMgtOfPCPartitionConfig(partitionIndex)[(Index)].TotLenOfTcpTxQueueMgt)
#define SoAd_GetTimeoutListNPduUdpTxConfigIdxOfTimeoutListIdent(Index, partitionIndex)              (SoAd_GetTimeoutListIdentOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListNPduUdpTxConfigIdxOfTimeoutListIdent)
#define SoAd_GetTimeoutListTcpAutoConnectConfigIdxOfTimeoutListIdent(Index, partitionIndex)         (SoAd_GetTimeoutListIdentOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListTcpAutoConnectConfigIdxOfTimeoutListIdent)
#define SoAd_GetTimeoutListUdpAliveConfigIdxOfTimeoutListIdent(Index, partitionIndex)               (SoAd_GetTimeoutListIdentOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListUdpAliveConfigIdxOfTimeoutListIdent)
#define SoAd_GetLvlOfTimeoutListMgmt(Index, partitionIndex)                                         (SoAd_GetTimeoutListMgmtOfPCPartitionConfig(partitionIndex)[(Index)].LvlOfTimeoutListMgmt)
#define SoAd_GetNPduUdpTxIdxOfTimeoutListNPduUdpTx(Index, partitionIndex)                           (SoAd_GetTimeoutListNPduUdpTxOfPCPartitionConfig(partitionIndex)[(Index)].NPduUdpTxIdxOfTimeoutListNPduUdpTx)
#define SoAd_GetTimeoutOfTimeoutListNPduUdpTx(Index, partitionIndex)                                (SoAd_GetTimeoutListNPduUdpTxOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutOfTimeoutListNPduUdpTx)
#define SoAd_GetTimeoutListMgmtIdxOfTimeoutListNPduUdpTxConfig(Index, partitionIndex)               (SoAd_GetTimeoutListNPduUdpTxConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListMgmtIdxOfTimeoutListNPduUdpTxConfig)
#define SoAd_GetTimeoutListNPduUdpTxEndIdxOfTimeoutListNPduUdpTxConfig(Index, partitionIndex)       (SoAd_GetTimeoutListNPduUdpTxConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListNPduUdpTxEndIdxOfTimeoutListNPduUdpTxConfig)
#define SoAd_GetTimeoutListNPduUdpTxStartIdxOfTimeoutListNPduUdpTxConfig(Index, partitionIndex)     (SoAd_GetTimeoutListNPduUdpTxConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListNPduUdpTxStartIdxOfTimeoutListNPduUdpTxConfig)
#define SoAd_GetTimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap(Index, partitionIndex)             (SoAd_GetTimeoutListNPduUdpTxMapOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap)
#define SoAd_GetTimeoutListMgmtIdxOfTimeoutListTcpAutoConnectConfig(Index, partitionIndex)          (SoAd_GetTimeoutListTcpAutoConnectConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListMgmtIdxOfTimeoutListTcpAutoConnectConfig)
#define SoAd_GetSoConIdxOfTimeoutListUdpAlive(Index, partitionIndex)                                (SoAd_GetTimeoutListUdpAliveOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdxOfTimeoutListUdpAlive)
#define SoAd_GetTimeoutOfTimeoutListUdpAlive(Index, partitionIndex)                                 (SoAd_GetTimeoutListUdpAliveOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutOfTimeoutListUdpAlive)
#define SoAd_GetTimeoutListMgmtIdxOfTimeoutListUdpAliveConfig(Index, partitionIndex)                (SoAd_GetTimeoutListUdpAliveConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListMgmtIdxOfTimeoutListUdpAliveConfig)
#define SoAd_GetTimeoutListUdpAliveEndIdxOfTimeoutListUdpAliveConfig(Index, partitionIndex)         (SoAd_GetTimeoutListUdpAliveConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListUdpAliveEndIdxOfTimeoutListUdpAliveConfig)
#define SoAd_GetTimeoutListUdpAliveStartIdxOfTimeoutListUdpAliveConfig(Index, partitionIndex)       (SoAd_GetTimeoutListUdpAliveConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListUdpAliveStartIdxOfTimeoutListUdpAliveConfig)
#define SoAd_GetTimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap(Index, partitionIndex)               (SoAd_GetTimeoutListUdpAliveMapOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap)
#define SoAd_GetTpRxBuffer(Index, partitionIndex)                                                   (SoAd_GetTpRxBufferOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_GetTpTxBuffer(Index, partitionIndex)                                                   (SoAd_GetTpTxBufferOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_GetTpTxBufferEndIdxOfTpTxBufferConfig(Index, partitionIndex)                           (SoAd_GetTpTxBufferConfigOfPCPartitionConfig(partitionIndex)[(Index)].TpTxBufferEndIdxOfTpTxBufferConfig)
#define SoAd_GetTpTxBufferStartIdxOfTpTxBufferConfig(Index, partitionIndex)                         (SoAd_GetTpTxBufferConfigOfPCPartitionConfig(partitionIndex)[(Index)].TpTxBufferStartIdxOfTpTxBufferConfig)
#define SoAd_GetTpTxBufferIdxOfTpTxBufferConfigDyn(Index, partitionIndex)                           (SoAd_GetTpTxBufferConfigDynOfPCPartitionConfig(partitionIndex)[(Index)].TpTxBufferIdxOfTpTxBufferConfigDyn)
#define SoAd_GetTriggerBuf(Index, partitionIndex)                                                   (SoAd_GetTriggerBufOfPCPartitionConfig(partitionIndex)[(Index)])
#define SoAd_GetTriggerBufEndIdxOfTriggerBufConfig(Index, partitionIndex)                           (SoAd_GetTriggerBufConfigOfPCPartitionConfig(partitionIndex)[(Index)].TriggerBufEndIdxOfTriggerBufConfig)
#define SoAd_GetTriggerBufStartIdxOfTriggerBufConfig(Index, partitionIndex)                         (SoAd_GetTriggerBufConfigOfPCPartitionConfig(partitionIndex)[(Index)].TriggerBufStartIdxOfTriggerBufConfig)
#define SoAd_GetLengthOfTriggerBufConfigDyn(Index, partitionIndex)                                  (SoAd_GetTriggerBufConfigDynOfPCPartitionConfig(partitionIndex)[(Index)].LengthOfTriggerBufConfigDyn)
#define SoAd_GetPduRouteIdxOfTriggerBufConfigDyn(Index, partitionIndex)                             (SoAd_GetTriggerBufConfigDynOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteIdxOfTriggerBufConfigDyn)
#define SoAd_IsCancelRequestedOfTxMgt(Index, partitionIndex)                                        ((SoAd_GetTxMgtOfPCPartitionConfig(partitionIndex)[(Index)].CancelRequestedOfTxMgt) != FALSE)
#define SoAd_GetPduRouteDestIdxOfTxMgt(Index, partitionIndex)                                       (SoAd_GetTxMgtOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteDestIdxOfTxMgt)
#define SoAd_GetTxBufPtrOfTxMgt(Index, partitionIndex)                                              (SoAd_GetTxMgtOfPCPartitionConfig(partitionIndex)[(Index)].TxBufPtrOfTxMgt)
#define SoAd_GetTxBytesLenOfTxMgt(Index, partitionIndex)                                            (SoAd_GetTxMgtOfPCPartitionConfig(partitionIndex)[(Index)].TxBytesLenOfTxMgt)
#define SoAd_GetTxBytesPendingOfTxMgt(Index, partitionIndex)                                        (SoAd_GetTxMgtOfPCPartitionConfig(partitionIndex)[(Index)].TxBytesPendingOfTxMgt)
#define SoAd_IsInvalidHndOfTxPduIdMap(Index)                                                        ((SoAd_GetTxPduIdMapOfPCPartitionConfig()[(Index)].InvalidHndOfTxPduIdMap) != FALSE)
#define SoAd_GetPartitionSpecificPduRouteIdxOfTxPduIdMap(Index)                                     (SoAd_GetTxPduIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificPduRouteIdxOfTxPduIdMap)
#define SoAd_GetPartitionSpecificPduRoutePartitionIdxOfTxPduIdMap(Index)                            (SoAd_GetTxPduIdMapOfPCPartitionConfig()[(Index)].PartitionSpecificPduRoutePartitionIdxOfTxPduIdMap)
#define SoAd_GetIfRxIndicationCbkOfUpperLayer(Index)                                                (SoAd_GetUpperLayerOfPCPartitionConfig()[(Index)].IfRxIndicationCbkOfUpperLayer)
#define SoAd_GetIfTriggerTransmitCbkOfUpperLayer(Index)                                             (SoAd_GetUpperLayerOfPCPartitionConfig()[(Index)].IfTriggerTransmitCbkOfUpperLayer)
#define SoAd_GetIfTxConfirmationCbkOfUpperLayer(Index)                                              (SoAd_GetUpperLayerOfPCPartitionConfig()[(Index)].IfTxConfirmationCbkOfUpperLayer)
#define SoAd_GetTpCopyRxDataCbkOfUpperLayer(Index)                                                  (SoAd_GetUpperLayerOfPCPartitionConfig()[(Index)].TpCopyRxDataCbkOfUpperLayer)
#define SoAd_GetTpCopyRxDataConstCbkOfUpperLayer(Index)                                             (SoAd_GetUpperLayerOfPCPartitionConfig()[(Index)].TpCopyRxDataConstCbkOfUpperLayer)
#define SoAd_GetTpCopyTxDataCbkOfUpperLayer(Index)                                                  (SoAd_GetUpperLayerOfPCPartitionConfig()[(Index)].TpCopyTxDataCbkOfUpperLayer)
#define SoAd_GetTpCopyTxDataConstCbkOfUpperLayer(Index)                                             (SoAd_GetUpperLayerOfPCPartitionConfig()[(Index)].TpCopyTxDataConstCbkOfUpperLayer)
#define SoAd_GetTpRxIndicationCbkOfUpperLayer(Index)                                                (SoAd_GetUpperLayerOfPCPartitionConfig()[(Index)].TpRxIndicationCbkOfUpperLayer)
#define SoAd_GetTpStartOfReceptionCbkOfUpperLayer(Index)                                            (SoAd_GetUpperLayerOfPCPartitionConfig()[(Index)].TpStartOfReceptionCbkOfUpperLayer)
#define SoAd_GetTpStartOfReceptionConstCbkOfUpperLayer(Index)                                       (SoAd_GetUpperLayerOfPCPartitionConfig()[(Index)].TpStartOfReceptionConstCbkOfUpperLayer)
#define SoAd_GetTpTxConfirmationCbkOfUpperLayer(Index)                                              (SoAd_GetUpperLayerOfPCPartitionConfig()[(Index)].TpTxConfirmationCbkOfUpperLayer)
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCGetDeduplicatedDataMacros  SoAd Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define SoAd_IsEventQueueIfTxRouteGrpConfigUsedOfEventQueueIdent(Index, partitionIndex)             (((boolean)(SoAd_GetEventQueueIfTxRouteGrpConfigIdxOfEventQueueIdent(((Index)), (partitionIndex)) != SOAD_NO_EVENTQUEUEIFTXROUTEGRPCONFIGIDXOFEVENTQUEUEIDENT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_EventQueueIfTxRouteGrpConfig */
#define SoAd_IsEventQueueIfUdpPduRouteConfigUsedOfEventQueueIdent(Index, partitionIndex)            (((boolean)(SoAd_GetEventQueueIfUdpPduRouteConfigIdxOfEventQueueIdent(((Index)), (partitionIndex)) != SOAD_NO_EVENTQUEUEIFUDPPDUROUTECONFIGIDXOFEVENTQUEUEIDENT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_EventQueueIfUdpPduRouteConfig */
#define SoAd_IsEventQueueTpRxSoConConfigUsedOfEventQueueIdent(Index, partitionIndex)                (((boolean)(SoAd_GetEventQueueTpRxSoConConfigIdxOfEventQueueIdent(((Index)), (partitionIndex)) != SOAD_NO_EVENTQUEUETPRXSOCONCONFIGIDXOFEVENTQUEUEIDENT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_EventQueueTpRxSoConConfig */
#define SoAd_IsEventQueueTpTxSoConConfigUsedOfEventQueueIdent(Index, partitionIndex)                (((boolean)(SoAd_GetEventQueueTpTxSoConConfigIdxOfEventQueueIdent(((Index)), (partitionIndex)) != SOAD_NO_EVENTQUEUETPTXSOCONCONFIGIDXOFEVENTQUEUEIDENT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_EventQueueTpTxSoConConfig */
#define SoAd_IsIpFragBufConfigUsedOfInstance(Index, partitionIndex)                                 (((boolean)(SoAd_GetIpFragBufConfigStartIdxOfInstance(((Index)), (partitionIndex)) != SOAD_NO_IPFRAGBUFCONFIGSTARTIDXOFINSTANCE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_IpFragBufConfig */
#define SoAd_IsTriggerBufConfigUsedOfInstance(Index, partitionIndex)                                (((boolean)(SoAd_GetTriggerBufConfigStartIdxOfInstance(((Index)), (partitionIndex)) != SOAD_NO_TRIGGERBUFCONFIGSTARTIDXOFINSTANCE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_TriggerBufConfig */
#define SoAd_IsSoConGrpUsedOfLocalAddr(Index, partitionIndex)                                       (((boolean)(SoAd_GetSoConGrpStartIdxOfLocalAddr(((Index)), (partitionIndex)) != SOAD_NO_SOCONGRPSTARTIDXOFLOCALADDR)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_SoConGrp */
#define SoAd_IsPartitionSpecificLocalAddrUsedOfLocalAddrIdMap(Index)                                (((boolean)(SoAd_GetPartitionSpecificLocalAddrIdxOfLocalAddrIdMap(Index) != SOAD_NO_PARTITIONSPECIFICLOCALADDRIDXOFLOCALADDRIDMAP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_LocalAddr */
#define SoAd_GetMaxIfRouteGrpTransmitPduSize(partitionIndex)                                        SoAd_GetMaxIfRouteGrpTransmitPduSizeOfPCPartitionConfig(partitionIndex)
#define SoAd_IsNPduUdpTxBufferUsedOfNPduUdpTx(Index, partitionIndex)                                (((boolean)(SoAd_GetNPduUdpTxBufferStartIdxOfNPduUdpTx(((Index)), (partitionIndex)) != SOAD_NO_NPDUUDPTXBUFFERSTARTIDXOFNPDUUDPTX)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_NPduUdpTxBuffer */
#define SoAd_IsNPduUdpTxQueueUsedOfNPduUdpTx(Index, partitionIndex)                                 (((boolean)(SoAd_GetNPduUdpTxQueueStartIdxOfNPduUdpTx(((Index)), (partitionIndex)) != SOAD_NO_NPDUUDPTXQUEUESTARTIDXOFNPDUUDPTX)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_NPduUdpTxQueue */
#define SoAd_IsRouteGrpSoConByPduRouteDestIndUsedOfPduRouteDest(Index, partitionIndex)              (((boolean)(SoAd_GetRouteGrpSoConByPduRouteDestIndStartIdxOfPduRouteDest(((Index)), (partitionIndex)) != SOAD_NO_ROUTEGRPSOCONBYPDUROUTEDESTINDSTARTIDXOFPDUROUTEDEST)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_RouteGrpSoConByPduRouteDestInd */
#define SoAd_IsPduRouteDestIndUsedOfRouteGrp(Index, partitionIndex)                                 (((boolean)(SoAd_GetPduRouteDestIndStartIdxOfRouteGrp(((Index)), (partitionIndex)) != SOAD_NO_PDUROUTEDESTINDSTARTIDXOFROUTEGRP)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_PduRouteDestInd */
#define SoAd_IsSocketRouteIndUsedOfRouteGrp(Index, partitionIndex)                                  (((boolean)(SoAd_GetSocketRouteIndStartIdxOfRouteGrp(((Index)), (partitionIndex)) != SOAD_NO_SOCKETROUTEINDSTARTIDXOFROUTEGRP)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_SocketRouteInd */
#define SoAd_IsPartitionSpecificRouteGrpUsedOfRouteGrpIdMap(Index)                                  (((boolean)(SoAd_GetPartitionSpecificRouteGrpIdxOfRouteGrpIdMap(Index) != SOAD_NO_PARTITIONSPECIFICROUTEGRPIDXOFROUTEGRPIDMAP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_RouteGrp */
#define SoAd_IsIfRxBufferUsedOfRxBufferConfig(Index, partitionIndex)                                (((boolean)(SoAd_GetIfRxBufferStartIdxOfRxBufferConfig(((Index)), (partitionIndex)) != SOAD_NO_IFRXBUFFERSTARTIDXOFRXBUFFERCONFIG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_IfRxBuffer */
#define SoAd_IsMetaDataRxBufferUsedOfRxBufferConfig(Index, partitionIndex)                          (((boolean)(SoAd_GetMetaDataRxBufferStartIdxOfRxBufferConfig(((Index)), (partitionIndex)) != SOAD_NO_METADATARXBUFFERSTARTIDXOFRXBUFFERCONFIG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_MetaDataRxBuffer */
#define SoAd_IsTpRxBufferUsedOfRxBufferConfig(Index, partitionIndex)                                (((boolean)(SoAd_GetTpRxBufferStartIdxOfRxBufferConfig(((Index)), (partitionIndex)) != SOAD_NO_TPRXBUFFERSTARTIDXOFRXBUFFERCONFIG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_TpRxBuffer */
#define SoAd_GetSizeOfBestMatchSoConIdxList(partitionIndex)                                         SoAd_GetSizeOfBestMatchSoConIdxListOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfDhcpEventCbk()                                                                SoAd_GetSizeOfDhcpEventCbkOfPCPartitionConfig()
#define SoAd_GetSizeOfEventQueueFlag(partitionIndex)                                                SoAd_GetSizeOfEventQueueFlagOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfEventQueueIdent(partitionIndex)                                               SoAd_GetSizeOfEventQueueIdentOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfEventQueueIfTxRouteGrp(partitionIndex)                                        SoAd_GetSizeOfEventQueueIfTxRouteGrpOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfEventQueueIfTxRouteGrpConfig(partitionIndex)                                  SoAd_GetSizeOfEventQueueIfTxRouteGrpConfigOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfEventQueueIfUdpPduRoute(partitionIndex)                                       SoAd_GetSizeOfEventQueueIfUdpPduRouteOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfEventQueueIfUdpPduRouteConfig(partitionIndex)                                 SoAd_GetSizeOfEventQueueIfUdpPduRouteConfigOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfEventQueueMgmt(partitionIndex)                                                SoAd_GetSizeOfEventQueueMgmtOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfEventQueueStateSoCon(partitionIndex)                                          SoAd_GetSizeOfEventQueueStateSoConOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfEventQueueStateSoConConfig(partitionIndex)                                    SoAd_GetSizeOfEventQueueStateSoConConfigOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfEventQueueTpRxSoCon(partitionIndex)                                           SoAd_GetSizeOfEventQueueTpRxSoConOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfEventQueueTpRxSoConConfig(partitionIndex)                                     SoAd_GetSizeOfEventQueueTpRxSoConConfigOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfEventQueueTpTxSoCon(partitionIndex)                                           SoAd_GetSizeOfEventQueueTpTxSoConOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfEventQueueTpTxSoConConfig(partitionIndex)                                     SoAd_GetSizeOfEventQueueTpTxSoConConfigOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfIfRxBuffer(partitionIndex)                                                    SoAd_GetSizeOfIfRxBufferOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfInstance(partitionIndex)                                                      SoAd_GetSizeOfInstanceOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfInstanceDyn(partitionIndex)                                                   SoAd_GetSizeOfInstanceDynOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfInstanceMap()                                                                 SoAd_GetSizeOfInstanceMapOfPCPartitionConfig()
#define SoAd_GetSizeOfIpFragBuf(partitionIndex)                                                     SoAd_GetSizeOfIpFragBufOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfIpFragBufConfig(partitionIndex)                                               SoAd_GetSizeOfIpFragBufConfigOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfIpFragBufConfigDyn(partitionIndex)                                            SoAd_GetSizeOfIpFragBufConfigDynOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfIpFragMgt(partitionIndex)                                                     SoAd_GetSizeOfIpFragMgtOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfLocalAddr(partitionIndex)                                                     SoAd_GetSizeOfLocalAddrOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfLocalAddrByTcpIpCtrlInd(partitionIndex)                                       SoAd_GetSizeOfLocalAddrByTcpIpCtrlIndOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfLocalAddrDyn(partitionIndex)                                                  SoAd_GetSizeOfLocalAddrDynOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfLocalAddrIdMap()                                                              SoAd_GetSizeOfLocalAddrIdMapOfPCPartitionConfig()
#define SoAd_GetSizeOfLocalIpAddrAssignmentChgCbk()                                                 SoAd_GetSizeOfLocalIpAddrAssignmentChgCbkOfPCPartitionConfig()
#define SoAd_GetSizeOfLocalIpAddrAssignmentChgCbkInd(partitionIndex)                                SoAd_GetSizeOfLocalIpAddrAssignmentChgCbkIndOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfMetaDataRxBuffer(partitionIndex)                                              SoAd_GetSizeOfMetaDataRxBufferOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfNPduUdpTx(partitionIndex)                                                     SoAd_GetSizeOfNPduUdpTxOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfNPduUdpTxBuffer(partitionIndex)                                               SoAd_GetSizeOfNPduUdpTxBufferOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfNPduUdpTxDyn(partitionIndex)                                                  SoAd_GetSizeOfNPduUdpTxDynOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfNPduUdpTxQueue(partitionIndex)                                                SoAd_GetSizeOfNPduUdpTxQueueOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfPartitionDyn(partitionIndex)                                                  SoAd_GetSizeOfPartitionDynOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfPartitionIdentifiers()                                                        SoAd_GetSizeOfPartitionIdentifiersOfPCConfig()
#define SoAd_GetSizeOfPduRoute(partitionIndex)                                                      SoAd_GetSizeOfPduRouteOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfPduRouteDest(partitionIndex)                                                  SoAd_GetSizeOfPduRouteDestOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfPduRouteDestBySoConInd(partitionIndex)                                        SoAd_GetSizeOfPduRouteDestBySoConIndOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfPduRouteDestInd(partitionIndex)                                               SoAd_GetSizeOfPduRouteDestIndOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfPduRouteDyn(partitionIndex)                                                   SoAd_GetSizeOfPduRouteDynOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfRemAddrIpV4(partitionIndex)                                                   SoAd_GetSizeOfRemAddrIpV4OfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfRemAddrIpV6(partitionIndex)                                                   SoAd_GetSizeOfRemAddrIpV6OfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfRemAddrRcv(partitionIndex)                                                    SoAd_GetSizeOfRemAddrRcvOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfRouteGrp(partitionIndex)                                                      SoAd_GetSizeOfRouteGrpOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfRouteGrpIdMap()                                                               SoAd_GetSizeOfRouteGrpIdMapOfPCPartitionConfig()
#define SoAd_GetSizeOfRouteGrpSoCon(partitionIndex)                                                 SoAd_GetSizeOfRouteGrpSoConOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfRouteGrpSoConByPduRouteDestInd(partitionIndex)                                SoAd_GetSizeOfRouteGrpSoConByPduRouteDestIndOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfRouteGrpSoConBySocketRouteDestInd(partitionIndex)                             SoAd_GetSizeOfRouteGrpSoConBySocketRouteDestIndOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfRouteGrpSoConDyn(partitionIndex)                                              SoAd_GetSizeOfRouteGrpSoConDynOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfRxBufStructMgt(partitionIndex)                                                SoAd_GetSizeOfRxBufStructMgtOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfRxBufStructSeg(partitionIndex)                                                SoAd_GetSizeOfRxBufStructSegOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfRxBufferConfig(partitionIndex)                                                SoAd_GetSizeOfRxBufferConfigOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfRxBufferConfigDyn(partitionIndex)                                             SoAd_GetSizeOfRxBufferConfigDynOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfRxMgt(partitionIndex)                                                         SoAd_GetSizeOfRxMgtOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfRxPduIdIdMap()                                                                SoAd_GetSizeOfRxPduIdIdMapOfPCPartitionConfig()
#define SoAd_GetSizeOfShutdownFinishedCbk()                                                         SoAd_GetSizeOfShutdownFinishedCbkOfPCPartitionConfig()
#define SoAd_GetSizeOfSoCon(partitionIndex)                                                         SoAd_GetSizeOfSoConOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfSoConDyn(partitionIndex)                                                      SoAd_GetSizeOfSoConDynOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfSoConGrp(partitionIndex)                                                      SoAd_GetSizeOfSoConGrpOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfSoConMap()                                                                    SoAd_GetSizeOfSoConMapOfPCPartitionConfig()
#define SoAd_GetSizeOfSoConModeChgCbk()                                                             SoAd_GetSizeOfSoConModeChgCbkOfPCPartitionConfig()
#define SoAd_GetSizeOfSoConModeChgCbkInd(partitionIndex)                                            SoAd_GetSizeOfSoConModeChgCbkIndOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfSocket(partitionIndex)                                                        SoAd_GetSizeOfSocketOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfSocketDyn(partitionIndex)                                                     SoAd_GetSizeOfSocketDynOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfSocketRoute(partitionIndex)                                                   SoAd_GetSizeOfSocketRouteOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfSocketRouteDest(partitionIndex)                                               SoAd_GetSizeOfSocketRouteDestOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfSocketRouteInd(partitionIndex)                                                SoAd_GetSizeOfSocketRouteIndOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfSocketTcp(partitionIndex)                                                     SoAd_GetSizeOfSocketTcpOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfSocketUdp(partitionIndex)                                                     SoAd_GetSizeOfSocketUdpOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTcpIpCtrl(partitionIndex)                                                     SoAd_GetSizeOfTcpIpCtrlOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTcpKeepAliveGloballyEnabled()                                                 SoAd_GetSizeOfTcpKeepAliveGloballyEnabledOfPCPartitionConfig()
#define SoAd_GetSizeOfTcpTxQueue(partitionIndex)                                                    SoAd_GetSizeOfTcpTxQueueOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTcpTxQueueData(partitionIndex)                                                SoAd_GetSizeOfTcpTxQueueDataOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTcpTxQueueMgt(partitionIndex)                                                 SoAd_GetSizeOfTcpTxQueueMgtOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTimeoutListIdent(partitionIndex)                                              SoAd_GetSizeOfTimeoutListIdentOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTimeoutListMgmt(partitionIndex)                                               SoAd_GetSizeOfTimeoutListMgmtOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTimeoutListNPduUdpTx(partitionIndex)                                          SoAd_GetSizeOfTimeoutListNPduUdpTxOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTimeoutListNPduUdpTxConfig(partitionIndex)                                    SoAd_GetSizeOfTimeoutListNPduUdpTxConfigOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTimeoutListNPduUdpTxMap(partitionIndex)                                       SoAd_GetSizeOfTimeoutListNPduUdpTxMapOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTimeoutListTcpAutoConnectConfig(partitionIndex)                               SoAd_GetSizeOfTimeoutListTcpAutoConnectConfigOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTimeoutListUdpAlive(partitionIndex)                                           SoAd_GetSizeOfTimeoutListUdpAliveOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTimeoutListUdpAliveConfig(partitionIndex)                                     SoAd_GetSizeOfTimeoutListUdpAliveConfigOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTimeoutListUdpAliveMap(partitionIndex)                                        SoAd_GetSizeOfTimeoutListUdpAliveMapOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTpRxBuffer(partitionIndex)                                                    SoAd_GetSizeOfTpRxBufferOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTpTxBuffer(partitionIndex)                                                    SoAd_GetSizeOfTpTxBufferOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTpTxBufferConfig(partitionIndex)                                              SoAd_GetSizeOfTpTxBufferConfigOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTpTxBufferConfigDyn(partitionIndex)                                           SoAd_GetSizeOfTpTxBufferConfigDynOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTriggerBuf(partitionIndex)                                                    SoAd_GetSizeOfTriggerBufOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTriggerBufConfig(partitionIndex)                                              SoAd_GetSizeOfTriggerBufConfigOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTriggerBufConfigDyn(partitionIndex)                                           SoAd_GetSizeOfTriggerBufConfigDynOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTxMgt(partitionIndex)                                                         SoAd_GetSizeOfTxMgtOfPCPartitionConfig(partitionIndex)
#define SoAd_GetSizeOfTxPduIdMap()                                                                  SoAd_GetSizeOfTxPduIdMapOfPCPartitionConfig()
#define SoAd_GetSizeOfUpperLayer()                                                                  SoAd_GetSizeOfUpperLayerOfPCPartitionConfig()
#define SoAd_IsIpFragMgtUsedOfSoCon(Index, partitionIndex)                                          (((boolean)(SoAd_GetIpFragMgtIdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_IPFRAGMGTIDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_IpFragMgt */
#define SoAd_IsLocalIpAddrAssignmentChgCbkIndUsedOfSoCon(Index, partitionIndex)                     (((boolean)(SoAd_GetLocalIpAddrAssignmentChgCbkIndStartIdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDSTARTIDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_LocalIpAddrAssignmentChgCbkInd */
#define SoAd_IsNPduUdpTxUsedOfSoCon(Index, partitionIndex)                                          (((boolean)(SoAd_GetNPduUdpTxIdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_NPDUUDPTXIDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_NPduUdpTx */
#define SoAd_IsPduRouteDestBySoConIndUsedOfSoCon(Index, partitionIndex)                             (((boolean)(SoAd_GetPduRouteDestBySoConIndStartIdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_PDUROUTEDESTBYSOCONINDSTARTIDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_PduRouteDestBySoConInd */
#define SoAd_IsRemAddrIpV4UsedOfSoCon(Index, partitionIndex)                                        (((boolean)(SoAd_GetRemAddrIpV4IdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_REMADDRIPV4IDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_RemAddrIpV4 */
#define SoAd_IsRemAddrIpV6UsedOfSoCon(Index, partitionIndex)                                        (((boolean)(SoAd_GetRemAddrIpV6IdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_REMADDRIPV6IDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_RemAddrIpV6 */
#define SoAd_IsRemAddrRcvUsedOfSoCon(Index, partitionIndex)                                         (((boolean)(SoAd_GetRemAddrRcvIdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_REMADDRRCVIDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_RemAddrRcv */
#define SoAd_IsRxBufStructMgtUsedOfSoCon(Index, partitionIndex)                                     (((boolean)(SoAd_GetRxBufStructMgtIdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_RXBUFSTRUCTMGTIDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_RxBufStructMgt */
#define SoAd_IsRxBufStructSegUsedOfSoCon(Index, partitionIndex)                                     (((boolean)(SoAd_GetRxBufStructSegStartIdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_RXBUFSTRUCTSEGSTARTIDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_RxBufStructSeg */
#define SoAd_IsRxBufferConfigUsedOfSoCon(Index, partitionIndex)                                     (((boolean)(SoAd_GetRxBufferConfigIdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_RXBUFFERCONFIGIDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_RxBufferConfig */
#define SoAd_IsRxMgtUsedOfSoCon(Index, partitionIndex)                                              (((boolean)(SoAd_GetRxMgtIdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_RXMGTIDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_RxMgt */
#define SoAd_IsSoConModeChgCbkIndUsedOfSoCon(Index, partitionIndex)                                 (((boolean)(SoAd_GetSoConModeChgCbkIndStartIdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_SOCONMODECHGCBKINDSTARTIDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_SoConModeChgCbkInd */
#define SoAd_IsSocketRouteUsedOfSoCon(Index, partitionIndex)                                        (((boolean)(SoAd_GetSocketRouteStartIdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_SOCKETROUTESTARTIDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_SocketRoute */
#define SoAd_IsTcpTxQueueUsedOfSoCon(Index, partitionIndex)                                         (((boolean)(SoAd_GetTcpTxQueueIdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_TCPTXQUEUEIDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_TcpTxQueue */
#define SoAd_IsTpTxBufferConfigUsedOfSoCon(Index, partitionIndex)                                   (((boolean)(SoAd_GetTpTxBufferConfigIdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_TPTXBUFFERCONFIGIDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_TpTxBufferConfig */
#define SoAd_IsTxMgtUsedOfSoCon(Index, partitionIndex)                                              (((boolean)(SoAd_GetTxMgtIdxOfSoCon(((Index)), (partitionIndex)) != SOAD_NO_TXMGTIDXOFSOCON)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_TxMgt */
#define SoAd_IsLocalAddrUsedOfSoConGrp(Index, partitionIndex)                                       (((boolean)(SoAd_GetLocalAddrIdxOfSoConGrp(((Index)), (partitionIndex)) != SOAD_NO_LOCALADDRIDXOFSOCONGRP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_LocalAddr */
#define SoAd_IsSocketTcpUsedOfSoConGrp(Index, partitionIndex)                                       (((boolean)(SoAd_GetSocketTcpIdxOfSoConGrp(((Index)), (partitionIndex)) != SOAD_NO_SOCKETTCPIDXOFSOCONGRP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_SocketTcp */
#define SoAd_IsSocketUdpUsedOfSoConGrp(Index, partitionIndex)                                       (((boolean)(SoAd_GetSocketUdpIdxOfSoConGrp(((Index)), (partitionIndex)) != SOAD_NO_SOCKETUDPIDXOFSOCONGRP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_SocketUdp */
#define SoAd_IsSocketUsedOfSoConGrp(Index, partitionIndex)                                          (((boolean)(SoAd_GetSocketIdxOfSoConGrp(((Index)), (partitionIndex)) != SOAD_NO_SOCKETIDXOFSOCONGRP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_Socket */
#define SoAd_IsRouteGrpSoConBySocketRouteDestIndUsedOfSocketRouteDest(Index, partitionIndex)        (((boolean)(SoAd_GetRouteGrpSoConBySocketRouteDestIndStartIdxOfSocketRouteDest(((Index)), (partitionIndex)) != SOAD_NO_ROUTEGRPSOCONBYSOCKETROUTEDESTINDSTARTIDXOFSOCKETROUTEDEST)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_RouteGrpSoConBySocketRouteDestInd */
#define SoAd_IsLocalAddrByTcpIpCtrlIndUsedOfTcpIpCtrl(Index, partitionIndex)                        (((boolean)(SoAd_GetLocalAddrByTcpIpCtrlIndStartIdxOfTcpIpCtrl(((Index)), (partitionIndex)) != SOAD_NO_LOCALADDRBYTCPIPCTRLINDSTARTIDXOFTCPIPCTRL)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_LocalAddrByTcpIpCtrlInd */
#define SoAd_IsTimeoutListNPduUdpTxConfigUsedOfTimeoutListIdent(Index, partitionIndex)              (((boolean)(SoAd_GetTimeoutListNPduUdpTxConfigIdxOfTimeoutListIdent(((Index)), (partitionIndex)) != SOAD_NO_TIMEOUTLISTNPDUUDPTXCONFIGIDXOFTIMEOUTLISTIDENT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_TimeoutListNPduUdpTxConfig */
#define SoAd_IsTimeoutListTcpAutoConnectConfigUsedOfTimeoutListIdent(Index, partitionIndex)         (((boolean)(SoAd_GetTimeoutListTcpAutoConnectConfigIdxOfTimeoutListIdent(((Index)), (partitionIndex)) != SOAD_NO_TIMEOUTLISTTCPAUTOCONNECTCONFIGIDXOFTIMEOUTLISTIDENT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_TimeoutListTcpAutoConnectConfig */
#define SoAd_IsTimeoutListUdpAliveConfigUsedOfTimeoutListIdent(Index, partitionIndex)               (((boolean)(SoAd_GetTimeoutListUdpAliveConfigIdxOfTimeoutListIdent(((Index)), (partitionIndex)) != SOAD_NO_TIMEOUTLISTUDPALIVECONFIGIDXOFTIMEOUTLISTIDENT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to SoAd_TimeoutListUdpAliveConfig */
#define SoAd_IsTpTxBufferUsedOfTpTxBufferConfig(Index, partitionIndex)                              (((boolean)(SoAd_GetTpTxBufferStartIdxOfTpTxBufferConfig(((Index)), (partitionIndex)) != SOAD_NO_TPTXBUFFERSTARTIDXOFTPTXBUFFERCONFIG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SoAd_TpTxBuffer */
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCSetDataMacros  SoAd Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define SoAd_SetSoConIdxOfBestMatchSoConIdxList(Index, Value, partitionIndex)                       SoAd_GetBestMatchSoConIdxListOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdxOfBestMatchSoConIdxList = (Value)
#define SoAd_SetEventQueueFlag(Index, Value, partitionIndex)                                        SoAd_GetEventQueueFlagOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define SoAd_SetRouteGrpIdxOfEventQueueIfTxRouteGrp(Index, Value, partitionIndex)                   SoAd_GetEventQueueIfTxRouteGrpOfPCPartitionConfig(partitionIndex)[(Index)].RouteGrpIdxOfEventQueueIfTxRouteGrp = (Value)
#define SoAd_SetPduRouteIdxOfEventQueueIfUdpPduRoute(Index, Value, partitionIndex)                  SoAd_GetEventQueueIfUdpPduRouteOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteIdxOfEventQueueIfUdpPduRoute = (Value)
#define SoAd_SetIdxOfEventQueueMgmt(Index, Value, partitionIndex)                                   SoAd_GetEventQueueMgmtOfPCPartitionConfig(partitionIndex)[(Index)].IdxOfEventQueueMgmt = (Value)
#define SoAd_SetLvlOfEventQueueMgmt(Index, Value, partitionIndex)                                   SoAd_GetEventQueueMgmtOfPCPartitionConfig(partitionIndex)[(Index)].LvlOfEventQueueMgmt = (Value)
#define SoAd_SetSoConIdxOfEventQueueStateSoCon(Index, Value, partitionIndex)                        SoAd_GetEventQueueStateSoConOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdxOfEventQueueStateSoCon = (Value)
#define SoAd_SetSoConIdxOfEventQueueTpRxSoCon(Index, Value, partitionIndex)                         SoAd_GetEventQueueTpRxSoConOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdxOfEventQueueTpRxSoCon = (Value)
#define SoAd_SetSoConIdxOfEventQueueTpTxSoCon(Index, Value, partitionIndex)                         SoAd_GetEventQueueTpTxSoConOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdxOfEventQueueTpTxSoCon = (Value)
#define SoAd_SetIfRxBuffer(Index, Value, partitionIndex)                                            SoAd_GetIfRxBufferOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define SoAd_SetBestMatchListSizeOfInstanceDyn(Index, Value, partitionIndex)                        SoAd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].BestMatchListSizeOfInstanceDyn = (Value)
#define SoAd_SetCounterOfInstanceDyn(Index, Value, partitionIndex)                                  SoAd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].CounterOfInstanceDyn = (Value)
#define SoAd_SetOpenSocksOfInstanceDyn(Index, Value, partitionIndex)                                SoAd_GetInstanceDynOfPCPartitionConfig(partitionIndex)[(Index)].OpenSocksOfInstanceDyn = (Value)
#define SoAd_SetIpFragBuf(Index, Value, partitionIndex)                                             SoAd_GetIpFragBufOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define SoAd_SetLengthOfIpFragBufConfigDyn(Index, Value, partitionIndex)                            SoAd_GetIpFragBufConfigDynOfPCPartitionConfig(partitionIndex)[(Index)].LengthOfIpFragBufConfigDyn = (Value)
#define SoAd_SetIpFragBufConfigIdxOfIpFragMgt(Index, Value, partitionIndex)                         SoAd_GetIpFragMgtOfPCPartitionConfig(partitionIndex)[(Index)].IpFragBufConfigIdxOfIpFragMgt = (Value)
#define SoAd_SetIpAddrStateOfLocalAddrDyn(Index, Value, partitionIndex)                             SoAd_GetLocalAddrDynOfPCPartitionConfig(partitionIndex)[(Index)].IpAddrStateOfLocalAddrDyn = (Value)
#define SoAd_SetMetaDataRxBuffer(Index, Value, partitionIndex)                                      SoAd_GetMetaDataRxBufferOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define SoAd_SetNPduUdpTxBuffer(Index, Value, partitionIndex)                                       SoAd_GetNPduUdpTxBufferOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define SoAd_SetBufLenOfNPduUdpTxDyn(Index, Value, partitionIndex)                                  SoAd_GetNPduUdpTxDynOfPCPartitionConfig(partitionIndex)[(Index)].BufLenOfNPduUdpTxDyn = (Value)
#define SoAd_SetLvlOfNPduUdpTxDyn(Index, Value, partitionIndex)                                     SoAd_GetNPduUdpTxDynOfPCPartitionConfig(partitionIndex)[(Index)].LvlOfNPduUdpTxDyn = (Value)
#define SoAd_SetRetryCntOfNPduUdpTxDyn(Index, Value, partitionIndex)                                SoAd_GetNPduUdpTxDynOfPCPartitionConfig(partitionIndex)[(Index)].RetryCntOfNPduUdpTxDyn = (Value)
#define SoAd_SetTotalLenOfNPduUdpTxDyn(Index, Value, partitionIndex)                                SoAd_GetNPduUdpTxDynOfPCPartitionConfig(partitionIndex)[(Index)].TotalLenOfNPduUdpTxDyn = (Value)
#define SoAd_SetTransmissionStateOfNPduUdpTxDyn(Index, Value, partitionIndex)                       SoAd_GetNPduUdpTxDynOfPCPartitionConfig(partitionIndex)[(Index)].TransmissionStateOfNPduUdpTxDyn = (Value)
#define SoAd_SetCopiedOfNPduUdpTxQueue(Index, Value, partitionIndex)                                SoAd_GetNPduUdpTxQueueOfPCPartitionConfig(partitionIndex)[(Index)].CopiedOfNPduUdpTxQueue = (Value)
#define SoAd_SetLenOfNPduUdpTxQueue(Index, Value, partitionIndex)                                   SoAd_GetNPduUdpTxQueueOfPCPartitionConfig(partitionIndex)[(Index)].LenOfNPduUdpTxQueue = (Value)
#define SoAd_SetNPduUdpTxBufferIdxOfNPduUdpTxQueue(Index, Value, partitionIndex)                    SoAd_GetNPduUdpTxQueueOfPCPartitionConfig(partitionIndex)[(Index)].NPduUdpTxBufferIdxOfNPduUdpTxQueue = (Value)
#define SoAd_SetPduRouteDestIdxOfNPduUdpTxQueue(Index, Value, partitionIndex)                       SoAd_GetNPduUdpTxQueueOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteDestIdxOfNPduUdpTxQueue = (Value)
#define SoAd_SetInitializedOfPartitionDyn(Index, Value, partitionIndex)                             SoAd_GetPartitionDynOfPCPartitionConfig(partitionIndex)[(Index)].InitializedOfPartitionDyn = (Value)
#define SoAd_SetPendingTxConfMainOfPduRouteDyn(Index, Value, partitionIndex)                        SoAd_GetPduRouteDynOfPCPartitionConfig(partitionIndex)[(Index)].PendingTxConfMainOfPduRouteDyn = (Value)
#define SoAd_SetPendingTxConfNumOfPduRouteDyn(Index, Value, partitionIndex)                         SoAd_GetPduRouteDynOfPCPartitionConfig(partitionIndex)[(Index)].PendingTxConfNumOfPduRouteDyn = (Value)
#define SoAd_SetRemAddrRcv(Index, Value, partitionIndex)                                            SoAd_GetRemAddrRcvOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define SoAd_SetEnabledOfRouteGrpSoConDyn(Index, Value, partitionIndex)                             SoAd_GetRouteGrpSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].EnabledOfRouteGrpSoConDyn = (Value)
#define SoAd_SetFlagsOfRouteGrpSoConDyn(Index, Value, partitionIndex)                               SoAd_GetRouteGrpSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].FlagsOfRouteGrpSoConDyn = (Value)
#define SoAd_SetRxBufStructSegIdxOfRxBufStructMgt(Index, Value, partitionIndex)                     SoAd_GetRxBufStructMgtOfPCPartitionConfig(partitionIndex)[(Index)].RxBufStructSegIdxOfRxBufStructMgt = (Value)
#define SoAd_SetRxBufStructSegLvlOfRxBufStructMgt(Index, Value, partitionIndex)                     SoAd_GetRxBufStructMgtOfPCPartitionConfig(partitionIndex)[(Index)].RxBufStructSegLvlOfRxBufStructMgt = (Value)
#define SoAd_SetDataPtrOfRxBufStructSeg(Index, Value, partitionIndex)                               SoAd_GetRxBufStructSegOfPCPartitionConfig(partitionIndex)[(Index)].DataPtrOfRxBufStructSeg = (Value)
#define SoAd_SetLenOfRxBufStructSeg(Index, Value, partitionIndex)                                   SoAd_GetRxBufStructSegOfPCPartitionConfig(partitionIndex)[(Index)].LenOfRxBufStructSeg = (Value)
#define SoAd_SetIfRxBufferIdxOfRxBufferConfigDyn(Index, Value, partitionIndex)                      SoAd_GetRxBufferConfigDynOfPCPartitionConfig(partitionIndex)[(Index)].IfRxBufferIdxOfRxBufferConfigDyn = (Value)
#define SoAd_SetTpRxBufferIdxOfRxBufferConfigDyn(Index, Value, partitionIndex)                      SoAd_GetRxBufferConfigDynOfPCPartitionConfig(partitionIndex)[(Index)].TpRxBufferIdxOfRxBufferConfigDyn = (Value)
#define SoAd_SetCancelRequestedOfRxMgt(Index, Value, partitionIndex)                                SoAd_GetRxMgtOfPCPartitionConfig(partitionIndex)[(Index)].CancelRequestedOfRxMgt = (Value)
#define SoAd_SetRxBytesPendingOfRxMgt(Index, Value, partitionIndex)                                 SoAd_GetRxMgtOfPCPartitionConfig(partitionIndex)[(Index)].RxBytesPendingOfRxMgt = (Value)
#define SoAd_SetSocketRouteDestIdxOfRxMgt(Index, Value, partitionIndex)                             SoAd_GetRxMgtOfPCPartitionConfig(partitionIndex)[(Index)].SocketRouteDestIdxOfRxMgt = (Value)
#define SoAd_SetAbortOfSoConDyn(Index, Value, partitionIndex)                                       SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].AbortOfSoConDyn = (Value)
#define SoAd_SetCloseModeOfSoConDyn(Index, Value, partitionIndex)                                   SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].CloseModeOfSoConDyn = (Value)
#define SoAd_SetModeOfSoConDyn(Index, Value, partitionIndex)                                        SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].ModeOfSoConDyn = (Value)
#define SoAd_SetOpenCloseCounterOfSoConDyn(Index, Value, partitionIndex)                            SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].OpenCloseCounterOfSoConDyn = (Value)
#define SoAd_SetRemAddrDynOfSoConDyn(Index, Value, partitionIndex)                                  SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].RemAddrDynOfSoConDyn = (Value)
#define SoAd_SetRemAddrReleaseOfSoConDyn(Index, Value, partitionIndex)                              SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].RemAddrReleaseOfSoConDyn = (Value)
#define SoAd_SetRemAddrStateDynOfSoConDyn(Index, Value, partitionIndex)                             SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].RemAddrStateDynOfSoConDyn = (Value)
#define SoAd_SetRxActiveOfSoConDyn(Index, Value, partitionIndex)                                    SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].RxActiveOfSoConDyn = (Value)
#define SoAd_SetTimeoutOccurredOfSoConDyn(Index, Value, partitionIndex)                             SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutOccurredOfSoConDyn = (Value)
#define SoAd_SetTxActiveOfSoConDyn(Index, Value, partitionIndex)                                    SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex)[(Index)].TxActiveOfSoConDyn = (Value)
#define SoAd_SetLocalPortOfSocketDyn(Index, Value, partitionIndex)                                  SoAd_GetSocketDynOfPCPartitionConfig(partitionIndex)[(Index)].LocalPortOfSocketDyn = (Value)
#define SoAd_SetSkipBytesOfSocketDyn(Index, Value, partitionIndex)                                  SoAd_GetSocketDynOfPCPartitionConfig(partitionIndex)[(Index)].SkipBytesOfSocketDyn = (Value)
#define SoAd_SetSoConTxActiveIdxOfSocketDyn(Index, Value, partitionIndex)                           SoAd_GetSocketDynOfPCPartitionConfig(partitionIndex)[(Index)].SoConTxActiveIdxOfSocketDyn = (Value)
#define SoAd_SetSocketIdOfSocketDyn(Index, Value, partitionIndex)                                   SoAd_GetSocketDynOfPCPartitionConfig(partitionIndex)[(Index)].SocketIdOfSocketDyn = (Value)
#define SoAd_SetStateOfSocketDyn(Index, Value, partitionIndex)                                      SoAd_GetSocketDynOfPCPartitionConfig(partitionIndex)[(Index)].StateOfSocketDyn = (Value)
#define SoAd_SetLenOfTcpTxQueueData(Index, Value, partitionIndex)                                   SoAd_GetTcpTxQueueDataOfPCPartitionConfig(partitionIndex)[(Index)].LenOfTcpTxQueueData = (Value)
#define SoAd_SetPduRouteIdxOfTcpTxQueueData(Index, Value, partitionIndex)                           SoAd_GetTcpTxQueueDataOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteIdxOfTcpTxQueueData = (Value)
#define SoAd_SetLvlOfTcpTxQueueMgt(Index, Value, partitionIndex)                                    SoAd_GetTcpTxQueueMgtOfPCPartitionConfig(partitionIndex)[(Index)].LvlOfTcpTxQueueMgt = (Value)
#define SoAd_SetTcpTxQueueDataIdxOfTcpTxQueueMgt(Index, Value, partitionIndex)                      SoAd_GetTcpTxQueueMgtOfPCPartitionConfig(partitionIndex)[(Index)].TcpTxQueueDataIdxOfTcpTxQueueMgt = (Value)
#define SoAd_SetTotLenOfTcpTxQueueMgt(Index, Value, partitionIndex)                                 SoAd_GetTcpTxQueueMgtOfPCPartitionConfig(partitionIndex)[(Index)].TotLenOfTcpTxQueueMgt = (Value)
#define SoAd_SetLvlOfTimeoutListMgmt(Index, Value, partitionIndex)                                  SoAd_GetTimeoutListMgmtOfPCPartitionConfig(partitionIndex)[(Index)].LvlOfTimeoutListMgmt = (Value)
#define SoAd_SetNPduUdpTxIdxOfTimeoutListNPduUdpTx(Index, Value, partitionIndex)                    SoAd_GetTimeoutListNPduUdpTxOfPCPartitionConfig(partitionIndex)[(Index)].NPduUdpTxIdxOfTimeoutListNPduUdpTx = (Value)
#define SoAd_SetTimeoutOfTimeoutListNPduUdpTx(Index, Value, partitionIndex)                         SoAd_GetTimeoutListNPduUdpTxOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutOfTimeoutListNPduUdpTx = (Value)
#define SoAd_SetTimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap(Index, Value, partitionIndex)      SoAd_GetTimeoutListNPduUdpTxMapOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap = (Value)
#define SoAd_SetSoConIdxOfTimeoutListUdpAlive(Index, Value, partitionIndex)                         SoAd_GetTimeoutListUdpAliveOfPCPartitionConfig(partitionIndex)[(Index)].SoConIdxOfTimeoutListUdpAlive = (Value)
#define SoAd_SetTimeoutOfTimeoutListUdpAlive(Index, Value, partitionIndex)                          SoAd_GetTimeoutListUdpAliveOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutOfTimeoutListUdpAlive = (Value)
#define SoAd_SetTimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap(Index, Value, partitionIndex)        SoAd_GetTimeoutListUdpAliveMapOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap = (Value)
#define SoAd_SetTpRxBuffer(Index, Value, partitionIndex)                                            SoAd_GetTpRxBufferOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define SoAd_SetTpTxBuffer(Index, Value, partitionIndex)                                            SoAd_GetTpTxBufferOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define SoAd_SetTpTxBufferIdxOfTpTxBufferConfigDyn(Index, Value, partitionIndex)                    SoAd_GetTpTxBufferConfigDynOfPCPartitionConfig(partitionIndex)[(Index)].TpTxBufferIdxOfTpTxBufferConfigDyn = (Value)
#define SoAd_SetTriggerBuf(Index, Value, partitionIndex)                                            SoAd_GetTriggerBufOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define SoAd_SetLengthOfTriggerBufConfigDyn(Index, Value, partitionIndex)                           SoAd_GetTriggerBufConfigDynOfPCPartitionConfig(partitionIndex)[(Index)].LengthOfTriggerBufConfigDyn = (Value)
#define SoAd_SetPduRouteIdxOfTriggerBufConfigDyn(Index, Value, partitionIndex)                      SoAd_GetTriggerBufConfigDynOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteIdxOfTriggerBufConfigDyn = (Value)
#define SoAd_SetCancelRequestedOfTxMgt(Index, Value, partitionIndex)                                SoAd_GetTxMgtOfPCPartitionConfig(partitionIndex)[(Index)].CancelRequestedOfTxMgt = (Value)
#define SoAd_SetPduRouteDestIdxOfTxMgt(Index, Value, partitionIndex)                                SoAd_GetTxMgtOfPCPartitionConfig(partitionIndex)[(Index)].PduRouteDestIdxOfTxMgt = (Value)
#define SoAd_SetTxBufPtrOfTxMgt(Index, Value, partitionIndex)                                       SoAd_GetTxMgtOfPCPartitionConfig(partitionIndex)[(Index)].TxBufPtrOfTxMgt = (Value)
#define SoAd_SetTxBytesLenOfTxMgt(Index, Value, partitionIndex)                                     SoAd_GetTxMgtOfPCPartitionConfig(partitionIndex)[(Index)].TxBytesLenOfTxMgt = (Value)
#define SoAd_SetTxBytesPendingOfTxMgt(Index, Value, partitionIndex)                                 SoAd_GetTxMgtOfPCPartitionConfig(partitionIndex)[(Index)].TxBytesPendingOfTxMgt = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCGetAddressOfDataMacros  SoAd Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define SoAd_GetAddrIfRxBuffer(Index, partitionIndex)                                               (&SoAd_GetIfRxBuffer(((Index)), (partitionIndex)))
#define SoAd_GetAddrOpenSocksOfInstanceDyn(Index, partitionIndex)                                   (&SoAd_GetOpenSocksOfInstanceDyn(((Index)), (partitionIndex)))
#define SoAd_GetAddrIpFragBuf(Index, partitionIndex)                                                (&SoAd_GetIpFragBuf(((Index)), (partitionIndex)))
#define SoAd_GetAddrMetaDataRxBuffer(Index, partitionIndex)                                         (&SoAd_GetMetaDataRxBuffer(((Index)), (partitionIndex)))
#define SoAd_GetAddrNPduUdpTxBuffer(Index, partitionIndex)                                          (&SoAd_GetNPduUdpTxBuffer(((Index)), (partitionIndex)))
#define SoAd_GetAddrInitializedOfPartitionDyn(Index, partitionIndex)                                (&SoAd_GetInitializedOfPartitionDyn(((Index)), (partitionIndex)))
#define SoAd_GetAddrAddrOfRemAddrIpV4(Index, partitionIndex)                                        (&SoAd_GetAddrOfRemAddrIpV4(((Index)), (partitionIndex)))
#define SoAd_GetAddrAddrOfRemAddrIpV6(Index, partitionIndex)                                        (&SoAd_GetAddrOfRemAddrIpV6(((Index)), (partitionIndex)))
#define SoAd_GetAddrRemAddrRcv(Index, partitionIndex)                                               (&SoAd_GetRemAddrRcv(((Index)), (partitionIndex)))
#define SoAd_GetAddrFlagsOfRouteGrpSoConDyn(Index, partitionIndex)                                  (&SoAd_GetFlagsOfRouteGrpSoConDyn(((Index)), (partitionIndex)))
#define SoAd_GetAddrDataPtrOfRxBufStructSeg(Index, partitionIndex)                                  (&SoAd_GetDataPtrOfRxBufStructSeg(((Index)), (partitionIndex)))
#define SoAd_GetAddrRemAddrDynOfSoConDyn(Index, partitionIndex)                                     (&SoAd_GetRemAddrDynOfSoConDyn(((Index)), (partitionIndex)))
#define SoAd_GetAddrTpRxBuffer(Index, partitionIndex)                                               (&SoAd_GetTpRxBuffer(((Index)), (partitionIndex)))
#define SoAd_GetAddrTpTxBuffer(Index, partitionIndex)                                               (&SoAd_GetTpTxBuffer(((Index)), (partitionIndex)))
#define SoAd_GetAddrTriggerBuf(Index, partitionIndex)                                               (&SoAd_GetTriggerBuf(((Index)), (partitionIndex)))
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCHasMacros  SoAd Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define SoAd_HasBestMatchSoConIdxList(partitionIndex)                                               (SoAd_GetBestMatchSoConIdxListOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasSoConIdxOfBestMatchSoConIdxList(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasDhcpEventCbk()                                                                      (SoAd_GetDhcpEventCbkOfPCPartitionConfig() != NULL_PTR)
#define SoAd_HasEventQueueFlag(partitionIndex)                                                      (SoAd_GetEventQueueFlagOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasEventQueueIdent(partitionIndex)                                                     (SoAd_GetEventQueueIdentOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasEventQueueFlagEndIdxOfEventQueueIdent(partitionIndex)                               (TRUE != FALSE)
#define SoAd_HasEventQueueFlagStartIdxOfEventQueueIdent(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasEventQueueIfTxRouteGrpConfigIdxOfEventQueueIdent(partitionIndex)                    (TRUE != FALSE)
#define SoAd_HasEventQueueIfTxRouteGrpConfigUsedOfEventQueueIdent(partitionIndex)                   (TRUE != FALSE)
#define SoAd_HasEventQueueIfUdpPduRouteConfigIdxOfEventQueueIdent(partitionIndex)                   (TRUE != FALSE)
#define SoAd_HasEventQueueIfUdpPduRouteConfigUsedOfEventQueueIdent(partitionIndex)                  (TRUE != FALSE)
#define SoAd_HasEventQueueStateSoConConfigIdxOfEventQueueIdent(partitionIndex)                      (TRUE != FALSE)
#define SoAd_HasEventQueueTpRxSoConConfigIdxOfEventQueueIdent(partitionIndex)                       (TRUE != FALSE)
#define SoAd_HasEventQueueTpRxSoConConfigUsedOfEventQueueIdent(partitionIndex)                      (TRUE != FALSE)
#define SoAd_HasEventQueueTpTxSoConConfigIdxOfEventQueueIdent(partitionIndex)                       (TRUE != FALSE)
#define SoAd_HasEventQueueTpTxSoConConfigUsedOfEventQueueIdent(partitionIndex)                      (TRUE != FALSE)
#define SoAd_HasEventQueueIfTxRouteGrp(partitionIndex)                                              (SoAd_GetEventQueueIfTxRouteGrpOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasRouteGrpIdxOfEventQueueIfTxRouteGrp(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasEventQueueIfTxRouteGrpConfig(partitionIndex)                                        (SoAd_GetEventQueueIfTxRouteGrpConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasEventQueueIfTxRouteGrpEndIdxOfEventQueueIfTxRouteGrpConfig(partitionIndex)          (TRUE != FALSE)
#define SoAd_HasEventQueueIfTxRouteGrpStartIdxOfEventQueueIfTxRouteGrpConfig(partitionIndex)        (TRUE != FALSE)
#define SoAd_HasEventQueueMgmtIdxOfEventQueueIfTxRouteGrpConfig(partitionIndex)                     (TRUE != FALSE)
#define SoAd_HasFlagOffsetOfEventQueueIfTxRouteGrpConfig(partitionIndex)                            (TRUE != FALSE)
#define SoAd_HasLimitOfEventQueueIfTxRouteGrpConfig(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasEventQueueIfUdpPduRoute(partitionIndex)                                             (SoAd_GetEventQueueIfUdpPduRouteOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasPduRouteIdxOfEventQueueIfUdpPduRoute(partitionIndex)                                (TRUE != FALSE)
#define SoAd_HasEventQueueIfUdpPduRouteConfig(partitionIndex)                                       (SoAd_GetEventQueueIfUdpPduRouteConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasEventQueueIfUdpPduRouteEndIdxOfEventQueueIfUdpPduRouteConfig(partitionIndex)        (TRUE != FALSE)
#define SoAd_HasEventQueueIfUdpPduRouteStartIdxOfEventQueueIfUdpPduRouteConfig(partitionIndex)      (TRUE != FALSE)
#define SoAd_HasEventQueueMgmtIdxOfEventQueueIfUdpPduRouteConfig(partitionIndex)                    (TRUE != FALSE)
#define SoAd_HasFlagOffsetOfEventQueueIfUdpPduRouteConfig(partitionIndex)                           (TRUE != FALSE)
#define SoAd_HasLimitOfEventQueueIfUdpPduRouteConfig(partitionIndex)                                (TRUE != FALSE)
#define SoAd_HasEventQueueMgmt(partitionIndex)                                                      (SoAd_GetEventQueueMgmtOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasIdxOfEventQueueMgmt(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasLvlOfEventQueueMgmt(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasEventQueueStateSoCon(partitionIndex)                                                (SoAd_GetEventQueueStateSoConOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasSoConIdxOfEventQueueStateSoCon(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasEventQueueStateSoConConfig(partitionIndex)                                          (SoAd_GetEventQueueStateSoConConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasEventQueueMgmtIdxOfEventQueueStateSoConConfig(partitionIndex)                       (TRUE != FALSE)
#define SoAd_HasEventQueueStateSoConEndIdxOfEventQueueStateSoConConfig(partitionIndex)              (TRUE != FALSE)
#define SoAd_HasEventQueueStateSoConStartIdxOfEventQueueStateSoConConfig(partitionIndex)            (TRUE != FALSE)
#define SoAd_HasFlagOffsetOfEventQueueStateSoConConfig(partitionIndex)                              (TRUE != FALSE)
#define SoAd_HasLimitOfEventQueueStateSoConConfig(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasEventQueueTpRxSoCon(partitionIndex)                                                 (SoAd_GetEventQueueTpRxSoConOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasSoConIdxOfEventQueueTpRxSoCon(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasEventQueueTpRxSoConConfig(partitionIndex)                                           (SoAd_GetEventQueueTpRxSoConConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasEventQueueMgmtIdxOfEventQueueTpRxSoConConfig(partitionIndex)                        (TRUE != FALSE)
#define SoAd_HasEventQueueTpRxSoConEndIdxOfEventQueueTpRxSoConConfig(partitionIndex)                (TRUE != FALSE)
#define SoAd_HasEventQueueTpRxSoConStartIdxOfEventQueueTpRxSoConConfig(partitionIndex)              (TRUE != FALSE)
#define SoAd_HasFlagOffsetOfEventQueueTpRxSoConConfig(partitionIndex)                               (TRUE != FALSE)
#define SoAd_HasLimitOfEventQueueTpRxSoConConfig(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasEventQueueTpTxSoCon(partitionIndex)                                                 (SoAd_GetEventQueueTpTxSoConOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasSoConIdxOfEventQueueTpTxSoCon(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasEventQueueTpTxSoConConfig(partitionIndex)                                           (SoAd_GetEventQueueTpTxSoConConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasEventQueueMgmtIdxOfEventQueueTpTxSoConConfig(partitionIndex)                        (TRUE != FALSE)
#define SoAd_HasEventQueueTpTxSoConEndIdxOfEventQueueTpTxSoConConfig(partitionIndex)                (TRUE != FALSE)
#define SoAd_HasEventQueueTpTxSoConStartIdxOfEventQueueTpTxSoConConfig(partitionIndex)              (TRUE != FALSE)
#define SoAd_HasFlagOffsetOfEventQueueTpTxSoConConfig(partitionIndex)                               (TRUE != FALSE)
#define SoAd_HasLimitOfEventQueueTpTxSoConConfig(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasIfRxBuffer(partitionIndex)                                                          (SoAd_GetIfRxBufferOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasInstance(partitionIndex)                                                            (SoAd_GetInstanceOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasBestMatchSoConIdxListEndIdxOfInstance(partitionIndex)                               (TRUE != FALSE)
#define SoAd_HasBestMatchSoConIdxListStartIdxOfInstance(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasEventQueueIdentIdxOfInstance(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasIpFragBufConfigEndIdxOfInstance(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasIpFragBufConfigStartIdxOfInstance(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasIpFragBufConfigUsedOfInstance(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasTimeoutListIdentIdxOfInstance(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasTriggerBufConfigEndIdxOfInstance(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasTriggerBufConfigStartIdxOfInstance(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasTriggerBufConfigUsedOfInstance(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasInstanceDyn(partitionIndex)                                                         (SoAd_GetInstanceDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasBestMatchListSizeOfInstanceDyn(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasCounterOfInstanceDyn(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasOpenSocksOfInstanceDyn(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasInstanceMap()                                                                       (SoAd_GetInstanceMapOfPCPartitionConfig() != NULL_PTR)
#define SoAd_HasPartitionSpecificInstanceIdxOfInstanceMap()                                         (TRUE != FALSE)
#define SoAd_HasPartitionSpecificInstancePartitionIdxOfInstanceMap()                                (TRUE != FALSE)
#define SoAd_HasIpFragBuf(partitionIndex)                                                           (SoAd_GetIpFragBufOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasIpFragBufConfig(partitionIndex)                                                     (SoAd_GetIpFragBufConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasIpFragBufEndIdxOfIpFragBufConfig(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasIpFragBufStartIdxOfIpFragBufConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasIpFragBufConfigDyn(partitionIndex)                                                  (SoAd_GetIpFragBufConfigDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasLengthOfIpFragBufConfigDyn(partitionIndex)                                          (TRUE != FALSE)
#define SoAd_HasIpFragMgt(partitionIndex)                                                           (SoAd_GetIpFragMgtOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasIpFragBufConfigIdxOfIpFragMgt(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasLocalAddr(partitionIndex)                                                           (SoAd_GetLocalAddrOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasAddrIdOfLocalAddr(partitionIndex)                                                   (TRUE != FALSE)
#define SoAd_HasDomainOfLocalAddr(partitionIndex)                                                   (TRUE != FALSE)
#define SoAd_HasSoConGrpEndIdxOfLocalAddr(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasSoConGrpStartIdxOfLocalAddr(partitionIndex)                                         (TRUE != FALSE)
#define SoAd_HasSoConGrpUsedOfLocalAddr(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasTcpIpCtrlIdxOfLocalAddr(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasLocalAddrByTcpIpCtrlInd(partitionIndex)                                             (SoAd_GetLocalAddrByTcpIpCtrlIndOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasLocalAddrDyn(partitionIndex)                                                        (SoAd_GetLocalAddrDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasIpAddrStateOfLocalAddrDyn(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasLocalAddrIdMap()                                                                    (SoAd_GetLocalAddrIdMapOfPCPartitionConfig() != NULL_PTR)
#define SoAd_HasInvalidHndOfLocalAddrIdMap()                                                        (TRUE != FALSE)
#define SoAd_HasPartitionSpecificLocalAddrIdxOfLocalAddrIdMap()                                     (TRUE != FALSE)
#define SoAd_HasPartitionSpecificLocalAddrPartitionIdxOfLocalAddrIdMap()                            (TRUE != FALSE)
#define SoAd_HasPartitionSpecificLocalAddrUsedOfLocalAddrIdMap()                                    (TRUE != FALSE)
#define SoAd_HasLocalIpAddrAssignmentChgCbk()                                                       (SoAd_GetLocalIpAddrAssignmentChgCbkOfPCPartitionConfig() != NULL_PTR)
#define SoAd_HasLocalIpAddrAssignmentChgCbkInd(partitionIndex)                                      (SoAd_GetLocalIpAddrAssignmentChgCbkIndOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasMaxIfRouteGrpTransmitPduSize(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasMetaDataRxBuffer(partitionIndex)                                                    (SoAd_GetMetaDataRxBufferOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasNPduUdpTx(partitionIndex)                                                           (SoAd_GetNPduUdpTxOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasNPduUdpTxBufferEndIdxOfNPduUdpTx(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasNPduUdpTxBufferStartIdxOfNPduUdpTx(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasNPduUdpTxBufferUsedOfNPduUdpTx(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasNPduUdpTxQueueEndIdxOfNPduUdpTx(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasNPduUdpTxQueueStartIdxOfNPduUdpTx(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasNPduUdpTxQueueUsedOfNPduUdpTx(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasSoConIdxOfNPduUdpTx(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasNPduUdpTxBuffer(partitionIndex)                                                     (SoAd_GetNPduUdpTxBufferOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasNPduUdpTxDyn(partitionIndex)                                                        (SoAd_GetNPduUdpTxDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasBufLenOfNPduUdpTxDyn(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasLvlOfNPduUdpTxDyn(partitionIndex)                                                   (TRUE != FALSE)
#define SoAd_HasRetryCntOfNPduUdpTxDyn(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasTotalLenOfNPduUdpTxDyn(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasTransmissionStateOfNPduUdpTxDyn(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasNPduUdpTxQueue(partitionIndex)                                                      (SoAd_GetNPduUdpTxQueueOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasCopiedOfNPduUdpTxQueue(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasLenOfNPduUdpTxQueue(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasNPduUdpTxBufferIdxOfNPduUdpTxQueue(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasPduRouteDestIdxOfNPduUdpTxQueue(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasPartitionDyn(partitionIndex)                                                        (SoAd_GetPartitionDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasInitializedOfPartitionDyn(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasPartitionIdentifiers()                                                              (SoAd_GetPartitionIdentifiersOfPCConfig() != NULL_PTR)
#define SoAd_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                        (TRUE != FALSE)
#define SoAd_HasPartitionSNVOfPartitionIdentifiers()                                                (TRUE != FALSE)
#define SoAd_HasPduRoute(partitionIndex)                                                            (SoAd_GetPduRouteOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasAllPduRouteDestWithPduHdrOfPduRoute(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasIfOptimisticTransmitOfPduRoute(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasIfTriggerTransmitModeOfPduRoute(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasMetaDataTxEnabledOfPduRoute(partitionIndex)                                         (TRUE != FALSE)
#define SoAd_HasPduRouteDestEndIdxOfPduRoute(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasPduRouteDestStartIdxOfPduRoute(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasTxConfEnabledOfPduRoute(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasTxConfPduIdOfPduRoute(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasTxOptimizedOfPduRoute(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasUpperLayerApiOfPduRoute(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasUpperLayerIdxOfPduRoute(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasPduRouteDest(partitionIndex)                                                        (SoAd_GetPduRouteDestOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasPduRouteIdxOfPduRouteDest(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasRouteGrpSoConByPduRouteDestIndEndIdxOfPduRouteDest(partitionIndex)                  (TRUE != FALSE)
#define SoAd_HasRouteGrpSoConByPduRouteDestIndStartIdxOfPduRouteDest(partitionIndex)                (TRUE != FALSE)
#define SoAd_HasRouteGrpSoConByPduRouteDestIndUsedOfPduRouteDest(partitionIndex)                    (TRUE != FALSE)
#define SoAd_HasSoConIdxOfPduRouteDest(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasTxPduHdrIdOfPduRouteDest(partitionIndex)                                            (TRUE != FALSE)
#define SoAd_HasTxUdpTriggerModeOfPduRouteDest(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasUdpTriggerTimeoutOfPduRouteDest(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasPduRouteDestBySoConInd(partitionIndex)                                              (SoAd_GetPduRouteDestBySoConIndOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasPduRouteDestInd(partitionIndex)                                                     (SoAd_GetPduRouteDestIndOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasPduRouteDyn(partitionIndex)                                                         (SoAd_GetPduRouteDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasPendingTxConfMainOfPduRouteDyn(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasPendingTxConfNumOfPduRouteDyn(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasRemAddrIpV4(partitionIndex)                                                         (SoAd_GetRemAddrIpV4OfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasAddrOfRemAddrIpV4(partitionIndex)                                                   (TRUE != FALSE)
#define SoAd_HasPortOfRemAddrIpV4(partitionIndex)                                                   (TRUE != FALSE)
#define SoAd_HasRemAddrIpV6(partitionIndex)                                                         (SoAd_GetRemAddrIpV6OfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasAddrOfRemAddrIpV6(partitionIndex)                                                   (TRUE != FALSE)
#define SoAd_HasPortOfRemAddrIpV6(partitionIndex)                                                   (TRUE != FALSE)
#define SoAd_HasRemAddrRcv(partitionIndex)                                                          (SoAd_GetRemAddrRcvOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasRouteGrp(partitionIndex)                                                            (SoAd_GetRouteGrpOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasEnabledAtInitOfRouteGrp(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasMultiInstanceOnGrpOfRouteGrp(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasPduRouteDestIndEndIdxOfRouteGrp(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasPduRouteDestIndStartIdxOfRouteGrp(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasPduRouteDestIndUsedOfRouteGrp(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasRouteGrpIdOfRouteGrp(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasRouteGrpSoConEndIdxOfRouteGrp(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasRouteGrpSoConStartIdxOfRouteGrp(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasRxRequestEnableOfRouteGrp(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasSocketRouteIndEndIdxOfRouteGrp(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasSocketRouteIndStartIdxOfRouteGrp(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasSocketRouteIndUsedOfRouteGrp(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasTxTriggerableOfRouteGrp(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasRouteGrpIdMap()                                                                     (SoAd_GetRouteGrpIdMapOfPCPartitionConfig() != NULL_PTR)
#define SoAd_HasInvalidHndOfRouteGrpIdMap()                                                         (TRUE != FALSE)
#define SoAd_HasPartitionSpecificRouteGrpIdxOfRouteGrpIdMap()                                       (TRUE != FALSE)
#define SoAd_HasPartitionSpecificRouteGrpPartitionIdxOfRouteGrpIdMap()                              (TRUE != FALSE)
#define SoAd_HasPartitionSpecificRouteGrpUsedOfRouteGrpIdMap()                                      (TRUE != FALSE)
#define SoAd_HasRouteGrpSoCon(partitionIndex)                                                       (SoAd_GetRouteGrpSoConOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasRouteGrpIdxOfRouteGrpSoCon(partitionIndex)                                          (TRUE != FALSE)
#define SoAd_HasSoConIdxOfRouteGrpSoCon(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasRouteGrpSoConByPduRouteDestInd(partitionIndex)                                      (SoAd_GetRouteGrpSoConByPduRouteDestIndOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasRouteGrpSoConBySocketRouteDestInd(partitionIndex)                                   (SoAd_GetRouteGrpSoConBySocketRouteDestIndOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasRouteGrpSoConDyn(partitionIndex)                                                    (SoAd_GetRouteGrpSoConDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasEnabledOfRouteGrpSoConDyn(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasFlagsOfRouteGrpSoConDyn(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasRxBufStructMgt(partitionIndex)                                                      (SoAd_GetRxBufStructMgtOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasRxBufStructSegIdxOfRxBufStructMgt(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasRxBufStructSegLvlOfRxBufStructMgt(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasRxBufStructSeg(partitionIndex)                                                      (SoAd_GetRxBufStructSegOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasDataPtrOfRxBufStructSeg(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasLenOfRxBufStructSeg(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasRxBufferConfig(partitionIndex)                                                      (SoAd_GetRxBufferConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasIfRxBufferEndIdxOfRxBufferConfig(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasIfRxBufferStartIdxOfRxBufferConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasIfRxBufferUsedOfRxBufferConfig(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasMetaDataRxBufferEndIdxOfRxBufferConfig(partitionIndex)                              (TRUE != FALSE)
#define SoAd_HasMetaDataRxBufferStartIdxOfRxBufferConfig(partitionIndex)                            (TRUE != FALSE)
#define SoAd_HasMetaDataRxBufferUsedOfRxBufferConfig(partitionIndex)                                (TRUE != FALSE)
#define SoAd_HasTpRxBufferEndIdxOfRxBufferConfig(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasTpRxBufferStartIdxOfRxBufferConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasTpRxBufferUsedOfRxBufferConfig(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasRxBufferConfigDyn(partitionIndex)                                                   (SoAd_GetRxBufferConfigDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasIfRxBufferIdxOfRxBufferConfigDyn(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasTpRxBufferIdxOfRxBufferConfigDyn(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasRxMgt(partitionIndex)                                                               (SoAd_GetRxMgtOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasCancelRequestedOfRxMgt(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasRxBytesPendingOfRxMgt(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasSocketRouteDestIdxOfRxMgt(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasRxPduIdIdMap()                                                                      (SoAd_GetRxPduIdIdMapOfPCPartitionConfig() != NULL_PTR)
#define SoAd_HasInvalidHndOfRxPduIdIdMap()                                                          (TRUE != FALSE)
#define SoAd_HasPartitionSpecificSocketRouteDestIdxOfRxPduIdIdMap()                                 (TRUE != FALSE)
#define SoAd_HasPartitionSpecificSocketRouteDestPartitionIdxOfRxPduIdIdMap()                        (TRUE != FALSE)
#define SoAd_HasShutdownFinishedCbk()                                                               (SoAd_GetShutdownFinishedCbkOfPCPartitionConfig() != NULL_PTR)
#define SoAd_HasSizeOfBestMatchSoConIdxList(partitionIndex)                                         (TRUE != FALSE)
#define SoAd_HasSizeOfDhcpEventCbk()                                                                (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueFlag(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueIdent(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueIfTxRouteGrp(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueIfTxRouteGrpConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueIfUdpPduRoute(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueIfUdpPduRouteConfig(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueMgmt(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueStateSoCon(partitionIndex)                                          (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueStateSoConConfig(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueTpRxSoCon(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueTpRxSoConConfig(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueTpTxSoCon(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueTpTxSoConConfig(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasSizeOfIfRxBuffer(partitionIndex)                                                    (TRUE != FALSE)
#define SoAd_HasSizeOfInstance(partitionIndex)                                                      (TRUE != FALSE)
#define SoAd_HasSizeOfInstanceDyn(partitionIndex)                                                   (TRUE != FALSE)
#define SoAd_HasSizeOfInstanceMap()                                                                 (TRUE != FALSE)
#define SoAd_HasSizeOfIpFragBuf(partitionIndex)                                                     (TRUE != FALSE)
#define SoAd_HasSizeOfIpFragBufConfig(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasSizeOfIpFragBufConfigDyn(partitionIndex)                                            (TRUE != FALSE)
#define SoAd_HasSizeOfIpFragMgt(partitionIndex)                                                     (TRUE != FALSE)
#define SoAd_HasSizeOfLocalAddr(partitionIndex)                                                     (TRUE != FALSE)
#define SoAd_HasSizeOfLocalAddrByTcpIpCtrlInd(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasSizeOfLocalAddrDyn(partitionIndex)                                                  (TRUE != FALSE)
#define SoAd_HasSizeOfLocalAddrIdMap()                                                              (TRUE != FALSE)
#define SoAd_HasSizeOfLocalIpAddrAssignmentChgCbk()                                                 (TRUE != FALSE)
#define SoAd_HasSizeOfLocalIpAddrAssignmentChgCbkInd(partitionIndex)                                (TRUE != FALSE)
#define SoAd_HasSizeOfMetaDataRxBuffer(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasSizeOfNPduUdpTx(partitionIndex)                                                     (TRUE != FALSE)
#define SoAd_HasSizeOfNPduUdpTxBuffer(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasSizeOfNPduUdpTxDyn(partitionIndex)                                                  (TRUE != FALSE)
#define SoAd_HasSizeOfNPduUdpTxQueue(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasSizeOfPartitionDyn(partitionIndex)                                                  (TRUE != FALSE)
#define SoAd_HasSizeOfPartitionIdentifiers()                                                        (TRUE != FALSE)
#define SoAd_HasSizeOfPduRoute(partitionIndex)                                                      (TRUE != FALSE)
#define SoAd_HasSizeOfPduRouteDest(partitionIndex)                                                  (TRUE != FALSE)
#define SoAd_HasSizeOfPduRouteDestBySoConInd(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasSizeOfPduRouteDestInd(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasSizeOfPduRouteDyn(partitionIndex)                                                   (TRUE != FALSE)
#define SoAd_HasSizeOfRemAddrIpV4(partitionIndex)                                                   (TRUE != FALSE)
#define SoAd_HasSizeOfRemAddrIpV6(partitionIndex)                                                   (TRUE != FALSE)
#define SoAd_HasSizeOfRemAddrRcv(partitionIndex)                                                    (TRUE != FALSE)
#define SoAd_HasSizeOfRouteGrp(partitionIndex)                                                      (TRUE != FALSE)
#define SoAd_HasSizeOfRouteGrpIdMap()                                                               (TRUE != FALSE)
#define SoAd_HasSizeOfRouteGrpSoCon(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasSizeOfRouteGrpSoConByPduRouteDestInd(partitionIndex)                                (TRUE != FALSE)
#define SoAd_HasSizeOfRouteGrpSoConBySocketRouteDestInd(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasSizeOfRouteGrpSoConDyn(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasSizeOfRxBufStructMgt(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasSizeOfRxBufStructSeg(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasSizeOfRxBufferConfig(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasSizeOfRxBufferConfigDyn(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasSizeOfRxMgt(partitionIndex)                                                         (TRUE != FALSE)
#define SoAd_HasSizeOfRxPduIdIdMap()                                                                (TRUE != FALSE)
#define SoAd_HasSizeOfShutdownFinishedCbk()                                                         (TRUE != FALSE)
#define SoAd_HasSizeOfSoCon(partitionIndex)                                                         (TRUE != FALSE)
#define SoAd_HasSizeOfSoConDyn(partitionIndex)                                                      (TRUE != FALSE)
#define SoAd_HasSizeOfSoConGrp(partitionIndex)                                                      (TRUE != FALSE)
#define SoAd_HasSizeOfSoConMap()                                                                    (TRUE != FALSE)
#define SoAd_HasSizeOfSoConModeChgCbk()                                                             (TRUE != FALSE)
#define SoAd_HasSizeOfSoConModeChgCbkInd(partitionIndex)                                            (TRUE != FALSE)
#define SoAd_HasSizeOfSocket(partitionIndex)                                                        (TRUE != FALSE)
#define SoAd_HasSizeOfSocketDyn(partitionIndex)                                                     (TRUE != FALSE)
#define SoAd_HasSizeOfSocketRoute(partitionIndex)                                                   (TRUE != FALSE)
#define SoAd_HasSizeOfSocketRouteDest(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasSizeOfSocketRouteInd(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasSizeOfSocketTcp(partitionIndex)                                                     (TRUE != FALSE)
#define SoAd_HasSizeOfSocketUdp(partitionIndex)                                                     (TRUE != FALSE)
#define SoAd_HasSizeOfTcpIpCtrl(partitionIndex)                                                     (TRUE != FALSE)
#define SoAd_HasSizeOfTcpKeepAliveGloballyEnabled()                                                 (TRUE != FALSE)
#define SoAd_HasSizeOfTcpTxQueue(partitionIndex)                                                    (TRUE != FALSE)
#define SoAd_HasSizeOfTcpTxQueueData(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasSizeOfTcpTxQueueMgt(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListIdent(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListMgmt(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListNPduUdpTx(partitionIndex)                                          (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListNPduUdpTxConfig(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListNPduUdpTxMap(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListTcpAutoConnectConfig(partitionIndex)                               (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListUdpAlive(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListUdpAliveConfig(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListUdpAliveMap(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasSizeOfTpRxBuffer(partitionIndex)                                                    (TRUE != FALSE)
#define SoAd_HasSizeOfTpTxBuffer(partitionIndex)                                                    (TRUE != FALSE)
#define SoAd_HasSizeOfTpTxBufferConfig(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasSizeOfTpTxBufferConfigDyn(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasSizeOfTriggerBuf(partitionIndex)                                                    (TRUE != FALSE)
#define SoAd_HasSizeOfTriggerBufConfig(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasSizeOfTriggerBufConfigDyn(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasSizeOfTxMgt(partitionIndex)                                                         (TRUE != FALSE)
#define SoAd_HasSizeOfTxPduIdMap()                                                                  (TRUE != FALSE)
#define SoAd_HasSizeOfUpperLayer()                                                                  (TRUE != FALSE)
#define SoAd_HasSoCon(partitionIndex)                                                               (SoAd_GetSoConOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasIpFragMgtIdxOfSoCon(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasIpFragMgtUsedOfSoCon(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasLocalIpAddrAssignmentChgCbkIndEndIdxOfSoCon(partitionIndex)                         (TRUE != FALSE)
#define SoAd_HasLocalIpAddrAssignmentChgCbkIndStartIdxOfSoCon(partitionIndex)                       (TRUE != FALSE)
#define SoAd_HasLocalIpAddrAssignmentChgCbkIndUsedOfSoCon(partitionIndex)                           (TRUE != FALSE)
#define SoAd_HasNPduUdpTxIdxOfSoCon(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasNPduUdpTxUsedOfSoCon(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasPduRouteDestBySoConIndEndIdxOfSoCon(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasPduRouteDestBySoConIndStartIdxOfSoCon(partitionIndex)                               (TRUE != FALSE)
#define SoAd_HasPduRouteDestBySoConIndUsedOfSoCon(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasRemAddrCfgStateOfSoCon(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasRemAddrIpV4IdxOfSoCon(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasRemAddrIpV4UsedOfSoCon(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasRemAddrIpV6IdxOfSoCon(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasRemAddrIpV6UsedOfSoCon(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasRemAddrRcvIdxOfSoCon(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasRemAddrRcvUsedOfSoCon(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasRxBufStructMgtIdxOfSoCon(partitionIndex)                                            (TRUE != FALSE)
#define SoAd_HasRxBufStructMgtUsedOfSoCon(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasRxBufStructSegEndIdxOfSoCon(partitionIndex)                                         (TRUE != FALSE)
#define SoAd_HasRxBufStructSegStartIdxOfSoCon(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasRxBufStructSegUsedOfSoCon(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasRxBufferConfigIdxOfSoCon(partitionIndex)                                            (TRUE != FALSE)
#define SoAd_HasRxBufferConfigUsedOfSoCon(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasRxMgtIdxOfSoCon(partitionIndex)                                                     (TRUE != FALSE)
#define SoAd_HasRxMgtUsedOfSoCon(partitionIndex)                                                    (TRUE != FALSE)
#define SoAd_HasSoConGrpIdxOfSoCon(partitionIndex)                                                  (TRUE != FALSE)
#define SoAd_HasSoConIdOfSoCon(partitionIndex)                                                      (TRUE != FALSE)
#define SoAd_HasSoConModeChgCbkIndEndIdxOfSoCon(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasSoConModeChgCbkIndStartIdxOfSoCon(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasSoConModeChgCbkIndUsedOfSoCon(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasSocketIdxOfSoCon(partitionIndex)                                                    (TRUE != FALSE)
#define SoAd_HasSocketRouteEndIdxOfSoCon(partitionIndex)                                            (TRUE != FALSE)
#define SoAd_HasSocketRouteStartIdxOfSoCon(partitionIndex)                                          (TRUE != FALSE)
#define SoAd_HasSocketRouteUsedOfSoCon(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasTcpTxQueueIdxOfSoCon(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasTcpTxQueueUsedOfSoCon(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasTpTxBufferConfigIdxOfSoCon(partitionIndex)                                          (TRUE != FALSE)
#define SoAd_HasTpTxBufferConfigUsedOfSoCon(partitionIndex)                                         (TRUE != FALSE)
#define SoAd_HasTxMgtIdxOfSoCon(partitionIndex)                                                     (TRUE != FALSE)
#define SoAd_HasTxMgtUsedOfSoCon(partitionIndex)                                                    (TRUE != FALSE)
#define SoAd_HasSoConDyn(partitionIndex)                                                            (SoAd_GetSoConDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasAbortOfSoConDyn(partitionIndex)                                                     (TRUE != FALSE)
#define SoAd_HasCloseModeOfSoConDyn(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasModeOfSoConDyn(partitionIndex)                                                      (TRUE != FALSE)
#define SoAd_HasOpenCloseCounterOfSoConDyn(partitionIndex)                                          (TRUE != FALSE)
#define SoAd_HasRemAddrDynOfSoConDyn(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasRemAddrReleaseOfSoConDyn(partitionIndex)                                            (TRUE != FALSE)
#define SoAd_HasRemAddrStateDynOfSoConDyn(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasRxActiveOfSoConDyn(partitionIndex)                                                  (TRUE != FALSE)
#define SoAd_HasTimeoutOccurredOfSoConDyn(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasTxActiveOfSoConDyn(partitionIndex)                                                  (TRUE != FALSE)
#define SoAd_HasSoConGrp(partitionIndex)                                                            (SoAd_GetSoConGrpOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasBestMatchWithPduHeaderEnabledOfSoConGrp(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasBestMatchWithSockRouteEnabledOfSoConGrp(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasFramePriorityOfSoConGrp(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasInstanceIdxOfSoConGrp(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasLocalAddrIdxOfSoConGrp(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasLocalAddrUsedOfSoConGrp(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasLocalPortOfSoConGrp(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasMeasurementDataSomeIpSdTypeOfSoConGrp(partitionIndex)                               (TRUE != FALSE)
#define SoAd_HasMsgAcceptFilterEnabledOfSoConGrp(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasPduHdrEnabledOfSoConGrp(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasSoConEndIdxOfSoConGrp(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasSoConStartIdxOfSoConGrp(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasSockAutoSoConSetupKeepOnlineOfSoConGrp(partitionIndex)                              (TRUE != FALSE)
#define SoAd_HasSockAutoSoConSetupOfSoConGrp(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasSocketIdxOfSoConGrp(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasSocketTcpIdxOfSoConGrp(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasSocketTcpUsedOfSoConGrp(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasSocketUdpIdxOfSoConGrp(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasSocketUdpUsedOfSoConGrp(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasSocketUsedOfSoConGrp(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasSoConMap()                                                                          (SoAd_GetSoConMapOfPCPartitionConfig() != NULL_PTR)
#define SoAd_HasInvalidHndOfSoConMap()                                                              (TRUE != FALSE)
#define SoAd_HasPartitionSpecificSoConIdxOfSoConMap()                                               (TRUE != FALSE)
#define SoAd_HasPartitionSpecificSoConPartitionIdxOfSoConMap()                                      (TRUE != FALSE)
#define SoAd_HasSoConModeChgCbk()                                                                   (SoAd_GetSoConModeChgCbkOfPCPartitionConfig() != NULL_PTR)
#define SoAd_HasSoConModeChgCbkInd(partitionIndex)                                                  (SoAd_GetSoConModeChgCbkIndOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasSocket(partitionIndex)                                                              (SoAd_GetSocketOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasSoConEndIdxOfSocket(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasSoConStartIdxOfSocket(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasSocketDyn(partitionIndex)                                                           (SoAd_GetSocketDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasLocalPortOfSocketDyn(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasSkipBytesOfSocketDyn(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasSoConTxActiveIdxOfSocketDyn(partitionIndex)                                         (TRUE != FALSE)
#define SoAd_HasSocketIdOfSocketDyn(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasStateOfSocketDyn(partitionIndex)                                                    (TRUE != FALSE)
#define SoAd_HasSocketRoute(partitionIndex)                                                         (SoAd_GetSocketRouteOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasMetaDataRxEnabledOfSocketRoute(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasRxPduHdrMethodIdOfSocketRoute(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasRxPduHdrServiceIdOfSocketRoute(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasSoConIdxOfSocketRoute(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasSocketRouteDestEndIdxOfSocketRoute(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasSocketRouteDestStartIdxOfSocketRoute(partitionIndex)                                (TRUE != FALSE)
#define SoAd_HasUpperLayerApiOfSocketRoute(partitionIndex)                                          (TRUE != FALSE)
#define SoAd_HasSocketRouteDest(partitionIndex)                                                     (SoAd_GetSocketRouteDestOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasRouteGrpSoConBySocketRouteDestIndEndIdxOfSocketRouteDest(partitionIndex)            (TRUE != FALSE)
#define SoAd_HasRouteGrpSoConBySocketRouteDestIndStartIdxOfSocketRouteDest(partitionIndex)          (TRUE != FALSE)
#define SoAd_HasRouteGrpSoConBySocketRouteDestIndUsedOfSocketRouteDest(partitionIndex)              (TRUE != FALSE)
#define SoAd_HasRxPduIdOfSocketRouteDest(partitionIndex)                                            (TRUE != FALSE)
#define SoAd_HasSocketRouteIdxOfSocketRouteDest(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasUpperLayerIdxOfSocketRouteDest(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasSocketRouteInd(partitionIndex)                                                      (SoAd_GetSocketRouteIndOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasSocketTcp(partitionIndex)                                                           (SoAd_GetSocketTcpOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasImmedTpTxConfOfSocketTcp(partitionIndex)                                            (TRUE != FALSE)
#define SoAd_HasTcpInitiateOfSocketTcp(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasTcpKeepAliveIntervalOfSocketTcp(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasTcpKeepAliveOfSocketTcp(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasTcpKeepAliveProbesMaxOfSocketTcp(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasTcpKeepAliveTimeOfSocketTcp(partitionIndex)                                         (TRUE != FALSE)
#define SoAd_HasTcpMslOfSocketTcp(partitionIndex)                                                   (TRUE != FALSE)
#define SoAd_HasTcpNoDelayOfSocketTcp(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasTcpRxBufMinOfSocketTcp(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasTcpTlsConIdOfSocketTcp(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasTcpTxBufMinOfSocketTcp(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasSocketUdp(partitionIndex)                                                           (SoAd_GetSocketUdpOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasAliveTimeoutMaxCntOfSocketUdp(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasChecksumChangeEnabledOfSocketUdp(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasChecksumEnabledOfSocketUdp(partitionIndex)                                          (TRUE != FALSE)
#define SoAd_HasImmedIfTxConfListSizeOfSocketUdp(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasImmedIfTxConfOfSocketUdp(partitionIndex)                                            (TRUE != FALSE)
#define SoAd_HasNPduUdpTxBufferMinOfSocketUdp(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasNPduUdpTxQueueSizeOfSocketUdp(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasRetryQueueLimitOfSocketUdp(partitionIndex)                                          (TRUE != FALSE)
#define SoAd_HasUdpListenOnlyOfSocketUdp(partitionIndex)                                            (TRUE != FALSE)
#define SoAd_HasUdpStrictHdrLenCheckEnabledOfSocketUdp(partitionIndex)                              (TRUE != FALSE)
#define SoAd_HasUdpTriggerTimeoutOfSocketUdp(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasTcpIpCtrl(partitionIndex)                                                           (SoAd_GetTcpIpCtrlOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasLocalAddrByTcpIpCtrlIndEndIdxOfTcpIpCtrl(partitionIndex)                            (TRUE != FALSE)
#define SoAd_HasLocalAddrByTcpIpCtrlIndStartIdxOfTcpIpCtrl(partitionIndex)                          (TRUE != FALSE)
#define SoAd_HasLocalAddrByTcpIpCtrlIndUsedOfTcpIpCtrl(partitionIndex)                              (TRUE != FALSE)
#define SoAd_HasRetryEnabledOfTcpIpCtrl(partitionIndex)                                             (TRUE != FALSE)
#define SoAd_HasTcpKeepAliveGloballyEnabled()                                                       (SoAd_GetTcpKeepAliveGloballyEnabledOfPCPartitionConfig() != NULL_PTR)
#define SoAd_HasTcpTxQueue(partitionIndex)                                                          (SoAd_GetTcpTxQueueOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasTcpTxQueueDataEndIdxOfTcpTxQueue(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasTcpTxQueueDataStartIdxOfTcpTxQueue(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasTcpTxQueueData(partitionIndex)                                                      (SoAd_GetTcpTxQueueDataOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasLenOfTcpTxQueueData(partitionIndex)                                                 (TRUE != FALSE)
#define SoAd_HasPduRouteIdxOfTcpTxQueueData(partitionIndex)                                         (TRUE != FALSE)
#define SoAd_HasTcpTxQueueMgt(partitionIndex)                                                       (SoAd_GetTcpTxQueueMgtOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasLvlOfTcpTxQueueMgt(partitionIndex)                                                  (TRUE != FALSE)
#define SoAd_HasTcpTxQueueDataIdxOfTcpTxQueueMgt(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasTotLenOfTcpTxQueueMgt(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasTimeoutListIdent(partitionIndex)                                                    (SoAd_GetTimeoutListIdentOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasTimeoutListNPduUdpTxConfigIdxOfTimeoutListIdent(partitionIndex)                     (TRUE != FALSE)
#define SoAd_HasTimeoutListNPduUdpTxConfigUsedOfTimeoutListIdent(partitionIndex)                    (TRUE != FALSE)
#define SoAd_HasTimeoutListTcpAutoConnectConfigIdxOfTimeoutListIdent(partitionIndex)                (TRUE != FALSE)
#define SoAd_HasTimeoutListTcpAutoConnectConfigUsedOfTimeoutListIdent(partitionIndex)               (TRUE != FALSE)
#define SoAd_HasTimeoutListUdpAliveConfigIdxOfTimeoutListIdent(partitionIndex)                      (TRUE != FALSE)
#define SoAd_HasTimeoutListUdpAliveConfigUsedOfTimeoutListIdent(partitionIndex)                     (TRUE != FALSE)
#define SoAd_HasTimeoutListMgmt(partitionIndex)                                                     (SoAd_GetTimeoutListMgmtOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasLvlOfTimeoutListMgmt(partitionIndex)                                                (TRUE != FALSE)
#define SoAd_HasTimeoutListNPduUdpTx(partitionIndex)                                                (SoAd_GetTimeoutListNPduUdpTxOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasNPduUdpTxIdxOfTimeoutListNPduUdpTx(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasTimeoutOfTimeoutListNPduUdpTx(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasTimeoutListNPduUdpTxConfig(partitionIndex)                                          (SoAd_GetTimeoutListNPduUdpTxConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasTimeoutListMgmtIdxOfTimeoutListNPduUdpTxConfig(partitionIndex)                      (TRUE != FALSE)
#define SoAd_HasTimeoutListNPduUdpTxEndIdxOfTimeoutListNPduUdpTxConfig(partitionIndex)              (TRUE != FALSE)
#define SoAd_HasTimeoutListNPduUdpTxStartIdxOfTimeoutListNPduUdpTxConfig(partitionIndex)            (TRUE != FALSE)
#define SoAd_HasTimeoutListNPduUdpTxMap(partitionIndex)                                             (SoAd_GetTimeoutListNPduUdpTxMapOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasTimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap(partitionIndex)                    (TRUE != FALSE)
#define SoAd_HasTimeoutListTcpAutoConnectConfig(partitionIndex)                                     (SoAd_GetTimeoutListTcpAutoConnectConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasTimeoutListMgmtIdxOfTimeoutListTcpAutoConnectConfig(partitionIndex)                 (TRUE != FALSE)
#define SoAd_HasTimeoutListUdpAlive(partitionIndex)                                                 (SoAd_GetTimeoutListUdpAliveOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasSoConIdxOfTimeoutListUdpAlive(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasTimeoutOfTimeoutListUdpAlive(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasTimeoutListUdpAliveConfig(partitionIndex)                                           (SoAd_GetTimeoutListUdpAliveConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasTimeoutListMgmtIdxOfTimeoutListUdpAliveConfig(partitionIndex)                       (TRUE != FALSE)
#define SoAd_HasTimeoutListUdpAliveEndIdxOfTimeoutListUdpAliveConfig(partitionIndex)                (TRUE != FALSE)
#define SoAd_HasTimeoutListUdpAliveStartIdxOfTimeoutListUdpAliveConfig(partitionIndex)              (TRUE != FALSE)
#define SoAd_HasTimeoutListUdpAliveMap(partitionIndex)                                              (SoAd_GetTimeoutListUdpAliveMapOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasTimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap(partitionIndex)                      (TRUE != FALSE)
#define SoAd_HasTpRxBuffer(partitionIndex)                                                          (SoAd_GetTpRxBufferOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasTpTxBuffer(partitionIndex)                                                          (SoAd_GetTpTxBufferOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasTpTxBufferConfig(partitionIndex)                                                    (SoAd_GetTpTxBufferConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasTpTxBufferEndIdxOfTpTxBufferConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasTpTxBufferStartIdxOfTpTxBufferConfig(partitionIndex)                                (TRUE != FALSE)
#define SoAd_HasTpTxBufferUsedOfTpTxBufferConfig(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasTpTxBufferConfigDyn(partitionIndex)                                                 (SoAd_GetTpTxBufferConfigDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasTpTxBufferIdxOfTpTxBufferConfigDyn(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasTriggerBuf(partitionIndex)                                                          (SoAd_GetTriggerBufOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasTriggerBufConfig(partitionIndex)                                                    (SoAd_GetTriggerBufConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasTriggerBufEndIdxOfTriggerBufConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasTriggerBufStartIdxOfTriggerBufConfig(partitionIndex)                                (TRUE != FALSE)
#define SoAd_HasTriggerBufConfigDyn(partitionIndex)                                                 (SoAd_GetTriggerBufConfigDynOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasLengthOfTriggerBufConfigDyn(partitionIndex)                                         (TRUE != FALSE)
#define SoAd_HasPduRouteIdxOfTriggerBufConfigDyn(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasTxMgt(partitionIndex)                                                               (SoAd_GetTxMgtOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define SoAd_HasCancelRequestedOfTxMgt(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasPduRouteDestIdxOfTxMgt(partitionIndex)                                              (TRUE != FALSE)
#define SoAd_HasTxBufPtrOfTxMgt(partitionIndex)                                                     (TRUE != FALSE)
#define SoAd_HasTxBytesLenOfTxMgt(partitionIndex)                                                   (TRUE != FALSE)
#define SoAd_HasTxBytesPendingOfTxMgt(partitionIndex)                                               (TRUE != FALSE)
#define SoAd_HasTxPduIdMap()                                                                        (SoAd_GetTxPduIdMapOfPCPartitionConfig() != NULL_PTR)
#define SoAd_HasInvalidHndOfTxPduIdMap()                                                            (TRUE != FALSE)
#define SoAd_HasPartitionSpecificPduRouteIdxOfTxPduIdMap()                                          (TRUE != FALSE)
#define SoAd_HasPartitionSpecificPduRoutePartitionIdxOfTxPduIdMap()                                 (TRUE != FALSE)
#define SoAd_HasUpperLayer()                                                                        (SoAd_GetUpperLayerOfPCPartitionConfig() != NULL_PTR)
#define SoAd_HasIfRxIndicationCbkOfUpperLayer()                                                     (TRUE != FALSE)
#define SoAd_HasIfTriggerTransmitCbkOfUpperLayer()                                                  (TRUE != FALSE)
#define SoAd_HasIfTxConfirmationCbkOfUpperLayer()                                                   (TRUE != FALSE)
#define SoAd_HasTpCopyRxDataCbkOfUpperLayer()                                                       (TRUE != FALSE)
#define SoAd_HasTpCopyRxDataConstCbkOfUpperLayer()                                                  (TRUE != FALSE)
#define SoAd_HasTpCopyTxDataCbkOfUpperLayer()                                                       (TRUE != FALSE)
#define SoAd_HasTpCopyTxDataConstCbkOfUpperLayer()                                                  (TRUE != FALSE)
#define SoAd_HasTpRxIndicationCbkOfUpperLayer()                                                     (TRUE != FALSE)
#define SoAd_HasTpStartOfReceptionCbkOfUpperLayer()                                                 (TRUE != FALSE)
#define SoAd_HasTpStartOfReceptionConstCbkOfUpperLayer()                                            (TRUE != FALSE)
#define SoAd_HasTpTxConfirmationCbkOfUpperLayer()                                                   (TRUE != FALSE)
#define SoAd_HasPCConfig()                                                                          (TRUE != FALSE)
#define SoAd_HasPCPartitionConfigOfPCConfig()                                                       (TRUE != FALSE)
#define SoAd_HasPartitionIdentifiersOfPCConfig()                                                    (TRUE != FALSE)
#define SoAd_HasSizeOfPartitionIdentifiersOfPCConfig()                                              (TRUE != FALSE)
#define SoAd_HasPCPartitionConfig()                                                                 (SoAd_GetPCPartitionConfigOfPCConfig() != NULL_PTR)
#define SoAd_HasBestMatchSoConIdxListOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define SoAd_HasDhcpEventCbkOfPCPartitionConfig()                                                   (TRUE != FALSE)
#define SoAd_HasEventQueueFlagOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasEventQueueIdentOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasEventQueueIfTxRouteGrpConfigOfPCPartitionConfig(partitionIndex)                     (TRUE != FALSE)
#define SoAd_HasEventQueueIfTxRouteGrpOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define SoAd_HasEventQueueIfUdpPduRouteConfigOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define SoAd_HasEventQueueIfUdpPduRouteOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define SoAd_HasEventQueueMgmtOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasEventQueueStateSoConConfigOfPCPartitionConfig(partitionIndex)                       (TRUE != FALSE)
#define SoAd_HasEventQueueStateSoConOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasEventQueueTpRxSoConConfigOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define SoAd_HasEventQueueTpRxSoConOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define SoAd_HasEventQueueTpTxSoConConfigOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define SoAd_HasEventQueueTpTxSoConOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define SoAd_HasIfRxBufferOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasInstanceDynOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasInstanceMapOfPCPartitionConfig()                                                    (TRUE != FALSE)
#define SoAd_HasInstanceOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define SoAd_HasIpFragBufConfigDynOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define SoAd_HasIpFragBufConfigOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasIpFragBufOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasIpFragMgtOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasLocalAddrByTcpIpCtrlIndOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define SoAd_HasLocalAddrDynOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasLocalAddrIdMapOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define SoAd_HasLocalAddrOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasLocalIpAddrAssignmentChgCbkIndOfPCPartitionConfig(partitionIndex)                   (TRUE != FALSE)
#define SoAd_HasLocalIpAddrAssignmentChgCbkOfPCPartitionConfig()                                    (TRUE != FALSE)
#define SoAd_HasMaxIfRouteGrpTransmitPduSizeOfPCPartitionConfig(partitionIndex)                     (TRUE != FALSE)
#define SoAd_HasMetaDataRxBufferOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasNPduUdpTxBufferOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasNPduUdpTxDynOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasNPduUdpTxOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasNPduUdpTxQueueOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasPartitionDynOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasPduRouteDestBySoConIndOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define SoAd_HasPduRouteDestIndOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasPduRouteDestOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasPduRouteDynOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasPduRouteOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define SoAd_HasRemAddrIpV4OfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasRemAddrIpV6OfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasRemAddrRcvOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasRouteGrpIdMapOfPCPartitionConfig()                                                  (TRUE != FALSE)
#define SoAd_HasRouteGrpOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define SoAd_HasRouteGrpSoConByPduRouteDestIndOfPCPartitionConfig(partitionIndex)                   (TRUE != FALSE)
#define SoAd_HasRouteGrpSoConBySocketRouteDestIndOfPCPartitionConfig(partitionIndex)                (TRUE != FALSE)
#define SoAd_HasRouteGrpSoConDynOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasRouteGrpSoConOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasRxBufStructMgtOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasRxBufStructSegOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasRxBufferConfigDynOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define SoAd_HasRxBufferConfigOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasRxMgtOfPCPartitionConfig(partitionIndex)                                            (TRUE != FALSE)
#define SoAd_HasRxPduIdIdMapOfPCPartitionConfig()                                                   (TRUE != FALSE)
#define SoAd_HasShutdownFinishedCbkOfPCPartitionConfig()                                            (TRUE != FALSE)
#define SoAd_HasSizeOfBestMatchSoConIdxListOfPCPartitionConfig(partitionIndex)                      (TRUE != FALSE)
#define SoAd_HasSizeOfDhcpEventCbkOfPCPartitionConfig()                                             (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueFlagOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueIdentOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueIfTxRouteGrpConfigOfPCPartitionConfig(partitionIndex)               (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueIfTxRouteGrpOfPCPartitionConfig(partitionIndex)                     (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueIfUdpPduRouteConfigOfPCPartitionConfig(partitionIndex)              (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueIfUdpPduRouteOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueMgmtOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueStateSoConConfigOfPCPartitionConfig(partitionIndex)                 (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueStateSoConOfPCPartitionConfig(partitionIndex)                       (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueTpRxSoConConfigOfPCPartitionConfig(partitionIndex)                  (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueTpRxSoConOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueTpTxSoConConfigOfPCPartitionConfig(partitionIndex)                  (TRUE != FALSE)
#define SoAd_HasSizeOfEventQueueTpTxSoConOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define SoAd_HasSizeOfIfRxBufferOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasSizeOfInstanceDynOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define SoAd_HasSizeOfInstanceMapOfPCPartitionConfig()                                              (TRUE != FALSE)
#define SoAd_HasSizeOfInstanceOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasSizeOfIpFragBufConfigDynOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define SoAd_HasSizeOfIpFragBufConfigOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define SoAd_HasSizeOfIpFragBufOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasSizeOfIpFragMgtOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasSizeOfLocalAddrByTcpIpCtrlIndOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define SoAd_HasSizeOfLocalAddrDynOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define SoAd_HasSizeOfLocalAddrIdMapOfPCPartitionConfig()                                           (TRUE != FALSE)
#define SoAd_HasSizeOfLocalAddrOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasSizeOfLocalIpAddrAssignmentChgCbkIndOfPCPartitionConfig(partitionIndex)             (TRUE != FALSE)
#define SoAd_HasSizeOfLocalIpAddrAssignmentChgCbkOfPCPartitionConfig()                              (TRUE != FALSE)
#define SoAd_HasSizeOfMetaDataRxBufferOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define SoAd_HasSizeOfNPduUdpTxBufferOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define SoAd_HasSizeOfNPduUdpTxDynOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define SoAd_HasSizeOfNPduUdpTxOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasSizeOfNPduUdpTxQueueOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasSizeOfPartitionDynOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define SoAd_HasSizeOfPduRouteDestBySoConIndOfPCPartitionConfig(partitionIndex)                     (TRUE != FALSE)
#define SoAd_HasSizeOfPduRouteDestIndOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define SoAd_HasSizeOfPduRouteDestOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define SoAd_HasSizeOfPduRouteDynOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define SoAd_HasSizeOfPduRouteOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasSizeOfRemAddrIpV4OfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define SoAd_HasSizeOfRemAddrIpV6OfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define SoAd_HasSizeOfRemAddrRcvOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasSizeOfRouteGrpIdMapOfPCPartitionConfig()                                            (TRUE != FALSE)
#define SoAd_HasSizeOfRouteGrpOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasSizeOfRouteGrpSoConByPduRouteDestIndOfPCPartitionConfig(partitionIndex)             (TRUE != FALSE)
#define SoAd_HasSizeOfRouteGrpSoConBySocketRouteDestIndOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define SoAd_HasSizeOfRouteGrpSoConDynOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define SoAd_HasSizeOfRouteGrpSoConOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define SoAd_HasSizeOfRxBufStructMgtOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasSizeOfRxBufStructSegOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasSizeOfRxBufferConfigDynOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define SoAd_HasSizeOfRxBufferConfigOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasSizeOfRxMgtOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasSizeOfRxPduIdIdMapOfPCPartitionConfig()                                             (TRUE != FALSE)
#define SoAd_HasSizeOfShutdownFinishedCbkOfPCPartitionConfig()                                      (TRUE != FALSE)
#define SoAd_HasSizeOfSoConDynOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasSizeOfSoConGrpOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasSizeOfSoConMapOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define SoAd_HasSizeOfSoConModeChgCbkIndOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define SoAd_HasSizeOfSoConModeChgCbkOfPCPartitionConfig()                                          (TRUE != FALSE)
#define SoAd_HasSizeOfSoConOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasSizeOfSocketDynOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasSizeOfSocketOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define SoAd_HasSizeOfSocketRouteDestOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define SoAd_HasSizeOfSocketRouteIndOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasSizeOfSocketRouteOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define SoAd_HasSizeOfSocketTcpOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasSizeOfSocketUdpOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasSizeOfTcpIpCtrlOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasSizeOfTcpKeepAliveGloballyEnabledOfPCPartitionConfig()                              (TRUE != FALSE)
#define SoAd_HasSizeOfTcpTxQueueDataOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasSizeOfTcpTxQueueMgtOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define SoAd_HasSizeOfTcpTxQueueOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListIdentOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListMgmtOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListNPduUdpTxConfigOfPCPartitionConfig(partitionIndex)                 (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListNPduUdpTxMapOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListNPduUdpTxOfPCPartitionConfig(partitionIndex)                       (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListTcpAutoConnectConfigOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListUdpAliveConfigOfPCPartitionConfig(partitionIndex)                  (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListUdpAliveMapOfPCPartitionConfig(partitionIndex)                     (TRUE != FALSE)
#define SoAd_HasSizeOfTimeoutListUdpAliveOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define SoAd_HasSizeOfTpRxBufferOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasSizeOfTpTxBufferConfigDynOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define SoAd_HasSizeOfTpTxBufferConfigOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define SoAd_HasSizeOfTpTxBufferOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasSizeOfTriggerBufConfigDynOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define SoAd_HasSizeOfTriggerBufConfigOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define SoAd_HasSizeOfTriggerBufOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasSizeOfTxMgtOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasSizeOfTxPduIdMapOfPCPartitionConfig()                                               (TRUE != FALSE)
#define SoAd_HasSizeOfUpperLayerOfPCPartitionConfig()                                               (TRUE != FALSE)
#define SoAd_HasSoConDynOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define SoAd_HasSoConGrpOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define SoAd_HasSoConMapOfPCPartitionConfig()                                                       (TRUE != FALSE)
#define SoAd_HasSoConModeChgCbkIndOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define SoAd_HasSoConModeChgCbkOfPCPartitionConfig()                                                (TRUE != FALSE)
#define SoAd_HasSoConOfPCPartitionConfig(partitionIndex)                                            (TRUE != FALSE)
#define SoAd_HasSocketDynOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasSocketOfPCPartitionConfig(partitionIndex)                                           (TRUE != FALSE)
#define SoAd_HasSocketRouteDestOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasSocketRouteIndOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasSocketRouteOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define SoAd_HasSocketTcpOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasSocketUdpOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasTcpIpCtrlOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define SoAd_HasTcpKeepAliveGloballyEnabledOfPCPartitionConfig()                                    (TRUE != FALSE)
#define SoAd_HasTcpTxQueueDataOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define SoAd_HasTcpTxQueueMgtOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define SoAd_HasTcpTxQueueOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasTimeoutListIdentOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasTimeoutListMgmtOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define SoAd_HasTimeoutListNPduUdpTxConfigOfPCPartitionConfig(partitionIndex)                       (TRUE != FALSE)
#define SoAd_HasTimeoutListNPduUdpTxMapOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define SoAd_HasTimeoutListNPduUdpTxOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define SoAd_HasTimeoutListTcpAutoConnectConfigOfPCPartitionConfig(partitionIndex)                  (TRUE != FALSE)
#define SoAd_HasTimeoutListUdpAliveConfigOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define SoAd_HasTimeoutListUdpAliveMapOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define SoAd_HasTimeoutListUdpAliveOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define SoAd_HasTpRxBufferOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasTpTxBufferConfigDynOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define SoAd_HasTpTxBufferConfigOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasTpTxBufferOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasTriggerBufConfigDynOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define SoAd_HasTriggerBufConfigOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define SoAd_HasTriggerBufOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define SoAd_HasTxMgtOfPCPartitionConfig(partitionIndex)                                            (TRUE != FALSE)
#define SoAd_HasTxPduIdMapOfPCPartitionConfig()                                                     (TRUE != FALSE)
#define SoAd_HasUpperLayerOfPCPartitionConfig()                                                     (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCIncrementDataMacros  SoAd Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define SoAd_IncSoConIdxOfBestMatchSoConIdxList(Index, partitionIndex)                              SoAd_GetSoConIdxOfBestMatchSoConIdxList(((Index)), (partitionIndex))++
#define SoAd_IncEventQueueFlag(Index, partitionIndex)                                               SoAd_GetEventQueueFlag(((Index)), (partitionIndex))++
#define SoAd_IncRouteGrpIdxOfEventQueueIfTxRouteGrp(Index, partitionIndex)                          SoAd_GetRouteGrpIdxOfEventQueueIfTxRouteGrp(((Index)), (partitionIndex))++
#define SoAd_IncPduRouteIdxOfEventQueueIfUdpPduRoute(Index, partitionIndex)                         SoAd_GetPduRouteIdxOfEventQueueIfUdpPduRoute(((Index)), (partitionIndex))++
#define SoAd_IncIdxOfEventQueueMgmt(Index, partitionIndex)                                          SoAd_GetIdxOfEventQueueMgmt(((Index)), (partitionIndex))++
#define SoAd_IncLvlOfEventQueueMgmt(Index, partitionIndex)                                          SoAd_GetLvlOfEventQueueMgmt(((Index)), (partitionIndex))++
#define SoAd_IncSoConIdxOfEventQueueStateSoCon(Index, partitionIndex)                               SoAd_GetSoConIdxOfEventQueueStateSoCon(((Index)), (partitionIndex))++
#define SoAd_IncSoConIdxOfEventQueueTpRxSoCon(Index, partitionIndex)                                SoAd_GetSoConIdxOfEventQueueTpRxSoCon(((Index)), (partitionIndex))++
#define SoAd_IncSoConIdxOfEventQueueTpTxSoCon(Index, partitionIndex)                                SoAd_GetSoConIdxOfEventQueueTpTxSoCon(((Index)), (partitionIndex))++
#define SoAd_IncIfRxBuffer(Index, partitionIndex)                                                   SoAd_GetIfRxBuffer(((Index)), (partitionIndex))++
#define SoAd_IncBestMatchListSizeOfInstanceDyn(Index, partitionIndex)                               SoAd_GetBestMatchListSizeOfInstanceDyn(((Index)), (partitionIndex))++
#define SoAd_IncCounterOfInstanceDyn(Index, partitionIndex)                                         SoAd_GetCounterOfInstanceDyn(((Index)), (partitionIndex))++
#define SoAd_IncOpenSocksOfInstanceDyn(Index, partitionIndex)                                       SoAd_GetOpenSocksOfInstanceDyn(((Index)), (partitionIndex))++
#define SoAd_IncIpFragBuf(Index, partitionIndex)                                                    SoAd_GetIpFragBuf(((Index)), (partitionIndex))++
#define SoAd_IncLengthOfIpFragBufConfigDyn(Index, partitionIndex)                                   SoAd_GetLengthOfIpFragBufConfigDyn(((Index)), (partitionIndex))++
#define SoAd_IncIpFragBufConfigIdxOfIpFragMgt(Index, partitionIndex)                                SoAd_GetIpFragBufConfigIdxOfIpFragMgt(((Index)), (partitionIndex))++
#define SoAd_IncIpAddrStateOfLocalAddrDyn(Index, partitionIndex)                                    SoAd_GetIpAddrStateOfLocalAddrDyn(((Index)), (partitionIndex))++
#define SoAd_IncMetaDataRxBuffer(Index, partitionIndex)                                             SoAd_GetMetaDataRxBuffer(((Index)), (partitionIndex))++
#define SoAd_IncNPduUdpTxBuffer(Index, partitionIndex)                                              SoAd_GetNPduUdpTxBuffer(((Index)), (partitionIndex))++
#define SoAd_IncBufLenOfNPduUdpTxDyn(Index, partitionIndex)                                         SoAd_GetBufLenOfNPduUdpTxDyn(((Index)), (partitionIndex))++
#define SoAd_IncLvlOfNPduUdpTxDyn(Index, partitionIndex)                                            SoAd_GetLvlOfNPduUdpTxDyn(((Index)), (partitionIndex))++
#define SoAd_IncRetryCntOfNPduUdpTxDyn(Index, partitionIndex)                                       SoAd_GetRetryCntOfNPduUdpTxDyn(((Index)), (partitionIndex))++
#define SoAd_IncTotalLenOfNPduUdpTxDyn(Index, partitionIndex)                                       SoAd_GetTotalLenOfNPduUdpTxDyn(((Index)), (partitionIndex))++
#define SoAd_IncTransmissionStateOfNPduUdpTxDyn(Index, partitionIndex)                              SoAd_GetTransmissionStateOfNPduUdpTxDyn(((Index)), (partitionIndex))++
#define SoAd_IncLenOfNPduUdpTxQueue(Index, partitionIndex)                                          SoAd_GetLenOfNPduUdpTxQueue(((Index)), (partitionIndex))++
#define SoAd_IncNPduUdpTxBufferIdxOfNPduUdpTxQueue(Index, partitionIndex)                           SoAd_GetNPduUdpTxBufferIdxOfNPduUdpTxQueue(((Index)), (partitionIndex))++
#define SoAd_IncPduRouteDestIdxOfNPduUdpTxQueue(Index, partitionIndex)                              SoAd_GetPduRouteDestIdxOfNPduUdpTxQueue(((Index)), (partitionIndex))++
#define SoAd_IncInitializedOfPartitionDyn(Index, partitionIndex)                                    SoAd_GetInitializedOfPartitionDyn(((Index)), (partitionIndex))++
#define SoAd_IncPendingTxConfNumOfPduRouteDyn(Index, partitionIndex)                                SoAd_GetPendingTxConfNumOfPduRouteDyn(((Index)), (partitionIndex))++
#define SoAd_IncRemAddrRcv(Index, partitionIndex)                                                   SoAd_GetRemAddrRcv(((Index)), (partitionIndex))++
#define SoAd_IncFlagsOfRouteGrpSoConDyn(Index, partitionIndex)                                      SoAd_GetFlagsOfRouteGrpSoConDyn(((Index)), (partitionIndex))++
#define SoAd_IncRxBufStructSegIdxOfRxBufStructMgt(Index, partitionIndex)                            SoAd_GetRxBufStructSegIdxOfRxBufStructMgt(((Index)), (partitionIndex))++
#define SoAd_IncRxBufStructSegLvlOfRxBufStructMgt(Index, partitionIndex)                            SoAd_GetRxBufStructSegLvlOfRxBufStructMgt(((Index)), (partitionIndex))++
#define SoAd_IncDataPtrOfRxBufStructSeg(Index, partitionIndex)                                      SoAd_GetDataPtrOfRxBufStructSeg(((Index)), (partitionIndex))++
#define SoAd_IncLenOfRxBufStructSeg(Index, partitionIndex)                                          SoAd_GetLenOfRxBufStructSeg(((Index)), (partitionIndex))++
#define SoAd_IncIfRxBufferIdxOfRxBufferConfigDyn(Index, partitionIndex)                             SoAd_GetIfRxBufferIdxOfRxBufferConfigDyn(((Index)), (partitionIndex))++
#define SoAd_IncTpRxBufferIdxOfRxBufferConfigDyn(Index, partitionIndex)                             SoAd_GetTpRxBufferIdxOfRxBufferConfigDyn(((Index)), (partitionIndex))++
#define SoAd_IncRxBytesPendingOfRxMgt(Index, partitionIndex)                                        SoAd_GetRxBytesPendingOfRxMgt(((Index)), (partitionIndex))++
#define SoAd_IncSocketRouteDestIdxOfRxMgt(Index, partitionIndex)                                    SoAd_GetSocketRouteDestIdxOfRxMgt(((Index)), (partitionIndex))++
#define SoAd_IncCloseModeOfSoConDyn(Index, partitionIndex)                                          SoAd_GetCloseModeOfSoConDyn(((Index)), (partitionIndex))++
#define SoAd_IncModeOfSoConDyn(Index, partitionIndex)                                               SoAd_GetModeOfSoConDyn(((Index)), (partitionIndex))++
#define SoAd_IncOpenCloseCounterOfSoConDyn(Index, partitionIndex)                                   SoAd_GetOpenCloseCounterOfSoConDyn(((Index)), (partitionIndex))++
#define SoAd_IncRemAddrDynOfSoConDyn(Index, partitionIndex)                                         SoAd_GetRemAddrDynOfSoConDyn(((Index)), (partitionIndex))++
#define SoAd_IncRemAddrReleaseOfSoConDyn(Index, partitionIndex)                                     SoAd_GetRemAddrReleaseOfSoConDyn(((Index)), (partitionIndex))++
#define SoAd_IncRemAddrStateDynOfSoConDyn(Index, partitionIndex)                                    SoAd_GetRemAddrStateDynOfSoConDyn(((Index)), (partitionIndex))++
#define SoAd_IncLocalPortOfSocketDyn(Index, partitionIndex)                                         SoAd_GetLocalPortOfSocketDyn(((Index)), (partitionIndex))++
#define SoAd_IncSkipBytesOfSocketDyn(Index, partitionIndex)                                         SoAd_GetSkipBytesOfSocketDyn(((Index)), (partitionIndex))++
#define SoAd_IncSoConTxActiveIdxOfSocketDyn(Index, partitionIndex)                                  SoAd_GetSoConTxActiveIdxOfSocketDyn(((Index)), (partitionIndex))++
#define SoAd_IncSocketIdOfSocketDyn(Index, partitionIndex)                                          SoAd_GetSocketIdOfSocketDyn(((Index)), (partitionIndex))++
#define SoAd_IncStateOfSocketDyn(Index, partitionIndex)                                             SoAd_GetStateOfSocketDyn(((Index)), (partitionIndex))++
#define SoAd_IncLenOfTcpTxQueueData(Index, partitionIndex)                                          SoAd_GetLenOfTcpTxQueueData(((Index)), (partitionIndex))++
#define SoAd_IncPduRouteIdxOfTcpTxQueueData(Index, partitionIndex)                                  SoAd_GetPduRouteIdxOfTcpTxQueueData(((Index)), (partitionIndex))++
#define SoAd_IncLvlOfTcpTxQueueMgt(Index, partitionIndex)                                           SoAd_GetLvlOfTcpTxQueueMgt(((Index)), (partitionIndex))++
#define SoAd_IncTcpTxQueueDataIdxOfTcpTxQueueMgt(Index, partitionIndex)                             SoAd_GetTcpTxQueueDataIdxOfTcpTxQueueMgt(((Index)), (partitionIndex))++
#define SoAd_IncTotLenOfTcpTxQueueMgt(Index, partitionIndex)                                        SoAd_GetTotLenOfTcpTxQueueMgt(((Index)), (partitionIndex))++
#define SoAd_IncLvlOfTimeoutListMgmt(Index, partitionIndex)                                         SoAd_GetLvlOfTimeoutListMgmt(((Index)), (partitionIndex))++
#define SoAd_IncNPduUdpTxIdxOfTimeoutListNPduUdpTx(Index, partitionIndex)                           SoAd_GetNPduUdpTxIdxOfTimeoutListNPduUdpTx(((Index)), (partitionIndex))++
#define SoAd_IncTimeoutOfTimeoutListNPduUdpTx(Index, partitionIndex)                                SoAd_GetTimeoutOfTimeoutListNPduUdpTx(((Index)), (partitionIndex))++
#define SoAd_IncTimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap(Index, partitionIndex)             SoAd_GetTimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap(((Index)), (partitionIndex))++
#define SoAd_IncSoConIdxOfTimeoutListUdpAlive(Index, partitionIndex)                                SoAd_GetSoConIdxOfTimeoutListUdpAlive(((Index)), (partitionIndex))++
#define SoAd_IncTimeoutOfTimeoutListUdpAlive(Index, partitionIndex)                                 SoAd_GetTimeoutOfTimeoutListUdpAlive(((Index)), (partitionIndex))++
#define SoAd_IncTimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap(Index, partitionIndex)               SoAd_GetTimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap(((Index)), (partitionIndex))++
#define SoAd_IncTpRxBuffer(Index, partitionIndex)                                                   SoAd_GetTpRxBuffer(((Index)), (partitionIndex))++
#define SoAd_IncTpTxBuffer(Index, partitionIndex)                                                   SoAd_GetTpTxBuffer(((Index)), (partitionIndex))++
#define SoAd_IncTpTxBufferIdxOfTpTxBufferConfigDyn(Index, partitionIndex)                           SoAd_GetTpTxBufferIdxOfTpTxBufferConfigDyn(((Index)), (partitionIndex))++
#define SoAd_IncTriggerBuf(Index, partitionIndex)                                                   SoAd_GetTriggerBuf(((Index)), (partitionIndex))++
#define SoAd_IncLengthOfTriggerBufConfigDyn(Index, partitionIndex)                                  SoAd_GetLengthOfTriggerBufConfigDyn(((Index)), (partitionIndex))++
#define SoAd_IncPduRouteIdxOfTriggerBufConfigDyn(Index, partitionIndex)                             SoAd_GetPduRouteIdxOfTriggerBufConfigDyn(((Index)), (partitionIndex))++
#define SoAd_IncPduRouteDestIdxOfTxMgt(Index, partitionIndex)                                       SoAd_GetPduRouteDestIdxOfTxMgt(((Index)), (partitionIndex))++
#define SoAd_IncTxBufPtrOfTxMgt(Index, partitionIndex)                                              SoAd_GetTxBufPtrOfTxMgt(((Index)), (partitionIndex))++
#define SoAd_IncTxBytesLenOfTxMgt(Index, partitionIndex)                                            SoAd_GetTxBytesLenOfTxMgt(((Index)), (partitionIndex))++
#define SoAd_IncTxBytesPendingOfTxMgt(Index, partitionIndex)                                        SoAd_GetTxBytesPendingOfTxMgt(((Index)), (partitionIndex))++
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCDecrementDataMacros  SoAd Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define SoAd_DecSoConIdxOfBestMatchSoConIdxList(Index, partitionIndex)                              SoAd_GetSoConIdxOfBestMatchSoConIdxList(((Index)), (partitionIndex))--
#define SoAd_DecEventQueueFlag(Index, partitionIndex)                                               SoAd_GetEventQueueFlag(((Index)), (partitionIndex))--
#define SoAd_DecRouteGrpIdxOfEventQueueIfTxRouteGrp(Index, partitionIndex)                          SoAd_GetRouteGrpIdxOfEventQueueIfTxRouteGrp(((Index)), (partitionIndex))--
#define SoAd_DecPduRouteIdxOfEventQueueIfUdpPduRoute(Index, partitionIndex)                         SoAd_GetPduRouteIdxOfEventQueueIfUdpPduRoute(((Index)), (partitionIndex))--
#define SoAd_DecIdxOfEventQueueMgmt(Index, partitionIndex)                                          SoAd_GetIdxOfEventQueueMgmt(((Index)), (partitionIndex))--
#define SoAd_DecLvlOfEventQueueMgmt(Index, partitionIndex)                                          SoAd_GetLvlOfEventQueueMgmt(((Index)), (partitionIndex))--
#define SoAd_DecSoConIdxOfEventQueueStateSoCon(Index, partitionIndex)                               SoAd_GetSoConIdxOfEventQueueStateSoCon(((Index)), (partitionIndex))--
#define SoAd_DecSoConIdxOfEventQueueTpRxSoCon(Index, partitionIndex)                                SoAd_GetSoConIdxOfEventQueueTpRxSoCon(((Index)), (partitionIndex))--
#define SoAd_DecSoConIdxOfEventQueueTpTxSoCon(Index, partitionIndex)                                SoAd_GetSoConIdxOfEventQueueTpTxSoCon(((Index)), (partitionIndex))--
#define SoAd_DecIfRxBuffer(Index, partitionIndex)                                                   SoAd_GetIfRxBuffer(((Index)), (partitionIndex))--
#define SoAd_DecBestMatchListSizeOfInstanceDyn(Index, partitionIndex)                               SoAd_GetBestMatchListSizeOfInstanceDyn(((Index)), (partitionIndex))--
#define SoAd_DecCounterOfInstanceDyn(Index, partitionIndex)                                         SoAd_GetCounterOfInstanceDyn(((Index)), (partitionIndex))--
#define SoAd_DecOpenSocksOfInstanceDyn(Index, partitionIndex)                                       SoAd_GetOpenSocksOfInstanceDyn(((Index)), (partitionIndex))--
#define SoAd_DecIpFragBuf(Index, partitionIndex)                                                    SoAd_GetIpFragBuf(((Index)), (partitionIndex))--
#define SoAd_DecLengthOfIpFragBufConfigDyn(Index, partitionIndex)                                   SoAd_GetLengthOfIpFragBufConfigDyn(((Index)), (partitionIndex))--
#define SoAd_DecIpFragBufConfigIdxOfIpFragMgt(Index, partitionIndex)                                SoAd_GetIpFragBufConfigIdxOfIpFragMgt(((Index)), (partitionIndex))--
#define SoAd_DecIpAddrStateOfLocalAddrDyn(Index, partitionIndex)                                    SoAd_GetIpAddrStateOfLocalAddrDyn(((Index)), (partitionIndex))--
#define SoAd_DecMetaDataRxBuffer(Index, partitionIndex)                                             SoAd_GetMetaDataRxBuffer(((Index)), (partitionIndex))--
#define SoAd_DecNPduUdpTxBuffer(Index, partitionIndex)                                              SoAd_GetNPduUdpTxBuffer(((Index)), (partitionIndex))--
#define SoAd_DecBufLenOfNPduUdpTxDyn(Index, partitionIndex)                                         SoAd_GetBufLenOfNPduUdpTxDyn(((Index)), (partitionIndex))--
#define SoAd_DecLvlOfNPduUdpTxDyn(Index, partitionIndex)                                            SoAd_GetLvlOfNPduUdpTxDyn(((Index)), (partitionIndex))--
#define SoAd_DecRetryCntOfNPduUdpTxDyn(Index, partitionIndex)                                       SoAd_GetRetryCntOfNPduUdpTxDyn(((Index)), (partitionIndex))--
#define SoAd_DecTotalLenOfNPduUdpTxDyn(Index, partitionIndex)                                       SoAd_GetTotalLenOfNPduUdpTxDyn(((Index)), (partitionIndex))--
#define SoAd_DecTransmissionStateOfNPduUdpTxDyn(Index, partitionIndex)                              SoAd_GetTransmissionStateOfNPduUdpTxDyn(((Index)), (partitionIndex))--
#define SoAd_DecLenOfNPduUdpTxQueue(Index, partitionIndex)                                          SoAd_GetLenOfNPduUdpTxQueue(((Index)), (partitionIndex))--
#define SoAd_DecNPduUdpTxBufferIdxOfNPduUdpTxQueue(Index, partitionIndex)                           SoAd_GetNPduUdpTxBufferIdxOfNPduUdpTxQueue(((Index)), (partitionIndex))--
#define SoAd_DecPduRouteDestIdxOfNPduUdpTxQueue(Index, partitionIndex)                              SoAd_GetPduRouteDestIdxOfNPduUdpTxQueue(((Index)), (partitionIndex))--
#define SoAd_DecInitializedOfPartitionDyn(Index, partitionIndex)                                    SoAd_GetInitializedOfPartitionDyn(((Index)), (partitionIndex))--
#define SoAd_DecPendingTxConfNumOfPduRouteDyn(Index, partitionIndex)                                SoAd_GetPendingTxConfNumOfPduRouteDyn(((Index)), (partitionIndex))--
#define SoAd_DecRemAddrRcv(Index, partitionIndex)                                                   SoAd_GetRemAddrRcv(((Index)), (partitionIndex))--
#define SoAd_DecFlagsOfRouteGrpSoConDyn(Index, partitionIndex)                                      SoAd_GetFlagsOfRouteGrpSoConDyn(((Index)), (partitionIndex))--
#define SoAd_DecRxBufStructSegIdxOfRxBufStructMgt(Index, partitionIndex)                            SoAd_GetRxBufStructSegIdxOfRxBufStructMgt(((Index)), (partitionIndex))--
#define SoAd_DecRxBufStructSegLvlOfRxBufStructMgt(Index, partitionIndex)                            SoAd_GetRxBufStructSegLvlOfRxBufStructMgt(((Index)), (partitionIndex))--
#define SoAd_DecDataPtrOfRxBufStructSeg(Index, partitionIndex)                                      SoAd_GetDataPtrOfRxBufStructSeg(((Index)), (partitionIndex))--
#define SoAd_DecLenOfRxBufStructSeg(Index, partitionIndex)                                          SoAd_GetLenOfRxBufStructSeg(((Index)), (partitionIndex))--
#define SoAd_DecIfRxBufferIdxOfRxBufferConfigDyn(Index, partitionIndex)                             SoAd_GetIfRxBufferIdxOfRxBufferConfigDyn(((Index)), (partitionIndex))--
#define SoAd_DecTpRxBufferIdxOfRxBufferConfigDyn(Index, partitionIndex)                             SoAd_GetTpRxBufferIdxOfRxBufferConfigDyn(((Index)), (partitionIndex))--
#define SoAd_DecRxBytesPendingOfRxMgt(Index, partitionIndex)                                        SoAd_GetRxBytesPendingOfRxMgt(((Index)), (partitionIndex))--
#define SoAd_DecSocketRouteDestIdxOfRxMgt(Index, partitionIndex)                                    SoAd_GetSocketRouteDestIdxOfRxMgt(((Index)), (partitionIndex))--
#define SoAd_DecCloseModeOfSoConDyn(Index, partitionIndex)                                          SoAd_GetCloseModeOfSoConDyn(((Index)), (partitionIndex))--
#define SoAd_DecModeOfSoConDyn(Index, partitionIndex)                                               SoAd_GetModeOfSoConDyn(((Index)), (partitionIndex))--
#define SoAd_DecOpenCloseCounterOfSoConDyn(Index, partitionIndex)                                   SoAd_GetOpenCloseCounterOfSoConDyn(((Index)), (partitionIndex))--
#define SoAd_DecRemAddrDynOfSoConDyn(Index, partitionIndex)                                         SoAd_GetRemAddrDynOfSoConDyn(((Index)), (partitionIndex))--
#define SoAd_DecRemAddrReleaseOfSoConDyn(Index, partitionIndex)                                     SoAd_GetRemAddrReleaseOfSoConDyn(((Index)), (partitionIndex))--
#define SoAd_DecRemAddrStateDynOfSoConDyn(Index, partitionIndex)                                    SoAd_GetRemAddrStateDynOfSoConDyn(((Index)), (partitionIndex))--
#define SoAd_DecLocalPortOfSocketDyn(Index, partitionIndex)                                         SoAd_GetLocalPortOfSocketDyn(((Index)), (partitionIndex))--
#define SoAd_DecSkipBytesOfSocketDyn(Index, partitionIndex)                                         SoAd_GetSkipBytesOfSocketDyn(((Index)), (partitionIndex))--
#define SoAd_DecSoConTxActiveIdxOfSocketDyn(Index, partitionIndex)                                  SoAd_GetSoConTxActiveIdxOfSocketDyn(((Index)), (partitionIndex))--
#define SoAd_DecSocketIdOfSocketDyn(Index, partitionIndex)                                          SoAd_GetSocketIdOfSocketDyn(((Index)), (partitionIndex))--
#define SoAd_DecStateOfSocketDyn(Index, partitionIndex)                                             SoAd_GetStateOfSocketDyn(((Index)), (partitionIndex))--
#define SoAd_DecLenOfTcpTxQueueData(Index, partitionIndex)                                          SoAd_GetLenOfTcpTxQueueData(((Index)), (partitionIndex))--
#define SoAd_DecPduRouteIdxOfTcpTxQueueData(Index, partitionIndex)                                  SoAd_GetPduRouteIdxOfTcpTxQueueData(((Index)), (partitionIndex))--
#define SoAd_DecLvlOfTcpTxQueueMgt(Index, partitionIndex)                                           SoAd_GetLvlOfTcpTxQueueMgt(((Index)), (partitionIndex))--
#define SoAd_DecTcpTxQueueDataIdxOfTcpTxQueueMgt(Index, partitionIndex)                             SoAd_GetTcpTxQueueDataIdxOfTcpTxQueueMgt(((Index)), (partitionIndex))--
#define SoAd_DecTotLenOfTcpTxQueueMgt(Index, partitionIndex)                                        SoAd_GetTotLenOfTcpTxQueueMgt(((Index)), (partitionIndex))--
#define SoAd_DecLvlOfTimeoutListMgmt(Index, partitionIndex)                                         SoAd_GetLvlOfTimeoutListMgmt(((Index)), (partitionIndex))--
#define SoAd_DecNPduUdpTxIdxOfTimeoutListNPduUdpTx(Index, partitionIndex)                           SoAd_GetNPduUdpTxIdxOfTimeoutListNPduUdpTx(((Index)), (partitionIndex))--
#define SoAd_DecTimeoutOfTimeoutListNPduUdpTx(Index, partitionIndex)                                SoAd_GetTimeoutOfTimeoutListNPduUdpTx(((Index)), (partitionIndex))--
#define SoAd_DecTimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap(Index, partitionIndex)             SoAd_GetTimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap(((Index)), (partitionIndex))--
#define SoAd_DecSoConIdxOfTimeoutListUdpAlive(Index, partitionIndex)                                SoAd_GetSoConIdxOfTimeoutListUdpAlive(((Index)), (partitionIndex))--
#define SoAd_DecTimeoutOfTimeoutListUdpAlive(Index, partitionIndex)                                 SoAd_GetTimeoutOfTimeoutListUdpAlive(((Index)), (partitionIndex))--
#define SoAd_DecTimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap(Index, partitionIndex)               SoAd_GetTimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap(((Index)), (partitionIndex))--
#define SoAd_DecTpRxBuffer(Index, partitionIndex)                                                   SoAd_GetTpRxBuffer(((Index)), (partitionIndex))--
#define SoAd_DecTpTxBuffer(Index, partitionIndex)                                                   SoAd_GetTpTxBuffer(((Index)), (partitionIndex))--
#define SoAd_DecTpTxBufferIdxOfTpTxBufferConfigDyn(Index, partitionIndex)                           SoAd_GetTpTxBufferIdxOfTpTxBufferConfigDyn(((Index)), (partitionIndex))--
#define SoAd_DecTriggerBuf(Index, partitionIndex)                                                   SoAd_GetTriggerBuf(((Index)), (partitionIndex))--
#define SoAd_DecLengthOfTriggerBufConfigDyn(Index, partitionIndex)                                  SoAd_GetLengthOfTriggerBufConfigDyn(((Index)), (partitionIndex))--
#define SoAd_DecPduRouteIdxOfTriggerBufConfigDyn(Index, partitionIndex)                             SoAd_GetPduRouteIdxOfTriggerBufConfigDyn(((Index)), (partitionIndex))--
#define SoAd_DecPduRouteDestIdxOfTxMgt(Index, partitionIndex)                                       SoAd_GetPduRouteDestIdxOfTxMgt(((Index)), (partitionIndex))--
#define SoAd_DecTxBufPtrOfTxMgt(Index, partitionIndex)                                              SoAd_GetTxBufPtrOfTxMgt(((Index)), (partitionIndex))--
#define SoAd_DecTxBytesLenOfTxMgt(Index, partitionIndex)                                            SoAd_GetTxBytesLenOfTxMgt(((Index)), (partitionIndex))--
#define SoAd_DecTxBytesPendingOfTxMgt(Index, partitionIndex)                                        SoAd_GetTxBytesPendingOfTxMgt(((Index)), (partitionIndex))--
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCAddDataMacros  SoAd Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define SoAd_AddSoConIdxOfBestMatchSoConIdxList(Index, Value, partitionIndex)                       SoAd_SetSoConIdxOfBestMatchSoConIdxList(Index, (SoAd_GetSoConIdxOfBestMatchSoConIdxList(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddEventQueueFlag(Index, Value, partitionIndex)                                        SoAd_SetEventQueueFlag(Index, (SoAd_GetEventQueueFlag(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddRouteGrpIdxOfEventQueueIfTxRouteGrp(Index, Value, partitionIndex)                   SoAd_SetRouteGrpIdxOfEventQueueIfTxRouteGrp(Index, (SoAd_GetRouteGrpIdxOfEventQueueIfTxRouteGrp(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddPduRouteIdxOfEventQueueIfUdpPduRoute(Index, Value, partitionIndex)                  SoAd_SetPduRouteIdxOfEventQueueIfUdpPduRoute(Index, (SoAd_GetPduRouteIdxOfEventQueueIfUdpPduRoute(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddIdxOfEventQueueMgmt(Index, Value, partitionIndex)                                   SoAd_SetIdxOfEventQueueMgmt(Index, (SoAd_GetIdxOfEventQueueMgmt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddLvlOfEventQueueMgmt(Index, Value, partitionIndex)                                   SoAd_SetLvlOfEventQueueMgmt(Index, (SoAd_GetLvlOfEventQueueMgmt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddSoConIdxOfEventQueueStateSoCon(Index, Value, partitionIndex)                        SoAd_SetSoConIdxOfEventQueueStateSoCon(Index, (SoAd_GetSoConIdxOfEventQueueStateSoCon(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddSoConIdxOfEventQueueTpRxSoCon(Index, Value, partitionIndex)                         SoAd_SetSoConIdxOfEventQueueTpRxSoCon(Index, (SoAd_GetSoConIdxOfEventQueueTpRxSoCon(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddSoConIdxOfEventQueueTpTxSoCon(Index, Value, partitionIndex)                         SoAd_SetSoConIdxOfEventQueueTpTxSoCon(Index, (SoAd_GetSoConIdxOfEventQueueTpTxSoCon(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddIfRxBuffer(Index, Value, partitionIndex)                                            SoAd_SetIfRxBuffer(Index, (SoAd_GetIfRxBuffer(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddBestMatchListSizeOfInstanceDyn(Index, Value, partitionIndex)                        SoAd_SetBestMatchListSizeOfInstanceDyn(Index, (SoAd_GetBestMatchListSizeOfInstanceDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddCounterOfInstanceDyn(Index, Value, partitionIndex)                                  SoAd_SetCounterOfInstanceDyn(Index, (SoAd_GetCounterOfInstanceDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddOpenSocksOfInstanceDyn(Index, Value, partitionIndex)                                SoAd_SetOpenSocksOfInstanceDyn(Index, (SoAd_GetOpenSocksOfInstanceDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddIpFragBuf(Index, Value, partitionIndex)                                             SoAd_SetIpFragBuf(Index, (SoAd_GetIpFragBuf(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddLengthOfIpFragBufConfigDyn(Index, Value, partitionIndex)                            SoAd_SetLengthOfIpFragBufConfigDyn(Index, (SoAd_GetLengthOfIpFragBufConfigDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddIpFragBufConfigIdxOfIpFragMgt(Index, Value, partitionIndex)                         SoAd_SetIpFragBufConfigIdxOfIpFragMgt(Index, (SoAd_GetIpFragBufConfigIdxOfIpFragMgt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddIpAddrStateOfLocalAddrDyn(Index, Value, partitionIndex)                             SoAd_SetIpAddrStateOfLocalAddrDyn(Index, (SoAd_GetIpAddrStateOfLocalAddrDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddMetaDataRxBuffer(Index, Value, partitionIndex)                                      SoAd_SetMetaDataRxBuffer(Index, (SoAd_GetMetaDataRxBuffer(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddNPduUdpTxBuffer(Index, Value, partitionIndex)                                       SoAd_SetNPduUdpTxBuffer(Index, (SoAd_GetNPduUdpTxBuffer(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddBufLenOfNPduUdpTxDyn(Index, Value, partitionIndex)                                  SoAd_SetBufLenOfNPduUdpTxDyn(Index, (SoAd_GetBufLenOfNPduUdpTxDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddLvlOfNPduUdpTxDyn(Index, Value, partitionIndex)                                     SoAd_SetLvlOfNPduUdpTxDyn(Index, (SoAd_GetLvlOfNPduUdpTxDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddRetryCntOfNPduUdpTxDyn(Index, Value, partitionIndex)                                SoAd_SetRetryCntOfNPduUdpTxDyn(Index, (SoAd_GetRetryCntOfNPduUdpTxDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTotalLenOfNPduUdpTxDyn(Index, Value, partitionIndex)                                SoAd_SetTotalLenOfNPduUdpTxDyn(Index, (SoAd_GetTotalLenOfNPduUdpTxDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTransmissionStateOfNPduUdpTxDyn(Index, Value, partitionIndex)                       SoAd_SetTransmissionStateOfNPduUdpTxDyn(Index, (SoAd_GetTransmissionStateOfNPduUdpTxDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddLenOfNPduUdpTxQueue(Index, Value, partitionIndex)                                   SoAd_SetLenOfNPduUdpTxQueue(Index, (SoAd_GetLenOfNPduUdpTxQueue(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddNPduUdpTxBufferIdxOfNPduUdpTxQueue(Index, Value, partitionIndex)                    SoAd_SetNPduUdpTxBufferIdxOfNPduUdpTxQueue(Index, (SoAd_GetNPduUdpTxBufferIdxOfNPduUdpTxQueue(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddPduRouteDestIdxOfNPduUdpTxQueue(Index, Value, partitionIndex)                       SoAd_SetPduRouteDestIdxOfNPduUdpTxQueue(Index, (SoAd_GetPduRouteDestIdxOfNPduUdpTxQueue(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddInitializedOfPartitionDyn(Index, Value, partitionIndex)                             SoAd_SetInitializedOfPartitionDyn(Index, (SoAd_GetInitializedOfPartitionDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddPendingTxConfNumOfPduRouteDyn(Index, Value, partitionIndex)                         SoAd_SetPendingTxConfNumOfPduRouteDyn(Index, (SoAd_GetPendingTxConfNumOfPduRouteDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddRemAddrRcv(Index, Value, partitionIndex)                                            SoAd_SetRemAddrRcv(Index, (SoAd_GetRemAddrRcv(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddFlagsOfRouteGrpSoConDyn(Index, Value, partitionIndex)                               SoAd_SetFlagsOfRouteGrpSoConDyn(Index, (SoAd_GetFlagsOfRouteGrpSoConDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddRxBufStructSegIdxOfRxBufStructMgt(Index, Value, partitionIndex)                     SoAd_SetRxBufStructSegIdxOfRxBufStructMgt(Index, (SoAd_GetRxBufStructSegIdxOfRxBufStructMgt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddRxBufStructSegLvlOfRxBufStructMgt(Index, Value, partitionIndex)                     SoAd_SetRxBufStructSegLvlOfRxBufStructMgt(Index, (SoAd_GetRxBufStructSegLvlOfRxBufStructMgt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddDataPtrOfRxBufStructSeg(Index, Value, partitionIndex)                               SoAd_SetDataPtrOfRxBufStructSeg(Index, (SoAd_GetDataPtrOfRxBufStructSeg(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddLenOfRxBufStructSeg(Index, Value, partitionIndex)                                   SoAd_SetLenOfRxBufStructSeg(Index, (SoAd_GetLenOfRxBufStructSeg(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddIfRxBufferIdxOfRxBufferConfigDyn(Index, Value, partitionIndex)                      SoAd_SetIfRxBufferIdxOfRxBufferConfigDyn(Index, (SoAd_GetIfRxBufferIdxOfRxBufferConfigDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTpRxBufferIdxOfRxBufferConfigDyn(Index, Value, partitionIndex)                      SoAd_SetTpRxBufferIdxOfRxBufferConfigDyn(Index, (SoAd_GetTpRxBufferIdxOfRxBufferConfigDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddRxBytesPendingOfRxMgt(Index, Value, partitionIndex)                                 SoAd_SetRxBytesPendingOfRxMgt(Index, (SoAd_GetRxBytesPendingOfRxMgt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddSocketRouteDestIdxOfRxMgt(Index, Value, partitionIndex)                             SoAd_SetSocketRouteDestIdxOfRxMgt(Index, (SoAd_GetSocketRouteDestIdxOfRxMgt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddCloseModeOfSoConDyn(Index, Value, partitionIndex)                                   SoAd_SetCloseModeOfSoConDyn(Index, (SoAd_GetCloseModeOfSoConDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddModeOfSoConDyn(Index, Value, partitionIndex)                                        SoAd_SetModeOfSoConDyn(Index, (SoAd_GetModeOfSoConDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddOpenCloseCounterOfSoConDyn(Index, Value, partitionIndex)                            SoAd_SetOpenCloseCounterOfSoConDyn(Index, (SoAd_GetOpenCloseCounterOfSoConDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddRemAddrDynOfSoConDyn(Index, Value, partitionIndex)                                  SoAd_SetRemAddrDynOfSoConDyn(Index, (SoAd_GetRemAddrDynOfSoConDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddRemAddrReleaseOfSoConDyn(Index, Value, partitionIndex)                              SoAd_SetRemAddrReleaseOfSoConDyn(Index, (SoAd_GetRemAddrReleaseOfSoConDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddRemAddrStateDynOfSoConDyn(Index, Value, partitionIndex)                             SoAd_SetRemAddrStateDynOfSoConDyn(Index, (SoAd_GetRemAddrStateDynOfSoConDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddLocalPortOfSocketDyn(Index, Value, partitionIndex)                                  SoAd_SetLocalPortOfSocketDyn(Index, (SoAd_GetLocalPortOfSocketDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddSkipBytesOfSocketDyn(Index, Value, partitionIndex)                                  SoAd_SetSkipBytesOfSocketDyn(Index, (SoAd_GetSkipBytesOfSocketDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddSoConTxActiveIdxOfSocketDyn(Index, Value, partitionIndex)                           SoAd_SetSoConTxActiveIdxOfSocketDyn(Index, (SoAd_GetSoConTxActiveIdxOfSocketDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddSocketIdOfSocketDyn(Index, Value, partitionIndex)                                   SoAd_SetSocketIdOfSocketDyn(Index, (SoAd_GetSocketIdOfSocketDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddStateOfSocketDyn(Index, Value, partitionIndex)                                      SoAd_SetStateOfSocketDyn(Index, (SoAd_GetStateOfSocketDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddLenOfTcpTxQueueData(Index, Value, partitionIndex)                                   SoAd_SetLenOfTcpTxQueueData(Index, (SoAd_GetLenOfTcpTxQueueData(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddPduRouteIdxOfTcpTxQueueData(Index, Value, partitionIndex)                           SoAd_SetPduRouteIdxOfTcpTxQueueData(Index, (SoAd_GetPduRouteIdxOfTcpTxQueueData(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddLvlOfTcpTxQueueMgt(Index, Value, partitionIndex)                                    SoAd_SetLvlOfTcpTxQueueMgt(Index, (SoAd_GetLvlOfTcpTxQueueMgt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTcpTxQueueDataIdxOfTcpTxQueueMgt(Index, Value, partitionIndex)                      SoAd_SetTcpTxQueueDataIdxOfTcpTxQueueMgt(Index, (SoAd_GetTcpTxQueueDataIdxOfTcpTxQueueMgt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTotLenOfTcpTxQueueMgt(Index, Value, partitionIndex)                                 SoAd_SetTotLenOfTcpTxQueueMgt(Index, (SoAd_GetTotLenOfTcpTxQueueMgt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddLvlOfTimeoutListMgmt(Index, Value, partitionIndex)                                  SoAd_SetLvlOfTimeoutListMgmt(Index, (SoAd_GetLvlOfTimeoutListMgmt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddNPduUdpTxIdxOfTimeoutListNPduUdpTx(Index, Value, partitionIndex)                    SoAd_SetNPduUdpTxIdxOfTimeoutListNPduUdpTx(Index, (SoAd_GetNPduUdpTxIdxOfTimeoutListNPduUdpTx(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTimeoutOfTimeoutListNPduUdpTx(Index, Value, partitionIndex)                         SoAd_SetTimeoutOfTimeoutListNPduUdpTx(Index, (SoAd_GetTimeoutOfTimeoutListNPduUdpTx(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap(Index, Value, partitionIndex)      SoAd_SetTimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap(Index, (SoAd_GetTimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddSoConIdxOfTimeoutListUdpAlive(Index, Value, partitionIndex)                         SoAd_SetSoConIdxOfTimeoutListUdpAlive(Index, (SoAd_GetSoConIdxOfTimeoutListUdpAlive(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTimeoutOfTimeoutListUdpAlive(Index, Value, partitionIndex)                          SoAd_SetTimeoutOfTimeoutListUdpAlive(Index, (SoAd_GetTimeoutOfTimeoutListUdpAlive(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap(Index, Value, partitionIndex)        SoAd_SetTimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap(Index, (SoAd_GetTimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTpRxBuffer(Index, Value, partitionIndex)                                            SoAd_SetTpRxBuffer(Index, (SoAd_GetTpRxBuffer(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTpTxBuffer(Index, Value, partitionIndex)                                            SoAd_SetTpTxBuffer(Index, (SoAd_GetTpTxBuffer(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTpTxBufferIdxOfTpTxBufferConfigDyn(Index, Value, partitionIndex)                    SoAd_SetTpTxBufferIdxOfTpTxBufferConfigDyn(Index, (SoAd_GetTpTxBufferIdxOfTpTxBufferConfigDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTriggerBuf(Index, Value, partitionIndex)                                            SoAd_SetTriggerBuf(Index, (SoAd_GetTriggerBuf(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddLengthOfTriggerBufConfigDyn(Index, Value, partitionIndex)                           SoAd_SetLengthOfTriggerBufConfigDyn(Index, (SoAd_GetLengthOfTriggerBufConfigDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddPduRouteIdxOfTriggerBufConfigDyn(Index, Value, partitionIndex)                      SoAd_SetPduRouteIdxOfTriggerBufConfigDyn(Index, (SoAd_GetPduRouteIdxOfTriggerBufConfigDyn(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddPduRouteDestIdxOfTxMgt(Index, Value, partitionIndex)                                SoAd_SetPduRouteDestIdxOfTxMgt(Index, (SoAd_GetPduRouteDestIdxOfTxMgt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTxBufPtrOfTxMgt(Index, Value, partitionIndex)                                       SoAd_SetTxBufPtrOfTxMgt(Index, (SoAd_GetTxBufPtrOfTxMgt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTxBytesLenOfTxMgt(Index, Value, partitionIndex)                                     SoAd_SetTxBytesLenOfTxMgt(Index, (SoAd_GetTxBytesLenOfTxMgt(((Index)), (partitionIndex)) + Value), partitionIndex)
#define SoAd_AddTxBytesPendingOfTxMgt(Index, Value, partitionIndex)                                 SoAd_SetTxBytesPendingOfTxMgt(Index, (SoAd_GetTxBytesPendingOfTxMgt(((Index)), (partitionIndex)) + Value), partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCSubstractDataMacros  SoAd Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define SoAd_SubSoConIdxOfBestMatchSoConIdxList(Index, Value, partitionIndex)                       SoAd_SetSoConIdxOfBestMatchSoConIdxList(Index, (SoAd_GetSoConIdxOfBestMatchSoConIdxList(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubEventQueueFlag(Index, Value, partitionIndex)                                        SoAd_SetEventQueueFlag(Index, (SoAd_GetEventQueueFlag(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubRouteGrpIdxOfEventQueueIfTxRouteGrp(Index, Value, partitionIndex)                   SoAd_SetRouteGrpIdxOfEventQueueIfTxRouteGrp(Index, (SoAd_GetRouteGrpIdxOfEventQueueIfTxRouteGrp(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubPduRouteIdxOfEventQueueIfUdpPduRoute(Index, Value, partitionIndex)                  SoAd_SetPduRouteIdxOfEventQueueIfUdpPduRoute(Index, (SoAd_GetPduRouteIdxOfEventQueueIfUdpPduRoute(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubIdxOfEventQueueMgmt(Index, Value, partitionIndex)                                   SoAd_SetIdxOfEventQueueMgmt(Index, (SoAd_GetIdxOfEventQueueMgmt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubLvlOfEventQueueMgmt(Index, Value, partitionIndex)                                   SoAd_SetLvlOfEventQueueMgmt(Index, (SoAd_GetLvlOfEventQueueMgmt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubSoConIdxOfEventQueueStateSoCon(Index, Value, partitionIndex)                        SoAd_SetSoConIdxOfEventQueueStateSoCon(Index, (SoAd_GetSoConIdxOfEventQueueStateSoCon(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubSoConIdxOfEventQueueTpRxSoCon(Index, Value, partitionIndex)                         SoAd_SetSoConIdxOfEventQueueTpRxSoCon(Index, (SoAd_GetSoConIdxOfEventQueueTpRxSoCon(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubSoConIdxOfEventQueueTpTxSoCon(Index, Value, partitionIndex)                         SoAd_SetSoConIdxOfEventQueueTpTxSoCon(Index, (SoAd_GetSoConIdxOfEventQueueTpTxSoCon(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubIfRxBuffer(Index, Value, partitionIndex)                                            SoAd_SetIfRxBuffer(Index, (SoAd_GetIfRxBuffer(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubBestMatchListSizeOfInstanceDyn(Index, Value, partitionIndex)                        SoAd_SetBestMatchListSizeOfInstanceDyn(Index, (SoAd_GetBestMatchListSizeOfInstanceDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubCounterOfInstanceDyn(Index, Value, partitionIndex)                                  SoAd_SetCounterOfInstanceDyn(Index, (SoAd_GetCounterOfInstanceDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubOpenSocksOfInstanceDyn(Index, Value, partitionIndex)                                SoAd_SetOpenSocksOfInstanceDyn(Index, (SoAd_GetOpenSocksOfInstanceDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubIpFragBuf(Index, Value, partitionIndex)                                             SoAd_SetIpFragBuf(Index, (SoAd_GetIpFragBuf(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubLengthOfIpFragBufConfigDyn(Index, Value, partitionIndex)                            SoAd_SetLengthOfIpFragBufConfigDyn(Index, (SoAd_GetLengthOfIpFragBufConfigDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubIpFragBufConfigIdxOfIpFragMgt(Index, Value, partitionIndex)                         SoAd_SetIpFragBufConfigIdxOfIpFragMgt(Index, (SoAd_GetIpFragBufConfigIdxOfIpFragMgt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubIpAddrStateOfLocalAddrDyn(Index, Value, partitionIndex)                             SoAd_SetIpAddrStateOfLocalAddrDyn(Index, (SoAd_GetIpAddrStateOfLocalAddrDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubMetaDataRxBuffer(Index, Value, partitionIndex)                                      SoAd_SetMetaDataRxBuffer(Index, (SoAd_GetMetaDataRxBuffer(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubNPduUdpTxBuffer(Index, Value, partitionIndex)                                       SoAd_SetNPduUdpTxBuffer(Index, (SoAd_GetNPduUdpTxBuffer(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubBufLenOfNPduUdpTxDyn(Index, Value, partitionIndex)                                  SoAd_SetBufLenOfNPduUdpTxDyn(Index, (SoAd_GetBufLenOfNPduUdpTxDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubLvlOfNPduUdpTxDyn(Index, Value, partitionIndex)                                     SoAd_SetLvlOfNPduUdpTxDyn(Index, (SoAd_GetLvlOfNPduUdpTxDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubRetryCntOfNPduUdpTxDyn(Index, Value, partitionIndex)                                SoAd_SetRetryCntOfNPduUdpTxDyn(Index, (SoAd_GetRetryCntOfNPduUdpTxDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTotalLenOfNPduUdpTxDyn(Index, Value, partitionIndex)                                SoAd_SetTotalLenOfNPduUdpTxDyn(Index, (SoAd_GetTotalLenOfNPduUdpTxDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTransmissionStateOfNPduUdpTxDyn(Index, Value, partitionIndex)                       SoAd_SetTransmissionStateOfNPduUdpTxDyn(Index, (SoAd_GetTransmissionStateOfNPduUdpTxDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubLenOfNPduUdpTxQueue(Index, Value, partitionIndex)                                   SoAd_SetLenOfNPduUdpTxQueue(Index, (SoAd_GetLenOfNPduUdpTxQueue(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubNPduUdpTxBufferIdxOfNPduUdpTxQueue(Index, Value, partitionIndex)                    SoAd_SetNPduUdpTxBufferIdxOfNPduUdpTxQueue(Index, (SoAd_GetNPduUdpTxBufferIdxOfNPduUdpTxQueue(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubPduRouteDestIdxOfNPduUdpTxQueue(Index, Value, partitionIndex)                       SoAd_SetPduRouteDestIdxOfNPduUdpTxQueue(Index, (SoAd_GetPduRouteDestIdxOfNPduUdpTxQueue(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubInitializedOfPartitionDyn(Index, Value, partitionIndex)                             SoAd_SetInitializedOfPartitionDyn(Index, (SoAd_GetInitializedOfPartitionDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubPendingTxConfNumOfPduRouteDyn(Index, Value, partitionIndex)                         SoAd_SetPendingTxConfNumOfPduRouteDyn(Index, (SoAd_GetPendingTxConfNumOfPduRouteDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubRemAddrRcv(Index, Value, partitionIndex)                                            SoAd_SetRemAddrRcv(Index, (SoAd_GetRemAddrRcv(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubFlagsOfRouteGrpSoConDyn(Index, Value, partitionIndex)                               SoAd_SetFlagsOfRouteGrpSoConDyn(Index, (SoAd_GetFlagsOfRouteGrpSoConDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubRxBufStructSegIdxOfRxBufStructMgt(Index, Value, partitionIndex)                     SoAd_SetRxBufStructSegIdxOfRxBufStructMgt(Index, (SoAd_GetRxBufStructSegIdxOfRxBufStructMgt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubRxBufStructSegLvlOfRxBufStructMgt(Index, Value, partitionIndex)                     SoAd_SetRxBufStructSegLvlOfRxBufStructMgt(Index, (SoAd_GetRxBufStructSegLvlOfRxBufStructMgt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubDataPtrOfRxBufStructSeg(Index, Value, partitionIndex)                               SoAd_SetDataPtrOfRxBufStructSeg(Index, (SoAd_GetDataPtrOfRxBufStructSeg(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubLenOfRxBufStructSeg(Index, Value, partitionIndex)                                   SoAd_SetLenOfRxBufStructSeg(Index, (SoAd_GetLenOfRxBufStructSeg(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubIfRxBufferIdxOfRxBufferConfigDyn(Index, Value, partitionIndex)                      SoAd_SetIfRxBufferIdxOfRxBufferConfigDyn(Index, (SoAd_GetIfRxBufferIdxOfRxBufferConfigDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTpRxBufferIdxOfRxBufferConfigDyn(Index, Value, partitionIndex)                      SoAd_SetTpRxBufferIdxOfRxBufferConfigDyn(Index, (SoAd_GetTpRxBufferIdxOfRxBufferConfigDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubRxBytesPendingOfRxMgt(Index, Value, partitionIndex)                                 SoAd_SetRxBytesPendingOfRxMgt(Index, (SoAd_GetRxBytesPendingOfRxMgt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubSocketRouteDestIdxOfRxMgt(Index, Value, partitionIndex)                             SoAd_SetSocketRouteDestIdxOfRxMgt(Index, (SoAd_GetSocketRouteDestIdxOfRxMgt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubCloseModeOfSoConDyn(Index, Value, partitionIndex)                                   SoAd_SetCloseModeOfSoConDyn(Index, (SoAd_GetCloseModeOfSoConDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubModeOfSoConDyn(Index, Value, partitionIndex)                                        SoAd_SetModeOfSoConDyn(Index, (SoAd_GetModeOfSoConDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubOpenCloseCounterOfSoConDyn(Index, Value, partitionIndex)                            SoAd_SetOpenCloseCounterOfSoConDyn(Index, (SoAd_GetOpenCloseCounterOfSoConDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubRemAddrDynOfSoConDyn(Index, Value, partitionIndex)                                  SoAd_SetRemAddrDynOfSoConDyn(Index, (SoAd_GetRemAddrDynOfSoConDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubRemAddrReleaseOfSoConDyn(Index, Value, partitionIndex)                              SoAd_SetRemAddrReleaseOfSoConDyn(Index, (SoAd_GetRemAddrReleaseOfSoConDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubRemAddrStateDynOfSoConDyn(Index, Value, partitionIndex)                             SoAd_SetRemAddrStateDynOfSoConDyn(Index, (SoAd_GetRemAddrStateDynOfSoConDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubLocalPortOfSocketDyn(Index, Value, partitionIndex)                                  SoAd_SetLocalPortOfSocketDyn(Index, (SoAd_GetLocalPortOfSocketDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubSkipBytesOfSocketDyn(Index, Value, partitionIndex)                                  SoAd_SetSkipBytesOfSocketDyn(Index, (SoAd_GetSkipBytesOfSocketDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubSoConTxActiveIdxOfSocketDyn(Index, Value, partitionIndex)                           SoAd_SetSoConTxActiveIdxOfSocketDyn(Index, (SoAd_GetSoConTxActiveIdxOfSocketDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubSocketIdOfSocketDyn(Index, Value, partitionIndex)                                   SoAd_SetSocketIdOfSocketDyn(Index, (SoAd_GetSocketIdOfSocketDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubStateOfSocketDyn(Index, Value, partitionIndex)                                      SoAd_SetStateOfSocketDyn(Index, (SoAd_GetStateOfSocketDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubLenOfTcpTxQueueData(Index, Value, partitionIndex)                                   SoAd_SetLenOfTcpTxQueueData(Index, (SoAd_GetLenOfTcpTxQueueData(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubPduRouteIdxOfTcpTxQueueData(Index, Value, partitionIndex)                           SoAd_SetPduRouteIdxOfTcpTxQueueData(Index, (SoAd_GetPduRouteIdxOfTcpTxQueueData(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubLvlOfTcpTxQueueMgt(Index, Value, partitionIndex)                                    SoAd_SetLvlOfTcpTxQueueMgt(Index, (SoAd_GetLvlOfTcpTxQueueMgt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTcpTxQueueDataIdxOfTcpTxQueueMgt(Index, Value, partitionIndex)                      SoAd_SetTcpTxQueueDataIdxOfTcpTxQueueMgt(Index, (SoAd_GetTcpTxQueueDataIdxOfTcpTxQueueMgt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTotLenOfTcpTxQueueMgt(Index, Value, partitionIndex)                                 SoAd_SetTotLenOfTcpTxQueueMgt(Index, (SoAd_GetTotLenOfTcpTxQueueMgt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubLvlOfTimeoutListMgmt(Index, Value, partitionIndex)                                  SoAd_SetLvlOfTimeoutListMgmt(Index, (SoAd_GetLvlOfTimeoutListMgmt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubNPduUdpTxIdxOfTimeoutListNPduUdpTx(Index, Value, partitionIndex)                    SoAd_SetNPduUdpTxIdxOfTimeoutListNPduUdpTx(Index, (SoAd_GetNPduUdpTxIdxOfTimeoutListNPduUdpTx(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTimeoutOfTimeoutListNPduUdpTx(Index, Value, partitionIndex)                         SoAd_SetTimeoutOfTimeoutListNPduUdpTx(Index, (SoAd_GetTimeoutOfTimeoutListNPduUdpTx(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap(Index, Value, partitionIndex)      SoAd_SetTimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap(Index, (SoAd_GetTimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubSoConIdxOfTimeoutListUdpAlive(Index, Value, partitionIndex)                         SoAd_SetSoConIdxOfTimeoutListUdpAlive(Index, (SoAd_GetSoConIdxOfTimeoutListUdpAlive(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTimeoutOfTimeoutListUdpAlive(Index, Value, partitionIndex)                          SoAd_SetTimeoutOfTimeoutListUdpAlive(Index, (SoAd_GetTimeoutOfTimeoutListUdpAlive(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap(Index, Value, partitionIndex)        SoAd_SetTimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap(Index, (SoAd_GetTimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTpRxBuffer(Index, Value, partitionIndex)                                            SoAd_SetTpRxBuffer(Index, (SoAd_GetTpRxBuffer(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTpTxBuffer(Index, Value, partitionIndex)                                            SoAd_SetTpTxBuffer(Index, (SoAd_GetTpTxBuffer(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTpTxBufferIdxOfTpTxBufferConfigDyn(Index, Value, partitionIndex)                    SoAd_SetTpTxBufferIdxOfTpTxBufferConfigDyn(Index, (SoAd_GetTpTxBufferIdxOfTpTxBufferConfigDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTriggerBuf(Index, Value, partitionIndex)                                            SoAd_SetTriggerBuf(Index, (SoAd_GetTriggerBuf(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubLengthOfTriggerBufConfigDyn(Index, Value, partitionIndex)                           SoAd_SetLengthOfTriggerBufConfigDyn(Index, (SoAd_GetLengthOfTriggerBufConfigDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubPduRouteIdxOfTriggerBufConfigDyn(Index, Value, partitionIndex)                      SoAd_SetPduRouteIdxOfTriggerBufConfigDyn(Index, (SoAd_GetPduRouteIdxOfTriggerBufConfigDyn(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubPduRouteDestIdxOfTxMgt(Index, Value, partitionIndex)                                SoAd_SetPduRouteDestIdxOfTxMgt(Index, (SoAd_GetPduRouteDestIdxOfTxMgt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTxBufPtrOfTxMgt(Index, Value, partitionIndex)                                       SoAd_SetTxBufPtrOfTxMgt(Index, (SoAd_GetTxBufPtrOfTxMgt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTxBytesLenOfTxMgt(Index, Value, partitionIndex)                                     SoAd_SetTxBytesLenOfTxMgt(Index, (SoAd_GetTxBytesLenOfTxMgt(((Index)), (partitionIndex)) - Value), partitionIndex)
#define SoAd_SubTxBytesPendingOfTxMgt(Index, Value, partitionIndex)                                 SoAd_SetTxBytesPendingOfTxMgt(Index, (SoAd_GetTxBytesPendingOfTxMgt(((Index)), (partitionIndex)) - Value), partitionIndex)
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  SoAdPCSizeOfTypes  SoAd SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for SoAd_SizeOfBestMatchSoConIdxList */
typedef uint8 SoAd_SizeOfBestMatchSoConIdxListType;

/**   \brief  value based type definition for SoAd_SizeOfDhcpEventCbk */
typedef uint8 SoAd_SizeOfDhcpEventCbkType;

/**   \brief  value based type definition for SoAd_SizeOfEventQueueFlag */
typedef uint8 SoAd_SizeOfEventQueueFlagType;

/**   \brief  value based type definition for SoAd_SizeOfEventQueueIdent */
typedef uint8 SoAd_SizeOfEventQueueIdentType;

/**   \brief  value based type definition for SoAd_SizeOfEventQueueIfTxRouteGrp */
typedef uint8 SoAd_SizeOfEventQueueIfTxRouteGrpType;

/**   \brief  value based type definition for SoAd_SizeOfEventQueueIfTxRouteGrpConfig */
typedef uint8 SoAd_SizeOfEventQueueIfTxRouteGrpConfigType;

/**   \brief  value based type definition for SoAd_SizeOfEventQueueIfUdpPduRoute */
typedef uint8 SoAd_SizeOfEventQueueIfUdpPduRouteType;

/**   \brief  value based type definition for SoAd_SizeOfEventQueueIfUdpPduRouteConfig */
typedef uint8 SoAd_SizeOfEventQueueIfUdpPduRouteConfigType;

/**   \brief  value based type definition for SoAd_SizeOfEventQueueMgmt */
typedef uint8 SoAd_SizeOfEventQueueMgmtType;

/**   \brief  value based type definition for SoAd_SizeOfEventQueueStateSoCon */
typedef uint8 SoAd_SizeOfEventQueueStateSoConType;

/**   \brief  value based type definition for SoAd_SizeOfEventQueueStateSoConConfig */
typedef uint8 SoAd_SizeOfEventQueueStateSoConConfigType;

/**   \brief  value based type definition for SoAd_SizeOfEventQueueTpRxSoCon */
typedef uint8 SoAd_SizeOfEventQueueTpRxSoConType;

/**   \brief  value based type definition for SoAd_SizeOfEventQueueTpRxSoConConfig */
typedef uint8 SoAd_SizeOfEventQueueTpRxSoConConfigType;

/**   \brief  value based type definition for SoAd_SizeOfEventQueueTpTxSoCon */
typedef uint8 SoAd_SizeOfEventQueueTpTxSoConType;

/**   \brief  value based type definition for SoAd_SizeOfEventQueueTpTxSoConConfig */
typedef uint8 SoAd_SizeOfEventQueueTpTxSoConConfigType;

/**   \brief  value based type definition for SoAd_SizeOfIfRxBuffer */
typedef uint8 SoAd_SizeOfIfRxBufferType;

/**   \brief  value based type definition for SoAd_SizeOfInstance */
typedef uint8 SoAd_SizeOfInstanceType;

/**   \brief  value based type definition for SoAd_SizeOfInstanceDyn */
typedef uint8 SoAd_SizeOfInstanceDynType;

/**   \brief  value based type definition for SoAd_SizeOfInstanceMap */
typedef uint8 SoAd_SizeOfInstanceMapType;

/**   \brief  value based type definition for SoAd_SizeOfIpFragBuf */
typedef uint8 SoAd_SizeOfIpFragBufType;

/**   \brief  value based type definition for SoAd_SizeOfIpFragBufConfig */
typedef uint8 SoAd_SizeOfIpFragBufConfigType;

/**   \brief  value based type definition for SoAd_SizeOfIpFragBufConfigDyn */
typedef uint8 SoAd_SizeOfIpFragBufConfigDynType;

/**   \brief  value based type definition for SoAd_SizeOfIpFragMgt */
typedef uint8 SoAd_SizeOfIpFragMgtType;

/**   \brief  value based type definition for SoAd_SizeOfLocalAddr */
typedef uint8 SoAd_SizeOfLocalAddrType;

/**   \brief  value based type definition for SoAd_SizeOfLocalAddrByTcpIpCtrlInd */
typedef uint8 SoAd_SizeOfLocalAddrByTcpIpCtrlIndType;

/**   \brief  value based type definition for SoAd_SizeOfLocalAddrDyn */
typedef uint8 SoAd_SizeOfLocalAddrDynType;

/**   \brief  value based type definition for SoAd_SizeOfLocalAddrIdMap */
typedef uint8 SoAd_SizeOfLocalAddrIdMapType;

/**   \brief  value based type definition for SoAd_SizeOfLocalIpAddrAssignmentChgCbk */
typedef uint8 SoAd_SizeOfLocalIpAddrAssignmentChgCbkType;

/**   \brief  value based type definition for SoAd_SizeOfLocalIpAddrAssignmentChgCbkInd */
typedef uint8 SoAd_SizeOfLocalIpAddrAssignmentChgCbkIndType;

/**   \brief  value based type definition for SoAd_SizeOfMetaDataRxBuffer */
typedef uint8 SoAd_SizeOfMetaDataRxBufferType;

/**   \brief  value based type definition for SoAd_SizeOfNPduUdpTx */
typedef uint8 SoAd_SizeOfNPduUdpTxType;

/**   \brief  value based type definition for SoAd_SizeOfNPduUdpTxBuffer */
typedef uint8 SoAd_SizeOfNPduUdpTxBufferType;

/**   \brief  value based type definition for SoAd_SizeOfNPduUdpTxDyn */
typedef uint8 SoAd_SizeOfNPduUdpTxDynType;

/**   \brief  value based type definition for SoAd_SizeOfNPduUdpTxQueue */
typedef uint8 SoAd_SizeOfNPduUdpTxQueueType;

/**   \brief  value based type definition for SoAd_SizeOfPartitionDyn */
typedef uint8 SoAd_SizeOfPartitionDynType;

/**   \brief  value based type definition for SoAd_SizeOfPartitionIdentifiers */
typedef uint8 SoAd_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for SoAd_SizeOfPduRoute */
typedef uint8 SoAd_SizeOfPduRouteType;

/**   \brief  value based type definition for SoAd_SizeOfPduRouteDest */
typedef uint8 SoAd_SizeOfPduRouteDestType;

/**   \brief  value based type definition for SoAd_SizeOfPduRouteDestBySoConInd */
typedef uint8 SoAd_SizeOfPduRouteDestBySoConIndType;

/**   \brief  value based type definition for SoAd_SizeOfPduRouteDestInd */
typedef uint8 SoAd_SizeOfPduRouteDestIndType;

/**   \brief  value based type definition for SoAd_SizeOfPduRouteDyn */
typedef uint8 SoAd_SizeOfPduRouteDynType;

/**   \brief  value based type definition for SoAd_SizeOfRemAddrIpV4 */
typedef uint8 SoAd_SizeOfRemAddrIpV4Type;

/**   \brief  value based type definition for SoAd_SizeOfRemAddrIpV6 */
typedef uint8 SoAd_SizeOfRemAddrIpV6Type;

/**   \brief  value based type definition for SoAd_SizeOfRemAddrRcv */
typedef uint8 SoAd_SizeOfRemAddrRcvType;

/**   \brief  value based type definition for SoAd_SizeOfRouteGrp */
typedef uint8 SoAd_SizeOfRouteGrpType;

/**   \brief  value based type definition for SoAd_SizeOfRouteGrpIdMap */
typedef uint8 SoAd_SizeOfRouteGrpIdMapType;

/**   \brief  value based type definition for SoAd_SizeOfRouteGrpSoCon */
typedef uint8 SoAd_SizeOfRouteGrpSoConType;

/**   \brief  value based type definition for SoAd_SizeOfRouteGrpSoConByPduRouteDestInd */
typedef uint8 SoAd_SizeOfRouteGrpSoConByPduRouteDestIndType;

/**   \brief  value based type definition for SoAd_SizeOfRouteGrpSoConBySocketRouteDestInd */
typedef uint8 SoAd_SizeOfRouteGrpSoConBySocketRouteDestIndType;

/**   \brief  value based type definition for SoAd_SizeOfRouteGrpSoConDyn */
typedef uint8 SoAd_SizeOfRouteGrpSoConDynType;

/**   \brief  value based type definition for SoAd_SizeOfRxBufStructMgt */
typedef uint8 SoAd_SizeOfRxBufStructMgtType;

/**   \brief  value based type definition for SoAd_SizeOfRxBufStructSeg */
typedef uint8 SoAd_SizeOfRxBufStructSegType;

/**   \brief  value based type definition for SoAd_SizeOfRxBufferConfig */
typedef uint8 SoAd_SizeOfRxBufferConfigType;

/**   \brief  value based type definition for SoAd_SizeOfRxBufferConfigDyn */
typedef uint8 SoAd_SizeOfRxBufferConfigDynType;

/**   \brief  value based type definition for SoAd_SizeOfRxMgt */
typedef uint8 SoAd_SizeOfRxMgtType;

/**   \brief  value based type definition for SoAd_SizeOfRxPduIdIdMap */
typedef uint8 SoAd_SizeOfRxPduIdIdMapType;

/**   \brief  value based type definition for SoAd_SizeOfShutdownFinishedCbk */
typedef uint8 SoAd_SizeOfShutdownFinishedCbkType;

/**   \brief  value based type definition for SoAd_SizeOfSoCon */
typedef uint8 SoAd_SizeOfSoConType;

/**   \brief  value based type definition for SoAd_SizeOfSoConDyn */
typedef uint8 SoAd_SizeOfSoConDynType;

/**   \brief  value based type definition for SoAd_SizeOfSoConGrp */
typedef uint8 SoAd_SizeOfSoConGrpType;

/**   \brief  value based type definition for SoAd_SizeOfSoConMap */
typedef uint8 SoAd_SizeOfSoConMapType;

/**   \brief  value based type definition for SoAd_SizeOfSoConModeChgCbk */
typedef uint8 SoAd_SizeOfSoConModeChgCbkType;

/**   \brief  value based type definition for SoAd_SizeOfSoConModeChgCbkInd */
typedef uint8 SoAd_SizeOfSoConModeChgCbkIndType;

/**   \brief  value based type definition for SoAd_SizeOfSocket */
typedef uint8 SoAd_SizeOfSocketType;

/**   \brief  value based type definition for SoAd_SizeOfSocketDyn */
typedef uint8 SoAd_SizeOfSocketDynType;

/**   \brief  value based type definition for SoAd_SizeOfSocketRoute */
typedef uint8 SoAd_SizeOfSocketRouteType;

/**   \brief  value based type definition for SoAd_SizeOfSocketRouteDest */
typedef uint8 SoAd_SizeOfSocketRouteDestType;

/**   \brief  value based type definition for SoAd_SizeOfSocketRouteInd */
typedef uint8 SoAd_SizeOfSocketRouteIndType;

/**   \brief  value based type definition for SoAd_SizeOfSocketTcp */
typedef uint8 SoAd_SizeOfSocketTcpType;

/**   \brief  value based type definition for SoAd_SizeOfSocketUdp */
typedef uint8 SoAd_SizeOfSocketUdpType;

/**   \brief  value based type definition for SoAd_SizeOfTcpIpCtrl */
typedef uint8 SoAd_SizeOfTcpIpCtrlType;

/**   \brief  value based type definition for SoAd_SizeOfTcpKeepAliveGloballyEnabled */
typedef uint8 SoAd_SizeOfTcpKeepAliveGloballyEnabledType;

/**   \brief  value based type definition for SoAd_SizeOfTcpTxQueue */
typedef uint8 SoAd_SizeOfTcpTxQueueType;

/**   \brief  value based type definition for SoAd_SizeOfTcpTxQueueData */
typedef uint8 SoAd_SizeOfTcpTxQueueDataType;

/**   \brief  value based type definition for SoAd_SizeOfTcpTxQueueMgt */
typedef uint8 SoAd_SizeOfTcpTxQueueMgtType;

/**   \brief  value based type definition for SoAd_SizeOfTimeoutListIdent */
typedef uint8 SoAd_SizeOfTimeoutListIdentType;

/**   \brief  value based type definition for SoAd_SizeOfTimeoutListMgmt */
typedef uint8 SoAd_SizeOfTimeoutListMgmtType;

/**   \brief  value based type definition for SoAd_SizeOfTimeoutListNPduUdpTx */
typedef uint8 SoAd_SizeOfTimeoutListNPduUdpTxType;

/**   \brief  value based type definition for SoAd_SizeOfTimeoutListNPduUdpTxConfig */
typedef uint8 SoAd_SizeOfTimeoutListNPduUdpTxConfigType;

/**   \brief  value based type definition for SoAd_SizeOfTimeoutListNPduUdpTxMap */
typedef uint8 SoAd_SizeOfTimeoutListNPduUdpTxMapType;

/**   \brief  value based type definition for SoAd_SizeOfTimeoutListTcpAutoConnectConfig */
typedef uint8 SoAd_SizeOfTimeoutListTcpAutoConnectConfigType;

/**   \brief  value based type definition for SoAd_SizeOfTimeoutListUdpAlive */
typedef uint8 SoAd_SizeOfTimeoutListUdpAliveType;

/**   \brief  value based type definition for SoAd_SizeOfTimeoutListUdpAliveConfig */
typedef uint8 SoAd_SizeOfTimeoutListUdpAliveConfigType;

/**   \brief  value based type definition for SoAd_SizeOfTimeoutListUdpAliveMap */
typedef uint8 SoAd_SizeOfTimeoutListUdpAliveMapType;

/**   \brief  value based type definition for SoAd_SizeOfTpRxBuffer */
typedef uint8 SoAd_SizeOfTpRxBufferType;

/**   \brief  value based type definition for SoAd_SizeOfTpTxBuffer */
typedef uint8 SoAd_SizeOfTpTxBufferType;

/**   \brief  value based type definition for SoAd_SizeOfTpTxBufferConfig */
typedef uint8 SoAd_SizeOfTpTxBufferConfigType;

/**   \brief  value based type definition for SoAd_SizeOfTpTxBufferConfigDyn */
typedef uint8 SoAd_SizeOfTpTxBufferConfigDynType;

/**   \brief  value based type definition for SoAd_SizeOfTriggerBuf */
typedef uint8 SoAd_SizeOfTriggerBufType;

/**   \brief  value based type definition for SoAd_SizeOfTriggerBufConfig */
typedef uint8 SoAd_SizeOfTriggerBufConfigType;

/**   \brief  value based type definition for SoAd_SizeOfTriggerBufConfigDyn */
typedef uint8 SoAd_SizeOfTriggerBufConfigDynType;

/**   \brief  value based type definition for SoAd_SizeOfTxMgt */
typedef uint8 SoAd_SizeOfTxMgtType;

/**   \brief  value based type definition for SoAd_SizeOfTxPduIdMap */
typedef uint8 SoAd_SizeOfTxPduIdMapType;

/**   \brief  value based type definition for SoAd_SizeOfUpperLayer */
typedef uint8 SoAd_SizeOfUpperLayerType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  SoAdPCIterableTypes  SoAd Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate SoAd_BestMatchSoConIdxList */
typedef uint8_least SoAd_BestMatchSoConIdxListIterType;

/**   \brief  type used to iterate SoAd_DhcpEventCbk */
typedef uint8_least SoAd_DhcpEventCbkIterType;

/**   \brief  type used to iterate SoAd_EventQueueFlag */
typedef uint8_least SoAd_EventQueueFlagIterType;

/**   \brief  type used to iterate SoAd_EventQueueIdent */
typedef uint8_least SoAd_EventQueueIdentIterType;

/**   \brief  type used to iterate SoAd_EventQueueIfTxRouteGrp */
typedef uint8_least SoAd_EventQueueIfTxRouteGrpIterType;

/**   \brief  type used to iterate SoAd_EventQueueIfTxRouteGrpConfig */
typedef uint8_least SoAd_EventQueueIfTxRouteGrpConfigIterType;

/**   \brief  type used to iterate SoAd_EventQueueIfUdpPduRoute */
typedef uint8_least SoAd_EventQueueIfUdpPduRouteIterType;

/**   \brief  type used to iterate SoAd_EventQueueIfUdpPduRouteConfig */
typedef uint8_least SoAd_EventQueueIfUdpPduRouteConfigIterType;

/**   \brief  type used to iterate SoAd_EventQueueMgmt */
typedef uint8_least SoAd_EventQueueMgmtIterType;

/**   \brief  type used to iterate SoAd_EventQueueStateSoCon */
typedef uint8_least SoAd_EventQueueStateSoConIterType;

/**   \brief  type used to iterate SoAd_EventQueueStateSoConConfig */
typedef uint8_least SoAd_EventQueueStateSoConConfigIterType;

/**   \brief  type used to iterate SoAd_EventQueueTpRxSoCon */
typedef uint8_least SoAd_EventQueueTpRxSoConIterType;

/**   \brief  type used to iterate SoAd_EventQueueTpRxSoConConfig */
typedef uint8_least SoAd_EventQueueTpRxSoConConfigIterType;

/**   \brief  type used to iterate SoAd_EventQueueTpTxSoCon */
typedef uint8_least SoAd_EventQueueTpTxSoConIterType;

/**   \brief  type used to iterate SoAd_EventQueueTpTxSoConConfig */
typedef uint8_least SoAd_EventQueueTpTxSoConConfigIterType;

/**   \brief  type used to iterate SoAd_IfRxBuffer */
typedef uint8_least SoAd_IfRxBufferIterType;

/**   \brief  type used to iterate SoAd_Instance */
typedef uint8_least SoAd_InstanceIterType;

/**   \brief  type used to iterate SoAd_InstanceMap */
typedef uint8_least SoAd_InstanceMapIterType;

/**   \brief  type used to iterate SoAd_IpFragBuf */
typedef uint8_least SoAd_IpFragBufIterType;

/**   \brief  type used to iterate SoAd_IpFragBufConfig */
typedef uint8_least SoAd_IpFragBufConfigIterType;

/**   \brief  type used to iterate SoAd_IpFragMgt */
typedef uint8_least SoAd_IpFragMgtIterType;

/**   \brief  type used to iterate SoAd_LocalAddr */
typedef uint8_least SoAd_LocalAddrIterType;

/**   \brief  type used to iterate SoAd_LocalAddrByTcpIpCtrlInd */
typedef uint8_least SoAd_LocalAddrByTcpIpCtrlIndIterType;

/**   \brief  type used to iterate SoAd_LocalAddrIdMap */
typedef uint8_least SoAd_LocalAddrIdMapIterType;

/**   \brief  type used to iterate SoAd_LocalIpAddrAssignmentChgCbk */
typedef uint8_least SoAd_LocalIpAddrAssignmentChgCbkIterType;

/**   \brief  type used to iterate SoAd_LocalIpAddrAssignmentChgCbkInd */
typedef uint8_least SoAd_LocalIpAddrAssignmentChgCbkIndIterType;

/**   \brief  type used to iterate SoAd_MetaDataRxBuffer */
typedef uint8_least SoAd_MetaDataRxBufferIterType;

/**   \brief  type used to iterate SoAd_NPduUdpTx */
typedef uint8_least SoAd_NPduUdpTxIterType;

/**   \brief  type used to iterate SoAd_NPduUdpTxBuffer */
typedef uint8_least SoAd_NPduUdpTxBufferIterType;

/**   \brief  type used to iterate SoAd_NPduUdpTxQueue */
typedef uint8_least SoAd_NPduUdpTxQueueIterType;

/**   \brief  type used to iterate SoAd_PartitionDyn */
typedef uint8_least SoAd_PartitionDynIterType;

/**   \brief  type used to iterate SoAd_PartitionIdentifiers */
typedef uint8_least SoAd_PartitionIdentifiersIterType;

/**   \brief  type used to iterate SoAd_PduRoute */
typedef uint8_least SoAd_PduRouteIterType;

/**   \brief  type used to iterate SoAd_PduRouteDest */
typedef uint8_least SoAd_PduRouteDestIterType;

/**   \brief  type used to iterate SoAd_PduRouteDestBySoConInd */
typedef uint8_least SoAd_PduRouteDestBySoConIndIterType;

/**   \brief  type used to iterate SoAd_PduRouteDestInd */
typedef uint8_least SoAd_PduRouteDestIndIterType;

/**   \brief  type used to iterate SoAd_RemAddrIpV4 */
typedef uint8_least SoAd_RemAddrIpV4IterType;

/**   \brief  type used to iterate SoAd_RemAddrIpV6 */
typedef uint8_least SoAd_RemAddrIpV6IterType;

/**   \brief  type used to iterate SoAd_RemAddrRcv */
typedef uint8_least SoAd_RemAddrRcvIterType;

/**   \brief  type used to iterate SoAd_RouteGrp */
typedef uint8_least SoAd_RouteGrpIterType;

/**   \brief  type used to iterate SoAd_RouteGrpIdMap */
typedef uint8_least SoAd_RouteGrpIdMapIterType;

/**   \brief  type used to iterate SoAd_RouteGrpSoCon */
typedef uint8_least SoAd_RouteGrpSoConIterType;

/**   \brief  type used to iterate SoAd_RouteGrpSoConByPduRouteDestInd */
typedef uint8_least SoAd_RouteGrpSoConByPduRouteDestIndIterType;

/**   \brief  type used to iterate SoAd_RouteGrpSoConBySocketRouteDestInd */
typedef uint8_least SoAd_RouteGrpSoConBySocketRouteDestIndIterType;

/**   \brief  type used to iterate SoAd_RxBufStructMgt */
typedef uint8_least SoAd_RxBufStructMgtIterType;

/**   \brief  type used to iterate SoAd_RxBufStructSeg */
typedef uint8_least SoAd_RxBufStructSegIterType;

/**   \brief  type used to iterate SoAd_RxBufferConfig */
typedef uint8_least SoAd_RxBufferConfigIterType;

/**   \brief  type used to iterate SoAd_RxMgt */
typedef uint8_least SoAd_RxMgtIterType;

/**   \brief  type used to iterate SoAd_RxPduIdIdMap */
typedef uint8_least SoAd_RxPduIdIdMapIterType;

/**   \brief  type used to iterate SoAd_ShutdownFinishedCbk */
typedef uint8_least SoAd_ShutdownFinishedCbkIterType;

/**   \brief  type used to iterate SoAd_SoCon */
typedef uint8_least SoAd_SoConIterType;

/**   \brief  type used to iterate SoAd_SoConGrp */
typedef uint8_least SoAd_SoConGrpIterType;

/**   \brief  type used to iterate SoAd_SoConMap */
typedef uint8_least SoAd_SoConMapIterType;

/**   \brief  type used to iterate SoAd_SoConModeChgCbk */
typedef uint8_least SoAd_SoConModeChgCbkIterType;

/**   \brief  type used to iterate SoAd_SoConModeChgCbkInd */
typedef uint8_least SoAd_SoConModeChgCbkIndIterType;

/**   \brief  type used to iterate SoAd_Socket */
typedef uint8_least SoAd_SocketIterType;

/**   \brief  type used to iterate SoAd_SocketRoute */
typedef uint8_least SoAd_SocketRouteIterType;

/**   \brief  type used to iterate SoAd_SocketRouteDest */
typedef uint8_least SoAd_SocketRouteDestIterType;

/**   \brief  type used to iterate SoAd_SocketRouteInd */
typedef uint8_least SoAd_SocketRouteIndIterType;

/**   \brief  type used to iterate SoAd_SocketTcp */
typedef uint8_least SoAd_SocketTcpIterType;

/**   \brief  type used to iterate SoAd_SocketUdp */
typedef uint8_least SoAd_SocketUdpIterType;

/**   \brief  type used to iterate SoAd_TcpIpCtrl */
typedef uint8_least SoAd_TcpIpCtrlIterType;

/**   \brief  type used to iterate SoAd_TcpKeepAliveGloballyEnabled */
typedef uint8_least SoAd_TcpKeepAliveGloballyEnabledIterType;

/**   \brief  type used to iterate SoAd_TcpTxQueue */
typedef uint8_least SoAd_TcpTxQueueIterType;

/**   \brief  type used to iterate SoAd_TcpTxQueueData */
typedef uint8_least SoAd_TcpTxQueueDataIterType;

/**   \brief  type used to iterate SoAd_TimeoutListIdent */
typedef uint8_least SoAd_TimeoutListIdentIterType;

/**   \brief  type used to iterate SoAd_TimeoutListMgmt */
typedef uint8_least SoAd_TimeoutListMgmtIterType;

/**   \brief  type used to iterate SoAd_TimeoutListNPduUdpTx */
typedef uint8_least SoAd_TimeoutListNPduUdpTxIterType;

/**   \brief  type used to iterate SoAd_TimeoutListNPduUdpTxConfig */
typedef uint8_least SoAd_TimeoutListNPduUdpTxConfigIterType;

/**   \brief  type used to iterate SoAd_TimeoutListNPduUdpTxMap */
typedef uint8_least SoAd_TimeoutListNPduUdpTxMapIterType;

/**   \brief  type used to iterate SoAd_TimeoutListTcpAutoConnectConfig */
typedef uint8_least SoAd_TimeoutListTcpAutoConnectConfigIterType;

/**   \brief  type used to iterate SoAd_TimeoutListUdpAlive */
typedef uint8_least SoAd_TimeoutListUdpAliveIterType;

/**   \brief  type used to iterate SoAd_TimeoutListUdpAliveConfig */
typedef uint8_least SoAd_TimeoutListUdpAliveConfigIterType;

/**   \brief  type used to iterate SoAd_TimeoutListUdpAliveMap */
typedef uint8_least SoAd_TimeoutListUdpAliveMapIterType;

/**   \brief  type used to iterate SoAd_TpRxBuffer */
typedef uint8_least SoAd_TpRxBufferIterType;

/**   \brief  type used to iterate SoAd_TpTxBuffer */
typedef uint8_least SoAd_TpTxBufferIterType;

/**   \brief  type used to iterate SoAd_TpTxBufferConfig */
typedef uint8_least SoAd_TpTxBufferConfigIterType;

/**   \brief  type used to iterate SoAd_TriggerBuf */
typedef uint8_least SoAd_TriggerBufIterType;

/**   \brief  type used to iterate SoAd_TriggerBufConfig */
typedef uint8_least SoAd_TriggerBufConfigIterType;

/**   \brief  type used to iterate SoAd_TxMgt */
typedef uint8_least SoAd_TxMgtIterType;

/**   \brief  type used to iterate SoAd_TxPduIdMap */
typedef uint8_least SoAd_TxPduIdMapIterType;

/**   \brief  type used to iterate SoAd_UpperLayer */
typedef uint8_least SoAd_UpperLayerIterType;

/**   \brief  type used to iterate SoAd_PCPartitionConfig */
typedef uint8_least SoAd_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCIterableTypesWithSizeRelations  SoAd Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate SoAd_InstanceDyn */
typedef SoAd_InstanceIterType SoAd_InstanceDynIterType;

/**   \brief  type used to iterate SoAd_IpFragBufConfigDyn */
typedef SoAd_IpFragBufConfigIterType SoAd_IpFragBufConfigDynIterType;

/**   \brief  type used to iterate SoAd_LocalAddrDyn */
typedef SoAd_LocalAddrIterType SoAd_LocalAddrDynIterType;

/**   \brief  type used to iterate SoAd_NPduUdpTxDyn */
typedef SoAd_NPduUdpTxIterType SoAd_NPduUdpTxDynIterType;

/**   \brief  type used to iterate SoAd_PduRouteDyn */
typedef SoAd_PduRouteIterType SoAd_PduRouteDynIterType;

/**   \brief  type used to iterate SoAd_RouteGrpSoConDyn */
typedef SoAd_RouteGrpSoConIterType SoAd_RouteGrpSoConDynIterType;

/**   \brief  type used to iterate SoAd_RxBufferConfigDyn */
typedef SoAd_RxBufferConfigIterType SoAd_RxBufferConfigDynIterType;

/**   \brief  type used to iterate SoAd_SoConDyn */
typedef SoAd_SoConIterType SoAd_SoConDynIterType;

/**   \brief  type used to iterate SoAd_SocketDyn */
typedef SoAd_SocketIterType SoAd_SocketDynIterType;

/**   \brief  type used to iterate SoAd_TcpTxQueueMgt */
typedef SoAd_TcpTxQueueIterType SoAd_TcpTxQueueMgtIterType;

/**   \brief  type used to iterate SoAd_TpTxBufferConfigDyn */
typedef SoAd_TpTxBufferConfigIterType SoAd_TpTxBufferConfigDynIterType;

/**   \brief  type used to iterate SoAd_TriggerBufConfigDyn */
typedef SoAd_TriggerBufConfigIterType SoAd_TriggerBufConfigDynIterType;

/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCValueTypes  SoAd Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for SoAd_SoConIdxOfBestMatchSoConIdxList */
typedef uint8 SoAd_SoConIdxOfBestMatchSoConIdxListType;

/**   \brief  value based type definition for SoAd_EventQueueFlagEndIdxOfEventQueueIdent */
typedef uint8 SoAd_EventQueueFlagEndIdxOfEventQueueIdentType;

/**   \brief  value based type definition for SoAd_EventQueueFlagStartIdxOfEventQueueIdent */
typedef uint8 SoAd_EventQueueFlagStartIdxOfEventQueueIdentType;

/**   \brief  value based type definition for SoAd_EventQueueIfTxRouteGrpConfigIdxOfEventQueueIdent */
typedef uint8 SoAd_EventQueueIfTxRouteGrpConfigIdxOfEventQueueIdentType;

/**   \brief  value based type definition for SoAd_EventQueueIfTxRouteGrpConfigUsedOfEventQueueIdent */
typedef boolean SoAd_EventQueueIfTxRouteGrpConfigUsedOfEventQueueIdentType;

/**   \brief  value based type definition for SoAd_EventQueueIfUdpPduRouteConfigIdxOfEventQueueIdent */
typedef uint8 SoAd_EventQueueIfUdpPduRouteConfigIdxOfEventQueueIdentType;

/**   \brief  value based type definition for SoAd_EventQueueIfUdpPduRouteConfigUsedOfEventQueueIdent */
typedef boolean SoAd_EventQueueIfUdpPduRouteConfigUsedOfEventQueueIdentType;

/**   \brief  value based type definition for SoAd_EventQueueStateSoConConfigIdxOfEventQueueIdent */
typedef uint8 SoAd_EventQueueStateSoConConfigIdxOfEventQueueIdentType;

/**   \brief  value based type definition for SoAd_EventQueueTpRxSoConConfigIdxOfEventQueueIdent */
typedef uint8 SoAd_EventQueueTpRxSoConConfigIdxOfEventQueueIdentType;

/**   \brief  value based type definition for SoAd_EventQueueTpRxSoConConfigUsedOfEventQueueIdent */
typedef boolean SoAd_EventQueueTpRxSoConConfigUsedOfEventQueueIdentType;

/**   \brief  value based type definition for SoAd_EventQueueTpTxSoConConfigIdxOfEventQueueIdent */
typedef uint8 SoAd_EventQueueTpTxSoConConfigIdxOfEventQueueIdentType;

/**   \brief  value based type definition for SoAd_EventQueueTpTxSoConConfigUsedOfEventQueueIdent */
typedef boolean SoAd_EventQueueTpTxSoConConfigUsedOfEventQueueIdentType;

/**   \brief  value based type definition for SoAd_RouteGrpIdxOfEventQueueIfTxRouteGrp */
typedef uint8 SoAd_RouteGrpIdxOfEventQueueIfTxRouteGrpType;

/**   \brief  value based type definition for SoAd_EventQueueIfTxRouteGrpEndIdxOfEventQueueIfTxRouteGrpConfig */
typedef uint8 SoAd_EventQueueIfTxRouteGrpEndIdxOfEventQueueIfTxRouteGrpConfigType;

/**   \brief  value based type definition for SoAd_EventQueueIfTxRouteGrpStartIdxOfEventQueueIfTxRouteGrpConfig */
typedef uint8 SoAd_EventQueueIfTxRouteGrpStartIdxOfEventQueueIfTxRouteGrpConfigType;

/**   \brief  value based type definition for SoAd_EventQueueMgmtIdxOfEventQueueIfTxRouteGrpConfig */
typedef uint8 SoAd_EventQueueMgmtIdxOfEventQueueIfTxRouteGrpConfigType;

/**   \brief  value based type definition for SoAd_FlagOffsetOfEventQueueIfTxRouteGrpConfig */
typedef uint8 SoAd_FlagOffsetOfEventQueueIfTxRouteGrpConfigType;

/**   \brief  value based type definition for SoAd_LimitOfEventQueueIfTxRouteGrpConfig */
typedef uint8 SoAd_LimitOfEventQueueIfTxRouteGrpConfigType;

/**   \brief  value based type definition for SoAd_PduRouteIdxOfEventQueueIfUdpPduRoute */
typedef uint8 SoAd_PduRouteIdxOfEventQueueIfUdpPduRouteType;

/**   \brief  value based type definition for SoAd_EventQueueIfUdpPduRouteEndIdxOfEventQueueIfUdpPduRouteConfig */
typedef uint8 SoAd_EventQueueIfUdpPduRouteEndIdxOfEventQueueIfUdpPduRouteConfigType;

/**   \brief  value based type definition for SoAd_EventQueueIfUdpPduRouteStartIdxOfEventQueueIfUdpPduRouteConfig */
typedef uint8 SoAd_EventQueueIfUdpPduRouteStartIdxOfEventQueueIfUdpPduRouteConfigType;

/**   \brief  value based type definition for SoAd_EventQueueMgmtIdxOfEventQueueIfUdpPduRouteConfig */
typedef uint8 SoAd_EventQueueMgmtIdxOfEventQueueIfUdpPduRouteConfigType;

/**   \brief  value based type definition for SoAd_FlagOffsetOfEventQueueIfUdpPduRouteConfig */
typedef uint8 SoAd_FlagOffsetOfEventQueueIfUdpPduRouteConfigType;

/**   \brief  value based type definition for SoAd_LimitOfEventQueueIfUdpPduRouteConfig */
typedef uint8 SoAd_LimitOfEventQueueIfUdpPduRouteConfigType;

/**   \brief  value based type definition for SoAd_IdxOfEventQueueMgmt */
typedef uint16 SoAd_IdxOfEventQueueMgmtType;

/**   \brief  value based type definition for SoAd_LvlOfEventQueueMgmt */
typedef uint16 SoAd_LvlOfEventQueueMgmtType;

/**   \brief  value based type definition for SoAd_SoConIdxOfEventQueueStateSoCon */
typedef uint8 SoAd_SoConIdxOfEventQueueStateSoConType;

/**   \brief  value based type definition for SoAd_EventQueueMgmtIdxOfEventQueueStateSoConConfig */
typedef uint8 SoAd_EventQueueMgmtIdxOfEventQueueStateSoConConfigType;

/**   \brief  value based type definition for SoAd_EventQueueStateSoConEndIdxOfEventQueueStateSoConConfig */
typedef uint8 SoAd_EventQueueStateSoConEndIdxOfEventQueueStateSoConConfigType;

/**   \brief  value based type definition for SoAd_EventQueueStateSoConStartIdxOfEventQueueStateSoConConfig */
typedef uint8 SoAd_EventQueueStateSoConStartIdxOfEventQueueStateSoConConfigType;

/**   \brief  value based type definition for SoAd_FlagOffsetOfEventQueueStateSoConConfig */
typedef uint8 SoAd_FlagOffsetOfEventQueueStateSoConConfigType;

/**   \brief  value based type definition for SoAd_LimitOfEventQueueStateSoConConfig */
typedef uint8 SoAd_LimitOfEventQueueStateSoConConfigType;

/**   \brief  value based type definition for SoAd_SoConIdxOfEventQueueTpRxSoCon */
typedef uint8 SoAd_SoConIdxOfEventQueueTpRxSoConType;

/**   \brief  value based type definition for SoAd_EventQueueMgmtIdxOfEventQueueTpRxSoConConfig */
typedef uint8 SoAd_EventQueueMgmtIdxOfEventQueueTpRxSoConConfigType;

/**   \brief  value based type definition for SoAd_EventQueueTpRxSoConEndIdxOfEventQueueTpRxSoConConfig */
typedef uint8 SoAd_EventQueueTpRxSoConEndIdxOfEventQueueTpRxSoConConfigType;

/**   \brief  value based type definition for SoAd_EventQueueTpRxSoConStartIdxOfEventQueueTpRxSoConConfig */
typedef uint8 SoAd_EventQueueTpRxSoConStartIdxOfEventQueueTpRxSoConConfigType;

/**   \brief  value based type definition for SoAd_FlagOffsetOfEventQueueTpRxSoConConfig */
typedef uint8 SoAd_FlagOffsetOfEventQueueTpRxSoConConfigType;

/**   \brief  value based type definition for SoAd_LimitOfEventQueueTpRxSoConConfig */
typedef uint8 SoAd_LimitOfEventQueueTpRxSoConConfigType;

/**   \brief  value based type definition for SoAd_SoConIdxOfEventQueueTpTxSoCon */
typedef uint8 SoAd_SoConIdxOfEventQueueTpTxSoConType;

/**   \brief  value based type definition for SoAd_EventQueueMgmtIdxOfEventQueueTpTxSoConConfig */
typedef uint8 SoAd_EventQueueMgmtIdxOfEventQueueTpTxSoConConfigType;

/**   \brief  value based type definition for SoAd_EventQueueTpTxSoConEndIdxOfEventQueueTpTxSoConConfig */
typedef uint8 SoAd_EventQueueTpTxSoConEndIdxOfEventQueueTpTxSoConConfigType;

/**   \brief  value based type definition for SoAd_EventQueueTpTxSoConStartIdxOfEventQueueTpTxSoConConfig */
typedef uint8 SoAd_EventQueueTpTxSoConStartIdxOfEventQueueTpTxSoConConfigType;

/**   \brief  value based type definition for SoAd_FlagOffsetOfEventQueueTpTxSoConConfig */
typedef uint8 SoAd_FlagOffsetOfEventQueueTpTxSoConConfigType;

/**   \brief  value based type definition for SoAd_LimitOfEventQueueTpTxSoConConfig */
typedef uint8 SoAd_LimitOfEventQueueTpTxSoConConfigType;

/**   \brief  value based type definition for SoAd_IfRxBuffer */
typedef uint8 SoAd_IfRxBufferType;

/**   \brief  value based type definition for SoAd_BestMatchSoConIdxListEndIdxOfInstance */
typedef uint8 SoAd_BestMatchSoConIdxListEndIdxOfInstanceType;

/**   \brief  value based type definition for SoAd_BestMatchSoConIdxListStartIdxOfInstance */
typedef uint8 SoAd_BestMatchSoConIdxListStartIdxOfInstanceType;

/**   \brief  value based type definition for SoAd_EventQueueIdentIdxOfInstance */
typedef uint8 SoAd_EventQueueIdentIdxOfInstanceType;

/**   \brief  value based type definition for SoAd_IpFragBufConfigEndIdxOfInstance */
typedef uint8 SoAd_IpFragBufConfigEndIdxOfInstanceType;

/**   \brief  value based type definition for SoAd_IpFragBufConfigStartIdxOfInstance */
typedef uint8 SoAd_IpFragBufConfigStartIdxOfInstanceType;

/**   \brief  value based type definition for SoAd_IpFragBufConfigUsedOfInstance */
typedef boolean SoAd_IpFragBufConfigUsedOfInstanceType;

/**   \brief  value based type definition for SoAd_TimeoutListIdentIdxOfInstance */
typedef uint8 SoAd_TimeoutListIdentIdxOfInstanceType;

/**   \brief  value based type definition for SoAd_TriggerBufConfigEndIdxOfInstance */
typedef uint8 SoAd_TriggerBufConfigEndIdxOfInstanceType;

/**   \brief  value based type definition for SoAd_TriggerBufConfigStartIdxOfInstance */
typedef uint8 SoAd_TriggerBufConfigStartIdxOfInstanceType;

/**   \brief  value based type definition for SoAd_TriggerBufConfigUsedOfInstance */
typedef boolean SoAd_TriggerBufConfigUsedOfInstanceType;

/**   \brief  value based type definition for SoAd_CounterOfInstanceDyn */
typedef uint32 SoAd_CounterOfInstanceDynType;

/**   \brief  value based type definition for SoAd_PartitionSpecificInstanceIdxOfInstanceMap */
typedef uint8 SoAd_PartitionSpecificInstanceIdxOfInstanceMapType;

/**   \brief  value based type definition for SoAd_PartitionSpecificInstancePartitionIdxOfInstanceMap */
typedef uint8 SoAd_PartitionSpecificInstancePartitionIdxOfInstanceMapType;

/**   \brief  value based type definition for SoAd_IpFragBuf */
typedef uint8 SoAd_IpFragBufType;

/**   \brief  value based type definition for SoAd_IpFragBufEndIdxOfIpFragBufConfig */
typedef uint8 SoAd_IpFragBufEndIdxOfIpFragBufConfigType;

/**   \brief  value based type definition for SoAd_IpFragBufStartIdxOfIpFragBufConfig */
typedef uint8 SoAd_IpFragBufStartIdxOfIpFragBufConfigType;

/**   \brief  value based type definition for SoAd_LengthOfIpFragBufConfigDyn */
typedef uint16 SoAd_LengthOfIpFragBufConfigDynType;

/**   \brief  value based type definition for SoAd_IpFragBufConfigIdxOfIpFragMgt */
typedef uint8 SoAd_IpFragBufConfigIdxOfIpFragMgtType;

/**   \brief  value based type definition for SoAd_SoConGrpEndIdxOfLocalAddr */
typedef uint8 SoAd_SoConGrpEndIdxOfLocalAddrType;

/**   \brief  value based type definition for SoAd_SoConGrpStartIdxOfLocalAddr */
typedef uint8 SoAd_SoConGrpStartIdxOfLocalAddrType;

/**   \brief  value based type definition for SoAd_SoConGrpUsedOfLocalAddr */
typedef boolean SoAd_SoConGrpUsedOfLocalAddrType;

/**   \brief  value based type definition for SoAd_TcpIpCtrlIdxOfLocalAddr */
typedef uint8 SoAd_TcpIpCtrlIdxOfLocalAddrType;

/**   \brief  value based type definition for SoAd_LocalAddrByTcpIpCtrlInd */
typedef uint8 SoAd_LocalAddrByTcpIpCtrlIndType;

/**   \brief  value based type definition for SoAd_InvalidHndOfLocalAddrIdMap */
typedef boolean SoAd_InvalidHndOfLocalAddrIdMapType;

/**   \brief  value based type definition for SoAd_PartitionSpecificLocalAddrIdxOfLocalAddrIdMap */
typedef uint8 SoAd_PartitionSpecificLocalAddrIdxOfLocalAddrIdMapType;

/**   \brief  value based type definition for SoAd_PartitionSpecificLocalAddrPartitionIdxOfLocalAddrIdMap */
typedef uint8 SoAd_PartitionSpecificLocalAddrPartitionIdxOfLocalAddrIdMapType;

/**   \brief  value based type definition for SoAd_PartitionSpecificLocalAddrUsedOfLocalAddrIdMap */
typedef boolean SoAd_PartitionSpecificLocalAddrUsedOfLocalAddrIdMapType;

/**   \brief  value based type definition for SoAd_LocalIpAddrAssignmentChgCbkInd */
typedef uint8 SoAd_LocalIpAddrAssignmentChgCbkIndType;

/**   \brief  value based type definition for SoAd_MaxIfRouteGrpTransmitPduSize */
typedef uint8 SoAd_MaxIfRouteGrpTransmitPduSizeType;

/**   \brief  value based type definition for SoAd_MetaDataRxBuffer */
typedef uint8 SoAd_MetaDataRxBufferType;

/**   \brief  value based type definition for SoAd_NPduUdpTxBufferEndIdxOfNPduUdpTx */
typedef uint8 SoAd_NPduUdpTxBufferEndIdxOfNPduUdpTxType;

/**   \brief  value based type definition for SoAd_NPduUdpTxBufferStartIdxOfNPduUdpTx */
typedef uint8 SoAd_NPduUdpTxBufferStartIdxOfNPduUdpTxType;

/**   \brief  value based type definition for SoAd_NPduUdpTxBufferUsedOfNPduUdpTx */
typedef boolean SoAd_NPduUdpTxBufferUsedOfNPduUdpTxType;

/**   \brief  value based type definition for SoAd_NPduUdpTxQueueEndIdxOfNPduUdpTx */
typedef uint8 SoAd_NPduUdpTxQueueEndIdxOfNPduUdpTxType;

/**   \brief  value based type definition for SoAd_NPduUdpTxQueueStartIdxOfNPduUdpTx */
typedef uint8 SoAd_NPduUdpTxQueueStartIdxOfNPduUdpTxType;

/**   \brief  value based type definition for SoAd_NPduUdpTxQueueUsedOfNPduUdpTx */
typedef boolean SoAd_NPduUdpTxQueueUsedOfNPduUdpTxType;

/**   \brief  value based type definition for SoAd_SoConIdxOfNPduUdpTx */
typedef uint8 SoAd_SoConIdxOfNPduUdpTxType;

/**   \brief  value based type definition for SoAd_NPduUdpTxBuffer */
typedef uint8 SoAd_NPduUdpTxBufferType;

/**   \brief  value based type definition for SoAd_BufLenOfNPduUdpTxDyn */
typedef uint16 SoAd_BufLenOfNPduUdpTxDynType;

/**   \brief  value based type definition for SoAd_LvlOfNPduUdpTxDyn */
typedef uint8 SoAd_LvlOfNPduUdpTxDynType;

/**   \brief  value based type definition for SoAd_RetryCntOfNPduUdpTxDyn */
typedef uint16 SoAd_RetryCntOfNPduUdpTxDynType;

/**   \brief  value based type definition for SoAd_TotalLenOfNPduUdpTxDyn */
typedef uint32 SoAd_TotalLenOfNPduUdpTxDynType;

/**   \brief  value based type definition for SoAd_CopiedOfNPduUdpTxQueue */
typedef boolean SoAd_CopiedOfNPduUdpTxQueueType;

/**   \brief  value based type definition for SoAd_LenOfNPduUdpTxQueue */
typedef PduLengthType SoAd_LenOfNPduUdpTxQueueType;

/**   \brief  value based type definition for SoAd_NPduUdpTxBufferIdxOfNPduUdpTxQueue */
typedef uint8 SoAd_NPduUdpTxBufferIdxOfNPduUdpTxQueueType;

/**   \brief  value based type definition for SoAd_PduRouteDestIdxOfNPduUdpTxQueue */
typedef uint8 SoAd_PduRouteDestIdxOfNPduUdpTxQueueType;

/**   \brief  value based type definition for SoAd_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 SoAd_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for SoAd_PartitionSNVOfPartitionIdentifiers */
typedef uint32 SoAd_PartitionSNVOfPartitionIdentifiersType;

/**   \brief  value based type definition for SoAd_AllPduRouteDestWithPduHdrOfPduRoute */
typedef boolean SoAd_AllPduRouteDestWithPduHdrOfPduRouteType;

/**   \brief  value based type definition for SoAd_IfOptimisticTransmitOfPduRoute */
typedef boolean SoAd_IfOptimisticTransmitOfPduRouteType;

/**   \brief  value based type definition for SoAd_MetaDataTxEnabledOfPduRoute */
typedef boolean SoAd_MetaDataTxEnabledOfPduRouteType;

/**   \brief  value based type definition for SoAd_PduRouteDestEndIdxOfPduRoute */
typedef uint8 SoAd_PduRouteDestEndIdxOfPduRouteType;

/**   \brief  value based type definition for SoAd_PduRouteDestStartIdxOfPduRoute */
typedef uint8 SoAd_PduRouteDestStartIdxOfPduRouteType;

/**   \brief  value based type definition for SoAd_TxConfEnabledOfPduRoute */
typedef boolean SoAd_TxConfEnabledOfPduRouteType;

/**   \brief  value based type definition for SoAd_TxConfPduIdOfPduRoute */
typedef PduIdType SoAd_TxConfPduIdOfPduRouteType;

/**   \brief  value based type definition for SoAd_TxOptimizedOfPduRoute */
typedef boolean SoAd_TxOptimizedOfPduRouteType;

/**   \brief  value based type definition for SoAd_UpperLayerIdxOfPduRoute */
typedef uint8 SoAd_UpperLayerIdxOfPduRouteType;

/**   \brief  value based type definition for SoAd_PduRouteIdxOfPduRouteDest */
typedef uint8 SoAd_PduRouteIdxOfPduRouteDestType;

/**   \brief  value based type definition for SoAd_RouteGrpSoConByPduRouteDestIndEndIdxOfPduRouteDest */
typedef uint8 SoAd_RouteGrpSoConByPduRouteDestIndEndIdxOfPduRouteDestType;

/**   \brief  value based type definition for SoAd_RouteGrpSoConByPduRouteDestIndStartIdxOfPduRouteDest */
typedef uint8 SoAd_RouteGrpSoConByPduRouteDestIndStartIdxOfPduRouteDestType;

/**   \brief  value based type definition for SoAd_RouteGrpSoConByPduRouteDestIndUsedOfPduRouteDest */
typedef boolean SoAd_RouteGrpSoConByPduRouteDestIndUsedOfPduRouteDestType;

/**   \brief  value based type definition for SoAd_SoConIdxOfPduRouteDest */
typedef uint8 SoAd_SoConIdxOfPduRouteDestType;

/**   \brief  value based type definition for SoAd_TxPduHdrIdOfPduRouteDest */
typedef uint32 SoAd_TxPduHdrIdOfPduRouteDestType;

/**   \brief  value based type definition for SoAd_UdpTriggerTimeoutOfPduRouteDest */
typedef uint8 SoAd_UdpTriggerTimeoutOfPduRouteDestType;

/**   \brief  value based type definition for SoAd_PduRouteDestBySoConInd */
typedef uint8 SoAd_PduRouteDestBySoConIndType;

/**   \brief  value based type definition for SoAd_PduRouteDestInd */
typedef uint8 SoAd_PduRouteDestIndType;

/**   \brief  value based type definition for SoAd_PendingTxConfMainOfPduRouteDyn */
typedef boolean SoAd_PendingTxConfMainOfPduRouteDynType;

/**   \brief  value based type definition for SoAd_EnabledAtInitOfRouteGrp */
typedef boolean SoAd_EnabledAtInitOfRouteGrpType;

/**   \brief  value based type definition for SoAd_MultiInstanceOnGrpOfRouteGrp */
typedef boolean SoAd_MultiInstanceOnGrpOfRouteGrpType;

/**   \brief  value based type definition for SoAd_PduRouteDestIndEndIdxOfRouteGrp */
typedef uint8 SoAd_PduRouteDestIndEndIdxOfRouteGrpType;

/**   \brief  value based type definition for SoAd_PduRouteDestIndStartIdxOfRouteGrp */
typedef uint8 SoAd_PduRouteDestIndStartIdxOfRouteGrpType;

/**   \brief  value based type definition for SoAd_PduRouteDestIndUsedOfRouteGrp */
typedef boolean SoAd_PduRouteDestIndUsedOfRouteGrpType;

/**   \brief  value based type definition for SoAd_RouteGrpIdOfRouteGrp */
typedef uint8 SoAd_RouteGrpIdOfRouteGrpType;

/**   \brief  value based type definition for SoAd_RouteGrpSoConEndIdxOfRouteGrp */
typedef uint8 SoAd_RouteGrpSoConEndIdxOfRouteGrpType;

/**   \brief  value based type definition for SoAd_RouteGrpSoConStartIdxOfRouteGrp */
typedef uint8 SoAd_RouteGrpSoConStartIdxOfRouteGrpType;

/**   \brief  value based type definition for SoAd_RxRequestEnableOfRouteGrp */
typedef boolean SoAd_RxRequestEnableOfRouteGrpType;

/**   \brief  value based type definition for SoAd_SocketRouteIndEndIdxOfRouteGrp */
typedef uint8 SoAd_SocketRouteIndEndIdxOfRouteGrpType;

/**   \brief  value based type definition for SoAd_SocketRouteIndStartIdxOfRouteGrp */
typedef uint8 SoAd_SocketRouteIndStartIdxOfRouteGrpType;

/**   \brief  value based type definition for SoAd_SocketRouteIndUsedOfRouteGrp */
typedef boolean SoAd_SocketRouteIndUsedOfRouteGrpType;

/**   \brief  value based type definition for SoAd_TxTriggerableOfRouteGrp */
typedef boolean SoAd_TxTriggerableOfRouteGrpType;

/**   \brief  value based type definition for SoAd_InvalidHndOfRouteGrpIdMap */
typedef boolean SoAd_InvalidHndOfRouteGrpIdMapType;

/**   \brief  value based type definition for SoAd_PartitionSpecificRouteGrpIdxOfRouteGrpIdMap */
typedef uint8 SoAd_PartitionSpecificRouteGrpIdxOfRouteGrpIdMapType;

/**   \brief  value based type definition for SoAd_PartitionSpecificRouteGrpPartitionIdxOfRouteGrpIdMap */
typedef uint8 SoAd_PartitionSpecificRouteGrpPartitionIdxOfRouteGrpIdMapType;

/**   \brief  value based type definition for SoAd_PartitionSpecificRouteGrpUsedOfRouteGrpIdMap */
typedef boolean SoAd_PartitionSpecificRouteGrpUsedOfRouteGrpIdMapType;

/**   \brief  value based type definition for SoAd_RouteGrpIdxOfRouteGrpSoCon */
typedef uint8 SoAd_RouteGrpIdxOfRouteGrpSoConType;

/**   \brief  value based type definition for SoAd_SoConIdxOfRouteGrpSoCon */
typedef uint8 SoAd_SoConIdxOfRouteGrpSoConType;

/**   \brief  value based type definition for SoAd_RouteGrpSoConByPduRouteDestInd */
typedef uint8 SoAd_RouteGrpSoConByPduRouteDestIndType;

/**   \brief  value based type definition for SoAd_RouteGrpSoConBySocketRouteDestInd */
typedef uint8 SoAd_RouteGrpSoConBySocketRouteDestIndType;

/**   \brief  value based type definition for SoAd_EnabledOfRouteGrpSoConDyn */
typedef boolean SoAd_EnabledOfRouteGrpSoConDynType;

/**   \brief  value based type definition for SoAd_FlagsOfRouteGrpSoConDyn */
typedef uint8 SoAd_FlagsOfRouteGrpSoConDynType;

/**   \brief  value based type definition for SoAd_RxBufStructSegIdxOfRxBufStructMgt */
typedef uint8 SoAd_RxBufStructSegIdxOfRxBufStructMgtType;

/**   \brief  value based type definition for SoAd_RxBufStructSegLvlOfRxBufStructMgt */
typedef uint8 SoAd_RxBufStructSegLvlOfRxBufStructMgtType;

/**   \brief  value based type definition for SoAd_LenOfRxBufStructSeg */
typedef uint16 SoAd_LenOfRxBufStructSegType;

/**   \brief  value based type definition for SoAd_IfRxBufferEndIdxOfRxBufferConfig */
typedef uint8 SoAd_IfRxBufferEndIdxOfRxBufferConfigType;

/**   \brief  value based type definition for SoAd_IfRxBufferStartIdxOfRxBufferConfig */
typedef uint8 SoAd_IfRxBufferStartIdxOfRxBufferConfigType;

/**   \brief  value based type definition for SoAd_IfRxBufferUsedOfRxBufferConfig */
typedef boolean SoAd_IfRxBufferUsedOfRxBufferConfigType;

/**   \brief  value based type definition for SoAd_MetaDataRxBufferEndIdxOfRxBufferConfig */
typedef uint8 SoAd_MetaDataRxBufferEndIdxOfRxBufferConfigType;

/**   \brief  value based type definition for SoAd_MetaDataRxBufferStartIdxOfRxBufferConfig */
typedef uint8 SoAd_MetaDataRxBufferStartIdxOfRxBufferConfigType;

/**   \brief  value based type definition for SoAd_MetaDataRxBufferUsedOfRxBufferConfig */
typedef boolean SoAd_MetaDataRxBufferUsedOfRxBufferConfigType;

/**   \brief  value based type definition for SoAd_TpRxBufferEndIdxOfRxBufferConfig */
typedef uint8 SoAd_TpRxBufferEndIdxOfRxBufferConfigType;

/**   \brief  value based type definition for SoAd_TpRxBufferStartIdxOfRxBufferConfig */
typedef uint8 SoAd_TpRxBufferStartIdxOfRxBufferConfigType;

/**   \brief  value based type definition for SoAd_TpRxBufferUsedOfRxBufferConfig */
typedef boolean SoAd_TpRxBufferUsedOfRxBufferConfigType;

/**   \brief  value based type definition for SoAd_IfRxBufferIdxOfRxBufferConfigDyn */
typedef uint8 SoAd_IfRxBufferIdxOfRxBufferConfigDynType;

/**   \brief  value based type definition for SoAd_TpRxBufferIdxOfRxBufferConfigDyn */
typedef uint8 SoAd_TpRxBufferIdxOfRxBufferConfigDynType;

/**   \brief  value based type definition for SoAd_CancelRequestedOfRxMgt */
typedef boolean SoAd_CancelRequestedOfRxMgtType;

/**   \brief  value based type definition for SoAd_RxBytesPendingOfRxMgt */
typedef PduLengthType SoAd_RxBytesPendingOfRxMgtType;

/**   \brief  value based type definition for SoAd_SocketRouteDestIdxOfRxMgt */
typedef uint8 SoAd_SocketRouteDestIdxOfRxMgtType;

/**   \brief  value based type definition for SoAd_InvalidHndOfRxPduIdIdMap */
typedef boolean SoAd_InvalidHndOfRxPduIdIdMapType;

/**   \brief  value based type definition for SoAd_PartitionSpecificSocketRouteDestIdxOfRxPduIdIdMap */
typedef uint8 SoAd_PartitionSpecificSocketRouteDestIdxOfRxPduIdIdMapType;

/**   \brief  value based type definition for SoAd_PartitionSpecificSocketRouteDestPartitionIdxOfRxPduIdIdMap */
typedef uint8 SoAd_PartitionSpecificSocketRouteDestPartitionIdxOfRxPduIdIdMapType;

/**   \brief  value based type definition for SoAd_IpFragMgtIdxOfSoCon */
typedef uint8 SoAd_IpFragMgtIdxOfSoConType;

/**   \brief  value based type definition for SoAd_IpFragMgtUsedOfSoCon */
typedef boolean SoAd_IpFragMgtUsedOfSoConType;

/**   \brief  value based type definition for SoAd_LocalIpAddrAssignmentChgCbkIndEndIdxOfSoCon */
typedef uint8 SoAd_LocalIpAddrAssignmentChgCbkIndEndIdxOfSoConType;

/**   \brief  value based type definition for SoAd_LocalIpAddrAssignmentChgCbkIndStartIdxOfSoCon */
typedef uint8 SoAd_LocalIpAddrAssignmentChgCbkIndStartIdxOfSoConType;

/**   \brief  value based type definition for SoAd_LocalIpAddrAssignmentChgCbkIndUsedOfSoCon */
typedef boolean SoAd_LocalIpAddrAssignmentChgCbkIndUsedOfSoConType;

/**   \brief  value based type definition for SoAd_NPduUdpTxIdxOfSoCon */
typedef uint8 SoAd_NPduUdpTxIdxOfSoConType;

/**   \brief  value based type definition for SoAd_NPduUdpTxUsedOfSoCon */
typedef boolean SoAd_NPduUdpTxUsedOfSoConType;

/**   \brief  value based type definition for SoAd_PduRouteDestBySoConIndEndIdxOfSoCon */
typedef uint8 SoAd_PduRouteDestBySoConIndEndIdxOfSoConType;

/**   \brief  value based type definition for SoAd_PduRouteDestBySoConIndStartIdxOfSoCon */
typedef uint8 SoAd_PduRouteDestBySoConIndStartIdxOfSoConType;

/**   \brief  value based type definition for SoAd_PduRouteDestBySoConIndUsedOfSoCon */
typedef boolean SoAd_PduRouteDestBySoConIndUsedOfSoConType;

/**   \brief  value based type definition for SoAd_RemAddrIpV4IdxOfSoCon */
typedef uint8 SoAd_RemAddrIpV4IdxOfSoConType;

/**   \brief  value based type definition for SoAd_RemAddrIpV4UsedOfSoCon */
typedef boolean SoAd_RemAddrIpV4UsedOfSoConType;

/**   \brief  value based type definition for SoAd_RemAddrIpV6IdxOfSoCon */
typedef uint8 SoAd_RemAddrIpV6IdxOfSoConType;

/**   \brief  value based type definition for SoAd_RemAddrIpV6UsedOfSoCon */
typedef boolean SoAd_RemAddrIpV6UsedOfSoConType;

/**   \brief  value based type definition for SoAd_RemAddrRcvIdxOfSoCon */
typedef uint8 SoAd_RemAddrRcvIdxOfSoConType;

/**   \brief  value based type definition for SoAd_RemAddrRcvUsedOfSoCon */
typedef boolean SoAd_RemAddrRcvUsedOfSoConType;

/**   \brief  value based type definition for SoAd_RxBufStructMgtIdxOfSoCon */
typedef uint8 SoAd_RxBufStructMgtIdxOfSoConType;

/**   \brief  value based type definition for SoAd_RxBufStructMgtUsedOfSoCon */
typedef boolean SoAd_RxBufStructMgtUsedOfSoConType;

/**   \brief  value based type definition for SoAd_RxBufStructSegEndIdxOfSoCon */
typedef uint8 SoAd_RxBufStructSegEndIdxOfSoConType;

/**   \brief  value based type definition for SoAd_RxBufStructSegStartIdxOfSoCon */
typedef uint8 SoAd_RxBufStructSegStartIdxOfSoConType;

/**   \brief  value based type definition for SoAd_RxBufStructSegUsedOfSoCon */
typedef boolean SoAd_RxBufStructSegUsedOfSoConType;

/**   \brief  value based type definition for SoAd_RxBufferConfigIdxOfSoCon */
typedef uint8 SoAd_RxBufferConfigIdxOfSoConType;

/**   \brief  value based type definition for SoAd_RxBufferConfigUsedOfSoCon */
typedef boolean SoAd_RxBufferConfigUsedOfSoConType;

/**   \brief  value based type definition for SoAd_RxMgtIdxOfSoCon */
typedef uint8 SoAd_RxMgtIdxOfSoConType;

/**   \brief  value based type definition for SoAd_RxMgtUsedOfSoCon */
typedef boolean SoAd_RxMgtUsedOfSoConType;

/**   \brief  value based type definition for SoAd_SoConGrpIdxOfSoCon */
typedef uint8 SoAd_SoConGrpIdxOfSoConType;

/**   \brief  value based type definition for SoAd_SoConIdOfSoCon */
typedef uint8 SoAd_SoConIdOfSoConType;

/**   \brief  value based type definition for SoAd_SoConModeChgCbkIndEndIdxOfSoCon */
typedef uint8 SoAd_SoConModeChgCbkIndEndIdxOfSoConType;

/**   \brief  value based type definition for SoAd_SoConModeChgCbkIndStartIdxOfSoCon */
typedef uint8 SoAd_SoConModeChgCbkIndStartIdxOfSoConType;

/**   \brief  value based type definition for SoAd_SoConModeChgCbkIndUsedOfSoCon */
typedef boolean SoAd_SoConModeChgCbkIndUsedOfSoConType;

/**   \brief  value based type definition for SoAd_SocketIdxOfSoCon */
typedef uint8 SoAd_SocketIdxOfSoConType;

/**   \brief  value based type definition for SoAd_SocketRouteEndIdxOfSoCon */
typedef uint8 SoAd_SocketRouteEndIdxOfSoConType;

/**   \brief  value based type definition for SoAd_SocketRouteStartIdxOfSoCon */
typedef uint8 SoAd_SocketRouteStartIdxOfSoConType;

/**   \brief  value based type definition for SoAd_SocketRouteUsedOfSoCon */
typedef boolean SoAd_SocketRouteUsedOfSoConType;

/**   \brief  value based type definition for SoAd_TcpTxQueueIdxOfSoCon */
typedef uint8 SoAd_TcpTxQueueIdxOfSoConType;

/**   \brief  value based type definition for SoAd_TcpTxQueueUsedOfSoCon */
typedef boolean SoAd_TcpTxQueueUsedOfSoConType;

/**   \brief  value based type definition for SoAd_TpTxBufferConfigIdxOfSoCon */
typedef uint8 SoAd_TpTxBufferConfigIdxOfSoConType;

/**   \brief  value based type definition for SoAd_TpTxBufferConfigUsedOfSoCon */
typedef boolean SoAd_TpTxBufferConfigUsedOfSoConType;

/**   \brief  value based type definition for SoAd_TxMgtIdxOfSoCon */
typedef uint8 SoAd_TxMgtIdxOfSoConType;

/**   \brief  value based type definition for SoAd_TxMgtUsedOfSoCon */
typedef boolean SoAd_TxMgtUsedOfSoConType;

/**   \brief  value based type definition for SoAd_AbortOfSoConDyn */
typedef boolean SoAd_AbortOfSoConDynType;

/**   \brief  value based type definition for SoAd_OpenCloseCounterOfSoConDyn */
typedef uint32 SoAd_OpenCloseCounterOfSoConDynType;

/**   \brief  value based type definition for SoAd_RxActiveOfSoConDyn */
typedef boolean SoAd_RxActiveOfSoConDynType;

/**   \brief  value based type definition for SoAd_TimeoutOccurredOfSoConDyn */
typedef boolean SoAd_TimeoutOccurredOfSoConDynType;

/**   \brief  value based type definition for SoAd_TxActiveOfSoConDyn */
typedef boolean SoAd_TxActiveOfSoConDynType;

/**   \brief  value based type definition for SoAd_BestMatchWithPduHeaderEnabledOfSoConGrp */
typedef boolean SoAd_BestMatchWithPduHeaderEnabledOfSoConGrpType;

/**   \brief  value based type definition for SoAd_BestMatchWithSockRouteEnabledOfSoConGrp */
typedef boolean SoAd_BestMatchWithSockRouteEnabledOfSoConGrpType;

/**   \brief  value based type definition for SoAd_FramePriorityOfSoConGrp */
typedef uint8 SoAd_FramePriorityOfSoConGrpType;

/**   \brief  value based type definition for SoAd_InstanceIdxOfSoConGrp */
typedef uint8 SoAd_InstanceIdxOfSoConGrpType;

/**   \brief  value based type definition for SoAd_LocalAddrIdxOfSoConGrp */
typedef uint8 SoAd_LocalAddrIdxOfSoConGrpType;

/**   \brief  value based type definition for SoAd_LocalAddrUsedOfSoConGrp */
typedef boolean SoAd_LocalAddrUsedOfSoConGrpType;

/**   \brief  value based type definition for SoAd_MsgAcceptFilterEnabledOfSoConGrp */
typedef boolean SoAd_MsgAcceptFilterEnabledOfSoConGrpType;

/**   \brief  value based type definition for SoAd_PduHdrEnabledOfSoConGrp */
typedef boolean SoAd_PduHdrEnabledOfSoConGrpType;

/**   \brief  value based type definition for SoAd_SoConEndIdxOfSoConGrp */
typedef uint8 SoAd_SoConEndIdxOfSoConGrpType;

/**   \brief  value based type definition for SoAd_SoConStartIdxOfSoConGrp */
typedef uint8 SoAd_SoConStartIdxOfSoConGrpType;

/**   \brief  value based type definition for SoAd_SockAutoSoConSetupKeepOnlineOfSoConGrp */
typedef boolean SoAd_SockAutoSoConSetupKeepOnlineOfSoConGrpType;

/**   \brief  value based type definition for SoAd_SockAutoSoConSetupOfSoConGrp */
typedef boolean SoAd_SockAutoSoConSetupOfSoConGrpType;

/**   \brief  value based type definition for SoAd_SocketIdxOfSoConGrp */
typedef uint8 SoAd_SocketIdxOfSoConGrpType;

/**   \brief  value based type definition for SoAd_SocketTcpIdxOfSoConGrp */
typedef uint8 SoAd_SocketTcpIdxOfSoConGrpType;

/**   \brief  value based type definition for SoAd_SocketTcpUsedOfSoConGrp */
typedef boolean SoAd_SocketTcpUsedOfSoConGrpType;

/**   \brief  value based type definition for SoAd_SocketUdpIdxOfSoConGrp */
typedef uint8 SoAd_SocketUdpIdxOfSoConGrpType;

/**   \brief  value based type definition for SoAd_SocketUdpUsedOfSoConGrp */
typedef boolean SoAd_SocketUdpUsedOfSoConGrpType;

/**   \brief  value based type definition for SoAd_SocketUsedOfSoConGrp */
typedef boolean SoAd_SocketUsedOfSoConGrpType;

/**   \brief  value based type definition for SoAd_InvalidHndOfSoConMap */
typedef boolean SoAd_InvalidHndOfSoConMapType;

/**   \brief  value based type definition for SoAd_PartitionSpecificSoConIdxOfSoConMap */
typedef uint8 SoAd_PartitionSpecificSoConIdxOfSoConMapType;

/**   \brief  value based type definition for SoAd_PartitionSpecificSoConPartitionIdxOfSoConMap */
typedef uint8 SoAd_PartitionSpecificSoConPartitionIdxOfSoConMapType;

/**   \brief  value based type definition for SoAd_SoConModeChgCbkInd */
typedef uint8 SoAd_SoConModeChgCbkIndType;

/**   \brief  value based type definition for SoAd_SoConEndIdxOfSocket */
typedef uint8 SoAd_SoConEndIdxOfSocketType;

/**   \brief  value based type definition for SoAd_SoConStartIdxOfSocket */
typedef uint8 SoAd_SoConStartIdxOfSocketType;

/**   \brief  value based type definition for SoAd_SkipBytesOfSocketDyn */
typedef uint32 SoAd_SkipBytesOfSocketDynType;

/**   \brief  value based type definition for SoAd_SoConTxActiveIdxOfSocketDyn */
typedef uint8 SoAd_SoConTxActiveIdxOfSocketDynType;

/**   \brief  value based type definition for SoAd_MetaDataRxEnabledOfSocketRoute */
typedef boolean SoAd_MetaDataRxEnabledOfSocketRouteType;

/**   \brief  value based type definition for SoAd_RxPduHdrMethodIdOfSocketRoute */
typedef uint16 SoAd_RxPduHdrMethodIdOfSocketRouteType;

/**   \brief  value based type definition for SoAd_RxPduHdrServiceIdOfSocketRoute */
typedef uint16 SoAd_RxPduHdrServiceIdOfSocketRouteType;

/**   \brief  value based type definition for SoAd_SoConIdxOfSocketRoute */
typedef uint8 SoAd_SoConIdxOfSocketRouteType;

/**   \brief  value based type definition for SoAd_SocketRouteDestEndIdxOfSocketRoute */
typedef uint8 SoAd_SocketRouteDestEndIdxOfSocketRouteType;

/**   \brief  value based type definition for SoAd_SocketRouteDestStartIdxOfSocketRoute */
typedef uint8 SoAd_SocketRouteDestStartIdxOfSocketRouteType;

/**   \brief  value based type definition for SoAd_RouteGrpSoConBySocketRouteDestIndEndIdxOfSocketRouteDest */
typedef uint8 SoAd_RouteGrpSoConBySocketRouteDestIndEndIdxOfSocketRouteDestType;

/**   \brief  value based type definition for SoAd_RouteGrpSoConBySocketRouteDestIndStartIdxOfSocketRouteDest */
typedef uint8 SoAd_RouteGrpSoConBySocketRouteDestIndStartIdxOfSocketRouteDestType;

/**   \brief  value based type definition for SoAd_RouteGrpSoConBySocketRouteDestIndUsedOfSocketRouteDest */
typedef boolean SoAd_RouteGrpSoConBySocketRouteDestIndUsedOfSocketRouteDestType;

/**   \brief  value based type definition for SoAd_RxPduIdOfSocketRouteDest */
typedef PduIdType SoAd_RxPduIdOfSocketRouteDestType;

/**   \brief  value based type definition for SoAd_SocketRouteIdxOfSocketRouteDest */
typedef uint8 SoAd_SocketRouteIdxOfSocketRouteDestType;

/**   \brief  value based type definition for SoAd_UpperLayerIdxOfSocketRouteDest */
typedef uint8 SoAd_UpperLayerIdxOfSocketRouteDestType;

/**   \brief  value based type definition for SoAd_SocketRouteInd */
typedef uint8 SoAd_SocketRouteIndType;

/**   \brief  value based type definition for SoAd_ImmedTpTxConfOfSocketTcp */
typedef boolean SoAd_ImmedTpTxConfOfSocketTcpType;

/**   \brief  value based type definition for SoAd_TcpInitiateOfSocketTcp */
typedef boolean SoAd_TcpInitiateOfSocketTcpType;

/**   \brief  value based type definition for SoAd_TcpKeepAliveIntervalOfSocketTcp */
typedef uint8 SoAd_TcpKeepAliveIntervalOfSocketTcpType;

/**   \brief  value based type definition for SoAd_TcpKeepAliveOfSocketTcp */
typedef boolean SoAd_TcpKeepAliveOfSocketTcpType;

/**   \brief  value based type definition for SoAd_TcpKeepAliveProbesMaxOfSocketTcp */
typedef uint8 SoAd_TcpKeepAliveProbesMaxOfSocketTcpType;

/**   \brief  value based type definition for SoAd_TcpKeepAliveTimeOfSocketTcp */
typedef uint8 SoAd_TcpKeepAliveTimeOfSocketTcpType;

/**   \brief  value based type definition for SoAd_TcpMslOfSocketTcp */
typedef uint8 SoAd_TcpMslOfSocketTcpType;

/**   \brief  value based type definition for SoAd_TcpRxBufMinOfSocketTcp */
typedef uint8 SoAd_TcpRxBufMinOfSocketTcpType;

/**   \brief  value based type definition for SoAd_TcpTlsConIdOfSocketTcp */
typedef uint8 SoAd_TcpTlsConIdOfSocketTcpType;

/**   \brief  value based type definition for SoAd_TcpTxBufMinOfSocketTcp */
typedef uint8 SoAd_TcpTxBufMinOfSocketTcpType;

/**   \brief  value based type definition for SoAd_AliveTimeoutMaxCntOfSocketUdp */
typedef uint16 SoAd_AliveTimeoutMaxCntOfSocketUdpType;

/**   \brief  value based type definition for SoAd_ChecksumChangeEnabledOfSocketUdp */
typedef boolean SoAd_ChecksumChangeEnabledOfSocketUdpType;

/**   \brief  value based type definition for SoAd_ChecksumEnabledOfSocketUdp */
typedef boolean SoAd_ChecksumEnabledOfSocketUdpType;

/**   \brief  value based type definition for SoAd_ImmedIfTxConfListSizeOfSocketUdp */
typedef uint8 SoAd_ImmedIfTxConfListSizeOfSocketUdpType;

/**   \brief  value based type definition for SoAd_ImmedIfTxConfOfSocketUdp */
typedef boolean SoAd_ImmedIfTxConfOfSocketUdpType;

/**   \brief  value based type definition for SoAd_NPduUdpTxBufferMinOfSocketUdp */
typedef uint8 SoAd_NPduUdpTxBufferMinOfSocketUdpType;

/**   \brief  value based type definition for SoAd_NPduUdpTxQueueSizeOfSocketUdp */
typedef uint8 SoAd_NPduUdpTxQueueSizeOfSocketUdpType;

/**   \brief  value based type definition for SoAd_RetryQueueLimitOfSocketUdp */
typedef uint8 SoAd_RetryQueueLimitOfSocketUdpType;

/**   \brief  value based type definition for SoAd_UdpListenOnlyOfSocketUdp */
typedef boolean SoAd_UdpListenOnlyOfSocketUdpType;

/**   \brief  value based type definition for SoAd_UdpStrictHdrLenCheckEnabledOfSocketUdp */
typedef boolean SoAd_UdpStrictHdrLenCheckEnabledOfSocketUdpType;

/**   \brief  value based type definition for SoAd_UdpTriggerTimeoutOfSocketUdp */
typedef uint8 SoAd_UdpTriggerTimeoutOfSocketUdpType;

/**   \brief  value based type definition for SoAd_LocalAddrByTcpIpCtrlIndEndIdxOfTcpIpCtrl */
typedef uint8 SoAd_LocalAddrByTcpIpCtrlIndEndIdxOfTcpIpCtrlType;

/**   \brief  value based type definition for SoAd_LocalAddrByTcpIpCtrlIndStartIdxOfTcpIpCtrl */
typedef uint8 SoAd_LocalAddrByTcpIpCtrlIndStartIdxOfTcpIpCtrlType;

/**   \brief  value based type definition for SoAd_LocalAddrByTcpIpCtrlIndUsedOfTcpIpCtrl */
typedef boolean SoAd_LocalAddrByTcpIpCtrlIndUsedOfTcpIpCtrlType;

/**   \brief  value based type definition for SoAd_RetryEnabledOfTcpIpCtrl */
typedef boolean SoAd_RetryEnabledOfTcpIpCtrlType;

/**   \brief  value based type definition for SoAd_TcpKeepAliveGloballyEnabled */
typedef boolean SoAd_TcpKeepAliveGloballyEnabledType;

/**   \brief  value based type definition for SoAd_TcpTxQueueDataEndIdxOfTcpTxQueue */
typedef uint8 SoAd_TcpTxQueueDataEndIdxOfTcpTxQueueType;

/**   \brief  value based type definition for SoAd_TcpTxQueueDataStartIdxOfTcpTxQueue */
typedef uint8 SoAd_TcpTxQueueDataStartIdxOfTcpTxQueueType;

/**   \brief  value based type definition for SoAd_LenOfTcpTxQueueData */
typedef PduLengthType SoAd_LenOfTcpTxQueueDataType;

/**   \brief  value based type definition for SoAd_PduRouteIdxOfTcpTxQueueData */
typedef uint8 SoAd_PduRouteIdxOfTcpTxQueueDataType;

/**   \brief  value based type definition for SoAd_LvlOfTcpTxQueueMgt */
typedef uint16 SoAd_LvlOfTcpTxQueueMgtType;

/**   \brief  value based type definition for SoAd_TcpTxQueueDataIdxOfTcpTxQueueMgt */
typedef uint8 SoAd_TcpTxQueueDataIdxOfTcpTxQueueMgtType;

/**   \brief  value based type definition for SoAd_TotLenOfTcpTxQueueMgt */
typedef uint32 SoAd_TotLenOfTcpTxQueueMgtType;

/**   \brief  value based type definition for SoAd_TimeoutListNPduUdpTxConfigIdxOfTimeoutListIdent */
typedef uint8 SoAd_TimeoutListNPduUdpTxConfigIdxOfTimeoutListIdentType;

/**   \brief  value based type definition for SoAd_TimeoutListNPduUdpTxConfigUsedOfTimeoutListIdent */
typedef boolean SoAd_TimeoutListNPduUdpTxConfigUsedOfTimeoutListIdentType;

/**   \brief  value based type definition for SoAd_TimeoutListTcpAutoConnectConfigIdxOfTimeoutListIdent */
typedef uint8 SoAd_TimeoutListTcpAutoConnectConfigIdxOfTimeoutListIdentType;

/**   \brief  value based type definition for SoAd_TimeoutListTcpAutoConnectConfigUsedOfTimeoutListIdent */
typedef boolean SoAd_TimeoutListTcpAutoConnectConfigUsedOfTimeoutListIdentType;

/**   \brief  value based type definition for SoAd_TimeoutListUdpAliveConfigIdxOfTimeoutListIdent */
typedef uint8 SoAd_TimeoutListUdpAliveConfigIdxOfTimeoutListIdentType;

/**   \brief  value based type definition for SoAd_TimeoutListUdpAliveConfigUsedOfTimeoutListIdent */
typedef boolean SoAd_TimeoutListUdpAliveConfigUsedOfTimeoutListIdentType;

/**   \brief  value based type definition for SoAd_LvlOfTimeoutListMgmt */
typedef uint16 SoAd_LvlOfTimeoutListMgmtType;

/**   \brief  value based type definition for SoAd_NPduUdpTxIdxOfTimeoutListNPduUdpTx */
typedef uint8 SoAd_NPduUdpTxIdxOfTimeoutListNPduUdpTxType;

/**   \brief  value based type definition for SoAd_TimeoutOfTimeoutListNPduUdpTx */
typedef uint32 SoAd_TimeoutOfTimeoutListNPduUdpTxType;

/**   \brief  value based type definition for SoAd_TimeoutListMgmtIdxOfTimeoutListNPduUdpTxConfig */
typedef uint8 SoAd_TimeoutListMgmtIdxOfTimeoutListNPduUdpTxConfigType;

/**   \brief  value based type definition for SoAd_TimeoutListNPduUdpTxEndIdxOfTimeoutListNPduUdpTxConfig */
typedef uint8 SoAd_TimeoutListNPduUdpTxEndIdxOfTimeoutListNPduUdpTxConfigType;

/**   \brief  value based type definition for SoAd_TimeoutListNPduUdpTxStartIdxOfTimeoutListNPduUdpTxConfig */
typedef uint8 SoAd_TimeoutListNPduUdpTxStartIdxOfTimeoutListNPduUdpTxConfigType;

/**   \brief  value based type definition for SoAd_TimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap */
typedef uint8 SoAd_TimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMapType;

/**   \brief  value based type definition for SoAd_TimeoutListMgmtIdxOfTimeoutListTcpAutoConnectConfig */
typedef uint8 SoAd_TimeoutListMgmtIdxOfTimeoutListTcpAutoConnectConfigType;

/**   \brief  value based type definition for SoAd_SoConIdxOfTimeoutListUdpAlive */
typedef uint8 SoAd_SoConIdxOfTimeoutListUdpAliveType;

/**   \brief  value based type definition for SoAd_TimeoutOfTimeoutListUdpAlive */
typedef uint32 SoAd_TimeoutOfTimeoutListUdpAliveType;

/**   \brief  value based type definition for SoAd_TimeoutListMgmtIdxOfTimeoutListUdpAliveConfig */
typedef uint8 SoAd_TimeoutListMgmtIdxOfTimeoutListUdpAliveConfigType;

/**   \brief  value based type definition for SoAd_TimeoutListUdpAliveEndIdxOfTimeoutListUdpAliveConfig */
typedef uint8 SoAd_TimeoutListUdpAliveEndIdxOfTimeoutListUdpAliveConfigType;

/**   \brief  value based type definition for SoAd_TimeoutListUdpAliveStartIdxOfTimeoutListUdpAliveConfig */
typedef uint8 SoAd_TimeoutListUdpAliveStartIdxOfTimeoutListUdpAliveConfigType;

/**   \brief  value based type definition for SoAd_TimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap */
typedef uint8 SoAd_TimeoutListUdpAliveIdxOfTimeoutListUdpAliveMapType;

/**   \brief  value based type definition for SoAd_TpRxBuffer */
typedef uint8 SoAd_TpRxBufferType;

/**   \brief  value based type definition for SoAd_TpTxBuffer */
typedef uint8 SoAd_TpTxBufferType;

/**   \brief  value based type definition for SoAd_TpTxBufferEndIdxOfTpTxBufferConfig */
typedef uint8 SoAd_TpTxBufferEndIdxOfTpTxBufferConfigType;

/**   \brief  value based type definition for SoAd_TpTxBufferStartIdxOfTpTxBufferConfig */
typedef uint8 SoAd_TpTxBufferStartIdxOfTpTxBufferConfigType;

/**   \brief  value based type definition for SoAd_TpTxBufferUsedOfTpTxBufferConfig */
typedef boolean SoAd_TpTxBufferUsedOfTpTxBufferConfigType;

/**   \brief  value based type definition for SoAd_TpTxBufferIdxOfTpTxBufferConfigDyn */
typedef uint8 SoAd_TpTxBufferIdxOfTpTxBufferConfigDynType;

/**   \brief  value based type definition for SoAd_TriggerBuf */
typedef uint8 SoAd_TriggerBufType;

/**   \brief  value based type definition for SoAd_TriggerBufEndIdxOfTriggerBufConfig */
typedef uint8 SoAd_TriggerBufEndIdxOfTriggerBufConfigType;

/**   \brief  value based type definition for SoAd_TriggerBufStartIdxOfTriggerBufConfig */
typedef uint8 SoAd_TriggerBufStartIdxOfTriggerBufConfigType;

/**   \brief  value based type definition for SoAd_LengthOfTriggerBufConfigDyn */
typedef uint16 SoAd_LengthOfTriggerBufConfigDynType;

/**   \brief  value based type definition for SoAd_PduRouteIdxOfTriggerBufConfigDyn */
typedef uint8 SoAd_PduRouteIdxOfTriggerBufConfigDynType;

/**   \brief  value based type definition for SoAd_CancelRequestedOfTxMgt */
typedef boolean SoAd_CancelRequestedOfTxMgtType;

/**   \brief  value based type definition for SoAd_PduRouteDestIdxOfTxMgt */
typedef uint8 SoAd_PduRouteDestIdxOfTxMgtType;

/**   \brief  value based type definition for SoAd_TxBytesLenOfTxMgt */
typedef PduLengthType SoAd_TxBytesLenOfTxMgtType;

/**   \brief  value based type definition for SoAd_TxBytesPendingOfTxMgt */
typedef PduLengthType SoAd_TxBytesPendingOfTxMgtType;

/**   \brief  value based type definition for SoAd_InvalidHndOfTxPduIdMap */
typedef boolean SoAd_InvalidHndOfTxPduIdMapType;

/**   \brief  value based type definition for SoAd_PartitionSpecificPduRouteIdxOfTxPduIdMap */
typedef uint8 SoAd_PartitionSpecificPduRouteIdxOfTxPduIdMapType;

/**   \brief  value based type definition for SoAd_PartitionSpecificPduRoutePartitionIdxOfTxPduIdMap */
typedef uint8 SoAd_PartitionSpecificPduRoutePartitionIdxOfTxPduIdMapType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  SoAdPCStructTypes  SoAd Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in SoAd_BestMatchSoConIdxList */
typedef struct sSoAd_BestMatchSoConIdxListType
{
  SoAd_SoConIdxOfBestMatchSoConIdxListType SoConIdxOfBestMatchSoConIdxList;  /**< the index of the 1:1 relation pointing to SoAd_SoCon */
} SoAd_BestMatchSoConIdxListType;

/**   \brief  type used in SoAd_EventQueueIdent */
typedef struct sSoAd_EventQueueIdentType
{
  SoAd_EventQueueFlagEndIdxOfEventQueueIdentType EventQueueFlagEndIdxOfEventQueueIdent;  /**< the end index of the 1:n relation pointing to SoAd_EventQueueFlag */
  SoAd_EventQueueFlagStartIdxOfEventQueueIdentType EventQueueFlagStartIdxOfEventQueueIdent;  /**< the start index of the 1:n relation pointing to SoAd_EventQueueFlag */
  SoAd_EventQueueIfTxRouteGrpConfigIdxOfEventQueueIdentType EventQueueIfTxRouteGrpConfigIdxOfEventQueueIdent;  /**< the index of the 0:1 relation pointing to SoAd_EventQueueIfTxRouteGrpConfig */
  SoAd_EventQueueIfUdpPduRouteConfigIdxOfEventQueueIdentType EventQueueIfUdpPduRouteConfigIdxOfEventQueueIdent;  /**< the index of the 0:1 relation pointing to SoAd_EventQueueIfUdpPduRouteConfig */
  SoAd_EventQueueStateSoConConfigIdxOfEventQueueIdentType EventQueueStateSoConConfigIdxOfEventQueueIdent;  /**< the index of the 1:1 relation pointing to SoAd_EventQueueStateSoConConfig */
  SoAd_EventQueueTpRxSoConConfigIdxOfEventQueueIdentType EventQueueTpRxSoConConfigIdxOfEventQueueIdent;  /**< the index of the 0:1 relation pointing to SoAd_EventQueueTpRxSoConConfig */
  SoAd_EventQueueTpTxSoConConfigIdxOfEventQueueIdentType EventQueueTpTxSoConConfigIdxOfEventQueueIdent;  /**< the index of the 0:1 relation pointing to SoAd_EventQueueTpTxSoConConfig */
} SoAd_EventQueueIdentType;

/**   \brief  type used in SoAd_EventQueueIfTxRouteGrp */
typedef struct sSoAd_EventQueueIfTxRouteGrpType
{
  SoAd_RouteGrpIdxOfEventQueueIfTxRouteGrpType RouteGrpIdxOfEventQueueIfTxRouteGrp;  /**< the index of the 0:1 relation pointing to SoAd_RouteGrp */
} SoAd_EventQueueIfTxRouteGrpType;

/**   \brief  type used in SoAd_EventQueueIfTxRouteGrpConfig */
typedef struct sSoAd_EventQueueIfTxRouteGrpConfigType
{
  SoAd_EventQueueIfTxRouteGrpEndIdxOfEventQueueIfTxRouteGrpConfigType EventQueueIfTxRouteGrpEndIdxOfEventQueueIfTxRouteGrpConfig;  /**< the end index of the 1:n relation pointing to SoAd_EventQueueIfTxRouteGrp */
  SoAd_EventQueueIfTxRouteGrpStartIdxOfEventQueueIfTxRouteGrpConfigType EventQueueIfTxRouteGrpStartIdxOfEventQueueIfTxRouteGrpConfig;  /**< the start index of the 1:n relation pointing to SoAd_EventQueueIfTxRouteGrp */
  SoAd_EventQueueMgmtIdxOfEventQueueIfTxRouteGrpConfigType EventQueueMgmtIdxOfEventQueueIfTxRouteGrpConfig;  /**< the index of the 1:1 relation pointing to SoAd_EventQueueMgmt */
  SoAd_FlagOffsetOfEventQueueIfTxRouteGrpConfigType FlagOffsetOfEventQueueIfTxRouteGrpConfig;  /**< the relative offset per instance within the event queue flags array */
  SoAd_LimitOfEventQueueIfTxRouteGrpConfigType LimitOfEventQueueIfTxRouteGrpConfig;  /**< the limit of events handled in a single main function call */
} SoAd_EventQueueIfTxRouteGrpConfigType;

/**   \brief  type used in SoAd_EventQueueIfUdpPduRoute */
typedef struct sSoAd_EventQueueIfUdpPduRouteType
{
  SoAd_PduRouteIdxOfEventQueueIfUdpPduRouteType PduRouteIdxOfEventQueueIfUdpPduRoute;  /**< the index of the 0:1 relation pointing to SoAd_PduRoute */
} SoAd_EventQueueIfUdpPduRouteType;

/**   \brief  type used in SoAd_EventQueueIfUdpPduRouteConfig */
typedef struct sSoAd_EventQueueIfUdpPduRouteConfigType
{
  SoAd_EventQueueIfUdpPduRouteEndIdxOfEventQueueIfUdpPduRouteConfigType EventQueueIfUdpPduRouteEndIdxOfEventQueueIfUdpPduRouteConfig;  /**< the end index of the 1:n relation pointing to SoAd_EventQueueIfUdpPduRoute */
  SoAd_EventQueueIfUdpPduRouteStartIdxOfEventQueueIfUdpPduRouteConfigType EventQueueIfUdpPduRouteStartIdxOfEventQueueIfUdpPduRouteConfig;  /**< the start index of the 1:n relation pointing to SoAd_EventQueueIfUdpPduRoute */
  SoAd_EventQueueMgmtIdxOfEventQueueIfUdpPduRouteConfigType EventQueueMgmtIdxOfEventQueueIfUdpPduRouteConfig;  /**< the index of the 1:1 relation pointing to SoAd_EventQueueMgmt */
  SoAd_FlagOffsetOfEventQueueIfUdpPduRouteConfigType FlagOffsetOfEventQueueIfUdpPduRouteConfig;  /**< the relative offset per instance within the event queue flags array */
  SoAd_LimitOfEventQueueIfUdpPduRouteConfigType LimitOfEventQueueIfUdpPduRouteConfig;  /**< the limit of events handled in a single main function call */
} SoAd_EventQueueIfUdpPduRouteConfigType;

/**   \brief  type used in SoAd_EventQueueMgmt */
typedef struct sSoAd_EventQueueMgmtType
{
  SoAd_IdxOfEventQueueMgmtType IdxOfEventQueueMgmt;  /**< the index of oldest pending event. */
  SoAd_LvlOfEventQueueMgmtType LvlOfEventQueueMgmt;  /**< the level of pending events */
} SoAd_EventQueueMgmtType;

/**   \brief  type used in SoAd_EventQueueStateSoCon */
typedef struct sSoAd_EventQueueStateSoConType
{
  SoAd_SoConIdxOfEventQueueStateSoConType SoConIdxOfEventQueueStateSoCon;  /**< the index of the 0:1 relation pointing to SoAd_SoCon */
} SoAd_EventQueueStateSoConType;

/**   \brief  type used in SoAd_EventQueueStateSoConConfig */
typedef struct sSoAd_EventQueueStateSoConConfigType
{
  SoAd_EventQueueMgmtIdxOfEventQueueStateSoConConfigType EventQueueMgmtIdxOfEventQueueStateSoConConfig;  /**< the index of the 1:1 relation pointing to SoAd_EventQueueMgmt */
  SoAd_EventQueueStateSoConEndIdxOfEventQueueStateSoConConfigType EventQueueStateSoConEndIdxOfEventQueueStateSoConConfig;  /**< the end index of the 1:n relation pointing to SoAd_EventQueueStateSoCon */
  SoAd_EventQueueStateSoConStartIdxOfEventQueueStateSoConConfigType EventQueueStateSoConStartIdxOfEventQueueStateSoConConfig;  /**< the start index of the 1:n relation pointing to SoAd_EventQueueStateSoCon */
  SoAd_FlagOffsetOfEventQueueStateSoConConfigType FlagOffsetOfEventQueueStateSoConConfig;  /**< the relative offset per instance within the event queue flags array */
  SoAd_LimitOfEventQueueStateSoConConfigType LimitOfEventQueueStateSoConConfig;  /**< the limit of events handled in a single main function call */
} SoAd_EventQueueStateSoConConfigType;

/**   \brief  type used in SoAd_EventQueueTpRxSoCon */
typedef struct sSoAd_EventQueueTpRxSoConType
{
  SoAd_SoConIdxOfEventQueueTpRxSoConType SoConIdxOfEventQueueTpRxSoCon;  /**< the index of the 0:1 relation pointing to SoAd_SoCon */
} SoAd_EventQueueTpRxSoConType;

/**   \brief  type used in SoAd_EventQueueTpRxSoConConfig */
typedef struct sSoAd_EventQueueTpRxSoConConfigType
{
  SoAd_EventQueueMgmtIdxOfEventQueueTpRxSoConConfigType EventQueueMgmtIdxOfEventQueueTpRxSoConConfig;  /**< the index of the 1:1 relation pointing to SoAd_EventQueueMgmt */
  SoAd_EventQueueTpRxSoConEndIdxOfEventQueueTpRxSoConConfigType EventQueueTpRxSoConEndIdxOfEventQueueTpRxSoConConfig;  /**< the end index of the 1:n relation pointing to SoAd_EventQueueTpRxSoCon */
  SoAd_EventQueueTpRxSoConStartIdxOfEventQueueTpRxSoConConfigType EventQueueTpRxSoConStartIdxOfEventQueueTpRxSoConConfig;  /**< the start index of the 1:n relation pointing to SoAd_EventQueueTpRxSoCon */
  SoAd_FlagOffsetOfEventQueueTpRxSoConConfigType FlagOffsetOfEventQueueTpRxSoConConfig;  /**< the relative offset per instance within the event queue flags array */
  SoAd_LimitOfEventQueueTpRxSoConConfigType LimitOfEventQueueTpRxSoConConfig;  /**< the limit of events handled in a single main function call */
} SoAd_EventQueueTpRxSoConConfigType;

/**   \brief  type used in SoAd_EventQueueTpTxSoCon */
typedef struct sSoAd_EventQueueTpTxSoConType
{
  SoAd_SoConIdxOfEventQueueTpTxSoConType SoConIdxOfEventQueueTpTxSoCon;  /**< the index of the 0:1 relation pointing to SoAd_SoCon */
} SoAd_EventQueueTpTxSoConType;

/**   \brief  type used in SoAd_EventQueueTpTxSoConConfig */
typedef struct sSoAd_EventQueueTpTxSoConConfigType
{
  SoAd_EventQueueMgmtIdxOfEventQueueTpTxSoConConfigType EventQueueMgmtIdxOfEventQueueTpTxSoConConfig;  /**< the index of the 1:1 relation pointing to SoAd_EventQueueMgmt */
  SoAd_EventQueueTpTxSoConEndIdxOfEventQueueTpTxSoConConfigType EventQueueTpTxSoConEndIdxOfEventQueueTpTxSoConConfig;  /**< the end index of the 1:n relation pointing to SoAd_EventQueueTpTxSoCon */
  SoAd_EventQueueTpTxSoConStartIdxOfEventQueueTpTxSoConConfigType EventQueueTpTxSoConStartIdxOfEventQueueTpTxSoConConfig;  /**< the start index of the 1:n relation pointing to SoAd_EventQueueTpTxSoCon */
  SoAd_FlagOffsetOfEventQueueTpTxSoConConfigType FlagOffsetOfEventQueueTpTxSoConConfig;  /**< the relative offset per instance within the event queue flags array */
  SoAd_LimitOfEventQueueTpTxSoConConfigType LimitOfEventQueueTpTxSoConConfig;  /**< the limit of events handled in a single main function call */
} SoAd_EventQueueTpTxSoConConfigType;

/**   \brief  type used in SoAd_Instance */
typedef struct sSoAd_InstanceType
{
  SoAd_BestMatchSoConIdxListEndIdxOfInstanceType BestMatchSoConIdxListEndIdxOfInstance;  /**< the end index of the 1:n relation pointing to SoAd_BestMatchSoConIdxList */
  SoAd_BestMatchSoConIdxListStartIdxOfInstanceType BestMatchSoConIdxListStartIdxOfInstance;  /**< the start index of the 1:n relation pointing to SoAd_BestMatchSoConIdxList */
  SoAd_EventQueueIdentIdxOfInstanceType EventQueueIdentIdxOfInstance;  /**< the index of the 1:1 relation pointing to SoAd_EventQueueIdent */
  SoAd_IpFragBufConfigEndIdxOfInstanceType IpFragBufConfigEndIdxOfInstance;  /**< the end index of the 0:n relation pointing to SoAd_IpFragBufConfig */
  SoAd_IpFragBufConfigStartIdxOfInstanceType IpFragBufConfigStartIdxOfInstance;  /**< the start index of the 0:n relation pointing to SoAd_IpFragBufConfig */
  SoAd_TimeoutListIdentIdxOfInstanceType TimeoutListIdentIdxOfInstance;  /**< the index of the 1:1 relation pointing to SoAd_TimeoutListIdent */
  SoAd_TriggerBufConfigEndIdxOfInstanceType TriggerBufConfigEndIdxOfInstance;  /**< the end index of the 0:n relation pointing to SoAd_TriggerBufConfig */
  SoAd_TriggerBufConfigStartIdxOfInstanceType TriggerBufConfigStartIdxOfInstance;  /**< the start index of the 0:n relation pointing to SoAd_TriggerBufConfig */
} SoAd_InstanceType;

/**   \brief  type used in SoAd_InstanceDyn */
typedef struct sSoAd_InstanceDynType
{
  SoAd_CounterOfInstanceDynType CounterOfInstanceDyn;  /**< counts the main function cycles (with wrap around) to handle timeouts for the timeout lists */
  SoAd_SizeOfSoConType BestMatchListSizeOfInstanceDyn;  /**< the number of valid socket connections saved in the best match list */
  SoAd_AtomicUint32Type OpenSocksOfInstanceDyn;  /**< the number of open sockets */
} SoAd_InstanceDynType;

/**   \brief  type used in SoAd_InstanceMap */
typedef struct sSoAd_InstanceMapType
{
  SoAd_PartitionSpecificInstanceIdxOfInstanceMapType PartitionSpecificInstanceIdxOfInstanceMap;  /**< the index of the 1:1 relation pointing to one of SoAd_Instance */
  SoAd_PartitionSpecificInstancePartitionIdxOfInstanceMapType PartitionSpecificInstancePartitionIdxOfInstanceMap;  /**< the partition index of the 1:1 relation pointing to one of SoAd_Instance */
} SoAd_InstanceMapType;

/**   \brief  type used in SoAd_IpFragBufConfig */
typedef struct sSoAd_IpFragBufConfigType
{
  SoAd_IpFragBufEndIdxOfIpFragBufConfigType IpFragBufEndIdxOfIpFragBufConfig;  /**< the end index of the 1:n relation pointing to SoAd_IpFragBuf */
  SoAd_IpFragBufStartIdxOfIpFragBufConfigType IpFragBufStartIdxOfIpFragBufConfig;  /**< the start index of the 1:n relation pointing to SoAd_IpFragBuf */
} SoAd_IpFragBufConfigType;

/**   \brief  type used in SoAd_IpFragBufConfigDyn */
typedef struct sSoAd_IpFragBufConfigDynType
{
  SoAd_LengthOfIpFragBufConfigDynType LengthOfIpFragBufConfigDyn;  /**< the length of the used part of the IP fragmentation buffer */
} SoAd_IpFragBufConfigDynType;

/**   \brief  type used in SoAd_IpFragMgt */
typedef struct sSoAd_IpFragMgtType
{
  SoAd_IpFragBufConfigIdxOfIpFragMgtType IpFragBufConfigIdxOfIpFragMgt;  /**< the index of the 1:1 relation pointing to SoAd_IpFragBufConfig */
} SoAd_IpFragMgtType;

/**   \brief  type used in SoAd_LocalAddr */
typedef struct sSoAd_LocalAddrType
{
  SoAd_SoConGrpEndIdxOfLocalAddrType SoConGrpEndIdxOfLocalAddr;  /**< the end index of the 0:n relation pointing to SoAd_SoConGrp */
  SoAd_SoConGrpStartIdxOfLocalAddrType SoConGrpStartIdxOfLocalAddr;  /**< the start index of the 0:n relation pointing to SoAd_SoConGrp */
  SoAd_TcpIpCtrlIdxOfLocalAddrType TcpIpCtrlIdxOfLocalAddr;  /**< the index of the 1:1 relation pointing to SoAd_TcpIpCtrl */
  SoAd_DomainType DomainOfLocalAddr;  /**< the IP domain (IPv4/6) */
  SoAd_LocalAddrIdType AddrIdOfLocalAddr;  /**< the address identifier to identify the local address at TcpIp */
} SoAd_LocalAddrType;

/**   \brief  type used in SoAd_LocalAddrDyn */
typedef struct sSoAd_LocalAddrDynType
{
  SoAd_IpAddrStateType IpAddrStateOfLocalAddrDyn;  /**< the local IP address assignment state */
} SoAd_LocalAddrDynType;

/**   \brief  type used in SoAd_LocalAddrIdMap */
typedef struct sSoAd_LocalAddrIdMapType
{
  SoAd_InvalidHndOfLocalAddrIdMapType InvalidHndOfLocalAddrIdMap;  /**< FALSE, if the handle of SoAd_LocalAddrIdMap is valid and can be used in the embedded code for further processing in the embedded code. */
  SoAd_PartitionSpecificLocalAddrIdxOfLocalAddrIdMapType PartitionSpecificLocalAddrIdxOfLocalAddrIdMap;  /**< the index of the 0:1 relation pointing to SoAd_LocalAddr */
  SoAd_PartitionSpecificLocalAddrPartitionIdxOfLocalAddrIdMapType PartitionSpecificLocalAddrPartitionIdxOfLocalAddrIdMap;  /**< the partition index of the 0:1 relation pointing to SoAd_LocalAddr */
} SoAd_LocalAddrIdMapType;

/**   \brief  type used in SoAd_NPduUdpTx */
typedef struct sSoAd_NPduUdpTxType
{
  SoAd_NPduUdpTxBufferEndIdxOfNPduUdpTxType NPduUdpTxBufferEndIdxOfNPduUdpTx;  /**< the end index of the 0:n relation pointing to SoAd_NPduUdpTxBuffer */
  SoAd_NPduUdpTxBufferStartIdxOfNPduUdpTxType NPduUdpTxBufferStartIdxOfNPduUdpTx;  /**< the start index of the 0:n relation pointing to SoAd_NPduUdpTxBuffer */
  SoAd_NPduUdpTxQueueEndIdxOfNPduUdpTxType NPduUdpTxQueueEndIdxOfNPduUdpTx;  /**< the end index of the 0:n relation pointing to SoAd_NPduUdpTxQueue */
  SoAd_NPduUdpTxQueueStartIdxOfNPduUdpTxType NPduUdpTxQueueStartIdxOfNPduUdpTx;  /**< the start index of the 0:n relation pointing to SoAd_NPduUdpTxQueue */
  SoAd_SoConIdxOfNPduUdpTxType SoConIdxOfNPduUdpTx;  /**< the index of the 1:1 relation pointing to SoAd_SoCon */
} SoAd_NPduUdpTxType;

/**   \brief  type used in SoAd_NPduUdpTxDyn */
typedef struct sSoAd_NPduUdpTxDynType
{
  SoAd_TotalLenOfNPduUdpTxDynType TotalLenOfNPduUdpTxDyn;  /**< the total length of nPdu */
  SoAd_BufLenOfNPduUdpTxDynType BufLenOfNPduUdpTxDyn;  /**< the total length of PDUs stored in buffer if queue is used */
  SoAd_RetryCntOfNPduUdpTxDynType RetryCntOfNPduUdpTxDyn;  /**< the retry counter for queue retransmission */
  SoAd_LvlOfNPduUdpTxDynType LvlOfNPduUdpTxDyn;  /**< the level of PDUs in nPdu */
  SoAd_NPduUdpTxStateType TransmissionStateOfNPduUdpTxDyn;  /**< indicates the current state of transmission */
} SoAd_NPduUdpTxDynType;

/**   \brief  type used in SoAd_NPduUdpTxQueue */
typedef struct sSoAd_NPduUdpTxQueueType
{
  SoAd_LenOfNPduUdpTxQueueType LenOfNPduUdpTxQueue;  /**< the length of PDU */
  SoAd_CopiedOfNPduUdpTxQueueType CopiedOfNPduUdpTxQueue;  /**< indicates if PDU is copied to transmission buffer or sent already */
  SoAd_NPduUdpTxBufferIdxOfNPduUdpTxQueueType NPduUdpTxBufferIdxOfNPduUdpTxQueue;  /**< the index of the 1:1 relation pointing to SoAd_NPduUdpTxBuffer */
  SoAd_PduRouteDestIdxOfNPduUdpTxQueueType PduRouteDestIdxOfNPduUdpTxQueue;  /**< the index of the 0:1 relation pointing to SoAd_PduRouteDest */
} SoAd_NPduUdpTxQueueType;

/**   \brief  type used in SoAd_PartitionDyn */
typedef struct sSoAd_PartitionDynType
{
  SoAd_PartitionStateType InitializedOfPartitionDyn;  /**< initialized state of the partition */
} SoAd_PartitionDynType;

/**   \brief  type used in SoAd_PartitionIdentifiers */
typedef struct sSoAd_PartitionIdentifiersType
{
  SoAd_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
  SoAd_PCPartitionConfigIdxOfPartitionIdentifiersType PCPartitionConfigIdxOfPartitionIdentifiers;  /**< the index of the 1:1 relation pointing to SoAd_PCPartitionConfig */
} SoAd_PartitionIdentifiersType;

/**   \brief  type used in SoAd_PduRoute */
typedef struct sSoAd_PduRouteType
{
  SoAd_TxConfPduIdOfPduRouteType TxConfPduIdOfPduRoute;  /**< the TxPduId used to call upper layer */
  SoAd_AllPduRouteDestWithPduHdrOfPduRouteType AllPduRouteDestWithPduHdrOfPduRoute;  /**< indicates if all related SoAdPduRouteDests have a SoAdTxPduHeaderId */
  SoAd_IfOptimisticTransmitOfPduRouteType IfOptimisticTransmitOfPduRoute;  /**< indicates if IF optimistic transmit is used */
  SoAd_MetaDataTxEnabledOfPduRouteType MetaDataTxEnabledOfPduRoute;  /**< indicates if transmission on specific socket connection via meta data is enabled */
  SoAd_TxConfEnabledOfPduRouteType TxConfEnabledOfPduRoute;  /**< indicates if TxConfirmation is enabled */
  SoAd_TxOptimizedOfPduRouteType TxOptimizedOfPduRoute;  /**< indicates if Tx optimized is enabled */
  SoAd_PduRouteDestEndIdxOfPduRouteType PduRouteDestEndIdxOfPduRoute;  /**< the end index of the 1:n relation pointing to SoAd_PduRouteDest */
  SoAd_PduRouteDestStartIdxOfPduRouteType PduRouteDestStartIdxOfPduRoute;  /**< the start index of the 1:n relation pointing to SoAd_PduRouteDest */
  SoAd_UpperLayerIdxOfPduRouteType UpperLayerIdxOfPduRoute;  /**< the index of the 1:1 relation pointing to SoAd_UpperLayer */
  SoAd_IfTriggerTransmitModeType IfTriggerTransmitModeOfPduRoute;  /**< the trigger transmit mode */
  SoAd_UpperLayerApiType UpperLayerApiOfPduRoute;  /**< the upper layer API type (IF/TP) */
} SoAd_PduRouteType;

/**   \brief  type used in SoAd_PduRouteDest */
typedef struct sSoAd_PduRouteDestType
{
  SoAd_TxPduHdrIdOfPduRouteDestType TxPduHdrIdOfPduRouteDest;  /**< the PDU header ID */
  SoAd_PduRouteIdxOfPduRouteDestType PduRouteIdxOfPduRouteDest;  /**< the index of the 1:1 relation pointing to SoAd_PduRoute */
  SoAd_RouteGrpSoConByPduRouteDestIndEndIdxOfPduRouteDestType RouteGrpSoConByPduRouteDestIndEndIdxOfPduRouteDest;  /**< the end index of the 0:n relation pointing to SoAd_RouteGrpSoConByPduRouteDestInd */
  SoAd_RouteGrpSoConByPduRouteDestIndStartIdxOfPduRouteDestType RouteGrpSoConByPduRouteDestIndStartIdxOfPduRouteDest;  /**< the start index of the 0:n relation pointing to SoAd_RouteGrpSoConByPduRouteDestInd */
  SoAd_SoConIdxOfPduRouteDestType SoConIdxOfPduRouteDest;  /**< the index of the 1:1 relation pointing to SoAd_SoCon */
  SoAd_UdpTriggerTimeoutOfPduRouteDestType UdpTriggerTimeoutOfPduRouteDest;  /**< the PduRouteDest specific timeout to send a nPdu */
  SoAd_TxUdpTriggerModeType TxUdpTriggerModeOfPduRouteDest;  /**< indicates if nPdu shall be sent on transmission request always or never */
} SoAd_PduRouteDestType;

/**   \brief  type used in SoAd_PduRouteDyn */
typedef struct sSoAd_PduRouteDynType
{
  SoAd_PendingTxConfMainOfPduRouteDynType PendingTxConfMainOfPduRouteDyn;  /**< indicates if transmission confirmation in main function context is pending */
  SoAd_SizeOfPduRouteDestType PendingTxConfNumOfPduRouteDyn;  /**< the number of pending transmission confirmation */
} SoAd_PduRouteDynType;

/**   \brief  type used in SoAd_RemAddrIpV4 */
typedef struct sSoAd_RemAddrIpV4Type
{
  SoAd_IpAddrInetType AddrOfRemAddrIpV4;  /**< the remote IPv4 address */
  SoAd_PortType PortOfRemAddrIpV4;  /**< the remote port */
} SoAd_RemAddrIpV4Type;

/**   \brief  type used in SoAd_RemAddrIpV6 */
typedef struct sSoAd_RemAddrIpV6Type
{
  SoAd_IpAddrInet6Type AddrOfRemAddrIpV6;  /**< the remote IPv6 address */
  SoAd_PortType PortOfRemAddrIpV6;  /**< the remote port */
} SoAd_RemAddrIpV6Type;

/**   \brief  type used in SoAd_RouteGrp */
typedef struct sSoAd_RouteGrpType
{
  SoAd_EnabledAtInitOfRouteGrpType EnabledAtInitOfRouteGrp;  /**< indicates if RoutingGroup is initially enabled */
  SoAd_MultiInstanceOnGrpOfRouteGrpType MultiInstanceOnGrpOfRouteGrp;  /**< indicates if RoutingGroup is used for the multi service instance use case on socket connection groups */
  SoAd_RxRequestEnableOfRouteGrpType RxRequestEnableOfRouteGrp;  /**< indicates if RoutingGroup can be requested to be enabled on reception (via Sd_RequestRoutingGroupEnable) */
  SoAd_TxTriggerableOfRouteGrpType TxTriggerableOfRouteGrp;  /**< indicates if RoutingGroup can be sent */
  SoAd_PduRouteDestIndEndIdxOfRouteGrpType PduRouteDestIndEndIdxOfRouteGrp;  /**< the end index of the 0:n relation pointing to SoAd_PduRouteDestInd */
  SoAd_PduRouteDestIndStartIdxOfRouteGrpType PduRouteDestIndStartIdxOfRouteGrp;  /**< the start index of the 0:n relation pointing to SoAd_PduRouteDestInd */
  SoAd_RouteGrpIdOfRouteGrpType RouteGrpIdOfRouteGrp;  /**< the Routing Group identifier used in SoAd API */
  SoAd_RouteGrpSoConEndIdxOfRouteGrpType RouteGrpSoConEndIdxOfRouteGrp;  /**< the end index of the 1:n relation pointing to SoAd_RouteGrpSoCon */
  SoAd_RouteGrpSoConStartIdxOfRouteGrpType RouteGrpSoConStartIdxOfRouteGrp;  /**< the start index of the 1:n relation pointing to SoAd_RouteGrpSoCon */
  SoAd_SocketRouteIndEndIdxOfRouteGrpType SocketRouteIndEndIdxOfRouteGrp;  /**< the end index of the 0:n relation pointing to SoAd_SocketRouteInd */
  SoAd_SocketRouteIndStartIdxOfRouteGrpType SocketRouteIndStartIdxOfRouteGrp;  /**< the start index of the 0:n relation pointing to SoAd_SocketRouteInd */
} SoAd_RouteGrpType;

/**   \brief  type used in SoAd_RouteGrpIdMap */
typedef struct sSoAd_RouteGrpIdMapType
{
  SoAd_InvalidHndOfRouteGrpIdMapType InvalidHndOfRouteGrpIdMap;  /**< FALSE, if the handle of SoAd_RouteGrpIdMap is valid and can be used in the embedded code for further processing in the embedded code. */
  SoAd_PartitionSpecificRouteGrpIdxOfRouteGrpIdMapType PartitionSpecificRouteGrpIdxOfRouteGrpIdMap;  /**< the index of the 0:1 relation pointing to SoAd_RouteGrp */
  SoAd_PartitionSpecificRouteGrpPartitionIdxOfRouteGrpIdMapType PartitionSpecificRouteGrpPartitionIdxOfRouteGrpIdMap;  /**< the partition index of the 0:1 relation pointing to SoAd_RouteGrp */
} SoAd_RouteGrpIdMapType;

/**   \brief  type used in SoAd_RouteGrpSoCon */
typedef struct sSoAd_RouteGrpSoConType
{
  SoAd_RouteGrpIdxOfRouteGrpSoConType RouteGrpIdxOfRouteGrpSoCon;  /**< the index of the 1:1 relation pointing to SoAd_RouteGrp */
  SoAd_SoConIdxOfRouteGrpSoConType SoConIdxOfRouteGrpSoCon;  /**< the index of the 1:1 relation pointing to SoAd_SoCon */
} SoAd_RouteGrpSoConType;

/**   \brief  type used in SoAd_RouteGrpSoConDyn */
typedef struct sSoAd_RouteGrpSoConDynType
{
  SoAd_EnabledOfRouteGrpSoConDynType EnabledOfRouteGrpSoConDyn;  /**< the routing group state on the socket connection */
  SoAd_FlagsOfRouteGrpSoConDynType FlagsOfRouteGrpSoConDyn;  /**< the current state of routing group transmission for socket connection: flag 0 = Tx active, flag 1 = Tx processed */
} SoAd_RouteGrpSoConDynType;

/**   \brief  type used in SoAd_RxBufStructMgt */
typedef struct sSoAd_RxBufStructMgtType
{
  SoAd_RxBufStructSegIdxOfRxBufStructMgtType RxBufStructSegIdxOfRxBufStructMgt;  /**< the index of the 1:1 relation pointing to SoAd_RxBufStructSeg */
  SoAd_RxBufStructSegLvlOfRxBufStructMgtType RxBufStructSegLvlOfRxBufStructMgt;  /**< the lvl of used SoAd_RxBufStructSegs */
} SoAd_RxBufStructMgtType;

/**   \brief  type used in SoAd_RxBufStructSeg */
typedef struct sSoAd_RxBufStructSegType
{
  SoAd_LenOfRxBufStructSegType LenOfRxBufStructSeg;  /**< the length of segment */
  SoAd_DataPtrType DataPtrOfRxBufStructSeg;  /**< the pointer to segment data */
} SoAd_RxBufStructSegType;

/**   \brief  type used in SoAd_RxBufferConfig */
typedef struct sSoAd_RxBufferConfigType
{
  SoAd_IfRxBufferEndIdxOfRxBufferConfigType IfRxBufferEndIdxOfRxBufferConfig;  /**< the end index of the 0:n relation pointing to SoAd_IfRxBuffer */
  SoAd_IfRxBufferStartIdxOfRxBufferConfigType IfRxBufferStartIdxOfRxBufferConfig;  /**< the start index of the 0:n relation pointing to SoAd_IfRxBuffer */
  SoAd_MetaDataRxBufferEndIdxOfRxBufferConfigType MetaDataRxBufferEndIdxOfRxBufferConfig;  /**< the end index of the 0:n relation pointing to SoAd_MetaDataRxBuffer */
  SoAd_MetaDataRxBufferStartIdxOfRxBufferConfigType MetaDataRxBufferStartIdxOfRxBufferConfig;  /**< the start index of the 0:n relation pointing to SoAd_MetaDataRxBuffer */
  SoAd_TpRxBufferEndIdxOfRxBufferConfigType TpRxBufferEndIdxOfRxBufferConfig;  /**< the end index of the 0:n relation pointing to SoAd_TpRxBuffer */
  SoAd_TpRxBufferStartIdxOfRxBufferConfigType TpRxBufferStartIdxOfRxBufferConfig;  /**< the start index of the 0:n relation pointing to SoAd_TpRxBuffer */
} SoAd_RxBufferConfigType;

/**   \brief  type used in SoAd_RxBufferConfigDyn */
typedef struct sSoAd_RxBufferConfigDynType
{
  SoAd_IfRxBufferIdxOfRxBufferConfigDynType IfRxBufferIdxOfRxBufferConfigDyn;  /**< the index of the 0:1 relation pointing to SoAd_IfRxBuffer */
  SoAd_TpRxBufferIdxOfRxBufferConfigDynType TpRxBufferIdxOfRxBufferConfigDyn;  /**< the index of the 0:1 relation pointing to SoAd_TpRxBuffer */
} SoAd_RxBufferConfigDynType;

/**   \brief  type used in SoAd_RxMgt */
typedef struct sSoAd_RxMgtType
{
  SoAd_RxBytesPendingOfRxMgtType RxBytesPendingOfRxMgt;  /**< the length of pending data to be received */
  SoAd_CancelRequestedOfRxMgtType CancelRequestedOfRxMgt;  /**< indicates if reception cancellation is requested */
  SoAd_SocketRouteDestIdxOfRxMgtType SocketRouteDestIdxOfRxMgt;  /**< the index of the 1:1 relation pointing to SoAd_SocketRouteDest */
} SoAd_RxMgtType;

/**   \brief  type used in SoAd_RxPduIdIdMap */
typedef struct sSoAd_RxPduIdIdMapType
{
  SoAd_InvalidHndOfRxPduIdIdMapType InvalidHndOfRxPduIdIdMap;  /**< FALSE, if the handle of SoAd_RxPduIdIdMap is valid and can be used in the embedded code for further processing in the embedded code. */
  SoAd_PartitionSpecificSocketRouteDestIdxOfRxPduIdIdMapType PartitionSpecificSocketRouteDestIdxOfRxPduIdIdMap;  /**< the index of the 1:1 relation pointing to one of SoAd_SocketRouteDest */
  SoAd_PartitionSpecificSocketRouteDestPartitionIdxOfRxPduIdIdMapType PartitionSpecificSocketRouteDestPartitionIdxOfRxPduIdIdMap;  /**< the partition index of the 1:1 relation pointing to one of SoAd_SocketRouteDest */
} SoAd_RxPduIdIdMapType;

/**   \brief  type used in SoAd_SoCon */
typedef struct sSoAd_SoConType
{
  SoAd_IpFragMgtIdxOfSoConType IpFragMgtIdxOfSoCon;  /**< the index of the 0:1 relation pointing to SoAd_IpFragMgt */
  SoAd_LocalIpAddrAssignmentChgCbkIndEndIdxOfSoConType LocalIpAddrAssignmentChgCbkIndEndIdxOfSoCon;  /**< the end index of the 0:n relation pointing to SoAd_LocalIpAddrAssignmentChgCbkInd */
  SoAd_LocalIpAddrAssignmentChgCbkIndStartIdxOfSoConType LocalIpAddrAssignmentChgCbkIndStartIdxOfSoCon;  /**< the start index of the 0:n relation pointing to SoAd_LocalIpAddrAssignmentChgCbkInd */
  SoAd_NPduUdpTxIdxOfSoConType NPduUdpTxIdxOfSoCon;  /**< the index of the 0:1 relation pointing to SoAd_NPduUdpTx */
  SoAd_PduRouteDestBySoConIndEndIdxOfSoConType PduRouteDestBySoConIndEndIdxOfSoCon;  /**< the end index of the 0:n relation pointing to SoAd_PduRouteDestBySoConInd */
  SoAd_PduRouteDestBySoConIndStartIdxOfSoConType PduRouteDestBySoConIndStartIdxOfSoCon;  /**< the start index of the 0:n relation pointing to SoAd_PduRouteDestBySoConInd */
  SoAd_RemAddrIpV4IdxOfSoConType RemAddrIpV4IdxOfSoCon;  /**< the index of the 0:1 relation pointing to SoAd_RemAddrIpV4 */
  SoAd_RemAddrIpV6IdxOfSoConType RemAddrIpV6IdxOfSoCon;  /**< the index of the 0:1 relation pointing to SoAd_RemAddrIpV6 */
  SoAd_RemAddrRcvIdxOfSoConType RemAddrRcvIdxOfSoCon;  /**< the index of the 0:1 relation pointing to SoAd_RemAddrRcv */
  SoAd_RxBufStructMgtIdxOfSoConType RxBufStructMgtIdxOfSoCon;  /**< the index of the 0:1 relation pointing to SoAd_RxBufStructMgt */
  SoAd_RxBufStructSegEndIdxOfSoConType RxBufStructSegEndIdxOfSoCon;  /**< the end index of the 0:n relation pointing to SoAd_RxBufStructSeg */
  SoAd_RxBufStructSegStartIdxOfSoConType RxBufStructSegStartIdxOfSoCon;  /**< the start index of the 0:n relation pointing to SoAd_RxBufStructSeg */
  SoAd_RxBufferConfigIdxOfSoConType RxBufferConfigIdxOfSoCon;  /**< the index of the 0:1 relation pointing to SoAd_RxBufferConfig */
  SoAd_RxMgtIdxOfSoConType RxMgtIdxOfSoCon;  /**< the index of the 0:1 relation pointing to SoAd_RxMgt */
  SoAd_SoConGrpIdxOfSoConType SoConGrpIdxOfSoCon;  /**< the index of the 1:1 relation pointing to SoAd_SoConGrp */
  SoAd_SoConIdOfSoConType SoConIdOfSoCon;  /**< the SocketConnection identifier used in SoAd API */
  SoAd_SoConModeChgCbkIndEndIdxOfSoConType SoConModeChgCbkIndEndIdxOfSoCon;  /**< the end index of the 0:n relation pointing to SoAd_SoConModeChgCbkInd */
  SoAd_SoConModeChgCbkIndStartIdxOfSoConType SoConModeChgCbkIndStartIdxOfSoCon;  /**< the start index of the 0:n relation pointing to SoAd_SoConModeChgCbkInd */
  SoAd_SocketIdxOfSoConType SocketIdxOfSoCon;  /**< the index of the 1:1 relation pointing to SoAd_Socket */
  SoAd_SocketRouteEndIdxOfSoConType SocketRouteEndIdxOfSoCon;  /**< the end index of the 0:n relation pointing to SoAd_SocketRoute */
  SoAd_SocketRouteStartIdxOfSoConType SocketRouteStartIdxOfSoCon;  /**< the start index of the 0:n relation pointing to SoAd_SocketRoute */
  SoAd_TcpTxQueueIdxOfSoConType TcpTxQueueIdxOfSoCon;  /**< the index of the 0:1 relation pointing to SoAd_TcpTxQueue */
  SoAd_TpTxBufferConfigIdxOfSoConType TpTxBufferConfigIdxOfSoCon;  /**< the index of the 0:1 relation pointing to SoAd_TpTxBufferConfig */
  SoAd_TxMgtIdxOfSoConType TxMgtIdxOfSoCon;  /**< the index of the 0:1 relation pointing to SoAd_TxMgt */
  SoAd_RemAddrStateType RemAddrCfgStateOfSoCon;  /**< the configured remote address state */
} SoAd_SoConType;

/**   \brief  type used in SoAd_SoConDyn */
typedef struct sSoAd_SoConDynType
{
  SoAd_OpenCloseCounterOfSoConDynType OpenCloseCounterOfSoConDyn;  /**< the open and close sequence counter */
  SoAd_AbortOfSoConDynType AbortOfSoConDyn;  /**< indicates if abort is requested */
  SoAd_RxActiveOfSoConDynType RxActiveOfSoConDyn;  /**< indicates if reception is active on any SocketRoute of the socket connection */
  SoAd_TimeoutOccurredOfSoConDynType TimeoutOccurredOfSoConDyn;  /**< indicates if timeout occurred while trying to open the socket connection */
  SoAd_TxActiveOfSoConDynType TxActiveOfSoConDyn;  /**< indicates if transmission is active on any PduRoute of the socket connection */
  SoAd_SoConCloseModeType CloseModeOfSoConDyn;  /**< the mode of socket connection */
  SoAd_SoConModeType ModeOfSoConDyn;  /**< the mode of socket connection */
  SoAd_SockAddrInetXType RemAddrDynOfSoConDyn;  /**< the remote address for each socket connection */
  SoAd_RemAddrReleaseStateType RemAddrReleaseOfSoConDyn;  /**< indicates if release of remote address is requested */
  SoAd_RemAddrStateType RemAddrStateDynOfSoConDyn;  /**< the remote address state on socket connection */
} SoAd_SoConDynType;

/**   \brief  type used in SoAd_SoConGrp */
typedef struct sSoAd_SoConGrpType
{
  SoAd_BestMatchWithPduHeaderEnabledOfSoConGrpType BestMatchWithPduHeaderEnabledOfSoConGrp;  /**< indicates if best match algorithm considers PDU Header ID */
  SoAd_BestMatchWithSockRouteEnabledOfSoConGrpType BestMatchWithSockRouteEnabledOfSoConGrp;  /**< indicates if best match algorithm considers socket route availability */
  SoAd_MsgAcceptFilterEnabledOfSoConGrpType MsgAcceptFilterEnabledOfSoConGrp;  /**< indicates if message acceptance filter is enabled */
  SoAd_PduHdrEnabledOfSoConGrpType PduHdrEnabledOfSoConGrp;  /**< indicates if PDU header is enabled */
  SoAd_SockAutoSoConSetupOfSoConGrpType SockAutoSoConSetupOfSoConGrp;  /**< indicates if automatic socket connection setup is enabled */
  SoAd_SockAutoSoConSetupKeepOnlineOfSoConGrpType SockAutoSoConSetupKeepOnlineOfSoConGrp;  /**< indicates if it is enabled that socket connection stays online after transmission */
  SoAd_FramePriorityOfSoConGrpType FramePriorityOfSoConGrp;  /**< the frame priority (VLAN) */
  SoAd_InstanceIdxOfSoConGrpType InstanceIdxOfSoConGrp;  /**< the index of the 1:1 relation pointing to SoAd_Instance */
  SoAd_LocalAddrIdxOfSoConGrpType LocalAddrIdxOfSoConGrp;  /**< the index of the 0:1 relation pointing to SoAd_LocalAddr */
  SoAd_SoConEndIdxOfSoConGrpType SoConEndIdxOfSoConGrp;  /**< the end index of the 1:n relation pointing to SoAd_SoCon */
  SoAd_SoConStartIdxOfSoConGrpType SoConStartIdxOfSoConGrp;  /**< the start index of the 1:n relation pointing to SoAd_SoCon */
  SoAd_SocketIdxOfSoConGrpType SocketIdxOfSoConGrp;  /**< the index of the 0:1 relation pointing to SoAd_Socket */
  SoAd_SocketTcpIdxOfSoConGrpType SocketTcpIdxOfSoConGrp;  /**< the index of the 0:1 relation pointing to SoAd_SocketTcp */
  SoAd_SocketUdpIdxOfSoConGrpType SocketUdpIdxOfSoConGrp;  /**< the index of the 0:1 relation pointing to SoAd_SocketUdp */
  SoAd_PortType LocalPortOfSoConGrp;  /**< the local port */
  SoAd_SomeIpSdMeasurementDataType MeasurementDataSomeIpSdTypeOfSoConGrp;  /**< indicates if SOME/IP SD data is measured */
} SoAd_SoConGrpType;

/**   \brief  type used in SoAd_SoConMap */
typedef struct sSoAd_SoConMapType
{
  SoAd_InvalidHndOfSoConMapType InvalidHndOfSoConMap;  /**< FALSE, if the handle of SoAd_SoConMap is valid and can be used in the embedded code for further processing in the embedded code. */
  SoAd_PartitionSpecificSoConIdxOfSoConMapType PartitionSpecificSoConIdxOfSoConMap;  /**< the index of the 1:1 relation pointing to one of SoAd_SoCon */
  SoAd_PartitionSpecificSoConPartitionIdxOfSoConMapType PartitionSpecificSoConPartitionIdxOfSoConMap;  /**< the partition index of the 1:1 relation pointing to one of SoAd_SoCon */
} SoAd_SoConMapType;

/**   \brief  type used in SoAd_Socket */
typedef struct sSoAd_SocketType
{
  SoAd_SoConEndIdxOfSocketType SoConEndIdxOfSocket;  /**< the end index of the 1:n relation pointing to SoAd_SoCon */
  SoAd_SoConStartIdxOfSocketType SoConStartIdxOfSocket;  /**< the start index of the 1:n relation pointing to SoAd_SoCon */
} SoAd_SocketType;

/**   \brief  type used in SoAd_SocketDyn */
typedef struct sSoAd_SocketDynType
{
  SoAd_SkipBytesOfSocketDynType SkipBytesOfSocketDyn;  /**< the number of bytes to be skipped */
  SoAd_SoConTxActiveIdxOfSocketDynType SoConTxActiveIdxOfSocketDyn;  /**< the index of the 0:1 relation pointing to SoAd_SoCon */
  SoAd_PortType LocalPortOfSocketDyn;  /**< the local port */
  SoAd_SocketIdType SocketIdOfSocketDyn;  /**< the socket identifier */
  SoAd_SockStateType StateOfSocketDyn;  /**< the socket state */
} SoAd_SocketDynType;

/**   \brief  type used in SoAd_SocketRoute */
typedef struct sSoAd_SocketRouteType
{
  SoAd_RxPduHdrMethodIdOfSocketRouteType RxPduHdrMethodIdOfSocketRoute;  /**< the PDU header Method ID */
  SoAd_RxPduHdrServiceIdOfSocketRouteType RxPduHdrServiceIdOfSocketRoute;  /**< the PDU header Service ID */
  SoAd_MetaDataRxEnabledOfSocketRouteType MetaDataRxEnabledOfSocketRoute;  /**< indicates if SoConId is forwarded as meta data on reception */
  SoAd_SoConIdxOfSocketRouteType SoConIdxOfSocketRoute;  /**< the index of the 1:1 relation pointing to SoAd_SoCon */
  SoAd_SocketRouteDestEndIdxOfSocketRouteType SocketRouteDestEndIdxOfSocketRoute;  /**< the end index of the 1:n relation pointing to SoAd_SocketRouteDest */
  SoAd_SocketRouteDestStartIdxOfSocketRouteType SocketRouteDestStartIdxOfSocketRoute;  /**< the start index of the 1:n relation pointing to SoAd_SocketRouteDest */
  SoAd_UpperLayerApiType UpperLayerApiOfSocketRoute;  /**< the upper layer API type (IF/TP) */
} SoAd_SocketRouteType;

/**   \brief  type used in SoAd_SocketRouteDest */
typedef struct sSoAd_SocketRouteDestType
{
  SoAd_RxPduIdOfSocketRouteDestType RxPduIdOfSocketRouteDest;  /**< the RxPduId used to call the upper layer */
  SoAd_RouteGrpSoConBySocketRouteDestIndEndIdxOfSocketRouteDestType RouteGrpSoConBySocketRouteDestIndEndIdxOfSocketRouteDest;  /**< the end index of the 0:n relation pointing to SoAd_RouteGrpSoConBySocketRouteDestInd */
  SoAd_RouteGrpSoConBySocketRouteDestIndStartIdxOfSocketRouteDestType RouteGrpSoConBySocketRouteDestIndStartIdxOfSocketRouteDest;  /**< the start index of the 0:n relation pointing to SoAd_RouteGrpSoConBySocketRouteDestInd */
  SoAd_SocketRouteIdxOfSocketRouteDestType SocketRouteIdxOfSocketRouteDest;  /**< the index of the 1:1 relation pointing to SoAd_SocketRoute */
  SoAd_UpperLayerIdxOfSocketRouteDestType UpperLayerIdxOfSocketRouteDest;  /**< the index of the 1:1 relation pointing to SoAd_UpperLayer */
} SoAd_SocketRouteDestType;

/**   \brief  type used in SoAd_SocketTcp */
typedef struct sSoAd_SocketTcpType
{
  SoAd_ImmedTpTxConfOfSocketTcpType ImmedTpTxConfOfSocketTcp;  /**< indicates if TP immediate TxConfirmation is used */
  SoAd_TcpInitiateOfSocketTcpType TcpInitiateOfSocketTcp;  /**< indicates if TCP connection is initiated by SoAd */
  SoAd_TcpKeepAliveOfSocketTcpType TcpKeepAliveOfSocketTcp;  /**< indicates if keepalive mechanism is used */
  SoAd_TcpKeepAliveIntervalOfSocketTcpType TcpKeepAliveIntervalOfSocketTcp;  /**< the interval time between keepalive probes */
  SoAd_TcpKeepAliveProbesMaxOfSocketTcpType TcpKeepAliveProbesMaxOfSocketTcp;  /**< the maximum number of keepalive probes */
  SoAd_TcpKeepAliveTimeOfSocketTcpType TcpKeepAliveTimeOfSocketTcp;  /**< the time between the last data packet sent and the first keepalive probe */
  SoAd_TcpMslOfSocketTcpType TcpMslOfSocketTcp;  /**< the socket specific maximum segment lifetime */
  SoAd_TcpRxBufMinOfSocketTcpType TcpRxBufMinOfSocketTcp;  /**< the size of TCP reception buffer */
  SoAd_TcpTlsConIdOfSocketTcpType TcpTlsConIdOfSocketTcp;  /**< identifier of the TCP TLS connection */
  SoAd_TcpTxBufMinOfSocketTcpType TcpTxBufMinOfSocketTcp;  /**< the size of TCP transmission buffer */
  SoAd_TcpNoDelayType TcpNoDelayOfSocketTcp;  /**< indicates not to use the congestion control mechanism */
} SoAd_SocketTcpType;

/**   \brief  type used in SoAd_SocketUdp */
typedef struct sSoAd_SocketUdpType
{
  SoAd_AliveTimeoutMaxCntOfSocketUdpType AliveTimeoutMaxCntOfSocketUdp;  /**< the time a connection remains online after the last reception */
  SoAd_ChecksumChangeEnabledOfSocketUdpType ChecksumChangeEnabledOfSocketUdp;  /**< indicates if UDP checksum calculation setting shall be changed */
  SoAd_ChecksumEnabledOfSocketUdpType ChecksumEnabledOfSocketUdp;  /**< indicates if UDP checksum calculation shall be enabled */
  SoAd_ImmedIfTxConfOfSocketUdpType ImmedIfTxConfOfSocketUdp;  /**< indicates if immediate TxConfirmation is used */
  SoAd_UdpListenOnlyOfSocketUdpType UdpListenOnlyOfSocketUdp;  /**< indicates if the socket is used for reception only */
  SoAd_UdpStrictHdrLenCheckEnabledOfSocketUdpType UdpStrictHdrLenCheckEnabledOfSocketUdp;  /**< indicates if UDP messages shall be dropped dependent on header length check */
  SoAd_ImmedIfTxConfListSizeOfSocketUdpType ImmedIfTxConfListSizeOfSocketUdp;  /**< the list size to handle UDP transmissions with immediate TxConfirmation */
  SoAd_NPduUdpTxBufferMinOfSocketUdpType NPduUdpTxBufferMinOfSocketUdp;  /**< the amount of data in bytes that SoAd is able to buffer */
  SoAd_NPduUdpTxQueueSizeOfSocketUdpType NPduUdpTxQueueSizeOfSocketUdp;  /**< the size of the management queue */
  SoAd_RetryQueueLimitOfSocketUdpType RetryQueueLimitOfSocketUdp;  /**< the limitation of maximum used UDP transmission retry queue elements for this socket */
  SoAd_UdpTriggerTimeoutOfSocketUdpType UdpTriggerTimeoutOfSocketUdp;  /**< the time to wait for a PDU with TriggerMode = TRIGGER_ALWAYS before nPduUdpTxBuffer is transmitted */
} SoAd_SocketUdpType;

/**   \brief  type used in SoAd_TcpIpCtrl */
typedef struct sSoAd_TcpIpCtrlType
{
  SoAd_RetryEnabledOfTcpIpCtrlType RetryEnabledOfTcpIpCtrl;  /**< indicates if transmission retry is available on controller/interface */
  SoAd_LocalAddrByTcpIpCtrlIndEndIdxOfTcpIpCtrlType LocalAddrByTcpIpCtrlIndEndIdxOfTcpIpCtrl;  /**< the end index of the 0:n relation pointing to SoAd_LocalAddrByTcpIpCtrlInd */
  SoAd_LocalAddrByTcpIpCtrlIndStartIdxOfTcpIpCtrlType LocalAddrByTcpIpCtrlIndStartIdxOfTcpIpCtrl;  /**< the start index of the 0:n relation pointing to SoAd_LocalAddrByTcpIpCtrlInd */
} SoAd_TcpIpCtrlType;

/**   \brief  type used in SoAd_TcpTxQueue */
typedef struct sSoAd_TcpTxQueueType
{
  SoAd_TcpTxQueueDataEndIdxOfTcpTxQueueType TcpTxQueueDataEndIdxOfTcpTxQueue;  /**< the end index of the 1:n relation pointing to SoAd_TcpTxQueueData */
  SoAd_TcpTxQueueDataStartIdxOfTcpTxQueueType TcpTxQueueDataStartIdxOfTcpTxQueue;  /**< the start index of the 1:n relation pointing to SoAd_TcpTxQueueData */
} SoAd_TcpTxQueueType;

/**   \brief  type used in SoAd_TcpTxQueueData */
typedef struct sSoAd_TcpTxQueueDataType
{
  SoAd_LenOfTcpTxQueueDataType LenOfTcpTxQueueData;  /**< the length of the queue element */
  SoAd_PduRouteIdxOfTcpTxQueueDataType PduRouteIdxOfTcpTxQueueData;  /**< the index of the 1:1 relation pointing to SoAd_PduRoute */
} SoAd_TcpTxQueueDataType;

/**   \brief  type used in SoAd_TcpTxQueueMgt */
typedef struct sSoAd_TcpTxQueueMgtType
{
  SoAd_TotLenOfTcpTxQueueMgtType TotLenOfTcpTxQueueMgt;  /**< the total length of all used elements */
  SoAd_LvlOfTcpTxQueueMgtType LvlOfTcpTxQueueMgt;  /**< the level of used elements */
  SoAd_TcpTxQueueDataIdxOfTcpTxQueueMgtType TcpTxQueueDataIdxOfTcpTxQueueMgt;  /**< the index of the 1:1 relation pointing to SoAd_TcpTxQueueData */
} SoAd_TcpTxQueueMgtType;

/**   \brief  type used in SoAd_TimeoutListIdent */
typedef struct sSoAd_TimeoutListIdentType
{
  SoAd_TimeoutListNPduUdpTxConfigIdxOfTimeoutListIdentType TimeoutListNPduUdpTxConfigIdxOfTimeoutListIdent;  /**< the index of the 0:1 relation pointing to SoAd_TimeoutListNPduUdpTxConfig */
  SoAd_TimeoutListTcpAutoConnectConfigIdxOfTimeoutListIdentType TimeoutListTcpAutoConnectConfigIdxOfTimeoutListIdent;  /**< the index of the 0:1 relation pointing to SoAd_TimeoutListTcpAutoConnectConfig */
  SoAd_TimeoutListUdpAliveConfigIdxOfTimeoutListIdentType TimeoutListUdpAliveConfigIdxOfTimeoutListIdent;  /**< the index of the 0:1 relation pointing to SoAd_TimeoutListUdpAliveConfig */
} SoAd_TimeoutListIdentType;

/**   \brief  type used in SoAd_TimeoutListMgmt */
typedef struct sSoAd_TimeoutListMgmtType
{
  SoAd_LvlOfTimeoutListMgmtType LvlOfTimeoutListMgmt;  /**< the level of pending timeouts */
} SoAd_TimeoutListMgmtType;

/**   \brief  type used in SoAd_TimeoutListNPduUdpTx */
typedef struct sSoAd_TimeoutListNPduUdpTxType
{
  SoAd_TimeoutOfTimeoutListNPduUdpTxType TimeoutOfTimeoutListNPduUdpTx;  /**< the timeout value */
  SoAd_NPduUdpTxIdxOfTimeoutListNPduUdpTxType NPduUdpTxIdxOfTimeoutListNPduUdpTx;  /**< the index of the 0:1 relation pointing to SoAd_NPduUdpTx */
} SoAd_TimeoutListNPduUdpTxType;

/**   \brief  type used in SoAd_TimeoutListNPduUdpTxConfig */
typedef struct sSoAd_TimeoutListNPduUdpTxConfigType
{
  SoAd_TimeoutListMgmtIdxOfTimeoutListNPduUdpTxConfigType TimeoutListMgmtIdxOfTimeoutListNPduUdpTxConfig;  /**< the index of the 1:1 relation pointing to SoAd_TimeoutListMgmt */
  SoAd_TimeoutListNPduUdpTxEndIdxOfTimeoutListNPduUdpTxConfigType TimeoutListNPduUdpTxEndIdxOfTimeoutListNPduUdpTxConfig;  /**< the end index of the 1:n relation pointing to SoAd_TimeoutListNPduUdpTx */
  SoAd_TimeoutListNPduUdpTxStartIdxOfTimeoutListNPduUdpTxConfigType TimeoutListNPduUdpTxStartIdxOfTimeoutListNPduUdpTxConfig;  /**< the start index of the 1:n relation pointing to SoAd_TimeoutListNPduUdpTx */
} SoAd_TimeoutListNPduUdpTxConfigType;

/**   \brief  type used in SoAd_TimeoutListNPduUdpTxMap */
typedef struct sSoAd_TimeoutListNPduUdpTxMapType
{
  SoAd_TimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMapType TimeoutListNPduUdpTxIdxOfTimeoutListNPduUdpTxMap;  /**< the index of the 0:1 relation pointing to SoAd_TimeoutListNPduUdpTx */
} SoAd_TimeoutListNPduUdpTxMapType;

/**   \brief  type used in SoAd_TimeoutListTcpAutoConnectConfig */
typedef struct sSoAd_TimeoutListTcpAutoConnectConfigType
{
  SoAd_TimeoutListMgmtIdxOfTimeoutListTcpAutoConnectConfigType TimeoutListMgmtIdxOfTimeoutListTcpAutoConnectConfig;  /**< the index of the 1:1 relation pointing to SoAd_TimeoutListMgmt */
} SoAd_TimeoutListTcpAutoConnectConfigType;

/**   \brief  type used in SoAd_TimeoutListUdpAlive */
typedef struct sSoAd_TimeoutListUdpAliveType
{
  SoAd_TimeoutOfTimeoutListUdpAliveType TimeoutOfTimeoutListUdpAlive;  /**< the timeout value */
  SoAd_SoConIdxOfTimeoutListUdpAliveType SoConIdxOfTimeoutListUdpAlive;  /**< the index of the 0:1 relation pointing to SoAd_SoCon */
} SoAd_TimeoutListUdpAliveType;

/**   \brief  type used in SoAd_TimeoutListUdpAliveConfig */
typedef struct sSoAd_TimeoutListUdpAliveConfigType
{
  SoAd_TimeoutListMgmtIdxOfTimeoutListUdpAliveConfigType TimeoutListMgmtIdxOfTimeoutListUdpAliveConfig;  /**< the index of the 1:1 relation pointing to SoAd_TimeoutListMgmt */
  SoAd_TimeoutListUdpAliveEndIdxOfTimeoutListUdpAliveConfigType TimeoutListUdpAliveEndIdxOfTimeoutListUdpAliveConfig;  /**< the end index of the 1:n relation pointing to SoAd_TimeoutListUdpAlive */
  SoAd_TimeoutListUdpAliveStartIdxOfTimeoutListUdpAliveConfigType TimeoutListUdpAliveStartIdxOfTimeoutListUdpAliveConfig;  /**< the start index of the 1:n relation pointing to SoAd_TimeoutListUdpAlive */
} SoAd_TimeoutListUdpAliveConfigType;

/**   \brief  type used in SoAd_TimeoutListUdpAliveMap */
typedef struct sSoAd_TimeoutListUdpAliveMapType
{
  SoAd_TimeoutListUdpAliveIdxOfTimeoutListUdpAliveMapType TimeoutListUdpAliveIdxOfTimeoutListUdpAliveMap;  /**< the index of the 0:1 relation pointing to SoAd_TimeoutListUdpAlive */
} SoAd_TimeoutListUdpAliveMapType;

/**   \brief  type used in SoAd_TpTxBufferConfig */
typedef struct sSoAd_TpTxBufferConfigType
{
  SoAd_TpTxBufferEndIdxOfTpTxBufferConfigType TpTxBufferEndIdxOfTpTxBufferConfig;  /**< the end index of the 0:n relation pointing to SoAd_TpTxBuffer */
  SoAd_TpTxBufferStartIdxOfTpTxBufferConfigType TpTxBufferStartIdxOfTpTxBufferConfig;  /**< the start index of the 0:n relation pointing to SoAd_TpTxBuffer */
} SoAd_TpTxBufferConfigType;

/**   \brief  type used in SoAd_TpTxBufferConfigDyn */
typedef struct sSoAd_TpTxBufferConfigDynType
{
  SoAd_TpTxBufferIdxOfTpTxBufferConfigDynType TpTxBufferIdxOfTpTxBufferConfigDyn;  /**< the index of the 1:1 relation pointing to SoAd_TpTxBuffer */
} SoAd_TpTxBufferConfigDynType;

/**   \brief  type used in SoAd_TriggerBufConfig */
typedef struct sSoAd_TriggerBufConfigType
{
  SoAd_TriggerBufEndIdxOfTriggerBufConfigType TriggerBufEndIdxOfTriggerBufConfig;  /**< the end index of the 1:n relation pointing to SoAd_TriggerBuf */
  SoAd_TriggerBufStartIdxOfTriggerBufConfigType TriggerBufStartIdxOfTriggerBufConfig;  /**< the start index of the 1:n relation pointing to SoAd_TriggerBuf */
} SoAd_TriggerBufConfigType;

/**   \brief  type used in SoAd_TriggerBufConfigDyn */
typedef struct sSoAd_TriggerBufConfigDynType
{
  SoAd_LengthOfTriggerBufConfigDynType LengthOfTriggerBufConfigDyn;  /**< the length of the used part of the buffer */
  SoAd_PduRouteIdxOfTriggerBufConfigDynType PduRouteIdxOfTriggerBufConfigDyn;  /**< the index of the 1:1 relation pointing to SoAd_PduRoute */
} SoAd_TriggerBufConfigDynType;

/**   \brief  type used in SoAd_TxMgt */
typedef struct sSoAd_TxMgtType
{
  SoAd_TxBytesLenOfTxMgtType TxBytesLenOfTxMgt;  /**< the length of data to be transmitted */
  SoAd_TxBytesPendingOfTxMgtType TxBytesPendingOfTxMgt;  /**< the length of pending data to be transmitted */
  SoAd_CancelRequestedOfTxMgtType CancelRequestedOfTxMgt;  /**< indicates if transmission cancellation is requested */
  SoAd_PduRouteDestIdxOfTxMgtType PduRouteDestIdxOfTxMgt;  /**< the index of the 1:1 relation pointing to SoAd_PduRouteDest */
  SduDataPtrType TxBufPtrOfTxMgt;  /**< the pointer to transmission data buffer */
} SoAd_TxMgtType;

/**   \brief  type used in SoAd_TxPduIdMap */
typedef struct sSoAd_TxPduIdMapType
{
  SoAd_InvalidHndOfTxPduIdMapType InvalidHndOfTxPduIdMap;  /**< FALSE, if the handle of SoAd_TxPduIdMap is valid and can be used in the embedded code for further processing in the embedded code. */
  SoAd_PartitionSpecificPduRouteIdxOfTxPduIdMapType PartitionSpecificPduRouteIdxOfTxPduIdMap;  /**< the index of the 1:1 relation pointing to one of SoAd_PduRoute */
  SoAd_PartitionSpecificPduRoutePartitionIdxOfTxPduIdMapType PartitionSpecificPduRoutePartitionIdxOfTxPduIdMap;  /**< the partition index of the 1:1 relation pointing to one of SoAd_PduRoute */
} SoAd_TxPduIdMapType;

/**   \brief  type used in SoAd_UpperLayer */
typedef struct sSoAd_UpperLayerType
{
  SoAd_IfRxIndicationCbkType IfRxIndicationCbkOfUpperLayer;  /**< the callback Up_[SoAd][If]RxIndication */
  SoAd_IfTriggerTransmitCbkType IfTriggerTransmitCbkOfUpperLayer;  /**< the callback Up_[SoAd][If]TriggerTransmit */
  SoAd_IfTxConfirmationCbkType IfTxConfirmationCbkOfUpperLayer;  /**< the callback Up_[SoAd][If]TxConfirmation */
  SoAd_TpCopyRxDataCbkType TpCopyRxDataCbkOfUpperLayer;  /**< the callback Up_[SoAd][Tp]CopyRxData */
  SoAd_TpCopyRxDataConstCbkType TpCopyRxDataConstCbkOfUpperLayer;  /**< the callback Up_[SoAd][Tp]CopyRxData with const data pointer */
  SoAd_TpCopyTxDataCbkType TpCopyTxDataCbkOfUpperLayer;  /**< the callback Up_[SoAd][Tp]CopyTxData */
  SoAd_TpCopyTxDataConstCbkType TpCopyTxDataConstCbkOfUpperLayer;  /**< the callback Up_[SoAd][Tp]CopyTxData with const data pointer */
  SoAd_TpRxIndicationCbkType TpRxIndicationCbkOfUpperLayer;  /**< the callback Up_[SoAd][Tp]RxIndication */
  SoAd_TpStartOfReceptionCbkType TpStartOfReceptionCbkOfUpperLayer;  /**< the callback Up_[SoAd][Tp]StartOfReception */
  SoAd_TpStartOfReceptionConstCbkType TpStartOfReceptionConstCbkOfUpperLayer;  /**< the callback Up_[SoAd][Tp]StartOfReception with const data pointer */
  SoAd_TpTxConfirmationCbkType TpTxConfirmationCbkOfUpperLayer;  /**< the callback Up_[SoAd][Tp]TxConfirmation */
} SoAd_UpperLayerType;

/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCRootPointerTypes  SoAd Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to SoAd_BestMatchSoConIdxList */
typedef P2VAR(SoAd_BestMatchSoConIdxListType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_BestMatchSoConIdxListPtrType;

/**   \brief  type used to point to SoAd_DhcpEventCbk */
typedef P2CONST(SoAd_DhcpEventCbkType, TYPEDEF, SOAD_CONST) SoAd_DhcpEventCbkPtrType;

/**   \brief  type used to point to SoAd_EventQueueFlag */
typedef P2VAR(SoAd_EventQueueFlagType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_EventQueueFlagPtrType;

/**   \brief  type used to point to SoAd_EventQueueIdent */
typedef P2CONST(SoAd_EventQueueIdentType, TYPEDEF, SOAD_CONST) SoAd_EventQueueIdentPtrType;

/**   \brief  type used to point to SoAd_EventQueueIfTxRouteGrp */
typedef P2VAR(SoAd_EventQueueIfTxRouteGrpType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_EventQueueIfTxRouteGrpPtrType;

/**   \brief  type used to point to SoAd_EventQueueIfTxRouteGrpConfig */
typedef P2CONST(SoAd_EventQueueIfTxRouteGrpConfigType, TYPEDEF, SOAD_CONST) SoAd_EventQueueIfTxRouteGrpConfigPtrType;

/**   \brief  type used to point to SoAd_EventQueueIfUdpPduRoute */
typedef P2VAR(SoAd_EventQueueIfUdpPduRouteType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_EventQueueIfUdpPduRoutePtrType;

/**   \brief  type used to point to SoAd_EventQueueIfUdpPduRouteConfig */
typedef P2CONST(SoAd_EventQueueIfUdpPduRouteConfigType, TYPEDEF, SOAD_CONST) SoAd_EventQueueIfUdpPduRouteConfigPtrType;

/**   \brief  type used to point to SoAd_EventQueueMgmt */
typedef P2VAR(SoAd_EventQueueMgmtType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_EventQueueMgmtPtrType;

/**   \brief  type used to point to SoAd_EventQueueStateSoCon */
typedef P2VAR(SoAd_EventQueueStateSoConType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_EventQueueStateSoConPtrType;

/**   \brief  type used to point to SoAd_EventQueueStateSoConConfig */
typedef P2CONST(SoAd_EventQueueStateSoConConfigType, TYPEDEF, SOAD_CONST) SoAd_EventQueueStateSoConConfigPtrType;

/**   \brief  type used to point to SoAd_EventQueueTpRxSoCon */
typedef P2VAR(SoAd_EventQueueTpRxSoConType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_EventQueueTpRxSoConPtrType;

/**   \brief  type used to point to SoAd_EventQueueTpRxSoConConfig */
typedef P2CONST(SoAd_EventQueueTpRxSoConConfigType, TYPEDEF, SOAD_CONST) SoAd_EventQueueTpRxSoConConfigPtrType;

/**   \brief  type used to point to SoAd_EventQueueTpTxSoCon */
typedef P2VAR(SoAd_EventQueueTpTxSoConType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_EventQueueTpTxSoConPtrType;

/**   \brief  type used to point to SoAd_EventQueueTpTxSoConConfig */
typedef P2CONST(SoAd_EventQueueTpTxSoConConfigType, TYPEDEF, SOAD_CONST) SoAd_EventQueueTpTxSoConConfigPtrType;

/**   \brief  type used to point to SoAd_IfRxBuffer */
typedef P2VAR(SoAd_IfRxBufferType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_IfRxBufferPtrType;

/**   \brief  type used to point to SoAd_Instance */
typedef P2CONST(SoAd_InstanceType, TYPEDEF, SOAD_CONST) SoAd_InstancePtrType;

/**   \brief  type used to point to SoAd_InstanceDyn */
typedef P2VAR(SoAd_InstanceDynType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_InstanceDynPtrType;

/**   \brief  type used to point to SoAd_OpenSocksOfInstanceDyn */
typedef P2VAR(SoAd_AtomicUint32Type, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_OpenSocksOfInstanceDynPtrType;

/**   \brief  type used to point to SoAd_InstanceMap */
typedef P2CONST(SoAd_InstanceMapType, TYPEDEF, SOAD_CONST) SoAd_InstanceMapPtrType;

/**   \brief  type used to point to SoAd_IpFragBuf */
typedef P2VAR(SoAd_IpFragBufType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_IpFragBufPtrType;

/**   \brief  type used to point to SoAd_IpFragBufConfig */
typedef P2CONST(SoAd_IpFragBufConfigType, TYPEDEF, SOAD_CONST) SoAd_IpFragBufConfigPtrType;

/**   \brief  type used to point to SoAd_IpFragBufConfigDyn */
typedef P2VAR(SoAd_IpFragBufConfigDynType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_IpFragBufConfigDynPtrType;

/**   \brief  type used to point to SoAd_IpFragMgt */
typedef P2VAR(SoAd_IpFragMgtType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_IpFragMgtPtrType;

/**   \brief  type used to point to SoAd_LocalAddr */
typedef P2CONST(SoAd_LocalAddrType, TYPEDEF, SOAD_CONST) SoAd_LocalAddrPtrType;

/**   \brief  type used to point to SoAd_LocalAddrByTcpIpCtrlInd */
typedef P2CONST(SoAd_LocalAddrByTcpIpCtrlIndType, TYPEDEF, SOAD_CONST) SoAd_LocalAddrByTcpIpCtrlIndPtrType;

/**   \brief  type used to point to SoAd_LocalAddrDyn */
typedef P2VAR(SoAd_LocalAddrDynType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_LocalAddrDynPtrType;

/**   \brief  type used to point to SoAd_LocalAddrIdMap */
typedef P2CONST(SoAd_LocalAddrIdMapType, TYPEDEF, SOAD_CONST) SoAd_LocalAddrIdMapPtrType;

/**   \brief  type used to point to SoAd_LocalIpAddrAssignmentChgCbk */
typedef P2CONST(SoAd_LocalIpAddrAssignmentChgCbkType, TYPEDEF, SOAD_CONST) SoAd_LocalIpAddrAssignmentChgCbkPtrType;

/**   \brief  type used to point to SoAd_LocalIpAddrAssignmentChgCbkInd */
typedef P2CONST(SoAd_LocalIpAddrAssignmentChgCbkIndType, TYPEDEF, SOAD_CONST) SoAd_LocalIpAddrAssignmentChgCbkIndPtrType;

/**   \brief  type used to point to SoAd_MetaDataRxBuffer */
typedef P2VAR(SoAd_MetaDataRxBufferType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_MetaDataRxBufferPtrType;

/**   \brief  type used to point to SoAd_NPduUdpTx */
typedef P2CONST(SoAd_NPduUdpTxType, TYPEDEF, SOAD_CONST) SoAd_NPduUdpTxPtrType;

/**   \brief  type used to point to SoAd_NPduUdpTxBuffer */
typedef P2VAR(SoAd_NPduUdpTxBufferType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_NPduUdpTxBufferPtrType;

/**   \brief  type used to point to SoAd_NPduUdpTxDyn */
typedef P2VAR(SoAd_NPduUdpTxDynType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_NPduUdpTxDynPtrType;

/**   \brief  type used to point to SoAd_NPduUdpTxQueue */
typedef P2VAR(SoAd_NPduUdpTxQueueType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_NPduUdpTxQueuePtrType;

/**   \brief  type used to point to SoAd_PartitionDyn */
typedef P2VAR(SoAd_PartitionDynType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_PartitionDynPtrType;

/**   \brief  type used to point to SoAd_InitializedOfPartitionDyn */
typedef P2VAR(SoAd_PartitionStateType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_InitializedOfPartitionDynPtrType;

/**   \brief  type used to point to SoAd_PartitionIdentifiers */
typedef P2CONST(SoAd_PartitionIdentifiersType, TYPEDEF, SOAD_CONST) SoAd_PartitionIdentifiersPtrType;

/**   \brief  type used to point to SoAd_PduRoute */
typedef P2CONST(SoAd_PduRouteType, TYPEDEF, SOAD_CONST) SoAd_PduRoutePtrType;

/**   \brief  type used to point to SoAd_PduRouteDest */
typedef P2CONST(SoAd_PduRouteDestType, TYPEDEF, SOAD_CONST) SoAd_PduRouteDestPtrType;

/**   \brief  type used to point to SoAd_PduRouteDestBySoConInd */
typedef P2CONST(SoAd_PduRouteDestBySoConIndType, TYPEDEF, SOAD_CONST) SoAd_PduRouteDestBySoConIndPtrType;

/**   \brief  type used to point to SoAd_PduRouteDestInd */
typedef P2CONST(SoAd_PduRouteDestIndType, TYPEDEF, SOAD_CONST) SoAd_PduRouteDestIndPtrType;

/**   \brief  type used to point to SoAd_PduRouteDyn */
typedef P2VAR(SoAd_PduRouteDynType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_PduRouteDynPtrType;

/**   \brief  type used to point to SoAd_AddrOfRemAddrIpV4 */
typedef P2CONST(SoAd_IpAddrInetType, TYPEDEF, SOAD_CONST) SoAd_AddrOfRemAddrIpV4PtrType;

/**   \brief  type used to point to SoAd_RemAddrIpV4 */
typedef P2CONST(SoAd_RemAddrIpV4Type, TYPEDEF, SOAD_CONST) SoAd_RemAddrIpV4PtrType;

/**   \brief  type used to point to SoAd_AddrOfRemAddrIpV6 */
typedef P2CONST(SoAd_IpAddrInet6Type, TYPEDEF, SOAD_CONST) SoAd_AddrOfRemAddrIpV6PtrType;

/**   \brief  type used to point to SoAd_RemAddrIpV6 */
typedef P2CONST(SoAd_RemAddrIpV6Type, TYPEDEF, SOAD_CONST) SoAd_RemAddrIpV6PtrType;

/**   \brief  type used to point to SoAd_RemAddrRcv */
typedef P2VAR(SoAd_SockAddrInetXType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_RemAddrRcvPtrType;

/**   \brief  type used to point to SoAd_RouteGrp */
typedef P2CONST(SoAd_RouteGrpType, TYPEDEF, SOAD_CONST) SoAd_RouteGrpPtrType;

/**   \brief  type used to point to SoAd_RouteGrpIdMap */
typedef P2CONST(SoAd_RouteGrpIdMapType, TYPEDEF, SOAD_CONST) SoAd_RouteGrpIdMapPtrType;

/**   \brief  type used to point to SoAd_RouteGrpSoCon */
typedef P2CONST(SoAd_RouteGrpSoConType, TYPEDEF, SOAD_CONST) SoAd_RouteGrpSoConPtrType;

/**   \brief  type used to point to SoAd_RouteGrpSoConByPduRouteDestInd */
typedef P2CONST(SoAd_RouteGrpSoConByPduRouteDestIndType, TYPEDEF, SOAD_CONST) SoAd_RouteGrpSoConByPduRouteDestIndPtrType;

/**   \brief  type used to point to SoAd_RouteGrpSoConBySocketRouteDestInd */
typedef P2CONST(SoAd_RouteGrpSoConBySocketRouteDestIndType, TYPEDEF, SOAD_CONST) SoAd_RouteGrpSoConBySocketRouteDestIndPtrType;

/**   \brief  type used to point to SoAd_RouteGrpSoConDyn */
typedef P2VAR(SoAd_RouteGrpSoConDynType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_RouteGrpSoConDynPtrType;

/**   \brief  type used to point to SoAd_FlagsOfRouteGrpSoConDyn */
typedef P2VAR(SoAd_FlagsOfRouteGrpSoConDynType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_FlagsOfRouteGrpSoConDynPtrType;

/**   \brief  type used to point to SoAd_RxBufStructMgt */
typedef P2VAR(SoAd_RxBufStructMgtType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_RxBufStructMgtPtrType;

/**   \brief  type used to point to SoAd_RxBufStructSeg */
typedef P2VAR(SoAd_RxBufStructSegType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_RxBufStructSegPtrType;

/**   \brief  type used to point to SoAd_DataPtrOfRxBufStructSeg */
typedef P2VAR(SoAd_DataPtrType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_DataPtrOfRxBufStructSegPtrType;

/**   \brief  type used to point to SoAd_RxBufferConfig */
typedef P2CONST(SoAd_RxBufferConfigType, TYPEDEF, SOAD_CONST) SoAd_RxBufferConfigPtrType;

/**   \brief  type used to point to SoAd_RxBufferConfigDyn */
typedef P2VAR(SoAd_RxBufferConfigDynType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_RxBufferConfigDynPtrType;

/**   \brief  type used to point to SoAd_RxMgt */
typedef P2VAR(SoAd_RxMgtType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_RxMgtPtrType;

/**   \brief  type used to point to SoAd_RxPduIdIdMap */
typedef P2CONST(SoAd_RxPduIdIdMapType, TYPEDEF, SOAD_CONST) SoAd_RxPduIdIdMapPtrType;

/**   \brief  type used to point to SoAd_ShutdownFinishedCbk */
typedef P2CONST(SoAd_ShutdownFinishedCbkType, TYPEDEF, SOAD_CONST) SoAd_ShutdownFinishedCbkPtrType;

/**   \brief  type used to point to SoAd_SoCon */
typedef P2CONST(SoAd_SoConType, TYPEDEF, SOAD_CONST) SoAd_SoConPtrType;

/**   \brief  type used to point to SoAd_SoConDyn */
typedef P2VAR(SoAd_SoConDynType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_SoConDynPtrType;

/**   \brief  type used to point to SoAd_RemAddrDynOfSoConDyn */
typedef P2VAR(SoAd_SockAddrInetXType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_RemAddrDynOfSoConDynPtrType;

/**   \brief  type used to point to SoAd_SoConGrp */
typedef P2CONST(SoAd_SoConGrpType, TYPEDEF, SOAD_CONST) SoAd_SoConGrpPtrType;

/**   \brief  type used to point to SoAd_SoConMap */
typedef P2CONST(SoAd_SoConMapType, TYPEDEF, SOAD_CONST) SoAd_SoConMapPtrType;

/**   \brief  type used to point to SoAd_SoConModeChgCbk */
typedef P2CONST(SoAd_SoConModeChgCbkType, TYPEDEF, SOAD_CONST) SoAd_SoConModeChgCbkPtrType;

/**   \brief  type used to point to SoAd_SoConModeChgCbkInd */
typedef P2CONST(SoAd_SoConModeChgCbkIndType, TYPEDEF, SOAD_CONST) SoAd_SoConModeChgCbkIndPtrType;

/**   \brief  type used to point to SoAd_Socket */
typedef P2CONST(SoAd_SocketType, TYPEDEF, SOAD_CONST) SoAd_SocketPtrType;

/**   \brief  type used to point to SoAd_SocketDyn */
typedef P2VAR(SoAd_SocketDynType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_SocketDynPtrType;

/**   \brief  type used to point to SoAd_SocketRoute */
typedef P2CONST(SoAd_SocketRouteType, TYPEDEF, SOAD_CONST) SoAd_SocketRoutePtrType;

/**   \brief  type used to point to SoAd_SocketRouteDest */
typedef P2CONST(SoAd_SocketRouteDestType, TYPEDEF, SOAD_CONST) SoAd_SocketRouteDestPtrType;

/**   \brief  type used to point to SoAd_SocketRouteInd */
typedef P2CONST(SoAd_SocketRouteIndType, TYPEDEF, SOAD_CONST) SoAd_SocketRouteIndPtrType;

/**   \brief  type used to point to SoAd_SocketTcp */
typedef P2CONST(SoAd_SocketTcpType, TYPEDEF, SOAD_CONST) SoAd_SocketTcpPtrType;

/**   \brief  type used to point to SoAd_SocketUdp */
typedef P2CONST(SoAd_SocketUdpType, TYPEDEF, SOAD_CONST) SoAd_SocketUdpPtrType;

/**   \brief  type used to point to SoAd_TcpIpCtrl */
typedef P2CONST(SoAd_TcpIpCtrlType, TYPEDEF, SOAD_CONST) SoAd_TcpIpCtrlPtrType;

/**   \brief  type used to point to SoAd_TcpKeepAliveGloballyEnabled */
typedef P2CONST(SoAd_TcpKeepAliveGloballyEnabledType, TYPEDEF, SOAD_CONST) SoAd_TcpKeepAliveGloballyEnabledPtrType;

/**   \brief  type used to point to SoAd_TcpTxQueue */
typedef P2CONST(SoAd_TcpTxQueueType, TYPEDEF, SOAD_CONST) SoAd_TcpTxQueuePtrType;

/**   \brief  type used to point to SoAd_TcpTxQueueData */
typedef P2VAR(SoAd_TcpTxQueueDataType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_TcpTxQueueDataPtrType;

/**   \brief  type used to point to SoAd_TcpTxQueueMgt */
typedef P2VAR(SoAd_TcpTxQueueMgtType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_TcpTxQueueMgtPtrType;

/**   \brief  type used to point to SoAd_TimeoutListIdent */
typedef P2CONST(SoAd_TimeoutListIdentType, TYPEDEF, SOAD_CONST) SoAd_TimeoutListIdentPtrType;

/**   \brief  type used to point to SoAd_TimeoutListMgmt */
typedef P2VAR(SoAd_TimeoutListMgmtType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_TimeoutListMgmtPtrType;

/**   \brief  type used to point to SoAd_TimeoutListNPduUdpTx */
typedef P2VAR(SoAd_TimeoutListNPduUdpTxType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_TimeoutListNPduUdpTxPtrType;

/**   \brief  type used to point to SoAd_TimeoutListNPduUdpTxConfig */
typedef P2CONST(SoAd_TimeoutListNPduUdpTxConfigType, TYPEDEF, SOAD_CONST) SoAd_TimeoutListNPduUdpTxConfigPtrType;

/**   \brief  type used to point to SoAd_TimeoutListNPduUdpTxMap */
typedef P2VAR(SoAd_TimeoutListNPduUdpTxMapType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_TimeoutListNPduUdpTxMapPtrType;

/**   \brief  type used to point to SoAd_TimeoutListTcpAutoConnectConfig */
typedef P2CONST(SoAd_TimeoutListTcpAutoConnectConfigType, TYPEDEF, SOAD_CONST) SoAd_TimeoutListTcpAutoConnectConfigPtrType;

/**   \brief  type used to point to SoAd_TimeoutListUdpAlive */
typedef P2VAR(SoAd_TimeoutListUdpAliveType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_TimeoutListUdpAlivePtrType;

/**   \brief  type used to point to SoAd_TimeoutListUdpAliveConfig */
typedef P2CONST(SoAd_TimeoutListUdpAliveConfigType, TYPEDEF, SOAD_CONST) SoAd_TimeoutListUdpAliveConfigPtrType;

/**   \brief  type used to point to SoAd_TimeoutListUdpAliveMap */
typedef P2VAR(SoAd_TimeoutListUdpAliveMapType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_TimeoutListUdpAliveMapPtrType;

/**   \brief  type used to point to SoAd_TpRxBuffer */
typedef P2VAR(SoAd_TpRxBufferType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_TpRxBufferPtrType;

/**   \brief  type used to point to SoAd_TpTxBuffer */
typedef P2VAR(SoAd_TpTxBufferType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_TpTxBufferPtrType;

/**   \brief  type used to point to SoAd_TpTxBufferConfig */
typedef P2CONST(SoAd_TpTxBufferConfigType, TYPEDEF, SOAD_CONST) SoAd_TpTxBufferConfigPtrType;

/**   \brief  type used to point to SoAd_TpTxBufferConfigDyn */
typedef P2VAR(SoAd_TpTxBufferConfigDynType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_TpTxBufferConfigDynPtrType;

/**   \brief  type used to point to SoAd_TriggerBuf */
typedef P2VAR(SoAd_TriggerBufType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_TriggerBufPtrType;

/**   \brief  type used to point to SoAd_TriggerBufConfig */
typedef P2CONST(SoAd_TriggerBufConfigType, TYPEDEF, SOAD_CONST) SoAd_TriggerBufConfigPtrType;

/**   \brief  type used to point to SoAd_TriggerBufConfigDyn */
typedef P2VAR(SoAd_TriggerBufConfigDynType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_TriggerBufConfigDynPtrType;

/**   \brief  type used to point to SoAd_TxMgt */
typedef P2VAR(SoAd_TxMgtType, TYPEDEF, SOAD_VAR_NO_INIT) SoAd_TxMgtPtrType;

/**   \brief  type used to point to SoAd_TxPduIdMap */
typedef P2CONST(SoAd_TxPduIdMapType, TYPEDEF, SOAD_CONST) SoAd_TxPduIdMapPtrType;

/**   \brief  type used to point to SoAd_UpperLayer */
typedef P2CONST(SoAd_UpperLayerType, TYPEDEF, SOAD_CONST) SoAd_UpperLayerPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCPartitionRootPointer  SoAd Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in SoAd_PCPartitionConfig */
typedef struct sSoAd_PCPartitionConfigType
{
  SoAd_BestMatchSoConIdxListPtrType BestMatchSoConIdxListOfPCPartitionConfig;  /**< the pointer to SoAd_BestMatchSoConIdxList */
  SoAd_DhcpEventCbkPtrType DhcpEventCbkOfPCPartitionConfig;  /**< the pointer to SoAd_DhcpEventCbk */
  SoAd_EventQueueFlagPtrType EventQueueFlagOfPCPartitionConfig;  /**< the pointer to SoAd_EventQueueFlag */
  SoAd_EventQueueIdentPtrType EventQueueIdentOfPCPartitionConfig;  /**< the pointer to SoAd_EventQueueIdent */
  SoAd_EventQueueIfTxRouteGrpPtrType EventQueueIfTxRouteGrpOfPCPartitionConfig;  /**< the pointer to SoAd_EventQueueIfTxRouteGrp */
  SoAd_EventQueueIfTxRouteGrpConfigPtrType EventQueueIfTxRouteGrpConfigOfPCPartitionConfig;  /**< the pointer to SoAd_EventQueueIfTxRouteGrpConfig */
  SoAd_EventQueueIfUdpPduRoutePtrType EventQueueIfUdpPduRouteOfPCPartitionConfig;  /**< the pointer to SoAd_EventQueueIfUdpPduRoute */
  SoAd_EventQueueIfUdpPduRouteConfigPtrType EventQueueIfUdpPduRouteConfigOfPCPartitionConfig;  /**< the pointer to SoAd_EventQueueIfUdpPduRouteConfig */
  SoAd_EventQueueMgmtPtrType EventQueueMgmtOfPCPartitionConfig;  /**< the pointer to SoAd_EventQueueMgmt */
  SoAd_EventQueueStateSoConPtrType EventQueueStateSoConOfPCPartitionConfig;  /**< the pointer to SoAd_EventQueueStateSoCon */
  SoAd_EventQueueStateSoConConfigPtrType EventQueueStateSoConConfigOfPCPartitionConfig;  /**< the pointer to SoAd_EventQueueStateSoConConfig */
  SoAd_EventQueueTpRxSoConPtrType EventQueueTpRxSoConOfPCPartitionConfig;  /**< the pointer to SoAd_EventQueueTpRxSoCon */
  SoAd_EventQueueTpRxSoConConfigPtrType EventQueueTpRxSoConConfigOfPCPartitionConfig;  /**< the pointer to SoAd_EventQueueTpRxSoConConfig */
  SoAd_EventQueueTpTxSoConPtrType EventQueueTpTxSoConOfPCPartitionConfig;  /**< the pointer to SoAd_EventQueueTpTxSoCon */
  SoAd_EventQueueTpTxSoConConfigPtrType EventQueueTpTxSoConConfigOfPCPartitionConfig;  /**< the pointer to SoAd_EventQueueTpTxSoConConfig */
  SoAd_IfRxBufferPtrType IfRxBufferOfPCPartitionConfig;  /**< the pointer to SoAd_IfRxBuffer */
  SoAd_InstancePtrType InstanceOfPCPartitionConfig;  /**< the pointer to SoAd_Instance */
  SoAd_InstanceDynPtrType InstanceDynOfPCPartitionConfig;  /**< the pointer to SoAd_InstanceDyn */
  SoAd_InstanceMapPtrType InstanceMapOfPCPartitionConfig;  /**< the pointer to SoAd_InstanceMap */
  SoAd_IpFragBufPtrType IpFragBufOfPCPartitionConfig;  /**< the pointer to SoAd_IpFragBuf */
  SoAd_IpFragBufConfigPtrType IpFragBufConfigOfPCPartitionConfig;  /**< the pointer to SoAd_IpFragBufConfig */
  SoAd_IpFragBufConfigDynPtrType IpFragBufConfigDynOfPCPartitionConfig;  /**< the pointer to SoAd_IpFragBufConfigDyn */
  SoAd_IpFragMgtPtrType IpFragMgtOfPCPartitionConfig;  /**< the pointer to SoAd_IpFragMgt */
  SoAd_LocalAddrPtrType LocalAddrOfPCPartitionConfig;  /**< the pointer to SoAd_LocalAddr */
  SoAd_LocalAddrByTcpIpCtrlIndPtrType LocalAddrByTcpIpCtrlIndOfPCPartitionConfig;  /**< the pointer to SoAd_LocalAddrByTcpIpCtrlInd */
  SoAd_LocalAddrDynPtrType LocalAddrDynOfPCPartitionConfig;  /**< the pointer to SoAd_LocalAddrDyn */
  SoAd_LocalAddrIdMapPtrType LocalAddrIdMapOfPCPartitionConfig;  /**< the pointer to SoAd_LocalAddrIdMap */
  SoAd_LocalIpAddrAssignmentChgCbkPtrType LocalIpAddrAssignmentChgCbkOfPCPartitionConfig;  /**< the pointer to SoAd_LocalIpAddrAssignmentChgCbk */
  SoAd_LocalIpAddrAssignmentChgCbkIndPtrType LocalIpAddrAssignmentChgCbkIndOfPCPartitionConfig;  /**< the pointer to SoAd_LocalIpAddrAssignmentChgCbkInd */
  SoAd_MetaDataRxBufferPtrType MetaDataRxBufferOfPCPartitionConfig;  /**< the pointer to SoAd_MetaDataRxBuffer */
  SoAd_NPduUdpTxPtrType NPduUdpTxOfPCPartitionConfig;  /**< the pointer to SoAd_NPduUdpTx */
  SoAd_NPduUdpTxBufferPtrType NPduUdpTxBufferOfPCPartitionConfig;  /**< the pointer to SoAd_NPduUdpTxBuffer */
  SoAd_NPduUdpTxDynPtrType NPduUdpTxDynOfPCPartitionConfig;  /**< the pointer to SoAd_NPduUdpTxDyn */
  SoAd_NPduUdpTxQueuePtrType NPduUdpTxQueueOfPCPartitionConfig;  /**< the pointer to SoAd_NPduUdpTxQueue */
  SoAd_PartitionDynPtrType PartitionDynOfPCPartitionConfig;  /**< the pointer to SoAd_PartitionDyn */
  SoAd_PduRoutePtrType PduRouteOfPCPartitionConfig;  /**< the pointer to SoAd_PduRoute */
  SoAd_PduRouteDestPtrType PduRouteDestOfPCPartitionConfig;  /**< the pointer to SoAd_PduRouteDest */
  SoAd_PduRouteDestBySoConIndPtrType PduRouteDestBySoConIndOfPCPartitionConfig;  /**< the pointer to SoAd_PduRouteDestBySoConInd */
  SoAd_PduRouteDestIndPtrType PduRouteDestIndOfPCPartitionConfig;  /**< the pointer to SoAd_PduRouteDestInd */
  SoAd_PduRouteDynPtrType PduRouteDynOfPCPartitionConfig;  /**< the pointer to SoAd_PduRouteDyn */
  SoAd_RemAddrIpV4PtrType RemAddrIpV4OfPCPartitionConfig;  /**< the pointer to SoAd_RemAddrIpV4 */
  SoAd_RemAddrIpV6PtrType RemAddrIpV6OfPCPartitionConfig;  /**< the pointer to SoAd_RemAddrIpV6 */
  SoAd_RemAddrRcvPtrType RemAddrRcvOfPCPartitionConfig;  /**< the pointer to SoAd_RemAddrRcv */
  SoAd_RouteGrpPtrType RouteGrpOfPCPartitionConfig;  /**< the pointer to SoAd_RouteGrp */
  SoAd_RouteGrpIdMapPtrType RouteGrpIdMapOfPCPartitionConfig;  /**< the pointer to SoAd_RouteGrpIdMap */
  SoAd_RouteGrpSoConPtrType RouteGrpSoConOfPCPartitionConfig;  /**< the pointer to SoAd_RouteGrpSoCon */
  SoAd_RouteGrpSoConByPduRouteDestIndPtrType RouteGrpSoConByPduRouteDestIndOfPCPartitionConfig;  /**< the pointer to SoAd_RouteGrpSoConByPduRouteDestInd */
  SoAd_RouteGrpSoConBySocketRouteDestIndPtrType RouteGrpSoConBySocketRouteDestIndOfPCPartitionConfig;  /**< the pointer to SoAd_RouteGrpSoConBySocketRouteDestInd */
  SoAd_RouteGrpSoConDynPtrType RouteGrpSoConDynOfPCPartitionConfig;  /**< the pointer to SoAd_RouteGrpSoConDyn */
  SoAd_RxBufStructMgtPtrType RxBufStructMgtOfPCPartitionConfig;  /**< the pointer to SoAd_RxBufStructMgt */
  SoAd_RxBufStructSegPtrType RxBufStructSegOfPCPartitionConfig;  /**< the pointer to SoAd_RxBufStructSeg */
  SoAd_RxBufferConfigPtrType RxBufferConfigOfPCPartitionConfig;  /**< the pointer to SoAd_RxBufferConfig */
  SoAd_RxBufferConfigDynPtrType RxBufferConfigDynOfPCPartitionConfig;  /**< the pointer to SoAd_RxBufferConfigDyn */
  SoAd_RxMgtPtrType RxMgtOfPCPartitionConfig;  /**< the pointer to SoAd_RxMgt */
  SoAd_RxPduIdIdMapPtrType RxPduIdIdMapOfPCPartitionConfig;  /**< the pointer to SoAd_RxPduIdIdMap */
  SoAd_ShutdownFinishedCbkPtrType ShutdownFinishedCbkOfPCPartitionConfig;  /**< the pointer to SoAd_ShutdownFinishedCbk */
  SoAd_SoConPtrType SoConOfPCPartitionConfig;  /**< the pointer to SoAd_SoCon */
  SoAd_SoConDynPtrType SoConDynOfPCPartitionConfig;  /**< the pointer to SoAd_SoConDyn */
  SoAd_SoConGrpPtrType SoConGrpOfPCPartitionConfig;  /**< the pointer to SoAd_SoConGrp */
  SoAd_SoConMapPtrType SoConMapOfPCPartitionConfig;  /**< the pointer to SoAd_SoConMap */
  SoAd_SoConModeChgCbkPtrType SoConModeChgCbkOfPCPartitionConfig;  /**< the pointer to SoAd_SoConModeChgCbk */
  SoAd_SoConModeChgCbkIndPtrType SoConModeChgCbkIndOfPCPartitionConfig;  /**< the pointer to SoAd_SoConModeChgCbkInd */
  SoAd_SocketPtrType SocketOfPCPartitionConfig;  /**< the pointer to SoAd_Socket */
  SoAd_SocketDynPtrType SocketDynOfPCPartitionConfig;  /**< the pointer to SoAd_SocketDyn */
  SoAd_SocketRoutePtrType SocketRouteOfPCPartitionConfig;  /**< the pointer to SoAd_SocketRoute */
  SoAd_SocketRouteDestPtrType SocketRouteDestOfPCPartitionConfig;  /**< the pointer to SoAd_SocketRouteDest */
  SoAd_SocketRouteIndPtrType SocketRouteIndOfPCPartitionConfig;  /**< the pointer to SoAd_SocketRouteInd */
  SoAd_SocketTcpPtrType SocketTcpOfPCPartitionConfig;  /**< the pointer to SoAd_SocketTcp */
  SoAd_SocketUdpPtrType SocketUdpOfPCPartitionConfig;  /**< the pointer to SoAd_SocketUdp */
  SoAd_TcpIpCtrlPtrType TcpIpCtrlOfPCPartitionConfig;  /**< the pointer to SoAd_TcpIpCtrl */
  SoAd_TcpKeepAliveGloballyEnabledPtrType TcpKeepAliveGloballyEnabledOfPCPartitionConfig;  /**< the pointer to SoAd_TcpKeepAliveGloballyEnabled */
  SoAd_TcpTxQueuePtrType TcpTxQueueOfPCPartitionConfig;  /**< the pointer to SoAd_TcpTxQueue */
  SoAd_TcpTxQueueDataPtrType TcpTxQueueDataOfPCPartitionConfig;  /**< the pointer to SoAd_TcpTxQueueData */
  SoAd_TcpTxQueueMgtPtrType TcpTxQueueMgtOfPCPartitionConfig;  /**< the pointer to SoAd_TcpTxQueueMgt */
  SoAd_TimeoutListIdentPtrType TimeoutListIdentOfPCPartitionConfig;  /**< the pointer to SoAd_TimeoutListIdent */
  SoAd_TimeoutListMgmtPtrType TimeoutListMgmtOfPCPartitionConfig;  /**< the pointer to SoAd_TimeoutListMgmt */
  SoAd_TimeoutListNPduUdpTxPtrType TimeoutListNPduUdpTxOfPCPartitionConfig;  /**< the pointer to SoAd_TimeoutListNPduUdpTx */
  SoAd_TimeoutListNPduUdpTxConfigPtrType TimeoutListNPduUdpTxConfigOfPCPartitionConfig;  /**< the pointer to SoAd_TimeoutListNPduUdpTxConfig */
  SoAd_TimeoutListNPduUdpTxMapPtrType TimeoutListNPduUdpTxMapOfPCPartitionConfig;  /**< the pointer to SoAd_TimeoutListNPduUdpTxMap */
  SoAd_TimeoutListTcpAutoConnectConfigPtrType TimeoutListTcpAutoConnectConfigOfPCPartitionConfig;  /**< the pointer to SoAd_TimeoutListTcpAutoConnectConfig */
  SoAd_TimeoutListUdpAlivePtrType TimeoutListUdpAliveOfPCPartitionConfig;  /**< the pointer to SoAd_TimeoutListUdpAlive */
  SoAd_TimeoutListUdpAliveConfigPtrType TimeoutListUdpAliveConfigOfPCPartitionConfig;  /**< the pointer to SoAd_TimeoutListUdpAliveConfig */
  SoAd_TimeoutListUdpAliveMapPtrType TimeoutListUdpAliveMapOfPCPartitionConfig;  /**< the pointer to SoAd_TimeoutListUdpAliveMap */
  SoAd_TpRxBufferPtrType TpRxBufferOfPCPartitionConfig;  /**< the pointer to SoAd_TpRxBuffer */
  SoAd_TpTxBufferPtrType TpTxBufferOfPCPartitionConfig;  /**< the pointer to SoAd_TpTxBuffer */
  SoAd_TpTxBufferConfigPtrType TpTxBufferConfigOfPCPartitionConfig;  /**< the pointer to SoAd_TpTxBufferConfig */
  SoAd_TpTxBufferConfigDynPtrType TpTxBufferConfigDynOfPCPartitionConfig;  /**< the pointer to SoAd_TpTxBufferConfigDyn */
  SoAd_TriggerBufPtrType TriggerBufOfPCPartitionConfig;  /**< the pointer to SoAd_TriggerBuf */
  SoAd_TriggerBufConfigPtrType TriggerBufConfigOfPCPartitionConfig;  /**< the pointer to SoAd_TriggerBufConfig */
  SoAd_TriggerBufConfigDynPtrType TriggerBufConfigDynOfPCPartitionConfig;  /**< the pointer to SoAd_TriggerBufConfigDyn */
  SoAd_TxMgtPtrType TxMgtOfPCPartitionConfig;  /**< the pointer to SoAd_TxMgt */
  SoAd_TxPduIdMapPtrType TxPduIdMapOfPCPartitionConfig;  /**< the pointer to SoAd_TxPduIdMap */
  SoAd_UpperLayerPtrType UpperLayerOfPCPartitionConfig;  /**< the pointer to SoAd_UpperLayer */
  SoAd_MaxIfRouteGrpTransmitPduSizeType MaxIfRouteGrpTransmitPduSizeOfPCPartitionConfig;  /**< the maximum length of all PDUs which can be sent via routing group transmit */
  SoAd_SizeOfBestMatchSoConIdxListType SizeOfBestMatchSoConIdxListOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_BestMatchSoConIdxList */
  SoAd_SizeOfDhcpEventCbkType SizeOfDhcpEventCbkOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_DhcpEventCbk */
  SoAd_SizeOfEventQueueFlagType SizeOfEventQueueFlagOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_EventQueueFlag */
  SoAd_SizeOfEventQueueIdentType SizeOfEventQueueIdentOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_EventQueueIdent */
  SoAd_SizeOfEventQueueIfTxRouteGrpType SizeOfEventQueueIfTxRouteGrpOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_EventQueueIfTxRouteGrp */
  SoAd_SizeOfEventQueueIfTxRouteGrpConfigType SizeOfEventQueueIfTxRouteGrpConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_EventQueueIfTxRouteGrpConfig */
  SoAd_SizeOfEventQueueIfUdpPduRouteType SizeOfEventQueueIfUdpPduRouteOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_EventQueueIfUdpPduRoute */
  SoAd_SizeOfEventQueueIfUdpPduRouteConfigType SizeOfEventQueueIfUdpPduRouteConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_EventQueueIfUdpPduRouteConfig */
  SoAd_SizeOfEventQueueMgmtType SizeOfEventQueueMgmtOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_EventQueueMgmt */
  SoAd_SizeOfEventQueueStateSoConType SizeOfEventQueueStateSoConOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_EventQueueStateSoCon */
  SoAd_SizeOfEventQueueStateSoConConfigType SizeOfEventQueueStateSoConConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_EventQueueStateSoConConfig */
  SoAd_SizeOfEventQueueTpRxSoConType SizeOfEventQueueTpRxSoConOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_EventQueueTpRxSoCon */
  SoAd_SizeOfEventQueueTpRxSoConConfigType SizeOfEventQueueTpRxSoConConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_EventQueueTpRxSoConConfig */
  SoAd_SizeOfEventQueueTpTxSoConType SizeOfEventQueueTpTxSoConOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_EventQueueTpTxSoCon */
  SoAd_SizeOfEventQueueTpTxSoConConfigType SizeOfEventQueueTpTxSoConConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_EventQueueTpTxSoConConfig */
  SoAd_SizeOfIfRxBufferType SizeOfIfRxBufferOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_IfRxBuffer */
  SoAd_SizeOfInstanceType SizeOfInstanceOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_Instance */
  SoAd_SizeOfInstanceMapType SizeOfInstanceMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_InstanceMap */
  SoAd_SizeOfIpFragBufType SizeOfIpFragBufOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_IpFragBuf */
  SoAd_SizeOfIpFragBufConfigType SizeOfIpFragBufConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_IpFragBufConfig */
  SoAd_SizeOfIpFragMgtType SizeOfIpFragMgtOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_IpFragMgt */
  SoAd_SizeOfLocalAddrType SizeOfLocalAddrOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_LocalAddr */
  SoAd_SizeOfLocalAddrByTcpIpCtrlIndType SizeOfLocalAddrByTcpIpCtrlIndOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_LocalAddrByTcpIpCtrlInd */
  SoAd_SizeOfLocalAddrIdMapType SizeOfLocalAddrIdMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_LocalAddrIdMap */
  SoAd_SizeOfLocalIpAddrAssignmentChgCbkType SizeOfLocalIpAddrAssignmentChgCbkOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_LocalIpAddrAssignmentChgCbk */
  SoAd_SizeOfLocalIpAddrAssignmentChgCbkIndType SizeOfLocalIpAddrAssignmentChgCbkIndOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_LocalIpAddrAssignmentChgCbkInd */
  SoAd_SizeOfMetaDataRxBufferType SizeOfMetaDataRxBufferOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_MetaDataRxBuffer */
  SoAd_SizeOfNPduUdpTxType SizeOfNPduUdpTxOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_NPduUdpTx */
  SoAd_SizeOfNPduUdpTxBufferType SizeOfNPduUdpTxBufferOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_NPduUdpTxBuffer */
  SoAd_SizeOfNPduUdpTxQueueType SizeOfNPduUdpTxQueueOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_NPduUdpTxQueue */
  SoAd_SizeOfPartitionDynType SizeOfPartitionDynOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_PartitionDyn */
  SoAd_SizeOfPduRouteType SizeOfPduRouteOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_PduRoute */
  SoAd_SizeOfPduRouteDestType SizeOfPduRouteDestOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_PduRouteDest */
  SoAd_SizeOfPduRouteDestBySoConIndType SizeOfPduRouteDestBySoConIndOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_PduRouteDestBySoConInd */
  SoAd_SizeOfPduRouteDestIndType SizeOfPduRouteDestIndOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_PduRouteDestInd */
  SoAd_SizeOfRemAddrIpV4Type SizeOfRemAddrIpV4OfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_RemAddrIpV4 */
  SoAd_SizeOfRemAddrIpV6Type SizeOfRemAddrIpV6OfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_RemAddrIpV6 */
  SoAd_SizeOfRemAddrRcvType SizeOfRemAddrRcvOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_RemAddrRcv */
  SoAd_SizeOfRouteGrpType SizeOfRouteGrpOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_RouteGrp */
  SoAd_SizeOfRouteGrpIdMapType SizeOfRouteGrpIdMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_RouteGrpIdMap */
  SoAd_SizeOfRouteGrpSoConType SizeOfRouteGrpSoConOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_RouteGrpSoCon */
  SoAd_SizeOfRouteGrpSoConByPduRouteDestIndType SizeOfRouteGrpSoConByPduRouteDestIndOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_RouteGrpSoConByPduRouteDestInd */
  SoAd_SizeOfRouteGrpSoConBySocketRouteDestIndType SizeOfRouteGrpSoConBySocketRouteDestIndOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_RouteGrpSoConBySocketRouteDestInd */
  SoAd_SizeOfRxBufStructMgtType SizeOfRxBufStructMgtOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_RxBufStructMgt */
  SoAd_SizeOfRxBufStructSegType SizeOfRxBufStructSegOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_RxBufStructSeg */
  SoAd_SizeOfRxBufferConfigType SizeOfRxBufferConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_RxBufferConfig */
  SoAd_SizeOfRxMgtType SizeOfRxMgtOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_RxMgt */
  SoAd_SizeOfRxPduIdIdMapType SizeOfRxPduIdIdMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_RxPduIdIdMap */
  SoAd_SizeOfShutdownFinishedCbkType SizeOfShutdownFinishedCbkOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_ShutdownFinishedCbk */
  SoAd_SizeOfSoConType SizeOfSoConOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_SoCon */
  SoAd_SizeOfSoConGrpType SizeOfSoConGrpOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_SoConGrp */
  SoAd_SizeOfSoConMapType SizeOfSoConMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_SoConMap */
  SoAd_SizeOfSoConModeChgCbkType SizeOfSoConModeChgCbkOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_SoConModeChgCbk */
  SoAd_SizeOfSoConModeChgCbkIndType SizeOfSoConModeChgCbkIndOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_SoConModeChgCbkInd */
  SoAd_SizeOfSocketType SizeOfSocketOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_Socket */
  SoAd_SizeOfSocketRouteType SizeOfSocketRouteOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_SocketRoute */
  SoAd_SizeOfSocketRouteDestType SizeOfSocketRouteDestOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_SocketRouteDest */
  SoAd_SizeOfSocketRouteIndType SizeOfSocketRouteIndOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_SocketRouteInd */
  SoAd_SizeOfSocketTcpType SizeOfSocketTcpOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_SocketTcp */
  SoAd_SizeOfSocketUdpType SizeOfSocketUdpOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_SocketUdp */
  SoAd_SizeOfTcpIpCtrlType SizeOfTcpIpCtrlOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TcpIpCtrl */
  SoAd_SizeOfTcpKeepAliveGloballyEnabledType SizeOfTcpKeepAliveGloballyEnabledOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TcpKeepAliveGloballyEnabled */
  SoAd_SizeOfTcpTxQueueType SizeOfTcpTxQueueOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TcpTxQueue */
  SoAd_SizeOfTcpTxQueueDataType SizeOfTcpTxQueueDataOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TcpTxQueueData */
  SoAd_SizeOfTimeoutListIdentType SizeOfTimeoutListIdentOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TimeoutListIdent */
  SoAd_SizeOfTimeoutListMgmtType SizeOfTimeoutListMgmtOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TimeoutListMgmt */
  SoAd_SizeOfTimeoutListNPduUdpTxType SizeOfTimeoutListNPduUdpTxOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TimeoutListNPduUdpTx */
  SoAd_SizeOfTimeoutListNPduUdpTxConfigType SizeOfTimeoutListNPduUdpTxConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TimeoutListNPduUdpTxConfig */
  SoAd_SizeOfTimeoutListNPduUdpTxMapType SizeOfTimeoutListNPduUdpTxMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TimeoutListNPduUdpTxMap */
  SoAd_SizeOfTimeoutListTcpAutoConnectConfigType SizeOfTimeoutListTcpAutoConnectConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TimeoutListTcpAutoConnectConfig */
  SoAd_SizeOfTimeoutListUdpAliveType SizeOfTimeoutListUdpAliveOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TimeoutListUdpAlive */
  SoAd_SizeOfTimeoutListUdpAliveConfigType SizeOfTimeoutListUdpAliveConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TimeoutListUdpAliveConfig */
  SoAd_SizeOfTimeoutListUdpAliveMapType SizeOfTimeoutListUdpAliveMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TimeoutListUdpAliveMap */
  SoAd_SizeOfTpRxBufferType SizeOfTpRxBufferOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TpRxBuffer */
  SoAd_SizeOfTpTxBufferType SizeOfTpTxBufferOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TpTxBuffer */
  SoAd_SizeOfTpTxBufferConfigType SizeOfTpTxBufferConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TpTxBufferConfig */
  SoAd_SizeOfTriggerBufType SizeOfTriggerBufOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TriggerBuf */
  SoAd_SizeOfTriggerBufConfigType SizeOfTriggerBufConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TriggerBufConfig */
  SoAd_SizeOfTxMgtType SizeOfTxMgtOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TxMgt */
  SoAd_SizeOfTxPduIdMapType SizeOfTxPduIdMapOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_TxPduIdMap */
  SoAd_SizeOfUpperLayerType SizeOfUpperLayerOfPCPartitionConfig;  /**< the number of accomplishable value elements in SoAd_UpperLayer */
} SoAd_PCPartitionConfigType;  /* PRQA S 0639 */  /* MD_MSR_Dir1.1 */

/**   \brief  type used to point to SoAd_PCPartitionConfig */
typedef P2CONST(SoAd_PCPartitionConfigType, TYPEDEF, SOAD_CONST) SoAd_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  SoAdPCRootValueTypes  SoAd Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in SoAd_PCConfig */
typedef struct sSoAd_PCConfigType
{
  SoAd_PCPartitionConfigPtrType PCPartitionConfigOfPCConfig;  /**< the pointer to SoAd_PCPartitionConfig */
  SoAd_PartitionIdentifiersPtrType PartitionIdentifiersOfPCConfig;  /**< the pointer to SoAd_PartitionIdentifiers */
  SoAd_SizeOfPartitionIdentifiersType SizeOfPartitionIdentifiersOfPCConfig;  /**< the number of accomplishable value elements in SoAd_PartitionIdentifiers */
} SoAd_PCConfigType;

typedef SoAd_PCConfigType SoAd_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access SoAd_PCConfig in a symbol based style. */
typedef struct sSoAd_PCConfigsType
{
  SoAd_PCConfigType Config;  /**< [Config] */
} SoAd_PCConfigsType;

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  SoAd_EventQueueIdent
**********************************************************************************************************************/
/** 
  \var    SoAd_EventQueueIdent
  \brief  the event queue identification to get the index of a specific event queue
  \details
  Element                             Description
  EventQueueFlagEndIdx                the end index of the 1:n relation pointing to SoAd_EventQueueFlag
  EventQueueFlagStartIdx              the start index of the 1:n relation pointing to SoAd_EventQueueFlag
  EventQueueIfTxRouteGrpConfigIdx     the index of the 0:1 relation pointing to SoAd_EventQueueIfTxRouteGrpConfig
  EventQueueIfUdpPduRouteConfigIdx    the index of the 0:1 relation pointing to SoAd_EventQueueIfUdpPduRouteConfig
  EventQueueStateSoConConfigIdx       the index of the 1:1 relation pointing to SoAd_EventQueueStateSoConConfig
  EventQueueTpRxSoConConfigIdx        the index of the 0:1 relation pointing to SoAd_EventQueueTpRxSoConConfig
  EventQueueTpTxSoConConfigIdx        the index of the 0:1 relation pointing to SoAd_EventQueueTpTxSoConConfig
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_EventQueueIdentType, SOAD_CONST) SoAd_EventQueueIdent[1];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_EventQueueIfUdpPduRouteConfig
**********************************************************************************************************************/
/** 
  \var    SoAd_EventQueueIfUdpPduRouteConfig
  \brief  the configuration of the specific event queue
  \details
  Element                            Description
  EventQueueIfUdpPduRouteEndIdx      the end index of the 1:n relation pointing to SoAd_EventQueueIfUdpPduRoute
  EventQueueIfUdpPduRouteStartIdx    the start index of the 1:n relation pointing to SoAd_EventQueueIfUdpPduRoute
  EventQueueMgmtIdx                  the index of the 1:1 relation pointing to SoAd_EventQueueMgmt
  FlagOffset                         the relative offset per instance within the event queue flags array
  Limit                              the limit of events handled in a single main function call
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_EventQueueIfUdpPduRouteConfigType, SOAD_CONST) SoAd_EventQueueIfUdpPduRouteConfig[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_EventQueueStateSoConConfig
**********************************************************************************************************************/
/** 
  \var    SoAd_EventQueueStateSoConConfig
  \brief  the configuration of the specific event queue
  \details
  Element                         Description
  EventQueueMgmtIdx               the index of the 1:1 relation pointing to SoAd_EventQueueMgmt
  EventQueueStateSoConEndIdx      the end index of the 1:n relation pointing to SoAd_EventQueueStateSoCon
  EventQueueStateSoConStartIdx    the start index of the 1:n relation pointing to SoAd_EventQueueStateSoCon
  FlagOffset                      the relative offset per instance within the event queue flags array
  Limit                           the limit of events handled in a single main function call
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_EventQueueStateSoConConfigType, SOAD_CONST) SoAd_EventQueueStateSoConConfig[1];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_Instance
**********************************************************************************************************************/
/** 
  \var    SoAd_Instance
  \brief  contains the event queue and timeout list indexes
  \details
  Element                          Description
  BestMatchSoConIdxListEndIdx      the end index of the 1:n relation pointing to SoAd_BestMatchSoConIdxList
  BestMatchSoConIdxListStartIdx    the start index of the 1:n relation pointing to SoAd_BestMatchSoConIdxList
  EventQueueIdentIdx               the index of the 1:1 relation pointing to SoAd_EventQueueIdent
  IpFragBufConfigEndIdx            the end index of the 0:n relation pointing to SoAd_IpFragBufConfig
  IpFragBufConfigStartIdx          the start index of the 0:n relation pointing to SoAd_IpFragBufConfig
  TimeoutListIdentIdx              the index of the 1:1 relation pointing to SoAd_TimeoutListIdent
  TriggerBufConfigEndIdx           the end index of the 0:n relation pointing to SoAd_TriggerBufConfig
  TriggerBufConfigStartIdx         the start index of the 0:n relation pointing to SoAd_TriggerBufConfig
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_InstanceType, SOAD_CONST) SoAd_Instance[1];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_InstanceMap
**********************************************************************************************************************/
/** 
  \var    SoAd_InstanceMap
  \brief  the partition-unspecific instanceMap ID mapping to partition-specific instance
  \details
  Element                                  Description
  PartitionSpecificInstanceIdx             the index of the 1:1 relation pointing to one of SoAd_Instance
  PartitionSpecificInstancePartitionIdx    the partition index of the 1:1 relation pointing to one of SoAd_Instance
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_InstanceMapType, SOAD_CONST) SoAd_InstanceMap[1];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_LocalAddr
**********************************************************************************************************************/
/** 
  \var    SoAd_LocalAddr
  \brief  the local address configurations
  \details
  Element             Description
  SoConGrpEndIdx      the end index of the 0:n relation pointing to SoAd_SoConGrp
  SoConGrpStartIdx    the start index of the 0:n relation pointing to SoAd_SoConGrp
  TcpIpCtrlIdx        the index of the 1:1 relation pointing to SoAd_TcpIpCtrl
  Domain              the IP domain (IPv4/6)
  AddrId              the address identifier to identify the local address at TcpIp
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_LocalAddrType, SOAD_CONST) SoAd_LocalAddr[2];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_LocalAddrByTcpIpCtrlInd
**********************************************************************************************************************/
/** 
  \var    SoAd_LocalAddrByTcpIpCtrlInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_LocalAddr
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_LocalAddrByTcpIpCtrlIndType, SOAD_CONST) SoAd_LocalAddrByTcpIpCtrlInd[1];
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_LocalAddrIdMap
**********************************************************************************************************************/
/** 
  \var    SoAd_LocalAddrIdMap
  \brief  the partition-unspecific LocalAddrId mapping to partition-specific LocalAddr
  \details
  Element                                   Description
  InvalidHnd                                FALSE, if the handle of SoAd_LocalAddrIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificLocalAddrIdx             the index of the 0:1 relation pointing to SoAd_LocalAddr
  PartitionSpecificLocalAddrPartitionIdx    the partition index of the 0:1 relation pointing to SoAd_LocalAddr
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_LocalAddrIdMapType, SOAD_CONST) SoAd_LocalAddrIdMap[4];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_LocalIpAddrAssignmentChgCbk
**********************************************************************************************************************/
/** 
  \var    SoAd_LocalIpAddrAssignmentChgCbk
  \brief  the callback Up_LocalIpAddrAssignmentChg
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_LocalIpAddrAssignmentChgCbkType, SOAD_CONST) SoAd_LocalIpAddrAssignmentChgCbk[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_LocalIpAddrAssignmentChgCbkInd
**********************************************************************************************************************/
/** 
  \var    SoAd_LocalIpAddrAssignmentChgCbkInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_LocalIpAddrAssignmentChgCbk
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_LocalIpAddrAssignmentChgCbkIndType, SOAD_CONST) SoAd_LocalIpAddrAssignmentChgCbkInd[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    SoAd_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to SoAd_PCPartitionConfig
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_PartitionIdentifiersType, SOAD_CONST) SoAd_PartitionIdentifiers[1];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PduRoute
**********************************************************************************************************************/
/** 
  \var    SoAd_PduRoute
  \brief  the SoAdPduRoutes configuration
  \details
  Element                      Description
  TxConfPduId                  the TxPduId used to call upper layer
  AllPduRouteDestWithPduHdr    indicates if all related SoAdPduRouteDests have a SoAdTxPduHeaderId
  IfOptimisticTransmit         indicates if IF optimistic transmit is used
  MetaDataTxEnabled            indicates if transmission on specific socket connection via meta data is enabled
  TxConfEnabled                indicates if TxConfirmation is enabled
  TxOptimized                  indicates if Tx optimized is enabled
  PduRouteDestEndIdx           the end index of the 1:n relation pointing to SoAd_PduRouteDest
  PduRouteDestStartIdx         the start index of the 1:n relation pointing to SoAd_PduRouteDest
  UpperLayerIdx                the index of the 1:1 relation pointing to SoAd_UpperLayer
  IfTriggerTransmitMode        the trigger transmit mode
  UpperLayerApi                the upper layer API type (IF/TP)
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_PduRouteType, SOAD_CONST) SoAd_PduRoute[8];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PduRouteDest
**********************************************************************************************************************/
/** 
  \var    SoAd_PduRouteDest
  \brief  the PduRouteDests configuraion
  \details
  Element                                   Description
  TxPduHdrId                                the PDU header ID
  PduRouteIdx                               the index of the 1:1 relation pointing to SoAd_PduRoute
  RouteGrpSoConByPduRouteDestIndEndIdx      the end index of the 0:n relation pointing to SoAd_RouteGrpSoConByPduRouteDestInd
  RouteGrpSoConByPduRouteDestIndStartIdx    the start index of the 0:n relation pointing to SoAd_RouteGrpSoConByPduRouteDestInd
  SoConIdx                                  the index of the 1:1 relation pointing to SoAd_SoCon
  UdpTriggerTimeout                         the PduRouteDest specific timeout to send a nPdu
  TxUdpTriggerMode                          indicates if nPdu shall be sent on transmission request always or never
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_PduRouteDestType, SOAD_CONST) SoAd_PduRouteDest[8];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PduRouteDestBySoConInd
**********************************************************************************************************************/
/** 
  \var    SoAd_PduRouteDestBySoConInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_PduRouteDest
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_PduRouteDestBySoConIndType, SOAD_CONST) SoAd_PduRouteDestBySoConInd[8];
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PduRouteDestInd
**********************************************************************************************************************/
/** 
  \var    SoAd_PduRouteDestInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_PduRouteDest
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_PduRouteDestIndType, SOAD_CONST) SoAd_PduRouteDestInd[7];
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RemAddrIpV4
**********************************************************************************************************************/
/** 
  \var    SoAd_RemAddrIpV4
  \brief  the configured IPv4 remote addresses for each IPv4 socket connection
  \details
  Element    Description
  Addr       the remote IPv4 address
  Port       the remote port
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_RemAddrIpV4Type, SOAD_CONST) SoAd_RemAddrIpV4[9];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RouteGrp
**********************************************************************************************************************/
/** 
  \var    SoAd_RouteGrp
  \brief  the routing group configuration
  \details
  Element                    Description
  EnabledAtInit              indicates if RoutingGroup is initially enabled
  MultiInstanceOnGrp         indicates if RoutingGroup is used for the multi service instance use case on socket connection groups
  RxRequestEnable            indicates if RoutingGroup can be requested to be enabled on reception (via Sd_RequestRoutingGroupEnable)
  TxTriggerable              indicates if RoutingGroup can be sent
  PduRouteDestIndEndIdx      the end index of the 0:n relation pointing to SoAd_PduRouteDestInd
  PduRouteDestIndStartIdx    the start index of the 0:n relation pointing to SoAd_PduRouteDestInd
  RouteGrpId                 the Routing Group identifier used in SoAd API
  RouteGrpSoConEndIdx        the end index of the 1:n relation pointing to SoAd_RouteGrpSoCon
  RouteGrpSoConStartIdx      the start index of the 1:n relation pointing to SoAd_RouteGrpSoCon
  SocketRouteIndEndIdx       the end index of the 0:n relation pointing to SoAd_SocketRouteInd
  SocketRouteIndStartIdx     the start index of the 0:n relation pointing to SoAd_SocketRouteInd
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_RouteGrpType, SOAD_CONST) SoAd_RouteGrp[5];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RouteGrpIdMap
**********************************************************************************************************************/
/** 
  \var    SoAd_RouteGrpIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific SoAdRoutingGroupId
  \details
  Element                                  Description
  InvalidHnd                               FALSE, if the handle of SoAd_RouteGrpIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificRouteGrpIdx             the index of the 0:1 relation pointing to SoAd_RouteGrp
  PartitionSpecificRouteGrpPartitionIdx    the partition index of the 0:1 relation pointing to SoAd_RouteGrp
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_RouteGrpIdMapType, SOAD_CONST) SoAd_RouteGrpIdMap[5];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RouteGrpSoCon
**********************************************************************************************************************/
/** 
  \var    SoAd_RouteGrpSoCon
  \brief  the routing groups on the socket connections
  \details
  Element        Description
  RouteGrpIdx    the index of the 1:1 relation pointing to SoAd_RouteGrp
  SoConIdx       the index of the 1:1 relation pointing to SoAd_SoCon
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_RouteGrpSoConType, SOAD_CONST) SoAd_RouteGrpSoCon[8];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RouteGrpSoConByPduRouteDestInd
**********************************************************************************************************************/
/** 
  \var    SoAd_RouteGrpSoConByPduRouteDestInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_RouteGrpSoCon
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_RouteGrpSoConByPduRouteDestIndType, SOAD_CONST) SoAd_RouteGrpSoConByPduRouteDestInd[7];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RouteGrpSoConBySocketRouteDestInd
**********************************************************************************************************************/
/** 
  \var    SoAd_RouteGrpSoConBySocketRouteDestInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_RouteGrpSoCon
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_RouteGrpSoConBySocketRouteDestIndType, SOAD_CONST) SoAd_RouteGrpSoConBySocketRouteDestInd[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RxPduIdIdMap
**********************************************************************************************************************/
/** 
  \var    SoAd_RxPduIdIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific RxPduId
  \details
  Element                                         Description
  InvalidHnd                                      FALSE, if the handle of SoAd_RxPduIdIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificSocketRouteDestIdx             the index of the 1:1 relation pointing to one of SoAd_SocketRouteDest
  PartitionSpecificSocketRouteDestPartitionIdx    the partition index of the 1:1 relation pointing to one of SoAd_SocketRouteDest
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_RxPduIdIdMapType, SOAD_CONST) SoAd_RxPduIdIdMap[6];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SoCon
**********************************************************************************************************************/
/** 
  \var    SoAd_SoCon
  \brief  the socket connection configuration
  \details
  Element                                   Description
  IpFragMgtIdx                              the index of the 0:1 relation pointing to SoAd_IpFragMgt
  LocalIpAddrAssignmentChgCbkIndEndIdx      the end index of the 0:n relation pointing to SoAd_LocalIpAddrAssignmentChgCbkInd
  LocalIpAddrAssignmentChgCbkIndStartIdx    the start index of the 0:n relation pointing to SoAd_LocalIpAddrAssignmentChgCbkInd
  NPduUdpTxIdx                              the index of the 0:1 relation pointing to SoAd_NPduUdpTx
  PduRouteDestBySoConIndEndIdx              the end index of the 0:n relation pointing to SoAd_PduRouteDestBySoConInd
  PduRouteDestBySoConIndStartIdx            the start index of the 0:n relation pointing to SoAd_PduRouteDestBySoConInd
  RemAddrIpV4Idx                            the index of the 0:1 relation pointing to SoAd_RemAddrIpV4
  RemAddrIpV6Idx                            the index of the 0:1 relation pointing to SoAd_RemAddrIpV6
  RemAddrRcvIdx                             the index of the 0:1 relation pointing to SoAd_RemAddrRcv
  RxBufStructMgtIdx                         the index of the 0:1 relation pointing to SoAd_RxBufStructMgt
  RxBufStructSegEndIdx                      the end index of the 0:n relation pointing to SoAd_RxBufStructSeg
  RxBufStructSegStartIdx                    the start index of the 0:n relation pointing to SoAd_RxBufStructSeg
  RxBufferConfigIdx                         the index of the 0:1 relation pointing to SoAd_RxBufferConfig
  RxMgtIdx                                  the index of the 0:1 relation pointing to SoAd_RxMgt
  SoConGrpIdx                               the index of the 1:1 relation pointing to SoAd_SoConGrp
  SoConId                                   the SocketConnection identifier used in SoAd API
  SoConModeChgCbkIndEndIdx                  the end index of the 0:n relation pointing to SoAd_SoConModeChgCbkInd
  SoConModeChgCbkIndStartIdx                the start index of the 0:n relation pointing to SoAd_SoConModeChgCbkInd
  SocketIdx                                 the index of the 1:1 relation pointing to SoAd_Socket
  SocketRouteEndIdx                         the end index of the 0:n relation pointing to SoAd_SocketRoute
  SocketRouteStartIdx                       the start index of the 0:n relation pointing to SoAd_SocketRoute
  TcpTxQueueIdx                             the index of the 0:1 relation pointing to SoAd_TcpTxQueue
  TpTxBufferConfigIdx                       the index of the 0:1 relation pointing to SoAd_TpTxBufferConfig
  TxMgtIdx                                  the index of the 0:1 relation pointing to SoAd_TxMgt
  RemAddrCfgState                           the configured remote address state
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_SoConType, SOAD_CONST) SoAd_SoCon[9];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SoConGrp
**********************************************************************************************************************/
/** 
  \var    SoAd_SoConGrp
  \brief  the socket connection group configuration
  \details
  Element                          Description
  BestMatchWithPduHeaderEnabled    indicates if best match algorithm considers PDU Header ID
  BestMatchWithSockRouteEnabled    indicates if best match algorithm considers socket route availability
  MsgAcceptFilterEnabled           indicates if message acceptance filter is enabled
  PduHdrEnabled                    indicates if PDU header is enabled
  SockAutoSoConSetup               indicates if automatic socket connection setup is enabled
  SockAutoSoConSetupKeepOnline     indicates if it is enabled that socket connection stays online after transmission
  FramePriority                    the frame priority (VLAN)
  InstanceIdx                      the index of the 1:1 relation pointing to SoAd_Instance
  LocalAddrIdx                     the index of the 0:1 relation pointing to SoAd_LocalAddr
  SoConEndIdx                      the end index of the 1:n relation pointing to SoAd_SoCon
  SoConStartIdx                    the start index of the 1:n relation pointing to SoAd_SoCon
  SocketIdx                        the index of the 0:1 relation pointing to SoAd_Socket
  SocketTcpIdx                     the index of the 0:1 relation pointing to SoAd_SocketTcp
  SocketUdpIdx                     the index of the 0:1 relation pointing to SoAd_SocketUdp
  LocalPort                        the local port
  MeasurementDataSomeIpSdType      indicates if SOME/IP SD data is measured
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_SoConGrpType, SOAD_CONST) SoAd_SoConGrp[7];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SoConMap
**********************************************************************************************************************/
/** 
  \var    SoAd_SoConMap
  \brief  the partition-unspecific handle ID mapping to partition-specific SoAdSocketId
  \details
  Element                               Description
  InvalidHnd                            FALSE, if the handle of SoAd_SoConMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificSoConIdx             the index of the 1:1 relation pointing to one of SoAd_SoCon
  PartitionSpecificSoConPartitionIdx    the partition index of the 1:1 relation pointing to one of SoAd_SoCon
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_SoConMapType, SOAD_CONST) SoAd_SoConMap[9];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SoConModeChgCbk
**********************************************************************************************************************/
/** 
  \var    SoAd_SoConModeChgCbk
  \brief  the callback Up_SoConModeChg
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_SoConModeChgCbkType, SOAD_CONST) SoAd_SoConModeChgCbk[2];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SoConModeChgCbkInd
**********************************************************************************************************************/
/** 
  \var    SoAd_SoConModeChgCbkInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_SoConModeChgCbk
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_SoConModeChgCbkIndType, SOAD_CONST) SoAd_SoConModeChgCbkInd[5];
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_Socket
**********************************************************************************************************************/
/** 
  \var    SoAd_Socket
  \brief  the socket configuration
  \details
  Element          Description
  SoConEndIdx      the end index of the 1:n relation pointing to SoAd_SoCon
  SoConStartIdx    the start index of the 1:n relation pointing to SoAd_SoCon
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_SocketType, SOAD_CONST) SoAd_Socket[7];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SocketRoute
**********************************************************************************************************************/
/** 
  \var    SoAd_SocketRoute
  \brief  the socket route configuration
  \details
  Element                    Description
  RxPduHdrMethodId           the PDU header Method ID
  RxPduHdrServiceId          the PDU header Service ID
  MetaDataRxEnabled          indicates if SoConId is forwarded as meta data on reception
  SoConIdx                   the index of the 1:1 relation pointing to SoAd_SoCon
  SocketRouteDestEndIdx      the end index of the 1:n relation pointing to SoAd_SocketRouteDest
  SocketRouteDestStartIdx    the start index of the 1:n relation pointing to SoAd_SocketRouteDest
  UpperLayerApi              the upper layer API type (IF/TP)
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_SocketRouteType, SOAD_CONST) SoAd_SocketRoute[6];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SocketRouteDest
**********************************************************************************************************************/
/** 
  \var    SoAd_SocketRouteDest
  \brief  the socket route destination configuration
  \details
  Element                                      Description
  RxPduId                                      the RxPduId used to call the upper layer
  RouteGrpSoConBySocketRouteDestIndEndIdx      the end index of the 0:n relation pointing to SoAd_RouteGrpSoConBySocketRouteDestInd
  RouteGrpSoConBySocketRouteDestIndStartIdx    the start index of the 0:n relation pointing to SoAd_RouteGrpSoConBySocketRouteDestInd
  SocketRouteIdx                               the index of the 1:1 relation pointing to SoAd_SocketRoute
  UpperLayerIdx                                the index of the 1:1 relation pointing to SoAd_UpperLayer
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_SocketRouteDestType, SOAD_CONST) SoAd_SocketRouteDest[6];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SocketRouteInd
**********************************************************************************************************************/
/** 
  \var    SoAd_SocketRouteInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_SocketRoute
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_SocketRouteIndType, SOAD_CONST) SoAd_SocketRouteInd[3];
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SocketUdp
**********************************************************************************************************************/
/** 
  \var    SoAd_SocketUdp
  \brief  the UDP socket configuration
  \details
  Element                        Description
  AliveTimeoutMaxCnt             the time a connection remains online after the last reception
  ChecksumChangeEnabled          indicates if UDP checksum calculation setting shall be changed
  ChecksumEnabled                indicates if UDP checksum calculation shall be enabled
  ImmedIfTxConf                  indicates if immediate TxConfirmation is used
  UdpListenOnly                  indicates if the socket is used for reception only
  UdpStrictHdrLenCheckEnabled    indicates if UDP messages shall be dropped dependent on header length check
  ImmedIfTxConfListSize          the list size to handle UDP transmissions with immediate TxConfirmation
  NPduUdpTxBufferMin             the amount of data in bytes that SoAd is able to buffer
  NPduUdpTxQueueSize             the size of the management queue
  RetryQueueLimit                the limitation of maximum used UDP transmission retry queue elements for this socket
  UdpTriggerTimeout              the time to wait for a PDU with TriggerMode = TRIGGER_ALWAYS before nPduUdpTxBuffer is transmitted
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_SocketUdpType, SOAD_CONST) SoAd_SocketUdp[7];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TcpIpCtrl
**********************************************************************************************************************/
/** 
  \var    SoAd_TcpIpCtrl
  \brief  the TcpIp controller/interface
  \details
  Element                            Description
  RetryEnabled                       indicates if transmission retry is available on controller/interface
  LocalAddrByTcpIpCtrlIndEndIdx      the end index of the 0:n relation pointing to SoAd_LocalAddrByTcpIpCtrlInd
  LocalAddrByTcpIpCtrlIndStartIdx    the start index of the 0:n relation pointing to SoAd_LocalAddrByTcpIpCtrlInd
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_TcpIpCtrlType, SOAD_CONST) SoAd_TcpIpCtrl[1];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TcpKeepAliveGloballyEnabled
**********************************************************************************************************************/
/** 
  \var    SoAd_TcpKeepAliveGloballyEnabled
  \brief  indicates if TCP keep alive is enabled at all
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_TcpKeepAliveGloballyEnabledType, SOAD_CONST) SoAd_TcpKeepAliveGloballyEnabled[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TimeoutListIdent
**********************************************************************************************************************/
/** 
  \var    SoAd_TimeoutListIdent
  \brief  the timeout list identification to get the index of a specific timeout list
  \details
  Element                               Description
  TimeoutListNPduUdpTxConfigIdx         the index of the 0:1 relation pointing to SoAd_TimeoutListNPduUdpTxConfig
  TimeoutListTcpAutoConnectConfigIdx    the index of the 0:1 relation pointing to SoAd_TimeoutListTcpAutoConnectConfig
  TimeoutListUdpAliveConfigIdx          the index of the 0:1 relation pointing to SoAd_TimeoutListUdpAliveConfig
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_TimeoutListIdentType, SOAD_CONST) SoAd_TimeoutListIdent[1];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TimeoutListUdpAliveConfig
**********************************************************************************************************************/
/** 
  \var    SoAd_TimeoutListUdpAliveConfig
  \brief  the configuration of the specific timeout list
  \details
  Element                        Description
  TimeoutListMgmtIdx             the index of the 1:1 relation pointing to SoAd_TimeoutListMgmt
  TimeoutListUdpAliveEndIdx      the end index of the 1:n relation pointing to SoAd_TimeoutListUdpAlive
  TimeoutListUdpAliveStartIdx    the start index of the 1:n relation pointing to SoAd_TimeoutListUdpAlive
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_TimeoutListUdpAliveConfigType, SOAD_CONST) SoAd_TimeoutListUdpAliveConfig[1];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TxPduIdMap
**********************************************************************************************************************/
/** 
  \var    SoAd_TxPduIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific TxPduId
  \details
  Element                                  Description
  InvalidHnd                               FALSE, if the handle of SoAd_TxPduIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificPduRouteIdx             the index of the 1:1 relation pointing to one of SoAd_PduRoute
  PartitionSpecificPduRoutePartitionIdx    the partition index of the 1:1 relation pointing to one of SoAd_PduRoute
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_TxPduIdMapType, SOAD_CONST) SoAd_TxPduIdMap[8];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_UpperLayer
**********************************************************************************************************************/
/** 
  \var    SoAd_UpperLayer
  \brief  the upper layer configuration
  \details
  Element                       Description
  IfRxIndicationCbk             the callback Up_[SoAd][If]RxIndication
  IfTriggerTransmitCbk          the callback Up_[SoAd][If]TriggerTransmit
  IfTxConfirmationCbk           the callback Up_[SoAd][If]TxConfirmation
  TpCopyRxDataCbk               the callback Up_[SoAd][Tp]CopyRxData
  TpCopyRxDataConstCbk          the callback Up_[SoAd][Tp]CopyRxData with const data pointer
  TpCopyTxDataCbk               the callback Up_[SoAd][Tp]CopyTxData
  TpCopyTxDataConstCbk          the callback Up_[SoAd][Tp]CopyTxData with const data pointer
  TpRxIndicationCbk             the callback Up_[SoAd][Tp]RxIndication
  TpStartOfReceptionCbk         the callback Up_[SoAd][Tp]StartOfReception
  TpStartOfReceptionConstCbk    the callback Up_[SoAd][Tp]StartOfReception with const data pointer
  TpTxConfirmationCbk           the callback Up_[SoAd][Tp]TxConfirmation
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_UpperLayerType, SOAD_CONST) SoAd_UpperLayer[4];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_BestMatchSoConIdxList
**********************************************************************************************************************/
/** 
  \var    SoAd_BestMatchSoConIdxList
  \brief  the global list to store all matching socket connections if best match alogorithm is used
  \details
  Element     Description
  SoConIdx    the index of the 1:1 relation pointing to SoAd_SoCon
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_BestMatchSoConIdxListType, SOAD_VAR_NO_INIT) SoAd_BestMatchSoConIdxList[2];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_EventQueueFlag
**********************************************************************************************************************/
/** 
  \var    SoAd_EventQueueFlag
  \brief  stores a flag for each handle index and event queue type to indicate if handle is in event queue (i.e. event active for handle)
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_EventQueueFlagType, SOAD_VAR_NO_INIT) SoAd_EventQueueFlag[9];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_EventQueueIfUdpPduRoute
**********************************************************************************************************************/
/** 
  \var    SoAd_EventQueueIfUdpPduRoute
  \brief  indicates if a IF confirmation is pending on a UDP socket connection
  \details
  Element        Description
  PduRouteIdx    the index of the 0:1 relation pointing to SoAd_PduRoute
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_EventQueueIfUdpPduRouteType, SOAD_VAR_NO_INIT) SoAd_EventQueueIfUdpPduRoute[8];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_EventQueueMgmt
**********************************************************************************************************************/
/** 
  \var    SoAd_EventQueueMgmt
  \brief  the management struct of all event queues
  \details
  Element    Description
  Idx        the index of oldest pending event.
  Lvl        the level of pending events
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_EventQueueMgmtType, SOAD_VAR_NO_INIT) SoAd_EventQueueMgmt[2];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_EventQueueStateSoCon
**********************************************************************************************************************/
/** 
  \var    SoAd_EventQueueStateSoCon
  \brief  indicates if an event is active for socket connection state
  \details
  Element     Description
  SoConIdx    the index of the 0:1 relation pointing to SoAd_SoCon
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_EventQueueStateSoConType, SOAD_VAR_NO_INIT) SoAd_EventQueueStateSoCon[9];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_InstanceDyn
**********************************************************************************************************************/
/** 
  \var    SoAd_InstanceDyn
  \brief  contains the instance-specific counter variables (main function cycles, open sockets and measurement data)
  \details
  Element              Description
  Counter              counts the main function cycles (with wrap around) to handle timeouts for the timeout lists
  BestMatchListSize    the number of valid socket connections saved in the best match list
  OpenSocks            the number of open sockets
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_InstanceDynType, SOAD_VAR_NO_INIT) SoAd_InstanceDyn[1];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_LocalAddrDyn
**********************************************************************************************************************/
/** 
  \var    SoAd_LocalAddrDyn
  \details
  Element        Description
  IpAddrState    the local IP address assignment state
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_LocalAddrDynType, SOAD_VAR_NO_INIT) SoAd_LocalAddrDyn[2];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PartitionDyn
**********************************************************************************************************************/
/** 
  \var    SoAd_PartitionDyn
  \brief  contains the partition-specific init status
  \details
  Element        Description
  Initialized    initialized state of the partition
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_PartitionDynType, SOAD_VAR_NO_INIT) SoAd_PartitionDyn[1];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PduRouteDyn
**********************************************************************************************************************/
/** 
  \var    SoAd_PduRouteDyn
  \brief  the SoAdPduRoute management structs
  \details
  Element              Description
  PendingTxConfMain    indicates if transmission confirmation in main function context is pending
  PendingTxConfNum     the number of pending transmission confirmation
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_PduRouteDynType, SOAD_VAR_NO_INIT) SoAd_PduRouteDyn[8];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RemAddrRcv
**********************************************************************************************************************/
/** 
  \var    SoAd_RemAddrRcv
  \brief  stores remote address on reception
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_SockAddrInetXType, SOAD_VAR_NO_INIT) SoAd_RemAddrRcv[2];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RouteGrpSoConDyn
**********************************************************************************************************************/
/** 
  \var    SoAd_RouteGrpSoConDyn
  \brief  the routing groups on the socket connections management struct
  \details
  Element    Description
  Enabled    the routing group state on the socket connection
  Flags      the current state of routing group transmission for socket connection: flag 0 = Tx active, flag 1 = Tx processed
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_RouteGrpSoConDynType, SOAD_VAR_NO_INIT) SoAd_RouteGrpSoConDyn[8];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RxMgt
**********************************************************************************************************************/
/** 
  \var    SoAd_RxMgt
  \brief  the Rx management structs
  \details
  Element               Description
  RxBytesPending        the length of pending data to be received
  CancelRequested       indicates if reception cancellation is requested
  SocketRouteDestIdx    the index of the 1:1 relation pointing to SoAd_SocketRouteDest
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_RxMgtType, SOAD_VAR_NO_INIT) SoAd_RxMgt[6];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SoConDyn
**********************************************************************************************************************/
/** 
  \var    SoAd_SoConDyn
  \brief  the socket connection managment structs
  \details
  Element             Description
  OpenCloseCounter    the open and close sequence counter
  Abort               indicates if abort is requested
  RxActive            indicates if reception is active on any SocketRoute of the socket connection
  TimeoutOccurred     indicates if timeout occurred while trying to open the socket connection
  TxActive            indicates if transmission is active on any PduRoute of the socket connection
  CloseMode           the mode of socket connection
  Mode                the mode of socket connection
  RemAddrDyn          the remote address for each socket connection
  RemAddrRelease      indicates if release of remote address is requested
  RemAddrStateDyn     the remote address state on socket connection
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_SoConDynType, SOAD_VAR_NO_INIT) SoAd_SoConDyn[9];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SocketDyn
**********************************************************************************************************************/
/** 
  \var    SoAd_SocketDyn
  \brief  the socket management structs
  \details
  Element             Description
  SkipBytes           the number of bytes to be skipped
  SoConTxActiveIdx    the index of the 0:1 relation pointing to SoAd_SoCon
  LocalPort           the local port
  SocketId            the socket identifier
  State               the socket state
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_SocketDynType, SOAD_VAR_NO_INIT) SoAd_SocketDyn[7];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TimeoutListMgmt
**********************************************************************************************************************/
/** 
  \var    SoAd_TimeoutListMgmt
  \brief  the management struct of all timeout lists
  \details
  Element    Description
  Lvl        the level of pending timeouts
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_TimeoutListMgmtType, SOAD_VAR_NO_INIT) SoAd_TimeoutListMgmt[1];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TimeoutListUdpAlive
**********************************************************************************************************************/
/** 
  \var    SoAd_TimeoutListUdpAlive
  \brief  the timeout list for UDP Alive supervision timeout
  \details
  Element     Description
  Timeout     the timeout value
  SoConIdx    the index of the 0:1 relation pointing to SoAd_SoCon
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_TimeoutListUdpAliveType, SOAD_VAR_NO_INIT) SoAd_TimeoutListUdpAlive[3];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TimeoutListUdpAliveMap
**********************************************************************************************************************/
/** 
  \var    SoAd_TimeoutListUdpAliveMap
  \brief  maps all socket connections to the timeout list index for UDP Alive supervision timeout if timeout is running
  \details
  Element                   Description
  TimeoutListUdpAliveIdx    the index of the 0:1 relation pointing to SoAd_TimeoutListUdpAlive
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_TimeoutListUdpAliveMapType, SOAD_VAR_NO_INIT) SoAd_TimeoutListUdpAliveMap[9];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TxMgt
**********************************************************************************************************************/
/** 
  \var    SoAd_TxMgt
  \brief  the Tx management structs
  \details
  Element            Description
  TxBytesLen         the length of data to be transmitted
  TxBytesPending     the length of pending data to be transmitted
  CancelRequested    indicates if transmission cancellation is requested
  PduRouteDestIdx    the index of the 1:1 relation pointing to SoAd_PduRouteDest
  TxBufPtr           the pointer to transmission data buffer
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SoAd_TxMgtType, SOAD_VAR_NO_INIT) SoAd_TxMgt[5];
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PCConfig
**********************************************************************************************************************/
/** 
  \var    SoAd_PCConfig
  \details
  Element                       Description
  PCPartitionConfig             the pointer to SoAd_PCPartitionConfig
  PartitionIdentifiers          the pointer to SoAd_PartitionIdentifiers
  SizeOfPartitionIdentifiers    the number of accomplishable value elements in SoAd_PartitionIdentifiers
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_PCConfigsType, SOAD_CONST) SoAd_PCConfig;
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PCPartitionConfig
**********************************************************************************************************************/
/** 
  \var    SoAd_PCPartitionConfig
  \details
  Element                                    Description
  BestMatchSoConIdxList                      the pointer to SoAd_BestMatchSoConIdxList
  DhcpEventCbk                               the pointer to SoAd_DhcpEventCbk
  EventQueueFlag                             the pointer to SoAd_EventQueueFlag
  EventQueueIdent                            the pointer to SoAd_EventQueueIdent
  EventQueueIfTxRouteGrp                     the pointer to SoAd_EventQueueIfTxRouteGrp
  EventQueueIfTxRouteGrpConfig               the pointer to SoAd_EventQueueIfTxRouteGrpConfig
  EventQueueIfUdpPduRoute                    the pointer to SoAd_EventQueueIfUdpPduRoute
  EventQueueIfUdpPduRouteConfig              the pointer to SoAd_EventQueueIfUdpPduRouteConfig
  EventQueueMgmt                             the pointer to SoAd_EventQueueMgmt
  EventQueueStateSoCon                       the pointer to SoAd_EventQueueStateSoCon
  EventQueueStateSoConConfig                 the pointer to SoAd_EventQueueStateSoConConfig
  EventQueueTpRxSoCon                        the pointer to SoAd_EventQueueTpRxSoCon
  EventQueueTpRxSoConConfig                  the pointer to SoAd_EventQueueTpRxSoConConfig
  EventQueueTpTxSoCon                        the pointer to SoAd_EventQueueTpTxSoCon
  EventQueueTpTxSoConConfig                  the pointer to SoAd_EventQueueTpTxSoConConfig
  IfRxBuffer                                 the pointer to SoAd_IfRxBuffer
  Instance                                   the pointer to SoAd_Instance
  InstanceDyn                                the pointer to SoAd_InstanceDyn
  InstanceMap                                the pointer to SoAd_InstanceMap
  IpFragBuf                                  the pointer to SoAd_IpFragBuf
  IpFragBufConfig                            the pointer to SoAd_IpFragBufConfig
  IpFragBufConfigDyn                         the pointer to SoAd_IpFragBufConfigDyn
  IpFragMgt                                  the pointer to SoAd_IpFragMgt
  LocalAddr                                  the pointer to SoAd_LocalAddr
  LocalAddrByTcpIpCtrlInd                    the pointer to SoAd_LocalAddrByTcpIpCtrlInd
  LocalAddrDyn                               the pointer to SoAd_LocalAddrDyn
  LocalAddrIdMap                             the pointer to SoAd_LocalAddrIdMap
  LocalIpAddrAssignmentChgCbk                the pointer to SoAd_LocalIpAddrAssignmentChgCbk
  LocalIpAddrAssignmentChgCbkInd             the pointer to SoAd_LocalIpAddrAssignmentChgCbkInd
  MetaDataRxBuffer                           the pointer to SoAd_MetaDataRxBuffer
  NPduUdpTx                                  the pointer to SoAd_NPduUdpTx
  NPduUdpTxBuffer                            the pointer to SoAd_NPduUdpTxBuffer
  NPduUdpTxDyn                               the pointer to SoAd_NPduUdpTxDyn
  NPduUdpTxQueue                             the pointer to SoAd_NPduUdpTxQueue
  PartitionDyn                               the pointer to SoAd_PartitionDyn
  PduRoute                                   the pointer to SoAd_PduRoute
  PduRouteDest                               the pointer to SoAd_PduRouteDest
  PduRouteDestBySoConInd                     the pointer to SoAd_PduRouteDestBySoConInd
  PduRouteDestInd                            the pointer to SoAd_PduRouteDestInd
  PduRouteDyn                                the pointer to SoAd_PduRouteDyn
  RemAddrIpV4                                the pointer to SoAd_RemAddrIpV4
  RemAddrIpV6                                the pointer to SoAd_RemAddrIpV6
  RemAddrRcv                                 the pointer to SoAd_RemAddrRcv
  RouteGrp                                   the pointer to SoAd_RouteGrp
  RouteGrpIdMap                              the pointer to SoAd_RouteGrpIdMap
  RouteGrpSoCon                              the pointer to SoAd_RouteGrpSoCon
  RouteGrpSoConByPduRouteDestInd             the pointer to SoAd_RouteGrpSoConByPduRouteDestInd
  RouteGrpSoConBySocketRouteDestInd          the pointer to SoAd_RouteGrpSoConBySocketRouteDestInd
  RouteGrpSoConDyn                           the pointer to SoAd_RouteGrpSoConDyn
  RxBufStructMgt                             the pointer to SoAd_RxBufStructMgt
  RxBufStructSeg                             the pointer to SoAd_RxBufStructSeg
  RxBufferConfig                             the pointer to SoAd_RxBufferConfig
  RxBufferConfigDyn                          the pointer to SoAd_RxBufferConfigDyn
  RxMgt                                      the pointer to SoAd_RxMgt
  RxPduIdIdMap                               the pointer to SoAd_RxPduIdIdMap
  ShutdownFinishedCbk                        the pointer to SoAd_ShutdownFinishedCbk
  SoCon                                      the pointer to SoAd_SoCon
  SoConDyn                                   the pointer to SoAd_SoConDyn
  SoConGrp                                   the pointer to SoAd_SoConGrp
  SoConMap                                   the pointer to SoAd_SoConMap
  SoConModeChgCbk                            the pointer to SoAd_SoConModeChgCbk
  SoConModeChgCbkInd                         the pointer to SoAd_SoConModeChgCbkInd
  Socket                                     the pointer to SoAd_Socket
  SocketDyn                                  the pointer to SoAd_SocketDyn
  SocketRoute                                the pointer to SoAd_SocketRoute
  SocketRouteDest                            the pointer to SoAd_SocketRouteDest
  SocketRouteInd                             the pointer to SoAd_SocketRouteInd
  SocketTcp                                  the pointer to SoAd_SocketTcp
  SocketUdp                                  the pointer to SoAd_SocketUdp
  TcpIpCtrl                                  the pointer to SoAd_TcpIpCtrl
  TcpKeepAliveGloballyEnabled                the pointer to SoAd_TcpKeepAliveGloballyEnabled
  TcpTxQueue                                 the pointer to SoAd_TcpTxQueue
  TcpTxQueueData                             the pointer to SoAd_TcpTxQueueData
  TcpTxQueueMgt                              the pointer to SoAd_TcpTxQueueMgt
  TimeoutListIdent                           the pointer to SoAd_TimeoutListIdent
  TimeoutListMgmt                            the pointer to SoAd_TimeoutListMgmt
  TimeoutListNPduUdpTx                       the pointer to SoAd_TimeoutListNPduUdpTx
  TimeoutListNPduUdpTxConfig                 the pointer to SoAd_TimeoutListNPduUdpTxConfig
  TimeoutListNPduUdpTxMap                    the pointer to SoAd_TimeoutListNPduUdpTxMap
  TimeoutListTcpAutoConnectConfig            the pointer to SoAd_TimeoutListTcpAutoConnectConfig
  TimeoutListUdpAlive                        the pointer to SoAd_TimeoutListUdpAlive
  TimeoutListUdpAliveConfig                  the pointer to SoAd_TimeoutListUdpAliveConfig
  TimeoutListUdpAliveMap                     the pointer to SoAd_TimeoutListUdpAliveMap
  TpRxBuffer                                 the pointer to SoAd_TpRxBuffer
  TpTxBuffer                                 the pointer to SoAd_TpTxBuffer
  TpTxBufferConfig                           the pointer to SoAd_TpTxBufferConfig
  TpTxBufferConfigDyn                        the pointer to SoAd_TpTxBufferConfigDyn
  TriggerBuf                                 the pointer to SoAd_TriggerBuf
  TriggerBufConfig                           the pointer to SoAd_TriggerBufConfig
  TriggerBufConfigDyn                        the pointer to SoAd_TriggerBufConfigDyn
  TxMgt                                      the pointer to SoAd_TxMgt
  TxPduIdMap                                 the pointer to SoAd_TxPduIdMap
  UpperLayer                                 the pointer to SoAd_UpperLayer
  MaxIfRouteGrpTransmitPduSize               the maximum length of all PDUs which can be sent via routing group transmit
  SizeOfBestMatchSoConIdxList                the number of accomplishable value elements in SoAd_BestMatchSoConIdxList
  SizeOfDhcpEventCbk                         the number of accomplishable value elements in SoAd_DhcpEventCbk
  SizeOfEventQueueFlag                       the number of accomplishable value elements in SoAd_EventQueueFlag
  SizeOfEventQueueIdent                      the number of accomplishable value elements in SoAd_EventQueueIdent
  SizeOfEventQueueIfTxRouteGrp               the number of accomplishable value elements in SoAd_EventQueueIfTxRouteGrp
  SizeOfEventQueueIfTxRouteGrpConfig         the number of accomplishable value elements in SoAd_EventQueueIfTxRouteGrpConfig
  SizeOfEventQueueIfUdpPduRoute              the number of accomplishable value elements in SoAd_EventQueueIfUdpPduRoute
  SizeOfEventQueueIfUdpPduRouteConfig        the number of accomplishable value elements in SoAd_EventQueueIfUdpPduRouteConfig
  SizeOfEventQueueMgmt                       the number of accomplishable value elements in SoAd_EventQueueMgmt
  SizeOfEventQueueStateSoCon                 the number of accomplishable value elements in SoAd_EventQueueStateSoCon
  SizeOfEventQueueStateSoConConfig           the number of accomplishable value elements in SoAd_EventQueueStateSoConConfig
  SizeOfEventQueueTpRxSoCon                  the number of accomplishable value elements in SoAd_EventQueueTpRxSoCon
  SizeOfEventQueueTpRxSoConConfig            the number of accomplishable value elements in SoAd_EventQueueTpRxSoConConfig
  SizeOfEventQueueTpTxSoCon                  the number of accomplishable value elements in SoAd_EventQueueTpTxSoCon
  SizeOfEventQueueTpTxSoConConfig            the number of accomplishable value elements in SoAd_EventQueueTpTxSoConConfig
  SizeOfIfRxBuffer                           the number of accomplishable value elements in SoAd_IfRxBuffer
  SizeOfInstance                             the number of accomplishable value elements in SoAd_Instance
  SizeOfInstanceMap                          the number of accomplishable value elements in SoAd_InstanceMap
  SizeOfIpFragBuf                            the number of accomplishable value elements in SoAd_IpFragBuf
  SizeOfIpFragBufConfig                      the number of accomplishable value elements in SoAd_IpFragBufConfig
  SizeOfIpFragMgt                            the number of accomplishable value elements in SoAd_IpFragMgt
  SizeOfLocalAddr                            the number of accomplishable value elements in SoAd_LocalAddr
  SizeOfLocalAddrByTcpIpCtrlInd              the number of accomplishable value elements in SoAd_LocalAddrByTcpIpCtrlInd
  SizeOfLocalAddrIdMap                       the number of accomplishable value elements in SoAd_LocalAddrIdMap
  SizeOfLocalIpAddrAssignmentChgCbk          the number of accomplishable value elements in SoAd_LocalIpAddrAssignmentChgCbk
  SizeOfLocalIpAddrAssignmentChgCbkInd       the number of accomplishable value elements in SoAd_LocalIpAddrAssignmentChgCbkInd
  SizeOfMetaDataRxBuffer                     the number of accomplishable value elements in SoAd_MetaDataRxBuffer
  SizeOfNPduUdpTx                            the number of accomplishable value elements in SoAd_NPduUdpTx
  SizeOfNPduUdpTxBuffer                      the number of accomplishable value elements in SoAd_NPduUdpTxBuffer
  SizeOfNPduUdpTxQueue                       the number of accomplishable value elements in SoAd_NPduUdpTxQueue
  SizeOfPartitionDyn                         the number of accomplishable value elements in SoAd_PartitionDyn
  SizeOfPduRoute                             the number of accomplishable value elements in SoAd_PduRoute
  SizeOfPduRouteDest                         the number of accomplishable value elements in SoAd_PduRouteDest
  SizeOfPduRouteDestBySoConInd               the number of accomplishable value elements in SoAd_PduRouteDestBySoConInd
  SizeOfPduRouteDestInd                      the number of accomplishable value elements in SoAd_PduRouteDestInd
  SizeOfRemAddrIpV4                          the number of accomplishable value elements in SoAd_RemAddrIpV4
  SizeOfRemAddrIpV6                          the number of accomplishable value elements in SoAd_RemAddrIpV6
  SizeOfRemAddrRcv                           the number of accomplishable value elements in SoAd_RemAddrRcv
  SizeOfRouteGrp                             the number of accomplishable value elements in SoAd_RouteGrp
  SizeOfRouteGrpIdMap                        the number of accomplishable value elements in SoAd_RouteGrpIdMap
  SizeOfRouteGrpSoCon                        the number of accomplishable value elements in SoAd_RouteGrpSoCon
  SizeOfRouteGrpSoConByPduRouteDestInd       the number of accomplishable value elements in SoAd_RouteGrpSoConByPduRouteDestInd
  SizeOfRouteGrpSoConBySocketRouteDestInd    the number of accomplishable value elements in SoAd_RouteGrpSoConBySocketRouteDestInd
  SizeOfRxBufStructMgt                       the number of accomplishable value elements in SoAd_RxBufStructMgt
  SizeOfRxBufStructSeg                       the number of accomplishable value elements in SoAd_RxBufStructSeg
  SizeOfRxBufferConfig                       the number of accomplishable value elements in SoAd_RxBufferConfig
  SizeOfRxMgt                                the number of accomplishable value elements in SoAd_RxMgt
  SizeOfRxPduIdIdMap                         the number of accomplishable value elements in SoAd_RxPduIdIdMap
  SizeOfShutdownFinishedCbk                  the number of accomplishable value elements in SoAd_ShutdownFinishedCbk
  SizeOfSoCon                                the number of accomplishable value elements in SoAd_SoCon
  SizeOfSoConGrp                             the number of accomplishable value elements in SoAd_SoConGrp
  SizeOfSoConMap                             the number of accomplishable value elements in SoAd_SoConMap
  SizeOfSoConModeChgCbk                      the number of accomplishable value elements in SoAd_SoConModeChgCbk
  SizeOfSoConModeChgCbkInd                   the number of accomplishable value elements in SoAd_SoConModeChgCbkInd
  SizeOfSocket                               the number of accomplishable value elements in SoAd_Socket
  SizeOfSocketRoute                          the number of accomplishable value elements in SoAd_SocketRoute
  SizeOfSocketRouteDest                      the number of accomplishable value elements in SoAd_SocketRouteDest
  SizeOfSocketRouteInd                       the number of accomplishable value elements in SoAd_SocketRouteInd
  SizeOfSocketTcp                            the number of accomplishable value elements in SoAd_SocketTcp
  SizeOfSocketUdp                            the number of accomplishable value elements in SoAd_SocketUdp
  SizeOfTcpIpCtrl                            the number of accomplishable value elements in SoAd_TcpIpCtrl
  SizeOfTcpKeepAliveGloballyEnabled          the number of accomplishable value elements in SoAd_TcpKeepAliveGloballyEnabled
  SizeOfTcpTxQueue                           the number of accomplishable value elements in SoAd_TcpTxQueue
  SizeOfTcpTxQueueData                       the number of accomplishable value elements in SoAd_TcpTxQueueData
  SizeOfTimeoutListIdent                     the number of accomplishable value elements in SoAd_TimeoutListIdent
  SizeOfTimeoutListMgmt                      the number of accomplishable value elements in SoAd_TimeoutListMgmt
  SizeOfTimeoutListNPduUdpTx                 the number of accomplishable value elements in SoAd_TimeoutListNPduUdpTx
  SizeOfTimeoutListNPduUdpTxConfig           the number of accomplishable value elements in SoAd_TimeoutListNPduUdpTxConfig
  SizeOfTimeoutListNPduUdpTxMap              the number of accomplishable value elements in SoAd_TimeoutListNPduUdpTxMap
  SizeOfTimeoutListTcpAutoConnectConfig      the number of accomplishable value elements in SoAd_TimeoutListTcpAutoConnectConfig
  SizeOfTimeoutListUdpAlive                  the number of accomplishable value elements in SoAd_TimeoutListUdpAlive
  SizeOfTimeoutListUdpAliveConfig            the number of accomplishable value elements in SoAd_TimeoutListUdpAliveConfig
  SizeOfTimeoutListUdpAliveMap               the number of accomplishable value elements in SoAd_TimeoutListUdpAliveMap
  SizeOfTpRxBuffer                           the number of accomplishable value elements in SoAd_TpRxBuffer
  SizeOfTpTxBuffer                           the number of accomplishable value elements in SoAd_TpTxBuffer
  SizeOfTpTxBufferConfig                     the number of accomplishable value elements in SoAd_TpTxBufferConfig
  SizeOfTriggerBuf                           the number of accomplishable value elements in SoAd_TriggerBuf
  SizeOfTriggerBufConfig                     the number of accomplishable value elements in SoAd_TriggerBufConfig
  SizeOfTxMgt                                the number of accomplishable value elements in SoAd_TxMgt
  SizeOfTxPduIdMap                           the number of accomplishable value elements in SoAd_TxPduIdMap
  SizeOfUpperLayer                           the number of accomplishable value elements in SoAd_UpperLayer
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SoAd_PCPartitionConfigType, SOAD_CONST) SoAd_PCPartitionConfig[1];
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * GLOBAL CUSTOM TYPES
 *********************************************************************************************************************/
 /*! Partition config index data type. */
typedef SoAd_PCPartitionConfigIdxOfPartitionIdentifiersType SoAd_PartitionConfigIdxType;

/**********************************************************************************************************************
 * GLOBAL CUSTOM DEFINES
 *********************************************************************************************************************/
# define SOAD_NO_OS_APPL_MAPPED 65535u

 /*! Macros for indirections to routing group socket connection flags. */
# define SoAd_AtomicSetFlagsOfRouteGrpSoConDyn(FLAGSPTR, FLAGS)    (*FLAGSPTR = FLAGS)
# define SoAd_NonAtomicSetSentFlagOfRouteGrpSoConDyn(FLAGSPTR)     (*FLAGSPTR |= SOAD_ROUTEGRPSOCON_MASK_SENT)
# define SoAd_NonAtomicIsTriggeredFlagOfRouteGrpSoConDyn(FLAGSPTR) ((boolean)(((uint8)((*FLAGSPTR) & SOAD_ROUTEGRPSOCON_MASK_TRIGGERED)) == SOAD_ROUTEGRPSOCON_MASK_TRIGGERED))
# define SoAd_NonAtomicIsSentFlagOfRouteGrpSoConDyn(FLAGSPTR)      ((boolean)(((uint8)((*FLAGSPTR) & SOAD_ROUTEGRPSOCON_MASK_SENT)) == SOAD_ROUTEGRPSOCON_MASK_SENT))

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

# define SOAD_START_SEC_VAR_CLEARED_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
# include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

extern P2CONST(SoAd_ConfigType, SOAD_VAR_CLEARED, SOAD_PBCFG) SoAd_ConfigDataPtr;

# define SOAD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
# include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#endif /* SOAD_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: SoAd_Lcfg.h
 *********************************************************************************************************************/

