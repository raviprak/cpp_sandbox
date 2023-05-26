#include <iostream>

#include "absl/log/log.h"
#include "absl/log/initialize.h"

int main()
{
    absl::InitializeLog();
    LOG(ERROR) << "Logging a message with severity INFO to stderr.";
    std::cout << "Writing a message to stdout." << std::endl;
    return 0;
}
 