#include "grpc_example_server.h"

#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <chrono>
#include <random>

#include "absl/strings/str_format.h"
#include "absl/status/statusor.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "example_service.grpc.pb.h"
#include "example_service.pb.h"

grpc::Status DoublingRandomWaitServiceImpl::DoubleThis(grpc::ServerContext *context, const DoublingRequest *request,
                                                       DoublingReply *reply)
{
  reply->set_doubled_number(request->number() * 2);

  int sleep_seconds = rand() % 10;
  std::cout << "New doubling request received. Going to sleep for " << sleep_seconds << " seconds. ";
  std::this_thread::sleep_for(std::chrono::seconds(sleep_seconds));
  std::cout << "Finished sleeping." << std::endl;
  return grpc::Status::OK;
}

void DoublingRandomWaitServiceImpl::StartDoublingRandomWaitService(int port)
{
  std::string server_address = absl::StrFormat("0.0.0.0:%d", port);

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  grpc::ServerBuilder builder;

  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(this);

  // Finally assemble the server.
  server_ = builder.BuildAndStart();
  std::cout << "Server listening on " << server_address << std::endl;
}

void DoublingRandomWaitServiceImpl::Wait()
{
  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server_->Wait();
}
