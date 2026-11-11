cc_library(
    name = "interference_detection_algo_fake_lib",
    srcs = [
        "interference_detection_algo_fake.cc",
    ],
    hdrs = [
        "interference_detection_algo_fake.h",
    ],
    features = ["-lto"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/common/ipc:ipc_data_h",
        "@fff",
        "@idbb//module/id_api:interference_detection_h",
        "@interference_detection_cfg//:id_algo_unit_test_support_lib",
    ],
)

cc_test(
    name = "interference_detection_algo_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "interference_detection_algo_unit_test.cc",
    ],
    defines = ["ID_GEN8"],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":interference_detection_algo_fake_lib",
        "@Gen8_iND13400//software/bbe32/test/mocks:ipc_mock_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":interference_detection_algo_unit_test",
        # Add other unit tests here.
    ],
    visibility = ["//visibility:public"],
)
