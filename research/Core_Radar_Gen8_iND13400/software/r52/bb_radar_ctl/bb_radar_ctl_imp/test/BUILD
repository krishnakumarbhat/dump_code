cc_test(
    name = "radar_ctl_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "radar_ctl_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/calibrations/smc:smc_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/test:swc_platformtime_fakes",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync:SWC_PLT_CDD_ECUSync_external_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync/test:SWC_PLT_CDD_ECUSync_external_fake_lib",
        "//software/r52/bb_radar_ctl:radar_ctl_unit_test_support_lib",
        "//software/r52/bb_radar_ctl/bb_radar_ctl_imp/test/mocks:radar_ctl_fake_lib",
        "//software/r52/bb_radar_ctl/bb_radar_ctl_imp/test/mocks:radar_data_fake_lib",
        "//software/r52/bb_radar_ctl/bb_radar_ctl_imp/test/mocks:radar_look_fake_lib",
        "//software/r52/mmic/test/mocks:mmic_interface_fake_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
    ],
)

cc_test(
    name = "radar_look_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "radar_look_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb:SWC_PLT_Appl_XCP_H",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb/test/mocks:xcp_bb_fake_lib",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/bb_radar_ctl:radar_look_unit_test_support_lib",
        "//software/r52/bb_radar_ctl/bb_radar_ctl_imp/test/mocks:radar_ctl_fake_lib",
        "//software/r52/bb_radar_ctl/bb_radar_ctl_imp/test/mocks:radar_look_fake_lib",
        "//software/r52/mmic/test/mocks:dd_mmic_fake_lib",
        "//software/r52/mmic/test/mocks:mmic_error_fake_lib",
        "//software/r52/mmic/test/mocks:mmic_interface_fake_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

cc_test(
    name = "radar_data_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "radar_data_fake.h",
        "radar_data_unit_test.cc",
    ],
    copts = [
        "-Wno-pragma-pack",
        "-DUNIT_TEST",
    ],
    features = ["-layering_check"],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/bb_radar_ctl:radar_data_ut_lib",
        "//software/r52/bb_radar_ctl/bb_radar_ctl_imp/test/mocks:radar_data_fake_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":radar_ctl_unit_test",
        ":radar_data_unit_test",
        ":radar_look_unit_test",
    ],
    visibility = ["//visibility:public"],
)
