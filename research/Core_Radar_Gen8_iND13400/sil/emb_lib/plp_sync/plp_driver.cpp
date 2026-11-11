#include "plp_driver.h"
#include "mdf_read.h"
#include <cstring>
#include <filesystem>
#include <iomanip>
#include <sstream>
#include <unordered_set>
// #include <filesystem>
// #include <pthread.h>

// // External functions from the framework
// extern int Get_Radar_Position(void);
// extern SIL_RADAR_Input_Symbol_T* Get_Sil_Radar_Input_Symbol_Ptr(void);
// extern SIL_RADAR_Output_Data_T* Get_Sil_Radar_Output_Data_Ptr(void);

// Global variables
static bool one_time_call       = true;
uint16_t msgCount               = 0;
static bool foundFirstAlignment = false;
// MDF file handlers
mdf_file_handler *Read_Vigem_Can_Bus = nullptr;
int Plp_Sync_flag;
static std::string current_file_path;
static std::string next_file_path_holder;
static bool current_file_eof = true;

uint64_t StartTimeStamp_Bus_file = 0;
int End_of_Plp_Bus_file          = 0;
int Plp_File_Read_Bus_file       = 0;

// Data collections
std::map<uint16_t, uint8_t> plpAliveCount;

static std::vector<BufferedCANMessage> bufferedMessages;
static std::vector<BufferedCANMessage> stillBuffered;

// Map of CAN_ID -> Absolute timestamp (in µs or ns)
// static std::unordered_map<uint32_t, int64_t> canIdTimestamps;

// namespace fs           = std::filesystem;
// fs::path cwd           = fs::current_path();
// std::string cwd_string = cwd.string();

// std::string filename_FR = (cwd_string + "\\write_FR_mf4.txt"); //"C:\\logs\\STLA_NEW\\OUTPUT\\write_FR_mf4.txt";
// std::string filename_FL = (cwd_string + "\\write_FL_mf4.txt"); // "C:\\logs\\STLA_NEW\\OUTPUT\\write_FL_mf4.txt";
// std::string filename_FC = (cwd_string + "\\write_FC_mf4.txt"); // "C:\\logs\\STLA_NEW\\OUTPUT\\write_FC_mf4.txt";
// std::string filename_RL = (cwd_string + "\\write_RL_mf4.txt"); // "C:\\logs\\STLA_NEW\\OUTPUT\\write_RL_mf4.txt";
// std::string filename_RR = (cwd_string + "\\write_RR_mf4.txt"); // "C:\\logs\\STLA_NEW\\OUTPUT\\write_RR_mf4.txt";

void Radar_plp_Synchronizer(void)
{
   SIL_RADAR_Input_Symbol_T *radar_input = Get_Sil_Radar_Input_Symbol_Ptr();
   uint64_t udp_timestamp                = radar_input->MF4_Information.network_timeStamp[Get_Radar_Position() - 1];

   // to read CAN bus file path
   const char *plp_file_path = radar_input->fPath_BN_CALIFR;

   // Print the file path for debugging
   if (plp_file_path != nullptr)
   {
      if (one_time_call)
      {
         // std::cout << "[DEBUG]: Current file path from radar input is: " << plp_file_path << "\n";
         one_time_call = false;
      }
   }

   // check for a new file path and store it
   if (radar_input->f_readFilePath == READ_NEXT_LOG)
   {
      if (plp_file_path != nullptr)
      {
         // Check if the path is already stored to avoid redundant assignments
         if (next_file_path_holder.empty() || next_file_path_holder != plp_file_path)
         {
            next_file_path_holder = plp_file_path;
            // std::cout << "[INFO]: New file path detected. Storing for later use.\n";
            // std::cout << "[DEBUG]: The next file path to be opened is: " << next_file_path_holder << "\n";
         }
      }
      else
      {
         // std::cout << "[INFO]: Detected READ_NEXT_LOG but the file path is null.\n";
      }
   }

   // open new file only when the old one is completly processed
   if (IsCurrentFileEOF() && !next_file_path_holder.empty())
   {
      if (current_file_path.empty() || next_file_path_holder != current_file_path)
      {
         Clear_Can_ptr();
         // save_txt_file(filename, "[OPEN] : Reading new file", next_file_path_holder);
         PLP_Algo_Status_T status = Open_mdf4_Radar_input(next_file_path_holder);
         if (status == PLP_ALGO_SUCCESS)
         {
            // Reset state for the new file
            SetCurrentFileEOF(false);
            current_file_path = next_file_path_holder; // Store the new path as the current one
            next_file_path_holder.clear();
            // log_info("Successfully opened new file. Resuming processing.");
         }
         else
         {
            // log_error("Failed to open new file.");
            return;
         }
      }
      else
      {
         // File path is the same, so no action is needed.
         // Clear the holder to prevent reopening on subsequent loops.
         next_file_path_holder.clear();
      }
   }

   // Process the data from the currently open file
   if (!IsCurrentFileEOF())
   {
      Read_Vigem_CANBus(udp_timestamp);
   }
   else
   {
      // log_info("No new file to open or current file is not yet at EOF.");
   }

   // Additional error handling
   if (udp_timestamp == 0)
   { // A timestamp of 0 might indicate an issue
     // log_error("UDP timestamp is 0, potential issue.");
   }
}

