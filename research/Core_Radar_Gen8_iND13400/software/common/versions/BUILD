load("@emb_tracker_wrapper//:emb_tracker_project_profile.bzl", "EMB_TRACKER_PROJECT_PROFILE")

cc_library(
    name = "versions",
    srcs = [
        "versions.c",
    ],
    hdrs = [],
    defines = EMB_TRACKER_PROJECT_PROFILE().TRACKER_MODE_DEFINES + select({
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_Communication:VEH_SOMEIP": [
            "VEH_SOMEIP",
        ],
        "//conditions:default": [],
    }),
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":versions_hdrs",
        "@boot//:boot_interface",
    ],
)

cc_library(
    name = "versions_hdrs",
    srcs = [],
    hdrs = [
        "gitinfo.h",
        "retention_ram_data.h",
        "versions.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        ":gitinfo-gen",
        "//software/common/calibrations/smc:radar_sw_config_h",
    ],
)

genrule(
    name = "gitinfo-gen",
    outs = ["gitinfo.h"],
    cmd = "$(location //software/common/versions/linkstamp:gen_gitinfo_hdr.sh) > $@",
    cmd_ps = "$(location //software/common/versions/linkstamp:gen_gitinfo_hdr.ps1) 6> $@",
    stamp = True,
    tools = [
        "//software/common/versions/linkstamp:gen_gitinfo_hdr.ps1",
        "//software/common/versions/linkstamp:gen_gitinfo_hdr.sh",
    ],
    visibility = ["//visibility:private"],
)

filegroup(
    name = "versions_c",
    srcs = [
        "versions.c",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "versions_unit_test_lib",
    hdrs = [
        "versions.c",
    ],
    defines = [
    ],
    strip_include_prefix = "//software/common/versions",
    visibility = ["//visibility:public"],
    deps = [
        ":versions",
    ],
)
