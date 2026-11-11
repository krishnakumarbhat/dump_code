cc_library(
    name = "SWC_PLT_Appl_NvMHandler",
    srcs = [
        "Source/SWC_PLT_Appl_NvMHandler.c",
    ],
    hdrs = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_NvMHandler_h",
        "//software/common/crc32",
        "//software/common/crc32:crc32_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@iND13400_autosar_sip//Components/Fee_30_FlexNor",
        "@iND13400_autosar_sip//Components/Fls",
        "@iND13400_autosar_sip//Components/NvM",
        "@iND13400_autosar_sip//Components/_Common:BSW_Common_h",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_NvMHandler_h",
    srcs = [],
    hdrs = [
        "Include/SWC_PLT_Appl_NvMHandler.h",
    ],
    defines = [],
    strip_include_prefix = "Include",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "SWC_PLT_Appl_NvMHandler_unit_test_support_lib",
    srcs = [],
    hdrs = ["Source/SWC_PLT_Appl_NvMHandler.c"],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_NvMHandler/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_NvMHandler/test:SWC_PLT_Appl_NvMHandler_fake_lib",
    ],
)