static inline void debug_log_skip(const char *reason, int32_t channel_id, int32_t can_id, int64_t abs_ts, int64_t window_start,
                                  int64_t window_end, int64_t extra_delta)
{
   if (get_output_control().plp_analysis == 1)
   {
      std::cout << "[PLP-DBG] " << reason << " can=0x" << std::hex << can_id << std::dec << " ch=" << channel_id
                << " ts=" << abs_ts << " ws=" << window_start << " we=" << window_end << " dlt=" << extra_delta
                << " scan=" << Get_Current_Scan_Index() << " radar=" << std::string(Get_Radar_Position_Str()) << "\n";
   }
}

PLP_Algo_Status_T Open_mdf4_Radar_input(const std::string &file_path)
{
   // Use a reference for the global logger flag
   int &logger_flag = Plp_Sync_flag;
   uint8_t log_type = 0;

   if (file_path.empty())
   {
      logger_flag = e_MDF_PLP_FILE_EMPTY_PATH;
      // log_error("File path is empty.");
      return PLP_ALGO_FAIL;
   }

   if (Read_Vigem_Can_Bus == nullptr)
   {
      // log_info("No existing handler, creating a new one.");
      Read_Vigem_Can_Bus = new mdf_file_handler("Default");
      Read_Vigem_Can_Bus->Initialise();
   }
   else
   {
      // log_info("Reusing existing handler for new file.");
   }

   if (Read_Vigem_Can_Bus->m_MdfLibValid_Flag)
   {
      if (eOK !=
          Read_Vigem_Can_Bus->OpenVIGEMmdfFile(file_path.c_str(), &StartTimeStamp_Bus_file, true, Get_Radar_Position(), &log_type))
      {
         logger_flag = e_MDF_PLP_FILE_OPEN_ERROR;
         // log_error("Failed to open MDF file: " + file_path);
         return PLP_ALGO_FAIL;
      }

      logger_flag            = e_MDF_PLP_FILE_NO_ERR;
      End_of_Plp_Bus_file    = 0;
      Plp_File_Read_Bus_file = 1;
   }
   else
   {
      logger_flag = e_MDF_PLP_FILE_OPEN_ERROR;
      // log_error("MDF library is not valid.");
      return PLP_ALGO_FAIL;
   }

   return PLP_ALGO_SUCCESS;
}

bool Read_Vigem_CANBus(int64_t udp_timestamp)
{
   // Fetch CAN messages. The logic for setting timestamp limits is now expected
   // to be handled either by the calling function or inside Fetch_CAN_Msg().
   PLP_Algo_Status_T status = Fetch_CAN_Msg(udp_timestamp);
   if (status != PLP_ALGO_SUCCESS)
   {
      return true; // Return a success code or handle error
   }
   return false;
}

