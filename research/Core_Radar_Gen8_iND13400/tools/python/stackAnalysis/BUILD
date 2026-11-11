py_binary(
    name = "stackAnalysis",
    srcs = [
        "__init__.py",
        "loghelper.py",
        "stackAnalysis.py",
        "stack_parser.py",
        "xt_stack_usage.py",
    ],
    data = glob(["*.ini"]),
    imports = ["."],
    main = "stackAnalysis.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
)
