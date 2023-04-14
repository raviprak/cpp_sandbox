
add_executable(totw003 totw003.cpp)
target_link_libraries(totw003 absl_strings)

add_executable(benchmark003 benchmarks003.cpp)
target_link_libraries(benchmark003 absl_strings)
target_include_directories(benchmark003 PUBLIC ${GOOGLE_INSTALL_DIR}/benchmark/include)
target_link_directories(benchmark003 PUBLIC ${GOOGLE_INSTALL_DIR}/benchmark/lib64)
target_link_libraries(benchmark003 benchmark)