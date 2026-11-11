load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SWC_PLT_CDD_WdgHandler",
    srcs = [
        "Source/SWC_PLT_CDD_WdgHandler.c",
        "Source/SWC_PLT_CDD_WdgHandler_Test.c",
    ],
    hdrs = [],
    defines = [],
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }) + select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_WdgHandler_cfg_h",
        ":appl_wdg_handler_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_h",
        "@iND13400_autosar_sip//Components/Wdg:wdg_h",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_WdgHandler_cfg_h",
    srcs = [],
    hdrs = ["Include/SWC_PLT_CDD_WdgHandler_cfg.h"],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler/Include",
    visibility = ["//visibility:public"],
    deps = [
        "@iND13400_autosar_sip//Components/Wdg:wdg_h",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_WdgHandler_unit_test_support_lib",
    srcs = [],
    hdrs = ["Source/SWC_PLT_CDD_WdgHandler.c"],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":appl_wdg_handler_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler/test:SWC_PLT_CDD_WdgHandler_fake_lib",
        "@reuse",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_WdgHandler_test_unit_test_support_lib",
    srcs = [],
    hdrs = ["Source/SWC_PLT_CDD_WdgHandler_Test.c"],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":appl_wdg_handler_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "@iND13400_autosar_sip//Components/Wdg:wdg_h",
        "@reuse",
    ],
)

cc_library(
    name = "appl_wdg_handler_h",
    srcs = [],
    hdrs = ["@SWC_PLT_CDD_WdgHandler//:Include/appl_wdg_handler.h"],
    defines = [],
    strip_include_prefix = "/Include",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_WdgHandler_cfg_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "@iND13400_autosar_sip//Components/Wdg:wdg_h",
        "@iND13400_autosar_sip//Components/WdgM:WdgM_h",
        "@reuse",
    ],
)

cc_library(
    name = "PLT_CDD_WdgHandler",
    srcs = [
        "@SWC_PLT_CDD_WdgHandler//:Source/appl_wdg_handler.c",
    ],
    hdrs = [],
    defines = [],
    strip_include_prefix = "/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":appl_wdg_handler_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler:SWC_PLT_CDD_WdgHandler_cfg_h",
        "@reuse",
    ],
)

cc_library(
    name = "appl_wdg_handler_unit_test_support_lib",
    hdrs = [
        "@SWC_PLT_CDD_WdgHandler//:Source/appl_wdg_handler.c",
    ],
    defines = [],
    strip_include_prefix = "/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":appl_wdg_handler_h",
    ],
)
