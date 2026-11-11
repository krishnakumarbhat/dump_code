load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "program_flow_monitor_fake_lib",
    srcs = ["program_flow_monitor_fake.cc"],
    hdrs = ["program_flow_monitor_fake.h"],
    strip_include_prefix = "//software/r52/program_flow_monitor/test",
    visibility = ["//visibility:public"],
    deps = [
        "@fff",
    ],
)

cc_test(
    name = "program_flow_monitor_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "program_flow_monitor_unit_test.cc",
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
        ":program_flow_monitor_fake_lib",
        "//software/r52/program_flow_monitor:program_flow_monitor_ut_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":program_flow_monitor_unit_test",
    ],
    visibility = ["//visibility:public"],
)
