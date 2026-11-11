load("//tools/python/memoryStats:memory_stats_wrapper.bzl", "generate_memory_stats")
load("//tools/python/stackAnalysis:stack_analysis_wrapper.bzl", "stack_analysis")
load("//tools/python/flash_memory_stats:flash_memory_stats.bzl", "flash_memory_stats")
load("//tools/bazel/scripts:copy_to_dir.bzl", "copy_to_dir")
load("@bazel_skylib//rules:common_settings.bzl", "bool_flag", "string_flag")
load("@bazel_platform//utils/compilation_database:refresh_compile_commands.bzl", "refresh_compile_commands")
load("@bazel_platform//quality/compiler_warnings:compiler_warnings_report.bzl", "compiler_warnings_report")
load("//tools/python/streamGenerator:stream_generator.bzl", "generate_stream_files")
load("//tools/python/streamBandwidth:stream_bandwidth_rule.bzl", "Stream_Bandwidth_Info")
load("@Gen8_iND13400//tools/bazel/scripts:save_build_config.bzl", "save_build_config")
load("//tools/bazel/scripts:unsupported_combo_guard.bzl", "unsupported_combo_guard")
load("@bazel_skylib//lib:selects.bzl", "selects")

# Prefixes every variant output folder with "1GB/" (default) or "100Mb/" (--enable_phy_100Mb),
# so binaries from both PHY speed builds can coexist under outputs/ without overwriting each other.
PHY_OUTPUT_PREFIX = select({
    ":Build_enable_phy_100Mb": "outputs/PHY_100Mb/",
    "//conditions:default": "outputs/PHY_1Gb/",
})

VARIANT_OUTPUT_DIR = PHY_OUTPUT_PREFIX + select({
    "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": "flr8_satellite_can",
    "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": "flr8_satellite_eth_high_det",
    "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": "flr8_standalone",
    "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": "srr8p_satellite_can",
    "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": "srr8p_satellite_eth_high_det",
    "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": "srr8p_standalone",
    "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": "srr8p_al_can_standalone",
})

filegroup(
    name = "gen8",
    srcs = [
        ":aptivAppOutputs",
        ":boot",
        ":generate_lua_script",
        ":generate_stream_defs",
        ":phy_100mb_compat_guard",
        ":quickflash",
        ":quickflashConfig",
        ":spc",
        ":streamGeneratorTool",
        ":stream_bandwidth_report",
        "//software:flash_image_overlap_checks",
        ":warnings_report",
    ] + select({
        "enable_stream_generation": [":generate_stream_files"],
        "//conditions:default": [],
    }),
    visibility = [
        "//coverage:__pkg__",
    ],
)

save_build_config(
    name = "save_build_config",
    config_flags = [
        "@build_config//:variant",
        "@appl_inclusion_dep//:enable_bench_testing",
        "@emb_tracker_wrapper//:tracker_variant",
        "@emb_tracker_wrapper//:stub_tracker",
        "@Gen8_iND13400//software/r52:boardVersion",
        "@Gen8_iND13400//software/bbe32/src:enable_chirp_timing",
        "@Gen8_iND13400//software/bbe32/src:enable_cdc",
        "@Gen8_iND13400//software/r52/r52_stack:disable_stack_monitor_r52",
        # "@spbb//modules/range_process:enable_adc_logging",
        "@Gen8_iND13400//:SQT_Test_Cases",
        "@Gen8_iND13400//:SIT_Test_Cases",
        "@Gen8_iND13400//:SQT_ARTIEMEM_FAULT",
        "@Gen8_iND13400//:XCP_FAULT_INJECTION_Test_Cases",
        "@Gen8_iND13400//:Disable_int_Wdg",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:veh_com",
        "@Gen8_iND13400//:stream_generation_enabled",
        "@Gen8_iND13400//:enable_uart",
        "@Gen8_iND13400//:enable_mcal_test",
        "@calib_cfg//:calibration_default_init_values",
    ],
    visibility = ["@Gen8_iND13400//:__pkg__"],
)

