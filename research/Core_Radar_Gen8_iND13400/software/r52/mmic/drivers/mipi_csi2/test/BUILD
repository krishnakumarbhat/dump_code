cc_test(
    name = "dd_mipi_csi2_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "dd_mipi_csi2_unit_test.cc",
    ],
    copts = [
        "-fpermissive",  # Allow volatile struct assignment in C++ for testing
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/mmic/drivers/mipi_csi2:mipi_csi2_unit_test_support_lib",
        "//software/r52/mmic/drivers/mipi_csi2/test/mocks:mipi_interrupt_fake_lib",
        "@com_google_googletest//:gtest_main",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)

cc_test(
    name = "mipi_interrupt_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "mipi_interrupt_unit_test.cc",
    ],
    copts = [
        "-fpermissive",
        "-Wno-macro-redefined",
    ],
    features = ["-layering_check"],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/mmic/drivers/mipi_csi2:mipi_interrupt_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":dd_mipi_csi2_unit_test",
        ":mipi_interrupt_unit_test",
    ],
    visibility = ["//visibility:public"],
)
