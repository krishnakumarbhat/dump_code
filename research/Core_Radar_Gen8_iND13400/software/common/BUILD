load("//tools/bazel/scripts:generate_stream_def.bzl", "generate_stream_def")
load("//tools/bazel/scripts:copy_to_dir.bzl", "copy_to_dir")

# -----------------------------------------------------------------
# Each of these stream defs point to a "generate_stream_def" below.
# -----------------------------------------------------------------
filegroup(
    name = "stream_defs",
    srcs = [
        ":alignment_stream",  # Stream 9
        ":cdc_stream",  # Stream 6
        ":debug_stream",  # Stream 7
        ":detection_debug_stream",  # Stream 15
        ":detection_stream",  # Stream 1
        ":down_selection_stream",  # Stream 21
        ":dra_stream",  # Stream 45
        ":header_stream",  # Stream 2
        ":hil_communication_stream",  # Stream 50
        ":id_stream",  # Stream 36
        ":mmic_stream",  # Stream 8
        ":radar_capability_stream",  # Stream 20
        ":rdd_debug_stream",  # Stream 44
        ":rdd_stream",  # Stream 4
        ":status_stream",  # Stream 3
        ":vid_stream",  # Stream 80 (rx stream)
        ":toi_stream",  # Stream 40
        ":toi_ds_stream",  # Stream 41
        ":vse_stream",  # Stream 5
        "//software/common/calibrations/smc:calib_stream_smc",
        "//software/common/calibrations/usc:calib_stream_usc",
    ] + select({
        "@emb_tracker_wrapper//:tracker_disabled": [],
        "@emb_tracker_wrapper//:partner_sensor": [],
        "//conditions:default": [
            ":sync_info_stream",  # Stream 120
            ":vehicle_info_stream",  # Stream 121
            ":tracker_info_stream",  # Stream 122
            ":timing_info_stream",  # Stream 123
            ":host_calibs_stream",  # Stream 124
            ":host_props_stream",  # Stream 125
            ":static_env_poly_stream",  # Stream 126
            ":functional_safety_faults_stream",  # Stream 127
            ":object_list_stream",  # Stream 128
            ":processed_detection_stream",  # Stream 129
            ":sensor_calib_stream",  # Stream 130
            ":trailer_detector_stream",  # Stream 131
            ":internal_trailer_detector_stream",  # Stream 132
            ":cv_trailer_stream",  # Stream 133
            ":internal_object_stream",  # Stream 134
            ":internal_cluster_stream",  # Stream 135
            ":internal_detection_hist_stream",  # Stream 136
            ":internal_reflection_buffer_stream",  # Stream 137
            ":internal_cwd_stream",  # Stream 138
            ":partner_sensor_stream",  # Stream 16
        ],
    }) + select({
        "//:Run_Feature_functions": [
            ":bsis_stream",  # Stream 160
            ":mois_stream",  # Stream 161
            ":olp_stream",  # Stream 162
        ],
        "//conditions:default": [],
    }),
    visibility = ["//visibility:public"],
)

