/*
L-Values and R-Values
*/

/*
Expressions that refer to memory locations are called l-value expressions. An l-value represents a 
storage region's "locator" value, or a "left" value, implying that it can appear on the left of the 
equal sign. L-values are often identifiers.

alternatively

An l-value refers to an onject that persists beyond a single expression.
*/
/*
An r-value is a temporary value that does not persist beyond the expression that uses it.
*/


#include <iostream>
#include <string>


//this function returns and l-value reference 
int& GetValue()
{
    static int value = 10;
    return value;
}

void SetValue(int value)
{}

void PrintName(std::string& name)
{
    std::cout << "[l-value]" << name << std::endl;
}

//this functions accepts an r-value reference
void PrintName(std::string&& name)
{
    std::cout << "[r-value]" << name << std::endl;
}

int main()
{
    int i = 10;
    SetValue(i);            //here we are calling the function with an l-value
    SetValue(10);           //in this case an r-value will be used to create an l-value when the function is called
    //we cannot take an l-value reference from an r-value


    const int& a = 10;      //const l-value references are allowed

    std::string firstName = "Eizad";
    std::string lastName = "Hamdan";

    std::string fullName = firstName + lastName;        
    // the expression on the right side of equals sign is an r-value 
    //(it is a temporary string that get's created at the time of assigment)
    //everything else on the left side of equals sign is an l-value

    PrintName(fullName);
    PrintName(firstName + lastName);

    GetValue() = 5;
}