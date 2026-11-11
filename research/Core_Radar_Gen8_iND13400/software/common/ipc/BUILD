load("@emb_tracker_wrapper//:emb_tracker_project_profile.bzl", "EMB_TRACKER_PROJECT_PROFILE")

exports_files([
    "ipc_data.c",
    "ipc_data.h",
])

cc_library(
    name = "ipc_data_h",
    srcs = [],
    hdrs = [
        "ipc_commands.h",
        "ipc_data.h",
    ],
    defines = EMB_TRACKER_PROJECT_PROFILE().TRACKER_ENABLED_DEFINES + select({
        "//:Run_Feature_functions": ["FEATURE_ENABLE"],
        "//conditions:default": ["FEATURE_DISABLE"],
    }) + select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }) + select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:VEH_AL_CAN_STANDALONE": ["VEH_AL_CAN_STANDALONE"],
        "//conditions:default": [],
    }),
    strip_include_prefix = "//software/common/ipc",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:UDPLoggingStreamHeaders",
        "//software/common:radar_look_types",
        "//software/common/calibrations/smc:radar_sw_config_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync:SWC_PLT_CDD_ECUSync_external_h",
        "@afbb//module/_api:angle_finding_interface_h",
        "@bb_cfg//:afbb_cfg_h",
        "@bb_cfg//:spbb_cfg_h",
        "@dabb//module/dyn_alignment/dyn_alignment_api:dyn_align_module_h",
        "@hilbb//module/_api:hil_command_req_resp_stream_h",
        "@rcbb//module/common:rc_stream_headers",
        "@reuse",
        "@rotbb//emb_tracker:emb_tracker_interface_h",
        "@sabb//module/static_alignment/static_alignment_api:static_alignment_stream_header",
        "@spbb//common:common_h",
        "@spbb//modules/helpers:profiling_helpers_h",
        "@spbb//modules/range_process:range_proc_xcp_include_h",
    ],
)

cc_library(
    name = "ipc_data_lib",
    srcs = [
        "ipc_data.c",
    ],
    hdrs = [
        "ipc_commands.h",
        "ipc_data.h",
    ],
    strip_include_prefix = "//software/common/ipc",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/ipc:ipc_data_h",
    ],
)

cc_library(
    name = "ipc_data_ut_lib",
    hdrs = ["ipc_data.c"],
    strip_include_prefix = "//software/common/ipc",
    visibility = ["//visibility:public"],
    deps = [":ipc_data_h"],
)
