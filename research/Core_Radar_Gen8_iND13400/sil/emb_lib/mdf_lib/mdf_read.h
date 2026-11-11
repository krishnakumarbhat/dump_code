#ifndef MDF_READ_H
#define MDF_READ_H

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#undef _USE_ENUM_DEFS_
#undef _USE_ENUM_

#include "MDF4LibEnums.h"
#include "MdfUse.h" //Use only this header if you are using Error codes
#include "sil_wrapper_common.h"
// #include "genutil.h"

/*
#include "Backward.h"
#include "Byte_bit_Offset_Def.h"
#include "MDF4LibTypeDefs.h"
#include "MdfUse.h"
#include "ReferencePointer.h"
*/

// licence information for APTIV from Vector
#define MDF4LIB_CUSTOMER_NAME                                                                                                     \
   _T("Aptiv Services Deutschland GmbH tools 'SIL Tool', 'HIL Tool', 'Visualization Tool' and 'MDF2DVSU Tool'")
#define MDF4LIB_SERIAL_NUMBER _T("58716000011")
#define MDF4LIB_REG_KEY       _T("910D-06BF-5A0E-EEA7-F4FA-9F19-7682-4246")

#define MDF_VERSION           410                    // Version number of MDF.
#define UDP_PAYLOAD_SIZE      1472                   // Total number of bytes in a UDP payload: 1472 bytes = 11,776 bits.
#define METADATA_PAYLOAD_SIZE 4                      // total number of bytes in a metadata for video
#define ETH_MAX_DATA_SIZE     2000                   // Maximum buffer size of Ethernet data
#define CAN_PAYLOAD_SIZE      15                     // Total number of bytes in a CAN payload: 15 bytes = 120 bits.
#define ETH_PAYLOAD_SIZE      49                     // Total number of bytes in a Vigem_eth payload: 49 bytes = 272 bits.
#define VGM_CAN_PAYLOAD_SIZE  25                     // Total number of bytes in a Vigem_can payload:
#define CAN_MSG_DATA_BTYES    8                      // Maximum number of data bytes in a CAN message.
#define CANFD_MSG_DATA_BTYES  64                     // Maximum number of data bytes in a CANFD message.
#define CAN_EXT_ID_MASK       ((UINT32)(0x1FFFFFFF)) // CAN 29 bit mask
#define ORCAS_PAYLOAD_SIZE    49                     // ORCAS payload size is 32 bytes.
#define _MAX_BUFFER_SIZE      2000                   // Maximum buffer size to read databytes of a record.
#define IPV4_VER_LENGTH       0x45
#define VLAN_ETHER_TYPE       0x8100
#define IPV4_ETHER_TYPE       0x0800
#define PTP_ETHER_TYPE        0x88F7

#define ETH_PAYLOAD_SOMEIP_OFFSET (uint32_t)(28)
#define SOMEIP_OFFSET_POS         (uint32_t)(16) // someip offset value byte position in someip msg.
// moved to customer_ID_config.h file to solve confilts for dvsu and mf4
//#if !defined(DVSU_RECORD_Tag_Struct)
// const int MAX_MUDP_PACKET_SIZE = 1500;
//#define DVSU_RECORD_Tag_Struct
// typedef struct DVSU_RECORD_Tag{
//	unsigned int pcTime;                           // computer time (ms)
//	unsigned char payload[MAX_MUDP_PACKET_SIZE];     // UDP/IP data packet
// }DVSU_RECORD_T;
//#endif //DVSU_RECORD_Tag_Struct

#define strDELPHIRAWDATA _T("DelphiRawData") // Byte channel name for UDP
#define strRAWDATA       _T("RawData")       // Byte channel name for UDP
#define strCANDATAFRAME  _T("CAN_DataFrame") // Byte channel name for CAN
#define strORCASMF4FRAME _T("MF4Frame")      // Byte channel name for ORCAS mf4
#define strCANOEethFRAME _T("ETH_Frame")     // Byte channel name for ETH_Frame: CANoe mf4 log

