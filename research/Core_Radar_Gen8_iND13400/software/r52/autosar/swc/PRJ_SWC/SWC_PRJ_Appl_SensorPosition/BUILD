load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SWC_PRJ_Appl_SensorPosition",
    srcs = [
        "Source/SWC_PRJ_Appl_SensorPosition.c",
    ],
    hdrs = [],
    local_defines = select({
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj_h",
        "@Sensor_Position//:sensor_position_h",
    ],
)

cc_library(
    name = "SWC_PRJ_Appl_SensorPosition_unit_test_support_lib",
    hdrs = [
        "Source/SWC_PRJ_Appl_SensorPosition.c",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_SensorPosition/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj_h",
        "@Sensor_Position//:sensor_position_h",
    ],
)
