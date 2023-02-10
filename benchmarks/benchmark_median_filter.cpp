#include "MedianFilter1/MedianFilter.h"
#include <benchmark/benchmark.h>


static void BM_FilterOnes(benchmark::State& state) {
  // setup
  MedianFilter filter(state.range(0));
  double x = 1;
  double y = 0;

  for (auto _: state) {
    // timed section
    y = filter.filter(x);
    benchmark::DoNotOptimize(y);

  }
}

static void BM_FilterRandom(benchmark::State& state) {
  // setup
  MedianFilter filter(state.range(0));
  double x = 1;
  double y = 0;

  for (auto _: state) {
    // timed section
    x = std::rand();
    y = filter.filter(x);
    benchmark::DoNotOptimize(y);

  }
}

BENCHMARK(BM_FilterOnes)
  ->Range(0, 1<<16)
  ->Complexity(benchmark::oAuto);

BENCHMARK(BM_FilterRandom)
  ->Range(0, 1<<16)
  ->Complexity(benchmark::oAuto);

BENCHMARK_MAIN();
