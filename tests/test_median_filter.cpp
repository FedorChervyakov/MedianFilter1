#include "MedianFilter.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>


TEST(MedianFilterTests, TestReset) {
  constexpr int N_TAPS = 20;
  MedianFilter filter(N_TAPS);
  filter.reset();
}

TEST(MedianFilterTests, TestGetTaps) {
  constexpr int N_TAPS = 20;
  MedianFilter filter(N_TAPS);

  constexpr int expected = N_TAPS;
  unsigned int actual = filter.getTaps();

  ASSERT_EQ(actual, expected);
}

TEST(MedianFilterTests, TestFilterOperation_Const) {
  constexpr int N_TAPS = 3;
  constexpr int INPUT_SIZE = 5;

  constexpr double x[INPUT_SIZE] = {1, 1, 1, 1, 1};
  constexpr double expected_y[INPUT_SIZE] = {0, 1, 1, 1, 1};
  double actual_y[INPUT_SIZE] = {0};

  MedianFilter filter(N_TAPS);

  for (auto i = 0; i<INPUT_SIZE; i++) {
    actual_y[i] = filter.filter(x[i]);
  }

  EXPECT_THAT(actual_y, testing::Pointwise(testing::DoubleEq(), expected_y));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
