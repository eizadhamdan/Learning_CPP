#include <iostream>


int main()
{
    int example[5];
    int* ptr = example;

    for(int i = 0; i < 5; i++)
    {
        example[i] = 2;
    }

    
    example[2] = 5;
    *(ptr + 2) = 6;             //to deal with single byte we'd have to type cast the pointer to a data type that is of one byte


    /*creating arrays on heap*/

    int* another = new int[5];
    
    for(int i = 0; i < 5; i++)
    {
        another[i] = 3;
    }
    delete[] another;           //we have to destroy the array manually because it doesn't get destroyed once the program ends



    std::cin.get();
}