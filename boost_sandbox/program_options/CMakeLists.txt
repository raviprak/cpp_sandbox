add_executable(program_options program_options.cpp)

find_package(Boost REQUIRED program_options)
target_link_libraries(program_options PRIVATE ${Boost_LIBRARIES})