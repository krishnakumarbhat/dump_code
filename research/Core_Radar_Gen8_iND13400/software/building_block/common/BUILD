load("@bazel_skylib//rules:common_settings.bzl", "bool_flag")
load("@emb_tracker_wrapper//:emb_tracker_project_profile.bzl", "EMB_TRACKER_PROJECT_PROFILE")

# Embedded library
# -------------------------------------------------------------------------------------------------
cc_library(
    name = "spbb_include_h",
    hdrs = [
        "spbb_include.h",
        "spbb_memmap.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common:radar_look_types",
        "@Gen8_iND13400//software/common:rdd_debug_stream_h",
        "@Gen8_iND13400//software/common:rdd_stream_h",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "afbb_include_h",
    hdrs = [
        "afbb_include.h",
        "afbb_memmap.h",
    ],
    defines = select({
        "@Gen8_iND13400//software/r52:b0_board": ["CHANDRA_B0"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Calibration_Handler//:calibration_h",
        "@Gen8_iND13400//software/bbe32/inc:mem_pool_h",
        "@Gen8_iND13400//software/common:UDPLoggingStreamHeaders",
        "@Gen8_iND13400//software/common:radar_look_types",
        "@Gen8_iND13400//software/common/calibrations/smc:smc_h",
        "@Gen8_iND13400//software/common/calibrations/usc:usc_h",
        "@bb_cfg//:afbb_cfg_h",
        "@reuse",
        "@reuse//:fixmac",
        "@rm//module/radar_math:radar_math_types_h",
    ],
)

cc_library(
    name = "idbb_include_h",
    hdrs = [
        "idbb_include.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common:UDPLoggingStreamHeaders",
        "@Gen8_iND13400//software/common/calibrations/smc:smc_h",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@rm//module/radar_math:radar_math_lib",
    ],
)

cc_library(
    name = "dabb_include_h",
    hdrs = [
        "dabb_include.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common/calibrations/smc:smc_h",
    ],
)

cc_library(
    name = "hilbb_include_h",
    hdrs = [
        "hilbb_include.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common:UDPLoggingStreamHeaders",
        "@Gen8_iND13400//software/common:rdd_stream_h",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
        "@reuse",
        "@reuse//:fixmac",
        "@sh_module_cfg//:sh_module_cfg_h",
        "@shbb//module/_api:sh_api_h",
    ],
)

cc_library(
    name = "sh_bb_include_h",
    hdrs = [
        "sh_bb_include.h",
    ],
    defines = select({
        "@Gen8_iND13400//:Run_Feature_functions": ["FEATURE_ENABLE"],
        "//conditions:default": [],
    }) + EMB_TRACKER_PROJECT_PROFILE().TRACKER_ENABLED_DEFINES + select({
        "@sh_module_cfg//:stream_rx_enabled": ["STREAM_RX_ENABLE"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common:UDPLoggingStreamHeaders",
        "@Gen8_iND13400//software/common:radar_look_types",
        "@Gen8_iND13400//software/common:rdd_stream_h",
        "@Gen8_iND13400//software/common:stream_header_h",
        "@Gen8_iND13400//software/common:toi_ds_stream_h",
        "@Gen8_iND13400//software/common:toi_stream_h",
        "@Gen8_iND13400//software/common/calib_cfg:calibration_handler_cfg",
        "@Gen8_iND13400//software/common/calibrations/smc:radar_sw_config_h",
        "@Gen8_iND13400//software/common/calibrations/smc:smc_h",
        "@Gen8_iND13400//software/common/calibrations/usc:usc_h",
        "@bb_cfg//:afbb_cfg_h",
        "@bb_cfg//:spbb_cfg_h",
        "@dabb//module/dyn_alignment/dyn_alignment_api:dyn_align_module_h",
        "@idbb//module/id_imp/_inc:id_stream_header",
        "@rcbb//module/common:rc_stream_headers",
        "@reuse",
        "@rotbb//emb_tracker:emb_tracker_interface_h",
        "@sabb//module/static_alignment/static_alignment_api:static_alignment_stream_header",
    ],
)

bool_flag(
    name = "enable_psp_sil",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "enable_bench_testing",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "enable_id_testing",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "rc_test_stub_data",
    flag_values = {":enable_bench_testing": "true"},
    visibility = ["//visibility:public"],
)

config_setting(
    name = "psp_sil_enable",
    flag_values = {":enable_psp_sil": "True"},
    visibility = ["//visibility:public"],
)

config_setting(
    name = "enable_testing_id",
    flag_values = {":enable_id_testing": "True"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "enable_v1",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "enable_gen8",
    build_setting_default = True,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "gen8",
    flag_values = {"@appl_inclusion_dep//:enable_gen8": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "alignment_nvm_test",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "alignment_nvm_fail_test",
    flag_values = {"@appl_inclusion_dep//:alignment_nvm_test": "true"},
    visibility = ["//visibility:public"],
)

# Variant config_settings for compatibility with external dependencies (RCBB module)
config_setting(
    name = "flr7",
    flag_values = {
        "@build_config//:variant": "flr7",
    },
    visibility = ["//visibility:public"],
)

config_setting(
    name = "srr7p",
    flag_values = {
        "@build_config//:variant": "srr7p",
    },
    visibility = ["//visibility:public"],
)

config_setting(
    name = "srr7hd",
    flag_values = {
        "@build_config//:variant": "srr7hd",
    },
    visibility = ["//visibility:public"],
)

config_setting(
    name = "flr8",
    flag_values = {
        "@build_config//:variant": "flr8",
    },
    visibility = ["//visibility:public"],
)

config_setting(
    name = "srr8p",
    flag_values = {
        "@build_config//:variant": "srr8p",
    },
    visibility = ["//visibility:public"],
)

cc_library(
    name = "rcbb_include_h",
    hdrs = [
        "rcbb_include.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common:UDPLoggingStreamHeaders",
        "@Gen8_iND13400//software/common/calibrations/smc:radar_sw_config_h",
        "@Gen8_iND13400//software/common/calibrations/smc:smc_h",
        "@Gen8_iND13400//software/common/calibrations/usc:usc_h",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync:SWC_PLT_CDD_ECUSync_external_h",
        "@dabb//module/dyn_alignment/dyn_alignment_api:dyn_align_module_h",
        "@reuse//:fixmac",
    ],
)

# Interference Detection flags
bool_flag(
    name = "id_enable_gen8",
    build_setting_default = True,
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "rbin_scaling_enabled",
    build_setting_default = True,
    visibility = ["//visibility:public"],
)
