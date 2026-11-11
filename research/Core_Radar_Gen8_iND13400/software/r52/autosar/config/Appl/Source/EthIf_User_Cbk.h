#ifndef ETHIF_USER_CBK_H
#define ETHIF_USER_CBK_H

/**\file
 * \brief Callback functions stubs definitions for Ethernet Interface Link Status
 *
 * This file contains some implementations needed to manage Eth Link and Properties
 *
 * \b Application:        RNA SRR5 \n
 * \b File-Revision:      %version: 1 %\n
 * \b Last-Changed-by:    %derived_by: cjkl48 % \n
 * \b Classification:     CONFIDENTIAL \n
 */

/*============================================================================*
 *
 * Copyright 2021 APTIV, Inc., All Rights Reserved
 * It is not allowed to reproduce or utilize parts of this document in any form
 * or by any means, including photocopying and microfilm, without permission in
 * written by APTIV Electronics & Safety Division.
 *
 *============================================================================*/
#include "EthIf.h"
#include "Std_Types.h"
#include "TcpIp_Types.h"

/*============================================================================*
 * PREPROCESSOR DIRECTIVES
 *============================================================================*/

/* INCLUDE DIRECTIVES FOR STANDARD HEADERS -----------------------------------*/

/* INCLUDE DIRECTIVES FOR OTHER HEADERS --------------------------------------*/

/* EXPORTED DEFINE MACROS (#, ##) --------------------------------------------*/

/* EXPORTED DEFINES FOR CONSTANTS --------------------------------------------*/
#define MAC_ADDR_BYTES  (6u)
#define IP_ADD_POS_3    (24u)
#define IP_ADD_POS_2    (16u)
#define IP_ADD_POS_1    (8u)
#define IP_ADD_POS_0    (0u)
#define REMOTE_PORT     (0xB315u)
#define LOCAL_PORT      (0xBA13u)
#define CDC_PORT_OFFSET (0x100u)
/*============================================================================*\
 * EXPORTED TYPEDEF DECLARATIONS
\*============================================================================*/

/* ENUMS ---------------------------------------------------------------------*/

/* STRUCTS -------------------------------------------------------------------*/

/* UNIONS --------------------------------------------------------------------*/

/* OTHER TYPEDEFS ------------------------------------------------------------*/

/*============================================================================*\
 * EXPORTED OBJECT DECLARATIONS
\*============================================================================*/

/*============================================================================*\
 * EXPORTED FUNCTIONS PROTOTYPES
\*============================================================================*/

/* Link State Change callback - Called once per change,
 *which guarantees resetting of IP and MAC once Link is lost and reestablished
 */
void CDD_Cbk_TrcvLinkStateChg(uint8 EthIfCtrlIdx, EthTrcv_LinkStateType TrcvLinkState);

/*============================================================================*\
 * LOCAL FUNCTIONS PROTOTYPES
\*============================================================================*/
static uint8 *Get_Sensor_Mac_Address(uint8 position);
static uint32 Get_Sensor_IP_Address(uint8 position);

/*============================================================================*\
 * EXPORTED FUNCTIONS PROTOTYPES
\*============================================================================*/
extern uint32 Get_Remote_IP_Address(void);
extern uint16 Get_Remote_Port(void);
extern uint16 Get_Local_Port(void);

/*==================================================================================================================================================================*\
* File Revision History (top to bottom: first revision to last revision)
*==================================================================================================================================================================
*    Date        By             Description
* ----------  ---------   -----------------------
* 11-02-2022  Mounir          - Initial Version to set IP and MAC per sensor position.
*
\*======================================================================================================================================================================*/
#endif /* ETHIF_USER_CBK_H */
