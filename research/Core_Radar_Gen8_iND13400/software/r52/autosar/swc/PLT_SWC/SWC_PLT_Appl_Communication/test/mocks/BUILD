cc_library(
    name = "can_tx_msgs_stubs_lib",
    srcs = [
        "can_tx_msgs_stubs.cc",
    ],
    hdrs = [
        "can_tx_msgs_stubs.h",
    ],
    strip_include_prefix = ".",
    visibility = ["//visibility:public"],
    deps = [
        "//software/r52/autosar/swc/COMMON/Diagnostic_Library:Fault_Lib_Plt_h",
        "//software/r52/autosar/config/Appl/GenData:BSW_GenData_h",
        "//software/r52/autosar/config/Appl/GenData/Components:BSW_GenData_Components_h",
        "//software/common/calib_cfg:calibration_handler_cfg",
        # "@calib_cfg//:calib_cfg_h",
        "//software/r52/ipc:ipc_mss_h",
        "//software/common/ipc:ipc_data_h",
        "//software/common/versions:versions_hdrs",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_Radar_Alignment_Handler:SWC_PLT_Radar_Alignment_Handler_h",
        "//software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/bb:SWC_PLT_Appl_XCP_H",
        "//software/r52/mmic:mmic_error_h",
        "@Sensor_Position//:sensor_position_h",
        "@fff",
        "@reuse",
    ],
)
