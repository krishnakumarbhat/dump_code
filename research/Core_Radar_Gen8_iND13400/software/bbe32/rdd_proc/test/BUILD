cc_test(
    name = "appl_cfar_ifc_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "appl_cfar_ifc_unit_test.cc",
    ],
    copts = [],
    defines = [
        "SMC_Cal_Data_T=SMC_Cal_T",
    ],
    linkopts = [],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/rdd_proc/imp/src:appl_cfar_ifc_ut_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@spbb//modules/cfar/api/mocks:cfar_mock_lib",
        "@spbb//modules/doppler_process:doppler_proc_include_h",
    ],
)

cc_test(
    name = "appl_adaptive_cfar_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "appl_adaptive_cfar_unit_test.cc",
    ],
    copts = [],
    linkopts = [],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/rdd_proc/imp/src:appl_adaptive_cfar_ut_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "appl_fp_ifc_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "appl_fp_ifc_unit_test.cc",
    ],
    copts = [],
    linkopts = [],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:doppler_process_ifc_h",
        "//software/bbe32/inc:mem_pool_h",
        "//software/bbe32/rdd_proc/imp/src:appl_fp_ifc_ut_lib",
        "//software/bbe32/test/mocks:ipc_mock_lib",
        "//software/common/calibrations/usc:usc_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@spbb//common:bbe_xtensa_mock_lib",
        "@spbb//modules/doppler_process:doppler_proc_include_h",
        "@spbb//modules/helpers:bbe_helpers_h",
        "@spbb//modules/rdd_first_pass_process/api/mocks:first_pass_mock_lib",
    ],
)

cc_test(
    name = "appl_sp_ifc_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "appl_sp_ifc_unit_test.cc",
    ],
    copts = [],
    defines = [
        "SMC_Cal_Data_T=SMC_Cal_T",
    ],
    linkopts = [],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/rdd_proc/imp/src:appl_sp_ifc_ut_lib",
        "//software/bbe32/test/mocks:ipc_mock_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@spbb//modules/second_pass/api/mocks:second_pass_mock_lib",
    ],
)

cc_test(
    name = "appl_sweepbw_ifc_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "appl_sweepbw_ifc_unit_test.cc",
    ],
    copts = [],
    linkopts = [],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/rdd_proc/imp/src:appl_sweepbw_ifc_ut_lib",
        "//software/bbe32/test/mocks:ipc_mock_lib",
        "@com_google_googletest//:gtest_main",
        "@spbb//modules/sweep_bw/api/mocks:sweep_bw_mock_lib",
    ],
)

test_suite(
    name = "all_tests",
    tests = [
        ":appl_adaptive_cfar_unit_test",
        ":appl_cfar_ifc_unit_test",
        ":appl_fp_ifc_unit_test",
        ":appl_sp_ifc_unit_test",
        ":appl_sweepbw_ifc_unit_test",
    ],
    visibility = ["//visibility:public"],
)
