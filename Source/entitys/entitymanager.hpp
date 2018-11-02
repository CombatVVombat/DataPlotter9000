#ifndef ENTITYMANAGER_HPP_INCLUDED
#define ENTITYMANAGER_HPP_INCLUDED

#include <iostream>
#include "entity.hpp"

class cEntityManager
{
public:
private:
    static entityIdType lastIdCreated;

public:
    cEntity createEntity();
private:
};



#endif // ENTITYMANAGER_HPP_INCLUDED
