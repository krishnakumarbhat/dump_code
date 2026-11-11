load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "sfl_core",
    visibility = ["//visibility:public"],
    deps = [
        ":bsis_lib",
        ":cal_tool_lib",
        ":fbk_lib",
        ":mois_lib",
        "@math_library_bb//:ml_core_lib",
    ],
)

# Start of BIN_WRITER module
cc_library(
    name = "as_bin_writer_wrapper_mock_h",
    hdrs = ["BIN_WRITER/lib/lib_mock/AS_bin_writer_wrapper.h"],
    includes = ["BIN_WRITER/lib/lib_mock"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "as_bin_writer_lib",
    srcs = [
        "BIN_WRITER/lib/AS_bin_writer_wrapper.cpp",
        "BIN_WRITER/lib/binary_writer_lib.cpp",
    ],
    hdrs = [
        "BIN_WRITER/lib/AS_bin_writer_wrapper.h",
        "BIN_WRITER/lib/AS_bin_writer_wrapper_plainC.h",
        "BIN_WRITER/lib/binary_writer_lib.h",
        "BIN_WRITER/lib/binary_writer_lib_sizes.h",
    ],
    includes = ["BIN_WRITER/lib"],
    visibility = ["//visibility:public"],
    deps = [":as_bin_writer_lib_export_h"],
)

cc_library(
    name = "as_bin_writer_wrapper_h",
    hdrs = ["BIN_WRITER/lib/AS_bin_writer_wrapper.h"],
    includes = ["BIN_WRITER/lib"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "as_bin_writer_lib_export_h",
    hdrs = ["BIN_WRITER/ports/visualC12/as-bin-writer-lib_export.h"],
    includes = ["BIN_WRITER/ports/visualC12"],
    visibility = ["//visibility:public"],
)

# Start of Calibration_Tool module
cc_library(
    name = "cal_tool_c_src_h",
    hdrs = [
        "Calibration_Tool/c_src/ct_boundaries_check_function_helpers.h",
        "Calibration_Tool/c_src/ct_calibration_header_t.h",
        "Calibration_Tool/c_src/ct_endianness_switch.h",
    ],
    includes = ["Calibration_Tool/c_src"],
    visibility = ["//visibility:public"],
    deps = ["@math_library_bb//:ml_reuse_h"],
)

cc_library(
    name = "cal_tool_lib",
    srcs = [
        "Calibration_Tool/c_src/ct_boundaries_check_function_helpers.c",
        "Calibration_Tool/c_src/ct_endianness_switch.c",
    ],
    features = ["-lto"],
    includes = ["Calibration_Tool/c_src"],
    visibility = ["//visibility:public"],
    deps = [":cal_tool_c_src_h"],
)
# End of Calibration_Tool module

# Start of Feature_Building_Kit module
cc_library(
    name = "fbk_cal_core_h",
    hdrs = [
        "Feature_Building_Kit/Calibration/Feature_Building_Kit_Core/fbk_core_calibration.h",
        "Feature_Building_Kit/Calibration/Feature_Building_Kit_Core/fbk_core_calibration_check.h",
        "Feature_Building_Kit/Calibration/Feature_Building_Kit_Core/fbk_core_calibration_t.h",
    ],
    includes = ["Feature_Building_Kit/Calibration/Feature_Building_Kit_Core"],
    visibility = ["//visibility:public"],
    deps = [":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h"],
)

cc_library(
    name = "fbk_cal_generic_h",
    srcs = [],
    hdrs = [
        "Feature_Building_Kit/Calibration/Generic/fbk_customer_calibration.h",
        "Feature_Building_Kit/Calibration/Generic/fbk_customer_calibration_check.h",
        "Feature_Building_Kit/Calibration/Generic/fbk_customer_calibration_t.h",
        "Feature_Building_Kit/Calibration/Generic/fbk_public_calibration.h",
        "Feature_Building_Kit/Calibration/Generic/fbk_public_calibration_check.h",
        "Feature_Building_Kit/Calibration/Generic/fbk_public_calibration_t.h",
        "Feature_Building_Kit/Calibration/Generic/fbk_update_calibration.h",
    ],
    includes = ["Feature_Building_Kit/Calibration/Generic"],
    visibility = ["//visibility:public"],
    deps = [
        ":cal_tool_c_src_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_cal_core_h",
        "@math_library_bb//:ml_reuse_h",
    ],
)

cc_library(
    name = "fbk_Interface_ego_traj_pred_instance_h",
    hdrs = ["Feature_Building_Kit/Interface/fbk_ego_traj_predictor_instance.h"],
    includes = ["Feature_Building_Kit/Interface"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Interface_iface_types_h",
        ":fbk_shared_ff_trajectory_prediction_h",
    ],
)

cc_library(
    name = "fbk_Interface_h",
    hdrs = [
        "Feature_Building_Kit/Interface/fbk_iface.h",
        "Feature_Building_Kit/Interface/fbk_instance.h",
        "Feature_Building_Kit/Interface/fbk_output.h",
        "Feature_Building_Kit/Interface/sfl_status.h",
    ],
    includes = ["Feature_Building_Kit/Interface"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Interface_ego_traj_pred_instance_h",
        ":fbk_Interface_host_trail_h",
        ":fbk_Interface_iface_types_h",
        ":fbk_Interface_index_lookup_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_h",
        ":fbk_Platform_Abstraction_Layer_h",
        ":fbk_cal_core_h",
        ":fbk_shared_ff_h",
    ],
)

cc_library(
    name = "fbk_Interface_iface_types_h",
    hdrs = ["Feature_Building_Kit/Interface/fbk_iface_types.h"],
    includes = ["Feature_Building_Kit/Interface"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_Platform_Abstraction_Layer_pa_shrd_types_h",
        "@math_library_bb//:ml_core_lib",
    ],
)

cc_library(
    name = "fbk_Interface_boundaries_h",
    hdrs = ["Feature_Building_Kit/Interface/boundaries/fbk_output_boundary_check.h"],
    includes = ["Feature_Building_Kit/Interface/boundaries"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Interface_h",
        ":fbk_Interface_iface_types_h",
        ":fbk_Interface_index_lookup_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
    ],
)

cc_library(
    name = "fbk_Interface_debug_writer_h",
    hdrs = [
        "Feature_Building_Kit/Interface/debug_writer/fbk_debug_interface.h",
        "Feature_Building_Kit/Interface/debug_writer/fbk_debug_writer.h",
    ],
    includes = ["Feature_Building_Kit/Interface/debug_writer"],
    visibility = ["//visibility:public"],
    deps = select({
        "//conditions:default": [":as_bin_writer_wrapper_mock_h"],
    }),
)

cc_library(
    name = "fbk_Interface_fill_pa_data_h",
    hdrs = ["Feature_Building_Kit/Interface/fill_pa_data/fbk_fill_pa_data.h"],
    includes = ["Feature_Building_Kit/Interface/fill_pa_data"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Platform_Abstraction_Layer_generic_inc_h",
        ":fbk_Platform_Abstraction_Layer_h",
    ],
)

cc_library(
    name = "fbk_Interface_host_trail_h",
    hdrs = ["Feature_Building_Kit/Interface/host_trail/fbk_host_trail.h"],
    defines = ["PA_OBJ_NUMBER_OF_OBJECTS=64"],
    includes = ["Feature_Building_Kit/Interface/host_trail"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Interface_iface_types_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_Platform_Abstraction_Layer_h",
        ":fbk_cal_core_h",
        "@math_library_bb//:ml_core_lib",
    ],
)

cc_library(
    name = "fbk_Interface_index_lookup_h",
    hdrs = ["Feature_Building_Kit/Interface/index_lookup/fbk_index_lookup.h"],
    includes = ["Feature_Building_Kit/Interface/index_lookup"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_Platform_Abstraction_Layer_h",
        ":fbk_shared_ff_h",
    ],
)

cc_library(
    name = "fbk_Interface_object_ageing_h",
    hdrs = ["Feature_Building_Kit/Interface/object_ageing/fbk_obj_ageing.h"],
    includes = ["Feature_Building_Kit/Interface/object_ageing"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Interface_h",
        ":fbk_Interface_iface_types_h",
        ":fbk_Platform_Abstraction_Layer_h",
    ],
)

cc_library(
    name = "fbk_Platform_Abstraction_Layer_generic_inc_h",
    hdrs = ["Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/pa_context.h"],
    defines = [
        "PLATFORM_INTERFACE_USED",
        "boolean_T=uint8_t",
        "float32_T=float32_t",
    ],
    includes = ["Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc"],
    visibility = ["//visibility:public"],
    deps = [":fbk_Platform_Abstraction_Layer_h"],
)

cc_library(
    name = "fbk_Platform_Abstraction_Layer_generic_inc_data_ports_h",
    hdrs = [
        "Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports/pa_const_macros.h",
        "Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports/pa_env_in.h",
        "Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports/pa_obj_in.h",
        "Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports/pa_vehicle_in.h",
    ],
    defines = ["PA_OBJ_NUMBER_OF_OBJECTS=64"],
    includes = ["Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports"],
    visibility = ["//visibility:public"],
    deps = [":fbk_Platform_Abstraction_Layer_generic_inc_h"],
)

cc_library(
    name = "fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
    hdrs = ["Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports/pa_reuse.h"],
    includes = ["Feature_Building_Kit/Platform_Abstraction_Layer/Generic/inc/data_ports"],
    visibility = ["//visibility:public"],
    deps = ["@math_library_bb//:ml_reuse_h"],
)

cc_library(
    name = "fbk_Platform_Abstraction_Layer_h",
    hdrs = [
        "Feature_Building_Kit/Platform_Abstraction_Layer/pa_data.h",
        "Feature_Building_Kit/Platform_Abstraction_Layer/pa_mock_functions.h",
    ],
    includes = ["Feature_Building_Kit/Platform_Abstraction_Layer"],
    visibility = ["//visibility:public"],
    deps = [":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h"],
)

cc_library(
    name = "fbk_shared_ff_reference_point_h",
    hdrs = [
        "Feature_Building_Kit/Shared_Feature_Functions/reference_point/fbk_ref_point.h",
        "Feature_Building_Kit/Shared_Feature_Functions/reference_point/fbk_ref_point_calc.h",
    ],
    includes = ["Feature_Building_Kit/Shared_Feature_Functions/reference_point"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        "@math_library_bb//:ml_core_lib",
    ],
)

cc_library(
    name = "fbk_Platform_Abstraction_Layer_pa_shrd_types_h",
    hdrs = ["Feature_Building_Kit/Platform_Abstraction_Layer/pa_shared_types.h"],
    includes = ["Feature_Building_Kit/Platform_Abstraction_Layer"],
    visibility = ["//visibility:public"],
    deps = [":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h"],
)

cc_library(
    name = "fbk_shared_ff_interpolation_h",
    hdrs = ["Feature_Building_Kit/Shared_Feature_Functions/interpolation/fbk_array_interpolation.h"],
    includes = ["Feature_Building_Kit/Shared_Feature_Functions/interpolation"],
    visibility = ["//visibility:public"],
    deps = [":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h"],
)

cc_library(
    name = "fbk_shared_ff_trajectory_prediction_h",
    hdrs = [
        "Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction/fbk_circular_shape_calculator.h",
        "Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction/fbk_ego_traj_predictor.h",
        "Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction/fbk_obj_traj_predictor.h",
    ],
    includes = ["Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_shared_ff_h",
        ":fbk_shared_ff_validation_data_h",
    ],
)

cc_library(
    name = "fbk_shared_ff_trajectory_prediction_traj_predictor_h",
    hdrs = ["Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction/fbk_traj_predictor_t.h"],
    includes = ["Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_h",
        ":fbk_shared_ff_h",
        ":fbk_shared_ff_validation_data_h",
        "@math_library_bb//:ml_core_lib",
    ],
)

cc_library(
    name = "fbk_shared_ff_validation_h",
    hdrs = [
        "Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_guardrail_validation.h",
        "Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_object_validation.h",
        "Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_vehicle_validation.h",
    ],
    includes = ["Feature_Building_Kit/Shared_Feature_Functions/validation"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_h",
        ":fbk_shared_ff_validation_data_h",
    ],
)

cc_library(
    name = "fbk_shared_ff_validation_data_h",
    hdrs = [
        "Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_object_data_t.h",
        "Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_vehicle_data_t.h",
    ],
    includes = ["Feature_Building_Kit/Shared_Feature_Functions/validation"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_Platform_Abstraction_Layer_pa_shrd_types_h",
        "@math_library_bb//:ml_core_lib",
    ],
)

cc_library(
    name = "fbk_shared_ff_zone_h",
    hdrs = [
        "Feature_Building_Kit/Shared_Feature_Functions/zone/fbk_field_of_interest.h",
        "Feature_Building_Kit/Shared_Feature_Functions/zone/fbk_field_of_interest_factory.h",
    ],
    includes = ["Feature_Building_Kit/Shared_Feature_Functions/zone"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        "@math_library_bb//:ml_core_lib",
    ],
)

cc_library(
    name = "fbk_shared_ff_h",
    hdrs = [
        "Feature_Building_Kit/Shared_Feature_Functions/fbk_functions.h",
        "Feature_Building_Kit/Shared_Feature_Functions/fbk_macros.h",
    ],
    includes = ["Feature_Building_Kit/Shared_Feature_Functions"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        "@math_library_bb//:ml_core_lib",
    ],
)

cc_library(
    name = "fbk_lib",
    srcs = [
        "Feature_Building_Kit/Calibration/Feature_Building_Kit_Core/fbk_core_calibration_check.c",
        "Feature_Building_Kit/Calibration/Feature_Building_Kit_Core/fbk_core_calibration_print_functions.c",
        "Feature_Building_Kit/Calibration/Generic/fbk_core_calibration.c",
        "Feature_Building_Kit/Calibration/Generic/fbk_customer_calibration.c",
        "Feature_Building_Kit/Calibration/Generic/fbk_customer_calibration_check.c",
        "Feature_Building_Kit/Calibration/Generic/fbk_customer_calibration_print_functions.c",
        "Feature_Building_Kit/Calibration/Generic/fbk_public_calibration.c",
        "Feature_Building_Kit/Calibration/Generic/fbk_public_calibration_check.c",
        "Feature_Building_Kit/Calibration/Generic/fbk_public_calibration_print_functions.c",
        "Feature_Building_Kit/Calibration/Generic/fbk_update_calibration.c",
        "Feature_Building_Kit/Interface/boundaries/fbk_output_boundary_check.c",
        "Feature_Building_Kit/Interface/debug_writer/fbk_debug_interface.c",
        "Feature_Building_Kit/Interface/debug_writer/fbk_debug_writer.c",
        "Feature_Building_Kit/Interface/fbk_iface.c",
        "Feature_Building_Kit/Interface/fill_pa_data/fbk_fill_pa_data.c",
        "Feature_Building_Kit/Interface/host_trail/fbk_host_trail.c",
        "Feature_Building_Kit/Interface/index_lookup/fbk_index_lookup.c",
        "Feature_Building_Kit/Interface/object_ageing/fbk_obj_ageing.c",
        "Feature_Building_Kit/Shared_Feature_Functions/fbk_functions.c",
        "Feature_Building_Kit/Shared_Feature_Functions/interpolation/fbk_array_interpolation.c",
        "Feature_Building_Kit/Shared_Feature_Functions/reference_point/fbk_ref_point_calc.c",
        "Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction/fbk_circular_shape_calculator.c",
        "Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction/fbk_ego_traj_predictor.c",
        "Feature_Building_Kit/Shared_Feature_Functions/trajectory_prediction/fbk_obj_traj_predictor.c",
        "Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_guardrail_validation.c",
        "Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_object_validation.c",
        "Feature_Building_Kit/Shared_Feature_Functions/validation/fbk_vehicle_validation.c",
        "Feature_Building_Kit/Shared_Feature_Functions/zone/fbk_field_of_interest_factory.c",
    ],
    defines = [
        "PA_OBJ_NUMBER_OF_OBJECTS=64",
        "PA_Generic",
    ],
    features = ["-lto"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Interface_boundaries_h",
        ":fbk_Interface_debug_writer_h",
        ":fbk_Interface_ego_traj_pred_instance_h",
        ":fbk_Interface_fill_pa_data_h",
        ":fbk_Interface_h",
        ":fbk_Interface_host_trail_h",
        ":fbk_Interface_iface_types_h",
        ":fbk_Interface_index_lookup_h",
        ":fbk_Interface_object_ageing_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_h",
        ":fbk_Platform_Abstraction_Layer_h",
        ":fbk_Platform_Abstraction_Layer_pa_shrd_types_h",
        ":fbk_cal_core_h",
        ":fbk_cal_generic_h",
        ":fbk_shared_ff_h",
        ":fbk_shared_ff_interpolation_h",
        ":fbk_shared_ff_reference_point_h",
        ":fbk_shared_ff_trajectory_prediction_h",
        ":fbk_shared_ff_trajectory_prediction_traj_predictor_h",
        ":fbk_shared_ff_validation_data_h",
        ":fbk_shared_ff_validation_h",
        ":fbk_shared_ff_zone_h",
        "@math_library_bb//:ml_core_lib",
    ],
)
# End of Feature_Building_Kit module

# Start of BSIS module
cc_library(
    name = "bsis_cal_core_h",
    hdrs = [
        "BSIS/Calibration/BSIS_Core/bsis_core_calibration.h",
        "BSIS/Calibration/BSIS_Core/bsis_core_calibration_check.h",
        "BSIS/Calibration/BSIS_Core/bsis_core_calibration_t.h",
    ],
    includes = ["BSIS/Calibration/BSIS_Core"],
    visibility = ["//visibility:public"],
    deps = [
        ":cal_tool_c_src_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
    ],
)

cc_library(
    name = "bsis_cal_generic_h",
    hdrs = [
        "BSIS/Calibration/Generic/bsis_customer_calibration.h",
        "BSIS/Calibration/Generic/bsis_customer_calibration_check.h",
        "BSIS/Calibration/Generic/bsis_customer_calibration_t.h",
        "BSIS/Calibration/Generic/bsis_public_calibration.h",
        "BSIS/Calibration/Generic/bsis_public_calibration_check.h",
        "BSIS/Calibration/Generic/bsis_public_calibration_t.h",
        "BSIS/Calibration/Generic/bsis_update_calibration.h",
    ],
    includes = ["BSIS/Calibration/Generic"],
    visibility = ["//visibility:public"],
    deps = [
        ":cal_tool_c_src_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
    ],
)

cc_library(
    name = "bsis_customer_adapter_h",
    hdrs = [
        "BSIS/Customer_Adapter/bsis_post_run.h",
        "BSIS/Customer_Adapter/bsis_pre_run.h",
    ],
    includes = ["BSIS/Customer_Adapter"],
    visibility = ["//visibility:public"],
    deps = [
        ":bsis_cal_core_h",
        ":bsis_cal_generic_h",
    ],
)

cc_library(
    name = "bsis_customer_adapter_generic_h",
    hdrs = [
        "BSIS/Customer_Adapter/Generic/bsis_input_t.h",
        "BSIS/Customer_Adapter/Generic/bsis_output_t.h",
    ],
    includes = ["BSIS/Customer_Adapter/Generic"],
    visibility = ["//visibility:public"],
    deps = [
        ":bsis_cal_core_h",
        ":bsis_cal_generic_h",
        ":bsis_customer_adapter_h",
        ":bsis_source_bsis_instance_t_h",
        ":bsis_source_bsis_types_h",
    ],
)

cc_library(
    name = "bsis_source_bsis_types_h",
    hdrs = ["BSIS/Source/bsis_types.h"],
    includes = ["BSIS/Source"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Interface_boundaries_h",
        ":fbk_Interface_debug_writer_h",
        ":fbk_Interface_ego_traj_pred_instance_h",
        ":fbk_Interface_fill_pa_data_h",
        ":fbk_Interface_h",
        ":fbk_Interface_host_trail_h",
        ":fbk_Interface_iface_types_h",
        ":fbk_Interface_index_lookup_h",
        ":fbk_Interface_object_ageing_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_h",
        ":fbk_Platform_Abstraction_Layer_h",
        ":fbk_Platform_Abstraction_Layer_pa_shrd_types_h",
        ":fbk_cal_core_h",
        ":fbk_cal_generic_h",
        ":fbk_shared_ff_h",
        ":fbk_shared_ff_interpolation_h",
        ":fbk_shared_ff_reference_point_h",
        ":fbk_shared_ff_trajectory_prediction_h",
        ":fbk_shared_ff_trajectory_prediction_traj_predictor_h",
        ":fbk_shared_ff_validation_data_h",
        ":fbk_shared_ff_validation_h",
        ":fbk_shared_ff_zone_h",
        "@math_library_bb//:ml_core_lib",
    ],
)

cc_library(
    name = "bsis_source_bsis_instance_t_h",
    hdrs = ["BSIS/Source/bsis_instance_t.h"],
    includes = ["BSIS/Source"],
    visibility = ["//visibility:public"],
    deps = [
        ":bsis_cal_core_h",
        ":bsis_cal_generic_h",
        ":bsis_source_input_output_perst_h",
        "@math_library_bb//:ml_core_lib",
    ],
)

cc_library(
    name = "bsis_source_h",
    hdrs = [
        "BSIS/Source/bsis.h",
        "BSIS/Source/bsis_collision_prediction.h",
        "BSIS/Source/bsis_debug_interface.h",
        "BSIS/Source/bsis_debug_writer.h",
        "BSIS/Source/bsis_iface.h",
        "BSIS/Source/bsis_instance_t.h",
        "BSIS/Source/bsis_output_debouncer.h",
    ],
    includes = ["BSIS/Source"],
    visibility = ["//visibility:public"],
    deps = [
        ":bsis_cal_core_h",
        ":bsis_cal_generic_h",
        ":bsis_customer_adapter_generic_h",
        ":bsis_customer_adapter_h",
        ":bsis_source_bsis_types_h",
        ":bsis_source_input_output_perst_h",
        ":fbk_Interface_boundaries_h",
        ":fbk_Interface_debug_writer_h",
        ":fbk_Interface_ego_traj_pred_instance_h",
        ":fbk_Interface_fill_pa_data_h",
        ":fbk_Interface_h",
        ":fbk_Interface_host_trail_h",
        ":fbk_Interface_iface_types_h",
        ":fbk_Interface_index_lookup_h",
        ":fbk_Interface_object_ageing_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_h",
        ":fbk_Platform_Abstraction_Layer_h",
        ":fbk_Platform_Abstraction_Layer_pa_shrd_types_h",
        ":fbk_cal_core_h",
        ":fbk_cal_generic_h",
        ":fbk_shared_ff_h",
        ":fbk_shared_ff_interpolation_h",
        ":fbk_shared_ff_reference_point_h",
        ":fbk_shared_ff_trajectory_prediction_h",
        ":fbk_shared_ff_trajectory_prediction_traj_predictor_h",
        ":fbk_shared_ff_validation_data_h",
        ":fbk_shared_ff_validation_h",
        ":fbk_shared_ff_zone_h",
    ],
)

cc_library(
    name = "bsis_source_input_output_perst_h",
    hdrs = [
        "BSIS/Source/bsis_core_input_t.h",
        "BSIS/Source/bsis_core_output_t.h",
        "BSIS/Source/bsis_persistent_t.h",
    ],
    includes = ["BSIS/Source"],
    visibility = ["//visibility:public"],
    deps = [
        ":bsis_source_bsis_types_h",
        ":fbk_Interface_boundaries_h",
        ":fbk_Interface_debug_writer_h",
        ":fbk_Interface_ego_traj_pred_instance_h",
        ":fbk_Interface_fill_pa_data_h",
        ":fbk_Interface_h",
        ":fbk_Interface_host_trail_h",
        ":fbk_Interface_iface_types_h",
        ":fbk_Interface_index_lookup_h",
        ":fbk_Interface_object_ageing_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_h",
        ":fbk_Platform_Abstraction_Layer_h",
        ":fbk_Platform_Abstraction_Layer_pa_shrd_types_h",
        ":fbk_cal_core_h",
        ":fbk_cal_generic_h",
        ":fbk_shared_ff_h",
        ":fbk_shared_ff_interpolation_h",
        ":fbk_shared_ff_reference_point_h",
        ":fbk_shared_ff_trajectory_prediction_h",
        ":fbk_shared_ff_trajectory_prediction_traj_predictor_h",
        ":fbk_shared_ff_validation_data_h",
        ":fbk_shared_ff_validation_h",
        ":fbk_shared_ff_zone_h",
    ],
)

cc_library(
    name = "bsis_debug_writer_h",
    hdrs = ["BSIS/Source/bsis_debug_writer.h"],
    includes = ["BSIS/Source"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "bsis_lib",
    srcs = [
        "BSIS/Calibration/BSIS_Core/bsis_core_calibration_check.c",
        "BSIS/Calibration/BSIS_Core/bsis_core_calibration_print_functions.c",
        "BSIS/Calibration/Generic/bsis_core_calibration.c",
        "BSIS/Calibration/Generic/bsis_customer_calibration.c",
        "BSIS/Calibration/Generic/bsis_customer_calibration_check.c",
        "BSIS/Calibration/Generic/bsis_customer_calibration_print_functions.c",
        "BSIS/Calibration/Generic/bsis_public_calibration.c",
        "BSIS/Calibration/Generic/bsis_public_calibration_check.c",
        "BSIS/Calibration/Generic/bsis_public_calibration_print_functions.c",
        "BSIS/Calibration/Generic/bsis_update_calibration.c",
        "BSIS/Customer_Adapter/Generic/bsis_post_run.c",
        "BSIS/Customer_Adapter/Generic/bsis_pre_run.c",
        "BSIS/Source/bsis.c",
        "BSIS/Source/bsis_collision_prediction.c",
        "BSIS/Source/bsis_debug_interface.c",
        "BSIS/Source/bsis_debug_writer.c",
        "BSIS/Source/bsis_iface.c",
        "BSIS/Source/bsis_output_debouncer.c",
    ],
    copts = [
        "-Wno-unused-parameter",
    ],
    defines = ["PA_OBJ_NUMBER_OF_OBJECTS=64"],
    features = ["-lto"],
    visibility = ["//visibility:public"],
    deps = [
        ":bsis_cal_core_h",
        ":bsis_cal_generic_h",
        ":bsis_customer_adapter_generic_h",
        ":bsis_customer_adapter_h",
        ":bsis_debug_writer_h",
        ":bsis_source_bsis_instance_t_h",
        ":bsis_source_bsis_types_h",
        ":bsis_source_h",
        ":bsis_source_input_output_perst_h",
        "@math_library_bb//:ml_core_lib",
    ],
)
# End of BSIS module

# Start of MOIS module
cc_library(
    name = "mois_cal_core_h",
    hdrs = [
        "MOIS/Calibration/MOIS_Core/mois_core_calibration.h",
        "MOIS/Calibration/MOIS_Core/mois_core_calibration_check.h",
        "MOIS/Calibration/MOIS_Core/mois_core_calibration_t.h",
    ],
    includes = ["MOIS/Calibration/MOIS_Core"],
    visibility = ["//visibility:public"],
    deps = [
        ":cal_tool_c_src_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
    ],
)

cc_library(
    name = "mois_cal_generic_h",
    hdrs = [
        "MOIS/Calibration/Generic/mois_customer_calibration.h",
        "MOIS/Calibration/Generic/mois_customer_calibration_check.h",
        "MOIS/Calibration/Generic/mois_customer_calibration_t.h",
        "MOIS/Calibration/Generic/mois_public_calibration.h",
        "MOIS/Calibration/Generic/mois_public_calibration_check.h",
        "MOIS/Calibration/Generic/mois_public_calibration_t.h",
        "MOIS/Calibration/Generic/mois_update_calibration.h",
    ],
    includes = ["MOIS/Calibration/Generic"],
    visibility = ["//visibility:public"],
    deps = [
        ":cal_tool_c_src_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
    ],
)

cc_library(
    name = "mois_customer_adapter_h",
    hdrs = [
        "MOIS/Customer_Adapter/mois_post_run.h",
        "MOIS/Customer_Adapter/mois_pre_run.h",
    ],
    includes = ["MOIS/Customer_Adapter"],
    visibility = ["//visibility:public"],
    deps = [
        ":mois_cal_core_h",
        ":mois_cal_generic_h",
    ],
)

cc_library(
    name = "mois_customer_adapter_generic_h",
    hdrs = [
        "MOIS/Customer_Adapter/Generic/mois_input_t.h",
        "MOIS/Customer_Adapter/Generic/mois_output_t.h",
    ],
    includes = ["MOIS/Customer_Adapter/Generic"],
    visibility = ["//visibility:public"],
    deps = [
        ":mois_cal_core_h",
        ":mois_cal_generic_h",
        ":mois_customer_adapter_h",
        ":mois_source_mois_instance_h",
        ":mois_source_mois_types_h",
    ],
)

cc_library(
    name = "mois_source_mois_types_h",
    hdrs = ["MOIS/Source/mois_types.h"],
    includes = ["MOIS/Source"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Interface_boundaries_h",
        ":fbk_Interface_debug_writer_h",
        ":fbk_Interface_ego_traj_pred_instance_h",
        ":fbk_Interface_fill_pa_data_h",
        ":fbk_Interface_h",
        ":fbk_Interface_host_trail_h",
        ":fbk_Interface_iface_types_h",
        ":fbk_Interface_index_lookup_h",
        ":fbk_Interface_object_ageing_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_h",
        ":fbk_Platform_Abstraction_Layer_h",
        ":fbk_Platform_Abstraction_Layer_pa_shrd_types_h",
        ":fbk_cal_core_h",
        ":fbk_cal_generic_h",
        ":fbk_shared_ff_h",
        ":fbk_shared_ff_interpolation_h",
        ":fbk_shared_ff_reference_point_h",
        ":fbk_shared_ff_trajectory_prediction_h",
        ":fbk_shared_ff_trajectory_prediction_traj_predictor_h",
        ":fbk_shared_ff_validation_data_h",
        ":fbk_shared_ff_validation_h",
        ":fbk_shared_ff_zone_h",
        "@math_library_bb//:ml_core_lib",
    ],
)

cc_library(
    name = "mois_source_mois_instance_h",
    hdrs = ["MOIS/Source/mois_instance.h"],
    includes = ["MOIS/Source"],
    visibility = ["//visibility:public"],
    deps = [
        ":mois_cal_core_h",
        ":mois_cal_generic_h",
        ":mois_source_input_output_perst_h",
        "@math_library_bb//:ml_core_lib",
    ],
)

cc_library(
    name = "mois_source_h",
    hdrs = [
        "MOIS/Source/mois.h",
        "MOIS/Source/mois_debug_interface.h",
        "MOIS/Source/mois_debug_writer.h",
        "MOIS/Source/mois_iface.h",
        "MOIS/Source/mois_instance.h",
        "MOIS/Source/mois_object.h",
        "MOIS/Source/mois_output_debouncer.h",
        "MOIS/Source/mois_persistent.h",
        "MOIS/Source/mois_zone.h",
    ],
    includes = ["MOIS/Source"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Interface_boundaries_h",
        ":fbk_Interface_debug_writer_h",
        ":fbk_Interface_ego_traj_pred_instance_h",
        ":fbk_Interface_fill_pa_data_h",
        ":fbk_Interface_h",
        ":fbk_Interface_host_trail_h",
        ":fbk_Interface_iface_types_h",
        ":fbk_Interface_index_lookup_h",
        ":fbk_Interface_object_ageing_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_h",
        ":fbk_Platform_Abstraction_Layer_h",
        ":fbk_Platform_Abstraction_Layer_pa_shrd_types_h",
        ":fbk_cal_core_h",
        ":fbk_cal_generic_h",
        ":fbk_shared_ff_h",
        ":fbk_shared_ff_interpolation_h",
        ":fbk_shared_ff_reference_point_h",
        ":fbk_shared_ff_trajectory_prediction_h",
        ":fbk_shared_ff_trajectory_prediction_traj_predictor_h",
        ":fbk_shared_ff_validation_data_h",
        ":fbk_shared_ff_validation_h",
        ":fbk_shared_ff_zone_h",
        ":mois_cal_core_h",
        ":mois_cal_generic_h",
        ":mois_customer_adapter_generic_h",
        ":mois_customer_adapter_h",
        ":mois_source_input_output_perst_h",
        ":mois_source_mois_types_h",
    ],
)

cc_library(
    name = "mois_source_input_output_perst_h",
    hdrs = [
        "MOIS/Source/mois_core_input_t.h",
        "MOIS/Source/mois_core_output_t.h",
        "MOIS/Source/mois_persistent.h",
    ],
    includes = ["MOIS/Source"],
    visibility = ["//visibility:public"],
    deps = [
        ":fbk_Interface_boundaries_h",
        ":fbk_Interface_debug_writer_h",
        ":fbk_Interface_ego_traj_pred_instance_h",
        ":fbk_Interface_fill_pa_data_h",
        ":fbk_Interface_h",
        ":fbk_Interface_host_trail_h",
        ":fbk_Interface_iface_types_h",
        ":fbk_Interface_index_lookup_h",
        ":fbk_Interface_object_ageing_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        ":fbk_Platform_Abstraction_Layer_generic_inc_h",
        ":fbk_Platform_Abstraction_Layer_h",
        ":fbk_Platform_Abstraction_Layer_pa_shrd_types_h",
        ":fbk_cal_core_h",
        ":fbk_cal_generic_h",
        ":fbk_shared_ff_h",
        ":fbk_shared_ff_interpolation_h",
        ":fbk_shared_ff_reference_point_h",
        ":fbk_shared_ff_trajectory_prediction_h",
        ":fbk_shared_ff_trajectory_prediction_traj_predictor_h",
        ":fbk_shared_ff_validation_data_h",
        ":fbk_shared_ff_validation_h",
        ":fbk_shared_ff_zone_h",
        ":mois_source_mois_types_h",
    ],
)

cc_library(
    name = "mois_debug_writer_h",
    hdrs = ["MOIS/Source/mois_debug_writer.h"],
    includes = ["MOIS/Source"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "mois_lib",
    srcs = [
        "MOIS/Calibration/Generic/mois_core_calibration.c",
        "MOIS/Calibration/Generic/mois_customer_calibration.c",
        "MOIS/Calibration/Generic/mois_customer_calibration_check.c",
        "MOIS/Calibration/Generic/mois_customer_calibration_print_functions.c",
        "MOIS/Calibration/Generic/mois_public_calibration.c",
        "MOIS/Calibration/Generic/mois_public_calibration_check.c",
        "MOIS/Calibration/Generic/mois_public_calibration_print_functions.c",
        "MOIS/Calibration/Generic/mois_update_calibration.c",
        "MOIS/Calibration/MOIS_Core/mois_core_calibration_check.c",
        "MOIS/Calibration/MOIS_Core/mois_core_calibration_print_functions.c",
        "MOIS/Customer_Adapter/Generic/mois_post_run.c",
        "MOIS/Customer_Adapter/Generic/mois_pre_run.c",
        "MOIS/Source/mois.c",
        "MOIS/Source/mois_debug_interface.c",
        "MOIS/Source/mois_debug_writer.c",
        "MOIS/Source/mois_iface.c",
        "MOIS/Source/mois_object.c",
        "MOIS/Source/mois_output_debouncer.c",
        "MOIS/Source/mois_persistent.c",
        "MOIS/Source/mois_zone.c",
    ],
    copts = [
        "-Wno-unused-parameter",
    ],
    defines = ["PA_OBJ_NUMBER_OF_OBJECTS=64"],
    features = ["-lto"],
    visibility = ["//visibility:public"],
    deps = [
        ":mois_cal_core_h",
        ":mois_cal_generic_h",
        ":mois_customer_adapter_generic_h",
        ":mois_customer_adapter_h",
        ":mois_debug_writer_h",
        ":mois_source_h",
        ":mois_source_input_output_perst_h",
        ":mois_source_mois_instance_h",
        ":mois_source_mois_types_h",
        "@math_library_bb//:ml_core_lib",
    ],
)
# End of MOIS module
