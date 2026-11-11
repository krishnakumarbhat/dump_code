load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SWC_PLT_Appl_IntWDG",
    srcs = [
        "Source/SWC_PLT_Appl_IntWDG.c",
        "Source/SWC_PLT_Appl_IntWDG_test.c",
    ],
    hdrs = [],
    defines = [],
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }) + select({
        "//:Build_Disable_int_Wdg": ["DISABLE_INT_WDG"],
        "//conditions:default": [],
    }) + select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_IntWDG_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_IntWDG_h",
    srcs = [],
    hdrs = [
        "Include/SWC_PLT_Appl_IntWDG.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IntWDG/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/calibrations/smc:smc_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "@iND13400_autosar_sip//Components/WdgM:WdgM_h",
        "@reuse",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_IntWDG_unit_test_support_lib",
    srcs = [],
    hdrs = [
        "Include/SWC_PLT_Appl_IntWDG.h",
        "Source/SWC_PLT_Appl_IntWDG.c",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [],
)
