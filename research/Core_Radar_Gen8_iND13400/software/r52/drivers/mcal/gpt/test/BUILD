cc_test(
    name = "dd_gpt_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "dd_gpt_unit_test.cc",
    ],
    defines = ["UNITTEST"],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:gpt_cfg_h",
        "//software/r52/drivers/mcal/gpt:dd_gpt_unit_test_lib",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@iND13400_autosar_sip//Components/Gpt:gpt_h",
        "@iND13400_autosar_sip//Components/Gpt/test/mocks:Gpt_fake_lib",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":dd_gpt_unit_test",
    ],
    visibility = ["//visibility:public"],
)
