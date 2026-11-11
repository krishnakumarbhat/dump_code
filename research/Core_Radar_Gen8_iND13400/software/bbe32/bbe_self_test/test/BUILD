load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "fusa_bbe_self_test_fake_lib",
    srcs = [],
    hdrs = [
        "fusa_bbe_self_test_fake.h",
    ],
    strip_include_prefix = "//software/bbe32/bbe_self_test/test",
    visibility = ["//visibility:public"],
    deps = [
        "@fff",
    ],
)

cc_library(
    name = "fusa_bbe_self_test_unit_test_support_lib",
    srcs = [],
    hdrs = [],
    visibility = ["//visibility:public"],
    deps = [
        ":fusa_bbe_self_test_fake_lib",
        "//software/bbe32/bbe_self_test:fusa_bbe_self_test_ut_lib",
        "@com_google_googletest//:gtest",
        "@fff",
    ],
)

cc_test(
    name = "fusa_bbe_self_test_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "fusa_bbe_self_test_unit_test.cc",
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
        ":fusa_bbe_self_test_fake_lib",
        ":fusa_bbe_self_test_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":fusa_bbe_self_test_unit_test",
    ],
    visibility = ["//visibility:public"],
)
