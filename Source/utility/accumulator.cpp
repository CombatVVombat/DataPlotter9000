#include "accumulator.hpp"

cAccumulator::cAccumulator(const uint64_t frequencyAsHz)
: lastRunTime(0), currentTime(0)
{
    assert((frequencyAsHz >= 1) && (frequencyAsHz <= 5000));
    period = (1000000 / frequencyAsHz);
}

bool cAccumulator::isTimeToRun() const
{
    if((currentTime - lastRunTime) > period)
        return true;
    else
        return false;
}

void cAccumulator::hasRun()
{
    lastRunTime += period;
}

void cAccumulator::update(const sf::Time& currentTime)
{
    this->currentTime = currentTime.asMicroseconds();
}
