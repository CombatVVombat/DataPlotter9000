#ifndef COMPONENTHANDLE_HPP_INCLUDED
#define COMPONENTHANDLE_HPP_INCLUDED

#include "../entitys/entity.hpp"

template <typename componentType> class cComponentManager;

template <typename componentType>
class cComponentHandle
{
public:
private:
    cEntity owner;
    cComponentManager<componentType>* manager;

public:
    cComponentHandle(const cEntity& owner, cComponentManager<componentType>* manager);
    cComponent<componentType>* getPtr();
private:
};


/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///
/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///


template <typename componentType>
cComponentHandle<componentType>::cComponentHandle(const cEntity& owner, cComponentManager<componentType>* manager)
{
    this->owner = owner;
    this->manager = manager;
}

template <typename componentType>
cComponent<componentType>* cComponentHandle<componentType>::getPtr()
{
    return manager->getPtr();
}

#endif // COMPONENTHANDLE_HPP_INCLUDED
