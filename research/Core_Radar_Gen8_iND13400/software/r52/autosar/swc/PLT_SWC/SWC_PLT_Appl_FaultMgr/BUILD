load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SWC_Appl_FaultMgr_Cfg_h",
    srcs = [],
    hdrs = [
        "Include/SWC_Appl_FaultMgr_Cfg.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr/Include",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_library(
    name = "SWC_PLT_Appl_FaultMgr_unit_test_support_lib",
    hdrs = [
        "Source/SWC_PLT_Appl_FaultMgr.c",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_FaultMgr_h",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_FaultMgr",
    srcs = [
        "Source/SWC_PLT_Appl_FaultMgr.c",
    ],
    hdrs = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_FaultMgr_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr:SWC_Appl_FaultMgr_Cfg_h",
        "@iND13400_autosar_sip//Components/NvM",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
        "@reuse",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_FaultMgr_h",
    srcs = [],
    hdrs = [
        "@SWC_PLT_Appl_FaultMgr//:Include/SWC_PLT_Appl_FaultMgr.h",
    ],
    defines = [],
    strip_include_prefix = "/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/calibrations/psc:psc_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Calibration:Diagnostic_Calib_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr:SWC_Appl_FaultMgr_Cfg_h",
        "@Calibration_Handler//:calibration_h",
    ],
)

cc_library(
    name = "PLT_Appl_FaultMgr",
    srcs = [
        "@SWC_PLT_Appl_FaultMgr//:Source/appl_faultmgr.c",
    ],
    hdrs = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_FaultMgr_h",
        "//software/common/calibrations/psc:psc_module",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
        "@reuse",
    ],
)

cc_library(
    name = "appl_faultmgr_unit_test_support_lib",
    hdrs = [
        "@SWC_PLT_Appl_FaultMgr//:Source/appl_faultmgr.c",
    ],
    defines = [],
    strip_include_prefix = "/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_FaultMgr_h",
        "@reuse",
    ],
)
