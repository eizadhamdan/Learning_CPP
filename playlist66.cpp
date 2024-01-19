/*
Benchmarking in C++

(Measuring the performance of our code)
*/

#include <iostream>
#include <memory>
#include <chrono>
#include <array>


class Timer
{
public:
    Timer()
    {
        m_StartTimepoint = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        Stop();
    }

    void Stop()
    {
        auto endTimepoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
    
        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << "Duration in microseconds: " << duration << std::endl;
        std::cout << "Duration in milliseconds: " << ms << std::endl;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
};

int main()
{
    struct Vector2
    {
        float x, y;
    };

    std::cout << "Make shared" << std::endl;
    {
        Timer timer0;
        std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
        for(int i = 0; i < sharedPtrs.size(); i++)
        {
            sharedPtrs[i] = std::make_shared<Vector2>();
        }
    }

    std::cout << "New shared" << std::endl;
    {
        Timer timer1;
        std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
        for(int i = 0; i < sharedPtrs.size(); i++)
        {
            sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
        }
    }

    std::cout << "Make unique" << std::endl;
    {
        Timer timer2;
        std::array<std::unique_ptr<Vector2>, 1000> uniquePtrs;
        for(int i = 0; i < uniquePtrs.size(); i++)
        {
            uniquePtrs[i] = std::make_unique<Vector2>();
        }
    }

    return 0;
}