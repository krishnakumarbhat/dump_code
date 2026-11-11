load("@aptiv-pypi//:requirements.bzl", "requirement")

py_binary(
    name = "getUTTrueCount",
    srcs = [
        "__init__.py",
        "getUTTrueCount.py",
    ],
    main = "getUTTrueCount.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        requirement("python-dateutil"),
        requirement("et-xmlfile"),
        requirement("numpy"),
        requirement("openpyxl"),
        requirement("pandas"),
        requirement("pytz"),
        requirement("six"),
    ],
)
