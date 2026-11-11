load("@rules_cc//cc:defs.bzl", "cc_library")

# Self-contained stub for J1939Rm types - no Rte_J1939Rm_Type.h needed.
cc_library(
    name = "J1939Rm_Types_h",
    hdrs = ["J1939Rm_Types.h"],
    strip_include_prefix = "//software/r52/autosar/config/Appl/J1939_Stubs",
    visibility = ["//visibility:public"],
    deps = [
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
    ],
)

# Stub headers for J1939Nm and J1939Rm - provided per J1939Dcm TechRef section 6.4.
cc_library(
    name = "J1939_Stubs_h",
    hdrs = [
        "J1939Nm.h",
        "J1939Rm.h",
    ],
    strip_include_prefix = "//software/r52/autosar/config/Appl/J1939_Stubs",
    visibility = ["//visibility:public"],
    deps = [
        ":J1939Rm_Types_h",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
    ],
)

# Stub implementations for J1939Nm and J1939Rm functions.
cc_library(
    name = "J1939_Stubs",
    srcs = ["J1939_Stubs.c"],
    visibility = ["//visibility:public"],
    deps = [":J1939Rm_Types_h"],
)
