cc_library(
    name = "cust_someip",
    srcs = [
        "cust_someip_iface.cpp",
        "populate_and_transmit.cpp",
    ],
    hdrs = [
        "cust_someip_iface.h",
        "populate_and_transmit.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/emb_lib/sil_source/src:emblib_ipc_data",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
        "//sil/emb_lib/someip:someip_driver",
        "//sil/emb_lib/someip/customer/ceer/autogen:ceer_autogen",
    ],
)
