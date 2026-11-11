load("@bazel_skylib//rules:common_settings.bzl", "bool_flag", "string_flag")

bool_flag(
    name = "build_rdd_sil",
    build_setting_default = True,
    visibility = ["//visibility:private"],
)

config_setting(
    name = "rdd_sil",
    flag_values = {"build_rdd_sil": "true"},
    visibility = ["//visibility:private"],
)

string_flag(
    name = "cal_bin_path",
    build_setting_default = "flr8_cal_path",
    values = [
        "flr8_Cal_path",
    ],
    visibility = ["//visibility:private"],
)

config_setting(
    name = "flr8_cal_path",
    flag_values = {"cal_bin_path": "flr8_cal_path"},
    visibility = ["//visibility:private"],
)

cc_binary(
    name = "rdd_sil_Test",
    srcs = [
        "main.cpp",
    ],
    visibility = ["//visibility:private"],
    deps = [
        "@Gen8_iND13400//sil/rsp_sil/data_bin:binary_headers",
        "@Gen8_iND13400//sil/rsp_sil/main/rsp_wrapper_interface/psp_sil_interface:psp_sil_interface_lib",
        "@Gen8_iND13400//sil/rsp_sil/main/rsp_wrapper_interface/rdd_sil_interface:rdd_sil_interface_lib",
    ],
)
