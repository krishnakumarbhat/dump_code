cc_library(
    name = "mipi_csi2_fake_lib",
    srcs = [
        "dd_mipi_csi2_fake.cc",
    ],
    hdrs = [
        "dd_mipi_csi2_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/mmic/drivers/mipi_csi2:dd_mipi_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@fff",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
    ],
)

cc_library(
    name = "dd_mipi_mock_lib",
    srcs = [
        "dd_mipi_fff.cc",
    ],
    hdrs = [
        "dd_mipi_fff.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/mmic/drivers/mipi_csi2:dd_mipi_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@fff",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
    ],
)

cc_library(
    name = "mipi_interrupt_fake_lib",
    srcs = [
        "mipi_interrupt_fake.cc",
    ],
    hdrs = [
        "mipi_interrupt_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/mmic/drivers/mipi_csi2:dd_mipi_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@fff",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
    ],
)
