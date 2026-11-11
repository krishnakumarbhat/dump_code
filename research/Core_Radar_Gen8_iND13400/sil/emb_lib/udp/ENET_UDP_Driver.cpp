/**********************************************************************************************
 * Includes
 **********************************************************************************************/
#include "ENET_UDP_Driver.h"
#include "Radar_SIL_Output_Data.h"
#include "sil_wrapper_common.h"
#include "stream_info.h"
#include <cstring>
/**********************************************************************************************
 * Constants and macros
 **********************************************************************************************/
#define PHY_WRITE        1
#define PHY_READ         2
#define ORIGIN_IP_INDEX  29
#define CRC_OFFSET       4
#define ONE_BYTE_SHIFT   8
#define TWO_BYTE_SHIFT   16
#define THREE_BYTE_SHIFT 24

/* Defines position of sourceTxCnt(MUDP) in Frame. */
#define HDR_TX_CNT_INDEX 44
/* Defines position of packetnumber(AUDI HDR) in Frame */
#define AUDI_HDR_PCK_NO_INDEX 66

#define PHY_PIN_STRAPPING_TIME_MICROSECONDS (2000)

/* Configure CDC frames to be 0xFF filled */
#define CDC_TX_FULL_FRAMES

#define CRC_XOR_VALUE         0xFFFFFFFF /* Used as Initial and Final XOR value. Chosen based on Autosar CRC spec */
#define NUM_ENET_TX_RX_BUFFER (250)      /*todo:output symbol to be changed to 150 once crash reloved from sil engine*/
#define NUM_UDP_RX_BUFFER     (10)       /*This macro defined only for UDP*/
#define MAX_NUM_UDP_RX_BUFFER (15)
/**********************************************************************************************
 * External objects
 **********************************************************************************************/
Stream_Rec_T frame = {0}; /* Actual Data Frame */
uint16_t ENET_Rx_ISR_Count;

uint32_t ENET_Tx_ISR_Count;
static uint8_t Buffer_ID_ETH_Rx;
static uint8_t XCP_DISCONNECT = false;
static uint8_t rad_pos;

static ENET_Frame_data_T ENET_frame_statistic = {0};

static uint32_t ENET_Frame_Count;
volatile uint8_t Number_of_CDC_frames_Tx_per_cycle;
volatile uint8_t Total_number_of_chunks_prev_cycle = 0xFF;
static uint8_t bd_idx                              = 0;
static uint8_t Tx_buffer_index                     = 0;
static uint8_t Target_PC_MAC_address[6];
static uint8_t Request_rcvd_from_Port[2];
static uint8_t ARP_DEST_ADD[6]              = {0};
static uint8_t ARP_data[ARP_PACKET_LENGTH]  = {0};
static uint8_t XCP_data[MAX_XCP_REQ_LENGTH] = {0};

static uint16_t frameLen    = 0;
static uint16_t UDP_Length  = 0;
static uint16_t IPV4_Length = 0;

static uint16_t Previous_Scan_Index = 0;
static uint8_t Prev_Exec_Counter    = 0;

static ENET_Frame_type_T Frame_Rx_count = {0};

uint8_t UNICAST_MODE_ON   = false;
uint8_t BROADCAST_MODE_ON = true;
uint8_t NUM_RXBDS;
uint8_t NUM_TXBDS;

static uint32_t entry_to_unicast   = 0;
static uint32_t entry_to_broadcast = 0;
static uint8_t UDP_BUFFER_INIT     = CODED_FALSE;

static volatile IPV4_UDP_Tx_Rx_Buffer_T *Tx_Buffer; /* Create transmission buffer. Size must be divisible over 16 */
static volatile IPV4_UDP_Tx_Rx_Buffer_T *Rx_Buffer; /* Create reception buffer. Size must be divisible over 16 */
static volatile Tx_Rx_eNBUF_T ENET_Tx_Rx_bd[NUM_ENET_TX_RX_BUFFER]; /* Create a Reception Buffer Descriptor */
static volatile IPV4_UDP_Tx_Rx_Buffer_T
   ENET_Tx_Rx_Buffer[NUM_ENET_TX_RX_BUFFER]; /* Create reception buffer. Size must be divisible over 16 */

static volatile Tx_Rx_eNBUF_T *txbd_buff; /* Create a Transmission Buffer Descriptor */
static volatile Tx_Rx_eNBUF_T *rxbd_buff; /* Create a Reception Buffer Descriptor */
/**********************************************************************************************
 * Local types
 **********************************************************************************************/
