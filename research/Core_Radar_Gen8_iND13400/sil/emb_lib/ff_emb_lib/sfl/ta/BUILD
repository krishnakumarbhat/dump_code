cc_library(
    name = "ta_iface",
    srcs = [
        "@sfl//:TA/Source/ta.c",
        "@sfl//:TA/Source/ta.h",
        "@sfl//:TA/Source/ta_iface.c",
    ],
    hdrs = ["@sfl//:TA/Source/ta_iface.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_calibration",
        ":ta_calibration_t",
        ":ta_collision_filter",
        ":ta_common_functions",
        ":ta_constants",
        ":ta_debug_interface",
        ":ta_factory",
        ":ta_input_boundary_check",
        ":ta_io_t",
        ":ta_object_filter",
        ":ta_output_boundary_check",
        ":ta_post_run",
        ":ta_pre_run",
        ":ta_warn_logic",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_traj_pred",
        "//ff_emb_lib/sfl/pt:pt_iface",
    ],
)

cc_library(
    name = "ta_post_run",
    srcs = ["@sfl//:TA/Customer_Adapter/Generic/ta_post_run.c"],
    hdrs = ["@sfl//:TA/Customer_Adapter/ta_post_run.h"],
    strip_include_prefix = "/TA/Customer_Adapter",
    deps = [
        ":ta_instance",
        ":ta_io_t",
    ],
)

cc_library(
    name = "ta_pre_run",
    srcs = ["@sfl//:TA/Customer_Adapter/Generic/ta_pre_run.c"],
    hdrs = ["@sfl//:TA/Customer_Adapter/ta_pre_run.h"],
    strip_include_prefix = "/TA/Customer_Adapter",
    deps = [
        ":ta_instance",
        ":ta_io_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/mock_files:radar_config",
    ],
)

