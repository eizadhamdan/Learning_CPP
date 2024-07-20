#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>


int main()
{
    std::vector<int> values = {3, 5, 1, 4, 2};
    //std::sort(values.begin(), values.end(), std::greater<int>());
    std::sort(values.begin(), values.end(), [](int a, int b)
    {
        return a <= b;
    });


    for(int value : values)
    {
        std::cout << value << std::endl;
    }

    std::cin.get();
}