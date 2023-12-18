/*A destructor runs when we destroy an object*/

#include <iostream>



class Entity
{
    public:
        float X, Y;

        Entity()
        {
            X = 0.0f;
            Y = 0.0f;
            std::cout << "Created Entity!" << std::endl;
        }

        ~Entity()                       //the name of a destructor always starts with a tilde(~) and them the name of our class
        {
            std::cout <<"Destroyed Entity!" << std::endl;
        }

        void Print()
        {
            std::cout << X << ", " << Y << std::endl;
        }
};

void Function()
{
    Entity e;
    e.Print();

    e.~Entity();        //we can manually call the destructor but it's not common practice to do so(this is not recommended)
}

int main()
{
    Function();
    std::cin.get();
}