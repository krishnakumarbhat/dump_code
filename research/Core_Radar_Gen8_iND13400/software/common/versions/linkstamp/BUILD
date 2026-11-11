exports_files([
    "gen_gitinfo_hdr.ps1",
    "gen_gitinfo_hdr.sh",
    "gen_workspace_status.bat",
    "gen_workspace_status.sh",
])

genrule(
    name = "copy_stamp_files",
    outs = [
        "stable-status.txt",
        "volatile-status.txt",
    ],
    cmd = "cp bazel-out/*-status.txt $(RULEDIR)",
    cmd_ps = "Copy-Item -Force -Path bazel-out/*-status.txt -Destination $(RULEDIR)",
    stamp = 1,
    visibility = ["//:__pkg__"],
)
