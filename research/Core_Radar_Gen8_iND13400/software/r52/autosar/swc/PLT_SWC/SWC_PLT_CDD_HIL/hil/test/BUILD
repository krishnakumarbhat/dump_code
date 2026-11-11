cc_test(
    name = "hil_project_interface_test",
    size = "small",
    timeout = "short",
    srcs = [
        "hil_interface_unit_test.cc",
    ],
    defines = [],
    linkopts = [],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/ipc:ipc_data_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/test:swc_platformtime_fakes",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL/hil:hil_interface_ut_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL/hil/test/mocks:hil_if_mock_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging:SWC_PLT_CDD_LOGGING_h",
        "//software/r52/dsp_setup:dsp_setup_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@hilbb//module/_api:hil_communication_handler_h",
        "@hilbb//module/_test/mocks:hil_communication_handler_fake_h",
        "@hilbb//module/_test/mocks:hil_communication_handler_fake_lib",
        "@iND13400_autosar_sip//Components/SoAd",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":hil_project_interface_test",
        "@hilbb//module:hil_communication_handler_unit_test",
    ],
    visibility = ["//visibility:public"],
)
