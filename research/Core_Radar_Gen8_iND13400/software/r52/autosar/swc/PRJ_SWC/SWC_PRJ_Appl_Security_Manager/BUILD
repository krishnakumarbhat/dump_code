load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SWC_PRJ_Appl_Security_Manager",
    srcs = [
        "Source/SWC_PRJ_Appl_Security_Manager.c",
        "Source/SWC_Security_Manager_Common.c",
    ],
    hdrs = [
        "Include/SWC_Security_Manager_Common.h",
    ],
    local_defines = select({
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    strip_include_prefix = "Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "@iND13400_autosar_sip//Components/Crypto:Crypto_h",
    ],
)
