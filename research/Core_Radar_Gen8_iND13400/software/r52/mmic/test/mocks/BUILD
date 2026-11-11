cc_library(
    name = "mmic_interface_fake_lib",
    srcs = [
        "mmic_interface_fake.cc",
    ],
    hdrs = [
        "mmic_interface_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:UDPLoggingStreamHeaders",
        "//software/r52/bb_radar_ctl/bb_radar_ctl_imp/test/mocks:radar_data_fake_lib",
        "//software/r52/mmic:mmic_h",
        "//software/r52/mmic/drivers/mipi_csi2/test/mocks:mipi_csi2_fake_lib",
        "//software/r52/mmic/test/mocks:dd_mmic_fake_lib",
        "//software/r52/mmic/test/mocks:mmic_error_fake_lib",
        "@fff",
    ],
)

cc_library(
    name = "mmic_error_fake_lib",
    srcs = [
        "mmic_error_fake.cc",
    ],
    hdrs = [
        "mmic_error_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        # "//software/m7/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP:SWC_CDD_XCP_Logging_h",
        "//software/r52/mmic:mmic_error_h",
        # "//software/m7/mmic/drivers/ppe_csi2:csi2_ppe_h",
        "@fff",
    ],
)

cc_library(
    name = "dd_mmic_fake_lib",
    srcs = [
        "dd_mmic_fake.cc",
    ],
    hdrs = [
        "dd_mmic_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/mmic:mmic_h",
        "//software/r52/mmic/drivers/mars_api/test/mocks:mars_api_fake_lib",
        "@fff",
    ],
)
