cc_library(
    name = "calibtool",
    srcs = [
        "@calibtool//:c_src/ct_boundaries_check_function_helpers.c",
        "@calibtool//:c_src/ct_endianness_switch.c",
    ],
    hdrs = [
        "@calibtool//:c_src/ct_boundaries_check_function_helpers.h",
        "@calibtool//:c_src/ct_calibration_header_t.h",
        "@calibtool//:c_src/ct_endianness_switch.h",
    ],
    strip_include_prefix = "/c_src",
    visibility = ["//visibility:public"],
    deps = ["//ff_emb_lib/sfl/math_library:mathlib_reuse"],
)
