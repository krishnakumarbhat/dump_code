filegroup(
    name = "fg_rdd_stream",
    srcs = [
        "rdd_stream.h",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "rdd_stream_module_h",
    srcs = [
    ],
    hdrs = [
        "rdd_stream.h",
    ],
    defines = [
    ],
    strip_include_prefix = "//software/common/satellite_can_standalone_common",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:stream_header_h",
        "//software/common/calibrations/smc:radar_sw_config_h",
        "@reuse//:fixmac",
    ],
)

filegroup(
    name = "fg_toi_stream",
    srcs = [
        "toi_stream.h",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "toi_stream_module_h",
    srcs = [
    ],
    hdrs = [
        "toi_stream.h",
    ],
    defines = [
    ],
    strip_include_prefix = "//software/common/satellite_can_standalone_common",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:stream_header_h",
        "//software/common/calibrations/smc:radar_sw_config_h",
        "@reuse//:fixmac",
    ],
)

filegroup(
    name = "fg_toi_ds_stream",
    srcs = [
        "toi_ds_stream.h",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "toi_ds_stream_module_h",
    srcs = [
    ],
    hdrs = [
        "toi_ds_stream.h",
    ],
    defines = [
    ],
    strip_include_prefix = "//software/common/satellite_can_standalone_common",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:stream_header_h",
        "//software/common/calibrations/smc:radar_sw_config_h",
        "@reuse//:fixmac",
    ],
)
