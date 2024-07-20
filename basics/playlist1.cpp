#include <iostream>

#define LOG(x) std::cout << x << std::endl;

int main()
{
    int var = 8;
    LOG(var);
    int* ptr = &var;                 //intialising a pointer(using & to get the memory location of var)
    *ptr = 10;                      //dereferencing the pointer(writing to the location where the pointer is pointing)
    LOG(var);
    LOG(ptr);

    //Here we get memory allocated to us from the stack.
    
    
    
    std::cin.get();                 //waiting for user to press enter to complete the execution of main
}