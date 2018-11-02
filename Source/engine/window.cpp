#include "window.hpp"

cRenderWindow::cRenderWindow(sf::VideoMode mode, const sf::String& title, sf::Uint32 style)
: sf::RenderWindow(mode, title, style)
{
}

void cRenderWindow::handleEvent(sf::Event event)
{
    if(event.type == sf::Event::Closed)
        close();
}
