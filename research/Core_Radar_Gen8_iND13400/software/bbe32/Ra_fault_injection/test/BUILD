cc_library(
    name = "Ra_fault_injection_mock_lib",
    srcs = ["Ra_fault_injection_mock.c"],
    hdrs = [
        "Ra_fault_injection_mock.h",
        "chandra_sfrs_base.h",
        "ra_mem_sfrs.h",
        "ra_sfrs.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_test(
    name = "Ra_fault_injection_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "Ra_fault_injection_unit_test.cc",
    ],
    copts = [
        "-fpermissive",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":Ra_fault_injection_mock_lib",
        "//software/bbe32/Ra_fault_injection:Ra_fault_injection_ut_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@reuse",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":Ra_fault_injection_unit_test",
    ],
    visibility = [
        "//visibility:public",
    ],
)
