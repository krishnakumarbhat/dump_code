load("@bazel_skylib//rules:copy_file.bzl", "copy_file")
load("@bazel_platform//tools/srec_cat:srec_cat.bzl", "srec_cat")

exports_files(
    srcs = [
        "cals_c_files/usc_cal.c",
        "cals_c_files/usc_cal.h",
        "cals_c_files/usc_cal_noinit.c",
    ],
    visibility = ["//visibility:public"],
)

copy_file(
    name = "usc_cal_ptp",
    src = glob(["ptp/usc_cal*.ptp"]).pop(),
    out = "usc_cal.ptp",
    visibility = ["//visibility:public"],
)

srec_cat(
    name = "usc_cal.bin",
    srcs = {
        ":usc_cal_ptp": "ptp",
    },
    options = [
        "{INPUT_FILE0}",
        "-offset",
        "-",
        "-minimum-addr",
        "{INPUT_FILE0}",
        "-output",
        "{OUTPUT_FILE}",
        "-binary",
    ],
    visibility = ["//visibility:public"],
)
