cc_library(
    name = "PLT_Srv_IoHwAb_fake_lib",
    srcs = [
        "PLT_Srv_IoHwAb_fake.cc",
    ],
    hdrs = [
        "PLT_Srv_IoHwAb_fake.h",
    ],
    # strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/drivers/mcal/dio_wrapper:dio_wrapper_h",
        "@fff",
        "@iND13400_autosar_sip//Components/Dio:Dio_h",
        # "@saf85xx_autosar_sip//Components/_Common/Implementation:BSW_Common_h",
    ],
)

cc_test(
    name = "PLT_Srv_IoHwAb_unit_test",
    size = "small",
    timeout = "short",
    srcs = [
        "PLT_Srv_IoHwAb_unit_test.cc",
    ],
    copts = ["-fno-exceptions"],
    linkstatic = True,
    # target_compatible_with = [
    #     "@platforms//cpu:x86_64",
    # ],
    visibility = ["//visibility:public"],
    deps = [
        ":PLT_Srv_IoHwAb_fake_lib",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb:PLT_Srv_IoHwAb_unit_test_support_lib",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Service_IoHwAb/bb:SWC_PLT_Service_IoHwAb_h",
        "@com_google_googletest//:gtest_main",
    ],
)

test_suite(
    name = "unit_tests",
    tests = [
        ":PLT_Srv_IoHwAb_unit_test",
        # Add other unit tests here
    ],
    visibility = [
        "//:__pkg__",
        "//coverage:__pkg__",
    ],
)
