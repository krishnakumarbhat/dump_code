load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "appl_fp_ifc_lib",
    srcs = ["appl_fp_ifc.c"],
    hdrs = [],
    data = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/rdd_proc/api:appl_fp_ifc_h",
        "//software/bbe32/rdd_proc/imp/inc:appl_rdd_prv_h",
        "//software/bbe32/inc:doppler_process_ifc_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
        "//software/bbe32/inc:cdc_packing_h",
        "@appl_inclusion_dep//:spbb_include_h",
        "@spbb//modules/rdd_first_pass_process/imp/src:rdd_fp_detection_lib",
        "@spbb//modules/doppler_process:doppler_proc_include_h",
        "@spbb//modules/rdd_first_pass_process/imp/src:rdd_fp_interface_lib",
        "@spbb//modules/rdd_first_pass_process/imp/src:fp_xcp_var_lib",
        "//software/bbe32/integration_test:dsp_it_macros_test_h",
        "@spbb//modules/helpers:aa_helpers_h",
    ] + select({
        "//software/bbe32/src:cdc_enable": [
            "//software/bbe32/src:cdc_packing_lib",
            "@spbb//modules/cdc:cdc_include_h",
        ],
        "//conditions:default": [],
    }),
)

cc_library(
    name = "appl_sp_ifc_lib",
    srcs = ["appl_sp_ifc.c"],
    hdrs = [],
    data = [],
    local_defines = select({
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/rdd_proc/api:appl_sp_ifc_h",
        "//software/bbe32/rdd_proc/imp/inc:appl_rdd_prv_h",
        "//software/common:rdd_stream_h",
        "//software/common/calibrations/smc:smc_h",
        "@spbb//modules/second_pass/imp/src/bbe:second_pass_lib",
    ],
)

cc_library(
    name = "appl_cfar_ifc_lib",
    srcs = ["appl_cfar_ifc.c"],
    hdrs = [],
    data = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":appl_adaptive_cfar_lib",
        "//software/bbe32/inc:doppler_process_ifc_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/rdd_proc/api:appl_cfar_ifc_h",
        "//software/bbe32/rdd_proc/imp/inc:appl_rdd_prv_h",
        "//software/common:rdd_stream_h",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
        "@appl_inclusion_dep//:spbb_include_h",
        "@spbb//modules/cfar/imp/src:cfar_interface_lib",
        "@spbb//modules/cfar/imp/src:cfar_lib",
        "@spbb//modules/doppler_process:doppler_proc_include_h",
    ],
)

cc_library(
    name = "appl_adaptive_cfar_lib",
    srcs = ["appl_adaptive_cfar.c"],
    hdrs = ["appl_adaptive_cfar.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_library(
    name = "appl_adaptive_cfar_ut_lib",
    hdrs = ["appl_adaptive_cfar.c"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_library(
    name = "appl_cfar_ifc_ut_lib",
    hdrs = ["appl_cfar_ifc.c"],
    data = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:doppler_process_ifc_h",
        "//software/bbe32/inc:mem_pool_h",
        "//software/bbe32/rdd_proc/api:appl_cfar_ifc_h",
    ],
)

cc_library(
    name = "appl_fp_ifc_ut_lib",
    hdrs = ["appl_fp_ifc.c"],
    data = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:mem_pool_h",
        "//software/bbe32/integration_test:dsp_it_macros_test_h",
        "//software/bbe32/rdd_proc/api:appl_fp_ifc_h",
    ],
)

cc_library(
    name = "appl_sp_ifc_ut_lib",
    hdrs = ["appl_sp_ifc.c"],
    data = [],
    defines = ["restrict=__restrict"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/rdd_proc/api:appl_sp_ifc_h",
        "//software/bbe32/rdd_proc/imp/inc:appl_rdd_prv_h",
        "//software/common:rdd_stream_h",
        "//software/common/calibrations/smc:smc_h",
        "@spbb//modules/second_pass:second_pass_include_h",
    ],
)

cc_library(
    name = "appl_sp_ifc_pcresim_lib",
    srcs = [],
    hdrs = ["appl_sp_ifc.c"],
    data = [],
    local_defines = select({
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/rdd_proc/api:appl_sp_ifc_h",
        "//software/bbe32/rdd_proc/imp/inc:appl_rdd_prv_h",
        "//software/common:rdd_stream_h",
        "//software/common/calibrations/smc:smc_h",
        "@spbb//modules/second_pass/imp/src/bbe:second_pass_pcresim_lib",
    ],
)

cc_library(
    name = "appl_sweepbw_ifc_ut_lib",
    hdrs = ["appl_sweepbw_ifc.c"],
    data = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/rdd_proc/api:appl_sweepbw_ifc_h",
        "//software/bbe32/rdd_proc/imp/inc:appl_rdd_prv_h",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
        "@appl_inclusion_dep//:spbb_include_h",
        "@spbb//modules/sweep_bw:sweep_bw_include_h",
    ],
)

cc_library(
    name = "appl_sweepbw_ifc_lib",
    srcs = ["appl_sweepbw_ifc.c"],
    hdrs = [],
    data = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/rdd_proc/api:appl_sweepbw_ifc_h",
        "//software/bbe32/rdd_proc/imp/inc:appl_rdd_prv_h",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
        "@spbb//modules/sweep_bw/imp/src:sweep_bw_lib",
    ],
)
