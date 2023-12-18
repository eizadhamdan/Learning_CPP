/*
Virtual function allow us to override methods in subclasses.
Virtual Functions introduce dynamic dispatch.
Compilers implement dynamic dispath via a VTables(or virtual tables).
Dynamic dispatch is the process of selecting which implementation of a polymorphic operation(method or function)
to call at run time.
A VTable is a table that contains the mapping of all the functions in our base class so that we can map them 
to the correct overriden function at run time.
*/

#include <iostream>
#include <string>


class Entity
{
public:
    virtual std::string GetName()           /*this instructs the compiler to generate a VTable for this function 
                                            so that when it's overriden it can point to the correct function*/
    {
        return "Entity";
    }
};

class Player : public Entity
{
private:
    std::string m_Name;

public:
    Player(const std::string& name)
        :m_Name(name) {}

    std::string GetName() override
    {
        return m_Name;
    }
};

void PrintName(Entity* entity)
{
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    Entity* e  = new Entity;
    PrintName(e);

    Player* p = new Player("Ghost");
    PrintName(p);


    std::cin.get();
}
