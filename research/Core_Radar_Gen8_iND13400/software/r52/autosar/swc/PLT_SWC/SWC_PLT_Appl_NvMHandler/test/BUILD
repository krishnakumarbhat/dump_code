cc_library(
    name = "SWC_PLT_Appl_NvMHandler_fake_lib",
    srcs = [
        "NvM.h",
        "Rte_SWC_PLT_Appl_NvMHandler.h",
        "Rte_Type.h",
        "SWC_PLT_Appl_NvMHandler_fake.cc",
    ],
    hdrs = [
        "Fee_30_FlexNor.h",
        "Fls.h",
        "MemIf.h",
        "NvM.h",
        "Rte_SWC_PLT_Appl_NvMHandler.h",
        "Rte_Type.h",
        "SWC_PLT_Appl_NvMHandler_MemMap.h",
        "fixmac.h",
    ],
    strip_include_prefix = "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_NvMHandler/test",
    visibility = ["//visibility:public"],
    deps = [],
)

cc_test(
    name = "SWC_PLT_Appl_NvMHandler_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "SWC_PLT_Appl_NvMHandler_unit_test.cc",
    ],
    copts = [
        "-Isoftware/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_NvMHandler/test",
    ],
    linkstatic = True,
    target_compatible_with = [
        "@platforms//cpu:x86_64",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":SWC_PLT_Appl_NvMHandler_fake_lib",
        "//software/common/crc32:crc32_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Appl_NvMHandler:SWC_PLT_Appl_NvMHandler_unit_test_support_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":SWC_PLT_Appl_NvMHandler_unit_test",
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
