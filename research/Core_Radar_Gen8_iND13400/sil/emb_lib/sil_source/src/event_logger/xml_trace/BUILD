cc_library(
    name = "xml_trace",
    srcs = [
        "xml_trace.cpp",
    ],
    hdrs = [
        "xml_trace.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/emb_lib/sil_source/sil_engine_headers:resim_config_h",
        "//sil/emb_lib/sil_source/src:emblib_ipc_data",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
        "//sil/emb_lib/sil_source/src/event_logger:output_control",
        "//software/common:UDPLoggingStreamHeaders",
        "@pugixml",
        # "@spbb//common:spbb_typedefs",
    ],
)
