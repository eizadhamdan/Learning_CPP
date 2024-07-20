#include <iostream>
#include <string>


class Entity
{
private:
    int m_X, m_Y;
    mutable int var;            //if we really need to modify a variable
public:
    int GetX() const            //this method can't modify any class member variables
    {
        var = 2;                //this method can now modify var because it's declared to be mutable
        return m_X;
    }
    void SetX(int x)
    {
        m_X = x;
    }
};

void PrintEntity(const Entity& e)
{
    std::cout << e.GetX() << std::endl;
}

int main()
{
    Entity e;


    const int MAX_AGE = 90;

    int* a = new int;

    *a = 2;
    a = (int*)&MAX_AGE;             //this is not recommended

    std::cout << *a << std::endl;

    std::cin.get();
}