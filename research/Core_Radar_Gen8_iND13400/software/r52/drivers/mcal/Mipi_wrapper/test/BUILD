cc_library(
    name = "Mipi_wrapper_fake_lib",
    srcs = ["Mipi_wrapper_fake.cc"],
    hdrs = [
        "Driver_Port.h",
        "Mipi_wrapper_fake.h",
        "Port.h",
        "board_revision.h",
        "i2c_wrapper.h",
    ],
    strip_include_prefix = "//software/r52/drivers/mcal/Mipi_wrapper/test",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/drivers/mcal/Mipi_wrapper:Mipi_wrapper_h",
        "@fff",
    ],
)

cc_library(
    name = "Mipi_wrapper_swc_textual_lib",
    deps = [
        ":Mipi_wrapper_fake_lib",
        "//software/r52/drivers/mcal/Mipi_wrapper:Mipi_wrapper_h",
        "//software/r52/drivers/mcal/Mipi_wrapper:Mipi_wrapper_unit_test_support_lib",
    ],
)

cc_test(
    name = "Mipi_wrapper_unit_test",
    srcs = ["Mipi_wrapper_unit_test.cc"],
    copts = [
        "-DUNIT_TEST",
        "-Wno-pragma-pack",
    ],
    features = ["-layering_check"],
    target_compatible_with = ["@platforms//cpu:x86_64"],
    deps = [
        ":Mipi_wrapper_fake_lib",
        ":Mipi_wrapper_swc_textual_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:SWC_PLT_PlatformTime_cfg_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [":Mipi_wrapper_unit_test"],
    visibility = ["//visibility:public"],
)
