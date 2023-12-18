/*
"Operators and operator overloading"

overloading essentially means giving a new meaning to an already existing operator.
We can change or define the behaviour of an operator in our program.
*/

#include <iostream>
#include <string>

struct Vector2
{
    float x, y;

    Vector2(float x, float y)
        : x(x), y(y) {}

    Vector2 Add(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 Multiply(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }
};


int main()
{

    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);

    Vector2 result = position.Add(speed.Multiply(powerup));

    std::cout << result.x << ", " << result.y << std::endl;


    std::cin.get();
}

//if we don't use the existing operators to add or multiply our struct members then we'd have to define methods to perform each of these arithmetic operations.

/*The next code is an improvement for this code and a justification for why we need opoerator overloading.*/