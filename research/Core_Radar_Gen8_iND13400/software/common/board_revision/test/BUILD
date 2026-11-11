cc_test(
    name = "board_revision_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "board_revision_unit_test.cc",
    ],
    copts = ["-fno-exceptions"],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/board_revision:board_revision_unit_test_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":board_revision_unit_test",
    ],
    visibility = ["//visibility:public"],
)
