cc_library(
    name = "interference_detection_algo_feature_h",
    srcs = [],
    hdrs = [
        "interference_detection_algo_interface.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@idbb//module/id_imp/_inc:interference_detection_inc",
    ],
)

cc_library(
    name = "interference_detection_algo_feature_lib",
    srcs = [
        "interference_detection_algo_interface.c",
    ],
    hdrs = [
    ],
    local_defines = select({
        "@appl_inclusion_dep//:enable_testing_id": [
            "ID_TEST",
        ],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":interference_detection_algo_feature_h",
        "@Gen8_iND13400//software/bbe32/inc:ipc_dsp_h",
        "@appl_inclusion_dep//:idbb_include_h",
        "@idbb//module/id_api:interference_detection_h",
        "@idbb//module/id_imp/_src:interference_detection_src_lib",
        "@rm//module/radar_math:radar_math_lib",
    ],
)

cc_library(
    name = "id_algo_unit_test_support_lib",
    hdrs = [
        "interference_detection_algo_interface.c",
    ],
    local_defines = select({
        "@appl_inclusion_dep//:enable_testing_id": [
            "ID_TEST",
        ],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":interference_detection_algo_feature_h",
        "@Gen8_iND13400//software/bbe32/inc:ipc_dsp_h",
        "@Gen8_iND13400//software/common/calibrations/smc:smc_h",
        "@idbb//module/id_api:interference_detection_h",
        "@idbb//module/id_imp/_cfg:interference_detection_cfg_h",
        "@idbb//module/id_imp/_intr:interference_detection_cbk",
    ],
)
