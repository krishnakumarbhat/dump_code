cc_test(
    name = "SWC_PLT_CDD_Logging_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_CDD_Logging_host_slice.c",
        "SWC_PLT_CDD_Logging_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging:SWC_PLT_CDD_Logging_source_support_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":SWC_PLT_CDD_Logging_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
