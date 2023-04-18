#include "absl/status/statusor.h"
#include <grpcpp/grpcpp.h>

#include "example_service.grpc.pb.h"
#include "example_service.pb.h"

class DoublingRandomWaitServiceImpl final : public DoublingRandomWaitService::Service
{
public:
    grpc::Status DoubleThis(grpc::ServerContext *context, const DoublingRequest *request, DoublingReply *reply) override;

    void StartDoublingRandomWaitService(int port);

    void Wait();

private:
    std::unique_ptr<grpc::Server> server_;
};