# -----------------------------------------------------------------
# All of the stream logging files as well as the necessary
# includes are all copied to a temp folder so the StreamTool
# can generate all of the stream defs from that folder.
# -----------------------------------------------------------------
copy_to_dir(
    name = "copyStreamFilesToTemp",
    srcs = [
        "calib_stream.h",
        "debug_stream.h",
        "detection_stream.h",
        "detection_debug_stream.h",
        "down_selection_stream.h",
        "dynamic_stream_helper.h",
        "header_stream.h",
        "mmic_stream.h",
        "rdd_debug_stream.h",
        "status_stream.h",
        "cdc_stream.h",
        "stream_header.h",
        "vid_stream.h",
        "vse_stream.h",
        "//software/common/calibrations/smc:fg_smc_cal",
        "//software/common/calibrations/usc:fg_usc_cal",
        "@Calibration_Handler//:calib_handler/calibration.h",
        "@dabb//module/dyn_alignment/dyn_alignment_api:fg_dra_stream",
        "@sabb//module/static_alignment/static_alignment_api:fg_alignment_stream",
        "@rcbb//module/common:fg_radar_capability_stream",
        "@hilbb//module/_api:fg_hil_communication_stream",
        "@idbb//module/id_imp/_inc:fg_id_stream",
        "partner_sensor_stream.h",
    ] + select({
        "//:Run_Feature_functions": [
            "bsis_stream.h",
            "mois_stream.h",
            "olp_stream.h",
        ],
        "//conditions:default": [],
    }) + select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": [
            "//software/common/satellite_can_standalone_common:fg_rdd_stream",
            "//software/common/satellite_can_standalone_common:fg_toi_stream",
            "//software/common/satellite_can_standalone_common:fg_toi_ds_stream",
        ],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": [
            "//software/common/satellite_eth_high_det:fg_rdd_stream",
            "//software/common/satellite_eth_high_det:fg_toi_stream",
            "//software/common/satellite_eth_high_det:fg_toi_ds_stream",
        ],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": [
            "//software/common/satellite_can_standalone_common:fg_rdd_stream",
            "//software/common/satellite_can_standalone_common:fg_toi_stream",
            "//software/common/satellite_can_standalone_common:fg_toi_ds_stream",
        ],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": [
            "//software/common/satellite_can_standalone_common:fg_rdd_stream",
            "//software/common/satellite_can_standalone_common:fg_toi_stream",
            "//software/common/satellite_can_standalone_common:fg_toi_ds_stream",
        ],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": [
            "//software/common/satellite_eth_high_det:fg_rdd_stream",
            "//software/common/satellite_eth_high_det:fg_toi_stream",
            "//software/common/satellite_eth_high_det:fg_toi_ds_stream",
        ],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": [
            "//software/common/satellite_can_standalone_common:fg_rdd_stream",
            "//software/common/satellite_can_standalone_common:fg_toi_stream",
            "//software/common/satellite_can_standalone_common:fg_toi_ds_stream",
        ],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": [
            "//software/common/satellite_can_standalone_common:fg_rdd_stream",
            "//software/common/satellite_can_standalone_common:fg_toi_stream",
            "//software/common/satellite_can_standalone_common:fg_toi_ds_stream",
        ],
        "//conditions:default": [
            "//software/common/satellite_can_standalone_common:fg_rdd_stream",
            "//software/common/satellite_can_standalone_common:fg_toi_stream",
            "//software/common/satellite_can_standalone_common:fg_toi_ds_stream",
        ],
    }) + select({
        "@emb_tracker_wrapper//:tracker_disabled": [],
        "@emb_tracker_wrapper//:partner_sensor": [],
        "//conditions:default": [
            "@rotbb//emb_tracker:fg_tracker_streams",
            "@emb_tracker_wrapper//:emb_tracker_project_parameters.h",
        ],
    }),
    outputDir = "temp",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "UDPLoggingStreamHeaders",
    hdrs = [
        "af_common_data.h",
        "calib_stream.h",
        "cdc_stream.h",
        "debug_stream.h",
        "detection_debug_stream.h",
        "detection_stream.h",
        "down_selection_stream.h",
        "dynamic_stream_helper.h",
        "header_stream.h",
        "mmic_stream.h",
        "rdd_debug_stream.h",
        "status_stream.h",
        "stream_header.h",
        "vid_stream.h",
        "vse_stream.h",
        "partner_sensor_stream.h",
    ] + select({
        "//:Run_Feature_functions": [
            "bsis_stream.h",
            "mois_stream.h",
            "olp_stream.h",
        ],
        "//conditions:default": [],
    }),
    defines = [],
    strip_include_prefix = "//software/common",
    visibility = ["//visibility:public"],
    deps = [
        ":rdd_stream_h",
        ":stream_header_h",
        ":toi_ds_stream_h",
        ":toi_stream_h",
        "//software/common/calibrations/smc:radar_sw_config_h",
        "@dabb//module/dyn_alignment/dyn_alignment_api:dyn_align_module_h",
        "@idbb//module/id_imp/_inc:id_stream_header",
        "@rcbb//module/common:rc_stream_headers",
        "@reuse",
        "@reuse//:fixmac",
        "@sabb//module/static_alignment/static_alignment_api:static_alignment_algo_inc",
    ],
)

