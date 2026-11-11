load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "SWC_CDD_IPC_fake_lib",
    srcs = [
        "SWC_CDD_IPC_fake.cc",
    ],
    hdrs = [
        "SWC_CDD_IPC_MemMap.h",
        "SWC_CDD_IPC_fake.h",
        "crc_calc.h",
        "ipc_mss.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/ipc:ipc_data_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/program_flow_monitor:program_flow_monitor_h",
        "@fff",
    ],
)

cc_test(
    name = "swc_cdd_ipc_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_CDD_IPC_unit_test.cc",
    ],
    copts = [
        "-Isoftware/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/test",
        "-fpermissive",
    ],
    defines = ["XCP_FAULT_INJECTION"],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_CDD_IPC_fake_lib",
        "//software/building_block/sh_cfg:sh_module_cfg_h",
        "//software/common/calibrations/smc:smc_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC:SWC_CDD_IPC_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/VSE:vse_core_c_api",
        "@com_google_googletest//:gtest_main",
        "@fff",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":swc_cdd_ipc_unit_test",
    ],
    visibility = ["//visibility:public"],
)