typedef union
{ /* MII Management Frame Register */
   vuint32_t R;
   struct
   {
      vuint32_t ST:2;    /* Start Of Frame Delimiter */
      vuint32_t OP:2;    /* Operation Code */
      vuint32_t PA:5;    /* PHY Address */
      vuint32_t RA:5;    /* Register Address */
      vuint32_t TA:2;    /* Turn Around */
      vuint32_t DATA:16; /* Management Frame Data */
   } B;
} ENET_MMFR_T;

/**********************************************************************************************
 * Local function prototypes
 *********************************************************************************************/
static uint32_t Calculate_CRC32(uint8_t *dataptr, uint32_t length);
uint8_t Get_Number_of_CDC_frames_Tx_per_cycle();
void Clear_Number_of_CDC_frames_Tx_per_cycle();
uint8_t Get_Number_of_CDC_frames_Tx_per_cycle();
uint8_t Get_Total_number_of_chunks_prev_cycle();

/**********************************************************************************************
 * Local variables
 **********************************************************************************************/
static volatile ENET_MMFR_T PHY_Data_Write;
static volatile ENET_MMFR_T PHY_Data_Read;

/* Autosar crc table duplicated for crc calculation */
static const uint32_t Crc_Table[256] = {
   0x00000000uL, 0x77073096uL, 0xEE0E612CuL, 0x990951BAuL, 0x076DC419uL, 0x706AF48FuL, 0xE963A535uL, 0x9E6495A3uL, 0x0EDB8832uL,
   0x79DCB8A4uL, 0xE0D5E91EuL, 0x97D2D988uL, 0x09B64C2BuL, 0x7EB17CBDuL, 0xE7B82D07uL, 0x90BF1D91uL, 0x1DB71064uL, 0x6AB020F2uL,
   0xF3B97148uL, 0x84BE41DEuL, 0x1ADAD47DuL, 0x6DDDE4EBuL, 0xF4D4B551uL, 0x83D385C7uL, 0x136C9856uL, 0x646BA8C0uL, 0xFD62F97AuL,
   0x8A65C9ECuL, 0x14015C4FuL, 0x63066CD9uL, 0xFA0F3D63uL, 0x8D080DF5uL, 0x3B6E20C8uL, 0x4C69105EuL, 0xD56041E4uL, 0xA2677172uL,
   0x3C03E4D1uL, 0x4B04D447uL, 0xD20D85FDuL, 0xA50AB56BuL, 0x35B5A8FAuL, 0x42B2986CuL, 0xDBBBC9D6uL, 0xACBCF940uL, 0x32D86CE3uL,
   0x45DF5C75uL, 0xDCD60DCFuL, 0xABD13D59uL, 0x26D930ACuL, 0x51DE003AuL, 0xC8D75180uL, 0xBFD06116uL, 0x21B4F4B5uL, 0x56B3C423uL,
   0xCFBA9599uL, 0xB8BDA50FuL, 0x2802B89EuL, 0x5F058808uL, 0xC60CD9B2uL, 0xB10BE924uL, 0x2F6F7C87uL, 0x58684C11uL, 0xC1611DABuL,
   0xB6662D3DuL, 0x76DC4190uL, 0x01DB7106uL, 0x98D220BCuL, 0xEFD5102AuL, 0x71B18589uL, 0x06B6B51FuL, 0x9FBFE4A5uL, 0xE8B8D433uL,
   0x7807C9A2uL, 0x0F00F934uL, 0x9609A88EuL, 0xE10E9818uL, 0x7F6A0DBBuL, 0x086D3D2DuL, 0x91646C97uL, 0xE6635C01uL, 0x6B6B51F4uL,
   0x1C6C6162uL, 0x856530D8uL, 0xF262004EuL, 0x6C0695EDuL, 0x1B01A57BuL, 0x8208F4C1uL, 0xF50FC457uL, 0x65B0D9C6uL, 0x12B7E950uL,
   0x8BBEB8EAuL, 0xFCB9887CuL, 0x62DD1DDFuL, 0x15DA2D49uL, 0x8CD37CF3uL, 0xFBD44C65uL, 0x4DB26158uL, 0x3AB551CEuL, 0xA3BC0074uL,
   0xD4BB30E2uL, 0x4ADFA541uL, 0x3DD895D7uL, 0xA4D1C46DuL, 0xD3D6F4FBuL, 0x4369E96AuL, 0x346ED9FCuL, 0xAD678846uL, 0xDA60B8D0uL,
   0x44042D73uL, 0x33031DE5uL, 0xAA0A4C5FuL, 0xDD0D7CC9uL, 0x5005713CuL, 0x270241AAuL, 0xBE0B1010uL, 0xC90C2086uL, 0x5768B525uL,
   0x206F85B3uL, 0xB966D409uL, 0xCE61E49FuL, 0x5EDEF90EuL, 0x29D9C998uL, 0xB0D09822uL, 0xC7D7A8B4uL, 0x59B33D17uL, 0x2EB40D81uL,
   0xB7BD5C3BuL, 0xC0BA6CADuL, 0xEDB88320uL, 0x9ABFB3B6uL, 0x03B6E20CuL, 0x74B1D29AuL, 0xEAD54739uL, 0x9DD277AFuL, 0x04DB2615uL,
   0x73DC1683uL, 0xE3630B12uL, 0x94643B84uL, 0x0D6D6A3EuL, 0x7A6A5AA8uL, 0xE40ECF0BuL, 0x9309FF9DuL, 0x0A00AE27uL, 0x7D079EB1uL,
   0xF00F9344uL, 0x8708A3D2uL, 0x1E01F268uL, 0x6906C2FEuL, 0xF762575DuL, 0x806567CBuL, 0x196C3671uL, 0x6E6B06E7uL, 0xFED41B76uL,
   0x89D32BE0uL, 0x10DA7A5AuL, 0x67DD4ACCuL, 0xF9B9DF6FuL, 0x8EBEEFF9uL, 0x17B7BE43uL, 0x60B08ED5uL, 0xD6D6A3E8uL, 0xA1D1937EuL,
   0x38D8C2C4uL, 0x4FDFF252uL, 0xD1BB67F1uL, 0xA6BC5767uL, 0x3FB506DDuL, 0x48B2364BuL, 0xD80D2BDAuL, 0xAF0A1B4CuL, 0x36034AF6uL,
   0x41047A60uL, 0xDF60EFC3uL, 0xA867DF55uL, 0x316E8EEFuL, 0x4669BE79uL, 0xCB61B38CuL, 0xBC66831AuL, 0x256FD2A0uL, 0x5268E236uL,
   0xCC0C7795uL, 0xBB0B4703uL, 0x220216B9uL, 0x5505262FuL, 0xC5BA3BBEuL, 0xB2BD0B28uL, 0x2BB45A92uL, 0x5CB36A04uL, 0xC2D7FFA7uL,
   0xB5D0CF31uL, 0x2CD99E8BuL, 0x5BDEAE1DuL, 0x9B64C2B0uL, 0xEC63F226uL, 0x756AA39CuL, 0x026D930AuL, 0x9C0906A9uL, 0xEB0E363FuL,
   0x72076785uL, 0x05005713uL, 0x95BF4A82uL, 0xE2B87A14uL, 0x7BB12BAEuL, 0x0CB61B38uL, 0x92D28E9BuL, 0xE5D5BE0DuL, 0x7CDCEFB7uL,
   0x0BDBDF21uL, 0x86D3D2D4uL, 0xF1D4E242uL, 0x68DDB3F8uL, 0x1FDA836EuL, 0x81BE16CDuL, 0xF6B9265BuL, 0x6FB077E1uL, 0x18B74777uL,
   0x88085AE6uL, 0xFF0F6A70uL, 0x66063BCAuL, 0x11010B5CuL, 0x8F659EFFuL, 0xF862AE69uL, 0x616BFFD3uL, 0x166CCF45uL, 0xA00AE278uL,
   0xD70DD2EEuL, 0x4E048354uL, 0x3903B3C2uL, 0xA7672661uL, 0xD06016F7uL, 0x4969474DuL, 0x3E6E77DBuL, 0xAED16A4AuL, 0xD9D65ADCuL,
   0x40DF0B66uL, 0x37D83BF0uL, 0xA9BCAE53uL, 0xDEBB9EC5uL, 0x47B2CF7FuL, 0x30B5FFE9uL, 0xBDBDF21CuL, 0xCABAC28AuL, 0x53B39330uL,
   0x24B4A3A6uL, 0xBAD03605uL, 0xCDD70693uL, 0x54DE5729uL, 0x23D967BFuL, 0xB3667A2EuL, 0xC4614AB8uL, 0x5D681B02uL, 0x2A6F2B94uL,
   0xB40BBE37uL, 0xC30C8EA1uL, 0x5A05DF1BuL, 0x2D02EF8DuL};

