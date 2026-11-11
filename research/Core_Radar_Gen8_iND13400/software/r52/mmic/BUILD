cc_library(
    name = "mmic_h",
    srcs = [],
    hdrs = glob([
        "*.h",
    ]),
    defines = [
        "CMSIS_ENVIRONMENT",
    ],
    strip_include_prefix = "//software/r52/mmic",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:radar_look_types",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/crc_calc:crc_calc_h",
        "//software/common/mmic:mmic_common_types_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/mmic/drivers/mars_api:mars_api_h",
        "@Calibration_Handler//:calibration_module",
        "@reuse",
    ],
)

cc_library(
    name = "mmic_error_h",
    srcs = [],
    hdrs = [
        "mmic_error.h",
        "mmic_interface.h",
    ],
    strip_include_prefix = "//software/r52/mmic",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:UDPLoggingStreamHeaders",
        "//software/common/crc_calc:crc_calc_h",
        "//software/common/mmic:mmic_common_types_h",
        "@reuse",
    ],
)

cc_library(
    name = "mmic",
    srcs = glob([
        "*.c",
    ]),
    hdrs = [],
    defines = [
        "CMSIS_ENVIRONMENT",
        "EDU_BOARD",
    ],
    strip_include_prefix = "//software/r52/mmic",
    visibility = ["//visibility:public"],
    deps = [
        ":mmic_h",
        "//software/common:UDPLoggingStreamHeaders",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:PLT_Appl_PlatformTime_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/mmic/drivers/mars_api",
        "//software/r52/mmic/drivers/mars_api:mars_api_h",
        "//software/r52/mmic/drivers/mars_api:mars_hw_rev_defines",
        "//software/r52/mmic/drivers/mipi_csi2:dd_mipi",
        "@Gen8_iND13400//software/common/calibrations/smc:radar_sw_config_lib",
        "@iND13400_autosar_sip//Components/Fls",
        "@iND13400_autosar_sip//Components/Uart",
        "@sh_module_cfg//:sh_module_cfg_h",
        "@shbb//module/_api:sh_api_h",
    ],
)

cc_library(
    name = "dd_mmic_unit_test_support_lib",
    hdrs = [
        "dd_mmic.c",
    ],
    strip_include_prefix = "//software/r52/mmic",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb/test:iohwab_adc_fake_lib",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "//software/r52/mmic:mmic_h",
        "//software/r52/mmic/drivers/mars_api/test/mocks:mars_api_fake_lib",
        "//software/r52/mmic/drivers/mipi_csi2:dd_mipi_h",
        "//software/r52/mmic/test/mocks:mmic_error_fake_lib",
        "@Calibration_Handler//:calibration_h",
        "@fff",
        "@iND13400_autosar_sip//Components/Fls:Fls_h",
        "@iND13400_autosar_sip//Components/Uart:Uart_h",
        "@sh_module_cfg//:sh_module_cfg_h",
        "@shbb//module/_api:sh_api_h",
    ],
)

cc_library(
    name = "mmic_error_unit_test_support_lib",
    hdrs = [
        "mmic_error.c",
    ],
    strip_include_prefix = "//software/r52/mmic",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/mmic:mmic_common_types_h",
        "//software/r52/mmic:mmic_error_h",
        "//software/r52/mmic:mmic_h",
    ],
)

cc_library(
    name = "mmic_interface_unit_test_support_lib",
    hdrs = [
        "mmic_interface.c",
    ],
    strip_include_prefix = "//software/r52/mmic",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:UDPLoggingStreamHeaders",
        "//software/common/mmic:mmic_common_types_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:PLT_Appl_PlatformTime_h",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/bb_radar_ctl/bb_radar_ctl_imp/test/mocks:radar_data_fake_lib",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/mmic:mmic_h",
        "//software/r52/mmic/drivers/mipi_csi2:dd_mipi_h",
        "//software/r52/mmic/drivers/mipi_csi2/test/mocks:mipi_csi2_fake_lib",
        "//software/r52/mmic/test/mocks:dd_mmic_fake_lib",
        "//software/r52/mmic/test/mocks:mmic_error_fake_lib",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@fff",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
    ],
)
