cc_library(
    name = "dss_ecc_parity_mock_lib",
    srcs = [
        "dss_ecc_parity_mock.c",
    ],
    hdrs = [
        "dss_ecc_parity_mock.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_test(
    name = "dss_ecc_parity_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "dss_ecc_parity_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":dss_ecc_parity_mock_lib",
        "//software/bbe32/dss_ecc_parity:dss_ecc_parity_ut_lib",
        "//software/bbe32/src/test:xtensa_stubs",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":dss_ecc_parity_unit_test",
    ],
    visibility = [
        "//visibility:public",
    ],
)
