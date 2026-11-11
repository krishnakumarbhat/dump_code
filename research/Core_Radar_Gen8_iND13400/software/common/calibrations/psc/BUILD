load("@rules_cc//cc:defs.bzl", "cc_library")
load("@Gen8_iND13400//tools/bazel/scripts:generate_stream_def.bzl", "generate_stream_def")

cc_library(
    name = "psc_h",
    hdrs = [
        "srr8p/psc_cal.h",
    ],
    defines = [],
    strip_include_prefix = "srr8p",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/board_revision:board_revision_h",
        "@Calibration_Handler//:calibration_h",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "psc_module",
    srcs = [
        "srr8p/psc_cal.c",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":psc_h",
        "//software/common/board_revision:board_revision_module",
    ],
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
    name = "calib_stream_psc",
    logging_dir = "@Gen8_iND13400//software/common:copyStreamFilesToTemp",
    logging_file = "psc_cal.h",
    section_compatability = select({
        "@build_config//:srr7e": 2,
        "@build_config//:flr7": 2,
        "@build_config//:srr7p": 2,
        "@build_config//:flr7v3": 2,
    }),
    stream_num = 14,
    stream_struct = "PSC_Cal_T",
    stream_ver = 2,  # Update when CAL_TABLE order changes
    visibility = ["//visibility:public"],
)
