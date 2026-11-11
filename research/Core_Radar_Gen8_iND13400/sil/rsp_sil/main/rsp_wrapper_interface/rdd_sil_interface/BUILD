load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "rdd_sil_api_h",
    hdrs = [
        "rdd_sil_api.hpp",
    ],
    strip_include_prefix = "//sil/rsp_sil/main/rsp_wrapper_interface/rdd_sil_interface",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:UDPLoggingStreamHeaders",
        "//software/common:radar_look_types",
    ],
)

cc_library(
    name = "rdd_sil_interface_lib",
    srcs = ["rdd_sil_interface.cpp"],
    copts = [],
    strip_include_prefix = "//sil/rsp_sil/main/rsp_wrapper_interface/rdd_sil_interface",
    visibility = ["//visibility:public"],
    deps = [
        ":rdd_sil_api_h",
        "@Gen8_iND13400//sil/rsp_sil/main/building_block/src:rdd_proc_pcresim_lib",
        "@Gen8_iND13400//sil/rsp_sil/main/rsp_wrapper_interface/af_sil_interface/api:af_sil_lib",
        "@Gen8_iND13400//sil/rsp_sil/main/rsp_wrapper_interface/af_sil_interface/common:af_sil_utils_lib",
        "@Gen8_iND13400//sil/rsp_sil/main/sil_wrapper_interface:sil_wrapper_utils_h",
        "@Gen8_iND13400//sil/rsp_sil/main/sil_wrapper_interface:sil_wrapper_utils_lib",
        "@Gen8_iND13400//software/bbe32/rdd_proc/api:appl_sp_ifc_h",
        "@Gen8_iND13400//software/bbe32/rdd_proc/imp/src:appl_sp_ifc_pcresim_lib",
        "@spbb//common:common_lib",
        "@spbb//common/cstub_helpers:cstub_helpers_lib",
    ],
)
