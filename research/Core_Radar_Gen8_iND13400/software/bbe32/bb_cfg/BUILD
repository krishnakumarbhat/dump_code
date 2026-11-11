load("@emb_tracker_wrapper//:emb_tracker_project_profile.bzl", "EMB_TRACKER_PROJECT_PROFILE")
load("@bazel_skylib//rules:common_settings.bzl", "bool_flag")

cc_library(
    name = "spbb_cfg_h",
    hdrs = [
        "spbb_cfg.h",
    ],
    defines = select({
        "@spbb//modules/range_process:adc_logging_enable": ["ENABLE_ADC_DATA_LOGGING=1"],
        "//conditions:default": [],
    }) + select({
        "enable_transpose_cfar": ["SPBB_ENABLE_TRANSPOSE_CFAR=1"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common/calibrations/smc:radar_sw_config_h",
    ],
)

cc_library(
    name = "afbb_cfg_h",
    srcs = [],
    hdrs = [
        "afbb_cfg.h",
    ],
    defines = [] + select(
        {
            "@build_config//:flr8": ["FLR8"],
            "@build_config//:srr8p": ["SRR8P"],
        },
    ) + select(
        {
            "@afbb//module/_common:sil_config": ["AF_CFG_SIL_BUILD"],
            "//conditions:default": [],
        },
    ) + EMB_TRACKER_PROJECT_PROFILE().TRACKER_ENABLED_DEFINES,
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common/calibrations/smc:radar_sw_config_h",
        "@Gen8_iND13400//software/common/calibrations/smc:smc_h",
    ],
)

bool_flag(
    name = "enable_transpose_cfar_flag",
    build_setting_default = True,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "enable_transpose_cfar",
    flag_values = {":enable_transpose_cfar_flag": "True"},
    visibility = ["//visibility:public"],
)
