exports_files([
    "inc/dsp_setup.h",
    "src/dsp_setup.c",
])

cc_library(
    name = "dsp_setup_unit_test_support_lib",
    hdrs = ["src/dsp_setup.c"],
    strip_include_prefix = "src",
    visibility = ["//visibility:public"],
    deps = [
        ":dsp_setup_h",
        "//software/common:UDPLoggingStreamHeaders",
        "//software/common/calibrations/smc:radar_sw_config_h",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
        "//software/common/crc_calc:crc_calc_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync:SWC_PLT_CDD_ECUSync_external_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler:SWC_PLT_Radar_Alignment_Handler_h",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "//software/r52/integration_test:master_it_macros_test_h",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/mmic:mmic_h",
        "//software/r52/program_flow_monitor",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:priv_sfrs",
        "@shbb//module/_api:sh_api_h",
    ],
)

cc_library(
    name = "dsp_setup_h",
    srcs = [],
    hdrs = [
        "inc/dsp_setup.h",
    ],
    defines = [
    ],
    strip_include_prefix = "//software/r52/dsp_setup/inc",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/ipc:ipc_data_h",
    ],
)

cc_library(
    name = "dsp_setup_lib",
    srcs = [
        "src/dsp_setup.c",
    ],
    hdrs = [],
    defines = [],
    strip_include_prefix = "//software/r52/dsp_setup/src",
    visibility = ["//visibility:public"],
    deps = [
        ":dsp_setup_h",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
        "//software/common/crc_calc:crc_calc_h",
        "//software/common/ipc:ipc_data_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync:SWC_PLT_CDD_ECUSync_external_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging/SH:sh_interface_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler:SWC_PLT_Radar_Alignment_Handler_h",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/integration_test:master_it_macros_test_h",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/mmic:mmic_h",
        "//software/r52/program_flow_monitor",
        "@afbb//module/_api:angle_finding_interface_h",
        "@bb_cfg//:afbb_cfg_h",
        "@emb_tracker_wrapper//:emb_tracker_project_parameters_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:priv_sfrs",
        "@reuse",
        "@shbb//module/_api:sh_api_h",
    ],
)

cc_library(
    name = "dsp_setup_ut_lib",
    srcs = [],
    hdrs = [
        "src/dsp_setup.c",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/dsp_setup/src",
    visibility = ["//visibility:public"],
    deps = [
        ":dsp_setup_h",
    ],
)
