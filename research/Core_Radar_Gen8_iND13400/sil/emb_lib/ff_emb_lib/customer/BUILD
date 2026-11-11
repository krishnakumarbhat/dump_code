load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "ff_emb_lib",
    srcs = select({
        "//sil/emb_lib/sil_source:gpo": ["//sil/emb_lib/ff_emb_lib/customer/gpo:ff_sil_wrapper.cpp"],
        "//sil/emb_lib/sil_source:al": ["//sil/emb_lib/ff_emb_lib/customer/al:ff_sil_wrapper.cpp"],
    }),
    hdrs = ["ff_sil_wrapper.h"],
    defines = select({
        "//:Run_Feature_functions": ["FEATURE_ENABLE"],
        "//conditions:default": ["FEATURE_DISABLE"],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = select({
        "//:Run_Feature_functions": [
            "//software/bbe32/Cust/OLP_Wrapper:olp_wrapper_h",
            "//software/bbe32/Cust/OLP_Wrapper:olp_wrapper_lib",
            "//software/bbe32/Cust/SFL_Wrapper:sfl_headers_h",
            "//software/bbe32/Cust/SFL_Wrapper:Wrappers_lib",
            "@sfl_core_bb//:sfl_core",
            "@sfl_core_bb//:fbk_lib",
            "//sil/emb_lib/profile_timing",
        ],
        "//conditions:default": [],
    }),
)
