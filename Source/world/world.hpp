#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED

#include <memory>
#include "../components/componentmanagerbase.hpp"
#include "../entitys/entityhandle.hpp"
#include "../entitys/entitymanager.hpp"
#include "../processors/processorbase.hpp"

class cWorld
{
public:
private:
    std::unique_ptr<cEntityManager> entityManager;
    std::vector<cComponentManagerBase*> componentManagers;
    //std::vector<cProcessorBase*> processors;

public:
    cWorld();
    cEntityHandle createEntity();
private:
};


#endif // WORLD_HPP_INCLUDED
