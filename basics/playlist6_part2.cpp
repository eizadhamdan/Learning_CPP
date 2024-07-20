#include <iostream>



static int s_Variable;             //the compiler looks for the variable in a different translation unit. his is called external linkage or external linking.


void Function()
{
    //we don't get a redefinition error because the Function is now declared static in the included file and the linker will not look for it anymore.

}


int main()
{
    std::cout << s_Variable << std::endl;
    std::cin.get();

}