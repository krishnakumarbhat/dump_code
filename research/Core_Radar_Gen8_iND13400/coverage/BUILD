load("@bazel_platform//quality/ut:coverage_report.bzl", "coverage_report")

COMPILE_UT_EXCLUDES = [
    # External dependencies - we want to focus coverage on our own code, not 3rd party libraries
    "external/.*com_google_googletest~?.*/.*",  # GoogleTest framework
    "external/.*mingw64_10_0_0_rev0~?.*/.*",  # Windows MinGW Compiler
    "external/.*gcc-glibc~?.*/.*",  # Linux GCC compiler
    "external/.*bbe_(linux|windows).*/.*",
]

# Add path which need to be Exclude
UT_EXCLUDES = [
    "external/.*iND13400_autosar_sip/.*",
    "external/.*iND13400_sdk/.*",
    ".*/test/.*",
    ".*/_test/.*",
    ".*/mocks/.*",
    "external/.*rotbb/.*",
    "external/.*afbb/module/_common/radar_math/_src/rm_bv_comp_copy_sres_2tx_bat.c",
    "external/.*afbb/module/_common/radar_math/_src/rm_bv_comp_pad_2tx_bat.c",
    "external/.*afbb/module/_common/radar_math/_src/rm_bv_cp4q_float_reorder_2tx_bat.c",
    "external/.*angle_finding_module_cfg/angle_finding_project_interface.h",
    "external/.*appl_inclusion_dep/afbb_include.h",
    "external/.*calib_cfg/calibration_sect_cfg.h",
    "external/.*angle_finding_module_cfg/angle_finding_module_cfg.h",
    "external/.*spbb/modules/sweep_bw/imp/inc/.*",
    "external/.*spbb/modules/sweep_bw/api/inc/.*",
    "external/.*spbb/modules/second_pass/imp/inc/.*",
    "external/.*spbb/modules/second_pass/api/.*",
    "external/.*spbb/modules/range_process/imp/inc",
    "external/.*spbb/modules/range_process/api/.*",
    "external/.*spbb/modules/helpers/imp/src/perfmon/.*",
    "external/.*spbb/common/cstub_helpers/.*",
    # These helper implementation files are pulled transitively by many targets,
    # but they are validated via dedicated SPBB helper coverage/tests and should
    # not dilute module-specific coverage reports.
    "external/.*spbb/modules/helpers/imp/src/profiling_helpers.c",
    "external/.*spbb/modules/doppler_process/imp/src/b0_rest_map_doppler_a_ra_cmds.c",  # No functionality, just have a array commands
    "external/.*spbb/modules/range_process/imp/src/range_process_adc_light_comp_a_ra_cmds.c",  # No functionality, just have a array commands
    "external/.*spbb/modules/range_process/imp/src/range_process_ridm_cmds.c",  # No functionality, just have a array commands
    "external/.*spbb/modules/helpers/imp/src/sysmem_helpers.c",
    "external/.*spbb/modules/doppler_process/imp/inc/.*",
    "external/.*spbb/modules/cdc/imp/inc/.*",
    "external/.*spbb/common/spbb_sort.h",
    "external/.*bbe_luna_a0_asic_stl/include/.*",
    "external/.*appl_inclusion_dep/.*",
    "external/.*afbb/module/_imp/_src/common_src/compute_rcs_data.c",  # Data Files

    # drivers files are excluded here but have their own separate reports, so we can set different thresholds and focus on them separately from the rest of the codebase
    "software/r52/mmic/drivers/mars_api/.*",
    "software/common/chandra_r52_isr.c",
    "software/common/chandra_r52_gic.c",

    # local dependencies - these are part of our codebase but are not the focus of our coverage efforts (e.g. config files, headers without much logic, or modules we have separate reports for)
    "software/r52/autosar/config/Appl/GenData/.*",
    "software/bbe32/f360_tracker/.*",
    "software/r52/autosar/config/Appl/include/.*",
    "software/r52/autosar/config/Appl/Source/.*",
    "software/r52/dsp_setup/inc/.*",
    "software/r52/startup/inc/.*",
    "software/r52/drivers/mcal/inc/.*",
    "bazel-out/winarmr52-fastbuild/bin/software/common/versions/gitinfo.h",
    "bazel-out/linuxarmr52-fastbuild/bin/software/common/versions/gitinfo.h",
    "software/r52/r52_stack/stack_monitor_r52.h",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler/Include/.*",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging/stream_handler/stream_handler_rx.h",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_NvMHandler/Include/.*",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IntWDG/Include/.*",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/someip/someip_services.h",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/can/can_tx_msgs.h",
    "software/bbe32/bbe32_static_register_validation/bbe32_static_register_validation_cfg.h",
    "software/r52/autosar/swc/PLT_SWC/SWC_PRJ_Appl_FaultMgr/Source/SWC_PRJ_Appl_FaultMgr.c",
    "software/r52/mmic/indie_debug.c",
    "software/bbe32/inc/cdc_packing.h",  # Not having functionality to check, just a header with packing macros
    "software/common/cdc_frame_interface.h",  # Not having functionality to check, just a header with frame interface definitions
    "software/bbe32/adc_logging/xcp_adc_logging.c",
    "software/bbe32/adc_logging/xcp_adc_logging.h",
    "software/bbe32/bbe32_static_register_validation/bbe32_static_register_validation_cfg.h",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/Include/.*",
    # ------------------------------------------------------------------------------------------------
    # Files without unit tests - excluded to avoid penalizing coverage metrics & Recheck if they can be added to the report after adding unit tests
    "software/r52/drivers/mcal/src/mcal_init.c",  # Excluded - contains only hardware register writes (PLL init, SERDES, GPIO) with no testable logic; covered by integration/smoke tests
    "software/r52/main.c",  # Excluded - OS/AUTOSAR entry point (main, TASK macro bodies); no standalone testable logic; covered by integration/smoke tests
    "software/r52/startup/.*",  # Exclude all startup files, which are hard to cover with unit tests and have their own separate integration tests
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler/Source/SWC_PLT_CDD_WdgHandler_Test.c",  # Test has missing dep (SWC_PLT_CDD_WdgHandler_unit_test_support_lib)
    # Test files - we want to exclude test code from coverage metrics, but we still want to include the tests themselves in the report to see which lines are covered by tests
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync/Source/SWC_PLT_CDD_TimeSync.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/Source/Mss_Ecc_Parity.c",  # Dummy file without any functions, included in the report to show that it's not covered and needs tests, but excluded from coverage metrics so it doesn't bring down our overall numbers
    # ------------------------------------------------------------------------------------------
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag/Source/SWC_PLT_Appl_Diag_Test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IntWDG/Source/SWC_PLT_Appl_IntWDG_test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/Source/SWC_PLT_Appl_PlatformTime_Test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/Source/SWC_PLT_CDD_FailSafe_Test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/Source/SWC_CDD_IPC_test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/Source/MCU_Safety_test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Radar_Control/Source/SWC_PLT_CDD_Radar_Control_test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler/Source/SWC_PLT_Radar_Alignment_Handler_test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager/Source/SWC_PLT_Appl_ModeManager_Test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/someip/someip_services.c",  # Excluded - complex AUTOSAR dependencies, tested via integration
    "software/r52/integration_test/master_integration_test.h",  # Excluded - contains only test macros and definitions, no standalone logic to cover; included in the report to show that it's not covered and needs tests, but excluded from coverage metrics so it doesn't bring down our overall numbers
    "software/r52/integration_test/master_it_macros_test.h",  # Excluded - contains only test macros and definitions, no standalone logic to cover; included in the report to show that it's not covered and needs tests, but excluded from coverage metrics so it doesn't bring down our overall numbers
    ".*/emb_tracker_stubs.cpp",  # Stub implementation; test support code only
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/VSE/.*",  # Excluded VSE folder
]

