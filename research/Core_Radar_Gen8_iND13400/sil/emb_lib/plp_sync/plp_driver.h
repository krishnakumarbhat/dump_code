#ifndef PLP_DRIVER_H
#define PLP_DRIVER_H

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <stdint.h>
#include <string>
#include <unordered_map>
#include <vector>

#ifdef __WIN32
   #include <direct.h>
#else
   #include <sys/stat.h>
   #include <sys/types.h>
#endif

#include "fixmac.h"
#include "mdf_read.h"
#include "output_control.h"
#include "sil_output_symbol.h"
#include "sil_wrapper_common.h"

#include "can_message_id.h"

using namespace std;

// Constants
#define MAX_DVL_MESSAGES      500
#define RADAR_PLP_SYNC_ENABLE 0
#define READ_NEXT_LOG         1
#define PLP_ANALYSIS_ENABLE   1

#define MESSAGE_TYPE_CAN_FD (3)
#define CAN_FD_LENGTH       64

#define UPPER_LIMIT_UDP_TIME ((INT64)55000000) // +65ms: ~50ms scan + margin
#define ACCEPTABLE_LIMIT     ((INT64)40000000) // 40ms to accomodate the repeating messages like NM in same scan index
#define ROLL_TIME            ((INT64)5000000)  // 5ms pre-roll
#define STEP_TIME            ((INT64)1000000)  // 1ms

#ifdef _WIN32
   #define MAX_FILE_PATH 243
#elif __linux__
   #define MAX_FILE_PATH 4096
#endif

struct BufferedCANMessage
{
   dvlMessageUnion msg;
   int64_t timestamp;
   UINT32 channelId;
   UINT32 canId;
};

typedef struct Can_FD_ID_Struct_Tag
{
   uint32_t Can_Id;
   uint8_t Can_Data[64];
   uint8_t Can_FD_Flag;
   uint8_t Can_FD_DLC;
   uint32_t channelID;
} Can_FD_ID_Struct_T;

// sensor val define
#define PLP_SENSOR      4
#define PLP_TRIGER      3
#define VCAN_PLP_SENSOR 4

// Status enums
typedef enum
{
   PLP_ALGO_SUCCESS,
   PLP_ALGO_FAIL,
   PLP_FLAG_TRASITION_FAIL,
   PLP_FLAG_TRASITION_SUCCESS,
   PLP_FLAG_EOF
} PLP_Algo_Status_T;

typedef enum
{
   e_MDF_TIMESTAMP_UNKNOWN_ERR      = 0,
   e_MDF_TIMESTAMP_NO_ERR           = 1,
   e_MDF_TIMESTAMP_NEGATIVE         = 2,
   e_MDF_TIMESTAMP_START_TIME_ERROR = 3,
   e_MDF_TIMESTAMP_IN_SYNC          = 4,
   e_MDF_TIMESTAMP_OUT_OF_SYNC      = 5
} MDF_Time_Status_T;

typedef enum
{
   e_MDF_PLP_FILE_UNKNOWN_ERR           = 0,
   e_MDF_PLP_FILE_NO_ERR                = 1,
   e_MDF_PLP_FILE_NEGATIVE_TIMESTAMP    = 2,
   e_MDF_PLP_FILE_EMPTY_PATH            = 3,
   e_MDF_PLP_FILE_TIMESTAMP_ARRAY_ERR   = 4,
   e_MDF_PLP_FILE_FILE_TRANSITION_ERR   = 5,
   e_MDF_PLP_FILE_OPEN_ERROR            = 6,
   e_MDF_PLP_FILE_ZERO_TIME_STAMP_ERROR = 7,
   e_MDF_PLP_DETECTION_HDR_TS_ZERO      = 8
} PLP_Sync_Status_T;

// CAN data structure
struct CAN_Data
{
   uint32_t canID;
   int64_t CANTimestamp;
   uint16_t CAN_SCANIndex;
};

struct CANMessageKey
{
   UINT32 channelId;
   UINT32 canId;
   int64_t timestamp;

   /**
    * @brief Comparison operator to enable storage in std::set.
    *
    * Compares messages first by channelId, then canId, and finally by timestamp.
    */
   bool operator<(const CANMessageKey &other) const
   {
      if (channelId != other.channelId)
         return channelId < other.channelId;
      if (canId != other.canId)
         return canId < other.canId;
      return timestamp < other.timestamp;
   }
};

// Global variables
extern std::vector<CAN_Data> vecCanInfo;
extern std::map<uint16_t, CAN_Data> plpCANInfo;
extern std::map<uint16_t, CAN_Data> plpCANInfo_prev;
extern std::map<uint16_t, CAN_Data> plpCANInfo_repeated;

// Core synchronization functions
void Radar_plp_Synchronizer(void);
PLP_Algo_Status_T Open_mdf4_Radar_input(const std::string &file_path);
void SetCurrentFileEOF(bool status);
bool IsCurrentFileEOF();
void log_info(const std::string &msg);
void log_error(const std::string &msg);
PLP_Algo_Status_T Fetch_CAN_Msg(int64_t udp_timestamp);
bool Read_Vigem_CANBus(int64_t udp_timestamp);

void Clear_Can_ptr(void);
int64_t AbsTimestamp(int64_t TimeStamp);
void PLP_output_logger(Can_FD_ID_Struct_T *can_fd_data);
void reset_output_dvl_payload(void);

void saveSyncData(dvlMessageUnion *bytePtr, INT64 timestamp_ns, INT32 busSpecid, INT32 canID);

// function overloading
void save_txt_file(const std::string &filename, const std::string &message, INT64 timestamp_ns, INT32 busSpecid, INT32 canID,
                   INT64 diff_time);
void save_txt_file(const std::string &filename, const std::string &message);
void save_txt_file(const std::string &filename, const std::string &message, const std::string &message1);
void save_txt_file(const std::string &filename, const std::string &message, uint32_t can_id);

bool IsKnownCANID(int32_t channel_id, int32_t can_id);

#endif // PLP_DRIVER_H
