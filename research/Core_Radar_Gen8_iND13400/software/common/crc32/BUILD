exports_files([
    "src/crc32.c",
    "inc/crc32.h",
])

cc_library(
    name = "crc32_ut_lib",
    hdrs = ["src/crc32.c"],
    strip_include_prefix = "src",
    visibility = ["//visibility:public"],
    deps = [":crc32"],
)

cc_library(
    name = "crc32_h",
    hdrs = [
        "inc/crc32.h",
    ],
    data = [],
    defines = [],
    implementation_deps = [
    ],
    strip_include_prefix = "inc",
    visibility = ["//visibility:public"],
    deps = [
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
    ],
)

cc_library(
    name = "crc32",
    srcs = [
        "src/crc32.c",
    ],
    hdrs = [],
    data = [],
    defines = [],
    implementation_deps = [
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":crc32_h",
    ],
)
