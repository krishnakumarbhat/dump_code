load("@bazel_platform//toolchains/windriver/v7:cc_binary_windriver.bzl", "cc_binary_windriver")
load("@bazel_platform//platforms:platforms_transition.bzl", "platforms_transition")
load("@bazel_platform//quality/sca/coverity:analysis.bzl", "coverity_analysis")
load("@bazel_platform//quality/sca/coverity:cc_coverity_summary.bzl", "cc_coverity_summary")
load("@bazel_platform//quality/sca/coverity:commit_defects.bzl", "coverity_commit_defects")
load("@build_config//:coverity.bzl", "CODING_STANDARD_CONFIG", "CODING_STANDARD_PARAMS", "COV_ANALYZE_PARAMS", "COV_SKIP_FILES")
load("@bazel_skylib//rules:common_settings.bzl", "string_flag")
load("@bazel_skylib//lib:selects.bzl", "selects")

platforms_transition(
    name = "r52",
    actual_target = ":r52App",
    set_platform = select({
        "@platforms//os:windows": "@bazel_platform//platforms:winarmr52",
        "//conditions:default": "@bazel_platform//platforms:linuxarmr52",
    }),
    visibility = [
        "//:__pkg__",
        "//software:__pkg__",
    ],
)

string_flag(
    name = "boardVersion",
    build_setting_default = "B0",
    values = [
        "EDU",
        "A0",
        "B0",
        "A2P4",
    ],
    visibility = ["//visibility:public"],
)

config_setting(
    name = "edu",
    flag_values = {":boardVersion": "EDU"},
)

config_setting(
    name = "a0",
    flag_values = {":boardVersion": "A0"},
)

config_setting(
    name = "b0",
    flag_values = {":boardVersion": "B0"},
)

selects.config_setting_group(
    name = "edu_board",
    match_any = [
        ":edu",
    ],
)

selects.config_setting_group(
    name = "a0_board",
    match_any = [
        ":a0",
    ],
)

selects.config_setting_group(
    name = "b0_board",
    match_any = [
        ":b0",
    ],
)

config_setting(
    name = "a2p4",
    flag_values = {":boardVersion": "A2P4"},
    visibility = ["//visibility:public"],
)

selects.config_setting_group(
    name = "a2p4_board",
    match_any = [
        ":a2p4",
    ],
    visibility = ["//visibility:public"],
)

