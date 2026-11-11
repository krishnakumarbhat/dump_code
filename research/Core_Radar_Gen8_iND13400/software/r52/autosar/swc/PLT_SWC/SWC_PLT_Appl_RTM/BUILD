cc_library(
    name = "SWC_PLT_Appl_RTM",
    srcs = [
        "source/SWC_PLT_Appl_RTM.c",
    ],
    hdrs = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "@iND13400_autosar_sip//Components/Det:Det_h",
        "@iND13400_autosar_sip//Components/Gpt:gpt_h",
        "@iND13400_autosar_sip//Components/Rtm:Rtm_h",
        "@reuse",
    ],
)

cc_library(
    name = "appl_RTM_unit_test_support_lib",
    hdrs = [
        "source/SWC_PLT_Appl_RTM.c",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_RTM/source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_RTM",
    ],
)
