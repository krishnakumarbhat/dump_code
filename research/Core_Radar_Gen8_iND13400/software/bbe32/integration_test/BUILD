################################################################################
# SWE5 Integration Test Support for BBE32/DSP Core
# Provides stubbing and validation for integration test hooks.
################################################################################

load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "dsp_integration_test_h",
    hdrs = ["dsp_integration_test.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:angle_finding_project_interface_h",
    ] + select({
        "//:RADAR_CAPABILITY_enabled": ["@radar_capability_module_interface//:rc_wrapper_h"],
        "//conditions:default": [],
    }) + select({
        "//:FIRSTPASS_enabled": [
            "@spbb//modules/rdd_first_pass_process:rdd_fp_include_h",
            "@appl_inclusion_dep//:spbb_include_h",
        ],
        "//conditions:default": [],
    }),
)

cc_library(
    name = "dsp_it_macros_test_h",
    hdrs = ["dsp_it_macros_test.h"],
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
        "//:FIRSTPASS_enabled": ["FirstPass_IT"],
        "//conditions:default": [],
    }) + select({
        "@build_config//:flr8": ["FLR8"],
        "@build_config//:srr8p": ["SRR8P"],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":dsp_integration_test_h",
    ],
)

cc_library(
    name = "dsp_integration_test_lib",
    srcs = ["dsp_integration_test.c"],
    hdrs = ["dsp_integration_test.h"],
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
        "//:FIRSTPASS_enabled": ["FirstPass_IT"],
        "//conditions:default": [],
    }) + select({
        "@build_config//:flr8": ["FLR8"],
        "@build_config//:srr8p": ["SRR8P"],
    }),
    includes = ["."],
    visibility = ["//visibility:public"],
    deps = select({
        "//:Integration_Testing_enabled": [
            "//software/common/calibrations/usc:usc_h",
            "//software/common/ipc:ipc_data_h",
            "//software/bbe32/inc:angle_finding_project_interface_h",
            "//software/common:rdd_stream_h",
            "//software/common:stream_header_h",
            "//software/common:UDPLoggingStreamHeaders",
            "//software/common/satellite_can_standalone_common:rdd_stream_module_h",
            "@appl_inclusion_dep//:spbb_include_h",
            "@radar_capability_module_interface//:rc_wrapper_h",
            ":dsp_it_macros_test_h",
        ],
        "//conditions:default": [],
    }),
    alwayslink = True,
)
