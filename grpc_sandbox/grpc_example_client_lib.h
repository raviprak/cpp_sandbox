#include <memory>

#include <grpcpp/grpcpp.h>
#include <absl/status/statusor.h>

#include "example_service.grpc.pb.h"
#include "example_service.pb.h"

class DoublingClient
{
public:
    DoublingClient(const std::string &target)
    {
        auto channel = grpc::CreateChannel(target, grpc::InsecureChannelCredentials());
        stub_ = DoublingRandomWaitService::NewStub(channel);
    }

    absl::StatusOr<int64_t> SendRequest(const int64_t number);

private:
    std::unique_ptr<DoublingRandomWaitService::Stub> stub_;
};