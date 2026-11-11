load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "PLT_Appl_PlatformTime_h",
    srcs = [],
    hdrs = ["Include/platformtime.h"],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/Include",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_PlatformTime_cfg_h",
        "@iND13400_autosar_sip//Components/Os:Os_h",
    ],
)

cc_library(
    name = "SWC_PLT_PlatformTime_cfg_h",
    srcs = [],
    hdrs = ["Include/SWC_PLT_Appl_PlatformTime_cfg.h"],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "@reuse",
    ],
)

cc_library(
    name = "SWC_PLT_PlatformTime_unit_test_support_lib",
    hdrs = [
        "Source/SWC_PLT_Appl_PlatformTime.c",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":PLT_Appl_PlatformTime_h",
        ":SWC_PLT_PlatformTime_cfg_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@build_config//:chandra_sfr_h",
        "@iND13400_autosar_sip//Components/LdCom/Implementation:LdCom",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_PlatformTime",
    srcs = [
        "Source/SWC_PLT_Appl_PlatformTime.c",
        "Source/SWC_PLT_Appl_PlatformTime_Test.c",
    ],
    hdrs = [],
    defines = [],
    local_defines = select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }) + select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":PLT_Appl_PlatformTime_h",
        ":SWC_PLT_PlatformTime_cfg_h",
        "//software/common/versions:versions_hdrs",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "@build_config//:chandra_sfr_h",
        "@iND13400_autosar_sip//Components/LdCom/Implementation:LdCom_h",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)

exports_files(
    [
        "Source/SWC_PLT_Appl_PlatformTime.c",
    ],
    visibility = ["//visibility:public"],
)
