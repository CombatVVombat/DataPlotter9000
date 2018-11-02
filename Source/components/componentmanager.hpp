#ifndef COMPONENTMANAGER_HPP_INCLUDED
#define COMPONENTMANAGER_HPP_INCLUDED

#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include "component.hpp"
#include "componenthandle.hpp"
#include "componentmanagerbase.hpp"
#include "../entitys/entityhandle.hpp"

/// Holds the components in contiguous memory
/// Allows lookup of the components by entityID (the entity they are attached to)

template <typename componentType>
class cComponentManager : public cComponentManagerBase
{
public:
private:
    uint32_t family;
    std::unordered_map<cEntity, size_t> indexMap;
    std::vector<componentType> components;

public:
    cComponentManager<componentType>();
    ~cComponentManager<componentType>();
    cComponentHandle<componentType> addComponent(const cEntityHandle& entityHandle, const componentType& component);
    cComponentHandle<componentType> getHandle(const cEntityHandle& entityHandle);
    cComponent<componentType>* getPtr(const cEntityHandle& entityHandle);


private:
};


/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///
/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///

template <typename componentType>
cComponentManager<componentType>::cComponentManager()
{
    componentType sampleComponent; /// Make an instance to be sure the component family is assigned.
    family = sampleComponent.getFamily();
}

template <typename componentType>
cComponentManager<componentType>::~cComponentManager()
{
}


template <typename componentType>
cComponentHandle<componentType> cComponentManager<componentType>::addComponent(const cEntityHandle& entityHandle, const componentType& component)
{
    /// Make sure the entity does not already have a component of this type
    cEntity entity = entityHandle.getEntity();
    auto iterator = indexMap.find(entity);
    if(iterator != indexMap.end())
    {
        std::string error = "Entity " + std::to_string(entity) + " already has a component of family " + std::to_string(family);
        throw std::out_of_range(error);
    }
    size_t index = components.size();
    indexMap.insert(std::pair<cEntity, size_t>(entity, index));
    components.push_back(component);

    #ifdef DEBUG
        std::cout << "cComponentManager<" << std::to_string(family) << "> Added component.\n"
                    << "    Index: " << index << "\n"
                    << "    Attached to entity: " << entity << "\n"
                    << "    Component Family: " << std::to_string(family) << "\n";
    #endif

    cComponentHandle<componentType> handle(entity, this);
    return handle;
}

template <typename componentType>
cComponentHandle<componentType> cComponentManager<componentType>::getHandle(const cEntityHandle& entityHandle)
{
    /// Gets a handle to a component
    cEntity entity = entityHandle.getEntity();
    auto iterator = indexMap.find(entity);
    if(iterator == indexMap.end())
    {
        std::string error = "In cComponentManager::getHandle: Entity: " + std::to_string(entity) + ": component of type " + std::to_string(family) + " not found";
        throw std::out_of_range(error);
    }

    size_t index = iterator->second;

    #ifdef DEBUG
        std::cout << "cComponentManager<" << std::to_string(family) << ">: Lookup component of family: " << std::to_string(family) << " in entity: " << entity << "\n"
                    << "Found at vector index: " << index << "\n";
    #endif

    cComponentHandle<componentType> handle(entity, this);
    return handle;
}

template <typename componentType>
cComponent<componentType>* cComponentManager<componentType>::getPtr(const cEntityHandle& entityHandle)
{
    cEntity entity = entityHandle.getEntity();
    auto iterator = indexMap.find(entity);
    if(iterator == indexMap.end())
    {
        std::string error = "In cComponentManager::getPtr: Entity: " + std::to_string(entity) + ": component of type " + std::to_string(family) + " not found";
        throw std::out_of_range(error);
    }

    size_t index = iterator->second;
    return &components[index];
}



#endif // COMPONENTMANAGER_HPP_INCLUDED
