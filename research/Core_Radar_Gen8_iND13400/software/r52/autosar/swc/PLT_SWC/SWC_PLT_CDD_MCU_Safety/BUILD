load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SWC_PLT_CDD_MCU_Safety_Cfg_h",
    srcs = [],
    hdrs = [
        "Include/SWC_PLT_CDD_MCU_Safety_Cfg.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/Include",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "PLT_CDD_MCU_Safety_h",
    srcs = [],
    hdrs = [
        "Include/dd_cmu.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/Include",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "SWC_PLT_CDD_MCU_Safety_unit_test_support_lib",
    hdrs = [
        "Source/SWC_PLT_CDD_MCU_Safety.c",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/drivers/mcal/mcu_reset_wrapper:mcu_reset_wrapper_h",
    ],
)

cc_library(
    name = "dd_cmu_ut_lib",
    hdrs = ["Source/dd_cmu.c"],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/Source",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "SWC_PLT_CDD_MCU_Safety",
    srcs = [
        "Source/MCU_Safety_test.c",
        "Source/SWC_PLT_CDD_MCU_Safety.c",
        "Source/dd_cmu.c",
    ],
    hdrs = [],
    defines = [],
    local_defines = select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }) + select({
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/versions:versions_hdrs",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety:PLT_CDD_MCU_Safety_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb:SWC_PLT_CDD_MCU_Safety_h",
        "//software/r52/drivers/mcal/mcu_reset_wrapper",
        "@reuse//:fixmac",
    ],
)
