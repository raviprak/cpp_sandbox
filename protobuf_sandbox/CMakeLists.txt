cmake_minimum_required(VERSION 3.0.0)
project(protobuf_sandbox VERSION 0.1.0)

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

find_package(Protobuf REQUIRED)
protobuf_generate_cpp(MY_PROTO_SRCS MY_PROTO_HDRS my_proto.proto)

include_directories()
add_executable(protobuf_example protobuf_example.cpp ${MY_PROTO_SRCS} ${MY_PROTO_HDRS})
target_link_libraries(protobuf_example ${Protobuf_LIBRARIES})