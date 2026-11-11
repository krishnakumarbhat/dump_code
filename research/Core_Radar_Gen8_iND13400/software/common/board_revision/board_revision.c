/*===========================================================================*\
 * FILE: board_revision.c
 *===========================================================================
 * Copyright � 2020 Aptiv Advanced Safety and User Experience. All rights
 * reserved.
 * Confidential � Restricted Aptiv information. Do not disclose.
 *
 * DESCRIPTION:
 * This file contains functions related to Board Revision.
 *
 * ABBREVIATIONS:
 *   List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   Requirements Document(s):
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards" [30-Mar-2018]
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "board_revision.h"
#include "Rte_Type.h"
#include "SWC_PLT_Service_IoHwAb.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
#define Is_Within_Limits(x, i) (((x) >= Board_Rev_Th[i].lower) && ((x) <= Board_Rev_Th[i].upper))

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
static Board_Revision_T Board_Revision;

const Board_Rev_Threshold_T Board_Rev_Th[BOARD_REV_MAX] = {
   {0U, 128U},

   {129U, 384U},

   {385U, 640U},

   {641U, 896U},

   {897U, 1152U},

   {1153U, 1408U},

   {1409U, 1664U},

   {1665U, 1920U},

   {1921U, 2176U},

   {2177U, 2432U},

   {2433U, 2688U},

   {2689U, 2944U},

   {2945U, 3200U},

   {3201U, 3456U},

   {3457U, 3712U},

   {3713U, 3968U},

   {3969U, 4096U},
};

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/*****************************************************************************
 *. Name: void Read_Board_Revision(void)
 *.    This function checks the board revision.
 *.
 *. Parameters:void
 *.
 *. Return Value: None.
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
void Read_Board_Revision(void)
{
   uint16_t board_rev_cnt = 0U;
   uint8_t i              = 0U;

   board_rev_cnt = Get_Board_Rev_Cnt();

   for (i = 0; i < BOARD_REV_MAX; i++)
   {
      if (Is_Within_Limits(board_rev_cnt, i))
      {
         Board_Revision = (Board_Revision_T)i;
         break;
      }
   }
}

/*****************************************************************************
 *. Name: Board_Revision_T Get_Board_Revision(void)
 *.    This function returns board revision
 *.
 *. Parameters: None.
 *.
 *. Return Value: uint8_t.
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/

Board_Revision_T Get_Board_Revision(void)
{
   return Board_Revision;
}
