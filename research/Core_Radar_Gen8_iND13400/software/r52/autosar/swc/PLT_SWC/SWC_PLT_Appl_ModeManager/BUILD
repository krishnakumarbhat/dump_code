cc_library(
    name = "SWC_PLT_Appl_ModeManager",
    srcs = [
        "Source/SWC_PLT_Appl_ModeManager.c",
        "Source/SWC_PLT_Appl_ModeManager_Test.c",
    ],
    defines = [],
    local_defines = select({
        "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
        "//conditions:default": [],
    }) + select({
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    visibility = ["//visibility:public"],
    deps = [
        ":PLT_Appl_ModeManager_h",
        "//software/common/versions",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager:PLT_Appl_ModeManager",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager:SWC_PLT_Appl_ModeManager_Cfg_h",
        "@reuse",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_ModeManager_Cfg_h",
    srcs = [],
    hdrs = ["Include/SWC_PLT_Appl_ModeManager_Cfg.h"],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/versions:versions_hdrs",
        "@iND13400_autosar_sip//Components/Dio:Dio_h",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_ModeManager_unit_test_support_lib",
    srcs = [],
    hdrs = ["Source/SWC_PLT_Appl_ModeManager.c"],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager/Source",
    visibility = ["//visibility:public"],
    deps = [
        ":PLT_Appl_ModeManager_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager:SWC_PLT_Appl_ModeManager_Cfg_h",
    ],
)

cc_library(
    name = "PLT_Appl_ModeManager",
    srcs = [
        "@SWC_PLT_Appl_ModeManager//Source:modemanager.c",
    ],
    hdrs = [],
    includes = ["@SWC_PLT_Appl_ModeManager//"],
    local_defines =
        select({
            "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
            "//conditions:default": [],
        }) + select({
            "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
            "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
            "//conditions:default": [],
        }),
    visibility = ["//visibility:public"],
    deps = [
        ":PLT_Appl_ModeManager_h",
        "//software/common/versions",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager:SWC_PLT_Appl_ModeManager_Cfg_h",
        "//software/r52/drivers/mcal/gpt:dd_gpt_h",
        "@boot//:boot_interface",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "PLT_Appl_ModeManager_h",
    srcs = [],
    hdrs = ["@SWC_PLT_Appl_ModeManager//Include:modemanager.h"],
    defines = [],
    local_defines =
        select({
            "//:Build_XCP_FAULT_INJECTION_Test_Cases": ["XCP_FAULT_INJECTION"],
            "//conditions:default": [],
        }),
    # this is required for including path externally automatically Don't remove this comment
    strip_include_prefix = "/Include",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager:SWC_PLT_Appl_ModeManager_Cfg_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:PLT_Appl_PlatformTime_h",
        "@Gen8_iND13400//software/r52/drivers/mcal/gpt:dd_gpt_h",
    ],
)

cc_library(
    name = "modemanager_unit_test_support_lib",
    hdrs = [
        "@SWC_PLT_Appl_ModeManager//Source:modemanager.c",
    ],
    strip_include_prefix = "/Source",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_ModeManager:PLT_Appl_ModeManager_h",
        "@reuse//:fixmac",
    ],
)
