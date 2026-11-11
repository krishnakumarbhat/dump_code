load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "crc_calc_h",
    srcs = [
    ],
    hdrs = [
        "crc_calc.h",
    ],
    defines = [
    ],
    strip_include_prefix = "//software/common/crc_calc/",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:rdd_stream_h",
        "//software/common/ipc:ipc_data_h",
        "@Calibration_Handler//:calibration_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/common:driver_common_h",
        "@reuse",
    ],
)

cc_library(
    name = "crc_calc_c",
    srcs = [
        "crc_calc.c",
    ],
    hdrs = [
    ],
    defines = [
    ],
    features = ["-lto"],
    strip_include_prefix = "//software/common/crc_calc/",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:rdd_stream_h",
        "//software/common/crc_calc:crc_calc_h",
        "//software/common/ipc:ipc_data_h",
        "@Calibration_Handler//:calibration_h",
        "@bb_cfg//:spbb_cfg_h",  # Transitive dependency from @spbb
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)

cc_library(
    name = "crc_calc_unit_test_support_lib",
    testonly = True,
    srcs = [],
    hdrs = [
        "crc_calc.c",
    ],
    strip_include_prefix = "//software/common/crc_calc/",
    visibility = ["//visibility:public"],
    deps = [
        ":crc_calc_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)
