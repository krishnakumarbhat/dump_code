load("//tools/bazel/scripts:generate_stream_def.bzl", "generate_stream_def")

filegroup(
    name = "fg_smc_cal",
    srcs = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": [
            "@smc_flr8//:cals_c_files/smc_cal.h",
            "@smc_flr8//:cfg_c_files/radar_sw_config.h",
        ],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": [
            "@smc_flr8_high_det//:cals_c_files/smc_cal.h",
            "@smc_flr8_high_det//:cfg_c_files/radar_sw_config.h",
        ],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": [
            "@smc_flr8_standalone//:cals_c_files/smc_cal.h",
            "@smc_flr8_standalone//:cfg_c_files/radar_sw_config.h",
        ],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": [
            "@smc_srr8p//:cals_c_files/smc_cal.h",
            "@smc_srr8p//:cfg_c_files/radar_sw_config.h",
        ],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": [
            "@smc_srr8p_high_det//:cals_c_files/smc_cal.h",
            "@smc_srr8p_high_det//:cfg_c_files/radar_sw_config.h",
        ],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": [
            "@smc_srr8p_standalone//:cals_c_files/smc_cal.h",
            "@smc_srr8p_standalone//:cfg_c_files/radar_sw_config.h",
        ],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": [
            "@smc_srr8p_al_can_standalone//:cals_c_files/smc_cal.h",
            "@smc_srr8p_al_can_standalone//:cfg_c_files/radar_sw_config.h",
        ],
        "//conditions:default": [
            "@smc_flr8//:cals_c_files/smc_cal.h",
            "@smc_flr8//:cfg_c_files/radar_sw_config.h",
        ],
    }),
    visibility = ["//software/common:__pkg__"],
)

cc_library(
    name = "smc_h",
    hdrs = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": ["@smc_flr8//:cals_c_files/smc_cal.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": ["@smc_flr8_high_det//:cals_c_files/smc_cal.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": ["@smc_flr8_standalone//:cals_c_files/smc_cal.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": ["@smc_srr8p//:cals_c_files/smc_cal.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": ["@smc_srr8p_high_det//:cals_c_files/smc_cal.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": ["@smc_srr8p_standalone//:cals_c_files/smc_cal.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": ["@smc_srr8p_al_can_standalone//:cals_c_files/smc_cal.h"],
        "//conditions:default": ["@smc_flr8//:cals_c_files/smc_cal.h"],
    }),
    defines = [],
    strip_include_prefix = "/cals_c_files",
    visibility = ["//visibility:public"],
    deps = [
        "@Calibration_Handler//:calibration_h",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "smc_module_noinit",
    srcs = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": ["@smc_flr8//:cals_c_files/smc_cal_noinit.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": ["@smc_flr8_high_det//:cals_c_files/smc_cal_noinit.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": ["@smc_flr8_standalone//:cals_c_files/smc_cal_noinit.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": ["@smc_srr8p//:cals_c_files/smc_cal_noinit.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": ["@smc_srr8p_high_det//:cals_c_files/smc_cal_noinit.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": ["@smc_srr8p_standalone//:cals_c_files/smc_cal_noinit.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": ["@smc_srr8p_al_can_standalone//:cals_c_files/smc_cal_noinit.c"],
        "//conditions:default": ["@smc_flr8//:cals_c_files/smc_cal_noinit.c"],
    }),
    defines = [],
    visibility = ["//visibility:public"],
    deps = [
        ":smc_h",
    ],
)

cc_library(
    name = "smc_module_init",
    srcs = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": ["@smc_flr8//:cals_c_files/smc_cal.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": ["@smc_flr8_high_det//:cals_c_files/smc_cal.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": ["@smc_flr8_standalone//:cals_c_files/smc_cal.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": ["@smc_srr8p//:cals_c_files/smc_cal.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": ["@smc_srr8p_high_det//:cals_c_files/smc_cal.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": ["@smc_srr8p_standalone//:cals_c_files/smc_cal.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": ["@smc_srr8p_al_can_standalone//:cals_c_files/smc_cal.c"],
        "//conditions:default": ["@smc_flr8//:cals_c_files/smc_cal.c"],
    }),
    defines = [],
    visibility = ["//visibility:public"],
    deps = [
        ":smc_h",
    ],
)

