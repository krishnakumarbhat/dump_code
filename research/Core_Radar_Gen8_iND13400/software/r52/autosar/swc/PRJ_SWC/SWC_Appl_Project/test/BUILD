cc_library(
    name = "SWC_Appl_Project_fake_lib",
    testonly = True,
    srcs = [
        "SWC_Appl_Project_fake.cc",
    ],
    hdrs = [
        "SWC_Appl_Project_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "@fff",
        "@iND13400_autosar_sip//Components/Dio:Dio_h",
    ],
)

cc_test(
    name = "SWC_Appl_Project_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_Appl_Project_fake.cc",
        "SWC_Appl_Project_fake.h",
        "SWC_Appl_Project_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_Appl_Project",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@iND13400_autosar_sip//Components/Dio:Dio_h",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":SWC_Appl_Project_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
