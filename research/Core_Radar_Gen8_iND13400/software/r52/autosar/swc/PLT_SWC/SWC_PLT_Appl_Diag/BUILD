load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Platform_Diag_Cfg_h",
    srcs = [],
    hdrs = [
        "Include/Platform_Diag_Cfg.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag/Include",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "Platform_Diag_Callout_h",
    srcs = [],
    hdrs = [
        "Include/Platform_Diag_Callout.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag:Platform_Diag_Cfg_h",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_Diag",
    srcs = [
        "Source/Platform_Diag_Callout.c",
        "Source/SWC_PLT_Appl_Diag.c",
        "Source/SWC_PLT_Appl_Diag_Test.c",
    ],
    hdrs = [],
    defines = [],
    local_defines = select({
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@reuse",
        ":SWC_PLT_Appl_Diag_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag:Platform_Diag_Callout_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag:Platform_Diag_Cfg_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        # "//software/app/mss/mcal/modules/autosar_include:autosar_include_h",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
    ],
)

cc_library(
    name = "Platform_Diag_Callout_unit_test_support_lib",
    hdrs = [
        "Source/Platform_Diag_Callout.c",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_Diag_h",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_Diag_unit_test_support_lib",
    hdrs = [
        "Source/SWC_PLT_Appl_Diag.c",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_Diag_h",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_Diag_h",
    srcs = [],
    hdrs = ["@SWC_PLT_Appl_Diag//:Include/SWC_PLT_Appl_Diag.h"],
    defines = [],
    strip_include_prefix = "/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/calibrations/psc:psc_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Calibration:Diagnostic_Calib_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag:Platform_Diag_Callout_h",
        "@Calibration_Handler//:calibration_h",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "PLT_Appl_Diag",
    srcs = [
        "@SWC_PLT_Appl_Diag//:Source/appl_diag.c",
    ],
    hdrs = [],
    copts = [
        "-Wno-unused-variable",
    ],
    defines = [],
    local_defines = select({
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_Diag_h",
        "//software/common/calibrations/psc:psc_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag:Platform_Diag_Callout_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg:dd_pmic_h",
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "//software/r52/ipc:ipc_mss_h",
        "@Gen8_iND13400//software/r52/dsp_setup:dsp_setup_h",
        "@Sensor_Position//:sensor_position_h",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
        "@reuse",
    ],
)

cc_library(
    name = "appl_diag_unit_test_support_lib",
    hdrs = [
        "@SWC_PLT_Appl_Diag//:Source/appl_diag.c",
    ],
    defines = [],
    strip_include_prefix = "/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_Diag_h",
        "//software/common/calibrations/psc:psc_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag:Platform_Diag_Callout_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg:dd_pmic_h",
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "//software/r52/ipc:ipc_mss_h",
        "@Gen8_iND13400//software/r52/dsp_setup:dsp_setup_h",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
        "@reuse",
    ],
)
