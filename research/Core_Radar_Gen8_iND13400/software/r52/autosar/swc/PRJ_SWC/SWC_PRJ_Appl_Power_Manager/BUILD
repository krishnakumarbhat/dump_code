load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SWC_PRJ_Appl_Power_Manager",
    srcs = [
        "Source/SWC_PRJ_Appl_Power_Manager.c",
    ],
    hdrs = [],
    local_defines = select({
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PRJ_Appl_Power_Manager_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/drivers/mcal/dio_wrapper",
        "@reuse",
    ],
)

cc_library(
    name = "SWC_PRJ_Appl_Power_Manager_unit_test_support_lib",
    hdrs = [
        "Source/SWC_PRJ_Appl_Power_Manager.c",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_Power_Manager/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PRJ_Appl_Power_Manager_h",
        "//software/common/board_revision:board_revision_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "@reuse",
    ],
)

cc_library(
    name = "SWC_PRJ_Appl_Power_Manager_h",
    srcs = [],
    hdrs = [
        "Include/SWC_PRJ_Appl_Power_Manager.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_Power_Manager/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/board_revision:board_revision_h",
        "//software/r52/drivers/mcal/mcu_reset_wrapper:mcu_reset_wrapper_h",
        "@iND13400_autosar_sip//Components/Dio:Dio_h",
    ],
)
