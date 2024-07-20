#include <iostream>
#include <array>

int main()
{
    std::array<int, 5> data;
    data[0] = 1;
    data[1] = 4;

    /*
    Advantage of using std_array is that we don't have to separately allocate a variable to keep track of 
    its size, we can use the inbuilt method to get the size of this array.

    They are stored on the stack unlike std_vector which is stored on the heap and std_array works the
    same as way as a normal C-style array does.
    */
   std::cout << data.size();


    std::cin.get();
}