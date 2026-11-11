cc_test(
    name = "mars_api_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "mars_api_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/mmic/drivers/mars_api:mars_api_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":mars_api_unit_test",
        # Add other unit tests here
    ],
    visibility = ["//:__pkg__"],
)
