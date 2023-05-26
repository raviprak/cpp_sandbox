project(absl_log_sandbox VERSION 0.1.0)

find_package(absl CONFIG REQUIRED)

add_executable(absl_log_sandbox absl_log_sandbox.cpp)
# target_include_directories(absl_log_sandbox PUBLIC absl::log)
target_link_libraries(absl_log_sandbox absl::log absl::log_initialize)

