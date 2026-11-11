load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

# Common test dependencies
TEST_DEPS = [
    "@com_google_googletest//:gtest_main",
    "@fff",
]

# Cdd_Cbk test
cc_library(
    name = "cdd_cbk_test_lib",
    srcs = ["Cdd_Cbk_wrapper.c"],
    hdrs = ["Cdd_Cbk_fakes.h"],
    deps = ["@fff"],
)

cc_test(
    name = "Cdd_Cbk_unit_test",
    size = "small",
    srcs = ["Cdd_Cbk_unit_test.cc"],
    deps = [
        ":cdd_cbk_test_lib",
    ] + TEST_DEPS,
)

# Os_Callout_Stubs test
cc_library(
    name = "os_callout_test_lib",
    srcs = ["Os_Callout_Stubs_wrapper.c"],
    hdrs = ["Os_Callout_fakes.h"],
    deps = ["@fff"],
)

cc_test(
    name = "Os_Callout_Stubs_unit_test",
    size = "small",
    srcs = ["Os_Callout_Stubs_unit_test.cc"],
    deps = [
        ":os_callout_test_lib",
    ] + TEST_DEPS,
)

# BswM_Callout_Stubs test
cc_library(
    name = "bswm_callout_test_lib",
    srcs = ["BswM_Callout_Stubs_wrapper.c"],
    hdrs = ["BswM_Callout_fakes.h"],
    deps = ["@fff"],
)

cc_test(
    name = "BswM_Callout_Stubs_unit_test",
    size = "small",
    srcs = ["BswM_Callout_Stubs_unit_test.cc"],
    deps = [
        ":bswm_callout_test_lib",
    ] + TEST_DEPS,
)

# EthIf_User_Cbk test
cc_library(
    name = "ethif_user_cbk_test_lib",
    srcs = ["EthIf_User_Cbk_wrapper.c"],
    hdrs = ["EthIf_User_Cbk_fakes.h"],
    deps = ["@fff"],
)

cc_test(
    name = "EthIf_User_Cbk_unit_test",
    size = "small",
    srcs = ["EthIf_User_Cbk_unit_test.cc"],
    deps = [
        ":ethif_user_cbk_test_lib",
    ] + TEST_DEPS,
)

# EcuM_Callout_Stubs test
cc_library(
    name = "ecum_callout_test_lib",
    srcs = ["EcuM_Callout_Stubs_wrapper.c"],
    hdrs = ["EcuM_Callout_fakes.h"],
    copts = ["-DUNIT_TEST"],
    deps = ["@fff"],
)

cc_test(
    name = "EcuM_Callout_Stubs_unit_test",
    size = "small",
    srcs = ["EcuM_Callout_Stubs_unit_test.cc"],
    deps = [
        ":ecum_callout_test_lib",
    ] + TEST_DEPS,
)

# PHY_User_Cbk test
cc_library(
    name = "phy_user_cbk_test_lib",
    srcs = ["PHY_User_Cbk_wrapper.c"],
    hdrs = ["PHY_User_Cbk_fakes.h"],
    deps = ["@fff"],
)

cc_test(
    name = "PHY_User_Cbk_unit_test",
    size = "small",
    srcs = ["PHY_User_Cbk_unit_test.cc"],
    deps = [
        ":phy_user_cbk_test_lib",
    ] + TEST_DEPS,
)

# Test suite aggregating all tests
test_suite(
    name = "unit_tests",
    tests = [
        ":BswM_Callout_Stubs_unit_test",
        ":Cdd_Cbk_unit_test",
        ":EcuM_Callout_Stubs_unit_test",
        ":EthIf_User_Cbk_unit_test",
        ":Os_Callout_Stubs_unit_test",
        ":PHY_User_Cbk_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
