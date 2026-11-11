load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "olp_wrapper_lib",
    srcs = [
        "src/OLP_wrapper.cpp",
    ],
    defines = [
        "OLP_OBJ_SOURCE_F360",
        "OLP_NUMBER_OF_OBJECTS=64",
    ],
    features = ["-lto"],
    implementation_deps = [
        ":olp_wrapper_h",
        "@olp_bb//:OLP_Core_h",
        "@olp_bb//:OLP_Core_Lib",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/common:UDPLoggingStreamHeaders",
        "@emb_tracker_wrapper//:emb_tracker_wrapper",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "olp_wrapper_h",
    hdrs = [
        "inc/OLP_wrapper.h",
    ],
    strip_include_prefix = "inc",
    visibility = ["//visibility:public"],
    deps = [
        "@olp_bb//:OLP_Core_h",
    ],
)

cc_library(
    name = "olp_wrapper_lib_unit",
    hdrs = [
        "src/OLP_wrapper.cpp",
    ],
    copts = [],
    defines = ["OLP_NUMBER_OF_OBJECTS=64"],
    features = ["-lto"],
    visibility = ["//visibility:public"],
    deps = [
        ":Olp_wrapper_h",
        "//software/common:UDPLoggingStreamHeaders",
        "@emb_tracker_wrapper",
        "@olp_bb//:OLP_Core_h",
    ],
)
