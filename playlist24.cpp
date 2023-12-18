#include <iostream>
#include <string>

class Example
{
public:
    Example()
    {
        std::cout << "Created Entity!" << std::endl;
    }
    Example(int x)
    {
        std::cout << "Created Entity with " << x << "!" << std::endl;
    }
};
class Entity
{
private:
    std::string m_Name;
    int m_Score;
    Example m_Example;
public:
    Entity()
        :m_Name("Unknown"), m_Score(0), m_Example(8)          //this is a member initializer list
    {
    }
    
    /*
    It is advisable to write the initiliazer list in the order in which the member variables are declared
    (some compilers might even warn us if we don't do so)
    (The list will be initialized in the order the class members are defined in)
    */
    
    Entity(const std::string& name)
        :m_Name(name)
    {
    }
    const std::string & GetName() const
    {
        return m_Name;
    }
};

int main()
{
    Entity e0;
    std::cout << e0.GetName() << std::endl;
    Entity e1("Eizad");
    std::cout << e1.GetName() << std::endl;

    std::cin.get();
}