cc_library(
    name = "McalTest_H",
    srcs = [],
    hdrs = [
        "mcal_test.h",
    ],
    implementation_deps = [
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@reuse",
    ],
)

cc_library(
    name = "McalTest",
    srcs = [
        "mcal_test.c",
    ],
    hdrs = [
    ],
    implementation_deps = [
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":McalTest_H",
        "//software/r52/drivers/mcal:McalInit_H",
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "@Gen8_iND13400//software/r52/drivers/mcal/Mipi_wrapper",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg:dd_pmic",
        "@Gen8_iND13400//software/r52/drivers/mcal/power_supply_clock",
        "@iND13400_autosar_sip//Components/Adc:AdcMcalModule",
        # "@iND13400_autosar_sip//Components/Can:CanModule",
        "@iND13400_autosar_sip//Components/Can:Can_h",
        "@iND13400_autosar_sip//Components/Dio",
        "@iND13400_autosar_sip//Components/Dma",
        "@iND13400_autosar_sip//Components/Eth",
        "@iND13400_autosar_sip//Components/Fls",
        "@iND13400_autosar_sip//Components/I2c",
        "@iND13400_autosar_sip//Components/Port",
        "@iND13400_autosar_sip//Components/Spi",
        "@iND13400_autosar_sip//Components/Uart",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr",
        "//software/r52/drivers/mcal/dio_wrapper:dio_wrapper_h",
        "//software/r52/drivers/mcal/dio_wrapper",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:SWC_PLT_PlatformTime_cfg_h",
    ],
)
