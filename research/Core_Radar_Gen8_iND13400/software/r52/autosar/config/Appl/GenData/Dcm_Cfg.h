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
 *            Module: Dcm
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dcm_Cfg.h
 *   Generation Time: 2026-08-13 10:24:58
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


#if !defined(DCM_CFG_H)
# define DCM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/*! Implementation version */
# define DCM_CFG_MAJOR_VERSION                                                 23u
# define DCM_CFG_MINOR_VERSION                                                  9u
# define DCM_CFG_PATCH_VERSION                                                  0u

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! Access to version information */
# define DCM_VERSION_INFO_API                                                  STD_OFF
/*! Development error detection and reporting */
# define DCM_DEV_ERROR_REPORT                                                  STD_ON
/*! Highest possible safety module usage */
# define DCM_DEV_ERROR_DETECT                                                  STD_ON
/*! Specifies whether DCM will be put into SafeBSW mode (restricted features). */
# define DCM_DEV_RUNTIME_CHECKS                                                STD_ON
/*! Support reporting of security events to IdsM */
# define DCM_DEBUG_SECURITY_EVENT_REPORT_ENABLED                               STD_OFF
/*! Support reporting of security events with context data to IdsM */
# define DCM_DEBUG_SECURITY_EVENT_WITH_CONTEXT_DATA_ENABLED                    STD_OFF
/*! Optimization for single client configurations */
# define DCM_NET_MULTI_CLIENT_ENABLED                                          STD_OFF
/*! Support communication control on all ECU channels */
# define DCM_NET_COMCTRL_ALLNET_SUPPORT_ENABLED                                STD_OFF
/*! Periodic transmission unit */
# define DCM_NET_PERIODIC_TX_ENABLED                                           STD_OFF
/*! Periodic transmission unused byte padding */
# define DCM_NET_PERIODIC_MSG_PADDING_ENABLED                                  STD_OFF
/*! Periodic transmission UUDT delay timer */
# define DCM_NET_UUDT_DELAYTIMER_ENABLED                                       STD_OFF
/*! Support monitoring of requests to other ECUs */
# define DCM_NET_MONITOR_FOREIGN_N_TA_ENABLED                                  STD_OFF
/*! Support generic connections */
# define DCM_NET_GENERIC_CONNECTION_ENABLED                                    STD_OFF
/*! Source Address is the first two bytes of the meta datas */
# define DCM_NET_METADATA_SOURCE_ADDRESS_FIRST                                 STD_ON
/*! Protect against clients other than the one started the non-default session */
# define DCM_NET_PROTECT_SESSION_OF_CLIENT_ENABLED                             STD_ON
/*! Support protocol change notifications */
# define DCM_NET_PROTOCOL_NOTIFICATION_ENABLED                                 STD_OFF
/*! Paged buffer support for DEM interfaces */
# define DCM_DEMIF_PAGED_BUFFER_ENABLED                                        STD_ON
/*! Paged buffer support */
# define DCM_PAGED_BUFFER_ENABLED                                              STD_ON
/*! Any diagnostic object needs rule check */
# define DCM_MODEMGR_CHECK_SUPPORT_ENABLED                                     STD_OFF
/*! ECU rapid shutdown mode management support */
# define DCM_MODE_RPD_SHTDWN_ENABLED                                           STD_OFF
/*! ECU reset mode management support */
# define DCM_MODE_ECU_RESET_ENABLED                                            STD_ON
/*! Control DTC setting mode management support */
# define DCM_MODE_CTRLDTCSETTING_ENABLED                                       STD_ON
/*! Control DTC setting mode management monitoring support */
# define DCM_MODE_CTRLDTCSETTING_MONITOR_ENABLED                               STD_OFF
/*! Communication control mode management support */
# define DCM_MODE_COMMCTRL_ENABLED                                             STD_ON
/*! Communication control mode management monitoring support */
# define DCM_MODE_COMMCTRL_MONITOR_ENABLED                                     STD_OFF
/*! Security access mode management support */
# define DCM_MODE_SECURITY_ACCESS_ENABLED                                      STD_OFF
/*! Response on event mode management support */
# define DCM_MODE_ROE_ENABLED                                                  STD_OFF
/*! Authentication general NRC mode management support */
# define DCM_MODE_AUTH_GENERAL_NRC_ENABLED                                     STD_OFF
/*! Support security access state management */
# define DCM_STATE_SECURITY_ENABLED                                            STD_ON
/*! Support security access delay on boot */
# define DCM_STATE_SEC_DELAY_ON_BOOT_ENABLED                                   STD_OFF
/*! Support SecurityGet-/SetAttemptCounter APIs */
# define DCM_STATE_SEC_ATT_CNTR_EXT_STORAGE_ENABLED                            STD_ON
/*! Support security fixed bytes */
# define DCM_STATE_SECURITY_FIXED_BYTES_ENABLED                                STD_OFF
/*! Support multiple security fixed bytes per security level */
# define DCM_STATE_MULTIPLE_SECURITYFIXEDBYTES_ENABLED                         STD_OFF
/*! Support authentication state management */
# define DCM_STATE_AUTHENTICATION_ENABLED                                      STD_OFF
/*! Support authentication bypass */
# define DCM_STATE_AUTHENTICATION_BYPASS_ENABLED                               STD_OFF
/*! Support protocol state management */
# define DCM_STATE_PROTOCOL_ENABLED                                            STD_OFF
/*! Support security level bypass */
# define DCM_STATE_SECURITY_BYPASS_ENABLED                                     STD_OFF
/*! Support security level retention on session self-transition */
# define DCM_STATE_SECURITY_RETAIN_ON_SESSION_SELF_TRANSITION_ENABLED          STD_OFF
/*! Support session change notifications */
# define DCM_STATE_SESSION_NOTIFICATION_ENABLED                                STD_OFF
/*! Support security level change notifications */
# define DCM_STATE_SECURITY_NOTIFICATION_ENABLED                               STD_OFF
/*! Support setting S3 timer at runtime */
# define DCM_STATE_TIMER_S3_APPL_OVERRIDE_ENABLED                              STD_OFF
/*! DEM Interfaces for AR 4.2.1 */
# define DCM_DEMIF_421_ENABLED                                                 STD_OFF
/*! DEM Interfaces for AR 4.3.0 */
# define DCM_DEMIF_430_ENABLED                                                 STD_ON
/*! DEM Interfaces for AR 4.3.1 */
# define DCM_DEMIF_431_ENABLED                                                 STD_OFF
/*! Support DID manager  */
# define DCM_DIDMGR_SUPPORT_ENABLED                                            STD_ON
/*! Support external DID look up filter */
# define DCM_DIDMGR_EXTENDED_LOOKUP_ENABLED                                    STD_OFF
/*! Any paged DID supported */
# define DCM_DIDMGR_PAGED_SUPPORT_ENABLED                                      STD_OFF
/*! Support secure coding for Dcm */
# define DCM_DIDMGR_SECURE_CODING_ENABLED                                      STD_OFF
/*! Support IO control (Reset To Default, Freeze Current State, Short Term Adjustment) operation in S/R style */
# define DCM_DIDMGR_SR_IO_CONTROL_ENABLED                                      STD_OFF
/*! There is a dynamically define periodic DID */
# define DCM_DIDMGR_PERIODICDYNDID_ENABLED                                     STD_OFF
/*! Automatically remove any periodic DID not supported any more in the current state */
# define DCM_DIDMGR_PERIODICDID_CLR_ON_STATE_CHG_ENABLED                       STD_OFF
/*! Support DID ROE */
# define DCM_DIDMGR_OP_INFO_ROE_ENABLED                                        STD_OFF
/*! Support dynamically define DID additional information */
# define DCM_DIDMGR_OP_INFO_DEFINE_ENABLED                                     STD_OFF
/*! The ConditionCheckRead operation on source items will be called */
# define DCM_DIDMGR_DYNDID_SRCITEM_CHECK_COND_ENABLED                          STD_OFF
/*! The session and security states as well as any configured mode conditions on source items will be validated */
# define DCM_DIDMGR_DYNDID_SRCITEM_CHECK_STATE_ENABLED                         STD_OFF
/*! Automatically clear any dynamically defined DID not supported any more in the current state */
# define DCM_DIDMGR_DYNDID_CLR_ON_STATE_CHG_ENABLED                            STD_OFF
/*! Supports any DID NvM signals with read operation */
# define DCM_DIDMGR_NVM_READ_ENABLED                                           STD_OFF
/*! Supports any DID NvM signals with write operation */
# define DCM_DIDMGR_NVM_WRITE_ENABLED                                          STD_OFF
/*! Supports DID 0xF186 signal with read operation */
# define DCM_DIDMGR_DID_F186_READ_ENABLED                                      STD_OFF
/*! Support report of NODI Byte */
# define DCM_DIDMGR_REPORT_NODIBYTE_ENABLED                                    STD_OFF
/*! Support read operation */
# define DCM_DIDMGR_OPTYPE_READ_ENABLED                                        STD_ON
/*! Support DID ranges with gaps */
# define DCM_DIDMGR_OPTYPE_RANGE_ISAVAIL_ENABLED                               STD_OFF
/*! Support return control to ECU */
# define DCM_DIDMGR_OPTYPE_IO_RETCTRL2ECU_ENABLED                              STD_OFF
/*! Support short term adjustment */
# define DCM_DIDMGR_OPTYPE_IO_SHRTTERMADJ_ENABLED                              STD_OFF
/*! Support RID manager  */
# define DCM_RIDMGR_SUPPORT_ENABLED                                            STD_ON
/*! Support external RID look up filter */
# define DCM_RIDMGR_EXTENDED_LOOKUP_ENABLED                                    STD_OFF
/*! Support secure coding for Dcm */
# define DCM_RIDMGR_SECURE_CODING_ENABLED                                      STD_OFF
/*! Support direct memory access */
# define DCM_MEMMGR_SUPPORT_ENABLED                                            STD_OFF
/*! Support memory transfer via FBL */
# define DCM_FBLMGR_SUPPORT_ENABLED                                            STD_ON
/*! Support manager for OBD and UDS IDs */
# define DCM_OBDUDSIDMGR_SUPPORT_ENABLED                                       STD_OFF
/*! Support calibration for OBD and UDS IDs */
# define DCM_OBDUDSIDMGR_CALIBRATION_ENABLED                                   STD_OFF
/*! Support UDS MIDs provided by DEM module */
# define DCM_OBDUDSIDMGR_UDSMID_SUPPORT_BY_DEM_ENABLED                         STD_OFF
/*! Support UDS MIDs from DCM configuration */
# define DCM_OBDUDSIDMGR_UDSMID_SUPPORT_BY_DCM_ENABLED                         STD_OFF
/*! Support of OBD calibration via service 0x22 will be handled by DCM */
# define DCM_SVC_22_OBD_CALIBRATION_ENABLED                                    STD_OFF
/*! Support of OBD calibration via service 0x31 will be handled by DCM */
# define DCM_SVC_31_OBD_CALIBRATION_ENABLED                                    STD_OFF
/*! Support OBD manager for IDs */
# define DCM_OBDIDMGR_SUPPORT_ENABLED                                          STD_OFF
/*! Support OBD-MIDs through the AUTOSAR DEM APIs */
# define DCM_OBDIDMGR_OBDMID_SUPPORT_BY_DEM_ENABLED                            STD_OFF
/*! Support OBD-MIDs in DCM, don't use the AUTOSAR DEM APIs */
# define DCM_OBDIDMGR_OBDMID_SUPPORT_BY_DCM_ENABLED                            STD_OFF
/*! Support manager for OBD DTCs */
# define DCM_OBDDTCMGR_SUPPORT_ENABLED                                         STD_OFF
/*! Split task concept */
# define DCM_SPLIT_TASKS_ENABLED                                               STD_OFF
/*! Delay the unregistration of a diagnostic user */
# define DCM_NET_KEEP_ALIVE_TIME_ENABLED                                       STD_OFF
/*! Start keep alive timer on functional 0x3E 80 request */
# define DCM_NET_KEEP_ALIVE_TIME_START_ON_FUNC_3E_80_ENABLED                   STD_OFF
/*! Parallel service processing */
# define DCM_MULTI_THREAD_ENABLED                                              STD_OFF
/*! Ignore any request with response SID */
# define DCM_DIAG_IGNORE_RESPONSE_SID_ENABLED                                  STD_OFF
/*! Support final response after reset from FBL */
# define DCM_DIAG_JUMPFROMFBL_ENABLED                                          STD_OFF
/*! Support jump to the FBL */
# define DCM_DIAG_JUMPTOFBL_ENABLED                                            STD_OFF
/*! Suppression of NRC 0x7E, 0x7F on functional requests */
# define DCM_DIAG_SUPPRESS_NRC_7F_7E_ENABLED                                   STD_ON
/*! BswM notification for updated application */
# define DCM_DIAG_NOTIF_BSWM_APPL_UPDATED_ENABLED                              STD_OFF
/*! Reset to default session on any functionally requested OBD service */
# define DCM_DIAG_RST2DEF_ON_FUNC_OBD_REQ_ENABLED                              STD_OFF
/*! Support DCM state recovery */
# define DCM_DIAG_STATE_RECOVERY_ENABLED                                       STD_OFF
/*! Support RCR-RP transmission limitation */
# define DCM_DIAG_RCRRP_LIMIT_ENABLED                                          STD_OFF
/*! Support virtual requests */
# define DCM_DIAG_VIRTUAL_REQUEST_ENABLED                                      STD_OFF
/*! Support diagnostic service dispatcher */
# define DCM_DIAG_SERVICE_DISPATCHER_ENABLED                                   STD_OFF
/*! Support SpecificCauseCode in negative response messages */
# define DCM_DIAG_SPECIFIC_CAUSE_CODE_ENABLED                                  STD_OFF
/*! Support system notifications */
# define DCM_DIAG_SYSTEM_NOTIFICATION_ENABLED                                  STD_ON
/*! Support Oem notifications */
# define DCM_DIAG_OEM_NOTIFICATION_ENABLED                                     STD_OFF
/*! Support Service Initializers */
# define DCM_DIAG_SVC_INITIALIZERS_ENABLED                                     STD_ON
/*! Support variant management */
# define DCM_VARMGR_SUPPORT_ENABLED                                            STD_OFF
/*! Support configuration variant management */
# define DCM_VARMGR_MULTI_SVC_EXCLUSIVE_ENABLED                                STD_OFF
/*! Support VSG variant management */
# define DCM_VARMGR_MULTI_SVC_INCLUSIVE_ENABLED                                STD_OFF
/*! Support communication variant management */
# define DCM_VARMGR_MULTI_COM_ENABLED                                          STD_OFF
/*! Active configuration mode for pre-compile */
# define DCM_VARMGR_MODE_PRECOMPILE_ENABLED                                    STD_OFF
/*! Active configuration mode for post build loadable */
# define DCM_VARMGR_MODE_POSTBUILD_LOAD_ENABLED                                STD_OFF
/*! Active configuration mode for post build selectable */
# define DCM_VARMGR_MODE_POSTBUILD_SELECT_ENABLED                              STD_ON
/*! Support authentication manager */
# define DCM_AUTHMGR_SUPPORT_ENABLED                                           STD_OFF
/*! Support external setting of security states */
# define DCM_AUTHMGR_EXT_SETTER_ENABLED                                        STD_OFF
/*! Support authentication with services white lists */
# define DCM_AUTHMGR_WHITELIST_SERVICES_ENABLED                                STD_OFF
/*! Support authentication with DID white lists */
# define DCM_AUTHMGR_WHITELIST_DID_ENABLED                                     STD_OFF
/*! Support authentication with RID white lists */
# define DCM_AUTHMGR_WHITELIST_RID_ENABLED                                     STD_OFF
/*! Support authentication with memory selection white lists */
# define DCM_AUTHMGR_WHITELIST_MEM_ENABLED                                     STD_OFF
/*! Support authentication state persistence in non-volatile memory */
# define DCM_AUTHMGR_PERSIST_STATE_ENABLED                                     STD_OFF
/*! Support API Dcm_SetDeauthenticatedRole() */
# define DCM_AUTHMGR_SET_DEAUTH_ROLE_ENABLED                                   STD_OFF
/*! Support Default Session Timeout */
# define DCM_AUTHMGR_DEFAULT_SESSION_TIMEOUT_ENABLED                           STD_OFF
/*! Support user specific authentication roles */
# define DCM_AUTHMGR_USER_SPECIFIC_ROLES_ENABLED                               STD_OFF
/*! Support Certificate Group Ids */
# define DCM_AUTHMGR_CERT_GROUPS_ENABLED                                       STD_OFF
/*! Ephemeral Key Support */
# define DCM_AUTHMGR_EPHEMERAL_KEY_SUPPORT_ENABLED                             STD_OFF
/*! Session Key Info Support */
# define DCM_AUTHMGR_SESSION_KEY_INFO_SUPPORT_ENABLED                          STD_OFF
/*! All Challenges In ProofOfOwnership Support */
# define DCM_AUTHMGR_ALL_CHALLENGES_POWN_SUPPORT_ENABLED                       STD_OFF
/*! Support anti brute force attempt counter */
# define DCM_AUTHMGR_ANTI_BRUTE_FORCE_SUPPORT_ENABLED                          STD_OFF
/*! Diagnostic service 0x01 handled by DCM */
# define DCM_SVC_01_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x02 handled by DCM */
# define DCM_SVC_02_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x03 handled by DCM */
# define DCM_SVC_03_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x04 handled by DCM */
# define DCM_SVC_04_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x06 handled by DCM */
# define DCM_SVC_06_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x07 handled by DCM */
# define DCM_SVC_07_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x08 handled by DCM */
# define DCM_SVC_08_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x09 handled by DCM */
# define DCM_SVC_09_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x0A handled by DCM */
# define DCM_SVC_0A_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x10 handled by DCM */
# define DCM_SVC_10_SUPPORT_ENABLED                                            STD_ON
/*! Support jump to bootloader */
# define DCM_SVC_10_JMP2BOOT_ENABLED                                           STD_OFF
/*! Reset the ECU before the final response is sent */
# define DCM_SVC_10_RST2BOOT_HIS_ENABLED                                       STD_ON
/*! Diagnostic service 0x11 handled by DCM */
# define DCM_SVC_11_SUPPORT_ENABLED                                            STD_ON
# define DCM_SVC_11_ECU_RESET_ENABLED                                          STD_ON
# define DCM_SVC_11_RAPID_SHTDWN_ENABLED                                       STD_OFF
/*! Reset the ECU before the final response is sent */
# define DCM_SVC_11_RST2BOOT_HIS_ENABLED                                       STD_OFF
# define DCM_SVC_11_01_SUPPORT_ENABLED                                         STD_ON
# define DCM_SVC_11_02_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_11_03_SUPPORT_ENABLED                                         STD_ON
# define DCM_SVC_11_04_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_11_05_SUPPORT_ENABLED                                         STD_OFF
/*! Diagnostic service 0x14 handled by DCM */
# define DCM_SVC_14_SUPPORT_ENABLED                                            STD_ON
/*! User memory identifier available */
# define DCM_SVC_14_USER_MEM_ID_ENABLED                                        STD_OFF
/*! User memory identifier evaluation */
# define DCM_SVC_14_USER_MEM_ID_CHECK_ENABLED                                  STD_OFF
/*! Diagnostic service 0x19 handled by DCM */
# define DCM_SVC_19_SUPPORT_ENABLED                                            STD_ON
# define DCM_SVC_19_01_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_02_SUPPORT_ENABLED                                         STD_ON
# define DCM_SVC_19_03_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_04_SUPPORT_ENABLED                                         STD_ON
# define DCM_SVC_19_05_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_06_SUPPORT_ENABLED                                         STD_ON
# define DCM_SVC_19_07_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_08_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_09_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0A_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0B_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0C_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0D_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0E_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0F_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_10_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_11_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_12_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_13_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_14_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_15_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_16_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_17_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_18_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_19_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_1A_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_42_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_55_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_56_SUPPORT_ENABLED                                         STD_OFF
/*! User memory identifier evaluation */
# define DCM_SVC_19_USER_MEM_ID_CHECK_ENABLED                                  STD_OFF
/*! Dtc Status patch support */
# define DCM_SVC_19_PATCH_SUPPORT_ENABLED                                      STD_OFF
/*! OBDonUDS Dtc Separation */
# define DCM_SVC_19_OBD_UDS_DTC_SEPARATION_ENABLED                             STD_OFF
/*! Diagnostic service 0x22 handled by DCM */
# define DCM_SVC_22_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x23 handled by DCM */
# define DCM_SVC_23_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x24 handled by DCM */
# define DCM_SVC_24_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x27 handled by DCM */
# define DCM_SVC_27_SUPPORT_ENABLED                                            STD_ON
/*! Support post build for service 0x27 */
# define DCM_SVC_27_PB_ENABLED                                                 STD_OFF
/*! Support multiple attempt counter instances */
# define DCM_SVC_27_MULTI_ATTEMPT_COUNTER_ENABLED                              STD_OFF
/*! Support multiple delay timer instances */
# define DCM_SVC_27_MULTI_DELAY_TIMER_ENABLED                                  STD_OFF
/*! Security attempt counter reset on delay timer expiry */
# define DCM_STATE_SEC_RESET_ATT_CNTR_ON_TIMEOUT_ENABLED                       STD_OFF
/*! Reset attempt counter only for the security level which has reached its limit */
# define DCM_STATE_SEC_RESET_ATT_CNTR_SELECTIVELY_ENABLED                      STD_OFF
/*! Diagnostic service 0x28 handled by DCM */
# define DCM_SVC_28_SUPPORT_ENABLED                                            STD_ON
/*! Support communication control on the request channel */
# define DCM_SVC_28_CURNET_SUPPORT_ENABLED                                     STD_ON
/*! Diagnostic service 0x29 handled by DCM */
# define DCM_SVC_29_SUPPORT_ENABLED                                            STD_OFF
/*! Support unidirectional certificate verification */
# define DCM_SVC_29_01_SUPPORT_ENABLED                                         STD_OFF
/*! Support bidirectional certificate verification */
# define DCM_SVC_29_02_SUPPORT_ENABLED                                         STD_OFF
/*! Support certificate transmission */
# define DCM_SVC_29_04_SUPPORT_ENABLED                                         STD_OFF
/*! Support certificate pre-verification */
# define DCM_SVC_29_CERT_PREVERIFICATION_ENABLED                               STD_OFF
/*! Support Custom Challenge Server Computation */
# define DCM_SVC_29_CUSTOM_CHALLENGE_SERVER_ENABLED                            STD_OFF
/*! Support Custom Proof Of Ownership Verification */
# define DCM_SVC_29_CUSTOM_POWN_ENABLED                                        STD_OFF
/*! Support Certificate Verification Error Hook Computation */
# define DCM_SVC_29_CERT_VERIFICATION_ERROR_HOOK_ENABLED                       STD_OFF
/*! Diagnostic service 0x2A handled by DCM */
# define DCM_SVC_2A_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x2C handled by DCM */
# define DCM_SVC_2C_SUPPORT_ENABLED                                            STD_OFF
/*! Support dynamically define DID by identifier */
# define DCM_SVC_2C_01_SUPPORT_ENABLED                                         STD_OFF
/*! Support dynamically define DID by memory address */
# define DCM_SVC_2C_02_SUPPORT_ENABLED                                         STD_OFF
/*! Support clear dynamically defined DID */
# define DCM_SVC_2C_03_SUPPORT_ENABLED                                         STD_OFF
/*! Support NvM persistence of dynamically defined DID */
# define DCM_SVC_2C_NVRAM_SUPPORT_ENABLED                                      STD_OFF
/*! Diagnostic service 0x2E handled by DCM */
# define DCM_SVC_2E_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x2F handled by DCM */
# define DCM_SVC_2F_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x31 handled by DCM */
# define DCM_SVC_31_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x34 handled by DCM */
# define DCM_SVC_34_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x35 handled by DCM */
# define DCM_SVC_35_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x36 handled by DCM */
# define DCM_SVC_36_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x37 handled by DCM */
# define DCM_SVC_37_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x38 handled by DCM */
# define DCM_SVC_38_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x3D handled by DCM */
# define DCM_SVC_3D_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x3E handled by DCM */
# define DCM_SVC_3E_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x85 handled by DCM */
# define DCM_SVC_85_SUPPORT_ENABLED                                            STD_ON
/*! Support DTC group in requests  */
# define DCM_SVC_85_DTC_GRP_ENABLED                                            STD_OFF
/*! Diagnostic service 0x86 handled by DCM */
# define DCM_SVC_86_SUPPORT_ENABLED                                            STD_OFF
/*! Support stop response on event with store event-bit unset */
# define DCM_SVC_86_00_SUPPORT_ENABLED                                         STD_OFF
/*! Support response on DTC status-change with store event-bit unset */
# define DCM_SVC_86_01_SUPPORT_ENABLED                                         STD_OFF
/*! Support response on change of data identifier with store event-bit unset */
# define DCM_SVC_86_03_SUPPORT_ENABLED                                         STD_OFF
/*! Support report activated events with store event-bit unset */
# define DCM_SVC_86_04_SUPPORT_ENABLED                                         STD_OFF
/*! Support start response on event with store event-bit unset */
# define DCM_SVC_86_05_SUPPORT_ENABLED                                         STD_OFF
/*! Support clear response on event with store event-bit unset */
# define DCM_SVC_86_06_SUPPORT_ENABLED                                         STD_OFF
/*! Support response on comparison of values with store event-bit unset */
# define DCM_SVC_86_07_SUPPORT_ENABLED                                         STD_OFF
/*! Support response on DTC Status changed with store event-bit unset */
# define DCM_SVC_86_09_SUPPORT_ENABLED                                         STD_OFF
/*! Support stop response on event with store event-bit set */
# define DCM_SVC_86_40_SUPPORT_ENABLED                                         STD_OFF
/*! Support response on DTC status-change with store event-bit set */
# define DCM_SVC_86_41_SUPPORT_ENABLED                                         STD_OFF
/*! Support response on change of data identifier with store event-bit set */
# define DCM_SVC_86_43_SUPPORT_ENABLED                                         STD_OFF
/*! Support start response on event with store event-bit set */
# define DCM_SVC_86_45_SUPPORT_ENABLED                                         STD_OFF
/*! Support clear response on event with store event-bit set */
# define DCM_SVC_86_46_SUPPORT_ENABLED                                         STD_OFF
/*! Service 0x86 needs a timer */
# define DCM_SVC_86_TIMER_ENABLED                                              STD_OFF
/*! Service 0x86 will be reset on session transition */
# define DCM_SVC_86_RST_ON_DSC_ENABLED                                         STD_OFF
/*! Service 0x86 needs nv blocks */
# define DCM_SVC_86_NVM_SUPPORT_ENABLED                                        STD_OFF
/*! Service 0x86 event type DID supported  */
# define DCM_SVC_86_EVTYPE_ONCHGDID_ENABLED                                    STD_OFF
/*! Service 0x86 event type DTC supported  */
# define DCM_SVC_86_EVTYPE_ONCHGDTC_ENABLED                                    STD_OFF

