/*
Storing multiple types of data in one variable.
(Since C++17)
*/


#include <iostream>
#include <variant>
#include <string>

int main()
{
    std::variant<std::string, int> data;
    /*
    variants work by storing all the possible data types as separate variables as separate members.
    */
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(std::string) << std::endl;
    std::cout << sizeof(data) << std::endl;
    
    data = "Eizad";

    std::cout << std::get<std::string>(data) << std::endl;          //to access the data
    
    if (auto value = std::get_if<std::string>(&data))
    {
        std::string& v = *value; 
    }


    data = 3;
    std::cout << std::get<int>(data) << std::endl;              //to access the data

    std::cin.get();
}