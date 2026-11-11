cc_library(
    name = "SWC_PRJ_Appl_Power_Manager_fake_lib",
    testonly = True,
    srcs = [
        "SWC_PRJ_Appl_Power_Manager_fake.cc",
    ],
    hdrs = [
        "SWC_PRJ_Appl_Power_Manager_fake.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_Power_Manager/test",
    deps = [
        "//software/common/board_revision:board_revision_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_Power_Manager:SWC_PRJ_Appl_Power_Manager_h",
        "//software/r52/drivers/mcal/dio_wrapper:dio_wrapper_h",
        "@fff",
    ],
)

cc_test(
    name = "SWC_PRJ_Appl_Power_Manager_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PRJ_Appl_Power_Manager_unit_test.cc",
    ],
    defines = [],
    linkopts = [],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PRJ_Appl_Power_Manager_fake_lib",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_Power_Manager:SWC_PRJ_Appl_Power_Manager_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "Appl_Power_Manager_unit_tests",
    tests = [
        ":SWC_PRJ_Appl_Power_Manager_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
