//
// Created by Adam Cardenas on 12/17/16.
//

#include "benchmark/benchmark.h"
#include "xtra/xtra.h"


xtra::VectorStack<int> PushPopVectorStack(int size) {
    xtra::VectorStack<int> s;
    for (int i = 0; i < size; ++i) s.push(i);
    for (int i = 0; i < size; ++i) s.pop();
    return s;
}

static void BM_PushPopVectorStackRange(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(PushPopVectorStack(state.range(0)));
    }
    state.SetItemsProcessed(state.iterations() * state.range(0));
    state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(int));
}

BENCHMARK(BM_PushPopVectorStackRange)->Range(1 << 10, 512 << 10);

int SearchVectorStack(xtra::VectorStack<int> s, int item) {
    return s.search(item);
}

static void BM_SearchVectorStackRange(benchmark::State &state) {
    while (state.KeepRunning()) {
        xtra::VectorStack<int> s;

        state.PauseTiming();
        for (int i = 0; i < state.range(0); ++i) s.push(i);
        state.ResumeTiming();

        benchmark::DoNotOptimize(SearchVectorStack(s, state.range(0) - 1));
    }
    state.SetItemsProcessed(state.iterations() * state.range(0));
    state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(int));
}

BENCHMARK(BM_SearchVectorStackRange)->Range(1 << 10, 512 << 10);

BENCHMARK_MAIN();