cc_library(
    name = "esa_iface",
    srcs = [
        "@sfl//:ESA/Source/esa.c",
        "@sfl//:ESA/Source/esa.h",
        "@sfl//:ESA/Source/esa_iface.c",
    ],
    hdrs = ["@sfl//:ESA/Source/esa_iface.h"],
    strip_include_prefix = "/ESA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":esa_calibration",
        ":esa_calibration_t",
        ":esa_debug_interface",
        ":esa_post_run",
        ":esa_pre_run",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
    ],
)

cc_library(
    name = "esa_post_run",
    srcs = ["@sfl//:ESA/Customer_Adapter/Generic/esa_post_run.c"],
    hdrs = ["@sfl//:ESA/Customer_Adapter/esa_post_run.h"],
    strip_include_prefix = "/ESA/Customer_Adapter",
    deps = [
        ":esa_instance",
        ":esa_io_t",
    ],
)

cc_library(
    name = "esa_pre_run",
    srcs = ["@sfl//:ESA/Customer_Adapter/Generic/esa_pre_run.c"],
    hdrs = ["@sfl//:ESA/Customer_Adapter/esa_pre_run.h"],
    strip_include_prefix = "/ESA/Customer_Adapter",
    deps = [
        ":esa_instance",
        ":esa_io_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
    ],
)

cc_library(
    name = "esa_debug_interface",
    srcs = ["@sfl//:ESA/Source/esa_debug_interface.c"],
    hdrs = ["@sfl//:ESA/Source/esa_debug_interface.h"],
    strip_include_prefix = "/ESA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":esa_calibration_t",
        ":esa_core_io",
        ":esa_create_zone",
        ":esa_debug_writer_h",
        ":esa_instance",
        ":esa_io_t",
        ":esa_persistent_t",
        ":esa_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "esa_debug_interface_h",
    hdrs = ["@sfl//:ESA/Source/esa_debug_interface.h"],
    strip_include_prefix = "/ESA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":esa_calibration_t",
        ":esa_core_io",
        ":esa_debug_writer_h",
        ":esa_instance",
        ":esa_io_t",
        ":esa_persistent_t",
        ":esa_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "esa_debug_writer",
    srcs = ["@sfl//:ESA/Source/esa_debug_writer.c"],
    hdrs = ["@sfl//:ESA/Source/esa_debug_writer.h"],
    strip_include_prefix = "/ESA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":esa_debug_interface",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
    ],
)

cc_library(
    name = "esa_debug_writer_h",
    hdrs = ["@sfl//:ESA/Source/esa_debug_writer.h"],
    strip_include_prefix = "/ESA/Source",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "esa_instance",
    hdrs = ["@sfl//:ESA/Source/esa_instance_t.h"],
    strip_include_prefix = "/ESA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":esa_calibration_t",
        ":esa_core_io",
        ":esa_persistent_t",
    ],
)

cc_library(
    name = "esa_core_io",
    hdrs = [
        "@sfl//:ESA/Source/esa_core_input_t.h",
        "@sfl//:ESA/Source/esa_core_output_t.h",
    ],
    strip_include_prefix = "/ESA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":esa_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
    ],
)

cc_library(
    name = "esa_types",
    hdrs = ["@sfl//:ESA/Source/esa_types.h"],
    strip_include_prefix = "/ESA/Source",
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
    name = "esa_persistent_t",
    hdrs = ["@sfl//:ESA/Source/esa_persistent_t.h"],
    strip_include_prefix = "/ESA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":esa_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "esa_calibration",
    srcs = [
        "@sfl//:ESA/Calibration/ESA_Core/esa_calibration_cal_check.c",
        "@sfl//:ESA/Calibration/ESA_Core/esa_calibration_print_functions.c",
        "@sfl//:ESA/Calibration/Generic/esa_calibration.c",
    ],
    hdrs = [
        "@sfl//:ESA/Calibration/ESA_Core/esa_calibration.h",
        "@sfl//:ESA/Calibration/ESA_Core/esa_calibration_cal_check.h",
    ],
    strip_include_prefix = "/ESA/Calibration/ESA_Core",
    visibility = ["//visibility:public"],
    deps = [
        ":esa_calibration_t",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "esa_calibration_t",
    hdrs = ["@sfl//:ESA/Calibration/ESA_Core/esa_calibration_t.h"],
    strip_include_prefix = "/ESA/Calibration/ESA_Core",
    visibility = ["//visibility:public"],
    deps = ["//ff_emb_lib/sfl/calibration_tool:calibtool"],
)

cc_library(
    name = "esa_io_t",
    hdrs = [
        "@sfl//:ESA/Customer_Adapter/Generic/esa_input_t.h",
        "@sfl//:ESA/Customer_Adapter/Generic/esa_output_t.h",
    ],
    strip_include_prefix = "/ESA/Customer_Adapter/Generic",
    visibility = ["//visibility:public"],
    deps = [
        ":esa_core_io",
        ":esa_types",
    ],
)

cc_library(
    name = "esa_create_zone",
    srcs = ["@sfl//:ESA/Source/esa_create_zone.c"],
    hdrs = ["@sfl//:ESA/Source/esa_create_zone.h"],
    strip_include_prefix = "/ESA/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":esa_calibration_t",
        ":esa_io_t",
        ":esa_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)
