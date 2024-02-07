/*
Argument evaluation order in C++
*/

#include <iostream>

void PrintSum(int a, int b)
{
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
}

int main()
{
    int value = 0;
    
    //this has an undefined behaviour
    PrintSum(value++, value++);
    PrintSum(++value, ++value);
    /*
    The C++ standard does not define what should happen in this situation.
    It will vary from compiler to compiler on the actual implementation of the C++ compiler
    which has to translate this code into machine code.
    */


    std::cin.get();
}