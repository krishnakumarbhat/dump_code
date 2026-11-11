cc_library(
    name = "toi_config_h",
    hdrs = [
        "toi_config.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common:UDPLoggingStreamHeaders",
        "@rcbb//module/capability/blockage:blockage_headers",
    ],
)

cc_library(
    name = "TOI_algo_interface_lib",
    srcs = [
        "toi_algo_interface.c",
    ],
    hdrs = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/common/ipc:ipc_data_h",
        "@TOI_Char_Quality_Determination//:toi_algo_interface_h",
    ],
)
