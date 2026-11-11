load("@bazel_skylib//rules:common_settings.bzl", "string_flag")
load("@rules_cc//cc:defs.bzl", "cc_library")

exports_files(glob([
    "compiler_warnings_allowlist.yml",
]))

string_flag(
    name = "variant",
    build_setting_default = "flr8",
    values = [
        "flr8",
        "srr8p",
    ],
    visibility = ["//visibility:public"],
)

config_setting(
    name = "flr8",
    flag_values = {":variant": "flr8"},
)

config_setting(
    name = "srr8p",
    flag_values = {":variant": "srr8p"},
)

# BBE32 Core windows
platform(
    name = "winbbe32",
    constraint_values = [
        "@build_config//cpu:bbe32",
        "@platforms//os:windows",
    ],
    visibility = ["//visibility:public"],
)

# BBE32 Core linux
platform(
    name = "linuxbbe32",
    constraint_values = [
        "@build_config//cpu:bbe32",
        "@platforms//os:linux",
    ],
    visibility = ["//visibility:public"],
)

exports_files(glob([
    "*.bzl",
]))

alias(
    name = "cstub64_library",
    actual = select({
        "@platforms//os:windows": "@bbe_windows_luna//:cstub64_lib",
        "@platforms//os:linux": "@bbe_linux_luna//:cstub64_lib",
    }),
    visibility = ["//visibility:public"],
)

filegroup(
    name = "all_files",
    srcs = select({
        "@platforms//os:windows": [
            "@bbe_windows//:all_files",
            "@bbe_windows_luna//:all_files",
        ],
        "@platforms//os:linux": [
            "@bbe_linux//:all_files",
            "@bbe_linux_luna//:all_files",
        ],
    }),
    visibility = ["//visibility:public"],
)

filegroup(
    name = "compiler_include_directories",
    srcs = select({
        "@platforms//os:windows": [
            "@bbe_windows//:compiler_include_directories",
            "@bbe_windows_luna//:compiler_include_directories",
        ],
        "@platforms//os:linux": [
            "@bbe_linux//:compiler_include_directories",
            "@bbe_linux_luna//:compiler_include_directories",
        ],
    }),
    visibility = ["//visibility:public"],
)

filegroup(
    name = "config",
    srcs = select({
        "@platforms//os:windows": [
            "@bbe_windows_luna//:config",
        ],
        "@platforms//os:linux": [
            "@bbe_linux_luna//:config",
        ],
    }),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "chandra_sfr_h",
    visibility = ["//visibility:public"],
    deps = ["@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h"],
)
