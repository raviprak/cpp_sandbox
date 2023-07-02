// https://abseil.io/tips/18
#include <iostream>
#include <absl/strings/substitute.h>

using namespace std;

int main()
{
	std::string message = absl::Substitute("Adding a string ($0), an int ($1) and a bool ($2)", "a string", 10, true);
	std::cout << message << endl;
}

/* Output
$ ./totw018
Adding a string (a string), an int (10) and a bool (true)
*/