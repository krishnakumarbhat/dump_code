cc_library(
    name = "fbk_iface",
    srcs = [
        "@sfl//:Feature_Building_Kit/Interface/fbk_iface.c",
    ],
    hdrs = [
        "@sfl//:Feature_Building_Kit/Interface/fbk_ego_traj_predictor_instance.h",
        "@sfl//:Feature_Building_Kit/Interface/fbk_iface.h",
        "@sfl//:Feature_Building_Kit/Interface/fbk_iface_types.h",
        "@sfl//:Feature_Building_Kit/Interface/fbk_instance.h",
        "@sfl//:Feature_Building_Kit/Interface/fbk_output.h",
        "@sfl//:Feature_Building_Kit/Interface/sfl_status.h",
    ],
    strip_include_prefix = "/Feature_Building_Kit/Interface",
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_boundaries",
        ":fbk_calibration",
        ":fbk_debug_interface",
        ":fbk_fill_pa_data",
        ":fbk_host_trail",
        ":fbk_iface_types",
        ":fbk_index_lookup",
        ":fbk_object_ageing",
        ":fbk_shared_ff_traj_pred_types",
        "//ff_emb_lib/sfl/math_library:mathlib_types",
    ],
)

cc_library(
    name = "fbk_iface_types",
    hdrs = ["@sfl//:Feature_Building_Kit/Interface/fbk_iface_types.h"],
    strip_include_prefix = "/Feature_Building_Kit/Interface",
    visibility = ["//visibility:public"],
    deps = [
        ":pa_const_macros",
        ":pa_reuse",
        "//ff_emb_lib/sfl/math_library:mathlib_types",
    ],
)

cc_library(
    name = "fbk_fill_pa_data",
    srcs = ["@sfl//:Feature_Building_Kit/Interface/fill_pa_data/fbk_fill_pa_data.c"],
    hdrs = ["@sfl//:Feature_Building_Kit/Interface/fill_pa_data/fbk_fill_pa_data.h"],
    strip_include_prefix = "/Feature_Building_Kit/Interface/fill_pa_data",
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_shared_ff_validation",
        ":fbk_shared_ff_validation_types",
        ":pa_const_macros",
        ":pa_context",
        ":pa_selector",
    ],
)

cc_library(
    name = "fbk_index_lookup",
    srcs = ["@sfl//:Feature_Building_Kit/Interface/index_lookup/fbk_index_lookup.c"],
    hdrs = ["@sfl//:Feature_Building_Kit/Interface/index_lookup/fbk_index_lookup.h"],
    strip_include_prefix = "/Feature_Building_Kit/Interface/index_lookup",
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_debug_interface",
        ":fbk_functions",
    ],
)

cc_library(
    name = "fbk_object_ageing",
    srcs = ["@sfl//:Feature_Building_Kit/Interface/object_ageing/fbk_obj_ageing.c"],
    hdrs = ["@sfl//:Feature_Building_Kit/Interface/object_ageing/fbk_obj_ageing.h"],
    strip_include_prefix = "/Feature_Building_Kit/Interface/object_ageing",
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_debug_interface",
        ":fbk_iface_types",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "fbk_boundaries",
    srcs = ["@sfl//:Feature_Building_Kit/Interface/boundaries/fbk_output_boundary_check.c"],
    hdrs = ["@sfl//:Feature_Building_Kit/Interface/boundaries/fbk_output_boundary_check.h"],
    strip_include_prefix = "/Feature_Building_Kit/Interface/boundaries",
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_iface_types",
        ":fbk_index_lookup",
    ],
)

cc_library(
    name = "fbk_host_trail",
    srcs = ["@sfl//:Feature_Building_Kit/Interface/host_trail/fbk_host_trail.c"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_calibration",
        ":fbk_debug_interface",
        ":fbk_host_trail_h",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "fbk_host_trail_h",
    hdrs = ["@sfl//:Feature_Building_Kit/Interface/host_trail/fbk_host_trail.h"],
    strip_include_prefix = "/Feature_Building_Kit/Interface/host_trail",
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_iface_types",
    ],
)

