cc_library(
    name = "recw_iface",
    srcs = [
        "@sfl//:RECW/Source/recw.c",
        "@sfl//:RECW/Source/recw.h",
        "@sfl//:RECW/Source/recw_iface.c",
    ],
    hdrs = ["@sfl//:RECW/Source/recw_iface.h"],
    strip_include_prefix = "/RECW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":recw_calibration",
        ":recw_calibration_t",
        ":recw_car_wash_detection",
        ":recw_crash_prob_steer_brake",
        ":recw_debug_interface",
        ":recw_debug_writer",
        ":recw_instance",
        ":recw_io_t",
        ":recw_object_validator",
        ":recw_output_debouncer",
        ":recw_post_run",
        ":recw_pre_run",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
    ],
)

cc_library(
    name = "recw_post_run",
    srcs = ["@sfl//:RECW/Customer_Adapter/Generic/recw_post_run.c"],
    hdrs = ["@sfl//:RECW/Customer_Adapter/recw_post_run.h"],
    strip_include_prefix = "/RECW/Customer_Adapter",
    deps = [
        ":recw_core_io",
        ":recw_instance",
        ":recw_io_t",
    ],
)

cc_library(
    name = "recw_pre_run",
    srcs = ["@sfl//:RECW/Customer_Adapter/Generic/recw_pre_run.c"],
    hdrs = ["@sfl//:RECW/Customer_Adapter/recw_pre_run.h"],
    strip_include_prefix = "/RECW/Customer_Adapter",
    deps = [
        ":recw_instance",
        ":recw_io_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
    ],
)

cc_library(
    name = "recw_output_debouncer",
    srcs = ["@sfl//:RECW/Source/recw_output_debouncer.c"],
    hdrs = [
        "@sfl//:RECW/Source/recw.h",
        "@sfl//:RECW/Source/recw_output_debouncer.h",
    ],
    strip_include_prefix = "/RECW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":recw_calibration_t",
        ":recw_core_io",
        ":recw_persistent_t",
    ],
)

cc_library(
    name = "recw_object_validator",
    srcs = ["@sfl//:RECW/Source/recw_object_validator.c"],
    hdrs = ["@sfl//:RECW/Source/recw_object_validator.h"],
    strip_include_prefix = "/RECW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":recw_calibration_t",
        ":recw_car_wash_detection",
        ":recw_core_io",
        ":recw_persistent_t",
        ":recw_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_ref_point",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "recw_crash_prob_steer_brake",
    srcs = ["@sfl//:RECW/Source/recw_crash_prob_steer_brake.c"],
    hdrs = ["@sfl//:RECW/Source/recw_crash_prob_steer_brake.h"],
    strip_include_prefix = "/RECW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":recw_calibration_t",
        ":recw_core_io",
        ":recw_persistent_t",
        ":recw_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "recw_car_wash_detection",
    srcs = ["@sfl//:RECW/Source/recw_car_wash_detection.c"],
    hdrs = ["@sfl//:RECW/Source/recw_car_wash_detection.h"],
    strip_include_prefix = "/RECW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":recw_calibration_t",
        ":recw_core_io",
        ":recw_persistent_t",
        ":recw_types",
    ],
)

cc_library(
    name = "recw_debug_interface",
    srcs = ["@sfl//:RECW/Source/recw_debug_interface.c"],
    hdrs = ["@sfl//:RECW/Source/recw_debug_interface.h"],
    strip_include_prefix = "/RECW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":recw_calibration_t",
        ":recw_io_t",
        ":recw_persistent_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "recw_debug_writer",
    srcs = ["@sfl//:RECW/Source/recw_debug_writer.c"],
    hdrs = ["@sfl//:RECW/Source/recw_debug_writer.h"],
    strip_include_prefix = "/RECW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":recw_calibration_t",
        ":recw_debug_interface",
        ":recw_io_t",
        ":recw_persistent_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_fill_pa_data",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
    ],
)

cc_library(
    name = "recw_instance",
    hdrs = ["@sfl//:RECW/Source/recw_instance.h"],
    strip_include_prefix = "/RECW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":recw_calibration_t",
        ":recw_core_io",
        ":recw_persistent_t",
    ],
)

cc_library(
    name = "recw_core_io",
    hdrs = [
        "@sfl//:RECW/Source/recw_core_input_t.h",
        "@sfl//:RECW/Source/recw_core_output_t.h",
    ],
    strip_include_prefix = "/RECW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":recw_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
    ],
)

cc_library(
    name = "recw_types",
    hdrs = ["@sfl//:RECW/Source/recw_types.h"],
    strip_include_prefix = "/RECW/Source",
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
    name = "recw_persistent_t",
    hdrs = ["@sfl//:RECW/Source/recw_persistent_t.h"],
    strip_include_prefix = "/RECW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":recw_types",
    ],
)

cc_library(
    name = "recw_calibration",
    srcs = [
        "@sfl//:RECW/Calibration/Generic/recw_calibration.c",
        "@sfl//:RECW/Calibration/RECW_Core/recw_calibration_cal_check.c",
        "@sfl//:RECW/Calibration/RECW_Core/recw_calibration_print_functions.c",
    ],
    hdrs = [
        "@sfl//:RECW/Calibration/RECW_Core/recw_calibration.h",
        "@sfl//:RECW/Calibration/RECW_Core/recw_calibration_cal_check.h",
    ],
    strip_include_prefix = "/RECW/Calibration/RECW_Core",
    visibility = ["//visibility:public"],
    deps = [
        ":recw_calibration_t",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "recw_calibration_t",
    hdrs = ["@sfl//:RECW/Calibration/RECW_Core/recw_calibration_t.h"],
    strip_include_prefix = "/RECW/Calibration/RECW_Core",
    visibility = ["//visibility:public"],
    deps = ["//ff_emb_lib/sfl/calibration_tool:calibtool"],
)

cc_library(
    name = "recw_io_t",
    hdrs = [
        "@sfl//:RECW/Customer_Adapter/Generic/recw_input_t.h",
        "@sfl//:RECW/Customer_Adapter/Generic/recw_output_t.h",
    ],
    strip_include_prefix = "/RECW/Customer_Adapter/Generic",
    visibility = ["//visibility:public"],
    deps = [
        ":recw_core_io",
        ":recw_types",
    ],
)
