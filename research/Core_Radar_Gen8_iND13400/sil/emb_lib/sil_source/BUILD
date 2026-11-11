load("@bazel_platform//toolchains/mingw:dll_interface_library.bzl", "dll_interface_library")
load("@bazel_skylib//rules:common_settings.bzl", "string_flag")

exports_files(
    [
        "sil_wrapper.h",
    ],
    visibility = ["//visibility:public"],
)

sil_wrapper_deps = [
    "//software/common:UDPLoggingStreamHeaders",
    "//sil/emb_lib/profile_timing",
    "//sil/emb_lib/ff_emb_lib/customer:ff_emb_lib",
    "//sil/emb_lib/rsp_emb_lib",
    "//sil/emb_lib/sil_source/customer:customer_sil_wrapper",
    "//sil/emb_lib/sil_source/inc:sil_macros_time",
    "//sil/emb_lib/sil_source/inc:sil_version_h",
    "//sil/emb_lib/sil_source/sil_engine_headers:radar_sil_version_h",
    "//sil/emb_lib/sil_source/sil_engine_headers:resim_config_h",
    "//sil/emb_lib/sil_source/sil_engine_headers:sil_input_symbol_h",
    "//sil/emb_lib/sil_source/sil_engine_headers:sil_output_symbol_h",
    "//sil/emb_lib/sil_source/src/event_logger:enable_debugging",
    "//sil/emb_lib/sil_source/src/event_logger:output_control",
    "//sil/emb_lib/sil_source/src:emblib_ipc_data",
    "//sil/emb_lib/sil_source/src:sil_stream_wrapper",
    "//sil/emb_lib/sil_source/src:sil_wrapper_common",
    "//sil/emb_lib/sil_source/src:sil_symbol_wrapper",
    "//sil/emb_lib/sil_source/src/internals_data:alignment_internals_data",
    "//sil/emb_lib/sil_source/src/event_logger/statistical_report",
    "//sil/emb_lib/tracker_emb_lib",
    "//sil/emb_lib/udp:udp_emblib",
    "//sil/emb_lib/plp_sync:plp",
    "//sil/emb_lib/vse:vse_sil_wrapper",
    "//sil/emb_lib/can:can",
    "@pugixml",
]

cc_library(
    name = "emb_lib_static",
    srcs = ["sil_wrapper.cpp"],
    hdrs = ["sil_wrapper.h"],
    defines = ["EMB_LIB_SIL_WRAPPER_STATIC"],
    strip_include_prefix = "//sil/emb_lib/sil_source",
    visibility = ["//visibility:public"],
    deps = sil_wrapper_deps,
)

cc_library(
    name = "emb_lib_shared",
    srcs = ["sil_wrapper.cpp"],
    hdrs = ["sil_wrapper.h"],
    defines = select({
        "@platforms//os:windows": ["EMB_LIB_SIL_WRAPPER_SHARED_EXPORT"],
        "@platforms//os:linux": [],
    }),
    strip_include_prefix = "//sil/emb_lib/sil_source",
    visibility = ["//visibility:public"],
    deps = sil_wrapper_deps,
)

cc_shared_library(
    name = "emb_lib_sharedlib",
    visibility = ["//visibility:public"],
    deps = [":emb_lib_shared"],
)

dll_interface_library(
    name = "emb_lib_interfacelib",
    cc_shared_library = ":emb_lib_sharedlib",
    dlltool = "@mingw//:bin/dlltool.exe",
    gendef = "@mingw//:bin/gendef.exe",
)

# # Define string flags
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
    build_setting_default = "v3.0",
    values = [
        "v3.0",
        "v2.0",
        "v1.1",
    ],
    visibility = ["//visibility:public"],
)

# # Config settings for individual flags
config_setting(
    name = "gpo",
    flag_values = {":customer": "gpo"},
)

config_setting(
    name = "al",
    flag_values = {":customer": "al"},
)

config_setting(
    name = "v2_0",
    flag_values = {":dbc_version": "v2.0"},
)

config_setting(
    name = "v3_0",
    flag_values = {":dbc_version": "v3.0"},
)

config_setting(
    name = "v1_1",
    flag_values = {":dbc_version": "v1.1"},
)

# Combined config settings
config_setting(
    name = "gpo_v3_0",
    flag_values = {
        ":customer": "gpo",
        ":dbc_version": "v3.0",
    },
)

config_setting(
    name = "gpo_v2_0",
    flag_values = {
        ":customer": "gpo",
        ":dbc_version": "v2.0",
    },
)

config_setting(
    name = "al_v1_1",
    flag_values = {
        ":customer": "al",
        ":dbc_version": "v1.1",
    },
)
