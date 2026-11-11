load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "vse_teststub",
    srcs = ["VSE_Teststub.c"],
    hdrs = ["VSE_Teststub.h"],
    includes = ["."],
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/calibrations/smc:smc_h",
        "//software/common/ipc:ipc_data_h",
        "@Sensor_Position//:sensor_position_h",
    ],
)
