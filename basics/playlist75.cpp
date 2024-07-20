/*
Small String Optimization


C++ standard library has a builtin way to optimize strings as allocating memory for strings
slows down our program as most of the time memory is allocated on the heap and it is slow.
So, depending on our version of C++ the standard library doesn't allocate memory for small strings.
(small strings is decided based on how many characters they have and if the number of characters is less than
a decided certain number of characters, the string is stored on stack)

In C++14, a string is considered small if it is maximum 15 characters long. 
*/
#include <iostream>
#include <string>


void* operator new(size_t size)
{
    std::cout << "Allocating " << size << " bytes" <<std::endl;
    return malloc(size);
}

int main()
{
    //this is stored in a statically allocated buffer on the stack and not on the heap cause it's a small string
    std::string name = "Eizad";
    
    std::string text = "My name is Eizad Hamdan.";

    std::cin.get();
}