coverage_report(
    name = "report",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    criteria = [
        "line",
        "decision",
        "function",
        "branch",
    ],
    exclude = UT_EXCLUDES + [
    ],
    find_untested_sources_from_targets = [
        "//:gen8",
    ],
    # TODO_UT to be improved
    include_test_files = True,
    min_branch = "85.0",
    min_decision = "90.0",
    min_function = "90.0",
    min_line = "90.0",
    subreports = [
        ":versions",
        ":r52_drivers_mcal_gpt",
        ":ecusync",
        ":appl_PLT_RTM",
        ":MCU_Safety",
        ":appl_PLT_Diag",
        ":appl_PLT_FaultMgr",
        ":Diagnostic_Library",
        ":Service_IoHwAb",
        ":Appl_IoHwAb",
        ":SWC_Appl_Modemanager",
        ":PLT_Appl_Modemanager",
        ":r52_dd_mmic",
        ":r52_appl_xcp",
        ":r52_Stream_Handler",
        ":r52_appl_alignment_handler",
        ":afbb",
        ":dabb",
        ":rcbb",
        ":sabb",
        ":idbb",
        ":spbb",
        ":Dyn_alignment_wrapper",
        ":Interference_detection_wrapper",
        ":Radar_capability_wrapper",
        ":Static_alignment_wrapper",
        ":dsp_bbe",
        ":cdd_externalwdg",
        ":SWC_PLT_CDD_MCU_Safety",
        ":SWC_PLT_CDD_Failsafe",
        ":FailSafe_Callout",
        ":SWC_PLT_CDD_FCRU",
        ":SWC_PLT_CDD_HIL",
        ":r52_stack_monitor",
        ":swc_plt_appl_communication",
        ":swc_appl_project",
        ":swc_plt_appl_nvmhandler",
        ":swc_plt_appl_intwdg",
        ":swc_plt_cdd_logging",
        ":swc_plt_cdd_xcp_logging",
        ":swc_plt_cdd_xcp_core",
        ":SWC_PLT_CDD_WdgHandler",
        ":plt_wdg_handler",
        ":swc_plt_appl_platformtime",
        ":swc_plt_cdd_ipc",
        ":swc_plt_cdd_timesync",
        ":swc_plt_cdd_ecusync",
        ":radar_ctl",
        ":bsw_callbacks",
        ":board_revision",
        ":crc_calc",
        ":rdd_proc_ifc",
        ":mpu",
        ":Calibration_Handler",
        ":SWC_PRJ_Appl_Power_Manager",
        ":SWC_PRJ_Appl_FaultMgr",
        ":SWC_PRJ_Appl_SensorPosition",
        ":SWC_CMP_PRJ_UDSHandler",
        ":dsp_setup",
        ":ipc_dsp",
        ":emb_tracker_wrapper",
        ":Sensor_Position",
    ],
    tests = [
        "//:all_unit_tests",
    ],
)

