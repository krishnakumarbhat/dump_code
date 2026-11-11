cc_library(
    name = "bbe32_main_fake_lib",
    srcs = [],
    hdrs = ["bbe32_main_fake.h"],
    strip_include_prefix = "//software/bbe32/test",
    visibility = ["//visibility:public"],
    deps = ["@fff"],
)

cc_test(
    name = "bbe32_main_unit_test",
    size = "small",
    timeout = "short",
    srcs = ["bbe32_main_unit_test.cc"],
    copts = [
        "-Wno-pragma-pack",
        "-DUNIT_TEST",
    ],
    features = ["-layering_check"],
    linkstatic = True,
    target_compatible_with = ["@platforms//cpu:x86_64"],
    deps = [
        ":bbe32_main_fake_lib",
        "//software/bbe32:main_ut_lib",
        "//software/bbe32/inc:include_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

cc_test(
    name = "mem_pool_test",
    size = "small",
    timeout = "short",
    srcs = [
        "mem_pool_unit_test.cc",
    ],
    copts = [],
    defines = [],
    linkopts = [],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:mem_pool_h",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "ci_stv_test",
    size = "small",
    timeout = "short",
    srcs = [
        "ci_misalign_stv_unit_test.cc",
    ],
    copts = [],
    defines = ["restrict=__restrict"],
    linkopts = [],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/src:ci_stv_misalignment_ut_lib",
        "//software/bbe32/test/test_data:ci_misalign_stv_test_data_lib",
        "@appl_inclusion_dep//:spbb_include_h",
        "@com_google_googletest//:gtest_main",
        "@spbb//common:common_lib",
        "@spbb//common/cstub_helpers:cstub_helpers_lib",
    ],
)

cc_test(
    name = "cdc_packing_test",
    size = "small",
    timeout = "short",
    srcs = [
        "cdc_packing_unit_test.cc",
    ],
    copts = ["-fno-exceptions"],
    defines = ["restrict=__restrict"],
    linkopts = [],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:cdc_packing_h",
        "//software/bbe32/inc:doppler_process_ifc_h",
        "//software/bbe32/src:cdc_packing_ut_lib",
        "//software/bbe32/test/mocks:appl_fp_ifc_mock_lib",
        "//software/common:cdc_stream_h",
        "//software/common:rdd_stream_h",
        "//software/common/calibrations/smc:smc_h",
        "@Gen8_iND13400//software/common/calibrations/smc:radar_sw_config_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@spbb//common:bbe_xtensa_mock_lib",
        "@spbb//common:common_lib",
        "@spbb//modules/doppler_process:doppler_proc_include_h",
        "@spbb//modules/helpers:profiling_helpers_h",
        "@spbb//modules/helpers/api/mocks:bbe_helpers_mock_lib",
        "@spbb//modules/rdd_first_pass_process/api/mocks:first_pass_mock_lib",
    ],
)

cc_test(
    name = "doppler_process_ifc_test",
    size = "small",
    timeout = "short",
    srcs = [
        "doppler_process_ifc_unit_test.cc",
    ],
    copts = ["-fpermissive"],
    defines = [],
    linkopts = [],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:doppler_process_ifc_h",
        "//software/bbe32/inc:range_process_ifc_h",
        "//software/bbe32/integration_test:dsp_it_macros_test_h",
        "//software/bbe32/rdd_proc/test/mocks:appl_cfar_ifc_mock_lib",
        "//software/bbe32/rdd_proc/test/mocks:appl_fp_ifc_mock_lib",
        "//software/bbe32/rdd_proc/test/mocks:appl_sp_ifc_mock_lib",
        "//software/bbe32/rdd_proc/test/mocks:appl_sweepbw_ifc_mock_lib",
        "//software/bbe32/src:dopplerproc_ifc_ut_lib",
        "//software/bbe32/test/mocks:ci_stv_misalignment_mock_lib",
        "//software/bbe32/test/mocks:ipc_mock_lib",
        "//software/common/calibrations/usc:usc_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@spbb//common:bbe_xtensa_mock_lib",
        "@spbb//common/cstub_helpers:cstub_helpers_lib",
        "@spbb//modules/cfar/api/mocks:cfar_mock_lib",
        "@spbb//modules/doppler_process/api/mocks:doppler_process_mock_lib",
        "@spbb//modules/helpers:bbe_helpers_h",
        "@spbb//modules/helpers/api/mocks:ra_helpers_mock_lib",
        "@spbb//modules/second_pass/api/mocks:second_pass_mock_lib",
        "@spbb//modules/sweep_bw/api/mocks:sweep_bw_mock_lib",
    ],
)

