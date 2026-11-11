load("@rules_cc//cc:defs.bzl", "cc_library")

# PHY variant headers live in separate subfolders (PHY_100Mb/ or PHY_1Gb/) but must be
# included as bare filenames (e.g. #include "Eth_Cfg.h"). Give each variant its own
# strip_include_prefix so the virtual include path drops the subfolder, then select the
# right one as a dep (instead of listing the raw subfolder path directly in hdrs).
cc_library(
    name = "PHY_100Mb_GenData_h",
    hdrs = [
        "PHY_100Mb/EthIf_GenTypes.h",
        "PHY_100Mb/Eth_Cfg.h",
        "PHY_100Mb/TcpIp_Lcfg.h",
    ],
    strip_include_prefix = "PHY_100Mb",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "PHY_1Gb_GenData_h",
    hdrs = [
        "PHY_1Gb/EthIf_GenTypes.h",
        "PHY_1Gb/Eth_Cfg.h",
        "PHY_1Gb/TcpIp_Lcfg.h",
    ],
    strip_include_prefix = "PHY_1Gb",
    visibility = ["//visibility:public"],
)

PHY_GENDATA_HDR_DEP = select({
    "//:Build_enable_phy_100Mb": [":PHY_100Mb_GenData_h"],
    "//conditions:default": [":PHY_1Gb_GenData_h"],
})

cc_library(
    name = "BSW_GenData_h",
    srcs = [
    ],
    hdrs = glob(
        ["*.h"],
        exclude = [
            "Eth_Cfg.h",
            "EthIf_GenTypes.h",
            "TcpIp_Lcfg.h",
        ],
    ),
    defines = [],
    strip_include_prefix = "//software/r52/autosar/config/Appl/GenData",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr:SWC_Appl_FaultMgr_Cfg_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_NvMHandler:SWC_PLT_Appl_NvMHandler_h",
        "//software/r52/autosar/swc/PRJ_SWC/SWC_PRJ_Appl_FaultMgr:SWC_PRJ_APPL_FaultMgr_h",
        "@iND13400_autosar_sip//Components/BswM:BswM_h",
        "@iND13400_autosar_sip//Components/CanTSyn:CanTSyn_h",
        "@iND13400_autosar_sip//Components/Com:Com_h",
        "@iND13400_autosar_sip//Components/CryIf:CryIf_h",
        "@iND13400_autosar_sip//Components/Crypto:Crypto_h",
        "@iND13400_autosar_sip//Components/Csm:Csm_h",
        "@iND13400_autosar_sip//Components/Dem:Dem_h",
        "@iND13400_autosar_sip//Components/Det:Det_h",
        "@iND13400_autosar_sip//Components/E2E:E2E_h",
        "@iND13400_autosar_sip//Components/EthTSyn:EthTSyn_h",
        "@iND13400_autosar_sip//Components/Gpt:gpt_h",
        "@iND13400_autosar_sip//Components/J1939Dcm:J1939Dcm_h",
        "@iND13400_autosar_sip//Components/J1939Tp:J1939Tp_h",
        "@iND13400_autosar_sip//Components/Os:Os_h",
        "@iND13400_autosar_sip//Components/Rtm:Rtm_h",
        "@iND13400_autosar_sip//Components/StbM:StbM_h",
        "@iND13400_autosar_sip//Components/TcpIpXcp:TcpIpXcp_h",
        "//software/r52/autosar/config/Appl/Source:PHY_User_Cbk_H",
    ] + PHY_GENDATA_HDR_DEP,
)

