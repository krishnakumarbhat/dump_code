load("@rules_cc//cc:defs.bzl", "cc_library")

SH_MODULE_IMP_SRCS = [
    "sh_comm.cpp",
    "sh_core.cpp",
    "sh_error.cpp",
    "sh_init.cpp",
]

SH_MODULE_IMP_DEPS = [
    "@shbb//module/_imp/_inc:sh_module_imp_inc_h",
    "@sh_module_cfg//:sh_module_cfg_h",
    "@shbb//module/_api:sh_api_h",
    ":stream_handler",
]

cc_library(
    name = "sh_module_imp_src",
    srcs = SH_MODULE_IMP_SRCS,
    hdrs = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = SH_MODULE_IMP_DEPS +
           select({
               "@sh_module_cfg//:stream_rx_enabled": [
                   "@shbb//module/_imp/_inc:sh_init_rx_h",
               ],
               "//conditions:default": [],
           }),
)

cc_library(
    name = "stream_handler",
    srcs = ["stream_handler.cpp"],
    deps = [
        ":ENET_UDP_Driver",
        "//sil/emb_lib/timer:timer_emb_lib",
        "@shbb//module/_imp/_inc:sh_module_imp_inc_h",
    ],
)

cc_library(
    name = "udp_sil_wrapper_h",
    hdrs = ["udp_sil_wrapper.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "sh_interface_lib",
    srcs = ["sh_interface.cpp"],
    hdrs = ["sh_interface.h"],
    strip_include_prefix = ".",
    deps = [
        ":udp_sil_wrapper_h",
        "//sil/emb_lib/timer:timer_emb_lib",
        "@shbb//module/_imp/_inc:sh_module_imp_inc_h",
    ],
)

cc_library(
    name = "app_chksum",
    srcs = ["app_chksum.cpp"],
    hdrs = ["app_chksum.h"],
    strip_include_prefix = ".",
    deps = [
        "//software/common:UDPLoggingStreamHeaders",
        "@reuse",
    ],
)

cc_library(
    name = "ENET_UDP_Driver",
    srcs = ["ENET_UDP_Driver.cpp"],
    hdrs = ["ENET_UDP_Driver.h"],
    strip_include_prefix = ".",
    deps = [
        "//sil/emb_lib/sil_source/sil_engine_headers:radar_sil_output_data_h",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
        "//software/common:UDPLoggingStreamHeaders",
        "@reuse//:fixmac",
        "@shbb//module/_imp/_inc:sh_module_imp_inc_h",
    ],
)

cc_library(
    name = "udp_emblib",
    srcs = ["udp_sil_wrapper.cpp"],
    hdrs = ["udp_sil_wrapper.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":ENET_UDP_Driver",
        ":app_chksum",
        ":sh_interface_lib",
        ":sh_module_imp_src",
        ":stream_handler",
        "//sil/emb_lib/profile_timing",
        "//sil/emb_lib/sil_source/inc:sil_version_h",
        "//sil/emb_lib/sil_source/src:emblib_ipc_data",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
        "//software/common:UDPLoggingStreamHeaders",
        "//software/common:cdc_frame_interface_h",
        "//software/common/calibrations/smc:radar_sw_config_lib",
        "@reuse",
        "@shbb//module/_imp/_src:sh_module_imp_rx_src",
    ],
)
