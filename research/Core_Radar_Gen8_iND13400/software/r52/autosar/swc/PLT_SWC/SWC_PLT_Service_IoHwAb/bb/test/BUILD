cc_library(
    name = "iohwab_adc_fake_lib",
    srcs = [
        "iohwab_fake.cc",
    ],
    hdrs = [
        "iohwab_fake.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb/test",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
        "//software/r52/drivers/mcal/gpt/test/mocks:dd_gpt_mocks",
        "@fff",
    ],
)

cc_library(
    name = "therm_mon_fake_lib",
    srcs = [
        "therm_mon_fake.cc",
    ],
    hdrs = [
        "therm_mon_fake.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb/test",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
        "@fff",
        "@iND13400_autosar_sip//Components/VStdLib",
    ],
)

cc_test(
    name = "iohwab_adc_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "iohwab_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":iohwab_adc_fake_lib",
        "//software/common/board_revision/test/mocks:board_revision_mocks",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:iohwab_adc_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@iND13400_autosar_sip//Components/Adc/test/mocks:Adc_fake_lib",
        "@iND13400_autosar_sip//Components/VStdLib",
    ],
)

cc_test(
    name = "therm_mon_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "therm_mon_unit_test.cc",
    ],
    linkstatic = True,
    local_defines = ["UNIT_TEST"],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":therm_mon_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:iohwab_adc_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@iND13400_autosar_sip//Components/VStdLib",
        "@reuse",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":iohwab_adc_unit_test",
        ":therm_mon_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
