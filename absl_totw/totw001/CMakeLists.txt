
add_executable(totw001 totw001.cpp)
add_executable(benchmark001 benchmarks001.cpp)

find_package(benchmark REQUIRED)
target_link_libraries(benchmark001 benchmark::benchmark)