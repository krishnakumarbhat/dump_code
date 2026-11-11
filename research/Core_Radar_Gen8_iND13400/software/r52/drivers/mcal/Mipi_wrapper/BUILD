exports_files(["Mipi_wrapper.c"])

cc_library(
    name = "Mipi_wrapper_h",
    srcs = [],
    hdrs = [
        "mipi_wrapper.h",
    ],
    implementation_deps = [
    ],
    strip_include_prefix = "//software/r52/drivers/mcal/Mipi_wrapper",
    visibility = ["//visibility:public"],
    deps = [
        "@iND13400_autosar_sip//Components/I2c:I2c_h",
        "@reuse",
    ],
)

cc_library(
    name = "Mipi_wrapper",
    srcs = [
        "mipi_wrapper.c",
    ],
    hdrs = [
    ],
    implementation_deps = [
    ],
    strip_include_prefix = "//software/r52/drivers/mcal/Mipi_wrapper",
    visibility = ["//visibility:public"],
    deps = [
        ":Mipi_wrapper_h",
        "//software/common/board_revision:board_revision_module",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:SWC_PLT_PlatformTime_cfg_h",
        "//software/r52/drivers/mcal:McalInit_H",
        "@iND13400_autosar_sip//Components/Port",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/Port:Driver_Port_h",
    ],
)

cc_library(
    name = "Mipi_wrapper_unit_test_support_lib",
    srcs = [
    ],
    hdrs = [
        "mipi_wrapper.c",
    ],
    implementation_deps = [
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":Mipi_wrapper_h",
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
    ],
)
