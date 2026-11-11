config_setting(
    name = "mars_rev_a0",
    flag_values = {"//:mars_hw_revision": "A0"},
)

config_setting(
    name = "mars_rev_b0",
    flag_values = {"//:mars_hw_revision": "B0"},
)

# Library that provides the MARS_HW_REV define based on the flag
cc_library(
    name = "mars_hw_rev_defines",
    defines = select({
        ":mars_rev_a0": ["MARS_HW_REV_A0"],
        ":mars_rev_b0": [
            "MARS_HW_REV_B0",
            "MARS_DEBUG_SUPPORT_DISABLED",  # Assumption Of Use Update
        ],
        "//conditions:default": ["MARS_HW_REV_A0"],  # Default to A0
    }),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "mars_api_h",
    srcs = [],
    hdrs = [],
    defines = [],
    strip_include_prefix = "//software/r52/mmic/drivers/mars_api",
    visibility = ["//visibility:public"],
    deps = [
        ":level0_Gpio_inc_h",
        ":level0_Stc_inc_h",
        ":level0_crc_inc_h",
        ":level0_inc_h",
        ":level0_master_inc_h",
        ":level1_inc_h",
        ":level2_inc_h",
        ":mars_hw_rev_defines",
        ":mars_inc_h",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
    ],
)

cc_library(
    name = "mars_api",
    srcs = [],
    hdrs = [],
    defines = [],
    strip_include_prefix = "//software/r52/mmic/drivers/mars_api",
    visibility = ["//visibility:public"],
    deps = [
        ":level0_module",
        ":level1_module",
        ":level2_module",
        ":mars_api_h",
    ],
)

