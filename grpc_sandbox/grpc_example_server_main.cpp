#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

#include "grpc_example_server.h"

ABSL_FLAG(uint16_t, port, 50051, "Server port for the service");

int main(int argc, char **argv)
{
    absl::ParseCommandLine(argc, argv);

    DoublingRandomWaitServiceImpl server;
    server.StartDoublingRandomWaitService(absl::GetFlag(FLAGS_port));
    server.Wait();

    return 0;
}
