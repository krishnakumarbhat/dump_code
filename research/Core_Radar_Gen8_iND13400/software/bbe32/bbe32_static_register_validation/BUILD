exports_files([
    "bbe32_static_register_validation.c",
    "bbe32_static_register_validation.h",
])

cc_library(
    name = "bbe32_static_register_validation_h",
    hdrs = [
        "bbe32_static_register_validation.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
    ],
)

cc_library(
    name = "bbe32_static_register_validation_lib",
    srcs = [
        "bbe32_static_register_validation.c",
        "bbe32_static_register_validation_cfg.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":bbe32_static_register_validation_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/common/crc_calc:crc_calc_c",
    ],
)

cc_library(
    name = "bbe32_static_register_validation_ut_lib",
    hdrs = [
        "bbe32_static_register_validation.c",
        "bbe32_static_register_validation_cfg.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":bbe32_static_register_validation_h",
        "//software/bbe32/inc:ipc_dsp_h",
        "//software/common/crc_calc:crc_calc_h",
    ],
)
