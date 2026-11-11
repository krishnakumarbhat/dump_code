load("@bazel_skylib//rules:common_settings.bzl", "bool_flag")
load("@rules_cc//cc:defs.bzl", "cc_library")

bool_flag(
    name = "enable_profiling",
    build_setting_default = False,
    visibility = ["//visibility:private"],
)

config_setting(
    name = "profiling_enable",
    flag_values = {":enable_profiling": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "enable_logging",
    build_setting_default = False,
    visibility = ["//visibility:private"],
)

config_setting(
    name = "logging_enable",
    flag_values = {":enable_logging": "True"},
    visibility = ["//visibility:public"],
)

cc_library(
    name = "sil_wrapper_utils_h",
    hdrs = [
        "sil_wrapper_utils.hpp",
    ],
    defines = select({
        "@Gen8_iND13400//sil/rsp_sil/main/sil_wrapper_interface:logging_enable": [
            "LOGGING_ENABLE",
        ],
        "//conditions:default": [],
    }),
    strip_include_prefix = "//sil/rsp_sil/main/sil_wrapper_interface",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/rsp_sil/main/rsp_wrapper_interface/common:sil_api_h",
        "@bb_cfg//:spbb_cfg_h",
    ],
)

cc_library(
    name = "sil_wrapper_utils_lib",
    srcs = ["sil_wrapper_utils.cpp"],
    strip_include_prefix = "//sil/rsp_sil/main/sil_wrapper_interface",
    visibility = ["//visibility:public"],
    deps = [
        ":sil_wrapper_utils_h",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
        "//software/common/ipc:ipc_data_h",
        "@Gen8_iND13400//sil/rsp_sil/main/building_block/src:rdd_proc_pcresim_lib",
        "@Gen8_iND13400//sil/rsp_sil/main/rsp_wrapper_interface/psp_sil_interface:psp_sil_api_h",
        "@Gen8_iND13400//sil/rsp_sil/main/rsp_wrapper_interface/rdd_sil_interface:rdd_sil_api_h",
        "@appl_inclusion_dep//:dabb_include_h",
    ],
)
