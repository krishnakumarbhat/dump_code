load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "AF_sil_Test",
    srcs = [
        "main.cpp",
    ],
    defines = select({
        "@build_config//:flr8": ["FLR8"],
        "@build_config//:srr8p": ["SRR8P"],
        "//conditions:default": ["FLR8"],
    }),
    visibility = ["//visibility:private"],
    deps = [
        "@Gen8_iND13400//sil/rsp_sil/main/rsp_wrapper_interface/af_sil_interface/api:af_sil_lib",
        "@Gen8_iND13400//sil/rsp_sil/main/rsp_wrapper_interface/af_sil_interface/common:af_sil_utils_lib",
        "@Gen8_iND13400//sil/rsp_sil/main/sil_wrapper_interface:sil_wrapper_utils_lib",
        "@bb_cfg//:afbb_cfg_h",
    ],
)
