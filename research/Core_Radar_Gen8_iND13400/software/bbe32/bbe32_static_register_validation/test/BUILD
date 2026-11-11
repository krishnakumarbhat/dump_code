load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "bbe32_static_register_validation_fake_lib",
    srcs = [],
    hdrs = [
        "bbe32_static_register_validation_fake.h",
    ],
    strip_include_prefix = "//software/bbe32/bbe32_static_register_validation/test",
    visibility = ["//visibility:public"],
    deps = [
        "@fff",
    ],
)

cc_library(
    name = "bbe32_static_register_validation_unit_test_support_lib",
    srcs = [],
    hdrs = [],
    visibility = ["//visibility:public"],
    deps = [
        ":bbe32_static_register_validation_fake_lib",
        "//software/bbe32/bbe32_static_register_validation:bbe32_static_register_validation_ut_lib",
        "@com_google_googletest//:gtest",
        "@fff",
    ],
)

cc_test(
    name = "bbe32_static_register_validation_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "bbe32_static_register_validation_unit_test.cc",
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
        ":bbe32_static_register_validation_fake_lib",
        ":bbe32_static_register_validation_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":bbe32_static_register_validation_unit_test",
    ],
    visibility = ["//visibility:public"],
)
