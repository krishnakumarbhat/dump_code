/*===========================================================================*\
 * FILE: dio_wrapper.c
 *===========================================================================
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2026 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains DIO wrapper functions to validate channel access based
 *   on board revision. A2 boards can only access A2_A3 common pins, while
 *   A3 boards can access both A2_A3 and A3-specific pins.
 *
 * ABBREVIATIONS:
 *   DIO - Digital Input/Output
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/GlobalRegional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards </a>
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/

/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include <stddef.h>

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "board_revision.h"
#include "dio_wrapper.h"

/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/
#define IS_CHANNEL_IN_LIST(channel, array) Is_Channel_In_List((channel), (array), (sizeof(array) / sizeof(array[0])))

/*===========================================================================*\
 * Local Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Local Object Definitions
\*===========================================================================*/
/* Table mapping DIO channels available on both A2 and A3 boards */
static const Dio_ChannelType A2_A3_Common_Channels[] = {DioConf_DioChannel_A2_A3_MARS_RESET_N, DioConf_DioChannel_A2_A3_CANWK_EN,
                                                        DioConf_DioChannel_A2_A3_MM_FRAME_START,
                                                        DioConf_DioChannel_A2_A3_ERRN_HSDEN, DioConf_DioChannel_A2_A3_POS_GND_EN};

/* Table mapping DIO channels available only on A3 boards */
static const Dio_ChannelType A3_Channels[] = {DioConf_DioChannel_A3_DEBUG_DETECT, DioConf_DioChannel_A3_TOD,
                                              DioConf_DioChannel_A3_ERR_N, DioConf_DioChannel_A3_FPGA_RST_N,
                                              DioConf_DioChannel_A3_HSD_FAULT};

/*===========================================================================*\
 * Local Function Prototypes
\*===========================================================================*/
static bool Is_Channel_In_List(Dio_ChannelType ChannelId, const Dio_ChannelType *channel_list, uint8_t list_count);

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/

/*****************************************************************************
 * Function: Is_Channel_In_List
 *
 * Description:
 *   Generic function to check if a channel is present in a given array
 *
 * Parameters:
 *   ChannelId    - DIO channel identifier to search for
 *   channel_list - Pointer to array of DIO channels
 *   list_count   - Number of elements in the array
 *
 * Return:
 *   bool - true if channel is found in the list, false otherwise
 ******************************************************************************/
static bool Is_Channel_In_List(Dio_ChannelType ChannelId, const Dio_ChannelType *channel_list, uint8_t list_count)
{
   uint8_t i;
   bool is_found = false;

   for (i = 0; i < list_count; i++)
   {
      if (ChannelId == channel_list[i])
      {
         is_found = true;
         break;
      }
   }

   return is_found;
}

/*****************************************************************************
 * Function: Dio_Wrapper_IsChannelAllowed
 *
 * Description:
 *   Checks if a DIO channel is allowed to be accessed based on the current
 *   board revision. A2 boards can only access A2_A3 common pins, while
 *   A3 boards can access both A2_A3 common pins and A3-specific pins.
 *   Any channel not explicitly in the allowed lists will be rejected.
 *
 * Parameters:
 *   ChannelId - DIO channel identifier
 *
 * Return:
 *   bool - true if channel access is allowed, false otherwise
 ******************************************************************************/
bool Dio_Wrapper_IsChannelAllowed(Dio_ChannelType ChannelId)
{
   Board_Revision_T board_rev;
   bool is_allowed = false;

   /* Get current board revision */
   board_rev = Get_Board_Revision();

   switch (board_rev)
   {
      /* Intentional fall through of the cases for common HW Versions */
      case BOARD_REV_A2P0:
      case BOARD_REV_A2P1:
         /* A2 boards can only access A2_A3 common channels */
         if (IS_CHANNEL_IN_LIST(ChannelId, A2_A3_Common_Channels))
         {
            is_allowed = true;
         }
         break;

      /* Intentional fall through of the cases for common HW Versions */
      case BOARD_REV_A3P0:
      case BOARD_REV_B0CVAL:
      case BOARD_REV_B0CVAL_ETH:
         /* A3 boards can access A2_A3 common channels and A3-specific channels */
         if (IS_CHANNEL_IN_LIST(ChannelId, A2_A3_Common_Channels) || IS_CHANNEL_IN_LIST(ChannelId, A3_Channels))
         {
            is_allowed = true;
         }
         break;

      default:
         /* Unknown board revision - no channels allowed */
         break;
   }

   return is_allowed;
}

/*****************************************************************************
 * Function: Dio_Wrapper_ReadChannel
 *
 * Description:
 *   Wrapper function for Dio_ReadChannel that validates channel access based
 *   on board revision. A2 boards can only access A2_A3 common pins, while
 *   A3 boards can access both A2_A3 and A3-specific pins.
 *
 * Parameters:
 *   ChannelId - DIO channel identifier
 *   Status    - Pointer to store operation status
 *
 * Return:
 *   Dio_LevelType - Channel level (STD_HIGH/STD_LOW) if successful,
 *                   STD_LOW if validation fails
 ******************************************************************************/
Dio_LevelType Dio_Wrapper_ReadChannel(Dio_ChannelType ChannelId, Dio_Wrapper_Status_T *Status)
{
   Dio_LevelType level               = STD_LOW;
   Dio_Wrapper_Status_T local_status = DIO_WRAPPER_OK;

   /* Validate channel access based on board revision */
   if (!Dio_Wrapper_IsChannelAllowed(ChannelId))
   {
      local_status = DIO_WRAPPER_BOARD_MISMATCH;
   }
   else
   {
      /* Channel is allowed, perform read operation */
      level        = Dio_ReadChannel(ChannelId);
      local_status = DIO_WRAPPER_OK;
   }

   /* Update status if pointer is provided */
   if (Status != NULL)
   {
      *Status = local_status;
   }

   return level;
}

/*****************************************************************************
 * Function: Dio_Wrapper_WriteChannel
 *
 * Description:
 *   Wrapper function for Dio_WriteChannel that validates channel access based
 *   on board revision. A2 boards can only access A2_A3 common pins, while
 *   A3 boards can access both A2_A3 and A3-specific pins.
 *
 * Parameters:
 *   ChannelId - DIO channel identifier
 *   Level     - Level to be written (STD_HIGH/STD_LOW)
 *
 * Return:
 *   Dio_Wrapper_Status_T - Status of the operation
 ******************************************************************************/
Dio_Wrapper_Status_T Dio_Wrapper_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
   Dio_Wrapper_Status_T status = DIO_WRAPPER_OK;

   /* Validate channel access based on board revision */
   if (!Dio_Wrapper_IsChannelAllowed(ChannelId))
   {
      status = DIO_WRAPPER_BOARD_MISMATCH;
   }
   else
   {
      /* Channel is allowed, perform write operation */
      Dio_WriteChannel(ChannelId, Level);
      status = DIO_WRAPPER_OK;
   }

   return status;
}
