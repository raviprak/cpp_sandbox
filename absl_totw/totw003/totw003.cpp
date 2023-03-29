#include <string>
#include <iostream>
#include "absl/strings/str_cat.h"

int main() {
    std::string str1 = "My favorite first string.";
    std::string str2 = "My favorite second string.";
    std::string str3 = "My favorite third string.";

    std::string all_strings = str1 + " " + str2 + " " + str3;
    std::cout << all_strings << std::endl;

    std::string all_catted_strings = absl::StrCat(str1, " ", str2, " ", str3);
    std::cout << all_catted_strings << std::endl;
}