PLP_Algo_Status_T Fetch_CAN_Msg(int64_t udp_timestamp)
{
   int64_t window_start = udp_timestamp;                        // include pre-roll before UDP time
   int64_t window_end   = udp_timestamp + UPPER_LIMIT_UDP_TIME; // end relative to UDP time
   std::unordered_map<uint32_t, int64_t> canIdTimestamps;
   stillBuffered.clear();
   stillBuffered.reserve(bufferedMessages.size());

   for (auto &buffered : bufferedMessages)
   {
      int64_t abs_ts      = buffered.timestamp;
      uint32_t can_id     = buffered.canId;
      uint32_t channel_id = buffered.channelId;

      // For buffered messages, do not drop on window_start.
      // These were intentionally deferred; allow them to be considered now.
      if (abs_ts < window_start)
      {
         continue; // too old
      }

      if (abs_ts >= window_end)
      {
         // Future message: keep buffered for a future scan, but continue
         // processing remaining buffered messages that may fit in this window.
         debug_log_skip("buffer_future_buffered", channel_id, can_id, abs_ts, window_start, window_end, 0);
         stillBuffered.push_back(std::move(buffered));
         continue; // do not return early; process the rest of the buffer
      }

      auto it = canIdTimestamps.find(can_id);
      if (it != canIdTimestamps.end())
      {
         int64_t delta_can = abs_ts - it->second;

         if (0)
         {
            if (delta_can <= ACCEPTABLE_LIMIT)
            {
               saveSyncData(&buffered.msg, abs_ts, channel_id, can_id);
            }
            else
            {
               debug_log_skip("buffer_repeat_delta_buffered", channel_id, can_id, abs_ts, window_start, window_end, delta_can);
               stillBuffered.push_back(std::move(buffered)); // next scan
               continue;                                     // don't touch canIdTimestamps — mirrors Phase 2
            }
         }
         else
         {
            // duplicate, non-SYS_VEHICLE_STATUS -> drop, same as Phase 2
            stillBuffered.push_back(std::move(buffered));
            debug_log_skip("skip_duplicate_non_sys_vehicle_buffered", channel_id, can_id, abs_ts, window_start, window_end,
                           delta_can);
         }
      }
      else
      {
         saveSyncData(&buffered.msg, abs_ts, channel_id, can_id);
      }

      canIdTimestamps[can_id] = abs_ts;
   }

   bufferedMessages.swap(stillBuffered);
   stillBuffered.clear();

   /*
       CANBus_data   -> Can data
       CAN_Timestamp    -> can timestamp
       BUSCan_id  -> can ID
       Bus_ChannelId    -> buspec ID
   */
   for (;;)
   {
      void *can_bus_data    = nullptr;
      uint32_t can_id       = 0;
      uint32_t channel_id   = 0;
      int64_t CAN_Timestamp = 0;
      int64_t diff_time     = 0;

      // Use a single pointer and check against nullptr
      if (Read_Vigem_Can_Bus == nullptr)
      {
         // log_error("Read_Vigem_Can_Bus is NULL, cannot fetch messages.");
         return PLP_ALGO_FAIL;
      }

      ErrorCode error_plp = (Read_Vigem_Can_Bus->read_VigemMDF(&can_bus_data, &CAN_Timestamp, &can_id, &channel_id));

      if (error_plp == eReachedEndOfData)
      {
         SetCurrentFileEOF(true);
         // std::cout << "[INFO]: Reached end of MDF file.\n";
         return PLP_ALGO_SUCCESS;
      }

      if (error_plp != eOK)
      {
         // log_error("Error reading from MDF file.");
         return PLP_ALGO_FAIL;
      }

      if (!can_bus_data || !IsKnownCANID(channel_id, can_id))
      {
         continue;
      }

      int64_t abs_ts = AbsTimestamp(CAN_Timestamp);

      // --------- Skip old data (with grace for stragglers) ---------
      if (abs_ts < window_start)
      {
         // Accept first-occurrence stragglers slightly older than window_start
         // to prevent dropping valid signals that belong to this scan.
         auto it_old = canIdTimestamps.find(can_id);
         int64_t lag = window_start - abs_ts;
         if (it_old == canIdTimestamps.end() && lag <= ROLL_TIME)
         {
            dvlMessageUnion CAN_BusMsg = {0};
            memcpy(&CAN_BusMsg, can_bus_data, sizeof(dvlMessageUnion));
            saveSyncData(&CAN_BusMsg, abs_ts, channel_id, can_id);
            canIdTimestamps[can_id] = abs_ts;
            debug_log_skip("grace_accept_old_live", channel_id, can_id, abs_ts, window_start, window_end, -lag);
         }
         else
         {
            debug_log_skip("skip_old_live", channel_id, can_id, abs_ts, window_start, window_end, -lag);
         }
         continue; // older data beyond grace remains skipped
      }

      // --- Future message, stop loop and buffer ---
      if (abs_ts >= window_end)
      {
         BufferedCANMessage buffered;
         memcpy(&buffered.msg, can_bus_data, sizeof(dvlMessageUnion));
         buffered.timestamp = abs_ts;
         buffered.channelId = channel_id;
         buffered.canId     = can_id;
         bufferedMessages.push_back(std::move(buffered));
         debug_log_skip("buffer_future_live", channel_id, can_id, abs_ts, window_start, window_end, 0);
         return PLP_ALGO_SUCCESS; // stop reading, next scan will handle
      }

      // --- Repeated CAN ID logic ---
      auto it = canIdTimestamps.find(can_id);
      if (it != canIdTimestamps.end())
      {
         int64_t delta_can = abs_ts - it->second;

         if (0)
         {
            if (delta_can <=
                ACCEPTABLE_LIMIT) // less than 25ms → save now ; SYS_VEH_STATUS messages occurs twice in a cycle (25ms)
            {
               dvlMessageUnion CAN_BusMsg = {0};
               memcpy(&CAN_BusMsg, can_bus_data, sizeof(dvlMessageUnion));
               saveSyncData(&CAN_BusMsg, abs_ts, channel_id, can_id);
            }
            else // more than 10ms → buffer for next scan
            {
               BufferedCANMessage buffered;
               memcpy(&buffered.msg, can_bus_data, sizeof(dvlMessageUnion));
               buffered.timestamp = abs_ts;
               buffered.channelId = channel_id;
               buffered.canId     = can_id;
               bufferedMessages.push_back(std::move(buffered));
               debug_log_skip("buffer_repeat_delta_live", channel_id, can_id, abs_ts, window_start, window_end, delta_can);
               continue; // break; // stop reading, next scan will handle      // return PLP_ALGO_SUCCESS;
            }
         }
         else
         {
            // any other duplicate other than SYStime sync
            BufferedCANMessage buffered;
            memcpy(&buffered.msg, can_bus_data, sizeof(dvlMessageUnion));
            buffered.timestamp = abs_ts;
            buffered.channelId = channel_id;
            buffered.canId     = can_id;
            bufferedMessages.push_back(std::move(buffered));
            debug_log_skip("skip_duplicate_non_sys_vehicle", channel_id, can_id, abs_ts, window_start, window_end, delta_can);
            continue;
         }
      }
      else
      {
         // first occurrence → save
         dvlMessageUnion CAN_BusMsg = {0};
         memcpy(&CAN_BusMsg, can_bus_data, sizeof(dvlMessageUnion));
         saveSyncData(&CAN_BusMsg, abs_ts, channel_id, can_id);
      }

      canIdTimestamps[can_id] = abs_ts;
   }
   return PLP_ALGO_FAIL;
}

