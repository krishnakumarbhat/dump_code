cc_library(
    name = "static_alignment_mocks_lib",
    srcs = [
        "static_align_main_fake.cc",
    ],
    hdrs = [
        "static_align_main_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@fff",
        "@sabb//module/static_alignment/static_alignment_api:static_alignment_algo_inc",
    ],
)

cc_test(
    name = "static_align_wrapper_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "static_align_wrapper_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":static_alignment_mocks_lib",
        "@Static_alignment_module_interface//:alignment_wrapper_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":static_align_wrapper_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//visibility:public",
    ],
)
