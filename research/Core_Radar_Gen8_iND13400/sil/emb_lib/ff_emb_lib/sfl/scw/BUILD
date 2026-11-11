cc_library(
    name = "scw_iface",
    srcs = [
        "@sfl//:SCW/Source/scw.c",
        "@sfl//:SCW/Source/scw.h",
        "@sfl//:SCW/Source/scw_iface.c",
    ],
    hdrs = ["@sfl//:SCW/Source/scw_iface.h"],
    strip_include_prefix = "/SCW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":scw_calibration",
        ":scw_calibration_t",
        ":scw_core_io",
        ":scw_debug_interface",
        ":scw_debug_writer",
        ":scw_helper_functions",
        ":scw_io_t",
        ":scw_persistent_t",
        ":scw_post_run",
        ":scw_pre_run",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
        "//ff_emb_lib/sfl/pt:pt_iface",
    ],
)

cc_library(
    name = "scw_post_run",
    srcs = ["@sfl//:SCW/Customer_Adapter/Generic/scw_post_run.c"],
    hdrs = ["@sfl//:SCW/Customer_Adapter/scw_post_run.h"],
    strip_include_prefix = "/SCW/Customer_Adapter",
    deps = [
        ":scw_instance_t",
        ":scw_io_t",
        "//ff_emb_lib/sfl/pt:pt_iface",
    ],
)

cc_library(
    name = "scw_pre_run",
    srcs = ["@sfl//:SCW/Customer_Adapter/Generic/scw_pre_run.c"],
    hdrs = ["@sfl//:SCW/Customer_Adapter/scw_pre_run.h"],
    strip_include_prefix = "/SCW/Customer_Adapter",
    deps = [
        ":scw_instance_t",
        ":scw_io_t",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_iface",
    ],
)

cc_library(
    name = "scw_helper_functions",
    srcs = ["@sfl//:SCW/Source/scw_helper_functions.c"],
    hdrs = ["@sfl//:SCW/Source/scw_helper_functions.h"],
    strip_include_prefix = "/SCW/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_ref_point",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)

cc_library(
    name = "scw_debug_interface",
    srcs = ["@sfl//:SCW/Source/scw_debug_interface.c"],
    hdrs = ["@sfl//:SCW/Source/scw_debug_interface.h"],
    strip_include_prefix = "/SCW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":scw_calibration_t",
        ":scw_core_io",
        ":scw_io_t",
        ":scw_persistent_t",
        ":scw_types",
        "//ff_emb_lib/sfl/calibration_tool:calibtool",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "scw_debug_writer",
    srcs = ["@sfl//:SCW/Source/scw_debug_writer.c"],
    hdrs = ["@sfl//:SCW/Source/scw_debug_writer.h"],
    strip_include_prefix = "/SCW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":scw_debug_interface",
        "//ff_emb_lib/sfl/calibration_tool:calibtool",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:pa_vehicle_in",
    ],
)

cc_library(
    name = "scw_instance_t",
    hdrs = ["@sfl//:SCW/Source/scw_instance_t.h"],
    strip_include_prefix = "/SCW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":scw_calibration_t",
        ":scw_core_io",
        ":scw_persistent_t",
    ],
)

cc_library(
    name = "scw_core_io",
    hdrs = [
        "@sfl//:SCW/Source/scw_core_input_t.h",
        "@sfl//:SCW/Source/scw_core_output_t.h",
    ],
    strip_include_prefix = "/SCW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":scw_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_field_of_interest",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:pa_data",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "scw_types",
    hdrs = ["@sfl//:SCW/Source/scw_types.h"],
    strip_include_prefix = "/SCW/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_shared_ff_validation_types",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "scw_persistent_t",
    hdrs = ["@sfl//:SCW/Source/scw_persistent_t.h"],
    strip_include_prefix = "/SCW/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":scw_types",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:pa_obj_in",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "scw_calibration",
    srcs = [
        "@sfl//:SCW/Calibration/Generic/scw_calibration.c",
        "@sfl//:SCW/Calibration/SCW_Core/scw_calibration_cal_check.c",
        "@sfl//:SCW/Calibration/SCW_Core/scw_calibration_print_functions.c",
    ],
    hdrs = [
        "@sfl//:SCW/Calibration/SCW_Core/scw_calibration.h",
        "@sfl//:SCW/Calibration/SCW_Core/scw_calibration_cal_check.h",
    ],
    strip_include_prefix = "/SCW/Calibration/SCW_Core",
    visibility = ["//visibility:public"],
    deps = [
        ":scw_calibration_t",
        "//ff_emb_lib/sfl/calibration_tool:calibtool",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
    ],
)

cc_library(
    name = "scw_calibration_t",
    hdrs = ["@sfl//:SCW/Calibration/SCW_Core/scw_calibration_t.h"],
    strip_include_prefix = "/SCW/Calibration/SCW_Core",
    visibility = ["//visibility:public"],
    deps = ["//ff_emb_lib/sfl/feature_building_kit:pa_reuse"],
)

cc_library(
    name = "scw_io_t",
    hdrs = [
        "@sfl//:SCW/Customer_Adapter/Generic/scw_input_t.h",
        "@sfl//:SCW/Customer_Adapter/Generic/scw_output_t.h",
    ],
    strip_include_prefix = "/SCW/Customer_Adapter/Generic",
    visibility = ["//visibility:public"],
    deps = [
        ":scw_core_io",
        "//ff_emb_lib/sfl/feature_building_kit:fbk_functions",
        "//ff_emb_lib/sfl/feature_building_kit:pa_reuse",
        "//ff_emb_lib/sfl/math_library:mathlib",
    ],
)
