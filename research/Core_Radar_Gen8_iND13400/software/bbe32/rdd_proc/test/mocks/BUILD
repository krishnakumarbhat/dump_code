cc_library(
    name = "appl_fp_ifc_mock_lib",
    srcs = [
        "appl_fp_ifc_fff.cc",
    ],
    hdrs = [
        "appl_fp_ifc_fff.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:mem_pool_h",
        "//software/bbe32/rdd_proc/api:appl_fp_ifc_h",
        "//software/common/ipc:ipc_data_h",
        "@fff",
        "@spbb//modules/rdd_first_pass_process:rdd_fp_include_h",
    ],
)

cc_library(
    name = "appl_cfar_ifc_mock_lib",
    srcs = [
        "appl_cfar_ifc_fff.cc",
    ],
    hdrs = [
        "appl_cfar_ifc_fff.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:mem_pool_h",
        "//software/bbe32/rdd_proc/api:appl_cfar_ifc_h",
        "//software/common/ipc:ipc_data_h",
        "@fff",
    ],
)

cc_library(
    name = "appl_sp_ifc_mock_lib",
    srcs = [
        "appl_sp_ifc_fff.cc",
    ],
    hdrs = [
        "appl_sp_ifc_fff.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/rdd_proc/api:appl_sp_ifc_h",
        "//software/common/ipc:ipc_data_h",
        "@fff",
    ],
)

cc_library(
    name = "appl_sweepbw_ifc_mock_lib",
    srcs = [
        "appl_sweepbw_ifc_fff.cc",
    ],
    hdrs = [
        "appl_sweepbw_ifc_fff.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/rdd_proc/api:appl_sweepbw_ifc_h",
        "//software/common/ipc:ipc_data_h",
        "@fff",
    ],
)
