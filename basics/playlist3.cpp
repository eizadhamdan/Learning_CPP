#include <iostream>


#define LOG(x) std::cout << x << std::endl;

void increment(int& value);
void increase(int* value);

int main()
{
    int a = 5;

    int& ref = a;       //this ref variable is kind of an alias, it doesn't really exist

    //however we can use ref as if it were the variable a
    

    ref = 2;        //this will actually assign a to be 2

    LOG(a);

    increment(ref);

    LOG(ref);
    LOG(a);


    int x = 7;
    increase(&x);
    LOG(x);

    /*
    BTW both the functions increment and increase that we've defined here do the same thing, it's just a syntax difference 
    */


}

void increment(int& value)          //we are passing the variable by reference and not just a copy of it
{
    value += 1;

}

void increase(int* value)
{
    (*value) += 1;          //the order of operations is important here.

    /*
    We first want to dereference the variable or say go to its memory address and get the value at that address and then increase it by 1.
    Failing to use the brackets we will just be increasing the value of the memory address by 1 and not the variable therein. 
    */
}