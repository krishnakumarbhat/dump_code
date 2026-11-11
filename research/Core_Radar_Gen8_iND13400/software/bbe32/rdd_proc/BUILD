load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "rdd_proc_h",
    srcs = [
        # No sources included directly here. Dependencies will point to the privately available source files.
    ],
    hdrs = [
        "api/appl_fp_ifc.h",
    ],
    defines = [],
    strip_include_prefix = "api",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/rdd_proc/api:appl_fp_ifc_h",
        "//software/bbe32/rdd_proc/imp/src:appl_fp_ifc_lib",
    ],
)
