load("//tools/bazel/scripts:ld_preprocess.bzl", "ld_preprocess")
load("@emb_tracker_wrapper//:emb_tracker_project_profile.bzl", "EMB_TRACKER_PROJECT_PROFILE")

exports_files(
    [
        "bbe32.ld",
        "common.ld",
        "r52.ld",
    ],
    visibility = [
        "//software/bbe32:__pkg__",
        "//software/r52:__pkg__",
    ],
)

filegroup(
    name = "linker_support_package",
    srcs = glob(
        include = [
            "bbe32",
        ],
        allow_empty = False,
        exclude_directories = 0,
    ),
    visibility = [
        "//software/bbe32:__pkg__",
        "//tools/bazel/toolchains/bbe32:__pkg__",
    ],
)

ld_preprocess(
    name = "common_ld",
    src = "common.ld",
    args = select({
        "//:Build_enable_phy_100Mb": ["-DEnable_PHY_100Mb"],
        "//conditions:default": [],
    }) + select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:VEH_SOMEIP": ["-DVEH_SOMEIP"],
        "//conditions:default": ["-DVEH_CAN"],
    }),
    local_defines = EMB_TRACKER_PROJECT_PROFILE().TRACKER_ENABLED_DEFINES,
    preprocess_compiler_executable = select({
        "@platforms//os:windows": "@clang_windows//:bin/clang.exe",
        "//conditions:default": "@clang_linux//:bin/clang",
    }),
    visibility = [
        "//software/bbe32:__pkg__",
        "//software/r52:__pkg__",
    ],
)

ld_preprocess(
    name = "r52_ld",
    src = "r52.ld",
    args = select({
        "//:Build_enable_phy_100Mb": ["-DEnable_PHY_100Mb"],
        "//conditions:default": [],
    }) + select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:VEH_SOMEIP": ["-DVEH_SOMEIP"],
        "//conditions:default": ["-DVEH_CAN"],
    }),
    local_defines = EMB_TRACKER_PROJECT_PROFILE().TRACKER_ENABLED_DEFINES,
    preprocess_compiler_executable = select({
        "@platforms//os:windows": "@clang_windows//:bin/clang.exe",
        "//conditions:default": "@clang_linux//:bin/clang",
    }),
    visibility = [
        "//software/bbe32:__pkg__",
        "//software/r52:__pkg__",
    ],
    deps = [
        ":common_ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_CODE.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_CONST.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_DATA_CORE0_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_DATA_SHARED_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_EXCVEC_CORE0_CODE.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_GLOBALSHARED_CONST.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_GLOBALSHARED_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_INTVEC_CODE.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_INTVEC_CONST.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_INTVEC_CORE0_CODE.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_INTVEC_CORE0_CONST.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_OsCore0_ASIL_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_OsCore_Qm_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_Appl_BackgroundTask_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_Appl_IPC_Task_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_Appl_Task_Communication_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_Appl_Task_Fast_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_Appl_Task_High_Prio_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_Appl_Task_Logging_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_Appl_Task_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_BSW_Task_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_OsCore0_Error_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_OsCore0_Init_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_OsCore0_Isr_Core_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_OsCore0_Kernel_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_OsCore0_Shutdown_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_OsCore0_Startup_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_OsCore0_Task_Prio0_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_OsCore0_Task_Prio190_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_OsCore0_Task_Prio200_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_OsCore0_Task_Prio210_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_OsCore0_Task_Prio4294967295_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_STACK_Radar_Ctrl_Task_VAR.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_USER_CODE.ld",
        "//software/r52/autosar/config/Appl/Source:vLinkGen_Inc_OS_USER_CONST.ld",
        "@boot//:boot.ld",
    ],
)

ld_preprocess(
    name = "bbe32_ld",
    src = "bbe32.ld",
    args = select({
        "//:Build_enable_phy_100Mb": ["-DEnable_PHY_100Mb"],
        "//conditions:default": [],
    }) + select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:VEH_SOMEIP": ["-DVEH_SOMEIP"],
        "//conditions:default": ["-DVEH_CAN"],
    }),
    local_defines = EMB_TRACKER_PROJECT_PROFILE().TRACKER_ENABLED_DEFINES,
    preprocess_compiler_executable = select({
        "@platforms//os:windows": "@clang_windows//:bin/clang.exe",
        "//conditions:default": "@clang_linux//:bin/clang",
    }),
    visibility = [
        "//software/bbe32:__pkg__",
    ],
    deps = [
        ":common_ld",
    ],
)
