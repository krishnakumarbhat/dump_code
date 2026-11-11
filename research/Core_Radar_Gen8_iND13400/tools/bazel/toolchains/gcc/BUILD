load("@bazel_platform//toolchains/gcc:cc_toolchain_config.bzl", "cc_toolchain_config")

package(default_visibility = ["//visibility:public"])

# default toolchain on linux x86_64
toolchain(
    name = "gcc_linux_toolchain",
    exec_compatible_with = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
    tags = ["manual"],
    target_compatible_with = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
    toolchain = ":gcc_glibc_cc_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)

filegroup(
    name = "gcc_glibc_all_files",
    srcs = [
        "@bazel_platform//toolchains/go/binaries:mid",
        "@gcc-glibc//:all_files",
    ],
    target_compatible_with = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
)

cc_toolchain(
    name = "gcc_glibc_cc_toolchain",
    all_files = ":gcc_glibc_all_files",
    ar_files = ":gcc_glibc_all_files",
    compiler_files = ":gcc_glibc_all_files",
    dwp_files = ":gcc_glibc_all_files",
    linker_files = ":gcc_glibc_all_files",
    objcopy_files = ":gcc_glibc_all_files",
    strip_files = ":gcc_glibc_all_files",
    tags = ["manual"],
    target_compatible_with = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
    toolchain_config = ":gcc_glibc_cc_toolchain_config",
)

cc_toolchain_config(
    name = "gcc_glibc_cc_toolchain_config",
    ar_executable = "@gcc-glibc//:bin/x86_64-unknown-linux-gnu-ar",
    # For toolchain with sysroot need to specify path to the toolchain so that
    # linker will find libraries.
    builtin_relative_sysroot = "x86_64-unknown-linux-gnu/sysroot",
    cxxopts = select({
        "//software/bbe32/src:cdc_enable": ["-DCDC_ENABLE"],
        "//conditions:default": [],
    }),
    defines = [],
    exec_compatible_with = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
    gcc_executable = "@gcc-glibc//:bin/x86_64-unknown-linux-gnu-gcc",
    gcc_version = "11.4.0",
    gcov_executable = "@gcc-glibc//:bin/x86_64-unknown-linux-gnu-gcov",
    gplusplus_executable = "@gcc-glibc//:bin/x86_64-unknown-linux-gnu-g++",
    ld_executable = "@gcc-glibc//:bin/x86_64-unknown-linux-gnu-ld",
    static_link = False,
    strip_executable = "@gcc-glibc//:bin/x86_64-unknown-linux-gnu-strip",
    # For gcc toolchain with sysroot need to explicitly list include paths,
    # otherwise bazel inclusion checker will get confused with absolute paths
    # created in .d files by gcc. List of headers can be obtained with something like:
    #    bin/x86_64-linux-gcc -xc++ -E -v -
    system_includes = [
        "lib/gcc/x86_64-unknown-linux-gnu/11.4.0/include",
        "lib/gcc/x86_64-unknown-linux-gnu/11.4.0/include-fixed",
        "x86_64-unknown-linux-gnu/include",
        "x86_64-unknown-linux-gnu/include/c++/11.4.0",
        "x86_64-unknown-linux-gnu/include/c++/11.4.0/backward",
        "x86_64-unknown-linux-gnu/include/c++/11.4.0/x86_64-unknown-linux-gnu",
        "x86_64-unknown-linux-gnu/sysroot/usr/include",
    ],
    tags = ["manual"],
)
