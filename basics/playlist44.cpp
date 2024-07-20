#include <iostream>
#include <string>

template<typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

int main()
{
    Print<int>(5);              //we can also do this
    Print("Hello");
    Print(5.5f);

    std::cin.get();
}