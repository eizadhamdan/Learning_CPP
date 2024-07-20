#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>


void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{
    for(int value : values)
    {
        func(value);
    }
}

int main()
{
    std::vector<int> values = {1, 5, 4, 2, 3};

    //find_if takes in an iterator that's why we're 
    //using begin and end method and some kind of expression has to be passed as well
    auto iter = std::find_if(values.begin(), values.end(), [](int value){ return value > 3; });

    std::cout << *iter << std::endl;

    auto lambda = [=](int value) { std::cout << "Value: " << value << std::endl; };
    /*
    [] these are called captures.

    [=] to pass by value
    [&] to pass by reference
    [a, &b] we can specify the variables we want our lambda function to capture

    The return type of a lambda function is deduced from return statements as if for a function
    whose return type is declared "auto".
    */

    ForEach(values, lambda);

    std::cin.get();
}