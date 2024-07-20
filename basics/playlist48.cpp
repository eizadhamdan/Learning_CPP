#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


auto GetName() -> std::string
{
    return "Eizad";
}

class Device {};

class DeviceManager
{
private:
    std::unordered_map<std::string, std::vector<Device*>> m_Devices;

public:
    const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
    {
        return m_Devices;
    }
};

int main()
{
    auto a = 5;
    auto b = a;

    std::cout << a << std::endl;
    
    auto name = GetName();
    int x = name.size();

    std::cout << "Name: " << name << " and size: " << x << std::endl;

    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");


    //using an iterator

    for(std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    //this for loop is the same as above, we just don't have to specify the type
    for(auto it = strings.begin(); it != strings.end(); it++)
    {
        std::cout << *it << std::endl;
    }


    DeviceManager dm;
    const auto& devices = dm.GetDevices();

    std::cin.get();
}