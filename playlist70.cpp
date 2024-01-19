/*
How to store any kind of data in C++
(Since C++17)
*/
#include <iostream>
#include <any>
#include <string>

int main()
{
    std::any data;
    data = 2;
    data = "Eizad";
    data = std::string("Hello");

    //to retrieve the data we have to cast it to the appropriate data type.
    //this will throw an exception if it's a bad cast
    std::string& data_string = std::any_cast<std::string&>(data);

    //std::variant is much more type safe than std::any because we have to list all the possible
    //types that the variable can be
    /*
    Varaint is a type safe union.
    std::any for small data types stores them as a union so for small types it 
    is the same as std::variant. For large types it uses a void pointer an dynamically allocates memory for it.
    (dynamically allocating is not good for performance)
    */

    std::cin.get();
}