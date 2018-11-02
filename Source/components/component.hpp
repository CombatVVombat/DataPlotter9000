#ifndef COMPONENT_HPP_INCLUDED
#define COMPONENT_HPP_INCLUDED

#include "componentbase.hpp"

template <typename componentType>
class cComponent : public cComponentBase
{
public:
private:
    static uint32_t family;
    static bool familyAssigned;
public:
    cComponent();
    ~cComponent();
    static uint32_t getFamily();
    void aTestMethod() const;

private:
};


template <typename componentType>
uint32_t cComponent<componentType>::family = 0;

template <typename componentType>
bool cComponent<componentType>::familyAssigned = false;

template <typename componentType>
cComponent<componentType>::cComponent()
{
    if(!familyAssigned)
    {
        family = cFamilyCounter::get();
        familyAssigned = true;
    }
}

template <typename componentType>
cComponent<componentType>::~cComponent()
{
}

template <typename componentType>
uint32_t cComponent<componentType>::getFamily()
{
    return family;
}

template <typename componentType>
void cComponent<componentType>::aTestMethod() const
{
    std::cout << "cComponent<" << std::to_string(family) << "> does aTestMethod()" << "\n";
}

#endif // COMPONENT_HPP_INCLUDED
