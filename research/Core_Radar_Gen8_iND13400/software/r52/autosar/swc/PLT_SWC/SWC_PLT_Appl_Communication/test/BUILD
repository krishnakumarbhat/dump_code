cc_test(
    name = "swc_plt_appl_comm_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_Appl_Communication_unit_test.cc",
    ],
    copts = ["-fno-exceptions"],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:SWC_PLT_Appl_Communication_source_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/can:can_tx_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/someip:someip_services_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/test/fakes:can_tx_msgs_fakes_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:PLT_Appl_PlatformTime_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler:SWC_PLT_Radar_Alignment_Handler_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@iND13400_autosar_sip//Components/CanSM:CanSM_h",
        "@iND13400_autosar_sip//Components/Com:Com_h",
        "@iND13400_autosar_sip//Components/ComM:ComM_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)

cc_test(
    name = "can_tx_msgs_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "can_tx_msgs_unit_test.cc",
    ],
    copts = ["-fno-exceptions"],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/common/ipc:ipc_data_h",
        "//software/common/versions:versions_hdrs",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/can:can_tx_ut_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/test/mocks:can_tx_msgs_stubs_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync:SWC_PLT_CDD_ECUSync_external_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync:SWC_PLT_CDD_ECUSync_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb:SWC_PLT_Appl_XCP_H",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler:SWC_PLT_Radar_Alignment_Handler_h",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/mmic:mmic_error_h",
        "//software/r52/mmic:mmic_h",
        "@Gen8_iND13400//software/common/calibrations/smc:smc_h",
        "@Gen8_iND13400//software/common/calibrations/usc:usc_h",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging:SWC_PLT_CDD_LOGGING_h",
        "@Sensor_Position//:sensor_position_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

# Unit test for CAN RX messages
cc_test(
    name = "can_rx_msgs_unit_test",
    srcs = ["can_rx_msgs_unit_test.cc"],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        # ":can_rx_msgs_fakes",
        # ":can_rx_msgs_source",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/can:can_rx_ut_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":can_tx_msgs_unit_test",
        ":can_rx_msgs_unit_test",
        ":swc_plt_appl_comm_unit_test",
        # Add other unit tests here
    ],
    visibility = ["//visibility:public"],
)
