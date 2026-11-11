load("@bazel_skylib//rules:common_settings.bzl", "bool_flag")
load("@emb_tracker_wrapper//:emb_tracker_project_profile.bzl", "EMB_TRACKER_PROJECT_PROFILE")

exports_files([
    "performance_monitor_ifc.c",
    "anglefinding_project_interface.c",
    "doppler_process_ifc.c",
    "ipc_dsp.c",
    "main_application.c",
    "mipi_ifc.c",
    "range_process_ifc.c",
])

bool_flag(
    name = "enable_chirp_timing",
    build_setting_default = True,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "chirp_timing_enable",
    flag_values = {":enable_chirp_timing": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "enable_cdc",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "cdc_enable",
    flag_values = {":enable_cdc": "true"},
    visibility = ["//visibility:public"],
)

cc_library(
    name = "main_application_lib",
    srcs = [
        "main_application.c",
    ],
    hdrs = [],
    defines = select({
        "//:Run_Feature_functions": ["FEATURE_ENABLE"],
        "//conditions:default": ["FEATURE_DISABLE"],
    }) + select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }) + EMB_TRACKER_PROJECT_PROFILE().TRACKER_ENABLED_DEFINES,
    local_defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":angle_finding_project_interface_lib",
        "@bb_cfg//:afbb_cfg_h",
        ":dopplerproc_ifc_lib",
        ":mipi_ifc_lib",
        ":rangeproc_ifc_lib",
        ":ci_stv_misalignment_lib",
        "@TOI_Char_Quality_Determination//:toi_algo_interface_h",
        "//software/bbe32/TOI_char_quality_determination/TOI_char_quality_determination/TOI_Char_Quality_Configuration:TOI_algo_interface_lib",
        "@TOI_Char_Quality_Determination//:TOI_Radar_Data_Quality_Check_lib_h",
        "//software/bbe32/adc_logging:adc_data_logging_h",
        "//software/bbe32/adc_logging:adc_data_logging_lib",
        "//software/bbe32/bbe32_static_register_validation:bbe32_static_register_validation_lib",
        "@Dyn_alignment_module_interface//:dyn_align_wrapper",
        "@interference_detection_cfg//:interference_detection_algo_feature_h",
        "@interference_detection_cfg//:interference_detection_algo_feature_lib",
        "@radar_capability_module_interface//:rc_wrapper_lib",
        "@Static_alignment_module_interface//:static_alignment",
        "//software/bbe32/inc:doppler_process_ifc_h",
        "//software/bbe32/inc:include_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/inc:mem_pool_h",
        "//software/bbe32/inc:mipi_ifc_h",
        "//software/bbe32/inc:range_process_ifc_h",
        "//software/bbe32/mpu",
        "//software/bbe32/src:ipc_dsp_lib",
        "//software/common/crc_calc:crc_calc_h",
        "//software/common/ipc:ipc_data_lib",
        "//software/bbe32/dss_ecc_parity:dss_ecc_parity",
        "@spbb//modules/doppler_process:doppler_proc_include_h",
        "@spbb//modules/doppler_process:doppler_process_module",
        "@spbb//modules/helpers:mipi_helpers_h",
        "@spbb//modules/helpers:profiling_helpers_h",
        "@spbb//modules/helpers:ra_helpers_h",
        "@spbb//modules/helpers:sysmem_helpers_h",
        "@spbb//modules/helpers:timing_helpers_h",
        "@spbb//modules/range_process:range_proc_include_h",
        "@spbb//modules/range_process:range_process_module",
        "@appl_inclusion_dep//:spbb_include_h",
        ":performance_monitor_ifc_lib",
        "//software/bbe32/bbe_self_test:fusa_bbe_self_test_lib",
        "@sh_module_cfg//:sh_module_cfg_h",
        "//software/bbe32/Ra_fault_injection:Ra_fault_injection",
    ] + select({
        "@emb_tracker_wrapper//:tracker_disabled": [],
        "//conditions:default": [
            "@emb_tracker_wrapper//:emb_tracker_wrapper",
        ],
    }) + select({
        "//:Run_Feature_functions": [
            "//software/bbe32/Cust/OLP_Wrapper:olp_wrapper_h",
            "//software/bbe32/Cust/OLP_Wrapper:olp_wrapper_lib",
            "//software/bbe32/Cust/SFL_Wrapper:sfl_headers_h",
            "//software/bbe32/Cust/SFL_Wrapper:Wrappers_lib",
            "@sfl_core_bb//:sfl_core",
        ],
        "//conditions:default": [],
    }),
)

cc_library(
    name = "get_r52_time_from_bbe32_lib",
    srcs = [
        "get_r52_time_from_bbe32.c",
    ],
    hdrs = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:get_r52_time_from_bbe32_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)

