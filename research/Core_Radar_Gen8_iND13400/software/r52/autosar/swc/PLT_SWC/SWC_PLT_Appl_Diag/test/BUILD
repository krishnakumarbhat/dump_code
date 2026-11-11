cc_test(
    name = "Platform_Diag_Callout_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "Platform_Diag_Callout_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag:Platform_Diag_Callout_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag/test/mocks:Platform_Diag_Callout_fake_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

cc_test(
    name = "SWC_PLT_Appl_Diag_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_Appl_Diag_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag:SWC_PLT_Appl_Diag_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag/test/mocks:Platform_Diag_Callout_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag/test/mocks:SWC_PLT_Appl_Diag_fake_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":Platform_Diag_Callout_unit_test",
        ":SWC_PLT_Appl_Diag_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)

cc_library(
    name = "PLT_Appl_Diag_fake_lib",
    srcs = [
        "@SWC_PLT_Appl_Diag//test:mocks/SWC_PLT_Appl_Diag_fake.cc",
    ],
    hdrs = [
        "@SWC_PLT_Appl_Diag//test:mocks/SWC_PLT_Appl_Diag_fake.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag:SWC_PLT_Appl_Diag_h",
        "@fff",
    ],
)

cc_library(
    name = "appl_diag_fake_lib",
    srcs = [
        "@SWC_PLT_Appl_Diag//test:appl_diag_fake.cc",
    ],
    hdrs = [
        "@SWC_PLT_Appl_Diag//test:appl_diag_fake.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":PLT_Appl_Diag_fake_lib",
        "//software/common/calibrations/psc:psc_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag:appl_diag_unit_test_support_lib",
        "@Calibration_Handler//:calibration_h",
        "@Sensor_Position//:sensor_position_h",
        "@fff",
    ],
)

cc_test(
    name = "appl_diag_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "@SWC_PLT_Appl_Diag//test:appl_diag_unit_test.cc",
    ],
    copts = ["-fno-exceptions"],
    linkstatic = True,
    local_defines = ["UNIT_TEST"],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":appl_diag_fake_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "plt_unit_tests",
    tests = [
        ":appl_diag_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
