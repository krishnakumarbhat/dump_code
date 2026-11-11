cc_library(
    name = "radar_ctl_h",
    srcs = [],
    hdrs = [
        "bb_radar_ctl_api/radar_ctl.h",
        "bb_radar_ctl_api/radar_data.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/bb_radar_ctl/bb_radar_ctl_api",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:radar_look_types",
        "//software/r52/autosar/config/Appl/GenData:Rte_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "@reuse",
    ],
)

cc_library(
    name = "radar_data_ut_lib",
    hdrs = ["bb_radar_ctl_imp/radar_data.c"],
    strip_include_prefix = "bb_radar_ctl_imp",
    visibility = ["//visibility:public"],
    deps = [":radar_ctl_h"],
)

cc_library(
    name = "radar_look_h",
    srcs = [],
    hdrs = [
        "bb_radar_ctl_imp/radar_look.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/bb_radar_ctl/bb_radar_ctl_imp",
    visibility = ["//visibility:public"],
    deps = [
        "@reuse",
    ],
)

cc_library(
    name = "radar_ctl_module",
    srcs = [
        "bb_radar_ctl_imp/radar_ctl.c",
        "bb_radar_ctl_imp/radar_data.c",
        "bb_radar_ctl_imp/radar_look.c",
    ],
    hdrs = [
        "bb_radar_ctl_imp/radar_look.h",
    ],
    strip_include_prefix = "//software/r52/bb_radar_ctl/bb_radar_ctl_imp",
    visibility = ["//visibility:public"],
    deps = [
        ":radar_ctl_h",
        "//software/common:UDPLoggingStreamHeaders",
        "//software/common/mmic:mmic_common_types_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:PLT_Appl_PlatformTime_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync:SWC_PLT_CDD_ECUSync_external_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb:SWC_PLT_Appl_XCP_H",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/mmic:mmic_h",
    ],
)

cc_library(
    name = "radar_ctl_unit_test_support_lib",
    hdrs = [
        "bb_radar_ctl_imp/radar_ctl.c",
        "bb_radar_ctl_imp/radar_look.h",
    ],
    strip_include_prefix = "//software/r52/bb_radar_ctl",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/mmic:mmic_common_types_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime/test:swc_platformtime_fakes",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync:SWC_PLT_CDD_ECUSync_external_h",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/bb_radar_ctl/bb_radar_ctl_imp/test/mocks:radar_ctl_fake_lib",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/mmic:mmic_h",
        "//software/r52/mmic/drivers/mipi_csi2:mipi_csi2_unit_test_support_lib",
    ],
)

cc_library(
    name = "radar_look_unit_test_support_lib",
    hdrs = [
        "bb_radar_ctl_imp/radar_look.c",
        "bb_radar_ctl_imp/radar_look.h",
    ],
    strip_include_prefix = "//software/r52/bb_radar_ctl",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/mmic:mmic_common_types_h",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/bb_radar_ctl/bb_radar_ctl_imp/test/mocks:radar_data_fake_lib",
        "//software/r52/bb_radar_ctl/bb_radar_ctl_imp/test/mocks:radar_look_fake_lib",
        "//software/r52/mmic:mmic_h",
        "//software/r52/mmic/test/mocks:dd_mmic_fake_lib",
    ],
)
