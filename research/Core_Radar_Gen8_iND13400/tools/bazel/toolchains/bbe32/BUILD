load("@bazel_platform//toolchains/xtensa:cc_toolchain_config.bzl", "cc_toolchain_config")

package(default_visibility = ["//visibility:public"])

XTENSA_CORE = "bbe32_luna"  # change this to bbe32_luna_fpga for FPGA builds, which are currently not supported by Bzlmod as they are obsolete

COPTS = select({
    "//software/bbe32/src:cdc_enable": ["-DCDC_ENABLE"],
    "//conditions:default": [],
}) + [
    "-O2",
    "-g",
    "-Wall",
    "-DNDEBUG",
    "-fno-strict-aliasing",
    "-fmessage-length=0",
    "-Werror",
    "-Wextra",
    "-Wshadow",
    "-Wwrite-strings",
    "-fno-asynchronous-unwind-tables",
    "-fno-unwind-tables",
    "-fno-omit-frame-pointer",
    "-fno-exceptions",
    "-ffunction-sections",
    "-fdata-sections",
    "-fno-threadsafe-statics",
    "-mlongcalls",  # This allows use of system memory for program
    "-Wno-unused-but-set-variable",
]

CXXOPTS = [
    "-g",
    "-O2",
    "-DNDEBUG",
    "-stdlib=libc++-re",
    "-fno-asynchronous-unwind-tables",
    "-fno-unwind-tables",
    "-fno-omit-frame-pointer",
    "-fno-exceptions",
    "-fno-threadsafe-statics",
    "-fno-dwarf2-cfi-asm",
    "-mlongcalls",  # This allows use of system memory for program
    "-std=c++11",
]

LINKEROPTS = [
    "--xtensa-params=",
    "-fno-use-cxa-atexit",
    "-Wl,--gc-sections",
]

ASMOPTS = [
]

DEFINES = [
    "XTENSA_LX7",
    "PROC_overlay",
    "CONFIG_overlay",
]

toolchain(
    name = "bbe_toolchain_windows",
    exec_compatible_with = [
        "@platforms//os:windows",
        "@platforms//cpu:x86_64",
    ],
    target_compatible_with = [
        "@build_config//cpu:bbe32",
    ],
    toolchain = ":bbe_cc_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
    visibility = ["//visibility:public"],
)

cc_toolchain(
    name = "bbe_cc_toolchain",
    all_files = "@bbe_windows_luna//:all_files",
    compiler_files = "@bbe_windows_luna//:all_files",
    dwp_files = "@bbe_windows_luna//:all_files",
    linker_files = "@bbe_windows_luna//:all_files",
    objcopy_files = "@bbe_windows_luna//:all_files",
    strip_files = "@bbe_windows_luna//:all_files",
    supports_header_parsing = True,
    supports_param_files = 0,
    toolchain_config = ":cc_toolchain_config",
    toolchain_identifier = "bbe-toolchain",
)

cc_toolchain_config(
    name = "cc_toolchain_config",
    archiver_executable = "@bbe_windows//:tools/RJ-2025.5-win32/XtensaTools/bin/xt-ar.exe",
    asmopts = ASMOPTS,
    assembler_executable = "@bbe_windows//:tools/RJ-2025.5-win32/XtensaTools/bin/xt-as.exe",
    c_executable = "@bbe_windows//:tools/RJ-2025.5-win32/XtensaTools/bin/xt-clang.exe",
    compiler_inc_paths = ["@bbe_windows_luna//:compiler_include_directories"],
    copts = COPTS,
    cpp_executable = "@bbe_windows//:tools/RJ-2025.5-win32/XtensaTools/bin/xt-clang++.exe",
    cxxopts = CXXOPTS,
    defines = DEFINES,
    enable_lto = "ThinLTO",  # LTO and the -safety option cannot be used at the same time
    license_server = "27001@nlnhsrk-is22.aptiv.com;27001@nlnhsrk-ap49.aptiv.com",
    link_executable = "@bbe_windows//:tools/RJ-2025.5-win32/XtensaTools/bin/xt-clang++.exe",
    linker_support_package = "//software/common/linker:linker_support_package",
    linkopts = LINKEROPTS,
    strip_executable = "@bbe_windows//:tools/RJ-2025.5-win32/XtensaTools/bin/xt-strip.exe",
    xtensa_core = XTENSA_CORE,
    xtensa_system_path = "@bbe_windows_luna//:config",
)

toolchain(
    name = "bbe_toolchain_linux",
    exec_compatible_with = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
    target_compatible_with = [
        "@build_config//cpu:bbe32",
    ],
    toolchain = ":bbe_cc_toolchain_linux",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
    visibility = ["//visibility:public"],
)

cc_toolchain(
    name = "bbe_cc_toolchain_linux",
    all_files = "@bbe_linux_luna//:all_files",
    compiler_files = "@bbe_linux_luna//:all_files",
    dwp_files = "@bbe_linux_luna//:all_files",
    linker_files = "@bbe_linux_luna//:all_files",
    objcopy_files = "@bbe_linux_luna//:all_files",
    strip_files = "@bbe_linux_luna//:all_files",
    supports_header_parsing = True,
    supports_param_files = 0,
    toolchain_config = ":cc_toolchain_config_linux",
    toolchain_identifier = "bbe-toolchain",
)

cc_toolchain_config(
    name = "cc_toolchain_config_linux",
    archiver_executable = "@bbe_linux//:tools/RJ-2025.5-linux/XtensaTools/bin/xt-ar",
    asmopts = ASMOPTS,
    assembler_executable = "@bbe_linux//:tools/RJ-2025.5-linux/XtensaTools/bin/xt-as",
    c_executable = "@bbe_linux//:tools/RJ-2025.5-linux/XtensaTools/bin/xt-clang",
    compiler_inc_paths = ["@bbe_linux_luna//:compiler_include_directories"],
    copts = COPTS,
    cpp_executable = "@bbe_linux//:tools/RJ-2025.5-linux/XtensaTools/bin/xt-clang++",
    cxxopts = CXXOPTS,
    defines = DEFINES,
    enable_lto = "ThinLTO",  # LTO and the -safety option cannot be used at the same time
    license_server = "27001@nlnhsrk-is22.aptiv.com:27001@nlnhsrk-ap49.aptiv.com",
    link_executable = "@bbe_linux//:tools/RJ-2025.5-linux/XtensaTools/bin/xt-clang++",
    linker_support_package = "//software/common/linker:linker_support_package",
    linkopts = LINKEROPTS,
    strip_executable = "@bbe_linux//:tools/RJ-2025.5-linux/XtensaTools/bin/xt-strip",
    xtensa_core = XTENSA_CORE,
    xtensa_system_path = "@bbe_linux_luna//:config",
)
