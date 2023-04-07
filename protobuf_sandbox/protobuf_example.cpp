#include <iostream>
#include "my_proto.pb.h"

int main()
{
    MySimpleProto my_simple_proto;
    my_simple_proto.set_my_string("Hello World!");
    std::cout << my_simple_proto.DebugString() << std::endl;
}