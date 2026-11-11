cc_test(
    name = "mcu_reset_wrapper_test",
    size = "small",
    timeout = "short",
    srcs = ["mcu_reset_wrapper_test.cc"],
    copts = ["-fno-exceptions"],
    linkstatic = True,
    local_defines = ["UNIT_TEST"],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/drivers/mcal/mcu_reset_wrapper:mcu_reset_wrapper_ut_lib",
        "//software/r52/drivers/mcal/mcu_reset_wrapper/test/mocks:mcu_reset_wrapper_test_mocks",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [":mcu_reset_wrapper_test"],
    visibility = ["//visibility:public"],
)
