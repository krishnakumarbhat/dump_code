package(default_visibility = ["//visibility:public"])

exports_files(glob(["**/*"]))

cc_library(
    name = "mpu_h",
    hdrs = [
        "exceptions.h",
        "mpu.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "mpu_ut_lib",
    hdrs = ["mpu.c"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [":mpu_h"],
)

cc_library(
    name = "exceptions_ut_lib",
    hdrs = ["exceptions.c"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":mpu_h",
        "//software/bbe32/inc:ipc_dsp_h",
    ],
)

cc_library(
    name = "mpu",
    srcs = [
        "mpu.c",
    ],
    hdrs = [
        "mpu.h",
    ],
    defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":exceptions",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "exceptions",
    srcs = [
        "exceptions.c",
    ],
    hdrs = [
        "exceptions.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:private"],
    deps = [
        "//software/bbe32/inc:ipc_dsp_h",
    ],
)
