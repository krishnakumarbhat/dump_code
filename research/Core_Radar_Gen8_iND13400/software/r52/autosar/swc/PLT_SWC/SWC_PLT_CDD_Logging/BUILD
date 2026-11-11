load("@rules_cc//cc:defs.bzl", "cc_library")
load("@bazel_skylib//rules:common_settings.bzl", "bool_flag")
load("@emb_tracker_wrapper//:emb_tracker_project_profile.bzl", "EMB_TRACKER_PROJECT_PROFILE")

exports_files(
    [
        "Source/SWC_PLT_CDD_Logging.c",
    ],
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "enable_multicast_log_tx",
    build_setting_default = False,
    visibility = ["//:__pkg__"],
)

config_setting(
    name = "multicast_log_tx",
    flag_values = {":enable_multicast_log_tx": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "disable_all_logging_streams_tx",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "all_logging_streams_tx_disable",
    flag_values = {":disable_all_logging_streams_tx": "true"},
    visibility = ["//visibility:public"],
)

bool_flag(
    name = "disable_udp_logging_streams_tx",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "udp_logging_streams_tx_disable",
    flag_values = {":disable_udp_logging_streams_tx": "true"},
    visibility = ["//visibility:public"],
)

cc_library(
    name = "SWC_PLT_CDD_LOGGING_h",
    srcs = [],
    hdrs = ["Include/SWC_PLT_CDD_Logging.h"],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:UDPLoggingStreamHeaders",
        "@shbb//module/_api:sh_api_h",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_Logging",
    srcs = [
        "Source/SWC_PLT_CDD_Logging.c",
    ],
    hdrs = [],
    copts = ["-Wno-pragma-pack"],  # JH: Added to get rid of build error in Os_MemMap_Stacks.h
    defines = select({
        #        "//software/app/dss/src:tdc_enable": [
        #            "TDC_ENABLE",
        #        ],
        #        "//conditions:default": [],
        #    }) + select({
        #        "//software/app/dss/src:cdc_enable": [
        #            "CDC_ENABLE",
        #        ],
        #        "//conditions:default": [],
        #    }) + select({
        ":multicast_log_tx": [
            "MULTICAST_LOG_TX_ENABLE",
        ],
        "//conditions:default": [],
        #    }) + select({
        #        "@spbb//range_process_module:dss_adc_streaming_enabled": [
        #            "ADC_STREAMING_ENABLE",
        #        ],
        #        "//conditions:default": [],
    }) + select({
        "//software/r52/r52_stack:stack_monitor_disable_r52": [
            "DISBLE_STACK_MONITOR_R52",
        ],
        "//conditions:default": [],
    }) + select({
        "//software/bbe32/src:cdc_enable": ["CDC_ENABLE"],
        "//conditions:default": [],
    }) + EMB_TRACKER_PROJECT_PROFILE().TRACKER_ENABLED_DEFINES + EMB_TRACKER_PROJECT_PROFILE().TRACKER_VARIANT_DEFINES + select({
        "//:Run_Feature_functions": ["FEATURE_ENABLE"],
        "//conditions:default": [],
    }) + select({
        ":all_logging_streams_tx_disable": ["ALL_LOGGING_STREAMS_TX_DISABLE"],
        ":udp_logging_streams_tx_disable": ["UDP_LOGGING_STREAMS_TX_DISABLE"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:UDPLoggingStreamHeaders",
        "//software/common:cdc_frame_interface_h",
        "//software/common:cdc_stream_h",
        "//software/common/ipc:ipc_data_h",
        "//software/common/ipc:ipc_data_lib",
        "//software/common/versions",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IoHwAb:SWC_PLT_Appl_IoHwAb_Cfg_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:PLT_Appl_PlatformTime_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync:SWC_PLT_CDD_ECUSync_external_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ExternalWdg:dd_pmic_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging:SWC_PLT_CDD_LOGGING_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb:SWC_PLT_Appl_XCP_H",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/dsp_setup:dsp_setup_h",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/ipc:ipc_mss_lib",
        "//software/r52/mmic:mmic_h",
        "//software/r52/r52_stack:stack_monitor_r52_h",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging/SH:sh_interface_lib",
        "@Sensor_Position//:sensor_position_h",
        "@dabb//module/dyn_alignment/dyn_alignment_api:dynamic_alignment_stream_header",
        "@hilbb//module/_api:hil_communication_handler_h",
        "@hilbb//module/_api:hil_types_h",
        "@iND13400_autosar_sip//Components/EthTrcv_30_Rtl9010:EthTrcv_30_Rtl9010_h",
        "@iND13400_autosar_sip//Components/EthTrcv_30_Tja1103:EthTrcv_30_Tja1103_h",
        "@iND13400_autosar_sip//Components/Eth_30_Wrapper:Eth_30_Wrapper_h",
        "@iND13400_autosar_sip//Components/SoAd",
        "@iND13400_autosar_sip//Components/Xcp",
        "@idbb//module/id_imp/_inc:id_stream_header",
        "@reuse",
        "@sabb//module/static_alignment/static_alignment_api:static_alignment_stream_header",
        "@sh_module_cfg//:sh_module_cfg_h",
        "@shbb//module/_api:sh_api_h",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_Logging_source_support_lib",
    srcs = [],
    hdrs = [
        "Source/SWC_PLT_CDD_Logging.c",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
)
