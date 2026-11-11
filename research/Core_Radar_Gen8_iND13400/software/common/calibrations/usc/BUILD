load("//tools/bazel/scripts:generate_stream_def.bzl", "generate_stream_def")

filegroup(
    name = "fg_usc_cal",
    srcs = select({
        "@build_config//:flr8": [
            "@usc_flr8//:cals_c_files/usc_cal.h",
        ],
        "@build_config//:srr8p": [
            "@usc_srr8p//:cals_c_files/usc_cal.h",
        ],
    }),
    visibility = ["//software/common:__pkg__"],
)

# ----------------------------------------------------------
# Stream versions (stream_ver) corresponds to the order
# in which the calibration appears in the CAL_TABLE.
# So an order change in CAL_TABLE, should result in a
# stream_ver update here as well.
# section_compatability should also be updated along with
# the section_compatability in the corresponding logging_file
# ----------------------------------------------------------
generate_stream_def(
    name = "calib_stream_usc",
    logging_dir = "//software/common:copyStreamFilesToTemp",
    logging_file = "usc_cal.h",
    section_compatability = select({
        "@build_config//:flr8": 8,
        "@build_config//:srr8p": 10,
    }),
    stream_num = 14,
    stream_struct = "USC_Cal_T",
    stream_ver = 0,  # Update when CAL_TABLE order changes
    visibility = ["//visibility:public"],
)

cc_library(
    name = "usc_h",
    hdrs = select({
        "@build_config//:flr8": [
            "@usc_flr8//:cals_c_files/usc_cal.h",
        ],
        "@build_config//:srr8p": [
            "@usc_srr8p//:cals_c_files/usc_cal.h",
        ],
    }),
    defines = [],
    strip_include_prefix = "/cals_c_files",
    visibility = ["//visibility:public"],
    deps = [
        "@Calibration_Handler//:calibration_h",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "usc_module",
    srcs = [],
    defines = [],
    strip_include_prefix = "//software/common/calibrations/usc",
    visibility = ["//visibility:public"],
    deps = select({
        "@calib_cfg//:calibration_default_init": [":usc_module_init"],
        "//conditions:default": [":usc_module_noinit"],
    }),
)

cc_library(
    name = "usc_module_init",
    srcs = select({
        "@build_config//:flr8": [
            "@usc_flr8//:cals_c_files/usc_cal.c",
        ],
        "@build_config//:srr8p": [
            "@usc_srr8p//:cals_c_files/usc_cal.c",
        ],
    }),
    defines = [],
    strip_include_prefix = "//software/common/calibrations/usc",
    visibility = ["//visibility:public"],
    deps = [
        ":usc_h",
    ],
)

cc_library(
    name = "usc_module_noinit",
    srcs = select({
        "@build_config//:flr8": [
            "@usc_flr8//:cals_c_files/usc_cal_noinit.c",
        ],
        "@build_config//:srr8p": [
            "@usc_srr8p//:cals_c_files/usc_cal_noinit.c",
        ],
    }),
    defines = [],
    strip_include_prefix = "//software/common/calibrations/usc",
    visibility = ["//visibility:public"],
    deps = [
        ":usc_h",
    ],
)
