cmake_minimum_required(VERSION 3.0.0)
project(absl_totw VERSION 0.1.0)

include(CTest)
enable_testing()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


add_subdirectory(totw001)
add_subdirectory(totw003)
add_subdirectory(totw010)