/*
Benchmarking in C++

(Measuring the performance of our code)
*/

#include <iostream>
#include <memory>
#include <chrono>

class Timer
{
public:
    Timer()
    {
        m_StartTimepoint = std::chrono::high_resolution_clock::now();          //this gets the current time
    }
    ~Timer()
    {
        Stop();
    }
    /*
        We want the timer to be scope-based(to be tied to the lifetime of the object).
        When an instance of Timer class is created we want to start the timer and when it is destroyed
        we want to stop the timer.
        This is called RAII(Resource Acquisition Is Initialization).
        RAII is a programming technique which binds the lifecycle of a resource that must be acquired before
        use to the lifetime of an object.
    */

    void Stop()
    {
        auto endTimepoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
    
        auto duration = end - start;
        double ms = duration * 0.001;       //to get it in milliseconds

        std::cout << "Duration in microseconds: " << duration << std::endl;
        std::cout << "Duration in milliseconds: " << ms << std::endl;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
};

int main()
{
    int value = 0;
    {
        Timer timer;
        for(int i = 0; i < 100000; i++)
        {
            value += 2;
        }

        std::cout << value << std::endl;
    }
    return 0;
}