load("@aptiv-pypi//:requirements.bzl", "requirement")

py_binary(
    name = "flash_memory_stats",
    srcs = [
        "flash_memory_stats.py",
    ],
    main = "flash_memory_stats.py",
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
