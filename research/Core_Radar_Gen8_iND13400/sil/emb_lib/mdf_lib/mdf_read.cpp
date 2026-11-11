#include <cstring>
#include <fstream>
#include <ios>
#include <stdlib.h>
#include <string.h>
#ifdef __linux__
   #include <libgen.h>
#endif
#include "Byte_bit_Offset_Def.h"
#include "mdf_read.h"

using namespace std;

#define _CRT_SECURE_NO_WARNINGS // Place before any includes

// filename.append(TO_STR(MDF4LIB_DLL_NAME));

unsigned long long GetFilesize(const char *file_name)
{
   unsigned long long fileSize = 0;
   std::string fileName;
   fileName = file_name;
   std::ifstream file(fileName.c_str(), ios::in | ios::binary);
   if (!file.is_open())
   {
      return fileSize;
   }
   file.seekg(0, ios::end);
   fileSize = file.tellg();
   file.close();
   return fileSize;
}
#ifdef _WIN32
void split_path(const char *Path, char *Drive, char *Directory, char *Filename, char *Extension)
{
   _splitpath_s(Path, Drive, _MAX_DRIVE, Directory, _MAX_DIR, Filename, _MAX_FNAME, Extension, _MAX_EXT);
}
#elif __linux__
void split_pathLinux(const char *Path, char **Drive, char **Directory, char **Filename, char **Extension)
{
   char *ts1 = strdup(Path);
   char *ts2 = strdup(Path);

   char *fullPath = dirname(ts1);
   strcat(fullPath, "/");
   char *filenameWithExt = basename(ts2);

   std::string directory_name(fullPath);
   std::size_t posDrive = directory_name.find('/', 1);

   std::string file_name(filenameWithExt);
   std::size_t found = file_name.find(".");

   char *driveName     = strdup(directory_name.substr(0, posDrive).c_str());
   char *directoryName = strdup(directory_name.substr(posDrive, directory_name.size()).c_str());
   char *fName         = strdup(file_name.substr(0, found).c_str());
   char *extName       = strdup(file_name.substr(found, file_name.size() - 1).c_str());

   strcpy(*Drive, driveName);
   strcpy(*Directory, directoryName);
   strcpy(*Filename, fName);
   strcpy(*Extension, extName);

   free(ts1);
   free(ts2);
   free(driveName);
   free(directoryName);
   free(fName);
   free(extName);
}
#endif

mdf_file_handler::mdf_file_handler()
{
   // ClearMembers();
   // m_MdfLibValid_Flag = true;
   // m_pFileManager = mdf4Lib.GetFileManager();

   // if (!m_pFileManager) {
   //	m_MdfLibValid_Flag = false;
   // }
   // else{
   //	if (m_pFileManager->GetLicenseLevel() < eWriteLicense) {
   //		m_MdfLibValid_Flag = false;
   //	}
   // }
   // m_pSrcInfoCAN = nullptr;
}

void mdf_file_handler::Initialise()
{
   ClearMembers();
   m_MdfLibValid_Flag = true;
   m_vecViGEM_Index   = 0;
   mdf4Lib            = std::unique_ptr<VMdf4Lib>(new VMdf4Lib(MDF4LIB_CUSTOMER_NAME, MDF4LIB_SERIAL_NUMBER, MDF4LIB_REG_KEY));
   m_pFileManager     = mdf4Lib->GetFileManager();

   if (!m_pFileManager)
   {
      m_MdfLibValid_Flag = false;
   }
   else
   {
      if (m_pFileManager->GetLicenseLevel() < eWriteLicense)
      {
         m_MdfLibValid_Flag = false;
      }
   }
   m_pSrcInfoCAN = nullptr;
}

mdf_file_handler::mdf_file_handler(const char *mdf4LibDllPath)
{
   ClearMembers();
   m_MdfLibValid_Flag = true;

   std::string filename;

#ifdef _WIN32
   if (strcmp(mdf4LibDllPath, "Default") == 0)
   {
      filename = "./";
      filename.append(MDF4LIB_DLL_NAME);
   }
   else
   {
      filename = mdf4LibDllPath;
      filename.append("/");
      filename.append(MDF4LIB_DLL_NAME);
   }
#elif __linux__
   if (strcmp(mdf4LibDllPath, "Default") == 0)
   {
      filename = "./";
      filename.append(MDF4LIB_DLL_NAME);
   }
   else
   {
      filename = mdf4LibDllPath;
      filename.append("/");
      filename.append(MDF4LIB_DLL_NAME);
   }
#endif
   // VMdf4Lib mdf4Lib(MDF4LIB_CUSTOMER_NAME, MDF4LIB_SERIAL_NUMBER, MDF4LIB_REG_KEY, filename.c_str());
   mdf4Lib =
      std::unique_ptr<VMdf4Lib>(new VMdf4Lib(MDF4LIB_CUSTOMER_NAME, MDF4LIB_SERIAL_NUMBER, MDF4LIB_REG_KEY, filename.c_str()));
   m_pFileManager = mdf4Lib->GetFileManager();

   if (!m_pFileManager)
   {
      m_MdfLibValid_Flag = false;
   }
   else
   {
      if (m_pFileManager->GetLicenseLevel() < eWriteLicense)
      {
         m_MdfLibValid_Flag = false;
      }
   }
   m_pSrcInfoCAN = nullptr;
}
void mdf_file_handler::ClearMembers()
{
   m_MdfErr           = eOK;
   m_MdfLibValid_Flag = false;
   if (m_vecCANObj.size() > 0)
   {
      m_vecCANObj.clear();
   }
   memset(m_Buffer, 0x00, sizeof(m_Buffer));
   memset(&m_udpCH, 0x0, sizeof(mdfUDPchannel_T));
   mf4NumberOfRec    = 0;
   m_pETH_GrpDataPtr = NULL;
   m_pCAN_GrpDataPtr = NULL;
}
mdf_file_handler::~mdf_file_handler()
{
   ClearMembers();
}

static UINT16 ReverseTwoBytes(UINT16 value)
{
   unsigned char Byte0 = value & 0xff;
   unsigned char Byte1 = value >> 8;
   value               = Byte0 << 8 | Byte1;
   return value; // rounding, could be done better!
}

static INT32 ReadValue(IGroupDataPointer *pGroupDataPointer, IChannel *pChannel)
{
   INT64 v;
   ErrorCode mdfErr = pGroupDataPointer->ReadRawValueInt64(pChannel, &v);
   if (mdfErr != eOK)
   {
      return -1;
   }

   return (INT32)v;
}

static INT32 GetFixValue(IChannelPtr pChannel)
{
   if (!pChannel)
      return -1;
   if (pChannel->GetType() != eVirtualData)
      return -1;

   IConversionPtr pCC = pChannel->GetConversion();
   if (!pCC)
      return -1;
   if (pCC->GetType() != eLinear)
      return -1;
   if (pCC->GetParameterCount() != 2)
      return -1;
   if (pCC->GetParameterValue(1) != 0.0)
      return -1; // note: compare with float 0.0 is dangerous, should use epsilon!

   return (INT32)(pCC->GetParameterValue(0) + 0.5); // rounding, could be done better!
}

static ErrorCode WriteSignalValue(IDataWriterPtr pDataWtr, IChannel *pChannel, INT64 value)
{
   bool isValid     = true;
   ErrorCode mdfErr = pDataWtr->WriteRawValue(pChannel, value, isValid);
   if (mdfErr != eOK)
   {
      return -1;
   }

   return mdfErr;
}
static ErrorCode ProcessCanFrame(INT64 time, mdfCANchannel_T &canFrame, IGroupDataPointer *pGroupDataPointer,
                                 dvlMessageUnion *pDVLCANmsg)
{
   UINT32 ActualDataSize                               = 0;
   unsigned char CAN_DataBytes[CAN_MSG_DATA_BTYES]     = {0};
   unsigned char CANFD_DataBytes[CANFD_MSG_DATA_BTYES] = {0};
   dvlMessageUnion DVLCANmsg                           = {0};

   INT32 canId = canFrame.vFixID < 0 ? ReadValue(pGroupDataPointer, canFrame.pCAN_ID) : canFrame.vFixID;
   INT32 busChannel =
      canFrame.mFixBusChannel < 0 ? ReadValue(pGroupDataPointer, canFrame.pCAN_BusChannel) : canFrame.mFixBusChannel;
   UINT8 dlc = canFrame.mFixDLC < 0 ? ReadValue(pGroupDataPointer, canFrame.pCAN_DLC) : canFrame.mFixDLC;
   UINT8 DataLength =
      canFrame.mFixDataLength < 0 ? ReadValue(pGroupDataPointer, canFrame.pCAN_DataLength) : canFrame.mFixDataLength;
   INT8 IDEx        = canFrame.vFixIDE < 0 ? ReadValue(pGroupDataPointer, canFrame.pCAN_IDE) : canFrame.vFixIDE;
   INT8 b_canFD_EDL = false;
   INT8 b_canFD_BRS = false;

   if (canFrame.pCAN_EDL)
   {
      b_canFD_EDL = canFrame.vFixEDL < 0 ? ReadValue(pGroupDataPointer, canFrame.pCAN_EDL) : canFrame.vFixEDL;
   }
   if (canFrame.pCAN_BRS)
   {
      b_canFD_BRS = canFrame.vFixBRS < 0 ? ReadValue(pGroupDataPointer, canFrame.pCAN_BRS) : canFrame.vFixBRS;
   }

   DVLCANmsg.info.timestamp   = time;
   DVLCANmsg.info.messageSize = 0x000000000; // Need to check this. 17/Oct/2018

   if (b_canFD_EDL)
   { // EDL is true => the CAN frame is CANFD
      DVLCANmsg.info.messageType  = DVL_MESSAGE_TYPE_CAN_FD;
      DVLCANmsg.dvlCANFD.id       = canId;
      DVLCANmsg.dvlCANFD.extFrame = IDEx;
      DVLCANmsg.dvlCANFD.channel  = busChannel;
      DVLCANmsg.dvlCANFD.length   = DataLength;
      pGroupDataPointer->ReadRawValueByteArray(canFrame.pCAN_DataBytes, CANFD_DataBytes, CANFD_MSG_DATA_BTYES, &ActualDataSize, 0);
      memcpy(&DVLCANmsg.dvlCANFD.data, CANFD_DataBytes, CANFD_MSG_DATA_BTYES);
      DVLCANmsg.dvlCANFD.flags  = 0x0;
      DVLCANmsg.dvlCANFD.fd_brs = b_canFD_BRS;
   }
   else
   {
      DVLCANmsg.info.messageType = DVL_MESSAGE_TYPE_CAN;
      DVLCANmsg.dvlCAN.id        = canId;
      DVLCANmsg.dvlCAN.extFrame  = IDEx;
      DVLCANmsg.dvlCAN.channel   = busChannel;
      DVLCANmsg.dvlCAN.length    = DataLength;
      pGroupDataPointer->ReadRawValueByteArray(canFrame.pCAN_DataBytes, CAN_DataBytes, CAN_MSG_DATA_BTYES, &ActualDataSize, 0);
      memcpy(&DVLCANmsg.dvlCAN.data, CAN_DataBytes, CAN_MSG_DATA_BTYES);
   }
   memcpy(pDVLCANmsg, &DVLCANmsg, sizeof(dvlMessageUnion));

   // increment group pointer!
   return pGroupDataPointer->Inc(1);
}

/*ErrorCode apt_mdfFile::write_MDF(const dvlMessageUnion* pDVLmsg){

   ErrorCode mdfErr = eFileWriteError ;
   bool f_channelMatch = false;

   if(m_MdfLibValid_Flag == false){
      return mdfErr;
   }
   UINT32 CH_No = pDVLmsg->dvlCAN.channel;
   unsigned char can_DataByte[CAN_MSG_DATA_BTYES] = {0};
   INT64 xcan_timeStamp = 0;
   INT32 vIdx = 0;

   m_vecCANObj.begin();
   for(vIdx = 0 ; vIdx < m_vecCANObj.size(); vIdx++){
      if(m_vecCANObj[vIdx].ch_number == CH_No){
         f_channelMatch = true;
         break;
      }
   }
   if(f_channelMatch == false)
   {
      if(eOK != CreateCAN_ChGroup(CH_No)){
         return mdfErr;
      }
   }

   if(!m_vecCANObj[vIdx].pCAN_ChGroup){
      return mdfErr;
   }

   xcan_timeStamp = (INT64)pDVLmsg->info.timestamp;

   mdfErr = m_vecCANObj[vIdx].pCAN_DataWriter->SetTimeNs(xcan_timeStamp);

   UINT8 can_Dir = 0x0;
   WriteSignalValue(m_vecCANObj[vIdx].pCAN_DataWriter, m_vecCANObj[vIdx].pCAN_Dir, can_Dir);

   UINT8 can_EDL = (pDVLmsg->info.messageType == DVL_MESSAGE_TYPE_CAN_FD)? 1 : 0;
   WriteSignalValue(m_vecCANObj[vIdx].pCAN_DataWriter, m_vecCANObj[vIdx].pCAN_EDL, can_EDL);

   UINT8 can_BRS = (pDVLmsg->dvlCANFD.fd_brs == 1)? 1 : 0;
   WriteSignalValue(m_vecCANObj[vIdx].pCAN_DataWriter, m_vecCANObj[vIdx].pCAN_BRS, can_BRS);

   UINT32 can_DLC = pDVLmsg->dvlCAN.length;
   WriteSignalValue(m_vecCANObj[vIdx].pCAN_DataWriter, m_vecCANObj[vIdx].pCAN_DLC, can_DLC);

   UINT32 can_DataLen = pDVLmsg->dvlCAN.length;
   WriteSignalValue(m_vecCANObj[vIdx].pCAN_DataWriter, m_vecCANObj[vIdx].pCAN_DataLength, can_DataLen);

   UINT32 can_ID = (CAN_EXT_ID_MASK & pDVLmsg->dvlCAN.id);
   WriteSignalValue(m_vecCANObj[vIdx].pCAN_DataWriter, m_vecCANObj[vIdx].pCAN_ID, can_ID);

   UINT32 can_IDE = (0x01 & pDVLmsg->dvlCAN.extFrame);
   WriteSignalValue(m_vecCANObj[vIdx].pCAN_DataWriter, m_vecCANObj[vIdx].pCAN_IDE, can_IDE);

   memcpy(can_DataByte, &pDVLmsg->dvlCAN.data, CAN_MSG_DATA_BTYES);
   mdfErr = m_vecCANObj[vIdx].pCAN_DataWriter->WriteRawValue(m_vecCANObj[vIdx].pCAN_DataBytes, can_DataByte, CAN_MSG_DATA_BTYES,
true);

   return mdfErr;
}*/

static ErrorCode ProcessETH_Frame(INT64 time, mdfETH_Frame_T &ETH_Frame, IGroupDataPointer *pGroupDataPointer,
                                  DVSU_RECORD_T *pUDPrec)
{
   UINT32 DataSizeRead                                  = 0;
   ErrorCode errRet                                     = eOK;
   const unsigned int ETH_FRAME_UDP_PAYLOAD_OFFSET      = 28;
   const unsigned int MAX_DATA_SIZE                     = 1522;
   unsigned char ETH_Frame_DataBytes[ETH_MAX_DATA_SIZE] = {0};
   pGroupDataPointer->ReadRawValueByteArray(ETH_Frame.ETH_FrameDataBytes, ETH_Frame_DataBytes, MAX_DATA_SIZE, &DataSizeRead, 0);
   pUDPrec->pcTime = time;
   if (DataSizeRead == ETH_MAX_DATA_SIZE)
   {
      memcpy(&pUDPrec->payload, &ETH_Frame_DataBytes[ETH_FRAME_UDP_PAYLOAD_OFFSET], UDP_PAYLOAD_SIZE);
   }
   // increment group pointer!
   errRet = pGroupDataPointer->Inc(1);
   return errRet;
}

