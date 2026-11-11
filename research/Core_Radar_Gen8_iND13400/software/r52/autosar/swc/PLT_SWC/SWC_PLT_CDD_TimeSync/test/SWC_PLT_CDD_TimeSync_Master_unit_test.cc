/*===========================================================================*/
/**
 * @file SWC_PLT_CDD_TimeSync_Master_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for SWC_PLT_CDD_TimeSync_Master.
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
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 */
/*==========================================================================*/

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "SWC_PLT_CDD_TimeSync_Master_fake.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;

extern "C"
{
#include "../Source/SWC_PLT_CDD_TimeSync_Master.c"
}
uint8_t g_radar_position                                  = 1u;
unsigned g_StbM_GetTimeBaseStatus_calls                   = 0;
Std_ReturnType g_stbm_get_time_base_status_return_value   = 0; /* E_OK */
Std_ReturnType g_stbm_set_global_time_return_value        = 0; /* E_OK */
StbM_TimeBaseStatusType g_stbm_sync_time_base_status      = (StbM_TimeBaseStatusType)1u;
StbM_TimeBaseStatusType g_stbm_offset_time_base_status    = (StbM_TimeBaseStatusType)0u;
StbM_SynchronizedTimeBaseType g_last_set_global_time_base = (StbM_SynchronizedTimeBaseType)0;
StbM_TimeStampType g_last_set_global_time_stamp           = {0};
StbM_UserDataType g_last_set_global_time_user_data        = {0};
unsigned g_StbM_SetGlobalTime_calls                       = 0;

/* Stub for radar position selector */
uint8_t Get_Radar_Position(void)
{
   return g_radar_position;
}
Std_ReturnType StbM_GetTimeBaseStatus(StbM_SynchronizedTimeBaseType base, StbM_TimeBaseStatusType *syncStatus,
                                      StbM_TimeBaseStatusType *offsetStatus)
{
   (void)base;
   g_StbM_GetTimeBaseStatus_calls++;

   if (syncStatus != NULL)
   {
      *syncStatus = g_stbm_sync_time_base_status;
   }
   if (offsetStatus != NULL)
   {
      *offsetStatus = g_stbm_offset_time_base_status;
   }
   return g_stbm_get_time_base_status_return_value;
}
Std_ReturnType StbM_SetGlobalTime(StbM_SynchronizedTimeBaseType timeBaseId, const StbM_TimeStampType *timeStampPtr,
                                  const StbM_UserDataType *userDataPtr)
{
   g_StbM_SetGlobalTime_calls++;
   g_last_set_global_time_base = timeBaseId;
   if (timeStampPtr != NULL)
   {
      g_last_set_global_time_stamp = *timeStampPtr;
   }
   if (userDataPtr != NULL)
   {
      g_last_set_global_time_user_data = *userDataPtr;
   }
   return g_stbm_set_global_time_return_value;
}
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class swc_plt_cdd_timesync_master_UnitTestSuite : public ::testing::Test
{
   void SetUp() override
   {
      FFF_RESET_HISTORY();
      g_radar_position                         = 1u;
      g_StbM_GetTimeBaseStatus_calls           = 0u;
      g_stbm_get_time_base_status_return_value = 0u; /* E_OK */
      g_stbm_set_global_time_return_value      = 0u; /* E_OK */
      g_stbm_sync_time_base_status             = (StbM_TimeBaseStatusType)0u;
      g_stbm_offset_time_base_status           = (StbM_TimeBaseStatusType)0u;
      g_StbM_SetGlobalTime_calls               = 0u;
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/* Branch 1: radar position != 5 — function returns early, no StbM calls made */
TEST_F(swc_plt_cdd_timesync_master_UnitTestSuite, EcuSync_SeedCanTSynTimeBaseIfNeeded_NotRdr05_NoStbMCalls)
{
   g_radar_position = 1u;

   EcuSync_SeedCanTSynTimeBaseIfNeeded();

   EXPECT_EQ(0u, g_StbM_GetTimeBaseStatus_calls);
   EXPECT_EQ(0u, g_StbM_SetGlobalTime_calls);
}

/* Branch 2: radar position == 5, GetTimeBaseStatus fails — no seed issued */
TEST_F(swc_plt_cdd_timesync_master_UnitTestSuite, EcuSync_SeedCanTSynTimeBaseIfNeeded_Rdr05_GetTimeBaseStatusFails_NoSeed)
{
   g_radar_position                         = 5u;
   g_stbm_get_time_base_status_return_value = 1u; /* E_NOT_OK */

   EcuSync_SeedCanTSynTimeBaseIfNeeded();

   EXPECT_EQ(1u, g_StbM_GetTimeBaseStatus_calls);
   EXPECT_EQ(0u, g_StbM_SetGlobalTime_calls);
}

/* Branch 3: radar position == 5, status OK, Global Time Base bit already set — no seed */
TEST_F(swc_plt_cdd_timesync_master_UnitTestSuite, EcuSync_SeedCanTSynTimeBaseIfNeeded_Rdr05_GlobalTimeBitSet_NoSeed)
{
   g_radar_position                         = 5u;
   g_stbm_get_time_base_status_return_value = 0u;                             /* E_OK */
   g_stbm_sync_time_base_status             = (StbM_TimeBaseStatusType)0x08u; /* StbM_Global_Time_Base_BflMask */

   EcuSync_SeedCanTSynTimeBaseIfNeeded();

   EXPECT_EQ(1u, g_StbM_GetTimeBaseStatus_calls);
   EXPECT_EQ(0u, g_StbM_SetGlobalTime_calls);
}

/* Branch 4: radar position == 5, status OK, Global Time Base bit not set — SetGlobalTime called with zero timestamp */
TEST_F(swc_plt_cdd_timesync_master_UnitTestSuite, EcuSync_SeedCanTSynTimeBaseIfNeeded_Rdr05_GlobalTimeBitNotSet_Seeds)
{
   g_radar_position                         = 5u;
   g_stbm_get_time_base_status_return_value = 0u;                          /* E_OK */
   g_stbm_sync_time_base_status             = (StbM_TimeBaseStatusType)0u; /* bit not set */

   EcuSync_SeedCanTSynTimeBaseIfNeeded();

   EXPECT_EQ(1u, g_StbM_GetTimeBaseStatus_calls);
   EXPECT_EQ(1u, g_StbM_SetGlobalTime_calls);
   /* Verify the seed timestamp is zero-initialized */
   EXPECT_EQ(0u, g_last_set_global_time_stamp.nanoseconds);
   EXPECT_EQ(0u, g_last_set_global_time_stamp.seconds);
   EXPECT_EQ(0u, g_last_set_global_time_stamp.secondsHi);
}
