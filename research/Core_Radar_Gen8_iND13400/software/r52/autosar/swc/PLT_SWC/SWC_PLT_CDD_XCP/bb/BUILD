cc_library(
    name = "SWC_PLT_Appl_XCP",
    srcs = [
        "Source/xcp_bb.c",
        "Source/xcp_user_cmds.c",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_XCP_H",
        "@reuse",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_XCP_H",
    hdrs = [
        "Include/xcp_bb.h",
        "Include/xcp_bb_types.h",
        "Include/xcp_user_cmds.h",
        "Include/xcp_version.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:radar_look_types",
        "//software/common/ipc:ipc_data_h",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "xcp_bb_unit_test_support_lib",
    hdrs = [
        "Source/xcp_bb.c",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_XCP_H",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb/test/mocks:xcp_bb_fake_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb/test/mocks:xcp_user_cmds_fake_lib",
    ],
)

cc_library(
    name = "xcp_user_unit_test_support_lib",
    hdrs = [
        "Source/xcp_user_cmds.c",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_XCP_H",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb/test/mocks:xcp_core_fake_lib",
    ],
)
