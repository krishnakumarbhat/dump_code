load("@rules_python//python:pip.bzl", "compile_pip_requirements")

exports_files(
    srcs = ["requirements.in"],
    visibility = ["//visibility:public"],
)

compile_pip_requirements(
    name = "requirements",
    src = ":requirements.in",
    extra_args = [
        "--index-url=https://jfrog.asux.aptiv.com/artifactory/api/pypi/pypi-org-remote/simple",
    ],
    requirements_txt = "requirements.txt",
)
