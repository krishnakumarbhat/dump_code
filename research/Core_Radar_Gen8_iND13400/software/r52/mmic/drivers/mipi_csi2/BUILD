exports_files([
    "mipi_interrupt.c",
    "mipi_interrupt.h",
])

cc_library(
    name = "dd_mipi",
    srcs = [
        "dd_mipi.c",
        "mipi_interrupt.c",
    ],
    hdrs = [
        "dd_mipi.h",
        "mipi_interrupt.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/mmic/drivers/mipi_csi2",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common",
        "//software/common:UDPLoggingStreamHeaders",
        "//software/r52/mmic:mmic_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)

cc_library(
    name = "dd_mipi_h",
    srcs = [
    ],
    hdrs = [
        "dd_mipi.h",
        "mipi_interrupt.h",
    ],
    defines = [],
    strip_include_prefix = "//software/r52/mmic/drivers/mipi_csi2",
    visibility = ["//visibility:public"],
    deps = [
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)

cc_library(
    name = "mipi_csi2_unit_test_support_lib",
    srcs = [
    ],
    hdrs = [
        "dd_mipi.c",  # used as textual include in unit tests with mocked PTR macros
    ],
    copts = [
        "-fpermissive",  # Allow volatile struct assignment in C++ for testing
    ],
    strip_include_prefix = "//software/r52/mmic/drivers/mipi_csi2",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/mmic:mmic_h",
        "//software/r52/mmic/drivers/mipi_csi2:dd_mipi_h",
        "//software/r52/mmic/drivers/mipi_csi2/test/mocks:mipi_csi2_fake_lib",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        # "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra_b0/sfr:sfr",
        "@fff",
    ],
)

cc_library(
    name = "mipi_interrupt_unit_test_support_lib",
    srcs = [],
    hdrs = [
        "mipi_interrupt.c",  # used as textual include in unit tests with mocked hardware
    ],
    copts = [
        "-fpermissive",
    ],
    strip_include_prefix = "//software/r52/mmic/drivers/mipi_csi2",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common:chandra_h",
        "//software/r52/mmic/drivers/mipi_csi2:dd_mipi_h",
        "@Gen8_iND13400//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "@fff",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)
