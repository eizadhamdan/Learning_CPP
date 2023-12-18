#include <iostream>


class Singleton         //a singleton class is a class that should only have one instance in existence
{
private:
    static Singleton* s_Instance;
public:
    static Singleton& Get() { return *s_Instance; }

    void exampleFunction() {}
};

Singleton* Singleton::s_Instance = nullptr;             //declaring our instance


//alternative syntax for singleton class

class Singleton2
{
public:
    static Singleton2& Get()
    {
        static Singleton2 instance;
        return instance;
    }

    void exampleFunction() {}

    //we get the exact same behaviour as the Singleton class and we don't even need an external declaration
};


void Function()
{
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}

int main()
{
    Singleton::Get().exampleFunction();





    for(int j = 0; j < 5; j++)
    {
        Function();
    }

    std::cin.get();
}