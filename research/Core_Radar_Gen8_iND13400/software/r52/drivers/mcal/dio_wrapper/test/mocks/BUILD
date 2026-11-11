cc_library(
    name = "dio_wrapper_fake",
    srcs = [
        "dio_wrapper_fake.cc",
    ],
    hdrs = [
        "dio_wrapper_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/drivers/mcal/dio_wrapper:dio_wrapper_ut_lib",
        "@fff",
        "@iND13400_autosar_sip//Components/Dio:Dio_h",
    ],
)
