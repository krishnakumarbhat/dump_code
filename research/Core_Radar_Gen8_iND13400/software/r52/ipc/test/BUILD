cc_test(
    name = "ipc_mss_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "ipc_mss_unit_test.cc",
    ],
    copts = [
        "-fpermissive",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/crc_calc/test/mocks:crc_calc_mocks_lib",
        "//software/common/ipc/test/mocks:ipc_data_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/test:swc_platformtime_fakes",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync/test:Rte_SWC_PLT_CDD_Radar_Control_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync/test:SWC_PLT_CDD_ECUSync_external_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/test:FS_IntHndlr_fake_lib",
        "//software/r52/integration_test:master_it_macros_test_h",
        "//software/r52/ipc:ipc_mss_unit_test_support_lib",
        "//software/r52/program_flow_monitor/test/mocks:program_flow_monitor_mocks_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:priv_sfrs",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [":ipc_mss_unit_test"],
    visibility = ["//visibility:public"],
)
