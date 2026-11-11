load("@bazel_skylib//rules:common_settings.bzl", "bool_flag")
load("@emb_tracker_wrapper//:emb_tracker_project_profile.bzl", "EMB_TRACKER_PROJECT_PROFILE")
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "sh_module_cfg_h",
    hdrs = [
        "sh_module_cfg.h",
    ],
    defines = select({
        ":stream_rx_enabled": ["STREAM_RX_ENABLE"],
        "//conditions:default": [],
    }) + select({
        "@Gen8_iND13400//software/bbe32/src:cdc_enable": ["CDC_ENABLE"],
        "//conditions:default": [],
    }) + EMB_TRACKER_PROJECT_PROFILE().TRACKER_ENABLED_DEFINES + select({
        "@Gen8_iND13400//:Run_Feature_functions": ["FEATURE_ENABLE"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@appl_inclusion_dep//:sh_bb_include_h",
    ],
)

cc_library(
    name = "sh_memmap_h",
    hdrs = [
        "sh_memmap.h",
    ],
    defines = [
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
    ],
)

bool_flag(
    name = "enable_stream_rx",
    build_setting_default = True,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "stream_rx_enabled",
    flag_values = {":enable_stream_rx": "true"},
    visibility = ["//visibility:public"],
)
