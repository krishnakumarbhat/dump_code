# PMIC CDD (Complex Device Driver) - Part of AUTOSAR standard
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "dd_pmic_h",
    srcs = [],
    hdrs = [
        "Source/dd_pmic.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg/Source",
    visibility = ["//visibility:public"],
    deps = [
        "@iND13400_autosar_sip//Components/I2c:I2c_h",
        "@reuse",
    ],
)

cc_library(
    name = "dd_pmic",
    srcs = [
        "Source/dd_pmic.c",
    ],
    hdrs = [],
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }) + select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }),
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":dd_pmic_h",
        "//software/common/versions:versions_hdrs",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:SWC_PLT_PlatformTime_cfg_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
    ],
)

cc_library(
    name = "dd_pmic_unit_test_support_lib",
    srcs = [],
    hdrs = [
        "Source/dd_pmic.c",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":dd_pmic_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:SWC_PLT_PlatformTime_cfg_h",
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_ExternalWdg",
    srcs = [
        "Source/SWC_PLT_CDD_ExternalWdg.c",
    ],
    hdrs = [],
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }) + select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }),
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":dd_pmic_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_ExternalWdg_unit_test_support_lib",
    srcs = [],
    hdrs = ["Source/SWC_PLT_CDD_ExternalWdg.c"],
    defines = [
        "XCP_FAULT_INJECTION=STD_ON",
        "ENABLE_SQT_TEST_STUBS=STD_ON",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":dd_pmic_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg/test:SWC_PLT_CDD_ExternalWdg_fake_lib",
    ],
)
