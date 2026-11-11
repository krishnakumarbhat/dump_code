cc_test(
    name = "dd_mmic_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "dd_mmic_unit_test.cc",
    ],
    copts = ["-fpermissive"],
    linkstatic = True,
    local_defines = [
        "UNIT_TEST",
        "__ARM_FEATURE_CRC32=1",
        "CHANDRA_EVB_BOARD",
    ],
    # target_compatible_with = [
    #     "@platforms//cpu:x86_64",
    # ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/mmic:dd_mmic_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@shbb//module/_api:sh_api_h",
    ],
)

cc_test(
    name = "mmic_error_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "mmic_error_unit_test.cc",
    ],
    linkstatic = True,
    # target_compatible_with = [
    #     "@platforms//cpu:x86_64",
    # ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:radar_look_types",
        "//software/r52/mmic:mmic_error_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

cc_test(
    name = "mmic_interface_test",
    size = "small",
    timeout = "short",
    srcs = [
        "mmic_interface_unit_test.cc",
    ],
    linkstatic = True,
    # target_compatible_with = [
    #     "@platforms//cpu:x86_64",
    # ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:UDPLoggingStreamHeaders",
        "//software/common/crc_calc/test/mocks:crc_calc_mocks_lib",
        "//software/r52/mmic:mmic_interface_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":dd_mmic_unit_test",
        ":mmic_interface_test",
        ":mmic_error_unit_test",
        # Add other unit tests here
    ],
    visibility = ["//visibility:public"],
)