void Clear_ENET_buffers()
{
   /*Clearing Tx Rx buffer memory*/
   memset((uint8_t *)ENET_Tx_Rx_Buffer, (uint8_t)0, sizeof(ENET_Tx_Rx_Buffer));
   memset((uint8_t *)ENET_Tx_Rx_bd, (uint8_t)0, sizeof(ENET_Tx_Rx_bd));
}

void Initialize_Tx_Rx_Buffer_Size(Tx_Rx_Buffer_T Buffer_Mode)
{
   if ((Buffer_Mode == UDP_LOGGING_BUFFER) && (UDP_BUFFER_INIT == CODED_FALSE))
   {
      Clear_ENET_buffers();

      NUM_RXBDS = NUM_UDP_RX_BUFFER;
      /*Checking the number of Rx buffer greater than alloted then resetting value to defult*/
      if (NUM_RXBDS > MAX_NUM_UDP_RX_BUFFER)
      {
         NUM_RXBDS = MAX_NUM_UDP_RX_BUFFER;
      }

      NUM_TXBDS = NUM_ENET_TX_RX_BUFFER - NUM_RXBDS;
      /*Assigning pointers to Tx Rx  buffers based on the Number of Rxbuffer nad Txbuffer values*/
      Tx_Buffer = &ENET_Tx_Rx_Buffer[0];                                 /*Sttting Tx buffer starting address*/
      Rx_Buffer = &ENET_Tx_Rx_Buffer[NUM_ENET_TX_RX_BUFFER - NUM_RXBDS]; /*Setting Rx buffer starting address*/
      txbd_buff = &ENET_Tx_Rx_bd[0];
      rxbd_buff = &ENET_Tx_Rx_bd[NUM_ENET_TX_RX_BUFFER - NUM_RXBDS];
      /*Once Initialization completed set UDP_BUFFER_INIT*/
      Clear_ENET_buffers();
      // Re_initialize_ENET_Buffer();
      UDP_BUFFER_INIT = CODED_TRUE;
   }
   else
   {
      /*Invalid Mode*/
   }
}

