load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "sh_interface_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "sh_interface_unit_test.cc",
    ],
    copts = [
        "-DUNIT_TEST",
        "-std=gnu++17",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging/SH:sh_interface_ut_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging/SH/test/mocks:sh_interface_mock_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":sh_interface_unit_test",
        "@shbb//module:sh_unit_test_lib",
    ],
    visibility = ["//visibility:public"],
)
