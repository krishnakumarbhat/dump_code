load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "hil_project_interface_h",
    srcs = [],
    hdrs = ["hil_interface.h"],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_library(
    name = "hil_project_interface_lib",
    srcs = ["hil_interface.c"],
    hdrs = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":hil_project_interface_h",
        "//software/common:UDPLoggingStreamHeaders",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:PLT_Appl_PlatformTime_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging:SWC_PLT_CDD_LOGGING_h",
        "//software/r52/dsp_setup:dsp_setup_h",
        "//software/r52/ipc:ipc_mss_h",
        "@hilbb//module:bb_hil_module_lib",
        "@hilbb//module/_api:hil_communication_handler_h",
        "@iND13400_autosar_sip//Components/SoAd",
        "@shbb//module/_api:sh_api_h",
    ],
)

cc_library(
    name = "hil_interface_ut_lib",
    srcs = [],
    hdrs = [
        "hil_interface.c",
        "hil_interface.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/dsp_setup:dsp_setup_h",
        "//software/r52/ipc:ipc_mss_h",
        "@fff",
    ],
)
