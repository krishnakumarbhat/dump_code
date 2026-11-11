load("@rules_cc//cc:defs.bzl", "cc_library")

# Start of Mode Manager

cc_library(
    name = "sfl_input_processing_h",
    hdrs = ["SFL_InputProcessing/SFL_InputProcessing_iface.h"],
    includes = ["SFL_InputProcessing"],
    visibility = ["//visibility:public"],
    deps = [
        ":sfl_mode_manager_calibration_h",
        ":sfl_mode_manager_reuse_h",
        ":sfl_mode_manager_shared_library_h",
    ],
)

cc_library(
    name = "sfl_input_processing_bsis_h",
    hdrs = ["SFL_InputProcessing/BSIS/bsis_input_processing.h"],
    includes = ["SFL_InputProcessing/BSIS"],
    visibility = ["//visibility:public"],
    deps = [
        ":sfl_input_processing_h",
        ":sfl_mode_manager_calibration_h",
        ":sfl_mode_manager_reuse_h",
        ":sfl_mode_manager_shared_library_h",
    ],
)

cc_library(
    name = "sfl_input_processing_mois_h",
    hdrs = ["SFL_InputProcessing/MOIS/mois_input_processing.h"],
    includes = ["SFL_InputProcessing/MOIS"],
    visibility = ["//visibility:public"],
    deps = [
        ":sfl_input_processing_h",
        ":sfl_mode_manager_calibration_h",
        ":sfl_mode_manager_reuse_h",
        ":sfl_mode_manager_shared_library_h",
    ],
)

cc_library(
    name = "sfl_output_processing_h",
    hdrs = ["SFL_OutputProcessing/SFL_OutputProcessing_iface.h"],
    includes = ["SFL_OutputProcessing"],
    visibility = ["//visibility:public"],
    deps = [
        ":sfl_mode_manager_calibration_h",
        ":sfl_mode_manager_reuse_h",
        ":sfl_mode_manager_shared_library_h",
    ],
)

cc_library(
    name = "sfl_output_processing_bsis_h",
    hdrs = ["SFL_OutputProcessing/BSIS/bsis_output_processing.h"],
    includes = ["SFL_OutputProcessing/BSIS"],
    visibility = ["//visibility:public"],
    deps = [
        ":sfl_mode_manager_calibration_h",
        ":sfl_mode_manager_reuse_h",
        ":sfl_mode_manager_shared_library_h",
        ":sfl_output_processing_h",
    ],
)

cc_library(
    name = "sfl_output_processing_mois_h",
    hdrs = ["SFL_OutputProcessing/MOIS/mois_output_processing.h"],
    includes = ["SFL_OutputProcessing/MOIS"],
    visibility = ["//visibility:public"],
    deps = [
        ":sfl_mode_manager_calibration_h",
        ":sfl_mode_manager_reuse_h",
        ":sfl_mode_manager_shared_library_h",
        ":sfl_output_processing_h",
    ],
)

cc_library(
    name = "sfl_mode_manager_shared_library_h",
    hdrs = [
        "Shared_Library/MM_OutputProcessing_T.h",
        "Shared_Library/SFL_Constants.h",
        "Shared_Library/SFL_Types.h",
        "Shared_Library/macros.h",
        "Shared_Library/ml_math.h",
    ],
    includes = ["Shared_Library"],
    visibility = ["//visibility:public"],
    deps = [":sfl_mode_manager_reuse_h"],
)

cc_library(
    name = "sfl_mode_manager_reuse_h",
    hdrs = ["Shared_Library/reuse.h"],
    includes = ["Shared_Library"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "sfl_mode_manager_calibration_h",
    hdrs = ["Calibrations/SFL_Calibration.h"],
    includes = ["Calibrations"],
    visibility = ["//visibility:public"],
    deps = [":sfl_mode_manager_shared_library_h"],
)

cc_library(
    name = "mode_manager_lib",
    srcs = [
        "Calibrations/SFL_Calibration.c",
        "SFL_InputProcessing/BSIS/bsis_input_processing.c",
        "SFL_InputProcessing/MOIS/mois_input_processing.c",
        "SFL_InputProcessing/SFL_InputProcessing_iface.c",
        "SFL_OutputProcessing/BSIS/bsis_output_processing.c",
        "SFL_OutputProcessing/MOIS/mois_output_processing.c",
        "SFL_OutputProcessing/SFL_OutputProcessing_iface.c",
    ],
    copts = [
        "-Wno-unused-parameter",
    ],
    defines = [
        "FF_BSIS",
        "FF_MOIS",
    ],
    features = ["-lto"],
    visibility = ["//visibility:public"],
    deps = [
        ":sfl_input_processing_bsis_h",
        ":sfl_input_processing_h",
        ":sfl_input_processing_mois_h",
        ":sfl_mode_manager_calibration_h",
        ":sfl_mode_manager_reuse_h",
        ":sfl_mode_manager_shared_library_h",
        ":sfl_output_processing_bsis_h",
        ":sfl_output_processing_h",
        ":sfl_output_processing_mois_h",
    ],
)
# End of Mode Manager
