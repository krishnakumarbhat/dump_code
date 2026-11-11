cc_library(
    name = "FailSafe_fake_lib",
    srcs = [
        "FailSafe_fake.cc",
    ],
    hdrs = [
        "FailSafe_fake.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_h",
        "//software/r52/drivers/mcal/mcu_reset_wrapper:mcu_reset_wrapper_h",
        "@fff",
    ],
)

cc_library(
    name = "FailSafe_callout_fake_lib",
    srcs = [
        "FailSafe_callout_fake.cc",
    ],
    hdrs = [
        "FailSafe_callout_fake.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_h",
        "@fff",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
    ],
)

cc_test(
    name = "FailSafe_Callout_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "FailSafe_Callout_unit_test.cc",
    ],
    linkstatic = True,
    local_defines = ["UNIT_TEST"],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":FailSafe_callout_fake_lib",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:FailSafe_Callout_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "FailSafe_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "FailSafe_unit_test.cc",
    ],
    copts = ["-fno-exceptions"],
    linkstatic = True,
    local_defines = ["UNIT_TEST"],
    visibility = ["//visibility:public"],
    deps = [
        ":FailSafe_fake_lib",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:FS_IntHndlr_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_unit_test_support_lib",
        "@boot//:boot_interface",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

cc_library(
    name = "FS_IntHndlr_fake_lib",
    srcs = [
        "FS_IntHndlr_fake.cc",
    ],
    hdrs = [
        "FS_IntHndlr_fake.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/test",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/versions:versions_hdrs",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_h",
        "@fff",
    ],
)

cc_test(
    name = "FS_IntHndlr_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "FS_IntHndlr_unit_test.cc",
    ],
    linkstatic = True,
    local_defines = ["UNIT_TEST"],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":FS_IntHndlr_fake_lib",
        ":FailSafe_fake_lib",
        "//software/common/versions:versions_hdrs",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:FS_IntHndlr_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":FailSafe_unit_test",
        ":FailSafe_Callout_unit_test",
        ":FS_IntHndlr_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
