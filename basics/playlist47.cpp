#include <iostream>
#include <string>


#define PR_DEBUG 1

#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x) std::cout << "Other Version" << std::endl
#endif



#define WAIT std::cin.get()

int main()
{
    LOG("Hello");

    WAIT;
}