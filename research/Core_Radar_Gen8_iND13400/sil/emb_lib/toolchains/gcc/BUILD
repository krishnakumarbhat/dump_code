load("@bazel_platform//toolchains/gcc:cc_toolchain_config.bzl", "cc_toolchain_config")

package(default_visibility = ["//visibility:public"])

toolchain(
    name = "gcc_glibc_toolchain",
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
    builtin_relative_sysroot = "x86_64-unknown-linux-gnu/sysroot",
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
