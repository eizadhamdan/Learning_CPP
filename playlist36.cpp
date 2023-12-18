#include <iostream>
#include <string>
#include <memory>

class Entity
{
public:
    Entity()
    {
        std::cout << "Created entity" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destroyed entity" << std::endl;
    }

    void Print() {}
};

int main()
{
    {
        std::shared_ptr<Entity> e0;
        {
            std::unique_ptr<Entity> entity = std::make_unique<Entity>();      
            //this is recommended because of exception safety

            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            //shared pointer allocates a block of memory(called "Control Block") where it stores reference counts
            
            std::weak_ptr<Entity> weakEntity = sharedEntity;
            //almost the same as shared pointer but it doesn't increase the ref count

            e0 = sharedEntity;

            entity->Print();
        }
    }

    std::cin.get();
}