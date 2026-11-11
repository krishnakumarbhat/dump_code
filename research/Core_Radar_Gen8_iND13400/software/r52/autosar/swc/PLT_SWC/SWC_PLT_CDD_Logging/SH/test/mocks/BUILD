load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "sh_interface_mock_lib",
    srcs = [
        "sh_interface_fff.c",
    ],
    hdrs = [
        "sh_interface_fff.h",
    ],
    copts = [
        "-DUNIT_TEST",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:UDPLoggingStreamHeaders",
        "//software/common:radar_look_types",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging/SH:sh_interface_ut_lib",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging:SWC_PLT_CDD_LOGGING_h",
        "@fff",
        "@sh_module_cfg//:sh_module_cfg_h",
    ],
)