# ----------------------------------------------------------
# Stream versions (stream_ver) will need to be updated
# in this file when updated in the corresponding *_stream.h
# ----------------------------------------------------------
generate_stream_def(
    name = "detection_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "detection_stream.h",
    repeating_struct = "af_dets",
    stream_num = 1,
    stream_struct = "Detection_Stream_T",
    stream_ver = 200,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "rdd_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "rdd_stream.h",
    stream_num = 4,
    stream_struct = "Rdd_Stream_T",
    stream_ver = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": 21,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": 120,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": 21,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": 21,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": 120,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": 21,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": 21,
        "//conditions:default": 21,
    }),
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "toi_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "toi_stream.h",
    stream_num = 40,
    stream_struct = "TOI_Stream_T",
    stream_ver = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": 5,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": 106,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": 5,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": 5,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": 106,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": 5,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": 5,
        "//conditions:default": 5,
    }),
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "toi_ds_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "toi_ds_stream.h",
    stream_num = 41,
    stream_struct = "TOI_DS_Stream_T",
    stream_ver = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": 4,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": 105,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": 4,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": 4,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": 105,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": 4,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": 4,
        "//conditions:default": 4,
    }),
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "detection_debug_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "detection_debug_stream.h",
    repeating_struct = "af_debug_detections",
    stream_num = 15,
    stream_struct = "Detection_Debug_Stream_T",
    stream_ver = 200,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "hil_communication_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "hil_communication_stream.h",
    stream_num = 50,
    stream_struct = "HIL_Req_Resp_Command_T",
    stream_ver = 13,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "down_selection_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "down_selection_stream.h",
    repeating_struct = "af_ds_dets",
    stream_num = 21,
    stream_struct = "Down_selection_Stream_T",
    stream_ver = 200,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "mmic_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "mmic_stream.h",
    stream_num = 8,
    stream_struct = "MMIC_Stream_T",
    stream_ver = 25,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "debug_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "debug_stream.h",
    stream_num = 7,
    stream_struct = "Debug_Stream_T",
    stream_ver = 21,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "status_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "status_stream.h",
    stream_num = 3,
    stream_struct = "Status_Stream_T",
    stream_ver = 9,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "header_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "header_stream.h",
    stream_num = 2,
    stream_struct = "Header_Stream_T",
    stream_ver = 11,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "id_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "id_stream.h",
    stream_num = 36,
    stream_struct = "ID_Stream_T",
    stream_ver = 5,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "rdd_debug_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "rdd_debug_stream.h",
    stream_num = 44,
    stream_struct = "Rdd_Debug_Stream_T",
    stream_ver = 9,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "cdc_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "cdc_stream.h",
    stream_num = 6,
    stream_struct = "CDC_Stream_T",
    stream_ver = 1,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "vse_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "vse_stream.h",
    stream_num = 5,
    stream_struct = "Vse_Stream_T",
    stream_ver = 4,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "alignment_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "static_alignment_stream.h",
    stream_num = 9,
    stream_struct = "Static_Alignment_Log_Stream_T",
    stream_ver = 12,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "dra_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "Dynamic_alignment_stream.h",
    stream_num = 45,
    stream_struct = "Dynamic_Alignment_Log_Stream_T",
    stream_ver = 16,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "radar_capability_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "radar_capability_stream.h",
    stream_num = 20,
    stream_struct = "Radar_Capability_Stream_T",
    stream_ver = 53,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "vid_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "vid_stream.h",
    stream_num = 80,
    stream_struct = "Vid_Stream_T",
    stream_ver = 2,
    visibility = ["//visibility:public"],
)