cc_library(
    name = "smc_module",
    srcs = [],
    defines = [],
    strip_include_prefix = "//software/common/calibrations/smc",
    visibility = ["//visibility:public"],
    deps = [
        ":smc_h",
    ] + select({
        "@calib_cfg//:calibration_default_init": [":smc_module_init"],
        "//conditions:default": [":smc_module_noinit"],
    }),
)

cc_library(
    name = "radar_sw_config_lib",
    srcs = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": ["@smc_flr8//:cfg_c_files/radar_sw_config.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": ["@smc_flr8_high_det//:cfg_c_files/radar_sw_config.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": ["@smc_flr8_standalone//:cfg_c_files/radar_sw_config.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": ["@smc_srr8p//:cfg_c_files/radar_sw_config.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": ["@smc_srr8p_high_det//:cfg_c_files/radar_sw_config.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": ["@smc_srr8p_standalone//:cfg_c_files/radar_sw_config.c"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": ["@smc_srr8p_al_can_standalone//:cfg_c_files/radar_sw_config.c"],
        "//conditions:default": ["@smc_flr8//:cfg_c_files/radar_sw_config.c"],
    }),
    hdrs = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": ["@smc_flr8//:cfg_c_files/radar_sw_config.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": ["@smc_flr8_high_det//:cfg_c_files/radar_sw_config.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": ["@smc_flr8_standalone//:cfg_c_files/radar_sw_config.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": ["@smc_srr8p//:cfg_c_files/radar_sw_config.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": ["@smc_srr8p_high_det//:cfg_c_files/radar_sw_config.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": ["@smc_srr8p_standalone//:cfg_c_files/radar_sw_config.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": ["@smc_srr8p_al_can_standalone//:cfg_c_files/radar_sw_config.h"],
        "//conditions:default": ["@smc_flr8//:cfg_c_files/radar_sw_config.h"],
    }),
    defines = [],
    visibility = ["//visibility:public"],
    deps = [
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "radar_sw_config_h",
    hdrs = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": ["@smc_flr8//:cfg_c_files/radar_sw_config.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": ["@smc_flr8_high_det//:cfg_c_files/radar_sw_config.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": ["@smc_flr8_standalone//:cfg_c_files/radar_sw_config.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": ["@smc_srr8p//:cfg_c_files/radar_sw_config.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": ["@smc_srr8p_high_det//:cfg_c_files/radar_sw_config.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": ["@smc_srr8p_standalone//:cfg_c_files/radar_sw_config.h"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": ["@smc_srr8p_al_can_standalone//:cfg_c_files/radar_sw_config.h"],
        "//conditions:default": ["@smc_flr8//:cfg_c_files/radar_sw_config.h"],
    }),
    defines = [],
    strip_include_prefix = "/cfg_c_files",
    visibility = ["//visibility:public"],
    deps = [
        "@reuse//:fixmac",
    ],
)

# ----------------------------------------------------------
# Stream versions (stream_ver) corresponds to the order
# in which the calibration appears in the CAL_TABLE.w
# So an order change in CAL_TABLE, should result in a
# stream_ver update here as well.
# section_compatability should also be updated along with
# the section_compatability in the corresponding logging_file
# ----------------------------------------------------------
generate_stream_def(
    name = "calib_stream_smc",
    logging_dir = "//software/common:copyStreamFilesToTemp",
    logging_file = "smc_cal.h",
    section_compatability = select({
        # This is for CAN protocol with default SMC
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": 35,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": 35,

        # This is for CAN protocol with default SMC
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": 35,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": 35,

        # This is specific to AL variant
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": 35,

        # This is for Someip protocol with High num of Dets SMC from Tiger
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": 35,
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": 35,

        # This is for CAN protocol with default SMC
        "//conditions:default": 35,
    }),
    stream_num = 14,
    stream_struct = "SMC_Cal_T",
    stream_ver = 1,  # Update when CAL_TABLE order changes
    visibility = ["//visibility:public"],
)
