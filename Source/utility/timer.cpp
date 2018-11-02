#include "timer.hpp"

cTimer::cTimer()
{
    restart();
    update();
}

void cTimer::update()
{
    previous = current;
    current = getElapsedTime();
    elapsed = current - previous;
}

const sf::Time& cTimer::getCurrent() const
{
    return current;
}

const sf::Time& cTimer::getPrevious() const
{
    return previous;
}

const sf::Time& cTimer::getElapsed() const
{
    return elapsed;
}

void cTimer::sayCurrentAsMicroseconds() const
{
    std::cout << "Current time is: " << current.asMicroseconds() << "\n";
}

void cTimer::sayCurrentAsMilliseconds() const
{
    std::cout << "Current time is: " << current.asMilliseconds() << "\n";
}

void cTimer::sayCurrentAsSeconds() const
{
    std::cout << "Current time is: " << current.asSeconds() << "\n";
}
