load("@bazel_platform//tools/srec_cat:srec_cat.bzl", "srec_cat")
load("//tools/python/create_flash_image:create_flash_image.bzl", "create_flash_image")
load("//tools/python/spc_gen:spc_gen.bzl", "spc_gen")
load("@flash_addresses//:flash_addresses.bzl", "FLASH_ADDRESSES")
load("//tools/bazel/scripts:formatter.bzl", "to_string")

spc_gen(
    name = "spc_1.s19",
    size = FLASH_ADDRESSES["__SPC_FLASH_BLOCK_SIZE"],
    sensor_position = 1,
    start_address = FLASH_ADDRESSES["__SPC_FLASH_START_ADDRESS"],
    visibility = ["//visibility:public"],
)

spc_gen(
    name = "spc_2.s19",
    size = FLASH_ADDRESSES["__SPC_FLASH_BLOCK_SIZE"],
    sensor_position = 2,
    start_address = FLASH_ADDRESSES["__SPC_FLASH_START_ADDRESS"],
    visibility = ["//visibility:public"],
)

spc_gen(
    name = "spc_3.s19",
    size = FLASH_ADDRESSES["__SPC_FLASH_BLOCK_SIZE"],
    sensor_position = 3,
    start_address = FLASH_ADDRESSES["__SPC_FLASH_START_ADDRESS"],
    visibility = ["//visibility:public"],
)

spc_gen(
    name = "spc_4.s19",
    size = FLASH_ADDRESSES["__SPC_FLASH_BLOCK_SIZE"],
    sensor_position = 4,
    start_address = FLASH_ADDRESSES["__SPC_FLASH_START_ADDRESS"],
    visibility = ["//visibility:public"],
)

spc_gen(
    name = "spc_5.s19",
    size = FLASH_ADDRESSES["__SPC_FLASH_BLOCK_SIZE"],
    sensor_position = 5,
    start_address = FLASH_ADDRESSES["__SPC_FLASH_START_ADDRESS"],
    visibility = ["//visibility:public"],
)

spc_gen(
    name = "spc_6.s19",
    size = FLASH_ADDRESSES["__SPC_FLASH_BLOCK_SIZE"],
    sensor_position = 6,
    start_address = FLASH_ADDRESSES["__SPC_FLASH_START_ADDRESS"],
    visibility = ["//visibility:public"],
)

spc_gen(
    name = "spc_7.s19",
    size = FLASH_ADDRESSES["__SPC_FLASH_BLOCK_SIZE"],
    sensor_position = 7,
    start_address = FLASH_ADDRESSES["__SPC_FLASH_START_ADDRESS"],
    visibility = ["//visibility:public"],
)

spc_gen(
    name = "spc_8.s19",
    size = FLASH_ADDRESSES["__SPC_FLASH_BLOCK_SIZE"],
    sensor_position = 8,
    start_address = FLASH_ADDRESSES["__SPC_FLASH_START_ADDRESS"],
    visibility = ["//visibility:public"],
)

srec_cat(
    name = "spc_erased.s19",
    options = [
        "-generate",
        to_string(FLASH_ADDRESSES["__SPC_FLASH_START_ADDRESS"]),
        to_string(FLASH_ADDRESSES["__SPC_FLASH_START_ADDRESS"] + FLASH_ADDRESSES["__SPC_FLASH_BLOCK_SIZE"]),
        "-constant",
        "0xFF",
        "-Output",
        "{OUTPUT_FILE}",
    ],
    visibility = ["//visibility:public"],
)

exports_files(["module_filename_map.json"])

config_setting(
    name = "mars_rev_a0",
    flag_values = {"//:mars_hw_revision": "A0"},
)

config_setting(
    name = "mars_rev_b0",
    flag_values = {"//:mars_hw_revision": "B0"},
)

