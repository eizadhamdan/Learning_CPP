#include <iostream>
#include <array>            //to use cpp std array


class Entity
{
public:
    int* example = new int [5];

    static constexpr int size = 5;          //or static const int size = 5;
    int example1[size];             //to allocate memory for array on stack  the size has to be known while compilation(however there are ways around it)

    std::array<int, 5> anotherArray;        //creating a cpp standard array



    Entity()
    {
        int a[5];
        int bytes = sizeof(a);      //this gives size of array a

        int bytes1 = sizeof(example);       //this gives size of pointer


        for(int i = 0; i < 5; i++)
        {
            example[i] = 2;
        }

        for(int i = 0; i < anotherArray.size(); i++)
        {
            anotherArray[i] = 3;
        }
    }
    
};

int main()
{
    Entity e;



    std::cin.get();
}