cc_library(
    name = "performance_monitor_ifc_lib",
    srcs = [
        "performance_monitor_ifc.c",
    ],
    hdrs = [],
    local_defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:performance_monitor_ifc_h",
        "@spbb//modules/helpers/imp/src/perfmon:perfmon_helpers_lib",
    ],
)

cc_library(
    name = "performance_monitor_ifc_ut_lib",
    srcs = [],
    hdrs = ["performance_monitor_ifc.c"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:performance_monitor_ifc_h",
        "@spbb//modules/helpers/imp/src/perfmon:perfmon_helpers_ut_lib",
    ],
)

cc_library(
    name = "angle_finding_project_interface_lib",
    srcs = ["anglefinding_project_interface.c"],
    hdrs = [],
    defines = [] + select(
        {
            "@build_config//:flr8": ["FLR8"],
            "@build_config//:srr8p": ["SRR8P"],
        },
    ),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":bb_angle_finding_module_lib",
        "//software/bbe32/integration_test:dsp_it_macros_test_h",
        "//software/common/ipc:ipc_data_h",
        "@Gen8_iND13400//software/bbe32/inc:angle_finding_project_interface_h",
        "@appl_inclusion_dep//:afbb_include_h",
        "@bb_cfg//:afbb_cfg_h",
        "@reuse",
        "@reuse//:fixmac",
        "@spbb//modules/helpers:timing_helpers_h",
    ],
)

cc_library(
    name = "bb_angle_finding_module_lib",
    srcs = [],
    hdrs = [],
    defines = [],
    visibility = ["//visibility:public"],
    deps = [] +
           select({
               "@build_config//:flr8": [
                   "@afbb//module:flr8_angle_finding_module_lib",
               ],
               "@build_config//:srr8p": [
                   "@afbb//module:srr8p_angle_finding_module_lib",
               ],
           }),
)

cc_library(
    name = "rangeproc_ifc_lib",
    srcs = [
        "range_process_ifc.c",
    ],
    hdrs = [],
    local_defines = select({
        ":chirp_timing_enable": ["ENABLE_CHIRP_PROFILING_INFO"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":mipi_ifc_lib",
        "//software/bbe32/adc_logging:adc_data_logging_h",
        "//software/bbe32/adc_logging:adc_data_logging_lib",
        "//software/bbe32/dss_ecc_parity",
        "//software/bbe32/inc:include_h",
        "//software/bbe32/inc:mipi_ifc_h",
        "//software/bbe32/inc:range_process_ifc_h",
        "//software/bbe32/mpu",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/ipc:ipc_data_h",
        "//software/common/ipc:ipc_data_lib",
        "@appl_inclusion_dep//:spbb_include_h",
        "@spbb//modules/helpers:mipi_helpers_h",
        "@spbb//modules/helpers:profiling_helpers_h",
        "@spbb//modules/helpers:timing_helpers_h",
        "@spbb//modules/helpers/imp:mipi_helpers_lib",
        "@spbb//modules/range_process:range_proc_include_h",
        "@spbb//modules/range_process:range_process_module",
    ],
)

cc_library(
    name = "dopplerproc_ifc_lib",
    srcs = [
        "doppler_process_ifc.c",
    ],
    hdrs = [],
    local_defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ci_stv_misalignment_h",
        "//software/bbe32/inc:doppler_process_ifc_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/inc:mem_pool_h",
        "//software/bbe32/inc:range_process_ifc_h",
        "//software/bbe32/integration_test:dsp_it_macros_test_h",
        "//software/bbe32/rdd_proc/imp/src:appl_cfar_ifc_lib",
        "//software/bbe32/rdd_proc/imp/src:appl_fp_ifc_lib",
        "//software/bbe32/rdd_proc/imp/src:appl_sp_ifc_lib",
        "//software/bbe32/rdd_proc/imp/src:appl_sweepbw_ifc_lib",
        "//software/common:rdd_stream_h",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
        "@appl_inclusion_dep//:spbb_include_h",
        "@spbb//modules/doppler_process:doppler_proc_include_h",
        "@spbb//modules/doppler_process:doppler_process_module",
        "@spbb//modules/doppler_process/imp/src:transpose_nci_lib",
        "@spbb//modules/rdd_first_pass_process/imp/src:rdd_fp_interface_lib",
        "@spbb//modules/second_pass/imp/src/bbe:second_pass_lib",
        "@spbb//modules/sweep_bw/imp/src:sweep_bw_lib",
    ],
)

cc_library(
    name = "dopplerproc_ifc_ut_lib",
    srcs = [],
    hdrs = ["doppler_process_ifc.c"],
    local_defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_library(
    name = "rangeproc_ifc_ut_lib",
    srcs = [],
    hdrs = ["range_process_ifc.c"],
    local_defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/dss_ecc_parity:dss_ecc_parity_h",
    ],
)

cc_library(
    name = "ci_stv_misalignment_lib",
    srcs = ["ci_stv_misalignment.c"],
    hdrs = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ci_stv_misalignment_h",
        "@spbb//common:common_lib",
    ],
)

