load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
  name = "median_filter_test",
  size = "small",
  srcs = ["test_median_filter.cpp"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//:median_filter",
  ]
)
