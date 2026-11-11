load("@rules_cc//cc:defs.bzl", "cc_library")
load("@bazel_skylib//rules:common_settings.bzl", "bool_flag")

bool_flag(
    name = "calibration_default_init_values",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "calibration_default_init",
    flag_values = {":calibration_default_init_values": "true"},
    visibility = ["//visibility:public"],
)

cc_library(
    name = "calibration_handler_cfg",
    hdrs = [
        "calibration_cfg.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "calibration_sect",
    hdrs = [
        "calibration_sect_cfg.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common/calibrations/smc:radar_sw_config_h",
        "@Gen8_iND13400//software/common/calibrations/smc:smc_module",
        "@Gen8_iND13400//software/common/calibrations/usc:usc_module",
    ],
)
