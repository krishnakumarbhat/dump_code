load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SWC_PLT_CDD_FailSafe",
    srcs = [
        "Source/FS_IntHndlr.c",
        "Source/FailSafe_Callout.c",
        "Source/SWC_PLT_CDD_FailSafe.c",
        "Source/SWC_PLT_CDD_FailSafe_Test.c",
    ],
    hdrs = [],
    defines = [],
    features = ["thin"],
    local_defines = select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }) + select({
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_FailSafe_h",
        "//software/common/versions:versions_hdrs",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb:SWC_PLT_CDD_MCU_Safety_h",
        "//software/r52/drivers/mcal/mcu_reset_wrapper",
        "@boot//:boot_interface",
        "@iND13400_autosar_sip//Components/Can:Can_h",
        "@iND13400_autosar_sip//Components/EthTrcv_30_Rtl9010:EthTrcv_30_Rtl9010_h",
        "@iND13400_autosar_sip//Components/EthTrcv_30_Tja1103:EthTrcv_30_Tja1103_h",
        "@iND13400_autosar_sip//Components/_Common:ComTypes_h",
        "@iND13400_autosar_sip//Components/_Common:Eth_GeneralTypes_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_FailSafe_h",
    srcs = [],
    hdrs = [
        "Include/FS_IntHndlr.h",
        "Include/FailSafe_Callout.h",
        "Include/SWC_PLT_CDD_FailSafe.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/Include",
    visibility = ["//visibility:public"],
    deps = [
        "@reuse",
    ],
)

cc_library(
    name = "FailSafe_Callout_unit_test_support_lib",
    hdrs = ["Source/FailSafe_Callout.c"],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_FailSafe_h",
        "//software/common/versions:versions_hdrs",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_FailSafe_unit_test_support_lib",
    hdrs = [
        "Source/SWC_PLT_CDD_FailSafe.c",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/versions:versions_hdrs",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe:SWC_PLT_CDD_FailSafe_h",
        "@boot//:boot_interface",
        "@iND13400_autosar_sip//Components/Can:Can_h",
        "@iND13400_autosar_sip//Components/EthTrcv_30_Rtl9010",
        "@iND13400_autosar_sip//Components/EthTrcv_30_Tja1103",
    ],
)

cc_library(
    name = "FS_IntHndlr_unit_test_support_lib",
    hdrs = ["Source/FS_IntHndlr.c"],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_FailSafe_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_MCU_Safety/bb:SWC_PLT_CDD_MCU_Safety_h",
    ],
)
