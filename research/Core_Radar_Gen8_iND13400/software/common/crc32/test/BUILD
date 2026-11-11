load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "crc32_unit_test_support_lib",
    srcs = [],
    hdrs = [],
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/crc32:crc32_ut_lib",
        "@com_google_googletest//:gtest",
        "@fff",
    ],
)

cc_test(
    name = "crc32_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "crc32_unit_test.cc",
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
        ":crc32_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":crc32_unit_test",
    ],
    visibility = ["//visibility:public"],
)
