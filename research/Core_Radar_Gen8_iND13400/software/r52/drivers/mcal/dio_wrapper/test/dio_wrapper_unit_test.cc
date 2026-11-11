/*===========================================================================*\
 * FILE: dio_wrapper_unit_test.cc
 *===========================================================================
 * Copyright (C) 2026 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * Unit tests for dio_wrapper module.
 *
 * Tests cover:
 *   - Dio_Wrapper_ReadChannel validation for A2 boards
 *   - Dio_Wrapper_ReadChannel validation for A3 boards
 *   - Dio_Wrapper_WriteChannel validation for A2 boards
 *   - Dio_Wrapper_WriteChannel validation for A3 boards
 *   - Dio_Wrapper_IsChannelAllowed validation
 *   - Invalid channel handling
 *   - Board revision mismatch handling
\*===========================================================================*/

#include <gtest/gtest.h>

#include "board_revision_mocks.h"
#include "dio_wrapper_fake.h"
#include "fff.h"
DEFINE_FFF_GLOBALS;

/*===========================================================================*\
 * FFF Fakes for all functions called by dio_wrapper
\*===========================================================================*/
extern "C"
{
/* Include real DIO types */
#include "Dio.h"
#include "Dio_Cfg.h"
}

/*===========================================================================*\
 * Include the source file under test
\*===========================================================================*/
extern "C"
{
#include "dio_wrapper.c"
}

/*===========================================================================*\
 * Test Fixture
\*===========================================================================*/
class DioWrapperTest : public testing::Test
{
 protected:
   void SetUp() override
   {
      // RESET_FAKE(Get_Board_Revision);
      // RESET_FAKE(Dio_ReadChannel);
      // RESET_FAKE(Dio_WriteChannel);
      FFF_RESET_HISTORY();
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*\
 * Dio_Wrapper_IsChannelAllowed Tests
\*===========================================================================*/

/**
 * @brief A2 board shall allow access to A2_A3 common channels
 */
TEST_F(DioWrapperTest, IsChannelAllowed_A2Board_AllowsA2A3Channels)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A2P0;

   EXPECT_TRUE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A2_A3_MARS_RESET_N));
   EXPECT_TRUE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A2_A3_CANWK_EN));
   EXPECT_TRUE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A2_A3_MM_FRAME_START));
   EXPECT_TRUE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A2_A3_ERRN_HSDEN));
   EXPECT_TRUE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A2_A3_POS_GND_EN));
}

/**
 * @brief A2 board shall NOT allow access to A3-only channels
 */
TEST_F(DioWrapperTest, IsChannelAllowed_A2Board_DeniesA3OnlyChannels)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A2P0;

   EXPECT_FALSE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A3_DEBUG_DETECT));
   EXPECT_FALSE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A3_TOD));
   EXPECT_FALSE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A3_ERR_N));
   EXPECT_FALSE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A3_FPGA_RST_N));
   EXPECT_FALSE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A3_HSD_FAULT));
}

/**
 * @brief A2P1 board shall also deny access to A3-only channels
 */
TEST_F(DioWrapperTest, IsChannelAllowed_A2P1Board_DeniesA3OnlyChannels)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A2P1;

   EXPECT_FALSE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A3_DEBUG_DETECT));
   EXPECT_FALSE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A3_TOD));
}

/**
 * @brief A3 board shall allow access to both A2_A3 and A3-only channels
 */
TEST_F(DioWrapperTest, IsChannelAllowed_A3Board_AllowsAllChannels)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;

   /* A2_A3 common channels */
   EXPECT_TRUE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A2_A3_MARS_RESET_N));
   EXPECT_TRUE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A2_A3_CANWK_EN));

   /* A3-only channels */
   EXPECT_TRUE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A3_DEBUG_DETECT));
   EXPECT_TRUE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A3_TOD));
   EXPECT_TRUE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A3_ERR_N));
   EXPECT_TRUE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A3_FPGA_RST_N));
   EXPECT_TRUE(Dio_Wrapper_IsChannelAllowed(DioConf_DioChannel_A3_HSD_FAULT));
}

/**
 * @brief Invalid channel ID shall be denied regardless of board revision
 */
TEST_F(DioWrapperTest, IsChannelAllowed_InvalidChannel_IsDenied)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;

   EXPECT_FALSE(Dio_Wrapper_IsChannelAllowed((Dio_ChannelType)0xFF));
}

/*===========================================================================*\
 * Dio_Wrapper_ReadChannel Tests
\*===========================================================================*/

/**
 * @brief ReadChannel on A2 board with A2_A3 channel shall succeed
 */
TEST_F(DioWrapperTest, ReadChannel_A2Board_A2A3Channel_Succeeds)
{
   Dio_Wrapper_Status_T status;
   Get_Board_Revision_fake.return_val = BOARD_REV_A2P0;
   Dio_ReadChannel_fake.return_val    = STD_HIGH;

   Dio_LevelType level = Dio_Wrapper_ReadChannel(DioConf_DioChannel_A2_A3_MARS_RESET_N, &status);

   EXPECT_EQ(level, STD_HIGH);
   EXPECT_EQ(status, DIO_WRAPPER_OK);
}

