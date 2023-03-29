cmake_minimum_required(VERSION 3.0.0)
project(totw001 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(totw001 totw001.cpp)

add_executable(benchmark001 benchmarks001.cpp)

find_package(benchmark REQUIRED)
target_link_libraries(benchmark001 benchmark::benchmark)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

