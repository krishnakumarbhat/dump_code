load("@aptiv-pypi//:requirements.bzl", "requirement")

py_binary(
    name = "spc_gen",
    srcs = [
        "spc_gen.py",
    ],
    main = "spc_gen.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        requirement("argparse_addons"),
        requirement("bincopy"),
        requirement("humanfriendly"),
        requirement("pyelftools"),
    ],
)