coverage_report(
    name = "ecusync",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        # Focus coverage only on ECU Sync sources, exclude other large deps
        "software/r52/autosar/config/.*",
        "software/r52/drivers/.*",
        "software/r52/bb_radar_ctl/.*",
        "software/common/.*",
        # Explicitly exclude external calibration handler implementation (only want ECUSync .c files)
        "external/.*Calibration_Handler/calib_handler/calibration.c",
    ],
    min_branch = "90",
    # Set thresholds based on detected coverage, aiming for 90%+
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync/test:SWC_PLT_CDD_ECUSync_unit_test",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync/test:unit_tests",
    ],
)

# This report is the same as :report, but without changes noted in-line below
coverage_report(
    name = "TICS",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    criteria = [
        "line",
        "decision",
        "function",
        "branch",
    ],
    exclude = UT_EXCLUDES,
    find_untested_sources_from_targets = [
        "//:gen8",
    ],
    include_test_files = True,
    # We always want TICS to run, do don't check quality thresholds. (min_decision, min_function, min_line)
    # TICS gets confused when there are multiple reports, so don't include subreports.
    tests = [
        "//:all_unit_tests",
    ],
)

coverage_report(
    name = "versions",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_branch = "0",
    min_decision = "0",
    min_function = "100",
    min_line = "100.0",
    tests = [
        "//software/common/versions/test:unit_tests",
    ],
)

