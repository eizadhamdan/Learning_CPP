#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;
public:
    Entity() : m_Name("Unknown") {}
    Entity(const String& name) : m_Name(name) {}

    const String& GetName() const { return m_Name; }
};

int main()
{
    Entity* e;
    {
        Entity* entity = new Entity("Player");
        e = entity;                     //we don't need an ampersand here because entity is already a pointer
        std::cout << entity->GetName() << std::endl;            //we can either use the arrow operator or dereference entity then call GetName()
    }
    delete e;
    std::cin.get();
}

/*create an object on the heap memory*/
/*
There is a performance overhead for allocating memory on the heap.
Allocating on the heap takes longer than allocating on the stack.
*/
/*
We are responsible for the memory allocated to us on the heap in contrast to how it is done on the stack.
We have to free that memory which was allocated to us after we are done using it.
*/