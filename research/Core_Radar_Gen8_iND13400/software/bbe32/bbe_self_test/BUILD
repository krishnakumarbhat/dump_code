exports_files([
    "fusa_bbe_self_test.c",
    "fusa_bbe_self_test.h",
])

cc_library(
    name = "fusa_bbe_self_test_h",
    srcs = [],
    hdrs = [
        "fusa_bbe_self_test.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "fusa_bbe_self_test_lib",
    srcs = [
        "fusa_bbe_self_test.c",
    ],
    hdrs = [
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":fusa_bbe_self_test_h",
        "//software/bbe32/inc:include_h",
        "//software/bbe32/inc:mem_pool_h",
        "@bbe_luna_stl//:stl_lib",
        "@spbb//modules/helpers:bbe_helpers_h",
        "@spbb//modules/helpers:timing_helpers_h",
    ],
)

cc_library(
    name = "fusa_bbe_self_test_ut_lib",
    hdrs = ["fusa_bbe_self_test.c"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":fusa_bbe_self_test_h",
        "//software/bbe32/inc:include_h",
        "//software/bbe32/inc:mem_pool_h",
        "//software/bbe32/inc:mipi_ifc_h",
        "@bbe_luna_stl//:stl_lib",
        "@spbb//modules/helpers:timing_helpers_h",
    ],
)