coverage_report(
    name = "r52_drivers_mcal_gpt",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    min_branch = "100",
    min_decision = "100",
    min_function = "100",
    min_line = "100",
    tests = [
        "//software/r52/drivers/mcal/gpt/test:unit_tests",
    ],
)

coverage_report(
    name = "appl_PLT_RTM",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    min_decision = "90",
    min_function = "100",
    min_line = "100",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_RTM/test:unit_tests",
    ],
)

coverage_report(
    name = "MCU_Safety",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
        "software/common/board_revision/board_revision.c",
    ],
    # TODO_UT to be improved
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/test:Exception_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/test:Mss_Ecc_Parity_unit_test",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/test:static_register_safety_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/test:unit_tests",
    ],
)

coverage_report(
    name = "appl_PLT_FaultMgr",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    min_decision = "90",
    min_function = "100",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr/test:plt_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr/test:unit_tests",
    ],
)

coverage_report(
    name = "appl_PLT_Diag",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    min_decision = "80",
    min_function = "95",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag/test:plt_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag/test:unit_tests",
    ],
)

coverage_report(
    name = "Diagnostic_Library",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    # TODO_UT to be improved
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library/test:unit_tests",
    ],
)

coverage_report(
    name = "Service_IoHwAb",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    # TODO_UT to be improved
    min_decision = "40",
    min_function = "95",
    min_line = "90",
    tests = [
        "//software/common/board_revision/test:board_revision_unit_test",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/test:unit_tests",
        "@Calibration_Handler//calib_handler/test:calibration_unit_test",
    ],
)

coverage_report(
    name = "Appl_IoHwAb",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
        "software/common/board_revision/board_revision.c",
    ],
    min_decision = "90",
    min_function = "100",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb/test:plt_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb/test:unit_tests",
    ],
)

coverage_report(
    name = "r52_dd_mmic",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
        "software/common/board_revision/board_revision.c",
        "external/.*Calibration_Handler/calib_handler/calibration.c",
        ".*LdCom_Cfg_Generic\\.h",
        ".*LdCom_Lcfg\\.h",
    ],
    # TODO_UT to be improved
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/bb_radar_ctl/bb_radar_ctl_imp/test:unit_tests",
        "//software/r52/mmic/drivers/mipi_csi2/test:unit_tests",
        "//software/r52/mmic/test:unit_tests",
    ],
)

coverage_report(
    name = "r52_appl_xcp",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    # TODO_UT to be improved
    min_decision = "90",
    min_function = "100",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb/test:unit_tests",
    ],
)

coverage_report(
    name = "swc_plt_cdd_xcp_logging",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = [
        "external/.*iND13400_autosar_sip/.*",
        "external/.*iND13400_sdk/.*",
    ],
    min_branch = "70",
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/test:SWC_PLT_CDD_XCP_xcp_logging_unit_test",
    ],
)

coverage_report(
    name = "swc_plt_cdd_xcp_core",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_branch = "70",
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/test:core_unit_tests",
    ],
)

coverage_report(
    name = "swc_plt_cdd_logging",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging/test:unit_tests",
    ],
)

coverage_report(
    name = "r52_Stream_Handler",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
        # calibration.c is a transitive dep of SWC_PLT_CDD_Logging but has its own dedicated :Calibration_Handler report
        "external/.*Calibration_Handler/calib_handler/calibration.c",
        ".*LdCom_Cfg_Generic\\.h",
        ".*LdCom_Lcfg\\.h",
    ],
    # TODO_UT to be improved
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "@shbb//module:sh_unit_test_lib",
    ],
)

coverage_report(
    name = "r52_appl_alignment_handler",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler/test:unit_tests",
    ],
)

