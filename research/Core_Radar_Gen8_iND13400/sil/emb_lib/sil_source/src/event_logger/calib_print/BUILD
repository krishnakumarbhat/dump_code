cc_library(
    name = "calib_print",
    hdrs = ["calib_print.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":smc_csv",
        ":smc_xml",
        ":usc_csv",
        ":usc_xml",
    ],
)

cc_library(
    name = "smc_csv",
    srcs = ["smc_csv.cpp"],
    copts = [
        "-Os",
        "-g0",
    ],
    deps = [
        ":calib_print_h",
        "//sil/emb_lib/sil_source/inc:serialize_object",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
        "//sil/emb_lib/sil_source/src/event_logger:output_control",
        "//software/common/calibrations/smc:smc_module",
    ],
)

cc_library(
    name = "usc_csv",
    srcs = ["usc_csv.cpp"],
    copts = [
        "-Os",
        "-g0",
    ],
    deps = [
        ":calib_print_h",
        "//sil/emb_lib/sil_source/inc:serialize_object",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
        "//sil/emb_lib/sil_source/src/event_logger:output_control",
        "//software/common/calibrations/usc:usc_module",
    ],
)

cc_library(
    name = "usc_xml",
    srcs = ["usc_xml.cpp"],
    copts = [
        "-Os",
        "-g0",
    ],
    deps = [
        ":calib_print_h",
        "//sil/emb_lib/sil_source/inc:serialize_object",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
        "//sil/emb_lib/sil_source/src/event_logger:output_control",
        "//software/common/calibrations/usc:usc_module",
        "@pugixml",
    ],
)

cc_library(
    name = "smc_xml",
    srcs = ["smc_xml.cpp"],
    copts = [
        "-Os",
        "-g0",
    ],
    deps = [
        ":calib_print_h",
        "//sil/emb_lib/sil_source/inc:serialize_object",
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
        "//sil/emb_lib/sil_source/src/event_logger:output_control",
        "//software/common/calibrations/smc:smc_module",
        "@pugixml",
    ],
)

cc_library(
    name = "calib_print_h",
    hdrs = ["calib_print.h"],
    deps = [
        "//software/common/calibrations/smc:smc_module",
        "//software/common/calibrations/usc:usc_module",
    ],
)
