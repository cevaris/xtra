cmake_minimum_required(VERSION 3.6)
project(xtra)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES xtra/vector_stack.cpp xtra/vector_stack_test.cpp xtra/vector_stack.h xtra/xtra.h main.cpp)
add_executable(xtra ${SOURCE_FILES})

enable_testing()
include_directories(/usr/local/include)
target_link_libraries(xtra /usr/local/lib/libgtest.a)

set(BENCHMARK_SOURCE_FILES xtra/xtra.h xtra/xtra_benchmark.cpp)
add_executable(benchmark_xtra ${BENCHMARK_SOURCE_FILES})
include_directories(/usr/local/include)
target_link_libraries(benchmark_xtra /usr/local/lib/libbenchmark.a)