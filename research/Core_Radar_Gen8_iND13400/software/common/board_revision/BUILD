cc_library(
    name = "board_revision_h",
    srcs = [
    ],
    hdrs = [
        "board_revision.h",
        "board_revision_cfg.h",
    ],
    defines = [
    ],
    strip_include_prefix = "//software/common/board_revision/",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
    ],
)

cc_library(
    name = "board_revision_module",
    srcs = [
        "board_revision.c",
    ],
    hdrs = [
    ],
    defines = [
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":board_revision_h",
    ],
)

cc_library(
    name = "board_revision_unit_test_lib",
    hdrs = [
        "board_revision.c",
    ],
    defines = [
    ],
    strip_include_prefix = "//software/common/board_revision",
    visibility = ["//visibility:public"],
    deps = [
        ":board_revision_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
    ],
)
