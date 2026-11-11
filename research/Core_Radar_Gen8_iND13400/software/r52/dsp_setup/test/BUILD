cc_library(
    name = "generic_drv_sfr_stub",
    hdrs = ["Generic_Drv_sfr.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = ["@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:priv_sfrs"],
)

cc_test(
    name = "dsp_setup_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "dsp_setup_unit_test.cc",
    ],
    copts = [
        "-fpermissive",
    ],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        ":generic_drv_sfr_stub",
        "//software/common:UDPLoggingStreamHeaders",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
        "//software/common/crc_calc:crc_calc_h",
        "//software/common/ipc/test/mocks:ipc_data_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/test:platformtime_fff",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync/test:Rte_SWC_PLT_CDD_Radar_Control_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync/test:SWC_PLT_CDD_ECUSync_external_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging/SH:sh_interface_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler:SWC_PLT_Radar_Alignment_Handler_h",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/dsp_setup:dsp_setup_ut_lib",
        "//software/r52/integration_test:master_it_macros_test_h",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/ipc/test/mocks:ipc_mss_fake_lib",
        "//software/r52/mmic:mmic_h",
        "//software/r52/mmic/test/mocks:dd_mmic_fake_lib",
        "//software/r52/program_flow_monitor/test/mocks:program_flow_monitor_mocks_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:priv_sfrs",
        "@shbb//module/_api:sh_api_h",
        "@shbb//module/_test/mocks:sh_rx_mocks_lib",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [":dsp_setup_unit_test"],
    visibility = ["//visibility:public"],
)
