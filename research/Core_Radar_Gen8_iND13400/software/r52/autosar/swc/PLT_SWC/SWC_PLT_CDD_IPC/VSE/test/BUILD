load("@rules_cc//cc:defs.bzl", "cc_test")

# bazelisk test //software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/VSE/test:unit_tests -c dbg --jobs=auto
cc_test(
    name = "unit_tests",
    size = "small",
    timeout = "short",
    srcs = [
        "vse_core_unit_test.cc",
    ],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/VSE:vse_core_c_api",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_IPC/VSE/vse_stub:vse_teststub",
        "@com_google_googletest//:gtest_main",
    ],
)