filegroup(
    name = "selected_maf_bin",
    srcs = select({
        "//:mars_hw_rev_a0": ["@MAF_BIN_A//:MAF.bin"],
        "//:mars_hw_rev_b0": ["@MAF_BIN_B//:MAF.bin"],
        "//conditions:default": ["@MAF_BIN_A//:MAF.bin"],  # Default to A0
    }),
    visibility = ["//visibility:public"],
)

srec_cat(
    name = "flash_image_table.s19",
    options = [
        # Word0 @ __ILUT_FLASH_START_ADDRESS: ASCII "HEAD" (4 bytes)
        "-generate",
        to_string(FLASH_ADDRESSES["__ILUT_FLASH_START_ADDRESS"]),
        to_string(FLASH_ADDRESSES["__ILUT_FLASH_START_ADDRESS"] + 0x4),
        "-repeat-string",
        "ILUT",

        # Word1 @ __ILUT_FLASH_START_ADDRESS + 4: app start address (32-bit)
        "-generate",
        to_string(FLASH_ADDRESSES["__ILUT_FLASH_START_ADDRESS"] + 0x4),
        to_string(FLASH_ADDRESSES["__ILUT_FLASH_START_ADDRESS"] + 0x8),
        "-constant-l-e",
        to_string(FLASH_ADDRESSES["__APP_FLASH_START_ADDRESS"]),
        "4",
        "-execution-start-address",
        "0",
        "-Output",
        "{OUTPUT_FILE}",
    ],
    visibility = ["//visibility:public"],
)

create_flash_image(
    name = "dyn_app.s19",
    srcs = {
        "//software/r52": "r52App.s19",
        "//software/bbe32": "bbe32App.s19",
    },
    entry_address = 0x7FFE0400,  # vector table start address mapped to R52_TCM in r52.ld
    pattern = "APP",
    start_address = FLASH_ADDRESSES["__APP_FLASH_START_ADDRESS"],
    visibility = ["//visibility:public"],
)

srec_cat(
    name = "mars_fw.s19",
    srcs = {
        ":selected_maf_bin": "MAF.bin",
    },
    options = [
        "{INPUT_FILE0}",
        "-Binary",
        "-offset",
        to_string(FLASH_ADDRESSES["__MARS_FW_FLASH_START_ADDRESS"]),
        "-Output",
        "{OUTPUT_FILE}",
    ],
    visibility = ["//visibility:public"],
)

srec_cat(
    name = "nvm_erase.s19",
    options = [
        "-generate",
        "0x0",
        to_string(FLASH_ADDRESSES["__NVM_PARTITION_B_FLASH_BLOCK_SIZE"]),
        "-constant",
        "0xFF",
        "-offset",
        to_string(FLASH_ADDRESSES["__NVM_PARTITION_B_FLASH_START_ADDRESS"]),
        "-generate",
        "0x0",
        to_string(FLASH_ADDRESSES["__NVM_PARTITION_A_FLASH_BLOCK_SIZE"]),
        "-constant",
        "0xFF",
        "-offset",
        to_string(FLASH_ADDRESSES["__NVM_PARTITION_A_FLASH_START_ADDRESS"]),
        "-Output",
        "{OUTPUT_FILE}",
    ],
    visibility = ["//visibility:public"],
)

srec_cat(
    name = "app.s19",
    srcs = {
        ":dyn_app.s19": "dyn_app.s19",  # INPUT_FILE0
        ":selected_maf_bin": "MAF.bin",  # INPUT_FILE1
        ":flash_image_table.s19": "flash_image_table.s19",  # INPUT_FILE2
    },
    options = [
        # Application image (dyn_app.s19)
        "{INPUT_FILE0}",

        # MAF.bin as binary, padded or offset to __MARS_FW_FLASH_START_ADDRESS
        "{INPUT_FILE1}",
        "-Binary",
        "-offset",
        to_string(FLASH_ADDRESSES["__MARS_FW_FLASH_START_ADDRESS"]),

        # flash_image_table.s19
        "{INPUT_FILE2}",

        # Output the final merged flash image
        "-Output",
        "{OUTPUT_FILE}",
    ],
    visibility = ["//:__subpackages__"],
)

