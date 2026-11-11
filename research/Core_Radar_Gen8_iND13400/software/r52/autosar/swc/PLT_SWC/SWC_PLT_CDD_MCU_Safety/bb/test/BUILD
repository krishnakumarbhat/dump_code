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
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_NvMHandler/Include/.*",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IntWDG/Include/.*",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/someip/someip_services.h",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/can/can_tx_msgs.h",
    "software/bbe32/bbe32_static_register_validation/bbe32_static_register_validation_cfg.h",
    "software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_FaultMgr/Source/SWC_PRJ_Appl_FaultMgr.c",
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
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/Source/MCU_Safety_test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Radar_Control/Source/SWC_PLT_CDD_Radar_Control_test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler/Source/SWC_PLT_Radar_Alignment_Handler_test.c",
    "software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager/Source/SWC_PLT_Appl_ModeManager_Test.c",
]

cc_library(
    name = "MCU_Safety_fake_lib",
    srcs = [
        "MCU_Safety_fake.cc",
    ],
    hdrs = [
        "MCU_Safety_fake.h",
    ],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb:MCU_Safety_unit_test_support_lib",
        "@fff",
    ],
)

cc_library(
    name = "mss_ecc_parity_fake_lib",
    srcs = [
        "Mss_Ecc_Parity_fake.cc",
    ],
    hdrs = [
        "Mss_Ecc_Parity_fake.h",
    ],
    deps = [
        "@fff",
    ],
)

cc_test(
    name = "MCU_Safety_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "MCU_Safety_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":MCU_Safety_fake_lib",
        ":mss_ecc_parity_fake_lib",
        ":static_register_safety_mocks_lib",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb:MCU_Safety_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "Mss_Ecc_Parity_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "Mss_Ecc_Parity_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb:Mss_Ecc_Parity_ut_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb:SWC_PLT_CDD_MCU_Safety_h",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "NOC_Handler_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "NOC_Handler_unit_test.cc",
    ],
    linkstatic = True,
    local_defines = ["UNIT_TEST"],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/test:FailSafe_callout_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb:NOC_Handler_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":MCU_Safety_unit_test",
        ":Mss_Ecc_Parity_unit_test",
        ":NOC_Handler_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)

test_suite(
    name = "NOC_Handler_unit_tests",
    tests = [
        ":NOC_Handler_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)

cc_test(
    name = "Exception_handler_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "Exception_handler_unit_test.cc",
    ],
    linkstatic = True,
    local_defines = ["UNIT_TEST"],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":Crc_fake_lib",
        "//software/common/versions:versions_hdrs",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/test:FailSafe_callout_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb:Exception_handler_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb:SWC_PLT_CDD_MCU_Safety_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

cc_library(
    name = "Exception_handler_mocks",
    srcs = [
        "Exception_handler_mocks.cc",
    ],
    hdrs = [
        "Exception_handler_mocks.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@fff",
    ],
)

test_suite(
    name = "Exception_unit_tests",
    tests = [
        ":Exception_handler_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)

cc_library(
    name = "static_register_safety_mocks_lib",
    srcs = [
        "static_register_safety_mocks.cc",
    ],
    hdrs = [
        "static_register_safety_mocks.h",
    ],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb:static_register_safety_test_support_lib",
        "@fff",
    ],
)

cc_library(
    name = "Crc_fake_lib",
    srcs = [
        "Crc_mocks.cc",
    ],
    hdrs = [
        "Crc_mocks.h",
    ],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@fff",
        "@iND13400_autosar_sip//Components/Crc:Crc_h",
        "@reuse",
    ],
)

cc_library(
    name = "radar_ctl_fake_lib",
    hdrs = [
        "radar_ctl.h",
    ],
    deps = [
    ],
)

cc_test(
    name = "static_register_safety_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "static_register_safety_unit_test.cc",
    ],
    linkstatic = True,
    local_defines = ["UNIT_TEST"],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":Crc_fake_lib",
        ":radar_ctl_fake_lib",
        "//software/common/board_revision/test/mocks:board_revision_mocks",
        "//software/common/versions:versions_hdrs",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/test:FailSafe_callout_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb:static_register_safety_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "static_register_safety_unit_tests",
    tests = [
        ":static_register_safety_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
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
        # "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/test:Exception_unit_tests",
        # "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/test:static_register_safety_unit_tests",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb/test:unit_tests",
    ],
)
