//aplicable from C++11 and later as rvalue references were introduced in C++11 

/*
Move semantics in C++


Move semantics allow us to move objects around.
There are many cases where we don't necessarily need to or want to copy objects from
one place to another, here we can use move semantics. 
*/

#include <iostream>
#include <string.h>
#include <stdio.h>


class String
{
public:
    String() = default;
    String(const char* string)
    {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    String(const String& other)
    {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    // this takes in an rvalue reference
    String(String&& other) noexcept      //this is a move constructor
    {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;          //here we are reassigning the pointer instead of allocating new memory

        //we have to do this because we are taking control of the object that was passed to us
        other.m_Size = 0;
        other.m_Data = nullptr;
        //this will leave behind a hollow object
    }   

    ~String()
    {
        printf("Destroyed\n");
        delete m_Data;
    }

    void Print()
    {
        for (uint32_t i = 0; i < m_Size; i++)
        {
            printf("%c", m_Data[i]);
        }
        printf("\n");
    }

private:
    char* m_Data;
    uint32_t m_Size;
};

class Entity
{
public:
    Entity(const String& name)
        : m_Name(name)
    {
    }

    Entity(String&& name)
        : m_Name((String&&)name)            //it's advisable to use std::move here instead of this
    {
    }

    void PrintName()
    {
        m_Name.Print();
    }

private:
    String m_Name;
};

int main()
{   
    Entity entity(String("Eizad"));
    entity.PrintName();


    std::cin.get();
}
