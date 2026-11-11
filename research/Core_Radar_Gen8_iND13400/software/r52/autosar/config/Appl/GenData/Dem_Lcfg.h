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
 *              File: Dem_Lcfg.h
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

/* configuration, interrupt handling and callback headers use different names
 * for the multiple inclusion protection define, shown in this example. The
 * appropriate names for these files can be taken from this list:
 *
 * Dem_Cfg.h:                   DEM_CFG_H
 * Dem_Lcfg.h:                  DEM_LCFG_H
 * Dem_PBcfg.h:                 DEM_PBFG_H
 * Dem_AdditionalIncludeCfg.h:  DEM_ADDITIONALINCLUDECFG_H
 * Dem_Swc.h:                   DEM_SWC_H
 * Dem_Swc_Types.h:             DEM_SWC_TYPES_H
 */
#if !defined (DEM_LCFG_H)
# define DEM_LCFG_H

/**********************************************************************************************************************
  MISRA JUSTIFICATIONS
**********************************************************************************************************************/

/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */                                          /* External identifier does not differ in 32 significant characters */
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */                                          /* Identifier does not differ in 32 significant characters */


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Dem_SatelliteData_Types.h"
#include "Dem_DTCSelector_Types.h"
#include "Dem_FilterData_Types.h"
#include "Dem_FreezeFrameIterator_Types.h"
#include "Dem_ClearDTC_Types.h"
#include "Dem_Event_Types.h"
#include "Dem_DTCReadoutBuffer_Types.h"
#include "Dem_MemoryEntry_Types.h"
#include "Dem_ERec_Types.h"
#include "Dem_0x1956_Types.h"
#include "Dem_Infra_Types.h"

#include "Os.h"                                                                           /* get: ApplicationType    */

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Dem_CfgPCDataSwitches  Dem_Cfg Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define DEM_CFG_ADMINDATA                                                                           STD_ON
#define DEM_CFG_AGINGDATA                                                                           STD_OFF  /**< DEM_CFG_SUPPORT_AGING_FOR_ALL_DTCS==STD_OFF && DEM_CFG_DATA_AGED_COUNTER==STD_OFF */
#define DEM_CFG_CALIBRATIONERRORREGISTER                                                            STD_ON
#define DEM_CFG_CALIBRATIONOBDDTCTABLE                                                              STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define DEM_CFG_AGINGALLOWEDOFCALIBRATIONOBDDTCTABLE                                                STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_AGINGCYCLECOUNTERTHRESHOLDOFCALIBRATIONOBDDTCTABLE                                  STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_AGINGCYCLEIDOFCALIBRATIONOBDDTCTABLE                                                STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_IMMEDIATENVSTORAGEOFCALIBRATIONOBDDTCTABLE                                          STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_OPERATIONCYCLEIDOFCALIBRATIONOBDDTCTABLE                                            STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_READINESSGROUPOFCALIBRATIONOBDDTCTABLE                                              STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_USEEXTENDEDDATARECORD0X93OFCALIBRATIONOBDDTCTABLE                                   STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_CALLBACKCLEAREVENTALLOWED                                                           STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_CALLBACKDTCSTATUSCHANGED                                                            STD_ON
#define DEM_CFG_CALLBACKGETFDC                                                                      STD_OFF  /**< (DEM_CFG_SUPPORT_DEBOUNCE_MONITORINTERNAL == STD_OFF) */
#define DEM_CFG_CALLBACKJ1939DTCSTATUSCHANGED                                                       STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_CLEARDTCTABLE                                                                       STD_ON
#define DEM_CFG_CLEARDTCNOTIFICATIONFINISHTABLE                                                     STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_CLEARDTCNOTIFICATIONSTARTTABLE                                                      STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_CLIENTTABLE                                                                         STD_ON
#define DEM_CFG_CLEARDTCINDEXOFCLIENTTABLE                                                          STD_ON
#define DEM_CFG_FILTERINDEXOFCLIENTTABLE                                                            STD_ON
#define DEM_CFG_FREEZEFRAMEITERATORINDEXOFCLIENTTABLE                                               STD_ON
#define DEM_CFG_NMNODEIDOFCLIENTTABLE                                                               STD_ON
#define DEM_CFG_READOUTBUFFERINDEXOFCLIENTTABLE                                                     STD_ON
#define DEM_CFG_SELECTORINDEXOFCLIENTTABLE                                                          STD_ON
#define DEM_CFG_COMMITBUFFER                                                                        STD_ON
#define DEM_CFG_COMMONDIDLIST                                                                       STD_ON
#define DEM_CFG_FREEZEFRAMETABLEIDXOFCOMMONDIDLIST                                                  STD_ON
#define DEM_CFG_COMPATIBILITYVERSION                                                                STD_ON
#define DEM_CFG_CONFIGURATIONID                                                                     STD_ON
#define DEM_CFG_COUNTERBASEDDEBOUNCETABLE                                                           STD_ON
#define DEM_CFG_DEBOUNCECONTINUOUSOFCOUNTERBASEDDEBOUNCETABLE                                       STD_ON
#define DEM_CFG_DECREMENTSTEPSIZEOFCOUNTERBASEDDEBOUNCETABLE                                        STD_ON
#define DEM_CFG_EVENTDEBOUNCEBEHAVIOROFCOUNTERBASEDDEBOUNCETABLE                                    STD_ON
#define DEM_CFG_FAILEDTHRESHOLDOFCOUNTERBASEDDEBOUNCETABLE                                          STD_ON
#define DEM_CFG_INCREMENTSTEPSIZEOFCOUNTERBASEDDEBOUNCETABLE                                        STD_ON
#define DEM_CFG_JUMPDOWNOFCOUNTERBASEDDEBOUNCETABLE                                                 STD_ON
#define DEM_CFG_JUMPDOWNVALUEOFCOUNTERBASEDDEBOUNCETABLE                                            STD_ON
#define DEM_CFG_JUMPUPOFCOUNTERBASEDDEBOUNCETABLE                                                   STD_ON
#define DEM_CFG_JUMPUPVALUEOFCOUNTERBASEDDEBOUNCETABLE                                              STD_ON
#define DEM_CFG_MASKEDBITSOFCOUNTERBASEDDEBOUNCETABLE                                               STD_ON
#define DEM_CFG_PASSEDTHRESHOLDOFCOUNTERBASEDDEBOUNCETABLE                                          STD_ON
#define DEM_CFG_STORAGETHRESHOLDOFCOUNTERBASEDDEBOUNCETABLE                                         STD_OFF  /**< DemCounterBasedFdcThresholdStorageValue is not required. */
#define DEM_CFG_CUSTOMTIMESERIESFREEZEFRAMETABLE                                                    STD_OFF  /**< no TimeSeriesSamples for custom triggered events configured */
#define DEM_CFG_FIRSTRECORDNUMBEROFCUSTOMTIMESERIESFREEZEFRAMETABLE                                 STD_OFF  /**< no TimeSeriesSamples for custom triggered events configured */
#define DEM_CFG_LASTRECORDNUMBEROFCUSTOMTIMESERIESFREEZEFRAMETABLE                                  STD_OFF  /**< no TimeSeriesSamples for custom triggered events configured */
#define DEM_CFG_TIMESERIESSAMPLINGPROFILETABLEIDXOFCUSTOMTIMESERIESFREEZEFRAMETABLE                 STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_UPDATERECORDOFCUSTOMTIMESERIESFREEZEFRAMETABLE                                      STD_OFF  /**< no TimeSeriesSamples for custom triggered events configured */
#define DEM_CFG_CUSTOMTRIGGERENTRYINDEXTONVBLOCKINDEX                                               STD_OFF  /**< DEM_CFG_SUPPORT_CUSTOMTRIGGER_SREC ==STD_OFF && DEM_CFG_SUPPORT_CUSTOMTRIGGER_TSSR ==STD_OFF */
#define DEM_CFG_CUSTOMTRIGGERENTRYPTR                                                               STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_CYCLECOUNTERDATA                                                                    STD_OFF  /**< DEM_CFG_SUPPORT_MEM_INDEPENDENT_CYCLE_COUNTERS == STD_OFF */
#define DEM_CFG_CYCLEIDTABLE                                                                        STD_ON
#define DEM_CFG_ENDSONINITOFCYCLEIDTABLE                                                            STD_OFF  /**< no DemOperationCycle/DemOperationCycleAutomaticEnd defined or all defined parameters are 'false' */
#define DEM_CFG_OPCYCLETYPEOFCYCLEIDTABLE                                                           STD_ON
#define DEM_CFG_DTCSELECTORTABLE                                                                    STD_ON
#define DEM_CFG_DTCSTATUSAVAILABILITYMASKINVARIANT                                                  STD_ON
#define DEM_CFG_DATACOLLECTIONTABLE                                                                 STD_ON
#define DEM_CFG_COLLECTIONSIZEOFDATACOLLECTIONTABLE                                                 STD_ON
#define DEM_CFG_DATAELEMENTTABLECOL2ELMTINDDATAELEMENTTABLECOL2ELMTINDENDIDXOFDATACOLLECTIONTABLE   STD_ON
#define DEM_CFG_DATAELEMENTTABLECOL2ELMTINDDATAELEMENTTABLECOL2ELMTINDSTARTIDXOFDATACOLLECTIONTABLE STD_ON
#define DEM_CFG_DATAELEMENTTABLECOL2ELMTINDDATAELEMENTTABLECOL2ELMTINDUSEDOFDATACOLLECTIONTABLE     STD_ON
#define DEM_CFG_EVENTTABLE_EREC2EVENTIDINDENDIDXOFDATACOLLECTIONTABLE                               STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_EVENTTABLE_EREC2EVENTIDINDSTARTIDXOFDATACOLLECTIONTABLE                             STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_EVENTTABLE_EREC2EVENTIDINDUSEDOFDATACOLLECTIONTABLE                                 STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_IDNUMBEROFDATACOLLECTIONTABLE                                                       STD_ON
#define DEM_CFG_STORAGEKINDOFDATACOLLECTIONTABLE                                                    STD_ON
#define DEM_CFG_TRIGGEROFDATACOLLECTIONTABLE                                                        STD_ON
#define DEM_CFG_UPDATEOFDATACOLLECTIONTABLE                                                         STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEEREC2COLLIND                                                     STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEIDXOFDATACOLLECTIONTABLEEDR2COLLIND                              STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEIDXOFDATACOLLECTIONTABLEFFM2COLLIND                              STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEPID2COLLIND                                                      STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_DATAELEMENTTABLE                                                                    STD_ON
#define DEM_CFG_DATAISSTOREDINNVOFDATAELEMENTTABLE                                                  STD_ON
#define DEM_CFG_ELEMENTDATATYPEOFDATAELEMENTTABLE                                                   STD_ON
#define DEM_CFG_ELEMENTKINDOFDATAELEMENTTABLE                                                       STD_ON
#define DEM_CFG_ELEMENTSIZEOFDATAELEMENTTABLE                                                       STD_ON
#define DEM_CFG_READDATAFUNCOFDATAELEMENTTABLE                                                      STD_ON
#define DEM_CFG_DATAELEMENTTABLEIDXOFDATAELEMENTTABLECOL2ELMTIND                                    STD_ON
#define DEM_CFG_DEBOUNCEDATA                                                                        STD_OFF  /**< DEM_CFG_SUPPORT_DEBOUNCE_NV==STD_OFF */
#define DEM_CFG_DEBOUNCEINDIRECTIONTABLE                                                            STD_ON
#define DEM_CFG_COUNTERBASEDDEBOUNCETABLEIDXOFDEBOUNCEINDIRECTIONTABLE                              STD_ON
#define DEM_CFG_COUNTERBASEDDEBOUNCETABLEUSEDOFDEBOUNCEINDIRECTIONTABLE                             STD_ON
#define DEM_CFG_TIMEBASEDDEBOUNCETABLEIDXOFDEBOUNCEINDIRECTIONTABLE                                 STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_TIMEBASEDDEBOUNCETABLEUSEDOFDEBOUNCEINDIRECTIONTABLE                                STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_DTCCALIBTABLE                                                                       STD_ON
#define DEM_CFG_AGINGCYCLECOUNTERTHRESHOLDOFDTCCALIBTABLE                                           STD_ON
#define DEM_CFG_AGINGCYCLEIDOFDTCCALIBTABLE                                                         STD_ON
#define DEM_CFG_DTCPRIORITYOFDTCCALIBTABLE                                                          STD_ON
#define DEM_CFG_DTCSEVERITYOFDTCCALIBTABLE                                                          STD_ON
#define DEM_CFG_UDSDTCOFDTCCALIBTABLE                                                               STD_ON
#define DEM_CFG_DTCGROUPMASK                                                                        STD_OFF  /**< No configured DemGroupOfDTC containers. */
#define DEM_CFG_GROUPMASKOFDTCGROUPMASK                                                             STD_OFF  /**< No configured DemGroupOfDTC containers. */
#define DEM_CFG_UDSGROUPDTCOFDTCGROUPMASK                                                           STD_OFF  /**< No configured DemGroupOfDTC containers. */
#define DEM_CFG_DTCINVARIANTDATATABLE                                                               STD_ON
#define DEM_CFG_AGINGALLOWEDOFDTCINVARIANTDATATABLE                                                 STD_ON
#define DEM_CFG_FREEZEFRAMETABLESECONDSTDFFIDXOFDTCINVARIANTDATATABLE                               STD_ON
#define DEM_CFG_FREEZEFRAMETABLESTDFFIDXOFDTCINVARIANTDATATABLE                                     STD_ON
#define DEM_CFG_FUNCTIONALUNITOFDTCINVARIANTDATATABLE                                               STD_ON
#define DEM_CFG_DTCTABLE                                                                            STD_ON
#define DEM_CFG_CUSTOMTIMESERIESFREEZEFRAMETABLEIDXOFDTCTABLE                                       STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_CUSTOMTIMESERIESFREEZEFRAMETABLEUSEDOFDTCTABLE                                      STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_CUSTOMTRIGGEREDSNAPSHOTCONFIGUREDOFDTCTABLE                                         STD_OFF  /**< No dtc referenced by an event with custom triggered snapshots configured. */
#define DEM_CFG_CUSTOMTRIGGEREDTIMESERIESSNAPSHOTCONFIGUREDOFDTCTABLE                               STD_OFF  /**< No dtc referenced by an event with custom triggered time series snapshots configured. */
#define DEM_CFG_DTCOBDRELEVANCEOFDTCTABLE                                                           STD_OFF  /**< (DEM_CFG_SUPPORT_CALIBRATION_FOR_OBD_RELEVANCE == STD_ON) || ((DEM_CFG_HAS_OBDII_ENABLED == STD_OFF) && (DEM_CFG_SUPPORT_WWHOBD == STD_OFF) && (DEM_CFG_SUPPORT_OBDONUDS == STD_OFF) && (DEM_CFG_SUPPORT_ZEVONUDS == STD_OFF)) */
#define DEM_CFG_EVENTSIGNIFICANCEOFDTCTABLE                                                         STD_ON
#define DEM_CFG_EXTENDEDDATATABLEIDXOFDTCTABLE                                                      STD_ON
#define DEM_CFG_FREEZEFRAMENUMINDIRECTIONTABLEIDXOFDTCTABLE                                         STD_ON
#define DEM_CFG_FREEZEFRAMENUMINDIRECTIONTABLEUSEDOFDTCTABLE                                        STD_ON
#define DEM_CFG_IMMEDIATENVSTORAGEOFDTCTABLE                                                        STD_ON
#define DEM_CFG_J1939DTCOFDTCTABLE                                                                  STD_ON
#define DEM_CFG_J1939NODEIDINDENDIDXOFDTCTABLE                                                      STD_ON
#define DEM_CFG_J1939NODEIDINDSTARTIDXOFDTCTABLE                                                    STD_ON
#define DEM_CFG_J1939NODEIDINDUSEDOFDTCTABLE                                                        STD_ON
#define DEM_CFG_SMARINDEXOFDTCTABLE                                                                 STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_TIMESERIESINDIRECTIONTABLEENDIDXOFDTCTABLE                                          STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_TIMESERIESINDIRECTIONTABLESTARTIDXOFDTCTABLE                                        STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_TIMESERIESINDIRECTIONTABLEUSEDOFDTCTABLE                                            STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_DTRDATA                                                                             STD_OFF  /**< (((DEM_CFG_HAS_OBDII_ENABLED == STD_OFF) && (DEM_CFG_SUPPORT_WWHOBD == STD_OFF) && (DEM_CFG_SUPPORT_OBDONUDS == STD_OFF) && (DEM_CFG_SUPPORT_ZEVONUDS == STD_OFF))) || (DEM_CFG_SUPPORT_DTR==STD_OFF) */
#define DEM_CFG_DTRSTATUS                                                                           STD_OFF  /**< (DEM_CFG_SUPPORT_DTR==STD_OFF) || (((DEM_CFG_HAS_OBDII_ENABLED == STD_OFF) && (DEM_CFG_SUPPORT_WWHOBD == STD_OFF) && (DEM_CFG_SUPPORT_OBDONUDS == STD_OFF) && (DEM_CFG_SUPPORT_ZEVONUDS == STD_OFF))) */
#define DEM_CFG_DTRTABLE                                                                            STD_OFF  /**< No Dtr support. */
#define DEM_CFG_DIVISOROFDTRTABLE                                                                   STD_OFF  /**< No Dtr support. */
#define DEM_CFG_EVENTTABLEIDXOFDTRTABLE                                                             STD_OFF  /**< No Dtr support. */
#define DEM_CFG_LINEARFACTOROFDTRTABLE                                                              STD_OFF  /**< No Dtr support. */
#define DEM_CFG_OFFSETOFDTRTABLE                                                                    STD_OFF  /**< No Dtr support. */
#define DEM_CFG_UASIDOFDTRTABLE                                                                     STD_OFF  /**< No Dtr support. */
#define DEM_CFG_UPDATEKINDOFDTRTABLE                                                                STD_OFF  /**< No Dtr support. */
#define DEM_CFG_DTRTABLEIND                                                                         STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_ENABLECONDITIONFULFILLED                                                            STD_ON
#define DEM_CFG_ENABLECONDITIONGROUPCOUNTER                                                         STD_ON
#define DEM_CFG_ENABLECONDITIONGROUPSTATE                                                           STD_ON
#define DEM_CFG_ENABLECONDITIONGROUPTABLE                                                           STD_ON
#define DEM_CFG_INDEXOFENABLECONDITIONGROUPTABLE                                                    STD_ON
#define DEM_CFG_ENABLECONDITIONGROUPTABLEIND                                                        STD_ON
#define DEM_CFG_ENABLECONDITIONINITTABLE                                                            STD_ON
#define DEM_CFG_FULFILLEDATINITOFENABLECONDITIONINITTABLE                                           STD_ON
#define DEM_CFG_ENABLECONDITIONTABLE                                                                STD_ON
#define DEM_CFG_ENABLECONDITIONGROUPTABLEINDENDIDXOFENABLECONDITIONTABLE                            STD_ON
#define DEM_CFG_ENABLECONDITIONGROUPTABLEINDSTARTIDXOFENABLECONDITIONTABLE                          STD_ON
#define DEM_CFG_ENABLECONDITIONGROUPTABLEINDUSEDOFENABLECONDITIONTABLE                              STD_ON
#define DEM_CFG_ENDIDXOFDEMDIDCLASSINDATACOLLECTIONTABLE                                            STD_ON
#define DEM_CFG_EVENTAVAILABLEDATA                                                                  STD_OFF  /**< DEM_CFG_SUPPORT_EVENTAVAILABLE_NV==STD_OFF */
#define DEM_CFG_EVENTAVAILABLEDEFAULT                                                               STD_ON
#define DEM_CFG_EVENTAVAILABLEINVARIANT                                                             STD_ON
#define DEM_CFG_EVENTCALIBTABLE                                                                     STD_ON
#define DEM_CFG_EVENTFAILURECYCLECOUNTERTHRESHOLDOFEVENTCALIBTABLE                                  STD_ON
#define DEM_CFG_OPERATIONCYCLEIDOFEVENTCALIBTABLE                                                   STD_ON
#define DEM_CFG_EVENTCYCLESTATUS                                                                    STD_OFF  /**< (((DEM_CFG_HAS_OBDII_ENABLED == STD_OFF) && (DEM_CFG_SUPPORT_WWHOBD == STD_OFF) && (DEM_CFG_SUPPORT_OBDONUDS == STD_OFF) && (DEM_CFG_SUPPORT_ZEVONUDS == STD_OFF))) || (DEM_CFG_PROCESS_CDTC_STOREDONLY==STD_OFF) */
#define DEM_CFG_EVENTDATACHANGED                                                                    STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_EVENTDATACOMMITNUMBER                                                               STD_ON
#define DEM_CFG_EVENTENTRYINDEXTONVBLOCKINDEX                                                       STD_ON
#define DEM_CFG_EVENTENTRYINFOTABLE                                                                 STD_ON
#define DEM_CFG_BASEENTRYPTROFEVENTENTRYINFOTABLE                                                   STD_ON
#define DEM_CFG_EXTENDEDDATAPTROFEVENTENTRYINFOTABLE                                                STD_ON
#define DEM_CFG_INITPTROFEVENTENTRYINFOTABLE                                                        STD_ON
#define DEM_CFG_J1939FREEZEFRAMEDATAPTROFEVENTENTRYINFOTABLE                                        STD_ON
#define DEM_CFG_OBDFREEZEFRAMEDATAPTROFEVENTENTRYINFOTABLE                                          STD_ON
#define DEM_CFG_SIZEOFEXTENDEDDATAOFEVENTENTRYINFOTABLE                                             STD_ON
#define DEM_CFG_SIZEOFJ1939EXPFREEZEFRAMEOFEVENTENTRYINFOTABLE                                      STD_ON
#define DEM_CFG_SIZEOFJ1939FREEZEFRAMEOFEVENTENTRYINFOTABLE                                         STD_ON
#define DEM_CFG_SIZEOFOBDFREEZEFRAMEOFEVENTENTRYINFOTABLE                                           STD_ON
#define DEM_CFG_SIZEOFSNAPSHOTDATAOFEVENTENTRYINFOTABLE                                             STD_ON
#define DEM_CFG_SNAPSHOTDATAPTROFEVENTENTRYINFOTABLE                                                STD_ON
#define DEM_CFG_EVENTINDICATORDATA                                                                  STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define DEM_CFG_ASSIGNEDATTRIBUTEBITFIELDOFEVENTINDICATORDATA                                       STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_EVENTHEALINGTARGETOFEVENTINDICATORDATA                                              STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_EVENTINTERNALSTATUS                                                                 STD_ON
#define DEM_CFG_EVENTINVARIANTDATATABLE                                                             STD_ON
#define DEM_CFG_DTCTABLEIDXOFEVENTINVARIANTDATATABLE                                                STD_ON
#define DEM_CFG_EVENTPRECOMPILEDATATABLE                                                            STD_ON
#define DEM_CFG_CALLBACKGETFDCIDXOFEVENTPRECOMPILEDATATABLE                                         STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_DEBOUNCECOUNTERSTORAGEOFEVENTPRECOMPILEDATATABLE                                    STD_ON
#define DEM_CFG_EVENTCONSIDERPTOSTATUSOFEVENTPRECOMPILEDATATABLE                                    STD_OFF  /**< No event configured to be affected by Dem PTO handling. */
#define DEM_CFG_EVENTKINDOFEVENTPRECOMPILEDATATABLE                                                 STD_ON
#define DEM_CFG_EVENTLATCHTFOFEVENTPRECOMPILEDATATABLE                                              STD_ON
#define DEM_CFG_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE                                  STD_ON
#define DEM_CFG_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE                                STD_ON
#define DEM_CFG_EVENTSTATUSCHANGEDUSEDOFEVENTPRECOMPILEDATATABLE                                    STD_ON
#define DEM_CFG_MASKEDBITSOFEVENTPRECOMPILEDATATABLE                                                STD_ON
#define DEM_CFG_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLEENDIDXOFEVENTPRECOMPILEDATATABLE                STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLESTARTIDXOFEVENTPRECOMPILEDATATABLE              STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLEUSEDOFEVENTPRECOMPILEDATATABLE                  STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_MULTIEVENTTRIGGERINGSLAVEOFEVENTPRECOMPILEDATATABLE                                 STD_OFF  /**< No /Dem/DemConfigSet/DemMultiEventTriggering containers exist. */
#define DEM_CFG_SATELLITEEVENTIDXOFEVENTPRECOMPILEDATATABLE                                         STD_ON
#define DEM_CFG_SATELLITEINFOIDXOFEVENTPRECOMPILEDATATABLE                                          STD_ON
#define DEM_CFG_EVENTPRECOMPILEDATATABLEIND                                                         STD_ON
#define DEM_CFG_EVENTSTATUSCHANGED                                                                  STD_ON
#define DEM_CFG_EVENTTABLE                                                                          STD_ON
#define DEM_CFG_DTRTABLEINDENDIDXOFEVENTTABLE                                                       STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_DTRTABLEINDSTARTIDXOFEVENTTABLE                                                     STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_DTRTABLEINDUSEDOFEVENTTABLE                                                         STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_ENABLECONDITIONGROUPTABLEIDXOFEVENTTABLE                                            STD_OFF  /**< the optional indirection is deactivated because EnableConditionGroupTableUsedOfEventTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'. */
#define DEM_CFG_ENABLECONDITIONGROUPTABLEUSEDOFEVENTTABLE                                           STD_OFF  /**< the optional indirection is deactivated because EnableConditionGroupTableUsedOfEventTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'. */
#define DEM_CFG_EVENTCALIBTABLEIDXOFEVENTTABLE                                                      STD_ON
#define DEM_CFG_EVENTDESTINATIONOFEVENTTABLE                                                        STD_ON
#define DEM_CFG_EVENTINDICATORDATAIDXOFEVENTTABLE                                                   STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_EVENTINDICATORDATAUSEDOFEVENTTABLE                                                  STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_EVENTINVARIANTDATATABLEIDXOFEVENTTABLE                                              STD_ON
#define DEM_CFG_EVENTPTOTIMERINDEXOFEVENTTABLE                                                      STD_OFF  /**< No event configured to be affected by Dem PTO handling. */
#define DEM_CFG_FAILEDCYCLECOUNTERINDEXOFEVENTTABLE                                                 STD_OFF  /**< DEM_CFG_SUPPORT_MEM_INDEPENDENT_CYCLE_COUNTERS==STD_OFF || DEM_CFG_DATA_FAILED_CYCLES ==STD_OFF */
#define DEM_CFG_FAULTPENDINGCOUNTERINDEXOFEVENTTABLE                                                STD_OFF  /**< DEM_CFG_SUPPORT_MEM_INDEPENDENT_CYCLE_COUNTERS==STD_OFF || DEM_CFG_DATA_FAULT_PENDING_COUNTER ==STD_OFF */
#define DEM_CFG_MAXFDCSINCELASTCLEARINDEXOFEVENTTABLE                                               STD_OFF  /**< DEM_CFG_SUPPORT_MEM_INDEPENDENT_MAX_FDC_SLC==STD_OFF || DEM_CFG_DATA_MAX_FDC_SINCE_LAST_CLEAR ==STD_OFF */
#define DEM_CFG_MONITORACTIVITYRATIOTABLEIDXOFEVENTTABLE                                            STD_OFF  /**< DEM_CFG_DATA_MONITOR_ACTIVITY_DATA==STD_OFF */
#define DEM_CFG_OBDVISIBILITYDELAYEDUNTILDCYQUALIFICATIONOFEVENTTABLE                               STD_ON
#define DEM_CFG_EVENTTABLE_EREC2EVENTIDIND                                                          STD_OFF  /**< DEM_CFG_SUPPORT_SVC19_16==STD_OFF && DEM_CFG_SUPPORT_SVC19_1A==STD_OFF */
#define DEM_CFG_EXTENDEDDATARECORDITERATORTABLE                                                     STD_ON
#define DEM_CFG_EXTENDEDDATARECORDTABLE                                                             STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEEREC2COLLINDENDIDXOFEXTENDEDDATARECORDTABLE                      STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEEREC2COLLINDSTARTIDXOFEXTENDEDDATARECORDTABLE                    STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEEREC2COLLINDUSEDOFEXTENDEDDATARECORDTABLE                        STD_ON
#define DEM_CFG_EXTENDEDDATATABLE                                                                   STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEEDR2COLLINDDATACOLLECTIONTABLEEDR2COLLINDENDIDXOFEXTENDEDDATATABLE STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEEDR2COLLINDDATACOLLECTIONTABLEEDR2COLLINDSTARTIDXOFEXTENDEDDATATABLE STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEEDR2COLLINDDATACOLLECTIONTABLEEDR2COLLINDUSEDOFEXTENDEDDATATABLE STD_ON
#define DEM_CFG_MAXRECORDSIZEOFEXTENDEDDATATABLE                                                    STD_ON
#define DEM_CFG_FILTERINFOTABLE                                                                     STD_ON
#define DEM_CFG_FINALMAGICNUMBER                                                                    STD_OFF  /**< the module configuration does not support flashing of data. */
#define DEM_CFG_FREEZEFRAMEDATA                                                                     STD_OFF  /**< ((DEM_CFG_HAS_OBDII_ENABLED == STD_OFF) && (DEM_CFG_SUPPORT_OBDONUDS == STD_OFF)) */
#define DEM_CFG_FREEZEFRAMEITERATORTABLE                                                            STD_ON
#define DEM_CFG_FREEZEFRAMENUMINDIRECTIONTABLE                                                      STD_ON
#define DEM_CFG_FREEZEFRAMENUMTABLEENDIDXOFFREEZEFRAMENUMINDIRECTIONTABLE                           STD_ON
#define DEM_CFG_FREEZEFRAMENUMTABLESECONDENDIDXOFFREEZEFRAMENUMINDIRECTIONTABLE                     STD_OFF  /**< the optional indirection is deactivated because FreezeFrameNumTableSecondUsedOfFreezeFrameNumIndirectionTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'. */
#define DEM_CFG_FREEZEFRAMENUMTABLESECONDSTARTIDXOFFREEZEFRAMENUMINDIRECTIONTABLE                   STD_OFF  /**< the optional indirection is deactivated because FreezeFrameNumTableSecondUsedOfFreezeFrameNumIndirectionTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'. */
#define DEM_CFG_FREEZEFRAMENUMTABLESECONDUSEDOFFREEZEFRAMENUMINDIRECTIONTABLE                       STD_OFF  /**< the optional indirection is deactivated because FreezeFrameNumTableSecondUsedOfFreezeFrameNumIndirectionTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'. */
#define DEM_CFG_FREEZEFRAMENUMTABLESTARTIDXOFFREEZEFRAMENUMINDIRECTIONTABLE                         STD_ON
#define DEM_CFG_FREEZEFRAMENUMTABLEUSEDOFFREEZEFRAMENUMINDIRECTIONTABLE                             STD_ON
#define DEM_CFG_FREEZEFRAMENUMTABLE                                                                 STD_ON
#define DEM_CFG_FFNUMBEROFFREEZEFRAMENUMTABLE                                                       STD_ON
#define DEM_CFG_FFTRIGGEROFFREEZEFRAMENUMTABLE                                                      STD_ON
#define DEM_CFG_FFUPDATEOFFREEZEFRAMENUMTABLE                                                       STD_ON
#define DEM_CFG_ISGLOBALOFFREEZEFRAMENUMTABLE                                                       STD_ON
#define DEM_CFG_MASKEDBITSOFFREEZEFRAMENUMTABLE                                                     STD_ON
#define DEM_CFG_FREEZEFRAMETABLE                                                                    STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEFFM2COLLINDDATACOLLECTIONTABLEFFM2COLLINDENDIDXOFFREEZEFRAMETABLE STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEFFM2COLLINDDATACOLLECTIONTABLEFFM2COLLINDSTARTIDXOFFREEZEFRAMETABLE STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEFFM2COLLINDDATACOLLECTIONTABLEFFM2COLLINDUSEDOFFREEZEFRAMETABLE  STD_ON
#define DEM_CFG_RECORDSIZEOFFREEZEFRAMETABLE                                                        STD_ON
#define DEM_CFG_RECORDSIZEUDSOFFREEZEFRAMETABLE                                                     STD_ON
#define DEM_CFG_GENERALJ1939TABLE                                                                   STD_OFF  /**< no DemJ1939FreezeFrameClass (FreezeFrames) */
#define DEM_CFG_RECORDSIZEOFGENERALJ1939TABLE                                                       STD_OFF  /**< no DemJ1939FreezeFrameClass (FreezeFrames) */
#define DEM_CFG_GENERALOBDINPUT                                                                     STD_ON
#define DEM_CFG_DATAELEMENTTABLEIDXOFGENERALOBDINPUT                                                STD_ON
#define DEM_CFG_GLOBALOBDREQUIREMENTS                                                               STD_OFF  /**< ((DEM_CFG_HAS_OBDII_ENABLED == STD_OFF) && (DEM_CFG_SUPPORT_WWHOBD == STD_OFF) && (DEM_CFG_SUPPORT_OBDONUDS == STD_OFF)) */
#define DEM_CFG_GLOBALSEVERITYMASK                                                                  STD_ON
#define DEM_CFG_GLOBALSNAPSHOTRECORD                                                                STD_ON
#define DEM_CFG_FREEZEFRAMETABLEIDXOFGLOBALSNAPSHOTRECORD                                           STD_ON
#define DEM_CFG_INDICATORATTRIBUTETABLE                                                             STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define DEM_CFG_BEHAVIOUROFINDICATORATTRIBUTETABLE                                                  STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_FAILURECYCLECOUNTERTHRESHOLDOFINDICATORATTRIBUTETABLE                               STD_OFF  /**< DemPerIndicatorActivation not supported */
#define DEM_CFG_IDOFINDICATORATTRIBUTETABLE                                                         STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_J1939NODEIDOFINDICATORATTRIBUTETABLE                                                STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_INDICATORDATA                                                                       STD_OFF  /**< DEM_CFG_PER_INDICATOR_ACTIVATION == STD_OFF */
#define DEM_CFG_INDICATOREVENTCOUNTERS                                                              STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_INITDATAHASHCODE                                                                    STD_OFF  /**< the module configuration does not support flashing of data. */
#define DEM_CFG_INITMONLISTFORFUNC                                                                  STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define DEM_CFG_INITMONITORFOREVENT                                                                 STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_INITMONITORSFORFUNC                                                                 STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_J1939EVENTIDSWITHRATIOTABLE                                                         STD_OFF  /**< DemGeneral/DemGeneralJ1939/DemJ1939RatioSupport not supported */
#define DEM_CFG_EVENTIDOFJ1939EVENTIDSWITHRATIOTABLE                                                STD_OFF  /**< DemGeneral/DemGeneralJ1939/DemJ1939RatioSupport not supported */
#define DEM_CFG_J1939NODEID                                                                         STD_ON
#define DEM_CFG_J1939NODEIDIND                                                                      STD_ON
#define DEM_CFG_J1939NODEINDICATORAVAILABILITY                                                      STD_ON
#define DEM_CFG_J1939SPNSINEXPANDEDFREEZEFRAMETABLE                                                 STD_OFF  /**< J1939 Expanded Freeze Frames not supported */
#define DEM_CFG_SPNIDOFJ1939SPNSINEXPANDEDFREEZEFRAMETABLE                                          STD_OFF  /**< J1939 Expanded Freeze Frames not supported */
#define DEM_CFG_SPNSIZEOFJ1939SPNSINEXPANDEDFREEZEFRAMETABLE                                        STD_OFF  /**< J1939 Expanded Freeze Frames not supported */
#define DEM_CFG_MAXNUMBEREVENTENTRYOBDFREEZEFRAME                                                   STD_OFF  /**< ((DEM_CFG_HAS_OBDII_ENABLED == STD_OFF) && (DEM_CFG_SUPPORT_OBDONUDS == STD_OFF)) */
#define DEM_CFG_MEMORYCURRENTCOUNT                                                                  STD_ON
#define DEM_CFG_MEMORYINFOTABLE                                                                     STD_ON
#define DEM_CFG_CHRONOPTROFMEMORYINFOTABLE                                                          STD_ON
#define DEM_CFG_CUSTOMTRIGGERTRANSLATEDMEMORYIDOFMEMORYINFOTABLE                                    STD_ON
#define DEM_CFG_ENABLECONDITIONGROUPTABLECONTROLDTCSETTINGGROUPIDXOFMEMORYINFOTABLE                 STD_ON
#define DEM_CFG_ENABLECONDITIONGROUPTABLECONTROLDTCSETTINGGROUPUSEDOFMEMORYINFOTABLE                STD_ON
#define DEM_CFG_EVENTMEMORYENTRYSTORAGETRIGGEROFMEMORYINFOTABLE                                     STD_ON
#define DEM_CFG_FIRSTENTRYINDEXOFMEMORYINFOTABLE                                                    STD_ON
#define DEM_CFG_FIRSTEVENTOFMEMORYINFOTABLE                                                         STD_ON
#define DEM_CFG_INDIVIDUALERECSIZEOFMEMORYINFOTABLE                                                 STD_ON
#define DEM_CFG_INDIVIDUALSRECSIZEOFMEMORYINFOTABLE                                                 STD_ON
#define DEM_CFG_LASTEVENTOFMEMORYINFOTABLE                                                          STD_ON
#define DEM_CFG_MAXNUMBERTIMESERIESSETSOFMEMORYINFOTABLE                                            STD_ON
#define DEM_CFG_MAXSIZEOFMEMORYINFOTABLE                                                            STD_ON
#define DEM_CFG_SRECNUMTYPEOFMEMORYINFOTABLE                                                        STD_ON
#define DEM_CFG_TIMESERIESFIFOSUPPORTOFMEMORYINFOTABLE                                              STD_ON
#define DEM_CFG_TIMESERIESSETSRECNUMOFFSETOFMEMORYINFOTABLE                                         STD_ON
#define DEM_CFG_TIMESERIESTRANSLATEDMEMORYIDOFMEMORYINFOTABLE                                       STD_ON
#define DEM_CFG_MEMORYSTATUS                                                                        STD_ON
#define DEM_CFG_MIDTABLE                                                                            STD_OFF  /**< No Dtr support. */
#define DEM_CFG_DTRTABLEIDXOFMIDTABLE                                                               STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_MIDOFMIDTABLE                                                                       STD_OFF  /**< No Dtr support. */
#define DEM_CFG_TIDOFMIDTABLE                                                                       STD_OFF  /**< No Dtr support. */
#define DEM_CFG_MIRRORDATA                                                                          STD_OFF  /**< DEM_CFG_SUPPORT_MIRROR==STD_OFF */
#define DEM_CFG_MONITORACTIVITYRATIOTABLE                                                           STD_ON
#define DEM_CFG_MARINDEXOFMONITORACTIVITYRATIOTABLE                                                 STD_ON
#define DEM_CFG_SMARINDEXOFMONITORACTIVITYRATIOTABLE                                                STD_ON
#define DEM_CFG_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLE                                                STD_OFF  /**< No /Dem/DemConfigSet/DemMultiEventTriggering containers exist. */
#define DEM_CFG_EVENTPRECOMPILEDATATABLEIDXOFMULTIEVENTTRIGGERINGSLAVEEVENTSTABLE                   STD_OFF  /**< No /Dem/DemConfigSet/DemMultiEventTriggering containers exist. */
#define DEM_CFG_NODTCCONFIGURED                                                                     STD_ON
#define DEM_CFG_NVBLOCKDATAPTR                                                                      STD_ON
#define DEM_CFG_NVBLOCKDATASIZE                                                                     STD_ON
#define DEM_CFG_NVBLOCKID                                                                           STD_ON
#define DEM_CFG_OBDCALIBTABLE                                                                       STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define DEM_CFG_CALIBRATIONOBDDTCTABLEIDXOFOBDCALIBTABLE                                            STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_CALIBRATIONOBDDTCTABLEUSEDOFOBDCALIBTABLE                                           STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_OBDDTC3BYTEOFOBDCALIBTABLE                                                          STD_OFF  /**< (DEM_CFG_SUPPORT_OBD_UDS_DTC_SEPARATION == STD_OFF) */
#define DEM_CFG_OBDDTCOFOBDCALIBTABLE                                                               STD_OFF  /**< (DEM_CFG_HAS_OBDII_ENABLED == STD_OFF) */
#define DEM_CFG_READINESSGROUPOFOBDCALIBTABLE                                                       STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_OBDIUMPRDATA                                                                        STD_OFF  /**< (((DEM_CFG_HAS_OBDII_ENABLED == STD_OFF) && (DEM_CFG_SUPPORT_WWHOBD == STD_OFF) && (DEM_CFG_SUPPORT_OBDONUDS == STD_OFF) && (DEM_CFG_SUPPORT_ZEVONUDS == STD_OFF))) || (DEM_CFG_SUPPORT_IUMPR==STD_OFF && DEM_MONITOR_ACTIVITY_DATA==STD_OFF) */
#define DEM_CFG_OBDIUMPRUPDATEPENDING                                                               STD_OFF  /**< (((DEM_CFG_HAS_OBDII_ENABLED == STD_OFF) && (DEM_CFG_SUPPORT_WWHOBD == STD_OFF) && (DEM_CFG_SUPPORT_OBDONUDS == STD_OFF) && (DEM_CFG_SUPPORT_ZEVONUDS == STD_OFF))) || (DEM_CFG_SUPPORT_IUMPR==STD_OFF) */
#define DEM_CFG_PIDF501READINESSSUPPORTEDANDCOMPLETEDENFORCEMENTMASK                                STD_ON
#define DEM_CFG_PIDF501READINESSUNSUPPORTEDENFORCEMENTMASK                                          STD_ON
#define DEM_CFG_PENDINGEVALUATEDFORCONFIRMEDANDACTIVECONDITIONINVARIANT                             STD_OFF  /**< DEM_CFG_SUPPORT_WWHOBD==STD_OFF */
#define DEM_CFG_PERMANENTDATA                                                                       STD_OFF  /**< (DEM_CFG_SUPPORT_PERMANENT==STD_OFF) || (((DEM_CFG_HAS_OBDII_ENABLED == STD_OFF) && (DEM_CFG_SUPPORT_WWHOBD == STD_OFF) && (DEM_CFG_SUPPORT_OBDONUDS == STD_OFF) && (DEM_CFG_SUPPORT_ZEVONUDS == STD_OFF))) */
#define DEM_CFG_PIDTABLE                                                                            STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define DEM_CFG_DATACOLLECTIONTABLEPID2COLLINDENDIDXOFPIDTABLE                                      STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_DATACOLLECTIONTABLEPID2COLLINDSTARTIDXOFPIDTABLE                                    STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_DATACOLLECTIONTABLEPID2COLLINDUSEDOFPIDTABLE                                        STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_PRESTORAGE                                                                          STD_OFF  /**< DEM_CFG_SUPPORT_PRESTORED_FF==STD_OFF */
#define DEM_CFG_PRESTORAGEINDEX                                                                     STD_OFF  /**< DEM_CFG_SUPPORT_PRESTORED_FF==STD_OFF */
#define DEM_CFG_PRIMARYCHRONOLOGY                                                                   STD_ON
#define DEM_CFG_PRIMARYENTRY_0                                                                      STD_ON
#define DEM_CFG_PRIMARYENTRY_1                                                                      STD_ON
#define DEM_CFG_PRIMARYENTRY_2                                                                      STD_ON
#define DEM_CFG_PRIMARYENTRY_3                                                                      STD_ON
#define DEM_CFG_PRIMARYENTRY_4                                                                      STD_ON
#define DEM_CFG_PRIMARYENTRY_5                                                                      STD_ON
#define DEM_CFG_PRIMARYENTRY_6                                                                      STD_ON
#define DEM_CFG_PRIMARYENTRY_7                                                                      STD_ON
#define DEM_CFG_PRIMARYENTRY_8                                                                      STD_ON
#define DEM_CFG_PRIMARYENTRY_9                                                                      STD_ON
#define DEM_CFG_PRIMARYEVENTENTRYINIT                                                               STD_ON
#define DEM_CFG_RATIOIDTABLE                                                                        STD_OFF  /**< no OBD support or no DemRatioId container configured */
#define DEM_CFG_READOUTBUFFER                                                                       STD_ON
#define DEM_CFG_REPORTEDEVENTSOFFILTER                                                              STD_ON
#define DEM_CFG_RINGBUFFER                                                                          STD_OFF  /**< no TimeSeriesSamples configured */
#define DEM_CFG_SAMPLINGPROFILEDIDINFOTABLE                                                         STD_OFF  /**< Feature Generic Time Series not configured */
#define DEM_CFG_DATACOLLECTIONTABLEIDXOFSAMPLINGPROFILEDIDINFOTABLE                                 STD_OFF  /**< Feature Generic Time Series not configured */
#define DEM_CFG_DIDRINGBUFFEROFFSETOFSAMPLINGPROFILEDIDINFOTABLE                                    STD_OFF  /**< Feature Generic Time Series not configured */
#define DEM_CFG_SATELLITEINFO                                                                       STD_ON
#define DEM_CFG_APPLICATIONIDOFSATELLITEINFO                                                        STD_ON
#define DEM_CFG_DEBOUNCELORESTIMEROFSATELLITEINFO                                                   STD_OFF  /**< No LowRes Timebased Debouncing support (DEM_CFG_SUPPORT_DEBOUNCE_TIME_LR == STD_OFF) */
#define DEM_CFG_EVENTCOUNTOFSATELLITEINFO                                                           STD_ON
#define DEM_CFG_EVENTPRECOMPILEDATATABLEINDENDIDXOFSATELLITEINFO                                    STD_ON
#define DEM_CFG_EVENTPRECOMPILEDATATABLEINDSTARTIDXOFSATELLITEINFO                                  STD_ON
#define DEM_CFG_EVENTPRECOMPILEDATATABLEINDUSEDOFSATELLITEINFO                                      STD_ON
#define DEM_CFG_MAXDEBOUNCEVALUESOFSATELLITEINFO                                                    STD_OFF  /**< Neither DataElement type DEM_MAX_FDC_SINCE_LAST_CLEAR nor DEM_MAX_FDC_DURING_CURRENT_CYCLE is used (DEM_CFG_DATA_MAX_FDC_SINCE_LAST_CLEAR == STD_OFF) && (DEM_CFG_DATA_MAX_FDC_DURING_CURRENT_CYCLE == STD_OFF) */
#define DEM_CFG_SATELLITEDATAOFSATELLITEINFO                                                        STD_ON
#define DEM_CFG_SATELLITEEXTENDEDDATAOFSATELLITEINFO                                                STD_OFF  /**< (DEM_CFG_SUPPORT_PRESTORED_FF == STD_OFF) && (DEM_CFG_SUPPORT_EXTENDED_FIM == STD_OFF) && (Total number of events with Pto Timer required == 0) && no event references a custom triggered snapshot && disable event monitoring is not used */
#define DEM_CFG_SATELLITESTATUSOFSATELLITEINFO                                                      STD_ON
#define DEM_CFG_SATELLITEINFOINVALID_OSAPPLICATION                                                  STD_ON
#define DEM_CFG_SATELLITETIMEDEBOUNCEINFO                                                           STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define DEM_CFG_TIMEBASEDEVENTTABLEENDIDXOFSATELLITETIMEDEBOUNCEINFO                                STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_TIMEBASEDEVENTTABLESTARTIDXOFSATELLITETIMEDEBOUNCEINFO                              STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_TIMEBASEDEVENTTABLEUSEDOFSATELLITETIMEDEBOUNCEINFO                                  STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_SIZEOFCALIBRATIONOBDDTCTABLE                                                        STD_ON
#define DEM_CFG_SIZEOFCALLBACKCLEAREVENTALLOWED                                                     STD_ON
#define DEM_CFG_SIZEOFCALLBACKDTCSTATUSCHANGED                                                      STD_ON
#define DEM_CFG_SIZEOFCALLBACKGETFDC                                                                STD_ON
#define DEM_CFG_SIZEOFCALLBACKJ1939DTCSTATUSCHANGED                                                 STD_ON
#define DEM_CFG_SIZEOFCLEARDTCTABLE                                                                 STD_ON
#define DEM_CFG_SIZEOFCLEARDTCNOTIFICATIONFINISHTABLE                                               STD_ON
#define DEM_CFG_SIZEOFCLEARDTCNOTIFICATIONSTARTTABLE                                                STD_ON
#define DEM_CFG_SIZEOFCLIENTTABLE                                                                   STD_ON
#define DEM_CFG_SIZEOFCOUNTERBASEDDEBOUNCETABLE                                                     STD_ON
#define DEM_CFG_SIZEOFCUSTOMTIMESERIESFREEZEFRAMETABLE                                              STD_ON
#define DEM_CFG_SIZEOFCUSTOMTRIGGERENTRYINDEXTONVBLOCKINDEX                                         STD_ON
#define DEM_CFG_SIZEOFCUSTOMTRIGGERENTRYPTR                                                         STD_ON
#define DEM_CFG_SIZEOFDTCSELECTORTABLE                                                              STD_ON
#define DEM_CFG_SIZEOFDATACOLLECTIONTABLE                                                           STD_ON
#define DEM_CFG_SIZEOFDATAELEMENTTABLE                                                              STD_ON
#define DEM_CFG_SIZEOFDTCGROUPMASK                                                                  STD_ON
#define DEM_CFG_SIZEOFDTCTABLE                                                                      STD_ON
#define DEM_CFG_SIZEOFDTRSTATUS                                                                     STD_ON
#define DEM_CFG_SIZEOFDTRTABLE                                                                      STD_ON
#define DEM_CFG_SIZEOFENABLECONDITIONFULFILLED                                                      STD_ON
#define DEM_CFG_SIZEOFENABLECONDITIONGROUPCOUNTER                                                   STD_ON
#define DEM_CFG_SIZEOFENABLECONDITIONGROUPSTATE                                                     STD_ON
#define DEM_CFG_SIZEOFENABLECONDITIONGROUPTABLE                                                     STD_ON
#define DEM_CFG_SIZEOFENABLECONDITIONTABLE                                                          STD_ON
#define DEM_CFG_SIZEOFEVENTCYCLESTATUS                                                              STD_ON
#define DEM_CFG_SIZEOFEVENTDATACHANGED                                                              STD_ON
#define DEM_CFG_SIZEOFEVENTDATACOMMITNUMBER                                                         STD_ON
#define DEM_CFG_SIZEOFEVENTENTRYINDEXTONVBLOCKINDEX                                                 STD_ON
#define DEM_CFG_SIZEOFEVENTENTRYINFOTABLE                                                           STD_ON
#define DEM_CFG_SIZEOFEVENTINDICATORDATA                                                            STD_ON
#define DEM_CFG_SIZEOFEVENTINTERNALSTATUS                                                           STD_ON
#define DEM_CFG_SIZEOFEVENTSTATUSCHANGED                                                            STD_ON
#define DEM_CFG_SIZEOFEVENTTABLE                                                                    STD_ON
#define DEM_CFG_SIZEOFEXTENDEDDATARECORDITERATORTABLE                                               STD_ON
#define DEM_CFG_SIZEOFFILTERINFOTABLE                                                               STD_ON
#define DEM_CFG_SIZEOFFREEZEFRAMEITERATORTABLE                                                      STD_ON
#define DEM_CFG_SIZEOFFREEZEFRAMETABLE                                                              STD_ON
#define DEM_CFG_SIZEOFGLOBALSNAPSHOTRECORD                                                          STD_ON
#define DEM_CFG_SIZEOFINDICATORATTRIBUTETABLE                                                       STD_ON
#define DEM_CFG_SIZEOFINDICATOREVENTCOUNTERS                                                        STD_ON
#define DEM_CFG_SIZEOFINITMONITORFOREVENT                                                           STD_ON
#define DEM_CFG_SIZEOFINITMONITORSFORFUNC                                                           STD_ON
#define DEM_CFG_SIZEOFJ1939SPNSINEXPANDEDFREEZEFRAMETABLE                                           STD_ON
#define DEM_CFG_SIZEOFMEMORYCURRENTCOUNT                                                            STD_ON
#define DEM_CFG_SIZEOFMEMORYINFOTABLE                                                               STD_ON
#define DEM_CFG_SIZEOFMEMORYSTATUS                                                                  STD_ON
#define DEM_CFG_SIZEOFMONITORACTIVITYRATIOTABLE                                                     STD_ON
#define DEM_CFG_SIZEOFOBDIUMPRUPDATEPENDING                                                         STD_ON
#define DEM_CFG_SIZEOFPRESTORAGEINDEX                                                               STD_ON
#define DEM_CFG_SIZEOFPRIMARYCHRONOLOGY                                                             STD_ON
#define DEM_CFG_SIZEOFRATIOIDTABLE                                                                  STD_ON
#define DEM_CFG_SIZEOFREADOUTBUFFER                                                                 STD_ON
#define DEM_CFG_SIZEOFREPORTEDEVENTSOFFILTER                                                        STD_ON
#define DEM_CFG_SIZEOFSATELLITEINFO                                                                 STD_ON
#define DEM_CFG_SIZEOFSPNTOEVENTSWITHRATIOTABLE                                                     STD_ON
#define DEM_CFG_SIZEOFSTARTIDX500MIDENRATIOTABLE                                                    STD_ON
#define DEM_CFG_SIZEOFSTORAGECONDITIONFULFILLED                                                     STD_ON
#define DEM_CFG_SIZEOFSTORAGECONDITIONGROUPCOUNTER                                                  STD_ON
#define DEM_CFG_SIZEOFSTORAGECONDITIONGROUPTABLE                                                    STD_ON
#define DEM_CFG_SIZEOFSTORAGECONDITIONTABLE                                                         STD_ON
#define DEM_CFG_SIZEOFSUPPORTEDMIDSTABLE                                                            STD_ON
#define DEM_CFG_SIZEOFTIMEBASEDDEBOUNCETABLE                                                        STD_ON
#define DEM_CFG_SIZEOFTIMEBASEDEVENTTABLE                                                           STD_ON
#define DEM_CFG_SIZEOFTIMESERIESENTRYINDEXTONVBLOCKINDEX                                            STD_ON
#define DEM_CFG_SIZEOFTIMESERIESENTRYTABLE                                                          STD_ON
#define DEM_CFG_SIZEOFTIMESERIESSAMPLINGPROFILETABLE                                                STD_ON
#define DEM_CFG_SPNTOEVENTSWITHRATIOTABLE                                                           STD_OFF  /**< DemGeneral/DemGeneralJ1939/DemJ1939RatioSupport not supported */
#define DEM_CFG_J1939EVENTIDSWITHRATIOTABLEENDIDXOFSPNTOEVENTSWITHRATIOTABLE                        STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_J1939EVENTIDSWITHRATIOTABLESTARTIDXOFSPNTOEVENTSWITHRATIOTABLE                      STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_SPNOFSPNTOEVENTSWITHRATIOTABLE                                                      STD_OFF  /**< DemGeneral/DemGeneralJ1939/DemJ1939RatioSupport not supported */
#define DEM_CFG_STARTIDX500MIDENRATIOTABLE                                                          STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define DEM_CFG_STARTIDXOFDEMDIDCLASSINDATACOLLECTIONTABLE                                          STD_ON
#define DEM_CFG_STATUSDATA                                                                          STD_ON
#define DEM_CFG_STORAGECONDITIONFULFILLED                                                           STD_OFF  /**< (DEM_CFG_HAS_STORAGE_CONDITIONS == STD_OFF) */
#define DEM_CFG_STORAGECONDITIONGROUPCOUNTER                                                        STD_OFF  /**< (DEM_CFG_HAS_STORAGE_CONDITIONS == STD_OFF) */
#define DEM_CFG_STORAGECONDITIONGROUPTABLE                                                          STD_OFF  /**< (DEM_CFG_HAS_STORAGE_CONDITIONS == STD_OFF) */
#define DEM_CFG_INDEXOFSTORAGECONDITIONGROUPTABLE                                                   STD_OFF  /**< (DEM_CFG_HAS_STORAGE_CONDITIONS == STD_OFF) */
#define DEM_CFG_STORAGECONDITIONGROUPTABLEIND                                                       STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_STORAGECONDITIONINITTABLE                                                           STD_OFF  /**< (DEM_CFG_HAS_STORAGE_CONDITIONS == STD_OFF) */
#define DEM_CFG_FULFILLEDATINITOFSTORAGECONDITIONINITTABLE                                          STD_OFF  /**< (DEM_CFG_HAS_STORAGE_CONDITIONS == STD_OFF) */
#define DEM_CFG_STORAGECONDITIONTABLE                                                               STD_OFF  /**< (DEM_CFG_HAS_STORAGE_CONDITIONS == STD_OFF) */
#define DEM_CFG_STORAGECONDITIONGROUPTABLEINDENDIDXOFSTORAGECONDITIONTABLE                          STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_STORAGECONDITIONGROUPTABLEINDSTARTIDXOFSTORAGECONDITIONTABLE                        STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_STORAGECONDITIONGROUPTABLEINDUSEDOFSTORAGECONDITIONTABLE                            STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_SUPPORTEDMIDSTABLE                                                                  STD_OFF  /**< No Dtr support. */
#define DEM_CFG_STARTIDXMIDTABLEOFSUPPORTEDMIDSTABLE                                                STD_OFF  /**< No Dtr support. */
#define DEM_CFG_TIMEBASEDDEBOUNCETABLE                                                              STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define DEM_CFG_DEBOUNCECONTINUOUSOFTIMEBASEDDEBOUNCETABLE                                          STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_EVENTDEBOUNCEBEHAVIOROFTIMEBASEDDEBOUNCETABLE                                       STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_FAILTIMERTHRESHOLDHIGHRESOFTIMEBASEDDEBOUNCETABLE                                   STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_FAILTIMERTHRESHOLDLOWRESOFTIMEBASEDDEBOUNCETABLE                                    STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_ISLOWRESOLUTIONOFTIMEBASEDDEBOUNCETABLE                                             STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_PASSTIMERTHRESHOLDHIGHRESOFTIMEBASEDDEBOUNCETABLE                                   STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_PASSTIMERTHRESHOLDLOWRESOFTIMEBASEDDEBOUNCETABLE                                    STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_STORAGETIMERTHRESHOLDHIGHRESOFTIMEBASEDDEBOUNCETABLE                                STD_OFF  /**< DemTimeBasedFdcThresholdStorageValue is not required.  */
#define DEM_CFG_STORAGETIMERTHRESHOLDLOWRESOFTIMEBASEDDEBOUNCETABLE                                 STD_OFF  /**< DemTimeBasedFdcThresholdStorageValue is not required.  */
#define DEM_CFG_TIMEBASEDEVENTTABLE                                                                 STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_TIMESERIESENTRYINDEXTONVBLOCKINDEX                                                  STD_OFF  /**< DEM_CFG_SUPPORT_TIME_SERIES_PAST==STD_OFF && DEM_CFG_SUPPORT_TIME_SERIES_FUTURE==STD_OFF */
#define DEM_CFG_TIMESERIESENTRYTABLE                                                                STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define DEM_CFG_BASEENTRYOFTIMESERIESENTRYTABLE                                                     STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_BUFFERSIZEOFTIMESERIESENTRYTABLE                                                    STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_ENTRYDATAOFTIMESERIESENTRYTABLE                                                     STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_MAXSNAPSHOTSIZEOFTIMESERIESENTRYTABLE                                               STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_TIMESERIESFREEZEFRAMETABLE                                                          STD_OFF  /**< no TimeSeriesSamples configured */
#define DEM_CFG_FIRSTRECORDNUMBEROFTIMESERIESFREEZEFRAMETABLE                                       STD_OFF  /**< no TimeSeriesSamples configured */
#define DEM_CFG_LASTRECORDNUMBEROFTIMESERIESFREEZEFRAMETABLE                                        STD_OFF  /**< no TimeSeriesSamples configured */
#define DEM_CFG_RECORDTRIGGEROFTIMESERIESFREEZEFRAMETABLE                                           STD_OFF  /**< no TimeSeriesSamples configured */
#define DEM_CFG_TIMESERIESSAMPLINGPROFILETABLEIDXOFTIMESERIESFREEZEFRAMETABLE                       STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_UPDATERECORDOFTIMESERIESFREEZEFRAMETABLE                                            STD_OFF  /**< no TimeSeriesSamples configured */
#define DEM_CFG_TIMESERIESINDIRECTIONTABLE                                                          STD_OFF  /**< no TimeSeriesSamples configured */
#define DEM_CFG_TIMESERIESFREEZEFRAMETABLEIDXOFTIMESERIESINDIRECTIONTABLE                           STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_TIMESERIESSAMPLINGPROFILECALIBTABLE                                                 STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define DEM_CFG_DATACOLLECTIONTABLEIDXOFTIMESERIESSAMPLINGPROFILECALIBTABLE                         STD_OFF  /**< Feature Time Series Powertrain not configured */
#define DEM_CFG_PASTSAMPLESOFTIMESERIESSAMPLINGPROFILECALIBTABLE                                    STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_SAMPLINGPERIODTICSOFTIMESERIESSAMPLINGPROFILECALIBTABLE                             STD_OFF  /**< the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define DEM_CFG_SAMPLINGPROFILEDIDINFOTABLEENDIDXOFTIMESERIESSAMPLINGPROFILECALIBTABLE              STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_SAMPLINGPROFILEDIDINFOTABLESTARTIDXOFTIMESERIESSAMPLINGPROFILECALIBTABLE            STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_SAMPLINGPROFILEDIDINFOTABLEUSEDOFTIMESERIESSAMPLINGPROFILECALIBTABLE                STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_TIMESERIESSAMPLINGPROFILETABLE                                                      STD_OFF  /**< no TimeSeriesSamples configured */
#define DEM_CFG_RINGBUFFERPTROFTIMESERIESSAMPLINGPROFILETABLE                                       STD_OFF  /**< no TimeSeriesSamples configured */
#define DEM_CFG_RINGBUFFERSAMPLESOFTIMESERIESSAMPLINGPROFILETABLE                                   STD_OFF  /**< no TimeSeriesSamples configured */
#define DEM_CFG_SAMPLESIZEOFTIMESERIESSAMPLINGPROFILETABLE                                          STD_OFF  /**< no TimeSeriesSamples configured */
#define DEM_CFG_SEQUENTIALDIDIDOFTIMESERIESSAMPLINGPROFILETABLE                                     STD_OFF  /**< no TimeSeriesSamples configured */
#define DEM_CFG_TIMESERIESSAMPLINGPROFILECALIBTABLEIDXOFTIMESERIESSAMPLINGPROFILETABLE              STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_TOTALSAMPLESOFTIMESERIESSAMPLINGPROFILETABLE                                        STD_OFF  /**< no TimeSeriesSamples configured */
#define DEM_CFG_USEOBDIIOROBDONUDSINVARIANT                                                         STD_ON
#define DEM_CFG_USEOBDONUDSINVARIANT                                                                STD_ON
#define DEM_CFG_USEPERMANENTINVARIANT                                                               STD_OFF  /**< DEM_CFG_SUPPORT_PERMANENT==STD_OFF */
#define DEM_CFG_USEREADINESSSUPPORTANDCOMPLETENESSENFORCEMENTMASKINVARIANT                          STD_ON
#define DEM_CFG_USEREADINESSUNSUPPORTEDENFORCEMENTBITMASKINVARIANT                                  STD_ON
#define DEM_CFG_USEWWHOBDINVARIANT                                                                  STD_ON
#define DEM_CFG_USEZEVONUDSINVARIANT                                                                STD_ON
#define DEM_CFG_USERDEFINEDORIGINTABLE                                                              STD_OFF  /**< the struct is deactivated because all elements are deactivated in all variants. */
#define DEM_CFG_MEMORYINFOTABLEIDXOFUSERDEFINEDORIGINTABLE                                          STD_OFF  /**< the optional indirection is deactivated because MemoryInfoTableUsedOfUserDefinedOriginTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'. */
#define DEM_CFG_MEMORYINFOTABLEUSEDOFUSERDEFINEDORIGINTABLE                                         STD_OFF  /**< the optional indirection is deactivated because MemoryInfoTableUsedOfUserDefinedOriginTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'. */
#define DEM_PCCONFIG                                                                                STD_ON
#define DEM_CFG_ADMINDATAOFPCCONFIG                                                                 STD_ON
#define DEM_CFG_AGINGDATAOFPCCONFIG                                                                 STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_CALIBRATIONERRORREGISTEROFPCCONFIG                                                  STD_ON
#define DEM_CFG_CALIBRATIONOBDDTCTABLEOFPCCONFIG                                                    STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_CALLBACKCLEAREVENTALLOWEDOFPCCONFIG                                                 STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_CALLBACKDTCSTATUSCHANGEDOFPCCONFIG                                                  STD_ON
#define DEM_CFG_CALLBACKGETFDCOFPCCONFIG                                                            STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_CALLBACKJ1939DTCSTATUSCHANGEDOFPCCONFIG                                             STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_CLEARDTCTABLEOFPCCONFIG                                                             STD_ON
#define DEM_CFG_CLEARDTCNOTIFICATIONFINISHTABLEOFPCCONFIG                                           STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_CLEARDTCNOTIFICATIONSTARTTABLEOFPCCONFIG                                            STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_CLIENTTABLEOFPCCONFIG                                                               STD_ON
#define DEM_CFG_COMMITBUFFEROFPCCONFIG                                                              STD_ON
#define DEM_CFG_COMMONDIDLISTOFPCCONFIG                                                             STD_ON
#define DEM_CFG_COMPATIBILITYVERSIONOFPCCONFIG                                                      STD_ON
#define DEM_CFG_CONFIGURATIONIDOFPCCONFIG                                                           STD_ON
#define DEM_CFG_COUNTERBASEDDEBOUNCETABLEOFPCCONFIG                                                 STD_ON
#define DEM_CFG_CUSTOMTIMESERIESFREEZEFRAMETABLEOFPCCONFIG                                          STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_CUSTOMTRIGGERENTRYINDEXTONVBLOCKINDEXOFPCCONFIG                                     STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_CUSTOMTRIGGERENTRYPTROFPCCONFIG                                                     STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_CYCLECOUNTERDATAOFPCCONFIG                                                          STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_CYCLEIDTABLEOFPCCONFIG                                                              STD_ON
#define DEM_CFG_DTCSELECTORTABLEOFPCCONFIG                                                          STD_ON
#define DEM_CFG_DTCSTATUSAVAILABILITYMASKINVARIANTOFPCCONFIG                                        STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEEREC2COLLINDOFPCCONFIG                                           STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEIDXOFDATACOLLECTIONTABLEEDR2COLLINDOFPCCONFIG                    STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEIDXOFDATACOLLECTIONTABLEFFM2COLLINDOFPCCONFIG                    STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEOFPCCONFIG                                                       STD_ON
#define DEM_CFG_DATACOLLECTIONTABLEPID2COLLINDOFPCCONFIG                                            STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_DATAELEMENTTABLEIDXOFDATAELEMENTTABLECOL2ELMTINDOFPCCONFIG                          STD_ON
#define DEM_CFG_DATAELEMENTTABLEOFPCCONFIG                                                          STD_ON
#define DEM_CFG_DEBOUNCEDATAOFPCCONFIG                                                              STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_DEBOUNCEINDIRECTIONTABLEOFPCCONFIG                                                  STD_ON
#define DEM_CFG_DTCCALIBTABLEOFPCCONFIG                                                             STD_ON
#define DEM_CFG_DTCGROUPMASKOFPCCONFIG                                                              STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_DTCINVARIANTDATATABLEOFPCCONFIG                                                     STD_ON
#define DEM_CFG_DTCTABLEOFPCCONFIG                                                                  STD_ON
#define DEM_CFG_DTRDATAOFPCCONFIG                                                                   STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_DTRSTATUSOFPCCONFIG                                                                 STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_DTRTABLEINDOFPCCONFIG                                                               STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_DTRTABLEOFPCCONFIG                                                                  STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_ENABLECONDITIONFULFILLEDOFPCCONFIG                                                  STD_ON
#define DEM_CFG_ENABLECONDITIONGROUPCOUNTEROFPCCONFIG                                               STD_ON
#define DEM_CFG_ENABLECONDITIONGROUPSTATEOFPCCONFIG                                                 STD_ON
#define DEM_CFG_ENABLECONDITIONGROUPTABLEINDOFPCCONFIG                                              STD_ON
#define DEM_CFG_ENABLECONDITIONGROUPTABLEOFPCCONFIG                                                 STD_ON
#define DEM_CFG_ENABLECONDITIONINITTABLEOFPCCONFIG                                                  STD_ON
#define DEM_CFG_ENABLECONDITIONTABLEOFPCCONFIG                                                      STD_ON
#define DEM_CFG_ENDIDXOFDEMDIDCLASSINDATACOLLECTIONTABLEOFPCCONFIG                                  STD_ON
#define DEM_CFG_EVENTAVAILABLEDATAOFPCCONFIG                                                        STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_EVENTAVAILABLEDEFAULTOFPCCONFIG                                                     STD_ON
#define DEM_CFG_EVENTAVAILABLEINVARIANTOFPCCONFIG                                                   STD_ON
#define DEM_CFG_EVENTCALIBTABLEOFPCCONFIG                                                           STD_ON
#define DEM_CFG_EVENTCYCLESTATUSOFPCCONFIG                                                          STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_EVENTDATACHANGEDOFPCCONFIG                                                          STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_EVENTDATACOMMITNUMBEROFPCCONFIG                                                     STD_ON
#define DEM_CFG_EVENTENTRYINDEXTONVBLOCKINDEXOFPCCONFIG                                             STD_ON
#define DEM_CFG_EVENTENTRYINFOTABLEOFPCCONFIG                                                       STD_ON
#define DEM_CFG_EVENTINDICATORDATAOFPCCONFIG                                                        STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_EVENTINTERNALSTATUSOFPCCONFIG                                                       STD_ON
#define DEM_CFG_EVENTINVARIANTDATATABLEOFPCCONFIG                                                   STD_ON
#define DEM_CFG_EVENTPRECOMPILEDATATABLEINDOFPCCONFIG                                               STD_ON
#define DEM_CFG_EVENTPRECOMPILEDATATABLEOFPCCONFIG                                                  STD_ON
#define DEM_CFG_EVENTSTATUSCHANGEDOFPCCONFIG                                                        STD_ON
#define DEM_CFG_EVENTTABLEOFPCCONFIG                                                                STD_ON
#define DEM_CFG_EVENTTABLE_EREC2EVENTIDINDOFPCCONFIG                                                STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_EXTENDEDDATARECORDITERATORTABLEOFPCCONFIG                                           STD_ON
#define DEM_CFG_EXTENDEDDATARECORDTABLEOFPCCONFIG                                                   STD_ON
#define DEM_CFG_EXTENDEDDATATABLEOFPCCONFIG                                                         STD_ON
#define DEM_CFG_FILTERINFOTABLEOFPCCONFIG                                                           STD_ON
#define DEM_CFG_FINALMAGICNUMBEROFPCCONFIG                                                          STD_OFF  /**< the module configuration does not support flashing of data. */
#define DEM_CFG_FREEZEFRAMEDATAOFPCCONFIG                                                           STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_FREEZEFRAMEITERATORTABLEOFPCCONFIG                                                  STD_ON
#define DEM_CFG_FREEZEFRAMENUMINDIRECTIONTABLEOFPCCONFIG                                            STD_ON
#define DEM_CFG_FREEZEFRAMENUMTABLEOFPCCONFIG                                                       STD_ON
#define DEM_CFG_FREEZEFRAMETABLEOFPCCONFIG                                                          STD_ON
#define DEM_CFG_GENERALJ1939TABLEOFPCCONFIG                                                         STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_GENERALOBDINPUTOFPCCONFIG                                                           STD_ON
#define DEM_CFG_GLOBALOBDREQUIREMENTSOFPCCONFIG                                                     STD_OFF  /**< ((DEM_CFG_HAS_OBDII_ENABLED == STD_OFF) && (DEM_CFG_SUPPORT_WWHOBD == STD_OFF) && (DEM_CFG_SUPPORT_OBDONUDS == STD_OFF)) */
#define DEM_CFG_GLOBALSEVERITYMASKOFPCCONFIG                                                        STD_ON
#define DEM_CFG_GLOBALSNAPSHOTRECORDOFPCCONFIG                                                      STD_ON
#define DEM_CFG_INDICATORATTRIBUTETABLEOFPCCONFIG                                                   STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_INDICATORDATAOFPCCONFIG                                                             STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_INDICATOREVENTCOUNTERSOFPCCONFIG                                                    STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_INITDATAHASHCODEOFPCCONFIG                                                          STD_OFF  /**< the module configuration does not support flashing of data. */
#define DEM_CFG_INITMONLISTFORFUNCOFPCCONFIG                                                        STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_INITMONITORFOREVENTOFPCCONFIG                                                       STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_INITMONITORSFORFUNCOFPCCONFIG                                                       STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_J1939EVENTIDSWITHRATIOTABLEOFPCCONFIG                                               STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_J1939NODEIDINDOFPCCONFIG                                                            STD_ON
#define DEM_CFG_J1939NODEIDOFPCCONFIG                                                               STD_ON
#define DEM_CFG_J1939NODEINDICATORAVAILABILITYOFPCCONFIG                                            STD_ON
#define DEM_CFG_J1939SPNSINEXPANDEDFREEZEFRAMETABLEOFPCCONFIG                                       STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_MAXNUMBEREVENTENTRYOBDFREEZEFRAMEOFPCCONFIG                                         STD_OFF  /**< ((DEM_CFG_HAS_OBDII_ENABLED == STD_OFF) && (DEM_CFG_SUPPORT_OBDONUDS == STD_OFF)) */
#define DEM_CFG_MEMORYCURRENTCOUNTOFPCCONFIG                                                        STD_ON
#define DEM_CFG_MEMORYINFOTABLEOFPCCONFIG                                                           STD_ON
#define DEM_CFG_MEMORYSTATUSOFPCCONFIG                                                              STD_ON
#define DEM_CFG_MIDTABLEOFPCCONFIG                                                                  STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_MIRRORDATAOFPCCONFIG                                                                STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_MONITORACTIVITYRATIOTABLEOFPCCONFIG                                                 STD_ON
#define DEM_CFG_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLEOFPCCONFIG                                      STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_NODTCCONFIGUREDOFPCCONFIG                                                           STD_ON
#define DEM_CFG_NVBLOCKDATAPTROFPCCONFIG                                                            STD_ON
#define DEM_CFG_NVBLOCKDATASIZEOFPCCONFIG                                                           STD_ON
#define DEM_CFG_NVBLOCKIDOFPCCONFIG                                                                 STD_ON
#define DEM_CFG_OBDCALIBTABLEOFPCCONFIG                                                             STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_OBDIUMPRDATAOFPCCONFIG                                                              STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_OBDIUMPRUPDATEPENDINGOFPCCONFIG                                                     STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_PIDF501READINESSSUPPORTEDANDCOMPLETEDENFORCEMENTMASKOFPCCONFIG                      STD_ON
#define DEM_CFG_PIDF501READINESSUNSUPPORTEDENFORCEMENTMASKOFPCCONFIG                                STD_ON
#define DEM_CFG_PENDINGEVALUATEDFORCONFIRMEDANDACTIVECONDITIONINVARIANTOFPCCONFIG                   STD_OFF  /**< DEM_CFG_SUPPORT_WWHOBD==STD_OFF */
#define DEM_CFG_PERMANENTDATAOFPCCONFIG                                                             STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_PIDTABLEOFPCCONFIG                                                                  STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_PRESTORAGEINDEXOFPCCONFIG                                                           STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_PRESTORAGEOFPCCONFIG                                                                STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_PRIMARYCHRONOLOGYOFPCCONFIG                                                         STD_ON
#define DEM_CFG_PRIMARYENTRY_0OFPCCONFIG                                                            STD_ON
#define DEM_CFG_PRIMARYENTRY_1OFPCCONFIG                                                            STD_ON
#define DEM_CFG_PRIMARYENTRY_2OFPCCONFIG                                                            STD_ON
#define DEM_CFG_PRIMARYENTRY_3OFPCCONFIG                                                            STD_ON
#define DEM_CFG_PRIMARYENTRY_4OFPCCONFIG                                                            STD_ON
#define DEM_CFG_PRIMARYENTRY_5OFPCCONFIG                                                            STD_ON
#define DEM_CFG_PRIMARYENTRY_6OFPCCONFIG                                                            STD_ON
#define DEM_CFG_PRIMARYENTRY_7OFPCCONFIG                                                            STD_ON
#define DEM_CFG_PRIMARYENTRY_8OFPCCONFIG                                                            STD_ON
#define DEM_CFG_PRIMARYENTRY_9OFPCCONFIG                                                            STD_ON
#define DEM_CFG_PRIMARYEVENTENTRYINITOFPCCONFIG                                                     STD_ON
#define DEM_CFG_RATIOIDTABLEOFPCCONFIG                                                              STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_READOUTBUFFEROFPCCONFIG                                                             STD_ON
#define DEM_CFG_REPORTEDEVENTSOFFILTEROFPCCONFIG                                                    STD_ON
#define DEM_CFG_RINGBUFFEROFPCCONFIG                                                                STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_SAMPLINGPROFILEDIDINFOTABLEOFPCCONFIG                                               STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_SATELLITEINFOINVALID_OSAPPLICATIONOFPCCONFIG                                        STD_ON
#define DEM_CFG_SATELLITEINFOOFPCCONFIG                                                             STD_ON
#define DEM_CFG_SATELLITETIMEDEBOUNCEINFOOFPCCONFIG                                                 STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_SIZEOFCALIBRATIONOBDDTCTABLEOFPCCONFIG                                              STD_ON
#define DEM_CFG_SIZEOFCALLBACKCLEAREVENTALLOWEDOFPCCONFIG                                           STD_ON
#define DEM_CFG_SIZEOFCALLBACKDTCSTATUSCHANGEDOFPCCONFIG                                            STD_ON
#define DEM_CFG_SIZEOFCALLBACKGETFDCOFPCCONFIG                                                      STD_ON
#define DEM_CFG_SIZEOFCALLBACKJ1939DTCSTATUSCHANGEDOFPCCONFIG                                       STD_ON
#define DEM_CFG_SIZEOFCLEARDTCTABLEOFPCCONFIG                                                       STD_ON
#define DEM_CFG_SIZEOFCLEARDTCNOTIFICATIONFINISHTABLEOFPCCONFIG                                     STD_ON
#define DEM_CFG_SIZEOFCLEARDTCNOTIFICATIONSTARTTABLEOFPCCONFIG                                      STD_ON
#define DEM_CFG_SIZEOFCLIENTTABLEOFPCCONFIG                                                         STD_ON
#define DEM_CFG_SIZEOFCOUNTERBASEDDEBOUNCETABLEOFPCCONFIG                                           STD_ON
#define DEM_CFG_SIZEOFCUSTOMTIMESERIESFREEZEFRAMETABLEOFPCCONFIG                                    STD_ON
#define DEM_CFG_SIZEOFCUSTOMTRIGGERENTRYINDEXTONVBLOCKINDEXOFPCCONFIG                               STD_ON
#define DEM_CFG_SIZEOFCUSTOMTRIGGERENTRYPTROFPCCONFIG                                               STD_ON
#define DEM_CFG_SIZEOFDTCSELECTORTABLEOFPCCONFIG                                                    STD_ON
#define DEM_CFG_SIZEOFDATACOLLECTIONTABLEOFPCCONFIG                                                 STD_ON
#define DEM_CFG_SIZEOFDATAELEMENTTABLEOFPCCONFIG                                                    STD_ON
#define DEM_CFG_SIZEOFDTCGROUPMASKOFPCCONFIG                                                        STD_ON
#define DEM_CFG_SIZEOFDTCTABLEOFPCCONFIG                                                            STD_ON
#define DEM_CFG_SIZEOFDTRSTATUSOFPCCONFIG                                                           STD_ON
#define DEM_CFG_SIZEOFDTRTABLEOFPCCONFIG                                                            STD_ON
#define DEM_CFG_SIZEOFENABLECONDITIONFULFILLEDOFPCCONFIG                                            STD_ON
#define DEM_CFG_SIZEOFENABLECONDITIONGROUPCOUNTEROFPCCONFIG                                         STD_ON
#define DEM_CFG_SIZEOFENABLECONDITIONGROUPSTATEOFPCCONFIG                                           STD_ON
#define DEM_CFG_SIZEOFENABLECONDITIONGROUPTABLEOFPCCONFIG                                           STD_ON
#define DEM_CFG_SIZEOFENABLECONDITIONTABLEOFPCCONFIG                                                STD_ON
#define DEM_CFG_SIZEOFEVENTCYCLESTATUSOFPCCONFIG                                                    STD_ON
#define DEM_CFG_SIZEOFEVENTDATACHANGEDOFPCCONFIG                                                    STD_ON
#define DEM_CFG_SIZEOFEVENTDATACOMMITNUMBEROFPCCONFIG                                               STD_ON
#define DEM_CFG_SIZEOFEVENTENTRYINDEXTONVBLOCKINDEXOFPCCONFIG                                       STD_ON
#define DEM_CFG_SIZEOFEVENTENTRYINFOTABLEOFPCCONFIG                                                 STD_ON
#define DEM_CFG_SIZEOFEVENTINDICATORDATAOFPCCONFIG                                                  STD_ON
#define DEM_CFG_SIZEOFEVENTINTERNALSTATUSOFPCCONFIG                                                 STD_ON
#define DEM_CFG_SIZEOFEVENTSTATUSCHANGEDOFPCCONFIG                                                  STD_ON
#define DEM_CFG_SIZEOFEVENTTABLEOFPCCONFIG                                                          STD_ON
#define DEM_CFG_SIZEOFEXTENDEDDATARECORDITERATORTABLEOFPCCONFIG                                     STD_ON
#define DEM_CFG_SIZEOFFILTERINFOTABLEOFPCCONFIG                                                     STD_ON
#define DEM_CFG_SIZEOFFREEZEFRAMEITERATORTABLEOFPCCONFIG                                            STD_ON
#define DEM_CFG_SIZEOFFREEZEFRAMETABLEOFPCCONFIG                                                    STD_ON
#define DEM_CFG_SIZEOFGLOBALSNAPSHOTRECORDOFPCCONFIG                                                STD_ON
#define DEM_CFG_SIZEOFINDICATORATTRIBUTETABLEOFPCCONFIG                                             STD_ON
#define DEM_CFG_SIZEOFINDICATOREVENTCOUNTERSOFPCCONFIG                                              STD_ON
#define DEM_CFG_SIZEOFINITMONITORFOREVENTOFPCCONFIG                                                 STD_ON
#define DEM_CFG_SIZEOFINITMONITORSFORFUNCOFPCCONFIG                                                 STD_ON
#define DEM_CFG_SIZEOFJ1939SPNSINEXPANDEDFREEZEFRAMETABLEOFPCCONFIG                                 STD_ON
#define DEM_CFG_SIZEOFMEMORYCURRENTCOUNTOFPCCONFIG                                                  STD_ON
#define DEM_CFG_SIZEOFMEMORYINFOTABLEOFPCCONFIG                                                     STD_ON
#define DEM_CFG_SIZEOFMEMORYSTATUSOFPCCONFIG                                                        STD_ON
#define DEM_CFG_SIZEOFMONITORACTIVITYRATIOTABLEOFPCCONFIG                                           STD_ON
#define DEM_CFG_SIZEOFOBDIUMPRUPDATEPENDINGOFPCCONFIG                                               STD_ON
#define DEM_CFG_SIZEOFPRESTORAGEINDEXOFPCCONFIG                                                     STD_ON
#define DEM_CFG_SIZEOFPRIMARYCHRONOLOGYOFPCCONFIG                                                   STD_ON
#define DEM_CFG_SIZEOFRATIOIDTABLEOFPCCONFIG                                                        STD_ON
#define DEM_CFG_SIZEOFREADOUTBUFFEROFPCCONFIG                                                       STD_ON
#define DEM_CFG_SIZEOFREPORTEDEVENTSOFFILTEROFPCCONFIG                                              STD_ON
#define DEM_CFG_SIZEOFSATELLITEINFOOFPCCONFIG                                                       STD_ON
#define DEM_CFG_SIZEOFSPNTOEVENTSWITHRATIOTABLEOFPCCONFIG                                           STD_ON
#define DEM_CFG_SIZEOFSTARTIDX500MIDENRATIOTABLEOFPCCONFIG                                          STD_ON
#define DEM_CFG_SIZEOFSTORAGECONDITIONFULFILLEDOFPCCONFIG                                           STD_ON
#define DEM_CFG_SIZEOFSTORAGECONDITIONGROUPCOUNTEROFPCCONFIG                                        STD_ON
#define DEM_CFG_SIZEOFSTORAGECONDITIONGROUPTABLEOFPCCONFIG                                          STD_ON
#define DEM_CFG_SIZEOFSTORAGECONDITIONTABLEOFPCCONFIG                                               STD_ON
#define DEM_CFG_SIZEOFSUPPORTEDMIDSTABLEOFPCCONFIG                                                  STD_ON
#define DEM_CFG_SIZEOFTIMEBASEDDEBOUNCETABLEOFPCCONFIG                                              STD_ON
#define DEM_CFG_SIZEOFTIMEBASEDEVENTTABLEOFPCCONFIG                                                 STD_ON
#define DEM_CFG_SIZEOFTIMESERIESENTRYINDEXTONVBLOCKINDEXOFPCCONFIG                                  STD_ON
#define DEM_CFG_SIZEOFTIMESERIESENTRYTABLEOFPCCONFIG                                                STD_ON
#define DEM_CFG_SIZEOFTIMESERIESSAMPLINGPROFILETABLEOFPCCONFIG                                      STD_ON
#define DEM_CFG_SPNTOEVENTSWITHRATIOTABLEOFPCCONFIG                                                 STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_STARTIDX500MIDENRATIOTABLEOFPCCONFIG                                                STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_STARTIDXOFDEMDIDCLASSINDATACOLLECTIONTABLEOFPCCONFIG                                STD_ON
#define DEM_CFG_STATUSDATAOFPCCONFIG                                                                STD_ON
#define DEM_CFG_STORAGECONDITIONFULFILLEDOFPCCONFIG                                                 STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_STORAGECONDITIONGROUPCOUNTEROFPCCONFIG                                              STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_STORAGECONDITIONGROUPTABLEINDOFPCCONFIG                                             STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_STORAGECONDITIONGROUPTABLEOFPCCONFIG                                                STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_STORAGECONDITIONINITTABLEOFPCCONFIG                                                 STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_STORAGECONDITIONTABLEOFPCCONFIG                                                     STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_SUPPORTEDMIDSTABLEOFPCCONFIG                                                        STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_TIMEBASEDDEBOUNCETABLEOFPCCONFIG                                                    STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_TIMEBASEDEVENTTABLEOFPCCONFIG                                                       STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_TIMESERIESENTRYINDEXTONVBLOCKINDEXOFPCCONFIG                                        STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_TIMESERIESENTRYTABLEOFPCCONFIG                                                      STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_TIMESERIESFREEZEFRAMETABLEOFPCCONFIG                                                STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_TIMESERIESINDIRECTIONTABLEOFPCCONFIG                                                STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_TIMESERIESSAMPLINGPROFILECALIBTABLEOFPCCONFIG                                       STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_TIMESERIESSAMPLINGPROFILETABLEOFPCCONFIG                                            STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define DEM_CFG_USEOBDIIOROBDONUDSINVARIANTOFPCCONFIG                                               STD_ON
#define DEM_CFG_USEOBDONUDSINVARIANTOFPCCONFIG                                                      STD_ON
#define DEM_CFG_USEPERMANENTINVARIANTOFPCCONFIG                                                     STD_OFF  /**< DEM_CFG_SUPPORT_PERMANENT==STD_OFF */
#define DEM_CFG_USEREADINESSSUPPORTANDCOMPLETENESSENFORCEMENTMASKINVARIANTOFPCCONFIG                STD_ON
#define DEM_CFG_USEREADINESSUNSUPPORTEDENFORCEMENTBITMASKINVARIANTOFPCCONFIG                        STD_ON
#define DEM_CFG_USEWWHOBDINVARIANTOFPCCONFIG                                                        STD_ON
#define DEM_CFG_USEZEVONUDSINVARIANTOFPCCONFIG                                                      STD_ON
#define DEM_CFG_USERDEFINEDORIGINTABLEOFPCCONFIG                                                    STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCMinNumericValueDefines  Dem_Cfg Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define DEM_CFG_MIN_CALIBRATIONERRORREGISTER                                                        0u
#define DEM_CFG_MIN_ENABLECONDITIONGROUPCOUNTER                                                     0u
#define DEM_CFG_MIN_ENABLECONDITIONGROUPSTATE                                                       0u
#define DEM_CFG_MIN_EVENTCYCLESTATUS                                                                0u
#define DEM_CFG_MIN_EVENTDATACOMMITNUMBER                                                           0u
#define DEM_CFG_MIN_INDICATOREVENTCOUNTERS                                                          0u
#define DEM_CFG_MIN_MEMORYCURRENTCOUNT                                                              0u
#define DEM_CFG_MIN_MEMORYSTATUS                                                                    0u
#define DEM_CFG_MIN_MIRRORDATA                                                                      0u
#define DEM_CFG_MIN_STORAGECONDITIONGROUPCOUNTER                                                    0u
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCMaxNumericValueDefines  Dem_Cfg Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define DEM_CFG_MAX_CALIBRATIONERRORREGISTER                                                        255u
#define DEM_CFG_MAX_ENABLECONDITIONGROUPCOUNTER                                                     255u
#define DEM_CFG_MAX_ENABLECONDITIONGROUPSTATE                                                       255u
#define DEM_CFG_MAX_EVENTCYCLESTATUS                                                                255u
#define DEM_CFG_MAX_EVENTDATACOMMITNUMBER                                                           255u
#define DEM_CFG_MAX_INDICATOREVENTCOUNTERS                                                          65535u
#define DEM_CFG_MAX_MEMORYCURRENTCOUNT                                                              255u
#define DEM_CFG_MAX_MEMORYSTATUS                                                                    255u
#define DEM_CFG_MAX_MIRRORDATA                                                                      255u
#define DEM_CFG_MAX_STORAGECONDITIONGROUPCOUNTER                                                    255u
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCNoReferenceDefines  Dem_Cfg No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define DEM_CFG_NO_DATAELEMENTTABLECOL2ELMTINDDATAELEMENTTABLECOL2ELMTINDENDIDXOFDATACOLLECTIONTABLE 255u
#define DEM_CFG_NO_DATAELEMENTTABLECOL2ELMTINDDATAELEMENTTABLECOL2ELMTINDSTARTIDXOFDATACOLLECTIONTABLE 255u
#define DEM_CFG_NO_EVENTTABLE_EREC2EVENTIDINDENDIDXOFDATACOLLECTIONTABLE                            255u
#define DEM_CFG_NO_EVENTTABLE_EREC2EVENTIDINDSTARTIDXOFDATACOLLECTIONTABLE                          255u
#define DEM_CFG_NO_COUNTERBASEDDEBOUNCETABLEIDXOFDEBOUNCEINDIRECTIONTABLE                           255u
#define DEM_CFG_NO_TIMEBASEDDEBOUNCETABLEIDXOFDEBOUNCEINDIRECTIONTABLE                              255u
#define DEM_CFG_NO_CUSTOMTIMESERIESFREEZEFRAMETABLEIDXOFDTCTABLE                                    255u
#define DEM_CFG_NO_FREEZEFRAMENUMINDIRECTIONTABLEIDXOFDTCTABLE                                      255u
#define DEM_CFG_NO_J1939NODEIDINDENDIDXOFDTCTABLE                                                   255u
#define DEM_CFG_NO_J1939NODEIDINDSTARTIDXOFDTCTABLE                                                 255u
#define DEM_CFG_NO_TIMESERIESINDIRECTIONTABLEENDIDXOFDTCTABLE                                       255u
#define DEM_CFG_NO_TIMESERIESINDIRECTIONTABLESTARTIDXOFDTCTABLE                                     255u
#define DEM_CFG_NO_ENABLECONDITIONGROUPTABLEINDENDIDXOFENABLECONDITIONTABLE                         255u
#define DEM_CFG_NO_ENABLECONDITIONGROUPTABLEINDSTARTIDXOFENABLECONDITIONTABLE                       255u
#define DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE                               255u
#define DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE                             255u
#define DEM_CFG_NO_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLEENDIDXOFEVENTPRECOMPILEDATATABLE             255u
#define DEM_CFG_NO_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLESTARTIDXOFEVENTPRECOMPILEDATATABLE           255u
#define DEM_CFG_NO_DTRTABLEINDENDIDXOFEVENTTABLE                                                    255u
#define DEM_CFG_NO_DTRTABLEINDSTARTIDXOFEVENTTABLE                                                  255u
#define DEM_CFG_NO_ENABLECONDITIONGROUPTABLEIDXOFEVENTTABLE                                         255u
#define DEM_CFG_NO_EVENTINDICATORDATAIDXOFEVENTTABLE                                                255u
#define DEM_CFG_NO_DATACOLLECTIONTABLEEREC2COLLINDENDIDXOFEXTENDEDDATARECORDTABLE                   255u
#define DEM_CFG_NO_DATACOLLECTIONTABLEEREC2COLLINDSTARTIDXOFEXTENDEDDATARECORDTABLE                 255u
#define DEM_CFG_NO_DATACOLLECTIONTABLEEDR2COLLINDDATACOLLECTIONTABLEEDR2COLLINDENDIDXOFEXTENDEDDATATABLE 255u
#define DEM_CFG_NO_DATACOLLECTIONTABLEEDR2COLLINDDATACOLLECTIONTABLEEDR2COLLINDSTARTIDXOFEXTENDEDDATATABLE 255u
#define DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFFREEZEFRAMENUMINDIRECTIONTABLE                        255u
#define DEM_CFG_NO_FREEZEFRAMENUMTABLESECONDENDIDXOFFREEZEFRAMENUMINDIRECTIONTABLE                  255u
#define DEM_CFG_NO_FREEZEFRAMENUMTABLESECONDSTARTIDXOFFREEZEFRAMENUMINDIRECTIONTABLE                255u
#define DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFFREEZEFRAMENUMINDIRECTIONTABLE                      255u
#define DEM_CFG_NO_DATACOLLECTIONTABLEFFM2COLLINDDATACOLLECTIONTABLEFFM2COLLINDENDIDXOFFREEZEFRAMETABLE 255u
#define DEM_CFG_NO_DATACOLLECTIONTABLEFFM2COLLINDDATACOLLECTIONTABLEFFM2COLLINDSTARTIDXOFFREEZEFRAMETABLE 255u
#define DEM_CFG_NO_ENABLECONDITIONGROUPTABLECONTROLDTCSETTINGGROUPIDXOFMEMORYINFOTABLE              255u
#define DEM_CFG_NO_CALIBRATIONOBDDTCTABLEIDXOFOBDCALIBTABLE                                         255u
#define DEM_CFG_NO_DATACOLLECTIONTABLEPID2COLLINDENDIDXOFPIDTABLE                                   255u
#define DEM_CFG_NO_DATACOLLECTIONTABLEPID2COLLINDSTARTIDXOFPIDTABLE                                 255u
#define DEM_CFG_NO_EVENTPRECOMPILEDATATABLEINDENDIDXOFSATELLITEINFO                                 255u
#define DEM_CFG_NO_EVENTPRECOMPILEDATATABLEINDSTARTIDXOFSATELLITEINFO                               255u
#define DEM_CFG_NO_TIMEBASEDEVENTTABLEENDIDXOFSATELLITETIMEDEBOUNCEINFO                             255u
#define DEM_CFG_NO_TIMEBASEDEVENTTABLESTARTIDXOFSATELLITETIMEDEBOUNCEINFO                           255u
#define DEM_CFG_NO_STORAGECONDITIONGROUPTABLEINDENDIDXOFSTORAGECONDITIONTABLE                       255u
#define DEM_CFG_NO_STORAGECONDITIONGROUPTABLEINDSTARTIDXOFSTORAGECONDITIONTABLE                     255u
#define DEM_CFG_NO_SAMPLINGPROFILEDIDINFOTABLEENDIDXOFTIMESERIESSAMPLINGPROFILECALIBTABLE           255u
#define DEM_CFG_NO_SAMPLINGPROFILEDIDINFOTABLESTARTIDXOFTIMESERIESSAMPLINGPROFILECALIBTABLE         255u
#define DEM_CFG_NO_MEMORYINFOTABLEIDXOFUSERDEFINEDORIGINTABLE                                       255u
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCEnumExistsDefines  Dem_Cfg Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define DEM_CFG_EXISTS_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFDTCTABLE                STD_OFF
#define DEM_CFG_EXISTS_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFDTCTABLE                     STD_ON
#define DEM_CFG_EXISTS_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTPRECOMPILEDATATABLE                       STD_OFF
#define DEM_CFG_EXISTS_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTPRECOMPILEDATATABLE                       STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCEnumDefines  Dem_Cfg Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFDTCTABLE                       0x00u
#define DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFDTCTABLE                            0x01u
#define DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTPRECOMPILEDATATABLE                              0x00u
#define DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTPRECOMPILEDATATABLE                              0x01u
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCMaskedBitDefines  Dem_Cfg Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define DEM_CFG_DEBOUNCECONTINUOUSOFCOUNTERBASEDDEBOUNCETABLE_MASK                                  0x08u
#define DEM_CFG_EVENTDEBOUNCEBEHAVIOROFCOUNTERBASEDDEBOUNCETABLE_MASK                               0x04u
#define DEM_CFG_JUMPDOWNOFCOUNTERBASEDDEBOUNCETABLE_MASK                                            0x02u
#define DEM_CFG_JUMPUPOFCOUNTERBASEDDEBOUNCETABLE_MASK                                              0x01u
#define DEM_CFG_DEBOUNCECOUNTERSTORAGEOFEVENTPRECOMPILEDATATABLE_MASK                               0x02u
#define DEM_CFG_EVENTLATCHTFOFEVENTPRECOMPILEDATATABLE_MASK                                         0x01u
#define DEM_CFG_FFUPDATEOFFREEZEFRAMENUMTABLE_MASK                                                  0x02u
#define DEM_CFG_ISGLOBALOFFREEZEFRAMENUMTABLE_MASK                                                  0x01u
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCIsReducedToDefineDefines  Dem_Cfg Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define DEM_CFG_ISDEF_AGINGALLOWEDOFCALIBRATIONOBDDTCTABLE                                          STD_OFF
#define DEM_CFG_ISDEF_AGINGCYCLECOUNTERTHRESHOLDOFCALIBRATIONOBDDTCTABLE                            STD_OFF
#define DEM_CFG_ISDEF_AGINGCYCLEIDOFCALIBRATIONOBDDTCTABLE                                          STD_OFF
#define DEM_CFG_ISDEF_IMMEDIATENVSTORAGEOFCALIBRATIONOBDDTCTABLE                                    STD_OFF
#define DEM_CFG_ISDEF_OPERATIONCYCLEIDOFCALIBRATIONOBDDTCTABLE                                      STD_OFF
#define DEM_CFG_ISDEF_READINESSGROUPOFCALIBRATIONOBDDTCTABLE                                        STD_OFF
#define DEM_CFG_ISDEF_USEEXTENDEDDATARECORD0X93OFCALIBRATIONOBDDTCTABLE                             STD_OFF
#define DEM_CFG_ISDEF_CALLBACKCLEAREVENTALLOWED                                                     STD_OFF
#define DEM_CFG_ISDEF_CALLBACKDTCSTATUSCHANGED                                                      STD_OFF
#define DEM_CFG_ISDEF_CALLBACKGETFDC                                                                STD_OFF
#define DEM_CFG_ISDEF_CALLBACKJ1939DTCSTATUSCHANGED                                                 STD_OFF
#define DEM_CFG_ISDEF_CLEARDTCNOTIFICATIONFINISHTABLE                                               STD_OFF
#define DEM_CFG_ISDEF_CLEARDTCNOTIFICATIONSTARTTABLE                                                STD_OFF
#define DEM_CFG_ISDEF_CLEARDTCINDEXOFCLIENTTABLE                                                    STD_ON
#define DEM_CFG_ISDEF_FILTERINDEXOFCLIENTTABLE                                                      STD_ON
#define DEM_CFG_ISDEF_FREEZEFRAMEITERATORINDEXOFCLIENTTABLE                                         STD_ON
#define DEM_CFG_ISDEF_NMNODEIDOFCLIENTTABLE                                                         STD_ON
#define DEM_CFG_ISDEF_READOUTBUFFERINDEXOFCLIENTTABLE                                               STD_ON
#define DEM_CFG_ISDEF_SELECTORINDEXOFCLIENTTABLE                                                    STD_ON
#define DEM_CFG_ISDEF_FREEZEFRAMETABLEIDXOFCOMMONDIDLIST                                            STD_ON
#define DEM_CFG_ISDEF_DEBOUNCECONTINUOUSOFCOUNTERBASEDDEBOUNCETABLE                                 STD_ON
#define DEM_CFG_ISDEF_DECREMENTSTEPSIZEOFCOUNTERBASEDDEBOUNCETABLE                                  STD_ON
#define DEM_CFG_ISDEF_EVENTDEBOUNCEBEHAVIOROFCOUNTERBASEDDEBOUNCETABLE                              STD_ON
#define DEM_CFG_ISDEF_FAILEDTHRESHOLDOFCOUNTERBASEDDEBOUNCETABLE                                    STD_ON
#define DEM_CFG_ISDEF_INCREMENTSTEPSIZEOFCOUNTERBASEDDEBOUNCETABLE                                  STD_ON
#define DEM_CFG_ISDEF_JUMPDOWNOFCOUNTERBASEDDEBOUNCETABLE                                           STD_ON
#define DEM_CFG_ISDEF_JUMPDOWNVALUEOFCOUNTERBASEDDEBOUNCETABLE                                      STD_ON
#define DEM_CFG_ISDEF_JUMPUPOFCOUNTERBASEDDEBOUNCETABLE                                             STD_ON
#define DEM_CFG_ISDEF_JUMPUPVALUEOFCOUNTERBASEDDEBOUNCETABLE                                        STD_ON
#define DEM_CFG_ISDEF_MASKEDBITSOFCOUNTERBASEDDEBOUNCETABLE                                         STD_ON
#define DEM_CFG_ISDEF_PASSEDTHRESHOLDOFCOUNTERBASEDDEBOUNCETABLE                                    STD_ON
#define DEM_CFG_ISDEF_STORAGETHRESHOLDOFCOUNTERBASEDDEBOUNCETABLE                                   STD_OFF
#define DEM_CFG_ISDEF_FIRSTRECORDNUMBEROFCUSTOMTIMESERIESFREEZEFRAMETABLE                           STD_OFF
#define DEM_CFG_ISDEF_LASTRECORDNUMBEROFCUSTOMTIMESERIESFREEZEFRAMETABLE                            STD_OFF
#define DEM_CFG_ISDEF_TIMESERIESSAMPLINGPROFILETABLEIDXOFCUSTOMTIMESERIESFREEZEFRAMETABLE           STD_OFF
#define DEM_CFG_ISDEF_UPDATERECORDOFCUSTOMTIMESERIESFREEZEFRAMETABLE                                STD_OFF
#define DEM_CFG_ISDEF_CUSTOMTRIGGERENTRYINDEXTONVBLOCKINDEX                                         STD_OFF
#define DEM_CFG_ISDEF_CUSTOMTRIGGERENTRYPTR                                                         STD_OFF
#define DEM_CFG_ISDEF_ENDSONINITOFCYCLEIDTABLE                                                      STD_OFF
#define DEM_CFG_ISDEF_OPCYCLETYPEOFCYCLEIDTABLE                                                     STD_ON
#define DEM_CFG_ISDEF_COLLECTIONSIZEOFDATACOLLECTIONTABLE                                           STD_OFF
#define DEM_CFG_ISDEF_DATAELEMENTTABLECOL2ELMTINDDATAELEMENTTABLECOL2ELMTINDENDIDXOFDATACOLLECTIONTABLE STD_OFF
#define DEM_CFG_ISDEF_DATAELEMENTTABLECOL2ELMTINDDATAELEMENTTABLECOL2ELMTINDSTARTIDXOFDATACOLLECTIONTABLE STD_OFF
#define DEM_CFG_ISDEF_DATAELEMENTTABLECOL2ELMTINDDATAELEMENTTABLECOL2ELMTINDUSEDOFDATACOLLECTIONTABLE STD_OFF
#define DEM_CFG_ISDEF_EVENTTABLE_EREC2EVENTIDINDENDIDXOFDATACOLLECTIONTABLE                         STD_OFF
#define DEM_CFG_ISDEF_EVENTTABLE_EREC2EVENTIDINDSTARTIDXOFDATACOLLECTIONTABLE                       STD_OFF
#define DEM_CFG_ISDEF_EVENTTABLE_EREC2EVENTIDINDUSEDOFDATACOLLECTIONTABLE                           STD_OFF
#define DEM_CFG_ISDEF_IDNUMBEROFDATACOLLECTIONTABLE                                                 STD_OFF
#define DEM_CFG_ISDEF_STORAGEKINDOFDATACOLLECTIONTABLE                                              STD_OFF
#define DEM_CFG_ISDEF_TRIGGEROFDATACOLLECTIONTABLE                                                  STD_ON
#define DEM_CFG_ISDEF_UPDATEOFDATACOLLECTIONTABLE                                                   STD_OFF
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEEREC2COLLIND                                               STD_OFF
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEIDXOFDATACOLLECTIONTABLEEDR2COLLIND                        STD_OFF
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEIDXOFDATACOLLECTIONTABLEFFM2COLLIND                        STD_OFF
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEPID2COLLIND                                                STD_OFF
#define DEM_CFG_ISDEF_DATAISSTOREDINNVOFDATAELEMENTTABLE                                            STD_OFF
#define DEM_CFG_ISDEF_ELEMENTDATATYPEOFDATAELEMENTTABLE                                             STD_OFF
#define DEM_CFG_ISDEF_ELEMENTKINDOFDATAELEMENTTABLE                                                 STD_OFF
#define DEM_CFG_ISDEF_ELEMENTSIZEOFDATAELEMENTTABLE                                                 STD_OFF
#define DEM_CFG_ISDEF_READDATAFUNCOFDATAELEMENTTABLE                                                STD_OFF
#define DEM_CFG_ISDEF_DATAELEMENTTABLEIDXOFDATAELEMENTTABLECOL2ELMTIND                              STD_OFF
#define DEM_CFG_ISDEF_COUNTERBASEDDEBOUNCETABLEIDXOFDEBOUNCEINDIRECTIONTABLE                        STD_OFF
#define DEM_CFG_ISDEF_COUNTERBASEDDEBOUNCETABLEUSEDOFDEBOUNCEINDIRECTIONTABLE                       STD_OFF
#define DEM_CFG_ISDEF_TIMEBASEDDEBOUNCETABLEIDXOFDEBOUNCEINDIRECTIONTABLE                           STD_OFF
#define DEM_CFG_ISDEF_TIMEBASEDDEBOUNCETABLEUSEDOFDEBOUNCEINDIRECTIONTABLE                          STD_OFF
#define DEM_CFG_ISDEF_AGINGCYCLECOUNTERTHRESHOLDOFDTCCALIBTABLE                                     STD_OFF
#define DEM_CFG_ISDEF_AGINGCYCLEIDOFDTCCALIBTABLE                                                   STD_OFF
#define DEM_CFG_ISDEF_DTCPRIORITYOFDTCCALIBTABLE                                                    STD_OFF
#define DEM_CFG_ISDEF_DTCSEVERITYOFDTCCALIBTABLE                                                    STD_ON
#define DEM_CFG_ISDEF_UDSDTCOFDTCCALIBTABLE                                                         STD_OFF
#define DEM_CFG_ISDEF_GROUPMASKOFDTCGROUPMASK                                                       STD_OFF
#define DEM_CFG_ISDEF_UDSGROUPDTCOFDTCGROUPMASK                                                     STD_OFF
#define DEM_CFG_ISDEF_AGINGALLOWEDOFDTCINVARIANTDATATABLE                                           STD_OFF
#define DEM_CFG_ISDEF_FREEZEFRAMETABLESECONDSTDFFIDXOFDTCINVARIANTDATATABLE                         STD_ON
#define DEM_CFG_ISDEF_FREEZEFRAMETABLESTDFFIDXOFDTCINVARIANTDATATABLE                               STD_OFF
#define DEM_CFG_ISDEF_FUNCTIONALUNITOFDTCINVARIANTDATATABLE                                         STD_OFF
#define DEM_CFG_ISDEF_CUSTOMTIMESERIESFREEZEFRAMETABLEIDXOFDTCTABLE                                 STD_OFF
#define DEM_CFG_ISDEF_CUSTOMTIMESERIESFREEZEFRAMETABLEUSEDOFDTCTABLE                                STD_OFF
#define DEM_CFG_ISDEF_CUSTOMTRIGGEREDSNAPSHOTCONFIGUREDOFDTCTABLE                                   STD_OFF
#define DEM_CFG_ISDEF_CUSTOMTRIGGEREDTIMESERIESSNAPSHOTCONFIGUREDOFDTCTABLE                         STD_OFF
#define DEM_CFG_ISDEF_DTCOBDRELEVANCEOFDTCTABLE                                                     STD_OFF
#define DEM_CFG_ISDEF_EVENTSIGNIFICANCEOFDTCTABLE                                                   STD_ON
#define DEM_CFG_ISDEF_EXTENDEDDATATABLEIDXOFDTCTABLE                                                STD_OFF
#define DEM_CFG_ISDEF_FREEZEFRAMENUMINDIRECTIONTABLEIDXOFDTCTABLE                                   STD_OFF
#define DEM_CFG_ISDEF_FREEZEFRAMENUMINDIRECTIONTABLEUSEDOFDTCTABLE                                  STD_OFF
#define DEM_CFG_ISDEF_IMMEDIATENVSTORAGEOFDTCTABLE                                                  STD_ON
#define DEM_CFG_ISDEF_J1939DTCOFDTCTABLE                                                            STD_ON
#define DEM_CFG_ISDEF_J1939NODEIDINDENDIDXOFDTCTABLE                                                STD_OFF
#define DEM_CFG_ISDEF_J1939NODEIDINDSTARTIDXOFDTCTABLE                                              STD_OFF
#define DEM_CFG_ISDEF_J1939NODEIDINDUSEDOFDTCTABLE                                                  STD_OFF
#define DEM_CFG_ISDEF_SMARINDEXOFDTCTABLE                                                           STD_OFF
#define DEM_CFG_ISDEF_TIMESERIESINDIRECTIONTABLEENDIDXOFDTCTABLE                                    STD_OFF
#define DEM_CFG_ISDEF_TIMESERIESINDIRECTIONTABLESTARTIDXOFDTCTABLE                                  STD_OFF
#define DEM_CFG_ISDEF_TIMESERIESINDIRECTIONTABLEUSEDOFDTCTABLE                                      STD_OFF
#define DEM_CFG_ISDEF_DIVISOROFDTRTABLE                                                             STD_OFF
#define DEM_CFG_ISDEF_EVENTTABLEIDXOFDTRTABLE                                                       STD_OFF
#define DEM_CFG_ISDEF_LINEARFACTOROFDTRTABLE                                                        STD_OFF
#define DEM_CFG_ISDEF_OFFSETOFDTRTABLE                                                              STD_OFF
#define DEM_CFG_ISDEF_UASIDOFDTRTABLE                                                               STD_OFF
#define DEM_CFG_ISDEF_UPDATEKINDOFDTRTABLE                                                          STD_OFF
#define DEM_CFG_ISDEF_DTRTABLEIND                                                                   STD_OFF
#define DEM_CFG_ISDEF_INDEXOFENABLECONDITIONGROUPTABLE                                              STD_ON
#define DEM_CFG_ISDEF_ENABLECONDITIONGROUPTABLEIND                                                  STD_ON
#define DEM_CFG_ISDEF_FULFILLEDATINITOFENABLECONDITIONINITTABLE                                     STD_ON
#define DEM_CFG_ISDEF_ENABLECONDITIONGROUPTABLEINDENDIDXOFENABLECONDITIONTABLE                      STD_ON
#define DEM_CFG_ISDEF_ENABLECONDITIONGROUPTABLEINDSTARTIDXOFENABLECONDITIONTABLE                    STD_ON
#define DEM_CFG_ISDEF_ENABLECONDITIONGROUPTABLEINDUSEDOFENABLECONDITIONTABLE                        STD_ON
#define DEM_CFG_ISDEF_EVENTAVAILABLEDEFAULT                                                         STD_ON
#define DEM_CFG_ISDEF_EVENTAVAILABLEINVARIANT                                                       STD_OFF
#define DEM_CFG_ISDEF_EVENTFAILURECYCLECOUNTERTHRESHOLDOFEVENTCALIBTABLE                            STD_ON
#define DEM_CFG_ISDEF_OPERATIONCYCLEIDOFEVENTCALIBTABLE                                             STD_ON
#define DEM_CFG_ISDEF_EVENTDATACHANGED                                                              STD_OFF
#define DEM_CFG_ISDEF_EVENTENTRYINDEXTONVBLOCKINDEX                                                 STD_OFF
#define DEM_CFG_ISDEF_BASEENTRYPTROFEVENTENTRYINFOTABLE                                             STD_OFF
#define DEM_CFG_ISDEF_EXTENDEDDATAPTROFEVENTENTRYINFOTABLE                                          STD_OFF
#define DEM_CFG_ISDEF_INITPTROFEVENTENTRYINFOTABLE                                                  STD_OFF
#define DEM_CFG_ISDEF_J1939FREEZEFRAMEDATAPTROFEVENTENTRYINFOTABLE                                  STD_OFF
#define DEM_CFG_ISDEF_OBDFREEZEFRAMEDATAPTROFEVENTENTRYINFOTABLE                                    STD_OFF
#define DEM_CFG_ISDEF_SIZEOFEXTENDEDDATAOFEVENTENTRYINFOTABLE                                       STD_OFF
#define DEM_CFG_ISDEF_SIZEOFJ1939EXPFREEZEFRAMEOFEVENTENTRYINFOTABLE                                STD_OFF
#define DEM_CFG_ISDEF_SIZEOFJ1939FREEZEFRAMEOFEVENTENTRYINFOTABLE                                   STD_OFF
#define DEM_CFG_ISDEF_SIZEOFOBDFREEZEFRAMEOFEVENTENTRYINFOTABLE                                     STD_OFF
#define DEM_CFG_ISDEF_SIZEOFSNAPSHOTDATAOFEVENTENTRYINFOTABLE                                       STD_OFF
#define DEM_CFG_ISDEF_SNAPSHOTDATAPTROFEVENTENTRYINFOTABLE                                          STD_OFF
#define DEM_CFG_ISDEF_ASSIGNEDATTRIBUTEBITFIELDOFEVENTINDICATORDATA                                 STD_OFF
#define DEM_CFG_ISDEF_EVENTHEALINGTARGETOFEVENTINDICATORDATA                                        STD_OFF
#define DEM_CFG_ISDEF_DTCTABLEIDXOFEVENTINVARIANTDATATABLE                                          STD_OFF
#define DEM_CFG_ISDEF_CALLBACKGETFDCIDXOFEVENTPRECOMPILEDATATABLE                                   STD_OFF
#define DEM_CFG_ISDEF_DEBOUNCECOUNTERSTORAGEOFEVENTPRECOMPILEDATATABLE                              STD_ON
#define DEM_CFG_ISDEF_EVENTCONSIDERPTOSTATUSOFEVENTPRECOMPILEDATATABLE                              STD_OFF
#define DEM_CFG_ISDEF_EVENTKINDOFEVENTPRECOMPILEDATATABLE                                           STD_ON
#define DEM_CFG_ISDEF_EVENTLATCHTFOFEVENTPRECOMPILEDATATABLE                                        STD_ON
#define DEM_CFG_ISDEF_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE                            STD_OFF
#define DEM_CFG_ISDEF_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE                          STD_OFF
#define DEM_CFG_ISDEF_EVENTSTATUSCHANGEDUSEDOFEVENTPRECOMPILEDATATABLE                              STD_OFF
#define DEM_CFG_ISDEF_MASKEDBITSOFEVENTPRECOMPILEDATATABLE                                          STD_ON
#define DEM_CFG_ISDEF_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLEENDIDXOFEVENTPRECOMPILEDATATABLE          STD_OFF
#define DEM_CFG_ISDEF_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLESTARTIDXOFEVENTPRECOMPILEDATATABLE        STD_OFF
#define DEM_CFG_ISDEF_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLEUSEDOFEVENTPRECOMPILEDATATABLE            STD_OFF
#define DEM_CFG_ISDEF_MULTIEVENTTRIGGERINGSLAVEOFEVENTPRECOMPILEDATATABLE                           STD_OFF
#define DEM_CFG_ISDEF_SATELLITEEVENTIDXOFEVENTPRECOMPILEDATATABLE                                   STD_OFF
#define DEM_CFG_ISDEF_SATELLITEINFOIDXOFEVENTPRECOMPILEDATATABLE                                    STD_ON
#define DEM_CFG_ISDEF_EVENTPRECOMPILEDATATABLEIND                                                   STD_OFF
#define DEM_CFG_ISDEF_EVENTSTATUSCHANGED                                                            STD_OFF
#define DEM_CFG_ISDEF_DTRTABLEINDENDIDXOFEVENTTABLE                                                 STD_OFF
#define DEM_CFG_ISDEF_DTRTABLEINDSTARTIDXOFEVENTTABLE                                               STD_OFF
#define DEM_CFG_ISDEF_DTRTABLEINDUSEDOFEVENTTABLE                                                   STD_OFF
#define DEM_CFG_ISDEF_ENABLECONDITIONGROUPTABLEIDXOFEVENTTABLE                                      STD_OFF
#define DEM_CFG_ISDEF_ENABLECONDITIONGROUPTABLEUSEDOFEVENTTABLE                                     STD_OFF
#define DEM_CFG_ISDEF_EVENTCALIBTABLEIDXOFEVENTTABLE                                                STD_ON
#define DEM_CFG_ISDEF_EVENTDESTINATIONOFEVENTTABLE                                                  STD_ON
#define DEM_CFG_ISDEF_EVENTINDICATORDATAIDXOFEVENTTABLE                                             STD_OFF
#define DEM_CFG_ISDEF_EVENTINDICATORDATAUSEDOFEVENTTABLE                                            STD_OFF
#define DEM_CFG_ISDEF_EVENTINVARIANTDATATABLEIDXOFEVENTTABLE                                        STD_OFF
#define DEM_CFG_ISDEF_EVENTPTOTIMERINDEXOFEVENTTABLE                                                STD_OFF
#define DEM_CFG_ISDEF_FAILEDCYCLECOUNTERINDEXOFEVENTTABLE                                           STD_OFF
#define DEM_CFG_ISDEF_FAULTPENDINGCOUNTERINDEXOFEVENTTABLE                                          STD_OFF
#define DEM_CFG_ISDEF_MAXFDCSINCELASTCLEARINDEXOFEVENTTABLE                                         STD_OFF
#define DEM_CFG_ISDEF_MONITORACTIVITYRATIOTABLEIDXOFEVENTTABLE                                      STD_OFF
#define DEM_CFG_ISDEF_OBDVISIBILITYDELAYEDUNTILDCYQUALIFICATIONOFEVENTTABLE                         STD_ON
#define DEM_CFG_ISDEF_EVENTTABLE_EREC2EVENTIDIND                                                    STD_OFF
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEEREC2COLLINDENDIDXOFEXTENDEDDATARECORDTABLE                STD_ON
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEEREC2COLLINDSTARTIDXOFEXTENDEDDATARECORDTABLE              STD_ON
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEEREC2COLLINDUSEDOFEXTENDEDDATARECORDTABLE                  STD_ON
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEEDR2COLLINDDATACOLLECTIONTABLEEDR2COLLINDENDIDXOFEXTENDEDDATATABLE STD_OFF
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEEDR2COLLINDDATACOLLECTIONTABLEEDR2COLLINDSTARTIDXOFEXTENDEDDATATABLE STD_OFF
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEEDR2COLLINDDATACOLLECTIONTABLEEDR2COLLINDUSEDOFEXTENDEDDATATABLE STD_OFF
#define DEM_CFG_ISDEF_MAXRECORDSIZEOFEXTENDEDDATATABLE                                              STD_OFF
#define DEM_CFG_ISDEF_FREEZEFRAMENUMTABLEENDIDXOFFREEZEFRAMENUMINDIRECTIONTABLE                     STD_OFF
#define DEM_CFG_ISDEF_FREEZEFRAMENUMTABLESECONDENDIDXOFFREEZEFRAMENUMINDIRECTIONTABLE               STD_OFF
#define DEM_CFG_ISDEF_FREEZEFRAMENUMTABLESECONDSTARTIDXOFFREEZEFRAMENUMINDIRECTIONTABLE             STD_OFF
#define DEM_CFG_ISDEF_FREEZEFRAMENUMTABLESECONDUSEDOFFREEZEFRAMENUMINDIRECTIONTABLE                 STD_OFF
#define DEM_CFG_ISDEF_FREEZEFRAMENUMTABLESTARTIDXOFFREEZEFRAMENUMINDIRECTIONTABLE                   STD_OFF
#define DEM_CFG_ISDEF_FREEZEFRAMENUMTABLEUSEDOFFREEZEFRAMENUMINDIRECTIONTABLE                       STD_OFF
#define DEM_CFG_ISDEF_FFNUMBEROFFREEZEFRAMENUMTABLE                                                 STD_ON
#define DEM_CFG_ISDEF_FFTRIGGEROFFREEZEFRAMENUMTABLE                                                STD_ON
#define DEM_CFG_ISDEF_FFUPDATEOFFREEZEFRAMENUMTABLE                                                 STD_ON
#define DEM_CFG_ISDEF_ISGLOBALOFFREEZEFRAMENUMTABLE                                                 STD_ON
#define DEM_CFG_ISDEF_MASKEDBITSOFFREEZEFRAMENUMTABLE                                               STD_ON
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEFFM2COLLINDDATACOLLECTIONTABLEFFM2COLLINDENDIDXOFFREEZEFRAMETABLE STD_OFF
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEFFM2COLLINDDATACOLLECTIONTABLEFFM2COLLINDSTARTIDXOFFREEZEFRAMETABLE STD_OFF
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEFFM2COLLINDDATACOLLECTIONTABLEFFM2COLLINDUSEDOFFREEZEFRAMETABLE STD_OFF
#define DEM_CFG_ISDEF_RECORDSIZEOFFREEZEFRAMETABLE                                                  STD_OFF
#define DEM_CFG_ISDEF_RECORDSIZEUDSOFFREEZEFRAMETABLE                                               STD_OFF
#define DEM_CFG_ISDEF_RECORDSIZEOFGENERALJ1939TABLE                                                 STD_OFF
#define DEM_CFG_ISDEF_DATAELEMENTTABLEIDXOFGENERALOBDINPUT                                          STD_ON
#define DEM_CFG_ISDEF_FREEZEFRAMETABLEIDXOFGLOBALSNAPSHOTRECORD                                     STD_ON
#define DEM_CFG_ISDEF_BEHAVIOUROFINDICATORATTRIBUTETABLE                                            STD_OFF
#define DEM_CFG_ISDEF_FAILURECYCLECOUNTERTHRESHOLDOFINDICATORATTRIBUTETABLE                         STD_OFF
#define DEM_CFG_ISDEF_IDOFINDICATORATTRIBUTETABLE                                                   STD_OFF
#define DEM_CFG_ISDEF_J1939NODEIDOFINDICATORATTRIBUTETABLE                                          STD_OFF
#define DEM_CFG_ISDEF_INITMONITORFOREVENT                                                           STD_OFF
#define DEM_CFG_ISDEF_INITMONITORSFORFUNC                                                           STD_OFF
#define DEM_CFG_ISDEF_EVENTIDOFJ1939EVENTIDSWITHRATIOTABLE                                          STD_OFF
#define DEM_CFG_ISDEF_J1939NODEID                                                                   STD_OFF
#define DEM_CFG_ISDEF_J1939NODEIDIND                                                                STD_OFF
#define DEM_CFG_ISDEF_J1939NODEINDICATORAVAILABILITY                                                STD_ON
#define DEM_CFG_ISDEF_SPNIDOFJ1939SPNSINEXPANDEDFREEZEFRAMETABLE                                    STD_OFF
#define DEM_CFG_ISDEF_SPNSIZEOFJ1939SPNSINEXPANDEDFREEZEFRAMETABLE                                  STD_OFF
#define DEM_CFG_ISDEF_CHRONOPTROFMEMORYINFOTABLE                                                    STD_ON
#define DEM_CFG_ISDEF_CUSTOMTRIGGERTRANSLATEDMEMORYIDOFMEMORYINFOTABLE                              STD_ON
#define DEM_CFG_ISDEF_ENABLECONDITIONGROUPTABLECONTROLDTCSETTINGGROUPIDXOFMEMORYINFOTABLE           STD_ON
#define DEM_CFG_ISDEF_ENABLECONDITIONGROUPTABLECONTROLDTCSETTINGGROUPUSEDOFMEMORYINFOTABLE          STD_ON
#define DEM_CFG_ISDEF_EVENTMEMORYENTRYSTORAGETRIGGEROFMEMORYINFOTABLE                               STD_ON
#define DEM_CFG_ISDEF_FIRSTENTRYINDEXOFMEMORYINFOTABLE                                              STD_ON
#define DEM_CFG_ISDEF_FIRSTEVENTOFMEMORYINFOTABLE                                                   STD_ON
#define DEM_CFG_ISDEF_INDIVIDUALERECSIZEOFMEMORYINFOTABLE                                           STD_ON
#define DEM_CFG_ISDEF_INDIVIDUALSRECSIZEOFMEMORYINFOTABLE                                           STD_ON
#define DEM_CFG_ISDEF_LASTEVENTOFMEMORYINFOTABLE                                                    STD_ON
#define DEM_CFG_ISDEF_MAXNUMBERTIMESERIESSETSOFMEMORYINFOTABLE                                      STD_ON
#define DEM_CFG_ISDEF_MAXSIZEOFMEMORYINFOTABLE                                                      STD_ON
#define DEM_CFG_ISDEF_SRECNUMTYPEOFMEMORYINFOTABLE                                                  STD_ON
#define DEM_CFG_ISDEF_TIMESERIESFIFOSUPPORTOFMEMORYINFOTABLE                                        STD_ON
#define DEM_CFG_ISDEF_TIMESERIESSETSRECNUMOFFSETOFMEMORYINFOTABLE                                   STD_ON
#define DEM_CFG_ISDEF_TIMESERIESTRANSLATEDMEMORYIDOFMEMORYINFOTABLE                                 STD_ON
#define DEM_CFG_ISDEF_DTRTABLEIDXOFMIDTABLE                                                         STD_OFF
#define DEM_CFG_ISDEF_MIDOFMIDTABLE                                                                 STD_OFF
#define DEM_CFG_ISDEF_TIDOFMIDTABLE                                                                 STD_OFF
#define DEM_CFG_ISDEF_MARINDEXOFMONITORACTIVITYRATIOTABLE                                           STD_ON
#define DEM_CFG_ISDEF_SMARINDEXOFMONITORACTIVITYRATIOTABLE                                          STD_ON
#define DEM_CFG_ISDEF_EVENTPRECOMPILEDATATABLEIDXOFMULTIEVENTTRIGGERINGSLAVEEVENTSTABLE             STD_OFF
#define DEM_CFG_ISDEF_NVBLOCKDATAPTR                                                                STD_OFF
#define DEM_CFG_ISDEF_NVBLOCKDATASIZE                                                               STD_OFF
#define DEM_CFG_ISDEF_NVBLOCKID                                                                     STD_OFF
#define DEM_CFG_ISDEF_CALIBRATIONOBDDTCTABLEIDXOFOBDCALIBTABLE                                      STD_OFF
#define DEM_CFG_ISDEF_CALIBRATIONOBDDTCTABLEUSEDOFOBDCALIBTABLE                                     STD_OFF
#define DEM_CFG_ISDEF_OBDDTC3BYTEOFOBDCALIBTABLE                                                    STD_OFF
#define DEM_CFG_ISDEF_OBDDTCOFOBDCALIBTABLE                                                         STD_OFF
#define DEM_CFG_ISDEF_READINESSGROUPOFOBDCALIBTABLE                                                 STD_OFF
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEPID2COLLINDENDIDXOFPIDTABLE                                STD_OFF
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEPID2COLLINDSTARTIDXOFPIDTABLE                              STD_OFF
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEPID2COLLINDUSEDOFPIDTABLE                                  STD_OFF
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEIDXOFSAMPLINGPROFILEDIDINFOTABLE                           STD_OFF
#define DEM_CFG_ISDEF_DIDRINGBUFFEROFFSETOFSAMPLINGPROFILEDIDINFOTABLE                              STD_OFF
#define DEM_CFG_ISDEF_APPLICATIONIDOFSATELLITEINFO                                                  STD_ON
#define DEM_CFG_ISDEF_DEBOUNCELORESTIMEROFSATELLITEINFO                                             STD_OFF
#define DEM_CFG_ISDEF_EVENTCOUNTOFSATELLITEINFO                                                     STD_ON
#define DEM_CFG_ISDEF_EVENTPRECOMPILEDATATABLEINDENDIDXOFSATELLITEINFO                              STD_ON
#define DEM_CFG_ISDEF_EVENTPRECOMPILEDATATABLEINDSTARTIDXOFSATELLITEINFO                            STD_ON
#define DEM_CFG_ISDEF_EVENTPRECOMPILEDATATABLEINDUSEDOFSATELLITEINFO                                STD_ON
#define DEM_CFG_ISDEF_MAXDEBOUNCEVALUESOFSATELLITEINFO                                              STD_OFF
#define DEM_CFG_ISDEF_SATELLITEDATAOFSATELLITEINFO                                                  STD_ON
#define DEM_CFG_ISDEF_SATELLITEEXTENDEDDATAOFSATELLITEINFO                                          STD_OFF
#define DEM_CFG_ISDEF_SATELLITESTATUSOFSATELLITEINFO                                                STD_ON
#define DEM_CFG_ISDEF_TIMEBASEDEVENTTABLEENDIDXOFSATELLITETIMEDEBOUNCEINFO                          STD_OFF
#define DEM_CFG_ISDEF_TIMEBASEDEVENTTABLESTARTIDXOFSATELLITETIMEDEBOUNCEINFO                        STD_OFF
#define DEM_CFG_ISDEF_TIMEBASEDEVENTTABLEUSEDOFSATELLITETIMEDEBOUNCEINFO                            STD_OFF
#define DEM_CFG_ISDEF_J1939EVENTIDSWITHRATIOTABLEENDIDXOFSPNTOEVENTSWITHRATIOTABLE                  STD_OFF
#define DEM_CFG_ISDEF_J1939EVENTIDSWITHRATIOTABLESTARTIDXOFSPNTOEVENTSWITHRATIOTABLE                STD_OFF
#define DEM_CFG_ISDEF_SPNOFSPNTOEVENTSWITHRATIOTABLE                                                STD_OFF
#define DEM_CFG_ISDEF_INDEXOFSTORAGECONDITIONGROUPTABLE                                             STD_OFF
#define DEM_CFG_ISDEF_STORAGECONDITIONGROUPTABLEIND                                                 STD_OFF
#define DEM_CFG_ISDEF_FULFILLEDATINITOFSTORAGECONDITIONINITTABLE                                    STD_OFF
#define DEM_CFG_ISDEF_STORAGECONDITIONGROUPTABLEINDENDIDXOFSTORAGECONDITIONTABLE                    STD_OFF
#define DEM_CFG_ISDEF_STORAGECONDITIONGROUPTABLEINDSTARTIDXOFSTORAGECONDITIONTABLE                  STD_OFF
#define DEM_CFG_ISDEF_STORAGECONDITIONGROUPTABLEINDUSEDOFSTORAGECONDITIONTABLE                      STD_OFF
#define DEM_CFG_ISDEF_STARTIDXMIDTABLEOFSUPPORTEDMIDSTABLE                                          STD_OFF
#define DEM_CFG_ISDEF_DEBOUNCECONTINUOUSOFTIMEBASEDDEBOUNCETABLE                                    STD_OFF
#define DEM_CFG_ISDEF_EVENTDEBOUNCEBEHAVIOROFTIMEBASEDDEBOUNCETABLE                                 STD_OFF
#define DEM_CFG_ISDEF_FAILTIMERTHRESHOLDHIGHRESOFTIMEBASEDDEBOUNCETABLE                             STD_OFF
#define DEM_CFG_ISDEF_FAILTIMERTHRESHOLDLOWRESOFTIMEBASEDDEBOUNCETABLE                              STD_OFF
#define DEM_CFG_ISDEF_ISLOWRESOLUTIONOFTIMEBASEDDEBOUNCETABLE                                       STD_OFF
#define DEM_CFG_ISDEF_PASSTIMERTHRESHOLDHIGHRESOFTIMEBASEDDEBOUNCETABLE                             STD_OFF
#define DEM_CFG_ISDEF_PASSTIMERTHRESHOLDLOWRESOFTIMEBASEDDEBOUNCETABLE                              STD_OFF
#define DEM_CFG_ISDEF_STORAGETIMERTHRESHOLDHIGHRESOFTIMEBASEDDEBOUNCETABLE                          STD_OFF
#define DEM_CFG_ISDEF_STORAGETIMERTHRESHOLDLOWRESOFTIMEBASEDDEBOUNCETABLE                           STD_OFF
#define DEM_CFG_ISDEF_TIMEBASEDEVENTTABLE                                                           STD_OFF
#define DEM_CFG_ISDEF_TIMESERIESENTRYINDEXTONVBLOCKINDEX                                            STD_OFF
#define DEM_CFG_ISDEF_BASEENTRYOFTIMESERIESENTRYTABLE                                               STD_OFF
#define DEM_CFG_ISDEF_BUFFERSIZEOFTIMESERIESENTRYTABLE                                              STD_OFF
#define DEM_CFG_ISDEF_ENTRYDATAOFTIMESERIESENTRYTABLE                                               STD_OFF
#define DEM_CFG_ISDEF_MAXSNAPSHOTSIZEOFTIMESERIESENTRYTABLE                                         STD_OFF
#define DEM_CFG_ISDEF_FIRSTRECORDNUMBEROFTIMESERIESFREEZEFRAMETABLE                                 STD_OFF
#define DEM_CFG_ISDEF_LASTRECORDNUMBEROFTIMESERIESFREEZEFRAMETABLE                                  STD_OFF
#define DEM_CFG_ISDEF_RECORDTRIGGEROFTIMESERIESFREEZEFRAMETABLE                                     STD_OFF
#define DEM_CFG_ISDEF_TIMESERIESSAMPLINGPROFILETABLEIDXOFTIMESERIESFREEZEFRAMETABLE                 STD_OFF
#define DEM_CFG_ISDEF_UPDATERECORDOFTIMESERIESFREEZEFRAMETABLE                                      STD_OFF
#define DEM_CFG_ISDEF_TIMESERIESFREEZEFRAMETABLEIDXOFTIMESERIESINDIRECTIONTABLE                     STD_OFF
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEIDXOFTIMESERIESSAMPLINGPROFILECALIBTABLE                   STD_OFF
#define DEM_CFG_ISDEF_PASTSAMPLESOFTIMESERIESSAMPLINGPROFILECALIBTABLE                              STD_OFF
#define DEM_CFG_ISDEF_SAMPLINGPERIODTICSOFTIMESERIESSAMPLINGPROFILECALIBTABLE                       STD_OFF
#define DEM_CFG_ISDEF_SAMPLINGPROFILEDIDINFOTABLEENDIDXOFTIMESERIESSAMPLINGPROFILECALIBTABLE        STD_OFF
#define DEM_CFG_ISDEF_SAMPLINGPROFILEDIDINFOTABLESTARTIDXOFTIMESERIESSAMPLINGPROFILECALIBTABLE      STD_OFF
#define DEM_CFG_ISDEF_SAMPLINGPROFILEDIDINFOTABLEUSEDOFTIMESERIESSAMPLINGPROFILECALIBTABLE          STD_OFF
#define DEM_CFG_ISDEF_RINGBUFFERPTROFTIMESERIESSAMPLINGPROFILETABLE                                 STD_OFF
#define DEM_CFG_ISDEF_RINGBUFFERSAMPLESOFTIMESERIESSAMPLINGPROFILETABLE                             STD_OFF
#define DEM_CFG_ISDEF_SAMPLESIZEOFTIMESERIESSAMPLINGPROFILETABLE                                    STD_OFF
#define DEM_CFG_ISDEF_SEQUENTIALDIDIDOFTIMESERIESSAMPLINGPROFILETABLE                               STD_OFF
#define DEM_CFG_ISDEF_TIMESERIESSAMPLINGPROFILECALIBTABLEIDXOFTIMESERIESSAMPLINGPROFILETABLE        STD_OFF
#define DEM_CFG_ISDEF_TOTALSAMPLESOFTIMESERIESSAMPLINGPROFILETABLE                                  STD_OFF
#define DEM_CFG_ISDEF_MEMORYINFOTABLEIDXOFUSERDEFINEDORIGINTABLE                                    STD_OFF
#define DEM_CFG_ISDEF_MEMORYINFOTABLEUSEDOFUSERDEFINEDORIGINTABLE                                   STD_OFF
#define DEM_CFG_ISDEF_ADMINDATAOFPCCONFIG                                                           STD_ON
#define DEM_CFG_ISDEF_AGINGDATAOFPCCONFIG                                                           STD_ON
#define DEM_CFG_ISDEF_CALIBRATIONERRORREGISTEROFPCCONFIG                                            STD_ON
#define DEM_CFG_ISDEF_CALIBRATIONOBDDTCTABLEOFPCCONFIG                                              STD_ON
#define DEM_CFG_ISDEF_CALLBACKCLEAREVENTALLOWEDOFPCCONFIG                                           STD_ON
#define DEM_CFG_ISDEF_CALLBACKDTCSTATUSCHANGEDOFPCCONFIG                                            STD_ON
#define DEM_CFG_ISDEF_CALLBACKGETFDCOFPCCONFIG                                                      STD_ON
#define DEM_CFG_ISDEF_CALLBACKJ1939DTCSTATUSCHANGEDOFPCCONFIG                                       STD_ON
#define DEM_CFG_ISDEF_CLEARDTCTABLEOFPCCONFIG                                                       STD_ON
#define DEM_CFG_ISDEF_CLEARDTCNOTIFICATIONFINISHTABLEOFPCCONFIG                                     STD_ON
#define DEM_CFG_ISDEF_CLEARDTCNOTIFICATIONSTARTTABLEOFPCCONFIG                                      STD_ON
#define DEM_CFG_ISDEF_CLIENTTABLEOFPCCONFIG                                                         STD_ON
#define DEM_CFG_ISDEF_COMMITBUFFEROFPCCONFIG                                                        STD_ON
#define DEM_CFG_ISDEF_COMMONDIDLISTOFPCCONFIG                                                       STD_ON
#define DEM_CFG_ISDEF_CONFIGURATIONIDOFPCCONFIG                                                     STD_OFF
#define DEM_CFG_ISDEF_COUNTERBASEDDEBOUNCETABLEOFPCCONFIG                                           STD_ON
#define DEM_CFG_ISDEF_CUSTOMTIMESERIESFREEZEFRAMETABLEOFPCCONFIG                                    STD_ON
#define DEM_CFG_ISDEF_CUSTOMTRIGGERENTRYINDEXTONVBLOCKINDEXOFPCCONFIG                               STD_ON
#define DEM_CFG_ISDEF_CUSTOMTRIGGERENTRYPTROFPCCONFIG                                               STD_ON
#define DEM_CFG_ISDEF_CYCLECOUNTERDATAOFPCCONFIG                                                    STD_ON
#define DEM_CFG_ISDEF_CYCLEIDTABLEOFPCCONFIG                                                        STD_ON
#define DEM_CFG_ISDEF_DTCSELECTORTABLEOFPCCONFIG                                                    STD_ON
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEEREC2COLLINDOFPCCONFIG                                     STD_ON
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEIDXOFDATACOLLECTIONTABLEEDR2COLLINDOFPCCONFIG              STD_ON
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEIDXOFDATACOLLECTIONTABLEFFM2COLLINDOFPCCONFIG              STD_ON
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEOFPCCONFIG                                                 STD_ON
#define DEM_CFG_ISDEF_DATACOLLECTIONTABLEPID2COLLINDOFPCCONFIG                                      STD_ON
#define DEM_CFG_ISDEF_DATAELEMENTTABLEIDXOFDATAELEMENTTABLECOL2ELMTINDOFPCCONFIG                    STD_ON
#define DEM_CFG_ISDEF_DATAELEMENTTABLEOFPCCONFIG                                                    STD_ON
#define DEM_CFG_ISDEF_DEBOUNCEDATAOFPCCONFIG                                                        STD_ON
#define DEM_CFG_ISDEF_DEBOUNCEINDIRECTIONTABLEOFPCCONFIG                                            STD_ON
#define DEM_CFG_ISDEF_DTCCALIBTABLEOFPCCONFIG                                                       STD_ON
#define DEM_CFG_ISDEF_DTCGROUPMASKOFPCCONFIG                                                        STD_ON
#define DEM_CFG_ISDEF_DTCINVARIANTDATATABLEOFPCCONFIG                                               STD_ON
#define DEM_CFG_ISDEF_DTCTABLEOFPCCONFIG                                                            STD_ON
#define DEM_CFG_ISDEF_DTRDATAOFPCCONFIG                                                             STD_ON
#define DEM_CFG_ISDEF_DTRSTATUSOFPCCONFIG                                                           STD_ON
#define DEM_CFG_ISDEF_DTRTABLEINDOFPCCONFIG                                                         STD_ON
#define DEM_CFG_ISDEF_DTRTABLEOFPCCONFIG                                                            STD_ON
#define DEM_CFG_ISDEF_ENABLECONDITIONFULFILLEDOFPCCONFIG                                            STD_ON
#define DEM_CFG_ISDEF_ENABLECONDITIONGROUPCOUNTEROFPCCONFIG                                         STD_ON
#define DEM_CFG_ISDEF_ENABLECONDITIONGROUPSTATEOFPCCONFIG                                           STD_ON
#define DEM_CFG_ISDEF_ENABLECONDITIONGROUPTABLEINDOFPCCONFIG                                        STD_ON
#define DEM_CFG_ISDEF_ENABLECONDITIONGROUPTABLEOFPCCONFIG                                           STD_ON
#define DEM_CFG_ISDEF_ENABLECONDITIONINITTABLEOFPCCONFIG                                            STD_ON
#define DEM_CFG_ISDEF_ENABLECONDITIONTABLEOFPCCONFIG                                                STD_ON
#define DEM_CFG_ISDEF_EVENTAVAILABLEDATAOFPCCONFIG                                                  STD_ON
#define DEM_CFG_ISDEF_EVENTAVAILABLEDEFAULTOFPCCONFIG                                               STD_ON
#define DEM_CFG_ISDEF_EVENTAVAILABLEINVARIANTOFPCCONFIG                                             STD_OFF
#define DEM_CFG_ISDEF_EVENTCALIBTABLEOFPCCONFIG                                                     STD_ON
#define DEM_CFG_ISDEF_EVENTCYCLESTATUSOFPCCONFIG                                                    STD_ON
#define DEM_CFG_ISDEF_EVENTDATACHANGEDOFPCCONFIG                                                    STD_ON
#define DEM_CFG_ISDEF_EVENTDATACOMMITNUMBEROFPCCONFIG                                               STD_ON
#define DEM_CFG_ISDEF_EVENTENTRYINDEXTONVBLOCKINDEXOFPCCONFIG                                       STD_ON
#define DEM_CFG_ISDEF_EVENTENTRYINFOTABLEOFPCCONFIG                                                 STD_ON
#define DEM_CFG_ISDEF_EVENTINDICATORDATAOFPCCONFIG                                                  STD_ON
#define DEM_CFG_ISDEF_EVENTINTERNALSTATUSOFPCCONFIG                                                 STD_ON
#define DEM_CFG_ISDEF_EVENTINVARIANTDATATABLEOFPCCONFIG                                             STD_ON
#define DEM_CFG_ISDEF_EVENTPRECOMPILEDATATABLEINDOFPCCONFIG                                         STD_ON
#define DEM_CFG_ISDEF_EVENTPRECOMPILEDATATABLEOFPCCONFIG                                            STD_ON
#define DEM_CFG_ISDEF_EVENTSTATUSCHANGEDOFPCCONFIG                                                  STD_ON
#define DEM_CFG_ISDEF_EVENTTABLEOFPCCONFIG                                                          STD_ON
#define DEM_CFG_ISDEF_EVENTTABLE_EREC2EVENTIDINDOFPCCONFIG                                          STD_ON
#define DEM_CFG_ISDEF_EXTENDEDDATARECORDITERATORTABLEOFPCCONFIG                                     STD_ON
#define DEM_CFG_ISDEF_EXTENDEDDATARECORDTABLEOFPCCONFIG                                             STD_ON
#define DEM_CFG_ISDEF_EXTENDEDDATATABLEOFPCCONFIG                                                   STD_ON
#define DEM_CFG_ISDEF_FILTERINFOTABLEOFPCCONFIG                                                     STD_ON
#define DEM_CFG_ISDEF_FREEZEFRAMEDATAOFPCCONFIG                                                     STD_ON
#define DEM_CFG_ISDEF_FREEZEFRAMEITERATORTABLEOFPCCONFIG                                            STD_ON
#define DEM_CFG_ISDEF_FREEZEFRAMENUMINDIRECTIONTABLEOFPCCONFIG                                      STD_ON
#define DEM_CFG_ISDEF_FREEZEFRAMENUMTABLEOFPCCONFIG                                                 STD_ON
#define DEM_CFG_ISDEF_FREEZEFRAMETABLEOFPCCONFIG                                                    STD_ON
#define DEM_CFG_ISDEF_GENERALJ1939TABLEOFPCCONFIG                                                   STD_ON
#define DEM_CFG_ISDEF_GENERALOBDINPUTOFPCCONFIG                                                     STD_ON
#define DEM_CFG_ISDEF_GLOBALSNAPSHOTRECORDOFPCCONFIG                                                STD_ON
#define DEM_CFG_ISDEF_INDICATORATTRIBUTETABLEOFPCCONFIG                                             STD_ON
#define DEM_CFG_ISDEF_INDICATORDATAOFPCCONFIG                                                       STD_ON
#define DEM_CFG_ISDEF_INDICATOREVENTCOUNTERSOFPCCONFIG                                              STD_ON
#define DEM_CFG_ISDEF_INITMONLISTFORFUNCOFPCCONFIG                                                  STD_ON
#define DEM_CFG_ISDEF_INITMONITORFOREVENTOFPCCONFIG                                                 STD_ON
#define DEM_CFG_ISDEF_INITMONITORSFORFUNCOFPCCONFIG                                                 STD_ON
#define DEM_CFG_ISDEF_J1939EVENTIDSWITHRATIOTABLEOFPCCONFIG                                         STD_ON
#define DEM_CFG_ISDEF_J1939NODEIDINDOFPCCONFIG                                                      STD_ON
#define DEM_CFG_ISDEF_J1939NODEIDOFPCCONFIG                                                         STD_ON
#define DEM_CFG_ISDEF_J1939NODEINDICATORAVAILABILITYOFPCCONFIG                                      STD_ON
#define DEM_CFG_ISDEF_J1939SPNSINEXPANDEDFREEZEFRAMETABLEOFPCCONFIG                                 STD_ON
#define DEM_CFG_ISDEF_MEMORYCURRENTCOUNTOFPCCONFIG                                                  STD_ON
#define DEM_CFG_ISDEF_MEMORYINFOTABLEOFPCCONFIG                                                     STD_ON
#define DEM_CFG_ISDEF_MEMORYSTATUSOFPCCONFIG                                                        STD_ON
#define DEM_CFG_ISDEF_MIDTABLEOFPCCONFIG                                                            STD_ON
#define DEM_CFG_ISDEF_MIRRORDATAOFPCCONFIG                                                          STD_ON
#define DEM_CFG_ISDEF_MONITORACTIVITYRATIOTABLEOFPCCONFIG                                           STD_ON
#define DEM_CFG_ISDEF_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLEOFPCCONFIG                                STD_ON
#define DEM_CFG_ISDEF_NVBLOCKDATAPTROFPCCONFIG                                                      STD_ON
#define DEM_CFG_ISDEF_NVBLOCKDATASIZEOFPCCONFIG                                                     STD_ON
#define DEM_CFG_ISDEF_NVBLOCKIDOFPCCONFIG                                                           STD_ON
#define DEM_CFG_ISDEF_OBDCALIBTABLEOFPCCONFIG                                                       STD_ON
#define DEM_CFG_ISDEF_OBDIUMPRDATAOFPCCONFIG                                                        STD_ON
#define DEM_CFG_ISDEF_OBDIUMPRUPDATEPENDINGOFPCCONFIG                                               STD_ON
#define DEM_CFG_ISDEF_PERMANENTDATAOFPCCONFIG                                                       STD_ON
#define DEM_CFG_ISDEF_PIDTABLEOFPCCONFIG                                                            STD_ON
#define DEM_CFG_ISDEF_PRESTORAGEINDEXOFPCCONFIG                                                     STD_ON
#define DEM_CFG_ISDEF_PRESTORAGEOFPCCONFIG                                                          STD_ON
#define DEM_CFG_ISDEF_PRIMARYCHRONOLOGYOFPCCONFIG                                                   STD_ON
#define DEM_CFG_ISDEF_PRIMARYENTRY_0OFPCCONFIG                                                      STD_ON
#define DEM_CFG_ISDEF_PRIMARYENTRY_1OFPCCONFIG                                                      STD_ON
#define DEM_CFG_ISDEF_PRIMARYENTRY_2OFPCCONFIG                                                      STD_ON
#define DEM_CFG_ISDEF_PRIMARYENTRY_3OFPCCONFIG                                                      STD_ON
#define DEM_CFG_ISDEF_PRIMARYENTRY_4OFPCCONFIG                                                      STD_ON
#define DEM_CFG_ISDEF_PRIMARYENTRY_5OFPCCONFIG                                                      STD_ON
#define DEM_CFG_ISDEF_PRIMARYENTRY_6OFPCCONFIG                                                      STD_ON
#define DEM_CFG_ISDEF_PRIMARYENTRY_7OFPCCONFIG                                                      STD_ON
#define DEM_CFG_ISDEF_PRIMARYENTRY_8OFPCCONFIG                                                      STD_ON
#define DEM_CFG_ISDEF_PRIMARYENTRY_9OFPCCONFIG                                                      STD_ON
#define DEM_CFG_ISDEF_PRIMARYEVENTENTRYINITOFPCCONFIG                                               STD_ON
#define DEM_CFG_ISDEF_RATIOIDTABLEOFPCCONFIG                                                        STD_ON
#define DEM_CFG_ISDEF_READOUTBUFFEROFPCCONFIG                                                       STD_ON
#define DEM_CFG_ISDEF_REPORTEDEVENTSOFFILTEROFPCCONFIG                                              STD_ON
#define DEM_CFG_ISDEF_RINGBUFFEROFPCCONFIG                                                          STD_ON
#define DEM_CFG_ISDEF_SAMPLINGPROFILEDIDINFOTABLEOFPCCONFIG                                         STD_ON
#define DEM_CFG_ISDEF_SATELLITEINFOINVALID_OSAPPLICATIONOFPCCONFIG                                  STD_ON
#define DEM_CFG_ISDEF_SATELLITEINFOOFPCCONFIG                                                       STD_ON
#define DEM_CFG_ISDEF_SATELLITETIMEDEBOUNCEINFOOFPCCONFIG                                           STD_ON
#define DEM_CFG_ISDEF_SPNTOEVENTSWITHRATIOTABLEOFPCCONFIG                                           STD_ON
#define DEM_CFG_ISDEF_STARTIDX500MIDENRATIOTABLEOFPCCONFIG                                          STD_ON
#define DEM_CFG_ISDEF_STATUSDATAOFPCCONFIG                                                          STD_ON
#define DEM_CFG_ISDEF_STORAGECONDITIONFULFILLEDOFPCCONFIG                                           STD_ON
#define DEM_CFG_ISDEF_STORAGECONDITIONGROUPCOUNTEROFPCCONFIG                                        STD_ON
#define DEM_CFG_ISDEF_STORAGECONDITIONGROUPTABLEINDOFPCCONFIG                                       STD_ON
#define DEM_CFG_ISDEF_STORAGECONDITIONGROUPTABLEOFPCCONFIG                                          STD_ON
#define DEM_CFG_ISDEF_STORAGECONDITIONINITTABLEOFPCCONFIG                                           STD_ON
#define DEM_CFG_ISDEF_STORAGECONDITIONTABLEOFPCCONFIG                                               STD_ON
#define DEM_CFG_ISDEF_SUPPORTEDMIDSTABLEOFPCCONFIG                                                  STD_ON
#define DEM_CFG_ISDEF_TIMEBASEDDEBOUNCETABLEOFPCCONFIG                                              STD_ON
#define DEM_CFG_ISDEF_TIMEBASEDEVENTTABLEOFPCCONFIG                                                 STD_ON
#define DEM_CFG_ISDEF_TIMESERIESENTRYINDEXTONVBLOCKINDEXOFPCCONFIG                                  STD_ON
#define DEM_CFG_ISDEF_TIMESERIESENTRYTABLEOFPCCONFIG                                                STD_ON
#define DEM_CFG_ISDEF_TIMESERIESFREEZEFRAMETABLEOFPCCONFIG                                          STD_ON
#define DEM_CFG_ISDEF_TIMESERIESINDIRECTIONTABLEOFPCCONFIG                                          STD_ON
#define DEM_CFG_ISDEF_TIMESERIESSAMPLINGPROFILECALIBTABLEOFPCCONFIG                                 STD_ON
#define DEM_CFG_ISDEF_TIMESERIESSAMPLINGPROFILETABLEOFPCCONFIG                                      STD_ON
#define DEM_CFG_ISDEF_USERDEFINEDORIGINTABLEOFPCCONFIG                                              STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCEqualsAlwaysToDefines  Dem_Cfg Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define DEM_CFG_EQ2_AGINGALLOWEDOFCALIBRATIONOBDDTCTABLE                                            
#define DEM_CFG_EQ2_AGINGCYCLECOUNTERTHRESHOLDOFCALIBRATIONOBDDTCTABLE                              
#define DEM_CFG_EQ2_AGINGCYCLEIDOFCALIBRATIONOBDDTCTABLE                                            
#define DEM_CFG_EQ2_IMMEDIATENVSTORAGEOFCALIBRATIONOBDDTCTABLE                                      
#define DEM_CFG_EQ2_OPERATIONCYCLEIDOFCALIBRATIONOBDDTCTABLE                                        
#define DEM_CFG_EQ2_READINESSGROUPOFCALIBRATIONOBDDTCTABLE                                          
#define DEM_CFG_EQ2_USEEXTENDEDDATARECORD0X93OFCALIBRATIONOBDDTCTABLE                               
#define DEM_CFG_EQ2_CALLBACKCLEAREVENTALLOWED                                                       
#define DEM_CFG_EQ2_CALLBACKDTCSTATUSCHANGED                                                        
#define DEM_CFG_EQ2_CALLBACKGETFDC                                                                  
#define DEM_CFG_EQ2_CALLBACKJ1939DTCSTATUSCHANGED                                                   
#define DEM_CFG_EQ2_CLEARDTCNOTIFICATIONFINISHTABLE                                                 
#define DEM_CFG_EQ2_CLEARDTCNOTIFICATIONSTARTTABLE                                                  
#define DEM_CFG_EQ2_CLEARDTCINDEXOFCLIENTTABLE                                                      0u
#define DEM_CFG_EQ2_FILTERINDEXOFCLIENTTABLE                                                        0u
#define DEM_CFG_EQ2_FREEZEFRAMEITERATORINDEXOFCLIENTTABLE                                           0u
#define DEM_CFG_EQ2_NMNODEIDOFCLIENTTABLE                                                           J1939NmConf_J1939NmNode_J1939NmNode
#define DEM_CFG_EQ2_READOUTBUFFERINDEXOFCLIENTTABLE                                                 0u
#define DEM_CFG_EQ2_SELECTORINDEXOFCLIENTTABLE                                                      0u
#define DEM_CFG_EQ2_FREEZEFRAMETABLEIDXOFCOMMONDIDLIST                                              0u
#define DEM_CFG_EQ2_DEBOUNCECONTINUOUSOFCOUNTERBASEDDEBOUNCETABLE                                   FALSE
#define DEM_CFG_EQ2_DECREMENTSTEPSIZEOFCOUNTERBASEDDEBOUNCETABLE                                    -20
#define DEM_CFG_EQ2_EVENTDEBOUNCEBEHAVIOROFCOUNTERBASEDDEBOUNCETABLE                                FALSE
#define DEM_CFG_EQ2_FAILEDTHRESHOLDOFCOUNTERBASEDDEBOUNCETABLE                                      127
#define DEM_CFG_EQ2_INCREMENTSTEPSIZEOFCOUNTERBASEDDEBOUNCETABLE                                    20
#define DEM_CFG_EQ2_JUMPDOWNOFCOUNTERBASEDDEBOUNCETABLE                                             TRUE
#define DEM_CFG_EQ2_JUMPDOWNVALUEOFCOUNTERBASEDDEBOUNCETABLE                                        0
#define DEM_CFG_EQ2_JUMPUPOFCOUNTERBASEDDEBOUNCETABLE                                               FALSE
#define DEM_CFG_EQ2_JUMPUPVALUEOFCOUNTERBASEDDEBOUNCETABLE                                          0
#define DEM_CFG_EQ2_MASKEDBITSOFCOUNTERBASEDDEBOUNCETABLE                                           0x02u
#define DEM_CFG_EQ2_PASSEDTHRESHOLDOFCOUNTERBASEDDEBOUNCETABLE                                      -128
#define DEM_CFG_EQ2_STORAGETHRESHOLDOFCOUNTERBASEDDEBOUNCETABLE                                     
#define DEM_CFG_EQ2_FIRSTRECORDNUMBEROFCUSTOMTIMESERIESFREEZEFRAMETABLE                             
#define DEM_CFG_EQ2_LASTRECORDNUMBEROFCUSTOMTIMESERIESFREEZEFRAMETABLE                              
#define DEM_CFG_EQ2_TIMESERIESSAMPLINGPROFILETABLEIDXOFCUSTOMTIMESERIESFREEZEFRAMETABLE             
#define DEM_CFG_EQ2_UPDATERECORDOFCUSTOMTIMESERIESFREEZEFRAMETABLE                                  
#define DEM_CFG_EQ2_CUSTOMTRIGGERENTRYINDEXTONVBLOCKINDEX                                           
#define DEM_CFG_EQ2_CUSTOMTRIGGERENTRYPTR                                                           
#define DEM_CFG_EQ2_ENDSONINITOFCYCLEIDTABLE                                                        
#define DEM_CFG_EQ2_OPCYCLETYPEOFCYCLEIDTABLE                                                       DEM_CFG_OPCYC_POWER
#define DEM_CFG_EQ2_COLLECTIONSIZEOFDATACOLLECTIONTABLE                                             
#define DEM_CFG_EQ2_DATAELEMENTTABLECOL2ELMTINDDATAELEMENTTABLECOL2ELMTINDENDIDXOFDATACOLLECTIONTABLE 
#define DEM_CFG_EQ2_DATAELEMENTTABLECOL2ELMTINDDATAELEMENTTABLECOL2ELMTINDSTARTIDXOFDATACOLLECTIONTABLE 
#define DEM_CFG_EQ2_DATAELEMENTTABLECOL2ELMTINDDATAELEMENTTABLECOL2ELMTINDUSEDOFDATACOLLECTIONTABLE 
#define DEM_CFG_EQ2_EVENTTABLE_EREC2EVENTIDINDENDIDXOFDATACOLLECTIONTABLE                           
#define DEM_CFG_EQ2_EVENTTABLE_EREC2EVENTIDINDSTARTIDXOFDATACOLLECTIONTABLE                         
#define DEM_CFG_EQ2_EVENTTABLE_EREC2EVENTIDINDUSEDOFDATACOLLECTIONTABLE                             
#define DEM_CFG_EQ2_IDNUMBEROFDATACOLLECTIONTABLE                                                   
#define DEM_CFG_EQ2_STORAGEKINDOFDATACOLLECTIONTABLE                                                
#define DEM_CFG_EQ2_TRIGGEROFDATACOLLECTIONTABLE                                                    DEM_CFG_TRIGGER_NONE
#define DEM_CFG_EQ2_UPDATEOFDATACOLLECTIONTABLE                                                     
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEEREC2COLLIND                                                 
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEIDXOFDATACOLLECTIONTABLEEDR2COLLIND                          
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEIDXOFDATACOLLECTIONTABLEFFM2COLLIND                          
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEPID2COLLIND                                                  
#define DEM_CFG_EQ2_DATAISSTOREDINNVOFDATAELEMENTTABLE                                              
#define DEM_CFG_EQ2_ELEMENTDATATYPEOFDATAELEMENTTABLE                                               
#define DEM_CFG_EQ2_ELEMENTKINDOFDATAELEMENTTABLE                                                   
#define DEM_CFG_EQ2_ELEMENTSIZEOFDATAELEMENTTABLE                                                   
#define DEM_CFG_EQ2_READDATAFUNCOFDATAELEMENTTABLE                                                  
#define DEM_CFG_EQ2_DATAELEMENTTABLEIDXOFDATAELEMENTTABLECOL2ELMTIND                                
#define DEM_CFG_EQ2_COUNTERBASEDDEBOUNCETABLEIDXOFDEBOUNCEINDIRECTIONTABLE                          
#define DEM_CFG_EQ2_COUNTERBASEDDEBOUNCETABLEUSEDOFDEBOUNCEINDIRECTIONTABLE                         
#define DEM_CFG_EQ2_TIMEBASEDDEBOUNCETABLEIDXOFDEBOUNCEINDIRECTIONTABLE                             
#define DEM_CFG_EQ2_TIMEBASEDDEBOUNCETABLEUSEDOFDEBOUNCEINDIRECTIONTABLE                            
#define DEM_CFG_EQ2_AGINGCYCLECOUNTERTHRESHOLDOFDTCCALIBTABLE                                       
#define DEM_CFG_EQ2_AGINGCYCLEIDOFDTCCALIBTABLE                                                     
#define DEM_CFG_EQ2_DTCPRIORITYOFDTCCALIBTABLE                                                      
#define DEM_CFG_EQ2_DTCSEVERITYOFDTCCALIBTABLE                                                      0u
#define DEM_CFG_EQ2_UDSDTCOFDTCCALIBTABLE                                                           
#define DEM_CFG_EQ2_GROUPMASKOFDTCGROUPMASK                                                         
#define DEM_CFG_EQ2_UDSGROUPDTCOFDTCGROUPMASK                                                       
#define DEM_CFG_EQ2_AGINGALLOWEDOFDTCINVARIANTDATATABLE                                             
#define DEM_CFG_EQ2_FREEZEFRAMETABLESECONDSTDFFIDXOFDTCINVARIANTDATATABLE                           0u
#define DEM_CFG_EQ2_FREEZEFRAMETABLESTDFFIDXOFDTCINVARIANTDATATABLE                                 
#define DEM_CFG_EQ2_FUNCTIONALUNITOFDTCINVARIANTDATATABLE                                           
#define DEM_CFG_EQ2_CUSTOMTIMESERIESFREEZEFRAMETABLEIDXOFDTCTABLE                                   
#define DEM_CFG_EQ2_CUSTOMTIMESERIESFREEZEFRAMETABLEUSEDOFDTCTABLE                                  
#define DEM_CFG_EQ2_CUSTOMTRIGGEREDSNAPSHOTCONFIGUREDOFDTCTABLE                                     
#define DEM_CFG_EQ2_CUSTOMTRIGGEREDTIMESERIESSNAPSHOTCONFIGUREDOFDTCTABLE                           
#define DEM_CFG_EQ2_DTCOBDRELEVANCEOFDTCTABLE                                                       
#define DEM_CFG_EQ2_EVENTSIGNIFICANCEOFDTCTABLE                                                     DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFDTCTABLE
#define DEM_CFG_EQ2_EXTENDEDDATATABLEIDXOFDTCTABLE                                                  
#define DEM_CFG_EQ2_FREEZEFRAMENUMINDIRECTIONTABLEIDXOFDTCTABLE                                     
#define DEM_CFG_EQ2_FREEZEFRAMENUMINDIRECTIONTABLEUSEDOFDTCTABLE                                    
#define DEM_CFG_EQ2_IMMEDIATENVSTORAGEOFDTCTABLE                                                    FALSE
#define DEM_CFG_EQ2_J1939DTCOFDTCTABLE                                                              16777215u
#define DEM_CFG_EQ2_J1939NODEIDINDENDIDXOFDTCTABLE                                                  
#define DEM_CFG_EQ2_J1939NODEIDINDSTARTIDXOFDTCTABLE                                                
#define DEM_CFG_EQ2_J1939NODEIDINDUSEDOFDTCTABLE                                                    
#define DEM_CFG_EQ2_SMARINDEXOFDTCTABLE                                                             
#define DEM_CFG_EQ2_TIMESERIESINDIRECTIONTABLEENDIDXOFDTCTABLE                                      
#define DEM_CFG_EQ2_TIMESERIESINDIRECTIONTABLESTARTIDXOFDTCTABLE                                    
#define DEM_CFG_EQ2_TIMESERIESINDIRECTIONTABLEUSEDOFDTCTABLE                                        
#define DEM_CFG_EQ2_DIVISOROFDTRTABLE                                                               
#define DEM_CFG_EQ2_EVENTTABLEIDXOFDTRTABLE                                                         
#define DEM_CFG_EQ2_LINEARFACTOROFDTRTABLE                                                          
#define DEM_CFG_EQ2_OFFSETOFDTRTABLE                                                                
#define DEM_CFG_EQ2_UASIDOFDTRTABLE                                                                 
#define DEM_CFG_EQ2_UPDATEKINDOFDTRTABLE                                                            
#define DEM_CFG_EQ2_DTRTABLEIND                                                                     
#define DEM_CFG_EQ2_INDEXOFENABLECONDITIONGROUPTABLE                                                0u
#define DEM_CFG_EQ2_ENABLECONDITIONGROUPTABLEIND                                                    0u
#define DEM_CFG_EQ2_FULFILLEDATINITOFENABLECONDITIONINITTABLE                                       TRUE
#define DEM_CFG_EQ2_ENABLECONDITIONGROUPTABLEINDENDIDXOFENABLECONDITIONTABLE                        1u
#define DEM_CFG_EQ2_ENABLECONDITIONGROUPTABLEINDSTARTIDXOFENABLECONDITIONTABLE                      0u
#define DEM_CFG_EQ2_ENABLECONDITIONGROUPTABLEINDUSEDOFENABLECONDITIONTABLE                          TRUE
#define DEM_CFG_EQ2_EVENTAVAILABLEDEFAULT                                                           TRUE
#define DEM_CFG_EQ2_EVENTAVAILABLEINVARIANT                                                         
#define DEM_CFG_EQ2_EVENTFAILURECYCLECOUNTERTHRESHOLDOFEVENTCALIBTABLE                              0u
#define DEM_CFG_EQ2_OPERATIONCYCLEIDOFEVENTCALIBTABLE                                               DemConf_DemOperationCycle_Power_On_Off
#define DEM_CFG_EQ2_EVENTDATACHANGED                                                                
#define DEM_CFG_EQ2_EVENTENTRYINDEXTONVBLOCKINDEX                                                   
#define DEM_CFG_EQ2_BASEENTRYPTROFEVENTENTRYINFOTABLE                                               
#define DEM_CFG_EQ2_EXTENDEDDATAPTROFEVENTENTRYINFOTABLE                                            
#define DEM_CFG_EQ2_INITPTROFEVENTENTRYINFOTABLE                                                    
#define DEM_CFG_EQ2_J1939FREEZEFRAMEDATAPTROFEVENTENTRYINFOTABLE                                    
#define DEM_CFG_EQ2_OBDFREEZEFRAMEDATAPTROFEVENTENTRYINFOTABLE                                      
#define DEM_CFG_EQ2_SIZEOFEXTENDEDDATAOFEVENTENTRYINFOTABLE                                         
#define DEM_CFG_EQ2_SIZEOFJ1939EXPFREEZEFRAMEOFEVENTENTRYINFOTABLE                                  
#define DEM_CFG_EQ2_SIZEOFJ1939FREEZEFRAMEOFEVENTENTRYINFOTABLE                                     
#define DEM_CFG_EQ2_SIZEOFOBDFREEZEFRAMEOFEVENTENTRYINFOTABLE                                       
#define DEM_CFG_EQ2_SIZEOFSNAPSHOTDATAOFEVENTENTRYINFOTABLE                                         
#define DEM_CFG_EQ2_SNAPSHOTDATAPTROFEVENTENTRYINFOTABLE                                            
#define DEM_CFG_EQ2_ASSIGNEDATTRIBUTEBITFIELDOFEVENTINDICATORDATA                                   
#define DEM_CFG_EQ2_EVENTHEALINGTARGETOFEVENTINDICATORDATA                                          
#define DEM_CFG_EQ2_DTCTABLEIDXOFEVENTINVARIANTDATATABLE                                            
#define DEM_CFG_EQ2_CALLBACKGETFDCIDXOFEVENTPRECOMPILEDATATABLE                                     
#define DEM_CFG_EQ2_DEBOUNCECOUNTERSTORAGEOFEVENTPRECOMPILEDATATABLE                                FALSE
#define DEM_CFG_EQ2_EVENTCONSIDERPTOSTATUSOFEVENTPRECOMPILEDATATABLE                                
#define DEM_CFG_EQ2_EVENTKINDOFEVENTPRECOMPILEDATATABLE                                             DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTPRECOMPILEDATATABLE
#define DEM_CFG_EQ2_EVENTLATCHTFOFEVENTPRECOMPILEDATATABLE                                          FALSE
#define DEM_CFG_EQ2_EVENTSTATUSCHANGEDENDIDXOFEVENTPRECOMPILEDATATABLE                              
#define DEM_CFG_EQ2_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE                            
#define DEM_CFG_EQ2_EVENTSTATUSCHANGEDUSEDOFEVENTPRECOMPILEDATATABLE                                
#define DEM_CFG_EQ2_MASKEDBITSOFEVENTPRECOMPILEDATATABLE                                            0x00u
#define DEM_CFG_EQ2_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLEENDIDXOFEVENTPRECOMPILEDATATABLE            
#define DEM_CFG_EQ2_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLESTARTIDXOFEVENTPRECOMPILEDATATABLE          
#define DEM_CFG_EQ2_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLEUSEDOFEVENTPRECOMPILEDATATABLE              
#define DEM_CFG_EQ2_MULTIEVENTTRIGGERINGSLAVEOFEVENTPRECOMPILEDATATABLE                             
#define DEM_CFG_EQ2_SATELLITEEVENTIDXOFEVENTPRECOMPILEDATATABLE                                     
#define DEM_CFG_EQ2_SATELLITEINFOIDXOFEVENTPRECOMPILEDATATABLE                                      0u
#define DEM_CFG_EQ2_EVENTPRECOMPILEDATATABLEIND                                                     
#define DEM_CFG_EQ2_EVENTSTATUSCHANGED                                                              
#define DEM_CFG_EQ2_DTRTABLEINDENDIDXOFEVENTTABLE                                                   
#define DEM_CFG_EQ2_DTRTABLEINDSTARTIDXOFEVENTTABLE                                                 
#define DEM_CFG_EQ2_DTRTABLEINDUSEDOFEVENTTABLE                                                     
#define DEM_CFG_EQ2_ENABLECONDITIONGROUPTABLEIDXOFEVENTTABLE                                        
#define DEM_CFG_EQ2_ENABLECONDITIONGROUPTABLEUSEDOFEVENTTABLE                                       
#define DEM_CFG_EQ2_EVENTCALIBTABLEIDXOFEVENTTABLE                                                  0u
#define DEM_CFG_EQ2_EVENTDESTINATIONOFEVENTTABLE                                                    DEM_CFG_MEMORYID_PRIMARY
#define DEM_CFG_EQ2_EVENTINDICATORDATAIDXOFEVENTTABLE                                               
#define DEM_CFG_EQ2_EVENTINDICATORDATAUSEDOFEVENTTABLE                                              
#define DEM_CFG_EQ2_EVENTINVARIANTDATATABLEIDXOFEVENTTABLE                                          
#define DEM_CFG_EQ2_EVENTPTOTIMERINDEXOFEVENTTABLE                                                  
#define DEM_CFG_EQ2_FAILEDCYCLECOUNTERINDEXOFEVENTTABLE                                             
#define DEM_CFG_EQ2_FAULTPENDINGCOUNTERINDEXOFEVENTTABLE                                            
#define DEM_CFG_EQ2_MAXFDCSINCELASTCLEARINDEXOFEVENTTABLE                                           
#define DEM_CFG_EQ2_MONITORACTIVITYRATIOTABLEIDXOFEVENTTABLE                                        
#define DEM_CFG_EQ2_OBDVISIBILITYDELAYEDUNTILDCYQUALIFICATIONOFEVENTTABLE                           FALSE
#define DEM_CFG_EQ2_EVENTTABLE_EREC2EVENTIDIND                                                      
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEEREC2COLLINDENDIDXOFEXTENDEDDATARECORDTABLE                  2u
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEEREC2COLLINDSTARTIDXOFEXTENDEDDATARECORDTABLE                0u
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEEREC2COLLINDUSEDOFEXTENDEDDATARECORDTABLE                    TRUE
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEEDR2COLLINDDATACOLLECTIONTABLEEDR2COLLINDENDIDXOFEXTENDEDDATATABLE 
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEEDR2COLLINDDATACOLLECTIONTABLEEDR2COLLINDSTARTIDXOFEXTENDEDDATATABLE 
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEEDR2COLLINDDATACOLLECTIONTABLEEDR2COLLINDUSEDOFEXTENDEDDATATABLE 
#define DEM_CFG_EQ2_MAXRECORDSIZEOFEXTENDEDDATATABLE                                                
#define DEM_CFG_EQ2_FREEZEFRAMENUMTABLEENDIDXOFFREEZEFRAMENUMINDIRECTIONTABLE                       
#define DEM_CFG_EQ2_FREEZEFRAMENUMTABLESECONDENDIDXOFFREEZEFRAMENUMINDIRECTIONTABLE                 
#define DEM_CFG_EQ2_FREEZEFRAMENUMTABLESECONDSTARTIDXOFFREEZEFRAMENUMINDIRECTIONTABLE               
#define DEM_CFG_EQ2_FREEZEFRAMENUMTABLESECONDUSEDOFFREEZEFRAMENUMINDIRECTIONTABLE                   
#define DEM_CFG_EQ2_FREEZEFRAMENUMTABLESTARTIDXOFFREEZEFRAMENUMINDIRECTIONTABLE                     
#define DEM_CFG_EQ2_FREEZEFRAMENUMTABLEUSEDOFFREEZEFRAMENUMINDIRECTIONTABLE                         
#define DEM_CFG_EQ2_FFNUMBEROFFREEZEFRAMENUMTABLE                                                   1u
#define DEM_CFG_EQ2_FFTRIGGEROFFREEZEFRAMENUMTABLE                                                  DEM_CFG_TRIGGER_TESTFAILED
#define DEM_CFG_EQ2_FFUPDATEOFFREEZEFRAMENUMTABLE                                                   TRUE
#define DEM_CFG_EQ2_ISGLOBALOFFREEZEFRAMENUMTABLE                                                   FALSE
#define DEM_CFG_EQ2_MASKEDBITSOFFREEZEFRAMENUMTABLE                                                 0x02u
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEFFM2COLLINDDATACOLLECTIONTABLEFFM2COLLINDENDIDXOFFREEZEFRAMETABLE 
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEFFM2COLLINDDATACOLLECTIONTABLEFFM2COLLINDSTARTIDXOFFREEZEFRAMETABLE 
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEFFM2COLLINDDATACOLLECTIONTABLEFFM2COLLINDUSEDOFFREEZEFRAMETABLE 
#define DEM_CFG_EQ2_RECORDSIZEOFFREEZEFRAMETABLE                                                    
#define DEM_CFG_EQ2_RECORDSIZEUDSOFFREEZEFRAMETABLE                                                 
#define DEM_CFG_EQ2_RECORDSIZEOFGENERALJ1939TABLE                                                   
#define DEM_CFG_EQ2_DATAELEMENTTABLEIDXOFGENERALOBDINPUT                                            0u
#define DEM_CFG_EQ2_FREEZEFRAMETABLEIDXOFGLOBALSNAPSHOTRECORD                                       0u
#define DEM_CFG_EQ2_BEHAVIOUROFINDICATORATTRIBUTETABLE                                              
#define DEM_CFG_EQ2_FAILURECYCLECOUNTERTHRESHOLDOFINDICATORATTRIBUTETABLE                           
#define DEM_CFG_EQ2_IDOFINDICATORATTRIBUTETABLE                                                     
#define DEM_CFG_EQ2_J1939NODEIDOFINDICATORATTRIBUTETABLE                                            
#define DEM_CFG_EQ2_INITMONITORFOREVENT                                                             
#define DEM_CFG_EQ2_INITMONITORSFORFUNC                                                             
#define DEM_CFG_EQ2_EVENTIDOFJ1939EVENTIDSWITHRATIOTABLE                                            
#define DEM_CFG_EQ2_J1939NODEID                                                                     
#define DEM_CFG_EQ2_J1939NODEIDIND                                                                  
#define DEM_CFG_EQ2_J1939NODEINDICATORAVAILABILITY                                                  0xFFu
#define DEM_CFG_EQ2_SPNIDOFJ1939SPNSINEXPANDEDFREEZEFRAMETABLE                                      
#define DEM_CFG_EQ2_SPNSIZEOFJ1939SPNSINEXPANDEDFREEZEFRAMETABLE                                    
#define DEM_CFG_EQ2_CHRONOPTROFMEMORYINFOTABLE                                                      &Dem_Cfg_PrimaryChronology[0]
#define DEM_CFG_EQ2_CUSTOMTRIGGERTRANSLATEDMEMORYIDOFMEMORYINFOTABLE                                DEM_CFG_MEMORYID_INVALID
#define DEM_CFG_EQ2_ENABLECONDITIONGROUPTABLECONTROLDTCSETTINGGROUPIDXOFMEMORYINFOTABLE             0u
#define DEM_CFG_EQ2_ENABLECONDITIONGROUPTABLECONTROLDTCSETTINGGROUPUSEDOFMEMORYINFOTABLE            TRUE
#define DEM_CFG_EQ2_EVENTMEMORYENTRYSTORAGETRIGGEROFMEMORYINFOTABLE                                 DEM_MEMORY_STORAGE_TRIGGER_FAILED
#define DEM_CFG_EQ2_FIRSTENTRYINDEXOFMEMORYINFOTABLE                                                DEM_CFG_ENTRY_PRIMARY_START_INDEX
#define DEM_CFG_EQ2_FIRSTEVENTOFMEMORYINFOTABLE                                                     1u
#define DEM_CFG_EQ2_INDIVIDUALERECSIZEOFMEMORYINFOTABLE                                             0u
#define DEM_CFG_EQ2_INDIVIDUALSRECSIZEOFMEMORYINFOTABLE                                             13u
#define DEM_CFG_EQ2_LASTEVENTOFMEMORYINFOTABLE                                                      62u
#define DEM_CFG_EQ2_MAXNUMBERTIMESERIESSETSOFMEMORYINFOTABLE                                        0u
#define DEM_CFG_EQ2_MAXSIZEOFMEMORYINFOTABLE                                                        10u
#define DEM_CFG_EQ2_SRECNUMTYPEOFMEMORYINFOTABLE                                                    DEM_CFG_MEMORY_FF_RECNUM_CONFIGURED
#define DEM_CFG_EQ2_TIMESERIESFIFOSUPPORTOFMEMORYINFOTABLE                                          FALSE
#define DEM_CFG_EQ2_TIMESERIESSETSRECNUMOFFSETOFMEMORYINFOTABLE                                     0u
#define DEM_CFG_EQ2_TIMESERIESTRANSLATEDMEMORYIDOFMEMORYINFOTABLE                                   DEM_CFG_MEMORYID_INVALID
#define DEM_CFG_EQ2_DTRTABLEIDXOFMIDTABLE                                                           
#define DEM_CFG_EQ2_MIDOFMIDTABLE                                                                   
#define DEM_CFG_EQ2_TIDOFMIDTABLE                                                                   
#define DEM_CFG_EQ2_MARINDEXOFMONITORACTIVITYRATIOTABLE                                             65535u
#define DEM_CFG_EQ2_SMARINDEXOFMONITORACTIVITYRATIOTABLE                                            65535u
#define DEM_CFG_EQ2_EVENTPRECOMPILEDATATABLEIDXOFMULTIEVENTTRIGGERINGSLAVEEVENTSTABLE               
#define DEM_CFG_EQ2_NVBLOCKDATAPTR                                                                  
#define DEM_CFG_EQ2_NVBLOCKDATASIZE                                                                 
#define DEM_CFG_EQ2_NVBLOCKID                                                                       
#define DEM_CFG_EQ2_CALIBRATIONOBDDTCTABLEIDXOFOBDCALIBTABLE                                        
#define DEM_CFG_EQ2_CALIBRATIONOBDDTCTABLEUSEDOFOBDCALIBTABLE                                       
#define DEM_CFG_EQ2_OBDDTC3BYTEOFOBDCALIBTABLE                                                      
#define DEM_CFG_EQ2_OBDDTCOFOBDCALIBTABLE                                                           
#define DEM_CFG_EQ2_READINESSGROUPOFOBDCALIBTABLE                                                   
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEPID2COLLINDENDIDXOFPIDTABLE                                  
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEPID2COLLINDSTARTIDXOFPIDTABLE                                
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEPID2COLLINDUSEDOFPIDTABLE                                    
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEIDXOFSAMPLINGPROFILEDIDINFOTABLE                             
#define DEM_CFG_EQ2_DIDRINGBUFFEROFFSETOFSAMPLINGPROFILEDIDINFOTABLE                                
#define DEM_CFG_EQ2_APPLICATIONIDOFSATELLITEINFO                                                    INVALID_OSAPPLICATION
#define DEM_CFG_EQ2_DEBOUNCELORESTIMEROFSATELLITEINFO                                               
#define DEM_CFG_EQ2_EVENTCOUNTOFSATELLITEINFO                                                       63u
#define DEM_CFG_EQ2_EVENTPRECOMPILEDATATABLEINDENDIDXOFSATELLITEINFO                                63u
#define DEM_CFG_EQ2_EVENTPRECOMPILEDATATABLEINDSTARTIDXOFSATELLITEINFO                              0u
#define DEM_CFG_EQ2_EVENTPRECOMPILEDATATABLEINDUSEDOFSATELLITEINFO                                  TRUE
#define DEM_CFG_EQ2_MAXDEBOUNCEVALUESOFSATELLITEINFO                                                
#define DEM_CFG_EQ2_SATELLITEDATAOFSATELLITEINFO                                                    &Dem_Cfg_SatelliteInfoInvalid_OsApplication.SatelliteData[0]
#define DEM_CFG_EQ2_SATELLITEEXTENDEDDATAOFSATELLITEINFO                                            
#define DEM_CFG_EQ2_SATELLITESTATUSOFSATELLITEINFO                                                  &Dem_Cfg_SatelliteInfoInvalid_OsApplication.SatelliteStatus
#define DEM_CFG_EQ2_TIMEBASEDEVENTTABLEENDIDXOFSATELLITETIMEDEBOUNCEINFO                            
#define DEM_CFG_EQ2_TIMEBASEDEVENTTABLESTARTIDXOFSATELLITETIMEDEBOUNCEINFO                          
#define DEM_CFG_EQ2_TIMEBASEDEVENTTABLEUSEDOFSATELLITETIMEDEBOUNCEINFO                              
#define DEM_CFG_EQ2_J1939EVENTIDSWITHRATIOTABLEENDIDXOFSPNTOEVENTSWITHRATIOTABLE                    
#define DEM_CFG_EQ2_J1939EVENTIDSWITHRATIOTABLESTARTIDXOFSPNTOEVENTSWITHRATIOTABLE                  
#define DEM_CFG_EQ2_SPNOFSPNTOEVENTSWITHRATIOTABLE                                                  
#define DEM_CFG_EQ2_INDEXOFSTORAGECONDITIONGROUPTABLE                                               
#define DEM_CFG_EQ2_STORAGECONDITIONGROUPTABLEIND                                                   
#define DEM_CFG_EQ2_FULFILLEDATINITOFSTORAGECONDITIONINITTABLE                                      
#define DEM_CFG_EQ2_STORAGECONDITIONGROUPTABLEINDENDIDXOFSTORAGECONDITIONTABLE                      
#define DEM_CFG_EQ2_STORAGECONDITIONGROUPTABLEINDSTARTIDXOFSTORAGECONDITIONTABLE                    
#define DEM_CFG_EQ2_STORAGECONDITIONGROUPTABLEINDUSEDOFSTORAGECONDITIONTABLE                        
#define DEM_CFG_EQ2_STARTIDXMIDTABLEOFSUPPORTEDMIDSTABLE                                            
#define DEM_CFG_EQ2_DEBOUNCECONTINUOUSOFTIMEBASEDDEBOUNCETABLE                                      
#define DEM_CFG_EQ2_EVENTDEBOUNCEBEHAVIOROFTIMEBASEDDEBOUNCETABLE                                   
#define DEM_CFG_EQ2_FAILTIMERTHRESHOLDHIGHRESOFTIMEBASEDDEBOUNCETABLE                               
#define DEM_CFG_EQ2_FAILTIMERTHRESHOLDLOWRESOFTIMEBASEDDEBOUNCETABLE                                
#define DEM_CFG_EQ2_ISLOWRESOLUTIONOFTIMEBASEDDEBOUNCETABLE                                         
#define DEM_CFG_EQ2_PASSTIMERTHRESHOLDHIGHRESOFTIMEBASEDDEBOUNCETABLE                               
#define DEM_CFG_EQ2_PASSTIMERTHRESHOLDLOWRESOFTIMEBASEDDEBOUNCETABLE                                
#define DEM_CFG_EQ2_STORAGETIMERTHRESHOLDHIGHRESOFTIMEBASEDDEBOUNCETABLE                            
#define DEM_CFG_EQ2_STORAGETIMERTHRESHOLDLOWRESOFTIMEBASEDDEBOUNCETABLE                             
#define DEM_CFG_EQ2_TIMEBASEDEVENTTABLE                                                             
#define DEM_CFG_EQ2_TIMESERIESENTRYINDEXTONVBLOCKINDEX                                              
#define DEM_CFG_EQ2_BASEENTRYOFTIMESERIESENTRYTABLE                                                 
#define DEM_CFG_EQ2_BUFFERSIZEOFTIMESERIESENTRYTABLE                                                
#define DEM_CFG_EQ2_ENTRYDATAOFTIMESERIESENTRYTABLE                                                 
#define DEM_CFG_EQ2_MAXSNAPSHOTSIZEOFTIMESERIESENTRYTABLE                                           
#define DEM_CFG_EQ2_FIRSTRECORDNUMBEROFTIMESERIESFREEZEFRAMETABLE                                   
#define DEM_CFG_EQ2_LASTRECORDNUMBEROFTIMESERIESFREEZEFRAMETABLE                                    
#define DEM_CFG_EQ2_RECORDTRIGGEROFTIMESERIESFREEZEFRAMETABLE                                       
#define DEM_CFG_EQ2_TIMESERIESSAMPLINGPROFILETABLEIDXOFTIMESERIESFREEZEFRAMETABLE                   
#define DEM_CFG_EQ2_UPDATERECORDOFTIMESERIESFREEZEFRAMETABLE                                        
#define DEM_CFG_EQ2_TIMESERIESFREEZEFRAMETABLEIDXOFTIMESERIESINDIRECTIONTABLE                       
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEIDXOFTIMESERIESSAMPLINGPROFILECALIBTABLE                     
#define DEM_CFG_EQ2_PASTSAMPLESOFTIMESERIESSAMPLINGPROFILECALIBTABLE                                
#define DEM_CFG_EQ2_SAMPLINGPERIODTICSOFTIMESERIESSAMPLINGPROFILECALIBTABLE                         
#define DEM_CFG_EQ2_SAMPLINGPROFILEDIDINFOTABLEENDIDXOFTIMESERIESSAMPLINGPROFILECALIBTABLE          
#define DEM_CFG_EQ2_SAMPLINGPROFILEDIDINFOTABLESTARTIDXOFTIMESERIESSAMPLINGPROFILECALIBTABLE        
#define DEM_CFG_EQ2_SAMPLINGPROFILEDIDINFOTABLEUSEDOFTIMESERIESSAMPLINGPROFILECALIBTABLE            
#define DEM_CFG_EQ2_RINGBUFFERPTROFTIMESERIESSAMPLINGPROFILETABLE                                   
#define DEM_CFG_EQ2_RINGBUFFERSAMPLESOFTIMESERIESSAMPLINGPROFILETABLE                               
#define DEM_CFG_EQ2_SAMPLESIZEOFTIMESERIESSAMPLINGPROFILETABLE                                      
#define DEM_CFG_EQ2_SEQUENTIALDIDIDOFTIMESERIESSAMPLINGPROFILETABLE                                 
#define DEM_CFG_EQ2_TIMESERIESSAMPLINGPROFILECALIBTABLEIDXOFTIMESERIESSAMPLINGPROFILETABLE          
#define DEM_CFG_EQ2_TOTALSAMPLESOFTIMESERIESSAMPLINGPROFILETABLE                                    
#define DEM_CFG_EQ2_MEMORYINFOTABLEIDXOFUSERDEFINEDORIGINTABLE                                      
#define DEM_CFG_EQ2_MEMORYINFOTABLEUSEDOFUSERDEFINEDORIGINTABLE                                     
#define DEM_CFG_EQ2_ADMINDATAOFPCCONFIG                                                             (&(Dem_Cfg_AdminData))
#define DEM_CFG_EQ2_AGINGDATAOFPCCONFIG                                                             (&(Dem_Cfg_AgingData))
#define DEM_CFG_EQ2_CALIBRATIONERRORREGISTEROFPCCONFIG                                              (&(Dem_Cfg_CalibrationErrorRegister))
#define DEM_CFG_EQ2_CALIBRATIONOBDDTCTABLEOFPCCONFIG                                                Dem_Cfg_CalibrationObdDtcTable
#define DEM_CFG_EQ2_CALLBACKCLEAREVENTALLOWEDOFPCCONFIG                                             Dem_Cfg_CallbackClearEventAllowed
#define DEM_CFG_EQ2_CALLBACKDTCSTATUSCHANGEDOFPCCONFIG                                              Dem_Cfg_CallbackDtcStatusChanged
#define DEM_CFG_EQ2_CALLBACKGETFDCOFPCCONFIG                                                        Dem_Cfg_CallbackGetFdc
#define DEM_CFG_EQ2_CALLBACKJ1939DTCSTATUSCHANGEDOFPCCONFIG                                         Dem_Cfg_CallbackJ1939DtcStatusChanged
#define DEM_CFG_EQ2_CLEARDTCTABLEOFPCCONFIG                                                         Dem_Cfg_ClearDTCTable
#define DEM_CFG_EQ2_CLEARDTCNOTIFICATIONFINISHTABLEOFPCCONFIG                                       Dem_Cfg_ClearDtcNotificationFinishTable
#define DEM_CFG_EQ2_CLEARDTCNOTIFICATIONSTARTTABLEOFPCCONFIG                                        Dem_Cfg_ClearDtcNotificationStartTable
#define DEM_CFG_EQ2_CLIENTTABLEOFPCCONFIG                                                           Dem_Cfg_ClientTable
#define DEM_CFG_EQ2_COMMITBUFFEROFPCCONFIG                                                          (&(Dem_Cfg_CommitBuffer))
#define DEM_CFG_EQ2_COMMONDIDLISTOFPCCONFIG                                                         Dem_Cfg_CommonDidList
#define DEM_CFG_EQ2_CONFIGURATIONIDOFPCCONFIG                                                       
#define DEM_CFG_EQ2_COUNTERBASEDDEBOUNCETABLEOFPCCONFIG                                             Dem_Cfg_CounterBasedDebounceTable
#define DEM_CFG_EQ2_CUSTOMTIMESERIESFREEZEFRAMETABLEOFPCCONFIG                                      Dem_Cfg_CustomTimeSeriesFreezeFrameTable
#define DEM_CFG_EQ2_CUSTOMTRIGGERENTRYINDEXTONVBLOCKINDEXOFPCCONFIG                                 Dem_Cfg_CustomTriggerEntryIndexToNvBlockIndex
#define DEM_CFG_EQ2_CUSTOMTRIGGERENTRYPTROFPCCONFIG                                                 Dem_Cfg_CustomTriggerEntryPtr
#define DEM_CFG_EQ2_CYCLECOUNTERDATAOFPCCONFIG                                                      (&(Dem_Cfg_CycleCounterData))
#define DEM_CFG_EQ2_CYCLEIDTABLEOFPCCONFIG                                                          Dem_Cfg_CycleIdTable
#define DEM_CFG_EQ2_DTCSELECTORTABLEOFPCCONFIG                                                      Dem_Cfg_DTCSelectorTable
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEEREC2COLLINDOFPCCONFIG                                       Dem_Cfg_DataCollectionTableErec2CollInd
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEIDXOFDATACOLLECTIONTABLEEDR2COLLINDOFPCCONFIG                Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEIDXOFDATACOLLECTIONTABLEFFM2COLLINDOFPCCONFIG                Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEOFPCCONFIG                                                   Dem_Cfg_DataCollectionTable
#define DEM_CFG_EQ2_DATACOLLECTIONTABLEPID2COLLINDOFPCCONFIG                                        Dem_Cfg_DataCollectionTablePid2CollInd
#define DEM_CFG_EQ2_DATAELEMENTTABLEIDXOFDATAELEMENTTABLECOL2ELMTINDOFPCCONFIG                      Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd
#define DEM_CFG_EQ2_DATAELEMENTTABLEOFPCCONFIG                                                      Dem_Cfg_DataElementTable
#define DEM_CFG_EQ2_DEBOUNCEDATAOFPCCONFIG                                                          (&(Dem_Cfg_DebounceData))
#define DEM_CFG_EQ2_DEBOUNCEINDIRECTIONTABLEOFPCCONFIG                                              Dem_Cfg_DebounceIndirectionTable
#define DEM_CFG_EQ2_DTCCALIBTABLEOFPCCONFIG                                                         Dem_Cfg_DtcCalibTable
#define DEM_CFG_EQ2_DTCGROUPMASKOFPCCONFIG                                                          Dem_Cfg_DtcGroupMask
#define DEM_CFG_EQ2_DTCINVARIANTDATATABLEOFPCCONFIG                                                 Dem_Cfg_DtcInvariantDataTable
#define DEM_CFG_EQ2_DTCTABLEOFPCCONFIG                                                              Dem_Cfg_DtcTable
#define DEM_CFG_EQ2_DTRDATAOFPCCONFIG                                                               (&(Dem_Cfg_DtrData))
#define DEM_CFG_EQ2_DTRSTATUSOFPCCONFIG                                                             Dem_Cfg_DtrStatus
#define DEM_CFG_EQ2_DTRTABLEINDOFPCCONFIG                                                           Dem_Cfg_DtrTableInd
#define DEM_CFG_EQ2_DTRTABLEOFPCCONFIG                                                              Dem_Cfg_DtrTable
#define DEM_CFG_EQ2_ENABLECONDITIONFULFILLEDOFPCCONFIG                                              Dem_Cfg_EnableConditionFulfilled
#define DEM_CFG_EQ2_ENABLECONDITIONGROUPCOUNTEROFPCCONFIG                                           Dem_Cfg_EnableConditionGroupCounter
#define DEM_CFG_EQ2_ENABLECONDITIONGROUPSTATEOFPCCONFIG                                             Dem_Cfg_EnableConditionGroupState
#define DEM_CFG_EQ2_ENABLECONDITIONGROUPTABLEINDOFPCCONFIG                                          Dem_Cfg_EnableConditionGroupTableInd
#define DEM_CFG_EQ2_ENABLECONDITIONGROUPTABLEOFPCCONFIG                                             Dem_Cfg_EnableConditionGroupTable
#define DEM_CFG_EQ2_ENABLECONDITIONINITTABLEOFPCCONFIG                                              Dem_Cfg_EnableConditionInitTable
#define DEM_CFG_EQ2_ENABLECONDITIONTABLEOFPCCONFIG                                                  Dem_Cfg_EnableConditionTable
#define DEM_CFG_EQ2_EVENTAVAILABLEDATAOFPCCONFIG                                                    (&(Dem_Cfg_EventAvailableData))
#define DEM_CFG_EQ2_EVENTAVAILABLEDEFAULTOFPCCONFIG                                                 Dem_Cfg_EventAvailableDefault
#define DEM_CFG_EQ2_EVENTAVAILABLEINVARIANTOFPCCONFIG                                               
#define DEM_CFG_EQ2_EVENTCALIBTABLEOFPCCONFIG                                                       Dem_Cfg_EventCalibTable
#define DEM_CFG_EQ2_EVENTCYCLESTATUSOFPCCONFIG                                                      Dem_Cfg_EventCycleStatus
#define DEM_CFG_EQ2_EVENTDATACHANGEDOFPCCONFIG                                                      Dem_Cfg_EventDataChanged
#define DEM_CFG_EQ2_EVENTDATACOMMITNUMBEROFPCCONFIG                                                 Dem_Cfg_EventDataCommitNumber
#define DEM_CFG_EQ2_EVENTENTRYINDEXTONVBLOCKINDEXOFPCCONFIG                                         Dem_Cfg_EventEntryIndexToNvBlockIndex
#define DEM_CFG_EQ2_EVENTENTRYINFOTABLEOFPCCONFIG                                                   Dem_Cfg_EventEntryInfoTable
#define DEM_CFG_EQ2_EVENTINDICATORDATAOFPCCONFIG                                                    Dem_Cfg_EventIndicatorData
#define DEM_CFG_EQ2_EVENTINTERNALSTATUSOFPCCONFIG                                                   Dem_Cfg_EventInternalStatus
#define DEM_CFG_EQ2_EVENTINVARIANTDATATABLEOFPCCONFIG                                               Dem_Cfg_EventInvariantDataTable
#define DEM_CFG_EQ2_EVENTPRECOMPILEDATATABLEINDOFPCCONFIG                                           Dem_Cfg_EventPrecompileDataTableInd
#define DEM_CFG_EQ2_EVENTPRECOMPILEDATATABLEOFPCCONFIG                                              Dem_Cfg_EventPrecompileDataTable
#define DEM_CFG_EQ2_EVENTSTATUSCHANGEDOFPCCONFIG                                                    Dem_Cfg_EventStatusChanged
#define DEM_CFG_EQ2_EVENTTABLEOFPCCONFIG                                                            Dem_Cfg_EventTable
#define DEM_CFG_EQ2_EVENTTABLE_EREC2EVENTIDINDOFPCCONFIG                                            Dem_Cfg_EventTable_ERec2EventIdInd
#define DEM_CFG_EQ2_EXTENDEDDATARECORDITERATORTABLEOFPCCONFIG                                       Dem_Cfg_ExtendedDataRecordIteratorTable
#define DEM_CFG_EQ2_EXTENDEDDATARECORDTABLEOFPCCONFIG                                               Dem_Cfg_ExtendedDataRecordTable
#define DEM_CFG_EQ2_EXTENDEDDATATABLEOFPCCONFIG                                                     Dem_Cfg_ExtendedDataTable
#define DEM_CFG_EQ2_FILTERINFOTABLEOFPCCONFIG                                                       Dem_Cfg_FilterInfoTable
#define DEM_CFG_EQ2_FREEZEFRAMEDATAOFPCCONFIG                                                       (&(Dem_Cfg_FreezeFrameData))
#define DEM_CFG_EQ2_FREEZEFRAMEITERATORTABLEOFPCCONFIG                                              Dem_Cfg_FreezeFrameIteratorTable
#define DEM_CFG_EQ2_FREEZEFRAMENUMINDIRECTIONTABLEOFPCCONFIG                                        Dem_Cfg_FreezeFrameNumIndirectionTable
#define DEM_CFG_EQ2_FREEZEFRAMENUMTABLEOFPCCONFIG                                                   Dem_Cfg_FreezeFrameNumTable
#define DEM_CFG_EQ2_FREEZEFRAMETABLEOFPCCONFIG                                                      Dem_Cfg_FreezeFrameTable
#define DEM_CFG_EQ2_GENERALJ1939TABLEOFPCCONFIG                                                     Dem_Cfg_GeneralJ1939Table
#define DEM_CFG_EQ2_GENERALOBDINPUTOFPCCONFIG                                                       Dem_Cfg_GeneralObdInput
#define DEM_CFG_EQ2_GLOBALSNAPSHOTRECORDOFPCCONFIG                                                  Dem_Cfg_GlobalSnapshotRecord
#define DEM_CFG_EQ2_INDICATORATTRIBUTETABLEOFPCCONFIG                                               Dem_Cfg_IndicatorAttributeTable
#define DEM_CFG_EQ2_INDICATORDATAOFPCCONFIG                                                         (&(Dem_Cfg_IndicatorData))
#define DEM_CFG_EQ2_INDICATOREVENTCOUNTERSOFPCCONFIG                                                Dem_Cfg_IndicatorEventCounters
#define DEM_CFG_EQ2_INITMONLISTFORFUNCOFPCCONFIG                                                    Dem_Cfg_InitMonListForFunc
#define DEM_CFG_EQ2_INITMONITORFOREVENTOFPCCONFIG                                                   Dem_Cfg_InitMonitorForEvent
#define DEM_CFG_EQ2_INITMONITORSFORFUNCOFPCCONFIG                                                   Dem_Cfg_InitMonitorsForFunc
#define DEM_CFG_EQ2_J1939EVENTIDSWITHRATIOTABLEOFPCCONFIG                                           Dem_Cfg_J1939EventIdsWithRatioTable
#define DEM_CFG_EQ2_J1939NODEIDINDOFPCCONFIG                                                        Dem_Cfg_J1939NodeIdInd
#define DEM_CFG_EQ2_J1939NODEIDOFPCCONFIG                                                           Dem_Cfg_J1939NodeId
#define DEM_CFG_EQ2_J1939NODEINDICATORAVAILABILITYOFPCCONFIG                                        Dem_Cfg_J1939NodeIndicatorAvailability
#define DEM_CFG_EQ2_J1939SPNSINEXPANDEDFREEZEFRAMETABLEOFPCCONFIG                                   Dem_Cfg_J1939SpnsInExpandedFreezeFrameTable
#define DEM_CFG_EQ2_MEMORYCURRENTCOUNTOFPCCONFIG                                                    Dem_Cfg_MemoryCurrentCount
#define DEM_CFG_EQ2_MEMORYINFOTABLEOFPCCONFIG                                                       Dem_Cfg_MemoryInfoTable
#define DEM_CFG_EQ2_MEMORYSTATUSOFPCCONFIG                                                          Dem_Cfg_MemoryStatus
#define DEM_CFG_EQ2_MIDTABLEOFPCCONFIG                                                              Dem_Cfg_MidTable
#define DEM_CFG_EQ2_MIRRORDATAOFPCCONFIG                                                            (&(Dem_Cfg_MirrorData))
#define DEM_CFG_EQ2_MONITORACTIVITYRATIOTABLEOFPCCONFIG                                             Dem_Cfg_MonitorActivityRatioTable
#define DEM_CFG_EQ2_MULTIEVENTTRIGGERINGSLAVEEVENTSTABLEOFPCCONFIG                                  Dem_Cfg_MultiEventTriggeringSlaveEventsTable
#define DEM_CFG_EQ2_NVBLOCKDATAPTROFPCCONFIG                                                        Dem_Cfg_NvBlockDataPtr
#define DEM_CFG_EQ2_NVBLOCKDATASIZEOFPCCONFIG                                                       Dem_Cfg_NvBlockDataSize
#define DEM_CFG_EQ2_NVBLOCKIDOFPCCONFIG                                                             Dem_Cfg_NvBlockId
#define DEM_CFG_EQ2_OBDCALIBTABLEOFPCCONFIG                                                         Dem_Cfg_ObdCalibTable
#define DEM_CFG_EQ2_OBDIUMPRDATAOFPCCONFIG                                                          (&(Dem_Cfg_ObdIumprData))
#define DEM_CFG_EQ2_OBDIUMPRUPDATEPENDINGOFPCCONFIG                                                 Dem_Cfg_ObdIumprUpdatePending
#define DEM_CFG_EQ2_PERMANENTDATAOFPCCONFIG                                                         (&(Dem_Cfg_PermanentData))
#define DEM_CFG_EQ2_PIDTABLEOFPCCONFIG                                                              Dem_Cfg_PidTable
#define DEM_CFG_EQ2_PRESTORAGEINDEXOFPCCONFIG                                                       Dem_Cfg_PrestorageIndex
#define DEM_CFG_EQ2_PRESTORAGEOFPCCONFIG                                                            (&(Dem_Cfg_Prestorage))
#define DEM_CFG_EQ2_PRIMARYCHRONOLOGYOFPCCONFIG                                                     Dem_Cfg_PrimaryChronology
#define DEM_CFG_EQ2_PRIMARYENTRY_0OFPCCONFIG                                                        (&(Dem_Cfg_PrimaryEntry_0))
#define DEM_CFG_EQ2_PRIMARYENTRY_1OFPCCONFIG                                                        (&(Dem_Cfg_PrimaryEntry_1))
#define DEM_CFG_EQ2_PRIMARYENTRY_2OFPCCONFIG                                                        (&(Dem_Cfg_PrimaryEntry_2))
#define DEM_CFG_EQ2_PRIMARYENTRY_3OFPCCONFIG                                                        (&(Dem_Cfg_PrimaryEntry_3))
#define DEM_CFG_EQ2_PRIMARYENTRY_4OFPCCONFIG                                                        (&(Dem_Cfg_PrimaryEntry_4))
#define DEM_CFG_EQ2_PRIMARYENTRY_5OFPCCONFIG                                                        (&(Dem_Cfg_PrimaryEntry_5))
#define DEM_CFG_EQ2_PRIMARYENTRY_6OFPCCONFIG                                                        (&(Dem_Cfg_PrimaryEntry_6))
#define DEM_CFG_EQ2_PRIMARYENTRY_7OFPCCONFIG                                                        (&(Dem_Cfg_PrimaryEntry_7))
#define DEM_CFG_EQ2_PRIMARYENTRY_8OFPCCONFIG                                                        (&(Dem_Cfg_PrimaryEntry_8))
#define DEM_CFG_EQ2_PRIMARYENTRY_9OFPCCONFIG                                                        (&(Dem_Cfg_PrimaryEntry_9))
#define DEM_CFG_EQ2_PRIMARYEVENTENTRYINITOFPCCONFIG                                                 (&(Dem_Cfg_PrimaryEventEntryInit))
#define DEM_CFG_EQ2_RATIOIDTABLEOFPCCONFIG                                                          Dem_Cfg_RatioIdTable
#define DEM_CFG_EQ2_READOUTBUFFEROFPCCONFIG                                                         Dem_Cfg_ReadoutBuffer
#define DEM_CFG_EQ2_REPORTEDEVENTSOFFILTEROFPCCONFIG                                                Dem_Cfg_ReportedEventsOfFilter
#define DEM_CFG_EQ2_RINGBUFFEROFPCCONFIG                                                            (&(Dem_Cfg_RingBuffer))
#define DEM_CFG_EQ2_SAMPLINGPROFILEDIDINFOTABLEOFPCCONFIG                                           Dem_Cfg_SamplingProfileDidInfoTable
#define DEM_CFG_EQ2_SATELLITEINFOINVALID_OSAPPLICATIONOFPCCONFIG                                    (&(Dem_Cfg_SatelliteInfoInvalid_OsApplication))
#define DEM_CFG_EQ2_SATELLITEINFOOFPCCONFIG                                                         Dem_Cfg_SatelliteInfo
#define DEM_CFG_EQ2_SATELLITETIMEDEBOUNCEINFOOFPCCONFIG                                             Dem_Cfg_SatelliteTimeDebounceInfo
#define DEM_CFG_EQ2_SPNTOEVENTSWITHRATIOTABLEOFPCCONFIG                                             Dem_Cfg_SpnToEventsWithRatioTable
#define DEM_CFG_EQ2_STARTIDX500MIDENRATIOTABLEOFPCCONFIG                                            Dem_Cfg_StartIdx500miDenRatioTable
#define DEM_CFG_EQ2_STATUSDATAOFPCCONFIG                                                            (&(Dem_Cfg_StatusData))
#define DEM_CFG_EQ2_STORAGECONDITIONFULFILLEDOFPCCONFIG                                             Dem_Cfg_StorageConditionFulfilled
#define DEM_CFG_EQ2_STORAGECONDITIONGROUPCOUNTEROFPCCONFIG                                          Dem_Cfg_StorageConditionGroupCounter
#define DEM_CFG_EQ2_STORAGECONDITIONGROUPTABLEINDOFPCCONFIG                                         Dem_Cfg_StorageConditionGroupTableInd
#define DEM_CFG_EQ2_STORAGECONDITIONGROUPTABLEOFPCCONFIG                                            Dem_Cfg_StorageConditionGroupTable
#define DEM_CFG_EQ2_STORAGECONDITIONINITTABLEOFPCCONFIG                                             Dem_Cfg_StorageConditionInitTable
#define DEM_CFG_EQ2_STORAGECONDITIONTABLEOFPCCONFIG                                                 Dem_Cfg_StorageConditionTable
#define DEM_CFG_EQ2_SUPPORTEDMIDSTABLEOFPCCONFIG                                                    Dem_Cfg_SupportedMidsTable
#define DEM_CFG_EQ2_TIMEBASEDDEBOUNCETABLEOFPCCONFIG                                                Dem_Cfg_TimeBasedDebounceTable
#define DEM_CFG_EQ2_TIMEBASEDEVENTTABLEOFPCCONFIG                                                   Dem_Cfg_TimeBasedEventTable
#define DEM_CFG_EQ2_TIMESERIESENTRYINDEXTONVBLOCKINDEXOFPCCONFIG                                    Dem_Cfg_TimeSeriesEntryIndexToNvBlockIndex
#define DEM_CFG_EQ2_TIMESERIESENTRYTABLEOFPCCONFIG                                                  Dem_Cfg_TimeSeriesEntryTable
#define DEM_CFG_EQ2_TIMESERIESFREEZEFRAMETABLEOFPCCONFIG                                            Dem_Cfg_TimeSeriesFreezeFrameTable
#define DEM_CFG_EQ2_TIMESERIESINDIRECTIONTABLEOFPCCONFIG                                            Dem_Cfg_TimeSeriesIndirectionTable
#define DEM_CFG_EQ2_TIMESERIESSAMPLINGPROFILECALIBTABLEOFPCCONFIG                                   Dem_Cfg_TimeSeriesSamplingProfileCalibTable
#define DEM_CFG_EQ2_TIMESERIESSAMPLINGPROFILETABLEOFPCCONFIG                                        Dem_Cfg_TimeSeriesSamplingProfileTable
#define DEM_CFG_EQ2_USERDEFINEDORIGINTABLEOFPCCONFIG                                                Dem_Cfg_UserDefinedOriginTable
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCSymbolicNonDereferenciateablePointers  Dem_Cfg Symbolic Non Dereferenciateable Pointers (PRE_COMPILE)
  \brief  Symbolic non dereferenciateable pointers to be used if all values are optimized to a defined and to return a correct value for has macros in variants.
  \{
*/ 
#define Dem_Cfg_AgingData                                                                           ((Dem_Cfg_AgingDataPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_CalibrationObdDtcTable                                                              ((Dem_Cfg_CalibrationObdDtcTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_CallbackClearEventAllowed                                                           ((Dem_Cfg_CallbackClearEventAllowedPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_CallbackGetFdc                                                                      ((Dem_Cfg_CallbackGetFdcPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_CallbackJ1939DtcStatusChanged                                                       ((Dem_Cfg_CallbackJ1939DtcStatusChangedPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_ClearDtcNotificationFinishTable                                                     ((Dem_Cfg_ClearDtcNotificationFinishTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_ClearDtcNotificationStartTable                                                      ((Dem_Cfg_ClearDtcNotificationStartTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_ClientTable                                                                         ((Dem_Cfg_ClientTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_CommonDidList                                                                       ((Dem_Cfg_CommonDidListPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_CounterBasedDebounceTable                                                           ((Dem_Cfg_CounterBasedDebounceTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_CustomTimeSeriesFreezeFrameTable                                                    ((Dem_Cfg_CustomTimeSeriesFreezeFrameTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_CustomTriggerEntryIndexToNvBlockIndex                                               ((Dem_Cfg_CustomTriggerEntryIndexToNvBlockIndexPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_CustomTriggerEntryPtr                                                               ((Dem_Cfg_CustomTriggerEntryPtrPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_CycleCounterData                                                                    ((Dem_Cfg_CycleCounterDataPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_CycleIdTable                                                                        ((Dem_Cfg_CycleIdTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_DataCollectionTableErec2CollInd                                                     ((Dem_Cfg_DataCollectionTableErec2CollIndPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_DataCollectionTablePid2CollInd                                                      ((Dem_Cfg_DataCollectionTablePid2CollIndPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_DebounceData                                                                        ((Dem_Cfg_DebounceDataPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_DtcGroupMask                                                                        ((Dem_Cfg_DtcGroupMaskPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_DtrData                                                                             ((Dem_Cfg_DtrDataPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_DtrStatus                                                                           ((Dem_Cfg_DtrStatusPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_DtrTable                                                                            ((Dem_Cfg_DtrTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_DtrTableInd                                                                         ((Dem_Cfg_DtrTableIndPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_EnableConditionGroupTable                                                           ((Dem_Cfg_EnableConditionGroupTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_EnableConditionGroupTableInd                                                        ((Dem_Cfg_EnableConditionGroupTableIndPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_EnableConditionInitTable                                                            ((Dem_Cfg_EnableConditionInitTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_EnableConditionTable                                                                ((Dem_Cfg_EnableConditionTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_EventAvailableData                                                                  ((Dem_Cfg_EventAvailableDataPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_EventAvailableDefault                                                               ((Dem_Cfg_EventAvailableDefaultPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_EventCalibTable                                                                     ((Dem_Cfg_EventCalibTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_EventCycleStatus                                                                    ((Dem_Cfg_EventCycleStatusPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_EventDataChanged                                                                    ((Dem_Cfg_EventDataChangedPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_EventIndicatorData                                                                  ((Dem_Cfg_EventIndicatorDataPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_EventPrecompileDataTableInd                                                         ((Dem_Cfg_EventPrecompileDataTableIndPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_EventTable                                                                          ((Dem_Cfg_EventTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_EventTable_ERec2EventIdInd                                                          ((Dem_Cfg_EventTable_ERec2EventIdIndPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_ExtendedDataRecordTable                                                             ((Dem_Cfg_ExtendedDataRecordTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_FreezeFrameData                                                                     ((Dem_Cfg_FreezeFrameDataPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_FreezeFrameNumTable                                                                 ((Dem_Cfg_FreezeFrameNumTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_GeneralJ1939Table                                                                   ((Dem_Cfg_GeneralJ1939TablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_GeneralObdInput                                                                     ((Dem_Cfg_GeneralObdInputPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_GlobalSnapshotRecord                                                                ((Dem_Cfg_GlobalSnapshotRecordPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_IndicatorAttributeTable                                                             ((Dem_Cfg_IndicatorAttributeTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_IndicatorData                                                                       ((Dem_Cfg_IndicatorDataPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_IndicatorEventCounters                                                              ((Dem_Cfg_IndicatorEventCountersPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_InitMonListForFunc                                                                  ((Dem_Cfg_InitMonListForFuncPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_InitMonitorForEvent                                                                 ((Dem_Cfg_InitMonitorForEventPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_InitMonitorsForFunc                                                                 ((Dem_Cfg_InitMonitorsForFuncPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_J1939EventIdsWithRatioTable                                                         ((Dem_Cfg_J1939EventIdsWithRatioTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_J1939NodeIndicatorAvailability                                                      ((Dem_Cfg_J1939NodeIndicatorAvailabilityPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_J1939SpnsInExpandedFreezeFrameTable                                                 ((Dem_Cfg_J1939SpnsInExpandedFreezeFrameTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_MemoryInfoTable                                                                     ((Dem_Cfg_MemoryInfoTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_MidTable                                                                            ((Dem_Cfg_MidTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_MirrorData                                                                          ((Dem_Cfg_MirrorDataPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_MonitorActivityRatioTable                                                           ((Dem_Cfg_MonitorActivityRatioTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_MultiEventTriggeringSlaveEventsTable                                                ((Dem_Cfg_MultiEventTriggeringSlaveEventsTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_ObdCalibTable                                                                       ((Dem_Cfg_ObdCalibTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_ObdIumprData                                                                        ((Dem_Cfg_ObdIumprDataPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_ObdIumprUpdatePending                                                               ((Dem_Cfg_ObdIumprUpdatePendingPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_PermanentData                                                                       ((Dem_Cfg_PermanentDataPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_PidTable                                                                            ((Dem_Cfg_PidTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_Prestorage                                                                          ((Dem_Cfg_PrestoragePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_PrestorageIndex                                                                     ((Dem_Cfg_PrestorageIndexPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_RatioIdTable                                                                        ((Dem_Cfg_RatioIdTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_RingBuffer                                                                          ((Dem_Cfg_RingBufferPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_SamplingProfileDidInfoTable                                                         ((Dem_Cfg_SamplingProfileDidInfoTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_SatelliteInfo                                                                       ((Dem_Cfg_SatelliteInfoPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_SatelliteTimeDebounceInfo                                                           ((Dem_Cfg_SatelliteTimeDebounceInfoPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_SpnToEventsWithRatioTable                                                           ((Dem_Cfg_SpnToEventsWithRatioTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_StartIdx500miDenRatioTable                                                          ((Dem_Cfg_StartIdx500miDenRatioTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_StorageConditionFulfilled                                                           ((Dem_Cfg_StorageConditionFulfilledPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_StorageConditionGroupCounter                                                        ((Dem_Cfg_StorageConditionGroupCounterPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_StorageConditionGroupTable                                                          ((Dem_Cfg_StorageConditionGroupTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_StorageConditionGroupTableInd                                                       ((Dem_Cfg_StorageConditionGroupTableIndPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_StorageConditionInitTable                                                           ((Dem_Cfg_StorageConditionInitTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_StorageConditionTable                                                               ((Dem_Cfg_StorageConditionTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_SupportedMidsTable                                                                  ((Dem_Cfg_SupportedMidsTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_TimeBasedDebounceTable                                                              ((Dem_Cfg_TimeBasedDebounceTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_TimeBasedEventTable                                                                 ((Dem_Cfg_TimeBasedEventTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_TimeSeriesEntryIndexToNvBlockIndex                                                  ((Dem_Cfg_TimeSeriesEntryIndexToNvBlockIndexPtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_TimeSeriesEntryTable                                                                ((Dem_Cfg_TimeSeriesEntryTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_TimeSeriesFreezeFrameTable                                                          ((Dem_Cfg_TimeSeriesFreezeFrameTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_TimeSeriesIndirectionTable                                                          ((Dem_Cfg_TimeSeriesIndirectionTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_TimeSeriesSamplingProfileCalibTable                                                 ((Dem_Cfg_TimeSeriesSamplingProfileCalibTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_TimeSeriesSamplingProfileTable                                                      ((Dem_Cfg_TimeSeriesSamplingProfileTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
#define Dem_Cfg_UserDefinedOriginTable                                                              ((Dem_Cfg_UserDefinedOriginTablePtrType)(&(Dem_PCConfig)))  /**< Non derefenciateable valid pointer */
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCSymbolicInitializationPointers  Dem_Cfg Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Dem_Config_RDR_01_Ptr                                                                       &(Dem_PCConfig.Config_RDR_01)  /**< symbolic identifier which shall be used to initialize 'Dem' */
#define Dem_Config_RDR_02_Ptr                                                                       &(Dem_PCConfig.Config_RDR_02)  /**< symbolic identifier which shall be used to initialize 'Dem' */
#define Dem_Config_RDR_03_Ptr                                                                       &(Dem_PCConfig.Config_RDR_03)  /**< symbolic identifier which shall be used to initialize 'Dem' */
#define Dem_Config_RDR_04_Ptr                                                                       &(Dem_PCConfig.Config_RDR_04)  /**< symbolic identifier which shall be used to initialize 'Dem' */
#define Dem_Config_RDR_05_Ptr                                                                       &(Dem_PCConfig.Config_RDR_05)  /**< symbolic identifier which shall be used to initialize 'Dem' */
#define Dem_Config_RDR_06_Ptr                                                                       &(Dem_PCConfig.Config_RDR_06)  /**< symbolic identifier which shall be used to initialize 'Dem' */
#define Dem_Config_RDR_07_Ptr                                                                       &(Dem_PCConfig.Config_RDR_07)  /**< symbolic identifier which shall be used to initialize 'Dem' */
#define Dem_Config_RDR_08_Ptr                                                                       &(Dem_PCConfig.Config_RDR_08)  /**< symbolic identifier which shall be used to initialize 'Dem' */
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCInitializationSymbols  Dem_Cfg Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Dem_Config_RDR_01                                                                           Dem_PCConfig.Config_RDR_01  /**< symbolic identifier which could be used to initialize 'Dem */
#define Dem_Config_RDR_02                                                                           Dem_PCConfig.Config_RDR_02  /**< symbolic identifier which could be used to initialize 'Dem */
#define Dem_Config_RDR_03                                                                           Dem_PCConfig.Config_RDR_03  /**< symbolic identifier which could be used to initialize 'Dem */
#define Dem_Config_RDR_04                                                                           Dem_PCConfig.Config_RDR_04  /**< symbolic identifier which could be used to initialize 'Dem */
#define Dem_Config_RDR_05                                                                           Dem_PCConfig.Config_RDR_05  /**< symbolic identifier which could be used to initialize 'Dem */
#define Dem_Config_RDR_06                                                                           Dem_PCConfig.Config_RDR_06  /**< symbolic identifier which could be used to initialize 'Dem */
#define Dem_Config_RDR_07                                                                           Dem_PCConfig.Config_RDR_07  /**< symbolic identifier which could be used to initialize 'Dem */
#define Dem_Config_RDR_08                                                                           Dem_PCConfig.Config_RDR_08  /**< symbolic identifier which could be used to initialize 'Dem */
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCGeneral  Dem_Cfg General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define DEM_CFG_CHECK_INIT_POINTER                                                                  STD_ON  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define DEM_CFG_FINAL_MAGIC_NUMBER                                                                  0x361Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Dem */
#define DEM_CFG_INDIVIDUAL_POSTBUILD                                                                STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Dem' is not configured to be postbuild capable. */
#define DEM_CFG_INIT_DATA                                                                           DEM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define DEM_CFG_INIT_DATA_HASH_CODE                                                                 951837509  /**< the precompile constant to validate the initialization structure at initialization time of Dem with a hashcode. The seed value is '0x361Eu' */
#define DEM_CFG_USE_ECUM_BSW_ERROR_HOOK                                                             STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define DEM_CFG_USE_INIT_POINTER                                                                    STD_ON  /**< STD_ON if the init pointer Dem shall be used. */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Dem_CfgLTDataSwitches  Dem_Cfg Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define DEM_LTCONFIG                                                                                STD_OFF  /**< the module configuration is VARIANT_PRE_COMPILE. */
/** 
  \}
*/ 


/*********************************************************************************************************************/




 /*  Aging- and OperationCycle IDs [symbolic name value]  */ 
#define DemConf_DemOperationCycle_Power_On_Off                        0u 

 /*  Global, cycle related values  */ 
#define DEM_CFG_GLOBAL_CYCLE_COUNT                                    1u                                                                /* Total number of configured (operation and aging) cycles. */ 
#define DEM_CFG_GLOBAL_OBD_DRIVING_CYCLE_ID                           /* No DemOperationCycleType 'DEM_OPCYC_OBD_DCY' configured. */    /* Cycle ID of the DemOperationCycleType 'DEM_OPCYC_OBD_DCY'. */ 
#define DEM_CFG_GLOBAL_WARMUP_CYCLE_ID                                /* No DemOperationCycleType 'DEM_OPCYC_WARMUP' configured. */     /* Cycle ID of the DemOperationCycleType 'DEM_OPCYC_WARMUP'. */ 

 /*  Dem general defines  */ 
#define DEM_CFG_CLEAR_EVENTS_WITHOUT_DTC_EVENT_MEMORY_ID              1u                                 /* The event memory id referenced to clear events without DTC - /Dem/DemGeneral/DemClearEventsWithoutDTCEventMemoryRef */ 
#define DEM_CFG_GLOBALCBKCONTROLDTCSETTING_FUNC                       NULL_PTR                           /* DEM_CFG_NOTIFY_CONTROL_DTC_SETTING==STD_OFF */ 
#define DEM_CFG_GLOBALCBKDATA_FUNC                                    NULL_PTR                           /* No ClientServerInterface GeneralCallbackEventDataChanged, DEM_CFG_NOTIFY_GENERAL_DATA==STD_OFF */ 
#define DEM_CFG_GLOBALCBKSTATUS_FUNC                                  NULL_PTR                           /* No ClientServerInterface GeneralCallbackEventUdsStatusChanged, DEM_CFG_NOTIFY_GENERAL_STATUS==STD_OFF */ 
#define DEM_CFG_GLOBALTRIGGERONMONITORSTATUS_FUNC                     NULL_PTR                           /* No or empty /Dem/DemGeneral/DemGeneralCallbackMonitorStatusChangedFnc parameter, DEM_CFG_NOTIFY_GENERAL_MONITORSTATUS_CHANGED==STD_OFF */ 
#define DEM_CFG_GLOBAL_CLEAR_DTC_RUNTIME_LIMIT                        63u                                /* not configured, here substituted by number of events (incl. event #0) */ 
#define DEM_CFG_GLOBAL_CUSTOM_TRIGGERED_SNAPSHOTS_SIZE                0u                                 /* The sum of DemMaxNumberCustomTriggeredSnapshots over all DemPrimaryMemory and all DemUserDefinedMemory containers */ 
#define DEM_CFG_GLOBAL_DEBOUNCE_STORAGE_EVENT_COUNT                   0u                                 /* Number of events with .../DemEventClass/DemDebounceAlgorithClass/DemDebounceCounterBased/DemDebounceCounterStorage == TRUE */ 
#define DEM_CFG_GLOBAL_DTC_FORMAT                                     DEM_DTC_TRANSLATION_SAEJ1939_73    /* /Dem/DemGeneral/DemTypeOfDTCSupported */ 
#define DEM_CFG_GLOBAL_FREEZEFRAME_SIZE                               0u                                 /* /Dem/DemGeneral/DemMaxNumberEventEntryOBDFreezeFrame max. value in all variants */ 
#define DEM_CFG_GLOBAL_J1939_READING_DTC_RUNTIME_LIMIT                63u                                /* /Dem/DemGeneral/DemGeneralJ1939/DemJ1939ReadingDTCRuntimeLimit not configured, substituted by number of events (incl. event #0) */ 
#define DEM_CFG_GLOBAL_MIRROR_SIZE                                    0u                                 /* /Dem/DemGeneral/DemMaxNumberEventEntryMirror */ 
#define DEM_CFG_GLOBAL_NV_STORAGE_LIMIT                               0u                                 /* /Dem/DemGeneral/DemImmediateNvStorageLimit, 0: no limit configured */ 
#define DEM_CFG_GLOBAL_PERMANENT_SIZE                                 0u                                 /* /Dem/DemGeneral/DemMaxNumberEventEntryPermanent */ 
#define DEM_CFG_GLOBAL_PRESTORED_FF_SIZE                              0u                                 /* /Dem/DemGeneral/DemMaxNumberPrestoredFF, see Dem_Cfg_GlobalPrestorageSize() */ 
#define DEM_CFG_GLOBAL_PRIMARY_SIZE                                   10u                                /* /Dem/DemGeneral/DemEventMemorySet/DemPrimaryMemory/DemMaxNumberEventEntryPrimary */ 
#define DEM_CFG_GLOBAL_TASK_MS                                        10u                                /* /Dem/DemGeneral/DemTaskTime in [ms]. See also macro DEM_CFG_TASK_TIME for exact float value */ 
#define DEM_CFG_GLOBAL_TIMESERIES_SNAPSHOTS_SIZE                      0u                                 /* The sum of DemMaxNumberTimeSeriesSnapshots over all DemPrimaryMemory and all DemUserDefinedMemory containers */ 
#define DEM_CFG_J1939_NODE_INVALID                                    1u                                 /* Invalid NmNode index (Dem internal) */ 
#define DEM_CFG_MAX_16BIT_ARRAY_SIZE                                  1u                                 /* Number of array elements in the largest data element with UINT16_N or SINT16_N, minimum size is 1 to prevent zero-length arrays. */ 
#define DEM_CFG_MAX_32BIT_ARRAY_SIZE                                  1u                                 /* Number of array elements in the largest data element with type UINT32_N, SINT32_N or FLOAT_N, minimum size is 1 to prevent zero-length arrays. */ 
#define DEM_CFG_MAX_NUMBER_PERMANENT_CHRONOLOGY                       1u                                 /* /Dem/DemGeneral/DemGeneralOBD/DemOBDPermanentChronologyMaxNumberEvents */ 
#define DEM_CFG_MAX_NUM_DID_PER_COMMON_DID_LIST                       0u                                 /* /Dem/DemGeneral/DemGeneralCalibration/DemCalibrationMaxDIDperCommonDidList: if /Dem/DemGeneral/DemGeneralCalibration/DemCalibrationASRSnapshotRecordsSupport==TRUE, /Dem/DemGeneral/DemCommonDidListFreezeFrame container exists with a reference to Common Did List,0: else */ 
#define DEM_CFG_MAX_NUM_DID_PER_FREEZE_FRAME_RECORD                   0u                                 /* /Dem/DemGeneral/DemGeneralCalibration/DemCalibrationMaxDIDperFF: if /Dem/DemGeneral/DemCalibrationSupport==TRUE, /Dem/DemGeneral/DemGeneralCalibration container exists, 0: else */ 
#define DEM_CFG_MAX_NUM_ENABLE_CONDITIONS_PER_GROUP                   0u                                 /* /Dem/DemGeneral/DemGeneralCalibration/DemCalibrationMaxEnableConditionPerGroup: use value of /Dem/DemGeneral/DemGeneralCalibration/DemCalibrationMaxEnableConditionPerGroup if /Dem/DemGeneral/DemCalibrationSupport==TRUE and /Dem/DemGeneral/DemGeneralCalibration container exists, 0: else */ 
#define DEM_CFG_MAX_NUM_STORAGE_CONDITIONS_PER_GROUP                  0u                                 /* /Dem/DemGeneral/DemGeneralCalibration/DemCalibrationMaxStorageConditionPerGroup: use value of /Dem/DemGeneral/DemGeneralCalibration/DemCalibrationMaxStorageConditionPerGroup if /Dem/DemGeneral/DemCalibrationSupport==TRUE and /Dem/DemGeneral/DemGeneralCalibration container exists, 0: else */ 
#define DEM_CFG_NUMBER_GLOBAL_FREEZE_FRAME_RECORDS                    0u                                 /* Number of global freeze frame records */ 
#define DEM_CFG_OEMCBKGETCURRENTODOMETER_FUNC                         NULL_PTR                           /* unused */ 
#define DEM_CFG_OEMCBKGETEXTERNALTESTERSTATUS_FUNC                    NULL_PTR                           /* unused */ 
#define DEM_CFG_RATIOINDEX_INVALID                                    255u                               /* Internal use: no OBD RatioId configured */ 
#define DEM_CFG_SIZEOF_MAX_DATA_VALUE_TYPE                            7u                                 /* sizeof(Dem_MaxDataValueType) - typedef is generated by the RTE into Rte_Type.h */ 
#define DEM_CFG_TASK_TIME                                             10.0                               /* /Dem/DemGeneral/DemTaskTime in [ms]. See also macro DEM_CFG_GLOBAL_TASK_MS for integer value. */ 
#define DEM_G_GLOBAL_PRESTORED_EVENT_COUNT                            0u                                 /* Number of events with DemEventClass/DemFFPrestorageSupported == TRUE, see Dem_Cfg_GlobalPrestorageEventCount() */ 
#define DEM_G_MAX_NUMBER_J1939_NODES                                  2u                                 /* Number of different J1939Nm node targets (=J1939NmNode) referenced via /Dem/DemConfigSet/DemJ1939NodeAddress/DemJ1939NmNodeRef - plus 1 when there are DTCs without a DemJ1939DTC_NodeAddressRef value. */ 
#define DEM_G_NUMBER_OF_EVENTS                                        63u                                /* Total number of DemEventParameter, incl. event #0 */ 
#define DEM_G_NUMBER_OF_RATIO_IDS                                     0u                                 /* Number of OBD RatioIds (incl. ID 0, internally used for global values) */ 


 /*  Indicator global definitions  */ 
#define DEM_CFG_GLOBAL_INDICATOR_COUNT                                0u           /* Total number of configured Indicators */ 


 /*  Support for optimized routines of Vector DCM - Extended Data records  */ 
#define DEM_DCM_NUM_EXTDATA_RECID                                     2u 
#define DEM_DCM_LST_EXTDATA_RECID                                     0x01u, 0x02u 


 /*  Event IDs [symbolic name value] - sorted by name.
     See Dem_Cfg_EventTable[] for this list sorted by Ids.  */ 
#define DemConf_DemEventParameter_ADAS_FN_STS_message_BSIS_FN_Switch_STS_Invalid_Serial_Data_Received     1u 
#define DemConf_DemEventParameter_ADAS_FN_STS_message_MOIS_FN_Switch_STS_Invalid_Serial_Data_Received     2u 
#define DemConf_DemEventParameter_AT_AMT_ECU_ETC2_03_message_Missing_Message                              3u 
#define DemConf_DemEventParameter_AT_AMT_ETC2_erratic_communication_Erratic                               4u 
#define DemConf_DemEventParameter_AT_AMT_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received      5u 
#define DemConf_DemEventParameter_Application_Interface_Lookup_Performance_or_Incorrect_Operation         6u 
#define DemConf_DemEventParameter_CCVS1_message_Vehicle_Speed_Invalid_Serial_Data_Received                7u 
#define DemConf_DemEventParameter_CLS_TX_16_message_Transmission_Type_info_Invalid_Serial_Data_Received   8u 
#define DemConf_DemEventParameter_Cluster_ECU_ADAS_FN_STS_erratic_communication_Erratic                   9u 
#define DemConf_DemEventParameter_Cluster_ECU_ADAS_FN_STS_message_Missing_Message                         10u 
#define DemConf_DemEventParameter_Cluster_ECU_CLS_Tx_16_erratic_communication_Erratic                     13u 
#define DemConf_DemEventParameter_Cluster_ECU_CLS_Tx_16_message_Missing_Message                           14u 
#define DemConf_DemEventParameter_Cluster_ECU_CLS_Tx_4_erratic_communication_Erratic                      11u 
#define DemConf_DemEventParameter_Cluster_ECU_CLS_Tx_4_message_Missing_Message                            12u 
#define DemConf_DemEventParameter_Cluster_ECU_OEL_erratic_communication_Erratic                           15u 
#define DemConf_DemEventParameter_Cluster_ECU_OEL_message_Missing_Message                                 16u 
#define DemConf_DemEventParameter_Cluster_ECU_TD_erratic_communication_Erratic                            17u 
#define DemConf_DemEventParameter_Cluster_ECU_TD_message_Missing_Message                                  18u 
#define DemConf_DemEventParameter_DemEventParameter                                                       62u 
#define DemConf_DemEventParameter_ECU_NVM_Corruption_Program_memory_Failure                               19u 
#define DemConf_DemEventParameter_EMS_ECU_CCVS1_erratic_communication_Erractic                            20u 
#define DemConf_DemEventParameter_EMS_ECU_CCVS1_message_Missing_Message                                   21u 
#define DemConf_DemEventParameter_EMS_ECU_ETC2_00_message_Missing_Message                                 22u 
#define DemConf_DemEventParameter_EMS_ECU_ETC2_erratic_communication_Erractic                             23u 
#define DemConf_DemEventParameter_EMS_ECU_VD_erratic_communication_Erratic                                24u 
#define DemConf_DemEventParameter_EMS_ECU_VD_message_Missing_Message                                      25u 
#define DemConf_DemEventParameter_ESC_ECU_VDC2_erratic_communication_Erratic                              26u 
#define DemConf_DemEventParameter_ESC_ECU_VDC2_message_Missing_Message                                    27u 
#define DemConf_DemEventParameter_Exceeded_Security_Access_0x27_Attempt_Threshold_Authentication_Failure  28u 
#define DemConf_DemEventParameter_Front_Left_Side_Radar_Missing_Message                                   29u 
#define DemConf_DemEventParameter_Front_Left_Side_Radar_value_of_signal_protection_calculation_Incorrect  30u 
#define DemConf_DemEventParameter_Manual_ETC2_message_Transcurrent_gear_Invalid_Serial_Data_Received      31u 
#define DemConf_DemEventParameter_OEL_message_Turn_Signal_Switch_Invalid_Serial_Data_Received             32u 
#define DemConf_DemEventParameter_PCAN_Communication_Bus_Off                                              33u 
#define DemConf_DemEventParameter_PCAN_TimeSync_Missing_Message                                           34u 
#define DemConf_DemEventParameter_Radar_AutoAlignment_Algorithm_Signal_Calculation_Failure                35u 
#define DemConf_DemEventParameter_Radar_AutoAlignment_Misalignment_Performance_or_Incorrect_Operation     36u 
#define DemConf_DemEventParameter_Radar_AutoAlignment_Range_Alignment_or_Adjustement_Incorrect            37u 
#define DemConf_DemEventParameter_Radar_Initial_Alignment_Missing_Calibration                             38u 
#define DemConf_DemEventParameter_Radar_MMIC_Component_Failure                                            39u 
#define DemConf_DemEventParameter_Radar_MMIC_RFBIST_Component_Internal_Failure                            40u 
#define DemConf_DemEventParameter_Radar_Module_General_Memory_Failure                                     41u 
#define DemConf_DemEventParameter_Radar_Module_Over_Temperature                                           42u 
#define DemConf_DemEventParameter_Radar_Module_System_Internal_Failure                                    43u 
#define DemConf_DemEventParameter_Radar_Module_Watchdog_Failure                                           44u 
#define DemConf_DemEventParameter_Radar_Mounting_Orientation_Incorrect_Assembly                           45u 
#define DemConf_DemEventParameter_Radar_Performance_Capability_Algorithm_Based_Failure                    46u 
#define DemConf_DemEventParameter_Radar_Pin_Position_Wrong_Mounting_Position                              47u 
#define DemConf_DemEventParameter_Radar_Platform_Time_System_Programming_Failure                          48u 
#define DemConf_DemEventParameter_Radar_SMC_General_Checksum_Failure                                      49u 
#define DemConf_DemEventParameter_Radar_System_Battery_High_Voltage_System_Voltage_High                   50u 
#define DemConf_DemEventParameter_Radar_System_Battery_Low_Voltage_System_Voltage_Low                     51u 
#define DemConf_DemEventParameter_Radar_calibration_Calibration_or_Paramater_Memory_Failure               52u 
#define DemConf_DemEventParameter_SAS_ECU_SAS_message_Missing_Message                                     53u 
#define DemConf_DemEventParameter_SAS_ECU_erratic_communication_Erratic                                   54u 
#define DemConf_DemEventParameter_SAS_message_Steering_Wheel_Angle_Invalid_Serial_Data_Received           55u 
#define DemConf_DemEventParameter_VCAN_Communication_Bus_Off                                              56u 
#define DemConf_DemEventParameter_VDC2_message_Lateral_Accleration_Invalid_Serial_Data_Received           57u 
#define DemConf_DemEventParameter_VDC2_message_LongitudinalAcceleration_Invalid_Serial_Data_Received      58u 
#define DemConf_DemEventParameter_VDC2_message_Yaw_rate_Invalid_Serial_Data_Received                      59u 
#define DemConf_DemEventParameter_Vehicle_DataSet_Not_Configured                                          60u 
#define DemConf_DemEventParameter_Vehicle_Dataset_value_of_signal_protection_calculation_Incorrect        61u 


 /*  Existance of iterator interfaces  */ 
#define DEM_CFG_HAVEITER_EVENTOBDDID                                  STD_OFF      /* Deactivated due DEM_CFG_SUPPORT_WWHOBD==STD_OFF and DEM_CFG_SUPPORT_OBDONUDS==STD_OFF */ 
#define DEM_CFG_HAVEITER_EVENTSPN                                     STD_OFF      /* Deactivated due DEM_CFG_SUPPORT_J1939==STD_OFF */ 
#define DEM_CFG_HAVEITER_OBDFIMFID                                    STD_OFF      /* Deactivated due DEM_CFG_SUPPORT_IUMPR==STD_OFF */ 
#define DEM_CFG_HAVEITER_OBDRATIOID                                   STD_OFF      /* Deactivated due DEM_CFG_SUPPORT_IUMPR==STD_OFF */ 

 /*  Event global definitions  */ 
#define DEM_CFG_EVENTINDICATORATTRIBUTEBITFIELDBLOCKSIZE              8u 
#define DEM_CFG_EVENTINDICATORATTRIBUTEBITFIELDSIZE                   8u 
#define DEM_CFG_FAILEDCYCLECOUNTER_INDEX_INVALID                      255u 
#define DEM_CFG_FAULTPENDINGCOUNTER_INDEX_INVALID                     255u 
#define DEM_CFG_GLOBAL_DTC_COUNT                                      63u 
#define DEM_CFG_GLOBAL_INTERNAL_EVENT_FIRST                           0u           /* Lowest EventID with EventDestination==DEM_CFG_MEMORYID_INVALID, or 0 if no such destination is configured. */ 
#define DEM_CFG_GLOBAL_INTERNAL_EVENT_LAST                            0u           /* Highest EventID with EventDestination==DEM_CFG_MEMORYID_INVALID, or 0 if no such destination is configured. */ 
#define DEM_CFG_GLOBAL_MIRROR_FIRST                                   0u           /* Lowest EventID with DemEventDestination==DEM_DTC_ORIGIN_MIRROR_MEMORY, or 0 if no such destination is configured. */ 
#define DEM_CFG_GLOBAL_MIRROR_LAST                                    0u           /* Highest EventID with DemEventDestination==DEM_DTC_ORIGIN_MIRROR_MEMORY, or 0 if no such destination is configured. */ 
#define DEM_CFG_GLOBAL_PERMANENT_FIRST                                0u           /* Lowest EventID with EventDestination==DEM_CFG_MEMORYID_PERMANENT, or 0 if no such destination is configured. */ 
#define DEM_CFG_GLOBAL_PERMANENT_LAST                                 0u           /* Highest EventID with EventDestination==DEM_CFG_MEMORYID_PERMANENT, or 0 if no such destination is configured. */ 
#define DEM_CFG_GLOBAL_PRIMARY_FIRST                                  1u           /* Lowest EventID with DemEventDestination==DEM_DTC_ORIGIN_PRIMARY_MEMORY, or 0 if no such destination is configured. */ 
#define DEM_CFG_GLOBAL_PRIMARY_LAST                                   62u          /* Highest EventID with DemEventDestination==DEM_DTC_ORIGIN_PRIMARY_MEMORY, or 0 if no such destination is configured. */ 
#define DEM_CFG_MAXFDCSINCELASTCLEAR_INDEX_INVALID                    255u 
#define DEM_CFG_MONITOR_ACTIVITY_RATIO_INDEX_INVALID                  65535u 
#define DEM_CFG_PTO_TIMER_INDEX_INVALID                               65535u 


 /*  Timebased debouncing - timing constants  */ 
#define DEM_CFG_DEBOUNCE_LO_RES_TIMER_VALUE                           15u          /* Ticks of the low resolution timer, based on Dem_MasterMainFunction() call cycle [10.0ms]. Tick count here equals 150.0ms. */ 

 /*  EnableCondition IDs [symbolic name value]  */ 
#define DemConf_DemEnableCondition___Internal_ControlDtcSetting       0u 

 /*  EnableCondition global definitions  */ 
#define DEM_CFG_UNUSED_ENABLE_CONDITION                               0u           /* (DEM_CFG_SUPPORT_CALIBRATION_OF_ENABLE_CONDITIONS == STD_OFF) */ 

 /*  Dem time series defines  */ 
#define DEM_CFG_TIMESERIES_MAX_NUMBER_OF_SERIES                       1u           /* Max number Time Series Sets any time series stored in memory. */ 
#define DEM_CFG_TIMESERIES_MAX_NUMBER_OF_SETS                         1u           /* Max number Time Series Sets any time series stored in memory. */ 
#define DEM_CFG_TIMESERIES_NUMBER_OF_SAMPLING_PROFILES                1u           /* Feature Time Series is not used: Set to dummy value. */ 


 /*  StorageCondition global definitions  */ 
#define DEM_CFG_GLOBAL_STORAGE_COND_COUNT                             0u           /* (DEM_CFG_HAS_STORAGE_CONDITIONS == STD_OFF) */ 
#define DEM_CFG_UNUSED_STORAGE_CONDITION                              0u           /* (DEM_CFG_SUPPORT_CALIBRATION_OF_STORAGE_CONDITIONS == STD_OFF) */ 

 /*  Satellite global definitions  */ 
#define DEM_CFG_GLOBAL_PARTITION_COUNT                                1u                       /* Total number of different, referenced /Os/OsApplication containers (plus Application "0"). */ 
#define DEM_CFG_MASTER_APPLICATION_ID                                 INVALID_OSAPPLICATION    /* no /Dem/DemGeneral/DemMasterOsApplicationRef configured */ 
#define DEM_SATELLITEINFO_Invalid_OsApplication                       0x00u                    /* Index of partition "Invalid_OsApplication" in SatelliteInfo[] table */ 


 /*  PID global definitions  */ 
#define DEM_CFG_GLOBAL_OBD_IIFFRAW_SIZE                               0u           /* Pure data size of OBD-II record. */ 
#define DEM_CFG_GLOBAL_OBD_IIFFUDS_SIZE                               0u           /* Data size of OBD-II record incl PID numbers (each 2B) plus RecordNumber (1B) plus RecordCount (1B). */ 




 /*  NV block global definitions  */ 
#define DEM_CFG_ATTRIBUTES_PER_EVENT_IN_BYTES                         1u             /* Max number of indicator attributes per event divided by 8. */ 
#define DEM_CFG_ENTRYINDEX_INVALID                                    0xFFFFFFFFu    /* Value for an invalid event entry handle. Must be greater than any possible number of entries in the memories. */ 
#define DEM_CFG_ENTRY_PRIMARY_START_INDEX                             0u             /* Index of first event belonging to memory Primary in Dem_Cfg_EventEntry. */ 
#define DEM_CFG_EVENTAVAILABLEDATATYPE_SIZE                           8u             /* Number of elements in arraytype 'Dem_Cfg_EventAvailableDataType'. */ 
#define DEM_CFG_GLOBAL_NV_BLOCK_COUNT                                 12u            /* Number of NV blocks. */ 
#define DEM_CFG_GLOBAL_PROCESSORWORDS_PER_REPORTEDEVENTSTYPE          2u             /* Number of Dem_Com_ProcessorWordType elements in arraytype 'Dem_Cfg_ReportedEventsType'. */ 
#define DEM_CFG_INVALID_NVBLOCK_INDEX                                 12u            /* Value representing an invalid NV Block index. The number of NV Blocks is used as the invalid index.  */ 
#define DEM_CFG_MAX_J1939_EXP_FF_SIZE                                 0u             /* Data size of the largest configured J1939 Expanded FreezeFrame record in all event memories. */ 
#define DEM_CFG_MAX_J1939_FF_SIZE                                     0u             /* Data size of the largest configured J1939 FreezeFrame record in all event memories. */ 
#define DEM_CFG_MAX_NUMBER_AGED_DTCS                                  0u             /* Maximum number of aged DTCs (number of DTCs assigned to an ageable event). */ 
#define DEM_CFG_MAX_NUMBER_AGING_DTCS                                 0u             /* Maximum number of aging DTCs (number of DTCs assigned to an event). */ 
#define DEM_CFG_MAX_NUMBER_CONFIGURABLE_DTRS                          0u             /* Maximum number of configurable Dtrs (defined by the largest DemDtrId value, or with PostBuild-Loadable the value /Dem/DemGeneral/DemPostbuild/DemMaxNumberDtr). */ 
#define DEM_CFG_MAX_NUMBER_EVENTS_WITH_PTO_TIMER                      1u             /* Total number of events with Pto Timer required */ 
#define DEM_CFG_MAX_NUMBER_FAILED_CYCLE_DTCS                          0u             /* Size of Dem_Cfg_CycleCounterDataType.FailedCycleCounter. */ 
#define DEM_CFG_MAX_NUMBER_FAULT_PENDING_DTCS                         0u             /* Size of Dem_Cfg_CycleCounterDataType.FaultPendingCounter. */ 
#define DEM_CFG_MAX_NUMBER_MAX_FDC_SLC_DTCS                           0u             /* Size of Dem_Cfg_AdminDataType.MaxFDCSinceLastClear. */ 
#define DEM_CFG_MAX_NUMBER_OF_EVENTS_WITH_MAR                         1u             /* Number of Events using Monitor Activity Ratio */ 
#define DEM_CFG_MAX_NUMBER_OF_MAN_TO_BE_INCREMENTED_ENTRIES           1u             /* Size of Dem_Cfg_ObdIumprData.MonitorActivityNumeratorToBeIncrementedFlag array: [ceiling( DEM_CFG_MAX_NUMBER_OF_EVENTS_WITH_MAR / 32 )] or 1 if no event has MAR configured */ 
#define DEM_CFG_MAX_NUMBER_OF_STORED_MONITOR_ACTIVITY_RATIO           1u             /* Number of DTCs using Monitor Activity Ratio */ 
#define DEM_CFG_MAX_NUM_OBDFREEZEFRAME                                1u             /* Largest count of OBD FF to be stored in FreezeFrameData[DEM_CFG_MAX_NUM_OBDFREEZEFRAME][DEM_CFG_MAX_SIZE_OBDFREEZEFRAME]. */ 
#define DEM_CFG_MAX_SAMPLES_CUSTOM_TRIGGERED_TIMESERIESSNAPSHOT       1u             /* Number of total samples to be stored in TSSnapshotData[DEM_CFG_MAX_SAMPLES_CUSTOM_TRIGGERED_TIMESERIESSNAPSHOT][DEM_CFG_MAX_SIZE_CUSTOM_TRIGGERED_RECORD] or '1' if there are 0 records. */ 
#define DEM_CFG_MAX_SIZE_CUSTOM_TRIGGERED_RECORD                      1u             /* Data size of the largest custom triggered snapshot record to be stored in SnapshotData[DEM_CFG_MAX_SIZE_CUSTOM_TRIGGERED_RECORD] or in TSSnapshotData[][DEM_CFG_MAX_SIZE_CUSTOM_TRIGGERED_RECORD], or '1' if size is 0 or there are 0 records. */ 
#define DEM_CFG_MAX_SIZE_GLOBAL_SNAPSHOT                              1u             /* Data size of the global freeze frame record to be stored in GlobalSnapshotData[DEM_CFG_MAX_SIZE_GLOBAL_SNAPSHOT] or '1' if size is 0 or there is no global freeze frame. */ 
#define DEM_CFG_MAX_SIZE_OBDFREEZEFRAME                               1u             /* Data size of largest configured FreezeFrame (OBD II/ OBDonUDS) record. */ 
#define DEM_CFG_MAX_SIZE_OVERFLOWINDICATOR                            1u             /* Size of MemoryOverflow array: [ceiling( numer of primary + user defined + permanent memories / 32 )]  */ 
#define DEM_CFG_MAX_SIZE_SNAPSHOT                                     13u            /* Data size of the largest freeze frame in all event memories or '1' if size is 0. */ 
#define DEM_CFG_MAX_SIZE_WWHFREEZEFRAME                               1u             /* Data size of the largest WWH-OBD FreezeFrame record in all event memories or '1' if size is 0 or there are 0 records. */ 
#define DEM_CFG_MEMORYENTRY_HANDLE_READOUTBUFFER                      10u            /* Table Index of the first readout buffer in Dem_Cfg_MemoryEntry. */ 
#define DEM_CFG_NUMBER_OF_SUBEVENT_DATA_READOUTBUFFERS                1u             /* Maximum number of required readout buffer for subevent data. If DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON: Min(#MaxSubEventsInOneGroup,#MaxEntryInPrimary/UserDefined), else: 1 */ 
#define DEM_CFG_NUM_EVENTS_WITH_INDICATOR                             1u             /* Total number of events that are referencing at least one indicator attribute. '1' if there are 0 events. */ 
#define DEM_CFG_NVBLOCKINDEX_MAX                                      255u           /* Maximum value of Dem_Cfg_NvBlockIndexType */ 
#define DEM_CFG_NVBLOCK_ADMIN_INDEX                                   0u             /* Index into Dem_Cfg_NvBlockId[], Dem_Cfg_NvBlockDataSize[], Dem_Cfg_NvBlockDataPtr[] and other Nv*[] arrays. */ 
#define DEM_CFG_NVBLOCK_PRIMARY_INDEX                                 2u             /* Index into Dem_Cfg_NvBlockId[], Dem_Cfg_NvBlockDataSize[], Dem_Cfg_NvBlockDataPtr[] and other Nv*[] arrays. Buffer count: Dem_Cfg_GlobalPrimarySize() = 10 */ 
#define DEM_CFG_NVBLOCK_STATUS_INDEX                                  1u             /* Index into Dem_Cfg_NvBlockId[], Dem_Cfg_NvBlockDataSize[], Dem_Cfg_NvBlockDataPtr[] and other Nv*[] arrays. */ 
#define DEM_CFG_PROCESSEDCOMBINEDDTCGROUP_SIZE                        1u             /* Number of elements in arraytype 'Dem_Cfg_ProcessedCombinedDTCGroupType'. */ 



 /*  OBD global definitions  */ 
#define DEM_CFG_OBDACCELERATORPEDALINFORMATION_INDEX                  0u           /* not defined */ 
#define DEM_CFG_OBDAMBIENTPRESSURE_INDEX                              0u           /* not defined */ 
#define DEM_CFG_OBDAMBIENTTEMPERATURE_INDEX                           0u           /* not defined */ 
#define DEM_CFG_OBDDISTANCEINFORMATION_INDEX                          0u           /* not defined */ 
#define DEM_CFG_OBDENGINERUNTIMESECONDS_INDEX                         0u           /* not defined */ 
#define DEM_CFG_OBDENGINERUNTIME_INDEX                                0u           /* not defined */ 
#define DEM_CFG_OBDENGINESPEED_INDEX                                  0u           /* not defined */ 
#define DEM_CFG_OBDENGINETEMPERATURE_INDEX                            0u           /* not defined */ 
#define DEM_CFG_OBDPROGRAMMINGEVENT_INDEX                             0u           /* not defined */ 
#define DEM_CFG_OBDVEHICLESPEED_INDEX                                 0u           /* not defined */ 

 /*  Memory Info global definitions  */ 
#define DEM_CFG_MEMORYID_PRIMARY                                      0u           /* Memory Id of primary memory(The Index in Dem_Cfg_MemoryInfoTable). */ 
#define DEM_CFG_MEMORYID_PERMANENT                                    1u           /* Memory Id of permanent memory(The Index in Dem_Cfg_MemoryInfoTable). This is always generated regardless of permanent memory support. */ 
#define DEM_CFG_FIRST_MEMORYID_TIMESERIES                             1u           /* Memory Id of the first time series memory(The Index in Dem_Cfg_MemoryInfoTable). This is always generated regardless of time series memory support. */ 
#define DEM_CFG_MAX_NUM_TIMESERIES_MEMORIES                           0u           /* The number of time series memories. This is always generated regardless of time series memory support. */ 
#define DEM_CFG_FIRST_MEMORYID_CUSTOMTRIGGER                          1u           /* Memory Id of the first custom trigger memory(The Index in Dem_Cfg_MemoryInfoTable). This is always generated regardless of custom trigger memory support. */ 
#define DEM_CFG_MAX_NUM_CUSTOMTRIGGER_MEMORIES                        0u           /* The number of custom trigger memories. This is always generated regardless of custom trigger memory support. */ 
#define DEM_CFG_MEMORYID_INVALID                                      1u           /* Invalid memory Id */ 
#define DEM_CFG_MAX_NUM_USER_DEFINED_MEMORIES                         0u           /* The number of Dem/DemGeneral/DemEventMemorySet/DemUserDefinedMemory container(s) */ 
#define DEM_CFG_MEMORY_FF_RECNUM_CALCULATED                           0u           /* Calculated Snapshot Records */ 
#define DEM_CFG_MEMORY_FF_RECNUM_CONFIGURED                           1u           /* Configured Snapshot Records */ 
#define DEM_CFG_MEMORY_FF_RECNUM_CALCULATED_FIFO                      2u           /* Calculated FIFO Snapshot Records */ 
#define DEM_CFG_MEMORY_FF_RECNUM_INVALID                              3u           /* No Snapshot Enumeration type set (invalid) */ 

 /*  Client IDs [symbolic name value]  */ 
#define DemConf_DemClient_DemClient                                   0u 

 /*  Client global definitions  */ 
#define DEM_CFG_CLEARDTC_INVALID                                      255u         /* Value used as invalid index in Dem_Cfg_ClientTable[] for the ClearDTCIndex - the Client has no ClearDTC filter. */ 
#define DEM_CFG_DTCSELECTOR_INVALID                                   255u         /* Value used as invalid index in Dem_Cfg_ClientTable[] for the SelectorIndex - the Client has no selector. */ 
#define DEM_CFG_FILTER_INVALID                                        255u         /* Value used as invalid index in Dem_Cfg_ClientTable[] for the FilterIndex - the Client has no filter. */ 
#define DEM_CFG_FREEZEFRAMEITERATOR_INVALID                           255u         /* Value used as invalid index in Dem_Cfg_ClientTable[] for the FreezeFrameIteratorIndex - the Client has no FreezeFrameIterator. */ 
#define DEM_CFG_GLOBAL_CLIENT_COUNT                                   1u           /* Total number of configured /Dem/DemGeneral/DemClient containers. */ 
#define DEM_CFG_NMNODEID_INVALID                                      65535u       /* Value used in Dem_Cfg_ClientTable[] for a Client, that has no J1939NmNode configured in the J1939Dcm. */ 
#define DEM_CFG_NUMBER_OF_CLEARDTCS                                   1u           /* Currently equal to the total number of configured /Dem/DemGeneral/DemClient containers. */ 
#define DEM_CFG_NUMBER_OF_DTCSELECTORS                                1u           /* Currently equal to the total number of configured /Dem/DemGeneral/DemClient containers. */ 
#define DEM_CFG_NUMBER_OF_FILTER                                      1u           /* Currently equal to the total number of configured /Dem/DemGeneral/DemClient containers. */ 
#define DEM_CFG_NUMBER_OF_FREEZEFRAMEITERATORS                        1u           /* Currently equal to the total number of configured /Dem/DemGeneral/DemClient containers. */ 
#define DEM_CFG_NUMBER_OF_READOUTBUFFERS                              1u           /* Currently equal to the total number of configured /Dem/DemGeneral/DemClient containers. */ 
#define DEM_CFG_READOUTBUFFER_INVALID                                 255u         /* Value used as invalid index in Dem_Cfg_ClientTable[] for the ReadoutBufferIndex - the Client has no ReadoutBuffer. */ 




/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
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
  \defgroup  Dem_CfgPCGetRootDataMacros  Dem_Cfg Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Dem_Cfg_GetConfigurationIdOfPCConfig()                                                      Dem_GlobalConfigPtr->ConfigurationIdOfPCConfig
#define Dem_Cfg_GetEventAvailableInVariantOfPCConfig()                                              Dem_GlobalConfigPtr->EventAvailableInVariantOfPCConfig
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCGetConstantDuplicatedRootDataMacros  Dem_Cfg Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Dem_Cfg_GetAdminDataOfPCConfig()                                                            (&(Dem_Cfg_AdminData))  /**< the pointer to Dem_Cfg_AdminData */
#define Dem_Cfg_GetAgingDataOfPCConfig()                                                            (&(Dem_Cfg_AgingData))  /**< the pointer to Dem_Cfg_AgingData */
#define Dem_Cfg_GetCalibrationErrorRegisterOfPCConfig()                                             (&(Dem_Cfg_CalibrationErrorRegister))  /**< the pointer to Dem_Cfg_CalibrationErrorRegister */
#define Dem_Cfg_GetCalibrationObdDtcTableOfPCConfig()                                               Dem_Cfg_CalibrationObdDtcTable  /**< the pointer to Dem_Cfg_CalibrationObdDtcTable */
#define Dem_Cfg_GetCallbackClearEventAllowedOfPCConfig()                                            Dem_Cfg_CallbackClearEventAllowed  /**< the pointer to Dem_Cfg_CallbackClearEventAllowed */
#define Dem_Cfg_GetCallbackDtcStatusChangedOfPCConfig()                                             Dem_Cfg_CallbackDtcStatusChanged  /**< the pointer to Dem_Cfg_CallbackDtcStatusChanged */
#define Dem_Cfg_GetCallbackGetFdcOfPCConfig()                                                       Dem_Cfg_CallbackGetFdc  /**< the pointer to Dem_Cfg_CallbackGetFdc */
#define Dem_Cfg_GetCallbackJ1939DtcStatusChangedOfPCConfig()                                        Dem_Cfg_CallbackJ1939DtcStatusChanged  /**< the pointer to Dem_Cfg_CallbackJ1939DtcStatusChanged */
#define Dem_Cfg_GetClearDTCTableOfPCConfig()                                                        Dem_Cfg_ClearDTCTable  /**< the pointer to Dem_Cfg_ClearDTCTable */
#define Dem_Cfg_GetClearDtcNotificationFinishTableOfPCConfig()                                      Dem_Cfg_ClearDtcNotificationFinishTable  /**< the pointer to Dem_Cfg_ClearDtcNotificationFinishTable */
#define Dem_Cfg_GetClearDtcNotificationStartTableOfPCConfig()                                       Dem_Cfg_ClearDtcNotificationStartTable  /**< the pointer to Dem_Cfg_ClearDtcNotificationStartTable */
#define Dem_Cfg_GetClientTableOfPCConfig()                                                          Dem_Cfg_ClientTable  /**< the pointer to Dem_Cfg_ClientTable */
#define Dem_Cfg_GetCommitBufferOfPCConfig()                                                         (&(Dem_Cfg_CommitBuffer))  /**< the pointer to Dem_Cfg_CommitBuffer */
#define Dem_Cfg_GetCommonDidListOfPCConfig()                                                        Dem_Cfg_CommonDidList  /**< the pointer to Dem_Cfg_CommonDidList */
#define Dem_Cfg_GetCompatibilityVersionOfPCConfig(ConfigDataPtr)                                    234032u  /**< Compatibility version of the Dem generator that generated this configuration. */
#define Dem_Cfg_GetCounterBasedDebounceTableOfPCConfig()                                            Dem_Cfg_CounterBasedDebounceTable  /**< the pointer to Dem_Cfg_CounterBasedDebounceTable */
#define Dem_Cfg_GetCustomTimeSeriesFreezeFrameTableOfPCConfig()                                     Dem_Cfg_CustomTimeSeriesFreezeFrameTable  /**< the pointer to Dem_Cfg_CustomTimeSeriesFreezeFrameTable */
#define Dem_Cfg_GetCustomTriggerEntryIndexToNvBlockIndexOfPCConfig()                                Dem_Cfg_CustomTriggerEntryIndexToNvBlockIndex  /**< the pointer to Dem_Cfg_CustomTriggerEntryIndexToNvBlockIndex */
#define Dem_Cfg_GetCustomTriggerEntryPtrOfPCConfig()                                                Dem_Cfg_CustomTriggerEntryPtr  /**< the pointer to Dem_Cfg_CustomTriggerEntryPtr */
#define Dem_Cfg_GetCycleCounterDataOfPCConfig()                                                     (&(Dem_Cfg_CycleCounterData))  /**< the pointer to Dem_Cfg_CycleCounterData */
#define Dem_Cfg_GetCycleIdTableOfPCConfig()                                                         Dem_Cfg_CycleIdTable  /**< the pointer to Dem_Cfg_CycleIdTable */
#define Dem_Cfg_GetDTCSelectorTableOfPCConfig()                                                     Dem_Cfg_DTCSelectorTable  /**< the pointer to Dem_Cfg_DTCSelectorTable */
#define Dem_Cfg_GetDTCStatusAvailabilityMaskInVariantOfPCConfig()                                   0xFFu  /**< Mask provided by /Dem/DemGeneral/DemDtcStatusAvailabilityMask that indicates which Status bits are visible to the DCM. */
#define Dem_Cfg_GetDataCollectionTableErec2CollIndOfPCConfig()                                      Dem_Cfg_DataCollectionTableErec2CollInd  /**< the pointer to Dem_Cfg_DataCollectionTableErec2CollInd */
#define Dem_Cfg_GetDataCollectionTableIdxOfDataCollectionTableEdr2CollIndOfPCConfig()               Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd  /**< the pointer to Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd */
#define Dem_Cfg_GetDataCollectionTableIdxOfDataCollectionTableFfm2CollIndOfPCConfig()               Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd  /**< the pointer to Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd */
#define Dem_Cfg_GetDataCollectionTableOfPCConfig()                                                  Dem_Cfg_DataCollectionTable  /**< the pointer to Dem_Cfg_DataCollectionTable */
#define Dem_Cfg_GetDataCollectionTablePid2CollIndOfPCConfig()                                       Dem_Cfg_DataCollectionTablePid2CollInd  /**< the pointer to Dem_Cfg_DataCollectionTablePid2CollInd */
#define Dem_Cfg_GetDataElementTableIdxOfDataElementTableCol2ElmtIndOfPCConfig()                     Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd  /**< the pointer to Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd */
#define Dem_Cfg_GetDataElementTableOfPCConfig()                                                     Dem_Cfg_DataElementTable  /**< the pointer to Dem_Cfg_DataElementTable */
#define Dem_Cfg_GetDebounceDataOfPCConfig()                                                         (&(Dem_Cfg_DebounceData))  /**< the pointer to Dem_Cfg_DebounceData */
#define Dem_Cfg_GetDebounceIndirectionTableOfPCConfig()                                             Dem_Cfg_DebounceIndirectionTable  /**< the pointer to Dem_Cfg_DebounceIndirectionTable */
#define Dem_Cfg_GetDtcCalibTableOfPCConfig()                                                        Dem_Cfg_DtcCalibTable  /**< the pointer to Dem_Cfg_DtcCalibTable */
#define Dem_Cfg_GetDtcGroupMaskOfPCConfig()                                                         Dem_Cfg_DtcGroupMask  /**< the pointer to Dem_Cfg_DtcGroupMask */
#define Dem_Cfg_GetDtcInvariantDataTableOfPCConfig()                                                Dem_Cfg_DtcInvariantDataTable  /**< the pointer to Dem_Cfg_DtcInvariantDataTable */
#define Dem_Cfg_GetDtcTableOfPCConfig()                                                             Dem_Cfg_DtcTable  /**< the pointer to Dem_Cfg_DtcTable */
#define Dem_Cfg_GetDtrDataOfPCConfig()                                                              (&(Dem_Cfg_DtrData))  /**< the pointer to Dem_Cfg_DtrData */
#define Dem_Cfg_GetDtrStatusOfPCConfig()                                                            Dem_Cfg_DtrStatus  /**< the pointer to Dem_Cfg_DtrStatus */
#define Dem_Cfg_GetDtrTableIndOfPCConfig()                                                          Dem_Cfg_DtrTableInd  /**< the pointer to Dem_Cfg_DtrTableInd */
#define Dem_Cfg_GetDtrTableOfPCConfig()                                                             Dem_Cfg_DtrTable  /**< the pointer to Dem_Cfg_DtrTable */
#define Dem_Cfg_GetEnableConditionFulfilledOfPCConfig()                                             Dem_Cfg_EnableConditionFulfilled  /**< the pointer to Dem_Cfg_EnableConditionFulfilled */
#define Dem_Cfg_GetEnableConditionGroupCounterOfPCConfig()                                          Dem_Cfg_EnableConditionGroupCounter  /**< the pointer to Dem_Cfg_EnableConditionGroupCounter */
#define Dem_Cfg_GetEnableConditionGroupStateOfPCConfig()                                            Dem_Cfg_EnableConditionGroupState  /**< the pointer to Dem_Cfg_EnableConditionGroupState */
#define Dem_Cfg_GetEnableConditionGroupTableIndOfPCConfig()                                         Dem_Cfg_EnableConditionGroupTableInd  /**< the pointer to Dem_Cfg_EnableConditionGroupTableInd */
#define Dem_Cfg_GetEnableConditionGroupTableOfPCConfig()                                            Dem_Cfg_EnableConditionGroupTable  /**< the pointer to Dem_Cfg_EnableConditionGroupTable */
#define Dem_Cfg_GetEnableConditionInitTableOfPCConfig()                                             Dem_Cfg_EnableConditionInitTable  /**< the pointer to Dem_Cfg_EnableConditionInitTable */
#define Dem_Cfg_GetEnableConditionTableOfPCConfig()                                                 Dem_Cfg_EnableConditionTable  /**< the pointer to Dem_Cfg_EnableConditionTable */
#define Dem_Cfg_GetEndIdxOfDemDidClassInDataCollectionTableOfPCConfig()                             7u  /**< the end index of DemDidClass pointing in Dem_Cfg_DataCollectionTable */
#define Dem_Cfg_GetEventAvailableDataOfPCConfig()                                                   (&(Dem_Cfg_EventAvailableData))  /**< the pointer to Dem_Cfg_EventAvailableData */
#define Dem_Cfg_GetEventAvailableDefaultOfPCConfig()                                                Dem_Cfg_EventAvailableDefault  /**< the pointer to Dem_Cfg_EventAvailableDefault */
#define Dem_Cfg_GetEventCalibTableOfPCConfig()                                                      Dem_Cfg_EventCalibTable  /**< the pointer to Dem_Cfg_EventCalibTable */
#define Dem_Cfg_GetEventCycleStatusOfPCConfig()                                                     Dem_Cfg_EventCycleStatus  /**< the pointer to Dem_Cfg_EventCycleStatus */
#define Dem_Cfg_GetEventDataChangedOfPCConfig()                                                     Dem_Cfg_EventDataChanged  /**< the pointer to Dem_Cfg_EventDataChanged */
#define Dem_Cfg_GetEventDataCommitNumberOfPCConfig()                                                Dem_Cfg_EventDataCommitNumber  /**< the pointer to Dem_Cfg_EventDataCommitNumber */
#define Dem_Cfg_GetEventEntryIndexToNvBlockIndexOfPCConfig()                                        Dem_Cfg_EventEntryIndexToNvBlockIndex  /**< the pointer to Dem_Cfg_EventEntryIndexToNvBlockIndex */
#define Dem_Cfg_GetEventEntryInfoTableOfPCConfig()                                                  Dem_Cfg_EventEntryInfoTable  /**< the pointer to Dem_Cfg_EventEntryInfoTable */
#define Dem_Cfg_GetEventIndicatorDataOfPCConfig()                                                   Dem_Cfg_EventIndicatorData  /**< the pointer to Dem_Cfg_EventIndicatorData */
#define Dem_Cfg_GetEventInternalStatusOfPCConfig()                                                  Dem_Cfg_EventInternalStatus  /**< the pointer to Dem_Cfg_EventInternalStatus */
#define Dem_Cfg_GetEventInvariantDataTableOfPCConfig()                                              Dem_Cfg_EventInvariantDataTable  /**< the pointer to Dem_Cfg_EventInvariantDataTable */
#define Dem_Cfg_GetEventPrecompileDataTableIndOfPCConfig()                                          Dem_Cfg_EventPrecompileDataTableInd  /**< the pointer to Dem_Cfg_EventPrecompileDataTableInd */
#define Dem_Cfg_GetEventPrecompileDataTableOfPCConfig()                                             Dem_Cfg_EventPrecompileDataTable  /**< the pointer to Dem_Cfg_EventPrecompileDataTable */
#define Dem_Cfg_GetEventStatusChangedOfPCConfig()                                                   Dem_Cfg_EventStatusChanged  /**< the pointer to Dem_Cfg_EventStatusChanged */
#define Dem_Cfg_GetEventTableOfPCConfig()                                                           Dem_Cfg_EventTable  /**< the pointer to Dem_Cfg_EventTable */
#define Dem_Cfg_GetEventTable_ERec2EventIdIndOfPCConfig()                                           Dem_Cfg_EventTable_ERec2EventIdInd  /**< the pointer to Dem_Cfg_EventTable_ERec2EventIdInd */
#define Dem_Cfg_GetExtendedDataRecordIteratorTableOfPCConfig()                                      Dem_Cfg_ExtendedDataRecordIteratorTable  /**< the pointer to Dem_Cfg_ExtendedDataRecordIteratorTable */
#define Dem_Cfg_GetExtendedDataRecordTableOfPCConfig()                                              Dem_Cfg_ExtendedDataRecordTable  /**< the pointer to Dem_Cfg_ExtendedDataRecordTable */
#define Dem_Cfg_GetExtendedDataTableOfPCConfig()                                                    Dem_Cfg_ExtendedDataTable  /**< the pointer to Dem_Cfg_ExtendedDataTable */
#define Dem_Cfg_GetFilterInfoTableOfPCConfig()                                                      Dem_Cfg_FilterInfoTable  /**< the pointer to Dem_Cfg_FilterInfoTable */
#define Dem_Cfg_GetFinalMagicNumberOfPCConfig(ConfigDataPtr)                                        0x361Eu  /**< the FinalMagicNumber to validate the size of the initialization structure at initialization time of Dem */
#define Dem_Cfg_GetFreezeFrameDataOfPCConfig()                                                      (&(Dem_Cfg_FreezeFrameData))  /**< the pointer to Dem_Cfg_FreezeFrameData */
#define Dem_Cfg_GetFreezeFrameIteratorTableOfPCConfig()                                             Dem_Cfg_FreezeFrameIteratorTable  /**< the pointer to Dem_Cfg_FreezeFrameIteratorTable */
#define Dem_Cfg_GetFreezeFrameNumIndirectionTableOfPCConfig()                                       Dem_Cfg_FreezeFrameNumIndirectionTable  /**< the pointer to Dem_Cfg_FreezeFrameNumIndirectionTable */
#define Dem_Cfg_GetFreezeFrameNumTableOfPCConfig()                                                  Dem_Cfg_FreezeFrameNumTable  /**< the pointer to Dem_Cfg_FreezeFrameNumTable */
#define Dem_Cfg_GetFreezeFrameTableOfPCConfig()                                                     Dem_Cfg_FreezeFrameTable  /**< the pointer to Dem_Cfg_FreezeFrameTable */
#define Dem_Cfg_GetGeneralJ1939TableOfPCConfig()                                                    Dem_Cfg_GeneralJ1939Table  /**< the pointer to Dem_Cfg_GeneralJ1939Table */
#define Dem_Cfg_GetGeneralObdInputOfPCConfig()                                                      Dem_Cfg_GeneralObdInput  /**< the pointer to Dem_Cfg_GeneralObdInput */
#define Dem_Cfg_GetGlobalObdRequirementsOfPCConfig()                                                1u
#define Dem_Cfg_GetGlobalSeverityMaskOfPCConfig()                                                   0x00u  /**< Variant specific mask from OR'ed /Dem/DemConfigSet/DemDTCClass/DemDTCSeverity bits. */
#define Dem_Cfg_GetGlobalSnapshotRecordOfPCConfig()                                                 Dem_Cfg_GlobalSnapshotRecord  /**< the pointer to Dem_Cfg_GlobalSnapshotRecord */
#define Dem_Cfg_GetIndicatorAttributeTableOfPCConfig()                                              Dem_Cfg_IndicatorAttributeTable  /**< the pointer to Dem_Cfg_IndicatorAttributeTable */
#define Dem_Cfg_GetIndicatorDataOfPCConfig()                                                        (&(Dem_Cfg_IndicatorData))  /**< the pointer to Dem_Cfg_IndicatorData */
#define Dem_Cfg_GetIndicatorEventCountersOfPCConfig()                                               Dem_Cfg_IndicatorEventCounters  /**< the pointer to Dem_Cfg_IndicatorEventCounters */
#define Dem_Cfg_GetInitDataHashCodeOfPCConfig(ConfigDataPtr)                                        1845267276  /**< the hashcode to validate the initialization structure at initialization time of Dem */
#define Dem_Cfg_GetInitMonListForFuncOfPCConfig()                                                   Dem_Cfg_InitMonListForFunc  /**< the pointer to Dem_Cfg_InitMonListForFunc */
#define Dem_Cfg_GetInitMonitorForEventOfPCConfig()                                                  Dem_Cfg_InitMonitorForEvent  /**< the pointer to Dem_Cfg_InitMonitorForEvent */
#define Dem_Cfg_GetInitMonitorsForFuncOfPCConfig()                                                  Dem_Cfg_InitMonitorsForFunc  /**< the pointer to Dem_Cfg_InitMonitorsForFunc */
#define Dem_Cfg_GetJ1939EventIdsWithRatioTableOfPCConfig()                                          Dem_Cfg_J1939EventIdsWithRatioTable  /**< the pointer to Dem_Cfg_J1939EventIdsWithRatioTable */
#define Dem_Cfg_GetJ1939NodeIdIndOfPCConfig()                                                       Dem_Cfg_J1939NodeIdInd  /**< the pointer to Dem_Cfg_J1939NodeIdInd */
#define Dem_Cfg_GetJ1939NodeIdOfPCConfig()                                                          Dem_Cfg_J1939NodeId  /**< the pointer to Dem_Cfg_J1939NodeId */
#define Dem_Cfg_GetJ1939NodeIndicatorAvailabilityOfPCConfig()                                       Dem_Cfg_J1939NodeIndicatorAvailability  /**< the pointer to Dem_Cfg_J1939NodeIndicatorAvailability */
#define Dem_Cfg_GetJ1939SpnsInExpandedFreezeFrameTableOfPCConfig()                                  Dem_Cfg_J1939SpnsInExpandedFreezeFrameTable  /**< the pointer to Dem_Cfg_J1939SpnsInExpandedFreezeFrameTable */
#define Dem_Cfg_GetMaxNumberEventEntryOBDFreezeFrameOfPCConfig()                                    0u  /**< the value of MaxNumberEventEntryOBDFreezeFrame */
#define Dem_Cfg_GetMemoryCurrentCountOfPCConfig()                                                   Dem_Cfg_MemoryCurrentCount  /**< the pointer to Dem_Cfg_MemoryCurrentCount */
#define Dem_Cfg_GetMemoryInfoTableOfPCConfig()                                                      Dem_Cfg_MemoryInfoTable  /**< the pointer to Dem_Cfg_MemoryInfoTable */
#define Dem_Cfg_GetMemoryStatusOfPCConfig()                                                         Dem_Cfg_MemoryStatus  /**< the pointer to Dem_Cfg_MemoryStatus */
#define Dem_Cfg_GetMidTableOfPCConfig()                                                             Dem_Cfg_MidTable  /**< the pointer to Dem_Cfg_MidTable */
#define Dem_Cfg_GetMirrorDataOfPCConfig()                                                           (&(Dem_Cfg_MirrorData))  /**< the pointer to Dem_Cfg_MirrorData */
#define Dem_Cfg_GetMonitorActivityRatioTableOfPCConfig()                                            Dem_Cfg_MonitorActivityRatioTable  /**< the pointer to Dem_Cfg_MonitorActivityRatioTable */
#define Dem_Cfg_GetMultiEventTriggeringSlaveEventsTableOfPCConfig()                                 Dem_Cfg_MultiEventTriggeringSlaveEventsTable  /**< the pointer to Dem_Cfg_MultiEventTriggeringSlaveEventsTable */
#define Dem_Cfg_GetNoDtcConfiguredOfPCConfig()                                                      0u  /**< No Dtc configured. */
#define Dem_Cfg_GetNvBlockDataPtrOfPCConfig()                                                       Dem_Cfg_NvBlockDataPtr  /**< the pointer to Dem_Cfg_NvBlockDataPtr */
#define Dem_Cfg_GetNvBlockDataSizeOfPCConfig()                                                      Dem_Cfg_NvBlockDataSize  /**< the pointer to Dem_Cfg_NvBlockDataSize */
#define Dem_Cfg_GetNvBlockIdOfPCConfig()                                                            Dem_Cfg_NvBlockId  /**< the pointer to Dem_Cfg_NvBlockId */
#define Dem_Cfg_GetObdCalibTableOfPCConfig()                                                        Dem_Cfg_ObdCalibTable  /**< the pointer to Dem_Cfg_ObdCalibTable */
#define Dem_Cfg_GetObdIumprDataOfPCConfig()                                                         (&(Dem_Cfg_ObdIumprData))  /**< the pointer to Dem_Cfg_ObdIumprData */
#define Dem_Cfg_GetObdIumprUpdatePendingOfPCConfig()                                                Dem_Cfg_ObdIumprUpdatePending  /**< the pointer to Dem_Cfg_ObdIumprUpdatePending */
#define Dem_Cfg_GetPIDF501ReadinessSupportedAndCompletedEnforcementMaskOfPCConfig()                 0u  /**< Mask provided by /Dem/DemGeneral/DemGeneralOBD/DemOBDPIDF501RdyEnforcementMaskSupportedAlwaysCompleted that indicates which readiness groups will always be reported as supported and completed in PIDF501. */
#define Dem_Cfg_GetPIDF501ReadinessUnsupportedEnforcementMaskOfPCConfig()                           0u  /**< Mask provided by /Dem/DemGeneral/DemGeneralOBD/DemOBDPIDF501RdyEnforcementMaskUnsupported that indicates which readiness groups will always be reported as unsupported in PIDF501. */
#define Dem_Cfg_IsPendingEvaluatedForConfirmedAndActiveConditionInVariantOfPCConfig()               (((FALSE)) != FALSE)
#define Dem_Cfg_GetPermanentDataOfPCConfig()                                                        (&(Dem_Cfg_PermanentData))  /**< the pointer to Dem_Cfg_PermanentData */
#define Dem_Cfg_GetPidTableOfPCConfig()                                                             Dem_Cfg_PidTable  /**< the pointer to Dem_Cfg_PidTable */
#define Dem_Cfg_GetPrestorageIndexOfPCConfig()                                                      Dem_Cfg_PrestorageIndex  /**< the pointer to Dem_Cfg_PrestorageIndex */
#define Dem_Cfg_GetPrestorageOfPCConfig()                                                           (&(Dem_Cfg_Prestorage))  /**< the pointer to Dem_Cfg_Prestorage */
#define Dem_Cfg_GetPrimaryChronologyOfPCConfig()                                                    Dem_Cfg_PrimaryChronology  /**< the pointer to Dem_Cfg_PrimaryChronology */
#define Dem_Cfg_GetPrimaryEntry_0OfPCConfig()                                                       (&(Dem_Cfg_PrimaryEntry_0))  /**< the pointer to Dem_Cfg_PrimaryEntry_0 */
#define Dem_Cfg_GetPrimaryEntry_1OfPCConfig()                                                       (&(Dem_Cfg_PrimaryEntry_1))  /**< the pointer to Dem_Cfg_PrimaryEntry_1 */
#define Dem_Cfg_GetPrimaryEntry_2OfPCConfig()                                                       (&(Dem_Cfg_PrimaryEntry_2))  /**< the pointer to Dem_Cfg_PrimaryEntry_2 */
#define Dem_Cfg_GetPrimaryEntry_3OfPCConfig()                                                       (&(Dem_Cfg_PrimaryEntry_3))  /**< the pointer to Dem_Cfg_PrimaryEntry_3 */
#define Dem_Cfg_GetPrimaryEntry_4OfPCConfig()                                                       (&(Dem_Cfg_PrimaryEntry_4))  /**< the pointer to Dem_Cfg_PrimaryEntry_4 */
#define Dem_Cfg_GetPrimaryEntry_5OfPCConfig()                                                       (&(Dem_Cfg_PrimaryEntry_5))  /**< the pointer to Dem_Cfg_PrimaryEntry_5 */
#define Dem_Cfg_GetPrimaryEntry_6OfPCConfig()                                                       (&(Dem_Cfg_PrimaryEntry_6))  /**< the pointer to Dem_Cfg_PrimaryEntry_6 */
#define Dem_Cfg_GetPrimaryEntry_7OfPCConfig()                                                       (&(Dem_Cfg_PrimaryEntry_7))  /**< the pointer to Dem_Cfg_PrimaryEntry_7 */
#define Dem_Cfg_GetPrimaryEntry_8OfPCConfig()                                                       (&(Dem_Cfg_PrimaryEntry_8))  /**< the pointer to Dem_Cfg_PrimaryEntry_8 */
#define Dem_Cfg_GetPrimaryEntry_9OfPCConfig()                                                       (&(Dem_Cfg_PrimaryEntry_9))  /**< the pointer to Dem_Cfg_PrimaryEntry_9 */
#define Dem_Cfg_GetPrimaryEventEntryInitOfPCConfig()                                                (&(Dem_Cfg_PrimaryEventEntryInit))  /**< the pointer to Dem_Cfg_PrimaryEventEntryInit */
#define Dem_Cfg_GetRatioIdTableOfPCConfig()                                                         Dem_Cfg_RatioIdTable  /**< the pointer to Dem_Cfg_RatioIdTable */
#define Dem_Cfg_GetReadoutBufferOfPCConfig()                                                        Dem_Cfg_ReadoutBuffer  /**< the pointer to Dem_Cfg_ReadoutBuffer */
#define Dem_Cfg_GetReportedEventsOfFilterOfPCConfig()                                               Dem_Cfg_ReportedEventsOfFilter  /**< the pointer to Dem_Cfg_ReportedEventsOfFilter */
#define Dem_Cfg_GetRingBufferOfPCConfig()                                                           (&(Dem_Cfg_RingBuffer))  /**< the pointer to Dem_Cfg_RingBuffer */
#define Dem_Cfg_GetSamplingProfileDidInfoTableOfPCConfig()                                          Dem_Cfg_SamplingProfileDidInfoTable  /**< the pointer to Dem_Cfg_SamplingProfileDidInfoTable */
#define Dem_Cfg_GetSatelliteInfoInvalid_OsApplicationOfPCConfig()                                   (&(Dem_Cfg_SatelliteInfoInvalid_OsApplication))  /**< the pointer to Dem_Cfg_SatelliteInfoInvalid_OsApplication */
#define Dem_Cfg_GetSatelliteInfoOfPCConfig()                                                        Dem_Cfg_SatelliteInfo  /**< the pointer to Dem_Cfg_SatelliteInfo */
#define Dem_Cfg_GetSatelliteTimeDebounceInfoOfPCConfig()                                            Dem_Cfg_SatelliteTimeDebounceInfo  /**< the pointer to Dem_Cfg_SatelliteTimeDebounceInfo */
#define Dem_Cfg_GetSizeOfCalibrationObdDtcTableOfPCConfig()                                         0u  /**< the number of accomplishable value elements in Dem_Cfg_CalibrationObdDtcTable */
#define Dem_Cfg_GetSizeOfCallbackClearEventAllowedOfPCConfig()                                      0u  /**< the number of accomplishable value elements in Dem_Cfg_CallbackClearEventAllowed */
#define Dem_Cfg_GetSizeOfCallbackDtcStatusChangedOfPCConfig()                                       1u  /**< the number of accomplishable value elements in Dem_Cfg_CallbackDtcStatusChanged */
#define Dem_Cfg_GetSizeOfCallbackGetFdcOfPCConfig()                                                 0u  /**< the number of accomplishable value elements in Dem_Cfg_CallbackGetFdc */
#define Dem_Cfg_GetSizeOfCallbackJ1939DtcStatusChangedOfPCConfig()                                  0u  /**< the number of accomplishable value elements in Dem_Cfg_CallbackJ1939DtcStatusChanged */
#define Dem_Cfg_GetSizeOfClearDTCTableOfPCConfig()                                                  1u  /**< the number of accomplishable value elements in Dem_Cfg_ClearDTCTable */
#define Dem_Cfg_GetSizeOfClearDtcNotificationFinishTableOfPCConfig()                                0u  /**< the number of accomplishable value elements in Dem_Cfg_ClearDtcNotificationFinishTable */
#define Dem_Cfg_GetSizeOfClearDtcNotificationStartTableOfPCConfig()                                 0u  /**< the number of accomplishable value elements in Dem_Cfg_ClearDtcNotificationStartTable */
#define Dem_Cfg_GetSizeOfClientTableOfPCConfig()                                                    1u  /**< the number of accomplishable value elements in Dem_Cfg_ClientTable */
#define Dem_Cfg_GetSizeOfCounterBasedDebounceTableOfPCConfig()                                      1u  /**< the number of accomplishable value elements in Dem_Cfg_CounterBasedDebounceTable */
#define Dem_Cfg_GetSizeOfCustomTimeSeriesFreezeFrameTableOfPCConfig()                               0u  /**< the number of accomplishable value elements in Dem_Cfg_CustomTimeSeriesFreezeFrameTable */
#define Dem_Cfg_GetSizeOfCustomTriggerEntryIndexToNvBlockIndexOfPCConfig()                          0u  /**< the number of accomplishable value elements in Dem_Cfg_CustomTriggerEntryIndexToNvBlockIndex */
#define Dem_Cfg_GetSizeOfCustomTriggerEntryPtrOfPCConfig()                                          0u  /**< the number of accomplishable value elements in Dem_Cfg_CustomTriggerEntryPtr */
#define Dem_Cfg_GetSizeOfDTCSelectorTableOfPCConfig()                                               1u  /**< the number of accomplishable value elements in Dem_Cfg_DTCSelectorTable */
#define Dem_Cfg_GetSizeOfDataCollectionTableOfPCConfig()                                            8u  /**< the number of accomplishable value elements in Dem_Cfg_DataCollectionTable */
#define Dem_Cfg_GetSizeOfDataElementTableOfPCConfig()                                               8u  /**< the number of accomplishable value elements in Dem_Cfg_DataElementTable */
#define Dem_Cfg_GetSizeOfDtcGroupMaskOfPCConfig()                                                   0u  /**< the number of accomplishable value elements in Dem_Cfg_DtcGroupMask */
#define Dem_Cfg_GetSizeOfDtcTableOfPCConfig()                                                       63u  /**< the number of accomplishable value elements in Dem_Cfg_DtcTable */
#define Dem_Cfg_GetSizeOfDtrStatusOfPCConfig()                                                      0u  /**< the number of accomplishable value elements in Dem_Cfg_DtrStatus */
#define Dem_Cfg_GetSizeOfDtrTableOfPCConfig()                                                       0u  /**< the number of accomplishable value elements in Dem_Cfg_DtrTable */
#define Dem_Cfg_GetSizeOfEnableConditionGroupTableOfPCConfig()                                      1u  /**< the number of accomplishable value elements in Dem_Cfg_EnableConditionGroupTable */
#define Dem_Cfg_GetSizeOfEnableConditionTableOfPCConfig()                                           1u  /**< the number of accomplishable value elements in Dem_Cfg_EnableConditionTable */
#define Dem_Cfg_GetSizeOfEventCycleStatusOfPCConfig()                                               0u  /**< the number of accomplishable value elements in Dem_Cfg_EventCycleStatus */
#define Dem_Cfg_GetSizeOfEventDataChangedOfPCConfig()                                               0u  /**< the number of accomplishable value elements in Dem_Cfg_EventDataChanged */
#define Dem_Cfg_GetSizeOfEventDataCommitNumberOfPCConfig()                                          63u  /**< the number of accomplishable value elements in Dem_Cfg_EventDataCommitNumber */
#define Dem_Cfg_GetSizeOfEventEntryIndexToNvBlockIndexOfPCConfig()                                  11u  /**< the number of accomplishable value elements in Dem_Cfg_EventEntryIndexToNvBlockIndex */
#define Dem_Cfg_GetSizeOfEventEntryInfoTableOfPCConfig()                                            11u  /**< the number of accomplishable value elements in Dem_Cfg_EventEntryInfoTable */
#define Dem_Cfg_GetSizeOfEventIndicatorDataOfPCConfig()                                             0u  /**< the number of accomplishable value elements in Dem_Cfg_EventIndicatorData */
#define Dem_Cfg_GetSizeOfEventStatusChangedOfPCConfig()                                             2u  /**< the number of accomplishable value elements in Dem_Cfg_EventStatusChanged */
#define Dem_Cfg_GetSizeOfEventTableOfPCConfig()                                                     63u  /**< the number of accomplishable value elements in Dem_Cfg_EventTable */
#define Dem_Cfg_GetSizeOfExtendedDataRecordIteratorTableOfPCConfig()                                1u  /**< the number of accomplishable value elements in Dem_Cfg_ExtendedDataRecordIteratorTable */
#define Dem_Cfg_GetSizeOfFilterInfoTableOfPCConfig()                                                1u  /**< the number of accomplishable value elements in Dem_Cfg_FilterInfoTable */
#define Dem_Cfg_GetSizeOfFreezeFrameIteratorTableOfPCConfig()                                       1u  /**< the number of accomplishable value elements in Dem_Cfg_FreezeFrameIteratorTable */
#define Dem_Cfg_GetSizeOfFreezeFrameTableOfPCConfig()                                               2u  /**< the number of accomplishable value elements in Dem_Cfg_FreezeFrameTable */
#define Dem_Cfg_GetSizeOfGlobalSnapshotRecordOfPCConfig()                                           1u  /**< the number of accomplishable value elements in Dem_Cfg_GlobalSnapshotRecord */
#define Dem_Cfg_GetSizeOfIndicatorAttributeTableOfPCConfig()                                        0u  /**< the number of accomplishable value elements in Dem_Cfg_IndicatorAttributeTable */
#define Dem_Cfg_GetSizeOfIndicatorEventCountersOfPCConfig()                                         0u  /**< the number of accomplishable value elements in Dem_Cfg_IndicatorEventCounters */
#define Dem_Cfg_GetSizeOfInitMonitorForEventOfPCConfig()                                            0u  /**< the number of accomplishable value elements in Dem_Cfg_InitMonitorForEvent */
#define Dem_Cfg_GetSizeOfInitMonitorsForFuncOfPCConfig()                                            0u  /**< the number of accomplishable value elements in Dem_Cfg_InitMonitorsForFunc */
#define Dem_Cfg_GetSizeOfJ1939SpnsInExpandedFreezeFrameTableOfPCConfig()                            0u  /**< the number of accomplishable value elements in Dem_Cfg_J1939SpnsInExpandedFreezeFrameTable */
#define Dem_Cfg_GetSizeOfMemoryCurrentCountOfPCConfig()                                             1u  /**< the number of accomplishable value elements in Dem_Cfg_MemoryCurrentCount */
#define Dem_Cfg_GetSizeOfMemoryInfoTableOfPCConfig()                                                1u  /**< the number of accomplishable value elements in Dem_Cfg_MemoryInfoTable */
#define Dem_Cfg_GetSizeOfMemoryStatusOfPCConfig()                                                   12u  /**< the number of accomplishable value elements in Dem_Cfg_MemoryStatus */
#define Dem_Cfg_GetSizeOfMonitorActivityRatioTableOfPCConfig()                                      1u  /**< the number of accomplishable value elements in Dem_Cfg_MonitorActivityRatioTable */
#define Dem_Cfg_GetSizeOfObdIumprUpdatePendingOfPCConfig()                                          0u  /**< the number of accomplishable value elements in Dem_Cfg_ObdIumprUpdatePending */
#define Dem_Cfg_GetSizeOfPrestorageIndexOfPCConfig()                                                0u  /**< the number of accomplishable value elements in Dem_Cfg_PrestorageIndex */
#define Dem_Cfg_GetSizeOfPrimaryChronologyOfPCConfig()                                              10u  /**< the number of accomplishable value elements in Dem_Cfg_PrimaryChronology */
#define Dem_Cfg_GetSizeOfRatioIdTableOfPCConfig()                                                   0u  /**< the number of accomplishable value elements in Dem_Cfg_RatioIdTable */
#define Dem_Cfg_GetSizeOfReadoutBufferOfPCConfig()                                                  1u  /**< the number of accomplishable value elements in Dem_Cfg_ReadoutBuffer */
#define Dem_Cfg_GetSizeOfReportedEventsOfFilterOfPCConfig()                                         1u  /**< the number of accomplishable value elements in Dem_Cfg_ReportedEventsOfFilter */
#define Dem_Cfg_GetSizeOfSatelliteInfoOfPCConfig()                                                  1u  /**< the number of accomplishable value elements in Dem_Cfg_SatelliteInfo */
#define Dem_Cfg_GetSizeOfSpnToEventsWithRatioTableOfPCConfig()                                      0u  /**< the number of accomplishable value elements in Dem_Cfg_SpnToEventsWithRatioTable */
#define Dem_Cfg_GetSizeOfStartIdx500miDenRatioTableOfPCConfig()                                     0u  /**< the number of accomplishable value elements in Dem_Cfg_StartIdx500miDenRatioTable */
#define Dem_Cfg_GetSizeOfStorageConditionFulfilledOfPCConfig()                                      0u  /**< the number of accomplishable value elements in Dem_Cfg_StorageConditionFulfilled */
#define Dem_Cfg_GetSizeOfStorageConditionGroupCounterOfPCConfig()                                   0u  /**< the number of accomplishable value elements in Dem_Cfg_StorageConditionGroupCounter */
#define Dem_Cfg_GetSizeOfStorageConditionGroupTableOfPCConfig()                                     0u  /**< the number of accomplishable value elements in Dem_Cfg_StorageConditionGroupTable */
#define Dem_Cfg_GetSizeOfStorageConditionTableOfPCConfig()                                          0u  /**< the number of accomplishable value elements in Dem_Cfg_StorageConditionTable */
#define Dem_Cfg_GetSizeOfSupportedMidsTableOfPCConfig()                                             0u  /**< the number of accomplishable value elements in Dem_Cfg_SupportedMidsTable */
#define Dem_Cfg_GetSizeOfTimeBasedDebounceTableOfPCConfig()                                         0u  /**< the number of accomplishable value elements in Dem_Cfg_TimeBasedDebounceTable */
#define Dem_Cfg_GetSizeOfTimeBasedEventTableOfPCConfig()                                            0u  /**< the number of accomplishable value elements in Dem_Cfg_TimeBasedEventTable */
#define Dem_Cfg_GetSizeOfTimeSeriesEntryIndexToNvBlockIndexOfPCConfig()                             0u  /**< the number of accomplishable value elements in Dem_Cfg_TimeSeriesEntryIndexToNvBlockIndex */
#define Dem_Cfg_GetSizeOfTimeSeriesEntryTableOfPCConfig()                                           0u  /**< the number of accomplishable value elements in Dem_Cfg_TimeSeriesEntryTable */
#define Dem_Cfg_GetSizeOfTimeSeriesSamplingProfileTableOfPCConfig()                                 0u  /**< the number of accomplishable value elements in Dem_Cfg_TimeSeriesSamplingProfileTable */
#define Dem_Cfg_GetSpnToEventsWithRatioTableOfPCConfig()                                            Dem_Cfg_SpnToEventsWithRatioTable  /**< the pointer to Dem_Cfg_SpnToEventsWithRatioTable */
#define Dem_Cfg_GetStartIdx500miDenRatioTableOfPCConfig()                                           Dem_Cfg_StartIdx500miDenRatioTable  /**< the pointer to Dem_Cfg_StartIdx500miDenRatioTable */
#define Dem_Cfg_GetStartIdxOfDemDidClassInDataCollectionTableOfPCConfig()                           3u  /**< the start index of DemDidClass pointing in Dem_Cfg_DataCollectionTable */
#define Dem_Cfg_GetStatusDataOfPCConfig()                                                           (&(Dem_Cfg_StatusData))  /**< the pointer to Dem_Cfg_StatusData */
#define Dem_Cfg_GetStorageConditionFulfilledOfPCConfig()                                            Dem_Cfg_StorageConditionFulfilled  /**< the pointer to Dem_Cfg_StorageConditionFulfilled */
#define Dem_Cfg_GetStorageConditionGroupCounterOfPCConfig()                                         Dem_Cfg_StorageConditionGroupCounter  /**< the pointer to Dem_Cfg_StorageConditionGroupCounter */
#define Dem_Cfg_GetStorageConditionGroupTableIndOfPCConfig()                                        Dem_Cfg_StorageConditionGroupTableInd  /**< the pointer to Dem_Cfg_StorageConditionGroupTableInd */
#define Dem_Cfg_GetStorageConditionGroupTableOfPCConfig()                                           Dem_Cfg_StorageConditionGroupTable  /**< the pointer to Dem_Cfg_StorageConditionGroupTable */
#define Dem_Cfg_GetStorageConditionInitTableOfPCConfig()                                            Dem_Cfg_StorageConditionInitTable  /**< the pointer to Dem_Cfg_StorageConditionInitTable */
#define Dem_Cfg_GetStorageConditionTableOfPCConfig()                                                Dem_Cfg_StorageConditionTable  /**< the pointer to Dem_Cfg_StorageConditionTable */
#define Dem_Cfg_GetSupportedMidsTableOfPCConfig()                                                   Dem_Cfg_SupportedMidsTable  /**< the pointer to Dem_Cfg_SupportedMidsTable */
#define Dem_Cfg_GetTimeBasedDebounceTableOfPCConfig()                                               Dem_Cfg_TimeBasedDebounceTable  /**< the pointer to Dem_Cfg_TimeBasedDebounceTable */
#define Dem_Cfg_GetTimeBasedEventTableOfPCConfig()                                                  Dem_Cfg_TimeBasedEventTable  /**< the pointer to Dem_Cfg_TimeBasedEventTable */
#define Dem_Cfg_GetTimeSeriesEntryIndexToNvBlockIndexOfPCConfig()                                   Dem_Cfg_TimeSeriesEntryIndexToNvBlockIndex  /**< the pointer to Dem_Cfg_TimeSeriesEntryIndexToNvBlockIndex */
#define Dem_Cfg_GetTimeSeriesEntryTableOfPCConfig()                                                 Dem_Cfg_TimeSeriesEntryTable  /**< the pointer to Dem_Cfg_TimeSeriesEntryTable */
#define Dem_Cfg_GetTimeSeriesFreezeFrameTableOfPCConfig()                                           Dem_Cfg_TimeSeriesFreezeFrameTable  /**< the pointer to Dem_Cfg_TimeSeriesFreezeFrameTable */
#define Dem_Cfg_GetTimeSeriesIndirectionTableOfPCConfig()                                           Dem_Cfg_TimeSeriesIndirectionTable  /**< the pointer to Dem_Cfg_TimeSeriesIndirectionTable */
#define Dem_Cfg_GetTimeSeriesSamplingProfileCalibTableOfPCConfig()                                  Dem_Cfg_TimeSeriesSamplingProfileCalibTable  /**< the pointer to Dem_Cfg_TimeSeriesSamplingProfileCalibTable */
#define Dem_Cfg_GetTimeSeriesSamplingProfileTableOfPCConfig()                                       Dem_Cfg_TimeSeriesSamplingProfileTable  /**< the pointer to Dem_Cfg_TimeSeriesSamplingProfileTable */
#define Dem_Cfg_IsUseOBDIIOrOBDonUDSInVariantOfPCConfig()                                           (((FALSE)) != FALSE)
#define Dem_Cfg_IsUseOBDonUDSInVariantOfPCConfig()                                                  (((FALSE)) != FALSE)
#define Dem_Cfg_IsUsePermanentInVariantOfPCConfig()                                                 (((FALSE)) != FALSE)
#define Dem_Cfg_IsUseReadinessSupportAndCompletenessEnforcementMaskInVariantOfPCConfig()            (((FALSE)) != FALSE)
#define Dem_Cfg_IsUseReadinessUnsupportedEnforcementBitMaskInVariantOfPCConfig()                    (((FALSE)) != FALSE)
#define Dem_Cfg_IsUseWWHOBDInVariantOfPCConfig()                                                    (((FALSE)) != FALSE)
#define Dem_Cfg_IsUseZEVonUDSInVariantOfPCConfig()                                                  (((FALSE)) != FALSE)
#define Dem_Cfg_GetUserDefinedOriginTableOfPCConfig()                                               Dem_Cfg_UserDefinedOriginTable  /**< the pointer to Dem_Cfg_UserDefinedOriginTable */
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCGetDuplicatedRootDataMacros  Dem_Cfg Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Dem_Cfg_GetSizeOfEnableConditionFulfilledOfPCConfig()                                       Dem_Cfg_GetSizeOfEnableConditionTableOfPCConfig()  /**< the number of accomplishable value elements in Dem_Cfg_EnableConditionFulfilled */
#define Dem_Cfg_GetSizeOfEnableConditionGroupCounterOfPCConfig()                                    Dem_Cfg_GetSizeOfEnableConditionGroupTableOfPCConfig()  /**< the number of accomplishable value elements in Dem_Cfg_EnableConditionGroupCounter */
#define Dem_Cfg_GetSizeOfEnableConditionGroupStateOfPCConfig()                                      Dem_Cfg_GetSizeOfEnableConditionGroupTableOfPCConfig()  /**< the number of accomplishable value elements in Dem_Cfg_EnableConditionGroupState */
#define Dem_Cfg_GetSizeOfEventInternalStatusOfPCConfig()                                            Dem_Cfg_GetSizeOfEventTableOfPCConfig()  /**< the number of accomplishable value elements in Dem_Cfg_EventInternalStatus */
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCGetDataMacros  Dem_Cfg Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Dem_Cfg_GetAdminData()                                                                      ((*(Dem_Cfg_GetAdminDataOfPCConfig())))
#define Dem_Cfg_GetAgingData()                                                                      (NULL_PTR)
#define Dem_Cfg_GetCalibrationErrorRegister()                                                       ((*(Dem_Cfg_GetCalibrationErrorRegisterOfPCConfig())))
#define Dem_Cfg_IsAgingAllowedOfCalibrationObdDtcTable(Index)                                       ((FALSE) != FALSE)
#define Dem_Cfg_GetAgingCycleCounterThresholdOfCalibrationObdDtcTable(Index)                        (0u)
#define Dem_Cfg_GetAgingCycleIdOfCalibrationObdDtcTable(Index)                                      (NULL_PTR)
#define Dem_Cfg_IsImmediateNvStorageOfCalibrationObdDtcTable(Index)                                 ((FALSE) != FALSE)
#define Dem_Cfg_GetOperationCycleIdOfCalibrationObdDtcTable(Index)                                  (NULL_PTR)
#define Dem_Cfg_GetReadinessGroupOfCalibrationObdDtcTable(Index)                                    (NULL_PTR)
#define Dem_Cfg_IsUseExtendedDataRecord0x93OfCalibrationObdDtcTable(Index)                          ((FALSE) != FALSE)
#define Dem_Cfg_GetCallbackClearEventAllowed(Index)                                                 (NULL_PTR)
#define Dem_Cfg_GetCallbackDtcStatusChanged(Index)                                                  (Dem_Cfg_GetCallbackDtcStatusChangedOfPCConfig()[(Index)])
#define Dem_Cfg_GetCallbackGetFdc(Index)                                                            (NULL_PTR)
#define Dem_Cfg_GetCallbackJ1939DtcStatusChanged(Index)                                             (NULL_PTR)
#define Dem_Cfg_GetClearDTCTable(Index)                                                             (Dem_Cfg_GetClearDTCTableOfPCConfig()[(Index)])
#define Dem_Cfg_GetClearDtcNotificationFinishTable(Index)                                           (NULL_PTR)
#define Dem_Cfg_GetClearDtcNotificationStartTable(Index)                                            (NULL_PTR)
#define Dem_Cfg_GetCommitBuffer()                                                                   ((*(Dem_Cfg_GetCommitBufferOfPCConfig())))
#define Dem_Cfg_GetStorageThresholdOfCounterBasedDebounceTable(Index)                               (0u)
#define Dem_Cfg_GetFirstRecordNumberOfCustomTimeSeriesFreezeFrameTable(Index)                       (0u)
#define Dem_Cfg_GetLastRecordNumberOfCustomTimeSeriesFreezeFrameTable(Index)                        (0u)
#define Dem_Cfg_GetTimeSeriesSamplingProfileTableIdxOfCustomTimeSeriesFreezeFrameTable(Index)       (0u)
#define Dem_Cfg_IsUpdateRecordOfCustomTimeSeriesFreezeFrameTable(Index)                             ((FALSE) != FALSE)
#define Dem_Cfg_GetCustomTriggerEntryIndexToNvBlockIndex(Index)                                     (NULL_PTR)
#define Dem_Cfg_GetCustomTriggerEntryPtr(Index)                                                     (NULL_PTR)
#define Dem_Cfg_GetCycleCounterData()                                                               (NULL_PTR)
#define Dem_Cfg_IsEndsOnInitOfCycleIdTable(Index)                                                   ((FALSE) != FALSE)
#define Dem_Cfg_GetDTCSelectorTable(Index)                                                          (Dem_Cfg_GetDTCSelectorTableOfPCConfig()[(Index)])
#define Dem_Cfg_GetCollectionSizeOfDataCollectionTable(Index)                                       (Dem_Cfg_GetDataCollectionTableOfPCConfig()[(Index)].CollectionSizeOfDataCollectionTable)
#define Dem_Cfg_GetDataElementTableCol2ElmtIndDataElementTableCol2ElmtIndEndIdxOfDataCollectionTable(Index) (Dem_Cfg_GetDataCollectionTableOfPCConfig()[(Index)].DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndEndIdxOfDataCollectionTable)
#define Dem_Cfg_GetDataElementTableCol2ElmtIndDataElementTableCol2ElmtIndStartIdxOfDataCollectionTable(Index) (Dem_Cfg_GetDataCollectionTableOfPCConfig()[(Index)].DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndStartIdxOfDataCollectionTable)
#define Dem_Cfg_GetEventTable_ERec2EventIdIndEndIdxOfDataCollectionTable(Index)                     (0u)
#define Dem_Cfg_GetEventTable_ERec2EventIdIndStartIdxOfDataCollectionTable(Index)                   (0u)
#define Dem_Cfg_IsEventTable_ERec2EventIdIndUsedOfDataCollectionTable(Index)                        ((FALSE) != FALSE)
#define Dem_Cfg_GetIdNumberOfDataCollectionTable(Index)                                             (Dem_Cfg_GetDataCollectionTableOfPCConfig()[(Index)].IdNumberOfDataCollectionTable)
#define Dem_Cfg_GetStorageKindOfDataCollectionTable(Index)                                          (Dem_Cfg_GetDataCollectionTableOfPCConfig()[(Index)].StorageKindOfDataCollectionTable)
#define Dem_Cfg_GetDataCollectionTableIdxOfDataCollectionTableEdr2CollInd(Index)                    (Dem_Cfg_GetDataCollectionTableIdxOfDataCollectionTableEdr2CollIndOfPCConfig()[(Index)])
#define Dem_Cfg_GetDataCollectionTableIdxOfDataCollectionTableFfm2CollInd(Index)                    (Dem_Cfg_GetDataCollectionTableIdxOfDataCollectionTableFfm2CollIndOfPCConfig()[(Index)])
#define Dem_Cfg_GetDataCollectionTablePid2CollInd(Index)                                            (0u)
#define Dem_Cfg_GetElementDataTypeOfDataElementTable(Index)                                         (Dem_Cfg_GetDataElementTableOfPCConfig()[(Index)].ElementDataTypeOfDataElementTable)
#define Dem_Cfg_GetElementKindOfDataElementTable(Index)                                             (Dem_Cfg_GetDataElementTableOfPCConfig()[(Index)].ElementKindOfDataElementTable)
#define Dem_Cfg_GetElementSizeOfDataElementTable(Index)                                             (Dem_Cfg_GetDataElementTableOfPCConfig()[(Index)].ElementSizeOfDataElementTable)
#define Dem_Cfg_GetReadDataFuncOfDataElementTable(Index)                                            (Dem_Cfg_GetDataElementTableOfPCConfig()[(Index)].ReadDataFuncOfDataElementTable)
#define Dem_Cfg_GetDataElementTableIdxOfDataElementTableCol2ElmtInd(Index)                          (Dem_Cfg_GetDataElementTableIdxOfDataElementTableCol2ElmtIndOfPCConfig()[(Index)])
#define Dem_Cfg_GetDebounceData()                                                                   (NULL_PTR)
#define Dem_Cfg_GetCounterBasedDebounceTableIdxOfDebounceIndirectionTable(Index)                    (Dem_Cfg_GetDebounceIndirectionTableOfPCConfig()[(Index)].CounterBasedDebounceTableIdxOfDebounceIndirectionTable)
#define Dem_Cfg_GetTimeBasedDebounceTableIdxOfDebounceIndirectionTable(Index)                       (0u)
#define Dem_Cfg_IsTimeBasedDebounceTableUsedOfDebounceIndirectionTable(Index)                       ((FALSE) != FALSE)
#define Dem_Cfg_GetAgingCycleCounterThresholdOfDtcCalibTable(Index)                                 (Dem_Cfg_GetDtcCalibTableOfPCConfig()[(Index)].AgingCycleCounterThresholdOfDtcCalibTable)
#define Dem_Cfg_GetAgingCycleIdOfDtcCalibTable(Index)                                               (Dem_Cfg_GetDtcCalibTableOfPCConfig()[(Index)].AgingCycleIdOfDtcCalibTable)
#define Dem_Cfg_GetDtcPriorityOfDtcCalibTable(Index)                                                (Dem_Cfg_GetDtcCalibTableOfPCConfig()[(Index)].DtcPriorityOfDtcCalibTable)
#define Dem_Cfg_GetUdsDtcOfDtcCalibTable(Index)                                                     (Dem_Cfg_GetDtcCalibTableOfPCConfig()[(Index)].UdsDtcOfDtcCalibTable)
#define Dem_Cfg_GetGroupMaskOfDtcGroupMask(Index)                                                   (0u)
#define Dem_Cfg_GetUdsGroupDtcOfDtcGroupMask(Index)                                                 (0x00u)
#define Dem_Cfg_GetFreezeFrameTableStdFFIdxOfDtcInvariantDataTable(Index)                           (Dem_Cfg_GetDtcInvariantDataTableOfPCConfig()[(Index)].FreezeFrameTableStdFFIdxOfDtcInvariantDataTable)
#define Dem_Cfg_GetFunctionalUnitOfDtcInvariantDataTable(Index)                                     (Dem_Cfg_GetDtcInvariantDataTableOfPCConfig()[(Index)].FunctionalUnitOfDtcInvariantDataTable)
#define Dem_Cfg_GetCustomTimeSeriesFreezeFrameTableIdxOfDtcTable(Index)                             (0u)
#define Dem_Cfg_IsCustomTimeSeriesFreezeFrameTableUsedOfDtcTable(Index)                             ((FALSE) != FALSE)
#define Dem_Cfg_IsCustomTriggeredSnapshotConfiguredOfDtcTable(Index)                                ((FALSE) != FALSE)
#define Dem_Cfg_IsCustomTriggeredTimeSeriesSnapshotConfiguredOfDtcTable(Index)                      ((FALSE) != FALSE)
#define Dem_Cfg_IsDtcObdRelevanceOfDtcTable(Index)                                                  ((FALSE) != FALSE)
#define Dem_Cfg_GetExtendedDataTableIdxOfDtcTable(Index)                                            (Dem_Cfg_GetDtcTableOfPCConfig()[(Index)].ExtendedDataTableIdxOfDtcTable)
#define Dem_Cfg_GetFreezeFrameNumIndirectionTableIdxOfDtcTable(Index)                               (Dem_Cfg_GetDtcTableOfPCConfig()[(Index)].FreezeFrameNumIndirectionTableIdxOfDtcTable)
#define Dem_Cfg_GetJ1939NodeIdIndEndIdxOfDtcTable(Index)                                            (Dem_Cfg_GetDtcTableOfPCConfig()[(Index)].J1939NodeIdIndEndIdxOfDtcTable)
#define Dem_Cfg_GetJ1939NodeIdIndStartIdxOfDtcTable(Index)                                          (Dem_Cfg_GetDtcTableOfPCConfig()[(Index)].J1939NodeIdIndStartIdxOfDtcTable)
#define Dem_Cfg_GetSMARIndexOfDtcTable(Index)                                                       (0u)
#define Dem_Cfg_GetTimeSeriesIndirectionTableEndIdxOfDtcTable(Index)                                (0u)
#define Dem_Cfg_GetTimeSeriesIndirectionTableStartIdxOfDtcTable(Index)                              (0u)
#define Dem_Cfg_IsTimeSeriesIndirectionTableUsedOfDtcTable(Index)                                   ((FALSE) != FALSE)
#define Dem_Cfg_GetDtrData()                                                                        (NULL_PTR)
#define Dem_Cfg_GetDtrStatus(Index)                                                                 ()
#define Dem_Cfg_GetDivisorOfDtrTable(Index)                                                         (NULL_PTR)
#define Dem_Cfg_GetEventTableIdxOfDtrTable(Index)                                                   (0u)
#define Dem_Cfg_GetLinearFactorOfDtrTable(Index)                                                    (NULL_PTR)
#define Dem_Cfg_GetOffsetOfDtrTable(Index)                                                          (NULL_PTR)
#define Dem_Cfg_GetUasidOfDtrTable(Index)                                                           (0u)
#define Dem_Cfg_GetUpdateKindOfDtrTable(Index)                                                      (NULL_PTR)
#define Dem_Cfg_GetDtrTableInd(Index)                                                               (0u)
#define Dem_Cfg_IsEnableConditionFulfilled(Index)                                                   ((Dem_Cfg_GetEnableConditionFulfilledOfPCConfig()[(Index)]) != FALSE)
#define Dem_Cfg_GetEnableConditionGroupCounter(Index)                                               (Dem_Cfg_GetEnableConditionGroupCounterOfPCConfig()[(Index)])
#define Dem_Cfg_GetEnableConditionGroupState(Index)                                                 (Dem_Cfg_GetEnableConditionGroupStateOfPCConfig()[(Index)])
#define Dem_Cfg_GetEventAvailableData()                                                             (NULL_PTR)
#define Dem_Cfg_IsEventAvailableInVariant(Index)                                                    ((Dem_Cfg_GetEventAvailableInVariantOfPCConfig()[(Index)]) != FALSE)
#define Dem_Cfg_GetEventCycleStatus(Index)                                                          (0u)
#define Dem_Cfg_GetEventDataChanged(Index)                                                          (NULL_PTR)
#define Dem_Cfg_GetEventDataCommitNumber(Index)                                                     (Dem_Cfg_GetEventDataCommitNumberOfPCConfig()[(Index)])
#define Dem_Cfg_GetEventEntryIndexToNvBlockIndex(Index)                                             (Dem_Cfg_GetEventEntryIndexToNvBlockIndexOfPCConfig()[(Index)])
#define Dem_Cfg_GetBaseEntryPtrOfEventEntryInfoTable(Index)                                         (Dem_Cfg_GetEventEntryInfoTableOfPCConfig()[(Index)].BaseEntryPtrOfEventEntryInfoTable)
#define Dem_Cfg_GetExtendedDataPtrOfEventEntryInfoTable(Index)                                      (Dem_Cfg_GetEventEntryInfoTableOfPCConfig()[(Index)].ExtendedDataPtrOfEventEntryInfoTable)
#define Dem_Cfg_GetInitPtrOfEventEntryInfoTable(Index)                                              (Dem_Cfg_GetEventEntryInfoTableOfPCConfig()[(Index)].InitPtrOfEventEntryInfoTable)
#define Dem_Cfg_GetJ1939FreezeFrameDataPtrOfEventEntryInfoTable(Index)                              (Dem_Cfg_GetEventEntryInfoTableOfPCConfig()[(Index)].J1939FreezeFrameDataPtrOfEventEntryInfoTable)
#define Dem_Cfg_GetObdFreezeFrameDataPtrOfEventEntryInfoTable(Index)                                (Dem_Cfg_GetEventEntryInfoTableOfPCConfig()[(Index)].ObdFreezeFrameDataPtrOfEventEntryInfoTable)
#define Dem_Cfg_GetSizeOfExtendedDataOfEventEntryInfoTable(Index)                                   (Dem_Cfg_GetEventEntryInfoTableOfPCConfig()[(Index)].SizeOfExtendedDataOfEventEntryInfoTable)
#define Dem_Cfg_GetSizeOfJ1939ExpFreezeFrameOfEventEntryInfoTable(Index)                            (Dem_Cfg_GetEventEntryInfoTableOfPCConfig()[(Index)].SizeOfJ1939ExpFreezeFrameOfEventEntryInfoTable)
#define Dem_Cfg_GetSizeOfJ1939FreezeFrameOfEventEntryInfoTable(Index)                               (Dem_Cfg_GetEventEntryInfoTableOfPCConfig()[(Index)].SizeOfJ1939FreezeFrameOfEventEntryInfoTable)
#define Dem_Cfg_GetSizeOfObdFreezeFrameOfEventEntryInfoTable(Index)                                 (Dem_Cfg_GetEventEntryInfoTableOfPCConfig()[(Index)].SizeOfObdFreezeFrameOfEventEntryInfoTable)
#define Dem_Cfg_GetSizeOfSnapshotDataOfEventEntryInfoTable(Index)                                   (Dem_Cfg_GetEventEntryInfoTableOfPCConfig()[(Index)].SizeOfSnapshotDataOfEventEntryInfoTable)
#define Dem_Cfg_GetSnapshotDataPtrOfEventEntryInfoTable(Index)                                      (Dem_Cfg_GetEventEntryInfoTableOfPCConfig()[(Index)].SnapshotDataPtrOfEventEntryInfoTable)
#define Dem_Cfg_GetAssignedAttributeBitFieldOfEventIndicatorData(Index)                             (NULL_PTR)
#define Dem_Cfg_GetEventHealingTargetOfEventIndicatorData(Index)                                    (0u)
#define Dem_Cfg_GetEventInternalStatus(Index)                                                       (Dem_Cfg_GetEventInternalStatusOfPCConfig()[(Index)])
#define Dem_Cfg_GetDtcTableIdxOfEventInvariantDataTable(Index)                                      (Dem_Cfg_GetEventInvariantDataTableOfPCConfig()[(Index)].DtcTableIdxOfEventInvariantDataTable)
#define Dem_Cfg_GetCallbackGetFdcIdxOfEventPrecompileDataTable(Index)                               (0u)
#define Dem_Cfg_IsEventConsiderPtoStatusOfEventPrecompileDataTable(Index)                           ((FALSE) != FALSE)
#define Dem_Cfg_GetEventStatusChangedEndIdxOfEventPrecompileDataTable(Index)                        (Dem_Cfg_GetEventPrecompileDataTableOfPCConfig()[(Index)].EventStatusChangedEndIdxOfEventPrecompileDataTable)
#define Dem_Cfg_GetEventStatusChangedStartIdxOfEventPrecompileDataTable(Index)                      (Dem_Cfg_GetEventPrecompileDataTableOfPCConfig()[(Index)].EventStatusChangedStartIdxOfEventPrecompileDataTable)
#define Dem_Cfg_GetMultiEventTriggeringSlaveEventsTableEndIdxOfEventPrecompileDataTable(Index)      (0u)
#define Dem_Cfg_GetMultiEventTriggeringSlaveEventsTableStartIdxOfEventPrecompileDataTable(Index)    (0u)
#define Dem_Cfg_IsMultiEventTriggeringSlaveEventsTableUsedOfEventPrecompileDataTable(Index)         ((FALSE) != FALSE)
#define Dem_Cfg_IsMultiEventTriggeringSlaveOfEventPrecompileDataTable(Index)                        ((FALSE) != FALSE)
#define Dem_Cfg_GetEventStatusChanged(Index)                                                        (Dem_Cfg_GetEventStatusChangedOfPCConfig()[(Index)])
#define Dem_Cfg_GetDtrTableIndEndIdxOfEventTable(Index)                                             (0u)
#define Dem_Cfg_GetDtrTableIndStartIdxOfEventTable(Index)                                           (0u)
#define Dem_Cfg_IsDtrTableIndUsedOfEventTable(Index)                                                ((FALSE) != FALSE)
#define Dem_Cfg_GetEnableConditionGroupTableIdxOfEventTable(Index)                                  (0u)
#define Dem_Cfg_IsEnableConditionGroupTableUsedOfEventTable(Index)                                  ((FALSE) != FALSE)
#define Dem_Cfg_GetEventIndicatorDataIdxOfEventTable(Index)                                         (0u)
#define Dem_Cfg_IsEventIndicatorDataUsedOfEventTable(Index)                                         ((FALSE) != FALSE)
#define Dem_Cfg_GetEventPtoTimerIndexOfEventTable(Index)                                            (0u)
#define Dem_Cfg_GetFailedCycleCounterIndexOfEventTable(Index)                                       (0u)
#define Dem_Cfg_GetFaultPendingCounterIndexOfEventTable(Index)                                      (0u)
#define Dem_Cfg_GetMaxFDCSinceLastClearIndexOfEventTable(Index)                                     (0u)
#define Dem_Cfg_GetMonitorActivityRatioTableIdxOfEventTable(Index)                                  (0u)
#define Dem_Cfg_GetEventTable_ERec2EventIdInd(Index)                                                (0u)
#define Dem_Cfg_GetExtendedDataRecordIteratorTable(Index)                                           (Dem_Cfg_GetExtendedDataRecordIteratorTableOfPCConfig()[(Index)])
#define Dem_Cfg_GetDataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndEndIdxOfExtendedDataTable(Index) (Dem_Cfg_GetExtendedDataTableOfPCConfig()[(Index)].DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndEndIdxOfExtendedDataTable)
#define Dem_Cfg_GetDataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndStartIdxOfExtendedDataTable(Index) (Dem_Cfg_GetExtendedDataTableOfPCConfig()[(Index)].DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndStartIdxOfExtendedDataTable)
#define Dem_Cfg_GetFilterInfoTable(Index)                                                           (Dem_Cfg_GetFilterInfoTableOfPCConfig()[(Index)])
#define Dem_Cfg_GetFreezeFrameData()                                                                (NULL_PTR)
#define Dem_Cfg_GetFreezeFrameIteratorTable(Index)                                                  (Dem_Cfg_GetFreezeFrameIteratorTableOfPCConfig()[(Index)])
#define Dem_Cfg_GetFreezeFrameNumTableEndIdxOfFreezeFrameNumIndirectionTable(Index)                 (Dem_Cfg_GetFreezeFrameNumIndirectionTableOfPCConfig()[(Index)].FreezeFrameNumTableEndIdxOfFreezeFrameNumIndirectionTable)
#define Dem_Cfg_GetFreezeFrameNumTableSecondEndIdxOfFreezeFrameNumIndirectionTable(Index)           (0u)
#define Dem_Cfg_GetFreezeFrameNumTableSecondStartIdxOfFreezeFrameNumIndirectionTable(Index)         (0u)
#define Dem_Cfg_IsFreezeFrameNumTableSecondUsedOfFreezeFrameNumIndirectionTable(Index)              ((FALSE) != FALSE)
#define Dem_Cfg_GetFreezeFrameNumTableStartIdxOfFreezeFrameNumIndirectionTable(Index)               (Dem_Cfg_GetFreezeFrameNumIndirectionTableOfPCConfig()[(Index)].FreezeFrameNumTableStartIdxOfFreezeFrameNumIndirectionTable)
#define Dem_Cfg_GetDataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndEndIdxOfFreezeFrameTable(Index) (Dem_Cfg_GetFreezeFrameTableOfPCConfig()[(Index)].DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndEndIdxOfFreezeFrameTable)
#define Dem_Cfg_GetDataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndStartIdxOfFreezeFrameTable(Index) (Dem_Cfg_GetFreezeFrameTableOfPCConfig()[(Index)].DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndStartIdxOfFreezeFrameTable)
#define Dem_Cfg_GetRecordSizeOfFreezeFrameTable(Index)                                              (Dem_Cfg_GetFreezeFrameTableOfPCConfig()[(Index)].RecordSizeOfFreezeFrameTable)
#define Dem_Cfg_GetRecordSizeUdsOfFreezeFrameTable(Index)                                           (Dem_Cfg_GetFreezeFrameTableOfPCConfig()[(Index)].RecordSizeUdsOfFreezeFrameTable)
#define Dem_Cfg_GetRecordSizeOfGeneralJ1939Table(Index)                                             (0u)
#define Dem_Cfg_GetBehaviourOfIndicatorAttributeTable(Index)                                        (DEM_INDICATOR_OFF)
#define Dem_Cfg_GetFailureCycleCounterThresholdOfIndicatorAttributeTable(Index)                     (0u)
#define Dem_Cfg_GetIdOfIndicatorAttributeTable(Index)                                               (0u)
#define Dem_Cfg_GetJ1939NodeIdOfIndicatorAttributeTable(Index)                                      (0)
#define Dem_Cfg_GetIndicatorData()                                                                  (NULL_PTR)
#define Dem_Cfg_GetIndicatorEventCounters(Index)                                                    (0u)
#define Dem_Cfg_GetInitMonitorForEvent(Index)                                                       (NULL_PTR)
#define Dem_Cfg_GetInitMonitorsForFunc(Index)                                                       (NULL_PTR)
#define Dem_Cfg_GetEventIdOfJ1939EventIdsWithRatioTable(Index)                                      (0u)
#define Dem_Cfg_GetJ1939NodeId(Index)                                                               (Dem_Cfg_GetJ1939NodeIdOfPCConfig()[(Index)])
#define Dem_Cfg_GetJ1939NodeIdInd(Index)                                                            (Dem_Cfg_GetJ1939NodeIdIndOfPCConfig()[(Index)])
#define Dem_Cfg_GetSpnIdOfJ1939SpnsInExpandedFreezeFrameTable(Index)                                (0u)
#define Dem_Cfg_GetSpnSizeOfJ1939SpnsInExpandedFreezeFrameTable(Index)                              (0u)
#define Dem_Cfg_GetMemoryCurrentCount(Index)                                                        (Dem_Cfg_GetMemoryCurrentCountOfPCConfig()[(Index)])
#define Dem_Cfg_GetMemoryStatus(Index)                                                              (Dem_Cfg_GetMemoryStatusOfPCConfig()[(Index)])
#define Dem_Cfg_GetDtrTableIdxOfMidTable(Index)                                                     (0u)
#define Dem_Cfg_GetMidOfMidTable(Index)                                                             (0x00u)
#define Dem_Cfg_GetTidOfMidTable(Index)                                                             (0x00u)
#define Dem_Cfg_GetMirrorData()                                                                     (0u)
#define Dem_Cfg_GetEventPrecompileDataTableIdxOfMultiEventTriggeringSlaveEventsTable(Index)         (0u)
#define Dem_Cfg_GetNvBlockDataPtr(Index)                                                            (Dem_Cfg_GetNvBlockDataPtrOfPCConfig()[(Index)])
#define Dem_Cfg_GetNvBlockDataSize(Index)                                                           (Dem_Cfg_GetNvBlockDataSizeOfPCConfig()[(Index)])
#define Dem_Cfg_GetNvBlockId(Index)                                                                 (Dem_Cfg_GetNvBlockIdOfPCConfig()[(Index)])
#define Dem_Cfg_GetCalibrationObdDtcTableIdxOfObdCalibTable(Index)                                  (0u)
#define Dem_Cfg_IsCalibrationObdDtcTableUsedOfObdCalibTable(Index)                                  ((FALSE) != FALSE)
#define Dem_Cfg_GetObdDtc3ByteOfObdCalibTable(Index)                                                (0u)
#define Dem_Cfg_GetObdDtcOfObdCalibTable(Index)                                                     (0u)
#define Dem_Cfg_GetReadinessGroupOfObdCalibTable(Index)                                             (NULL_PTR)
#define Dem_Cfg_GetObdIumprData()                                                                   (NULL_PTR)
#define Dem_Cfg_IsObdIumprUpdatePending(Index)                                                      ((FALSE) != FALSE)
#define Dem_Cfg_GetPermanentData()                                                                  (NULL_PTR)
#define Dem_Cfg_GetDataCollectionTablePid2CollIndEndIdxOfPidTable(Index)                            (0u)
#define Dem_Cfg_GetDataCollectionTablePid2CollIndStartIdxOfPidTable(Index)                          (0u)
#define Dem_Cfg_IsDataCollectionTablePid2CollIndUsedOfPidTable(Index)                               ((FALSE) != FALSE)
#define Dem_Cfg_GetPrestorage()                                                                     (NULL_PTR)
#define Dem_Cfg_GetPrestorageIndex(Index)                                                           ()
#define Dem_Cfg_GetPrimaryChronology(Index)                                                         (Dem_Cfg_GetPrimaryChronologyOfPCConfig()[(Index)])
#define Dem_Cfg_GetPrimaryEntry_0()                                                                 ((*(Dem_Cfg_GetPrimaryEntry_0OfPCConfig())))
#define Dem_Cfg_GetPrimaryEntry_1()                                                                 ((*(Dem_Cfg_GetPrimaryEntry_1OfPCConfig())))
#define Dem_Cfg_GetPrimaryEntry_2()                                                                 ((*(Dem_Cfg_GetPrimaryEntry_2OfPCConfig())))
#define Dem_Cfg_GetPrimaryEntry_3()                                                                 ((*(Dem_Cfg_GetPrimaryEntry_3OfPCConfig())))
#define Dem_Cfg_GetPrimaryEntry_4()                                                                 ((*(Dem_Cfg_GetPrimaryEntry_4OfPCConfig())))
#define Dem_Cfg_GetPrimaryEntry_5()                                                                 ((*(Dem_Cfg_GetPrimaryEntry_5OfPCConfig())))
#define Dem_Cfg_GetPrimaryEntry_6()                                                                 ((*(Dem_Cfg_GetPrimaryEntry_6OfPCConfig())))
#define Dem_Cfg_GetPrimaryEntry_7()                                                                 ((*(Dem_Cfg_GetPrimaryEntry_7OfPCConfig())))
#define Dem_Cfg_GetPrimaryEntry_8()                                                                 ((*(Dem_Cfg_GetPrimaryEntry_8OfPCConfig())))
#define Dem_Cfg_GetPrimaryEntry_9()                                                                 ((*(Dem_Cfg_GetPrimaryEntry_9OfPCConfig())))
#define Dem_Cfg_GetPrimaryEventEntryInit()                                                          ((*(Dem_Cfg_GetPrimaryEventEntryInitOfPCConfig())))
#define Dem_Cfg_GetReadoutBuffer(Index)                                                             (Dem_Cfg_GetReadoutBufferOfPCConfig()[(Index)])
#define Dem_Cfg_GetReportedEventsOfFilter(Index)                                                    (Dem_Cfg_GetReportedEventsOfFilterOfPCConfig()[(Index)])
#define Dem_Cfg_GetRingBuffer()                                                                     ()
#define Dem_Cfg_GetDataCollectionTableIdxOfSamplingProfileDidInfoTable(Index)                       (0u)
#define Dem_Cfg_GetDidRingBufferOffsetOfSamplingProfileDidInfoTable(Index)                          (0u)
#define Dem_Cfg_GetDebounceLoResTimerOfSatelliteInfo(Index)                                         (NULL_PTR)
#define Dem_Cfg_GetMaxDebounceValuesOfSatelliteInfo(Index)                                          (NULL_PTR)
#define Dem_Cfg_GetSatelliteExtendedDataOfSatelliteInfo(Index)                                      (NULL_PTR)
#define Dem_Cfg_GetSatelliteInfoInvalid_OsApplication()                                             ((*(Dem_Cfg_GetSatelliteInfoInvalid_OsApplicationOfPCConfig())))
#define Dem_Cfg_GetTimeBasedEventTableEndIdxOfSatelliteTimeDebounceInfo(Index)                      (0u)
#define Dem_Cfg_GetTimeBasedEventTableStartIdxOfSatelliteTimeDebounceInfo(Index)                    (0u)
#define Dem_Cfg_IsTimeBasedEventTableUsedOfSatelliteTimeDebounceInfo(Index)                         ((FALSE) != FALSE)
#define Dem_Cfg_GetJ1939EventIdsWithRatioTableEndIdxOfSpnToEventsWithRatioTable(Index)              (0u)
#define Dem_Cfg_GetJ1939EventIdsWithRatioTableStartIdxOfSpnToEventsWithRatioTable(Index)            (0u)
#define Dem_Cfg_GetSPNOfSpnToEventsWithRatioTable(Index)                                            (0u)
#define Dem_Cfg_GetStatusData()                                                                     ((*(Dem_Cfg_GetStatusDataOfPCConfig())))
#define Dem_Cfg_IsStorageConditionFulfilled(Index)                                                  ((FALSE) != FALSE)
#define Dem_Cfg_GetStorageConditionGroupCounter(Index)                                              (0u)
#define Dem_Cfg_GetIndexOfStorageConditionGroupTable(Index)                                         (0u)
#define Dem_Cfg_GetStorageConditionGroupTableInd(Index)                                             (0u)
#define Dem_Cfg_IsFulfilledAtInitOfStorageConditionInitTable(Index)                                 ((FALSE) != FALSE)
#define Dem_Cfg_GetStorageConditionGroupTableIndEndIdxOfStorageConditionTable(Index)                (0u)
#define Dem_Cfg_GetStorageConditionGroupTableIndStartIdxOfStorageConditionTable(Index)              (0u)
#define Dem_Cfg_IsStorageConditionGroupTableIndUsedOfStorageConditionTable(Index)                   ((FALSE) != FALSE)
#define Dem_Cfg_GetStartIdxMidTableOfSupportedMidsTable(Index)                                      (0u)
#define Dem_Cfg_IsDebounceContinuousOfTimeBasedDebounceTable(Index)                                 ((FALSE) != FALSE)
#define Dem_Cfg_IsEventDebounceBehaviorOfTimeBasedDebounceTable(Index)                              ((FALSE) != FALSE)
#define Dem_Cfg_GetFailTimerThresholdHighResOfTimeBasedDebounceTable(Index)                         (0)
#define Dem_Cfg_GetFailTimerThresholdLowResOfTimeBasedDebounceTable(Index)                          (0)
#define Dem_Cfg_IsIsLowResolutionOfTimeBasedDebounceTable(Index)                                    ((FALSE) != FALSE)
#define Dem_Cfg_GetPassTimerThresholdHighResOfTimeBasedDebounceTable(Index)                         (0)
#define Dem_Cfg_GetPassTimerThresholdLowResOfTimeBasedDebounceTable(Index)                          (0)
#define Dem_Cfg_GetStorageTimerThresholdHighResOfTimeBasedDebounceTable(Index)                      (0)
#define Dem_Cfg_GetStorageTimerThresholdLowResOfTimeBasedDebounceTable(Index)                       (0)
#define Dem_Cfg_GetTimeBasedEventTable(Index)                                                       (0u)
#define Dem_Cfg_GetTimeSeriesEntryIndexToNvBlockIndex(Index)                                        (NULL_PTR)
#define Dem_Cfg_GetBaseEntryOfTimeSeriesEntryTable(Index)                                           (NULL_PTR)
#define Dem_Cfg_GetBufferSizeOfTimeSeriesEntryTable(Index)                                          (0u)
#define Dem_Cfg_GetEntryDataOfTimeSeriesEntryTable(Index)                                           (NULL_PTR)
#define Dem_Cfg_GetMaxSnapShotSizeOfTimeSeriesEntryTable(Index)                                     (0u)
#define Dem_Cfg_GetFirstRecordNumberOfTimeSeriesFreezeFrameTable(Index)                             (0u)
#define Dem_Cfg_GetLastRecordNumberOfTimeSeriesFreezeFrameTable(Index)                              (0u)
#define Dem_Cfg_GetRecordTriggerOfTimeSeriesFreezeFrameTable(Index)                                 (NULL_PTR)
#define Dem_Cfg_GetTimeSeriesSamplingProfileTableIdxOfTimeSeriesFreezeFrameTable(Index)             (0u)
#define Dem_Cfg_IsUpdateRecordOfTimeSeriesFreezeFrameTable(Index)                                   ((FALSE) != FALSE)
#define Dem_Cfg_GetTimeSeriesFreezeFrameTableIdxOfTimeSeriesIndirectionTable(Index)                 (0u)
#define Dem_Cfg_GetDataCollectionTableIdxOfTimeSeriesSamplingProfileCalibTable(Index)               (0u)
#define Dem_Cfg_GetPastSamplesOfTimeSeriesSamplingProfileCalibTable(Index)                          (0u)
#define Dem_Cfg_GetSamplingPeriodTicsOfTimeSeriesSamplingProfileCalibTable(Index)                   (0u)
#define Dem_Cfg_GetSamplingProfileDidInfoTableEndIdxOfTimeSeriesSamplingProfileCalibTable(Index)    (0u)
#define Dem_Cfg_GetSamplingProfileDidInfoTableStartIdxOfTimeSeriesSamplingProfileCalibTable(Index)  (0u)
#define Dem_Cfg_IsSamplingProfileDidInfoTableUsedOfTimeSeriesSamplingProfileCalibTable(Index)       ((FALSE) != FALSE)
#define Dem_Cfg_GetRingBufferPtrOfTimeSeriesSamplingProfileTable(Index)                             (NULL_PTR)
#define Dem_Cfg_GetRingBufferSamplesOfTimeSeriesSamplingProfileTable(Index)                         (0u)
#define Dem_Cfg_GetSampleSizeOfTimeSeriesSamplingProfileTable(Index)                                (0u)
#define Dem_Cfg_GetSequentialDidIdOfTimeSeriesSamplingProfileTable(Index)                           (0u)
#define Dem_Cfg_GetTimeSeriesSamplingProfileCalibTableIdxOfTimeSeriesSamplingProfileTable(Index)    (0u)
#define Dem_Cfg_GetTotalSamplesOfTimeSeriesSamplingProfileTable(Index)                              (0u)
#define Dem_Cfg_GetMemoryInfoTableIdxOfUserDefinedOriginTable(Index)                                (0u)
#define Dem_Cfg_IsMemoryInfoTableUsedOfUserDefinedOriginTable(Index)                                ((FALSE) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCGetDeduplicatedDataMacros  Dem_Cfg Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Dem_Cfg_GetClearDTCIndexOfClientTable(Index)                                                0u  /**< 'DEM_CFG_CLEARDTC_INVALID'(=255): no ClearDTC for the Client, else: index in Dem_Cfg_ClearDTCTable[] */
#define Dem_Cfg_GetFilterIndexOfClientTable(Index)                                                  0u  /**< 'DEM_CFG_FILTER_INVALID'(=255): no filter for the Client, else: index in Dem_Cfg_FilterInfoTable[] */
#define Dem_Cfg_GetFreezeFrameIteratorIndexOfClientTable(Index)                                     0u  /**< 'DEM_CFG_FREEZEFRAMEITERATOR_INVALID'(=255): no FreezeFrameIterator for the Client, else: index in Dem_Cfg_FreezeFrameIteratorTable[] */
#define Dem_Cfg_GetNmNodeIdOfClientTable(Index)                                                     J1939NmConf_J1939NmNode_J1939NmNode  /**< 'DEM_CFG_NMNODEID_INVALID'(=65535): no NmNodeId configured for the Client, else: symbolic name value of the J1939Nm/J1939NmConfigSet/J1939NmNode container, that is configured in the J1939Dcm for the Client. */
#define Dem_Cfg_GetReadoutBufferIndexOfClientTable(Index)                                           0u  /**< 'DEM_CFG_READOUTBUFFER_INVALID'(=255): no ReadoutBuffer for the Client, else: index in Dem_Cfg_ReadoutBuffer[] */
#define Dem_Cfg_GetSelectorIndexOfClientTable(Index)                                                0u  /**< 'DEM_CFG_DTCSELECTOR_INVALID'(=255): no selector for the Client, else: index in Dem_Cfg_DTCSelectorTable[] */
#define Dem_Cfg_GetFreezeFrameTableIdxOfCommonDidList(Index)                                        0u  /**< the index of the 1:1 relation pointing to Dem_Cfg_FreezeFrameTable */
#define Dem_Cfg_GetCompatibilityVersion(ConfigDataPtr)                                              Dem_Cfg_GetCompatibilityVersionOfPCConfig(ConfigDataPtr)
#define Dem_Cfg_GetConfigurationId()                                                                Dem_Cfg_GetConfigurationIdOfPCConfig()
#define Dem_Cfg_IsDebounceContinuousOfCounterBasedDebounceTable(Index)                              (((FALSE)) != FALSE)  /**< DemDebounceContinuous of the DemConfigSet/DemDebounceCounterBasedClass */
#define Dem_Cfg_GetDecrementStepSizeOfCounterBasedDebounceTable(Index)                              -20  /**< (-1) * DemDebounceCounterDecrementStepSize of the DemConfigSet/DemDebounceCounterBasedClass */
#define Dem_Cfg_IsEventDebounceBehaviorOfCounterBasedDebounceTable(Index)                           (((FALSE)) != FALSE)  /**< DemDebounceBehavior == DEM_DEBOUNCE_RESET of the DemConfigSet/DemDebounceCounterBasedClass */
#define Dem_Cfg_GetFailedThresholdOfCounterBasedDebounceTable(Index)                                127  /**< DemDebounceCounterFailedThreshold of the DemConfigSet/DemDebounceCounterBasedClass */
#define Dem_Cfg_GetIncrementStepSizeOfCounterBasedDebounceTable(Index)                              20  /**< DemDebounceCounterIncrementStepSize of the DemConfigSet/DemDebounceCounterBasedClass */
#define Dem_Cfg_IsJumpDownOfCounterBasedDebounceTable(Index)                                        (((TRUE)) != FALSE)  /**< DemDebounceCounterJumpDown of the DemConfigSet/DemDebounceCounterBasedClass */
#define Dem_Cfg_GetJumpDownValueOfCounterBasedDebounceTable(Index)                                  0  /**< DemDebounceCounterJumpDownValue of the DemConfigSet/DemDebounceCounterBasedClass */
#define Dem_Cfg_IsJumpUpOfCounterBasedDebounceTable(Index)                                          (((FALSE)) != FALSE)  /**< DemDebounceCounterJumpUp of the DemConfigSet/DemDebounceCounterBasedClass */
#define Dem_Cfg_GetJumpUpValueOfCounterBasedDebounceTable(Index)                                    0  /**< DemDebounceCounterJumpUpValue of the DemConfigSet/DemDebounceCounterBasedClass */
#define Dem_Cfg_GetMaskedBitsOfCounterBasedDebounceTable(Index)                                     0x02u  /**< contains bitcoded the boolean data of Dem_Cfg_DebounceContinuousOfCounterBasedDebounceTable, Dem_Cfg_EventDebounceBehaviorOfCounterBasedDebounceTable, Dem_Cfg_JumpDownOfCounterBasedDebounceTable, Dem_Cfg_JumpUpOfCounterBasedDebounceTable */
#define Dem_Cfg_GetPassedThresholdOfCounterBasedDebounceTable(Index)                                -128  /**< DemDebounceCounterPassedThreshold of the DemConfigSet/DemDebounceCounterBasedClass */
#define Dem_Cfg_GetOpCycleTypeOfCycleIdTable(Index)                                                 DEM_CFG_OPCYC_POWER  /**< DemOperationCycleType of the DemOperationCycle: [DEM_CFG_OPCYC_IGNITION, DEM_CFG_OPCYC_OBD_DCY, DEM_CFG_OPCYC_OTHER, DEM_CFG_OPCYC_POWER, DEM_CFG_OPCYC_TIME, DEM_CFG_OPCYC_WARMUP, DEM_CFG_OPCYC_IGNITION_HYBRID, DEM_CFG_OPCYC_AGING] */
#define Dem_Cfg_GetDTCStatusAvailabilityMaskInVariant()                                             Dem_Cfg_GetDTCStatusAvailabilityMaskInVariantOfPCConfig()
#define Dem_Cfg_IsDataElementTableCol2ElmtIndDataElementTableCol2ElmtIndUsedOfDataCollectionTable(Index) (((boolean)(Dem_Cfg_GetDataElementTableCol2ElmtIndDataElementTableCol2ElmtIndStartIdxOfDataCollectionTable(Index) != DEM_CFG_NO_DATAELEMENTTABLECOL2ELMTINDDATAELEMENTTABLECOL2ELMTINDSTARTIDXOFDATACOLLECTIONTABLE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd */
#define Dem_Cfg_GetTriggerOfDataCollectionTable(Index)                                              DEM_CFG_TRIGGER_NONE  /**< Trigger for storage and update of extended data records */
#define Dem_Cfg_IsUpdateOfDataCollectionTable(Index)                                                (((boolean)(Dem_Cfg_GetDataElementTableCol2ElmtIndDataElementTableCol2ElmtIndEndIdxOfDataCollectionTable(Index) < 3u)) != FALSE)
#define Dem_Cfg_GetDataCollectionTableErec2CollInd(Index)                                           ((Dem_Cfg_DataCollectionTableErec2CollIndType)((((Dem_Cfg_DataCollectionTableErec2CollIndType)(Index)) + 1u)))  /**< the indexes of the 1:1 sorted relation pointing to Dem_Cfg_DataCollectionTable */
#define Dem_Cfg_IsDataIsStoredInNVOfDataElementTable(Index)                                         (((boolean)(Dem_Cfg_GetElementSizeOfDataElementTable(Index) != 0u)) != FALSE)
#define Dem_Cfg_IsCounterBasedDebounceTableUsedOfDebounceIndirectionTable(Index)                    (((boolean)(Dem_Cfg_GetCounterBasedDebounceTableIdxOfDebounceIndirectionTable(Index) != DEM_CFG_NO_COUNTERBASEDDEBOUNCETABLEIDXOFDEBOUNCEINDIRECTIONTABLE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Dem_Cfg_CounterBasedDebounceTable */
#define Dem_Cfg_GetDtcSeverityOfDtcCalibTable(Index)                                                0u
#define Dem_Cfg_IsAgingAllowedOfDtcInvariantDataTable(Index)                                        (((boolean)(Dem_Cfg_GetFreezeFrameTableStdFFIdxOfDtcInvariantDataTable(Index) == 1u)) != FALSE)  /**< DemAgingAllowed of the DemEventParameter/DemEventClass */
#define Dem_Cfg_GetFreezeFrameTableSecondStdFFIdxOfDtcInvariantDataTable(Index)                     0u  /**< the index of the 1:1 relation pointing to Dem_Cfg_FreezeFrameTable */
#define Dem_Cfg_GetEventSignificanceOfDtcTable(Index)                                               DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFDTCTABLE  /**< DemEventSignificance parameter of the DemEventParameter/DemEventClass */
#define Dem_Cfg_IsFreezeFrameNumIndirectionTableUsedOfDtcTable(Index)                               (((boolean)(Dem_Cfg_GetFreezeFrameNumIndirectionTableIdxOfDtcTable(Index) != DEM_CFG_NO_FREEZEFRAMENUMINDIRECTIONTABLEIDXOFDTCTABLE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Dem_Cfg_FreezeFrameNumIndirectionTable */
#define Dem_Cfg_IsImmediateNvStorageOfDtcTable(Index)                                               (((FALSE)) != FALSE)
#define Dem_Cfg_GetJ1939DtcOfDtcTable(Index)                                                        16777215u
#define Dem_Cfg_IsJ1939NodeIdIndUsedOfDtcTable(Index)                                               (((boolean)(Dem_Cfg_GetJ1939NodeIdIndStartIdxOfDtcTable(Index) != DEM_CFG_NO_J1939NODEIDINDSTARTIDXOFDTCTABLE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Dem_Cfg_J1939NodeIdInd */
#define Dem_Cfg_GetIndexOfEnableConditionGroupTable(Index)                                          0u  /**< Dummy - contains always the index of this element (self) */
#define Dem_Cfg_GetEnableConditionGroupTableInd(Index)                                              0u  /**< the indexes of the 1:1 sorted relation pointing to Dem_Cfg_EnableConditionGroupTable */
#define Dem_Cfg_IsFulfilledAtInitOfEnableConditionInitTable(Index)                                  (((TRUE)) != FALSE)  /**< Initial value: 'FALSE' condition is not fulfilled, 'TRUE' condition is fulfilled */
#define Dem_Cfg_GetEnableConditionGroupTableIndEndIdxOfEnableConditionTable(Index)                  1u  /**< the end index of the 0:n relation pointing to Dem_Cfg_EnableConditionGroupTableInd */
#define Dem_Cfg_GetEnableConditionGroupTableIndStartIdxOfEnableConditionTable(Index)                0u  /**< the start index of the 0:n relation pointing to Dem_Cfg_EnableConditionGroupTableInd */
#define Dem_Cfg_IsEnableConditionGroupTableIndUsedOfEnableConditionTable(Index)                     (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Dem_Cfg_EnableConditionGroupTableInd */
#define Dem_Cfg_GetEndIdxOfDemDidClassInDataCollectionTable()                                       Dem_Cfg_GetEndIdxOfDemDidClassInDataCollectionTableOfPCConfig()
#define Dem_Cfg_IsEventAvailableDefault(Index)                                                      (((TRUE)) != FALSE)
#define Dem_Cfg_GetEventFailureCycleCounterThresholdOfEventCalibTable(Index)                        0u  /**< DemEventFailureCycleCounterThreshold of the DemEventParameter/DemEventClass, '0': is also default for unset parameter */
#define Dem_Cfg_GetOperationCycleIdOfEventCalibTable(Index)                                         DemConf_DemOperationCycle_Power_On_Off  /**< DemOperationCycle (ID) referenced by DemEventParameter/DemEventClass/DemOperationCycleRef */
#define Dem_Cfg_IsDebounceCounterStorageOfEventPrecompileDataTable(Index)                           (((FALSE)) != FALSE)  /**< DemDebounceCounterStorage of the DemDebounceCounterBasedClass referenced by the event via DemDebounceAlgorithmClass/DemDebounceCounterBased/DemDebounceCounterBasedClassRef; FALSE if the event has no DemDebounceCounterBasedClassRef */
#define Dem_Cfg_GetEventKindOfEventPrecompileDataTable(Index)                                       DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTPRECOMPILEDATATABLE  /**< DemEventKind of the DemEventParameter */
#define Dem_Cfg_IsEventLatchTFOfEventPrecompileDataTable(Index)                                     (((FALSE)) != FALSE)  /**< DemEventLatchTestFailed of the DemEventParameter */
#define Dem_Cfg_IsEventStatusChangedUsedOfEventPrecompileDataTable(Index)                           (((boolean)(Dem_Cfg_GetEventStatusChangedStartIdxOfEventPrecompileDataTable(Index) != DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTPRECOMPILEDATATABLE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Dem_Cfg_EventStatusChanged */
#define Dem_Cfg_GetMaskedBitsOfEventPrecompileDataTable(Index)                                      0x00u  /**< contains bitcoded the boolean data of Dem_Cfg_DebounceCounterStorageOfEventPrecompileDataTable, Dem_Cfg_EventLatchTFOfEventPrecompileDataTable */
#define Dem_Cfg_GetSatelliteEventIdxOfEventPrecompileDataTable(Index)                               ((Dem_Cfg_SatelliteEventIdxOfEventPrecompileDataTableType)((Index)))  /**< Index of this event in the satellite's RAM buffers Dem_Cfg_SatelliteInfoNN.SatelliteData[] and Dem_Cfg_SatelliteInfoNN.SatelliteExtendedData[]. */
#define Dem_Cfg_GetSatelliteInfoIdxOfEventPrecompileDataTable(Index)                                0u  /**< the index of the 1:1 relation pointing to Dem_Cfg_SatelliteInfo */
#define Dem_Cfg_GetEventPrecompileDataTableInd(Index)                                               ((Dem_Cfg_EventPrecompileDataTableIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Dem_Cfg_EventPrecompileDataTable */
#define Dem_Cfg_GetEventCalibTableIdxOfEventTable(Index)                                            0u  /**< the index of the 1:1 relation pointing to Dem_Cfg_EventCalibTable */
#define Dem_Cfg_GetEventDestinationOfEventTable(Index)                                              DEM_CFG_MEMORYID_PRIMARY  /**< Memory Destination of the referenced DTC */
#define Dem_Cfg_GetEventInvariantDataTableIdxOfEventTable(Index)                                    ((Dem_Cfg_EventInvariantDataTableIdxOfEventTableType)((Index)))  /**< the index of the 1:1 relation pointing to Dem_Cfg_EventInvariantDataTable */
#define Dem_Cfg_IsOBDVisibilityDelayedUntilDcyQualificationOfEventTable(Index)                      (((FALSE)) != FALSE)  /**< DemOBDVisibilityDelayedUntilDcyQualification of the DemEventParameter */
#define Dem_Cfg_GetDataCollectionTableErec2CollIndEndIdxOfExtendedDataRecordTable(Index)            2u  /**< the end index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableErec2CollInd */
#define Dem_Cfg_GetDataCollectionTableErec2CollIndStartIdxOfExtendedDataRecordTable(Index)          0u  /**< the start index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableErec2CollInd */
#define Dem_Cfg_IsDataCollectionTableErec2CollIndUsedOfExtendedDataRecordTable(Index)               (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Dem_Cfg_DataCollectionTableErec2CollInd */
#define Dem_Cfg_IsDataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndUsedOfExtendedDataTable(Index) (((boolean)(Dem_Cfg_GetDataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndStartIdxOfExtendedDataTable(Index) != DEM_CFG_NO_DATACOLLECTIONTABLEEDR2COLLINDDATACOLLECTIONTABLEEDR2COLLINDSTARTIDXOFEXTENDEDDATATABLE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd */
#define Dem_Cfg_GetMaxRecordSizeOfExtendedDataTable(Index)                                          ((Dem_Cfg_MaxRecordSizeOfExtendedDataTableType)((Index)))
#define Dem_Cfg_GetFinalMagicNumber(ConfigDataPtr)                                                  Dem_Cfg_GetFinalMagicNumberOfPCConfig(ConfigDataPtr)
#define Dem_Cfg_IsFreezeFrameNumTableUsedOfFreezeFrameNumIndirectionTable(Index)                    (((boolean)(Dem_Cfg_GetFreezeFrameNumTableStartIdxOfFreezeFrameNumIndirectionTable(Index) != DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFFREEZEFRAMENUMINDIRECTIONTABLE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Dem_Cfg_FreezeFrameNumTable */
#define Dem_Cfg_GetFFNumberOfFreezeFrameNumTable(Index)                                             1u
#define Dem_Cfg_GetFFTriggerOfFreezeFrameNumTable(Index)                                            DEM_CFG_TRIGGER_TESTFAILED
#define Dem_Cfg_IsFFUpdateOfFreezeFrameNumTable(Index)                                              (((TRUE)) != FALSE)
#define Dem_Cfg_IsIsGlobalOfFreezeFrameNumTable(Index)                                              (((FALSE)) != FALSE)
#define Dem_Cfg_GetMaskedBitsOfFreezeFrameNumTable(Index)                                           0x02u  /**< contains bitcoded the boolean data of Dem_Cfg_FFUpdateOfFreezeFrameNumTable, Dem_Cfg_IsGlobalOfFreezeFrameNumTable */
#define Dem_Cfg_IsDataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndUsedOfFreezeFrameTable(Index) (((boolean)(Dem_Cfg_GetDataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndStartIdxOfFreezeFrameTable(Index) != DEM_CFG_NO_DATACOLLECTIONTABLEFFM2COLLINDDATACOLLECTIONTABLEFFM2COLLINDSTARTIDXOFFREEZEFRAMETABLE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd */
#define Dem_Cfg_GetDataElementTableIdxOfGeneralObdInput(Index)                                      0u  /**< the index of the 1:1 relation pointing to Dem_Cfg_DataElementTable */
#define Dem_Cfg_GetGlobalObdRequirements()                                                          Dem_Cfg_GetGlobalObdRequirementsOfPCConfig()
#define Dem_Cfg_GetGlobalSeverityMask()                                                             Dem_Cfg_GetGlobalSeverityMaskOfPCConfig()
#define Dem_Cfg_GetFreezeFrameTableIdxOfGlobalSnapshotRecord(Index)                                 0u  /**< the index of the 1:1 relation pointing to Dem_Cfg_FreezeFrameTable */
#define Dem_Cfg_GetInitDataHashCode(ConfigDataPtr)                                                  Dem_Cfg_GetInitDataHashCodeOfPCConfig(ConfigDataPtr)
#define Dem_Cfg_GetJ1939NodeIndicatorAvailability(Index)                                            0xFFu  /**< Bitmask to calculate the readiness: if indicator is not available, use for MIL: (0x03U &lt;&lt; 6), RSL: (0x03U &lt;&lt; 4), AWL: (0x03U &lt;&lt; 2), PL: (0x03U &lt;&lt; 0), or 0x00 else. Sequence of elements is identical to J1939NodeId[] XXXXXXXDem_Cfg_J1939NodeId[] */
#define Dem_Cfg_GetMaxNumberEventEntryOBDFreezeFrame()                                              Dem_Cfg_GetMaxNumberEventEntryOBDFreezeFrameOfPCConfig()
#define Dem_Cfg_GetChronoPtrOfMemoryInfoTable(Index)                                                &Dem_Cfg_PrimaryChronology[0]  /**< Pointer to the chronology list of the memory if available and null pointer otherwise */
#define Dem_Cfg_GetCustomTriggerTranslatedMemoryIdOfMemoryInfoTable(Index)                          DEM_CFG_MEMORYID_INVALID  /**< The idx of the custom trigger memory for each event memory in this table */
#define Dem_Cfg_GetEnableConditionGroupTableControlDtcSettingGroupIdxOfMemoryInfoTable(Index)       0u  /**< the index of the 0:1 relation pointing to Dem_Cfg_EnableConditionGroupTable */
#define Dem_Cfg_IsEnableConditionGroupTableControlDtcSettingGroupUsedOfMemoryInfoTable(Index)       (((TRUE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Dem_Cfg_EnableConditionGroupTable */
#define Dem_Cfg_GetEventMemoryEntryStorageTriggerOfMemoryInfoTable(Index)                           DEM_MEMORY_STORAGE_TRIGGER_FAILED  /**< Event memory entry storage trigger */
#define Dem_Cfg_GetFirstEntryIndexOfMemoryInfoTable(Index)                                          DEM_CFG_ENTRY_PRIMARY_START_INDEX  /**< First entry index belonging to the memory */
#define Dem_Cfg_GetFirstEventOfMemoryInfoTable(Index)                                               1u  /**< First event Id belonging to the memory */
#define Dem_Cfg_GetIndividualERecSizeOfMemoryInfoTable(Index)                                       0u  /**< Max size of each extended data record in the memory */
#define Dem_Cfg_GetIndividualSRecSizeOfMemoryInfoTable(Index)                                       13u  /**< Max size of each snapshot record in the memory */
#define Dem_Cfg_GetLastEventOfMemoryInfoTable(Index)                                                62u  /**< Last event Id belonging to the memory */
#define Dem_Cfg_GetMaxNumberTimeSeriesSetsOfMemoryInfoTable(Index)                                  0u  /**< Max Number of Time Series Sets */
#define Dem_Cfg_GetMaxSizeOfMemoryInfoTable(Index)                                                  10u  /**< Maximum number of memory entries or slots for the memory */
#define Dem_Cfg_GetSRecNumTypeOfMemoryInfoTable(Index)                                              DEM_CFG_MEMORY_FF_RECNUM_CONFIGURED  /**< Type of assigning snapshot record numbers */
#define Dem_Cfg_IsTimeSeriesFifoSupportOfMemoryInfoTable(Index)                                     (((FALSE)) != FALSE)  /**< Time Series Memory Fifo Support */
#define Dem_Cfg_GetTimeSeriesSetsRecNumOffsetOfMemoryInfoTable(Index)                               0u  /**< Time Series Sets Record Number Offset */
#define Dem_Cfg_GetTimeSeriesTranslatedMemoryIdOfMemoryInfoTable(Index)                             DEM_CFG_MEMORYID_INVALID  /**< The idx of the time series memory for each event memory in this table */
#define Dem_Cfg_GetMARIndexOfMonitorActivityRatioTable(Index)                                       65535u  /**< Monitor Activity Ratio Index (event based) */
#define Dem_Cfg_GetSMARIndexOfMonitorActivityRatioTable(Index)                                      65535u  /**< Stored Monitor Activity Ratio Index (DTC based) */
#define Dem_Cfg_GetNoDtcConfigured()                                                                Dem_Cfg_GetNoDtcConfiguredOfPCConfig()
#define Dem_Cfg_GetPIDF501ReadinessSupportedAndCompletedEnforcementMask()                           Dem_Cfg_GetPIDF501ReadinessSupportedAndCompletedEnforcementMaskOfPCConfig()
#define Dem_Cfg_GetPIDF501ReadinessUnsupportedEnforcementMask()                                     Dem_Cfg_GetPIDF501ReadinessUnsupportedEnforcementMaskOfPCConfig()
#define Dem_Cfg_IsPendingEvaluatedForConfirmedAndActiveConditionInVariant()                         Dem_Cfg_IsPendingEvaluatedForConfirmedAndActiveConditionInVariantOfPCConfig()
#define Dem_Cfg_GetApplicationIdOfSatelliteInfo(Index)                                              INVALID_OSAPPLICATION  /**< Partition (OsApplication identifier) of the satellite. */
#define Dem_Cfg_GetEventCountOfSatelliteInfo(Index)                                                 63u  /**< Satellite individual size of the monitor/event data RAM buffer */
#define Dem_Cfg_GetEventPrecompileDataTableIndEndIdxOfSatelliteInfo(Index)                          63u  /**< the end index of the 0:n relation pointing to Dem_Cfg_EventPrecompileDataTableInd */
#define Dem_Cfg_GetEventPrecompileDataTableIndStartIdxOfSatelliteInfo(Index)                        0u  /**< the start index of the 0:n relation pointing to Dem_Cfg_EventPrecompileDataTableInd */
#define Dem_Cfg_IsEventPrecompileDataTableIndUsedOfSatelliteInfo(Index)                             (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Dem_Cfg_EventPrecompileDataTableInd */
#define Dem_Cfg_GetSatelliteDataOfSatelliteInfo(Index)                                              &Dem_Cfg_SatelliteInfoInvalid_OsApplication.SatelliteData[0]  /**< Satellite individual RAM buffer 1 for the monitor/event data */
#define Dem_Cfg_GetSatelliteStatusOfSatelliteInfo(Index)                                            &Dem_Cfg_SatelliteInfoInvalid_OsApplication.SatelliteStatus  /**< Satellite individual RAM buffer for the monitor/event status */
#define Dem_Cfg_GetSizeOfCalibrationObdDtcTable()                                                   Dem_Cfg_GetSizeOfCalibrationObdDtcTableOfPCConfig()
#define Dem_Cfg_GetSizeOfCallbackClearEventAllowed()                                                Dem_Cfg_GetSizeOfCallbackClearEventAllowedOfPCConfig()
#define Dem_Cfg_GetSizeOfCallbackDtcStatusChanged()                                                 Dem_Cfg_GetSizeOfCallbackDtcStatusChangedOfPCConfig()
#define Dem_Cfg_GetSizeOfCallbackGetFdc()                                                           Dem_Cfg_GetSizeOfCallbackGetFdcOfPCConfig()
#define Dem_Cfg_GetSizeOfCallbackJ1939DtcStatusChanged()                                            Dem_Cfg_GetSizeOfCallbackJ1939DtcStatusChangedOfPCConfig()
#define Dem_Cfg_GetSizeOfClearDTCTable()                                                            Dem_Cfg_GetSizeOfClearDTCTableOfPCConfig()
#define Dem_Cfg_GetSizeOfClearDtcNotificationFinishTable()                                          Dem_Cfg_GetSizeOfClearDtcNotificationFinishTableOfPCConfig()
#define Dem_Cfg_GetSizeOfClearDtcNotificationStartTable()                                           Dem_Cfg_GetSizeOfClearDtcNotificationStartTableOfPCConfig()
#define Dem_Cfg_GetSizeOfClientTable()                                                              Dem_Cfg_GetSizeOfClientTableOfPCConfig()
#define Dem_Cfg_GetSizeOfCounterBasedDebounceTable()                                                Dem_Cfg_GetSizeOfCounterBasedDebounceTableOfPCConfig()
#define Dem_Cfg_GetSizeOfCustomTimeSeriesFreezeFrameTable()                                         Dem_Cfg_GetSizeOfCustomTimeSeriesFreezeFrameTableOfPCConfig()
#define Dem_Cfg_GetSizeOfCustomTriggerEntryIndexToNvBlockIndex()                                    Dem_Cfg_GetSizeOfCustomTriggerEntryIndexToNvBlockIndexOfPCConfig()
#define Dem_Cfg_GetSizeOfCustomTriggerEntryPtr()                                                    Dem_Cfg_GetSizeOfCustomTriggerEntryPtrOfPCConfig()
#define Dem_Cfg_GetSizeOfDTCSelectorTable()                                                         Dem_Cfg_GetSizeOfDTCSelectorTableOfPCConfig()
#define Dem_Cfg_GetSizeOfDataCollectionTable()                                                      Dem_Cfg_GetSizeOfDataCollectionTableOfPCConfig()
#define Dem_Cfg_GetSizeOfDataElementTable()                                                         Dem_Cfg_GetSizeOfDataElementTableOfPCConfig()
#define Dem_Cfg_GetSizeOfDtcGroupMask()                                                             Dem_Cfg_GetSizeOfDtcGroupMaskOfPCConfig()
#define Dem_Cfg_GetSizeOfDtcTable()                                                                 Dem_Cfg_GetSizeOfDtcTableOfPCConfig()
#define Dem_Cfg_GetSizeOfDtrStatus()                                                                Dem_Cfg_GetSizeOfDtrStatusOfPCConfig()
#define Dem_Cfg_GetSizeOfDtrTable()                                                                 Dem_Cfg_GetSizeOfDtrTableOfPCConfig()
#define Dem_Cfg_GetSizeOfEnableConditionFulfilled()                                                 Dem_Cfg_GetSizeOfEnableConditionFulfilledOfPCConfig()
#define Dem_Cfg_GetSizeOfEnableConditionGroupCounter()                                              Dem_Cfg_GetSizeOfEnableConditionGroupCounterOfPCConfig()
#define Dem_Cfg_GetSizeOfEnableConditionGroupState()                                                Dem_Cfg_GetSizeOfEnableConditionGroupStateOfPCConfig()
#define Dem_Cfg_GetSizeOfEnableConditionGroupTable()                                                Dem_Cfg_GetSizeOfEnableConditionGroupTableOfPCConfig()
#define Dem_Cfg_GetSizeOfEnableConditionTable()                                                     Dem_Cfg_GetSizeOfEnableConditionTableOfPCConfig()
#define Dem_Cfg_GetSizeOfEventCycleStatus()                                                         Dem_Cfg_GetSizeOfEventCycleStatusOfPCConfig()
#define Dem_Cfg_GetSizeOfEventDataChanged()                                                         Dem_Cfg_GetSizeOfEventDataChangedOfPCConfig()
#define Dem_Cfg_GetSizeOfEventDataCommitNumber()                                                    Dem_Cfg_GetSizeOfEventDataCommitNumberOfPCConfig()
#define Dem_Cfg_GetSizeOfEventEntryIndexToNvBlockIndex()                                            Dem_Cfg_GetSizeOfEventEntryIndexToNvBlockIndexOfPCConfig()
#define Dem_Cfg_GetSizeOfEventEntryInfoTable()                                                      Dem_Cfg_GetSizeOfEventEntryInfoTableOfPCConfig()
#define Dem_Cfg_GetSizeOfEventIndicatorData()                                                       Dem_Cfg_GetSizeOfEventIndicatorDataOfPCConfig()
#define Dem_Cfg_GetSizeOfEventInternalStatus()                                                      Dem_Cfg_GetSizeOfEventInternalStatusOfPCConfig()
#define Dem_Cfg_GetSizeOfEventStatusChanged()                                                       Dem_Cfg_GetSizeOfEventStatusChangedOfPCConfig()
#define Dem_Cfg_GetSizeOfEventTable()                                                               Dem_Cfg_GetSizeOfEventTableOfPCConfig()
#define Dem_Cfg_GetSizeOfExtendedDataRecordIteratorTable()                                          Dem_Cfg_GetSizeOfExtendedDataRecordIteratorTableOfPCConfig()
#define Dem_Cfg_GetSizeOfFilterInfoTable()                                                          Dem_Cfg_GetSizeOfFilterInfoTableOfPCConfig()
#define Dem_Cfg_GetSizeOfFreezeFrameIteratorTable()                                                 Dem_Cfg_GetSizeOfFreezeFrameIteratorTableOfPCConfig()
#define Dem_Cfg_GetSizeOfFreezeFrameTable()                                                         Dem_Cfg_GetSizeOfFreezeFrameTableOfPCConfig()
#define Dem_Cfg_GetSizeOfGlobalSnapshotRecord()                                                     Dem_Cfg_GetSizeOfGlobalSnapshotRecordOfPCConfig()
#define Dem_Cfg_GetSizeOfIndicatorAttributeTable()                                                  Dem_Cfg_GetSizeOfIndicatorAttributeTableOfPCConfig()
#define Dem_Cfg_GetSizeOfIndicatorEventCounters()                                                   Dem_Cfg_GetSizeOfIndicatorEventCountersOfPCConfig()
#define Dem_Cfg_GetSizeOfInitMonitorForEvent()                                                      Dem_Cfg_GetSizeOfInitMonitorForEventOfPCConfig()
#define Dem_Cfg_GetSizeOfInitMonitorsForFunc()                                                      Dem_Cfg_GetSizeOfInitMonitorsForFuncOfPCConfig()
#define Dem_Cfg_GetSizeOfJ1939SpnsInExpandedFreezeFrameTable()                                      Dem_Cfg_GetSizeOfJ1939SpnsInExpandedFreezeFrameTableOfPCConfig()
#define Dem_Cfg_GetSizeOfMemoryCurrentCount()                                                       Dem_Cfg_GetSizeOfMemoryCurrentCountOfPCConfig()
#define Dem_Cfg_GetSizeOfMemoryInfoTable()                                                          Dem_Cfg_GetSizeOfMemoryInfoTableOfPCConfig()
#define Dem_Cfg_GetSizeOfMemoryStatus()                                                             Dem_Cfg_GetSizeOfMemoryStatusOfPCConfig()
#define Dem_Cfg_GetSizeOfMonitorActivityRatioTable()                                                Dem_Cfg_GetSizeOfMonitorActivityRatioTableOfPCConfig()
#define Dem_Cfg_GetSizeOfObdIumprUpdatePending()                                                    Dem_Cfg_GetSizeOfObdIumprUpdatePendingOfPCConfig()
#define Dem_Cfg_GetSizeOfPrestorageIndex()                                                          Dem_Cfg_GetSizeOfPrestorageIndexOfPCConfig()
#define Dem_Cfg_GetSizeOfPrimaryChronology()                                                        Dem_Cfg_GetSizeOfPrimaryChronologyOfPCConfig()
#define Dem_Cfg_GetSizeOfRatioIdTable()                                                             Dem_Cfg_GetSizeOfRatioIdTableOfPCConfig()
#define Dem_Cfg_GetSizeOfReadoutBuffer()                                                            Dem_Cfg_GetSizeOfReadoutBufferOfPCConfig()
#define Dem_Cfg_GetSizeOfReportedEventsOfFilter()                                                   Dem_Cfg_GetSizeOfReportedEventsOfFilterOfPCConfig()
#define Dem_Cfg_GetSizeOfSatelliteInfo()                                                            Dem_Cfg_GetSizeOfSatelliteInfoOfPCConfig()
#define Dem_Cfg_GetSizeOfSpnToEventsWithRatioTable()                                                Dem_Cfg_GetSizeOfSpnToEventsWithRatioTableOfPCConfig()
#define Dem_Cfg_GetSizeOfStartIdx500miDenRatioTable()                                               Dem_Cfg_GetSizeOfStartIdx500miDenRatioTableOfPCConfig()
#define Dem_Cfg_GetSizeOfStorageConditionFulfilled()                                                Dem_Cfg_GetSizeOfStorageConditionFulfilledOfPCConfig()
#define Dem_Cfg_GetSizeOfStorageConditionGroupCounter()                                             Dem_Cfg_GetSizeOfStorageConditionGroupCounterOfPCConfig()
#define Dem_Cfg_GetSizeOfStorageConditionGroupTable()                                               Dem_Cfg_GetSizeOfStorageConditionGroupTableOfPCConfig()
#define Dem_Cfg_GetSizeOfStorageConditionTable()                                                    Dem_Cfg_GetSizeOfStorageConditionTableOfPCConfig()
#define Dem_Cfg_GetSizeOfSupportedMidsTable()                                                       Dem_Cfg_GetSizeOfSupportedMidsTableOfPCConfig()
#define Dem_Cfg_GetSizeOfTimeBasedDebounceTable()                                                   Dem_Cfg_GetSizeOfTimeBasedDebounceTableOfPCConfig()
#define Dem_Cfg_GetSizeOfTimeBasedEventTable()                                                      Dem_Cfg_GetSizeOfTimeBasedEventTableOfPCConfig()
#define Dem_Cfg_GetSizeOfTimeSeriesEntryIndexToNvBlockIndex()                                       Dem_Cfg_GetSizeOfTimeSeriesEntryIndexToNvBlockIndexOfPCConfig()
#define Dem_Cfg_GetSizeOfTimeSeriesEntryTable()                                                     Dem_Cfg_GetSizeOfTimeSeriesEntryTableOfPCConfig()
#define Dem_Cfg_GetSizeOfTimeSeriesSamplingProfileTable()                                           Dem_Cfg_GetSizeOfTimeSeriesSamplingProfileTableOfPCConfig()
#define Dem_Cfg_GetStartIdxOfDemDidClassInDataCollectionTable()                                     Dem_Cfg_GetStartIdxOfDemDidClassInDataCollectionTableOfPCConfig()
#define Dem_Cfg_IsUseOBDIIOrOBDonUDSInVariant()                                                     Dem_Cfg_IsUseOBDIIOrOBDonUDSInVariantOfPCConfig()
#define Dem_Cfg_IsUseOBDonUDSInVariant()                                                            Dem_Cfg_IsUseOBDonUDSInVariantOfPCConfig()
#define Dem_Cfg_IsUsePermanentInVariant()                                                           Dem_Cfg_IsUsePermanentInVariantOfPCConfig()
#define Dem_Cfg_IsUseReadinessSupportAndCompletenessEnforcementMaskInVariant()                      Dem_Cfg_IsUseReadinessSupportAndCompletenessEnforcementMaskInVariantOfPCConfig()
#define Dem_Cfg_IsUseReadinessUnsupportedEnforcementBitMaskInVariant()                              Dem_Cfg_IsUseReadinessUnsupportedEnforcementBitMaskInVariantOfPCConfig()
#define Dem_Cfg_IsUseWWHOBDInVariant()                                                              Dem_Cfg_IsUseWWHOBDInVariantOfPCConfig()
#define Dem_Cfg_IsUseZEVonUDSInVariant()                                                            Dem_Cfg_IsUseZEVonUDSInVariantOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCSetDataMacros  Dem_Cfg Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Dem_Cfg_SetAdminData(Value)                                                                 (*(Dem_Cfg_GetAdminDataOfPCConfig())) = (Value)
#define Dem_Cfg_SetAgingData(Value)                                                                 
#define Dem_Cfg_SetCalibrationErrorRegister(Value)                                                  (*(Dem_Cfg_GetCalibrationErrorRegisterOfPCConfig())) = (Value)
#define Dem_Cfg_SetClearDTCTable(Index, Value)                                                      Dem_Cfg_GetClearDTCTableOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetCommitBuffer(Value)                                                              (*(Dem_Cfg_GetCommitBufferOfPCConfig())) = (Value)
#define Dem_Cfg_SetCycleCounterData(Value)                                                          
#define Dem_Cfg_SetDTCSelectorTable(Index, Value)                                                   Dem_Cfg_GetDTCSelectorTableOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetDebounceData(Value)                                                              
#define Dem_Cfg_SetDtrData(Value)                                                                   
#define Dem_Cfg_SetDtrStatus(Index, Value)                                                          
#define Dem_Cfg_SetEnableConditionFulfilled(Index, Value)                                           Dem_Cfg_GetEnableConditionFulfilledOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetEnableConditionGroupCounter(Index, Value)                                        Dem_Cfg_GetEnableConditionGroupCounterOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetEnableConditionGroupState(Index, Value)                                          Dem_Cfg_GetEnableConditionGroupStateOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetEventAvailableData(Value)                                                        
#define Dem_Cfg_SetEventCycleStatus(Index, Value)                                                   
#define Dem_Cfg_SetEventDataCommitNumber(Index, Value)                                              Dem_Cfg_GetEventDataCommitNumberOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetEventInternalStatus(Index, Value)                                                Dem_Cfg_GetEventInternalStatusOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetExtendedDataRecordIteratorTable(Index, Value)                                    Dem_Cfg_GetExtendedDataRecordIteratorTableOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetFilterInfoTable(Index, Value)                                                    Dem_Cfg_GetFilterInfoTableOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetFreezeFrameData(Value)                                                           
#define Dem_Cfg_SetFreezeFrameIteratorTable(Index, Value)                                           Dem_Cfg_GetFreezeFrameIteratorTableOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetIndicatorData(Value)                                                             
#define Dem_Cfg_SetIndicatorEventCounters(Index, Value)                                             
#define Dem_Cfg_SetMemoryCurrentCount(Index, Value)                                                 Dem_Cfg_GetMemoryCurrentCountOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetMemoryStatus(Index, Value)                                                       Dem_Cfg_GetMemoryStatusOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetMirrorData(Value)                                                                
#define Dem_Cfg_SetObdIumprData(Value)                                                              
#define Dem_Cfg_SetObdIumprUpdatePending(Index, Value)                                              
#define Dem_Cfg_SetPermanentData(Value)                                                             
#define Dem_Cfg_SetPrestorage(Value)                                                                
#define Dem_Cfg_SetPrestorageIndex(Index, Value)                                                    
#define Dem_Cfg_SetPrimaryChronology(Index, Value)                                                  Dem_Cfg_GetPrimaryChronologyOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetPrimaryEntry_0(Value)                                                            (*(Dem_Cfg_GetPrimaryEntry_0OfPCConfig())) = (Value)
#define Dem_Cfg_SetPrimaryEntry_1(Value)                                                            (*(Dem_Cfg_GetPrimaryEntry_1OfPCConfig())) = (Value)
#define Dem_Cfg_SetPrimaryEntry_2(Value)                                                            (*(Dem_Cfg_GetPrimaryEntry_2OfPCConfig())) = (Value)
#define Dem_Cfg_SetPrimaryEntry_3(Value)                                                            (*(Dem_Cfg_GetPrimaryEntry_3OfPCConfig())) = (Value)
#define Dem_Cfg_SetPrimaryEntry_4(Value)                                                            (*(Dem_Cfg_GetPrimaryEntry_4OfPCConfig())) = (Value)
#define Dem_Cfg_SetPrimaryEntry_5(Value)                                                            (*(Dem_Cfg_GetPrimaryEntry_5OfPCConfig())) = (Value)
#define Dem_Cfg_SetPrimaryEntry_6(Value)                                                            (*(Dem_Cfg_GetPrimaryEntry_6OfPCConfig())) = (Value)
#define Dem_Cfg_SetPrimaryEntry_7(Value)                                                            (*(Dem_Cfg_GetPrimaryEntry_7OfPCConfig())) = (Value)
#define Dem_Cfg_SetPrimaryEntry_8(Value)                                                            (*(Dem_Cfg_GetPrimaryEntry_8OfPCConfig())) = (Value)
#define Dem_Cfg_SetPrimaryEntry_9(Value)                                                            (*(Dem_Cfg_GetPrimaryEntry_9OfPCConfig())) = (Value)
#define Dem_Cfg_SetReadoutBuffer(Index, Value)                                                      Dem_Cfg_GetReadoutBufferOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetReportedEventsOfFilter(Index, Value)                                             Dem_Cfg_GetReportedEventsOfFilterOfPCConfig()[(Index)] = (Value)
#define Dem_Cfg_SetRingBuffer(Value)                                                                
#define Dem_Cfg_SetSatelliteInfoInvalid_OsApplication(Value)                                        (*(Dem_Cfg_GetSatelliteInfoInvalid_OsApplicationOfPCConfig())) = (Value)
#define Dem_Cfg_SetStatusData(Value)                                                                (*(Dem_Cfg_GetStatusDataOfPCConfig())) = (Value)
#define Dem_Cfg_SetStorageConditionFulfilled(Index, Value)                                          
#define Dem_Cfg_SetStorageConditionGroupCounter(Index, Value)                                       
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCGetAddressOfDataMacros  Dem_Cfg Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Dem_Cfg_GetAddrAdminData()                                                                  (&Dem_Cfg_GetAdminData())
#define Dem_Cfg_GetAddrAgingData()                                                                  ((Dem_Cfg_AgingDataPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrCallbackClearEventAllowed(Index)                                             ((Dem_Cfg_CallbackClearEventAllowedPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrCallbackDtcStatusChanged(Index)                                              (&Dem_Cfg_GetCallbackDtcStatusChanged(Index))
#define Dem_Cfg_GetAddrCallbackGetFdc(Index)                                                        ((Dem_Cfg_CallbackGetFdcPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrCallbackJ1939DtcStatusChanged(Index)                                         ((Dem_Cfg_CallbackJ1939DtcStatusChangedPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrClearDTCTable(Index)                                                         (&Dem_Cfg_GetClearDTCTable(Index))
#define Dem_Cfg_GetAddrClearDtcNotificationFinishTable(Index)                                       ((Dem_Cfg_ClearDtcNotificationFinishTablePtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrClearDtcNotificationStartTable(Index)                                        ((Dem_Cfg_ClearDtcNotificationStartTablePtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrCommitBuffer()                                                               (&Dem_Cfg_GetCommitBuffer())
#define Dem_Cfg_GetAddrCycleCounterData()                                                           ((Dem_Cfg_CycleCounterDataPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrDTCSelectorTable(Index)                                                      (&Dem_Cfg_GetDTCSelectorTable(Index))
#define Dem_Cfg_GetAddrReadDataFuncOfDataElementTable(Index)                                        (&Dem_Cfg_GetReadDataFuncOfDataElementTable(Index))
#define Dem_Cfg_GetAddrDebounceData()                                                               ((Dem_Cfg_DebounceDataPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrDtrData()                                                                    ((Dem_Cfg_DtrDataPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrDtrStatus(Index)                                                             ((Dem_Cfg_DtrStatusPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrEnableConditionFulfilled(Index)                                              (&(Dem_Cfg_GetEnableConditionFulfilledOfPCConfig()[(Index)]))
#define Dem_Cfg_GetAddrEnableConditionGroupCounter(Index)                                           (&Dem_Cfg_GetEnableConditionGroupCounter(Index))
#define Dem_Cfg_GetAddrEnableConditionGroupState(Index)                                             (&Dem_Cfg_GetEnableConditionGroupState(Index))
#define Dem_Cfg_GetAddrEventAvailableData()                                                         ((Dem_Cfg_EventAvailableDataPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrEventCycleStatus(Index)                                                      ((Dem_Cfg_EventCycleStatusPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrEventDataChanged(Index)                                                      ((Dem_Cfg_EventDataChangedPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrEventDataCommitNumber(Index)                                                 (&Dem_Cfg_GetEventDataCommitNumber(Index))
#define Dem_Cfg_GetAddrEventInternalStatus(Index)                                                   (&Dem_Cfg_GetEventInternalStatus(Index))
#define Dem_Cfg_GetAddrEventStatusChanged(Index)                                                    (&Dem_Cfg_GetEventStatusChanged(Index))
#define Dem_Cfg_GetAddrExtendedDataRecordIteratorTable(Index)                                       (&Dem_Cfg_GetExtendedDataRecordIteratorTable(Index))
#define Dem_Cfg_GetAddrFilterInfoTable(Index)                                                       (&Dem_Cfg_GetFilterInfoTable(Index))
#define Dem_Cfg_GetAddrFreezeFrameData()                                                            ((Dem_Cfg_FreezeFrameDataPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrFreezeFrameIteratorTable(Index)                                              (&Dem_Cfg_GetFreezeFrameIteratorTable(Index))
#define Dem_Cfg_GetAddrIndicatorData()                                                              ((Dem_Cfg_IndicatorDataPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrInitMonitorForEvent(Index)                                                   ((Dem_Cfg_InitMonitorForEventPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrInitMonitorsForFunc(Index)                                                   ((Dem_Cfg_InitMonitorsForFuncPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrMemoryCurrentCount(Index)                                                    (&Dem_Cfg_GetMemoryCurrentCount(Index))
#define Dem_Cfg_GetAddrMemoryStatus(Index)                                                          (&Dem_Cfg_GetMemoryStatus(Index))
#define Dem_Cfg_GetAddrMirrorData()                                                                 ((Dem_Cfg_MirrorDataPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrObdIumprData()                                                               ((Dem_Cfg_ObdIumprDataPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrObdIumprUpdatePending(Index)                                                 ((Dem_Cfg_ObdIumprUpdatePendingPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrPermanentData()                                                              ((Dem_Cfg_PermanentDataPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrPrestorage()                                                                 ((Dem_Cfg_PrestoragePtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrPrestorageIndex(Index)                                                       ((Dem_Cfg_PrestorageIndexPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrPrimaryChronology(Index)                                                     (&Dem_Cfg_GetPrimaryChronology(Index))
#define Dem_Cfg_GetAddrPrimaryEntry_0()                                                             (&Dem_Cfg_GetPrimaryEntry_0())
#define Dem_Cfg_GetAddrPrimaryEntry_1()                                                             (&Dem_Cfg_GetPrimaryEntry_1())
#define Dem_Cfg_GetAddrPrimaryEntry_2()                                                             (&Dem_Cfg_GetPrimaryEntry_2())
#define Dem_Cfg_GetAddrPrimaryEntry_3()                                                             (&Dem_Cfg_GetPrimaryEntry_3())
#define Dem_Cfg_GetAddrPrimaryEntry_4()                                                             (&Dem_Cfg_GetPrimaryEntry_4())
#define Dem_Cfg_GetAddrPrimaryEntry_5()                                                             (&Dem_Cfg_GetPrimaryEntry_5())
#define Dem_Cfg_GetAddrPrimaryEntry_6()                                                             (&Dem_Cfg_GetPrimaryEntry_6())
#define Dem_Cfg_GetAddrPrimaryEntry_7()                                                             (&Dem_Cfg_GetPrimaryEntry_7())
#define Dem_Cfg_GetAddrPrimaryEntry_8()                                                             (&Dem_Cfg_GetPrimaryEntry_8())
#define Dem_Cfg_GetAddrPrimaryEntry_9()                                                             (&Dem_Cfg_GetPrimaryEntry_9())
#define Dem_Cfg_GetAddrReadoutBuffer(Index)                                                         (&Dem_Cfg_GetReadoutBuffer(Index))
#define Dem_Cfg_GetAddrReportedEventsOfFilter(Index)                                                (&Dem_Cfg_GetReportedEventsOfFilter(Index))
#define Dem_Cfg_GetAddrSatelliteInfoInvalid_OsApplication()                                         (&Dem_Cfg_GetSatelliteInfoInvalid_OsApplication())
#define Dem_Cfg_GetAddrStatusData()                                                                 (&Dem_Cfg_GetStatusData())
#define Dem_Cfg_GetAddrStorageConditionFulfilled(Index)                                             ((Dem_Cfg_StorageConditionFulfilledPtrType)(NULL_PTR))
#define Dem_Cfg_GetAddrStorageConditionGroupCounter(Index)                                          ((Dem_Cfg_StorageConditionGroupCounterPtrType)(NULL_PTR))
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCHasMacros  Dem_Cfg Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Dem_Cfg_HasAdminData()                                                                      (TRUE != FALSE)
#define Dem_Cfg_HasAgingData()                                                                      (FALSE != FALSE)
#define Dem_Cfg_HasCalibrationErrorRegister()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasCalibrationObdDtcTable()                                                         (FALSE != FALSE)
#define Dem_Cfg_HasAgingAllowedOfCalibrationObdDtcTable()                                           (FALSE != FALSE)
#define Dem_Cfg_HasAgingCycleCounterThresholdOfCalibrationObdDtcTable()                             (FALSE != FALSE)
#define Dem_Cfg_HasAgingCycleIdOfCalibrationObdDtcTable()                                           (FALSE != FALSE)
#define Dem_Cfg_HasImmediateNvStorageOfCalibrationObdDtcTable()                                     (FALSE != FALSE)
#define Dem_Cfg_HasOperationCycleIdOfCalibrationObdDtcTable()                                       (FALSE != FALSE)
#define Dem_Cfg_HasReadinessGroupOfCalibrationObdDtcTable()                                         (FALSE != FALSE)
#define Dem_Cfg_HasUseExtendedDataRecord0x93OfCalibrationObdDtcTable()                              (FALSE != FALSE)
#define Dem_Cfg_HasCallbackClearEventAllowed()                                                      (FALSE != FALSE)
#define Dem_Cfg_HasCallbackDtcStatusChanged()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasCallbackGetFdc()                                                                 (FALSE != FALSE)
#define Dem_Cfg_HasCallbackJ1939DtcStatusChanged()                                                  (FALSE != FALSE)
#define Dem_Cfg_HasClearDTCTable()                                                                  (TRUE != FALSE)
#define Dem_Cfg_HasClearDtcNotificationFinishTable()                                                (FALSE != FALSE)
#define Dem_Cfg_HasClearDtcNotificationStartTable()                                                 (FALSE != FALSE)
#define Dem_Cfg_HasClientTable()                                                                    (TRUE != FALSE)
#define Dem_Cfg_HasClearDTCIndexOfClientTable()                                                     (TRUE != FALSE)
#define Dem_Cfg_HasFilterIndexOfClientTable()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameIteratorIndexOfClientTable()                                          (TRUE != FALSE)
#define Dem_Cfg_HasNmNodeIdOfClientTable()                                                          (TRUE != FALSE)
#define Dem_Cfg_HasReadoutBufferIndexOfClientTable()                                                (TRUE != FALSE)
#define Dem_Cfg_HasSelectorIndexOfClientTable()                                                     (TRUE != FALSE)
#define Dem_Cfg_HasCommitBuffer()                                                                   (TRUE != FALSE)
#define Dem_Cfg_HasCommonDidList()                                                                  (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameTableIdxOfCommonDidList()                                             (TRUE != FALSE)
#define Dem_Cfg_HasCompatibilityVersion()                                                           (TRUE != FALSE)
#define Dem_Cfg_HasConfigurationId()                                                                (TRUE != FALSE)
#define Dem_Cfg_HasCounterBasedDebounceTable()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasDebounceContinuousOfCounterBasedDebounceTable()                                  (TRUE != FALSE)
#define Dem_Cfg_HasDecrementStepSizeOfCounterBasedDebounceTable()                                   (TRUE != FALSE)
#define Dem_Cfg_HasEventDebounceBehaviorOfCounterBasedDebounceTable()                               (TRUE != FALSE)
#define Dem_Cfg_HasFailedThresholdOfCounterBasedDebounceTable()                                     (TRUE != FALSE)
#define Dem_Cfg_HasIncrementStepSizeOfCounterBasedDebounceTable()                                   (TRUE != FALSE)
#define Dem_Cfg_HasJumpDownOfCounterBasedDebounceTable()                                            (TRUE != FALSE)
#define Dem_Cfg_HasJumpDownValueOfCounterBasedDebounceTable()                                       (TRUE != FALSE)
#define Dem_Cfg_HasJumpUpOfCounterBasedDebounceTable()                                              (TRUE != FALSE)
#define Dem_Cfg_HasJumpUpValueOfCounterBasedDebounceTable()                                         (TRUE != FALSE)
#define Dem_Cfg_HasMaskedBitsOfCounterBasedDebounceTable()                                          (TRUE != FALSE)
#define Dem_Cfg_HasPassedThresholdOfCounterBasedDebounceTable()                                     (TRUE != FALSE)
#define Dem_Cfg_HasStorageThresholdOfCounterBasedDebounceTable()                                    (FALSE != FALSE)
#define Dem_Cfg_HasCustomTimeSeriesFreezeFrameTable()                                               (FALSE != FALSE)
#define Dem_Cfg_HasFirstRecordNumberOfCustomTimeSeriesFreezeFrameTable()                            (FALSE != FALSE)
#define Dem_Cfg_HasLastRecordNumberOfCustomTimeSeriesFreezeFrameTable()                             (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesSamplingProfileTableIdxOfCustomTimeSeriesFreezeFrameTable()            (FALSE != FALSE)
#define Dem_Cfg_HasUpdateRecordOfCustomTimeSeriesFreezeFrameTable()                                 (FALSE != FALSE)
#define Dem_Cfg_HasCustomTriggerEntryIndexToNvBlockIndex()                                          (FALSE != FALSE)
#define Dem_Cfg_HasCustomTriggerEntryPtr()                                                          (FALSE != FALSE)
#define Dem_Cfg_HasCycleCounterData()                                                               (FALSE != FALSE)
#define Dem_Cfg_HasCycleIdTable()                                                                   (TRUE != FALSE)
#define Dem_Cfg_HasEndsOnInitOfCycleIdTable()                                                       (FALSE != FALSE)
#define Dem_Cfg_HasOpCycleTypeOfCycleIdTable()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasDTCSelectorTable()                                                               (TRUE != FALSE)
#define Dem_Cfg_HasDTCStatusAvailabilityMaskInVariant()                                             (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTable()                                                            (TRUE != FALSE)
#define Dem_Cfg_HasCollectionSizeOfDataCollectionTable()                                            (TRUE != FALSE)
#define Dem_Cfg_HasDataElementTableCol2ElmtIndDataElementTableCol2ElmtIndEndIdxOfDataCollectionTable() (TRUE != FALSE)
#define Dem_Cfg_HasDataElementTableCol2ElmtIndDataElementTableCol2ElmtIndStartIdxOfDataCollectionTable() (TRUE != FALSE)
#define Dem_Cfg_HasDataElementTableCol2ElmtIndDataElementTableCol2ElmtIndUsedOfDataCollectionTable() (TRUE != FALSE)
#define Dem_Cfg_HasEventTable_ERec2EventIdIndEndIdxOfDataCollectionTable()                          (FALSE != FALSE)
#define Dem_Cfg_HasEventTable_ERec2EventIdIndStartIdxOfDataCollectionTable()                        (FALSE != FALSE)
#define Dem_Cfg_HasEventTable_ERec2EventIdIndUsedOfDataCollectionTable()                            (FALSE != FALSE)
#define Dem_Cfg_HasIdNumberOfDataCollectionTable()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasStorageKindOfDataCollectionTable()                                               (TRUE != FALSE)
#define Dem_Cfg_HasTriggerOfDataCollectionTable()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasUpdateOfDataCollectionTable()                                                    (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableErec2CollInd()                                                (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableIdxOfDataCollectionTableEdr2CollInd()                         (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableIdxOfDataCollectionTableFfm2CollInd()                         (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTablePid2CollInd()                                                 (FALSE != FALSE)
#define Dem_Cfg_HasDataElementTable()                                                               (TRUE != FALSE)
#define Dem_Cfg_HasDataIsStoredInNVOfDataElementTable()                                             (TRUE != FALSE)
#define Dem_Cfg_HasElementDataTypeOfDataElementTable()                                              (TRUE != FALSE)
#define Dem_Cfg_HasElementKindOfDataElementTable()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasElementSizeOfDataElementTable()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasReadDataFuncOfDataElementTable()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasDataElementTableIdxOfDataElementTableCol2ElmtInd()                               (TRUE != FALSE)
#define Dem_Cfg_HasDebounceData()                                                                   (FALSE != FALSE)
#define Dem_Cfg_HasDebounceIndirectionTable()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasCounterBasedDebounceTableIdxOfDebounceIndirectionTable()                         (TRUE != FALSE)
#define Dem_Cfg_HasCounterBasedDebounceTableUsedOfDebounceIndirectionTable()                        (TRUE != FALSE)
#define Dem_Cfg_HasTimeBasedDebounceTableIdxOfDebounceIndirectionTable()                            (FALSE != FALSE)
#define Dem_Cfg_HasTimeBasedDebounceTableUsedOfDebounceIndirectionTable()                           (FALSE != FALSE)
#define Dem_Cfg_HasDtcCalibTable()                                                                  (TRUE != FALSE)
#define Dem_Cfg_HasAgingCycleCounterThresholdOfDtcCalibTable()                                      (TRUE != FALSE)
#define Dem_Cfg_HasAgingCycleIdOfDtcCalibTable()                                                    (TRUE != FALSE)
#define Dem_Cfg_HasDtcPriorityOfDtcCalibTable()                                                     (TRUE != FALSE)
#define Dem_Cfg_HasDtcSeverityOfDtcCalibTable()                                                     (TRUE != FALSE)
#define Dem_Cfg_HasUdsDtcOfDtcCalibTable()                                                          (TRUE != FALSE)
#define Dem_Cfg_HasDtcGroupMask()                                                                   (FALSE != FALSE)
#define Dem_Cfg_HasGroupMaskOfDtcGroupMask()                                                        (FALSE != FALSE)
#define Dem_Cfg_HasUdsGroupDtcOfDtcGroupMask()                                                      (FALSE != FALSE)
#define Dem_Cfg_HasDtcInvariantDataTable()                                                          (TRUE != FALSE)
#define Dem_Cfg_HasAgingAllowedOfDtcInvariantDataTable()                                            (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameTableSecondStdFFIdxOfDtcInvariantDataTable()                          (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameTableStdFFIdxOfDtcInvariantDataTable()                                (TRUE != FALSE)
#define Dem_Cfg_HasFunctionalUnitOfDtcInvariantDataTable()                                          (TRUE != FALSE)
#define Dem_Cfg_HasDtcTable()                                                                       (TRUE != FALSE)
#define Dem_Cfg_HasCustomTimeSeriesFreezeFrameTableIdxOfDtcTable()                                  (FALSE != FALSE)
#define Dem_Cfg_HasCustomTimeSeriesFreezeFrameTableUsedOfDtcTable()                                 (FALSE != FALSE)
#define Dem_Cfg_HasCustomTriggeredSnapshotConfiguredOfDtcTable()                                    (FALSE != FALSE)
#define Dem_Cfg_HasCustomTriggeredTimeSeriesSnapshotConfiguredOfDtcTable()                          (FALSE != FALSE)
#define Dem_Cfg_HasDtcObdRelevanceOfDtcTable()                                                      (FALSE != FALSE)
#define Dem_Cfg_HasEventSignificanceOfDtcTable()                                                    (TRUE != FALSE)
#define Dem_Cfg_HasExtendedDataTableIdxOfDtcTable()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameNumIndirectionTableIdxOfDtcTable()                                    (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameNumIndirectionTableUsedOfDtcTable()                                   (TRUE != FALSE)
#define Dem_Cfg_HasImmediateNvStorageOfDtcTable()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasJ1939DtcOfDtcTable()                                                             (TRUE != FALSE)
#define Dem_Cfg_HasJ1939NodeIdIndEndIdxOfDtcTable()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasJ1939NodeIdIndStartIdxOfDtcTable()                                               (TRUE != FALSE)
#define Dem_Cfg_HasJ1939NodeIdIndUsedOfDtcTable()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasSMARIndexOfDtcTable()                                                            (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesIndirectionTableEndIdxOfDtcTable()                                     (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesIndirectionTableStartIdxOfDtcTable()                                   (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesIndirectionTableUsedOfDtcTable()                                       (FALSE != FALSE)
#define Dem_Cfg_HasDtrData()                                                                        (FALSE != FALSE)
#define Dem_Cfg_HasDtrStatus()                                                                      (FALSE != FALSE)
#define Dem_Cfg_HasDtrTable()                                                                       (FALSE != FALSE)
#define Dem_Cfg_HasDivisorOfDtrTable()                                                              (FALSE != FALSE)
#define Dem_Cfg_HasEventTableIdxOfDtrTable()                                                        (FALSE != FALSE)
#define Dem_Cfg_HasLinearFactorOfDtrTable()                                                         (FALSE != FALSE)
#define Dem_Cfg_HasOffsetOfDtrTable()                                                               (FALSE != FALSE)
#define Dem_Cfg_HasUasidOfDtrTable()                                                                (FALSE != FALSE)
#define Dem_Cfg_HasUpdateKindOfDtrTable()                                                           (FALSE != FALSE)
#define Dem_Cfg_HasDtrTableInd()                                                                    (FALSE != FALSE)
#define Dem_Cfg_HasEnableConditionFulfilled()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupCounter()                                                    (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupState()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupTable()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasIndexOfEnableConditionGroupTable()                                               (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupTableInd()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionInitTable()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasFulfilledAtInitOfEnableConditionInitTable()                                      (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionTable()                                                           (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupTableIndEndIdxOfEnableConditionTable()                       (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupTableIndStartIdxOfEnableConditionTable()                     (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupTableIndUsedOfEnableConditionTable()                         (TRUE != FALSE)
#define Dem_Cfg_HasEndIdxOfDemDidClassInDataCollectionTable()                                       (TRUE != FALSE)
#define Dem_Cfg_HasEventAvailableData()                                                             (FALSE != FALSE)
#define Dem_Cfg_HasEventAvailableDefault()                                                          (TRUE != FALSE)
#define Dem_Cfg_HasEventAvailableInVariant()                                                        (Dem_Cfg_GetEventAvailableInVariantOfPCConfig() != NULL_PTR)
#define Dem_Cfg_HasEventCalibTable()                                                                (TRUE != FALSE)
#define Dem_Cfg_HasEventFailureCycleCounterThresholdOfEventCalibTable()                             (TRUE != FALSE)
#define Dem_Cfg_HasOperationCycleIdOfEventCalibTable()                                              (TRUE != FALSE)
#define Dem_Cfg_HasEventCycleStatus()                                                               (FALSE != FALSE)
#define Dem_Cfg_HasEventDataChanged()                                                               (FALSE != FALSE)
#define Dem_Cfg_HasEventDataCommitNumber()                                                          (TRUE != FALSE)
#define Dem_Cfg_HasEventEntryIndexToNvBlockIndex()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasEventEntryInfoTable()                                                            (TRUE != FALSE)
#define Dem_Cfg_HasBaseEntryPtrOfEventEntryInfoTable()                                              (TRUE != FALSE)
#define Dem_Cfg_HasExtendedDataPtrOfEventEntryInfoTable()                                           (TRUE != FALSE)
#define Dem_Cfg_HasInitPtrOfEventEntryInfoTable()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasJ1939FreezeFrameDataPtrOfEventEntryInfoTable()                                   (TRUE != FALSE)
#define Dem_Cfg_HasObdFreezeFrameDataPtrOfEventEntryInfoTable()                                     (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfExtendedDataOfEventEntryInfoTable()                                        (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfJ1939ExpFreezeFrameOfEventEntryInfoTable()                                 (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfJ1939FreezeFrameOfEventEntryInfoTable()                                    (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfObdFreezeFrameOfEventEntryInfoTable()                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfSnapshotDataOfEventEntryInfoTable()                                        (TRUE != FALSE)
#define Dem_Cfg_HasSnapshotDataPtrOfEventEntryInfoTable()                                           (TRUE != FALSE)
#define Dem_Cfg_HasEventIndicatorData()                                                             (FALSE != FALSE)
#define Dem_Cfg_HasAssignedAttributeBitFieldOfEventIndicatorData()                                  (FALSE != FALSE)
#define Dem_Cfg_HasEventHealingTargetOfEventIndicatorData()                                         (FALSE != FALSE)
#define Dem_Cfg_HasEventInternalStatus()                                                            (TRUE != FALSE)
#define Dem_Cfg_HasEventInvariantDataTable()                                                        (TRUE != FALSE)
#define Dem_Cfg_HasDtcTableIdxOfEventInvariantDataTable()                                           (TRUE != FALSE)
#define Dem_Cfg_HasEventPrecompileDataTable()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasCallbackGetFdcIdxOfEventPrecompileDataTable()                                    (FALSE != FALSE)
#define Dem_Cfg_HasDebounceCounterStorageOfEventPrecompileDataTable()                               (TRUE != FALSE)
#define Dem_Cfg_HasEventConsiderPtoStatusOfEventPrecompileDataTable()                               (FALSE != FALSE)
#define Dem_Cfg_HasEventKindOfEventPrecompileDataTable()                                            (TRUE != FALSE)
#define Dem_Cfg_HasEventLatchTFOfEventPrecompileDataTable()                                         (TRUE != FALSE)
#define Dem_Cfg_HasEventStatusChangedEndIdxOfEventPrecompileDataTable()                             (TRUE != FALSE)
#define Dem_Cfg_HasEventStatusChangedStartIdxOfEventPrecompileDataTable()                           (TRUE != FALSE)
#define Dem_Cfg_HasEventStatusChangedUsedOfEventPrecompileDataTable()                               (TRUE != FALSE)
#define Dem_Cfg_HasMaskedBitsOfEventPrecompileDataTable()                                           (TRUE != FALSE)
#define Dem_Cfg_HasMultiEventTriggeringSlaveEventsTableEndIdxOfEventPrecompileDataTable()           (FALSE != FALSE)
#define Dem_Cfg_HasMultiEventTriggeringSlaveEventsTableStartIdxOfEventPrecompileDataTable()         (FALSE != FALSE)
#define Dem_Cfg_HasMultiEventTriggeringSlaveEventsTableUsedOfEventPrecompileDataTable()             (FALSE != FALSE)
#define Dem_Cfg_HasMultiEventTriggeringSlaveOfEventPrecompileDataTable()                            (FALSE != FALSE)
#define Dem_Cfg_HasSatelliteEventIdxOfEventPrecompileDataTable()                                    (TRUE != FALSE)
#define Dem_Cfg_HasSatelliteInfoIdxOfEventPrecompileDataTable()                                     (TRUE != FALSE)
#define Dem_Cfg_HasEventPrecompileDataTableInd()                                                    (TRUE != FALSE)
#define Dem_Cfg_HasEventStatusChanged()                                                             (TRUE != FALSE)
#define Dem_Cfg_HasEventTable()                                                                     (TRUE != FALSE)
#define Dem_Cfg_HasDtrTableIndEndIdxOfEventTable()                                                  (FALSE != FALSE)
#define Dem_Cfg_HasDtrTableIndStartIdxOfEventTable()                                                (FALSE != FALSE)
#define Dem_Cfg_HasDtrTableIndUsedOfEventTable()                                                    (FALSE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupTableIdxOfEventTable()                                       (FALSE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupTableUsedOfEventTable()                                      (FALSE != FALSE)
#define Dem_Cfg_HasEventCalibTableIdxOfEventTable()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasEventDestinationOfEventTable()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasEventIndicatorDataIdxOfEventTable()                                              (FALSE != FALSE)
#define Dem_Cfg_HasEventIndicatorDataUsedOfEventTable()                                             (FALSE != FALSE)
#define Dem_Cfg_HasEventInvariantDataTableIdxOfEventTable()                                         (TRUE != FALSE)
#define Dem_Cfg_HasEventPtoTimerIndexOfEventTable()                                                 (FALSE != FALSE)
#define Dem_Cfg_HasFailedCycleCounterIndexOfEventTable()                                            (FALSE != FALSE)
#define Dem_Cfg_HasFaultPendingCounterIndexOfEventTable()                                           (FALSE != FALSE)
#define Dem_Cfg_HasMaxFDCSinceLastClearIndexOfEventTable()                                          (FALSE != FALSE)
#define Dem_Cfg_HasMonitorActivityRatioTableIdxOfEventTable()                                       (FALSE != FALSE)
#define Dem_Cfg_HasOBDVisibilityDelayedUntilDcyQualificationOfEventTable()                          (TRUE != FALSE)
#define Dem_Cfg_HasEventTable_ERec2EventIdInd()                                                     (FALSE != FALSE)
#define Dem_Cfg_HasExtendedDataRecordIteratorTable()                                                (TRUE != FALSE)
#define Dem_Cfg_HasExtendedDataRecordTable()                                                        (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableErec2CollIndEndIdxOfExtendedDataRecordTable()                 (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableErec2CollIndStartIdxOfExtendedDataRecordTable()               (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableErec2CollIndUsedOfExtendedDataRecordTable()                   (TRUE != FALSE)
#define Dem_Cfg_HasExtendedDataTable()                                                              (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndEndIdxOfExtendedDataTable() (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndStartIdxOfExtendedDataTable() (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndUsedOfExtendedDataTable() (TRUE != FALSE)
#define Dem_Cfg_HasMaxRecordSizeOfExtendedDataTable()                                               (TRUE != FALSE)
#define Dem_Cfg_HasFilterInfoTable()                                                                (TRUE != FALSE)
#define Dem_Cfg_HasFinalMagicNumber()                                                               (FALSE != FALSE)
#define Dem_Cfg_HasFreezeFrameData()                                                                (FALSE != FALSE)
#define Dem_Cfg_HasFreezeFrameIteratorTable()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameNumIndirectionTable()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameNumTableEndIdxOfFreezeFrameNumIndirectionTable()                      (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameNumTableSecondEndIdxOfFreezeFrameNumIndirectionTable()                (FALSE != FALSE)
#define Dem_Cfg_HasFreezeFrameNumTableSecondStartIdxOfFreezeFrameNumIndirectionTable()              (FALSE != FALSE)
#define Dem_Cfg_HasFreezeFrameNumTableSecondUsedOfFreezeFrameNumIndirectionTable()                  (FALSE != FALSE)
#define Dem_Cfg_HasFreezeFrameNumTableStartIdxOfFreezeFrameNumIndirectionTable()                    (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameNumTableUsedOfFreezeFrameNumIndirectionTable()                        (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameNumTable()                                                            (TRUE != FALSE)
#define Dem_Cfg_HasFFNumberOfFreezeFrameNumTable()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasFFTriggerOfFreezeFrameNumTable()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasFFUpdateOfFreezeFrameNumTable()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasIsGlobalOfFreezeFrameNumTable()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasMaskedBitsOfFreezeFrameNumTable()                                                (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameTable()                                                               (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndEndIdxOfFreezeFrameTable() (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndStartIdxOfFreezeFrameTable() (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndUsedOfFreezeFrameTable() (TRUE != FALSE)
#define Dem_Cfg_HasRecordSizeOfFreezeFrameTable()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasRecordSizeUdsOfFreezeFrameTable()                                                (TRUE != FALSE)
#define Dem_Cfg_HasGeneralJ1939Table()                                                              (FALSE != FALSE)
#define Dem_Cfg_HasRecordSizeOfGeneralJ1939Table()                                                  (FALSE != FALSE)
#define Dem_Cfg_HasGeneralObdInput()                                                                (TRUE != FALSE)
#define Dem_Cfg_HasDataElementTableIdxOfGeneralObdInput()                                           (TRUE != FALSE)
#define Dem_Cfg_HasGlobalObdRequirements()                                                          (FALSE != FALSE)
#define Dem_Cfg_HasGlobalSeverityMask()                                                             (TRUE != FALSE)
#define Dem_Cfg_HasGlobalSnapshotRecord()                                                           (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameTableIdxOfGlobalSnapshotRecord()                                      (TRUE != FALSE)
#define Dem_Cfg_HasIndicatorAttributeTable()                                                        (FALSE != FALSE)
#define Dem_Cfg_HasBehaviourOfIndicatorAttributeTable()                                             (FALSE != FALSE)
#define Dem_Cfg_HasFailureCycleCounterThresholdOfIndicatorAttributeTable()                          (FALSE != FALSE)
#define Dem_Cfg_HasIdOfIndicatorAttributeTable()                                                    (FALSE != FALSE)
#define Dem_Cfg_HasJ1939NodeIdOfIndicatorAttributeTable()                                           (FALSE != FALSE)
#define Dem_Cfg_HasIndicatorData()                                                                  (FALSE != FALSE)
#define Dem_Cfg_HasIndicatorEventCounters()                                                         (FALSE != FALSE)
#define Dem_Cfg_HasInitDataHashCode()                                                               (FALSE != FALSE)
#define Dem_Cfg_HasInitMonListForFunc()                                                             (FALSE != FALSE)
#define Dem_Cfg_HasInitMonitorForEvent()                                                            (FALSE != FALSE)
#define Dem_Cfg_HasInitMonitorsForFunc()                                                            (FALSE != FALSE)
#define Dem_Cfg_HasJ1939EventIdsWithRatioTable()                                                    (FALSE != FALSE)
#define Dem_Cfg_HasEventIdOfJ1939EventIdsWithRatioTable()                                           (FALSE != FALSE)
#define Dem_Cfg_HasJ1939NodeId()                                                                    (TRUE != FALSE)
#define Dem_Cfg_HasJ1939NodeIdInd()                                                                 (TRUE != FALSE)
#define Dem_Cfg_HasJ1939NodeIndicatorAvailability()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasJ1939SpnsInExpandedFreezeFrameTable()                                            (FALSE != FALSE)
#define Dem_Cfg_HasSpnIdOfJ1939SpnsInExpandedFreezeFrameTable()                                     (FALSE != FALSE)
#define Dem_Cfg_HasSpnSizeOfJ1939SpnsInExpandedFreezeFrameTable()                                   (FALSE != FALSE)
#define Dem_Cfg_HasMaxNumberEventEntryOBDFreezeFrame()                                              (FALSE != FALSE)
#define Dem_Cfg_HasMemoryCurrentCount()                                                             (TRUE != FALSE)
#define Dem_Cfg_HasMemoryInfoTable()                                                                (TRUE != FALSE)
#define Dem_Cfg_HasChronoPtrOfMemoryInfoTable()                                                     (TRUE != FALSE)
#define Dem_Cfg_HasCustomTriggerTranslatedMemoryIdOfMemoryInfoTable()                               (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupTableControlDtcSettingGroupIdxOfMemoryInfoTable()            (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupTableControlDtcSettingGroupUsedOfMemoryInfoTable()           (TRUE != FALSE)
#define Dem_Cfg_HasEventMemoryEntryStorageTriggerOfMemoryInfoTable()                                (TRUE != FALSE)
#define Dem_Cfg_HasFirstEntryIndexOfMemoryInfoTable()                                               (TRUE != FALSE)
#define Dem_Cfg_HasFirstEventOfMemoryInfoTable()                                                    (TRUE != FALSE)
#define Dem_Cfg_HasIndividualERecSizeOfMemoryInfoTable()                                            (TRUE != FALSE)
#define Dem_Cfg_HasIndividualSRecSizeOfMemoryInfoTable()                                            (TRUE != FALSE)
#define Dem_Cfg_HasLastEventOfMemoryInfoTable()                                                     (TRUE != FALSE)
#define Dem_Cfg_HasMaxNumberTimeSeriesSetsOfMemoryInfoTable()                                       (TRUE != FALSE)
#define Dem_Cfg_HasMaxSizeOfMemoryInfoTable()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasSRecNumTypeOfMemoryInfoTable()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasTimeSeriesFifoSupportOfMemoryInfoTable()                                         (TRUE != FALSE)
#define Dem_Cfg_HasTimeSeriesSetsRecNumOffsetOfMemoryInfoTable()                                    (TRUE != FALSE)
#define Dem_Cfg_HasTimeSeriesTranslatedMemoryIdOfMemoryInfoTable()                                  (TRUE != FALSE)
#define Dem_Cfg_HasMemoryStatus()                                                                   (TRUE != FALSE)
#define Dem_Cfg_HasMidTable()                                                                       (FALSE != FALSE)
#define Dem_Cfg_HasDtrTableIdxOfMidTable()                                                          (FALSE != FALSE)
#define Dem_Cfg_HasMidOfMidTable()                                                                  (FALSE != FALSE)
#define Dem_Cfg_HasTidOfMidTable()                                                                  (FALSE != FALSE)
#define Dem_Cfg_HasMirrorData()                                                                     (FALSE != FALSE)
#define Dem_Cfg_HasMonitorActivityRatioTable()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasMARIndexOfMonitorActivityRatioTable()                                            (TRUE != FALSE)
#define Dem_Cfg_HasSMARIndexOfMonitorActivityRatioTable()                                           (TRUE != FALSE)
#define Dem_Cfg_HasMultiEventTriggeringSlaveEventsTable()                                           (FALSE != FALSE)
#define Dem_Cfg_HasEventPrecompileDataTableIdxOfMultiEventTriggeringSlaveEventsTable()              (FALSE != FALSE)
#define Dem_Cfg_HasNoDtcConfigured()                                                                (TRUE != FALSE)
#define Dem_Cfg_HasNvBlockDataPtr()                                                                 (TRUE != FALSE)
#define Dem_Cfg_HasNvBlockDataSize()                                                                (TRUE != FALSE)
#define Dem_Cfg_HasNvBlockId()                                                                      (TRUE != FALSE)
#define Dem_Cfg_HasObdCalibTable()                                                                  (FALSE != FALSE)
#define Dem_Cfg_HasCalibrationObdDtcTableIdxOfObdCalibTable()                                       (FALSE != FALSE)
#define Dem_Cfg_HasCalibrationObdDtcTableUsedOfObdCalibTable()                                      (FALSE != FALSE)
#define Dem_Cfg_HasObdDtc3ByteOfObdCalibTable()                                                     (FALSE != FALSE)
#define Dem_Cfg_HasObdDtcOfObdCalibTable()                                                          (FALSE != FALSE)
#define Dem_Cfg_HasReadinessGroupOfObdCalibTable()                                                  (FALSE != FALSE)
#define Dem_Cfg_HasObdIumprData()                                                                   (FALSE != FALSE)
#define Dem_Cfg_HasObdIumprUpdatePending()                                                          (FALSE != FALSE)
#define Dem_Cfg_HasPIDF501ReadinessSupportedAndCompletedEnforcementMask()                           (TRUE != FALSE)
#define Dem_Cfg_HasPIDF501ReadinessUnsupportedEnforcementMask()                                     (TRUE != FALSE)
#define Dem_Cfg_HasPendingEvaluatedForConfirmedAndActiveConditionInVariant()                        (FALSE != FALSE)
#define Dem_Cfg_HasPermanentData()                                                                  (FALSE != FALSE)
#define Dem_Cfg_HasPidTable()                                                                       (FALSE != FALSE)
#define Dem_Cfg_HasDataCollectionTablePid2CollIndEndIdxOfPidTable()                                 (FALSE != FALSE)
#define Dem_Cfg_HasDataCollectionTablePid2CollIndStartIdxOfPidTable()                               (FALSE != FALSE)
#define Dem_Cfg_HasDataCollectionTablePid2CollIndUsedOfPidTable()                                   (FALSE != FALSE)
#define Dem_Cfg_HasPrestorage()                                                                     (FALSE != FALSE)
#define Dem_Cfg_HasPrestorageIndex()                                                                (FALSE != FALSE)
#define Dem_Cfg_HasPrimaryChronology()                                                              (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_0()                                                                 (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_1()                                                                 (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_2()                                                                 (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_3()                                                                 (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_4()                                                                 (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_5()                                                                 (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_6()                                                                 (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_7()                                                                 (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_8()                                                                 (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_9()                                                                 (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEventEntryInit()                                                          (TRUE != FALSE)
#define Dem_Cfg_HasRatioIdTable()                                                                   (FALSE != FALSE)
#define Dem_Cfg_HasReadoutBuffer()                                                                  (TRUE != FALSE)
#define Dem_Cfg_HasReportedEventsOfFilter()                                                         (TRUE != FALSE)
#define Dem_Cfg_HasRingBuffer()                                                                     (FALSE != FALSE)
#define Dem_Cfg_HasSamplingProfileDidInfoTable()                                                    (FALSE != FALSE)
#define Dem_Cfg_HasDataCollectionTableIdxOfSamplingProfileDidInfoTable()                            (FALSE != FALSE)
#define Dem_Cfg_HasDidRingBufferOffsetOfSamplingProfileDidInfoTable()                               (FALSE != FALSE)
#define Dem_Cfg_HasSatelliteInfo()                                                                  (TRUE != FALSE)
#define Dem_Cfg_HasApplicationIdOfSatelliteInfo()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasDebounceLoResTimerOfSatelliteInfo()                                              (FALSE != FALSE)
#define Dem_Cfg_HasEventCountOfSatelliteInfo()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasEventPrecompileDataTableIndEndIdxOfSatelliteInfo()                               (TRUE != FALSE)
#define Dem_Cfg_HasEventPrecompileDataTableIndStartIdxOfSatelliteInfo()                             (TRUE != FALSE)
#define Dem_Cfg_HasEventPrecompileDataTableIndUsedOfSatelliteInfo()                                 (TRUE != FALSE)
#define Dem_Cfg_HasMaxDebounceValuesOfSatelliteInfo()                                               (FALSE != FALSE)
#define Dem_Cfg_HasSatelliteDataOfSatelliteInfo()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasSatelliteExtendedDataOfSatelliteInfo()                                           (FALSE != FALSE)
#define Dem_Cfg_HasSatelliteStatusOfSatelliteInfo()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasSatelliteInfoInvalid_OsApplication()                                             (TRUE != FALSE)
#define Dem_Cfg_HasSatelliteTimeDebounceInfo()                                                      (FALSE != FALSE)
#define Dem_Cfg_HasTimeBasedEventTableEndIdxOfSatelliteTimeDebounceInfo()                           (FALSE != FALSE)
#define Dem_Cfg_HasTimeBasedEventTableStartIdxOfSatelliteTimeDebounceInfo()                         (FALSE != FALSE)
#define Dem_Cfg_HasTimeBasedEventTableUsedOfSatelliteTimeDebounceInfo()                             (FALSE != FALSE)
#define Dem_Cfg_HasSizeOfCalibrationObdDtcTable()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCallbackClearEventAllowed()                                                (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCallbackDtcStatusChanged()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCallbackGetFdc()                                                           (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCallbackJ1939DtcStatusChanged()                                            (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfClearDTCTable()                                                            (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfClearDtcNotificationFinishTable()                                          (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfClearDtcNotificationStartTable()                                           (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfClientTable()                                                              (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCounterBasedDebounceTable()                                                (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCustomTimeSeriesFreezeFrameTable()                                         (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCustomTriggerEntryIndexToNvBlockIndex()                                    (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCustomTriggerEntryPtr()                                                    (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfDTCSelectorTable()                                                         (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfDataCollectionTable()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfDataElementTable()                                                         (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfDtcGroupMask()                                                             (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfDtcTable()                                                                 (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfDtrStatus()                                                                (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfDtrTable()                                                                 (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEnableConditionFulfilled()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEnableConditionGroupCounter()                                              (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEnableConditionGroupState()                                                (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEnableConditionGroupTable()                                                (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEnableConditionTable()                                                     (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventCycleStatus()                                                         (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventDataChanged()                                                         (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventDataCommitNumber()                                                    (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventEntryIndexToNvBlockIndex()                                            (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventEntryInfoTable()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventIndicatorData()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventInternalStatus()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventStatusChanged()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventTable()                                                               (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfExtendedDataRecordIteratorTable()                                          (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfFilterInfoTable()                                                          (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfFreezeFrameIteratorTable()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfFreezeFrameTable()                                                         (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfGlobalSnapshotRecord()                                                     (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfIndicatorAttributeTable()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfIndicatorEventCounters()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfInitMonitorForEvent()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfInitMonitorsForFunc()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfJ1939SpnsInExpandedFreezeFrameTable()                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfMemoryCurrentCount()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfMemoryInfoTable()                                                          (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfMemoryStatus()                                                             (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfMonitorActivityRatioTable()                                                (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfObdIumprUpdatePending()                                                    (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfPrestorageIndex()                                                          (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfPrimaryChronology()                                                        (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfRatioIdTable()                                                             (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfReadoutBuffer()                                                            (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfReportedEventsOfFilter()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfSatelliteInfo()                                                            (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfSpnToEventsWithRatioTable()                                                (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfStartIdx500miDenRatioTable()                                               (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfStorageConditionFulfilled()                                                (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfStorageConditionGroupCounter()                                             (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfStorageConditionGroupTable()                                               (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfStorageConditionTable()                                                    (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfSupportedMidsTable()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfTimeBasedDebounceTable()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfTimeBasedEventTable()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfTimeSeriesEntryIndexToNvBlockIndex()                                       (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfTimeSeriesEntryTable()                                                     (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfTimeSeriesSamplingProfileTable()                                           (TRUE != FALSE)
#define Dem_Cfg_HasSpnToEventsWithRatioTable()                                                      (FALSE != FALSE)
#define Dem_Cfg_HasJ1939EventIdsWithRatioTableEndIdxOfSpnToEventsWithRatioTable()                   (FALSE != FALSE)
#define Dem_Cfg_HasJ1939EventIdsWithRatioTableStartIdxOfSpnToEventsWithRatioTable()                 (FALSE != FALSE)
#define Dem_Cfg_HasSPNOfSpnToEventsWithRatioTable()                                                 (FALSE != FALSE)
#define Dem_Cfg_HasStartIdx500miDenRatioTable()                                                     (FALSE != FALSE)
#define Dem_Cfg_HasStartIdxOfDemDidClassInDataCollectionTable()                                     (TRUE != FALSE)
#define Dem_Cfg_HasStatusData()                                                                     (TRUE != FALSE)
#define Dem_Cfg_HasStorageConditionFulfilled()                                                      (FALSE != FALSE)
#define Dem_Cfg_HasStorageConditionGroupCounter()                                                   (FALSE != FALSE)
#define Dem_Cfg_HasStorageConditionGroupTable()                                                     (FALSE != FALSE)
#define Dem_Cfg_HasIndexOfStorageConditionGroupTable()                                              (FALSE != FALSE)
#define Dem_Cfg_HasStorageConditionGroupTableInd()                                                  (FALSE != FALSE)
#define Dem_Cfg_HasStorageConditionInitTable()                                                      (FALSE != FALSE)
#define Dem_Cfg_HasFulfilledAtInitOfStorageConditionInitTable()                                     (FALSE != FALSE)
#define Dem_Cfg_HasStorageConditionTable()                                                          (FALSE != FALSE)
#define Dem_Cfg_HasStorageConditionGroupTableIndEndIdxOfStorageConditionTable()                     (FALSE != FALSE)
#define Dem_Cfg_HasStorageConditionGroupTableIndStartIdxOfStorageConditionTable()                   (FALSE != FALSE)
#define Dem_Cfg_HasStorageConditionGroupTableIndUsedOfStorageConditionTable()                       (FALSE != FALSE)
#define Dem_Cfg_HasSupportedMidsTable()                                                             (FALSE != FALSE)
#define Dem_Cfg_HasStartIdxMidTableOfSupportedMidsTable()                                           (FALSE != FALSE)
#define Dem_Cfg_HasTimeBasedDebounceTable()                                                         (FALSE != FALSE)
#define Dem_Cfg_HasDebounceContinuousOfTimeBasedDebounceTable()                                     (FALSE != FALSE)
#define Dem_Cfg_HasEventDebounceBehaviorOfTimeBasedDebounceTable()                                  (FALSE != FALSE)
#define Dem_Cfg_HasFailTimerThresholdHighResOfTimeBasedDebounceTable()                              (FALSE != FALSE)
#define Dem_Cfg_HasFailTimerThresholdLowResOfTimeBasedDebounceTable()                               (FALSE != FALSE)
#define Dem_Cfg_HasIsLowResolutionOfTimeBasedDebounceTable()                                        (FALSE != FALSE)
#define Dem_Cfg_HasPassTimerThresholdHighResOfTimeBasedDebounceTable()                              (FALSE != FALSE)
#define Dem_Cfg_HasPassTimerThresholdLowResOfTimeBasedDebounceTable()                               (FALSE != FALSE)
#define Dem_Cfg_HasStorageTimerThresholdHighResOfTimeBasedDebounceTable()                           (FALSE != FALSE)
#define Dem_Cfg_HasStorageTimerThresholdLowResOfTimeBasedDebounceTable()                            (FALSE != FALSE)
#define Dem_Cfg_HasTimeBasedEventTable()                                                            (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesEntryIndexToNvBlockIndex()                                             (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesEntryTable()                                                           (FALSE != FALSE)
#define Dem_Cfg_HasBaseEntryOfTimeSeriesEntryTable()                                                (FALSE != FALSE)
#define Dem_Cfg_HasBufferSizeOfTimeSeriesEntryTable()                                               (FALSE != FALSE)
#define Dem_Cfg_HasEntryDataOfTimeSeriesEntryTable()                                                (FALSE != FALSE)
#define Dem_Cfg_HasMaxSnapShotSizeOfTimeSeriesEntryTable()                                          (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesFreezeFrameTable()                                                     (FALSE != FALSE)
#define Dem_Cfg_HasFirstRecordNumberOfTimeSeriesFreezeFrameTable()                                  (FALSE != FALSE)
#define Dem_Cfg_HasLastRecordNumberOfTimeSeriesFreezeFrameTable()                                   (FALSE != FALSE)
#define Dem_Cfg_HasRecordTriggerOfTimeSeriesFreezeFrameTable()                                      (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesSamplingProfileTableIdxOfTimeSeriesFreezeFrameTable()                  (FALSE != FALSE)
#define Dem_Cfg_HasUpdateRecordOfTimeSeriesFreezeFrameTable()                                       (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesIndirectionTable()                                                     (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesFreezeFrameTableIdxOfTimeSeriesIndirectionTable()                      (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesSamplingProfileCalibTable()                                            (FALSE != FALSE)
#define Dem_Cfg_HasDataCollectionTableIdxOfTimeSeriesSamplingProfileCalibTable()                    (FALSE != FALSE)
#define Dem_Cfg_HasPastSamplesOfTimeSeriesSamplingProfileCalibTable()                               (FALSE != FALSE)
#define Dem_Cfg_HasSamplingPeriodTicsOfTimeSeriesSamplingProfileCalibTable()                        (FALSE != FALSE)
#define Dem_Cfg_HasSamplingProfileDidInfoTableEndIdxOfTimeSeriesSamplingProfileCalibTable()         (FALSE != FALSE)
#define Dem_Cfg_HasSamplingProfileDidInfoTableStartIdxOfTimeSeriesSamplingProfileCalibTable()       (FALSE != FALSE)
#define Dem_Cfg_HasSamplingProfileDidInfoTableUsedOfTimeSeriesSamplingProfileCalibTable()           (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesSamplingProfileTable()                                                 (FALSE != FALSE)
#define Dem_Cfg_HasRingBufferPtrOfTimeSeriesSamplingProfileTable()                                  (FALSE != FALSE)
#define Dem_Cfg_HasRingBufferSamplesOfTimeSeriesSamplingProfileTable()                              (FALSE != FALSE)
#define Dem_Cfg_HasSampleSizeOfTimeSeriesSamplingProfileTable()                                     (FALSE != FALSE)
#define Dem_Cfg_HasSequentialDidIdOfTimeSeriesSamplingProfileTable()                                (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesSamplingProfileCalibTableIdxOfTimeSeriesSamplingProfileTable()         (FALSE != FALSE)
#define Dem_Cfg_HasTotalSamplesOfTimeSeriesSamplingProfileTable()                                   (FALSE != FALSE)
#define Dem_Cfg_HasUseOBDIIOrOBDonUDSInVariant()                                                    (TRUE != FALSE)
#define Dem_Cfg_HasUseOBDonUDSInVariant()                                                           (TRUE != FALSE)
#define Dem_Cfg_HasUsePermanentInVariant()                                                          (FALSE != FALSE)
#define Dem_Cfg_HasUseReadinessSupportAndCompletenessEnforcementMaskInVariant()                     (TRUE != FALSE)
#define Dem_Cfg_HasUseReadinessUnsupportedEnforcementBitMaskInVariant()                             (TRUE != FALSE)
#define Dem_Cfg_HasUseWWHOBDInVariant()                                                             (TRUE != FALSE)
#define Dem_Cfg_HasUseZEVonUDSInVariant()                                                           (TRUE != FALSE)
#define Dem_Cfg_HasUserDefinedOriginTable()                                                         (FALSE != FALSE)
#define Dem_Cfg_HasMemoryInfoTableIdxOfUserDefinedOriginTable()                                     (FALSE != FALSE)
#define Dem_Cfg_HasMemoryInfoTableUsedOfUserDefinedOriginTable()                                    (FALSE != FALSE)
#define Dem_HasPCConfig()                                                                           (TRUE != FALSE)
#define Dem_Cfg_HasAdminDataOfPCConfig()                                                            (TRUE != FALSE)
#define Dem_Cfg_HasAgingDataOfPCConfig()                                                            (FALSE != FALSE)
#define Dem_Cfg_HasCalibrationErrorRegisterOfPCConfig()                                             (TRUE != FALSE)
#define Dem_Cfg_HasCalibrationObdDtcTableOfPCConfig()                                               (FALSE != FALSE)
#define Dem_Cfg_HasCallbackClearEventAllowedOfPCConfig()                                            (FALSE != FALSE)
#define Dem_Cfg_HasCallbackDtcStatusChangedOfPCConfig()                                             (TRUE != FALSE)
#define Dem_Cfg_HasCallbackGetFdcOfPCConfig()                                                       (FALSE != FALSE)
#define Dem_Cfg_HasCallbackJ1939DtcStatusChangedOfPCConfig()                                        (FALSE != FALSE)
#define Dem_Cfg_HasClearDTCTableOfPCConfig()                                                        (TRUE != FALSE)
#define Dem_Cfg_HasClearDtcNotificationFinishTableOfPCConfig()                                      (FALSE != FALSE)
#define Dem_Cfg_HasClearDtcNotificationStartTableOfPCConfig()                                       (FALSE != FALSE)
#define Dem_Cfg_HasClientTableOfPCConfig()                                                          (TRUE != FALSE)
#define Dem_Cfg_HasCommitBufferOfPCConfig()                                                         (TRUE != FALSE)
#define Dem_Cfg_HasCommonDidListOfPCConfig()                                                        (TRUE != FALSE)
#define Dem_Cfg_HasCompatibilityVersionOfPCConfig()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasConfigurationIdOfPCConfig()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasCounterBasedDebounceTableOfPCConfig()                                            (TRUE != FALSE)
#define Dem_Cfg_HasCustomTimeSeriesFreezeFrameTableOfPCConfig()                                     (FALSE != FALSE)
#define Dem_Cfg_HasCustomTriggerEntryIndexToNvBlockIndexOfPCConfig()                                (FALSE != FALSE)
#define Dem_Cfg_HasCustomTriggerEntryPtrOfPCConfig()                                                (FALSE != FALSE)
#define Dem_Cfg_HasCycleCounterDataOfPCConfig()                                                     (FALSE != FALSE)
#define Dem_Cfg_HasCycleIdTableOfPCConfig()                                                         (TRUE != FALSE)
#define Dem_Cfg_HasDTCSelectorTableOfPCConfig()                                                     (TRUE != FALSE)
#define Dem_Cfg_HasDTCStatusAvailabilityMaskInVariantOfPCConfig()                                   (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableErec2CollIndOfPCConfig()                                      (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableIdxOfDataCollectionTableEdr2CollIndOfPCConfig()               (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableIdxOfDataCollectionTableFfm2CollIndOfPCConfig()               (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTableOfPCConfig()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasDataCollectionTablePid2CollIndOfPCConfig()                                       (FALSE != FALSE)
#define Dem_Cfg_HasDataElementTableIdxOfDataElementTableCol2ElmtIndOfPCConfig()                     (TRUE != FALSE)
#define Dem_Cfg_HasDataElementTableOfPCConfig()                                                     (TRUE != FALSE)
#define Dem_Cfg_HasDebounceDataOfPCConfig()                                                         (FALSE != FALSE)
#define Dem_Cfg_HasDebounceIndirectionTableOfPCConfig()                                             (TRUE != FALSE)
#define Dem_Cfg_HasDtcCalibTableOfPCConfig()                                                        (TRUE != FALSE)
#define Dem_Cfg_HasDtcGroupMaskOfPCConfig()                                                         (FALSE != FALSE)
#define Dem_Cfg_HasDtcInvariantDataTableOfPCConfig()                                                (TRUE != FALSE)
#define Dem_Cfg_HasDtcTableOfPCConfig()                                                             (TRUE != FALSE)
#define Dem_Cfg_HasDtrDataOfPCConfig()                                                              (FALSE != FALSE)
#define Dem_Cfg_HasDtrStatusOfPCConfig()                                                            (FALSE != FALSE)
#define Dem_Cfg_HasDtrTableIndOfPCConfig()                                                          (FALSE != FALSE)
#define Dem_Cfg_HasDtrTableOfPCConfig()                                                             (FALSE != FALSE)
#define Dem_Cfg_HasEnableConditionFulfilledOfPCConfig()                                             (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupCounterOfPCConfig()                                          (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupStateOfPCConfig()                                            (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupTableIndOfPCConfig()                                         (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionGroupTableOfPCConfig()                                            (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionInitTableOfPCConfig()                                             (TRUE != FALSE)
#define Dem_Cfg_HasEnableConditionTableOfPCConfig()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasEndIdxOfDemDidClassInDataCollectionTableOfPCConfig()                             (TRUE != FALSE)
#define Dem_Cfg_HasEventAvailableDataOfPCConfig()                                                   (FALSE != FALSE)
#define Dem_Cfg_HasEventAvailableDefaultOfPCConfig()                                                (TRUE != FALSE)
#define Dem_Cfg_HasEventAvailableInVariantOfPCConfig()                                              (TRUE != FALSE)
#define Dem_Cfg_HasEventCalibTableOfPCConfig()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasEventCycleStatusOfPCConfig()                                                     (FALSE != FALSE)
#define Dem_Cfg_HasEventDataChangedOfPCConfig()                                                     (FALSE != FALSE)
#define Dem_Cfg_HasEventDataCommitNumberOfPCConfig()                                                (TRUE != FALSE)
#define Dem_Cfg_HasEventEntryIndexToNvBlockIndexOfPCConfig()                                        (TRUE != FALSE)
#define Dem_Cfg_HasEventEntryInfoTableOfPCConfig()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasEventIndicatorDataOfPCConfig()                                                   (FALSE != FALSE)
#define Dem_Cfg_HasEventInternalStatusOfPCConfig()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasEventInvariantDataTableOfPCConfig()                                              (TRUE != FALSE)
#define Dem_Cfg_HasEventPrecompileDataTableIndOfPCConfig()                                          (TRUE != FALSE)
#define Dem_Cfg_HasEventPrecompileDataTableOfPCConfig()                                             (TRUE != FALSE)
#define Dem_Cfg_HasEventStatusChangedOfPCConfig()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasEventTableOfPCConfig()                                                           (TRUE != FALSE)
#define Dem_Cfg_HasEventTable_ERec2EventIdIndOfPCConfig()                                           (FALSE != FALSE)
#define Dem_Cfg_HasExtendedDataRecordIteratorTableOfPCConfig()                                      (TRUE != FALSE)
#define Dem_Cfg_HasExtendedDataRecordTableOfPCConfig()                                              (TRUE != FALSE)
#define Dem_Cfg_HasExtendedDataTableOfPCConfig()                                                    (TRUE != FALSE)
#define Dem_Cfg_HasFilterInfoTableOfPCConfig()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasFinalMagicNumberOfPCConfig()                                                     (FALSE != FALSE)
#define Dem_Cfg_HasFreezeFrameDataOfPCConfig()                                                      (FALSE != FALSE)
#define Dem_Cfg_HasFreezeFrameIteratorTableOfPCConfig()                                             (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameNumIndirectionTableOfPCConfig()                                       (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameNumTableOfPCConfig()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasFreezeFrameTableOfPCConfig()                                                     (TRUE != FALSE)
#define Dem_Cfg_HasGeneralJ1939TableOfPCConfig()                                                    (FALSE != FALSE)
#define Dem_Cfg_HasGeneralObdInputOfPCConfig()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasGlobalObdRequirementsOfPCConfig()                                                (FALSE != FALSE)
#define Dem_Cfg_HasGlobalSeverityMaskOfPCConfig()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasGlobalSnapshotRecordOfPCConfig()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasIndicatorAttributeTableOfPCConfig()                                              (FALSE != FALSE)
#define Dem_Cfg_HasIndicatorDataOfPCConfig()                                                        (FALSE != FALSE)
#define Dem_Cfg_HasIndicatorEventCountersOfPCConfig()                                               (FALSE != FALSE)
#define Dem_Cfg_HasInitDataHashCodeOfPCConfig()                                                     (FALSE != FALSE)
#define Dem_Cfg_HasInitMonListForFuncOfPCConfig()                                                   (FALSE != FALSE)
#define Dem_Cfg_HasInitMonitorForEventOfPCConfig()                                                  (FALSE != FALSE)
#define Dem_Cfg_HasInitMonitorsForFuncOfPCConfig()                                                  (FALSE != FALSE)
#define Dem_Cfg_HasJ1939EventIdsWithRatioTableOfPCConfig()                                          (FALSE != FALSE)
#define Dem_Cfg_HasJ1939NodeIdIndOfPCConfig()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasJ1939NodeIdOfPCConfig()                                                          (TRUE != FALSE)
#define Dem_Cfg_HasJ1939NodeIndicatorAvailabilityOfPCConfig()                                       (TRUE != FALSE)
#define Dem_Cfg_HasJ1939SpnsInExpandedFreezeFrameTableOfPCConfig()                                  (FALSE != FALSE)
#define Dem_Cfg_HasMaxNumberEventEntryOBDFreezeFrameOfPCConfig()                                    (FALSE != FALSE)
#define Dem_Cfg_HasMemoryCurrentCountOfPCConfig()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasMemoryInfoTableOfPCConfig()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasMemoryStatusOfPCConfig()                                                         (TRUE != FALSE)
#define Dem_Cfg_HasMidTableOfPCConfig()                                                             (FALSE != FALSE)
#define Dem_Cfg_HasMirrorDataOfPCConfig()                                                           (FALSE != FALSE)
#define Dem_Cfg_HasMonitorActivityRatioTableOfPCConfig()                                            (TRUE != FALSE)
#define Dem_Cfg_HasMultiEventTriggeringSlaveEventsTableOfPCConfig()                                 (FALSE != FALSE)
#define Dem_Cfg_HasNoDtcConfiguredOfPCConfig()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasNvBlockDataPtrOfPCConfig()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasNvBlockDataSizeOfPCConfig()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasNvBlockIdOfPCConfig()                                                            (TRUE != FALSE)
#define Dem_Cfg_HasObdCalibTableOfPCConfig()                                                        (FALSE != FALSE)
#define Dem_Cfg_HasObdIumprDataOfPCConfig()                                                         (FALSE != FALSE)
#define Dem_Cfg_HasObdIumprUpdatePendingOfPCConfig()                                                (FALSE != FALSE)
#define Dem_Cfg_HasPIDF501ReadinessSupportedAndCompletedEnforcementMaskOfPCConfig()                 (TRUE != FALSE)
#define Dem_Cfg_HasPIDF501ReadinessUnsupportedEnforcementMaskOfPCConfig()                           (TRUE != FALSE)
#define Dem_Cfg_HasPendingEvaluatedForConfirmedAndActiveConditionInVariantOfPCConfig()              (FALSE != FALSE)
#define Dem_Cfg_HasPermanentDataOfPCConfig()                                                        (FALSE != FALSE)
#define Dem_Cfg_HasPidTableOfPCConfig()                                                             (FALSE != FALSE)
#define Dem_Cfg_HasPrestorageIndexOfPCConfig()                                                      (FALSE != FALSE)
#define Dem_Cfg_HasPrestorageOfPCConfig()                                                           (FALSE != FALSE)
#define Dem_Cfg_HasPrimaryChronologyOfPCConfig()                                                    (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_0OfPCConfig()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_1OfPCConfig()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_2OfPCConfig()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_3OfPCConfig()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_4OfPCConfig()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_5OfPCConfig()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_6OfPCConfig()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_7OfPCConfig()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_8OfPCConfig()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEntry_9OfPCConfig()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasPrimaryEventEntryInitOfPCConfig()                                                (TRUE != FALSE)
#define Dem_Cfg_HasRatioIdTableOfPCConfig()                                                         (FALSE != FALSE)
#define Dem_Cfg_HasReadoutBufferOfPCConfig()                                                        (TRUE != FALSE)
#define Dem_Cfg_HasReportedEventsOfFilterOfPCConfig()                                               (TRUE != FALSE)
#define Dem_Cfg_HasRingBufferOfPCConfig()                                                           (FALSE != FALSE)
#define Dem_Cfg_HasSamplingProfileDidInfoTableOfPCConfig()                                          (FALSE != FALSE)
#define Dem_Cfg_HasSatelliteInfoInvalid_OsApplicationOfPCConfig()                                   (TRUE != FALSE)
#define Dem_Cfg_HasSatelliteInfoOfPCConfig()                                                        (TRUE != FALSE)
#define Dem_Cfg_HasSatelliteTimeDebounceInfoOfPCConfig()                                            (FALSE != FALSE)
#define Dem_Cfg_HasSizeOfCalibrationObdDtcTableOfPCConfig()                                         (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCallbackClearEventAllowedOfPCConfig()                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCallbackDtcStatusChangedOfPCConfig()                                       (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCallbackGetFdcOfPCConfig()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCallbackJ1939DtcStatusChangedOfPCConfig()                                  (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfClearDTCTableOfPCConfig()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfClearDtcNotificationFinishTableOfPCConfig()                                (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfClearDtcNotificationStartTableOfPCConfig()                                 (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfClientTableOfPCConfig()                                                    (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCounterBasedDebounceTableOfPCConfig()                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCustomTimeSeriesFreezeFrameTableOfPCConfig()                               (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCustomTriggerEntryIndexToNvBlockIndexOfPCConfig()                          (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfCustomTriggerEntryPtrOfPCConfig()                                          (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfDTCSelectorTableOfPCConfig()                                               (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfDataCollectionTableOfPCConfig()                                            (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfDataElementTableOfPCConfig()                                               (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfDtcGroupMaskOfPCConfig()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfDtcTableOfPCConfig()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfDtrStatusOfPCConfig()                                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfDtrTableOfPCConfig()                                                       (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEnableConditionFulfilledOfPCConfig()                                       (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEnableConditionGroupCounterOfPCConfig()                                    (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEnableConditionGroupStateOfPCConfig()                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEnableConditionGroupTableOfPCConfig()                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEnableConditionTableOfPCConfig()                                           (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventCycleStatusOfPCConfig()                                               (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventDataChangedOfPCConfig()                                               (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventDataCommitNumberOfPCConfig()                                          (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventEntryIndexToNvBlockIndexOfPCConfig()                                  (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventEntryInfoTableOfPCConfig()                                            (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventIndicatorDataOfPCConfig()                                             (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventInternalStatusOfPCConfig()                                            (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventStatusChangedOfPCConfig()                                             (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfEventTableOfPCConfig()                                                     (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfExtendedDataRecordIteratorTableOfPCConfig()                                (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfFilterInfoTableOfPCConfig()                                                (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfFreezeFrameIteratorTableOfPCConfig()                                       (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfFreezeFrameTableOfPCConfig()                                               (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfGlobalSnapshotRecordOfPCConfig()                                           (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfIndicatorAttributeTableOfPCConfig()                                        (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfIndicatorEventCountersOfPCConfig()                                         (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfInitMonitorForEventOfPCConfig()                                            (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfInitMonitorsForFuncOfPCConfig()                                            (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfJ1939SpnsInExpandedFreezeFrameTableOfPCConfig()                            (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfMemoryCurrentCountOfPCConfig()                                             (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfMemoryInfoTableOfPCConfig()                                                (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfMemoryStatusOfPCConfig()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfMonitorActivityRatioTableOfPCConfig()                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfObdIumprUpdatePendingOfPCConfig()                                          (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfPrestorageIndexOfPCConfig()                                                (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfPrimaryChronologyOfPCConfig()                                              (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfRatioIdTableOfPCConfig()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfReadoutBufferOfPCConfig()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfReportedEventsOfFilterOfPCConfig()                                         (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfSatelliteInfoOfPCConfig()                                                  (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfSpnToEventsWithRatioTableOfPCConfig()                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfStartIdx500miDenRatioTableOfPCConfig()                                     (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfStorageConditionFulfilledOfPCConfig()                                      (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfStorageConditionGroupCounterOfPCConfig()                                   (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfStorageConditionGroupTableOfPCConfig()                                     (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfStorageConditionTableOfPCConfig()                                          (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfSupportedMidsTableOfPCConfig()                                             (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfTimeBasedDebounceTableOfPCConfig()                                         (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfTimeBasedEventTableOfPCConfig()                                            (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfTimeSeriesEntryIndexToNvBlockIndexOfPCConfig()                             (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfTimeSeriesEntryTableOfPCConfig()                                           (TRUE != FALSE)
#define Dem_Cfg_HasSizeOfTimeSeriesSamplingProfileTableOfPCConfig()                                 (TRUE != FALSE)
#define Dem_Cfg_HasSpnToEventsWithRatioTableOfPCConfig()                                            (FALSE != FALSE)
#define Dem_Cfg_HasStartIdx500miDenRatioTableOfPCConfig()                                           (FALSE != FALSE)
#define Dem_Cfg_HasStartIdxOfDemDidClassInDataCollectionTableOfPCConfig()                           (TRUE != FALSE)
#define Dem_Cfg_HasStatusDataOfPCConfig()                                                           (TRUE != FALSE)
#define Dem_Cfg_HasStorageConditionFulfilledOfPCConfig()                                            (FALSE != FALSE)
#define Dem_Cfg_HasStorageConditionGroupCounterOfPCConfig()                                         (FALSE != FALSE)
#define Dem_Cfg_HasStorageConditionGroupTableIndOfPCConfig()                                        (FALSE != FALSE)
#define Dem_Cfg_HasStorageConditionGroupTableOfPCConfig()                                           (FALSE != FALSE)
#define Dem_Cfg_HasStorageConditionInitTableOfPCConfig()                                            (FALSE != FALSE)
#define Dem_Cfg_HasStorageConditionTableOfPCConfig()                                                (FALSE != FALSE)
#define Dem_Cfg_HasSupportedMidsTableOfPCConfig()                                                   (FALSE != FALSE)
#define Dem_Cfg_HasTimeBasedDebounceTableOfPCConfig()                                               (FALSE != FALSE)
#define Dem_Cfg_HasTimeBasedEventTableOfPCConfig()                                                  (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesEntryIndexToNvBlockIndexOfPCConfig()                                   (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesEntryTableOfPCConfig()                                                 (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesFreezeFrameTableOfPCConfig()                                           (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesIndirectionTableOfPCConfig()                                           (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesSamplingProfileCalibTableOfPCConfig()                                  (FALSE != FALSE)
#define Dem_Cfg_HasTimeSeriesSamplingProfileTableOfPCConfig()                                       (FALSE != FALSE)
#define Dem_Cfg_HasUseOBDIIOrOBDonUDSInVariantOfPCConfig()                                          (TRUE != FALSE)
#define Dem_Cfg_HasUseOBDonUDSInVariantOfPCConfig()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasUsePermanentInVariantOfPCConfig()                                                (FALSE != FALSE)
#define Dem_Cfg_HasUseReadinessSupportAndCompletenessEnforcementMaskInVariantOfPCConfig()           (TRUE != FALSE)
#define Dem_Cfg_HasUseReadinessUnsupportedEnforcementBitMaskInVariantOfPCConfig()                   (TRUE != FALSE)
#define Dem_Cfg_HasUseWWHOBDInVariantOfPCConfig()                                                   (TRUE != FALSE)
#define Dem_Cfg_HasUseZEVonUDSInVariantOfPCConfig()                                                 (TRUE != FALSE)
#define Dem_Cfg_HasUserDefinedOriginTableOfPCConfig()                                               (FALSE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCExistsEnumMacros  Dem_Cfg Exists Enum Macros (PRE_COMPILE)
  \brief  These macros can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define Dem_Cfg_ExistsDEM_EVENT_SIGNIFICANCE_OCCURRENCEEventSignificanceOfDtcTable()                (FALSE != FALSE)
#define Dem_Cfg_ExistsDEM_EVENT_SIGNIFICANCE_FAULTEventSignificanceOfDtcTable()                     (TRUE != FALSE)
#define Dem_Cfg_ExistsDEM_EVENT_KIND_BSWEventKindOfEventPrecompileDataTable()                       (FALSE != FALSE)
#define Dem_Cfg_ExistsDEM_EVENT_KIND_SWCEventKindOfEventPrecompileDataTable()                       (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCIncrementDataMacros  Dem_Cfg Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Dem_Cfg_IncCalibrationErrorRegister()                                                       Dem_Cfg_GetCalibrationErrorRegister()++
#define Dem_Cfg_IncClearDTCTable(Index)                                                             Dem_Cfg_GetClearDTCTable(Index)++
#define Dem_Cfg_IncDTCSelectorTable(Index)                                                          Dem_Cfg_GetDTCSelectorTable(Index)++
#define Dem_Cfg_IncDtrStatus(Index)                                                                 
#define Dem_Cfg_IncEnableConditionGroupCounter(Index)                                               Dem_Cfg_GetEnableConditionGroupCounter(Index)++
#define Dem_Cfg_IncEnableConditionGroupState(Index)                                                 Dem_Cfg_GetEnableConditionGroupState(Index)++
#define Dem_Cfg_IncEventCycleStatus(Index)                                                          
#define Dem_Cfg_IncEventDataCommitNumber(Index)                                                     Dem_Cfg_GetEventDataCommitNumber(Index)++
#define Dem_Cfg_IncEventInternalStatus(Index)                                                       Dem_Cfg_GetEventInternalStatus(Index)++
#define Dem_Cfg_IncIndicatorEventCounters(Index)                                                    
#define Dem_Cfg_IncMemoryCurrentCount(Index)                                                        Dem_Cfg_GetMemoryCurrentCount(Index)++
#define Dem_Cfg_IncMemoryStatus(Index)                                                              Dem_Cfg_GetMemoryStatus(Index)++
#define Dem_Cfg_IncMirrorData()                                                                     
#define Dem_Cfg_IncPrestorageIndex(Index)                                                           
#define Dem_Cfg_IncPrimaryChronology(Index)                                                         Dem_Cfg_GetPrimaryChronology(Index)++
#define Dem_Cfg_IncRingBuffer()                                                                     
#define Dem_Cfg_IncStorageConditionGroupCounter(Index)                                              
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCDecrementDataMacros  Dem_Cfg Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Dem_Cfg_DecCalibrationErrorRegister()                                                       Dem_Cfg_GetCalibrationErrorRegister()--
#define Dem_Cfg_DecClearDTCTable(Index)                                                             Dem_Cfg_GetClearDTCTable(Index)--
#define Dem_Cfg_DecDTCSelectorTable(Index)                                                          Dem_Cfg_GetDTCSelectorTable(Index)--
#define Dem_Cfg_DecDtrStatus(Index)                                                                 
#define Dem_Cfg_DecEnableConditionGroupCounter(Index)                                               Dem_Cfg_GetEnableConditionGroupCounter(Index)--
#define Dem_Cfg_DecEnableConditionGroupState(Index)                                                 Dem_Cfg_GetEnableConditionGroupState(Index)--
#define Dem_Cfg_DecEventCycleStatus(Index)                                                          
#define Dem_Cfg_DecEventDataCommitNumber(Index)                                                     Dem_Cfg_GetEventDataCommitNumber(Index)--
#define Dem_Cfg_DecEventInternalStatus(Index)                                                       Dem_Cfg_GetEventInternalStatus(Index)--
#define Dem_Cfg_DecIndicatorEventCounters(Index)                                                    
#define Dem_Cfg_DecMemoryCurrentCount(Index)                                                        Dem_Cfg_GetMemoryCurrentCount(Index)--
#define Dem_Cfg_DecMemoryStatus(Index)                                                              Dem_Cfg_GetMemoryStatus(Index)--
#define Dem_Cfg_DecMirrorData()                                                                     
#define Dem_Cfg_DecPrestorageIndex(Index)                                                           
#define Dem_Cfg_DecPrimaryChronology(Index)                                                         Dem_Cfg_GetPrimaryChronology(Index)--
#define Dem_Cfg_DecRingBuffer()                                                                     
#define Dem_Cfg_DecStorageConditionGroupCounter(Index)                                              
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCAddDataMacros  Dem_Cfg Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define Dem_Cfg_AddCalibrationErrorRegister(Value)                                                  Dem_Cfg_SetCalibrationErrorRegister((Dem_Cfg_GetCalibrationErrorRegister() + Value))
#define Dem_Cfg_AddClearDTCTable(Index, Value)                                                      Dem_Cfg_SetClearDTCTable(Index, (Dem_Cfg_GetClearDTCTable(Index) + Value))
#define Dem_Cfg_AddDTCSelectorTable(Index, Value)                                                   Dem_Cfg_SetDTCSelectorTable(Index, (Dem_Cfg_GetDTCSelectorTable(Index) + Value))
#define Dem_Cfg_AddDtrStatus(Index, Value)                                                          
#define Dem_Cfg_AddEnableConditionGroupCounter(Index, Value)                                        Dem_Cfg_SetEnableConditionGroupCounter(Index, (Dem_Cfg_GetEnableConditionGroupCounter(Index) + Value))
#define Dem_Cfg_AddEnableConditionGroupState(Index, Value)                                          Dem_Cfg_SetEnableConditionGroupState(Index, (Dem_Cfg_GetEnableConditionGroupState(Index) + Value))
#define Dem_Cfg_AddEventCycleStatus(Index, Value)                                                   
#define Dem_Cfg_AddEventDataCommitNumber(Index, Value)                                              Dem_Cfg_SetEventDataCommitNumber(Index, (Dem_Cfg_GetEventDataCommitNumber(Index) + Value))
#define Dem_Cfg_AddEventInternalStatus(Index, Value)                                                Dem_Cfg_SetEventInternalStatus(Index, (Dem_Cfg_GetEventInternalStatus(Index) + Value))
#define Dem_Cfg_AddIndicatorEventCounters(Index, Value)                                             
#define Dem_Cfg_AddMemoryCurrentCount(Index, Value)                                                 Dem_Cfg_SetMemoryCurrentCount(Index, (Dem_Cfg_GetMemoryCurrentCount(Index) + Value))
#define Dem_Cfg_AddMemoryStatus(Index, Value)                                                       Dem_Cfg_SetMemoryStatus(Index, (Dem_Cfg_GetMemoryStatus(Index) + Value))
#define Dem_Cfg_AddMirrorData(Value)                                                                
#define Dem_Cfg_AddPrestorageIndex(Index, Value)                                                    
#define Dem_Cfg_AddPrimaryChronology(Index, Value)                                                  Dem_Cfg_SetPrimaryChronology(Index, (Dem_Cfg_GetPrimaryChronology(Index) + Value))
#define Dem_Cfg_AddRingBuffer(Value)                                                                
#define Dem_Cfg_AddStorageConditionGroupCounter(Index, Value)                                       
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCSubstractDataMacros  Dem_Cfg Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define Dem_Cfg_SubCalibrationErrorRegister(Value)                                                  Dem_Cfg_SetCalibrationErrorRegister((Dem_Cfg_GetCalibrationErrorRegister() - Value))
#define Dem_Cfg_SubClearDTCTable(Index, Value)                                                      Dem_Cfg_SetClearDTCTable(Index, (Dem_Cfg_GetClearDTCTable(Index) - Value))
#define Dem_Cfg_SubDTCSelectorTable(Index, Value)                                                   Dem_Cfg_SetDTCSelectorTable(Index, (Dem_Cfg_GetDTCSelectorTable(Index) - Value))
#define Dem_Cfg_SubDtrStatus(Index, Value)                                                          
#define Dem_Cfg_SubEnableConditionGroupCounter(Index, Value)                                        Dem_Cfg_SetEnableConditionGroupCounter(Index, (Dem_Cfg_GetEnableConditionGroupCounter(Index) - Value))
#define Dem_Cfg_SubEnableConditionGroupState(Index, Value)                                          Dem_Cfg_SetEnableConditionGroupState(Index, (Dem_Cfg_GetEnableConditionGroupState(Index) - Value))
#define Dem_Cfg_SubEventCycleStatus(Index, Value)                                                   
#define Dem_Cfg_SubEventDataCommitNumber(Index, Value)                                              Dem_Cfg_SetEventDataCommitNumber(Index, (Dem_Cfg_GetEventDataCommitNumber(Index) - Value))
#define Dem_Cfg_SubEventInternalStatus(Index, Value)                                                Dem_Cfg_SetEventInternalStatus(Index, (Dem_Cfg_GetEventInternalStatus(Index) - Value))
#define Dem_Cfg_SubIndicatorEventCounters(Index, Value)                                             
#define Dem_Cfg_SubMemoryCurrentCount(Index, Value)                                                 Dem_Cfg_SetMemoryCurrentCount(Index, (Dem_Cfg_GetMemoryCurrentCount(Index) - Value))
#define Dem_Cfg_SubMemoryStatus(Index, Value)                                                       Dem_Cfg_SetMemoryStatus(Index, (Dem_Cfg_GetMemoryStatus(Index) - Value))
#define Dem_Cfg_SubMirrorData(Value)                                                                
#define Dem_Cfg_SubPrestorageIndex(Index, Value)                                                    
#define Dem_Cfg_SubPrimaryChronology(Index, Value)                                                  Dem_Cfg_SetPrimaryChronology(Index, (Dem_Cfg_GetPrimaryChronology(Index) - Value))
#define Dem_Cfg_SubRingBuffer(Value)                                                                
#define Dem_Cfg_SubStorageConditionGroupCounter(Index, Value)                                       
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
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Dem_CfgLTHasMacros  Dem_Cfg Has Macros (LINK)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Dem_HasLTConfig()                                                                           (FALSE != FALSE)
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/



/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
typedef uint8                                                         Dem_Cfg_EventIndicatorAttributeBitFieldType[1];    /* An indicator attribute is assigned to the event referencing this bitfield if the bit with bit position equal to its id in the IndicatorAttributeTable is set. */ 

typedef struct Dem_Cfg_TimeSeriesEntryCompanionType_s {
  uint8 ClientCounter;
  uint8 ReadoutStatus;
}                                                                     Dem_Cfg_TimeSeriesEntryCompanionType; 

typedef P2VAR(Dem_Cfg_TimeSeriesEntryCompanionType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_PtrToTimeSeriesEntryCompanionType; 
typedef P2CONST(Dem_Cfg_TimeSeriesEntryCompanionType, TYPEDEF, DEM_CONST)   Dem_Cfg_PtrToConstTimeSeriesEntryCompanionType; 
typedef CONSTP2VAR(Dem_Cfg_TimeSeriesEntryCompanionType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_ConstPtrToTimeSeriesEntryCompanionType; 
typedef CONSTP2CONST(Dem_Cfg_TimeSeriesEntryCompanionType, TYPEDEF, DEM_CONST) Dem_Cfg_ConstPtrToConstTimeSeriesEntryCompanionType; 

typedef P2VAR(uint8, TYPEDEF, DEM_SHARED_DATA)                        Dem_Cfg_TimeSeriesRingBufferDataPtrType; 

typedef struct Dem_Cfg_RingBufferType_s {
  uint8 CurrentIndex[ 1 /*unused*/];
  uint8 SampleCount[ 1 /*unused*/];
}                                                                     Dem_Cfg_RingBufferType; 

typedef uint16                                                        Dem_Cfg_MaxDebounceValuesType; 

typedef uint8                                                         Dem_Cfg_DebounceLoResTimerType; 

typedef volatile P2VAR(Dem_Com_ProcessorWordType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_ProcessorWordPtrType; 

typedef volatile P2VAR(Dem_SatelliteData_DataType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_SatelliteDataPtrType; 

typedef volatile P2VAR(Dem_SatelliteData_ExtendedDataType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_SatelliteExtendedDataPtrType; 

typedef volatile P2CONST(Dem_SatelliteData_ExtendedDataType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_SatelliteExtendedDataConstPtrType; 

typedef volatile P2VAR(Dem_Cfg_MaxDebounceValuesType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_MaxDebounceValuesPtrType; 

typedef volatile P2CONST(Dem_Cfg_MaxDebounceValuesType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_MaxDebounceValuesConstPtrType; 

typedef P2VAR(Dem_Cfg_DebounceLoResTimerType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_DebounceLoResTimerPtrType; 

typedef P2CONST(Dem_Cfg_DebounceLoResTimerType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_DebounceLoResTimerConstPtrType; 

typedef struct Dem_Cfg_SatelliteInfoTypeInvalid_OsApplication_s {
  volatile Dem_SatelliteData_DataType SatelliteData[ 63 ];
  volatile Dem_Com_ProcessorWordType  SatelliteStatus;
}                                                                     Dem_Cfg_SatelliteInfoTypeInvalid_OsApplication;    /* Data structure for DEM satellite on partition "Invalid_OsApplication" */ 

 /*  Return type of Dem_Cfg_EventRatioIdIdx() and Dem_Cfg_ObdRatioIdIterGet() - returns: ratioIdIndex   */ 
typedef uint8                                                         Dem_RatioIdIndexType; 

typedef struct Dem_Cfg_AdminDataType_s {
  uint16                    ImplementationVersion;
  uint16                    ConfigurationId;
  Dem_Com_ProcessorWordType MemoryOverflow[ 1 /*DEM_CFG_MAX_SIZE_OVERFLOWINDICATOR*/];  /* (DEM_CFG_DATA_OVFLIND == STD_ON) || (DEM_CFG_SUPPORT_OVFLIND_API == STD_ON) */
  uint16                    CycleCounter[ 1 /*DEM_CFG_GLOBAL_CYCLE_COUNT*/];
  uint16                    CycleState;                                                 /* (DEM_CFG_SUPPORT_OPCYCLE_STORAGE == STD_ON) */
}                                                                     Dem_Cfg_AdminDataType; 

typedef struct Dem_Cfg_StatusDataType_s {
  uint16         FirstFailedEvent;
  uint16         FirstConfirmedEvent;
  uint16         MostRecentFailedEvent;
  uint16         MostRecentConfmdEvent;
  volatile uint8 EventStatus[ 63 /*DEM_G_NUMBER_OF_EVENTS (incl. #0)*/];
}                                                                     Dem_Cfg_StatusDataType; 

typedef struct Dem_Cfg_EventEntryBaseType_s {
  uint32 Timestamp;
  uint16 AgingTargetCycle;
  uint16 EventId;
  uint8  OccurrenceCounter;
  uint8  SnapshotHeader;                                                        /* (DEM_CFG_SUPPORT_SRECS == STD_ON) */
  uint8  SnapshotHeaderFifo;                                                    /* (DEM_CFG_SUPPORT_SRECS == STD_ON) */
}                                                                     Dem_Cfg_EventEntryBaseType; 

typedef P2VAR(Dem_Cfg_EventEntryBaseType, TYPEDEF, DEM_SHARED_DATA)   Dem_Cfg_EventEntryBasePtrType; 

typedef P2CONST(Dem_Cfg_EventEntryBaseType, TYPEDEF, DEM_SHARED_DATA) Dem_Cfg_ConstEventEntryBasePtrType; 

typedef struct Dem_Cfg_ReadoutBufferDataEntryType_s { /* Event Memory Entry Type for DemVirtualMaxSumMemory */
  Dem_Cfg_EventEntryBaseType BaseEntry;
  uint8                      SnapshotData[ 1 ][ 13 ];                           /* (DEM_CFG_SUPPORT_SRECS == STD_ON) */
}                                                                     Dem_Cfg_ReadoutBufferDataEntryType; 

typedef struct Dem_Cfg_PrimaryEntryType_s { /* Event Memory Entry Type for PrimaryMemory */
  Dem_Cfg_EventEntryBaseType BaseEntry;
  uint8                      SnapshotData[ 1 ][ 13 ];                           /* (DEM_CFG_SUPPORT_SRECS == STD_ON) */
}                                                                     Dem_Cfg_PrimaryEntryType; 

typedef struct Dem_Cfg_TimeSeriesEntryBaseType_s {
  uint32  Timestamp;
  uint16  EventId;
  boolean AllSetsStored[ 1 /*DEM_CFG_TIMESERIES_MAX_NUMBER_OF_SERIES*/];        /* Indicates whether all sets are stored. */
  uint8   NextSetId[ 1 /*DEM_CFG_TIMESERIES_MAX_NUMBER_OF_SERIES*/];            /* The next set index to be stored/updated. */
}                                                                     Dem_Cfg_TimeSeriesEntryBaseType; 

typedef P2VAR(Dem_Cfg_TimeSeriesEntryBaseType, TYPEDEF, DEM_NVM_DATA) Dem_Cfg_PtrToTimeSeriesEntryBaseType; 

typedef P2CONST(Dem_Cfg_TimeSeriesEntryBaseType, TYPEDEF, DEM_NVM_DATA) Dem_Cfg_PtrToConstTimeSeriesEntryBaseType; 
typedef CONSTP2VAR(Dem_Cfg_TimeSeriesEntryBaseType, TYPEDEF, DEM_NVM_DATA) Dem_Cfg_ConstPtrToTimeSeriesEntryBaseType; 

typedef P2VAR(uint8, TYPEDEF, DEM_SHARED_DATA)                        Dem_Cfg_SharedTimeSeriesSnapshotDataPtrType; 

typedef struct Dem_Cfg_PermanentDataEntryType_s { /* Unused typedef, as DEM_CFG_GLOBAL_PERMANENT_SIZE= 0 */
  uint16 EventId;
  uint8  Status;
}                                                                     Dem_Cfg_PermanentDataEntryType; 

typedef struct Dem_Cfg_PermanentDataType_s { /* Unused typedef, as DEM_CFG_GLOBAL_PERMANENT_SIZE= 0 */
  Dem_Cfg_PermanentDataEntryType PermanentDataEntry[ 1 /*unused*/];
  uint16                         InitPattern;
}                                                                     Dem_Cfg_PermanentDataType; 

typedef struct Dem_Cfg_FreezeFrameDataEntryType_s { /* Unused typedef, as DEM_CFG_GLOBAL_FREEZEFRAME_SIZE= 0 */
  volatile uint16 EventId;
  uint8           FreezeFrameData[ 1 /*DEM_CFG_MAX_NUM_OBDFREEZEFRAME*/][ 1 /*unused*/];
}                                                                     Dem_Cfg_FreezeFrameDataEntryType; 

typedef Dem_Cfg_FreezeFrameDataEntryType                              Dem_Cfg_FreezeFrameDataType[1];        /* size: [unused] Unused typedef, as ((DEM_CFG_HAS_OBDII_ENABLED == STD_OFF) && (DEM_CFG_SUPPORT_OBDONUDS == STD_OFF)) */ 

typedef sint16                                                        Dem_Cfg_DebounceDataType[1];           /* size: [unused] Unused typedef, as DEM_CFG_GLOBAL_DEBOUNCE_STORAGE_EVENT_COUNT= 0 */ 

typedef uint8                                                         Dem_Cfg_EventAvailableDataType[8];     /* size: [ceiling( DEM_G_NUMBER_OF_EVENTS / 8 )] Unused typedef, as DEM_CFG_SUPPORT_EVENTAVAILABLE_NV==STD_OFF */ 

typedef struct Dem_Cfg_ObdIumprDataType_s { /* Unused typedef, as DEM_G_NUMBER_OF_RATIO_IDS = 0 && DEM_MONITOR_ACTIVITY_DATA is not used */
  uint16 GeneralDenominator;
  uint8  DenominatorConditionStatusReached;
  uint8  DenominatorConditionStatusInhibited;
  uint8  GlobalHybridStatus;
  uint8  GlobalNumeratorsLocked;
}                                                                     Dem_Cfg_ObdIumprDataType; 

typedef struct Dem_Cfg_DtrDataType_s { /* Unused typedef, as DEM_CFG_MAX_NUMBER_CONFIGURABLE_DTRS = 0 */
  uint16 TestValue[ 1 /*unused*/];
  uint16 LowLimValue[ 1 /*unused*/];
  uint16 UppLimValue[ 1 /*unused*/];
}                                                                     Dem_Cfg_DtrDataType; 

typedef struct Dem_Cfg_AgingDataType_s { /* Unused typedef, as DEM_CFG_SUPPORT_AGING_FOR_ALL_DTCS==STD_OFF && DEM_CFG_DATA_AGED_COUNTER==STD_OFF */
  uint8 AgedCounter[ 1 /*unused*/];
}                                                                     Dem_Cfg_AgingDataType; 

typedef struct Dem_Cfg_CycleCounterDataType_s { /* Unused typedef, as DEM_CFG_SUPPORT_MEM_INDEPENDENT_CYCLE_COUNTERS==STD_OFF */
  uint8 FaultPendingCounter[ 1 /*unused*/];
}                                                                     Dem_Cfg_CycleCounterDataType; 

typedef struct Dem_Cfg_PrestorageEntryType_s { /* Unused typedef, as DEM_CFG_GLOBAL_PRESTORED_FF_SIZE= 0 */
  uint16 EventId;                                                               /* An allocated buffer element holds here the EventId. When this buffer element is part of the free list, it is the index of next free buffer. */
  uint8  SnapshotData[ 13 /*DEM_CFG_MAX_SIZE_SNAPSHOT*/];                       /* (DEM_CFG_SUPPORT_SRECS == STD_ON) */
  uint8  State;
}                                                                     Dem_Cfg_PrestorageEntryType; 

typedef Dem_Cfg_PrestorageEntryType                                   Dem_Cfg_PrestorageType[1];             /* size: [1 + DEM_CFG_GLOBAL_PRESTORED_FF_SIZE] */ 

typedef struct Dem_Cfg_CustomTriggerEntryType_s { /* Unused typedef, as DEM_CFG_SUPPORT_CUSTOMTRIGGER_SREC ==STD_OFF || DEM_CFG_SUPPORT_CUSTOMTRIGGER_TSSR == STD_OFF */
  uint32 Timestamp;
  uint16 EventId;
}                                                                     Dem_Cfg_CustomTriggerEntryType; 

typedef P2VAR(Dem_Cfg_CustomTriggerEntryType, TYPEDEF, DEM_SHARED_DATA) Dem_Cfg_CustomTriggerEntryPtrType; 

typedef P2CONST(Dem_Cfg_CustomTriggerEntryType, TYPEDEF, DEM_SHARED_DATA) Dem_Cfg_PtrToConstCustomTriggerEntryType; 

typedef struct Dem_Cfg_IndicatorType_s { /* Unused typedef, as DEM_CFG_PER_INDICATOR_ACTIVATION ==STD_OFF */
  uint8 RequestedIndicator[ 1 /*unused*/][ 1 /*unused*/];
}                                                                     Dem_Cfg_IndicatorType; 

typedef uint8                                                         Dem_Cfg_NvBlockIndexType;              /* Datatype used to access Dem_Cfg_NvBlockId[], Dem_Cfg_NvBlockDataSize[], Dem_Cfg_NvBlockDataPtr[] and other Nv*[] arrays. */ 

typedef uint32                                                        Dem_Cfg_EntryIndexType;                /* Datatype used to access all types of entries (Dem_Cfg_EventEntryInfoTable[], Dem_Cfg_TimeSeriesEntry[]) */ 

typedef uint8                                                         Dem_Cfg_DtrStatusType; 

 /*  Iterator data for Dem_Cfg_FilterData_InfoType  */ 
typedef union Dem_Cfg_Union_ChronoIterType_u { /* PRQA S 0750 */ /* MD_MSR_Union */
  Dem_Cfg_EntryIndexType    ChronoIter;                                         /* chronology iterator for chronological order filtering */
  uint16                    EventIndex;                                         /* Event Id used for linear order filtering */
  uint8                     PermanentIndex;                                     /* permanent entry iterator for permanent filtering */
  Dem_ERec_EventIterType    ERecIterator;                                       /* Iterator for events referencing a specific extended data record */
  Dem_Infra_ComplexIterType SpnIterator;                                        /* Suspect Parameter Number iterator */
}                                                                     Dem_Cfg_Union_ChronoIterType; 

 /*  Table indexes for Dem_Cfg_FilterData_InfoType  */ 
typedef union Dem_Cfg_Union_TableIndexType_u { /* PRQA S 0750 */ /* MD_MSR_Union */
  uint8                 ReadinessGroupId;                                       /* Readiness Group Id */
  Dem_Cfg_ERecIndexType DataCollectionTableIdx;                                 /* Data collection table index of extended data record */
}                                                                     Dem_Cfg_Union_TableIndexType; 

typedef Dem_Com_ProcessorWordType                                     Dem_Cfg_ProcessedCombinedDTCGroupType[1];    /* size: [1] (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_OFF) */ 

 /*  Filter data for Dcm requests   */ 
typedef struct Dem_Cfg_FilterData_InfoType_s {
  Dem_Cfg_Union_ChronoIterType            Iterator;                             /* Chronology Iterator */
  Dem_FilterData_DTCFilteringStrategyType FilterDtcStrategy;                    /* Active DTC filtering strategy */
  uint16                                  EventId;                              /* Event Id for J1939 Freeze Frame filtering */
  uint16                                  MemoryId;                             /* Filtered event memory */
  uint16                                  NumberOfDTCsTested;                   /* Counter for limiting number of tested DTCs during J1939Dcm DTC filtering */
  Dem_Cfg_Union_TableIndexType            TableIndex;                           /* Table Index for filtering */
  Dem_DTCSeverityType                     SeverityMask;                         /* Severity mask filter */
  Dem_FilterData_FilterType               FilterState;                          /* Filter state */
  Dem_J1939DcmDTCStatusFilterType         DTCStatusFilterType;                  /* J1939Dcm DTC status filter type */
  sint8                                   FaultDetectionCounter;                /* FaultDetectionCounter for FDC filter */
  uint8                                   StatusMask;                           /* Status mask filter */
  uint8                                   FilterFlags;                          /* Filter flags */
  uint8                                   NodeIndex;                            /* Node Index */
}                                                                     Dem_Cfg_FilterData_InfoType; 

typedef uint8                                                         Dem_Cfg_SRecNumerationType; 

 /*  Snapshot entry handle type  */ 
typedef struct Dem_Cfg_SnapshotEntry_Handle_s {
  Dem_Cfg_EntryIndexType         EventEntryIndex;                               /* Event entry handle */
  Dem_Cfg_CombinedGroupIndexType CombinedGroupIndex;                            /* Combined Group Index, DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON */
  uint16                         EventId;                                       /* Event ID */
  Dem_Cfg_SRecIndexType          SRecIndex;                                     /* Index in FreezeFrameNumTable */
  Dem_Cfg_SRecIndexType          SRecIndex2;                                    /* Index in FreezeFrameNumTable for second freeze frame list */
  uint8                          EntryIndex;                                    /* SRec entry index */
  uint8                          EntryIndexGlobal;                              /* Global SRec entry index */
  uint8                          OldestFifoEntryIndex;                          /* Oldest Fifo entry index */
  uint8                          NumberOfProcessedRecords;                      /* Number of processed records */
  Dem_Cfg_SRecIndexType          CombinedSRecIndex;                             /* Combined Group SnapShot Iterator,  DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON */
}                                                                     Dem_Cfg_SnapshotEntry_IterType; 

typedef P2VAR(Dem_Cfg_SnapshotEntry_IterType, TYPEDEF, AUTOMATIC)     Dem_Cfg_SnapshotEntry_IterPtrType;     /* PRQA S 0779 */ /* MD_MSR_Rule5.2 */ 

 /*  FreezeFrameIterator data for Dcm requests  */ 
typedef struct Dem_Cfg_FreezeFrameIterator_FilterType_s {
  Dem_Cfg_SnapshotEntry_IterType        SnapshotEntryIter;                      /* Iterator for the snapshot entries */
  Dem_Cfg_EntryIndexType                EventEntryIndex;                        /* Index of current event entry used for reading out freeze frames */
  Dem_Cfg_EntryIndexType                TimeSeriesEntryIndex;                   /* Index of current time series entry used for reading out time series freeze frames */
  Dem_Cfg_EntryIndexType                CustomTriggerEntryIndex;                /* Index of current custom trigger entry used for reading out custom triggered freeze frames */
  Dem_Infra_ComplexIterType             CustomTriggerTssrIter;                  /* Custom triggered time series iterator position */
  Dem_Infra_ComplexIterType             SpnIter;                                /* Iterator for the SPNs in the J1939 expanded Freeze Frame */
  uint16                                EventId;                                /* Event Id for J1939 Freeze Frame filtering */
  Dem_FreezeFrameIterator_DTCFormatType FilterDTCFormat;                        /*  DTCFormat: UDS, OBD, J1939, INIT (no filter)  */
  Dem_J1939DcmSetFreezeFrameFilterType  FreezeFrameKind;                        /* Freeze Frame Kind for J1939 Freeze Frame filtering */
  boolean                               CustomTriggerEntryReadStatus;           /* Flag to indicate whether the readout of the current custom trigger entry has been started */
  uint8                                 TimeSeriesRecordNumber;                 /* time series iterator position */
  uint8                                 NodeIndex;                              /* Node Index for J1939 Freeze Frame filtering */
  uint8                                 FilterState;                            /* Filter state for J1939 Freeze Frame filtering */
}                                                                     Dem_Cfg_FreezeFrameIterator_FilterType; 

 /*  ExtendedDataRecordIterator data for Dcm requests  */ 
typedef struct Dem_Cfg_ExtendedDataRecordIterator_FilterType_s {
  Dem_ERec_EventIterType ERecIterator;                                          /* Iterator for events of extended data record */
  Dem_Cfg_EntryIndexType StoredEventEntryIndex;                                 /* Index to next event entry */
  Dem_DTCOriginType      DTCOrigin;                                             /* Dtc origin */
  Dem_Cfg_ERecIndexType  DataCollectionTableIdx;                                /* Data collection table index of extended data record */
  Dem_DTCFormatType      DTCFormat;                                             /* Dtc format */
}                                                                     Dem_Cfg_ExtendedDataRecordIterator_FilterType; 

typedef Dem_Com_ProcessorWordType                                     Dem_Cfg_ReportedEventsType[2];         /* size: [ceiling( DEM_G_NUMBER_OF_EVENTS / 32 )] = (((DEM_G_NUMBER_OF_EVENTS - 1) / 32) + 1), here: 2. See define DEM_CFG_GLOBAL_PROCESSORWORDS_PER_REPORTEDEVENTSTYPE */ 

typedef uint8                                                         Dem_Cfg_PrestorageIndexType;           /* Span the index values of buffer slots in Dem_Cfg_Prestorage[], i.e. (/DemGeneral/DemMaxNumberPrestoredFF + 1) = 1 entries with index values in range [0..0]. */ 

 /*  Temporary buffer for interaction with NvM  */ 
typedef union Dem_Cfg_CommitBufferType_u { /* PRQA S 0750 */ /* MD_MSR_Union */
  uint8                    mRaw[ 1 ];
  Dem_Cfg_AdminDataType    mAdmin;
  Dem_Cfg_StatusDataType   mStatus;
  Dem_Cfg_PrimaryEntryType mPrimary;
}                                                                     Dem_Cfg_CommitBufferType; 

 /*  Iterator for extended data record types.  */ 
typedef struct Dem_Cfg_DTCReadoutBuffer_ExtendedDataIteratorType_s {
  Dem_ERec_RecordIterType ExtendedRecordIter;                                   /* Iterator for the extended entries */
  uint8                   ExtendedEntryIndex;                                   /* Extended entry index */
}                                                                     Dem_Cfg_DTCReadoutBuffer_ExtendedDataIteratorType; 

typedef P2VAR(Dem_Cfg_DTCReadoutBuffer_ExtendedDataIteratorType, TYPEDEF, AUTOMATIC) Dem_Cfg_DTCReadoutBuffer_ExtendedDataIteratorPtrType;    /* PRQA S 0779 */ /* MD_MSR_Rule5.2 */ 

typedef P2CONST(Dem_Cfg_DTCReadoutBuffer_ExtendedDataIteratorType, TYPEDEF, AUTOMATIC) Dem_Cfg_DTCReadoutBuffer_ExtendedDataIteratorConstPtrType;    /* PRQA S 0779 */ /* MD_MSR_Rule5.2 */ 

 /*  Iterator for snapshot record types.  */ 
typedef struct Dem_Cfg_DTCReadoutBuffer_SnapshotDataIteratorType_s {
  Dem_Cfg_SnapshotEntry_IterType SnapshotEntryIter;                             /* Iterator for the snapshot entries */
  Dem_Infra_ComplexIterType      SourceIterator;                                /* Iterator for the different sources */
}                                                                     Dem_Cfg_DTCReadoutBuffer_SnapshotDataIteratorType; 

typedef P2VAR(Dem_Cfg_DTCReadoutBuffer_SnapshotDataIteratorType, TYPEDEF, AUTOMATIC) Dem_Cfg_DTCReadoutBuffer_SnapshotDataIteratorPtrType;    /* PRQA S 0779 */ /* MD_MSR_Rule5.2 */ 

typedef P2CONST(Dem_Cfg_DTCReadoutBuffer_SnapshotDataIteratorType, TYPEDEF, AUTOMATIC) Dem_Cfg_DTCReadoutBuffer_SnapshotDataIteratorConstPtrType;    /* PRQA S 0779 */ /* MD_MSR_Rule5.2 */ 

 /*  Buffer for OBD Freeze Frame Data used in Dem_Cfg_ReadoutBufferEntryType.  */ 
typedef struct Dem_Cfg_ReadOutBufferFreezeFrameDataEntryType_s {
  uint8   ObdFreezeFrame[ 1 /*DEM_CFG_MAX_NUM_OBDFREEZEFRAME*/][ 1 /*unused*/];
  boolean IsStored;                                                              /* TRUE if event has stored OBD Freeze Frame */
}                                                                     Dem_Cfg_ReadOutBufferFreezeFrameDataEntryType; 

typedef P2VAR(Dem_Cfg_ReadOutBufferFreezeFrameDataEntryType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_ReadOutBufferFreezeFrameDataEntryPtrType; 

 /*  Buffer for subevent entry, one for each subevent.  */ 
typedef struct Dem_Cfg_ReadoutBufferDataType_s {
  Dem_Cfg_ReadoutBufferDataEntryType                Data;                       /* Backed event data */
  Dem_Cfg_DTCReadoutBuffer_ExtendedDataIteratorType ExtendedIterator;           /* Internal state for reporting ExtendedData record(s) */
  Dem_Cfg_DTCReadoutBuffer_SnapshotDataIteratorType SnapshotIterator;           /* Internal state for reporting SnapshotData record(s) */
  uint16                                            EventId;                    /* Subevent ID */
}                                                                     Dem_Cfg_ReadoutBufferDataType; 

typedef P2VAR(Dem_Cfg_ReadoutBufferDataType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_ReadoutBufferDataPtrType; 

 /*  Buffer for statistical data stored outside of the event entry.  */ 
typedef struct Dem_Cfg_ReadoutMemIndeCounterType_s { /* Unused typedef, as DEM_CFG_SUPPORT_MEM_INDEPENDENT_CYCLE_COUNTERS==STD_OFF && DEM_CFG_SUPPORT_MEM_INDEPENDENT_MAX_FDC_SLCand no event memory independent data elements requiring protection supported */
  uint8 FaultPendingCounter;
}                                                                     Dem_Cfg_ReadoutMemIndeCounterType; 

typedef P2CONST(Dem_Cfg_ReadoutMemIndeCounterType, TYPEDEF, AUTOMATIC) Dem_Cfg_ReadoutMemIndeCounterConstPtrType;    /* PRQA S 0779 */ /* MD_MSR_Rule5.2 */ 

 /*  Buffer for Event Data, used after calling Dem_DisableDTCRecordUpdate().  */ 
typedef struct Dem_Cfg_ReadoutBufferEntryType_s {
  Dem_Cfg_ReadoutBufferDataType                 ReadOutBufferData[ 1 ];         /* General: Backed (sub-)event data */
  Dem_DTCReadoutBuffer_SnapshotSourceType       Source;                         /* Data record selection: The source of a selected snapshot */
  uint16                                        MemoryId;                       /* General: MemoryId of this request */
  uint8                                         State;                          /* General: Internal state of this buffer, see Dem_DTCReadoutBuffer_StatusType */
  Dem_Cfg_ReadOutBufferFreezeFrameDataEntryType OBDFreezeFrameData;             /* General: Backed OBD freeze frame data */
  uint8                                         SelectedSnapshotRecordNumber;   /* Data record selection: Selected FreezeFrame Record Number */
  boolean                                       SnapshotSelected;               /* Data record selection: Specifies whether a snapshot is selected or not  */
  uint8                                         SelectedExtendedDataNumber;     /* Data record selection: Selected Extended Data Record Number */
  boolean                                       ExtendedRecordSelected;         /* Data record selection: Specifies whether an extended data record is selected or not  */
}                                                                     Dem_Cfg_ReadoutBufferEntryType; 

typedef P2VAR(Dem_Cfg_ReadoutBufferEntryType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_ReadoutBufferEntryPtrType; 

typedef P2VAR(Dem_Cfg_EntryIndexType, TYPEDEF, DEM_VAR_CLEARED)       Dem_Cfg_ChronoStackPtrType; 

typedef uint16                                                        Dem_Cfg_EventMemoryStorageTriggerType; 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  Dem_CfgPCSizeOfTypes  Dem_Cfg SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for Dem_Cfg_SizeOfCalibrationObdDtcTable */
typedef uint8 Dem_Cfg_SizeOfCalibrationObdDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfCallbackClearEventAllowed */
typedef uint8 Dem_Cfg_SizeOfCallbackClearEventAllowedType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfCallbackDtcStatusChanged */
typedef uint8 Dem_Cfg_SizeOfCallbackDtcStatusChangedType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfCallbackGetFdc */
typedef uint8 Dem_Cfg_SizeOfCallbackGetFdcType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfCallbackJ1939DtcStatusChanged */
typedef uint8 Dem_Cfg_SizeOfCallbackJ1939DtcStatusChangedType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfClearDTCTable */
typedef uint8 Dem_Cfg_SizeOfClearDTCTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfClearDtcNotificationFinishTable */
typedef uint8 Dem_Cfg_SizeOfClearDtcNotificationFinishTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfClearDtcNotificationStartTable */
typedef uint8 Dem_Cfg_SizeOfClearDtcNotificationStartTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfClientTable */
typedef uint8 Dem_Cfg_SizeOfClientTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfCounterBasedDebounceTable */
typedef uint8 Dem_Cfg_SizeOfCounterBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfCustomTimeSeriesFreezeFrameTable */
typedef uint8 Dem_Cfg_SizeOfCustomTimeSeriesFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfCustomTriggerEntryIndexToNvBlockIndex */
typedef uint8 Dem_Cfg_SizeOfCustomTriggerEntryIndexToNvBlockIndexType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfCustomTriggerEntryPtr */
typedef uint8 Dem_Cfg_SizeOfCustomTriggerEntryPtrType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfDTCSelectorTable */
typedef uint8 Dem_Cfg_SizeOfDTCSelectorTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfDataCollectionTable */
typedef uint8 Dem_Cfg_SizeOfDataCollectionTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfDataElementTable */
typedef uint8 Dem_Cfg_SizeOfDataElementTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfDtcGroupMask */
typedef uint8 Dem_Cfg_SizeOfDtcGroupMaskType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfDtcTable */
typedef uint8 Dem_Cfg_SizeOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfDtrStatus */
typedef uint8 Dem_Cfg_SizeOfDtrStatusType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfDtrTable */
typedef uint8 Dem_Cfg_SizeOfDtrTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfEnableConditionFulfilled */
typedef uint8 Dem_Cfg_SizeOfEnableConditionFulfilledType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfEnableConditionGroupCounter */
typedef uint8 Dem_Cfg_SizeOfEnableConditionGroupCounterType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfEnableConditionGroupState */
typedef uint8 Dem_Cfg_SizeOfEnableConditionGroupStateType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfEnableConditionGroupTable */
typedef uint8 Dem_Cfg_SizeOfEnableConditionGroupTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfEnableConditionTable */
typedef uint8 Dem_Cfg_SizeOfEnableConditionTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfEventCycleStatus */
typedef uint8 Dem_Cfg_SizeOfEventCycleStatusType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfEventDataChanged */
typedef uint8 Dem_Cfg_SizeOfEventDataChangedType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfEventDataCommitNumber */
typedef uint8 Dem_Cfg_SizeOfEventDataCommitNumberType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfEventEntryIndexToNvBlockIndex */
typedef uint8 Dem_Cfg_SizeOfEventEntryIndexToNvBlockIndexType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfEventEntryInfoTable */
typedef uint8 Dem_Cfg_SizeOfEventEntryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfEventIndicatorData */
typedef uint8 Dem_Cfg_SizeOfEventIndicatorDataType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfEventInternalStatus */
typedef uint8 Dem_Cfg_SizeOfEventInternalStatusType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfEventStatusChanged */
typedef uint8 Dem_Cfg_SizeOfEventStatusChangedType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfEventTable */
typedef uint8 Dem_Cfg_SizeOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfExtendedDataRecordIteratorTable */
typedef uint8 Dem_Cfg_SizeOfExtendedDataRecordIteratorTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfFilterInfoTable */
typedef uint8 Dem_Cfg_SizeOfFilterInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfFreezeFrameIteratorTable */
typedef uint8 Dem_Cfg_SizeOfFreezeFrameIteratorTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfFreezeFrameTable */
typedef uint8 Dem_Cfg_SizeOfFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfGlobalSnapshotRecord */
typedef uint8 Dem_Cfg_SizeOfGlobalSnapshotRecordType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfIndicatorAttributeTable */
typedef uint8 Dem_Cfg_SizeOfIndicatorAttributeTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfIndicatorEventCounters */
typedef uint8 Dem_Cfg_SizeOfIndicatorEventCountersType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfInitMonitorForEvent */
typedef uint8 Dem_Cfg_SizeOfInitMonitorForEventType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfInitMonitorsForFunc */
typedef uint8 Dem_Cfg_SizeOfInitMonitorsForFuncType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfJ1939SpnsInExpandedFreezeFrameTable */
typedef uint8 Dem_Cfg_SizeOfJ1939SpnsInExpandedFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfMemoryCurrentCount */
typedef uint8 Dem_Cfg_SizeOfMemoryCurrentCountType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfMemoryInfoTable */
typedef uint8 Dem_Cfg_SizeOfMemoryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfMemoryStatus */
typedef uint8 Dem_Cfg_SizeOfMemoryStatusType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfMonitorActivityRatioTable */
typedef uint8 Dem_Cfg_SizeOfMonitorActivityRatioTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfObdIumprUpdatePending */
typedef uint8 Dem_Cfg_SizeOfObdIumprUpdatePendingType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfPrestorageIndex */
typedef uint8 Dem_Cfg_SizeOfPrestorageIndexType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfPrimaryChronology */
typedef uint8 Dem_Cfg_SizeOfPrimaryChronologyType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfRatioIdTable */
typedef uint8 Dem_Cfg_SizeOfRatioIdTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfReadoutBuffer */
typedef uint8 Dem_Cfg_SizeOfReadoutBufferType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfReportedEventsOfFilter */
typedef uint8 Dem_Cfg_SizeOfReportedEventsOfFilterType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfSatelliteInfo */
typedef uint8 Dem_Cfg_SizeOfSatelliteInfoType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfSpnToEventsWithRatioTable */
typedef uint8 Dem_Cfg_SizeOfSpnToEventsWithRatioTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfStartIdx500miDenRatioTable */
typedef uint8 Dem_Cfg_SizeOfStartIdx500miDenRatioTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfStorageConditionFulfilled */
typedef uint8 Dem_Cfg_SizeOfStorageConditionFulfilledType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfStorageConditionGroupCounter */
typedef uint8 Dem_Cfg_SizeOfStorageConditionGroupCounterType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfStorageConditionGroupTable */
typedef uint8 Dem_Cfg_SizeOfStorageConditionGroupTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfStorageConditionTable */
typedef uint8 Dem_Cfg_SizeOfStorageConditionTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfSupportedMidsTable */
typedef uint8 Dem_Cfg_SizeOfSupportedMidsTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfTimeBasedDebounceTable */
typedef uint8 Dem_Cfg_SizeOfTimeBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfTimeBasedEventTable */
typedef uint8 Dem_Cfg_SizeOfTimeBasedEventTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfTimeSeriesEntryIndexToNvBlockIndex */
typedef uint8 Dem_Cfg_SizeOfTimeSeriesEntryIndexToNvBlockIndexType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfTimeSeriesEntryTable */
typedef uint8 Dem_Cfg_SizeOfTimeSeriesEntryTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfTimeSeriesSamplingProfileTable */
typedef uint8 Dem_Cfg_SizeOfTimeSeriesSamplingProfileTableType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Dem_CfgPCIterableTypes  Dem_Cfg Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Dem_Cfg_CalibrationObdDtcTable */
typedef uint8_least Dem_Cfg_CalibrationObdDtcTableIterType;

/**   \brief  type used to iterate Dem_Cfg_CallbackClearEventAllowed */
typedef uint8_least Dem_Cfg_CallbackClearEventAllowedIterType;

/**   \brief  type used to iterate Dem_Cfg_CallbackDtcStatusChanged */
typedef uint8_least Dem_Cfg_CallbackDtcStatusChangedIterType;

/**   \brief  type used to iterate Dem_Cfg_CallbackGetFdc */
typedef uint8_least Dem_Cfg_CallbackGetFdcIterType;

/**   \brief  type used to iterate Dem_Cfg_CallbackJ1939DtcStatusChanged */
typedef uint8_least Dem_Cfg_CallbackJ1939DtcStatusChangedIterType;

/**   \brief  type used to iterate Dem_Cfg_ClearDTCTable */
typedef uint8_least Dem_Cfg_ClearDTCTableIterType;

/**   \brief  type used to iterate Dem_Cfg_ClearDtcNotificationFinishTable */
typedef uint8_least Dem_Cfg_ClearDtcNotificationFinishTableIterType;

/**   \brief  type used to iterate Dem_Cfg_ClearDtcNotificationStartTable */
typedef uint8_least Dem_Cfg_ClearDtcNotificationStartTableIterType;

/**   \brief  type used to iterate Dem_Cfg_ClientTable */
typedef uint8_least Dem_Cfg_ClientTableIterType;

/**   \brief  type used to iterate Dem_Cfg_CommonDidList */
typedef uint8_least Dem_Cfg_CommonDidListIterType;

/**   \brief  type used to iterate Dem_Cfg_CounterBasedDebounceTable */
typedef uint8_least Dem_Cfg_CounterBasedDebounceTableIterType;

/**   \brief  type used to iterate Dem_Cfg_CustomTimeSeriesFreezeFrameTable */
typedef uint8_least Dem_Cfg_CustomTimeSeriesFreezeFrameTableIterType;

/**   \brief  type used to iterate Dem_Cfg_CustomTriggerEntryIndexToNvBlockIndex */
typedef uint8_least Dem_Cfg_CustomTriggerEntryIndexToNvBlockIndexIterType;

/**   \brief  type used to iterate Dem_Cfg_CustomTriggerEntryPtr */
typedef uint8_least Dem_Cfg_CustomTriggerEntryPtrIterType;

/**   \brief  type used to iterate Dem_Cfg_CycleIdTable */
typedef uint8_least Dem_Cfg_CycleIdTableIterType;

/**   \brief  type used to iterate Dem_Cfg_DTCSelectorTable */
typedef uint8_least Dem_Cfg_DTCSelectorTableIterType;

/**   \brief  type used to iterate Dem_Cfg_DataCollectionTable */
typedef uint8_least Dem_Cfg_DataCollectionTableIterType;

/**   \brief  type used to iterate Dem_Cfg_DataCollectionTableErec2CollInd */
typedef uint8_least Dem_Cfg_DataCollectionTableErec2CollIndIterType;

/**   \brief  type used to iterate Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd */
typedef uint8_least Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollIndIterType;

/**   \brief  type used to iterate Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd */
typedef uint8_least Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollIndIterType;

/**   \brief  type used to iterate Dem_Cfg_DataCollectionTablePid2CollInd */
typedef uint8_least Dem_Cfg_DataCollectionTablePid2CollIndIterType;

/**   \brief  type used to iterate Dem_Cfg_DataElementTable */
typedef uint8_least Dem_Cfg_DataElementTableIterType;

/**   \brief  type used to iterate Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd */
typedef uint8_least Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtIndIterType;

/**   \brief  type used to iterate Dem_Cfg_DebounceIndirectionTable */
typedef uint8_least Dem_Cfg_DebounceIndirectionTableIterType;

/**   \brief  type used to iterate Dem_Cfg_DtcCalibTable */
typedef uint8_least Dem_Cfg_DtcCalibTableIterType;

/**   \brief  type used to iterate Dem_Cfg_DtcGroupMask */
typedef uint8_least Dem_Cfg_DtcGroupMaskIterType;

/**   \brief  type used to iterate Dem_Cfg_DtcInvariantDataTable */
typedef uint8_least Dem_Cfg_DtcInvariantDataTableIterType;

/**   \brief  type used to iterate Dem_Cfg_DtcTable */
typedef uint8_least Dem_Cfg_DtcTableIterType;

/**   \brief  type used to iterate Dem_Cfg_DtrStatus */
typedef uint8_least Dem_Cfg_DtrStatusIterType;

/**   \brief  type used to iterate Dem_Cfg_DtrTable */
typedef uint8_least Dem_Cfg_DtrTableIterType;

/**   \brief  type used to iterate Dem_Cfg_DtrTableInd */
typedef uint8_least Dem_Cfg_DtrTableIndIterType;

/**   \brief  type used to iterate Dem_Cfg_EnableConditionGroupTable */
typedef uint8_least Dem_Cfg_EnableConditionGroupTableIterType;

/**   \brief  type used to iterate Dem_Cfg_EnableConditionGroupTableInd */
typedef uint8_least Dem_Cfg_EnableConditionGroupTableIndIterType;

/**   \brief  type used to iterate Dem_Cfg_EnableConditionInitTable */
typedef uint8_least Dem_Cfg_EnableConditionInitTableIterType;

/**   \brief  type used to iterate Dem_Cfg_EnableConditionTable */
typedef uint8_least Dem_Cfg_EnableConditionTableIterType;

/**   \brief  type used to iterate Dem_Cfg_EventAvailableDefault */
typedef uint8_least Dem_Cfg_EventAvailableDefaultIterType;

/**   \brief  type used to iterate Dem_Cfg_EventAvailableInVariant */
typedef uint8_least Dem_Cfg_EventAvailableInVariantIterType;

/**   \brief  type used to iterate Dem_Cfg_EventCalibTable */
typedef uint8_least Dem_Cfg_EventCalibTableIterType;

/**   \brief  type used to iterate Dem_Cfg_EventDataChanged */
typedef uint8_least Dem_Cfg_EventDataChangedIterType;

/**   \brief  type used to iterate Dem_Cfg_EventDataCommitNumber */
typedef uint8_least Dem_Cfg_EventDataCommitNumberIterType;

/**   \brief  type used to iterate Dem_Cfg_EventEntryIndexToNvBlockIndex */
typedef uint8_least Dem_Cfg_EventEntryIndexToNvBlockIndexIterType;

/**   \brief  type used to iterate Dem_Cfg_EventEntryInfoTable */
typedef uint8_least Dem_Cfg_EventEntryInfoTableIterType;

/**   \brief  type used to iterate Dem_Cfg_EventIndicatorData */
typedef uint8_least Dem_Cfg_EventIndicatorDataIterType;

/**   \brief  type used to iterate Dem_Cfg_EventInvariantDataTable */
typedef uint8_least Dem_Cfg_EventInvariantDataTableIterType;

/**   \brief  type used to iterate Dem_Cfg_EventPrecompileDataTable */
typedef uint8_least Dem_Cfg_EventPrecompileDataTableIterType;

/**   \brief  type used to iterate Dem_Cfg_EventPrecompileDataTableInd */
typedef uint8_least Dem_Cfg_EventPrecompileDataTableIndIterType;

/**   \brief  type used to iterate Dem_Cfg_EventStatusChanged */
typedef uint8_least Dem_Cfg_EventStatusChangedIterType;

/**   \brief  type used to iterate Dem_Cfg_EventTable */
typedef uint8_least Dem_Cfg_EventTableIterType;

/**   \brief  type used to iterate Dem_Cfg_EventTable_ERec2EventIdInd */
typedef uint8_least Dem_Cfg_EventTable_ERec2EventIdIndIterType;

/**   \brief  type used to iterate Dem_Cfg_ExtendedDataRecordIteratorTable */
typedef uint8_least Dem_Cfg_ExtendedDataRecordIteratorTableIterType;

/**   \brief  type used to iterate Dem_Cfg_ExtendedDataRecordTable */
typedef uint8_least Dem_Cfg_ExtendedDataRecordTableIterType;

/**   \brief  type used to iterate Dem_Cfg_ExtendedDataTable */
typedef uint8_least Dem_Cfg_ExtendedDataTableIterType;

/**   \brief  type used to iterate Dem_Cfg_FilterInfoTable */
typedef uint8_least Dem_Cfg_FilterInfoTableIterType;

/**   \brief  type used to iterate Dem_Cfg_FreezeFrameIteratorTable */
typedef uint8_least Dem_Cfg_FreezeFrameIteratorTableIterType;

/**   \brief  type used to iterate Dem_Cfg_FreezeFrameNumIndirectionTable */
typedef uint8_least Dem_Cfg_FreezeFrameNumIndirectionTableIterType;

/**   \brief  type used to iterate Dem_Cfg_FreezeFrameNumTable */
typedef uint8_least Dem_Cfg_FreezeFrameNumTableIterType;

/**   \brief  type used to iterate Dem_Cfg_FreezeFrameTable */
typedef uint8_least Dem_Cfg_FreezeFrameTableIterType;

/**   \brief  type used to iterate Dem_Cfg_GeneralJ1939Table */
typedef uint8_least Dem_Cfg_GeneralJ1939TableIterType;

/**   \brief  type used to iterate Dem_Cfg_GeneralObdInput */
typedef uint8_least Dem_Cfg_GeneralObdInputIterType;

/**   \brief  type used to iterate Dem_Cfg_GlobalSnapshotRecord */
typedef uint8_least Dem_Cfg_GlobalSnapshotRecordIterType;

/**   \brief  type used to iterate Dem_Cfg_IndicatorAttributeTable */
typedef uint8_least Dem_Cfg_IndicatorAttributeTableIterType;

/**   \brief  type used to iterate Dem_Cfg_InitMonListForFunc */
typedef uint8_least Dem_Cfg_InitMonListForFuncIterType;

/**   \brief  type used to iterate Dem_Cfg_InitMonitorForEvent */
typedef uint8_least Dem_Cfg_InitMonitorForEventIterType;

/**   \brief  type used to iterate Dem_Cfg_InitMonitorsForFunc */
typedef uint8_least Dem_Cfg_InitMonitorsForFuncIterType;

/**   \brief  type used to iterate Dem_Cfg_J1939EventIdsWithRatioTable */
typedef uint8_least Dem_Cfg_J1939EventIdsWithRatioTableIterType;

/**   \brief  type used to iterate Dem_Cfg_J1939NodeId */
typedef uint8_least Dem_Cfg_J1939NodeIdIterType;

/**   \brief  type used to iterate Dem_Cfg_J1939NodeIdInd */
typedef uint8_least Dem_Cfg_J1939NodeIdIndIterType;

/**   \brief  type used to iterate Dem_Cfg_J1939NodeIndicatorAvailability */
typedef uint8_least Dem_Cfg_J1939NodeIndicatorAvailabilityIterType;

/**   \brief  type used to iterate Dem_Cfg_J1939SpnsInExpandedFreezeFrameTable */
typedef uint8_least Dem_Cfg_J1939SpnsInExpandedFreezeFrameTableIterType;

/**   \brief  type used to iterate Dem_Cfg_MemoryCurrentCount */
typedef uint8_least Dem_Cfg_MemoryCurrentCountIterType;

/**   \brief  type used to iterate Dem_Cfg_MemoryInfoTable */
typedef uint8_least Dem_Cfg_MemoryInfoTableIterType;

/**   \brief  type used to iterate Dem_Cfg_MemoryStatus */
typedef uint8_least Dem_Cfg_MemoryStatusIterType;

/**   \brief  type used to iterate Dem_Cfg_MidTable */
typedef uint8_least Dem_Cfg_MidTableIterType;

/**   \brief  type used to iterate Dem_Cfg_MonitorActivityRatioTable */
typedef uint8_least Dem_Cfg_MonitorActivityRatioTableIterType;

/**   \brief  type used to iterate Dem_Cfg_MultiEventTriggeringSlaveEventsTable */
typedef uint8_least Dem_Cfg_MultiEventTriggeringSlaveEventsTableIterType;

/**   \brief  type used to iterate Dem_Cfg_NvBlockDataPtr */
typedef uint8_least Dem_Cfg_NvBlockDataPtrIterType;

/**   \brief  type used to iterate Dem_Cfg_NvBlockDataSize */
typedef uint8_least Dem_Cfg_NvBlockDataSizeIterType;

/**   \brief  type used to iterate Dem_Cfg_NvBlockId */
typedef uint8_least Dem_Cfg_NvBlockIdIterType;

/**   \brief  type used to iterate Dem_Cfg_ObdCalibTable */
typedef uint8_least Dem_Cfg_ObdCalibTableIterType;

/**   \brief  type used to iterate Dem_Cfg_ObdIumprUpdatePending */
typedef uint8_least Dem_Cfg_ObdIumprUpdatePendingIterType;

/**   \brief  type used to iterate Dem_Cfg_PidTable */
typedef uint8_least Dem_Cfg_PidTableIterType;

/**   \brief  type used to iterate Dem_Cfg_PrestorageIndex */
typedef uint8_least Dem_Cfg_PrestorageIndexIterType;

/**   \brief  type used to iterate Dem_Cfg_PrimaryChronology */
typedef uint8_least Dem_Cfg_PrimaryChronologyIterType;

/**   \brief  type used to iterate Dem_Cfg_RatioIdTable */
typedef uint8_least Dem_Cfg_RatioIdTableIterType;

/**   \brief  type used to iterate Dem_Cfg_ReadoutBuffer */
typedef uint8_least Dem_Cfg_ReadoutBufferIterType;

/**   \brief  type used to iterate Dem_Cfg_ReportedEventsOfFilter */
typedef uint8_least Dem_Cfg_ReportedEventsOfFilterIterType;

/**   \brief  type used to iterate Dem_Cfg_SamplingProfileDidInfoTable */
typedef uint8_least Dem_Cfg_SamplingProfileDidInfoTableIterType;

/**   \brief  type used to iterate Dem_Cfg_SatelliteInfo */
typedef uint8_least Dem_Cfg_SatelliteInfoIterType;

/**   \brief  type used to iterate Dem_Cfg_SatelliteTimeDebounceInfo */
typedef uint8_least Dem_Cfg_SatelliteTimeDebounceInfoIterType;

/**   \brief  type used to iterate Dem_Cfg_SpnToEventsWithRatioTable */
typedef uint8_least Dem_Cfg_SpnToEventsWithRatioTableIterType;

/**   \brief  type used to iterate Dem_Cfg_StartIdx500miDenRatioTable */
typedef uint8_least Dem_Cfg_StartIdx500miDenRatioTableIterType;

/**   \brief  type used to iterate Dem_Cfg_StorageConditionGroupTable */
typedef uint8_least Dem_Cfg_StorageConditionGroupTableIterType;

/**   \brief  type used to iterate Dem_Cfg_StorageConditionGroupTableInd */
typedef uint8_least Dem_Cfg_StorageConditionGroupTableIndIterType;

/**   \brief  type used to iterate Dem_Cfg_StorageConditionInitTable */
typedef uint8_least Dem_Cfg_StorageConditionInitTableIterType;

/**   \brief  type used to iterate Dem_Cfg_StorageConditionTable */
typedef uint8_least Dem_Cfg_StorageConditionTableIterType;

/**   \brief  type used to iterate Dem_Cfg_SupportedMidsTable */
typedef uint8_least Dem_Cfg_SupportedMidsTableIterType;

/**   \brief  type used to iterate Dem_Cfg_TimeBasedDebounceTable */
typedef uint8_least Dem_Cfg_TimeBasedDebounceTableIterType;

/**   \brief  type used to iterate Dem_Cfg_TimeBasedEventTable */
typedef uint8_least Dem_Cfg_TimeBasedEventTableIterType;

/**   \brief  type used to iterate Dem_Cfg_TimeSeriesEntryIndexToNvBlockIndex */
typedef uint8_least Dem_Cfg_TimeSeriesEntryIndexToNvBlockIndexIterType;

/**   \brief  type used to iterate Dem_Cfg_TimeSeriesEntryTable */
typedef uint8_least Dem_Cfg_TimeSeriesEntryTableIterType;

/**   \brief  type used to iterate Dem_Cfg_TimeSeriesFreezeFrameTable */
typedef uint8_least Dem_Cfg_TimeSeriesFreezeFrameTableIterType;

/**   \brief  type used to iterate Dem_Cfg_TimeSeriesIndirectionTable */
typedef uint8_least Dem_Cfg_TimeSeriesIndirectionTableIterType;

/**   \brief  type used to iterate Dem_Cfg_TimeSeriesSamplingProfileCalibTable */
typedef uint8_least Dem_Cfg_TimeSeriesSamplingProfileCalibTableIterType;

/**   \brief  type used to iterate Dem_Cfg_TimeSeriesSamplingProfileTable */
typedef uint8_least Dem_Cfg_TimeSeriesSamplingProfileTableIterType;

/**   \brief  type used to iterate Dem_Cfg_UserDefinedOriginTable */
typedef uint16_least Dem_Cfg_UserDefinedOriginTableIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCIterableTypesWithSizeRelations  Dem_Cfg Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Dem_Cfg_EnableConditionFulfilled */
typedef Dem_Cfg_EnableConditionTableIterType Dem_Cfg_EnableConditionFulfilledIterType;

/**   \brief  type used to iterate Dem_Cfg_EnableConditionGroupCounter */
typedef Dem_Cfg_EnableConditionGroupTableIterType Dem_Cfg_EnableConditionGroupCounterIterType;

/**   \brief  type used to iterate Dem_Cfg_EnableConditionGroupState */
typedef Dem_Cfg_EnableConditionGroupTableIterType Dem_Cfg_EnableConditionGroupStateIterType;

/**   \brief  type used to iterate Dem_Cfg_EventCycleStatus */
typedef Dem_Cfg_EventTableIterType Dem_Cfg_EventCycleStatusIterType;

/**   \brief  type used to iterate Dem_Cfg_EventInternalStatus */
typedef Dem_Cfg_EventTableIterType Dem_Cfg_EventInternalStatusIterType;

/**   \brief  type used to iterate Dem_Cfg_IndicatorEventCounters */
typedef Dem_Cfg_IndicatorAttributeTableIterType Dem_Cfg_IndicatorEventCountersIterType;

/**   \brief  type used to iterate Dem_Cfg_StorageConditionFulfilled */
typedef Dem_Cfg_StorageConditionTableIterType Dem_Cfg_StorageConditionFulfilledIterType;

/**   \brief  type used to iterate Dem_Cfg_StorageConditionGroupCounter */
typedef Dem_Cfg_StorageConditionGroupTableIterType Dem_Cfg_StorageConditionGroupCounterIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCValueTypes  Dem_Cfg Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Dem_Cfg_CalibrationErrorRegister */
typedef uint8 Dem_Cfg_CalibrationErrorRegisterType;

/**   \brief  value based type definition for Dem_Cfg_AgingAllowedOfCalibrationObdDtcTable */
typedef boolean Dem_Cfg_AgingAllowedOfCalibrationObdDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_AgingCycleCounterThresholdOfCalibrationObdDtcTable */
typedef uint8 Dem_Cfg_AgingCycleCounterThresholdOfCalibrationObdDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_AgingCycleIdOfCalibrationObdDtcTable */
typedef uint8 Dem_Cfg_AgingCycleIdOfCalibrationObdDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_ImmediateNvStorageOfCalibrationObdDtcTable */
typedef boolean Dem_Cfg_ImmediateNvStorageOfCalibrationObdDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_OperationCycleIdOfCalibrationObdDtcTable */
typedef uint8 Dem_Cfg_OperationCycleIdOfCalibrationObdDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_ReadinessGroupOfCalibrationObdDtcTable */
typedef uint8 Dem_Cfg_ReadinessGroupOfCalibrationObdDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_UseExtendedDataRecord0x93OfCalibrationObdDtcTable */
typedef boolean Dem_Cfg_UseExtendedDataRecord0x93OfCalibrationObdDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_ClearDTCIndexOfClientTable */
typedef uint8 Dem_Cfg_ClearDTCIndexOfClientTableType;

/**   \brief  value based type definition for Dem_Cfg_FilterIndexOfClientTable */
typedef uint8 Dem_Cfg_FilterIndexOfClientTableType;

/**   \brief  value based type definition for Dem_Cfg_FreezeFrameIteratorIndexOfClientTable */
typedef uint8 Dem_Cfg_FreezeFrameIteratorIndexOfClientTableType;

/**   \brief  value based type definition for Dem_Cfg_NmNodeIdOfClientTable */
typedef uint16 Dem_Cfg_NmNodeIdOfClientTableType;

/**   \brief  value based type definition for Dem_Cfg_ReadoutBufferIndexOfClientTable */
typedef uint8 Dem_Cfg_ReadoutBufferIndexOfClientTableType;

/**   \brief  value based type definition for Dem_Cfg_SelectorIndexOfClientTable */
typedef uint8 Dem_Cfg_SelectorIndexOfClientTableType;

/**   \brief  value based type definition for Dem_Cfg_FreezeFrameTableIdxOfCommonDidList */
typedef uint8 Dem_Cfg_FreezeFrameTableIdxOfCommonDidListType;

/**   \brief  value based type definition for Dem_Cfg_CompatibilityVersion */
typedef uint32 Dem_Cfg_CompatibilityVersionType;

/**   \brief  value based type definition for Dem_Cfg_ConfigurationId */
typedef uint16 Dem_Cfg_ConfigurationIdType;

/**   \brief  value based type definition for Dem_Cfg_DebounceContinuousOfCounterBasedDebounceTable */
typedef boolean Dem_Cfg_DebounceContinuousOfCounterBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_DecrementStepSizeOfCounterBasedDebounceTable */
typedef sint8 Dem_Cfg_DecrementStepSizeOfCounterBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_EventDebounceBehaviorOfCounterBasedDebounceTable */
typedef boolean Dem_Cfg_EventDebounceBehaviorOfCounterBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_FailedThresholdOfCounterBasedDebounceTable */
typedef sint8 Dem_Cfg_FailedThresholdOfCounterBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_IncrementStepSizeOfCounterBasedDebounceTable */
typedef sint8 Dem_Cfg_IncrementStepSizeOfCounterBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_JumpDownOfCounterBasedDebounceTable */
typedef boolean Dem_Cfg_JumpDownOfCounterBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_JumpDownValueOfCounterBasedDebounceTable */
typedef sint8 Dem_Cfg_JumpDownValueOfCounterBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_JumpUpOfCounterBasedDebounceTable */
typedef boolean Dem_Cfg_JumpUpOfCounterBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_JumpUpValueOfCounterBasedDebounceTable */
typedef sint8 Dem_Cfg_JumpUpValueOfCounterBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_MaskedBitsOfCounterBasedDebounceTable */
typedef uint8 Dem_Cfg_MaskedBitsOfCounterBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_PassedThresholdOfCounterBasedDebounceTable */
typedef sint8 Dem_Cfg_PassedThresholdOfCounterBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_StorageThresholdOfCounterBasedDebounceTable */
typedef uint8 Dem_Cfg_StorageThresholdOfCounterBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_FirstRecordNumberOfCustomTimeSeriesFreezeFrameTable */
typedef uint8 Dem_Cfg_FirstRecordNumberOfCustomTimeSeriesFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_LastRecordNumberOfCustomTimeSeriesFreezeFrameTable */
typedef uint8 Dem_Cfg_LastRecordNumberOfCustomTimeSeriesFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_TimeSeriesSamplingProfileTableIdxOfCustomTimeSeriesFreezeFrameTable */
typedef uint8 Dem_Cfg_TimeSeriesSamplingProfileTableIdxOfCustomTimeSeriesFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_UpdateRecordOfCustomTimeSeriesFreezeFrameTable */
typedef boolean Dem_Cfg_UpdateRecordOfCustomTimeSeriesFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_EndsOnInitOfCycleIdTable */
typedef boolean Dem_Cfg_EndsOnInitOfCycleIdTableType;

/**   \brief  value based type definition for Dem_Cfg_OpCycleTypeOfCycleIdTable */
typedef uint8 Dem_Cfg_OpCycleTypeOfCycleIdTableType;

/**   \brief  value based type definition for Dem_Cfg_DTCStatusAvailabilityMaskInVariant */
typedef uint8 Dem_Cfg_DTCStatusAvailabilityMaskInVariantType;

/**   \brief  value based type definition for Dem_Cfg_CollectionSizeOfDataCollectionTable */
typedef uint8 Dem_Cfg_CollectionSizeOfDataCollectionTableType;

/**   \brief  value based type definition for Dem_Cfg_DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndEndIdxOfDataCollectionTable */
typedef uint8 Dem_Cfg_DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndEndIdxOfDataCollectionTableType;

/**   \brief  value based type definition for Dem_Cfg_DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndStartIdxOfDataCollectionTable */
typedef uint8 Dem_Cfg_DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndStartIdxOfDataCollectionTableType;

/**   \brief  value based type definition for Dem_Cfg_DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndUsedOfDataCollectionTable */
typedef boolean Dem_Cfg_DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndUsedOfDataCollectionTableType;

/**   \brief  value based type definition for Dem_Cfg_EventTable_ERec2EventIdIndEndIdxOfDataCollectionTable */
typedef uint8 Dem_Cfg_EventTable_ERec2EventIdIndEndIdxOfDataCollectionTableType;

/**   \brief  value based type definition for Dem_Cfg_EventTable_ERec2EventIdIndStartIdxOfDataCollectionTable */
typedef uint8 Dem_Cfg_EventTable_ERec2EventIdIndStartIdxOfDataCollectionTableType;

/**   \brief  value based type definition for Dem_Cfg_EventTable_ERec2EventIdIndUsedOfDataCollectionTable */
typedef boolean Dem_Cfg_EventTable_ERec2EventIdIndUsedOfDataCollectionTableType;

/**   \brief  value based type definition for Dem_Cfg_IdNumberOfDataCollectionTable */
typedef uint16 Dem_Cfg_IdNumberOfDataCollectionTableType;

/**   \brief  value based type definition for Dem_Cfg_StorageKindOfDataCollectionTable */
typedef uint8 Dem_Cfg_StorageKindOfDataCollectionTableType;

/**   \brief  value based type definition for Dem_Cfg_TriggerOfDataCollectionTable */
typedef uint16 Dem_Cfg_TriggerOfDataCollectionTableType;

/**   \brief  value based type definition for Dem_Cfg_UpdateOfDataCollectionTable */
typedef boolean Dem_Cfg_UpdateOfDataCollectionTableType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTableErec2CollInd */
typedef uint8 Dem_Cfg_DataCollectionTableErec2CollIndType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd */
typedef uint8 Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollIndType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd */
typedef uint8 Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollIndType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTablePid2CollInd */
typedef uint8 Dem_Cfg_DataCollectionTablePid2CollIndType;

/**   \brief  value based type definition for Dem_Cfg_DataIsStoredInNVOfDataElementTable */
typedef boolean Dem_Cfg_DataIsStoredInNVOfDataElementTableType;

/**   \brief  value based type definition for Dem_Cfg_ElementDataTypeOfDataElementTable */
typedef uint8 Dem_Cfg_ElementDataTypeOfDataElementTableType;

/**   \brief  value based type definition for Dem_Cfg_ElementKindOfDataElementTable */
typedef uint8 Dem_Cfg_ElementKindOfDataElementTableType;

/**   \brief  value based type definition for Dem_Cfg_ElementSizeOfDataElementTable */
typedef uint8 Dem_Cfg_ElementSizeOfDataElementTableType;

/**   \brief  value based type definition for Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd */
typedef uint8 Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtIndType;

/**   \brief  value based type definition for Dem_Cfg_CounterBasedDebounceTableIdxOfDebounceIndirectionTable */
typedef uint8 Dem_Cfg_CounterBasedDebounceTableIdxOfDebounceIndirectionTableType;

/**   \brief  value based type definition for Dem_Cfg_CounterBasedDebounceTableUsedOfDebounceIndirectionTable */
typedef boolean Dem_Cfg_CounterBasedDebounceTableUsedOfDebounceIndirectionTableType;

/**   \brief  value based type definition for Dem_Cfg_TimeBasedDebounceTableIdxOfDebounceIndirectionTable */
typedef uint8 Dem_Cfg_TimeBasedDebounceTableIdxOfDebounceIndirectionTableType;

/**   \brief  value based type definition for Dem_Cfg_TimeBasedDebounceTableUsedOfDebounceIndirectionTable */
typedef boolean Dem_Cfg_TimeBasedDebounceTableUsedOfDebounceIndirectionTableType;

/**   \brief  value based type definition for Dem_Cfg_AgingCycleCounterThresholdOfDtcCalibTable */
typedef uint8 Dem_Cfg_AgingCycleCounterThresholdOfDtcCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_AgingCycleIdOfDtcCalibTable */
typedef uint8 Dem_Cfg_AgingCycleIdOfDtcCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_DtcPriorityOfDtcCalibTable */
typedef uint8 Dem_Cfg_DtcPriorityOfDtcCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_DtcSeverityOfDtcCalibTable */
typedef uint8 Dem_Cfg_DtcSeverityOfDtcCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_UdsDtcOfDtcCalibTable */
typedef uint32 Dem_Cfg_UdsDtcOfDtcCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_GroupMaskOfDtcGroupMask */
typedef uint8 Dem_Cfg_GroupMaskOfDtcGroupMaskType;

/**   \brief  value based type definition for Dem_Cfg_UdsGroupDtcOfDtcGroupMask */
typedef uint8 Dem_Cfg_UdsGroupDtcOfDtcGroupMaskType;

/**   \brief  value based type definition for Dem_Cfg_AgingAllowedOfDtcInvariantDataTable */
typedef boolean Dem_Cfg_AgingAllowedOfDtcInvariantDataTableType;

/**   \brief  value based type definition for Dem_Cfg_FreezeFrameTableSecondStdFFIdxOfDtcInvariantDataTable */
typedef uint8 Dem_Cfg_FreezeFrameTableSecondStdFFIdxOfDtcInvariantDataTableType;

/**   \brief  value based type definition for Dem_Cfg_FreezeFrameTableStdFFIdxOfDtcInvariantDataTable */
typedef uint8 Dem_Cfg_FreezeFrameTableStdFFIdxOfDtcInvariantDataTableType;

/**   \brief  value based type definition for Dem_Cfg_FunctionalUnitOfDtcInvariantDataTable */
typedef uint8 Dem_Cfg_FunctionalUnitOfDtcInvariantDataTableType;

/**   \brief  value based type definition for Dem_Cfg_CustomTimeSeriesFreezeFrameTableIdxOfDtcTable */
typedef uint8 Dem_Cfg_CustomTimeSeriesFreezeFrameTableIdxOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_CustomTimeSeriesFreezeFrameTableUsedOfDtcTable */
typedef boolean Dem_Cfg_CustomTimeSeriesFreezeFrameTableUsedOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_CustomTriggeredSnapshotConfiguredOfDtcTable */
typedef boolean Dem_Cfg_CustomTriggeredSnapshotConfiguredOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_CustomTriggeredTimeSeriesSnapshotConfiguredOfDtcTable */
typedef boolean Dem_Cfg_CustomTriggeredTimeSeriesSnapshotConfiguredOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_DtcObdRelevanceOfDtcTable */
typedef boolean Dem_Cfg_DtcObdRelevanceOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_EventSignificanceOfDtcTable */
typedef uint8 Dem_Cfg_EventSignificanceOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_ExtendedDataTableIdxOfDtcTable */
typedef uint8 Dem_Cfg_ExtendedDataTableIdxOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_FreezeFrameNumIndirectionTableIdxOfDtcTable */
typedef uint8 Dem_Cfg_FreezeFrameNumIndirectionTableIdxOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_FreezeFrameNumIndirectionTableUsedOfDtcTable */
typedef boolean Dem_Cfg_FreezeFrameNumIndirectionTableUsedOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_ImmediateNvStorageOfDtcTable */
typedef boolean Dem_Cfg_ImmediateNvStorageOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_J1939DtcOfDtcTable */
typedef uint32 Dem_Cfg_J1939DtcOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_J1939NodeIdIndEndIdxOfDtcTable */
typedef uint8 Dem_Cfg_J1939NodeIdIndEndIdxOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_J1939NodeIdIndStartIdxOfDtcTable */
typedef uint8 Dem_Cfg_J1939NodeIdIndStartIdxOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_J1939NodeIdIndUsedOfDtcTable */
typedef boolean Dem_Cfg_J1939NodeIdIndUsedOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_SMARIndexOfDtcTable */
typedef uint8 Dem_Cfg_SMARIndexOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_TimeSeriesIndirectionTableEndIdxOfDtcTable */
typedef uint8 Dem_Cfg_TimeSeriesIndirectionTableEndIdxOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_TimeSeriesIndirectionTableStartIdxOfDtcTable */
typedef uint8 Dem_Cfg_TimeSeriesIndirectionTableStartIdxOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_TimeSeriesIndirectionTableUsedOfDtcTable */
typedef boolean Dem_Cfg_TimeSeriesIndirectionTableUsedOfDtcTableType;

/**   \brief  value based type definition for Dem_Cfg_DivisorOfDtrTable */
typedef float32 Dem_Cfg_DivisorOfDtrTableType;

/**   \brief  value based type definition for Dem_Cfg_EventTableIdxOfDtrTable */
typedef uint8 Dem_Cfg_EventTableIdxOfDtrTableType;

/**   \brief  value based type definition for Dem_Cfg_LinearFactorOfDtrTable */
typedef float32 Dem_Cfg_LinearFactorOfDtrTableType;

/**   \brief  value based type definition for Dem_Cfg_OffsetOfDtrTable */
typedef float32 Dem_Cfg_OffsetOfDtrTableType;

/**   \brief  value based type definition for Dem_Cfg_UasidOfDtrTable */
typedef uint8 Dem_Cfg_UasidOfDtrTableType;

/**   \brief  value based type definition for Dem_Cfg_UpdateKindOfDtrTable */
typedef uint8 Dem_Cfg_UpdateKindOfDtrTableType;

/**   \brief  value based type definition for Dem_Cfg_DtrTableInd */
typedef uint8 Dem_Cfg_DtrTableIndType;

/**   \brief  value based type definition for Dem_Cfg_EnableConditionFulfilled */
typedef boolean Dem_Cfg_EnableConditionFulfilledType;

/**   \brief  value based type definition for Dem_Cfg_EnableConditionGroupCounter */
typedef uint8 Dem_Cfg_EnableConditionGroupCounterType;

/**   \brief  value based type definition for Dem_Cfg_EnableConditionGroupState */
typedef uint8 Dem_Cfg_EnableConditionGroupStateType;

/**   \brief  value based type definition for Dem_Cfg_IndexOfEnableConditionGroupTable */
typedef uint8 Dem_Cfg_IndexOfEnableConditionGroupTableType;

/**   \brief  value based type definition for Dem_Cfg_EnableConditionGroupTableInd */
typedef uint8 Dem_Cfg_EnableConditionGroupTableIndType;

/**   \brief  value based type definition for Dem_Cfg_FulfilledAtInitOfEnableConditionInitTable */
typedef boolean Dem_Cfg_FulfilledAtInitOfEnableConditionInitTableType;

/**   \brief  value based type definition for Dem_Cfg_EnableConditionGroupTableIndEndIdxOfEnableConditionTable */
typedef uint8 Dem_Cfg_EnableConditionGroupTableIndEndIdxOfEnableConditionTableType;

/**   \brief  value based type definition for Dem_Cfg_EnableConditionGroupTableIndStartIdxOfEnableConditionTable */
typedef uint8 Dem_Cfg_EnableConditionGroupTableIndStartIdxOfEnableConditionTableType;

/**   \brief  value based type definition for Dem_Cfg_EnableConditionGroupTableIndUsedOfEnableConditionTable */
typedef boolean Dem_Cfg_EnableConditionGroupTableIndUsedOfEnableConditionTableType;

/**   \brief  value based type definition for Dem_Cfg_EndIdxOfDemDidClassInDataCollectionTable */
typedef uint8 Dem_Cfg_EndIdxOfDemDidClassInDataCollectionTableType;

/**   \brief  value based type definition for Dem_Cfg_EventAvailableDefault */
typedef boolean Dem_Cfg_EventAvailableDefaultType;

/**   \brief  value based type definition for Dem_Cfg_EventAvailableInVariant */
typedef boolean Dem_Cfg_EventAvailableInVariantType;

/**   \brief  value based type definition for Dem_Cfg_EventFailureCycleCounterThresholdOfEventCalibTable */
typedef uint8 Dem_Cfg_EventFailureCycleCounterThresholdOfEventCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_OperationCycleIdOfEventCalibTable */
typedef uint8 Dem_Cfg_OperationCycleIdOfEventCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_EventCycleStatus */
typedef uint8 Dem_Cfg_EventCycleStatusType;

/**   \brief  value based type definition for Dem_Cfg_EventDataCommitNumber */
typedef uint8 Dem_Cfg_EventDataCommitNumberType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfExtendedDataOfEventEntryInfoTable */
typedef uint32 Dem_Cfg_SizeOfExtendedDataOfEventEntryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfJ1939ExpFreezeFrameOfEventEntryInfoTable */
typedef uint32 Dem_Cfg_SizeOfJ1939ExpFreezeFrameOfEventEntryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfJ1939FreezeFrameOfEventEntryInfoTable */
typedef uint32 Dem_Cfg_SizeOfJ1939FreezeFrameOfEventEntryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfObdFreezeFrameOfEventEntryInfoTable */
typedef uint32 Dem_Cfg_SizeOfObdFreezeFrameOfEventEntryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_SizeOfSnapshotDataOfEventEntryInfoTable */
typedef uint32 Dem_Cfg_SizeOfSnapshotDataOfEventEntryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_EventHealingTargetOfEventIndicatorData */
typedef uint8 Dem_Cfg_EventHealingTargetOfEventIndicatorDataType;

/**   \brief  value based type definition for Dem_Cfg_DtcTableIdxOfEventInvariantDataTable */
typedef uint8 Dem_Cfg_DtcTableIdxOfEventInvariantDataTableType;

/**   \brief  value based type definition for Dem_Cfg_CallbackGetFdcIdxOfEventPrecompileDataTable */
typedef uint8 Dem_Cfg_CallbackGetFdcIdxOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_DebounceCounterStorageOfEventPrecompileDataTable */
typedef boolean Dem_Cfg_DebounceCounterStorageOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_EventConsiderPtoStatusOfEventPrecompileDataTable */
typedef boolean Dem_Cfg_EventConsiderPtoStatusOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_EventKindOfEventPrecompileDataTable */
typedef uint8 Dem_Cfg_EventKindOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_EventLatchTFOfEventPrecompileDataTable */
typedef boolean Dem_Cfg_EventLatchTFOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_EventStatusChangedEndIdxOfEventPrecompileDataTable */
typedef uint8 Dem_Cfg_EventStatusChangedEndIdxOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_EventStatusChangedStartIdxOfEventPrecompileDataTable */
typedef uint8 Dem_Cfg_EventStatusChangedStartIdxOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_EventStatusChangedUsedOfEventPrecompileDataTable */
typedef boolean Dem_Cfg_EventStatusChangedUsedOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_MaskedBitsOfEventPrecompileDataTable */
typedef uint8 Dem_Cfg_MaskedBitsOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_MultiEventTriggeringSlaveEventsTableEndIdxOfEventPrecompileDataTable */
typedef uint8 Dem_Cfg_MultiEventTriggeringSlaveEventsTableEndIdxOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_MultiEventTriggeringSlaveEventsTableStartIdxOfEventPrecompileDataTable */
typedef uint8 Dem_Cfg_MultiEventTriggeringSlaveEventsTableStartIdxOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_MultiEventTriggeringSlaveEventsTableUsedOfEventPrecompileDataTable */
typedef boolean Dem_Cfg_MultiEventTriggeringSlaveEventsTableUsedOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_MultiEventTriggeringSlaveOfEventPrecompileDataTable */
typedef boolean Dem_Cfg_MultiEventTriggeringSlaveOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_SatelliteEventIdxOfEventPrecompileDataTable */
typedef uint8 Dem_Cfg_SatelliteEventIdxOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_SatelliteInfoIdxOfEventPrecompileDataTable */
typedef uint8 Dem_Cfg_SatelliteInfoIdxOfEventPrecompileDataTableType;

/**   \brief  value based type definition for Dem_Cfg_EventPrecompileDataTableInd */
typedef uint8 Dem_Cfg_EventPrecompileDataTableIndType;

/**   \brief  value based type definition for Dem_Cfg_DtrTableIndEndIdxOfEventTable */
typedef uint8 Dem_Cfg_DtrTableIndEndIdxOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_DtrTableIndStartIdxOfEventTable */
typedef uint8 Dem_Cfg_DtrTableIndStartIdxOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_DtrTableIndUsedOfEventTable */
typedef boolean Dem_Cfg_DtrTableIndUsedOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_EnableConditionGroupTableIdxOfEventTable */
typedef uint8 Dem_Cfg_EnableConditionGroupTableIdxOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_EnableConditionGroupTableUsedOfEventTable */
typedef boolean Dem_Cfg_EnableConditionGroupTableUsedOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_EventCalibTableIdxOfEventTable */
typedef uint8 Dem_Cfg_EventCalibTableIdxOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_EventDestinationOfEventTable */
typedef uint8 Dem_Cfg_EventDestinationOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_EventIndicatorDataIdxOfEventTable */
typedef uint8 Dem_Cfg_EventIndicatorDataIdxOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_EventIndicatorDataUsedOfEventTable */
typedef boolean Dem_Cfg_EventIndicatorDataUsedOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_EventInvariantDataTableIdxOfEventTable */
typedef uint8 Dem_Cfg_EventInvariantDataTableIdxOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_EventPtoTimerIndexOfEventTable */
typedef uint16 Dem_Cfg_EventPtoTimerIndexOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_FailedCycleCounterIndexOfEventTable */
typedef uint8 Dem_Cfg_FailedCycleCounterIndexOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_FaultPendingCounterIndexOfEventTable */
typedef uint8 Dem_Cfg_FaultPendingCounterIndexOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_MaxFDCSinceLastClearIndexOfEventTable */
typedef uint8 Dem_Cfg_MaxFDCSinceLastClearIndexOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_MonitorActivityRatioTableIdxOfEventTable */
typedef uint8 Dem_Cfg_MonitorActivityRatioTableIdxOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_OBDVisibilityDelayedUntilDcyQualificationOfEventTable */
typedef boolean Dem_Cfg_OBDVisibilityDelayedUntilDcyQualificationOfEventTableType;

/**   \brief  value based type definition for Dem_Cfg_EventTable_ERec2EventIdInd */
typedef uint8 Dem_Cfg_EventTable_ERec2EventIdIndType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTableErec2CollIndEndIdxOfExtendedDataRecordTable */
typedef uint8 Dem_Cfg_DataCollectionTableErec2CollIndEndIdxOfExtendedDataRecordTableType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTableErec2CollIndStartIdxOfExtendedDataRecordTable */
typedef uint8 Dem_Cfg_DataCollectionTableErec2CollIndStartIdxOfExtendedDataRecordTableType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTableErec2CollIndUsedOfExtendedDataRecordTable */
typedef boolean Dem_Cfg_DataCollectionTableErec2CollIndUsedOfExtendedDataRecordTableType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndEndIdxOfExtendedDataTable */
typedef uint8 Dem_Cfg_DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndEndIdxOfExtendedDataTableType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndStartIdxOfExtendedDataTable */
typedef uint8 Dem_Cfg_DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndStartIdxOfExtendedDataTableType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndUsedOfExtendedDataTable */
typedef boolean Dem_Cfg_DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndUsedOfExtendedDataTableType;

/**   \brief  value based type definition for Dem_Cfg_MaxRecordSizeOfExtendedDataTable */
typedef uint8 Dem_Cfg_MaxRecordSizeOfExtendedDataTableType;

/**   \brief  value based type definition for Dem_Cfg_FinalMagicNumber */
typedef uint16 Dem_Cfg_FinalMagicNumberType;

/**   \brief  value based type definition for Dem_Cfg_FreezeFrameNumTableEndIdxOfFreezeFrameNumIndirectionTable */
typedef uint8 Dem_Cfg_FreezeFrameNumTableEndIdxOfFreezeFrameNumIndirectionTableType;

/**   \brief  value based type definition for Dem_Cfg_FreezeFrameNumTableSecondEndIdxOfFreezeFrameNumIndirectionTable */
typedef uint8 Dem_Cfg_FreezeFrameNumTableSecondEndIdxOfFreezeFrameNumIndirectionTableType;

/**   \brief  value based type definition for Dem_Cfg_FreezeFrameNumTableSecondStartIdxOfFreezeFrameNumIndirectionTable */
typedef uint8 Dem_Cfg_FreezeFrameNumTableSecondStartIdxOfFreezeFrameNumIndirectionTableType;

/**   \brief  value based type definition for Dem_Cfg_FreezeFrameNumTableSecondUsedOfFreezeFrameNumIndirectionTable */
typedef boolean Dem_Cfg_FreezeFrameNumTableSecondUsedOfFreezeFrameNumIndirectionTableType;

/**   \brief  value based type definition for Dem_Cfg_FreezeFrameNumTableStartIdxOfFreezeFrameNumIndirectionTable */
typedef uint8 Dem_Cfg_FreezeFrameNumTableStartIdxOfFreezeFrameNumIndirectionTableType;

/**   \brief  value based type definition for Dem_Cfg_FreezeFrameNumTableUsedOfFreezeFrameNumIndirectionTable */
typedef boolean Dem_Cfg_FreezeFrameNumTableUsedOfFreezeFrameNumIndirectionTableType;

/**   \brief  value based type definition for Dem_Cfg_FFNumberOfFreezeFrameNumTable */
typedef uint8 Dem_Cfg_FFNumberOfFreezeFrameNumTableType;

/**   \brief  value based type definition for Dem_Cfg_FFTriggerOfFreezeFrameNumTable */
typedef uint16 Dem_Cfg_FFTriggerOfFreezeFrameNumTableType;

/**   \brief  value based type definition for Dem_Cfg_FFUpdateOfFreezeFrameNumTable */
typedef boolean Dem_Cfg_FFUpdateOfFreezeFrameNumTableType;

/**   \brief  value based type definition for Dem_Cfg_IsGlobalOfFreezeFrameNumTable */
typedef boolean Dem_Cfg_IsGlobalOfFreezeFrameNumTableType;

/**   \brief  value based type definition for Dem_Cfg_MaskedBitsOfFreezeFrameNumTable */
typedef uint8 Dem_Cfg_MaskedBitsOfFreezeFrameNumTableType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndEndIdxOfFreezeFrameTable */
typedef uint8 Dem_Cfg_DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndEndIdxOfFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndStartIdxOfFreezeFrameTable */
typedef uint8 Dem_Cfg_DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndStartIdxOfFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndUsedOfFreezeFrameTable */
typedef boolean Dem_Cfg_DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndUsedOfFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_RecordSizeOfFreezeFrameTable */
typedef uint8 Dem_Cfg_RecordSizeOfFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_RecordSizeUdsOfFreezeFrameTable */
typedef uint8 Dem_Cfg_RecordSizeUdsOfFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_RecordSizeOfGeneralJ1939Table */
typedef uint8 Dem_Cfg_RecordSizeOfGeneralJ1939TableType;

/**   \brief  value based type definition for Dem_Cfg_DataElementTableIdxOfGeneralObdInput */
typedef uint8 Dem_Cfg_DataElementTableIdxOfGeneralObdInputType;

/**   \brief  value based type definition for Dem_Cfg_GlobalObdRequirements */
typedef uint8 Dem_Cfg_GlobalObdRequirementsType;

/**   \brief  value based type definition for Dem_Cfg_GlobalSeverityMask */
typedef uint8 Dem_Cfg_GlobalSeverityMaskType;

/**   \brief  value based type definition for Dem_Cfg_FreezeFrameTableIdxOfGlobalSnapshotRecord */
typedef uint8 Dem_Cfg_FreezeFrameTableIdxOfGlobalSnapshotRecordType;

/**   \brief  value based type definition for Dem_Cfg_BehaviourOfIndicatorAttributeTable */
typedef uint8 Dem_Cfg_BehaviourOfIndicatorAttributeTableType;

/**   \brief  value based type definition for Dem_Cfg_FailureCycleCounterThresholdOfIndicatorAttributeTable */
typedef uint8 Dem_Cfg_FailureCycleCounterThresholdOfIndicatorAttributeTableType;

/**   \brief  value based type definition for Dem_Cfg_IdOfIndicatorAttributeTable */
typedef uint8 Dem_Cfg_IdOfIndicatorAttributeTableType;

/**   \brief  value based type definition for Dem_Cfg_J1939NodeIdOfIndicatorAttributeTable */
typedef uint8 Dem_Cfg_J1939NodeIdOfIndicatorAttributeTableType;

/**   \brief  value based type definition for Dem_Cfg_IndicatorEventCounters */
typedef uint16 Dem_Cfg_IndicatorEventCountersType;

/**   \brief  value based type definition for Dem_Cfg_InitDataHashCode */
typedef sint32 Dem_Cfg_InitDataHashCodeType;

/**   \brief  value based type definition for Dem_Cfg_EventIdOfJ1939EventIdsWithRatioTable */
typedef uint8 Dem_Cfg_EventIdOfJ1939EventIdsWithRatioTableType;

/**   \brief  value based type definition for Dem_Cfg_J1939NodeId */
typedef uint8 Dem_Cfg_J1939NodeIdType;

/**   \brief  value based type definition for Dem_Cfg_J1939NodeIdInd */
typedef uint8 Dem_Cfg_J1939NodeIdIndType;

/**   \brief  value based type definition for Dem_Cfg_J1939NodeIndicatorAvailability */
typedef uint8 Dem_Cfg_J1939NodeIndicatorAvailabilityType;

/**   \brief  value based type definition for Dem_Cfg_SpnIdOfJ1939SpnsInExpandedFreezeFrameTable */
typedef uint8 Dem_Cfg_SpnIdOfJ1939SpnsInExpandedFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_SpnSizeOfJ1939SpnsInExpandedFreezeFrameTable */
typedef uint8 Dem_Cfg_SpnSizeOfJ1939SpnsInExpandedFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_MaxNumberEventEntryOBDFreezeFrame */
typedef uint8 Dem_Cfg_MaxNumberEventEntryOBDFreezeFrameType;

/**   \brief  value based type definition for Dem_Cfg_MemoryCurrentCount */
typedef uint8 Dem_Cfg_MemoryCurrentCountType;

/**   \brief  value based type definition for Dem_Cfg_CustomTriggerTranslatedMemoryIdOfMemoryInfoTable */
typedef uint16 Dem_Cfg_CustomTriggerTranslatedMemoryIdOfMemoryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_EnableConditionGroupTableControlDtcSettingGroupIdxOfMemoryInfoTable */
typedef uint8 Dem_Cfg_EnableConditionGroupTableControlDtcSettingGroupIdxOfMemoryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_EnableConditionGroupTableControlDtcSettingGroupUsedOfMemoryInfoTable */
typedef boolean Dem_Cfg_EnableConditionGroupTableControlDtcSettingGroupUsedOfMemoryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_FirstEventOfMemoryInfoTable */
typedef uint8 Dem_Cfg_FirstEventOfMemoryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_IndividualERecSizeOfMemoryInfoTable */
typedef uint8 Dem_Cfg_IndividualERecSizeOfMemoryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_IndividualSRecSizeOfMemoryInfoTable */
typedef uint8 Dem_Cfg_IndividualSRecSizeOfMemoryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_LastEventOfMemoryInfoTable */
typedef uint8 Dem_Cfg_LastEventOfMemoryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_MaxNumberTimeSeriesSetsOfMemoryInfoTable */
typedef uint8 Dem_Cfg_MaxNumberTimeSeriesSetsOfMemoryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_MaxSizeOfMemoryInfoTable */
typedef uint8 Dem_Cfg_MaxSizeOfMemoryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_TimeSeriesFifoSupportOfMemoryInfoTable */
typedef boolean Dem_Cfg_TimeSeriesFifoSupportOfMemoryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_TimeSeriesSetsRecNumOffsetOfMemoryInfoTable */
typedef uint8 Dem_Cfg_TimeSeriesSetsRecNumOffsetOfMemoryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_TimeSeriesTranslatedMemoryIdOfMemoryInfoTable */
typedef uint16 Dem_Cfg_TimeSeriesTranslatedMemoryIdOfMemoryInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_MemoryStatus */
typedef uint8 Dem_Cfg_MemoryStatusType;

/**   \brief  value based type definition for Dem_Cfg_DtrTableIdxOfMidTable */
typedef uint8 Dem_Cfg_DtrTableIdxOfMidTableType;

/**   \brief  value based type definition for Dem_Cfg_MidOfMidTable */
typedef uint8 Dem_Cfg_MidOfMidTableType;

/**   \brief  value based type definition for Dem_Cfg_TidOfMidTable */
typedef uint8 Dem_Cfg_TidOfMidTableType;

/**   \brief  value based type definition for Dem_Cfg_MirrorData */
typedef uint8 Dem_Cfg_MirrorDataType;

/**   \brief  value based type definition for Dem_Cfg_MARIndexOfMonitorActivityRatioTable */
typedef uint16 Dem_Cfg_MARIndexOfMonitorActivityRatioTableType;

/**   \brief  value based type definition for Dem_Cfg_SMARIndexOfMonitorActivityRatioTable */
typedef uint16 Dem_Cfg_SMARIndexOfMonitorActivityRatioTableType;

/**   \brief  value based type definition for Dem_Cfg_EventPrecompileDataTableIdxOfMultiEventTriggeringSlaveEventsTable */
typedef uint8 Dem_Cfg_EventPrecompileDataTableIdxOfMultiEventTriggeringSlaveEventsTableType;

/**   \brief  value based type definition for Dem_Cfg_NoDtcConfigured */
typedef uint8 Dem_Cfg_NoDtcConfiguredType;

/**   \brief  value based type definition for Dem_Cfg_NvBlockDataSize */
typedef uint16 Dem_Cfg_NvBlockDataSizeType;

/**   \brief  value based type definition for Dem_Cfg_NvBlockId */
typedef uint16 Dem_Cfg_NvBlockIdType;

/**   \brief  value based type definition for Dem_Cfg_CalibrationObdDtcTableIdxOfObdCalibTable */
typedef uint8 Dem_Cfg_CalibrationObdDtcTableIdxOfObdCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_CalibrationObdDtcTableUsedOfObdCalibTable */
typedef boolean Dem_Cfg_CalibrationObdDtcTableUsedOfObdCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_ObdDtc3ByteOfObdCalibTable */
typedef uint8 Dem_Cfg_ObdDtc3ByteOfObdCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_ObdDtcOfObdCalibTable */
typedef uint8 Dem_Cfg_ObdDtcOfObdCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_ReadinessGroupOfObdCalibTable */
typedef uint8 Dem_Cfg_ReadinessGroupOfObdCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_ObdIumprUpdatePending */
typedef boolean Dem_Cfg_ObdIumprUpdatePendingType;

/**   \brief  value based type definition for Dem_Cfg_PIDF501ReadinessSupportedAndCompletedEnforcementMask */
typedef uint8 Dem_Cfg_PIDF501ReadinessSupportedAndCompletedEnforcementMaskType;

/**   \brief  value based type definition for Dem_Cfg_PIDF501ReadinessUnsupportedEnforcementMask */
typedef uint8 Dem_Cfg_PIDF501ReadinessUnsupportedEnforcementMaskType;

/**   \brief  value based type definition for Dem_Cfg_PendingEvaluatedForConfirmedAndActiveConditionInVariant */
typedef boolean Dem_Cfg_PendingEvaluatedForConfirmedAndActiveConditionInVariantType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTablePid2CollIndEndIdxOfPidTable */
typedef uint8 Dem_Cfg_DataCollectionTablePid2CollIndEndIdxOfPidTableType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTablePid2CollIndStartIdxOfPidTable */
typedef uint8 Dem_Cfg_DataCollectionTablePid2CollIndStartIdxOfPidTableType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTablePid2CollIndUsedOfPidTable */
typedef boolean Dem_Cfg_DataCollectionTablePid2CollIndUsedOfPidTableType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTableIdxOfSamplingProfileDidInfoTable */
typedef uint8 Dem_Cfg_DataCollectionTableIdxOfSamplingProfileDidInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_DidRingBufferOffsetOfSamplingProfileDidInfoTable */
typedef uint8 Dem_Cfg_DidRingBufferOffsetOfSamplingProfileDidInfoTableType;

/**   \brief  value based type definition for Dem_Cfg_EventCountOfSatelliteInfo */
typedef uint8 Dem_Cfg_EventCountOfSatelliteInfoType;

/**   \brief  value based type definition for Dem_Cfg_EventPrecompileDataTableIndEndIdxOfSatelliteInfo */
typedef uint8 Dem_Cfg_EventPrecompileDataTableIndEndIdxOfSatelliteInfoType;

/**   \brief  value based type definition for Dem_Cfg_EventPrecompileDataTableIndStartIdxOfSatelliteInfo */
typedef uint8 Dem_Cfg_EventPrecompileDataTableIndStartIdxOfSatelliteInfoType;

/**   \brief  value based type definition for Dem_Cfg_EventPrecompileDataTableIndUsedOfSatelliteInfo */
typedef boolean Dem_Cfg_EventPrecompileDataTableIndUsedOfSatelliteInfoType;

/**   \brief  value based type definition for Dem_Cfg_TimeBasedEventTableEndIdxOfSatelliteTimeDebounceInfo */
typedef uint8 Dem_Cfg_TimeBasedEventTableEndIdxOfSatelliteTimeDebounceInfoType;

/**   \brief  value based type definition for Dem_Cfg_TimeBasedEventTableStartIdxOfSatelliteTimeDebounceInfo */
typedef uint8 Dem_Cfg_TimeBasedEventTableStartIdxOfSatelliteTimeDebounceInfoType;

/**   \brief  value based type definition for Dem_Cfg_TimeBasedEventTableUsedOfSatelliteTimeDebounceInfo */
typedef boolean Dem_Cfg_TimeBasedEventTableUsedOfSatelliteTimeDebounceInfoType;

/**   \brief  value based type definition for Dem_Cfg_J1939EventIdsWithRatioTableEndIdxOfSpnToEventsWithRatioTable */
typedef uint8 Dem_Cfg_J1939EventIdsWithRatioTableEndIdxOfSpnToEventsWithRatioTableType;

/**   \brief  value based type definition for Dem_Cfg_J1939EventIdsWithRatioTableStartIdxOfSpnToEventsWithRatioTable */
typedef uint8 Dem_Cfg_J1939EventIdsWithRatioTableStartIdxOfSpnToEventsWithRatioTableType;

/**   \brief  value based type definition for Dem_Cfg_SPNOfSpnToEventsWithRatioTable */
typedef uint8 Dem_Cfg_SPNOfSpnToEventsWithRatioTableType;

/**   \brief  value based type definition for Dem_Cfg_StartIdxOfDemDidClassInDataCollectionTable */
typedef uint8 Dem_Cfg_StartIdxOfDemDidClassInDataCollectionTableType;

/**   \brief  value based type definition for Dem_Cfg_StorageConditionFulfilled */
typedef boolean Dem_Cfg_StorageConditionFulfilledType;

/**   \brief  value based type definition for Dem_Cfg_StorageConditionGroupCounter */
typedef uint8 Dem_Cfg_StorageConditionGroupCounterType;

/**   \brief  value based type definition for Dem_Cfg_IndexOfStorageConditionGroupTable */
typedef uint8 Dem_Cfg_IndexOfStorageConditionGroupTableType;

/**   \brief  value based type definition for Dem_Cfg_StorageConditionGroupTableInd */
typedef uint8 Dem_Cfg_StorageConditionGroupTableIndType;

/**   \brief  value based type definition for Dem_Cfg_FulfilledAtInitOfStorageConditionInitTable */
typedef boolean Dem_Cfg_FulfilledAtInitOfStorageConditionInitTableType;

/**   \brief  value based type definition for Dem_Cfg_StorageConditionGroupTableIndEndIdxOfStorageConditionTable */
typedef uint8 Dem_Cfg_StorageConditionGroupTableIndEndIdxOfStorageConditionTableType;

/**   \brief  value based type definition for Dem_Cfg_StorageConditionGroupTableIndStartIdxOfStorageConditionTable */
typedef uint8 Dem_Cfg_StorageConditionGroupTableIndStartIdxOfStorageConditionTableType;

/**   \brief  value based type definition for Dem_Cfg_StorageConditionGroupTableIndUsedOfStorageConditionTable */
typedef boolean Dem_Cfg_StorageConditionGroupTableIndUsedOfStorageConditionTableType;

/**   \brief  value based type definition for Dem_Cfg_StartIdxMidTableOfSupportedMidsTable */
typedef uint8 Dem_Cfg_StartIdxMidTableOfSupportedMidsTableType;

/**   \brief  value based type definition for Dem_Cfg_DebounceContinuousOfTimeBasedDebounceTable */
typedef boolean Dem_Cfg_DebounceContinuousOfTimeBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_EventDebounceBehaviorOfTimeBasedDebounceTable */
typedef boolean Dem_Cfg_EventDebounceBehaviorOfTimeBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_FailTimerThresholdHighResOfTimeBasedDebounceTable */
typedef sint8 Dem_Cfg_FailTimerThresholdHighResOfTimeBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_FailTimerThresholdLowResOfTimeBasedDebounceTable */
typedef sint8 Dem_Cfg_FailTimerThresholdLowResOfTimeBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_IsLowResolutionOfTimeBasedDebounceTable */
typedef boolean Dem_Cfg_IsLowResolutionOfTimeBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_PassTimerThresholdHighResOfTimeBasedDebounceTable */
typedef sint8 Dem_Cfg_PassTimerThresholdHighResOfTimeBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_PassTimerThresholdLowResOfTimeBasedDebounceTable */
typedef sint8 Dem_Cfg_PassTimerThresholdLowResOfTimeBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_StorageTimerThresholdHighResOfTimeBasedDebounceTable */
typedef sint8 Dem_Cfg_StorageTimerThresholdHighResOfTimeBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_StorageTimerThresholdLowResOfTimeBasedDebounceTable */
typedef sint8 Dem_Cfg_StorageTimerThresholdLowResOfTimeBasedDebounceTableType;

/**   \brief  value based type definition for Dem_Cfg_TimeBasedEventTable */
typedef uint8 Dem_Cfg_TimeBasedEventTableType;

/**   \brief  value based type definition for Dem_Cfg_BufferSizeOfTimeSeriesEntryTable */
typedef uint16 Dem_Cfg_BufferSizeOfTimeSeriesEntryTableType;

/**   \brief  value based type definition for Dem_Cfg_MaxSnapShotSizeOfTimeSeriesEntryTable */
typedef uint16 Dem_Cfg_MaxSnapShotSizeOfTimeSeriesEntryTableType;

/**   \brief  value based type definition for Dem_Cfg_FirstRecordNumberOfTimeSeriesFreezeFrameTable */
typedef uint8 Dem_Cfg_FirstRecordNumberOfTimeSeriesFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_LastRecordNumberOfTimeSeriesFreezeFrameTable */
typedef uint8 Dem_Cfg_LastRecordNumberOfTimeSeriesFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_RecordTriggerOfTimeSeriesFreezeFrameTable */
typedef uint8 Dem_Cfg_RecordTriggerOfTimeSeriesFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_TimeSeriesSamplingProfileTableIdxOfTimeSeriesFreezeFrameTable */
typedef uint8 Dem_Cfg_TimeSeriesSamplingProfileTableIdxOfTimeSeriesFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_UpdateRecordOfTimeSeriesFreezeFrameTable */
typedef boolean Dem_Cfg_UpdateRecordOfTimeSeriesFreezeFrameTableType;

/**   \brief  value based type definition for Dem_Cfg_TimeSeriesFreezeFrameTableIdxOfTimeSeriesIndirectionTable */
typedef uint8 Dem_Cfg_TimeSeriesFreezeFrameTableIdxOfTimeSeriesIndirectionTableType;

/**   \brief  value based type definition for Dem_Cfg_DataCollectionTableIdxOfTimeSeriesSamplingProfileCalibTable */
typedef uint8 Dem_Cfg_DataCollectionTableIdxOfTimeSeriesSamplingProfileCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_PastSamplesOfTimeSeriesSamplingProfileCalibTable */
typedef uint8 Dem_Cfg_PastSamplesOfTimeSeriesSamplingProfileCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_SamplingPeriodTicsOfTimeSeriesSamplingProfileCalibTable */
typedef uint8 Dem_Cfg_SamplingPeriodTicsOfTimeSeriesSamplingProfileCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_SamplingProfileDidInfoTableEndIdxOfTimeSeriesSamplingProfileCalibTable */
typedef uint8 Dem_Cfg_SamplingProfileDidInfoTableEndIdxOfTimeSeriesSamplingProfileCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_SamplingProfileDidInfoTableStartIdxOfTimeSeriesSamplingProfileCalibTable */
typedef uint8 Dem_Cfg_SamplingProfileDidInfoTableStartIdxOfTimeSeriesSamplingProfileCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_SamplingProfileDidInfoTableUsedOfTimeSeriesSamplingProfileCalibTable */
typedef boolean Dem_Cfg_SamplingProfileDidInfoTableUsedOfTimeSeriesSamplingProfileCalibTableType;

/**   \brief  value based type definition for Dem_Cfg_RingBufferSamplesOfTimeSeriesSamplingProfileTable */
typedef uint8 Dem_Cfg_RingBufferSamplesOfTimeSeriesSamplingProfileTableType;

/**   \brief  value based type definition for Dem_Cfg_SampleSizeOfTimeSeriesSamplingProfileTable */
typedef uint16 Dem_Cfg_SampleSizeOfTimeSeriesSamplingProfileTableType;

/**   \brief  value based type definition for Dem_Cfg_SequentialDidIdOfTimeSeriesSamplingProfileTable */
typedef uint8 Dem_Cfg_SequentialDidIdOfTimeSeriesSamplingProfileTableType;

/**   \brief  value based type definition for Dem_Cfg_TimeSeriesSamplingProfileCalibTableIdxOfTimeSeriesSamplingProfileTable */
typedef uint8 Dem_Cfg_TimeSeriesSamplingProfileCalibTableIdxOfTimeSeriesSamplingProfileTableType;

/**   \brief  value based type definition for Dem_Cfg_TotalSamplesOfTimeSeriesSamplingProfileTable */
typedef uint8 Dem_Cfg_TotalSamplesOfTimeSeriesSamplingProfileTableType;

/**   \brief  value based type definition for Dem_Cfg_UseOBDIIOrOBDonUDSInVariant */
typedef boolean Dem_Cfg_UseOBDIIOrOBDonUDSInVariantType;

/**   \brief  value based type definition for Dem_Cfg_UseOBDonUDSInVariant */
typedef boolean Dem_Cfg_UseOBDonUDSInVariantType;

/**   \brief  value based type definition for Dem_Cfg_UsePermanentInVariant */
typedef boolean Dem_Cfg_UsePermanentInVariantType;

/**   \brief  value based type definition for Dem_Cfg_UseReadinessSupportAndCompletenessEnforcementMaskInVariant */
typedef boolean Dem_Cfg_UseReadinessSupportAndCompletenessEnforcementMaskInVariantType;

/**   \brief  value based type definition for Dem_Cfg_UseReadinessUnsupportedEnforcementBitMaskInVariant */
typedef boolean Dem_Cfg_UseReadinessUnsupportedEnforcementBitMaskInVariantType;

/**   \brief  value based type definition for Dem_Cfg_UseWWHOBDInVariant */
typedef boolean Dem_Cfg_UseWWHOBDInVariantType;

/**   \brief  value based type definition for Dem_Cfg_UseZEVonUDSInVariant */
typedef boolean Dem_Cfg_UseZEVonUDSInVariantType;

/**   \brief  value based type definition for Dem_Cfg_MemoryInfoTableIdxOfUserDefinedOriginTable */
typedef uint8 Dem_Cfg_MemoryInfoTableIdxOfUserDefinedOriginTableType;

/**   \brief  value based type definition for Dem_Cfg_MemoryInfoTableUsedOfUserDefinedOriginTable */
typedef boolean Dem_Cfg_MemoryInfoTableUsedOfUserDefinedOriginTableType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Dem_CfgPCStructTypes  Dem_Cfg Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Dem_Cfg_CalibrationObdDtcTable */
typedef struct sDem_Cfg_CalibrationObdDtcTableType
{
  uint8 Dem_Cfg_CalibrationObdDtcTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_CalibrationObdDtcTableType;

/**   \brief  type used in Dem_Cfg_ClientTable */
typedef struct sDem_Cfg_ClientTableType
{
  uint8 Dem_Cfg_ClientTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_ClientTableType;

/**   \brief  type used in Dem_Cfg_CommonDidList */
typedef struct sDem_Cfg_CommonDidListType
{
  uint8 Dem_Cfg_CommonDidListNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_CommonDidListType;

/**   \brief  type used in Dem_Cfg_CounterBasedDebounceTable */
typedef struct sDem_Cfg_CounterBasedDebounceTableType
{
  uint8 Dem_Cfg_CounterBasedDebounceTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_CounterBasedDebounceTableType;

/**   \brief  type used in Dem_Cfg_CustomTimeSeriesFreezeFrameTable */
typedef struct sDem_Cfg_CustomTimeSeriesFreezeFrameTableType
{
  uint8 Dem_Cfg_CustomTimeSeriesFreezeFrameTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_CustomTimeSeriesFreezeFrameTableType;

/**   \brief  type used in Dem_Cfg_CycleIdTable */
typedef struct sDem_Cfg_CycleIdTableType
{
  uint8 Dem_Cfg_CycleIdTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_CycleIdTableType;

/**   \brief  type used in Dem_Cfg_DataCollectionTable */
typedef struct sDem_Cfg_DataCollectionTableType
{
  Dem_Cfg_IdNumberOfDataCollectionTableType IdNumberOfDataCollectionTable;
  Dem_Cfg_CollectionSizeOfDataCollectionTableType CollectionSizeOfDataCollectionTable;
  Dem_Cfg_DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndEndIdxOfDataCollectionTableType DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndEndIdxOfDataCollectionTable;  /**< the end index of the 0:n relation pointing to Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd */
  Dem_Cfg_DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndStartIdxOfDataCollectionTableType DataElementTableCol2ElmtIndDataElementTableCol2ElmtIndStartIdxOfDataCollectionTable;  /**< the start index of the 0:n relation pointing to Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd */
  Dem_Cfg_StorageKindOfDataCollectionTableType StorageKindOfDataCollectionTable;
} Dem_Cfg_DataCollectionTableType;

/**   \brief  type used in Dem_Cfg_DataElementTable */
typedef struct sDem_Cfg_DataElementTableType
{
  Dem_Cfg_ElementDataTypeOfDataElementTableType ElementDataTypeOfDataElementTable;  /**< DataElement data type, returned by Dem_Cfg_DataElementDataType() */
  Dem_Cfg_ElementKindOfDataElementTableType ElementKindOfDataElementTable;  /**< DataElement kind, returned by Dem_Cfg_DataCallbackType() */
  Dem_Cfg_ElementSizeOfDataElementTableType ElementSizeOfDataElementTable;  /**< Size of data element in Byte. */
  Dem_ReadDataFPtrType ReadDataFuncOfDataElementTable;  /**< C-function for getting the data. Its signature depends on ElementKind and ElementDataType */
} Dem_Cfg_DataElementTableType;

/**   \brief  type used in Dem_Cfg_DebounceIndirectionTable */
typedef struct sDem_Cfg_DebounceIndirectionTableType
{
  Dem_Cfg_CounterBasedDebounceTableIdxOfDebounceIndirectionTableType CounterBasedDebounceTableIdxOfDebounceIndirectionTable;  /**< the index of the 0:1 relation pointing to Dem_Cfg_CounterBasedDebounceTable */
} Dem_Cfg_DebounceIndirectionTableType;

/**   \brief  type used in Dem_Cfg_DtcCalibTable */
typedef struct sDem_Cfg_DtcCalibTableType
{
  Dem_Cfg_UdsDtcOfDtcCalibTableType UdsDtcOfDtcCalibTable;
  Dem_Cfg_AgingCycleCounterThresholdOfDtcCalibTableType AgingCycleCounterThresholdOfDtcCalibTable;  /**< DemAgingCycleCounterThreshold of the DemEventParameter/DemEventClass. If AgingAllowedOfEventTable==FALSE and DemAgingCycleCounterThreshold does not exist '255' is set. If AgingAllowedOfEventTable==TRUE and DemAgingCycleCounterThreshold does not exist '0' is set. */
  Dem_Cfg_AgingCycleIdOfDtcCalibTableType AgingCycleIdOfDtcCalibTable;  /**< DemOperationCycle (ID) referenced by DemEventParameter/DemEventClass/DemAgingCycleRef */
  Dem_Cfg_DtcPriorityOfDtcCalibTableType DtcPriorityOfDtcCalibTable;  /**< DemEventParameter/DemEventClass/DemEventPriority, values [1..255] for the configuration range [1..255]. */
} Dem_Cfg_DtcCalibTableType;

/**   \brief  type used in Dem_Cfg_DtcGroupMask */
typedef struct sDem_Cfg_DtcGroupMaskType
{
  uint8 Dem_Cfg_DtcGroupMaskNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_DtcGroupMaskType;

/**   \brief  type used in Dem_Cfg_DtcInvariantDataTable */
typedef struct sDem_Cfg_DtcInvariantDataTableType
{
  Dem_Cfg_FreezeFrameTableStdFFIdxOfDtcInvariantDataTableType FreezeFrameTableStdFFIdxOfDtcInvariantDataTable;  /**< the index of the 1:1 relation pointing to Dem_Cfg_FreezeFrameTable */
  Dem_Cfg_FunctionalUnitOfDtcInvariantDataTableType FunctionalUnitOfDtcInvariantDataTable;
} Dem_Cfg_DtcInvariantDataTableType;

/**   \brief  type used in Dem_Cfg_DtcTable */
typedef struct sDem_Cfg_DtcTableType
{
  Dem_Cfg_ExtendedDataTableIdxOfDtcTableType ExtendedDataTableIdxOfDtcTable;  /**< the index of the 1:1 relation pointing to Dem_Cfg_ExtendedDataTable */
  Dem_Cfg_FreezeFrameNumIndirectionTableIdxOfDtcTableType FreezeFrameNumIndirectionTableIdxOfDtcTable;  /**< the index of the 0:1 relation pointing to Dem_Cfg_FreezeFrameNumIndirectionTable */
  Dem_Cfg_J1939NodeIdIndEndIdxOfDtcTableType J1939NodeIdIndEndIdxOfDtcTable;  /**< the end index of the 0:n relation pointing to Dem_Cfg_J1939NodeIdInd */
  Dem_Cfg_J1939NodeIdIndStartIdxOfDtcTableType J1939NodeIdIndStartIdxOfDtcTable;  /**< the start index of the 0:n relation pointing to Dem_Cfg_J1939NodeIdInd */
} Dem_Cfg_DtcTableType;

/**   \brief  type used in Dem_Cfg_DtrTable */
typedef struct sDem_Cfg_DtrTableType
{
  uint8 Dem_Cfg_DtrTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_DtrTableType;

/**   \brief  type used in Dem_Cfg_EnableConditionGroupTable */
typedef struct sDem_Cfg_EnableConditionGroupTableType
{
  uint8 Dem_Cfg_EnableConditionGroupTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_EnableConditionGroupTableType;

/**   \brief  type used in Dem_Cfg_EnableConditionInitTable */
typedef struct sDem_Cfg_EnableConditionInitTableType
{
  uint8 Dem_Cfg_EnableConditionInitTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_EnableConditionInitTableType;

/**   \brief  type used in Dem_Cfg_EnableConditionTable */
typedef struct sDem_Cfg_EnableConditionTableType
{
  uint8 Dem_Cfg_EnableConditionTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_EnableConditionTableType;

/**   \brief  type used in Dem_Cfg_EventCalibTable */
typedef struct sDem_Cfg_EventCalibTableType
{
  uint8 Dem_Cfg_EventCalibTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_EventCalibTableType;

/**   \brief  type used in Dem_Cfg_EventEntryInfoTable */
typedef struct sDem_Cfg_EventEntryInfoTableType
{
  Dem_Cfg_SizeOfExtendedDataOfEventEntryInfoTableType SizeOfExtendedDataOfEventEntryInfoTable;  /**< Size in bytes of the extended record data buffer. */
  Dem_Cfg_SizeOfJ1939ExpFreezeFrameOfEventEntryInfoTableType SizeOfJ1939ExpFreezeFrameOfEventEntryInfoTable;  /**< Size in bytes of the J1939 expanded freeze frame in the J1939 data buffer. */
  Dem_Cfg_SizeOfJ1939FreezeFrameOfEventEntryInfoTableType SizeOfJ1939FreezeFrameOfEventEntryInfoTable;  /**< Size in bytes of the J1939 freeze frame in the J1939 data buffer. */
  Dem_Cfg_SizeOfObdFreezeFrameOfEventEntryInfoTableType SizeOfObdFreezeFrameOfEventEntryInfoTable;  /**< Size in bytes of the WWH-OBD freeze frame data buffer. */
  Dem_Cfg_SizeOfSnapshotDataOfEventEntryInfoTableType SizeOfSnapshotDataOfEventEntryInfoTable;  /**< Size in bytes of the snapshot data buffer. */
  Dem_Cfg_EventEntryBasePtrType BaseEntryPtrOfEventEntryInfoTable;  /**< Pointer to the event entry base data. */
  Dem_ConstDataPtrType InitPtrOfEventEntryInfoTable;  /**< Pointer to the event entry specific initialization block. */
  Dem_SharedDataPtrType ExtendedDataPtrOfEventEntryInfoTable;  /**< Pointer to the extended record data buffer. */
  Dem_SharedDataPtrType J1939FreezeFrameDataPtrOfEventEntryInfoTable;  /**< Pointer to the J1939 freeze frame data buffer. */
  Dem_SharedDataPtrType ObdFreezeFrameDataPtrOfEventEntryInfoTable;  /**< Pointer to the WWH-OBD freeze frame data buffer. */
  Dem_SharedDataPtrType SnapshotDataPtrOfEventEntryInfoTable;  /**< Pointer to the snapshot data buffer. */
} Dem_Cfg_EventEntryInfoTableType;

/**   \brief  type used in Dem_Cfg_EventIndicatorData */
typedef struct sDem_Cfg_EventIndicatorDataType
{
  uint8 Dem_Cfg_EventIndicatorDataNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_EventIndicatorDataType;

/**   \brief  type used in Dem_Cfg_EventInvariantDataTable */
typedef struct sDem_Cfg_EventInvariantDataTableType
{
  Dem_Cfg_DtcTableIdxOfEventInvariantDataTableType DtcTableIdxOfEventInvariantDataTable;  /**< the index of the 1:1 relation pointing to Dem_Cfg_DtcTable */
} Dem_Cfg_EventInvariantDataTableType;

/**   \brief  type used in Dem_Cfg_EventPrecompileDataTable */
typedef struct sDem_Cfg_EventPrecompileDataTableType
{
  Dem_Cfg_EventStatusChangedEndIdxOfEventPrecompileDataTableType EventStatusChangedEndIdxOfEventPrecompileDataTable;  /**< the end index of the 0:n relation pointing to Dem_Cfg_EventStatusChanged */
  Dem_Cfg_EventStatusChangedStartIdxOfEventPrecompileDataTableType EventStatusChangedStartIdxOfEventPrecompileDataTable;  /**< the start index of the 0:n relation pointing to Dem_Cfg_EventStatusChanged */
} Dem_Cfg_EventPrecompileDataTableType;

/**   \brief  type used in Dem_Cfg_EventTable */
typedef struct sDem_Cfg_EventTableType
{
  uint8 Dem_Cfg_EventTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_EventTableType;

/**   \brief  type used in Dem_Cfg_ExtendedDataRecordTable */
typedef struct sDem_Cfg_ExtendedDataRecordTableType
{
  uint8 Dem_Cfg_ExtendedDataRecordTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_ExtendedDataRecordTableType;

/**   \brief  type used in Dem_Cfg_ExtendedDataTable */
typedef struct sDem_Cfg_ExtendedDataTableType
{
  Dem_Cfg_DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndEndIdxOfExtendedDataTableType DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndEndIdxOfExtendedDataTable;  /**< the end index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd */
  Dem_Cfg_DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndStartIdxOfExtendedDataTableType DataCollectionTableEdr2CollIndDataCollectionTableEdr2CollIndStartIdxOfExtendedDataTable;  /**< the start index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd */
} Dem_Cfg_ExtendedDataTableType;

/**   \brief  type used in Dem_Cfg_FreezeFrameNumIndirectionTable */
typedef struct sDem_Cfg_FreezeFrameNumIndirectionTableType
{
  Dem_Cfg_FreezeFrameNumTableEndIdxOfFreezeFrameNumIndirectionTableType FreezeFrameNumTableEndIdxOfFreezeFrameNumIndirectionTable;  /**< the end index of the 0:n relation pointing to Dem_Cfg_FreezeFrameNumTable */
  Dem_Cfg_FreezeFrameNumTableStartIdxOfFreezeFrameNumIndirectionTableType FreezeFrameNumTableStartIdxOfFreezeFrameNumIndirectionTable;  /**< the start index of the 0:n relation pointing to Dem_Cfg_FreezeFrameNumTable */
} Dem_Cfg_FreezeFrameNumIndirectionTableType;

/**   \brief  type used in Dem_Cfg_FreezeFrameNumTable */
typedef struct sDem_Cfg_FreezeFrameNumTableType
{
  uint8 Dem_Cfg_FreezeFrameNumTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_FreezeFrameNumTableType;

/**   \brief  type used in Dem_Cfg_FreezeFrameTable */
typedef struct sDem_Cfg_FreezeFrameTableType
{
  Dem_Cfg_DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndEndIdxOfFreezeFrameTableType DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndEndIdxOfFreezeFrameTable;  /**< the end index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd */
  Dem_Cfg_DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndStartIdxOfFreezeFrameTableType DataCollectionTableFfm2CollIndDataCollectionTableFfm2CollIndStartIdxOfFreezeFrameTable;  /**< the start index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd */
  Dem_Cfg_RecordSizeOfFreezeFrameTableType RecordSizeOfFreezeFrameTable;  /**< Summarized size of did data that is stored in the SnapshotData[][] of the corresponding Memory Entry Type (i.e. typically without size of dids containing internal data elements). */
  Dem_Cfg_RecordSizeUdsOfFreezeFrameTableType RecordSizeUdsOfFreezeFrameTable;  /**< Summarized size of did data, did numbers and snapshot header (i.e. dynamical payload size of the uds response message). */
} Dem_Cfg_FreezeFrameTableType;

/**   \brief  type used in Dem_Cfg_GeneralJ1939Table */
typedef struct sDem_Cfg_GeneralJ1939TableType
{
  uint8 Dem_Cfg_GeneralJ1939TableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_GeneralJ1939TableType;

/**   \brief  type used in Dem_Cfg_GeneralObdInput */
typedef struct sDem_Cfg_GeneralObdInputType
{
  uint8 Dem_Cfg_GeneralObdInputNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_GeneralObdInputType;

/**   \brief  type used in Dem_Cfg_GlobalSnapshotRecord */
typedef struct sDem_Cfg_GlobalSnapshotRecordType
{
  uint8 Dem_Cfg_GlobalSnapshotRecordNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_GlobalSnapshotRecordType;

/**   \brief  type used in Dem_Cfg_IndicatorAttributeTable */
typedef struct sDem_Cfg_IndicatorAttributeTableType
{
  uint8 Dem_Cfg_IndicatorAttributeTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_IndicatorAttributeTableType;

/**   \brief  type used in Dem_Cfg_InitMonListForFunc */
typedef struct sDem_Cfg_InitMonListForFuncType
{
  uint8 Dem_Cfg_InitMonListForFuncNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_InitMonListForFuncType;

/**   \brief  type used in Dem_Cfg_J1939EventIdsWithRatioTable */
typedef struct sDem_Cfg_J1939EventIdsWithRatioTableType
{
  uint8 Dem_Cfg_J1939EventIdsWithRatioTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_J1939EventIdsWithRatioTableType;

/**   \brief  type used in Dem_Cfg_J1939SpnsInExpandedFreezeFrameTable */
typedef struct sDem_Cfg_J1939SpnsInExpandedFreezeFrameTableType
{
  uint8 Dem_Cfg_J1939SpnsInExpandedFreezeFrameTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_J1939SpnsInExpandedFreezeFrameTableType;

/**   \brief  type used in Dem_Cfg_MemoryInfoTable */
typedef struct sDem_Cfg_MemoryInfoTableType
{
  uint8 Dem_Cfg_MemoryInfoTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_MemoryInfoTableType;

/**   \brief  type used in Dem_Cfg_MidTable */
typedef struct sDem_Cfg_MidTableType
{
  uint8 Dem_Cfg_MidTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_MidTableType;

/**   \brief  type used in Dem_Cfg_MonitorActivityRatioTable */
typedef struct sDem_Cfg_MonitorActivityRatioTableType
{
  uint8 Dem_Cfg_MonitorActivityRatioTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_MonitorActivityRatioTableType;

/**   \brief  type used in Dem_Cfg_MultiEventTriggeringSlaveEventsTable */
typedef struct sDem_Cfg_MultiEventTriggeringSlaveEventsTableType
{
  uint8 Dem_Cfg_MultiEventTriggeringSlaveEventsTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_MultiEventTriggeringSlaveEventsTableType;

/**   \brief  type used in Dem_Cfg_ObdCalibTable */
typedef struct sDem_Cfg_ObdCalibTableType
{
  uint8 Dem_Cfg_ObdCalibTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_ObdCalibTableType;

/**   \brief  type used in Dem_Cfg_PidTable */
typedef struct sDem_Cfg_PidTableType
{
  uint8 Dem_Cfg_PidTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_PidTableType;

/**   \brief  type used in Dem_Cfg_RatioIdTable */
typedef struct sDem_Cfg_RatioIdTableType
{
  uint8 Dem_Cfg_RatioIdTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_RatioIdTableType;

/**   \brief  type used in Dem_Cfg_SamplingProfileDidInfoTable */
typedef struct sDem_Cfg_SamplingProfileDidInfoTableType
{
  uint8 Dem_Cfg_SamplingProfileDidInfoTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_SamplingProfileDidInfoTableType;

/**   \brief  type used in Dem_Cfg_SatelliteInfo */
typedef struct sDem_Cfg_SatelliteInfoType
{
  uint8 Dem_Cfg_SatelliteInfoNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_SatelliteInfoType;

/**   \brief  type used in Dem_Cfg_SatelliteTimeDebounceInfo */
typedef struct sDem_Cfg_SatelliteTimeDebounceInfoType
{
  uint8 Dem_Cfg_SatelliteTimeDebounceInfoNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_SatelliteTimeDebounceInfoType;

/**   \brief  type used in Dem_Cfg_SpnToEventsWithRatioTable */
typedef struct sDem_Cfg_SpnToEventsWithRatioTableType
{
  uint8 Dem_Cfg_SpnToEventsWithRatioTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_SpnToEventsWithRatioTableType;

/**   \brief  type used in Dem_Cfg_StartIdx500miDenRatioTable */
typedef struct sDem_Cfg_StartIdx500miDenRatioTableType
{
  uint8 Dem_Cfg_StartIdx500miDenRatioTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_StartIdx500miDenRatioTableType;

/**   \brief  type used in Dem_Cfg_StorageConditionGroupTable */
typedef struct sDem_Cfg_StorageConditionGroupTableType
{
  uint8 Dem_Cfg_StorageConditionGroupTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_StorageConditionGroupTableType;

/**   \brief  type used in Dem_Cfg_StorageConditionInitTable */
typedef struct sDem_Cfg_StorageConditionInitTableType
{
  uint8 Dem_Cfg_StorageConditionInitTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_StorageConditionInitTableType;

/**   \brief  type used in Dem_Cfg_StorageConditionTable */
typedef struct sDem_Cfg_StorageConditionTableType
{
  uint8 Dem_Cfg_StorageConditionTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_StorageConditionTableType;

/**   \brief  type used in Dem_Cfg_SupportedMidsTable */
typedef struct sDem_Cfg_SupportedMidsTableType
{
  uint8 Dem_Cfg_SupportedMidsTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_SupportedMidsTableType;

/**   \brief  type used in Dem_Cfg_TimeBasedDebounceTable */
typedef struct sDem_Cfg_TimeBasedDebounceTableType
{
  uint8 Dem_Cfg_TimeBasedDebounceTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_TimeBasedDebounceTableType;

/**   \brief  type used in Dem_Cfg_TimeSeriesEntryTable */
typedef struct sDem_Cfg_TimeSeriesEntryTableType
{
  uint8 Dem_Cfg_TimeSeriesEntryTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_TimeSeriesEntryTableType;

/**   \brief  type used in Dem_Cfg_TimeSeriesFreezeFrameTable */
typedef struct sDem_Cfg_TimeSeriesFreezeFrameTableType
{
  uint8 Dem_Cfg_TimeSeriesFreezeFrameTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_TimeSeriesFreezeFrameTableType;

/**   \brief  type used in Dem_Cfg_TimeSeriesIndirectionTable */
typedef struct sDem_Cfg_TimeSeriesIndirectionTableType
{
  uint8 Dem_Cfg_TimeSeriesIndirectionTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_TimeSeriesIndirectionTableType;

/**   \brief  type used in Dem_Cfg_TimeSeriesSamplingProfileCalibTable */
typedef struct sDem_Cfg_TimeSeriesSamplingProfileCalibTableType
{
  uint8 Dem_Cfg_TimeSeriesSamplingProfileCalibTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_TimeSeriesSamplingProfileCalibTableType;

/**   \brief  type used in Dem_Cfg_TimeSeriesSamplingProfileTable */
typedef struct sDem_Cfg_TimeSeriesSamplingProfileTableType
{
  uint8 Dem_Cfg_TimeSeriesSamplingProfileTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_TimeSeriesSamplingProfileTableType;

/**   \brief  type used in Dem_Cfg_UserDefinedOriginTable */
typedef struct sDem_Cfg_UserDefinedOriginTableType
{
  uint8 Dem_Cfg_UserDefinedOriginTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_Cfg_UserDefinedOriginTableType;

/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCRootPointerTypes  Dem_Cfg Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Dem_Cfg_AdminData */
typedef P2VAR(Dem_Cfg_AdminDataType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_AdminDataPtrType;

/**   \brief  type used to point to Dem_Cfg_AgingData */
typedef P2VAR(Dem_Cfg_AgingDataType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_AgingDataPtrType;

/**   \brief  type used to point to Dem_Cfg_CalibrationErrorRegister */
typedef P2VAR(Dem_Cfg_CalibrationErrorRegisterType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_CalibrationErrorRegisterPtrType;

/**   \brief  type used to point to Dem_Cfg_CalibrationObdDtcTable */
typedef P2CONST(Dem_Cfg_CalibrationObdDtcTableType, TYPEDEF, DEM_CONST) Dem_Cfg_CalibrationObdDtcTablePtrType;

/**   \brief  type used to point to Dem_Cfg_CallbackClearEventAllowed */
typedef P2CONST(Dem_ClearEventAllowedFPtrType, TYPEDEF, DEM_CONST) Dem_Cfg_CallbackClearEventAllowedPtrType;

/**   \brief  type used to point to Dem_Cfg_CallbackDtcStatusChanged */
typedef P2CONST(Dem_DtcStatusChangedFPtrType, TYPEDEF, DEM_CONST) Dem_Cfg_CallbackDtcStatusChangedPtrType;

/**   \brief  type used to point to Dem_Cfg_CallbackGetFdc */
typedef P2CONST(Dem_GetFDCFPtrType, TYPEDEF, DEM_CONST) Dem_Cfg_CallbackGetFdcPtrType;

/**   \brief  type used to point to Dem_Cfg_CallbackJ1939DtcStatusChanged */
typedef P2CONST(Dem_DtcStatusChangedFPtrType, TYPEDEF, DEM_CONST) Dem_Cfg_CallbackJ1939DtcStatusChangedPtrType;

/**   \brief  type used to point to Dem_Cfg_ClearDTCTable */
typedef P2VAR(Dem_ClearDTC_DataType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_ClearDTCTablePtrType;

/**   \brief  type used to point to Dem_Cfg_ClearDtcNotificationFinishTable */
typedef P2CONST(Dem_ClearDtcNotificationFPtrType, TYPEDEF, DEM_CONST) Dem_Cfg_ClearDtcNotificationFinishTablePtrType;

/**   \brief  type used to point to Dem_Cfg_ClearDtcNotificationStartTable */
typedef P2CONST(Dem_ClearDtcNotificationFPtrType, TYPEDEF, DEM_CONST) Dem_Cfg_ClearDtcNotificationStartTablePtrType;

/**   \brief  type used to point to Dem_Cfg_ClientTable */
typedef P2CONST(Dem_Cfg_ClientTableType, TYPEDEF, DEM_CONST) Dem_Cfg_ClientTablePtrType;

/**   \brief  type used to point to Dem_Cfg_CommitBuffer */
typedef P2VAR(Dem_Cfg_CommitBufferType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_CommitBufferPtrType;

/**   \brief  type used to point to Dem_Cfg_CommonDidList */
typedef P2CONST(Dem_Cfg_CommonDidListType, TYPEDEF, DEM_CONST) Dem_Cfg_CommonDidListPtrType;

/**   \brief  type used to point to Dem_Cfg_CounterBasedDebounceTable */
typedef P2CONST(Dem_Cfg_CounterBasedDebounceTableType, TYPEDEF, DEM_CONST) Dem_Cfg_CounterBasedDebounceTablePtrType;

/**   \brief  type used to point to Dem_Cfg_CustomTimeSeriesFreezeFrameTable */
typedef P2CONST(Dem_Cfg_CustomTimeSeriesFreezeFrameTableType, TYPEDEF, DEM_CONST) Dem_Cfg_CustomTimeSeriesFreezeFrameTablePtrType;

/**   \brief  type used to point to Dem_Cfg_CustomTriggerEntryIndexToNvBlockIndex */
typedef P2CONST(Dem_Cfg_NvBlockIndexType, TYPEDEF, DEM_CONST) Dem_Cfg_CustomTriggerEntryIndexToNvBlockIndexPtrType;

/**   \brief  type used to point to Dem_Cfg_CustomTriggerEntryPtr */
typedef P2CONST(Dem_Cfg_CustomTriggerEntryPtrType, TYPEDEF, DEM_CONST) Dem_Cfg_CustomTriggerEntryPtrPtrType;

/**   \brief  type used to point to Dem_Cfg_CycleCounterData */
typedef P2VAR(Dem_Cfg_CycleCounterDataType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_CycleCounterDataPtrType;

/**   \brief  type used to point to Dem_Cfg_CycleIdTable */
typedef P2CONST(Dem_Cfg_CycleIdTableType, TYPEDEF, DEM_CONST) Dem_Cfg_CycleIdTablePtrType;

/**   \brief  type used to point to Dem_Cfg_DTCSelectorTable */
typedef P2VAR(Dem_DTCSelector_DataType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_DTCSelectorTablePtrType;

/**   \brief  type used to point to Dem_Cfg_DataCollectionTable */
typedef P2CONST(Dem_Cfg_DataCollectionTableType, TYPEDEF, DEM_CONST) Dem_Cfg_DataCollectionTablePtrType;

/**   \brief  type used to point to Dem_Cfg_DataCollectionTableErec2CollInd */
typedef P2CONST(Dem_Cfg_DataCollectionTableErec2CollIndType, TYPEDEF, DEM_CONST) Dem_Cfg_DataCollectionTableErec2CollIndPtrType;

/**   \brief  type used to point to Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd */
typedef P2CONST(Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollIndType, TYPEDEF, DEM_CONST) Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollIndPtrType;

/**   \brief  type used to point to Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd */
typedef P2CONST(Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollIndType, TYPEDEF, DEM_CONST) Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollIndPtrType;

/**   \brief  type used to point to Dem_Cfg_DataCollectionTablePid2CollInd */
typedef P2CONST(Dem_Cfg_DataCollectionTablePid2CollIndType, TYPEDEF, DEM_CONST) Dem_Cfg_DataCollectionTablePid2CollIndPtrType;

/**   \brief  type used to point to Dem_Cfg_ReadDataFuncOfDataElementTable */
typedef P2CONST(Dem_ReadDataFPtrType, TYPEDEF, DEM_CONST) Dem_Cfg_ReadDataFuncOfDataElementTablePtrType;

/**   \brief  type used to point to Dem_Cfg_DataElementTable */
typedef P2CONST(Dem_Cfg_DataElementTableType, TYPEDEF, DEM_CONST) Dem_Cfg_DataElementTablePtrType;

/**   \brief  type used to point to Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd */
typedef P2CONST(Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtIndType, TYPEDEF, DEM_CONST) Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtIndPtrType;

/**   \brief  type used to point to Dem_Cfg_DebounceData */
typedef P2VAR(Dem_Cfg_DebounceDataType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_DebounceDataPtrType;

/**   \brief  type used to point to Dem_Cfg_DebounceIndirectionTable */
typedef P2CONST(Dem_Cfg_DebounceIndirectionTableType, TYPEDEF, DEM_CONST) Dem_Cfg_DebounceIndirectionTablePtrType;

/**   \brief  type used to point to Dem_Cfg_DtcCalibTable */
typedef P2CONST(Dem_Cfg_DtcCalibTableType, TYPEDEF, DEM_CONST) Dem_Cfg_DtcCalibTablePtrType;

/**   \brief  type used to point to Dem_Cfg_DtcGroupMask */
typedef P2CONST(Dem_Cfg_DtcGroupMaskType, TYPEDEF, DEM_CONST) Dem_Cfg_DtcGroupMaskPtrType;

/**   \brief  type used to point to Dem_Cfg_DtcInvariantDataTable */
typedef P2CONST(Dem_Cfg_DtcInvariantDataTableType, TYPEDEF, DEM_CONST) Dem_Cfg_DtcInvariantDataTablePtrType;

/**   \brief  type used to point to Dem_Cfg_DtcTable */
typedef P2CONST(Dem_Cfg_DtcTableType, TYPEDEF, DEM_CONST) Dem_Cfg_DtcTablePtrType;

/**   \brief  type used to point to Dem_Cfg_DtrData */
typedef P2VAR(Dem_Cfg_DtrDataType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_DtrDataPtrType;

/**   \brief  type used to point to Dem_Cfg_DtrStatus */
typedef P2VAR(volatile Dem_Cfg_DtrStatusType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_DtrStatusPtrType;

/**   \brief  type used to point to Dem_Cfg_DtrTable */
typedef P2CONST(Dem_Cfg_DtrTableType, TYPEDEF, DEM_CONST) Dem_Cfg_DtrTablePtrType;

/**   \brief  type used to point to Dem_Cfg_DtrTableInd */
typedef P2CONST(Dem_Cfg_DtrTableIndType, TYPEDEF, DEM_CONST) Dem_Cfg_DtrTableIndPtrType;

/**   \brief  type used to point to Dem_Cfg_EnableConditionFulfilled */
typedef P2VAR(Dem_Cfg_EnableConditionFulfilledType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_EnableConditionFulfilledPtrType;

/**   \brief  type used to point to Dem_Cfg_EnableConditionGroupCounter */
typedef P2VAR(Dem_Cfg_EnableConditionGroupCounterType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_EnableConditionGroupCounterPtrType;

/**   \brief  type used to point to Dem_Cfg_EnableConditionGroupState */
typedef P2VAR(volatile Dem_Cfg_EnableConditionGroupStateType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_EnableConditionGroupStatePtrType;

/**   \brief  type used to point to Dem_Cfg_EnableConditionGroupTable */
typedef P2CONST(Dem_Cfg_EnableConditionGroupTableType, TYPEDEF, DEM_CONST) Dem_Cfg_EnableConditionGroupTablePtrType;

/**   \brief  type used to point to Dem_Cfg_EnableConditionGroupTableInd */
typedef P2CONST(Dem_Cfg_EnableConditionGroupTableIndType, TYPEDEF, DEM_CONST) Dem_Cfg_EnableConditionGroupTableIndPtrType;

/**   \brief  type used to point to Dem_Cfg_EnableConditionInitTable */
typedef P2CONST(Dem_Cfg_EnableConditionInitTableType, TYPEDEF, DEM_CONST) Dem_Cfg_EnableConditionInitTablePtrType;

/**   \brief  type used to point to Dem_Cfg_EnableConditionTable */
typedef P2CONST(Dem_Cfg_EnableConditionTableType, TYPEDEF, DEM_CONST) Dem_Cfg_EnableConditionTablePtrType;

/**   \brief  type used to point to Dem_Cfg_EventAvailableData */
typedef P2VAR(Dem_Cfg_EventAvailableDataType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_EventAvailableDataPtrType;

/**   \brief  type used to point to Dem_Cfg_EventAvailableDefault */
typedef P2CONST(Dem_Cfg_EventAvailableDefaultType, TYPEDEF, DEM_CONST) Dem_Cfg_EventAvailableDefaultPtrType;

/**   \brief  type used to point to Dem_Cfg_EventAvailableInVariant */
typedef P2CONST(Dem_Cfg_EventAvailableInVariantType, TYPEDEF, DEM_CONST) Dem_Cfg_EventAvailableInVariantPtrType;

/**   \brief  type used to point to Dem_Cfg_EventCalibTable */
typedef P2CONST(Dem_Cfg_EventCalibTableType, TYPEDEF, DEM_CONST) Dem_Cfg_EventCalibTablePtrType;

/**   \brief  type used to point to Dem_Cfg_EventCycleStatus */
typedef P2VAR(volatile Dem_Cfg_EventCycleStatusType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_EventCycleStatusPtrType;

/**   \brief  type used to point to Dem_Cfg_EventDataChanged */
typedef P2CONST(Dem_EventDataChangedFPtrType, TYPEDEF, DEM_CONST) Dem_Cfg_EventDataChangedPtrType;

/**   \brief  type used to point to Dem_Cfg_EventDataCommitNumber */
typedef P2VAR(volatile Dem_Cfg_EventDataCommitNumberType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_EventDataCommitNumberPtrType;

/**   \brief  type used to point to Dem_Cfg_EventEntryIndexToNvBlockIndex */
typedef P2CONST(Dem_Cfg_NvBlockIndexType, TYPEDEF, DEM_CONST) Dem_Cfg_EventEntryIndexToNvBlockIndexPtrType;

/**   \brief  type used to point to Dem_Cfg_EventEntryInfoTable */
typedef P2CONST(Dem_Cfg_EventEntryInfoTableType, TYPEDEF, DEM_CONST) Dem_Cfg_EventEntryInfoTablePtrType;

/**   \brief  type used to point to Dem_Cfg_EventIndicatorData */
typedef P2CONST(Dem_Cfg_EventIndicatorDataType, TYPEDEF, DEM_CONST) Dem_Cfg_EventIndicatorDataPtrType;

/**   \brief  type used to point to Dem_Cfg_EventInternalStatus */
typedef P2VAR(volatile Dem_Event_InternalStatusType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_EventInternalStatusPtrType;

/**   \brief  type used to point to Dem_Cfg_EventInvariantDataTable */
typedef P2CONST(Dem_Cfg_EventInvariantDataTableType, TYPEDEF, DEM_CONST) Dem_Cfg_EventInvariantDataTablePtrType;

/**   \brief  type used to point to Dem_Cfg_EventPrecompileDataTable */
typedef P2CONST(Dem_Cfg_EventPrecompileDataTableType, TYPEDEF, DEM_CONST) Dem_Cfg_EventPrecompileDataTablePtrType;

/**   \brief  type used to point to Dem_Cfg_EventPrecompileDataTableInd */
typedef P2CONST(Dem_Cfg_EventPrecompileDataTableIndType, TYPEDEF, DEM_CONST) Dem_Cfg_EventPrecompileDataTableIndPtrType;

/**   \brief  type used to point to Dem_Cfg_EventStatusChanged */
typedef P2CONST(Dem_EventStatusChangedFPtrType, TYPEDEF, DEM_CONST) Dem_Cfg_EventStatusChangedPtrType;

/**   \brief  type used to point to Dem_Cfg_EventTable */
typedef P2CONST(Dem_Cfg_EventTableType, TYPEDEF, DEM_CONST) Dem_Cfg_EventTablePtrType;

/**   \brief  type used to point to Dem_Cfg_EventTable_ERec2EventIdInd */
typedef P2CONST(Dem_Cfg_EventTable_ERec2EventIdIndType, TYPEDEF, DEM_CONST) Dem_Cfg_EventTable_ERec2EventIdIndPtrType;

/**   \brief  type used to point to Dem_Cfg_ExtendedDataRecordIteratorTable */
typedef P2VAR(Dem_Cfg_ExtendedDataRecordIterator_FilterType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_ExtendedDataRecordIteratorTablePtrType;

/**   \brief  type used to point to Dem_Cfg_ExtendedDataRecordTable */
typedef P2CONST(Dem_Cfg_ExtendedDataRecordTableType, TYPEDEF, DEM_CONST) Dem_Cfg_ExtendedDataRecordTablePtrType;

/**   \brief  type used to point to Dem_Cfg_ExtendedDataTable */
typedef P2CONST(Dem_Cfg_ExtendedDataTableType, TYPEDEF, DEM_CONST) Dem_Cfg_ExtendedDataTablePtrType;

/**   \brief  type used to point to Dem_Cfg_FilterInfoTable */
typedef P2VAR(Dem_Cfg_FilterData_InfoType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_FilterInfoTablePtrType;

/**   \brief  type used to point to Dem_Cfg_FreezeFrameData */
typedef P2VAR(Dem_Cfg_FreezeFrameDataType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_FreezeFrameDataPtrType;

/**   \brief  type used to point to Dem_Cfg_FreezeFrameIteratorTable */
typedef P2VAR(Dem_Cfg_FreezeFrameIterator_FilterType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_FreezeFrameIteratorTablePtrType;

/**   \brief  type used to point to Dem_Cfg_FreezeFrameNumIndirectionTable */
typedef P2CONST(Dem_Cfg_FreezeFrameNumIndirectionTableType, TYPEDEF, DEM_CONST) Dem_Cfg_FreezeFrameNumIndirectionTablePtrType;

/**   \brief  type used to point to Dem_Cfg_FreezeFrameNumTable */
typedef P2CONST(Dem_Cfg_FreezeFrameNumTableType, TYPEDEF, DEM_CONST) Dem_Cfg_FreezeFrameNumTablePtrType;

/**   \brief  type used to point to Dem_Cfg_FreezeFrameTable */
typedef P2CONST(Dem_Cfg_FreezeFrameTableType, TYPEDEF, DEM_CONST) Dem_Cfg_FreezeFrameTablePtrType;

/**   \brief  type used to point to Dem_Cfg_GeneralJ1939Table */
typedef P2CONST(Dem_Cfg_GeneralJ1939TableType, TYPEDEF, DEM_CONST) Dem_Cfg_GeneralJ1939TablePtrType;

/**   \brief  type used to point to Dem_Cfg_GeneralObdInput */
typedef P2CONST(Dem_Cfg_GeneralObdInputType, TYPEDEF, DEM_CONST) Dem_Cfg_GeneralObdInputPtrType;

/**   \brief  type used to point to Dem_Cfg_GlobalSnapshotRecord */
typedef P2CONST(Dem_Cfg_GlobalSnapshotRecordType, TYPEDEF, DEM_CONST) Dem_Cfg_GlobalSnapshotRecordPtrType;

/**   \brief  type used to point to Dem_Cfg_IndicatorAttributeTable */
typedef P2CONST(Dem_Cfg_IndicatorAttributeTableType, TYPEDEF, DEM_CONST) Dem_Cfg_IndicatorAttributeTablePtrType;

/**   \brief  type used to point to Dem_Cfg_IndicatorData */
typedef P2VAR(Dem_Cfg_IndicatorType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_IndicatorDataPtrType;

/**   \brief  type used to point to Dem_Cfg_IndicatorEventCounters */
typedef P2VAR(Dem_Cfg_IndicatorEventCountersType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_IndicatorEventCountersPtrType;

/**   \brief  type used to point to Dem_Cfg_InitMonListForFunc */
typedef P2CONST(Dem_Cfg_InitMonListForFuncType, TYPEDEF, DEM_CONST) Dem_Cfg_InitMonListForFuncPtrType;

/**   \brief  type used to point to Dem_Cfg_InitMonitorForEvent */
typedef P2CONST(Dem_InitMonitorForEventFPtrType, TYPEDEF, DEM_CONST) Dem_Cfg_InitMonitorForEventPtrType;

/**   \brief  type used to point to Dem_Cfg_InitMonitorsForFunc */
typedef P2CONST(Dem_InitMonitorForFuncFPtrType, TYPEDEF, DEM_CONST) Dem_Cfg_InitMonitorsForFuncPtrType;

/**   \brief  type used to point to Dem_Cfg_J1939EventIdsWithRatioTable */
typedef P2CONST(Dem_Cfg_J1939EventIdsWithRatioTableType, TYPEDEF, DEM_CONST) Dem_Cfg_J1939EventIdsWithRatioTablePtrType;

/**   \brief  type used to point to Dem_Cfg_J1939NodeId */
typedef P2CONST(Dem_Cfg_J1939NodeIdType, TYPEDEF, DEM_CONST) Dem_Cfg_J1939NodeIdPtrType;

/**   \brief  type used to point to Dem_Cfg_J1939NodeIdInd */
typedef P2CONST(Dem_Cfg_J1939NodeIdIndType, TYPEDEF, DEM_CONST) Dem_Cfg_J1939NodeIdIndPtrType;

/**   \brief  type used to point to Dem_Cfg_J1939NodeIndicatorAvailability */
typedef P2CONST(Dem_Cfg_J1939NodeIndicatorAvailabilityType, TYPEDEF, DEM_CONST) Dem_Cfg_J1939NodeIndicatorAvailabilityPtrType;

/**   \brief  type used to point to Dem_Cfg_J1939SpnsInExpandedFreezeFrameTable */
typedef P2CONST(Dem_Cfg_J1939SpnsInExpandedFreezeFrameTableType, TYPEDEF, DEM_CONST) Dem_Cfg_J1939SpnsInExpandedFreezeFrameTablePtrType;

/**   \brief  type used to point to Dem_Cfg_MemoryCurrentCount */
typedef P2VAR(Dem_Cfg_MemoryCurrentCountType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_MemoryCurrentCountPtrType;

/**   \brief  type used to point to Dem_Cfg_MemoryInfoTable */
typedef P2CONST(Dem_Cfg_MemoryInfoTableType, TYPEDEF, DEM_CONST) Dem_Cfg_MemoryInfoTablePtrType;

/**   \brief  type used to point to Dem_Cfg_MemoryStatus */
typedef P2VAR(Dem_Cfg_MemoryStatusType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_MemoryStatusPtrType;

/**   \brief  type used to point to Dem_Cfg_MidTable */
typedef P2CONST(Dem_Cfg_MidTableType, TYPEDEF, DEM_CONST) Dem_Cfg_MidTablePtrType;

/**   \brief  type used to point to Dem_Cfg_MirrorData */
typedef P2VAR(Dem_Cfg_MirrorDataType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_MirrorDataPtrType;

/**   \brief  type used to point to Dem_Cfg_MonitorActivityRatioTable */
typedef P2CONST(Dem_Cfg_MonitorActivityRatioTableType, TYPEDEF, DEM_CONST) Dem_Cfg_MonitorActivityRatioTablePtrType;

/**   \brief  type used to point to Dem_Cfg_MultiEventTriggeringSlaveEventsTable */
typedef P2CONST(Dem_Cfg_MultiEventTriggeringSlaveEventsTableType, TYPEDEF, DEM_CONST) Dem_Cfg_MultiEventTriggeringSlaveEventsTablePtrType;

/**   \brief  type used to point to Dem_Cfg_NvBlockDataPtr */
typedef P2CONST(Dem_NvDataPtrType, TYPEDEF, DEM_CONST) Dem_Cfg_NvBlockDataPtrPtrType;

/**   \brief  type used to point to Dem_Cfg_NvBlockDataSize */
typedef P2CONST(Dem_Cfg_NvBlockDataSizeType, TYPEDEF, DEM_CONST) Dem_Cfg_NvBlockDataSizePtrType;

/**   \brief  type used to point to Dem_Cfg_NvBlockId */
typedef P2CONST(Dem_Cfg_NvBlockIdType, TYPEDEF, DEM_CONST) Dem_Cfg_NvBlockIdPtrType;

/**   \brief  type used to point to Dem_Cfg_ObdCalibTable */
typedef P2CONST(Dem_Cfg_ObdCalibTableType, TYPEDEF, DEM_CONST) Dem_Cfg_ObdCalibTablePtrType;

/**   \brief  type used to point to Dem_Cfg_ObdIumprData */
typedef P2VAR(Dem_Cfg_ObdIumprDataType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_ObdIumprDataPtrType;

/**   \brief  type used to point to Dem_Cfg_ObdIumprUpdatePending */
typedef P2VAR(Dem_Cfg_ObdIumprUpdatePendingType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_ObdIumprUpdatePendingPtrType;

/**   \brief  type used to point to Dem_Cfg_PermanentData */
typedef P2VAR(Dem_Cfg_PermanentDataType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_PermanentDataPtrType;

/**   \brief  type used to point to Dem_Cfg_PidTable */
typedef P2CONST(Dem_Cfg_PidTableType, TYPEDEF, DEM_CONST) Dem_Cfg_PidTablePtrType;

/**   \brief  type used to point to Dem_Cfg_Prestorage */
typedef P2VAR(Dem_Cfg_PrestorageType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_PrestoragePtrType;

/**   \brief  type used to point to Dem_Cfg_PrestorageIndex */
typedef P2VAR(Dem_Cfg_PrestorageIndexType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_PrestorageIndexPtrType;

/**   \brief  type used to point to Dem_Cfg_PrimaryChronology */
typedef P2VAR(Dem_Cfg_EntryIndexType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_PrimaryChronologyPtrType;

/**   \brief  type used to point to Dem_Cfg_PrimaryEntry_0 */
typedef P2VAR(Dem_Cfg_PrimaryEntryType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_0PtrType;

/**   \brief  type used to point to Dem_Cfg_PrimaryEntry_1 */
typedef P2VAR(Dem_Cfg_PrimaryEntryType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_1PtrType;

/**   \brief  type used to point to Dem_Cfg_PrimaryEntry_2 */
typedef P2VAR(Dem_Cfg_PrimaryEntryType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_2PtrType;

/**   \brief  type used to point to Dem_Cfg_PrimaryEntry_3 */
typedef P2VAR(Dem_Cfg_PrimaryEntryType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_3PtrType;

/**   \brief  type used to point to Dem_Cfg_PrimaryEntry_4 */
typedef P2VAR(Dem_Cfg_PrimaryEntryType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_4PtrType;

/**   \brief  type used to point to Dem_Cfg_PrimaryEntry_5 */
typedef P2VAR(Dem_Cfg_PrimaryEntryType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_5PtrType;

/**   \brief  type used to point to Dem_Cfg_PrimaryEntry_6 */
typedef P2VAR(Dem_Cfg_PrimaryEntryType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_6PtrType;

/**   \brief  type used to point to Dem_Cfg_PrimaryEntry_7 */
typedef P2VAR(Dem_Cfg_PrimaryEntryType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_7PtrType;

/**   \brief  type used to point to Dem_Cfg_PrimaryEntry_8 */
typedef P2VAR(Dem_Cfg_PrimaryEntryType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_8PtrType;

/**   \brief  type used to point to Dem_Cfg_PrimaryEntry_9 */
typedef P2VAR(Dem_Cfg_PrimaryEntryType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_9PtrType;

/**   \brief  type used to point to Dem_Cfg_PrimaryEventEntryInit */
typedef P2CONST(Dem_Cfg_PrimaryEntryType, TYPEDEF, DEM_CONST) Dem_Cfg_PrimaryEventEntryInitPtrType;

/**   \brief  type used to point to Dem_Cfg_RatioIdTable */
typedef P2CONST(Dem_Cfg_RatioIdTableType, TYPEDEF, DEM_CONST) Dem_Cfg_RatioIdTablePtrType;

/**   \brief  type used to point to Dem_Cfg_ReadoutBuffer */
typedef P2VAR(Dem_Cfg_ReadoutBufferEntryType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_ReadoutBufferPtrType;

/**   \brief  type used to point to Dem_Cfg_ReportedEventsOfFilter */
typedef P2VAR(Dem_Cfg_ReportedEventsType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_ReportedEventsOfFilterPtrType;

/**   \brief  type used to point to Dem_Cfg_RingBuffer */
typedef P2VAR(Dem_Cfg_RingBufferType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_RingBufferPtrType;

/**   \brief  type used to point to Dem_Cfg_SamplingProfileDidInfoTable */
typedef P2CONST(Dem_Cfg_SamplingProfileDidInfoTableType, TYPEDEF, DEM_CONST) Dem_Cfg_SamplingProfileDidInfoTablePtrType;

/**   \brief  type used to point to Dem_Cfg_SatelliteInfo */
typedef P2CONST(Dem_Cfg_SatelliteInfoType, TYPEDEF, DEM_CONST) Dem_Cfg_SatelliteInfoPtrType;

/**   \brief  type used to point to Dem_Cfg_SatelliteInfoInvalid_OsApplication */
typedef P2VAR(Dem_Cfg_SatelliteInfoTypeInvalid_OsApplication, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_SatelliteInfoInvalid_OsApplicationPtrType;

/**   \brief  type used to point to Dem_Cfg_SatelliteTimeDebounceInfo */
typedef P2CONST(Dem_Cfg_SatelliteTimeDebounceInfoType, TYPEDEF, DEM_CONST) Dem_Cfg_SatelliteTimeDebounceInfoPtrType;

/**   \brief  type used to point to Dem_Cfg_SpnToEventsWithRatioTable */
typedef P2CONST(Dem_Cfg_SpnToEventsWithRatioTableType, TYPEDEF, DEM_CONST) Dem_Cfg_SpnToEventsWithRatioTablePtrType;

/**   \brief  type used to point to Dem_Cfg_StartIdx500miDenRatioTable */
typedef P2CONST(Dem_Cfg_StartIdx500miDenRatioTableType, TYPEDEF, DEM_CONST) Dem_Cfg_StartIdx500miDenRatioTablePtrType;

/**   \brief  type used to point to Dem_Cfg_StatusData */
typedef P2VAR(Dem_Cfg_StatusDataType, TYPEDEF, DEM_NVM_DATA_CLEARED) Dem_Cfg_StatusDataPtrType;

/**   \brief  type used to point to Dem_Cfg_StorageConditionFulfilled */
typedef P2VAR(Dem_Cfg_StorageConditionFulfilledType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_StorageConditionFulfilledPtrType;

/**   \brief  type used to point to Dem_Cfg_StorageConditionGroupCounter */
typedef P2VAR(Dem_Cfg_StorageConditionGroupCounterType, TYPEDEF, DEM_VAR_CLEARED) Dem_Cfg_StorageConditionGroupCounterPtrType;

/**   \brief  type used to point to Dem_Cfg_StorageConditionGroupTable */
typedef P2CONST(Dem_Cfg_StorageConditionGroupTableType, TYPEDEF, DEM_CONST) Dem_Cfg_StorageConditionGroupTablePtrType;

/**   \brief  type used to point to Dem_Cfg_StorageConditionGroupTableInd */
typedef P2CONST(Dem_Cfg_StorageConditionGroupTableIndType, TYPEDEF, DEM_CONST) Dem_Cfg_StorageConditionGroupTableIndPtrType;

/**   \brief  type used to point to Dem_Cfg_StorageConditionInitTable */
typedef P2CONST(Dem_Cfg_StorageConditionInitTableType, TYPEDEF, DEM_CONST) Dem_Cfg_StorageConditionInitTablePtrType;

/**   \brief  type used to point to Dem_Cfg_StorageConditionTable */
typedef P2CONST(Dem_Cfg_StorageConditionTableType, TYPEDEF, DEM_CONST) Dem_Cfg_StorageConditionTablePtrType;

/**   \brief  type used to point to Dem_Cfg_SupportedMidsTable */
typedef P2CONST(Dem_Cfg_SupportedMidsTableType, TYPEDEF, DEM_CONST) Dem_Cfg_SupportedMidsTablePtrType;

/**   \brief  type used to point to Dem_Cfg_TimeBasedDebounceTable */
typedef P2CONST(Dem_Cfg_TimeBasedDebounceTableType, TYPEDEF, DEM_CONST) Dem_Cfg_TimeBasedDebounceTablePtrType;

/**   \brief  type used to point to Dem_Cfg_TimeBasedEventTable */
typedef P2CONST(Dem_Cfg_TimeBasedEventTableType, TYPEDEF, DEM_CONST) Dem_Cfg_TimeBasedEventTablePtrType;

/**   \brief  type used to point to Dem_Cfg_TimeSeriesEntryIndexToNvBlockIndex */
typedef P2CONST(Dem_Cfg_NvBlockIndexType, TYPEDEF, DEM_CONST) Dem_Cfg_TimeSeriesEntryIndexToNvBlockIndexPtrType;

/**   \brief  type used to point to Dem_Cfg_TimeSeriesEntryTable */
typedef P2CONST(Dem_Cfg_TimeSeriesEntryTableType, TYPEDEF, DEM_CONST) Dem_Cfg_TimeSeriesEntryTablePtrType;

/**   \brief  type used to point to Dem_Cfg_TimeSeriesFreezeFrameTable */
typedef P2CONST(Dem_Cfg_TimeSeriesFreezeFrameTableType, TYPEDEF, DEM_CONST) Dem_Cfg_TimeSeriesFreezeFrameTablePtrType;

/**   \brief  type used to point to Dem_Cfg_TimeSeriesIndirectionTable */
typedef P2CONST(Dem_Cfg_TimeSeriesIndirectionTableType, TYPEDEF, DEM_CONST) Dem_Cfg_TimeSeriesIndirectionTablePtrType;

/**   \brief  type used to point to Dem_Cfg_TimeSeriesSamplingProfileCalibTable */
typedef P2CONST(Dem_Cfg_TimeSeriesSamplingProfileCalibTableType, TYPEDEF, DEM_CONST) Dem_Cfg_TimeSeriesSamplingProfileCalibTablePtrType;

/**   \brief  type used to point to Dem_Cfg_TimeSeriesSamplingProfileTable */
typedef P2CONST(Dem_Cfg_TimeSeriesSamplingProfileTableType, TYPEDEF, DEM_CONST) Dem_Cfg_TimeSeriesSamplingProfileTablePtrType;

/**   \brief  type used to point to Dem_Cfg_UserDefinedOriginTable */
typedef P2CONST(Dem_Cfg_UserDefinedOriginTableType, TYPEDEF, DEM_CONST) Dem_Cfg_UserDefinedOriginTablePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPCRootValueTypes  Dem_Cfg Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Dem_PCConfig */
typedef struct sDem_PCConfigType
{
  Dem_Cfg_EventAvailableInVariantPtrType EventAvailableInVariantOfPCConfig;  /**< the pointer to Dem_Cfg_EventAvailableInVariant */
  Dem_Cfg_ConfigurationIdType ConfigurationIdOfPCConfig;  /**< Magic constant derived from the configuration parameters /Dem/DemGeneral/DemCompiledConfigId and /Dem/DemGeneral/DemCompiledPostbuildCrc. Each value change is evidence to incompatible NV stored data and triggers a re-initialization of the NV data. */
} Dem_PCConfigType;

typedef Dem_PCConfigType Dem_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access Dem_PCConfig in a symbol based style. */
typedef struct sDem_PCConfigsType
{
  Dem_PCConfigType Config_RDR_01;  /**< [Config_RDR_01] */
  Dem_PCConfigType Config_RDR_02;  /**< [Config_RDR_02] */
  Dem_PCConfigType Config_RDR_03;  /**< [Config_RDR_03] */
  Dem_PCConfigType Config_RDR_04;  /**< [Config_RDR_04] */
  Dem_PCConfigType Config_RDR_05;  /**< [Config_RDR_05] */
  Dem_PCConfigType Config_RDR_06;  /**< [Config_RDR_06] */
  Dem_PCConfigType Config_RDR_07;  /**< [Config_RDR_07] */
  Dem_PCConfigType Config_RDR_08;  /**< [Config_RDR_08] */
} Dem_PCConfigsType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Dem_Cfg_CallbackDtcStatusChanged
**********************************************************************************************************************/
#define DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Dem_DtcStatusChangedFPtrType, DEM_CONST) Dem_Cfg_CallbackDtcStatusChanged[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(Dem_Cfg_DataCollectionTableType, DEM_CONST) Dem_Cfg_DataCollectionTable[8];
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
extern CONST(Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollIndType, DEM_CONST) Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableEdr2CollInd[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollIndType, DEM_CONST) Dem_Cfg_DataCollectionTableIdxOfDataCollectionTableFfm2CollInd[5];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(Dem_Cfg_DataElementTableType, DEM_CONST) Dem_Cfg_DataElementTable[8];
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
extern CONST(Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtIndType, DEM_CONST) Dem_Cfg_DataElementTableIdxOfDataElementTableCol2ElmtInd[7];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(Dem_Cfg_DebounceIndirectionTableType, DEM_CONST) Dem_Cfg_DebounceIndirectionTable[63];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(Dem_Cfg_DtcCalibTableType, DEM_CONST) Dem_Cfg_DtcCalibTable[63];
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
extern CONST(Dem_Cfg_DtcInvariantDataTableType, DEM_CONST) Dem_Cfg_DtcInvariantDataTable[63];
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
extern CONST(Dem_Cfg_DtcTableType, DEM_CONST) Dem_Cfg_DtcTable[63];
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
extern CONST(Dem_Cfg_EventAvailableInVariantType, DEM_CONST) Dem_Cfg_EventAvailableInVariantRDR_01[63];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(Dem_Cfg_EventAvailableInVariantType, DEM_CONST) Dem_Cfg_EventAvailableInVariantRDR_02[63];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(Dem_Cfg_EventAvailableInVariantType, DEM_CONST) Dem_Cfg_EventAvailableInVariantRDR_04[63];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(Dem_Cfg_NvBlockIndexType, DEM_CONST) Dem_Cfg_EventEntryIndexToNvBlockIndex[11];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(Dem_Cfg_EventEntryInfoTableType, DEM_CONST) Dem_Cfg_EventEntryInfoTable[11];
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
extern CONST(Dem_Cfg_EventInvariantDataTableType, DEM_CONST) Dem_Cfg_EventInvariantDataTable[63];
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
extern CONST(Dem_Cfg_EventPrecompileDataTableType, DEM_CONST) Dem_Cfg_EventPrecompileDataTable[63];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(Dem_EventStatusChangedFPtrType, DEM_CONST) Dem_Cfg_EventStatusChanged[2];
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
extern CONST(Dem_Cfg_ExtendedDataTableType, DEM_CONST) Dem_Cfg_ExtendedDataTable[2];
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
extern CONST(Dem_Cfg_FreezeFrameNumIndirectionTableType, DEM_CONST) Dem_Cfg_FreezeFrameNumIndirectionTable[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(Dem_Cfg_FreezeFrameTableType, DEM_CONST) Dem_Cfg_FreezeFrameTable[2];
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
extern CONST(Dem_Cfg_J1939NodeIdType, DEM_CONST) Dem_Cfg_J1939NodeId[2];
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
extern CONST(Dem_Cfg_J1939NodeIdIndType, DEM_CONST) Dem_Cfg_J1939NodeIdInd[62];
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
extern CONST(Dem_NvDataPtrType, DEM_CONST) Dem_Cfg_NvBlockDataPtr[12];
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
extern CONST(Dem_Cfg_NvBlockDataSizeType, DEM_CONST) Dem_Cfg_NvBlockDataSize[12];
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
extern CONST(Dem_Cfg_NvBlockIdType, DEM_CONST) Dem_Cfg_NvBlockId[12];
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
extern CONST(Dem_Cfg_PrimaryEntryType, DEM_CONST) Dem_Cfg_PrimaryEventEntryInit;
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
extern VAR(Dem_Cfg_AdminDataType, DEM_NVM_DATA_CLEARED) Dem_Cfg_AdminData;
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
extern VAR(Dem_Cfg_CalibrationErrorRegisterType, DEM_VAR_CLEARED) Dem_Cfg_CalibrationErrorRegister;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern VAR(Dem_ClearDTC_DataType, DEM_VAR_CLEARED) Dem_Cfg_ClearDTCTable[1];
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
extern VAR(Dem_Cfg_CommitBufferType, DEM_VAR_CLEARED) Dem_Cfg_CommitBuffer;  /* PRQA S 0759, 0759, 0759, 0759, 0759, 0759, 0759, 0759 */  /* MD_MSR_Union */
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
extern VAR(Dem_DTCSelector_DataType, DEM_VAR_CLEARED) Dem_Cfg_DTCSelectorTable[1];
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
extern VAR(Dem_Cfg_EnableConditionFulfilledType, DEM_VAR_CLEARED) Dem_Cfg_EnableConditionFulfilled[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern VAR(Dem_Cfg_EnableConditionGroupCounterType, DEM_VAR_CLEARED) Dem_Cfg_EnableConditionGroupCounter[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern volatile VAR(Dem_Cfg_EnableConditionGroupStateType, DEM_VAR_CLEARED) Dem_Cfg_EnableConditionGroupState[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern volatile VAR(Dem_Cfg_EventDataCommitNumberType, DEM_VAR_CLEARED) Dem_Cfg_EventDataCommitNumber[63];
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
extern volatile VAR(Dem_Event_InternalStatusType, DEM_VAR_CLEARED) Dem_Cfg_EventInternalStatus[63];
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
extern VAR(Dem_Cfg_ExtendedDataRecordIterator_FilterType, DEM_VAR_CLEARED) Dem_Cfg_ExtendedDataRecordIteratorTable[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern VAR(Dem_Cfg_FilterData_InfoType, DEM_VAR_CLEARED) Dem_Cfg_FilterInfoTable[1];
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
extern VAR(Dem_Cfg_FreezeFrameIterator_FilterType, DEM_VAR_CLEARED) Dem_Cfg_FreezeFrameIteratorTable[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern VAR(Dem_Cfg_MemoryCurrentCountType, DEM_VAR_CLEARED) Dem_Cfg_MemoryCurrentCount[1];
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
extern VAR(Dem_Cfg_MemoryStatusType, DEM_VAR_CLEARED) Dem_Cfg_MemoryStatus[12];
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
extern VAR(Dem_Cfg_EntryIndexType, DEM_VAR_CLEARED) Dem_Cfg_PrimaryChronology[10];
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
extern VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_0;
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
extern VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_1;
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
extern VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_2;
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
extern VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_3;
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
extern VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_4;
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
extern VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_5;
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
extern VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_6;
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
extern VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_7;
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
extern VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_8;
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
extern VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_CLEARED) Dem_Cfg_PrimaryEntry_9;
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
extern VAR(Dem_Cfg_ReadoutBufferEntryType, DEM_VAR_CLEARED) Dem_Cfg_ReadoutBuffer[1];
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
extern VAR(Dem_Cfg_ReportedEventsType, DEM_VAR_CLEARED) Dem_Cfg_ReportedEventsOfFilter[1];
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
extern VAR(Dem_Cfg_SatelliteInfoTypeInvalid_OsApplication, DEM_VAR_CLEARED) Dem_Cfg_SatelliteInfoInvalid_OsApplication;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern VAR(Dem_Cfg_StatusDataType, DEM_NVM_DATA_CLEARED) Dem_Cfg_StatusData;
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
extern CONST(Dem_PCConfigsType, DEM_CONST) Dem_PCConfig;
#define DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Dem_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  Justification of MISRA deviations
**********************************************************************************************************************/


/* User Specific Content Post Start */

/* User Specific Content Post End */

#endif  /* DEM_LCFG_H */
/**********************************************************************************************************************
  END OF FILE: Dem_Lcfg.h     [Vector, VARIANT-POSTBUILD-SELECTABLE, 29.03.00.234032]
**********************************************************************************************************************/