void Update_Data_Buffer_SIL(uint8_t *data_bfr)
{
   memcpy((uint8_t *)&frame, data_bfr, sizeof(frame));

   ((Stream_Rec_T *)data_bfr)->rec_hdr.versionInfo          = (frame.rec_hdr.versionInfo);
   ((Stream_Rec_T *)data_bfr)->rec_hdr.sourceTxCnt          = (frame.rec_hdr.sourceTxCnt);
   ((Stream_Rec_T *)data_bfr)->rec_hdr.sourceTxTime         = (frame.rec_hdr.sourceTxTime);
   ((Stream_Rec_T *)data_bfr)->rec_hdr.sourceInfo           = (frame.rec_hdr.sourceInfo);
   ((Stream_Rec_T *)data_bfr)->rec_hdr.streamVersion        = (frame.rec_hdr.streamVersion);
   ((Stream_Rec_T *)data_bfr)->rec_hdr.streamRefIndex       = (frame.rec_hdr.streamRefIndex);
   ((Stream_Rec_T *)data_bfr)->rec_hdr.streamDataLen        = (frame.rec_hdr.streamDataLen);
   ((Stream_Rec_T *)data_bfr)->rec_hdr.streamTxCnt          = (frame.rec_hdr.streamTxCnt);
   ((Stream_Rec_T *)data_bfr)->rec_hdr.streamNumber         = (frame.rec_hdr.streamNumber);
   ((Stream_Rec_T *)data_bfr)->rec_hdr.streamChunksPerCycle = (frame.rec_hdr.streamChunksPerCycle);
   ((Stream_Rec_T *)data_bfr)->rec_hdr.streamChunks         = (frame.rec_hdr.streamChunks);
   ((Stream_Rec_T *)data_bfr)->rec_hdr.streamChunkIdx       = (frame.rec_hdr.streamChunkIdx);
   ((Stream_Rec_T *)data_bfr)->rec_hdr.reserved             = (frame.rec_hdr.reserved);
   ((Stream_Rec_T *)data_bfr)->rec_hdr.sensorId             = (frame.rec_hdr.sensorId);
}

volatile IPV4_UDP_Tx_Rx_Buffer_T *Get_Tx_Buffer_ptr()
{
   return (&Tx_Buffer[0]);
}