ErrorCode mdf_file_handler::CreateUDPmdfFile(const char *FileName)
{
   ErrorCode mdfErr            = eFileCreateError;
   char FileNameMDF[_MAX_PATH] = {0};

   if (m_MdfLibValid_Flag == false)
   {
      return mdfErr;
   }
   strcpy(FileNameMDF, FileName);

#ifdef _WIN32
   char drvName[_MAX_DRIVE];
   char dir[_MAX_DIR];
   char fName[_MAX_FNAME];
   char ext[_MAX_EXT];
   split_path(FileName, drvName, dir, fName, ext);
#elif __linux__
   char *drvName = new char[_MAX_DRIVE];
   char *dir     = new char[_MAX_DIR];
   char *fName   = new char[_MAX_FNAME];
   char *ext     = new char[_MAX_EXT];
   split_pathLinux(FileName, &drvName, &dir, &fName, &ext);
#endif

   sprintf(FileNameMDF, "%s%s%s_UDP.mf4", drvName, dir, fName);

#ifdef __linux__
   delete[] drvName;
   delete[] dir;
   delete[] fName;
   delete[] ext;
#endif
   m_pFile_UDP = m_pFileManager->CreateFile(FileNameMDF, MDF_VERSION, &mdfErr, eOverwriteExistingFile | eUseAsyncFileWrite, true);
   if (!m_pFile_UDP)
   {
      return eFileCreateError;
   }
   //////////////////////////////////////////////////////////////////////////////////
   // create a file comment and set standard fields and some additional comment fields it for the file

   // note: additional comment fields are a standard feature in MDF 4.x and a proprietary feature in MDF 3.x
   const UINT32 fieldCount = 2;
   IMDF4LibStructs::FieldProperties props[fieldCount];
   props[0] = IMDF4LibStructs::FieldProperties(_T("field no.1"), _T("value for field no.1"));
   props[1] = IMDF4LibStructs::FieldProperties(_T("field no.2"), _T("value for field no.2"));

   mdfErr = m_pFile_UDP->SetCommentTextAndFields(_T("this is a plain text file comment"), _T("Aptiv_SRR"), _T("ActiveSafety"),
                                                 _T("ResimSIL"), _T("Resim_UDP_OutLog"), props, fieldCount);
   if (mdfErr == eOK)
   {
      mdfErr = CreateUDP_ChGroup();
   }

   return mdfErr;
}

ErrorCode mdf_file_handler::getMf4_ToolID(const char *FileName, UINT8 *setVigemmf4)
{
   ErrorCode mdfErr   = eOK;
   UINT8 flagVigemmf4 = 0;
   IFilePtr pFile     = m_pFileManager->OpenFile(FileName, &mdfErr);
   if (pFile)
   {
      IFormatInfoPtr pFormatInfo = pFile->GetFormatInfo(&mdfErr);
      if (mdfErr != eOK)
      {
         return mdfErr;
      }
      LPCTSTR programID = pFormatInfo->GetProgramIdentifier();
      if ((strcmp(programID, "vgmcca10") == 0) || (strcmp(programID, "vgmcca12") == 0) || (strcmp(programID, "vgmcca13") == 0) ||
          (strcmp(programID, "vgmcca15") == 0))
      {
         // printf(_T("Tool ID:     \t%s\n"), programID);
         flagVigemmf4 = 1;
      }
      if (strcmp(programID, "X2E_MDF ") == 0 || strcmp(programID, "X2E_MDF") == 0)
      {
         flagVigemmf4 = 1;
      }
      if ((strcmp(programID, "MDF4Lib") == 0))
      {
         // printf(_T("Tool ID:     \t%s\n"), programID);
         flagVigemmf4 = 2;
      }
   }
   *setVigemmf4 = flagVigemmf4;
   return mdfErr;
}
ErrorCode mdf_file_handler::getMf4_Header_Info(const char *FileName, MDF4_Header_Info_T *pMdfInfo)
{
   ErrorCode mdfErr = eOK;
   IFilePtr pFile   = m_pFileManager->OpenFile(FileName, &mdfErr);
   if (pFile)
   {
      pMdfInfo->mf4_fileName     = (char *)pFile->GetFileName();
      pMdfInfo->MF4_fileSize     = GetFilesize(FileName);
      IFormatInfoPtr pFormatInfo = pFile->GetFormatInfo(&mdfErr);
      if (mdfErr != eOK)
      {
         return mdfErr;
      }
      UINT16 versionNumber          = pFormatInfo->GetVersionNumber();
      pMdfInfo->MF4_Major_Version   = (versionNumber / 100);
      pMdfInfo->MF4_Minor_Version   = ((versionNumber / 10) % 10);
      pMdfInfo->MF4_Release_Version = (versionNumber % 10);
   }
   else
   {
      mdfErr = eFileOpenError;
      return mdfErr;
   }
   return mdfErr;
}

ErrorCode mdf_file_handler::OpenUDPmdfFile(const char *FileName, bool allow_MultiThreading)
{
   ErrorCode mdfErr     = eOK;
   UINT64 numOfChGroups = 0, chIndex = 0;
   SourceBusTypeEnum BusSource = eSourceBusTypeUnspec;

   m_pFile_UDP = m_pFileManager->OpenFile(FileName, &mdfErr, eReadShare, allow_MultiThreading);

   if (!m_pFile_UDP)
   {
      mdfErr = eFileOpenError;
      return mdfErr;
   }

   numOfChGroups = m_pFile_UDP->GetChannelGroupCount();
   if (numOfChGroups < 1)
   {
      mdfErr = eFileEmpty;
      return mdfErr;
   }
   else if (numOfChGroups == 1)
   {
      IChannelGroupPtr pCG     = m_pFile_UDP->GetChannelGroup(chIndex);
      IChannelSetPtr pChildSet = NULL;
      UINT64 CycleCount        = pCG->GetSampleCount();
      if (CycleCount == 0)
      {
         mdfErr = eNoDataAvailable;
         return mdfErr;
      }
      IChannelSetPtr pChSet = pCG->GetChannelSet();
      if (!pChSet)
      {
         mdfErr = eNoDataAvailable;
         return mdfErr;
      }
      // Get the total number of channels to make sure we have at least one channel in the group
      UINT64 numChannels = pChSet->GetCount();
      if (numChannels < 1)
      {
         mdfErr = eNoDataAvailable;
         return mdfErr;
      }
      IChannelPtr pUDPDataByteCH = pChSet->GetChannelByName(_T(strDELPHIRAWDATA));
      IChannelPtr pUDPmf4FrameCH = pChSet->GetChannelByName(_T(strORCASMF4FRAME));

      if (pUDPDataByteCH)
      {
         printf(_T(" 'DelphiRawData' channel is present in the given MF4 log  \n"));
      }
      else
      {
         pUDPDataByteCH = pChSet->GetChannelByName(_T(strRAWDATA));
         if (pUDPDataByteCH)
            printf(_T(" 'RawData' channel is present in the given MF4 log \n"));
      }
      if (!pUDPDataByteCH && pUDPmf4FrameCH)
      {
         pChildSet              = pUDPmf4FrameCH->GetChildChannelSet();
         m_MF4FrameBus          = pChildSet->GetChannelByName(_T(strORCASMF4FRAME strBUSCHANNEL));
         m_MF4FrameID           = pChildSet->GetChannelByName(_T(strORCASMF4FRAME strID));
         m_MF4FrameDLC          = pChildSet->GetChannelByName(_T(strORCASMF4FRAME strDLC));
         m_MF4FrameDest         = pChildSet->GetChannelByName(_T(strORCASMF4FRAME strDEST));
         m_MF4FrameDataLen      = pChildSet->GetChannelByName(_T(strORCASMF4FRAME strDATALENGTH));
         m_MF4FrameDataBytes    = pChildSet->GetChannelByName(_T(strORCASMF4FRAME strDATABYTES));
         m_MF4FrameProtocolType = pChildSet->GetChannelByName(_T(strORCASMF4FRAME strPROTOCOLTYPE));
         m_MF4FrameCycle        = pChildSet->GetChannelByName(_T(strORCASMF4FRAME strCYCLE));
         // printf(_T(" 'MF4Frame' channel is present in the given MF4 log \n"));
      }
      if (!pUDPDataByteCH && !pUDPmf4FrameCH)
      {
         mdfErr = eNoDataAvailable;
         return mdfErr;
      }

      if (pUDPDataByteCH)
      {
         m_udpCH.pUDP_ChannelGroup = pCG;
         UINT32 dataByteCnt        = pCG->GetDataByteCount();
         m_udpCH.pUDP_ByteChannel  = pUDPDataByteCH;
         m_udpCH.vNumberOfRec      = CycleCount;
         m_udpCH.pUDP_DataPointer  = pCG->CreateDataPointerEx(eUseAutoIncrement);
         mdfErr                    = m_udpCH.pUDP_DataPointer->SeekFirst();
      }
      if (pUDPmf4FrameCH)
      {
         m_MF4FrameChGroup     = pCG;
         m_MF4Frame_ByteCh     = pUDPmf4FrameCH;
         mf4NumberOfRec        = CycleCount;
         m_MF4FrameDataPointer = pCG->CreateDataPointerEx(eUseAutoIncrement);
         mdfErr                = m_MF4FrameDataPointer->SeekFirst();
      }
      mdfErr = eOK;
   }
   else
   {
      IGroupDataPointerPtr pETH_GrpDataPtr = m_pFile_UDP->CreateGroupDataPointer(&mdfErr);

      for (chIndex = 0; chIndex < numOfChGroups; chIndex++)
      {
         IChannelGroupPtr pCG     = m_pFile_UDP->GetChannelGroup(chIndex);
         IChannelSetPtr pChildSet = NULL;
         UINT64 CycleCount        = pCG->GetSampleCount();
         if (CycleCount == 0)
         {
            mdfErr = eNoDataAvailable;
            continue; // ignore empty CGs
         }

         IChannelSetPtr pChSet = pCG->GetChannelSet();
         if (!pChSet)
         {
            mdfErr = eNoDataAvailable;
            continue;
         }
         // Get the total number of channels to make sure we have at least one channel in the group
         UINT64 numChannels = pChSet->GetCount();
         if (numChannels < 1)
         {
            mdfErr = eNoDataAvailable;
            continue;
         }

         IChannelPtr pUDPDataByteCH = pChSet->GetChannelByName(_T(strDELPHIRAWDATA));
         IChannelPtr pETH_FrameCH   = pChSet->GetChannelByName(_T(strCANOEethFRAME));

         if (pUDPDataByteCH)
         {
            printf(_T(" 'DelphiRawData' channel is present in the given MF4 log  \n"));
         }
         else
         {
            pUDPDataByteCH = pChSet->GetChannelByName(_T(strRAWDATA));
            if (pUDPDataByteCH)
               printf(_T(" 'RawData' channel is present in the given MF4 log \n"));
         }

         if (pUDPDataByteCH)
         {
            m_udpCH.pUDP_ChannelGroup = pCG;
            UINT32 dataByteCnt        = pCG->GetDataByteCount();
            m_udpCH.pUDP_ByteChannel  = pUDPDataByteCH;
            m_udpCH.vNumberOfRec      = CycleCount;
            m_udpCH.pUDP_DataPointer  = pCG->CreateDataPointerEx(eUseAutoIncrement);
            mdfErr                    = m_udpCH.pUDP_DataPointer->SeekFirst();
            continue;
         }
         ISourceInfoPtr pSrcInfo = pCG->GetSourceInfo();
         if (!pSrcInfo)
            continue;
         BusSource         = (SourceBusTypeEnum)pSrcInfo->GetBusType();
         m_pETH_GrpDataPtr = pETH_GrpDataPtr;
         if (pETH_FrameCH && (BusSource == eBusEthernet))
         {
            mdfETH_Frame_T ETH_CHvtr            = {0};
            pChildSet                           = pETH_FrameCH->GetChildChannelSet();
            ETH_CHvtr.ETH_FrameBus              = pChildSet->GetChannelByName(_T(strCANOEethFRAME strBUSCHANNEL));
            ETH_CHvtr.ETH_FrameSource           = pChildSet->GetChannelByName(_T(strCANOEethFRAME strSOURCE));
            ETH_CHvtr.ETH_FrameDest             = pChildSet->GetChannelByName(_T(strCANOEethFRAME strDEST));
            ETH_CHvtr.ETH_FrameDir              = pChildSet->GetChannelByName(_T(strCANOEethFRAME strDIR));
            ETH_CHvtr.ETH_FrameEtherType        = pChildSet->GetChannelByName(_T(strCANOEethFRAME strETHERTYPE));
            ETH_CHvtr.ETH_FrameDataLen          = pChildSet->GetChannelByName(_T(strCANOEethFRAME strDATALENGTH));
            ETH_CHvtr.ETH_FrameDataBytes        = pChildSet->GetChannelByName(_T(strCANOEethFRAME strDATABYTES));
            ETH_CHvtr.ETH_FrameRcvDataByteCount = pChildSet->GetChannelByName(_T(strCANOEethFRAME strRCVBYTECNT));

            ETH_CHvtr.ETH_FrameChGroup     = pCG;
            ETH_CHvtr.ETH_Frame_ByteCh     = pETH_FrameCH;
            ETH_CHvtr.vETH_NumberOfRec     = CycleCount;
            ETH_CHvtr.ETH_FrameDataPointer = pCG->CreateDataPointerEx(eUseAutoIncrement);
            mdfErr                         = ETH_CHvtr.ETH_FrameDataPointer->SeekFirst();

            // register at IGroupDataPointer and insert into own array
            ETH_CHvtr.vETH_Index = m_pETH_GrpDataPtr->AddChannelGroup(pCG);
            m_vecETHObj.push_back(ETH_CHvtr);
            mdfErr = eOK;
         }
      }
      if (m_pETH_GrpDataPtr)
      {
         mdfErr = m_pETH_GrpDataPtr->SeekFirst();
      }
   }
   return mdfErr;
}

