cc_library(
    name = "ipc_mss_fake_lib",
    srcs = [
        "ipc_mss_mocks.cc",
    ],
    hdrs = [
        "ipc_mss_mocks.h",
    ],
    strip_include_prefix = "//software/r52/ipc/test/mocks",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/dsp_setup:dsp_setup_h",
        "//software/r52/ipc:ipc_mss_h",
        "@fff",
    ],
)
