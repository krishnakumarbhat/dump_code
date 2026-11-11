load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "master_integration_test_h",
    hdrs = ["master_integration_test.h"],
    defines = select({
        "//:Integration_Testing_enabled": ["Integration_Testing"],
        "//conditions:default": [],
    }) + select({
        "//:ANGLEFINDING_enabled": ["Anglefinding_IT"],
        "//conditions:default": [],
    }) + select({
        "//:RADAR_CAPABILITY_enabled": ["Radar_capability_IT"],
        "//conditions:default": [],
    }) + select({
        "@build_config//:flr8": ["FLR8"],
        "@build_config//:srr8p": ["SRR8P"],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
        "//software/common/ipc:ipc_data_h",
    ],
)

cc_library(
    name = "master_it_macros_test_h",
    hdrs = ["master_it_macros_test.h"],
    defines = select({
        "//:Integration_Testing_enabled": ["Integration_Testing"],
        "//conditions:default": [],
    }) + select({
        "//:ANGLEFINDING_enabled": ["Anglefinding_IT"],
        "//conditions:default": [],
    }) + select({
        "//:RADAR_CAPABILITY_enabled": ["Radar_capability_IT"],
        "//conditions:default": [],
    }) + select({
        "@build_config//:flr8": ["FLR8"],
        "@build_config//:srr8p": ["SRR8P"],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":master_integration_test_h",
    ],
)

cc_library(
    name = "master_integration_test",
    srcs = ["master_integration_test.c"],
    hdrs = ["master_integration_test.h"],
    defines = select({
        "//:Integration_Testing_enabled": ["Integration_Testing"],
        "//conditions:default": [],
    }) + select({
        "//:ANGLEFINDING_enabled": ["Anglefinding_IT"],
        "//conditions:default": [],
    }) + select({
        "//:RADAR_CAPABILITY_enabled": ["Radar_capability_IT"],
        "//conditions:default": [],
    }) + select({
        "@build_config//:flr8": ["FLR8"],
        "@build_config//:srr8p": ["SRR8P"],
    }),
    linkopts = ["-lm"],  # Link math library for fabs() in validation functions
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":master_it_macros_test_h",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
        "//software/common/ipc:ipc_data_h",
    ],
    alwayslink = True,
)
