# Bazel includes
load("@rules_cc//cc:defs.bzl", "cc_library")

# emb_tracker bzl file includes
load(":emb_tracker_build_flags.bzl", "pc_resim_tracker_build_flag", "stub_tracker_build_flag", "stub_tracker_defines", "tracker_variant_build_flag")
load(":emb_tracker_project_profile.bzl", "EMB_TRACKER_PROJECT_PROFILE")

# Create tracker build flags
tracker_variant_build_flag()

stub_tracker_build_flag()

pc_resim_tracker_build_flag()

# Create project profile struct for using project options in these libraries
PROJECT_PROFILE = EMB_TRACKER_PROJECT_PROFILE()

# Library for the embedded tracker wrapper files
cc_library(
    name = "emb_tracker_wrapper",
    srcs = [
        "emb_tracker_wrapper.cpp",
    ] + select({
        ":stub_tracker_enabled": ["emb_tracker_stubs.cpp"],
        "//conditions:default": [],
    }),
    hdrs = [
        "emb_tracker_wrapper.h",
        "emb_tracker_internal.h",
    ] + select({
        ":stub_tracker_enabled": ["emb_tracker_stubs.h"],
        "//conditions:default": [],
    }),
    defines = stub_tracker_defines() + PROJECT_PROFILE.OCG_SG_DISABLE_DEFINES + PROJECT_PROFILE.PC_TRACKER_ENABLE_DEFINES,
    features = ["-lto"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/bbe32/inc:get_r52_time_from_bbe32_h",
        "@Gen8_iND13400//software/bbe32/src:get_r52_time_from_bbe32_lib",
        "@Gen8_iND13400//software/bbe32/inc:ipc_dsp_h",
        "@Gen8_iND13400//software/bbe32/inc:mem_pool_h",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@rotbb//emb_tracker:emb_tracker_interface_h",
        "@rotbb//emb_tracker:fusion_360",
        "@rotbb//emb_tracker:shared_tracker_api",
        "@rotbb//emb_tracker:state_manager",
    ] + PROJECT_PROFILE.OCG_DEPS + PROJECT_PROFILE.SG_DEPS,
)

cc_library(
    name = "emb_tracker_wrapper_h",
    hdrs = ["emb_tracker_wrapper.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
)

# Library for the embedded tracker stream interface and parameter setting files
cc_library(
    name = "emb_tracker_project_parameters_h",
    srcs = [],
    hdrs = [
        "emb_tracker_project_parameters.h",
    ],
    defines = PROJECT_PROFILE.TRACKER_VARIANT_DEFINES,
    features = ["-lto"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@rotbb//emb_tracker:shared_tracker_api",
    ],
)

# Also export this file so it is visible to software/common
exports_files(
    srcs = [
        "emb_tracker_project_parameters.h",
    ],
    visibility = ["@Gen8_iND13400//software/common:__pkg__"],
)

# Unit-test-only wrapper target built in real-flow mode.
# Wrapper is compiled with EMB_TRACKER_STUBBED=1 so init/run paths populate data internally.
cc_library(
    name = "emb_tracker_wrapper_with_stubs",
    testonly = True,
    srcs = [
        "emb_tracker_stubs.cpp",
        "emb_tracker_wrapper.cpp",
    ],
    hdrs = [
        "emb_tracker_internal.h",
        "emb_tracker_stubs.h",
        "emb_tracker_wrapper.h",
    ],
    copts = [
        "-include",
        "math.h",
        "-include",
        "string.h",
    ],
    defines = [
        "EMB_TRACKER_STUBBED=1",
        "HOST_BUFFER_DELAY_CYCLES=0",
        "MAIN_SENSOR_BUFFER_DELAY_CYCLES=0",
    ] + PROJECT_PROFILE.OCG_SG_DISABLE_DEFINES,
    features = ["-lto"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/bbe32/inc:get_r52_time_from_bbe32_h",
        "@Gen8_iND13400//software/bbe32/inc:ipc_dsp_h",
        "@Gen8_iND13400//software/bbe32/inc:mem_pool_h",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@rotbb//emb_tracker:emb_tracker_interface_h",
        "@rotbb//emb_tracker:fusion_360",
        "@rotbb//emb_tracker:shared_tracker_api",
        "@rotbb//emb_tracker:state_manager",
    ] + PROJECT_PROFILE.OCG_DEPS + PROJECT_PROFILE.SG_DEPS,
    alwayslink = True,
)

# Unit-test-only wrapper target built in non-stubbed mode.
# Wrapper is compiled with EMB_TRACKER_STUBBED=0 to exercise real-flow paths.
cc_library(
    name = "emb_tracker_wrapper_without_stubs",
    testonly = True,
    srcs = [
        "emb_tracker_stubs.cpp",
        "emb_tracker_wrapper.cpp",
    ],
    hdrs = [
        "emb_tracker_internal.h",
        "emb_tracker_stubs.h",
        "emb_tracker_wrapper.h",
    ],
    copts = [
        "-include",
        "math.h",
        "-include",
        "string.h",
    ],
    defines = [
        "EMB_TRACKER_STUBBED=0",
        "HOST_BUFFER_DELAY_CYCLES=2",
        "MAIN_SENSOR_BUFFER_DELAY_CYCLES=2",
    ] + PROJECT_PROFILE.OCG_SG_DISABLE_DEFINES,
    features = ["-lto"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/bbe32/inc:get_r52_time_from_bbe32_h",
        "@Gen8_iND13400//software/bbe32/inc:ipc_dsp_h",
        "@Gen8_iND13400//software/bbe32/inc:mem_pool_h",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@rotbb//emb_tracker:emb_tracker_interface_h",
        "@rotbb//emb_tracker:fusion_360",
        "@rotbb//emb_tracker:shared_tracker_api",
        "@rotbb//emb_tracker:state_manager",
    ] + PROJECT_PROFILE.OCG_DEPS + PROJECT_PROFILE.SG_DEPS,
    alwayslink = True,
)

# A-PRISM satellite-side association enablers (N11 Doppler gate quantities,
# N22g occupancy/SNR mask rows for the CFAR feed). Self-contained.
cc_library(
    name = "ghost_assoc_enabler_lib",
    srcs = [
        "ghost_assoc_enabler.c",
    ],
    hdrs = [
        "ghost_assoc_enabler.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [],
)
