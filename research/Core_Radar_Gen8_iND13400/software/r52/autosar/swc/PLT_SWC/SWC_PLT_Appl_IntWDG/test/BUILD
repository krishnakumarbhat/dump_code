cc_library(
    name = "SWC_PLT_Appl_IntWDG_fake_lib",
    srcs = [
        "SWC_PLT_Appl_IntWDG_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_Appl_IntWDG_fake.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IntWDG/test",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@fff",
        "@iND13400_autosar_sip//Components/WdgM:WdgM_h",
    ],
)

cc_test(
    name = "SWC_PLT_Appl_IntWDG_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_Appl_IntWDG_unit_test.cc",
    ],
    copts = [
        "-Isoftware/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IntWDG/Include",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_IntWDG_fake_lib",
        "//software/common/calibrations/smc:smc_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_IntWDG:SWC_PLT_Appl_IntWDG_unit_test_support_lib",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":SWC_PLT_Appl_IntWDG_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
