#include <iostream>
#include <memory>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

#include <grpcpp/grpcpp.h>

#include "example_service.grpc.pb.h"
#include "example_service.pb.h"

ABSL_FLAG(std::string, target, "localhost:50051", "Server address");

class DoublingClient
{
public:
    DoublingClient(std::shared_ptr<grpc::Channel> channel)
        : stub_(DoublingRandomWaitService::NewStub(channel)) {}

    void SendRequest(const int64_t number)
    {
        DoublingRequest request;
        request.set_number(number);

        DoublingReply reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        grpc::ClientContext context;

        // The actual RPC.
        grpc::Status status = stub_->DoubleThis(&context, request, &reply);

        // Act upon its status.
        if (status.ok())
        {
            std::cout << "Request successful. Doubled number = " << reply.doubled_number() << std::endl;
        }
        else
        {
            std::cout << status.error_code() << ": " << status.error_message()
                      << std::endl;
            std::cout << "RPC failed";
        }
    }

private:
    std::unique_ptr<DoublingRandomWaitService::Stub> stub_;
};

int main(int argc, char **argv)
{
    absl::ParseCommandLine(argc, argv);
    // Instantiate the client. It requires a channel, out of which the actual RPCs
    // are created. This channel models a connection to an endpoint specified by
    // the argument "--target=" which is the only expected argument.
    std::string target_str = absl::GetFlag(FLAGS_target);
    // We indicate that the channel isn't authenticated (use of
    // InsecureChannelCredentials()).
    DoublingClient doubling_client(
        grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
    doubling_client.SendRequest(10);
    return 0;
}