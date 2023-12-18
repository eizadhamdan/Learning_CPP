#include <iostream>

struct entity
{
    static int x, y;

    void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int entity::x;
int entity::y;

int main()
{
    entity e;

    e.x = 2;
    e.y = 3;

    /*
    entity e2 = {5, 8};         //here we are initializing another instance of entity
    the initializer fails because we are now using static variables
    */

    
    entity e2;
    /*
    e2.x = 5;
    e2.y = 8;
    */
    //we don't need to refer to entity in this way

    entity::x = 5;          //this is like a global variable
    entity::y = 8;          //this is like a global variable
    e2.Print();
    e.Print();


    std::cin.get();
}