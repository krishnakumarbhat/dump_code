cc_library(
    name = "SWC_PLT_CDD_MCU_Safety_fake_lib",
    srcs = [
        "SWC_PLT_CDD_MCU_Safety_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_CDD_MCU_Safety_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/versions:versions_hdrs",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb:SWC_PLT_CDD_MCU_Safety_h",
        "//software/r52/drivers/mcal/mcu_reset_wrapper:mcu_reset_wrapper_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@fff",
    ],
)

cc_test(
    name = "SWC_PLT_CDD_MCU_Safety_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_CDD_MCU_Safety_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_MCU_Safety_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety:SWC_PLT_CDD_MCU_Safety_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

cc_library(
    name = "dd_cmu_test_mocks",
    hdrs = ["reuse.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "dd_cmu_unit_test",
    size = "small",
    timeout = "short",
    srcs = ["dd_cmu_unit_test.cc"],
    copts = ["-fno-exceptions"],
    linkstatic = True,
    local_defines = ["UNIT_TEST"],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":dd_cmu_test_mocks",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety:PLT_CDD_MCU_Safety_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety:dd_cmu_ut_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":SWC_PLT_CDD_MCU_Safety_unit_test",
        ":dd_cmu_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
