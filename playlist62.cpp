/*
A union is a user-defined datatype in which we can define members of different types of data types just like
structures. But one thing makes it different from structures is that the member variables in a union share
the same memory location, unlike a structure that allocates memory separately for each member variable. 
The size of the union is equal to the size of the largest data type.


Usually they are used for type punning.
*/

#include <iostream>


struct Vector2
{
    float x, y;
};

struct Vector4
{
    union
    {
        struct 
        {
            float x, y, z, w;
        };
        struct
        {
            Vector2 a, b;
        };
    };
};

void PrintVector2(const Vector2& vector)
{
    std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
    Vector4 vector = { 1.0f, 2.0f, 3.0f, 4.0f };
    PrintVector2(vector.a);
    PrintVector2(vector.b);
    vector.z = 500.0f;
    std::cout << "---------------------------" << std::endl;
    PrintVector2(vector.a);
    PrintVector2(vector.b);

    std::cin.get();
}