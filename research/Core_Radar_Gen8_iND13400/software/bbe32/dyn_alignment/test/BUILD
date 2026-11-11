cc_library(
    name = "dyn_align_wrapper_mocks_lib",
    srcs = [
        "dyn_align_wrapper_fake.cc",
    ],
    hdrs = [
        "dyn_align_wrapper_fake.h",
    ],
    features = ["-lto"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@fff",
    ],
)

cc_test(
    name = "dyn_align_wrapper_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "dyn_align_wrapper_unit_test.cc",
    ],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":dyn_align_wrapper_mocks_lib",
        "@Dyn_alignment_module_interface//:dyn_align_wrapper_unit_test_support_lib",
        "@Gen8_iND13400//software/common/calibrations/smc:smc_module",
        "@appl_inclusion_dep//:dabb_include_h",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":dyn_align_wrapper_unit_test",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "dyn_align_main_mocks_lib",
    srcs = [
        "dyn_align_main_fake.cc",
    ],
    hdrs = [
        "dyn_align_main_fake.h",
    ],
    features = ["-lto"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Dyn_alignment_module_interface//:dyn_align_wrapper_unit_test_support_lib",
        "@fff",
    ],
)
