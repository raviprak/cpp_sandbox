add_executable(totw001 totw001.cpp)

# Build using cmake -DGOOGLE_INSTALL_DIR=<path_where_you_cmake_installed_google_libs> ..
add_executable(benchmark001 benchmarks001.cpp)
target_include_directories(benchmark001 PUBLIC ${GOOGLE_INSTALL_DIR}/benchmark/include)
target_link_directories(benchmark001 PUBLIC ${GOOGLE_INSTALL_DIR}/benchmark/lib64)
target_link_libraries(benchmark001 benchmark)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
add_executable(totw001_tests totw001_tests.cpp)
target_include_directories(totw001_tests PRIVATE ${GOOGLE_INSTALL_DIR}/googletest/include)
target_link_directories(totw001_tests PRIVATE ${GOOGLE_INSTALL_DIR}/googletest/lib64)
target_link_libraries(totw001_tests gtest_main gtest)

include(GoogleTest)
gtest_discover_tests(totw001_tests)
