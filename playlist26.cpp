#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;
public:
    Entity() : m_Name("Unknown") {}                         //this is the default constructor
    Entity(const String& name) : m_Name(name) {}

    const String& GetName() const { return m_Name; }
};

int main()
{
    Entity* e;
    {
        Entity entity("Player");                    //memory for entity is allocated on the stack
        e = &entity;
        std::cout << entity.GetName() << std::endl;
    }                                                   //entity will be destroyed once the scope ends
    std::cin.get();
}
/*
the stack is usually quite small in size
depending on the platform and the compiler, the stack could be around 1 or 2 MB
so if we have a lot of objects that need to be instantiated then there's a chance we might run out of stack memory
*/
