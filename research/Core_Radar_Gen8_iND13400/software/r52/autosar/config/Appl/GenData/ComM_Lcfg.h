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
 *              File: ComM_Lcfg.h
 *   Generation Time: 2026-04-02 15:10:12
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

#if !defined(COMM_LCFG_H)
#define COMM_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
**********************************************************************************************************************/
#include "ComM_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
 *  CONFIG POINTER
**********************************************************************************************************************/
#if (COMM_USE_INIT_POINTER == STD_ON)
# define COMM_START_SEC_VAR_CLEARED_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
# include "ComM_MemMap.h"

extern P2CONST(ComM_ConfigType, AUTOMATIC, COMM_INIT_DATA) ComM_ConfigPtr;

# define COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
# include "ComM_MemMap.h"
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
**********************************************************************************************************************/

#define COMM_START_SEC_CONST_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "ComM_MemMap.h"

extern CONST(ComM_InhibitionStatusType, COMM_CONST) ComM_ECUGroupClassInit;

#define COMM_STOP_SEC_CONST_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "ComM_MemMap.h"

/* PRQA S 3451, 3449 EXTERNDECLARATIONS */ /* MD_ComM_3451_3449 */

/* PRQA L:EXTERNDECLARATIONS */

#define COMM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "ComM_MemMap.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

 /* PRQA S 3451, 3449 EXTERNDECLARATIONS */ /* MD_ComM_3451_3449 */
/*********************************************************************************************************************
FUNCTION: ComM_MainFunction_0
*********************************************************************************************************************/
/*! \brief       Calls ComM_MainFunction() for the corresponding channel. This function is called by RTE with the
 *               configured channel-specific Main Function Period
 *  \pre         ComM must be initialized
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_MainFunction_0(void);
/* PRQA L:EXTERNDECLARATIONS */

 /* PRQA S 3451, 3449 EXTERNDECLARATIONS */ /* MD_ComM_3451_3449 */
/*********************************************************************************************************************
FUNCTION: ComM_MainFunction_1
*********************************************************************************************************************/
/*! \brief       Calls ComM_MainFunction() for the corresponding channel. This function is called by RTE with the
 *               configured channel-specific Main Function Period
 *  \pre         ComM must be initialized
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_MainFunction_1(void);
/* PRQA L:EXTERNDECLARATIONS */

 /* PRQA S 3451, 3449 EXTERNDECLARATIONS */ /* MD_ComM_3451_3449 */
/*********************************************************************************************************************
FUNCTION: ComM_MainFunction_2
*********************************************************************************************************************/
/*! \brief       Calls ComM_MainFunction() for the corresponding channel. This function is called by RTE with the
 *               configured channel-specific Main Function Period
 *  \pre         ComM must be initialized
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_MainFunction_2(void);
/* PRQA L:EXTERNDECLARATIONS */

/**********************************************************************************************************************
 *  INTERNAL GENERATED FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
FUNCTION: ComM_MainFunction()
*********************************************************************************************************************/
/*! \brief      Function to perform channel-specific state transitions and state change notifications.
 *  \details     This function must be called cyclically with the configured channel-specific cycle time.
 *  \param[in]   Channel                 Valid channel identifier (network handle)
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
*********************************************************************************************************************/
extern FUNC( void, COMM_CODE ) ComM_MainFunction( NetworkHandleType Channel );

/*********************************************************************************************************************
  FUNCTION: ComM_CurrentChannelRequestInit
*********************************************************************************************************************/
/*! \brief       This function initializes data needed by sender-receiver interface ComM_CurrentChannelRequest.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_CurrentChannelRequestInit( void );

/*********************************************************************************************************************
  FUNCTION: ComM_CurrentChannelRequestNotification
*********************************************************************************************************************/
/*! \brief       This function updates the set of ComM users currently requesting FULL_COMM for a channel
 *               if the set changes and notifies SWC-s using the sender-receiver interface ComM_CurrentChannelRequest.
 *  \param[in]   Channel                 Handle of the ComM channel, can be found in ComM_Lcfg.h
 *  \param[in]   numberOfRequesters      Number of users which keep the channel requested. This is the
 *                                       number of valid user handle entries in ComM_FullComRequesters array.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_CurrentChannelRequestNotification( NetworkHandleType Channel, ComM_SizeOfFullComRequestersType numberOfRequesters );

#define COMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "ComM_MemMap.h"


#endif /* COMM_LCFG_H */