# --enable_phy_100Mb is not supported together with --veh_com=someip or
# --veh_com=al_can_standalone (e.g. --tracker_variant=AL). Fail fast during analysis
# so the SW compile never starts for these combinations.
selects.config_setting_group(
    name = "phy_100mb_someip",
    match_all = [
        ":Build_enable_phy_100Mb",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:VEH_SOMEIP",
    ],
)

selects.config_setting_group(
    name = "phy_100mb_al_can_standalone",
    match_all = [
        ":Build_enable_phy_100Mb",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:VEH_AL_CAN_STANDALONE",
    ],
)

selects.config_setting_group(
    name = "phy_100mb_can_standalone",
    match_all = [
        ":Build_enable_phy_100Mb",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:VEH_TRACKER",
    ],
)

unsupported_combo_guard(
    name = "phy_100mb_compat_guard",
    unsupported = select({
        ":phy_100mb_someip": True,
        ":phy_100mb_al_can_standalone": True,
        ":phy_100mb_can_standalone": True,
        "//conditions:default": False,
    }),
)

copy_to_dir(
    name = "aptivAppOutputs",
    srcs = [
        "flash_memory_stats.txt",
        ":generate_dependency_inventory",
        ":generate_memory_stats",
        ":save_build_config",
        ":stack_analysis_bbe32",
        "//software:app.s19",
        "//software:nvm_erase.s19",
        "//software:smc_cal_ptp",
        "//software:usc_cal_ptp",
        "//software/bbe32",
        "//software/common/versions/linkstamp:copy_stamp_files",
        "//software/r52",
        "//tools/lauterbach:flash_session_with_platform_AL_CAN_Bootloader.ini",
    ] + select({
        ":Build_enable_phy_100Mb": ["//tools/lauterbach:flash_session_PHY_100Mb.ini"],
        "//conditions:default": ["//tools/lauterbach:flash_session_PHY_1Gb.ini"],
    }),
    outputDir = VARIANT_OUTPUT_DIR,
)

genrule(
    name = "generate_dependency_inventory",
    srcs = [
        "MODULE.bazel",
        "bb.MODULE.bazel",
    ],
    outs = ["dependency_inventory.csv"],
    cmd = "$(location //tools/python/dependency_inventory:generate_dependency_inventory) --input $(location MODULE.bazel) --input $(location bb.MODULE.bazel) --out $@",
    cmd_bat = "$(location //tools/python/dependency_inventory:generate_dependency_inventory) --input $(location MODULE.bazel) --input $(location bb.MODULE.bazel) --out $@",
    tools = ["//tools/python/dependency_inventory:generate_dependency_inventory"],
)

compiler_warnings_report(
    name = "warnings",
    allowlist = "@build_config//:compiler_warnings_allowlist.yml",
    deps = [
        ":aptivAppOutputs",
        ":boot",
    ],
)

copy_to_dir(
    name = "warnings_report",
    srcs = [":warnings"],
    outputDir = VARIANT_OUTPUT_DIR,
)

generate_memory_stats(
    name = "generate_memory_stats",
    cc_windriver_binaries = [
        "//software/r52",
        "//software/bbe32",
    ],
    module_map = "//software:module_filename_map.json",
    verbosePython = False,
)

stack_analysis(
    name = "stack_analysis_bbe32",
    stack_analysis_target = "//software/bbe32:bbe32",
    system_path = select({
        "@platforms//os:windows": "@bbe_windows_luna//:config",
        "//conditions:default": "@bbe_linux_luna//:config",
    }),
    tool_path = select({
        "@platforms//os:windows": "@bbe_windows//:tools/RJ-2025.5-win32/XtensaTools/bin/xt-stack-usage.exe",
        "//conditions:default": "@bbe_linux//:tools/RJ-2025.5-linux/XtensaTools/bin/xt-stack-usage",
    }),
    verbosePython = False,
)

filegroup(
    name = "_pbl_eth_pbl_files",
    srcs = ["@boot//:pbl_eth_1Gbps"],
)

filegroup(
    name = "_pbl_eth_hsm_files",
    srcs = ["@boot//:pbl_eth_1Gbps"],
)

