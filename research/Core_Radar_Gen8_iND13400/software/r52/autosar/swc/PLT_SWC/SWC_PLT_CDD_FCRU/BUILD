load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SWC_PLT_CDD_FCRU_h",
    srcs = [],
    hdrs = [
        "Include/SWC_PLT_CDD_FCRU.h",
        "Include/SWC_PLT_CDD_FCRU_Cfg.h",
    ],
    defines = [],
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }) + select({
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }) + select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }),
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FCRU/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/board_revision:board_revision_module",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_FCRU",
    srcs = [
        "Source/SWC_PLT_CDD_FCRU.c",
        "Source/SWC_PLT_CDD_FCRU_Test.c",
    ],
    hdrs = [],
    defines = [],
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }) + select({
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }) + select({
        "//:Build_DEBUG_Enable": ["ENABLE_DEBUGGING"],
        "//conditions:default": [],
    }) + select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/board_revision:board_revision_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FCRU:SWC_PLT_CDD_FCRU_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_h",
        "@boot//:boot_interface",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_FCRU_unit_test_support_lib",
    hdrs = [
        "Source/SWC_PLT_CDD_FCRU.c",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FCRU/Source",
    visibility = ["//visibility:public"],
    deps = [],
)
