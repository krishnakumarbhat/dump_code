load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SWC_PLT_CDD_MCU_Safety",
    srcs = [
        "Source/Exception_handler.c",
        "Source/NOC_Handler.c",
        "Source/MCU_Safety.c",
        "Source/Mss_Ecc_Parity.c",
    ] + select({
        "//:enable_static_register_safety": ["Source/static_register_safety.c"],
        "//conditions:default": [],
    }),
    hdrs = [],
    defines = [],
    local_defines = select({
        "//:enable_static_register_safety": ["MCAL_SAFETY_REQ_GEN8"],
        "//conditions:default": [],
    }) + select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }) + select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }) + select({
        "//:Build_SQT_ARTIEMEM_FAULT": ["ENABLE_SQT_ARTIEMEM_FAULT"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":Exception_handler_s",
        ":SWC_PLT_CDD_MCU_Safety_h",
        "//software/common/versions:versions_hdrs",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "@boot//:boot_interface",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "Mss_Ecc_Parity_ut_lib",
    testonly = True,
    srcs = [
        "Source/Mss_Ecc_Parity.c",
    ],
    local_defines = ["UNIT_TEST"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_MCU_Safety_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_MCU_Safety_h",
    srcs = [],
    hdrs = [
        "Include/Exception_handler.h",
        "Include/Mss_Ecc_Parity.h",
        "Include/NOC_Handler.h",
        "Include/SWC_PLT_CDD_MCU_Safety.h",
        "Include/static_register_safety.h",
        "Include/static_register_safety_cfg.h",
    ],
    defines = [],
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/board_revision:board_revision_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@iND13400_autosar_sip//Components/Crc:Crc_h",
        "@reuse",
    ],
)

cc_library(
    name = "MCU_Safety_unit_test_support_lib",
    hdrs = [
        "Source/MCU_Safety.c",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_MCU_Safety_h",
        "//software/common/versions:versions_hdrs",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "Exception_handler_test_support_lib",
    hdrs = [
        "Source/Exception_handler.c",
    ],
    defines = [],
    local_defines = ["UNIT_TEST"],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_MCU_Safety_h",
    ],
)

cc_library(
    name = "NOC_Handler_test_support_lib",
    hdrs = [
        "Source/NOC_Handler.c",
    ],
    defines = [],
    local_defines = ["UNIT_TEST"],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_MCU_Safety_h",
    ],
)

cc_library(
    name = "Exception_handler_s",
    srcs = [
        "Source/Exception_handler.s",
    ],
    hdrs = [],
    copts = [
        "-Xpreprocess-assembly",
    ],
    data = [],
    defines = [],
    local_defines = [
        "MULTIPLE_IMAGE",
    ],
    visibility = ["//visibility:public"],
    deps = [],
)

cc_library(
    name = "static_register_safety_test_support_lib",
    hdrs = select({
        "//:enable_static_register_safety": ["Source/static_register_safety.c"],
        "//conditions:default": [],
    }),
    defines = [],
    local_defines = ["UNIT_TEST"],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_MCU_Safety_h",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
    ],
)
