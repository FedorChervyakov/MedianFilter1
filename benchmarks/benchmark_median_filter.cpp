#include "MedianFilter.h"
#include <benchmark/benchmark.h>


static void BM_Filter(benchmark::State& state) {
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

BENCHMARK(BM_Filter)
  ->Range(0, 1<<16)
  ->Complexity(benchmark::oAuto);

BENCHMARK_MAIN();
