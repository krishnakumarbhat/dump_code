load("@bazel_skylib//rules:common_settings.bzl", "bool_flag")

exports_files([
    "stack_monitor_r52.h",
    "stack_monitor_r52.c",
])

cc_library(
    name = "stack_monitor_r52_h",
    srcs = [],
    hdrs = [
        "stack_monitor_r52.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@reuse",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        # "@Gen7//software/app/common:UDPLoggingStreamHeaders",
        "@iND13400_autosar_sip//Components/Os:Os_h",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
    ],
)

cc_library(
    name = "Stack_Monitor_R52_external_module",
    srcs = [
        "stack_monitor_r52.c",
    ],
    hdrs = [],
    copts = ["-Wno-pragma-pack"],  # JH: Added to get rid of build error in Os_MemMap_Stacks.h
    defines = [
    ],
    strip_include_prefix = "//software/r52/r52_stack",
    visibility = ["//visibility:public"],
    deps = [
        ":stack_monitor_r52_h",
        "@iND13400_autosar_sip//Components/Os",
    ],
)

bool_flag(
    name = "disable_stack_monitor_r52",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "stack_monitor_disable_r52",
    flag_values = {":disable_stack_monitor_r52": "true"},
    visibility = ["//visibility:public"],
)

# Unit test support library
cc_library(
    name = "stack_monitor_r52_unit_test_support_lib",
    srcs = [],
    hdrs = [
        "stack_monitor_r52.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/r52_stack/test:stack_monitor_r52_fake_lib",
        "@com_google_googletest//:gtest",
        "@fff",
    ],
)