int64_t AbsTimestamp(int64_t TimeStamp)
{
   return (int64_t)(StartTimeStamp_Bus_file) + TimeStamp;
}

void PLP_output_logger(Can_FD_ID_Struct_T *can_fd_data)
{
   SIL_RADAR_Output_Data_T *Sil_output_plp = Get_Sil_Radar_Output_Data_Ptr();
   unsigned int &count                     = Sil_output_plp->dvl_payload_out.msg_count;
   const uint64_t step_ns                  = STEP_TIME; // 1 ms

   int found_idx      = -1;
   uint64_t max_ts_ns = 0;

   for (unsigned int i = 0; i < count && i < MAX_CAN_MESSAGES; ++i)
   {
      auto &msg = Sil_output_plp->dvl_payload_out.dvl[i].dvlCANFD;

      if (msg.info.timestamp > max_ts_ns)
         max_ts_ns = msg.info.timestamp;

      if (msg.id == can_fd_data->Can_Id)
      {
         found_idx = static_cast<int>(i);
         break;
      }
   }

   if (found_idx >= 0)
   {
      auto &msg = Sil_output_plp->dvl_payload_out.dvl[found_idx].dvlCANFD;
      memcpy(msg.data, can_fd_data->Can_Data, sizeof(can_fd_data->Can_Data));
      return;
   }

   // Exception for time sync message (CAN_ID : 0x01)
   if (can_fd_data->Can_Id == SYS_TIME_SYNC)
   {
      return;
   }

   // New message ID from latest DBC: append manually
   if (count >= MAX_CAN_MESSAGES)
   {
      return;
   }

   auto &new_msg            = Sil_output_plp->dvl_payload_out.dvl[count].dvlCANFD;
   new_msg.id               = can_fd_data->Can_Id;
   new_msg.channel          = can_fd_data->channelID;
   new_msg.length           = can_fd_data->Can_FD_DLC;
   new_msg.info.messageSize = can_fd_data->Can_FD_DLC;
   new_msg.info.messageType = MESSAGE_TYPE_CAN_FD;
   new_msg.info.timestamp   = (max_ts_ns == 0ULL) ? StartTimeStamp_Bus_file : (max_ts_ns + step_ns);
   memcpy(new_msg.data, can_fd_data->Can_Data, sizeof(can_fd_data->Can_Data));

   ++count;

   /*    // plp analysis
      if (get_output_control().plp_analysis == 1)
      {
         std::string radar_name = std::string(Get_Radar_Position_Str());
         int scan_index         = Get_Current_Scan_Index();

         // Ensure folder structure under get_output_path(): <out>\DVL\<RADAR>
         std::filesystem::path base = get_output_path();
         std::filesystem::path dir  = base / "DVL" / radar_name;
         std::error_code ec;
         std::filesystem::create_directories(dir, ec);

         // Create a per-radar CSV file name
         std::filesystem::path csv_path_fs = dir / "plp_analysis.csv";
         std::string csv_path              = csv_path_fs.string();
         std::ofstream csv(csv_path, std::ios::app);
         if (!csv.is_open())
         {
            // Fallback to current directory with per-radar filename
            csv_path = std::string("plp_analysis_") + radar_name + ".csv";
            csv.open(csv_path, std::ios::app);
         }

         if (csv.is_open())
         {
            static std::unordered_set<std::string> s_printed_paths;
            if (s_printed_paths.insert(csv_path).second)
            {
               std::cout << "[INFO]: PLP analysis CSV path: " << csv_path << "\n";
            }

            bool need_header = false;
            std::error_code fec;
            // Write header only if file doesn't exist or is empty
            if (!std::filesystem::exists(csv_path_fs, fec))
            {
               need_header = true;
            }
            else
            {
               auto sz     = std::filesystem::file_size(csv_path_fs, fec);
               need_header = (!fec && sz == 0);
            }
            if (need_header)
            {
               csv << "scan_index,radar,can_id,channel,length,timestamp,data_hex\n";
            }

            auto &msg = Sil_output_plp->dvl_payload_out.dvl[i].dvlCANFD;

            // Build data_hex as space-separated uppercase two-digit bytes
            std::ostringstream data_hex;
            for (int b = 0; b < msg.length && b < 64; ++b)
            {
               if (b > 0)
                  data_hex << ' ';
               data_hex << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned
      int>(msg.data[b]);
            }

            double timestamp_s = static_cast<double>(msg.info.timestamp - StartTimeStamp_Bus_file) / 1e9;
            csv << scan_index << "," << radar_name << "," << std::showbase << std::uppercase << std::hex << msg.id << std::dec <<
      ","
                << msg.channel << "," << msg.length << "," << std::fixed << std::setprecision(9) << timestamp_s << ","
                << data_hex.str() << "\n";
            csv.close();
         }
      }
    */
   // std::cout << "PLP_output_logger: Could not find raw message for processed CAN ID 0x" << std::hex << can_fd_data->Can_Id
   //           << ". Processed data will be discarded.\n";
}