flash_memory_stats(
    name = "flash_memory_stats.txt",
    srcs = {
        "//software:flash_image_table.s19": "flash_image_table.s19",
        "//software:mars_fw.s19": "mars_fw.s19",
        "//software:dyn_app.s19": "dyn_app.s19",
        "//software:usc_cal_ptp": "usc_cal.ptp",
        "//software:smc_cal_ptp": "smc_cal.ptp",
    } | select({
        "//software/r52:b0_board": {
            "//:_pbl_eth_pbl_files": "pbl_b0_eth_signed.s19",
            "//:_pbl_eth_hsm_files": "hsm_container_b0_v50a_225.s19",
        },
        "//software/r52:a0_board": {
            "//:_pbl_eth_pbl_files": "pbl_a0_eth_signed.s19",
            "//:_pbl_eth_hsm_files": "hsm_container_a0_v35e.s19",
        },
        "//software/r52:edu_board": {
            "//:_pbl_eth_pbl_files": "pbl_edu_eth_signed.s19",
            "//:_pbl_eth_hsm_files": "hsm_container_edu_v33a.s19",
        },
    }),
    flash_size = 4,
)

filegroup(
    name = "boot",
    srcs = [
        ":pbl",
    ],
)

copy_to_dir(
    name = "spc",
    srcs = [
        "//software:spc_1.s19",
        "//software:spc_2.s19",
        "//software:spc_3.s19",
        "//software:spc_4.s19",
        "//software:spc_5.s19",
        "//software:spc_6.s19",
        "//software:spc_7.s19",
        "//software:spc_8.s19",
        "//software:spc_erased.s19",
    ],
    outputDir = "outputs/spc",
)

copy_to_dir(
    name = "pbl",
    srcs = [
        "@boot//:pbl_b0_can_al",
        "@boot//:pbl_can",
        "@boot//:pbl_eth_100Mbps",
        "@boot//:pbl_eth_1Gbps",
    ],
    outputDir = "outputs/pbl",
    preserve_directories = True,
    strip_prefix = "external/_main~_repo_rules~boot/pbl",
)

copy_to_dir(
    name = "generate_stream_defs",
    srcs = ["//software/common:stream_defs"],
    outputDir = VARIANT_OUTPUT_DIR + "/streamdefs",
)

copy_to_dir(
    name = "generate_lua_script",
    srcs = ["lua_script_creator"],
    outputDir = VARIANT_OUTPUT_DIR + "/streamdefs",
)

genrule(
    name = "lua_script_creator",
    srcs = [
        ":generate_stream_defs",
        "//software/common/versions:versions_c",
    ],
    outs = ["temp/wiresharkDissector.lua"],
    cmd = "$(location @StreamHeader_Gen//luaScriptCreator) --streamDefs $(locations //:generate_stream_defs) --versionFile $(location //software/common/versions:versions_c) --outLuaScript $@",
    cmd_bat = "$(location @StreamHeader_Gen//luaScriptCreator) --streamDefs $(locations //:generate_stream_defs) --versionFile $(location //software/common/versions:versions_c) --outLuaScript $@",
    tools = ["@StreamHeader_Gen//luaScriptCreator"],
)

copy_to_dir(
    name = "streamGeneratorTool",
    srcs = select({
        "@bazel_tools//src/conditions:host_windows": ["@StreamHeader_Gen//:LE_Defined_StreamGeneratorWindows"],
        "//conditions:default": ["@StreamHeader_Gen//:StreamGeneratorLinux"],
    }),
    outputDir = "outputs/tools/streamGeneratorTool",
)

bool_flag(
    name = "stream_generation_enabled",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "enable_stream_generation",
    flag_values = {":stream_generation_enabled": "True"},
    visibility = ["//visibility:public"],
)

generate_stream_files(
    name = "generate_stream_files",
    exclude_files = [
        "calib_stream.h",
        "Dynamic_alignment_stream.h",
        "static_alignment_stream.h",
    ],
    logging_files = ["//software/common:copyStreamFilesToTemp"],
    variant_name = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": "flr8_satellite_can",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": "flr8_satellite_eth_high_det",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": "flr8_standalone",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": "srr8p_satellite_can",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": "srr8p_satellite_eth_high_det",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": "srr8p_standalone",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": "srr8p_al_can_standalone",
    }),
    visibility = ["//visibility:public"],
)

