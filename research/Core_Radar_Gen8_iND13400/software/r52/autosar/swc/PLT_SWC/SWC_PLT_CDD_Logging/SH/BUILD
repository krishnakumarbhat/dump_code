load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "sh_interface_h",
    hdrs = [
        "sh_interface.h",
    ],
    strip_include_prefix = ".",
    visibility = [
        "//visibility:public",
    ],
    deps = [
        "@Gen8_iND13400//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "@iND13400_autosar_sip//Components/Os:Os_h",
        "@shbb//module/_api:sh_api_h",
    ],
)

cc_library(
    name = "sh_interface_lib",
    srcs = [
        "sh_interface.c",
    ],
    strip_include_prefix = ".",
    visibility = [
        "//visibility:public",
    ],
    deps = [
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:PLT_Appl_PlatformTime_h",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging:SWC_PLT_CDD_LOGGING_h",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging/SH:sh_interface_h",
        "@Gen8_iND13400//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "@iND13400_autosar_sip//Components/Os:Os_h",
        "@shbb//module:bb_sh_module_lib",
        "@shbb//module/_imp/_inc:sh_module_imp_inc_h",  # Added for Send_Stream_Internal fptr
    ],
)

cc_library(
    name = "sh_interface_ut_lib",
    srcs = ["sh_interface.c"],
    hdrs = [
        "sh_interface.h",
    ],
    strip_include_prefix = ".",
    visibility = [
        "//visibility:public",
    ],
    deps = [
        ":sh_interface_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_Logging:SWC_PLT_CDD_LOGGING_h",
        "@Gen8_iND13400//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:PLT_Appl_PlatformTime_h",
        "@fff",
        "@iND13400_autosar_sip//Components/Os:Os_h",
        "@shbb//module/_api:sh_api_h",
        "@shbb//module/_imp/_inc:sh_module_imp_inc_h",  # added for send_stream_internal
    ],
)