cc_library(
    name = "mars_inc_h",
    hdrs = glob([
        "Common/*.h",
    ]),
    defines = [],
    strip_include_prefix = "Common",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_library(
    name = "level0_inc_h",
    srcs = [],
    hdrs = glob([
        "level0/include/*.h",
    ]),
    defines = [
    ],
    strip_include_prefix = "level0/include",
    visibility = ["//visibility:private"],
    deps = [
    ],
)

cc_library(
    name = "level0_master_inc_h",
    srcs = [],
    hdrs = glob([
        "level0/r52/include/*.h",
    ]),
    defines = [
    ],
    strip_include_prefix = "level0/r52/include",
    visibility = ["//visibility:private"],
    deps = [
    ],
)

cc_library(
    name = "level0_crc_inc_h",
    srcs = [],
    hdrs = glob([
        "level0/r52/drivers/Crc_ARMv8/inc/*.h",
    ]),
    defines = [
    ],
    strip_include_prefix = "level0/r52/drivers/Crc_ARMv8/inc",
    visibility = ["//visibility:private"],
    deps = [
    ],
)

cc_library(
    name = "level0_Gpio_inc_h",
    srcs = [],
    hdrs = glob([
        "level0/r52/drivers/Gpio/inc/*.h",
    ]),
    defines = [
    ],
    strip_include_prefix = "level0/r52/drivers/Gpio/inc",
    visibility = ["//visibility:private"],
    deps = [
    ],
)

cc_library(
    name = "level0_Stc_inc_h",
    srcs = [],
    hdrs = glob([
        "level0/r52/drivers/Stc/inc/*.h",
    ]),
    defines = [
    ],
    strip_include_prefix = "level0/r52/drivers/Stc/inc",
    visibility = ["//visibility:private"],
    deps = [
        # "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr",
    ],
)

cc_library(
    name = "level0_module",
    srcs = glob([
        "level0/r52/src/*.c",
        "level0/r52/drivers/Crc_ARMv8/src/*.c",
        "level0/r52/drivers/Gpio/src/*.c",
        "level0/r52/drivers/Stc/src/*.c",
    ]),
    hdrs = [],
    defines = [
        "EDU_BOARD",
    ],
    visibility = ["//visibility:private"],
    deps = [
        ":level0_Gpio_inc_h",
        ":level0_Stc_inc_h",
        ":level0_crc_inc_h",
        ":level0_inc_h",
        ":level0_master_inc_h",
        ":mars_hw_rev_defines",
        ":mars_inc_h",
        "//software/common",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/Gpio:Driver_GPIO_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/Port:Driver_Port_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/SPI:Driver_SPI_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/Sys:Sys_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/common/TCM_LIB",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/sfr:chandra_sfr_h",
    ],
)

cc_library(
    name = "mars_a0_specific_h",
    hdrs = glob(["level1/include/A0/*.h"]),
    strip_include_prefix = "level1/include/A0",
    visibility = ["//visibility:private"],
    deps = [
        ":level2_inc_h",
    ],
)

cc_library(
    name = "mars_b0_specific_h",
    hdrs = glob(["level1/include/B0/*.h"]),
    strip_include_prefix = "level1/include/B0",
    visibility = ["//visibility:private"],
    deps = [
        ":level2_inc_h",
    ],
)

cc_library(
    name = "level1_inc_h",
    hdrs = glob(["level1/include/*.h"]),
    strip_include_prefix = "level1/include",
    visibility = ["//visibility:private"],
    deps = select({
        ":mars_rev_a0": [":mars_a0_specific_h"],
        ":mars_rev_b0": [":mars_b0_specific_h"],
        "//conditions:default": [],
    }) + [":level2_inc_h"],
)

cc_library(
    name = "mars_a0_specific_c",
    srcs = glob(["level1/src/A0/*.c"]),
    hdrs = [],
    visibility = ["//visibility:private"],
    deps = [
        ":mars_a0_specific_h",
        ":mars_hw_rev_defines",
    ],
)

cc_library(
    name = "mars_b0_specific_c",
    srcs = glob(["level1/src/B0/*.c"]),
    hdrs = [],
    visibility = ["//visibility:private"],
    deps = [
        ":mars_b0_specific_h",
        ":mars_hw_rev_defines",
    ],
)

cc_library(
    name = "level1_module",
    srcs = glob(["level1/src/*.c"]),
    hdrs = [],
    visibility = ["//visibility:private"],
    deps = select({
        ":mars_rev_a0": [":mars_a0_specific_c"],
        ":mars_rev_b0": [":mars_b0_specific_c"],
        "//conditions:default": [],
    }) + [
        ":level0_Gpio_inc_h",
        ":level0_Stc_inc_h",
        ":level0_crc_inc_h",
        ":level0_inc_h",
        ":level0_master_inc_h",
        ":level1_inc_h",
        ":mars_hw_rev_defines",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/Gpio:Driver_GPIO_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/Port:Driver_Port_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/SPI:Driver_SPI_h",
    ],
)

cc_library(
    name = "level2_inc_h",
    srcs = [],
    hdrs = glob([
        "level2/include/*.h",
    ]),
    defines = [
        "CMSIS_ENVIRONMENT",
    ],
    strip_include_prefix = "level2/include",
    visibility = ["//visibility:private"],
    deps = [
        ":level0_Gpio_inc_h",
        ":level0_Stc_inc_h",
        ":level0_crc_inc_h",
        ":level0_inc_h",
        ":level0_master_inc_h",
        ":mars_inc_h",
        "//software/common/board_revision:board_revision_module",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/Gpio:Driver_GPIO_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/Port:Driver_Port_h",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/SPI:Driver_SPI_h",
    ],
)

cc_library(
    name = "level2_module",
    srcs = glob([
        "level2/src/*.c",
    ]),
    hdrs = [],
    defines = [
        "CMSIS_ENVIRONMENT",
    ],
    strip_include_prefix = "level2/src",
    visibility = ["//visibility:private"],
    deps = [
        ":level0_Gpio_inc_h",
        ":level0_Stc_inc_h",
        ":level0_crc_inc_h",
        ":level0_inc_h",
        ":level0_master_inc_h",
        ":level1_inc_h",
        ":level1_module",
        ":level2_inc_h",
        ":mars_hw_rev_defines",
        "//software/common",
        "//software/common/crc32",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/Sys",
        "@iND13400_sdk//sdk/R52/cmsis-drivers/CMSIS/chandra/common:driver_common_h",
    ],
)

cc_library(
    name = "mars_api_unit_test_support_lib",
    hdrs = [
        "mars_api.c",
    ],
    strip_include_prefix = "//software/r52/mmic/drivers/mars_api/level2/src",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/mmic:mmic_h",
        "//software/r52/mmic/drivers/mars_api:mars_api_h",
        "//software/r52/mmic/drivers/mars_api/test/mocks:mars_api_fake_lib",
        "@fff",
    ],
)
