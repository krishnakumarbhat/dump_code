#include <gtest/gtest.h>

extern "C"
{
   uint32_t XcpAppl_GetTimestamp(void);
   uint8_t XcpAppl_GetClockSyncState(void);
}

TEST(XcpApplCoreHostUnitTest, TimestampReturnsDeterministicValue)
{
   EXPECT_EQ(0u, XcpAppl_GetTimestamp());
}

TEST(XcpApplCoreHostUnitTest, ClockSyncStateReturnsExpectedFlags)
{
   EXPECT_EQ(static_cast<uint8_t>(0x11u), XcpAppl_GetClockSyncState());
}