# Feature Function Streams
generate_stream_def(
    name = "bsis_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "bsis_stream.h",
    stream_num = 160,
    stream_struct = "Bsis_Stream_T",
    stream_ver = 3,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "mois_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "mois_stream.h",
    stream_num = 161,
    stream_struct = "Mois_Stream_T",
    stream_ver = 2,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "olp_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "olp_stream.h",
    stream_num = 162,
    stream_struct = "Olp_Stream_T",
    stream_ver = 1,
    visibility = ["//visibility:public"],
)

# Generate tracker stream def .txt files
generate_stream_def(
    name = "sync_info_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 120,
    stream_struct = "Sync_Info_Stream_T",
    stream_ver = 3,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "vehicle_info_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 121,
    stream_struct = "Vehicle_Info_Stream_T",
    stream_ver = 10,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "tracker_info_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 122,
    stream_struct = "Tracker_Info_Stream_T",
    stream_ver = 10,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "timing_info_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 123,
    stream_struct = "Timing_Info_Stream_T",
    stream_ver = 22,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "host_calibs_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 124,
    stream_struct = "Host_Calibs_Stream_T",
    stream_ver = 3,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "host_props_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 125,
    stream_struct = "Host_Props_Stream_T",
    stream_ver = 2,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "static_env_poly_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 126,
    stream_struct = "Static_Env_Poly_Stream_T",
    stream_ver = 3,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "functional_safety_faults_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 127,
    stream_struct = "Functional_Safety_Faults_Stream_T",
    stream_ver = 13,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "object_list_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 128,
    stream_struct = "Object_List_StreamDef_T",
    stream_ver = 12,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "processed_detection_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 129,
    stream_struct = "Processed_Detection_StreamDef_T",
    stream_ver = 4,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "sensor_calib_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 130,
    stream_struct = "Sensor_Calib_StreamDef_T",
    stream_ver = 5,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "trailer_detector_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 131,
    stream_struct = "Trailer_Detector_Stream_T",
    stream_ver = 2,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "internal_trailer_detector_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 132,
    stream_struct = "Internal_Trailer_Detector_Stream_T",
    stream_ver = 4,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "cv_trailer_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 133,
    stream_struct = "Cv_Trailer_Stream_T",
    stream_ver = 4,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "internal_object_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 134,
    stream_struct = "Internal_Object_StreamDef_T",
    stream_ver = 37,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "internal_cluster_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 135,
    stream_struct = "Internal_Cluster_StreamDef_T",
    stream_ver = 5,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "internal_detection_hist_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 136,
    stream_struct = "Internal_Detection_Hist_StreamDef_T",
    stream_ver = 4,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "internal_reflection_buffer_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 137,
    stream_struct = "Internal_Reflection_Buffer_StreamDef_T",
    stream_ver = 1,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "internal_cwd_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "emb_tracker_stream_interface.h",
    stream_num = 138,
    stream_struct = "Internal_CWD_StreamDef_T",
    stream_ver = 3,
    visibility = ["//visibility:public"],
)

generate_stream_def(
    name = "partner_sensor_stream",
    generate_yml = True,
    logging_dir = ":copyStreamFilesToTemp",
    logging_file = "partner_sensor_stream.h",
    repeating_struct = "ps_dets",
    stream_num = 16,
    stream_struct = "Partner_Sensor_Stream_T",
    stream_ver = 3,
    visibility = ["//visibility:public"],
)

