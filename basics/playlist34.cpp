#include <iostream>
#include <string>

/*
Every time we enter a scope in C++ we push a stack frame on.
*/

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destroyed Entity" << std::endl;
    }
};

int* CreateArray()      //this code will fail if we allocate memory for array on the stack and not on the heap
{
    int* array = new int[50];
    return array;
}

int main()
{

    {
        Entity e;
    }       //a stack variable gets destroyed the moment we go out of scope(unlike heap)





    std::cin.get();
}