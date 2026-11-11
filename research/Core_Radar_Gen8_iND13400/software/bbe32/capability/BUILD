load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "rc_wrapper_h",
    srcs = [
    ],
    hdrs = [
        "rc_wrapper.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@rcbb//module/common:rc_common_headers",
    ] + select({
        "@rcbb//module/capability/RC_fault_injection:rc_fault_injection_enabled": [
            "@rcbb//module/capability/RC_fault_injection:rc_fault_injection_lib",
        ],
        "//conditions:default": [],
    }),
)

cc_library(
    name = "rc_wrapper_lib",
    srcs = [
        "rc_wrapper.c",
    ],
    hdrs = [
    ],
    features = ["-lto"],
    local_defines = select({
        "@rcbb//module/capability/RC_fault_injection:rc_fault_injection_enabled": [
            "RC_FAULT_INJECION_ENABLED",
        ],
        "@appl_inclusion_dep//:psp_sil_enable": [
            "PSP_SIL_ENABLE",
        ],
        "//conditions:default": [],
    }) + select({
        "@appl_inclusion_dep//:rc_test_stub_data": [
            "BLOCKAGE_TEST",
        ],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":rc_wrapper_h",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@Gen8_iND13400//software/common/mmic:mmic_common_types_h",
        "@rcbb//module/common/support:rcbb_include_h",
        "@rcbb//module/common:rc_common_module",
        "@rcbb//module/common:rc_memory_type_headers",
        "@rcbb//module/capability:radar_capability_feature_lib",
        "@rcbb//module/capability/diagnostics:rc_diag_headers",
        "@Dyn_alignment_module_interface//:dyn_align_wrapper_h",
        "@appl_inclusion_dep//:dabb_include_h",
        "@Gen8_iND13400//software/bbe32/inc:mem_pool_h",
        "@Gen8_iND13400//software/bbe32/integration_test:dsp_it_macros_test_h",
        "@reuse",
    ] + select({
        "@rcbb//module/capability/RC_fault_injection:rc_fault_injection_enabled": [
            "@rcbb//module/capability/RC_fault_injection:rc_fault_injection_lib",
        ],
        "//conditions:default": [],
    }),
)

cc_library(
    name = "radar_capability_wrapper_unit_test_support_lib",
    srcs = [],
    hdrs = [
        "rc_wrapper.c",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":rc_wrapper_h",
        # need to create fakes for all the libs below
        "@radar_capability_module_interface//:rc_wrapper_lib",
        "@rcbb//module/capability/DM:damping_monitor_unit_test_support_lib",
        "@rcbb//module/capability/FSC:free_sight_check_unit_test_support_lib",
        "@rcbb//module/capability/RE:range_estimation_unit_test_support_lib",
        "@rcbb//module/capability/SE:scene_estimation_unit_test_support_lib",
        "@rcbb//module/capability/PBD:partial_blockage_detector_unit_test_support_lib",
        "@rcbb//module/capability/blockage:blockage_unit_test_support_lib",
        "@rcbb//module/common:rc_common_unit_test_support_lib",
        "@rcbb//module/capability/diagnostics:rc_diagnostics_unit_test_support_lib",
        "@Gen8_iND13400//software/bbe32/integration_test:dsp_it_macros_test_h",
    ] + select({
        "@rcbb//module/capability/RC_fault_injection:rc_fault_injection_enabled": [
            "@rcbb//module/capability/RC_fault_injection:rc_fault_injection_lib",
        ],
        "//conditions:default": [],
    }),
    alwayslink = True,
)
