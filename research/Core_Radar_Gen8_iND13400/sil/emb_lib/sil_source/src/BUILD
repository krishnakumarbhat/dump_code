load("@rules_cc//cc:defs.bzl", "cc_library")
load("@bazel_skylib//rules:common_settings.bzl", "string_flag")

cc_library(
    name = "sil_wrapper_common",
    srcs = ["sil_wrapper_common.cpp"],
    hdrs = ["sil_wrapper_common.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/emb_lib/sil_source/sil_engine_headers:radar_position_h",
        "//sil/emb_lib/sil_source/sil_engine_headers:radar_sil_input_data_h",
        "//sil/emb_lib/sil_source/sil_engine_headers:radar_sil_output_data_h",
        "//sil/emb_lib/sil_source/sil_engine_headers:rr_adas_symbol_h",
        "//sil/emb_lib/sil_source/sil_engine_headers:sil_input_symbol_h",
        "//sil/emb_lib/sil_source/sil_engine_headers:sil_output_symbol_h",
        "//sil/emb_lib/streams:cdc_stream_combined_h",
        "//software/common:UDPLoggingStreamHeaders",
    ],
)

cc_library(
    name = "emblib_ipc_data",
    srcs = ["emblib_ipc_data.cpp"],
    hdrs = ["emblib_ipc_data.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/ipc:ipc_data_h",
    ],
)

cc_library(
    name = "sil_symbol_wrapper",
    srcs = [
        "sil_radar_fusion_delay.cpp",
        "sil_radar_fusion_delay.h",
        "sil_symbol_wrapper.cpp",
        "sil_symbol_wrapper_internal.h",
    ],
    hdrs = ["sil_symbol_wrapper.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":emblib_ipc_data",
        "//sil/emb_lib/sil_source/sil_engine_headers:radar_position_h",
        "//sil/emb_lib/sil_source/sil_engine_headers:radar_sil_input_data_h",
        "//sil/emb_lib/sil_source/sil_engine_headers:radar_sil_output_data_h",
        "//sil/emb_lib/sil_source/sil_engine_headers:rr_adas_symbol_h",
        "//sil/emb_lib/sil_source/sil_engine_headers:sil_input_symbol_h",
        "//sil/emb_lib/sil_source/sil_engine_headers:sil_output_symbol_h",
        "//sil/emb_lib/sil_source/src/event_logger/statistical_report",
        "//sil/emb_lib/streams:cdc_stream_combined_h",
        "//software/common:UDPLoggingStreamHeaders",
    ],
)

cc_library(
    name = "sil_stream_wrapper",
    srcs = ["sil_stream_wrapper.cpp"],
    hdrs = ["sil_stream_wrapper.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":emblib_ipc_data",
        ":sil_wrapper_common",
        "//sil/emb_lib/sil_source/inc:sil_macros_time",
        "//sil/emb_lib/sil_source/sil_engine_headers:sil_input_symbol_h",
        "//sil/emb_lib/sil_source/src/event_logger/statistical_report",
        "//sil/emb_lib/streams:cdc_stream_combined_h",
        "//software/common:UDPLoggingStreamHeaders",
    ],
)

# Define string flags
string_flag(
    name = "customer",
    build_setting_default = "gpo",
    values = [
        "gpo",
        "al",
    ],
    visibility = ["//visibility:public"],
)

string_flag(
    name = "dbc_version",
    build_setting_default = "v1.1",
    values = [
        "v1.1",
    ],
    visibility = ["//visibility:public"],
)

# Config settings for individual flags
config_setting(
    name = "gpo",
    flag_values = {":customer": "gpo"},
)

config_setting(
    name = "al",
    flag_values = {":customer": "al"},
)

config_setting(
    name = "v1_1",
    flag_values = {":dbc_version": "v1.1"},
)

config_setting(
    name = "al_v1_1",
    flag_values = {
        ":customer": "al",
        ":dbc_version": "v1.1",
    },
)
