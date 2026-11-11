cc_library(
    name = "program_flow_monitor_mocks_lib",
    srcs = [
        "program_flow_monitor_fff.cc",
    ],
    hdrs = [
        "program_flow_monitor_fff.h",
    ],
    strip_include_prefix = "//software/r52/program_flow_monitor/test/mocks",
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/ipc:ipc_data_h",
        "//software/r52/program_flow_monitor:program_flow_monitor_h",
        "@fff",
    ],
)
