cc_library(
    name = "someip_driver",
    srcs = [
        "someip_driver.cpp",
    ],
    hdrs = [
        "someip_driver.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//sil/emb_lib/sil_source/src:sil_wrapper_common",
    ],
)

cc_library(
    name = "someip",
    srcs = [
        "someip_iface.cpp",
    ],
    hdrs = [
        "someip_iface.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = select({
        "//sil/emb_lib/sil_source:gpo": ["//sil/emb_lib/someip/customer/ceer:cust_someip"],
    }),
)
