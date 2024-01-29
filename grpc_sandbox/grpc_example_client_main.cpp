#include <iostream>
#include <memory>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

#include "grpc_example_client_lib.h"
#include <grpcpp/grpcpp.h>

ABSL_FLAG(std::string, target, "localhost:50051", "Server address");

int main(int argc, char **argv)
{
    absl::ParseCommandLine(argc, argv);
    // Instantiate the client. It requires a channel, out of which the actual RPCs
    // are created. This channel models a connection to an endpoint specified by
    // the argument "--target=" which is the only expected argument.
    std::string target_str = absl::GetFlag(FLAGS_target);
    // We indicate that the channel isn't authenticated (use of
    // InsecureChannelCredentials()).
    DoublingClient doubling_client(target_str);
    absl::StatusOr<int64_t> reply = doubling_client.SendRequest(10);
    return reply.ok() ? 0 : -1;
}