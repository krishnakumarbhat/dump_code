load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SWC_PLT_CDD_HIL_h",
    srcs = [],
    hdrs = [
        "Include/SWC_PLT_CDD_HIL.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL/Include",
    visibility = ["//visibility:public"],
    deps = [
        "@reuse",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_HIL",
    srcs = [
        "Source/SWC_PLT_CDD_HIL.c",
    ],
    hdrs = [],
    defines = [],
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL:SWC_PLT_CDD_HIL_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL/hil:hil_project_interface_lib",
        "//software/r52/ipc:ipc_mss_h",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging:SWC_PLT_CDD_LOGGING_h",
        "@Sensor_Position//:sensor_position_h",
        "@hilbb//module:bb_hil_module_lib",
        "@hilbb//module/_api:hil_communication_handler_h",
        "@hilbb//module/_api:hil_types_h",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_HIL_unit_test_support_lib",
    hdrs = [
        "Source/SWC_PLT_CDD_HIL.c",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/ipc:ipc_mss_h",
    ],
)
