/*A string is a group of characters*/
#include <iostream>
#include <string>


void PrintString(const std::string& string)             //this passes the string by reference(passing a string by value is not recommended because copying operation is slow)
{
    std::cout << string << std::endl;
}

int main()
{
    const char* name = "Eizad";
    std::cout << name << std::endl;

    std::string name1 = "Hamdan";
    std::cout << name1 << std::endl;
    int size = name1.size();

    std::cout << size << std::endl;


    std::string name2 = std::string("hello") + "user";      //to concatenate two strings
    std::cout << name2 << std::endl;

    bool contains = name2.find("llo") != std::string::npos;         //to check  whether a string contains a group of characters or not


    std::cout << contains << std::endl;

    PrintString(name2);


}
