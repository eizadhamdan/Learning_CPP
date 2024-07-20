#include <iostream>
#include <algorithm>
#include <string>



namespace apple {
    void print(const char* text)
    {
        std::cout << text <<std::endl;
    }
}

namespace orange {
    void print(const char* text)
    {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
}

//the primary purpose of namespaces is to resolve naming conflicts

int main()
{
    //creating an alias for a namespace
    namespace a = apple;
    //this namespace is only confined to the scope of the main function


    a::print("Hello");
    orange::print("Hello");


    std::cin.get();
}