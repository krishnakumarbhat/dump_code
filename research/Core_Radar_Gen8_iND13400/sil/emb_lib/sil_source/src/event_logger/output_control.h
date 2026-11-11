#pragma once

#include <filesystem>
#include <string>

#ifndef FLOAT32_T_DEFINED
using float32_t = float;
   #define FLOAT32_T_DEFINED
#endif
/*===========================================================================*\
 * Typedef's or Structure Declarations
\*===========================================================================*/
using Calib_Control_T = struct Calib_Control_Tag
{
   std::string filepath;
   std::string Enable_copy_from_xml;
};

using Tracker_Fix_Algorithm_T = struct Tracker_Fix_Algorithm_Tag
{
   std::string Algorithm_Control;
   std::string Ghost_Detections_Enable;
   std::string Tram_Fix_Enable;
   std::string Kerbstone_Fix_Enable;
   std::string SWW_Enable_KerbstoneSuppression;
   std::string SWW_Enable_ConcreteGuardrailSuppression;
};

using Emb_Lib_Output_XML_Trace_Files_T = struct Emb_Lib_Output_XML_Trace_Files_TAG
{
   uint8_t Vehicle_Info          = 0;
   uint8_t Mounting_Info         = 0;
   uint8_t MNR_blockage          = 0;
   uint8_t TD_blockage           = 0;
   uint8_t Self_Dets             = 0;
   uint8_t Opp_Dets              = 0;
   uint8_t scan_prints           = 0;
   uint8_t Cal_Error_Files       = 0;
   uint8_t Active_Faults         = 0;
   uint8_t UDP_Datas             = 0;
   uint8_t Curvi_Tracks          = 0;
   uint8_t Alignment_Info        = 0;
   uint8_t Z4_Z7B_Cust_Data      = 0;
   uint8_t ADC_Physical_Data     = 0;
   uint8_t Algo_Z7B_core         = 0;
   uint8_t Algo_Z7A_core         = 0;
   uint8_t Algo_Z4_core          = 0;
   uint8_t PATH_Tracking_Info    = 0;
   uint8_t LCDA_Info             = 0;
   uint8_t CTA_Info              = 0;
   uint8_t RECW_Info             = 0;
   uint8_t ASW_Info              = 0;
   uint8_t ABA_Info              = 0;
   uint8_t CDC_Errors_Info       = 0;
   uint8_t IPC_Error_Infor       = 0;
   uint8_t PCAN_Error_Info       = 0;
   uint8_t ENET_Frame_Error_Info = 0;
   uint8_t HIL_BB_Erors_Info     = 0;
   uint8_t OCG_info              = 0;
   uint8_t roadmodel_info        = 0;
   uint8_t Static_Objects        = 0;
   uint8_t Moving_Objects        = 0;
   uint8_t VSE_Data              = 0;
   uint8_t Interference_Dets     = 0;
   uint8_t Det_Data_Info         = 0;
   uint8_t Radar_Capability_Info = 0;
   uint8_t Det_Debug_Data_Info   = 0;
};

using Embedded_Report_Gen_T = struct Embedded_Report_Gen_TAG
{
   uint8_t Detection_Plots;
   uint8_t Tracker_Plots;
   uint8_t MNR_Plots;
   uint8_t Time_Throughput_Plots;
   uint8_t Feature_Function_Plots;
   uint8_t Vehicle_Info_Plots;
};

using Align_Anle_Quality_Hardcoded_Values_T = struct Align_Anle_Quality_Hardcoded_Values_TAG
{
   float Rear_Left_AA;
   uint8_t Rear_Left_AQF;
   float Rear_Right_AA;
   uint8_t Rear_Right_AQF;
   float Front_Right_AA;
   uint8_t Front_Right_AQF;
   float Front_Left_AA;
   uint8_t Front_Left_AQF;
   float Right_Center_AA;
   uint8_t Right_Center_AQF;
   float Left_Center_AA;
   uint8_t Left_Center_AQF;
};

