#include <gtest/gtest.h>

extern "C"
{
#include "SWC_PLT_CDD_XCP.h"
#include "Xcp.h"
#include "dsp_setup.h"
#include "ipc_mss.h"

   void Test_Set_Xcp_Session_Status(uint16 status);

   uint8 Xcp_Connect_Status(void);
   uint8 SWC_Xcp_RAM_Memorycheck(Xcp_AddressPtrType *addr, uint8 size);
   uint8 SWC_Xcp_Ipc_Memorycheck(Xcp_AddressPtrType *addr, uint8 size);
   uint8 SWC_Xcp_RAM_Memorycheck_Write(Xcp_AddressPtrType *addr, uint8 size);
}

TEST(SWCPLTCDDXcpLoggingUnitTest, ConnectStatusReturnsTrueWhenConnected)
{
   Test_Set_Xcp_Session_Status(XCP_SESSION_CONNECTED);

   EXPECT_EQ(Xcp_Connect_Status(), CODED_TRUE);
}

TEST(SWCPLTCDDXcpLoggingUnitTest, ConnectStatusReturnsFalseWhenDisconnected)
{
   Test_Set_Xcp_Session_Status(0U);

   EXPECT_EQ(Xcp_Connect_Status(), CODED_FALSE);
}

TEST(SWCPLTCDDXcpLoggingUnitTest, RamMemoryCheckAcceptsValidRange)
{
   Xcp_AddressPtrType address = R52TCM_ADDR_START + 0x10U;

   EXPECT_EQ(SWC_Xcp_RAM_Memorycheck(&address, 16U), XCP_CMD_OK);
}

TEST(SWCPLTCDDXcpLoggingUnitTest, RamMemoryCheckRejectsInvalidRange)
{
   Xcp_AddressPtrType address = 0x70000000U;

   EXPECT_EQ(SWC_Xcp_RAM_Memorycheck(&address, 16U), XCP_CMD_DENIED);
}

TEST(SWCPLTCDDXcpLoggingUnitTest, IpcMemoryCheckAdjustsAddressInPingRange)
{
   IPC_Dopp_RDD_Comp_Buf_Read_idx = 3U;
   Xcp_AddressPtrType address     = Get_D2M_Ping_Buf_Addr() + 0x20U;
   Xcp_AddressPtrType original    = address;

   EXPECT_EQ(SWC_Xcp_Ipc_Memorycheck(&address, 4U), XCP_CMD_OK);
   EXPECT_EQ(address, static_cast<Xcp_AddressPtrType>(original + (sizeof(D2M_Msg_T) * Get_IPC_Dopp_RDD_Comp_Buf_Read_Idx())));
}

TEST(SWCPLTCDDXcpLoggingUnitTest, IpcMemoryCheckDoesNotAdjustOutsidePingRange)
{
   IPC_Dopp_RDD_Comp_Buf_Read_idx = 2U;
   Xcp_AddressPtrType address     = Get_D2M_Pong_Buf_Addr() + 0x10U;
   Xcp_AddressPtrType original    = address;

   EXPECT_EQ(SWC_Xcp_Ipc_Memorycheck(&address, 8U), XCP_CMD_OK);
   EXPECT_EQ(address, original);
}

/* -- Missing branch: address < Ping_Buf_Addr → first condition (A) is false → no adjustment --
 * Covers the short-circuit A=false path of (address >= Ping_Buf_Addr) && (...) */
TEST(SWCPLTCDDXcpLoggingUnitTest, IpcMemoryCheckNoAdjustWhenAddressBeforePingBuffer)
{
   IPC_Dopp_RDD_Comp_Buf_Read_idx = 1U;
   Xcp_AddressPtrType address     = Get_D2M_Ping_Buf_Addr() - 0x10U;
   Xcp_AddressPtrType original    = address;

   EXPECT_EQ(SWC_Xcp_Ipc_Memorycheck(&address, 4U), XCP_CMD_OK);
   EXPECT_EQ(address, original); /* address must not be modified */
}

/* -- Missing branch: start_addr inside a region but end_addr overflows the boundary → DENIED --
 * Covers A=true, B=false path of (start_addr >= region.start) && (end_addr < region.end):
 * start is inside R52TCM (A=true) but end spills past R52TCM_ADDR_END (B=false). */
