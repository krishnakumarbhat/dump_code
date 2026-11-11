load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "mpu_fake_lib",
    srcs = ["mpu_fake.cc"],
    hdrs = [
        "mpu_fake.h",
    ],
    strip_include_prefix = "//software/bbe32/mpu/test",
    visibility = ["//visibility:public"],
    deps = [
        "@fff",
    ],
)

cc_library(
    name = "mpu_textual_lib",
    deps = [
        ":mpu_fake_lib",
        "//software/bbe32/mpu:mpu_h",
        "//software/bbe32/mpu:mpu_ut_lib",
    ],
)

cc_test(
    name = "mpu_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "mpu_unit_test.cc",
    ],
    copts = [
        "-Wno-pragma-pack",
        "-DUNIT_TEST",
    ],
    features = ["-layering_check"],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":mpu_fake_lib",
        ":mpu_textual_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":exceptions_unit_test",
        ":mpu_unit_test",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "xtensa_stubs",
    hdrs = ["xtensa/xtruntime.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "exceptions_fake_lib",
    srcs = ["exceptions_fake.cc"],
    hdrs = ["exceptions_fake.h"],
    strip_include_prefix = "//software/bbe32/mpu/test",
    visibility = ["//visibility:public"],
    deps = ["@fff"],
)

cc_library(
    name = "exceptions_textual_lib",
    deps = [
        ":exceptions_fake_lib",
        ":xtensa_stubs",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/mpu:exceptions_ut_lib",
        "//software/bbe32/mpu:mpu_h",
    ],
)

cc_test(
    name = "exceptions_unit_test",
    size = "small",
    timeout = "short",
    srcs = ["exceptions_unit_test.cc"],
    copts = [
        "-Wno-pragma-pack",
        "-DUNIT_TEST",
        "-fpermissive",
    ],
    features = ["-layering_check"],
    linkstatic = True,
    target_compatible_with = ["@platforms//cpu:x86_64"],
    visibility = ["//visibility:public"],
    deps = [
        ":exceptions_fake_lib",
        ":exceptions_textual_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)
