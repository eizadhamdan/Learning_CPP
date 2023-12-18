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
    int a = 2;
    int* b = new int[50];

    Entity* e = new Entity();       //new keyword doesn't just allocate memory but it also calls the constructor
    //new is just an operator

    delete e;          //delete is also an operator
    //delete also calls the destructor

    delete[] b;

    Entity* e1 = new(b) Entity();           //this allocates memory at a specific memory address(only where we specify)

    delete e1;






    std::cin.get();
}