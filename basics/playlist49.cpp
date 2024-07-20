#include <iostream>

namespace first
{
    int val = 50;
}
int main()
{
    int val = 20;
    std::cout << val << std::endl;
    std::cout << first::val << std::endl;
    
}