cc_library(
    name = "IpBase_GenData_h",
    srcs = [],
    hdrs = [
        "IpBase_Cfg.h",
        "IpBase_MemMap.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/config/Appl/GenData",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_library(
    name = "CRC_GenData_h",
    srcs = [],
    hdrs = [
        "Crc_Cfg.h",
        "Crc_MemMap.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/config/Appl/GenData",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_library(
    name = "E2E_GenData_h",
    srcs = [],
    hdrs = [
        "E2E_MemMap.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/config/Appl/GenData",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_library(
    name = "BSW_GenData_Cfg_h",
    srcs = [],
    hdrs = glob(
        ["*.h"],
        exclude = [
            "Eth_Cfg.h",
            "EthIf_GenTypes.h",
            "TcpIp_Lcfg.h",
        ],
    ),
    defines = [],
    strip_include_prefix = "//software/r52/autosar/config/Appl/GenData",
    visibility = ["//visibility:public"],
    deps = [
        "@iND13400_autosar_sip//Components/BswM:BswM_h",
        "@iND13400_autosar_sip//Components/Can:Can_h",
        "@iND13400_autosar_sip//Components/Com:Com_h",
        "@iND13400_autosar_sip//Components/Det:Det_h",
        "@iND13400_autosar_sip//Components/Os:Os_h",
    ] + PHY_GENDATA_HDR_DEP,
)

cc_library(
    name = "BSW_GenData",
    srcs = glob(
        ["*.c"],
        exclude = [
            "Rte_OsCore0_ASIL.c",
            "PduR_Lcfg.c",
            "EcuM_Init_Cfg.c",
            "Eth_PBcfg.c",
            "EthIf_Lcfg.c",
            "TcpIp_Lcfg.c",
        ],
    ) + select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:VEH_SOMEIP": [
            "VEH_SOMEIP/PduR_Lcfg.c",
            "VEH_SOMEIP/Rte_OsCore0_ASIL.c",
            "VEH_SOMEIP/EcuM_Init_Cfg.c",
            "VEH_SOMEIP/SoAd_Lcfg.c",
            "VEH_SOMEIP/LdCom_Lcfg.c",
            "VEH_SOMEIP/BswM_Lcfg.c",
        ],
        "//conditions:default": [
            "VEH_CAN/PduR_Lcfg.c",
            "VEH_CAN/Rte_OsCore0_ASIL.c",
            "VEH_CAN/EcuM_Init_Cfg.c",
            "VEH_CAN/SoAd_Lcfg.c",
            "VEH_CAN/LdCom_Lcfg.c",
            "VEH_CAN/BswM_Lcfg.c",
        ],
    }) + select({
        "//:Build_enable_phy_100Mb": [
            "PHY_100Mb/Eth_PBcfg.c",
            "PHY_100Mb/EthIf_Lcfg.c",
            "PHY_100Mb/TcpIp_Lcfg.c",
        ],
        "//conditions:default": [
            "PHY_1Gb/Eth_PBcfg.c",
            "PHY_1Gb/EthIf_Lcfg.c",
            "PHY_1Gb/TcpIp_Lcfg.c",
        ],
    }),
    hdrs = glob(
        ["*.h"],
        exclude = [
            "Eth_Cfg.h",
            "EthIf_GenTypes.h",
            "TcpIp_Lcfg.h",
        ],
    ),
    copts = [
        "-Wno-unused-function",
        "-Wno-incompatible-function-pointer-types",  # MK: Remove when Ethernet Driver is integrated
        "-Wno-empty-translation-unit",  # Added to get rid of post build error in TcpIpXcp_PBcfg.c file :
        "-Wno-pragma-pack",  # JH: Added to get rid of build error in Os_MemMap_Stacks.h
        "-Wno-self-assign",
    ],
    defines = select({
        "//:Build_enable_phy_100Mb": ["Enable_PHY_100Mb"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/Source:BSW_Callout",
        "//software/r52/autosar/config/Appl/J1939_Stubs:J1939_Stubs_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_FaultMgr:SWC_Appl_FaultMgr_Cfg_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_NvMHandler",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_NvMHandler:SWC_PLT_Appl_NvMHandler_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_WdgHandler:SWC_PLT_CDD_WdgHandler_cfg_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP:XcpAppl_h",
        "@iND13400_autosar_sip//Components/Adc:Adc_h",
        "@iND13400_autosar_sip//Components/BswM",
        "@iND13400_autosar_sip//Components/Can:CanModule",
        "@iND13400_autosar_sip//Components/CanIf",
        "@iND13400_autosar_sip//Components/CanSM",
        "@iND13400_autosar_sip//Components/CanXcp",
        "@iND13400_autosar_sip//Components/Com",
        "@iND13400_autosar_sip//Components/ComM",
        "@iND13400_autosar_sip//Components/Crypto",
        "@iND13400_autosar_sip//Components/Crypto:Crypto_h",
        "@iND13400_autosar_sip//Components/CryIf",
        "@iND13400_autosar_sip//Components/CryIf:CryIf_h",
        "@iND13400_autosar_sip//Components/Csm",
        "@iND13400_autosar_sip//Components/Csm:Csm_h",
        "@iND13400_autosar_sip//Components/Det",
        "@iND13400_autosar_sip//Components/Dio",
        "@iND13400_autosar_sip//Components/Dma:Dma_h",
        "@iND13400_autosar_sip//Components/E2E",
        "@iND13400_autosar_sip//Components/E2E:E2E_h",
        "@iND13400_autosar_sip//Components/E2EXf",
        "@iND13400_autosar_sip//Components/EcuM",
        "@iND13400_autosar_sip//Components/EthIf",
        "@iND13400_autosar_sip//Components/EthSM",
        "@iND13400_autosar_sip//Components/EthTSyn",
        "@iND13400_autosar_sip//Components/EthTrcv_30_Rtl9010",
        "@iND13400_autosar_sip//Components/EthTrcv_30_Tja1103",
        "@iND13400_autosar_sip//Components/Eth_30_Wrapper",
        "@iND13400_autosar_sip//Components/Fee_30_FlexNor",
        "@iND13400_autosar_sip//Components/Fls:Fls_h",
        "@iND13400_autosar_sip//Components/Gpt:gpt",
        "@iND13400_autosar_sip//Components/I2c:I2c_h",
        "@iND13400_autosar_sip//Components/IpBase",
        "@iND13400_autosar_sip//Components/LdCom/Implementation:LdCom",
        "@iND13400_autosar_sip//Components/Mcu:Mcu_h",
        "@iND13400_autosar_sip//Components/MemIf",
        "@iND13400_autosar_sip//Components/NvM",
        "@iND13400_autosar_sip//Components/Os",
        "@iND13400_autosar_sip//Components/Os:Os_asm",
        "@iND13400_autosar_sip//Components/PduR",
        "@iND13400_autosar_sip//Components/Port:Port_h",
        "@iND13400_autosar_sip//Components/Pwm",
        "@iND13400_autosar_sip//Components/Rtm",
        "@iND13400_autosar_sip//Components/Sd/Implementation:Sd",
        "@iND13400_autosar_sip//Components/SoAd",
        "@iND13400_autosar_sip//Components/SomeIpTp/Implementation:SomeIpTp",
        "@iND13400_autosar_sip//Components/Spi",
        "@iND13400_autosar_sip//Components/StbM",
        "@iND13400_autosar_sip//Components/TcpIp",
        "@iND13400_autosar_sip//Components/TcpIpXcp",
        "@iND13400_autosar_sip//Components/Uart:Uart_h",
        "@iND13400_autosar_sip//Components/VStdLib",
        "@iND13400_autosar_sip//Components/Wdg:wdg",
        "@iND13400_autosar_sip//Components/Wdg:wdg_h",
        "@iND13400_autosar_sip//Components/WdgM:WdgM_h",
        "@iND13400_autosar_sip//Components/Xcp",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/SPI:Driver_SPI_h",
    ] + select({
        "//:mcal_test_enable": [
            "//software/r52/drivers/mcal/src/test:McalTest",  # Provides Channel1_EndNotification for Dma_PBcfg.c
        ],
        "//conditions:default": [],
    }) + PHY_GENDATA_HDR_DEP,
)

cc_library(
    name = "BSW_GenData_asm",
    srcs = glob(["*.S"]),
    hdrs = [],
    copts = [],
    defines = [],
    linkopts = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":BSW_GenData_h",
        "@iND13400_autosar_sip//Components/Os",
        "@iND13400_autosar_sip//Components/Os:Os_Hal_Entry_inc",
    ],
)

cc_library(
    name = "gpt_cfg_h",
    srcs = [],
    hdrs = [
        "Gpt_Cfg.h",
        "Gpt_PBcfg.h",
    ],
    implementation_deps = [
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "adc_cfg_h",
    srcs = [],
    hdrs = [
        "Adc_Cfg.h",
        "Adc_PBcfg.h",
    ],
    implementation_deps = [
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "Det_Cfg_h",
    srcs = [],
    hdrs = [
        "Det_Cfg.h",
        "Det_MemMap.h",
    ],
    implementation_deps = [
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "Gen_Compiler_Cfg_h",
    srcs = [],
    hdrs = [
        "ComXf_Compiler_Cfg.h",
        "Os_Compiler_Cfg.h",
        "Rte_Compiler_Cfg.h",
        "SomeIpXf_Compiler_Cfg.h",
    ],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "MemMap_Common_h",
    srcs = [],
    hdrs = [
        "MemMap_Common.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "Os_MemMap_h",
    srcs = [],
    hdrs = [
        "Os_Code_MemMap.h",
        "Os_Const_MemMap.h",
        "Os_MemMap.h",
        "Os_OsCore0_swc_MemMap.h",
        "Os_Stacks_MemMap.h",
        "Os_Var_MemMap.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":MemMap_Common_h",
    ],
)

cc_library(
    name = "ComStack_Cfg_h",
    srcs = [],
    hdrs = [
        "ComStack_Cfg.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "Rte_GenData_h",
    srcs = [],
    hdrs = glob([
        "Rte*.h",
    ]),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "@iND13400_autosar_sip//Components/_Common:ComTypes_h",
    ],
)

cc_library(
    name = "Crypto_Cfg_h",
    srcs = [],
    hdrs = [
        "Crypto_182_iND13400_Cfg.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "@iND13400_autosar_sip//Components/Crypto:Crypto_h",
    ],
)

cc_library(
    name = "CryIf_Cfg_h",
    srcs = [],
    hdrs = [
        "CryIf_Cfg.h",
        "CryIf_MemMap.h",
    ] + glob([
        "Rte*.h",
    ]),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":Rte_GenData_h",
        "@iND13400_autosar_sip//Components/CryIf:CryIf_h",
    ],
)

cc_library(
    name = "Csm_Cfg_h",
    srcs = [],
    hdrs = [
        "Csm_Cfg.h",
        "Csm_Generated_Types.h",
    ] + glob([
        "Rte*.h",
    ]),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":Rte_GenData_h",
        "@iND13400_autosar_sip//Components/Csm:Csm_h",
        "@iND13400_autosar_sip//Components/_Common:MemMap_h",
    ],
)

cc_library(
    name = "Dcm_Cfg_h",
    srcs = [],
    hdrs = [
        "Dcm_Cfg.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "Dcm_Gen_h",
    srcs = [],
    hdrs = [
        "Dcm_Lcfg.h",
        "Dcm_MemMap.h",
        "Dcm_PBcfg.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "Dio_Cfg_h",
    srcs = [],
    hdrs = [
        "Dio_Cfg.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)
