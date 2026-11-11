cc_library(
    name = "SWC_PLT_Radar_Alignment_Handler_fake_lib",
    srcs = [
        "SWC_PLT_Radar_Alignment_Handler_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_Radar_Alignment_Handler_fake.h",
        "ipc_mss.h",
    ],
    deps = [
        "//software/common/ipc:ipc_data_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

cc_test(
    name = "Radar_Alignment_Handler_unit_test",
    srcs = [
        "SWC_PLT_Radar_Alignment_Handler_unit_test.cc",
    ],
    copts = [
        "-Isoftware/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler/test",
    ],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Radar_Alignment_Handler_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler:Radar_Alignment_Handler_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":Radar_Alignment_Handler_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//visibility:public",
    ],
)
