exports_files(["power_supply_clock.c"])

cc_library(
    name = "power_supply_clock",
    srcs = [
        "power_supply_clock.c",
    ],
    hdrs = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":Power_Supply_Clock_h",
        "//software/common",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg:dd_pmic_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/Sys",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)

cc_library(
    name = "Power_Supply_Clock_h",
    srcs = [
    ],
    hdrs = [
        "power_supply_clock.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg:dd_pmic_h",
    ],
)

cc_library(
    name = "power_supply_clock_ut_lib",
    hdrs = ["power_supply_clock.c"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [":Power_Supply_Clock_h"],
)
