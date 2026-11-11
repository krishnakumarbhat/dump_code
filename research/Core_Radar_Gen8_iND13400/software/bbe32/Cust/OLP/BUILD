load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "OLP_Core_Lib",
    srcs = [
        "OLP_Core/source/olp.cpp",
        "OLP_Core/source/olp_calibration.cpp",
        "OLP_Core/source/olp_compute_cog.cpp",
        "OLP_Core/source/olp_compute_curvi_data.cpp",
        "OLP_Core/source/olp_distance_based_curvature.cpp",
        "OLP_Core/source/olp_iface.cpp",
        "OLP_Core/source/olp_ml_math.cpp",
        "OLP_Core/source/olp_snail_trail_computation.cpp",
    ],
    defines = [
        "OLP_OBJ_SOURCE_F360",
        "OLP_NUMBER_OF_OBJECTS=64",
    ],
    features = ["-lto"],
    visibility = ["//visibility:public"],
    deps = [
        ":OLP_Core_h",
        "@math_library_bb//:ml_core_lib",
    ],
)

cc_library(
    name = "OLP_Core_h",
    hdrs = [
        "OLP_Core/includes/olp.h",
        "OLP_Core/includes/olp_calibration.h",
        "OLP_Core/includes/olp_compute_cog.h",
        "OLP_Core/includes/olp_compute_curvi_data.h",
        "OLP_Core/includes/olp_core_types.h",
        "OLP_Core/includes/olp_distance_based_curvature.h",
        "OLP_Core/includes/olp_iface.h",
        "OLP_Core/includes/olp_ml_math.h",
        "OLP_Core/includes/olp_snail_trail_computation.h",
    ],
    defines = [
        "OLP_OBJ_SOURCE_F360",
        "OLP_NUMBER_OF_OBJECTS=64",
    ],
    includes = ["OLP_Core/includes"],
    visibility = ["//visibility:public"],
    deps = [
        "@math_library_bb//:ml_core_lib",
        "@math_library_bb//:ml_legacy_h",
    ],
)
