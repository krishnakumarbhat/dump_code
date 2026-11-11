cc_library(
    name = "ced_iface",
    srcs = [
        "@sfl//:CED/Source/ced.c",
        "@sfl//:CED/Source/ced.h",
        "@sfl//:CED/Source/ced_iface.c",
    ],
    hdrs = ["@sfl//:CED/Source/ced_iface.h"],
    strip_include_prefix = "/CED/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ced_calibration",
        ":ced_calibration_t",
        ":ced_common_functions",
        ":ced_create_zones",
        ":ced_debug_writer",
        ":ced_io_t",
        ":ced_post_run",
        ":ced_pre_run",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/pt:pt_iface",
    ],
)

cc_library(
    name = "ced_post_run",
    srcs = ["@sfl//:CED/Customer_Adapter/Generic/ced_post_run.c"],
    hdrs = ["@sfl//:CED/Customer_Adapter/ced_post_run.h"],
    strip_include_prefix = "/CED/Customer_Adapter",
    deps = [
        ":ced_calibration",
        ":ced_instance",
        ":ced_io_t",
        "//ff_emb_lib/sfl/pt:pt_iface",
    ],
)

cc_library(
    name = "ced_pre_run",
    srcs = ["@sfl//:CED/Customer_Adapter/Generic/ced_pre_run.c"],
    hdrs = ["@sfl//:CED/Customer_Adapter/ced_pre_run.h"],
    strip_include_prefix = "/CED/Customer_Adapter",
    deps = [
        ":ced_calibration",
        ":ced_instance",
        ":ced_io_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
    ],
)

cc_library(
    name = "ced_common_functions",
    srcs = ["@sfl//:CED/Source/ced_common_functions.c"],
    hdrs = ["@sfl//:CED/Source/ced_common_functions.h"],
    strip_include_prefix = "/CED/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ced_calibration_t",
        ":ced_debug_interface_h",
        ":ced_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "ced_create_zones",
    srcs = [
        "@sfl//:CED/Source/ced_create_zones.c",
    ],
    hdrs = [
        "@sfl//:CED/Source/ced_create_zones.h",
    ],
    strip_include_prefix = "/CED/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ced_calibration_t",
        ":ced_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
        "//ff_emb_lib/sfl/math_library:mathlib",
        "//ff_emb_lib/sfl/math_library:mathlib_types",
    ],
)

cc_library(
    name = "ced_debug_interface",
    srcs = ["@sfl//:CED/Source/ced_debug_interface.c"],
    hdrs = ["@sfl//:CED/Source/ced_debug_interface.h"],
    strip_include_prefix = "/CED/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ced_calibration_t",
        ":ced_core_io",
        ":ced_debug_interface_h",
        ":ced_persistent_t",
        ":ced_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/pt:pt_io_t",
    ],
)

cc_library(
    name = "ced_debug_interface_h",
    hdrs = ["@sfl//:CED/Source/ced_debug_interface.h"],
    strip_include_prefix = "/CED/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ced_calibration_t",
        ":ced_core_io",
        ":ced_io_t",
        ":ced_persistent_t",
        ":ced_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "ced_debug_writer",
    srcs = ["@sfl//:CED/Source/ced_debug_writer.c"],
    hdrs = ["@sfl//:CED/Source/ced_debug_writer.h"],
    strip_include_prefix = "/CED/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ced_debug_interface_h",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
    ],
)

cc_library(
    name = "ced_debug_writer_h",
    hdrs = ["@sfl//:CED/Source/ced_debug_writer.h"],
    strip_include_prefix = "/CED/Source",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "ced_instance",
    hdrs = ["@sfl//:CED/Source/ced_instance.h"],
    strip_include_prefix = "/CED/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ced_calibration_t",
        ":ced_core_io",
        ":ced_persistent_t",
    ],
)

cc_library(
    name = "ced_core_io",
    hdrs = [
        "@sfl//:CED/Source/ced_core_input_t.h",
        "@sfl//:CED/Source/ced_core_output_t.h",
    ],
    strip_include_prefix = "/CED/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ced_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
    ],
)

cc_library(
    name = "ced_types",
    hdrs = ["@sfl//:CED/Source/ced_types.h"],
    strip_include_prefix = "/CED/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
        "//ff_emb_lib/sfl/pt:pt_io_t",
    ],
)

cc_library(
    name = "ced_persistent_t",
    hdrs = ["@sfl//:CED/Source/ced_persistent_t.h"],
    strip_include_prefix = "/CED/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":ced_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "ced_calibration",
    srcs = [
        "@sfl//:CED/Calibration/CED_Core/ced_calibration_cal_check.c",
        "@sfl//:CED/Calibration/CED_Core/ced_calibration_print_functions.c",
        "@sfl//:CED/Calibration/Generic/ced_calibration.c",
    ],
    hdrs = [
        "@sfl//:CED/Calibration/CED_Core/ced_calibration.h",
        "@sfl//:CED/Calibration/CED_Core/ced_calibration_cal_check.h",
    ],
    strip_include_prefix = "/CED/Calibration/CED_Core",
    visibility = ["//visibility:public"],
    deps = [
        ":ced_calibration_t",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "ced_calibration_t",
    hdrs = ["@sfl//:CED/Calibration/CED_Core/ced_calibration_t.h"],
    strip_include_prefix = "/CED/Calibration/CED_Core",
    visibility = ["//visibility:public"],
    deps = ["//ff_emb_lib/sfl/calibration_tool:calibtool"],
)

cc_library(
    name = "ced_io_t",
    hdrs = [
        "@sfl//:CED/Customer_Adapter/Generic/ced_generic_types.h",
        "@sfl//:CED/Customer_Adapter/Generic/ced_input_t.h",
        "@sfl//:CED/Customer_Adapter/Generic/ced_output_t.h",
    ],
    strip_include_prefix = "/CED/Customer_Adapter/Generic",
    visibility = ["//visibility:public"],
    deps = [
        ":ced_core_io",
        ":ced_types",
        "//ff_emb_lib/sfl/pt:pt_iface",
    ],
)