coverage_report(
    name = "afbb",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_branch = "80",
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "@afbb//:all_unit_tests",
        "@rm//:unit_tests",
    ],
)

coverage_report(
    name = "dabb",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    # TODO_UT to be improved
    min_branch = "90",
    min_decision = "90",
    min_function = "100",
    min_line = "90",
    tests = [
        "@dabb//module/test:unit_tests_lib",
    ],
)

coverage_report(
    name = "idbb",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        ".*/module/radar_math/.*",  # Exclude AFBB dependencies, which have their own dedicated report.
    ],
    # TODO_UT to be improved
    min_branch = "90",
    min_decision = "90",
    min_function = "95",
    min_line = "95",
    tests = [
        "@idbb//module/test:unit_tests_lib",
    ],
)

coverage_report(
    name = "rcbb",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    # TODO_UT to be improved
    min_branch = "80",
    min_decision = "85",
    min_function = "96",
    min_line = "90",
    tests = [
        "@rcbb//:RC_unit_tests",
    ],
)

coverage_report(
    name = "Dyn_alignment_wrapper",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "external/.*dabb/.*",
        ".*/mem_pool.h",
    ],
    # TODO_UT to be improved
    min_branch = "70",
    min_decision = "75",
    min_function = "100",
    min_line = "98",
    tests = [
        "@Dyn_alignment_module_interface//test:unit_tests",
    ],
)

coverage_report(
    name = "Interference_detection_wrapper",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        ".*/module/radar_math/.*",  # Exclude AFBB dependencies, which have their own dedicated report.
    ],
    # TODO_UT to be improved
    min_branch = "95",
    min_decision = "95",
    min_function = "95",
    min_line = "95",
    tests = [
        "//software/bbe32/interference_detection/test:unit_tests",
    ],
)

coverage_report(
    name = "Radar_capability_wrapper",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "external/.*rcbb/.*",
    ],
    # TODO_UT to be improved
    min_branch = "79",
    min_decision = "70",
    min_function = "94",
    min_line = "95",
    tests = [
        "@radar_capability_module_interface//test:unit_tests",
    ],
)

coverage_report(
    name = "Static_alignment_wrapper",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "external/.*sabb/.*",
        ".*/mem_pool.h",
    ],
    # TODO_UT to be improved
    min_branch = "80",
    min_decision = "75",
    min_function = "100",
    min_line = "97",
    tests = [
        "@Static_alignment_module_interface//test:unit_tests",
    ],
)

coverage_report(
    name = "sabb",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_branch = "95",
    min_decision = "100",
    min_function = "100",
    min_line = "100",
    tests = [
        "@sabb//module/test:unit_tests",
    ],
)

coverage_report(
    name = "spbb",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_branch = "90",
    min_decision = "90",
    min_function = "95",
    min_line = "95",
    tests = [
        "@spbb//:spbb_tests",
    ],
)

coverage_report(
    name = "dsp_bbe",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        ".*/external/.*spbb/.*",  # Exclude SPBB dependencies, which have their own dedicated report.
        ".*/module/radar_math/.*",  # Exclude AFBB dependencies, which have their own dedicated report.
        ".*/external/.*rotbb/.*",  # Exclude ROTBB dependencies, which have their own dedicated report.
        "software/bbe32/src/ipc_dsp.c",  # IPC DSP code is covered under the :ipc_dsp report, so exclude it here.
        "software/bbe32/src/get_r52_time_from_bbe32.c",  # can be removed from excludes once after the unit test is added.
    ],
    # TODO_UT to be improved for get_r52_time_from_bbe32.c and can be removed from excludes after the unit test is added.
    min_branch = "75",
    min_decision = "75",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/bbe32/bbe32_static_register_validation/test:unit_tests",
        "//software/bbe32/bbe_self_test/test:unit_tests",
        "//software/bbe32/dss_ecc_parity/test:unit_tests",
        "//software/bbe32/emb_tracker/test:unit_tests",
        "//software/bbe32/src/test:unit_tests",
        "//software/bbe32/test:all_tests",
    ],
)

