#include "componentbase.hpp"

uint32_t cFamilyCounter::counter = 0;

uint32_t cFamilyCounter::get()
{
    counter++;
    #ifdef DEBUG
        std::cout << "cFamilyCounter value is now: " << counter << "\n";
    #endif
    return counter;
}

cComponentBase::~cComponentBase()
{
}
