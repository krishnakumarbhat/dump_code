cc_library(
    name = "appl_RTM_fake_lib",
    srcs = [
        "appl_RTM_fake.cc",
    ],
    hdrs = [
        "appl_RTM_fake.h",
    ],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_RTM",
        "@fff",
        "@iND13400_autosar_sip//Components/Gpt:gpt_h",
        "@iND13400_autosar_sip//Components/Rtm:Rtm_h",
    ],
)

cc_test(
    name = "appl_RTM_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "appl_RTM_unit_test.cc",
    ],
    copts = ["-fno-exceptions"],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        ":appl_RTM_fake_lib",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_RTM:appl_RTM_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@iND13400_autosar_sip//Components/Det:Det_h",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":appl_RTM_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
