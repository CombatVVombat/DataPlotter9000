#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class cRenderWindow : public sf::RenderWindow
{
friend class cEngine;
public:
private:
    sf::Event event;

public:
    cRenderWindow(sf::VideoMode mode, const sf::String& title, sf::Uint32 style = sf::Style::Default);
private:
    void handleEvent(sf::Event event);
};



#endif // WINDOW_HPP_INCLUDED
