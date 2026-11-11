load("@bazel_platform//toolchains/xtensa:cc_binary_bbe32.bzl", "cc_binary_bbe32")
load("@bazel_platform//platforms:platforms_transition.bzl", "platforms_transition")
load("@bazel_platform//quality/sca/coverity:analysis.bzl", "coverity_analysis")
load("@bazel_platform//quality/sca/coverity:cc_coverity_summary.bzl", "cc_coverity_summary")
load("@bazel_platform//quality/sca/coverity:commit_defects.bzl", "coverity_commit_defects")
load("@build_config//:coverity.bzl", "CODING_STANDARD_CONFIG", "CODING_STANDARD_PARAMS", "COV_ANALYZE_PARAMS", "COV_SKIP_FILES")

exports_files(["main.c"])

cc_library(
    name = "main_ut_lib",
    hdrs = ["main.c"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/inc:include_h",
        "//software/bbe32/mpu:mpu_h",
    ],
)

platforms_transition(
    name = "bbe32",
    actual_target = ":bbe32App",
    set_platform = select({
        "@platforms//os:windows": "@build_config//:winbbe32",
        "//conditions:default": "@build_config//:linuxbbe32",
    }),
    visibility = [
        "//:__pkg__",
        "//software:__pkg__",
    ],
)

cc_binary_bbe32(
    name = "bbe32App",
    srcs = [
        "main.c",
    ],
    copts = [],
    defines = [],
    linkopts = [
        "-T $(execpath //software/common/linker:bbe32_ld)",
    ],
    visibility = ["//visibility:private"],
    deps = [
        "//software/bbe32/inc:include_h",
        "//software/bbe32/mpu",
        "//software/bbe32/src:ipc_dsp_lib",
        "//software/bbe32/src:main_application_lib",
        "//software/common/calibrations/smc:smc_h",
        "//software/common/calibrations/usc:usc_h",
        # "//software/common/crc32:Driver_crc32_c",
        "//software/common/crc_calc:crc_calc_c",
        "//software/common/ipc:ipc_data_lib",
        "//software/common/linker:bbe32_ld",
        "//software/common/linker:linker_support_package",
        "@Gen8_iND13400//software/common/calibrations/smc:radar_sw_config_lib",
        "@spbb//modules/helpers:helpers_lib",
    ] + select({
        "//:Integration_Testing_enabled": ["//software/bbe32/integration_test:dsp_integration_test_lib"],
        "//:ANGLEFINDING_enabled": ["//software/bbe32/integration_test:dsp_integration_test_lib"],
        "//:FIRSTPASS_enabled": ["//software/bbe32/integration_test:dsp_integration_test_lib"],
        "//:RADAR_CAPABILITY_enabled": ["//software/bbe32/integration_test:dsp_integration_test_lib"],
        "//conditions:default": [],
    }),
)

# -----------------------------------
# Coverity Settings
# -----------------------------------

coverity_analysis(
    name = "xtensa_bbe32_cov",
    coding_standards_cfg = CODING_STANDARD_CONFIG,
    coding_standards_params = CODING_STANDARD_PARAMS,
    compiler_type = "xtensa",
    cov_analyze_params = COV_ANALYZE_PARAMS,
    skip_file_args = COV_SKIP_FILES,
    tags = ["manual"],
    deps = [
        ":bbe32",
    ],
)

coverity_commit_defects(
    name = "commit_defects",
    analysis = ":xtensa_bbe32_cov",
    args = [
        "--host=https://coverity.asux.aptiv.com:443",
        "--output-tag=_combined",
        "--retry-attempts=1",
        # "--verbose=1",  # Use this for debugging, levels 1-4
    ] + select({
        "//tools/coverity:coverityNightly": ["--commit"],  # only commit on nightly builds
        "//conditions:default": [
            "--failure-strategy=fail-on-new-medium-high",  # Fail on new 'High' or 'Medium' impact defects
            "--failure-strategy-misra=fail-on-new-mandatory",  # Fail on new MISRA 'Mandatory' defects too
        ],
    }) + select({
        "@build_config//:flr8": ["--stream=10034606_Core_Radar_Gen8_IND13400_FLR8_BBE32"],
        "@build_config//:srr8p": ["--stream=10034606_Core_Radar_Gen8_IND13400_SRR8p_BBE32"],
    }),
)

cc_coverity_summary(
    name = "coverity_summary",
    output_tag = "_combined",
    test = ":xtensa_bbe32_cov",
    text_summary = "bbe32_coverity_summary.txt",
)
