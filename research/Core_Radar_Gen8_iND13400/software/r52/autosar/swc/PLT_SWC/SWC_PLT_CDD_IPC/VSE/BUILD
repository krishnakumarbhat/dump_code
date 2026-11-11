load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "vse_core_c_api",
    srcs = ["VSE_Core.c"],
    hdrs = ["VSE_Core.h"],
    includes = ["."],
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/calibrations/smc:smc_h",
        "//software/common/ipc:ipc_data_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/VSE/bb_VSE_Master_Model_WL_L2P:VSE_Master_Model",
        "//software/r52/ipc:ipc_mss_h",
        "@Sensor_Position//:sensor_position_h",
    ],
)
