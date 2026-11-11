cc_library(
    name = "SWC_PLT_Appl_IoHwAb_fake_lib",
    srcs = [
        "SWC_PLT_Appl_IoHwAb_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_Appl_IoHwAb_fake.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb/test",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/board_revision:board_revision_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@fff",
    ],
)

cc_test(
    name = "SWC_PLT_Appl_IoHwAb_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_Appl_IoHwAb_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/board_revision/test/mocks:board_revision_mocks",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:SWC_PLT_Appl_IoHwAb_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@iND13400_autosar_sip//Components/_Common:Eth_GeneralTypes_h",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":SWC_PLT_Appl_IoHwAb_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)

cc_library(
    name = "psc_cal_stub_lib",
    srcs = [
        "psc_cal_stub.c",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/calibrations/psc:psc_h",
    ],
)

cc_library(
    name = "iohwab_adc_appl_fake_lib",
    srcs = [
        "@SWC_PLT_Appl_IoHwAb//test:iohwab_adc_appl_fake.cc",
    ],
    hdrs = [
        "@SWC_PLT_Appl_IoHwAb//test:iohwab_adc_appl_fake.h",
    ],
    strip_include_prefix = "/test",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:iohwab_adc_appl_unit_test_support_lib",
        "@fff",
    ],
)

cc_test(
    name = "iohwab_adc_appl_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "@SWC_PLT_Appl_IoHwAb//test:iohwab_adc_appl_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":iohwab_adc_appl_fake_lib",
        ":psc_cal_stub_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:PLT_Appl_IoHwAb_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:iohwab_adc_appl_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
        "@Gen8_iND13400//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "plt_unit_tests",
    tests = [
        ":iohwab_adc_appl_unit_test",
        ":psc_cal_impl_unit_test",
        ":volt_monitor_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)

cc_library(
    name = "volt_monit_fake_lib",
    srcs = [
        "@SWC_PLT_Appl_IoHwAb//test:volt_monitor_fake.cc",
    ],
    hdrs = [
        "@SWC_PLT_Appl_IoHwAb//test:volt_monitor_fake.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:volt_Monitor_unit_test_support_lib",
        "@fff",
    ],
)

cc_test(
    name = "volt_monitor_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "@SWC_PLT_Appl_IoHwAb//test:volt_monitor_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":volt_monit_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:volt_Monitor_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "psc_cal_impl_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "psc_cal_impl_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/board_revision/test/mocks:board_revision_mocks",
        "//software/common/calibrations/psc:psc_module",
        "@com_google_googletest//:gtest_main",
    ],
)