/*! The maximum number of iterations per DCM task activation */
# define DCM_RUNTIME_USAGE_ITERATIONS                                           0u
/*! DCM AUTOSAR versions */
# define DCM_DCM_AR_VERSION_421                                                0x0421u
/*! DCM AUTOSAR versions */
# define DCM_DCM_AR_VERSION_422                                                0x0422u
/*! DCM AUTOSAR versions */
# define DCM_DCM_AR_VERSION_450                                                0x0450u
/*! DCM active AUTOSAR version */
# define DCM_DCM_AR_VERSION                                                    0x0422u
/*! Vendor specific DCM extension identifier */
# define DCM_EXTENSION_ID                                                      0x96ACD543u
/*! Invalid security event */
# define DCM_DEBUG_SEV_INVALID                                                 0xFFFFu
/*! Security event for successful authentication */
# define DCM_DEBUG_SEV_AUTHENTICATION_SUCCESSFUL                               DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_CERTIFICATE_FAILURE */
# define DCM_DEBUG_SEV_CERTIFICATE_FAILURE                                     DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_CLEAR_DTC_SUCCESSFUL */
# define DCM_DEBUG_SEV_CLEAR_DTC_SUCCESSFUL                                    DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_COMMUNICATION_CONTROL_SWITCHED_OFF */
# define DCM_DEBUG_SEV_COMMUNICATION_CONTROL_SWITCHED_OFF                      DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_DTC_SETTING_SWITCHED_OFF */
# define DCM_DEBUG_SEV_DTC_SETTING_SWITCHED_OFF                                DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_ECU_RESET */
# define DCM_DEBUG_SEV_ECU_RESET                                               DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_ECU_UNLOCK_SUCCESSFUL */
# define DCM_DEBUG_SEV_ECU_UNLOCK_SUCCESSFUL                                   DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_INCORRECT_MESSAGE_LENGTH_OR_FORMAT */
# define DCM_DEBUG_SEV_INCORRECT_MESSAGE_LENGTH_OR_FORMAT                      DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_REQUEST_DOWNLOAD */
# define DCM_DEBUG_SEV_REQUEST_DOWNLOAD                                        DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_REQUEST_OUT_OF_RANGE */
# define DCM_DEBUG_SEV_REQUEST_OUT_OF_RANGE                                    DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_REQUEST_SEQUENCE_ERROR */
# define DCM_DEBUG_SEV_REQUEST_SEQUENCE_ERROR                                  DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_REQUESTED_ACTIONS_REQUIRES_AUTHENTICATION */
# define DCM_DEBUG_SEV_REQUESTED_ACTIONS_REQUIRES_AUTHENTICATION               DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_SECURITY_ACCESS_DENIED */
# define DCM_DEBUG_SEV_SECURITY_ACCESS_DENIED                                  DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_SECURITY_ACCESS_INVALID_KEY */
# define DCM_DEBUG_SEV_SECURITY_ACCESS_INVALID_KEY                             DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_SECURITY_ACCESS_NUMBER_OF_ATTEMPTS_EXCEEDED */
# define DCM_DEBUG_SEV_SECURITY_ACCESS_NUMBER_OF_ATTEMPTS_EXCEEDED             DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_SECURITY_ACCESS_REQUIRED_TIME_DELAY_NOT_EXPIRED */
# define DCM_DEBUG_SEV_SECURITY_ACCESS_REQUIRED_TIME_DELAY_NOT_EXPIRED         DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_SERVICE_NOT_SUPPORTED */
# define DCM_DEBUG_SEV_SERVICE_NOT_SUPPORTED                                   DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_SUBFUNCTION_NOT_SUPPORTED */
# define DCM_DEBUG_SEV_SUBFUNCTION_NOT_SUPPORTED                               DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_WRITE_DATA */
# define DCM_DEBUG_SEV_WRITE_DATA                                              DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_WRITE_INV_DATA */
# define DCM_DEBUG_SEV_WRITE_INV_DATA                                          DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_VERIFY_CERTIFICATE_UNIDIRECTIONAL_FAILURE_WITH_CONTEXTDATA */
# define DCM_DEBUG_SEV_VERIFY_CERTIFICATE_UNIDIRECTIONAL_FAILURE_WITH_CONTEXTDATA DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_VERIFY_CERTIFICATE_BIDIRECTIONAL_FAILURE_WITH_CONTEXTDATA */
# define DCM_DEBUG_SEV_VERIFY_CERTIFICATE_BIDIRECTIONAL_FAILURE_WITH_CONTEXTDATA DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_PROOFOFOWNERSHIP_FAILURE_WITH_CONTEXTDATA */
# define DCM_DEBUG_SEV_PROOFOFOWNERSHIP_FAILURE_WITH_CONTEXTDATA               DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_TRANSMIT_CERTIFICATE_FAILURE_WITH_CONTEXTDATA */
# define DCM_DEBUG_SEV_TRANSMIT_CERTIFICATE_FAILURE_WITH_CONTEXTDATA           DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_ECU_UNLOCK_SUCCESSFUL_WITH_CONTEXTDATA */
# define DCM_DEBUG_SEV_ECU_UNLOCK_SUCCESSFUL_WITH_CONTEXTDATA                  DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_ECU_UNLOCK_FAILURE_WITH_CONTEXTDATA */
# define DCM_DEBUG_SEV_ECU_UNLOCK_FAILURE_WITH_CONTEXTDATA                     DCM_DEBUG_SEV_INVALID
/*! Specifies the AUTOSAR version of the PduR API */
# define DCM_PDUR_API_AR_VERSION                                               0x412
/*! Number of available buffers */
# define DCM_NET_NUM_BUFFERS                                                    1u
/*! Maximum number of ComM channels to keep ECU awake */
# define DCM_NET_MAX_NUM_COMM_CHANNELS                                          2u
/*! Maximum number of ComM channels DCM communicates over */
# define DCM_NET_MAX_NUM_CHANNELS                                               2u
/*! Maximum number of periodic transmission objects */
# define DCM_NET_MAX_NUM_PERIODIC_TX_OBJ                                        0u
/*! Periodic buffer size */
# define DCM_NET_PERIODIC_BUFFER_SIZE                                           0u
/*! Pattern byte used for periodic transmission message padding */
# define DCM_NET_PERIODIC_MSG_PADDING_PATTERN                                  0xAAu
/*! The maximum size of all configured buffers */
# define DCM_NET_MAX_BUFFER_SIZE                                                 96u
/*! Maximum number of connections */
# define DCM_NET_MAX_NUM_CONNECTIONS                                           12u
/*! Number of channels from main connections and ComControl channels */
# define DCM_NET_MAX_NUM_ALL_COMM_CHANNELS                                        2u
/*! The default DemClientId */
# define DCM_NET_DEFAULT_DEM_CLIENTID                                          DemConf_DemClient_DemClient
/*! The number of periodic messages to be sent within the delay time */
# define DCM_NET_DELAY_BULK_TRANSMISSION                                        0u
/*! Maximum periodic response length for service 0x2A */
# define DCM_SVC2A_MAX_RESPONSE_LEN                                             0u
/*! Size of table Dcm_CfgNetBufferInfo */
# define DCM_CFGNETBUFFERINFO_SIZE                                              1u
/*!  ----- Symbolic name values for DCM protocols -----  */
# define DcmConf_DcmDslProtocolRow_DcmDslProtocolRow_29812fbf                   3u
/*!  ----- Symbolic name values for Rx PduIds -----  */
# define DcmConf_DcmDslProtocolRx_DIAG_REQ_FNC_OBD1_oVCAN_RADAR_ea4d23fb_Rx_4734fad9  4u
# define DcmConf_DcmDslProtocolRx_DIAG_REQ_FNC_OBD2_oVCAN_RADAR_57874f35_Rx_1a4abb4e 10u
# define DcmConf_DcmDslProtocolRx_DIAG_REQ_FNC_OTA_oVCAN_RADAR_b630c1e5_Rx_0176162e 16u
# define DcmConf_DcmDslProtocolRx_DIAG_REQ_FNC_PLANT_oVCAN_RADAR_9fd4cadc_Rx_f47e2bb6 22u
# define DcmConf_DcmDslProtocolRx_FR_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_83827d3f_Rx_a310dd11  5u
# define DcmConf_DcmDslProtocolRx_FR_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_3e4811f1_Rx_ef982e0b 11u
# define DcmConf_DcmDslProtocolRx_FR_DIAG_REQ_PHY_OTA_oVCAN_RADAR_7facfb76_Rx_b2eaa10c 17u
# define DcmConf_DcmDslProtocolRx_FR_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_03b4032b_Rx_f4f84964 23u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_FUNC_OBD1_oPCAN_RADAR_20_e986e253_Rx_5365c009  2u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_FUNC_OBD1_oPCAN_RADAR_5664bded_Rx_f8c6c8a4  0u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_FUNC_OBD2_oPCAN_RADAR_20_c04e56a1_Rx_a7582bb7  8u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_FUNC_OBD2_oPCAN_RADAR_ebaed123_Rx_69afd2b8  6u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_FUNC_OTA_oPCAN_RADAR_20_4ceedd9c_Rx_8d5a8781 12u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_FUNC_OTA_oPCAN_RADAR_8729c499_Rx_63a44321 14u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_FUNC_PLANT_oPCAN_RADAR_20_3b79581e_Rx_36801f1b 18u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_FUNC_PLANT_oPCAN_RADAR_8e17ec17_Rx_e2e07788 20u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_PHYS_OBD1_oPCAN_RADAR_20_3bfe27fe_Rx_2d01fee8  3u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_PHYS_OBD1_oPCAN_RADAR_caf5eb16_Rx_95487f2b  1u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_PHYS_OBD2_oPCAN_RADAR_20_1236930c_Rx_26654501  9u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_PHYS_OBD2_oPCAN_RADAR_773f87d8_Rx_31c94776  7u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_PHYS_OTA_oPCAN_RADAR_1f79965d_Rx_897b19f5 15u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_PHYS_OTA_oPCAN_RADAR_20_39ae8dba_Rx_fd38421b 13u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_PHYS_PLANT_oPCAN_RADAR_20_93ccff8e_Rx_c332e01f 19u
# define DcmConf_DcmDslProtocolRx_PCAN_DIAG_REQ_PHYS_PLANT_oPCAN_RADAR_a4e456d5_Rx_de87c92a 21u
/*!  ----- Symbolic name values for Tx PduIds -----  */
# define DcmConf_DcmDslProtocolTx_FR_DIAG_RES_PHY_OBD1_oVCAN_RADAR_add2b4bf_Tx_08033c95  2u
# define DcmConf_DcmDslProtocolTx_FR_DIAG_RES_PHY_OBD2_oVCAN_RADAR_1018d871_Tx_ee91ebc0  5u
# define DcmConf_DcmDslProtocolTx_FR_DIAG_RES_PHY_OTA_oVCAN_RADAR_9b68fa0b_Tx_bc6c5974  8u
# define DcmConf_DcmDslProtocolTx_FR_DIAG_RES_PHY_PLANT_oVCAN_RADAR_ee22d0c2_Tx_70415e78 11u
# define DcmConf_DcmDslProtocolTx_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_20_f26199fd_Tx_55fbdb8d  1u
# define DcmConf_DcmDslProtocolTx_PCAN_DIAG_RESP_PHYS_OBD1_oPCAN_RADAR_62c2ee1d_Tx_71c025ae  0u
# define DcmConf_DcmDslProtocolTx_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_20_dba92d0f_Tx_dcc6691a  4u
# define DcmConf_DcmDslProtocolTx_PCAN_DIAG_RESP_PHYS_OBD2_oPCAN_RADAR_df0882d3_Tx_fbbf77c9  3u
# define DcmConf_DcmDslProtocolTx_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_20_aa3008c9_Tx_74022f70  6u
# define DcmConf_DcmDslProtocolTx_PCAN_DIAG_RESP_PHYS_OTA_oPCAN_RADAR_4fa3c8f0_Tx_93c6c140  7u
# define DcmConf_DcmDslProtocolTx_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_20_0a0c318a_Tx_b4cb0023  9u
# define DcmConf_DcmDslProtocolTx_PCAN_DIAG_RESP_PHYS_PLANT_oPCAN_RADAR_339eb858_Tx_b55bc933 10u
/*! Number of receive PduIds */
# define DCM_NET_NUM_RX_PDUIDS                                                 24u
/*! Number of send PduIds */
# define DCM_NET_NUM_TX_PDUIDS                                                 12u
/*! The total number of configured protocols */
# define DCM_NET_NUM_PROTOCOLS                                                  1u
/*! The minimum RxPduID value of the CanTp */
# define DCM_NET_CANTP_RX_PDUID_MIN                                               0u
/*! The maximum RxPduID value of the CanTp */
# define DCM_NET_CANTP_RX_PDUID_MAX                                               0u
/*! The total number of CanTp RxPduIDs */
# define DCM_NET_NUM_CANTP_RX_PDUIDS                                              0u
/*! Size of table Dcm_CfgNetRxPduInfo */
# define DCM_CFGNETRXPDUINFO_SIZE                                              24u
/*! Size of table Dcm_CfgNetTxPduInfo */
# define DCM_CFGNETTXPDUINFO_SIZE                                              12u
/*! Size of table Dcm_CfgNetConnectionInfo */
# define DCM_CFGNETCONNECTIONINFO_SIZE                                         12u
/*! Size of table Dcm_CfgNetProtocolInfo */
# define DCM_CFGNETPROTOCOLINFO_SIZE                                            1u
/*! Size of table Dcm_CfgNetAllComMChannelMap */
# define DCM_CFGNETALLCOMMCHANNELMAP_SIZE                                       2u
/*! Size of table Dcm_CfgNetConnComMChannelMap */
# define DCM_CFGNETCONNCOMMCHANNELMAP_SIZE                                      2u
/*! Size of table Dcm_CfgNetNetworkHandleLookUpTable */
# define DCM_CFGNETNETWORKHANDLELOOKUPTABLE_SIZE                                3u
/*! Reference to padding function */
# define DCM_PAGEDBUFFER_PADDING_FUNC_REF                                       1u
/*! The mode rule reference for DTC setting re-enabling */
# define DCM_MODE_CTRLDTCSETTING_MONITOR_MODERULE_REF                             0u
/*! The mode rule reference for communication control re-enabling */
# define DCM_MODE_COMMCTRL_MONITOR_MODERULE_REF                                   0u
/*! The mode rule reference for sending the general authentication NRC */
# define DCM_MODE_AUTH_SEND_GENERAL_NRC_MODERULE_REF                              0u
/*! The mode rule reference for persisting the authentication state */
# define DCM_MODE_AUTH_PERSIST_STATE_MODERULE_REF                                 0u
/*! Tester present timeout */
# define DCM_STATE_TIME_S3                                                          500u
/*! Number of session states */
# define DCM_STATE_NUM_SESSION                                                  3u
/*! Number of security access states */
# define DCM_STATE_NUM_SECURITY                                                 2u
/*! Number of security levels (all security states except the "locked" one) */
# define DCM_STATE_SECURITY_NUM_LEVELS                                          1u
/*! Size of table Dcm_CfgStatePreconditions */
# define DCM_CFGSTATEPRECONDITIONS_SIZE                                         8u
/*! Size of table Dcm_CfgStateSessionInfo */
# define DCM_CFGSTATESESSIONINFO_SIZE                                           3u
/*! Size of table Dcm_CfgStateSecurityInfo */
# define DCM_CFGSTATESECURITYINFO_SIZE                                          1u
/*!  ----- Symbolic name values for Session -----  */
# define DcmConf_DcmDspSessionRow_Default                                       1u
# define DcmConf_DcmDspSessionRow_Programming                                   2u
# define DcmConf_DcmDspSessionRow_Extended                                      3u
/*!  ----- Symbolic name values for Security -----  */
# define DcmConf_DcmDspSecurity_Locked                                          0u
# define DcmConf_DcmDspSecurityRow_UnlockedL1                                   9u
/*! Number of DID ranges */
# define DCM_NUM_DID_RANGES                                                     0u
/*! Read paged data page buffer size */
# define DCM_DIDMGR_READ_PAGE_SIZE                                                    7u
/*! Total number of DynDID items */
# define DCM_NUM_DYNDID_ITEMS                                                     0u
/*! Number of dynamically defined DIDs */
# define DCM_NUM_DYNDIDS                                                          0u
/*! Number of IO control DIDs */
# define DCM_NUM_IODIDS                                                           0u
/*! Maximum size of an IO control DIDs CEMR to be passed to the application */
# define DCM_DIDMGR_IODID_MAX_EXT_CEMR_SIZE                                       1u
/*! Pattern used to fill the gaps between Did signals */
# define DCM_DIDMGR_GAP_SIGNAL_PADDING_PATTERN                                 0x00u
/*! Maximum size of the secure coding buffer */
# define DCM_DIDMGR_SECURE_CODING_BUFFER_SIZE                                         1u
/*! Size of table Dcm_CfgDidMgrDidLookUpTable */
# define DCM_CFGDIDMGRDIDLOOKUPTABLE_SIZE                                      32u
/*! Size of table Dcm_CfgDidMgrDidRanges */
# define DCM_CFGDIDMGRDIDRANGES_SIZE                                            1u
/*! Size of table Dcm_CfgDidMgrRangeDidInfoRefs */
# define DCM_CFGDIDMGRRANGEDIDINFOREFS_SIZE                                     1u
/*! Size of table Dcm_CfgDidMgrDidInfo */
# define DCM_CFGDIDMGRDIDINFO_SIZE                                             31u
/*! Size of table Dcm_CfgDidMgrDidOpInfo */
# define DCM_CFGDIDMGRDIDOPINFO_SIZE                                           34u
/*! Size of table Dcm_CfgDidMgrDidOpClassInfo */
# define DCM_CFGDIDMGRDIDOPCLASSINFO_SIZE                                      65u
/*! Size of table Dcm_CfgDidMgrSignalOpClassInfo */
# define DCM_CFGDIDMGRSIGNALOPCLASSINFO_SIZE                                   64u
/*! Invalid value for Routine Info Byte */
# define DCM_CFGRIDMGR_INVALID_ROUTINEINFOBYTE                                    0u
/*! Pattern used to fill the gaps between Rid signals */
# define DCM_RIDMGR_GAP_SIGNAL_PADDING_PATTERN                                 0x00u
/*! Size of table Dcm_CfgRidMgrRidLookUpTable */
# define DCM_CFGRIDMGRRIDLOOKUPTABLE_SIZE                                       9u
/*! Size of table Dcm_CfgRidMgrRidInfo */
# define DCM_CFGRIDMGRRIDINFO_SIZE                                              8u
/*! Size of table Dcm_CfgRidMgrOpInfo */
# define DCM_CFGRIDMGROPINFO_SIZE                                              14u
/*! Specifies total number of supported memory operations */
# define DCM_MEMMGR_NUM_MEMORY_OPERATIONS                                       0u
/*! Specifies total number of memory ranges in single MID or no MID mode */
# define DCM_MEMMGR_MEMMAP_NUM_ENTRIES                                            0u
/*! Call out function for service 0x34 */
# define DCM_PROCESS_REQUEST_DOWNLOAD                                          Dcm_ProcessRequestDownload
/*! Call out function for service 0x36 */
# define DCM_PROCESS_TRANSFER_DATA_WRITE                                       Dcm_ProcessTransferDataWrite
/*! Call out function for service 0x35 */
# define DCM_PROCESS_REQUEST_UPLOAD                                            Dcm_ProcessRequestUpload
/*! Call out function for service 0x36 */
# define DCM_PROCESS_TRANSFER_DATA_READ                                        Dcm_ProcessTransferDataRead
/*! Call out function for service 0x37 */
# define DCM_PROCESS_REQUEST_TRANSFER_EXIT                                     Dcm_ProcessRequestTransferExit
/*! Size of table Dcm_CfgFblMgrTransferAlfidLookUpTable */
# define DCM_CFGFBLMGRTRANSFERALFIDLOOKUPTABLE_SIZE                            17u
/*! Size of table Dcm_CfgFblMgrTransferMidLookUpTable */
# define DCM_CFGFBLMGRTRANSFERMIDLOOKUPTABLE_SIZE                               1u
/*! Configured main function period time */
# define DCM_TASK_CYCLE_MS                                                       10u
/*! Configured keep alive time */
# define DCM_NET_KEEP_ALIVE_TIME                                                  0u
/*! The total number threads */
# define DCM_NUM_THREADS                                                        1u
/*! Maximum number of RCR-RP response before processing interruption */
# define DCM_DIAG_RCRRP_LIMIT_COUNT                                             0u
/*! Specifies the NRC to be sent, once the maximum number of RCR-RP responses has been reached */
# define DCM_DIAG_CANCEL_OP_NRC                                                DCM_E_GENERALREJECT
/*! Specifies the reference to function that stops the repeater */
# define DCM_DIAG_SERVICEINFO_REPEATEREND_IDX                                  14u
/*! Size of table Dcm_CfgDiagSvcIdLookUpTable */
# define DCM_CFGDIAGSVCIDLOOKUPTABLE_SIZE                                      15u
/*! Size of table Dcm_CfgDiagSvcInitializers */
# define DCM_CFGDIAGSVCINITIALIZERS_SIZE                                        1u
/*! Size of table Dcm_CfgDiagServiceInfo */
# define DCM_CFGDIAGSERVICEINFO_SIZE                                           15u
/*! Size of table Dcm_CfgDiagSvcIdExecPrecondTable */
# define DCM_CFGDIAGSVCIDEXECPRECONDTABLE_SIZE                                 14u
/*! Size of table Dcm_CfgDiagSvcPostProcessors */
# define DCM_CFGDIAGSVCPOSTPROCESSORS_SIZE                                     10u
/*! Size of table Dcm_CfgDiagSvcUpdaters */
# define DCM_CFGDIAGSVCUPDATERS_SIZE                                            3u
/*! Size of table Dcm_CfgDiagSvcCancellers */
# define DCM_CFGDIAGSVCCANCELLERS_SIZE                                          5u
/*! Size of table Dcm_CfgDiagSvcPreHandlers */
# define DCM_CFGDIAGSVCPREHANDLERS_SIZE                                         1u
/*! Size of table Dcm_CfgDiagSvcPostHandlers */
# define DCM_CFGDIAGSVCPOSTHANDLERS_SIZE                                        1u
/*! Size of table Dcm_CfgDiagSysNotificationInfo */
# define DCM_CFGDIAGSYSNOTIFICATIONINFO_SIZE                                    1u
/*! Size of table Dcm_CfgDiagSvcId2ProtMap */
# define DCM_CFGDIAGSVCID2PROTMAP_SIZE                                         14u
/*! Total number of configuration variants */
# define DCM_VARMGR_NUM_CFG_VARIANTS                                              8u
/*! Release specific variant magic number */
# define DCM_CFG_FINAL_MAGIC_NUMBER                                            0x3530u
/*! Release specific generator compatibility number */
# define DCM_CFG_GEN_COMPATIBILITY_VERSION                                     0x7480u
/*! Maximum numbers of Dids which could be handled in parallel. */
# define DCM_RSRCMGR_DID_LOCK_LIST_SIZE                                         1u
/*! The deauthenticated role */
# define DCM_AUTHMGR_DEAUTHENTICATED_ROLE                                      0x00000000u
/*! Default session timeout for transition to deauthenticated state */
# define DCM_AUTHMGR_DEFAULT_SESSION_TIMEOUT                                      0u
/*! Overall max size of client challenge */
# define DCM_AUTHMGR_CHALLENGE_CLIENT_MAX_SIZE                                    0u
/*! Overall max size of server challenge */
# define DCM_AUTHMGR_CHALLENGE_SERVER_MAX_SIZE                                    0u
/*! Overall max size of ephemeral key */
# define DCM_AUTHMGR_EPK_MAX_SIZE                                                 0u
/*! Size of the role element in a certificate */
# define DCM_AUTHMGR_CERT_ROLE_SIZE                                             0u
/*! Specifies total number of supported DID white list elements */
# define DCM_AUTHMGR_NUM_DID_WL_ELEMENTS                                        0u
/*! Specifies total number of supported memory selection white list elements */
# define DCM_AUTHMGR_NUM_MEM_WL_ELEMENTS                                        0u
/*! Specifies total number of supported RID white list elements */
# define DCM_AUTHMGR_NUM_RID_WL_ELEMENTS                                        0u
/*! Specifies total number of supported service white list elements */
# define DCM_AUTHMGR_NUM_SERVICE_WL_ELEMENTS                                    0u
/*! Specifies total number of authentication connections */
# define DCM_AUTHMGR_NUM_AUTH_CONNECTIONS                                       0u
/*! Invalid white list KeyM element id */
# define DCM_AUTHMGR_INVALID_WL_KEYM_ELEMENT_ID                                65535u
/*! Invalid client certificate id */
# define DCM_AUTHMGR_INVALID_CERT_ID                                           65535u
/*! Invalid client certificate group id */
# define DCM_AUTHMGR_INVALID_GROUP_ID                                          65535u
/*! Invalid epk job id */
# define DCM_AUTHMGR_INVALID_EPK_ID                                            4294967295u
/*! Invalid authentication info reference */
# define DCM_AUTHMGR_INVALID_AUTH_INFO_REF                                     0xFFu
/*! General NRC for authentication */
# define DCM_AUTHMGR_GENERAL_NRC                                               0x00u
/*! JobId for secure coding validation job */
# define DCM_AUTHMGR_SECURE_CODING_CSM_JOB_ID
/*! Size of table Dcm_CfgSvc10SubFuncLookUpTable */
# define DCM_CFGSVC10SUBFUNCLOOKUPTABLE_SIZE                                    4u
/*! Size of table Dcm_CfgSvc10SubFuncInfo */
# define DCM_CFGSVC10SUBFUNCINFO_SIZE                                           3u
/*! Size of table Dcm_CfgSvc10SubFuncExecPrecondTable */
# define DCM_CFGSVC10SUBFUNCEXECPRECONDTABLE_SIZE                               3u
/*! The ECU power down time */
# define DCM_SVC_11_POWERDOWNTIME                                              255u
/*! Size of table Dcm_CfgSvc11SubFuncLookUpTable */
# define DCM_CFGSVC11SUBFUNCLOOKUPTABLE_SIZE                                    3u
/*! Size of table Dcm_CfgSvc11SubFuncInfo */
# define DCM_CFGSVC11SUBFUNCINFO_SIZE                                           2u
/*! Size of table Dcm_CfgSvc11SubFuncExecPrecondTable */
# define DCM_CFGSVC11SUBFUNCEXECPRECONDTABLE_SIZE                               2u
/*! Size of table Dcm_CfgSvc19SubFuncLookUpTable */
# define DCM_CFGSVC19SUBFUNCLOOKUPTABLE_SIZE                                    4u
/*! Size of table Dcm_CfgSvc19SubFuncInfo */
# define DCM_CFGSVC19SUBFUNCINFO_SIZE                                           3u
/*! Size of table Dcm_CfgSvc19SubFuncExecPrecondTable */
# define DCM_CFGSVC19SUBFUNCEXECPRECONDTABLE_SIZE                               3u
/*! Specifies the maximum number of DIDs per single request service 0x22 */
# define DCM_SVC_22_MAX_DID_LIST_LEN                                            5u
/*! The total number of failed attempt counter monitors */
# define DCM_SVC_27_NUM_ATTEMPT_COUNTERS                                        1u
/*! The total number of failed attempt timers */
# define DCM_SVC_27_NUM_DELAY_TIMERS                                            1u
/*! Maximum allowed seed length for SafeBSW checks */
# define DCM_SAFEBSW_SVC27_MAX_SEED_LENGTH                                           16u
/*! Size of table Dcm_CfgSvc27SubFuncLookUpTable */
# define DCM_CFGSVC27SUBFUNCLOOKUPTABLE_SIZE                                    3u
/*! Size of table Dcm_CfgSvc27SecLevelInfo */
# define DCM_CFGSVC27SECLEVELINFO_SIZE                                          1u
/*! Size of table Dcm_CfgSvc27SubFuncExecPrecondTable */
# define DCM_CFGSVC27SUBFUNCEXECPRECONDTABLE_SIZE                               2u
/*! Size of table Dcm_CfgSvc28SubFuncLookUpTable */
# define DCM_CFGSVC28SUBFUNCLOOKUPTABLE_SIZE                                    5u
/*! Size of table Dcm_CfgSvc28SubFuncInfo */
# define DCM_CFGSVC28SUBFUNCINFO_SIZE                                           4u
/*! Size of table Dcm_CfgSvc28SubFuncExecPrecondTable */
# define DCM_CFGSVC28SUBFUNCEXECPRECONDTABLE_SIZE                               4u
/*! Size of table Dcm_CfgSvc28MessageTypeLookUpTable */
# define DCM_CFGSVC28MESSAGETYPELOOKUPTABLE_SIZE                                4u
/*! Size of table Dcm_CfgSvc28SubNetIdLookUp */
# define DCM_CFGSVC28SUBNETIDLOOKUP_SIZE                                        2u
/*! Size of table Dcm_CfgSvc28SubNetIdMap */
# define DCM_CFGSVC28SUBNETIDMAP_SIZE                                           1u
/*! Specifies the buffers size needed for data extraction of a DDDID source item */
# define DCM_SVC_2C_READ_BUFFER_SIZE                                              0u
/*! Buffer size for the routine parameter integrity */
# define DCM_SVC_31_INTEGRITY_BUFFER_SIZE                                         1u
/*! Size of table Dcm_CfgSvc3ESubFuncLookUpTable */
# define DCM_CFGSVC3ESUBFUNCLOOKUPTABLE_SIZE                                    2u
/*! Size of table Dcm_CfgSvc3ESubFuncExecPrecondTable */
# define DCM_CFGSVC3ESUBFUNCEXECPRECONDTABLE_SIZE                               1u
/*! Specifies the total request length for service 0x85 */
# define DCM_SVC_85_REQ_LENGTH                                                  1u
/*! Size of table Dcm_CfgSvc85SubFuncLookUpTable */
# define DCM_CFGSVC85SUBFUNCLOOKUPTABLE_SIZE                                    3u
/*! Size of table Dcm_CfgSvc85SubFuncExecPrecondTable */
# define DCM_CFGSVC85SUBFUNCEXECPRECONDTABLE_SIZE                               2u
/*! Size of table Dcm_CfgSvc85SubFuncInfo */
# define DCM_CFGSVC85SUBFUNCINFO_SIZE                                           2u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA DECLARATIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#endif /* !defined(DCM_CFG_H) */

/**********************************************************************************************************************
 *  END OF FILE: Dcm_Cfg.h
 *********************************************************************************************************************/

