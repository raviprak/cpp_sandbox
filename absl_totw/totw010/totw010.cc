// https://abseil.io/tips/10
#include <absl/strings/str_split.h>
#include <iostream>

using namespace std;

int main() {
	std::vector<absl::string_view> v = absl::StrSplit("a,b,c", ',');
	for(auto split: v) {
		cout << split << endl;
	}
	return 0;
}

// Build using
// $ g++ -labsl_throw_delegate -labsl_strings totw010.cc
