#include <iostream>
#include <string>


struct Vector3
{
    float x, y, z;

    Vector3()
        : x(10), y(11), z(12) {}
};

int main()
{
    int value = 5;          //allocating on stack
    int array[5] = {1, 2, 3, 4, 5};
    Vector3 vector;

    /*
    Allocation on stack for different values is done close to each other. When we want to allocate memory for an int
    the stack pointer just moves 4 bytes and then when we want to allocate memory  for another variable the stack pointer
    will move accordingly, it won't allocate memory at a random memory location and when we allocate memory for a struct
    the stack pointer moves accordingly for the structure padding and then for the data types according to the requirement.

    Stack grows from higher memory address to lower memory address.
    */



    int* hvalue = new int;          //allocating on heap
    *hvalue = 5;
    int* harray = new int[5];
    harray[0] = 1;
    harray[1] = 2;
    harray[2] = 3;
    harray[3] = 4;
    harray[4] = 5;
    
    Vector3* hvector = new Vector3();
    

    //heap allocation is very random, so our variables will be quite far away from each other in memory


    //since we are allocating on the heap using new keyword we have to free that memeory 
    //(if we had used smart pointers it would've done that for us)

    delete hvalue;
    delete[] harray;
    delete hvector;

    std::cin.get();
}
