load("@bazel_skylib//rules:common_settings.bzl", "bool_flag", "string_flag")
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

string_flag(
    name = "sil_mode",
    build_setting_default = "RDD",
    values = [
        "RDD",
        "AF",
        "DETECT",
    ],
    visibility = ["//visibility:public"],
)

config_setting(
    name = "sil_mode_rdd",
    flag_values = {":sil_mode": "RDD"},
    visibility = ["//visibility:public"],
)

config_setting(
    name = "sil_mode_af",
    flag_values = {":sil_mode": "AF"},
    visibility = ["//visibility:public"],
)

config_setting(
    name = "sil_mode_detect",
    flag_values = {":sil_mode": "DETECT"},
    visibility = ["//visibility:public"],
)

cc_library(
    name = "rsp_emb_lib",
    srcs = ["rsp_sil_wrapper.cpp"],
    hdrs = ["rsp_sil_wrapper.h"],
    defines = select({
        "//sil/emb_lib/rsp_emb_lib:profiling_enable": ["ENABLE_PROFILING"],
        "//sil/emb_lib/rsp_emb_lib:sil_mode_rdd": ["SIL_MODE_RDD"],
        "//sil/emb_lib/rsp_emb_lib:sil_mode_af": ["SIL_MODE_AF"],
        "//sil/emb_lib/rsp_emb_lib:sil_mode_detect": ["SIL_MODE_DETECT"],
        "//conditions:default": [],
    }),
    strip_include_prefix = "//sil/emb_lib/rsp_emb_lib",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/emb_lib/profile_timing",
        "//sil/emb_lib/sil_source/sil_engine_headers:resim_config_h",
        "//sil/emb_lib/sil_source/src:emblib_ipc_data",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
    ] + select({
        "//sil/emb_lib/rsp_emb_lib:sil_mode_rdd": [
            "//sil/rsp_sil/main/rsp_wrapper_interface/rdd_sil_interface:rdd_sil_interface_lib",
            "//sil/rsp_sil/main/rsp_wrapper_interface/af_sil_interface/api:af_sil_lib",
            "@Dyn_alignment_module_interface//:dyn_align_wrapper",
            "@Static_alignment_module_interface//:static_alignment",
            "@interference_detection_cfg//:interference_detection_algo_feature_lib",
            "@radar_capability_module_interface//:rc_wrapper_lib",
            "//software/bbe32/TOI_char_quality_determination/TOI_char_quality_determination/TOI_Char_Quality_Configuration:TOI_algo_interface_lib",
            "@TOI_Char_Quality_Determination//:TOI_Char_Quality_determination_lib",
        ],
        "//sil/emb_lib/rsp_emb_lib:sil_mode_af": [
            "//sil/rsp_sil/main/rsp_wrapper_interface/af_sil_interface/api:af_sil_lib",
            "@Dyn_alignment_module_interface//:dyn_align_wrapper",
            "@Static_alignment_module_interface//:static_alignment",
            "@interference_detection_cfg//:interference_detection_algo_feature_lib",
            "@radar_capability_module_interface//:rc_wrapper_lib",
            "//software/bbe32/TOI_char_quality_determination/TOI_char_quality_determination/TOI_Char_Quality_Configuration:TOI_algo_interface_lib",
            "@TOI_Char_Quality_Determination//:TOI_Char_Quality_determination_lib",
        ],
        "//sil/emb_lib/rsp_emb_lib:sil_mode_detect": [
            "@Dyn_alignment_module_interface//:dyn_align_wrapper",
            "@Static_alignment_module_interface//:static_alignment",
            "@interference_detection_cfg//:interference_detection_algo_feature_lib",
            "@radar_capability_module_interface//:rc_wrapper_lib",
            "//software/bbe32/TOI_char_quality_determination/TOI_char_quality_determination/TOI_Char_Quality_Configuration:TOI_algo_interface_lib",
            "@TOI_Char_Quality_Determination//:TOI_Char_Quality_determination_lib",
        ],
        "//conditions:default": [],
    }),
)