void saveSyncData(dvlMessageUnion *bytePtr, INT64 timestamp_ns, INT32 busSpecid, INT32 canID)
{
   SIL_RADAR_Output_Data_T *Sil_output_plp = Get_Sil_Radar_Output_Data_Ptr();

   if (busSpecid == can_channel_FLR)
   {
      if (Get_Radar_Position() == FRONT_CENTER)
      {
         if (knownFrontCenterCANIDs.find(canID) != knownFrontCenterCANIDs.end())
         {
            memcpy(&Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.data, bytePtr, sizeof(uint8_t) * 64);
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.id               = canID;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.channel          = busSpecid;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.length           = CAN_FD_LENGTH;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.timestamp   = timestamp_ns;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.messageSize = CAN_FD_LENGTH;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.messageType = MESSAGE_TYPE_CAN_FD;
            msgCount++;
            // save_txt_file(filename_FC, "[LOGGING] : the can id saved is ", timestamp_ns, busSpecid, canID,
            //               timestamp_ns - StartTimeStamp_Bus_file);
         }
      }
   }
   else if (busSpecid == can_channel_FL)
   {
      if (Get_Radar_Position() == FRONT_LEFT)
      {
         if (knownFrontLeftCANIDs.find(canID) != knownFrontLeftCANIDs.end())
         {
            memcpy(&Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.data, bytePtr, sizeof(uint8_t) * 64);
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.id               = canID;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.channel          = busSpecid;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.length           = CAN_FD_LENGTH;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.timestamp   = timestamp_ns;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.messageSize = CAN_FD_LENGTH;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.messageType = MESSAGE_TYPE_CAN_FD;
            msgCount++;
            // save_txt_file(filename_FL, "[LOGGING] : the can id saved is ", timestamp_ns, busSpecid, canID,
            //               timestamp_ns - StartTimeStamp_Bus_file);
         }
      }
      // if (Get_Radar_Position() == FRONT_RIGHT)
      // {
      //    if (knownFrontRightCANIDs.find(canID) != knownFrontRightCANIDs.end())
      //    {
      //       memcpy(&Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.data, bytePtr, sizeof(uint8_t) * 64);
      //       Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.id               = canID;
      //       Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.channel          = busSpecid;
      //       Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.length           = CAN_FD_LENGTH;
      //       Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.timestamp   = timestamp_ns;
      //       Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.messageSize = CAN_FD_LENGTH;
      //       Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.messageType = MESSAGE_TYPE_CAN_FD;
      //       msgCount++;
      //       // save_txt_file(filename_FR, "[LOGGING] : the can id saved is ", timestamp_ns, busSpecid, canID,
      //       //               timestamp_ns - StartTimeStamp_Bus_file);
      //    }
      // }
   }
   else if (busSpecid == can_channel_RL)
   {
      if (Get_Radar_Position() == REAR_LEFT)
      {
         if (knownRearLeftCANIDs.find(canID) != knownRearLeftCANIDs.end())
         {
            memcpy(&Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.data, bytePtr, sizeof(uint8_t) * 64);
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.id               = canID;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.channel          = busSpecid;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.length           = CAN_FD_LENGTH;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.timestamp   = timestamp_ns;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.messageSize = CAN_FD_LENGTH;
            Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.messageType = MESSAGE_TYPE_CAN_FD;
            msgCount++;
            // save_txt_file(filename_RL, "[LOGGING] : the can id saved is ", timestamp_ns, busSpecid, canID,
            //               timestamp_ns - StartTimeStamp_Bus_file);
         }
      }
      // if (Get_Radar_Position() == REAR_RIGHT)
      // {
      //    if (knownRearRightCANIDs.find(canID) != knownRearRightCANIDs.end())
      //    {
      //       memcpy(&Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.data, bytePtr, sizeof(uint8_t) * 64);
      //       Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.id               = canID;
      //       Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.channel          = busSpecid;
      //       Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.length           = CAN_FD_LENGTH;
      //       Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.timestamp   = timestamp_ns;
      //       Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.messageSize = CAN_FD_LENGTH;
      //       Sil_output_plp->dvl_payload_out.dvl[msgCount].dvlCANFD.info.messageType = MESSAGE_TYPE_CAN_FD;
      //       msgCount++;
      //       // save_txt_file(filename_RR, "[LOGGING] : the can id saved is ", timestamp_ns, busSpecid, canID,
      //       //               timestamp_ns - StartTimeStamp_Bus_file);
      //    }
      // }
   }

   Sil_output_plp->dvl_payload_out.msg_count = msgCount;

   if (msgCount >= 499)
      msgCount = 0;
}

