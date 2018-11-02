#include "entitymanager.hpp"

entityIdType cEntityManager::lastIdCreated = 0;

cEntity cEntityManager::createEntity()
{
    cEntity entity = ++lastIdCreated;
    #ifdef DEBUG
        std::cout << "cEntityManager: Created entity: " << entity << "\n";
    #endif // DEBUG
    return entity;
}
