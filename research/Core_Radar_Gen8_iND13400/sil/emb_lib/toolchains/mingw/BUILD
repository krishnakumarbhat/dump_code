load("@bazel_platform//toolchains/mingw:cc_toolchain_config.bzl", "cc_toolchain_config")

package(default_visibility = ["//visibility:public"])

# default toolchain on windows x86_64
# Need to add for linux too
toolchain(
    name = "mingw_windows_toolchain",
    exec_compatible_with = [
        "@platforms//os:windows",
        "@platforms//cpu:x86_64",
    ],
    target_compatible_with = [
        "@platforms//os:windows",
        "@platforms//cpu:x86_64",
    ],
    target_settings = [
        "@bazel_platform//toolchains:host_compiler_gcc",
    ],
    toolchain = ":mingw_cc_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)

cc_toolchain(
    name = "mingw_cc_toolchain",
    all_files = "@mingw//:all_files",
    compiler_files = "@mingw//:compiler_files",
    dwp_files = "@mingw//:dwp_files",
    linker_files = "@mingw//:linker_files",
    objcopy_files = "@mingw//:objcopy_files",
    strip_files = "@mingw//:strip_files",
    toolchain_config = ":mingw_cc_toolchain_config",
)

cc_toolchain_config(
    name = "mingw_cc_toolchain_config",
    ar_executable = "@mingw//:bin/ar.exe",
    defines = ["WIN32"],
    gcc_executable = "@mingw//:bin/gcc.exe",
    gcov_executable = "@mingw//:bin/gcov.exe",
    gplusplus_executable = "@mingw//:bin/g++.exe",
    ld_executable = "@mingw//:bin/ld.exe",
    strip_executable = "@mingw//:bin/strip.exe",
    system_includes = [
        "lib/gcc/x86_64-w64-mingw32/14.2.0/include",
        "lib/gcc/x86_64-w64-mingw32/14.2.0/include-fixed",
        "lib/gcc/x86_64-w64-mingw32/14.2.0/include/c++",
        "lib/gcc/x86_64-w64-mingw32/14.2.0/include/c++/x86_64-w64-mingw32",
        "lib/gcc/x86_64-w64-mingw32/14.2.0/include/c++/backward",
        "x86_64-w64-mingw32/include",
        "include",
    ],
)
