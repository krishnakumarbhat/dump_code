"""BUILD file for SWC_PLT_CDD_Radar_Control unit tests."""

load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

# Library for fake functions (mocks)
cc_library(
    name = "radar_ctl_fakes",
    srcs = ["SWC_PLT_CDD_Radar_Control_fake.cc"],
    hdrs = [
        "Generic_Drv_sfr.h",
        "Os.h",
        "Rte_SWC_PLT_Appl_NvMHandler.h",
        "Rte_SWC_PLT_CDD_Radar_Control.h",
        "SWC_PLT_CDD_Radar_Control_MemMap.h",
        "SWC_PLT_CDD_Radar_Control_fake.h",
        "Uart.h",
        "cstring",
        "dd_gpt.h",
        "dd_mipi.h",
        "dd_mmic.h",
        "dsp_setup.h",
        "mcal_init.h",
        "mipi_wrapper.h",
        "mmic_error.h",
        "mmic_interface.h",
        "radar_ctl.h",
        "radar_data.h",
    ],
    copts = [
        "-Iexternal/fff",
    ],
    deps = [
        "//software/common:UDPLoggingStreamHeaders",
        "@fff",
    ],
)

# Library wrapping the source code for unit testing
cc_library(
    name = "radar_ctl_src",
    features = ["-layering_check"],
    includes = [
        "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Radar_Control/Source",
    ],
    textual_hdrs = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Radar_Control:Source/SWC_PLT_CDD_Radar_Control.c",
    ],
    deps = [
        ":radar_ctl_fakes",
    ],
)

# Unit test for SWC_PLT_CDD_Radar_Control
cc_test(
    name = "radar_ctl_test",
    size = "small",
    timeout = "short",
    srcs = ["SWC_PLT_CDD_Radar_Control_unit_test.cc"],
    copts = [
        "-Wno-pragma-pack",
        "-DUNIT_TEST",
        "-Isoftware/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Radar_Control/Source",
        "-Isoftware/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Radar_Control/test",
    ],
    features = ["-layering_check"],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":radar_ctl_fakes",
        ":radar_ctl_src",
        "//software/common:UDPLoggingStreamHeaders",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Radar_Control:SWC_PLT_CDD_Radar_Control_source_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@reuse",
    ],
)

# Test suite target
test_suite(
    name = "unit_tests",
    tests = [
        ":radar_ctl_test",
    ],
    visibility = ["//visibility:public"],
)
