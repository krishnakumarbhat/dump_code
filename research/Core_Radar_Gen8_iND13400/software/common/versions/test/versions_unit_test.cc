/*===========================================================================*/
/**
 * @file versions_unit_test.cc
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
 * Unit test suite for the checking the versions.c file
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

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
extern "C"
{
#include "versions.c"
#include "versions.h"
}

#define EXPECT_IN_RANGE(VAL, MIN, MAX)                                                                                            \
   EXPECT_GE((VAL), (MIN));                                                                                                       \
   EXPECT_LE((VAL), (MAX))

#define ASSERT_IN_RANGE(VAL, MIN, MAX)                                                                                            \
   ASSERT_GE((VAL), (MIN));                                                                                                       \
   ASSERT_LE((VAL), (MAX))

DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class VersionsUnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_RESET_HISTORY();
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

/**
 *  @b VersionsUnitTestAppCheck
 *  @n
 *      Test the application versions are valid.
 */
TEST_F(VersionsUnitTestSuite, VersionsUnitTestAppCheck)
{
   const Application_Version_T *app_version;
   app_version = Get_Application_Version();

   ASSERT_EQ(app_version->generation, 8U);
   ASSERT_IN_RANGE(app_version->variant, 0, 255);
   ASSERT_IN_RANGE(app_version->major, 0, 255);
   ASSERT_IN_RANGE(app_version->minor, 0, 255);
   ASSERT_IN_RANGE(app_version->patch, 0, 255);
}

/**
 *  @b VersionsUnitTestBootCheck
 *  @n
 *      Test the bootloader versions are valid.
 */
TEST_F(VersionsUnitTestSuite, VersionsUnitTestBootCheck)
{
   const Bootloader_Version_T *boot_version;
   boot_version = Get_Bootloader_Version();

   ASSERT_IN_RANGE(boot_version->major, 0, 255);
   ASSERT_IN_RANGE(boot_version->minor, 0, 255);
   ASSERT_IN_RANGE(boot_version->patch, 0, 255);
}
