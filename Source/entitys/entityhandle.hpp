#ifndef ENTITYHANDLE_HPP_INCLUDED
#define ENTITYHANDLE_HPP_INCLUDED

#include "entity.hpp"

class cWorld;

class cEntityHandle
{
public:
private:
    cEntity entity;
    cWorld* world;

public:
    cEntityHandle(const cEntity& entity, cWorld* world);
    void destroy();
    template <typename componentType>
    void addComponent(componentType component);
    template <typename componentType>
    void removeComponent();
    const cEntity& getEntity() const;
private:
};



#endif // ENTITYHANDLE_HPP_INCLUDED
