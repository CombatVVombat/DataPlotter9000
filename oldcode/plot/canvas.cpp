#include "canvas.hpp"

using namespace plot;

cCanvas::cCanvas(entityIdType id)  : iRenderable(id)
{
    setDrawablePtr(&rectangle);
    setSize(sf::Vector2f(1000,400));
    setPosition(sf::Vector2f(2.0f,2.0f));
    setFillColor(sf::Color(225,225,225,255));
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(1.0f);

    setTransformPtr(&transform);
}

void cCanvas::setFillColor(sf::Color color)
{
    rectangle.setFillColor(color);
}

void cCanvas::setOutlineColor(sf::Color color)
{
    rectangle.setOutlineColor(color);
}

void cCanvas::setOutlineThickness(const float thickness)
{
    rectangle.setOutlineThickness(thickness);
}

void cCanvas::setPosition(const sf::Vector2f& position)
{
    transform = sf::Transform::Identity;
    transform.translate(position);
}

void cCanvas::setSize(const sf::Vector2f& size)
{
    rectangle.setSize(size);
}

