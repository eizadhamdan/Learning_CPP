#include <iostream>


class Random
{
public:
    Random(const Random&) = delete;

    static Random& Get()
    {   
        static Random instance;
        return instance;
    }

    static float Float()
    {
        return Get().IFloat();
    }

private:
    Random() {}

    float IFloat()
    {
        return m_RandomGenerator;
    }

    float m_RandomGenerator = 0.5f;

};

namespace RandomClass {
    static float s_RandomGenerator = 0.5f;
    
    static float Float() 
    {
        return s_RandomGenerator;
    }
}

int main()
{
    float number = Random::Float();
    float number1 = RandomClass::Float();

    std::cout << number << std::endl;
    std::cout << number1 << std::endl;


    std::cin.get();
}
