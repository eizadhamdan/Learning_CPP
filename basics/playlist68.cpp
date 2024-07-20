/*
Dealing with ooptional data
(Since C++17)
*/

#include <iostream>
#include <string>
#include <fstream>
#include <optional>


std::optional<std::string> ReadFileAsString(const std::string& filepath)
{
    std::ifstream stream(filepath);

    if(stream)
    {
        std::string result;
        //read file here
        stream.close();
        return result;
    }

    return {};
} 

int main()
{
    std::optional<std::string> data = ReadFileAsString("data.txt");            //example of a file that is to be read
    
    std::string value = data.value_or("Not present");               //if the file couldn't be read
    std::cout << value << std::endl;
    
    if(data.has_value())
    {
        std::cout << "File read successfully!" << std::endl; 
    }
    else
    {
        std::cout << "File could not be opened!" << std::endl;
    }


    std::cin.get();
}