ErrorCode mdf_file_handler::OpenVIGEMmdfFile(const char *FileName, UINT64 *StartTimeStamp, bool allow_MultiThreading,
                                             unsigned int radar_pos, UINT8 *logType)
{
   ErrorCode mdfErr     = eOK;
   UINT64 numOfChGroups = 0, chIndex = 0;
   SourceBusTypeEnum BusSource = eSourceBusTypeUnspec;
   m_pFile_ViGEM               = m_pFileManager->OpenFile(FileName, &mdfErr, eReadShare, allow_MultiThreading);
   if (!m_pFile_ViGEM)
   {
      mdfErr = eFileOpenError;
      return mdfErr;
   }
   getMf4_ToolID(FileName, logType);
   if (*logType == 2)
   {
      mdfErr = 2;
      return mdfErr;
   }
   ITimeStampPtr p = m_pFile_ViGEM->GetStartTime();
   UINT64 ts       = p->GetTimeStampNs(0);
   *StartTimeStamp = ts;
   m_startTime_ns  = ts;

   numOfChGroups = m_pFile_ViGEM->GetChannelGroupCount();
   if (numOfChGroups < 1)
   {
      mdfErr = eFileEmpty;
      return mdfErr;
   }
   else
   {
      IGroupDataPointerPtr pViGEM_GrpDataPtr = m_pFile_ViGEM->CreateGroupDataPointer(&mdfErr);

      for (chIndex = 0; chIndex < numOfChGroups; chIndex++)
      {
         IChannelGroupPtr pCG = m_pFile_ViGEM->GetChannelGroup(chIndex);
         if (pCG)
         {
            IChannelSetPtr pChildSet = NULL;
            UINT64 CycleCount        = pCG->GetSampleCount();
            if (CycleCount == 0)
            {
               mdfErr = eNoDataAvailable;
               continue; // ignore empty CGs
            }

            IChannelSetPtr pChSet = pCG->GetChannelSet();
            if (!pChSet)
            {
               mdfErr = eNoDataAvailable;
               continue;
            }
            // Get the total number of channels to make sure we have at least one channel in the group
            UINT64 numChannels = pChSet->GetCount();
            if (numChannels < 1)
            {
               mdfErr = eNoDataAvailable;
               continue;
            }

            IChannelPtr pETH_FrameCH = pChSet->GetChannelByName(_T(strCANOEethFRAME));
            IChannelPtr pCAN_FrameCH = pChSet->GetChannelByName(strCANDATAFRAME);
            ISourceInfoPtr pSrcInfo  = pCG->GetSourceInfo();
            if (!pSrcInfo)
               continue;
            BusSource = (SourceBusTypeEnum)pSrcInfo->GetBusType();
            // if(pETH_FrameCH && (BusSource == eBusEthernet)){
            //	m_pViGEM_GrpDataPtr = pViGEM_GrpDataPtr;
            //	mdfViGEM_Frame_T ETH_CHvtr = {0};
            //	pChildSet = pETH_FrameCH->GetChildChannelSet();
            //	ETH_CHvtr.mdfViGEM_BusChannel = pChildSet->GetChannelByName(_T(strCANOEethFRAME strBUSCHANNEL));
            //	ETH_CHvtr.ETH_FrameSource = pChildSet->GetChannelByName(_T(strCANOEethFRAME strSOURCE));
            //	ETH_CHvtr.ETH_FrameDest = pChildSet->GetChannelByName(_T(strCANOEethFRAME strDEST));
            //	ETH_CHvtr.ETH_FrameDir = pChildSet->GetChannelByName(_T(strCANOEethFRAME strDIR));
            //	ETH_CHvtr.ETH_FrameEtherType = pChildSet->GetChannelByName(_T(strCANOEethFRAME strETHERTYPE));
            //	ETH_CHvtr.mdfViGEM_FrameCRC = pChildSet->GetChannelByName(strCANOEethFRAME strCRC);
            //	ETH_CHvtr.mdfViGEM_FrameDataLen = pChildSet->GetChannelByName(_T(strCANOEethFRAME strDATALENGTH));
            //	ETH_CHvtr.mdfViGEM_FrameDataBytes = pChildSet->GetChannelByName(_T(strCANOEethFRAME strDATABYTES));
            //	ETH_CHvtr.ETH_FrameRcvDataByteCount = pChildSet->GetChannelByName(_T(strCANOEethFRAME strRCVBYTECNT));

            //	ETH_CHvtr.mdfViGEM_FrameChGroup = pCG;
            //	ETH_CHvtr.mdfViGEM_FrameCh = pETH_FrameCH;
            //	ETH_CHvtr.vNumberOfRec = CycleCount;
            //	ETH_CHvtr.vBusType = BusSource;
            //	ETH_CHvtr.mdfViGEM_FrameDataPointer = pCG->CreateDataPointerEx(eUseAutoIncrement);
            //	mdfErr = ETH_CHvtr.mdfViGEM_FrameDataPointer->SeekFirst();

            //	ETH_CHvtr.vFixBusChannel = GetFixValue(ETH_CHvtr.mdfViGEM_BusChannel);
            //	// register at IGroupDataPointer and insert into own array
            //	ETH_CHvtr.vIndex = m_pViGEM_GrpDataPtr->AddChannelGroup(pCG);
            //	m_vecViGEMObj.push_back(ETH_CHvtr);
            //	mdfErr = eOK;
            //}
            if (pCAN_FrameCH && (BusSource == eBusCAN))
            {
               m_pViGEM_GrpDataPtr                 = pViGEM_GrpDataPtr;
               mdfViGEM_Frame_T canCHvtr           = {0};
               pChildSet                           = pCAN_FrameCH->GetChildChannelSet();
               canCHvtr.mdfViGEM_BusChannel        = pChildSet->GetChannelByName(strCANDATAFRAME strBUSCHANNEL);
               canCHvtr.pCAN_ID                    = pChildSet->GetChannelByName(strCANDATAFRAME strID);
               canCHvtr.pCAN_IDE                   = pChildSet->GetChannelByName(strCANDATAFRAME strIDE);
               canCHvtr.pCAN_DLC                   = pChildSet->GetChannelByName(strCANDATAFRAME strDLC);
               canCHvtr.pCAN_EDL                   = pChildSet->GetChannelByName(strCANDATAFRAME strEDL);
               canCHvtr.pCAN_BRS                   = pChildSet->GetChannelByName(strCANDATAFRAME strBRS);
               canCHvtr.mdfViGEM_FrameCRC          = pChildSet->GetChannelByName(strCANDATAFRAME strCRC);
               canCHvtr.mdfViGEM_FrameDataLen      = pChildSet->GetChannelByName(strCANDATAFRAME strDATALENGTH);
               canCHvtr.mdfViGEM_CANFrameDataBytes = pChildSet->GetChannelByName(strCANDATAFRAME strDATABYTES);

               canCHvtr.mdfViGEM_FrameChGroup = pCG;
               canCHvtr.mdfViGEM_FrameCh      = pCAN_FrameCH;
               canCHvtr.vBusType              = BusSource;
               canCHvtr.vNumberOfRec          = CycleCount;
               canCHvtr.vFixBusChannel        = GetFixValue(canCHvtr.mdfViGEM_BusChannel);
               if (((radar_pos == 8) && (549 == canCHvtr.vFixBusChannel)) ||
                   ((radar_pos == 7) && (550 == canCHvtr.vFixBusChannel)) || ((radar_pos != 7) && (radar_pos != 8)))
               {
                  canCHvtr.mdfViGEM_FrameDataPointer = pCG->CreateDataPointerEx(eUseAutoIncrement, &mdfErr);
                  mdfErr                             = canCHvtr.mdfViGEM_FrameDataPointer->SeekFirst();
                  canCHvtr.vIndex                    = m_pViGEM_GrpDataPtr->AddChannelGroup(pCG);
               }

               // optimization: read fix values only once, -1 means that the value must be read each time!
               canCHvtr.vFixID = GetFixValue(canCHvtr.pCAN_ID);

               canCHvtr.vFixDLC        = GetFixValue(canCHvtr.pCAN_DLC);
               canCHvtr.vFixDataLength = GetFixValue(canCHvtr.mdfViGEM_FrameDataLen);
               canCHvtr.vFixIDE        = GetFixValue(canCHvtr.pCAN_IDE);
               if (canCHvtr.pCAN_EDL)
               {
                  canCHvtr.vFixEDL = GetFixValue(canCHvtr.pCAN_EDL);
               }
               if (canCHvtr.pCAN_BRS)
               {
                  canCHvtr.vFixBRS = GetFixValue(canCHvtr.pCAN_BRS);
               }

               // register at IGroupDataPointer and insert into own array

               m_vecViGEMObj.push_back(canCHvtr);
               mdfErr = eOK;
            }
         }
      }
      if (m_pViGEM_GrpDataPtr)
      {
         mdfErr = m_pViGEM_GrpDataPtr->SeekFirst();
      }
   }
   strcpy(m_file_path, FileName);
   return mdfErr;
}

ErrorCode mdf_file_handler::OpenORCASmdfFile(const char *FileName, bool allow_MultiThreading)
{
   ErrorCode mdfErr     = eOK;
   UINT64 numOfChGroups = 0, chIndex = 0;
   SourceBusTypeEnum BusSource = eSourceBusTypeUnspec;

   m_pFile_ORCAS = m_pFileManager->OpenFile(FileName, &mdfErr, eReadShare, allow_MultiThreading);

   if (!m_pFile_ORCAS)
   {
      mdfErr = eFileOpenError;
      return mdfErr;
   }

   numOfChGroups = m_pFile_ORCAS->GetChannelGroupCount();
   if (numOfChGroups < 1)
   {
      mdfErr = eFileEmpty;
      return mdfErr;
   }
   IChannelGroupPtr pCG                = m_pFile_ORCAS->GetChannelGroup(0); // ORCAS mf4 log has only one data group.
   IChannelSetPtr pChildSet            = NULL;
   IChannelPtr pMf4FrameDataLenCH      = NULL;
   IChannelPtr pMf4FrameDataBytesCH    = NULL;
   IChannelPtr pMf4FrameProtocolTypeCH = NULL;
   UINT64 CycleCount                   = pCG->GetSampleCount();
   if (CycleCount == 0)
   {
      mdfErr = eFileEmpty;
      return mdfErr;
   }

   IChannelSetPtr pChSet = pCG->GetChannelSet();
   if (!pChSet)
   {
      mdfErr = eNoDataAvailable;
      return mdfErr;
   }
   // Get the total number of channels to make sure we have at least one channel in the group
   UINT64 numChannels = pChSet->GetCount();
   if (numChannels < 1)
   {
      mdfErr = eNoDataAvailable;
      return mdfErr;
   }

   m_MF4Frame_ByteCh = pChSet->GetChannelByName(_T("MF4Frame"));

   if (m_MF4Frame_ByteCh)
   {
      pChildSet              = m_MF4Frame_ByteCh->GetChildChannelSet();
      m_MF4FrameBus          = pChildSet->GetChannelByName(_T("MF4Frame.BusChannel"));
      m_MF4FrameID           = pChildSet->GetChannelByName(_T("MF4Frame.ID"));
      m_MF4FrameDLC          = pChildSet->GetChannelByName(_T("MF4Frame.DLC"));
      m_MF4FrameDest         = pChildSet->GetChannelByName(_T("MF4Frame.Destination"));
      m_MF4FrameDataLen      = pChildSet->GetChannelByName(_T("MF4Frame.DataLength"));
      m_MF4FrameDataBytes    = pChildSet->GetChannelByName(_T("MF4Frame.DataBytes"));
      m_MF4FrameProtocolType = pChildSet->GetChannelByName(_T("MF4Frame.ProtocolType"));
      m_MF4FrameCycle        = pChildSet->GetChannelByName(_T("MF4Frame.Cycle"));
      //	printf(_T(" 'MF4Frame' channel is present in the given MF4 log \n"));
   }

   if (!m_MF4Frame_ByteCh)
   {
      mdfErr = eNoDataAvailable;
      return mdfErr;
   }
   mdfErr             = eOK;
   UINT32 dataByteCnt = pCG->GetDataByteCount();

   m_MF4FrameChGroup     = pCG;
   m_MF4FrameDataPointer = m_MF4FrameChGroup->CreateDataPointerEx(eUseAutoIncrement);
   mf4NumberOfRec        = CycleCount;
   mdfErr                = m_MF4FrameDataPointer->SeekFirst();

   return mdfErr;
}
ErrorCode mdf_file_handler::OpenCANmdfFile(const char *FileName)
{
   ErrorCode mdfErr     = eOK;
   UINT64 numOfChGroups = 0, chIndex = 0;

   SourceBusTypeEnum BusSource = eSourceBusTypeUnspec;

   m_pFile_CAN = m_pFileManager->OpenFile(FileName, &mdfErr);
   if (!m_pFile_CAN)
   {
      return mdfErr;
   }

   numOfChGroups = m_pFile_CAN->GetChannelGroupCount();
   if (numOfChGroups < 1)
   {
      return eNoDataAvailable;
   }

   m_pCAN_GrpDataPtr = m_pFile_CAN->CreateGroupDataPointer(&mdfErr);

   for (chIndex = 0; chIndex < numOfChGroups; chIndex++)
   {
      IChannelGroupPtr pCG = m_pFile_CAN->GetChannelGroup(chIndex);

      UINT64 CycleCount = pCG->GetSampleCount();
      if (CycleCount == 0)
         continue; // ignore empty CGs

      ISourceInfoPtr pSrcInfo = pCG->GetSourceInfo();
      if (!pSrcInfo)
         continue;

      BusSource = (SourceBusTypeEnum)pSrcInfo->GetBusType();
      if (BusSource == eBusCAN)
      {
         IChannelSetPtr pChSet = pCG->GetChannelSet(eExcludeNonBusEventChannels);
         if (!pChSet)
            continue;
         IChannelPtr pCanDataFrame = pChSet->GetChannelByName(strCANDATAFRAME);
         if (!pCanDataFrame)
            continue;
         IChannelSetPtr pChildSet = pCanDataFrame->GetChildChannelSet();
         if (!pChildSet)
            continue;

         mdfCANchannel_T canCHvtr = {0};
         canCHvtr.pCAN_ChGroup    = pCG;
         canCHvtr.pCAN_ID         = pChildSet->GetChannelByName(strCANDATAFRAME strID);
         canCHvtr.pCAN_IDE        = pChildSet->GetChannelByName(strCANDATAFRAME strIDE);
         canCHvtr.pCAN_EDL        = pChildSet->GetChannelByName(strCANDATAFRAME strEDL);
         canCHvtr.pCAN_BRS        = pChildSet->GetChannelByName(strCANDATAFRAME strBRS);
         canCHvtr.pCAN_BusChannel = pChildSet->GetChannelByName(strCANDATAFRAME strBUSCHANNEL);
         canCHvtr.pCAN_DataBytes  = pChildSet->GetChannelByName(strCANDATAFRAME strDATABYTES);
         canCHvtr.pCAN_DataLength = pChildSet->GetChannelByName(strCANDATAFRAME strDATALENGTH);
         canCHvtr.pCAN_DLC        = pChildSet->GetChannelByName(strCANDATAFRAME strDLC);

         // optimization: read fix values only once, -1 means that the value must be read each time!
         canCHvtr.vFixID         = GetFixValue(canCHvtr.pCAN_ID);
         canCHvtr.mFixBusChannel = GetFixValue(canCHvtr.pCAN_BusChannel);
         canCHvtr.mFixDLC        = GetFixValue(canCHvtr.pCAN_DLC);
         canCHvtr.mFixDataLength = GetFixValue(canCHvtr.pCAN_DataLength);
         canCHvtr.vFixIDE        = GetFixValue(canCHvtr.pCAN_IDE);
         if (canCHvtr.pCAN_EDL)
         {
            canCHvtr.vFixEDL = GetFixValue(canCHvtr.pCAN_EDL);
         }
         if (canCHvtr.pCAN_BRS)
         {
            canCHvtr.vFixBRS = GetFixValue(canCHvtr.pCAN_BRS);
         }

         // register at IGroupDataPointer and insert into own array
         canCHvtr.vIndex = m_pCAN_GrpDataPtr->AddChannelGroup(pCG);
         m_vecCANObj.push_back(canCHvtr);
      }
   }
   if (m_vecCANObj.empty())
   {
      return eNoDataAvailable; // No CAN Dataframes are found
   }

   mdfErr = m_pCAN_GrpDataPtr->SeekFirst();

   return mdfErr;
}

ErrorCode mdf_file_handler::rewindCAN_MDF(void)
{
   ErrorCode mdfErr = eErrorCodeUnspec;
   if (m_pCAN_GrpDataPtr)
   {
      mdfErr = m_pCAN_GrpDataPtr->SeekFirst();
   }
   return mdfErr;
}