cc_library(
    name = "ci_stv_misalignment_ut_lib",
    hdrs = ["ci_stv_misalignment.c"],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ci_stv_misalignment_h",
    ],
)

cc_library(
    name = "ipc_dsp_lib",
    srcs = [
        "ipc_dsp.c",
    ],
    hdrs = [],
    local_defines = select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":mipi_ifc_lib",
        "//software/bbe32/bbe32_static_register_validation:bbe32_static_register_validation_lib",
        "//software/bbe32/inc:cdc_packing_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/inc:mipi_ifc_h",
        "//software/bbe32/inc:range_process_ifc_h",
        "//software/bbe32/integration_test:dsp_it_macros_test_h",
        "//software/common/calibrations/smc:radar_sw_config_h",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
        "//software/common/ipc:ipc_data_h",
        "//software/common/mmic:mmic_common_types_h",
        "@TOI_Char_Quality_Determination//:TOI_Char_Quality_determination_lib",
        "@TOI_Char_Quality_Determination//:toi_algo_interface_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
        "@reuse",
        "@spbb//modules/helpers:bbe_helpers_h",
        "@spbb//modules/helpers:idma_lib",
    ],
)

cc_library(
    name = "mipi_ifc_lib",
    srcs = [
        "mipi_ifc.c",
    ],
    hdrs = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:include_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/inc:mipi_ifc_h",
        "//software/bbe32/inc:range_process_ifc_h",
        "//software/bbe32/mpu",
        "//software/common:radar_look_types",
        "//software/common/calibrations/smc:smc_h",
        "@appl_inclusion_dep//:spbb_include_h",
        "@spbb//common:sorting_lib",
        "@spbb//modules/helpers:mipi_helpers_h",
        "@spbb//modules/helpers:profiling_helpers_h",
        "@spbb//modules/helpers:timing_helpers_h",
        "@spbb//modules/helpers/imp:mipi_helpers_lib",
    ],
)

cc_library(
    name = "cdc_packing_lib",
    srcs = [
        "cdc_packing.c",
    ],
    hdrs = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":cdc_priority_lib",
        "//software/bbe32/inc:cdc_packing_h",
        "//software/bbe32/inc:doppler_process_ifc_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/inc:mem_pool_h",
        "//software/bbe32/rdd_proc/api:appl_fp_ifc_h",
        "//software/common:cdc_stream_h",
        "//software/common:rdd_stream_h",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/ipc:ipc_data_h",
        "@Gen8_iND13400//software/common/calibrations/smc:radar_sw_config_lib",
        "@spbb//modules/doppler_process:doppler_proc_include_h",
        "@spbb//modules/helpers:bbe_helpers_h",
        "@spbb//modules/helpers:timing_helpers_h",
        "@spbb//modules/helpers/imp:sysmem_helpers_lib",
        "@spbb//modules/rdd_first_pass_process:rdd_fp_include_h",
        "@spbb//modules/rdd_first_pass_process/imp/src:rdd_fp_detection_lib",
    ],
)

cc_library(
    name = "cdc_packing_ut_lib",
    hdrs = [
        "cdc_packing.c",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = ["@spbb//modules/helpers:bbe_helpers_h"],
)

cc_library(
    name = "ipc_dsp_ut_lib",
    hdrs = ["ipc_dsp.c"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:include_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/bbe32/integration_test:dsp_it_macros_test_h",
    ],
)

cc_library(
    name = "main_application_ut_lib",
    hdrs = ["main_application.c"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:include_h",
        "@TOI_Char_Quality_Determination//:toi_algo_interface_h",
        "@sh_module_cfg//:sh_module_cfg_h",
    ],
)

cc_library(
    name = "angle_finding_project_interface_ut_lib",
    hdrs = ["anglefinding_project_interface.c"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/integration_test:dsp_it_macros_test_h",
        "//software/common/ipc:ipc_data_h",
        "@Gen8_iND13400//software/bbe32/inc:angle_finding_project_interface_h",
        "@reuse",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "mipi_ifc_ut_lib",
    hdrs = ["mipi_ifc.c"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = ["//software/bbe32/inc:mipi_ifc_h"],
)

# A-PRISM track-conditioned residual estimators (N14/N23). Self-contained.
cc_library(
    name = "residual_track_ifc_lib",
    srcs = ["residual_track_ifc.c"],
    hdrs = ["residual_track_ifc.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [],
)

# A-PRISM priority-ranked CDC packing (F5 mitigation). Self-contained.
cc_library(
    name = "cdc_priority_lib",
    srcs = ["cdc_priority.c"],
    hdrs = ["cdc_priority.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [],
)
