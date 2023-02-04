#include "MedianFilter.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;


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

class MedianFilterFilteringTests:
  public testing::TestWithParam<tuple<int, vector<double>, vector<double>>>
{
};

TEST_P(MedianFilterFilteringTests, FilterOperation) {
  const int N_TAPS = get<0>(GetParam());
  vector<double> input_x = get<1>(GetParam());
  vector<double> expected_y = get<2>(GetParam());

  vector<double> actual_y(expected_y.size(), 0);

  MedianFilter filter(N_TAPS);

  for (int i = 0; i<expected_y.size(); i++) {
    actual_y[i] = filter.filter(input_x[i]);
  }

  EXPECT_THAT(actual_y, testing::Pointwise(testing::DoubleEq(), expected_y));
}

const vector<tuple<int, vector<double>, vector<double>>> filtering_sequences {
  // Test single tap median filter doesn't modify input
  {1, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}},
  {1, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}},
  // Test double tap median filter produces halved values
  {2, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}},
  {2, {1, 2, 3, 4, 5}, {0.5, 1.5, 2.5, 3.5, 4.5}},
  // Test tripple tap median filter filters correctly
  {3, {1, 1, 1, 1, 1}, {0, 1, 1, 1, 1}},
  {3, {-1, -1, -1, -1, -1}, {0, -1, -1, -1, -1}},
  {3, {1, 2, 3, 4, 5}, {0, 1, 2, 3, 4}},
  {3, {-2, -1, 0, 1, 2}, {0, -1, -1, 0, 1}},
};

INSTANTIATE_TEST_SUITE_P(
    MedianFilterTests,
    MedianFilterFilteringTests,
    ::testing::ValuesIn(filtering_sequences)
);


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
