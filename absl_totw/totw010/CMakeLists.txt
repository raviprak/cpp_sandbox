cmake_minimum_required(VERSION 3.10)
project(totw010 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(totw010 totw010.cc)
target_link_libraries(totw010 absl_strings)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
