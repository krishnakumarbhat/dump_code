load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "hil_if_mock_lib",
    srcs = [
        "hil_interface_fff.cc",
    ],
    hdrs = [
        "hil_interface_fff.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:UDPLoggingStreamHeaders",
        "//software/common/ipc:ipc_data_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_HIL/hil:hil_project_interface_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging/SH:sh_interface_h",
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "//software/r52/dsp_setup:dsp_setup_h",
        "@Sensor_Position//:sensor_position_h",
        "@fff",
        "@iND13400_autosar_sip//Components/SoAd",
        "@sh_module_cfg//:sh_module_cfg_h",
        "@shbb//module/_api:sh_api_h",
    ],
    alwayslink = True,
)
