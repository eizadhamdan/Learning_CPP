#include <iostream>
#include <cstring>          //including this for memset function

#define LOG(x) std::cin << x << std::endl;


int main()
{
    char* buffer = new char[8];         //this allocates us 8 bytes of memory and returns a pointer to the beginning of that block of memory
    memset(buffer, 0, 8);   //fills in data at a memory which we specify
    //memset takes in a pointer to the beginning of the block of memory, a value and how many bytes should it fill.

    char** ptr = &buffer;       //double pointer i.e. a pointer to another pointer

    delete[] buffer;






    //Here we get memory allocated to us from the heap


    std::cin.get();
}