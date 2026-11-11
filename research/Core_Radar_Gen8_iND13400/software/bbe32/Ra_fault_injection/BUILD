load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Ra_fault_injection",
    srcs = [
        "Ra_fault_injection.c",
    ],
    hdrs = [
    ],
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":Ra_fault_injection_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
        "@reuse",
    ],
)

cc_library(
    name = "Ra_fault_injection_h",
    hdrs = [
        "Ra_fault_injection.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "Ra_fault_injection_ut_lib",
    testonly = True,
    hdrs = [
        "Ra_fault_injection.c",
    ],
    local_defines = [
        "ENABLE_SQT_TEST_STUBS",
        "UNIT_TEST",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":Ra_fault_injection_h",
        "@reuse",
    ],
)