coverage_report(
    name = "SWC_Appl_Modemanager",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    min_branch = "0",
    min_decision = "0",
    min_function = "100",
    min_line = "100",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager/test:unit_tests",
    ],
)

coverage_report(
    name = "PLT_Appl_Modemanager",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    min_decision = "95",
    min_function = "100",
    min_line = "98",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager/test:plt_unit_tests",
    ],
)

coverage_report(
    name = "cdd_externalwdg",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    # TODO_UT to be improved
    min_branch = "90",
    min_decision = "90",
    min_function = "100",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg/test:unit_tests",
    ],
)

coverage_report(
    name = "SWC_PLT_CDD_MCU_Safety",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
        "software/common/board_revision/board_revision.c",
    ],
    min_branch = "0",
    min_decision = "0",
    min_function = "100",
    min_line = "100",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/test:unit_tests",
    ],
)

coverage_report(
    name = "SWC_PLT_CDD_Failsafe",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    # TODO_UT to be improved
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/test:unit_tests",
    ],
)

coverage_report(
    name = "FailSafe_Callout",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    # TODO_UT to be improved
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/test:unit_tests",
    ],
)

coverage_report(
    name = "SWC_PLT_CDD_HIL",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
        "external/.*Calibration_Handler/calib_handler/calibration.c",
        "bazel-out/.*IpBase/.*",
        ".*LdCom_Cfg_Generic\\.h",
        ".*LdCom_Lcfg\\.h",
    ],
    min_branch = "95",
    min_decision = "95",
    min_function = "95",
    min_line = "95",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL/hil/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL/test:HIL_unit_tests",
    ],
)

coverage_report(
    name = "SWC_PLT_CDD_FCRU",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    # TODO_UT to be improved
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/common/board_revision/test:unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FCRU/test:FCRU_unit_tests",
    ],
)

coverage_report(
    name = "r52_stack_monitor",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    # Set high thresholds to ensure quality - aiming for 95%+
    min_decision = "95",
    min_function = "95",
    min_line = "95",
    tests = [
        "//software/r52/r52_stack/test:unit_tests",
    ],
)

coverage_report(
    name = "swc_plt_appl_communication",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/.*",
        "software/r52/autosar/config/.*",
        "external/.*Calibration_Handler/calib_handler/calibration.c",
        "external/.*sensor_position/sensor_position.c",
    ],
    min_branch = "85",
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        # Include communication unit tests for CAN RX/TX, SOME/IP and application paths.
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/test:can_rx_msgs_unit_test",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/test:can_tx_msgs_unit_test",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/test:swc_plt_appl_comm_unit_test",
    ],
)

coverage_report(
    name = "swc_appl_project",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PRJ_SWC/SWC_Appl_Project/test:unit_tests",
    ],
)

coverage_report(
    name = "swc_plt_appl_nvmhandler",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_branch = "70",
    min_decision = "75",
    min_function = "95",
    min_line = "95",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_NvMHandler/test:unit_tests",
    ],
)

coverage_report(
    name = "swc_plt_appl_intwdg",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_branch = "90",
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IntWDG/test:unit_tests",
    ],
)

coverage_report(
    name = "SWC_PLT_CDD_WdgHandler",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    # TODO_UT to be improved
    min_branch = "90",
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler/test:unit_tests",
    ],
)

coverage_report(
    name = "plt_wdg_handler",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    min_branch = "90",
    min_decision = "100",
    min_function = "100",
    min_line = "100",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler/test:plt_unit_tests",
    ],
)
# Note: Decision and Branch coverage set to 0% as there are no runtime branches in this module to test. Sometimes it is 0/0 which is correct. This requires Source code review/change to get any better coverage here.

coverage_report(
    name = "swc_plt_appl_platformtime",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
        "software/common/.*",
        "software/r52/autosar/config/.*",
        ".*/LdCom_Cfg_Generic\\.h",
        ".*/LdCom_Lcfg\\.h",
    ],
    # Set high thresholds - aiming for 95%+ coverage
    # The 0/0 for branches and decisions is correct and expected - there are no runtime conditional branches in this file to test!
    min_branch = "100",
    min_decision = "100",
    min_function = "100",
    min_line = "100",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/test:unit_tests",
    ],
)

