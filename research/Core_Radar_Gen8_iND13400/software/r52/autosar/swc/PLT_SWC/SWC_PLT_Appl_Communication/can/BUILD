load("@emb_tracker_wrapper//:emb_tracker_project_profile.bzl", "EMB_TRACKER_PROJECT_PROFILE")

exports_files(
    [
        "can_rx_msgs.c",
        "can_rx_msgs.h",
        "can_signals.h",
        "can_tx_msgs.c",
        "can_tx_msgs.h",
        "can_tx_msgs_al.c",
        "can_tx_msgs_al.h",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "can_tx_h",
    srcs = [
    ],
    hdrs = [
        "can_rx_msgs.h",
        "can_signals.h",
        "can_tx_msgs.h",
    ] + select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:VEH_AL_CAN_STANDALONE": ["can_tx_msgs_al.h"],
        "//conditions:default": [],
    }),
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/can/",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/dsp_setup:dsp_setup_h",
    ],
)

cc_library(
    name = "can_tx",
    srcs = [
        "can_rx_msgs.c",
        "can_tx_msgs.c",
    ],
    hdrs = [],
    copts = [
    ],
    defines = EMB_TRACKER_PROJECT_PROFILE().TRACKER_ENABLED_DEFINES,
    local_defines = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:VEH_AL_CAN_STANDALONE": ["VEH_AL_CAN_STANDALONE"],
        "//conditions:default": [],
    }),
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/can/",
    visibility = ["//visibility:public"],
    deps = [
        ":can_tx_h",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/ipc:ipc_mss_lib",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler:SWC_PLT_Radar_Alignment_Handler_h",
        "@Gen8_iND13400//software/common/calibrations/smc:smc_h",
        "@Gen8_iND13400//software/common/calibrations/usc:usc_h",
        "@Gen8_iND13400//software/common/versions",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        # "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        # "@Gen8_iND13400//software/r52/dsp_setup: ",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging:SWC_PLT_CDD_LOGGING_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync:SWC_PLT_CDD_ECUSync_h",
        "//software/common/ipc:ipc_data_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        "@reuse",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "can_tx_al",
    srcs = ["can_tx_msgs_al.c"],
    hdrs = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/can/",
    visibility = ["//visibility:public"],
    deps = [
        ":can_tx_h",
        "//software/common/ipc:ipc_data_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/ipc:ipc_mss_lib",
        "@reuse",
    ],
)

cc_library(
    name = "can_tx_ut_support_lib",
    srcs = [
    ],
    hdrs = [
        "can_tx_msgs.c",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/can/",
    visibility = ["//visibility:public"],
    deps = [
        ":can_tx_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
    ],
)

cc_library(
    name = "can_rx_ut_support_lib",
    srcs = [
    ],
    hdrs = [
        "can_rx_msgs.c",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/can/",
    visibility = ["//visibility:public"],
    deps = [
        ":can_tx_h",
        "//software/r52/ipc:ipc_mss_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@Sensor_Position//:sensor_position",
    ],
)
