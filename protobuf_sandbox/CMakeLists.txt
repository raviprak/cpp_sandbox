project(protobuf_sandbox VERSION 0.1.0)

# We need this so that the generated protobuf source and header files are found.
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

# We need this so that the protobuf_generate_cpp cmake command is found. 
find_package(Protobuf REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")
message(STATUS "Using protoc: ${Protobuf_PROTOC_EXECUTABLE}" )
protobuf_generate_cpp(MY_PROTO_SRCS MY_PROTO_HDRS my_proto.proto)

add_executable(protobuf_example protobuf_example.cpp ${MY_PROTO_SRCS} ${MY_PROTO_HDRS})
target_link_libraries(protobuf_example ${Protobuf_LIBRARIES})
