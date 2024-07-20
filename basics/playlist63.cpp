#include <iostream>


class Base
{
public:
    Base()
    {
        std::cout << "Base Constructor" << std::endl;
    }
    virtual ~Base()
    {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        m_Array = new int[5];
        std::cout << "Derived Constructor" << std::endl;
    }
    ~Derived()
    {
        delete[] m_Array;
        std::cout << "Derived Destructor" << std::endl;
    }
private:
    int* m_Array;
};

int main()
{
    Base* base = new Base();
    delete base;

    std::cout << "---------------------------------" << std::endl;

    Derived* derived = new Derived();
    delete derived;

    std::cout << "---------------------------------" << std::endl;

    Base* poly = new Derived();
    delete poly;            //this will cause a memeory leak if the base class destructor is not marked virtual
    //marking the base class destructor as virtual instructs the compiler to look for a 
    //derived class destructor and call it before calling the base class destructor.
    
    std::cin.get();
}