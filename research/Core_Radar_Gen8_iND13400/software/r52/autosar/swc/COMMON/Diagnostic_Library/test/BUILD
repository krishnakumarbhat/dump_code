cc_library(
    name = "fault_lib_Plt_fake_lib",
    srcs = [
        "Fault_Lib_Plt_fake.cc",
    ],
    hdrs = [
        "Fault_Lib_Plt_fake.h",
    ],
    deps = [
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_support_lib",
        "@fff",
    ],
)

cc_library(
    name = "fault_lib_Prj_fake_lib",
    srcs = [
        "Fault_Lib_Prj_fake.cc",
    ],
    hdrs = [
        "Fault_Lib_Prj_fake.h",
    ],
    deps = [
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj_support_lib",
        "@fff",
    ],
)

cc_test(
    name = "fault_lib_Plt_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "Fault_Lib_Plt_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":fault_lib_Plt_fake_lib",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_support_lib",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "fault_lib_Prj_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "Fault_Lib_Prj_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":fault_lib_Prj_fake_lib",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj_support_lib",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":fault_lib_Plt_unit_test",
        ":fault_lib_Prj_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
