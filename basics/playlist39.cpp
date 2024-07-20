#include <iostream>
#include <string>

class Entity
{
public:
    int x;
public:
    void Print() const
    {
        std::cout << "Hello" << std::endl;
    }
};

class ScopedPtr
{
private:
    Entity m_Obj;
public:
    // ScopedPtr(Entity* entity)
    //     : m_Obj(entity)
    // {
    // }

    // ~ScopedPtr()
    // {
    //     delete m_Obj;
    // }

    // const Entity* operator->() const
    // {
    //     return m_Obj;
    // }
};

int main()
{
    /*
    Entity e;
    e.Print();

    Entity* ptr = &e;

    ptr->x = 2;
    */
    // const ScopedPtr entity = new Entity();
    // entity->Print();


    std::cin.get();
}