coverage_report(
    name = "swc_plt_cdd_ipc",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/.*",
        "software/r52/autosar/config/.*",
        "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/VSE/.*",
    ],
    # Set high thresholds - aiming for 95%+ coverage
    # TODO_UT to be improved
    min_branch = "70",
    min_decision = "80",
    min_function = "95",
    min_line = "95",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/test:unit_tests",
    ],
)

coverage_report(
    name = "swc_plt_cdd_timesync",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    min_branch = "0",
    min_decision = "0",
    min_function = "0",  # dummy file with no functions, so set to 0% to avoid confusion
    min_line = "0",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync/test:unit_tests",
    ],
)

coverage_report(
    name = "swc_plt_cdd_ecusync",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
        "external/.*Calibration_Handler/calib_handler/calibration.c",
    ],
    min_branch = "90",
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync/test:unit_tests",
    ],
)

coverage_report(
    name = "radar_ctl",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/.*",
        "software/r52/autosar/config/.*",
        "software/r52/drivers/.*",
        "software/r52/bb_radar_ctl/.*",
        "software/r52/mmic/.*",
    ],
    # Set high thresholds - aiming for 95%+ coverage
    min_branch = "90",
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Radar_Control/test:unit_tests",
    ],
)

coverage_report(
    name = "bsw_callbacks",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = [
        # Exclude external dependencies
        "external/.*iND13400_autosar_sip/.*",
        "external/.*iND13400_sdk/.*",
        # Exclude mocks but NOT the wrapper files
        ".*/mocks/.*",
        # Exclude all other modules except BSW callbacks wrappers
        "software/r52/autosar/swc/.*",
        "software/r52/autosar/config/Appl/GenData/.*",
        "software/r52/drivers/.*",
        "software/r52/bb_radar_ctl/.*",
        "software/r52/mmic/.*",
        "software/r52/startup/.*",
        "software/r52/r52_stack/.*",
        "software/r52/dsp_setup/.*",
        "software/common/.*",
        "software/bbe32/.*",
        # Exclude test files including wrapper files
        ".*unit_test\\.cc",
        ".*_fakes\\.h",
        ".*stubs_.*\\.c",
        ".*_wrapper\\.c",
    ],
    # Set moderate thresholds for BSW callback code
    # These are AUTOSAR-generated stubs with user additions
    # min_decision is 0 because the coverage tool does not produce decision
    # coverage data for BSW callback/driver files (consistent with other
    # generated/callback modules: versions, SWC_Appl_Modemanager,
    # swc_plt_cdd_logging, swc_appl_project, swc_plt_appl_communication).
    min_branch = "90",
    min_decision = "0",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/config/Appl/Source/test:unit_tests",
    ],
)

coverage_report(
    name = "board_revision",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    # min_branch is capped at 75% (3/4) because Branch 1 of Is_Within_Limits()
    # (i.e. board_rev_cnt < Board_Rev_Th[i].lower) is structurally unreachable:
    # Board_Rev_Th thresholds are perfectly contiguous starting from 0, so for
    # uint16_t the left operand of && can never be false at any loop iteration.
    min_branch = "75",
    min_decision = "90",
    min_function = "100",
    min_line = "100",
    tests = [
        "//software/common/board_revision/test:unit_tests",
    ],
)

coverage_report(
    name = "crc_calc",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/chandra_r52_isr.c",
        "software/common/chandra_r52_gic.c",
    ],
    min_branch = "90",
    # TODO_UT to be improved
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/common/crc_calc/test:unit_tests",
    ],
)

coverage_report(
    name = "mpu",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_branch = "90",
    # TODO_UT to be improved
    min_decision = "90",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/bbe32/mpu/test:unit_tests",
    ],
)

