load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "rdd_proc_pcresim_lib",
    srcs = ["rdd_proc_pcresim.cpp"],
    hdrs = ["rdd_proc_pcresim.hpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/rdd_proc/imp/src:appl_sp_ifc_pcresim_lib",
        "//software/common/ipc:ipc_data_h",
        "@spbb//common/cstub_helpers:cstub_helpers_lib",
    ],
)