using Speed_Compensation_Factor_Hardcoded_Values_T = struct Speed_Compensation_Factor_Hardcoded_Values_TAG
{
   float32_t Rear_Left_Speed_Compensation_Factor;
   float32_t Rear_Right_Speed_Compensation_Factor;
   float32_t Front_Right_Speed_Compensation_Factor;
   float32_t Front_Left_Speed_Compensation_Factor;
};
using DGPS_BOX_OFFSET_Hardcoded_Values_T = struct DGPS_BOX_OFFSET_Hardcoded_Values_TAG
{
   float32_t HOST_DGPS_BOX_OFFSET;
   float32_t TARGET_DGPS_BOX_OFFSET;
};
using Caf_Parameter_Hardcoded_Values_T = struct Caf_Parameter_Hardcoded_Values_TAG
{
   float32_t Rearaxel;
};

/* Autocalibration Values from XML File */
using ALIGNMENT_VALUES_EB_T = struct ALIGNMENT_VALUES_EB_TAG
{
   float ALIGNMENT_REAR_LEFT;
   float ALIGNMENT_REAR_RIGHT;
   float ALIGNMENT_FRONT_RIGHT;
   float ALIGNMENT_FRONT_LEFT;
};

/* KD / EOL Values from XML File */
using KD_EOL_VALUES_EB_T = struct KD_EOL_VALUES_EB_TAG
{
   float Activated;
   float Range;
   float Angle;
};

/* KD / EOL Values for all Radar */
using KD_EOL_VALUES_POS_EB_T = struct KD_EOL_VALUES_POS_EB_TAG
{
   KD_EOL_VALUES_EB_T Value_REAR_LEFT;
   KD_EOL_VALUES_EB_T Value_REAR_RIGHT;
   KD_EOL_VALUES_EB_T Value_FRONT_LEFT;
   KD_EOL_VALUES_EB_T Value_FRONT_RIGHT;
};

using Emb_Lib_Output_Control_T = struct Emb_Lib_Output_Control_TAG
{
   std::string SIL_Embedded_Library_Output_Control_XML_Version;
   std::string CUSTOMER_NAME          = "GPO";
   uint8_t STATISTICAL_REPORT         = 0;
   uint8_t CDC_SATURATION_CHECK       = 0;
   std::string CAN_TRANSMISSION       = "CAN_TX_DISABLED";
   std::string Veh_Data_CSV_Path      = "NONE";
   std::string TRACKER_INTERNALS      = "TRACKER_INTERNALS_ENABLED";
   std::string ALIGNMENT_INTERNALS    = "ALIGNMENT_INTERNALS_ENABLED";
   std::string PSP_MODULES            = "PSP_MODULES_ENABLED";
   std::string UDP_TRANSMISSION       = "UDP_TX_DISABLED";
   std::string XML_Trace_Files        = "XML_TRACE_DISBLED";
   std::string LOAD_TRACKER_INTERNALS = "ENABLE_TRACKER_MODE_INIT";
   std::string LOAD_ANERMA_ERROR      = "EXTERNAL_ERROR_XML_DISABLED";
   std::string USC_XML_Control        = "USC_NORMAL";
   std::string Suppress_Usc_Csv_log   = "DISABLE_USC_CSV_MODE";
   std::string Suppress_Usc_Xml_log   = "DISABLE_USC_XML_MODE";
   std::string SMC_XML_Control        = "SMC_NORMAL";
   std::string Suppress_Smc_Csv_log   = "DISABLE_SMC_CSV_MODE";
   std::string Suppress_Smc_Xml_log   = "DISABLE_SMC_XML_MODE";
   std::string USC_Calibration_Source = "LOG";
   std::string SMC_Calibration_Source = "DEFAULT";
   std::string PSC_Calibration_Source = "DEFAULT";
   uint8_t plp_algorithms             = 1;
   uint8_t plp_analysis               = 0;
   uint8_t Enable_Console_Prints      = 1;
   uint8_t Output_Symbol_Source       = 0;
   Emb_Lib_Output_XML_Trace_Files_T Output_XML_Trace_Files;
   uint8_t UDP_Log_Data_CSV       = 0;
   uint8_t CDC_Log_Data_CSV       = 0;
   uint8_t PCAN_DECODER_XML       = 0;
   uint8_t UDP_Log_Data_XML_TRACE = 0;
   std::string BIN_FILES          = "BIN_FILES_DISABLED";
   std::string XTRK_ENABLE        = "XTRK_FILES_DISABLED";
   std::string HDF_FILES          = "HDF_FILES_DISABLED";
   std::string CONSOLE_PRINTS     = "CONSOLE_PRINTS_DISABLED";
   std::string Auto_Align_Option  = "AUTO_ALIGN_DISABLED";
   Align_Anle_Quality_Hardcoded_Values_T Auto_Align_Hard_Coded_Values;
   std::string Speed_Compensation_Factor = "SPEED_COMPENSATION_FACTOR_HARD_CODED_VALUE_DISABLED";
   Speed_Compensation_Factor_Hardcoded_Values_T speed_compensation_fctr_values;
};

