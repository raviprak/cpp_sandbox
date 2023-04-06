add_executable(totw001 totw001.cpp)

# Build using cmake -DGOOGLETEST_INSTALL_DIR=<path_where_you_cmake_installed_googletest> ..
add_executable(benchmark001 benchmarks001.cpp)
include_directories(${GOOGLETEST_INSTALL_DIR}/benchmark/include)
link_directories(${GOOGLETEST_INSTALL_DIR}/benchmark/lib64)
target_link_libraries(benchmark001 benchmark)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
include_directories(${GOOGLETEST_INSTALL_DIR}/googletest/include)
link_directories(${GOOGLETEST_INSTALL_DIR}/googletest/lib64)
add_executable(totw001_tests totw001_tests.cpp)
target_link_libraries(totw001_tests gtest_main gtest)

include(GoogleTest)
gtest_discover_tests(totw001_tests)
