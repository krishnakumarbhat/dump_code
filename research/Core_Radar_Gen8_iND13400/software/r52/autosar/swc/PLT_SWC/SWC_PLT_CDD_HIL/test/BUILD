cc_library(
    name = "SWC_PLT_CDD_HIL_fake_lib",
    srcs = [
        "SWC_PLT_CDD_HIL_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_CDD_HIL_fake.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:UDPLoggingStreamHeaders",
        "//software/common/ipc:ipc_data_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "@Sensor_Position//:sensor_position_h",
        "@fff",
    ],
)

cc_test(
    name = "SWC_PLT_CDD_HIL_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_CDD_HIL_unit_test.cc",
    ],
    defines = [],
    linkopts = [],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_HIL_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/test:swc_platformtime_fakes",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL:SWC_PLT_CDD_HIL_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL:SWC_PLT_CDD_HIL_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL/hil:hil_project_interface_h",
        "//software/r52/dsp_setup:dsp_setup_h",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging:SWC_PLT_CDD_LOGGING_h",
        "@Sensor_Position//:sensor_position_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@hilbb//module/_api:hil_communication_handler_h",
        "@hilbb//module/_api:hil_types_h",
        "@hilbb//module/_test/mocks:hil_communication_handler_fake_lib",
    ],
)

test_suite(
    name = "HIL_unit_tests",
    tests = [
        ":SWC_PLT_CDD_HIL_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
