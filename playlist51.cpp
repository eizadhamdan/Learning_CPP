#include <iostream>

void PrintValue(int value);
void HelloWorld();
int main()
{
    /*
    Function pointers are essentially used to assign a function to a variable.
    */

    auto function = HelloWorld;
    //here we have a function pointer(notice that there are no parentheses)
    //we are getting the memeory address of this function


    function();
    //we can call our function like this now.   


    /*
    void(*function)()
    
    this is the type of the variable in which our function pointer is stored.
    */


    // it's better to use typedef than to use auto keyword
    typedef void(*printFunction)(int);

    printFunction func1 = PrintValue;

    func1(8);
    func1(5);

    std::cin.get();
}

// a simple function for demonstration 
void HelloWorld()
{
    std::cout << "Hello World" << std::endl;
}

void PrintValue(int value)
{
    std::cout << "Value of the variable is " << value << std::endl;
}