cc_library(
    name = "fbk_debug_interface",
    srcs = [
        "@sfl//:Feature_Building_Kit/Interface/debug_writer/fbk_debug_interface.c",
        "@sfl//:Feature_Building_Kit/Interface/debug_writer/fbk_debug_writer.c",
    ],
    hdrs = [
        "@sfl//:Feature_Building_Kit/Interface/debug_writer/fbk_debug_interface.h",
        "@sfl//:Feature_Building_Kit/Interface/debug_writer/fbk_debug_writer.h",
    ],
    strip_include_prefix = "/Feature_Building_Kit/Interface/debug_writer",
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_calibration",
        ":fbk_functions",
        ":fbk_host_trail_h",
        ":fbk_shared_ff_validation",
        ":pa_obj_in",
    ],
)

cc_library(
    name = "fbk_calibration",
    srcs = [
        "@sfl//:Feature_Building_Kit/Calibration/Feature_Building_Kit_Core/fbk_calibration_cal_check.c",
        "@sfl//:Feature_Building_Kit/Calibration/Generic/fbk_calibration.c",
    ],
    hdrs = [
        "@sfl//:Feature_Building_Kit/Calibration/Feature_Building_Kit_Core/fbk_calibration.h",
        "@sfl//:Feature_Building_Kit/Calibration/Feature_Building_Kit_Core/fbk_calibration_cal_check.h",
        "@sfl//:Feature_Building_Kit/Calibration/Feature_Building_Kit_Core/fbk_calibration_t.h",
    ],
    strip_include_prefix = "/Feature_Building_Kit/Calibration/Feature_Building_Kit_Core",
    visibility = ["//visibility:public"],
    deps = [
        ":pa_reuse",
        "//ff_emb_lib/sfl/calibration_tool:calibtool",
    ],
)

cc_library(
    name = "pa_obj_in",
    hdrs = [
        "@sfl//:Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports/pa_obj_in.h",
    ],
    strip_include_prefix = "/Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports",
    visibility = ["//visibility:public"],
    deps = [
        ":pa_context",
        ":pa_reuse",
    ],
)

cc_library(
    name = "pa_const_macros",
    hdrs = ["@sfl//:Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports/pa_const_macros.h"],
    strip_include_prefix = "/Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "pa_vehicle_in",
    hdrs = ["@sfl//:Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports/pa_vehicle_in.h"],
    strip_include_prefix = "/Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "pa_env_in",
    hdrs = ["@sfl//:Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports/pa_env_in.h"],
    strip_include_prefix = "/Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "pa_reuse",
    hdrs = [
        "@sfl//:Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports/pa_reuse.h",
    ],
    strip_include_prefix = "/Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports",
    visibility = ["//visibility:public"],
    deps = ["//ff_emb_lib/sfl/math_library:mathlib_reuse"],
)

cc_library(
    name = "pa_context",
    hdrs = ["@sfl//:Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/pa_context.h"],
    strip_include_prefix = "/Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc",
    visibility = ["//visibility:public"],
    deps = [
        ":pa_data",
        ":pa_shared_types",
    ],
)

cc_library(
    name = "pa_shared_types",
    hdrs = [
        "@sfl//:Feature_Building_Kit/Platform_Abstraction_Layer/pa_shared_types.h",
    ],
    strip_include_prefix = "/Feature_Building_Kit/Platform_Abstraction_Layer",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "pa_data",
    hdrs = [
        "@sfl//:Feature_Building_Kit/Platform_Abstraction_Layer/pa_data.h",
    ],
    defines = ["PA_OBJ_NUMBER_OF_OBJECTS=64"],
    strip_include_prefix = "/Feature_Building_Kit/Platform_Abstraction_Layer",
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_shared_ff_validation_types",
        ":pa_const_macros",
    ],
)