coverage_report(
    name = "Calibration_Handler",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_branch = "90",
    # TODO_UT to be improved
    min_decision = "89",
    min_function = "90",
    min_line = "90",
    tests = [
        "@Calibration_Handler//calib_handler/test:calibration_unit_test",
    ],
)

coverage_report(
    name = "Sensor_Position",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_branch = "95",
    # TODO_UT to be improved
    min_decision = "95",
    min_function = "95",
    min_line = "95",
    tests = [
        "@Sensor_Position//:unit_tests",
    ],
)

coverage_report(
    name = "rdd_proc_ifc",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        ".*/external/.*spbb/.*",  # Exclude SPBB dependencies, which have their own dedicated report.
        ".*/mem_pool.h",  # Exclude mem_pool.h here, as it is part of dsp_bbe.
    ],
    min_branch = "95",
    min_decision = "95",
    min_function = "95",
    min_line = "95",
    tests = [
        "//software/bbe32/rdd_proc/test:all_tests",
        "//software/bbe32/test:range_doppler_tests",
    ],
)

coverage_report(
    name = "dsp_setup",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        "software/common/board_revision/board_revision.c",
        "software/r52/program_flow_monitor/.*",
        "external/.*Calibration_Handler/.*",
        ".*LdCom_Cfg_Generic\\.h",
        ".*LdCom_Lcfg\\.h",
    ],
    min_branch = "90",
    min_decision = "90",
    min_function = "95",
    min_line = "95",
    tests = [
        "//software/r52/dsp_setup/test:unit_tests",
    ],
)

coverage_report(
    name = "ipc_dsp",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        ".*/external/.*spbb/.*",  # Exclude SPBB dependencies, which have their own dedicated report.
    ],
    min_branch = "90",
    min_decision = "90",
    min_function = "95",
    min_line = "95",
    tests = [
        "//software/bbe32/test:ipc_dsp_test",
    ],
)

coverage_report(
    name = "ipc_mss",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        ".*LdCom_Lcfg.h",
        "external/.*Calibration_Handler/.*",
        ".*SWC_PLT_Appl_PlatformTime.*",
    ],
    min_branch = "95",
    min_decision = "90",
    min_function = "95",
    min_line = "95",
    tests = [
        "//software/r52/ipc/test:unit_tests",
    ],
)

coverage_report(
    name = "SWC_PRJ_Appl_Power_Manager",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_branch = "0",
    min_decision = "0",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_Power_Manager/test:Appl_Power_Manager_unit_tests",
    ],
)

coverage_report(
    name = "SWC_PRJ_Appl_FaultMgr",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_branch = "0",
    min_decision = "0",
    min_function = "0",
    min_line = "0",
    tests = [
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_FaultMgr/test:SWC_PRJ_Appl_FaultMgr_unit_test",
    ],
)

coverage_report(
    name = "SWC_PRJ_Appl_SensorPosition",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_branch = "0",
    min_decision = "0",
    min_function = "0",
    min_line = "0",
    tests = [
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_SensorPosition/test:Appl_SensorPosition_unit_tests",
    ],
)

coverage_report(
    name = "SWC_CMP_PRJ_UDSHandler",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES,
    min_branch = "0",
    min_decision = "0",
    min_function = "90",
    min_line = "90",
    tests = [
        "//software/r52/autosar/swc/PRJ_SWC/SWC_CMP_PRJ_UDSHandler/test:UDSHandler_unit_tests",
    ],
)

coverage_report(
    name = "emb_tracker_wrapper",
    compile_coverage_exclude = COMPILE_UT_EXCLUDES,
    exclude = UT_EXCLUDES + [
        ".*/mem_pool.h",  # Transitive dep; has its own dedicated tests
        "bazel-out/.*rotbb/.*",  # rotbb virtual includes reported under bazel-out path by gcovr
    ],
    min_branch = "90",
    min_decision = "90",
    min_function = "95",
    min_line = "95",
    tests = [
        "//software/bbe32/emb_tracker/test:unit_tests",
    ],
)
