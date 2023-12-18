#include <iostream>
#include <string>

#include <stdlib.h>

int main()
{
    using namespace std::string_literals;

    std::string name0 = "Hello"s + "user";

    std::u32string name4 = U"Hello"s + U"user"; 

    const char* name = u8"Eizad";

    const wchar_t* name1 = L"Hamdan";           //capital L signifies that the following string literal is made up of wide characters
    //wchar_t is 2 bytes per character

    const char16_t* name2 = u"Eizad";               //2 bytes per character

    const char32_t* name3 = U"Hamdan";              //4 bytes per character


    const char* example = R"(Line1
    Line2
    Line3
    Line4)";            //R stands for raw


    std::cout << name << std::endl;


    std::cin.get();
}