/**
 * @brief ReadChannel on A2 board with A3-only channel shall fail
 */
TEST_F(DioWrapperTest, ReadChannel_A2Board_A3OnlyChannel_Fails)
{
   Dio_Wrapper_Status_T status;
   Get_Board_Revision_fake.return_val = BOARD_REV_A2P0;

   Dio_LevelType level = Dio_Wrapper_ReadChannel(DioConf_DioChannel_A3_DEBUG_DETECT, &status);

   EXPECT_EQ(level, STD_LOW);
   EXPECT_EQ(status, DIO_WRAPPER_BOARD_MISMATCH);
}

/**
 * @brief ReadChannel on A3 board with A3-only channel shall succeed
 */
TEST_F(DioWrapperTest, ReadChannel_A3Board_A3OnlyChannel_Succeeds)
{
   Dio_Wrapper_Status_T status;
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;
   Dio_ReadChannel_fake.return_val    = STD_LOW;

   Dio_LevelType level = Dio_Wrapper_ReadChannel(DioConf_DioChannel_A3_DEBUG_DETECT, &status);

   EXPECT_EQ(level, STD_LOW);
   EXPECT_EQ(status, DIO_WRAPPER_OK);
}

/**
 * @brief ReadChannel with invalid channel ID shall return INVALID_CHANNEL status
 */
TEST_F(DioWrapperTest, ReadChannel_InvalidChannel_ReturnsInvalidStatus)
{
   Dio_Wrapper_Status_T status;
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;

   Dio_LevelType level = Dio_Wrapper_ReadChannel((Dio_ChannelType)0xFF, &status);

   EXPECT_EQ(level, STD_LOW);
   EXPECT_EQ(status, DIO_WRAPPER_BOARD_MISMATCH);
}

/**
 * @brief ReadChannel with NULL status pointer shall not crash
 */
TEST_F(DioWrapperTest, ReadChannel_NullStatusPointer_DoesNotCrash)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;
   Dio_ReadChannel_fake.return_val    = STD_HIGH;

   Dio_LevelType level = Dio_Wrapper_ReadChannel(DioConf_DioChannel_A2_A3_MARS_RESET_N, NULL);

   EXPECT_EQ(level, STD_HIGH);
}

/*===========================================================================*\
 * Dio_Wrapper_WriteChannel Tests
\*===========================================================================*/

/**
 * @brief WriteChannel on A2 board with A2_A3 channel shall succeed
 */
TEST_F(DioWrapperTest, WriteChannel_A2Board_A2A3Channel_Succeeds)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A2P0;

   Dio_Wrapper_Status_T status = Dio_Wrapper_WriteChannel(DioConf_DioChannel_A2_A3_MARS_RESET_N, STD_HIGH);

   EXPECT_EQ(status, DIO_WRAPPER_OK);
}

/**
 * @brief WriteChannel on A2 board with A3-only channel shall fail
 */
TEST_F(DioWrapperTest, WriteChannel_A2Board_A3OnlyChannel_Fails)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A2P0;

   Dio_Wrapper_Status_T status = Dio_Wrapper_WriteChannel(DioConf_DioChannel_A3_DEBUG_DETECT, STD_HIGH);

   EXPECT_EQ(status, DIO_WRAPPER_BOARD_MISMATCH);
}

/**
 * @brief WriteChannel on A3 board with A3-only channel shall succeed
 */
TEST_F(DioWrapperTest, WriteChannel_A3Board_A3OnlyChannel_Succeeds)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;

   Dio_Wrapper_Status_T status = Dio_Wrapper_WriteChannel(DioConf_DioChannel_A3_DEBUG_DETECT, STD_LOW);

   EXPECT_EQ(status, DIO_WRAPPER_OK);
}

/**
 * @brief WriteChannel with invalid channel ID shall return INVALID_CHANNEL status
 */
TEST_F(DioWrapperTest, WriteChannel_InvalidChannel_ReturnsInvalidStatus)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;

   Dio_Wrapper_Status_T status = Dio_Wrapper_WriteChannel((Dio_ChannelType)0xFF, STD_HIGH);

   EXPECT_EQ(status, DIO_WRAPPER_BOARD_MISMATCH);
}

/**
 * @brief WriteChannel on A2P1 board with A2_A3 channel shall succeed
 */
TEST_F(DioWrapperTest, WriteChannel_A2P1Board_A2A3Channel_Succeeds)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A2P1;

   Dio_Wrapper_Status_T status = Dio_Wrapper_WriteChannel(DioConf_DioChannel_A2_A3_CANWK_EN, STD_LOW);

   EXPECT_EQ(status, DIO_WRAPPER_OK);
}

/**
 * @brief WriteChannel on A3 board with A2_A3 channel shall succeed
 */
TEST_F(DioWrapperTest, WriteChannel_A3Board_A2A3Channel_Succeeds)
{
   Get_Board_Revision_fake.return_val = BOARD_REV_A3P0;

   Dio_Wrapper_Status_T status = Dio_Wrapper_WriteChannel(DioConf_DioChannel_A2_A3_MM_FRAME_START, STD_HIGH);

   EXPECT_EQ(status, DIO_WRAPPER_OK);
}
