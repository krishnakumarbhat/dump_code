cc_library(
    name = "dd_gpt",
    srcs = [
        "dd_gpt.c",
    ],
    hdrs = [
    ],
    implementation_deps = [
    ],
    local_defines = select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":dd_gpt_h",
        "//software/common/versions:versions_hdrs",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:PLT_Appl_PlatformTime_h",
        "@boot//:boot_interface",
        "@build_config//:chandra_sfr_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)

cc_library(
    name = "dd_gpt_h",
    srcs = [
    ],
    hdrs = [
        "dd_gpt.h",
    ],
    implementation_deps = [
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@iND13400_autosar_sip//Components/Gpt:gpt_h",
    ],
)

cc_library(
    name = "dd_gpt_unit_test_lib",
    hdrs = [
        "dd_gpt.c",
    ],
    defines = [
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":dd_gpt_h",
    ],
)
