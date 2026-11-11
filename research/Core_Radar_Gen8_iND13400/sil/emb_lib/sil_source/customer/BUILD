cc_library(
    name = "customer_sil_wrapper",
    srcs = select({
        "//sil/emb_lib/sil_source:gpo": [":gpo/sil_wrapper_customer.cpp"],
        "//sil/emb_lib/sil_source:al": [":al/sil_wrapper_customer.cpp"],
    }),
    hdrs = ["sil_wrapper_customer.h"],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
)
