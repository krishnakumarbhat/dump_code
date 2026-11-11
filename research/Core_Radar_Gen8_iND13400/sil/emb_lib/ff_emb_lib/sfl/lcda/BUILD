cc_library(
    name = "lcda_iface",
    srcs = [
        "@sfl//:LCDA/Source/lcda.c",
        "@sfl//:LCDA/Source/lcda.h",
        "@sfl//:LCDA/Source/lcda_iface.c",
    ],
    hdrs = ["@sfl//:LCDA/Source/lcda_iface.h"],
    strip_include_prefix = "/LCDA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":lcda_bsw_cvw",
        ":lcda_calibration",
        ":lcda_calibration_t",
        ":lcda_debug_interface",
        ":lcda_io_t",
        ":lcda_post_run",
        ":lcda_pre_run",
        ":lcda_process_elc",
        ":lcda_process_slc",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
    ],
)

# cc_library(
#     name = "lcda_iface",
#     srcs = ["@sfl//:LCDA/Source/lcda_iface.c"],
#     hdrs = ["@sfl//:LCDA/Source/lcda_iface.h"],
#     strip_include_prefix = "/LCDA/Source",
#     visibility = ["//visibility:public"],
#     deps = [
#         ":lcda_bsw_cvw",
#         ":lcda_debug_interface",
#         ":lcda_instance",
#         ":lcda_persistent_t",
#         ":lcda_process_elc",
#         ":lcda_process_slc",
#         "//ff_emb_lib/sfl/feature_building_kit:pa_data",
#     ],
# )

cc_library(
    name = "lcda_post_run",
    srcs = ["@sfl//:LCDA/Customer_Adapter/Generic/lcda_post_run.c"],
    hdrs = ["@sfl//:LCDA/Customer_Adapter/lcda_post_run.h"],
    strip_include_prefix = "/LCDA/Customer_Adapter",
    deps = [
        ":lcda_instance",
        ":lcda_io_t",
    ],
)

cc_library(
    name = "lcda_pre_run",
    srcs = ["@sfl//:LCDA/Customer_Adapter/Generic/lcda_pre_run.c"],
    hdrs = ["@sfl//:LCDA/Customer_Adapter/lcda_pre_run.h"],
    strip_include_prefix = "/LCDA/Customer_Adapter",
    deps = [
        ":lcda_instance",
        ":lcda_io_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
    ],
)

cc_library(
    name = "lcda_common_functions",
    srcs = ["@sfl//:LCDA/Source/lcda_common_functions.c"],
    hdrs = ["@sfl//:LCDA/Source/lcda_common_functions.h"],
    strip_include_prefix = "/LCDA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":lcda_calibration_t",
        ":lcda_debug_interface_h",
        ":lcda_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_ref_point",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "lcda_bsw_cvw",
    srcs = [
        "@sfl//:LCDA/Source/lcda_create_bsw_zone.c",
        "@sfl//:LCDA/Source/lcda_create_cvw_zone.c",
        "@sfl//:LCDA/Source/lcda_process_bsw.c",
        "@sfl//:LCDA/Source/lcda_process_cvw.c",
    ],
    hdrs = [
        "@sfl//:LCDA/Source/lcda_create_bsw_zone.h",
        "@sfl//:LCDA/Source/lcda_create_cvw_zone.h",
        "@sfl//:LCDA/Source/lcda_process_bsw.h",
        "@sfl//:LCDA/Source/lcda_process_cvw.h",
    ],
    strip_include_prefix = "/LCDA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":lcda_calibration_t",
        ":lcda_common_functions",
        ":lcda_core_io",
        ":lcda_debug_interface_h",
        ":lcda_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_ref_point",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_data",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
        "//ff_emb_lib/sfl/feature_building_kit:pa_shared_types",
        "//ff_emb_lib/sfl/math_library:mathlib",
        "//ff_emb_lib/sfl/math_library:mathlib_types",
    ],
)

cc_library(
    name = "lcda_process_elc",
    srcs = ["@sfl//:LCDA/Source/lcda_process_elc.c"],
    hdrs = ["@sfl//:LCDA/Source/lcda_process_elc.h"],
    strip_include_prefix = "/LCDA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":lcda_calibration_t",
        ":lcda_common_functions",
        ":lcda_debug_interface_h",
        ":lcda_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
    ],
)

