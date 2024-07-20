/*
A singleton is a single instance of a class that we have in our program.
*/

#include <iostream>


class Singleton
{
public:
    Singleton(const Singleton&) = delete;

    static Singleton& Get()
    {
        return s_Instance;
    }

    void Function() {}

private:
    Singleton() {}          
    //we are making this constructor private so that this class cannot be instatiated from somewhere else

    static Singleton s_Instance;
};

Singleton Singleton::s_Instance;

int main()
{
    Singleton::Get().Function();            //we can call Function on Get as if it were an object 


    std::cin.get();
}
