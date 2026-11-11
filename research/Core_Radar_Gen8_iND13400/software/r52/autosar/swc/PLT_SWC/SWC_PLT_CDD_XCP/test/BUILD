cc_library(
    name = "SWC_PLT_CDD_XCP_xcp_logging_fake_lib",
    srcs = [
        "SWC_PLT_CDD_XCP_xcp_logging_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_CDD_XCP.h",
        "Xcp.h",
        "dsp_setup.h",
        "ipc_mss.h",
        "reuse.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/test",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "SWC_PLT_CDD_XCP_xcp_logging_lib",
    srcs = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP:Source/xcp_logging.c",
    ],
    copts = [
        "-Isoftware/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/test",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_XCP_xcp_logging_fake_lib",
    ],
)

cc_test(
    name = "SWC_PLT_CDD_XCP_xcp_logging_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_CDD_XCP_xcp_logging_unit_test.cc",
    ],
    copts = [
        "-Isoftware/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/test",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_XCP_xcp_logging_fake_lib",
        ":SWC_PLT_CDD_XCP_xcp_logging_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_XCP_core_host_slice_lib",
    srcs = [
        "SWC_PLT_CDD_XCP_core_host_slice.c",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP:SWC_PLT_CDD_XCP_source_support_lib",
    ],
)

cc_library(
    name = "XcpAppl_core_host_slice_lib",
    srcs = [
        "XcpAppl_core_host_slice.c",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP:SWC_PLT_CDD_XCP_source_support_lib",
    ],
)

cc_test(
    name = "SWC_PLT_CDD_XCP_core_host_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_CDD_XCP_core_host_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_XCP_core_host_slice_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP:SWC_PLT_CDD_XCP_source_support_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "XcpAppl_core_host_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "XcpAppl_core_host_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":XcpAppl_core_host_slice_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP:SWC_PLT_CDD_XCP_source_support_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":SWC_PLT_CDD_XCP_core_host_unit_test",
        ":SWC_PLT_CDD_XCP_xcp_logging_unit_test",
        ":XcpAppl_core_host_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)

test_suite(
    name = "core_unit_tests",
    tests = [
        ":SWC_PLT_CDD_XCP_core_host_unit_test",
        ":SWC_PLT_CDD_XCP_xcp_logging_unit_test",
        ":XcpAppl_core_host_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