# list of file combinations to verify no overlap between generated images
FILES_TO_VERIFY = [
    # test with EDU pbl
    {
        ":app.s19": "app.s19",  # INPUT_FILE0
        ":spc_1.s19": "spc_1.s19",  # INPUT_FILE1
        "@boot//:pbl_eth": "pbl_edu_eth_signed.s19",  # INPUT_FILE2
        ":smc_cal_ptp": "smc_cal.ptp",  # INPUT_FILE3
        ":usc_cal_ptp": "usc_cal.ptp",  # INPUT_FILE4
        ":nvm_erase.s19": "nvm_erase.s19",  # INPUT_FILE5
    },
    # test with A0 pbl
    {
        ":app.s19": "app.s19",  # INPUT_FILE0
        ":spc_1.s19": "spc_1.s19",  # INPUT_FILE1
        "@boot//:pbl_eth": "pbl_a0_eth_signed.s19",  # INPUT_FILE2
        ":smc_cal_ptp": "smc_cal.ptp",  # INPUT_FILE3
        ":usc_cal_ptp": "usc_cal.ptp",  # INPUT_FILE4
        ":nvm_erase.s19": "nvm_erase.s19",  # INPUT_FILE5
    },
    # test with B0 pbl
    {
        ":app.s19": "app.s19",  # INPUT_FILE0
        ":spc_1.s19": "spc_1.s19",  # INPUT_FILE1
        "@boot//:pbl_eth": "pbl_b0_eth_signed.s19",  # INPUT_FILE2
        ":smc_cal_ptp": "smc_cal.ptp",  # INPUT_FILE3
        ":usc_cal_ptp": "usc_cal.ptp",  # INPUT_FILE4
        ":nvm_erase.s19": "nvm_erase.s19",  # INPUT_FILE5
    },
]

# target for confirming no overlap between generated images. output is not used.
filegroup(
    name = "flash_image_overlap_checks",
    srcs = [
        # "flash_image_overlap_check_{}".format(idx + 1)
        # for idx in range(len(FILES_TO_VERIFY))
    ],
    visibility = ["//visibility:public"],
)

[
    srec_cat(
        name = "flash_image_overlap_check_{}".format(idx + 1),
        srcs = files,
        options = ["{" + "INPUT_FILE{}".format(i) + "}" for i in range(len(files))] + [
            "-Output",
            "{OUTPUT_FILE}",
        ],
    )
    for idx, files in enumerate(FILES_TO_VERIFY)
]

filegroup(
    name = "smc_cal_ptp",
    srcs = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": ["@smc_flr8//:smc_cal_ptp"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": ["@smc_flr8_high_det//:smc_cal_ptp"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": ["@smc_flr8_standalone//:smc_cal_ptp"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": ["@smc_srr8p//:smc_cal_ptp"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": ["@smc_srr8p_high_det//:smc_cal_ptp"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": ["@smc_srr8p_standalone//:smc_cal_ptp"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": ["@smc_srr8p_al_can_standalone//:smc_cal_ptp"],
        "//conditions:default": ["@smc_flr8//:smc_cal_ptp"],
    }),
    visibility = ["//visibility:public"],
)

filegroup(
    name = "usc_cal_ptp",
    srcs = select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_can": ["@usc_flr8//:usc_cal_ptp"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_someip": ["@usc_flr8//:usc_cal_ptp"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:flr8_standalone": ["@usc_flr8//:usc_cal_ptp"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_can": ["@usc_srr8p//:usc_cal_ptp"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_someip": ["@usc_srr8p//:usc_cal_ptp"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_standalone": ["@usc_srr8p//:usc_cal_ptp"],
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:srr8p_al_can_standalone": ["@usc_srr8p//:usc_cal_ptp"],
        "//conditions:default": ["@usc_flr8//:usc_cal_ptp"],
    }),
    visibility = ["//visibility:public"],
)
