#include <iostream>
#include <string>


class Entity
{
public:
    virtual void PrintName()
    {

    }
};

class Player : public Entity
{
public:

};

class Enemy : public Entity
{
public:

};

int main()
{
    Player* player = new Player();
    Entity* actuallyPlayer = player;
    Entity* actuallyEnemy = new Enemy();

    Player* p0 = dynamic_cast<Player*>(actuallyEnemy);          //this cast should fail
   
    /*
    
    C++ knows whether our cast is valid or not by storing RTTI(Run-Time Type Information) about all of our types,
    this has some performance overhead(as types need to store more information about themselves)
    but this helps us in dynamic casting and dynamic casting takes more time as we have to perform 
    some validation as well to see if two types match or not.
    
    */

    Player* p1 = dynamic_cast<Player*>(actuallyPlayer);
    
    //for dynamic cast to actually work here entity class has to have virtual functions in it


    std::cin.get();
}