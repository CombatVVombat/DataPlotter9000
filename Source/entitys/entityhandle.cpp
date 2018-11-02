#include "entityhandle.hpp"

cEntityHandle::cEntityHandle(const cEntity& entity, cWorld* world)
    :   entity(entity), world(world)
{
}

const cEntity& cEntityHandle::getEntity() const
{
    return entity;
}
