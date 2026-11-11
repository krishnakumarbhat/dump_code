load("@bazel_platform//quality/ut:coverage_report.bzl", "coverage_report")

COMPILE_UT_EXCLUDES = [
    "external/.*com_google_googletest~?.*/.*",  # GoogleTest framework
    "external/.*mingw64_10_0_0_rev0~?.*/.*",  # Windows MinGW Compiler
    "external/.*gcc-glibc~?.*/.*",  # Linux GCC compiler
    "external/.*bbe_(linux|windows).*/.*",
]

UT_EXCLUDES = [
    "external/.*iND13400_autosar_sip/.*",
    "external/.*iND13400_sdk/.*",
    ".*/test/.*",
    ".*/_test/.*",
    ".*/mocks/.*",
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
    "external/.*spbb/modules/doppler_process/imp/inc/.*",
    "external/.*spbb/modules/cdc/imp/inc/.*",
    "external/.*spbb/common/spbb_sort.h",
    "external/.*bbe_luna_a0_asic_stl/include/.*",
    "external/.*appl_inclusion_dep/.*",
    "external/.*Sensor_Position/sensor_position/sensor_position_cfg.h",
    "external/.*afbb/module/_imp/_src/common_src/compute_rcs_data.c",  # Data Files

    # drivers files are excluded here but have their own separate reports, so we can set different thresholds and focus on them separately from the rest of the codebase
    "software/r52/mmic/drivers/mars_api/.*",

    # local dependencies - these are part of our codebase but are not the focus of our coverage efforts (e.g. config files, headers without much logic, or modules we have separate reports for)
    "software/r52/autosar/config/Appl/GenData/.*",
    "software/bbe32/f360_tracker/.*",
    "software/r52/autosar/config/Appl/include/.*",
    "software/r52/autosar/config/Appl/Source/.*",
    "software/r52/dsp_setup/inc/.*",
    "software/r52/startup/inc/.*",
    "bazel-out/linuxarmm7-dbg/bin/software/common/versions/gitinfo.h",
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
    "software/bbe32/adc_logging/xcp_adc_logging.c",
    "software/bbe32/adc_logging/xcp_adc_logging.h",
    "software/bbe32/bbe32_static_register_validation/bbe32_static_register_validation_cfg.h",

    # Test files - we want to exclude test code from coverage metrics, but we still want to include the tests themselves in the report to see which lines are covered by tests
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag/Source/SWC_PLT_Appl_Diag_Test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IntWDG/Source/SWC_PLT_Appl_IntWDG_test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/Source/SWC_PLT_Appl_PlatformTime_Test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/Source/SWC_PLT_CDD_FailSafe_Test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/Source/SWC_CDD_IPC_test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/Source/MCU_Safety_test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Radar_Control/Source/SWC_PLT_CDD_Radar_Control_test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler/Source/SWC_PLT_Radar_Alignment_Handler_test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager/Source/SWC_PLT_Appl_ModeManager_Test.c",
]

cc_library(
    name = "swc_platformtime_fakes",
    srcs = [
        "SWC_PLT_Appl_PlatformTime_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_Appl_PlatformTime_MemMap.h",
        "SWC_PLT_Appl_PlatformTime_fake.h",
    ],
    copts = [
        "-Iexternal/fff",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:SWC_PLT_PlatformTime_unit_test_support_lib",
        "@fff",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:priv_sfrs",
    ],
)

cc_library(
    name = "platformtime_fff",
    srcs = [
        "platformtime_fff.cc",
    ],
    hdrs = [
        "platformtime_fff.h",
    ],
    copts = [
        "-Iexternal/fff",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:SWC_PLT_PlatformTime_unit_test_support_lib",
        "@fff",
    ],
)

cc_test(
    name = "SWC_PltformTime_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PltTime_unit_test.cc",
    ],
    copts = [
        "-Isoftware/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/test",
    ],
    defines = ["UNITTEST"],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":swc_platformtime_fakes",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:SWC_PLT_PlatformTime_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":SWC_PltformTime_unit_test",
        # Add other unit tests here
    ],
    visibility = ["//visibility:public"],
)

coverage_report(
    name = "Platform_time",
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
        # "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/test:Exception_unit_tests",
        # "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/test:static_register_safety_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/test:unit_tests",
    ],
)
