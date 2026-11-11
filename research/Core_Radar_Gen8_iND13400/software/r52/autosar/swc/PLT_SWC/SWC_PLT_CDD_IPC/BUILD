load("@rules_cc//cc:defs.bzl", "cc_library")
load("@emb_tracker_wrapper//:emb_tracker_project_profile.bzl", "EMB_TRACKER_PROJECT_PROFILE")

# Export source files for testing
exports_files([
    "Source/SWC_CDD_IPC.c",
])

cc_library(
    name = "SWC_CDD_IPC",
    srcs = [
        "Source/SWC_CDD_IPC.c",
        "Source/SWC_CDD_IPC_test.c",
    ],
    hdrs = [],
    local_defines = select({
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }) + select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }) + select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:VEH_AL_CAN_STANDALONE": ["VEH_AL_CAN_STANDALONE"],
        "//conditions:default": [],
    }) + EMB_TRACKER_PROJECT_PROFILE().TRACKER_ENABLED_DEFINES,
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC:SWC_CDD_IPC/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//software/building_block/sh_cfg:sh_module_cfg_h",
        "//software/common/crc_calc:crc_calc_h",
        "//software/common/ipc:ipc_data_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:PLT_Appl_PlatformTime_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/VSE:vse_core_c_api",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/VSE/vse_stub:vse_teststub",
        "//software/r52/dsp_setup:dsp_setup_h",
        "//software/r52/ipc:ipc_mss_h",
        "//software/r52/program_flow_monitor:program_flow_monitor_h",
        "@iND13400_autosar_sip//Components/WdgM:WdgM_h",
        "@reuse",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "SWC_CDD_IPC_unit_test_support_lib",
    hdrs = [
        "Source/SWC_CDD_IPC.c",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//software/building_block/sh_cfg:sh_module_cfg_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/VSE/vse_stub:vse_teststub",
        "//software/r52/dsp_setup:dsp_setup_h",
        "//software/r52/program_flow_monitor:program_flow_monitor_h",
        "@iND13400_autosar_sip//Components/WdgM:WdgM_h",
    ],
)
