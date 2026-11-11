load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SWC_CMP_PRJ_UDSHandler",
    srcs = [
        "Source/SWC_CMP_PRJ_UDSHandler.c",
        "Source/SWC_Project_Radar_Alignment_Handler.c",
    ],
    hdrs = [],
    local_defines = select({
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_CMP_PRJ_UDSHandler_h",
        "//software/common/calibrations/usc:usc_h",
        "//software/common/crc32",
        "//software/common/crc32:crc32_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj",
        "//software/r52/drivers/mcal/mcu_reset_wrapper",
        "@Sensor_Position//:sensor_position",
        "@Sensor_Position//:sensor_position_h",
        "@reuse",
    ],
)

cc_library(
    name = "SWC_CMP_PRJ_UDSHandler_unit_test_support_lib",
    hdrs = [
        "Source/SWC_CMP_PRJ_UDSHandler.c",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PRJ_SWC/SWC_CMP_PRJ_UDSHandler/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_CMP_PRJ_UDSHandler_h",
        "//software/common/calibrations/usc:usc_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        "//software/r52/drivers/mcal/mcu_reset_wrapper:mcu_reset_wrapper_h",
        "@reuse",
    ],
)

cc_library(
    name = "SWC_Project_Radar_Alignment_Handler_unit_test_lib",
    testonly = True,
    srcs = [
        "Source/SWC_Project_Radar_Alignment_Handler.c",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_CMP_PRJ_UDSHandler_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
    ],
)

cc_library(
    name = "SWC_CMP_PRJ_UDSHandler_h",
    srcs = [],
    hdrs = [
        "Include/SWC_CMP_PRJ_UDSHandler.h",
        "Include/SWC_Project_Radar_Alignment_Handler.h",
        "Include/Versions_UDS.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PRJ_SWC/SWC_CMP_PRJ_UDSHandler/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler:SWC_PLT_Radar_Alignment_Handler_h",
    ],
)
