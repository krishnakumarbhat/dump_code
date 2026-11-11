cc_library(
    name = "include_h",
    srcs = [],
    hdrs = [
        "main_application.h",
    ],
    local_defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "range_process_ifc_h",
    srcs = [],
    hdrs = [
        "range_process_ifc.h",
    ],
    data = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/adc_logging:adc_data_logging_h",
        "//software/bbe32/inc:mem_pool_h",
        "//software/common/ipc:ipc_data_h",
    ],
)

cc_library(
    name = "ipc_dsp_h",
    srcs = [],
    hdrs = [
        "ipc_dsp.h",
    ],
    defines = [],
    strip_include_prefix = "//software/bbe32/inc",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/ipc:ipc_data_h",
    ],
)

cc_library(
    name = "doppler_process_ifc_h",
    srcs = [],
    hdrs = [
        "doppler_process_ifc.h",
    ],
    data = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":mem_pool_h",
        "@bb_cfg//:spbb_cfg_h",
    ],
)

cc_library(
    name = "mipi_ifc_h",
    srcs = [],
    hdrs = [
        "mipi_ifc.h",
    ],
    data = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":mem_pool_h",
        "@bb_cfg//:spbb_cfg_h",
        "@spbb//modules/helpers:mipi_helpers_h",
    ],
)

cc_library(
    name = "mem_pool_h",
    srcs = [],
    hdrs = [
        "mem_pool.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@appl_inclusion_dep//:spbb_include_h",
    ],
)

cc_library(
    name = "ci_stv_misalignment_h",
    srcs = [],
    hdrs = [
        "ci_stv_misalignment.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@appl_inclusion_dep//:spbb_include_h",
        "@bb_cfg//:spbb_cfg_h",
    ],
)

cc_library(
    name = "angle_finding_project_interface_h",
    srcs = [],
    hdrs = [
        "angle_finding_project_interface.h",
    ],
    defines = [] + select(
        {
            "@build_config//:flr8": ["FLR8"],
            "@build_config//:srr8p": ["SRR8P"],
        },
    ),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/bbe32/inc:mem_pool_h",
        "@Gen8_iND13400//software/common:UDPLoggingStreamHeaders",
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@afbb//module/_api:angle_finding_interface_h",
        "@bb_cfg//:afbb_cfg_h",
        "@reuse",
    ],
)

cc_library(
    name = "cdc_packing_h",
    srcs = [],
    hdrs = [
        "cdc_packing.h",
    ],
    strip_include_prefix = "//software/bbe32/inc",
    visibility = ["//visibility:public"],
    deps = [
        ":ipc_dsp_h",
        "//software/common:cdc_frame_interface_h",
        "//software/common/ipc:ipc_data_h",
        "@appl_inclusion_dep//:spbb_include_h",
        "@bb_cfg//:spbb_cfg_h",
        "@sh_module_cfg//:sh_module_cfg_h",
    ],
)

cc_library(
    name = "performance_monitor_ifc_h",
    srcs = [],
    hdrs = [
        "performance_monitor_ifc.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ipc_dsp_h",
    ],
)

cc_library(
    name = "get_r52_time_from_bbe32_h",
    srcs = [],
    hdrs = [
        "get_r52_time_from_bbe32.h",
    ],
    strip_include_prefix = "//software/bbe32/inc",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/ipc:ipc_data_h",
    ],
)
