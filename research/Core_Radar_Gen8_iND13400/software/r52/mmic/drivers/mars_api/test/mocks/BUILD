cc_library(
    name = "mars_api_fake_lib",
    srcs = [
        "mars_api_fake.cc",
    ],
    hdrs = [
        "mars_api_fake.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/mmic/drivers/mars_api:mars_api_h",
        "@fff",
        "@iND13400_autosar_sip//Components/Uart:Uart_h",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
    ],
)