#define strBUSCHANNEL        _T(".BusChannel")            // Child name
#define strFLAGS             _T(".Flags")                 // Child name
#define strDIR               _T(".Dir")                   // Child name
#define strEDL               _T(".EDL")                   // Child name
#define strBRS               _T(".BRS")                   // Child name
#define strSINGLEWIRE        _T(".SingleWire")            // Child name
#define strWAKEUP            _T(".WakeUp")                // Child name
#define strID                _T(".ID")                    // Child name
#define strIDE               _T(".IDE")                   // Child name
#define strDLC               _T(".DLC")                   // Child name
#define strDATALENGTH        _T(".DataLength")            // Child name
#define strDATABYTES         _T(".DataBytes")             // Child name
#define strDEST              _T(".Destination")           // Child name
#define strPROTOCOLTYPE      _T(".ProtocolType")          // Child name
#define strCYCLE             _T(".Cycle")                 // Child name
#define strSOURCE            _T(".Source")                // Child name
#define strETHERTYPE         _T(".EtherType")             // Child name
#define strRCVBYTECNT        _T(".ReceivedDataByteCount") // Child name
#define strCRC               _T(".CRC")                   // Child name
#define MAX_MUDP_PACKET_SIZE 1500
#ifdef _WIN32
   #define MAX_PATH_PLP 260
#elif __linux__
   #define MAX_PATH_PLP 4096
#endif

#if __linux__
   #define _MAX_EXT   256
   #define _MAX_DRIVE 3
   #define _MAX_DIR   4096
   #define _MAX_FNAME 256
   #define _MAX_PATH  4096
   #define MAX_PATH   4096
#endif

typedef struct CCA_EthProtocol_Info_TAG
{
   int64_t abs_timeStamp_ns;
   int64_t rel_timeStamp_ns;
   uint64_t dest_addr;
   uint64_t source_addr;
   uint32_t bus_SpecId;
   uint32_t canID;
   uint16_t ether_Type;
   uint16_t dataByteCount;
   uint8_t srcBusType;
   uint8_t dlc;
} CCA_EthProtocol_Info_T;
typedef struct DVSU_RECORD_Tag
{
   unsigned int pcTime;                         // computer time (ms)
   unsigned char payload[MAX_MUDP_PACKET_SIZE]; // UDP/IP data packet
} DVSU_RECORD_T;
typedef struct MF4_TimeStamp_Out_Tag
{
   unsigned int ScanIndex;           //!< scan cycle counter and increments on every radar processing cycle
   unsigned long long Mf4_TimeStamp; //!< [s] timestamp from mf4 file
} MF4_TimeStamp_Out_T;

typedef struct MDF4_Header_Info_TAG
{
   char *mf4_fileName;
   unsigned char MF4_Major_Version;
   unsigned char MF4_Minor_Version;
   unsigned char MF4_Release_Version;
   unsigned long long MF4_fileSize;
} MDF4_Header_Info_T;

typedef struct mdfCANchannel_TAG
{
   IChannelGroupPtr pCAN_ChGroup;
   IChannelPtr pCAN_TimeCh;
   IChannelPtr pCAN_ByteCh;
   IChannelPtr pCAN_BusChannel;
   IChannelPtr pCAN_Flags;
   IChannelPtr pCAN_Dir;
   IChannelPtr pCAN_EDL;
   IChannelPtr pCAN_BRS;
   IChannelPtr pCAN_SingleWire;
   IChannelPtr pCAN_WakeUp;
   IChannelPtr pCAN_ID;
   IChannelPtr pCAN_IDE;
   IChannelPtr pCAN_DLC;
   IChannelPtr pCAN_DataLength;
   IChannelPtr pCAN_DataBytes;
   IDataWriterPtr pCAN_DataWriter;
   UINT32 ch_number;
   INT32 vIndex;
   INT32 vFixID;
   INT32 mFixBusChannel;
   INT8 mFixDLC;
   INT8 mFixDataLength;
   INT8 vFixIDE;
   INT8 vFixEDL; //	EXTENDED DATA LENGTH to differentiate CAN FD and CAN: 1 => CAN FD, 0 => CAN.
   INT8 vFixBRS; //	BIT RATE SWITCH
} mdfCANchannel_T;

