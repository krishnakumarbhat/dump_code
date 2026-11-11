###############################################################################
# Shared Xtensa stub headers for x86_64 unit testing
###############################################################################
cc_library(
    name = "xtensa_stubs",
    hdrs = [
        "Generic_Drv_sfr.h",
        "xtensa/config/core.h",
        "xtensa/hal.h",
        "xtensa/tie/xt_bbe32.h",
        "xtensa/tie/xt_bben.h",
        "xtensa/tie/xt_ioports.h",
        "xtensa/xtruntime.h",
    ],
    strip_include_prefix = "//software/bbe32/src/test",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "main_application_fake_lib",
    srcs = ["main_application_fake.cc"],
    hdrs = ["main_application_fake.h"],
    strip_include_prefix = "//software/bbe32/src/test",
    visibility = ["//visibility:public"],
    deps = ["@fff"],
)

cc_library(
    name = "main_application_textual_lib",
    defines = [
        "TRACKER_ENABLED",
        "AL_TRACKER",
    ],
    deps = [
        ":main_application_fake_lib",
        ":xtensa_stubs",
        "//software/bbe32/Ra_fault_injection:Ra_fault_injection_h",
        "//software/bbe32/TOI_char_quality_determination:radar_data_quality_h",
        "//software/bbe32/adc_logging:adc_data_logging_h",
        "//software/bbe32/bbe32_static_register_validation:bbe32_static_register_validation_h",
        "//software/bbe32/bbe_self_test:fusa_bbe_self_test_h",
        "//software/bbe32/dss_ecc_parity:dss_ecc_parity_h",
        "//software/bbe32/inc:angle_finding_project_interface_h",
        "//software/bbe32/inc:doppler_process_ifc_h",
        "//software/bbe32/inc:include_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/inc:mem_pool_h",
        "//software/bbe32/inc:mipi_ifc_h",
        "//software/bbe32/inc:performance_monitor_ifc_h",
        "//software/bbe32/inc:range_process_ifc_h",
        "//software/bbe32/integration_test:dsp_it_macros_test_h",
        "//software/bbe32/interference_detection:interference_detection_algo_feature_h",
        "//software/bbe32/src:main_application_ut_lib",
        "//software/common/ipc:ipc_data_h",
        "@Dyn_alignment_module_interface//:dyn_align_wrapper_h",
        "@Static_alignment_module_interface//:static_alignment_h",
        "@appl_inclusion_dep//:afbb_include_h",
        "@appl_inclusion_dep//:spbb_include_h",
        "@bb_cfg//:afbb_cfg_h",
        "@bb_cfg//:spbb_cfg_h",
        "@emb_tracker_wrapper//:emb_tracker_wrapper_h",
        "@radar_capability_module_interface//:rc_wrapper_h",
        "@sh_module_cfg//:sh_module_cfg_h",
        "@spbb//modules/helpers:bbe_helpers_h",
        "@spbb//modules/helpers:mipi_helpers_h",
        "@spbb//modules/helpers:profiling_helpers_h",
        "@spbb//modules/helpers:ra_helpers_h",
        "@spbb//modules/helpers:sysmem_helpers_h",
        "@spbb//modules/helpers:timing_helpers_h",
        "@spbb//modules/range_process:range_proc_include_h",
    ],
)

cc_test(
    name = "main_application_unit_test",
    size = "small",
    timeout = "short",
    srcs = ["main_application_unit_test.cc"],
    copts = [
        "-Wno-pragma-pack",
        "-DUNIT_TEST",
        "-fpermissive",
    ],
    features = ["-layering_check"],
    linkstatic = True,
    target_compatible_with = ["@platforms//cpu:x86_64"],
    deps = [
        ":main_application_fake_lib",
        ":main_application_textual_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

###############################################################################
# anglefinding_project_interface
###############################################################################
cc_library(
    name = "anglefinding_project_interface_fake_lib",
    srcs = ["anglefinding_project_interface_fake.cc"],
    hdrs = ["anglefinding_project_interface_fake.h"],
    strip_include_prefix = "//software/bbe32/src/test",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:angle_finding_project_interface_h",
        "@afbb//module/_api:angle_finding_interface_h",
        "@fff",
        "@reuse",
    ],
)

cc_library(
    name = "anglefinding_project_interface_textual_lib",
    deps = [
        ":anglefinding_project_interface_fake_lib",
        "//software/bbe32/inc:angle_finding_project_interface_h",
        "//software/bbe32/inc:mem_pool_h",
        "//software/bbe32/integration_test:dsp_it_macros_test_h",
        "//software/bbe32/src:angle_finding_project_interface_ut_lib",
        "@appl_inclusion_dep//:afbb_include_h",
        "@bb_cfg//:afbb_cfg_h",
        "@reuse",
        "@spbb//modules/helpers:timing_helpers_h",
    ],
)

cc_library(
    name = "test_calibration_matrices_lib",
    testonly = True,
    srcs = ["data/test_calibration_matrices.c"],
    hdrs = ["data/test_calibration_matrices.h"],
    strip_include_prefix = "//software/bbe32/src/test/data",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "anglefinding_project_interface_unit_test",
    size = "small",
    timeout = "short",
    srcs = ["anglefinding_project_interface_unit_test.cc"],
    copts = [
        "-Wno-pragma-pack",
        "-DUNIT_TEST",
    ],
    features = ["-layering_check"],
    linkstatic = True,
    target_compatible_with = ["@platforms//cpu:x86_64"],
    deps = [
        ":anglefinding_project_interface_fake_lib",
        ":anglefinding_project_interface_textual_lib",
        ":test_calibration_matrices_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

###############################################################################
# mipi_ifc
###############################################################################
cc_library(
    name = "mipi_ifc_fake_lib",
    srcs = ["mipi_ifc_fake.cc"],
    hdrs = [
        "mipi_ifc_fake.h",
        "range_process_ifc.h",
    ],
    strip_include_prefix = "//software/bbe32/src/test",
    visibility = ["//visibility:public"],
    deps = ["@fff"],
)

cc_library(
    name = "mipi_ifc_textual_lib",
    deps = [
        ":mipi_ifc_fake_lib",
        ":xtensa_stubs",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/inc:mipi_ifc_h",
        "//software/bbe32/src:mipi_ifc_ut_lib",
        "//software/common:radar_look_types",
        "//software/common/calibrations/smc:smc_h",
        "@appl_inclusion_dep//:spbb_include_h",
        "@spbb//common:sorting_lib",
        "@spbb//modules/helpers:bbe_helpers_h",
        "@spbb//modules/helpers:mipi_helpers_h",
        "@spbb//modules/helpers:profiling_helpers_h",
        "@spbb//modules/helpers:timing_helpers_h",
    ],
)

cc_test(
    name = "mipi_ifc_unit_test",
    size = "small",
    timeout = "short",
    srcs = ["mipi_ifc_unit_test.cc"],
    copts = [
        "-Wno-pragma-pack",
        "-DUNIT_TEST",
    ],
    features = ["-layering_check"],
    linkstatic = True,
    target_compatible_with = ["@platforms//cpu:x86_64"],
    deps = [
        ":mipi_ifc_fake_lib",
        ":mipi_ifc_textual_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@spbb//common:bbe_xtensa_mock_lib",
    ],
)

###############################################################################
# test suite
###############################################################################
test_suite(
    name = "unit_tests",
    tests = [
        ":anglefinding_project_interface_unit_test",
        ":main_application_unit_test",
        ":mipi_ifc_unit_test",
    ],
    visibility = ["//visibility:public"],
)
