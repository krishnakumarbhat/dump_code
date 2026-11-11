cc_library(
    name = "SWC_PRJ_Appl_FaultMgr_fake_lib",
    srcs = [
        "SWC_PRJ_Appl_FaultMgr_fake.cc",
    ],
    hdrs = [
        "NvM.h",
        "SWC_PRJ_Appl_FaultMgr_fake.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_FaultMgr/test",
    deps = [
        "//software/common/calibrations/psc:psc_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj_h",
        "@fff",
    ],
)

cc_test(
    name = "SWC_PRJ_Appl_FaultMgr_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PRJ_Appl_FaultMgr_unit_test.cc",
    ],
    defines = [],
    linkopts = [],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PRJ_Appl_FaultMgr_fake_lib",
        "//software/common/calibrations/psc:psc_module",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Prj_h",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_FaultMgr:SWC_PRJ_Appl_FaultMgr_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "Appl_FaultMgr_unit_tests",
    tests = [
        ":SWC_PRJ_Appl_FaultMgr_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