copy_to_dir(
    name = "stream_bandwidth_report",
    srcs = ["Stream_Bandwidth_Info"],
    outputDir = VARIANT_OUTPUT_DIR + "/streamdefs",
)

Stream_Bandwidth_Info(
    name = "Stream_Bandwidth_Info",
    input_files = [":generate_stream_defs"],
    variant_id = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": "082",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": "082",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": "082",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": "083",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": "083",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": "083",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": "083",
    }),
    variant_name = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": "flr8_satellite_can",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": "flr8_satellite_eth_high_det",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": "flr8_standalone",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": "srr8p_satellite_can",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": "srr8p_satellite_eth_high_det",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": "srr8p_standalone",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": "srr8p_al_can_standalone",
    }),
    visibility = ["//visibility:public"],
)

copy_to_dir(
    name = "quickflashConfig",
    srcs = ["//tools/quickflash:quickflash_configs"],
    outputDir = "outputs/quickflash",
)

copy_to_dir(
    name = "quickflash",
    srcs = [
        "@quickflash//:quickflash_files",
    ],
    outputDir = "outputs/quickflash",
    preserve_directories = True,
    strip_prefix = "external/_main~_repo_rules~quickflash",
)
# -----------------------------------
# to enable sqt and sit test cases
# -----------------------------------

