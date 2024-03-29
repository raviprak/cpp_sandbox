project(grpc_sandbox VERSION 0.1.0)

########################################################################
## Very Important: Make sure the versions of protobuf, 
## absl etc are exactly the ones found in the grpc source (submodules).
## What a PITA.
########################################################################

# We need this to find the grpc_cpp_plugin in the grpc install directory.
find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin ${GOOGLE_INSTALL_DIR}/grpc/bin NO_DEFAULT_PATH)
message(STATUS "Using protoc-gen-grpc: ${_GRPC_CPP_PLUGIN_EXECUTABLE}")

# Find the protoc compiler. We need to find the same version of protoc which is a submodule of the built gRPC library. 
find_program(_PROTOBUF_PROTOC protoc ${GOOGLE_INSTALL_DIR}/grpc/bin NO_DEFAULT_PATH)
message(STATUS "Using protoc from path: ${_PROTOBUF_PROTOC}")

# Generate the *.pb.h *.pb.cc *.grpc.pb.h and *.grpc.pb.cc files.
add_custom_command(
      OUTPUT example_service.pb.cc example_service.pb.h example_service.grpc.pb.cc example_service.grpc.pb.h
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I ${CMAKE_CURRENT_SOURCE_DIR}
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        example_service.proto
      DEPENDS example_service.proto)

# Abseil wants to be linked in via cmake / bazel. Yuck. https://github.com/abseil/abseil-cpp/issues/367
# We have to specify NO_CMAKE_PATH so that the _other_ abseil-cpp installed in ${GOOGLE_INSTALL_DIR} doesn't get picked up. SMH. 
find_package(absl CONFIG REQUIRED PATHS ${GOOGLE_INSTALL_DIR}/grpc/lib64/cmake/absl NO_DEFAULT_PATH NO_CMAKE_PATH)
message(STATUS "Using absl ${absl_VERSION}")

# We need this because the subsequent find_package for gRPC needs it. 
find_package(Protobuf CONFIG REQUIRED PATHS ${GOOGLE_INSTALL_DIR}/grpc NO_CMAKE_PATH)

find_package(gRPC CONFIG REQUIRED PATHS ${GOOGLE_INSTALL_DIR}/grpc NO_CMAKE_PATH NO_DEFAULT_PATH)
message(STATUS "Using gRPC ${gRPC_VERSION}")

# Create a separate library for the stubs and protobufs created from generated code.
add_library(example_server_stubs example_service.pb.cc example_service.pb.h example_service.grpc.pb.cc example_service.grpc.pb.h)
target_link_libraries(example_server_stubs gRPC::grpc++_reflection gRPC::grpc++ protobuf::libprotobuf)

# Create a separate library for the server so that it can be included in the server main as well as unit tests.
add_library(grpc_example_server_lib grpc_example_server.cpp grpc_example_server.h)
target_include_directories(grpc_example_server_lib PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")
target_link_libraries(grpc_example_server_lib example_server_stubs)

# The example server. 
add_executable(grpc_example_server grpc_example_server_main.cpp)
target_link_libraries(grpc_example_server grpc_example_server_lib absl::flags absl::flags_parse example_server_stubs)

# Create a separate example client library so that it can be used in the client as well as unit tests.
add_library(grpc_example_client_lib grpc_example_client_lib.h  grpc_example_client_lib.cpp)
target_include_directories(grpc_example_client_lib PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")
target_link_libraries(grpc_example_client_lib example_server_stubs)

# The example client.
add_executable(grpc_example_client grpc_example_client_main.cpp)
target_link_libraries(grpc_example_client absl::flags absl::flags_parse example_server_stubs grpc_example_client_lib)

# The unit tests for our server and client.
set(CMAKE_CXX_STANDARD 17)
add_executable(grpc_example_server_tests grpc_example_server_tests.cpp)
target_include_directories(grpc_example_server_tests PUBLIC ${GOOGLE_INSTALL_DIR}/googletest/include)
target_link_directories(grpc_example_server_tests PUBLIC ${GOOGLE_INSTALL_DIR}/googletest/lib64)
target_link_libraries(grpc_example_server_tests grpc_example_server_lib grpc_example_client_lib gtest_main gtest)

include(GoogleTest)
gtest_discover_tests(grpc_example_server_tests)