cc_binary_windriver(
    name = "r52App",
    srcs = [
        "main.c",
    ],
    copts = [],
    defines = select({
        "//:mcal_test_enable": ["MCAL_TEST_ENABLE"],
        "//conditions:default": [],
    }),
    linkopts = [
        "$(execpath //software/common/linker:r52_ld)",
        "-e EL2_Reset_Handler",
        "-u copyright",
        "-u EL1_IRQ_Handler",
        "-u EL1_FIQ_Handler",
        "-u Os_TrapHandler",
        "-u Os_MemFault",
        "-u Git_Commit_Hash",
        "-u Git_Status",
        "-u Get_Ipc_Shared_Buffer_Base_Address",
    ],
    visibility = ["//visibility:private"],
    deps = [
        "//software/common/calibrations/psc:psc_module",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/crc_calc:crc_calc_c",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/ipc:ipc_mss_lib",
        "//software/common/ipc:ipc_data_lib",
        "//software/common/linker:r52_ld",
        "//software/common/versions",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_asm",
        "//software/r52/autosar/config/Appl/GenData:Csm_Cfg_h",
        "//software/r52/autosar/config/Appl/Source:BSW_Callout",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb:SWC_PLT_Appl_XCP",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb:SWC_PLT_CDD_MCU_Safety",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:PLT_iohwab_adc_appl_c",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager:PLT_Appl_ModeManager",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_RTM",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC:SWC_CDD_IPC",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Radar_Control",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_Appl_Project",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IntWDG",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FCRU",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_FaultMgr",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync",
        "//software/r52/bb_radar_ctl:radar_ctl_module",
        "//software/r52/drivers/mcal:McalInit",
        "//software/r52/dsp_setup:dsp_setup_lib",
        "//software/r52/mmic",
        "//software/r52/r52_stack:Stack_Monitor_R52_external_module",
        "//software/r52/startup",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg",
        "@Calibration_Handler//:calibration_module",
        "@Gen8_iND13400//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "@Sensor_Position//:sensor_position",
        "@iND13400_autosar_sip//Components/Can:Can_h",
        "@iND13400_autosar_sip//Components/CanIf",
        "@iND13400_autosar_sip//Components/CanTSyn",
        "@iND13400_autosar_sip//Components/CanTp",
        "@iND13400_autosar_sip//Components/Fee_30_FlexNor:Fee_30_FlexNor_h",
        "@iND13400_autosar_sip//Components/J1939Dcm",
        "@iND13400_autosar_sip//Components/J1939Tp",
        "@iND13400_autosar_sip//Components/I2c",
        "@iND13400_autosar_sip//Components/Mcu:Mcu_h",
        "@iND13400_autosar_sip//Components/NvM:NvM_h",
        "@iND13400_autosar_sip//Components/Dcm",
        "@iND13400_autosar_sip//Components/Dem",
        "@iND13400_autosar_sip//Components/WdgM",
        "@iND13400_autosar_sip//Components/WdgIf",
        "@iND13400_autosar_sip//Components/Os",
        "@iND13400_autosar_sip//Components/Os:Os_asm",
        "@iND13400_autosar_sip//Components/CanXcp:CanXcp_h",
        "@iND13400_autosar_sip//Components/Crypto",
        "@iND13400_autosar_sip//Components/Crypto:Crypto_h",
        "@iND13400_autosar_sip//Components/Csm",
        "@iND13400_autosar_sip//Components/Csm:Csm_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/common/TCM_LIB",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/Port:Driver_Port",
        "@reuse",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag:PLT_Appl_Diag",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr:PLT_Appl_FaultMgr",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler:PLT_CDD_WdgHandler",
        # common files
        "//software/r52/autosar/swc/COMMON/Diagnostic_Calibration:Diagnostic_Calib",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/integration_test:master_it_macros_test_h",
        "//software/r52/startup:mpu_r52_h",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_Power_Manager:SWC_PRJ_Appl_Power_Manager",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_CMP_PRJ_UDSHandler:SWC_CMP_PRJ_UDSHandler",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_SensorPosition:SWC_PRJ_Appl_SensorPosition",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_Security_Manager:SWC_PRJ_Appl_Security_Manager",
    ] + select({
        "//:mcal_test_enable": [
            "//software/r52/drivers/mcal/src/test:McalTest",
        ],
        "//conditions:default": [],
    }) + select({
        "//:Integration_Testing_enabled": [
            "//software/r52/integration_test:master_integration_test",
        ],
        "//conditions:default": [],
    }),
)

# -----------------------------------
# Coverity Settings
# -----------------------------------

coverity_analysis(
    name = "windriver_r52_cov",
    coding_standards_cfg = CODING_STANDARD_CONFIG,
    coding_standards_params = CODING_STANDARD_PARAMS,
    compiler_type = "windriver_v7",
    cov_analyze_params = COV_ANALYZE_PARAMS,
    skip_file_args = COV_SKIP_FILES,
    tags = ["manual"],
    deps = [
        ":r52",
    ],
)

coverity_commit_defects(
    name = "commit_defects",
    analysis = ":windriver_r52_cov",
    args = [
        "--host=https://coverity.asux.aptiv.com:443",
        "--output-tag=_combined",
        "--retry-attempts=1",
        # "--verbose=1",  # Use this for debugging, levels 1-4
    ] + select({
        "//tools/coverity:coverityNightly": ["--commit"],  # only commit on nightly builds
        "//conditions:default": [
            "--failure-strategy=fail-on-new-medium-high",  # Fail on new 'High' or 'Medium' impact defects
            "--failure-strategy-misra=fail-on-new-mandatory",  # Fail on new MISRA 'Mandatory' defects too
        ],
    }) + select({
        "@build_config//:flr8": ["--stream=10034606_Core_Radar_Gen8_IND13400_FLR8_R52"],
        "@build_config//:srr8p": ["--stream=10034606_Core_Radar_Gen8_IND13400_SRR8p_R52"],
    }),
)

cc_coverity_summary(
    name = "coverity_summary",
    output_tag = "_combined",
    test = ":windriver_r52_cov",
    text_summary = "r52_coverity_summary.txt",
)
