load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "BSW_GenData_Components_h",
    hdrs = glob(["*.h"]),
    strip_include_prefix = "//software/r52/autosar/config/Appl/GenData/Components",
    visibility = ["//visibility:public"],
    deps = [
        "@iND13400_autosar_sip//Components/ComM:ComM_h",
        "@iND13400_autosar_sip//Components/LdCom/Implementation:LdCom_h",
        "@iND13400_autosar_sip//Components/Os:Os_h",
        "@iND13400_autosar_sip//Components/_Common:StdTypes_h",
    ],
)
