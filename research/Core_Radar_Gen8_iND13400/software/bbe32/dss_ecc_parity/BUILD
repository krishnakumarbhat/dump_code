cc_library(
    name = "dss_ecc_parity_h",
    hdrs = [
        "dss_ecc_parity.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_library(
    name = "dss_ecc_parity",
    srcs = [
        "dss_ecc_parity.c",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "dss_ecc_parity_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
        "@reuse",
    ],
)

cc_library(
    name = "dss_ecc_parity_ut_lib",
    hdrs = ["dss_ecc_parity.c"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":dss_ecc_parity_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
        "@reuse",
    ],
)
