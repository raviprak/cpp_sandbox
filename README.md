# Sandbox for playing with C++.

* absl_totw contains the tips of the week from [Abseil tips of the week](https://abseil.io/tips/).
* protobuf_sandbox is my sandbox for experimenting with [Protocol Buffers](https://protobuf.dev/).
* grpc_sandbox is my sandbox for experimenting with [GRPC](https://grpc.io/).

To build the whole source tree, from cpp_sandbox:
```
mkdir build
cd build
cmake -DGOOGLE_INSTALL_DIR=<directory where you installed google libs> ..
make
