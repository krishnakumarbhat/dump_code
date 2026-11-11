load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "stack_monitor_r52_fake_lib",
    srcs = [
        "stack_monitor_r52_fake.cc",
    ],
    hdrs = [
        "stack_monitor_r52_fake.h",
    ],
    strip_include_prefix = "//software/r52/r52_stack/test",
    visibility = ["//visibility:public"],
    deps = [
        "@fff",
    ],
)

cc_library(
    name = "stack_monitor_r52_unit_test_support_lib",
    hdrs = [
        "//software/r52/r52_stack:stack_monitor_r52.c",
        "//software/r52/r52_stack:stack_monitor_r52.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":stack_monitor_r52_fake_lib",
        "@com_google_googletest//:gtest",
        "@fff",
    ],
)

cc_test(
    name = "stack_monitor_r52_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "stack_monitor_r52_unit_test.cc",
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
        ":stack_monitor_r52_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":stack_monitor_r52_unit_test",
    ],
    visibility = ["//visibility:public"],
)