volatile IPV4_UDP_Tx_Rx_Buffer_T *Get_Rx_Buffer_ptr()
{
   return (&Rx_Buffer[0]);
}

volatile Tx_Rx_eNBUF_T *Get_txbd_ptr()
{
   return (&txbd_buff[0]);
}

volatile Tx_Rx_eNBUF_T *Get_rxbd_ptr()
{
   return (&rxbd_buff[0]);
}

uint8_t ENET_UDP_Driver_FrameTX(uint8_t *dataBuffer, uint16_t len)
{
   uint16_t i;
   uint16_t frameLen                       = len + CRC_OFFSET; /* CRC added here is not MAC CRC */
   uint16_t UDP_Length                     = UDP_HEADER_SIZE + len + CRC_OFFSET;
   uint16_t IPV4_Length                    = IPV4_HEADER_SIZE + UDP_HEADER_SIZE + len + CRC_OFFSET;
   uint8_t frame_sent                      = 0;
   uint32_t crc                            = 0;
   unsigned int loop                       = 0;
   uint16_t Current_Scan_Index             = Get_Current_Scan_Index();
   uint8_t Execution_Counter               = Get_Current_Exec_Counter();
   SIL_RADAR_Output_Data_T *Output_Str_Ptr = Get_Sil_Radar_Output_Data_Ptr();
   /* UDP Logging is scheduled to follow Core1 execution where CDC UDP
    * is processed. In case that the timing overruns, suppress CDC ISR's
    * while accessing the Ethernet buffers.
    */

   volatile IPV4_UDP_Tx_Rx_Buffer_T *TxBuffer = Get_Tx_Buffer_ptr();
   volatile Tx_Rx_eNBUF_T *txbd               = Get_txbd_ptr();

   if ((TxBuffer == NULL) || (txbd == NULL) || (Output_Str_Ptr == NULL))
   {
      return frame_sent;
   }

   Update_Data_Buffer_SIL(dataBuffer);

   // Transmit a frame if there is an available buffer (this buffer was selected
   // by the previous transmit).  If the buffer is ready it hasn't transmitted yet.
   if ((Current_Scan_Index != 0) || (Execution_Counter != 0))
   {
      if (Execution_Counter != Prev_Exec_Counter) // This Logic has been added for Sending the Scan Index Data to DVSU Writer
      {
         if ((bd_idx > 0) && (!Output_Str_Ptr->f_dvsu_buff_valid))
         {
            memcpy((unsigned char *)&Output_Str_Ptr->Tx_Buff[0], (unsigned char *)TxBuffer[0].Buf_Bytes,
                   sizeof(TxBuffer[0].Buf_Bytes));
            for (loop = 0; loop < bd_idx; loop++)
            {
               memcpy((unsigned char *)&Output_Str_Ptr->Tx_Buff[loop], (unsigned char *)TxBuffer[loop].Buf_Bytes,
                      sizeof(TxBuffer[loop].Buf_Bytes));
            }
            Output_Str_Ptr->Buff_Len          = bd_idx;
            Output_Str_Ptr->f_dvsu_buff_valid = 1;
            frame_sent                        = 0;
         }
         memset((unsigned char *)&TxBuffer[0], 0, sizeof(ENET_Tx_Rx_Buffer));
#ifndef CUSTOMER_SCANIA
         memset((unsigned char *)&txbd[0], 0, sizeof(ENET_Tx_Rx_bd));
#endif
         bd_idx = 0;

         Prev_Exec_Counter = Execution_Counter;

         if (bd_idx >= NUM_TXBDS)
         {
            return frame_sent;
         }

         if ((uint32_t)len + CRC_OFFSET > sizeof(TxBuffer[bd_idx].Buf_Bytes))
         {
            return frame_sent;
         }

         for (i = 0; i < len; i++)
         {
            TxBuffer[bd_idx].Buf_Bytes[i] = (uint8_t) * (dataBuffer + i);
         }

         crc                             = Calculate_CRC32((uint8_t *)&(TxBuffer[bd_idx].Buf_Bytes[0]), len);
         i                               = len;
         TxBuffer[bd_idx].Buf_Bytes[i++] = (uint8_t)((crc >> THREE_BYTE_SHIFT) & 0xFF);
         TxBuffer[bd_idx].Buf_Bytes[i++] = (uint8_t)((crc >> TWO_BYTE_SHIFT) & 0xFF);
         TxBuffer[bd_idx].Buf_Bytes[i++] = (uint8_t)((crc >> ONE_BYTE_SHIFT) & 0xFF);
         TxBuffer[bd_idx].Buf_Bytes[i++] = (uint8_t)(crc & 0xFF);

         ENET_Frame_Count++;

         // txbd[bd_idx].length = frameLen;

         bd_idx++;
      }
      else
      {
         /* Copy the payload of this frame */

         if (bd_idx >= NUM_TXBDS)
         {
            return frame_sent;
         }

         if ((uint32_t)len + CRC_OFFSET > sizeof(TxBuffer[bd_idx].Buf_Bytes))
         {
            return frame_sent;
         }

         for (i = 0; i < len; i++)
         {
            TxBuffer[bd_idx].Buf_Bytes[i] = (uint8_t) * (dataBuffer + i);
         }

         ENET_Frame_Count++;

         /* Populate CRC to the last 4 bytes */
         crc                             = Calculate_CRC32((uint8_t *)&(TxBuffer[bd_idx].Buf_Bytes[0]), len);
         i                               = len;
         TxBuffer[bd_idx].Buf_Bytes[i++] = (uint8_t)((crc >> THREE_BYTE_SHIFT) & 0xFF);
         TxBuffer[bd_idx].Buf_Bytes[i++] = (uint8_t)((crc >> TWO_BYTE_SHIFT) & 0xFF);
         TxBuffer[bd_idx].Buf_Bytes[i++] = (uint8_t)((crc >> ONE_BYTE_SHIFT) & 0xFF);
         TxBuffer[bd_idx].Buf_Bytes[i++] = (uint8_t)(crc & 0xFF);

         // txbd[bd_idx].length = frameLen;
         bd_idx++; // Next frame will be processed on the next buffer descriptor
         frame_sent = 0;
      }
   }

   return (frame_sent);
}

