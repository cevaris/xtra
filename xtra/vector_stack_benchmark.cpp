//
// Created by Adam Cardenas on 12/17/16.
//

#include "benchmark/benchmark.h"
#include "xtra.h"

#include <list>
#include <map>
#include <set>
#include <sstream>
#include <thread>

double CalculatePi(int depth) {
    double pi = 0.0;
    for (int i = 0; i < depth; ++i) {
        double numerator = static_cast<double>(((i % 2) * 2) - 1);
        double denominator = static_cast<double>((2 * i) - 1);
        pi += numerator / denominator;
    }
    return (pi - 1.0) * 4;
}

static void BM_CalculatePiRange(benchmark::State &state) {
    double pi = 0.0;
    while (state.KeepRunning()) pi = CalculatePi(state.range(0));
    std::stringstream ss;
    ss << pi;
    state.SetLabel(ss.str());
}

BENCHMARK_RANGE(BM_CalculatePiRange, 1, 1024 * 1024);

static void BM_CalculatePi(benchmark::State &state) {
    static const int depth = 1024;
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(CalculatePi(depth));
    }
}

BENCHMARK(BM_CalculatePi)->Threads(8);
BENCHMARK(BM_CalculatePi)->ThreadRange(1, 32);
BENCHMARK(BM_CalculatePi)->ThreadPerCpu();


BENCHMARK_MAIN();