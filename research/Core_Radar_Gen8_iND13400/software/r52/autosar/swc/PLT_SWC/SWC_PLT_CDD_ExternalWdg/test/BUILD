cc_library(
    name = "SWC_PLT_CDD_ExternalWdg_fake_lib",
    srcs = [
        "SWC_PLT_CDD_ExternalWdg_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_CDD_ExternalWdg_fake.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg/test",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@fff",
    ],
)

cc_test(
    name = "dd_pmic_test",
    size = "small",
    timeout = "short",
    srcs = [
        "dd_pmic_test.cc",
    ],
    copts = ["-fno-exceptions"],
    linkstatic = True,
    local_defines = ["UNIT_TEST"],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg:dd_pmic_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
        "//software/r52/drivers/mcal/gpt/test/mocks:dd_gpt_mocks",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

cc_test(
    name = "SWC_PLT_CDD_ExternalWdg_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_CDD_ExternalWdg_unit_test.cc",
    ],
    linkstatic = True,
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }) + select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }) + ["UNIT_TEST"],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg:SWC_PLT_CDD_ExternalWdg_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg/test/mocks:dd_pmic_mocks",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":SWC_PLT_CDD_ExternalWdg_unit_test",
        ":dd_pmic_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
