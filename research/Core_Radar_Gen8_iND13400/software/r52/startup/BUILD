cc_library(
    name = "mpu_r52_h",
    srcs = [],
    hdrs = [
        "mpu_r52.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@reuse",
    ],
)

cc_library(
    name = "startup",
    srcs = [
        "crt0.S",
        "mpu_r52.c",
        "r52_isr.S",
        "startup.c",
    ],
    hdrs = [],
    data = [],
    defines = [],
    features = ["-lto"],
    implementation_deps = [
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_r52",
        ":mpu_r52_h",
    ],
    visibility = ["//software/r52:__pkg__"],
    deps = [],
)