ErrorCode mdf_file_handler::rewindUDP_MDF(void)
{
   ErrorCode mdfErr = eErrorCodeUnspec;
   if (m_udpCH.pUDP_ByteChannel)
   {
      mdfErr = m_udpCH.pUDP_DataPointer->SeekFirst();
   }
   if (m_MF4Frame_ByteCh)
   {
      mdfErr = m_MF4FrameDataPointer->SeekFirst();
   }
   if (m_pETH_GrpDataPtr)
   {
      mdfErr = m_pETH_GrpDataPtr->SeekFirst();
   }
   if (m_pViGEM_GrpDataPtr)
   {
      mdfErr = m_pViGEM_GrpDataPtr->SeekFirst();
   }
   return mdfErr;
}

ErrorCode mdf_file_handler::rewindORCAS_MDF(void)
{
   ErrorCode mdfErr = eErrorCodeUnspec;
   if (m_MF4FrameDataPointer)
   {
      mdfErr = m_MF4FrameDataPointer->SeekFirst();
   }
   return mdfErr;
}
ErrorCode mdf_file_handler::rewindViGEM_MDF(void)
{
   ErrorCode mdfErr = eErrorCodeUnspec;
   if (m_pETH_GrpDataPtr)
   {
      mdfErr = m_pETH_GrpDataPtr->SeekFirst();
   }
   return mdfErr;
}

ErrorCode mdf_file_handler::ProcessViGEMETH_Frame(INT64 time, mdfViGEM_Frame_T &ETH_Frame, IGroupDataPointer *pGroupDataPointer,
                                                  DVSU_RECORD_T *pUDPrec)
{
   UINT32 DataSizeRead                                  = 0;
   ErrorCode errRet                                     = eOK;
   unsigned int ETH_FRAME_UDP_PAYLOAD_OFFSET            = 28;
   const unsigned int MAX_DATA_SIZE                     = 1522;
   unsigned char ETH_Frame_DataBytes[ETH_MAX_DATA_SIZE] = {0};
   INT64 i64BusSrc = 0, i64Dest = 0, i64BusChannel = 0, i64EtherType = 0, i64rcvBtcnt = 0;
   INT64 i64Busethertype = 0, i64Datalen = 0, i64CRC = 0;

   i64BusChannel =
      ETH_Frame.vFixBusChannel < 0 ? ReadValue(pGroupDataPointer, ETH_Frame.mdfViGEM_BusChannel) : ETH_Frame.vFixBusChannel;
   errRet                           = pGroupDataPointer->ReadRawValueInt64(ETH_Frame.mdfViGEM_BusChannel, &i64BusChannel, 0);
   m_ViGEMEthSignals.vEThBusChannel = (UINT32)i64BusChannel;
   errRet                           = pGroupDataPointer->ReadRawValueInt64(ETH_Frame.ETH_FrameSource, &i64BusSrc, 0);
   m_ViGEMEthSignals.vEThSrc        = (UINT64)i64BusSrc;
   errRet                           = pGroupDataPointer->ReadRawValueInt64(ETH_Frame.ETH_FrameDest, &i64Dest, 0);
   m_ViGEMEthSignals.vEThDest       = (UINT64)i64Dest;
   errRet                           = pGroupDataPointer->ReadRawValueInt64(ETH_Frame.ETH_FrameEtherType, &i64Busethertype, 0);
   m_ViGEMEthSignals.vEThetherType  = (UINT32)i64Busethertype;
   errRet                           = pGroupDataPointer->ReadRawValueInt64(ETH_Frame.mdfViGEM_FrameCRC, &i64CRC, 0);
   m_ViGEMEthSignals.vEThCRC        = (UINT32)i64CRC;
   errRet                           = pGroupDataPointer->ReadRawValueInt64(ETH_Frame.ETH_FrameRcvDataByteCount, &i64rcvBtcnt, 0);
   m_ViGEMEthSignals.vEThRcvdbyteCount = (UINT32)i64rcvBtcnt;
   errRet                              = pGroupDataPointer->ReadRawValueInt64(ETH_Frame.mdfViGEM_FrameDataLen, &i64Datalen, 0);
   m_ViGEMEthSignals.vEThDataLength    = (UINT32)i64Datalen;

   pGroupDataPointer->ReadRawValueByteArray(ETH_Frame.mdfViGEM_FrameDataBytes, ETH_Frame_DataBytes, MAX_DATA_SIZE, &DataSizeRead,
                                            0);
   pUDPrec->pcTime = time;
   if ((ETH_Frame_DataBytes[0] == 0xA2 || ETH_Frame_DataBytes[1] == 0xA2) &&
       (ETH_Frame_DataBytes[0] == 0x18 || ETH_Frame_DataBytes[1] == 0x18))
   {
      ETH_FRAME_UDP_PAYLOAD_OFFSET = 0;
   }
   else if (DataSizeRead == 1500)
   {
      ETH_FRAME_UDP_PAYLOAD_OFFSET = 28;
   }
   else if (DataSizeRead == 1504)
   {
      ETH_FRAME_UDP_PAYLOAD_OFFSET = 32;
   }

   if ((ETH_Frame_DataBytes[ETH_FRAME_UDP_PAYLOAD_OFFSET] == 0xA2 &&
        ETH_Frame_DataBytes[ETH_FRAME_UDP_PAYLOAD_OFFSET + 1] == 0x18) ||
       (ETH_Frame_DataBytes[ETH_FRAME_UDP_PAYLOAD_OFFSET] == 0x18 &&
        ETH_Frame_DataBytes[ETH_FRAME_UDP_PAYLOAD_OFFSET + 1] == 0xA2))
   {
      memcpy(&pUDPrec->payload, &ETH_Frame_DataBytes[ETH_FRAME_UDP_PAYLOAD_OFFSET], UDP_PAYLOAD_SIZE);
      m_ViGEMEthSignals.pEthDataBytes = pUDPrec->payload;
   }
   // increment group pointer!
   // errRet = pGroupDataPointer->Inc(1);
   return errRet;
}

ErrorCode mdf_file_handler::ProcessViGEMCAN_Frame(INT64 time, mdfViGEM_Frame_T &canFrame, IGroupDataPointer *pGroupDataPointer,
                                                  dvlMessageUnion *pDVLCANmsg, UINT32 *Buschannel)
{
   UINT32 ActualDataSize                               = 0;
   ErrorCode errRet                                    = eOK;
   unsigned char CAN_DataBytes[CAN_MSG_DATA_BTYES]     = {0};
   unsigned char CANFD_DataBytes[CANFD_MSG_DATA_BTYES] = {0};
   dvlMessageUnion DVLCANmsg                           = {0};
   // static int counter = 0;
   // counter++;
   INT32 canId = canFrame.vFixID < 0 ? ReadValue(pGroupDataPointer, canFrame.pCAN_ID) : canFrame.vFixID;
   INT32 busChannel =
      canFrame.vFixBusChannel < 0 ? ReadValue(pGroupDataPointer, canFrame.mdfViGEM_BusChannel) : canFrame.vFixBusChannel;
   INT8 dlc = canFrame.vFixDLC < 0 ? ReadValue(pGroupDataPointer, canFrame.pCAN_DLC) : canFrame.vFixDLC;
   INT8 DataLength =
      canFrame.vFixDataLength < 0 ? ReadValue(pGroupDataPointer, canFrame.mdfViGEM_FrameDataLen) : canFrame.vFixDataLength;
   INT32 CRC = ReadValue(pGroupDataPointer, canFrame.mdfViGEM_FrameCRC);
   INT8 IDEx = canFrame.vFixIDE < 0 ? ReadValue(pGroupDataPointer, canFrame.pCAN_IDE) : canFrame.vFixIDE;

   INT8 b_canFD_EDL = false;
   INT8 b_canFD_BRS = false;

   if (canFrame.pCAN_EDL)
   {
      b_canFD_EDL = canFrame.vFixEDL < 0 ? ReadValue(pGroupDataPointer, canFrame.pCAN_EDL) : canFrame.vFixEDL;
   }
   if (canFrame.pCAN_BRS)
   {
      b_canFD_BRS = canFrame.vFixBRS < 0 ? ReadValue(pGroupDataPointer, canFrame.pCAN_BRS) : canFrame.vFixBRS;
   }

   DVLCANmsg.info.timestamp   = (UINT64)time;
   DVLCANmsg.info.messageSize = 0x000000000; // Need to check this. 17/Oct/2018

   if (b_canFD_EDL)
   { // EDL is true => the CAN frame is CANFD
      DVLCANmsg.info.messageType  = DVL_MESSAGE_TYPE_CAN_FD;
      DVLCANmsg.dvlCANFD.id       = (CAN_EXT_ID_MASK & canId);
      DVLCANmsg.dvlCANFD.extFrame = IDEx;
      DVLCANmsg.dvlCANFD.channel  = busChannel;
      DVLCANmsg.dvlCANFD.length   = DataLength;
      pGroupDataPointer->ReadRawValueByteArray(canFrame.mdfViGEM_CANFrameDataBytes, CANFD_DataBytes, CANFD_MSG_DATA_BTYES,
                                               &ActualDataSize, 0);
      memcpy(&DVLCANmsg.dvlCANFD.data, CANFD_DataBytes, CANFD_MSG_DATA_BTYES);
      DVLCANmsg.dvlCANFD.flags  = 0x0;
      DVLCANmsg.dvlCANFD.fd_brs = b_canFD_BRS;
      memcpy(&DVLCANmsg.dvlCAN.data, CANFD_DataBytes, CAN_MSG_DATA_BTYES);
   }
   else
   {
      DVLCANmsg.info.messageType = DVL_MESSAGE_TYPE_CAN;
      DVLCANmsg.dvlCAN.id        = (CAN_EXT_ID_MASK & canId);
      DVLCANmsg.dvlCAN.extFrame  = IDEx;
      DVLCANmsg.dvlCAN.channel   = busChannel;
      DVLCANmsg.dvlCAN.length    = DataLength;
      pGroupDataPointer->ReadRawValueByteArray(canFrame.mdfViGEM_CANFrameDataBytes, CAN_DataBytes, CAN_MSG_DATA_BTYES,
                                               &ActualDataSize, 0);
      memcpy(&DVLCANmsg.dvlCAN.data, CAN_DataBytes, CAN_MSG_DATA_BTYES);
      memcpy(&DVLCANmsg.dvlCANFD.data, CAN_DataBytes, CAN_MSG_DATA_BTYES);
   }
   memset(pDVLCANmsg, '\0', sizeof(dvlMessageUnion));
   memcpy(pDVLCANmsg, &DVLCANmsg, sizeof(dvlMessageUnion));
   *Buschannel = busChannel;
   // increment group pointer!
   return errRet;
}

ErrorCode mdf_file_handler::read_MDF(dvlMessageUnion *pDVLmsg)
{
   ErrorCode mdfErr = eOK;
   INT64 ns1 = 0, ns2 = 0, ns3 = 0;

   ns1 = m_pCAN_GrpDataPtr->GetTimeNs();

   // loop: evaluate all CGs with same time as current time
   for (size_t i = 0; i < m_vecCANObj.size(); i++)
   {
      ns2 = m_pCAN_GrpDataPtr->GetTimeNs(nullptr, m_vecCANObj[i].vIndex);
      if (ns2 != ns1)
      {
         continue;
      }
      mdfErr = ProcessCanFrame(ns1, m_vecCANObj[i], m_pCAN_GrpDataPtr, pDVLmsg);

      if (mdfErr != eOK)
      {
         break;
      }

      ns3 = m_pCAN_GrpDataPtr->GetTimeNs();
      if (ns1 != ns3)
      {
         break;
      }
   }
   return mdfErr;
}

ErrorCode mdf_file_handler::read_OrcasMDF(OrcasMdfSignals_T *pOrcas_Mdf_Signal)
{
   ErrorCode mdfErr              = eOK;
   ProtocolTypeEnum ProtocolType = e_Bus_Unknown;
   INT64 DataLength              = 0;
   INT64 Dest                    = 0;
   UINT32 ActualDataSize         = 0;
   INT64 iTemp                   = 0;
   INT64 ns1                     = 0;
   memset(m_Buffer, 0x00, sizeof(m_Buffer));

   if (pOrcas_Mdf_Signal->ProtocolType == e_Bus_Dynamic)
   {
      if (m_MF4FrameChGroup)
      {
         if (mf4NumberOfRec == 0)
         {
            mdfErr = eFileEmpty;
            return mdfErr;
         }

         ns1                          = m_MF4FrameDataPointer->GetTimeNs();
         pOrcas_Mdf_Signal->TimeStamp = ns1;

         mdfErr                        = m_MF4FrameDataPointer->ReadRawValueInt64(m_MF4FrameBus, &iTemp, 0);
         pOrcas_Mdf_Signal->BusChannel = (INT32)iTemp;

         mdfErr                = m_MF4FrameDataPointer->ReadRawValueInt64(m_MF4FrameID, &iTemp, 0);
         pOrcas_Mdf_Signal->ID = (INT32)iTemp;

         mdfErr                 = m_MF4FrameDataPointer->ReadRawValueInt64(m_MF4FrameDLC, &iTemp, 0);
         pOrcas_Mdf_Signal->DLC = (INT8)iTemp;

         mdfErr = m_MF4FrameDataPointer->ReadRawValueInt64(m_MF4FrameDest, &Dest, 0);
         if (mdfErr == eOK)
         {
            pOrcas_Mdf_Signal->Destination = (INT64)Dest;
         }
         mdfErr = m_MF4FrameDataPointer->ReadRawValueInt64(m_MF4FrameDataLen, &DataLength, 0);
         if (mdfErr == eOK)
         {
            pOrcas_Mdf_Signal->DataLength = (INT32)DataLength;
         }
         mdfErr = m_MF4FrameDataPointer->ReadRawValueByteArray(m_MF4FrameDataBytes, m_Buffer, DataLength, &ActualDataSize, 0);
         if (mdfErr == eOK)
         {
            pOrcas_Mdf_Signal->pDataBytes = m_Buffer;
         }
         mdfErr                          = m_MF4FrameDataPointer->ReadRawValueInt64(m_MF4FrameProtocolType, &iTemp, 0);
         pOrcas_Mdf_Signal->ProtocolType = (ProtocolTypeEnum)iTemp;

         mdfErr                   = m_MF4FrameDataPointer->ReadRawValueInt64(m_MF4FrameCycle, &iTemp, 0);
         pOrcas_Mdf_Signal->Cycle = (INT32)iTemp;
      }
   }
   return mdfErr;
}

