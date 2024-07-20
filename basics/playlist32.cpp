
#include <iostream>
#include <string>

struct Vector2
{
    float x, y;

    Vector2(float x, float y)
        : x(x), y(y) {}

    Vector2 operator+ (const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);           //we can also define an add function and call it for the return value
    }

    Vector2 operator* (const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);           //we can also define a multiply function and call it for return value
    }

    bool operator== (const  Vector2& other) const               //operator overload for test of equality
    {
        return x == other.x && y == other.y;
    }
    
    bool operator!= (const  Vector2& other) const               //operator overload for test of inequality
    {
        return !(*this == other);
    }
};

//we're overloading the original defintion of << in ostream
std::ostream& operator<< (std::ostream& stream, const Vector2& other)
{
    stream << other.x << ", " << other.y;           //ostream already knows how to print a float so we have to define it in terms of a built-in data type
    return stream;                          //we then need to return a reference to the stream           
}

int main()
{
    
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);

    Vector2 result = position + speed * powerup;

    if(position == speed)
    {
        std::cout << "They are equal." << std::endl;
    }
    if(position != powerup)
    {
        std::cout << "They are unequal." << std::endl;
    }


    //we need to define an overload for the put to operator.
    std::cout << result << std::endl;


    std::cin.get();
}