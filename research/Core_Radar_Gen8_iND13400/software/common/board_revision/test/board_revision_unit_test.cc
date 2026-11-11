/*===========================================================================*/
/**
 * @file board_revision_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for checking the board_revision.c file
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include <gtest/gtest.h>
#include <stdint.h>

DEFINE_FFF_GLOBALS;

extern "C"
{
/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/

/*===========================================================================*
 * File Under Test
 *===========================================================================*/
#include "board_revision.c"

   /*===========================================================================*
    * FFF Fakes - Only fake the external dependency Get_Board_Rev_Cnt
    * (Read_Board_Revision and Get_Board_Revision are real, from board_revision.c)
    *===========================================================================*/
   FAKE_VALUE_FUNC(uint16_t, Get_Board_Rev_Cnt);
}
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class board_revision_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      RESET_FAKE(Get_Board_Rev_Cnt);
      FFF_RESET_HISTORY();
      Board_Revision = BOARD_REV_EDU;
   }

   /**
    * @b Description
    * @n
    *    Method run after each individual test case.
    */
   void TearDown()
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 *  @b Read_Board_Revision_Test
 *  @n
 *     Checks the assignment of board revision based on the board_rev_count
 */
TEST_F(board_revision_UnitTestSuite, Read_Board_Revision_Test_1)
{
   Get_Board_Rev_Cnt_fake.return_val = 64U; /* Within {0U, 128U} -> BOARD_REV_EDU */
   Read_Board_Revision();
   EXPECT_EQ(Get_Board_Revision(), BOARD_REV_EDU) << "Board_Revision should be BOARD_REV_EDU.";
}

/**
 *  @b Read_Board_Revision_Test
 *  @n
 *     Checks the assignment of board revision based on the board_rev_count
 */
TEST_F(board_revision_UnitTestSuite, Read_Board_Revision_Test_2)
{
   Get_Board_Rev_Cnt_fake.return_val = 256U; /* Within {129U, 384U} -> BOARD_REV_EDU3 */
   Read_Board_Revision();
   EXPECT_EQ(Get_Board_Revision(), BOARD_REV_EDU3) << "Board_Revision should be BOARD_REV_EDU3.";
}

/**
 *  @b Read_Board_Revision_Test
 *  @n
 *     Checks the assignment of board revision based on the board_rev_count
 */
TEST_F(board_revision_UnitTestSuite, Read_Board_Revision_Test_3)
{
   Get_Board_Rev_Cnt_fake.return_val = 512U; /* Within {385U, 640U} -> BOARD_REV_A0 */
   Read_Board_Revision();
   EXPECT_EQ(Get_Board_Revision(), BOARD_REV_A0) << "Board_Revision should be BOARD_REV_A0.";
}

/**
 *  @b Read_Board_Revision_Test
 *  @n
 *     Checks that Board_Revision remains unchanged when board_rev_count
 *     is outside all defined thresholds (no matching range found).
 *     This covers the for-loop natural-exit branch and the
 *     Is_Within_Limits false (true && false) branch.
 */
TEST_F(board_revision_UnitTestSuite, Read_Board_Revision_Test_OutOfRange)
{
   Get_Board_Rev_Cnt_fake.return_val = 65535U; /* Above all thresholds (max > 4096U) */
   Read_Board_Revision();
   /* Board_Revision must remain BOARD_REV_EDU as initialised in SetUp */
   EXPECT_EQ(Get_Board_Revision(), BOARD_REV_EDU) << "Board_Revision should remain unchanged when no threshold matched.";
}

/**
 *  @b Get_Board_Revision_Test
 *  @n
 *      Checks the return of board revision value
 */
TEST_F(board_revision_UnitTestSuite, Get_Board_Revision_Test)
{
   Get_Board_Revision();
   EXPECT_EQ(Board_Revision, BOARD_REV_EDU) << "Board_Revision value is returned incorrectly.";
}
