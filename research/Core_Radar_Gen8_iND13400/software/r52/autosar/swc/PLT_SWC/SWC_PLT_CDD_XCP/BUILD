load("@rules_cc//cc:defs.bzl", "cc_library")

exports_files(
    [
        "Source/xcp_logging.c",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "SWC_PLT_CDD_XCP",
    srcs = [
        "Source/SWC_PLT_CDD_XCP.c",
        "Source/XcpAppl.c",
        "Source/xcp_logging.c",
    ],
    hdrs = [],
    defines = [],
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":XcpAppl_h",
        "//software/common:radar_look_types",
        "//software/common/board_revision:board_revision_h",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/ipc:ipc_data_h",
        "//software/common/versions",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb:SWC_PLT_Appl_XCP",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "//software/r52/drivers/mcal/mcu_reset_wrapper",
        "//software/r52/dsp_setup:dsp_setup_h",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/mmic:mmic_h",
        "@boot//:boot_interface",
        "@iND13400_autosar_sip//Components/Fls",
        "@iND13400_autosar_sip//Components/WdgM:WdgM_h",
        "@iND13400_autosar_sip//Components/Xcp:Xcp_h",
    ],
)

cc_library(
    name = "SWC_CDD_XCP_Logging_h",
    srcs = [],
    hdrs = [
        "Include/SWC_PLT_CDD_XCP.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/Include",
    visibility = ["//visibility:public"],
    deps = [
        ":XcpAppl_h",
    ],
)

cc_library(
    name = "XcpAppl_h",
    srcs = [],
    hdrs = [
        "Include/SWC_PLT_CDD_XCP.h",
        "Include/XcpAppl.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/Include",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_library(
    name = "SWC_PLT_CDD_XCP_source_support_lib",
    srcs = [],
    hdrs = [
        "Source/SWC_PLT_CDD_XCP.c",
        "Source/XcpAppl.c",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
)
