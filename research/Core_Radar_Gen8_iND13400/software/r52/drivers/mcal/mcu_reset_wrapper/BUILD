exports_files([
    "mcu_reset_wrapper.c",
    "mcu_reset_wrapper.h",
])

cc_library(
    name = "mcu_reset_wrapper_h",
    srcs = [],
    hdrs = [
        "mcu_reset_wrapper.h",
    ],
    strip_include_prefix = "//software/r52/drivers/mcal/mcu_reset_wrapper",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "mcu_reset_wrapper",
    srcs = [
        "mcu_reset_wrapper.c",
    ],
    hdrs = [],
    visibility = ["//visibility:public"],
    deps = [
        ":mcu_reset_wrapper_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
        "//software/r52/mmic:mmic_h",
        "@Gen8_iND13400//software/r52/drivers/mcal/Mipi_wrapper",
        "@boot//:boot_interface",
        "@iND13400_autosar_sip//Components/Mcu:Mcu_h",
    ],
)

cc_library(
    name = "mcu_reset_wrapper_ut_lib",
    hdrs = [
        "mcu_reset_wrapper.c",
        "mcu_reset_wrapper.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
    ],
)
