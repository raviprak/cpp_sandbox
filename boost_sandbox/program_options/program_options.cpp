#include <iostream>
#include "boost/program_options.hpp"

int main(int argc, char **argv)
{
    boost::program_options::options_description desc("Sandbox program options");
    boost::program_options::positional_options_description command;
    command.add("command", 1);

    desc.add_options()("help", "produce help message")("address", boost::program_options::value<std::string>(), "server address as host:port")("command", boost::program_options::value<std::string>(), "command");
    std::cout << "Hello World!\n";

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::command_line_parser(argc, argv).options(desc).positional(command).run(), vm);
    boost::program_options::notify(vm);

    if (vm.count("help"))
    {
        std::cout << desc << "\n";
        return 0;
    }
    if (vm.count("command"))
    {
        std::cout << "Command found : " << vm["command"].as<std::string>() << std::endl;
    }
    if (vm.count("address"))
    {
        std::cout << "Using server at " << vm["address"].as<std::string>() << std::endl;
    }
}