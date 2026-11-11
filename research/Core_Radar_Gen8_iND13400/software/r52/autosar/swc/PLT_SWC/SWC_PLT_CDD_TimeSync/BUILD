load("@rules_cc//cc:defs.bzl", "cc_library")

exports_files(
    [
        "Source/SWC_PLT_CDD_TimeSync.c",
        "Source/SWC_PLT_CDD_TimeSync_Master.c",
    ],
    visibility = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync/test:__pkg__",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_TimeSync",
    srcs = [
        "Source/SWC_PLT_CDD_TimeSync.c",
        "Source/SWC_PLT_CDD_TimeSync_Master.c",
        "@SWC_PLT_Appl_TimeSync//Source:PLT_APPL_CDD_TimeSync.c",
        "@SWC_PLT_Appl_TimeSync//Source:PLT_APPL_CDD_TimeSync_test.c",
    ],
    hdrs = [],
    defines = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:VEH_AL_CAN_STANDALONE": [
            "AL_CAN_TSYNCH_DEFAULT",
        ],
        "//conditions:default": [],
    }),
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }) + select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_TimeSync_cfg_h",
        ":SWC_PLT_CDD_TimeSync_h",
        "//software/common/board_revision:board_revision_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj_h",
        "@Sensor_Position//:sensor_position_h",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_TimeSync_h",
    srcs = [],
    hdrs = [
        "@SWC_PLT_Appl_TimeSync//Include:PLT_APPL_CDD_TimeSync.h",
    ],
    defines = [],
    strip_include_prefix = "/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "@iND13400_autosar_sip//Components/StbM:StbM_h",
        "@reuse",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_TimeSync_cfg_h",
    srcs = [],
    hdrs = [
        "Include/SWC_PLT_CDD_TimeSync_cfg.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync/Include",
    visibility = ["//visibility:public"],
    deps = [
        "@iND13400_autosar_sip//Components/Gpt:gpt_h",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_TimeSync_source_support_lib",
    srcs = [],
    hdrs = [
        "Source/SWC_PLT_CDD_TimeSync.c",
        "Source/SWC_PLT_CDD_TimeSync_Master.c",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
)
