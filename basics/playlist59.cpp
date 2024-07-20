#include <iostream>


int main()
{
    //for allocation of memory of 2D array on heap, we need to have a pointer to pointer
    //we have a pointer to an integer pointer
    int** a2d = new int*[50];           //we have allocated memory for 50 integer pointers

    for(int i = 0; i < 50; i++)
    {
        a2d[i] = new int[50];       //here we are allocating 50 different arrays
    }

    a2d[0][0] = 0;      //accessing an element


    //to delete this allocated memory
    for(int i = 0; i < 50; i++)
    {
        delete[] a2d[i];
    }
    delete[] a2d;



    //for a 3 dimensional array
    int*** a3d = new int**[50];

    for(int i = 0; i < 50; i++)
    {
        a3d[i] = new int*[50];
        for(int j = 0; j < 50; j++)
        {
            int** ptr = a3d[i];
            ptr[j] = new int[50];
        }
    }



    /*
    Allocating memory this way results in memory fragmentation. Iterating through such an array will be slow
    as we have to go to many different places in memory to fetch the data as memory on heap is allocated randomly,
    there is no guarantee that the arrays allocated to us are close together in memory, they might be close or
    they might be far apart.
    
    This might result in a cache miss, that means we are wasting time to fetch that data from our RAM, it might not
    be a cache miss if the memory allocated for the arrays are close to each other.

    For a good program we need to allocate memory in such a way that while fetching data it results in more
    cache hits rather than cache misses as it will slow down our program.
    */


    std::cin.get();
}