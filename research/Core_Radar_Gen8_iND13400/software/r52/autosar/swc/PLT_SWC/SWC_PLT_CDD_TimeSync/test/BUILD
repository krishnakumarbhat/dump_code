cc_test(
    name = "SWC_PLT_CDD_TimeSync_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_CDD_TimeSync_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_TimeSync_fake_lib",
        ":SWC_PLT_CDD_TimeSync_swc_textual_lib",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync:SWC_PLT_CDD_TimeSync_cfg_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync:SWC_PLT_CDD_TimeSync_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync:SWC_PLT_CDD_TimeSync_source_support_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "SWC_PLT_CDD_TimeSync_Master_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_CDD_TimeSync_Master_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_TimeSync_Master_fake_lib",
        ":SWC_PLT_CDD_TimeSync_Master_swc_textual_lib",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync:SWC_PLT_CDD_TimeSync_cfg_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync:SWC_PLT_CDD_TimeSync_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync:SWC_PLT_CDD_TimeSync_source_support_lib",
        "@Sensor_Position//:sensor_position_h",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_TimeSync_swc_textual_lib",
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    textual_hdrs = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync:Source/SWC_PLT_CDD_TimeSync.c",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "SWC_PLT_CDD_TimeSync_Master_swc_textual_lib",
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    textual_hdrs = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_TimeSync:Source/SWC_PLT_CDD_TimeSync_Master.c",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "SWC_PLT_CDD_TimeSync_fake_lib",
    srcs = [
        "SWC_PLT_CDD_TimeSync_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_CDD_TimeSync_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@fff",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_TimeSync_Master_fake_lib",
    srcs = [
        "SWC_PLT_CDD_TimeSync_Master_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_CDD_TimeSync_Master_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":SWC_PLT_CDD_TimeSync_Master_unit_test",
        ":SWC_PLT_CDD_TimeSync_unit_test",
    ],
    visibility = [
        "//visibility:public",
    ],
)
