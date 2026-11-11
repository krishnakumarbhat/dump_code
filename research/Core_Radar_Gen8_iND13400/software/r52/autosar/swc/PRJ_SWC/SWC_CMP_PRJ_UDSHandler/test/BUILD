cc_library(
    name = "SWC_CMP_PRJ_UDSHandler_fake_lib",
    testonly = True,
    srcs = [
        "SWC_CMP_PRJ_UDSHandler_fake.cc",
    ],
    hdrs = [
        "SWC_CMP_PRJ_UDSHandler_fake.h",
    ],
    deps = [
        "//software/common/calibrations/usc:usc_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/drivers/mcal/mcu_reset_wrapper:mcu_reset_wrapper_h",
        "@fff",
    ],
)

cc_test(
    name = "SWC_CMP_PRJ_UDSHandler_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_CMP_PRJ_UDSHandler_unit_test.cc",
    ],
    defines = [],
    linkopts = [],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_CMP_PRJ_UDSHandler_fake_lib",
        "//software/common/calibrations/usc:usc_h",
        "//software/common/calibrations/usc:usc_module",
        "//software/common/crc32:crc32_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj_h",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_CMP_PRJ_UDSHandler:SWC_CMP_PRJ_UDSHandler_unit_test_support_lib",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_CMP_PRJ_UDSHandler:SWC_Project_Radar_Alignment_Handler_unit_test_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "UDSHandler_unit_tests",
    tests = [
        ":SWC_CMP_PRJ_UDSHandler_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
