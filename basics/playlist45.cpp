#include <iostream>
#include <string>


//Implementing an array class using template just like in STL.
template<typename T,int N>
class Array
{
private:
    T m_Array[N];
public:
    T GetSize() const { return N; }
};

int main()
{
    Array<int, 5> array;
    std::cout << array.GetSize() << std::endl;

    std::cin.get();
}