cc_library(
    name = "can_tx_msgs_fakes_lib",
    srcs = [
        "can_tx_msgs_fakes.cc",
    ],
    hdrs = [
        "can_tx_msgs_fakes.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        "@fff",
        "@reuse",
    ],
)
