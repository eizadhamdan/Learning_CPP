#include <iostream>
#include <string>


class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destroyed Entity" << std::endl;
    }
};

class ScopedPtr         //this is like a basic smart pointer
{
private:
    Entity* m_ptr;

public:
    ScopedPtr(Entity* ptr)
        :m_ptr(ptr)
    {
    }
    ~ScopedPtr()
    {
        delete m_ptr;
    }

};

int main()
{

    {
        ScopedPtr e = new Entity();         //this will free memory which was allocated on the heap once the scope ends
    }





    std::cin.get();
}