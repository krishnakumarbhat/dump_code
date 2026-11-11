load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "af_sil_utils_lib",
    srcs = [
        "af_sil_utils.cpp",
    ],
    hdrs = [
        "af_sil_utils.hpp",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common:UDPLoggingStreamHeaders",
        "@bb_cfg//:afbb_cfg_h",
    ],
)
