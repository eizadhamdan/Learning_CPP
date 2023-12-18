/*A constructor is a special type of method which runs everytime we instantiate an object*/

#include <iostream>


class Entity
{
    public:
        float X, Y;

        Entity()                        //the name of the constructor should match the name of the class.
        {
            X = 0.0f;
            Y = 0.0f;
        }                               //if we don't specify a constructor we'll still have a default constructor but that constructor doesn't do anything.

        Entity(float x, float y)        //we can create many constructors as long as they have different parameters
        {
            X = x;
            Y = y;
        }   

        void Print()
        {
            std::cout << X << ", " << Y << std::endl;
        }
};

class Log
{
    public:
        Log() = delete;             //this is will not allow us to create an instance

        static void Write()
        {

        }
};

int main()
{
    Log::Write();

    Entity e(10.0f, 5.0f);
    std::cout << e.X << std::endl;
    e.Print();

}