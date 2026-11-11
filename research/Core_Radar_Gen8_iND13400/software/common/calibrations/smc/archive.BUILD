load("@bazel_skylib//rules:copy_file.bzl", "copy_file")

exports_files(
    srcs = [
        "cals_c_files/smc_cal.c",
        "cals_c_files/smc_cal.h",
        "cals_c_files/smc_cal_noinit.c",
        "cfg_c_files/radar_sw_config.c",
        "cfg_c_files/radar_sw_config.h",
    ],
    visibility = ["//visibility:public"],
)

copy_file(
    name = "smc_cal_ptp",
    src = glob(["ptp/smc_cal*.ptp"]).pop(),
    out = "smc_cal.ptp",
    visibility = ["//visibility:public"],
)
