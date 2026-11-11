load("@aptiv-pypi//:requirements.bzl", "requirement")

py_binary(
    name = "create_flash_image",
    srcs = [
        "create_flash_image.py",
    ],
    main = "create_flash_image.py",
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