ErrorCode mdf_file_handler::readMDFrec(void **pdata_ptr, CCA_EthProtocol_Info_T *ProtocolRec)
{
   ErrorCode mdfErr = eOK;
   INT64 ns1        = 0;
   INT64 ns2 = 0, ns3 = 0;
   DVSU_RECORD_T UDPRec_Buffer = {0};
   dvlMessageUnion dvlMsg      = {0};
   UINT8 bustype               = 0;
   INT64 i64BusSrc = 0, i64Dest = 0, i64EtherType = 0, i64rcvBtcnt = 0;
   INT64 i64Busethertype = 0, i64Datalen = 0, can_ID = 0x00, can_EDL = 0;
   UINT32 DataSizeRead                         = 0;
   CCA_EthProtocol_Info_T proRec               = {0};
   const unsigned int MAX_DATA_SIZE            = 1522;
   BYTE ETH_Frame_DataBytes[ETH_MAX_DATA_SIZE] = {0};
   BYTE canDataBytes[CANFD_MSG_DATA_BTYES]     = {0};
   static int i                                = 0;
   UINT32 PTPMessage                           = 0;
   do
   {
      ns1 = m_pViGEM_GrpDataPtr->GetTimeNs();
      if (/*ns1 == 0 ||*/ mdfErr == eReachedEndOfData)
      {
         mdfErr = eReachedEndOfData;
         i      = 0;
         break;
      }
      while (i < m_vecViGEMObj.size())
      {
         ns2 = m_pViGEM_GrpDataPtr->GetTimeNs(nullptr, m_vecViGEMObj[i].vIndex);
         if (ns2 != ns1)
         {
            mdfErr = eFileSortError;
         }
         else
         {
            proRec.abs_timeStamp_ns = m_startTime_ns + ns1; // Absolute timestamp
            proRec.rel_timeStamp_ns = ns1;                  /*Relative Timestamp*/
            proRec.bus_SpecId       = m_vecViGEMObj[i].vFixBusChannel;
            proRec.srcBusType       = m_vecViGEMObj[i].vBusType;
            if (m_vecViGEMObj[i].vBusType == eBusEthernet)
            {
               mdfErr             = m_pViGEM_GrpDataPtr->ReadRawValueInt64(m_vecViGEMObj[i].ETH_FrameSource, &i64BusSrc, 0);
               proRec.source_addr = (UINT64)i64BusSrc;
               mdfErr             = m_pViGEM_GrpDataPtr->ReadRawValueInt64(m_vecViGEMObj[i].ETH_FrameDest, &i64Dest, 0);
               proRec.dest_addr   = (UINT64)i64Dest;
               mdfErr = m_pViGEM_GrpDataPtr->ReadRawValueInt64(m_vecViGEMObj[i].ETH_FrameEtherType, &i64Busethertype, 0);
               proRec.ether_Type = (UINT32)i64Busethertype;
               mdfErr = m_pViGEM_GrpDataPtr->ReadRawValueInt64(m_vecViGEMObj[i].ETH_FrameRcvDataByteCount, &i64rcvBtcnt, 0);
               proRec.dataByteCount = (UINT32)i64rcvBtcnt;
               mdfErr = m_pViGEM_GrpDataPtr->ReadRawValueInt64(m_vecViGEMObj[i].mdfViGEM_FrameDataLen, &i64Datalen, 0);
               m_ViGEMEthSignals.vEThDataLength = (UINT32)i64Datalen;
               mdfErr = m_pViGEM_GrpDataPtr->ReadRawValueByteArray(m_vecViGEMObj[i].mdfViGEM_FrameDataBytes, ETH_Frame_DataBytes,
                                                                   MAX_DATA_SIZE, &DataSizeRead, 0);
               if (proRec.ether_Type == IPV4_ETHER_TYPE)
               {
                  if (ETH_Frame_DataBytes[0] == IPV4_VER_LENGTH)
                  {
                     memcpy(*pdata_ptr, &ETH_Frame_DataBytes[0], sizeof(ETH_Frame_DataBytes));
                  }
               }
               else if (proRec.ether_Type == VLAN_ETHER_TYPE)
               {
                  if (ETH_Frame_DataBytes[4] == IPV4_VER_LENGTH)
                  {
                     memcpy(*pdata_ptr, &ETH_Frame_DataBytes[4], (sizeof(ETH_Frame_DataBytes) - 4));
                  }
                  else if (0 == ETH_Frame_DataBytes[4])
                  {
                     proRec.bus_SpecId = 0;
                  }
               }
               else if (proRec.ether_Type == PTP_ETHER_TYPE)
               {
                  PTPMessage = 1;
                  memcpy(*pdata_ptr, &ETH_Frame_DataBytes[0], sizeof(ETH_Frame_DataBytes));
               }
               else
               {
                  proRec.bus_SpecId = 0;
                  mdfErr            = eNotAvailable;
               }
               if (mdfErr != eOK)
               {
                  i++;
                  break;
               }
            }
            if (m_vecViGEMObj[i].vBusType == eBusCAN)
            {
               mdfErr             = m_pViGEM_GrpDataPtr->ReadRawValueInt64(m_vecViGEMObj[i].ETH_FrameSource, &i64BusSrc, 0);
               proRec.source_addr = (UINT64)i64BusSrc;
               mdfErr             = m_pViGEM_GrpDataPtr->ReadRawValueInt64(m_vecViGEMObj[i].ETH_FrameDest, &i64Dest, 0);
               proRec.dest_addr   = (UINT64)i64Dest;
               mdfErr = m_pViGEM_GrpDataPtr->ReadRawValueInt64(m_vecViGEMObj[i].ETH_FrameEtherType, &i64Busethertype, 0);
               proRec.ether_Type = (UINT32)i64Busethertype;
               mdfErr = m_pViGEM_GrpDataPtr->ReadRawValueInt64(m_vecViGEMObj[i].ETH_FrameRcvDataByteCount, &i64rcvBtcnt, 0);
               proRec.dataByteCount = (UINT32)i64rcvBtcnt;
               i64Datalen           = m_vecViGEMObj[i].vFixDataLength < 0 ?
                                         ReadValue(m_pViGEM_GrpDataPtr, m_vecViGEMObj[i].mdfViGEM_FrameDataLen) :
                                         m_vecViGEMObj[i].vFixDataLength;
               ;
               proRec.dataByteCount = (UINT32)i64Datalen;
               INT8 dlc             = m_vecViGEMObj[i].vFixDLC < 0 ? ReadValue(m_pViGEM_GrpDataPtr, m_vecViGEMObj[i].pCAN_DLC) :
                                                                     m_vecViGEMObj[i].vFixDLC;
               proRec.dlc           = (UINT8)dlc;
               mdfErr               = m_pViGEM_GrpDataPtr->ReadRawValueInt64(m_vecViGEMObj[i].pCAN_ID, &can_ID, 0);
               proRec.canID         = (UINT32)(can_ID & CAN_EXT_ID_MASK);
               mdfErr               = m_pViGEM_GrpDataPtr->ReadRawValueInt64(m_vecViGEMObj[i].pCAN_EDL, &can_EDL, 0);
               ValueAccessMode accsMode = eGetCurrent;
               mdfErr = m_pViGEM_GrpDataPtr->ReadRawValueByteArray(m_vecViGEMObj[i].mdfViGEM_CANFrameDataBytes, canDataBytes,
                                                                   CANFD_MSG_DATA_BTYES, &DataSizeRead, 0, accsMode);
               if (mdfErr != eOK)
               {
                  i++;
                  break;
               }
               memcpy(*pdata_ptr, &canDataBytes[0], sizeof(canDataBytes));
            }
            if (mdfErr != eOK)
            {
               break;
            }
         }
         i++;
         break;
      }
      if (i == m_vecViGEMObj.size())
      {
         mdfErr = m_pViGEM_GrpDataPtr->Inc(1);
         i      = 0;
      }
      if (i > m_vecViGEMObj.size())
      {
         i      = 0;
         mdfErr = eIndexOutOfBound;
      }
      if (mdfErr == eReachedEndOfData)
      {
         if (proRec.bus_SpecId != 0 && proRec.ether_Type != 0)
         {
            if (pdata_ptr != nullptr)
            {
               memcpy(ProtocolRec, &proRec, sizeof(CCA_EthProtocol_Info_T));
               mdfErr = eOK;
               break;
            }
         }
         else
         {
            mdfErr = eReachedEndOfData;
         }
      }
   } while (mdfErr != eOK);
   memcpy(ProtocolRec, &proRec, sizeof(CCA_EthProtocol_Info_T));
   return mdfErr;
}
ErrorCode mdf_file_handler::read_VigemMDF(void **pdata_ptr, INT64 *TimeStamp_ns, UINT32 *busType, UINT32 *Buschannel)
{
   ErrorCode mdfErr = eOK;
   INT64 ns1        = 0;
   INT64 ns2 = 0, ns3 = 0;
   DVSU_RECORD_T UDPRec_Buffer = {0};
   *TimeStamp_ns               = ns1;
   dvlMessageUnion dvlMsg      = {0};
   UINT32 bustype              = 0; // filling can id instead
   // static int i = 0;
   UINT32 buschannel = 0;

   do
   {
      if (m_pViGEM_GrpDataPtr)
      {
         ns1 = m_pViGEM_GrpDataPtr->GetTimeNs();
      }
      else
      {
         return eFileEmpty;
      }

      if (mdfErr == eReachedEndOfData)
      {
         mdfErr = eReachedEndOfData;
         break;
      }
      while (m_vecViGEM_Index < m_vecViGEMObj.size())
      {
         ns2 = m_pViGEM_GrpDataPtr->GetTimeNs(nullptr, m_vecViGEMObj[m_vecViGEM_Index].vIndex);
         if (ns2 != ns1)
         {
            mdfErr = eFileSortError;
         }
         else
         {
            // void* pdata_ptr1 = NULL;
            /*if(m_vecViGEMObj[m_vecViGEM_Index].vBusType == eBusEthernet){
               mdfErr = ProcessViGEMETH_Frame(ns1, m_vecViGEMObj[m_vecViGEM_Index], m_pViGEM_GrpDataPtr, &UDPRec_Buffer);
               if( mdfErr == eReachedEndOfData){
                  break;
               }
            bustype = m_vecViGEMObj[m_vecViGEM_Index].vBusType;
               *pdata_ptr = &UDPRec_Buffer;
            if(UDPRec_Buffer.payload[0] == 0 || UDPRec_Buffer.payload[1] == 0){
               mdfErr = eErrorCodeUnspec;
               m_vecViGEM_Index++;
               break;
            }

         }*/
            if (m_vecViGEMObj[m_vecViGEM_Index].vBusType == eBusCAN)
            {
               mdfErr = ProcessViGEMCAN_Frame(ns1, m_vecViGEMObj[m_vecViGEM_Index], m_pViGEM_GrpDataPtr, &dvlMsg, &buschannel);
               if (mdfErr == eReachedEndOfData)
               {
                  break;
               }
               bustype = dvlMsg.dvlCANFD.id;
               // bustype = m_vecViGEMObj[m_vecViGEM_Index].vBusType;
               *pdata_ptr = &dvlMsg;
               if (dvlMsg.dvlCAN.length == 0 || dvlMsg.dvlCANFD.length == 0)
               {
                  mdfErr = eErrorCodeUnspec;
                  m_vecViGEM_Index++;
                  break;
               }
            }
            if (mdfErr != eOK)
            {
               break;
            }
         }
         m_vecViGEM_Index++;
         break;
      }
      if (m_vecViGEM_Index == m_vecViGEMObj.size())
      {
         mdfErr           = m_pViGEM_GrpDataPtr->Inc(1);
         m_vecViGEM_Index = 0;
      }
   } while (mdfErr != eOK);
   *TimeStamp_ns = ns1;
   *busType      = bustype;
   *Buschannel   = buschannel;

   return mdfErr;
}

ErrorCode mdf_file_handler::read_MDF(DVSU_RECORD_T *pUDPRec, UINT64 *pTimeStamp_ns)
{
   ErrorCode mdfErr              = eOK;
   DVSU_RECORD_T UDPRec_Buffer   = {0};
   UINT32 ActualDataSize         = 0;
   UINT32 UDPbCount              = 1480;
   unsigned char Buffer[1500]    = {0};
   INT64 DataLength              = 0;
   INT64 iTemp                   = 0;
   ProtocolTypeEnum ProtocolType = e_Bus_Unknown;
   size_t i                      = 0;
   // static UINT64 counter = 0;
   INT64 i64DataLen = 0, i64DLC = 0;
   INT64 i64CanID = 0, i64Cycle = 0;
   INT64 i64BusSrc = 0, i64Dest = 0, i64Bus = 0, i64Dir = 0, i64rcvBtcnt = 0;
   // static int dataSize = 0;
   INT64 ns1 = 0;
   INT64 ns2 = 0, ns3 = 0;
   *pTimeStamp_ns = ns1;

   if (m_udpCH.pUDP_ByteChannel && m_udpCH.vNumberOfRec != 0)
   {
      do
      {
         ns1    = m_udpCH.pUDP_DataPointer->GetTimeNs();
         mdfErr = m_udpCH.pUDP_DataPointer->ReadRawValueByteArray(m_udpCH.pUDP_ByteChannel, Buffer, UDPbCount, &ActualDataSize, 0);
         if (mdfErr != eOK)
         {
            break;
         }
         // counter++;
         m_udpCH.pUDP_DataPointer->Inc(1);
         if (mdfErr == eOK)
         {
            //*pTimeStamp_ns = ns1;
            UDPRec_Buffer.pcTime = ns1;
            memcpy(&UDPRec_Buffer.payload, Buffer, ActualDataSize);
         }
      } while (ActualDataSize != UDP_PAYLOAD_SIZE);
   }
   else if (m_MF4FrameChGroup && mf4NumberOfRec != 0)
   {
      do
      {
         ns1    = m_MF4FrameDataPointer->GetTimeNs();
         mdfErr = m_MF4FrameDataPointer->ReadRawValueByteArray(m_MF4FrameDataBytes, Buffer, UDPbCount, &ActualDataSize, 0);
         if (mdfErr != eOK)
         {
            break;
         }
         mdfErr = m_MF4FrameDataPointer->ReadRawValueInt64(m_MF4FrameDataLen, &DataLength, 0);
         if (mdfErr != eOK)
         {
            break;
         }
         mdfErr = m_MF4FrameDataPointer->ReadRawValueInt64(m_MF4FrameProtocolType, &iTemp, 0);
         if (mdfErr != eOK)
         {
            break;
         }
         ProtocolType = (ProtocolTypeEnum)iTemp;
         // This below code is a debug code for frames from the ORCAS mf4 log
         /*************************************************************************************/
         ErrorCode mdfErrX = eOK;
         {
            mdfErrX = m_MF4FrameDataPointer->ReadRawValueInt64(m_MF4FrameID, &i64CanID, 0);
            mdfErrX = m_MF4FrameDataPointer->ReadRawValueInt64(m_MF4FrameDLC, &i64DLC, 0);
            mdfErrX = m_MF4FrameDataPointer->ReadRawValueInt64(m_MF4FrameCycle, &i64Cycle, 0);
         }
         /*************************************************************************************/

         // counter++;
         if (ProtocolType != e_Bus_UDP)
         {
            continue;
         }
         if (mdfErr == eOK && ProtocolType == e_Bus_UDP)
         {
            //	*pTimeStamp_ns = ns1;
            UDPRec_Buffer.pcTime = ns1;
            memcpy(&UDPRec_Buffer.payload, Buffer, ActualDataSize);
         }
      } while (ProtocolType != e_Bus_UDP);
   }
   else if (m_pETH_GrpDataPtr)
   {
      do
      {
         ns1 = m_pETH_GrpDataPtr->GetTimeNs();
         if (ns1 == 0 || mdfErr == eReachedEndOfData)
         {
            break;
         }
         mdfErr = eErrorCodeUnspec;
         for (i = 0; i < m_vecETHObj.size(); i++)
         {
            ns2 = m_pETH_GrpDataPtr->GetTimeNs(nullptr, m_vecETHObj[i].vETH_Index);
            if (ns2 != ns1)
            {
               continue;
            }

            //	*pTimeStamp_ns = ns1;
            mdfErr = ProcessETH_Frame(ns1, m_vecETHObj[i], m_pETH_GrpDataPtr, &UDPRec_Buffer);

            if (mdfErr != eOK)
            {
               break;
            }
            ns3 = m_pETH_GrpDataPtr->GetTimeNs();
            if (UDPRec_Buffer.payload[0] == 0 || UDPRec_Buffer.payload[1] == 0)
            {
               mdfErr = eErrorCodeUnspec;
               break;
            }
            if (ns1 != ns3)
            {
               break;
            }
         }
      } while (mdfErr != eOK);
   }
   *pTimeStamp_ns = ns1;
   memcpy(pUDPRec, &UDPRec_Buffer, sizeof(DVSU_RECORD_T));
   return mdfErr;
}

