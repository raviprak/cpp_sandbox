
add_executable(totw003 totw003.cpp)
target_link_libraries(totw003 absl_strings)

add_executable(benchmark003 benchmarks003.cpp)
find_package(benchmark REQUIRED)
target_link_libraries(benchmark003 absl_strings)
target_link_libraries(benchmark003 benchmark::benchmark)