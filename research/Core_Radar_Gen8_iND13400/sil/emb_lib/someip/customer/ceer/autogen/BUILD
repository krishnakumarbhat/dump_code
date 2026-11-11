cc_library(
    name = "ceer_autogen",
    srcs = [
        "src/Encode_ENET.cpp",
    ],
    hdrs = [
        "inc/ENET_decoded_types.h",
        "inc/ENET_encoded_types.h",
        "inc/macros.h",
    ],
    strip_include_prefix = "inc",
    visibility = ["//visibility:public"],
    deps = [
        "@reuse//:fixmac",
    ],
)
