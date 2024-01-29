cmake_minimum_required(VERSION 3.5.0)
project(cpp_sandbox VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_CXX_CLANG_TIDY clang-tidy)

add_subdirectory(absl_totw)
add_subdirectory(protobuf_sandbox)
add_subdirectory(grpc_sandbox)
add_subdirectory(absl_log_sandbox)
add_subdirectory(boost_sandbox)
