cc_library(
    name = "ltb_iface",
    srcs = [
        "@sfl//:LTB/Source/ltb.c",
        "@sfl//:LTB/Source/ltb.h",
        "@sfl//:LTB/Source/ltb_iface.c",
    ],
    hdrs = ["@sfl//:LTB/Source/ltb_iface.h"],
    strip_include_prefix = "/LTB/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ltb_calibration",
        ":ltb_calibration_t",
        ":ltb_debug_interface",
        ":ltb_debug_writer",
        ":ltb_io_t",
        ":ltb_post_run",
        ":ltb_pre_run",
        ":ltb_time_calculation",
        ":ltb_warn_logic",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
    ],
)

cc_library(
    name = "ltb_post_run",
    srcs = ["@sfl//:LTB/Customer_Adapter/Generic/ltb_post_run.c"],
    hdrs = ["@sfl//:LTB/Customer_Adapter/ltb_post_run.h"],
    strip_include_prefix = "/LTB/Customer_Adapter",
    deps = [
        ":ltb_instance",
        ":ltb_io_t",
    ],
)

cc_library(
    name = "ltb_pre_run",
    srcs = ["@sfl//:LTB/Customer_Adapter/Generic/ltb_pre_run.c"],
    hdrs = ["@sfl//:LTB/Customer_Adapter/ltb_pre_run.h"],
    strip_include_prefix = "/LTB/Customer_Adapter",
    deps = [
        ":ltb_instance",
        ":ltb_io_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
    ],
)

cc_library(
    name = "ltb_common_functions",
    srcs = ["@sfl//:LTB/Source/ltb_common_functions.c"],
    hdrs = ["@sfl//:LTB/Source/ltb_common_functions.h"],
    strip_include_prefix = "/LTB/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ltb_calibration_t",
        ":ltb_debug_interface_h",
        ":ltb_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_ref_point",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "ltb_factory",
    srcs = ["@sfl//:LTB/Source/ltb_factory.c"],
    hdrs = ["@sfl//:LTB/Source/ltb_factory.h"],
    strip_include_prefix = "/LTB/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ltb_calibration_t",
        ":ltb_common_functions",
        ":ltb_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_traj_pred",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
    ],
)

cc_library(
    name = "ltb_time_calculation",
    srcs = ["@sfl//:LTB/Source/ltb_time_calculation.c"],
    hdrs = ["@sfl//:LTB/Source/ltb_time_calculation.h"],
    strip_include_prefix = "/LTB/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ltb_calibration_t",
        ":ltb_common_functions",
        ":ltb_core_io",
        ":ltb_debug_interface_h",
        ":ltb_io_t",
        ":ltb_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "ltb_warn_logic",
    srcs = ["@sfl//:LTB/Source/ltb_warn_logic.c"],
    hdrs = ["@sfl//:LTB/Source/ltb_warn_logic.h"],
    strip_include_prefix = "/LTB/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ltb_calibration_t",
        ":ltb_common_functions",
        ":ltb_core_io",
        ":ltb_debug_interface_h",
        ":ltb_io_t",
        ":ltb_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "ltb_debug_interface",
    srcs = ["@sfl//:LTB/Source/ltb_debug_interface.c"],
    hdrs = ["@sfl//:LTB/Source/ltb_debug_interface.h"],
    strip_include_prefix = "/LTB/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ltb_calibration_t",
        ":ltb_factory",
        ":ltb_io_t",
        ":ltb_persistent_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "ltb_debug_interface_h",
    hdrs = ["@sfl//:LTB/Source/ltb_debug_interface.h"],
    strip_include_prefix = "/LTB/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ltb_calibration_t",
        ":ltb_core_io",
        ":ltb_io_t",
        ":ltb_persistent_t",
        ":ltb_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "ltb_debug_writer",
    srcs = ["@sfl//:LTB/Source/ltb_debug_writer.c"],
    hdrs = ["@sfl//:LTB/Source/ltb_debug_writer.h"],
    strip_include_prefix = "/LTB/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ltb_debug_interface",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
    ],
)

cc_library(
    name = "ltb_debug_writer_h",
    hdrs = ["@sfl//:LTB/Source/ltb_debug_writer.h"],
    strip_include_prefix = "/LTB/Source",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "ltb_instance",
    hdrs = ["@sfl//:LTB/Source/ltb_instance.h"],
    strip_include_prefix = "/LTB/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ltb_calibration_t",
        ":ltb_core_io",
        ":ltb_persistent_t",
    ],
)

cc_library(
    name = "ltb_core_io",
    hdrs = [
        "@sfl//:LTB/Source/ltb_core_input_t.h",
        "@sfl//:LTB/Source/ltb_core_output_t.h",
    ],
    strip_include_prefix = "/LTB/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ltb_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
    ],
)

cc_library(
    name = "ltb_types",
    hdrs = ["@sfl//:LTB/Source/ltb_types.h"],
    strip_include_prefix = "/LTB/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "ltb_persistent_t",
    hdrs = ["@sfl//:LTB/Source/ltb_persistent_t.h"],
    strip_include_prefix = "/LTB/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ltb_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "ltb_calibration",
    srcs = [
        "@sfl//:LTB/Calibration/Generic/ltb_calibration.c",
        "@sfl//:LTB/Calibration/LTB_Core/ltb_calibration_cal_check.c",
        "@sfl//:LTB/Calibration/LTB_Core/ltb_calibration_print_functions.c",
    ],
    hdrs = [
        "@sfl//:LTB/Calibration/LTB_Core/ltb_calibration.h",
        "@sfl//:LTB/Calibration/LTB_Core/ltb_calibration_cal_check.h",
    ],
    strip_include_prefix = "/LTB/Calibration/LTB_Core",
    visibility = ["//visibility:public"],
    deps = [
        ":ltb_calibration_t",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "ltb_calibration_t",
    hdrs = ["@sfl//:LTB/Calibration/LTB_Core/ltb_calibration_t.h"],
    strip_include_prefix = "/LTB/Calibration/LTB_Core",
    visibility = ["//visibility:public"],
    deps = ["//ff_emb_lib/sfl/calibration_tool:calibtool"],
)

cc_library(
    name = "ltb_io_t",
    hdrs = [
        "@sfl//:LTB/Customer_Adapter/Generic/ltb_input_t.h",
        "@sfl//:LTB/Customer_Adapter/Generic/ltb_output_t.h",
    ],
    strip_include_prefix = "/LTB/Customer_Adapter/Generic",
    visibility = ["//visibility:public"],
    deps = [
        ":ltb_core_io",
        ":ltb_types",
    ],
)