bool_flag(
    name = "Feature_functions",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "Run_Feature_functions",
    flag_values = {":Feature_functions": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "SQT_Test_Cases",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "Build_SQT_Test_Cases",
    flag_values = {":SQT_Test_Cases": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "SIT_Test_Cases",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "Build_SIT_Test_Cases",
    flag_values = {":SIT_Test_Cases": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "DEBUG_Enable",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "Build_DEBUG_Enable",
    flag_values = {":DEBUG_Enable": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "XCP_FAULT_INJECTION_Test_Cases",
    build_setting_default = True,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "Build_XCP_FAULT_INJECTION_Test_Cases",
    flag_values = {":XCP_FAULT_INJECTION_Test_Cases": "true"},
    visibility = ["//visibility:public"],
)

# -----------------------------------
# SQT ARTIEMEM fault injection flags
# -----------------------------------

bool_flag(
    name = "SQT_ARTIEMEM_FAULT",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "Build_SQT_ARTIEMEM_FAULT",
    flag_values = {":SQT_ARTIEMEM_FAULT": "true"},
    visibility = ["//visibility:public"],
)

# -----------------------------------
# Integration Testing (SWE5) Flags
# -----------------------------------

bool_flag(
    name = "Integration_Testing",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "Integration_Testing_enabled",
    flag_values = {":Integration_Testing": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "Anglefinding_IT",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "ANGLEFINDING_enabled",
    flag_values = {":Anglefinding_IT": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "Radar_capability_IT",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "RADAR_CAPABILITY_enabled",
    flag_values = {":Radar_capability_IT": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "FirstPass_IT",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "FIRSTPASS_enabled",
    flag_values = {":FirstPass_IT": "true"},
    visibility = ["//visibility:public"],
)

# -----------------------------------

bool_flag(
    name = "Disable_int_Wdg",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "Build_Disable_int_Wdg",
    flag_values = {":Disable_int_Wdg": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "enable_uart",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "uart_enable",
    flag_values = {":enable_uart": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "enable_phy_100Mb",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "Build_enable_phy_100Mb",
    flag_values = {":enable_phy_100Mb": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "static_register_safety_enabled",
    build_setting_default = True,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "enable_static_register_safety",
    flag_values = {":static_register_safety_enabled": "true"},
    visibility = ["//visibility:public"],
)

config_setting(
    name = "board",
    flag_values = {":boardVersion": "EDU"},
    visibility = ["//visibility:public"],
)

# MARS Hardware Revision Setting
string_flag(
    name = "mars_hw_revision",
    build_setting_default = "B0",
    values = [
        "A0",
        "B0",
    ],
    visibility = ["//visibility:public"],
)

config_setting(
    name = "mars_hw_rev_a0",
    flag_values = {":mars_hw_revision": "A0"},
    visibility = ["//visibility:public"],
)

config_setting(
    name = "mars_hw_rev_b0",
    flag_values = {":mars_hw_revision": "B0"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "enable_mcal_test",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "mcal_test_enable",
    flag_values = {":enable_mcal_test": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "Aptiv_Official_Release",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "Build_Aptiv_Official_Release",
    flag_values = {":Aptiv_Official_Release": "true"},
    visibility = ["//visibility:public"],
)

# -----------------------------------
# Unit Tests
# -----------------------------------
test_suite(
    name = "all_unit_tests",
    tests = [
        ":tests_bbe",
        "//software/common/board_revision/test:unit_tests",
        "//software/common/crc32/test:unit_tests",
        "//software/common/crc_calc/test:unit_tests",
        "//software/common/ipc/test:unit_tests",
        "//software/common/versions/test:unit_tests",
        "//software/r52/autosar/config/Appl/Source/test:unit_tests",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag/test:plt_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr/test:plt_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IntWDG/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb/test:plt_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager/test:plt_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_NvMHandler/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_RTM/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FCRU/test:FCRU_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL/hil/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL/test:HIL_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging/SH/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/test:Exception_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/test:static_register_safety_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Radar_Control/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler/test:plt_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/test:core_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/test:unit_tests",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_Appl_Project/test:unit_tests",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_CMP_PRJ_UDSHandler/test:UDSHandler_unit_tests",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_FaultMgr/test:SWC_PRJ_Appl_FaultMgr_unit_test",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_Power_Manager/test:Appl_Power_Manager_unit_tests",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_SensorPosition/test:Appl_SensorPosition_unit_tests",
        "//software/r52/bb_radar_ctl/bb_radar_ctl_imp/test:unit_tests",
        "//software/r52/drivers/mcal/Mipi_wrapper/test:unit_tests",
        "//software/r52/drivers/mcal/gpt/test:unit_tests",
        "//software/r52/drivers/mcal/mcu_reset_wrapper/test:unit_tests",
        "//software/r52/drivers/mcal/power_supply_clock/test:unit_tests",
        "//software/r52/dsp_setup/test:unit_tests",
        "//software/r52/mmic/drivers/mipi_csi2/test:unit_tests",
        "//software/r52/mmic/test:unit_tests",
        "//software/r52/program_flow_monitor/test:unit_tests",
        "//software/r52/r52_stack/test:unit_tests",
        "@Calibration_Handler//calib_handler/test:unit_tests",
        "@Sensor_Position//:unit_tests",
    ],
    visibility = [
        "//coverage:__pkg__",
    ],
)

test_suite(
    name = "tests_bbe",
    tests = [
        # TODO spbbtag update to enable
        "//software/bbe32/emb_tracker/test:unit_tests",
        "//software/bbe32/test:all_tests",
        "//software/bbe32/rdd_proc/test:all_tests",
        "//software/bbe32/bbe_self_test/test:unit_tests",
        "//software/bbe32/dss_ecc_parity/test:unit_tests",
        "//software/bbe32/mpu/test:unit_tests",
        "//software/bbe32/src/test:unit_tests",
        "//software/bbe32/test:range_doppler_tests",
        "//software/bbe32/bbe32_static_register_validation/test:unit_tests",
        "@spbb//:spbb_tests",
        "@Dyn_alignment_module_interface//test:unit_tests",
        "@Static_alignment_module_interface//test:unit_tests",
        "//software/bbe32/interference_detection/test:unit_tests",
        "@dabb//module/test:unit_tests_lib",
        "@idbb//module/test:unit_tests_lib",
        "@radar_capability_module_interface//test:unit_tests",
        "@rcbb//:RC_unit_tests",
        "@sabb//module/test:unit_tests",
        # "@TOI_Char_Quality_Determination//TOI_char_quality_determination/test:radar_data_quality_unit_tests",
        "@afbb//:all_unit_tests",
        "@rm//:unit_tests",
    ],
    visibility = ["//visibility:public"],
)

# -----------------------------------
# Generate a compile_commands.json used by TICS
# -----------------------------------
refresh_compile_commands(
    name = "compiledb",  # target name
    exclude_headers = "all",
    targets = {
        # which target to analyze: required config flags (--config=variantName)
        "//:gen8": "--notool_deps",
    },
)