ErrorCode mdf_file_handler::CreateORCASmdfFile(const char *FileName)
{
   ErrorCode mdfErr           = eFileCreateError;
   char FileNameMDF[MAX_PATH] = {0};

   if (m_MdfLibValid_Flag == false)
   {
      return mdfErr;
   }

#ifdef _WIN32
   char drvName[_MAX_DRIVE];
   char dir[_MAX_DIR];
   char fName[_MAX_FNAME];
   char ext[_MAX_EXT];
   split_path(FileName, drvName, dir, fName, ext);
#elif __linux__
   char *drvName = new char[_MAX_DRIVE];
   char *dir     = new char[_MAX_DIR];
   char *fName   = new char[_MAX_FNAME];
   char *ext     = new char[_MAX_EXT];
   split_pathLinux(FileName, &drvName, &dir, &fName, &ext);
#endif

   sprintf(FileNameMDF, "%s%s%s.mf4", drvName, dir, fName);
#ifdef __linux__
   delete[] drvName;
   delete[] dir;
   delete[] fName;
   delete[] ext;
#endif

   m_pFile_ORCAS = m_pFileManager->CreateFile(FileNameMDF, MDF_VERSION, &mdfErr, eOverwriteExistingFile | eUseAsyncFileWrite);
   if (!m_pFile_ORCAS)
   {
      // printf(_T("Could not create MDF file %s (error code: %d).\n"), FileNameMDF, err);
      return eFileCreateError;
   }
   //////////////////////////////////////////////////////////////////////////////////
   // create a file comment and set standard fields and some additional comment fields it for the file

   // note: additional comment fields are a standard feature in MDF 4.x and a proprietary feature in MDF 3.x
   const UINT32 fieldCount = 2;
   IMDF4LibStructs::FieldProperties props[fieldCount];
   props[0] = IMDF4LibStructs::FieldProperties(_T("field no.1"), _T("value for field no.1"));
   props[1] = IMDF4LibStructs::FieldProperties(_T("field no.2"), _T("value for field no.2"));

   mdfErr = m_pFile_ORCAS->SetCommentTextAndFields(_T("this is a plain text file comment"), _T("Aptiv_SRR"), _T("ActiveSafety"),
                                                   _T("ResimSIL"), _T("Resim_ORCAS_OutLog"), props, fieldCount);

   mdfErr = CreateOrcas_ChGroup();
   return mdfErr;
}
ErrorCode mdf_file_handler::CreateCANmdfFile(const char *FileName)
{
   ErrorCode mdfErr           = eFileCreateError;
   char FileNameMDF[MAX_PATH] = {0};

   if (m_MdfLibValid_Flag == false)
   {
      return mdfErr;
   }

#ifdef _WIN32
   char drvName[_MAX_DRIVE];
   char dir[_MAX_DIR];
   char fName[_MAX_FNAME];
   char ext[_MAX_EXT];
   split_path(FileName, drvName, dir, fName, ext);
#elif __linux__
   char *drvName = new char[_MAX_DRIVE];
   char *dir     = new char[_MAX_DIR];
   char *fName   = new char[_MAX_FNAME];
   char *ext     = new char[_MAX_EXT];
   split_pathLinux(FileName, &drvName, &dir, &fName, &ext);
#endif

   sprintf(FileNameMDF, "%s%s%s_CAN.mf4", drvName, dir, fName);
#ifdef __linux__
   delete[] drvName;
   delete[] dir;
   delete[] fName;
   delete[] ext;
#endif

   m_pFile_CAN = m_pFileManager->CreateFile(FileNameMDF, MDF_VERSION, &mdfErr, eOverwriteExistingFile | eUseAsyncFileWrite);
   if (!m_pFile_CAN)
   {
      // printf(_T("Could not create MDF file %s (error code: %d).\n"), FileNameMDF, err);
      return eFileCreateError;
   }
   //////////////////////////////////////////////////////////////////////////////////
   // create a file comment and set standard fields and some additional comment fields it for the file

   // note: additional comment fields are a standard feature in MDF 4.x and a proprietary feature in MDF 3.x
   const UINT32 fieldCount = 2;
   IMDF4LibStructs::FieldProperties props[fieldCount];
   props[0] = IMDF4LibStructs::FieldProperties(_T("field no.1"), _T("value for field no.1"));
   props[1] = IMDF4LibStructs::FieldProperties(_T("field no.2"), _T("value for field no.2"));

   mdfErr = m_pFile_CAN->SetCommentTextAndFields(_T("this is a plain text file comment"), _T("Aptiv_SRR"), _T("ActiveSafety"),
                                                 _T("ResimSIL"), _T("Resim_DVL_OutLog"), props, fieldCount);

   return mdfErr;
}

ErrorCode mdf_file_handler::CreateVigemmdfFile(const char *FileName)
{
   ErrorCode mdfErr           = eFileCreateError;
   char FileNameMDF[MAX_PATH] = {0};

   if (m_MdfLibValid_Flag == false)
   {
      return mdfErr;
   }

#ifdef _WIN32
   char drvName[_MAX_DRIVE];
   char dir[_MAX_DIR];
   char fName[_MAX_FNAME];
   char ext[_MAX_EXT];
   split_path(FileName, drvName, dir, fName, ext);
#else
   char *drvName = new char[_MAX_DRIVE];
   char *dir     = new char[_MAX_DIR];
   char *fName   = new char[_MAX_FNAME];
   char *ext     = new char[_MAX_EXT];
   split_pathLinux(FileName, &drvName, &dir, &fName, &ext);
#endif

   sprintf(FileNameMDF, "%s%s%s_VGM.mf4", drvName, dir, fName);
#ifdef __linux__
   delete[] drvName;
   delete[] dir;
   delete[] fName;
   delete[] ext;
#endif
   m_pFile_ViGEM = m_pFileManager->CreateFileEx(FileNameMDF, MDF_VERSION, &mdfErr, eOverwriteExistingFile | eUseAsyncFileWrite,
                                                false, "vgmcca12");
   if (!m_pFile_ViGEM)
   {
      // printf(_T("Could not create MDF file %s (error code: %d).\n"), FileNameMDF, err);
      return eFileCreateError;
   }
   //////////////////////////////////////////////////////////////////////////////////
   // create a file comment and set standard fields and some additional comment fields it for the file

   // note: additional comment fields are a standard feature in MDF 4.x and a proprietary feature in MDF 3.x
   const UINT32 fieldCount = 2;
   IMDF4LibStructs::FieldProperties props[fieldCount];
   props[0] = IMDF4LibStructs::FieldProperties(_T("field no.1"), _T("value for field no.1"));
   props[1] = IMDF4LibStructs::FieldProperties(_T("field no.2"), _T("value for field no.2"));

   mdfErr = m_pFile_ViGEM->SetCommentTextAndFields(_T("this is a plain text file comment"), _T("Aptiv_SRR"), _T("ActiveSafety"),
                                                   _T("ResimSIL"), _T("Resim_VIGEM_OutLog"), props, fieldCount);
   return mdfErr;
}

ErrorCode mdf_file_handler::CreateUDP_ChGroup()
{
   ErrorCode mdfErr = eFileCreateError; // 14 - eFileWriteError ;

   if (m_MdfLibValid_Flag == false)
   {
      return mdfErr;
   }
   if (!m_pFile_UDP)
   {
      return mdfErr;
   }
   // create a channel group with acquisition name "DelphiData"
   m_pUDP_ChannelGroup = m_pFile_UDP->CreateChannelGroup(_T("DelphiData")); // Aquisition name for Aptiv UDP data channel
   if (!m_pUDP_ChannelGroup)
   {
      // printf(_T("Failed to create channel group.\n"));
      return mdfErr;
   }
   m_pUDP_TimeChannel = m_pUDP_ChannelGroup->CreateMasterChannel(_T("timestamp"), 0, 1e-9, 64, eInteger_Unsigned_LE, eTimeSync);
   if (!m_pUDP_TimeChannel)
   {
      // printf(_T("Failed to create time channel 'timestamp'.\n"));
      return mdfErr;
   }
   m_pUDP_ByteChannel = m_pUDP_ChannelGroup->CreateDataChannel(strDELPHIRAWDATA, m_pUDP_ChannelGroup->GetDataByteCount(),
                                                               (8 * UDP_PAYLOAD_SIZE), eByteArray);
   if (!m_pUDP_ByteChannel)
   {
      // printf(_T("Failed to create Data Channel 'DelphiRawData'.\n"));
      return mdfErr;
   }
   /////////////////////////////////////////////////////////////////////////////////
   // create a data writer for writing the values
   m_pUDPDataWriter = m_pUDP_ChannelGroup->CreateDataWriter(nullptr, 0, eNoCompression); // eNoCompression, //eTransposeDeflate_1
   if (!m_pUDPDataWriter)
   {
      // printf(_T("Failed to create data writer.\n"));
      return mdfErr;
   }
   mdfErr = m_pUDPDataWriter->SetWriteMode(eAutoFlush);

   return mdfErr;
}

