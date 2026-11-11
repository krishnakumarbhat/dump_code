cc_library(
    name = "can_sil_driver",
    srcs = [
        "can_sil_driver.cpp",
    ],
    hdrs = [
        "can_sil_driver.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/emb_lib/plp_sync:plp",
        "//sil/emb_lib/sil_source/inc:sil_version_h",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
    ],
)

cc_library(
    name = "can",
    srcs = [
        "can_sil_iface.cpp",
    ],
    hdrs = [
        "can_sil_iface.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/emb_lib/profile_timing",
    ] + select({
        "//sil/emb_lib/sil_source:al_v1_1": ["//sil/emb_lib/can/customer/AshLey/v1.1:cust_can"],
        # gpo DBC not integrated yet, so no customer CAN lib for that config.
        "//conditions:default": [],
    }),
)
