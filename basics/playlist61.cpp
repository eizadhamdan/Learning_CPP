/*
Type punning is a programming technique that subverts or circumvents the type system of a 
programming language in order to achieve an effect that would be difficult or impossible to achieve
within the bounds of the formal language.
*/
#include <iostream>


struct Entity
{
    int x, y;
};

int main()
{
    /*
    The commented out code below is an example of bad type punning.
    Programming style like this is dangerous and might cause our program to crash.
    */
    //int a = 50;
    //double value = *(double*)&a;            //type punning an integer into a double
    //std::cout << value << std::endl;

    Entity e = {5, 8};
    int* position = (int*)&e;
    //we are addressing our struct as if it is an array
    std::cout << position[0] << ", " << position[1] << std::endl;

    int y = *(int*)((char*)&e + 4);     //to access y in our struct
    //we first reference e than cast it to a char pointer then move 4 bytes ahead in memory then 
    //cast it to an int pointer then dereference it.

    std::cout << y << std::endl;

    std::cin.get();
}