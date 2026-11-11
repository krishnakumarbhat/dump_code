cc_library(
    name = "olp_lib",
    srcs = ["src/populate_sfl_input.cpp"],
    hdrs = ["inc/populate_sfl_input.h"],
    strip_include_prefix = "//ff_emb_lib/olp/inc",
    visibility = ["//visibility:public"],
    deps = [
        "//sil_source/src:emblib_ipc_data",
    ],
)

cc_library(
    name = "olp_h",
    hdrs = ["inc/populate_sfl_input.h"],
    strip_include_prefix = "//ff_emb_lib/olp/inc",
    visibility = ["//visibility:public"],
)
