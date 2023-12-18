#include <iostream>
#include <string>
#include <cstring>

class String
{
private:
    char *m_Buffer;
    unsigned int m_Size;

public:
    String(const char *string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size); // function to copy a string instead of using a for loop
        m_Buffer[m_Size] = 0;             // we're guaranteeing that our string is null terminated
    }

    // the copy constructor
    // this is the signature of a copy constructor
    String(const String &other)
        : m_Buffer(other.m_Buffer), m_Size(other.m_Size)
    {
        /*
        Alternative syntax for copy constructor-

        memcpy(this, &other, sizeof(String));

        */
    }

    /*
        If we don't wanna allow copy constructor;

        //declare the copy constructor as delete

        String(const String& other) = delete;
    */

    ~String()
    {
        delete[] m_Buffer;
    }

    char &operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    friend std::ostream &operator<<(std::ostream &stream, const String &string);
};

// writing an overload for operator to print our string
std::ostream &operator<<(std::ostream &stream, const String &string)
{
    stream << string.m_Buffer; // since this is a friend function we can access a private member
    return stream;
}

int main()
{
    // a deep copy copies an object in its entirety
    // we perform a deep copy by using a copy constructor

    String string = "Eizad";
    String second = string;

    second[2] = 'x';

    std::cout << string << std::endl;
    std::cout << second << std::endl;

    std::cin.get();
}