cc_library(
    name = "AshLey_autogen",
    srcs = [
        "src/autogen_encode_messages.cpp",
        "src/autogen_encode_messages_VCAN.cpp",
    ],
    hdrs = [
        "inc/autogen_message_decode_types.h",
        "inc/autogen_message_decode_types_VCAN.h",
        "inc/autogen_message_encoded_types.h",
        "inc/autogen_message_encoded_types_VCAN.h",
        "inc/autogen_signal_macros.h",
        "inc/autogen_signal_macros_VCAN.h",
    ],
    strip_include_prefix = "inc",
    visibility = ["//visibility:public"],
    deps = [
        "@reuse//:fixmac",
    ],
)