cc_library(
    name = "lcda_process_slc",
    srcs = ["@sfl//:LCDA/Source/lcda_process_slc.c"],
    hdrs = ["@sfl//:LCDA/Source/lcda_process_slc.h"],
    strip_include_prefix = "/LCDA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":lcda_calibration_t",
        ":lcda_common_functions",
        ":lcda_core_io",
        ":lcda_debug_interface_h",
        ":lcda_io_t",
        ":lcda_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "lcda_debug_interface",
    srcs = ["@sfl//:LCDA/Source/lcda_debug_interface.c"],
    hdrs = ["@sfl//:LCDA/Source/lcda_debug_interface.h"],
    strip_include_prefix = "/LCDA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":lcda_bsw_cvw",
        ":lcda_calibration_t",
        ":lcda_debug_writer_h",
        ":lcda_io_t",
        ":lcda_persistent_t",
        ":lcda_process_elc",
        ":lcda_process_slc",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "lcda_debug_interface_h",
    hdrs = ["@sfl//:LCDA/Source/lcda_debug_interface.h"],
    strip_include_prefix = "/LCDA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":lcda_calibration_t",
        ":lcda_core_io",
        ":lcda_io_t",
        ":lcda_persistent_t",
        ":lcda_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "lcda_debug_writer",
    srcs = ["@sfl//:LCDA/Source/lcda_debug_writer.c"],
    hdrs = ["@sfl//:LCDA/Source/lcda_debug_writer.h"],
    strip_include_prefix = "/LCDA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":lcda_debug_interface",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
    ],
)

cc_library(
    name = "lcda_debug_writer_h",
    hdrs = ["@sfl//:LCDA/Source/lcda_debug_writer.h"],
    strip_include_prefix = "/LCDA/Source",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "lcda_instance",
    hdrs = ["@sfl//:LCDA/Source/lcda_instance.h"],
    strip_include_prefix = "/LCDA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":lcda_calibration_t",
        ":lcda_core_io",
        ":lcda_persistent_t",
    ],
)

cc_library(
    name = "lcda_core_io",
    hdrs = [
        "@sfl//:LCDA/Source/lcda_core_input_t.h",
        "@sfl//:LCDA/Source/lcda_core_output_t.h",
    ],
    strip_include_prefix = "/LCDA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":lcda_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
    ],
)

cc_library(
    name = "lcda_types",
    hdrs = ["@sfl//:LCDA/Source/lcda_types.h"],
    strip_include_prefix = "/LCDA/Source",
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
    name = "lcda_persistent_t",
    hdrs = ["@sfl//:LCDA/Source/lcda_persistent_t.h"],
    strip_include_prefix = "/LCDA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":lcda_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "lcda_calibration",
    srcs = [
        "@sfl//:LCDA/Calibration/Generic/lcda_calibration.c",
        "@sfl//:LCDA/Calibration/LCDA_Core/lcda_calibration_cal_check.c",
        "@sfl//:LCDA/Calibration/LCDA_Core/lcda_calibration_print_functions.c",
    ],
    hdrs = [
        "@sfl//:LCDA/Calibration/LCDA_Core/lcda_calibration.h",
        "@sfl//:LCDA/Calibration/LCDA_Core/lcda_calibration_cal_check.h",
    ],
    strip_include_prefix = "/LCDA/Calibration/LCDA_Core",
    visibility = ["//visibility:public"],
    deps = [
        ":lcda_calibration_t",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "lcda_calibration_t",
    hdrs = ["@sfl//:LCDA/Calibration/LCDA_Core/lcda_calibration_t.h"],
    strip_include_prefix = "/LCDA/Calibration/LCDA_Core",
    visibility = ["//visibility:public"],
    deps = ["//ff_emb_lib/sfl/calibration_tool:calibtool"],
)

cc_library(
    name = "lcda_io_t",
    hdrs = [
        "@sfl//:LCDA/Customer_Adapter/Generic/lcda_input_t.h",
        "@sfl//:LCDA/Customer_Adapter/Generic/lcda_output_t.h",
    ],
    strip_include_prefix = "/LCDA/Customer_Adapter/Generic",
    visibility = ["//visibility:public"],
    deps = [
        ":lcda_core_io",
        ":lcda_types",
    ],
)
