// https://abseil.io/tips/1

#include <iostream>
#include <string_view>

void fn_accepts_char_arr(const char *char_arr)
{
    std::cout << "Got char array: " << char_arr << std::endl;
}

void fn_accepts_string(const std::string &str)
{
    std::cout << "Got string: " << str << std::endl;
}

void fn_accepts_string_view(std::string_view str_view)
{
    std::cout << "Got string_view: " << str_view << std::endl;
}

int main(int, char **)
{
    const char *my_char_arr = "This is my precious character array.";
    std::string my_str("This is my precious string object.");
    fn_accepts_char_arr(my_char_arr);
    // fn_accepts_char_arr(my_str); // Compilation error.
    fn_accepts_string(my_char_arr); // A temporary string object is made created.
    fn_accepts_string(my_str);
    fn_accepts_string_view(my_char_arr);
    fn_accepts_string_view(my_str);
    return 0;
}
