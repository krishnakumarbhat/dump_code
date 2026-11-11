load("@bazel_skylib//rules:common_settings.bzl", "string_flag")
load("@aptiv-pypi//:requirements.bzl", "requirement")

py_binary(
    name = "memoryStats",
    srcs = [
        "__init__.py",
        "memoryStats.py",
    ],
    main = "memoryStats.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        # "//tools/python/dataDogMetrics", TODO Sandeep
        requirement("PyYAML"),
        requirement("openpyxl"),
    ],
)

string_flag(
    name = "gitBranch",
    build_setting_default = "",
    visibility = ["//visibility:public"],
)

config_setting(
    name = "jenkinsDevBranch",
    flag_values = {
        ":gitBranch": "dev",
        "@build_config//:jenkins": "true",
    },
)

string_flag(
    name = "swVersion",
    build_setting_default = "",
    visibility = ["//visibility:public"],
)
