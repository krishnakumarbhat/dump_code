cc_library(
    name = "plp",
    srcs = [
        "plp_iface.cpp",
    ],
    hdrs = [
        "plp_iface.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/emb_lib/plp_sync:plp_driver",
    ],
)

cc_library(
    name = "plp_driver",
    srcs = [
        "plp_driver.cpp",
    ],
    hdrs = [
        "plp_driver.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/emb_lib/can/customer/AshLey/v1.1:can_message_id",
        "//sil/emb_lib/mdf_lib:mdf_iface",
        "//sil/emb_lib/sil_source/sil_engine_headers:sil_output_symbol_h",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
        "//sil/emb_lib/sil_source/src/event_logger:output_control",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "someip_plp_driver",
    srcs = [
        "someip_plp_driver.cpp",
    ],
    hdrs = [
        "someip_plp_driver.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/emb_lib/mdf_lib:mdf_iface",
        "//sil/emb_lib/plp_sync:plp_driver",
        "//sil/emb_lib/sil_source/sil_engine_headers:sil_output_symbol_h",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
        "//sil/emb_lib/sil_source/src/event_logger:output_control",
        "//sil/emb_lib/someip:someip_driver",
        "@reuse//:fixmac",
    ],
)
