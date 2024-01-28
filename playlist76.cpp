/*
Tracking memory allocations
*/
#include <iostream>
#include <memory>


struct AllocationMetrics
{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage()
    {
        return TotalAllocated - TotalFreed;
    }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size)
{
    s_AllocationMetrics.TotalAllocated += size;

    return malloc(size);
}

void operator delete(void* memory, size_t size)
{
    s_AllocationMetrics.TotalFreed += size;

    free(memory);
}

struct Object
{
    int x, y, z;
};

static void PrintMemoryUsage()
{
    std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes" << std::endl;
}

int main()
{
    PrintMemoryUsage();
    Object* obj = new Object();
    PrintMemoryUsage();
    {
        std::unique_ptr<Object> obj1 = std::make_unique<Object>();
        PrintMemoryUsage();
    }
    PrintMemoryUsage();
}

/*
Alternatively, we can use Visual Studio's builtin memory allocation tracking profile tools to do this work
for us, Valgrind also has tools to do this work for us. They can be useful in some situations and tracking
memory usage this way can also be useful in some situations.
*/