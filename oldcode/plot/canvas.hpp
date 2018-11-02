#ifndef CANVAS_HPP_INCLUDED
#define CANVAS_HPP_INCLUDED

#include "../graphics/irenderable.hpp"

namespace plot
{
    class cCanvas   : public iRenderable
    {
    public:
    private:
        sf::RectangleShape rectangle;
        sf::Transform transform;

    public:
        cCanvas(entityIdType id);
        void setFillColor(sf::Color color);
        void setOutlineColor(sf::Color color);
        void setOutlineThickness(const float thickness);
        void setPosition(const sf::Vector2f& position);
        void setSize(const sf::Vector2f& size);

    private:
    };
}



#endif // CANVAS_HPP_INCLUDED
