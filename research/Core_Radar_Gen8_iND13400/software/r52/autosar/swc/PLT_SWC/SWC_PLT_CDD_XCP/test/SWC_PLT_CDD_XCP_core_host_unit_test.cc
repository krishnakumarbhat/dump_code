#include <gtest/gtest.h>

extern "C"
{
   void RE_XCP_10ms(void);
   void RE_XCP_50ms(void);
   void RE_XCP_Init(void);

   void Test_Set_XCP_UserCommand_Received(unsigned char value);
   void Test_Set_XCP_Pending_Status(unsigned char value);
   void Test_Trigger_MM3_Fault_Injection(unsigned char fault_index, unsigned char injection_control);
   unsigned char Test_Get_Last_Fault_Handler_Id(void);
   unsigned char Test_Get_Last_Fault_Injection_Control(void);
   unsigned char Test_Get_Last_Fault_Failure_Type(void);
   unsigned char Test_Get_Last_Fault_Index(void);
}

TEST(SWCPLTCDDXcpCoreHostUnitTest, InitRunnableExecutes)
{
   RE_XCP_Init();
   SUCCEED();
}

TEST(SWCPLTCDDXcpCoreHostUnitTest, Runnable10msExecutesWithAndWithoutCommand)
{
   Test_Set_XCP_UserCommand_Received(0U);
   RE_XCP_10ms();

   Test_Set_XCP_UserCommand_Received(1U);
   RE_XCP_10ms();

   SUCCEED();
}

TEST(SWCPLTCDDXcpCoreHostUnitTest, Runnable50msExecutesWithAndWithoutPendingStatus)
{
   Test_Set_XCP_Pending_Status(0U);
   RE_XCP_50ms();

   Test_Set_XCP_Pending_Status(1U);
   RE_XCP_50ms();

   SUCCEED();
}

TEST(SWCPLTCDDXcpCoreHostUnitTest, Mm3PmicMcuCommunicationFaultUsesExpectedHandler)
{
   Test_Trigger_MM3_Fault_Injection(4U, 0x03U);

   EXPECT_EQ(4U, Test_Get_Last_Fault_Index());
   EXPECT_EQ(4U, Test_Get_Last_Fault_Handler_Id());
   EXPECT_EQ(0x03U, Test_Get_Last_Fault_Injection_Control());
   EXPECT_EQ(4U, Test_Get_Last_Fault_Failure_Type());
}
