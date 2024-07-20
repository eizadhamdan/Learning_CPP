#include <iostream>
#include <thread>


static bool s_Finished = false;

void DoWork()
{

    using namespace std::literals::chrono_literals;

    std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;

    while(!s_Finished)
    {
        std::cout << "Working..." << std::endl;
        std::this_thread::sleep_for(1s);
        //if we don't add this sleep time it'll keep on printing to the console
        //and this will end up using 100% of the CPU for that thread
    }
}

int main()
{
    //thread takes in a function pointer
    std::thread worker(DoWork);

    std::cin.get();
    s_Finished = true;

    worker.join();
    //join() method makes one thread of execution wait for another thread to finish running.
    //(we still need mutex to protect shared resources)

    std::cout << "Finished" << std::endl;
    std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;


    std::cin.get();
}