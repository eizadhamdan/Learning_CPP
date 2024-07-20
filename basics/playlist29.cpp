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

    Entity(int age)
        :m_Name("Unknown"), m_Age(age) {}
};

int main()
{
    Entity a = Entity("Eizad");         
    //conversion won't work here because it's not an std::string rather it is a const char[]
    /*
    C++ is only allowed to do one implicit conversion 
    so for implicit conversion we'd first have to convert it into an std::string then into an Entity
    */
    Entity a1 = (std::string("Eizad"));
    
    Entity b = 20;             //this is implicit conversion



    std::cin.get();
}