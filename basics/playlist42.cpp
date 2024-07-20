/*optimizing the usage of STL vector*/

/*
Dynamic arrays work by allocating some extra amount of memory intially and when that memory gets used up,
it allocates new contiguous memory with some extra space for new elements to be added and then copies the elements
to these contiguous memory locations and now new elements can be added.

The problemwith this is that this reallocation takes place quite often which slows down the program
and to deal with this we implement our own version of dynamic array.
*/

#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }
    
    //to check how many times copying and reallocation takes place we need to add a copy constructor
    // and see how many times it gets called.

    Vertex(const Vertex& vertex)
        : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        std::cout << "Copied!" << std::endl;
    } 
};

int main()
{
    std::vector<Vertex> vertices;

    vertices.reserve(3);            
    //we tell the compiler to have the capacity of 3 vectors from the start so it doesn't have to reallocate that often 
    //cause we know that we'll be pushing in three vectors. this will optimize our code a little bit.

    vertices.push_back({ 1, 2, 3 });
    vertices.push_back({ 4, 5, 6 });

    //we are using emplace_back instead of push_back because when we use push_back it creates an object in the 
    //main function's memory and then copies it into the memory that has been allocated for the vector
    //by using emplace_back we avoid this copying and directly create an object by calling the constructor and
    //placing the object in the memory of the vector 
    vertices.emplace_back(7, 8, 9);


    std::cin.get();
}