typedef std::vector<mdfCANchannel_T> vec_CAN;

typedef struct mdfUDPchannel_TAG
{
   IChannelGroupPtr pUDP_ChannelGroup;
   IDataPointerPtr pUDP_DataPointer;
   IChannelPtr pUDP_ByteChannel;
   UINT64 vNumberOfRec;
   INT32 vIndex;
} mdfUDPchannel_T;

typedef struct mdfETH_Frame_TAG
{
   IDataPointerPtr ETH_FrameDataPointer;
   IChannelGroupPtr ETH_FrameChGroup;
   IChannelPtr ETH_Frame_ByteCh;
   IChannelPtr ETH_FrameBus;
   IChannelPtr ETH_FrameSource;
   IChannelPtr ETH_FrameDest;
   IChannelPtr ETH_FrameDir;
   IChannelPtr ETH_FrameEtherType;
   IChannelPtr ETH_FrameDataLen;
   IChannelPtr ETH_FrameDataBytes;
   IChannelPtr ETH_FrameRcvDataByteCount;
   UINT64 vETH_NumberOfRec;
   UINT32 vETH_ch_number;
   INT32 vETH_Index;
   INT32 vETH_FixID;
   INT32 vETH_FixBusChannel;
   INT8 vETH_FixDataLength;
} mdfETH_Frame_T;

typedef std::vector<mdfETH_Frame_T> vec_ETH;

typedef struct mdfViGEM_Frame_TAG
{
   IDataPointerPtr mdfViGEM_FrameDataPointer;
   IChannelGroupPtr mdfViGEM_FrameChGroup;
   IDataWriterPtr mdfViGEM_FrameWriter;
   IDataWriterPtr mdfViGEM_CANFrameWriter;
   IChannelPtr mdfViGEM_FrameTimeCh;
   IChannelPtr mdfViGEM_FrameAsyncCh;
   IChannelPtr mdfViGEM_FrameCh;
   IChannelPtr mdfViGEM_BusChannel;
   IChannelPtr ETH_FrameSource;
   IChannelPtr ETH_FrameDest;
   IChannelPtr ETH_FrameDir;
   IChannelPtr ETH_FrameEtherType;
   IChannelPtr mdfViGEM_FrameDataLen;
   IChannelPtr mdfViGEM_CANFrameDataBytes;
   IChannelPtr mdfViGEM_FrameDataBytes;
   IChannelPtr ETH_FrameRcvDataByteCount;
   IChannelPtr mdfViGEM_FrameCRC;
   IChannelPtr pCAN_EDL;
   IChannelPtr pCAN_BRS;
   IChannelPtr pCAN_ID;
   IChannelPtr pCAN_IDE;
   IChannelPtr pCAN_DLC;
   UINT64 vNumberOfRec;
   INT32 vch_number;
   INT32 vCANch_number;
   INT32 vIndex;
   INT32 vFixID;
   INT32 vFixBusChannel;
   INT8 vFixDataLength;
   SourceBusTypeEnum vBusType; // to get bus type from Vigem channel e.g. CAN , CANFD, ETH..
   INT8 vFixDLC;
   INT8 vFixIDE;
   INT8 vFixEDL; //	EXTENDED DATA LENGTH to differentiate CAN FD and CAN: 1 => CAN FD, 0 => CAN.
   INT8 vFixBRS; //	BIT RATE SWITCH
} mdfViGEM_Frame_T;

typedef struct ViGEMEthSignals_TAG
{
   UINT32 vEThBusChannel; //	(for CAN, for another 0),
   UINT64 vEThSrc;
   UINT64 vEThDest;
   UINT16 vEThetherType;
   UINT32 vEThCRC;
   UINT32 vEThRcvdbyteCount;
   UINT32 vEThDataLength;        //
   unsigned char *pEthDataBytes; //	pointer to the data byte array
} ViGEMEthSignals_T;

typedef struct ViGEMCANSignals_TAG
{
   UINT32 vCANBusChannel; //	(for CAN, for another 0),
   UINT64 vCANID;
   UINT64 vFixIDE;
   UINT16 vFixDLC;
   UINT32 vFixEDL;
   UINT32 vFixBRS;
   UINT32 vEThCRC;
   unsigned char *pEthDataBytes; //	pointer to the data byte array
} ViGEMCANSignals_T;

