# Fetch Google Benchmark
include(FetchContent)

FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG        v1.7.1
)
FetchContent_MakeAvailable(benchmark)

# Add test executables
add_executable(benchmark_median_filter benchmark_median_filter.cpp)

target_link_libraries(benchmark_median_filter
 PRIVATE 
  benchmark::benchmark 
  MedianFilter
  )

#add_test(median_filter_benchmark benchmark_median_filter)
