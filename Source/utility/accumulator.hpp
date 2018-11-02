#ifndef ACCUMULATOR_HPP_INCLUDED
#define ACCUMULATOR_HPP_INCLUDED

#include <assert.h>
#include <stdint.h>
#include <SFML/System.hpp>
#include <iostream>

class cAccumulator
{
public:
    cAccumulator(const uint64_t frequencyAsHz);
private:

public:
    bool isTimeToRun() const;
    void update(const sf::Time &currentTime);
    void hasRun();
private:
    uint64_t lastRunTime;
    uint64_t currentTime;
    uint64_t period;
};



#endif // ACCUMULATOR_HPP_INCLUDED
