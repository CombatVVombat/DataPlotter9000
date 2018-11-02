#include "world.hpp"

cWorld::cWorld()
{
    entityManager = std::make_unique<cEntityManager>();
}

cEntityHandle cWorld::createEntity()
{
    cEntityHandle handle(entityManager->createEntity(), this);
    return handle;
}

