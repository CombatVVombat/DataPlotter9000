#ifndef COMPONENTSTORE_HPP_INCLUDED
#define COMPONENTSTORE_HPP_INCLUDED

#include <stdexcept>
#include <vector>
#include "../components/componentid.hpp"


template <typename componentType>
class cComponentStore
{
    using storageType = typename std::vector<componentType>;
    using iteratorType = typename std::vector<componentType>::const_iterator;
public:

private:
    storageType components;
    iteratorType iteratorBegin;
    iteratorType iteratorEnd;
public:
    iteratorType begin() const;
    iteratorType end() const;

private:
};


///
template <typename componentType>
void cComponentStore<componentType>::addComponent(const componentIdType id, const componentType* component)
{
    components.insert(std::make_pair(id, component));
    iteratorBegin = components.begin();
    iteratorEnd = components.end();
}

template <typename componentType>
const componentType* cComponentStore<componentType>::getComponent(const componentIdType id) const
{
    auto iterator = components.find(id);
    if (iterator != components.end())
    {
        return &iterator->second;
    }
    else
    {
        throw std::invalid_argument("ComponentStore could not find component");
        return NULL;
    }
}

template <typename componentType>
typename cComponentStore<componentType>::iteratorType cComponentStore<componentType>::begin() const
{
    return iteratorBegin;
}

template <typename componentType>
typename cComponentStore<componentType>::iteratorType cComponentStore<componentType>::end() const
{
    return iteratorEnd;
}




#endif // COMPONENTSTORE_HPP_INCLUDED
