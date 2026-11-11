cc_library(
    name = "SWC_PLT_Service_IoHwAb",
    srcs = [
        "Source/iohwab_adc.c",
        "Source/thermal_monitor.c",
    ] + select({
        "//:Build_SQT_Test_Cases": ["Source/thermal_monitor_test.c"],
        "//conditions:default": [],
    }),
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Service_IoHwAb_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:SWC_PLT_Appl_IoHwAb_Cfg_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_h",
        "@Gen8_iND13400//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "@iND13400_autosar_sip//Components/Gpt:gpt",
    ],
)

cc_library(
    name = "SWC_PLT_Service_IoHwAb_h",
    srcs = [],
    hdrs = [
        "Include/SWC_PLT_Service_IoHwAb.h",
        "Include/thermal_monitor.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:adc_cfg_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "@iND13400_autosar_sip//Components/Adc:Adc_h",
        "@reuse",
    ],
)

cc_library(
    name = "iohwab_adc_unit_test_support_lib",
    hdrs = [
        "Source/iohwab_adc.c",
        "Source/thermal_monitor.c",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Service_IoHwAb",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:SWC_PLT_Appl_IoHwAb_Cfg_h",
    ],
)
