load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "binary_headers",
    visibility = ["//visibility:public"],
    deps = select({
        "@build_config//:flr8": ["//sil/rsp_sil/data_bin/flr8:binary_header_h"],
        "@build_config//:srr8p": ["//sil/rsp_sil/data_bin/srr8p:binary_header_h"],
    }),
)
