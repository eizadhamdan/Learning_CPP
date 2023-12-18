#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    mutable int m_DebugCount  = 0;              //we're allowing the getter to modify this variable by declaring it to be mutable
public:
    const std::string& GetName() const
    {
        m_DebugCount++;
        return m_Name;
    }
};

int main()
{
    const Entity e;
    e.GetName();

    int x = 8;
    auto f = [=]() mutable               
    {
        x++;        
        std::cout << x << std::endl;
    };

    f();
    //x will still be equal to 8, it'll not be modified

    std::cin.get();
}