cc_library(
    name = "SWC_PLT_Service_IoHwAb",
    srcs = [
        "Source/SWC_PLT_Service_IoHwAb.c",
    ],
    hdrs = [],
    defines = [],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb",
        "//software/r52/drivers/mcal/dio_wrapper",
        "@iND13400_autosar_sip//Components/Dio:Dio_h",
    ],
)

cc_library(
    name = "PLT_Srv_IoHwAb_unit_test_support_lib",
    hdrs = ["Source/SWC_PLT_Service_IoHwAb.c"],
    defines = [],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/Source",
    visibility = ["//visibility:public"],
)
