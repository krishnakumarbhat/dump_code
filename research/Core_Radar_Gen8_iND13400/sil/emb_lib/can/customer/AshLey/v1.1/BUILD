cc_library(
    name = "cust_can",
    srcs = [
        "cust_can_sil_iface.cpp",
        "populate_and_transmit_signals.cpp",
    ],
    hdrs = [
        "cust_can_sil_iface.h",
        "populate_and_transmit_signals.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":can_message_id",
        "//sil/emb_lib/can:can_sil_driver",
        "//sil/emb_lib/can/customer/AshLey/v1.1/autogen:AshLey_autogen",
        "//sil/emb_lib/sil_source/inc:sil_version_h",
        "//sil/emb_lib/sil_source/src:emblib_ipc_data",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
        "//sil/emb_lib/sil_source/src/event_logger:output_control",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "can_message_id",
    srcs = ["can_message_id.cpp"],
    hdrs = ["can_message_id.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
)