/*****************************************************************************
 *. Name: Calculate_CRC32
 *. This function calculates CRC32 - method defined by AUTOSAR
 *.
 *. Parameters: Data(uint8) and Length(uint32)
 *.
 *. Return Value: uint32_t.
 *.
 *. Shared Variables: None.
 *.
 *. SCR Information:
 *. 26354
 ******************************************************************************/
static uint32_t Calculate_CRC32(uint8_t *dataptr, uint32_t length)
{
   /* Initial Value */
   uint32_t CrcValue_u32 = CRC_XOR_VALUE;
   while (length--)
   {
      CrcValue_u32 ^= 0xFFuL & (uint32_t)(*(dataptr++));
      CrcValue_u32 = (CrcValue_u32 >> 8) ^ (Crc_Table[(uint8_t)(CrcValue_u32)]);
   }
   return CRC_XOR_VALUE ^ CrcValue_u32;
}

ENET_Frame_data_T *Get_ENET_logging_error_ptr()
{
   return &ENET_frame_statistic;
}
/**
 * FUNCTION:Get_Number_of_CDC_frames_Tx_per_cycle
 *   This function gets the value of Number of CDC frames transmitted per CDC cycle
 * \param[in]      void
 *
 * \return         none
 *
 * \remark         kok_css2#39340
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 * \reqtrace{ADASCORE-SDD-udplogging-6-1}{ADASCORE-SWS-udplogging-2-1}
 * \\input{Update_ARM_ISR_Latency_Timing}
 */

uint8_t Get_ENET_MODE()
{
   uint8_t Enet_Mode_loc = 0XCC;
   if (CODED_TRUE == UNICAST_MODE_ON)
   {
      Enet_Mode_loc = 0XAA;
   }
   if (CODED_TRUE == BROADCAST_MODE_ON)
   {
      Enet_Mode_loc = 0XBB;
   }
   return Enet_Mode_loc;
}
uint8_t Get_Number_of_CDC_frames_Tx_per_cycle()
{
}

void Clear_Number_of_CDC_frames_Tx_per_cycle()
{
   // Number_of_CDC_frames_Tx_per_cycle = 0;
}
uint8_t Get_Total_number_of_chunks_prev_cycle()
{
   // return Total_number_of_chunks_prev_cycle;
}
/*===========================================================================*\
 * FUNCTION: Set_Data_logging_mode
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * ENET_MODE_T Mode
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 *This function will Set_Data_logging_mode
\*===========================================================================*/
//****************************************************************************
uint8_t Update_bd_idx_value_to_header()
{
   return Tx_buffer_index;
}
