load("@bazel_skylib//rules:common_settings.bzl", "bool_flag")

bool_flag(
    name = "nightly",
    build_setting_default = False,
    visibility = ["//visibility:public"],
)

config_setting(
    name = "coverityNightly",
    flag_values = {":nightly": "True"},
    visibility = ["//visibility:public"],
)
