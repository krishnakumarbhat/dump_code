cc_library(
    name = "timer_emb_lib",
    srcs = ["dd_gpt.cpp"],
    hdrs = ["dd_gpt.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/emb_lib/sil_source/src:emblib_ipc_data",
        "@reuse",
    ],
)
