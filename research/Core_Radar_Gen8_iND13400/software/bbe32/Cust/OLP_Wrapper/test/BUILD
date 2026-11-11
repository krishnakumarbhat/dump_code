load("@bazel_platform//tools/gcovr:rule.bzl", "gcovr_report")

package(
    default_visibility = ["//visibility:public"],
)

cc_test(
    name = "OLP_Wrapper_unit_test",
    size = "small",
    srcs = ["OLP_Wrapper_Test.cpp"],
    defines = [
        "UNIT_TEST",
        "OLP_OBJ_SOURCE_F360",
    ],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    deps = [
        "//software/a53/Cust/OLP_Wrapper:Olp_wrapper_h",
        "//software/a53/Cust/OLP_Wrapper:olp_wrapper_lib_unit",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

# 1. bazel test ...  - to generate coverage info
# 2. bazel run //software/test:coverage - to generate the report.
# 3. report will be in /bazel-bin/software/test/coverage_gcovr_report
gcovr_report(
    name = "coverage",
    tests = [
        ":OLP_Wrapper_unit_test",
    ],
)
