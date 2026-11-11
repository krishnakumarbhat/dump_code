cc_test(
    name = "xcp_bb_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "xcp_bb_unit_test.cc",
    ],
    copts = ["-fno-exceptions"],
    linkstatic = True,
    local_defines = ["UNIT_TEST"],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb:xcp_bb_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb/test/mocks:xcp_user_cmds_fake_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

cc_test(
    name = "xcp_user_cmds_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "xcp_user_cmds_unit_test.cc",
    ],
    copts = ["-fno-exceptions"],
    linkstatic = True,
    local_defines = ["UNIT_TEST"],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb:xcp_user_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":xcp_bb_unit_test",
        ":xcp_user_cmds_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
