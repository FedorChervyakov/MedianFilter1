load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

git_repository(
  name = "com_google_googletest",
  remote = "https://github.com/google/googletest.git",
  tag = "v1.13.0",
)

git_repository(
  name = "com_google_benchmark",
  remote = "https://github.com/google/benchmark.git",
  tag = "v1.7.1",
)

# Hedron's Compile Commands Extractor for Bazel
# https://github.com/hedronvision/bazel-compile-commands-extractor
http_archive(
    name = "hedron_compile_commands",
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/d3afb5dfadd4beca48bb027112d029f2d34ff0a0.tar.gz",
    strip_prefix = "bazel-compile-commands-extractor-d3afb5dfadd4beca48bb027112d029f2d34ff0a0",
)
load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")
hedron_compile_commands_setup()
