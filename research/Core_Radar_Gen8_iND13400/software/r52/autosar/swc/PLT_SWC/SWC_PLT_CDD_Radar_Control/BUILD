load("@rules_cc//cc:defs.bzl", "cc_library")

# Export source files for testing
exports_files([
    "Source/SWC_PLT_CDD_Radar_Control.c",
])

cc_library(
    name = "SWC_PLT_CDD_Radar_Control",
    srcs = [
        "Source/SWC_PLT_CDD_Radar_Control.c",
        "Source/SWC_PLT_CDD_Radar_Control_test.c",
    ],
    hdrs = [],
    defines = [],
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/ipc:ipc_data_lib",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/drivers/mcal:McalInit",
        "//software/r52/dsp_setup:dsp_setup_h",
        "//software/r52/mmic",
        "//software/r52/mmic:mmic_error_h",
        "@Gen8_iND13400//software/r52/drivers/mcal/Mipi_wrapper",
        "@Gen8_iND13400//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "@iND13400_autosar_sip//Components/Os:Os_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:priv_sfrs",
        # "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/Adc:Driver_Adc_h",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_Radar_Control_source_support_lib",
    srcs = [],
    hdrs = [
        "Source/SWC_PLT_CDD_Radar_Control.c",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
)
