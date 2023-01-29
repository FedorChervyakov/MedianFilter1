# Fetch GTest
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0
)
FetchContent_MakeAvailable(googletest)

# Add test executables
add_executable(median_filter_test test_median_filter.cpp)

target_link_libraries(median_filter_test
 PRIVATE 
  GTest::gtest_main
  GTest::gmock_main
  MedianFilter
  )

add_test(test_median_filter median_filter_test)
