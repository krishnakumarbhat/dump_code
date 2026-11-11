load("@emb_tracker_wrapper//:emb_tracker_project_profile.bzl", "EMB_TRACKER_PROJECT_PROFILE")

exports_files(
    [
        "someip_services.c",
        "someip_services.h",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "someip_services_h",
    srcs = [
    ],
    hdrs = [
        "someip_services.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/someip/",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/ipc:ipc_data_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/can:can_tx_h",
    ],
)

cc_library(
    name = "someip_services",
    srcs = [
        "someip_services.c",
    ],
    hdrs = [],
    copts = [
    ],
    defines = EMB_TRACKER_PROJECT_PROFILE().TRACKER_MODE_DEFINES,
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/someip/",
    visibility = ["//visibility:public"],
    deps = [
        ":someip_services_h",
        "//software/common/calibrations/smc:radar_sw_config_h",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
        "//software/common/versions",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync:SWC_PLT_CDD_ECUSync_external_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb:SWC_PLT_Appl_XCP_H",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler:SWC_PLT_Radar_Alignment_Handler_h",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/mmic:mmic_h",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging:SWC_PLT_CDD_LOGGING_h",
        "@Sensor_Position//:sensor_position_h",
        "@reuse",
    ],
)

cc_library(
    name = "someip_services_test_lib",
    srcs = [
    ],
    hdrs = [
        "someip_services.c",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication/someip/",
    visibility = ["//visibility:public"],
    deps = [
        ":someip_services_h",
        "//software/common/ipc:ipc_data_h",
    ],
)
