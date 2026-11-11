cc_library(
    name = "radar_look_fake_lib",
    srcs = [
        "radar_look_fake.cc",
    ],
    hdrs = [
        "radar_look_fake.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb/test/mocks:xcp_bb_fake_lib",
        "//software/r52/bb_radar_ctl:radar_look_h",
        "@fff",
    ],
)

cc_library(
    name = "radar_data_fake_lib",
    srcs = [
        "radar_data_fake.cc",
    ],
    hdrs = [
        "radar_data_fake.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "@fff",
    ],
)

cc_library(
    name = "radar_ctl_fake_lib",
    srcs = [
        "radar_ctl_fake.cc",
    ],
    hdrs = [
        "radar_ctl_fake.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/bb_radar_ctl:radar_ctl_h",
        "//software/r52/bb_radar_ctl:radar_look_h",
        "@fff",
    ],
)
