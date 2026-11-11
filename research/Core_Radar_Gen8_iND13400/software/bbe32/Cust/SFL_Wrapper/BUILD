load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Wrappers_lib",
    srcs = [
        "src/BSIS_Wrapper.cpp",
        "src/MOIS_Wrapper.cpp",
        "src/SFL_Wrapper.cpp",
    ],
    features = ["-lto"],
    visibility = ["//visibility:public"],
    deps = [
        ":bsis_headers_h",
        ":mois_headers_h",
        ":sfl_headers_h",
        "//software/bbe32/Cust/OLP_Wrapper:olp_wrapper_h",
        "//software/bbe32/TOI_char_quality_determination:radar_data_quality_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/common/calibrations/smc:smc_h",
        "@math_library_bb//:ml_core_lib",
        "@math_library_bb//:ml_reuse_h",
        "@mode_manager_bb//:mode_manager_lib",
        "@reuse",
        "@reuse//:fixmac",
        "@sfl_core_bb//:sfl_core",
    ],
)

cc_library(
    name = "sfl_headers_h",
    hdrs = ["inc/SFL_Wrapper.h"],
    strip_include_prefix = "//software/bbe32/Cust/SFL_Wrapper/inc",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "SFL_Wrapper_Unit_Test_Lib_Gtest",
    hdrs = [
        "src/SFL_Wrapper.cpp",
    ],
    defines = [
        "SFL_UT",
        "OLP_NUMBER_OF_OBJECTS=64",
        "OLP_OBJ_SOURCE_F360",
        "PA_OBJ_NUMBER_OF_OBJECTS=OLP_NUMBER_OF_OBJECTS",
        "PLATFORM_INTERFACE_USED",
        "ROT_STANDALONE",
    ],
    features = ["compiler_param_file"],
    visibility = ["//visibility:public"],
    deps = [
        ":SFL_Wrapper_Unit_Test_h",
        ":bsis_headers_h",
        ":sfl_headers_h",
        "//software/bbe32/Cust/OLP_Wrapper:Olp_wrapper_h",
        "//software/bbe32/TOI_char_quality_determination:TOI_Radar_Data_Quality_Check_lib_h",
        "//software/bbe32/TOI_char_quality_determination:std_deviation_h",
        "@math_library_bb//:ml_core_lib",
        "@sfl_core_bb//:cal_tool_c_src_h",
        "@sfl_core_bb//:fbk_Interface_boundaries_h",
        "@sfl_core_bb//:fbk_Interface_debug_writer_h",
        "@sfl_core_bb//:fbk_Interface_ego_traj_pred_instance_h",
        "@sfl_core_bb//:fbk_Interface_fill_pa_data_h",
        "@sfl_core_bb//:fbk_Interface_h",
        "@sfl_core_bb//:fbk_Interface_host_trail_h",
        "@sfl_core_bb//:fbk_Interface_iface_types_h",
        "@sfl_core_bb//:fbk_Interface_index_lookup_h",
        "@sfl_core_bb//:fbk_Interface_object_ageing_h",
        "@sfl_core_bb//:fbk_Platform_Abstraction_Layer_generic_inc_data_ports_h",
        "@sfl_core_bb//:fbk_Platform_Abstraction_Layer_generic_inc_data_ports_pa_reuse_h",
        "@sfl_core_bb//:fbk_Platform_Abstraction_Layer_generic_inc_h",
        "@sfl_core_bb//:fbk_Platform_Abstraction_Layer_h",
        "@sfl_core_bb//:fbk_Platform_Abstraction_Layer_pa_shrd_types_h",
        "@sfl_core_bb//:fbk_cal_core_h",
        "@sfl_core_bb//:fbk_cal_generic_h",
        "@sfl_core_bb//:fbk_shared_ff_h",
        "@sfl_core_bb//:fbk_shared_ff_interpolation_h",
        "@sfl_core_bb//:fbk_shared_ff_reference_point_h",
        "@sfl_core_bb//:fbk_shared_ff_trajectory_prediction_h",
        "@sfl_core_bb//:fbk_shared_ff_trajectory_prediction_traj_predictor_h",
        "@sfl_core_bb//:fbk_shared_ff_validation_data_h",
        "@sfl_core_bb//:fbk_shared_ff_validation_h",
        "@sfl_core_bb//:fbk_shared_ff_zone_h",
    ],
)

# Bsis related libraries:
cc_library(
    name = "bsis_headers_h",
    hdrs = ["inc/BSIS_Wrapper.h"],
    strip_include_prefix = "//software/bbe32/Cust/SFL_Wrapper/inc",
    visibility = ["//visibility:public"],
    deps = [
        "@mode_manager_bb//:sfl_input_processing_h",
        "@sfl_core_bb//:bsis_customer_adapter_generic_h",
        "@sfl_core_bb//:fbk_Interface_h",
    ],
)

# Mois related libraries:
cc_library(
    name = "mois_headers_h",
    hdrs = ["inc/MOIS_Wrapper.h"],
    strip_include_prefix = "//software/bbe32/Cust/SFL_Wrapper/inc",
    visibility = ["//visibility:public"],
    deps = [
        "@mode_manager_bb//:sfl_input_processing_h",
        "@sfl_core_bb//:fbk_Interface_h",
        "@sfl_core_bb//:mois_customer_adapter_generic_h",
    ],
)