cc_test(
    name = "range_process_ifc_test",
    size = "small",
    timeout = "short",
    srcs = [
        "range_process_ifc_unit_test.cc",
    ],
    copts = ["-fpermissive"],
    defines = [
        "ENABLE_CHIRP_PROFILING_INFO",
        "ENABLE_ADC_DATA_LOGGING=1",
    ],
    linkopts = [],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/adc_logging/mocks:xcp_adc_logging_mock_lib",
        "//software/bbe32/inc:mem_pool_h",
        "//software/bbe32/inc:range_process_ifc_h",
        "//software/bbe32/src:rangeproc_ifc_ut_lib",
        "//software/bbe32/test/mocks:ipc_mock_lib",
        "//software/bbe32/test/mocks:mipi_ifc_mock_lib",
        "//software/common/calibrations/smc:smc_h",
        "//software/r52/mmic/drivers/mipi_csi2/test/mocks:dd_mipi_mock_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@spbb//common:bbe_xtensa_mock_lib",
        "@spbb//common:common_h",
        "@spbb//common/cstub_helpers:cstub_helpers_lib",
        "@spbb//modules/helpers/api/mocks:mipi_helpers_mock_lib",
        "@spbb//modules/helpers/api/mocks:profiling_helpers_mock_lib",
        "@spbb//modules/helpers/api/mocks:ra_helpers_mock_lib",
        "@spbb//modules/range_process/api/mocks:range_process_mock_lib",
    ],
)

cc_test(
    name = "performance_monitor_ifc_test",
    size = "small",
    timeout = "short",
    srcs = [
        "performance_monitor_ifc_unit_test.cc",
    ],
    copts = [],
    defines = [],
    linkopts = [],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:performance_monitor_ifc_h",
        "//software/bbe32/src:performance_monitor_ifc_ut_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@spbb//common:bbe_xtensa_mock_lib",
        "@spbb//common:common_lib",
        "@spbb//modules/helpers/imp/src/perfmon:perfmon_helpers_ut_lib",
    ],
)

cc_library(
    name = "generic_drv_sfr_stub",
    hdrs = ["Generic_Drv_sfr.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = ["@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h"],
)

cc_test(
    name = "ipc_dsp_test",
    size = "small",
    timeout = "short",
    srcs = [
        "ipc_dsp_unit_test.cc",
    ],
    copts = [
        "-fpermissive",
    ],
    defines = [
        "UNIT_TEST",  # Enable unit test mode - removes section attributes
        "ENABLE_IPC_CRC",  # Enable CRC path for header validation tests
        "ENABLE_IPC_CRC_PROFILING",  # Enable profiling path for timing tests
        "XCP_FAULT_INJECTION",  # Enable XCP fault injection paths
    ],
    linkopts = [],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        ":generic_drv_sfr_stub",
        "//software/bbe32/TOI_char_quality_determination/test:toi_algo_interface_mock_lib",
        "//software/bbe32/src:ipc_dsp_ut_lib",
        "//software/bbe32/test/mocks:mipi_ifc_mock_lib",
        "//software/bbe32/test/mocks:range_process_ifc_mock_lib",
        "//software/common/crc_calc/test/mocks:crc_calc_mocks_lib",
        "//software/common/ipc/test/mocks:ipc_data_fake_lib",
        "//software/common/mmic:mmic_common_types_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@spbb//common:bbe_xtensa_mock_lib",
        "@spbb//modules/helpers:bbe_helpers_ut_h",
        "@spbb//modules/helpers/api/mocks:idma_helpers_mock_lib",
    ],
)

test_suite(
    name = "all_tests",
    tests = [
        ":bbe32_main_unit_test",
        ":ci_stv_test",
        ":ipc_dsp_test",
        ":mem_pool_test",
        ":performance_monitor_ifc_test",
    ],
    visibility = ["//visibility:public"],
)

test_suite(
    name = "range_doppler_tests",
    tests = [
        ":doppler_process_ifc_test",
        ":range_process_ifc_test",
    ],
    visibility = ["//visibility:public"],
)
