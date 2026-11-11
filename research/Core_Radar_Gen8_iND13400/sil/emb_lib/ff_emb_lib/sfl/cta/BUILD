cc_library(
    name = "cta_iface",
    srcs = [
        "@sfl//:CTA/Source/cta.c",
        "@sfl//:CTA/Source/cta.h",
        "@sfl//:CTA/Source/cta_iface.c",
    ],
    hdrs = ["@sfl//:CTA/Source/cta_iface.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_braking_logic",
        ":cta_calibration",
        ":cta_calibration_t",
        ":cta_common_functions",
        ":cta_conflict_zone_adapter",
        ":cta_counters",
        ":cta_criticality_level_calculation",
        ":cta_debug_interface",
        ":cta_factory",
        ":cta_io_t",
        ":cta_object_validator",
        ":cta_post_run",
        ":cta_pre_run",
        ":cta_struct_initializer",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/pt:pt_iface",
    ],
)

cc_library(
    name = "cta_post_run",
    srcs = ["@sfl//:CTA/Customer_Adapter/Generic/cta_post_run.c"],
    hdrs = ["@sfl//:CTA/Customer_Adapter/cta_post_run.h"],
    strip_include_prefix = "/CTA/Customer_Adapter",
    deps = [
        ":cta_instance",
        ":cta_io_t",
    ],
)

cc_library(
    name = "cta_pre_run",
    srcs = ["@sfl//:CTA/Customer_Adapter/Generic/cta_pre_run.c"],
    hdrs = ["@sfl//:CTA/Customer_Adapter/cta_pre_run.h"],
    strip_include_prefix = "/CTA/Customer_Adapter",
    deps = [
        ":cta_instance",
        ":cta_io_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
    ],
)

cc_library(
    name = "cta_common_functions",
    srcs = ["@sfl//:CTA/Source/cta_common_functions.c"],
    hdrs = ["@sfl//:CTA/Source/cta_common_functions.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_calibration_t",
        ":cta_debug_interface_h",
        ":cta_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_ref_point",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "cta_debug_interface",
    srcs = ["@sfl//:CTA/Source/cta_debug_interface.c"],
    hdrs = ["@sfl//:CTA/Source/cta_debug_interface.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_calibration_t",
        ":cta_core_io",
        ":cta_debug_writer_h",
        ":cta_instance",
        ":cta_io_t",
        ":cta_persistent_t",
        ":cta_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "cta_debug_interface_h",
    hdrs = ["@sfl//:CTA/Source/cta_debug_interface.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_calibration_t",
        ":cta_core_io",
        ":cta_debug_writer_h",
        ":cta_instance",
        ":cta_io_t",
        ":cta_persistent_t",
        ":cta_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "cta_debug_writer",
    srcs = ["@sfl//:CTA/Source/cta_debug_writer.c"],
    hdrs = ["@sfl//:CTA/Source/cta_debug_writer.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_debug_interface",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
    ],
)

cc_library(
    name = "cta_debug_writer_h",
    hdrs = ["@sfl//:CTA/Source/cta_debug_writer.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "cta_instance",
    hdrs = ["@sfl//:CTA/Source/cta_instance.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_calibration_t",
        ":cta_core_io",
        ":cta_persistent_t",
    ],
)

cc_library(
    name = "cta_core_io",
    hdrs = [
        "@sfl//:CTA/Source/cta_core_input_t.h",
        "@sfl//:CTA/Source/cta_core_output_t.h",
    ],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
    ],
)

cc_library(
    name = "cta_types",
    hdrs = ["@sfl//:CTA/Source/cta_types.h"],
    strip_include_prefix = "/CTA/Source",
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
    name = "cta_persistent_t",
    hdrs = ["@sfl//:CTA/Source/cta_persistent_t.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "cta_calibration",
    srcs = [
        "@sfl//:CTA/Calibration/CTA_Core/cta_calibration_cal_check.c",
        "@sfl//:CTA/Calibration/CTA_Core/cta_calibration_print_functions.c",
        "@sfl//:CTA/Calibration/Generic/cta_calibration.c",
    ],
    hdrs = [
        "@sfl//:CTA/Calibration/CTA_Core/cta_calibration.h",
        "@sfl//:CTA/Calibration/CTA_Core/cta_calibration_cal_check.h",
    ],
    strip_include_prefix = "/CTA/Calibration/CTA_Core",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_calibration_t",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "cta_calibration_t",
    hdrs = ["@sfl//:CTA/Calibration/CTA_Core/cta_calibration_t.h"],
    strip_include_prefix = "/CTA/Calibration/CTA_Core",
    visibility = ["//visibility:public"],
    deps = ["//ff_emb_lib/sfl/calibration_tool:calibtool"],
)

cc_library(
    name = "cta_io_t",
    hdrs = [
        "@sfl//:CTA/Customer_Adapter/Generic/cta_input_t.h",
        "@sfl//:CTA/Customer_Adapter/Generic/cta_output_t.h",
    ],
    strip_include_prefix = "/CTA/Customer_Adapter/Generic",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_core_io",
        ":cta_types",
    ],
)

cc_library(
    name = "cta_braking_logic",
    srcs = ["@sfl//:CTA/Source/cta_braking_logic.c"],
    hdrs = ["@sfl//:CTA/Source/cta_braking_logic.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        "cta_common_functions",
        ":cta_calibration_t",
        ":cta_debug_interface",
        ":cta_debug_writer_h",
        ":cta_io_t",
        ":cta_persistent_t",
        ":cta_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_interpolation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "cta_conflict_zone_adapter",
    srcs = ["@sfl//:CTA/Source/cta_conflict_zone_adapter.c"],
    hdrs = ["@sfl//:CTA/Source/cta_conflict_zone_adapter.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_calibration_t",
        ":cta_io_t",
        ":cta_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_interpolation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "cta_counters",
    srcs = ["@sfl//:CTA/Source/cta_counters.c"],
    hdrs = ["@sfl//:CTA/Source/cta_counters.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_calibration_t",
        ":cta_debug_writer_h",
        ":cta_io_t",
        ":cta_persistent_t",
        ":cta_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "cta_criticality_level_calculation",
    srcs = ["@sfl//:CTA/Source/cta_criticality_level_calculation.c"],
    hdrs = ["@sfl//:CTA/Source/cta_criticality_level_calculation.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_calibration_t",
        ":cta_debug_writer_h",
        ":cta_io_t",
        ":cta_persistent_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "cta_factory",
    srcs = ["@sfl//:CTA/Source/cta_factory.c"],
    hdrs = ["@sfl//:CTA/Source/cta_factory.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_calibration_t",
        ":cta_core_io",
        ":cta_debug_writer_h",
        ":cta_instance",
        ":cta_io_t",
        ":cta_persistent_t",
        ":cta_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "cta_object_validator",
    srcs = ["@sfl//:CTA/Source/cta_object_validator.c"],
    hdrs = ["@sfl//:CTA/Source/cta_object_validator.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_calibration_t",
        ":cta_debug_interface",
        ":cta_io_t",
        ":cta_persistent_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "cta_struct_initializer",
    srcs = ["@sfl//:CTA/Source/cta_struct_initializer.c"],
    hdrs = ["@sfl//:CTA/Source/cta_struct_initializer.h"],
    strip_include_prefix = "/CTA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":cta_calibration_t",
        ":cta_core_io",
        ":cta_io_t",
        ":cta_persistent_t",
        ":cta_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)
