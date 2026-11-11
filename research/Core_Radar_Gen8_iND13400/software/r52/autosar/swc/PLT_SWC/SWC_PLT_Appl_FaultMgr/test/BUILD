cc_test(
    name = "SWC_PLT_Appl_FaultMgr_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_Appl_FaultMgr_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr:SWC_PLT_Appl_FaultMgr_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr/test:SWC_PLT_Appl_FaultMgr_fake_lib",
        "@com_google_googletest//:gtest_main",
        "@iND13400_autosar_sip//Components/NvM:NvM_h",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_FaultMgr_fake_lib",
    srcs = [
        "SWC_PLT_Appl_FaultMgr_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_Appl_FaultMgr_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr:SWC_PLT_Appl_FaultMgr_h",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":SWC_PLT_Appl_FaultMgr_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)

cc_library(
    name = "appl_faultmgr_fake_lib",
    srcs = [
        "@SWC_PLT_Appl_FaultMgr//test:appl_faultmgr_fake.cc",
    ],
    hdrs = [
        "@SWC_PLT_Appl_FaultMgr//test:appl_faultmgr_fake.h",
    ],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr:appl_faultmgr_unit_test_support_lib",
        "@fff",
    ],
)

cc_library(
    name = "appl_faultmgr_stubs_h",
    srcs = [
        "@SWC_PLT_Appl_FaultMgr//test:appl_faultmgr_stubs.cc",
    ],
    hdrs = [
        "@SWC_PLT_Appl_FaultMgr//test:appl_faultmgr_stubs.h",
    ],
    deps = [
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@reuse",
    ],
)

cc_test(
    name = "appl_faultmgr_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "@SWC_PLT_Appl_FaultMgr//test:appl_faultmgr_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":appl_faultmgr_fake_lib",
        ":appl_faultmgr_stubs_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr:appl_faultmgr_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "plt_unit_tests",
    tests = [
        ":appl_faultmgr_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
