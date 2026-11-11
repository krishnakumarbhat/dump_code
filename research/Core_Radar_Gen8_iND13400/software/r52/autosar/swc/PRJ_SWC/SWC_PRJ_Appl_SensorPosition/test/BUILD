cc_test(
    name = "SWC_PRJ_Appl_SensorPosition_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PRJ_Appl_SensorPosition_unit_test.cc",
    ],
    defines = [],
    linkopts = [],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_SensorPosition:SWC_PRJ_Appl_SensorPosition_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "Appl_SensorPosition_unit_tests",
    tests = [
        ":SWC_PRJ_Appl_SensorPosition_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
