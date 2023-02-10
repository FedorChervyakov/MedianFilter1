load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "benchmark_median_filter",
    srcs = ["benchmark_median_filter.cpp"],
    deps = [
        "@com_google_benchmark//:benchmark_main",
        "//:median_filter",
    ]
)
