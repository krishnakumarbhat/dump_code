cc_library(
    name = "csv_trace",
    srcs = ["csv_trace.cpp"],
    hdrs = ["csv_trace.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/emb_lib/sil_source/inc:serialize_object",
        "//sil/emb_lib/sil_source/src:emblib_ipc_data",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
        "//sil/emb_lib/sil_source/src/event_logger:output_control",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
    ],
)
