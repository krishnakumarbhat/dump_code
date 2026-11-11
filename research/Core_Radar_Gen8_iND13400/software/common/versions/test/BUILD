cc_test(
    name = "versions_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "versions_unit_test.cc",
    ],
    visibility = ["//visibility:private"],
    deps = [
        "//tools/bazel/fff",
        "@//software/common/versions:versions_unit_test_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":versions_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
