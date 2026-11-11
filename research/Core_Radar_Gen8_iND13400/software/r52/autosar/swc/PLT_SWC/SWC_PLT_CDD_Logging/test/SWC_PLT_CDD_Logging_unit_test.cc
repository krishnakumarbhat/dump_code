#include <gtest/gtest.h>

extern "C"
{
   void RE_Logging_10ms(void);
}

TEST(SWCPLTCDDLoggingUnitTest, Runnable10msExecutes)
{
   RE_Logging_10ms();
   SUCCEED();
}
