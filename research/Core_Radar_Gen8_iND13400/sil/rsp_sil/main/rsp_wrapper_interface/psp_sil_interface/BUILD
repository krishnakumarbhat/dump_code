load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "psp_sil_api_h",
    srcs = [],
    hdrs = [
        "psp_sil_api.hpp",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Dyn_alignment_module_interface//:dyn_align_wrapper_h",
        "@Static_alignment_module_interface//:static_alignment_h",
        "@interference_detection_cfg//:interference_detection_algo_feature_h",
        "@radar_capability_module_interface//:rc_wrapper_h",
    ],
)

cc_library(
    name = "psp_sil_interface_lib",
    srcs = [
        "psp_sil_interface.cpp",
    ],
    hdrs = [],
    strip_include_prefix = "//sil/rsp_sil/main/rsp_wrapper_interface/psp_sil_interface",
    visibility = ["//visibility:public"],
    deps = [
        ":psp_sil_api_h",
        "@Dyn_alignment_module_interface//:dyn_align_wrapper",
        "@Static_alignment_module_interface//:static_alignment",
        "@interference_detection_cfg//:interference_detection_algo_feature_lib",
        "@radar_capability_module_interface//:rc_wrapper_lib",
        "@rm//module/radar_math:radar_math_lib",
    ],
)
