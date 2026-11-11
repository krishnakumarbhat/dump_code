load("@rules_cc//cc:defs.bzl", "cc_library")
load("@emb_tracker_wrapper//:emb_tracker_project_profile.bzl", "EMB_TRACKER_PROJECT_PROFILE")

cc_library(
    name = "vse_sil_wrapper",
    srcs = [
        "vse_wrapper.cpp",
    ],
    hdrs = ["vse_wrapper.h"],
    local_defines = EMB_TRACKER_PROJECT_PROFILE().TRACKER_ENABLED_DEFINES,
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/emb_lib/sil_source/src:emblib_ipc_data",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/VSE:vse_core_c_api",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/VSE/vse_stub:vse_teststub",
        "@Sensor_Position//:sensor_position",
        "@reuse",
        "@reuse//:fixmac",
    ],
)