void reset_output_dvl_payload(void)
{
   // clear the output dvl payload and reset the counters to 0
   SIL_RADAR_Output_Data_T *Sil_output_plp = Get_Sil_Radar_Output_Data_Ptr();
   memset(&Sil_output_plp->dvl_payload_out, 0, sizeof(DVL_PAYLOAD_T));
   msgCount = 0;
}

void SetCurrentFileEOF(bool status)
{
   current_file_eof = status;
}

bool IsCurrentFileEOF()
{
   // This function would contain the real logic to check if the file reader is at the end of the file.
   return current_file_eof;
}

void Clear_Can_ptr(void)
{
   if (Read_Vigem_Can_Bus)
   {
      delete Read_Vigem_Can_Bus;
      Read_Vigem_Can_Bus = nullptr;
      // log_info("Cleared and deleted a single CAN handler pointer.");
   }
}

void log_info(const std::string &msg)
{
   std::cout << "[INFO]: " << msg << "\n";
}

void log_error(const std::string &msg)
{
   std::cout << "[ERROR] : " << msg << "\n";
}

void save_txt_file(const std::string &filename, const std::string &message, INT64 timestamp_ns, INT32 busSpecid, INT32 canID,
                   INT64 diff_time)
{
   std::ofstream outputfile(filename, std::ios::app);
   if (!outputfile.is_open())
      std::cout << "[INFO]: couldnt write into the file \n";

   std::stringstream ss;
   ss << message << " , Canid : " << canID << " , buspecid : " << busSpecid << " , timestamp : " << timestamp_ns
      << " , delta time : " << diff_time << ", SCANINDEX : " << Get_Current_Scan_Index()
      << ", RADAR : " << std::string(Get_Radar_Position_Str()) << "\n";

   outputfile << ss.str();
   outputfile.close();
}

