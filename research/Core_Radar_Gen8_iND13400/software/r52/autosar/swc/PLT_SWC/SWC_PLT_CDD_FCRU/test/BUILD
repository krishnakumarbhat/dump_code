cc_library(
    name = "SWC_PLT_CDD_FCRU_fake_lib",
    srcs = [
        "SWC_PLT_CDD_FCRU_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_CDD_FCRU_fake.h",
    ],
    deps = [
        "//software/common/board_revision:board_revision_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FCRU",
        "@boot//:boot_interface",
        "@fff",
    ],
)

cc_test(
    name = "SWC_PLT_CDD_FCRU_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_CDD_FCRU_unit_test.cc",
    ],
    defines = [],
    linkopts = [],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_FCRU_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FCRU:SWC_PLT_CDD_FCRU_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "FCRU_unit_tests",
    tests = [
        ":SWC_PLT_CDD_FCRU_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
