load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "test_static",
    srcs = ["static.cpp"],
    defines = ["EMB_LIB_SIL_WRAPPER_STATIC"],
    visibility = ["//visibility:private"],
    deps = [
        "//sil_source:emb_lib_static",
    ],
)

cc_import(
    name = "emb_lib_sharedimport",
    shared_library = "//sil_source:emb_lib_sharedlib",
)

cc_binary(
    name = "test_dlopen",
    srcs = ["dlopen.cpp"],
    data = [
        "//sil_source:emb_lib_sharedlib",
    ],
    linkopts = select({
        "@platforms//os:windows": [],
        "@platforms//os:linux": ["-ldl"],
    }),
    visibility = ["//visibility:private"],
    deps = [
        ":emb_lib_sharedimport",
    ],
)