typedef std::vector<mdfViGEM_Frame_T> vec_ViGEM;

enum ProtocolTypeEnum
{
   e_Bus_Unknown = 0x00 //!< Unknown protocol
      ,
   e_Bus_CAN = 0x01 //!< CAN protocol
      ,
   e_Bus_UDP = 0x02 //!< UDP protocol
      ,
   e_Bus_FlexRay = 0x03 //!< FxR protocol
      ,
   e_Bus_CANFD = 0x04 //!< CAN FD protocol
      ,
   e_Bus_Dynamic = 0xFF //!< This enum is to read any of the subsequent data record.
};
typedef struct OrcasMdfSignals_TAG
{
   INT8 BusChannel;               //	(for CAN, for another 0),
   INT32 ID;                      //
   INT8 DLC;                      //	(for now dataLenght),
   INT64 Destination;             //	(for now 0),
   INT32 DataLength;              //
   INT32 Cycle;                   //	(for FlexRay, for another 0),
   ProtocolTypeEnum ProtocolType; //	(unknown = 0, CAN = 1, UDP = 2, FlexRay = 3, CAN = 4)
   unsigned char *pDataBytes;     //	pointer to the data byte array
   INT64 TimeStamp;               //	8 byte timestamp.
} OrcasMdfSignals_T;

class mdf_file_handler
{
 public:
   mdf_file_handler();
   mdf_file_handler(const char *mdf4LibDllPath);
   void Initialise();
   virtual ~mdf_file_handler();
   virtual ErrorCode OpenCANmdfFile(const char *FileName);
   virtual ErrorCode OpenUDPmdfFile(const char *FileName,
                                    bool allow_MultiThreading); // this flag is added to handle HIL multithreaded application
   virtual ErrorCode OpenORCASmdfFile(const char *FileName, bool allow_MultiThreading);
   virtual ErrorCode OpenVIGEMmdfFile(const char *FileName, UINT64 *StartTimeStamp, bool allow_MultiThreading,
                                      unsigned int radar_pos = 0,
                                      UINT8 *logType         = 0); // this flag is added to handle HIL multithreaded application
   virtual ErrorCode CreateUDPmdfFile(const char *FileName);
   virtual ErrorCode CreateCANmdfFile(const char *FileName);
   virtual ErrorCode CreateORCASmdfFile(const char *FileName);
   virtual ErrorCode CreateVigemmdfFile(const char *FileName);
   // virtual ErrorCode write_MDF(const dvlMessageUnion* pDVLmsg,UINT32 * Buschannel);
   // virtual ErrorCode write_OrcasMDFsignal(const DVSU_RECORD_T* pUdpRec, UINT64 TimeStamp_ns);
   // virtual ErrorCode write_OrcasMDFsignal(const dvlMessageUnion* pDVLmsg);
   virtual ErrorCode write_VigemMDFsignal(const DVSU_RECORD_T *pUdpRec, UINT64 TimeStamp_ns);
   virtual ErrorCode write_VigemMDFsignal(const dvlMessageUnion *pDVLmsg);
   virtual ErrorCode rewindCAN_MDF(void);
   virtual ErrorCode rewindUDP_MDF(void);
   virtual ErrorCode rewindORCAS_MDF(void);
   virtual ErrorCode rewindViGEM_MDF(void);
   virtual ErrorCode read_MDF(dvlMessageUnion *pDVLmsg);
   virtual ErrorCode read_MDF(DVSU_RECORD_T *pUDPRec, UINT64 *pTimeStamp_ns);
   virtual ErrorCode read_OrcasMDF(OrcasMdfSignals_T *pOrcas_Mdf_Signal);
   virtual ErrorCode read_VigemMDF(void **pdata_ptr, INT64 *TimeStamp_ns, UINT32 *busType, UINT32 *Buschannel);
   virtual ErrorCode getMf4_Header_Info(const char *FileName, MDF4_Header_Info_T *pMdfInfo);
   virtual ErrorCode getMf4_ToolID(const char *FileName, UINT8 *setVigemmf4);
   ErrorCode readMDFrec(void **pdata_ptr, CCA_EthProtocol_Info_T *ProtocolRec);
   bool m_MdfLibValid_Flag;
   char m_file_path[MAX_PATH_PLP];
   ViGEMEthSignals_T m_ViGEMEthSignals;

