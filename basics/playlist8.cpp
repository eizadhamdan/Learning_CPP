#include <iostream>


enum Example : char            //specifying the type to be char
{
    A = 0, B = 2, C = 6
};

int a = 0;
int b = 1;
int c = 2;

int main()
{
    //enum stands for enumeration. enums are just integers
    //enums are by default 32-bit integers but we can also speify their type if needed

    Example value = B;

    if(value == 1)
    {
        //some code that does something
    }


    std::cin.get();

    return 0;
}