load("@bazel_platform//toolchains/windriver/v7:cc_toolchain_config.bzl", "cc_toolchain_config")

DIAB_VERSION = "7.0.6.0"

TARGET = ["-tARMV8RT2MS:simple"]

COPTS = TARGET + select({
    "//software/bbe32/src:cdc_enable": ["-DCDC_ENABLE"],
    "//conditions:default": [],
}) + [
    "-Xlicense-wait",
    "-ffunction-sections",
    "-fdata-sections",
    "-g",
    "-mthumb",
    "-Ws",
    "-Wall",
    "-Wpedantic",
    "-Werror",
    "-gdwarf-4",
    "-Wno-overlength-strings",
    "-fsanitize=integer-divide-by-zero",
    "-fsanitize=float-divide-by-zero",
]

CONLYOPTS = [
    "-std=c11",
]

LINKEROPTS = TARGET + [
    "-m22",
    "-lc",
    "-limpl",
    "-Xgenerate-copytables",
    "-Xemulate-gnu-vma-lma",
    "-Xremove-unused-sections",
    "-Xpreprocess-lecl",
    "-Xstop-on-warning",
    "-lm",
]

ASMOPTS = TARGET + [
]

DEFINES = [
]

# LTO setting: Classic, Thin, Off
ENABLE_LTO = "Classic"

# Optimization level: None, O0, O1, O2, O3, Oz, Os
OPTIMIZATION_LEVEL = "Oz"

toolchain(
    name = "windriver_r52_toolchain",
    exec_compatible_with = [
        "@platforms//os:windows",
        "@platforms//cpu:x86_64",
    ],
    target_compatible_with = [
        "@bazel_platform//platforms/cpu:arm-r52",
    ],
    toolchain = ":windriver_cc_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
    visibility = ["//visibility:public"],
)

cc_toolchain(
    name = "windriver_cc_toolchain",
    all_files = "@windriver_diab_windows//:all_files",
    compiler_files = "@windriver_diab_windows//:all_files",
    dwp_files = "@windriver_diab_windows//:all_files",
    linker_files = "@windriver_diab_windows//:all_files",
    objcopy_files = "@windriver_diab_windows//:all_files",
    strip_files = "@windriver_diab_windows//:all_files",
    supports_header_parsing = True,
    supports_param_files = 0,
    toolchain_config = ":cc_toolchain_config",
    toolchain_identifier = "windriver-toolchain",
)

cc_toolchain_config(
    name = "cc_toolchain_config",
    as_executable = "@windriver_diab_windows//:diab-" + DIAB_VERSION + "/WIN64/bin/dcc.exe",
    asmopts = ASMOPTS,
    conlyopts = CONLYOPTS,
    copts = COPTS,
    cxxopts = [],
    dar_executable = "@windriver_diab_windows//:diab-" + DIAB_VERSION + "/WIN64/bin/dar.exe",
    dcc_executable = "@windriver_diab_windows//:diab-" + DIAB_VERSION + "/WIN64/bin/dcc.exe",
    defines = DEFINES,
    dld_executable = "@windriver_diab_windows//:diab-" + DIAB_VERSION + "/WIN64/bin/dld.exe",
    dplus_executable = "@windriver_diab_windows//:diab-" + DIAB_VERSION + "/WIN64/bin/dplus.exe",
    enable_lto = ENABLE_LTO,
    linkopts = LINKEROPTS,
    optimization_level = OPTIMIZATION_LEVEL,
    path_env_paths = ["@windriver_diab_windows//:path_env_directories"],
    strip_executable = "@windriver_diab_windows//:diab-" + DIAB_VERSION + "/WIN64/bin/striparm.exe",
)

toolchain(
    name = "windriver_r52_toolchain_linux",
    exec_compatible_with = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
    target_compatible_with = [
        "@bazel_platform//platforms/cpu:arm-r52",
    ],
    toolchain = ":windriver_cc_toolchain_linux",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
    visibility = ["//visibility:public"],
)

cc_toolchain(
    name = "windriver_cc_toolchain_linux",
    all_files = "@windriver_diab_linux//:all_files",
    ar_files = "@windriver_diab_linux//:all_files",
    as_files = "@windriver_diab_linux//:all_files",
    compiler_files = "@windriver_diab_linux//:all_files",
    dwp_files = "@windriver_diab_linux//:all_files",
    linker_files = "@windriver_diab_linux//:all_files",
    objcopy_files = "@windriver_diab_linux//:all_files",
    strip_files = "@windriver_diab_linux//:all_files",
    supports_header_parsing = True,
    supports_param_files = 0,
    toolchain_config = ":cc_toolchain_config_linux",
    toolchain_identifier = "windriver-toolchain",
)

cc_toolchain_config(
    name = "cc_toolchain_config_linux",
    as_executable = "@windriver_diab_linux//:diab-" + DIAB_VERSION + "/LINUX64/bin/dcc",
    asmopts = ASMOPTS,
    conlyopts = CONLYOPTS,
    copts = COPTS,
    cxxopts = [],
    dar_executable = "@windriver_diab_linux//:diab-" + DIAB_VERSION + "/LINUX64/bin/dar",
    dcc_executable = "@windriver_diab_linux//:diab-" + DIAB_VERSION + "/LINUX64/bin/dcc",
    defines = DEFINES,
    dld_executable = "@windriver_diab_linux//:diab-" + DIAB_VERSION + "/LINUX64/bin/dld",
    dplus_executable = "@windriver_diab_linux//:diab-" + DIAB_VERSION + "/LINUX64/bin/dplus",
    enable_lto = ENABLE_LTO,
    linkopts = LINKEROPTS,
    optimization_level = OPTIMIZATION_LEVEL,
    path_env_paths = ["@windriver_diab_linux//:path_env_directories"],
    strip_executable = "@windriver_diab_linux//:diab-" + DIAB_VERSION + "/LINUX64/bin/striparm",
)
