load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SWC_PLT_Radar_Alignment_Handler",
    srcs = [
        "Source/SWC_PLT_Radar_Alignment_Handler.c",
        "Source/SWC_PLT_Radar_Alignment_Handler_test.c",
    ],
    hdrs = [],
    defines = select({
        "@dabb//module:da_test_stub_data": [
            "ALIGN_STUB_SIMULATE_DET",
        ],
        "//conditions:default": [],
    }) + select({
        "@appl_inclusion_dep//:alignment_nvm_fail_test": [
            "ALIGNMENT_NVM_FAIL_TEST",
        ],
        "//conditions:default": [],
    }) + select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": [
            "AL_ALIGNMENT_BUILD",
        ],
        "//conditions:default": [],
    }) + select({
        "@build_config//:flr8": ["FLR8"],
        "//conditions:default": [],
    }),
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Radar_Alignment_Handler_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP:SWC_CDD_XCP_Logging_h",
        "//software/r52/drivers/mcal:McalInit",
        "//software/r52/ipc:ipc_mss_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@reuse",
    ],
)

cc_library(
    name = "Radar_Alignment_Handler_unit_test_support_lib",
    hdrs = [
        "Source/SWC_PLT_Radar_Alignment_Handler.c",
    ],
    defines = select({
        "@build_config//:flr8": ["FLR8"],
        "//conditions:default": [],
    }),
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Radar_Alignment_Handler_h",
    ],
)

cc_library(
    name = "SWC_PLT_Radar_Alignment_Handler_h",
    srcs = [],
    hdrs = [
        "Include/SWC_PLT_Radar_Alignment_Handler.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler/Include",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common/calibrations/smc:smc_h",
        "@Gen8_iND13400//software/r52/dsp_setup:dsp_setup_h",
        "@Sensor_Position//:sensor_position_h",
        "@TOI_Char_Quality_Determination//:TOI_Radar_Data_Quality_Check_lib_h",
        "@dabb//module/dyn_alignment/dyn_alignment_api:dyn_align_module_h",
        "@iND13400_autosar_sip//Components/Xcp:Xcp_h",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
        "@sabb//module/static_alignment/static_alignment_api:static_alignment_algo_inc",
    ],
)
