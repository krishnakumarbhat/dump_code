cc_library(
    name = "output_control",
    srcs = ["output_control.cpp"],
    hdrs = ["output_control.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
        "@pugixml",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "enable_debugging",
    srcs = ["enable_debugging.cpp"],
    hdrs = ["enable_debugging.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":output_control",
        # "//can",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
        "//sil/emb_lib/sil_source/src/event_logger/calib_print",
        "//sil/emb_lib/sil_source/src/event_logger/csv_trace",
        "//sil/emb_lib/sil_source/src/event_logger/xml_trace",
        "//sil/emb_lib/tracker_emb_lib",
        "//sil/emb_lib/sil_source/src/event_logger/statistical_report",
    ],
)
