/**
 * @file Cdd_Cbk_unit_test.cc
 * @brief Unit tests for Cdd_Cbk.c
 */

#include <gtest/gtest.h>
extern "C"
{
#include "Cdd_Cbk_fakes.h"

   DEFINE_FFF_GLOBALS;

   // Function under test
   void Cdd_SoAdIfRxIndication(PduIdType RxPduId, const PduInfoType *PduInfoPtr);

   // External counters
   extern volatile uint32_t Veh_UDP_Stream_Rx_Cbk_counter;
   extern volatile uint32_t Cdd_SoAdIfRxIndication_counter;
   extern volatile uint32_t HIL_Cbk_Counter;
}

DEFINE_FAKE_VOID_FUNC(Udp_Rx_Callback, uint8_t *);

class CddCbkTest : public ::testing::Test
{
 protected:
   void SetUp() override
   {
      RESET_FAKE(Udp_Rx_Callback);
      FFF_RESET_HISTORY();
      Veh_UDP_Stream_Rx_Cbk_counter  = 0;
      Cdd_SoAdIfRxIndication_counter = 0;
      HIL_Cbk_Counter                = 0;
   }
};

TEST_F(CddCbkTest, VehUdpStreamRx_IncrementsCounters)
{
   uint8_t test_data[]  = {0x01, 0x02, 0x03};
   PduInfoType pdu_info = {test_data, sizeof(test_data)};

   Cdd_SoAdIfRxIndication(CddConf_CddSoAdUpperLayerRxPdu_RDR_Veh_UDP_Stream_Rx, &pdu_info);

   EXPECT_EQ(Cdd_SoAdIfRxIndication_counter, 1);
   EXPECT_EQ(Veh_UDP_Stream_Rx_Cbk_counter, 1);
   EXPECT_EQ(Udp_Rx_Callback_fake.call_count, 1);
}

TEST_F(CddCbkTest, VehUdpStreamRx_CallsUdpRxCallback)
{
   uint8_t test_data[]  = {0xAA, 0xBB, 0xCC};
   PduInfoType pdu_info = {test_data, sizeof(test_data)};

   Cdd_SoAdIfRxIndication(CddConf_CddSoAdUpperLayerRxPdu_RDR_Veh_UDP_Stream_Rx, &pdu_info);

   EXPECT_EQ(Udp_Rx_Callback_fake.arg0_val, test_data);
}

TEST_F(CddCbkTest, HilReqRx_IncrementsHilCounter)
{
   uint8_t test_data[]  = {0x01};
   PduInfoType pdu_info = {test_data, sizeof(test_data)};

   Cdd_SoAdIfRxIndication(CddConf_CddSoAdUpperLayerRxPdu_RDR_HIL_Req_RX, &pdu_info);

   EXPECT_EQ(Cdd_SoAdIfRxIndication_counter, 1);
   EXPECT_EQ(HIL_Cbk_Counter, 1);
   EXPECT_EQ(Veh_UDP_Stream_Rx_Cbk_counter, 0);
}

TEST_F(CddCbkTest, HilReqRx_DoesNotCallUdpCallback)
{
   uint8_t test_data[]  = {0x01};
   PduInfoType pdu_info = {test_data, sizeof(test_data)};

   Cdd_SoAdIfRxIndication(CddConf_CddSoAdUpperLayerRxPdu_RDR_HIL_Req_RX, &pdu_info);

   EXPECT_EQ(Udp_Rx_Callback_fake.call_count, 0);
}

TEST_F(CddCbkTest, UnknownPduId_NoCounterIncrement)
{
   uint8_t test_data[]  = {0x01};
   PduInfoType pdu_info = {test_data, sizeof(test_data)};

   Cdd_SoAdIfRxIndication(999, &pdu_info);

   EXPECT_EQ(Cdd_SoAdIfRxIndication_counter, 1);
   EXPECT_EQ(Veh_UDP_Stream_Rx_Cbk_counter, 0);
   EXPECT_EQ(HIL_Cbk_Counter, 0);
}

TEST_F(CddCbkTest, MultipleVehCalls_CountersAccumulate)
{
   uint8_t test_data[]  = {0x01};
   PduInfoType pdu_info = {test_data, sizeof(test_data)};

   Cdd_SoAdIfRxIndication(CddConf_CddSoAdUpperLayerRxPdu_RDR_Veh_UDP_Stream_Rx, &pdu_info);
   Cdd_SoAdIfRxIndication(CddConf_CddSoAdUpperLayerRxPdu_RDR_Veh_UDP_Stream_Rx, &pdu_info);

   EXPECT_EQ(Cdd_SoAdIfRxIndication_counter, 2);
   EXPECT_EQ(Veh_UDP_Stream_Rx_Cbk_counter, 2);
}

TEST_F(CddCbkTest, MixedCalls_IndependentCounters)
{
   uint8_t test_data[]  = {0x01};
   PduInfoType pdu_info = {test_data, sizeof(test_data)};

   Cdd_SoAdIfRxIndication(CddConf_CddSoAdUpperLayerRxPdu_RDR_Veh_UDP_Stream_Rx, &pdu_info);
   Cdd_SoAdIfRxIndication(CddConf_CddSoAdUpperLayerRxPdu_RDR_HIL_Req_RX, &pdu_info);

   EXPECT_EQ(Cdd_SoAdIfRxIndication_counter, 2);
   EXPECT_EQ(Veh_UDP_Stream_Rx_Cbk_counter, 1);
   EXPECT_EQ(HIL_Cbk_Counter, 1);
}
