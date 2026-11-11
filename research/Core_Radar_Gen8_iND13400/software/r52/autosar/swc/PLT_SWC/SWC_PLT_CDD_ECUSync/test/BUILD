cc_test(
    name = "SWC_PLT_CDD_ECUSync_unit_test",
    srcs = [
        "SWC_PLT_CDD_ECUSync_unit_test.cc",
        "stubs_ecusync_test.c",
    ],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync",
        "//software/r52/bb_radar_ctl:radar_look_h",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_ECUSync_external_fake_lib",
    srcs = [
        "SWC_PLT_CDD_ECUSync_external_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_CDD_ECUSync_external_fake.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync/test",
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync:SWC_PLT_CDD_ECUSync_external_h",
        "@fff",
    ],
)

cc_library(
    name = "Rte_SWC_PLT_CDD_Radar_Control_fake_lib",
    srcs = [
        "Rte_SWC_PLT_CDD_Radar_Control_fake.cc",
    ],
    hdrs = [
        "Rte_SWC_PLT_CDD_Radar_Control_fake.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync/test",
    visibility = ["//visibility:public"],
    deps = [
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":SWC_PLT_CDD_ECUSync_unit_test",
    ],
    visibility = [
        "//visibility:public",
    ],
)
