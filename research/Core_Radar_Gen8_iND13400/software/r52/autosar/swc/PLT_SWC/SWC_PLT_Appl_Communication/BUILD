load("@rules_cc//cc:defs.bzl", "cc_library")
load("@bazel_skylib//rules:common_settings.bzl", "string_flag")
load("@bazel_skylib//lib:selects.bzl", "selects")
load("@emb_tracker_wrapper//:emb_tracker_project_profile.bzl", "EMB_TRACKER_PROJECT_PROFILE")

# Export source files for testing
exports_files([
    "Source/SWC_PLT_Appl_Communication.c",
])

string_flag(
    name = "veh_com",
    build_setting_default = "can",
    values = [
        "can",
        "someip",
        "al_can_standalone",
        "can_standalone",
    ],
    visibility = ["//visibility:public"],
)

config_setting(
    name = "VEH_TRACKER",
    flag_values = {":veh_com": "can_standalone"},
)

config_setting(
    name = "VEH_SOMEIP",
    flag_values = {":veh_com": "someip"},
)

config_setting(
    name = "VEH_CAN_only",
    flag_values = {":veh_com": "can"},
)

config_setting(
    name = "VEH_AL_CAN_STANDALONE",
    flag_values = {":veh_com": "al_can_standalone"},
)

selects.config_setting_group(
    name = "VEH_CAN",
    match_any = [
        ":VEH_CAN_only",
        ":VEH_AL_CAN_STANDALONE",
    ],
)

config_setting(
    name = "flr8_can",
    flag_values = {
        "@build_config//:variant": "flr8",
        ":veh_com": "can",
    },
)

config_setting(
    name = "flr8_someip",
    flag_values = {
        "@build_config//:variant": "flr8",
        ":veh_com": "someip",
    },
)

config_setting(
    name = "flr8_standalone",
    flag_values = {
        "@build_config//:variant": "flr8",
        ":veh_com": "can_standalone",
    },
)

config_setting(
    name = "srr8p_can",
    flag_values = {
        "@build_config//:variant": "srr8p",
        ":veh_com": "can",
    },
)

config_setting(
    name = "srr8p_someip",
    flag_values = {
        "@build_config//:variant": "srr8p",
        ":veh_com": "someip",
    },
)

config_setting(
    name = "srr8p_standalone",
    flag_values = {
        "@build_config//:variant": "srr8p",
        ":veh_com": "can_standalone",
    },
)

config_setting(
    name = "srr8p_al_can_standalone",
    flag_values = {
        "@build_config//:variant": "srr8p",
        ":veh_com": "al_can_standalone",
    },
)

cc_library(
    name = "SWC_PLT_Appl_Communication",
    srcs = [
        "Source/SWC_PLT_Appl_Communication.c",
    ],
    hdrs = [],
    defines = select({
        ":VEH_SOMEIP": [
            "VEH_SOMEIP",
        ],
        ":VEH_TRACKER": [
            "VEH_TRACKER",
        ],
        ":VEH_AL_CAN_STANDALONE": [
            "VEH_CAN",
            "VEH_AL_CAN_STANDALONE",
            "AL_CAN_TSYNCH_DEFAULT",
        ],
        "//conditions:default": [
            "VEH_CAN",
        ],
    }) + EMB_TRACKER_PROJECT_PROFILE().TRACKER_ENABLED_DEFINES + select({
        "//:Run_Feature_functions": ["FEATURE_ENABLE"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/can:can_tx",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/someip:someip_services",
        "@iND13400_autosar_sip//Components/Can:Can_h",
        "@iND13400_autosar_sip//Components/CanSM:CanSM_h",
        "@iND13400_autosar_sip//Components/Com:Com_h",
        "@iND13400_autosar_sip//Components/ComM:ComM_h",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:PLT_Appl_PlatformTime_h",
    ] + select({
        "//:Run_Feature_functions": ["//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/can:can_tx_al"],
        "//conditions:default": [],
    }),
)

cc_library(
    name = "SWC_PLT_Appl_Communication_source_support_lib",
    srcs = [],
    hdrs = [
        "Source/SWC_PLT_Appl_Communication.c",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)
