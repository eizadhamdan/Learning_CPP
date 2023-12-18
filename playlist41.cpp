#include <iostream>
#include <vector>
#include <string>

struct Vertex
{
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream; 
}

int main()
{
    std::vector<Vertex> vertices;

    //to add elements to a vector use push_back() method

    vertices.push_back({1, 2, 3});
    vertices.push_back({4, 5, 6});

    for(int i = 0; i < vertices.size(); i++)
    {
        std::cout << vertices[i] << std::endl;
        //we can use index operator for vectors unlike java 
        //cause C++ by default has overloaded the index operator for vectors
    }

    //same loop as above but alternative syntax
    for(Vertex& v : vertices)
    {
        std::cout << v << std::endl;
    }

    //to erase an element
    vertices.erase(vertices.begin() + 1);           //erase()  method takes in an iterator
    //we have deleted the second element of the vector

    //always pass vectors into functions by reference and not by value

    //to clear the dynamic array of vertices
    vertices.clear();


    std::cin.get();
}