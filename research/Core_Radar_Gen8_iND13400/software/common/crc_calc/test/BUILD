cc_library(
    name = "generic_drv_sfr_stub",
    hdrs = ["Generic_Drv_sfr.h"],
    strip_include_prefix = "//software/common/crc_calc/test",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "crc_calc_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "crc_calc_unit_test.cc",
    ],
    copts = [
        "-fno-exceptions",
        "-DUNIT_TEST",
        "-DCHANDRA_B0",
    ],
    # Force low image base on Windows so embedded uint32_t <-> pointer casts
    # in the source under test survive the 64-bit round-trip.
    linkopts = select({
        "@platforms//os:windows": ["-Wl,--image-base,0x10000"],
        "//conditions:default": [],
    }),
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":generic_drv_sfr_stub",
        "//software/common/crc_calc:crc_calc_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":crc_calc_unit_test",
        # Add other unit tests here
    ],
    visibility = ["//visibility:public"],
)
