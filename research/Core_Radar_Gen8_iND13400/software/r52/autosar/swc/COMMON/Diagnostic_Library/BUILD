load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Fault_Lib_Plt_h",
    srcs = [],
    hdrs = [
        "Include/Fault_Lib_Plt.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/COMMON/Diagnostic_Library/Include",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "Fault_Lib_Prj_h",
    srcs = [],
    hdrs = [
        "Include/Fault_Lib_Prj.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/COMMON/Diagnostic_Library/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "Fault_Lib_Plt",
    srcs = [
        "Source/Fault_Lib_Plt.c",
    ],
    hdrs = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
    ],
)

cc_library(
    name = "Fault_Lib_Prj",
    srcs = [
        "Source/Fault_Lib_Prj.c",
    ],
    hdrs = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj_h",
    ],
)

cc_library(
    name = "Fault_Lib_Plt_support_lib",
    hdrs = [
        "Source/Fault_Lib_Plt.c",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/COMMON/Diagnostic_Library/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":Fault_Lib_Plt_h",
    ],
)

cc_library(
    name = "Fault_Lib_Prj_support_lib",
    hdrs = [
        "Source/Fault_Lib_Prj.c",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/COMMON/Diagnostic_Library/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":Fault_Lib_Prj_h",
    ],
)
