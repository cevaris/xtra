cmake_minimum_required(VERSION 3.6)
project(xtra)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES xtra/array_stack.cpp xtra/array_stack_test.cpp xtra/array_stack.h xtra/xtra.h main.cpp)
add_executable(xtra ${SOURCE_FILES})

enable_testing()
include_directories(/usr/local/include)
target_link_libraries(xtra /usr/local/lib/libgtest.a)