using SIL_Customer_CC_T = enum SIL_Customer_CC_TAG {
   enCUST_CC_VOLVO     = 0x01,
   enCUST_CC_BMW       = 0x02,
   enCUST_CC_GM        = 0x03,
   enCUST_CC_HYUNDAI   = 0x04,
   enCUST_CC_FORD      = 0x05,
   enCUST_CC_SGM       = 0x06,
   enCUST_CC_VGTT      = 0x07,
   enCUST_CC_AUDI      = 0x08,
   enCUST_CC_JLR       = 0x09,
   enCUST_CC_CHANGAN   = 0x0A,
   enCUST_CC_SCANIA    = 0x0B,
   enCUST_CC_GEELY     = 0x0C,
   enCUST_CC_HKMC_GEN2 = 0x0D,
   enCUST_CC_GWM       = 0x0E,
   enCUST_CC_HKMC_SRR5 = 0x0F,
   enCUST_CC_RNA_SRR5  = 0x20,
   enINVALID_CC_CUSTOMER
};

/*
SM_DISABLE::STATE MACHINE IS NOT EXECUTED IN RESIM, STATE MACHINE OUTPUTS FROM UDP/CORE0 ARE USED DIRECTLY IN RESIM.
SM_ENABLE_CAFF_MAGNA_A310_ENDURANCE::STATE MACHINE IS NOT EXECUTED IN RESIM AND FEATURE FUNCTION STATE MACHINE OUTPUT VALUES ARE
HARDCODE FOR LOGS BELOW SW::A470(CAFF VALUES AND STATE_MACHINE OUTPUTS ARE NOT AVAILABLE IN UDP) SM_ENABLE_CAFF_UDP::STATE MACHINE
IS EXECUTED  IN RESIM AND CAFF VALUES ARE PICKED UP FROM UDP(VALID CAFF ARE AVAILABLE IN UDP FROM SW : MARCH 25 2021)
SM_ENABLE_CAFF_HARDCODE_G01BLACK_G01GOLD_G31:: STATE MACHINE IS EXECUTED IN RESIM AND FF CAFF VALUES ARE PICKED UP FROM C FILE(CAFF
VALUES FROM SW MARCH 25 2021 ARE CORRUPTED)
*/
using SM_Config_Data = enum StateMachine_Config_Data {
   enSM_ENABLE_CAFF_UDP                           = 0x00,
   enSM_DISABLE                                   = 0x01,
   enSM_ENABLE_CAFF_MAGNA_A310_ENDURANCE          = 0x02,
   enSM_ENABLE_CAFF_HARDCODE_G01BLACK_G01GOLD_G31 = 0x03
};

/*===========================================================================*\
 * Local Function Prototypes
\*===========================================================================*/
const Emb_Lib_Output_Control_T &get_output_control();
std::filesystem::path get_output_path();
std::filesystem::path::string_type get_input_log_filename();
std::string get_xtrk_path();
uint8_t fill_output_control(const char *filepath);
void set_output_path(const std::filesystem::path &input_log_path);
