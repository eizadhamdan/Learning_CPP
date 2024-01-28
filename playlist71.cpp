/*From C++17 onwards*/
#include <iostream>
#include <string>

static uint32_t s_AllocCount = 0;

//overloading the new operator to track the number of memory allocations
void* operator new(size_t size)
{
    s_AllocCount++;
    std::cout << "Allocating " << size << " bytes." << std::endl;
    return malloc(size);
}

void PrintName(std::string_view name)
{
    std::cout << name << std::endl;
}

int main()
{
    std::string name = "Eizad Hamdan";
    
    std::string firstName = name.substr(0, 5);
    std::string lastName = name.substr(6, 13); 


    //this passes around the pointer in memory
    std::string_view firstName(name.c_str(), 5);
    std::string_view lastName(name.c_str() + 6, 13);

    PrintName(firstName);
    PrintName(lastName);
    
    std::cout << s_AllocCount << " allocations." << std::endl;

    std::cin.get();
}