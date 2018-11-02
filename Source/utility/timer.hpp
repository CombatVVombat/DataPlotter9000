#ifndef TIMER_HPP_INCLUDED
#define TIMER_HPP_INCLUDED

#include <iostream>
#include <SFML/System.hpp>

class cTimer : public sf::Clock
{
public:
private:
    sf::Time previous;
    sf::Time current;
    sf::Time elapsed;

public:
    cTimer();
    void update();
    const sf::Time& getCurrent() const;
    const sf::Time& getPrevious() const;
    const sf::Time& getElapsed() const;
    void sayCurrentAsMicroseconds() const;
    void sayCurrentAsMilliseconds() const;
    void sayCurrentAsSeconds() const;
private:
};



#endif // TIMER_HPP_INCLUDED
