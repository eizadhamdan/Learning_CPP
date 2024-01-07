#include <iostream>
#include <chrono>
#include <thread>


int main()
{
    using namespace std::literals::chrono_literals;


    auto start = std::chrono::high_resolution_clock::now();
    //this is used to get the current time

    std::this_thread::sleep_for(1s);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;
    std::cout << duration.count() << " s" << std::endl;

    std::cin.get();
}

/*
For very high resolution timing, we might want to use platform specific library or the query performance counter.
This might be useful if we are writing code for a game engine or a library for a specific platform and we need the performance.
*/