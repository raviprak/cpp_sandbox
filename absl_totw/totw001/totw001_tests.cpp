#include <gtest/gtest.h>
#include <string>
#include <string_view>

TEST(StringViewTest, BasicTest)
{
    std::string my_string = "My precious string";
    std::string_view my_view = my_string;
    EXPECT_EQ(my_view, my_string);
    const char *my_char_arr = "My precious string";
    EXPECT_EQ(my_view, my_char_arr);
}