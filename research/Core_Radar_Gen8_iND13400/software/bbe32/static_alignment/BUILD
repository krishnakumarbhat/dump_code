load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "static_alignment_h",
    srcs = [
    ],
    hdrs = [
        "static_align_wrapper.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/bbe32/inc:mem_pool_h",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@sabb//module/static_alignment/static_alignment_api:static_alignment_algo_inc",
    ],
)

cc_library(
    name = "static_alignment",
    srcs = [
        "static_align_wrapper.c",
    ],
    hdrs = [
    ],
    defines = select({
        "@sabb//module:sa_test_stub_data": [
            "ALIGN_STUB_SIMULATE_DET",
        ],
        "//conditions:default": [],
    }),
    local_defines = select({
        "@appl_inclusion_dep//:psp_sil_enable": [
            "PSP_SIL_ENABLE",
        ],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":static_alignment_h",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler:SWC_PLT_Radar_Alignment_Handler_h",
        "@reuse",
        "@rm//module/radar_math:radar_math_lib",
        "@sabb//module/static_alignment/static_alignment_api:static_alignment_algo_inc",
        "@sabb//module/static_alignment/static_alignment_imp/_src:static_alignment_algo_src",
    ],
)

cc_library(
    name = "alignment_wrapper_unit_test_support_lib",
    hdrs = [
        "static_align_wrapper.c",
    ],
    defines = select({
        "@sabb//module:sa_test_stub_data": [
            "GTEST_STATIC_VARIABLE",
        ],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":static_alignment_h",
        "@Gen8_iND13400//software/bbe32/inc:mem_pool_h",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler:SWC_PLT_Radar_Alignment_Handler_h",
        "@reuse",
        "@sabb//module/static_alignment/static_alignment_api:static_alignment_algo_inc",
        "@sabb//module/static_alignment/static_alignment_imp/_src:static_alignment_algo_src",
    ],
)
