cc_test(
    name = "dio_wrapper_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "dio_wrapper_unit_test.cc",
    ],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = [
        "//software/common/board_revision/test/mocks:board_revision_mocks",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/drivers/mcal/dio_wrapper:dio_wrapper_ut_lib",
        "//software/r52/drivers/mcal/dio_wrapper/test/mocks:dio_wrapper_fake",
        "@com_google_googletest//:gtest_main",
        "@fff",
        "@iND13400_autosar_sip//Components/Dio:Dio_h",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":dio_wrapper_unit_test",
    ],
    visibility = ["//visibility:public"],
)
