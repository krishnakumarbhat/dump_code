load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "af_sil_lib",
    srcs = [
        "af_sil_api.cpp",
    ],
    hdrs = [
        "af_sil_api.hpp",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/bbe32/inc:mem_pool_h",
        "@Gen8_iND13400//software/bbe32/src:angle_finding_project_interface_lib",
        "@Gen8_iND13400//software/common:UDPLoggingStreamHeaders",
        "@Gen8_iND13400//software/common/calibrations/smc:radar_sw_config_h",
        "@Gen8_iND13400//software/common/calibrations/smc:smc_module",
        "@Gen8_iND13400//software/common/calibrations/usc:usc_module",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@bb_cfg//:afbb_cfg_h",
        "@fff",
    ],
)
