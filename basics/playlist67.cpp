/*
Structured bindings in C++ help us to deal with multiple return values.
(Since C++17)
*/

#include <iostream>
#include <tuple>
#include <string>

std::tuple<std::string, int> CreatePerson()
{
    return { "Eizad", 20 };
}

int main()
{   
    std::tuple<std::string, int> person = CreatePerson();
    auto person1 = CreatePerson();

    std::string& name0 = std::get<0>(person);
    int age1 = std::get<1>(person);

    //alternatively we can also do this
    std::string Name;
    int Age;
    std::tie(Name, Age) = CreatePerson();


    /*
    Structured Binding
    */
    auto[name, age] = CreatePerson();
    std::cout << name << ", " << age << std::endl;




    std::cin.get();
}