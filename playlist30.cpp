#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string& name)
        :m_Name(name), m_Age(-1) {}

    explicit Entity(int age)
        :m_Name("Unknown"), m_Age(age) {}
};
/*
explicit keyword disables the implicit conversion functionality.

we put the explicit keyword in front of a constructor.
*/
int main()
{
    Entity a = (std::string("Eizad"));
    Entity b = (Entity)20;              //or we can write Entity b = Entity(20)
    


    std::cin.get();
}