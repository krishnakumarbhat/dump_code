cc_library(
    name = "SWC_PLT_CDD_WdgHandler_fake_lib",
    srcs = [
        "SWC_PLT_CDD_WdgHandler_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_CDD_WdgHandler_fake.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler/test",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@fff",
        "@iND13400_autosar_sip//Components/Wdg:wdg_h",
    ],
)

cc_test(
    name = "SWC_PLT_CDD_WdgHandler_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_CDD_WdgHandler_unit_test.cc",
    ],
    linkstatic = True,
    local_defines = ["ENABLE_SIT_TEST_STUBS=STD_ON"],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/test:FailSafe_callout_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler:SWC_PLT_CDD_WdgHandler_test_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler:SWC_PLT_CDD_WdgHandler_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":SWC_PLT_CDD_WdgHandler_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)

cc_library(
    name = "appl_wdg_handler_fake_lib",
    srcs = [
        "@SWC_PLT_CDD_WdgHandler//test:appl_wdg_handler_fake.cc",
    ],
    hdrs = [
        "@SWC_PLT_CDD_WdgHandler//test:appl_wdg_handler_fake.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@iND13400_autosar_sip//Components/Wdg:wdg_h",
    ],
)

cc_test(
    name = "appl_wdg_handler_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "@SWC_PLT_CDD_WdgHandler//test:appl_wdg_handler_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":appl_wdg_handler_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler:appl_wdg_handler_unit_test_support_lib",
        "@fff",
        "@iND13400_autosar_sip//Components/Wdg:wdg_h",
    ],
)

test_suite(
    name = "plt_unit_tests",
    tests = [
        ":appl_wdg_handler_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