void save_txt_file(const std::string &filename, const std::string &message)
{
   std::ofstream outputfile(filename, std::ios::app);
   if (!outputfile.is_open())
      std::cout << "[INFO]: couldnt write into the file \n";

   std::stringstream ss;
   ss << message << "\n";

   outputfile << ss.str();
   outputfile.close();
}

void save_txt_file(const std::string &filename, const std::string &message, const std::string &message1)
{
   std::ofstream outputfile(filename, std::ios::app);
   if (!outputfile.is_open())
      std::cout << "[INFO]: couldnt write into the file \n";

   std::stringstream ss;
   ss << message << " " << message1 << "\n";

   outputfile << ss.str();
   outputfile.close();
}

void save_txt_file(const std::string &filename, const std::string &message, uint32_t can_id)
{
   std::ofstream outputfile(filename, std::ios::app);
   if (!outputfile.is_open())
      std::cout << "[INFO]: couldnt write into the file \n";

   std::stringstream ss;
   ss << message << " " << can_id << ", SCANINDEX : " << Get_Current_Scan_Index()
      << ", RADAR : " << std::string(Get_Radar_Position_Str()) << "\n";

   outputfile << ss.str();
   outputfile.close();
}

bool IsKnownCANID(int32_t channel_id, int32_t can_id)
{
   Radar_Position radarPos = Get_Radar_Position();

   if (channel_id == can_channel_FLR)
   {
      return (radarPos == FRONT_CENTER && knownFrontCenterCANIDs.count(can_id));
   }

   else if (channel_id == can_channel_FLRVcan)
   {
      return (radarPos == FRONT_CENTER && knownFrontCenterVcanCANIDs.count(can_id));
   }

   else if (channel_id == can_channel_FL)
   {
      if (radarPos == FRONT_LEFT)
         return knownFrontLeftCANIDs.count(can_id);
      // else if (radarPos == FRONT_RIGHT)
      //    return knownFrontRightCANIDs.count(can_id);
   }

   else if (channel_id == can_channel_RL)
   {
      if (radarPos == REAR_LEFT)
         return knownRearLeftCANIDs.count(can_id);
      // else if (radarPos == REAR_RIGHT)
      //    return knownRearRightCANIDs.count(can_id);
   }

   return false; // Not a known ID for this radar/channel
}
