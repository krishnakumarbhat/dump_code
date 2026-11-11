exports_files([
    "dio_wrapper.c",
    "dio_wrapper.h",
])

cc_library(
    name = "dio_wrapper_h",
    srcs = [],
    hdrs = [
        "dio_wrapper.h",
    ],
    strip_include_prefix = "//software/r52/drivers/mcal/dio_wrapper",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@iND13400_autosar_sip//Components/Dio:Dio_h",
    ],
)

cc_library(
    name = "dio_wrapper",
    srcs = [
        "dio_wrapper.c",
    ],
    hdrs = [],
    visibility = ["//visibility:public"],
    deps = [
        ":dio_wrapper_h",
        "//software/common/board_revision:board_revision_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@iND13400_autosar_sip//Components/Dio:Dio_h",
    ],
)

cc_library(
    name = "dio_wrapper_ut_lib",
    hdrs = [
        "dio_wrapper.c",
        "dio_wrapper.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@iND13400_autosar_sip//Components/Dio:Dio_h",
    ],
)
