#include <iostream>


class Entity 
{
public:
    float X, Y;


    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }
};

class Player : public Entity                //this class inherits all the properties of class Entity and also has functionality of its own 
{
public:
    const char* Name;

    void PrintName()
    {
        std::cout << Name << std::endl;
    }
};

int main()
{
    std::cout << sizeof(Entity) << std:: endl;
    std::cout << sizeof(Player) << std::endl;

    Player player;      //it has inherited all the functionality of Entity class(only the public ones)
    //player.X = 2;
    //player.Move(5, 5);
    //player.PrintName();

    std::cin.get();

}