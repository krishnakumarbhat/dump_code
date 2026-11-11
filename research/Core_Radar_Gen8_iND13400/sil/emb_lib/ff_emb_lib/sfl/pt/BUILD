cc_library(
    name = "pt_iface",
    srcs = [
        "@sfl//:PT/Source/pt.c",
        "@sfl//:PT/Source/pt.h",
        "@sfl//:PT/Source/pt_iface.c",
    ],
    hdrs = ["@sfl//:PT/Source/pt_iface.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_calibration",
        ":pt_debug_interface",
        ":pt_group_paths",
        ":pt_host_lane",
        ":pt_modify_grid_cals",
        ":pt_object_matching",
        ":pt_path_rotation",
    ],
)

cc_library(
    name = "pt_constants",
    srcs = ["@sfl//:PT/Customer_Adapter/Generic/pt_constants.c"],
    hdrs = ["@sfl//:PT/Customer_Adapter/Generic/pt_constants.h"],
    strip_include_prefix = "/PT/Customer_Adapter/Generic",
    deps = [
        ":pt_instance",
    ],
)

cc_library(
    name = "pt_common_functions",
    srcs = ["@sfl//:PT/Source/pt_common_functions.c"],
    hdrs = ["@sfl//:PT/Source/pt_common_functions.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_debug_interface_h",
    ],
)

cc_library(
    name = "pt_group_paths",
    srcs = ["@sfl//:PT/Source/pt_group_paths.c"],
    hdrs = ["@sfl//:PT/Source/pt_group_paths.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_reset",
    ],
)

cc_library(
    name = "pt_host_lane",
    srcs = ["@sfl//:PT/Source/pt_host_lane.c"],
    hdrs = ["@sfl//:PT/Source/pt_host_lane.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_common_functions",
        ":pt_debug_interface_h",
    ],
)

cc_library(
    name = "pt_object_matching",
    srcs = ["@sfl//:PT/Source/pt_object_matching.c"],
    hdrs = ["@sfl//:PT/Source/pt_object_matching.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_output_factory",
    ],
)

cc_library(
    name = "pt_path_rotation",
    srcs = ["@sfl//:PT/Source/pt_path_rotation.c"],
    hdrs = ["@sfl//:PT/Source/pt_path_rotation.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_reset",
    ],
)

cc_library(
    name = "pt_output_factory",
    srcs = ["@sfl//:PT/Source/pt_output_factory.c"],
    hdrs = ["@sfl//:PT/Source/pt_output_factory.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_reset",
    ],
)

cc_library(
    name = "pt_persistent_handler",
    srcs = ["@sfl//:PT/Source/pt_persistent_handler.c"],
    hdrs = ["@sfl//:PT/Source/pt_persistent_handler.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_debug_interface_h",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_interpolation",
    ],
)

cc_library(
    name = "pt_modify_grid_cals",
    srcs = ["@sfl//:PT/Source/pt_modify_grid_cals.c"],
    hdrs = ["@sfl//:PT/Source/pt_modify_grid_cals.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_debug_interface_h",
    ],
)

cc_library(
    name = "pt_debug_interface",
    srcs = ["@sfl//:PT/Source/pt_debug_interface.c"],
    hdrs = ["@sfl//:PT/Source/pt_debug_interface.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_debug_writer_h",
        ":pt_reset",
    ],
)

cc_library(
    name = "pt_debug_interface_h",
    hdrs = ["@sfl//:PT/Source/pt_debug_interface.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_constants",
        ":pt_io_t",
    ],
)

cc_library(
    name = "pt_debug_writer",
    srcs = ["@sfl//:PT/Source/pt_debug_writer.c"],
    hdrs = ["@sfl//:PT/Source/pt_debug_writer.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "pt_debug_writer_h",
    hdrs = ["@sfl//:PT/Source/pt_debug_writer.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "pt_instance",
    hdrs = ["@sfl//:PT/Source/pt_instance.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_calibration_t",
        ":pt_persistent_t",
    ],
)

cc_library(
    name = "pt_types",
    hdrs = ["@sfl//:PT/Source/pt_types.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_directions",
    ],
)

cc_library(
    name = "pt_reset",
    srcs = ["@sfl//:PT/Source/pt_reset.c"],
    hdrs = ["@sfl//:PT/Source/pt_reset.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_common_functions",
        ":pt_persistent_handler",
    ],
)

cc_library(
    name = "pt_directions",
    hdrs = ["@sfl//:PT/Source/pt_directions.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
    ],
)

cc_library(
    name = "pt_persistent_t",
    hdrs = ["@sfl//:PT/Source/pt_persistent_t.h"],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
    ],
)

cc_library(
    name = "pt_calibration",
    srcs = [
        "@sfl//:PT/Calibration/Generic/pt_calibration.c",
        "@sfl//:PT/Calibration/PT_Core/pt_calibration_cal_check.c",
        "@sfl//:PT/Calibration/PT_Core/pt_calibration_print_functions.c",
    ],
    hdrs = [
        "@sfl//:PT/Calibration/PT_Core/pt_calibration.h",
        "@sfl//:PT/Calibration/PT_Core/pt_calibration_cal_check.h",
    ],
    strip_include_prefix = "/PT/Calibration/PT_Core",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_calibration_t",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "pt_calibration_t",
    hdrs = ["@sfl//:PT/Calibration/PT_Core/pt_calibration_t.h"],
    strip_include_prefix = "/PT/Calibration/PT_Core",
    visibility = ["//visibility:public"],
    deps = [
        "//ff_emb_lib/sfl/calibration_tool:calibtool",
    ],
)

cc_library(
    name = "pt_io_t",
    hdrs = [
        "@sfl//:PT/Source/pt_input_t.h",
        "@sfl//:PT/Source/pt_output_t.h",
    ],
    strip_include_prefix = "/PT/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":pt_types",
    ],
)