TEST(SWCPLTCDDXcpLoggingUnitTest, RamMemoryCheckDeniedWhenEndOverflowsRegionBoundary)
{
   /* 0x7FFFFFFE is inside R52TCM [0x7FFE0000, 0x80000000) */
   /* size=10 → end=0x80000008 which is >= R52TCM_ADDR_END(0x80000000) → B=false */
   /* remaining regions all have start_addr > 0x7FFFFFFE → A=false → no match */
   Xcp_AddressPtrType address = R52TCM_ADDR_END - 2U;
   EXPECT_EQ(SWC_Xcp_RAM_Memorycheck(&address, 10U), XCP_CMD_DENIED);
}

/* -- Valid access to each of the five memory regions (ensures every region hit path is covered) -- */

TEST(SWCPLTCDDXcpLoggingUnitTest, RamMemoryCheckAcceptsSysmem0Range)
{
   Xcp_AddressPtrType address = SYSMEM0_DATA_START + 0x10U;
   EXPECT_EQ(SWC_Xcp_RAM_Memorycheck(&address, 16U), XCP_CMD_OK);
}

TEST(SWCPLTCDDXcpLoggingUnitTest, RamMemoryCheckAcceptsSysmem1Range)
{
   Xcp_AddressPtrType address = SYSMEM1_ADDR_START + 0x10U;
   EXPECT_EQ(SWC_Xcp_RAM_Memorycheck(&address, 16U), XCP_CMD_OK);
}

TEST(SWCPLTCDDXcpLoggingUnitTest, RamMemoryCheckAcceptsBbe32DramRange)
{
   Xcp_AddressPtrType address = BBE32_DRAM_START + 0x10U;
   EXPECT_EQ(SWC_Xcp_RAM_Memorycheck(&address, 16U), XCP_CMD_OK);
}

TEST(SWCPLTCDDXcpLoggingUnitTest, RamMemoryCheckAcceptsArtieRange)
{
   Xcp_AddressPtrType address = ARTIE_ADDR_START + 0x10U;
   EXPECT_EQ(SWC_Xcp_RAM_Memorycheck(&address, 16U), XCP_CMD_OK);
}

/* -- Boundary: end_addr exactly equals region.end_addr → condition is strict (<), so DENIED -- */
TEST(SWCPLTCDDXcpLoggingUnitTest, RamMemoryCheckDeniedWhenEndEqualsRegionBoundary)
{
   /* end_addr = R52TCM_ADDR_END exactly → (end_addr < R52TCM_ADDR_END) is false → DENIED */
   Xcp_AddressPtrType address = R52TCM_ADDR_END - 4U;
   EXPECT_EQ(SWC_Xcp_RAM_Memorycheck(&address, 4U), XCP_CMD_DENIED);
}

TEST(SWCPLTCDDXcpLoggingUnitTest, WriteBoundaryCheck)
{
   /* end_addr = R52TCM_ADDR_END exactly → (end_addr < R52TCM_ADDR_END) is false → DENIED */
   Xcp_AddressPtrType address = R52TCM_ADDR_START;
   EXPECT_EQ(SWC_Xcp_RAM_Memorycheck_Write(&address, 4U), XCP_CMD_OK);
}

TEST(SWCPLTCDDXcpLoggingUnitTest, WriteBoundaryCheck_1)
{
   /* end_addr = R52TCM_ADDR_END exactly → (end_addr < R52TCM_ADDR_END) is false → DENIED */
   Xcp_AddressPtrType address = 0;
   EXPECT_EQ(SWC_Xcp_RAM_Memorycheck_Write(&address, 4U), XCP_CMD_DENIED);
}

TEST(SWCPLTCDDXcpLoggingUnitTest, WriteBoundaryCheck_2)
{
   /* end_addr = R52TCM_ADDR_END exactly → (end_addr < R52TCM_ADDR_END) is false → DENIED */
   Xcp_AddressPtrType address = R52TCM_ADDR_END - 4U;
   EXPECT_EQ(SWC_Xcp_RAM_Memorycheck_Write(&address, 3U), XCP_CMD_OK);
}
