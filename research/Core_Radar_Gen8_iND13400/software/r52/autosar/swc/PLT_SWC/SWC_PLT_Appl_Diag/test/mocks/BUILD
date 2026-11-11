cc_library(
    name = "Platform_Diag_Callout_fake_lib",
    srcs = [
        "Platform_Diag_Callout_fake.cc",
    ],
    hdrs = [
        "Platform_Diag_Callout_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag:Platform_Diag_Callout_h",
        "@fff",
    ],
)

cc_library(
    name = "Rte_SWC_PLT_Appl_Diag_fake_lib",
    srcs = [
        "Rte_SWC_PLT_Appl_Diag_fake.cc",
    ],
    hdrs = [
        "Rte_SWC_PLT_Appl_Diag_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag:Platform_Diag_Callout_h",
        "@bazel_platform//tools/cstubber:fff",
    ],
)

cc_library(
    name = "SWC_PLT_Appl_Diag_fake_lib",
    srcs = [
        "SWC_PLT_Appl_Diag_fake.cc",
    ],
    hdrs = [
        "SWC_PLT_Appl_Diag_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Diag:SWC_PLT_Appl_Diag_h",
        "@fff",
    ],
)
