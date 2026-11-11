cc_test(
    name = "rc_wrapper_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "rc_wrapper_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":RC_wrapper_mocks_lib",
        "@com_google_googletest//:gtest_main",
        "@radar_capability_module_interface//:radar_capability_wrapper_unit_test_support_lib",
        "@rcbb//module/capability:radar_capability_unit_test_support_lib",
        "@rcbb//module/capability/DM:damping_monitor_unit_test_support_lib",
        "@rcbb//module/capability/FSC:free_sight_check_unit_test_support_lib",
        "@rcbb//module/capability/PBD:partial_blockage_detector_unit_test_support_lib",
        "@rcbb//module/capability/RE:range_estimation_unit_test_support_lib",
        "@rcbb//module/capability/SE:scene_estimation_unit_test_support_lib",
        "@rcbb//module/capability/blockage:blockage_unit_test_support_lib",
        "@rcbb//module/capability/diagnostics:rc_diagnostics_unit_test_support_lib",
        "@rcbb//module/test/rcbb_fff:fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":rc_wrapper_unit_test",
        # Add other unit tests here
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "rc_main_mocks_lib",
    srcs = [
        "rc_main_fake.cc",
    ],
    hdrs = [
        "rc_main_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@fff",
        "@radar_capability_module_interface//:radar_capability_wrapper_unit_test_support_lib",
    ],
)

cc_library(
    name = "RC_wrapper_mocks_lib",
    srcs = [
        "rc_wrapper_fake.cc",
    ],
    hdrs = [
        "rc_wrapper_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Dyn_alignment_module_interface//:dyn_align_wrapper_h",
        "@Gen8_iND13400//software/bbe32/inc:mem_pool_h",
        "@appl_inclusion_dep//:dabb_include_h",
        "@fff",
    ],
)
