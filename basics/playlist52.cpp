#include <iostream>
#include <vector>


//this function takes in a vector and a function pointer
void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for(int value : values)
    {
        func(value);
    }
}

int main()
{
    std::vector<int> values = {1, 5, 4, 2, 3};


    //we are passing a vector and a lambda function
    ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });

    std::cin.get();
}