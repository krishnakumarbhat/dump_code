load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "sil_input_symbol_h",
    hdrs = ["sil_input_symbol.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [":dvl_message_h"],
)

cc_library(
    name = "sil_output_symbol_h",
    hdrs = ["sil_output_symbol.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [":sil_input_symbol_h"],
)

cc_library(
    name = "dvl_message_h",
    hdrs = ["dvl_message.h"],
    strip_include_prefix = ".",
)

cc_library(
    name = "radar_sil_input_data_h",
    hdrs = ["Radar_SIL_Input_Data.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [":rr_adas_symbol_h"],
)

cc_library(
    name = "radar_sil_output_data_h",
    hdrs = ["Radar_SIL_Output_Data.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":dvl_message_h",
        ":rr_adas_symbol_h",
    ],
)

cc_library(
    name = "resim_config_h",
    hdrs = ["Resim_Config.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":radar_sil_input_data_h",
        ":radar_sil_output_data_h",
    ],
)

cc_library(
    name = "rr_adas_symbol_h",
    hdrs = [
        "RR_ADAS_SYMBOL_Data.h",
        "RR_ADAS_SYMBOL_Enum.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "radar_sil_version_h",
    hdrs = [
        "Radar_SIL_Version.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [":rr_adas_symbol_h"],
)

cc_library(
    name = "radar_position_h",
    hdrs = ["radar_position.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
)
