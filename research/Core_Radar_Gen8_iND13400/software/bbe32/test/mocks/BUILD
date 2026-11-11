cc_library(
    name = "ci_stv_misalignment_mock_lib",
    srcs = [
        "ci_stv_misalignment_fff.cc",
    ],
    hdrs = [
        "ci_stv_misalignment_fff.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ci_stv_misalignment_h",
        "@fff",
    ],
)

cc_library(
    name = "ipc_mock_lib",
    srcs = [
        "ipc_fff.cc",
    ],
    hdrs = [
        "ipc_fff.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:ipc_dsp_h",
        "@fff",
        "@spbb//common:bbe_xtensa_mock_lib",
    ],
)

cc_library(
    name = "mipi_ifc_mock_lib",
    srcs = [
        "mipi_ifc_fff.cc",
    ],
    hdrs = [
        "mipi_ifc_fff.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:mem_pool_h",
        "//software/bbe32/inc:mipi_ifc_h",
        "@fff",
    ],
)

cc_library(
    name = "range_process_ifc_mock_lib",
    srcs = [
        "range_process_ifc_fff.cc",
    ],
    hdrs = [
        "range_process_ifc_fff.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:range_process_ifc_h",
        "@fff",
    ],
)
