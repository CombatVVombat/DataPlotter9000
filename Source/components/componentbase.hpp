#ifndef COMPONENTBASE_HPP_INCLUDED
#define COMPONENTBASE_HPP_INCLUDED

#include <iostream>
#include <stdint.h>

/// Make familyCounter a class in its own file and stuff.

class cFamilyCounter
{
private:
    static uint32_t counter;
public:
    static uint32_t get();
};

class cComponentBase
{
public:
    virtual ~cComponentBase();
private:
public:
private:
};




#endif // COMPONENTBASE_HPP_INCLUDED
