#include "grpc_example_client_lib.h"

absl::StatusOr<int64_t> DoublingClient::SendRequest(const int64_t number)
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
        return reply.doubled_number();
    }
    else
    {
        std::cout << status.error_code() << ": " << status.error_message()
                  << std::endl;
        std::cout << "RPC failed";
        // Ideally we'd have something like https://github.com/grpc/grpc/pull/27903 for converting from grpc::Status to absl::Status[Or]. :-/
        // For an example just throw a random errorcode. :(
        absl::Status to_return(absl::StatusCode::kInternal, status.error_message());
        return to_return;
    }
}
