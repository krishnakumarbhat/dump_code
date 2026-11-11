load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SWC_PLT_Appl_IoHwAb",
    srcs = [
        "Source/SWC_PLT_Appl_IoHwAb.c",
    ],
    hdrs = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":PLT_iohwab_adc_appl_c",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/config/Appl/Source:BSW_Callout",
        # "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:PLT_iohwab_adc_appl_c",
        "@iND13400_autosar_sip//Components/Can:Can_h",
        "@iND13400_autosar_sip//Components/Eth:Eth_h",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_IoHwAb_Cfg_h",
    srcs = [],
    hdrs = [
        "Include/SWC_PLT_Appl_IoHwAb_Cfg.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/board_revision:board_revision_h",
        "@iND13400_autosar_sip//Components/Adc:Adc_h",
    ],
)

cc_library(
    name = "PLT_Appl_IoHwAb_h",
    srcs = [],
    hdrs = [
        "@SWC_PLT_Appl_IoHwAb//Include:iohwab_adc_appl.h",
        "@SWC_PLT_Appl_IoHwAb//Include:volt_monitor.h",
    ],
    defines = [],
    strip_include_prefix = "/Include",
    visibility = ["//visibility:public"],
    deps = [
        # "//software/m7/autosar/swc/COMMON/Diagnostic_Calibration:Diagnostic_Calib_h",
        # "//software/m7/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        # "//software/m7/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:SWC_PLT_Appl_IoHwAb_Cfg_h",
        "//software/common/calibrations/psc:psc_module",
    ],
)

cc_library(
    name = "PLT_iohwab_adc_appl_c",
    srcs = [
        "@SWC_PLT_Appl_IoHwAb//Source:iohwab_adc_appl.c",
        "@SWC_PLT_Appl_IoHwAb//Source:volt_monitor.c",
    ],
    hdrs = [],
    visibility = ["//visibility:public"],
    deps = [
        ":PLT_Appl_IoHwAb_h",
        "@reuse",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        # "//software/m7/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:PLT_Appl_Voltmonitor",
        # "//software/m7/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:PLT_volt_monitor_h",
        "@Gen8_iND13400//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "@iND13400_autosar_sip//Components/Gpt:gpt",
        # "@SAF85xx_MCAL_Config//:GptCfgH",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_IoHwAb_unit_test_support_lib",
    hdrs = ["Source/SWC_PLT_Appl_IoHwAb.c"],
    defines = ["UNIT_TEST"],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/board_revision:board_revision_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:PLT_Appl_IoHwAb_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:SWC_PLT_Appl_IoHwAb_Cfg_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb/test:SWC_PLT_Appl_IoHwAb_fake_lib",
        "@iND13400_autosar_sip//Components/Can:Can_h",
        "@iND13400_autosar_sip//Components/Eth:Eth_h",
    ],
)

cc_library(
    name = "volt_Monitor_unit_test_support_lib",
    hdrs = [
        "@SWC_PLT_Appl_IoHwAb//Source:volt_monitor.c",
    ],
    defines = [],
    strip_include_prefix = "/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":PLT_Appl_IoHwAb_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@Gen8_iND13400//software/r52/drivers/mcal/gpt:dd_gpt_h",
    ],
)

cc_library(
    name = "iohwab_adc_appl_unit_test_support_lib",
    hdrs = [
        "@SWC_PLT_Appl_IoHwAb//Source:iohwab_adc_appl.c",
    ],
    strip_include_prefix = "/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:PLT_Appl_IoHwAb_h",
        "@Gen8_iND13400//software/r52/drivers/mcal/gpt:dd_gpt_h",
    ],
)
