cmake_minimum_required(VERSION 3.6)
project(xtra)

set(CMAKE_CXX_STANDARD 11)

enable_testing()
include_directories(/usr/local/include)

file(GLOB SOURCE_FILES
        "xtra_test.cpp"
        "xtra/*.h"
        "xtra/*.cpp"
        "xtra/*_test.cpp"
        )
add_executable(xtra_test ${SOURCE_FILES})

target_link_libraries(xtra_test /usr/local/lib/libgtest.a)


option(WITH_BENCHMARK "with benchmark test" ON)
if(WITH_BENCHMARK)
    set(BENCHMARK_SOURCE_FILES xtra/xtra.h xtra_benchmark.cpp)
    add_executable(xtra_benchmark ${BENCHMARK_SOURCE_FILES})
    target_link_libraries(xtra_benchmark /usr/local/lib/libbenchmark.a)
endif(WITH_BENCHMARK)
