load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "ipc_mss_h",
    srcs = [],
    hdrs = [
        "inc/ipc_mss.h",
    ],
    defines = [
    ],
    strip_include_prefix = "//software/r52/ipc/inc",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/ipc:ipc_data_h",
    ],
)

cc_library(
    name = "ipc_mss_lib",
    srcs = [
        "src/ipc_mss.c",
    ],
    hdrs = [],
    defines = select({
        "//software/bbe32/src:cdc_enable": ["CDC_ENABLE"],
        "//conditions:default": [],
    }),
    local_defines = select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }),
    strip_include_prefix = "//software/r52/ipc/src",
    visibility = ["//visibility:public"],
    deps = [
        ":ipc_mss_h",
        "//software/common/crc_calc:crc_calc_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_h",
        # "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP:SWC_CDD_XCP_Logging_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime",
        "//software/r52/dsp_setup:dsp_setup_h",
        "//software/r52/dsp_setup:dsp_setup_lib",
        "//software/r52/program_flow_monitor:program_flow_monitor_h",
        "@hilbb//module/_api:hil_communication_handler_h",
    ],
)

cc_library(
    name = "ipc_mss_unit_test_support_lib",
    hdrs = [
        "src/ipc_mss.c",
    ],
    strip_include_prefix = "//software/r52/ipc/src",
    visibility = ["//visibility:public"],
    deps = [
        ":ipc_mss_h",
        "//software/common/crc_calc:crc_calc_h",
        "//software/common/mmic:mmic_common_types_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP:SWC_CDD_XCP_Logging_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler:SWC_PLT_Radar_Alignment_Handler_h",
        "//software/r52/dsp_setup:dsp_setup_h",
        "@hilbb//module/_api:hil_communication_handler_h",
    ],
)