ErrorCode mdf_file_handler::CreateOrcas_ChGroup()
{
   char AqName_ORCAS[10] = {0};
   ErrorCode mdfErr      = eFileCreateError;

   if (m_MdfLibValid_Flag == false)
   {
      return mdfErr;
   }
   if (!m_pFile_ORCAS)
   {
      // printf(_T("Could not create MDF file %s (error code: %d).\n"), FileNameMDF, err);
      return mdfErr;
   }
   sprintf(AqName_ORCAS, "MF4Frame");

   m_pFactoryPtrORCAS = m_pFile_ORCAS->GetFactory();
   if (!m_pFactoryPtrORCAS)
   {
      return mdfErr;
   }

   m_pSrcInfoOrcas      = m_pFactoryPtrORCAS->CreateSourceInfo(0, strORCASMF4FRAME, eSourceBus, eBusNone, nullptr, nullptr);
   char strComment[200] = {0};
   bool isXml           = false;
   m_MF4FrameChGroup    = m_pFile_ORCAS->CreateChannelGroup(AqName_ORCAS, m_pSrcInfoOrcas);
   m_MF4FrameChGroup->SetPathSeparatorChar('.');
   m_MF4Frame_TimeCh = m_MF4FrameChGroup->CreateMasterChannel(_T("TimeStamp"), 0, 1e-9, 64, eInteger_Unsigned_LE, eTimeSync);
   if (!m_MF4Frame_TimeCh)
   {
      // printf(_T("Failed to create time channel 't'.\n"));
      return mdfErr;
   }

   UINT32 f_Flags = (eFlagBusEvent);
   m_MF4Frame_ByteCh =
      m_MF4FrameChGroup->CreateDataChannel(strORCASMF4FRAME, m_MF4FrameChGroup->GetDataByteCount(), (8 * ORCAS_PAYLOAD_SIZE),
                                           eByteArray, nullptr, nullptr, nullptr, m_pSrcInfoOrcas, f_Flags);
   if (!m_MF4Frame_ByteCh)
   {
      // printf(_T("Failed to create Data Channel 'MF4Frame' for ORCAS log.\n"));
      return mdfErr;
   }
   m_MF4FrameBus = m_MF4Frame_ByteCh->CreateChildDataChannel(strORCASMF4FRAME strBUSCHANNEL, B_OFFSET_0, BIT_COUNT_32,
                                                             eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   m_MF4FrameID = m_MF4Frame_ByteCh->CreateChildDataChannel(strORCASMF4FRAME strID, B_OFFSET_4, BIT_COUNT_32, eInteger_Unsigned_LE,
                                                            0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   m_MF4FrameDLC       = m_MF4Frame_ByteCh->CreateChildDataChannel(strORCASMF4FRAME strDLC, B_OFFSET_8, BIT_COUNT_8,
                                                                   eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   m_MF4FrameDest      = m_MF4Frame_ByteCh->CreateChildDataChannel(strORCASMF4FRAME strDEST, B_OFFSET_9, BIT_COUNT_48,
                                                                   eInteger_Unsigned_LE, 0, 0, 0, 0, 0, bit_OFFSET_0, 0);
   m_MF4FrameDataLen   = m_MF4Frame_ByteCh->CreateChildDataChannel(strORCASMF4FRAME strDATALENGTH, B_OFFSET_15, BIT_COUNT_32,
                                                                   eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   m_MF4FrameDataBytes = m_MF4Frame_ByteCh->CreateChildVLSDChannel(strORCASMF4FRAME strDATABYTES, B_OFFSET_24, eByteArray, nullptr,
                                                                   nullptr, nullptr, eFlagBusEvent, 0, nullptr);
   m_MF4FrameProtocolType = m_MF4Frame_ByteCh->CreateChildDataChannel(strORCASMF4FRAME strPROTOCOLTYPE, B_OFFSET_23, BIT_COUNT_8,
                                                                      eInteger_Unsigned_LE, 0, 0, 0, 0, 0, bit_OFFSET_0, 0);
   m_MF4FrameCycle        = m_MF4Frame_ByteCh->CreateChildDataChannel(strORCASMF4FRAME strCYCLE, B_OFFSET_19, BIT_COUNT_32,
                                                                      eInteger_Unsigned_LE, 0, 0, 0, 0, 0, bit_OFFSET_0, 0);
   /////////////////////////////////////////////////////////////////////////////////
   // create a data writer for writing the values
   m_MF4FrameDataWriter = m_MF4FrameChGroup->CreateDataWriter(nullptr, 0, eNoCompression); // eNoCompression, //eTransposeDeflate_1
   if (!m_MF4FrameDataWriter)
   {
      // printf(_T("Failed to create data writer.\n"));
      return mdfErr;
   }
   mdfErr = m_MF4FrameDataWriter->SetWriteMode(eAutoFlush);
   return mdfErr;
}

ErrorCode mdf_file_handler::CreateCAN_ChGroup(const UINT32 channelNumber)
{
   char AqName_CAN[10] = {0};
   ErrorCode mdfErr    = eFileCreateError;

   if (m_MdfLibValid_Flag == false)
   {
      return mdfErr;
   }
   if (!m_pFile_CAN)
   {
      // printf(_T("Could not create MDF file %s (error code: %d).\n"), FileNameMDF, err);
      return mdfErr;
   }
   sprintf(AqName_CAN, "CAN%d", channelNumber);

   mdfCANchannel_T canCHvector = {0};
   m_pFactoryPtrCAN            = m_pFile_CAN->GetFactory();
   if (!m_pFactoryPtrCAN)
   {
      return mdfErr;
   }

   m_pSrcInfoCAN            = m_pFactoryPtrCAN->CreateSourceInfo(0, strCANDATAFRAME, eSourceBus, eBusCAN, nullptr, nullptr);
   char strComment[200]     = {0};
   bool isXml               = false;
   canCHvector.pCAN_ChGroup = m_pFile_CAN->CreateChannelGroup(AqName_CAN, m_pSrcInfoCAN);
   canCHvector.ch_number    = channelNumber;
   if (!canCHvector.pCAN_ChGroup)
   {
      // printf(_T("Failed to create time channel 't'.\n"));
      return mdfErr;
   }
   canCHvector.pCAN_ChGroup->SetPathSeparatorChar('.');
   canCHvector.pCAN_TimeCh = canCHvector.pCAN_ChGroup->CreateMasterChannel(_T("t"), 0, 1e-9, 64, eInteger_Unsigned_LE, eTimeSync);
   if (!canCHvector.pCAN_TimeCh)
   {
      // printf(_T("Failed to create time channel 't'.\n"));
      return mdfErr;
   }

   UINT32 f_Flags = (eFlagBusEvent);
   sprintf(strComment, "CAN%d", channelNumber);
   m_pCommentCAN = m_pFactoryPtrCAN->CreateComment(strComment);
   m_pSrcInfoCAN = m_pFactoryPtrCAN->CreateSourceInfo(0, AqName_CAN, eSourceBus, eBusCAN, nullptr, nullptr);

   canCHvector.pCAN_ByteCh = canCHvector.pCAN_ChGroup->CreateDataChannel(
      strCANDATAFRAME, canCHvector.pCAN_ChGroup->GetDataByteCount(), (8 * CAN_PAYLOAD_SIZE), eByteArray, nullptr, nullptr, nullptr,
      m_pSrcInfoCAN, f_Flags);
   if (!canCHvector.pCAN_ByteCh)
   {
      // printf(_T("Failed to create Data Channel 'CANDATAFRAME'.\n"));
      return mdfErr;
   }
   IConversionPtr pConvsn = m_pFactoryPtrCAN->CreateLinearConversion(0, channelNumber);

   f_Flags                     = (eFlagDiscrete | eFlagBusEvent);
   canCHvector.pCAN_BusChannel = canCHvector.pCAN_ByteCh->CreateChildDataChannel(
      strCANDATAFRAME strBUSCHANNEL, B_OFFSET_0, BIT_COUNT_0, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   canCHvector.pCAN_BusChannel->SetConversion(pConvsn);

   canCHvector.pCAN_Flags = canCHvector.pCAN_ByteCh->CreateChildDataChannel(
      strCANDATAFRAME strFLAGS, B_OFFSET_0, BIT_COUNT_8, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   canCHvector.pCAN_Dir = canCHvector.pCAN_ByteCh->CreateChildDataChannel(
      strCANDATAFRAME strDIR, B_OFFSET_0, BIT_COUNT_1, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   canCHvector.pCAN_EDL = canCHvector.pCAN_ByteCh->CreateChildDataChannel(
      strCANDATAFRAME strEDL, B_OFFSET_0, BIT_COUNT_1, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_1, 0);
   canCHvector.pCAN_BRS = canCHvector.pCAN_ByteCh->CreateChildDataChannel(
      strCANDATAFRAME strBRS, B_OFFSET_0, BIT_COUNT_1, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_2, 0);

   // Need to add EDL ans BRS
   canCHvector.pCAN_SingleWire = canCHvector.pCAN_ByteCh->CreateChildDataChannel(
      strCANDATAFRAME strSINGLEWIRE, B_OFFSET_0, BIT_COUNT_1, eInteger_Unsigned_LE, 0, 0, 0, 0, 0, bit_OFFSET_5, 0);
   canCHvector.pCAN_WakeUp = canCHvector.pCAN_ByteCh->CreateChildDataChannel(strCANDATAFRAME strWAKEUP, B_OFFSET_0, BIT_COUNT_1,
                                                                             eInteger_Unsigned_LE, 0, 0, 0, 0, 0, bit_OFFSET_6, 0);

   canCHvector.pCAN_ID = canCHvector.pCAN_ByteCh->CreateChildDataChannel(
      strCANDATAFRAME strID, B_OFFSET_3, BIT_COUNT_32, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   canCHvector.pCAN_IDE = canCHvector.pCAN_ByteCh->CreateChildDataChannel(strCANDATAFRAME strIDE, B_OFFSET_6, BIT_COUNT_1,
                                                                          eInteger_Unsigned_LE, 0, 0, 0, 0, 0, bit_OFFSET_7, 0);

   canCHvector.pCAN_DLC = canCHvector.pCAN_ByteCh->CreateChildDataChannel(
      strCANDATAFRAME strDLC, B_OFFSET_1, BIT_COUNT_8, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   canCHvector.pCAN_DataLength = canCHvector.pCAN_ByteCh->CreateChildDataChannel(
      strCANDATAFRAME strDATALENGTH, B_OFFSET_2, BIT_COUNT_8, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);

   // canCHvector.pCAN_DataBytes = canCHvector.pCAN_ByteCh->CreateChildDataChannel(strCANDATAFRAME strDATABYTES, B_OFFSET_7,
   // (BIT_COUNT_64 * 8), eByteArray, 0, 0, 0, (eFlagDiscrete|eFlagBusEvent), 0, bit_OFFSET_0, 0);;
   canCHvector.pCAN_DataBytes = canCHvector.pCAN_ByteCh->CreateChildVLSDChannel(
      strCANDATAFRAME strDATABYTES, B_OFFSET_7, eByteArray, nullptr, nullptr, nullptr, eFlagBusEvent, 0, nullptr);
   canCHvector.pCAN_DataWriter =
      canCHvector.pCAN_ChGroup->CreateDataWriter(nullptr, 0, eNoCompression); // eNoCompression, //eTransposeDeflate_1

   // register at IGroupDataPointer and insert into own array
   // canCHvector.vIndex = m_pCAN_GrpDataPtr->AddChannelGroup(pCG);
   canCHvector.pCAN_DataWriter->SetWriteMode(eAutoFlush);

   m_vecCANObj.push_back(canCHvector);

   mdfErr = eOK;

   return mdfErr;
}

ErrorCode mdf_file_handler::CreateVigem_ChGroup(const UINT8 radarPos)
{
   ErrorCode mdfErr = eFileCreateError;

   if (m_MdfLibValid_Flag == false)
   {
      return mdfErr;
   }
   if (!m_pFile_ViGEM)
   {
      return mdfErr;
   }

   mdfViGEM_Frame_T ethCHvector = {0};
   m_pFactoryPtrVIGEM           = m_pFile_ViGEM->GetFactory();
   if (!m_pFactoryPtrVIGEM)
   {
      return mdfErr;
   }

   m_pSrcInfoVigem      = m_pFactoryPtrVIGEM->CreateSourceInfo(0, strCANOEethFRAME, eSourceBus, eBusEthernet, nullptr, nullptr);
   char strComment[200] = {0};
   bool isXml           = false;
   ethCHvector.mdfViGEM_FrameChGroup = m_pFile_ViGEM->CreateChannelGroup(strCANOEethFRAME, m_pSrcInfoVigem);
   ethCHvector.vch_number            = radarPos;
   if (!ethCHvector.mdfViGEM_FrameChGroup)
   {
      return mdfErr;
   }
   ethCHvector.mdfViGEM_FrameChGroup->SetPathSeparatorChar('.');
   ethCHvector.mdfViGEM_FrameTimeCh =
      ethCHvector.mdfViGEM_FrameChGroup->CreateMasterChannel(_T("TimeStamp"), 0, 1e-9, 64, eInteger_Unsigned_LE, eTimeSync);
   if (!ethCHvector.mdfViGEM_FrameTimeCh)
   {
      // printf(_T("Failed to create time channel 't'.\n"));
      return mdfErr;
   }
   UINT32 f_Flags = (eFlagBusEvent);
   sprintf(strComment, "ETH_%d", radarPos);
   m_pCommentVigem = m_pFactoryPtrVIGEM->CreateComment(strComment);
   m_pSrcInfoVigem = m_pFactoryPtrVIGEM->CreateSourceInfo(0, _T("CCA"), eSourceBus, eBusEthernet, nullptr, nullptr);

   ethCHvector.mdfViGEM_FrameAsyncCh = ethCHvector.mdfViGEM_FrameChGroup->CreateDataChannel(
      _T("Asynchronous"), ethCHvector.mdfViGEM_FrameChGroup->GetDataByteCount(), BIT_COUNT_8, eByteArray, nullptr, nullptr,
      nullptr, nullptr, f_Flags);
   if (!ethCHvector.mdfViGEM_FrameAsyncCh)
   {
      return mdfErr;
   }
   ethCHvector.mdfViGEM_FrameCh = ethCHvector.mdfViGEM_FrameChGroup->CreateDataChannel(
      strCANOEethFRAME, ethCHvector.mdfViGEM_FrameChGroup->GetDataByteCount(), (8 * ETH_PAYLOAD_SIZE), eByteArray, nullptr,
      nullptr, nullptr, m_pSrcInfoVigem, f_Flags);
   if (!ethCHvector.mdfViGEM_FrameCh)
   {
      return mdfErr;
   }

   IConversionPtr pConvsn          = m_pFactoryPtrVIGEM->CreateLinearConversion(0, radarPos);
   f_Flags                         = (eFlagDiscrete | eFlagBusEvent);
   ethCHvector.mdfViGEM_BusChannel = ethCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(
      strCANOEethFRAME strBUSCHANNEL, B_OFFSET_0, BIT_COUNT_0, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   ethCHvector.mdfViGEM_BusChannel->SetConversion(pConvsn);

   ethCHvector.ETH_FrameSource = ethCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(
      strCANOEethFRAME strSOURCE, B_OFFSET_9, BIT_COUNT_48, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   ethCHvector.ETH_FrameDest = ethCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(
      strCANOEethFRAME strDEST, B_OFFSET_15, BIT_COUNT_48, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   ethCHvector.ETH_FrameEtherType = ethCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(
      strCANOEethFRAME strETHERTYPE, B_OFFSET_21, BIT_COUNT_16, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_1, 0);
   ethCHvector.mdfViGEM_FrameCRC = ethCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(
      strCANOEethFRAME strCRC, B_OFFSET_23, BIT_COUNT_32, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_2, 0);
   ethCHvector.ETH_FrameRcvDataByteCount =
      ethCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(strCANOEethFRAME strRCVBYTECNT, B_OFFSET_27, BIT_COUNT_32, eByteArray,
                                                           0, 0, 0, (eFlagDiscrete | eFlagBusEvent), 0, bit_OFFSET_0, 0);
   ethCHvector.mdfViGEM_FrameDataLen = ethCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(
      strCANOEethFRAME strDATALENGTH, B_OFFSET_31, BIT_COUNT_32, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   ethCHvector.mdfViGEM_FrameDataBytes = ethCHvector.mdfViGEM_FrameCh->CreateChildVLSDChannel(
      strCANOEethFRAME strDATABYTES, B_OFFSET_41, eByteArray, nullptr, nullptr, nullptr, eFlagBusEvent, 0, nullptr);
   ethCHvector.mdfViGEM_FrameWriter =
      ethCHvector.mdfViGEM_FrameChGroup->CreateDataWriter(nullptr, 0, eNoCompression); // eNoCompression, //eTransposeDeflate_1
   if (ethCHvector.mdfViGEM_FrameWriter)
   {
      ethCHvector.mdfViGEM_FrameWriter->SetWriteMode(eAutoFlush);
   }
   m_vecViGEMObj.push_back(ethCHvector);

   mdfErr = eOK;

   return mdfErr;
}

ErrorCode mdf_file_handler::CreateVigem_CANChGroup(const UINT32 channelNumber)
{
   ErrorCode mdfErr = eFileCreateError;

   if (m_MdfLibValid_Flag == false)
   {
      return mdfErr;
   }
   if (!m_pFile_ViGEM)
   {
      return mdfErr;
   }

   mdfViGEM_Frame_T canCHvector = {0};
   ;
   m_pFactoryPtrVIGEM = m_pFile_ViGEM->GetFactory();
   if (!m_pFactoryPtrVIGEM)
   {
      return mdfErr;
   }

   m_pSrcInfoVigem      = m_pFactoryPtrVIGEM->CreateSourceInfo(0, strCANDATAFRAME, eSourceBus, eBusCAN, nullptr, nullptr);
   char strComment[200] = {0};
   bool isXml           = false;

   canCHvector.mdfViGEM_FrameChGroup = m_pFile_ViGEM->CreateChannelGroup(strCANDATAFRAME, m_pSrcInfoVigem);
   canCHvector.vCANch_number         = channelNumber;
   if (!canCHvector.mdfViGEM_FrameChGroup)
   {
      return mdfErr;
   }
   canCHvector.mdfViGEM_FrameChGroup->SetPathSeparatorChar('.');
   canCHvector.mdfViGEM_FrameTimeCh =
      canCHvector.mdfViGEM_FrameChGroup->CreateMasterChannel(_T("TimeStamp"), 0, 1e-9, 64, eInteger_Unsigned_LE, eTimeSync);
   if (!canCHvector.mdfViGEM_FrameTimeCh)
   {
      // printf(_T("Failed to create time channel 't'.\n"));
      return mdfErr;
   }
   UINT32 f_Flags = (eFlagBusEvent);
   sprintf(strComment, "CAN%d", channelNumber);
   m_pCommentCAN = m_pFactoryPtrVIGEM->CreateComment(strComment);
   m_pSrcInfoCAN = m_pFactoryPtrVIGEM->CreateSourceInfo(0, _T("CCA"), eSourceBus, eBusCAN, nullptr, nullptr);

   canCHvector.mdfViGEM_FrameAsyncCh = canCHvector.mdfViGEM_FrameChGroup->CreateDataChannel(
      _T("Asynchronous"), canCHvector.mdfViGEM_FrameChGroup->GetDataByteCount(), BIT_COUNT_8, eByteArray, nullptr, nullptr,
      nullptr, nullptr, f_Flags);
   if (!canCHvector.mdfViGEM_FrameAsyncCh)
   {
      return mdfErr;
   }
   canCHvector.mdfViGEM_FrameCh = canCHvector.mdfViGEM_FrameChGroup->CreateDataChannel(
      strCANDATAFRAME, canCHvector.mdfViGEM_FrameChGroup->GetDataByteCount(), (8 * VGM_CAN_PAYLOAD_SIZE), eByteArray, nullptr,
      nullptr, nullptr, m_pSrcInfoCAN, f_Flags);
   if (!canCHvector.mdfViGEM_FrameCh)
   {
      return mdfErr;
   }

   IConversionPtr pConvsn          = m_pFactoryPtrVIGEM->CreateLinearConversion(0, channelNumber);
   f_Flags                         = (eFlagDiscrete | eFlagBusEvent);
   canCHvector.mdfViGEM_BusChannel = canCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(
      strCANDATAFRAME strBUSCHANNEL, B_OFFSET_0, BIT_COUNT_0, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   canCHvector.mdfViGEM_BusChannel->SetConversion(pConvsn);

   canCHvector.pCAN_ID = canCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(
      strCANDATAFRAME strID, B_OFFSET_9, BIT_COUNT_32, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   canCHvector.pCAN_IDE = canCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(
      strCANDATAFRAME strIDE, B_OFFSET_12, BIT_COUNT_1, eInteger_Unsigned_LE, 0, 0, 0, 0, 0, bit_OFFSET_7, 0);
   canCHvector.pCAN_DLC = canCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(
      strCANDATAFRAME strDLC, B_OFFSET_13, BIT_COUNT_6, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   canCHvector.pCAN_EDL = canCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(
      strCANDATAFRAME strEDL, B_OFFSET_13, BIT_COUNT_1, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_6, 0);
   canCHvector.pCAN_BRS = canCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(
      strCANDATAFRAME strBRS, B_OFFSET_13, BIT_COUNT_1, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_7, 0);
   canCHvector.mdfViGEM_FrameCRC = canCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(
      strCANDATAFRAME strCRC, B_OFFSET_14, BIT_COUNT_16, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   canCHvector.mdfViGEM_FrameDataLen = canCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(
      strCANDATAFRAME strDATALENGTH, B_OFFSET_16, BIT_COUNT_8, eInteger_Unsigned_LE, 0, 0, 0, f_Flags, 0, bit_OFFSET_0, 0);
   // canCHvector.mdfViGEM_CANFrameDataBytes = canCHvector.mdfViGEM_FrameCh->CreateChildDataChannel(strCANDATAFRAME strDATABYTES,
   // B_OFFSET_17, BIT_COUNT_64, eByteArray, 0, 0, 0, (eFlagDiscrete|eFlagBusEvent), 0, bit_OFFSET_0, 0);
   canCHvector.mdfViGEM_CANFrameDataBytes = canCHvector.mdfViGEM_FrameCh->CreateChildVLSDChannel(
      strCANDATAFRAME strDATABYTES, B_OFFSET_7, eByteArray, nullptr, nullptr, nullptr, eFlagBusEvent, 0, nullptr);
   canCHvector.mdfViGEM_CANFrameWriter =
      canCHvector.mdfViGEM_FrameChGroup->CreateDataWriter(nullptr, 0, eNoCompression); // eNoCompression, //eTransposeDeflate_1

   // register at IGroupDataPointer and insert into own array
   if (canCHvector.mdfViGEM_CANFrameWriter)
      canCHvector.mdfViGEM_CANFrameWriter->SetWriteMode(eAutoFlush);

   m_vecViGEMObj.push_back(canCHvector);

   mdfErr = eOK;

   return mdfErr;
}
UINT8 mapToDLC(UINT32 length)
{
   static UINT8 canfd_DLC = 0;
   switch (length)
   {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
         canfd_DLC = length;
         break;
      case 12:
         canfd_DLC = 9;
         break;
      case 16:
         canfd_DLC = 10;
         break;
      case 20:
         canfd_DLC = 11;
         break;
      case 24:
         canfd_DLC = 12;
         break;
      case 32:
         canfd_DLC = 13;
         break;
      case 48:
         canfd_DLC = 14;
         break;
      case 64:
         canfd_DLC = 15;
         break;
      default:
         break;
   }
   return canfd_DLC;
}
//
// ErrorCode apt_mdfFile::write_OrcasMDFsignal(const DVSU_RECORD_T* pUdpRec, UINT64 TimeStamp_ns){
//	ErrorCode mdfErr = eFileWriteError ;
//	write_OrcasMDF(pUdpRec, TimeStamp_ns);
//	return mdfErr;
//}
// ErrorCode apt_mdfFile::write_OrcasMDFsignal(const dvlMessageUnion* pDVLmsg){
//	ErrorCode mdfErr = eFileWriteError ;
//	OrcasMdfSignals_T OrcasObj = {0};
//
//	OrcasObj.BusChannel = 0;
//	OrcasObj.Destination = 0;
//	OrcasObj.Cycle = 0;
//	OrcasObj.ProtocolType = (ProtocolTypeEnum)((pDVLmsg->info.messageType == DVL_MESSAGE_TYPE_CAN) ? e_Bus_CAN : e_Bus_CANFD);
//
//	if(OrcasObj.ProtocolType == e_Bus_CAN){
//		OrcasObj.ID			= pDVLmsg->dvlCAN.id;
//		OrcasObj.pDataBytes = (unsigned char*)pDVLmsg->dvlCAN.data;
//		OrcasObj.DataLength = pDVLmsg->dvlCAN.length;
//		OrcasObj.DLC		= pDVLmsg->dvlCAN.length;
//	}
//
//	if(OrcasObj.ProtocolType == e_Bus_CANFD){
//		OrcasObj.ID			= pDVLmsg->dvlCANFD.id;
//		OrcasObj.pDataBytes = (unsigned char*)pDVLmsg->dvlCANFD.data;
//		OrcasObj.DataLength = pDVLmsg->dvlCANFD.length;
//		OrcasObj.DLC		= pDVLmsg->dvlCANFD.length;
//	}
//	OrcasObj.TimeStamp = pDVLmsg->info.timestamp;
//
//	write_OrcasMDF(&OrcasObj);
//	return mdfErr;
//}
ErrorCode mdf_file_handler::write_OrcasMDF(const OrcasMdfSignals_T *pOrcasMdfSignal)
{
   ErrorCode mdfErr                              = eFileWriteError;
   bool isValid                                  = true;
   unsigned char DataByteArray[UDP_PAYLOAD_SIZE] = {0}; //	UDP_PAYLOAD_SIZE 1472.
   INT64 pc_timeStamp                            = 0;
   INT64 iProtocol_Type                          = 0;
   INT64 iCycle                                  = 0;
   INT64 iBusCh                                  = 0;
   INT64 iID                                     = 0;
   INT64 iDLC                                    = 0;
   INT64 iDest                                   = 0;
   INT64 iDataLen                                = 0;
   if (m_MdfLibValid_Flag == false)
   {
      return mdfErr;
   }

   if (!m_MF4FrameChGroup)
   {
      return mdfErr;
   }

   iBusCh = (INT8)pOrcasMdfSignal->BusChannel;
   mdfErr = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameBus, iBusCh, true);

   iID    = (INT32)pOrcasMdfSignal->ID;
   mdfErr = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameID, iID, true);

   iDLC   = (INT8)pOrcasMdfSignal->DLC;
   mdfErr = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameDLC, iDLC, true);

   iDest  = (INT8)pOrcasMdfSignal->Destination;
   mdfErr = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameDest, iDest, true);

   iDataLen = (INT32)pOrcasMdfSignal->DataLength;

   mdfErr = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameDataLen, iDataLen, true);

   memcpy(&DataByteArray, pOrcasMdfSignal->pDataBytes, iDataLen);
   mdfErr = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameDataBytes, DataByteArray, iDataLen, true);

   iProtocol_Type = (INT64)pOrcasMdfSignal->ProtocolType;
   mdfErr         = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameProtocolType, iProtocol_Type, true);

   iCycle = (INT32)pOrcasMdfSignal->Cycle;
   mdfErr = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameCycle, iCycle, true);

   pc_timeStamp = (INT64)pOrcasMdfSignal->TimeStamp;
   mdfErr       = m_MF4FrameDataWriter->SetTimeNs(pc_timeStamp);

   isValid = true;

   return mdfErr;
}
ErrorCode mdf_file_handler::write_OrcasMDF(const DVSU_RECORD_T *pUdpRec, UINT64 TimeStamp_ns)
{
   ErrorCode mdfErr                              = eFileWriteError;
   bool isValid                                  = true;
   unsigned char DataByteArray[UDP_PAYLOAD_SIZE] = {0}; //	UDP_PAYLOAD_SIZE 1472.
   INT64 pc_timeStamp                            = 0;
   INT64 iProtocol_Type                          = 0;
   INT64 iCycle                                  = 0;
   INT64 iBusCh                                  = 0;
   INT64 iID                                     = 0;
   INT64 iDLC                                    = 0;
   INT64 iDest                                   = 0;
   INT64 iDataLen                                = 0;
   if (m_MdfLibValid_Flag == false)
   {
      return mdfErr;
   }

   if (!m_MF4FrameChGroup)
   {
      return mdfErr;
   }

   mdfErr = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameBus, iBusCh, true);

   mdfErr = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameID, iID, true);

   mdfErr = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameDLC, iDLC, true);

   mdfErr = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameDest, iDest, true);

   iDataLen = (INT32)UDP_PAYLOAD_SIZE;
   mdfErr   = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameDataLen, iDataLen, true);

   memcpy(&DataByteArray, &pUdpRec->payload[0], UDP_PAYLOAD_SIZE);
   mdfErr = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameDataBytes, DataByteArray, iDataLen, true);

   iProtocol_Type = (INT64)e_Bus_UDP;
   mdfErr         = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameProtocolType, iProtocol_Type, true);

   mdfErr = m_MF4FrameDataWriter->WriteRawValue(m_MF4FrameCycle, iCycle, true);

   pc_timeStamp = (INT64)TimeStamp_ns;
   mdfErr       = m_MF4FrameDataWriter->SetTimeNs(pc_timeStamp);

   isValid = true;

   return mdfErr;
}
ErrorCode mdf_file_handler::write_VigemMDFsignal(const DVSU_RECORD_T *pUdpRec, UINT64 TimeStamp_ns)
{
   ErrorCode mdfErr     = eFileWriteError;
   bool f_radarPosMatch = false;

   if (m_MdfLibValid_Flag == false)
   {
      return mdfErr;
   }
   UINT32 Source_No                             = pUdpRec->payload[0x09];
   unsigned char eth_DataByte[UDP_PAYLOAD_SIZE] = {0};
   INT32 vIdx                                   = 0;

   m_vecViGEMObj.begin();
   for (vIdx = 0; vIdx < m_vecViGEMObj.size(); vIdx++)
   {
      if (m_vecViGEMObj[vIdx].vch_number == Source_No)
      {
         f_radarPosMatch = true;
         break;
      }
   }
   if (f_radarPosMatch == false)
   {
      if (eOK != CreateVigem_ChGroup(Source_No))
      {
         return mdfErr;
      }
   }

   if (!m_vecViGEMObj[vIdx].mdfViGEM_FrameChGroup)
   {
      return mdfErr;
   }

   mdfErr = m_vecViGEMObj[vIdx].mdfViGEM_FrameWriter->SetTimeNs(TimeStamp_ns);

   UINT64 eth_Source = m_ViGEMEthSignals.vEThSrc;
   WriteSignalValue(m_vecViGEMObj[vIdx].mdfViGEM_FrameWriter, m_vecViGEMObj[vIdx].ETH_FrameSource, eth_Source);

   UINT64 eth_Dest = m_ViGEMEthSignals.vEThDest;
   WriteSignalValue(m_vecViGEMObj[vIdx].mdfViGEM_FrameWriter, m_vecViGEMObj[vIdx].ETH_FrameDest, eth_Dest);

   UINT16 eth_EtherType = m_ViGEMEthSignals.vEThetherType;
   WriteSignalValue(m_vecViGEMObj[vIdx].mdfViGEM_FrameWriter, m_vecViGEMObj[vIdx].ETH_FrameEtherType, eth_EtherType);

   UINT32 eth_CRC = m_ViGEMEthSignals.vEThCRC;
   WriteSignalValue(m_vecViGEMObj[vIdx].mdfViGEM_FrameWriter, m_vecViGEMObj[vIdx].mdfViGEM_FrameCRC, eth_CRC);

   UINT32 eth_rcvDataByteCnt = m_ViGEMEthSignals.vEThRcvdbyteCount;
   WriteSignalValue(m_vecViGEMObj[vIdx].mdfViGEM_FrameWriter, m_vecViGEMObj[vIdx].ETH_FrameRcvDataByteCount, eth_rcvDataByteCnt);

   UINT32 eth_DataLen = (INT32)UDP_PAYLOAD_SIZE;
   WriteSignalValue(m_vecViGEMObj[vIdx].mdfViGEM_FrameWriter, m_vecViGEMObj[vIdx].mdfViGEM_FrameDataLen, eth_DataLen);

   memcpy(&eth_DataByte, &pUdpRec->payload[0], UDP_PAYLOAD_SIZE);
   mdfErr = m_vecViGEMObj[vIdx].mdfViGEM_FrameWriter->WriteRawValue(m_vecViGEMObj[vIdx].mdfViGEM_FrameDataBytes, eth_DataByte,
                                                                    eth_DataLen, true);

   return mdfErr;
}

ErrorCode mdf_file_handler::write_VigemMDFsignal(const dvlMessageUnion *pDVLmsg)
{
   ErrorCode mdfErr    = eFileWriteError;
   bool f_channelMatch = false;

   if (m_MdfLibValid_Flag == false)
   {
      return mdfErr;
   }
   UINT32 CH_No = (pDVLmsg->info.messageType == DVL_MESSAGE_TYPE_CAN_FD) ? pDVLmsg->dvlCANFD.channel : pDVLmsg->dvlCAN.channel;
   unsigned char can_DataByte[CAN_MSG_DATA_BTYES]     = {0};
   unsigned char can_FDDataByte[CANFD_MSG_DATA_BTYES] = {0};
   INT64 xcan_timeStamp                               = 0;
   INT32 vIdx                                         = 0;

   m_vecViGEMObj.begin();
   for (vIdx = 0; vIdx < m_vecViGEMObj.size(); vIdx++)
   {
      if (m_vecViGEMObj[vIdx].vCANch_number == CH_No)
      {
         f_channelMatch = true;
         break;
      }
   }
   if (f_channelMatch == false)
   {
      if (eOK != CreateVigem_CANChGroup(CH_No))
      {
         return mdfErr;
      }
   }

   if (!m_vecViGEMObj[vIdx].mdfViGEM_FrameChGroup)
   {
      return mdfErr;
   }

   xcan_timeStamp = (INT64)pDVLmsg->info.timestamp;

   mdfErr = m_vecViGEMObj[vIdx].mdfViGEM_CANFrameWriter->SetTimeNs(xcan_timeStamp);

   UINT8 can_EDL = (pDVLmsg->info.messageType == DVL_MESSAGE_TYPE_CAN_FD) ? 1 : 0;
   WriteSignalValue(m_vecViGEMObj[vIdx].mdfViGEM_CANFrameWriter, m_vecViGEMObj[vIdx].pCAN_EDL, can_EDL);

   UINT8 can_BRS = (pDVLmsg->dvlCANFD.fd_brs == 1) ? 1 : 0;
   WriteSignalValue(m_vecViGEMObj[vIdx].mdfViGEM_CANFrameWriter, m_vecViGEMObj[vIdx].pCAN_BRS, can_BRS);

   UINT32 can_DLC = (pDVLmsg->info.messageType == DVL_MESSAGE_TYPE_CAN) ? pDVLmsg->dvlCAN.length : pDVLmsg->dvlCANFD.length;
   WriteSignalValue(m_vecViGEMObj[vIdx].mdfViGEM_CANFrameWriter, m_vecViGEMObj[vIdx].pCAN_DLC, can_DLC);

   UINT32 can_DataLen = (pDVLmsg->info.messageType == DVL_MESSAGE_TYPE_CAN) ? pDVLmsg->dvlCAN.length : pDVLmsg->dvlCANFD.length;
   WriteSignalValue(m_vecViGEMObj[vIdx].mdfViGEM_CANFrameWriter, m_vecViGEMObj[vIdx].mdfViGEM_FrameDataLen, can_DataLen);

   UINT32 can_ID = (pDVLmsg->info.messageType == DVL_MESSAGE_TYPE_CAN_FD) ? (CAN_EXT_ID_MASK & pDVLmsg->dvlCANFD.id) :
                                                                            (CAN_EXT_ID_MASK & pDVLmsg->dvlCAN.id);
   WriteSignalValue(m_vecViGEMObj[vIdx].mdfViGEM_CANFrameWriter, m_vecViGEMObj[vIdx].pCAN_ID, can_ID);

   UINT32 can_IDE = (pDVLmsg->info.messageType == DVL_MESSAGE_TYPE_CAN_FD) ? (0x01 & pDVLmsg->dvlCANFD.extFrame) :
                                                                             (0x01 & pDVLmsg->dvlCAN.extFrame);
   WriteSignalValue(m_vecViGEMObj[vIdx].mdfViGEM_CANFrameWriter, m_vecViGEMObj[vIdx].pCAN_IDE, can_IDE);

   UINT8 busType = (pDVLmsg->info.messageType == DVL_MESSAGE_TYPE_CAN) ? e_Bus_CAN : e_Bus_CANFD;

   if (busType == e_Bus_CAN)
   {
      memcpy(can_DataByte, &pDVLmsg->dvlCAN.data, CAN_MSG_DATA_BTYES);
      mdfErr = m_vecViGEMObj[vIdx].mdfViGEM_CANFrameWriter->WriteRawValue(m_vecViGEMObj[vIdx].mdfViGEM_CANFrameDataBytes,
                                                                          can_DataByte, CAN_MSG_DATA_BTYES, true);
   }
   else if (busType == e_Bus_CANFD)
   {
      memcpy(can_FDDataByte, &pDVLmsg->dvlCANFD.data, CANFD_MSG_DATA_BTYES);
      mdfErr = m_vecViGEMObj[vIdx].mdfViGEM_CANFrameWriter->WriteRawValue(m_vecViGEMObj[vIdx].mdfViGEM_CANFrameDataBytes,
                                                                          can_FDDataByte, CANFD_MSG_DATA_BTYES, true);
   }

   return eFileWriteError;
}
