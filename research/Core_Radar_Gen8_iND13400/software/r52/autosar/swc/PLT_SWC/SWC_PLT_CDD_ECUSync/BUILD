cc_library(
    name = "SWC_PLT_CDD_ECUSync",
    srcs = [
        "Source/SWC_PLT_CDD_ECUSync.c",
        "Source/SWC_PLT_CDD_ECUSync_Test.c",
        "Source/SWC_PLT_CDD_ECUSync_external.c",
    ],
    hdrs = [
    ],
    defines = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:VEH_AL_CAN_STANDALONE": [
            "AL_CAN_TSYNCH_DEFAULT",
        ],
        "//conditions:default": [],
    }),
    local_defines = select({
        "//:Build_SQT_Test_Cases": ["ENABLE_SQT_TEST_STUBS"],
        "//:Build_SIT_Test_Cases": ["ENABLE_SIT_TEST_STUBS"],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_CDD_ECUSync_external_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_PlatformTime:PLT_Appl_PlatformTime_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync:SWC_PLT_CDD_ECUSync_h",
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/bb_radar_ctl:radar_look_h",
        "@iND13400_autosar_sip//Components/StbM:StbM_h",
        "@reuse",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_ECUSync_h",
    srcs = [],
    hdrs = [
        "Include/SWC_PLT_CDD_ECUSync.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync/Include",
    visibility = ["//visibility:public"],
    deps = [
        "@Calibration_Handler//:calibration_h",
        "@Calibration_Handler//:calibration_module",
        "@Sensor_Position//:sensor_position_h",
        "@reuse//:fixmac",
    ],
)

cc_library(
    name = "SWC_PLT_CDD_ECUSync_external_h",
    srcs = [],
    hdrs = [
        "Include/SWC_PLT_CDD_ECUSync_external.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync/Include",
    visibility = ["//visibility:public"],
    deps = [
    ],
)
