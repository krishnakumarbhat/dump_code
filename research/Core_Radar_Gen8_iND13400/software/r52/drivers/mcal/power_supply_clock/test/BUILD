cc_test(
    name = "power_supply_clock_test",
    size = "small",
    timeout = "short",
    srcs = ["power_supply_clock_test.cc"],
    copts = ["-fno-exceptions"],
    linkstatic = True,
    local_defines = [
        "UNIT_TEST",
        "DEVELOPMENT_ONLY",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/drivers/mcal/power_supply_clock:power_supply_clock_ut_lib",
        "//software/r52/drivers/mcal/power_supply_clock/test/mocks:power_supply_clock_test_mocks",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [":power_supply_clock_test"],
    visibility = ["//visibility:public"],
)
