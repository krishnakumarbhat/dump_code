cc_library(
    name = "xcp_adc_logging_mock_lib",
    srcs = [
        "xcp_adc_logging_fff.cc",
    ],
    hdrs = [
        "xcp_adc_logging_fff.h",
    ],
    defines = [
        "ENABLE_ADC_DATA_LOGGING=1",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/bbe32/adc_logging:adc_data_logging_h",
        "@fff",
    ],
)
