cc_library(
    name = "SWC_PLT_Appl_ModeManager_fake_lib",
    srcs = [
        "SWC_PLT_Appl_ModeManager_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_Appl_ModeManager_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager:PLT_Appl_ModeManager_h",
        "@fff",
        "@iND13400_autosar_sip//Components/Dio:Dio_h",
    ],
)

cc_test(
    name = "SWC_PLT_Appl_ModeManager_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_Appl_ModeManager_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager:SWC_PLT_Appl_ModeManager_Cfg_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager:SWC_PLT_Appl_ModeManager_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager/test:SWC_PLT_Appl_ModeManager_fake_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":SWC_PLT_Appl_ModeManager_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)

cc_library(
    name = "modemanager_fake_lib",
    srcs = [
        "@SWC_PLT_Appl_ModeManager//test:modemanager_fake.cc",
    ],
    hdrs = [
        "@SWC_PLT_Appl_ModeManager//test:modemanager_fake.h",
    ],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager:modemanager_unit_test_support_lib",
        "@fff",
    ],
)

cc_test(
    name = "modemanager_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "@SWC_PLT_Appl_ModeManager//test:modemanager_unit_test.cc",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":modemanager_fake_lib",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager:modemanager_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "plt_unit_tests",
    tests = [
        ":modemanager_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
