load("@bazel_skylib//rules:common_settings.bzl", "bool_flag")

exports_files([
    "program_flow_monitor.c",
    "program_flow_monitor.h",
])

bool_flag(
    name = "disable_pfm",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "pfm_disable",
    flag_values = {":disable_pfm": "true"},
    visibility = ["//visibility:public"],
)

cc_library(
    name = "program_flow_monitor_h",
    hdrs = ["program_flow_monitor.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "program_flow_monitor",
    srcs = ["program_flow_monitor.c"],
    defines = select({
        ":pfm_disable": ["PFM_DISABLE"],
        "//conditions:default": [],
    }),
    visibility = ["//visibility:public"],
    deps = [
        ":program_flow_monitor_h",
        "//software/common/ipc:ipc_data_h",
        "@reuse",
    ],
)

# Unit test support library (textual include of source for white-box testing)
cc_library(
    name = "program_flow_monitor_ut_lib",
    srcs = [],
    hdrs = [
        "program_flow_monitor.c",
        "program_flow_monitor.h",
    ],
    strip_include_prefix = "//software/r52/program_flow_monitor",
    visibility = ["//visibility:public"],
    deps = [
        ":program_flow_monitor_h",
        "//software/common/ipc:ipc_data_h",
        "@reuse",
    ],
)
