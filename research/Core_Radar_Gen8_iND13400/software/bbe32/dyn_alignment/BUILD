load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "dyn_align_wrapper_h",
    srcs = [],
    hdrs = [
        "dyn_align_wrapper.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/bbe32/inc:mem_pool_h",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@appl_inclusion_dep//:dabb_include_h",
        "@dabb//module/dyn_alignment/dyn_alignment_api:dyn_align_module_h",
    ],
)

cc_library(
    name = "dyn_align_wrapper",
    srcs = [
        "dyn_align_wrapper.c",
    ],
    hdrs = [],
    defines = select({
        "@dabb//module:da_test_stub_data": [
            "ALIGN_STUB_SIMULATE_DET",
        ],
        "//conditions:default": [],
    }) + select({
        "@build_config//:flr8": ["FLR8"],
        "@build_config//:srr8p": ["SRR8P"],
    }),
    features = ["-lto"],
    local_defines = select({
        "@appl_inclusion_dep//:psp_sil_enable": [
            "PSP_SIL_ENABLE",
        ],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":dyn_align_wrapper_h",
        ":ghost_calib_lib",
        "@Gen8_iND13400//software/bbe32/integration_test:dsp_it_macros_test_h",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@dabb//module/dyn_alignment/dyn_alignment_api:dyn_align_module_h",
        "@dabb//module/dyn_alignment/dyn_alignment_imp/_src:dyn_align_module_src_lib",
        "@rm//module/radar_math:radar_math_lib",
    ],
)

# A-PRISM ghost calibration kernels (N25/N26/N20g/N27 + DA fast-lock gain).
# Self-contained (math.h only); verified by aprism_host_tests/test_ghost_calib.
cc_library(
    name = "ghost_calib_lib",
    srcs = [
        "ghost_calib.c",
    ],
    hdrs = [
        "ghost_calib.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_library(
    name = "dyn_align_wrapper_unit_test_support_lib",
    hdrs = [
        "dyn_align_wrapper.c",
    ],
    defines = select({
        "@build_config//:flr8": ["FLR8"],
        "@build_config//:srr8p": ["SRR8P"],
        "//conditions:default": ["FLR8"],
    }),
    features = ["-lto"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":dyn_align_wrapper_h",
        ":ghost_calib_lib",
        "@Gen8_iND13400//software/bbe32/inc:mem_pool_h",
        "@Gen8_iND13400//software/bbe32/integration_test:dsp_it_macros_test_h",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@dabb//module/dyn_alignment/dyn_alignment_imp/_src:dyn_align_module_sources_ut",
    ],
)
