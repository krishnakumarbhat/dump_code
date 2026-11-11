load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "appl_rdd_prv_h",
    srcs = [],
    hdrs = [
        "appl_rdd_prv.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//software/bbe32/rdd_proc:__subpackages__"],
    deps = [
        "@bb_cfg//:spbb_cfg_h",
        "@spbb//common:common_h",
        "@spbb//modules/rdd_first_pass_process:rdd_fp_include_h",
    ],
)