cc_library(
    name = "ta_common_functions",
    srcs = ["@sfl//:TA/Source/ta_common_functions.c"],
    hdrs = ["@sfl//:TA/Source/ta_common_functions.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_calibration_t",
        ":ta_constants",
        ":ta_debug_interface_h",
        ":ta_types_h",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_ref_point",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "ta_debug_interface",
    srcs = ["@sfl//:TA/Source/ta_debug_interface.c"],
    hdrs = ["@sfl//:TA/Source/ta_debug_interface.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_calibration_t",
        ":ta_core_io",
        ":ta_debug_writer_h",
        ":ta_instance",
        ":ta_io_t",
        ":ta_persistent_t",
        ":ta_types_h",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "ta_debug_interface_h",
    hdrs = ["@sfl//:TA/Source/ta_debug_interface.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_calibration_t",
        ":ta_core_io",
        ":ta_debug_writer_h",
        ":ta_instance",
        ":ta_io_t",
        ":ta_persistent_t",
        ":ta_types_h",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "ta_debug_writer",
    srcs = ["@sfl//:TA/Source/ta_debug_writer.c"],
    hdrs = ["@sfl//:TA/Source/ta_debug_writer.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_debug_interface",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
    ],
)

cc_library(
    name = "ta_debug_writer_h",
    hdrs = ["@sfl//:TA/Source/ta_debug_writer.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "ta_instance",
    hdrs = ["@sfl//:TA/Source/ta_instance_t.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_calibration_t",
        ":ta_core_io",
        ":ta_persistent_t",
    ],
)

cc_library(
    name = "ta_core_io",
    hdrs = [
        "@sfl//:TA/Source/ta_core_input_t.h",
        "@sfl//:TA/Source/ta_core_output_t.h",
    ],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_types_h",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
    ],
)

cc_library(
    name = "ta_types_h",
    hdrs = ["@sfl//:TA/Source/ta_types.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
        "//ff_emb_lib/sfl/pt:pt_io_t",
    ],
)

cc_library(
    name = "ta_persistent_t",
    hdrs = ["@sfl//:TA/Source/ta_persistent_t.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_types_h",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "ta_calibration",
    srcs = [
        "@sfl//:TA/Calibration/Generic/ta_calibration.c",
        "@sfl//:TA/Calibration/TA_Core/ta_calibration_cal_check.c",
        "@sfl//:TA/Calibration/TA_Core/ta_calibration_print_functions.c",
    ],
    hdrs = [
        "@sfl//:TA/Calibration/TA_Core/ta_calibration.h",
        "@sfl//:TA/Calibration/TA_Core/ta_calibration_cal_check.h",
    ],
    strip_include_prefix = "/TA/Calibration/TA_Core",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_calibration_t",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "ta_calibration_t",
    hdrs = ["@sfl//:TA/Calibration/TA_Core/ta_calibration_t.h"],
    strip_include_prefix = "/TA/Calibration/TA_Core",
    visibility = ["//visibility:public"],
    deps = ["//ff_emb_lib/sfl/calibration_tool:calibtool"],
)

cc_library(
    name = "ta_io_t",
    hdrs = [
        "@sfl//:TA/Customer_Adapter/Generic/ta_input_t.h",
        "@sfl//:TA/Customer_Adapter/Generic/ta_output_t.h",
    ],
    strip_include_prefix = "/TA/Customer_Adapter/Generic",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_core_io",
        ":ta_types_h",
    ],
)

cc_library(
    name = "ta_input_boundary_check",
    srcs = ["@sfl//:TA/Customer_Adapter/Generic/ta_input_boundary_check.c"],
    hdrs = ["@sfl//:TA/Customer_Adapter/ta_input_boundary_check.h"],
    strip_include_prefix = "/TA/Customer_Adapter",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_io_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_interpolation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "ta_output_boundary_check",
    srcs = ["@sfl//:TA/Customer_Adapter/Generic/ta_output_boundary_check.c"],
    hdrs = ["@sfl//:TA/Customer_Adapter/ta_output_boundary_check.h"],
    strip_include_prefix = "/TA/Customer_Adapter",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_calibration",
        ":ta_io_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_calibration",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_interpolation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_traj_pred_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "ta_intersection_analyzer",
    srcs = ["@sfl//:TA/Source/ta_intersection_analyzer.c"],
    hdrs = ["@sfl//:TA/Source/ta_intersection_analyzer.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        "ta_common_functions",
        ":ta_calibration_t",
        ":ta_debug_interface",
        ":ta_debug_writer_h",
        ":ta_io_t",
        ":ta_persistent_t",
        ":ta_types_h",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_interpolation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "ta_object_filter",
    srcs = ["@sfl//:TA/Source/ta_object_filter.c"],
    hdrs = ["@sfl//:TA/Source/ta_object_filter.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_calibration_t",
        ":ta_core_io",
        ":ta_factory",
        ":ta_io_t",
        ":ta_persistent_t",
        ":ta_types_h",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_interpolation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_traj_pred",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "ta_warn_logic",
    srcs = ["@sfl//:TA/Source/ta_warn_logic.c"],
    hdrs = ["@sfl//:TA/Source/ta_warn_logic.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_calibration_t",
        ":ta_constants",
        ":ta_debug_writer_h",
        ":ta_io_t",
        ":ta_object_filter",
        ":ta_persistent_t",
        ":ta_types_h",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "ta_factory",
    srcs = ["@sfl//:TA/Source/ta_factory.c"],
    hdrs = ["@sfl//:TA/Source/ta_factory.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_calibration_t",
        ":ta_core_io",
        ":ta_debug_writer_h",
        ":ta_instance",
        ":ta_io_t",
        ":ta_persistent_t",
        ":ta_types_h",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_traj_pred",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "ta_constants",
    srcs = ["@sfl//:TA/Source/ta_constants.c"],
    hdrs = ["@sfl//:TA/Source/ta_constants.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_calibration_t",
        ":ta_debug_interface",
        ":ta_io_t",
        ":ta_persistent_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "ta_collision_filter",
    srcs = ["@sfl//:TA/Source/ta_collision_filter.c"],
    hdrs = ["@sfl//:TA/Source/ta_collision_filter.h"],
    strip_include_prefix = "/TA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ta_calibration_t",
        ":ta_constants",
        ":ta_core_io",
        ":ta_intersection_analyzer",
        ":ta_io_t",
        ":ta_persistent_t",
        ":ta_types_h",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)