 private:
   // VMdf4Lib* mdf4Lib;
   ErrorCode m_MdfErr;
   std::unique_ptr<VMdf4Lib> mdf4Lib;
   unsigned char m_Buffer[_MAX_BUFFER_SIZE];
   virtual ErrorCode write_OrcasMDF(const DVSU_RECORD_T *pUdpRec, UINT64 TimeStamp_ns);
   virtual ErrorCode write_OrcasMDF(const OrcasMdfSignals_T *pOrcasMdfSignal);
   ErrorCode CreateUDP_ChGroup();
   ErrorCode CreateCAN_ChGroup(const UINT32 channelNumber);
   ErrorCode CreateOrcas_ChGroup();
   ErrorCode CreateVigem_ChGroup(const UINT8 radarPos);
   ErrorCode CreateVigem_CANChGroup(const UINT32 channelNumber);
   ErrorCode ProcessViGEMETH_Frame(INT64 time, mdfViGEM_Frame_T &ETH_Frame, IGroupDataPointer *pGroupDataPointer,
                                   DVSU_RECORD_T *pUDPrec);
   ErrorCode ProcessViGEMCAN_Frame(INT64 time, mdfViGEM_Frame_T &ETH_Frame, IGroupDataPointer *pGroupDataPointer,
                                   dvlMessageUnion *pDVLCANmsg, UINT32 *Buschannel);
   int m_vecViGEM_Index;

 protected:
   IFileManagerPtr m_pFileManager;
   IFilePtr m_pFile_UDP;
   IFilePtr m_pFile_CAN;
   IFilePtr m_pFile_ORCAS;
   IFilePtr m_pFile_ViGEM;
   IGroupDataPointerPtr m_pCAN_GrpDataPtr;
   IGroupDataPointerPtr m_pETH_GrpDataPtr;
   IGroupDataPointerPtr m_pViGEM_GrpDataPtr;
   IChannelGroupPtr m_pUDP_ChannelGroup;
   IChannelPtr m_pUDP_TimeChannel;
   IChannelPtr m_pUDP_ByteChannel;
   IDataWriterPtr m_pUDPDataWriter;
   IFactoryPtr m_pFactoryPtrCAN;
   IFactoryPtr m_pFactoryPtrORCAS;
   IFactoryPtr m_pFactoryPtrVIGEM;
   ISourceInfoPtr m_pSrcInfoCAN;
   ISourceInfoPtr m_pSrcInfoOrcas;
   ISourceInfoPtr m_pSrcInfoVigem;
   ICommentPtr m_pCommentCAN;
   ICommentPtr m_pCommentVigem;
   vec_CAN m_vecCANObj;
   mdfUDPchannel_T m_udpCH;
   IChannelGroupPtr m_MF4FrameChGroup;
   IDataWriterPtr m_MF4FrameDataWriter;
   IDataPointerPtr m_MF4FrameDataPointer;
   IChannelPtr m_MF4Frame_ByteCh;
   IChannelPtr m_MF4Frame_TimeCh;
   IChannelPtr m_MF4FrameBus;
   IChannelPtr m_MF4FrameID;
   IChannelPtr m_MF4FrameDLC;
   IChannelPtr m_MF4FrameDest;
   IChannelPtr m_MF4FrameDataLen;
   IChannelPtr m_MF4FrameDataBytes;
   IChannelPtr m_MF4FrameProtocolType;
   IChannelPtr m_MF4FrameCycle;
   vec_ETH m_vecETHObj;
   vec_ViGEM m_vecViGEMObj;
   UINT64 mf4NumberOfRec;
   UINT64 m_startTime_ns;
   void ClearMembers();
};

#endif // MDF_READ_H
