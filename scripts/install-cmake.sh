#!/usr/bin/env bash

if [[ "${TRAVIS_OS_NAME}" == "linux" ]]; then
    CMAKE_URL="https://cmake.org/files/v3.6/cmake-3.6.3-Linux-x86_64.tar.gz"
    wget --no-check-certificate ${CMAKE_URL}
    tar xf cmake-3.6.3-Linux-x86_64.tar.gz
    export PATH=${DEPS_DIR}/cmake-3.6.3-Linux-x86_64/bin:${PATH}
else
    brew install cmake
fi