cc_library(
    name = "common",
    srcs = [
        "chandra_r52_isr.c",
    ],
    hdrs = [
        "chandra_r52_irq.h",
        "system_chandra.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "chandra_h",
    srcs = [
    ],
    hdrs = [
        "chandra_r52_irq.h",
        "system_chandra.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "radar_look_types",
    srcs = [],
    hdrs = [
        "radar_look_types.h",
    ],
    defines = [],
    implementation_deps = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_library(
    name = "stream_header_h",
    srcs = [],
    hdrs = [
        "stream_header.h",
    ],
    implementation_deps = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_library(
    name = "rdd_stream_h",
    srcs = [
    ],
    hdrs = [],
    defines = [
    ],
    strip_include_prefix = "//software/common",
    visibility = ["//visibility:public"],
    deps = [
        ":stream_header_h",
        "//software/common/calibrations/smc:radar_sw_config_h",
        "@reuse",
        "@spbb//common:common_h",
    ] + select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": ["//software/common/satellite_can_standalone_common:rdd_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": ["//software/common/satellite_eth_high_det:rdd_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": ["//software/common/satellite_can_standalone_common:rdd_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": ["//software/common/satellite_can_standalone_common:rdd_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": ["//software/common/satellite_eth_high_det:rdd_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": ["//software/common/satellite_can_standalone_common:rdd_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": ["//software/common/satellite_can_standalone_common:rdd_stream_module_h"],
        "//conditions:default": ["//software/common/satellite_can_standalone_common:rdd_stream_module_h"],
    }),
)

cc_library(
    name = "toi_stream_h",
    srcs = [
    ],
    hdrs = [],
    defines = [
    ],
    strip_include_prefix = "//software/common",
    visibility = ["//visibility:public"],
    deps = [
        ":stream_header_h",
        "//software/common/calibrations/smc:radar_sw_config_h",
        "@reuse",
        "@spbb//common:common_h",
    ] + select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": ["//software/common/satellite_can_standalone_common:toi_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": ["//software/common/satellite_eth_high_det:toi_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": ["//software/common/satellite_can_standalone_common:toi_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": ["//software/common/satellite_can_standalone_common:toi_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": ["//software/common/satellite_eth_high_det:toi_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": ["//software/common/satellite_can_standalone_common:toi_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": ["//software/common/satellite_can_standalone_common:toi_stream_module_h"],
        "//conditions:default": ["//software/common/satellite_can_standalone_common:toi_stream_module_h"],
    }),
)

cc_library(
    name = "toi_ds_stream_h",
    srcs = [
    ],
    hdrs = [],
    defines = [
    ],
    strip_include_prefix = "//software/common",
    visibility = ["//visibility:public"],
    deps = [
        ":stream_header_h",
        "//software/common/calibrations/smc:radar_sw_config_h",
        "@reuse",
        "@spbb//common:common_h",
    ] + select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": ["//software/common/satellite_can_standalone_common:toi_ds_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": ["//software/common/satellite_eth_high_det:toi_ds_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": ["//software/common/satellite_can_standalone_common:toi_ds_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": ["//software/common/satellite_can_standalone_common:toi_ds_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": ["//software/common/satellite_eth_high_det:toi_ds_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": ["//software/common/satellite_can_standalone_common:toi_ds_stream_module_h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": ["//software/common/satellite_can_standalone_common:toi_ds_stream_module_h"],
        "//conditions:default": ["//software/common/satellite_can_standalone_common:toi_ds_stream_module_h"],
    }),
)

cc_library(
    name = "cdc_stream_h",
    srcs = [
    ],
    hdrs = [
        "cdc_stream.h",
    ],
    defines = [
    ],
    strip_include_prefix = "//software/common",
    visibility = ["//visibility:public"],
    deps = [
        ":stream_header_h",
        "@reuse",
        "@spbb//common:common_h",
    ],
)

cc_library(
    name = "cdc_frame_interface_h",
    srcs = [],
    hdrs = [
        "cdc_frame_interface.h",
    ],
    strip_include_prefix = "//software/common",
    visibility = ["//visibility:public"],
    deps = [
        "@reuse",
    ],
)

cc_library(
    name = "rdd_debug_stream_h",
    srcs = [
    ],
    hdrs = [
        "rdd_debug_stream.h",
    ],
    defines = [
    ],
    strip_include_prefix = "//software/common",
    visibility = ["//visibility:public"],
    deps = [
        ":stream_header_h",
        "//software/common/calibrations/smc:radar_sw_config_h",
        "@reuse",
        "@spbb//common:common_h",
    ],
)

cc_library(
    name = "chandra_sfr_version_h",
    srcs = [
    ],
    hdrs = [
        "chandra_sfr_version.h",
    ],
    defines = [
    ],
    strip_include_prefix = "//software/common",
    visibility = ["//visibility:public"],
    deps = [
    ],
)
