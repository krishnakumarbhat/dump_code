load("@rules_cc//cc:defs.bzl", "cc_test")

# Unit test for embedded tracker wrapper with stub code, TRACKER_ENABLED, and AL variant.
# Run with: bazelisk test //software/bbe32/emb_tracker/test:unit_tests  --tracker_variant=AL -c dbg
cc_test(
    name = "unit_tests_with_stub",
    size = "small",
    srcs = [
        "emb_tracker_wrapper_test.cpp",
    ],
    features = ["-lto"],
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_googletest//:gtest_main",
        "@emb_tracker_wrapper//:emb_tracker_wrapper_with_stubs",
    ],
)

cc_test(
    name = "unit_tests_without_stub",
    size = "small",
    srcs = [
        "emb_tracker_wrapper_api_test.cpp",
    ],
    features = ["-lto"],
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_googletest//:gtest_main",
        "@emb_tracker_wrapper//:emb_tracker_wrapper_without_stubs",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":unit_tests_with_stub",
        ":unit_tests_without_stub",
    ],
    visibility = ["//visibility:public"],
)