cc_library(
    name = "pa_selector",
    srcs = ["@sfl//:Feature_Building_Kit/Platform_Abstraction_Layer/pa_selector.c"],
    hdrs = ["@sfl//:Feature_Building_Kit/Platform_Abstraction_Layer/pa_selector.h"],
    defines = ["PA_Generic"],
    strip_include_prefix = "/Feature_Building_Kit/Platform_Abstraction_Layer",
    visibility = ["//visibility:public"],
    deps = [":pa_context"],
)

cc_library(
    name = "fbk_shared_ff_traj_pred",
    srcs = [
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction/fbk_circular_shape_calculator.c",
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction/fbk_ego_traj_predictor.c",
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction/fbk_obj_traj_predictor.c",
    ],
    hdrs = [
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction/fbk_circular_shape_calculator.h",
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction/fbk_ego_traj_predictor.h",
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction/fbk_obj_traj_predictor.h",
    ],
    strip_include_prefix = "/Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction",
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_iface",
        ":fbk_shared_ff_traj_pred_types",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "fbk_field_of_interest",
    srcs = ["@sfl//:Feature_Building_Kit/Shared_Feature_Functions/zone/fbk_field_of_interest_factory.c"],
    hdrs = [
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/zone/fbk_field_of_interest.h",
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/zone/fbk_field_of_interest_factory.h",
    ],
    strip_include_prefix = "/Feature_Building_Kit/Shared_Feature_Functions/zone",
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_functions",
        ":fbk_ref_point",
        ":pa_reuse",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "fbk_ref_point",
    srcs = [
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/reference_point/fbk_ref_point_calc.c",
    ],
    hdrs = [
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/reference_point/fbk_ref_point.h",
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/reference_point/fbk_ref_point_calc.h",
    ],
    strip_include_prefix = "/Feature_Building_Kit/Shared_Feature_Functions/reference_point",
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_functions",
        ":pa_reuse",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "fbk_interpolation",
    srcs = [
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/interpolation/fbk_array_interpolation.c",
    ],
    hdrs = [
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/interpolation/fbk_array_interpolation.h",
    ],
    strip_include_prefix = "/Feature_Building_Kit/Shared_Feature_Functions/interpolation",
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_functions",
        ":pa_reuse",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "fbk_functions",
    srcs = ["@sfl//:Feature_Building_Kit/Shared_Feature_Functions/fbk_functions.c"],
    hdrs = [
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/fbk_functions.h",
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/fbk_macros.h",
    ],
    strip_include_prefix = "/Feature_Building_Kit/Shared_Feature_Functions",
    visibility = ["//visibility:public"],
    deps = [
        ":pa_reuse",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "fbk_shared_ff_traj_pred_types",
    hdrs = [
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction/fbk_traj_predictor_t.h",
    ],
    strip_include_prefix = "/Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction",
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_functions",
        ":fbk_shared_ff_validation_types",
        ":pa_obj_in",
    ],
)

cc_library(
    name = "fbk_shared_ff_validation_types",
    hdrs = [
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_guardrail_data_t.h",
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_object_data_t.h",
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_vehicle_data_t.h",
    ],
    strip_include_prefix = "/Feature_Building_Kit/Shared_Feature_Functions/validation",
    visibility = ["//visibility:public"],
    deps = [
        ":pa_reuse",
        ":pa_shared_types",
        "//ff_emb_lib/sfl/math_library:mathlib_types",
    ],
)

cc_library(
    name = "fbk_shared_ff_validation",
    srcs = [
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_guardrail_validation.c",
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_object_validation.c",
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_vehicle_validation.c",
    ],
    hdrs = [
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_guardrail_validation.h",
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_object_validation.h",
        "@sfl//:Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_vehicle_validation.h",
    ],
    strip_include_prefix = "/Feature_Building_Kit/Shared_Feature_Functions/validation",
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_functions",
        ":fbk_shared_ff_validation_types",
        ":pa_context",
        ":pa_env_in",
        ":pa_obj_in",
        ":pa_vehicle_in",
    ],
)
