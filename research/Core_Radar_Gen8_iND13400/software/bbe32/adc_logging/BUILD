cc_library(
    name = "adc_data_logging_h",
    srcs = [],
    hdrs = [
        "xcp_adc_logging.h",
    ],
    defines = [
    ],
    strip_include_prefix = "//software/bbe32/adc_logging",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/ipc:ipc_data_h",
        "@bb_cfg//:spbb_cfg_h",
        "@spbb//modules/range_process:range_proc_include_h",
    ],
)

cc_library(
    name = "adc_data_logging_lib",
    srcs = [
        "xcp_adc_logging.c",
    ],
    hdrs = [
    ],
    defines = [],
    strip_include_prefix = "//software/bbe32/adc_logging",
    visibility = ["//visibility:public"],
    deps = [
        ":adc_data_logging_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/common/ipc:ipc_data_h",
        "//software/common/ipc:ipc_data_lib",
        "@spbb//modules/range_process:range_proc_include_h",
        "@spbb//modules/range_process:range_process_module",
    ],
)
