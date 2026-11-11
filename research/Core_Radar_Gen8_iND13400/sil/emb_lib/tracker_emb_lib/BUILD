load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "tracker_emb_lib",
    srcs = ["tracker_sil_wrapper.cpp"],
    hdrs = ["tracker_sil_wrapper.h"],
    defines = select({
        "@emb_tracker_wrapper//:tracker_disabled": ["TRACKER_DISABLED"],
        "@emb_tracker_wrapper//:partner_sensor": ["TRACKER_DISABLED"],
        "//conditions:default": ["TRACKER_ENABLED"],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = select({
        "@emb_tracker_wrapper//:tracker_disabled": [],
        "//conditions:default": [
            "//sil/emb_lib/sil_source/inc:sil_macros_time",
            "//sil/emb_lib/sil_source/src:emblib_ipc_data",
            "//sil/emb_lib/sil_source/src:sil_wrapper_common",
            "//sil/emb_lib/sil_source/src/event_logger:output_control",
            "//sil/emb_lib/profile_timing",
            "@emb_tracker_wrapper//:emb_tracker_wrapper",
            "@emb_tracker_wrapper//:emb_tracker_project_parameters_h",
        ],
    }),
)
